
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

#include "functional_scheduler.hpp"

namespace fnc
{
    FunctionScheduler& FunctionScheduler::Update()
    {
        _now = detail::clock_t::now();
        Dispatch();
        return *this;
    }

    FunctionScheduler& FunctionScheduler::Update(size_t const milliseconds)
    {
        return Update(std::chrono::milliseconds(milliseconds));
    }

    FunctionScheduler& FunctionScheduler::Async(std::function<void()> const& callable)
    {
        _asyncHolder.push(callable);
        return *this;
    }

    FunctionScheduler& FunctionScheduler::CancelAll()
    {
        /// Clear the task holder
        _task_holder.Clear();
        _asyncHolder = AsyncHolder();
        return *this;
    }

    FunctionScheduler& FunctionScheduler::CancelGroup(detail::Task::group_t const group)
    {
        _task_holder.RemoveIf([group](TaskContainer const& task) -> bool
        {
            return task->IsInGroup(group);
        });
        return *this;
    }

    FunctionScheduler& FunctionScheduler::CancelGroupsOf(std::vector<detail::Task::group_t> const& groups)
    {
        std::for_each(groups.begin(), groups.end(),
            std::bind(&FunctionScheduler::CancelGroup, this, std::placeholders::_1));

        return *this;
    }

    FunctionScheduler& FunctionScheduler::InsertTask(TaskContainer task)
    {
        _task_holder.Push(std::forward<TaskContainer>(task));
        return *this;
    }

    void FunctionScheduler::Dispatch()
    {
        // Process all asyncs
        while (!_asyncHolder.empty())
        {
            _asyncHolder.front()();
            _asyncHolder.pop();
        }

        while (!_task_holder.IsEmpty())
        {
            if (_task_holder.First()->_end > _now)
                break;

            // Perfect forward the context to the handler
            // Use weak references to catch destruction before callbacks.
            TaskContext context(new TaskContextInstance(_task_holder.Pop(),
                std::weak_ptr<FunctionScheduler>(self_reference)));

            // Invoke the context
            context->Invoke();
        }
    }
}
