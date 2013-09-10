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

/**
* @file RBAC.h
* @brief Role Based Access Control related classes definition
*
* This file contains all the classes and enums used to implement
* Role Based Access Control
*
* RBAC Rules:
* - Pemission: Defines an autorization to perform certain operation.
* - Role: Set of permissions.
* - Group: Set of roles.
* - An Account can have multiple groups, roles and permissions.
* - Account Groups can only be granted or revoked
* - Account Roles and Permissions can be granted, denied or revoked
* - Grant: Assignment of the object (role/permission) and allow it
* - Deny: Assignment of the object (role/permission) and deny it
* - Revoke: Removal of the object (role/permission) no matter if it was granted or denied
* - Global Permissions are computed as:
*       Group Grants + Role Grants + User Grans - Role Grants - User Grants
* - Groups, Roles and Permissions can be assigned by realm
*/

#ifndef _RBAC_H
#define _RBAC_H

#include "Define.h"
#include <string>
#include <bitset>
#include <set>
#include <map>

enum RBACPermissions
{
    RBAC_PERM_INSTANT_LOGOUT                                 = 1,
    RBAC_PERM_SKIP_QUEUE                                     = 2,
    RBAC_PERM_JOIN_NORMAL_BG                                 = 3,
    RBAC_PERM_JOIN_RANDOM_BG                                 = 4,
    RBAC_PERM_JOIN_ARENAS                                    = 5,
    RBAC_PERM_JOIN_DUNGEON_FINDER                            = 6,
    RBAC_PERM_PLAYER_COMMANDS                                = 7,
    RBAC_PERM_MODERATOR_COMMANDS                             = 8,
    RBAC_PERM_GAMEMASTER_COMMANDS                            = 9,
    RBAC_PERM_ADMINISTRATOR_COMMANDS                         = 10,
    RBAC_PERM_LOG_GM_TRADE                                   = 11,
    RBAC_PERM_CONSOLE_COMMANDS                               = 12, // Not pressent in DB
    RBAC_PERM_SKIP_CHECK_INSTANCE_REQUIRED_BOSSES            = 13,
    RBAC_PERM_SKIP_CHECK_CHARACTER_CREATION_TEAMMASK         = 14,
    RBAC_PERM_SKIP_CHECK_CHARACTER_CREATION_CLASSMASK        = 15,
    RBAC_PERM_SKIP_CHECK_CHARACTER_CREATION_RACEMASK         = 16,
    RBAC_PERM_SKIP_CHECK_CHARACTER_CREATION_RESERVEDNAME     = 17,
    RBAC_PERM_SKIP_CHECK_CHARACTER_CREATION_HEROIC_CHARACTER = 18,
    RBAC_PERM_SKIP_CHECK_CHAT_CHANNEL_REQ                    = 19,
    RBAC_PERM_SKIP_CHECK_DISABLE_MAP                         = 20,
    RBAC_PERM_SKIP_CHECK_MORE_TALENTS_THAN_ALLOWED           = 21,
    RBAC_PERM_SKIP_CHECK_CHAT_SPAM                           = 22,
    RBAC_PERM_SKIP_CHECK_OVERSPEED_PING                      = 23,
    RBAC_PERM_TWO_SIDE_CHARACTER_CREATION                    = 24,
    RBAC_PERM_TWO_SIDE_INTERACTION_CHAT                      = 25,
    RBAC_PERM_TWO_SIDE_INTERACTION_CHANNEL                   = 26,
    RBAC_PERM_TWO_SIDE_INTERACTION_MAIL                      = 27,
    RBAC_PERM_TWO_SIDE_WHO_LIST                              = 28,
    RBAC_PERM_TWO_SIDE_ADD_FRIEND                            = 29,
    RBAC_PERM_COMMANDS_SAVE_WITHOUT_DELAY                    = 30,
    RBAC_PERM_COMMANDS_USE_UNSTUCK_WITH_ARGS                 = 31,
    RBAC_PERM_COMMANDS_BE_ASSIGNED_TICKET                    = 32,
    RBAC_PERM_COMMANDS_NOTIFY_COMMAND_NOT_FOUND_ERROR        = 33,
    RBAC_PERM_COMMANDS_APPEAR_IN_GM_LIST                     = 34,
    RBAC_PERM_WHO_SEE_ALL_SEC_LEVELS                         = 35,
    RBAC_PERM_CAN_FILTER_WHISPERS                            = 36,
    RBAC_PERM_CHAT_USE_STAFF_BADGE                           = 37,
    RBAC_PERM_RESURRECT_WITH_FULL_HPS                        = 38,
    RBAC_PERM_RESTORE_SAVED_GM_STATE                         = 39,
    RBAC_PERM_ALLOW_GM_FRIEND                                = 40,
    RBAC_PERM_USE_START_GM_LEVEL                             = 41,
    RBAC_PERM_OPCODE_WORLD_TELEPORT                          = 42,
    RBAC_PERM_OPCODE_WHOIS                                   = 43,
    RBAC_PERM_RECEIVE_GLOBAL_GM_TEXTMESSAGE                  = 44,
    RBAC_PERM_SILENTLY_JOIN_CHANNEL                          = 45,
    RBAC_PERM_CHANGE_CHANNEL_NOT_MODERATOR                   = 46,
    RBAC_PERM_CHECK_FOR_LOWER_SECURITY                       = 47,
    RBAC_PERM_COMMANDS_PINFO_CHECK_PERSONAL_DATA             = 48,
    RBAC_PERM_EMAIL_CONFIRM_FOR_PASS_CHANGE                  = 49,
    RBAC_PERM_MAY_CHECK_OWN_EMAIL                            = 50,
    // Leave some space for core permissions
    RBAC_PERM_COMMAND_RBAC                                   = 200,
    RBAC_PERM_COMMAND_RBAC_ACC                               = 201,
    RBAC_PERM_COMMAND_RBAC_ACC_GROUP                         = 202,
    RBAC_PERM_COMMAND_RBAC_ACC_GROUP_ADD                     = 203,
    RBAC_PERM_COMMAND_RBAC_ACC_GROUP_DEL                     = 204,
    RBAC_PERM_COMMAND_RBAC_ACC_ROLE                          = 205,
    RBAC_PERM_COMMAND_RBAC_ACC_ROLE_GRANT                    = 206,
    RBAC_PERM_COMMAND_RBAC_ACC_ROLE_DENY                     = 207,
    RBAC_PERM_COMMAND_RBAC_ACC_ROLE_REVOKE                   = 208,
    RBAC_PERM_COMMAND_RBAC_ACC_PERM                          = 209,
    RBAC_PERM_COMMAND_RBAC_ACC_PERM_GRANT                    = 210,
    RBAC_PERM_COMMAND_RBAC_ACC_PERM_DENY                     = 211,
    RBAC_PERM_COMMAND_RBAC_ACC_PERM_REVOKE                   = 212,
    RBAC_PERM_COMMAND_RBAC_LIST                              = 213,
    RBAC_PERM_COMMAND_RBAC_LIST_GROUPS                       = 214,
    RBAC_PERM_COMMAND_RBAC_LIST_ROLES                        = 215,
    RBAC_PERM_COMMAND_RBAC_LIST_PERMS                        = 216,
    RBAC_PERM_COMMAND_ACCOUNT                                = 217,
    RBAC_PERM_COMMAND_ACCOUNT_ADDON                          = 218,
    RBAC_PERM_COMMAND_ACCOUNT_CREATE                         = 219,
    RBAC_PERM_COMMAND_ACCOUNT_DELETE                         = 220,
    RBAC_PERM_COMMAND_ACCOUNT_LOCK                           = 221,
    RBAC_PERM_COMMAND_ACCOUNT_LOCK_COUNTRY                   = 222,
    RBAC_PERM_COMMAND_ACCOUNT_LOCK_IP                        = 223,
    RBAC_PERM_COMMAND_ACCOUNT_ONLINE_LIST                    = 224,
    RBAC_PERM_COMMAND_ACCOUNT_PASSWORD                       = 225,
    RBAC_PERM_COMMAND_ACCOUNT_SET                            = 226,
    RBAC_PERM_COMMAND_ACCOUNT_SET_ADDON                      = 227,
    RBAC_PERM_COMMAND_ACCOUNT_SET_GMLEVEL                    = 228,
    RBAC_PERM_COMMAND_ACCOUNT_SET_PASSWORD                   = 229,
    RBAC_PERM_COMMAND_ACHIEVEMENT                            = 230,
    RBAC_PERM_COMMAND_ACHIEVEMENT_ADD                        = 231,
    RBAC_PERM_COMMAND_ARENA                                  = 232,
    RBAC_PERM_COMMAND_ARENA_CAPTAIN                          = 233,
    RBAC_PERM_COMMAND_ARENA_CREATE                           = 234,
    RBAC_PERM_COMMAND_ARENA_DISBAND                          = 235,
    RBAC_PERM_COMMAND_ARENA_INFO                             = 236,
    RBAC_PERM_COMMAND_ARENA_LOOKUP                           = 237,
    RBAC_PERM_COMMAND_ARENA_RENAME                           = 238,
    RBAC_PERM_COMMAND_BAN                                    = 239,
    RBAC_PERM_COMMAND_BAN_ACCOUNT                            = 240,
    RBAC_PERM_COMMAND_BAN_CHARACTER                          = 241,
    RBAC_PERM_COMMAND_BAN_IP                                 = 242,
    RBAC_PERM_COMMAND_BAN_PLAYERACCOUNT                      = 243,
    RBAC_PERM_COMMAND_BANINFO                                = 244,
    RBAC_PERM_COMMAND_BANINFO_ACCOUNT                        = 245,
    RBAC_PERM_COMMAND_BANINFO_CHARACTER                      = 246,
    RBAC_PERM_COMMAND_BANINFO_IP                             = 247,
    RBAC_PERM_COMMAND_BANLIST                                = 248,
    RBAC_PERM_COMMAND_BANLIST_ACCOUNT                        = 249,
    RBAC_PERM_COMMAND_BANLIST_CHARACTER                      = 250,
    RBAC_PERM_COMMAND_BANLIST_IP                             = 251,
    RBAC_PERM_COMMAND_UNBAN                                  = 252,
    RBAC_PERM_COMMAND_UNBAN_ACCOUNT                          = 253,
    RBAC_PERM_COMMAND_UNBAN_CHARACTER                        = 254,
    RBAC_PERM_COMMAND_UNBAN_IP                               = 255,
    RBAC_PERM_COMMAND_UNBAN_PLAYERACCOUNT                    = 256,
    RBAC_PERM_COMMAND_BF                                     = 257,
    RBAC_PERM_COMMAND_BF_START                               = 258,
    RBAC_PERM_COMMAND_BF_STOP                                = 259,
    RBAC_PERM_COMMAND_BF_SWITCH                              = 260,
    RBAC_PERM_COMMAND_BF_TIMER                               = 261,
    RBAC_PERM_COMMAND_BF_ENABLE                              = 262,
    RBAC_PERM_COMMAND_ACCOUNT_EMAIL                          = 263,
    RBAC_PERM_COMMAND_ACCOUNT_SET_SEC                        = 264,
    RBAC_PERM_COMMAND_ACCOUNT_SET_SEC_EMAIL                  = 265,
    RBAC_PERM_COMMAND_ACCOUNT_SET_SEC_REGMAIL                = 266,
    RBAC_PERM_COMMAND_CAST                                   = 267,
    RBAC_PERM_COMMAND_CAST_BACK                              = 268,
    RBAC_PERM_COMMAND_CAST_DIST                              = 269,
    RBAC_PERM_COMMAND_CAST_SELF                              = 270,
    RBAC_PERM_COMMAND_CAST_TARGET                            = 271,
    RBAC_PERM_COMMAND_CAST_DEST                              = 272,
    RBAC_PERM_COMMAND_CHARACTER                              = 273,
    RBAC_PERM_COMMAND_CHARACTER_CUSTOMIZE                    = 274,
    RBAC_PERM_COMMAND_CHARACTER_CHANGEFACTION                = 275,
    RBAC_PERM_COMMAND_CHARACTER_CHANGERACE                   = 276,
    RBAC_PERM_COMMAND_CHARACTER_DELETED                      = 277,
    RBAC_PERM_COMMAND_CHARACTER_DELETED_DELETE               = 278,
    RBAC_PERM_COMMAND_CHARACTER_DELETED_LIST                 = 279,
    RBAC_PERM_COMMAND_CHARACTER_DELETED_RESTORE              = 280,
    RBAC_PERM_COMMAND_CHARACTER_DELETED_OLD                  = 281,
    RBAC_PERM_COMMAND_CHARACTER_ERASE                        = 282,
    RBAC_PERM_COMMAND_CHARACTER_LEVEL                        = 283,
    RBAC_PERM_COMMAND_CHARACTER_RENAME                       = 284,
    RBAC_PERM_COMMAND_CHARACTER_REPUTATION                   = 285,
    RBAC_PERM_COMMAND_CHARACTER_TITLES                       = 286,
    RBAC_PERM_COMMAND_LEVELUP                                = 287,
    RBAC_PERM_COMMAND_PDUMP                                  = 288,
    RBAC_PERM_COMMAND_PDUMP_LOAD                             = 289,
    RBAC_PERM_COMMAND_PDUMP_WRITE                            = 290,
    RBAC_PERM_COMMAND_CHEAT                                  = 291,
    RBAC_PERM_COMMAND_CHEAT_CASTTIME                         = 292,
    RBAC_PERM_COMMAND_CHEAT_COOLDOWN                         = 293,
    RBAC_PERM_COMMAND_CHEAT_EXPLORE                          = 294,
    RBAC_PERM_COMMAND_CHEAT_GOD                              = 295,
    RBAC_PERM_COMMAND_CHEAT_POWER                            = 296,
    RBAC_PERM_COMMAND_CHEAT_STATUS                           = 297,
    RBAC_PERM_COMMAND_CHEAT_TAXI                             = 298,
    RBAC_PERM_COMMAND_CHEAT_WATERWALK                        = 299,
    RBAC_PERM_COMMAND_DEBUG                                  = 300,
    RBAC_PERM_COMMAND_DEBUG_ANIM                             = 301,
    RBAC_PERM_COMMAND_DEBUG_AREATRIGGERS                     = 302,
    RBAC_PERM_COMMAND_DEBUG_ARENA                            = 303,
    RBAC_PERM_COMMAND_DEBUG_BG                               = 304,
    RBAC_PERM_COMMAND_DEBUG_ENTERVEHICLE                     = 305,
    RBAC_PERM_COMMAND_DEBUG_GETITEMSTATE                     = 306,
    RBAC_PERM_COMMAND_DEBUG_GETITEMVALUE                     = 307,
    RBAC_PERM_COMMAND_DEBUG_GETVALUE                         = 308,
    RBAC_PERM_COMMAND_DEBUG_HOSTIL                           = 309,
    RBAC_PERM_COMMAND_DEBUG_ITEMEXPIRE                       = 310,
    RBAC_PERM_COMMAND_DEBUG_LOOTRECIPIENT                    = 311,
    RBAC_PERM_COMMAND_DEBUG_LOS                              = 312,
    RBAC_PERM_COMMAND_DEBUG_MOD32VALUE                       = 313,
    RBAC_PERM_COMMAND_DEBUG_MOVEFLAGS                        = 314,
    RBAC_PERM_COMMAND_DEBUG_PLAY                             = 315,
    RBAC_PERM_COMMAND_DEBUG_PLAY_CINEMATIC                   = 316,
    RBAC_PERM_COMMAND_DEBUG_PLAY_MOVIE                       = 317,
    RBAC_PERM_COMMAND_DEBUG_PLAY_SOUND                       = 318,
    RBAC_PERM_COMMAND_DEBUG_SEND                             = 319,
    RBAC_PERM_COMMAND_DEBUG_SEND_BUYERROR                    = 320,
    RBAC_PERM_COMMAND_DEBUG_SEND_CHANNELNOTIFY               = 321,
    RBAC_PERM_COMMAND_DEBUG_SEND_CHATMESSAGE                 = 322,
    RBAC_PERM_COMMAND_DEBUG_SEND_EQUIPERROR                  = 323,
    RBAC_PERM_COMMAND_DEBUG_SEND_LARGEPACKET                 = 324,
    RBAC_PERM_COMMAND_DEBUG_SEND_OPCODE                      = 325,
    RBAC_PERM_COMMAND_DEBUG_SEND_QINVALIDMSG                 = 326,
    RBAC_PERM_COMMAND_DEBUG_SEND_QPARTYMSG                   = 327,
    RBAC_PERM_COMMAND_DEBUG_SEND_SELLERROR                   = 328,
    RBAC_PERM_COMMAND_DEBUG_SEND_SETPHASESHIFT               = 329,
    RBAC_PERM_COMMAND_DEBUG_SEND_SPELLFAIL                   = 330,
    RBAC_PERM_COMMAND_DEBUG_SETAURASTATE                     = 331,
    RBAC_PERM_COMMAND_DEBUG_SETBIT                           = 332,
    RBAC_PERM_COMMAND_DEBUG_SETITEMVALUE                     = 333,
    RBAC_PERM_COMMAND_DEBUG_SETVALUE                         = 334,
    RBAC_PERM_COMMAND_DEBUG_SETVID                           = 335,
    RBAC_PERM_COMMAND_DEBUG_SPAWNVEHICLE                     = 336,
    RBAC_PERM_COMMAND_DEBUG_THREAT                           = 337,
    RBAC_PERM_COMMAND_DEBUG_UPDATE                           = 338,
    RBAC_PERM_COMMAND_DEBUG_UWS                              = 339,
    RBAC_PERM_COMMAND_WPGPS                                  = 340,
    RBAC_PERM_COMMAND_DESERTER                               = 341,
    RBAC_PERM_COMMAND_DESERTER_BG                            = 342,
    RBAC_PERM_COMMAND_DESERTER_BG_ADD                        = 343,
    RBAC_PERM_COMMAND_DESERTER_BG_REMOVE                     = 344,
    RBAC_PERM_COMMAND_DESERTER_INSTANCE                      = 345,
    RBAC_PERM_COMMAND_DESERTER_INSTANCE_ADD                  = 346,
    RBAC_PERM_COMMAND_DESERTER_INSTANCE_REMOVE               = 347,
    RBAC_PERM_COMMAND_DISABLE                                = 348,
    RBAC_PERM_COMMAND_DISABLE_ADD                            = 349,
    RBAC_PERM_COMMAND_DISABLE_ADD_ACHIEVEMENT_CRITERIA       = 350,
    RBAC_PERM_COMMAND_DISABLE_ADD_BATTLEGROUND               = 351,
    RBAC_PERM_COMMAND_DISABLE_ADD_MAP                        = 352,
    RBAC_PERM_COMMAND_DISABLE_ADD_MMAP                       = 353,
    RBAC_PERM_COMMAND_DISABLE_ADD_OUTDOORPVP                 = 354,
    RBAC_PERM_COMMAND_DISABLE_ADD_QUEST                      = 355,
    RBAC_PERM_COMMAND_DISABLE_ADD_SPELL                      = 356,
    RBAC_PERM_COMMAND_DISABLE_ADD_VMAP                       = 357,
    RBAC_PERM_COMMAND_DISABLE_REMOVE                         = 358,
    RBAC_PERM_COMMAND_DISABLE_REMOVE_ACHIEVEMENT_CRITERIA    = 359,
    RBAC_PERM_COMMAND_DISABLE_REMOVE_BATTLEGROUND            = 360,
    RBAC_PERM_COMMAND_DISABLE_REMOVE_MAP                     = 361,
    RBAC_PERM_COMMAND_DISABLE_REMOVE_MMAP                    = 362,
    RBAC_PERM_COMMAND_DISABLE_REMOVE_OUTDOORPVP              = 363,
    RBAC_PERM_COMMAND_DISABLE_REMOVE_QUEST                   = 364,
    RBAC_PERM_COMMAND_DISABLE_REMOVE_SPELL                   = 365,
    RBAC_PERM_COMMAND_DISABLE_REMOVE_VMAP                    = 366,
    RBAC_PERM_COMMAND_EVENT                                  = 367,
    RBAC_PERM_COMMAND_EVENT_ACTIVELIST                       = 368,
    RBAC_PERM_COMMAND_EVENT_START                            = 369,
    RBAC_PERM_COMMAND_EVENT_STOP                             = 370,
    RBAC_PERM_COMMAND_GM                                     = 371,
    RBAC_PERM_COMMAND_GM_CHAT                                = 372,
    RBAC_PERM_COMMAND_GM_FLY                                 = 373,
    RBAC_PERM_COMMAND_GM_INGAME                              = 374,
    RBAC_PERM_COMMAND_GM_LIST                                = 375,
    RBAC_PERM_COMMAND_GM_VISIBLE                             = 376,
    RBAC_PERM_COMMAND_GO                                     = 377,
    RBAC_PERM_COMMAND_GO_CREATURE                            = 378,
    RBAC_PERM_COMMAND_GO_GRAVEYARD                           = 379,
    RBAC_PERM_COMMAND_GO_GRID                                = 380,
    RBAC_PERM_COMMAND_GO_OBJECT                              = 381,
    RBAC_PERM_COMMAND_GO_TAXINODE                            = 382,
    RBAC_PERM_COMMAND_GO_TICKET                              = 383,
    RBAC_PERM_COMMAND_GO_TRIGGER                             = 384,
    RBAC_PERM_COMMAND_GO_XYZ                                 = 385,
    RBAC_PERM_COMMAND_GO_ZONEXY                              = 386,
    RBAC_PERM_COMMAND_GOBJECT                                = 387,
    RBAC_PERM_COMMAND_GOBJECT_ACTIVATE                       = 388,
    RBAC_PERM_COMMAND_GOBJECT_ADD                            = 389,
    RBAC_PERM_COMMAND_GOBJECT_ADD_TEMP                       = 390,
    RBAC_PERM_COMMAND_GOBJECT_DELETE                         = 391,
    RBAC_PERM_COMMAND_GOBJECT_INFO                           = 392,
    RBAC_PERM_COMMAND_GOBJECT_MOVE                           = 393,
    RBAC_PERM_COMMAND_GOBJECT_NEAR                           = 394,
    RBAC_PERM_COMMAND_GOBJECT_SET                            = 395,
    RBAC_PERM_COMMAND_GOBJECT_SET_PHASE                      = 396,
    RBAC_PERM_COMMAND_GOBJECT_SET_STATE                      = 397,
    RBAC_PERM_COMMAND_GOBJECT_TARGET                         = 398,
    RBAC_PERM_COMMAND_GOBJECT_TURN                           = 399,
    // 400 - reuse
    RBAC_PERM_COMMAND_GUILD                                  = 401,
    RBAC_PERM_COMMAND_GUILD_CREATE                           = 402,
    RBAC_PERM_COMMAND_GUILD_DELETE                           = 403,
    RBAC_PERM_COMMAND_GUILD_INVITE                           = 404,
    RBAC_PERM_COMMAND_GUILD_UNINVITE                         = 405,
    RBAC_PERM_COMMAND_GUILD_RANK                             = 406,
    RBAC_PERM_COMMAND_GUILD_RENAME                           = 407,
    RBAC_PERM_COMMAND_HONOR                                  = 408,
    RBAC_PERM_COMMAND_HONOR_ADD                              = 409,
    RBAC_PERM_COMMAND_HONOR_ADD_KILL                         = 410,
    RBAC_PERM_COMMAND_HONOR_UPDATE                           = 411,
    RBAC_PERM_COMMAND_INSTANCE                               = 412,
    RBAC_PERM_COMMAND_INSTANCE_LISTBINDS                     = 413,
    RBAC_PERM_COMMAND_INSTANCE_UNBIND                        = 414,
    RBAC_PERM_COMMAND_INSTANCE_STATS                         = 415,
    RBAC_PERM_COMMAND_INSTANCE_SAVEDATA                      = 416,
    RBAC_PERM_COMMAND_LEARN                                  = 417,
    RBAC_PERM_COMMAND_LEARN_ALL                              = 418,
    RBAC_PERM_COMMAND_LEARN_ALL_MY                           = 419,
    RBAC_PERM_COMMAND_LEARN_ALL_MY_CLASS                     = 420,
    RBAC_PERM_COMMAND_LEARN_ALL_MY_PETTALENTS                = 421,
    RBAC_PERM_COMMAND_LEARN_ALL_MY_SPELLS                    = 422,
    RBAC_PERM_COMMAND_LEARN_ALL_MY_TALENTS                   = 423,
    RBAC_PERM_COMMAND_LEARN_ALL_GM                           = 424,
    RBAC_PERM_COMMAND_LEARN_ALL_CRAFTS                       = 425,
    RBAC_PERM_COMMAND_LEARN_ALL_DEFAULT                      = 426,
    RBAC_PERM_COMMAND_LEARN_ALL_LANG                         = 427,
    RBAC_PERM_COMMAND_LEARN_ALL_RECIPES                      = 428,
    RBAC_PERM_COMMAND_UNLEARN                                = 429,
    RBAC_PERM_COMMAND_LFG                                    = 430,
    RBAC_PERM_COMMAND_LFG_PLAYER                             = 431,
    RBAC_PERM_COMMAND_LFG_GROUP                              = 432,
    RBAC_PERM_COMMAND_LFG_QUEUE                              = 433,
    RBAC_PERM_COMMAND_LFG_CLEAN                              = 434,
    RBAC_PERM_COMMAND_LFG_OPTIONS                            = 435,
    RBAC_PERM_COMMAND_LIST                                   = 436,
    RBAC_PERM_COMMAND_LIST_CREATURE                          = 437,
    RBAC_PERM_COMMAND_LIST_ITEM                              = 438,
    RBAC_PERM_COMMAND_LIST_OBJECT                            = 439,
    RBAC_PERM_COMMAND_LIST_AURAS                             = 440,
    RBAC_PERM_COMMAND_LIST_MAIL                              = 441,
    RBAC_PERM_COMMAND_LOOKUP                                 = 442,
    RBAC_PERM_COMMAND_LOOKUP_AREA                            = 443,
    RBAC_PERM_COMMAND_LOOKUP_CREATURE                        = 444,
    RBAC_PERM_COMMAND_LOOKUP_EVENT                           = 445,
    RBAC_PERM_COMMAND_LOOKUP_FACTION                         = 446,
    RBAC_PERM_COMMAND_LOOKUP_ITEM                            = 447,
    RBAC_PERM_COMMAND_LOOKUP_ITEMSET                         = 448,
    RBAC_PERM_COMMAND_LOOKUP_OBJECT                          = 449,
    RBAC_PERM_COMMAND_LOOKUP_QUEST                           = 450,
    RBAC_PERM_COMMAND_LOOKUP_PLAYER                          = 451,
    RBAC_PERM_COMMAND_LOOKUP_PLAYER_IP                       = 452,
    RBAC_PERM_COMMAND_LOOKUP_PLAYER_ACCOUNT                  = 453,
    RBAC_PERM_COMMAND_LOOKUP_PLAYER_EMAIL                    = 454,
    RBAC_PERM_COMMAND_LOOKUP_SKILL                           = 455,
    RBAC_PERM_COMMAND_LOOKUP_SPELL                           = 456,
    RBAC_PERM_COMMAND_LOOKUP_SPELL_ID                        = 457,
    RBAC_PERM_COMMAND_LOOKUP_TAXINODE                        = 458,
    RBAC_PERM_COMMAND_LOOKUP_TELE                            = 459,
    RBAC_PERM_COMMAND_LOOKUP_TITLE                           = 460,
    RBAC_PERM_COMMAND_LOOKUP_MAP                             = 461,
    RBAC_PERM_COMMAND_ANNOUNCE                               = 462,
    RBAC_PERM_COMMAND_CHANNEL                                = 463,
    RBAC_PERM_COMMAND_CHANNEL_SET                            = 464,
    RBAC_PERM_COMMAND_CHANNEL_SET_OWNERSHIP                  = 465,
    RBAC_PERM_COMMAND_GMANNOUNCE                             = 466,
    RBAC_PERM_COMMAND_GMNAMEANNOUNCE                         = 467,
    RBAC_PERM_COMMAND_GMNOTIFY                               = 468,
    RBAC_PERM_COMMAND_NAMEANNOUNCE                           = 469,
    RBAC_PERM_COMMAND_NOTIFY                                 = 470,
    RBAC_PERM_COMMAND_WHISPERS                               = 471,
    RBAC_PERM_COMMAND_GROUP                                  = 472,
    RBAC_PERM_COMMAND_GROUP_LEADER                           = 473,
    RBAC_PERM_COMMAND_GROUP_DISBAND                          = 474,
    RBAC_PERM_COMMAND_GROUP_REMOVE                           = 475,
    RBAC_PERM_COMMAND_GROUP_JOIN                             = 476,
    RBAC_PERM_COMMAND_GROUP_LIST                             = 477,
    RBAC_PERM_COMMAND_GROUP_SUMMON                           = 478,
    RBAC_PERM_COMMAND_PET                                    = 479,
    RBAC_PERM_COMMAND_PET_CREATE                             = 480,
    RBAC_PERM_COMMAND_PET_LEARN                              = 481,
    RBAC_PERM_COMMAND_PET_UNLEARN                            = 482,

