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

#include "firelands.h"
#include "InstanceScript.h"
#include "Map.h"
#include "Player.h"
#include "ScriptMgr.h"

class at_fl_ragnaros_spawn : public OnlyOnceAreaTriggerScript
{
public:
    at_fl_ragnaros_spawn() : OnlyOnceAreaTriggerScript("at_fl_ragnaros_spawn") { }

    bool _OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        if (InstanceScript* instance = player->GetInstanceScript())
            if (instance->GetBossState(DATA_RAGNAROS) != DONE && instance->GetGuidData(DATA_RAGNAROS).IsEmpty())
                instance->instance->SpawnGroupSpawn(SPAWN_GROUP_ID_RAGNAROS);

        return true;
    }
};

void AddSC_firelands()
{
    new at_fl_ragnaros_spawn();
}
