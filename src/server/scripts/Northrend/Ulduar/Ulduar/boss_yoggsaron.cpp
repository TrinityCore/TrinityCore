/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
    SAY_PHASE2_1                                = -1603330,
    SAY_PHASE2_2                                = -1603331,
    SAY_PHASE2_3                                = -1603332,
    SAY_PHASE2_4                                = -1603333,
    SAY_PHASE2_5                                = -1603334,
    SAY_PHASE3                                  = -1603335,
    SAY_VISION                                  = -1603336,
    SAY_SLAY_1                                  = -1603337,
    SAY_SLAY_2                                  = -1603338,
    WHISP_INSANITY_1                            = -1603339,
    WHISP_INSANITY_2                            = -1603340,
    SAY_DEATH                                   = -1603341,
};

enum
{
    ACHIEV_TIMED_START_EVENT                      = 21001,
};
//not in scriptloader yet just to remove warning boss_yoggsaron.obj : warning LNK4221: no public symbols found; archive member will be inaccessible
void AddSC_boss_yoggsaron()
{
}
