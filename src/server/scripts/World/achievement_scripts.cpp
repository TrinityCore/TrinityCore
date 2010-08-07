/*
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "ScriptPCH.h"

class achievement_school_of_hard_knocks : public AchievementCriteriaScript
{
    public:
        achievement_school_of_hard_knocks() : AchievementCriteriaScript("achievement_school_of_hard_knocks") { }

        bool OnCheck(Player* source, Unit* /*target*/)
        {
            static uint32 const orphanEntries[6] = {14305, 14444, 22818, 22817, 33533, 33532};
            uint32 currentPet = GUID_ENPART(source->GetCritterGUID());
            for (uint8 i = 0; i < 6; ++i)
                if (currentPet == orphanEntries[i])
                    return true;

            return false;
        }
};

class achievement_storm_glory : public AchievementCriteriaScript
{
    public:
        achievement_storm_glory() : AchievementCriteriaScript("achievement_storm_glory") { }

        bool OnCheck(Player* source, Unit* /*target*/)
        {
            if (source->GetBattleGroundTypeId() != BATTLEGROUND_EY)
                return false;

            BattleGround *pEotS = source->GetBattleGround();
            if (!pEotS)
                return false;

            return pEotS->IsAllNodesConrolledByTeam(source->GetTeam());
        }
};

void AddSC_achievement_scripts()
{
    new achievement_school_of_hard_knocks;
    new achievement_storm_glory;
}
