
#include "BotDuelClassAI.h"
#include "BotBGAIMovement.h"
#include "Item.h"
#include "Bag.h"
#include "Spell.h"
#include "MovementPackets.h"

void DuelRogueAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();// PlayerBotSetting::FindPlayerTalentType(me);
}

void DuelRogueAI::ResetBotAI()
{
    BotDuelAI::ResetBotAI();
    UpdateTalentType();
    InitializeSpells(me);
}

uint32 DuelRogueAI::GetEnergyPowerPer()
{
    float per = (float)me->GetPower(POWER_ENERGY) / (float)me->GetMaxPower(POWER_ENERGY);
    return (uint32)(per * 100);
}

void DuelRogueAI::EachTick()
{
    BotDuelAI::EachTick();
    if (!me->IsInCombat())
        return;
    UpEnergy();
}

bool DuelRogueAI::ProcessSneakSpell(Unit* pTarget)
{
    if (!pTarget || !me->HasAura(RogueGuard_Sneak))
        return false;
    if (m_BotTalentType == 2 && RogueSneak_Premeditate && TryCastSpell(RogueSneak_Premeditate, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return true;
    if (!HasAuraMechanic(pTarget, Mechanics::MECHANIC_STUN))
    {
        if (TryCastSpell(RogueSneak_Surprise, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    else
    {
        if (TryCastSpell(RogueSneak_Ambush, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (TryCastSpell(RogueSneak_Surprise, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    return false;
}

bool DuelRogueAI::ProcessMeleeDance(Unit* pTarget)
{
    if (m_BotTalentType != 2)
        return false;
    if (!CanBlind(pTarget))
        return false;
    //if (BotUtility::ControllSpellDiminishing && !TargetIsNotDiminishingByType(pTarget, DiminishingGroup::DIMINISHING_CONTROLLED_STUN))
    //	return false;
    if (me->HasAura(RogueFlag_Dance))
    {
        if (TryCastSpell(RogueSneak_Surprise, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    else if (RogueAssist_ShadowDance)
    {
        if (TryCastSpell(RogueAssist_ShadowDance, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (RogueAssist_ReadyCD && TryCastSpell(RogueAssist_ReadyCD, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    return false;
}

void DuelRogueAI::ProcessMeleeSpell(Unit* pTarget)
{
    if (me->GetSelectedUnit() && !me->IsInCombat() && !me->HasAura(RogueGuard_Sneak) &&
        TryCastSpell(RogueGuard_Sneak, me) == SpellCastResult::SPELL_CAST_OK)
    {
        OnCastSneak();
        return;
    }
    if (!CanStartSpell())
        return;
    if (ProcessSneakSpell(pTarget))
        return;
    if (TargetIsMelee(pTarget->ToPlayer()) && me->GetHealthPct() < 20 && TryCastSpell(RogueGuard_Dodge, me) == SpellCastResult::SPELL_CAST_OK)
        return;

    if (pTarget->HasUnitState(UNIT_STATE_CASTING))
    {
        if (RogueAssist_BlockCast && TryCastSpell(RogueAssist_BlockCast, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (RogueAssist_Paralyze && TryCastSpell(RogueAssist_Paralyze, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (RogueAssist_Blind && TryCastSpell(RogueAssist_Blind, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (RogueAttack_Stun && TryCastSpell(RogueAttack_Stun, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (RogueAssist_Disarm && TargetIsMelee(pTarget->ToPlayer()) && !HasAuraMechanic(pTarget, Mechanics::MECHANIC_STUN))
    {
        if (!pTarget->HasAura(RogueAssist_Disarm) && TryCastSpell(RogueAssist_Disarm, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (CastCloakByNeed())
        return;
    if (m_BotTalentType == 1 && RogueAssist_FastEnergy)
    {
        if (GetEnergyPowerPer() < 20 && TryCastSpell(RogueAssist_FastEnergy, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (RogueGuard_Disappear && me->IsInCombat())// && !HasAuraMechanic(me, Mechanics::MECHANIC_BLEED))
    {
        if (!pTarget->HasAura(RogueAssist_Disarm) && !HasAuraMechanic(pTarget, Mechanics::MECHANIC_STUN) &&
            !HasAuraMechanic(pTarget, Mechanics::MECHANIC_FEAR))
        {
            if (TryCastSpell(RogueGuard_Disappear, me) == SpellCastResult::SPELL_CAST_OK)
            {
                OnCastSneak();
                return;
            }
        }
    }
    if (m_BotTalentType == 0 && RogueAssist_NextCrit)
        TryCastSpell(RogueAssist_NextCrit, pTarget);
    if (CanConsumeCombo(pTarget))
    {
        if (RogueAttack_Stun && !pTarget->HasAura(RogueAssist_Disarm) && !HasAuraMechanic(pTarget, Mechanics::MECHANIC_STUN))
        {
            //if (!BotUtility::ControllSpellDiminishing || TargetIsNotDiminishingByType(pTarget, DiminishingGroup::DIMINISHING_CONTROLLED_STUN))
            {
                if (TryCastSpell(RogueAttack_Stun, pTarget) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
        }
        if (ProcessMeleeDance(pTarget))
            return;
        if (RogueAttack_PoisonDmg/* && pTarget->HasAuraState(AuraStateType::AURA_STATE_DEADLY_POISON, NULL, me)*/)
        {
            if (TryCastSpell(RogueAttack_PoisonDmg, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        if (pTarget->HasAura(RogueAttack_Separate))
        {
            if (TryCastSpell(RogueAttack_Damage, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        else
        {
            if (TryCastSpell(RogueAttack_Separate, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
    }
    else
    {
        if (RogueAttack_PoisonAtt && !HasAuraMechanic(pTarget, Mechanics::MECHANIC_SNARE))
        {
            if (TryCastSpell(RogueAttack_PoisonAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        if (ProcessMeleeDance(pTarget))
            return;
        if (m_BotTalentType == 0 && RogueAttack_Injure && TryCastSpell(RogueAttack_Injure, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (m_BotTalentType == 2 && RogueAttack_Ghost && TryCastSpell(RogueAttack_Ghost, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (m_BotTalentType == 2 && RogueAttack_Blood)
        {
            if (TryCastSpell(RogueAttack_Blood, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        else if (m_BotTalentType != 0 && RogueAttack_BackAtt && TryCastSpell(RogueAttack_BackAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (TryCastSpell(RogueAttack_EvilAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
}

void DuelRogueAI::ProcessRangeSpell(Unit* pTarget)
{
    if (me->GetSelectedUnit() != pTarget)
        return;
    if (me->GetSelectedUnit() && !me->IsInCombat() && TryCastSpell(RogueGuard_Sneak, me) == SpellCastResult::SPELL_CAST_OK)
    {
        OnCastSneak();
        return;
    }
    if (ProcessSneakSpell(pTarget))
        return;
    //if (ProcessMeleeDance(pTarget))
    //	return;
    if (RogueAssist_ShadowFlash && m_BotTalentType == 2)
    {
        if (me->HasAura(RogueGuard_Sneak) || (!HasAuraMechanic(me, Mechanics::MECHANIC_ROOT) && !HasAuraMechanic(me, Mechanics::MECHANIC_STUN)))
        {
            if (TryCastSpell(RogueAssist_ShadowFlash, pTarget) == SpellCastResult::SPELL_CAST_OK)
            {
                OnCastFlash(pTarget);
                return;
            }
        }
    }
    uint8 combo = me->GetComboPoints();
    if (RogueRange_Throw && pTarget->HasUnitState(UNIT_STATE_CASTING) && combo > 0)
    {
        if (TryCastSpell(RogueRange_Throw, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else if (RogueRange_Throw && combo > 3)
    {
        if (TryCastSpell(RogueRange_Throw, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (CastCloakByNeed())
        return;
}

void DuelRogueAI::ProcessFlee()
{
    FleeMovement();
}

bool DuelRogueAI::CastCloakByNeed()
{
    if (!RogueGuard_ShadowCloak)
        return false;
    if (HasAuraMechanic(me, Mechanics::MECHANIC_ROOT))
    {
        if (TryCastSpell(RogueGuard_ShadowCloak, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (HasAuraMechanic(me, Mechanics::MECHANIC_SNARE))
    {
        if (TryCastSpell(RogueGuard_ShadowCloak, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }

    return false;
}

bool DuelRogueAI::CanBlind(Unit* pTarget)
{
    if (/*HasAuraMechanic(pTarget, Mechanics::MECHANIC_KNOCKOUT) ||*/
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_BLEED) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_BANISH) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_FEAR) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_ROOT) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_STUN) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_SLEEP) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_SAPPED))
        return false;
    return true;
}

bool DuelRogueAI::CanConsumeCombo(Unit* pTarget)
{
    uint8 combo = me->GetComboPoints();
    if (combo == 0)
        return false;
    float targetLife = pTarget->GetHealthPct();
    if (targetLife < 10)
        return true;
    else if (targetLife < 60 && combo > 2)
        return true;
    else if (combo >= 4)
        return true;
    return false;
}

bool DuelRogueAI::CanStartSpell()
{
    return GetEnergyPowerPer() >= 60;
}

void DuelRogueAI::OnCastSneak()
{
    if (Player* player = me->GetSelectedPlayer())
        player->SetSelection(ObjectGuid::Empty);
}

void DuelRogueAI::OnCastFlash(Unit* pTarget)
{
    me->GetMotionMaster()->Clear();
    Position pos = pTarget->GetPosition();
    me->TeleportTo(me->GetMapId(), pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), me->GetOrientation());
    WorldSession* pSession = me->GetSession();
    WorldPacket opcode2(CMSG_MOVE_TELEPORT_ACK);
    WorldPackets::Movement::MoveTeleportAck pakcet(std::move(opcode2));
    pakcet.MoverGUID = me->GetGUID();
    pSession->HandleMoveTeleportAck(pakcet);
    m_Movement->SyncPosition(pos, true);
}

void DuelRogueAI::UpEnergy()
{
    uint32 max = me->GetMaxPower(Powers::POWER_ENERGY);
    uint32 power = me->GetPower(Powers::POWER_ENERGY);
    me->SetPower(Powers::POWER_ENERGY, (max / 25) + power);
}
