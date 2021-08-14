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

#include "SongInfo.h"

SongInfo::SongInfo() {}

SongInfo::SongInfo(QString artist_data, QString album_data, QString title_data,
                   QString path_data) {
#if zdbug_print_function_call_trace
  cout << "SongInfo::SongInfo(QString artist_data, QString album_data, QString "
          "title_data, QString path_data)\n";
#endif
  artist = artist_data;
  album = album_data;
  title = title_data;
  path = path_data;
  type = SONG;
  songID = 0;
  next = NULL;
  prev = NULL;

  cout << "Song type: " << type << endl;
}

SongInfo::SongInfo(QString art) {
#if zdbug_print_function_call_trace
  cout << "SongInfo::SongInfo(QString data, int type)\n";
#endif

  artist = art;
  album = " ";
  title = " ";
  path = " ";
  songID = -42;
  type = LABEL;
  next = NULL;
  prev = NULL;
  cout << "Song type: " << type << endl;
}

SongInfo::~SongInfo() {
#if zdbug_print_function_call_trace
  cout << "SongInfo::~SongInfo()\n";
#endif
}
