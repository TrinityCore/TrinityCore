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
#define CRITERIA_CON_SPEED_ATORY                 21597

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
    TYPE_HODIR                  = 7,
    TYPE_THORIM                 = 8,
    TYPE_FREYA                  = 9,
    TYPE_MIMIRON                = 10,
    TYPE_VEZAX                  = 11,
    TYPE_YOGGSARON              = 12,
    TYPE_ALGALON                = 13,
    TYPE_COLOSSUS               = 14, // unused as encounter
    
    // Assembly of Iorn
    DATA_STEELBREAKER,
    DATA_MOLGEIM,
    DATA_BRUNDIR,

    // Razorscale
    DATA_EXP_COMMANDER,
    DATA_RAZORSCALE_CONTROL,

    // Kologarn:
    DATA_LEFT_ARM,
    DATA_RIGHT_ARM,

    // XT-002
    DATA_TOY_PILE_0,
    DATA_TOY_PILE_1,
    DATA_TOY_PILE_2,
    DATA_TOY_PILE_3,

    // Freya Elders
    TYPE_ELDER_BRIGHTLEAF,
    TYPE_ELDER_IRONBRANCH,
    TYPE_ELDER_STONEBARK,

    // Thorim
    DATA_RUNIC_COLOSSUS,
    DATA_RUNE_GIANT,
    DATA_RUNIC_DOOR,
    DATA_STONE_DOOR,
    DATA_HODIR_RARE_CHEST,

    // Algalon
    DATA_ALGALON_INTRO,
    DATA_ALGALON_TIMER,
    DATA_BRANN_ALGALON,

    // Mimiron
    DATA_LEVIATHAN_MK_II,
    DATA_MIMIRON_ELEVATOR,
    DATA_AERIAL_UNIT,
    DATA_VX_001,
    DATA_MAGNETIC_CORE,
    DATA_CALL_TRAM,

    // YoggSaron
    TYPE_SARA,
    TYPE_BRAIN_DOOR_1,
    TYPE_BRAIN_DOOR_2,
    TYPE_BRAIN_DOOR_3,
    DATA_ADD_HELP_FLAG,
    DATA_KEEPER_SUPPORT_YOGG,
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
    NPC_XT_TOY_PILE                              = 33337,
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
    NPC_AERIAL_COMMAND_UNIT     = 33670,
    NPC_MAGNETIC_CORE           = 34068,
    NPC_LEVIATHAN_MKII          = 33432,
    NPC_VX_001                  = 33651,
    NPC_HODIR                   = 32845,
    NPC_THORIM                  = 32865,
    NPC_RUNIC_COLOSSUS          = 32872,
    NPC_RUNE_GIANT              = 32873,
    NPC_FREYA                   = 32906,
    NPC_ELDER_IRONBRANCH        = 32913,
    NPC_ELDER_STONEBARK         = 32914,
    NPC_ELDER_BRIGHTLEAF        = 32915,
    NPC_VEZAX                   = 33271,
    NPC_YOGGSARON               = 33288,
    NPC_SARA                    = 33134,
    NPC_ALGALON                 = 32871,
    NPC_BRANN_ALGALON           = 34064,

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

    // Freya's trash NPCs
    NPC_CORRUPTED_SERVITOR      = 33354,
    NPC_MISGUIDED_NYMPH         = 33355,
    NPC_GUARDIAN_LASHER         = 33430,
    NPC_FOREST_SWARMER          = 33431,
    NPC_MANGROVE_ENT            = 33525,
    NPC_IRONROOT_LASHER         = 33526,
    NPC_NATURES_BLADE           = 33527,
    NPC_GUARDIAN_OF_LIFE        = 33528,
};

enum UlduarGameObjects
{
    GO_IRON_COUNCIL_ENTRANCE    = 194554,
    GO_ARCHIVUM_DOOR            = 194556,
    GO_KOLOGARN_CHEST_HERO      = 195047,
    GO_KOLOGARN_CHEST           = 195046,
    GO_KOLOGARN_BRIDGE          = 194232,
    GO_KOLOGARN_DOOR            = 194553,
    GO_THORIM_CHEST_HERO        = 194315,
    GO_THORIM_CHEST             = 194314,
    GO_THORIM_ENCOUNTER_DOOR    = 194559,
    GO_THORIM_STONE_DOOR        = 194558,
    GO_THORIM_RUNIC_DOOR        = 194557,
    GO_HODIR_RARE_CACHE_HERO    = 194201,
    GO_HODIR_RARE_CACHE         = 194200,
    GO_HODIR_CHEST_HERO         = 194308,
    GO_HODIR_CHEST              = 194307,
    GO_HODIR_IN_DOOR_STONE      = 194442,
    GO_HODIR_OUT_DOOR_ICE       = 194441,
    GO_HODIR_OUT_DOOR_STONE     = 194634,
    GO_FREYA_CHEST              = 194324,
    GO_FREYA_CHEST_HERO         = 194325,
    GO_FREYA_CHEST_HARD         = 194327,
    GO_FREYA_CHEST_HERO_HARD    = 194331,
    GO_LEVIATHAN_DOOR           = 194905,
    GO_LEVIATHAN_GATE           = 194630,
    GO_XT002_DOOR               = 194631,
    GO_MIMIRON_TRAIN            = 194675,
    GO_MIMIRON_ELEVATOR         = 194749,
    GO_MIMIRON_DOOR_1           = 194776,
    GO_MIMIRON_DOOR_2           = 194774,
    GO_MIMIRON_DOOR_3           = 194775,
    GO_BIG_RED_BUTTON           = 194739,
    GO_WAY_TO_YOGG              = 194255,
    GO_VEZAX_DOOR               = 194750,
    GO_YOGGSARON_DOOR           = 194773,
    GO_YOGGBRAIN_DOOR_1         = 194635,
    GO_YOGGBRAIN_DOOR_2         = 194636,
    GO_YOGGBRAIN_DOOR_3         = 194637,
    GO_MOLE_MACHINE             = 194316,
    GO_RAZOR_HARPOON_1          = 194542,
    GO_RAZOR_HARPOON_2          = 194541,
    GO_RAZOR_HARPOON_3          = 194543,
    GO_RAZOR_HARPOON_4          = 194519,
    GO_RAZOR_BROKEN_HARPOON     = 194565,
    GO_ALGALON_DOOR             = 194767,
    GO_ALGALON_FLOOR_COM        = 194715,
    GO_ALGALON_FLOOR_OOC        = 194716,
    GO_ALGALON_GLOBE            = 194148,
    GO_ALGALON_BRIDGE           = 194253,
    GO_ALGALON_INVISDOOR        = 194910,
    GO_ALGALON_CONSOLE          = 194628,
    GO_GIFT_OF_THE_OBSERVER     = 194821
};

