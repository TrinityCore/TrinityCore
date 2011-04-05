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

#ifndef DEF_ICECROWN_CITADEL_H
#define DEF_ICECROWN_CITADEL_H
#define WEEKLY_NPCS   7

#define ICCScriptName "instance_icecrown_citadel"

enum eSharedSpells
{
    SPELL_BERSERK   = 26662,
    SPELL_BERSERK2  = 47008
};

enum eEnums
{
    SOUND_ENDING_7_KING                   = 17360,
    MOVIE_ID_ARTHAS_DEATH                 = 16
};

enum eAchievements
{
    ACHIEV_BONED_10                             = 4534,
    ACHIEV_BONED_25                             = 4610,
    ACHIEV_FROZEN_THRONE_10                    = 4530,
    ACHIEV_FROZEN_THRONE_25                    = 4597,
    AVHIEV_FULL_HOUSE_10                        = 4535,
    AVHIEV_FULL_HOUSE_25                        = 4611,
    ACHIEV_MESS_10                              = 4537,
    ACHIEV_MESS_25                              = 4613,
    ACHIEVMENT_ONCE_BITTEN_TWICE_SHY_10         = 4539,
    ACHIEVMENT_ONCE_BITTEN_TWICE_SHY_25         = 4618,
    ACHIEV_ALL_YOU_CAN_EAT_10                   = 4580,
    ACHIEV_ALL_YOU_CAN_EAT_25                   = 4620,
    ACHIEV_BEEN_WAITING_A_LONG_TIME_FOR_THIS_10 = 4601,
    ACHIEV_BEEN_WAITING_A_LONG_TIME_FOR_THIS_25 = 4621,
    ACHIEV_NECK_DEEP_IN_VILE_10                 = 4581,
    ACHIEV_NECK_DEEP_IN_VILE_25                 = 4622,
    ACHIEV_PORTAL_JOCKEY_10                     = 4579,
    ACHIEV_PORTAL_JOCKEY_25                     = 4619,
    ACHIEV_VALITHRIA_DREAMWALKER_RESCUES_10N    = 4649,
    ACHIEV_VALITHRIA_DREAMWALKER_RESCUES_10H    = 4674,//     Valithria Dreamwalker rescues (Heroic Icecrown 10 player) 
    ACHIEV_VALITHRIA_DREAMWALKER_RESCUES_25N    = 4675,//     Valithria Dreamwalker rescues (Icecrown 25 player) 
    ACHIEV_VALITHRIA_DREAMWALKER_RESCUES_25H    = 4676,//     Valithria Dreamwalker rescues (Heroic Icecrown 25 player)
};

enum eAchievementCriteria
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
    CRITERIA_ONCE_BITTEN_TWICE_SHY_25V  = 13013,
};

enum eCommonActions
{
    // Coldflame Traps
    ACTION_STOP_TRAPS           = -377440,

    //Putricide actions
    ACTION_ACTIVATE_ORANGE_DOOR = -366781,
    ACTION_ACTIVATE_GREEN_DOOR  = -366782,
    ACTION_OPEN_DOORS           = -366783,

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

