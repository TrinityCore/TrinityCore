//来源:https://github.com/openlcoreteam/OpenLCore/blob/master/src/server/scripts/Custom/quest_conversation.cpp
#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "World.h"
#include "Conversation.h"
#include "DatabaseEnv.h"
#include "Log.h"

// Structure Quest Conversation
//还不清楚这个脚本是干嘛的,字面意思是任务对话
//这货启用,会使服务端启动不了,千万别启用,谨记!
struct QuestConversation
{
    QuestConversation(uint32 questId, uint32 questAcceptConversation, uint32 questCompleteConversation) :
        QuestId(questId), QuestAcceptConversation(questAcceptConversation), QuestCompleteConversation(questCompleteConversation) { }
    uint32      QuestId;
    uint32      QuestAcceptConversation;
    uint32      QuestCompleteConversation;
};
typedef std::unordered_map<uint32, QuestConversation*> QuestConversationMap;
QuestConversationMap _QuestConversations;
///struct QuestConversation;


class quest_conversation : public PlayerScript
{
public:
    quest_conversation() : PlayerScript("quest_conversation") { }

    // Called when player accepts some quest
    void OnQuestAccept(Player* player, Quest const* quest)
    {
        CheckConversationByQuestId(player, quest->GetQuestId(), true);
    }

    // Called when player completes some quest
    void OnQuestComplete(Player* player, Quest const* quest)
    {
        CheckConversationByQuestId(player, quest->GetQuestId(), false);
    }

    QuestConversation* GetQuestConversation(uint32 questId)
    {
        if (_QuestConversations.find(questId) == _QuestConversations.end())
            return nullptr;

        return _QuestConversations.find(questId)->second;
    }

    void CheckConversationByQuestId(Player* player, uint32 quest, bool isaccept)
    {
        QuestConversation* qc = GetQuestConversation(quest);
        if (qc)
        {
            uint32 conversationEntry = 0;
            if (isaccept)
            {
                conversationEntry = qc->QuestAcceptConversation;
            }
            else
            {
                conversationEntry = qc->QuestCompleteConversation;
            }

            if (conversationEntry > 0)
                Conversation::CreateConversation(conversationEntry, player, *player, { player->GetGUID() });
        }

    }
};





void LoadQuestConversation(void)
{
    // For reload case
    for (QuestConversationMap::const_iterator itr = _QuestConversations.begin(); itr != _QuestConversations.end(); ++itr)
        delete itr->second;

    const char* Table[] =
    {
        "quest_conversation",
    };

    QueryResult result = WorldDatabase.PQuery(
        "SELECT `questId`, `questAcceptConversation`, `questCompleteConversation` "
        //          0                   1                       2        
        "FROM `%s` ", Table[0]);


    uint32 nbQC = 0;
    _QuestConversations.clear();

    if (result)
    {
        TC_LOG_INFO("server.loading", "Loading %s ...", Table[0]);
        // barGoLink bar(result->GetRowCount());

        do
        {
            // bar.step();
            Field* fields = result->Fetch();

            uint32 questId = fields[0].GetUInt32();
            //uint32 questAcceptConversation = 0;
            //uint32 questCompleteConversation = 0;

            QuestConversation* questConversation = new QuestConversation(questId, fields[1].GetUInt32(), fields[2].GetUInt32());
            _QuestConversations[questId] = questConversation;

            ++nbQC;
        } while (result->NextRow());

        TC_LOG_INFO("server.loading", " ");
        TC_LOG_INFO("server.loading", "Loaded %u quest_conversation.", nbQC);
    }
    else TC_LOG_ERROR("misc", "WARNING >> Loaded 0 quest_conversation.");
}


void AddSC_quest_conversation()
{
    new quest_conversation();
    LoadQuestConversation();
}
