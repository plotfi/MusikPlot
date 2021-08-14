/***************************************************************************
 *   Copyright (C) 2007 by Puyan Lotfi
 *   plotfi@gmail.com
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  * *
 *the Free Software Foundation; either version 2 of the License, or     * * (at
 *your option) any later version.                                   * * * This
 *program is distributed in the hope that it will be useful,       * but WITHOUT
 *ANY WARRANTY; without even the implied warranty of        * MERCHANTABILITY or
 *FITNESS FOR A PARTICULAR PURPOSE.  See the         * GNU General Public
 *License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include <iostream>
using namespace std;

#include "GridMatrix.h"

#include <stdlib.h>

GridMatrix::GridMatrix() {
#if zdbug_print_function_call_trace
  cout << "GridMatrix::GridMatrix() \n";
#endif

  getSongInfoFromAmarok = new AmarokInfo();

  for (int i = 0; i < matrix_column_depth; i++) {
    grid_matrix[i] = new PuyansList *[matrix_row_depth];
  }

  for (int i = 0; i < matrix_column_depth; i++) {
    for (int j = 0; j < matrix_row_depth; j++) {
      (grid_matrix[i])[j] = NULL;
      (grid_matrix_marker[i])[j] = 0;
    }
  }

  /*for(int i=0;i<matrix_column_depth;i++) {
    for(int j=0;j<matrix_row_depth;j++) {
  //cout << (grid_matrix[i])[j];
  //if(i==j) (grid_matrix[i])[j] = 1;
  (grid_matrix[i])[j] = NULL;
  }
  //cout << endl;
  }*/
  /*
     for(int i=0;i<matrix_column_depth;i++) {
     for(int j=0;j<matrix_row_depth;j++) {
     cout << (grid_matrix[i])[j];
     }
     cout << endl;
     }*/
}

GridMatrix::~GridMatrix() {
#if zdbug_print_function_call_trace
  cout << "GridMatrix::~GridMatrix()\n";
#endif
  // TODO: delete the arrays in the grid_matrix.
}

int GridMatrix::addSong(int row, int column, songInfoType type) {
// return 0 if fail, 1 if pass
#if zdbug_print_function_call_trace
  cout << "int GridMatrix::addSong(int row, int column, songInfoType type)\n";
#endif

  if (row >= matrix_row_depth || column >= matrix_column_depth)
    return 0;

  PuyansList *insertCell = (grid_matrix[row])[column];
  // SongInfo* newSong;
  QString artist;
  QString album;
  QString title;
  QString path;

  /*	if (NULL == insertCell) {
          cout << "Null, setting cell\n";
          (grid_matrix[row])[column] = new PuyansList();
          insertCell = (grid_matrix[row])[column];
          } */

  if (NULL != (artist = getSongInfoFromAmarok->getCurrentArtist()) &&
      NULL != (album = getSongInfoFromAmarok->getCurrentAlbum()) &&
      NULL != (title = getSongInfoFromAmarok->getCurrentTitle()) &&
      NULL != (path = getSongInfoFromAmarok->getCurrentPath())) {

    if (NULL == insertCell) {
      cout << "Null, setting cell\n";
      (grid_matrix[row])[column] = new PuyansList();
      insertCell = (grid_matrix[row])[column];
    }

    if (type == LABEL) {
      insertCell->qAdd(new PuyansListNode(new SongInfo(artist)));
    } else if (type == SONG) {
      insertCell->qAdd(
          new PuyansListNode(new SongInfo(artist, album, title, path)));
    } else {
      cout << "__FILE__ : "
           << "__LINE__ "
           << " this should now be happening." << endl;
      return 0;
    }

    return 1;

  } else {
    cout << "Unable to get current song info. \n "
         << "Amarok Might not be running... " << endl;
    return 0;
  }

  return 0;
}

int GridMatrix::addSongByInfo(int row, int column, SongInfo *songToAdd) {
// return 0 if fail, 1 if pass
#if zdbug_print_function_call_trace
  cout << "int GridMatrix::addSongByInfo(int row, int column, SongInfo* "
          "songToAdd)\n";
#endif

  if (row >= matrix_row_depth || column >= matrix_column_depth ||
      NULL == songToAdd)
    return 0;

  PuyansList *insertCell = (grid_matrix[row])[column];

  if (NULL == insertCell) {
    // cout << "Null, setting cell\n";
    (grid_matrix[row])[column] = new PuyansList();
    insertCell = (grid_matrix[row])[column];
  }

  insertCell->qAdd(new PuyansListNode(songToAdd));
  return 1;
}

