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

#include "zulgurub.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ScriptMgr.h"

enum ZulGurubGameEventIds
{
    EVENT_MUDSKUNK_LURE = 9104
};

DoorData const doorData[] =
{
    { GO_FORCEFIELD, DATA_ARLOKK, DOOR_TYPE_ROOM },
    { 0,             0,           DOOR_TYPE_ROOM } // END
};

ObjectData const creatureData[] =
{
    { NPC_ZEALOT_LORKHAN,     DATA_LORKHAN },
    { NPC_ZEALOT_ZATH,        DATA_ZATH },
    { NPC_HIGH_PRIEST_THEKAL, DATA_THEKAL },
    { NPC_JINDO_THE_HEXXER,   DATA_JINDO },
    { NPC_ARLOKK,             DATA_ARLOKK },
    { NPC_PRIESTESS_MARLI,    DATA_MARLI },
    { NPC_VILEBRANCH_SPEAKER, DATA_VILEBRANCH_SPEAKER },
    { NPC_GAHZRANKA,          DATA_GAHZRANKA },
    { NPC_HAKKAR,             DATA_HAKKAR },
    { 0,                      0 } // END
};

ObjectData const gameobjectData[] =
{
    { GO_GONG_OF_BETHEKK, DATA_GONG_BETHEKK },
    { 0,                  0 } // END
};

class instance_zulgurub : public InstanceMapScript
{
    public: instance_zulgurub(): InstanceMapScript(ZGScriptName, 309) { }

        struct instance_zulgurub_InstanceMapScript : public InstanceScript
        {
            instance_zulgurub_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, gameobjectData);
                LoadDoorData(doorData);
            }

            bool IsEncounterInProgress() const override
            {
                // not active in Zul'Gurub
                return false;
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                InstanceScript::OnGameObjectCreate(go);

                switch (go->GetEntry())
                {
                    case GO_GONG_OF_BETHEKK:
                        if (GetBossState(DATA_ARLOKK) == DONE)
                            go->SetFlag(GO_FLAG_NOT_SELECTABLE);
                        else
                            go->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
                        break;
                    default:
                        break;
                }
            }

            void ProcessEvent(WorldObject* /*obj*/, uint32 eventId) override
            {
                if (eventId == EVENT_MUDSKUNK_LURE && GetBossState(DATA_GAHZRANKA) != DONE && !GetCreature(DATA_GAHZRANKA))
                    instance->SummonCreature(NPC_GAHZRANKA, { -11688.5f, -1737.74f, 2.6789f, 3.9f });
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_zulgurub_InstanceMapScript(map);
        }
};

void AddSC_instance_zulgurub()
{
    new instance_zulgurub();
}
