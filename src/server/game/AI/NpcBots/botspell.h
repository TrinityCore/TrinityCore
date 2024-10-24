#ifndef _BOTSPELL_H
#define _BOTSPELL_H

#include "Define.h"

/*
NpcBot System by Trickerer (onlysuffering@gmail.com)
Original patch from: LordPsyan https://bitbucket.org/lordpsyan/trinitycore-patches/src/3b8b9072280e/Individual/11185-BOTS-NPCBots.patch
*/

class SpellInfo;
struct SpellProcEntry;

enum BotSpells : uint32
{
//COMMON SPELLS
    PVPTRINKET                          = 42292,//PvP Trinket no CD
    BERSERK                             = 46587,//68378,//900%/150%
    MODEL_TRANSITION                    = 24753,//"Trick" cannot cast or attack
    SUMMONING_DISORIENTATION            = 32752,
    ACTIVATE_SPEC                       = 63645,//Activate Primary Spec
    WANDERER_HEARTHSTONE                = 54318,//"Hearthsone" no CD
    SUMMONING_STONE_EFFECT              = 59782,//Cast time 5s + Channeled 2m
    SHOOT_WAND                          = 5019,
///Portals
    PORTAL_STORMWIND                    = 10059,
    PORTAL_IRONFORGE                    = 11416,
    PORTAL_DARNASSUS                    = 11419,
    PORTAL_EXODAR                       = 32266,
    PORTAL_SHATTRATH_A                  = 33691,
    PORTAL_THERAMORE                    = 49360,
    PORTAL_ORGRIMMAR                    = 11417,
    PORTAL_UNDERCITY                    = 11418,
    PORTAL_THUNDERBLUFF                 = 11420,
    PORTAL_SILVERMOON                   = 32267,
    PORTAL_SHATTRATH_H                  = 35717,
    PORTAL_STONARD                      = 49361,
    PORTAL_DALARAN                      = 53142,
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
//ADVANCED
    //SPELL_SUMMON_FELBLAZE_PREVISUAL     = 46350,//green splash impact head/torso
    //HONORLESS_TARGET                    = 2479,
    COSMETIC_TELEPORT_EFFECT            = 52096,//visual instant cast omni
    COSMETIC_RESURRECTION               = 58854,//visual instant cast self (castable while dead, hidden)
    SUMMON_DEMON_VISUAL                 = 6657,//SUMMON_SERPENT_MESSENGER
    CALL_PET_VISUAL                     = 30416,//QUEST_WOOD_CLEANSE_EFFECT
    SPELL_VERTEX_COLOR_BLACK            = 39662,//black color model full
    SPELL_VERTEX_COLOR_GREY             = 43355,//grey color model full
    SPELL_BLACK_HOLE_VISUAL_2           = 46235,//blackened+smoke trail med
////CUSTOM SPELLS - UNUSED IN CODE AND DB
  //common
  //modify
    SPELL_TRIGGERED_HEAL                = 25155,//hidden
    SPELL_TELEPORT_LOCAL                = 7794,//Teleport, no log
    SPELL_NULLIFY_POISON                = 550,//To convert into passive for bots
  //unmodify
    SPELL_ATTACK_MELEE_1H               = 42880,
    SPELL_TRIGGERED_ENERGIZE            = 60628,//hidden
    SPELL_BRIEF_STUN                    = 41421,//1sec stun
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
    SPELL_SHADOW_BOLT1                  = 16408,
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
    SPELL_STEAL_MAGIC_VISUAL            = 11084, // "Shock"
  //unmodify
//DARK RANGER
  //modify
    SPELL_BLACK_ARROW                   = 20733, //supposed to be used by Dark Ranger Clea
    SPELL_DRAIN_LIFE                    = 17238, //used by Maleki the Palid, supposed to be by Shadow Adept (31145)
    SPELL_SILENCE                       = 29943,
    //SPELL_CHARM                         = 11111, //
  //unmodify
//NECROMANCER
  //modify
    SPELL_SHADOW_BOLT2                  = 17509,
    SPELL_RAISE_DEAD                    = 34011,
    SPELL_UNHOLY_FRENZY                 = 52499,
    SPELL_CRIPPLE                       = 50379,
    SPELL_CORPSE_EXPLOSION              = 61614,
    //SPELL_BONE_SHIELD                   = 0,//27688, //NIY //NO VIABLE SPELLS
    //for Attract faction reaction must be adjusted at Object.cpp::GetFactionReactionTo(L2831)
    //SPELL_BLOOD_CURSE                   = 29933, //NIY for Attract //NO VIABLE SPELLS
  //unmodify
    CORPSE_EXPLOSION_VISUAL             = 60081, //explosion
//NAGA SEA WITCH
  //modify
    SPELL_FORKED_LIGHTNING              = 63541,
    SPELL_FORKED_LIGHTNING_EFFECT       = 50900, // "Lightning Shock"
    SPELL_FROST_ARROW                   = 38942,
    SPELL_FROST_ARROW_EFFECT            = 56095,
    SPELL_MANA_SHIELD                   = 35064,
    SPELL_TORNADO                       = 34695,
    SPELL_TORNADO_EFFECT                = 21990, // stun, -resistances
    SPELL_TORNADO_EFFECT2               = 34683, // aoe damage
    SPELL_TORNADO_EFFECT3               = 39261,
    SPELL_SHOOT_BOW                     = 41188,
  //unmodify
    SPELL_TORNADO_LIGHTNING_VISUAL      = 45869, //periodic, 1 sec
//CRYPT LORD
  //modify
    //impale cd 9
    //locust dur 30 cd 180
    SPELL_IMPALE                        = 53458,
    SPELL_IMPALE_DAMAGE                 = 53454,
    SPELL_IMPALE_VISUAL                 = 59446,
    SPELL_CARRION_BEETLES               = 53520,
    SPELL_LOCUST_SWARM                  = 28785,
    SPELL_SOUL_BITE                     = 11016, //special - pet
    SPELL_ENERGIZE_VISUAL               = 59198,
    SPELL_BURROW                        = 68394, //special - pet (NYI) //SPELL_EFFECT_FORCE_DESELECT
  //unmodify
    SPELL_SPIKED_CARAPACE_DAMAGE        = 14104,

//OTHER
    BASE_MANA_SPHYNX                    = 400 * 5,
    BASE_MANA_SPELLBREAKER              = 250 * 5,
    BASE_MANA_NECROMANCER               = 400 * 5,
    //base mana at 10
    BASE_MANA_10_BM                     = 540 * 5,
    BASE_MANA_10_ARCHMAGE               = 705 * 5,
    BASE_MANA_10_DREADLORD              = 600 * 5,
    BASE_MANA_10_DARK_RANGER            = 570 * 5,
    BASE_MANA_10_SEA_WITCH              = 735 * 5,
    BASE_MANA_10_CRYPT_LORD             = 420 * 5,
    //base mana at 1
    BASE_MANA_1_BM                      = 240 * 5,
    BASE_MANA_1_ARCHMAGE                = 285 * 5,
    BASE_MANA_1_DREADLORD               = 270 * 5,
    BASE_MANA_1_DARK_RANGER             = 225 * 5,
    BASE_MANA_1_SEA_WITCH               = 330 * 5,
    BASE_MANA_1_CRYPT_LORD              = 210 * 5,
};

