/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef TRINITY_QUESTPOOLS_H
#define TRINITY_QUESTPOOLS_H

#include "Define.h"
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct QuestPool
{
    using Member = std::vector<uint32>;
    using Members = std::vector<Member>;

    uint32 poolId;
    uint32 numActive;
    Members members;
    std::unordered_set<uint32> activeQuests;
};

class TC_GAME_API QuestPoolMgr
{
    private:
        QuestPoolMgr() {}
        ~QuestPoolMgr() {}

    public:
        static QuestPoolMgr* instance();

        void LoadFromDB();
        void ChangeDailyQuests() { Regenerate(_dailyPools); }
        void ChangeWeeklyQuests() { Regenerate(_weeklyPools); }
        void ChangeMonthlyQuests() { Regenerate(_monthlyPools); }

        QuestPool const* FindQuestPool(uint32 poolId) const;
        bool IsQuestPooled(uint32 questId) const { return _poolLookup.find(questId) != _poolLookup.end(); }
        bool IsQuestActive(uint32 questId) const;

    private:
        void Regenerate(std::vector<QuestPool>& pools);
        std::vector<QuestPool> _dailyPools;
        std::vector<QuestPool> _weeklyPools;
        std::vector<QuestPool> _monthlyPools;
        std::unordered_map<uint32, QuestPool*> _poolLookup; // questId -> pool
};

#define sQuestPoolMgr QuestPoolMgr::instance()

#endif
