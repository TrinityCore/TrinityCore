
#include "PlayerBotTalkMgr.h"
#include "FieldBotMgr.h"
#include "World.h"
#include "Player.h"
#include "Chat.h"
#include "ChatPackets.h"
#include "Group.h"
#include "GuildMgr.h"
#include "Guild.h"

#include <fstream>

std::string BotTalkText::defauleText = "I said a word.";

void SplitText(std::string& s, std::string delim, std::vector< std::string >* ret)
{
    size_t last = 0;
    size_t index = s.find_first_of(delim, last);
    while (index != std::string::npos)
    {
        ret->push_back(s.substr(last, index - last));
        last = index + 1;
        index = s.find_first_of(delim, last);
    }
    if (index - last > 0)
    {
        ret->push_back(s.substr(last, index - last));
    }
}

bool BotTalkStory::ResolutionContent(std::string& text)
{
    std::vector< std::string > contents;
    SplitText(text, "&", &contents);
    uint32 count = contents.size();
    if (count == 0 || count % 2 != 0)
        return false;

    indexs.clear();
    texts.clear();
    for (uint32 i = 0; i < count; i += 2)
    {
        std::string& numberText = contents[i];
        int index = atoi(numberText.c_str());
        if (index <= 0)
            return false;
        indexs.push_back(index);
        texts.push_back(contents[i + 1]);
    }
    return true;
}

bool BotTalkStory::GetStoryByIndex(uint32 step, uint32& index, std::string& text)
{
    if (step >= indexs.size() || step >= texts.size())
        return false;
    index = indexs[step];
    text = texts[step];
    return true;
}

bool BotTalkStory::IsValidStep(uint32 step)
{
    if (step >= indexs.size() || step >= texts.size())
        return false;
    return true;
}

PlayerBotTalkMgr::PlayerBotTalkMgr() :
    m_CommonChannelMgr(ChannelMgr::ForTeam(ALLIANCE)),
    m_DefaultChannel(0),
    m_WorkTick(getMSTime()),
    m_NextRndTick(urand(2000, 10000))
{

}

PlayerBotTalkMgr::~PlayerBotTalkMgr()
{
}

PlayerBotTalkMgr* PlayerBotTalkMgr::instance()
{
    static PlayerBotTalkMgr instance;
    return &instance;
}

void PlayerBotTalkMgr::InitializeTalkText()
{
    uint32 oldMSTime = getMSTime();
    QueryResult result = WorldDatabase.Query("SELECT entry, talktype, subtype, text FROM bottalktext");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> PlayerBotTalkMgr InitializeTalkText Find 0 Text!");
        return;
    }

    uint32 talkCount = 0;
    m_BotTalkTypes.clear();
    do
    {
        Field* fields = result->Fetch();
        uint32 id = fields[0].GetUInt32();
        uint32 tType = fields[1].GetUInt32();
        uint32 sType = fields[2].GetUInt32();
        std::string text = fields[3].GetString();

        BotTalkType& botTalk = m_BotTalkTypes[tType];
        botTalk.entry = id;
        botTalk.talkType = tType;
        botTalk.AddBotTalk(sType, text);
        ++talkCount;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u Player bot talk text base info in %u ms", talkCount, GetMSTimeDiffToNow(oldMSTime));
}

void PlayerBotTalkMgr::InitializeStory()
{
    QueryResult result = WorldDatabase.Query("SELECT entry, story FROM talkstory");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> PlayerBotTalkMgr InitializeStory Find 0 Text!");
        return;
    }

    m_BotTalkStorys.clear();
    do
    {
        Field* fields = result->Fetch();
        uint32 id = fields[0].GetUInt32();
        std::string text = fields[1].GetString();

        BotTalkStory& story = m_BotTalkStorys[id];
        story.entry = id;
        if (!story.ResolutionContent(text))
            m_BotTalkStorys.erase(id);
    } while (result->NextRow());
}

uint32 PlayerBotTalkMgr::RandomStoryID()
{
    if (m_BotTalkStorys.empty())
        return -1;
    if (m_CanUseTalkStorys.empty())
    {
        for (BOT_TALKSTORYS::iterator itStory = m_BotTalkStorys.begin();
            itStory != m_BotTalkStorys.end();
            itStory++)
        {
            m_CanUseTalkStorys[itStory->first] = itStory->second;
        }
    }
    uint32 index = urand(0, m_CanUseTalkStorys.size() - 1);
    for (BOT_TALKSTORYS::iterator itStory = m_CanUseTalkStorys.begin();
        itStory != m_CanUseTalkStorys.end();
        itStory++)
    {
        if (index == 0)
        {
            return itStory->first;
        }
        --index;
    }
    return -1;
}

bool PlayerBotTalkMgr::GetStoryByIndex(uint32 id, uint32 step, uint32& index, std::string& text)
{
    BOT_TALKSTORYS::iterator itStory = m_CanUseTalkStorys.find(id);
    if (itStory == m_CanUseTalkStorys.end())
    {
        return false;
    }
    bool succ = itStory->second.GetStoryByIndex(step, index, text);
    if (!succ)
    {
        m_CanUseTalkStorys.erase(id);
    }
    return succ;
}

