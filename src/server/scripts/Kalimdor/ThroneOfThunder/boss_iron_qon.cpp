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

#include "throne_of_thunder.h"
#include "Vehicle.h"
#include "SpellAuraEffects.h"
#include "SpellAuraDefines.h"

enum Spells
{
    // Iron Qon
    SPELL_THROW_SPEAR = 134925,
    SPELL_RETURN_SPEAR = 137712,
    SPELL_IMPALE = 134691,

    SPELL_IGNITE_CYCLONE = 136159,
    SPELL_FREEZE_CYCLONE = 136153,
    SPELL_FIST_SMASH = 136146,
    SPELL_RISING_ANGER = 136323,

    // Roshak
    SPELL_MOLTEN_INFERNO = 134664,
    SPELL_MOLTEN_OVERLOAD = 137221,
    SPELL_UNLEASHED_FLAME = 139138,

    SPELL_BURNING_CINDERS_SPEAR = 136330, // visual on spear
    SPELL_BURNING_CINDERS = 134758, // trail visual too 
    SPELL_BURNING_CINDERS_DAMAGE = 137668,

    // Quetzal
    SPELL_ARCING_LIGHTNING_ZAP = 136192, // on on random target
    SPELL_ARCING_LIGHTNING = 136193, // on nearby players
    SPELL_ARCING_LIGHTNING_VISUAL = 136224,
    SPELL_ARCING_LIGHTNING_STUN = 136198, // npc creator

    SPELL_RUSHING_WINDS_STUN = 137654, // on players when hit by tornados
    SPELL_RUSHING_WINDS = 136161, // on tornados
    SPELL_RUSHING_WINDS_VISUAL = 136574, // trigger visual
    SPELL_RUSHING_WINDS_SPEED = 136590, // not used
    SPELL_RUSHING_WINDS_TORNADO_VISUAL = 135570,

    SPELL_ELECTRIFIED = 136615,
    SPELL_ELECTRIC_CHARGES = 137669,
    SPELL_STORM_CLOUD_VISUAL = 136421, // trail visual
    SPELL_STORM_CLOUD_SPEAR = 137657, // on spear

    // Damren
    SPELL_DEAD_ZONE = 137232,
    SPELL_DEAD_ZONE_DEBUFF = 135147,

    SPELL_DEAD_ZONE_1 = 137226,
    SPELL_DEAD_ZONE_2 = 137227,
    SPELL_DEAD_ZONE_3 = 137228,
    SPELL_DEAD_ZONE_4 = 137229,
    SPELL_DEAD_ZONE_5 = 137230,
    SPELL_DEAD_ZONE_6 = 137231,

    SPELL_DEAD_ZONE_FRONT = 135361,
    SPELL_DEAD_ZONE_BACK = 135225,
    SPELL_DEAD_ZONE_RIGHT = 135223,
    SPELL_DEAD_ZONE_LEFT = 135199,

    SPELL_FROZEN_RESILIENCE = 135144,
    SPELL_FREEZE = 135145,
    SPELL_SHATTER_SELF = 135146,
    SPELL_SHATTER_AOE = 137709,

    SPELL_FROZEN_BLOOD_AT = 136451, // areatrigger when spear is hit by visual | trail visual too 
    SPELL_FROZEN_BLOOD = 136449, // visual on spear
    SPELL_FROZEN_BLOOD_DAMAGE = 137664, // this is used when players are coming in contact with spear \ ground

    // heroic
    // Qeustzal
    SPELL_WHIRLING_WINDS_SUMMON = 77316,
    SPELL_WHIRLING_WINDS = 139167,
    SPELL_WHIRLING_WINDS_AT = 139166,

    // Damren
    SPELL_FROST_SPIKE = 139177,

    // freeze cyclone
    SPELL_FROZEN_SOLID = 136892,
    SPELL_FROZEN_SOLID_ICE_TOMB = 143776,
};

uint32 DeadZones[6] =
{
    SPELL_DEAD_ZONE_1,
    SPELL_DEAD_ZONE_2,
    SPELL_DEAD_ZONE_3,
    SPELL_DEAD_ZONE_4,
    SPELL_DEAD_ZONE_5,
    SPELL_DEAD_ZONE_6,
};

enum Creatures
{
    NPC_IRON_QON_SPEAR = 68480,

