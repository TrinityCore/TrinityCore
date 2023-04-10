
#ifndef _BOT_DUEL_CLASS_AI_H_
#define _BOT_DUEL_CLASS_AI_H_

#include "ScriptSystem.h"
#include "BotDuelAI.h"
#include "Totem.h"

class DuelWarriorAI : public BotDuelAI, public BotWarriorSpells
{
public:
    DuelWarriorAI(Player* player) :
        BotDuelAI(player),
        m_BotTalentType(0),
        m_ChargeWaitTick(0)
    {}
    ~DuelWarriorAI() {}

    void ResetBotAI() override;

protected:
    uint32 GetRagePowerPer();
    void EachTick() override;
    void ClearMechanicAura() override;
    bool NeedWaitSpecialSpell(uint32 diff) override;
    void UpdateTalentType();
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
    bool ProcessSurviveSpell();
    void OnCastCharge(Unit* pTarget);

private:
    uint32 m_BotTalentType;
    int32 m_ChargeWaitTick;
};

class DuelPaladinAI : public BotDuelAI, public BotPaladinSpells
{
public:
    DuelPaladinAI(Player* player) :
        BotDuelAI(player),
        m_BotTalentType(0)
    {}
    ~DuelPaladinAI() {}

    void ResetBotAI() override;

protected:
    uint32 GetManaPowerPer();
    void UpdateTalentType();
    void EachTick() override;
    void ProcessHealthSpell(Unit* pTarget) override;
    void ProcessMeleeSpell(Unit* pTarget) override;
    void ProcessRangeSpell(Unit* pTarget) override;
    void ProcessFlee() override;

    bool ProcessStamp();
    bool ProcessDispel();
    bool ProcessAura();
    bool ProcessControl(Unit* pTarget);
    bool ProcessFreeAura();
    bool ProcessTryFullHealth();

    bool TargetNeedInvincible(Unit* player);
    bool TargetNeedFree(Unit* player);
    bool IsHealerBotAI() override;
    bool IsAttacker() override;
    bool TargetIsCtrl(Unit* pTarget);

private:
    uint32 m_BotTalentType;
};

class DuelDeathknightAI : public BotDuelAI, public BotDeathknightSpells
{
public:
    DuelDeathknightAI(Player* player) :
        BotDuelAI(player),
        m_BotTalentType(0)
    {}
    ~DuelDeathknightAI() {}

    void ResetBotAI() override;

protected:
    uint32 GetRunePowerPer();
    void UpdateTalentType();
    void EachTick() override;
    void ProcessMeleeSpell(Unit* pTarget) override;
    void ProcessRangeSpell(Unit* pTarget) override;
    void ProcessFlee() override;

    void UpdatePose();

    void ProcessBloodMeleeSpell(Unit* pTarget);
    void ProcessFrostMeleeSpell(Unit* pTarget);
    void ProcessEvilMeleeSpell(Unit* pTarget);

    bool ProcessBlcokCast();
    bool ProcessMgcShield();
    bool ProcessDKPull(Unit* pTarget);
    void PetAction(Unit* pTarget);
    void UpEnergy();

private:
    uint32 m_BotTalentType;
};

class DuelRogueAI : public BotDuelAI, public BotRogueSpells
{
public:
    DuelRogueAI(Player* player) :
        BotDuelAI(player),
        m_BotTalentType(0)
    {}
    ~DuelRogueAI() {}

    void ResetBotAI() override;

protected:
    uint32 GetEnergyPowerPer();
    void UpdateTalentType();
    void EachTick() override;
    void ProcessMeleeSpell(Unit* pTarget) override;
    void ProcessRangeSpell(Unit* pTarget) override;
    void ProcessFlee() override;
    bool ProcessSneakSpell(Unit* pTarget);
    bool ProcessMeleeDance(Unit* pTarget);

