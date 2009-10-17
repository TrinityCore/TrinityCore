/** \file Thread.h
 ** \date  2004-10-30
 ** \author grymse@alhem.net
**/
/*
Copyright (C) 2004-2007  Anders Hedstrom
This library is made available under the terms of the GNU GPL.
If you would like to use this library in a closed-source application,
a separate license agreement is available. For information about
the closed-source license agreement for the C++ sockets library,
please visit http://www.alhem.net/Sockets/license.html and/or
email license@alhem.net.
This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/
#ifndef _SOCKETS_Thread_H
#define _SOCKETS_Thread_H
#include "sockets-config.h"
#ifdef SOCKETS_NAMESPACE
namespace SOCKETS_NAMESPACE {
#endif
#ifdef _WIN32
// to be
//typedef DWORD  threadfunc_t;
//typedef LPVOID threadparam_t;
//#define STDPREFIX WINAPI
typedef unsigned threadfunc_t;
typedef void * threadparam_t;
#define STDPREFIX __stdcall
#else
#include <pthread.h>
typedef void * threadfunc_t;
typedef void * threadparam_t;
#define STDPREFIX
#endif
/** \defgroup threading Threading */
/** Thread base class.
The Thread class is used by the resolver (ResolvServer) and running a detached socket (SocketThread).
When you know some processing will take a long time and will freeze up a socket, there is always the
possibility to call Detach() on that socket before starting the processing.
When the OnDetached() callback is later called the processing can continue, now in its own thread.
    \ingroup threading */
class Thread
{
public:
    Thread(bool release = true);
    virtual ~Thread();
    static threadfunc_t STDPREFIX StartThread(threadparam_t);
    virtual void Run() = 0;
    bool IsRunning();
    void SetRunning(bool x);
    bool IsReleased();
    void SetRelease(bool x);
    bool DeleteOnExit();
    void SetDeleteOnExit(bool x = true);
    bool IsDestructor();
private:
    Thread(const Thread& ) {}
    Thread& operator=(const Thread& ) { return *this; }
#ifdef _WIN32
    HANDLE m_thread;
    unsigned m_dwThreadId;
#else
    pthread_t m_thread;
#endif
    bool m_running;
    bool m_release;
    bool m_b_delete_on_exit;
    bool m_b_destructor;
};

#ifdef SOCKETS_NAMESPACE
}
#endif
#endif // _SOCKETS_Thread_H

