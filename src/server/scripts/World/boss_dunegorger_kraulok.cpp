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
#include "world_bosses_zuldazar.h"

enum Events{
    EVENT_SHAKE_LOSE   = 1,
    EVENT_PRIMAL_RAGE  = 2,
    EVENT_SONIC_BELLOW = 3,
};

enum Spells {
    SPELL_SHAKE_LOSE          = 276046,
    SPELL_PRIMAL_RAGE         = 275200,
    SPELL_SONIC_BELLOW        = 275175,
    SPELL_SHAKE_LOSE_DMG      = 276055,
    SPELL_SHAKE_LOSE_SUMMON   = 276053,
    SPELL_SONIC_BELLOW_VISUAL = 275177,
};

void AddSC_boss_dunegorger_kraulok()
{
    
}
