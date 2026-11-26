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

#ifndef TRINITYCORE_CORO_SWITCH_EXECUTOR_H
#define TRINITYCORE_CORO_SWITCH_EXECUTOR_H

#include "./CancellableAwaiter.h"
#include "./CoroutineFwd.h"
#include "Define.h"
#include "UniqueTrackablePtr.h"
#include <coroutine>

namespace Trinity::Coro
{
namespace Impl
{
struct SwitchToExecutorAwaiter : CancellableAwaiter
{
    bool await_ready() const noexcept { return false; }

    template <std::derived_from<CoroutineExecutionContext> promise_type>
    void await_suspend(std::coroutine_handle<promise_type> coroutine) noexcept
    {
        this->handle_suspend(&coroutine.promise());
    }

    TC_COMMON_API void handle_suspend(CoroutineExecutionContext* coroutine);

    unique_weak_ptr<Coro::Executor>&& await_resume() noexcept
    {
        CancellableAwaiter::handle_resume();
        return std::move(OldExecutor);
    }

    Coro::Executor& NewExecutor;
    unique_weak_ptr<Coro::Executor> OldExecutor;
};
}

class SwitchToExecutor
{
public:
    explicit SwitchToExecutor(Executor& executor) : _executor(executor) { }
    explicit SwitchToExecutor(unique_weak_ptr<Executor> const& executor) : _executor(resolve_executor(executor)) { }

    Impl::SwitchToExecutorAwaiter operator co_await() const && noexcept { return { .NewExecutor = _executor }; }

private:
    TC_COMMON_API static Executor& resolve_executor(unique_weak_ptr<Executor> const& executorRef);

    Executor& _executor;
};
}

#endif // TRINITYCORE_CORO_SWITCH_EXECUTOR_H
