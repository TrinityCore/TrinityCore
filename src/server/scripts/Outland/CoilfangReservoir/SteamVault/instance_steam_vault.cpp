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

#include "ScriptMgr.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "steam_vault.h"

static constexpr ObjectData gameObjectData[] =
{
    { GO_ACCESS_PANEL_THESPIA,      DATA_ACCESS_PANEL_THESPIA     },
    { GO_ACCESS_PANEL_STEAMRIGGER,  DATA_ACCESS_PANEL_STEAMRIGGER },
    { GO_MAIN_CHAMBERS_DOOR,        DATA_MAIN_CHAMBERS_DOOR       },
    { 0,                            0                             } // END
};

static constexpr ObjectData creatureData[] =
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
            instance_steam_vault_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, gameObjectData);
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                InstanceScript::OnGameObjectCreate(go);

                if (go->GetEntry() == GO_MAIN_CHAMBERS_DOOR)
                {
                    if (GetBossState(DATA_HYDROMANCER_THESPIA) == DONE && GetBossState(DATA_MEKGINEER_STEAMRIGGER) == DONE)
                    {
                        HandleGameObject(ObjectGuid::Empty, true, go);
                        go->ActivateObject(GameObjectActions(GameObjectActions::MakeInert));
                    }
                }
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_HYDROMANCER_THESPIA:
                        if (state == DONE)
                            if (GameObject* panel = GetGameObject(DATA_ACCESS_PANEL_THESPIA))
                                panel->ActivateObject(GameObjectActions(GameObjectActions::MakeActive));
                        break;
                    case DATA_MEKGINEER_STEAMRIGGER:
                        if (state == DONE)
                            if (GameObject* panel = GetGameObject(DATA_ACCESS_PANEL_STEAMRIGGER))
                                panel->ActivateObject(GameObjectActions(GameObjectActions::MakeActive));
                        break;
                    default:
                        break;
                }

                return true;
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_steam_vault_InstanceMapScript(map);
        }
};

void AddSC_instance_steam_vault()
{
    new instance_steam_vault();
}
