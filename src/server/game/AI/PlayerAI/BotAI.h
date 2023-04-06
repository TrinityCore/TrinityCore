
#ifndef _BOT_AI_H_
#define _BOT_AI_H_

#include "BotAITool.h"
#include "AIWaypointsMgr.h"
#include "SpellMgr.h"
#include "PlayerBotSetting.h"
#include "GridNotifiers.h"
#include <mutex>

enum BotAIBGState
{
	AIBGState_Ready,
	AIBGState_Start,
	AIBGState_Leave
};

enum MonkTalentType
{
    MonkTalent_BrewMaster,
    MonkTalent_BattleDancer,
    MonkTalent_MistWeaver
};

enum DruidTalentType
{
    DruidTalent_Bird,
    DruidTalent_Cat,
    DruidTalent_Bear,     
    DruidTalent_Restoration
};

enum HunterTalentType
{
    HunterTalent_BreastMaster,
    HunterTalent_Marksman,
    HunterTalent_Survival
};

enum DeathknightTalentType
{
    DeathknightTalent_Blood,
    DeathknightTalent_Frost,
    DeathknightTalent_Unholy
};

enum RogueTalentType
{
    RogueTalent_Assassination,
    RogueTalent_Combat,
    RogueTalent_Subtlety
};

enum WarlockTalentType
{
    WarlockTalent_Pain,
    WarlockTalent_Demon,
    WarlockTalent_Ruin
};

class Player;
class BotBGAIMovement;
struct PathParameter;

typedef std::set<uint32> UINT_SET;
typedef std::queue<PathParameter*> MoveParameterQueue;
typedef std::list<GameObject*> NearObjectList;
typedef std::list<Player*> NearPlayerList;
typedef std::vector<Player*> NearPlayerVec;
typedef std::list<Creature*> NearCreatureList;
typedef std::vector<Creature*> NearCreatureVec;
typedef std::list<Unit*> NearUnitList;
typedef std::vector<Unit*> NearUnitVec;

class BotBGAI : public PlayerAI
{
public:
	const static uint32 c_Alliance_Faction = 84;
	const static uint32 c_Horde_Faction = 83;
	static BotBGAI* CreateBotBGAIByPlayerClass(Player* player);
	static BotBGAI* debugBGAI;

public:
	BotBGAI(Player* player);
	~BotBGAI();

	void DamageDealt(Unit* victim, uint32& damage, DamageEffectType damageType) override;
	void DamageEndure(Unit* attacker, uint32& damage, DamageEffectType damageType);
	void UpdateAI(uint32 diff) override;
	virtual void UpdateBotAI(uint32 diff);
	virtual void ResetBotAI();
	void SetTeleport(Position& telePos) { m_Teleporting.SetTeleport(telePos); }
    void SetTeleport(uint32 mapId, Position& telePos) { m_Teleporting.SetTeleport(mapId, telePos); }
	void ReadyBattleground();
	void StartBattleground() { m_AIBGStateType = BotAIBGState::AIBGState_Start; }
	void LeaveBattleground() { m_AIBGStateType = BotAIBGState::AIBGState_Leave; }
	void PushFinishQueue(PathParameter* pathParam);
	bool CanUseBGObject();
	NearObjectList SearchGameObject(float range);
	bool TryUpMount();
	void Dismount();

	virtual bool CastingControlCommandSpell() { return false; }
	void SetNonSelectTarget(ObjectGuid guid) { m_LastControlTarget = guid; }
	void SetReserveCtrlSpell(bool reserve) { m_NeedReserveCtrlSpell = reserve; if (!reserve) m_LastControlTarget = ObjectGuid::Empty; }
	void ClearCruxControlCommand() { m_CruxControlTarget = ObjectGuid::Empty; m_LastControlTarget = ObjectGuid::Empty; m_NeedReserveCtrlSpell = false; }
	bool HasCruxControlTarget() { return m_CruxControlTarget != ObjectGuid::Empty; }
	DiminishingGroup GetControlSpellDiminishingGroup();
	virtual float TryPushControlCommand(Player* /*pTarget*/) { return -1; }

	BotBGAIMovement* GetAIMovement() { return m_Movement; }
	void SetNeedFindpathSearch() { m_NeedFindpathSearch = true; }
	bool IsNotSelect(Unit* pTarget);
	bool NearHasEnemy(float range = BOTAI_RANGESPELL_DISTANCE) { return RangeEnemyListByHasAura(0, range).size() > 0; }

	bool CastingSummonRite() { return m_MovetoUseGO.CastingSummonRite(); }
	bool SetMovetoUseGOTarget(ObjectGuid target) { return m_MovetoUseGO.SetNeedMovetoUseGO(target); }
	void ProcessBotCommand(Player* srcPlayer, std::string cmd);

protected:
	bool CanReciveCommand(std::string& cmd, std::string& param);
	void ProcessSummonRiteSpell(Player* srcPlayer);
	void ProcessAttackCommand(Player* srcPlayer);

