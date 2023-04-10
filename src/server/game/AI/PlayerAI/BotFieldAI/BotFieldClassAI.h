
#ifndef _BOT_GROUP_CLASS_AI_H_
#define _BOT_GROUP_CLASS_AI_H_

#include "ScriptSystem.h"
#include "BotFieldAI.h"

class FieldWarriorAI : public BotFieldAI, public BotWarriorSpells
{
public:
    FieldWarriorAI(Player* player) :
        BotFieldAI(player),
        m_BotTalentType(0),
        m_ChargeWaitTick(0)
    {}
    ~FieldWarriorAI() {}

    void ResetBotAI() override;
    void OnLevelUp(uint32 talentType) override;

protected:
    uint32 GetRagePowerPer();
    void ClearMechanicAura() override;
    bool NeedWaitSpecialSpell(uint32 diff) override;
    void UpdateTalentType();
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

    void OnCastCharge(Unit* pTarget);

    void UpEnergy() override;

private:
    uint32 m_BotTalentType;
    int32 m_ChargeWaitTick;
};


class FieldPaladinAI : public BotFieldAI, public BotPaladinSpells
{
public:
    FieldPaladinAI(Player* player) :
        BotFieldAI(player),
        m_BotTalentType(0)
    {}
    ~FieldPaladinAI() {}

    void ResetBotAI() override;
    void OnLevelUp(uint32 talentType) override;

protected:
    uint32 GetManaPowerPer();
    void UpdateTalentType();
    bool ProcessNormalSpell() override;
    void ProcessHealthSpell(Unit* pTarget) override;
    void ProcessMeleeSpell(Unit* pTarget) override;
    void ProcessRangeSpell(Unit* pTarget) override;
    bool NeedFlee() override;
    void ProcessFlee() override;

    bool ProcessDispel();
    bool ProcessAura();

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

private:
    uint32 m_BotTalentType;
};

class FieldDeathknightAI : public BotFieldAI, public BotDeathknightSpells
{
public:
    FieldDeathknightAI(Player* player) :
        BotFieldAI(player),
        m_BotTalentType(0)
    {}
    ~FieldDeathknightAI() {}

    void ResetBotAI() override;
    void OnLevelUp(uint32 talentType) override;

protected:
    uint32 GetRunePowerPer();
    void UpdateTalentType();
    bool ProcessNormalSpell() override;
    void ProcessMeleeSpell(Unit* pTarget) override;
    void ProcessRangeSpell(Unit* pTarget) override;
    void ProcessFlee() override;

    void UpdatePose();

    void ProcessBloodMeleeSpell(Unit* pTarget);
    void ProcessFrostMeleeSpell(Unit* pTarget);
    void ProcessEvilMeleeSpell(Unit* pTarget);

    bool ProcessBlcokCast();
    bool ProcessMgcShield();
    bool ProcessInfected(Unit* pTarget);
    bool ProcessDKPull(Unit* pTarget);
    void PetAction(Unit* pTarget);
    void UpEnergy() override;

private:
    uint32 m_BotTalentType;
};

class FieldRogueAI : public BotFieldAI, public BotRogueSpells
{
public:
    FieldRogueAI(Player* player) :
        BotFieldAI(player),
        m_BotTalentType(0),
        m_IsUpedPoison(0)
    {}
    ~FieldRogueAI() {}

    void ResetBotAI() override;
    void OnLevelUp(uint32 talentType) override;

protected:
    uint32 GetEnergyPowerPer();
    uint32 GetPoisonEntryByWeaponType(EquipmentSlots equipSlot);
    void UpdateTalentType();
    bool ProcessUpPoison();
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

class FieldDruidAI : public BotFieldAI, public BotDruidSpells
{
public:
    FieldDruidAI(Player* player) :
        BotFieldAI(player),
        m_BotTalentType(0)
    {}
    ~FieldDruidAI() {}

    void ResetBotAI() override;
    void OnLevelUp(uint32 talentType) override;

protected:
    uint32 GetManaPowerPer();
    uint32 GetEnergyPowerPer();
    uint32 GetRagePowerPer();
    void UpdateTalentType();
    bool NeedFlee() override;
    void ProcessFlee() override;
    bool ProcessNormalSpell() override;
    void ProcessHealthSpell(Unit* pTarget) override;
    void ProcessMeleeSpell(Unit* pTarget) override;
    void ProcessRangeSpell(Unit* pTarget) override;

    bool ProcessSneak();
    void ProcessBearCombat(Unit* pTarget);
    void ProcessCatCombat(Unit* pTarget);
    void ProcessBalanceCombat(Unit* pTarget);
    void ProcessCombatRevive();

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

class FieldHunterAI : public BotFieldAI, public BotHunterSpells
{
public:
    FieldHunterAI(Player* player) :
        BotFieldAI(player),
        m_BotTalentType(0),
        m_IsSupplemented(false)
    {}
    ~FieldHunterAI() {}

    void ResetBotAI() override;
    void OnLevelUp(uint32 talentType) override;

protected:
    uint32 GetManaPowerPer();
    void UpdateTalentType();
    bool NeedFlee() override;
    void ProcessFlee() override;
    bool ProcessNormalSpell() override;
    void ProcessMeleeSpell(Unit* pTarget) override;
    void ProcessRangeSpell(Unit* pTarget) override;

