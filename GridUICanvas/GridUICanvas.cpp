/***************************************************************************
 *   Copyright (C) 2007 by Puyan Lotfi
 *   plotfi@gmail.com
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "GridUICanvas.h"

#include <qcanvas.h>
//#include <qcanvas.h>
//#include <qpoint.h>
//#include <qpainter.h>

#include <fstream>
#include <iostream>
using namespace std;

GridUICanvas::GridUICanvas(QCanvas &c, QWidget *parent, const char *name,
                           WFlags f)
    : QCanvasView(&c, parent, name, f) {

#if zdbug_print_function_call_trace
  cout << "GridUICanvas::GridUICanvas(QCanvas& c, QWidget* parent, const char* "
          "name, WFlags f) : QCanvasView(&c,parent,name,f)\n";
#endif

  QCanvasLine *line1 = new QCanvasLine(canvas());
  line1->setPoints(250, 0, 250, 500);
  line1->show();

  QCanvasLine *line2 = new QCanvasLine(canvas());
  line2->setPoints(0, 250, 500, 250);
  line2->show();

  preline = new QCanvasLine(canvas());

  linemode = false;
  startedLine = false;
  playlistPath = new LineCollection();

  assembleBackend();
}

GridUICanvas::GridUICanvas(QWidget *parent, const char *name)
    : QCanvasView(parent, name) {

#if zdbug_print_function_call_trace
  cout << "GridUICanvas::GridUICanvas(QWidget* parent,const char* name) "
          ":QCanvasView(parent,name) \n";
#endif

  assembleBackend();
}

GridUICanvas::~GridUICanvas() {

#if zdbug_print_function_call_trace
  cout << "GridUICanvas::~GridUICanvas() \n";
#endif

  teardownBackend();
}

void GridUICanvas::assembleBackend() {

#if zdbug_print_function_call_trace
  cout << "void GridUICanvas::assembleBackend()  \n";
#endif

  canvas_backend = new GridMatrix(); // must go first to start dcop
  /*  current_song = new QCanvasText(
      canvas_backend->
      getSongInfoFromAmarok->
      getCurrentTitle(),
      canvas());
      current_song->show();*/

  char linestring[15000];

  char *album_to_insert;
  char *artist_to_insert;
  char *title_to_insert;
  char *path_to_insert;

  songInfoType plot_type;

  int row_coord, col_coord;

  stringstream musiKplot_store_path;

  musiKplot_store_path << getenv("HOME") << "/.musiKPlot";

  ifstream grid_data_store(musiKplot_store_path.str().c_str());
  cout << "Read file opened.\n";
  while (!grid_data_store.eof()) {
    grid_data_store.getline(linestring, 14500);
    // cout << linestring << endl;

    char *cur_tok = NULL;

    int wtf = 29;

    int *wtf_ref = &wtf;

    cur_tok = strtok(linestring, (const char *)(wtf_ref));
    for (int i = 0; NULL != cur_tok; i++) {

      switch (i) {
      case row:
        row_coord = atoi(cur_tok);
        break;
      case col:
        col_coord = atoi(cur_tok);
        break;
      case type: {
        char *LABEL_STR = "LABEL";
        char *SONG_STR = "SONG";
        if (0 == strncasecmp(LABEL_STR, cur_tok, strlen(LABEL_STR))) {
          plot_type = LABEL;
          //	cout << "got a label\n";
        } else if (0 == strncasecmp(SONG_STR, cur_tok, strlen(SONG_STR))) {
          plot_type = SONG;
          //	cout << "got a song\n";
        } else {
          cout << "FILE: " << __FILE__ << "LINE: " << __LINE__
               << " this should not be happening." << endl;
        }
      } break;
      case artist:
        artist_to_insert = cur_tok;
        break;
      case album:
        album_to_insert = cur_tok;
        break;
      case song:
        title_to_insert = cur_tok;
        break;
      case path:
        path_to_insert = cur_tok;
        break;
      default:
        cout << "FILE: " << __FILE__ << "LINE: " << __LINE__
             << " this should not be happening." << endl;
      }

      cur_tok = strtok(NULL, (const char *)(wtf_ref));
    }

    //	cout << "row: " << row_coord << " col: " << col_coord << " type: " <<
    //thisSong->type << " artist: " << thisSong->artist << " album: " <<
    //thisSong->album << " song: " << thisSong->title << " path: " <<
    //thisSong->path << endl;

    if (SONG == plot_type) {
      canvas_backend->addSongByInfo(
          row_coord, col_coord,
          new SongInfo(artist_to_insert, album_to_insert, title_to_insert,
                       path_to_insert));
    } else if (LABEL == plot_type) {
      canvas_backend->addSongByInfo(row_coord, col_coord,
                                    new SongInfo(artist_to_insert));
    } else {
      cout << "__FILE__ : "
           << "__LINE__ "
           << " this should not be happening." << endl;
    }

    //////////////////////////////////
    if (plot_type == LABEL) {
      QCanvasText *qctwtf = new QCanvasText(artist_to_insert, canvas());
      qctwtf->setX(row_coord);
      qctwtf->setY(col_coord);
      qctwtf->show();
    } else if (plot_type == SONG) {
      QCanvasRectangle *raysDemand =
          new QCanvasRectangle(row_coord, col_coord, 6, 6, canvas());
      raysDemand->show();
    } else {
      cout << "__FILE__ : "
           << "__LINE__ "
           << " this should not be happening." << endl;
    }
    ///////////////////////////////
  }
  grid_data_store.close();

  cout << "Read file closed.\n";

  for (int k = 0; k < 500; k++) {
    for (int h = 0; h < 500; h++) {

      PuyansList *printlist = canvas_backend->getObjectFromCoordinate(h, k);

      if (NULL != printlist) {
        PuyansListNode *current = printlist->getHead();

        if (NULL != printlist->getHead()) {
          do {
            cout << "X: " << k << " Y: " << h << " ";
            cout << "Artist: " << ((SongInfo *)(current->data))->artist;
            cout << "Album: " << ((SongInfo *)(current->data))->album;
            cout << "Song: " << ((SongInfo *)(current->data))->title;
            cout << "Path: " << ((SongInfo *)(current->data))->path << endl;
            current = current->next;
          } while (printlist->getHead() != current);
        } else {
          cout << "Empty>" << endl;
        }
      }
    }
  }
}

