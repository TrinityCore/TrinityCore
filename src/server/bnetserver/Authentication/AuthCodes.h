/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef _AUTHCODES_H
#define _AUTHCODES_H

enum GameAccountFlags
{
    GAMEACCOUNT_FLAG_GM                   = 0x00000001,
    GAMEACCOUNT_FLAG_NOKICK               = 0x00000002,
    GAMEACCOUNT_FLAG_COLLECTOR            = 0x00000004,
    GAMEACCOUNT_FLAG_WOW_TRIAL            = 0x00000008,
    GAMEACCOUNT_FLAG_CANCELLED            = 0x00000010,
    GAMEACCOUNT_FLAG_IGR                  = 0x00000020,
    GAMEACCOUNT_FLAG_WHOLESALER           = 0x00000040,
    GAMEACCOUNT_FLAG_PRIVILEGED           = 0x00000080,
    GAMEACCOUNT_FLAG_EU_FORBID_ELV        = 0x00000100,
    GAMEACCOUNT_FLAG_EU_FORBID_BILLING    = 0x00000200,
    GAMEACCOUNT_FLAG_WOW_RESTRICTED       = 0x00000400,
    GAMEACCOUNT_FLAG_PARENTAL_CONTROL     = 0x00000800,
    GAMEACCOUNT_FLAG_REFERRAL             = 0x00001000,
    GAMEACCOUNT_FLAG_BLIZZARD             = 0x00002000,
    GAMEACCOUNT_FLAG_RECURRING_BILLING    = 0x00004000,
    GAMEACCOUNT_FLAG_NOELECTUP            = 0x00008000,
    GAMEACCOUNT_FLAG_KR_CERTIFICATE       = 0x00010000,
    GAMEACCOUNT_FLAG_EXPANSION_COLLECTOR  = 0x00020000,
    GAMEACCOUNT_FLAG_DISABLE_VOICE        = 0x00040000,
    GAMEACCOUNT_FLAG_DISABLE_VOICE_SPEAK  = 0x00080000,
    GAMEACCOUNT_FLAG_REFERRAL_RESURRECT   = 0x00100000,
    GAMEACCOUNT_FLAG_EU_FORBID_CC         = 0x00200000,
    GAMEACCOUNT_FLAG_OPENBETA_DELL        = 0x00400000,
    GAMEACCOUNT_FLAG_PROPASS              = 0x00800000,
    GAMEACCOUNT_FLAG_PROPASS_LOCK         = 0x01000000,
    GAMEACCOUNT_FLAG_PENDING_UPGRADE      = 0x02000000,
    GAMEACCOUNT_FLAG_RETAIL_FROM_TRIAL    = 0x04000000,
    GAMEACCOUNT_FLAG_EXPANSION2_COLLECTOR = 0x08000000,
    GAMEACCOUNT_FLAG_OVERMIND_LINKED      = 0x10000000,
    GAMEACCOUNT_FLAG_DEMOS                = 0x20000000,
    GAMEACCOUNT_FLAG_DEATH_KNIGHT_OK      = 0x40000000,
};

namespace Battlenet
{
    enum AuthResult
    {
        AUTH_OK                         = 0,
        AUTH_INTERNAL_ERROR             = 100,
        AUTH_CORRUPTED_MODULE           = 101,
        AUTH_NO_BATTLETAGS              = 102,
        AUTH_BAD_SERVER_PROOF           = 103,
        AUTH_UNKNOWN_ACCOUNT            = 104,
        AUTH_CLOSED                     = 105,
        AUTH_LOGIN_TIMEOUT              = 106,
        AUTH_NO_GAME_ACCOUNTS           = 107,
        AUTH_INVALID_TOKEN              = 108,
        AUTH_INVALID_PROGRAM            = 109,
        AUTH_INVALID_OS                 = 110,
        AUTH_UNSUPPORTED_LANGUAGE       = 111,
        AUTH_REGION_BAD_VERSION         = 112,
        AUTH_TEMP_OUTAGE                = 113,
        AUTH_CANT_DOWNLOAD_MODULE       = 114,
        AUTH_DUPLICATE_LOGON            = 115,
        AUTH_BAD_CREDENTIALS_2          = 116,
        AUTH_VERSION_CHECK_SUCCEEDED    = 117,
        AUTH_BAD_VERSION_HASH           = 118,
        AUTH_CANT_RETRIEVE_PORTAL_LIST  = 119,
        AUTH_DARK_PORTAL_DOES_NOT_EXIST = 120,
        AUTH_DARK_PORTAL_FILE_CORRUPTED = 121,
        AUTH_BATTLENET_MAINTENANCE      = 122,
        AUTH_LOGON_TOO_FAST             = 123,
        AUTH_USE_GRUNT_LOGON            = 124,
        AUTH_NO_GAME_ACCOUNTS_IN_REGION = 140,
        AUTH_ACCOUNT_LOCKED             = 141,

