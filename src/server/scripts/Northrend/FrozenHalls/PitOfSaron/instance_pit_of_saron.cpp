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
#include "InstanceScript.h"
#include "Map.h"
#include "pit_of_saron.h"
#include "TemporarySummon.h"

// positions for Martin Victus (37591) and Gorkun Ironskull (37592)
Position const SlaveLeaderPos  = {689.7158f, -104.8736f, 513.7360f, 0.0f};
// position for Jaina and Sylvanas
Position const EventLeaderPos2 = {1054.368f, 107.14620f, 628.4467f, 0.0f};

DoorData const Doors[] =
{
    { GO_ICE_WALL,                       DATA_GARFROST,  EncounterDoorBehavior::OpenWhenDone },
    { GO_ICE_WALL,                       DATA_ICK,       EncounterDoorBehavior::OpenWhenDone },
    { GO_HALLS_OF_REFLECTION_PORTCULLIS, DATA_TYRANNUS,  EncounterDoorBehavior::OpenWhenDone },
    { 0,                                 0,              EncounterDoorBehavior::OpenWhenNotInProgress } // END
};

DungeonEncounterData const encounters[] =
{
    { DATA_GARFROST, {{ 1999 }} },
    { DATA_ICK, {{ 2001 }} },
    { DATA_TYRANNUS, {{ 2000 }} }
};

class instance_pit_of_saron : public InstanceMapScript
{
    public:
        instance_pit_of_saron() : InstanceMapScript(PoSScriptName, 658) { }

        struct instance_pit_of_saron_InstanceScript : public InstanceScript
        {
            instance_pit_of_saron_InstanceScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDoorData(Doors);
                LoadDungeonEncounterData(encounters);
                _cavernActive = 0;
                _shardsHit = 0;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_GARFROST:
                        _garfrostGUID = creature->GetGUID();
                        break;
                    case NPC_KRICK:
                        _krickGUID = creature->GetGUID();
                        break;
                    case NPC_ICK:
                        _ickGUID = creature->GetGUID();
                        break;
                    case NPC_TYRANNUS:
                        _tyrannusGUID = creature->GetGUID();
                        break;
                    case NPC_RIMEFANG:
                        _rimefangGUID = creature->GetGUID();
                        break;
                    case NPC_TYRANNUS_EVENTS:
                        _tyrannusEventGUID = creature->GetGUID();
                        break;
                    case NPC_CAVERN_EVENT_TRIGGER:
                        _cavernstriggersVector.push_back(creature->GetGUID());
                        break;
                    case NPC_SYLVANAS_PART1:
                    case NPC_SYLVANAS_PART2:
                    case NPC_JAINA_PART1:
                    case NPC_JAINA_PART2:
                        _jainaOrSylvanas1GUID = creature->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            uint32 GetCreatureEntry(ObjectGuid::LowType /*guidLow*/, CreatureData const* data) override
            {
                uint32 entry = data->id;
                switch (entry)
                {
                    case NPC_SYLVANAS_PART1:
                        return instance->GetTeamInInstance() == ALLIANCE ? NPC_JAINA_PART1 : NPC_SYLVANAS_PART1;
                    case NPC_SYLVANAS_PART2:
                        return instance->GetTeamInInstance() == ALLIANCE ? NPC_JAINA_PART2 : NPC_SYLVANAS_PART2;
                    case NPC_KILARA:
                        return instance->GetTeamInInstance() == ALLIANCE ? NPC_ELANDRA : NPC_KILARA;
                    case NPC_KORALEN:
                        return instance->GetTeamInInstance() == ALLIANCE ? NPC_KORLAEN : NPC_KORALEN;
                    case NPC_CHAMPION_1_HORDE:
                        return instance->GetTeamInInstance() == ALLIANCE ? NPC_CHAMPION_1_ALLIANCE : NPC_CHAMPION_1_HORDE;
                    case NPC_CHAMPION_2_HORDE:
                        return instance->GetTeamInInstance() == ALLIANCE ? NPC_CHAMPION_2_ALLIANCE : NPC_CHAMPION_2_HORDE;
                    case NPC_CHAMPION_3_HORDE:
                        return instance->GetTeamInInstance() == ALLIANCE ? NPC_CHAMPION_2_ALLIANCE : NPC_CHAMPION_3_HORDE;
                    case NPC_HORDE_SLAVE_1:
                        return instance->GetTeamInInstance() == ALLIANCE ? NPC_ALLIANCE_SLAVE_1 : NPC_HORDE_SLAVE_1;
                    case NPC_HORDE_SLAVE_2:
                        return instance->GetTeamInInstance() == ALLIANCE ? NPC_ALLIANCE_SLAVE_2 : NPC_HORDE_SLAVE_2;
                    case NPC_HORDE_SLAVE_3:
                        return instance->GetTeamInInstance() == ALLIANCE ? NPC_ALLIANCE_SLAVE_3 : NPC_HORDE_SLAVE_3;
                    case NPC_HORDE_SLAVE_4:
                        return instance->GetTeamInInstance() == ALLIANCE ? NPC_ALLIANCE_SLAVE_4 : NPC_HORDE_SLAVE_4;
                    case NPC_FREED_SLAVE_1_HORDE:
                        return instance->GetTeamInInstance() == ALLIANCE ? NPC_FREED_SLAVE_1_ALLIANCE : NPC_FREED_SLAVE_1_HORDE;
                    case NPC_FREED_SLAVE_2_HORDE:
                        return instance->GetTeamInInstance() == ALLIANCE ? NPC_FREED_SLAVE_2_ALLIANCE : NPC_FREED_SLAVE_2_HORDE;
                    case NPC_FREED_SLAVE_3_HORDE:
                        return instance->GetTeamInInstance() == ALLIANCE ? NPC_FREED_SLAVE_3_ALLIANCE : NPC_FREED_SLAVE_3_HORDE;
                    case NPC_RESCUED_SLAVE_HORDE:
                        return instance->GetTeamInInstance() == ALLIANCE ? NPC_RESCUED_SLAVE_ALLIANCE : NPC_RESCUED_SLAVE_HORDE;
                    case NPC_GORKUN_IRONSKULL_1:
                        return instance->GetTeamInInstance() == ALLIANCE ? NPC_MARTIN_VICTUS_1 : NPC_GORKUN_IRONSKULL_1;
                    case NPC_GORKUN_IRONSKULL_2:
                        return instance->GetTeamInInstance() == ALLIANCE ? NPC_MARTIN_VICTUS_2 : NPC_GORKUN_IRONSKULL_2;
                    default:
                        return entry;
                }
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_GARFROST:
                        if (state == DONE)
                        {
                            if (instance->GetCreature(_garfrostGUID))
                            {
                                if (instance->GetTeamInInstance() == ALLIANCE)
                                {
                                    if (TempSummon* summon = instance->SummonCreature(NPC_MARTIN_VICTUS_1, SlaveLeaderPos))
                                        summon->SetTempSummonType(TEMPSUMMON_MANUAL_DESPAWN);
                                }
                                else
                                {
                                    if (TempSummon* summon = instance->SummonCreature(NPC_GORKUN_IRONSKULL_1, SlaveLeaderPos))
                                        summon->SetTempSummonType(TEMPSUMMON_MANUAL_DESPAWN);
                                }
                            }
                        }
                        break;
                    case DATA_TYRANNUS:
                        if (state == DONE)
                        {
                            if (instance->GetCreature(_tyrannusGUID))
                            {
                                if (instance->GetTeamInInstance() == ALLIANCE)
                                {
                                    if (TempSummon * summon = instance->SummonCreature(NPC_JAINA_PART2, EventLeaderPos2))
                                        summon->SetTempSummonType(TEMPSUMMON_MANUAL_DESPAWN);
                                }
                                else
                                {
                                    if (TempSummon * summon = instance->SummonCreature(NPC_SYLVANAS_PART2, EventLeaderPos2))
                                        summon->SetTempSummonType(TEMPSUMMON_MANUAL_DESPAWN);
                                }
                            }
                        }
                        break;
                    default:
                        break;
                }

