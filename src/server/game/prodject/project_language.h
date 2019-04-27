#ifndef PROJECT_LANGUAGE_H
#define PROJECT_LANGUAGE_H

#include "project.h"

namespace PROJECT
{
    namespace Language
    {
        enum Languages
        {
            FRENCH = 0,
            ENGLISH  = 1,

            MAX,
        };

        extern std::vector<std::map<uint32, char *> > StringsList;

        TC_GAME_API PROJECT::Language::Languages GetLanguageForPlayer(Player * player);
        TC_GAME_API const char * GetLanguageString(uint32 stringId, Languages language);
        TC_GAME_API const char * GetLanguageString(uint32 stringId, Player * player);
        TC_GAME_API const char * GetLanguageString(uint32 stringId, ObjectGuid playerGuid);
        TC_GAME_API const char * GetLanguageName(Languages language);
        void Reload();

        namespace Strings
        {
            enum StringsEnum
            {
                NONE                                      = 0,
                // other
                DELETED                                   = 1,
                SUBJECT                                   = 2,
                MESSAGE                                   = 3,
                DATE                                      = 4,
                CUSTOM_TITLE_STRING                       = 5,
                TARGET_YOURSELF                           = 9,
                PETS_DISABLED                             = 10,
                MUTED                                     = 11,
                NOT_ALLOWED_IN_AREA                       = 12,
                CHANNEL_CHAT_DISABLED                     = 13,
                HEROIC_MODE_UNAVAILABLE                   = 14,
                CANT_COMPLETE_QUEST_ON_THIS_REALM         = 15,
                ACTIVATE_GLOBAL_FIRST                     = 16,
                BANNED_FROM_BATTLEGROUNDS                 = 17,
                GEARSCORE_FOR_PLAYER                      = 18,
                DONE                                      = 20,
                INVALID_CHARACTER                         = 21,
                INVALID_COMMAND                           = 23,
                MUTED_MUST_WAIT                           = 25,
                DEATH_KNIGHT_TUTORIAL_ON_LOGIN            = 26,
                WORGEN_TUTORIAL_ON_LOGIN                  = 27,
                GUILD_ACHIEVEMENT_EARNED                  = 28,
                PLEASE_LOGOUT_REALM_TRANSFER              = 29,
                THIS_IS_NON_ROMANIAN_REALM                = 30,
                GROUP_HAS_INSTANCE_COOLDOWN               = 31,
                INVALID_OR_NOT_ONLINE_CHARACTER           = 32,
                INSTANCE_CDS_ITEM                         = 33,
                INSTANCE_CDS_COUNT                        = 34,
                INSTANCE_SHOWING_CDS_OF                   = 35,
                CANT_GIVE_LEADER_TO_PLAYER_DIFF_CD        = 36,
                NOT_ALLOWED_IN_CHANNEL                    = 37,
                CANT_SUMMON_WHILE_IN_ARENA                = 38,
                ANNIVERSARY_MESSAGE                       = 39,
                CANT_LOCK_ACCOUNT_INGAME                  = 40,
                COD_MESSAGE_WARNING                       = 41,
                CANT_VOID_STORAGE_SHOP_ITEMS_NO_LEVEL_REQ = 42,
                CANT_EQUIP_SHOP_ITEMS_NO_LEVEL_REQ        = 43,
                HK_TITLE_REWARDED                         = 44,
                HK_TITLE_REWARDED_NO_OTHER_TITLE          = 45,
                CANT_SELL_EPIC_DONATED_ITEMS              = 46,
                CANT_DELETE_EPIC_DONATED_ITEMS            = 47,
                CANT_VOID_STORAGE_EPIC_DONATED_ITEMS      = 48,
                CANT_DISENCHANT_EPIC_DONATED_ITEMS        = 49,
                GLOBAL_MESSAGE                            = 50,
                CANT_JOIN_CHANNEL_GLOBAL                  = 51,
                INFO_ABOUT_GLOBAL_CHANNELS                = 52,
                AFK_KICK_REMINDER                         = 53,
                CANT_UNSTUCK_HERE                         = 54,
                NOT_ALLOWED_IN_AREA_NEED_QUEST            = 55,
                CANT_JOIN_ARENA_WHILE_OTHER_ALREADY_ACTIVE= 56,
                DONATION_DUE                              = 57,
                GUILD_MASTER_DETHRONE_NOT_ELIGIBLE        = 58,
                WARDEN_WARNING                            = 59,
                ARENA_SPECTATOR_DEATH_EFFECT              = 60,
                LOOT_COOLDOWNS_PERSONAL_LOOT              = 61,
                LOOT_COOLDOWNS_BONUS_ROLL                 = 62,
                LOOT_OBJECT_ALREADY_BEING_LOOTED          = 63,
                LOOT_COOLDOWNS_PERSONAL_LOOT_FLEX         = 64,
                LOOT_COOLDOWNS_PERSONAL_LOOT_LEGENDARY    = 65,
                LOOT_COOLDOWNS_PERSONAL_LOOT_LEGENDARY_2  = 66,
                CHAT_LINKS_EXTRA_INFO                     = 67,
                CHAT_LINKS_EXTRA_INFO_LAST_COMPLETION     = 68,
                CHAT_LINKS_EXTRA_INFO_NO_LINK             = 69,
                SERVER_RESTART_IMPORTANT                  = 70,

