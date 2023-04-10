
#ifndef __FIELDBOTMGR__
#define __FIELDBOTMGR__

#include "Log.h"
#include "Common.h"
#include "SharedDefines.h"
#include "DatabaseEnv.h"
#include "Timer.h"
#include "PlayerBotMgr.h"
#include "PlayerBotSession.h"
#include "BotFieldAI.h"

typedef std::list<Player*> PLAYER_LIST;
typedef std::list<BotFieldAI*> FIELDAI_LIST;

class WorldPoster
{
public:
    WorldPoster() : currentPoster(0), sendTick(0) { InitializePoster(); }
    ~WorldPoster() {}

    void SendOnceGlobalPoster();

private:
    void InitializePoster();
    void PushPoster(std::string content);

private:
    uint32 currentPoster;
    uint32 sendTick;
    std::vector<std::string> m_AllPosterContent;
};

enum ACTING_TYPE
{
    ACTING_WARFARE,
    ACTING_STORY
};

class FieldActing
{
public:
    FieldActing(ACTING_TYPE aType) : m_ActingType(aType) {}
    ~FieldActing() {}

    bool MatchActingType(ACTING_TYPE aType) { return m_ActingType == aType; }
    virtual void Update() {}
    virtual bool FieldActingIsOver() { return true; }
    virtual void OverFieldActing() {}

private:
    ACTING_TYPE m_ActingType;
};

class FieldStory : public FieldActing
{
public:
    FieldStory();
    ~FieldStory() {}

    bool FieldActingIsOver() override;
    void Update() override;

private:
    bool FillNeedBotGUID(uint32 index);
    bool ExistBotGUID(ObjectGuid& guid);

private:
    uint32 m_StoryTimer;
    uint32 m_StoryEntry;
    uint32 m_StoryStep;
    std::vector<ObjectGuid> m_TalkBotGUIDs;

    static uint32 LastStoryEntry;
};

class FieldWarfare : public FieldActing
{
public:
    FieldWarfare(Player* trigger, Player* target);
    ~FieldWarfare() {}

    bool FieldActingIsOver() override;
    void OverFieldActing() override;
    void Update() override;
    void UpdateWarfareKill(Player* deather);

private:
    bool IsWarfareStartTime();
    void ProcessStart();
    void ProcessWarrfare(Player* targetPlayer);
    void ProcessEpilog(Player* targetPlayer);
    void AddPlayerBotToFieldWarfare(Player* target, TeamId upTeam);
    void TeleportToTargetVisible(Player* pBot, Player* pTarget);
    TeamId GetWeaknessTeam();
    Position GetEvadePosition(Player* centerPlayer, Player* evadePlayer);
    int32 GetWarfareMaxCount();
    void UpdateWarfareDurableTimer();

private:
    ObjectGuid m_WarfareTrigger;
    ObjectGuid m_WarfareTarget;
    uint32 m_WarfareMapID;
    TeamId m_TriggerTeam;
    uint32 m_TriggerTimer;
    uint32 m_WarfareDurable;
    uint32 m_WarfareStartTimer;
    uint32 m_WarfareEndTimekeeping;

    int32 m_TriggerTeamKill;
    int32 m_AttackTeamKill;

public:
    static bool AID_TARGET_TEAM;
};

class  FieldBotMgr
{
private:
    FieldBotMgr();
    ~FieldBotMgr();

public:
    FieldBotMgr(FieldBotMgr const&) = delete;
    FieldBotMgr(FieldBotMgr&&) = delete;

    FieldBotMgr& operator= (FieldBotMgr const&) = delete;
    FieldBotMgr& operator= (FieldBotMgr&&) = delete;

    static FieldBotMgr* instance();

    bool HasActing() { return m_FieldActing != NULL; }
    bool ExistWarfare() { return (m_FieldActing != NULL && m_FieldActing->MatchActingType(ACTING_WARFARE)); }
    void StartStoryTalk();
    void Update(ObjectGuid workGUID);
    void OnRealPlayerLogin(Player* player);
    void OnRealPlayerLogout(ObjectGuid guid);
    void KillFieldPlayer(Player* pAttacker, Player* deather);
    FieldWarfare* GetWarfareActing();

    static FIELDAI_LIST GetAllFieldBotPlayer(TeamId team);
    static bool MatchTeleportCondition(Player* p1, Player* p2);
    static bool CanExistTargetZone(Player* player, Player* target);

private:
    PLAYER_LIST GetAllRealPlayer();
    void TeleportToTargetVisible(BotFieldAI* pFieldAI, Player* pTarget);
    void UpdateInitOnline();
    void UpdateTeleport();
    bool IsVaildVisiblePos(Player* pTarget, float x, float y, float z);
    void RandomPlayerBotNormalTalk();
    int32 GetMaxNearPlayer();
    bool CanTriggerWarfare(Player* pAttacker, Player* deather);

private:
    WorldPoster m_WorldPoster;
    uint32 m_WorkTick;
    ObjectGuid m_WorkPlayerGUID;
    int32 m_MaxNearPlayer;
    uint32 m_ProbabilityWarfare;
    FieldActing* m_FieldActing;

public:
    static bool FIELDBOT_CREATURE;
    static bool FIELDBOT_DRIVING;
    static uint32 FIELDWARFARE_SIZE;
};

#define sFieldBotMgr FieldBotMgr::instance()

#endif // !__FIELDBOTMGR__
