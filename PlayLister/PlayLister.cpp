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

#include "PlayLister.h"

/*
#define playsongatcoord(musiccoodX,musiccoodY)    musiKnode =
musiKgrid->getObjectFromCoordinate((int)(musiccoodX), (int)(musiccoodY)); \
                                                              cout << "X: " <<
printpointsX << " Y: " << printpointsY << endl;  \
if (NULL != musiKnode &&
(musiKgrid->grid_matrix_marker[(int)musiccoodX][(int)musiccoodY])<counter) { \
        musiKgrid->grid_matrix_marker[(int)musiccoodX][(int)musiccoodY]=counter;
\
        PuyansList* printlist = musiKnode; \
        PuyansListNode* current = printlist->getHead(); \
        if(NULL != printlist->getHead()) { \
                do { \
                        com_backend->addSongToPlaylist(((SongInfo*)(current->data))->path);
\
                        current = current->next; \
                } while(printlist->getHead()!=current); \
        } else { \
                cout << "Empty>" << endl; \
        } \
} \
\


#define playsongsinarea(printpointsX,printpointsY)
playsongatcoord(printpointsX,printpointsY) \
        \
playsongatcoord((printpointsX),(printpointsY+1))\
playsongatcoord((printpointsX),(printpointsY-1))\
playsongatcoord((printpointsX+1),(printpointsY))\
playsongatcoord((printpointsX-1),(printpointsY))\
\
playsongatcoord((printpointsX+1),(printpointsY+1))\
playsongatcoord((printpointsX-1),(printpointsY-1))\
playsongatcoord((printpointsX-1),(printpointsY+1))\
playsongatcoord((printpointsX+1),(printpointsY-1))\
\
playsongatcoord((printpointsX),(printpointsY+2))\
playsongatcoord((printpointsX),(printpointsY-2))\
playsongatcoord((printpointsX+2),(printpointsY))\
playsongatcoord((printpointsX-2),(printpointsY))\
\
playsongatcoord((printpointsX+2),(printpointsY+2))\
playsongatcoord((printpointsX-2),(printpointsY-2))\
playsongatcoord((printpointsX-2),(printpointsY+2))\
playsongatcoord((printpointsX+2),(printpointsY-2))\
\
playsongatcoord((printpointsX-2),(printpointsY+1))\
playsongatcoord((printpointsX-1),(printpointsY+2))\
playsongatcoord((printpointsX-1),(printpointsY-2))\
playsongatcoord((printpointsX-2),(printpointsY-1))\
\
playsongatcoord((printpointsX+2),(printpointsY+1))\
playsongatcoord((printpointsX+1),(printpointsY+2))\
playsongatcoord((printpointsX+1),(printpointsY-2))\
playsongatcoord((printpointsX+2),(printpointsY-1))\
\
\
playsongatcoord((printpointsX-3),(printpointsY+3))\
playsongatcoord((printpointsX-2),(printpointsY+3))\
playsongatcoord((printpointsX-1),(printpointsY+3))\
playsongatcoord((printpointsX),(printpointsY+3))\
playsongatcoord((printpointsX+1),(printpointsY+3))\
playsongatcoord((printpointsX+2),(printpointsY+3))\
playsongatcoord((printpointsX+3),(printpointsY+3))\
\
playsongatcoord((printpointsX-2),(printpointsY-3))\
playsongatcoord((printpointsX-2),(printpointsY-3))\
playsongatcoord((printpointsX-2),(printpointsY-3))\
playsongatcoord((printpointsX),(printpointsY-3))\
playsongatcoord((printpointsX+1),(printpointsY-3))\
playsongatcoord((printpointsX+2),(printpointsY-3))\
playsongatcoord((printpointsX+3),(printpointsY-3))\
\
playsongatcoord((printpointsX-3),(printpointsY+2))\
playsongatcoord((printpointsX-3),(printpointsY+1))\
playsongatcoord((printpointsX-3),(printpointsY))\
playsongatcoord((printpointsX-3),(printpointsY-1))\
playsongatcoord((printpointsX-3),(printpointsY-2))\
\
\
playsongatcoord((printpointsX+3),(printpointsY+2))\
playsongatcoord((printpointsX+3),(printpointsY+1))\
playsongatcoord((printpointsX+3),(printpointsY))\
playsongatcoord((printpointsX+3),(printpointsY-1))\
playsongatcoord((printpointsX+3),(printpointsY-2))\
\

*/

