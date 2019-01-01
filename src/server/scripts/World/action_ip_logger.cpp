/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "DatabaseEnv.h"
#include "Player.h"
#include "WorldSession.h"

enum IPLoggingTypes
{
    // AccountActionIpLogger();
    ACCOUNT_LOGIN                = 0,
    ACCOUNT_FAIL_LOGIN           = 1,
    ACCOUNT_CHANGE_PW            = 2,
    ACCOUNT_CHANGE_PW_FAIL       = 3, // Only two types of account changes exist...
    ACCOUNT_CHANGE_EMAIL         = 4,
    ACCOUNT_CHANGE_EMAIL_FAIL    = 5, // ...so we log them individually
    // OBSOLETE - ACCOUNT_LOGOUT = 6, /* Can not be logged. We still keep the type however */
    // CharacterActionIpLogger();
    CHARACTER_CREATE             = 7,
    CHARACTER_LOGIN              = 8,
    CHARACTER_LOGOUT             = 9,
    // CharacterDeleteActionIpLogger();
    CHARACTER_DELETE             = 10,
    CHARACTER_FAILED_DELETE      = 11,
    // AccountActionIpLogger(), CharacterActionIpLogger(), CharacterActionIpLogger();
    UNKNOWN_ACTION               = 12
};

class AccountActionIpLogger : public AccountScript
{
    public:
        AccountActionIpLogger() : AccountScript("AccountActionIpLogger") { }

        // We log last_ip instead of last_attempt_ip, as login was successful
        // ACCOUNT_LOGIN = 0
        void OnAccountLogin(uint32 accountId) override
        {
            AccountIPLogAction(accountId, ACCOUNT_LOGIN);
        }

        // We log last_attempt_ip instead of last_ip, as failed login doesn't necessarily mean approperiate user
        // ACCOUNT_FAIL_LOGIN = 1
        void OnFailedAccountLogin(uint32 accountId) override
        {
            AccountIPLogAction(accountId, ACCOUNT_FAIL_LOGIN);
        }

        // ACCOUNT_CHANGE_PW = 2
        void OnPasswordChange(uint32 accountId) override
        {
            AccountIPLogAction(accountId, ACCOUNT_CHANGE_PW);
        }

        // ACCOUNT_CHANGE_PW_FAIL = 3
        void OnFailedPasswordChange(uint32 accountId) override
        {
            AccountIPLogAction(accountId, ACCOUNT_CHANGE_PW_FAIL);
        }

        // Registration Email can NOT be changed apart from GM level users. Thus, we do not require to log them...
        // ACCOUNT_CHANGE_EMAIL = 4
        void OnEmailChange(uint32 accountId) override
        {
            AccountIPLogAction(accountId, ACCOUNT_CHANGE_EMAIL); // ... they get logged by gm command logger anyway
        }

        // ACCOUNT_CHANGE_EMAIL_FAIL = 5
        void OnFailedEmailChange(uint32 accountId) override
        {
            AccountIPLogAction(accountId, ACCOUNT_CHANGE_EMAIL_FAIL);
        }

        /* It's impossible to log the account logout process out of character selection - shouldn't matter anyway,
         * as ip doesn't change through playing (obviously).*/
        // ACCOUNT_LOGOUT = 6
        void AccountIPLogAction(uint32 accountId, IPLoggingTypes aType)
        {
            // Action IP Logger is only intialized if config is set up
            // Else, this script isn't loaded in the first place: We require no config check.

            // We declare all the required variables
            uint32 playerGuid = accountId;
            std::string systemNote = "ERROR"; // "ERROR" is a placeholder here. We change it later.

            // With this switch, we change systemNote so that we have a more accurate phrasing of what type it is.
            // Avoids Magicnumbers in SQL table
            switch (aType)
            {
            case ACCOUNT_LOGIN:
                systemNote = "Logged on Successful AccountLogin";
                break;
            case ACCOUNT_FAIL_LOGIN:
                systemNote = "Logged on Failed AccountLogin";
                break;
            case ACCOUNT_CHANGE_PW:
                systemNote = "Logged on Successful Account Password Change";
                break;
            case ACCOUNT_CHANGE_PW_FAIL:
                systemNote = "Logged on Failed Account Password Change";
                break;
            case ACCOUNT_CHANGE_EMAIL:
                systemNote = "Logged on Successful Account Email Change";
                break;
            case ACCOUNT_CHANGE_EMAIL_FAIL:
                systemNote = "Logged on Failed Account Email Change";
                break;
            /*case ACCOUNT_LOGOUT:
                systemNote = "Logged on AccountLogout"; //Can not be logged
                break;*/
                // Neither should happen. Ever. Period. If it does, call Ghostbusters and all your local software defences to investigate.
            case UNKNOWN_ACTION:
            default:
                systemNote = "ERROR! Unknown action!";
                break;
            }

            // Once we have done everything, we can insert the new log.
            // Seeing as the time differences should be minimal, we do not get unixtime and the timestamp right now;
            // Rather, we let it be added with the SQL query.
            if (aType != ACCOUNT_FAIL_LOGIN)
            {
                // As we can assume most account actions are NOT failed login, so this is the more accurate check.
                // For those, we need last_ip...
                PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_ALDL_IP_LOGGING);

                stmt->setUInt32(0, playerGuid);
                stmt->setUInt32(1, 0);
                stmt->setUInt8(2, aType);
                stmt->setUInt32(3, playerGuid);
                stmt->setString(4, systemNote.c_str());
                LoginDatabase.Execute(stmt);
            }
            else // ... but for failed login, we query last_attempt_ip from account table. Which we do with an unique query
            {
                PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_FACL_IP_LOGGING);

