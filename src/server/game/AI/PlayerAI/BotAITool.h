#ifndef _BOT_AI_TOOL_H
#define _BOT_AI_TOOL_H

#include "ScriptSystem.h"
#include "PlayerAI.h"
#include "PlayerBotTalkMgr.h"
#include "MotionMaster.h"
#include "SpellHistory.h"
#include "ItemTemplate.h"
#include "Item.h"
#include "Bag.h"
#include "TradeData.h"
#include "Channel.h"
#include "PhasingHandler.h"
#include "Player.h"

#define ARENA_PLAYER_BOT_AURA 80849
#define ARENA_WARRIOR_BOT_AURA 80850
#define ARENA_PALADIN_BOT_AURA 80851
#define ARENA_ROGUE_BOT_AURA 80852
#define ARENA_HUNTER_BOT_AURA 80853
#define ARENA_SHAMAN_BOT_AURA 80854
#define ARENA_MAGE_BOT_AURA 80855
#define ARENA_WARLOCK_BOT_AURA 80856
#define ARENA_PRIEST_BOT_AURA 80857
#define ARENA_DRUID_BOT_AURA 80858

#define BOTAI_UPDATE_TICK 500

#define BOTAI_MAXTARGET_TICKTIME 30000
#define BOTAI_FIELDTELEPORT_DISTANCE 80
#define BOTAI_SEARCH_RANGE 32
#define BOTAI_RANGESPELL_DISTANCE 28
#define BOTAI_TOTEMRANGE 18
#define BOTAI_FLEE_JUDGE 14

#define NEEDFLEE_CHECKRANGE 10

enum PlayerTotemType
{
    SUMMON_TYPE_TOTEM_FIRE = 63,
    SUMMON_TYPE_TOTEM_EARTH = 81,
    SUMMON_TYPE_TOTEM_WATER = 82,
    SUMMON_TYPE_TOTEM_AIR = 83
};

enum ShamanTotemPattern
{
    ShamanTP_None = 0,
    ShamanTP_Normal = 1,
    ShamanTP_Flee = 2,
    ShamanTP_Heal = 3,
    ShamanTP_Melee = 4,
    ShamanTP_Range = 5
};

enum BOTAI_WORKTYPE
{
    AIWT_TANK,
    AIWT_MELEE,
    AIWT_RANGE,
    AIWT_HEAL,
    AIWT_ALL
};

struct SpellEntry;
class Player;
class Group;
class BotBGAIMovement;
class BotFieldAI;

class BotUtility
{
public:
    static float BattlegroundScoreRate;
    static float DungeonBotDamageModify;
    static float DungeonBotEndureModify;
    static bool BotCanForceRevive;
    static bool BotCanSettingToMaster;
    static int32 BotCritTakenAddion;
    static bool ControllSpellDiminishing;
    static bool ControllSpellFromDmgBreak;
    static bool DownBotArenaTeam;
    static bool ArenaIsHell;
    static uint32 BotArenaTeamTactics;
    static bool DisableDKQuest;

public:
    static void AddArenaBotSpellsByPlayer(Player* player);
    static void RemoveArenaBotSpellsByPlayer(Player* player);
    static void TryCancelDuel(Player* player);
    static bool SpellHasReady(Player* player, uint32 spellID);
    static uint32 GetFirstNumberByString(std::string& text);
    static std::string BuildItemLinkText(const ItemTemplate* pItemTemplate);
    static void UpdatePlayerBotRoll(Player* player);
    static Item* FindItemFromAllBag(Player* player, uint32 entry, bool destroy = false);
    static Item* FindItemFromAllBag(Player* player, uint32 entry, uint8& bag, uint8& index);
    static bool DestroyItemFromAllBag(Player* player, Item* pItem);
    static Item* StoreNewItemByEntry(Player* player, uint32 entry, int32 count = 1);
    static uint32 FindMaxRankSpellByExist(Player* player, uint32 spellID);
    static uint32 FindPetMaxRankSpellByExist(Player* player, uint32 spellID);
    static void PlayerBotTogglePVP(Player* player, bool pvp);
    static void TryTeleportHome(BotFieldAI* pAI);
    static Position GetPositionFromGroup(Player* pCenterPlayer, ObjectGuid self, Group* pGroup);
    static void ProcessGroupTankPullTargets(Player* player);
    static void ProcessGroupRingMovement(Player* pCenterPlayer, BOTAI_WORKTYPE aiType);
    static void ProcessGroupCombatMovement(Player* pCenterPlayer, BOTAI_WORKTYPE aiType);
    static Position FindRadiusByNearDistance(Unit* pTargetUnit, float range, Unit* pRefUnit);
    static Position FindRadiusByFarDistance(Unit* pTargetUnit, float range, Unit* pRefUnit);
    static bool FindFirstCollisionPosition(Unit* pTargetUnit, float range, Unit* pRefUnit, Position& outPos);
    static void TryTeleportPlayerPet(Player* player, bool force = false);
};

