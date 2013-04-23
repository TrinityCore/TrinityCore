/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#include "ObjectMgr.h"
#define UlduarScriptName "instance_ulduar"

enum UlduarBosses
{
    MAX_ENCOUNTER            = 20,

    BOSS_LEVIATHAN           = 0,
    BOSS_IGNIS               = 1,
    BOSS_RAZORSCALE          = 2,
    BOSS_XT002               = 3,
    BOSS_ASSEMBLY_OF_IRON    = 4,
    BOSS_STEELBREAKER        = 5,
    BOSS_MOLGEIM             = 6,
    BOSS_BRUNDIR             = 7,
    BOSS_KOLOGARN            = 8,
    BOSS_AURIAYA             = 9,
    BOSS_MIMIRON             = 10,
    BOSS_HODIR               = 11,
    BOSS_THORIM              = 12,
    BOSS_FREYA               = 13,
    BOSS_BRIGHTLEAF          = 14,
    BOSS_IRONBRANCH          = 15,
    BOSS_STONEBARK           = 16,
    BOSS_VEZAX               = 17,
    BOSS_YOGGSARON           = 18,
    BOSS_ALGALON             = 19,
    BOSS_SARA                = 20,
    DATA_BRAIN_DOOR_1,
    DATA_BRAIN_DOOR_2,
    DATA_BRAIN_DOOR_3,
    DATA_KEEPER_SUPPORT_YOGG,

    // Razorscale
    DATA_EXPEDITION_COMMANDER,

    // Hodir
    DATA_HODIR_RARE_CACHE,

    // Collosus (Leviathan)
    DATA_COLOSSUS,               

    // Assembly of Iorn
    DATA_STEELBREAKER,
    DATA_MOLGEIM,
    DATA_BRUNDIR,

    DATA_EXP_COMMANDER,
    DATA_RAZORSCALE_CONTROL,

    // XT-002
    DATA_TOY_PILE_0,
    DATA_TOY_PILE_1,
    DATA_TOY_PILE_2,
    DATA_TOY_PILE_3,

    // Freya Elders
    DATA_ELDER_BRIGHTLEAF,
    DATA_ELDER_IRONBRANCH,
    DATA_ELDER_STONEBARK,

    // Thorim
    DATA_RUNIC_COLOSSUS,
    DATA_RUNE_GIANT,
    DATA_RUNIC_DOOR,
    DATA_STONE_DOOR,
    DATA_HODIR_RARE_CHEST,

    DATA_CALL_TRAM,
    // Mimiron
    DATA_LEVIATHAN_MK_II,
    DATA_VX_001,
    DATA_AERIAL_UNIT,
    DATA_MIMIRON_ELEVATOR,

    // Pre YoggSaron
    DATA_ADD_HELP_FLAG,

    // YoggSaron himself - phase during fight
    DATA_PORTAL_PHASE,
    DATA_IS_ENCOUNTER_IN_PROGRESS,
    DATA_BRAIN_EVT_CNT,
    DATA_KEEPER_CNT,

    // Algalon the Observer
    DATA_ALGALON_SUMMON_STATE,
    DATA_SIGILDOOR_01,
    DATA_SIGILDOOR_02,
    DATA_SIGILDOOR_03,
    DATA_UNIVERSE_FLOOR_01,
    DATA_UNIVERSE_FLOOR_02,
    DATA_UNIVERSE_GLOBE,
    DATA_ALGALON_TRAPDOOR,
    DATA_BRANN_BRONZEBEARD_ALG,
};

