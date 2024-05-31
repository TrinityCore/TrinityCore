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

#include "ScriptActions.h"
#include "GameTime.h"

namespace Scripting::v2
{
ActionBase::ActionBase() : _isReady(false)
{
}

ActionBase::ActionBase(ActionBase const& other) = default;
ActionBase::ActionBase(ActionBase&& other) noexcept = default;
ActionBase& ActionBase::operator=(ActionBase const& other) = default;
ActionBase& ActionBase::operator=(ActionBase&& other) noexcept = default;

ActionBase::~ActionBase() = default;

bool ActionBase::IsReady() const noexcept
{
    return _isReady;
}

void ActionBase::MarkCompleted() noexcept
{
    _isReady = true;
}

void MarkActionCompleted(ActionBase& action)
{
    action.MarkCompleted();
}

WaitAction::WaitAction(TimePoint waitEnd) : _waitEnd(waitEnd)
{
}

bool WaitAction::IsReady() const noexcept
{
    return _waitEnd <= GameTime::Now();
}
}
