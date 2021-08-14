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

#include <iostream>
using namespace std;

#include "LineCollection.h"

LineCollection::LineCollection() {
#if zdbug_print_function_call_trace
  cout << "LineCollection::LineCollection()\n";
#endif
  lastVertex = NULL;
  lineCollection = new PuyansList();
}

LineCollection::~LineCollection() {}

Line *LineCollection::addNewVertex(LineNode *newVertex) {
#if zdbug_print_function_call_trace
  cout << "Line* LineCollection::addNewVertex(LineNode* newVertex)\n";
#endif

  LineNode *startVertex = lastVertex;
  LineNode *endVertex = newVertex;
  Line *newLine = NULL;

  if (NULL != startVertex) {
    // Check for nulls
    newLine = new Line(startVertex, endVertex);
    lineCollection->qAdd(new PuyansListNode(newLine));
    lastVertex = newVertex;
  }
  lastVertex = newVertex;
  return newLine;
}