class BotAIGuild
{
public:
    BotAIGuild(Player* self) : me(self)
    {
    }
    ~BotAIGuild() {}

    void UpdateGuildProcess();

private:
    Player* me;
};

class BotAITeleport
{
public:
    BotAITeleport(Player* self) : me(self), m_Teleporting(false), m_MapId(self->GetMapId()), m_TeleportStep(0)
    {
    }
    ~BotAITeleport() {}

    void SetTeleport(Position* telePos, float offset);
    void SetTeleport(Position& telePos);
    void SetTeleport(uint32 mapID, Position& telePos);
    void SetTeleport(Player* pTarget, float offset = NEEDFLEE_CHECKRANGE);
    void ClearTeleport();
    void Update(uint32 diff, BotBGAIMovement* pMovement);
    bool CanMovement() { return !m_Teleporting; }
    void UpdateMapID() { if (me) m_MapId = me->GetMapId(); }

private:
    Player* me;
    Player* master;
    bool m_Teleporting;
    Position m_TeleportPositon;
    uint32 m_MapId;
    uint32 m_TeleportStep;
};

class BotAIStoped
{
public:
    BotAIStoped(Player* self) : me(self), m_updateTick(0), m_SyncTick(0)
    {
        if (me)
        {
            m_lastPosition = me->GetPosition();
        }
    }
    ~BotAIStoped() {}

    void UpdatePosition(uint32 diff);

private:
    bool HasDifference(Position& pos1, Position& pos2);
    void SyncPosition(Position& pos, uint32 opcode);

private:
    Player* me;
    int32 m_updateTick;
    Position m_lastPosition;
    uint32 m_SyncTick;
};

class BotAIHorrorState
{
public:
    BotAIHorrorState(Player* self) : me(self), m_CurHorrorPos(self->GetPosition()) {}
    ~BotAIHorrorState() {}

    void UpdateHorror(uint32 diff, BotBGAIMovement* movement);

    Position GetNewHorrorPos();
    static Position GetNewHorrorPosByRange(Player* player, float distance);
    Position FindNewHorrorPos(BotBGAIMovement* movement);

private:
    Player* me;
    Position m_CurHorrorPos;
};

struct FoodInfo
{
    uint32 level;
    uint32 foodEntry;
    uint32 foodBuff;
    uint32 waterEntry;
    uint32 waterBuff;

    FoodInfo(uint32 lv, uint32 food, uint32 fbuf, uint32 water, uint32 wbuf)
    {
        level = lv;
        foodEntry = food;
        foodBuff = fbuf;
        waterEntry = water;
        waterBuff = wbuf;
    }
};
typedef std::list<FoodInfo> FOOD_LIST;

class BotAIUseFood
{
public:
    BotAIUseFood(Player* self);
    ~BotAIUseFood() {}

    bool UpdateBotFood(uint32 diff, uint32 downMountID);
    bool HasFoodState() { return (m_LastFoodAura > 0 || m_LastWaterAura > 0); }

private:
    FoodInfo* GetFoodInfoByLevel(uint32 level);
    void ClearFoodState();

private:
    Player* me;
    bool m_HasMana;
    FOOD_LIST m_FoodInfos;
    uint32 m_LastFoodAura;
    uint32 m_LastWaterAura;
};

struct PotionInfo
{
    uint32 level;
    uint32 potionEntry;

    PotionInfo(uint32 lv, uint32 entry) : level(lv), potionEntry(entry)
    {
    }
};

class BotAIUsePotion
{
    typedef std::list<PotionInfo> POTION_LIST;
public:
    BotAIUsePotion(Player* self);
    ~BotAIUsePotion() {}

    bool TryUsePotion();

private:
    bool TryUseLifeVial();
    bool TryUseManaVial();
    Item* FindLifeVial();
    Item* FindManaVial();

private:
    Player* me;
    bool m_NeedMana;
    POTION_LIST m_LifeVials;
    POTION_LIST m_ManaVials;
};

