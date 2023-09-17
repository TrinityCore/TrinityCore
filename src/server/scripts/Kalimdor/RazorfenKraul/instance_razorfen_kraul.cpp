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

/* ScriptData
SDName: Instance_Razorfen_Kraul
SD%Complete:
SDComment:
SDCategory: Razorfen Kraul
EndScriptData */

#include "ScriptMgr.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "razorfen_kraul.h"

#define WARD_KEEPERS_NR 2

static constexpr DungeonEncounterData Encounters[] =
{
    { BOSS_HUNTER_BONETUSK, { { 1656 } } },
    { BOSS_ROOGUG, { { 438 } } },
    { BOSS_WARLORD_RAMTUSK, { { 1659 } } },
    { BOSS_GROYAT_THE_BLIND_HUNTER, { { 1660 } } },
    { BOSS_CHARLGA_RAZORFLANK, { { 1661 } } },
};

class instance_razorfen_kraul : public InstanceMapScript
{
public:
    instance_razorfen_kraul() : InstanceMapScript(RFKScriptName, 47) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_razorfen_kraul_InstanceMapScript(map);
    }

    struct instance_razorfen_kraul_InstanceMapScript : public InstanceScript
    {
        instance_razorfen_kraul_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(MAX_ENCOUNTER);
            LoadDungeonEncounterData(Encounters);
            WardKeeperDeath = 0;
        }

        ObjectGuid DoorWardGUID;
        int WardKeeperDeath;

        void OnUnitDeath(Unit* unit) override
        {
            switch (unit->GetEntry())
            {
                case NPC_HUNTER_BONETUSK:           SetBossState(BOSS_HUNTER_BONETUSK, DONE); break;
                case NPC_ROOGUG:                    SetBossState(BOSS_ROOGUG, DONE); break;
                case NPC_WARLORD_RAMTUSK:           SetBossState(BOSS_WARLORD_RAMTUSK, DONE); break;
                case NPC_GROYAT_THE_BLIND_HUNTER:   SetBossState(BOSS_GROYAT_THE_BLIND_HUNTER, DONE); break;
                case NPC_CHARLGA_RAZORFLANK:        SetBossState(BOSS_CHARLGA_RAZORFLANK, DONE); break;
                default:                            break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case 21099: DoorWardGUID = go->GetGUID(); break;
                case 20920: go->SetFaction(FACTION_NONE); break; // big fat fugly hack
            }
        }

        void Update(uint32 /*diff*/) override
        {
            if (WardKeeperDeath == WARD_KEEPERS_NR)
                if (GameObject* go = instance->GetGameObject(DoorWardGUID))
                {
                    go->SetFlag(GO_FLAG_IN_USE | GO_FLAG_NODESPAWN);
                    go->SetGoState(GO_STATE_ACTIVE);
                }
        }

        void SetData(uint32 type, uint32 /*data*/) override
        {
            switch (type)
            {
                case EVENT_WARD_KEEPER: WardKeeperDeath++; break;
            }
        }

    };

};

void AddSC_instance_razorfen_kraul()
{
    new instance_razorfen_kraul();
}
