///* ------------------------------------ */
///* AUTHOR   Azgath                      */
///*    FOR   Az'gath Private Server      */
///* ------------------------------------ */
//
//#include "ScriptMgr.h"
//#include "Chat.h"
//#include "DatabaseEnv.h"
//#include "DB2Stores.h"
//#include "ObjectMgr.h"
//#include "Player.h"
//#include "RBAC.h"
//#include "ReputationMgr.h"
//#include "World.h"
//#include "WorldSession.h"
//
//class azgath_legit_quest_bypass : public CommandScript
//{
//public:
//    azgath_legit_quest_bypass() : CommandScript("azgath_legit_quest_bypass") { }
//
//    std::vector<ChatCommand> GetCommands() const override
//    {
//        static std::vector<ChatCommand> commandTable =
//        {
//            { "bypass",          rbac::RBAC_PERM_COMMAND_QUEST_BYPASS,   true,  &HandleBypassQuestCommand,     ""       },
//            { "report",          rbac::RBAC_PERM_COMMAND_QUEST_BYPASS,   true,  &HandleReportQuestCommand,     ""       },
//        };
//        return commandTable;
//    }
//
//    static bool HandleBypassQuestCommand(ChatHandler* handler, char const* args)
//    {
//        Player* player = handler->GetSession()->GetPlayer();
//
//        if (!player)
//        {
//            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
//            handler->SetSentErrorMessage(true);
//            return false;
//        }
//
//        // .quest complete #entry
//        // number or [name] Shift-click form |color|Hquest:quest_id:quest_level:min_level:max_level:scaling_faction|h[name]|h|r
//        char* cId = handler->extractKeyFromLink((char*)args, "Hquest");
//        if (!cId)
//            return false;
//
//        uint32 entry = atoul(cId);
//
//        Quest const* quest = sObjectMgr->GetQuestTemplate(entry);
//
//        // Check if the linked quest is an bypassable quest by the player
//        QueryResult checkQuest = WorldDatabase.PQuery("SELECT * FROM quest_bypass WHERE questId = %u AND bypass = '1'", quest->GetQuestId());
//        if (!checkQuest) {
//            handler->PSendSysMessage("The quest you are trying to bypass is not in our database.");
//            handler->PSendSysMessage("If you think this is an bugged quest, please report it to our bugtracker or our Discord.");
//            handler->PSendSysMessage("Thanks for you report.");
//
//            return true;
//        }
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
//            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_QUEST_TRACK_GM_COMPLETE);
//            stmt->setUInt32(0, quest->GetQuestId());
//            stmt->setUInt64(1, player->GetGUID().GetCounter());
//
//            // add to Quest Tracker
//            CharacterDatabase.Execute(stmt);
//        }
//
//        player->ForceCompleteQuest(entry);
//        return true;
//    }
//
//    static bool HandleReportQuestCommand(ChatHandler* handler, char const* args)
//    {
//        char* cId = handler->extractKeyFromLink((char*)args, "Hquest");
//        if (!cId)
//            return false;
//
//        uint32 entry = atoul(cId);
//        Quest const* quest = sObjectMgr->GetQuestTemplate(entry);
//        uint32 questId = quest->GetQuestId();
//
//        /* Check if the quest is already bypassable. */
//        QueryResult checkQuest = WorldDatabase.PQuery("SELECT * FROM quest_bypass WHERE questId = %u AND bypass = '1'", questId);
//        if (checkQuest) {
//            handler->PSendSysMessage("This quest is an already bypassable quest.");
//            return true;
//        }
//
//        /* Check if the quest is already reported. */
//        QueryResult checkQuest2 = WorldDatabase.PQuery("SELECT * FROM quest_report WHERE questId = %u", questId);
//        if (checkQuest2) {
//            handler->PSendSysMessage("The quest ID: %u has already been reported. Thanks you. :)", questId);
//            return true;
//        }
//
//        /* Insert into the quest_report table. */
//        QueryResult reportQuest = WorldDatabase.PQuery("INSERT INTO quest_report (`questId`, `questName`) VALUES (%u, \"%s\")", questId, quest->GetLogTitle());
//        if (!reportQuest) {
//            handler->PSendSysMessage("The quest ID: %u has been sucessfully reported. Thanks you for your report.", questId);
//            return true;
//        }
//        else {
//            handler->PSendSysMessage("Your report got an problem. Please contact the Az'gath staff for help.");
//            return true;
//        }
//
//        return true;
//    }
//};
//
//void AddSC_azgath_legit_quest_bypass() {
//    new azgath_legit_quest_bypass();
//}
