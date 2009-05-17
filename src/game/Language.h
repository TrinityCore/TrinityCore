/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __TRINITY_LANGUAGE_H
#define __TRINITY_LANGUAGE_H

enum TrinityStrings
{
    // for chat commands
    LANG_SELECT_CHAR_OR_CREATURE        = 1,
    LANG_SELECT_CREATURE                = 2,

    // level 0 chat
    LANG_SYSTEMMESSAGE                  = 3,
    LANG_EVENTMESSAGE                   = 4,
    LANG_NO_HELP_CMD                    = 5,
    LANG_NO_CMD                         = 6,
    LANG_NO_SUBCMD                      = 7,
    LANG_SUBCMDS_LIST                   = 8,
    LANG_AVIABLE_CMD                    = 9,
    LANG_CMD_SYNTAX                     = 10,
    LANG_ACCOUNT_LEVEL                  = 11,
    LANG_CONNECTED_USERS                = 12,
    LANG_UPTIME                         = 13,
    LANG_PLAYER_SAVED                   = 14,
    LANG_PLAYERS_SAVED                  = 15,
    LANG_GMS_ON_SRV                     = 16,
    LANG_GMS_NOT_LOGGED                 = 17,
    LANG_YOU_IN_FLIGHT                  = 18,
    //LANG_YOU_IN_BATTLEGROUND            = 19, not used
    //LANG_TARGET_IN_FLIGHT               = 20, not used
    LANG_CHAR_IN_FLIGHT                 = 21,
    LANG_CHAR_NON_MOUNTED               = 22,
    LANG_YOU_IN_COMBAT                  = 23,
    LANG_YOU_USED_IT_RECENTLY           = 24,
    LANG_COMMAND_NOTCHANGEPASSWORD      = 25,
    LANG_COMMAND_PASSWORD               = 26,
    LANG_COMMAND_WRONGOLDPASSWORD       = 27,
    LANG_COMMAND_ACCLOCKLOCKED          = 28,
    LANG_COMMAND_ACCLOCKUNLOCKED        = 29,
    LANG_SPELL_RANK                     = 30,
    LANG_KNOWN                          = 31,
    LANG_LEARN                          = 32,
    LANG_PASSIVE                        = 33,
    LANG_TALENT                         = 34,
    LANG_ACTIVE                         = 35,
    LANG_COMPLETE                       = 36,
    LANG_OFFLINE                        = 37,
    LANG_ON                             = 38,
    LANG_OFF                            = 39,
    LANG_YOU_ARE                        = 40,
    LANG_VISIBLE                        = 41,
    LANG_INVISIBLE                      = 42,
    LANG_DONE                           = 43,
    LANG_YOU                            = 44,
    LANG_UNKNOWN                        = 45,
    LANG_ERROR                          = 46,
    LANG_NON_EXIST_CHARACTER            = 47,
    LANG_FRIEND_IGNORE_UNKNOWN          = 48,
    LANG_LEVEL_MINREQUIRED              = 49,
    LANG_LEVEL_MINREQUIRED_AND_ITEM     = 50,
    LANG_NPC_TAINER_HELLO               = 51,
    LANG_COMMAND_INVALID_ITEM_COUNT     = 52,
    LANG_COMMAND_MAIL_ITEMS_LIMIT       = 53,
    LANG_NEW_PASSWORDS_NOT_MATCH        = 54,
    LANG_PASSWORD_TOO_LONG              = 55,
    LANG_MOTD_CURRENT                   = 56,
    LANG_USING_WORLD_DB                 = 57,
    LANG_USING_SCRIPT_LIB               = 58,
    LANG_USING_EVENT_AI                 = 59,
    // Room for more level 0              60-99 not used

    // level 1 chat
    LANG_GLOBAL_NOTIFY                  = 100,
    LANG_MAP_POSITION                   = 101,
    LANG_IS_TELEPORTED                  = 102,
    LANG_CANNOT_SUMMON_TO_INST          = 103,
    LANG_CANNOT_GO_TO_INST_PARTY        = 104,
    LANG_CANNOT_GO_TO_INST_GM           = 105,
    LANG_CANNOT_GO_INST_INST            = 106,
    LANG_CANNOT_SUMMON_INST_INST        = 107,
    LANG_SUMMONING                      = 108,
    LANG_SUMMONED_BY                    = 109,
    LANG_TELEPORTING_TO                 = 110,
    LANG_TELEPORTED_TO_BY               = 111,
    LANG_NO_PLAYER                      = 112,
    LANG_APPEARING_AT                   = 113,
    LANG_APPEARING_TO                   = 114,
    LANG_BAD_VALUE                      = 115,
    LANG_NO_CHAR_SELECTED               = 116,
    LANG_NOT_IN_GROUP                   = 117,

    LANG_YOU_CHANGE_HP                  = 118,
    LANG_YOURS_HP_CHANGED               = 119,
    LANG_YOU_CHANGE_MANA                = 120,
    LANG_YOURS_MANA_CHANGED             = 121,
    LANG_YOU_CHANGE_ENERGY              = 122,
    LANG_YOURS_ENERGY_CHANGED           = 123,

    LANG_CURRENT_ENERGY                 = 124,              //log
    LANG_YOU_CHANGE_RAGE                = 125,
    LANG_YOURS_RAGE_CHANGED             = 126,
    LANG_YOU_CHANGE_LVL                 = 127,
    LANG_CURRENT_FACTION                = 128,
    LANG_WRONG_FACTION                  = 129,
    LANG_YOU_CHANGE_FACTION             = 130,
    LANG_YOU_CHANGE_SPELLFLATID         = 131,
    LANG_YOURS_SPELLFLATID_CHANGED      = 132,
    LANG_YOU_GIVE_TAXIS                 = 133,
    LANG_YOU_REMOVE_TAXIS               = 134,
    LANG_YOURS_TAXIS_ADDED              = 135,
    LANG_YOURS_TAXIS_REMOVED            = 136,

    LANG_YOU_CHANGE_ASPEED              = 137,
    LANG_YOURS_ASPEED_CHANGED           = 138,
    LANG_YOU_CHANGE_SPEED               = 139,
    LANG_YOURS_SPEED_CHANGED            = 140,
    LANG_YOU_CHANGE_SWIM_SPEED          = 141,
    LANG_YOURS_SWIM_SPEED_CHANGED       = 142,
    LANG_YOU_CHANGE_BACK_SPEED          = 143,
    LANG_YOURS_BACK_SPEED_CHANGED       = 144,
    LANG_YOU_CHANGE_FLY_SPEED           = 145,
    LANG_YOURS_FLY_SPEED_CHANGED        = 146,

    LANG_YOU_CHANGE_SIZE                = 147,
    LANG_YOURS_SIZE_CHANGED             = 148,
    LANG_NO_MOUNT                       = 149,
    LANG_YOU_GIVE_MOUNT                 = 150,
    LANG_MOUNT_GIVED                    = 151,

