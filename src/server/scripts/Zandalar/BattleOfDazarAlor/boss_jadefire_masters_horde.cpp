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
#include "Creature.h"
#include "CreatureAI.h"
#include "Unit.h"
#include "UnitAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "MotionMaster.h"
#include "battle_of_dazaralor.h"

const Position living_bomb_pos_a = { -1853.448f, 778.556f, 53.784f, 0.025f };
const Position living_bomb_pos_b = { -1811.786f, 801.702f, 53.390f, 0.033f };
const Position living_bomb_pos_c = { -1854.693f, 831.997f, 53.783f, 3.206f };
const Position at_60_energy_pos = { -905.0f, 847.0f, 369.0f, 4.6f };
const Position center_of_room = { -909.0f, 805.0f, 369.0f, 3.1f };
const Position spirit_of_xuen_pos = { -905.0f, 786.0f, 369.0f, 1.6f };
const Position magma_trap_a = { -891.0f, 818.0f, 369.0f, 3.f };
const Position magma_trap_b = { -892.0f, 810.0f, 369.0f, 3.f };
const Position magma_trap_c = { -892.0f, 798.0f, 369.0f, 3.f };
const Position magma_trap_d = { -892.0f, 798.0f, 369.0f, 3.f };
const Position manceroy_tele_pos = { -898.0f, 736.0f, 369.0f, 1.6f }; // used for barrier phase
const Position mestrah_tele_pos = { -917.0f, 733.0f, 369.0f, 1.58f }; // used for barrier phase

enum Spells
{
    PERIODIC_ENERGY_GAIN = 299956,
    //Monk
    MULTI_SIDED_STRIKE = 284028,
    SUCCESSFUL_DEFENSE = 284089,
    TESTED = 288151,
    ROLL = 109131,
    WHIRLING_JADE_STORM = 286436,
    //Mage
    FIREBALL = 282036, //cast 2s
    RISING_FLAMES = 282037, //triggers burnout, after expire/remove
    BURNOUT = 282041,
    FIRE_SHIELD = 286425,
    PYROBLAST = 286379,
    SEARING_EMBERS = 286988, //5 targets
    UNLEASHED_EMBER = 286989,
    //Team attacks
    FIRE_FROM_MIST = 285428, // at 30 energy, summon two adds npc 146107, on mythic 3, they're stationary, displayid 90376
    BEAM_DAMAGE_AURA = 286503,
    EXPLOSION = 284399,
    //A Flash of Hostility used by Monk, at 60 energy, 
    //BARRIER npc, 147374, displayid 90015
    FLASH_OF_PHOENIXES = 284669,
    RING_OF_HOSTILITY_MESTRAH_PERIODIC_DUMMY = 297568,
    RING_OF_HOSTILITY_KNOCKBACK = 284146,
    PHOENIX_STRIKE_MISSILE = 282043,
    PHOENIX_STRIKE_DAMAGE = 284388,
    //Transmorms, at 100 energy, both bosses transform
    DRAGONS_BREATH = 286396,
    BLAZING_PHOENIX_TRANSFORM = 282040, //npc 147536, 89730 displayid    
    SPIRITS_OF_XUEN = 285645,
    TIGER_PAW = 285634,
    POUNCE = 286086,
    MAGMA_TRAP_MISSILE_TRIGGER = 284373, //on spellhitdest summon trap, spell 282038
    MAGMA_TRAP_KNOCK = 284374,
    MAGMA_TRAP_2 = 98170,
    FORCE_ORB_REDUCE_MOVEMENT_SPEED = 287747,
    PATH_OF_NIUAZUO_SUMMON = 287623, // npc 148344
    PATH_OF_NIUAZUO_AT_DAMAGE = 287615
};

enum Events
{
    EVENT_WHIRLING_JADE_STORM = 1,
    EVENT_FIREBALL,
    EVENT_PYROBLAST,
    EVENT_SEARING_EMBERS,
    EVENT_FIRE_FROM_MIST,
    EVENT_A_FLASH_OF_HOSTILITY,
    EVENT_MARA_GRIMFANG_TRANSFORM,
    EVENT_ANATHOS_FIRECALLER_TRANSFORM,
    EVENT_DRAGONS_BREATH,
    EVENT_MAGMA_TRAPS,
    EVENT_SPIRITS_OF_XUEN,
    EVENT_RISING_FLAMES,
    EVENT_SPIRITS_OF_NIUZAO,
    EVENT_CHECK_BARRIER
};

void AddSC_boss_jadefire_masters_horde()
{
    
}
