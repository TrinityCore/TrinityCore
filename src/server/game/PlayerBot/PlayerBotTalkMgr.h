
#ifndef __PLAYERBOT_TALKMGR_H__
#define __PLAYERBOT_TALKMGR_H__

#include "Log.h"
#include "Common.h"
#include "SharedDefines.h"
#include "DatabaseEnv.h"
#include "Timer.h"
#include "ChannelMgr.h"

enum TALK_TTYPE
{
	TTT_Normal = 0,
	TTT_Warfare,
	TTT_OVER
};

struct BotTalkStory
{
	uint32 entry;
	std::vector<uint32> indexs;
	std::vector<std::string> texts;

	bool ResolutionContent(std::string& text);
	bool GetStoryByIndex(uint32 step, uint32& index, std::string& text);
	bool IsValidStep(uint32 step);
};

typedef	std::map<uint32, BotTalkStory>	BOT_TALKSTORYS;

struct BotTalkText
{
	static std::string defauleText;
	uint32 entry;
	uint32 subType;
	std::vector<std::string> texts;

	std::string& GetRandomText()
	{
		if (texts.empty())
			return defauleText;
		return texts[urand(0, texts.size() - 1)];
	}
};

typedef	std::map<uint32, BotTalkText>	BOT_TALKTEXTS;

struct BotTalkType
{
	uint32 entry;
	uint32 talkType;
	BOT_TALKTEXTS talkTexts;

	void AddBotTalk(uint32 subType, std::string text)
	{
		if (talkType == TALK_TTYPE::TTT_Normal)
			subType = 0;
		BotTalkText& talkText = talkTexts[subType];
		talkText.entry = entry;
		talkText.subType = subType;
		talkText.texts.push_back(text);
	}
	std::string& GetTextByType(uint32 subType)
	{
		if (talkType == TALK_TTYPE::TTT_Normal)
			subType = 0;
		BOT_TALKTEXTS::iterator itTalk = talkTexts.find(subType);
		if (itTalk == talkTexts.end())
			return BotTalkText::defauleText;
		return itTalk->second.GetRandomText();
	}
};

typedef	std::map<uint32, BotTalkType>	BOT_TALKTYPES;

class TC_GAME_API PlayerBotTalkMgr
{
private:
	PlayerBotTalkMgr();
	~PlayerBotTalkMgr();

public:
	PlayerBotTalkMgr(PlayerBotTalkMgr const&) = delete;
	PlayerBotTalkMgr(PlayerBotTalkMgr&&) = delete;

	PlayerBotTalkMgr& operator= (PlayerBotTalkMgr const&) = delete;
	PlayerBotTalkMgr& operator= (PlayerBotTalkMgr&&) = delete;

	static PlayerBotTalkMgr* instance();

	std::string& FindTalkText(uint32 tType, uint32 sType)
	{
		BOT_TALKTYPES::iterator itTalk = m_BotTalkTypes.find(tType);
		if (itTalk == m_BotTalkTypes.end())
			return BotTalkText::defauleText;
		return itTalk->second.GetTextByType(sType);
	}
	void InitializeTalkText();
	void InitializeStory();
	uint32 RandomStoryID();
	bool GetStoryByIndex(uint32 id, uint32 step, uint32& index, std::string& text);
	bool IsValidStoryStep(uint32 id, uint32 step);
	std::string GetDefaultChannelName();
	void SetDefaultChannel(Channel* pChannel) { m_DefaultChannel = pChannel; }
	void JoinDefaultChannel(Player* player);
	bool CanNextTalk() { return ((m_WorkTick + m_NextRndTick) <= getMSTime()); }
	void WarfareActingTalk(uint32 sType, Player* player);
	void StoryActingTalk(Player* player, std::string& talkText);
	void PlayerBotTalkByType(TALK_TTYPE tType, uint32 sType, Player* player);

private:
	bool MatchTalkTick();
	void TriggerStoryTalk();
	uint32 RandomNormalTalkType();
	Player* GetRealPlayer();
	void NormalTalk(uint32 sType, Player* player, std::string text);

private:
	ChannelMgr* m_CommonChannelMgr;
	Channel* m_DefaultChannel;
	uint32 m_WorkTick;
	uint32 m_NextRndTick;
	BOT_TALKTYPES m_BotTalkTypes;
	BOT_TALKSTORYS m_BotTalkStorys;
	BOT_TALKSTORYS m_CanUseTalkStorys;
};

#define sPlayerBotTalkMgr PlayerBotTalkMgr::instance()
#define sPlayerBotTryTalk(t, s, p) PlayerBotTalkMgr::instance()->PlayerBotTalkByType(t, s, p)

#endif // !__PLAYERBOT_TALKMGR_H__
