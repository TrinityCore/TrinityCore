
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

#include "functional_scheduler_detail.hpp"

namespace fnc
{
    namespace detail
    {
        void TaskQueue::Push(TaskContainer&& task)
        {
            container.insert(task);
        }

        fnc::TaskContainer TaskQueue::Pop()
        {
            TaskContainer result = *container.begin();
            container.erase(container.begin());
            return result;
        }

        TaskContainer const& TaskQueue::First() const
        {
            return *container.begin();
        }

        void TaskQueue::Clear()
        {
            container.clear();
        }

        void TaskQueue::RemoveIf(std::function<bool(TaskContainer const&)> const& filter)
        {
            for (auto itr = container.begin(); itr != container.end();)
                if (filter(*itr))
                    itr = container.erase(itr);
                else
                    ++itr;
        }

        void TaskQueue::ModifyIf(std::function<bool(TaskContainer const&)> const& filter)
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

        bool TaskQueue::IsEmpty() const
        {
            return container.empty();
        }

    } // detail

} // fnc

