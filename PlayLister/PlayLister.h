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

#include "../AmarokInfo/AmarokInfo.h"
#include "../GridMatrix/GridMatrix.h"
#include "../Line/Line.h"
#include "../PuyansList/PuyansList.h"
#include "../PuyansListNode/PuyansListNode.h"
#include "../SongInfo/SongInfo.h"
#include "../ZDBug/ZDBug.h"

#ifndef PLAYLISTER_H_
#define PLAYLISTER_H_

class PlayLister {
public:
  PlayLister();
  virtual ~PlayLister();
  void getPlayableGridNodes(Line *line2playableNodes, GridMatrix *musiKgrid,
                            LineNode *start, LineNode *end, AmarokInfo *canvas);

private:
  int counter;
};

#endif /*PLAYLISTER_H_*/