enum UlduarBossDeadFlags
{
    DEAD_NONE             =        0,   // Death is registered, but irrelevant
    DEAD_FLAME_LEVIATHAN  = (1 << 0),
    DEAD_IGNIS            = (1 << 1),
    DEAD_RAZORSCALE       = (1 << 2),
    DEAD_XT002            = (1 << 3),
    DEAD_ASSEMBLY         = (1 << 4),
    DEAD_KOLOGARN         = (1 << 5),
    DEAD_AURIAYA          = (1 << 6),
    DEAD_HODIR            = (1 << 7),
    DEAD_THORIM           = (1 << 8),
    DEAD_FREYA            = (1 << 9),
    DEAD_MIMIRON          = (1 << 10),
    DEAD_VEZAX            = (1 << 11),
    DEAD_YOGGSARON        = (1 << 12),
    DEAD_ALGALON          = (1 << 13)
};

enum UlduarNPCs
{
    NPC_LEVIATHAN               = 33113,
    NPC_SALVAGED_DEMOLISHER     = 33109,
    NPC_SALVAGED_SIEGE_ENGINE   = 33060,
    NPC_IGNIS                   = 33118,
    NPC_RAZORSCALE              = 33186,
    NPC_RAZORSCALE_CONTROLLER   = 33233,
    NPC_STEELFORGED_DEFFENDER   = 33236,
    NPC_EXPEDITION_COMMANDER    = 33210,
    NPC_XT002                   = 33293,
    NPC_XT_TOY_PILE             = 33337,
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
    NPC_RUNIC_COLOSSUS          = 32872,
    NPC_RUNE_GIANT              = 32873,
    NPC_FREYA                   = 32906,
    NPC_ELDER_IRONBRANCH        = 32913,
    NPC_ELDER_STONEBARK         = 32914,
    NPC_ELDER_BRIGHTLEAF        = 32915,
    NPC_VEZAX                   = 33271,
    NPC_YOGGSARON               = 33288,
    NPC_YOGGSARON_CTRL          = 29224,
    NPC_SARA                    = 33134,
    NPC_ALGALON                 = 32871,

    // Mimiron
    NPC_LEVIATHAN_MKII           = 33432,
    NPC_VX_001                   = 33651,
    NPC_AERIAL_COMMAND_UNIT      = 33670,

    NPC_MIMIRON_IMAGE            = 33412,

    // Freya's Keepers
    NPC_IRONBRANCH               = 32913,
    NPC_BRIGHTLEAF               = 32915,
    NPC_STONEBARK                = 32914,

    NPC_FREYA_IMAGE              = 33410,

    // Thorim
    NPC_THORIM_CTRL              = 32879,
    NPC_THORIM_IMAGE             = 33413,
    // Thorim_PrePhaseAddEntries
    NPC_JORMUNGAR_BEHEMOTH       = 32882,
    NPC_MERCENARY_CAPTAIN_A      = 32908,
    NPC_MERCENARY_SOLDIER_A      = 32885,
    NPC_DARK_RUNE_ACOLYTE        = 32886,
    NPC_MERCENARY_CAPTAIN_H      = 32907,
    NPC_MERCENARY_SOLDIER_H      = 32883,

    // Hodir's Helper NPCs
    NPC_TOR_GREYCLOUD            = 32941,
    NPC_KAR_GREYCLOUD            = 33333,
    NPC_EIVI_NIGHTFEATHER        = 33325,
    NPC_ELLIE_NIGHTFEATHER       = 32901,
    NPC_SPIRITWALKER_TARA        = 33332,
    NPC_SPIRITWALKER_YONA        = 32950,
    NPC_ELEMENTALIST_MAHFUUN     = 33328,
    NPC_ELEMENTALIST_AVUUN       = 32900,
    NPC_AMIRA_BLAZEWEAVER        = 33331,
    NPC_VEESHA_BLAZEWEAVER       = 32946,
    NPC_MISSY_FLAMECUFFS         = 32893,
    NPC_SISSY_FLAMECUFFS         = 33327,
    NPC_BATTLE_PRIEST_ELIZA      = 32948,
    NPC_BATTLE_PRIEST_GINA       = 33330,
    NPC_FIELD_MEDIC_PENNY        = 32897,
    NPC_FIELD_MEDIC_JESSI        = 33326,

