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

#include "ScriptMgr.h"
#include "Battleground.h"
#include "ConditionMgr.h"
#include "Map.h"

class condition_is_shadow_sight_enabled : public ConditionScript
{
public:
    condition_is_shadow_sight_enabled() : ConditionScript("condition_is_shadow_sight_enabled") { }

    bool OnConditionCheck(Condition const* /*condition*/, ConditionSourceInfo& sourceInfo) override
    {
        if (!sourceInfo.mConditionMap)
            return false;

        if (BattlegroundMap const* bgMap = sourceInfo.mConditionMap->ToBattlegroundMap())
            if (Battleground const* bg = bgMap->GetBG())
                if (bg->GetStatus() >= STATUS_IN_PROGRESS)
                    return bg->GetInProgressDuration() >= 90s;

        return false;
    }
};

void AddSC_arena_scripts_generic()
{
    new condition_is_shadow_sight_enabled();
}