PuyansList *GridMatrix::getObjectFromCoordinate(int row, int column) {
#if zdbug_print_function_call_trace
  cout << "PuyansList* GridMatrix::getObjectFromCoordinate(int row, int "
          "column) \n";
#endif

  if (row >= matrix_row_depth || column >= matrix_column_depth) {
    return NULL;
  }

#if zdbug
  cout << "[ LINE - " << __LINE__ << " ] [ FILE - " << __FILE__
       << " ] getting objects from coordinate: "
       << " row: " << row << " col: " << column << endl;
#endif

  return (grid_matrix[row])[column];
}

int GridMatrix::get_grid_matrix_marker(int row, int column) {
#if zdbug_print_function_call_trace
  cout << "int GridMatrix::get_grid_matrix_marker(int row, int column) \n";
#endif

  if (row >= matrix_row_depth || column >= matrix_column_depth)
    return -1;

  return (grid_matrix_marker[row])[column];
}

int GridMatrix::set_grid_matrix_marker(int row, int column, int marker) {
#if zdbug_print_function_call_trace
  cout << "int GridMatrix::set_grid_matrix_marker(int row, int column, int "
          "marker) \n";
#endif

  if (row >= matrix_row_depth || column >= matrix_column_depth)
    return 0;

  (grid_matrix_marker[row])[column] = marker;
  return 1;
}

int GridMatrix::get_grid_matrix_content(int row, int column) {
#if zdbug_print_function_call_trace
  cout << "char* GridMatrix::get_grid_matrix_content(int row, int column)  \n";
#endif

  if (row >= matrix_row_depth || column >= matrix_column_depth)
    return -1;

  // QString songs_in_coord;

  PuyansList *printlist = getObjectFromCoordinate(row, column);

  if (NULL != printlist) {
    PuyansListNode *current = printlist->getHead();

    if (NULL != printlist->getHead()) {
      do {

        SongInfo *thisSong = (SongInfo *)(current->data);

        /*
        cout << "Writing to file --- row: " << row << " col: "
             << column << " type: " << thisSong->type
             << " artist: " << thisSong->artist << " album: "
             << thisSong->album << " song: " << thisSong->title
             << " path: " << thisSong->path << endl;
        */

        writefile << column << (char)29 << row << (char)29;
        if (((SongInfo *)(current->data))->type == LABEL) {
          writefile << "LABEL" << (char)29;
          writefile << ((SongInfo *)(current->data))->artist << (char)29;
          writefile << " " << (char)29 << " " << (char)29 << " " << (char)29
                    << " " << endl;
        } else if (((SongInfo *)(current->data))->type == SONG) {
          writefile << "SONG" << (char)29;
          writefile << ((SongInfo *)(current->data))->artist << (char)29;
          writefile << ((SongInfo *)(current->data))->album << (char)29;
          writefile << ((SongInfo *)(current->data))->title << (char)29;
          writefile << ((SongInfo *)(current->data))->path << endl;

        } else {
          cout << "__FILE__ : "
               << "__LINE__ "
               << " this should now be happening." << endl;
        }
        current = current->next;
      } while (printlist->getHead() != current);
    } else {
      cout << "Empty>" << endl;
    }
  }

  return 0;
}

void GridMatrix::print_grid_matrix_content() {

  stringstream musiKplot_store_path;

  musiKplot_store_path << getenv("HOME") << "/.musiKPlot";

  // cout << "Writing to: " << musiKplot_store_path.str().c_str() << endl;

  writefile.open(musiKplot_store_path.str().c_str());
  cout << "Write file opened.\n";
  writefile_open = true;

  for (int i = 0; i < matrix_row_depth; i++) {
    for (int j = 0; j < matrix_column_depth; j++) {
      get_grid_matrix_content(j, i);
    }
  }

  writefile.close();
  cout << "Write file closed.\n";
  writefile_open = false;
}