    // custom permissions 1000+
    RBAC_PERM_MAX
};

enum RBACCommandResult
{
    RBAC_OK,
    RBAC_CANT_ADD_ALREADY_ADDED,
    RBAC_CANT_REVOKE_NOT_IN_LIST,
    RBAC_IN_GRANTED_LIST,
    RBAC_IN_DENIED_LIST,
    RBAC_ID_DOES_NOT_EXISTS
};

typedef std::bitset<RBAC_PERM_MAX> RBACPermissionContainer;
typedef std::set<uint32> RBACRoleContainer;
typedef std::set<uint32> RBACGroupContainer;

class RBACObject
{
    public:
        RBACObject(uint32 id = 0, std::string const& name = ""):
            _id(id), _name(name) { }

        virtual ~RBACObject() { }

        /// Gets the Name of the Object
        std::string const& GetName() const { return _name; }
        /// Gets the Id of the Object
        uint32 GetId() const { return _id; }

    private:
        uint32 _id;                                        ///> id of the object
        std::string _name;                                 ///> name of the object
};

/// Permission: Defines an autorization to perform certain operation
class RBACPermission: public RBACObject
{
    public:
        RBACPermission(uint32 id = 0, std::string const& name = ""):
            RBACObject(id, name) { }
};

/// Set of Permissions
class RBACRole: public RBACObject
{
    public:
        RBACRole(uint32 id = 0, std::string const& name = ""):
            RBACObject(id, name) { }

