#ifndef _BOTCOMMON_H
#define _BOTCOMMON_H

#include "ObjectGuid.h"
#include "SharedDefines.h"
#include "SpellAuraDefines.h"

#include <utility>
#include <vector>

/*
NpcBot System by Trickerer (onlysuffering@gmail.com)
Original patch from: LordPsyan https://bitbucket.org/lordpsyan/trinitycore-patches/src/3b8b9072280e/Individual/11185-BOTS-NPCBots.patch
*/

constexpr std::size_t MAX_BOT_LOG_PARAMS = 5;
constexpr std::size_t MAX_BOT_LOG_PARAM_LENGTH = 50;

struct Position;

typedef std::vector<std::pair<Position, float> > AoeSpotsVec;
typedef std::vector<Position> AoeSafeSpotsVec;

enum BotCommonValues
{
//MISC
    BOT_GIVER_ENTRY                     = 70000,
    BOT_ENTRY_BEGIN                     = 70001,
    //BOT_ENTRY_END                       = 71000,
    BOT_ENTRY_CREATE_BEGIN              = 70800, // 70800+ reserved for bot creation
    //BOT_PET_ENTRY_BEGIN                 = 70501,
    //BOT_PET_ENTRY_END                   = 70550,
    BOT_ENTRY_MIRROR_IMAGE_BM           = 70552,
    BOT_MAX_CHASE_RANGE                 = 120,  //yds
    //BOT_EVADE_TIME                      = 3000, //ms
//COMMON GAMEOBJECTS
    GO_REFRESHMENT_TABLE_1              = 186812,//lvl 65 req70
    GO_REFRESHMENT_TABLE_2              = 193061,//lvl 80 req80
    GO_SOULWELL_1                       = 181621,//lvl 60 req68
    GO_SOULWELL_2                       = 193169,//lvl 69 req80
    GO_BOT_MONEY_BAG                    = 186736,
//COMMON CDs
    POTION_CD                           = 60000,//default 60sec potion cd
    REGEN_CD                            = 1000, //update hp/mana every X milliseconds
//COMMON TIMERS
    ITEM_ENCHANTMENT_EXPIRE_TIMER       = 3600000, //1 Hour
    REVIVE_TIMER_DEFAULT                = 180000, //3 Minutes
    REVIVE_TIMER_MEDIUM                 = 90000, //1.5 Minutes
    REVIVE_TIMER_SHORT                  = 60000, //1 Minute
    INOUTDOORS_ENSURE_TIMER             = 1500,
    BOT_GROUP_UPDATE_TIMER              = 2000,
//VEHICLE CREATURES
    CREATURE_NEXUS_SKYTALON_1           = 32535, // [Q] Aces High
    CREATURE_EOE_SKYTALON_N             = 30161, // Eye of Eternity
    CREATURE_EOE_SKYTALON_H             = 31752,
    CREATURE_OCULUS_DRAKE_RUBY          = 27756, // Oculus
    CREATURE_OCULUS_DRAKE_EMERALD       = 27692,
    CREATURE_OCULUS_DRAKE_AMBER         = 27755,
    //CREATURE_TOC_STEED_QUELDOREI        = 33845, // Argent Tournament
    //CREATURE_TOC_NIGHTSABER             = 33319,
    //CREATURE_TOC_STEED_STORMWIND        = 33217,
    //CREATURE_TOC_MECHANOSTRIDER         = 33317,
    //CREATURE_TOC_RAM                    = 33316,
    //CREATURE_TOC_ELEKK                  = 33318,
    //CREATURE_TOC_HAWKSTRIDER_SUNREAVER  = 33844,
    //CREATURE_TOC_RAPTOR                 = 33321,
    //CREATURE_TOC_WARHORSE               = 33324,
    //CREATURE_TOC_WOLF                   = 33320,
    //CREATURE_TOC_HAWKSTRIDER_SILVERMOON = 33323,
    //CREATURE_TOC_KODO                   = 33322,
    CREATURE_TOC5_WARHORSE              = 35644, // Trial of Champion
    CREATURE_TOC5_BATTLEWORG            = 36558,
    CREATURE_ULDUAR_DEMOLISHER          = 33109, // Ulduar
    CREATURE_ULDUAR_SIEGE_ENGINE        = 33060,
    CREATURE_ULDUAR_CHOPPER             = 33062,
    CREATURE_ULDUAR_CHOPPER1            = 34045,
    CREATURE_ICC_BONE_SPIKE1            = 36619, // Icecrown Citadel
    CREATURE_ICC_BONE_SPIKE2            = 38712,
    CREATURE_ICC_BONE_SPIKE3            = 38711,
    CREATURE_ICC_GUNSHIPCANNON_ALLIANCE = 36838,
    CREATURE_ICC_GUNSHIPCANNON_HORDE    = 36839,
    CREATURE_ICC_MUTATED_ABOMINATION1   = 38285,
    CREATURE_ICC_MUTATED_ABOMINATION2   = 38788,
    CREATURE_ICC_MUTATED_ABOMINATION3   = 38789,
    CREATURE_ICC_MUTATED_ABOMINATION4   = 38790,
    CREATURE_ICC_MUTATED_ABOMINATION5   = 37672,
    CREATURE_ICC_MUTATED_ABOMINATION6   = 38605,
    CREATURE_ICC_MUTATED_ABOMINATION7   = 38786,
    CREATURE_ICC_MUTATED_ABOMINATION8   = 38787,
//COMMON AOE TRIGGERS
    CREATURE_FOCUS_FIRE_N               = 18374,
    CREATURE_FOCUS_FIRE_H               = 20308,
    CREATURE_MT_PHOENIX                 = 24674,
    CREATURE_MT_ARCANE_SPHERE_N         = 24708,
    CREATURE_MT_ARCANE_SPHERE_H         = 25543,
    CREATURE_ZA_FIRE_BOMB               = 23920,
    CREATURE_UK_SHADOW_AXE_N            = 23997,
    CREATURE_UK_SHADOW_AXE_H            = 31835,
    CREATURE_EOE_STATIC_FIELD           = 30592,
    CREATURE_ICC_OOZE_PUDDLE            = 37690,
    GAMEOBJECT_HOT_COAL                 = 178164,
//COMMON ENEMY CREATURES
    CREATURE_BOSS_EREGOS_N              = 27656,
    CREATURE_BOSS_EREGOS_H              = 31561,
    CREATURE_ICC_SINDRAGOSA1            = 36853,
    CREATURE_ICC_SINDRAGOSA2            = 38265,
    CREATURE_ICC_SINDRAGOSA3            = 38266,
    CREATURE_ICC_SINDRAGOSA4            = 38267,
    CREATURE_ICC_ICE_TOMB1              = 36980,
    CREATURE_ICC_ICE_TOMB2              = 38320,
    CREATURE_ICC_ICE_TOMB3              = 38321,
    CREATURE_ICC_ICE_TOMB4              = 38322,
    CREATURE_ICC_VALKYR_LK1             = 36609,
    CREATURE_ICC_VALKYR_LK2             = 39120,
    CREATURE_ICC_VALKYR_LK3             = 39121,
    CREATURE_ICC_VALKYR_LK4             = 39122,
    CREATURE_ICC_ICE_SPHERE1            = 36633,
    CREATURE_ICC_ICE_SPHERE2            = 39305,
    CREATURE_ICC_ICE_SPHERE3            = 39306,
    CREATURE_ICC_ICE_SPHERE4            = 39307,
//COMMON NPCS
    SHAMAN_EARTH_ELEMENTAL              = 15352,
    SHAMAN_FIRE_ELEMENTAL               = 15438,
    //NPC_WORLD_TRIGGER                   = 22515,
//COMMON ITEM DISPLAY IDS
    CHEST_HALISCAN                      = 50566, //Haliscan Jacket
    LEGS_HALISCAN                       = 50567, //Haliscan Pants
//COMMON GAMEEVENTS
    GAME_EVENT_WINTER_VEIL              = 2,
//COMMON FACTIONS
    FACTION_TEMPLATE_HATES_EVERYTHING_1 = 2150, //faction 966 - Monster spar buddy
//COMMON AI MISC VALUES
    BOTAI_MISC_COMBO_POINTS             = 1,
    BOTAI_MISC_DAGGER_MAINHAND,
    BOTAI_MISC_DAGGER_OFFHAND,
    BOTAI_MISC_ENCHANT_IS_AUTO_MH,
    BOTAI_MISC_ENCHANT_IS_AUTO_OH,
    BOTAI_MISC_ENCHANT_CAN_EXPIRE_MH,
    BOTAI_MISC_ENCHANT_CAN_EXPIRE_OH,
    BOTAI_MISC_ENCHANT_CURRENT_MH,
    BOTAI_MISC_ENCHANT_CURRENT_OH,
    BOTAI_MISC_ENCHANT_AVAILABLE_1,
    BOTAI_MISC_ENCHANT_AVAILABLE_2,
    BOTAI_MISC_ENCHANT_AVAILABLE_3,
    BOTAI_MISC_ENCHANT_AVAILABLE_4,
    BOTAI_MISC_ENCHANT_AVAILABLE_5,
    BOTAI_MISC_ENCHANT_AVAILABLE_6,
    BOTAI_MISC_PET_TYPE,
    BOTAI_MISC_PET_AVAILABLE_1,
    BOTAI_MISC_PET_AVAILABLE_2,
    BOTAI_MISC_PET_AVAILABLE_3,
    BOTAI_MISC_PET_AVAILABLE_4,
    BOTAI_MISC_PET_AVAILABLE_5,
    BOTAI_MISC_PET_AVAILABLE_6,
    BOTAI_MISC_PET_AVAILABLE_7,
    BOTAI_MISC_PET_AVAILABLE_8,
    BOTAI_MISC_PET_AVAILABLE_9,
    BOTAI_MISC_PET_AVAILABLE_10,
    BOTAI_MISC_PET_AVAILABLE_11,
    BOTAI_MISC_WEAPON_SPEC,
    BOTPETAI_MISC_DURATION,
    BOTPETAI_MISC_DURATION_MAX,
    BOTPETAI_MISC_MAXLEVEL,
    BOTPETAI_MISC_FIXEDLEVEL,
    BOTPETAI_MISC_CARRY,
    BOTPETAI_MISC_CAPACITY,
    BOTPETAI_MISC_MAX_ATTACKERS,
  //SOUNDS
    SOUND_FREEZE_IMPACT_WINDWALK        = 29,
    SOUND_AXE_2H_IMPACT_FLESH_CRIT      = 158,
    SOUND_ABSORB_GET_HIT                = 3334,
    SOUND_MISS_WHOOSH_2H                = 7081,

//UNUSED

