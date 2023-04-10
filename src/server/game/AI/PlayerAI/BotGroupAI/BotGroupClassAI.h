
#ifndef _BOT_GROUP_CLASS_AI_H_
#define _BOT_GROUP_CLASS_AI_H_

#include "ScriptSystem.h"
#include "BotGroupAI.h"

class GroupWarriorAI : public BotGroupAI, public BotWarriorSpells
{
public:
	GroupWarriorAI(Player* player) :
		BotGroupAI(player),
		m_BotTalentType(0),
		m_ChargeWaitTick(0)
	{}
	~GroupWarriorAI() {}

	void ResetBotAI() override;
	uint32 GetSeducePriority() override;
	void OnLevelUp(uint32 talentType) override;
	bool TryBlockCastingByTarget(Unit* pTarget) override;
	bool ProcessPullSpell(Unit* pTarget) override;

protected:
	uint32 GetRagePowerPer();
	void ClearMechanicAura() override;
	bool NeedWaitSpecialSpell(uint32 diff) override;
	void UpdateTalentType();
	void ProcessSeduceSpell(Unit* pTarget) override;
	bool ProcessNormalSpell() override;
	void ProcessMeleeSpell(Unit* pTarget) override;
	void ProcessRangeSpell(Unit* pTarget) override;
	void ProcessFlee() override;

	void UpdateWarriorPose();

	void ProcessWeaponRangeSpell(Unit* pTarget);
	void ProcessRageRangeSpell(Unit* pTarget);
	void ProcessDefanceRangeSpell(Unit* pTarget);
	void ProcessWeaponMeleeSpell(Unit* pTarget);
	void ProcessRageMeleeSpell(Unit* pTarget);
	void ProcessDefanceMeleeSpell(Unit* pTarget);
	bool ProcessFullAttack(Unit* pTarget);
	bool ProcessBackStorm();
	void OnCastCharge(Unit* pTarget);

	void UpEnergy() override;

public:
	bool IsTankBotAI() override;

private:
	uint32 m_BotTalentType;
	int32 m_ChargeWaitTick;
};

class GroupPaladinAI : public BotGroupAI, public BotPaladinSpells
{
public:
	GroupPaladinAI(Player* player) :
		BotGroupAI(player),
		m_BotTalentType(0)
	{}
	~GroupPaladinAI() {}

	void ResetBotAI() override;
	uint32 GetSeducePriority() override;
	void OnLevelUp(uint32 talentType) override;
	bool ProcessPullSpell(Unit* pTarget) override;

protected:
	uint32 GetManaPowerPer();
	void UpdateTalentType();
	void ProcessSeduceSpell(Unit* pTarget) override;
	bool ProcessNormalSpell() override;
	void ProcessPrepareHealthSpell(Unit* pTarget) override;
	void ProcessHealthSpell(Unit* pTarget) override;
	void ProcessMeleeSpell(Unit* pTarget) override;
	void ProcessRangeSpell(Unit* pTarget) override;
	bool ProcessFullDispel() override;
	bool NeedFlee() override;
	void ProcessFlee() override;

	bool ProcessStamp();
	bool ProcessDispel();
	bool ProcessAura();
	bool ProcessTryFriendImmune();
	bool ProcessTryFullHealth();

	bool TargetNeedInvincible(Unit* player);
	bool TargetNeedFree(Unit* player);
	bool IsHealerBotAI() override;
	bool IsAttacker() override;
	bool NeedUseGuardWish(Player* player);
	bool NeedUseKingWish(Player* player);
	bool NeedUseWitWish(Player* player);
	bool NeedUseStrWish(Player* player);
	bool ExistWish(Unit* player);
	void UpEnergy() override;

	uint32 GetReviveSpell() override;

public:
	bool IsMeleeBotAI() override;
	bool IsTankBotAI() override;

private:
	uint32 m_BotTalentType;
};

class GroupDeathknightAI : public BotGroupAI, public BotDeathknightSpells
{
public:
	GroupDeathknightAI(Player* player) :
		BotGroupAI(player),
		m_BotTalentType(0)
	{}
	~GroupDeathknightAI() {}

