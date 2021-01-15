/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#ifndef DEF_CRUSADER_H
#define DEF_CRUSADER_H

#include "CreatureAIImpl.h"

#define ToCrScriptName "instance_trial_of_the_crusader"
#define DataHeader "TCR"

struct Position;

enum TCRDataTypes
{
    BOSS_BEASTS                 = 0,
    BOSS_JARAXXUS               = 1,
    BOSS_CRUSADERS              = 2,
    BOSS_VALKIRIES              = 3,
    BOSS_LICH_KING              = 4,    // not really a boss but oh well
    BOSS_ANUBARAK               = 5,
    MAX_ENCOUNTERS              = 6,

    TYPE_COUNTER                = 8,
    TYPE_EVENT                  = 9,

    TYPE_EVENT_TIMER            = 101,
    TYPE_EVENT_NPC              = 102,
    TYPE_NORTHREND_BEASTS       = 103,

    DATA_SNOBOLD_COUNT          = 301,
    DATA_MISTRESS_OF_PAIN_COUNT = 302,

    INCREASE                    = 501,
    DECREASE                    = 502,
};

enum TCRSpellIds
{
    SPELL_WILFRED_PORTAL        = 68424,
    SPELL_JARAXXUS_CHAINS       = 67924,
    SPELL_CORPSE_TELEPORT       = 69016,
    SPELL_DESTROY_FLOOR_KNOCKUP = 68193,
};

enum TCRMiscData
{
    DESPAWN_TIME                = 1200000
};

extern Position const ToCCommonLoc[];
extern Position const AnubarakLoc[];

enum TCRWorldStateIds
{
    UPDATE_STATE_UI_SHOW            = 4390,
    UPDATE_STATE_UI_COUNT           = 4389
};

enum NorthrendBeasts
{
    GORMOK_IN_PROGRESS              = 1000,
    GORMOK_DONE                     = 1001,
    SNAKES_IN_PROGRESS              = 2000,
    DREADSCALE_SUBMERGED            = 2001,
    ACIDMAW_SUBMERGED               = 2002,
    SNAKES_SPECIAL                  = 2003,
    SNAKES_DONE                     = 2004,
    ICEHOWL_IN_PROGRESS             = 3000,
    ICEHOWL_DONE                    = 3001
};

enum AnnouncerMessages
{
    MSG_BEASTS                 = 724001,
    MSG_JARAXXUS               = 724002,
    MSG_CRUSADERS              = 724003,
    MSG_VALKIRIES              = 724004,
    MSG_LICH_KING              = 724005,
    MSG_ANUBARAK               = 724006
};

enum TCRCreatureIds
{
    NPC_BARRENT                 = 34816,
    NPC_TIRION                  = 34996,
    NPC_TIRION_FORDRING         = 36095,
    NPC_ARGENT_MAGE             = 36097,
    NPC_FIZZLEBANG              = 35458,
    NPC_GARROSH                 = 34995,
    NPC_VARIAN                  = 34990,
    NPC_LICH_KING               = 35877,

    NPC_THRALL                  = 34994,
    NPC_PROUDMOORE              = 34992,
    NPC_WILFRED_PORTAL          = 17965,
    NPC_TRIGGER                 = 35651,

    NPC_ICEHOWL                 = 34797,
    NPC_GORMOK                  = 34796,
    NPC_DREADSCALE              = 34799,
    NPC_ACIDMAW                 = 35144,

    NPC_JARAXXUS                = 34780,

    NPC_CHAMPIONS_CONTROLLER    = 34781,

    NPC_ALLIANCE_DEATH_KNIGHT           = 34461,
    NPC_ALLIANCE_DRUID_BALANCE          = 34460,
    NPC_ALLIANCE_DRUID_RESTORATION      = 34469,
    NPC_ALLIANCE_HUNTER                 = 34467,
    NPC_ALLIANCE_MAGE                   = 34468,
    NPC_ALLIANCE_PALADIN_HOLY           = 34465,
    NPC_ALLIANCE_PALADIN_RETRIBUTION    = 34471,
    NPC_ALLIANCE_PRIEST_DISCIPLINE      = 34466,
    NPC_ALLIANCE_PRIEST_SHADOW          = 34473,
    NPC_ALLIANCE_ROGUE                  = 34472,
    NPC_ALLIANCE_SHAMAN_ENHANCEMENT     = 34463,
    NPC_ALLIANCE_SHAMAN_RESTORATION     = 34470,
    NPC_ALLIANCE_WARLOCK                = 34474,
    NPC_ALLIANCE_WARRIOR                = 34475,

