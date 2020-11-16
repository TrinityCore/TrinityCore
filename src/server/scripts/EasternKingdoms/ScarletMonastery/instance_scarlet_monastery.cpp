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
#include "EventMap.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "scarlet_monastery.h"

ObjectData const creatureData[] =
{
    { BOSS_INTERROGATOR_VISHAS,         DATA_INTERROGATOR_VISHAS        },
    { BOSS_BLOODMAGE_THALNOS,           DATA_BLOODMAGE_THALNOS          },
    { BOSS_HOUNDMASTER_LOKSEY,          DATA_HOUNDMASTER_LOKSEY         },
    { BOSS_ARCANIST_DOAN,               DATA_ARCANIST_DOAN              },
    { BOSS_HIGH_INQUISITOR_WHITEMANE,   DATA_HIGH_INQUISITOR_WHITEMANE  },
    { BOSS_SCARLET_COMMANDER_MOGRAINE,  DATA_SCARLET_COMMANDER_MOGRAINE },
    { 0,                                0                               } // END
};

ObjectData const gameObjectData[] =
{
    { GO_HIGH_INQUISITORS_DOOR,     DATA_HIGH_INQUISITORS_DOOR  },
    { 0,                            0                           } // END
};

enum SpawnGroups
{
    SPAWN_GROUP_ID_WHITEMANE_AND_MOGRAINE = 451
};

enum Events
{
    EVENT_RESPAWN_MOGRAINE_AND_WHITEMANE = 1
};

class instance_scarlet_monastery : public InstanceMapScript
{
    public:
        instance_scarlet_monastery() : InstanceMapScript(SMScriptName, 189) { }

        struct instance_scarlet_monastery_InstanceMapScript : public InstanceScript
        {
            instance_scarlet_monastery_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, gameObjectData);
            }

            void Create() override
            {
                InstanceScript::Create();
                instance->SpawnGroupSpawn(SPAWN_GROUP_ID_WHITEMANE_AND_MOGRAINE, true);
            }

            void Load(char const* data) override
            {
                InstanceScript::Load(data);
                if (GetBossState(DATA_MOGRAINE_AND_WHITEMANE) != DONE)
                    instance->SpawnGroupSpawn(SPAWN_GROUP_ID_WHITEMANE_AND_MOGRAINE, true, true);
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                InstanceScript::OnGameObjectCreate(go);

                switch (go->GetEntry())
                {
                    case GO_PUMPKIN_SHRINE:
                        PumpkinShrineGUID = go->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                switch (creature->GetEntry())
                {
                    case NPC_HORSEMAN:
                        HorsemanGUID = creature->GetGUID();
                        break;
                    case NPC_HEAD:
                        HeadGUID = creature->GetGUID();
                        break;
                    case NPC_PUMPKIN:
                        HorsemanAdds.insert(creature->GetGUID());
                        break;
                    case NPC_VORREL:
                        VorrelGUID = creature->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void SetData(uint32 type, uint32 /*data*/) override
            {
                switch (type)
                {
                    case DATA_PUMPKIN_SHRINE:
                        HandleGameObject(PumpkinShrineGUID, false);
                        break;
                    default:
                        break;
                }
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_HORSEMAN_EVENT:
                        if (state == DONE)
                        {
                            for (ObjectGuid guid : HorsemanAdds)
                            {
                                Creature* add = instance->GetCreature(guid);
                                if (add && add->IsAlive())
                                    add->KillSelf();
                            }
                            HorsemanAdds.clear();
                            HandleGameObject(PumpkinShrineGUID, false);
                        }
                        break;
                    case DATA_MOGRAINE_AND_WHITEMANE:
                        if (state == FAIL)
                        {
                            instance->SpawnGroupDespawn(SPAWN_GROUP_ID_WHITEMANE_AND_MOGRAINE);
                            _events.ScheduleEvent(EVENT_RESPAWN_MOGRAINE_AND_WHITEMANE, 30s);

                            if (GameObject* door = GetGameObject(DATA_HIGH_INQUISITORS_DOOR))
                                door->ResetDoorOrButton();
                        }
                        break;
                    default:
                        break;
                }
                return true;
            }

            void Update(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_RESPAWN_MOGRAINE_AND_WHITEMANE:
                            instance->SpawnGroupSpawn(SPAWN_GROUP_ID_WHITEMANE_AND_MOGRAINE);
                            break;
                        default:
                            break;
                    }
                }
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_VORREL:
                        return VorrelGUID;
                    default:
                        break;
                }
                return ObjectGuid::Empty;
            }

        private:
            EventMap _events;

            ObjectGuid PumpkinShrineGUID;
            ObjectGuid HorsemanGUID;
            ObjectGuid HeadGUID;
            ObjectGuid VorrelGUID;
            GuidSet HorsemanAdds;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_scarlet_monastery_InstanceMapScript(map);
        }
};

void AddSC_instance_scarlet_monastery()
{
    new instance_scarlet_monastery();
}
