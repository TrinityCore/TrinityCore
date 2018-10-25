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
#include "Containers.h"
#include "CreatureAI.h"
#include "EventMap.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "throne_of_the_four_winds.h"
#include "AreaBoundary.h"
#include "Map.h"
#include "TemporarySummon.h"
#include "Vehicle.h"
#include "Weather.h"

ObjectData const creatureData[] =
{
    { BOSS_ANSHAL,  DATA_ANSHAL },
    { BOSS_NEZIR,   DATA_NEZIR  },
    { BOSS_ROHASH,  DATA_ROHASH },
    { BOSS_ALAKIR,  DATA_ALAKIR },
    { 0,            0           } // End
};

ObjectData const gameObjectData[] =
{
    { GO_SKYWALL_RAID_CENTER_PLATFORM,  DATA_SKYWALL_RAID_CENTER_PLATFORM   },
    { GO_SKYALL_DJIN_HEALING,           DATA_SKYWALL_DJIN_HEALING           },
    { GO_SKYALL_DJIN_FROST,             DATA_SKYWALL_DJIN_FROST             },
    { GO_SKYALL_DJIN_TORNADO,           DATA_SKYWALL_DJIN_TORNADO           },
    { 0,                                0                                   } // End
};

enum Events
{
    EVENT_ENERGIZE = 1,
    EVENT_ANNOUNCE_ALMOST_FULL_STRENGTH,
    EVENT_CONCLAVE_AT_FULL_STRENGTH,
};

Position const EnergizeWorldTriggerPos = { -287.795f, 816.681f, 199.5723f };

class instance_throne_of_the_four_winds : public InstanceMapScript
{
    public:
        instance_throne_of_the_four_winds() : InstanceMapScript(TotFWScriptName, 754) { }

