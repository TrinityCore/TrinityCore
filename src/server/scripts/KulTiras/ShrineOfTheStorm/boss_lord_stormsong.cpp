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
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "PlayerAI.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "shrine_of_the_storm.h"

enum Stormsong
{
    SPELL_VOID_BOLT = 268347,
    SPELL_MIND_REND = 268896,

    SPELL_WAKEN_THE_VOID = 269097,
    SPELL_WAKEN_THE_VOID_MISSILE = 269021,
    SPELL_WAKEN_THE_VOID_AURA = 269094,
    SPELL_FIXATE = 269103,
    SPELL_EXPLOSIVE_VOID = 269104,

    //mind control stuff
    SPELL_ANCIENT_MINDBENDER = 269131,
    SPELL_SURRENDER_TO_THE_VOID = 269242,
    SPELL_DISCIPLE_OF_THE_VOLZITH = 269289, // visual id

    SPELL_VOID_BOLT_VOLLEY = 269282,
};

enum Creatures
{
    BOSS_LORD_STORMSONG = 134060,
};

enum Events
{
    EVENT_VOID_BOLT = 1,
    EVENT_WAKEN_THE_VOID,
    EVENT_FIXATE,
    EVENT_ANCIENT_MINDBENDER,
    EVENT_MIND_REND,
};

enum Timers
{
    TIMER_FIXATE_PLAYER = 1500,
    TIMER_VOID_BOLT = 5 * IN_MILLISECONDS,
    TIMER_WAKEN_THE_VOID = 30 * IN_MILLISECONDS,
    TIMER_MIND_REND = 22 * IN_MILLISECONDS,
    TIMER_ANCIENT_MINDBENDER = 40 * IN_MILLISECONDS,
};

const Position cheatersCheck = { 3560.75f, -1484.49f, 153.31f };

#define AGGRO_TEXT "Intruders?! I shall cast your bodies to the blackened depths, to be crushed for eternity!"

void AddSC_boss_lord_stormsong()
{
   
}