    NPC_HODIR_IMAGE              = 33411,

    // Freya's trash NPCs
    NPC_CORRUPTED_SERVITOR       = 33354,
    NPC_MISGUIDED_NYMPH          = 33355,
    NPC_GUARDIAN_LASHER          = 33430,
    NPC_FOREST_SWARMER           = 33431,
    NPC_MANGROVE_ENT             = 33525,
    NPC_IRONROOT_LASHER          = 33526,
    NPC_NATURES_BLADE            = 33527,
    NPC_GUARDIAN_OF_LIFE         = 33528,

    // Algalon the Observer
    NPC_BRANN_BRONZBEARD_ALG                = 34064,
    NPC_PROSPECTOR_DOREN                    = 33956,
    NPC_AZEROTH                             = 34246,
    NPC_LIVING_CONSTELLATION                = 33052,
    NPC_ALGALON_STALKER                     = 33086,
    NPC_COLLAPSING_STAR                     = 32955,
    NPC_BLACK_HOLE                          = 32953,
    NPC_WORM_HOLE                           = 34099,
    NPC_ALGALON_VOID_ZONE_VISUAL_STALKER    = 34100,
    NPC_ALGALON_STALKER_ASTEROID_TARGET_01  = 33104,
    NPC_ALGALON_STALKER_ASTEROID_TARGET_02  = 33105,
    NPC_UNLEASHED_DARK_MATTER               = 34097,
};

enum UlduarGameObjects
{
    GO_IRON_COUNCIL_ENTRANCE    = 194554,
    GO_ARCHIVUM_DOOR            = 194556,

    GO_KOLOGARN_CHEST_HERO      = 195047,
    GO_KOLOGARN_CHEST           = 195046,
    GO_KOLOGARN_BRIDGE          = 194232,
    GO_KOLOGARN_DOOR            = 194553,

    GO_THORIM_DARK_IRON_PROTCULLIS  = 194560,
    GO_THORIM_CHEST_HERO            = 194315,
    GO_THORIM_CHEST                 = 194314,
    GO_THORIM_LIGHTNING_FIELD       = 194559,
    GO_THORIM_STONE_DOOR            = 194558,
    GO_THORIM_RUNIC_DOOR            = 194557,

    GO_HODIR_RARE_CACHE_OF_WINTER_HERO  = 194201,
    GO_HODIR_RARE_CACHE_OF_WINTER       = 194200,
    GO_HODIR_CHEST_HERO                 = 194308,
    GO_HODIR_CHEST                      = 194307,
    GO_HODIR_IN_DOOR_STONE              = 194442,
    GO_HODIR_OUT_DOOR_ICE               = 194441,
    GO_HODIR_OUT_DOOR_STONE             = 194634,

    GO_FREYA_CHEST              = 194324,
    GO_FREYA_CHEST_HERO         = 194325,
    GO_FREYA_CHEST_HARD         = 194327,
    GO_FREYA_CHEST_HERO_HARD    = 194331,

    GO_LEVIATHAN_DOOR           = 194905,
    GO_LEVIATHAN_GATE           = 194630,

    GO_XT_002_DOOR              = 194631,

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

    GO_ALGALON_ACCESS           = 194628,
    GO_ALGALON_DOOR_1           = 194911,
    GO_ALGALON_DOOR_2           = 194767,
    GO_ALGALON_PLATFORM         = 194715,
    GO_ALGALON_GLOBE            = 194148,
    GO_ALGALON_BRIDGE           = 194253,
    GO_ALGALON_B_VISUAL         = 194716,
    GO_ALGALON_B_DOOR           = 194910,
    GO_GIFT_OF_THE_OBSERVER_10  = 194821,
    GO_GIFT_OF_THE_OBSERVER_25  = 194822,
    // Dummies - not yet in db
    GO_LEVIATHAN_CHEST_10       = 555555,
    GO_LEVIATHAN_CHEST_25       = 444444
};

