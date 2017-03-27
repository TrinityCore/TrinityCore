/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#include "GameTime.h"
#include "ScriptMgr.h"
#include "World.h"

#include <boost/date_time/posix_time/posix_time.hpp>

namespace
{
    bool IsWeekendActive()
    {
        int32 const weekendXPDays = static_cast<int32>(sWorld->getIntConfig(CONFIG_WEEKEND_XP_DAYS));

        tm const now = boost::posix_time::to_tm(boost::posix_time::from_time_t(GameTime::GetGameTime()));
        int32 const days = 7 - ((now.tm_wday + 6) % 7);

        return days <= weekendXPDays;
    }
}

class weekend_xp_FormulaScript : public FormulaScript
{
    public:
        weekend_xp_FormulaScript() : FormulaScript("weekend_xp_FormulaScript") { }

        void OnGainCalculation(uint32& gain, Player* /*player*/, Unit* /*unit*/) override
        {
            if (IsWeekendActive())
                gain *= sWorld->getRate(RATE_XP_WEEKEND);
        }
};

void AddSC_weekend_xp()
{
    new weekend_xp_FormulaScript();
}