    //MAX_LOOT_ITEMS                      = 18 // Client limitation 3.3.5 code confirmed
};

enum BotClasses : uint8
{
    BOT_CLASS_NONE                      = CLASS_NONE,
    BOT_CLASS_WARRIOR                   = CLASS_WARRIOR,
    BOT_CLASS_PALADIN                   = CLASS_PALADIN,
    BOT_CLASS_HUNTER                    = CLASS_HUNTER,
    BOT_CLASS_ROGUE                     = CLASS_ROGUE,
    BOT_CLASS_PRIEST                    = CLASS_PRIEST,
    BOT_CLASS_DEATH_KNIGHT              = CLASS_DEATH_KNIGHT,
    BOT_CLASS_SHAMAN                    = CLASS_SHAMAN,
    BOT_CLASS_MAGE                      = CLASS_MAGE,
    BOT_CLASS_WARLOCK                   = CLASS_WARLOCK,
    BOT_CLASS_DRUID                     = CLASS_DRUID,

    BOT_CLASS_BM,
    BOT_CLASS_SPHYNX,
    BOT_CLASS_ARCHMAGE,
    BOT_CLASS_DREADLORD,
    BOT_CLASS_SPELLBREAKER,
    BOT_CLASS_DARK_RANGER,
    BOT_CLASS_NECROMANCER,
    BOT_CLASS_SEA_WITCH,
    BOT_CLASS_CRYPT_LORD,

