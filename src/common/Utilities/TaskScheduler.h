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

#ifndef TRINITYCORE_TASK_SCHEDULER_H
#define TRINITYCORE_TASK_SCHEDULER_H

#include "Duration.h"
#include "Optional.h"
#include "Random.h"
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <memory>
#include <utility>
#include <set>

class TaskContext;

/// The TaskScheduler class provides the ability to schedule std::function's in the near future.
/// Use TaskScheduler::Update to update the scheduler.
/// Popular methods are:
/// * Schedule (Schedules a std::function which will be executed in the near future).
/// * Schedules an asynchronous function which will be executed at the next update tick.
/// * Cancel, Delay & Reschedule (Methods to manipulate already scheduled tasks).
/// Tasks are organized in groups (uint), multiple tasks can have the same group id,
/// you can provide a group or not, but keep in mind that you can only manipulate specific tasks through its group id!
/// Tasks callbacks use the function signature void(TaskContext) where TaskContext provides
/// access to the function schedule plan which makes it possible to repeat the task
/// with the same duration or a new one.
/// It also provides access to the repeat counter which is useful for task that repeat itself often
/// but behave different every time (spoken event dialogs for example).
class TC_COMMON_API TaskScheduler
{
    friend class TaskContext;

    // Time definitions (use steady clock)
    typedef std::chrono::steady_clock clock_t;
    typedef clock_t::time_point timepoint_t;
    typedef clock_t::duration duration_t;

    // Task group type
    typedef uint32 group_t;
    // Task repeated type
    typedef uint32 repeated_t;
    // Task handle type
    typedef std::function<void(TaskContext)> task_handler_t;
    // Predicate type
    typedef std::function<bool()> predicate_t;
    // Success handle type
    typedef std::function<void()> success_t;

    class Task
    {
        friend class TaskContext;
        friend class TaskScheduler;

        timepoint_t _end;
        duration_t _duration;
        Optional<group_t> _group;
        repeated_t _repeated;
        task_handler_t _task;

    public:
        // All Argument construct
        Task(timepoint_t end, duration_t duration, Optional<group_t> group,
            repeated_t const repeated, task_handler_t task)
                : _end(end), _duration(duration), _group(group), _repeated(repeated), _task(std::move(task)) { }

        // Minimal Argument construct
        Task(timepoint_t end, duration_t duration, task_handler_t task)
            : _end(end), _duration(duration), _group(std::nullopt), _repeated(0), _task(std::move(task)) { }

        // Copy construct
        Task(Task const&) = delete;
        // Move construct
        Task(Task&&) = delete;
        // Copy Assign
        Task& operator= (Task const&) = default;
        // Move Assign
        Task& operator= (Task&& right) = delete;

        ~Task() = default;

        // Order tasks by its end
        std::weak_ordering operator<=> (Task const& other) const
        {
            return std::compare_weak_order_fallback(_end, other._end);
        }

        // Compare tasks with its end
        bool operator== (Task const& other) const
        {
            return _end == other._end;
        }

        // Returns true if the task is in the given group
        inline bool IsInGroup(group_t const group) const
        {
            return _group == group;
        }
    };

    typedef std::shared_ptr<Task> TaskContainer;

    /// Container which provides Task order, insert and reschedule operations.
    struct Compare
    {
        bool operator() (TaskContainer const& left, TaskContainer const& right) const
        {
            return (*left.get()) < (*right.get());
        }
    };

    class TC_COMMON_API TaskQueue
    {
        std::multiset<TaskContainer, Compare> container;

    public:
        // Pushes the task in the container
        void Push(TaskContainer&& task);

        /// Pops the task out of the container
        TaskContainer Pop();

        TaskContainer const& First() const;

        void Clear();

        void RemoveIf(std::function<bool(TaskContainer const&)> const& filter);

        void ModifyIf(std::function<bool(TaskContainer const&)> const& filter);

        bool IsEmpty() const;
    };

    /// Contains a self reference to track if this object was deleted or not.
    std::shared_ptr<TaskScheduler> self_reference;

    /// The current time point (now)
    timepoint_t _now;

    /// The Task Queue which contains all task objects.
    TaskQueue _task_holder;

    typedef std::queue<std::function<void()>> AsyncHolder;

    /// Contains all asynchronous tasks which will be invoked at
    /// the next update tick.
    AsyncHolder _asyncHolder;

