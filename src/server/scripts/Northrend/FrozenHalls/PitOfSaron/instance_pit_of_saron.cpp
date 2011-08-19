/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "pit_of_saron.h"

// positions for Martin Victus (37591) and Gorkun Ironskull (37592)
Position const SlaveLeaderPos  = {689.7158f, -104.8736f, 513.7360f, 0.0f};
// position for Jaina and Sylvanas
Position const EventLeaderPos2 = {1054.368f, 107.14620f, 628.4467f, 0.0f};

class instance_pit_of_saron : public InstanceMapScript
{
    public:
        instance_pit_of_saron() : InstanceMapScript(PoSScriptName, 658) { }

        struct instance_pit_of_saron_InstanceScript : public InstanceScript
        {
            instance_pit_of_saron_InstanceScript(Map* map) : InstanceScript(map)
            {
                SetBossNumber(MAX_ENCOUNTER);
                _garfrostGUID = 0;
                _krickGUID = 0;
                _ickGUID = 0;
                _tyrannusGUID = 0;
                _rimefangGUID = 0;
                _jainaOrSylvanas1GUID = 0;
                _jainaOrSylvanas2GUID = 0;
                _teamInInstance = 0;
            }

            void OnPlayerEnter(Player* player)
            {
                if (!_teamInInstance)
                    _teamInInstance = player->GetTeam();
            }

            void OnCreatureCreate(Creature* creature)
            {
                if (!_teamInInstance)
                {
                    Map::PlayerList const &players = instance->GetPlayers();
                    if (!players.isEmpty())
                        if (Player* player = players.begin()->getSource())
                            _teamInInstance = player->GetTeam();
                }

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
                    case NPC_SYLVANAS_PART1:
                        if (_teamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_JAINA_PART1, ALLIANCE);
                        _jainaOrSylvanas1GUID = creature->GetGUID();
                        break;
                    case NPC_SYLVANAS_PART2:
                        if (_teamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_JAINA_PART2, ALLIANCE);
                        _jainaOrSylvanas2GUID = creature->GetGUID();
                        break;
                    case NPC_KILARA:
                        if (_teamInInstance == ALLIANCE)
                           creature->UpdateEntry(NPC_ELANDRA, ALLIANCE);
                        break;
                    case NPC_KORALEN:
                        if (_teamInInstance == ALLIANCE)
                           creature->UpdateEntry(NPC_KORLAEN, ALLIANCE);
                        break;
                    case NPC_CHAMPION_1_HORDE:
                        if (_teamInInstance == ALLIANCE)
                           creature->UpdateEntry(NPC_CHAMPION_1_ALLIANCE, ALLIANCE);
                        break;
                    case NPC_CHAMPION_2_HORDE:
                        if (_teamInInstance == ALLIANCE)
                           creature->UpdateEntry(NPC_CHAMPION_2_ALLIANCE, ALLIANCE);
                        break;
                    case NPC_CHAMPION_3_HORDE: // No 3rd set for Alliance?
                        if (_teamInInstance == ALLIANCE)
                           creature->UpdateEntry(NPC_CHAMPION_2_ALLIANCE, ALLIANCE);
                        break;
                    case NPC_HORDE_SLAVE_1:
                        if (_teamInInstance == ALLIANCE)
                           creature->UpdateEntry(NPC_ALLIANCE_SLAVE_1, ALLIANCE);
                        break;
                    case NPC_HORDE_SLAVE_2:
                        if (_teamInInstance == ALLIANCE)
                           creature->UpdateEntry(NPC_ALLIANCE_SLAVE_2, ALLIANCE);
                        break;
                    case NPC_HORDE_SLAVE_3:
                        if (_teamInInstance == ALLIANCE)
                           creature->UpdateEntry(NPC_ALLIANCE_SLAVE_3, ALLIANCE);
                        break;
                    case NPC_HORDE_SLAVE_4:
                        if (_teamInInstance == ALLIANCE)
                           creature->UpdateEntry(NPC_ALLIANCE_SLAVE_4, ALLIANCE);
                        break;
                    case NPC_FREED_SLAVE_1_HORDE:
                        if (_teamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_FREED_SLAVE_1_ALLIANCE, ALLIANCE);
                        break;
                    case NPC_FREED_SLAVE_2_HORDE:
                        if (_teamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_FREED_SLAVE_2_ALLIANCE, ALLIANCE);
                        break;
                    case NPC_FREED_SLAVE_3_HORDE:
                        if (_teamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_FREED_SLAVE_3_ALLIANCE, ALLIANCE);
                        break;
                    case NPC_RESCUED_SLAVE_HORDE:
                        if (_teamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_RESCUED_SLAVE_ALLIANCE, ALLIANCE);
                        break;
                    case NPC_MARTIN_VICTUS_1:
                        if (_teamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_MARTIN_VICTUS_1, ALLIANCE);
                        break;
                    case NPC_MARTIN_VICTUS_2:
                        if (_teamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_MARTIN_VICTUS_2, ALLIANCE);
                        break;
                    default:
                        break;
                }
            }

            bool SetBossState(uint32 type, EncounterState state)
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_GARFROST:
                        if(state == DONE)
                        {
                            if (Creature* summoner = instance->GetCreature(_garfrostGUID))
                            {
                                if (_teamInInstance == ALLIANCE)
                                    summoner->SummonCreature(NPC_MARTIN_VICTUS_1, SlaveLeaderPos, TEMPSUMMON_MANUAL_DESPAWN);
                                else
                                    summoner->SummonCreature(NPC_GORKUN_IRONSKULL_2, SlaveLeaderPos, TEMPSUMMON_MANUAL_DESPAWN);
                            }
                        }
                        break;
                    case DATA_TYRANNUS:
                        if (state == DONE)
                        {
                            if (Creature* summoner = instance->GetCreature(_tyrannusGUID))
                            {
                                if (_teamInInstance == ALLIANCE)
                                    summoner->SummonCreature(NPC_JAINA_PART2, EventLeaderPos2, TEMPSUMMON_MANUAL_DESPAWN);
                                else
                                    summoner->SummonCreature(NPC_SYLVANAS_PART2, EventLeaderPos2, TEMPSUMMON_MANUAL_DESPAWN);
                            }
                        }
                        break;
                    default:
                        break;
                }

                return true;
            }

            uint32 GetData(uint32 type)
            {
                switch (type)
                {
                    case DATA_TEAM_IN_INSTANCE:
                        return _teamInInstance;
                    default:
                        break;
                }

                return 0;
            }

            uint64 GetData64(uint32 type)
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

                return 0;
            }

            std::string GetSaveData()
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "P S " << GetBossSaveData();

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(const char* in)
            {
                if (!in)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(in);

                char dataHead1, dataHead2;

                std::istringstream loadStream(in);
                loadStream >> dataHead1 >> dataHead2;

                if (dataHead1 == 'P' && dataHead2 == 'S')
                {
                    for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
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

        private:
            uint64 _garfrostGUID;
            uint64 _krickGUID;
            uint64 _ickGUID;
            uint64 _tyrannusGUID;
            uint64 _rimefangGUID;

            uint64 _tyrannusEventGUID;
            uint64 _jainaOrSylvanas1GUID;
            uint64 _jainaOrSylvanas2GUID;

            uint32 _teamInInstance;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_pit_of_saron_InstanceScript(map);
        }
};

void AddSC_instance_pit_of_saron()
{
    new instance_pit_of_saron();
}