	void ResetBotAI() override;
	uint32 GetSeducePriority() override;
	void OnLevelUp(uint32 talentType) override;
	bool TryBlockCastingByTarget(Unit* pTarget) override;
	bool ProcessPullSpell(Unit* pTarget) override;

protected:
	uint32 GetRunePowerPer();
	void UpdateTalentType();
	void ProcessSeduceSpell(Unit* pTarget) override;
	bool ProcessNormalSpell() override;
	void ProcessMeleeSpell(Unit* pTarget) override;
	void ProcessRangeSpell(Unit* pTarget) override;
	void ProcessFlee() override;

	void ProcessBloodMeleeSpell(Unit* pTarget);
	void ProcessFrostMeleeSpell(Unit* pTarget);
	void ProcessEvilMeleeSpell(Unit* pTarget);

	bool ProcessBlcokCast();
	bool ProcessMgcShield();
	bool ProcessInfected(Unit* pTarget);
	bool ProcessDKPull(Unit* pTarget);
	void PetAction(Unit* pTarget);
	void UpEnergy() override;

public:
	bool IsTankBotAI() override;

private:
	uint32 m_BotTalentType;
};

class GroupRogueAI : public BotGroupAI, public BotRogueSpells
{
public:
	GroupRogueAI(Player* player) :
		BotGroupAI(player),
		m_BotTalentType(0),
		m_IsUpedPoison(0)
	{}
	~GroupRogueAI() {}

	void ResetBotAI() override;
	uint32 GetSeducePriority() override;
	void OnLevelUp(uint32 talentType) override;
	bool TryBlockCastingByTarget(Unit* pTarget) override;

protected:
	uint32 GetEnergyPowerPer();
	uint32 GetPoisonEntryByWeaponType(EquipmentSlots equipSlot);
	void UpdateTalentType();
	bool ProcessUpPoison();
	void ProcessSeduceSpell(Unit* pTarget) override;
	bool ProcessNormalSpell() override;
	void ProcessMeleeSpell(Unit* pTarget) override;
	void ProcessRangeSpell(Unit* pTarget) override;
	void ProcessFlee() override;
	bool ProcessSneakSpell(Unit* pTarget);
	bool ProcessMeleeBlind(Unit* pTarget);

	bool CanConsumeCombo(Unit* pTarget);
	bool CastCloakByNeed();
	bool CanBlind(Unit* pTarget);
	bool CanStartSpell();
	void OnCastSneak();
	void OnCastFlash(Unit* pTarget);
	void UpEnergy() override;

private:
	uint32 m_BotTalentType;
	uint8 m_IsUpedPoison;
};

class GroupDruidAI : public BotGroupAI, public BotDruidSpells
{
public:
	GroupDruidAI(Player* player) :
		BotGroupAI(player),
		m_BotTalentType(0)
	{}
	~GroupDruidAI() {}

	void ResetBotAI() override;
	uint32 GetSeducePriority() override;
	void OnLevelUp(uint32 talentType) override;

protected:
	uint32 GetManaPowerPer();
	uint32 GetEnergyPowerPer();
	uint32 GetRagePowerPer();
	void UpdateTalentType();
	bool NeedFlee() override;
	void ProcessFlee() override;
	void ProcessSeduceSpell(Unit* pTarget) override;
	bool ProcessNormalSpell() override;
	void ProcessPrepareHealthSpell(Unit* pTarget) override;
	void ProcessHealthSpell(Unit* pTarget) override;
	void ProcessMeleeSpell(Unit* pTarget) override;
	void ProcessRangeSpell(Unit* pTarget) override;
	bool ProcessFullDispel() override;
	bool ProcessDispel();
	bool ProcessCruel();

	bool ProcessSneak();
	void ProcessBearCombat(Unit* pTarget);
	void ProcessCatCombat(Unit* pTarget);
	void ProcessBalanceCombat(Unit* pTarget);
	void ProcessCombatRevive();
	bool ProcessActive();

	bool CanMeleeHealthMe();
	bool CanConsumeCombo(Unit* pTarget);
	bool TargetHasMechanic(Unit* pTarget);
	bool HasEnergyStore();
	void UpEnergy() override;
	void SwitchStatus(uint32 status);

