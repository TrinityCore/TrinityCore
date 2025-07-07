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

#include "TaskScheduler.h"
#include "Errors.h"

TaskScheduler::TaskScheduler()
    : self_reference(this, [](TaskScheduler const*) { }),
    _now(clock_t::now()),
    _predicate(EmptyValidator)
{
}

TaskScheduler::~TaskScheduler() = default;

TaskScheduler& TaskScheduler::ClearValidator()
{
    _predicate = EmptyValidator;
    return *this;
}

TaskScheduler& TaskScheduler::Update(success_t const& callback/* = nullptr*/)
{
    _now = clock_t::now();
    Dispatch(callback);
    return *this;
}

TaskScheduler& TaskScheduler::Update(size_t milliseconds, success_t const& callback/* = nullptr*/)
{
    return Update(std::chrono::milliseconds(milliseconds), callback);
}

TaskScheduler& TaskScheduler::Update(duration_t difftime, success_t const& callback/* = nullptr*/)
{
    _now += difftime;
    Dispatch(callback);
    return *this;
}

TaskScheduler& TaskScheduler::Async(std::function<void()> callable)
{
    _asyncHolder.emplace(std::move(callable));
    return *this;
}

TaskScheduler& TaskScheduler::CancelAll()
{
    /// Clear the task holder
    _task_holder.Clear();
    _asyncHolder = AsyncHolder();
    return *this;
}

TaskScheduler& TaskScheduler::CancelGroup(group_t group)
{
    _task_holder.RemoveIf([group](TaskContainer const& task) -> bool
    {
        return task->IsInGroup(group);
    });
    return *this;
}

TaskScheduler& TaskScheduler::CancelGroupsOf(std::vector<group_t> const& groups)
{
    for (group_t group : groups)
        CancelGroup(group);

    return *this;
}

TaskScheduler& TaskScheduler::DelayAll(duration_t duration)
{
    _task_holder.ModifyIf([&duration](TaskContainer const& task) -> bool
    {
        task->_end += duration;
        return true;
    });
    return *this;
}

TaskScheduler& TaskScheduler::DelayGroup(group_t const group, duration_t duration)
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

TaskScheduler& TaskScheduler::RescheduleAll(duration_t duration)
{
    auto const end = _now + duration;
    _task_holder.ModifyIf([end](TaskContainer const& task) -> bool
    {
        task->_end = end;
        return true;
    });
    return *this;
}

TaskScheduler& TaskScheduler::RescheduleGroup(group_t const group, duration_t duration)
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

TaskScheduler& TaskScheduler::InsertTask(TaskContainer task)
{
    _task_holder.Push(std::move(task));
    return *this;
}

TaskScheduler& TaskScheduler::ScheduleAt(timepoint_t end, duration_t time, task_handler_t task)
{
    return InsertTask(TaskContainer(new Task(end + time, time, std::move(task))));
}

TaskScheduler& TaskScheduler::ScheduleAt(timepoint_t end, duration_t time, group_t const group, task_handler_t task)
{
    static constexpr repeated_t DEFAULT_REPEATED = 0;
    return InsertTask(TaskContainer(new Task(end + time, time, group, DEFAULT_REPEATED, std::move(task))));
}

void TaskScheduler::Dispatch(success_t const& callback/* = nullptr*/)
{
    // If the validation failed abort the dispatching here.
    if (!_predicate())
        return;

    // Process all asyncs
    while (!_asyncHolder.empty())
    {
        _asyncHolder.front()();
        _asyncHolder.pop();

        // If the validation failed abort the dispatching here.
        if (!_predicate())
            return;
    }

    while (!_task_holder.IsEmpty())
    {
        if (_task_holder.First()->_end > _now)
            break;

        // Perfect forward the context to the handler
        // Use weak references to catch destruction before callbacks.
        TaskContext context(_task_holder.Pop(), std::weak_ptr<TaskScheduler>(self_reference));

        // Invoke the context
        context.Invoke();

        // If the validation failed abort the dispatching here.
        if (!_predicate())
            return;
    }

    // On finish call the final callback
    if (callback)
        callback();
}

void TaskScheduler::TaskQueue::Push(TaskContainer&& task)
{
    container.emplace(std::move(task));
}

auto TaskScheduler::TaskQueue::Pop() -> TaskContainer
{
    TaskContainer result = *container.begin();
    container.erase(container.begin());
    return result;
}

auto TaskScheduler::TaskQueue::First() const -> TaskContainer const&
{
    return *container.begin();
}

void TaskScheduler::TaskQueue::Clear()
{
    container.clear();
}

