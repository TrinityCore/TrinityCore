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

#include "antorus.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"
#include "ScriptedGossip.h"

enum eSays
{
    //Eonar
    SAY_PULL = 0,
    SAY_FINAL_DOOM = 1,
    SAY_LIFE_FORCE_1 = 2,
    SAY_LIFE_FORCE_2 = 3,
    SAY_LIFE_FORCE_3 = 4,
    SAY_LIFE_FORCE_4 = 5,
    SAY_WIPE = 6,

    //Paraxis
    SAY_WARN_SPEAR_OF_DOOM = 0,
    SAY_WARN_FINAL_DOOM = 1,
    SAY_WARN_PURGE = 2,
    SAY_WARN_RAIN_OF_FEL = 3,
};

enum Spells
{
    SPELL_OUTRO_CONV = 249674,
    SPELL_TELEPORT = 254245,
    SPELL_EONAR_BONUS_ROLL = 250602,
    SPELL_DAILY_ESSENCE_EONAR = 305311,

    //Eonar
    SPELL_LIFE_ENERGY = 257673,
    SPELL_LIFE_FORCE = 250048,
    SPELL_LIFE_FORCE_PARAXIS_DMG = 250030,
    SPELL_LIFE_FORCE_VISUAL = 250043,
    SPELL_LIFE_FORCE_FILTER = 250467,
    SPELL_LIFE_FORCE_DMG = 254269,

    SPELL_JUMP_PAD_AT = 248222,
    SPELL_SWIFT_FEET = 246330,
    SPELL_TELEPORTER_AT = 249094, //Mythic
    SPELL_TP_PLAYER_ON_PARAXIS = 249103,

    //Paraxis
    SPELL_WARP_IN = 247214,
    SPELL_PARAXIS_EXPLOSION = 250361, //Encounter finish
    SPELL_PARAXIS_ARTILLERY_PERIODIC = 248836,
    SPELL_PARAXIS_ARTILLERY_FILTER = 246313,
    SPELL_PARAXIS_ARTILLERY_DMG = 246315,
    SPELL_RAIN_OF_FEL_FILTER = 248326,
    SPELL_RAIN_OF_FEL_MARK = 248332,
    SPELL_RAIN_OF_FEL_DMG = 248329,

    SPELL_SPEAR_OF_DOOM_FILTER = 248861, //Heroic+
    SPELL_SPEAR_OF_DOOM_SUMMON = 248791,
    SPELL_SPEAR_OF_DOOM_AT = 248789,

    SPELL_FINAL_DOOM = 249121, //Mythic
    SPELL_PURGE = 249934,

    //Generic Trash
    SPELL_VISUAL_SMALL_SHIP = 246896,
    SPELL_VISUAL_BIG_SHIP = 246888,
    SPELL_DEMONIC_PORTAL_VISUAL = 247189,
    SPELL_SPAWN_TRASH_VISUAL = 246951,
    SPELL_STRIKE = 245851,

    //NPC_FELGUARD
    SPELL_FELGUARD_WEAPONS_VISUAL = 247922,

    //NPC_FEL_LORD
    SPELL_FEL_LORD_WEAPONS_VISUAL = 247928,

    //NPC_VOLANT_KERAPTERON
    SPELL_SPAWN_KERAPTERON_VISUAL = 246959,
    SPELL_DEMON_ESCAPE = 252309, //unk

    //NPC_FEL_CHARGED_OBFUSCATOR
    SPELL_CLOAK_AT = 246753,
    SPELL_CLOAK_MOD_DMG = 246748,

    //NPC_FEL_INFUSED_DESTRUCTOR
    SPELL_HIGH_ALERT = 254769,
    SPELL_ARTILLERY_STRIKE = 246305,
    SPELL_ARTILLERY_MODE = 246301,

    //NPC_FEL_POWERED_PURIFIER
    SPELL_PURIFIIER = 246745,
    SPELL_PURIFICATION_AT = 250073,
    SPELL_PURIFICATION_VISUAL = 255137,
    SPELL_PURIFIIER_HIGH_ALERT = 246233,
    SPELL_PURIFIIER_FEL_SHIELDING = 250555,
    SPELL_SWING_DUMMY = 250706,
    SPELL_SWING_RIGHT = 250701,
    SPELL_SWING_LEFT = 250703,

