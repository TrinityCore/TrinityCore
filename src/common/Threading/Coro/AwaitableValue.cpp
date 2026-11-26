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

#include "./AwaitableValue.h"
#include "./CancellableAwaiter.h"
#include "./CoroutineExecutionContext.h"

namespace Trinity::Coro::Impl
{
namespace
{
    constexpr AwaitableValueAwaiterData READY_MARKER;
}

bool AwaitableValueAwaiterBase::await_ready() const noexcept
{
    return Value._waitQueue.load(std::memory_order::acquire) == &READY_MARKER;
}

bool AwaitableValueAwaiterBase::handle_suspend(CoroutineExecutionContext* coroutine) noexcept
{
    Coroutine = coroutine;

    AwaitableValueAwaiterData const* old = Value._waitQueue.load(std::memory_order::acquire);
    do
    {
        if (old == &READY_MARKER)
            return false; // value is now ready, don't suspend

        Next = old;
    } while (!Value._waitQueue.compare_exchange_weak(old, this, std::memory_order::release, std::memory_order::acquire));

    return true;
}

void AwaitableValueAwaiterBase::handle_resume()
{
    if (Coroutine && Coroutine->CancelToken.stop_requested())
        throw_cancelled_exception();
}

void AwaitableValueBase::notify_waiters()
{
    AwaitableValueAwaiterData const* waiter = _waitQueue.exchange(&READY_MARKER, std::memory_order::acq_rel);
    if (waiter != &READY_MARKER)
    {
        while (waiter)
        {
            AwaitableValueAwaiterData const* next = waiter->Next;
            waiter->Coroutine->QueueCompletion();
            waiter = next;
        }
    }
}

bool AwaitableValueBase::reset_waiters()
{
    AwaitableValueAwaiterData const* old = &READY_MARKER;
    return _waitQueue.compare_exchange_strong(old, nullptr, std::memory_order::acquire);
}
}
