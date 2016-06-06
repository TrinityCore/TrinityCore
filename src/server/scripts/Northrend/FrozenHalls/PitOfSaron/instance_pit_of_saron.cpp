/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
#include "InstanceScript.h"
#include "pit_of_saron.h"
#include "Player.h"

// positions for Martin Victus (37591) and Gorkun Ironskull (37592)
Position const SlaveLeaderPos  = {689.7158f, -104.8736f, 513.7360f, 0.0f};
// position for Jaina and Sylvanas
Position const EventLeaderPos2 = {1054.368f, 107.14620f, 628.4467f, 0.0f};

DoorData const Doors[] =
{
    {GO_ICE_WALL,   DATA_GARFROST,  DOOR_TYPE_PASSAGE },
    {GO_ICE_WALL,   DATA_ICK,       DOOR_TYPE_PASSAGE },
    {GO_HALLS_OF_REFLECTION_PORTCULLIS,   DATA_TYRANNUS,       DOOR_TYPE_PASSAGE },
};

class instance_pit_of_saron : public InstanceMapScript
{
    public:
        instance_pit_of_saron() : InstanceMapScript(PoSScriptName, 658) { }

        struct instance_pit_of_saron_InstanceScript : public InstanceScript
        {
            instance_pit_of_saron_InstanceScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDoorData(Doors);
                _teamInInstance = 0;
            }

            void OnPlayerEnter(Player* player) override
            {
                if (!_teamInInstance)
                    _teamInInstance = player->GetTeam();
            }

            void OnCreatureCreate(Creature* creature) override
            {
                if (!_teamInInstance)
                {
                    Map::PlayerList const& players = instance->GetPlayers();
                    if (!players.isEmpty())
                        if (Player* player = players.begin()->GetSource())
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
                            creature->UpdateEntry(NPC_JAINA_PART1);
                        _jainaOrSylvanas1GUID = creature->GetGUID();
                        break;
                    case NPC_SYLVANAS_PART2:
                        if (_teamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_JAINA_PART2);
                        _jainaOrSylvanas2GUID = creature->GetGUID();
                        break;
                    case NPC_KILARA:
                        if (_teamInInstance == ALLIANCE)
                           creature->UpdateEntry(NPC_ELANDRA);
                        break;
                    case NPC_KORALEN:
                        if (_teamInInstance == ALLIANCE)
                           creature->UpdateEntry(NPC_KORLAEN);
                        break;
                    case NPC_CHAMPION_1_HORDE:
                        if (_teamInInstance == ALLIANCE)
                           creature->UpdateEntry(NPC_CHAMPION_1_ALLIANCE);
                        break;
                    case NPC_CHAMPION_2_HORDE:
                        if (_teamInInstance == ALLIANCE)
                           creature->UpdateEntry(NPC_CHAMPION_2_ALLIANCE);
                        break;
                    case NPC_CHAMPION_3_HORDE: // No 3rd set for Alliance?
                        if (_teamInInstance == ALLIANCE)
                           creature->UpdateEntry(NPC_CHAMPION_2_ALLIANCE);
                        break;
                    case NPC_HORDE_SLAVE_1:
                        if (_teamInInstance == ALLIANCE)
                           creature->UpdateEntry(NPC_ALLIANCE_SLAVE_1);
                        break;
                    case NPC_HORDE_SLAVE_2:
                        if (_teamInInstance == ALLIANCE)
                           creature->UpdateEntry(NPC_ALLIANCE_SLAVE_2);
                        break;
                    case NPC_HORDE_SLAVE_3:
                        if (_teamInInstance == ALLIANCE)
                           creature->UpdateEntry(NPC_ALLIANCE_SLAVE_3);
                        break;
                    case NPC_HORDE_SLAVE_4:
                        if (_teamInInstance == ALLIANCE)
                           creature->UpdateEntry(NPC_ALLIANCE_SLAVE_4);
                        break;
                    case NPC_FREED_SLAVE_1_HORDE:
                        if (_teamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_FREED_SLAVE_1_ALLIANCE);
                        break;
                    case NPC_FREED_SLAVE_2_HORDE:
                        if (_teamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_FREED_SLAVE_2_ALLIANCE);
                        break;
                    case NPC_FREED_SLAVE_3_HORDE:
                        if (_teamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_FREED_SLAVE_3_ALLIANCE);
                        break;
                    case NPC_RESCUED_SLAVE_HORDE:
                        if (_teamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_RESCUED_SLAVE_ALLIANCE);
                        break;
                    case NPC_MARTIN_VICTUS_1:
                        if (_teamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_MARTIN_VICTUS_1);
                        break;
                    case NPC_MARTIN_VICTUS_2:
                        if (_teamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_MARTIN_VICTUS_2);
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_ICE_WALL:
                    case GO_HALLS_OF_REFLECTION_PORTCULLIS:
                        AddDoor(go, true);
                        break;
                }
            }

            void OnGameObjectRemove(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_ICE_WALL:
                    case GO_HALLS_OF_REFLECTION_PORTCULLIS:
                        AddDoor(go, false);
                        break;
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

            uint32 GetData(uint32 type) const override
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

        private:
            ObjectGuid _garfrostGUID;
            ObjectGuid _krickGUID;
            ObjectGuid _ickGUID;
            ObjectGuid _tyrannusGUID;
            ObjectGuid _rimefangGUID;

            ObjectGuid _tyrannusEventGUID;
            ObjectGuid _jainaOrSylvanas1GUID;
            ObjectGuid _jainaOrSylvanas2GUID;

            uint32 _teamInInstance;
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
