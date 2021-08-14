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

#include "../PuyansListNode/PuyansListNode.h"
#include "../ZDBug/ZDBug.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

#ifndef PUYANSLIST_H_
#define PUYANSLIST_H_

class PuyansList {
public:
  PuyansList();
  virtual ~PuyansList();
  void qAdd(PuyansListNode *new_node);
  PuyansListNode *qRemove(int nodeID);
  void print_object();
  inline PuyansListNode *getHead() {
    return qHead;
  } // Note! Do not use these yet! Not untile a reader lock is implemented.
  /** This inline method returns a pointer to the tail of the linked list.
   *  Note that the list is a bidirectional circular linked list.
   */
  inline PuyansListNode *getTail() {
    return qTail;
  } // Note! Do not use these yet! Not untile a reader lock is implemented.
private:
  unsigned int length;
  unsigned int count; // The difference between count and length is that I never
                      // decrement count.
  PuyansListNode *qHead;
  PuyansListNode *qTail;
};

#endif /*PUYANSLIST_H_*/