    LANG_CURRENT_MONEY                  = 152,
    LANG_YOU_TAKE_ALL_MONEY             = 153,
    LANG_YOURS_ALL_MONEY_GONE           = 154,
    LANG_YOU_TAKE_MONEY                 = 155,
    LANG_YOURS_MONEY_TAKEN              = 156,
    LANG_YOU_GIVE_MONEY                 = 157,
    LANG_YOURS_MONEY_GIVEN              = 158,
    LANG_YOU_HEAR_SOUND                 = 159,

    LANG_NEW_MONEY                      = 160,              // Log

    LANG_REMOVE_BIT                     = 161,
    LANG_SET_BIT                        = 162,
    LANG_COMMAND_TELE_TABLEEMPTY        = 163,
    LANG_COMMAND_TELE_NOTFOUND          = 164,
    LANG_COMMAND_TELE_PARAMETER         = 165,
    LANG_COMMAND_TELE_NOLOCATION        = 166,
    //                                    167               // not used
    LANG_COMMAND_TELE_LOCATION          = 168,

    LANG_MAIL_SENT                      = 169,
    LANG_SOUND_NOT_EXIST                = 170,
    LANG_CANT_TELEPORT_SELF             = 171,
    LANG_CONSOLE_COMMAND                = 172,
    LANG_YOU_CHANGE_RUNIC_POWER         = 173,
    LANG_YOURS_RUNIC_POWER_CHANGED      = 174,
    LANG_LIQUID_STATUS                  = 175,
    // Room for more level 1              176-199 not used

    // level 2 chat
    LANG_NO_SELECTION                   = 200,
    LANG_OBJECT_GUID                    = 201,
    LANG_TOO_LONG_NAME                  = 202,
    LANG_CHARS_ONLY                     = 203,
    LANG_TOO_LONG_SUBNAME               = 204,
    LANG_NOT_IMPLEMENTED                = 205,

    LANG_ITEM_ADDED_TO_LIST             = 206,
    LANG_ITEM_NOT_FOUND                 = 207,
    LANG_ITEM_DELETED_FROM_LIST         = 208,
    LANG_ITEM_NOT_IN_LIST               = 209,
    LANG_ITEM_ALREADY_IN_LIST           = 210,

    LANG_RESET_SPELLS_ONLINE            = 211,
    LANG_RESET_SPELLS_OFFLINE           = 212,
    LANG_RESET_TALENTS_ONLINE           = 213,
    LANG_RESET_TALENTS_OFFLINE          = 214,
    LANG_RESET_SPELLS                   = 215,
    LANG_RESET_TALENTS                  = 216,

    LANG_RESETALL_UNKNOWN_CASE          = 217,
    LANG_RESETALL_SPELLS                = 218,
    LANG_RESETALL_TALENTS               = 219,

    LANG_WAYPOINT_NOTFOUND              = 220,
    LANG_WAYPOINT_NOTFOUNDLAST          = 221,
    LANG_WAYPOINT_NOTFOUNDSEARCH        = 222,
    LANG_WAYPOINT_NOTFOUNDDBPROBLEM     = 223,
    LANG_WAYPOINT_CREATSELECTED         = 224,
    LANG_WAYPOINT_CREATNOTFOUND         = 225,
    LANG_WAYPOINT_VP_SELECT             = 226,
    LANG_WAYPOINT_VP_NOTFOUND           = 227,
    LANG_WAYPOINT_VP_NOTCREATED         = 228,
    LANG_WAYPOINT_VP_ALLREMOVED         = 229,
    LANG_WAYPOINT_NOTCREATED            = 230,
    LANG_WAYPOINT_NOGUID                = 231,
    LANG_WAYPOINT_NOWAYPOINTGIVEN       = 232,
    LANG_WAYPOINT_ARGUMENTREQ           = 233,
    LANG_WAYPOINT_ADDED                 = 234,
    LANG_WAYPOINT_ADDED_NO              = 235,
    LANG_WAYPOINT_CHANGED               = 236,
    LANG_WAYPOINT_CHANGED_NO            = 237,
    LANG_WAYPOINT_EXPORTED              = 238,
    LANG_WAYPOINT_NOTHINGTOEXPORT       = 239,
    LANG_WAYPOINT_IMPORTED              = 240,
    LANG_WAYPOINT_REMOVED               = 241,
    LANG_WAYPOINT_NOTREMOVED            = 242,
    LANG_WAYPOINT_TOOFAR1               = 243,
    LANG_WAYPOINT_TOOFAR2               = 244,
    LANG_WAYPOINT_TOOFAR3               = 245,
    LANG_WAYPOINT_INFO_TITLE            = 246,
    LANG_WAYPOINT_INFO_WAITTIME         = 247,
    LANG_WAYPOINT_INFO_MODEL            = 248,
    LANG_WAYPOINT_INFO_EMOTE            = 249,
    LANG_WAYPOINT_INFO_SPELL            = 250,
    LANG_WAYPOINT_INFO_TEXT             = 251,
    LANG_WAYPOINT_INFO_AISCRIPT         = 252,

    LANG_RENAME_PLAYER                  = 253,
    LANG_RENAME_PLAYER_GUID             = 254,

    LANG_WAYPOINT_WPCREATNOTFOUND       = 255,
    LANG_WAYPOINT_NPCNOTFOUND           = 256,

    LANG_MOVE_TYPE_SET                  = 257,
    LANG_MOVE_TYPE_SET_NODEL            = 258,
    LANG_USE_BOL                        = 259,
    LANG_VALUE_SAVED                    = 260,
    LANG_VALUE_SAVED_REJOIN             = 261,

    LANG_COMMAND_GOAREATRNOTFOUND       = 262,
    LANG_INVALID_TARGET_COORD           = 263,
    LANG_INVALID_ZONE_COORD             = 264,
    LANG_INVALID_ZONE_MAP               = 265,
    LANG_COMMAND_TARGETOBJNOTFOUND      = 266,
    LANG_COMMAND_GOOBJNOTFOUND          = 267,
    LANG_COMMAND_GOCREATNOTFOUND        = 268,
    LANG_COMMAND_GOCREATMULTIPLE        = 269,
    LANG_COMMAND_DELCREATMESSAGE        = 270,
    LANG_COMMAND_CREATUREMOVED          = 271,
    LANG_COMMAND_CREATUREATSAMEMAP      = 272,
    LANG_COMMAND_OBJNOTFOUND            = 273,
    LANG_COMMAND_DELOBJREFERCREATURE    = 274,
    LANG_COMMAND_DELOBJMESSAGE          = 275,
    LANG_COMMAND_TURNOBJMESSAGE         = 276,
    LANG_COMMAND_MOVEOBJMESSAGE         = 277,
    LANG_COMMAND_VENDORSELECTION        = 278,
    LANG_COMMAND_NEEDITEMSEND           = 279,
    LANG_COMMAND_ADDVENDORITEMITEMS     = 280,
    LANG_COMMAND_KICKSELF               = 281,
    LANG_COMMAND_KICKMESSAGE            = 282,
    //                                    283, not used
    LANG_COMMAND_WHISPERACCEPTING       = 284,
    LANG_COMMAND_WHISPERON              = 285,
    LANG_COMMAND_WHISPEROFF             = 286,
    LANG_COMMAND_CREATGUIDNOTFOUND      = 287,
      // TICKET STRINGS NEED REWRITE // 288-296 FREE

