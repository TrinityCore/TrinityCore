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

#include "./Exception.h"
#include <stdexcept>

namespace Trinity::Coro::Impl
{
void throw_no_value_exception(std::exception_ptr const& exception)
{
    if (exception)
        std::rethrow_exception(exception);
    else
        throw std::logic_error("No value or exception result for coroutine");
}

void throw_cancelled_exception()
{
    throw CancelledException();
}
}
