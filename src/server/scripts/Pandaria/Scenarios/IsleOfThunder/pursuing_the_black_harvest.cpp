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

#include "pursuing_the_black_harvest.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "CreatureAI.h"
#include "MoveSplineInit.h"
#include "SpellScript.h"
#include "Vehicle.h"
#include "LFGMgr.h"

enum Spells
{
    SPELL_SEARCHING_FOR_INTRUDERS = 134110,
    SPELL_MULTI_SHOT = 41187,
    SPELL_NETTED = 134111,
    SPELL_HEX = 134202,
    SPELL_LIGHTNING = 42024,
    SPELL_BLACKOUT = 134112,
    SPELL_SOULRIFT = 134208,
    SPELL_SAP = 134205,
    SPELL_DEMONIC_GATEWAY_EFF = 138649,
    SPELL_PLACE_EMPOWERED_SOULCORE = 138680,
    SPELL_SONIC_STRIKE = 41168,
    SPELL_CLEAVE = 15284,
    SPELL_SHADOW_INFERNO = 39645,
    SPELL_FEAR = 41150,
    SPELL_DARK_MENDING = 16588,
    SPELL_SHADOW_BOLT = 34344,
    SPELL_SHADOW_SHOCK = 16583,
    SPELL_MELT_FLESH = 37629,
    SPELL_FIREBOLT = 134245,
    SPELL_SOUL_BLAST = 50992,
    SPELL_SHADOW_BOLT_2 = 12739,
    SPELL_ETERNAL_BANISHMENT = 139186,
    SPELL_PURGE_XERATTH = 139366,
    SPELL_CODEX_OF_XERATTH = 101508,
    SPELL_SPELLFLAME = 134234,
    SPELL_SPELLFLAME_EFF = 134235,
    SPELL_HELLFIRE = 134225,

    // Kanrethad
    SPELL_SUMMON_PIT_LORD = 138789,
    SPELL_DEMONIC_GRASP = 139142,
    SPELL_AURA_OF_OMNIPOTENCE = 138563,
    SPELL_CATACLYSM = 138564,
    SPELL_EX_AGONY = 138560,
    SPELL_RAIN_OF_FIRE = 138561,
    SPELL_BACKFIRE = 138619,
    SPELL_SUMMON_WILD_IMPS = 138685,
    SPELL_BURNING_EMBERS = 138557,
    SPELL_SOUL_SHARDS = 138556,
    SPELL_CHAOS_BOLT = 138559,
    SPELL_ANNIHILATE_DEMONS = 139141,
    SPELL_SEED_OF_DESTRUCTION = 138587,
    SPELL_CURSE_OF_ULTIMATE_DOON = 138558,
    SPELL_SUMMON_FELHUNTERS = 138751,
    SPELL_SOUL_FIRE = 138554,

    // Green Fire
    SPELL_DRAIN_ENERGY = 139200,
    SPELL_FEEL_ENERGY_SPIN = 140164,
    SPELL_FEEL_ENERGY_GREEN_LIGHT = 140136,
    SPELL_FEEL_ENERGY_GOLDEN_ORB = 140137,
    SPELL_FEEL_ENERGY_GREEN_BALL = 140160,
    SPELL_FEEL_ENERGY_BIG_BALL = 140161,
    SPELL_FEEL_ENERGY_EXPLOSION = 140163,
    SPELL_FEEL_ENERGY_VEHICLE = 140116,
};

enum Events
{
    EVENT_MULTI_SHOT,
    EVENT_HEX,
    EVENT_LIGHTNING,
    EVENT_SONIC_STRIKE,
    EVENT_CLEAVE,
    EVENT_SHADOW_INFERNO,
    EVENT_FEAR,
    EVENT_DARK_MENDING,
    EVENT_SHADOW_BOLT,
    EVENT_SHADOW_SHOCK,
    EVENT_MELT_FLESH,
    EVENT_FIREBOLT,
    EVENT_SOUL_BLAST,
    EVENT_SPELLFLAME,
    EVENT_HELLFIRE,

    // Affliction
    EVENT_EX_AGONY,
    EVENT_BACKFIRE,
    EVENT_SEED_OF_DESTRUCTION,
    EVENT_CURSE_OF_ULTIMATE_DOOM,
    EVENT_AURA_OF_OMNIPOTENCE,

    // Destruction
    EVENT_CATACLYSM,
    EVENT_RAIN_OF_FIRE,
    EVENT_CHAOS_BOLT,
    EVENT_SOUL_FIRE,
    EVENT_SUMMON,
};

enum Phases
{
    PHASE_DESTRUCTION,
    PHASE_AFFLICTION,
};

void AddSC_pursuing_the_black_harvest()
{
    
}