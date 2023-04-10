
#ifndef __PLAYERBOTMGR_H__
#define __PLAYERBOTMGR_H__

//#include <chrono>

#include "Log.h"
#include "Common.h"
#include "SharedDefines.h"
#include "DatabaseEnv.h"
#include "Timer.h"
//#include "Callback.h"
#include "PlayerBotSession.h"
#include "BotAITool.h"
#include "LFGMgr.h"
#include "Containers.h"
#include "Player.h"

#define CONVERT_ARENAAI_TOBG

class ObjectGuid;
struct LFGBotRequirement;
struct BotGlobleSchedule;
class PlayerBotSession;

enum PlayerBot
{
    CURRENT_MAX_LEVEL = 110
};
enum PlayerBotAIType
{
    PBAIT_SIMPLE,
	PBAIT_FIELD,
	PBAIT_BG,
	PBAIT_GROUP,
	PBAIT_DUNGEON,
	PBAIT_DUEL,
	PBAIT_ARENA,
	PBAIT_OVER
};

struct createInfo
{
    uint8 Race = RACE_NONE;
    uint8 Class = CLASS_NONE;
    uint8 Sex = GENDER_NONE;
    uint8 Skin = 0;
    uint8 Face = 0;
    uint8 HairStyle = 0;
    uint8 HairColor = 0;
    uint8 FacialHairStyle = 0;
    uint8 OutfitId = 0;
    std::string Name;
};

struct PlayerBotCharBaseInfo
{
	uint32 guid;
	uint32 account;
	std::string name;
	uint16 race;
	uint16 Class;
	uint16 gender;
	uint16 level;

	PlayerBotCharBaseInfo()
	{
		guid = 0;
		account = 0;
		race = Class = gender = level = 0;
	}
	PlayerBotCharBaseInfo(uint32 id, uint32 acc, const std::string &na, uint16 ra, uint16 cls, uint16 gen, uint16 lv) :
		guid(id), account(acc), name(na), race(ra), Class(cls), gender(gen), level(lv)
	{
	}

	std::string GetNameANDClassesText();
};

struct PlayerBotBaseInfo
{
	static PlayerBotCharBaseInfo empty;
	bool isAccountInfo;
	uint32 id;
	std::string username;
	std::string pass;
	std::map<uint32,PlayerBotCharBaseInfo> characters;
	std::queue<createInfo> needCreateBots;

	PlayerBotBaseInfo(uint32 uid, const char *name, std::string &pa, bool isAcc) :
		isAccountInfo(isAcc), id(uid), pass(pa)
	{
		characters.clear();
		username = name;
	}

	bool ExistClass(TeamId team, uint16 Class)
	{
		for (auto it : characters)
		{
			if (it.second.Class == Class)
			{
				uint16 race = it.second.race;
				if (Player::BotTeamIdForRace(race) == team)
					return true;
			}
		}
		return false;
	}

	PlayerBotCharBaseInfo& GetRandomCharacterByFuction(TeamId team)
	{
		if (characters.size() <= 0)
		{
			return empty;
		}
#ifdef INCOMPLETE_BOT
		for (int i = 0; i < 20; i++)
#else
		for (int i = 0; i < 5; i++)
#endif
		{
			int16 select = irand(0, characters.size() / 2 - 1);
            for (auto it = characters.begin(); it != characters.end(); it++)
			{
                if (Player::BotTeamIdForRace(it->second.race) == team)
                {
                    if (select <= 0)
                        return it->second;
                    else
                        --select;
                }
			}
		}
		return characters.begin()->second;
	}
    /*todo47
	std::vector<uint32> GetNoArenaTeamCharacterIDsByFuction(TeamId team, ArenaTeamTypes type)
	{
		std::vector<uint32> outIDs;
		if (characters.size() <= 0)
		{
			return outIDs;
		}
		for (auto it : characters)
		{
			if (Player::TeamIdForRace(it.second.race) == team)
			{
				if (sArenaTeamMgr->ExistArenaTeamByType(ObjectGuid(uint64(it->second.guid)), type))
					continue;
				outIDs.push_back(it->second.guid);
			}
		}
		Trinity::Containers::RandomShuffle(outIDs);
		//unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		//std::shuffle(outIDs.begin(), outIDs.end(), std::default_random_engine(time(NULL)));
		return outIDs;
	}
    */
	PlayerBotCharBaseInfo& GetCharacter(TeamId team, uint32 cls)
	{
		if (characters.size() <= 0)
			return empty;
        for (auto it = characters.begin(); it != characters.end(); it++)
		{
            if (Player::BotTeamIdForRace(it->second.race) == team)
				continue;
			if (it->second.Class == cls)
				return it->second;
		}
		return empty;
	}

    PlayerBotCharBaseInfo& GetCharacterByTeam(TeamId team)
    {
        if (characters.size() <= 0)
            return empty;

        for (int i = 0; i < 5; i++)
        {
            int16 select = irand(0, characters.size() / 2 - 1);
            for (auto it = characters.begin(); it != characters.end(); it++)
            {
                if (Player::TeamIdForRace(it->second.race) == team)//BotTeamIdForRace TeamIdForRace
                {
                    if (select <= 0)
                        return it->second;
                    else
                        --select;
                }   
            }
        }
        return characters.begin()->second;
    }