                // PTR
                PTR_FUNCTIONALITY_DISABLED                = 950,

                // staff messages
                STAFF_MESSAGES_UNREAD                     = 1000,
                STAFF_MESSAGES_NO_MESSAGE                 = 1001,
                STAFF_MESSAGES_INVALID_MESSAGE            = 1002,

                // Raid Finder
                RAID_FINDER_AUTOREMOVE_MESSAGE            = 1100,
                RAID_FINDER_RAID_REMOVED_FULL             = 1101,
                RAID_FINDER_CHANGE_LEADER_WHILE_ACTIVE    = 1102,
                RAID_FINDER_CANT_JOIN_GROUP_WHILE_ACTIVE  = 1103,
                RAID_FINDER_CANT_LEAVE_GROUP_WHILE_ACTIVE = 1104,
                RAID_FINDER_CANT_START_RAID_FOR           = 1105,
                RAID_FINDER_CANT_START_RAID_WHILE_IN_MAP  = 1106,
                RAID_FINDER_CANT_CREATE_WITH_GEARSCORE    = 1107,
                RAID_FINDER_AVAILABLE_RAIDS_FOR_YOU       = 1108,
                RAID_FINDER_FOUND_RAIDS                   = 1109,
                RAID_FINDER_CANT_JOIN_NOT_ENOUGH_GS       = 1110,
                RAID_FINDER_RAID_INFO_MESSAGE             = 1111,
                RAID_FINDER_RAID_INFO_ZONE                = 1112,
                RAID_FINDER_RAID_INFO_BOSSES_KILLED       = 1113,
                RAID_FINDER_RAID_INFO_MINIMUM_GEARSCORE   = 1114,
                RAID_FINDER_RAID_INFO_LEADER              = 1115,
                RAID_FINDER_RAID_INFO_MEMBERS             = 1116,
                RAID_FINDER_RAID_INFO_CLASSES             = 1117,
                RAID_FINDER_RAID_INFO_POSSIBLE_ROLES      = 1118,
                RAID_FINDER_RAID_INFO_MEMBERS_UNKNOWN     = 1119,
                RAID_FINDER_YOU_HAVE_CD_FOR_INSTANCE      = 1120,
                RAID_FINDER_YOUR_CD_DIFFERS               = 1121,
                RAID_FINDER_YOU_HAVE_SAME_CD              = 1122,
                RAID_FINDER_JOIN_RAID_COMMAND             = 1123,
                RAID_FINDER_NO_TELEPORT_NOT_ENOUGH_MEMBER = 1124,
                RAID_FINDER_NO_TELEPORT_IN_COMBAT         = 1125,
                RAID_FINDER_CANT_CHANGE_DIFFICULTY        = 1126,
                RAID_FINDER_GENERAL_HELP                  = 1127,
                RAID_FINDER_UNKNOWN_ERROR                 = 1128,
                RAID_FINDER_UNKNOWN_ERROR_LEADER          = 1129,
                RAID_FINDER_INVALID_RAID_ID               = 1130,
                RAID_FINDER_NO_RAID_CREATED               = 1131,
                RAID_FINDER_LEVEL_REQUIREMENT             = 1132,
                RAID_FINDER_ALREADY_CREATED_RAID_RECENTLY = 1133,
                RAID_FINDER_CANT_CREATE_NOT_LEADER        = 1134,
                RAID_FINDER_CANT_CREATE_IN_WINTERGRASP    = 1135,
                RAID_FINDER_CREATE_SYNTAX                 = 1136,
                RAID_FINDER_ALREADY_HAVE_RAID             = 1137,
                RAID_FINDER_CANT_CREATE_IN_BATTLEGROUND   = 1138,
                RAID_FINDER_CANT_CREATE_DIFFICULTY        = 1139,
                RAID_FINDER_AVAILABLE_RAIDS_YOU_CAN_START = 1140,
                RAID_FINDER_INVALID_ZONE                  = 1141,
                RAID_FINDER_RAID_CREATED                  = 1142,
                RAID_FINDER_RAID_JOIN_CD                  = 1143,
                RAID_FINDER_LEAVE_CURRENT_RAID_FIRST      = 1144,
                RAID_FINDER_CANT_JOIN_KICKED_RECENTLY     = 1145,
                RAID_FINDER_CANT_JOIN_OWN_RAID            = 1146,
                RAID_FINDER_CANT_JOIN_OPPOSING_FACTION    = 1147,
                RAID_FINDER_CANT_JOIN_DIFFERENT_CD        = 1148,
                RAID_FINDER_CANT_JOIN_GROUP_UNAVAILABLE   = 1149,
                RAID_FINDER_CANT_JOIN_RAID_FULL           = 1150,
                RAID_FINDER_NO_TELEPORT_CD                = 1151,
                RAID_FINDER_NO_TELEPORT_UNSUPPORTED_RAID  = 1152,
                RAID_FINDER_TELEPORT_IN_PROGRESS          = 1153,
                RAID_FINDER_MESSAGES_VISIBLE              = 1154,
                RAID_FINDER_MESSAGES_HIDDEN               = 1155,
                RAID_FINDER_CREATE_LFM_CD                 = 1156,
                RAID_FINDER_LIST                          = 1157,
                RAID_FINDER_RAIDS                         = 1158,
                RAID_BROADCAST_CREATE                     = 1159,
                RAID_BROADCAST_LFM                        = 1160,
                RAID_BROADCAST_LFM_CROSS_FACTION          = 1161,
                RAID_BROADCAST_CREATE_CROSS_FACTION       = 1162,
                RAID_FINDER_RAID_INFO_LEADER_CROSS_FACTION= 1163,
                RAID_FINDER_LIST_CROSS_FACTION            = 1164,
                RAID_FINDER_INVALID_RAID_ACRONYM          = 1165,
                RAID_FINDER_INVALID_RAID_MODE             = 1166,
                RAID_FINDER_CANT_JOIN_NOT_NEEDED_SPEC     = 1167,