      // END
    LANG_COMMAND_SPAWNDIST              = 297,
    LANG_COMMAND_SPAWNTIME              = 298,
    LANG_COMMAND_MODIFY_HONOR           = 299,

    LANG_YOUR_CHAT_DISABLED             = 300,
    LANG_YOU_DISABLE_CHAT               = 301,
    LANG_CHAT_ALREADY_ENABLED           = 302,
    LANG_YOUR_CHAT_ENABLED              = 303,
    LANG_YOU_ENABLE_CHAT                = 304,

    LANG_COMMAND_MODIFY_REP             = 305,
    LANG_COMMAND_MODIFY_ARENA           = 306,
    LANG_COMMAND_FACTION_NOTFOUND       = 307,
    LANG_COMMAND_FACTION_UNKNOWN        = 308,
    LANG_COMMAND_FACTION_INVPARAM       = 309,
    LANG_COMMAND_FACTION_DELTA          = 310,
    LANG_FACTION_LIST                   = 311,
    LANG_FACTION_VISIBLE                = 312,
    LANG_FACTION_ATWAR                  = 313,
    LANG_FACTION_PEACE_FORCED           = 314,
    LANG_FACTION_HIDDEN                 = 315,
    LANG_FACTION_INVISIBLE_FORCED       = 316,
    LANG_FACTION_INACTIVE               = 317,
    LANG_REP_HATED                      = 318,
    LANG_REP_HOSTILE                    = 319,
    LANG_REP_UNFRIENDLY                 = 320,
    LANG_REP_NEUTRAL                    = 321,
    LANG_REP_FRIENDLY                   = 322,
    LANG_REP_HONORED                    = 323,
    LANG_REP_REVERED                    = 324,
    LANG_REP_EXALTED                    = 325,
    LANG_COMMAND_FACTION_NOREP_ERROR    = 326,
    LANG_FACTION_NOREPUTATION           = 327,
    LANG_LOOKUP_PLAYER_ACCOUNT          = 328,
    LANG_LOOKUP_PLAYER_CHARACTER        = 329,
    LANG_NO_PLAYERS_FOUND               = 330,
    LANG_EXTENDED_COST_NOT_EXIST        = 331,
    LANG_GM_ON                          = 332,
    LANG_GM_OFF                         = 333,
    LANG_GM_CHAT_ON                     = 334,
    LANG_GM_CHAT_OFF                    = 335,
    LANG_YOU_REPAIR_ITEMS               = 336,
    LANG_YOUR_ITEMS_REPAIRED            = 337,
    LANG_YOU_SET_WATERWALK              = 338,
    LANG_YOUR_WATERWALK_SET             = 339,
    LANG_CREATURE_FOLLOW_YOU_NOW        = 340,
    LANG_CREATURE_NOT_FOLLOW_YOU        = 341,
    LANG_CREATURE_NOT_FOLLOW_YOU_NOW    = 342,
    LANG_CREATURE_NON_TAMEABLE          = 343,
    LANG_YOU_ALREADY_HAVE_PET           = 344,
    LANG_CUSTOMIZE_PLAYER               = 345,
    LANG_CUSTOMIZE_PLAYER_GUID          = 346,
    LANG_COMMAND_GOTAXINODENOTFOUND     = 347,
    // Room for more level 2              348-399 not used

    // level 3 chat
    LANG_SCRIPTS_RELOADED               = 400,
    LANG_YOU_CHANGE_SECURITY            = 401,
    LANG_YOURS_SECURITY_CHANGED         = 402,
    LANG_YOURS_SECURITY_IS_LOW          = 403,
    LANG_CREATURE_MOVE_DISABLED         = 404,
    LANG_CREATURE_MOVE_ENABLED          = 405,
    LANG_NO_WEATHER                     = 406,
    LANG_WEATHER_DISABLED               = 407,

    LANG_BAN_YOUBANNED                  = 408,
    LANG_BAN_YOUPERMBANNED              = 409,
    LANG_BAN_NOTFOUND                   = 410,

    LANG_UNBAN_UNBANNED                 = 411,
    LANG_UNBAN_ERROR                    = 412,

    LANG_ACCOUNT_NOT_EXIST              = 413,

    LANG_BANINFO_NOCHARACTER            = 414,
    LANG_BANINFO_NOIP                   = 415,
    LANG_BANINFO_NOACCOUNTBAN           = 416,
    LANG_BANINFO_BANHISTORY             = 417,
    LANG_BANINFO_HISTORYENTRY           = 418,
    LANG_BANINFO_INFINITE               = 419,
    LANG_BANINFO_NEVER                  = 420,
    LANG_BANINFO_YES                    = 421,
    LANG_BANINFO_NO                     = 422,
    LANG_BANINFO_IPENTRY                = 423,

    LANG_BANLIST_NOIP                   = 424,
    LANG_BANLIST_NOACCOUNT              = 425,
    LANG_BANLIST_NOCHARACTER            = 426,
    LANG_BANLIST_MATCHINGIP             = 427,
    LANG_BANLIST_MATCHINGACCOUNT        = 428,

