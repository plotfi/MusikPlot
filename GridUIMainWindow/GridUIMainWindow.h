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

#include <qapplication.h>
#include <qcanvas.h>
#include <qmainwindow.h>
#include <qpushbutton.h>

#include "../GridUICanvas/GridUICanvas.h"
#include "../ZDBug/ZDBug.h"

#ifndef GRIDUIMAINWINDOW_H_
#define GRIDUIMAINWINDOW_H_
class GridUIMainWindow : public QMainWindow {
  Q_OBJECT
public:
  GridUIMainWindow(QCanvas &, QWidget *parent = 0, const char *name = 0,
                   WFlags f = 0);
  virtual ~GridUIMainWindow();

private slots:
  void lineModeButtonPress();
  void artistPlotButtonPress();
  void saveFileButtonPress();

private:
  QPushButton *lineModeButton;
  QPushButton *artistPlotButton;
  QPushButton *saveFileButton;
  QCanvas &canvas;
  GridUICanvas *editor;
};

#endif /*GRIDUIMAINWINDOW_H_*/