	void OnCastSneak();
	void OnCastCharge(Unit* pTarget);

public:
	uint32 GetReviveSpell() override;
	bool IsMeleeBotAI() override;
	bool IsRangeBotAI() override;
	bool IsHealerBotAI() override;
	bool IsAttacker() override;

private:
	uint32 m_BotTalentType;
};

class GroupHunterAI : public BotGroupAI, public BotHunterSpells
{
public:
	GroupHunterAI(Player* player) :
		BotGroupAI(player),
		m_BotTalentType(0),
		m_IsReviveManaModel(false)
	{}
	~GroupHunterAI() {}

	void ResetBotAI() override;
	uint32 GetSeducePriority() override;
	void OnLevelUp(uint32 talentType) override;
	bool TryBlockCastingByTarget(Unit* pTarget) override;
    bool CheckManaModel();
    bool IsMeleeBotAI() override;
    bool IsRangeBotAI() override;
    bool IsHealerBotAI() override;
    bool IsAttacker() override;
protected:
	uint32 GetManaPowerPer();
	void UpdateTalentType();
	bool NeedFlee() override;
	void ProcessSeduceSpell(Unit* pTarget) override;
	void ProcessFlee() override;
	bool ProcessNormalSpell() override;
	void ProcessMeleeSpell(Unit* pTarget) override;
	void ProcessRangeSpell(Unit* pTarget) override;

    bool ProcessAura(bool isFlee);

	bool CastRangeSpell(Unit* pTarget);
	bool CastMeleeSpell(Unit* pTarget);
	void PetAction(Pet* pPet, Unit* pTarget);
	bool HasRootMechanic();
	bool TargetIsSuppress(Unit* pTarget);
	void UpEnergy() override;

private:
	uint32 m_BotTalentType;
	bool m_IsReviveManaModel;
};

class GroupShamanAI : public BotGroupAI, public BotShamanSpells
{
public:
	GroupShamanAI(Player* player) :
		BotGroupAI(player),
		m_BotTalentType(0),
		m_CurrentPattern(ShamanTotemPattern::ShamanTP_None),
		m_NonFearTotemTick(0),
		m_SummonFireTotemTick(0),
		m_IsUpedWeapon(0)
	{}
	~GroupShamanAI() {}

	void ResetBotAI() override;
	uint32 GetSeducePriority() override;
	void OnLevelUp(uint32 talentType) override;
	bool TryBlockCastingByTarget(Unit* pTarget) override;

protected:
	uint32 GetManaPowerPer();
	void UpdateTalentType();
	bool ProcessUpWeapon();
	bool NeedFlee() override;
	void ProcessSeduceSpell(Unit* pTarget) override;
	void ProcessFlee() override;
	bool ProcessNormalSpell() override;
	void ProcessPrepareHealthSpell(Unit* pTarget) override;
	void ProcessHealthSpell(Unit* pTarget) override;
	void ProcessMeleeSpell(Unit* pTarget) override;
	void ProcessRangeSpell(Unit* pTarget) override;
	bool ProcessFullDispel() override;
	bool ProcessDispel();
	bool ProcessCruel();
	bool ProcessHeroic();

	bool ProcessShield();
	bool ProcessFleeStateTotem();
	bool ProcessHealthStateTotem();
	bool ProcessMeleeStateTotem();
	bool ProcessRangeStateTotem();
	bool ExistTotemByType(PlayerTotemType totemType, float range);
	bool TryRecycleTotem(ShamanTotemPattern pattern);
	void UpEnergy() override;

public:
	uint32 GetReviveSpell() override;
	bool IsMeleeBotAI() override;
	bool IsRangeBotAI() override;
	bool IsHealerBotAI() override;
	bool IsAttacker() override;

private:
	uint32 m_BotTalentType;
	ShamanTotemPattern m_CurrentPattern;
	uint32 m_NonFearTotemTick;
	uint32 m_SummonFireTotemTick;
	uint8 m_IsUpedWeapon;
};

