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
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "the_motherlode.h"
#include "ScriptedCreature.h"
#include "SpellHistory.h"

enum Spells
{
    SPELL_PILES_OF_GOLD_VISUAL = 271801,
    SPELL_STATIC_PULSE = 262347,
    SPELL_FOOTBOMB_LAUNCHER = 269493,
    SPELL_PAY_TO_WIN = 271867,
    SPELL_SHOCKING_CLAWS = 257337,
    SPELL_COIN_MAGNET = 271903,
    SPELL_BLAZING_AZERITE = 256163,
    SPELL_BLAZING_AZERITE_BOSS = 256493,
    SPELL_BLAZING_AZERITE_PLAYERS = 270882,
    SPELL_BOMB_TIMER = 256054,
};

enum Events
{
    EVENT_THROW_COINS = 1,
    EVENT_FOOTBOMB_LAUNCHER,
    EVENT_SHOCKING_CLAW,
    EVENT_DETONATE,
    EVENT_STATIC_PULSE,
    EVENT_COIN_MAGNET,
};

enum Timers
{
    TIMER_STATIC_PULSE = 10 * IN_MILLISECONDS,
    TIMER_FOOTBOMB_LAUNCHER = 17 * IN_MILLISECONDS,
    TIMER_SHOCKING_CLAW = 25 * IN_MILLISECONDS,
    TIMER_COIN_MAGNET = 10 * IN_MILLISECONDS,
    TIMER_THROW_COINS = 35 * IN_MILLISECONDS,
    TIMER_DETONATE = 15 * IN_MILLISECONDS,
};

enum Creatures
{
    BOSS_CO_CROWD_PLUMMELER = 129214,
    NPC_AZERITE_FOOTBOMB = 129246,
    NPC_PILE_OF_GOLD = 138083,
};

enum DisplayId
{
    DISPLAY_BOMB = 49134,
};

enum Actions
{
    ACTION_JUMP = 1,
    ACTION_INIT_SPELL,
};

const Position centerPos = { 1000.73f, -3556.13f, 13.01f }; //55y

enum SoundId
{
    SOUND_AGGRO = 97384,
    SOUND_STATIC = 97381,
    SOUND_SHOCKING_CLAW = 97380,
    SOUND_DEATH = 97385,
    SOUND_COIN_MAGNET = 97379,
};

#define AGGRO_TEXT "Systems engaged. Commence pummeling."
#define STATIC_PULSE "Voltage increased."
#define SHOCKING_CLAW "Lethal force authorized."
#define DEATH_TEXT "Systems... failing. Coin release... malfunction..."
#define COIN_MAGNET "Damaging this unit violates the terms of use."

void AddSC_boss_Coin_operated_crowd_pummeler()
{
    
}