    //NPC_PARAXIS_INQUISITOR
    SPELL_MIND_BLAST = 249196,
    SPELL_PAIN = 249194,
    SPELL_WRACK = 249126,
    SPELL_TORMENT = 249155,

    //Focusing Crystal
    SPELL_SHATTER = 250081,
    SPELL_TARGETED = 249016,
    SPELL_BURNING_EMBERS = 249015,
    SPELL_FOUL_STEPS = 249014,
    SPELL_ARCANE_SINGULARITY = 249017,
};

enum Events
{
    //Eonar
    EVENT_ENGAGE = 1,

    //Paraxis
    EVENT_COMBAT_ZONE = 1,
    EVENT_CHECK_PLAYERS = 2,
    EVENT_SUMMON_SHIP = 3,
    EVENT_KERAPTERON_PORTAL = 4,
    EVENT_RAIN_OF_FEL = 5,
    EVENT_SPEAR_OF_DOOM = 6, //Heroic+
    EVENT_FINAL_DOOM = 7, //Mythic
};

enum Actions
{
    //Eonar
    ACTION_RESTART = 1,
    ACTION_ENCOUNTER_COMPLETE = 2,

    //Paraxis
    ACTION_EVADE = 1,
    ACTION_CRYSTAL_DISABLE = 2,

    ACTION_1,
    ACTION_2,

    EVENT_1,
    EVENT_2,
    EVENT_3,
};

enum eMisc
{
    GOSSIP_ID_EONAR = 21203,
    GOSSIP_EONAR_NOT_STARTED = 32173,
    GOSSIP_EONAR_DONE = 33006,

    PATH_MID = 12444500,
    PATH_TOP = 12444501,
    PATH_BOT = 12444502,
    PATH_FLY = 12444503,
};

//NPC_INVASION_POINT - VIGNETTE
Position const invastionPos[4] =
{
    {-3983.17f, -10928.7f, 721.68f, 0.095f}, //Mid
    {-3876.61f, -10931.9f, 685.84f, 0.095f}, //Bot
    {-3931.62f, -10673.2f, 751.47f, 0.095f}, //Top
    {-4010.63f, -10679.4f, 753.04f, 0.070f}  //Fly
};

Position const shipPos[6] =
{
    //NPC_LEGION_SHIP_SMALL
    {-3982.94f, -10864.4f, 755.08f, 0.09f}, //Mid
    {-3906.69f, -10938.6f, 755.08f, 0.04f}, //Bot
    {-3908.35f, -10699.5f, 783.14f, 0.06f}, //Top

    //NPC_LEGION_SHIP_BIG
    {-3995.78f, -10879.9f, 755.08f, 0.09f}, //Mid
    {-3875.13f, -10908.0f, 755.08f, 0.04f}, //Bot
    {-3961.0f,  -10653.3f, 785.81f, 0.06f}  //Top
};

Position const trashPos[4] =
{
    {-3993.1f, -10939.0f, 721.8f, 0.8f}, //Mid
    {-3880.1f, -10927.4f, 685.9f, 2.4f}, //Bot
    {-3927.6f, -10668.0f, 751.6f, 4.0f}, //Top
    {-4003.0f, -10650.1f, 760.0f, 4.6f}  //Fly
};

Position const destructorPos[3] =
{
    {-3995.67f, -10905.17f, 721.60f, 1.12f},
    {-3896.17f, -10900.24f, 685.96f, 1.88f},
    {-3948.66f, -10689.98f, 751.36f, 3.74f}
};

//Visual
Position const lifeForcePos[4] =
{
    {-4111.94f, -10677.2f,  736.0f},
    {-4105.15f, -10689.87f, 729.02f},
    {-4105.33f, -10728.01f, 736.0f},
    {-4132.49f, -10723.22f, 749.58f}
};

//AT from Paraxis
Position const teleportPos[8] =
{
    {-4011.47f, -10717.76f, 696.82f},
    {-4016.53f, -10728.44f, 696.84f},
    {-4018.30f, -10741.89f, 696.73f},
    {-4016.58f, -10751.54f, 696.73f},

    {-4216.47f, -10688.27f, 728.31f},
    {-4218.95f, -10709.31f, 728.31f},
    {-4195.60f, -10690.69f, 728.31f},
    {-4197.89f, -10711.79f, 728.31f}
};

void AddSC_boss_eonar()
{
   
}
