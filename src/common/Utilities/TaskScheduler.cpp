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

TaskScheduler::success_t const TaskScheduler::EmptySuccessCallback;

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

TaskScheduler& TaskScheduler::Update()
{
    _now = clock_t::now();
    Dispatch(EmptySuccessCallback);
    return *this;
}

TaskScheduler& TaskScheduler::Update(success_t callback)
{
    _now = clock_t::now();
    Dispatch(callback);
    return *this;
}

TaskScheduler& TaskScheduler::Update(size_t milliseconds)
{
    _now += std::chrono::milliseconds(milliseconds);
    Dispatch(EmptySuccessCallback);
    return *this;
}

TaskScheduler& TaskScheduler::Update(size_t milliseconds, success_t callback)
{
    _now += std::chrono::milliseconds(milliseconds);
    Dispatch(callback);
    return *this;
}

TaskScheduler& TaskScheduler::Update(duration_t difftime)
{
    _now += difftime;
    Dispatch(EmptySuccessCallback);
    return *this;
}

TaskScheduler& TaskScheduler::Update(duration_t difftime, success_t callback)
{
    _now += difftime;
    Dispatch(callback);
    return *this;
}

TaskScheduler& TaskScheduler::Async(std::function<void()> callable)
{
    Schedule(duration_t(1), [callable = std::move(callable)](TaskContext const&) { callable(); });
    return *this;
}