class BotAIFastAid
{
    typedef std::list<PotionInfo> AID_LIST;
public:
    BotAIFastAid(Player* self);
    ~BotAIFastAid() {}

    void CheckPlayerFastAid();
    bool TryDoingFastAidForMe();

private:
    uint32 GetFastAidSpell();
    bool CanFastAidByTarget(Player* target);

private:
    Player* me;
    uint32 m_NoAidBuff;
    AID_LIST m_FastAids;
};

class BotAIFindNearLoot
{
public:
    BotAIFindNearLoot(Player* self) : me(self), m_LootingTick(0), m_HasLoot(false) {}
    ~BotAIFindNearLoot() {}

    bool DoFindLoot(uint32 diff, BotBGAIMovement* movement, uint32 downMountID);
    bool HasLoot() { return m_HasLoot; }

private:
    Creature* FindLootCreature(float range);

private:
    Player* me;
    int32 m_LootingTick;
    bool m_HasLoot;
};

class BotAILootedItems
{
public:
    BotAILootedItems(Player* self) : me(self) {}
    ~BotAILootedItems() {}

    void LookupLootedItems(uint32 diff);
    void AddLootedItem(uint32 entry) { if (entry > 0) items.push_back(entry); }
    bool HasItems() { return !(items.empty()); }

private:
    Player* me;
    std::list<uint32> items;
};

class BotAITrade
{
public:
    BotAITrade(Player* self) : me(self) {}
    ~BotAITrade() {}

    bool ProcessTrade();

private:
    Player* me;
};

class BotAIGiveXP
{
public:
    BotAIGiveXP(Player* self) : me(self), m_AddXP(0) {}
    ~BotAIGiveXP() {}

    void ProcessGiveXP(uint32 masterLV);
    void DelayAddXP(uint32 xp) { if (xp > 0) m_AddXP += xp; }

private:
    Player* me;
    uint32 m_AddXP;
};

class BotAIRevive
{
    static const uint32 c_MaxReviveWaitTick = 8000;

public:
    BotAIRevive(Player* self) : me(self), m_ReviveTick(0) {}
    ~BotAIRevive() {}

    void UpdateRevive(uint32 diff);

private:
    void ReviveMe();

private:
    uint32 m_ReviveTick;
    Player* me;
};

class BotAIFieldRevive
{
    static const uint32 c_MaxReviveWaitTick = 20000;

public:
    BotAIFieldRevive(Player* self) : me(self), m_ReviveTick(0), m_TickOvered(false) {}
    ~BotAIFieldRevive() {}

    void UpdateRevive(uint32 diff, BotAITeleport& teleport);

private:
    void TeleportToAround(BotAITeleport& teleport);
    void ReviveMe();

private:
    uint32 m_ReviveTick;
    bool m_TickOvered;
    Player* me;
};

class BotAIRevivePlayer
{
public:
    BotAIRevivePlayer(Player* self) : me(self) {}
    ~BotAIRevivePlayer() {}

    ObjectGuid SearchNeedRevive(uint32 diff);

private:
    bool CanRevivePlayer();

private:
    Player* me;
};

class BotAIFlee
{
    struct PVEFleePosition
    {
        Position fleePosition;
        uint32 enemyCount;
        float byMeDist;
        float byMasterDist;
        PVEFleePosition() : enemyCount(0), byMeDist(0), byMasterDist(0)
        {

        }
        bool operator < (const PVEFleePosition& fleePos)
        {
            return byMeDist > fleePos.byMeDist;
        }
    };

public:
    BotAIFlee(Player* self) : me(self), m_FleeTarget(NULL), m_FleeTick(0), m_cruxTime(0) {}
    ~BotAIFlee() {}

