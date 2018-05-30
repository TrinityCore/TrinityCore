/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2016 Firestorm Servers <https://firestorm-servers.com>
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

#ifndef MOGUSHAN_PALACE_H_
#define MOGUSHAN_PALACE_H_

#include "SpellScript.h"
#include "Map.h"
#include "Creature.h"
#include "CreatureAIImpl.h"

enum eData
{
    DATA_TRIAL_OF_THE_KING      = 0,
    DATA_GEKKAN                 = 1,
    DATA_XIN_THE_WEAPONMASTER   = 2,

    DATA_GEKKAN_ADDS            = 3
};

enum eTrashSpells
{
    //Kuai the brute
    SPELL_COMBAT_SOUND_LOOP         = 126252,
    SPELL_SHOCKWAVE                 = 119922,
    SPELL_PICK_SHOCKWAVE_TARGET     = 120499,
    SPELL_SHOCKWAVE_2               = 119929,
    SPELL_SHOCKWAVE_3               = 119930,
    SPELL_SHOCKWAVE_4               = 119931,
    SPELL_SHOCKWAVE_5               = 119932,
    SPELL_SHOCKWAVE_6               = 119933,
    SPELL_GUARDIAN_TAUNT            = 85667,
    //Ming the cunning
    SPELL_LIGHTNING_BOLT            = 123654,
    SPELL_WHIRLING_DERVISH          = 119981,
    SPELL_MAGNETIC_FIELD            = 120100,
    SPELL_MAGNETIC_FIELD_2          = 120101,
    SPELL_MAGNETIC_FIELD_3          = 120099,
    //Haiyan the unstoppable
    SPELL_TRAUMATIC_BLOW            = 123655,
    SPELL_CONFLAGRATE               = 120160,
    SPELL_CONFLAGRATE_2             = 120167,
    SPELL_CONFLAGRATE_3             = 120161,
    SPELL_CONFLAGRATE_4             = 120201,
    SPELL_METEOR                    = 120195,
    SPELL_METEOR_2                  = 120194,
    SPELL_METEOR_3                  = 120196,
    //Xin trigger
    SPELL_PING                      = 120510,
    SPELL_MOGU_JUMP                 = 120444,
    SPELL_THROW_DAMAGE              = 119311,
    SPELL_THROW_AURA                = 119315,
    SPELL_PERMANENT_FEIGN_DEATH     = 130966,
    SPELL_AXE_TOURBILOL             = 119373,
    //Gurthan scrapper, harthak adept and kargesh grunt
    SPELL_GRUNT_AURA                = 121746,
    //Whirling dervish trigger
    SPELL_WIRHLING_DERVISH_2        = 119982,
    SPELL_WHIRLING_DERVISH_3        = 119994,
    SPELL_THROW                     = 120087,
    SPELL_THROW_2                   = 120035,
};

enum eCreatures
{
    //Boss
    CREATURE_KUAI_THE_BRUTE                 = 61442,
    CREATURE_MING_THE_CUNNING               = 61444,
    CREATURE_HAIYAN_THE_UNSTOPPABLE         = 61445,
    CREATURE_XIN_THE_WEAPONMASTER_TRIGGER   = 61884,
    CREATURE_XIN_THE_WEAPONMASTER           = 61398,
    //Trash
    CREATURE_GURTHAN_SCRAPPER               = 61447,
    CREATURE_HARTHAK_ADEPT                  = 61449,
    CREATURE_KARGESH_GRUNT                  = 61450,
    //Trigger
    CREATURE_WHIRLING_DERVISH               = 61626,

    CREATURE_GEKKAN                         = 61243,
    CREATURE_GLINTROK_IRONHIDE              = 61337,
    CREATURE_GLINTROK_SKULKER               = 61338,
    CREATURE_GLINTROK_ORACLE                = 61339,
    CREATURE_GLINTROK_HEXXER                = 61340,

    //XIN THE WEAPONMASTER
    CREATURE_ANIMATED_STAFF                 = 61433,
    CREATURE_ANIMATED_AXE                   = 61451,
    CREATURE_LAUNCH_SWORD                   = 63808,
};

enum eTypes
{
    TYPE_MING_ATTACK = 4,   ///< Types are used as DATA_* with SetData function (WTF?!), so i make the enum start at 4 to avoid misconception error.
    TYPE_KUAI_ATTACK,
    TYPE_HAIYAN_ATTACK,
    TYPE_ALL_ATTACK,

    TYPE_MING_RETIRED,
    TYPE_KUAI_RETIRED,
    TYPE_HAIYAN_RETIRED,

    TYPE_WIPE_FIRST_BOSS,

    TYPE_MING_INTRO,
    TYPE_OUTRO_01,
    TYPE_OUTRO_02,
    TYPE_OUTRO_03,
    TYPE_OUTRO_04,
    TYPE_OUTRO_05,

    TYPE_GET_ENTOURAGE_0, //14
    TYPE_GET_ENTOURAGE_1, //15
    TYPE_GET_ENTOURAGE_2, //16
    TYPE_GET_ENTOURAGE_3, //17

    TYPE_ACTIVATE_ANIMATED_STAFF, //18
    TYPE_ACTIVATE_ANIMATED_AXE, //19
    TYPE_ACTIVATE_SWORD, //20
};

enum eGameObjects
{
    GO_DOOR_BEFORE_TRIAL    = 213594,
    GO_TRIAL_CHEST          = 214520,
    GO_DOOR_AFTER_TRIAL     = 213593,
    GO_DOOR_BEFORE_KING     = 213596,
};

#endif // MOGUSHAN_PALACE_H_
