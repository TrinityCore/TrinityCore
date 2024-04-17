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

#include "MovementGenerator.h"
#include "StringFormat.h"

MovementGenerator::~MovementGenerator()
{
    // Ensure script doesn't get stuck waiting for this movement
    SetScriptResult(MovementStopReason::Interrupted);
}

std::string MovementGenerator::GetDebugInfo() const
{
    return Trinity::StringFormat("Mode: {} Priority: {} Flags: {} BaseUniteState: {}",
        Mode, Priority, Flags, BaseUnitState);
}

void MovementGenerator::SetScriptResult(MovementStopReason reason)
{
    if (ScriptResult)
    {
        ScriptResult->SetResult(reason);
        ScriptResult.reset();
    }
}
