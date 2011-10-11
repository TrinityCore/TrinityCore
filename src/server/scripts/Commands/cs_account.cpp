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

/* ScriptData
Name: account_commandscript
%Complete: 100
Comment: All account related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "AccountMgr.h"
#include "Chat.h"

class account_commandscript : public CommandScript
{
public:
    account_commandscript() : CommandScript("account_commandscript") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand accountSetCommandTable[] =
        {
            { "addon",          SEC_ADMINISTRATOR,  true,  &HandleAccountSetAddonCommand,     "", NULL },
            { "gmlevel",        SEC_CONSOLE,        true,  &HandleAccountSetGmLevelCommand,   "", NULL },
            { "password",       SEC_CONSOLE,        true,  &HandleAccountSetPasswordCommand,  "", NULL },
            { NULL,             0,                  false, NULL,                              "", NULL }
        };
        static ChatCommand accountCommandTable[] =
        {
            { "addon",          SEC_MODERATOR,      false, &HandleAccountAddonCommand,        "", NULL },
            { "create",         SEC_CONSOLE,        true,  &HandleAccountCreateCommand,       "", NULL },
            { "delete",         SEC_CONSOLE,        true,  &HandleAccountDeleteCommand,       "", NULL },
            { "onlinelist",     SEC_CONSOLE,        true,  &HandleAccountOnlineListCommand,   "", NULL },
            { "lock",           SEC_PLAYER,         false, &HandleAccountLockCommand,         "", NULL },
            { "set",            SEC_ADMINISTRATOR,  true,  NULL,            "", accountSetCommandTable },
            { "password",       SEC_PLAYER,         false, &HandleAccountPasswordCommand,     "", NULL },
            { "",               SEC_PLAYER,         false, &HandleAccountCommand,             "", NULL },
            { NULL,             0,                  false, NULL,                              "", NULL }
        };
        static ChatCommand commandTable[] =
        {
            { "account",        SEC_PLAYER,         true,  NULL,     "", accountCommandTable  },
            { NULL,             0,                  false, NULL,                     "", NULL }
        };
        return commandTable;
    }

    static bool HandleAccountAddonCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
        {
            handler->SendSysMessage(LANG_CMD_SYNTAX);
            handler->SetSentErrorMessage(true);
            return false;
        }

        char* exp = strtok((char*)args, " ");

        uint32 accountId = handler->GetSession()->GetAccountId();

        int expansion = atoi(exp); //get int anyway (0 if error)
        if (expansion < 0 || uint8(expansion) > sWorld->getIntConfig(CONFIG_EXPANSION))
        {
            handler->SendSysMessage(LANG_IMPROPER_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // No SQL injection
        LoginDatabase.PExecute("UPDATE account SET expansion = '%d' WHERE id = '%u'", expansion, accountId);
        handler->PSendSysMessage(LANG_ACCOUNT_ADDON, expansion);
        return true;
    }

    /// Create an account
    static bool HandleAccountCreateCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        ///- %Parse the command line arguments
        char* accountName = strtok((char*)args, " ");
        char* password = strtok(NULL, " ");
        if (!accountName || !password)
            return false;

        AccountOpResult result = AccountMgr::CreateAccount(std::string(accountName), std::string(password));
        switch (result)
        {
            case AOR_OK:
                handler->PSendSysMessage(LANG_ACCOUNT_CREATED, accountName);
                break;
            case AOR_NAME_TOO_LONG:
                handler->SendSysMessage(LANG_ACCOUNT_TOO_LONG);
                handler->SetSentErrorMessage(true);
                return false;
            case AOR_NAME_ALREDY_EXIST:
                handler->SendSysMessage(LANG_ACCOUNT_ALREADY_EXIST);
                handler->SetSentErrorMessage(true);
                return false;
            case AOR_DB_INTERNAL_ERROR:
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
    /// \todo This function has to be enhanced to respect the login/realm split (delete char, delete account chars in realm then delete account)
    static bool HandleAccountDeleteCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        ///- Get the account name from the command line
        char* account = strtok((char*)args, " ");
        if (!account)
            return false;

        std::string accountName = account;
        if (!AccountMgr::normalizeString(accountName))
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
        if (handler->HasLowerSecurityAccount(NULL, accountId, true))
            return false;

        AccountOpResult result = AccountMgr::DeleteAccount(accountId);
        switch (result)
        {
            case AOR_OK:
                handler->PSendSysMessage(LANG_ACCOUNT_DELETED, accountName.c_str());
                break;
            case AOR_NAME_NOT_EXIST:
                handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName.c_str());
                handler->SetSentErrorMessage(true);
                return false;
            case AOR_DB_INTERNAL_ERROR:
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
    static bool HandleAccountOnlineListCommand(ChatHandler* handler, char const* /*args*/)
    {
        ///- Get the list of accounts ID logged to the realm
        QueryResult resultDB = CharacterDatabase.Query("SELECT name, account, map, zone FROM characters WHERE online > 0");
        if (!resultDB)
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
            Field* fieldsDB = resultDB->Fetch();
            std::string name = fieldsDB[0].GetString();
            uint32 account = fieldsDB[1].GetUInt32();

            ///- Get the username, last IP and GM level of each account
            // No SQL injection. account is uint32.
            QueryResult resultLogin =
                LoginDatabase.PQuery("SELECT a.username, a.last_ip, aa.gmlevel, a.expansion "
                "FROM account a "
                "LEFT JOIN account_access aa "
                "ON (a.id = aa.id) "
                "WHERE a.id = '%u'", account);

            if (resultLogin)
            {
                Field* fieldsLogin = resultLogin->Fetch();
                handler->PSendSysMessage(LANG_ACCOUNT_LIST_LINE,
                    fieldsLogin[0].GetCString(), name.c_str(), fieldsLogin[1].GetCString(),
                    fieldsDB[2].GetUInt16(), fieldsDB[3].GetUInt16(), fieldsLogin[3].GetUInt32(),
                    fieldsLogin[2].GetUInt32());
            }
            else
                handler->PSendSysMessage(LANG_ACCOUNT_LIST_ERROR, name.c_str());

        } while (resultDB->NextRow());

        handler->SendSysMessage(LANG_ACCOUNT_LIST_BAR);
        return true;
    }

    static bool HandleAccountLockCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
        {
            handler->SendSysMessage(LANG_USE_BOL);
            handler->SetSentErrorMessage(true);
            return false;
        }

        std::string param = (char*)args;
        if (param == "on")
        {
            LoginDatabase.PExecute("UPDATE account SET locked = '1' WHERE id = '%d'", handler->GetSession()->GetAccountId());
            handler->PSendSysMessage(LANG_COMMAND_ACCLOCKLOCKED);
            return true;
        }

        if (param == "off")
        {
            LoginDatabase.PExecute("UPDATE account SET locked = '0' WHERE id = '%d'", handler->GetSession()->GetAccountId());
            handler->PSendSysMessage(LANG_COMMAND_ACCLOCKUNLOCKED);
            return true;
        }

        handler->SendSysMessage(LANG_USE_BOL);
        handler->SetSentErrorMessage(true);
        return false;
    }

    static bool HandleAccountPasswordCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
        {
            handler->SendSysMessage(LANG_CMD_SYNTAX);
            handler->SetSentErrorMessage(true);
            return false;
        }

        char* oldPassword = strtok((char*)args, " ");
        char* newPassword = strtok(NULL, " ");
        char* passwordConfirmation = strtok(NULL, " ");

        if (!oldPassword || !newPassword || !passwordConfirmation)
        {
            handler->SendSysMessage(LANG_CMD_SYNTAX);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!AccountMgr::CheckPassword(handler->GetSession()->GetAccountId(), std::string(oldPassword)))
        {
            handler->SendSysMessage(LANG_COMMAND_WRONGOLDPASSWORD);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (strcmp(newPassword, passwordConfirmation) != 0)
        {
            handler->SendSysMessage(LANG_NEW_PASSWORDS_NOT_MATCH);
            handler->SetSentErrorMessage(true);
            return false;
        }

        AccountOpResult result = AccountMgr::ChangePassword(handler->GetSession()->GetAccountId(), std::string(newPassword));
        switch (result)
        {
            case AOR_OK:
                handler->SendSysMessage(LANG_COMMAND_PASSWORD);
                break;
            case AOR_PASS_TOO_LONG:
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

    static bool HandleAccountCommand(ChatHandler* handler, char const* /*args*/)
    {
        AccountTypes gmLevel = handler->GetSession()->GetSecurity();
        handler->PSendSysMessage(LANG_ACCOUNT_LEVEL, uint32(gmLevel));
        return true;
    }

    /// Set/Unset the expansion level for an account
    static bool HandleAccountSetAddonCommand(ChatHandler* handler, char const* args)
    {
        ///- Get the command line arguments
        char* account = strtok((char*)args, " ");
        char* exp = strtok(NULL, " ");

        if (!account)
            return false;

        std::string accountName;
        uint32 accountId;

        if (!exp)
        {
            Player* player = handler->getSelectedPlayer();
            if (!player)
                return false;

            accountId = player->GetSession()->GetAccountId();
            AccountMgr::GetName(accountId, accountName);
            exp = account;
        }
        else
        {
            ///- Convert Account name to Upper Format
            accountName = account;
            if (!AccountMgr::normalizeString(accountName))
            {
                handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName.c_str());
                handler->SetSentErrorMessage(true);
                return false;
            }

            accountId = AccountMgr::GetId(accountName);
            if (!accountId)
            {
                handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName.c_str());
                handler->SetSentErrorMessage(true);
                return false;
            }

        }

        // Let set addon state only for lesser (strong) security level
        // or to self account
        if (handler->GetSession() && handler->GetSession()->GetAccountId () != accountId &&
            handler->HasLowerSecurityAccount(NULL, accountId, true))
            return false;

        int expansion = atoi(exp); //get int anyway (0 if error)
        if (expansion < 0 || uint8(expansion) > sWorld->getIntConfig(CONFIG_EXPANSION))
            return false;

        // No SQL injection
        LoginDatabase.PExecute("UPDATE account SET expansion = '%d' WHERE id = '%u'", expansion, accountId);
        handler->PSendSysMessage(LANG_ACCOUNT_SETADDON, accountName.c_str(), accountId, expansion);
        return true;
    }

    static bool HandleAccountSetGmLevelCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        std::string targetAccountName;
        uint32 targetAccountId = 0;
        uint32 targetSecurity = 0;
        uint32 gm = 0;
        char* arg1 = strtok((char*)args, " ");
        char* arg2 = strtok(NULL, " ");
        char* arg3 = strtok(NULL, " ");
        bool isAccountNameGiven = true;

        if (arg1 && !arg3)
        {
            if (!handler->getSelectedPlayer())
                return false;
            isAccountNameGiven = false;
        }

        // Check for second parameter
        if (!isAccountNameGiven && !arg2)
            return false;

        // Check for account
        if (isAccountNameGiven)
        {
            targetAccountName = arg1;
            if (!AccountMgr::normalizeString(targetAccountName))
            {
                handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, targetAccountName.c_str());
                handler->SetSentErrorMessage(true);
                return false;
            }
        }

        // Check for invalid specified GM level.
        gm = (isAccountNameGiven) ? atoi(arg2) : atoi(arg1);
        if (gm > SEC_CONSOLE)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // handler->getSession() == NULL only for console
        targetAccountId = (isAccountNameGiven) ? AccountMgr::GetId(targetAccountName) : handler->getSelectedPlayer()->GetSession()->GetAccountId();
        int32 gmRealmID = (isAccountNameGiven) ? atoi(arg3) : atoi(arg2);
        uint32 playerSecurity;
        if (handler->GetSession())
            playerSecurity = AccountMgr::GetSecurity(handler->GetSession()->GetAccountId(), gmRealmID);
        else
            playerSecurity = SEC_CONSOLE;

        // can set security level only for target with less security and to less security that we have
        // This is also reject self apply in fact
        targetSecurity = AccountMgr::GetSecurity(targetAccountId, gmRealmID);
        if (targetSecurity >= playerSecurity || gm >= playerSecurity)
        {
            handler->SendSysMessage(LANG_YOURS_SECURITY_IS_LOW);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // Check and abort if the target gm has a higher rank on one of the realms and the new realm is -1
        if (gmRealmID == -1 && !AccountMgr::IsConsoleAccount(playerSecurity))
        {
            QueryResult result = LoginDatabase.PQuery("SELECT * FROM account_access WHERE id = '%u' AND gmlevel > '%d'", targetAccountId, gm);
            if (result)
            {
                handler->SendSysMessage(LANG_YOURS_SECURITY_IS_LOW);
                handler->SetSentErrorMessage(true);
                return false;
            }
        }

        // Check if provided realmID has a negative value other than -1
        if (gmRealmID < -1)
        {
            handler->SendSysMessage(LANG_INVALID_REALMID);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // If gmRealmID is -1, delete all values for the account id, else, insert values for the specific realmID
        if (gmRealmID == -1)
            LoginDatabase.PExecute("DELETE FROM account_access WHERE id = '%u'", targetAccountId);
        else
            LoginDatabase.PExecute("DELETE FROM account_access WHERE id = '%u' AND (RealmID = '%d' OR RealmID = '-1')", targetAccountId, realmID);

        if (gm != 0)
            LoginDatabase.PExecute("INSERT INTO account_access VALUES ('%u', '%d', '%d')", targetAccountId, gm, realmID);

        handler->PSendSysMessage(LANG_YOU_CHANGE_SECURITY, targetAccountName.c_str(), gm);
        return true;
    }

    /// Set password for account
    static bool HandleAccountSetPasswordCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        ///- Get the command line arguments
        char* account = strtok((char*)args, " ");
        char* password =  strtok(NULL, " ");
        char* passwordConfirmation =  strtok(NULL, " ");

        if (!account || !password || !passwordConfirmation)
            return false;

        std::string accountName = account;
        if (!AccountMgr::normalizeString(accountName))
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
        /// This is also reject self apply in fact
        if (handler->HasLowerSecurityAccount(NULL, targetAccountId, true))
            return false;

        if (strcmp(password, passwordConfirmation))
        {
            handler->SendSysMessage(LANG_NEW_PASSWORDS_NOT_MATCH);
            handler->SetSentErrorMessage(true);
            return false;
        }

        AccountOpResult result = AccountMgr::ChangePassword(targetAccountId, password);

        switch (result)
        {
            case AOR_OK:
                handler->SendSysMessage(LANG_COMMAND_PASSWORD);
                break;
            case AOR_NAME_NOT_EXIST:
                handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName.c_str());
                handler->SetSentErrorMessage(true);
                return false;
            case AOR_PASS_TOO_LONG:
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
};

void AddSC_account_commandscript()
{
    new account_commandscript();
}
