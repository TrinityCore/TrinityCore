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

#ifndef TRINITYCORE_CORO_AWAITABLE_H
#define TRINITYCORE_CORO_AWAITABLE_H

#include "./Allocator.h"
#include "./CoroutineExecutionContext.h"
#include "./CoroutineFwd.h"
#include "./ResultValue.h"
#include <concepts>
#include <coroutine>
#include <exception>
#include <utility>

namespace Trinity::Coro
{
namespace Impl
{
class PromiseBase : public CoroutineExecutionContext
{
public:
    explicit PromiseBase(std::coroutine_handle<> handle) : CoroutineExecutionContext(handle) { }

    struct FinalAwaitable
    {
        bool await_ready() const noexcept { return false; }

        template <std::derived_from<PromiseBase> promise_type>
        std::coroutine_handle<> await_suspend(std::coroutine_handle<promise_type> coroutine) noexcept
        {
            promise_type& promise = coroutine.promise();
            return promise.Next ? promise.Next : std::noop_coroutine();
        }

        void await_resume() noexcept { }
    };

    template <std::derived_from<CoroutineExecutionContext> promise_type>
    void set_next(std::coroutine_handle<promise_type> next)
    {
        Next = next;
        CurrentExecutor = next.promise().CurrentExecutor;
    }

protected:
    std::coroutine_handle<> Next;
};

template <typename T>
class Promise : public PromiseBase
{
public:
    Promise() : PromiseBase(std::coroutine_handle<Promise>::from_promise(*this)) { }

    Awaitable<T> get_return_object() noexcept;

    std::suspend_always initial_suspend() noexcept { return { }; }

    FinalAwaitable final_suspend() noexcept { return { }; }

    template <std::convertible_to<typename ResultValue<T>::value_holder> V>
    void return_value(V&& value) { _resultValue.set_value(std::forward<V>(value)); }

    void unhandled_exception() { _resultValue.set_exception(std::current_exception()); }

    T& get_result() & { return _resultValue.get(); }

    T&& get_result() && { return std::move(_resultValue).get(); }

    bool has_result() const { return _resultValue.has_value_or_exception(); }

    void* operator new(std::size_t size)
    {
        return CurrentAllocator::Allocate(size);
    }

    void operator delete(void* ptr, std::size_t size) noexcept
    {
        CurrentAllocator::Free(ptr, size);
    }

private:
    ResultValue<T> _resultValue;
};

template <>
class Promise<void> : public PromiseBase
{
public:
    Promise() : PromiseBase(std::coroutine_handle<Promise>::from_promise(*this)) { }

    Awaitable<void> get_return_object() noexcept;

    std::suspend_always initial_suspend() noexcept { return { }; }

    FinalAwaitable final_suspend() noexcept { return { }; }

    void return_void() { _resultValue.set_value(); }

    void unhandled_exception() { _resultValue.set_exception(std::current_exception()); }

    void get_result() { return _resultValue.get(); }

    bool has_result() const { return _resultValue.has_value_or_exception(); }

    void* operator new(std::size_t size)
    {
        return CurrentAllocator::Allocate(size);
    }

    void operator delete(void* ptr, std::size_t size) noexcept
    {
        CurrentAllocator::Free(ptr, size);
    }

private:
    ResultValue<void> _resultValue;
};

template <std::derived_from<PromiseBase> Promise>
class AwaiterBase
{
public:
    explicit AwaiterBase(std::coroutine_handle<Promise> coroutine) noexcept : _coroutine(coroutine) { }

    bool await_ready() const noexcept { return !_coroutine || _coroutine.done(); }

    template <std::derived_from<CoroutineExecutionContext> promise_type>
    std::coroutine_handle<> await_suspend(std::coroutine_handle<promise_type> next) noexcept
    {
        Promise& promise = _coroutine.promise();
        promise.set_next(next);
        return _coroutine;
    }

protected:
    std::coroutine_handle<Promise> _coroutine;
};

template <std::derived_from<PromiseBase> Promise, bool RValue>
class Awaiter : public AwaiterBase<Promise>
{
public:
    using AwaiterBase<Promise>::AwaiterBase;

    decltype(auto) await_resume()
    {
        if constexpr (RValue)
            return std::move(this->_coroutine.promise()).get_result();
        else
            return this->_coroutine.promise().get_result();
    }
};
}

template <typename T>
class Awaitable
{
public:
    using promise_type = Impl::Promise<T>;
    using return_type = T;

    Awaitable() noexcept = default;

    explicit Awaitable(std::coroutine_handle<promise_type> coroutine) : _coroutine(coroutine) { }

    Awaitable(Awaitable const&) = delete;
    Awaitable(Awaitable&& other) noexcept : _coroutine(std::exchange(other._coroutine, nullptr)) { }

    Awaitable& operator=(Awaitable const&) = delete;
    Awaitable& operator=(Awaitable&& right) noexcept
    {
        if (this != &right)
        {
            if (_coroutine)
                _coroutine.destroy();

            _coroutine = std::exchange(right._coroutine, nullptr);
        }

        return *this;
    }

    ~Awaitable()
    {
        if (_coroutine)
            _coroutine.destroy();
    }

    Impl::Awaiter<promise_type, false> operator co_await() const & noexcept { return Impl::Awaiter<promise_type, false>(_coroutine); }
    Impl::Awaiter<promise_type, true> operator co_await() const && noexcept { return Impl::Awaiter<promise_type, true>(_coroutine); }

    promise_type& promise() const { return _coroutine.promise(); }

private:
    std::coroutine_handle<promise_type> _coroutine;
};

namespace Impl
{
template <typename T>
inline Awaitable<T> Promise<T>::get_return_object() noexcept { return Awaitable<T>(std::coroutine_handle<Promise>::from_promise(*this)); }

inline Awaitable<void> Promise<void>::get_return_object() noexcept { return Awaitable<void>(std::coroutine_handle<Promise>::from_promise(*this)); }
}
}

#endif // TRINITYCORE_CORO_AWAITABLE_H