	uint32 GetCharIDByNoArenaType(TeamId team, uint32 prof, uint32 arenaType, std::vector<ObjectGuid>& fliters);

	bool ExistCharacterByGUID(ObjectGuid& guid)
	{
		for (auto it : characters)
		{
			if (it.second.guid == guid.GetCounter())
				return true;
		}
		return false;
	}

	TeamId GetTeamIDByChar(ObjectGuid& guid)
	{
		uint32 id = guid.GetCounter();
        for (auto it : characters)
		{
			if (it.second.guid != id)
				continue;
            return Player::BotTeamIdForRace(it.second.race);
		}
		return TeamId::TEAM_NEUTRAL;
	}

	std::string GetCharNameANDClassesText(ObjectGuid& guid)
	{
		uint32 id = guid.GetCounter();
        for (auto it : characters)
		{
			if (it.second.guid != id)
				continue;
			return it.second.GetNameANDClassesText();
		}
		return "";
	}

	bool RemoveCharacterByGUID(ObjectGuid& guid)
	{
		uint32 id = guid.GetCounter();
		for (auto it = characters.begin(); it != characters.end(); it++)
		{
			if (it->second.guid != id)
				continue;
			characters.erase(it);
			return true;
		}
		return false;
	}
};

class TC_GAME_API PlayerBotMgr
{
	typedef std::vector<BattlegroundTypeId> BattleGroundTypes;

private:
	PlayerBotMgr();
	~PlayerBotMgr();

public:
	PlayerBotMgr(PlayerBotMgr const&) = delete;
	PlayerBotMgr(PlayerBotMgr&&) = delete;

	PlayerBotMgr& operator= (PlayerBotMgr const&) = delete;
	PlayerBotMgr& operator= (PlayerBotMgr&&) = delete;

	static PlayerBotMgr* instance();
	static void SwitchPlayerBotAI(Player* player, PlayerBotAIType aiType, bool force);

	std::string GetPlayerLinkText(Player const* player) const;

	std::string RandomArenaName();
	PlayerBotSession* GetBotSessionByCharGUID(ObjectGuid& guid);
	TeamId GetTeamIDByPlayerBotGUID(ObjectGuid& guid);
	bool IsPlayerBot(WorldSession *pSession);
	bool IsBotAccuntName(std::string name);
	bool IsIDLEPlayerBot(Player* player);
	void DestroyBotMail(uint32 guid);
	void LoadPlayerBotBaseInfo();
	void AddNewAccountBotBaseInfo(std::string name);
	//std::set<uint32> GetArenaTeamPlayerBotIDCountByTeam(TeamId team, int32 count, ArenaTeamTypes type);todo47
	PlayerBotBaseInfo* GetPlayerBotAccountInfo(uint32 guid);
	PlayerBotBaseInfo* GetAccountBotAccountInfo(uint32 guid);

	void UpdateLastAccountIndex(std::string& username);
	void UpAllPlayerBotSession();

	void OnPlayerBotCreate(ObjectGuid const& guid, uint32 accountId, std::string const& name, uint8 gender, uint8 race, uint8 playerClass, uint8 level);
	void OnAccountBotCreate(ObjectGuid const& guid, uint32 accountId, std::string const& name, uint8 gender, uint8 race, uint8 playerClass, uint8 level);
	void OnAccountBotDelete(ObjectGuid& guid, uint32 accountId);
	void OnPlayerBotLogin(WorldSession* pSession, Player* pPlayer);
	void OnPlayerBotLogout(WorldSession* pSession);
	void OnPlayerBotLeaveOriginalGroup(Player* pPlayer);
	void LoginGroupBotByPlayer(Player* pPlayer);
	void LoginFriendBotByPlayer(Player* pPlayer);
    void LoginGuildMemberBotByPlayer(Player* pPlayer);
	void LogoutAllGroupPlayerBot(Group* pGroup, bool force);

	void AllPlayerBotRandomLogin();
    void AutoPlayerBotRandomLogin();
	void AllPlayerBotLogout();
	bool PlayerBotLogout(uint32 account);
	bool PlayerBotLogout(Player* player);
	bool AllPlayerLeaveBG(uint32 account);
	void SupplementPlayerBot();

	void OnRealPlayerJoinBattlegroundQueue(uint32 bgTypeId, uint32 level);
	void OnRealPlayerLeaveBattlegroundQueue(uint32 bgTypeId, uint32 level);
	void OnRealPlayerLeaveArenaQueue(uint32 bgTypeId, uint32 level, uint32 aaType);
	void OnRealPlayerEnterBattleground(uint32 bgTypeId, uint32 level);
	void OnRealPlayerLeaveBattleground(const Player* player);