    bool CanConsumeCombo(Unit* pTarget);
    bool CastCloakByNeed();
    bool CanBlind(Unit* pTarget);
    bool CanStartSpell();
    void OnCastSneak();
    void OnCastFlash(Unit* pTarget);
    void UpEnergy();

private:
    uint32 m_BotTalentType;
};

class DuelDruidAI : public BotDuelAI, public BotDruidSpells
{
public:
    DuelDruidAI(Player* player) :
        BotDuelAI(player),
        m_BotTalentType(0)
    {}
    ~DuelDruidAI() {}

    void ResetBotAI() override;

protected:
    uint32 GetManaPowerPer();
    uint32 GetEnergyPowerPer();
    uint32 GetRagePowerPer();
    void UpdateTalentType();
    void EachTick() override;
    bool NeedFlee() override;
    void ProcessFlee() override;
    void ProcessHealthSpell(Unit* pTarget) override;
    void ProcessMeleeSpell(Unit* pTarget) override;
    void ProcessRangeSpell(Unit* pTarget) override;

    bool ProcessSneak();
    void ProcessBearCombat(Unit* pTarget);
    void ProcessCatCombat(Unit* pTarget);
    void ProcessBalanceCombat(Unit* pTarget);
    bool ProcessActive();

    bool CanMeleeHealthMe();
    bool CanConsumeCombo(Unit* pTarget);
    bool TargetHasMechanic(Unit* pTarget);
    bool IsMeleeBotAI() override;
    bool IsRangeBotAI() override;
    bool IsHealerBotAI() override;
    bool IsAttacker() override;
    bool HasEnergyStore();
    void UpEnergy();
    void UpPower();
    void UpMana();
    void SwitchStatus(uint32 status);
    bool CanAttackSpell();
    bool ProcessControl(Unit* pTarget);
    void OnCastSneak();
    void OnCastCharge(Unit* pTarget);

private:
    uint32 m_BotTalentType;
};

class DuelHunterAI : public BotDuelAI, public BotHunterSpells
{
public:
    DuelHunterAI(Player* player) :
        BotDuelAI(player),
        m_BotTalentType(0)
    {}
    ~DuelHunterAI() {}

    void ResetBotAI() override;

protected:
    uint32 GetManaPowerPer();
    void UpdateTalentType();
    bool NeedFlee() override;
    void ProcessFlee() override;
    void ProcessMeleeSpell(Unit* pTarget) override;
    void ProcessRangeSpell(Unit* pTarget) override;

    void PetAction(Pet* pPet, Unit* pTarget);
    bool HasRootMechanic();
    bool TargetIsSuppress(Unit* pTarget);

private:
    uint32 m_BotTalentType;
};

class DuelShamanAI : public BotDuelAI, public BotShamanSpells
{
public:
    DuelShamanAI(Player* player) :
        BotDuelAI(player),
        m_BotTalentType(0),
        m_CurrentPattern(ShamanTotemPattern::ShamanTP_None),
        m_SummonFireTotemTick(0)
    {}
    ~DuelShamanAI() {}

    void ResetBotAI() override;

protected:
    uint32 GetManaPowerPer();
    void UpdateTalentType();
    void EachTick() override;
    bool NeedFlee() override;
    void ProcessFlee() override;
    void ProcessHealthSpell(Unit* pTarget) override;
    void ProcessMeleeSpell(Unit* pTarget) override;
    void ProcessRangeSpell(Unit* pTarget) override;
    bool ProcessDispel();

    bool ProcessShield();
    bool ProcessTotem();
    bool ExistTotemByType(PlayerTotemType totemType, float range);
    bool IsMeleeBotAI() override;
    bool IsRangeBotAI() override;
    bool IsHealerBotAI() override;
    bool IsAttacker() override;
    bool TargetIsSuppress(Unit* pTarget);
    bool TryRecycleTotem(ShamanTotemPattern pattern);

private:
    uint32 m_BotTalentType;
    ShamanTotemPattern m_CurrentPattern;
    uint32 m_SummonFireTotemTick;
};

