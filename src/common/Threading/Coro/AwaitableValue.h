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

#ifndef TRINITYCORE_CORO_AWAITABLE_VALUE_H
#define TRINITYCORE_CORO_AWAITABLE_VALUE_H

#include "./CoroutineFwd.h"
#include "./ResultValue.h"
#include "Define.h"
#include <atomic>
#include <concepts>
#include <coroutine>

namespace Trinity::Coro
{
namespace Impl
{
class AwaitableValueBase;

struct AwaitableValueAwaiterData
{
    AwaitableValueAwaiterData const* Next = nullptr;
    CoroutineExecutionContext* Coroutine = nullptr;
};

struct TC_COMMON_API AwaitableValueAwaiterBase : AwaitableValueAwaiterData
{
    explicit AwaitableValueAwaiterBase(AwaitableValueBase& value) noexcept : Value(value) { }

    bool await_ready() const noexcept;

    template <std::derived_from<CoroutineExecutionContext> promise_type>
    bool await_suspend(std::coroutine_handle<promise_type> coroutine) noexcept
    {
        return this->handle_suspend(&coroutine.promise());
    }

private:
    bool handle_suspend(CoroutineExecutionContext* coroutine) noexcept;

protected:
    void handle_resume();

    AwaitableValueBase& Value;
};

class TC_COMMON_API AwaitableValueBase
{
protected:
    void notify_waiters();

    bool reset_waiters();

    friend AwaitableValueAwaiterBase;
    std::atomic<AwaitableValueAwaiterData const*> _waitQueue;
};
}

template <typename T>
class AwaitableValue : public Impl::AwaitableValueBase
{
public:
    template <bool RValue>
    struct Awaiter : Impl::AwaitableValueAwaiterBase
    {
        explicit Awaiter(AwaitableValue& value) noexcept : AwaitableValueAwaiterBase(value) { }

        decltype(auto) await_resume()
        {
            handle_resume();
            if constexpr (RValue)
                return std::move(static_cast<AwaitableValue&>(Value)._resultValue).get();
            else
                return static_cast<AwaitableValue&>(Value)._resultValue.get();
        }
    };

    explicit AwaitableValue() noexcept = default;
    AwaitableValue(AwaitableValue const&) = delete;
    AwaitableValue(AwaitableValue&&) = delete;
    AwaitableValue& operator=(AwaitableValue const&) = delete;
    AwaitableValue& operator=(AwaitableValue&&) = delete;
    ~AwaitableValue() = default;

    template <std::convertible_to<typename ResultValue<T>::value_holder> V>
    void set_value(V&& value) requires (!std::same_as<T, void>)
    {
        _resultValue.set_value(std::forward<V>(value));

        this->notify_waiters();
    }

    void set_value() requires (std::same_as<T, void>)
    {
        _resultValue.set_value();

        this->notify_waiters();
    }

    void reset() noexcept
    {
        if (this->reset_waiters())
            _resultValue.reset();
    }

    Awaiter<false> operator co_await() & noexcept { return Awaiter<false>(*this); }
    Awaiter<true> operator co_await() && noexcept { return Awaiter<true>(*this); }

private:
    template <bool>
    friend struct Awaiter;
    ResultValue<T> _resultValue;
};
}

#endif // TRINITYCORE_CORO_AWAITABLE_VALUE_H
