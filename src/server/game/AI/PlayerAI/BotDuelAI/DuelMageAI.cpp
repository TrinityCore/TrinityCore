
#include "botDuelClassAI.h"
#include "BotBGAIMovement.h"
#include "Group.h"

void DuelMageAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();// PlayerBotSetting::FindPlayerTalentType(me);
}

void DuelMageAI::ResetBotAI()
{
    BotDuelAI::ResetBotAI();
    UpdateTalentType();
    InitializeSpells(me);

    m_JewelEntrys.clear();
    m_JewelEntrys.insert(5514);
    m_JewelEntrys.insert(5513);
    m_JewelEntrys.insert(8007);
    m_JewelEntrys.insert(8008);
    m_JewelEntrys.insert(22044);
    m_JewelEntrys.insert(33312);
}

uint32 DuelMageAI::GetManaPowerPer()
{
    float per = (float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA);
    return (uint32)(per * 100);
}

void DuelMageAI::ClearMechanicAura()
{
    if (IsStealthing())
        return;
    bool root = HasAuraMechanic(me, Mechanics::MECHANIC_ROOT) || HasAuraMechanic(me, Mechanics::MECHANIC_SNARE);
    bool stun = HasAuraMechanic(me, Mechanics::MECHANIC_STUN);
    if (root || stun)
    {
        if (stun && me->GetHealthPct() < 20 && TryCastSpell(MageGuard_FrostScherm, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (MageAssist_Teleport && TryCastSpell(MageAssist_Teleport, me) == SpellCastResult::SPELL_CAST_OK)
        {
            OnCastTeleport();
            return;
        }
    }
}

bool DuelMageAI::NeedWaitSpecialSpell(uint32 diff)
{
    if (BotDuelAI::NeedWaitSpecialSpell(diff))
        return true;
    if (MageFlag_Scherm)
    {
        if (me->HasAura(MageFlag_Scherm))
        {
            return true;
        }
    }
    return false;
}

bool DuelMageAI::TargetCanFreeze(Unit* pTarget)
{
    if (!pTarget)
        return false;
    if (pTarget->HasAuraState(AURA_STATE_FROZEN) || me->HasAura(MageFlag_CanFrozen))
        return true;
    if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_FREEZE) || HasAuraMechanic(pTarget, Mechanics::MECHANIC_ROOT))
        return true;
    return false;
}

void DuelMageAI::EachTick()
{
    BotDuelAI::EachTick();
    if (!me->IsInCombat() || !me->InArena())
        return;
    uint32 max = me->GetMaxPower(Powers::POWER_MANA);
    uint32 power = me->GetPower(Powers::POWER_MANA);
    me->SetPower(Powers::POWER_MANA, (max / 450) + power);
}

bool DuelMageAI::NeedFlee()
{
    if (m_Flee.Fleeing())
        return true;
    Unit* pTarget = GetDuelEnemy();
    if (!pTarget)
        return false;
    if (m_NeedFlee.TargetHasFleeAura(pTarget))
    {
        return true;
    }
    if (!IsFleeTargetByRangeBot(pTarget))
        return false;
    float fleeDistance = m_Flee.CalcMaxFleeDistance(pTarget);
    if (me->GetDistance(pTarget->GetPosition()) < fleeDistance)//BOTAI_FLEE_JUDGE)
        return true;
    return false;
}

