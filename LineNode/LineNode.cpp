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

#include "LineNode.h"

using namespace std;

LineNode::LineNode(int X, int Y) {
#if zdbug_print_function_call_trace
  cout << "LineNode::LineNode(int X, int Y)\n";
#endif
  LineNode::X = X;
  LineNode::Y = Y;
}

LineNode::~LineNode() {
#if zdbug_print_function_call_trace
  cout << "LineNode::~LineNode()\n";
#endif
}

int LineNode::getX() {
#if zdbug_print_function_call_trace
  cout << "int LineNode::getX()\n";
#endif
  return X;
}

int LineNode::getY() {
#if zdbug_print_function_call_trace
  cout << "int LineNode::getY()\n";
#endif
  return Y;
}
