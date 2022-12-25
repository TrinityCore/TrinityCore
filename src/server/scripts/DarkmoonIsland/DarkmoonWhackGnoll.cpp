/*
 * Copyright 2023 AzgathCore
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
#include "DarkmoonIsland.h"
#include "ScriptedGossip.h"

enum whackCreatures
{
    NPC_BARREL              = 54546,
    NPC_GNOLL               = 54444,
    NPC_DOLL                = 54466,
    NPC_BOSS                = 54549,
};

enum whackSpells
{
    SPELL_OVERRIDE_ACTION   = 101612,
    SPELL_ENABLE_POWERBAR   = 110230,
    SPELL_ACTIONBAR_REMOVE  = 102137,
    SPELL_WHACK             = 101604,
    SPELL_KILL_CREDIT       = 101835,
    SPELL_DOLL_STUN         = 101679,

    SPELL_SPAWN_VISUAL      = 102136,
    SPELL_OK_TO_HIT         = 101996,

    SPELL_SUMMON_GNOLL      = 102036,
    SPELL_SUMMON_DOLL       = 102043,
    SPELL_SUMMON_BOSS       = 102044,

    SPELL_FORBIDDEN_ZONE    = 109977,
};

enum whackEvents
{
    EVENT_SUMMON_GNOLL      = 1,
    EVENT_SUMMON_DOLL       = 2,
    EVENT_SUMMON_BOSS       = 3,

    EVENT_CHECK_PLAYER_POS  = 4
};

#define QUEST_WHACK_A_GNOLL 29463

#define MAX_BARRELS         9

#define GNOLL_TIMER         3  * IN_MILLISECONDS
#define DOLL_TIMER          6  * IN_MILLISECONDS
#define BOSS_TIMER          10 * IN_MILLISECONDS

void AddSC_darkmoon_whack_gnoll()
{
  
};