    predicate_t _predicate;

    static bool EmptyValidator()
    {
        return true;
    }

public:
    TaskScheduler()
        : self_reference(this, [](TaskScheduler const*) { }), _now(clock_t::now()), _predicate(EmptyValidator) { }

    template<typename P>
    TaskScheduler(P&& predicate)
        : self_reference(this, [](TaskScheduler const*) { }), _now(clock_t::now()), _predicate(std::forward<P>(predicate)) { }

    TaskScheduler(TaskScheduler const&) = delete;
    TaskScheduler(TaskScheduler&&) = delete;
    TaskScheduler& operator= (TaskScheduler const&) = delete;
    TaskScheduler& operator= (TaskScheduler&&) = delete;

    ~TaskScheduler() = default;

    /// Sets a validator which is asked if tasks are allowed to be executed.
    template<typename P>
    TaskScheduler& SetValidator(P&& predicate)
    {
        _predicate = std::forward<P>(predicate);
        return *this;
    }

    /// Clears the validator which is asked if tasks are allowed to be executed.
    TaskScheduler& ClearValidator();

    /// Update the scheduler to the current time.
    /// Calls the optional callback on successfully finish.
    TaskScheduler& Update(success_t const& callback = nullptr);

    /// Update the scheduler with a difftime in ms.
    /// Calls the optional callback on successfully finish.
    TaskScheduler& Update(size_t milliseconds, success_t const& callback = nullptr);

    /// Update the scheduler with a difftime.
    /// Calls the optional callback on successfully finish.
    template<class Rep, class Period>
    TaskScheduler& Update(std::chrono::duration<Rep, Period> difftime,
        success_t const& callback = nullptr)
    {
        _now += difftime;
        Dispatch(callback);
        return *this;
    }

    /// Schedule an callable function that is executed at the next update tick.
    /// Its safe to modify the TaskScheduler from within the callable.
    TaskScheduler& Async(std::function<void()> callable);

    /// Schedule an event with a fixed rate.
    /// Never call this from within a task context! Use TaskContext::Schedule instead!
    template<class Rep, class Period>
    TaskScheduler& Schedule(std::chrono::duration<Rep, Period> time,
        task_handler_t task)
    {
        return this->ScheduleAt(_now, time, std::move(task));
    }

    /// Schedule an event with a fixed rate.
    /// Never call this from within a task context! Use TaskContext::Schedule instead!
    template<class Rep, class Period>
    TaskScheduler& Schedule(std::chrono::duration<Rep, Period> time,
        group_t const group, task_handler_t task)
    {
        return this->ScheduleAt(_now, time, group, std::move(task));
    }

    /// Schedule an event with a randomized rate between min and max rate.
    /// Never call this from within a task context! Use TaskContext::Schedule instead!
    template<class RepLeft, class PeriodLeft, class RepRight, class PeriodRight>
    TaskScheduler& Schedule(std::chrono::duration<RepLeft, PeriodLeft> min,
        std::chrono::duration<RepRight, PeriodRight> max, task_handler_t task)
    {
        return this->Schedule(::randtime(min, max), std::move(task));
    }

    /// Schedule an event with a fixed rate.
    /// Never call this from within a task context! Use TaskContext::Schedule instead!
    template<class RepLeft, class PeriodLeft, class RepRight, class PeriodRight>
    TaskScheduler& Schedule(std::chrono::duration<RepLeft, PeriodLeft> min,
        std::chrono::duration<RepRight, PeriodRight> max, group_t const group,
        task_handler_t task)
    {
        return this->Schedule(::randtime(min, max), group, std::move(task));
    }

    /// Cancels all tasks.
    /// Never call this from within a task context! Use TaskContext::CancelAll instead!
    TaskScheduler& CancelAll();

    /// Cancel all tasks of a single group.
    /// Never call this from within a task context! Use TaskContext::CancelGroup instead!
    TaskScheduler& CancelGroup(group_t group);

    /// Cancels all groups in the given std::vector.
    /// Hint: Use std::initializer_list for this: "{1, 2, 3, 4}"
    TaskScheduler& CancelGroupsOf(std::vector<group_t> const& groups);

    /// Delays all tasks with the given duration.
    template<class Rep, class Period>
    TaskScheduler& DelayAll(std::chrono::duration<Rep, Period> duration)
    {
        _task_holder.ModifyIf([&duration](TaskContainer const& task) -> bool
        {
            task->_end += duration;
            return true;
        });
        return *this;
    }

