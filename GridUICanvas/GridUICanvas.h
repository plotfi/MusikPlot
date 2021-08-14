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

#include <qcanvas.h>
#include <qpainter.h>
#include <qstring.h>

#include "../AmarokInfo/AmarokInfo.h"
#include "../GridMatrix/GridMatrix.h"
#include "../LineCollection/LineCollection.h"
#include "../PlayLister/PlayLister.h"
#include "../PuyansList/PuyansList.h"
#include "../SongInfo/SongInfo.h"
#include "../ZDBug/ZDBug.h"

#ifndef GRIDUICANVAS_H_
#define GRIDUICANVAS_H_

class GridUICanvas : public QCanvasView {
  Q_OBJECT
public:
  GridUICanvas(QWidget *parent = 0, const char *name = 0);
  GridUICanvas(QCanvas &, QWidget *parent = 0, const char *name = 0,
               WFlags f = 0);
  virtual ~GridUICanvas();
  void clear();
  QCanvasText *current_song;
  void toggleLineMode();
  void plotArtist();
  void writeToFile();
  int lastX;
  int lastY;
  bool startedLine;

protected:
  void contentsMousePressEvent(QMouseEvent *);
  void contentsMouseMoveEvent(QMouseEvent *);

signals:
  void status(const QString &);

private:
  void assembleBackend();
  void teardownBackend();
  QCanvasItem *moving;
  QPoint moving_start;
  GridMatrix *canvas_backend;
  bool linemode;
  bool artistplotmode;
  LineCollection *playlistPath;
  // AmarokInfo* amarok_com_backend;
  PlayLister lineplaylistprocessor;
  QCanvasLine *preline;
};

#endif /*GRIDUICANVAS_H_*/
