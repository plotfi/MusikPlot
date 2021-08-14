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

#define DEFAULT_SEND_DATA 1
#define DEBUG_MODE false

#include "AmarokInfo.h"

#include <iostream>
using namespace std;

static DCOPClient *client;
static char *appname;

AmarokInfo::AmarokInfo() {
#if zdbug_print_function_call_trace
  cout << "AmarokInfo::AmarokInfo()  \n";
#endif

  client = KApplication::dcopClient();
  cout << "Registering DCOP client with server (attach)." << endl;
  client->attach();
  appname = "amarok";
}

AmarokInfo::~AmarokInfo() {
#if zdbug_print_function_call_trace
  cout << "AmarokInfo::~AmarokInfo() \n";
#endif
}

QString AmarokInfo::getCurrentAlbum() {
#if zdbug_print_function_call_trace
  cout << "QString AmarokInfo::getCurrentAlbum() \n";
#endif

#if DEBUG_MODE
  cout << "DCOP: getting Album\n";
#endif
  QByteArray data, replyData;
  QCString replyType;
  QDataStream arg(data, IO_WriteOnly);
  QStringList result;
  arg << DEFAULT_SEND_DATA;
  if (!client->call(appname, "player", "album()", data, replyType, replyData,
                    false, 5000)) {
    cout << "Error during DCOP call to " << appname << endl;
  } else {
#if DEBUG_MODE
    cout << "connectDCOPSignal to " << appname << " returned successfully!"
         << endl;
#endif
  }
  {
    QDataStream reply(replyData, IO_ReadOnly);
    if (replyType == "QString") {
      QString result;
      reply >> result;

#if DEBUG_MODE
      cout << "returning album: " << result.latin1() << endl;
#endif

#if zdbug
      if (NULL == result.latin1()) {
        cout << "NULL Album!" << endl;
      }
#endif

      return result.latin1();
    }
  }
  return NULL;
}

QString AmarokInfo::getCurrentArtist() {
#if zdbug_print_function_call_trace
  cout << "QString AmarokInfo::getCurrentArtist() \n";
#endif

#if DEBUG_MODE
  cout << "DCOP: getting Artist\n";
#endif
  QByteArray data, replyData;
  QCString replyType;
  QDataStream arg(data, IO_WriteOnly);
  QStringList result;
  arg << DEFAULT_SEND_DATA;
  if (!client->call(appname, "player", "artist()", data, replyType, replyData,
                    false, 5000)) {
    cout << "Error during DCOP call to " << appname << endl;
  } else {
#if DEBUG_MODE
    cout << "connectDCOPSignal to " << appname << " returned successfully!"
         << endl;
#endif
  }
  {
    QDataStream reply(replyData, IO_ReadOnly);
    if (replyType == "QString") {
      QString result;
      reply >> result;

#if zdbug
      if (NULL == result.latin1()) {
        cout << "NULL Artist!" << endl;
      }
#endif

      return result.latin1();
    }
  }
  return NULL;
}

QString AmarokInfo::getCurrentTitle() {
#if zdbug_print_function_call_trace
  cout << "QString AmarokInfo::getCurrentTitle() \n";
#endif

#if DEBUG_MODE
  cout << "DCOP: getting Title\n";
#endif
  QByteArray data, replyData;
  QCString replyType;
  QDataStream arg(data, IO_WriteOnly);
  QStringList result;
  arg << DEFAULT_SEND_DATA;
  if (!client->call(appname, "player", "title()", data, replyType, replyData,
                    false, 5000)) {
    cout << "Error during DCOP call to " << appname << endl;
  } else {
#if DEBUG_MODE
    cout << "connectDCOPSignal to " << appname << " returned successfully!"
         << endl;
#endif
  }
  {
    QDataStream reply(replyData, IO_ReadOnly);
    if (replyType == "QString") {
      QString result;
      reply >> result;

#if zdbug
      if (NULL == result.latin1()) {
        cout << "NULL Title!" << endl;
      }
#endif

      return result.latin1();
    }
  }
  return NULL;
}

QString AmarokInfo::getCurrentPath() {
#if zdbug_print_function_call_trace
  cout << "QString AmarokInfo::getCurrentPath()) \n";
#endif

#if DEBUG_MODE
  cout << "DCOP: getting Path\n";
#endif
  QByteArray data, replyData;
  QCString replyType;
  QDataStream arg(data, IO_WriteOnly);
  QStringList result;
  arg << DEFAULT_SEND_DATA;
  if (!client->call(appname, "player", "path()", data, replyType, replyData,
                    false, 5000)) {
    cout << "Error during DCOP call to " << appname << endl;
  } else {
#if DEBUG_MODE
    cout << "connectDCOPSignal to " << appname << " returned successfully!"
         << endl;
#endif
  }
  {
    QDataStream reply(replyData, IO_ReadOnly);
    if (replyType == "QString") {
      QString result;
      reply >> result;

#if zdbug
      if (NULL == result.latin1()) {
        cout << "NULL Path!" << endl;
      }
#endif

      return result.latin1();
    }
  }
  return NULL;
}