    NPC_HORDE_DEATH_KNIGHT              = 34458,
    NPC_HORDE_DRUID_BALANCE             = 34451,
    NPC_HORDE_DRUID_RESTORATION         = 34459,
    NPC_HORDE_HUNTER                    = 34448,
    NPC_HORDE_MAGE                      = 34449,
    NPC_HORDE_PALADIN_HOLY              = 34445,
    NPC_HORDE_PALADIN_RETRIBUTION       = 34456,
    NPC_HORDE_PRIEST_DISCIPLINE         = 34447,
    NPC_HORDE_PRIEST_SHADOW             = 34441,
    NPC_HORDE_ROGUE                     = 34454,
    NPC_HORDE_SHAMAN_ENHANCEMENT        = 34455,
    NPC_HORDE_SHAMAN_RESTORATION        = 34444,
    NPC_HORDE_WARLOCK                   = 34450,
    NPC_HORDE_WARRIOR                   = 34453,

    NPC_LIGHTBANE                       = 34497,
    NPC_DARKBANE                        = 34496,

    NPC_DARK_ESSENCE                    = 34567,
    NPC_LIGHT_ESSENCE                   = 34568,

    NPC_ANUBARAK                        = 34564
};

enum TCRGameObjectIds
{
    GO_CRUSADERS_CACHE_10       = 195631,
    GO_CRUSADERS_CACHE_25       = 195632,
    GO_CRUSADERS_CACHE_10_H     = 195633,
    GO_CRUSADERS_CACHE_25_H     = 195635,

    // Tribute Chest (heroic)
    // 10-man modes
    GO_TRIBUTE_CHEST_10H_25     = 195668, // 10man 01-24 attempts
    GO_TRIBUTE_CHEST_10H_45     = 195667, // 10man 25-44 attempts
    GO_TRIBUTE_CHEST_10H_50     = 195666, // 10man 45-49 attempts
    GO_TRIBUTE_CHEST_10H_99     = 195665, // 10man 50 attempts
    // 25-man modes
    GO_TRIBUTE_CHEST_25H_25     = 195672, // 25man 01-24 attempts
    GO_TRIBUTE_CHEST_25H_45     = 195671, // 25man 25-44 attempts
    GO_TRIBUTE_CHEST_25H_50     = 195670, // 25man 45-49 attempts
    GO_TRIBUTE_CHEST_25H_99     = 195669, // 25man 50 attempts

    GO_ARGENT_COLISEUM_FLOOR    = 195527, //20943
    GO_MAIN_GATE_DOOR           = 195647,
    GO_EAST_PORTCULLIS          = 195648,
    GO_WEB_DOOR                 = 195485,
    GO_PORTAL_TO_DALARAN        = 195682
};

enum TCRAchievementData
{
    // Northrend Beasts
    UPPER_BACK_PAIN_10_PLAYER               = 11779,
    UPPER_BACK_PAIN_10_PLAYER_HEROIC        = 11802,
    UPPER_BACK_PAIN_25_PLAYER               = 11780,
    UPPER_BACK_PAIN_25_PLAYER_HEROIC        = 11801,
    // Lord Jaraxxus
    THREE_SIXTY_PAIN_SPIKE_10_PLAYER        = 11838,
    THREE_SIXTY_PAIN_SPIKE_10_PLAYER_HEROIC = 11861,
    THREE_SIXTY_PAIN_SPIKE_25_PLAYER        = 11839,
    THREE_SIXTY_PAIN_SPIKE_25_PLAYER_HEROIC = 11862,
    // Tribute
    A_TRIBUTE_TO_SKILL_10_PLAYER            = 12344,
    A_TRIBUTE_TO_SKILL_25_PLAYER            = 12338,
    A_TRIBUTE_TO_MAD_SKILL_10_PLAYER        = 12347,
    A_TRIBUTE_TO_MAD_SKILL_25_PLAYER        = 12341,
    A_TRIBUTE_TO_INSANITY_10_PLAYER         = 12349,
    A_TRIBUTE_TO_INSANITY_25_PLAYER         = 12343,
    A_TRIBUTE_TO_IMMORTALITY_HORDE          = 12358,
    A_TRIBUTE_TO_IMMORTALITY_ALLIANCE       = 12359,
    A_TRIBUTE_TO_DEDICATED_INSANITY         = 12360,
    REALM_FIRST_GRAND_CRUSADER              = 12350,

    // Dummy spells - not existing in dbc but we don't need that
    SPELL_WORMS_KILLED_IN_10_SECONDS        = 68523,
    SPELL_CHAMPIONS_KILLED_IN_MINUTE        = 68620,
    SPELL_DEFEAT_FACTION_CHAMPIONS          = 68184,
    SPELL_TRAITOR_KING                      = 68186,

    // Timed events
    EVENT_START_TWINS_FIGHT                 = 21853
};

template <class AI, class T>
inline AI* GetTrialOfTheCrusaderAI(T* obj)
{
    return GetInstanceAI<AI>(obj, ToCrScriptName);
}

#endif
