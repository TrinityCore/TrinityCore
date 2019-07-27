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

#include "QuestPools.h"
#include "Containers.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "QuestDef.h"
#include "Timer.h"
#include "Transaction.h"
#include <unordered_map>
#include <unordered_set>

/*static*/ QuestPoolMgr* QuestPoolMgr::instance()
{
    static QuestPoolMgr instance;
    return &instance;
}

static void RegeneratePool(QuestPool& pool)
{
    ASSERT(!pool.members.empty(), "Quest pool %u is empty", pool.poolId);
    uint32 const n = pool.members.size()-1;
    ASSERT(pool.numActive <= pool.members.size(), "Quest Pool %u requests %u spawns, but has only %u members.", pool.poolId, pool.numActive, uint32(pool.members.size()));
    pool.activeQuests.clear();
    for (uint32 i = 0; i < pool.numActive; ++i)
    {
        uint32 j = urand(i,n);
        if (i != j)
            std::swap(pool.members[i], pool.members[j]);
        for (uint32 quest : pool.members[i])
            pool.activeQuests.insert(quest);
    }
}

static void SaveToDB(QuestPool const& pool, CharacterDatabaseTransaction trans)
{
    CharacterDatabasePreparedStatement* delStmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_POOL_QUEST_SAVE);
    delStmt->setUInt32(0, pool.poolId);
    trans->Append(delStmt);

    for (uint32 questId : pool.activeQuests)
    {
        CharacterDatabasePreparedStatement* insStmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_POOL_QUEST_SAVE);
        insStmt->setUInt32(0, pool.poolId);
        insStmt->setUInt32(1, questId);
        trans->Append(insStmt);
    }
}

