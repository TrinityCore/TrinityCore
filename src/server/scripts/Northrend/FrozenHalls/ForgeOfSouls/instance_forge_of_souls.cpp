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
#include "forge_of_souls.h"
#include "Group.h"

#define MAX_ENCOUNTER 2

/* Forge of Souls encounters:
0- Bronjahm, The Godfather of Souls
1- The Devourer of Souls
*/

class instance_forge_of_souls : public InstanceMapScript
{
    public:
        instance_forge_of_souls() : InstanceMapScript(FoSScriptName, 632) { }

        struct instance_forge_of_souls_InstanceScript : public InstanceScript
        {
            instance_forge_of_souls_InstanceScript(Map* pMap) : InstanceScript(pMap)
            {
                SetBossNumber(MAX_ENCOUNTER);
                uiBronjahm = 0;
                uiDevourer = 0;

                uiSylvanas_Part1 = 0;
                uiJaina_Part1 = 0;
                uiKalira = 0;
                uiElandra = 0;
                uiLoralen = 0;
                uiKoreln = 0;

                TeamId team = TEAM_NEUTRAL;

                spawned = false;
            }

            void OnPlayerEnter(Player *pl)
            {
                if (pl)
                    team = pl->GetTeamId();
                else
                    return;

                if (Group *grp = pl->GetGroup())
                {
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
                SpawnQuestgiver();
            }

            TeamId GetGrpTeam()
            {
                TeamId tmpteam = TEAM_NEUTRAL;
                Map::PlayerList const &pl = instance->GetPlayers();

                if (!pl.isEmpty())
                {
                    if (Player *member = pl.begin()->getSource())
                        tmpteam = member->GetTeamId();

                    for (Map::PlayerList::const_iterator itr = pl.begin(); itr != pl.end(); ++itr)
                    {
                        Player *member = itr->getSource();

                        if (!member)
                            continue;

                        if (tmpteam == member->GetTeamId())
                            continue;

                        if (tmpteam != member->GetTeamId())
                            // Gruppe besteht aus Allianz+Horde!
                            return TEAM_NEUTRAL;
                    }
                }
                return tmpteam;
            }

            void SpawnQuestgiver()
            {
                if (spawned)
                    if (team == GetGrpTeam())
                        return;
                    else
                        team = GetGrpTeam();

                Creature *TSAlly[3];
                Creature *TSHorde[3];

                Position NPC_SYLVANAS_PART1_POS = { 4899.98f, 2208.16f, 638.817f, 0.349066f };
                Position NPC_LORALEN_POS = { 4899.85f, 2205.9f, 638.817f, 5.49779f };
                Position NPC_KALIRA_POS = { 4902.83f, 2212.83f, 638.817f, 0.349066f };

                switch(team)
                {
                    case TEAM_ALLIANCE:
                        if (uiJaina_Part1)
                            break;

                        TSAlly[0] = instance->SummonCreature(NPC_JAINA_PART1, NPC_SYLVANAS_PART1_POS);
                        TSAlly[1] = instance->SummonCreature(NPC_KORELN, NPC_LORALEN_POS);
                        TSAlly[2] = instance->SummonCreature(NPC_ELANDRA, NPC_KALIRA_POS);

                        for (uint8 i=0; i<3; ++i)
                            if (TSAlly[i])
                            {
                                switch(i)
                                {
                                    case 0: uiJaina_Part1 = TSAlly[i]->GetGUID(); break;
                                    case 1: uiKoreln = TSAlly[i]->GetGUID(); break;
                                    case 2: uiElandra = TSAlly[i]->GetGUID(); break;
                                }
                                TSAlly[i]->SetReactState(REACT_PASSIVE);
                                TSAlly[i]->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_ATTACKABLE_1|UNIT_FLAG_OOC_NOT_ATTACKABLE);
                                TSAlly[i]->UpdateObjectVisibility();
                            }
                        break;
                    case TEAM_HORDE:
                        if (uiSylvanas_Part1)
                            break;

                        TSHorde[0] = instance->SummonCreature(NPC_SYLVANAS_PART1, NPC_SYLVANAS_PART1_POS);
                        TSHorde[1] = instance->SummonCreature(NPC_LORALEN, NPC_LORALEN_POS);
                        TSHorde[2] = instance->SummonCreature(NPC_KALIRA, NPC_KALIRA_POS);

                        for (uint8 i=0; i<3; ++i)
                            if (TSHorde[i])
                            {
                                switch(i)
                                {
                                    case 0: uiSylvanas_Part1 = TSHorde[i]->GetGUID(); break;
                                    case 1: uiLoralen = TSHorde[i]->GetGUID(); break;
                                    case 2: uiKalira = TSHorde[i]->GetGUID(); break;
                                }
                                TSHorde[i]->SetReactState(REACT_PASSIVE);
                                TSHorde[i]->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_ATTACKABLE_1|UNIT_FLAG_OOC_NOT_ATTACKABLE);
                                TSHorde[i]->UpdateObjectVisibility();
                            }
                        break;
                    // Gruppe besteht aus Allianz+Horde!
                    case TEAM_NEUTRAL:
                        // Ally
                        if (!uiJaina_Part1)
                        {
                            TSAlly[0] = instance->SummonCreature(NPC_JAINA_PART1, NPC_SYLVANAS_PART1_POS);
                            TSAlly[1] = instance->SummonCreature(NPC_KORELN, NPC_LORALEN_POS);
                            TSAlly[2] = instance->SummonCreature(NPC_ELANDRA, NPC_KALIRA_POS);
                        }
                        else
                        {
                            TSAlly[0] = instance->GetCreature(uiJaina_Part1);
                            TSAlly[1] = instance->GetCreature(uiKoreln);
                            TSAlly[2] = instance->GetCreature(uiElandra);
                        }
                        // Horde
                        if (!uiSylvanas_Part1)
                        {
                            Position pos[3];

                            for (uint8 i=0; i<3; ++i)
                                if (TSAlly[i])
                                    TSAlly[i]->GetNearPosition(pos[i], 2, 0);

                            TSHorde[0] = instance->SummonCreature(NPC_SYLVANAS_PART1, pos[0]);
                            TSHorde[1] = instance->SummonCreature(NPC_LORALEN, pos[1]);
                            TSHorde[2] = instance->SummonCreature(NPC_KALIRA, pos[2]);
                        }
                        for (uint8 i=0; i<3; ++i)
                        {
                            if (TSAlly[i] && (!uiJaina_Part1 || !uiKoreln || !uiElandra))
                            {
                                switch(i)
                                {
                                    case 0: uiJaina_Part1 = TSAlly[i]->GetGUID(); break;
                                    case 1: uiKoreln = TSAlly[i]->GetGUID(); break;
                                    case 2: uiElandra = TSAlly[i]->GetGUID(); break;
                                }
                                TSAlly[i]->SetReactState(REACT_PASSIVE);
                                TSAlly[i]->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_ATTACKABLE_1|UNIT_FLAG_OOC_NOT_ATTACKABLE);
                                TSAlly[i]->UpdateObjectVisibility();
                            }
                            if (TSHorde[i] && (!uiSylvanas_Part1 || !uiLoralen || !uiKalira))
                            {
                                switch(i)
                                {
                                    case 0: uiSylvanas_Part1 = TSHorde[i]->GetGUID(); break;
                                    case 1: uiLoralen = TSHorde[i]->GetGUID(); break;
                                    case 2: uiKalira = TSHorde[i]->GetGUID(); break;
                                }
                                TSHorde[i]->SetReactState(REACT_PASSIVE);
                                TSHorde[i]->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_ATTACKABLE_1|UNIT_FLAG_OOC_NOT_ATTACKABLE);
                                TSHorde[i]->UpdateObjectVisibility();
                            }
                        }
                        break;
                }
                spawned = true;
            }

            void OnCreatureCreate(Creature* pCreature, bool /*add*/)
            {
                team = GetGrpTeam();

                switch(pCreature->GetEntry())
                {
                    case CREATURE_BRONJAHM:
                        uiBronjahm = pCreature->GetGUID();
                        break;
                    case CREATURE_DEVOURER:
                        uiDevourer = pCreature->GetGUID();
                        break;
                }
            }

            uint32 GetData(uint32 type)
            {
                switch(type)
                {
                    case DATA_TEAM_IN_INSTANCE:
                        return uint32(team);
                    default:
                        break;
                }
                return 0;
            }

            uint64 GetData64(uint32 identifier)
            {
                switch(identifier)
                {
                    case DATA_BRONJAHM: return uiBronjahm;
                    case DATA_DEVOURER: return uiDevourer;
                }
                return 0;
            }

            std::string GetSaveData()
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "F S " << GetBossSaveData();

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

                if (dataHead1 == 'F' && dataHead2 == 'S')
                {
                    for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;
                        SetBossState(i, EncounterState(tmpState));
                    }
                } else OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }

        private:
            uint64 uiBronjahm;
            uint64 uiDevourer;

            uint64 uiSylvanas_Part1;
            uint64 uiJaina_Part1;
            uint64 uiKalira;
            uint64 uiElandra;
            uint64 uiLoralen;
            uint64 uiKoreln;

            TeamId team;

            bool spawned;
        };

        InstanceScript* GetInstanceScript(InstanceMap *map) const
        {
            return new instance_forge_of_souls_InstanceScript(map);
        }
};

void AddSC_instance_forge_of_souls()
{
    new instance_forge_of_souls();
}
