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

#include "Line.h"

Line::Line(LineNode *start, LineNode *end) {
#if zdbug_print_function_call_trace
  cout << "Line::Line(LineNode* start, LineNode* end)\n";
#endif

#if zdbug
  cout << "\tStart: \n";
  cout << "\t\t X: " << start->getX() << " Y: " << start->getY() << endl;
  cout << "\tEnd: \n";
  cout << "\t\t X: " << end->getX() << " Y: " << end->getY() << endl;
#endif

  Line::start = start;
  Line::end = end;

  run = end->getX() - start->getX();
  rise = end->getY() - start->getY();
  slope = (double)rise / (double)run;
}

Line::~Line() {
#if zdbug_print_function_call_trace
  cout << "Line::Line()\n";
#endif
}

LineNode *Line::getStart() {
#if zdbug_print_function_call_trace
  cout << "LineNode* Line::getStart()\n";
#endif
  return start;
}

LineNode *Line::getEnd() {
#if zdbug_print_function_call_trace
  cout << "LineNode* Line::getEnd()\n";
#endif
  return end;
}

double Line::getSlope() {
#if zdbug_print_function_call_trace
  cout << "double Line::getSlope() \n";
#endif
  return slope;
}

int Line::getRun() {
#if zdbug_print_function_call_trace
  cout << "int Line::getRun()\n";
#endif
  return run;
}

int Line::getRise() {
#if zdbug_print_function_call_trace
  cout << "int Line::getRise()\n";
#endif
  return rise;
}