    // Sindragosa
     ACTION_START_FROSTWYRM      = -368530,
     ACTION_TRIGGER_ASPHYXIATION = -368531,
    ACTION_BOMB_LANDED          = -368532
};
enum eAdditionalActions
{
    ACTION_LAND = 100,
    ACTION_NOT_LANDED = 101
};
enum Data
{
    DATA_LORD_MARROWGAR_EVENT,
    DATA_DEATHWHISPER_EVENT,
    DATA_GUNSHIP_BATTLE_EVENT,
    DATA_SAURFANG_EVENT,
    DATA_FESTERGUT_EVENT,
    DATA_ROTFACE_EVENT,
    DATA_PROFESSOR_PUTRICIDE_EVENT,
    DATA_BLOOD_PRINCE_COUNCIL_EVENT,
    DATA_BLOOD_QUEEN_LANA_THEL_EVENT,
    DATA_VALITHRIA_DREAMWALKER_EVENT,
    DATA_SINDRAGOSA_EVENT,
    DATA_LICH_KING_EVENT,
    //Additional data
    DATA_SINDRAGOSA_FROSTWYRMS,
    DATA_SPINESTALKER_EVENT,
    DATA_RIMEFANG_EVENT,
    DATA_TEAM_IN_INSTANCE,
    //Teleport state
    DATA_TELEPORT_ORATORY_OF_THE_DAMNED_ACTIVATED,
    DATA_TELEPORT_RAMPART_OF_SKULLS_ACTIVATED,
    DATA_TELEPORT_DEATHBRINGER_S_RISE_ACTIVATED,
    DATA_TELEPORT_UPPER_SPIRE_ACTIVATED,
    DATA_TELEPORT_SINDRAGOSA_S_LAIR_ACTIVATED,
    DATA_TELEPORT_FROZEN_THRONE_ACTIVATED,
    DATA_COLDFLAME_JETS_EVENT,
    DATA_OOZE_VALVE_ACTIVATED,
    DATA_GAS_VALVE_ACTIVATED,
    DATA_NECROTIC_STACK,
    DATA_BLOOD_QUICKENING_STATE,
    DATA_HEROIC_ATTEMPTS,
    //Achievements
    DATA_NECK_DEEP_ACHIEVEMENT,
    DATA_BONED_ACHIEVEMENT,
    DATA_OOZE_DANCE_ACHIEVEMENT,
    DATA_NAUSEA_ACHIEVEMENT,
    DATA_ORB_WHISPERER_ACHIEVEMENT,
    DATA_PORTAL_JOCKEY_ACHIEVEMENT,
    DATA_BEEN_WAITING_ACHIEVEMENT,
};

enum Data64
{
    // Boss GUIDs
    GUID_LORD_MARROWGAR,
    GUID_LADY_DEATHWHISPER,
    GUID_SAURFANG,
    GUID_FESTERGUT,
    GUID_ROTFACE,
    GUID_PROFESSOR_PUTRICIDE,
    GUID_PRINCE_VALANAR_ICC,
    GUID_PRINCE_KELESETH_ICC,
    GUID_PRINCE_TALDARAM_ICC,
    GUID_BLOOD_QUEEN_LANA_THEL,
    GUID_VALITHRIA_DREAMWALKER,
    GUID_VALITHRIA_ALTERNATIVE,
    GUID_VALITHRIA_COMBAT_TRIGGER,
    GUID_SINDRAGOSA,
    GUID_LICH_KING,

    // Additional data
    GUID_SAURFANG_EVENT_NPC,
    GUID_DEATHBRINGER_S_DOOR,
    GUID_TIRION,
    GUID_BLOOD_PRINCES_CONTROL,
    GUID_PUTRICIDE_TABLE,
    GUID_SINDRAGOSA_ENTRANCE_DOOR,
    GUID_RIMEFANG,
    GUID_SPINESTALKER,
    GUID_TERENAS_FIGHTER,
    GUID_SPIRIT_WARDEN,

    //Teleport data
    GUID_TELEPORT_LIGHTS_HAMMER,
    GUID_TELEPORT_ORATORY_OF_THE_DAMNED,
    GUID_TELEPORT_RAMPART_OF_SKULLS,
    GUID_TELEPORT_DEATHBRINGERS_RISE,
    GUID_TELEPORT_UPPER_SPIRE,
    GUID_TELEPORT_SINDRAGOSAS_LAIR,
    GUID_TELEPORT_FROZEN_THRONE,
    //Professor Putricide doors
    GUID_PROF_COLLISION_DOOR,
    GUID_PROF_ORANGE_DOOR,
    GUID_PROF_GREEN_DOOR,

    GUID_SPIRIT_ALARM1,
    GUID_SPIRIT_ALARM2,
    GUID_SPIRIT_ALARM3,
    GUID_SPIRIT_ALARM4,

    GUID_DEATHBOUND_WARD1,
    GUID_DEATHBOUND_WARD2,
    GUID_DEATHBOUND_WARD3,
    GUID_DEATHBOUND_WARD4,