                // 1v1 challenges
                CHALLENGE_ENABLED                         = 1300,
                CHALLENGE_DISABLED                        = 1301,
                CHALLENGE_RECEIVED                        = 1302,
                CHALLENGE_SENT                            = 1303,
                CHALLENGE_PLAYER_IN_BG_ARENA_INSTANCE     = 1304,
                CHALLENGE_IGNORE_OR_CHALLENGES_OFF        = 1305,
                CHALLENGE_CANT_SEND_TO_SELF               = 1306,
                CHALLENGE_RECEIVED_FROM_GM                = 1307,
                CHALLENGE_DIFFERENT_LEVELS_GM             = 1308,
                CHALLENGE_DIFFERENT_LEVELS                = 1309,
                CHALLENGE_WINNER                          = 1310,
                CHALLENGE_NOT_FOR_LOWL_LEVEL              = 1311,
                CHALLENGE_NOT_IN_COMBAT                   = 1312,
                CHALLENGE_NO_GROUPS                       = 1313,
                CHALLENGE_DIFFERENT_GROUP_SIZES_OR_BIG    = 1314,
                CHALLENGE_RECEIVED_FROM_GROUP             = 1315,
                CHALLENGE_BG_TEMPLATE_ERROR               = 1316,
                CHALLENGE_NO_BG_BETWEEN_SAME_FACTION      = 1317,
                // arena solo queue
                SOLO_QUEUE_NEED_MAX_LEVEL                 = 1330,
                SOLO_QUEUE_5V5_DISABLED                   = 1331,
                SOLO_QUEUE_NEED_ITEM_LEVEL_SKIRMISH       = 1332,
                SOLO_QUEUE_NEED_ITEM_LEVEL_RATED          = 1333,
                SOLO_QUEUE_TANK_SPECS_NOT_ALLOWED         = 1334,
                SOLO_QUEUE_SELECT_A_SPEC                  = 1335,
                SOLO_QUEUE_NOT_ALL_PLAYERS_JOINED         = 1336,
                SOLO_QUEUE_NOT_ALLOWED_TO_CHANGE_SPEC     = 1337,
                SOLO_QUEUE_PENALTY_INVITE_NOT_ACCEPTED    = 1338,
                SOLO_QUEUE_PENALTY_NEED_ITEM_LEVEL        = 1339,
                SOLO_QUEUE_REMOVED_FROM_QUEUE_ITEM_LEVEL  = 1340,
                // wargames
                WARGAME_SENT                              = 1350,
                WARGAME_RECEIVED                          = 1351,
                WARGAME_WINNER                            = 1352,
                WARGAME_IGNORE                            = 1353,
                // battlegrounds
                BG_REPORT_AFK_MUST_BE_SAME_TEAM           = 1370,
                BG_REPORT_AFK_BG_MUST_BE_IN_PROGRESS      = 1371,
                BG_REPORT_AFK_ALREADY_REPORTED            = 1372,
                BG_REPORT_AFK_ALREADY_MARKED_IDLE         = 1373,
                BG_REPORT_AFK_REPORT_LIMIT_REACHED        = 1374,
                BG_REPORT_AFK_REPORTED                    = 1375,
                BG_REPORT_AFK_REPORTED_MARKED_IDLE        = 1376,
                BG_REPORT_AFK_YOU_HAVE_BEEN_REPORTED      = 1377,