class GroupMageAI : public BotGroupAI, public BotMageSpells
{
public:
	GroupMageAI(Player* player) :
		BotGroupAI(player),
		m_BotTalentType(0),
		m_LastPolymorphTarget(ObjectGuid::Empty)
	{}
	~GroupMageAI() {}

	void ResetBotAI() override;
	uint32 GetSeducePriority() override;
	void OnLevelUp(uint32 talentType) override;
	bool TryBlockCastingByTarget(Unit* pTarget) override;

protected:
	uint32 GetManaPowerPer();
	void ClearMechanicAura() override;
	bool NeedWaitSpecialSpell(uint32 diff) override;
	void UpdateTalentType();
	bool TargetCanFreeze(Unit* pTarget);
	bool NeedFlee() override;
	void ProcessSeduceSpell(Unit* pTarget) override;
	void ProcessFlee() override;
	bool ProcessNormalSpell() override;
	void ProcessMeleeSpell(Unit* pTarget) override;
	void ProcessRangeSpell(Unit* pTarget) override;
	bool ProcessFullDispel() override;

	bool ProcessArcaneFlee();
	bool ProcessFireFlee();
	bool ProcessFrostFlee();
	void ProcessArcaneRangeSpell(Unit* pTarget);
	void ProcessFireRangeSpell(Unit* pTarget);
	void ProcessFrostRangeSpell(Unit* pTarget);
	void ProcessArcaneMeleeSpell(Unit* pTarget);
	void ProcessFireMeleeSpell(Unit* pTarget);
	void ProcessFrostMeleeSpell(Unit* pTarget);
	bool ProcessPolymorph(Unit* pTarget);
	bool ProcessFreezeSpell(Unit* pTarget);
	void ProcessPetAttack(Unit* pTarget);
	bool ProcessDispel();

	void OnCastPolymorph(Unit* pTarget);
	bool TargetCanPolymorph(Unit* pTarget);
	void OnCastTeleport();
	Position GetTeleportSpellPos();
	bool UseManaJewel();
	Item* FindExistManaJewel();
	uint32 GetMageTalentType();
	void UpEnergy() override;
	uint32 TryCastSummonRiteSpell() override;

private:
	ObjectGuid m_LastPolymorphTarget;
	uint32 m_BotTalentType;
	std::set<uint32> m_JewelEntrys;
};

class GroupWarlockAI : public BotGroupAI, public BotWarlockSpells
{
public:
	GroupWarlockAI(Player* player) :
		BotGroupAI(player),
		m_BotTalentType(0),
		m_IsInitedPetSpells(false),
		m_LastAOEDotTick(0)
	{}
	~GroupWarlockAI() {}

	void ResetBotAI() override;
	uint32 GetSeducePriority() override;
	void OnLevelUp(uint32 talentType) override;

protected:
	uint32 GetManaPowerPer();
	void InitializePetSpells();
	void UpdateTalentType();
	bool NeedFlee() override;
	void ProcessFlee() override;
	void ProcessSeduceSpell(Unit* pTarget) override;
	bool ProcessNormalSpell() override;
	void ProcessMeleeSpell(Unit* pTarget) override;
	void ProcessRangeSpell(Unit* pTarget) override;
	void ProcessPetSpell(Unit* pTarget, bool fleeing);

	bool ProcessMana();
	bool ProcessDot(Unit* pTarget, bool canCastTime);
	void PetAction(Pet* pPet, Unit* pTarget);
	bool TargetIsFear(Unit* pTarget);
	void InsureSoulItem();
	void UpEnergy() override;
	uint32 TryCastSummonRiteSpell() override;

private:
	uint32 m_BotTalentType;
	bool m_IsInitedPetSpells;
	uint32 m_LastAOEDotTick;
    uint32 m_LastAddTick;
};

class GroupPriestAI : public BotGroupAI, public BotPriestSpells
{
public:
	GroupPriestAI(Player* player) :
		BotGroupAI(player),
		m_BotTalentType(0),
		m_ReadyCurrentPrayer(0)
	{}
	~GroupPriestAI() {}

