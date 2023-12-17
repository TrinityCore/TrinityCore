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

#ifndef TRINITYCORE_CONCEPTS_H
#define TRINITYCORE_CONCEPTS_H

#include <concepts>
#include <functional> // std::invoke

namespace Trinity
{
template <typename Callable, typename R, typename... Args>
concept invocable_r = requires(Callable && callable, Args&&... args)
{
    { std::invoke(static_cast<Callable&&>(callable), static_cast<Args&&>(args)...) } -> std::convertible_to<R>;
};
}

#endif // TRINITYCORE_CONCEPTS_H