enum BotMountSpells : uint32
{
    //By game events
    REINDEER                            = 25859,
    REINDEER_FLY                        = 44827,
    //AQ40
    QIRAJI_BATTLE_TANK_1                = 25953,
    QIRAJI_BATTLE_TANK_2                = 26054,
    QIRAJI_BATTLE_TANK_3                = 26055,
    QIRAJI_BATTLE_TANK_4                = 26056,
    //By class
    BOT_DARK_RANGER_MOUNT               = 17481, // Deathcharger's Reins
    BOT_BE_PALLY_FAST_MOUNT             = 34767,
    BOT_BE_PALLY_MOUNT                  = 34769,
    BOT_ALLI_PALLY_FAST_MOUNT           = 23214,
    BOT_ALLI_PALLY_MOUNT                = 13819,
    BOT_DEATH_KNIGHT_MOUNT              = 48778,
    BOT_WARLOCK_FAST_MOUNT              = 23161,
    BOT_WARLOCK_MOUNT                   = 5784,
    //By race
    BOT_MOUNT_HUMAN_60_1                = 458,
    BOT_MOUNT_HUMAN_60_2                = 468,
    BOT_MOUNT_HUMAN_60_3                = 470,
    BOT_MOUNT_ORC_60_1                  = 459,
    BOT_MOUNT_ORC_60_2                  = 578,
    BOT_MOUNT_ORC_60_3                  = 579,
    BOT_MOUNT_DWARF_60_1                = 6777,
    BOT_MOUNT_DWARF_60_2                = 6896,
    BOT_MOUNT_DWARF_60_3                = 6897,
    BOT_MOUNT_NIGHTELF_60_1             = 8394,
    BOT_MOUNT_NIGHTELF_60_2             = 10787,
    BOT_MOUNT_NIGHTELF_60_3             = 10789,
    BOT_MOUNT_FORSAKEN_60_1             = 8980,
    BOT_MOUNT_FORSAKEN_60_2             = 17462,
    BOT_MOUNT_FORSAKEN_60_3             = 17463,
    BOT_MOUNT_TAUREN_60_1               = 18363,
    BOT_MOUNT_TAUREN_60_2               = 18989,
    BOT_MOUNT_TAUREN_60_3               = 18990,
    BOT_MOUNT_GNOME_60_1                = 10873,
    BOT_MOUNT_GNOME_60_2                = 10969,
    BOT_MOUNT_GNOME_60_3                = 15780,
    BOT_MOUNT_TROLL_60_1                = 8395,
    BOT_MOUNT_TROLL_60_2                = 10795,
    BOT_MOUNT_TROLL_60_3                = 10796,
    BOT_MOUNT_BLOODELF_60_1             = 34795,
    BOT_MOUNT_BLOODELF_60_2             = 35018,
    BOT_MOUNT_BLOODELF_60_3             = 35020,
    BOT_MOUNT_DRAENEI_60_1              = 34406,
    BOT_MOUNT_DRAENEI_60_2              = 35710,
    BOT_MOUNT_DRAENEI_60_3              = 35711,
    BOT_MOUNT_HUMAN_100_1               = 23227,
    BOT_MOUNT_HUMAN_100_2               = 23228,
    BOT_MOUNT_HUMAN_100_3               = 23229,
    BOT_MOUNT_ORC_100_1                 = 23250,
    BOT_MOUNT_ORC_100_2                 = 23251,
    BOT_MOUNT_ORC_100_3                 = 23252,
    BOT_MOUNT_DWARF_100_1               = 23238,
    BOT_MOUNT_DWARF_100_2               = 23239,
    BOT_MOUNT_DWARF_100_3               = 23240,
    BOT_MOUNT_NIGHTELF_100_1            = 23219,
    BOT_MOUNT_NIGHTELF_100_2            = 23220,
    BOT_MOUNT_NIGHTELF_100_3            = 23221,
    BOT_MOUNT_FORSAKEN_100_1            = 17465,
    BOT_MOUNT_FORSAKEN_100_2            = 22722,
    BOT_MOUNT_FORSAKEN_100_3            = 23246,
    BOT_MOUNT_TAUREN_100_1              = 23247,
    BOT_MOUNT_TAUREN_100_2              = 23248,
    BOT_MOUNT_TAUREN_100_3              = 23249,
    BOT_MOUNT_GNOME_100_1               = 23222,
    BOT_MOUNT_GNOME_100_2               = 23223,
    BOT_MOUNT_GNOME_100_3               = 23225,
    BOT_MOUNT_TROLL_100_1               = 23241,
    BOT_MOUNT_TROLL_100_2               = 23242,
    BOT_MOUNT_TROLL_100_3               = 23243,
    BOT_MOUNT_BLOODELF_100_1            = 35025,
    BOT_MOUNT_BLOODELF_100_2            = 35027,
    BOT_MOUNT_BLOODELF_100_3            = 46628,
    BOT_MOUNT_DRAENEI_100_1             = 35712,
    BOT_MOUNT_DRAENEI_100_2             = 35713,
    BOT_MOUNT_DRAENEI_100_3             = 35714,
    //By Team (flyers)
    BOT_MOUNT_FLY_ALLIANCE_150_1        = 32235,
    BOT_MOUNT_FLY_ALLIANCE_150_2        = 32239,
    BOT_MOUNT_FLY_ALLIANCE_150_3        = 32240,
    BOT_MOUNT_FLY_HORDE_150_1           = 32243,
    BOT_MOUNT_FLY_HORDE_150_2           = 32244,
    BOT_MOUNT_FLY_HORDE_150_3           = 32245,
    BOT_MOUNT_FLY_ALLIANCE_280_1        = 32242,
    BOT_MOUNT_FLY_ALLIANCE_280_2        = 32289,
    BOT_MOUNT_FLY_ALLIANCE_280_3        = 32290,
    BOT_MOUNT_FLY_HORDE_280_1           = 32246,
    BOT_MOUNT_FLY_HORDE_280_2           = 32295,
    BOT_MOUNT_FLY_HORDE_280_3           = 32296
};
constexpr std::size_t NUM_MOUNTS_PER_SPEED = 3;

enum BotItemUseSpellTargeting : uint8
{
    BOT_ITEM_USE_SPELL_TARGET_NONE         = 0,
    BOT_ITEM_USE_SPELL_TARGET_SELF         = 1,
    BOT_ITEM_USE_SPELL_TARGET_ATTACKTARGET = 2,
    BOT_ITEM_USE_SPELL_TARGET_ALLY         = 3
};

SpellInfo const* GetBotSpellInfoOverride(uint32 spellId);
SpellInfo const* AssertBotSpellInfoOverride(uint32 spellId);
SpellProcEntry const* GetBotSpellProceEntryOverride(uint32 spellId);
void GenerateBotCustomSpells();

#endif //_BOTSPELL_H
