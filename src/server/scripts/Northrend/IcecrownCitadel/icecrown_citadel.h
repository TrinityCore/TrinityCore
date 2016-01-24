/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#ifndef ICECROWN_CITADEL_H_
#define ICECROWN_CITADEL_H_

#include "SpellScript.h"

#define ICCScriptName "instance_icecrown_citadel"
#define DataHeader    "IC"

uint32 const EncounterCount = 13;
uint32 const WeeklyNPCs = 9;
uint32 const MaxHeroicAttempts = 50;

// Defined in boss_valithria_dreamwalker.cpp
extern Position const ValithriaSpawnPos;
// Defined in boss_sindragosa.cpp
extern Position const SindragosaSpawnPos;
// Defined in boss_the_lich_king.cpp
extern Position const TerenasSpawn;
extern Position const TerenasSpawnHeroic;
extern Position const SpiritWardenSpawn;

// Shared spells used by more than one script
enum SharedSpells
{
    SPELL_BERSERK                       = 26662,
    SPELL_BERSERK2                      = 47008,

    // Deathbound Ward
    SPELL_STONEFORM                     = 70733,

    // Residue Rendezvous
    SPELL_ORANGE_BLIGHT_RESIDUE         = 72144,
    SPELL_GREEN_BLIGHT_RESIDUE          = 72145,

    // The Lich King
    SPELL_ARTHAS_TELEPORTER_CEREMONY    = 72915,
    SPELL_FROSTMOURNE_TELEPORT_VISUAL   = 73078,

    // Shadowmourne questline
    SPELL_UNSATED_CRAVING               = 71168,
    SPELL_SHADOWS_FATE                  = 71169
};

enum TeleporterSpells
{
    LIGHT_S_HAMMER_TELEPORT         = 70781,
    ORATORY_OF_THE_DAMNED_TELEPORT  = 70856,
    RAMPART_OF_SKULLS_TELEPORT      = 70857,
    DEATHBRINGER_S_RISE_TELEPORT    = 70858,
    UPPER_SPIRE_TELEPORT            = 70859,
    FROZEN_THRONE_TELEPORT          = 70860,
    SINDRAGOSA_S_LAIR_TELEPORT      = 70861
};

enum DataTypes
{
    // Encounter States/Boss GUIDs
    DATA_LORD_MARROWGAR                = 0,
    DATA_LADY_DEATHWHISPER             = 1,
    DATA_ICECROWN_GUNSHIP_BATTLE       = 2,
    DATA_DEATHBRINGER_SAURFANG         = 3,
    DATA_FESTERGUT                     = 4,
    DATA_ROTFACE                       = 5,
    DATA_PROFESSOR_PUTRICIDE           = 6,
    DATA_BLOOD_PRINCE_COUNCIL          = 7,
    DATA_BLOOD_QUEEN_LANA_THEL         = 8,
    DATA_SISTER_SVALNA                 = 9,
    DATA_VALITHRIA_DREAMWALKER         = 10,
    DATA_SINDRAGOSA                    = 11,
    DATA_THE_LICH_KING                 = 12,

    // Additional data
    DATA_SAURFANG_EVENT_NPC            = 13,
    DATA_BONED_ACHIEVEMENT             = 14,
    DATA_OOZE_DANCE_ACHIEVEMENT        = 15,
    DATA_PUTRICIDE_TABLE               = 16,
    DATA_NAUSEA_ACHIEVEMENT            = 17,
    DATA_ORB_WHISPERER_ACHIEVEMENT     = 18,
    DATA_PRINCE_KELESETH_GUID          = 19,
    DATA_PRINCE_TALDARAM_GUID          = 20,
    DATA_PRINCE_VALANAR_GUID           = 21,
    DATA_BLOOD_PRINCES_CONTROL         = 22,
    DATA_SINDRAGOSA_FROSTWYRMS         = 23,
    DATA_SPINESTALKER                  = 24,
    DATA_RIMEFANG                      = 25,
    DATA_COLDFLAME_JETS                = 26,
    DATA_TEAM_IN_INSTANCE              = 27,
    DATA_BLOOD_QUICKENING_STATE        = 28,
    DATA_HEROIC_ATTEMPTS               = 29,
    DATA_CROK_SCOURGEBANE              = 30,
    DATA_CAPTAIN_ARNATH                = 31,
    DATA_CAPTAIN_BRANDON               = 32,
    DATA_CAPTAIN_GRONDEL               = 33,
    DATA_CAPTAIN_RUPERT                = 34,
    DATA_VALITHRIA_TRIGGER             = 35,
    DATA_VALITHRIA_LICH_KING           = 36,
    DATA_HIGHLORD_TIRION_FORDRING      = 37,
    DATA_ARTHAS_PLATFORM               = 38,
    DATA_TERENAS_MENETHIL              = 39,
    DATA_ENEMY_GUNSHIP                 = 40,
    DATA_UPPERSPIRE_TELE_ACT           = 41, /// also used by conditions
    DATA_BLOOD_QUEEN_LANA_THEL_COUNCIL = 42
};

