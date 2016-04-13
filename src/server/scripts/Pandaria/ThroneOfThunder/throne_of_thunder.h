/* 
 * Copyright (C) 2014-2015 Warlegend-Project <http://www.warlegend-project.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef THRONE_OF_THUNDER_H_
#define THRONE_OF_THUNDER_H_

#include "ScriptMgr.h"
#include "SpellScript.h"
#include "Map.h"
#include "Creature.h"
#include "CreatureAIImpl.h"
#include "ScriptMgr.h"

#define ToTScriptName "instance_throne_of_thunder"

enum eToTMisc
{
    TOT_MAPID                               = 1098,
};

enum eToTData
{
    DATA_JINROKH                            = 0,
    DATA_HORRIDON                           = 1,
    DATA_COUNCIL_OF_ELDERS                  = 2,
    DATA_TORTOS                             = 3,
    DATA_MEGAERA                            = 4,
    DATA_JI_KUN                             = 5,
    DATA_DURUMU_THE_FORGOTTEN               = 6,
    DATA_PRIMORDIUS                         = 7,
    DATA_DARK_ANIMUS                        = 8,
    DATA_IRON_QON                           = 9,
    DATA_TWIN_CONSORTS                      = 10,
    DATA_LEI_SHEN                           = 11,
    DATA_RA_DEN                             = 12,
    DATA_MAX_BOSS_DATA                      = 13,
};

enum eToTSharedActions
{
    SHARED_ACTION_ENTER_COMBAT              = 100,
    SHARED_ACTION_FAIL                      = 101,
};

enum eToTCreatures
{
    /* Encounters */

    // Last Stand of the Zandalari
    BOSS_JINROKH                            = 69465,

    BOSS_HORRIDON                           = 68476,
    // Council of Elders
    BOSS_COUNCIL_KAZRAJIN                   = 69134,
    BOSS_COUNCIL_SUL_THE_SANDCRAWLER        = 69078,
    BOSS_COUNCIL_FROST_KING_MALAKK          = 69131,
    BOSS_COUNCIL_HIGH_PRIESTESS_MARLI       = 69132,

    // Forgotten Depths
    BOSS_TORTOS                             = 67977,
    BOSS_MEGAERA                            = 70212,
    BOSS_JI_KUN                             = 69712,

    // Halls of Flesh-Shaping
    BOSS_DURUMU_THE_FORGOTTEN               = 68036,
    BOSS_PRIMORDIUS                         = 69017,
    BOSS_DARK_ANIMUS                        = 69427,

    // Pinnacle of Storms
    BOSS_IRON_QON                           = 68078,
    // Twin Consorts
    BOSS_LULIN                              = 68905,
    BOSS_SUEN                               = 68904,
    // Pinnacle of Storms
    BOSS_LEI_SHEN                           = 68397,
    BOSS_RA_DEN                             = 69473,

    /* Others */
    MOB_WAR_GOD_JALAK                       = 69374,
    NPC_HORRIDON_EVENT_HELPER               = 662202,
    
    // Council of Elders
    MOB_GARA_JAL                            = 69135,
    MOB_GARA_JALS_SOUL                      = 69182,
    NPC_COUNCIL_EVENT_HELPER                = 662203, 
    NPC_TWISTED_FATE_HELPER                 = 662204, 
};

enum eToTGameObjects
{
    //===============================================
    // Encounter doors
    GOB_JIN_ROKH_ENTRANCE                   = 218664,
    GOB_JIN_ROKH_EXIT                       = 218663,
    GOB_HORRIDON_ENTRANCE                   = 218667,
    GOB_HORRIDON_EXIT                       = 218666,
    GOB_COUNCIL_ENTRANCE                    = 218661,
    GOB_COUNCIL_EXIT                        = 218657,
    
    //===============================================
    // Horridon
    GOB_TRIBAL_DOOR_FARRAKI                 = 218672,
    GOB_TRIBAL_DOOR_GURUBASHI               = 218670,
    GOB_TRIBAL_DOOR_DRAKKARI                = 218671,
    GOB_TRIBAL_DOOR_AMANI                   = 218673,
};

template<typename AI, typename T> AI* GetThroneOfThunderAI(T* source)
{
    return GetInstanceAI<AI, T>(source, ToTScriptName);
}

#endif // THRONE_OF_THUNDER_H_