        /// Gets the Permissions assigned to this role
        RBACPermissionContainer const& GetPermissions() const { return _perms; }
        /// Grants a Permission (Adds)
        void GrantPermission(uint32 id);
        /// Revokes a Permission (Removes)
        void RevokePermission(uint32 id);

    private:
        RBACPermissionContainer _perms;                    ///> Set of permissions
};

/// Set of Roles
class RBACGroup: public RBACObject
{
    public:
        RBACGroup(uint32 id = 0, std::string const& name = ""):
            RBACObject(id, name) { }

        /// Gets the Roles assigned to this group
        RBACRoleContainer const& GetRoles() const { return _roles; }
        /// Grants a Role (Adds)
        void GrantRole(uint32 role);
        /// Revokes a Role (Removes)
        void RevokeRole(uint32 role);

    private:
        RBACRoleContainer _roles;                          ///> Set of Roles
};

/**
 * @name RBACData
 * @brief Contains all needed information about the acccount
 *
 * This class contains all the data needed to calculate the account permissions.
 * RBACDAta is formed by group permissions and user permissions through:
 * - Granted Groups, which contains roles, which contains permissions: Set of granted permissions
 * - Granted Roles, which contains permissions: Set of granted permissions
 * - Denied Roles, which contains permissions: Set of denied permissions
 * - Granted Permissions
 * - Denied Permissions
 *
 * Calculation of current Permissions: Granted permissions - Denied permissions
 * - Granted permissions: through groups, through roles and directly assigned
 * - Denied permissions: through roles and directly assigned
 */