    /// Delays all tasks with a random duration between min and max.
    template<class RepLeft, class PeriodLeft, class RepRight, class PeriodRight>
    TaskScheduler& DelayAll(std::chrono::duration<RepLeft, PeriodLeft> min,
        std::chrono::duration<RepRight, PeriodRight> max)
    {
        return this->DelayAll(::randtime(min, max));
    }

    /// Delays all tasks of a group with the given duration.
    template<class Rep, class Period>
    TaskScheduler& DelayGroup(group_t const group, std::chrono::duration<Rep, Period> duration)
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
    template<class RepLeft, class PeriodLeft, class RepRight, class PeriodRight>
    TaskScheduler& DelayGroup(group_t const group,
        std::chrono::duration<RepLeft, PeriodLeft> min,
        std::chrono::duration<RepRight, PeriodRight> max)
    {
        return this->DelayGroup(group, ::randtime(min, max));
    }

    /// Reschedule all tasks with a given duration.
    template<class Rep, class Period>
    TaskScheduler& RescheduleAll(std::chrono::duration<Rep, Period> duration)
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
    template<class RepLeft, class PeriodLeft, class RepRight, class PeriodRight>
    TaskScheduler& RescheduleAll(std::chrono::duration<RepLeft, PeriodLeft> min,
        std::chrono::duration<RepRight, PeriodRight> max)
    {
        return this->RescheduleAll(::randtime(min, max));
    }

    /// Reschedule all tasks of a group with the given duration.
    template<class Rep, class Period>
    TaskScheduler& RescheduleGroup(group_t const group, std::chrono::duration<Rep, Period> duration)
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
    template<class RepLeft, class PeriodLeft, class RepRight, class PeriodRight>
    TaskScheduler& RescheduleGroup(group_t const group,
        std::chrono::duration<RepLeft, PeriodLeft> min,
        std::chrono::duration<RepRight, PeriodRight> max)
    {
        return this->RescheduleGroup(group, ::randtime(min, max));
    }

private:
    /// Insert a new task to the enqueued tasks.
    TaskScheduler& InsertTask(TaskContainer task);

    template<class Rep, class Period>
    TaskScheduler& ScheduleAt(timepoint_t end,
        std::chrono::duration<Rep, Period> time, task_handler_t task)
    {
        return InsertTask(TaskContainer(new Task(end + time, time, std::move(task))));
    }

    /// Schedule an event with a fixed rate.
    /// Never call this from within a task context! Use TaskContext::schedule instead!
    template<class Rep, class Period>
    TaskScheduler& ScheduleAt(timepoint_t end,
        std::chrono::duration<Rep, Period> time,
        group_t const group, task_handler_t task)
    {
        static constexpr repeated_t DEFAULT_REPEATED = 0;
        return InsertTask(TaskContainer(new Task(end + time, time, group, DEFAULT_REPEATED, std::move(task))));
    }

    /// Dispatch remaining tasks
    void Dispatch(success_t const& callback);
};

class TC_COMMON_API TaskContext
{
    friend class TaskScheduler;

    /// Associated task
    TaskScheduler::TaskContainer _task;

    /// Owner
    std::weak_ptr<TaskScheduler> _owner;

    /// Marks the task as consumed
    std::shared_ptr<bool> _consumed;

    /// Dispatches an action safe on the TaskScheduler
    TaskContext& Dispatch(std::function<TaskScheduler&(TaskScheduler&)> const& apply);

public:
    // Empty constructor
    TaskContext()
        : _task(), _owner(), _consumed(std::make_shared<bool>(true)) { }

    // Construct from task and owner
    explicit TaskContext(TaskScheduler::TaskContainer&& task, std::weak_ptr<TaskScheduler>&& owner)
        : _task(std::move(task)), _owner(std::move(owner)), _consumed(std::make_shared<bool>(false)) { }

    // Copy construct
    TaskContext(TaskContext const& right)
        : _task(right._task), _owner(right._owner), _consumed(right._consumed) { }

    // Move construct
    TaskContext(TaskContext&& right) noexcept
        : _task(std::move(right._task)), _owner(std::move(right._owner)), _consumed(std::move(right._consumed)) { }

