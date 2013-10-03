/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "InstanceScript.h"
#include "WorldSession.h"
#include "halls_of_stone.h"
#include <Player.h>

DoorData const doorData[] =
{
    { GO_SJONNIR_DOOR, DATA_BRANN_EVENT, DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    { 0,               0,                DOOR_TYPE_ROOM,    BOUNDARY_NONE } // END
};

class instance_halls_of_stone : public InstanceMapScript
{
    public:
        instance_halls_of_stone() : InstanceMapScript(HoSScriptName, 599) { }

        struct instance_halls_of_stone_InstanceMapScript : public InstanceScript
        {
            instance_halls_of_stone_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);

                KrystallusGUID          = 0;
                MaidenOfGriefGUID       = 0;
                SjonnirGUID             = 0;

                KaddrakGUID             = 0;
                AbedneumGUID            = 0;
                MarnakGUID              = 0;
                BrannGUID               = 0;

                TribunalConsoleGUID     = 0;
                TribunalChestGUID       = 0;
                TribunalSkyFloorGUID    = 0;
                KaddrakGoGUID           = 0;
                AbedneumGoGUID          = 0;
                MarnakGoGUID            = 0;
            }

            void OnCreatureCreate(Creature* creature) OVERRIDE
            {
                switch (creature->GetEntry())
                {
                    case NPC_KRYSTALLUS:
                        KrystallusGUID = creature->GetGUID();
                        break;
                    case NPC_MAIDEN:
                        MaidenOfGriefGUID = creature->GetGUID();
                        break;
                    case NPC_SJONNIR:
                        SjonnirGUID = creature->GetGUID();
                        break;
                    case NPC_MARNAK:
                        MarnakGUID = creature->GetGUID();
                        break;
                    case NPC_KADDRAK:
                        KaddrakGUID = creature->GetGUID();
                        break;
                    case NPC_ABEDNEUM:
                        AbedneumGUID = creature->GetGUID();
                        break;
                    case NPC_BRANN:
                        BrannGUID = creature->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) OVERRIDE
            {
                switch (go->GetEntry())
                {
                    case GO_ABEDNEUM:
                        AbedneumGoGUID = go->GetGUID();
                        break;
                    case GO_MARNAK:
                        MarnakGoGUID = go->GetGUID();
                        break;
                    case GO_KADDRAK:
                        KaddrakGoGUID = go->GetGUID();
                        break;
                    case GO_TRIBUNAL_CONSOLE:
                        TribunalConsoleGUID = go->GetGUID();
                        break;
                    case GO_TRIBUNAL_CHEST:
                    case GO_TRIBUNAL_CHEST_HERO:
                        TribunalChestGUID = go->GetGUID();
                        if (GetBossState(DATA_BRANN_EVENT) == DONE)
                            go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
                        break;
                    case GO_TRIBUNAL_SKY_FLOOR:
                        TribunalSkyFloorGUID = go->GetGUID();
                        break;
                    case GO_SJONNIR_DOOR:
                        AddDoor(go, true);
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectRemove(GameObject* go) OVERRIDE
            {
                switch (go->GetEntry())
                {
                    case GO_SJONNIR_DOOR:
                        AddDoor(go, false);
                        break;
                    default:
                        break;
                }
            }

            uint64 GetData64(uint32 type) const OVERRIDE
            {
                switch (type)
                {
                    case DATA_MAIDEN_OF_GRIEF:
                        return MaidenOfGriefGUID;
                    case DATA_KRYSTALLUS:
                        return KrystallusGUID;
                    case DATA_SJONNIR:
                        return SjonnirGUID;
                    case DATA_KADDRAK:
                        return KaddrakGUID;
                    case DATA_MARNAK:
                        return MarnakGUID;
                    case DATA_ABEDNEUM:
                        return AbedneumGUID;
                    case DATA_GO_TRIBUNAL_CONSOLE:
                        return TribunalConsoleGUID;
                    case DATA_GO_KADDRAK:
                        return KaddrakGoGUID;
                    case DATA_GO_ABEDNEUM:
                        return AbedneumGoGUID;
                    case DATA_GO_MARNAK:
                        return MarnakGoGUID;
                    case DATA_GO_SKY_FLOOR:
                        return TribunalSkyFloorGUID;
                    default:
                        break;
                }

                return 0;
            }

            bool SetBossState(uint32 type, EncounterState state) OVERRIDE
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_BRANN_EVENT:
                        if (state == DONE)
                        {
                            if (GameObject* go = instance->GetGameObject(TribunalChestGUID))
                                go->RemoveFlag(GAMEOBJECT_FLAGS,GO_FLAG_INTERACT_COND);
                        }
                        break;
                    default:
                        break;
                }

                return true;
            }

            bool CheckRequiredBosses(uint32 bossId, Player const* player /*= NULL*/) const OVERRIDE
            {
                if (player && player->GetSession()->HasPermission(rbac::RBAC_PERM_SKIP_CHECK_INSTANCE_REQUIRED_BOSSES))
                    return true;

                switch (bossId)
                {
                    case DATA_SJONNIR:
                        if (GetBossState(DATA_BRANN_EVENT) != DONE)
                            return false;
                        break;
                    default:
                        break;
                }

                return true;
            }

            std::string GetSaveData() OVERRIDE
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "H S " << GetBossSaveData();

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(char const* str) OVERRIDE
            {
                if (!str)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(str);

                char dataHead1, dataHead2;

                std::istringstream loadStream(str);
                loadStream >> dataHead1 >> dataHead2;

                if (dataHead1 == 'H' && dataHead2 == 'S')
                {
                    for (uint32 i = 0; i < EncounterCount; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;
                        SetBossState(i, EncounterState(tmpState));
                    }
                }
                else
                    OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }

        protected:
            uint64 KrystallusGUID;
            uint64 MaidenOfGriefGUID;
            uint64 SjonnirGUID;

            uint64 KaddrakGUID;
            uint64 AbedneumGUID;
            uint64 MarnakGUID;
            uint64 BrannGUID;

            uint64 TribunalConsoleGUID;
            uint64 TribunalChestGUID;
            uint64 TribunalSkyFloorGUID;
            uint64 KaddrakGoGUID;
            uint64 AbedneumGoGUID;
            uint64 MarnakGoGUID;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const OVERRIDE
        {
            return new instance_halls_of_stone_InstanceMapScript(map);
        }
};

void AddSC_instance_halls_of_stone()
{
    new instance_halls_of_stone();
}