    NPC_DAMREN = 68081,
    NPC_QUESTZAL = 68080,
    NPC_ROSHAK = 68079,

    NPC_RUSHING_WINDS = 69703,
    NPC_RUSHING_WINDS_2 = 999280,
    NPC_RUSHING_WINDS_3 = 999281,
    NPC_RUSHING_WINDS_4 = 999282,
    NPC_RUSHING_WINDS_5 = 999283,
    NPC_RUSHING_WINDS_TRIGGER = 68852,
    NPC_WHIRLING_WINDS = 41245,
    NPC_LIGHTNING_CLOUD = 70660,

    NPC_TRAILS_HANDLER_1 = 999491,
    NPC_TRAILS_HANDLER_2 = 999492,
    NPC_TRAILS_HANDLER_3 = 999493,
    NPC_TRAILS_HANDLER_4 = 999494,

    NPC_ICE_TOMB = 71720,
};

Position const FirstRushingWind[8] =
{
    { 6036.76f, 4726.34f, 142.83f, 3.33f },
    { 5990.94f, 4710.38f, 142.83f, 3.48f },
    { 5991.69f, 4653.37f, 142.83f, 4.71f },
    { 6021.49f, 4631.92f, 142.83f, 5.66f },
    { 6082.12f, 4633.13f, 142.83f, 0.00f },
    { 6101.89f, 4658.11f, 142.83f, 0.83f },
    { 6102.25f, 4711.24f, 142.83f, 1.57f },
    { 6069.63f, 4724.77f, 142.83f, 3.04f },
};

Position const SecondRushingWind[7] =
{
    { 6051.40f, 4710.85f, 142.83f, 5.99f },
    { 6085.30f, 4698.50f, 142.83f, 5.87f },
    { 6084.66f, 4650.52f, 142.83f, 4.68f },
    { 6048.63f, 4637.36f, 142.83f, 3.54f },
    { 6016.11f, 4646.32f, 142.83f, 2.89f },
    { 5997.57f, 4673.21f, 142.83f, 2.11f },
    { 6006.72f, 4708.46f, 142.83f, 1.24f },
};

Position const ThirdRushingWind[7] =
{
    { 6014.21f, 4669.09f, 142.83f, 5.68f },
    { 6038.74f, 4652.73f, 142.83f, 2.62f },
    { 6066.38f, 4648.89f, 142.83f, 2.11f },
    { 6077.20f, 4673.67f, 142.83f, 3.07f },
    { 6063.22f, 4699.06f, 142.83f, 5.3f  },
    { 6047.18f, 4699.42f, 142.83f, 4.57f },
    { 6028.01f, 4697.76f, 142.83f, 5.83f },
};

Position const FourthRushingWind[6] =
{
    { 6046.01f, 4700.77f, 142.83f, 4.56f },
    { 6059.96f, 4689.29f, 142.83f, 3.45f },
    { 6059.84f, 4676.20f, 142.83f, 2.57f },
    { 6046.63f, 4670.15f, 142.83f, 2.88f },
    { 6030.33f, 4673.15f, 142.83f, 0.34f },
    { 6032.58f, 4692.41f, 142.83f, 5.38f },
};

enum Points
{
    POINT_1 = 1,
    POINT_2 = 2,
    POINT_3 = 3,
    POINT_4 = 4,
    POINT_5 = 5,
    POINT_6 = 6,
    POINT_7 = 7,
    POINT_8 = 8,
};

enum Timers
{
    TIMER_INIT = 0,

    TIMER_BERSERK = 12 * MINUTE * IN_MILLISECONDS,

    // Shared between first three phases
    TIMER_IMPALE = 20 * IN_MILLISECONDS,
    TIMER_THROW_SPEAR = 32 * IN_MILLISECONDS,
    TIMER_THROW_SPEAR_DOG = 5 * IN_MILLISECONDS,

    TIMER_SELECT_QUETZAL = 1 * IN_MILLISECONDS,
    TIMER_SELECT_DAMREN = 1 * IN_MILLISECONDS,

    // Ro'shak
    TIMER_ENERGY_GAIN = 2 * IN_MILLISECONDS,
    TIMER_UNLEASHED_FLAME = 3 * IN_MILLISECONDS,
    TIMER_MOLTEN_OVERLOAD = 1 * IN_MILLISECONDS,
    TIMER_MOLTEN_INFERNO = 15 * IN_MILLISECONDS,