    // Copy assign
    TaskContext& operator=(TaskContext const& right)
    {
        if (this != &right)
        {
            _task = right._task;
            _owner = right._owner;
            _consumed = right._consumed;
        }
        return *this;
    }

    // Move assign
    TaskContext& operator=(TaskContext&& right) noexcept
    {
        if (this != &right)
        {
            _task = std::move(right._task);
            _owner = std::move(right._owner);
            _consumed = std::move(right._consumed);
        }
        return *this;
    }

    ~TaskContext() = default;

    /// Returns true if the owner was deallocated and this context has expired.
    bool IsExpired() const;

    /// Returns true if the event is in the given group
    bool IsInGroup(TaskScheduler::group_t const group) const;

    /// Sets the event in the given group
    TaskContext& SetGroup(TaskScheduler::group_t const group);

    /// Removes the group from the event
    TaskContext& ClearGroup();

    /// Returns the repeat counter which increases every time the task is repeated.
    TaskScheduler::repeated_t GetRepeatCounter() const;

    /// Repeats the event and sets a new duration.
    /// std::chrono::seconds(5) for example.
    /// This will consume the task context, its not possible to repeat the task again
    /// from the same task context!
    template<class Rep, class Period>
    TaskContext& Repeat(std::chrono::duration<Rep, Period> duration)
    {
        AssertOnConsumed();

        // Set new duration, in-context timing and increment repeat counter
        _task->_duration = duration;
        _task->_end += duration;
        _task->_repeated += 1;
        (*_consumed) = true;
        return this->Dispatch([this](TaskScheduler& scheduler) -> TaskScheduler&
        {
            return scheduler.InsertTask(_task);
        });
    }

    /// Repeats the event with the same duration.
    /// This will consume the task context, its not possible to repeat the task again
    /// from the same task context!
    TaskContext& Repeat()
    {
        return Repeat(_task->_duration);
    }

    /// Repeats the event and set a new duration that is randomized between min and max.
    /// std::chrono::seconds(5) for example.
    /// This will consume the task context, its not possible to repeat the task again
    /// from the same task context!
    template<class RepLeft, class PeriodLeft, class RepRight, class PeriodRight>
    TaskContext& Repeat(std::chrono::duration<RepLeft, PeriodLeft> min,
        std::chrono::duration<RepRight, PeriodRight> max)
    {
        return this->Repeat(::randtime(min, max));
    }

    /// Schedule a callable function that is executed at the next update tick from within the context.
    /// Its safe to modify the TaskScheduler from within the callable.
    TaskContext& Async(std::function<void()> const& callable);

    /// Schedule an event with a fixed rate from within the context.
    /// Its possible that the new event is executed immediately!
    /// Use TaskScheduler::Async to create a task
    /// which will be called at the next update tick.
    template<class Rep, class Period>
    TaskContext& Schedule(std::chrono::duration<Rep, Period> time,
        TaskScheduler::task_handler_t task)
    {
        auto const end = _task->_end;
        return this->Dispatch([end, time, task = std::move(task)](TaskScheduler& scheduler) -> TaskScheduler&
        {
            return scheduler.ScheduleAt<Rep, Period>(end, time, std::move(task));
        });
    }

    /// Schedule an event with a fixed rate from within the context.
    /// Its possible that the new event is executed immediately!
    /// Use TaskScheduler::Async to create a task
    /// which will be called at the next update tick.
    template<class Rep, class Period>
    TaskContext& Schedule(std::chrono::duration<Rep, Period> time,
        TaskScheduler::group_t const group, TaskScheduler::task_handler_t task)
    {
        auto const end = _task->_end;
        return this->Dispatch([end, time, group, task = std::move(task)](TaskScheduler& scheduler) -> TaskScheduler&
        {
            return scheduler.ScheduleAt<Rep, Period>(end, time, group, std::move(task));
        });
    }

    /// Schedule an event with a randomized rate between min and max rate from within the context.
    /// Its possible that the new event is executed immediately!
    /// Use TaskScheduler::Async to create a task
    /// which will be called at the next update tick.
    template<class RepLeft, class PeriodLeft, class RepRight, class PeriodRight>
    TaskContext& Schedule(std::chrono::duration<RepLeft, PeriodLeft> min,
        std::chrono::duration<RepRight, PeriodRight> max, TaskScheduler::task_handler_t task)
    {
        return this->Schedule(::randtime(min, max), std::move(task));
    }

