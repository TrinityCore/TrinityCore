/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2008 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Threading.h"
#include "Errors.h"
#include <ace/OS_NS_unistd.h>
#include <ace/Sched_Params.h>
#include <vector>

using namespace ACE_Based;

ThreadPriority::ThreadPriority()
{
    for (int i = Idle; i < MAXPRIORITYNUM; ++i)
        m_priority[i] = ACE_THR_PRI_OTHER_DEF;

    m_priority[Idle] = ACE_Sched_Params::priority_min(ACE_SCHED_OTHER);
    m_priority[Realtime] = ACE_Sched_Params::priority_max(ACE_SCHED_OTHER);

    std::vector<int> _tmp;

    ACE_Sched_Params::Policy _policy = ACE_SCHED_OTHER;
    ACE_Sched_Priority_Iterator pr_iter(_policy);

    while (pr_iter.more())
    {
        _tmp.push_back(pr_iter.priority());
        pr_iter.next();
    }

    ASSERT (!_tmp.empty());

    if (_tmp.size() >= MAXPRIORITYNUM)
    {
        const size_t max_pos = _tmp.size();
        size_t min_pos = 1;
        size_t norm_pos = 0;
        for (size_t i = 0; i < max_pos; ++i)
        {
            if (_tmp[i] == ACE_THR_PRI_OTHER_DEF)
            {
                norm_pos = i + 1;
                break;
            }
        }

        // since we have only 7(seven) values in enum Priority
        // and 3 we know already (Idle, Normal, Realtime) so
        // we need to split each list [Idle...Normal] and [Normal...Realtime]
        // into pieces
        const size_t _divider = 4;
        size_t _div = (norm_pos - min_pos) / _divider;
        if (_div == 0)
            _div = 1;

        min_pos = (norm_pos - 1);

        m_priority[Low] = _tmp[min_pos -= _div];
        m_priority[Lowest] = _tmp[min_pos -= _div ];

        _div = (max_pos - norm_pos) / _divider;
        if (_div == 0)
            _div = 1;

        min_pos = norm_pos - 1;

        m_priority[High] = _tmp[min_pos += _div];
        m_priority[Highest] = _tmp[min_pos += _div];
    }
}

int ThreadPriority::getPriority(Priority p) const
{
    if (p < Idle)
        p = Idle;

    if (p > Realtime)
        p = Realtime;

    return m_priority[p];
}

#define THREADFLAG (THR_NEW_LWP | THR_SCHED_DEFAULT| THR_JOINABLE)

Thread::Thread(): m_iThreadId(0), m_hThreadHandle(0), m_task(0)
{

}

Thread::Thread(Runnable* instance): m_iThreadId(0), m_hThreadHandle(0), m_task(instance)
{
    // register reference to m_task to prevent it deeltion until destructor
    if (m_task)
        m_task->incReference();

    bool _start = start();
    ASSERT (_start);
}

Thread::~Thread()
{
    //Wait();

    // deleted runnable object (if no other references)
    if (m_task)
        m_task->decReference();
}

//initialize Thread's class static member
Thread::ThreadStorage Thread::m_ThreadStorage;
ThreadPriority Thread::m_TpEnum;

bool Thread::start()
{
    if (m_task == 0 || m_iThreadId != 0)
        return false;

    // incRef before spawing the thread, otherwise Thread::ThreadTask() might call decRef and delete m_task
    m_task->incReference();

    bool res = (ACE_Thread::spawn(&Thread::ThreadTask, (void*)m_task, THREADFLAG, &m_iThreadId, &m_hThreadHandle) == 0);

    if (!res)
        m_task->decReference();

    return res;
}

bool Thread::wait()
{
    if (!m_hThreadHandle || !m_task)
        return false;

    ACE_THR_FUNC_RETURN _value = ACE_THR_FUNC_RETURN(-1);
    int _res = ACE_Thread::join(m_hThreadHandle, &_value);

    m_iThreadId = 0;
    m_hThreadHandle = 0;

    return (_res == 0);
}

void Thread::destroy()
{
    if (!m_iThreadId || !m_task)
        return;

    if (ACE_Thread::kill(m_iThreadId, -1) != 0)
        return;

    m_iThreadId = 0;
    m_hThreadHandle = 0;

    // reference set at ACE_Thread::spawn
    m_task->decReference();
}

void Thread::suspend()
{
    ACE_Thread::suspend(m_hThreadHandle);
}

void Thread::resume()
{
    ACE_Thread::resume(m_hThreadHandle);
}

ACE_THR_FUNC_RETURN Thread::ThreadTask(void * param)
{
    Runnable* _task = (Runnable*)param;
    _task->run();

    // task execution complete, free referecne added at
    _task->decReference();

    return (ACE_THR_FUNC_RETURN)0;
}

ACE_thread_t Thread::currentId()
{
    return ACE_Thread::self();
}

ACE_hthread_t Thread::currentHandle()
{
    ACE_hthread_t _handle;
    ACE_Thread::self(_handle);

    return _handle;
}

Thread * Thread::current()
{
    Thread * _thread = m_ThreadStorage.ts_object();
    if (!_thread)
    {
        _thread = new Thread();
        _thread->m_iThreadId = Thread::currentId();
        _thread->m_hThreadHandle = Thread::currentHandle();

        Thread * _oldValue = m_ThreadStorage.ts_object(_thread);
        if (_oldValue)
            delete _oldValue;
    }

    return _thread;
}

void Thread::setPriority(Priority type)
{
    int _priority = m_TpEnum.getPriority(type);
    int _ok = ACE_Thread::setprio(m_hThreadHandle, _priority);
    //remove this ASSERT in case you don't want to know is thread priority change was successful or not
    ASSERT (_ok == 0);
}

void Thread::Sleep(unsigned long msecs)
{
    ACE_OS::sleep(ACE_Time_Value(0, 1000 * msecs));
}
