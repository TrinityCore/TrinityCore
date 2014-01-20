/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
Name: custom_Commandscript
%Complete: 90
Comment: commandscript for custom commands
Category: Scripts
EndScriptData */

#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "MapManager.h"
#include "Chat.h"
#include "Group.h"

class custom_commandscript : public CommandScript
{
    public:
        custom_commandscript() : CommandScript("custom_commandscript") { }

        ChatCommand* GetCommands() const OVERRIDE
        {
            static ChatCommand questcompleterCommandTable[] =
            {
                { "add",              rbac::RBAC_PERM_COMMAND_QUESTCOMPLETER_ADD,     true, &HandleQuestCompleterAddCommand,     "", NULL },
                { "del",              rbac::RBAC_PERM_COMMAND_QUESTCOMPLETER_DEL,     true, &HandleQuestCompleterDelCommand,     "", NULL },
                { "status",           rbac::RBAC_PERM_COMMAND_QUESTCOMPLETER_STATUS,  true, &HandleQuestCompleterStatusCommand,  "", NULL },
                { NULL,               0,                                              false, NULL,                               "", NULL }
            };
            static ChatCommand onlineCommandTable[] =
            {
                { "account",        rbac::RBAC_PERM_COMMAND_ONLINE_ACC,               true,  &HandleOnlineAccountCommand,        "", NULL },
                { "character",      rbac::RBAC_PERM_COMMAND_ONLINE_CHAR,              true,  &HandleOnlineCharacterCommand,      "", NULL },
                { NULL,             0,                                                false, NULL,                               "", NULL }
            };
            static ChatCommand commandTable[] =
            {
                { "qc",              rbac::RBAC_PERM_COMMAND_QUESTCOMPLETER,          true,  NULL,                               "", questcompleterCommandTable },
                { "online",          rbac::RBAC_PERM_COMMAND_ONLINE,                  true,  NULL,                               "", onlineCommandTable },
                { NULL,              0,                                               false, NULL,                               "", NULL }
            };
            return commandTable;
        }
        static bool HandleQuestCompleterStatusCommand(ChatHandler* handler, char const* args)
        {
            char* quest = handler->extractKeyFromLink((char*)args, "Hquest");
            if (!quest)
            {
                handler->PSendSysMessage("Please enter a quest link.");
                handler->SetSentErrorMessage(true);
                return false;
            }
            else
            {
                uint32 id = atol(quest);
                if(id != 0)
                {
                    QueryResult IDSearch = LoginDatabase.PQuery("SELECT COUNT(id) FROM quest_completer WHERE id = %i", id);
                    Field* fields = IDSearch->Fetch();

                    if (fields[0].GetUInt32() == 1)
                        handler->PSendSysMessage("Quest is bugged!");
                    else
                        handler->PSendSysMessage("Quest is not bugged!");
                }
                else
                {
                    handler->PSendSysMessage("Please enter a quest link.");
                    handler->SetSentErrorMessage(true);
                    return false;
                }
            }
        
            return true;
        }
	static bool HandleQuestCompleterAddCommand(ChatHandler* handler, char const* args)
	{
		char* quest = handler->extractKeyFromLink((char*)args, "Hquest");
		if (!quest)
		{
			handler->PSendSysMessage("Please enter a quest link.");
			handler->SetSentErrorMessage(true);
			return false;
		}
		// Change from string to int to prevent crash with query
		uint32 id = atol(quest);
		QueryResult QCSearch = LoginDatabase.PQuery("SELECT COUNT(id) FROM quest_completer WHERE id = %i", id);
		Field* fields = QCSearch->Fetch();

		if (fields[0].GetUInt32() == 1)
			handler->PSendSysMessage("Quest is already added!");
		else
		{
			if (id != 0)
			{
				PreparedStatement* stmt = NULL;
				stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_QUESTCOMPLETER);
				stmt->setUInt32(0, id);
				LoginDatabase.Execute(stmt);
				handler->PSendSysMessage("Quest was added!");
			}
			else
				handler->PSendSysMessage("There was a error with your request.");
		}
		return true;
	}
	static bool HandleQuestCompleterDelCommand(ChatHandler* handler, char const* args)
	{
		char* quest = handler->extractKeyFromLink((char*)args, "Hquest");
		if (!quest)
		{
			handler->PSendSysMessage("Please enter a quest link.");
			handler->SetSentErrorMessage(true);
			return false;
		}
		// Change from string to int to prevent crash with query
		uint32 id = atol(quest);
		QueryResult QCSearch = LoginDatabase.PQuery("SELECT COUNT(id) FROM quest_completer WHERE id = %i", id);
		Field* fields = QCSearch->Fetch();

		if (fields[0].GetUInt32() == 0)
			handler->PSendSysMessage("Quest not in list!");
		else
		{
			if (id != 0)
			{
				PreparedStatement* stmt = NULL;
				stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_QUESTCOMPLETER);
				stmt->setUInt32(0, id);
				LoginDatabase.Execute(stmt);
				handler->PSendSysMessage("Quest was removed!");
			}
			else
				handler->PSendSysMessage("There was a error with your request.");
		}
		return true;
        }
        //Added a way to see if a player is on a different character without having to pinfo/lookup all toons on the account
        static bool HandleOnlineAccountCommand(ChatHandler* handler, char const* args)
        {
            if (!*args)
                return false;

            std::string account = strtok((char*)args, " ");
            char* limitStr = strtok(NULL, " ");
            int32 limit = limitStr ? atoi(limitStr) : -1;

            if (!AccountMgr::normalizeString(account))
                return false;

            PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_LIST_BY_ONLINE_NAME);
            stmt->setString(0, account);
            PreparedQueryResult result = LoginDatabase.Query(stmt);

            return OnlineSearchCommand(result, limit, handler);
        }

        //Using the same way as above but using a character name to get the account id
        static bool HandleOnlineCharacterCommand(ChatHandler* handler, char const* args)
        {
            if (!*args)
                return false;

            char* name = strtok((char*)args, " ");
            char* limitStr = strtok(NULL, " ");
            int32 limit = limitStr ? atoi(limitStr) : -1;
            name[0] = toupper(name[0]);
            uint32 account = 0;
            account = AccountMgr::GetId(name);
            PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_LIST_BY_ONLINE_ID);
            stmt->setUInt32(0, account);
            PreparedQueryResult result = LoginDatabase.Query(stmt);
            return OnlineSearchCommand(result, limit, handler);
        }

        static bool OnlineSearchCommand(PreparedQueryResult result, int32 limit, ChatHandler* handler)
        {
            if (!result)
            {
                handler->PSendSysMessage("Player is not online!");
                handler->SetSentErrorMessage(true);
                return false;
            }

            int32 counter = 0;
            uint32 count = 0;
            uint32 maxResults = sWorld->getIntConfig(CONFIG_MAX_RESULTS_LOOKUP_COMMANDS);

            do
            {
                if (maxResults && count++ == maxResults)
                {
                    handler->PSendSysMessage("LOOKUP MAX RESULT: %i", maxResults);
                    return true;
                }

                Field* fields           = result->Fetch();
                uint32 accountId        = fields[0].GetUInt32();
                std::string accountName = fields[1].GetString();

                PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_GUID_NAME_BY_ONLINE);
                stmt->setUInt32(0, accountId);
                PreparedQueryResult result2 = CharacterDatabase.Query(stmt);

                if (result2)
                {
                    handler->PSendSysMessage("Looking up Account: %s [id: %i]", accountName.c_str(), accountId);

                    do
                    {
                        Field* characterFields  = result2->Fetch();
                        uint32 guid             = characterFields[0].GetUInt32();
                        std::string name        = characterFields[1].GetString();

                        handler->PSendSysMessage("Character: %s [guid: %i] is online.", name.c_str(), guid);
                        ++counter;
                    }
                    while (result2->NextRow() && (limit == -1 || counter < limit));
                }
            }
            while (result->NextRow());

            if (counter == 0) // empty accounts only
            {
                handler->PSendSysMessage("Player is not online!");
                handler->SetSentErrorMessage(true);
                return false;
            }

            return true;
        }
};

void AddSC_custom_commandscript()
{
    new custom_commandscript();
}
