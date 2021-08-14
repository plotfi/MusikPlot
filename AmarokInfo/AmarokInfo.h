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
 * Note: This is the AmarokInfo Class
 *
 * Provides a means for comunicating
 * with the external Music player: Amarok
 *
 * External APIs: KDE API
 *        - KDECORE: kapplication
 *        - DCOP:    dcopclient
 */

#ifndef AMAROKINFO_H_
#define AMAROKINFO_H_

#include "../ZDBug/ZDBug.h"
#include <dcopclient.h>
#include <kapplication.h>
#include <kurl.h>

class AmarokInfo {
public:
  AmarokInfo();
  virtual ~AmarokInfo();
  QString getCurrentAlbum();
  QString getCurrentArtist();
  QString getCurrentTitle();
  QString getCurrentPath();
  QString getCurrentPlay();
  QString getCurrentStop();
  QString getCurrentPause();
  QString clearPlaylist();
  QString addSongToPlaylist(QString songPath);
};

#endif /*AMAROKINFO_H_*/
