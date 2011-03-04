/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
#include "Group.h"

#define MAX_ENCOUNTER     3

/* Pit of Saron encounters:
0- Forgemaster Garfrost
1- Krick and Ick
2- Scourgelord Tyrannus
*/

class instance_pit_of_saron : public InstanceMapScript
{
public:
    instance_pit_of_saron() : InstanceMapScript("instance_pit_of_saron", 658) { }

    InstanceScript* GetInstanceScript(InstanceMap* pMap) const
    {
        return new instance_pit_of_saron_InstanceMapScript(pMap);
    }

    struct instance_pit_of_saron_InstanceMapScript : public InstanceScript
    {
        instance_pit_of_saron_InstanceMapScript(Map* pMap) : InstanceScript(pMap) {};

        uint64 uiKrick;
        uint64 uiIck;
        uint64 uiGarfrost;
        uint64 uiTyrannus;
        uint64 uiRimefang;

        uint64 uiJainaOrSylvanas1;
        uint64 uiJainaOrSylvanas2;

        uint32 uiEncounter[MAX_ENCOUNTER];

        TeamId team;

       void Initialize()
       {
            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                uiEncounter[i] = NOT_STARTED;

            uiGarfrost = 0;
            uiKrick = 0;
            uiIck = 0;
            uiTyrannus = 0;

            team = TEAM_NEUTRAL;
        }

        bool IsEncounterInProgress() const
        {
            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (uiEncounter[i] == IN_PROGRESS)
                    return true;

            return false;
        }

        void OnPlayerEnter(Player *pl)
        {
            if (pl)
                team = pl->GetTeamId();
            else
                return;

            if (Group *grp = pl->GetGroup())
                for (GroupReference *itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
                {
                    Player* member = itr->getSource();
                    if (!member || !member->IsInWorld())
                        continue;

                    if (team != member->GetTeamId())
                    {
                        // Gruppe besteht aus Allianz+Horde!
                        team = TEAM_NEUTRAL;
                        break;
                    }
                }
        }

        void OnCreatureCreate(Creature* pCreature, bool /*add*/)
        {
            Map::PlayerList const &pl = instance->GetPlayers();

            if (!pl.isEmpty())
            {
                if (Player *member = pl.begin()->getSource())
                    team = member->GetTeamId();

                for (Map::PlayerList::const_iterator itr = pl.begin(); itr != pl.end(); ++itr)
                {
                    Player *member = itr->getSource();

                    if (!member)
                        continue;

                    if (team == member->GetTeamId())
                        continue;

                    if (team != member->GetTeamId())
                    {
                        // Gruppe besteht aus Allianz+Horde!
                        team = TEAM_NEUTRAL;
                        break;
                    }
                }
            }

            switch(pCreature->GetEntry())
            {
                case CREATURE_KRICK:
                    uiKrick = pCreature->GetGUID();
                    break;

                case CREATURE_ICK:
                    uiIck = pCreature->GetGUID();
                    break;

                case CREATURE_GARFROST:
                    uiGarfrost = pCreature->GetGUID();
                    break;

                case CREATURE_TYRANNUS:
                    uiTyrannus = pCreature->GetGUID();
                    break;

                case CREATURE_RIMEFANG:
                    uiRimefang = pCreature->GetGUID();
                    break;

                case NPC_SYLVANAS_PART1:
                    if (team == TEAM_ALLIANCE)
                        pCreature->UpdateEntry(NPC_JAINA_PART1, TEAM_ALLIANCE);
                    uiJainaOrSylvanas1 = pCreature->GetGUID();
                    break;
                case NPC_SYLVANAS_PART2:
                    if (team == TEAM_ALLIANCE)
                        pCreature->UpdateEntry(NPC_JAINA_PART2, TEAM_ALLIANCE);
                    uiJainaOrSylvanas2 = pCreature->GetGUID();
                    break;
                case NPC_KILARA:
                    if (team == TEAM_ALLIANCE)
                       pCreature->UpdateEntry(NPC_ELANDRA, TEAM_ALLIANCE);
                    break;
                case NPC_KORALEN:
                    if (team == TEAM_ALLIANCE)
                       pCreature->UpdateEntry(NPC_KORLAEN, TEAM_ALLIANCE);
                    break;
                case NPC_CHAMPION_1_HORDE:
                    if (team == TEAM_ALLIANCE)
                       pCreature->UpdateEntry(NPC_CHAMPION_1_ALLIANCE, TEAM_ALLIANCE);
                    break;
                case NPC_CHAMPION_2_HORDE:
                    if (team == TEAM_ALLIANCE)
                       pCreature->UpdateEntry(NPC_CHAMPION_2_ALLIANCE, TEAM_ALLIANCE);
                    break;
                case NPC_CHAMPION_3_HORDE: // No 3rd set for Alliance?
                    if (team == TEAM_ALLIANCE)
                       pCreature->UpdateEntry(NPC_CHAMPION_2_ALLIANCE, TEAM_ALLIANCE);
                    break;
            }
        }

        uint64 GetData64(uint32 identifier)
        {
            switch(identifier)
            {
                case DATA_GARFROST:             return uiGarfrost;
                case DATA_KRICK:                return uiKrick;
                case DATA_ICK:                  return uiIck;
                case DATA_TYRANNUS:             return uiTyrannus;
                case DATA_RIMEFANG:             return uiRimefang;

                case DATA_JAINA_SYLVANAS_1:     return uiJainaOrSylvanas1;
                case DATA_JAINA_SYLVANAS_2:     return uiJainaOrSylvanas2;
            }

            return 0;
        }

        void SetData(uint32 type, uint32 data)
        {
            switch(type)
            {
                case DATA_GARFROST_EVENT:
                    uiEncounter[0] = data;
                    break;
                case DATA_TYRANNUS_EVENT:
                    uiEncounter[1] = data;
                    break;
                case DATA_KRICKANDICK_EVENT:
                    uiEncounter[2] = data;
                    break;
            }

            if (data == DONE)
                SaveToDB();
        }

        uint32 GetData(uint32 type)
        {
            switch(type)
            {
                case DATA_GARFROST_EVENT:       return uiEncounter[0];
                case DATA_TYRANNUS_EVENT:       return uiEncounter[1];
                case DATA_KRICKANDICK_EVENT:    return uiEncounter[2];
                case DATA_TEAM_IN_INSTANCE:     return uint32(team);
            }
            return 0;
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::string str_data;

            std::ostringstream saveStream;
            saveStream << "P S " << uiEncounter[0] << " " << uiEncounter[1]  << " " << uiEncounter[2];

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

            char dataHead1, dataHead2;
            uint16 data0, data1, data2;

            std::istringstream loadStream(in);
            loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2;

            if (dataHead1 == 'P' && dataHead2 == 'S')
            {
                uiEncounter[0] = data0;
                uiEncounter[1] = data1;
                uiEncounter[2] = data2;

                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (uiEncounter[i] == IN_PROGRESS)
                        uiEncounter[i] = NOT_STARTED;

            } else OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }
    };

};


void AddSC_instance_pit_of_saron()
{
    new instance_pit_of_saron();
}
