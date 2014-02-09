/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
%Complete: 90 will never complete
Comment: commandscript for custom commands
Category: Scripts
EndScriptData */

#include "Chat.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ReputationMgr.h"
#include "MapManager.h"
#include "Group.h"
#include "ScriptMgr.h"

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
                { "",                 rbac::RBAC_PERM_COMMAND_QUESTCOMPLETER_STATUS,  true, &HandleQuestCompleterStatusCommand,  "", NULL },
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
                { "mutehistory",     rbac::RBAC_PERM_COMMAND_MUTEHISTORY,             true,  &HandleMuteInfoCommand,             "", NULL },
                { NULL,              0,                                               false, NULL,                               "", NULL }
            };
            return commandTable;
        }
        
        static bool HandleMuteInfoCommand(ChatHandler* handler, char const* args)
        {
            if (!*args)
                return false;

            char* nameStr = strtok((char*)args, "");
            if (!nameStr)
                return false;

            std::string accountName = nameStr;
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
                return true;
            }

            return HandleMuteInfoHelper(accountId, accountName.c_str(), handler);
        }

        static bool HandleMuteInfoHelper(uint32 accountId, char const* accountName, ChatHandler* handler)
        {
            QueryResult result = LoginDatabase.PQuery("SELECT FROM_UNIXTIME(mutedate), mutetime, mutereason, mutedby FROM account_muted WHERE guid = '%u' ORDER BY mutedate ASC", accountId);
            if (!result)
            {
                handler->PSendSysMessage("No mutes for account: %s", accountName);
                return true;
            }

            handler->PSendSysMessage("Mutes for account: %s", accountName);
            do
            {
                Field* fields = result->Fetch();

                bool active = false;
                handler->PSendSysMessage("Mute Date: %s Mutetime: %u Reason: %s Set by: %s",
                    fields[0].GetCString(), fields[1].GetUInt32(), fields[2].GetCString(), fields[3].GetCString());
            }
            while (result->NextRow());

            return true;
        }
        static bool HandleQuestCompleterCompHelper(Player* player, uint32 entry, ChatHandler* handler)
        {
            // actual code for completing
            Quest const* quest = sObjectMgr->GetQuestTemplate(entry);
            
            //If player doesnt have the quest
            if(!quest || player->GetQuestStatus(entry) == QUEST_STATUS_NONE)
            {
                handler->PSendSysMessage("Quest not in your quest log.");
                handler->SetSentErrorMessage(true);
                return false;
            }
            
            // Add quest items for quests that require items
            for(uint8 x = 0; x < QUEST_ITEM_OBJECTIVES_COUNT; ++x)
            {
                uint32 id = quest->RequiredItemId[x];
                uint32 count = quest->RequiredItemCount[x];
                if(!id || !count)
                    continue;
                    
                uint32 curItemCount = player->GetItemCount(id, true);
              
                ItemPosCountVec dest;
                uint8 msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, id, count-curItemCount);
                if (msg == EQUIP_ERR_OK)
                {
                    Item* item = player->StoreNewItem(dest, id, true);
                    player->SendNewItem(item, count-curItemCount, true, false);
                }
            }
                
            // All creature/GO slain/cast (not required, but otherwise it will display "Creature slain 0/10")
            for (uint8 i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
            {
                int32 creature = quest->RequiredNpcOrGo[i];
                uint32 creatureCount = quest->RequiredNpcOrGoCount[i];

                if (creature > 0)
                {
                    if (CreatureTemplate const* creatureInfo = sObjectMgr->GetCreatureTemplate(creature))
                        for (uint16 z = 0; z < creatureCount; ++z)
                            player->KilledMonster(creatureInfo, 0);
                }
                else if (creature < 0)
                    for (uint16 z = 0; z < creatureCount; ++z)
                        player->KillCreditGO(creature, 0);
            }
            // If the quest requires reputation to complete
            if (uint32 repFaction = quest->GetRepObjectiveFaction())
            {
                uint32 repValue = quest->GetRepObjectiveValue();
                uint32 curRep = player->GetReputationMgr().GetReputation(repFaction);
                if (curRep < repValue)
                    if (FactionEntry const* factionEntry = sFactionStore.LookupEntry(repFaction))
                        player->GetReputationMgr().SetReputation(factionEntry, repValue);
            }

            // If the quest requires a SECOND reputation to complete
            if (uint32 repFaction = quest->GetRepObjectiveFaction2())
            {
                uint32 repValue2 = quest->GetRepObjectiveValue2();
                uint32 curRep = player->GetReputationMgr().GetReputation(repFaction);
                if (curRep < repValue2)
                    if (FactionEntry const* factionEntry = sFactionStore.LookupEntry(repFaction))
                        player->GetReputationMgr().SetReputation(factionEntry, repValue2);
            }

            // If the quest requires money
            int32 ReqOrRewMoney = quest->GetRewOrReqMoney();
            if (ReqOrRewMoney < 0)
                player->ModifyMoney(-ReqOrRewMoney);

            player->CompleteQuest(entry);
            return true;
        }
        
        static bool HandleQuestCompleterStatusCommand(ChatHandler* handler, char const* args)
        {
            char* cId = handler->extractKeyFromLink((char*)args, "Hquest");

            if(!cId)
            {
                handler->PSendSysMessage("Syntax: .qc $quest\n\nSearches Quest Completer to see if $quest is bugged.");
                handler->SetSentErrorMessage(true);
                return false;
            }

            uint32 entry = atol(cId);
            Quest const* quest = sObjectMgr->GetQuestTemplate(entry);
            if (!quest)
            {
                handler->PSendSysMessage("Please enter a quest link.");
                handler->SetSentErrorMessage(true);
                return false;
            }
            else
            {
                if(entry != 0)
                {
                    uint32 checked = 0;
                    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_QUESTCOMPLETER);
                    stmt->setUInt32(0, entry);
                    PreparedQueryResult resultCheck = LoginDatabase.Query(stmt);

                    if (!resultCheck)
                    {
                        handler->PSendSysMessage("Error: no results.");
                    }

                    checked = (*resultCheck)[0].GetUInt32();

                    if(checked == 1)
                    {
                        handler->PSendSysMessage("Bugged quest completed!");
                        std::string name;
                        const char* playerName = handler->GetSession() ? handler->GetSession()->GetPlayer()->GetName().c_str() : NULL;
                        //const char* playerName = handler->GetSession()->GetPlayer()->GetName().c_str();
                        if(playerName)
                        {
                            name = playerName;
                            normalizePlayerName(name);
                            Player* player = sObjectAccessor->FindPlayerByName(name);
                            HandleQuestCompleterCompHelper(player, entry, handler);
                            
                        }
                    }
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
            char* cId = handler->extractKeyFromLink((char*)args, "Hquest");

            if(!cId)
            {
                handler->PSendSysMessage("Syntax: .qc add $quest\n\nAdds $quest to the quest completer.");
                handler->SetSentErrorMessage(true);
                return false;
            }
            
            uint32 entry = atol(cId);
            Quest const* quest = sObjectMgr->GetQuestTemplate(entry);
            if (!quest)
            {
                handler->PSendSysMessage("Please enter a quest link.");
                handler->SetSentErrorMessage(true);
                return false;
            }
            
            // Change from string to int to prevent crash with query
            uint32 checked = 0;
            PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_QUESTCOMPLETER);
            stmt->setUInt32(0, entry);
            PreparedQueryResult resultCheck = LoginDatabase.Query(stmt);

            if (!resultCheck)
            {
                handler->PSendSysMessage("Error: no results.");
            }

            checked = (*resultCheck)[0].GetUInt32();

            if (checked == 1)
                handler->PSendSysMessage("Quest is already added!");
            else
            {
                if (entry != 0)
                {
                    PreparedStatement* stmt = NULL;
                    stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_QUESTCOMPLETER);
                    stmt->setUInt32(0, entry);
                    LoginDatabase.Execute(stmt);
                    handler->PSendSysMessage("Quest %u was added!", entry);
                }
                else
                    handler->PSendSysMessage("There was a error with your request.");
            }
            return true;
        }

        static bool HandleQuestCompleterDelCommand(ChatHandler* handler, char const* args)
        {
            char* cId = handler->extractKeyFromLink((char*)args, "Hquest");

            if(!cId)
            {
                handler->PSendSysMessage("Syntax: .qc del $quest\n\nDeletes $quest from the quest completer.");
                handler->SetSentErrorMessage(true);
                return false;
            }
            
            uint32 entry = atol(cId);
            Quest const* quest = sObjectMgr->GetQuestTemplate(entry);
            if (!quest)
            {
                handler->PSendSysMessage("Please enter a quest link.");
                handler->SetSentErrorMessage(true);
                return false;
            }
            
            // Change from string to int to prevent crash with query
            uint32 checked = 0;
            PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_QUESTCOMPLETER);
            stmt->setUInt32(0, entry);
            PreparedQueryResult resultCheck = LoginDatabase.Query(stmt);

            if (!resultCheck)
            {
                handler->PSendSysMessage("Error: no results.");
            }

            checked = (*resultCheck)[0].GetUInt32();

            if (checked == 0)
                handler->PSendSysMessage("Quest not in list!");
            else
            {
                if (entry != 0)
                {
                    PreparedStatement* stmt = NULL;
                    stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_QUESTCOMPLETER);
                    stmt->setUInt32(0, entry);
                    LoginDatabase.Execute(stmt);
                    handler->PSendSysMessage("Quest %u was removed!", entry);
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
