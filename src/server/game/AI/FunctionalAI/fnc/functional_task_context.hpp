
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

#ifndef _FUNCTIONAL_TASK_CONTEXT_HPP_
#define _FUNCTIONAL_TASK_CONTEXT_HPP_

#include "functional_scheduler.hpp"

namespace fnc
{
    class TaskContextInstance
        : public std::enable_shared_from_this<TaskContextInstance>
    {
        friend class FunctionScheduler;

        /// Owner
        std::weak_ptr<FunctionScheduler> const _owner;

        /// Associated task
        TaskContainer _task;

        /// Dispatches an action safe on the FunctionScheduler
        TaskContextInstance& Dispatch(std::function<FunctionScheduler&(FunctionScheduler&)> const& apply);

    public:
        explicit TaskContextInstance(TaskContainer task, std::weak_ptr<FunctionScheduler>&& owner)
            : _task(task), _owner(owner) { }

        /// Returns true if the event is in the given group
        bool IsInGroup(detail::Task::group_t const group) const;

        /// Sets the event in a given group
        TaskContextInstance& SetGroup(detail::Task::group_t const group);

        /// Removes the group from the event
        TaskContextInstance& ClearGroup();

        /// Returns the repeat counter which increses every time the task is repeated.
        detail::Task::repeated_t GetRepeatCounter() const;

        /// Repeats the event and set a new duration.
        /// std::chrono::seconds(5) for example.
        /// This will consume the task context, its not possible to repeat the task again.
        template<class _Rep, class _Period>
        TaskContextInstance& Repeat(std::chrono::duration<_Rep, _Period> const& duration)
        {
            // Set new duration, in-context timing and increment repeat counter
            _task->_duration = duration;
            _task->_end += duration;
            _task->_repeated += 1;
            return Dispatch(std::bind(&FunctionScheduler::InsertTask, std::placeholders::_1, _task));
        }

        /// Repeats the event with the same duration.
        /// This will consume the task context, its not possible to repeat the task again.
        TaskContextInstance& Repeat()
        {
            return Repeat(_task->_duration);
        }

        /// Repeats the event and set a new duration that is randomized between min and max.
        /// std::chrono::seconds(5) for example.
        /// This will consume the task context, its not possible to repeat the task again.
        template<class _RepLeft, class _PeriodLeft, class _RepRight, class _PeriodRight>
        TaskContextInstance& Repeat(std::chrono::duration<_RepLeft, _PeriodLeft> const& min,
            std::chrono::duration<_RepRight, _PeriodRight> const& max)
        {
            return Repeat(detail::RandomDurationBetween(min, max));
        }

        /// Schedule an callable function that is executed at the next update tick from within the context.
        /// Its safe to modify the FunctionScheduler from within the callable.
        TaskContextInstance& Async(std::function<void()> const& callable);

        /// Schedule an event with a fixed rate from within the context.
        /// Its possible that the new event is executed immediately!
        /// Use FunctionScheduler::Async to create a task
        /// which will be called at the next update tick.
        template<class _Rep, class _Period>
        TaskContextInstance& Schedule(std::chrono::duration<_Rep, _Period> const& time,
            task_handler_t const& task)
        {
            auto const end = _task->_end;
            return Dispatch([end, time, task](FunctionScheduler& scheduler) -> FunctionScheduler&
            {
                return scheduler.ScheduleAt<_Rep, _Period>(end, time, task);
            });
        }

        /// Schedule an event with a fixed rate from within the context.
        /// Its possible that the new event is executed immediately!
        /// Use FunctionScheduler::Async to create a task
        /// which will be called at the next update tick.
        template<class _Rep, class _Period>
        TaskContextInstance& Schedule(std::chrono::duration<_Rep, _Period> const& time,
            detail::Task::group_t const group, task_handler_t const& task)
        {
            auto const end = _task->_end;
            return Dispatch([end, time, group, task](FunctionScheduler& scheduler) -> FunctionScheduler&
            {
                return scheduler.ScheduleAt<_Rep, _Period>(end, time, group, task);
            });
        }

        /// Schedule an event with a randomized rate between min and max rate from within the context.
        /// Its possible that the new event is executed immediately!
        /// Use FunctionScheduler::Async to create a task
        /// which will be called at the next update tick.
        template<class _RepLeft, class _PeriodLeft, class _RepRight, class _PeriodRight>
        TaskContextInstance& Schedule(std::chrono::duration<_RepLeft, _PeriodLeft> const& min,
            std::chrono::duration<_RepRight, _PeriodRight> const& max, task_handler_t const& task)
        {
            return Schedule(detail::RandomDurationBetween(min, max), task);
        }

        /// Schedule an event with a randomized rate between min and max rate from within the context.
        /// Its possible that the new event is executed immediately!
        /// Use FunctionScheduler::Async to create a task
        /// which will be called at the next update tick.
        template<class _RepLeft, class _PeriodLeft, class _RepRight, class _PeriodRight>
        TaskContextInstance& Schedule(std::chrono::duration<_RepLeft, _PeriodLeft> const& min,
            std::chrono::duration<_RepRight, _PeriodRight> const& max, detail::Task::group_t const group,
            task_handler_t const& task)
        {
            return Schedule(detail::RandomDurationBetween(min, max), group, task);
        }

        /// Cancels all tasks from within the context.
        TaskContextInstance& CancelAll();

        /// Cancel all tasks of a single group from within the context.
        TaskContextInstance& CancelGroup(detail::Task::group_t const group);

        /// Cancels all groups in the given std::vector from within the context.
        TaskContextInstance& CancelGroupsOf(std::vector<detail::Task::group_t> const& groups);

        /// Delays all tasks with the given duration from within the context.
        template<class _Rep, class _Period>
        TaskContextInstance& DelayAll(std::chrono::duration<_Rep, _Period> const& duration)
        {
            return Dispatch(std::bind(&FunctionScheduler::DelayAll<_Rep, _Period>, std::placeholders::_1, duration));
        }

        /// Delays all tasks with a random duration between min and max from within the context.
        template<class _RepLeft, class _PeriodLeft, class _RepRight, class _PeriodRight>
        TaskContextInstance& DelayAll(std::chrono::duration<_RepLeft, _PeriodLeft> const& min,
            std::chrono::duration<_RepRight, _PeriodRight> const& max)
        {
            return DelayAll(detail::RandomDurationBetween(min, max));
        }

        /// Delays all tasks of a group with the given duration from within the context.
        template<class _Rep, class _Period>
        TaskContextInstance& DelayGroup(detail::Task::group_t const group, std::chrono::duration<_Rep, _Period> const& duration)
        {
            return Dispatch(std::bind(&FunctionScheduler::DelayGroup<_Rep, _Period>, std::placeholders::_1, group, duration));
        }

        /// Delays all tasks of a group with a random duration between min and max from within the context.
        template<class _RepLeft, class _PeriodLeft, class _RepRight, class _PeriodRight>
        TaskContextInstance& DelayGroup(detail::Task::group_t const group,
            std::chrono::duration<_RepLeft, _PeriodLeft> const& min,
            std::chrono::duration<_RepRight, _PeriodRight> const& max)
        {
            return DelayGroup(group, detail::RandomDurationBetween(min, max));
        }

        /// Reschedule all tasks with a given duration.
        template<class _Rep, class _Period>
        TaskContextInstance& RescheduleAll(std::chrono::duration<_Rep, _Period> const& duration)
        {
            return Dispatch(std::bind(&FunctionScheduler::RescheduleAll, std::placeholders::_1, duration));
        }

        /// Reschedule all tasks with a random duration between min and max.
        template<class _RepLeft, class _PeriodLeft, class _RepRight, class _PeriodRight>
        TaskContextInstance& RescheduleAll(std::chrono::duration<_RepLeft, _PeriodLeft> const& min,
            std::chrono::duration<_RepRight, _PeriodRight> const& max)
        {
            return RescheduleAll(detail::RandomDurationBetween(min, max));
        }

        /// Reschedule all tasks of a group with a given duration.
        template<class _Rep, class _Period>
        TaskContextInstance& RescheduleGroup(detail::Task::group_t const group, std::chrono::duration<_Rep, _Period> const& duration)
        {
            return Dispatch(std::bind(&FunctionScheduler::RescheduleGroup<_Rep, _Period>, std::placeholders::_1, group, duration));
        }

        /// Reschedule all tasks of a group with a random duration between min and max.
        template<class _RepLeft, class _PeriodLeft, class _RepRight, class _PeriodRight>
        TaskContextInstance& RescheduleGroup(detail::Task::group_t const group,
            std::chrono::duration<_RepLeft, _PeriodLeft> const& min,
            std::chrono::duration<_RepRight, _PeriodRight> const& max)
        {
            return RescheduleGroup(group, detail::RandomDurationBetween(min, max));
        }

    private:
        void Invoke();
    };
}

#endif /// _FUNCTIONAL_TASK_CONTEXT_HPP_