	bool IsAlive();
	void ProcessHorror(uint32 diff);
	bool TargetIsNotDiminishingByType(Unit* pTarget, DiminishingGroup diType);
	bool TargetIsNotDiminishingByType2(Unit* pTarget, DiminishingGroup diType);
	bool HasAuraMechanic(Unit* pTarget, Mechanics mask);
	bool IsNotMovement();
	bool IsInvincible(Unit* pTarget);
	uint32 FindMaxRankSpellByExist(uint32 spellID);
	uint32 FindPetMaxRankSpellByExist(uint32 spellID);
	bool InBattleground();
	void BattlegroundRevive();
	void ProcessHealth();
	void ProcessCombat(Unit* pTarget);
	void ChaseTarget(Unit* pTarget, bool isMelee, float range = 5.0f);
	void SearchCreatureListFromRange(Unit* center, NearCreatureVec& nearCreatures, float range, bool selfFaction);
	Unit* SearchEnemy(float range = BOTAI_SEARCH_RANGE);
	NearUnitVec SearchFriend(float range = BOTAI_SEARCH_RANGE);
	NearUnitVec SearchFriendTargetIsTarget(Unit* pTarget, float range = BOTAI_SEARCH_RANGE);
	NearPlayerVec SearchFarFriend(float minRange, float maxRange, bool isIDLE);
	NearPlayerVec ExistFriendAttacker(float range = BOTAI_RANGESPELL_DISTANCE);
	NearUnitVec SearchNeedHealth(float range = BOTAI_SEARCH_RANGE);
	NearUnitVec BeforeSearchNeedHealth(float range, float minHeal);
	NearUnitVec SearchLifePctByFriendRange(Unit* pTarget, float lifePct, float range = NEEDFLEE_CHECKRANGE);
	bool NeedDireFlee();
	bool DoDireFlee();
	bool DoFaceToTarget(Unit* pTarget);
	SpellCastResult TryCastSpell(uint32 spellID, Unit* pTarget = NULL, bool force = false, bool dismount = true);
	SpellCastResult PetTryCastSpell(uint32 spellID, Unit* pTarget = NULL, bool force = false);
	virtual uint32 TryCastSummonRiteSpell() { return 0; }
	void SettingPetAutoCastSpell(uint32 spellID, bool autoCast);

	Unit* RandomRangeEnemyByCasting(float range);
	NearUnitVec RangeEnemyListByHasAura(uint32 aura, float range);
	NearUnitVec RangeEnemyListByNonAura(uint32 aura, float range);
	NearUnitVec RangeEnemyListByTargetIsMe(float range);
	NearUnitVec RangeListByTargetIsTarget(Unit* pTarget, float range);
	NearUnitVec RangeEnemyListByTargetRange(Unit* pTarget, float range);
	NearUnitVec SearchFarEnemy(float minRange, float maxRange);

	virtual void EachTick();
	virtual bool HaveManaStore() { return true; }
	virtual void ClearMechanicAura() {}
	virtual bool NeedWaitSpecialSpell(uint32 diff);
	virtual bool NeedFlee();
	virtual void FleeMovement();
	virtual void ProcessReady();
	virtual void ProcessFlee() {}
	virtual bool ProcessNormalSpell() { return false; }
	virtual void ProcessRangeSpell(Unit* /*pTarget*/) {}
	virtual void ProcessMeleeSpell(Unit* /*pTarget*/) {}
	virtual void ProcessHealthSpell(Unit* /*pTarget*/) {}

	virtual bool IsMeleeBotAI();
	virtual bool IsRangeBotAI();
	virtual bool IsHealerBotAI();
	virtual bool IsAttacker() { return true; }
	virtual bool TryStartControlCommand() { ClearCruxControlCommand(); return false; }

	Unit* GetBotAIValidSelectedUnit();
	bool TargetIsControl(Unit* pTarget);
	bool TargetIsMelee(Player* pTarget);
	bool TargetIsRange(Player* pTarget);
	bool TargetIsMagic(Player* pTarget);
	bool TargetIsHealth(Player* pTarget);
	bool TargetCanManaBurn(Player* pTarget);
	bool TargetIsCastMagic(Player* pTarget);
	bool TargetIsStealth(Player* pTarget);
	uint32 TargetManaPCT(Unit* pTarget);

	bool IsSelfFaction(Unit* pTarget, uint32 faction);
	bool IsFilterCreatureByEntry(uint32 entry);
	bool IsFleeTargetByRangeBot(Unit* pTarget);
	//bool IsForceTarget() { return m_IsFlagTarget; }

private:
	void QueryNearCreatureList(float range, NearCreatureList& creatureList);
	void QueryNearPlayerList(float range, NearPlayerList& playerList);

protected:
	bool m_NeedFindpathSearch;
	int32 m_UpmountTick;
	BotAIBGState m_AIBGStateType;
	int32 m_UpdateTick;
	int32 m_CanDireFlee;
	BotBGAIMovement* m_Movement;
	uint32 m_CurrentTargetTick;

	uint32 m_UseMountID;
	BotAIHorrorState* pHorrorState;
	BotAIStoped m_CheckStoped;
	BotAITeleport m_Teleporting;
	BotAIUsePotion m_UsePotion;
	BotAIFlee m_Flee;
	BotAINeedFleeAura m_NeedFlee;
	BotAIRecordCastSpell m_CastRecords;
	BotAIFastAid m_FastAid;
	BotAIGroupLeader m_GroupLeader;
	BotAIMovetoUseGO m_MovetoUseGO;
	std::mutex m_movQueueLock;
	MoveParameterQueue m_pfFinishQueue;

	Position m_InitRndPos;

	bool m_IsMeleeBot;
	bool m_IsRangeBot;
	bool m_IsHealerBot;

	ObjectGuid m_CruxControlTarget;
	ObjectGuid m_LastControlTarget;
	bool m_NeedReserveCtrlSpell;

	std::map<float, NearCreatureList> m_RangeCreatureLists;
	std::map<float, NearPlayerList> m_RangePlayerLists;

	UINT_SET m_FilterCreatureEntrys;

	uint32 BotCommon_ClearAllCtrl;// = 59752;		// ??
	uint32 m_lastClearCtrlTick;
};

#endif // !_BOT_AI_H_