    LANG_COMMAND_LEARN_MANY_SPELLS      = 429,
    LANG_COMMAND_LEARN_CLASS_SPELLS     = 430,
    LANG_COMMAND_LEARN_CLASS_TALENTS    = 431,
    LANG_COMMAND_LEARN_ALL_LANG         = 432,
    LANG_COMMAND_LEARN_ALL_CRAFT        = 433,
    LANG_COMMAND_COULDNOTFIND           = 434,
    LANG_COMMAND_ITEMIDINVALID          = 435,
    LANG_COMMAND_NOITEMFOUND            = 436,
    LANG_COMMAND_LISTOBJINVALIDID       = 437,
    LANG_COMMAND_LISTITEMMESSAGE        = 438,
    LANG_COMMAND_LISTOBJMESSAGE         = 439,
    LANG_COMMAND_INVALIDCREATUREID      = 440,
    LANG_COMMAND_LISTCREATUREMESSAGE    = 441,
    LANG_COMMAND_NOAREAFOUND            = 442,
    LANG_COMMAND_NOITEMSETFOUND         = 443,
    LANG_COMMAND_NOSKILLFOUND           = 444,
    LANG_COMMAND_NOSPELLFOUND           = 445,
    LANG_COMMAND_NOQUESTFOUND           = 446,
    LANG_COMMAND_NOCREATUREFOUND        = 447,
    LANG_COMMAND_NOGAMEOBJECTFOUND      = 448,
    LANG_COMMAND_GRAVEYARDNOEXIST       = 449,
    LANG_COMMAND_GRAVEYARDALRLINKED     = 450,
    LANG_COMMAND_GRAVEYARDLINKED        = 451,
    LANG_COMMAND_GRAVEYARDWRONGZONE     = 452,
    //                                  = 453,
    LANG_COMMAND_GRAVEYARDERROR         = 454,
    LANG_COMMAND_GRAVEYARD_NOTEAM       = 455,
    LANG_COMMAND_GRAVEYARD_ANY          = 456,
    LANG_COMMAND_GRAVEYARD_ALLIANCE     = 457,
    LANG_COMMAND_GRAVEYARD_HORDE        = 458,
    LANG_COMMAND_GRAVEYARDNEAREST       = 459,
    LANG_COMMAND_ZONENOGRAVEYARDS       = 460,
    LANG_COMMAND_ZONENOGRAFACTION       = 461,
    LANG_COMMAND_TP_ALREADYEXIST        = 462,
    LANG_COMMAND_TP_ADDED               = 463,
    LANG_COMMAND_TP_ADDEDERR            = 464,
    LANG_COMMAND_TP_DELETED             = 465,
    LANG_COMMAND_NOTAXINODEFOUND        = 466,
    LANG_COMMAND_TARGET_LISTAURAS       = 467,
    LANG_COMMAND_TARGET_AURADETAIL      = 468,
    LANG_COMMAND_TARGET_LISTAURATYPE    = 469,
    LANG_COMMAND_TARGET_AURASIMPLE      = 470,

    LANG_COMMAND_QUEST_NOTFOUND         = 471,
    LANG_COMMAND_QUEST_STARTFROMITEM    = 472,
    LANG_COMMAND_QUEST_REMOVED          = 473,
    LANG_COMMAND_QUEST_REWARDED         = 474,
    LANG_COMMAND_QUEST_COMPLETE         = 475,
    LANG_COMMAND_QUEST_ACTIVE           = 476,

    LANG_COMMAND_FLYMODE_STATUS         = 477,

    LANG_COMMAND_OPCODESENT             = 478,

    LANG_COMMAND_IMPORT_SUCCESS         = 479,
    LANG_COMMAND_IMPORT_FAILED          = 480,
    LANG_COMMAND_EXPORT_SUCCESS         = 481,
    LANG_COMMAND_EXPORT_FAILED          = 482,

    LANG_COMMAND_SPELL_BROKEN           = 483,

    LANG_SET_SKILL                      = 484,
    LANG_SET_SKILL_ERROR                = 485,

    LANG_INVALID_SKILL_ID               = 486,
    LANG_LEARNING_GM_SKILLS             = 487,
    LANG_YOU_KNOWN_SPELL                = 488,
    LANG_TARGET_KNOWN_SPELL             = 489,
    LANG_UNKNOWN_SPELL                  = 490,
    LANG_FORGET_SPELL                   = 491,
    LANG_REMOVEALL_COOLDOWN             = 492,
    LANG_REMOVE_COOLDOWN                = 493,

    LANG_ADDITEM                        = 494,              //log
    LANG_ADDITEMSET                     = 495,              //log
    LANG_REMOVEITEM                     = 496,
    LANG_ITEM_CANNOT_CREATE             = 497,
    LANG_INSERT_GUILD_NAME              = 498,
    LANG_PLAYER_NOT_FOUND               = 499,
    LANG_PLAYER_IN_GUILD                = 500,
    LANG_GUILD_NOT_CREATED              = 501,
    LANG_NO_ITEMS_FROM_ITEMSET_FOUND    = 502,

    LANG_DISTANCE                       = 503,

    LANG_ITEM_SLOT                      = 504,
    LANG_ITEM_SLOT_NOT_EXIST            = 505,
    LANG_ITEM_ADDED_TO_SLOT             = 506,
    LANG_ITEM_SAVE_FAILED               = 507,
    LANG_ITEMLIST_SLOT                  = 508,
    LANG_ITEMLIST_MAIL                  = 509,
    LANG_ITEMLIST_AUCTION               = 510,

    LANG_WRONG_LINK_TYPE                = 511,
    LANG_ITEM_LIST_CHAT                 = 512,
    LANG_QUEST_LIST_CHAT                = 513,
    LANG_CREATURE_ENTRY_LIST_CHAT       = 514,
    LANG_CREATURE_LIST_CHAT             = 515,
    LANG_GO_ENTRY_LIST_CHAT             = 516,
    LANG_GO_LIST_CHAT                   = 517,
    LANG_ITEMSET_LIST_CHAT              = 518,
    LANG_TELE_LIST                      = 519,
    LANG_SPELL_LIST                     = 520,
    LANG_SKILL_LIST_CHAT                = 521,

    LANG_GAMEOBJECT_NOT_EXIST           = 522,

    LANG_GAMEOBJECT_CURRENT             = 523,              //log
    LANG_GAMEOBJECT_DETAIL              = 524,
    LANG_GAMEOBJECT_ADD                 = 525,

    LANG_MOVEGENS_LIST                  = 526,
    LANG_MOVEGENS_IDLE                  = 527,
    LANG_MOVEGENS_RANDOM                = 528,
    LANG_MOVEGENS_WAYPOINT              = 529,
    LANG_MOVEGENS_ANIMAL_RANDOM         = 530,
    LANG_MOVEGENS_CONFUSED              = 531,
    LANG_MOVEGENS_TARGETED_PLAYER       = 532,
    LANG_MOVEGENS_TARGETED_CREATURE     = 533,
    LANG_MOVEGENS_TARGETED_NULL         = 534,
    LANG_MOVEGENS_HOME_CREATURE         = 535,
    LANG_MOVEGENS_HOME_PLAYER           = 536,
    LANG_MOVEGENS_FLIGHT                = 537,
    LANG_MOVEGENS_UNKNOWN               = 538,

    LANG_NPCINFO_CHAR                   = 539,
    LANG_NPCINFO_LEVEL                  = 540,
    LANG_NPCINFO_HEALTH                 = 541,
    LANG_NPCINFO_FLAGS                  = 542,
    LANG_NPCINFO_LOOT                   = 543,
    LANG_NPCINFO_POSITION               = 544,
    LANG_NPCINFO_VENDOR                 = 545,
    LANG_NPCINFO_TRAINER                = 546,
    LANG_NPCINFO_DUNGEON_ID             = 547,

    LANG_PINFO_ACCOUNT                  = 548,
    LANG_PINFO_LEVEL                    = 549,
    LANG_PINFO_NO_REP                   = 550,

    LANG_YOU_SET_EXPLORE_ALL            = 551,
    LANG_YOU_SET_EXPLORE_NOTHING        = 552,
    LANG_YOURS_EXPLORE_SET_ALL          = 553,
    LANG_YOURS_EXPLORE_SET_NOTHING      = 554,

