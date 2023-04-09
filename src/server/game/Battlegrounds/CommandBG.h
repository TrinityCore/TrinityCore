
#ifndef _COMMANDBG_H_
#define _COMMANDBG_H_

#define COMMANDBG_UPDATE_TICK 5000
#define COMMAND_POINT_IFDISTANCE 80

#include "AIWaypointsMgr.h"
#include "Battleground.h"
#include "BotBGAIMovement.h"
#include "Player.h"

class Player;
class Battleground;
class BotBGAI;

typedef std::vector<uint32> AIWPEntrys;
typedef std::vector<AIWaypoint*> BGKeyPoints;
typedef std::set<uint64> PlayerGUIDs;
typedef std::map<uint64, bool> PlayerStatus;

enum CommandModel
{
    CM_Dispersibility,
    CM_GroupFocus,
    CM_Regulation,
    CM_Over
};

enum BGGameCommand
{
    BGGS_None = 0,
    BGGS_Init,
    BGGS_Ready,
    BGGS_Start
};

enum BGCommandType
{
    BGCT_IDLEMove,
    BGCT_NormalMove,
    BGCT_FullMove,
    BGCT_GuardObject,
    BGCT_GuardPoint,
    BGCT_AttackObject,
    BGCT_AttackPoint,
    BGCT_Over
};

struct BGCommandInfo
{
    BGCommandType bgcType;
    uint32 weight;
    AIWaypoint* targetAIWP;
    ObjectGuid targetGuid;
    float rndOffset;

    BGCommandInfo(BGCommandType eType) :
        bgcType(eType)
    {
        weight = 0;
        targetAIWP = NULL;
        targetGuid.Clear();
        rndOffset = 0;
    }

    void Clear()
    {
        bgcType = BGCommandType::BGCT_Over;
        weight = 0;
        targetAIWP = NULL;
        targetGuid.Clear();
        rndOffset = 0;
    }
};

class CommandBG
{
public:
    CommandBG(Battleground* pBG, TeamId team);
    ~CommandBG();

    static void SettingCommandModel(CommandModel modelType) { g_CommandModelType = modelType; }

    virtual void Initialize();
    virtual void ReadyGame();
    virtual void StartGame();
    virtual void OnPlayerDead(uint64 guid);
    virtual bool AddPlayerBot(Player* player, Battleground* pBG);
    void RemovePlayerBot(Player* player);
    virtual AIWaypoint* GetReadyPosition() { return NULL; }
    virtual void OnPlayerRevive(Player* /*player*/) {}
    virtual const Creature* GetMatchGraveyardNPC(const Player* /*player*/) { return NULL; };
    virtual void Update(uint32 diff);
    virtual bool CanUpMount(Player* /*player*/) { return true; }
    virtual bool CanDireFlee() { return true; }

    UnitAI* GetPlayerAI(uint64 guid);
    BotBGAI* GetBotBGAI(uint64 guid);
    Player* GetBGPlayer(uint64 guid);
    Position GetNearTeleportPoint(Position& currentPos);
    void UpdateBelongBattleground(Battleground* pBG) { m_pBattleground = pBG; }
    void ClearPlayerGUIDs() { m_PlayerGUIDs.clear(); }

protected:
    bool GroupAllPlayerReadyToWayPoint(AIWaypoint* pKeyPoint);
    void ProcessGroupFocus(AIWaypoint* selfFocus, AIWaypoint* enemyFocus);

    Position GetPositionByGuid(uint64 guid);

protected:
    BGGameCommand m_BGGC;
    uint32 m_ComModelStatus;
    Battleground* m_pBattleground;
    TeamId m_TeamID;
    AIWPEntrys m_AIWPEntrys;
    BGKeyPoints m_BGKeyWaypoints;
    PlayerStatus m_PlayerGUIDs;
    uint32 m_BGProcessTimerTick;

protected:
    static CommandModel g_CommandModelType;
};

#endif // _COMMANDBG_H_
