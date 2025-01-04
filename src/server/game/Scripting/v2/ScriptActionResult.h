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

void MarkActionCompleted(ActionBase& action);

template <typename T>
class ActionResultSetter
{
public:
    explicit ActionResultSetter(std::shared_ptr<ActionBase> action, T* result) : _action(std::move(action)), _result(result) { }

    void SetResult(T result)
    {
        if (std::shared_ptr<ActionBase> ptr = _action.lock())
        {
            *_result = std::move(result);
            MarkActionCompleted(*ptr);
        }
    }

private:
    std::weak_ptr<ActionBase> _action;
    T* _result;
};

template <>
class ActionResultSetter<void>
{
public:
    explicit ActionResultSetter(std::shared_ptr<ActionBase> action) : _action(std::move(action)) { }

    void SetResult()
    {
        if (std::shared_ptr<ActionBase> ptr = _action.lock())
            MarkActionCompleted(*ptr);
    }

private:
    std::weak_ptr<ActionBase> _action;
};
}

#endif // TRINITYCORE_SCRIPT_ACTION_RESULT_H
