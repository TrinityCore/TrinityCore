#ifndef _BOTCOMMON_H
#define _BOTCOMMON_H

/*
NpcBot System by Trickerer (onlysuffering@gmail.com)
Original patch from: LordPsyan https://bitbucket.org/lordpsyan/trinitycore-patches/src/3b8b9072280e/Individual/11185-BOTS-NPCBots.patch
*/

enum BotCommonValues
{
//MISC
    BOT_GIVER_ENTRY                     = 70000,
    BOT_ENTRY_BEGIN                     = 70001,
    BOT_ENTRY_END                       = 71000,
    BOT_PET_ENTRY_BEGIN                 = 70501,
    BOT_PET_ENTRY_END                   = 70550,
    BOT_ENTRY_MIRROR_IMAGE_BM           = 70552,
    BOT_ICON_ON                         = 9,    //GOSSIP_ICON_BATTLE,
    BOT_ICON_OFF                        = 0,    //GOSSIP_ICON_CHAT,
    BOT_MAX_CHASE_RANGE                 = 120,  //yds
    //BOT_EVADE_TIME                      = 3000, //ms
//COMMON SPELLS
    PVPTRINKET                          = 42292,//PvP Trinket no CD
    BERSERK                             = 46587,//68378,//900%/150%
    MODEL_TRANSITION                    = 24753,//"Trick" cannot cast or attack
    SUMMONING_DISORIENTATION            = 32752,
    ACTIVATE_SPEC                       = 63645,//Activate Primary Spec
    SHOOT_WAND                          = 5019,
///Passives
    DAMAGE_REDUCTION                    = 68066,//Vigilance, Blessing of Sanctuary, etc.
///Passives for Pets
    DAMAGEDONE_PASSIVE                  = 30147,//for custom value, Tamed Pet Passive (DND) physical at 0, magic at 1
    DAMAGETAKEN_PASSIVE                 = 35697,//for custom value, Pet Passive (DND), single effect (aura 87 at 0)
    SPELLDAMAGE_PASSIVE                 = 43922,//for custom value, Increase Spell Dam 473, single effect (aura 13 at 0)
    SPELLPENETRATION_PASSIVE            = 25975,//for custom value, Spell Penetration 10, single effect (aura 123 at 0)
    SPELLHASTE_PASSIVE                  = 44400,//for custom value, Netherwind Presence rank 1, single effect (aura 65 at 0)
    CRITBONUS_PASSIVE                   = 35695,//for custom value, Pet Passive (DND), spell at 0, physical at 1
///Racials
    RACIAL_EVERY_MAN_FOR_HIMSELF        = 59752,//pvp trinket effect, instant, 2 min cd
    RACIAL_BLOOD_FURY_WARLOCK           = 33702,//effect varies, 15 sec, 2 min cd
    RACIAL_BLOOD_FURY_SHAMAN            = 33697,
    RACIAL_BLOOD_FURY_OTHERS            = 20572,
    RACIAL_STONEFORM                    = 20594,//dispell disease, poison, bleed, instant, 2 min cd
    //RACIAL_FIND_TREASURE                = 2481,
    RACIAL_SHADOWMELD                   = 58984,//stealth, -threat, instant, 2 min cd
    RACIAL_WILL_OF_THE_FORSAKEN         = 7744,//dispel charm/fear/sleep, instant, 2 min cd, 45 sec category cd
    RACIAL_WARSTOMP                     = 20549,//2sec stun, casttime 500, 8yd, 2 min cd
    RACIAL_ESCAPE_ARTIST                = 20589,//dispel snare/root, instant, 1 min 45 sec cd
    RACIAL_BERSERKING                   = 26297,//haste all 20%, isntant, 3 min cd
    RACIAL_ARCANE_TORRENT_DEATHKNIGHT   = 50613,//2sec AoE silence + energize, instant, 2 min cd
    RACIAL_ARCANE_TORRENT_ROGUE         = 25046,
    RACIAL_ARCANE_TORRENT_OTHERS        = 28730,
    RACIAL_GIFT_OF_NAARU_WARRIOR        = 28880,//Hot over 15 sec, instant, 2 min cd
    RACIAL_GIFT_OF_NAARU_PALADIN        = 59542,
    RACIAL_GIFT_OF_NAARU_HUNTER         = 59543,
    RACIAL_GIFT_OF_NAARU_PRIEST         = 59544,
    RACIAL_GIFT_OF_NAARU_DEATHKNIGHT    = 59545,
    RACIAL_GIFT_OF_NAARU_SHAMAN         = 59547,
    RACIAL_GIFT_OF_NAARU_MAGE           = 59548,
//COMMON GAMEOBJECTS
    GO_REFRESHMENT_TABLE_1              = 186812,//lvl 65 req70
    GO_REFRESHMENT_TABLE_2              = 193061,//lvl 80 req80
    GO_SOULWELL_1                       = 181621,//lvl 60 req68
    GO_SOULWELL_2                       = 193169,//lvl 69 req80
//COMMON CDs
    POTION_CD                           = 60000,//default 60sec potion cd
    REGEN_CD                            = 1000, //update hp/mana every X milliseconds
//COMMON TIMERS
    ITEM_ENCHANTMENT_EXPIRE_TIMER       = 1 * HOUR * IN_MILLISECONDS,
//COMMON GOSSIPS
    GOSSIP_NORMAL_SERVE_MASTER          = 70001,//"I live only to serve the master."
    GOSSIP_GREET_NEED_SMTH              = 70002,//"You need something?"
    GOSSIP_GREET_MURDER                 = 70003,//"Mortals... usually I kill wretches like you at sight"
    GOSSIP_GREET_CUSTOM_SPHYNX          = 70004,
    GOSSIP_NORMAL_CUSTOM_SPHYNX         = 70005,
    GOSSIP_GREET_CUSTOM_DREADLORD       = 70006,
    GOSSIP_NORMAL_CUSTOM_DREADLORD      = 70007,
    GOSSIP_GREET_CUSTOM_DARKRANGER      = 70008,
    GOSSIP_NORMAL_CUSTOM_DARKRANGER     = 70009,
    GOSSIP_CLASSDESC_BM                 = 70101,
    GOSSIP_CLASSDESC_SPHYNX             = 70102,
    GOSSIP_CLASSDESC_ARCHMAGE           = 70103,
    GOSSIP_CLASSDESC_DREADLORD          = 70104,
    GOSSIP_CLASSDESC_SPELLBREAKER       = 70105,
    GOSSIP_CLASSDESC_DARKRANGER         = 70106,
    GOSSIP_BOTGIVER_GREET               = 70201,
    GOSSIP_BOTGIVER_HIRE                = 70202,
    GOSSIP_BOTGIVER_HIRE_CLASS          = 70203,
    GOSSIP_BOTGIVER_HIRE_EMPTY          = 70204,
    GOSSIP_SENDER_BEGIN                 = 6000,
    GOSSIP_SENDER_BOTGIVER_HIRE,
    GOSSIP_SENDER_BOTGIVER_HIRE_CLASS,
    GOSSIP_SENDER_BOTGIVER_HIRE_ENTRY,
    GOSSIP_SENDER_CLASS,
    GOSSIP_SENDER_CLASS_ACTION,
    GOSSIP_SENDER_CLASS_ACTION2,
    GOSSIP_SENDER_CLASS_ACTION3,
    GOSSIP_SENDER_CLASS_ACTION4,
    GOSSIP_SENDER_EQUIPMENT,
    GOSSIP_SENDER_EQUIPMENT_LIST,
    GOSSIP_SENDER_EQUIPMENT_SHOW,
    GOSSIP_SENDER_EQUIPMENT_INFO,
    GOSSIP_SENDER_UNEQUIP,
    GOSSIP_SENDER_UNEQUIP_ALL,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_EQUIP,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_BEGIN = GOSSIP_SENDER_EQUIP_AUTOEQUIP_EQUIP,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_MHAND = GOSSIP_SENDER_EQUIP_AUTOEQUIP_BEGIN,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_OHAND,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_RANGED,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_HEAD,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_SHOULDERS,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_CHEST,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_WAIST,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_LEGS,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_FEET,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_WRIST,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_HANDS,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_BACK,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_BODY,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_FINGER1,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_FINGER2,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_TRINKET1,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_TRINKET2,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_NECK,
    GOSSIP_SENDER_EQUIP_RESET,
    GOSSIP_SENDER_EQUIP,
    GOSSIP_SENDER_EQUIP_BEGIN           = GOSSIP_SENDER_EQUIP,
    GOSSIP_SENDER_EQUIP_MHAND           = GOSSIP_SENDER_EQUIP_BEGIN,
    GOSSIP_SENDER_EQUIP_OHAND,
    GOSSIP_SENDER_EQUIP_RANGED,
    GOSSIP_SENDER_EQUIP_HEAD,
    GOSSIP_SENDER_EQUIP_SHOULDERS,
    GOSSIP_SENDER_EQUIP_CHEST,
    GOSSIP_SENDER_EQUIP_WAIST,
    GOSSIP_SENDER_EQUIP_LEGS,
    GOSSIP_SENDER_EQUIP_FEET,
    GOSSIP_SENDER_EQUIP_WRIST,
    GOSSIP_SENDER_EQUIP_HANDS,
    GOSSIP_SENDER_EQUIP_BACK,
    GOSSIP_SENDER_EQUIP_BODY,
    GOSSIP_SENDER_EQUIP_FINGER1,
    GOSSIP_SENDER_EQUIP_FINGER2,
    GOSSIP_SENDER_EQUIP_TRINKET1,
    GOSSIP_SENDER_EQUIP_TRINKET2,
    GOSSIP_SENDER_EQUIP_NECK,
    GOSSIP_SENDER_ROLES_MAIN,
    GOSSIP_SENDER_ROLES_MAIN_TOGGLE,
    GOSSIP_SENDER_ROLES_GATHERING,
    GOSSIP_SENDER_ROLES_GATHERING_TOGGLE,
    GOSSIP_SENDER_ABILITIES,
    GOSSIP_SENDER_ABILITIES_USE,
    GOSSIP_SENDER_ABILITIES_SPECIFICS_LIST,
    GOSSIP_SENDER_ABILITIES_USAGE_LIST,
    GOSSIP_SENDER_ABILITIES_USAGE_LIST_DAMAGE,
    GOSSIP_SENDER_ABILITIES_USAGE_LIST_CC,
    GOSSIP_SENDER_ABILITIES_USAGE_LIST_HEAL,
    GOSSIP_SENDER_ABILITIES_USAGE_LIST_SUPPORT,
    GOSSIP_SENDER_ABILITIES_USAGE_TOGGLE_DAMAGE,
    GOSSIP_SENDER_ABILITIES_USAGE_TOGGLE_CC,
    GOSSIP_SENDER_ABILITIES_USAGE_TOGGLE_HEAL,
    GOSSIP_SENDER_ABILITIES_USAGE_TOGGLE_SUPPORT,
    GOSSIP_SENDER_SPEC,
    GOSSIP_SENDER_SPEC_SET,
    GOSSIP_SENDER_USEITEM,
    GOSSIP_SENDER_USEITEM_USE,
    GOSSIP_SENDER_HIRE,
    GOSSIP_SENDER_DISMISS,
    GOSSIP_SENDER_JOIN_GROUP,
    GOSSIP_SENDER_LEAVE_GROUP,
    GOSSIP_SENDER_FORMATION,
    GOSSIP_SENDER_FORMATION_FOLLOW_DISTANCE_SET,
    GOSSIP_SENDER_FORMATION_ATTACK,
    GOSSIP_SENDER_FORMATION_ATTACK_DISTANCE_SET,
    GOSSIP_SENDER_MODEL_UPDATE,
    GOSSIP_SENDER_HOLDPOSITION,
    GOSSIP_SENDER_DONOTHING,
    GOSSIP_SENDER_FOLLOWME,
    GOSSIP_SENDER_TROUBLESHOOTING,
    GOSSIP_SENDER_TROUBLESHOOTING_FIX,
    GOSSIP_SENDER_TROUBLESHOOTING_AURA,
    GOSSIP_SENDER_SCAN,
    GOSSIP_SENDER_DEBUG,
    GOSSIP_SENDER_DEBUG_ACTION,
//GOSSIP CONST
    BOT_GOSSIP_MAX_ITEMS                = 32, // Client limitation 3.3.5 code confirmed
//COMMON NPCS
    SHAMAN_EARTH_ELEMENTAL              = 15352,
    SHAMAN_FIRE_ELEMENTAL               = 15438,
    //NPC_WORLD_TRIGGER                   = 22515,
//COMMON ITEM DISPLAY IDS
    CHEST_HALISCAN                      = 50566, //Haliscan Jacket
    LEGS_HALISCAN                       = 50567, //Haliscan Pants
//COMMON GAMEEVENTS
    GAME_EVENT_WINTER_VEIL              = 2,
//COMMON MOUNTS SPELLS
    REINDEER                            = 25859,
    REINDEER_FLY                        = 44827,
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
    BOTPETAI_MISC_MAXLEVEL,
//ADVANCED
    //HONORLESS_TARGET                    = 2479,
    COSMETIC_TELEPORT_EFFECT            = 52096,//visual instant cast omni
    COSMETIC_RESURRECTION               = 58854,//visual instant cast self (castable while dead, hidden)
    SUMMON_DEMON_VISUAL                 = 6657,//SUMMON_SERPENT_MESSENGER
    CALL_PET_VISUAL                     = 30416,//QUEST_WOOD_CLEANSE_EFFECT
    SPELL_VERTEX_COLOR_BLACK            = 39662,//black color model full
    SPELL_VERTEX_COLOR_GREY             = 43355,//grey color model full
////CUSTOM SPELLS - UNUSED IN CODE AND DB
  //common
  //modify
    SPELL_TRIGGERED_HEAL                = 25155,//hidden
  //unmodify
    SPELL_ATTACK_MELEE_1H               = 42880,
    SPELL_TRIGGERED_ENERGIZE            = 60628,//hidden
//BLADEMASTER
  //SPELLS
  //unmodify
    //SPELL_DEATH_GRIP_JUMP               = 49575,
/**/SPELL_CRITICAL_STRIKE               = 1132,
    SPELL_BURNING_BLADE_BLADEMASTER     = 32281,//horde flag visual
    SPELL_STUN_FREEZE_ANIM              = 59123,//stun forever, full stop
  //modify
    SPELL_TRANSPARENCY_50               = 44816,
/**/SPELL_NETHERWALK                    = 31599,
/**/SPELL_MIRROR_IMAGE_BM               = 69936,//blank spell
    SPELL_COMBAT_SPECIAL_2H_ATTACK      = 44079,//animation only
//SPHYNX
  //modify
    SPELL_SHADOW_BOLT                   = 16408,
    SPELL_SHADOW_BLAST                  = 38085,
    //SPELL_SHADOW_BLAST_SPLASH           = 38205,
    SPELL_ATTACK_MELEE_RANDOM           = 42902,
    SHADOWFURY_VISUAL                   = 47444,//59912,
    SPELL_DEVOUR_MAGIC                  = 17012,//used by Spellmaw but no matter (this spell does not work as intended)
    SPELL_DRAIN_MANA                    = 25755,
    SPELL_REPLENISH_MANA                = 33394,//5406,
    SPELL_REPLENISH_HEALTH              = 34756,//regenerating aura
  //unmodify
    SPELL_DEVOUR_MAGIC_CASTER_IMPACT    = 50527,
    SPELL_DEVOUR_MAGIC_BEAM             = 54393,
//ARCHMAGE
  //modify
    SPELL_BRILLIANCE_AURA               = 1234,
    SPELL_FIREBALL                      = 9488,
    SPELL_BLIZZARD                      = 15783,
    SPELL_SUMMON_WATER_ELEMENTAL        = 35593,
    SPELL_WATERBOLT                     = 72898,
  //unmodify
//DREADLORD
  //modify
    SPELL_VAMPIRIC_AURA                 = 20810,
    SPELL_SLEEP                         = 20663,
    SPELL_CARRION_SWARM                 = 34240,
    SPELL_INFERNO                       = 12740, //summon infernal servant
    SPELL_INFERNO_METEOR_VISUAL         = 5739, //meteor strike infernal
  //unmodify
    SPELL_INFERNO_EFFECT                = 22703, //stun, damage (warlock spell)
    //SPELL_INFERNO_IMPACT_EXPLOSION      = 00000, //visual
//SPELLBREAKER
  //modify
    SPELL_STEAL_MAGIC                   = 30036, //used by Ethereal Spellfilcher
    SPELL_FEEDBACK                      = 32897,
  //unmodify
//DARK RANGER
  //modify
    SPELL_BLACK_ARROW                   = 20733, //supposed to be used by Dark Ranger Clea
    SPELL_DRAIN_LIFE                    = 17238, //used by Maleki the Palid, supposed to be by Shadow Adept (31145)
    SPELL_SILENCE                       = 29943,
    //SPELL_CHARM                         = 11111, //
  //unmodify