    GUID_INCONSPICUOUS_LEVER,

    GUID_ICE_SHARD_1,    
    GUID_ICE_SHARD_2,         
    GUID_ICE_SHARD_3,
    GUID_ICE_SHARD_4,
    GUID_LAVAMAN,
    GUID_HANGINGMAN,
    GUID_FROSTY_EDGE_OUTER,
    GUID_FROSTY_EDGE_INNER,
    GUID_EDGE_DESTROY_WARNING
};

enum eCreatures
{
    // At Light's Hammer    
    NPC_HIGHLORD_TIRION_FORDRING_LH             = 37119,    
    NPC_THE_LICH_KING_LH                        = 37181,    
    NPC_HIGHLORD_BOLVAR_FORDRAGON_LH            = 37183,

    // Weekly quests
     NPC_INFILTRATOR_MINCHAR                     = 38471,
     NPC_KOR_KRON_LIEUTENANT                     = 38491,
     NPC_SKYBREAKER_LIEUTENANT                   = 38492,
     NPC_ALCHEMIST_ADRIANNA                      = 38501,
     NPC_ALRIN_THE_AGILE                         = 38551,
     NPC_INFILTRATOR_MINCHAR_BQ                  = 38558,
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

    NPC_OOZE_COVERED_TENTACLE_STALKER           = 38308,
    NPC_SLIMY_TENTACLE_STALKER                  = 38309,
    NPC_GUNSHIP                                 = 30343,
    NPC_KOR_KRON_GENERAL                        = 37189,
    NPC_ALLIANCE_COMMANDER                      = 37190,
    NPC_TORTUNOK                                = 37992,
    NPC_ALANA_MOONSTRIKE                        = 37999,
    NPC_GERARDO_THE_SUAVE                       = 37993,
    NPC_TALAN_MOONSTRIKE                        = 37998,
    NPC_UVLUS_BANEFIRE                          = 38284,
    NPC_MALFUS_GRIMFROST                        = 38283,
    NPC_IKFIRUS_THE_VILE                        = 37991,
    NPC_YILI                                    = 37997,
    NPC_VOL_GUK                                 = 38841,
    NPC_JEDEBIA                                 = 38840,
    NPC_HARAGG_THE_UNSEEN                       = 38181,
    // Deathbringer Saurfang
    NPC_DEATHBRINGER_SAURFANG                   = 37813,
    NPC_BLOOD_BEAST                             = 38508,
    NPC_SE_JAINA_PROUDMOORE                     = 37188,    // SE means Saurfang Event
    NPC_SE_MURADIN_BRONZEBEARD                  = 37200,
    NPC_SE_KING_VARIAN_WRYNN                    = 37879,
    NPC_SE_HIGH_OVERLORD_SAURFANG               = 37187,
    NPC_SE_KOR_KRON_REAVER                      = 37920,
    NPC_SE_SKYBREAKER_MARINE                    = 37830,

    NPC_NIBY_THE_ALMIGHTY                       = 38182,
    NPC_GARROSH_HELLSCREAM                      = 39372,
    NPC_KING_VARIAN_WRYNN                       = 39371,

    NPC_MUTATED_ABOMINATION_10                  = 37672,
    NPC_MUTATED_ABOMINATION_25                  = 38285,

