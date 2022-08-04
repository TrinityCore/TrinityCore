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

#include "scarlet_monastery.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "EventMap.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ScriptMgr.h"
#include "TemporarySummon.h"

Position const BunnySpawnPosition = { 1776.27f, 1348.74f, 19.20f };
Position const EarthBunnySpawnPosition = { 1765.28f, 1347.46f, 18.55f, 6.17f };
Position const HeadlessHorsemanSpawnPosition = { 1765.00f, 1347.00f, 15.00f };
Position const HeadlessHorsemanHeadSpawnPosition = { 1788.54f, 1348.05f, 18.88f }; // Guessed

ObjectData const creatureData[] =
{
    { NPC_HEADLESS_HORSEMAN_HEAD, DATA_HORSEMAN_HEAD     },
    { NPC_HEADLESS_HORSEMAN,      DATA_HEADLESS_HORSEMAN },
    { NPC_FLAME_BUNNY,            DATA_FLAME_BUNNY       },
    { NPC_EARTH_BUNNY,            DATA_EARTH_BUNNY       },
    { NPC_SIR_THOMAS,             DATA_THOMAS            },
    { NPC_MOGRAINE,               DATA_MOGRAINE          },
    { NPC_VORREL,                 DATA_VORREL            },
    { NPC_WHITEMANE,              DATA_WHITEMANE         },
    { 0,                          0                      } // END
};

ObjectData const gameObjectData[] =
{
    { GO_PUMPKIN_SHRINE,        DATA_PUMPKIN_SHRINE        },
    { GO_HIGH_INQUISITORS_DOOR, DATA_HIGH_INQUISITORS_DOOR },
    { GO_LOOSELY_TURNED_SOIL,   DATA_LOOSELY_TURNED_SOIL   },
    { 0,                        0                          } // END
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
                _horsemanState = NOT_STARTED;
            }

            void HandleStartEvent()
            {
                _horsemanState = IN_PROGRESS;
                for (uint32 data : {DATA_PUMPKIN_SHRINE, DATA_LOOSELY_TURNED_SOIL})
                    if (GameObject* gob = GetGameObject(data))
                        gob->SetFlag(GO_FLAG_NOT_SELECTABLE);

                instance->SummonCreature(NPC_HEADLESS_HORSEMAN_HEAD, HeadlessHorsemanHeadSpawnPosition);
                instance->SummonCreature(NPC_FLAME_BUNNY, BunnySpawnPosition);
                instance->SummonCreature(NPC_EARTH_BUNNY, EarthBunnySpawnPosition);
                _events.ScheduleEvent(EVENT_ACTIVE_EARTH_EXPLOSION, 1s + 500ms);
                _events.ScheduleEvent(EVENT_SPAWN_HEADLESS_HORSEMAN, 3s);
                _events.ScheduleEvent(EVENT_DESPAWN_OBJECTS, 10s);
                if (Creature* thomas = GetCreature(DATA_THOMAS))
                    thomas->DespawnOrUnsummon();
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_START_HORSEMAN_EVENT:
                        if (_horsemanState != IN_PROGRESS)
                            HandleStartEvent();
                        break;
                    case DATA_HORSEMAN_EVENT_STATE:
                        _horsemanState = data;
                        break;
                    case DATA_PREPARE_RESET:
                        _horsemanState = NOT_STARTED;
                        for (uint32 data : {DATA_FLAME_BUNNY, DATA_EARTH_BUNNY})
                            if (Creature* bunny = GetCreature(data))
                                bunny->DespawnOrUnsummon();
                        break;
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_HORSEMAN_EVENT_STATE:
                        return _horsemanState;
                    default:
                        return 0;
                }
            }

            void Update(uint32 diff) override
            {
                if (_events.Empty())
                    return;

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ACTIVE_EARTH_EXPLOSION:
                            if (Creature* earthBunny = GetCreature(DATA_EARTH_BUNNY))
                                earthBunny->CastSpell(earthBunny, SPELL_EARTH_EXPLOSION);
                            break;
                        case EVENT_SPAWN_HEADLESS_HORSEMAN:
                            if (TempSummon* horseman = instance->SummonCreature(NPC_HEADLESS_HORSEMAN, HeadlessHorsemanSpawnPosition))
                                horseman->AI()->DoAction(ACTION_HORSEMAN_EVENT_START);
                            break;
                        case EVENT_DESPAWN_OBJECTS:
                            for (uint32 data : {DATA_PUMPKIN_SHRINE, DATA_LOOSELY_TURNED_SOIL})
                                if (GameObject* gob = GetGameObject(data))
                                    gob->RemoveFromWorld();
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            EventMap _events;
            uint32 _horsemanState;
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
