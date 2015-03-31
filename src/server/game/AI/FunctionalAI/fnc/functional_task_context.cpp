
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

#include "functional_task_context.hpp"

namespace fnc
{
    TaskContextInstance& TaskContextInstance::Dispatch(std::function<FunctionScheduler&(FunctionScheduler&)> const& apply)
    {
        if (auto const owner = _owner.lock())
            apply(*owner);

        return *this;
    }

    bool TaskContextInstance::IsInGroup(detail::Task::group_t const group) const
    {
        return _task->IsInGroup(group);
    }

    TaskContextInstance& TaskContextInstance::SetGroup(detail::Task::group_t const group)
    {
        _task->_group = group;
        return *this;
    }

    TaskContextInstance& TaskContextInstance::ClearGroup()
    {
        _task->_group = boost::none;
        return *this;
    }
    
    detail::Task::repeated_t TaskContextInstance::GetRepeatCounter() const
    {
        return _task->_repeated;
    }

    TaskContextInstance& TaskContextInstance::Async(std::function<void()> const& callable)
    {
        return Dispatch(std::bind(&FunctionScheduler::Async, std::placeholders::_1, callable));
    }

    TaskContextInstance& TaskContextInstance::CancelAll()
    {
        return Dispatch(std::mem_fn(&FunctionScheduler::CancelAll));
    }

    TaskContextInstance& TaskContextInstance::CancelGroup(detail::Task::group_t const group)
    {
        return Dispatch(std::bind(&FunctionScheduler::CancelGroup, std::placeholders::_1, group));
    }

    TaskContextInstance& TaskContextInstance::CancelGroupsOf(std::vector<detail::Task::group_t> const& groups)
    {
        return Dispatch(std::bind(&FunctionScheduler::CancelGroupsOf, std::placeholders::_1, groups));
    }

    void TaskContextInstance::Invoke()
    {
        _task->_task(shared_from_this());
    }
}
