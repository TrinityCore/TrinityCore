/*
 * Copyright 2021 ShadowCore
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

#include "ScriptMgr.h"
#include "Player.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "InstanceScript.h"
#include "CombatAI.h"
#include "LFGMgr.h"
#include "Group.h"
#include "darkmaul_citadel.h"

// map 2236
struct instance_darkmaul_citadel : public InstanceScript
{
    instance_darkmaul_citadel(InstanceMap* map) : InstanceScript(map) {  }

private:
    bool CombatAI;    
        Creature* GetGarrick() { return GetCreature(NPC_COMBAT_AI_GARRICK); }
        Creature* GetHenry() { return GetCreature(NPC_COMBAT_AI_HENRY); }   

    void Initialize() override
    {
        CombatAI = false;
    }

    void OnPlayerEnter(Player* player) override
    {
        if(!player)
            return;

        if (player->GetGUID() == ObjectGuid::Empty)
            return;

        if (!CombatAI)
            GenerateCombatAI(player);
    }

    void GenerateCombatAI(Player* player)
    {
        if(!player)
            return;

        if (player->GetGUID() == ObjectGuid::Empty)
            return;

        CombatAI = true;

        if (Creature* garrick = GetGarrick())
        {
            if(int32 playerFaction = player->GetFaction())
                garrick->SetFaction(playerFaction);

            if(int32 playerAttackPower = player->GetTotalAttackPowerValue(BASE_ATTACK) * 3.0f)
                garrick->SetAttackPower(playerAttackPower);

            if (player->GetGUID() != ObjectGuid::Empty)
            {
                garrick->SetOwnerGUID(player->GetGUID());
                garrick->GetMotionMaster()->MoveFollow(garrick->GetOwner(), PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
            }
        }

        if (Creature* henry = GetHenry())
        {
            if(int32 playerFaction = player->GetFaction())
                henry->SetFaction(playerFaction);

            if(int32 playerAttackPower = player->GetTotalAttackPowerValue(BASE_ATTACK) * 3.0f)
                henry->SetAttackPower(playerAttackPower);

            if (player->GetGUID() != ObjectGuid::Empty)
            {
                henry->SetOwnerGUID(player->GetGUID());
                henry->GetMotionMaster()->MoveFollow(henry->GetOwner(), PET_FOLLOW_DIST, PET_FOLLOW_ANGLE*3);
            }
        }
    }
};

void AddSC_instance_darkmaul_citadel()
{
    RegisterInstanceScript(instance_darkmaul_citadel, 2236);
}