enum CreaturesIds
{
    // At Light's Hammer
    NPC_HIGHLORD_TIRION_FORDRING_LH             = 37119,
    NPC_THE_LICH_KING_LH                        = 37181,
    NPC_HIGHLORD_BOLVAR_FORDRAGON_LH            = 37183,
    NPC_KOR_KRON_GENERAL                        = 37189,
    NPC_ALLIANCE_COMMANDER                      = 37190,
    NPC_TORTUNOK                                = 37992,    // Druid Armor H
    NPC_ALANA_MOONSTRIKE                        = 37999,    // Druid Armor A
    NPC_GERARDO_THE_SUAVE                       = 37993,    // Hunter Armor H
    NPC_TALAN_MOONSTRIKE                        = 37998,    // Hunter Armor A
    NPC_UVLUS_BANEFIRE                          = 38284,    // Mage Armor H
    NPC_MALFUS_GRIMFROST                        = 38283,    // Mage Armor A
    NPC_IKFIRUS_THE_VILE                        = 37991,    // Rogue Armor H
    NPC_YILI                                    = 37997,    // Rogue Armor A
    NPC_VOL_GUK                                 = 38841,    // Shaman Armor H
    NPC_JEDEBIA                                 = 38840,    // Shaman Armor A
    NPC_HARAGG_THE_UNSEEN                       = 38181,    // Warlock Armor H
    NPC_NIBY_THE_ALMIGHTY                       = 38182,    // Warlock Armor N
    NPC_GARROSH_HELLSCREAM                      = 39372,
    NPC_KING_VARIAN_WRYNN                       = 39371,
    NPC_DEATHBOUND_WARD                         = 37007,
    NPC_LADY_JAINA_PROUDMOORE_QUEST             = 38606,
    NPC_MURADIN_BRONZEBEARD_QUEST               = 38607,
    NPC_UTHER_THE_LIGHTBRINGER_QUEST            = 38608,
    NPC_LADY_SYLVANAS_WINDRUNNER_QUEST          = 38609,

    // Weekly quests
    NPC_INFILTRATOR_MINCHAR                     = 38471,
    NPC_KOR_KRON_LIEUTENANT                     = 38491,
    NPC_SKYBREAKER_LIEUTENANT                   = 38492,
    NPC_ROTTING_FROST_GIANT_10                  = 38490,
    NPC_ROTTING_FROST_GIANT_25                  = 38494,
    NPC_ALCHEMIST_ADRIANNA                      = 38501,
    NPC_ALRIN_THE_AGILE                         = 38551,
    NPC_INFILTRATOR_MINCHAR_BQ                  = 38558,
    NPC_INFILTRATOR_MINCHAR_BQ_25               = 39123,
    NPC_MINCHAR_BEAM_STALKER                    = 38557,
    NPC_VALITHRIA_DREAMWALKER_QUEST             = 38589,

    // Lord Marrowgar
    NPC_LORD_MARROWGAR                          = 36612,
    NPC_COLDFLAME                               = 36672,
    NPC_BONE_SPIKE                              = 36619,

    // Lady Deathwhisper
    NPC_LADY_DEATHWHISPER                       = 36855,
    NPC_CULT_FANATIC                            = 37890,
    NPC_DEFORMED_FANATIC                        = 38135,
    NPC_REANIMATED_FANATIC                      = 38009,
    NPC_CULT_ADHERENT                           = 37949,
    NPC_EMPOWERED_ADHERENT                      = 38136,
    NPC_REANIMATED_ADHERENT                     = 38010,
    NPC_VENGEFUL_SHADE                          = 38222,

