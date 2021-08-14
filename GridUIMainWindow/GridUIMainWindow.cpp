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

#include "GridUIMainWindow.h"

GridUIMainWindow::GridUIMainWindow(QCanvas &c, QWidget *parent,
                                   const char *name, WFlags f)
    : QMainWindow(parent, name, f), canvas(c) {

#if zdbug_print_function_call_trace
  cout << "GridUIMainWindow::GridUIMainWindow(QCanvas& c, QWidget* parent, "
          "const char* name, WFlags f) : QMainWindow(parent,name,f), "
          "canvas(c)\n";
#endif

  editor = new GridUICanvas(canvas, this);
  lineModeButton = new QPushButton("Line Mode", this);
  artistPlotButton = new QPushButton("Plot Artist", this);
  saveFileButton = new QPushButton("Write Changes", this);
  // clearPlaylistButton = new QPushButton( "Clear Playlist", this );
  artistPlotButton->move(150, 0);
  saveFileButton->move(300, 0);

  QObject::connect(lineModeButton, SIGNAL(clicked()),
                   SLOT(lineModeButtonPress()));
  QObject::connect(artistPlotButton, SIGNAL(clicked()),
                   SLOT(artistPlotButtonPress()));
  QObject::connect(saveFileButton, SIGNAL(clicked()),
                   SLOT(saveFileButtonPress()));

  setCentralWidget(editor);
}

GridUIMainWindow::~GridUIMainWindow() {
#if zdbug_print_function_call_trace
  cout << "GridUIMainWindow::~GridUIMainWindow()\n";
#endif
}

void GridUIMainWindow::lineModeButtonPress() {
#if zdbug_print_function_call_trace
  cout << "void GridUIMainWindow::button1Clicked()\n";
#endif

  editor->toggleLineMode();
}

void GridUIMainWindow::artistPlotButtonPress() {
#if zdbug_print_function_call_trace
  cout << "void GridUIMainWindow::artistPlotButtonPress()\n";
#endif

  editor->plotArtist();
}

void GridUIMainWindow::saveFileButtonPress() {
#if zdbug_print_function_call_trace
  cout << "void GridUIMainWindow::saveFileButtonPress()\n";
#endif
  editor->writeToFile();
}
