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

#ifndef TRINITYCORE_CORO_SLEEP_H
#define TRINITYCORE_CORO_SLEEP_H

#include "./CancellableAwaiter.h"
#include "./CoroutineExecutionContext.h"
#include "./CoroutineFwd.h"
#include "AsioHacksFwd.h"
#include "Define.h"
#include "Duration.h"

namespace Trinity::Coro
{
namespace Impl
{
struct SleepAwaiter : CancellableAwaiter
{
    bool await_ready() const noexcept { return Now >= Expiry; }

    template <std::derived_from<CoroutineExecutionContext> promise_type>
    void await_suspend(std::coroutine_handle<promise_type> coroutine) noexcept
    {
        this->handle_suspend(&coroutine.promise());
    }

    void await_resume() const { CancellableAwaiter::handle_resume(); }

    TC_COMMON_API void handle_suspend(CoroutineExecutionContext* coroutine) noexcept;

    TimePoint Now;
    TimePoint Expiry;
};

class SleepAwaitable
{
public:
    explicit SleepAwaitable(TimePoint expiry) : _now(TimePoint::clock::now()), _expiry(expiry) { }
    explicit SleepAwaitable(TimePoint::duration duration) : _now(TimePoint::clock::now()), _expiry(_now + duration) { }

    SleepAwaiter operator co_await() const { return { .Now = _now, .Expiry = _expiry }; }

private:
    TimePoint _now;
    TimePoint _expiry;
};
}

// Initializes the global asio executor that handles all timers
// This function must be called before using Coro::SleepFor and Coro::SleepUntil
TC_COMMON_API void InitializeTimerExecutor(Asio::IoContext* executor);
TC_COMMON_API void ShutdownTimerExecutor();

inline Impl::SleepAwaitable SleepFor(TimePoint::duration duration) { return Impl::SleepAwaitable(duration); }
inline Impl::SleepAwaitable SleepUntil(TimePoint expiry) { return Impl::SleepAwaitable(expiry); }
}

#endif // TRINITYCORE_CORO_SLEEP_H
