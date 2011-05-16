/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Instance_Old_Hillsbrad
SD%Complete: 75
SDComment: If thrall escort fail, all parts will reset. In future, save sub-parts and continue from last known.
SDCategory: Caverns of Time, Old Hillsbrad Foothills
EndScriptData */

#include "ScriptPCH.h"
#include "old_hillsbrad.h"

#define MAX_ENCOUNTER      6

#define THRALL_ENTRY    17876
#define TARETHA_ENTRY   18887
#define EPOCH_ENTRY    18096

#define DRAKE_ENTRY             17848

#define QUEST_ENTRY_DIVERSION   10283
#define LODGE_QUEST_TRIGGER     20155

class instance_old_hillsbrad : public InstanceMapScript
{
public:
    instance_old_hillsbrad() : InstanceMapScript("instance_old_hillsbrad", 560) { }

    InstanceScript* GetInstanceScript(InstanceMap* pMap) const
    {
        return new instance_old_hillsbrad_InstanceMapScript(pMap);
    }

    struct instance_old_hillsbrad_InstanceMapScript : public InstanceScript
    {
        instance_old_hillsbrad_InstanceMapScript(Map* pMap) : InstanceScript(pMap) {}

        uint32 m_auiEncounter[MAX_ENCOUNTER];
        uint32 mBarrelCount;
        uint32 mThrallEventCount;

        uint64 ThrallGUID;
        uint64 TarethaGUID;
        uint64 EpochGUID;

        void Initialize()
        {
            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

            mBarrelCount        = 0;
            mThrallEventCount   = 0;
            ThrallGUID          = 0;
            TarethaGUID         = 0;
            EpochGUID        = 0;
        }

        Player* GetPlayerInMap()
        {
            Map::PlayerList const& players = instance->GetPlayers();

            if (!players.isEmpty())
            {
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    if (Player* plr = itr->getSource())
                        return plr;
                }
            }

            sLog->outDebug(LOG_FILTER_TSCR, "TSCR: Instance Old Hillsbrad: GetPlayerInMap, but PlayerList is empty!");
            return NULL;
        }

        void UpdateQuestCredit()
        {
            Map::PlayerList const& players = instance->GetPlayers();

            if (!players.isEmpty())
            {
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    if (Player* pPlayer = itr->getSource())
                        pPlayer->KilledMonsterCredit(LODGE_QUEST_TRIGGER, 0);
                }
            }
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch(creature->GetEntry())
            {
                case THRALL_ENTRY:
                    ThrallGUID = creature->GetGUID();
                    break;
                case TARETHA_ENTRY:
                    TarethaGUID = creature->GetGUID();
                    break;
            case EPOCH_ENTRY:
            EpochGUID = creature->GetGUID();
            break;
            }
        }

        void SetData(uint32 type, uint32 data)
        {
            Player* pPlayer = GetPlayerInMap();

            if (!pPlayer)
            {
                sLog->outDebug(LOG_FILTER_TSCR, "TSCR: Instance Old Hillsbrad: SetData (Type: %u Data %u) cannot find any player.", type, data);
                return;
            }

            switch(type)
            {
                case TYPE_BARREL_DIVERSION:
                {
                    if (data == IN_PROGRESS)
                    {
                        if (mBarrelCount >= 5)
                            return;

                        ++mBarrelCount;
                        DoUpdateWorldState(WORLD_STATE_OH, mBarrelCount);

                        sLog->outDebug(LOG_FILTER_TSCR, "TSCR: Instance Old Hillsbrad: go_barrel_old_hillsbrad count %u", mBarrelCount);

                        m_auiEncounter[0] = IN_PROGRESS;

                        if (mBarrelCount == 5)
                        {
                            UpdateQuestCredit();
                            pPlayer->SummonCreature(DRAKE_ENTRY, 2128.43f, 71.01f, 64.42f, 1.74f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 1800000);
                            m_auiEncounter[0] = DONE;
                        }
                    }
                    break;
                }
                case TYPE_THRALL_EVENT:
                {
                    if (data == FAIL)
                    {
                        if (mThrallEventCount <= 20)
                        {
                            ++mThrallEventCount;
                            m_auiEncounter[1] = NOT_STARTED;
                            sLog->outDebug(LOG_FILTER_TSCR, "TSCR: Instance Old Hillsbrad: Thrall event failed %u times. Resetting all sub-events.", mThrallEventCount);
                            m_auiEncounter[2] = NOT_STARTED;
                            m_auiEncounter[3] = NOT_STARTED;
                            m_auiEncounter[4] = NOT_STARTED;
                            m_auiEncounter[5] = NOT_STARTED;
                        }
                        else if (mThrallEventCount > 20)
                        {
                            m_auiEncounter[1] = data;
                            m_auiEncounter[2] = data;
                            m_auiEncounter[3] = data;
                            m_auiEncounter[4] = data;
                            m_auiEncounter[5] = data;
                            sLog->outDebug(LOG_FILTER_TSCR, "TSCR: Instance Old Hillsbrad: Thrall event failed %u times. Resetting all sub-events.", mThrallEventCount);
                        }
                    }
                    else
                        m_auiEncounter[1] = data;
                    sLog->outDebug(LOG_FILTER_TSCR, "TSCR: Instance Old Hillsbrad: Thrall escort event adjusted to data %u.", data);
                    break;
                }
                case TYPE_THRALL_PART1:
                    m_auiEncounter[2] = data;
                    sLog->outDebug(LOG_FILTER_TSCR, "TSCR: Instance Old Hillsbrad: Thrall event part I adjusted to data %u.", data);
                    break;
                case TYPE_THRALL_PART2:
                    m_auiEncounter[3] = data;
                    sLog->outDebug(LOG_FILTER_TSCR, "TSCR: Instance Old Hillsbrad: Thrall event part II adjusted to data %u.", data);
                    break;
                case TYPE_THRALL_PART3:
                    m_auiEncounter[4] = data;
                    sLog->outDebug(LOG_FILTER_TSCR, "TSCR: Instance Old Hillsbrad: Thrall event part III adjusted to data %u.", data);
                    break;
                case TYPE_THRALL_PART4:
                    m_auiEncounter[5] = data;
                     sLog->outDebug(LOG_FILTER_TSCR, "TSCR: Instance Old Hillsbrad: Thrall event part IV adjusted to data %u.", data);
                    break;
            }
        }

        uint32 GetData(uint32 data)
        {
            switch(data)
            {
                case TYPE_BARREL_DIVERSION:
                    return m_auiEncounter[0];
                case TYPE_THRALL_EVENT:
                    return m_auiEncounter[1];
                case TYPE_THRALL_PART1:
                    return m_auiEncounter[2];
                case TYPE_THRALL_PART2:
                    return m_auiEncounter[3];
                case TYPE_THRALL_PART3:
                    return m_auiEncounter[4];
                case TYPE_THRALL_PART4:
                    return m_auiEncounter[5];
            }
            return 0;
        }

        uint64 GetData64(uint32 data)
        {
            switch(data)
            {
                case DATA_THRALL:
                    return ThrallGUID;
                case DATA_TARETHA:
                    return TarethaGUID;
            case DATA_EPOCH:
            return EpochGUID;
            }
            return 0;
        }
    };

};

void AddSC_instance_old_hillsbrad()
{
    new instance_old_hillsbrad();
}
