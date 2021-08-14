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

#include "PuyansList.h"
#include "../ZDBug/ZDBug.h"

PuyansList::PuyansList() {
#if zdbug_print_function_call_trace
  cout << "PuyansList::PuyansList()\n";
#endif
  qHead = NULL;
  qTail = NULL;
}

PuyansList::~PuyansList() {
#if zdbug_print_function_call_trace
  cout << "PuyansList::~PuyansList()\n";
#endif
}

void PuyansList::qAdd(PuyansListNode *new_node) {
#if zdbug_print_function_call_trace
  cout << "void PuyansList::qAdd(PuyansListNode* new_node)\n";
#endif

  if (NULL == new_node) {
#if zdbug
    cout << "Invalid Request (NULL).\n";
#endif
    return;
  } else {
#if zdbug
    cout << "Adding Node to List " << endl;
#endif
    new_node->next = new_node;
    new_node->prev = new_node;
    if (-1 == new_node->nodeID)
      new_node->nodeID = count;
  }

#if zdbug
  cout << "Checkpoint one" << endl;
#endif

  // printf("Adding %s\n", new_song->rules);

  // pthread_mutex_lock(IARequestQueue::get_mutex());

  if (NULL == qHead) {
#if zdbug
    cout << "Checkpoint one.1: empty list, adding new" << endl;
#endif
    // new_request->next = new_request->prev = new_request;
    qTail = new_node;
    qHead = new_node;

    // printf("1) %s Head: %d Tail: %d New: %d\n", qHead->rules, qHead, qTail,
    // new_request);
    length++;
    count++;
  } else {
// printf("2) %s Head: %d Tail: %d New: %d\n", qHead->rules, qHead, qTail,
// new_request);
#if zdbug
    cout << "Checkpoint one.2: adding another element" << endl;
#endif
    qTail->next = new_node;
    qHead->prev = new_node;
    new_node->prev = qTail;
    new_node->next = qHead;
    qTail = qTail->next; // the new_request is the new head
// printf("3) %s Head: %d Tail: %d New: %d\n", qHead->rules, qHead, qTail,
// new_request);
#if zdbug
    cout << "Checkpoint one.3: adding another element" << endl;
#endif
    length++;
    count++;
  }
#if zdbug
  cout << "Checkpoint two" << endl;
#endif
  // pthread_mutex_unlock(IARequestQueue::get_mutex());
  // pthread_cond_signal(IARequestQueue::get_is_ready());
}

PuyansListNode *PuyansList::qRemove(int nodeID) {
#if zdbug_print_function_call_trace
  cout << "PuyansList::qRemove(int nodeID)\n";
#endif

  PuyansListNode *temp;

  // pthread_mutex_lock(IARequestQueue::get_mutex());            //Lock mutex

  // while (!qHead) {
  //    pthread_cond_wait( IARequestQueue::get_is_ready(),
  //    IARequestQueue::get_mutex() );  //No requests waiting
  //}

  temp = qHead;

  // Fix the list
  if (length > 1) {
    qHead = qHead->next;
    if (2 == length)
      qTail = qHead;
    qHead->prev = qTail;
    qTail->next = qHead;
  } else {
    qHead = qTail = NULL;
  }

  length--;

  // Fine grain lock, release lock before freeing old node
  // pthread_mutex_unlock(IARequestQueue::get_mutex());

  // check if I need to signal a condition.

  return temp;
  // Make sure to free this
}
