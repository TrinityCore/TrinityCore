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
Name: quest_commandscript
%Complete: 100
Comment: All quest related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "Chat.h"
#include "ChatCommand.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "DisableMgr.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "RBAC.h"
#include "ReputationMgr.h"
#include "World.h"

#if TRINITY_COMPILER == TRINITY_COMPILER_GNU
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

using namespace Trinity::ChatCommands;

class quest_commandscript : public CommandScript
{
public:
    quest_commandscript() : CommandScript("quest_commandscript") { }

    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable objectiveCommandTable =
        {
            { "complete", HandleQuestObjectiveComplete, rbac::RBAC_PERM_COMMAND_QUEST_OBJECTIVE_COMPLETE, Console::No }
        };
        static ChatCommandTable questCommandTable =
        {
            { "add",        HandleQuestAdd,         rbac::RBAC_PERM_COMMAND_QUEST_ADD,      Console::No },
            { "complete",   HandleQuestComplete,    rbac::RBAC_PERM_COMMAND_QUEST_COMPLETE, Console::No },
            { "objective",  objectiveCommandTable },
            { "remove",     HandleQuestRemove,      rbac::RBAC_PERM_COMMAND_QUEST_REMOVE,   Console::No },
            { "reward",     HandleQuestReward,      rbac::RBAC_PERM_COMMAND_QUEST_REWARD,   Console::No },
        };
        static ChatCommandTable commandTable =
        {
            { "quest", questCommandTable }
        };
        return commandTable;
    }

    static bool HandleQuestAdd(ChatHandler* handler, char const* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // .addquest #entry'
        // number or [name] Shift-click form |color|Hquest:quest_id:quest_level:min_level:max_level:scaling_faction|h[name]|h|r
        char* cId = handler->extractKeyFromLink((char*)args, "Hquest");
        if (!cId)
            return false;

        uint32 entry = atoul(cId);

        Quest const* quest = sObjectMgr->GetQuestTemplate(entry);

        if (!quest || DisableMgr::IsDisabledFor(DISABLE_TYPE_QUEST, entry, nullptr))
        {
            handler->PSendSysMessage(LANG_COMMAND_QUEST_NOTFOUND, entry);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check item starting quest (it can work incorrectly if added without item in inventory)
        ItemTemplateContainer const& itc = sObjectMgr->GetItemTemplateStore();
        auto itr = std::find_if(std::begin(itc), std::end(itc), [quest](ItemTemplateContainer::value_type const& value)
        {
            return value.second.GetStartQuest() == quest->GetQuestId();
        });

        if (itr != std::end(itc))
        {
            handler->PSendSysMessage(LANG_COMMAND_QUEST_STARTFROMITEM, entry, itr->first);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (player->IsActiveQuest(entry))
            return false;

        // ok, normal (creature/GO starting) quest
        if (player->CanAddQuest(quest, true))
            player->AddQuestAndCheckCompletion(quest, nullptr);

        return true;
    }

    static bool HandleQuestRemove(ChatHandler* handler, char const* args)
    {
        Player* player = handler->getSelectedPlayer();
        if (!player)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // .removequest #entry'
        // number or [name] Shift-click form |color|Hquest:quest_id:quest_level:min_level:max_level:scaling_faction|h[name]|h|r
        char* cId = handler->extractKeyFromLink((char*)args, "Hquest");
        if (!cId)
            return false;

        uint32 entry = atoul(cId);

        Quest const* quest = sObjectMgr->GetQuestTemplate(entry);

        if (!quest)
        {
            handler->PSendSysMessage(LANG_COMMAND_QUEST_NOTFOUND, entry);
            handler->SetSentErrorMessage(true);
            return false;
        }

        QuestStatus oldStatus = player->GetQuestStatus(entry);

        if (player->GetQuestStatus(entry) != QUEST_STATUS_NONE)
        {
            // remove all quest entries for 'entry' from quest log
            for (uint8 slot = 0; slot < MAX_QUEST_LOG_SIZE; ++slot)
            {
                uint32 logQuest = player->GetQuestSlotQuestId(slot);
                if (logQuest == entry)
                {
                    player->SetQuestSlot(slot, 0);

                    // we ignore unequippable quest items in this case, its' still be equipped
                    player->TakeQuestSourceItem(logQuest, false);

                    if (quest->HasFlag(QUEST_FLAGS_FLAGS_PVP))
                    {
                        player->pvpInfo.IsHostile = player->pvpInfo.IsInHostileArea || player->HasPvPForcingQuest();
                        player->UpdatePvPState();
                    }
                }
            }
            player->RemoveActiveQuest(entry, false);
            player->RemoveRewardedQuest(entry);

            sScriptMgr->OnQuestStatusChange(player, entry);
            sScriptMgr->OnQuestStatusChange(player, quest, oldStatus, QUEST_STATUS_NONE);

            handler->SendSysMessage(LANG_COMMAND_QUEST_REMOVED);
            return true;
        }
        else
        {
            handler->PSendSysMessage(LANG_COMMAND_QUEST_NOTFOUND, entry);
            handler->SetSentErrorMessage(true);
            return false;
        }
    }

    static void CompleteObjective(Player* player, QuestObjective const& obj)
    {
        switch (obj.Type)
        {
            case QUEST_OBJECTIVE_ITEM:
            {
                uint32 curItemCount = player->GetItemCount(obj.ObjectID, true);
                ItemPosCountVec dest;
                uint8 msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, obj.ObjectID, obj.Amount - curItemCount);
                if (msg == EQUIP_ERR_OK)
                {
                    Item* item = player->StoreNewItem(dest, obj.ObjectID, true);
                    player->SendNewItem(item, obj.Amount - curItemCount, true, false);
                }
                break;
            }
            case QUEST_OBJECTIVE_MONSTER:
            {
                if (CreatureTemplate const* creatureInfo = sObjectMgr->GetCreatureTemplate(obj.ObjectID))
                    for (uint16 z = 0; z < obj.Amount; ++z)
                        player->KilledMonster(creatureInfo, ObjectGuid::Empty);
                break;
            }
            case QUEST_OBJECTIVE_GAMEOBJECT:
            {
                for (uint16 z = 0; z < obj.Amount; ++z)
                    player->KillCreditGO(obj.ObjectID);
                break;
            }
            case QUEST_OBJECTIVE_MIN_REPUTATION:
            {
                uint32 curRep = player->GetReputationMgr().GetReputation(obj.ObjectID);
                if (curRep < uint32(obj.Amount))
                    if (FactionEntry const* factionEntry = sFactionStore.LookupEntry(obj.ObjectID))
                        player->GetReputationMgr().SetReputation(factionEntry, obj.Amount);
                break;
            }
            case QUEST_OBJECTIVE_MAX_REPUTATION:
            {
                uint32 curRep = player->GetReputationMgr().GetReputation(obj.ObjectID);
                if (curRep > uint32(obj.Amount))
                    if (FactionEntry const* factionEntry = sFactionStore.LookupEntry(obj.ObjectID))
                        player->GetReputationMgr().SetReputation(factionEntry, obj.Amount);
                break;
            }
            case QUEST_OBJECTIVE_MONEY:
            {
                player->ModifyMoney(obj.Amount);
                break;
            }
            case QUEST_OBJECTIVE_PLAYERKILLS:
            {
                for (uint16 z = 0; z < obj.Amount; ++z)
                    player->KilledPlayerCredit(ObjectGuid::Empty);
                break;
            }
        }
    }

    static bool HandleQuestComplete(ChatHandler* handler, char const* args)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // .quest complete #entry
        // number or [name] Shift-click form |color|Hquest:quest_id:quest_level:min_level:max_level:scaling_faction|h[name]|h|r
        char* cId = handler->extractKeyFromLink((char*)args, "Hquest");
        if (!cId)
            return false;

        uint32 entry = atoul(cId);

        Quest const* quest = sObjectMgr->GetQuestTemplate(entry);

        // If player doesn't have the quest
        if (!quest || player->GetQuestStatus(entry) == QUEST_STATUS_NONE
            || DisableMgr::IsDisabledFor(DISABLE_TYPE_QUEST, entry, nullptr))
        {
            handler->PSendSysMessage(LANG_COMMAND_QUEST_NOTFOUND, entry);
            handler->SetSentErrorMessage(true);
            return false;
        }

        for (uint32 i = 0; i < quest->Objectives.size(); ++i)
        {
            QuestObjective const& obj = quest->Objectives[i];
            CompleteObjective(player, obj);
        }

        if (sWorld->getBoolConfig(CONFIG_QUEST_ENABLE_QUEST_TRACKER)) // check if Quest Tracker is enabled
        {
            // prepare Quest Tracker datas
            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_QUEST_TRACK_GM_COMPLETE);
            stmt->setUInt32(0, quest->GetQuestId());
            stmt->setUInt64(1, player->GetGUID().GetCounter());

            // add to Quest Tracker
            CharacterDatabase.Execute(stmt);
        }

        player->CompleteQuest(entry);
        return true;
    }

    static bool HandleQuestObjectiveComplete(ChatHandler* handler, uint32 objectiveId)
    {
        Player* player = handler->getSelectedPlayerOrSelf();
        if (!player)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        QuestObjective const* obj = sObjectMgr->GetQuestObjective(objectiveId);
        if (!obj)
        {
            handler->SendSysMessage(LANG_COMMAND_QUEST_OBJECTIVE_NOTFOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        CompleteObjective(player, *obj);
        return true;
    }

    static bool HandleQuestReward(ChatHandler* handler, char const* args)
    {
        Player* player = handler->getSelectedPlayer();
        if (!player)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // .quest reward #entry
        // number or [name] Shift-click form |color|Hquest:quest_id:quest_level:min_level:max_level:scaling_faction|h[name]|h|r
        char* cId = handler->extractKeyFromLink((char*)args, "Hquest");
        if (!cId)
            return false;

        uint32 entry = atoul(cId);

        Quest const* quest = sObjectMgr->GetQuestTemplate(entry);

        // If player doesn't have the quest
        if (!quest || player->GetQuestStatus(entry) != QUEST_STATUS_COMPLETE
            || DisableMgr::IsDisabledFor(DISABLE_TYPE_QUEST, entry, nullptr))
        {
            handler->PSendSysMessage(LANG_COMMAND_QUEST_NOTFOUND, entry);
            handler->SetSentErrorMessage(true);
            return false;
        }

        player->RewardQuest(quest, LootItemType::Item, 0, player);
        return true;
    }
};

void AddSC_quest_commandscript()
{
    new quest_commandscript();
}
