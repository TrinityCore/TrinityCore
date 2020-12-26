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

#include "AccountMgr.h"
#include "BattlenetAccountMgr.h"
#include "Chat.h"
#include "CryptoRandom.h"
#include "DatabaseEnv.h"
#include "IpAddress.h"
#include "IPLocation.h"
#include "Language.h"
#include "Log.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "Util.h"
#include "WorldSession.h"

class battlenet_account_commandscript : public CommandScript
{
public:
    battlenet_account_commandscript() : CommandScript("battlenet_account_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> accountSetCommandTable =
        {
            { "password", rbac::RBAC_PERM_COMMAND_BNET_ACCOUNT_SET_PASSWORD, true,  &HandleAccountSetPasswordCommand, "" },
        };

        static std::vector<ChatCommand> accountLockCommandTable =
        {
            { "country", rbac::RBAC_PERM_COMMAND_BNET_ACCOUNT_LOCK_COUNTRY, true,  &HandleAccountLockCountryCommand, "" },
            { "ip",      rbac::RBAC_PERM_COMMAND_BNET_ACCOUNT_LOCK_IP,      true,  &HandleAccountLockIpCommand,      "" },
        };

        static std::vector<ChatCommand> accountCommandTable =
        {
            { "create",            rbac::RBAC_PERM_COMMAND_BNET_ACCOUNT_CREATE,             true,  &HandleAccountCreateCommand,     ""                          },
            { "gameaccountcreate", rbac::RBAC_PERM_COMMAND_BNET_ACCOUNT_CREATE_GAME,        true,  &HandleGameAccountCreateCommand, ""                          },
            { "lock",              rbac::RBAC_PERM_COMMAND_BNET_ACCOUNT,                    false, nullptr,                         "", accountLockCommandTable },
            { "set",               rbac::RBAC_PERM_COMMAND_BNET_ACCOUNT_SET,                true,  nullptr,                         "", accountSetCommandTable  },
            { "password",          rbac::RBAC_PERM_COMMAND_BNET_ACCOUNT_PASSWORD,           false, &HandleAccountPasswordCommand,   ""                          },
            { "link",              rbac::RBAC_PERM_COMMAND_BNET_ACCOUNT_LINK,               true,  &HandleAccountLinkCommand,       ""                          },
            { "unlink",            rbac::RBAC_PERM_COMMAND_BNET_ACCOUNT_UNLINK,             true,  &HandleAccountUnlinkCommand,     ""                          },
            { "listgameaccounts",  rbac::RBAC_PERM_COMMAND_BNET_ACCOUNT_LIST_GAME_ACCOUTNS, true,  &HandleListGameAccountsCommand,  ""                          }
        };

        static std::vector<ChatCommand> commandTable =
        {
            { "bnetaccount", rbac::RBAC_PERM_COMMAND_BNET_ACCOUNT, true,  nullptr, "", accountCommandTable },
        };

        return commandTable;
    }

    /// Create an account
    static bool HandleAccountCreateCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        ///- %Parse the command line arguments
        char* accountName = strtok((char*)args, " ");
        char* password = strtok(nullptr, " ");
        if (!accountName || !password)
            return false;

        if (!strchr(accountName, '@'))
        {
            handler->SendSysMessage(LANG_ACCOUNT_INVALID_BNET_NAME);
            handler->SetSentErrorMessage(true);
            return false;
        }

        char* createGameAccountParam = strtok(nullptr, " ");
        bool createGameAccount = true;
        if (createGameAccountParam)
            createGameAccount = StringToBool(createGameAccountParam);