                return true;
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_TEAM_IN_INSTANCE:
                        return instance->GetTeamInInstance();
                    case DATA_ICE_SHARDS_HIT:
                        return _shardsHit;
                    case DATA_CAVERN_ACTIVE:
                        return _cavernActive;
                    default:
                        break;
                }

                return 0;
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_ICE_SHARDS_HIT:
                        _shardsHit = data;
                        break;
                    case DATA_CAVERN_ACTIVE:
                        if (data)
                        {
                            _cavernActive = data;
                            HandleCavernEventTrigger(true);
                        }
                        else
                            HandleCavernEventTrigger(false);
                        break;
                    default:
                        break;
                }
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_GARFROST:
                        return _garfrostGUID;
                    case DATA_KRICK:
                        return _krickGUID;
                    case DATA_ICK:
                        return _ickGUID;
                    case DATA_TYRANNUS:
                        return _tyrannusGUID;
                    case DATA_RIMEFANG:
                        return _rimefangGUID;
                    case DATA_TYRANNUS_EVENT:
                        return _tyrannusEventGUID;
                    case DATA_JAINA_SYLVANAS_1:
                        return _jainaOrSylvanas1GUID;
                    case DATA_JAINA_SYLVANAS_2:
                        return _jainaOrSylvanas2GUID;
                    default:
                        break;
                }

                return ObjectGuid::Empty;
            }

            void HandleCavernEventTrigger(bool activate)
            {
                for (ObjectGuid guid : _cavernstriggersVector)
                    if (Creature* trigger = instance->GetCreature(guid))
                    {
                        if (activate)
                            trigger->m_Events.AddEvent(new ScheduledIcicleSummons(trigger), trigger->m_Events.CalculateTime(1s));
                        else
                            trigger->m_Events.KillAllEvents(false);
                    }
            }

        private:
            ObjectGuid _garfrostGUID;
            ObjectGuid _krickGUID;
            ObjectGuid _ickGUID;
            ObjectGuid _tyrannusGUID;
            ObjectGuid _rimefangGUID;

            ObjectGuid _tyrannusEventGUID;
            ObjectGuid _jainaOrSylvanas1GUID;
            ObjectGuid _jainaOrSylvanas2GUID;
            GuidVector _cavernstriggersVector;

            uint8 _shardsHit;
            uint8 _cavernActive;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_pit_of_saron_InstanceScript(map);
        }
};

void AddSC_instance_pit_of_saron()
{
    new instance_pit_of_saron();
}
