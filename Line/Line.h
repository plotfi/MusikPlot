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

#include "../LineNode/LineNode.h"
#include "../ZDBug/ZDBug.h"

#ifndef LINE_H_
#define LINE_H_

class Line {
public:
  Line(LineNode *start, LineNode *end);
  virtual ~Line();
  LineNode *getStart();
  LineNode *getEnd();
  double getSlope();
  int getRun();
  int getRise();

private:
  LineNode *start;
  LineNode *end;
  bool newline;
  double slope;
  int rise;
  int run;
};

#endif /*LINE_H_*/
