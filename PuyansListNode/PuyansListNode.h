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

#include "../ZDBug/ZDBug.h"

#ifndef PUYANSLISTNODE_H_
#define PUYANSLISTNODE_H_

/**
 * Class: PuyansListNode
 * This is the same stuff as the Linux Embeded Linked List.
 * I Really needs to reimpliment this using templates.
 */

class PuyansListNode {
public:
  PuyansListNode();
  PuyansListNode(void *data);
  virtual ~PuyansListNode();
  class PuyansListNode *next;
  class PuyansListNode *prev;
  int nodeID;
  void *data;
};

#endif /*PUYANSLISTNODE_H_*/
