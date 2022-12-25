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
#include "nyalotha.h"

enum Texts
{
    SAY_AGGRO = 0,
    SAY_SHATTERED_EGO,
    SAY_VOID_GAZE,
    SAY_MINDGRASP,
    SAY_MINDGATE,
    SAY_CORRUPTING_OF_DEATHWING,
    SAY_SERVANT,
    SAY_WIPE
};

enum Spells
{
    SPELL_SANITY_BAR = 308997,
    SPELL_GIFT_OF_NZOTH = 313609,
    SPELL_MENTAY_DECAY_PERIODIC_AND_BURN = 313610,
    SPELL_SERVANT_OF_NZOTH_CONTROL = 308996,
    SPELL_AZEROTHS_RADIANCE_EXTRA_BUTTON = 310564,
    SPELL_MINDGRASP_CHANNEL = 315772,
    SPELL_MINDGRASP_PULL = 315876,
    SPELL_MINDGRASP_PUSH = 310073,
    SPELL_ETERNAL_TORMENT_AURA_TRIGGER = 318449,
    SPELL_CATACLYSMIC_FLAMES_MISSILE = 313789,
    SPELL_STUPEFYING_GLARE_CREATE_AT = 318975,
    SPELL_SANITY_SCREEN_EFFECT = 317324,
    SPELL_SANITY_RED_EFFECT_SOUND = 318336,
    SPELL_SANITY_SCREEN_EFFECT_2 = 316295,
    SPELL_PROBE_MIND = 314889,
    SPELL_BERSERK = 64238,
    SPELL_TRANDESCENT_POWER = 317639,
    SPELL_SUMMON_GATEWAY = 318091,
    SPELL_COLLAPSING_MINDSCAPE = 317292,
    SPELL_CLEANSING_PROTOCOL = 319349,
    SPELL_CLEANSING_PROTOCOL_DAMAGE = 316971,
    SPELL_MINDGATE_CREATE_AT = 316463,
    SPELL_DARK_MATTER = 318971,
};

enum Psychus
{
    EVENT_MANIFEST_MADNESS = 1,
    SPELL_MANIFEST_MADNESS = 310134,
    SPELL_SYNAPTIC_SHOCK = 313184,
    EVENT_MINDWRACK = 2,
    SPELL_MINDWRACK = 316711,
    EVENT_CREEPING_ANQUISH = 3,
    SPELL_CREEPING_ANQUISH_CREATE_AT = 310184,
    SPELL_CREEPING_ANQUISH_DAMAGE = 309991,
    SPELL_SHATTERED_EGO_STUN = 315672,
    SPELL_PERIODIC_ENERGY_GAIN = 299956,
    SPELL_MANIFEST_MADNESS_WAVE = 310135,
    EVENT_MANIFEST_MADNESS_DUMMY_TICK = 4,
    SPELL_ETERNAL_HATRED = 310130,
    SPELL_ETERNAL_HATRED_2 = 310128,

};

enum Events
{
    EVENT_BERSERK = 1,
    EVENT_ETERNAL_HUNGER,
    EVENT_MINDGRASP,
    EVENT_CATACLYSMIC_FLAMES,
    EVENT_STUPEFYING_GLARE,
    EVENT_HARVESTER
};

enum Misc
{
    ACHIEVEMENT_MYTHIC_NZOTH_THE_CORRUPTOR = 14055,
    SCENE_DEATH_OF_NZOTH = 2740,
    ACTION_INIT_PHASE_2,
    ACTION_MINDGATE,
    NZOTH_ENCOUNTER_ID = 2344,
};

const Position synapses_pos = { -11129.0f, 9312.0f, 125.866f, 0.0f };
const Position psychus_pos = { -11194.0f, 9323.0f, 125.865f, 3.0f };
const Position basher_tentacle_pos_1 = { -11099.0f, 9278.0f, 125.866f, 2.2f };
const Position basher_tentacle_pos_2 = { -11099.0f, 9278.0f, 125.866f, 2.2f };
const Position harvester_pos = { -11157.0f, 9321.0f, 125.866f, 3.0f };

void AddSC_nzoth()
{
    
};
