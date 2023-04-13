//#include "Chat.h"
//#include "CollectionMgr.h"
//#include "DatabaseEnv.h"
//#include "MapManager.h"
//#include "QuestData.h"
//#include "ScriptMgr.h"
//#include "ScriptedCreature.h"
//#include "ScriptedGossip.h"
//
//
//enum Data
//{
//    DB_MENU_ID = 600023,
//    DB_GOSSIP = 300000,
//
//    fishing = 356,
//    firstaid = 129,
//    cooking = 185,
//    archaeology = 794,
//};
//
//class npc_quest_restore : public CreatureScript
//{
//public:
//    npc_quest_restore() : CreatureScript("npc_quest_restore") {}
//
//    bool OnGossipHello(Player* player, Creature* creature)  override
//    {
//        LocaleConstant localeConstant = player->GetSession()->GetSessionDbLocaleIndex();
//
//        player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_INTERACT_1, sObjectMgr->GetTrinityString(600023, localeConstant), GOSSIP_SENDER_MAIN, 1, "", 0, true);
//        player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_INTERACT_1, sObjectMgr->GetTrinityString(600024, localeConstant), GOSSIP_SENDER_MAIN, 2, "", 1, true);
//        player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_INTERACT_1, sObjectMgr->GetTrinityString(600029, localeConstant), GOSSIP_SENDER_MAIN, 3, "", 1, true);
//
//        player->ADD_GOSSIP_ITEM_DB(DB_MENU_ID, 3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
//        player->ADD_GOSSIP_ITEM_DB(DB_MENU_ID, 4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
//        player->ADD_GOSSIP_ITEM_DB(DB_MENU_ID, 5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
//
//        player->SEND_GOSSIP_MENU(DB_GOSSIP, creature->GetGUID());
//        return true;
//    }
//
//    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)  override
//    {
//        player->PlayerTalkClass->ClearMenus();
//
//        switch (action)
//        {
//        case GOSSIP_ACTION_INFO_DEF + 1:
//        {
//            if (player->getLevel() <= 101)
//                return false;
//            ObjectGuid::LowType lowGuid = player->GetGUIDLow();
//            sMapMgr->SetUnloadGarrison(lowGuid);
//            uint32 id = player->GetTeam() == HORDE ? 71 : 2;
//            player->SaveToDB();
//            player->GetSession()->KickPlayer();
//
//            creature->AddDelayedEvent(1000, [this, lowGuid, id]() -> void
//                {
//                    SQLTransaction trans = CharacterDatabase.BeginTransaction();
//
//                    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_GARRISON_ONLY);
//                    stmt->setUInt64(0, lowGuid);
//                    trans->Append(stmt);
//
//                    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_GARRISON_BLUEPRINTS);
//                    stmt->setUInt64(0, lowGuid);
//                    trans->Append(stmt);
//
//                    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_GARRISON_BUILDINGS);
//                    stmt->setUInt64(0, lowGuid);
//                    trans->Append(stmt);
//
//                    trans->PAppend("insert into `character_reward` (`id`, `type`, `owner_guid`)value ('%u','10', '%u')", id, lowGuid);
//
//                    CharacterDatabase.CommitTransaction(trans);
//                });
//        }
//        break;
//        case GOSSIP_ACTION_INFO_DEF + 2:
//        {
//            ChatHandler(player).PSendSysMessage(600225);
//        }
//        break;
//        case GOSSIP_ACTION_INFO_DEF + 3:
//        {
//            switch (player->getClass())
//            {
//            case CLASS_WARRIOR:
//                QuestCheckAndComplete(player, 42605, 42606, 42598, 0);
//                break;
//            case CLASS_PALADIN:
//                QuestCheckAndComplete(player, 42881, 42881, 42846, 42846);
//                break;
//            case CLASS_HUNTER:
//                QuestCheckAndComplete(player, 40957, 42409, 42519, 0);
//                break;
//            case CLASS_ROGUE:
//                QuestCheckAndComplete(player, 43262, 43261, 42139, 0);
//                break;
//            case CLASS_PRIEST:
//                QuestCheckAndComplete(player, 43271, 43272, 43270, 0);
//                break;
//            case CLASS_DEATH_KNIGHT:
//                QuestCheckAndComplete(player, 39816, 39818, 43264, 0);
//                break;
//            case CLASS_SHAMAN:
//                QuestCheckAndComplete(player, 42197, 42198, 42383, 0);
//                break;
//            case CLASS_MAGE:
//                QuestCheckAndComplete(player, 42662, 42685, 42663, 0);
//                break;
//            case CLASS_WARLOCK:
//                QuestCheckAndComplete(player, 41748, 41750, 42608, 0);
//                break;
//            case CLASS_MONK:
//                QuestCheckAndComplete(player, 41115, 40704, 42187, 0);
//                break;
//            case CLASS_DRUID:
//                QuestCheckAndComplete(player, 42096, 40650, 42583, 0);
//                break;
//            case CLASS_DEMON_HUNTER:
//                QuestCheckAndComplete(player, 42695, 42697, 42671, 0);
//                break;
//            }
//            break;
//        }
//        }
//
//        player->CLOSE_GOSSIP_MENU();
//        return true;
//    }
//
//    bool OnGossipSelectCode(Player* player, Creature* creature, uint32 /*sender*/, uint32 action, const char* code) override
//    {
//        player->PlayerTalkClass->ClearMenus();
//
//        switch (action)
//        {
//        case 1:
//        {
//            questID = atol(code);
//
//            if (player->GetQuestStatus(questID) == QUEST_STATUS_REWARDED)
//            {
//                player->UpdateAchievementCriteria(CRITERIA_TYPE_COMPLETE_QUEST, questID);
//                ChatHandler(player).PSendSysMessage("Quest %u has been recompleted in achievement progress for your character.", questID);
//            }
//            else
//                ChatHandler(player).PSendSysMessage("You doesn't have saved quest %u on this character.", questID);
//
//            break;
//        }
//        case 2:
//        {
//            achievementID = atol(code);
//
//            if (AchievementEntry const* achiev = sAchievementStore.LookupEntry(achievementID))
//            {
//                if (player->GetAchievementMgr()->IsCompletedAchievement(achiev, player))
//                {
//                    player->CompletedAchievement(achiev);
//                    ChatHandler(player).PSendSysMessage("Achievement %u has been completed for your character.", achievementID);
//                }
//                else
//                    ChatHandler(player).PSendSysMessage("You doesn't have requried conditions for achievement: %u. Or have it already.", achievementID);
//            }
//            else
//                ChatHandler(player).PSendSysMessage("Incorrect achievement or criteria ID.");
//
//            if (achievementID >= 16000)
//            {
//                if (player->HasSpell(achievementID))
//                    player->UpdateAchievementCriteria(CRITERIA_TYPE_LEARN_SPELL, achievementID);
//            }
//
//            uint32 speciesID = 0;
//            if (auto speciesInfo = sDB2Manager.GetSpeciesByCreatureID(achievementID))
//            {
//                speciesID = speciesInfo->ID;
//                if (player->GetBattlePetCountForSpecies(speciesID))
//                    player->UpdateAchievementCriteria(CRITERIA_TYPE_ADD_BATTLE_PET_JOURNAL, achievementID);
//            }
//
//            if (achievementID == 10000)
//            {
//                if (auto skill = player->GetBaseSkillValue(fishing))
//                    player->UpdateAchievementCriteria(CRITERIA_TYPE_REACH_SKILL_LEVEL, fishing);
//
//                if (auto skill = player->GetBaseSkillValue(firstaid))
//                    player->UpdateAchievementCriteria(CRITERIA_TYPE_REACH_SKILL_LEVEL, firstaid);
//
//                if (auto skill = player->GetBaseSkillValue(cooking))
//                    player->UpdateAchievementCriteria(CRITERIA_TYPE_REACH_SKILL_LEVEL, cooking);
//
//                if (auto skill = player->GetBaseSkillValue(archaeology))
//                    player->UpdateAchievementCriteria(CRITERIA_TYPE_REACH_SKILL_LEVEL, archaeology);
//            }
//
//            break;
//        }
//        case 3:
//        {
//            mountSpell = atol(code);
//
//            auto accountId = player->GetSession()->GetAccountId();
//
//            QueryResult result = CharacterDatabase.PQuery("SELECT spell FROM account_mounts WHERE account = %u and spell = %u", accountId, mountSpell);
//            if (result)
//            {
//                player->removeSpell(mountSpell, false);
//                player->learnSpell(mountSpell, false);
//                ChatHandler(player).PSendSysMessage(600031);
//            }
//            break;
//        }
//        }
//        return OnGossipHello(player, creature);
//    }
//
//private:
//    uint32 questID = 0;
//    uint32 achievementID = 0;
//    uint32 mountSpell = 0;
//
//    bool QuestCheckAndComplete(Player* player, uint32 checkId1, uint32 checkId2, uint32 completeId1, uint32 completeId2)
//    {
//        if (checkId1)
//        {
//            if (player->GetQuestStatus(checkId1) != QUEST_STATUS_REWARDED)
//                return false;
//        }
//        if (checkId2)
//        {
//            if (player->GetQuestStatus(checkId2) != QUEST_STATUS_REWARDED)
//                return false;
//        }
//
//        player->CompleteQuest(completeId1);
//        player->CompleteQuest(completeId2);
//        return true;
//    }
//};
//
//
//void AddSC_npc_quest_giver()
//{
//    new npc_quest_restore();
//}