	void ResetBotAI() override;
	uint32 GetSeducePriority() override;
	void OnLevelUp(uint32 talentType) override;

protected:
	uint32 GetManaPowerPer();
	bool CastBuffPrayer();
	void UpdateTalentType();
	bool NeedFlee() override;
	void ProcessSeduceSpell(Unit* pTarget) override;
	void ProcessFlee() override;
	bool ProcessNormalSpell() override;
	void ProcessPrepareHealthSpell(Unit* pTarget) override;
	void ProcessHealthSpell(Unit* pTarget) override;
	void ProcessMeleeSpell(Unit* pTarget) override;
	void ProcessRangeSpell(Unit* pTarget) override;
	bool ProcessFullDispel() override;

	void ProcessNormalRangeSpell(Unit* pTarget);
	void ProcessShadowRangeSpell(Unit* pTarget);

	bool ProcessDispel();
	bool ProcessCruel();
	bool ProcessManaRevive();
	void UpEnergy() override;

public:
	uint32 GetReviveSpell() override;
	bool IsHealerBotAI() override;
	bool IsAttacker() override;

private:
	uint32 m_BotTalentType;
	uint32 m_ReadyCurrentPrayer;
};

class GroupDemonHunterAI : public BotGroupAI, public BotDemonHunterSpells
{
public:
    GroupDemonHunterAI(Player* player) :
        BotGroupAI(player),
        m_BotTalentType(0)
    {}
    ~GroupDemonHunterAI() {}

    void ResetBotAI() override;
    uint32 GetSeducePriority() override;
    void OnLevelUp(uint32 talentType) override;
    bool TryBlockCastingByTarget(Unit* pTarget) override;
    bool ProcessPullSpell(Unit* pTarget) override;
    uint32 GetFuryPowerPer();
    uint32 GetPainPowerPer();
    void UpdateTalentType();
    void ProcessSeduceSpell(Unit* pTarget) override;
    bool ProcessNormalSpell() override;
    void ProcessMeleeSpell(Unit* pTarget) override;
    void ProcessHealthSpell(Unit* pTarget) override;
    void ProcessVengeanceMeleeSpell(Unit * pTarget);
    void ProcessHavocMeleeSpell(Unit * pTarget);
    void ProcessRangeSpell(Unit* pTarget) override;
    void ProcessFlee() override;

    bool ProcessBlcokCast();
    bool ProcessDHPull(Unit * pTarget);

public:
    bool IsTankBotAI() override;

private:
    uint32 m_BotTalentType;
};

class GroupMonkAI : public BotGroupAI, public BotMonkSpells
{
public:
    GroupMonkAI(Player* player) :
        BotGroupAI(player),
        m_BotTalentType(0)
    {}
    ~GroupMonkAI() {}

    void ResetBotAI() override;
    uint32 GetSeducePriority() override;
    void OnLevelUp(uint32 talentType) override;

protected:
    uint32 GetManaPowerPer();
    uint32 GetEnergyPowerPer();
    uint32 GetRagePowerPer();
    void UpdateTalentType();
    bool NeedFlee() override;
    void ProcessFlee() override;
    void ProcessSeduceSpell(Unit* pTarget) override;
    bool ProcessNormalSpell() override;
    void ProcessPrepareHealthSpell(Unit* pTarget) override;
    void ProcessHealthSpell(Unit* pTarget) override;
    void ProcessMeleeSpell(Unit* pTarget) override;
    void ProcessRangeSpell(Unit* pTarget) override;
    bool ProcessFullDispel() override;
    bool ProcessDispel();
    bool ProcessCruel();

    void ProcessBrewMasterCombat(Unit* pTarget);
    void ProcessBattleDancerCombat(Unit* pTarget);
    void ProcessMistWeaverCombat(Unit* pTarget);

    bool CanMeleeHealthMe();
    bool TargetHasMechanic(Unit* pTarget);
    bool HasEnergyStore();
    void UpEnergy() override;

    void OnCastCharge(Unit* pTarget);

public:
    uint32 GetReviveSpell() override;
    bool IsMeleeBotAI() override;
    bool IsRangeBotAI() override;
    bool IsHealerBotAI() override;
    bool IsAttacker() override;

private:
    uint32 m_BotTalentType;
};

#endif // !_BOT_GROUP_CLASS_AI_H_
