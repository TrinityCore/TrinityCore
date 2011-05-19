/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#ifndef DEF_ULDUAR_H
#define DEF_ULDUAR_H

enum UlduarTypes
{
    MAX_ENCOUNTER               = 15,

    TYPE_LEVIATHAN              = 0,
    TYPE_IGNIS                  = 1,
    TYPE_RAZORSCALE             = 2,
    TYPE_XT002                  = 3,
    TYPE_ASSEMBLY               = 4,
    TYPE_KOLOGARN               = 5,
    TYPE_AURIAYA                = 6,
    TYPE_MIMIRON                = 7,
    TYPE_HODIR                  = 8,
    TYPE_THORIM                 = 9,
    TYPE_FREYA                  = 10,
    TYPE_VEZAX                  = 11,
    TYPE_YOGGSARON              = 12,
    TYPE_ALGALON                = 13,
    TYPE_COLOSSUS               = 14,

    // Assembly of Iorn
    DATA_STEELBREAKER,
    DATA_MOLGEIM,
    DATA_BRUNDIR,

    DATA_EXP_COMMANDER,
    DATA_RAZORSCALE_CONTROL,

    // Kologarn:
    DATA_LEFT_ARM,
    DATA_RIGHT_ARM,
};

enum UlduarNPCs
{
    NPC_LEVIATHAN               = 33113,
    NPC_IGNIS                   = 33118,
    NPC_RAZORSCALE              = 33186,
    NPC_RAZORSCALE_CONTROLLER   = 33233,
    NPC_STEELFORGED_DEFFENDER   = 33236,
    NPC_EXPEDITION_COMMANDER    = 33210,
    NPC_XT002                   = 33293,
    NPC_STEELBREAKER            = 32867,
    NPC_MOLGEIM                 = 32927,
    NPC_BRUNDIR                 = 32857,
    NPC_KOLOGARN                = 32930,
    NPC_KOLOGARN_BRIDGE         = 34297,
    NPC_FOCUSED_EYEBEAM         = 33632,
    NPC_FOCUSED_EYEBEAM_RIGHT   = 33802,
    NPC_LEFT_ARM                = 32933,
    NPC_RIGHT_ARM               = 32934,
    NPC_RUBBLE                  = 33768,
    NPC_AURIAYA                 = 33515,
    NPC_MIMIRON                 = 33350,
    NPC_HODIR                   = 32845,
    NPC_THORIM                  = 32865,
    NPC_FREYA                   = 32906,
    NPC_VEZAX                   = 33271,
    NPC_YOGGSARON               = 33288,
    NPC_ALGALON                 = 32871,
    NPC_LEVIATHAN_MKII          = 33432,
    NPC_VX_001                  = 33651,
    NPC_AERIAL_COMMAND_UNIT     = 33670,

    // Hodir's Helper NPCs
    NPC_TOR_GREYCLOUD           = 32941,
    NPC_KAR_GREYCLOUD           = 33333,
    NPC_EIVI_NIGHTFEATHER       = 33325,
    NPC_ELLIE_NIGHTFEATHER      = 32901,
    NPC_SPIRITWALKER_TARA       = 33332,
    NPC_SPIRITWALKER_YONA       = 32950,
    NPC_ELEMENTALIST_MAHFUUN    = 33328,
    NPC_ELEMENTALIST_AVUUN      = 32900,
    NPC_AMIRA_BLAZEWEAVER       = 33331,
    NPC_VEESHA_BLAZEWEAVER      = 32946,
    NPC_MISSY_FLAMECUFFS        = 32893,
    NPC_SISSY_FLAMECUFFS        = 33327,
    NPC_BATTLE_PRIEST_ELIZA     = 32948,
    NPC_BATTLE_PRIEST_GINA      = 33330,
    NPC_FIELD_MEDIC_PENNY       = 32897,
    NPC_FIELD_MEDIC_JESSI       = 33326,
};

enum UlduarGameObjects
{
    GO_KOLOGARN_CHEST_HERO  = 195047,
    GO_KOLOGARN_CHEST       = 195046,
    GO_KOLOGARN_BRIDGE      = 194232,
    GO_KOLOGARN_DOOR        = 194553,
    GO_THORIM_CHEST_HERO    = 194315,
    GO_THORIM_CHEST         = 194314,
    GO_HODIR_CHEST_HERO     = 194308,
    GO_HODIR_CHEST          = 194307,
    GO_FREYA_CHEST_HERO     = 194325,
    GO_FREYA_CHEST          = 194324,
    GO_LEVIATHAN_DOOR       = 194905,
    GO_LEVIATHAN_GATE       = 194630,
    GO_VEZAX_DOOR           = 194750,
    GO_MOLE_MACHINE         = 194316,
    GO_RAZOR_HARPOON_1      = 194542,
    GO_RAZOR_HARPOON_2      = 194541,
    GO_RAZOR_HARPOON_3      = 194543,
    GO_RAZOR_HARPOON_4      = 194519,
    GO_RAZOR_BROKEN_HARPOON = 194565,
};

enum UlduarTowerEvents
{
    EVENT_TOWER_OF_STORM_DESTROYED     = 21031,
    EVENT_TOWER_OF_FROST_DESTROYED     = 21032,
    EVENT_TOWER_OF_FLAMES_DESTROYED    = 21033,
    EVENT_TOWER_OF_LIFE_DESTROYED      = 21030
};

enum UlduarAchievementCriteria
{
    ACHIEVEMENT_UNBROKEN_10                              = 10044, // Leviathan
    ACHIEVEMENT_UNBROKEN_25                              = 10045,
    ACHIEVEMENT_CRITERIA_SHUTOUT_10                      = 10054,
    ACHIEVEMENT_CRITERIA_SHUTOUT_25                      = 10055,
    ACHIEVEMENT_CRITERIA_3_CAR_GARAGE_CHOPPER_10         = 10046,
    ACHIEVEMENT_CRITERIA_3_CAR_GARAGE_SIEGE_10           = 10047,
    ACHIEVEMENT_CRITERIA_3_CAR_GARAGE_DEMOLISHER_10      = 10048,
    ACHIEVEMENT_CRITERIA_3_CAR_GARAGE_CHOPPER_25         = 10049,
    ACHIEVEMENT_CRITERIA_3_CAR_GARAGE_SIEGE_25           = 10050,
    ACHIEVEMENT_CRITERIA_3_CAR_GARAGE_DEMOLISHER_25      = 10051,
    ACHIEVEMENT_CRITERIA_HOT_POCKET_10                   = 10430, // Ignis
    ACHIEVEMENT_CRITERIA_HOT_POCKET_25                   = 10431,
    ACHIEVEMENT_CRITERIA_QUICK_SHAVE_10                  = 10062, // Razorscale
    ACHIEVEMENT_CRITERIA_QUICK_SHAVE_25                  = 10063,
};

#endif