void QuestPoolMgr::LoadFromDB()
{
    uint32 oldMSTime = getMSTime();
    std::unordered_map<uint32, std::pair<std::vector<QuestPool>*, uint32>> lookup; // poolId -> (vector, index)

    _poolLookup.clear();
    _dailyPools.clear();
    _weeklyPools.clear();
    _monthlyPools.clear();

    // load template data from world DB
    {
        QueryResult result = WorldDatabase.Query("SELECT qpm.questId, qpm.poolId, qpm.poolIndex, qpt.numActive FROM quest_pool_members qpm LEFT JOIN quest_pool_template qpt ON qpm.poolId = qpt.poolId");
        if (!result)
        {
            TC_LOG_INFO("server.loading", ">> Loaded 0 quest pools. DB table `quest_pool_members` is empty.");
            return;
        }

        do
        {
            Field* fields = result->Fetch();
            if (fields[2].IsNull())
            {
                TC_LOG_ERROR("sql.sql", "Table `quest_pool_members` contains reference to non-existing pool %u. Skipped.", fields[1].GetUInt32());
                continue;
            }

            uint32 questId = fields[0].GetUInt32();
            uint32 poolId = fields[1].GetUInt32();
            uint32 poolIndex = fields[2].GetUInt8();
            uint32 numActive = fields[3].GetUInt32();

            Quest const* quest = sObjectMgr->GetQuestTemplate(questId);
            if (!quest)
            {
                TC_LOG_ERROR("sql.sql", "Table `quest_pool_members` contains reference to non-existing quest %u. Skipped.", questId);
                continue;
            }
            if (!quest->IsDailyOrWeekly() && !quest->IsMonthly())
            {
                TC_LOG_ERROR("sql.sql", "Table `quest_pool_members` contains reference to quest %u, which is neither daily, weekly nor monthly. Skipped.", questId);
                continue;
            }

            auto& pair = lookup[poolId];
            if (!pair.first)
            {
                pair.first = (quest->IsDaily() ? &_dailyPools : quest->IsWeekly() ? &_weeklyPools : &_monthlyPools);
                pair.first->emplace_back();
                pair.second = (pair.first->size()-1);

                pair.first->back().poolId = poolId;
                pair.first->back().numActive = numActive;
            }

            QuestPool::Members& members = (*pair.first)[pair.second].members;
            if (!(poolIndex < members.size()))
                members.resize(poolIndex+1);
            members[poolIndex].push_back(questId);
        } while (result->NextRow());
    }

    // load saved spawns from character DB
    {
        QueryResult result = CharacterDatabase.Query("SELECT pool_id, quest_id FROM pool_quest_save");
        if (result)
        {
            std::unordered_set<uint32> unknownPoolIds;
            do
            {
                Field* fields = result->Fetch();

                uint32 poolId = fields[0].GetUInt32();
                uint32 questId = fields[1].GetUInt32();

                auto it = lookup.find(poolId);
                if (it == lookup.end() || !it->second.first)
                {
                    TC_LOG_ERROR("sql.sql", "Table `pool_quest_save` contains reference to non-existant quest pool %u. Deleted.", poolId);
                    unknownPoolIds.insert(poolId);
                    continue;
                }

                (*it->second.first)[it->second.second].activeQuests.insert(questId);
            } while (result->NextRow());

            CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
            for (uint32 poolId : unknownPoolIds)
            {
                CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_POOL_QUEST_SAVE);
                stmt->setUInt32(0, poolId);
                trans->Append(stmt);
            }
            CharacterDatabase.CommitTransaction(trans);
        }
    }

    // post-processing and sanity checks
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    for (auto pair : lookup)
    {
        if (!pair.second.first)
            continue;
        QuestPool& pool = (*pair.second.first)[pair.second.second];
        if (pool.members.size() < pool.numActive)
        {
            TC_LOG_ERROR("sql.sql", "Table `quest_pool_template` contains quest pool %u requesting %u spawns, but only has %zu members. Requested spawns reduced.", pool.poolId, pool.numActive, pool.members.size());
            pool.numActive = pool.members.size();
        }

        bool doRegenerate = pool.activeQuests.empty();
        if (!doRegenerate)
        {
            std::unordered_set<uint32> accountedFor;
            uint32 activeCount = 0;
            for (size_t i = pool.members.size(); (i--);)
            {
                QuestPool::Member& member = pool.members[i];
                if (member.empty())
                {
                    TC_LOG_ERROR("sql.sql", "Table `quest_pool_members` contains no entries at index %zu for quest pool %u. Index removed.", i, pool.poolId);
                    std::swap(pool.members[i], pool.members.back());
                    pool.members.pop_back();
                    continue;
                }

                // check if the first member is active
                auto itFirst = pool.activeQuests.find(member[0]);
                bool status = (itFirst != pool.activeQuests.end());
                // temporarily remove any spawns that are accounted for
                if (status)
                {
                    accountedFor.insert(member[0]);
                    pool.activeQuests.erase(itFirst);
                }

                // now check if all other members also have the same status, and warn if not
                for (auto it = member.begin(); (++it) != member.end();)
                {
                    auto itOther = pool.activeQuests.find(*it);
                    bool otherStatus = (itOther != pool.activeQuests.end());
                    if (status != otherStatus)
                        TC_LOG_WARN("sql.sql", "Table `pool_quest_save` %s quest %u (in pool %u, index %zu) saved, but its index is%s active (because quest %u is%s in the table). Set quest %u to %sactive.", (status ? "does not have" : "has"), *it, pool.poolId, i, (status ? "" : " not"), member[0], (status ? "" : " not"), *it, (status ? "" : "in"));
                    if (otherStatus)
                        pool.activeQuests.erase(itOther);
                    if (status)
                        accountedFor.insert(*it);
                }

                if (status)
                    ++activeCount;
            }

            // warn for any remaining active spawns (not part of the pool)
            for (uint32 quest : pool.activeQuests)
                TC_LOG_WARN("sql.sql", "Table `pool_quest_save` has saved quest %u for pool %u, but that quest is not part of the pool. Skipped.", quest, pool.poolId);

            // only the previously-found spawns should actually be active
            std::swap(pool.activeQuests, accountedFor);

            if (activeCount != pool.numActive)
            {
                doRegenerate = true;
                TC_LOG_ERROR("sql.sql", "Table `pool_quest_save` has %u active members saved for pool %u, which requests %u active members. Pool spawns re-generated.", activeCount, pool.poolId, pool.numActive);
            }
        }

        if (doRegenerate)
        {
            RegeneratePool(pool);
            SaveToDB(pool, trans);
        }

        for (QuestPool::Member const& member : pool.members)
        {
            for (uint32 quest : member)
            {
                QuestPool*& ref = _poolLookup[quest];
                if (ref)
                {
                    TC_LOG_ERROR("sql.sql", "Table `quest_pool_members` lists quest %u as member of pool %u, but it is already a member of pool %u. Skipped.", quest, pool.poolId, ref->poolId);
                    continue;
                }
                ref = &pool;
            }
        }
    }
    CharacterDatabase.CommitTransaction(trans);

    TC_LOG_INFO("server.loading", ">> Loaded %zu daily, %zu weekly and %zu monthly quest pools in %u ms", _dailyPools.size(), _weeklyPools.size(), _monthlyPools.size(), GetMSTimeDiffToNow(oldMSTime));
}

void QuestPoolMgr::Regenerate(std::vector<QuestPool>& pools)
{
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    for (QuestPool& pool : pools)
    {
        RegeneratePool(pool);
        SaveToDB(pool, trans);
    }
    CharacterDatabase.CommitTransaction(trans);
}

// the storage structure ends up making this kind of inefficient
// we don't use it in practice (only in debug commands), so that's fine
QuestPool const* QuestPoolMgr::FindQuestPool(uint32 poolId) const
{
    auto lambda = [poolId](QuestPool const& p) { return (p.poolId == poolId); };
    auto it = std::find_if(_dailyPools.begin(), _dailyPools.end(), lambda);
    if (it != _dailyPools.end())
        return &*it;
    it = std::find_if(_weeklyPools.begin(), _weeklyPools.end(), lambda);
    if (it != _weeklyPools.end())
        return &*it;
    it = std::find_if(_monthlyPools.begin(), _monthlyPools.end(), lambda);
    if (it != _monthlyPools.end())
        return &*it;
    return nullptr;
}

bool QuestPoolMgr::IsQuestActive(uint32 questId) const
{
    auto it = _poolLookup.find(questId);
    if (it == _poolLookup.end()) // not pooled
        return true;

    return (it->second->activeQuests.find(questId) != it->second->activeQuests.end());
}


