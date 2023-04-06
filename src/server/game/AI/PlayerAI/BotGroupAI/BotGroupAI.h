
#ifndef _BOT_GROUP_AI_H
#define _BOT_GROUP_AI_H

#include "BotAITool.h"
#include "BotAISpells.h"
#include "SpellMgr.h"
#include "PlayerBotSetting.h"
#include "GridNotifiers.h"
#include "MotionMaster.h"
#include <mutex>

class Player;
class BotBGAIMovement;
class BotAIVehicleMovement3D;

typedef std::list<Player*> NearPlayerList;
typedef std::vector<Player*> NearPlayerVec;
typedef std::list<Creature*> NearCreatureList;
typedef std::vector<Creature*> NearCreatureVec;
typedef std::list<Unit*> NearUnitList;
typedef std::vector<Unit*> NearUnitVec;

class BotGroupAI : public PlayerAI
{
public:
	static BotGroupAI* CreateBotGroupAIByPlayerClass(Player* player);
	static BotGroupAI* debugGroupAI;

public:
	BotGroupAI(Player* player);
	~BotGroupAI();

	Player* GetAIPayer() { return me; }
	void ProcessBotCommand(Player* srcPlayer, std::string cmd);
	void DamageDealt(Unit* victim, uint32& damage, DamageEffectType damageType) override;
	void DamageEndure(Unit* attacker, uint32& damage, DamageEffectType damageType);
	void UpdateAI(uint32 diff) override;
	virtual void ResetBotAI();
	void StartFullDispel();
	void ClearFullDispel() { m_FullDispel = 0; }
	bool HasTeleport() { return !m_Teleporting.CanMovement(); }
	void SetTeleport(Position& telePos) { m_Teleporting.SetTeleport(telePos); }
    void SetTeleport(uint32 mapId, Position& telePos) { m_Teleporting.SetTeleport(mapId, telePos); }
	void SetTeleportToMaster() { m_Teleporting.SetTeleport(m_MasterPlayer, 0); }
	void UpdateTeleport(uint32 diff) { m_Teleporting.Update(diff, m_Movement); }
	void ClearCruxMovement();
	void SetCruxMovement(Position& pos) { me->SetSelection(ObjectGuid::Empty); m_CruxMovement.SetMovement(pos); }
	void RndCruxMovement(float dist = 12.0f) { m_CruxMovement.RandomMovement(dist); }
	void AddTankTarget(Creature* pCreature);
	void ClearTankTarget() { m_TankTargets.ClearTarget(); }
	void SetTankPosition(Position& pos) { m_TankTargets.SetMovement(pos); }
	bool ExistPullTarget() { return m_TankTargets.ExistPullTarget(); }
	bool IsNotSelect(Unit* pTarget);
	bool IsIDLEBot();
	bool CanExecuteSeduce();
	virtual uint32 GetSeducePriority() { return 0; }
	virtual void OnLevelUp(uint32 talentType);
	void OnLootedItem(uint32 entry);
	void DelayGiveXP(uint32 xp) { m_DelayGiveXP.DelayAddXP(xp); }
	void SearchCreatureListFromRange(Unit* center, NearCreatureVec& nearCreatures, float range, bool selfFaction);
	void ToggleFliterCreature(Creature* pCreature, bool fliter);
	virtual bool TryBlockCastingByTarget(Unit* /*pTarget*/) { return false; }
	bool IsFleeing() { return m_Flee.Fleeing(); }
	void AddCruxFlee(uint32 dur, Unit* pRefUnit) { if(me->IsAlive()) m_Flee.AddCruxFlee(dur, pRefUnit, m_Movement); }
	void AddWaitSpecialAura(uint32 aura) { m_WaitAuras.AddSpecialAura(aura); }
	virtual bool ProcessPullSpell(Unit* /*pTarget*/) { return false; }
	void SetCruxHealTarget(ObjectGuid& healTarget) { if (IsHealerBotAI()) m_CruxHealTarget = healTarget; else m_CruxHealTarget = ObjectGuid::Empty; }
	void SetForceFleeState(bool forceFlee) { m_ForceFlee = forceFlee; }
	void SetSeduceTarget(ObjectGuid target) { m_SeduceTarget = target; me->SetSelection(m_SeduceTarget); }
	bool CastingSummonRite() { return m_MovetoUseGO.CastingSummonRite(); }
	bool SetMovetoUseGOTarget(ObjectGuid target) { return m_MovetoUseGO.SetNeedMovetoUseGO(target); }
	void Dismount();