        LOGIN_SERVER_BUSY               = 200,
        LOGIN_NO_GAME_ACCOUNT           = 201,
        LOGIN_BANNED                    = 202,
        LOGIN_SUSPENDED                 = 203,
        LOGIN_GAME_ACCOUNT_LOCKED       = 204,
        LOGIN_ALREADY_ONLINE            = 205,
        LOGIN_NOTIME                    = 206,
        LOGIN_EXPIRED                   = 207,
        LOGIN_EXPIRED_2                 = 208,
        LOGIN_PARENTALCONTROL           = 209,
        LOGIN_TRIAL_EXPIRED             = 210,
        LOGIN_ANTI_INDULGENCE           = 211,
        LOGIN_INCORRECT_REGION          = 212,
        LOGIN_LOCKED_ENFORCED           = 213,
        LOGIN_CHARGEBACK                = 214,
        LOGIN_IGR_WITHOUT_BNET          = 215,
        LOGIN_UNLOCKABLE_LOCK           = 216,
        LOGIN_IGR_REQUIRED              = 217,
        LOGIN_PAYMENT_CHANGED           = 218,
        LOGIN_INVALID_PAYMENT           = 219,
        LOGIN_INVALID_ACCOUNT_STATE     = 220
    };

    namespace Wow
    {
        enum AuthResult
        {
            WOW_SUCCESS                 = 0,
            WOW_FAIL_BANNED             = 3,
            WOW_FAIL_UNKNOWN_ACCOUNT    = 4,
            WOW_FAIL_INCORRECT_PASSWORD = 5,
            WOW_FAIL_ALREADY_ONLINE     = 6,
            WOW_FAIL_NO_TIME            = 7,
            WOW_FAIL_DB_BUSY            = 8,
            WOW_FAIL_VERSION_INVALID    = 9,
            WOW_FAIL_VERSION_UPDATE     = 10,
            WOW_FAIL_INVALID_SERVER     = 11,
            WOW_FAIL_SUSPENDED          = 12,
            WOW_FAIL_FAIL_NOACCESS      = 13,
            WOW_SUCCESS_SURVEY          = 14,
            WOW_FAIL_PARENTCONTROL      = 15,
            WOW_FAIL_LOCKED_ENFORCED    = 16,
            WOW_FAIL_TRIAL_ENDED        = 17,
            WOW_FAIL_OVERMIND_CONVERTED = 18,
            WOW_FAIL_ANTI_INDULGENCE    = 19,
            WOW_FAIL_EXPIRED            = 20,
            WOW_FAIL_NO_GAME_ACCOUNT    = 21,
            WOW_FAIL_BILLING_LOCK       = 22,
            WOW_FAIL_IGR_WITHOUT_BNET   = 23,
            WOW_FAIL_AA_LOCK            = 24,
            WOW_FAIL_UNLOCKABLE_LOCK    = 25,
            WOW_FAIL_MUST_USE_BNET      = 26,
            WOW_FAIL_OTHER              = 255,
        };
    }
}

struct RealmBuildInfo
{
    int Build;
    int MajorVersion;
    int MinorVersion;
    int BugfixVersion;
    int HotfixVersion;
};

namespace AuthHelper
{
    RealmBuildInfo const* GetBuildInfo(int build);
    bool IsBuildSupportingBattlenet(int build);
}

#endif
