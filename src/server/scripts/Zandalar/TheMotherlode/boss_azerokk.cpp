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
#include "the_motherlode.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"

enum Spells
{
    SPELL_RAGING_GAZE_BEAM = 257582,
    SPELL_RAGING_GAZE_SELECTOR = 271526,
    SPELL_CALL_EARTHRAGER 	= 257593,
    SPELL_AZERITE_INFUSION_MISSILE = 271698,
    SPELL_JAGGED_CUT = 257543,
    SPELL_RESONANT_PULSE = 258622,
    SPELL_RESONANT_QUAKE = 258627,
    SPELL_TECTONIC_SMASH = 275907,

    SPELL_FRACKING_TOTEM_BUTTON = 257455,
    SPELL_FRACKING_TOTEM_CAST = 257480,
    SPELL_FRACKING_TOTEM_STUN = 257481,
    SPELL_FRACKING_TOTEM_SUMMON = 268204,
   
};

enum Events
{
    EVENT_FIXATE = 1,
    EVENT_AZERITE_INFUSION,
    EVENT_JAGGED_CUT,
    EVENT_CALL_EARTHRAGER,
    EVENT_RESONANT_PULSE,
    EVENT_RESONANT_QUAKE,
    EVENT_TECTONIC_SMASH,

    EVENT_TOTEM_TARGET,
};

enum Timers
{
    TIMER_AZERITE_INFUSION = 28 * IN_MILLISECONDS,
    TIMER_CALL_EARTHRAGER = 15 * IN_MILLISECONDS,
    TIMER_RESONANT_PULSE = 20 * IN_MILLISECONDS,
    TIMER_TECTONIC_SMASH = 40 * IN_MILLISECONDS,

    TIMER_TOTEM_TARGET = 2 * IN_MILLISECONDS,
};
enum Creatures
{
    BOSS_AZEROKK = 129227,
    NPC_EARTHRAGERS = 129802,
    NPC_FRACKING_TOTEM = 136500,
    NPC_FRACKING_TOTEM_PRE = 129804,
};

const Position centerPos = { 1215.50f, -3325.10f, 57.33f }; // 40y

enum SoundId
{
    SOUND_AZERITE_INFUSION = 97390,
    SOUND_CALL_EARTHRAGER = 97384,
    SOUND_RESONANT_PULSE = 97381,
    SOUND_TECTONIC_SMASH = 115344,
    SOUND_KILL = 97380,
    SOUND_DEATH = 97379,
    SOUND_AGGRO = 97385,
};

const Position earthragerPos[4] =
{
    { 1235.39f, -3324.67f, 56.98f },
    { 1213.96f, -3346.69f, 55.51f },
    { 1213.57f, -3304.01f, 55.71f },
    { 1194.62f, -3321.71f, 55.17f },
};

const Position frackingPos[2] =
{
    { 1183.08f, -3304.60f, 56.83f },
    { 1185.00f, -3301.67f, 56.67f },
};

#define AZERITE_INFUSION "You are not prepared!!!!"
#define CALL_EARTHRAGER "Burn..."
#define RESONANT_PULSE "Figth with me."
#define TECTONIC_SMASH "Arg"
#define KILL_TEXT "I will kill you"
#define DEATH_TEXT "Oh nooo..."
#define AGGRO_TEXT "Come here..."

void AddSC_boss_azerokk()
{
   
}