        struct instance_throne_of_the_four_winds_InstanceMapScript : public InstanceScript
        {
            instance_throne_of_the_four_winds_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, gameObjectData);
                Initialize();
            }

            void Initialize()
            {
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                creature->setActive(true);
                creature->SetFarVisible(true);

                switch (creature->GetEntry())
                {

                    case BOSS_ALAKIR:
                        if (GetBossState(DATA_CONCLAVE_OF_WIND) != DONE)
                            creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                        break;
                    case NPC_RAVENOUS_CREEPER:
                        if (Creature* anshal = GetCreature(DATA_ANSHAL))
                            anshal->AI()->JustSummoned(creature);
                        break;
                    case NPC_WORLD_TRIGGER:
                        if (creature->GetExactDist2d(EnergizeWorldTriggerPos) < 0.1f)
                            _engerizeWorldTriggerGUID = creature->GetGUID();
                        break;
                    case NPC_HURRICANE:
                        _hurricaneGUIDs.push_back(creature->GetGUID());
                        break;
                    case NPC_LIGHTNING_STRIKE_TRIGGER_HEROIC_CHAIN_CASTER:
                    case NPC_ICE_STORM:
                        if (Creature* alakir = GetCreature(DATA_ALAKIR))
                            alakir->AI()->JustSummoned(creature);
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                InstanceScript::OnGameObjectCreate(go);

                go->setActive(true);
                go->SetFarVisible(true);
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_CONCLAVE_OF_WIND:
                        if (state == IN_PROGRESS)
                        {
                            if (Creature* anshal = GetCreature(DATA_ANSHAL))
                                anshal->AI()->DoZoneInCombat();

                            if (Creature* nezir = GetCreature(DATA_NEZIR))
                                nezir->AI()->DoZoneInCombat();

                            if (Creature* rohash = GetCreature(DATA_ROHASH))
                                rohash->AI()->DoZoneInCombat();

                            events.ScheduleEvent(EVENT_ENERGIZE, 1ms);
                            events.ScheduleEvent(EVENT_ANNOUNCE_ALMOST_FULL_STRENGTH, 80s);
                            events.ScheduleEvent(EVENT_CONCLAVE_AT_FULL_STRENGTH, 90s);
                        }
                        else
                        {
                            if (GameObject* effect1 = GetGameObject(DATA_SKYWALL_DJIN_TORNADO))
                                effect1->SetGoState(GO_STATE_READY);
                            if (GameObject* effect2 = GetGameObject(DATA_SKYWALL_DJIN_FROST))
                                effect2->SetGoState(GO_STATE_READY);
                            if (GameObject* effect3 = GetGameObject(DATA_SKYWALL_DJIN_HEALING))
                                effect3->SetGoState(GO_STATE_READY);

                            events.CancelEvent(EVENT_ENERGIZE);
                            events.CancelEvent(EVENT_ANNOUNCE_ALMOST_FULL_STRENGTH);
                            events.CancelEvent(EVENT_CONCLAVE_AT_FULL_STRENGTH);

                            for (ObjectGuid guid : _hurricaneGUIDs)
                            {
                                if (Creature* hurricane = instance->GetCreature(guid))
                                    hurricane->DespawnOrUnsummon(0, 30s);
                            }

                            _hurricaneGUIDs.clear();

                            if (state == DONE)
                            {
                                if (Creature* alakir = GetCreature(DATA_ALAKIR))
                                {
                                    alakir->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                                    alakir->AI()->DoAction(ACTION_CONCLAVE_DEFEATED);
                                }
                            }
                        }
                        break;
                    default:
                        break;
                }

                return true;
            }

            void SetData(uint32 data, uint32 value) override
            {
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_FREE_HURRICANE_VEHICLE:
                        for (ObjectGuid guid : _hurricaneGUIDs)
                        {
                            if (Creature* hurricane = instance->GetCreature(guid))
                                if (hurricane->GetVehicleKit()->GetAvailableSeatCount())
                                    return guid;
                        }
                        break;
                    default:
                        break;
                }

                return ObjectGuid::Empty;
            }

            void Update(uint32 diff) override
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ENERGIZE:
                            if (Creature* trigger = instance->GetCreature(_engerizeWorldTriggerGUID))
                                trigger->CastSpell(trigger, SPELL_POWER_GAIN, true);
                            events.Repeat(1s);
                            break;
                        case EVENT_ANNOUNCE_ALMOST_FULL_STRENGTH:
                            if (Creature* trigger = instance->GetCreature(_engerizeWorldTriggerGUID))
                                if (trigger->IsAIEnabled)
                                    trigger->AI()->Talk(SAY_ANNOUNCE_ALMOST_FULL_STRENGTH);
                            break;
                        case EVENT_CONCLAVE_AT_FULL_STRENGTH:
                            if (Creature* anshal = GetCreature(DATA_ANSHAL))
                                anshal->AI()->DoAction(ACTION_CONCLAVE_AT_FULL_STRENGTH);

                            if (Creature* nezir = GetCreature(DATA_NEZIR))
                                nezir->AI()->DoAction(ACTION_CONCLAVE_AT_FULL_STRENGTH);

                            if (Creature* rohash = GetCreature(DATA_ROHASH))
                                rohash->AI()->DoAction(ACTION_CONCLAVE_AT_FULL_STRENGTH);

                            if (Creature* trigger = instance->GetCreature(_engerizeWorldTriggerGUID))
                                trigger->CastSpell(trigger, SPELL_POWER_GAIN, true);

                            events.RescheduleEvent(EVENT_ENERGIZE, 23s + 500ms);
                            events.ScheduleEvent(EVENT_ANNOUNCE_ALMOST_FULL_STRENGTH, 1min + 43s + 500ms);
                            events.Repeat(1min + 53s + 500ms);
                            break;
                        default:
                            break;
                    }
                }
            }

            void ReadSaveDataMore(std::istringstream& /*data*/) override
            {
            }

        protected:
            EventMap events;
            ObjectGuid _engerizeWorldTriggerGUID;
            GuidVector _hurricaneGUIDs;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_throne_of_the_four_winds_InstanceMapScript(map);
        }
};

void AddSC_instance_throne_of_the_four_winds()
{
    new instance_throne_of_the_four_winds();
}
