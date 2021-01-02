/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

/* ScriptData
Name: account_commandscript
%Complete: 100
Comment: All account related commands
Category: commandscripts
EndScriptData */

#include "AccountMgr.h"
#include "AES.h"
#include "Base32.h"
#include "Chat.h"
#include "CryptoGenerics.h"
#include "CryptoRandom.h"
#include "DatabaseEnv.h"
#include "IpAddress.h"
#include "IPLocation.h"
#include "Language.h"
#include "Log.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SecretMgr.h"
#include "TOTP.h"
#include "World.h"
#include "WorldSession.h"
#include <unordered_map>

using namespace Trinity::ChatCommands;

class account_commandscript : public CommandScript
{
public:
    account_commandscript() : CommandScript("account_commandscript") { }

    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable accountSetCommandTable =
        {
            { "addon",              HandleAccountSetAddonCommand,       LANG_COMMAND_ACC_SET_ADDON_HELP,        rbac::RBAC_PERM_COMMAND_ACCOUNT_SET_ADDON,          Console::Yes },
            { "sec regmail",        HandleAccountSetRegEmailCommand,    LANG_COMMAND_ACC_SET_SEC_REGMAIL_HELP,  rbac::RBAC_PERM_COMMAND_ACCOUNT_SET_SEC_REGMAIL,    Console::Yes },
            { "sec email",          HandleAccountSetEmailCommand,       LANG_COMMAND_ACC_SET_SEC_EMAIL_HELP,    rbac::RBAC_PERM_COMMAND_ACCOUNT_SET_SEC_EMAIL,      Console::Yes },
            { "gmlevel",            HandleAccountSetSecLevelCommand,    LANG_COMMAND_ACC_SET_SECLEVEL_HELP,     rbac::RBAC_PERM_COMMAND_ACCOUNT_SET_SECLEVEL,       Console::Yes },  // temp for a transition period
            { "seclevel",           HandleAccountSetSecLevelCommand,    LANG_COMMAND_ACC_SET_SECLEVEL_HELP,     rbac::RBAC_PERM_COMMAND_ACCOUNT_SET_SECLEVEL,       Console::Yes },
            { "password",           HandleAccountSetPasswordCommand,    LANG_COMMAND_ACC_SET_PASSWORD_HELP,     rbac::RBAC_PERM_COMMAND_ACCOUNT_SET_PASSWORD,       Console::Yes },
            { "2fa",                HandleAccountSet2FACommand,         LANG_COMMAND_ACC_SET_2FA_HELP,          rbac::RBAC_PERM_COMMAND_ACCOUNT_SET_2FA,            Console::Yes },
        };
        static ChatCommandTable accountCommandTable =
        {
            { "2fa setup",          HandleAccount2FASetupCommand,       LANG_COMMAND_ACC_2FA_SETUP_HELP,        rbac::RBAC_PERM_COMMAND_ACCOUNT_2FA_SETUP,          Console::No  },
            { "2fa remove",         HandleAccount2FARemoveCommand,      LANG_COMMAND_ACC_2FA_REMOVE_HELP,       rbac::RBAC_PERM_COMMAND_ACCOUNT_2FA_REMOVE,         Console::No  },
            { "addon",              HandleAccountAddonCommand,          LANG_COMMAND_ACC_ADDON_HELP,            rbac::RBAC_PERM_COMMAND_ACCOUNT_ADDON,              Console::No  },
            { "create",             HandleAccountCreateCommand,         LANG_COMMAND_ACC_CREATE_HELP,           rbac::RBAC_PERM_COMMAND_ACCOUNT_CREATE,             Console::Yes },
            { "delete",             HandleAccountDeleteCommand,         LANG_COMMAND_ACC_DELETE_HELP,           rbac::RBAC_PERM_COMMAND_ACCOUNT_DELETE,             Console::Yes },
            { "email",              HandleAccountEmailCommand,          LANG_COMMAND_ACC_EMAIL_HELP,            rbac::RBAC_PERM_COMMAND_ACCOUNT_EMAIL,              Console::No  },
            { "onlinelist",         HandleAccountOnlineListCommand,     LANG_COMMAND_ACC_ONLINELIST_HELP,       rbac::RBAC_PERM_COMMAND_ACCOUNT_ONLINE_LIST,        Console::Yes },
            { "lock country",       HandleAccountLockCountryCommand,    LANG_COMMAND_ACC_LOCK_COUNTRY_HELP,     rbac::RBAC_PERM_COMMAND_ACCOUNT_LOCK_COUNTRY,       Console::No  },
            { "lock ip",            HandleAccountLockIpCommand,         LANG_COMMAND_ACC_LOCK_IP_HELP,          rbac::RBAC_PERM_COMMAND_ACCOUNT_LOCK_IP,            Console::No  },
            { "set",                accountSetCommandTable },
            { "password",           HandleAccountPasswordCommand,       LANG_COMMAND_ACC_PASSWORD_HELP,         rbac::RBAC_PERM_COMMAND_ACCOUNT_PASSWORD,           Console::No  },
            { "",                   HandleAccountCommand,               LANG_COMMAND_ACCOUNT_HELP,              rbac::RBAC_PERM_COMMAND_ACCOUNT,                    Console::No  },
        };
        static ChatCommandTable commandTable =
        {
            { "account",            accountCommandTable },
        };
        return commandTable;
    }

    static bool HandleAccount2FASetupCommand(ChatHandler* handler, Optional<uint32> token)
    {
        auto const& masterKey = sSecretMgr->GetSecret(SECRET_TOTP_MASTER_KEY);
        if (!masterKey.IsAvailable())
        {
            handler->SendSysMessage(LANG_2FA_COMMANDS_NOT_SETUP);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 const accountId = handler->GetSession()->GetAccountId();

        { // check if 2FA already enabled
            LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_TOTP_SECRET);
            stmt->setUInt32(0, accountId);
            PreparedQueryResult result = LoginDatabase.Query(stmt);

            if (!result)
            {
                TC_LOG_ERROR("misc", "Account %u not found in login database when processing .account 2fa setup command.", accountId);
                handler->SendSysMessage(LANG_UNKNOWN_ERROR);
                handler->SetSentErrorMessage(true);
                return false;
            }

            if (!result->Fetch()->IsNull())
            {
                handler->SendSysMessage(LANG_2FA_ALREADY_SETUP);
                handler->SetSentErrorMessage(true);
                return false;
            }
        }

        // store random suggested secrets
        static std::unordered_map<uint32, Trinity::Crypto::TOTP::Secret> suggestions;
        auto pair = suggestions.emplace(std::piecewise_construct, std::make_tuple(accountId), std::make_tuple(Trinity::Crypto::TOTP::RECOMMENDED_SECRET_LENGTH)); // std::vector 1-argument size_t constructor invokes resize
        if (pair.second) // no suggestion yet, generate random secret
            Trinity::Crypto::GetRandomBytes(pair.first->second);

        if (!pair.second && token) // suggestion already existed and token specified - validate
        {
            if (Trinity::Crypto::TOTP::ValidateToken(pair.first->second, *token))
            {
                if (masterKey)
                    Trinity::Crypto::AEEncryptWithRandomIV<Trinity::Crypto::AES>(pair.first->second, *masterKey);

                LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_ACCOUNT_TOTP_SECRET);
                stmt->setBinary(0, pair.first->second);
                stmt->setUInt32(1, accountId);
                LoginDatabase.Execute(stmt);
                suggestions.erase(pair.first);
                handler->SendSysMessage(LANG_2FA_SETUP_COMPLETE);
                return true;
            }
            else
                handler->SendSysMessage(LANG_2FA_INVALID_TOKEN);
        }

        // new suggestion, or no token specified, output TOTP parameters
        handler->PSendSysMessage(LANG_2FA_SECRET_SUGGESTION, Trinity::Encoding::Base32::Encode(pair.first->second));
        handler->SetSentErrorMessage(true);
        return false;
    }

    static bool HandleAccount2FARemoveCommand(ChatHandler* handler, Optional<uint32> token)
    {
        auto const& masterKey = sSecretMgr->GetSecret(SECRET_TOTP_MASTER_KEY);
        if (!masterKey.IsAvailable())
        {
            handler->SendSysMessage(LANG_2FA_COMMANDS_NOT_SETUP);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 const accountId = handler->GetSession()->GetAccountId();
        Trinity::Crypto::TOTP::Secret secret;
        { // get current TOTP secret
            LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_TOTP_SECRET);
            stmt->setUInt32(0, accountId);
            PreparedQueryResult result = LoginDatabase.Query(stmt);

            if (!result)
            {
                TC_LOG_ERROR("misc", "Account %u not found in login database when processing .account 2fa setup command.", accountId);
                handler->SendSysMessage(LANG_UNKNOWN_ERROR);
                handler->SetSentErrorMessage(true);
                return false;
            }

            Field* field = result->Fetch();
            if (field->IsNull())
            { // 2FA not enabled
                handler->SendSysMessage(LANG_2FA_NOT_SETUP);
                handler->SetSentErrorMessage(true);
                return false;
            }

            secret = field->GetBinary();
        }

        if (token)
        {
            if (masterKey)
            {
                bool success = Trinity::Crypto::AEDecrypt<Trinity::Crypto::AES>(secret, *masterKey);
                if (!success)
                {
                    TC_LOG_ERROR("misc", "Account %u has invalid ciphertext in TOTP token.", accountId);
                    handler->SendSysMessage(LANG_UNKNOWN_ERROR);
                    handler->SetSentErrorMessage(true);
                    return false;
                }
            }

            if (Trinity::Crypto::TOTP::ValidateToken(secret, *token))
            {
                LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_ACCOUNT_TOTP_SECRET);
                stmt->setNull(0);
                stmt->setUInt32(1, accountId);
                LoginDatabase.Execute(stmt);
                handler->SendSysMessage(LANG_2FA_REMOVE_COMPLETE);
                return true;
            }
            else
                handler->SendSysMessage(LANG_2FA_INVALID_TOKEN);
        }

        handler->SendSysMessage(LANG_2FA_REMOVE_NEED_TOKEN);
        handler->SetSentErrorMessage(true);
        return false;
    }

    static bool HandleAccountAddonCommand(ChatHandler* handler, uint8 expansion)
    {
        if (expansion > sWorld->getIntConfig(CONFIG_EXPANSION))
        {
            handler->SendSysMessage(LANG_IMPROPER_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_EXPANSION);

        stmt->setUInt8(0, expansion);
        stmt->setUInt32(1, handler->GetSession()->GetAccountId());

        LoginDatabase.Execute(stmt);

        handler->PSendSysMessage(LANG_ACCOUNT_ADDON, expansion);
        return true;
    }

    /// Create an account
    static bool HandleAccountCreateCommand(ChatHandler* handler, std::string const& accountName, std::string const& password, Optional<std::string> const& email)
    {
        if (accountName.find('@') != std::string::npos)
        {
            handler->PSendSysMessage(LANG_ACCOUNT_USE_BNET_COMMANDS);
            handler->SetSentErrorMessage(true);
            return false;
        }

        switch (sAccountMgr->CreateAccount(accountName, password, email.value_or("")))
        {
            case AccountOpResult::AOR_OK:
                handler->PSendSysMessage(LANG_ACCOUNT_CREATED, accountName);
                if (handler->GetSession())
                {
                    TC_LOG_INFO("entities.player.character", "Account: %d (IP: %s) Character:[%s] %s) created Account %s (Email: '%s')",
                        handler->GetSession()->GetAccountId(), handler->GetSession()->GetRemoteAddress().c_str(),
                        handler->GetSession()->GetPlayer()->GetName().c_str(), handler->GetSession()->GetPlayer()->GetGUID().ToString().c_str(),
                        accountName.c_str(), email.value_or("").c_str());
                }
                break;
            case AccountOpResult::AOR_NAME_TOO_LONG:
                handler->SendSysMessage(LANG_ACCOUNT_NAME_TOO_LONG);
                handler->SetSentErrorMessage(true);
                return false;
            case AccountOpResult::AOR_PASS_TOO_LONG:
                handler->SendSysMessage(LANG_ACCOUNT_PASS_TOO_LONG);
                handler->SetSentErrorMessage(true);
                return false;
            case AccountOpResult::AOR_NAME_ALREADY_EXIST:
                handler->SendSysMessage(LANG_ACCOUNT_ALREADY_EXIST);
                handler->SetSentErrorMessage(true);
                return false;
            case AccountOpResult::AOR_DB_INTERNAL_ERROR:
                handler->PSendSysMessage(LANG_ACCOUNT_NOT_CREATED_SQL_ERROR, accountName);
                handler->SetSentErrorMessage(true);
                return false;
            default:
                handler->PSendSysMessage(LANG_ACCOUNT_NOT_CREATED, accountName);
                handler->SetSentErrorMessage(true);
                return false;
        }

        return true;
    }

    /// Delete a user account and all associated characters in this realm
    /// @todo This function has to be enhanced to respect the login/realm split (delete char, delete account chars in realm then delete account)
    static bool HandleAccountDeleteCommand(ChatHandler* handler, std::string accountName)
    {
        if (!Utf8ToUpperOnlyLatin(accountName))
        {
            handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 accountId = AccountMgr::GetId(accountName);
        if (!accountId)
        {
            handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        /// Commands not recommended call from chat, but support anyway
        /// can delete only for account with less security
        /// This is also reject self apply in fact
        if (handler->HasLowerSecurityAccount(nullptr, accountId, true))
            return false;

        AccountOpResult result = AccountMgr::DeleteAccount(accountId);
        switch (result)
        {
            case AccountOpResult::AOR_OK:
                handler->PSendSysMessage(LANG_ACCOUNT_DELETED, accountName.c_str());
                break;
            case AccountOpResult::AOR_NAME_NOT_EXIST:
                handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName.c_str());
                handler->SetSentErrorMessage(true);
                return false;
            case AccountOpResult::AOR_DB_INTERNAL_ERROR:
                handler->PSendSysMessage(LANG_ACCOUNT_NOT_DELETED_SQL_ERROR, accountName.c_str());
                handler->SetSentErrorMessage(true);
                return false;
            default:
                handler->PSendSysMessage(LANG_ACCOUNT_NOT_DELETED, accountName.c_str());
                handler->SetSentErrorMessage(true);
                return false;
        }

        return true;
    }

    /// Display info on users currently in the realm
    static bool HandleAccountOnlineListCommand(ChatHandler* handler)
    {
        ///- Get the list of accounts ID logged to the realm
        PreparedQueryResult result = CharacterDatabase.Query(CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_ONLINE));

        if (!result)
        {
            handler->SendSysMessage(LANG_ACCOUNT_LIST_EMPTY);
            return true;
        }

        ///- Display the list of account/characters online
        handler->SendSysMessage(LANG_ACCOUNT_LIST_BAR_HEADER);
        handler->SendSysMessage(LANG_ACCOUNT_LIST_HEADER);
        handler->SendSysMessage(LANG_ACCOUNT_LIST_BAR);

        ///- Cycle through accounts
        do
        {
            Field* fieldsDB = result->Fetch();
            std::string name = fieldsDB[0].GetString();
            uint32 account = fieldsDB[1].GetUInt32();

            ///- Get the username, last IP and GM level of each account
            // No SQL injection. account is uint32.
            LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_INFO);
            stmt->setUInt32(0, account);
            PreparedQueryResult resultLogin = LoginDatabase.Query(stmt);

            if (resultLogin)
            {
                Field* fieldsLogin = resultLogin->Fetch();
                handler->PSendSysMessage(LANG_ACCOUNT_LIST_LINE,
                    fieldsLogin[0].GetCString(), name.c_str(), fieldsLogin[1].GetCString(),
                    fieldsDB[2].GetUInt16(), fieldsDB[3].GetUInt16(), fieldsLogin[3].GetUInt8(),
                    fieldsLogin[2].GetUInt8());
            }
            else
                handler->PSendSysMessage(LANG_ACCOUNT_LIST_ERROR, name.c_str());
        }
        while (result->NextRow());

        handler->SendSysMessage(LANG_ACCOUNT_LIST_BAR);
        return true;
    }

    static bool HandleAccountLockCountryCommand(ChatHandler* handler, bool state)
    {
        if (state)
        {
            if (IpLocationRecord const* location = sIPLocation->GetLocationRecord(handler->GetSession()->GetRemoteAddress()))
            {
                LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_ACCOUNT_LOCK_COUNTRY);
                stmt->setString(0, location->CountryCode);
                stmt->setUInt32(1, handler->GetSession()->GetAccountId());
                LoginDatabase.Execute(stmt);
                handler->PSendSysMessage(LANG_COMMAND_ACCLOCKLOCKED);
            }
            else
            {
                handler->PSendSysMessage("No IP2Location information - account not locked");
                handler->SetSentErrorMessage(true);
                return false;
            }
        }
        else
        {
            LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_ACCOUNT_LOCK_COUNTRY);
            stmt->setString(0, "00");
            stmt->setUInt32(1, handler->GetSession()->GetAccountId());
            LoginDatabase.Execute(stmt);
            handler->PSendSysMessage(LANG_COMMAND_ACCLOCKUNLOCKED);
        }
        return true;
    }

    static bool HandleAccountLockIpCommand(ChatHandler* handler, bool state)
    {
        LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_ACCOUNT_LOCK);

        if (state)
        {
            stmt->setBool(0, true);                                     // locked
            handler->PSendSysMessage(LANG_COMMAND_ACCLOCKLOCKED);
        }
        else
        {
            stmt->setBool(0, false);                                    // unlocked
            handler->PSendSysMessage(LANG_COMMAND_ACCLOCKUNLOCKED);
        }

        stmt->setUInt32(1, handler->GetSession()->GetAccountId());

        LoginDatabase.Execute(stmt);
        return true;
    }

    static bool HandleAccountEmailCommand(ChatHandler* handler, std::string const& oldEmail, std::string const& password, std::string const& email, std::string const& emailConfirm)
    {
        if (!AccountMgr::CheckEmail(handler->GetSession()->GetAccountId(), oldEmail))
        {
            handler->SendSysMessage(LANG_COMMAND_WRONGEMAIL);
            sScriptMgr->OnFailedEmailChange(handler->GetSession()->GetAccountId());
            handler->SetSentErrorMessage(true);
            TC_LOG_INFO("entities.player.character", "Account: %u (IP: %s) Character:[%s] %s Tried to change email, but the provided email [%s] is not equal to registration email [%s].",
                handler->GetSession()->GetAccountId(), handler->GetSession()->GetRemoteAddress().c_str(),
                handler->GetSession()->GetPlayer()->GetName().c_str(), handler->GetSession()->GetPlayer()->GetGUID().ToString().c_str(),
                email.c_str(), oldEmail.c_str());
            return false;
        }

        if (!AccountMgr::CheckPassword(handler->GetSession()->GetAccountId(), password))
        {
            handler->SendSysMessage(LANG_COMMAND_WRONGOLDPASSWORD);
            sScriptMgr->OnFailedEmailChange(handler->GetSession()->GetAccountId());
            handler->SetSentErrorMessage(true);
            TC_LOG_INFO("entities.player.character", "Account: %u (IP: %s) Character:[%s] %s Tried to change email, but the provided password is wrong.",
                handler->GetSession()->GetAccountId(), handler->GetSession()->GetRemoteAddress().c_str(),
                handler->GetSession()->GetPlayer()->GetName().c_str(), handler->GetSession()->GetPlayer()->GetGUID().ToString().c_str());
            return false;
        }

        if (email == oldEmail)
        {
            handler->SendSysMessage(LANG_OLD_EMAIL_IS_NEW_EMAIL);
            sScriptMgr->OnFailedEmailChange(handler->GetSession()->GetAccountId());
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (email != emailConfirm)
        {
            handler->SendSysMessage(LANG_NEW_EMAILS_NOT_MATCH);
            sScriptMgr->OnFailedEmailChange(handler->GetSession()->GetAccountId());
            handler->SetSentErrorMessage(true);
            TC_LOG_INFO("entities.player.character", "Account: %u (IP: %s) Character:[%s] %s Tried to change email, but the confirm email does not match.",
                handler->GetSession()->GetAccountId(), handler->GetSession()->GetRemoteAddress().c_str(),
                handler->GetSession()->GetPlayer()->GetName().c_str(), handler->GetSession()->GetPlayer()->GetGUID().ToString().c_str());
            return false;
        }

        AccountOpResult result = AccountMgr::ChangeEmail(handler->GetSession()->GetAccountId(), email);
        switch (result)
        {
            case AccountOpResult::AOR_OK:
                handler->SendSysMessage(LANG_COMMAND_EMAIL);
                sScriptMgr->OnEmailChange(handler->GetSession()->GetAccountId());
                TC_LOG_INFO("entities.player.character", "Account: %u (IP: %s) Character:[%s] %s Changed Email from [%s] to [%s].",
                    handler->GetSession()->GetAccountId(), handler->GetSession()->GetRemoteAddress().c_str(),
                    handler->GetSession()->GetPlayer()->GetName().c_str(), handler->GetSession()->GetPlayer()->GetGUID().ToString().c_str(),
                    oldEmail.c_str(), email.c_str());
                break;
            case AccountOpResult::AOR_EMAIL_TOO_LONG:
                handler->SendSysMessage(LANG_EMAIL_TOO_LONG);
                sScriptMgr->OnFailedEmailChange(handler->GetSession()->GetAccountId());
                handler->SetSentErrorMessage(true);
                return false;
            default:
                handler->SendSysMessage(LANG_COMMAND_NOTCHANGEEMAIL);
                handler->SetSentErrorMessage(true);
                return false;
        }

        return true;
    }

    static bool HandleAccountPasswordCommand(ChatHandler* handler, std::string const& oldPassword, std::string const& newPassword, std::string const& confirmPassword, Optional<std::string> const& confirmEmail)
    {
        // First, we check config. What security type (sec type) is it ? Depending on it, the command branches out
        uint32 const pwConfig = sWorld->getIntConfig(CONFIG_ACC_PASSCHANGESEC); // 0 - PW_NONE, 1 - PW_EMAIL, 2 - PW_RBAC

        // We compare the old, saved password to the entered old password - no chance for the unauthorized.
        if (!AccountMgr::CheckPassword(handler->GetSession()->GetAccountId(), oldPassword))
        {
            handler->SendSysMessage(LANG_COMMAND_WRONGOLDPASSWORD);
            sScriptMgr->OnFailedPasswordChange(handler->GetSession()->GetAccountId());
            handler->SetSentErrorMessage(true);
            TC_LOG_INFO("entities.player.character", "Account: %u (IP: %s) Character:[%s] %s Tried to change password, but the provided old password is wrong.",
                handler->GetSession()->GetAccountId(), handler->GetSession()->GetRemoteAddress().c_str(),
                handler->GetSession()->GetPlayer()->GetName().c_str(), handler->GetSession()->GetPlayer()->GetGUID().ToString().c_str());
            return false;
        }

        // This compares the old, current email to the entered email - however, only...
        if ((pwConfig == PW_EMAIL || (pwConfig == PW_RBAC && handler->HasPermission(rbac::RBAC_PERM_EMAIL_CONFIRM_FOR_PASS_CHANGE))) // ...if either PW_EMAIL or PW_RBAC with the Permission is active...
            && !AccountMgr::CheckEmail(handler->GetSession()->GetAccountId(), confirmEmail.value_or(""))) // ... and returns false if the comparison fails.
        {
            handler->SendSysMessage(LANG_COMMAND_WRONGEMAIL);
            sScriptMgr->OnFailedPasswordChange(handler->GetSession()->GetAccountId());
            handler->SetSentErrorMessage(true);
            TC_LOG_INFO("entities.player.character", "Account: %u (IP: %s) Character:[%s] %s Tried to change password, but the entered email [%s] is wrong.",
                handler->GetSession()->GetAccountId(), handler->GetSession()->GetRemoteAddress().c_str(),
                handler->GetSession()->GetPlayer()->GetName().c_str(), handler->GetSession()->GetPlayer()->GetGUID().ToString().c_str(),
                confirmEmail.value_or("").c_str());
            return false;
        }

        // Making sure that newly entered password is correctly entered.
        if (newPassword != confirmPassword)
        {
            handler->SendSysMessage(LANG_NEW_PASSWORDS_NOT_MATCH);
            sScriptMgr->OnFailedPasswordChange(handler->GetSession()->GetAccountId());
            handler->SetSentErrorMessage(true);
            return false;
        }

        // Changes password and prints result.
        AccountOpResult result = AccountMgr::ChangePassword(handler->GetSession()->GetAccountId(), newPassword);
        switch (result)
        {
            case AccountOpResult::AOR_OK:
                handler->SendSysMessage(LANG_COMMAND_PASSWORD);
                sScriptMgr->OnPasswordChange(handler->GetSession()->GetAccountId());
                TC_LOG_INFO("entities.player.character", "Account: %u (IP: %s) Character:[%s] %s changed password.",
                    handler->GetSession()->GetAccountId(), handler->GetSession()->GetRemoteAddress().c_str(),
                    handler->GetSession()->GetPlayer()->GetName().c_str(), handler->GetSession()->GetPlayer()->GetGUID().ToString().c_str());
                break;
            case AccountOpResult::AOR_PASS_TOO_LONG:
                handler->SendSysMessage(LANG_PASSWORD_TOO_LONG);
                sScriptMgr->OnFailedPasswordChange(handler->GetSession()->GetAccountId());
                handler->SetSentErrorMessage(true);
                return false;
            default:
                handler->SendSysMessage(LANG_COMMAND_NOTCHANGEPASSWORD);
                handler->SetSentErrorMessage(true);
                return false;
        }

        return true;
    }

    static bool HandleAccountCommand(ChatHandler* handler)
    {
        // GM Level
        AccountTypes securityLevel = handler->GetSession()->GetSecurity();
        handler->PSendSysMessage(LANG_ACCOUNT_LEVEL, uint32(securityLevel));

        // Security level required
        bool hasRBAC = (handler->HasPermission(rbac::RBAC_PERM_EMAIL_CONFIRM_FOR_PASS_CHANGE) ? true : false);
        uint32 pwConfig = sWorld->getIntConfig(CONFIG_ACC_PASSCHANGESEC); // 0 - PW_NONE, 1 - PW_EMAIL, 2 - PW_RBAC

        handler->PSendSysMessage(LANG_ACCOUNT_SEC_TYPE, (pwConfig == PW_NONE  ? "Lowest level: No Email input required." :
                                                         pwConfig == PW_EMAIL ? "Highest level: Email input required." :
                                                         pwConfig == PW_RBAC  ? "Special level: Your account may require email input depending on settings. That is the case if another line is printed." :
                                                                                "Unknown security level: Config error?"));

        // RBAC required display - is not displayed for console
        if (pwConfig == PW_RBAC && handler->GetSession() && hasRBAC)
            handler->PSendSysMessage(LANG_RBAC_EMAIL_REQUIRED);

        // Email display if sufficient rights
        if (handler->HasPermission(rbac::RBAC_PERM_MAY_CHECK_OWN_EMAIL))
        {
            std::string emailoutput;
            uint32 accountId = handler->GetSession()->GetAccountId();

            LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_GET_EMAIL_BY_ID);
            stmt->setUInt32(0, accountId);
            PreparedQueryResult result = LoginDatabase.Query(stmt);

            if (result)
            {
                emailoutput = (*result)[0].GetString();
                handler->PSendSysMessage(LANG_COMMAND_EMAIL_OUTPUT, emailoutput.c_str());
            }
        }

        return true;
    }

    /// Set/Unset the expansion level for an account
    static bool HandleAccountSetAddonCommand(ChatHandler* handler, Optional<std::string> accountName, uint8 expansion)
    {
        uint32 accountId;
        if (accountName)
        {
            ///- Convert Account name to Upper Format
            if (!Utf8ToUpperOnlyLatin(*accountName))
            {
                handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName->c_str());
                handler->SetSentErrorMessage(true);
                return false;
            }

            accountId = AccountMgr::GetId(*accountName);
            if (!accountId)
            {
                handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName->c_str());
                handler->SetSentErrorMessage(true);
                return false;
            }

        }
        else
        {
            Player* player = handler->getSelectedPlayer();
            if (!player)
                return false;

            accountId = player->GetSession()->GetAccountId();
            accountName.emplace();
            AccountMgr::GetName(accountId, *accountName);
        }

        // Let set addon state only for lesser (strong) security level
        // or to self account
        if (handler->GetSession() && handler->GetSession()->GetAccountId() != accountId &&
            handler->HasLowerSecurityAccount(nullptr, accountId, true))
            return false;

        if (expansion > sWorld->getIntConfig(CONFIG_EXPANSION))
            return false;

        LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_EXPANSION);

        stmt->setUInt8(0, expansion);
        stmt->setUInt32(1, accountId);

        LoginDatabase.Execute(stmt);

        handler->PSendSysMessage(LANG_ACCOUNT_SETADDON, accountName->c_str(), accountId, expansion);
        return true;
    }

    static bool HandleAccountSetSecLevelCommand(ChatHandler* handler, Optional<std::string> accountName, uint8 securityLevel, Optional<int32> realmId)
    {
        uint32 accountId;
        if (accountName)
        {
            if (!Utf8ToUpperOnlyLatin(*accountName))
            {
                handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName->c_str());
                handler->SetSentErrorMessage(true);
                return false;
            }

            accountId = AccountMgr::GetId(*accountName);
            if (!accountId)
            {
                handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName->c_str());
                handler->SetSentErrorMessage(true);
                return false;
            }
        }
        else
        {
            Player* player = handler->getSelectedPlayer();
            if (!player)
                return false;
            accountId = player->GetSession()->GetAccountId();
            accountName.emplace();
            AccountMgr::GetName(accountId, *accountName);
        }

        if (securityLevel >= SEC_CONSOLE)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        int32 realmID = -1;
        if (realmId)
            realmID = *realmId;

        uint32 playerSecurity;
        if (handler->IsConsole())
            playerSecurity = SEC_CONSOLE;
        else
            playerSecurity = AccountMgr::GetSecurity(handler->GetSession()->GetAccountId(), realmID);

        // can set security level only for target with less security and to less security that we have
        // This also restricts setting handler's own security.
        uint32 targetSecurity = AccountMgr::GetSecurity(accountId, realmID);
        if (targetSecurity >= playerSecurity || securityLevel >= playerSecurity)
        {
            handler->SendSysMessage(LANG_YOURS_SECURITY_IS_LOW);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // Check and abort if the target gm has a higher rank on one of the realms and the new realm is -1
        if (realmID == -1 && !AccountMgr::IsConsoleAccount(playerSecurity))
        {
            LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_ACCESS_SECLEVEL_TEST);

            stmt->setUInt32(0, accountId);
            stmt->setUInt8(1, securityLevel);

            PreparedQueryResult result = LoginDatabase.Query(stmt);

            if (result)
            {
                handler->SendSysMessage(LANG_YOURS_SECURITY_IS_LOW);
                handler->SetSentErrorMessage(true);
                return false;
            }
        }

        // Check if provided realmID has a negative value other than -1
        if (realmID < -1)
        {
            handler->SendSysMessage(LANG_INVALID_REALMID);
            handler->SetSentErrorMessage(true);
            return false;
        }

        sAccountMgr->UpdateAccountAccess(nullptr, accountId, securityLevel, realmID);

        handler->PSendSysMessage(LANG_YOU_CHANGE_SECURITY, accountName->c_str(), securityLevel);
        return true;
    }

    /// Set password for account
    static bool HandleAccountSetPasswordCommand(ChatHandler* handler, std::string accountName, std::string const& password, std::string const& confirmPassword)
    {
        if (!Utf8ToUpperOnlyLatin(accountName))
        {
            handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 targetAccountId = AccountMgr::GetId(accountName);
        if (!targetAccountId)
        {
            handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        /// can set password only for target with less security
        /// This also restricts setting handler's own password
        if (handler->HasLowerSecurityAccount(nullptr, targetAccountId, true))
            return false;

        if (password != confirmPassword)
        {
            handler->SendSysMessage(LANG_NEW_PASSWORDS_NOT_MATCH);
            handler->SetSentErrorMessage(true);
            return false;
        }

        AccountOpResult result = AccountMgr::ChangePassword(targetAccountId, password);
        switch (result)
        {
            case AccountOpResult::AOR_OK:
                handler->SendSysMessage(LANG_COMMAND_PASSWORD);
                break;
            case AccountOpResult::AOR_NAME_NOT_EXIST:
                handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName.c_str());
                handler->SetSentErrorMessage(true);
                return false;
            case AccountOpResult::AOR_PASS_TOO_LONG:
                handler->SendSysMessage(LANG_PASSWORD_TOO_LONG);
                handler->SetSentErrorMessage(true);
                return false;
            default:
                handler->SendSysMessage(LANG_COMMAND_NOTCHANGEPASSWORD);
                handler->SetSentErrorMessage(true);
                return false;
        }
        return true;
    }

    static bool HandleAccountSet2FACommand(ChatHandler* handler, std::string accountName, std::string secret)
    {
        if (!Utf8ToUpperOnlyLatin(accountName))
        {
            handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 targetAccountId = AccountMgr::GetId(accountName);
        if (!targetAccountId)
        {
            handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (handler->HasLowerSecurityAccount(nullptr, targetAccountId, true))
            return false;

        if (secret == "off")
        {
            LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_ACCOUNT_TOTP_SECRET);
            stmt->setNull(0);
            stmt->setUInt32(1, targetAccountId);
            LoginDatabase.Execute(stmt);
            handler->PSendSysMessage(LANG_2FA_REMOVE_COMPLETE);
            return true;
        }

        auto const& masterKey = sSecretMgr->GetSecret(SECRET_TOTP_MASTER_KEY);
        if (!masterKey.IsAvailable())
        {
            handler->SendSysMessage(LANG_2FA_COMMANDS_NOT_SETUP);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Optional<std::vector<uint8>> decoded = Trinity::Encoding::Base32::Decode(secret);
        if (!decoded)
        {
            handler->SendSysMessage(LANG_2FA_SECRET_INVALID);
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (128 < (decoded->size() + Trinity::Crypto::AES::IV_SIZE_BYTES + Trinity::Crypto::AES::TAG_SIZE_BYTES))
        {
            handler->SendSysMessage(LANG_2FA_SECRET_TOO_LONG);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (masterKey)
            Trinity::Crypto::AEEncryptWithRandomIV<Trinity::Crypto::AES>(*decoded, *masterKey);

        LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_ACCOUNT_TOTP_SECRET);
        stmt->setBinary(0, *decoded);
        stmt->setUInt32(1, targetAccountId);
        LoginDatabase.Execute(stmt);
        handler->PSendSysMessage(LANG_2FA_SECRET_SET_COMPLETE, accountName.c_str());
        return true;
    }

    /// Set normal email for account
    static bool HandleAccountSetEmailCommand(ChatHandler* handler, std::string accountName, std::string const& email, std::string const& confirmEmail)
    {
        if (!Utf8ToUpperOnlyLatin(accountName))
        {
            handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 targetAccountId = AccountMgr::GetId(accountName);
        if (!targetAccountId)
        {
            handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        /// can set email only for target with less security
        /// This also restricts setting handler's own email.
        if (handler->HasLowerSecurityAccount(nullptr, targetAccountId, true))
            return false;

        if (email != confirmEmail)
        {
            handler->SendSysMessage(LANG_NEW_EMAILS_NOT_MATCH);
            handler->SetSentErrorMessage(true);
            return false;
        }

        AccountOpResult result = AccountMgr::ChangeEmail(targetAccountId, email);
        switch (result)
        {
            case AccountOpResult::AOR_OK:
                handler->SendSysMessage(LANG_COMMAND_EMAIL);
                TC_LOG_INFO("entities.player.character", "ChangeEmail: Account %s [Id: %u] had it's email changed to %s.",
                    accountName.c_str(), targetAccountId, email.c_str());
                break;
            case AccountOpResult::AOR_NAME_NOT_EXIST:
                handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName.c_str());
                handler->SetSentErrorMessage(true);
                return false;
            case AccountOpResult::AOR_EMAIL_TOO_LONG:
                handler->SendSysMessage(LANG_EMAIL_TOO_LONG);
                handler->SetSentErrorMessage(true);
                return false;
            default:
                handler->SendSysMessage(LANG_COMMAND_NOTCHANGEEMAIL);
                handler->SetSentErrorMessage(true);
                return false;
        }

        return true;
    }

    /// Change registration email for account
    static bool HandleAccountSetRegEmailCommand(ChatHandler* handler, std::string accountName, std::string const& email, std::string const& confirmEmail)
    {
        if (!Utf8ToUpperOnlyLatin(accountName))
        {
            handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 targetAccountId = AccountMgr::GetId(accountName);
        if (!targetAccountId)
        {
            handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        /// can set email only for target with less security
        /// This also restricts setting handler's own email.
        if (handler->HasLowerSecurityAccount(nullptr, targetAccountId, true))
            return false;

        if (email != confirmEmail)
        {
            handler->SendSysMessage(LANG_NEW_EMAILS_NOT_MATCH);
            handler->SetSentErrorMessage(true);
            return false;
        }

        AccountOpResult result = AccountMgr::ChangeRegEmail(targetAccountId, email);
        switch (result)
        {
            case AccountOpResult::AOR_OK:
                handler->SendSysMessage(LANG_COMMAND_EMAIL);
                TC_LOG_INFO("entities.player.character", "ChangeRegEmail: Account %s [Id: %u] had it's Registration Email changed to %s.",
                    accountName.c_str(), targetAccountId, email.c_str());
                break;
            case AccountOpResult::AOR_NAME_NOT_EXIST:
                handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName.c_str());
                handler->SetSentErrorMessage(true);
                return false;
            case AccountOpResult::AOR_EMAIL_TOO_LONG:
                handler->SendSysMessage(LANG_EMAIL_TOO_LONG);
                handler->SetSentErrorMessage(true);
                return false;
            default:
                handler->SendSysMessage(LANG_COMMAND_NOTCHANGEEMAIL);
                handler->SetSentErrorMessage(true);
                return false;
        }

        return true;
    }
};

void AddSC_account_commandscript()
{
    new account_commandscript();
}