    BOT_CLASS_END,

    BOT_CLASS_EX_START                  = BOT_CLASS_BM
};

constexpr uint32 ALL_BOT_CLASSES_MASK =
    ((1 << BOT_CLASS_WARRIOR)|(1 << BOT_CLASS_PALADIN)|(1 << BOT_CLASS_HUNTER)|(1 << BOT_CLASS_ROGUE)|(1 << BOT_CLASS_PRIEST)|
    (1 << BOT_CLASS_DEATH_KNIGHT)|(1 << BOT_CLASS_SHAMAN)|(1 << BOT_CLASS_MAGE)|(1 << BOT_CLASS_WARLOCK)|(1 << BOT_CLASS_DRUID)|
    (1 << BOT_CLASS_BM)|(1 << BOT_CLASS_SPHYNX)|(1 << BOT_CLASS_ARCHMAGE)|(1 << BOT_CLASS_DREADLORD)|(1 << BOT_CLASS_SPELLBREAKER)|
    (1 << BOT_CLASS_DARK_RANGER)|(1 << BOT_CLASS_NECROMANCER)|(1 << BOT_CLASS_SEA_WITCH)|(1 << BOT_CLASS_CRYPT_LORD));

enum BotStances
{
    BOT_STANCE_NONE                     = 0,
    WARRIOR_BATTLE_STANCE               = BOT_CLASS_END,
    WARRIOR_DEFENSIVE_STANCE,
    WARRIOR_BERSERKER_STANCE,
    DEATH_KNIGHT_BLOOD_PRESENCE,
    DEATH_KNIGHT_FROST_PRESENCE,
    DEATH_KNIGHT_UNHOLY_PRESENCE,
    DRUID_BEAR_FORM,
    DRUID_CAT_FORM,
    DRUID_MOONKIN_FORM,
    DRUID_TREE_FORM,
    DRUID_TRAVEL_FORM,
    DRUID_AQUATIC_FORM,
    DRUID_FLIGHT_FORM
};

