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

#ifndef TRINITYCORE_CORO_RESULT_VALUE_H
#define TRINITYCORE_CORO_RESULT_VALUE_H

#include "./CoroutineFwd.h"
#include "Define.h"
#include <exception>
#include <type_traits>
#include <variant>

namespace Trinity::Coro
{
namespace Impl
{
[[noreturn]] TC_COMMON_API void ThrowNoValueException(std::exception_ptr exception);
}

template <typename T>
class ResultValue
{
public:
    using value_holder = std::conditional_t<std::is_reference_v<T>, std::reference_wrapper<std::remove_reference_t<T>>, std::remove_const_t<T>>;

    bool has_value_or_exception() const { return !std::holds_alternative<std::monostate>(_result); }

    template <std::convertible_to<value_holder> V>
    void set_value(V&& value) { _result.template emplace<value_holder>(std::forward<V>(value)); }

    void set_exception(std::exception_ptr exception) { _result.template emplace<std::exception_ptr>(std::move(exception)); }

    T& get() &
    {
        if (std::holds_alternative<value_holder>(_result))
            return std::get<value_holder>(_result);

        Impl::ThrowNoValueException(std::holds_alternative<std::exception_ptr>(_result)
            ? std::get<std::exception_ptr>(std::move(_result)) : nullptr);
    }

    T&& get() &&
    {
        if (std::holds_alternative<value_holder>(_result))
            return std::get<value_holder>(std::move(_result));

        Impl::ThrowNoValueException(std::holds_alternative<std::exception_ptr>(_result)
            ? std::get<std::exception_ptr>(std::move(_result)) : nullptr);
    }

    void reset() { _result.template emplace<std::monostate>(); }

private:
    std::variant<std::monostate, value_holder, std::exception_ptr> _result;
};

template <>
class ResultValue<void>
{
public:
    bool has_value_or_exception() const { return !std::holds_alternative<std::monostate>(_result); }

    void set_value() { _result.emplace<bool>(true); }

    void set_exception(std::exception_ptr exception) { _result.emplace<std::exception_ptr>(std::move(exception)); }

    void get()
    {
        if (std::holds_alternative<bool>(_result))
            return;

        Impl::ThrowNoValueException(std::holds_alternative<std::exception_ptr>(_result)
            ? std::get<std::exception_ptr>(std::move(_result)) : nullptr);
    }

    void reset() { _result.emplace<std::monostate>(); }

private:
    std::variant<std::monostate /*incomplete*/, bool /*successful completion*/, std::exception_ptr> _result;
};
}

#endif // TRINITYCORE_CORO_RESULT_VALUE_H
