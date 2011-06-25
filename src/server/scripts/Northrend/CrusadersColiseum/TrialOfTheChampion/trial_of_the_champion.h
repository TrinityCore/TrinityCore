/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#ifndef DEF_TOC_H
#define DEF_TOC_H

enum eData
{
    BOSS_GRAND_CHAMPIONS,
    BOSS_ARGENT_CHALLENGE_E,
    BOSS_ARGENT_CHALLENGE_P,
    BOSS_BLACK_KNIGHT,
    DATA_MOVEMENT_DONE,
    DATA_LESSER_CHAMPIONS_DEFEATED,
    DATA_START,
    DATA_IN_POSITION,
    DATA_ARGENT_SOLDIER_DEFEATED,
    DATA_TEAM_IN_INSTANCE
};

enum Data64
{
    DATA_ANNOUNCER,
    DATA_MAIN_GATE,
    DATA_MAIN_GATE1,

    DATA_GRAND_CHAMPION_VEHICLE_1,
    DATA_GRAND_CHAMPION_VEHICLE_2,
    DATA_GRAND_CHAMPION_VEHICLE_3,

    DATA_GRAND_CHAMPION_1,
    DATA_GRAND_CHAMPION_2,
    DATA_GRAND_CHAMPION_3
};

enum eNpcs
{
    // Horde Champions
    NPC_MOKRA                   = 35572,
    NPC_ERESSEA                 = 35569,
    NPC_RUNOK                   = 35571,
    NPC_ZULTORE                 = 35570,
    NPC_VISCERI                 = 35617,

    // Alliance Champions
    NPC_JACOB                   = 34705,
    NPC_AMBROSE                 = 34702,
    NPC_COLOSOS                 = 34701,
    NPC_JAELYNE                 = 34657,
    NPC_LANA                    = 34703,

    // Faction champions horde
    NPC_ORGRIMAR_CHAMPION       = 35314,
    NPC_SILVERMOON_CHAMPION     = 35326,
    NPC_THUNDER_CHAMPION        = 35325,
    NPC_TROLL_CHAMPION          = 35323,
    NPC_UNDERCITY_CHAMPION      = 35327,

    // Faction champions alliance
    NPC_STORMWIND_CHAMPION      = 35328,
    NPC_GNOMERAGN_CHAMPION      = 35331,
    NPC_EXODAR_CHAMPION         = 35330,
    NPC_DRNASSUS_CHAMPION       = 35332,
    NPC_IRONFORGE_CHAMPION      = 35329,    

    NPC_EADRIC                  = 35119,
    NPC_PALETRESS               = 34928,

    NPC_ARGENT_LIGHWIELDER      = 35309,
    NPC_ARGENT_MONK             = 35305,
    NPC_PRIESTESS               = 35307,

    NPC_BLACK_KNIGHT            = 35451,

    NPC_RISEN_JAEREN            = 35545,
    NPC_RISEN_ARELAS            = 35564,
    
    // Announcer Start Event
    NPC_JAEREN                  = 35004,
    NPC_ARELAS                  = 35005,
    
    // Announcer
    NPC_JAEREN_AN               = 35591,
    NPC_ARELAS_AN               = 35592,

    // Memory
    MEMORY_ALGALON              = 35052,
    MEMORY_ARCHIMONDE           = 35041,
    MEMORY_CHROMAGGUS           = 35033,
    MEMORY_CYANIGOSA            = 35046,
    MEMORY_DELRISSA             = 35043,
    MEMORY_ECK                  = 35047,
    MEMORY_ENTROPIUS            = 35044,
    MEMORY_GRUUL                = 35039,
    MEMORY_HAKKAR               = 35034,
    MEMORY_HEIGAN               = 35049,
    MEMORY_HEROD                = 35030,
    MEMORY_HOGGER               = 34942,
    MEMORY_IGNIS                = 35050,
    MEMORY_ILLIDAN              = 35042,
    MEMORY_INGVAR               = 35045,
    MEMORY_KALITHRESH           = 35037,
    MEMORY_LUCIFRON             = 35031,
    MEMORY_MALCHEZAAR           = 35038,
    MEMORY_MUTANUS              = 35029,
    MEMORY_ONYXIA               = 35048,
    MEMORY_THUNDERAAN           = 35032,
    MEMORY_VANCLEEF             = 35028,
    MEMORY_VASHJ                = 35040,
    MEMORY_VEKNILASH            = 35036,
    MEMORY_VEZAX                = 35051
};

enum eGameObjects
{
    GO_MAIN_GATE                = 195647,
    GO_MAIN_GATE1               = 195650,

    GO_CHAMPIONS_LOOT           = 195709,
    GO_CHAMPIONS_LOOT_H         = 195710,

    GO_EADRIC_LOOT              = 195374,
    GO_EADRIC_LOOT_H            = 195375,

    GO_PALETRESS_LOOT           = 195323,
    GO_PALETRESS_LOOT_H         = 195324
};

enum eVehicles
{
    //Grand Champions Alliance Vehicles
    VEHICLE_MARSHAL_JACOB_ALERIUS_MOUNT             = 35637,
    VEHICLE_AMBROSE_BOLTSPARK_MOUNT                 = 35633,
    VEHICLE_COLOSOS_MOUNT                           = 35768,
    VEHICLE_EVENSONG_MOUNT                          = 34658,
    VEHICLE_LANA_STOUTHAMMER_MOUNT                  = 35636,
    //Faction Champions (ALLIANCE)
    VEHICLE_DARNASSIA_NIGHTSABER                    = 33319,
    VEHICLE_EXODAR_ELEKK                            = 33318,
    VEHICLE_STORMWIND_STEED                         = 33217,
    VEHICLE_GNOMEREGAN_MECHANOSTRIDER               = 33317,
    VEHICLE_IRONFORGE_RAM                           = 33316,
    //Grand Champions Horde Vehicles
    VEHICLE_MOKRA_SKILLCRUSHER_MOUNT                = 35638,
    VEHICLE_ERESSEA_DAWNSINGER_MOUNT                = 35635,
    VEHICLE_RUNOK_WILDMANE_MOUNT                    = 35640,
    VEHICLE_ZUL_TORE_MOUNT                          = 35641,
    VEHICLE_DEATHSTALKER_VESCERI_MOUNT              = 35634,
    //Faction Champions (HORDE)
    VEHICLE_FORSAKE_WARHORSE                        = 33324,
    VEHICLE_THUNDER_BLUFF_KODO                      = 33322,
    VEHICLE_ORGRIMMAR_WOLF                          = 33320,
    VEHICLE_SILVERMOON_HAWKSTRIDER                  = 33323,
    VEHICLE_DARKSPEAR_RAPTOR                        = 33321,

    VEHICLE_ARGENT_WARHORSE                         = 35644,
    VEHICLE_ARGENT_BATTLEWORG                       = 36558,

    VEHICLE_BLACK_KNIGHT                            = 35491
};

#endif
