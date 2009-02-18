/*
    Cross-platform thread handling
    Copyright (C) 2005 Andrew Zabolotny

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public
    License along with this library; if not, write to the Free
    Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#include "Mthread.h"

#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__APPLE_CC__)
#  define TRINITY_PTHREAD_MUTEX_RECURSIVE PTHREAD_MUTEX_RECURSIVE
#else
#  define TRINITY_PTHREAD_MUTEX_RECURSIVE PTHREAD_MUTEX_RECURSIVE_NP
#endif

#if PLATFORM != PLATFORM_WINDOWS

MThread::MThread ()
{
    tid = 0;
}

MThread::~MThread ()
{
    /* Kill thread if this is not the current thread */
    if (tid && (pthread_self () != tid))
    {
        pthread_cancel (tid);
        pthread_join (tid, NULL);
    }
}

static void *thread_start_routine (void *arg)
{
    MThread *newthr = (MThread *)arg;
    pthread_setcanceltype (PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
    newthr->routine (newthr->arg);
    return NULL;
}

MThread *MThread::Start (void (*routine) (void *arg), void *arg)
{
    MThread *newthr = new MThread ();
    newthr->routine = routine;
    newthr->arg = arg;
    int rc = pthread_create (&newthr->tid, NULL, thread_start_routine, newthr);
    if (rc)
    {
        newthr->DecRef ();
        return NULL;
    }

    return newthr;
}

pthread_mutexattr_t MMutex::attr;
int MMutex::attr_refcount = 0;

MMutex::MMutex ()
{
    if (!attr_refcount++)
    {
        pthread_mutexattr_init (&attr);
        pthread_mutexattr_settype (&attr, TRINITY_PTHREAD_MUTEX_RECURSIVE);
    }

    pthread_mutex_init (&mutex, &attr);
}

MMutex::~MMutex ()
{
    pthread_mutex_destroy (&mutex);
    if (!--attr_refcount)
        pthread_mutexattr_destroy (&attr);
}

bool MMutex::Lock ()
{
    return (pthread_mutex_lock (&mutex) == 0);
}

bool MMutex::TryLock ()
{
    return (pthread_mutex_trylock (&mutex) == 0);
}

void MMutex::Unlock ()
{
    pthread_mutex_unlock (&mutex);
}

MMutex *MMutex::Create ()
{
    return new MMutex ();
}

#else                                                       //windows

MThread::MThread()
{
    th = NULL;
}

MThread::~MThread ()
{
    /* Kill thread if this is not current thread */
    if (th && (GetCurrentThreadId () != id))
    {
        TerminateThread (th, 0);
        WaitForSingleObject (th, INFINITE);
        CloseHandle (th);
    }
}

bool MThread::SetPriority (ThreadPriority prio)
{
    int p;
    switch (prio)
    {
        case IDLE:      p = THREAD_PRIORITY_IDLE; break;
        case LOWER:     p = THREAD_PRIORITY_LOWEST; break;
        case LOW:       p = THREAD_PRIORITY_BELOW_NORMAL; break;
        case NORMAL:    p = THREAD_PRIORITY_NORMAL; break;
        case HIGH:      p = THREAD_PRIORITY_ABOVE_NORMAL; break;
        case HIGHER:    p = THREAD_PRIORITY_HIGHEST; break;
        case REALTIME:  p = THREAD_PRIORITY_TIME_CRITICAL; break;
        default:        p = THREAD_PRIORITY_NORMAL; break;
    }
    return SetThreadPriority (th, p);
}

static DWORD WINAPI thread_start_routine (void *arg)
//static void thread_start_routine (void *arg)
{
    MThread *newthr = (MThread *)arg;
    newthr->id = GetCurrentThreadId ();
    newthr->routine (newthr->arg);
    return 0;
}

MThread *MThread::Start (void (*routine) (void *arg), void *arg)
{
    DWORD dwtid;
    MThread *newthr = new MThread ();
    newthr->routine = routine;
    newthr->arg = arg;
    newthr->th = CreateThread (NULL, WIN32_THREAD_STACK_SIZE, thread_start_routine, newthr, 0, &dwtid);
    //newthr->th = (HANDLE)_beginthread(thread_start_routine, 0, newthr);
    if (!newthr->th)
    {
        newthr->DecRef ();
        return NULL;
    }
    return newthr;
}

MMutex::MMutex ()
{
    sem = CreateMutex (NULL, FALSE, NULL);
}

MMutex::~MMutex ()
{
    CloseHandle (sem);
}

bool MMutex::Lock ()
{
    return (WaitForSingleObject (sem, INFINITE) != WAIT_FAILED);
}

bool MMutex::TryLock ()
{
    DWORD state = WaitForSingleObject (sem, 0);
    return (state == WAIT_OBJECT_0) && (state != WAIT_ABANDONED);
}

void MMutex::Unlock ()
{
    ReleaseMutex (sem);
}

MMutex *MMutex::Create ()
{
    MMutex *mutex = new MMutex ();
    if (!mutex->sem)
    {
        mutex->DecRef ();
        return NULL;
    }
    return mutex;
}
#endif

