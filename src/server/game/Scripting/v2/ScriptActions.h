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

#ifndef TRINITYCORE_SCRIPT_ACTIONS_H
#define TRINITYCORE_SCRIPT_ACTIONS_H

#include "ScriptActionResult.h"
#include "Duration.h"

namespace Scripting::v2
{
class ActionBase;

template<typename T>
class ActionResultSetter;

class ActionBase
{
public:
    ActionBase();
    ActionBase(ActionBase const& other);
    ActionBase(ActionBase&& other) noexcept;
    ActionBase& operator=(ActionBase const& other);
    ActionBase& operator=(ActionBase&& other) noexcept;
    virtual ~ActionBase();

    virtual bool IsReady() const noexcept;

protected:
    friend void MarkActionCompleted(ActionBase& action);
    void MarkCompleted() noexcept;

private:
    bool _isReady;
};

class WaitAction : public ActionBase
{
public:
    explicit WaitAction(TimePoint waitEnd);

    bool IsReady() const noexcept override;

private:
    TimePoint _waitEnd;
};

template<typename T>
class ActionResult : public ActionBase
{
public:
    [[nodiscard]] static ActionResultSetter<T> GetResultSetter(std::shared_ptr<ActionResult> action)
    {
        T* resultPtr = &action->_result;
        return ActionResultSetter<T>(std::move(action), resultPtr);
    }

private:
    T _result = { };
};

template<>
class ActionResult<void> : public ActionBase
{
public:
    [[nodiscard]] static ActionResultSetter<void> GetResultSetter(std::shared_ptr<ActionResult> action)
    {
        return ActionResultSetter<void>(std::move(action));
    }
};
}

#endif // TRINITYCORE_SCRIPT_ACTIONS_H