  //SOUNDS
    SOUND_FREEZE_IMPACT_WINDWALK        = 29,
    SOUND_AXE_2H_IMPACT_FLESH_CRIT      = 158,
    SOUND_ABSORB_GET_HIT                = 3334,
    SOUND_MISS_WHOOSH_2H                = 7081,

//UNUSED
    //SPELL_SUMMON_FELBLAZE_PREVISUAL     = 46350,//green splash impact head/torso

//OTHER
    BASE_MANA_SPHYNX                    = 400 * 5,
    BASE_MANA_SPELLBREAKER              = 250 * 5,
    //base mana at 10
    BASE_MANA_10_BM                     = 540 * 5,
    BASE_MANA_10_ARCHMAGE               = 705 * 5,
    BASE_MANA_10_DREADLORD              = 600 * 5,
    BASE_MANA_10_DARK_RANGER            = 570 * 5,
    //base mana at 1
    BASE_MANA_1_BM                      = 240 * 5,
    BASE_MANA_1_ARCHMAGE                = 285 * 5,
    BASE_MANA_1_DREADLORD               = 270 * 5,
    BASE_MANA_1_DARK_RANGER             = 225 * 5,
    //MAX_LOOT_ITEMS                      = 18 // Client limitation 3.3.5 code confirmed
};

