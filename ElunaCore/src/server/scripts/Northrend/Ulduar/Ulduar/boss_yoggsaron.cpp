/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "ulduar.h"

enum Sara
{
    // text
    YELL_SARA_PREFIGHT                          = 0,
    YELL_COMBAT_PHASE_1                         = 1,
    YELL_COMBAT_PHASE_2                         = 2,
    YELL_SLAY                                   = 3,

    // Phase 1 spells
    SPELL_SARAS_ANGER_1                         = 63147, // Target Entry 33136
    SPELL_SARAS_ANGER_2                         = 63744, // Target Entry 33136
    SPELL_SARAS_FEVOR_1                         = 63138, // Target Player
    SPELL_SARAS_FEVOR_2                         = 63747, // Target Player
    SPELL_SARAS_BLESSING_1                      = 63134, // Target Player
    SPELL_SARAS_BLESSING_2                      = 63745, // Target Self

    // Phase 2 spells
    SPELL_PHYCHOSIS                             = 63795, // Target Self
    SPELL_MALADY_OF_THE_MIND                    = 63830, // Target Self
    SPELL_DEATH_RAY                             = 63891, // Target Self
    SPELL_BRAIN_LINK                            = 63802, // Target Self
};

enum YoggSaron_Yells
{
};

enum
{
    ACHIEV_TIMED_START_EVENT                      = 21001,
};
//not in scriptloader yet just to remove warning boss_yoggsaron.obj : warning LNK4221: no public symbols found; archive member will be inaccessible
void AddSC_boss_yoggsaron()
{
}
