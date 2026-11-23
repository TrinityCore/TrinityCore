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

#ifndef TRINITYCORE_CURRENT_COROUTINE_H
#define TRINITYCORE_CURRENT_COROUTINE_H

#include "./CoroutineExecutionContext.h"
#include "./CoroutineFwd.h"

namespace Trinity::Coro
{
namespace Impl
{
struct CurrentCoroutineBaseAwaiter
{
    bool await_ready() const noexcept { return false; }

    template <std::derived_from<CoroutineExecutionContext> promise_type>
    bool await_suspend(std::coroutine_handle<promise_type> coroutine) noexcept
    {
        Context = &coroutine.promise();
        return false;
    }

    CoroutineExecutionContext* Context = nullptr;
};

struct CurrentExecutorAwaiter : CurrentCoroutineBaseAwaiter
{
    unique_weak_ptr<Executor> await_resume() const noexcept { return Context->CurrentExecutor; }
};
}

struct CurrentExecutorAwaitable
{
    Impl::CurrentExecutorAwaiter operator co_await() const noexcept { return { }; }
} inline constexpr CurrentExecutor;
}

#endif // TRINITYCORE_CURRENT_COROUTINE_H