    void Clear() { if (m_FleeTarget) { delete m_FleeTarget; m_FleeTarget = NULL; } m_FleeTick = 0; m_cruxTime = 0; }
    bool Fleeing() { return m_FleeTarget != NULL; }
    void UpdateFleeMovementByPVE(Unit* pMaster, Unit* pRefUnit, BotBGAIMovement* pMovement);
    void UpdateFleeMovementByPVP(Unit* pRefUnit, BotBGAIMovement* pMovement);
    void UpdateFleeMovementByPosition(Unit* pRefUnit, Position centerPos, float maxPosDist, BotBGAIMovement* pMovement);
    float CalcMaxFleeDistance(Unit* pRefUnit);
    void AddCruxFlee(uint32 durTime, Unit* pRefUnit, BotBGAIMovement* pMovement);

private:
    bool CanFleeToTargetPlayer(Player* player);
    bool SearchPVEFleePosition(Unit* pMaster, Unit* pRefUnit, Position& fleePos);
    void SearchCreatureListFromRange(Position centerPos, std::list<Creature*>& nearCreatures, float range);
    Position CalculateFlee(float dist, float angle, Unit* pRefUnit, float& outDistance);

private:
    Player* me;
    Position* m_FleeTarget;
    uint32 m_FleeTick;
    uint32 m_cruxTime;
};

class BotAIIDLEMovement
{
public:
    BotAIIDLEMovement(Player* self) : me(self), m_IDLETarget(NULL), m_IDLETick(0) {}
    ~BotAIIDLEMovement() {}

    void Clear() { if (m_IDLETarget) { delete m_IDLETarget; m_IDLETarget = NULL; } m_IDLETick = 0; }
    bool Moveing() { return m_IDLETarget != NULL; }
    void UpdateIDLEMovement(BotBGAIMovement* pMovement);

private:
    Position CalculateIDLE(float dist, float angle, float& outDistance);

private:
    Player* me;
    Position* m_IDLETarget;
    uint32 m_IDLETick;
};

class BotAICruxMovement
{
public:
    BotAICruxMovement(Player* self) : me(self), m_MovementTarget(NULL), m_LastFleeDistance(0) {}
    ~BotAICruxMovement() {}

    void ClearMovement() { if (m_MovementTarget) { delete m_MovementTarget; m_MovementTarget = NULL; } m_LastFleeDistance = 0; }
    bool HasCruxMovement() { return m_MovementTarget != NULL; }
    void SetMovement(Position& pos);
    void RandomMovement(float range = NEEDFLEE_CHECKRANGE);
    void UpdateCruxMovement(BotBGAIMovement* pMovement);

private:
    Player* me;
    Position* m_MovementTarget;
    float m_LastFleeDistance;
};

class BotAITankTarget
{
public:
    BotAITankTarget(Player* self) : me(self), m_MovementTarget(NULL), m_MovementTick(0) {}
    ~BotAITankTarget() {}

    void ClearTarget();
    void SetMovement(Position& pos);
    void AddTarget(Creature* pCreature);
    bool IsSelfTarget(ObjectGuid target);
    bool AllTargetPullMe();
    bool ExistPullTarget();
    Creature* GetNeedPullTarget();
    bool UpdateTankTarget(BotBGAIMovement* pMovement);

private:
    Player* me;
    Position* m_MovementTarget;
    uint32 m_MovementTick;
    std::vector<ObjectGuid> m_Targets;
};

class BotAIFly
{
public:
    BotAIFly(Player* self) : me(self), m_FlyMountID(0), m_LastFlyPos(self->GetPosition()) {}
    ~BotAIFly() {}

    bool HasFlying();
    void CancelFly();
    void RandomFlyMount();
    void FlyToTarget(Player* player, bool offset);
    void UpdateFly(Player* masterPlayer, uint32 groundMountID, BotBGAIMovement* pMovement);

private:
    Player* me;
    uint32 m_FlyMountID;
    Position m_LastFlyPos;
};

class BotAIWishStore
{
    typedef std::map<uint32, std::set<ObjectGuid> > WISH_STORES;

public:
    BotAIWishStore(Player* self) : me(self), m_LastWishTick(0) {}
    ~BotAIWishStore() {}

    void ClearWishs() { m_WishStores.clear(); m_LastWishTick = 0; }
    void ClearStores();
    void RegisterWish(uint32 entry);
    bool CanWishStore(uint32 entry, Unit* pTarget);
    bool TryWishStore(uint32 entry, Unit* pTarget);
    void UpdateWishStore();

private:
    Player* me;
    WISH_STORES m_WishStores;
    uint32 m_LastWishTick;
};

class BotAICheckSetting
{
public:
    BotAICheckSetting(Player* self) : me(self), m_LastCheckTick(getMSTime()) {}
    ~BotAICheckSetting() {}

    void UpdateCheckSetting();

private:
    bool NeedResetSetting();
    bool CheckEquip();

private:
    Player* me;
    uint32 m_LastCheckTick;
};