    NPC_FESTERGUT                               = 36626,
    NPC_PUDDLE_STALKER                          = 37013,
    NPC_ORANGE_GAS_STALKER                      = 36659,
    NPC_VILE_GAS_STALKER                        = 38548,
    NPC_ROTFACE                                 = 36627,
    NPC_OOZE_SPRAY_STALKER                      = 37986,
    NPC_GREEN_GAS_STALKER                       = 37824,
    NPC_LITTLE_OOZE                             = 36897,
    NPC_BIG_OOZE                                = 36899,
    NPC_STINKY                                  = 37025,
    NPC_PRECIOUS                                = 37217,
    NPC_GROWING_OZZE_STALKER                    = 38234,
    NPC_TEAR_GAS_STALKER                        = 38317,
    NPC_CHOKING_GAS_BOMB                        = 38159,
    NPC_PROFESSOR_PUTRICIDE                     = 36678,
    NPC_ABOMINATION_WING_MAD_SCIENTIST_STALKER  = 37824,
    NPC_GROWING_OOZE_PUDDLE                     = 37690,
    NPC_GAS_CLOUD                               = 37562,
    NPC_VOLATILE_OOZE                           = 37697,
    NPC_TEAR_GAS_TARGET_STALKER                 = 38317,
    NPC_PRINCE_VALANAR_ICC                      = 37970,
    NPC_PRINCE_KELESETH_ICC                     = 37972,
    NPC_PRINCE_TALDARAM_ICC                     = 37973,
    NPC_BLOOD_ORB_CONTROLLER                    = 38008,
    NPC_FLOATING_TRIGGER                        = 30298,
    NPC_DARK_NUCLEUS                            = 38369,
    NPC_BALL_OF_FLAME                           = 38332,
    NPC_BALL_OF_INFERNO_FLAME                   = 38451,
    NPC_KINETIC_BOMB_TARGET                     = 38458,
    NPC_KINETIC_BOMB                            = 38454,
    NPC_SHOCK_VORTEX                            = 38422,
    NPC_BLOOD_QUEEN_LANA_THEL                   = 37955,
    NPC_SWARMING_SHADOWS                        = 38163,
    NPC_VALITHRIA_DREAMWALKER                   = 36789,
    NPC_VALITHRIA_ALTERNATIVE                   = 37950,
    NPC_PORTAL_NORMAL_MODE_PRE                  = 38186,
    NPC_PORTAL_NORMAL_MODE_NPC                  = 37945,
    NPC_PORTAL_HEROIC_MODE_PRE                  = 38429,
    NPC_PORTAL_HEROIC_MODE_NPC                  = 38430,
    NPC_ROT_WORM                                = 37907,
    NPC_PORTAL                                  = 37945,
    NPC_DREAM_CLOUD                             = 37985,
    NPC_NIGHTMARE_CLOUD                         = 38421,
    NPC_MANA_VOID                               = 38068,
    NPC_ABOMINATION                             = 37886,
    NPC_SKELETON                                = 36791,
    NPC_ARCHMAGE                                = 37868,
    NPC_SUPPRESSOR                              = 37863,
    NPC_ZOMBIE                                  = 37934,
    NPC_COLUMN_OF_FROST                         = 37918,
    NPC_COMBAT_TRIGGER                          = 38752,

    // Sindragosa
    NPC_SINDRAGOSA                             = 36853,
    NPC_SPINESTALKER                           = 37534,
    NPC_RIMEFANG                               = 37533,
    NPC_FROSTWARDEN_HANDLER                    = 37531,
    NPC_FROSTWING_WHELP                        = 37532,
    NPC_ICY_BLAST                              = 38223,
    NPC_FROST_BOMB                             = 37186,
    NPC_ICE_TOMB                               = 36980,

    //Lich King
    NPC_LICH_KING                               = 36597,
    NPC_TIRION_ICC                              = 38995,
    NPC_PLATFORM_DESTRUCTIBLE_EDGE_STALKER      = 22515,
    NPC_FROST_BOMB_EXPLOSION_VISUAL             = 34149,
    NPC_TERENAS_MENETHIL                        = 38579,
    NPC_FROSTMOURNE_TRIGGER                     = 38584,
    NPC_TERENAS_FIGHTER                         = 36823, //for frostmourne
    NPC_SPIRIT_WARDEN                           = 36824,
    NPC_ICE_SPHERE                              = 36633,
    NPC_DRUDGE_GHOUL                            = 37695,
    NPC_SHAMBLING_HORROR                        = 37698,
    NPC_VALKYR                                  = 36609,
    NPC_DEFILE                                  = 38757,
    NPC_RAGING_SPIRIT                           = 36701,
    NPC_TRIGGER                                 = 38667,
    NPC_VILE_SPIRIT                             = 37799,
    //NPC_FROSTWING_WHELP                      = 37532,
    //NPC_FROSTWARDEN_HANDLER                  = 37531
    NPC_FROST_FREEZE_TRAP                       = 37744,
    NPC_DEATHBOUND_WARD                         = 37007,
    NPC_SEVERED_ESSENCE                         = 38410,
    NPC_VALKYR_HERALD                           = 37098
};