	void SetVehicle3DNextMoveGap(float gap);
	void SetVehicle3DMoveTarget(Unit* pTarget, float offset);
	void SetMovetoHaltPos(Position& pos, uint32 dur = 1000) { m_MovetoHaltPos.SetMovetoPos(pos, dur); }

protected:
	bool TryUpMount();
	bool CanReciveCommand(std::string& cmd, std::string& param);
	void ProcessSummonCommand();
	void ProcessAttackCommand();
	void ProcessFleeCommand();
	void ProcessStopCommand();
	void ProcessSetting();
	void ProcessListEquip(Player* srcPlayer);
	void ProcessUpequip(Player* srcPlayer, std::string& equipLink);
	void ProcessUnequip(Player* srcPlayer, std::string& equipLink);
	void ProcessDestroyItem(Player* srcPlayer, std::string& equipLink);
	void ProcessTradeItem(Player* srcPlayer, std::string& equipLink);
	void ProcessUseItem(Player* srcPlayer, std::string& equipLink);
	void ProcessTalent(Player* srcPlayer, std::string& talentText);
    void ProcessTalentTo(Player* srcPlayer, std::string talentText);
	void ProcessSummonRiteSpell(Player* srcPlayer);

protected:
	void ProcessHorror(uint32 diff);
	bool TargetIsNotDiminishingByType(Unit* pTarget, DiminishingGroup diType);
	bool TargetIsNotDiminishingByType2(Unit* pTarget, DiminishingGroup diType);
	bool HasAuraMechanic(Unit* pTarget, Mechanics mask);
	bool IsNotMovement();
	bool IsInvincible(Unit* pTarget);

	virtual void UpEnergy() {}
	bool UpdateMasterPlayer();
	bool TrySettingToMaster();
	bool TryTeleportToMaster();
	virtual Unit* GetCombatTarget(float range = BOTAI_SEARCH_RANGE);
	void ProcessFollowToMaster();
	bool NonCombatProcess();
	bool ProcessRevivePlayer();
	bool DoFaceToTarget(Unit* pTarget);
	SpellCastResult TryCastSpell(uint32 spellID, Unit* pTarget = NULL, bool force = false, bool dismount = true);
	SpellCastResult TryCastSpellByLifePCTInterrupt(uint32 spellID, Unit* pTarget = NULL, uint32 interruptByLife = 99);
	SpellCastResult TryCastPullSpell(uint32 spellID, Unit* pTarget = NULL);
	SpellCastResult PetTryCastSpell(uint32 spellID, Unit* pTarget = NULL, bool force = false);
	virtual uint32 TryCastSummonRiteSpell() { return 0; }
	void SettingPetAutoCastSpell(uint32 spellID, bool autoCast);

	virtual void ClearMechanicAura() {}
	virtual bool NeedWaitSpecialSpell(uint32 diff);
	virtual bool NeedFlee();
	void FleeMovement();
	virtual void ProcessFlee();
	virtual bool ProcessNormalSpell() { return false; }
	virtual void ProcessRangeSpell(Unit* /*pTarget*/) {}
	virtual void ProcessMeleeSpell(Unit* /*pTarget*/) {}
	virtual void ProcessPrepareHealthSpell(Unit* /*pTarget*/) {}
	virtual void ProcessHealthSpell(Unit* /*pTarget*/) {}
	virtual void ProcessSeduceSpell(Unit* /*pTarget*/) {}
	virtual bool ProcessFullDispel() { m_FullDispel = 0; return false; }
	bool ExecuteSeduceCommand();
	void ProcessPrepareHealth();
	void ProcessHealth(bool canMove);
	void ProcessCombat(Unit* pTarget);
	void ProcessHalt(Unit* pTarget);
	bool ProcessTank(Unit* pTarget);