void GridUICanvas::teardownBackend() {
#if zdbug_print_function_call_trace
  cout << "void GridUICanvas::teardownBackend()  \n";
#endif

  delete canvas_backend;
}

void GridUICanvas::contentsMousePressEvent(QMouseEvent *e) {

#if zdbug_print_function_call_trace
  cout << "void GridUICanvas::contentsMousePressEvent(QMouseEvent* e)   \n";
#endif

  QPoint p = inverseWorldMatrix().map(e->pos());
  QCanvasItemList l = canvas()->collisions(p);
  cout << "X Coordinate: " << p.x() << "   "
       << "Y Coordinate: " << p.y() << endl;

  if (!linemode) {

    if (artistplotmode) {
      QCanvasText *qctwtf = new QCanvasText(
          canvas_backend->getSongInfoFromAmarok->getCurrentArtist(), canvas());

      cout << "plotting artist" << endl;

      qctwtf->setX(p.x());
      qctwtf->setY(p.y());
      qctwtf->show();

      canvas_backend->addSong(p.x(), p.y(), LABEL);

      artistplotmode = false;
    } else {

      if (canvas_backend->addSong(
              p.x(), p.y(),
              SONG)) { // HACK: 04/8/07: now grid and ui match: 500x500
        QCanvasRectangle *raysDemand =
            new QCanvasRectangle(p.x() - 3, p.y() - 3, 6, 6, canvas());
        raysDemand->show();
      } else {
        return;
      }

      PuyansList *printlist =
          canvas_backend->getObjectFromCoordinate(p.x(), p.y());

      if (NULL != printlist) {
        PuyansListNode *current = printlist->getHead();

        if (NULL != printlist->getHead()) {
          do {
            cout << "Artist: " << ((SongInfo *)(current->data))->artist << endl;
            cout << "Album: " << ((SongInfo *)(current->data))->album << endl;
            cout << "Song: " << ((SongInfo *)(current->data))->title << endl;
            cout << "Path: " << ((SongInfo *)(current->data))->path << endl;
            current = current->next;
          } while (printlist->getHead() != current);
        } else {
          cout << "Empty>" << endl;
        }
      }

      //    for(int i=0;i<printlist->length;i++) {
      //
      //    }
      //
    }

    // moving = 0 ; wtf man
  } else {

    Line *newLineToDraw;

    newLineToDraw = playlistPath->addNewVertex(new LineNode(p.x(), p.y()));

    if (NULL != newLineToDraw) {

      QCanvasLine *line2 = new QCanvasLine(canvas());
      // line2->setPoints(lastX,lastY,p.x(),p.y());
      line2->setPoints(
          newLineToDraw->getStart()->getX(), newLineToDraw->getStart()->getY(),
          newLineToDraw->getEnd()->getX(), newLineToDraw->getEnd()->getY());
      preline->setPoints(
          newLineToDraw->getStart()->getX(), newLineToDraw->getStart()->getY(),
          newLineToDraw->getEnd()->getX(), newLineToDraw->getEnd()->getY());

      preline->show();

      line2->show();

      lastX = p.x();
      lastY = p.y();

      lineplaylistprocessor.getPlayableGridNodes(
          newLineToDraw, canvas_backend, newLineToDraw->getStart(),
          newLineToDraw->getEnd(), canvas_backend->getSongInfoFromAmarok);

    } else {
      // lastX = p.x();
      // lastY = p.y();
      // startedLine = true;
    }
  }
}

void GridUICanvas::contentsMouseMoveEvent(QMouseEvent *e) {
  // Bad idea to print trace on this guy

  if (moving && linemode) {

    QPoint p = inverseWorldMatrix().map(e->pos());
    preline->setPoints(lastX, lastY, p.x(), p.y());
    preline->show();
  }
}

void GridUICanvas::toggleLineMode() {
#if zdbug_print_function_call_trace
  cout << "void GridUICanvas::toggleLineMode()   \n";
#endif
  linemode = !linemode;
  // canvas_backend->getSongInfoFromAmarok->clearPlaylist();
  cout << "toggle Line Mode" << endl;
}

void GridUICanvas::plotArtist() {
#if zdbug_print_function_call_trace
  cout << "void GridUICanvas::plotArtist() \n";
#endif
  artistplotmode = !artistplotmode;
  // canvas_backend->getSongInfoFromAmarok->clearPlaylist();
  cout << "toggle Artist Plot Mode" << endl;
}

void GridUICanvas::writeToFile() {
#if zdbug_print_function_call_trace
  cout << "void GridUICanvas::writeToFile() \n";
#endif

  canvas_backend->print_grid_matrix_content();
}

/*void GridUICanvas::load_song_info_from_file() {
        // Open file

        // loop
                // read line by line
                //add them to grid, and to the canvas

        // close file

}*/