enum eGameobjects
{
    // Lower spire
    GO_SPIRIT_ALARM1                          = 201814,
    GO_SPIRIT_ALARM2                          = 201815,
    GO_SPIRIT_ALARM3                          = 201816,
    GO_SPIRIT_ALARM4                          = 201817,

    // Lord Marrogar
    GO_LORD_MARROWGAR_ICE_WALL                = 201910,
    GO_LORD_MARROWGAR_ICE_WALL_1              = 201911,
    GO_LORD_MARROWGAR_S_ENTRANCE              = 201857,

    // Lady Deathwhisper
    GO_ORATORY_OF_THE_DAMNED_ENTRANCE         = 201563,
    GO_LADY_DEATHWHISPER_ELEVATOR             = 202220,

    // Gunship Battle
    GO_ORGRIM_S_HAMMER_HORDE_ICC              = 201812,
    GO_ORGRIM_S_HAMMER_ALLIANCE_ICC           = 201581,
    GO_THE_SKYBREAKER_HORDE_ICC               = 201811,
    GO_THE_SKYBREAKER_ALLIANCE_ICC            = 201580,

    // Deathbringer Saurfang
    GO_DEATHBRINGER_S_DOOR                    = 201825,
    GO_DEATHBRINGER_S_CACHE_10N               = 202239,
    GO_DEATHBRINGER_S_CACHE_25N               = 202240,
    GO_DEATHBRINGER_S_CACHE_10H               = 202238,
    GO_DEATHBRINGER_S_CACHE_25H               = 202241,

    // Upper Beaches
    GO_BLOODWING_DOOR                         = 201920,
    GO_FROSTWING_DOOR                         = 201919,
    GO_PLAGUE_SIGIL                           = 202182,
    GO_BLOODWING_SIGIL                        = 202183,
    GO_FROSTWING_SIGIL                        = 202181,
    GO_INCONSPICUOUS_LEVER                    = 201818,

    // Plagueworks
    GO_ORANGE_PLAGUE_MONSTER_ENTRANCE         = 201371,
    GO_GREEN_PLAGUE_MONSTER_ENTRANCE          = 201370,
    GO_SCIENTIST_AIRLOCK_DOOR_COLLISION       = 201612,
    GO_SCIENTIST_AIRLOCK_DOOR_ORANGE          = 201613,
    GO_SCIENTIST_AIRLOCK_DOOR_GREEN           = 201614,
    GO_DOODAD_ICECROWN_ORANGETUBES02          = 201617,
    GO_DOODAD_ICECROWN_GREENTUBES02           = 201618,
    GO_SCIENTIST_ENTRANCE                     = 201372,
    GO_DRINK_ME                               = 201584,
    GO_OOZE_VALVE                             = 201615,
    GO_GAS_VALVE                              = 201616,

    // Blood Prince Council
    GO_CRIMSON_HALL_DOOR                      = 201376,
    GO_BLOOD_ELF_COUNCIL_DOOR                 = 201378,
    GO_BLOOD_ELF_COUNCIL_DOOR_RIGHT           = 201377,

    // Blood-Queen Lana'thel
    GO_BLOOD_QUEEN_BLOOD_BARRIER              = 201746,
    GO_DOODAD_ICECROWN_GRATE_01               = 201755,