enum UlduarTowerEvents
{
    EVENT_TOWER_OF_STORM_DESTROYED     = 21031,
    EVENT_TOWER_OF_FROST_DESTROYED     = 21032,
    EVENT_TOWER_OF_FLAMES_DESTROYED    = 21033,
    EVENT_TOWER_OF_LIFE_DESTROYED      = 21030
};

enum UlduarAchievements
{
    ACHIEVEMENT_CHAMPION_OF_ULDUAR      = 2903,
    ACHIEVEMENT_CONQUEROR_OF_ULDUAR     = 2904
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
    ACHIEVEMENT_CRITERIA_QUICK_SHAVE_25                             = 10063,
    ACHIEVEMENT_CRITERIA_THE_ASSASSINATION_OF_KING_LLANE_25         = 10321, // Yogg-Saron
    ACHIEVEMENT_CRITERIA_THE_ASSASSINATION_OF_KING_LLANE_10         = 10324,
    ACHIEVEMENT_CRITERIA_FORGING_OF_THE_DEMON_SOUL_25               = 10322,
    ACHIEVEMENT_CRITERIA_FORGING_OF_THE_DEMON_SOUL_10               = 10325,
    ACHIEVEMENT_CRITERIA_THE_TORTURED_CHAMPION_25                   = 10323,
    ACHIEVEMENT_CRITERIA_THE_TORTURED_CHAMPION_10                   = 10326,

    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_FLAMELEVIATAN_10       = 10042,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_IGNIS_10               = 10342,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_RAZORSCALE_10          = 10340,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_XT002_10               = 10341,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_ASSEMBLY_10            = 10598,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_KOLOGARN_10            = 10348,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_AURIAYA_10             = 10351,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_HODIR_10               = 10439,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_THORIM_10              = 10403,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_FREYA_10               = 10582,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_MIMIRON_10             = 10347,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_VEZAX_10               = 10349,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_YOGGSARON_10           = 10350,

    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_FLAMELEVIATAN_25       = 10352,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_IGNIS_25               = 10355,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_RAZORSCALE_25          = 10353,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_XT002_25               = 10354,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_ASSEMBLY_25            = 10599,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_KOLOGARN_25            = 10357,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_AURIAYA_25             = 10363,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_HODIR_25               = 10719,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_THORIM_25              = 10404,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_FREYA_25               = 10583,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_MIMIRON_25             = 10361,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_VEZAX_25               = 10362,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_YOGGSARON_25           = 10364,

    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_ALGALON_10             = 10568,
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_ALGALON_25             = 10570
};

enum UlduarKeeperSupport
{
    THORIM_SUPPORT                      = 0x01,
    HODIR_SUPPORT                       = 0x02,
    FREYA_SUPPORT                       = 0x04,
    MIMIRON_SUPPORT                     = 0x08
};

enum UlduarBossDeadFlags
{
    DEAD_FLAME_LEVIATHAN                = 0x0001,
    DEAD_IGNIS                          = 0x0002,
    DEAD_RAZORSCALE                     = 0x0004,
    DEAD_XT002                          = 0x0008,
    DEAD_ASSEMBLY                       = 0x0010,
    DEAD_KOLOGARN                       = 0x0020,
    DEAD_AURIAYA                        = 0x0040, 
    DEAD_HODIR                          = 0x0080,
    DEAD_THORIM                         = 0x0100,
    DEAD_FREYA                          = 0x0200,
    DEAD_MIMIRON                        = 0x0400,
    DEAD_VEZAX                          = 0x0800,
    DEAD_YOGGSARON                      = 0x1000
};

enum UlduarData
{
    DATA_PORTAL_PHASE = 1,
};

enum UlduarWorldStates
{
    WORLDSTATE_SHOW_TIMER       = 4132,
    WORLDSTATE_ALGALON_TIMER    = 4131
};

enum UlduarAchievementData
 {	
    DATA_KNOCK_ON_WOOD_ACHIEVEMENTS              = 1,
    DATA_CON_SPEED_ATORY_ACHIEVEMENT             = 2,
 };

enum UlduarSharedActions
{
    ACTION_ALGALON_ASCEND      = -123460 //Wipe Raid, don't respawn
};

class PlayerOrPetCheck
{
    public:
        bool operator() (Unit* unit)
        {
            if (unit->GetTypeId() != TYPEID_PLAYER)
                if (!unit->ToCreature()->isPet())
                    return true;

            return false;
        }
};

#endif