class RBACData: public RBACObject
{
    public:
        RBACData(uint32 id, std::string const& name, int32 realmId):
            RBACObject(id, name), _realmId(realmId) { }

        /**
         * @name HasPermission
         * @brief Checks if certain action is allowed
         *
         * Checks if certain action can be performed.
         *
         * @return grant or deny action
         *
         * Example Usage:
         * @code
         * bool Player::CanJoinArena(Battleground* bg)
         * {
         *     return bg->isArena() && HasPermission(RBAC_PERM_JOIN_ARENA);
         * }
         * @endcode
         */
        bool HasPermission(uint32 permission) const { return _globalPerms.test(permission); }

        // Functions enabled to be used by command system
        /// Returns all the granted permissions (after computation)
        RBACPermissionContainer const& GetPermissions() const { return _globalPerms; }
        /// Returns all the granted permissions
        RBACPermissionContainer const& GetGrantedPermissions() const { return _grantedPerms; }
        /// Returns all the denied permissions
        RBACPermissionContainer const& GetDeniedPermissions() const { return _deniedPerms; }
        /// Returns all the granted roles
        RBACRoleContainer const& GetGrantedRoles() const { return _grantedRoles; }
        /// Returns all the denied roles
        RBACRoleContainer const& GetDeniedRoles() const { return _deniedRoles; }
        /// Returns all the granted groups
        RBACGroupContainer const& GetGroups() const { return _groups; }

