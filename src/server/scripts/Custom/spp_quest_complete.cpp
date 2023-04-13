//#include "ScriptMgr.h"
//#include "Chat.h"
//#include "DatabaseEnv.h"
//#include "DB2Stores.h"
//#include "ObjectMgr.h"
//#include "Player.h"
//#include "RBAC.h"
//#include "ReputationMgr.h"
//#include "World.h"
//#include "Config.h"
//
//
//class quest_complete_command : public CommandScript
//{
//public:
//    quest_complete_command() : CommandScript("quest_complete_command") { }
//
//    std::vector<ChatCommand> GetCommands() const override
//    {
//        if (sConfigMgr->GetBoolDefault("CompleteQuest.Command", false))
//        {
//            static std::vector<ChatCommand> HandleWorldChatCommandTable =
//            {
//                //{ "completequest",  rbac::RBAC_PERM_COMMAND_COMPLETE_QUEST_COMMAND, true, &HandleQuestCompleteCommand, "" },
//            };
//            return HandleWorldChatCommandTable;
//        }
//    }
//
//    static bool HandleQuestCompleteCommand(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->getSelectedPlayerOrSelf();
//        if (!player)
//        {
//            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
//            handler->SetSentErrorMessage(true);
//            return false;
//        }
//
//        // .quest complete #entry
//        // number or [name] Shift-click form |color|Hquest:quest_id:quest_level|h[name]|h|r
//        char* cId = handler->extractKeyFromLink((char*)args, "Hquest");
//        if (!cId)
//            return false;
//
//        uint32 entry = atoul(cId);
//
//        Quest const* quest = sObjectMgr->GetQuestTemplate(entry);
//
//        // If player doesn't have the quest
//        if (!quest || player->GetQuestStatus(entry) == QUEST_STATUS_NONE)
//        {
//            handler->PSendSysMessage(LANG_COMMAND_QUEST_NOTFOUND, entry);
//            handler->SetSentErrorMessage(true);
//            return false;
//        }
//
//        if (sWorld->getBoolConfig(CONFIG_QUEST_ENABLE_QUEST_TRACKER)) // check if Quest Tracker is enabled
//        {
//            // prepare Quest Tracker datas
//            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_QUEST_TRACK_GM_COMPLETE);
//            stmt->setUInt32(0, quest->GetQuestId());
//            stmt->setUInt64(1, player->GetGUID().GetCounter());
//
//            // add to Quest Tracker
//            CharacterDatabase.Execute(stmt);
//        }
//
//        player->CompleteQuest(entry);//ForceCompleteQuest
//        return true;
//    }
//};
//
//void AddSC_quest_complete_command()
//{
//    new quest_complete_command();
//}
