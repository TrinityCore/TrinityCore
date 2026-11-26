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

#include "./SwitchExecutor.h"
#include "./CoroutineExecutionContext.h"
#include "./Executor.h"
#include <stdexcept>

namespace Trinity::Coro
{
namespace Impl
{
void SwitchToExecutorAwaiter::handle_suspend(CoroutineExecutionContext* coroutine)
{
    CancellableAwaiter::handle_suspend(coroutine);

    OldExecutor = coroutine->CurrentExecutor;
    NewExecutor.QueueCompletion(coroutine);
}
}

Executor& SwitchToExecutor::resolve_executor(unique_weak_ptr<Executor> const& executorRef)
{
    if (unique_strong_ref_ptr<unique_weak_ptr<Executor>::element_type> executor = executorRef.lock())
        return *executor;

    throw std::invalid_argument("Expired executor");
}
}