                // vendor requirements errors
                VENDOR_REQUIREMENT_MUST_HAVE_GUILD        = 1400,
                VENDOR_REQUIREMENT_MUST_HAVE_ACHIEVEMENT  = 1401,
                VENDOR_REQUIREMENT_MUST_HAVE_REPUTATION   = 1402,
                VENDOR_REQUIREMENT_MUST_HAVE_QUEST        = 1403,
                VENDOR_REQUIREMENT_PLAYER_ACHIEVEMENT     = 1404,

                // 3v3 arena announcer
                ANNOUNCER_3v3_MESSAGES_VISIBLE            = 1500,
                ANNOUNCER_3v3_MESSAGES_HIDDEN             = 1501,
                ANNOUNCER_3v3_NO_TEAMS_NO_PLAYERS         = 1502,
                ANNOUNCER_3v3_YES_TEAMS_YES_PLAYERS       = 1503,
                ANNOUNCER_3v3_NO_TEAMS_YES_PLAYERS        = 1504,
                ANNOUNCER_3v3_YES_TEAMS_NO_PLAYERS        = 1505,

                // Spell Queue
                SPELL_QUEUE_STATUS_ENABLED                = 1600,
                SPELL_QUEUE_STATUS_DISABLED               = 1601,
                SPELL_QUEUE_ALREADY_ENABLED               = 1602,
                SPELL_QUEUE_ALREADY_DISABLED              = 1603,
                SPELL_QUEUE_CANT_WHILE_CASTING            = 1604,

