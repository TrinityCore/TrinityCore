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

/* ScriptData
SDName: Instance_Old_Hillsbrad
SD%Complete: 75
SDComment: If thrall escort fail, all parts will reset. In future, save sub-parts and continue from last known.
SDCategory: Caverns of Time, Old Hillsbrad Foothills
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "Log.h"
#include "Map.h"
#include "old_hillsbrad.h"
#include "Player.h"
#include "TemporarySummon.h"

#define THRALL_ENTRY    17876
#define TARETHA_ENTRY   18887
#define EPOCH_ENTRY    18096

#define DRAKE_ENTRY             17848

#define QUEST_ENTRY_DIVERSION   10283
#define LODGE_QUEST_TRIGGER     20155

class instance_old_hillsbrad : public InstanceMapScript
{
public:
    instance_old_hillsbrad() : InstanceMapScript(OHScriptName, 560) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_old_hillsbrad_InstanceMapScript(map);
    }

    struct instance_old_hillsbrad_InstanceMapScript : public InstanceScript
    {
        instance_old_hillsbrad_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(OldHillsbradFoothillsBossCount);

            ThrallEscortState = OH_ESCORT_PRISON_TO_SKARLOC;
            mBarrelCount = 0;
            mThrallEventCount = 0;
        }

        OHThrallEscortStates ThrallEscortState;
        uint32 mBarrelCount;
        uint32 mThrallEventCount;

        ObjectGuid ThrallGUID;
        ObjectGuid TarethaGUID;
        ObjectGuid EpochGUID;

        void UpdateQuestCredit()
        {
            Map::PlayerList const& players = instance->GetPlayers();

            if (!players.isEmpty())
            {
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    if (Player* player = itr->GetSource())
                        player->KilledMonsterCredit(LODGE_QUEST_TRIGGER);
                }
            }
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
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

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case TYPE_BARREL_DIVERSION:
                {
                    if (data == IN_PROGRESS)
                    {
                        if (mBarrelCount >= 5)
                            return;

                        ++mBarrelCount;
                        DoUpdateWorldState(WORLD_STATE_OH, mBarrelCount);

                        TC_LOG_DEBUG("scripts", "Instance Old Hillsbrad: go_barrel_old_hillsbrad count %u", mBarrelCount);

                        if (mBarrelCount == 5)
                        {
                            UpdateQuestCredit();
                            if (TempSummon* drake = instance->SummonCreature(DRAKE_ENTRY, { 2128.43f, 71.01f, 64.42f, 1.74f }, nullptr, Milliseconds(30min).count()))
                                drake->SetTempSummonType(TEMPSUMMON_DEAD_DESPAWN);
                        }
                    }
                    break;
                }
                case TYPE_THRALL_EVENT:
                {
                    if (data != OH_ESCORT_DEATH_EVENT)
                    {
                        ThrallEscortState = OHThrallEscortStates(data);
                        if (Creature* thrall = instance->GetCreature(ThrallGUID))
                            thrall->SetNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                    }
                    else
                    {
                        ++mThrallEventCount;
                        if (mThrallEventCount >= 20)
                            ThrallEscortState = OH_ESCORT_FINISHED; // wipe limit reached
                        else
                            ThrallEscortState = OH_ESCORT_PRISON_TO_SKARLOC; // not correct, see npc_thrall_old_hillsbrad::InitializeAI for details
                    }
                    TC_LOG_DEBUG("scripts", "Instance Old Hillsbrad: Thrall escort event adjusted to data %u.", data);
                    break;
                }
            }
        }

        uint32 GetData(uint32 data) const override
        {
            switch (data)
            {
                case TYPE_BARREL_DIVERSION:
                    return mBarrelCount >= 5 ? DONE : IN_PROGRESS;
                case TYPE_THRALL_EVENT:
                    return ThrallEscortState;
            }
            return 0;
        }

        ObjectGuid GetGuidData(uint32 data) const override
        {
            switch (data)
            {
                case DATA_THRALL:
                    return ThrallGUID;
                case DATA_TARETHA:
                    return TarethaGUID;
                case DATA_EPOCH_HUNTER:
                    return EpochGUID;
            }
            return ObjectGuid::Empty;
        }

        void ReadSaveDataMore(std::istringstream&) override
        {
            if (GetBossState(DATA_LIEUTENANT_DRAKE) == DONE)
                mBarrelCount = 5;
            /* TODO not correct, see npc_thrall_old_hillsbrad::InitializeAI for details
            if (GetBossState(DATA_CAPTAIN_SKARLOC) == DONE)
                ThrallEscortState = OH_ESCORT_HORSE_RIDE;
            if (GetBossState(DATA_EPOCH_HUNTER) == DONE)
                ThrallEscortState = OH_ESCORT_FINISHED;
            */
        }
    };
};

void AddSC_instance_old_hillsbrad()
{
    new instance_old_hillsbrad();
}
