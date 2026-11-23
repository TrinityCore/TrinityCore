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

#ifndef TRINITYCORE_CORO_EXECUTOR_H
#define TRINITYCORE_CORO_EXECUTOR_H

#include "./CoroutineFwd.h"
#include "Define.h"
#include "UniqueTrackablePtr.h"

namespace Trinity::Coro
{
class TC_COMMON_API Executor : public enable_unique_weak_from_this<Executor>
{
public:
    Executor() = default;
    Executor(Executor const& other) = delete;
    Executor(Executor&& other) noexcept = delete;
    Executor& operator=(Executor const& other) = delete;
    Executor& operator=(Executor&& other) noexcept = delete;
    virtual ~Executor() = default;

    virtual void QueueCompletion(CoroutineExecutionContext* context) = 0;
};
}

#endif // TRINITYCORE_CORO_EXECUTOR_H