class BotAIFliterCreatures
{
public:
    BotAIFliterCreatures(Player* self) : me(self), m_FliterTime(5000) {}
    ~BotAIFliterCreatures() {}

    bool IsFliterCreature(Creature* pCreature);
    void UpdateFliterCreature(Creature* pCreature);
    void RemoveFliterCreature(Creature* pCreature);

private:
    Player* me;
    uint32 m_FliterTime;
    std::map<Creature*, uint32> m_Fliters;
};

class BotAIWaitSpecialAura
{
public:
    BotAIWaitSpecialAura(Player* self) : me(self) {}
    ~BotAIWaitSpecialAura() {}

    void AddSpecialAura(uint32 id);
    bool HasNeedWaitAura();

private:
    Player* me;
    std::set<uint32> m_NeedWaitAuras;
};

class BotAINeedFleeAura
{
public:
    BotAINeedFleeAura(Player* self) : me(self)
    {
        m_NeedFleeAuras.push_back(46924);
    }
    ~BotAINeedFleeAura() {}

    void AddFleeAura(uint32 aura);
    bool TargetHasFleeAura() { return TargetHasFleeAura(me->GetSelectedPlayer()); };
    /*bool TargetHasFleeAura(ObjectGuid targetGUID) {
        return TargetHasFleeAura(ObjectAccessor::FindPlayer(targetGUID));
    };*/
    bool TargetHasFleeAura(Unit* pTarget);

private:
    Player* me;
    std::list<uint32> m_NeedFleeAuras;
};

class BotAIRecordCastSpell
{
    struct CastedSpell
    {
        CastedSpell() {}
        CastedSpell(ObjectGuid guid)
        {
            castTarget = guid;
        }
        ObjectGuid castTarget;
        std::map<uint32, uint32> castRecords;
    };
    typedef std::map<ObjectGuid, CastedSpell> AIRECORDS;

public:
    BotAIRecordCastSpell(Player* self) : me(self) {}
    ~BotAIRecordCastSpell() {}

    void ClearRecordSpell() { m_Records.clear(); }
    void RecordCastSpellTick(Unit* pTarget, uint32 spellID);
    bool MatchCastRecord(Unit* pTarget, uint32 spellID, uint32 tickGap);

private:
    Player* me;
    AIRECORDS m_Records;
};

class BotAICheckDuel
{
public:
    BotAICheckDuel(Player* self) : me(self) {}
    ~BotAICheckDuel() {}

    bool CheckDuel();

private:
    Player* me;
};

class BotAIGroupLeader
{
public:
    BotAIGroupLeader(Player* self) : me(self) {}
    ~BotAIGroupLeader() {}

    void ProcessGroupLeader();

private:
    Player* me;
};

class BotAIMovetoUseGO
{
public:
    BotAIMovetoUseGO(Player* self) : me(self), m_UseGO(ObjectGuid::Empty), m_RiteSpellID(0) {}
    ~BotAIMovetoUseGO() {}

    bool CanCastSummonRite();
    bool CastingSummonRite() { return m_RiteSpellID != 0; }
    void ClearUseGO() { m_UseGO = ObjectGuid::Empty; m_RiteSpellID = 0; }
    void StartSummonRite(uint32 spellID);
    bool SetNeedMovetoUseGO(ObjectGuid guid);
    bool ProcessMovetoUseGO(BotBGAIMovement* pMovement);

private:
    Player* me;
    ObjectGuid m_UseGO;
    uint32 m_RiteSpellID;
};

class BotAIMoveToHaltPosition
{
public:
    BotAIMoveToHaltPosition(Player* self) : me(self), m_MovetoPos(0, 0, 0, 0), m_MovetoTick(0) {}
    ~BotAIMoveToHaltPosition() {}

    void ClearMoveto() { m_MovetoPos = Position(); m_MovetoTick = 0; m_CurrentTick = 0; }
    bool HasMoveto() { return (m_MovetoPos.GetPositionX() != 0 && m_MovetoPos.GetPosition() != 0 && m_MovetoPos.GetPositionZ() != 0); }
    void SetMovetoPos(Position pos, uint32 dur = 1000) { m_MovetoPos = pos; m_MovetoTick = dur; m_CurrentTick = 0; }
    bool ProcessMovetoPosition(BotBGAIMovement* pMovement);

private:
    Player* me;
    Position m_MovetoPos;
    uint32 m_MovetoTick;
    uint32 m_CurrentTick;
};

#endif


