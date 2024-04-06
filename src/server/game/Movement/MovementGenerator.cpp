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
#include "Creature.h"
#include "IdleMovementGenerator.h"
#include "MovementDefines.h"
#include "PathGenerator.h"
#include "RandomMovementGenerator.h"
#include "UnitAI.h"
#include "WaypointMovementGenerator.h"
#include <sstream>

MovementGenerator::~MovementGenerator()
{
    SetScriptResult(MovementStopReason::Interrupted);
}

std::string MovementGenerator::GetDebugInfo() const
{
    std::stringstream sstr;
    sstr << std::boolalpha
        << "Mode: " << std::to_string(Mode)
        << " Priority: " << std::to_string(Priority)
        << " Flags: " << Flags
        << " BaseUniteState: " << BaseUnitState;
    return sstr.str();
}

void MovementGenerator::SetScriptResult(MovementStopReason reason)
{
    if (ScriptResult)
    {
        ScriptResult->SetResult(reason);
        ScriptResult.reset();
    }
}

IdleMovementFactory::IdleMovementFactory() : MovementGeneratorCreator(IDLE_MOTION_TYPE) { }

MovementGenerator* IdleMovementFactory::Create(Unit* /*object*/) const
{
    static IdleMovementGenerator instance;
    return &instance;
}

RandomMovementFactory::RandomMovementFactory() : MovementGeneratorCreator(RANDOM_MOTION_TYPE) { }

MovementGenerator* RandomMovementFactory::Create(Unit* /*object*/) const
{
    return new RandomMovementGenerator<Creature>();
}

WaypointMovementFactory::WaypointMovementFactory() : MovementGeneratorCreator(WAYPOINT_MOTION_TYPE) { }

MovementGenerator* WaypointMovementFactory::Create(Unit* /*object*/) const
{
    return new WaypointMovementGenerator<Creature>(0, true);
}