    // Icecrown Gunship Battle
    NPC_MARTYR_STALKER_IGB_SAURFANG             = 38569,
    NPC_ALLIANCE_GUNSHIP_CANNON                 = 36838,
    NPC_HORDE_GUNSHIP_CANNON                    = 36839,
    NPC_SKYBREAKER_DECKHAND                     = 36970,
    NPC_ORGRIMS_HAMMER_CREW                     = 36971,
    NPC_IGB_HIGH_OVERLORD_SAURFANG              = 36939,
    NPC_IGB_MURADIN_BRONZEBEARD                 = 36948,
    NPC_THE_SKYBREAKER                          = 37540,
    NPC_ORGRIMS_HAMMER                          = 37215,
    NPC_GUNSHIP_HULL                            = 37547,
    NPC_TELEPORT_PORTAL                         = 37227,
    NPC_TELEPORT_EXIT                           = 37488,
    NPC_SKYBREAKER_SORCERER                     = 37116,
    NPC_SKYBREAKER_RIFLEMAN                     = 36969,
    NPC_SKYBREAKER_MORTAR_SOLDIER               = 36978,
    NPC_SKYBREAKER_MARINE                       = 36950,
    NPC_SKYBREAKER_SERGEANT                     = 36961,
    NPC_KOR_KRON_BATTLE_MAGE                    = 37117,
    NPC_KOR_KRON_AXETHROWER                     = 36968,
    NPC_KOR_KRON_ROCKETEER                      = 36982,
    NPC_KOR_KRON_REAVER                         = 36957,
    NPC_KOR_KRON_SERGEANT                       = 36960,
    NPC_ZAFOD_BOOMBOX                           = 37184,
    NPC_HIGH_CAPTAIN_JUSTIN_BARTLETT            = 37182,
    NPC_SKY_REAVER_KORM_BLACKSCAR               = 37833,

    // Deathbringer Saurfang
    NPC_DEATHBRINGER_SAURFANG                   = 37813,
    NPC_BLOOD_BEAST                             = 38508,
    NPC_SE_JAINA_PROUDMOORE                     = 37188,    // SE means Saurfang Event
    NPC_SE_MURADIN_BRONZEBEARD                  = 37200,
    NPC_SE_KING_VARIAN_WRYNN                    = 37879,
    NPC_SE_HIGH_OVERLORD_SAURFANG               = 37187,
    NPC_SE_KOR_KRON_REAVER                      = 37920,
    NPC_SE_SKYBREAKER_MARINE                    = 37830,
    NPC_FROST_FREEZE_TRAP                       = 37744,

    // Festergut
    NPC_FESTERGUT                               = 36626,
    NPC_GAS_DUMMY                               = 36659,
    NPC_MALLEABLE_OOZE_STALKER                  = 38556,

    // Rotface
    NPC_ROTFACE                                 = 36627,
    NPC_OOZE_SPRAY_STALKER                      = 37986,
    NPC_PUDDLE_STALKER                          = 37013,
    NPC_UNSTABLE_EXPLOSION_STALKER              = 38107,
    NPC_VILE_GAS_STALKER                        = 38548,

    // Professor Putricide
    NPC_PROFESSOR_PUTRICIDE                     = 36678,
    NPC_ABOMINATION_WING_MAD_SCIENTIST_STALKER  = 37824,
    NPC_GROWING_OOZE_PUDDLE                     = 37690,
    NPC_GAS_CLOUD                               = 37562,
    NPC_VOLATILE_OOZE                           = 37697,
    NPC_CHOKING_GAS_BOMB                        = 38159,
    NPC_TEAR_GAS_TARGET_STALKER                 = 38317,
    NPC_MUTATED_ABOMINATION_10                  = 37672,
    NPC_MUTATED_ABOMINATION_25                  = 38285,