    LANG_HOVER_ENABLED                  = 555,
    LANG_HOVER_DISABLED                 = 556,
    LANG_YOURS_LEVEL_UP                 = 557,
    LANG_YOURS_LEVEL_DOWN               = 558,
    LANG_YOURS_LEVEL_PROGRESS_RESET     = 559,
    LANG_EXPLORE_AREA                   = 560,
    LANG_UNEXPLORE_AREA                 = 561,

    LANG_UPDATE                         = 562,
    LANG_UPDATE_CHANGE                  = 563,
    LANG_TOO_BIG_INDEX                  = 564,
    LANG_SET_UINT                       = 565,              //log
    LANG_SET_UINT_FIELD                 = 566,
    LANG_SET_FLOAT                      = 567,              //log
    LANG_SET_FLOAT_FIELD                = 568,
    LANG_GET_UINT                       = 569,              //log
    LANG_GET_UINT_FIELD                 = 570,
    LANG_GET_FLOAT                      = 571,              //log
    LANG_GET_FLOAT_FIELD                = 572,
    LANG_SET_32BIT                      = 573,              //log
    LANG_SET_32BIT_FIELD                = 574,
    LANG_CHANGE_32BIT                   = 575,              //log
    LANG_CHANGE_32BIT_FIELD             = 576,

    LANG_INVISIBLE_INVISIBLE              = 577,
    LANG_INVISIBLE_VISIBLE                = 578,
    LANG_SELECTED_TARGET_NOT_HAVE_VICTIM  = 579,

    LANG_COMMAND_LEARN_ALL_DEFAULT_AND_QUEST = 580,
    LANG_COMMAND_NEAROBJMESSAGE         = 581,
    LANG_COMMAND_RAWPAWNTIMES           = 582,

    LANG_EVENT_ENTRY_LIST_CHAT          = 583,
    LANG_NOEVENTFOUND                   = 584,
    LANG_EVENT_NOT_EXIST                = 585,
    LANG_EVENT_INFO                     = 586,
    LANG_EVENT_ALREADY_ACTIVE           = 587,
    LANG_EVENT_NOT_ACTIVE               = 588,

    LANG_MOVEGENS_POINT                 = 589,
    LANG_MOVEGENS_FEAR                  = 590,
    LANG_MOVEGENS_DISTRACT              = 591,

    LANG_COMMAND_LEARN_ALL_RECIPES      = 592,
    LANG_BANLIST_ACCOUNTS               = 593,
    LANG_BANLIST_ACCOUNTS_HEADER        = 594,
    LANG_BANLIST_IPS                    = 595,
    LANG_BANLIST_IPS_HEADER             = 596,
    LANG_GMLIST                         = 597,
    LANG_GMLIST_HEADER                  = 598,
    LANG_GMLIST_EMPTY                   = 599,
    // End Level 3 list, continued at 1100

    // Battleground
    LANG_BG_A_WINS                      = 600,
    LANG_BG_H_WINS                      = 601,

    LANG_BG_WS_START_TWO_MINUTES        = 753,
    LANG_BG_WS_START_ONE_MINUTE         = 602,
    LANG_BG_WS_START_HALF_MINUTE        = 603,
    LANG_BG_WS_HAS_BEGUN                = 604,

    LANG_BG_WS_CAPTURED_HF              = 605,
    LANG_BG_WS_CAPTURED_AF              = 606,
    LANG_BG_WS_DROPPED_HF               = 607,
    LANG_BG_WS_DROPPED_AF               = 608,
    LANG_BG_WS_RETURNED_AF              = 609,
    LANG_BG_WS_RETURNED_HF              = 610,
    LANG_BG_WS_PICKEDUP_HF              = 611,
    LANG_BG_WS_PICKEDUP_AF              = 612,
    LANG_BG_WS_F_PLACED                 = 613,
    LANG_BG_WS_ALLIANCE_FLAG_RESPAWNED  = 614,
    LANG_BG_WS_HORDE_FLAG_RESPAWNED     = 615,

    LANG_BG_EY_START_TWO_MINUTES        = 755,
    LANG_BG_EY_START_ONE_MINUTE         = 636,
    LANG_BG_EY_START_HALF_MINUTE        = 637,
    LANG_BG_EY_HAS_BEGUN                = 638,

    LANG_BG_AB_ALLY                     = 650,
    LANG_BG_AB_HORDE                    = 651,
    LANG_BG_AB_NODE_STABLES             = 652,
    LANG_BG_AB_NODE_BLACKSMITH          = 653,
    LANG_BG_AB_NODE_FARM                = 654,
    LANG_BG_AB_NODE_LUMBER_MILL         = 655,
    LANG_BG_AB_NODE_GOLD_MINE           = 656,
    LANG_BG_AB_NODE_TAKEN               = 657,
    LANG_BG_AB_NODE_DEFENDED            = 658,
    LANG_BG_AB_NODE_ASSAULTED           = 659,
    LANG_BG_AB_NODE_CLAIMED             = 660,

    LANG_BG_AB_START_TWO_MINUTES        = 754,
    LANG_BG_AB_START_ONE_MINUTE         = 661,
    LANG_BG_AB_START_HALF_MINUTE        = 662,
    LANG_BG_AB_HAS_BEGUN                = 663,
    LANG_BG_AB_A_NEAR_VICTORY           = 664,
    LANG_BG_AB_H_NEAR_VICTORY           = 665,
    LANG_BG_MARK_BY_MAIL                = 666,

    LANG_BG_EY_HAS_TAKEN_A_M_TOWER      = 667,
    LANG_BG_EY_HAS_TAKEN_H_M_TOWER      = 668,
    LANG_BG_EY_HAS_TAKEN_A_D_RUINS      = 669,
    LANG_BG_EY_HAS_TAKEN_H_D_RUINS      = 670,
    LANG_BG_EY_HAS_TAKEN_A_B_TOWER      = 671,
    LANG_BG_EY_HAS_TAKEN_H_B_TOWER      = 672,
    LANG_BG_EY_HAS_TAKEN_A_F_RUINS      = 673,
    LANG_BG_EY_HAS_TAKEN_H_F_RUINS      = 674,
    LANG_BG_EY_HAS_LOST_A_M_TOWER       = 675,
    LANG_BG_EY_HAS_LOST_H_M_TOWER       = 676,
    LANG_BG_EY_HAS_LOST_A_D_RUINS       = 677,
    LANG_BG_EY_HAS_LOST_H_D_RUINS       = 678,
    LANG_BG_EY_HAS_LOST_A_B_TOWER       = 679,
    LANG_BG_EY_HAS_LOST_H_B_TOWER       = 680,
    LANG_BG_EY_HAS_LOST_A_F_RUINS       = 681,
    LANG_BG_EY_HAS_LOST_H_F_RUINS       = 682,
    LANG_BG_EY_HAS_TAKEN_FLAG           = 683,
    LANG_BG_EY_CAPTURED_FLAG_A          = 684,
    LANG_BG_EY_CAPTURED_FLAG_H          = 685,
    LANG_BG_EY_DROPPED_FLAG             = 686,
    LANG_BG_EY_RESETED_FLAG             = 687,

