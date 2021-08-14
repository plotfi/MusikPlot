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

#include "AmarokInfo/AmarokInfo.h"
#include "GridMatrix/GridMatrix.h"
//#include "CoordinateSongList/CoordinateSongList.h"
#include "GridUICanvas/GridUICanvas.h"
#include "GridUIMainWindow/GridUIMainWindow.h"
#include <iostream>

#define dcop_test 0

using namespace std;

/*

#include <kaboutdata.h>
#include <kapplication.h>
#include <kcmdlineargs.h>
#include <klocale.h>


static const char description[] =
    I18N_NOOP("A KDE KPart Application");

static const char version[] = "0.1";

static KCmdLineOptions options[] =
{
//    { "+[URL]", I18N_NOOP( "Document to open" ), 0 },
    KCmdLineLastOption
};
*/

int main(int argc, char **argv) {

  QApplication app(argc, argv);

  QCanvas canvas(500, 500);
  canvas.setAdvancePeriod(30);
  GridUIMainWindow m(canvas);
  m.resize(m.sizeHint());

  m.setCaption("musiKplot: The spatial musik navigator!");

  if (QApplication::desktop()->width() > m.width() + 10 &&
      QApplication::desktop()->height() > m.height() + 30)
    m.show();
  else
    m.showMaximized();

  QObject::connect(qApp, SIGNAL(lastWindowClosed()), qApp, SLOT(quit()));
  return app.exec();
}