enum BotRoles : uint32
{
    BOT_ROLE_NONE                       = 0x00000,
    BOT_ROLE_TANK                       = 0x00001,
    BOT_ROLE_TANK_OFF                   = 0x00002,
    BOT_ROLE_DPS                        = 0x00004,
    BOT_ROLE_HEAL                       = 0x00008,
    BOT_ROLE_RANGED                     = 0x00010,

    BOT_ROLE_PARTY                      = 0x00020, //hidden

    BOT_ROLE_GATHERING_MINING           = 0x00040,
    BOT_ROLE_GATHERING_HERBALISM        = 0x00080,
    BOT_ROLE_GATHERING_SKINNING         = 0x00100,
    BOT_ROLE_GATHERING_ENGINEERING      = 0x00200,

    BOT_ROLE_AUTOLOOT                   = 0x00400, //not in mask
    BOT_ROLE_AUTOLOOT_POOR              = 0x00800,
    BOT_ROLE_AUTOLOOT_COMMON            = 0x01000,
    BOT_ROLE_AUTOLOOT_UNCOMMON          = 0x02000,
    BOT_ROLE_AUTOLOOT_RARE              = 0x04000,
    BOT_ROLE_AUTOLOOT_EPIC              = 0x08000,
    BOT_ROLE_AUTOLOOT_LEGENDARY         = 0x10000,

    BOT_MAX_ROLE                        = 0x20000,

    BOT_ROLE_MASK_MAIN                  = (BOT_ROLE_TANK | BOT_ROLE_TANK_OFF | BOT_ROLE_DPS | BOT_ROLE_HEAL | BOT_ROLE_RANGED),
    //BOT_ROLE_MASK_MAIN_EX               = (BOT_ROLE_TANK | BOT_ROLE_DPS | BOT_ROLE_HEAL | BOT_ROLE_RANGED | BOT_ROLE_PARTY),
    BOT_ROLE_MASK_GATHERING             = (BOT_ROLE_GATHERING_MINING | BOT_ROLE_GATHERING_HERBALISM | BOT_ROLE_GATHERING_SKINNING | BOT_ROLE_GATHERING_ENGINEERING),
    BOT_ROLE_MASK_LOOTING               = (BOT_ROLE_AUTOLOOT_POOR | BOT_ROLE_AUTOLOOT_COMMON | BOT_ROLE_AUTOLOOT_UNCOMMON | BOT_ROLE_AUTOLOOT_RARE | BOT_ROLE_AUTOLOOT_EPIC | BOT_ROLE_AUTOLOOT_LEGENDARY),

    //BOT_ROLE_TANK_MELEE                 = (BOT_ROLE_TANK | BOT_ROLE_DPS),
    //BOT_ROLE_TANK_RANGED                = (BOT_ROLE_TANK | BOT_ROLE_DPS | BOT_ROLE_RANGED),
    //BOT_ROLE_TANK_RANGED_NODPS          = (BOT_ROLE_TANK | BOT_ROLE_RANGED),
};