                stmt->setUInt32(0, playerGuid);
                stmt->setUInt32(1, 0);
                stmt->setUInt8(2, aType);
                stmt->setUInt32(3, playerGuid);
                stmt->setString(4, systemNote.c_str());
                LoginDatabase.Execute(stmt);
            }
            return;
        }
};

class CharacterActionIpLogger : public PlayerScript
{
    public:
        CharacterActionIpLogger() : PlayerScript("CharacterActionIpLogger") { }

        // CHARACTER_CREATE = 7
        void OnCreate(Player* player) override
        {
            CharacterIPLogAction(player, CHARACTER_CREATE);
        }

        // CHARACTER_LOGIN = 8
        void OnLogin(Player* player, bool /*firstLogin*/) override
        {
            CharacterIPLogAction(player, CHARACTER_LOGIN);
        }

        // CHARACTER_LOGOUT = 9
        void OnLogout(Player* player) override
        {
            CharacterIPLogAction(player, CHARACTER_LOGOUT);
        }

        // CHARACTER_DELETE = 10
        // CHARACTER_FAILED_DELETE = 11
        // We don't log either here - they require a guid

        // UNKNOWN_ACTION = 12
        // There is no real hook we could use for that.
        // Shouldn't happen anyway, should it ? Nothing to see here.

        /// Logs a number of actions done by players with an IP
        void CharacterIPLogAction(Player* player, IPLoggingTypes aType)
        {
            // Action IP Logger is only intialized if config is set up
            // Else, this script isn't loaded in the first place: We require no config check.

            // We declare all the required variables
            uint32 playerGuid = player->GetSession()->GetAccountId();
            const std::string currentIp = player->GetSession()->GetRemoteAddress();
            std::string systemNote = "ERROR"; // "ERROR" is a placeholder here. We change it...

            // ... with this switch, so that we have a more accurate phrasing of what type it is
            switch (aType)
            {
            case CHARACTER_CREATE:
                systemNote = "Logged on CharacterCreate";
                break;
            case CHARACTER_LOGIN:
                systemNote = "Logged on CharacterLogin";
                break;
            case CHARACTER_LOGOUT:
                systemNote = "Logged on CharacterLogout";
                break;
            case CHARACTER_DELETE:
                systemNote = "Logged on CharacterDelete";
                break;
            case CHARACTER_FAILED_DELETE:
                systemNote = "Logged on Failed CharacterDelete";
                break;
                // Neither should happen. Ever. Period. If it does, call Mythbusters.
            case UNKNOWN_ACTION:
            default:
                systemNote = "ERROR! Unknown action!";
                break;
            }

            // Once we have done everything, we can insert the new log.
            PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_CHAR_IP_LOGGING);

            stmt->setUInt32(0, playerGuid);
            stmt->setUInt64(1, player->GetGUID().GetCounter());
            stmt->setUInt8(2, aType);
            stmt->setString(3, currentIp.c_str()); // We query the ip here.
            stmt->setString(4, systemNote.c_str());
            // Seeing as the time differences should be minimal, we do not get unixtime and the timestamp right now;
            // Rather, we let it be added with the SQL query.

            LoginDatabase.Execute(stmt);
            return;
        }
};

class CharacterDeleteActionIpLogger : public PlayerScript
{
public:
    CharacterDeleteActionIpLogger() : PlayerScript("CharacterDeleteActionIpLogger") { }

    // CHARACTER_DELETE = 10
    void OnDelete(ObjectGuid guid, uint32 accountId) override
    {
        DeleteIPLogAction(guid, accountId, CHARACTER_DELETE);
    }

    // CHARACTER_FAILED_DELETE = 11
    void OnFailedDelete(ObjectGuid guid, uint32 accountId) override
    {
        DeleteIPLogAction(guid, accountId, CHARACTER_FAILED_DELETE);
    }

    void DeleteIPLogAction(ObjectGuid guid, uint32 playerGuid, IPLoggingTypes aType)
    {
        // Action IP Logger is only intialized if config is set up
        // Else, this script isn't loaded in the first place: We require no config check.

        // Query playerGuid/accountId, as we only have characterGuid
        std::string systemNote = "ERROR"; // "ERROR" is a placeholder here. We change it later.

        // With this switch, we change systemNote so that we have a more accurate phrasing of what type it is.
        // Avoids Magicnumbers in SQL table
        switch (aType)
        {
        case CHARACTER_DELETE:
            systemNote = "Logged on CharacterDelete";
            break;
        case CHARACTER_FAILED_DELETE:
            systemNote = "Logged on Failed CharacterDelete";
            break;
            // Neither should happen. Ever. Period. If it does, call to whatever god you have for mercy and guidance.
        case UNKNOWN_ACTION:
        default:
            systemNote = "ERROR! Unknown action!";
            break;
        }

        // Once we have done everything, we can insert the new log.
        PreparedStatement* stmt2 = LoginDatabase.GetPreparedStatement(LOGIN_INS_ALDL_IP_LOGGING);

        stmt2->setUInt32(0, playerGuid);
        stmt2->setUInt64(1, guid.GetCounter());
        stmt2->setUInt8(2, aType);
        stmt2->setUInt32(3, playerGuid);
        stmt2->setString(4, systemNote.c_str());
        // Seeing as the time differences should be minimal, we do not get unixtime and the timestamp right now;
        // Rather, we let it be added with the SQL query.

        LoginDatabase.Execute(stmt2);
        return;
    }
};


void AddSC_action_ip_logger()
{
    new AccountActionIpLogger();
    new CharacterActionIpLogger();
    new CharacterDeleteActionIpLogger();
}
