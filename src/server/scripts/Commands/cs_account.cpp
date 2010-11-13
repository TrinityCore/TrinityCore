/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

        static bool HandleAccountAddonCommand(ChatHandler* handler, const char* args)
        {
            if (!*args)
            {
                handler->SendSysMessage(LANG_CMD_SYNTAX);
                handler->SetSentErrorMessage(true);
                return false;
            }

            char *szExp = strtok((char*)args, " ");

            uint32 account_id = handler->GetSession()->GetAccountId();

            int expansion = atoi(szExp);                                    //get int anyway (0 if error)
            if (expansion < 0 || uint8(expansion) > sWorld.getIntConfig(CONFIG_EXPANSION))
            {
                handler->SendSysMessage(LANG_IMPROPER_VALUE);
                handler->SetSentErrorMessage(true);
                return false;
            }

            // No SQL injection
            LoginDatabase.PExecute("UPDATE account SET expansion = '%d' WHERE id = '%u'", expansion, account_id);
            handler->PSendSysMessage(LANG_ACCOUNT_ADDON, expansion);
            return true;
        }

        /// Create an account
        static bool HandleAccountCreateCommand(ChatHandler* handler, const char* args)
        {
            if (!*args)
                return false;

            ///- %Parse the command line arguments
            char *szAcc = strtok((char*)args, " ");
            char *szPassword = strtok(NULL, " ");
            if (!szAcc || !szPassword)
                return false;

            // normalized in sAccountMgr.CreateAccount
            std::string account_name = szAcc;
            std::string password = szPassword;

            AccountOpResult result = sAccountMgr.CreateAccount(account_name, password);
            switch(result)
            {
                case AOR_OK:
                    handler->PSendSysMessage(LANG_ACCOUNT_CREATED,account_name.c_str());
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
                    handler->PSendSysMessage(LANG_ACCOUNT_NOT_CREATED_SQL_ERROR,account_name.c_str());
                    handler->SetSentErrorMessage(true);
                    return false;
                default:
                    handler->PSendSysMessage(LANG_ACCOUNT_NOT_CREATED,account_name.c_str());
                    handler->SetSentErrorMessage(true);
                    return false;
            }

            return true;
        }

        /// Delete a user account and all associated characters in this realm
        /// \todo This function has to be enhanced to respect the login/realm split (delete char, delete account chars in realm, delete account chars in realm then delete account
        static bool HandleAccountDeleteCommand(ChatHandler* handler, const char* args)
        {
            if (!*args)
                return false;

            ///- Get the account name from the command line
            char *account_name_str=strtok ((char*)args," ");
            if (!account_name_str)
                return false;

            std::string account_name = account_name_str;
            if (!AccountMgr::normalizeString(account_name))
            {
                handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST,account_name.c_str());
                handler->SetSentErrorMessage(true);
                return false;
            }

            uint32 account_id = sAccountMgr.GetId(account_name);
            if (!account_id)
            {
                handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST,account_name.c_str());
                handler->SetSentErrorMessage(true);
                return false;
            }

            /// Commands not recommended call from chat, but support anyway
            /// can delete only for account with less security
            /// This is also reject self apply in fact
            if (handler->HasLowerSecurityAccount (NULL,account_id,true))
                return false;

            AccountOpResult result = sAccountMgr.DeleteAccount(account_id);
            switch(result)
            {
                case AOR_OK:
                    handler->PSendSysMessage(LANG_ACCOUNT_DELETED,account_name.c_str());
                    break;
                case AOR_NAME_NOT_EXIST:
                    handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST,account_name.c_str());
                    handler->SetSentErrorMessage(true);
                    return false;
                case AOR_DB_INTERNAL_ERROR:
                    handler->PSendSysMessage(LANG_ACCOUNT_NOT_DELETED_SQL_ERROR,account_name.c_str());
                    handler->SetSentErrorMessage(true);
                    return false;
                default:
                    handler->PSendSysMessage(LANG_ACCOUNT_NOT_DELETED,account_name.c_str());
                    handler->SetSentErrorMessage(true);
                    return false;
            }

            return true;
        }

        /// Display info on users currently in the realm
        static bool HandleAccountOnlineListCommand(ChatHandler* handler, const char* /*args*/)
        {
            ///- Get the list of accounts ID logged to the realm
            QueryResult resultDB = CharacterDatabase.Query("SELECT name,account,map,zone FROM characters WHERE online > 0");
            if (!resultDB)
            {
                handler->SendSysMessage(LANG_ACCOUNT_LIST_EMPTY);
                return true;
            }

            ///- Display the list of account/characters online
            handler->SendSysMessage(LANG_ACCOUNT_LIST_BAR_HEADER);
            handler->SendSysMessage(LANG_ACCOUNT_LIST_HEADER);
            handler->SendSysMessage(LANG_ACCOUNT_LIST_BAR);

            ///- Circle through accounts
            do
            {
                Field *fieldsDB = resultDB->Fetch();
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
                    Field *fieldsLogin = resultLogin->Fetch();
                    handler->PSendSysMessage(LANG_ACCOUNT_LIST_LINE,
                        fieldsLogin[0].GetCString(),name.c_str(),fieldsLogin[1].GetCString(),fieldsDB[2].GetInt32(),fieldsDB[3].GetInt32(),fieldsLogin[3].GetUInt32(),fieldsLogin[2].GetUInt32());
                }
                else
                    handler->PSendSysMessage(LANG_ACCOUNT_LIST_ERROR,name.c_str());

            }while (resultDB->NextRow());

            handler->SendSysMessage(LANG_ACCOUNT_LIST_BAR);
            return true;
        }

        static bool HandleAccountLockCommand(ChatHandler* handler, const char* args)
        {
            if (!*args)
            {
                handler->SendSysMessage(LANG_USE_BOL);
                handler->SetSentErrorMessage(true);
                return false;
            }

            std::string argstr = (char*)args;
            if (argstr == "on")
            {
                LoginDatabase.PExecute("UPDATE account SET locked = '1' WHERE id = '%d'",handler->GetSession()->GetAccountId());
                handler->PSendSysMessage(LANG_COMMAND_ACCLOCKLOCKED);
                return true;
            }

            if (argstr == "off")
            {
                LoginDatabase.PExecute("UPDATE account SET locked = '0' WHERE id = '%d'",handler->GetSession()->GetAccountId());
                handler->PSendSysMessage(LANG_COMMAND_ACCLOCKUNLOCKED);
                return true;
            }

            handler->SendSysMessage(LANG_USE_BOL);
            handler->SetSentErrorMessage(true);
            return false;
        }

        static bool HandleAccountPasswordCommand(ChatHandler* handler, const char* args)
        {
            if (!*args)
            {
                handler->SendSysMessage(LANG_CMD_SYNTAX);
                handler->SetSentErrorMessage(true);
                return false;
            }

            char *old_pass = strtok((char*)args, " ");
            char *new_pass = strtok(NULL, " ");
            char *new_pass_c  = strtok(NULL, " ");

            if (!old_pass || !new_pass || !new_pass_c)
            {
                handler->SendSysMessage(LANG_CMD_SYNTAX);
                handler->SetSentErrorMessage(true);
                return false;
            }

            std::string password_old = old_pass;
            std::string password_new = new_pass;
            std::string password_new_c = new_pass_c;

            if (!sAccountMgr.CheckPassword(handler->GetSession()->GetAccountId(), password_old))
            {
                handler->SendSysMessage(LANG_COMMAND_WRONGOLDPASSWORD);
                handler->SetSentErrorMessage(true);
                return false;
            }

            if (strcmp(new_pass, new_pass_c) != 0)
            {
                handler->SendSysMessage(LANG_NEW_PASSWORDS_NOT_MATCH);
                handler->SetSentErrorMessage(true);
                return false;
            }

            AccountOpResult result = sAccountMgr.ChangePassword(handler->GetSession()->GetAccountId(), password_new);
            switch(result)
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

        static bool HandleAccountCommand(ChatHandler* handler, const char* /*args*/)
        {
            AccountTypes gmlevel = handler->GetSession()->GetSecurity();
            handler->PSendSysMessage(LANG_ACCOUNT_LEVEL, uint32(gmlevel));
            return true;
        }

        /// Set/Unset the expansion level for an account
        static bool HandleAccountSetAddonCommand(ChatHandler* handler, const char *args)
        {
            ///- Get the command line arguments
            char *szAcc = strtok((char*)args," ");
            char *szExp = strtok(NULL," ");

            if (!szAcc)
                return false;

            std::string account_name;
            uint32 account_id;

            if (!szExp)
            {
                Player* player = handler->getSelectedPlayer();
                if (!player)
                    return false;

                account_id = player->GetSession()->GetAccountId();
                sAccountMgr.GetName(account_id,account_name);
                szExp = szAcc;
            }
            else
            {
                ///- Convert Account name to Upper Format
                account_name = szAcc;
                if (!AccountMgr::normalizeString(account_name))
                {
                    handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST,account_name.c_str());
                    handler->SetSentErrorMessage(true);
                    return false;
                }

                account_id = sAccountMgr.GetId(account_name);
                if (!account_id)
                {
                    handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST,account_name.c_str());
                    handler->SetSentErrorMessage(true);
                    return false;
                }

            }

            // Let set addon state only for lesser (strong) security level
            // or to self account
            if (handler->GetSession() && handler->GetSession()->GetAccountId () != account_id &&
                handler->HasLowerSecurityAccount (NULL,account_id,true))
                return false;

            int expansion = atoi(szExp);                                    //get int anyway (0 if error)
            if (expansion < 0 || uint8(expansion) > sWorld.getIntConfig(CONFIG_EXPANSION))
                 return false;

            // No SQL injection
            LoginDatabase.PExecute("UPDATE account SET expansion = '%d' WHERE id = '%u'",expansion,account_id);
            handler->PSendSysMessage(LANG_ACCOUNT_SETADDON,account_name.c_str(),account_id,expansion);
            return true;
        }

        static bool HandleAccountSetGmLevelCommand(ChatHandler* handler, const char *args)
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
                    handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST,targetAccountName.c_str());
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
            targetAccountId = (isAccountNameGiven) ? sAccountMgr.GetId(targetAccountName) : handler->getSelectedPlayer()->GetSession()->GetAccountId();
            int32 gmRealmID = (isAccountNameGiven) ? atoi(arg3) : atoi(arg2);
            uint32 plSecurity;
            if (handler->GetSession())
                plSecurity = sAccountMgr.GetSecurity(handler->GetSession()->GetAccountId(), gmRealmID);
            else
                plSecurity = SEC_CONSOLE;

            // can set security level only for target with less security and to less security that we have
            // This is also reject self apply in fact
            targetSecurity = sAccountMgr.GetSecurity(targetAccountId, gmRealmID);
            if (targetSecurity >= plSecurity || gm >= plSecurity)
            {
                handler->SendSysMessage(LANG_YOURS_SECURITY_IS_LOW);
                handler->SetSentErrorMessage(true);
                return false;
            }

            // Check and abort if the target gm has a higher rank on one of the realms and the new realm is -1
            if (gmRealmID == -1)
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
                LoginDatabase.PExecute("INSERT INTO account_access VALUES ('%u','%d','%d')", targetAccountId, gm, realmID);
            handler->PSendSysMessage(LANG_YOU_CHANGE_SECURITY, targetAccountName.c_str(), gm);
            return true;
        }

        /// Set password for account
        static bool HandleAccountSetPasswordCommand(ChatHandler* handler, const char *args)
        {
            if (!*args)
                return false;

            ///- Get the command line arguments
            char *szAccount = strtok ((char*)args," ");
            char *szPassword1 =  strtok (NULL," ");
            char *szPassword2 =  strtok (NULL," ");

            if (!szAccount||!szPassword1 || !szPassword2)
                return false;

            std::string account_name = szAccount;
            if (!AccountMgr::normalizeString(account_name))
            {
                handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST,account_name.c_str());
                handler->SetSentErrorMessage(true);
                return false;
            }

            uint32 targetAccountId = sAccountMgr.GetId(account_name);
            if (!targetAccountId)
            {
                handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST,account_name.c_str());
                handler->SetSentErrorMessage(true);
                return false;
            }

            /// can set password only for target with less security
            /// This is also reject self apply in fact
            if (handler->HasLowerSecurityAccount (NULL,targetAccountId,true))
                return false;

            if (strcmp(szPassword1,szPassword2))
            {
                handler->SendSysMessage (LANG_NEW_PASSWORDS_NOT_MATCH);
                handler->SetSentErrorMessage (true);
                return false;
            }

            AccountOpResult result = sAccountMgr.ChangePassword(targetAccountId, szPassword1);

            switch (result)
            {
                case AOR_OK:
                    handler->SendSysMessage(LANG_COMMAND_PASSWORD);
                    break;
                case AOR_NAME_NOT_EXIST:
                    handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST,account_name.c_str());
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
