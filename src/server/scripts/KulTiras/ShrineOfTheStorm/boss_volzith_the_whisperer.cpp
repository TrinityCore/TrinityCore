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

#include "PhasingHandler.h"
#include "PlayerAI.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "ScriptMgr.h"
#include "shrine_of_the_storm.h"
#include "InstanceScript.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"

enum Volzith
{
    SPELL_CHANNEL                               = 274175,
    SPELL_VOID_ENERGY_DISABLE_REGEN             = 267255,
    SPELL_VOID_ENERGY_DO_REGEN                  = 267260,

    SPELL_YAWNING_GATE                          = 269399,
    SPELL_YAWNING_GATE_AURA = 269419,

    SPELL_TENTACLE_SLAM                         = 267364,
    SPELL_TENTACLE_SLAM_SUMMON = 267382,
    SPELL_TENTACLE_SLAM_DMG                     = 267385,

    SPELL_WHISPERS_OF_POWER                     = 267034,
    SPELL_WHISPERS_OF_POWER_AURA                = 267037,
    SPELL_OLD_TONGUE                            = 274551,

    SPELL_GRASP_OF_THE_SUNKEN_CITY              = 267360, // target entry 140038
    SPELL_GRASP_OF_THE_SUNKEN_CITY_CHANNEL      = 267444,
    SPELL_GRASP_OF_THE_SUNKEN_CITY_DPS_PHASE    = 278209, // 267425 phaseid 10745 need to implement SPELL_AURA_164 - start drowning
    SPELL_GRASP_OF_THE_SUNKEN_CITY_TANK_PHASE   = 274556, // 267442 phaseid 10747

    SPELL_CALL_THE_ABYSS                        = 267299,
    SPELL_CALL_THE_ABYSS_SUMMON = 267306,

    SPELL_THE_SUNKEN_CITY                       = 267524,
    SPELL_CONSUME_ESSENCE                       = 267809,

    SPELL_LEVIATHANS_WAKE                       = 267548,

    SPELL_ABYSSAL_ERUPTION_DMG                  = 267310,
    SPELL_ABYSSAL_ERUPTION_ENERGIZE             = 267311,
};

static Position const spawnPoints[3] =
{
    { 3658.58f, -1715.67f, 85.89f },
    { 3603.31f, -1742.71f, 85.82f },
    { 3619.73f, -1709.18f, 86.14f },
};

static Position const manifestSpawnPoints[15] =
{
    { 3675.83f, -1688.60f, 83.4349f },
    { 3656.23f, -1675.91f, 83.8259f },
    { 3636.15f, -1673.52f, 83.3167f },
    { 3621.70f, -1673.33f, 84.4263f },
    { 3611.91f, -1678.02f, 83.5110f },
    { 3593.11f, -1687.05f, 84.3794f },
    { 3575.16f, -1698.99f, 83.5286f },
    { 3570.94f, -1714.89f, 83.6414f },
    { 3570.48f, -1730.42f, 83.3317f },
    { 3576.01f, -1751.30f, 83.4642f },
    { 3581.68f, -1761.81f, 83.5611f },
    { 3594.58f, -1772.18f, 83.6898f },
    { 3610.53f, -1783.90f, 83.6852f },
    { 3624.24f, -1788.61f, 82.8457f },
    { 3635.22f, -1786.49f, 84.6600f },
};

enum Creatures
{
    BOSS_VOLZITH_THE_WHISPERER = 134069,

    NPC_FORGOTTEN_DENIZEN = 136297,
    NPC_SUNKEN_DENIZEN = 136100,
    NPC_TENTACLE = 135987,
    NPC_MANIFESTATION_OF_THE_DEEP = 135903,
};

enum Events
{
    EVENT_YAWNING_GATE = 1,
    EVENT_TENTACLE_SUMMON,
    EVENT_WHISPER_OF_POWER,

    EVENT_ADD_POWER,
    EVENT_GRASP_OF_THE_SUNKEN_CITY,

    EVENT_CONSUME_ESSENCE,

    EVENT_CALL_THE_ABYSS,

    EVENT_TENTACLE_SLAM,
};

enum Timers
{
    TIMER_YAWNING_GATE = 15 * IN_MILLISECONDS,
    TIMER_TENTACLE_SUMMON = 12 * IN_MILLISECONDS,
    TIMER_WHISPERS_OF_POWER = 30 * IN_MILLISECONDS,
    TIMER_CALL_THE_ABYSS = 45 * IN_MILLISECONDS,

    TIMER_CONSUME_ESSENCE = 11 * IN_MILLISECONDS,

    TIMER_ADD_POWER = 3 * IN_MILLISECONDS,

    TIMER_TENTACLE_SLAM = 8 * IN_MILLISECONDS
};

const Position centerPos = { 3631.75f, -1728.81f, 105.55f  }; //cheaters 80y

enum Actions
{
    ACTION_COUNT_DPS_PHASE = 1,
    ACTION_COUNT_TANK_HEAL_PHASE = 2,
};

enum SoundIds
{
    SOUND_1 = 103098,
    SOUND_2 = 103110,

    SOUND_5 = 103104,
};

#define INTRO_TEXT_VOID "Ugalazul bwrxil' qu rax"
#define INTRO_TEXT "Darkness roots. Pestilence spreads. The doorway is open"

#define AGGRO_TEXT_VOID "Aglathrax hig' thrixa."
#define AGGRO_TEXT "I reside within your lungs!"

#define GRASP_TEXT_VOID "Skitsh qi'uthik illith!"
#define GRASP_TEXT "Beneath the tides, your truth awaits."

#define ABYSS_TEXT_VOID "Kril lax qutholil!"
#define ABYSS_TEXT "The crawling ones have awakened!"

#define KILL_TEXT_VOID "Krax il' oni OGOG!"
#define KILL_TEXT "Listen to the music of the drowned."

#define DEATH_TEXT_VOID "Bwixki amala zal qullllll...."
#define DEATH_TEXT "I will await you... in the dark..."

void AddSC_boss_volzith_the_whisperer()
{
    
}