    // Blood Prince Council
    NPC_PRINCE_KELESETH                         = 37972,
    NPC_PRINCE_TALDARAM                         = 37973,
    NPC_PRINCE_VALANAR                          = 37970,
    NPC_BLOOD_ORB_CONTROLLER                    = 38008,
    NPC_FLOATING_TRIGGER                        = 30298,
    NPC_DARK_NUCLEUS                            = 38369,
    NPC_BALL_OF_FLAME                           = 38332,
    NPC_BALL_OF_INFERNO_FLAME                   = 38451,
    NPC_KINETIC_BOMB_TARGET                     = 38458,
    NPC_KINETIC_BOMB                            = 38454,
    NPC_SHOCK_VORTEX                            = 38422,
    NPC_BLOOD_QUEEN_LANA_THEL_COUNCIL           = 38004,

    // Blood-Queen Lana'thel
    NPC_BLOOD_QUEEN_LANA_THEL                   = 37955,

    // Frostwing Halls gauntlet event
    NPC_CROK_SCOURGEBANE                        = 37129,
    NPC_CAPTAIN_ARNATH                          = 37122,
    NPC_CAPTAIN_BRANDON                         = 37123,
    NPC_CAPTAIN_GRONDEL                         = 37124,
    NPC_CAPTAIN_RUPERT                          = 37125,
    NPC_CAPTAIN_ARNATH_UNDEAD                   = 37491,
    NPC_CAPTAIN_BRANDON_UNDEAD                  = 37493,
    NPC_CAPTAIN_GRONDEL_UNDEAD                  = 37494,
    NPC_CAPTAIN_RUPERT_UNDEAD                   = 37495,
    NPC_YMIRJAR_BATTLE_MAIDEN                   = 37132,
    NPC_YMIRJAR_DEATHBRINGER                    = 38125,
    NPC_YMIRJAR_FROSTBINDER                     = 37127,
    NPC_YMIRJAR_HUNTRESS                        = 37134,
    NPC_YMIRJAR_WARLORD                         = 37133,
    NPC_SISTER_SVALNA                           = 37126,
    NPC_IMPALING_SPEAR                          = 38248,

    // Valithria Dreamwalker
    NPC_VALITHRIA_DREAMWALKER                   = 36789,
    NPC_GREEN_DRAGON_COMBAT_TRIGGER             = 38752,
    NPC_RISEN_ARCHMAGE                          = 37868,
    NPC_BLAZING_SKELETON                        = 36791,
    NPC_SUPPRESSER                              = 37863,
    NPC_BLISTERING_ZOMBIE                       = 37934,
    NPC_GLUTTONOUS_ABOMINATION                  = 37886,
    NPC_MANA_VOID                               = 38068,
    NPC_COLUMN_OF_FROST                         = 37918,
    NPC_ROT_WORM                                = 37907,
    NPC_THE_LICH_KING_VALITHRIA                 = 16980,
    NPC_DREAM_PORTAL_PRE_EFFECT                 = 38186,
    NPC_NIGHTMARE_PORTAL_PRE_EFFECT             = 38429,
    NPC_DREAM_PORTAL                            = 37945,
    NPC_NIGHTMARE_PORTAL                        = 38430,

    // Sindragosa
    NPC_SINDRAGOSA                              = 36853,
    NPC_SPINESTALKER                            = 37534,
    NPC_RIMEFANG                                = 37533,
    NPC_FROSTWARDEN_HANDLER                     = 37531,
    NPC_FROSTWING_WHELP                         = 37532,
    NPC_ICY_BLAST                               = 38223,
    NPC_FROST_BOMB                              = 37186,
    NPC_ICE_TOMB                                = 36980,

    // The Lich King
    NPC_THE_LICH_KING                           = 36597,
    NPC_HIGHLORD_TIRION_FORDRING_LK             = 38995,
    NPC_TERENAS_MENETHIL_FROSTMOURNE            = 36823,
    NPC_SPIRIT_WARDEN                           = 36824,
    NPC_TERENAS_MENETHIL_FROSTMOURNE_H          = 39217,
    NPC_SHAMBLING_HORROR                        = 37698,
    NPC_DRUDGE_GHOUL                            = 37695,
    NPC_ICE_SPHERE                              = 36633,
    NPC_RAGING_SPIRIT                           = 36701,
    NPC_DEFILE                                  = 38757,
    NPC_VALKYR_SHADOWGUARD                      = 36609,
    NPC_VILE_SPIRIT                             = 37799,
    NPC_WICKED_SPIRIT                           = 39190,
    NPC_STRANGULATE_VEHICLE                     = 36598,
    NPC_WORLD_TRIGGER                           = 22515,
    NPC_WORLD_TRIGGER_INFINITE_AOI              = 36171,
    NPC_SPIRIT_BOMB                             = 39189,
    NPC_FROSTMOURNE_TRIGGER                     = 38584,

