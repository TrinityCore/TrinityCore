/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "./Executor.h"
#include "./Allocator.h"
#include "./AsioExecutorAdapter.h"
#include "./MultiThreadedExecutor.h"
#include "./SingleThreadedExecutor.h"
#include "IoContext.h"

namespace Trinity::Coro
{
void CoroutineExecutionContext::Resume() noexcept
{
    Impl::CurrentAllocator::Set(CurrentAllocator);
    Handle.resume();
}

void CoroutineExecutionContext::QueueCompletion() noexcept
{
    if (unique_strong_ref_ptr<Executor> executor = CurrentExecutor.lock())
        executor->QueueCompletion(this);
    else
        Handle.destroy();
}

void Executor::QueueCompletion(CoroutineExecutionContext* context)
{
    context->CurrentExecutor = weak_from_this();
}

void AsioExecutorAdapter::QueueCompletion(CoroutineExecutionContext* context)
{
    Executor::QueueCompletion(context);

    Trinity::Asio::post(_ioContext, [context]
    {
        context->Resume();
    });
}

void MultiThreadedExecutor::QueueCompletion(CoroutineExecutionContext* context)
{
    Executor::QueueCompletion(context);

    std::scoped_lock lock(_mutex);

    _resumeQueue.push_back(*context);

    _condition.notify_one();
}

void MultiThreadedExecutor::ResumeReadyCoroutines()
{
    do
    {
        CoroutineExecutionContext* coroutine;
        {
            std::scoped_lock lock(_mutex);
            if (_resumeQueue.empty())
                break;

            coroutine = &_resumeQueue.front();
            _resumeQueue.pop_front();
        }

        coroutine->Resume();

    } while (true);
}

void MultiThreadedExecutor::WaitForReadyCoroutinesAndResume()
{
    do
    {
        CoroutineExecutionContext* coroutine;
        {
            std::unique_lock lock(_mutex);

            _condition.wait(lock, [&] { return !_resumeQueue.empty() || _stopped.test(std::memory_order::relaxed); });
            if (_resumeQueue.empty())
                break;

            coroutine = &_resumeQueue.front();
            _resumeQueue.pop_front();
        }

        coroutine->Resume();

    } while (true);
}

bool MultiThreadedExecutor::WaitForReadyCoroutinesAndResume(Milliseconds timeout)
{
    do
    {
        CoroutineExecutionContext* coroutine;
        {
            std::unique_lock lock(_mutex);

            if (!_condition.wait_for(lock, timeout, [&] { return !_resumeQueue.empty() || _stopped.test(std::memory_order::relaxed); }))
                return false;

            if (_resumeQueue.empty())
                break;

            coroutine = &_resumeQueue.front();
            _resumeQueue.pop_front();
        }

        coroutine->Resume();

    } while (true);

    return true;
}

void MultiThreadedExecutor::StopWaiting()
{
    std::scoped_lock lock(_mutex);

    _stopped.test_and_set(std::memory_order::relaxed);

    _condition.notify_all();
}

void SingleThreadedExecutor::QueueCompletion(CoroutineExecutionContext* context)
{
    Executor::QueueCompletion(context);

    _resumeQueue.Enqueue(context);
}

void SingleThreadedExecutor::ResumeReadyCoroutines()
{
    CoroutineExecutionContext* context = nullptr;
    while (_resumeQueue.Dequeue(context))
        context->Resume();
}
}