	void ChaseTarget(Unit* pTarget, bool isMelee, float range = 3.0f);
	NearUnitVec SearchFriend(float range = BOTAI_SEARCH_RANGE);
	NearUnitVec SearchFriendTargetIsTarget(Unit* pTarget, float range = BOTAI_SEARCH_RANGE);
	NearPlayerVec SearchFarFriend(float minRange, float maxRange, bool isIDLE);
	NearPlayerVec ExistFriendAttacker(float range = BOTAI_RANGESPELL_DISTANCE);
	NearUnitVec SearchNeedHealth(float range = BOTAI_SEARCH_RANGE);
	NearUnitVec SearchLifePctByFriendRange(Unit* pTarget, float lifePct, float range = NEEDFLEE_CHECKRANGE);
	Unit* RandomRangeEnemyByCasting(float range);
	Unit* SearchTankTargetEnemy(float range = BOTAI_SEARCH_RANGE);
	NearUnitVec RangeEnemyListByHasAura(uint32 aura, float range);
	NearUnitVec RangeEnemyListByNonAura(uint32 aura, float range);
	NearUnitVec RangeEnemyListByTargetIsMe(float range);
	NearUnitVec RangeListByTargetIsTarget(Unit* pTarget, float range);
	NearUnitVec RangeEnemyListByTargetRange(Unit* pTarget, float range);
	NearUnitVec SearchFarEnemy(float minRange, float maxRange);

	Unit* GetBotAIValidSelectedUnit();
	bool TargetIsControl(Unit* pTarget);
	bool TargetIsMelee(Player* pTarget);
	bool TargetIsRange(Player* pTarget);
	bool TargetIsMagic(Player* pTarget);
	bool TargetIsCastMagic(Player* pTarget);
	bool TargetIsStealth(Player* pTarget);

public:
	virtual uint32 GetReviveSpell() { return 0; }
    virtual bool IsTankBotAI() { return ((me->GetClass() == CLASS_WARRIOR && me->GetSpecializationId() == TALENT_SPEC_WARRIOR_PROTECTION) || (me->GetClass() == CLASS_PALADIN && me->GetSpecializationId() == TALENT_SPEC_PALADIN_PROTECTION) || (me->GetClass() == CLASS_DRUID && me->GetSpecializationId() == TALENT_SPEC_DRUID_BEAR) || (me->getClass() == CLASS_DEATH_KNIGHT && me->GetSpecializationId() == TALENT_SPEC_DEATHKNIGHT_BLOOD) || (me->GetClass() == CLASS_MONK && me->GetSpecializationId() == TALENT_SPEC_MONK_BREWMASTER) || (me->getClass() == CLASS_DEMON_HUNTER && me->GetSpecializationId() == TALENT_SPEC_DEMON_HUNTER_VENGEANCE)); }
	virtual bool IsMeleeBotAI();
	virtual bool IsRangeBotAI();
	virtual bool IsHealerBotAI();
	virtual bool IsAttacker() { return true; }
    void ProcessMoveToCommand(float x, float y, float z, float o, float offset = 0.0f);
protected:
	int32 m_UpdateTick;
	uint32 m_DuelEmoteTick;
	uint32 m_UseMountID;

	BotBGAIMovement* m_Movement;
	BotAIVehicleMovement3D* m_VehicleMovement3D;
	BotAIGuild m_Guild;
	BotAIHorrorState* pHorrorState;
	BotAIStoped m_CheckStoped;
	BotAITeleport m_Teleporting;
	BotAIUseFood m_UseFood;
	BotAIUsePotion m_UsePotion;
	BotAIFindNearLoot m_FindLoot;
	BotAILootedItems m_LootedItems;
	BotAITrade m_AITrade;
	BotAIGiveXP m_DelayGiveXP;
	BotAIRevive m_Revive;
	BotAIRevivePlayer m_RevivePlayer;
	BotAIFlee m_Flee;
	BotAICruxMovement m_CruxMovement;
	BotAITankTarget m_TankTargets;
	BotAIFly m_Flying;
	BotAIWishStore m_WishStore;
	BotAIFliterCreatures m_FliterCreatures;
	BotAIWaitSpecialAura m_WaitAuras;
	BotAICheckDuel m_CheckDuel;
	BotAIFastAid m_FastAid;
	BotAIMovetoUseGO m_MovetoUseGO;
	BotAIGroupLeader m_GroupLeader;
	BotAIMoveToHaltPosition m_MovetoHaltPos;

	ObjectGuid m_CruxHealTarget;
	ObjectGuid m_SeduceTarget;
	Player* m_MasterPlayer;
	uint32 m_FullDispel;
	uint32 m_MeleeFleeTick;
	bool m_ForceFlee;
	bool m_StopFollow;
	bool m_HasReset;
    bool m_UpdateEquit;

	bool m_IsMeleeBot;
	bool m_IsRangeBot;
	bool m_IsHealerBot;

	std::mutex m_ItemLock;

public:
	static bool PVE_MAX_DUNGEON;
	static bool PVE_DRIVING;
	static bool PVE_PULL;
};

#endif // !_BOT_GROUP_AI_H