    LANG_ARENA_ONE_TOOLOW               = 700,
    LANG_ARENA_ONE_MINUTE               = 701,
    LANG_ARENA_THIRTY_SECONDS           = 702,
    LANG_ARENA_FIFTEEN_SECONDS          = 703,
    LANG_ARENA_HAS_BEGUN                = 704,

    LANG_WAIT_BEFORE_SPEAKING           = 705,
    LANG_NOT_EQUIPPED_ITEM              = 706,
    LANG_PLAYER_DND                     = 707,
    LANG_PLAYER_AFK                     = 708,
    LANG_PLAYER_DND_DEFAULT             = 709,
    LANG_PLAYER_AFK_DEFAULT             = 710,

    LANG_BG_QUEUE_ANNOUNCE_SELF         = 711,
    LANG_BG_QUEUE_ANNOUNCE_WORLD        = 712,
    LANG_YOUR_ARENA_LEVEL_REQ_ERROR     = 713,
//                                      = 714, not used
    LANG_YOUR_BG_LEVEL_REQ_ERROR        = 715,
//                                      = 716, not used
    LANG_BG_STARTED_ANNOUNCE_WORLD      = 717,
    LANG_ARENA_QUEUE_ANNOUNCE_WORLD_JOIN= 718,
    LANG_ARENA_QUEUE_ANNOUNCE_WORLD_EXIT= 719,

    LANG_BG_GROUP_TOO_LARGE             = 720,              // "Your group is too large for this battleground. Please regroup to join."
    LANG_ARENA_GROUP_TOO_LARGE          = 721,              // "Your group is too large for this arena. Please regroup to join."
    LANG_ARENA_YOUR_TEAM_ONLY           = 722,              // "Your group has members not in your arena team. Please regroup to join."
    LANG_ARENA_NOT_ENOUGH_PLAYERS       = 723,              // "Your group does not have enough players to join this match."
    LANG_ARENA_GOLD_WINS                = 724,              // "The Gold Team wins!"
    LANG_ARENA_GREEN_WINS               = 725,              // "The Green Team wins!"
//                                      = 726, not used
    LANG_BG_GROUP_OFFLINE_MEMBER        = 727,              // "Your group has an offline member. Please remove him before joining."
    LANG_BG_GROUP_MIXED_FACTION         = 728,              // "Your group has players from the opposing faction. You can't join the battleground as a group."
    LANG_BG_GROUP_MIXED_LEVELS          = 729,              // "Your group has players from different battleground brakets. You can't join as group."
    LANG_BG_GROUP_MEMBER_ALREADY_IN_QUEUE = 730,            // "Someone in your party is already in this battleground queue. (S)he must leave it before joining as group."
    LANG_BG_GROUP_MEMBER_DESERTER       = 731,              // "Someone in your party is Deserter. You can't join as group."
    LANG_BG_GROUP_MEMBER_NO_FREE_QUEUE_SLOTS = 732,         // "Someone in your party is already in three battleground queues. You cannot join as group."

    LANG_CANNOT_TELE_TO_BG              = 733,              // "You cannot teleport to a battleground or arena map."
    LANG_CANNOT_SUMMON_TO_BG            = 734,              // "You cannot summon players to a battleground or arena map."
    LANG_CANNOT_GO_TO_BG_GM             = 735,              // "You must be in GM mode to teleport to a player in a battleground."
    LANG_CANNOT_GO_TO_BG_FROM_BG        = 736,              // "You cannot teleport to a battleground from another battleground. Please leave the current battleground first."
    LANG_DEBUG_ARENA_ON                 = 737,
    LANG_DEBUG_ARENA_OFF                = 738,
    LANG_DEBUG_BG_ON                    = 739,
    LANG_DEBUG_BG_OFF                   = 740,
    LANG_DIST_ARENA_POINTS_START        = 741,
    LANG_DIST_ARENA_POINTS_ONLINE_START = 742,
    LANG_DIST_ARENA_POINTS_ONLINE_END   = 743,
    LANG_DIST_ARENA_POINTS_TEAM_START   = 744,
    LANG_DIST_ARENA_POINTS_TEAM_END     = 745,
    LANG_DIST_ARENA_POINTS_END          = 746,
//                                      = 747, not used
//                                      = 748, not used
//                                      = 749, not used
    LANG_BATTLEGROUND_PREMATURE_FINISH_WARNING = 750,       // "Not enough players. This game will close in %u mins."
    LANG_BATTLEGROUND_PREMATURE_FINISH_WARNING_SECS = 751,  // "Not enough players. This game will close in %u seconds."
//                                      = 752, not used
//  LANG_BG_WS_START_TWO_MINUTES        = 753, - defined above
//  LANG_BG_AB_START_TWO_MINUTES        = 754, - defined above
//  LANG_BG_EY_START_TWO_MINUTES        = 755, - defined above
    // Room for batleground/arena strings 756-799 not used

    // Room for BG/ARENA                  751-769 not used
    LANG_ARENA_TESTING                  = 785,
    LANG_AUTO_ANN                       = 786,
    LANG_ANNOUNCE_COLOR                 = 787,

    // in game strings
    LANG_PET_INVALID_NAME               = 800,
    LANG_NOT_ENOUGH_GOLD                = 801,
    LANG_NOT_FREE_TRADE_SLOTS           = 802,
    LANG_NOT_PARTNER_FREE_TRADE_SLOTS   = 803,
    LANG_YOU_NOT_HAVE_PERMISSION        = 804,
    LANG_UNKNOWN_LANGUAGE               = 805,
    LANG_NOT_LEARNED_LANGUAGE           = 806,
    LANG_NEED_CHARACTER_NAME            = 807,
    LANG_PLAYER_NOT_EXIST_OR_OFFLINE    = 808,
    LANG_ACCOUNT_FOR_PLAYER_NOT_FOUND   = 809,
    LANG_ACHIEVEMENT_EARNED             = 810,
    LANG_GUILD_MASTER                   = 811,
    LANG_GUILD_OFFICER                  = 812,
    LANG_GUILD_VETERAN                  = 813,
    LANG_GUILD_MEMBER                   = 814,
    LANG_GUILD_INITIATE                 = 815,
    // Room for in-game strings           816-999 not used

