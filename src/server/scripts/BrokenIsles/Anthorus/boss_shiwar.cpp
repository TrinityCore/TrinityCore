/*
 * This file is part of the AshamaneCore Project. See AUTHORS file for Copyright information
 * Copyright (C) 2018+ MagicStormProject <https://github.com/MagicStormTeam>
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "GameObject.h"
#include "anthorus.h"

struct boss_shiwar : public BossAI
{
 boss_shiwar(Creature* creature) : BossAI(creature, DATA_SHIWAR) { }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (uint64(damage) > me->GetHealth())
        {
            _JustDied();

            if (GameObject* go = instance->GetGameObject(GO_DOOR_ROOM_GOROTH_ES))
                go->GetPhaseShift().AddPhase(170, PhaseFlags::None, nullptr);
        }
    }
};

void AddSC_boss_shiwar()
{
  RegisterCreatureAI(boss_shiwar);
}