enum UlduarTowerEvents // Separated from other data, since that's the relevant point which decides for hardmode 
{
    EVENT_TOWER_OF_STORM_DESTROYED      = 21031,
    EVENT_TOWER_OF_FROST_DESTROYED      = 21032,
    EVENT_TOWER_OF_FLAMES_DESTROYED     = 21033,
    EVENT_TOWER_OF_LIFE_DESTROYED       = 21030,
};

enum LeviathanData  
{
    ACTION_TOWER_OF_STORM_DESTROYED     = 1,
    ACTION_TOWER_OF_FROST_DESTROYED     = 2,
    ACTION_TOWER_OF_FLAMES_DESTROYED    = 3,
    ACTION_TOWER_OF_LIFE_DESTROYED      = 4,
    ACTION_MOVE_TO_CENTER_POSITION      = 10,
};

// TODO: Review those
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
    ACHIEVEMENT_CRITERIA_KILL_WITHOUT_DEATHS_ALGALON_25             = 10570,
    ACHIEVEMENT_CRITERIA_CON_SPEED_ATORY                            = 21597,
    ACHIEVEMENT_CRITERIA_DISARMED                                   = 21687,
    ACHIEVEMENT_CRITERIA_HERALD_OF_TITANS                           = 10678,
};

// Achievements for "Do not die during boss-fights"
enum UlduarAchievements
{
    ACHIEVEMENT_CHAMPION_OF_ULDUAR      = 2903,
    ACHIEVEMENT_CONQUEROR_OF_ULDUAR     = 2904
};

// Used for Yogg-Saron fight
enum UlduarKeeperSupport
{
    THORIM_SUPPORT                      = (1 << 0),
    HODIR_SUPPORT                       = (1 << 1),
    FREYA_SUPPORT                       = (1 << 2),
    MIMIRON_SUPPORT                     = (1 << 3)
};

enum UlduarAchievementData
{
    // FL Achievement boolean
    DATA_UNBROKEN = 29052906, // 2905, 2906 are achievement IDs,
    MAX_HERALD_ARMOR_ITEMLEVEL  = 226,
    MAX_HERALD_WEAPON_ITEMLEVEL = 232,
};

enum UlduarEvents
{
    EVENT_DESPAWN_ALGALON       = 1,
    EVENT_UPDATE_ALGALON_TIMER  = 2,
    ACTION_INIT_ALGALON         = 6,
};

enum UlduarWorldstates
{
    WORLD_STATE_ALGALON_DESPAWN_TIMER = 4131,
    WORLD_STATE_ALGALON_TIMER_ENABLED = 4132
};

enum UlduarArea
{
    MAP_ULDUAR              = 603,
    AREA_FORMATION_GROUNDS  = 4652
};

enum UlduarFactions
{
    FACTION_HOSTILE = 14,
    FACTION_FRIENDLY = 35
};

// leviathans spawn position after wipe
Position const Center =
{
    354.8771f, -12.90240f, 409.803650f, 3.05873f
};

template<class AI>
CreatureAI* GetUlduarAI(Creature* creature)
{
    if (InstanceMap* instance = creature->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId(UlduarScriptName))
                return new AI(creature);

    return NULL;
}

template<class AI>
GameObjectAI* GetUlduarAI(GameObject* go)
{
    if (InstanceMap* instance = go->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId(UlduarScriptName))
                return new AI(go);

    return NULL;
}

class PlayerOrPetCheck
{
    public:
        bool operator() (WorldObject* unit)
        {
            if (unit->GetTypeId() != TYPEID_PLAYER)
                if (!unit->ToCreature()->isPet())
                    return true;

            return false;
        }
};

class NoPlayerOrPetCheck
{
    public:
        bool operator() (WorldObject* unit)
        {
            if (unit->GetTypeId() != TYPEID_PLAYER)
                if (!unit->ToCreature()->isPet())
                    return false;

            return true;
        }
};

#endif
