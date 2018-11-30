/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "blackwing_lair.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "TemporarySummon.h"

DoorData const doorData[] =
{
    { GO_PORTCULLIS,             DATA_RAZORGORE_THE_UNTAMED,  DOOR_TYPE_PASSAGE },
    { GO_DRAKE_RIDER_PORTCULLIS, DATA_VAELASTRAZ_THE_CORRUPT, DOOR_TYPE_PASSAGE },
    { GO_ALTERAC_VALLEY_GATE,    DATA_BROODLORD_LASHLAYER,    DOOR_TYPE_PASSAGE },
    { GO_GATE,                   DATA_FIREMAW,                DOOR_TYPE_PASSAGE },
    { GO_GATE,                   DATA_EBONROC,                DOOR_TYPE_PASSAGE },
    { GO_GATE,                   DATA_FLAMEGOR,               DOOR_TYPE_PASSAGE },
    { GO_VACCUUM_EXIT_GATE,      DATA_CHROMAGGUS,             DOOR_TYPE_PASSAGE },
    { 0,                         0,                           DOOR_TYPE_ROOM } // END
};

ObjectData const creatureData[] =
{
    { NPC_RAZORGORE,       DATA_RAZORGORE_THE_UNTAMED  },
    { NPC_VAELASTRAZ,      DATA_VAELASTRAZ_THE_CORRUPT },
    { NPC_BROODLORD,       DATA_BROODLORD_LASHLAYER    },
    { NPC_FIREMAW,         DATA_FIREMAW                },
    { NPC_EBONROC,         DATA_EBONROC                },
    { NPC_FLAMEGOR,        DATA_FLAMEGOR               },
    { NPC_CHROMAGGUS,      DATA_CHROMAGGUS             },
    { NPC_NEFARIAN,        DATA_NEFARIAN               },
    { NPC_VICTOR_NEFARIUS, DATA_LORD_VICTOR_NEFARIUS   },
    { 0,                   0                           } // END
};

Position const SummonPosition[8] =
{
    {-7661.207520f, -1043.268188f, 407.199554f, 6.280452f},
    {-7644.145020f, -1065.628052f, 407.204956f, 0.501492f},
    {-7624.260742f, -1095.196899f, 407.205017f, 0.544694f},
    {-7608.501953f, -1116.077271f, 407.199921f, 0.816443f},
    {-7531.841797f, -1063.765381f, 407.199615f, 2.874187f},
    {-7547.319336f, -1040.971924f, 407.205078f, 3.789175f},
    {-7568.547852f, -1013.112488f, 407.204926f, 3.773467f},
    {-7584.175781f, -989.6691289f, 407.199585f, 4.527447f},
};

uint32 const Entry[5] = {12422, 12458, 12416, 12420, 12459};

class instance_blackwing_lair : public InstanceMapScript
{
public:
    instance_blackwing_lair() : InstanceMapScript(BWLScriptName, 469) { }

