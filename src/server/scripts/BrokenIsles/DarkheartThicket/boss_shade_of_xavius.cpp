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
#include "ScriptedCreature.h"
#include "darkheart_thicket.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_DEATH = 1,
    SAY_END = 0,
};

enum Spells
{
    SPELL_SHADE_VISUAL = 195106,
    SPELL_FESTERING_RIP = 200182,
    SPELL_NIGHTMARE_BOLT = 204808,
    SPELL_FEED_ON_THE_WEAK = 200238,
    SPELL_INDUCED_PARANOIA = 200359,
    SPELL_COWARDICE = 200273,

    //Final Phase 50%HP
    SPELL_PHASE_CHANGE_CONVERSATION = 199857, //deprecated
    SPELL_APOCOLYPTIC_NIGHTMARE = 200050,
    SPELL_DRAIN_ESSENCE = 199837, //deprecated

    //Cage
    SPELL_NIGHTMARE_SHIELD = 204511,
    SPELL_NIGHTMARE_BINDINGS = 199752,

    //Malfurion
    SPELL_NATURE_RECOVERY = 204680,
    SPELL_ESCAPES_CONVERSATION = 199912,
    SPELL_NATURE_DOMINANCE = 199922, //deprecated
};

enum eEvents
{
    EVENT_FESTERING_RIP = 1,
    EVENT_NIGHTMARE_BOLT = 2,
    EVENT_FEED_ON_THE_WEAK = 3,
    EVENT_INDUCED_PARANOIA = 4,
    EVENT_FINAL_PHASE = 5,
};

enum Misc
{
    DATA_STACKS = 221315,
    EVENT_1,
    ACTION_1,
};

void AddSC_boss_shade_of_xavius()
{
    
}
