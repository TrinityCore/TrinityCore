/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

// position for Jaina and Sylvanas
Position const EventLeaderPos2 = {1054.368f, 107.14620f, 628.4467f, 0.0f};
//Slaves For Alliance and Horde. Martin Victus and Gorkun Ironskull 
const uint32 NpcSlaveAlliance[3] = {37591, 37572, 37575 };
const uint32 NpcSlaveHorde[3] = {37592, 37578, 37579};
const uint32 NpcSlaveIfDeadGarfrost[2] = {36888, 36889};
//Dead Garfrost from sniff
static const Position SlaveLeaderPos[3] =
{
    {693.281555f, -169.690872f, 526.965454f, 1.485173f}, 
    {696.024902f, -169.953308f, 526.870850f, 1.603771f}, 
    {690.887512f, -169.970963f, 526.891357f, 1.269191f},
};
// if Dead IckandKrick from sniff
static const Position SlaveLeaderPos2[3] =
{
    {849.804016f, -9.097073f, 509.900574f, 2.183652f},
    {851.979919f, -7.567026f, 509.982391f, 2.040709f}, 
    {847.959351f, -11.114618f, 509.794922f, 2.366650f},
};
// Slaves Alliance and Horde If Gargrost Dead For Events  from sniff
const Position spawnPoints1[3] =
{
    {768.920044f, -38.462135f, 508.355469f, 3.903403f},
    {766.413635f, -36.130611f, 508.346466f, 4.056557f},
    {770.746033f, -40.480698f, 508.355469f, 3.915185f},
};
Position const spawnPoints2 = {773.266174f, -43.121738f, 508.355469f, 3.954455f};

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
                _sindragosaGUID = 0;
                _teamInInstance = 0;
                _uiHorp =0;
                _victusOrGorkunFreedGUID = 0;
                _tyrannusEventStart = NOT_STARTED;
                _areaTriggerYmirjar = NOT_STARTED;
                _areaTriggerFallen  = NOT_STARTED;
                _areaTriggerIceCicle = NOT_STARTED;
                _areaTriggerSlaveOutroFargrost = NOT_STARTED;
                _areTriggerGeistAmbusher = NOT_STARTED;
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
                    case NPC_GORKUN_IRONSKULL_1:
                        if (_teamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_MARTIN_VICTUS_2, ALLIANCE);
                          _victusOrGorkunFreedGUID = creature->GetGUID();
                    case NPC_SINDRAGOSA:
                         _sindragosaGUID = creature->GetGUID();
                        break;
                    default:
                        break;
                }
            }
            
            void OnGameObjectCreate(GameObject* go)
            {
               switch (go->GetEntry())
               {
                    case GO_ICE_WALL:
                        uiIceWall = go->GetGUID();
                        if (GetBossState(DATA_GARFROST) == DONE && GetBossState(DATA_ICK) == DONE)
                            HandleGameObject(NULL,true,go);
                         break;
                    case GO_HALLS_OF_REFLECT_PORT:
                         _uiHorp = go->GetGUID();
                         break;
                }
            }

            bool SetBossState(uint32 type, EncounterState state)
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_ICK:
                        if(state == DONE)
                        {
                            if (Creature* summoner = instance->GetCreature(_ickGUID))
                            {
                               for (int i = 0; i < 3; ++i)
                               {
                                if (_teamInInstance == ALLIANCE)
                                    summoner->SummonCreature(NpcSlaveAlliance[i], SlaveLeaderPos2[i], TEMPSUMMON_MANUAL_DESPAWN);
                                else
                                    summoner->SummonCreature(NpcSlaveHorde[i], SlaveLeaderPos2[i], TEMPSUMMON_MANUAL_DESPAWN);
                               }
                            }
                            if(GetBossState(DATA_GARFROST) == DONE)
                                HandleGameObject(uiIceWall, true, NULL);
                        }
                        break;
                    case DATA_GARFROST:
                        if(state == DONE)
                        {
                            SetData(DATA_SLAVE_OUTRO_GARFROST, IN_PROGRESS);
                            if (Creature* summoner = instance->GetCreature(_garfrostGUID))
                            {
                               for (int i = 0; i < 3; ++i)
                               {
                                if (_teamInInstance == ALLIANCE)
                                    summoner->SummonCreature(NpcSlaveAlliance[i], SlaveLeaderPos[i], TEMPSUMMON_MANUAL_DESPAWN);
                                else
                                    summoner->SummonCreature(NpcSlaveHorde[i], SlaveLeaderPos[i], TEMPSUMMON_MANUAL_DESPAWN);
                               }
                               summoner->SummonCreature(36888, spawnPoints2, TEMPSUMMON_MANUAL_DESPAWN);
                               for (uint8 i = 0; i < 3; i++)
                               {
                               summoner->SummonCreature(36889, spawnPoints1[i], TEMPSUMMON_MANUAL_DESPAWN);
                               }
                            }
                            if(GetBossState(DATA_ICK) == DONE)
                                HandleGameObject(uiIceWall, true, NULL);
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
                    case DATA_TYRANNUS_START:
                        return _tyrannusEventStart;
                    case DATA_AREA_TRIGGER_YMIRJAR:
                        return _areaTriggerYmirjar;
                    case DATA_AREA_TRIGGER_FALLEN:
                        return _areaTriggerFallen;
                    case DATA_AREA_TRIGGER_ICE_CICLE:
                        return _areaTriggerIceCicle;
                    case DATA_SLAVE_OUTRO_GARFROST:
                        return _areaTriggerSlaveOutroFargrost;
                    case DATA_GEIST_AMBUSHER:
                        return _areTriggerGeistAmbusher;
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
                    case DATA_VICTUS_OR_GORKUN_FREED:
                        return _victusOrGorkunFreedGUID;
                    case DATA_SINDRAGOSA:
                         return _sindragosaGUID;
                    case GO_HALLS_OF_REFLECT_PORT:
                         return _uiHorp;
                    default:
                        break;
                }

                return 0;
            }
            
            void SetData(uint32 type, uint32 data)
           {
            if(type == DATA_TYRANNUS_START)
                _tyrannusEventStart = data;
            if(type == DATA_AREA_TRIGGER_YMIRJAR)
                _areaTriggerYmirjar = data;
            if(type == DATA_AREA_TRIGGER_FALLEN)
                _areaTriggerFallen = data;
            if(type == DATA_AREA_TRIGGER_ICE_CICLE)
                _areaTriggerIceCicle = data;
            if(type == DATA_SLAVE_OUTRO_GARFROST)
                _areaTriggerSlaveOutroFargrost = data;
            if(type == DATA_GEIST_AMBUSHER)
                _areTriggerGeistAmbusher = data;
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
            uint64 uiIceWall;
            uint64 _victusOrGorkunFreedGUID;
            uint64 _sindragosaGUID;
            uint64 _uiHorp;

            uint32 _teamInInstance;
            uint8  _tyrannusEventStart;
            uint8  _areaTriggerYmirjar;
            uint8  _areaTriggerFallen;
            uint8  _areaTriggerIceCicle;
            uint8  _areaTriggerSlaveOutroFargrost;
            uint8  _areTriggerGeistAmbusher;
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
