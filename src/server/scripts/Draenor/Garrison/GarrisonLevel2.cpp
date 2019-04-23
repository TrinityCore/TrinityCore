/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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
    QUEST_MY_VERY_OWN_FORTRESS  = 36614,
    QUEST_MY_VERY_OWN_CASTLE    = 36615,
};

/*
 * Common scripts for garrison level 2 Alliance & Horde
 */
struct garrison_level_2 : public GarrisonAI
{
    garrison_level_2(Garrison* gar) : GarrisonAI(gar) { }

    bool OnCheckUpgradeable() override
    {
        return garrison->GetOwner()->HasQuest(QUEST_MY_VERY_OWN_FORTRESS) ||
               garrison->GetOwner()->HasQuest(QUEST_MY_VERY_OWN_CASTLE);
    }
};

struct garrison_level_2_alliance : public garrison_level_2
{
    garrison_level_2_alliance(Garrison* gar) : garrison_level_2(gar) { }
};

struct garrison_level_2_horde : public garrison_level_2
{
    garrison_level_2_horde(Garrison* gar) : garrison_level_2(gar) { }
};

void AddSC_garrison_level_2()
{
    RegisterGarrisonAI(garrison_level_2_alliance);
    RegisterGarrisonAI(garrison_level_2_horde);
};
