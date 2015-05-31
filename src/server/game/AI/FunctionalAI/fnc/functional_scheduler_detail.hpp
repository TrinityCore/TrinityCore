
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

#ifndef _FUNCTIONAL_SCHEDULER_DETAIL_HPP_
#define _FUNCTIONAL_SCHEDULER_DETAIL_HPP_

#include <set>
#include <chrono>
#include <memory>
#include <utility>

#include <random>
#include <chrono>
#include <mutex>

#include <boost/optional.hpp>

namespace fnc
{
    class FunctionScheduler;
    class TaskContextInstance;

    typedef std::shared_ptr<TaskContextInstance> TaskContext;

    typedef std::function<void(TaskContext)> task_handler_t;

    namespace detail
    {
        typedef std::chrono::steady_clock clock_t;

        typedef clock_t::time_point timepoint_t;
        typedef clock_t::duration duration_t;

        class Task
        {
            friend class ::fnc::FunctionScheduler;
            friend class ::fnc::TaskContextInstance;

            typedef size_t group_t;
            typedef size_t repeated_t;

            timepoint_t _end;
            duration_t _duration;
            boost::optional<group_t> _group;
            repeated_t _repeated;
            task_handler_t _task;

        public:
            // All Argument construct
            Task(timepoint_t const& end, duration_t const& duration, boost::optional<group_t> const& group,
                repeated_t const repeated, task_handler_t const& task)
                    : _end(end), _duration(duration), _group(group), _repeated(repeated), _task(task) { }

            // Minimal Argument construct
            Task(timepoint_t const& end, duration_t const& duration, task_handler_t const& task)
                : _end(end), _duration(duration), _group(boost::none), _repeated(0), _task(task) { }

            // Copy construct
            Task(Task const& right)
                : _end(right._end), _duration(right._duration), _group(right._group),
                  _repeated(right._repeated), _task(right._task) { }

            // Move construct
            Task(Task&& right)
                : _end(std::move(right._end)), _duration(std::move(right._duration)),
                   _group(std::move(right._group)), _repeated(right._repeated), _task(std::move(right._task))
            {
                right._repeated = 0;
            }

            // Copy Assign
            Task& operator= (Task const&) = default;

            // Move Assign
            Task& operator= (Task&& right)
            {
                _end = std::move(right._end);
                _duration = std::move(right._duration);
                _group = std::move(right._group);
                _repeated = right._repeated;
                right._repeated = 0;
                _task = std::move(right._task);
                return *this;
            }

            // Order tasks by its end
            inline bool operator< (Task const& other) const
            {
                return _end < other._end;
            }

            inline bool operator> (Task const& other) const
            {
                return _end > other._end;
            }

            // Compare tasks with its end
            inline bool operator== (Task const& other)
            {
                return _end == other._end;
            }

            // Returns true if the task is in the given group
            inline bool IsInGroup(group_t const group) const
            {
                return _group == group;
            }
        };

        template<class _RepLeft, class _PeriodLeft, class _RepRight, class _PeriodRight>
        std::chrono::duration<_RepLeft, _PeriodLeft>
            RandomDurationBetween(std::chrono::duration<_RepLeft, _PeriodLeft> const& min,
                std::chrono::duration<_RepRight, _PeriodRight> const& max)
        {
            static std::mutex _lock;
            std::lock_guard<std::mutex> guard(_lock);

            // Random engine
            static std::random_device rd;
            static std::mt19937 rng(rd());

            std::uniform_int_distribution<typename std::chrono::duration<_RepLeft, _PeriodLeft>::rep>
                _distribution(min.count(), max.count());

            // Distribute
            return std::chrono::duration<_RepLeft, _PeriodLeft>(_distribution(rng));
        }

    }

    typedef std::shared_ptr<detail::Task> TaskContainer;

    namespace detail
    {
        /// Container which provides Task order, insert and reschedule operations.
        struct Compare
        {
            bool operator() (TaskContainer const& left, TaskContainer const& right)
            {
                return (*left.get()) < (*right.get());
            };
        };

        class TaskQueue
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
    }
}

#endif // _FUNCTIONAL_SCHEDULER_DETAIL_HPP_
