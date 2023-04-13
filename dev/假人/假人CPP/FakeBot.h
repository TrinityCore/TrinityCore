
#ifndef _FAKEPLAYER_H
#define _FAKEPLAYER_H

struct FakeBotConfig
{
    uint32 Id;
    std::string Value;
};
typedef std::map<uint32, FakeBotConfig> FakeBotConfigMap;

typedef std::vector<WorldSession*> FakeBotSessions;

struct FakeLocation
{
    uint32 Idx;
    uint32 MapId;
    float X;
    float Y;
    float Z;
    float O;
};

typedef std::vector<FakeLocation> FakeBotLocations;

struct TrueLocation
{
    uint32 GuidLow;
    WorldLocation Location;
};
typedef std::vector<TrueLocation> TruePlayerLocations;

typedef std::vector<uint32> PlayerGuidList;
typedef std::unordered_map<uint32, PlayerGuidList> AccountContainer;
typedef std::unordered_map<uint32, Player*> PlayerContainer;

typedef std::unordered_map<uint32, uint32> PlayerGuidContainer;
typedef std::set<uint32> AccountSet;

typedef std::unordered_map<uint32, std::string> FakeMsgContainer;

enum FakeBotEvents
{
    EVENT_NONE = 6000,
    EVENT_UPDATE_ACCOUNT,
    EVENT_CHECK_PLAYERCOUNT,
    EVENT_REMOVE_ALL,
};

class FakeBot
{
public:
	static FakeBot* instance()
	{
		static FakeBot instance;
		return &instance;
	}

    FakeBotConfigMap _FakeBotConfigMap;
    FakeBotSessions _FakeBotSessions;
    TruePlayerLocations _TruePlayerLocations;
    FakeBotLocations _FakeBotLocations;
    AccountContainer m_AllAccount;
    AccountContainer m_BotAccount;
    PlayerContainer m_BotPlayers;

    PlayerGuidContainer m_LastWhispers;
    FakeMsgContainer FakeMsgs;

    uint32 AccountMax;
    uint32 CustomGuid;

    EventMap MapEvents;

    uint32 Enable;
    bool IsEnable() { return Enable > 0; }

    uint32 MessageToGM;
    bool IsMessageToGM() { return MessageToGM > 0; }

    void LoadFakeConfig();

    uint32 GetFakePlayerCount() const;

    bool IsFakeBot(Player* player);

    void CheckPlayerCount();

    uint32 GetPlayerBotAccountId(uint32 PlayerGuid);
    bool RemovePlayerBot(uint32 PlayerGuid);
    bool RemoveAccountBot(uint32 AccountId, bool All = false);
    bool FakePlayerLogin();

    bool FakePlayerLogout(bool Check = false);
    void HandlePlayerLoginOpcode(uint32 PlayerGuid);

    void CleanData(bool All = false);
    void RemoveAllPlayerBot();

    void FakeSendGlobalGMSysMessage(const char *Msg, WorldSession* Self = nullptr, TeamId Team = TEAM_NEUTRAL);
    bool OnFakeWhisper(std::string const& Msg, const uint32 Lang, Player* Sender, Player* Receiver);

    std::string GetWhisperRandom();

    uint32 GetFakeBotMoveDelay();

    void ResetTrueLocation(Player* FakeBot);
    void RemoveFakeBotSession(uint32 PlayerGuidLow);
    void UpdateAllSessions(uint32 Diff);
    void Update(Player* FakeBot, uint32 Diff);

    void LoadFakeBotConfig();
    const char* GetFakeConfig(uint32 Index);

    void LoadFakePlayerStore();
    void LoadFakeRandomMsg();

    void LoadFakeBotLocation();

private:

};
#define sFakeBot FakeBot::instance()

#endif