        /**
         * @name AddGroup
         * @brief Adds new group
         *
         * Add a new group to the account. If realm is 0 or the group can not be added
         * No save to db action will be performed.
         *
         * Fails if group Id does not exists or group already present
         *
         * @param groupId group to be added
         * @param realmId realm affected
         *
         * @return Success or failure (with reason) to add the group
         *
         * Example Usage:
         * @code
         * // previously defined "RBACData* rbac" with proper initialization
         * uint32 groupId = 2;
         * if (rbac->AddGroup(groupId) == RBAC_OK)
         *     TC_LOG_DEBUG(LOG_FILTER_PLAYER, "Group %u succesfully added", groupId);
         * @endcode
         */
        RBACCommandResult AddGroup(uint32 groupId, int32 realmId = 0);

        /**
         * @name RemoveGroup
         * @brief Removes a group
         *
         * Removes a group from the account. If realm is 0 or the group can not be removed
         * No save to db action will be performed. Any delete operation will always affect
         * "all realms (-1)" in addition to the realm specified
         *
         * Fails if group not present
         *
         * @param groupId group to be removed
         * @param realmId realm affected
         *
         * @return Success or failure (with reason) to remove the group
         *
         * Example Usage:
         * // previously defined "RBACData* rbac" with proper initialization
         * uint32 groupId = 2;
         * if (rbac->RemoveGroup(groupId) == RBAC_OK)
         *     TC_LOG_DEBUG(LOG_FILTER_PLAYER, "Group %u succesfully removed", groupId);
         * @endcode
         */
        RBACCommandResult RemoveGroup(uint32 groupId, int32 realmId = 0);