    // Valithria Dreamwalker
    GO_GREEN_DRAGON_BOSS_ENTRANCE             = 201375,
    GO_GREEN_DRAGON_BOSS_EXIT                 = 201374,
    GO_DREAMWALKER_DOOR_1                     = 201380,
    GO_DREAMWALKER_DOOR_2                     = 201381,
    GO_DREAMWALKER_DOOR_3                     = 201382,
    GO_DREAMWALKER_DOOR_4                     = 201383,
    GO_VALITHRIA_ELEVATOR                     = 202234,
    GO_DREAMWALKER_CACHE_10_N                 = 201959,
    GO_DREAMWALKER_CACHE_25_N                 = 202338,
    GO_DREAMWALKER_CACHE_10_H                 = 202339,
    GO_DREAMWALKER_CACHE_25_H                 = 202340,

    // Sindragosa
    GO_SINDRAGOSA_ENTRANCE_DOOR               = 201373,
    GO_SINDRAGOSA_SHORTCUT_ENTRANCE_DOOR      = 201369,
    GO_SINDRAGOSA_SHORTCUT_EXIT_DOOR          = 201379,
    GO_SINDRAGOSA_ICE_WALL                    = 202396,
    GO_SINDRAGOSA_ELEVATOR                    = 196840,
    GO_SINDRAGOSA_ICE_BLOCK                   = 201722,

    // Lich King
    GO_ARTHAS_PLATFORM                        = 202161,
    GO_ICE_SHARD_1                            = 202141,
    GO_ICE_SHARD_2                            = 202142,
    GO_ICE_SHARD_3                            = 202143,
    GO_ICE_SHARD_4                            = 202144,
    GO_FROSTY_EDGE_OUTER                      = 202188,
    GO_FROSTY_EDGE_INNER                      = 202189,
    GO_EDGE_DESTROY_WARNING                   = 202190,
    GO_LAVAMAN                                = 202436,
    GO_HANGINGMAN                             = 202437,

    // Teleports
    GO_TELEPORT_LIGHT_S_HAMMER                = 202242,
    GO_TELEPORT_ORATORY_OF_THE_DAMNED         = 202243,
    GO_TELEPORT_RAMPART_OF_SKULLS             = 202244,
    GO_TELEPORT_DEATHBRINGER_RISE             = 202245,
    GO_TELEPORT_UPPER_SPIRE                   = 202235,
    GO_TELEPORT_SINDRAGOSA_S_LAIR             = 202246,
    GO_TELEPORT_FROZEN_THRONE                 = 202223,

};
enum TeleporterSpells
{
    SPELL_TELEPORT_ICC_LIGHT_S_HAMMER         = 70781,
    SPELL_TELEPORT_ICC_ORATORY_OF_THE_DAMNED  = 70856,
    SPELL_TELEPORT_ICC_RAMPART_OF_SKULLS      = 70857,
    SPELL_TELEPORT_ICC_DEATHBRINGER_S_RISE    = 70858,
    SPELL_TELEPORT_ICC_UPPER_SPIRE            = 70859,
    SPELL_TELEPORT_ICC_SINDRAGOSA_S_LAIR      = 70861,
    SPELL_TELEPORT_ICC_FROZEN_THRONE          = 70860
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
    QUEST_RESPITE_FOR_A_TORNMENTED_SOUL_25  = 24880,
};

enum WorldStatesICC
{
    WORLDSTATE_SHOW_TIMER           = 4903,
    WORLDSTATE_EXECUTION_TIME       = 4904,
    WORLDSTATE_SHOW_ATTEMPTS        = 4940,
    WORLDSTATE_ATTEMPTS_REMAINING   = 4941,
    WORLDSTATE_ATTEMPTS_MAX         = 4942,
};

void DespawnAllCreaturesAround(Creature *ref, uint32 entry);
void UnsummonSpecificCreaturesNearby(Creature *ref, uint32 entry, float radius);
void LeaveOnlyPlayers(std::list<Unit*> &unitList);
uint32 GetPhase(const EventMap &em);
void TeleportPlayerToFrozenThrone(Player *player);
typedef std::list<Player*> TPlayerList;
TPlayerList GetPlayersInTheMap(Map *pMap);
TPlayerList GetAttackablePlayersInTheMap(Map *pMap);
// Declaration
extern Position const SindragosaSpawnPos;
#endif
