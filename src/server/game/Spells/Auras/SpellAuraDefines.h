/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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
#ifndef TRINITY_SPELLAURADEFINES_H
#define TRINITY_SPELLAURADEFINES_H

#include "Define.h"

#define MAX_AURAS 255

enum AURA_FLAGS
{
    AFLAG_NONE                   = 0x00,
    AFLAG_NOCASTER               = 0x01,
    AFLAG_POSITIVE               = 0x02,
    AFLAG_DURATION               = 0x04,
    AFLAG_SCALABLE               = 0x08,
    AFLAG_NEGATIVE               = 0x10,
    AFLAG_UNK20                  = 0x20
};

// these are modes, in which aura effect handler may be called

enum AuraEffectHandleModes
{
    AURA_EFFECT_HANDLE_DEFAULT = 0x0,
    AURA_EFFECT_HANDLE_REAL = 0x01, // handler applies/removes effect from unit
    AURA_EFFECT_HANDLE_SEND_FOR_CLIENT = 0x02, // handler sends apply/remove packet to unit
    AURA_EFFECT_HANDLE_CHANGE_AMOUNT = 0x04, // handler updates effect on target after effect amount change
    AURA_EFFECT_HANDLE_REAPPLY = 0x08, // handler updates effect on target after aura is reapplied on target
    AURA_EFFECT_HANDLE_STAT = 0x10, // handler updates effect on target when stat removal/apply is needed for calculations by core
    AURA_EFFECT_HANDLE_SKILL = 0x20, // handler updates effect on target when skill removal/apply is needed for calculations by core
    AURA_EFFECT_HANDLE_SEND_FOR_CLIENT_MASK = (AURA_EFFECT_HANDLE_SEND_FOR_CLIENT | AURA_EFFECT_HANDLE_REAL), // any case handler need to send packet
    AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK = (AURA_EFFECT_HANDLE_CHANGE_AMOUNT | AURA_EFFECT_HANDLE_REAL), // any case handler applies effect depending on amount
    AURA_EFFECT_HANDLE_CHANGE_AMOUNT_SEND_FOR_CLIENT_MASK = (AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK | AURA_EFFECT_HANDLE_SEND_FOR_CLIENT_MASK),
    AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK = (AURA_EFFECT_HANDLE_REAPPLY | AURA_EFFECT_HANDLE_REAL)
};

enum AuraRemoveMode
{
    AURA_REMOVE_NONE = 0,
    AURA_REMOVE_BY_DEFAULT = 1,       // scripted remove, remove by stack with aura with different ids and sc aura remove
    AURA_REMOVE_BY_CANCEL,
    AURA_REMOVE_BY_ENEMY_SPELL,       // dispel and absorb aura destroy
    AURA_REMOVE_BY_EXPIRE,            // aura duration has ended
    AURA_REMOVE_BY_DEATH
};

//m_schoolAbsorb
enum DAMAGE_ABSORB_TYPE
{
    ALL_DAMAGE_ABSORB       = -2,
    ONLY_MAGIC_ABSORB       = -1
};