enum BotClasses
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
    BOT_CLASS_END
};

#define BOT_CLASS_EX_START BOT_CLASS_BM

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
    //DRUID_FLIGHT_FORM //NYI
};

enum BotRoles
{
    BOT_ROLE_NONE                       = 0x000,
    BOT_ROLE_TANK                       = 0x001,
    BOT_ROLE_DPS                        = 0x002,
    BOT_ROLE_HEAL                       = 0x004,
    BOT_ROLE_RANGED                     = 0x008,

    BOT_ROLE_PARTY                      = 0x010, //hidden

    BOT_ROLE_GATHERING_MINING           = 0x020,
    BOT_ROLE_GATHERING_HERBALISM        = 0x040,
    BOT_ROLE_GATHERING_SKINNING         = 0x080,
    BOT_ROLE_GATHERING_ENGINEERING      = 0x100,

    BOT_MAX_ROLE                        = 0x200,

    BOT_ROLE_MASK_MAIN                  = (BOT_ROLE_TANK | BOT_ROLE_DPS | BOT_ROLE_HEAL | BOT_ROLE_RANGED),
    //BOT_ROLE_MASK_MAIN_EX               = (BOT_ROLE_TANK | BOT_ROLE_DPS | BOT_ROLE_HEAL | BOT_ROLE_RANGED | BOT_ROLE_PARTY),
    BOT_ROLE_MASK_GATHERING             = (BOT_ROLE_GATHERING_MINING | BOT_ROLE_GATHERING_HERBALISM | BOT_ROLE_GATHERING_SKINNING | BOT_ROLE_GATHERING_ENGINEERING),

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

enum BotEquipSlot
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

enum BotStatMods
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

