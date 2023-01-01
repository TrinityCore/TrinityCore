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

#include "GameTime.h"
#include "ScriptMgr.h"
#include "Util.h"
#include "World.h"

namespace
{
    bool IsXPBoostActive()
    {
        time_t time = GameTime::GetGameTime();
        tm localTm = TimeBreakdown(time);
        uint32 weekdayMaskBoosted = sWorld->getIntConfig(CONFIG_XP_BOOST_DAYMASK);
        uint32 weekdayMask = (1 << localTm.tm_wday);
        bool currentDayBoosted = (weekdayMask & weekdayMaskBoosted) != 0;
        return currentDayBoosted;
    }
}

class xp_boost_PlayerScript : public PlayerScript
{
public:
    xp_boost_PlayerScript() : PlayerScript("xp_boost_PlayerScript") { }

    void OnGiveXP(Player* /*player*/, uint32& amount, Unit* /*unit*/) override
    {
        if (IsXPBoostActive())
            amount *= sWorld->getRate(RATE_XP_BOOST);
    }
};

void AddSC_xp_boost()
{
    new xp_boost_PlayerScript();
}
