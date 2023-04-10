
#include "BotFieldClassAI.h"
#include "BotBGAIMovement.h"

void FieldMageAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();// PlayerBotSetting::FindPlayerTalentType(me);
}

void FieldMageAI::ResetBotAI()
{
    BotFieldAI::ResetBotAI();
    UpdateTalentType();
    InitializeSpells(me);

    m_JewelEntrys.clear();
    m_JewelEntrys.insert(5514);
    m_JewelEntrys.insert(5513);
    m_JewelEntrys.insert(8007);
    m_JewelEntrys.insert(8008);
    m_JewelEntrys.insert(22044);
    m_JewelEntrys.insert(33312);

    m_WishStore.ClearWishs();
    m_WishStore.RegisterWish(MageIDLE_AOEArcaneMagic);
    m_WishStore.RegisterWish(MageIDLE_ArcaneMagic);
}

void FieldMageAI::OnLevelUp(uint32 talentType)
{
    if (talentType < 3)
        m_BotTalentType = talentType;
    InitializeSpells(me);

    m_WishStore.ClearWishs();
    m_WishStore.RegisterWish(MageIDLE_AOEArcaneMagic);
    m_WishStore.RegisterWish(MageIDLE_ArcaneMagic);
}

uint32 FieldMageAI::GetManaPowerPer()
{
    float per = (float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA);
    return (uint32)(per * 100);
}

void FieldMageAI::ClearMechanicAura()
{
    bool root = HasAuraMechanic(me, Mechanics::MECHANIC_ROOT);
    bool stun = HasAuraMechanic(me, Mechanics::MECHANIC_STUN);
    if (root || stun)
    {
        //if (CanCastSpell(MageAssist_Teleport, me) == SpellCastResult::SPELL_CAST_OK)
        //{
        //	OnCastTeleport();
        //	return;
        //}
        if (stun && me->GetHealthPct() < 20 && TryCastSpell(MageGuard_FrostScherm, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
}

bool FieldMageAI::NeedWaitSpecialSpell(uint32 diff)
{
    if (BotFieldAI::NeedWaitSpecialSpell(diff))
        return true;
    if (me->HasAura(MageFlag_Scherm))
        return true;
    return false;
}

bool FieldMageAI::TargetCanFreeze(Unit* pTarget)
{
    if (!pTarget)
        return false;
    if (pTarget->HasAuraState(AURA_STATE_FROZEN) || me->HasAura(MageFlag_CanFrozen))
        return true;
    if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_FREEZE) || HasAuraMechanic(pTarget, Mechanics::MECHANIC_ROOT))
        return true;
    return false;
}

bool FieldMageAI::NeedFlee()
{
    if (m_Flee.Fleeing())
        return true;
    Unit* pTarget = me->GetSelectedUnit();
    if (!pTarget || pTarget->ToCreature())
        return false;
    if (RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE).size() > 0)
        return true;
    float fleeDistance = m_Flee.CalcMaxFleeDistance(pTarget);
    if (me->GetDistance(pTarget->GetPosition()) < fleeDistance)//BOTAI_FLEE_JUDGE)
        return true;
    return false;
}

