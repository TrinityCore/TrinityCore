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

#include "Creature.h"
#include "GridNotifiersImpl.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "Unit.h"

enum eBosses
{
    BOSS_SHA_OF_ANGER
};

enum eSpells
{
    SPELL_SHADOW_BOLT_ANGER = 119487,
    SPELL_OVERCOME_BY_ANGER = 129356,
    SPELL_ENDLESS_RAGE = 119446,
    SPELL_BITTER_THOUGHTS = 119601,
    SPELL_BERSERK = 47008,
    SPELL_DOMINATE_MIND_WARNING = 119622,
    SPELL_DOMINATE_MIND = 119626,
    SPELL_SEETHE_AURA = 119487,
    SPELL_SHA_OF_ANGER_BONUS = 132205
};

enum eEvents
{
    EVENT_GROWING_ANGER_WARNING = 1,
    EVENT_GROWING_ANGER = 2,
    EVENT_UNLEASHED_WRATH = 3,
    EVENT_BERSERK = 4,
    EVENT_DESPAWN = 5,
    EVENT_SPAWN = 6,
    EVENT_UPDATE_RAGE = 7,
    EVENT_RANGE_ATTACK = 8
};

enum eCreatures
{
    CREATURE_SHA_OF_ANGER = 56439
};

enum eTalk
{
    TALK_INTRO = 0,
    TALK_ANGER = 1,
    TALK_SPAWN = 2,
    TALK_RESET = 3,
    TALK_SLAY = 4,
    TALK_AGGRO = 5
};

void AddSC_boss_sha_of_anger()
{
    
}