enum BotTalentSpecs
{
    BOT_SPEC_WARRIOR_ARMS               = 1,
    BOT_SPEC_WARRIOR_FURY               = 2,
    BOT_SPEC_WARRIOR_PROTECTION         = 3,
    BOT_SPEC_PALADIN_HOLY               = 4,
    BOT_SPEC_PALADIN_PROTECTION         = 5,
    BOT_SPEC_PALADIN_RETRIBUTION        = 6,
    BOT_SPEC_HUNTER_BEASTMASTERY        = 7,
    BOT_SPEC_HUNTER_MARKSMANSHIP        = 8,
    BOT_SPEC_HUNTER_SURVIVAL            = 9,
    BOT_SPEC_ROGUE_ASSASINATION         = 10,
    BOT_SPEC_ROGUE_COMBAT               = 11,
    BOT_SPEC_ROGUE_SUBTLETY             = 12,
    BOT_SPEC_PRIEST_DISCIPLINE          = 13,
    BOT_SPEC_PRIEST_HOLY                = 14,
    BOT_SPEC_PRIEST_SHADOW              = 15,
    BOT_SPEC_DK_BLOOD                   = 16,
    BOT_SPEC_DK_FROST                   = 17,
    BOT_SPEC_DK_UNHOLY                  = 18,
    BOT_SPEC_SHAMAN_ELEMENTAL           = 19,
    BOT_SPEC_SHAMAN_ENHANCEMENT         = 20,
    BOT_SPEC_SHAMAN_RESTORATION         = 21,
    BOT_SPEC_MAGE_ARCANE                = 22,
    BOT_SPEC_MAGE_FIRE                  = 23,
    BOT_SPEC_MAGE_FROST                 = 24,
    BOT_SPEC_WARLOCK_AFFLICTION         = 25,
    BOT_SPEC_WARLOCK_DEMONOLOGY         = 26,
    BOT_SPEC_WARLOCK_DESTRUCTION        = 27,
    BOT_SPEC_DRUID_BALANCE              = 28,
    BOT_SPEC_DRUID_FERAL                = 29,
    BOT_SPEC_DRUID_RESTORATION          = 30,
    BOT_SPEC_DEFAULT                    = 31,

    BOT_SPEC_BEGIN                      = BOT_SPEC_WARRIOR_ARMS,
    BOT_SPEC_END                        = BOT_SPEC_DEFAULT

};

enum BotPetTypes
{
    //Warlock
    BOT_PET_IMP                         = 70501,
    BOT_PET_VOIDWALKER                  = 70502,
    BOT_PET_SUCCUBUS                    = 70503,
    BOT_PET_FELHUNTER                   = 70504,
    BOT_PET_FELGUARD                    = 70505,

    BOT_PET_WARLOCK_START               = BOT_PET_IMP,
    BOT_PET_WARLOCK_END                 = BOT_PET_FELGUARD,

    //Hunter
    //cunning
    BOT_PET_SPIDER                      = 70506,
    BOT_PET_SERPENT                     = 70507,
    BOT_PET_BIRDOFPREY                  = 70508,
    BOT_PET_BAT                         = 70509,
    BOT_PET_WINDSERPENT                 = 70510,
    BOT_PET_RAVAGER                     = 70511,
    BOT_PET_DRAGONHAWK                  = 70512,
    BOT_PET_NETHERRAY                   = 70513,
    BOT_PET_SPOREBAT                    = 70514,
    //ferocity
    BOT_PET_CARRIONBIRD                 = 70515,
    BOT_PET_RAPTOR                      = 70516,
    BOT_PET_WOLF                        = 70517,
    BOT_PET_TALLSTRIDER                 = 70518,
    BOT_PET_CAT                         = 70519,
    BOT_PET_HYENA                       = 70520,
    BOT_PET_WASP                        = 70521,
    BOT_PET_TEROMOTH                    = 70522,
    //tenacity
    BOT_PET_SCORPID                     = 70523,
    BOT_PET_TURTLE                      = 70524,
    BOT_PET_GORILLA                     = 70525,
    BOT_PET_BEAR                        = 70526,
    BOT_PET_BOAR                        = 70527,
    BOT_PET_CRAB                        = 70528,
    BOT_PET_CROCOLISK                   = 70529,
    BOT_PET_WARPSTALKER                 = 70530,
    //cunning (exotic)
    BOT_PET_SILITHID                    = 70531,
    BOT_PET_CHIMAERA                    = 70532,
    //ferocity (exotic)
    BOT_PET_SPIRITBEAST                 = 70533,
    BOT_PET_COREHOUND                   = 70534,
    BOT_PET_DEVILSAUR                   = 70535,
    //tenacity (exotic)
    BOT_PET_RHINO                       = 70536,
    BOT_PET_WORM                        = 70537,

