
#ifndef _BOT_DUEL_AI_H_
#define _BOT_DUEL_AI_H_

#include "BotAITool.h"
#include "BotAISpells.h"
#include "AIWaypointsMgr.h"
#include "SpellMgr.h"
#include "PlayerBotSetting.h"
#include "GridNotifiers.h"
#include <mutex>

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

class BotDuelAI : public PlayerAI
{
public:
	const static uint32 c_Alliance_Faction = 84;
	const static uint32 c_Horde_Faction = 83;
	static BotDuelAI* CreateBotDuelAIByPlayerClass(Player* player);

public:
	BotDuelAI(Player* player);
	~BotDuelAI();

	void UpdateAI(uint32 diff) override;
	virtual void UpdateBotAI(uint32 diff);
	virtual void ResetBotAI();
	void SetTeleport(Position& telePos) { m_Teleporting.SetTeleport(telePos); }
    void SetTeleport(uint32 mapId, Position& telePos) { m_Teleporting.SetTeleport(mapId, telePos); }
	NearObjectList SearchGameObject(float range);
	bool TryUpMount();
	void Dismount();

	BotBGAIMovement* GetAIMovement() { return m_Movement; }
	bool IsNotSelect(Unit* pTarget);

protected:
	bool TryFinishDuel();
	bool DuelIsStart();
	void ProcessHorror(uint32 diff);
	bool TargetIsNotDiminishingByType(Unit* pTarget, DiminishingGroup diType);
	bool TargetIsNotDiminishingByType2(Unit* pTarget, DiminishingGroup diType);
	bool HasAuraMechanic(Unit* pTarget, Mechanics mask);
	bool IsNotMovement();
	bool IsInvincible(Unit* pTarget);
	uint32 FindMaxRankSpellByExist(uint32 spellID);
	uint32 FindPetMaxRankSpellByExist(uint32 spellID);
	Unit* GetDuelEnemy();
	Position GetDuelCenterPosition();
	void ProcessHealth();
	void ProcessCombat(Unit* pTarget);
	void ChaseTarget(Unit* pTarget, bool isMelee, float range = 5.0f);
	bool DoFaceToTarget(Unit* pTarget);
	SpellCastResult TryCastSpell(uint32 spellID, Unit* pTarget = NULL, bool force = false, bool dismount = true);
	SpellCastResult PetTryCastSpell(uint32 spellID, Unit* pTarget = NULL, bool force = false);
	void SettingPetAutoCastSpell(uint32 spellID, bool autoCast);

	virtual void EachTick();
	virtual bool HaveManaStore() { return true; }
	virtual void ClearMechanicAura() {}
	virtual bool NeedWaitSpecialSpell(uint32 diff);
	virtual bool NeedFlee();
	virtual void FleeMovement();
	virtual void ProcessFlee() {}
	virtual void ProcessRangeSpell(Unit* /*pTarget*/) {}
	virtual void ProcessMeleeSpell(Unit* /*pTarget*/) {}
	virtual void ProcessHealthSpell(Unit* /*pTarget*/) {}

	virtual bool IsMeleeBotAI();
	virtual bool IsRangeBotAI();
	virtual bool IsHealerBotAI();
	virtual bool IsAttacker() { return true; }

	bool TargetIsMelee(Player* pTarget);
	bool TargetIsRange(Player* pTarget);
	bool TargetIsMagic(Player* pTarget);
	bool TargetIsHealth(Player* pTarget);
	bool TargetCanManaBurn(Player* pTarget);
	bool TargetIsCastMagic(Player* pTarget);
	bool TargetIsStealth(Player* pTarget);
	uint32 TargetManaPCT(Unit* pTarget);

	bool IsFleeTargetByRangeBot(Unit* pTarget);

protected:
	bool m_NeedFindpathSearch;
	int32 m_UpdateTick;
	BotBGAIMovement* m_Movement;

	uint32 m_UseMountID;
	BotAIHorrorState* pHorrorState;
	BotAIStoped m_CheckStoped;
	BotAITeleport m_Teleporting;
	BotAIUsePotion m_UsePotion;
	BotAIFlee m_Flee;
	BotAINeedFleeAura m_NeedFlee;
	BotAIRecordCastSpell m_CastRecords;

	Position m_InitRndPos;

	bool m_IsMeleeBot;
	bool m_IsRangeBot;
	bool m_IsHealerBot;

	uint32 BotCommon_ClearAllCtrl;// = 59752;		// ??
	uint32 m_lastClearCtrlTick;
};

#endif // !_BOT_DUEL_AI_H_
