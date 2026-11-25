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

#ifndef TRINITYCORE_CORO_EXECUTION_CONTEXT_H
#define TRINITYCORE_CORO_EXECUTION_CONTEXT_H

#include "./Allocator.h"
#include "./CoroutineFwd.h"
#include "UniqueTrackablePtr.h"
#include "advstd_stop_token.h"
#include <atomic>
#include <coroutine>

namespace Trinity::Coro
{
struct CoroutineExecutionContext
{
    explicit CoroutineExecutionContext(std::coroutine_handle<> handle) noexcept : Handle(handle) { }

    TC_COMMON_API void Resume() noexcept;
    TC_COMMON_API void QueueCompletion() noexcept;

    std::atomic<CoroutineExecutionContext*> QueueLink;
    std::coroutine_handle<> Handle;
    unique_weak_ptr<Executor> CurrentExecutor;
    Impl::Allocator* CurrentAllocator = Impl::CurrentAllocator::Get();
    advstd::stop_token CancelToken;
};
}

#endif // TRINITYCORE_CORO_EXECUTION_CONTEXT_H