	void Update(uint32 diff);
	uint32 GetOnlineBotCount(TeamId team, bool hasReal);
    uint32 GetAllowMaxBotCount();
    uint32 GetAllowMaxWarrfareBotCount();

	bool LoginBotByAccountIndex(uint32 account, uint32 index);
	void DelayLoginPlayerBotByGUID(ObjectGuid& guid) { m_DelayOnlineBots.push(guid); }
	bool AddNewPlayerBotByGUID(ObjectGuid& guid);
    bool AddOnePlayerBot(TeamId team, Classes cls);
	void AddNewPlayerBot(TeamId team, Classes prof, uint32 count);
	void AddNewAccountBot(TeamId team, Classes prof);
	void AddNewPlayerBotByClass(uint32 count, Classes prof);
	bool ChangePlayerBotSetting(uint32 account, uint32 minLV, uint32 maxLV, uint32 talent);
	lfg::LfgRoles GetPlayerBotCurrentLFGRoles(Player* player);
	ObjectGuid GetNoArenaMatchCharacter(TeamId team, uint32 arenaType, Classes cls, std::vector<ObjectGuid>& fliters);
	std::string GetNameANDClassesText(ObjectGuid& guid);
	bool CanReadyArenaByArenaTeamID(uint32 arenaTeamId);
    void SetBotAutoLoginStarted(bool started) { m_AutoLoginStarted = started; }
    void ProcessMoveToCommand(ObjectGuid& guid, float x, float y, float z, float o, float offset = 0.0f);
private:
	bool ExistClassByRace(uint8 race, uint8 prof);
	void InitializeCreatePlayerBotName();
	std::string RandomName();
	uint8 RandomRace(bool group, uint8 prof);
	uint8 RandomSkinColor(uint8 race, uint8 gender, uint8 prof);
	uint8 RandomFace(uint8 race, uint8 gender, uint8 skinColor, uint8 prof);
	uint8 RandomHair(uint8 race, uint8 gender, uint8 prof);
	uint8 RandomHairColor(uint8 race, uint8 gender, uint8 hairID, uint8 prof);
	uint8 RandomFacialHair(uint8 race, uint8 gender, uint8 hairColor, uint8 prof);
	PlayerBotSession* UpPlayerBotSessionByBaseInfo(PlayerBotBaseInfo *pAcc, bool accountInfo);
	createInfo BuildCreatePlayerData(bool group, uint8 prof);
	void CreateOncePlayerBot();

	void ClearBaseInfo();
	void SupplementAccount();
	void LoadCharBaseInfo();
	void LoadSessionPermissionsCallback(PreparedQueryResult result);

	void ClearEmptyNeedPlayer();
	void ClearNeedPlayer(uint32 bgTypeID, uint32 bracketID);
	void AddNewPlayerBotToBG(TeamId team, uint32 minLV, uint32 maxLV, BattlegroundTypeId bgTypeID);
	void AddNewPlayerBotToLFG(lfg::LFGBotRequirement* botRequirement);
	void AddNewPlayerBotToAA(TeamId team, BattlegroundTypeId bgTypeID, uint32 bracketID, uint32 aaType);
	void AddTeamBotToRatedArena(uint32 arenaTeamId);
	bool FillOnlineBotScheduleByLFGRequirement(lfg::LFGBotRequirement* botRequirement, BotGlobleSchedule* botSchedule);
	uint32 GetScheduleTalentByLFGRequirement(lfg::LfgRoles roles, uint32 botCls);
	void QueryBattlegroundRequirement();
	void QueryRatedArenaRequirement();
	void QueryNonRatedArenaRequirement();
	void OnlinePlayerBotByGUIDQueue();
	bool ExistUnBGPlayerBot();
	PVPDifficultyEntry const* FindBGBracketEntry(Battleground* bg_template, uint32 level);

private:
	uint32 m_BotAccountAmount;
	uint32 m_LastBotAccountIndex;
	uint32 m_MaxOnlineBot;
	uint32 m_BotOnlineCount;
    uint32 m_AutoLoginAliCount;
    uint32 m_AutoLoginHorCount;
    bool   m_AutoLoginStarted;
	uint32 m_LFGSearchTick;
    uint32 m_BGSearchTick;
	uint32 m_ArenaSearchTick;
	std::map<uint32, PlayerBotBaseInfo*> m_idPlayerBotBase;
	std::map<uint32, PlayerBotBaseInfo*> m_idAccountBotBase;

	BattleGroundTypes m_BGTypes;
	std::vector<std::string> allName;
	std::vector<std::string> allArenaName;
	std::queue<ObjectGuid> m_DelayOnlineBots;
    
    bool is_break;
public:
	static std::map<uint32, std::list<UnitAI*> > m_DelayDestroyAIs;
    std::unordered_map<ObjectGuid, ObjectGuid> m_DelayGroupBots;
	static std::mutex g_uniqueLock;
    EventProcessor m_Events;
};

#define sPlayerBotMgr PlayerBotMgr::instance()

#endif // __PLAYERBOTMGR_H__