    // Generic
    NPC_INVISIBLE_STALKER                       = 30298
};

enum GameObjectsIds
{
    // ICC Teleporters
    GO_SCOURGE_TRANSPORTER_LICHKING         = 202223,
    GO_SCOURGE_TRANSPORTER_UPPERSPIRE       = 202235,
    GO_SCOURGE_TRANSPORTER_LIGHTSHAMMER     = 202242,
    GO_SCOURGE_TRANSPORTER_RAMPART          = 202243,
    GO_SCOURGE_TRANSPORTER_DEATHBRINGER     = 202244,
    GO_SCOURGE_TRANSPORTER_ORATORY          = 202245,
    GO_SCOURGE_TRANSPORTER_SINDRAGOSA       = 202246,

    // Lower Spire Trash
    GO_SPIRIT_ALARM_1                       = 201814,
    GO_SPIRIT_ALARM_2                       = 201815,
    GO_SPIRIT_ALARM_3                       = 201816,
    GO_SPIRIT_ALARM_4                       = 201817,

    // Lord Marrogar
    GO_DOODAD_ICECROWN_ICEWALL02            = 201910,
    GO_ICEWALL                              = 201911,
    GO_LORD_MARROWGAR_S_ENTRANCE            = 201857,

    // Lady Deathwhisper
    GO_ORATORY_OF_THE_DAMNED_ENTRANCE       = 201563,
    GO_LADY_DEATHWHISPER_ELEVATOR           = 202220,

    // Icecrown Gunship Battle - Horde raid
    GO_ORGRIMS_HAMMER_H                     = 201812,
    GO_THE_SKYBREAKER_H                     = 201811,
    GO_GUNSHIP_ARMORY_H_10N                 = 202178,
    GO_GUNSHIP_ARMORY_H_25N                 = 202180,
    GO_GUNSHIP_ARMORY_H_10H                 = 202177,
    GO_GUNSHIP_ARMORY_H_25H                 = 202179,

    // Icecrown Gunship Battle - Alliance raid
    GO_ORGRIMS_HAMMER_A                     = 201581,
    GO_THE_SKYBREAKER_A                     = 201580,
    GO_GUNSHIP_ARMORY_A_10N                 = 201873,
    GO_GUNSHIP_ARMORY_A_25N                 = 201874,
    GO_GUNSHIP_ARMORY_A_10H                 = 201872,
    GO_GUNSHIP_ARMORY_A_25H                 = 201875,

    // Deathbringer Saurfang
    GO_SAURFANG_S_DOOR                      = 201825,
    GO_DEATHBRINGER_S_CACHE_10N             = 202239,
    GO_DEATHBRINGER_S_CACHE_25N             = 202240,
    GO_DEATHBRINGER_S_CACHE_10H             = 202238,
    GO_DEATHBRINGER_S_CACHE_25H             = 202241,

    // Professor Putricide
    GO_ORANGE_PLAGUE_MONSTER_ENTRANCE       = 201371,
    GO_GREEN_PLAGUE_MONSTER_ENTRANCE        = 201370,
    GO_SCIENTIST_AIRLOCK_DOOR_COLLISION     = 201612,
    GO_SCIENTIST_AIRLOCK_DOOR_ORANGE        = 201613,
    GO_SCIENTIST_AIRLOCK_DOOR_GREEN         = 201614,
    GO_DOODAD_ICECROWN_ORANGETUBES02        = 201617,
    GO_DOODAD_ICECROWN_GREENTUBES02         = 201618,
    GO_SCIENTIST_ENTRANCE                   = 201372,
    GO_DRINK_ME                             = 201584,
    GO_PLAGUE_SIGIL                         = 202182,

    // Blood Prince Council
    GO_CRIMSON_HALL_DOOR                    = 201376,
    GO_BLOOD_ELF_COUNCIL_DOOR               = 201378,
    GO_BLOOD_ELF_COUNCIL_DOOR_RIGHT         = 201377,