class DuelMageAI : public BotDuelAI, public BotMageSpells
{
public:
    DuelMageAI(Player* player) :
        BotDuelAI(player),
        m_BotTalentType(0),
        m_LastPolymorphTarget(ObjectGuid::Empty),
        m_StealthTick(0)
    {}
    ~DuelMageAI() {}

    void ResetBotAI() override;

protected:
    uint32 GetManaPowerPer();
    void ClearMechanicAura() override;
    bool NeedWaitSpecialSpell(uint32 diff) override;
    void UpdateTalentType();
    bool TargetCanFreeze(Unit* pTarget);
    void EachTick() override;
    bool NeedFlee() override;
    void ProcessFlee() override;
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
    bool ProcessFreezeSpell(Unit* pTarget);

    bool IsStealthing();
    void OnCastTeleport();
    Position GetTeleportSpellPos();
    bool UseManaJewel();
    Item* FindExistManaJewel();

private:
    ObjectGuid m_LastPolymorphTarget;
    uint32 m_StealthTick;
    uint32 m_BotTalentType;
    std::set<uint32> m_JewelEntrys;
};

class DuelWarlockAI : public BotDuelAI, public BotWarlockSpells
{
public:
    DuelWarlockAI(Player* player) :
        BotDuelAI(player),
        m_BotTalentType(0),
        m_IsInitedPetSpells(false),
        m_IsSummonPeted(false),
        m_LastAOEDotTick(0),
        m_GatePos(),
        m_LastCharmTarget(ObjectGuid::Empty),
        m_LastCharmTick(0)
    {}
    ~DuelWarlockAI() {}

    void ResetBotAI() override;

protected:
    uint32 GetManaPowerPer();
    void InitializePetSpells();
    void UpdateTalentType();
    void EachTick() override;
    bool NeedFlee() override;
    void ProcessFlee() override;
    void ProcessMeleeSpell(Unit* pTarget) override;
    void ProcessRangeSpell(Unit* pTarget) override;
    void ProcessPetSpell(Unit* pTarget, bool fleeing);

    bool ProcessGate(Unit* pTarget, bool onlyBuild);
    bool ProcessMana(bool isMoveing);
    bool ProcessDot(Unit* pTarget, bool canCastTime);
    bool ProcessFear(Unit* pTarget);
    void PetAction(Pet* pPet, Unit* pTarget);
    bool TargetIsFear(Unit* pTarget);
    void OnCastTeleGate();
    void InsureSoulItem();

private:
    uint32 m_BotTalentType;
    bool m_IsInitedPetSpells;
    uint32 m_LastAOEDotTick;
    Position m_GatePos;
    bool m_IsSummonPeted;
    ObjectGuid m_LastCharmTarget;
    uint32 m_LastCharmTick;
};

class DuelPriestAI : public BotDuelAI, public BotPriestSpells
{
public:
    DuelPriestAI(Player* player) :
        BotDuelAI(player),
        m_BotTalentType(0)
    {}
    ~DuelPriestAI() {}

    void ResetBotAI() override;

protected:
    uint32 GetManaPowerPer();
    bool HaveManaStore() override;
    void UpdateTalentType();
    void EachTick() override;
    bool NeedFlee() override;
    void ProcessFlee() override;
    void ProcessHealthSpell(Unit* pTarget) override;
    void ProcessMeleeSpell(Unit* pTarget) override;
    void ProcessRangeSpell(Unit* pTarget) override;

    void ProcessNormalRangeSpell(Unit* pTarget);
    void ProcessShadowRangeSpell(Unit* pTarget);

    bool ProcessManaBurn();
    bool ProcessDispel();

    bool IsHealerBotAI() override;
    bool IsAttacker() override;

private:
    uint32 m_BotTalentType;
};

#endif // !_BOT_DUEL_CLASS_AI_H_