        /**
         * @name GrantRole
         * @brief Grants a role
         *
         * Grants a role to the account. If realm is 0 or the role can not be added
         * No save to db action will be performed.
         *
         * Fails if role Id does not exists or role already granted or denied
         *
         * @param roleId role to be granted
         * @param realmId realm affected
         *
         * @return Success or failure (with reason) to grant the role
         *
         * Example Usage:
         * // previously defined "RBACData* rbac" with proper initialization
         * uint32 roleId = 2;
         * if (rbac->GrantRole(roleId) == RBAC_IN_DENIED_LIST)
         *     TC_LOG_DEBUG(LOG_FILTER_PLAYER, "Failed to grant role %u, already denied", roleId);
         * @endcode
         */
        RBACCommandResult GrantRole(uint32 roleId, int32 realmId = 0);

        /**
         * @name DenyRole
         * @brief Denies a role
         *
         * Denied a role to the account. If realm is 0 or the role can not be added
         * No save to db action will be performed.
         *
         * Fails if role Id does not exists or role already granted or denied
         *
         * @param roleId role to be denied
         * @param realmId realm affected
         *
         * @return Success or failure (with reason) to deny the role
         *
         * Example Usage:
         * // previously defined "RBACData* rbac" with proper initialization
         * uint32 roleId = 2;
         * if (rbac->DenyRole(roleId) == RBAC_ID_DOES_NOT_EXISTS)
         *     TC_LOG_DEBUG(LOG_FILTER_PLAYER, "Role Id %u does not exists", roleId);
         * @endcode
         */
        RBACCommandResult DenyRole(uint32 roleId, int32 realmId = 0);