bool PlayerBotTalkMgr::IsValidStoryStep(uint32 id, uint32 step)
{
    BOT_TALKSTORYS::iterator itStory = m_CanUseTalkStorys.find(id);
    if (itStory == m_CanUseTalkStorys.end())
        return false;
    bool succ = itStory->second.IsValidStep(step);
    if (!succ)
    {
        m_CanUseTalkStorys.erase(id);
    }
    return succ;
}

std::string PlayerBotTalkMgr::GetDefaultChannelName()
{
    std::string defaultChannelName;
    consoleToUtf8(std::string("????"), defaultChannelName);
    return defaultChannelName;
}

void PlayerBotTalkMgr::JoinDefaultChannel(Player* player)
{
    //if (!m_DefaultChannel || m_DefaultChannel->IsOn(player->GetGUID()))
    //	return;
    m_DefaultChannel->JoinChannel(player, "");
}

void PlayerBotTalkMgr::WarfareActingTalk(uint32 sType, Player* player)
{
    if (!player || !MatchTalkTick())
        return;
    std::string& talkText = FindTalkText(TTT_Warfare, sType);
    uint32 rate = urand(0, 99);
    if (rate < 25 && player->IsAlive())
        player->Yell(talkText.c_str(), Language::LANG_UNIVERSAL);
    else
    {
        JoinDefaultChannel(player);
        m_DefaultChannel->Say(player->GetGUID(), talkText.c_str(), Language::LANG_UNIVERSAL);
    }
}

void PlayerBotTalkMgr::StoryActingTalk(Player* player, std::string& talkText)
{
    if (!player || talkText.empty())
        return;
    m_WorkTick = getMSTime();
    m_NextRndTick = urand(2000, 10000);
    JoinDefaultChannel(player);
    m_DefaultChannel->Say(player->GetGUID(), talkText.c_str(), Language::LANG_UNIVERSAL);
}

void PlayerBotTalkMgr::PlayerBotTalkByType(TALK_TTYPE tType, uint32 sType, Player* player)
{
    if (!player || !player->IsPlayerBot())
        return;
    if (!MatchTalkTick())
        return;
    JoinDefaultChannel(player);
    std::string& talkText = FindTalkText(tType, sType);
    switch (tType)
    {
    case TTT_Normal:
        NormalTalk(RandomNormalTalkType(), player, talkText);
        break;
    case TTT_Warfare:
        NormalTalk(TTT_Warfare, player, talkText);
        break;
    }
}

bool PlayerBotTalkMgr::MatchTalkTick()
{
    if (!m_DefaultChannel)
        return false;
    uint32 currentTick = getMSTime();
    if (m_WorkTick + m_NextRndTick > currentTick)
        return false;
    m_WorkTick = currentTick;
    m_NextRndTick = urand(5000, 12000);
    return true;
}

uint32 PlayerBotTalkMgr::RandomNormalTalkType()
{
    uint32 rate = urand(0, 99);
    if (rate < 40)
        return 0;
    else if (rate >= 40 && rate < 50)
        return 1;
    else if (rate >= 50 && rate < 60)
        return 2;
    return 0;
}

Player* PlayerBotTalkMgr::GetRealPlayer()
{
    const SessionMap& allSession = sWorld->GetAllSessions();
    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
    {
        if (itSession->second->PlayerLoading() || itSession->second->IsBotSession())
            continue;
        Player* player = itSession->second->GetPlayer();
        if (!player || !player->IsInWorld())
            continue;
        return player;
    }
    return NULL;
}

void PlayerBotTalkMgr::NormalTalk(uint32 sType, Player* player, std::string text)
{
    if (sType == 3 && !player->GetGroup() && !player->GetGuildId())
        sType = 0;
    switch (sType)
    {
    case 0:
        m_DefaultChannel->Say(player->GetGUID(), text.c_str(), Language::LANG_UNIVERSAL);
        break;
    case 1:
        player->Yell(text.c_str(), Language::LANG_UNIVERSAL);
        break;
    case 2:
        if (Player* realPlayer = GetRealPlayer())
            player->Whisper(text.c_str(), Language::LANG_UNIVERSAL, realPlayer);
        break;
    case 3:
        if (Group* pGroup = player->GetGroup())
        {
            WorldPackets::Chat::Chat packet;
            packet.Initialize(CHAT_MSG_PARTY, LANG_UNIVERSAL, player, NULL, text);
            pGroup->BroadcastPacket(packet.Write(), false, pGroup->GetMemberGroup(player->GetGUID()));

        }
        else if (Guild* pGuild = sGuildMgr->GetGuildById(player->GetGuildId()))
        {
            pGuild->BroadcastToGuild(player->GetSession(), false, text.c_str(), Language::LANG_UNIVERSAL);
        }
        break;
    }
    TriggerStoryTalk();
}

void PlayerBotTalkMgr::TriggerStoryTalk()
{
    uint32 rate = urand(0, 99);
    if (rate < 92)
        return;
    sFieldBotMgr->StartStoryTalk();
}
