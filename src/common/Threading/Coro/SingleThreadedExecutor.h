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

#ifndef TRINITYCORE_CORO_SINGLE_THREADED_EXECUTOR_H
#define TRINITYCORE_CORO_SINGLE_THREADED_EXECUTOR_H

#include "./CoroutineExecutionContext.h"
#include "./CoroutineFwd.h"
#include "./Executor.h"
#include "MPSCQueue.h"

namespace Trinity::Coro
{
class TC_COMMON_API SingleThreadedExecutor final : public Executor
{
public:
    void QueueCompletion(CoroutineExecutionContext* context) override;

    void ResumeReadyCoroutines();

private:
    MPSCQueue<CoroutineExecutionContext, &CoroutineExecutionContext::QueueLink> _resumeQueue;
};
}

#endif // TRINITYCORE_CORO_SINGLE_THREADED_EXECUTOR_H