TaskScheduler& TaskScheduler::CancelAll()
{
    /// Clear the task holder
    _task_holder.Clear();
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

TaskScheduler& TaskScheduler::CancelGroupsOf(std::span<group_t> groups)
{
    _task_holder.RemoveIf([groups](TaskContainer const& task) -> bool
    {
        return std::ranges::any_of(groups, [&](group_t group) { return task->IsInGroup(group); });
    });
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

TaskScheduler& TaskScheduler::DelayGroup(group_t group, duration_t duration)
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
    timepoint_t end = _now + duration;
    _task_holder.ModifyIf([end](TaskContainer const& task) -> bool
    {
        task->_end = end;
        return true;
    });
    return *this;
}

TaskScheduler& TaskScheduler::RescheduleGroup(group_t group, duration_t duration)
{
    timepoint_t end = _now + duration;
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

TaskScheduler& TaskScheduler::InsertTask(TaskContainer&& task)
{
    _task_holder.Push(std::move(task));
    return *this;
}

TaskScheduler& TaskScheduler::InsertTask(TaskQueue::Container::node_type&& node)
{
    _task_holder.Push(std::move(node));
    return *this;
}

TaskScheduler& TaskScheduler::ScheduleAt(timepoint_t end, duration_t time, task_handler_t task)
{
    return InsertTask(std::make_shared<Task>(end + time, time, std::move(task)));
}

TaskScheduler& TaskScheduler::ScheduleAt(timepoint_t end, duration_t time, group_t const group, task_handler_t task)
{
    static constexpr repeated_t DEFAULT_REPEATED = 0;
    return InsertTask(std::make_shared<Task>(end + time, time, group, DEFAULT_REPEATED, std::move(task)));
}

void TaskScheduler::Dispatch(success_t const& callback/* = nullptr*/)
{
    // If the validation failed abort the dispatching here.
    if (!_predicate())
        return;

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

void TaskScheduler::TaskQueue::Push(Container::node_type&& node)
{
    container.insert(std::move(node));
}

TaskScheduler::TaskQueue::Container::node_type TaskScheduler::TaskQueue::Pop()
{
    return container.extract(container.begin());
}

TaskScheduler::TaskContainer const& TaskScheduler::TaskQueue::First() const
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
    Container cache;
    for (auto itr = container.begin(); itr != container.end();)
        if (filter(*itr))
            cache.insert(container.extract(itr++));
        else
            ++itr;

    container.merge(cache);
}

bool TaskScheduler::TaskQueue::IsEmpty() const
{
    return container.empty();
}

TaskScheduler::TaskContainer& TaskContext::GetTaskContainer() noexcept
{
    static_assert(std::variant_size_v<decltype(_task)> == 2);
    switch (_task.index())
    {
        case 0: return std::get<0>(_task).value();
        case 1: return std::get<1>(_task);
        default:
            ASSERT(false);
    }
}

TaskScheduler::Task* TaskContext::GetTask() const noexcept
{
    static_assert(std::variant_size_v<decltype(_task)> == 2);
    switch (_task.index())
    {
        case 0: return std::get<0>(_task).value().get();
        case 1: return std::get<1>(_task).get();
        default:
            ASSERT(false);
    }
}

TaskContext::TaskContext(TaskContext&& right) noexcept
    : _task(std::move(right._task)), _owner(std::move(right._owner))
{
    //leave moved-from object in usable state (const qualified functions need to remain callable)
    right._task = GetTaskContainer();
}

TaskContext& TaskContext::operator=(TaskContext&& right) noexcept
{
    if (this != &right)
    {
        _task = std::move(right._task);
        _owner = std::move(right._owner);

        //leave moved-from object in usable state (const qualified functions need to remain callable)
        right._task = GetTaskContainer();
    }
    return *this;
}

bool TaskContext::IsExpired() const
{
    return _owner.expired();
}

bool TaskContext::IsInGroup(TaskScheduler::group_t group) const
{
    return GetTask()->IsInGroup(group);
}

TaskContext& TaskContext::SetGroup(TaskScheduler::group_t group)
{
    GetTask()->_group = group;
    return *this;
}

TaskContext& TaskContext::ClearGroup()
{
    GetTask()->_group = std::nullopt;
    return *this;
}

TaskScheduler::repeated_t TaskContext::GetRepeatCounter() const
{
    return GetTask()->_repeated;
}

TaskContext& TaskContext::Repeat(TaskScheduler::duration_t duration)
{
    // If you encounter this assertion check if you repeat a TaskContext more then 1 time!
    ASSERT(std::holds_alternative<TaskScheduler::TaskQueue::Container::node_type>(_task), "Bad task logic, task context was consumed already!");

    // Set new duration, in-context timing and increment repeat counter
    TaskScheduler::TaskQueue::Container::node_type& taskNode = std::get<TaskScheduler::TaskQueue::Container::node_type>(_task);
    TaskScheduler::TaskContainer task = taskNode.value();
    task->_duration = duration;
    task->_end += duration;
    task->_repeated += 1;
    if (std::shared_ptr<TaskScheduler> scheduler = _owner.lock())
        scheduler->InsertTask(std::move(taskNode));

    //leave *this in usable state (const qualified functions need to remain callable)
    _task = std::move(task);

    return *this;
}

TaskContext& TaskContext::Repeat()
{
    return Repeat(GetTask()->_duration);
}

TaskContext& TaskContext::Async(std::function<void()> callable)
{
    if (std::shared_ptr<TaskScheduler> scheduler = _owner.lock())
        scheduler->Async(std::move(callable));

    return *this;
}

TaskContext& TaskContext::Schedule(TaskScheduler::duration_t time, TaskScheduler::task_handler_t task)
{
    if (std::shared_ptr<TaskScheduler> scheduler = _owner.lock())
         scheduler->ScheduleAt(GetTask()->_end, time, std::move(task));

    return *this;
}

TaskContext& TaskContext::Schedule(TaskScheduler::duration_t time, TaskScheduler::group_t group, TaskScheduler::task_handler_t task)
{
    if (std::shared_ptr<TaskScheduler> scheduler = _owner.lock())
        scheduler->ScheduleAt(GetTask()->_end, time, group, std::move(task));

    return *this;
}

TaskContext& TaskContext::CancelAll()
{
    if (std::shared_ptr<TaskScheduler> scheduler = _owner.lock())
        scheduler->CancelAll();

    return *this;
}

TaskContext& TaskContext::CancelGroup(TaskScheduler::group_t group)
{
    if (std::shared_ptr<TaskScheduler> scheduler = _owner.lock())
        scheduler->CancelGroup(group);

    return *this;
}

TaskContext& TaskContext::CancelGroupsOf(std::span<TaskScheduler::group_t> groups)
{
    if (std::shared_ptr<TaskScheduler> scheduler = _owner.lock())
        scheduler->CancelGroupsOf(groups);

    return *this;
}

TaskContext& TaskContext::DelayAll(TaskScheduler::duration_t duration)
{
    if (std::shared_ptr<TaskScheduler> scheduler = _owner.lock())
        scheduler->DelayAll(duration);

    return *this;
}

TaskContext& TaskContext::DelayGroup(TaskScheduler::group_t group, TaskScheduler::duration_t duration)
{
    if (std::shared_ptr<TaskScheduler> scheduler = _owner.lock())
        scheduler->DelayGroup(group, duration);

    return *this;
}

TaskContext& TaskContext::RescheduleAll(TaskScheduler::duration_t duration)
{
    if (std::shared_ptr<TaskScheduler> scheduler = _owner.lock())
        scheduler->RescheduleAll(duration);

    return *this;
}

TaskContext& TaskContext::RescheduleGroup(TaskScheduler::group_t group, TaskScheduler::duration_t duration)
{
    if (std::shared_ptr<TaskScheduler> scheduler = _owner.lock())
        scheduler->RescheduleGroup(group, duration);

    return *this;
}

void TaskContext::Invoke()
{
    GetTask()->_task(std::move(*this));
}