bool FieldMageAI::ProcessNormalSpell()
{
    if (me->HasAura(m_UseMountID))
        return false;
    if (MageIDLE_AOEArcaneMagic && !me->HasAura(MageIDLE_AOEArcaneMagic) && TryCastSpell(MageIDLE_AOEArcaneMagic, me, true) == SpellCastResult::SPELL_CAST_OK)
        return false;
    if (!MageIDLE_AOEArcaneMagic && MageIDLE_ArcaneMagic)
    {
        if (!me->HasAura(MageIDLE_ArcaneMagic) && TryCastSpell(MageIDLE_ArcaneMagic, me, true) == SpellCastResult::SPELL_CAST_OK)
            return false;
    }
    if (MageIDLE_MgcArmor)
    {
        if (!me->HasAura(MageIDLE_MgcArmor) && TryCastSpell(MageIDLE_MgcArmor, me) == SpellCastResult::SPELL_CAST_OK)
            return false;
    }
    else if (MageIDLE_FireArmor)
    {
        if (!me->HasAura(MageIDLE_FireArmor) && TryCastSpell(MageIDLE_FireArmor, me) == SpellCastResult::SPELL_CAST_OK)
            return false;
    }
    else if (MageIDLE_FrostArmor)
    {
        if (!me->HasAura(MageIDLE_FrostArmor) && TryCastSpell(MageIDLE_FrostArmor, me) == SpellCastResult::SPELL_CAST_OK)
            return false;
    }
    else
    {
        if (!me->HasAura(MageIDLE_IceArmor) && TryCastSpell(MageIDLE_IceArmor, me) == SpellCastResult::SPELL_CAST_OK)
            return false;
    }
    if (MageIDLE_MagicAdd && !me->HasAura(MageIDLE_MagicAdd) && TryCastSpell(MageIDLE_MagicAdd, me) == SpellCastResult::SPELL_CAST_OK)
        return false;
    uint32 manaPct = GetManaPowerPer();
    if (manaPct > 30 && !FindExistManaJewel())
    {
        m_Movement->ClearMovement();
        if (TryCastSpell(MageIDLE_ManaGem, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (MageAssist_Rouse && manaPct < 15 && TryCastSpell(MageAssist_Rouse, me) == SpellCastResult::SPELL_CAST_OK)
    {
        me->StopMoving();
        return true;
    }
    ProcessDispel();
    return TryUpMount();
}

void FieldMageAI::ProcessFlee()
{
    FleeMovement();
    if (me->HasAura(MageAssist_Stealth))
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

    float healthPct = me->GetHealthPct();
    NearUnitVec enemys = RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE);
    if (enemys.size() > 0)
    {
        for (Unit* player : enemys)
        {
            if (HasAuraMechanic(player, MECHANIC_ROOT) ||
                HasAuraMechanic(player, MECHANIC_STUN))
                continue;
            {
                if (PetTryCastSpell(MagePet_FrostNova, player) == SpellCastResult::SPELL_CAST_OK)
                    break;
                if (TryCastSpell(MageGuard_FrostNova, me) == SpellCastResult::SPELL_CAST_OK)
                    return;
                break;
            }
        }
    }
    if (healthPct <= 15 && enemys.size() > 0 && TryCastSpell(MageGuard_FrostScherm, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    //if (CanCastSpell(MageAssist_Teleport, me) == SpellCastResult::SPELL_CAST_OK)
    //{
    //	OnCastTeleport();
    //	return;
    //}
    uint32 manaPct = GetManaPowerPer();
    if (manaPct < 60 && UseManaJewel())
        return;

    switch (GetMageTalentType())
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
    if (enemys.size() > 0 && TryCastSpell(MageAssist_Stealth, me) == SpellCastResult::SPELL_CAST_OK)
    {
        me->SetSelection(ObjectGuid::Empty);
        NearUnitVec cancelTargets = RangeEnemyListByTargetIsMe(BOTAI_RANGESPELL_DISTANCE);
        for (Unit* target : cancelTargets)
        {
            target->SetTarget(ObjectGuid::Empty);
        }
        return;
    }
    Unit* pTarget = me->GetSelectedUnit();
    if (pTarget && TryCastSpell(MageFire_FireShock, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!me->HasAura(MageAssist_Stealth) && RangeEnemyListByHasAura(0, NEEDFLEE_CHECKRANGE).size() > 1)
    {
        if (TryCastSpell(MageAOE_ArcaneExplode, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (!me->HasAura(MageAssist_Stealth))
        ProcessDispel();
}

bool FieldMageAI::ProcessArcaneFlee()
{
    NearUnitVec enemys = RangeEnemyListByTargetIsMe(15.0f);
    float healthPct = me->GetHealthPct();
    if (healthPct <= 70 && enemys.size() > 0 && !me->HasAura(MageGuard_MagicShield) && TryCastSpell(MageGuard_MagicShield, me) == SpellCastResult::SPELL_CAST_OK)
        return true;
    if (Unit* pTarget = me->GetSelectedUnit())
    {
        if (!pTarget->HasAura(MageConfine_ArcaneSlow) && TryCastSpell(MageConfine_ArcaneSlow, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (pTarget->GetHealthPct() > 85 && !HasAuraMechanic(pTarget, Mechanics::MECHANIC_POLYMORPH) && TryCastSpell(MageAssist_Grace, me) == SpellCastResult::SPELL_CAST_OK)
        {
            if (TryCastSpell(MageConfine_ToSheep, pTarget) == SpellCastResult::SPELL_CAST_OK)
            {
                me->SetSelection(ObjectGuid::Empty);
                return true;
            }
        }
    }
    if (enemys.size() > 1)
    {
        Unit* player = enemys[urand(0, enemys.size() - 1)];
        if (player->GetHealthPct() > 80 && !HasAuraMechanic(player, Mechanics::MECHANIC_POLYMORPH) && TryCastSpell(MageAssist_Grace, me) == SpellCastResult::SPELL_CAST_OK)
        {
            if (TryCastSpell(MageConfine_ToSheep, player) == SpellCastResult::SPELL_CAST_OK)
            {
                me->SetSelection(ObjectGuid::Empty);
                return true;
            }
        }
    }

    return false;
}

bool FieldMageAI::ProcessFireFlee()
{
    NearUnitVec enemys = RangeEnemyListByTargetIsMe(8.0f);
    float healthPct = me->GetHealthPct();
    if (healthPct <= 70 && enemys.size() > 0 && !me->HasAura(MageGuard_MagicShield) && TryCastSpell(MageGuard_MagicShield, me) == SpellCastResult::SPELL_CAST_OK)
        return true;
    if (Unit* pTarget = me->GetSelectedUnit())
    {
        if (enemys.size() > 2 && TryCastSpell(MageGuard_FireNova, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (me->GetDistance(pTarget) < 8.0f && TryCastSpell(MageGuard_FireBreath, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }

    return false;
}

bool FieldMageAI::ProcessFrostFlee()
{
    NearUnitVec enemys = RangeEnemyListByTargetIsMe(8.0f);
    float healthPct = me->GetHealthPct();
    if (MageGuard_FrostShield)
    {
        if (healthPct <= 70 && enemys.size() > 0 && !me->HasAura(MageGuard_FrostShield) && TryCastSpell(MageGuard_FrostShield, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (MageGuard_MagicShield)
    {
        if (healthPct <= 70 && enemys.size() > 0 && !me->HasAura(MageGuard_MagicShield) && TryCastSpell(MageGuard_MagicShield, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (healthPct <= 50 && enemys.size() > 0 && TryCastSpell(MageAssist_FastColddown, me) == SpellCastResult::SPELL_CAST_OK)
        return true;
    if (Unit* pTarget = me->GetSelectedUnit())
    {
        if (TargetCanFreeze(pTarget) && TryCastSpell(MageConfine_Freeze, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }

    return false;
}

void FieldMageAI::ProcessMeleeSpell(Unit* pTarget)
{
    switch (GetMageTalentType())
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

void FieldMageAI::ProcessRangeSpell(Unit* pTarget)
{
    if (!me->IsInCombat())
    {
        //if (!me->HasAura(MageIDLE_ArcaneMagic) && TryCastSpell(MageIDLE_ArcaneMagic, me) == SpellCastResult::SPELL_CAST_OK)
        //	return;
        if (MageIDLE_MgcArmor)
        {
            if (!me->HasAura(MageIDLE_MgcArmor) && TryCastSpell(MageIDLE_MgcArmor, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        else if (MageIDLE_FireArmor)
        {
            if (!me->HasAura(MageIDLE_FireArmor) && TryCastSpell(MageIDLE_FireArmor, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        else if (MageIDLE_FrostArmor)
        {
            if (!me->HasAura(MageIDLE_FrostArmor) && TryCastSpell(MageIDLE_FrostArmor, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        else
        {
            if (!me->HasAura(MageIDLE_IceArmor) && TryCastSpell(MageIDLE_IceArmor, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
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
    if (TargetCanFreeze(pTarget) && TryCastSpell(MageFrost_IceLance, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    Unit* castEnemy = RandomRangeEnemyByCasting(BOTAI_RANGESPELL_DISTANCE);
    if (castEnemy && TryCastSpell(MageConfine_BreakCast, castEnemy) == SpellCastResult::SPELL_CAST_OK)
        return;
    //uint32 stealRate = urand(0, 99);
    //if (stealRate < 15 && TryCastSpell(MageConfine_AuraSteal, pTarget) == SpellCastResult::SPELL_CAST_OK)
    //	return;

    ProcessDispel();
    switch (GetMageTalentType())
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

void FieldMageAI::ProcessArcaneRangeSpell(Unit* pTarget)
{
    if (RangeEnemyListByTargetRange(pTarget, NEEDFLEE_CHECKRANGE).size() > 5 && TryCastSpell(MageAOE_Snowstorm, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    //if (!pTarget->HasAura(MageConfine_ArcaneSlow) && TryCastSpell(MageConfine_ArcaneSlow, pTarget) == SpellCastResult::SPELL_CAST_OK)
    //	return;
    if (TryCastSpell(MageAssist_ArcanePower, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    //if (RangeEnemyListByTargetIsMe(20).size() <= 0 && TryCastSpell(MageArcane_ArcaneShock, pTarget) == SpellCastResult::SPELL_CAST_OK)
    //	return;
    if (TryCastSpell(MageArcane_Barrage, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(MageArcane_Bullet, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void FieldMageAI::ProcessFireRangeSpell(Unit* pTarget)
{
    if (me->HasAura(MageFlag_FireStun) && TryCastSpell(MageFire_FireShock, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (RangeEnemyListByTargetRange(pTarget, NEEDFLEE_CHECKRANGE).size() > 4 && TryCastSpell(MageAOE_FireStorm, pTarget) == SpellCastResult::SPELL_CAST_OK)
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
        TryCastSpell(MageFire_BigFireBall, pTarget);// , true);
        return;
    }
    //if (CanCastSpell(MageFire_FireShock, pTarget) == SpellCastResult::SPELL_CAST_OK)
    //	return;
    uint32 rate = urand(0, 99);
    if (rate <= 50 || !MageFire_Firing)
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

void FieldMageAI::ProcessFrostRangeSpell(Unit* pTarget)
{
    if (RangeEnemyListByTargetRange(pTarget, 10.0f).size() > 5 && TryCastSpell(MageAOE_Snowstorm, pTarget) == SpellCastResult::SPELL_CAST_OK)
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

void FieldMageAI::ProcessArcaneMeleeSpell(Unit* /*pTarget*/)
{

}

void FieldMageAI::ProcessFireMeleeSpell(Unit* /*pTarget*/)
{

}

void FieldMageAI::ProcessFrostMeleeSpell(Unit* /*pTarget*/)
{

}

bool FieldMageAI::ProcessDispel()
{
    if (!MageAssist_DecCurse)
        return false;
    NearUnitVec friends = SearchFriend(BOTAI_RANGESPELL_DISTANCE);
    if (friends.empty())
        return false;
    //std::random_shuffle(friends.begin(), friends.end());
    for (Unit* player : friends)
    {
        //if (HasAuraMechanic(player, Mechanics::MECHANIC_ROOT))
        {
            if (TryCastSpell(MageAssist_DecCurse, player) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
    }
    return false;
}

void FieldMageAI::OnCastTeleport()
{
    //me->StopMoving();
    //Position& telePos = me->GetFirstCollisionPosition(21, 0);
    //float z = telePos.GetPositionZ();
    //me->GetMap()->GetHeight(me->GetPhaseMask(), telePos.GetPositionX(), telePos.GetPositionY(), z);
    //telePos.m_positionZ = z;
    //telePos.SetOrientation(me->GetOrientation());
    //me->UpdatePosition(telePos, true);
}

bool FieldMageAI::UseManaJewel()
{
    std::lock_guard<std::mutex> lock(m_ItemLock);
    Item* pItem = FindExistManaJewel();
    if (!pItem)
        return false;
    SpellCastTargets targets;
    targets.SetTargetMask(0);
    /*if (me->CastItemUseSpell(pItem, targets, ObjectGuid::Empty, 0) == SpellCastResult::SPELL_CAST_OK)
    {
        return true;
    }*/
    return false;
}

Item* FieldMageAI::FindExistManaJewel()
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

uint32 FieldMageAI::GetMageTalentType()
{
    if (me->getLevel() < 10)
        return 1;
    return m_BotTalentType;
}
