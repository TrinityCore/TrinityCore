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

#ifndef TRINITYCORE_CORO_START_H
#define TRINITYCORE_CORO_START_H

#include "./Awaitable.h"
#include "./CoroutineExecutionContext.h"
#include "./CoroutineFwd.h"
#include "Concepts.h"
#include "Define.h"
#include <functional>

namespace Trinity::Coro
{
namespace Impl
{
struct CoroutineEntryPoint
{
    struct InitialAwaiter
    {
        constexpr bool await_ready() const noexcept { return false; }
        constexpr void await_suspend(std::coroutine_handle<>) const noexcept { }
        void await_resume() const
        {
            if (CancelToken.stop_requested())
                throw_cancelled_exception();
        }

        advstd::stop_token& CancelToken;
    };

    struct promise_type final : CoroutineExecutionContext
    {
        promise_type() : CoroutineExecutionContext(std::coroutine_handle<promise_type>::from_promise(*this)) { }

        CoroutineEntryPoint get_return_object() noexcept;

        InitialAwaiter initial_suspend() noexcept { return { .CancelToken = CancelToken }; }

        std::suspend_never final_suspend() noexcept { return { }; }

        void return_void() noexcept { }

        TC_COMMON_API void unhandled_exception() noexcept;
    };

    TC_COMMON_API void Start(Executor& executor, advstd::stop_token&& cancelToken);

    CoroutineExecutionContext* Context = nullptr;
};

inline CoroutineEntryPoint CoroutineEntryPoint::promise_type::get_return_object() noexcept
{
    return { .Context = this };
}

TC_COMMON_API CoroutineEntryPoint Start(std::function<Awaitable<void>()> awaitableSource) noexcept;
}

template <typename CoroutineInitFunc>
requires (invocable_r<CoroutineInitFunc, Awaitable<void>>
            && std::is_rvalue_reference_v<CoroutineInitFunc&&>
            && !std::is_const_v<std::remove_reference_t<CoroutineInitFunc>>)
void Start(Executor& executor, CoroutineInitFunc&& coroutineInit, advstd::stop_token cancelToken = {})
{
    Impl::CoroutineEntryPoint entryPoint = Impl::Start(std::forward<CoroutineInitFunc>(coroutineInit));
    entryPoint.Start(executor, std::move(cancelToken));
}
}

#endif // TRINITYCORE_CORO_START_H