void TaskScheduler::TaskQueue::RemoveIf(std::function<bool(TaskContainer const&)> const& filter)
{
    for (auto itr = container.begin(); itr != container.end();)
        if (filter(*itr))
            itr = container.erase(itr);
        else
            ++itr;
}

void TaskScheduler::TaskQueue::ModifyIf(std::function<bool(TaskContainer const&)> const& filter)
{
    std::vector<TaskContainer> cache;
    for (auto itr = container.begin(); itr != container.end();)
        if (filter(*itr))
        {
            cache.push_back(*itr);
            itr = container.erase(itr);
        }
        else
            ++itr;

    container.insert(cache.begin(), cache.end());
}

bool TaskScheduler::TaskQueue::IsEmpty() const
{
    return container.empty();
}

TaskContext& TaskContext::Dispatch(std::function<TaskScheduler&(TaskScheduler&)> const& apply)
{
    if (std::shared_ptr<TaskScheduler> owner = _owner.lock())
        apply(*owner);

    return *this;
}

bool TaskContext::IsExpired() const
{
    return _owner.expired();
}

bool TaskContext::IsInGroup(TaskScheduler::group_t const group) const
{
    return _task->IsInGroup(group);
}

TaskContext& TaskContext::SetGroup(TaskScheduler::group_t const group)
{
    _task->_group = group;
    return *this;
}

TaskContext& TaskContext::ClearGroup()
{
    _task->_group = std::nullopt;
    return *this;
}

TaskScheduler::repeated_t TaskContext::GetRepeatCounter() const
{
    return _task->_repeated;
}

TaskContext& TaskContext::Repeat(TaskScheduler::duration_t duration)
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

TaskContext& TaskContext::Async(std::function<void()> const& callable)
{
    return Dispatch([&](TaskScheduler& scheduler) -> TaskScheduler&
    {
        return scheduler.Async(callable);
    });
}

TaskContext& TaskContext::Schedule(TaskScheduler::duration_t time, TaskScheduler::task_handler_t task)
{
    auto const end = _task->_end;
    return this->Dispatch([end, time, task = std::move(task)](TaskScheduler& scheduler) mutable -> TaskScheduler&
    {
        return scheduler.ScheduleAt(end, time, std::move(task));
    });
}

TaskContext& TaskContext::Schedule(TaskScheduler::duration_t time, TaskScheduler::group_t const group, TaskScheduler::task_handler_t task)
{
    auto const end = _task->_end;
    return this->Dispatch([end, time, group, task = std::move(task)](TaskScheduler& scheduler) mutable -> TaskScheduler&
    {
        return scheduler.ScheduleAt(end, time, group, std::move(task));
    });
}

TaskContext& TaskContext::CancelAll()
{
    return Dispatch(&TaskScheduler::CancelAll);
}

TaskContext& TaskContext::CancelGroup(TaskScheduler::group_t const group)
{
    return Dispatch([=](TaskScheduler& scheduler) -> TaskScheduler&
    {
        return scheduler.CancelGroup(group);
    });
}

TaskContext& TaskContext::CancelGroupsOf(std::vector<TaskScheduler::group_t> const& groups)
{
    return Dispatch([&](TaskScheduler& scheduler) -> TaskScheduler&
    {
        return scheduler.CancelGroupsOf(groups);
    });
}

TaskContext& TaskContext::DelayAll(TaskScheduler::duration_t duration)
{
    return this->Dispatch([=](TaskScheduler& scheduler) -> TaskScheduler&
    {
        return scheduler.DelayAll(duration);
    });
}

TaskContext& TaskContext::DelayGroup(TaskScheduler::group_t const group, TaskScheduler::duration_t duration)
{
    return this->Dispatch([=](TaskScheduler& scheduler) -> TaskScheduler&
    {
        return scheduler.DelayGroup(group, duration);
    });
}

TaskContext& TaskContext::RescheduleAll(TaskScheduler::duration_t duration)
{
    return this->Dispatch([=](TaskScheduler& scheduler) -> TaskScheduler&
    {
        return scheduler.RescheduleAll(duration);
    });
}

TaskContext& TaskContext::RescheduleGroup(TaskScheduler::group_t const group, TaskScheduler::duration_t duration)
{
    return this->Dispatch([=](TaskScheduler& scheduler) -> TaskScheduler&
    {
        return scheduler.RescheduleGroup(group, duration);
    });
}

void TaskContext::AssertOnConsumed() const
{
    // This was adapted to TC to prevent static analysis tools from complaining.
    // If you encounter this assertion check if you repeat a TaskContext more then 1 time!
    ASSERT(!(*_consumed) && "Bad task logic, task context was consumed already!");
}

void TaskContext::Invoke()
{
    _task->_task(*this);
}
