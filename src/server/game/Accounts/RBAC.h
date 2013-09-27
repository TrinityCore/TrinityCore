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

namespace rbac
{

enum RBACPermissions
{
    RBAC_PERM_INSTANT_LOGOUT                                 = 1,
    RBAC_PERM_SKIP_QUEUE                                     = 2,
    RBAC_PERM_JOIN_NORMAL_BG                                 = 3,
    RBAC_PERM_JOIN_RANDOM_BG                                 = 4,
    RBAC_PERM_JOIN_ARENAS                                    = 5,
    RBAC_PERM_JOIN_DUNGEON_FINDER                            = 6,
    //  7 - reuse
    //  8 - reuse
    //  9 - reuse
    // 10 - reuse
    RBAC_PERM_LOG_GM_TRADE                                   = 11,
    // 12 - reuse
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
    RBAC_PERM_COMMAND_SEND                                   = 483,
    RBAC_PERM_COMMAND_SEND_ITEMS                             = 484,
    RBAC_PERM_COMMAND_SEND_MAIL                              = 485,
    RBAC_PERM_COMMAND_SEND_MESSAGE                           = 486,
    RBAC_PERM_COMMAND_SEND_MONEY                             = 487,
    RBAC_PERM_COMMAND_ADDITEM                                = 488,
    RBAC_PERM_COMMAND_ADDITEMSET                             = 489,
    RBAC_PERM_COMMAND_APPEAR                                 = 490,
    RBAC_PERM_COMMAND_AURA                                   = 491,
    RBAC_PERM_COMMAND_BANK                                   = 492,
    RBAC_PERM_COMMAND_BINDSIGHT                              = 493,
    RBAC_PERM_COMMAND_COMBATSTOP                             = 494,
    RBAC_PERM_COMMAND_COMETOME                               = 495,
    RBAC_PERM_COMMAND_COMMANDS                               = 496,
    RBAC_PERM_COMMAND_COOLDOWN                               = 497,
    RBAC_PERM_COMMAND_DAMAGE                                 = 498,
    RBAC_PERM_COMMAND_DEV                                    = 499,
    RBAC_PERM_COMMAND_DIE                                    = 500,
    RBAC_PERM_COMMAND_DISMOUNT                               = 501,
    RBAC_PERM_COMMAND_DISTANCE                               = 502,
    RBAC_PERM_COMMAND_FLUSHARENAPOINTS                       = 503,
    RBAC_PERM_COMMAND_FREEZE                                 = 504,
    RBAC_PERM_COMMAND_GPS                                    = 505,
    RBAC_PERM_COMMAND_GUID                                   = 506,
    RBAC_PERM_COMMAND_HELP                                   = 507,
    RBAC_PERM_COMMAND_HIDEAREA                               = 508,
    RBAC_PERM_COMMAND_ITEMMOVE                               = 509,
    RBAC_PERM_COMMAND_KICK                                   = 510,
    RBAC_PERM_COMMAND_LINKGRAVE                              = 511,
    RBAC_PERM_COMMAND_LISTFREEZE                             = 512,
    RBAC_PERM_COMMAND_MAXSKILL                               = 513,
    RBAC_PERM_COMMAND_MOVEGENS                               = 514,
    RBAC_PERM_COMMAND_MUTE                                   = 515,
    RBAC_PERM_COMMAND_NEARGRAVE                              = 516,
    RBAC_PERM_COMMAND_PINFO                                  = 517,
    RBAC_PERM_COMMAND_PLAYALL                                = 518,
    RBAC_PERM_COMMAND_POSSESS                                = 519,
    RBAC_PERM_COMMAND_RECALL                                 = 520,
    RBAC_PERM_COMMAND_REPAIRITEMS                            = 521,
    RBAC_PERM_COMMAND_RESPAWN                                = 522,
    RBAC_PERM_COMMAND_REVIVE                                 = 523,
    RBAC_PERM_COMMAND_SAVE                                   = 524,
    RBAC_PERM_COMMAND_SAVEALL                                = 525,
    RBAC_PERM_COMMAND_SETSKILL                               = 526,
    RBAC_PERM_COMMAND_SHOWAREA                               = 527,
    RBAC_PERM_COMMAND_SUMMON                                 = 528,
    RBAC_PERM_COMMAND_UNAURA                                 = 529,
    RBAC_PERM_COMMAND_UNBINDSIGHT                            = 530,
    RBAC_PERM_COMMAND_UNFREEZE                               = 531,
    RBAC_PERM_COMMAND_UNMUTE                                 = 532,
    RBAC_PERM_COMMAND_UNPOSSESS                              = 533,
    RBAC_PERM_COMMAND_UNSTUCK                                = 534,
    RBAC_PERM_COMMAND_WCHANGE                                = 535,
    RBAC_PERM_COMMAND_MMAP                                   = 536,
    RBAC_PERM_COMMAND_MMAP_LOADEDTILES                       = 537,
    RBAC_PERM_COMMAND_MMAP_LOC                               = 538,
    RBAC_PERM_COMMAND_MMAP_PATH                              = 539,
    RBAC_PERM_COMMAND_MMAP_STATS                             = 540,
    RBAC_PERM_COMMAND_MMAP_TESTAREA                          = 541,
    RBAC_PERM_COMMAND_MORPH                                  = 542,
    RBAC_PERM_COMMAND_DEMORPH                                = 543,
    RBAC_PERM_COMMAND_MODIFY                                 = 544,
    RBAC_PERM_COMMAND_MODIFY_ARENAPOINTS                     = 545,
    RBAC_PERM_COMMAND_MODIFY_BIT                             = 546,
    RBAC_PERM_COMMAND_MODIFY_DRUNK                           = 547,
    RBAC_PERM_COMMAND_MODIFY_ENERGY                          = 548,
    RBAC_PERM_COMMAND_MODIFY_FACTION                         = 549,
    RBAC_PERM_COMMAND_MODIFY_GENDER                          = 550,
    RBAC_PERM_COMMAND_MODIFY_HONOR                           = 551,
    RBAC_PERM_COMMAND_MODIFY_HP                              = 552,
    RBAC_PERM_COMMAND_MODIFY_MANA                            = 553,
    RBAC_PERM_COMMAND_MODIFY_MONEY                           = 554,
    RBAC_PERM_COMMAND_MODIFY_MOUNT                           = 555,
    RBAC_PERM_COMMAND_MODIFY_PHASE                           = 556,
    RBAC_PERM_COMMAND_MODIFY_RAGE                            = 557,
    RBAC_PERM_COMMAND_MODIFY_REPUTATION                      = 558,
    RBAC_PERM_COMMAND_MODIFY_RUNICPOWER                      = 559,
    RBAC_PERM_COMMAND_MODIFY_SCALE                           = 560,
    RBAC_PERM_COMMAND_MODIFY_SPEED                           = 561,
    RBAC_PERM_COMMAND_MODIFY_SPEED_ALL                       = 562,
    RBAC_PERM_COMMAND_MODIFY_SPEED_BACKWALK                  = 563,
    RBAC_PERM_COMMAND_MODIFY_SPEED_FLY                       = 564,
    RBAC_PERM_COMMAND_MODIFY_SPEED_WALK                      = 565,
    RBAC_PERM_COMMAND_MODIFY_SPEED_SWIM                      = 566,
    RBAC_PERM_COMMAND_MODIFY_SPELL                           = 567,
    RBAC_PERM_COMMAND_MODIFY_STANDSTATE                      = 568,
    RBAC_PERM_COMMAND_MODIFY_TALENTPOINTS                    = 569,
    RBAC_PERM_COMMAND_NPC                                    = 570,
    RBAC_PERM_COMMAND_NPC_ADD                                = 571,
    RBAC_PERM_COMMAND_NPC_ADD_FORMATION                      = 572,
    RBAC_PERM_COMMAND_NPC_ADD_ITEM                           = 573,
    RBAC_PERM_COMMAND_NPC_ADD_MOVE                           = 574,
    RBAC_PERM_COMMAND_NPC_ADD_TEMP                           = 575,
    RBAC_PERM_COMMAND_NPC_DELETE                             = 576,
    RBAC_PERM_COMMAND_NPC_DELETE_ITEM                        = 577,
    RBAC_PERM_COMMAND_NPC_FOLLOW                             = 578,
    RBAC_PERM_COMMAND_NPC_FOLLOW_STOP                        = 579,
    RBAC_PERM_COMMAND_NPC_SET                                = 580,
    RBAC_PERM_COMMAND_NPC_SET_ALLOWMOVE                      = 581,
    RBAC_PERM_COMMAND_NPC_SET_ENTRY                          = 582,
    RBAC_PERM_COMMAND_NPC_SET_FACTIONID                      = 583,
    RBAC_PERM_COMMAND_NPC_SET_FLAG                           = 584,
    RBAC_PERM_COMMAND_NPC_SET_LEVEL                          = 585,
    RBAC_PERM_COMMAND_NPC_SET_LINK                           = 586,
    RBAC_PERM_COMMAND_NPC_SET_MODEL                          = 587,
    RBAC_PERM_COMMAND_NPC_SET_MOVETYPE                       = 588,
    RBAC_PERM_COMMAND_NPC_SET_PHASE                          = 589,
    RBAC_PERM_COMMAND_NPC_SET_SPAWNDIST                      = 590,
    RBAC_PERM_COMMAND_NPC_SET_SPAWNTIME                      = 591,
    RBAC_PERM_COMMAND_NPC_SET_DATA                           = 592,
    RBAC_PERM_COMMAND_NPC_INFO                               = 593,
    RBAC_PERM_COMMAND_NPC_NEAR                               = 594,
    RBAC_PERM_COMMAND_NPC_MOVE                               = 595,
    RBAC_PERM_COMMAND_NPC_PLAYEMOTE                          = 596,
    RBAC_PERM_COMMAND_NPC_SAY                                = 597,
    RBAC_PERM_COMMAND_NPC_TEXTEMOTE                          = 598,
    RBAC_PERM_COMMAND_NPC_WHISPER                            = 599,
    RBAC_PERM_COMMAND_NPC_YELL                               = 600,
    RBAC_PERM_COMMAND_NPC_TAME                               = 601,
    RBAC_PERM_COMMAND_QUEST                                  = 602,
    RBAC_PERM_COMMAND_QUEST_ADD                              = 603,
    RBAC_PERM_COMMAND_QUEST_COMPLETE                         = 604,
    RBAC_PERM_COMMAND_QUEST_REMOVE                           = 605,
    RBAC_PERM_COMMAND_QUEST_REWARD                           = 606,
    RBAC_PERM_COMMAND_RELOAD                                 = 607,
    RBAC_PERM_COMMAND_RELOAD_ACCESS_REQUIREMENT              = 608,
    RBAC_PERM_COMMAND_RELOAD_ACHIEVEMENT_CRITERIA_DATA       = 609,
    RBAC_PERM_COMMAND_RELOAD_ACHIEVEMENT_REWARD              = 610,
    RBAC_PERM_COMMAND_RELOAD_ALL                             = 611,
    RBAC_PERM_COMMAND_RELOAD_ALL_ACHIEVEMENT                 = 612,
    RBAC_PERM_COMMAND_RELOAD_ALL_AREA                        = 613,
    RBAC_PERM_COMMAND_RELOAD_ALL_EVENTAI                     = 614,
    RBAC_PERM_COMMAND_RELOAD_ALL_GOSSIP                      = 615,
    RBAC_PERM_COMMAND_RELOAD_ALL_ITEM                        = 616,
    RBAC_PERM_COMMAND_RELOAD_ALL_LOCALES                     = 617,
    RBAC_PERM_COMMAND_RELOAD_ALL_LOOT                        = 618,
    RBAC_PERM_COMMAND_RELOAD_ALL_NPC                         = 619,
    RBAC_PERM_COMMAND_RELOAD_ALL_QUEST                       = 620,
    RBAC_PERM_COMMAND_RELOAD_ALL_SCRIPTS                     = 621,
    RBAC_PERM_COMMAND_RELOAD_ALL_SPELL                       = 622,
    RBAC_PERM_COMMAND_RELOAD_AREATRIGGER_INVOLVEDRELATION    = 623,
    RBAC_PERM_COMMAND_RELOAD_AREATRIGGER_TAVERN              = 624,
    RBAC_PERM_COMMAND_RELOAD_AREATRIGGER_TELEPORT            = 625,
    RBAC_PERM_COMMAND_RELOAD_AUCTIONS                        = 626,
    RBAC_PERM_COMMAND_RELOAD_AUTOBROADCAST                   = 627,
    RBAC_PERM_COMMAND_RELOAD_COMMAND                         = 628,
    RBAC_PERM_COMMAND_RELOAD_CONDITIONS                      = 629,
    RBAC_PERM_COMMAND_RELOAD_CONFIG                          = 630,
    RBAC_PERM_COMMAND_RELOAD_CREATURE_AI_SCRIPTS             = 631,
    RBAC_PERM_COMMAND_RELOAD_CREATURE_AI_TEXTS               = 632,
    RBAC_PERM_COMMAND_RELOAD_CREATURE_LINKED_RESPAWN         = 633,
    RBAC_PERM_COMMAND_RELOAD_CREATURE_LOOT_TEMPLATE          = 634,
    RBAC_PERM_COMMAND_RELOAD_CREATURE_ONKILL_REPUTATION      = 635,
    RBAC_PERM_COMMAND_RELOAD_CREATURE_QUESTENDER             = 636,
    RBAC_PERM_COMMAND_RELOAD_CREATURE_QUESTSTARTER           = 637,
    RBAC_PERM_COMMAND_RELOAD_CREATURE_SUMMON_GROUPS          = 638,
    RBAC_PERM_COMMAND_RELOAD_CREATURE_TEMPLATE               = 639,
    RBAC_PERM_COMMAND_RELOAD_CREATURE_TEXT                   = 640,
    RBAC_PERM_COMMAND_RELOAD_DISABLES                        = 641,
    RBAC_PERM_COMMAND_RELOAD_DISENCHANT_LOOT_TEMPLATE        = 642,
    RBAC_PERM_COMMAND_RELOAD_EVENT_SCRIPTS                   = 643,
    RBAC_PERM_COMMAND_RELOAD_FISHING_LOOT_TEMPLATE           = 644,
    RBAC_PERM_COMMAND_RELOAD_GAME_GRAVEYARD_ZONE             = 645,
    RBAC_PERM_COMMAND_RELOAD_GAMEOBJECT_QUESTENDER           = 646,
    RBAC_PERM_COMMAND_RELOAD_GAMEOBJECT_QUEST_LOOT_TEMPLATE  = 647,
    RBAC_PERM_COMMAND_RELOAD_GAMEOBJECT_QUESTSTARTER         = 648,
    RBAC_PERM_COMMAND_RELOAD_GAME_TELE                       = 649,
    RBAC_PERM_COMMAND_RELOAD_GM_TICKETS                      = 650,
    RBAC_PERM_COMMAND_RELOAD_GOSSIP_MENU                     = 651,
    RBAC_PERM_COMMAND_RELOAD_GOSSIP_MENU_OPTION              = 652,
    RBAC_PERM_COMMAND_RELOAD_ITEM_ENCHANTMENT_TEMPLATE       = 653,
    RBAC_PERM_COMMAND_RELOAD_ITEM_LOOT_TEMPLATE              = 654,
    RBAC_PERM_COMMAND_RELOAD_ITEM_SET_NAMES                  = 655,
    RBAC_PERM_COMMAND_RELOAD_LFG_DUNGEON_REWARDS             = 656,
    RBAC_PERM_COMMAND_RELOAD_LOCALES_ACHIEVEMENT_REWARD      = 657,
    RBAC_PERM_COMMAND_RELOAD_LOCALES_CRETURE                 = 658,
    RBAC_PERM_COMMAND_RELOAD_LOCALES_CRETURE_TEXT            = 659,
    RBAC_PERM_COMMAND_RELOAD_LOCALES_GAMEOBJECT              = 660,
    RBAC_PERM_COMMAND_RELOAD_LOCALES_GOSSIP_MENU_OPTION      = 661,
    RBAC_PERM_COMMAND_RELOAD_LOCALES_ITEM                    = 662,
    RBAC_PERM_COMMAND_RELOAD_LOCALES_ITEM_SET_NAME           = 663,
    RBAC_PERM_COMMAND_RELOAD_LOCALES_NPC_TEXT                = 664,
    RBAC_PERM_COMMAND_RELOAD_LOCALES_PAGE_TEXT               = 665,
    RBAC_PERM_COMMAND_RELOAD_LOCALES_POINTS_OF_INTEREST      = 666,
    RBAC_PERM_COMMAND_RELOAD_LOCALES_QUEST                   = 667,
    RBAC_PERM_COMMAND_RELOAD_MAIL_LEVEL_REWARD               = 668,
    RBAC_PERM_COMMAND_RELOAD_MAIL_LOOT_TEMPLATE              = 669,
    RBAC_PERM_COMMAND_RELOAD_MILLING_LOOT_TEMPLATE           = 670,
    RBAC_PERM_COMMAND_RELOAD_NPC_SPELLCLICK_SPELLS           = 671,
    RBAC_PERM_COMMAND_RELOAD_NPC_TRAINER                     = 672,
    RBAC_PERM_COMMAND_RELOAD_NPC_VENDOR                      = 673,
    RBAC_PERM_COMMAND_RELOAD_PAGE_TEXT                       = 674,
    RBAC_PERM_COMMAND_RELOAD_PICKPOCKETING_LOOT_TEMPLATE     = 675,
    RBAC_PERM_COMMAND_RELOAD_POINTS_OF_INTEREST              = 676,
    RBAC_PERM_COMMAND_RELOAD_PROSPECTING_LOOT_TEMPLATE       = 677,
    RBAC_PERM_COMMAND_RELOAD_QUEST_POI                       = 678,
    RBAC_PERM_COMMAND_RELOAD_QUEST_TEMPLATE                  = 679,
    RBAC_PERM_COMMAND_RELOAD_RBAC                            = 680,
    RBAC_PERM_COMMAND_RELOAD_REFERENCE_LOOT_TEMPLATE         = 681,
    RBAC_PERM_COMMAND_RELOAD_REPUTATION_REWARD_RATE          = 682,
    RBAC_PERM_COMMAND_RELOAD_RESERVED_NAME                   = 683,
    RBAC_PERM_COMMAND_RELOAD_SKILL_DISCOVERY_TEMPLATE        = 684,
    RBAC_PERM_COMMAND_RELOAD_SKILL_EXTRA_ITEM_TEMPLATE       = 685,
    RBAC_PERM_COMMAND_RELOAD_SKILL_FISHING_BASE_LEVEL        = 686,
    RBAC_PERM_COMMAND_RELOAD_SKINNING_LOOT_TEMPLATE          = 687,
    RBAC_PERM_COMMAND_RELOAD_SMART_SCRIPTS                   = 688,
    RBAC_PERM_COMMAND_RELOAD_SPELL_AREA                      = 689,
    RBAC_PERM_COMMAND_RELOAD_SPELL_BONUS_DATA                = 690,
    RBAC_PERM_COMMAND_RELOAD_SPELL_GROUP                     = 691,
    RBAC_PERM_COMMAND_RELOAD_SPELL_GROUP_STACK_RULES         = 692,
    RBAC_PERM_COMMAND_RELOAD_SPELL_LEARN_SPELL               = 693,
    RBAC_PERM_COMMAND_RELOAD_SPELL_LINKED_SPELL              = 694,
    RBAC_PERM_COMMAND_RELOAD_SPELL_LOOT_TEMPLATE             = 695,
    RBAC_PERM_COMMAND_RELOAD_SPELL_PET_AURAS                 = 696,
    RBAC_PERM_COMMAND_RELOAD_SPELL_PROC                      = 697,
    RBAC_PERM_COMMAND_RELOAD_SPELL_PROC_EVENT                = 698,
    RBAC_PERM_COMMAND_RELOAD_SPELL_REQUIRED                  = 699,
    RBAC_PERM_COMMAND_RELOAD_SPELL_SCRIPTS                   = 700,
    RBAC_PERM_COMMAND_RELOAD_SPELL_TARGET_POSITION           = 701,
    RBAC_PERM_COMMAND_RELOAD_SPELL_THREATS                   = 702,
    RBAC_PERM_COMMAND_RELOAD_SPILLOVER_TEMPLATE              = 703,
    RBAC_PERM_COMMAND_RELOAD_TRINITY_STRING                  = 704,
    RBAC_PERM_COMMAND_RELOAD_VEHICLE_ACCESORY                = 705,
    RBAC_PERM_COMMAND_RELOAD_VEHICLE_TEMPLATE_ACCESSORY      = 706,
    RBAC_PERM_COMMAND_RELOAD_WARDEN_ACTION                   = 707,
    RBAC_PERM_COMMAND_RELOAD_WAYPOINT_DATA                   = 708,
    RBAC_PERM_COMMAND_RELOAD_WAYPOINT_SCRIPTS                = 709,
    RBAC_PERM_COMMAND_RESET                                  = 710,
    RBAC_PERM_COMMAND_RESET_ACHIEVEMENTS                     = 711,
    RBAC_PERM_COMMAND_RESET_HONOR                            = 712,
    RBAC_PERM_COMMAND_RESET_LEVEL                            = 713,
    RBAC_PERM_COMMAND_RESET_SPELLS                           = 714,
    RBAC_PERM_COMMAND_RESET_STATS                            = 715,
    RBAC_PERM_COMMAND_RESET_TALENTS                          = 716,
    RBAC_PERM_COMMAND_RESET_ALL                              = 717,
    RBAC_PERM_COMMAND_SERVER                                 = 718,
    RBAC_PERM_COMMAND_SERVER_CORPSES                         = 719,
    RBAC_PERM_COMMAND_SERVER_EXIT                            = 720,
    RBAC_PERM_COMMAND_SERVER_IDLERESTART                     = 721,
    RBAC_PERM_COMMAND_SERVER_IDLERESTART_CANCEL              = 722,
    RBAC_PERM_COMMAND_SERVER_IDLESHUTDOWN                    = 723,
    RBAC_PERM_COMMAND_SERVER_IDLESHUTDOWN_CANCEL             = 724,
    RBAC_PERM_COMMAND_SERVER_INFO                            = 725,
    RBAC_PERM_COMMAND_SERVER_PLIMIT                          = 726,
    RBAC_PERM_COMMAND_SERVER_RESTART                         = 727,
    RBAC_PERM_COMMAND_SERVER_RESTART_CANCEL                  = 728,
    RBAC_PERM_COMMAND_SERVER_SET                             = 729,
    RBAC_PERM_COMMAND_SERVER_SET_CLOSED                      = 730,
    RBAC_PERM_COMMAND_SERVER_SET_DIFFTIME                    = 731,
    RBAC_PERM_COMMAND_SERVER_SET_LOGLEVEL                    = 732,
    RBAC_PERM_COMMAND_SERVER_SET_MOTD                        = 733,
    RBAC_PERM_COMMAND_SERVER_SHUTDOWN                        = 734,
    RBAC_PERM_COMMAND_SERVER_SHUTDOWN_CANCEL                 = 735,
    RBAC_PERM_COMMAND_SERVER_MOTD                            = 736,
    RBAC_PERM_COMMAND_TELE                                   = 737,
    RBAC_PERM_COMMAND_TELE_ADD                               = 738,
    RBAC_PERM_COMMAND_TELE_DEL                               = 739,
    RBAC_PERM_COMMAND_TELE_NAME                              = 740,
    RBAC_PERM_COMMAND_TELE_GROUP                             = 741,
    RBAC_PERM_COMMAND_TICKET                                 = 742,
    RBAC_PERM_COMMAND_TICKET_ASSIGN                          = 743,
    RBAC_PERM_COMMAND_TICKET_CLOSE                           = 744,
    RBAC_PERM_COMMAND_TICKET_CLOSEDLIST                      = 745,
    RBAC_PERM_COMMAND_TICKET_COMMENT                         = 746,
    RBAC_PERM_COMMAND_TICKET_COMPLETE                        = 747,
    RBAC_PERM_COMMAND_TICKET_DELETE                          = 748,
    RBAC_PERM_COMMAND_TICKET_ESCALATE                        = 749,
    RBAC_PERM_COMMAND_TICKET_ESCALATEDLIST                   = 750,
    RBAC_PERM_COMMAND_TICKET_LIST                            = 751,
    RBAC_PERM_COMMAND_TICKET_ONLINELIST                      = 752,
    RBAC_PERM_COMMAND_TICKET_RESET                           = 753,
    RBAC_PERM_COMMAND_TICKET_RESPONSE                        = 754,
    RBAC_PERM_COMMAND_TICKET_RESPONSE_APPEND                 = 755,
    RBAC_PERM_COMMAND_TICKET_RESPONSE_APPENDLN               = 756,
    RBAC_PERM_COMMAND_TICKET_TOGGLESYSTEM                    = 757,
    RBAC_PERM_COMMAND_TICKET_UNASSIGN                        = 758,
    RBAC_PERM_COMMAND_TICKET_VIEWID                          = 759,
    RBAC_PERM_COMMAND_TICKET_VIEWNAME                        = 760,
    RBAC_PERM_COMMAND_TITLES                                 = 761,
    RBAC_PERM_COMMAND_TITLES_ADD                             = 762,
    RBAC_PERM_COMMAND_TITLES_CURRENT                         = 763,
    RBAC_PERM_COMMAND_TITLES_REMOVE                          = 764,
    RBAC_PERM_COMMAND_TITLES_SET                             = 765,
    RBAC_PERM_COMMAND_TITLES_SET_MASK                        = 766,
    RBAC_PERM_COMMAND_WP                                     = 767,
    RBAC_PERM_COMMAND_WP_ADD                                 = 768,
    RBAC_PERM_COMMAND_WP_EVENT                               = 769,
    RBAC_PERM_COMMAND_WP_LOAD                                = 770,
    RBAC_PERM_COMMAND_WP_MODIFY                              = 771,
    RBAC_PERM_COMMAND_WP_UNLOAD                              = 772,
    RBAC_PERM_COMMAND_WP_RELOAD                              = 773,
    RBAC_PERM_COMMAND_WP_SHOW                                = 774,
    RBAC_PERM_COMMAND_MODIFY_CURRENCY                        = 775, // only 4.3.4
    RBAC_PERM_COMMAND_DEBUG_PHASE                            = 776, // Only 4.3.4

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

}

#endif
