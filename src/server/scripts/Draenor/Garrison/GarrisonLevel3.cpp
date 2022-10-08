/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "Garrison.h"
#include "GarrisonAI.h"
#include "Player.h"
#include "ScriptMgr.h"

enum Quests
{
    QUEST_MY_VERY_OWN_FORTRESS = 36614,
    QUEST_MY_VERY_OWN_CASTLE = 36615,
};

/*
 * Common scripts for garrison level 3 Alliance & Horde
 */
struct garrison_level_3 : public GarrisonAI
{
    garrison_level_3(Garrison* gar) : GarrisonAI(gar) { }

    bool OnCheckUpgradeable() override
    {
        return false;
    }

    void OnUpgrade(Player* player) override
    {
        if (garrison->GetOwner()->HasQuest(QUEST_MY_VERY_OWN_FORTRESS))
            garrison->GetOwner()->ForceCompleteQuest(QUEST_MY_VERY_OWN_FORTRESS);
        if (garrison->GetOwner()->HasQuest(QUEST_MY_VERY_OWN_CASTLE))
            garrison->GetOwner()->ForceCompleteQuest(QUEST_MY_VERY_OWN_CASTLE);
    }
};

struct garrison_level_3_alliance : public garrison_level_3
{
    garrison_level_3_alliance(Garrison* gar) : garrison_level_3(gar) { }
};

struct garrison_level_3_horde : public garrison_level_3
{
    garrison_level_3_horde(Garrison* gar) : garrison_level_3(gar) { }
};

void AddSC_garrison_level_3()
{
    RegisterGarrisonAI(garrison_level_3_alliance);
    RegisterGarrisonAI(garrison_level_3_horde);
};