    BOT_STAT_MOD_DAMAGE_MIN                 = MAX_ITEM_MOD,
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
    BOTAI_RESET_LOST                    = 0x04,
    BOTAI_RESET_LOGOUT                  = 0x08,

    BOTAI_RESET_MASK_ABANDON_MASTER     = (BOTAI_RESET_INIT | BOTAI_RESET_DISMISS)
};

enum BotCommandStates
{
    BOT_COMMAND_STAY                    = 0x01,
    BOT_COMMAND_FOLLOW                  = 0x02,
    BOT_COMMAND_ATTACK                  = 0x04,
    BOT_COMMAND_COMBATRESET             = 0x08,
    BOT_COMMAND_FULLSTOP                = 0x10,
    BOT_COMMAND_ISSUED_ORDER            = 0x20,

    BOT_COMMAND_MASK_UNCHASE            = BOT_COMMAND_STAY | BOT_COMMAND_FOLLOW | BOT_COMMAND_FULLSTOP,
    BOT_COMMAND_MASK_UNMOVING           = BOT_COMMAND_STAY | BOT_COMMAND_FULLSTOP | BOT_COMMAND_ISSUED_ORDER
};

#define FROM_ARRAY(arr) arr, arr + sizeof(arr) / sizeof(arr[0])

//Only non-persistent types are allowed
enum BotOrderTypes
{
    BOT_ORDER_NONE          = 0,
    BOT_ORDER_SPELLCAST     = 1
};
#define DEBUG_BOT_ORDERS 1
#define MAX_BOT_ORDERS_QUEUE_SIZE 3

#endif
