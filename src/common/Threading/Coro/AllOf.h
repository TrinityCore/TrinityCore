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

#ifndef TRINITYCORE_CORO_ALL_OF_H
#define TRINITYCORE_CORO_ALL_OF_H

#include "./Awaitable.h"
#include "./CoroutineExecutionContext.h"
#include "./CoroutineFwd.h"
#include "Memory.h"
#include "Types.h"
#include "advstd.h"
#include <tuple>

namespace Trinity::Coro
{
namespace Impl
{
template <typename... Awaitables>
class AllOfAwaitable
{
public:
    template <typename Awaitable>
    using return_type_element = std::conditional_t<std::is_lvalue_reference_v<Awaitable>,
        std::add_lvalue_reference_t<typename std::remove_reference_t<Awaitable>::return_type>,
        std::remove_reference_t<typename std::remove_reference_t<Awaitable>::return_type>>;

    explicit AllOfAwaitable(Awaitables&&... awaitables)
        : _awaitables(AllOfAwaitable::AwaitableWrapper<Awaitables>(this, std::forward<Awaitables>(awaitables))...) { }

    bool await_ready() const noexcept { return _context && !_context->Handle.done(); }

    template <std::derived_from<CoroutineExecutionContext> promise_type>
    void await_suspend(std::coroutine_handle<promise_type> coroutine) noexcept
    {
        _context = &coroutine.promise();
        auto startCoro = [](CoroutineExecutionContext* context, auto&& awaitable)
        {
            auto& promise = awaitable.promise();
            promise.CurrentExecutor = context->CurrentExecutor;
            promise.CancelToken = context->CancelToken;
            promise.QueueCompletion();
        };
        std::apply([&](auto&&... awaitables) { (startCoro(_context, awaitables), ...); }, _awaitables);
    }

    auto await_resume()
    {
        using InputTuple = std::tuple<Awaitables...>;

        // call .get_result() on void returning awaitables to rethrow their exceptions
        auto voidsSequence = Trinity::filter_index_sequence(std::index_sequence_for<Awaitables...>{},
            []<std::size_t I>(std::index_sequence<I>) constexpr { return std::is_void_v<return_type_element<std::tuple_element_t<I, InputTuple>>>; });
        [&]<std::size_t... I>(std::index_sequence<I...>)
        {
            (std::get<I>(_awaitables).promise().get_result(), ...);
        }(voidsSequence);

        auto valuesSequence = Trinity::filter_index_sequence(std::index_sequence_for<Awaitables...>{},
            []<std::size_t I>(std::index_sequence<I>) constexpr { return !std::is_void_v<return_type_element<std::tuple_element_t<I, InputTuple>>>; });

        // return values from all awaitables
        // tuple element types are transformed like this
        // * if input awaitable was lvalue ref then tuple element is also lvalue ref
        // * if input awaitable was a rvalue ref or a value then tuple element is a value
        // * awaitables returning void are skipped in result tuple
        return [&]<std::size_t... I>(std::index_sequence<I...>)
        {
            return std::tuple<return_type_element<std::tuple_element_t<I, InputTuple>>...>(
                advstd::forward_like<return_type_element<std::tuple_element_t<I, InputTuple>>>(std::get<I>(_awaitables).promise()).get_result()...
            );
        }(valuesSequence);
    }

private:
    // this class takes ownership of rvalue awaitables by passing them by value to wrapper coroutine
    template <typename WrappedAwaitable>
    static Awaitable<return_type_element<WrappedAwaitable>> AwaitableWrapper(AllOfAwaitable* allOf,
        std::conditional_t<std::is_lvalue_reference_v<WrappedAwaitable>, WrappedAwaitable, std::remove_reference_t<WrappedAwaitable>> awaitable)
    {
        auto completionGuard = Trinity::make_unique_ptr_with_deleter<&AllOfAwaitable::OnChildComplete>(allOf);
        co_return co_await awaitable;
    }

    void OnChildComplete()
    {
        if (_pending.fetch_sub(1, std::memory_order::acq_rel) == 1)
            _context->QueueCompletion();
    }

    std::tuple<Awaitable<return_type_element<Awaitables>>...> _awaitables;
    std::atomic<std::size_t> _pending = sizeof...(Awaitables);
    CoroutineExecutionContext* _context = nullptr;
};
}

template <typename... Awaitables>
inline auto AllOf(Awaitables&&... awaitables) -> Impl::AllOfAwaitable<decltype(awaitables)...>
{
    return Impl::AllOfAwaitable<decltype(awaitables)...>(std::forward<Awaitables>(awaitables)...);
}
}

#endif // TRINITYCORE_CORO_ALL_OF_H
