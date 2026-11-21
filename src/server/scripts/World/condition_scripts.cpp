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

#include "ConditionMgr.h"
#include "Object.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "World.h"

namespace Scripts::World::ConditionScripts
{
    class condition_player_dual_talent_specialization : public ConditionScript
    {
    public:
        condition_player_dual_talent_specialization() : ConditionScript("condition_player_dual_talent_specialization") { }

        bool OnConditionCheck(Condition const* condition, ConditionSourceInfo& sourceInfo) override
        {
            Player const* player = Object::ToPlayer(sourceInfo.mConditionTargets[condition->ConditionTarget]);
            if (!player)
                return false;

            uint8 dualSpecMinLevel = static_cast<uint8>(::sWorld->getIntConfig(CONFIG_MIN_DUALSPEC_LEVEL));
            if (player->GetLevel() < dualSpecMinLevel)
                return false;

            return player->GetTalentGroupCount() < 2;
        }
    };
}

void AddSC_condition_scripts()
{
    using namespace Scripts::World::ConditionScripts;
    new condition_player_dual_talent_specialization();
}
