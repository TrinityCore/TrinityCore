/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "Log.h"
#include "Map.h"
#include "steam_vault.h"

struct go_main_chambers_access_panel : public GameObjectAI
{
    go_main_chambers_access_panel(GameObject* go) : GameObjectAI(go), _instance(go->GetInstanceScript()) { }

    bool GossipHello(Player* /*player*/) override
    {
        if (Creature* controller = _instance->GetCreature(DATA_DOOR_CONTROLLER))
            controller->AI()->Talk(CONTROLLER_TEXT_ACESS_USED);
        _instance->SetData(ACTION_OPEN_DOOR, 0);
        me->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
        me->SetGoState(GO_STATE_ACTIVE);
        return true;
    }

private:
    InstanceScript* _instance;
};

ObjectData const gameObjectData[] =
{
    { GO_ACCESS_PANEL_HYDRO, DATA_ACCESS_PANEL_HYDRO },
    { GO_ACCESS_PANEL_MEK,   DATA_ACCESS_PANEL_MEK   },
    { GO_MAIN_CHAMBERS_DOOR, DATA_MAIN_DOOR          },
    { 0,                     0                       } // END
};

ObjectData const creatureData[] =
{
    { NPC_HYDROMANCER_THESPIA,      DATA_HYDROMANCER_THESPIA   },
    { NPC_MEKGINEER_STEAMRIGGER,    DATA_MEKGINEER_STEAMRIGGER },
    { NPC_WARLORD_KALITHRESH,       DATA_WARLORD_KALITHRESH    },
    { NPC_COILFANG_DOOR_CONTROLLER, DATA_DOOR_CONTROLLER       },
    { 0,                            0                          } // END
};

class instance_steam_vault : public InstanceMapScript
{
    public:
        instance_steam_vault() : InstanceMapScript(SteamVaultScriptName, 545) { }

        struct instance_steam_vault_InstanceMapScript : public InstanceScript
        {
            instance_steam_vault_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, gameObjectData);
                distillerState = 0;
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                InstanceScript::OnGameObjectCreate(go);
                if (go->GetEntry() == GO_MAIN_CHAMBERS_DOOR)
                    CheckMainDoor();
            }

            void CheckMainDoor()
            {
                if (GetBossState(DATA_HYDROMANCER_THESPIA) == DONE && GetBossState(DATA_MEKGINEER_STEAMRIGGER) == DONE)
                {
                    if (Creature* controller = GetCreature(DATA_DOOR_CONTROLLER))
                        controller->AI()->Talk(CONTROLLER_TEXT_MAIN_DOOR_OPEN);

                    if (GameObject* mainDoor = GetGameObject(DATA_MAIN_DOOR))
                    {
                        HandleGameObject(ObjectGuid::Empty, true, mainDoor);
                       mainDoor->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                    }
                }
            }

            void SetData(uint32 type, uint32 data) override
            {
                if (type == DATA_DISTILLER)
                    distillerState = data;
                else if (type == ACTION_OPEN_DOOR)
                    CheckMainDoor();
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_DISTILLER)
                    return distillerState;
                return 0;
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_HYDROMANCER_THESPIA:
                        if (state == DONE)
                            if (GameObject* panel = GetGameObject(DATA_ACCESS_PANEL_HYDRO))
                                panel->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        break;
                    case DATA_MEKGINEER_STEAMRIGGER:
                        if (state == DONE)
                            if (GameObject* panel = GetGameObject(DATA_ACCESS_PANEL_MEK))
                                panel->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        break;
                    default:
                        break;
                }

                return true;
            }

        protected:
            uint8 distillerState;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_steam_vault_InstanceMapScript(map);
        }
};

void AddSC_instance_steam_vault()
{
    RegisterGameObjectAI(go_main_chambers_access_panel);
    new instance_steam_vault();
}