    BOT_PET_HUNTER_START                = BOT_PET_SPIDER,
    BOT_PET_HUNTER_END_GENERAL          = BOT_PET_WARPSTALKER,
    BOT_PET_HUNTER_END_EXOTIC           = BOT_PET_WORM,

    BOT_PET_CUNNING_START               = BOT_PET_SPIDER,
    BOT_PET_CUNNING_END                 = BOT_PET_SPOREBAT,
    BOT_PET_FEROCITY_START              = BOT_PET_CARRIONBIRD,
    BOT_PET_FEROCITY_END                = BOT_PET_TEROMOTH,
    BOT_PET_TENACITY_START              = BOT_PET_SCORPID,
    BOT_PET_TENACITY_END                = BOT_PET_WARPSTALKER,

    BOT_PET_EXOTIC_START                = BOT_PET_SILITHID,
    BOT_PET_EXOTIC_END                  = BOT_PET_WORM,

    //DK
    BOT_PET_GHOUL                       = 70538,
    BOT_PET_GARGOYLE                    = 70539,//NYI
    BOT_PET_DANCING_RUNE_WEAPON         = 70540,//NYI
    BOT_PET_AOD_GHOUL                   = 70541,//NYI

    //Priest
    BOT_PET_SHADOWFIEND                 = 70542,

    //Shaman
    BOT_PET_SPIRIT_WOLF                 = 70543,

    //Mage
    BOT_PET_WATER_ELEMENTAL             = 70544,

    //Druid
    BOT_PET_FORCE_OF_NATURE             = 70545,

    //Archmage
    BOT_PET_AWATER_ELEMENTAL            = 70556,

    //Dreadlord
    BOT_PET_INFERNAL                    = 70562,

    //Dark Ranger
    BOT_PET_DARK_MINION                 = 70573,
    BOT_PET_DARK_MINION_ELITE           = 70574,

    //Necromancer
    BOT_PET_NECROSKELETON               = 70580,

    //Sea Witch
    BOT_PET_TORNADO                     = 70586,

    //Crypt Lord
    BOT_PET_CARRION_BEETLE1             = 70592,
    BOT_PET_CARRION_BEETLE2             = 70593,
    BOT_PET_CARRION_BEETLE3             = 70594,
    BOT_PET_LOCUST_SWARM                = 70595,

    BOT_PET_INVALID                     = 99999
};

enum BotPetOriginalEntries
{
    ORIGINAL_ENTRY_IMP                  = 416,
    ORIGINAL_ENTRY_VOIDWALKER           = 1860,
    ORIGINAL_ENTRY_SUCCUBUS             = 1863,
    ORIGINAL_ENTRY_FELHUNTER            = 417,
    ORIGINAL_ENTRY_FELGUARD             = 17252,
    //ORIGINAL_ENTRY_GHOUL                = 26125,
    //ORIGINAL_ENTRY_SHADOWFIEND          = 19668,
    //ORIGINAL_ENTRY_SPIRIT_WOLF          = 29264,
    ORIGINAL_ENTRY_WATER_ELEMENTAL      = 510,
    //ORIGINAL_ENTRY_FORCE_OF_NATURE      = 1964,
    ORIGINAL_ENTRY_HUNTER_PET           = 1 // from Pet.cpp InitStatsForLevel()
};

