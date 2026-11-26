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

#include "./Start.h"
#include "./Allocator.h"
#include "./AllocatorImpl.h"
#include "./CurrentCoroutine.h"
#include "./Executor.h"
#include "Errors.h"
#include "Memory.h"

namespace Trinity::Coro::Impl
{
void CoroutineEntryPoint::promise_type::unhandled_exception() noexcept
try
{
    std::rethrow_exception(std::current_exception());
}
catch (CancelledException const&)
{
    // ignored, exception is used to trigger full cleanup of coroutine state
}
catch (std::exception const& e)
{
    ABORT_MSG("Unhandled coroutine exception: %s", e.what());
}
catch (...)
{
    ABORT_MSG("Unhandled coroutine exception: UNKNOWN");
}

void CoroutineEntryPoint::Start(Executor& executor, advstd::stop_token&& cancelToken)
{
    Context->CurrentExecutor = executor.weak_from_this();
    Context->CancelToken = std::move(cancelToken);
    Context->QueueCompletion();
}

CoroutineEntryPoint Start(std::function<Awaitable<void>()> awaitableSource) noexcept
{
    Allocator allocator;
    CurrentAllocator::Set(&allocator);
    auto allocatorGuard = Trinity::make_unique_ptr_with_deleter<[](void*){ CurrentAllocator::Set(nullptr); }>(&allocator);

    (co_await CurrentContext)->CurrentAllocator = &allocator;

    Awaitable<void> awaitable = awaitableSource();

    co_await awaitable;
}
}
