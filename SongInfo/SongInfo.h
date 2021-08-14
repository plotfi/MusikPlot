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

/**
 * Note: This is the SongInfo Class
 *
 * This is a linked list implementation.
 *
 * External APIs: KDE
 *        - KDECORE: kapplication
 *  note: damn this was lazy...
 *         I shouldn't just depend
 *         on their stupid string
 *         implementation like that.
 */

#include "../PuyansListNode/PuyansListNode.h"
#include "../ZDBug/ZDBug.h"
#include <kapplication.h>
#ifndef SONGINFO_H_
#define SONGINFO_H_

typedef enum { LABEL, SONG } songInfoType;

enum { col, row, type, artist, album, song, path };

class SongInfo {
public:
  SongInfo();
  SongInfo(QString artist_data, QString album_data, QString title_data,
           QString path_data);
  SongInfo(QString artist_data);
  virtual ~SongInfo();
  QString artist;
  QString album;
  QString title;
  QString path;
  songInfoType type;
  inline int getType() { return (int)type; };
  PuyansListNode *tolist;
  class SongInfo *next;
  class SongInfo *prev;
  int songID;

private:
};

#endif /*SONGINFO_H_*/
