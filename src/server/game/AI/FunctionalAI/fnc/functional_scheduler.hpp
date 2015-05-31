
/*
 *  Functional Composites/Collectors/Chrono Scheduling <https://github.com/Naios/FnC-Cpp>
 *
 *  Copyright (C) 2015 Naios <naios-dev@live.de>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _FUNCTIONAL_SCHEDULER_HPP_
#define _FUNCTIONAL_SCHEDULER_HPP_

#include <set>
#include <vector>
#include <queue>
#include <algorithm>

#include "functional_scheduler_detail.hpp"

namespace fnc
{
    class FunctionScheduler
    {
        friend class TaskContextInstance;

        /// Contains a self reference to track if this object was deleted or not.
        std::shared_ptr<FunctionScheduler> self_reference;

        /// The current time point (now)
        /// The time point is not the real time since we move it
        /// relatively forward and backward to reschedule all tasks.
        detail::timepoint_t _now;

        /// The Task Queue which contains all task objects.
        detail::TaskQueue _task_holder;
        
        typedef std::queue<std::function<void()>> AsyncHolder;

        /// Contains all asynchrone tasks which will be invoked at
        /// the next update tick.
        AsyncHolder _asyncHolder;

    public:
        typedef detail::clock_t clock;

        FunctionScheduler() : self_reference(this, [](FunctionScheduler const*) { }),
            _now(detail::clock_t::now()) { }

        FunctionScheduler(FunctionScheduler const&) = delete;
        FunctionScheduler(FunctionScheduler&&) = delete;
        FunctionScheduler& operator= (FunctionScheduler const&) = delete;
        FunctionScheduler& operator= (FunctionScheduler&&) = delete;

        /// Update the scheduler to the current time.
        FunctionScheduler& Update();

        /// Update the scheduler with a difftime in ms.
        FunctionScheduler& Update(size_t const milliseconds);

        /// Update the scheduler with a difftime.
        template<class _Rep, class _Period>
        FunctionScheduler& Update(std::chrono::duration<_Rep, _Period> const& difftime)
        {
            _now += difftime;
            Dispatch();
            return *this;
        }

        /// Schedule an callable function that is executed at the next update tick.
        /// Its safe to modify the FunctionScheduler from within the callable.
        FunctionScheduler& Async(std::function<void()> const& callable);

        /// Schedule an event with a fixed rate.
        /// Never call this from within a task context! Use TaskContext::schedule instead!
        template<class _Rep, class _Period>
        FunctionScheduler& Schedule(std::chrono::duration<_Rep, _Period> const& time,
            task_handler_t const& task)
        {
            return ScheduleAt(_now, time, task);
        }

        /// Schedule an event with a fixed rate.
        /// Never call this from within a task context! Use TaskContext::schedule instead!
        template<class _Rep, class _Period>
        FunctionScheduler& Schedule(std::chrono::duration<_Rep, _Period> const& time,
            detail::Task::group_t const group, task_handler_t const& task)
        {
            return ScheduleAt(_now, time, group, task);
        }

        /// Schedule an event with a randomized rate between min and max rate.
        /// Never call this from within a task context! Use TaskContext::schedule instead!
        template<class _RepLeft, class _PeriodLeft, class _RepRight, class _PeriodRight>
        FunctionScheduler& Schedule(std::chrono::duration<_RepLeft, _PeriodLeft> const& min,
            std::chrono::duration<_RepRight, _PeriodRight> const& max, task_handler_t const& task)
        {
            return Schedule(detail::RandomDurationBetween(min, max), task);
        }

        /// Schedule an event with a fixed rate.
        /// Never call this from within a task context! Use TaskContext::schedule instead!
        template<class _RepLeft, class _PeriodLeft, class _RepRight, class _PeriodRight>
        FunctionScheduler& Schedule(std::chrono::duration<_RepLeft, _PeriodLeft> const& min,
            std::chrono::duration<_RepRight, _PeriodRight> const& max, detail::Task::group_t const group,
            task_handler_t const& task)
        {
            return Schedule(detail::RandomDurationBetween(min, max), group, task);
        }

        /// Cancels all tasks.
        /// Never call this from within a task context! Use TaskContext::cancelAll instead!
        FunctionScheduler& CancelAll();

        /// Cancel all tasks of a single group.
        /// Never call this from within a task context! Use TaskContext::cancelGroup instead!
        FunctionScheduler& CancelGroup(detail::Task::group_t const group);

        /// Cancels all groups in the given std::vector.
        FunctionScheduler& CancelGroupsOf(std::vector<detail::Task::group_t> const& groups);

        /// Delays all tasks with the given duration.
        template<class _Rep, class _Period>
        FunctionScheduler& DelayAll(std::chrono::duration<_Rep, _Period> const& duration)
        {
            // Its enough to reduce the current time point.
            _now -= duration;
            return *this;
        }

        /// Delays all tasks with a random duration between min and max.
        template<class _RepLeft, class _PeriodLeft, class _RepRight, class _PeriodRight>
        FunctionScheduler& DelayAll(std::chrono::duration<_RepLeft, _PeriodLeft> const& min,
            std::chrono::duration<_RepRight, _PeriodRight> const& max)
        {
            return DelayAll(detail::RandomDurationBetween(min, max));
        }

        /// Delays all tasks of a group with the given duration.
        template<class _Rep, class _Period>
        FunctionScheduler& DelayGroup(detail::Task::group_t const group, std::chrono::duration<_Rep, _Period> const& duration)
        {
            _task_holder.ModifyIf([&duration, group](TaskContainer const& task) -> bool
            {
                if (task->IsInGroup(group))
                {
                    task->_end += duration;
                    return true;
                }
                else
                    return false;
            });
            return *this;
        }

        /// Delays all tasks of a group with a random duration between min and max.
        template<class _RepLeft, class _PeriodLeft, class _RepRight, class _PeriodRight>
        FunctionScheduler& DelayGroup(detail::Task::group_t const group,
            std::chrono::duration<_RepLeft, _PeriodLeft> const& min,
            std::chrono::duration<_RepRight, _PeriodRight> const& max)
        {
            return DelayGroup(group, detail::RandomDurationBetween(min, max));
        }

        /// Reschedule all tasks with a given duration.
        template<class _Rep, class _Period>
        FunctionScheduler& RescheduleAll(std::chrono::duration<_Rep, _Period> const& duration)
        {
            auto const end = _now + duration;
            _task_holder.ModifyIf([end](TaskContainer const& task) -> bool
            {
                task->_end = end;
                return true;
            });
            return *this;
        }

        /// Reschedule all tasks with a random duration between min and max.
        template<class _RepLeft, class _PeriodLeft, class _RepRight, class _PeriodRight>
        FunctionScheduler& RescheduleAll(std::chrono::duration<_RepLeft, _PeriodLeft> const& min,
            std::chrono::duration<_RepRight, _PeriodRight> const& max)
        {
            return RescheduleAll(detail::RandomDurationBetween(min, max));
        }

        /// Reschedule all tasks of a group with a given duration.
        template<class _Rep, class _Period>
        FunctionScheduler& RescheduleGroup(detail::Task::group_t const group, std::chrono::duration<_Rep, _Period> const& duration)
        {
            auto const end = _now + duration;
           _task_holder.ModifyIf([end, group](TaskContainer const& task) -> bool
            {
                if (task->IsInGroup(group))
                {
                    task->_end = end;
                    return true;
                }
                else
                    return false;
            });
            return *this;
        }

        /// Reschedule all tasks of a group with a random duration between min and max.
        template<class _RepLeft, class _PeriodLeft, class _RepRight, class _PeriodRight>
        FunctionScheduler& RescheduleGroup(detail::Task::group_t const group,
            std::chrono::duration<_RepLeft, _PeriodLeft> const& min,
            std::chrono::duration<_RepRight, _PeriodRight> const& max)
        {
            return RescheduleGroup(group, detail::RandomDurationBetween(min, max));
        }

    private:
        /// Insert a new task to the enqueued tasks.
        FunctionScheduler& InsertTask(TaskContainer task);

        template<class _Rep, class _Period>
        FunctionScheduler& ScheduleAt(detail::timepoint_t const& end,
            std::chrono::duration<_Rep, _Period> const& time, task_handler_t const& task)
        {
            return InsertTask(TaskContainer(new detail::Task(end + time, time, task)));
        }

        /// Schedule an event with a fixed rate.
        /// Never call this from within a task context! Use TaskContext::schedule instead!
        template<class _Rep, class _Period>
        FunctionScheduler& ScheduleAt(detail::timepoint_t const& end,
            std::chrono::duration<_Rep, _Period> const& time,
            detail::Task::group_t const group, task_handler_t const& task)
        {
            static detail::Task::repeated_t const DEFAULT_REPEATED = 0;
            return InsertTask(TaskContainer(new detail::Task(end + time, time, group, DEFAULT_REPEATED, task)));
        }

        /// Dispatch remaining tasks
        void Dispatch();
    };
}

#include "functional_task_context.hpp"

#endif /// _FUNCTIONAL_SCHEDULER_HPP_