void DuelMageAI::ProcessFlee()
{
    FleeMovement();
    if (IsStealthing())
        return;

    if (MageIDLE_FrostArmor)
    {
        if (!me->HasAura(MageIDLE_FrostArmor) && TryCastSpell(MageIDLE_FrostArmor, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else if (MageIDLE_IceArmor)
    {
        if (!me->HasAura(MageIDLE_IceArmor) && TryCastSpell(MageIDLE_IceArmor, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    Unit* pTarget = GetDuelEnemy();
    if (!pTarget)
        return;
    float healthPct = me->GetHealthPct();
    if (!HasAuraMechanic(pTarget, MECHANIC_ROOT) && !HasAuraMechanic(pTarget, MECHANIC_STUN) && me->GetDistance(pTarget->GetPosition()) < 8)
    {
        if (PetTryCastSpell(MagePet_FrostNova, pTarget) != SpellCastResult::SPELL_CAST_OK)
        {
            if (TryCastSpell(MageGuard_FrostNova, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
    }
    if (healthPct <= 20 && TryCastSpell(MageGuard_FrostScherm, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    uint32 manaPct = GetManaPowerPer();
    if (manaPct < 60 && UseManaJewel())
        return;

    if (ProcessFreezeSpell(me->GetSelectedUnit()))
        return;
    switch (m_BotTalentType)
    {
    case 0:
        if (ProcessArcaneFlee())
            return;
        break;
    case 1:
        if (ProcessFireFlee())
            return;
        break;
    case 2:
        if (ProcessFrostFlee())
            return;
        break;
    }
    if (TryCastSpell(MageAssist_Stealth, me) == SpellCastResult::SPELL_CAST_OK)
    {
        m_StealthTick = getMSTime();
        if (Player* player = pTarget->ToPlayer())
            player->SetSelection(ObjectGuid::Empty);
        return;
    }
    if (TryCastSpell(MageFire_FireShock, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(MageConfine_AuraSteal, pTarget, true) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!me->HasAura(MageAssist_Stealth))
    {
        if (TryCastSpell(MageAOE_ArcaneExplode, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
}

bool DuelMageAI::ProcessArcaneFlee()
{
    float healthPct = me->GetHealthPct();
    if (healthPct <= 50 && GetManaPowerPer() > 50 && !me->HasAura(MageGuard_MagicShield) && TryCastSpell(MageGuard_MagicShield, me) == SpellCastResult::SPELL_CAST_OK)
        return true;
    if (Unit* pTarget = me->GetSelectedUnit())
    {
        if (!pTarget->HasAura(MageConfine_ArcaneSlow) && TryCastSpell(MageConfine_ArcaneSlow, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (TryCastSpell(MageArcane_Barrage, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (TryCastSpell(MageAssist_Grace, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (me->HasAura(MageAssist_Grace))
        {
            if (TryCastSpell(MageFire_FireArrow, pTarget) == SpellCastResult::SPELL_CAST_OK)
            {
                return true;
            }
        }
    }

    return false;
}

bool DuelMageAI::ProcessFireFlee()
{
    float healthPct = me->GetHealthPct();
    if (healthPct <= 50 && GetManaPowerPer() > 50 && !me->HasAura(MageGuard_MagicShield) && TryCastSpell(MageGuard_MagicShield, me) == SpellCastResult::SPELL_CAST_OK)
        return true;
    if (Unit* pTarget = me->GetSelectedUnit())
    {
        if (me->GetDistance(pTarget) < 8.0f && TryCastSpell(MageGuard_FireBreath, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (me->GetDistance(pTarget) < 8.0f && TryCastSpell(MageGuard_FireNova, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (!pTarget->HasAura(MageFire_FireBomb) && TryCastSpell(MageFire_FireBomb, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }

    return false;
}

bool DuelMageAI::ProcessFrostFlee()
{
    float healthPct = me->GetHealthPct();
    if (MageGuard_FrostShield)
    {
        if (!me->HasAura(MageGuard_FrostShield) && TryCastSpell(MageGuard_FrostShield, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    else if (MageGuard_MagicShield)
    {
        if (healthPct <= 50 && GetManaPowerPer() > 50 && !me->HasAura(MageGuard_MagicShield) && TryCastSpell(MageGuard_MagicShield, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (healthPct <= 20 && TryCastSpell(MageAssist_FastColddown, me) == SpellCastResult::SPELL_CAST_OK)
        return true;
    if (Unit* pTarget = me->GetSelectedUnit())
    {
        if (ProcessFreezeSpell(pTarget))
            return true;
    }

    return false;
}

void DuelMageAI::ProcessMeleeSpell(Unit* pTarget)
{
    if (IsStealthing())
        return;
    if (PetTryCastSpell(MagePet_FrostNova, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!HasAuraMechanic(pTarget, MECHANIC_ROOT) && me->GetDistance(pTarget->GetPosition()) < 8 && TryCastSpell(MageGuard_FrostNova, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ProcessFreezeSpell(pTarget))
        return;
    switch (m_BotTalentType)
    {
    case 0:
        ProcessArcaneMeleeSpell(pTarget);
        break;
    case 1:
        ProcessFireMeleeSpell(pTarget);
        break;
    case 2:
        ProcessFrostMeleeSpell(pTarget);
        break;
    }
}

void DuelMageAI::ProcessRangeSpell(Unit* pTarget)
{
    if (IsStealthing())
        return;
    if (!me->IsInCombat())
    {
        if (!me->HasAura(MageIDLE_ArcaneMagic) && TryCastSpell(MageIDLE_ArcaneMagic, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (!me->HasAura(MageIDLE_FireArmor) && TryCastSpell(MageIDLE_FireArmor, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else
    {
        if (TryCastSpell(MageAssist_Mirror, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (me->HasAura(MageFlag_FireStun) && TryCastSpell(MageFire_FireShock, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    uint32 manaPct = GetManaPowerPer();
    if (manaPct < 8 && TryCastSpell(MageAssist_Rouse, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (manaPct < 60 && UseManaJewel())
        return;
    if (ProcessFreezeSpell(pTarget))
        return;
    if (pTarget->HasUnitState(UNIT_STATE_CASTING) && TryCastSpell(MageConfine_BreakCast, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (me->GetHealthPct() <= 20 && TryCastSpell(MageGuard_FrostScherm, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ProcessFreezeSpell(pTarget))
        return;
    uint32 stealRate = urand(0, 99);
    if (stealRate < 5 && TryCastSpell(MageConfine_AuraSteal, pTarget, true) == SpellCastResult::SPELL_CAST_OK)
        return;

    switch (m_BotTalentType)
    {
    case 0:
        ProcessArcaneRangeSpell(pTarget);
        break;
    case 1:
        ProcessFireRangeSpell(pTarget);
        break;
    case 2:
        ProcessFrostRangeSpell(pTarget);
        break;
    }
}

void DuelMageAI::ProcessArcaneRangeSpell(Unit* pTarget)
{
    if (!pTarget->HasAura(MageConfine_ArcaneSlow) && TryCastSpell(MageConfine_ArcaneSlow, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(MageAssist_ArcanePower, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(MageArcane_Barrage, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(MageArcane_Bullet, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void DuelMageAI::ProcessFireRangeSpell(Unit* pTarget)
{
    if (me->HasAura(MageFlag_FireStun) && TryCastSpell(MageFire_FireShock, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!pTarget->HasAura(MageFire_FireBomb) && TryCastSpell(MageFire_FireBomb, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!me->HasAura(MageAssist_FireCritAura) && TryCastSpell(MageAssist_FireCritAura, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (me->HasAura(MageFlag_FastFStorm))
    {
        TryCastSpell(MageAOE_FireStorm, pTarget, true);
        return;
    }
    if (MageFire_BigFireBall && me->HasAura(MageFlag_FastBFBall))
    {
        TryCastSpell(MageFire_BigFireBall, pTarget, true);
        return;
    }
    //if (CanCastSpell(MageFire_FireShock, pTarget) == SpellCastResult::SPELL_CAST_OK)
    //	return;
    uint32 rate = urand(0, 99);
    if (rate <= 30)
    {
        if (TryCastSpell(MageFire_FireArrow, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else
    {
        if (TryCastSpell(MageFire_Firing, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
}

void DuelMageAI::ProcessFrostRangeSpell(Unit* pTarget)
{
    if (!me->HasAura(MageGuard_FrostShield) && TryCastSpell(MageGuard_FrostShield, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(MageAssist_CastSpeed, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (me->HasAura(MageFlag_FastFFArrow))
    {
        if (MageFrost_FFArrow)
        {
            TryCastSpell(MageFrost_FFArrow, pTarget, true);
            return;
        }
        TryCastSpell(MageFire_FireArrow, pTarget, true);
        return;
    }
    if (TryCastSpell(MageAssist_FrostPet, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(MageFrost_IceArrow, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void DuelMageAI::ProcessArcaneMeleeSpell(Unit* /*pTarget*/)
{

}

void DuelMageAI::ProcessFireMeleeSpell(Unit* /*pTarget*/)
{

}

void DuelMageAI::ProcessFrostMeleeSpell(Unit* /*pTarget*/)
{

}

bool DuelMageAI::ProcessFreezeSpell(Unit* pTarget)
{
    if (!pTarget)
        return false;
    if (TargetCanFreeze(pTarget) && !HasAuraMechanic(pTarget, Mechanics::MECHANIC_POLYMORPH))
    {
        if (m_BotTalentType == 2 && MageConfine_Freeze && me->getLevel() == 80 && !pTarget->HasAura(MageConfine_Freeze) && TryCastSpell(MageConfine_Freeze, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (TryCastSpell(MageFrost_IceLance, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    return false;
}

void DuelMageAI::OnCastTeleport()
{
    Position telePos = GetTeleportSpellPos();
    me->GetMotionMaster()->Clear();
    m_Movement->ClearMovement();
    SetTeleport(telePos);
    //me->UpdatePosition(telePos, true);
    //m_Movement->SyncPosition(telePos, true);
}

bool DuelMageAI::IsStealthing()
{
    if (!MageAssist_Stealth || !me->HasAura(MageAssist_Stealth))
        return false;
    if (m_StealthTick + 5000 < getMSTime())
    {
        m_StealthTick = 0;
        return false;
    }
    return true;
}

Position DuelMageAI::GetTeleportSpellPos()
{
    float onceAngle = float(M_PI) * 2.0f / 8.0f;
    Position targetPos = me->GetPosition();
    float maxDist = 0.0f;
    std::list<Position> allPosition;
    for (float angle = 0.0f; angle < (float(M_PI) * 2.0f); angle += onceAngle)
    {
        Position pos = me->GetFirstCollisionPosition(BOTAI_RANGESPELL_DISTANCE, angle);
        //pos.m_positionZ = me->GetMap()->GetHeight(me->GetPhaseMask(), pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ());
        allPosition.push_back(pos);
    }
    if (allPosition.empty())
        return targetPos;
    for (Position pos : allPosition)
    {
        float dist = me->GetDistance(pos);
        if (dist > maxDist)
        {
            maxDist = dist;
            targetPos = pos;
        }
    }
    return targetPos;
}

bool DuelMageAI::UseManaJewel()
{
    Item* pItem = FindExistManaJewel();
    if (!pItem)
        return false;
    SpellCastTargets targets;
    targets.SetTargetMask(0);
   /* if (me->CastItemUseSpell(pItem, targets, 0, ObjectGuid::Empty) == SpellCastResult::SPELL_CAST_OK)
    {
        return true;
    }*/
    return false;
}

Item* DuelMageAI::FindExistManaJewel()
{
    for (uint8 slot = InventoryPackSlots::INVENTORY_SLOT_ITEM_START; slot < InventoryPackSlots::INVENTORY_SLOT_ITEM_END; slot++)
    {
        Item* pItem = me->GetItemByPos(255, slot);
        if (!pItem)
            continue;
        const ItemTemplate* pTemplate = pItem->GetTemplate();
        if (!pTemplate)
            continue;
        if (m_JewelEntrys.find(pTemplate->GetId()) != m_JewelEntrys.end())
            return pItem;
    }
    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (Bag* pBag = me->GetBagByPos(i))
        {
            for (uint32 j = 0; j < pBag->GetBagSize(); j++)
            {
                Item* pItem = pBag->GetItemByPos(uint8(j));
                if (!pItem)
                    continue;
                const ItemTemplate* pTemplate = pItem->GetTemplate();
                if (!pTemplate)
                    continue;
                if (m_JewelEntrys.find(pTemplate->GetId()) != m_JewelEntrys.end())
                    return pItem;
            }
        }
    }
    return NULL;
}