    // Quetzal
    TIMER_ARCING_LIGHT = 30 * IN_MILLISECONDS,
    TIMER_WINDSTORM = 3 * MINUTE * IN_MILLISECONDS,

    // Damren
    TIMER_DEAD_ZONE = 10 * IN_MILLISECONDS,
    TIMER_FREEZE = 5 * IN_MILLISECONDS,

    // Last Phase
    TIMER_RISING_ANGER = 15 * IN_MILLISECONDS,
    TIMER_FIST_SMASH = 50 * IN_MILLISECONDS,
    TIMER_FIST_SMASH_SECOND = 30 * IN_MILLISECONDS,
    TIMER_IGNITE_CYCLONE_FIRE = 7 * IN_MILLISECONDS,
    TIMER_IGNITE_CYCLONE_FREEZE = 9 * IN_MILLISECONDS,
};

enum Events
{
    // Iron Qon
    EVENT_IMPALE = 1,
    EVENT_IMPALE_2,
    EVENT_IMPALE_3,
    EVENT_THROW_SPEAR, // roshak
    EVENT_THROW_SPEAR_DOG, // roshak
    EVENT_THROW_SPEAR_DOG_2, // quetzal
    EVENT_THROW_SPEAR_DOG_3, // damren
    EVENT_THROW_SPEAR_1, // quetzal
    EVENT_THROW_SPEAR_2, // damren

    EVENT_SELECT_QUETZAL,
    EVENT_SELECT_DAMREN,

    // Roshak
    EVENT_ENERGY_GAIN,
    EVENT_UNLEASHED_FLAME,
    EVENT_MOLTEN_OVERLOAD,
    EVENT_MOLTEN_INFERNO,
    EVENT_ADD_SAFE, // safer aura because spear is not supposed to spam cinder on ground if there are multiple spears 

    // HEROIC
    EVENT_WHIRLING,

    EVENT_CALL_THE_STORM,

    // Quetzal
    EVENT_RETURN_TO_COMBAT,
    EVENT_ARCING_LIGHT,
    EVENT_WINDSTORM,
    EVENT_WHIRL_AT,
    EVENT_INIT_WINDSTORM,
    EVENT_ATTACK_TARGET,

    // heroic
    EVENT_FROST_SPIKE,

    // Damren
    EVENT_DEAD_ZONE,
    EVENT_FREEZE,

    // Last Phase
    EVENT_IGNITE_CYCLONE,
    EVENT_RISING_ANGER,
    EVENT_FREEZE_NEARBY_PLAYERS,
    EVENT_FREEZE_CYCLONE,
    EVENT_FIST_SMASH,

    // Wind Rush events ( movement )
    EVENT_1,
    EVENT_2,
    EVENT_3,
    EVENT_4,
    EVENT_5,
    EVENT_6,
    EVENT_7,
    EVENT_8,

    EVENT_CHECK_NEARBY_PLAYERS_RUSHING,
    EVENT_REMOVE_PLAYERS,
    // Spear
    EVENT_DO_FIRE,
    EVENT_DO_FROZEN,
    EVENT_DO_STORM,

    EVENT_EJECT_QON,
};

enum Actions
{
    ACTION_ENTER_LAST_PHASE = 1,
    ACTION_COUNT_DOGS_FLEE = 2, // used on heroic
    ACTION_ROSHAK_DIED = 3,
    ACTION_QUETZAL_DIED = 4,
    ACTION_START_COMBAT = 5, // shared between Quetzal and Damren
    ACTION_CAST_BURNING_TRAIL = 6,
    ACTION_CAST_FROZEN_BLOOD = 7,
    ACTION_CAST_STORM_CLOUD = 8,
    ACTION_CALLING_THE_STORM = 9,
    ACTION_STOP_CALLING_THE_STORM = 10,
    ACTION_BREAKING_THE_ICE = 11,
    ACTION_STOP_BREAKING_THE_ICE = 12,
    ACTION_SPARK_OF_MOLTEN_FLARE = 13,
    ACTION_STOP_SPARK_OF_MOLTEN_FLARE = 14,
    ACTION_START_FREEZING = 15,
    ACTION_LAST_PHASE_EJECTION = 16,
};

void AddSC_bfa_boss_iron_qon()
{
    
}