QString AmarokInfo::getCurrentPlay() {
#if zdbug_print_function_call_trace
  cout << "QString AmarokInfo::getCurrentPlay()) \n";
#endif

  QByteArray data, replyData;
  QCString replyType;
  QDataStream arg(data, IO_WriteOnly);
  QStringList result;
  arg << DEFAULT_SEND_DATA;
  if (!client->call(appname, "player", "play()", data, replyType, replyData,
                    false, 5000)) {
    cout << "Error during DCOP call to " << appname << endl;
  } else {
#if DEBUG_MODE
    cout << "connectDCOPSignal to " << appname << " returned successfully!"
         << endl;
#endif
  }
  {
    QDataStream reply(replyData, IO_ReadOnly);
    if (replyType == "QString") {
      QString result;
      reply >> result;

      return result.latin1();
    }
  }
  return NULL;
}

QString AmarokInfo::getCurrentStop() {
#if zdbug_print_function_call_trace
  cout << "QString AmarokInfo::getCurrentStop()  \n";
#endif

  QByteArray data, replyData;
  QCString replyType;
  QDataStream arg(data, IO_WriteOnly);
  QStringList result;
  arg << DEFAULT_SEND_DATA;
  if (!client->call(appname, "player", "stop()", data, replyType, replyData,
                    false, 5000)) {
    cout << "Error during DCOP call to " << appname << endl;
  } else {
#if DEBUG_MODE
    cout << "connectDCOPSignal to " << appname << " returned successfully!"
         << endl;
#endif
  }
  {
    QDataStream reply(replyData, IO_ReadOnly);
    if (replyType == "QString") {
      QString result;
      reply >> result;
      return result.latin1();
    }
  }
  return NULL;
}

QString AmarokInfo::getCurrentPause() {

#if zdbug_print_function_call_trace
  cout << "QString AmarokInfo::getCurrentPause() \n";
#endif

  QByteArray data, replyData;
  QCString replyType;
  QDataStream arg(data, IO_WriteOnly);
  QStringList result;
  arg << DEFAULT_SEND_DATA;
  if (!client->call(appname, "player", "pause()", data, replyType, replyData,
                    false, 5000)) {
    cout << "Error during DCOP call to " << appname << endl;
  } else {
#if DEBUG_MODE
    cout << "connectDCOPSignal to " << appname << " returned successfully!"
         << endl;
#endif
  }
  {
    QDataStream reply(replyData, IO_ReadOnly);
    if (replyType == "QString") {
      QString result;
      reply >> result;
      return result.latin1();
    }
  }
  return NULL;
}

QString AmarokInfo::clearPlaylist() {
#if zdbug_print_function_call_trace
  cout << "QString AmarokInfo::clearPlaylist() \n";
#endif

  QByteArray data, replyData;
  QCString replyType;
  QDataStream arg(data, IO_WriteOnly);
  QStringList result;
  arg << DEFAULT_SEND_DATA;
  if (!client->call(appname, "playlist", "clearPlaylist()", data, replyType,
                    replyData, false, 5000)) {
    cout << "Error during DCOP call to " << appname << endl;
  } else {
#if DEBUG_MODE
    cout << "connectDCOPSignal to " << appname << " returned successfully!"
         << endl;
#endif
  }
  {
    QDataStream reply(replyData, IO_ReadOnly);
    if (replyType == "QString") {
      QString result;
      reply >> result;

      return result.latin1();
    }
  }
  return NULL;
}

QString AmarokInfo::addSongToPlaylist(QString songPath) {
#if zdbug_print_function_call_trace
  cout << "QString AmarokInfo::addSongToPlaylist() \n";
#endif

  QByteArray data, replyData;
  QCString replyType;
  QDataStream arg(data, IO_WriteOnly);
  QStringList result;
  arg << KURL(songPath);

  cout << "Adding song: " << songPath << endl;

  if (!client->call(appname, "playlist", "addMedia(KURL)", data, replyType,
                    replyData, false, 5000)) {
    cout << "Error during DCOP call to " << appname << endl;
  } else {
#if DEBUG_MODE
    cout << "connectDCOPSignal to " << appname << " returned successfully!"
         << endl;
#endif
  }
  {
    QDataStream reply(replyData, IO_ReadOnly);
    if (replyType == "QString") {
      QString result;
      reply >> result;

      return result.latin1();
    }
  }
  return NULL;
}
