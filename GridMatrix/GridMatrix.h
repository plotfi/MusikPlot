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
/** * Note: This is the GridMatrix Class
 * It provides a way to plot points on a grid
 * that can overlap, etc.
 *
 * External APIs: None Used.
 */

#ifndef GRIDMATRIX_H_
#define GRIDMATRIX_H_

#define matrix_column_depth 500
#define matrix_row_depth 500
// HACK

#include <fstream>
#include <iostream>
#include <sstream>

#include "../AmarokInfo/AmarokInfo.h"
#include "../PuyansList/PuyansList.h"
#include "../PuyansListNode/PuyansListNode.h"
#include "../SongInfo/SongInfo.h"
#include "../ZDBug/ZDBug.h"
//#include "../CoordinateSongList/CoordinateSongList.h"

using namespace std;

class GridMatrix {
public:
  GridMatrix();
  virtual ~GridMatrix();
  int addSong(int row, int column, songInfoType type);
  int addSongByInfo(int row, int column, SongInfo *songToAdd);
  PuyansList *getObjectFromCoordinate(int row, int column);
  int get_grid_matrix_marker(int row, int column);
  int set_grid_matrix_marker(int row, int column, int marker);
  AmarokInfo *getSongInfoFromAmarok;
  void print_grid_matrix_content();
  int get_grid_matrix_content(int row, int column);

private:
  ofstream writefile;
  bool writefile_open;
  PuyansList **grid_matrix[matrix_column_depth];
  int grid_matrix_marker[matrix_column_depth][matrix_row_depth];
};

#endif /*GRIDMATRIX_H_*/