    // Level 4 (CLI only commands)
    LANG_COMMAND_EXIT                   = 1000,
    LANG_ACCOUNT_DELETED                = 1001,
    LANG_ACCOUNT_NOT_DELETED_SQL_ERROR  = 1002,
    LANG_ACCOUNT_NOT_DELETED            = 1003,
    LANG_ACCOUNT_CREATED                = 1004,
    LANG_ACCOUNT_TOO_LONG               = 1005,
    LANG_ACCOUNT_ALREADY_EXIST          = 1006,
    LANG_ACCOUNT_NOT_CREATED_SQL_ERROR  = 1007,
    LANG_ACCOUNT_NOT_CREATED            = 1008,
    LANG_CHARACTER_DELETED              = 1009,
    LANG_ACCOUNT_LIST_HEADER            = 1010,
    LANG_ACCOUNT_LIST_ERROR             = 1011,
    LANG_ACCOUNT_LIST_BAR               = 1012,
    LANG_ACCOUNT_LIST_LINE              = 1013,
    LANG_ACCOUNT_LIST_EMPTY             = 1014,
    // Room for more level 4              1015-1099 not used

    // Level 3 (continue)
    LANG_ACCOUNT_SETADDON               = 1100,
    LANG_MOTD_NEW                       = 1101,
    LANG_SENDMESSAGE                    = 1102,
    LANG_EVENT_ENTRY_LIST_CONSOLE       = 1103,
    LANG_CREATURE_ENTRY_LIST_CONSOLE    = 1104,
    LANG_ITEM_LIST_CONSOLE              = 1105,
    LANG_ITEMSET_LIST_CONSOLE           = 1106,
    LANG_GO_ENTRY_LIST_CONSOLE          = 1107,
    LANG_QUEST_LIST_CONSOLE             = 1108,
    LANG_SKILL_LIST_CONSOLE             = 1109,
    LANG_CREATURE_LIST_CONSOLE          = 1110,
    LANG_GO_LIST_CONSOLE                = 1111,
    LANG_FILE_OPEN_FAIL                 = 1112,
    LANG_ACCOUNT_CHARACTER_LIST_FULL    = 1113,
    LANG_DUMP_BROKEN                    = 1114,
    LANG_INVALID_CHARACTER_NAME         = 1115,
    LANG_INVALID_CHARACTER_GUID         = 1116,
    LANG_CHARACTER_GUID_IN_USE          = 1117,
    LANG_ITEMLIST_GUILD                 = 1118,
    LANG_MUST_MALE_OR_FEMALE            = 1119,
    LANG_YOU_CHANGE_GENDER              = 1120,
    LANG_YOUR_GENDER_CHANGED            = 1121,
    LANG_SKILL_VALUES                   = 1122,
    LANG_NO_PET_FOUND                   = 1123,
    LANG_WRONG_PET_TYPE                 = 1124,
    LANG_COMMAND_LEARN_PET_TALENTS      = 1125,
    LANG_RESET_PET_TALENTS              = 1126,
    LANG_RESET_PET_TALENTS_ONLINE       = 1127,
    LANG_TAXINODE_ENTRY_LIST_CHAT       = 1128,
    LANG_TAXINODE_ENTRY_LIST_CONSOLE    = 1129,
    // Room for more level 3              1130-1199 not used

    // Debug commands
    LANG_CINEMATIC_NOT_EXIST            = 1200,
    LANG_MOVIE_NOT_EXIST                = 1201,
    // Room for more debug                1202-1299 not used

    // FREE IDS                           1300-9999

    // AV
    LANG_BG_AV_ALLY                     = 1300,
    LANG_BG_AV_HORDE                    = 1301,
    LANG_BG_AV_TOWER_TAKEN              = 1302,
    LANG_BG_AV_TOWER_ASSAULTED          = 1303,
    LANG_BG_AV_TOWER_DEFENDED           = 1304,
    LANG_BG_AV_GRAVE_TAKEN              = 1305,
    LANG_BG_AV_GRAVE_DEFENDED           = 1306,
    LANG_BG_AV_GRAVE_ASSAULTED          = 1307,

    LANG_BG_AV_MINE_TAKEN               = 1308,
    LANG_BG_AV_MINE_NORTH               = 1309,
    LANG_BG_AV_MINE_SOUTH               = 1310,

    LANG_BG_AV_NODE_GRAVE_STORM_AID     = 1311,
    LANG_BG_AV_NODE_TOWER_DUN_S         = 1312,
    LANG_BG_AV_NODE_TOWER_DUN_N         = 1313,
    LANG_BG_AV_NODE_GRAVE_STORMPIKE     = 1314,
    LANG_BG_AV_NODE_TOWER_ICEWING       = 1315,
    LANG_BG_AV_NODE_GRAVE_STONE         = 1316,
    LANG_BG_AV_NODE_TOWER_STONE         = 1317,
    LANG_BG_AV_NODE_GRAVE_SNOW          = 1318,
    LANG_BG_AV_NODE_TOWER_ICE           = 1319,
    LANG_BG_AV_NODE_GRAVE_ICE           = 1320,
    LANG_BG_AV_NODE_TOWER_POINT         = 1321,
    LANG_BG_AV_NODE_GRAVE_FROST         = 1322,
    LANG_BG_AV_NODE_TOWER_FROST_E       = 1323,
    LANG_BG_AV_NODE_TOWER_FROST_W       = 1324,
    LANG_BG_AV_NODE_GRAVE_FROST_HUT     = 1325,

    LANG_BG_AV_ONEMINTOSTART            = 1326,
    LANG_BG_AV_HALFMINTOSTART           = 1327,
    LANG_BG_AV_STARTED                  = 1328,
    LANG_BG_AV_A_NEAR_LOSE              = 1329,
    LANG_BG_AV_H_NEAR_LOSE              = 1330,
    LANG_BG_AV_H_CAPTAIN_DEAD           = 1331,
    LANG_BG_AV_A_CAPTAIN_DEAD           = 1332,
    // FREE IDS                           1333-1999

    // Ticket Strings 2000-2029
    LANG_COMMAND_TICKETNEW              = 2000,
    LANG_COMMAND_TICKETUPDATED          = 2001,
    LANG_COMMAND_TICKETPLAYERABANDON    = 2002,
    LANG_COMMAND_TICKETCLOSED           = 2003,
    LANG_COMMAND_TICKETDELETED          = 2004,
    LANG_COMMAND_TICKETNOTEXIST         = 2005,
    LANG_COMMAND_TICKETCLOSEFIRST       = 2006,
    LANG_COMMAND_TICKETALREADYASSIGNED  = 2007,
    LANG_COMMAND_TICKETRELOAD           = 2008,
    LANG_COMMAND_TICKETSHOWLIST         = 2009,
    LANG_COMMAND_TICKETSHOWONLINELIST   = 2010,
    LANG_COMMAND_TICKETSHOWCLOSEDLIST   = 2011,
    LANG_COMMAND_TICKETASSIGNERROR_A    = 2012,
    LANG_COMMAND_TICKETASSIGNERROR_B    = 2013,
    LANG_COMMAND_TICKETNOTASSIGNED      = 2014,
    LANG_COMMAND_TICKETUNASSIGNSECURITY = 2015,
    LANG_COMMAND_TICKETCANNOTCLOSE      = 2016,
    LANG_COMMAND_TICKETLISTGUID         = 2017,
    LANG_COMMAND_TICKETLISTNAME         = 2018,
    LANG_COMMAND_TICKETLISTAGE          = 2019,
    LANG_COMMAND_TICKETLISTASSIGNEDTO   = 2020,
    LANG_COMMAND_TICKETLISTUNASSIGNED   = 2021,
    LANG_COMMAND_TICKETLISTMESSAGE      = 2022,
    LANG_COMMAND_TICKETLISTCOMMENT      = 2023,
    LANG_COMMAND_TICKETLISTADDCOMMENT   = 2024,
    LANG_COMMAND_TICKETLISTAGECREATE    = 2025,