        /**
         * @name RevokeRole
         * @brief Removes a role
         *
         * Removes a role from the account. If realm is 0 or the role can not be removed
         * No save to db action will be performed. Any delete operation will always affect
         * "all realms (-1)" in addition to the realm specified
         *
         * Fails if role not present
         *
         * @param roleId role to be removed
         * @param realmId realm affected
         *
         * @return Success or failure (with reason) to remove the role
         *
         * Example Usage:
         * // previously defined "RBACData* rbac" with proper initialization
         * uint32 roleId = 2;
         * if (rbac->RevokeRole(roleId) == RBAC_OK)
         *     TC_LOG_DEBUG(LOG_FILTER_PLAYER, "Role %u succesfully removed", roleId);
         * @endcode
         */
        RBACCommandResult RevokeRole(uint32 roleId, int32 realmId = 0);

        /**
         * @name GrantRole
         * @brief Grants a permission
         *
         * Grants a permission to the account. If realm is 0 or the permission can not be added
         * No save to db action will be performed.
         *
         * Fails if permission Id does not exists or permission already granted or denied
         *
         * @param permissionId permission to be granted
         * @param realmId realm affected
         *
         * @return Success or failure (with reason) to grant the permission
         *
         * Example Usage:
         * // previously defined "RBACData* rbac" with proper initialization
         * uint32 permissionId = 2;
         * if (rbac->GrantRole(permissionId) == RBAC_IN_DENIED_LIST)
         *     TC_LOG_DEBUG(LOG_FILTER_PLAYER, "Failed to grant permission %u, already denied", permissionId);
         * @endcode
         */
        RBACCommandResult GrantPermission(uint32 permissionId, int32 realmId = 0);