    /// Schedule an event with a randomized rate between min and max rate from within the context.
    /// Its possible that the new event is executed immediately!
    /// Use TaskScheduler::Async to create a task
    /// which will be called at the next update tick.
    template<class RepLeft, class PeriodLeft, class RepRight, class PeriodRight>
    TaskContext& Schedule(std::chrono::duration<RepLeft, PeriodLeft> min,
        std::chrono::duration<RepRight, PeriodRight> max, TaskScheduler::group_t const group,
        TaskScheduler::task_handler_t task)
    {
        return this->Schedule(::randtime(min, max), group, std::move(task));
    }

    /// Cancels all tasks from within the context.
    TaskContext& CancelAll();

    /// Cancel all tasks of a single group from within the context.
    TaskContext& CancelGroup(TaskScheduler::group_t const group);

    /// Cancels all groups in the given std::vector from within the context.
    /// Hint: Use std::initializer_list for this: "{1, 2, 3, 4}"
    TaskContext& CancelGroupsOf(std::vector<TaskScheduler::group_t> const& groups);

    /// Delays all tasks with the given duration from within the context.
    template<class Rep, class Period>
    TaskContext& DelayAll(std::chrono::duration<Rep, Period> duration)
    {
        return this->Dispatch([=](TaskScheduler& scheduler) -> TaskScheduler&
        {
            return scheduler.DelayAll(duration);
        });
    }

    /// Delays all tasks with a random duration between min and max from within the context.
    template<class RepLeft, class PeriodLeft, class RepRight, class PeriodRight>
    TaskContext& DelayAll(std::chrono::duration<RepLeft, PeriodLeft> min,
        std::chrono::duration<RepRight, PeriodRight> max)
    {
        return this->DelayAll(::randtime(min, max));
    }

    /// Delays all tasks of a group with the given duration from within the context.
    template<class Rep, class Period>
    TaskContext& DelayGroup(TaskScheduler::group_t const group, std::chrono::duration<Rep, Period> duration)
    {
        return this->Dispatch([=](TaskScheduler& scheduler) -> TaskScheduler&
        {
            return scheduler.DelayGroup(group, duration);
        });
    }

    /// Delays all tasks of a group with a random duration between min and max from within the context.
    template<class RepLeft, class PeriodLeft, class RepRight, class PeriodRight>
    TaskContext& DelayGroup(TaskScheduler::group_t const group,
        std::chrono::duration<RepLeft, PeriodLeft> min,
        std::chrono::duration<RepRight, PeriodRight> max)
    {
        return this->DelayGroup(group, ::randtime(min, max));
    }

    /// Reschedule all tasks with the given duration.
    template<class Rep, class Period>
    TaskContext& RescheduleAll(std::chrono::duration<Rep, Period> duration)
    {
        return this->Dispatch([=](TaskScheduler& scheduler) -> TaskScheduler&
        {
            return scheduler.RescheduleAll(duration);
        });
    }

    /// Reschedule all tasks with a random duration between min and max.
    template<class RepLeft, class PeriodLeft, class RepRight, class PeriodRight>
    TaskContext& RescheduleAll(std::chrono::duration<RepLeft, PeriodLeft> min,
        std::chrono::duration<RepRight, PeriodRight> max)
    {
        return this->RescheduleAll(::randtime(min, max));
    }

    /// Reschedule all tasks of a group with the given duration.
    template<class Rep, class Period>
    TaskContext& RescheduleGroup(TaskScheduler::group_t const group, std::chrono::duration<Rep, Period> duration)
    {
        return this->Dispatch([=](TaskScheduler& scheduler) -> TaskScheduler&
        {
            return scheduler.RescheduleGroup(group, duration);
        });
    }

    /// Reschedule all tasks of a group with a random duration between min and max.
    template<class RepLeft, class PeriodLeft, class RepRight, class PeriodRight>
    TaskContext& RescheduleGroup(TaskScheduler::group_t const group,
        std::chrono::duration<RepLeft, PeriodLeft> min,
        std::chrono::duration<RepRight, PeriodRight> max)
    {
        return this->RescheduleGroup(group, ::randtime(min, max));
    }

private:
    /// Asserts if the task was consumed already.
    void AssertOnConsumed() const;

    /// Invokes the associated hook of the task.
    void Invoke();
};

#endif /// TRINITYCORE_TASK_SCHEDULER_H
