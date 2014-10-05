/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "InstanceScript.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "WorldSession.h"
#include "halls_of_stone.h"

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
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);
            }

            void OnCreatureCreate(Creature* creature) override
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

            void OnGameObjectCreate(GameObject* go) override
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
                            go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
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

            void OnGameObjectRemove(GameObject* go) override
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

            ObjectGuid GetGuidData(uint32 type) const override
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

                return ObjectGuid::Empty;
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_BRANN_EVENT:
                        if (state == DONE)
                        {
                            if (GameObject* go = instance->GetGameObject(TribunalChestGUID))
                                go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        }
                        break;
                    default:
                        break;
                }

                return true;
            }

            bool CheckRequiredBosses(uint32 bossId, Player const* player = nullptr) const override
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

        protected:
            ObjectGuid KrystallusGUID;
            ObjectGuid MaidenOfGriefGUID;
            ObjectGuid SjonnirGUID;

            ObjectGuid KaddrakGUID;
            ObjectGuid AbedneumGUID;
            ObjectGuid MarnakGUID;
            ObjectGuid BrannGUID;

            ObjectGuid TribunalConsoleGUID;
            ObjectGuid TribunalChestGUID;
            ObjectGuid TribunalSkyFloorGUID;
            ObjectGuid KaddrakGoGUID;
            ObjectGuid AbedneumGoGUID;
            ObjectGuid MarnakGoGUID;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_halls_of_stone_InstanceMapScript(map);
        }
};

void AddSC_instance_halls_of_stone()
{
    new instance_halls_of_stone();
}
