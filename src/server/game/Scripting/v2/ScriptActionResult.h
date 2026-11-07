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

#ifndef TRINITYCORE_SCRIPT_ACTION_RESULT_H
#define TRINITYCORE_SCRIPT_ACTION_RESULT_H

#include <memory>

namespace Scripting::v2
{
class ActionBase;

template <typename T>
struct ActionResultValueHolder
{
    ActionBase& Action;
    T Result = { };
};

void MarkActionCompleted(ActionBase& action);

template <typename T>
class ActionResultSetter
{
public:
    ActionResultSetter() = default;

    explicit ActionResultSetter(std::shared_ptr<ActionResultValueHolder<T>>&& action) : _action(std::move(action)) { }

    void SetResult(T result)
    {
        if (std::shared_ptr<ActionResultValueHolder<T>> ptr = _action.lock())
        {
            ptr->Result = result;
            MarkActionCompleted(ptr->Action);
        }
    }

    explicit operator bool() const { return !_action.expired(); }

    void Reset() { _action.reset(); }

private:
    std::weak_ptr<ActionResultValueHolder<T>> _action;
};

template <>
class ActionResultSetter<void>
{
public:
    ActionResultSetter() = default;

    explicit ActionResultSetter(std::shared_ptr<ActionBase> action) : _action(std::move(action)) { }

    void SetResult()
    {
        if (std::shared_ptr<ActionBase> ptr = _action.lock())
            MarkActionCompleted(*ptr);
    }

    explicit operator bool() const { return !_action.expired(); }

    void Reset() { _action.reset(); }

private:
    std::weak_ptr<ActionBase> _action;
};
}

#endif // TRINITYCORE_SCRIPT_ACTION_RESULT_H
