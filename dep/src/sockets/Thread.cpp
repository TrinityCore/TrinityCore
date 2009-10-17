/** \file Thread.cpp
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
#include <stdio.h>
#ifdef _WIN32
#include <process.h>
#include "socket_include.h"
#else
#include <unistd.h>
#endif
#include "Thread.h"

#ifdef SOCKETS_NAMESPACE
namespace SOCKETS_NAMESPACE {
#endif

Thread::Thread(bool release)
:m_thread(0)
,m_running(true)
,m_release(false)
,m_b_delete_on_exit(false)
,m_b_destructor(false)
{
#ifdef _WIN32
//  m_thread = ::CreateThread(NULL, 0, StartThread, this, 0, &m_dwThreadId);
    m_thread = (HANDLE)_beginthreadex(NULL, 0, &StartThread, this, 0, &m_dwThreadId);
#else
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
    if (pthread_create(&m_thread,&attr, StartThread,this) == -1)
    {
        perror("Thread: create failed");
        SetRunning(false);
    }
//  pthread_attr_destroy(&attr);
#endif
    m_release = release;
}

Thread::~Thread()
{
    m_b_destructor = true;
    if (m_running)
    {
        SetRelease(true);
        SetRunning(false);
#ifdef _WIN32
        Sleep(1000);
#else
        sleep(1);
#endif
    }
#ifdef _WIN32
    if (m_thread)
        ::CloseHandle(m_thread);
#endif
}

threadfunc_t STDPREFIX Thread::StartThread(threadparam_t zz)
{
    Thread *p = (Thread *)zz;
    while (p -> m_running && !p -> m_release)
    {
#ifdef _WIN32
        Sleep(1000);
#else
        sleep(1);
#endif
    }
    if (p -> m_running)
    {
        p -> Run();
    }
    p -> SetRunning(false); // if return
    if (p -> DeleteOnExit() && !p -> IsDestructor())
    {
        delete p;
    }
#ifdef _WIN32
    _endthreadex(0);
#endif
    return (threadfunc_t)NULL;
}

bool Thread::IsRunning()
{
    return m_running;
}

void Thread::SetRunning(bool x)
{
    m_running = x;
}

bool Thread::IsReleased()
{
    return m_release;
}

void Thread::SetRelease(bool x)
{
    m_release = x;
}

bool Thread::DeleteOnExit()
{
    return m_b_delete_on_exit;
}

void Thread::SetDeleteOnExit(bool x)
{
    m_b_delete_on_exit = x;
}

bool Thread::IsDestructor()
{
    return m_b_destructor;
}

#ifdef SOCKETS_NAMESPACE
}
#endif