        std::string gameAccountName;
        switch (Battlenet::AccountMgr::CreateBattlenetAccount(std::string(accountName), std::string(password), createGameAccount, &gameAccountName))
        {
            case AccountOpResult::AOR_OK:
            {
                if (createGameAccount)
                    handler->PSendSysMessage(LANG_ACCOUNT_CREATED_BNET_WITH_GAME, accountName, gameAccountName.c_str());
                else
                    handler->PSendSysMessage(LANG_ACCOUNT_CREATED_BNET, accountName);

                if (handler->GetSession())
                {
                    TC_LOG_INFO("entities.player.character", "Account: %u (IP: %s) Character:[%s] (%s) created Battle.net account %s%s%s",
                        handler->GetSession()->GetAccountId(), handler->GetSession()->GetRemoteAddress().c_str(),
                        handler->GetSession()->GetPlayer()->GetName().c_str(), handler->GetSession()->GetPlayer()->GetGUID().ToString().c_str(),
                        accountName, createGameAccount ? " with game account " : "", createGameAccount ? gameAccountName.c_str() : "");
                }
                break;
            }
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
            default:
                break;
        }

        return true;
    }

    // Sets country lock on own account
    static bool HandleAccountLockCountryCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
        {
            handler->SendSysMessage(LANG_USE_BOL);
            handler->SetSentErrorMessage(true);
            return false;
        }

        std::string param = (char*)args;
        if (!param.empty())
        {
            if (param == "on")
            {
                if (IpLocationRecord const* location = sIPLocation->GetLocationRecord(handler->GetSession()->GetRemoteAddress()))
                {
                    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_ACCOUNT_LOCK_CONTRY);
                    stmt->setString(0, location->CountryCode);
                    stmt->setUInt32(1, handler->GetSession()->GetBattlenetAccountId());
                    LoginDatabase.Execute(stmt);
                    handler->PSendSysMessage(LANG_COMMAND_ACCLOCKLOCKED);
                }
                else
                {
                    handler->PSendSysMessage("IP2Location] No information");
                    TC_LOG_DEBUG("server.bnetserver", "IP2Location] No information");
                }
            }
            else if (param == "off")
            {
                LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_ACCOUNT_LOCK_CONTRY);
                stmt->setString(0, "00");
                stmt->setUInt32(1, handler->GetSession()->GetBattlenetAccountId());
                LoginDatabase.Execute(stmt);
                handler->PSendSysMessage(LANG_COMMAND_ACCLOCKUNLOCKED);
            }
            return true;
        }

        handler->SendSysMessage(LANG_USE_BOL);
        handler->SetSentErrorMessage(true);
        return false;
    }

    // Sets ip lock on own account
    static bool HandleAccountLockIpCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
        {
            handler->SendSysMessage(LANG_USE_BOL);
            handler->SetSentErrorMessage(true);
            return false;
        }

        std::string param = (char*)args;

        if (!param.empty())
        {
            LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_ACCOUNT_LOCK);

            if (param == "on")
            {
                stmt->setBool(0, true);                                     // locked
                handler->PSendSysMessage(LANG_COMMAND_ACCLOCKLOCKED);
            }
            else if (param == "off")
            {
                stmt->setBool(0, false);                                    // unlocked
                handler->PSendSysMessage(LANG_COMMAND_ACCLOCKUNLOCKED);
            }

            stmt->setUInt32(1, handler->GetSession()->GetBattlenetAccountId());

            LoginDatabase.Execute(stmt);
            return true;
        }

        handler->SendSysMessage(LANG_USE_BOL);
        handler->SetSentErrorMessage(true);
        return false;
    }

    static bool HandleAccountPasswordCommand(ChatHandler* handler, char const* args)
    {
        // If no args are given at all, we can return false right away.
        if (!*args)
        {
            handler->SendSysMessage(LANG_CMD_SYNTAX);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // Command is supposed to be: .account password [$oldpassword] [$newpassword] [$newpasswordconfirmation] [$emailconfirmation]
        char* oldPassword = strtok((char*)args, " ");       // This extracts [$oldpassword]
        char* newPassword = strtok(nullptr, " ");              // This extracts [$newpassword]
        char* passwordConfirmation = strtok(nullptr, " ");     // This extracts [$newpasswordconfirmation]

        //Is any of those variables missing for any reason ? We return false.
        if (!oldPassword || !newPassword || !passwordConfirmation)
        {
            handler->SendSysMessage(LANG_CMD_SYNTAX);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // We compare the old, saved password to the entered old password - no chance for the unauthorized.
        if (!Battlenet::AccountMgr::CheckPassword(handler->GetSession()->GetBattlenetAccountId(), std::string(oldPassword)))
        {
            handler->SendSysMessage(LANG_COMMAND_WRONGOLDPASSWORD);
            handler->SetSentErrorMessage(true);
            TC_LOG_INFO("entities.player.character", "Battle.net account: %u (IP: %s) Character:[%s] (%s) Tried to change password, but the provided old password is wrong.",
                handler->GetSession()->GetBattlenetAccountId(), handler->GetSession()->GetRemoteAddress().c_str(),
                handler->GetSession()->GetPlayer()->GetName().c_str(), handler->GetSession()->GetPlayer()->GetGUID().ToString().c_str());
            return false;
        }

        // Making sure that newly entered password is correctly entered.
        if (strcmp(newPassword, passwordConfirmation) != 0)
        {
            handler->SendSysMessage(LANG_NEW_PASSWORDS_NOT_MATCH);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // Changes password and prints result.
        AccountOpResult result = Battlenet::AccountMgr::ChangePassword(handler->GetSession()->GetBattlenetAccountId(), std::string(newPassword));
        switch (result)
        {
            case AccountOpResult::AOR_OK:
                handler->SendSysMessage(LANG_COMMAND_PASSWORD);
                TC_LOG_INFO("entities.player.character", "Battle.net account: %u (IP: %s) Character:[%s] (%s) Changed Password.",
                    handler->GetSession()->GetBattlenetAccountId(), handler->GetSession()->GetRemoteAddress().c_str(),
                    handler->GetSession()->GetPlayer()->GetName().c_str(), handler->GetSession()->GetPlayer()->GetGUID().ToString().c_str());
                break;
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

    /// Set password for account
    static bool HandleAccountSetPasswordCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
        {
            handler->SendSysMessage(LANG_CMD_SYNTAX);
            handler->SetSentErrorMessage(true);
            return false;
        }

        ///- Get the command line arguments
        char* account = strtok((char*)args, " ");
        char* password = strtok(nullptr, " ");
        char* passwordConfirmation = strtok(nullptr, " ");

        if (!account || !password || !passwordConfirmation)
            return false;

        std::string accountName = account;
        if (!Utf8ToUpperOnlyLatin(accountName))
        {
            handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 targetAccountId = Battlenet::AccountMgr::GetId(accountName);
        if (!targetAccountId)
        {
            handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (strcmp(password, passwordConfirmation))
        {
            handler->SendSysMessage(LANG_NEW_PASSWORDS_NOT_MATCH);
            handler->SetSentErrorMessage(true);
            return false;
        }

        AccountOpResult result = Battlenet::AccountMgr::ChangePassword(targetAccountId, password);

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
                break;
        }
        return true;
    }

    static bool HandleAccountLinkCommand(ChatHandler* handler, char const* args)
    {
        Tokenizer tokens(args, ' ', 2);
        if (tokens.size() != 2)
        {
            handler->SendSysMessage(LANG_CMD_SYNTAX);
            handler->SetSentErrorMessage(true);
            return false;
        }

        std::string bnetAccountName = tokens[0];
        std::string gameAccountName = tokens[1];

        switch (Battlenet::AccountMgr::LinkWithGameAccount(bnetAccountName, gameAccountName))
        {
            case AccountOpResult::AOR_OK:
                handler->PSendSysMessage(LANG_ACCOUNT_BNET_LINKED, bnetAccountName.c_str(), gameAccountName.c_str());
                break;
            case AccountOpResult::AOR_NAME_NOT_EXIST:
                handler->PSendSysMessage(LANG_ACCOUNT_OR_BNET_DOES_NOT_EXIST, bnetAccountName.c_str(), gameAccountName.c_str());
                handler->SetSentErrorMessage(true);
                break;
            case AccountOpResult::AOR_ACCOUNT_BAD_LINK:
                handler->PSendSysMessage(LANG_ACCOUNT_ALREADY_LINKED, gameAccountName.c_str());
                handler->SetSentErrorMessage(true);
                break;
            default:
                break;
        }

        return true;
    }

    static bool HandleAccountUnlinkCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
        {
            handler->SendSysMessage(LANG_CMD_SYNTAX);
            handler->SetSentErrorMessage(true);
            return false;
        }

        std::string gameAccountName = args;

        switch (Battlenet::AccountMgr::UnlinkGameAccount(gameAccountName))
        {
            case AccountOpResult::AOR_OK:
                handler->PSendSysMessage(LANG_ACCOUNT_BNET_UNLINKED, gameAccountName.c_str());
                break;
            case AccountOpResult::AOR_NAME_NOT_EXIST:
                handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, gameAccountName.c_str());
                handler->SetSentErrorMessage(true);
                break;
            case AccountOpResult::AOR_ACCOUNT_BAD_LINK:
                handler->PSendSysMessage(LANG_ACCOUNT_BNET_NOT_LINKED, gameAccountName.c_str());
                handler->SetSentErrorMessage(true);
                break;
            default:
                break;
        }

        return true;
    }

    static bool HandleGameAccountCreateCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
        {
            handler->SendSysMessage(LANG_CMD_SYNTAX);
            handler->SetSentErrorMessage(true);
            return false;
        }

        std::string bnetAccountName = args;
        uint32 accountId = Battlenet::AccountMgr::GetId(bnetAccountName);
        if (!accountId)
        {
            handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, bnetAccountName.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint8 index = Battlenet::AccountMgr::GetMaxIndex(accountId) + 1;
        std::string accountName = std::to_string(accountId) + '#' + std::to_string(uint32(index));

        // Generate random hex string for password, these accounts must not be logged on with GRUNT
        std::array<uint8, 16> randPassword = Trinity::Crypto::GetRandomBytes<16>();

        switch (sAccountMgr->CreateAccount(accountName, ByteArrayToHexStr(randPassword), bnetAccountName, accountId, index))
        {
            case AccountOpResult::AOR_OK:
                handler->PSendSysMessage(LANG_ACCOUNT_CREATED, accountName.c_str());
                if (handler->GetSession())
                {
                    TC_LOG_INFO("entities.player.character", "Account: %u (IP: %s) Character:[%s] (%s) created Account %s (Email: '%s')",
                        handler->GetSession()->GetAccountId(), handler->GetSession()->GetRemoteAddress().c_str(),
                        handler->GetSession()->GetPlayer()->GetName().c_str(), handler->GetSession()->GetPlayer()->GetGUID().ToString().c_str(),
                        accountName.c_str(), bnetAccountName.c_str());
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
                handler->PSendSysMessage(LANG_ACCOUNT_NOT_CREATED_SQL_ERROR, accountName.c_str());
                handler->SetSentErrorMessage(true);
                return false;
            default:
                handler->PSendSysMessage(LANG_ACCOUNT_NOT_CREATED, accountName.c_str());
                handler->SetSentErrorMessage(true);
                return false;
        }

        return true;
    }

    static bool HandleListGameAccountsCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* battlenetAccountName = strtok((char*)args, " ");
        LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_GAME_ACCOUNT_LIST_SMALL);
        stmt->setString(0, battlenetAccountName);
        if (PreparedQueryResult accountList = LoginDatabase.Query(stmt))
        {
            auto formatDisplayName = [](char const* name) -> std::string
            {
                if (char const* hashPos = strchr(name, '#'))
                    return std::string("WoW") + ++hashPos;
                else
                    return name;
            };

            handler->SendSysMessage("----------------------------------------------------");
            handler->SendSysMessage(LANG_ACCOUNT_BNET_LIST_HEADER);
            handler->SendSysMessage("----------------------------------------------------");
            do
            {
                Field* fields = accountList->Fetch();
                handler->PSendSysMessage("| %10u | %-16.16s | %-16.16s |", fields[0].GetUInt32(), fields[1].GetCString(), formatDisplayName(fields[1].GetCString()).c_str());
            } while (accountList->NextRow());
            handler->SendSysMessage("----------------------------------------------------");
        }
        else
            handler->PSendSysMessage(LANG_ACCOUNT_BNET_LIST_NO_ACCOUNTS, battlenetAccountName);

        return true;
    }
};

void AddSC_battlenet_account_commandscript()
{
    new battlenet_account_commandscript();
}