    void PetAction(Pet* pPet, Unit* pTarget);
    bool HasRootMechanic();
    bool TargetIsSuppress(Unit* pTarget);

private:
    uint32 m_BotTalentType;
    bool m_IsSupplemented;
};

class FieldShamanAI : public BotFieldAI, public BotShamanSpells
{
public:
    FieldShamanAI(Player* player) :
        BotFieldAI(player),
        m_BotTalentType(0),
        m_CurrentPattern(ShamanTotemPattern::ShamanTP_None)
    {}
    ~FieldShamanAI() {}

    void ResetBotAI() override;
    void OnLevelUp(uint32 talentType) override;

protected:
    uint32 GetManaPowerPer();
    void UpdateTalentType();
    bool NeedFlee() override;
    void ProcessFlee() override;
    bool ProcessNormalSpell() override;
    void ProcessHealthSpell(Unit* pTarget) override;
    void ProcessMeleeSpell(Unit* pTarget) override;
    void ProcessRangeSpell(Unit* pTarget) override;
    bool ProcessDispel();
    bool ProcessHeroic();

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
};

class FieldMageAI : public BotFieldAI, public BotMageSpells
{
public:
    FieldMageAI(Player* player) :
        BotFieldAI(player),
        m_BotTalentType(0)
    {}
    ~FieldMageAI() {}

    void ResetBotAI() override;
    void OnLevelUp(uint32 talentType) override;

protected:
    uint32 GetManaPowerPer();
    void ClearMechanicAura() override;
    bool NeedWaitSpecialSpell(uint32 diff) override;
    void UpdateTalentType();
    bool TargetCanFreeze(Unit* pTarget);
    bool NeedFlee() override;
    void ProcessFlee() override;
    bool ProcessNormalSpell() override;
    void ProcessMeleeSpell(Unit* pTarget) override;
    void ProcessRangeSpell(Unit* pTarget) override;

    bool ProcessArcaneFlee();
    bool ProcessFireFlee();
    bool ProcessFrostFlee();
    void ProcessArcaneRangeSpell(Unit* pTarget);
    void ProcessFireRangeSpell(Unit* pTarget);
    void ProcessFrostRangeSpell(Unit* pTarget);
    void ProcessArcaneMeleeSpell(Unit* pTarget);
    void ProcessFireMeleeSpell(Unit* pTarget);
    void ProcessFrostMeleeSpell(Unit* pTarget);

    bool ProcessDispel();
    void OnCastTeleport();

    bool UseManaJewel();
    Item* FindExistManaJewel();
    uint32 GetMageTalentType();

private:
    uint32 m_BotTalentType;
    std::set<uint32> m_JewelEntrys;
};

class FieldWarlockAI : public BotFieldAI, public BotWarlockSpells
{
public:
    FieldWarlockAI(Player* player) :
        BotFieldAI(player),
        m_BotTalentType(0),
        m_IsInitedPetSpells(false),
        m_LastAOEDotTick(0)
    {}
    ~FieldWarlockAI() {}

    void ResetBotAI() override;
    void OnLevelUp(uint32 talentType) override;

protected:
    uint32 GetManaPowerPer();
    void InitializePetSpells();
    void UpdateTalentType();
    bool NeedFlee() override;
    void ProcessFlee() override;
    bool ProcessNormalSpell() override;
    void ProcessMeleeSpell(Unit* pTarget) override;
    void ProcessRangeSpell(Unit* pTarget) override;
    void ProcessPetSpell(Unit* pTarget);

    bool ProcessMana();
    bool ProcessDot(Unit* pTarget, bool canCastTime);
    bool ProcessFear(Unit* pTarget);
    void PetAction(Pet* pPet, Unit* pTarget);
    bool TargetIsFear(Unit* pTarget);

private:
    uint32 m_BotTalentType;
    bool m_IsInitedPetSpells;
    uint32 m_LastAOEDotTick;
};

class FieldPriestAI : public BotFieldAI, public BotPriestSpells
{
public:
    FieldPriestAI(Player* player) :
        BotFieldAI(player),
        m_BotTalentType(0),
        m_ReadyCurrentPrayer(0)
    {}
    ~FieldPriestAI() {}

    void ResetBotAI() override;
    void OnLevelUp(uint32 talentType) override;

protected:
    uint32 GetManaPowerPer();
    bool CastBuffPrayer();
    void UpdateTalentType();
    bool NeedFlee() override;
    void ProcessFlee() override;
    bool ProcessNormalSpell() override;
    void ProcessHealthSpell(Unit* pTarget) override;
    void ProcessMeleeSpell(Unit* pTarget) override;
    void ProcessRangeSpell(Unit* pTarget) override;

    void ProcessNormalRangeSpell(Unit* pTarget);
    void ProcessShadowRangeSpell(Unit* pTarget);

    bool ProcessDispel();
    void UpEnergy() override;

public:
    uint32 GetReviveSpell() override;
    bool IsHealerBotAI() override;
    bool IsAttacker() override;

private:
    uint32 m_BotTalentType;
    uint32 m_ReadyCurrentPrayer;
};

#endif // !_BOT_GROUP_CLASS_AI_H_
