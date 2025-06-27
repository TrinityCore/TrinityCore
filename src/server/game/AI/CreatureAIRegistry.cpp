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

#include "CreatureAIFactory.h"
#include "GameObjectAIFactory.h"

#include "CombatAI.h"
#include "GuardAI.h"
#include "PassiveAI.h"
#include "PetAI.h"
#include "ReactorAI.h"
#include "ScheduledChangeAI.h"
#include "SmartAI.h"
#include "TotemAI.h"

#include "MovementGenerator.h"

namespace AIRegistry
{
    void Initialize()
    {
        (new CreatureAIFactory<NullCreatureAI>("NullCreatureAI"))->RegisterSelf();
        (new CreatureAIFactory<TriggerAI>("TriggerAI"))->RegisterSelf();
        (new CreatureAIFactory<AggressorAI>("AggressorAI"))->RegisterSelf();
        (new CreatureAIFactory<ReactorAI>("ReactorAI"))->RegisterSelf();
        (new CreatureAIFactory<PassiveAI>("PassiveAI"))->RegisterSelf();
        (new CreatureAIFactory<CritterAI>("CritterAI"))->RegisterSelf();
        (new CreatureAIFactory<GuardAI>("GuardAI"))->RegisterSelf();
        (new CreatureAIFactory<PetAI, false>("PetAI"))->RegisterSelf();
        (new CreatureAIFactory<TotemAI, false>("TotemAI"))->RegisterSelf();
        (new CreatureAIFactory<CombatAI>("CombatAI"))->RegisterSelf();
        (new CreatureAIFactory<ArcherAI>("ArcherAI"))->RegisterSelf();
        (new CreatureAIFactory<TurretAI>("TurretAI"))->RegisterSelf();
        (new CreatureAIFactory<VehicleAI>("VehicleAI"))->RegisterSelf();
        (new CreatureAIFactory<SmartAI>("SmartAI"))->RegisterSelf();
        (new CreatureAIFactory<ScheduledChangeAI, false>("ScheduledChangeAI"))->RegisterSelf();

        (new GameObjectAIFactory<NullGameObjectAI>("NullGameObjectAI"))->RegisterSelf();
        (new GameObjectAIFactory<GameObjectAI>("GameObjectAI"))->RegisterSelf();
        (new GameObjectAIFactory<SmartGameObjectAI>("SmartGameObjectAI"))->RegisterSelf();

        (new IdleMovementFactory())->RegisterSelf();
        (new RandomMovementFactory())->RegisterSelf();
        (new WaypointMovementFactory())->RegisterSelf();
    }
}