    // Blood-Queen Lana'thel
    GO_DOODAD_ICECROWN_BLOODPRINCE_DOOR_01  = 201746,
    GO_DOODAD_ICECROWN_GRATE_01             = 201755,
    GO_BLOODWING_SIGIL                      = 202183,

    // Valithria Dreamwalker
    GO_GREEN_DRAGON_BOSS_ENTRANCE           = 201375,
    GO_GREEN_DRAGON_BOSS_EXIT               = 201374,
    GO_DOODAD_ICECROWN_ROOSTPORTCULLIS_01   = 201380,
    GO_DOODAD_ICECROWN_ROOSTPORTCULLIS_02   = 201381,
    GO_DOODAD_ICECROWN_ROOSTPORTCULLIS_03   = 201382,
    GO_DOODAD_ICECROWN_ROOSTPORTCULLIS_04   = 201383,
    GO_CACHE_OF_THE_DREAMWALKER_10N         = 201959,
    GO_CACHE_OF_THE_DREAMWALKER_25N         = 202339,
    GO_CACHE_OF_THE_DREAMWALKER_10H         = 202338,
    GO_CACHE_OF_THE_DREAMWALKER_25H         = 202340,

    // Sindragosa
    GO_SINDRAGOSA_ENTRANCE_DOOR             = 201373,
    GO_SINDRAGOSA_SHORTCUT_ENTRANCE_DOOR    = 201369,
    GO_SINDRAGOSA_SHORTCUT_EXIT_DOOR        = 201379,
    GO_ICE_WALL                             = 202396,
    GO_ICE_BLOCK                            = 201722,
    GO_SIGIL_OF_THE_FROSTWING               = 202181,

    // The Lich King
    GO_ARTHAS_PLATFORM                      = 202161,
    GO_ARTHAS_PRECIPICE                     = 202078,
    GO_DOODAD_ICECROWN_THRONEFROSTYWIND01   = 202188,
    GO_DOODAD_ICECROWN_THRONEFROSTYEDGE01   = 202189,
    GO_DOODAD_ICESHARD_STANDING02           = 202141,
    GO_DOODAD_ICESHARD_STANDING01           = 202142,
    GO_DOODAD_ICESHARD_STANDING03           = 202143,
    GO_DOODAD_ICESHARD_STANDING04           = 202144,
    GO_DOODAD_ICECROWN_SNOWEDGEWARNING01    = 202190,
    GO_FROZEN_LAVAMAN                       = 202436,
    GO_LAVAMAN_PILLARS_CHAINED              = 202437,
    GO_LAVAMAN_PILLARS_UNCHAINED            = 202438
};

enum AchievementCriteriaIds
{
    // Lord Marrowgar
    CRITERIA_BONED_10N                  = 12775,
    CRITERIA_BONED_25N                  = 12962,
    CRITERIA_BONED_10H                  = 13393,
    CRITERIA_BONED_25H                  = 13394,

    // Rotface
    CRITERIA_DANCES_WITH_OOZES_10N      = 12984,
    CRITERIA_DANCES_WITH_OOZES_25N      = 12966,
    CRITERIA_DANCES_WITH_OOZES_10H      = 12985,
    CRITERIA_DANCES_WITH_OOZES_25H      = 12983,

    // Professor Putricide
    CRITERIA_NAUSEA_10N                 = 12987,
    CRITERIA_NAUSEA_25N                 = 12968,
    CRITERIA_NAUSEA_10H                 = 12988,
    CRITERIA_NAUSEA_25H                 = 12981,

    // Blood Prince Council
    CRITERIA_ORB_WHISPERER_10N          = 13033,
    CRITERIA_ORB_WHISPERER_25N          = 12969,
    CRITERIA_ORB_WHISPERER_10H          = 13034,
    CRITERIA_ORB_WHISPERER_25H          = 13032,

    // Blood-Queen Lana'thel
    CRITERIA_KILL_LANA_THEL_10M         = 13340,
    CRITERIA_KILL_LANA_THEL_25M         = 13360,
    CRITERIA_ONCE_BITTEN_TWICE_SHY_10N  = 12780,
    CRITERIA_ONCE_BITTEN_TWICE_SHY_25N  = 13012,
    CRITERIA_ONCE_BITTEN_TWICE_SHY_10V  = 13011,
    CRITERIA_ONCE_BITTEN_TWICE_SHY_25V  = 13013
};

