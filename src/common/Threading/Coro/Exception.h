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

#ifndef TRINITYCORE_CORO_EXCEPTION_H
#define TRINITYCORE_CORO_EXCEPTION_H

#include "Define.h"
#include <exception>

namespace Trinity::Coro
{
class CancelledException : public std::exception
{
public:
    char const* what() const noexcept override { return "Coroutine cancellation requested"; }
};

namespace Impl
{
[[noreturn]] TC_COMMON_API void throw_no_value_exception(std::exception_ptr const& exception);
[[noreturn]] TC_COMMON_API void throw_cancelled_exception();
}
}

#endif // TRINITYCORE_CORO_EXCEPTION_H