    // Trinity strings                    5000-9999
    LANG_COMMAND_FREEZE                 = 5000,
    LANG_COMMAND_FREEZE_ERROR           = 5001,
    LANG_COMMAND_FREEZE_WRONG           = 5002,
    LANG_COMMAND_UNFREEZE               = 5003,
    LANG_COMMAND_NO_FROZEN_PLAYERS      = 5004,
    LANG_COMMAND_LIST_FREEZE            = 5005,
    LANG_COMMAND_FROZEN_PLAYERS         = 5006,
    LANG_INSTANCE_RAID_GROUP_ONLY       = 5007,
    //LANG_INSTANCE_NOT_AS_GHOST        = 5008,
    LANG_COMMAND_PLAYED_TO_ALL          = 5009,
    LANG_NPCINFO_LINKGUID               = 5010,
    LANG_TELEPORTED_TO_BY_CONSOLE       = 5011,
    // Room for more Trinity strings      5012-9999
    // Used for GM Announcements
    LANG_GM_BROADCAST                    = 6613,
    LANG_GM_NOTIFY                       = 6614,
    LANG_GM_ANNOUNCE_COLOR               = 6615,
    LANG_RESETALL_PET_SPELLS             = 6616,

    LANG_WORLD_CLOSED                    = 7523,
    LANG_WORLD_OPENED                    = 7524,


    // Use for not-in-offcial-sources patches
    //                                    10000-10999
    // opvp hp
    LANG_OPVP_HP_CAPTURE_OVERLOOK_H     = 10001,
    LANG_OPVP_HP_CAPTURE_OVERLOOK_A     = 10002,
    LANG_OPVP_HP_CAPTURE_STADIUM_H      = 10003,
    LANG_OPVP_HP_CAPTURE_STADIUM_A      = 10004,
    LANG_OPVP_HP_CAPTURE_BROKENHILL_H   = 10005,
    LANG_OPVP_HP_CAPTURE_BROKENHILL_A   = 10006,
    LANG_OPVP_HP_LOOSE_OVERLOOK_H       = 10007,
    LANG_OPVP_HP_LOOSE_OVERLOOK_A       = 10008,
    LANG_OPVP_HP_LOOSE_STADIUM_H        = 10009,
    LANG_OPVP_HP_LOOSE_STADIUM_A        = 10010,
    LANG_OPVP_HP_LOOSE_BROKENHILL_H     = 10011,
    LANG_OPVP_HP_LOOSE_BROKENHILL_A     = 10012,
    // opvp zm
    LANG_OPVP_ZM_CAPTURE_WEST_H         = 10013,
    LANG_OPVP_ZM_CAPTURE_WEST_A         = 10014,
    LANG_OPVP_ZM_CAPTURE_EAST_H         = 10015,
    LANG_OPVP_ZM_CAPTURE_EAST_A         = 10016,
    LANG_OPVP_ZM_CAPTURE_GY_H           = 10017,
    LANG_OPVP_ZM_CAPTURE_GY_A           = 10018,
    LANG_OPVP_ZM_LOOSE_WEST_H           = 10019,
    LANG_OPVP_ZM_LOOSE_WEST_A           = 10020,
    LANG_OPVP_ZM_LOOSE_EAST_H           = 10021,
    LANG_OPVP_ZM_LOOSE_EAST_A           = 10022,
    LANG_OPVP_ZM_LOOSE_GY_H             = 10023,
    LANG_OPVP_ZM_LOOSE_GY_A             = 10024,
    // opvp na
    LANG_OPVP_NA_CAPTURE_H              = 10025,
    LANG_OPVP_NA_CAPTURE_A              = 10026,
    LANG_OPVP_NA_LOOSE_H                = 10027,
    LANG_OPVP_NA_LOOSE_A                = 10028,
    // opvp tf
    LANG_OPVP_TF_CAPTURE_H              = 10029,
    LANG_OPVP_TF_CAPTURE_A              = 10030,
    LANG_OPVP_TF_LOOSE_H                = 10031,
    LANG_OPVP_TF_LOOSE_A                = 10032,
    // opvp ep
    LANG_OPVP_EP_CAPTURE_NPT_H          = 10033,
    LANG_OPVP_EP_CAPTURE_NPT_A          = 10034,
    LANG_OPVP_EP_CAPTURE_EWT_H          = 10035,
    LANG_OPVP_EP_CAPTURE_EWT_A          = 10036,
    LANG_OPVP_EP_CAPTURE_CGT_H          = 10037,
    LANG_OPVP_EP_CAPTURE_CGT_A          = 10038,
    LANG_OPVP_EP_CAPTURE_PWT_H          = 10039,
    LANG_OPVP_EP_CAPTURE_PWT_A          = 10040,
    LANG_OPVP_EP_LOOSE_NPT_H            = 10041,
    LANG_OPVP_EP_LOOSE_NPT_A            = 10042,
    LANG_OPVP_EP_LOOSE_EWT_H            = 10043,
    LANG_OPVP_EP_LOOSE_EWT_A            = 10044,
    LANG_OPVP_EP_LOOSE_CGT_H            = 10045,
    LANG_OPVP_EP_LOOSE_CGT_A            = 10046,
    LANG_OPVP_EP_LOOSE_PWT_H            = 10047,
    LANG_OPVP_EP_LOOSE_PWT_A            = 10048,
    // opvp si
    LANG_OPVP_SI_CAPTURE_H              = 10049,
    LANG_OPVP_SI_CAPTURE_A              = 10050,
    // opvp gossips
    LANG_OPVP_EP_FLIGHT_NPT             = 10051,
    LANG_OPVP_EP_FLIGHT_EWT             = 10052,
    LANG_OPVP_EP_FLIGHT_CGT             = 10053,
    LANG_OPVP_ZM_GOSSIP_ALLIANCE        = 10054,
    LANG_OPVP_ZM_GOSSIP_HORDE           = 10055,
        
    // Use for custom patches             11000-11999

    // NOT RESERVED IDS                   12000-1999999999
    // `db_script_string` table index     2000000000-2000009999 (MIN_DB_SCRIPT_STRING_ID-MAX_DB_SCRIPT_STRING_ID)
    // For other tables maybe             2000010000-2147483647 (max index)
};
#endif