enum SharedActions
{
    // Icecrown Gunship Battle
    ACTION_ENEMY_GUNSHIP_TALK   = -369390,
    ACTION_EXIT_SHIP            = -369391,

    // Festergut
    ACTION_FESTERGUT_COMBAT     = -366260,
    ACTION_FESTERGUT_GAS        = -366261,
    ACTION_FESTERGUT_DEATH      = -366262,

    // Rotface
    ACTION_ROTFACE_COMBAT       = -366270,
    ACTION_ROTFACE_OOZE         = -366271,
    ACTION_ROTFACE_DEATH        = -366272,
    ACTION_CHANGE_PHASE         = -366780,

    // Blood-Queen Lana'thel
    ACTION_KILL_MINCHAR         = -379550,

    // Frostwing Halls gauntlet event
    ACTION_VRYKUL_DEATH         = 37129,

    // Sindragosa
    ACTION_START_FROSTWYRM      = -368530,
    ACTION_TRIGGER_ASPHYXIATION = -368531,

    // The Lich King
    ACTION_RESTORE_LIGHT        = -72262,
    ACTION_FROSTMOURNE_INTRO    = -36823
};

enum WeekliesICC
{
    QUEST_DEPROGRAMMING_10                  = 24869,
    QUEST_DEPROGRAMMING_25                  = 24875,
    QUEST_SECURING_THE_RAMPARTS_10          = 24870,
    QUEST_SECURING_THE_RAMPARTS_25          = 24877,
    QUEST_RESIDUE_RENDEZVOUS_10             = 24873,
    QUEST_RESIDUE_RENDEZVOUS_25             = 24878,
    QUEST_BLOOD_QUICKENING_10               = 24874,
    QUEST_BLOOD_QUICKENING_25               = 24879,
    QUEST_RESPITE_FOR_A_TORNMENTED_SOUL_10  = 24872,
    QUEST_RESPITE_FOR_A_TORNMENTED_SOUL_25  = 24880
};

enum WorldStatesICC
{
    WORLDSTATE_SHOW_TIMER           = 4903,
    WORLDSTATE_EXECUTION_TIME       = 4904,
    WORLDSTATE_SHOW_ATTEMPTS        = 4940,
    WORLDSTATE_ATTEMPTS_REMAINING   = 4941,
    WORLDSTATE_ATTEMPTS_MAX         = 4942
};

enum AreaIds
{
    AREA_ICECROWN_CITADEL   = 4812,
    AREA_THE_FROZEN_THRONE  = 4859
};

class spell_trigger_spell_from_caster : public SpellScriptLoader
{
    public:
        spell_trigger_spell_from_caster(char const* scriptName, uint32 triggerId, TriggerCastFlags triggerFlags = TRIGGERED_FULL_MASK)
            : SpellScriptLoader(scriptName), _triggerId(triggerId), _triggerFlags(triggerFlags) { }

        class spell_trigger_spell_from_caster_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_trigger_spell_from_caster_SpellScript);

        public:
            spell_trigger_spell_from_caster_SpellScript(uint32 triggerId, TriggerCastFlags triggerFlags)
                : SpellScript(), _triggerId(triggerId), _triggerFlags(triggerFlags) { }

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(_triggerId))
                    return false;
                return true;
            }

            void HandleTrigger()
            {
                GetCaster()->CastSpell(GetHitUnit(), _triggerId, _triggerFlags);
            }

            void Register() override
            {
                AfterHit += SpellHitFn(spell_trigger_spell_from_caster_SpellScript::HandleTrigger);
            }

            uint32 _triggerId;
            TriggerCastFlags _triggerFlags;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_trigger_spell_from_caster_SpellScript(_triggerId, _triggerFlags);
        }

    private:
        uint32 _triggerId;
        TriggerCastFlags _triggerFlags;
};

template<class AI, class T>
inline AI* GetIcecrownCitadelAI(T* obj)
{
    return GetInstanceAI<AI>(obj, ICCScriptName);
}

#endif // ICECROWN_CITADEL_H_
