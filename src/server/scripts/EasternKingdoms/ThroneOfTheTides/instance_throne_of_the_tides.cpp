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
#include "throne_of_the_tides.h"

enum Factions
{
    FACTION_FRIENDLY = 35
};

class instance_throne_of_the_tides : public InstanceMapScript
{
    public:
        instance_throne_of_the_tides() : InstanceMapScript("instance_throne_of_the_tides", 643) {}

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_throne_of_the_tides_InstanceMapScript(map);
        }

        struct instance_throne_of_the_tides_InstanceMapScript : public InstanceScript
        {
            instance_throne_of_the_tides_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetBossNumber(MAX_ENCOUNTER);
            }

            uint64 LadyNazjar;
            uint64 JellyFishElevator;
            uint64 CommanderUlthok;
            uint64 ErunakStonespeaker;
            uint64 MindbenderGhursha;
            uint64 Ozumat;
            uint64 Neptulon;

            uint64 LadyNazjarDoor;
            uint64 CommanderUlthokDoor;
            uint64 ErunakStonespeakerDoor;
            uint64 OzumatDoor;

            uint32 encounter[MAX_ENCOUNTER];

            std::string str_data;

            void Initialize()
            {
                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                   encounter[i] = NOT_STARTED;

                LadyNazjar              = 0;
                JellyFishElevator      = 0;
                CommanderUlthok         = 0;
                ErunakStonespeaker      = 0;
                MindbenderGhursha       = 0;
                Ozumat                  = 0;
                Neptulon                = 0;

                LadyNazjarDoor          = 0;
                CommanderUlthokDoor     = 0;
                ErunakStonespeakerDoor  = 0;
                OzumatDoor              = 0;
            }

            bool IsEncounterInProgress() const
            {
                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (encounter[i] == IN_PROGRESS) return true;

                return false;
            }

            void OnCreatureCreate(Creature* creature)
            {
                Map::PlayerList const &players = instance->GetPlayers();
                uint32 TeamInInstance = 0;

                if (!players.isEmpty())
                {
                    if (Player* player = players.begin()->getSource())
                        TeamInInstance = player->GetTeam();
                }
                switch (creature->GetEntry())
                {
                    case BOSS_LADY_NAZJAR:
                        LadyNazjar = creature->GetGUID();
                        break;
                    case BOSS_COMMANDER_ULTHOK:
                        CommanderUlthok = creature->GetGUID();
                        break;
                    case BOSS_ERUNAK_STONESPEAKER:
                        ErunakStonespeaker = creature->GetGUID();
                        break;
                    case BOSS_MINDBENDER_GHURSHA:
                        MindbenderGhursha = creature->GetGUID();
                        break;
                    case BOSS_OZUMAT:
                        Ozumat = creature->GetGUID();
                        break;
                    case BOSS_NEPTULON:
                        Neptulon = creature->GetGUID();
                        break;
                    case 50272:
                    {
                        if (ServerAllowsTwoSideGroups())
                            creature->setFaction(FACTION_FRIENDLY);

                        if (TeamInInstance == ALLIANCE)
                            creature->UpdateEntry(50270, ALLIANCE);
                        break;
                    }
                }
            }

            void OnGameObjectCreate(GameObject* go)
            {
                switch(go->GetEntry())
                {
                    case GO_LADY_NAZJAR_DOOR:
                        LadyNazjarDoor = go->GetGUID();
                        if (encounter[0] == DONE)
                            HandleGameObject(0, true, go);
                        if (encounter[0] == IN_PROGRESS)
                            HandleGameObject(0, false, go);
                        break;
                    case GO_JELLYFISH_ELEVATOR:
                        JellyFishElevator = go->GetGUID();
                        if (encounter[0] == DONE)
                            HandleGameObject(0, true, go);
                        if (encounter[0] == IN_PROGRESS)
                            HandleGameObject(0, false, go);
                        break;
                    case GO_COMMANDER_ULTHOK_DOOR:
                        CommanderUlthokDoor = go->GetGUID();
                        if (encounter[0] == DONE)
                            HandleGameObject(0, false, go);
                        if (encounter[1] == DONE)
                            HandleGameObject(0, true, go);
                        break;
                    case GO_ERUNAK_STONESPEAKER_DOOR:
                        OzumatDoor = go->GetGUID();
                        if (encounter[1] == DONE)
                            HandleGameObject(0, true, go);
                        if (encounter[2] == IN_PROGRESS)
                            HandleGameObject(0, false, go);
                        if (encounter[2] == DONE)
                            HandleGameObject(0, true, go);
                        break;
                    case GO_OZUMAT_DOOR:
                        ErunakStonespeakerDoor = go->GetGUID();
                        if (encounter[2] == DONE)
                            HandleGameObject(0, true, go);
                        if (encounter[3] == IN_PROGRESS)
                            HandleGameObject(0, false, go);
                        if (encounter[3] == DONE)
                            HandleGameObject(0, true, go);
                        break;
                }
            }

            void SetData(uint32 type, uint32 data)
            {
                switch(type)
                {
                    case DATA_LADY_NAZJAR_EVENT:
                        encounter[0] = data;
                        break;
                    case DATA_COMMANDER_ULTHOK_EVENT:
                        encounter[1] = data;
                        break;
                    case DATA_ERUNAK_STONESPEAKER_EVENT:
                        encounter[2] = data;
                        break;
                    case DATA_OZUMAT_EVENT:
                        encounter[3] = data;
                        break;
                }

                if (data == DONE)
                    SaveToDB();
            }

            uint32 GetData(uint32 type)
            {
                switch(type)
                {
                    case DATA_LADY_NAZJAR_EVENT:               return encounter[0];
                    case DATA_COMMANDER_ULTHOK_EVENT:          return encounter[1];
                    case DATA_ERUNAK_STONESPEAKER_EVENT:       return encounter[2];
                    case DATA_OZUMAT_EVENT:                    return encounter[3];
                }
                return 0;
            }

            uint64 GetData64(uint32 identifier)
            {
                switch(identifier)
                {
                    case DATA_LADY_NAZJAR:             return LadyNazjar;
                    case DATA_COMMANDER_ULTHOK:        return CommanderUlthok;
                    case DATA_ERUNAK_STONESPEAKER:     return ErunakStonespeaker;
                    case BOSS_MINDBENDER_GHURSHA:      return MindbenderGhursha;
                    case DATA_OZUMAT:                  return Ozumat;
                    case DATA_NEPTULON:                return Neptulon;
                }
                return 0;
            }

            std::string GetSaveData()
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "T o t T " << encounter[0] << " " << encounter[1] << " "
                    << encounter[2] << " " << encounter[3];

                str_data = saveStream.str();

                OUT_SAVE_INST_DATA_COMPLETE;
                return str_data;
            }

            void Load(const char* in)
            {
                if (!in)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(in);

                char dataHead1, dataHead2, dataHead3, dataHead4;
                uint16 data0, data1, data2, data3;

                std::istringstream loadStream(in);
                loadStream >> dataHead1 >> dataHead2 >> dataHead3 >> dataHead4 >> data0 >> data1 >> data2 >> data3;

                if (dataHead1 == 'T' && dataHead2 == 'o' && dataHead3 == 't' && dataHead4 == 'T')
                {
                    encounter[0] = data0;
                    encounter[1] = data1;
                    encounter[2] = data2;
                    encounter[3] = data3;

                    for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                        if (encounter[i] == IN_PROGRESS)
                            encounter[i] = NOT_STARTED;

                    if(encounter[0] == DONE && encounter[1] == NOT_STARTED)
                    {
                        if(Creature* summoner = instance->GetCreature(Neptulon))
                            summoner->SummonCreature(BOSS_COMMANDER_ULTHOK, 59.185f, 802.251f, 805.730f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 60480000);
                    }
                } else OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }
        };
};

void AddSC_instance_throne_of_the_tides()
{
    new instance_throne_of_the_tides();
}