enum AuraType : uint32
{
    SPELL_AURA_NONE                                         = 0,
    SPELL_AURA_BIND_SIGHT                                   = 1,
    SPELL_AURA_MOD_POSSESS                                  = 2,
    SPELL_AURA_PERIODIC_DAMAGE                              = 3,
    SPELL_AURA_DUMMY                                        = 4,
    SPELL_AURA_MOD_CONFUSE                                  = 5,
    SPELL_AURA_MOD_CHARM                                    = 6,
    SPELL_AURA_MOD_FEAR                                     = 7,
    SPELL_AURA_PERIODIC_HEAL                                = 8,
    SPELL_AURA_MOD_ATTACKSPEED                              = 9,
    SPELL_AURA_MOD_THREAT                                   = 10,
    SPELL_AURA_MOD_TAUNT                                    = 11,
    SPELL_AURA_MOD_STUN                                     = 12,
    SPELL_AURA_MOD_DAMAGE_DONE                              = 13,
    SPELL_AURA_MOD_DAMAGE_TAKEN                             = 14,
    SPELL_AURA_DAMAGE_SHIELD                                = 15,
    SPELL_AURA_MOD_STEALTH                                  = 16,
    SPELL_AURA_MOD_STEALTH_DETECT                           = 17,
    SPELL_AURA_MOD_INVISIBILITY                             = 18,
    SPELL_AURA_MOD_INVISIBILITY_DETECT                      = 19,
    SPELL_AURA_OBS_MOD_HEALTH                               = 20,   // 20, 21 unofficial
    SPELL_AURA_OBS_MOD_POWER                                = 21,
    SPELL_AURA_MOD_RESISTANCE                               = 22,
    SPELL_AURA_PERIODIC_TRIGGER_SPELL                       = 23,
    SPELL_AURA_PERIODIC_ENERGIZE                            = 24,
    SPELL_AURA_MOD_PACIFY                                   = 25,
    SPELL_AURA_MOD_ROOT                                     = 26,
    SPELL_AURA_MOD_SILENCE                                  = 27,
    SPELL_AURA_REFLECT_SPELLS                               = 28,
    SPELL_AURA_MOD_STAT                                     = 29,
    SPELL_AURA_MOD_SKILL                                    = 30,
    SPELL_AURA_MOD_INCREASE_SPEED                           = 31,
    SPELL_AURA_MOD_INCREASE_MOUNTED_SPEED                   = 32,
    SPELL_AURA_MOD_DECREASE_SPEED                           = 33,
    SPELL_AURA_MOD_INCREASE_HEALTH                          = 34,
    SPELL_AURA_MOD_INCREASE_ENERGY                          = 35,
    SPELL_AURA_MOD_SHAPESHIFT                               = 36,
    SPELL_AURA_EFFECT_IMMUNITY                              = 37,
    SPELL_AURA_STATE_IMMUNITY                               = 38,
    SPELL_AURA_SCHOOL_IMMUNITY                              = 39,
    SPELL_AURA_DAMAGE_IMMUNITY                              = 40,
    SPELL_AURA_DISPEL_IMMUNITY                              = 41,
    SPELL_AURA_PROC_TRIGGER_SPELL                           = 42,
    SPELL_AURA_PROC_TRIGGER_DAMAGE                          = 43,
    SPELL_AURA_TRACK_CREATURES                              = 44,
    SPELL_AURA_TRACK_RESOURCES                              = 45,
    SPELL_AURA_46                                           = 46,   // Ignore all Gear test spells
    SPELL_AURA_MOD_PARRY_PERCENT                            = 47,
    SPELL_AURA_48                                           = 48,   // One periodic spell
    SPELL_AURA_MOD_DODGE_PERCENT                            = 49,
    SPELL_AURA_MOD_CRITICAL_HEALING_AMOUNT                  = 50,
    SPELL_AURA_MOD_BLOCK_PERCENT                            = 51,
    SPELL_AURA_MOD_WEAPON_CRIT_PERCENT                      = 52,
    SPELL_AURA_PERIODIC_LEECH                               = 53,
    SPELL_AURA_MOD_HIT_CHANCE                               = 54,
    SPELL_AURA_MOD_SPELL_HIT_CHANCE                         = 55,
    SPELL_AURA_TRANSFORM                                    = 56,
    SPELL_AURA_MOD_SPELL_CRIT_CHANCE                        = 57,
    SPELL_AURA_MOD_INCREASE_SWIM_SPEED                      = 58,
    SPELL_AURA_MOD_DAMAGE_DONE_CREATURE                     = 59,
    SPELL_AURA_MOD_PACIFY_SILENCE                           = 60,
    SPELL_AURA_MOD_SCALE                                    = 61,
    SPELL_AURA_PERIODIC_HEALTH_FUNNEL                       = 62,
    SPELL_AURA_MOD_ADDITIONAL_POWER_COST                    = 63,
    SPELL_AURA_PERIODIC_MANA_LEECH                          = 64,
    SPELL_AURA_MOD_CASTING_SPEED_NOT_STACK                  = 65,
    SPELL_AURA_FEIGN_DEATH                                  = 66,
    SPELL_AURA_MOD_DISARM                                   = 67,
    SPELL_AURA_MOD_STALKED                                  = 68,
    SPELL_AURA_SCHOOL_ABSORB                                = 69,
    SPELL_AURA_EXTRA_ATTACKS                                = 70,
    SPELL_AURA_71                                           = 71,
    SPELL_AURA_MOD_POWER_COST_SCHOOL_PCT                    = 72,
    SPELL_AURA_MOD_POWER_COST_SCHOOL                        = 73,
    SPELL_AURA_REFLECT_SPELLS_SCHOOL                        = 74,
    SPELL_AURA_MOD_LANGUAGE                                 = 75,
    SPELL_AURA_FAR_SIGHT                                    = 76,
    SPELL_AURA_MECHANIC_IMMUNITY                            = 77,
    SPELL_AURA_MOUNTED                                      = 78,
    SPELL_AURA_MOD_DAMAGE_PERCENT_DONE                      = 79,
    SPELL_AURA_MOD_PERCENT_STAT                             = 80,
    SPELL_AURA_SPLIT_DAMAGE_PCT                             = 81,
    SPELL_AURA_WATER_BREATHING                              = 82,
    SPELL_AURA_MOD_BASE_RESISTANCE                          = 83,
    SPELL_AURA_MOD_REGEN                                    = 84,
    SPELL_AURA_MOD_POWER_REGEN                              = 85,
    SPELL_AURA_CHANNEL_DEATH_ITEM                           = 86,
    SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN                     = 87,
    SPELL_AURA_MOD_HEALTH_REGEN_PERCENT                     = 88,
    SPELL_AURA_PERIODIC_DAMAGE_PERCENT                      = 89,
    SPELL_AURA_90                                           = 90,   // old SPELL_AURA_MOD_RESIST_CHANCE
    SPELL_AURA_MOD_DETECT_RANGE                             = 91,
    SPELL_AURA_PREVENTS_FLEEING                             = 92,
    SPELL_AURA_MOD_UNATTACKABLE                             = 93,
    SPELL_AURA_INTERRUPT_REGEN                              = 94,
    SPELL_AURA_GHOST                                        = 95,
    SPELL_AURA_SPELL_MAGNET                                 = 96,
    SPELL_AURA_MANA_SHIELD                                  = 97,
    SPELL_AURA_MOD_SKILL_TALENT                             = 98,
    SPELL_AURA_MOD_ATTACK_POWER                             = 99,
    SPELL_AURA_AURAS_VISIBLE                                = 100,
    SPELL_AURA_MOD_RESISTANCE_PCT                           = 101,
    SPELL_AURA_MOD_MELEE_ATTACK_POWER_VERSUS                = 102,
    SPELL_AURA_MOD_TOTAL_THREAT                             = 103,
    SPELL_AURA_WATER_WALK                                   = 104,
    SPELL_AURA_FEATHER_FALL                                 = 105,
    SPELL_AURA_HOVER                                        = 106,
    SPELL_AURA_ADD_FLAT_MODIFIER                            = 107,
    SPELL_AURA_ADD_PCT_MODIFIER                             = 108,
    SPELL_AURA_ADD_TARGET_TRIGGER                           = 109,
    SPELL_AURA_MOD_POWER_REGEN_PERCENT                      = 110,
    SPELL_AURA_INTERCEPT_MELEE_RANGED_ATTACKS               = 111,
    SPELL_AURA_OVERRIDE_CLASS_SCRIPTS                       = 112,
    SPELL_AURA_MOD_RANGED_DAMAGE_TAKEN                      = 113,
    SPELL_AURA_MOD_RANGED_DAMAGE_TAKEN_PCT                  = 114,
    SPELL_AURA_MOD_HEALING                                  = 115,
    SPELL_AURA_MOD_REGEN_DURING_COMBAT                      = 116,
    SPELL_AURA_MOD_MECHANIC_RESISTANCE                      = 117,
    SPELL_AURA_MOD_HEALING_PCT                              = 118,
    SPELL_AURA_PVP_TALENTS                                  = 119,
    SPELL_AURA_UNTRACKABLE                                  = 120,
    SPELL_AURA_EMPATHY                                      = 121,
    SPELL_AURA_MOD_OFFHAND_DAMAGE_PCT                       = 122,
    SPELL_AURA_MOD_TARGET_RESISTANCE                        = 123,
    SPELL_AURA_MOD_RANGED_ATTACK_POWER                      = 124,
    SPELL_AURA_MOD_MELEE_DAMAGE_TAKEN                       = 125,
    SPELL_AURA_MOD_MELEE_DAMAGE_TAKEN_PCT                   = 126,
    SPELL_AURA_RANGED_ATTACK_POWER_ATTACKER_BONUS           = 127,
    SPELL_AURA_MOD_POSSESS_PET                              = 128,
    SPELL_AURA_MOD_SPEED_ALWAYS                             = 129,
    SPELL_AURA_MOD_MOUNTED_SPEED_ALWAYS                     = 130,
    SPELL_AURA_MOD_RANGED_ATTACK_POWER_VERSUS               = 131,
    SPELL_AURA_MOD_INCREASE_ENERGY_PERCENT                  = 132,
    SPELL_AURA_MOD_INCREASE_HEALTH_PERCENT                  = 133,
    SPELL_AURA_MOD_MANA_REGEN_INTERRUPT                     = 134,
    SPELL_AURA_MOD_HEALING_DONE                             = 135,
    SPELL_AURA_MOD_HEALING_DONE_PERCENT                     = 136,
    SPELL_AURA_MOD_TOTAL_STAT_PERCENTAGE                    = 137,
    SPELL_AURA_MOD_MELEE_HASTE                              = 138,
    SPELL_AURA_FORCE_REACTION                               = 139,
    SPELL_AURA_MOD_RANGED_HASTE                             = 140,
    SPELL_AURA_141                                          = 141,  // old SPELL_AURA_MOD_RANGED_AMMO_HASTE, unused now
    SPELL_AURA_MOD_BASE_RESISTANCE_PCT                      = 142,
    SPELL_AURA_MOD_RECOVERY_RATE                            = 143,  // NYI
    SPELL_AURA_SAFE_FALL                                    = 144,
    SPELL_AURA_MOD_PET_TALENT_POINTS                        = 145,
    SPELL_AURA_ALLOW_TAME_PET_TYPE                          = 146,
    SPELL_AURA_MECHANIC_IMMUNITY_MASK                       = 147,
    SPELL_AURA_RETAIN_COMBO_POINTS                          = 148,
    SPELL_AURA_REDUCE_PUSHBACK                              = 149,  //    Reduce Pushback
    SPELL_AURA_MOD_SHIELD_BLOCKVALUE_PCT                    = 150,
    SPELL_AURA_TRACK_STEALTHED                              = 151,  //    Track Stealthed
    SPELL_AURA_MOD_DETECTED_RANGE                           = 152,  //    Mod Detected Range
    SPELL_AURA_153                                          = 153,  // old SPELL_AURA_SPLIT_DAMAGE_FLAT. unused 4.3.4
    SPELL_AURA_MOD_STEALTH_LEVEL                            = 154,  //    Stealth Level Modifier
    SPELL_AURA_MOD_WATER_BREATHING                          = 155,  //    Mod Water Breathing
    SPELL_AURA_MOD_REPUTATION_GAIN                          = 156,  //    Mod Reputation Gain
    SPELL_AURA_PET_DAMAGE_MULTI                             = 157,  //    Mod Pet Damage
    SPELL_AURA_ALLOW_TALENT_SWAPPING                        = 158,
    SPELL_AURA_NO_PVP_CREDIT                                = 159,
    SPELL_AURA_160                                          = 160,  // old SPELL_AURA_MOD_AOE_AVOIDANCE. Unused 4.3.4
    SPELL_AURA_MOD_HEALTH_REGEN_IN_COMBAT                   = 161,
    SPELL_AURA_POWER_BURN                                   = 162,
    SPELL_AURA_MOD_CRIT_DAMAGE_BONUS                        = 163,
    SPELL_AURA_164                                          = 164,
    SPELL_AURA_MELEE_ATTACK_POWER_ATTACKER_BONUS            = 165,
    SPELL_AURA_MOD_ATTACK_POWER_PCT                         = 166,
    SPELL_AURA_MOD_RANGED_ATTACK_POWER_PCT                  = 167,
    SPELL_AURA_MOD_DAMAGE_DONE_VERSUS                       = 168,
    SPELL_AURA_169                                          = 169,  // old SPELL_AURA_MOD_CRIT_PERCENT_VERSUS. unused 4.3.4
    SPELL_AURA_DETECT_AMORE                                 = 170,
    SPELL_AURA_MOD_SPEED_NOT_STACK                          = 171,
    SPELL_AURA_MOD_MOUNTED_SPEED_NOT_STACK                  = 172,
    SPELL_AURA_MOD_RECOVERY_RATE_2                          = 173,  // NYI
    SPELL_AURA_MOD_SPELL_DAMAGE_OF_STAT_PERCENT             = 174,  // by defeult intelect, dependent from SPELL_AURA_MOD_SPELL_HEALING_OF_STAT_PERCENT
    SPELL_AURA_MOD_SPELL_HEALING_OF_STAT_PERCENT            = 175,
    SPELL_AURA_SPIRIT_OF_REDEMPTION                         = 176,
    SPELL_AURA_AOE_CHARM                                    = 177,
    SPELL_AURA_MOD_MAX_POWER_PCT                            = 178,
    SPELL_AURA_MOD_POWER_DISPLAY                            = 179,
    SPELL_AURA_MOD_FLAT_SPELL_DAMAGE_VERSUS                 = 180,
    SPELL_AURA_181                                          = 181,  // old SPELL_AURA_MOD_FLAT_SPELL_CRIT_DAMAGE_VERSUS - possible flat spell crit damage versus
    SPELL_AURA_MOD_RESISTANCE_OF_STAT_PERCENT               = 182,
    SPELL_AURA_MOD_CRITICAL_THREAT                          = 183,
    SPELL_AURA_MOD_ATTACKER_MELEE_HIT_CHANCE                = 184,
    SPELL_AURA_MOD_ATTACKER_RANGED_HIT_CHANCE               = 185,
    SPELL_AURA_MOD_ATTACKER_SPELL_HIT_CHANCE                = 186,
    SPELL_AURA_MOD_ATTACKER_MELEE_CRIT_CHANCE               = 187,
    SPELL_AURA_MOD_ATTACKER_RANGED_CRIT_CHANCE              = 188,
    SPELL_AURA_MOD_RATING                                   = 189,
    SPELL_AURA_MOD_FACTION_REPUTATION_GAIN                  = 190,
    SPELL_AURA_USE_NORMAL_MOVEMENT_SPEED                    = 191,
    SPELL_AURA_MOD_MELEE_RANGED_HASTE                       = 192,
    SPELL_AURA_MELEE_SLOW                                   = 193,
    SPELL_AURA_MOD_TARGET_ABSORB_SCHOOL                     = 194,
    SPELL_AURA_MOD_TARGET_ABILITY_ABSORB_SCHOOL             = 195,
    SPELL_AURA_MOD_COOLDOWN                                 = 196,  // only 24818 Noxious Breath
    SPELL_AURA_MOD_ATTACKER_SPELL_AND_WEAPON_CRIT_CHANCE    = 197,
    SPELL_AURA_198                                          = 198,  // old SPELL_AURA_MOD_ALL_WEAPON_SKILLS
    SPELL_AURA_199                                          = 199,  // old SPELL_AURA_MOD_INCREASES_SPELL_PCT_TO_HIT. unused 4.3.4
    SPELL_AURA_MOD_XP_PCT                                   = 200,
    SPELL_AURA_FLY                                          = 201,
    SPELL_AURA_IGNORE_COMBAT_RESULT                         = 202,
    SPELL_AURA_PREVENT_INTERRUPT                            = 203, // NYI
    SPELL_AURA_PREVENT_CORPSE_RELEASE                       = 204, // NYI
    SPELL_AURA_MOD_CHARGE_COOLDOWN                          = 205, // NYI
    SPELL_AURA_MOD_INCREASE_VEHICLE_FLIGHT_SPEED            = 206,
    SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED            = 207,
    SPELL_AURA_MOD_INCREASE_FLIGHT_SPEED                    = 208,
    SPELL_AURA_MOD_MOUNTED_FLIGHT_SPEED_ALWAYS              = 209,
    SPELL_AURA_MOD_VEHICLE_SPEED_ALWAYS                     = 210,
    SPELL_AURA_MOD_FLIGHT_SPEED_NOT_STACK                   = 211,
    SPELL_AURA_MOD_HONOR_GAIN_PCT                           = 212,
    SPELL_AURA_MOD_RAGE_FROM_DAMAGE_DEALT                   = 213,
    SPELL_AURA_214                                          = 214,
    SPELL_AURA_ARENA_PREPARATION                            = 215,
    SPELL_AURA_HASTE_SPELLS                                 = 216,
    SPELL_AURA_MOD_MELEE_HASTE_2                            = 217,
    SPELL_AURA_218                                          = 218,  // old SPELL_AURA_HASTE_RANGED
    SPELL_AURA_MOD_MANA_REGEN_FROM_STAT                     = 219,
    SPELL_AURA_MOD_RATING_FROM_STAT                         = 220,
    SPELL_AURA_MOD_DETAUNT                                  = 221,
    SPELL_AURA_222                                          = 222,
    SPELL_AURA_223                                          = 223,  // old SPELL_AURA_RAID_PROC_FROM_CHARGE
    SPELL_AURA_224                                          = 224,
    SPELL_AURA_MOD_VISIBILITY_RANGE                         = 225,
    SPELL_AURA_PERIODIC_DUMMY                               = 226,
    SPELL_AURA_PERIODIC_TRIGGER_SPELL_WITH_VALUE            = 227,
    SPELL_AURA_DETECT_STEALTH                               = 228,
    SPELL_AURA_MOD_AOE_DAMAGE_AVOIDANCE                     = 229,
    SPELL_AURA_MOD_MAX_HEALTH                               = 230,
    SPELL_AURA_PROC_TRIGGER_SPELL_WITH_VALUE                = 231,
    SPELL_AURA_MECHANIC_DURATION_MOD                        = 232,
    SPELL_AURA_CHANGE_MODEL_FOR_ALL_HUMANOIDS               = 233,  // client-side only
    SPELL_AURA_MECHANIC_DURATION_MOD_NOT_STACK              = 234,
    SPELL_AURA_MOD_DISPEL_RESIST                            = 235,
    SPELL_AURA_CONTROL_VEHICLE                              = 236,
    SPELL_AURA_MOD_SPELL_DAMAGE_OF_ATTACK_POWER             = 237,
    SPELL_AURA_MOD_SPELL_HEALING_OF_ATTACK_POWER            = 238,
    SPELL_AURA_MOD_SCALE_2                                  = 239,
    SPELL_AURA_MOD_EXPERTISE                                = 240,
    SPELL_AURA_FORCE_MOVE_FORWARD                           = 241,
    SPELL_AURA_MOD_SPELL_DAMAGE_FROM_HEALING                = 242,
    SPELL_AURA_MOD_FACTION                                  = 243,
    SPELL_AURA_COMPREHEND_LANGUAGE                          = 244,
    SPELL_AURA_MOD_AURA_DURATION_BY_DISPEL                  = 245,
    SPELL_AURA_MOD_AURA_DURATION_BY_DISPEL_NOT_STACK        = 246,
    SPELL_AURA_CLONE_CASTER                                 = 247,
    SPELL_AURA_MOD_COMBAT_RESULT_CHANCE                     = 248,
    SPELL_AURA_MOD_DAMAGE_PERCENT_DONE_BY_TARGET_AURA_MECHANIC = 249, // NYI
    SPELL_AURA_MOD_INCREASE_HEALTH_2                        = 250,
    SPELL_AURA_MOD_ENEMY_DODGE                              = 251,
    SPELL_AURA_MOD_SPEED_SLOW_ALL                           = 252,
    SPELL_AURA_MOD_BLOCK_CRIT_CHANCE                        = 253,
    SPELL_AURA_MOD_DISARM_OFFHAND                           = 254,
    SPELL_AURA_MOD_MECHANIC_DAMAGE_TAKEN_PERCENT            = 255,
    SPELL_AURA_NO_REAGENT_USE                               = 256,
    SPELL_AURA_MOD_TARGET_RESIST_BY_SPELL_CLASS             = 257,
    SPELL_AURA_OVERRIDE_SUMMONED_OBJECT                     = 258,
    SPELL_AURA_259                                          = 259,  // old SPELL_AURA_MOD_HOT_PCT, unused 4.3.4
    SPELL_AURA_SCREEN_EFFECT                                = 260,
    SPELL_AURA_PHASE                                        = 261,
    SPELL_AURA_ABILITY_IGNORE_AURASTATE                     = 262,
    SPELL_AURA_ALLOW_ONLY_ABILITY                           = 263,
    SPELL_AURA_264                                          = 264,
    SPELL_AURA_265                                          = 265,
    SPELL_AURA_266                                          = 266,
    SPELL_AURA_MOD_IMMUNE_AURA_APPLY_SCHOOL                 = 267,
    SPELL_AURA_268                                          = 268,  // old SPELL_AURA_MOD_ATTACK_POWER_OF_STAT_PERCENT. unused 4.3.4
    SPELL_AURA_MOD_IGNORE_TARGET_RESIST                     = 269,
    SPELL_AURA_MOD_SCHOOL_MASK_DAMAGE_FROM_CASTER           = 270,  // NYI
    SPELL_AURA_MOD_SPELL_DAMAGE_FROM_CASTER                 = 271,
    SPELL_AURA_IGNORE_MELEE_RESET                           = 272,
    SPELL_AURA_X_RAY                                        = 273,
    SPELL_AURA_274                                          = 274,  // old SPELL_AURA_ABILITY_CONSUME_NO_AMMO, unused 4.3.4
    SPELL_AURA_MOD_IGNORE_SHAPESHIFT                        = 275,
    SPELL_AURA_MOD_DAMAGE_DONE_FOR_MECHANIC                 = 276,
    SPELL_AURA_277                                          = 277,  // old SPELL_AURA_MOD_MAX_AFFECTED_TARGETS. unused 4.3.4
    SPELL_AURA_MOD_DISARM_RANGED                            = 278,
    SPELL_AURA_INITIALIZE_IMAGES                            = 279,
    SPELL_AURA_280                                          = 280,  // old SPELL_AURA_MOD_ARMOR_PENETRATION_PCT unused 4.3.4
    SPELL_AURA_MOD_GUILD_REPUTATION_GAIN_PCT                = 281,  // NYI
    SPELL_AURA_MOD_BASE_HEALTH_PCT                          = 282,
    SPELL_AURA_MOD_HEALING_RECEIVED                         = 283,  // Possibly only for some spell family class spells
    SPELL_AURA_LINKED                                       = 284,
    SPELL_AURA_MOD_ATTACK_POWER_OF_ARMOR                    = 285,
    SPELL_AURA_ABILITY_PERIODIC_CRIT                        = 286,
    SPELL_AURA_DEFLECT_SPELLS                               = 287,
    SPELL_AURA_IGNORE_HIT_DIRECTION                         = 288,
    SPELL_AURA_PREVENT_DURABILITY_LOSS                      = 289,
    SPELL_AURA_MOD_CRIT_PCT                                 = 290,
    SPELL_AURA_MOD_XP_QUEST_PCT                             = 291,
    SPELL_AURA_OPEN_STABLE                                  = 292,
    SPELL_AURA_OVERRIDE_SPELLS                              = 293,
    SPELL_AURA_PREVENT_REGENERATE_POWER                     = 294,
    SPELL_AURA_295                                          = 295,
    SPELL_AURA_SET_VEHICLE_ID                               = 296,
    SPELL_AURA_BLOCK_SPELL_FAMILY                           = 297,
    SPELL_AURA_STRANGULATE                                  = 298,
    SPELL_AURA_299                                          = 299,
    SPELL_AURA_SHARE_DAMAGE_PCT                             = 300,
    SPELL_AURA_SCHOOL_HEAL_ABSORB                           = 301,
    SPELL_AURA_302                                          = 302,
    SPELL_AURA_MOD_DAMAGE_DONE_VERSUS_AURASTATE             = 303,
    SPELL_AURA_MOD_FAKE_INEBRIATE                           = 304,
    SPELL_AURA_MOD_MINIMUM_SPEED                            = 305,
    SPELL_AURA_306                                          = 306,
    SPELL_AURA_HEAL_ABSORB_TEST                             = 307,
    SPELL_AURA_MOD_CRIT_CHANCE_FOR_CASTER                   = 308,
    SPELL_AURA_MOD_RESILIENCE                               = 309,  // NYI
    SPELL_AURA_MOD_CREATURE_AOE_DAMAGE_AVOIDANCE            = 310,
    SPELL_AURA_311                                          = 311,
    SPELL_AURA_ANIM_REPLACEMENT_SET                         = 312,
    SPELL_AURA_313                                          = 313,  // Not used in 4.3.4 - related to mounts
    SPELL_AURA_PREVENT_RESURRECTION                         = 314,
    SPELL_AURA_UNDERWATER_WALKING                           = 315,
    SPELL_AURA_PERIODIC_HASTE                               = 316,  // Not used in 4.3.4 (name from 3.3.5a)
    SPELL_AURA_MOD_SPELL_POWER_PCT                          = 317,
    SPELL_AURA_MASTERY                                      = 318,
    SPELL_AURA_MOD_MELEE_HASTE_3                            = 319,
    SPELL_AURA_MOD_RANGED_HASTE_2                           = 320,
    SPELL_AURA_MOD_NO_ACTIONS                               = 321,
    SPELL_AURA_INTERFERE_TARGETTING                         = 322,
    SPELL_AURA_323                                          = 323,  // Not used in 4.3.4
    SPELL_AURA_324                                          = 324,  // spell critical chance (probably by school mask)
    SPELL_AURA_325                                          = 325,  // Not used in 4.3.4
    SPELL_AURA_PHASE_GROUP                                  = 326,  // Puts the player in all the phases that are in the group with id = miscB
    SPELL_AURA_327                                          = 327,  // Not used in 4.3.4
    SPELL_AURA_TRIGGER_SPELL_ON_POWER_PCT                   = 328,  // NYI Triggers spell when power goes above (MiscB = 0) or falls below (MiscB = 1) specified percent value (once, not every time condition has meet)
    SPELL_AURA_MOD_POWER_GAIN_PCT                           = 329,  // NYI
    SPELL_AURA_CAST_WHILE_WALKING                           = 330,
    SPELL_AURA_FORCE_WEATHER                                = 331,
    SPELL_AURA_OVERRIDE_ACTIONBAR_SPELLS                    = 332,
    SPELL_AURA_OVERRIDE_ACTIONBAR_SPELLS_TRIGGERED          = 333,  // Spells cast with this override have no cast time or power cost
    SPELL_AURA_MOD_BLIND                                    = 334,  // NYI
    SPELL_AURA_335                                          = 335,
    SPELL_AURA_MOUNT_RESTRICTIONS                           = 336,
    SPELL_AURA_MOD_VENDOR_ITEMS_PRICES                      = 337,
    SPELL_AURA_MOD_DURABILITY_LOSS                          = 338,
    SPELL_AURA_INCREASE_SKILL_GAIN_CHANCE                   = 339,  // NYI
    SPELL_AURA_MOD_RESURRECTED_HEALTH_BY_GUILD_MEMBER       = 340,  // Increases health gained when resurrected by a guild member by X
    SPELL_AURA_MOD_SPELL_CATEGORY_COOLDOWN                  = 341,  // Modifies cooldown of all spells using affected category
    SPELL_AURA_MOD_MELEE_RANGED_HASTE_2                     = 342,
    SPELL_AURA_MOD_MELEE_DAMAGE_FROM_CASTER                 = 343,  // NYI
    SPELL_AURA_MOD_AUTOATTACK_DAMAGE                        = 344,  // NYI
    SPELL_AURA_BYPASS_ARMOR_FOR_CASTER                      = 345,
    SPELL_AURA_ENABLE_ALT_POWER                             = 346,  // NYI
    SPELL_AURA_MOD_SPELL_COOLDOWN_BY_HASTE                  = 347,
    SPELL_AURA_DEPOSIT_BONUS_MONEY_IN_GUILD_BANK_ON_LOOT    = 348,
    SPELL_AURA_MOD_CURRENCY_GAIN                            = 349,
    SPELL_AURA_MOD_GATHERING_ITEMS_GAINED_PERCENT           = 350,  // NYI
    SPELL_AURA_351                                          = 351,
    SPELL_AURA_352                                          = 352,
    SPELL_AURA_MOD_CAMOUFLAGE                               = 353,  // NYI
    SPELL_AURA_354                                          = 354,  // Restoration Shaman mastery - mod healing based on target's health (less = more healing)
    SPELL_AURA_MOD_CASTING_SPEED                            = 355,  // NYI
    SPELL_AURA_356                                          = 356,  // Arcane Mage mastery - mod damage based on current mana
    SPELL_AURA_ENABLE_BOSS1_UNIT_FRAME                      = 357,
    SPELL_AURA_WORGEN_ALTERED_FORM                          = 358,
    SPELL_AURA_359                                          = 359,
    SPELL_AURA_PROC_TRIGGER_SPELL_COPY                      = 360,  // Procs the same spell that caused this proc (Dragonwrath, Tarecgosa's Rest)
    SPELL_AURA_OVERRIDE_AUTOATTACK_WITH_MELEE_SPELL         = 361,  // NYI
    SPELL_AURA_362                                          = 362,  // Not used in 4.3.4
    SPELL_AURA_MOD_NEXT_SPELL                               = 363,  // Used by 101601 Throw Totem - causes the client to initialize spell cast with specified spell
    SPELL_AURA_364                                          = 364,  // Not used in 4.3.4
    SPELL_AURA_MAX_FAR_CLIP_PLANE                           = 365,  // Overrides client's View Distance setting to max("Fair", current_setting) and turns off terrain display
    SPELL_AURA_OVERRIDE_SPELL_POWER_BY_AP_PCT               = 366,  // NYI - Sets spellpower equal to % of attack power, discarding all other bonuses (from gear and buffs)
    SPELL_AURA_OVERRIDE_AUTOATTACK_WITH_RANGED_SPELL        = 367,  // NYI
    SPELL_AURA_368                                          = 368,  // Not used in 4.3.4
    SPELL_AURA_ENABLE_POWER_BAR_TIMER                       = 369,
    SPELL_AURA_SET_FAIR_FAR_CLIP                            = 370,  // Overrides client's View Distance setting to max("Fair", current_setting)
    SPELL_AURA_371                                          = 371,
    SPELL_AURA_372                                          = 372,
    SPELL_AURA_MOD_SPEED_NO_CONTROL                         = 373,  // NYI
    SPELL_AURA_MODIFY_FALL_DAMAGE_PCT                       = 374,  // NYI
    SPELL_AURA_375                                          = 375,
    SPELL_AURA_MOD_CURRENCY_GAIN_FROM_SOURCE                = 376,  // NYI
    SPELL_AURA_CAST_WHILE_WALKING_2                         = 377,  // NYI
    SPELL_AURA_378                                          = 378,
    SPELL_AURA_MOD_MANA_REGEN_PCT                           = 379,
    SPELL_AURA_MOD_GLOBAL_COOLDOWN_BY_HASTE                 = 380,  // Allows melee abilities to benefit from haste GCD reduction
    SPELL_AURA_381                                          = 381,
    SPELL_AURA_MOD_PET_STAT_PCT                             = 382,  // NYI
    SPELL_AURA_IGNORE_SPELL_COOLDOWN                        = 383,  // NYI
    SPELL_AURA_384                                          = 384,
    SPELL_AURA_CHANCE_OVERRIDE_AUTOATTACK_WITH_SPELL_ON_SELF= 385,  // NYI (with triggered spell cast by the initial caster?)
    SPELL_AURA_386                                          = 386,
    SPELL_AURA_387                                          = 387,
    SPELL_AURA_MOD_TAXI_FLIGHT_SPEED                        = 388,  // NYI
    SPELL_AURA_389                                          = 389,
    SPELL_AURA_390                                          = 390,
    SPELL_AURA_391                                          = 391,
    SPELL_AURA_392                                          = 392,
    SPELL_AURA_393                                          = 393,
    SPELL_AURA_SHOW_CONFIRMATION_PROMPT                     = 394,
    SPELL_AURA_AREA_TRIGGER                                 = 395,  // NYI
    SPELL_AURA_TRIGGER_SPELL_ON_POWER_AMOUNT                = 396,  // NYI Triggers spell when health goes above (MiscA = 0) or falls below (MiscA = 1) specified percent value (once, not every time condition has meet)
    SPELL_AURA_397                                          = 397,
    SPELL_AURA_398                                          = 398,
    SPELL_AURA_399                                          = 399,
    SPELL_AURA_MOD_SKILL_2                                  = 400,
    SPELL_AURA_401                                          = 401,
    SPELL_AURA_MOD_OVERRIDE_POWER_DISPLAY                   = 402,
    SPELL_AURA_OVERRIDE_SPELL_VISUAL                        = 403,
    SPELL_AURA_OVERRIDE_ATTACK_POWER_BY_SP_PCT              = 404,
    SPELL_AURA_MOD_RATING_PCT                               = 405,  // NYI
    SPELL_AURA_KEYBOUND_OVERRIDE                            = 406,  // NYI
    SPELL_AURA_MOD_FEAR_2                                   = 407,  // NYI
    SPELL_AURA_408                                          = 408,
    SPELL_AURA_CAN_TURN_WHILE_FALLING                       = 409,
    SPELL_AURA_410                                          = 410,
    SPELL_AURA_MOD_MAX_CHARGES                              = 411,
    SPELL_AURA_412                                          = 412,
    SPELL_AURA_413                                          = 413,
    SPELL_AURA_414                                          = 414,
    SPELL_AURA_415                                          = 415,
    SPELL_AURA_MOD_COOLDOWN_BY_HASTE_REGEN                  = 416,
    SPELL_AURA_MOD_GLOBAL_COOLDOWN_BY_HASTE_REGEN           = 417,
    SPELL_AURA_MOD_MAX_POWER                                = 418,  // NYI
    SPELL_AURA_MOD_BASE_MANA_PCT                            = 419,
    SPELL_AURA_MOD_BATTLE_PET_XP_PCT                        = 420,  // NYI
    SPELL_AURA_MOD_ABSORB_EFFECTS_AMOUNT_PCT                = 421,  // NYI
    SPELL_AURA_422                                          = 422,
    SPELL_AURA_423                                          = 423,
    SPELL_AURA_424                                          = 424,
    SPELL_AURA_425                                          = 425,
    SPELL_AURA_426                                          = 426,
    SPELL_AURA_SCALE_PLAYER_LEVEL                           = 427,  // NYI
    SPELL_AURA_LINKED_SUMMON                                = 428,
    SPELL_AURA_429                                          = 429,
    SPELL_AURA_PLAY_SCENE                                   = 430,
    SPELL_AURA_MOD_OVERRIDE_ZONE_PVP_TYPE                   = 431,  // NYI
    SPELL_AURA_432                                          = 432,
    SPELL_AURA_433                                          = 433,
    SPELL_AURA_434                                          = 434,
    SPELL_AURA_435                                          = 435,
    SPELL_AURA_MOD_ENVIRONMENTAL_DAMAGE_TAKEN               = 436,  // NYI
    SPELL_AURA_MOD_MINIMUM_SPEED_RATE                       = 437,
    SPELL_AURA_PRELOAD_PHASE                                = 438,  // NYI
    SPELL_AURA_439                                          = 439,
    SPELL_AURA_MOD_MULTISTRIKE_DAMAGE                       = 440,  // NYI
    SPELL_AURA_MOD_MULTISTRIKE_CHANCE                       = 441,  // NYI
    SPELL_AURA_MOD_READINESS                                = 442,  // NYI
    SPELL_AURA_MOD_LEECH                                    = 443,  // NYI
    SPELL_AURA_444                                          = 444,
    SPELL_AURA_445                                          = 445,
    SPELL_AURA_446                                          = 446,
    SPELL_AURA_MOD_XP_FROM_CREATURE_TYPE                    = 447,
    SPELL_AURA_448                                          = 448,
    SPELL_AURA_449                                          = 449,
    SPELL_AURA_450                                          = 450,
    SPELL_AURA_OVERRIDE_PET_SPECS                           = 451,
    SPELL_AURA_452                                          = 452,
    SPELL_AURA_CHARGE_RECOVERY_MOD                          = 453,
    SPELL_AURA_CHARGE_RECOVERY_MULTIPLIER                   = 454,
    SPELL_AURA_MOD_ROOT_2                                   = 455,
    SPELL_AURA_CHARGE_RECOVERY_AFFECTED_BY_HASTE            = 456,
    SPELL_AURA_CHARGE_RECOVERY_AFFECTED_BY_HASTE_REGEN      = 457,
    SPELL_AURA_IGNORE_DUAL_WIELD_HIT_PENALTY                = 458,  // NYI
    SPELL_AURA_IGNORE_MOVEMENT_FORCES                       = 459,  // NYI
    SPELL_AURA_RESET_COOLDOWNS_ON_DUEL_START                = 460,  // NYI
    SPELL_AURA_461                                          = 461,
    SPELL_AURA_MOD_HEALING_AND_ABSORB_FROM_CASTER           = 462,  // NYI
    SPELL_AURA_CONVERT_CRIT_RATING_PCT_TO_PARRY_RATING      = 463,  // NYI
    SPELL_AURA_MOD_ATTACK_POWER_OF_BONUS_ARMOR              = 464,  // NYI
    SPELL_AURA_MOD_BONUS_ARMOR                              = 465,  // NYI
    SPELL_AURA_MOD_BONUS_ARMOR_PCT                          = 466,  // Affects bonus armor gain from all sources except base stats
    SPELL_AURA_MOD_STAT_BONUS_PCT                           = 467,  // Affects stat gain from all sources except base stats
    SPELL_AURA_TRIGGER_SPELL_ON_HEALTH_PCT                  = 468,  // Triggers spell when health goes above (MiscA = 0) or falls below (MiscA = 1) specified percent value (once, not every time condition has meet)
    SPELL_AURA_SHOW_CONFIRMATION_PROMPT_WITH_DIFFICULTY     = 469,
    SPELL_AURA_470                                          = 470,
    SPELL_AURA_MOD_VERSATILITY                              = 471,
    SPELL_AURA_472                                          = 472,
    SPELL_AURA_PREVENT_DURABILITY_LOSS_FROM_COMBAT          = 473,  // Prevents durability loss from dealing/taking damage
    SPELL_AURA_474                                          = 474,
    SPELL_AURA_ALLOW_USING_GAMEOBJECTS_WHILE_MOUNTED        = 475,
    SPELL_AURA_MOD_CURRENCY_GAIN_LOOTED                     = 476,
    SPELL_AURA_477                                          = 477,
    SPELL_AURA_478                                          = 478,
    SPELL_AURA_479                                          = 479,
    SPELL_AURA_480                                          = 480,
    SPELL_AURA_CONVERT_CONSUMED_RUNE                        = 481,
    SPELL_AURA_482                                          = 482,
    SPELL_AURA_SUPPRESS_TRANSFORMS                          = 483,  // NYI
    SPELL_AURA_484                                          = 484,
    SPELL_AURA_485                                          = 485,
    SPELL_AURA_486                                          = 486,
    SPELL_AURA_487                                          = 487,
    SPELL_AURA_488                                          = 488,
    SPELL_AURA_489                                          = 489,
    SPELL_AURA_490                                          = 490,
    SPELL_AURA_491                                          = 491,
    TOTAL_AURAS                                             = 492
};

enum AuraObjectType
{
    UNIT_AURA_TYPE,
    DYNOBJ_AURA_TYPE
};

#endif