                // Dungeon Finder
                DUNGEON_FINDER_ONLY_LEADER_CAN_JOIN       = 1700,
                DUNGEON_FINDER_PLAYER_NOT_HAVE_REQ_ILVL   = 1702,
                DUNGEON_FINDER_CANT_CONVERT_TO_RAID       = 1703,
                DUNGEON_FINDER_PERIODIC_LEVEL_RANGE_INFO  = 1704,
                DUNGEON_FINDER_ALREADY_FIVE_MEMBERS       = 1705,
                DUNGEON_FINDER_CANT_JOIN_ALREADY_ACTIVE   = 1706,

                // LFR
                LFR_ALREADY_FULL                          = 1750,
                LFR_CANT_CONVERT_TO_PARTY                 = 1751,
                LFR_QUEUE_EMPTY                           = 1752,
                LFR_QUEUE_INFO                            = 1753,
                LFR_CANT_CHANGE_DIFFICULTY                = 1754,

                // Flex mode
                FLEX_ALREADY_ACTIVE                       = 1770,
                FLEX_CANT_JOIN_FROM_INSTANCE              = 1771,

                // Vote Points
                VOTE_POINTS_ADDED                         = 1800,
                VOTE_POINTS_SET                           = 1801,

                // streams
                STREAM_COMMENT                            = 1900,
                STREAM_STATUS                             = 1901,
                STREAM_COMMENTED                          = 1902,
                STREAM_OFFLINE                            = 1903,
                STREAM_NO_STREAM                          = 1904,

                // PvE info
                PVE_INFO_HOO                              = 2000,

                // Pet Battles
                PET_BATTLE_SCRIPT_ERROR                   = 2100,
                PET_BATTLE_CANT_JOIN_DURING_INSTANCE      = 2101,
                PET_BATTLE_QUEUE_INFO                     = 2102,

                // Isle of Thunder
                ISLE_OF_THUNDER_CANT_BE_HERE_UNTIL_STAGE  = 2200,
                ISLE_OF_THUNDER_ASSIGNMENT_ALREADY_CHOSEN = 2201,
                ISLE_OF_THUNDER_ASSIGNMENT_DAILY_COUNT    = 2202,
                ISLE_OF_THUNDER_ASSIGNMENT_DAILY_COUNT_ALL= 2203,
                ISLE_OF_THUNDER_ASSIGNMENT_CHOSEN         = 2204,

                // ingame shop
                BATTLE_PAY_ACCOUNT_BALANCE                = 2210,
                BATTLE_PAY_ACCOUNT_BALANCE_EXPLAIN        = 2211,
                BATTLE_PAY_PLEASE_LOGIN                   = 2212,
                BATTLE_PAY_PLEASE_LOGIN_EXPLAIN           = 2213,
                BATTLE_PAY_PLEASE_SALES                   = 2214,
                BATTLE_PAY_PLEASE_SALES_EXPLAIN           = 2215,
                BATTLE_PAY_BONUSES_INFO_BASIC             = 2216,
                BATTLE_PAY_BONUSES_INFO_SET               = 2217,
                BATTLE_PAY_PRODUCT_SUCCESSFULLY_BOUGHT    = 2218,
                // ingame shop errors
                BATTLE_PAY_ERROR_BAGS_FULL                = 2220,

                // challenge mode
                CHALLENGE_MODE_HACKS_DETECTED             = 2230,

                // launcher
                LAUNCHER_CLIENT_MODIFIED                  = 2240,
                LAUNCHER_NOT_USING_LAUNCHER               = 2241,

                // custom trinity_string
                CUSTOM_WINTERGRASP_MESSAGE                = 999002,
                CUSTOM_WINTERGRASP_FACTION                = 999003,
                CUSTOM_NOT_ALLOWED_IN_CHANNEL             = 999004,
                CUSTOM_INTERNAL_EVENTS                    = 999007,
                CUSTOM_TICKET_COMPLETED                   = 999014,
                CUSTOM_TICKET_REPLIED                     = 999015,
                CUSTOM_DEBUG                              = 999016,
                CUSTOM_NOT_DEATH_KNIGHT                   = 999017,
                CUSTOM_GURUBASHI_ARENA_BOOTY_RUN          = 999018,
            };
        }
    }
}

#endif