PlayLister::PlayLister() {
  cout << "PlayLister::PlayLister() \n";
  counter = 0;
}

PlayLister::~PlayLister() {}

void PlayLister::getPlayableGridNodes(Line *line2playableNodes,
                                      GridMatrix *musiKgrid, LineNode *start,
                                      LineNode *end, AmarokInfo *com_backend) {
#if zdbug_print_function_call_trace
  cout << "PuyansList* PlayLister::getPlayableGridNodes(Line* "
          "line2playableNodes, GridMatrix* musiKgrid, LineNode* start, "
          "LineNode* end )\n";
#endif

  double printpointsX = line2playableNodes->getStart()->getX();
  double printpointsY = line2playableNodes->getStart()->getY();

  PuyansList *musiKnode = NULL;

  counter++;

  cout << "Counter: " << counter << endl;

  cout << "X: " << printpointsX << " Y: " << printpointsY << endl;

  while (true) {

    // playsongsinarea((printpointsX),(printpointsY))

    int i = printpointsX - 10, imax, initi;
    int j = printpointsY - 10, jmax, initj;
    if (i < 0) {
      i = 0;
    } else if (i > 499) {
      i = 499;
    }
    if (j < 0) {
      j = 0;
    } else if (j > 499) {
      j = 499;
    }

    imax = i + 20;
    jmax = j + 20;

    initi = i;
    initj = j;

    // cout << "Start iteration" << endl;
    for (i = initi; i < imax; i++) {
      for (j = initj; j < jmax; j++) {
        // cout << "X: " << i << " Y: " << j << endl;
        musiKnode = musiKgrid->getObjectFromCoordinate((int)(i), (int)(j));

        int current_marker = musiKgrid->get_grid_matrix_marker((int)i, (int)j);

        if (NULL != musiKnode && current_marker < counter &&
            current_marker >= 0) {
          musiKgrid->set_grid_matrix_marker((int)i, (int)j, counter);
          PuyansList *printlist = musiKnode;
          PuyansListNode *current = printlist->getHead();
          if (NULL != printlist->getHead()) {
            do {

              if (SONG == ((SongInfo *)(current->data))->type) {
                cout << "Adding song at X: " << i << " Y: " << j << endl;
                com_backend->addSongToPlaylist(
                    ((SongInfo *)(current->data))->path);
                current = current->next;
              }
            } while (printlist->getHead() != current);
          } else {
            cout << "Empty>" << endl;
          }
        } else {
          //	continue;
        }
      }
    }

    /*
            playsongsinarea((printpointsX+3),(printpointsY+3))
            playsongsinarea((printpointsX-3),(printpointsY-3))
            playsongsinarea((printpointsX+3),(printpointsY-3))
            playsongsinarea((printpointsX-3),(printpointsY+3))
            */

    if (end->getX() == ((int)printpointsX)) {
      break;
    }

    if (line2playableNodes->getRise() != 0 &&
        line2playableNodes->getRun() != 0) {

      if (line2playableNodes->getSlope() < 0 &&
          line2playableNodes->getRun() < 0 &&
          line2playableNodes->getRise() > 0) {
        printpointsX -= 1;
        printpointsY += -1 * line2playableNodes->getSlope();
      } else if (line2playableNodes->getSlope() > 0 &&
                 line2playableNodes->getRun() < 0 &&
                 line2playableNodes->getRise() < 0) {
        printpointsX -= 1;
        printpointsY -= line2playableNodes->getSlope();
      } else {
        printpointsX += 1;
        printpointsY += line2playableNodes->getSlope();
      }
    } else {

      /*
         cout << "You suck\n";
         break;
         */
      if (line2playableNodes->getRise() == 0 &&
          line2playableNodes->getRun() != 0) {
        printpointsX += line2playableNodes->getRun();
        // Horizontal

      } else if (line2playableNodes->getRise() != 0 &&
                 line2playableNodes->getRun() == 0) {
        printpointsY += line2playableNodes->getRise();
        // Vertical

      } else {
        // A point in space?
        cout << "You suck\n";
        break;
      }
    }
  }
}
