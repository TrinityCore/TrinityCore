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

#ifndef TRINITYCORE_CANCELLABLE_AWAITER_H
#define TRINITYCORE_CANCELLABLE_AWAITER_H

#include "./CoroutineExecutionContext.h"
#include "./CoroutineFwd.h"
#include "./Exception.h"

namespace Trinity::Coro::Impl
{
// Base class for awaiters to handle cancellation
struct CancellableAwaiter
{
    void handle_suspend(CoroutineExecutionContext* context) noexcept
    {
        SuspendedContext = context;
    }

    void handle_resume() const
    {
        if (SuspendedContext->CancelToken.stop_requested())
            throw_cancelled_exception();
    }

protected:
    CoroutineExecutionContext* SuspendedContext = nullptr;
};
}

#endif // TRINITYCORE_CANCELLABLE_AWAITER_H