        /**
         * @name DenyPermission
         * @brief Denies a permission
         *
         * Denied a permission to the account. If realm is 0 or the permission can not be added
         * No save to db action will be performed.
         *
         * Fails if permission Id does not exists or permission already granted or denied
         *
         * @param permissionId permission to be denied
         * @param realmId realm affected
         *
         * @return Success or failure (with reason) to deny the permission
         *
         * Example Usage:
         * // previously defined "RBACData* rbac" with proper initialization
         * uint32 permissionId = 2;
         * if (rbac->DenyRole(permissionId) == RBAC_ID_DOES_NOT_EXISTS)
         *     TC_LOG_DEBUG(LOG_FILTER_PLAYER, "Role Id %u does not exists", permissionId);
         * @endcode
         */
        RBACCommandResult DenyPermission(uint32 permissionId, int32 realmId = 0);

        /**
         * @name RevokePermission
         * @brief Removes a permission
         *
         * Removes a permission from the account. If realm is 0 or the permission can not be removed
         * No save to db action will be performed. Any delete operation will always affect
         * "all realms (-1)" in addition to the realm specified
         *
         * Fails if permission not present
         *
         * @param permissionId permission to be removed
         * @param realmId realm affected
         *
         * @return Success or failure (with reason) to remove the permission
         *
         * Example Usage:
         * // previously defined "RBACData* rbac" with proper initialization
         * uint32 permissionId = 2;
         * if (rbac->RevokeRole(permissionId) == RBAC_OK)
         *     TC_LOG_DEBUG(LOG_FILTER_PLAYER, "Permission %u succesfully removed", permissionId);
         * @endcode
         */
        RBACCommandResult RevokePermission(uint32 permissionId, int32 realmId = 0);

        /// Loads all permissions, groups and roles assigned to current account
        void LoadFromDB();
    private:
        /// Saves a role to DB, Granted or Denied
        void SaveRole(uint32 role, bool granted, int32 realm);
        /// Saves a permission to DB, Granted or Denied
        void SavePermission(uint32 role, bool granted, int32 realm);

        /**
         * @name CalculateNewPermissions
         * @brief Calculates new permissions
         *
         * Calculates new permissions after some change in groups, roles or permissions.
         * The calculation is done Granted - Denied:
         * - Granted permissions: through groups, through roles and directly assigned
         * - Denied permissions: through roles and directly assigned
         */
        void CalculateNewPermissions();

        int32 GetRealmId() { return _realmId; }

        int32 _realmId;                                    ///> RealmId Affected
        RBACGroupContainer _groups;                        ///> Granted groups
        RBACRoleContainer _grantedRoles;                   ///> Granted roles
        RBACRoleContainer _deniedRoles;                    ///> Denied roles
        RBACPermissionContainer _grantedPerms;             ///> Granted permissions
        RBACPermissionContainer _deniedPerms;              ///> Denied permissions
        RBACPermissionContainer _globalPerms;              ///> Calculated permissions
};

#endif