    struct instance_blackwing_lair_InstanceMapScript : public InstanceScript
    {
        instance_blackwing_lair_InstanceMapScript(Map* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadDoorData(doorData);
            LoadObjectData(creatureData, nullptr);

            // Razorgore
            EggCount = 0;
            EggEvent = 0;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            InstanceScript::OnCreatureCreate(creature);

            switch (creature->GetEntry())
            {
                case NPC_BLACKWING_DRAGON:
                case NPC_BLACKWING_TASKMASTER:
                case NPC_BLACKWING_LEGIONAIRE:
                case NPC_BLACKWING_WARLOCK:
                    if (Creature* razor = GetCreature(DATA_RAZORGORE_THE_UNTAMED))
                        razor->AI()->JustSummoned(creature);
                    break;
                default:
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            InstanceScript::OnGameObjectCreate(go);

            if (go->GetEntry() == GO_BLACK_DRAGON_EGG)
            {
                if (GetBossState(DATA_FIREMAW) == DONE)
                    go->SetPhaseMask(2, true);
                else
                    EggList.push_back(go->GetGUID());
            }
        }

        void OnGameObjectRemove(GameObject* go) override
        {
            InstanceScript::OnGameObjectRemove(go);

            if (go->GetEntry() == GO_BLACK_DRAGON_EGG)
                EggList.remove(go->GetGUID());
        }

        bool CheckRequiredBosses(uint32 bossId, Player const* player /*= nullptr*/) const override
        {
            if (_SkipCheckRequiredBosses(player))
                return true;

            switch (bossId)
            {
                case DATA_BROODLORD_LASHLAYER:
                    if (GetBossState(DATA_VAELASTRAZ_THE_CORRUPT) != DONE)
                        return false;
                    break;
                case DATA_FIREMAW:
                case DATA_EBONROC:
                case DATA_FLAMEGOR:
                    if (GetBossState(DATA_BROODLORD_LASHLAYER) != DONE)
                        return false;
                    break;
                case DATA_CHROMAGGUS:
                    if (GetBossState(DATA_FIREMAW) != DONE
                        || GetBossState(DATA_EBONROC) != DONE
                        || GetBossState(DATA_FLAMEGOR) != DONE)
                        return false;
                    break;
                default:
                    break;
            }

            return true;
        }

        bool SetBossState(uint32 type, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            switch (type)
            {
                case DATA_RAZORGORE_THE_UNTAMED:
                    if (state == DONE)
                    {
                        for (GuidList::const_iterator itr = EggList.begin(); itr != EggList.end(); ++itr)
                            if (GameObject* egg = instance->GetGameObject(*itr))
                                egg->SetPhaseMask(2, true);
                    }
                    SetData(DATA_EGG_EVENT, NOT_STARTED);
                    break;
                case DATA_NEFARIAN:
                    switch (state)
                    {
                        case NOT_STARTED:
                            if (Creature* nefarian = GetCreature(DATA_NEFARIAN))
                                nefarian->DespawnOrUnsummon();
                            break;
                        case FAIL:
                            _events.ScheduleEvent(EVENT_RESPAWN_NEFARIUS, 15 * IN_MILLISECONDS * MINUTE);
                            SetBossState(DATA_NEFARIAN, NOT_STARTED);
                            break;
                        default:
                            break;
                    }
                    break;
            }
            return true;
        }

        void SetData(uint32 type, uint32 data) override
        {
            if (type == DATA_EGG_EVENT)
            {
                switch (data)
                {
                    case IN_PROGRESS:
                        _events.ScheduleEvent(EVENT_RAZOR_SPAWN, 45s);
                        EggEvent = data;
                        EggCount = 0;
                        break;
                    case NOT_STARTED:
                        _events.CancelEvent(EVENT_RAZOR_SPAWN);
                        EggEvent = data;
                        EggCount = 0;
                        break;
                    case SPECIAL:
                        if (++EggCount == 15)
                        {
                            if (Creature* razor = GetCreature(DATA_RAZORGORE_THE_UNTAMED))
                            {
                                SetData(DATA_EGG_EVENT, DONE);
                                razor->RemoveAurasDueToSpell(42013); // MindControl
                                DoRemoveAurasDueToSpellOnPlayers(42013);
                            }
                            _events.ScheduleEvent(EVENT_RAZOR_PHASE_TWO, 1s);
                            _events.CancelEvent(EVENT_RAZOR_SPAWN);
                        }
                        if (EggEvent == NOT_STARTED)
                            SetData(DATA_EGG_EVENT, IN_PROGRESS);
                        break;
                }
            }
        }

        void OnUnitDeath(Unit* unit) override
        {
            //! HACK, needed because of buggy CreatureAI after charm
            if (unit->GetEntry() == NPC_RAZORGORE && GetBossState(DATA_RAZORGORE_THE_UNTAMED) != DONE)
                SetBossState(DATA_RAZORGORE_THE_UNTAMED, DONE);
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
                    case EVENT_RAZOR_SPAWN:
                        for (uint8 i = urand(2, 5); i > 0; --i)
                            if (Creature* summon = instance->SummonCreature(Entry[urand(0, 4)], SummonPosition[urand(0, 7)]))
                                summon->AI()->DoZoneInCombat();
                        _events.ScheduleEvent(EVENT_RAZOR_SPAWN, 12s, 17s);
                        break;
                    case EVENT_RAZOR_PHASE_TWO:
                        _events.CancelEvent(EVENT_RAZOR_SPAWN);
                        if (Creature* razor = GetCreature(DATA_RAZORGORE_THE_UNTAMED))
                            razor->AI()->DoAction(ACTION_PHASE_TWO);
                        break;
                    case EVENT_RESPAWN_NEFARIUS:
                        if (Creature* nefarius = GetCreature(DATA_LORD_VICTOR_NEFARIUS))
                        {
                            nefarius->SetPhaseMask(1, true);
                            nefarius->setActive(true);
                            nefarius->SetFarVisible(true);
                            nefarius->Respawn();
                            nefarius->GetMotionMaster()->MoveTargetedHome();
                        }
                        break;
                }
            }
        }

    protected:
        // Misc
        EventMap _events;

        // Razorgore
        uint8 EggCount;
        uint32 EggEvent;
        GuidList EggList;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_blackwing_lair_InstanceMapScript(map);
    }
};

void AddSC_instance_blackwing_lair()
{
    new instance_blackwing_lair();
}