enum BotEquipSlot : uint8
{
    BOT_SLOT_MAINHAND           = 0,
    BOT_SLOT_OFFHAND            = 1,
    BOT_SLOT_RANGED             = 2,
    BOT_SLOT_HEAD               = 3,
    BOT_SLOT_SHOULDERS          = 4,
    BOT_SLOT_CHEST              = 5,
    BOT_SLOT_WAIST              = 6,
    BOT_SLOT_LEGS               = 7,
    BOT_SLOT_FEET               = 8,
    BOT_SLOT_WRIST              = 9,
    BOT_SLOT_HANDS              = 10,
    BOT_SLOT_BACK               = 11,
    BOT_SLOT_BODY               = 12,
    BOT_SLOT_FINGER1            = 13,
    BOT_SLOT_FINGER2            = 14,
    BOT_SLOT_TRINKET1           = 15,
    BOT_SLOT_TRINKET2           = 16,
    BOT_SLOT_NECK               = 17,
    BOT_INVENTORY_SIZE
};

constexpr uint8 BOT_TRANSMOG_INVENTORY_SIZE = 13; // BOT_SLOT_BODY + 1

enum BotStatMods : uint8
{
    //ItemProtoType.h
    BOT_STAT_MOD_MANA                       = 0,
    BOT_STAT_MOD_HEALTH                     = 1,
    BOT_STAT_MOD_AGILITY                    = 3,
    BOT_STAT_MOD_STRENGTH                   = 4,
    BOT_STAT_MOD_INTELLECT                  = 5,
    BOT_STAT_MOD_SPIRIT                     = 6,
    BOT_STAT_MOD_STAMINA                    = 7,
    BOT_STAT_MOD_DEFENSE_SKILL_RATING       = 12,
    BOT_STAT_MOD_DODGE_RATING               = 13,
    BOT_STAT_MOD_PARRY_RATING               = 14,
    BOT_STAT_MOD_BLOCK_RATING               = 15,
    BOT_STAT_MOD_HIT_MELEE_RATING           = 16,
    BOT_STAT_MOD_HIT_RANGED_RATING          = 17,
    BOT_STAT_MOD_HIT_SPELL_RATING           = 18,
    BOT_STAT_MOD_CRIT_MELEE_RATING          = 19,
    BOT_STAT_MOD_CRIT_RANGED_RATING         = 20,
    BOT_STAT_MOD_CRIT_SPELL_RATING          = 21,
    BOT_STAT_MOD_HIT_TAKEN_MELEE_RATING     = 22,
    BOT_STAT_MOD_HIT_TAKEN_RANGED_RATING    = 23,
    BOT_STAT_MOD_HIT_TAKEN_SPELL_RATING     = 24,
    BOT_STAT_MOD_CRIT_TAKEN_MELEE_RATING    = 25,
    BOT_STAT_MOD_CRIT_TAKEN_RANGED_RATING   = 26,
    BOT_STAT_MOD_CRIT_TAKEN_SPELL_RATING    = 27,
    BOT_STAT_MOD_HASTE_MELEE_RATING         = 28,
    BOT_STAT_MOD_HASTE_RANGED_RATING        = 29,
    BOT_STAT_MOD_HASTE_SPELL_RATING         = 30,
    BOT_STAT_MOD_HIT_RATING                 = 31,
    BOT_STAT_MOD_CRIT_RATING                = 32,
    BOT_STAT_MOD_HIT_TAKEN_RATING           = 33,
    BOT_STAT_MOD_CRIT_TAKEN_RATING          = 34,
    BOT_STAT_MOD_RESILIENCE_RATING          = 35,
    BOT_STAT_MOD_HASTE_RATING               = 36,
    BOT_STAT_MOD_EXPERTISE_RATING           = 37,
    BOT_STAT_MOD_ATTACK_POWER               = 38,
    BOT_STAT_MOD_RANGED_ATTACK_POWER        = 39,
    BOT_STAT_MOD_FERAL_ATTACK_POWER         = 40,
    BOT_STAT_MOD_SPELL_HEALING_DONE         = 41,                 // deprecated
    BOT_STAT_MOD_SPELL_DAMAGE_DONE          = 42,                 // deprecated
    BOT_STAT_MOD_MANA_REGENERATION          = 43,
    BOT_STAT_MOD_ARMOR_PENETRATION_RATING   = 44,
    BOT_STAT_MOD_SPELL_POWER                = 45,
    BOT_STAT_MOD_HEALTH_REGEN               = 46,
    BOT_STAT_MOD_SPELL_PENETRATION          = 47,
    BOT_STAT_MOD_BLOCK_VALUE                = 48,
    //END ItemProtoType.h

