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
 *
 *Original Script by Mindsear
 *Refactored by SPP Developer MDic
*/
#include "DBCStores.h"
#include "ScriptMgr.h"
#include "ArenaTeamMgr.h"
#include "Common.h"
#include "DisableMgr.h"
#include "BattlegroundMgr.h"
#include "Battleground.h"
#include "ArenaTeam.h"
#include "Language.h"
#include "World.h"
#include "Player.h"
#include "Chat.h"
#include "WorldSession.h"
#include "Log.h"
#include "ScriptedGossip.h"
#include "ScriptedCreature.h"
#include "CreatureAI.h"
#include "Config.h"

#ifndef ARENA_1V1_H
#define ARENA_1V1_H

bool config_Enable;
uint8 config_minLevel;
uint32 config_Costs;
bool config_VendorRating;
float config_ArenaPointsMulti;
bool config_BlockForbiddenTalents;

void TC1V1CONFIG()
{
    config_Enable = sConfigMgr->GetBoolDefault("Arena.1v1.Enable", true);
    config_minLevel = sConfigMgr->GetIntDefault("Arena.1v1.MinLevel", 255);
    config_Costs = sConfigMgr->GetIntDefault("Arena.1v1.Costs", 400000);
    config_BlockForbiddenTalents = sConfigMgr->GetBoolDefault("Arena.1v1.BlockForbiddenTalents", true);
}

// TalentTab.dbc -> TalentTabID
const uint32 FORBIDDEN_TALENTS_IN_1V1_ARENA[] =
{
    // Healer
    201, // PriestDiscipline
    202, // PriestHoly
    382, // PaladinHoly
    262, // ShamanRestoration
    282, // DruidRestoration

    // Tanks
    //383, // PaladinProtection
    //163, // WarriorProtection

    0 // End
};

// Return false, if player have invested more than 35 talentpoints in a forbidden talenttree.
static bool Arena1v1CheckTalents(Player* player)
{
    if (!player)
        return false;

    if (config_BlockForbiddenTalents == false)
        return true;

    uint32 count = 0;
    for (uint32 talentId = 0; talentId < sTalentStore.GetNumRows(); ++talentId)
    {
        TalentEntry const* talentInfo = sTalentStore.LookupEntry(talentId);

        if (!talentInfo)
            continue;

        for (int8 rank = MAX_TALENT_RANK - 1; rank >= 0; --rank)
        {
            if (talentInfo->SpellRank[rank] == 0)
                continue;

            if (player->HasTalent(talentInfo->SpellRank[rank], player->GetActiveSpec()))
            {
                for (int8 i = 0; FORBIDDEN_TALENTS_IN_1V1_ARENA[i] != 0; i++)
                    if (FORBIDDEN_TALENTS_IN_1V1_ARENA[i] == talentInfo->PrereqTalent)
                        count += rank + 1;
            }
        }
    }

    if (count >= 36)
    {
        ChatHandler(player->GetSession()).SendSysMessage("You can't join, because you have invested too many points in a forbidden talent. Please edit your talents.");
        return false;
    }
    else
        return true;
}

#endif