    BOT_STAT_MOD_DAMAGE_MIN                 = BOT_STAT_MOD_BLOCK_VALUE + 1,
    BOT_STAT_MOD_DAMAGE_MAX,
    BOT_STAT_MOD_ARMOR,
    BOT_STAT_MOD_RESIST_HOLY,
    BOT_STAT_MOD_RESIST_FIRE,
    BOT_STAT_MOD_RESIST_NATURE,
    BOT_STAT_MOD_RESIST_FROST,
    BOT_STAT_MOD_RESIST_SHADOW,
    BOT_STAT_MOD_RESIST_ARCANE,
    BOT_STAT_MOD_EX,
    MAX_BOT_ITEM_MOD,

    BOT_STAT_MOD_RESISTANCE_START           = BOT_STAT_MOD_ARMOR
};

enum BotAIResetType
{
    BOTAI_RESET_INIT                    = 0x01,
    BOTAI_RESET_DISMISS                 = 0x02,
    BOTAI_RESET_UNBIND                  = 0x04,
    BOTAI_RESET_LOGOUT                  = 0x08,
    BOTAI_RESET_FORCERECALL             = 0x10,

    BOTAI_RESET_MASK_ABANDON_MASTER     = (BOTAI_RESET_INIT | BOTAI_RESET_DISMISS)
};

enum BotMovementType
{
    BOT_MOVE_POINT                      = 1,
    //BOT_MOVE_FOLLOW
    BOT_MOVE_CHASE
};

enum BotCommandStates : uint32
{
    BOT_COMMAND_STAY                    = 0x00000001,
    BOT_COMMAND_FOLLOW                  = 0x00000002,
    BOT_COMMAND_ATTACK                  = 0x00000004,
    BOT_COMMAND_COMBATRESET             = 0x00000008,
    BOT_COMMAND_FULLSTOP                = 0x00000010,
    BOT_COMMAND_ISSUED_ORDER            = 0x00000020,
    BOT_COMMAND_WALK                    = 0x00000040,
    BOT_COMMAND_NOGOSSIP                = 0x00000080,
    BOT_COMMAND_UNBIND                  = 0x00000100,
    BOT_COMMAND_NO_CAST                 = 0x00000200,
    BOT_COMMAND_NO_CAST_LONG            = 0x00000400,
    BOT_COMMAND_INACTION                = 0x00000800,

    BOT_COMMAND_MASK_UNCHASE            = BOT_COMMAND_STAY | BOT_COMMAND_FOLLOW | BOT_COMMAND_FULLSTOP | BOT_COMMAND_INACTION,
    BOT_COMMAND_MASK_UNMOVING           = BOT_COMMAND_STAY | BOT_COMMAND_FULLSTOP | BOT_COMMAND_ISSUED_ORDER,
    BOT_COMMAND_MASK_NOCAST_ANY         = BOT_COMMAND_NO_CAST | BOT_COMMAND_NO_CAST_LONG
};

enum BotAwaitStates
{
    BOT_AWAIT_NONE                      = 0x00,
    BOT_AWAIT_SEND                      = 0x01
};

constexpr size_t MAX_SEND_POINTS = 5u;

#define FROM_ARRAY(arr) arr, arr + sizeof(arr) / sizeof(arr[0])

//Only non-persistent types are allowed
enum BotOrderTypes
{
    BOT_ORDER_NONE          = 0,
    BOT_ORDER_SPELLCAST     = 1,
    BOT_ORDER_PULL          = 2,

    BOT_ORDER_END
};
constexpr bool DEBUG_BOT_ORDERS = false;
constexpr size_t MAX_BOT_ORDERS_QUEUE_SIZE = 3u;

enum BotVehicleStrats
{
    BOT_VEH_STRAT_NONE,
    BOT_VEH_STRAT_WYRMREST_SKYTALON,
    BOT_VEH_STRAT_RUBY_DRAKE,
    BOT_VEH_STRAT_EMERALD_DRAKE,
    BOT_VEH_STRAT_AMBER_DRAKE,
    BOT_VEH_STRAT_TOC5_MOUNT,
    BOT_VEH_STRAT_ULDUAR_DEMOLISHER,
    BOT_VEH_STRAT_ULDUAR_SIEGEENGINE,
    BOT_VEH_STRAT_ULDUAR_CHOPPER,

    BOT_VEH_STRAT_GENERIC
};

#endif
