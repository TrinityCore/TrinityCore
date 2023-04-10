
#include "BotDuelClassAI.h"
#include "PlayerBotSession.h"
#include "Pet.h"
#include "BotBGAIMovement.h"

void DuelWarlockAI::InitializePetSpells()
{
    if (m_IsInitedPetSpells)
        return;
    Pet* pPet = me->GetPet();
    if (!pPet || !pPet->IsAlive())
        return;

    WarlockPetDemon_Charge = FindPetMaxRankSpellByExist(47996);
    WarlockPetDemon_Melee = FindPetMaxRankSpellByExist(47994);
    WarlockPetDog_MagicBuf = FindPetMaxRankSpellByExist(57567);
    WarlockPetDog_EatMgc = FindPetMaxRankSpellByExist(48011);
    WarlockPetDog_Bite = FindPetMaxRankSpellByExist(54053);
    WarlockPetDog_Silence = FindPetMaxRankSpellByExist(19647);
    WarlockPetSuccubus_Lash = FindPetMaxRankSpellByExist(47992);
    WarlockPetSuccubus_Sneak = FindPetMaxRankSpellByExist(7870);
    WarlockPetSuccubus_Charm = FindPetMaxRankSpellByExist(6358);
    WarlockPetGhost_Shield = FindPetMaxRankSpellByExist(47983);
    WarlockPetGhost_Sneak = FindPetMaxRankSpellByExist(4511);
    WarlockPetGhost_Stamp = FindPetMaxRankSpellByExist(47982);
    WarlockPetGhost_FireArrow = FindPetMaxRankSpellByExist(47964);

    SettingPetAutoCastSpell(WarlockPetDemon_Charge, true);
    SettingPetAutoCastSpell(WarlockPetDemon_Melee, true);
    SettingPetAutoCastSpell(WarlockPetDog_MagicBuf, false);
    SettingPetAutoCastSpell(WarlockPetDog_EatMgc, false);//true
    SettingPetAutoCastSpell(WarlockPetDog_Bite, true);
    SettingPetAutoCastSpell(WarlockPetDog_Silence, false);
    SettingPetAutoCastSpell(WarlockPetSuccubus_Lash, true);
    SettingPetAutoCastSpell(WarlockPetSuccubus_Sneak, true);
    SettingPetAutoCastSpell(WarlockPetSuccubus_Charm, false);
    SettingPetAutoCastSpell(WarlockPetGhost_Shield, true);
    SettingPetAutoCastSpell(WarlockPetGhost_Sneak, true);
    SettingPetAutoCastSpell(WarlockPetGhost_Stamp, true);
    SettingPetAutoCastSpell(WarlockPetGhost_FireArrow, true);

    m_IsInitedPetSpells = true;
}

void DuelWarlockAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();// PlayerBotSetting::FindPlayerTalentType(me);
}

void DuelWarlockAI::ResetBotAI()
{
    BotDuelAI::ResetBotAI();
    m_IsInitedPetSpells = false;
    m_IsSummonPeted = false;
    UpdateTalentType();
    InitializeSpells(me);
    m_LastCharmTarget = ObjectGuid::Empty;
    m_LastCharmTick = 0;
}

uint32 DuelWarlockAI::GetManaPowerPer()
{
    float per = (float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA);
    return (uint32)(per * 100);
}

void DuelWarlockAI::EachTick()
{
    BotDuelAI::EachTick();
    InsureSoulItem();
    if (m_LastCharmTick > 0)
    {
        if (m_LastCharmTick + 6000 <= getMSTime())
        {
            m_LastCharmTarget = ObjectGuid::Empty;
            m_LastCharmTick = 0;
        }
    }
    if (!me->IsInCombat() || !me->InArena())
        return;
    uint32 max = me->GetMaxPower(Powers::POWER_MANA);
    uint32 power = me->GetPower(Powers::POWER_MANA);
    me->SetPower(Powers::POWER_MANA, (max / 450) + power);
}

bool DuelWarlockAI::NeedFlee()
{
    if (m_Flee.Fleeing())
        return true;
    Unit* pTarget = me->GetSelectedUnit();
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

void DuelWarlockAI::ProcessFlee()
{
    if (!me->HasUnitState(UNIT_STATE_CASTING))
        FleeMovement();
    if (ProcessMana(true))
        return;

    Unit* pDuelEnemy = GetDuelEnemy();
    if (!pDuelEnemy)
        return;
    if (ProcessGate(pDuelEnemy, false))
        return;
    Pet* pPet = me->GetPet();
    if (pPet && !pPet->HasUnitState(UNIT_STATE_CASTING))
    {
        PetAction(pPet, pDuelEnemy);
    }

    if (!TargetIsFear(pDuelEnemy))
    {
        if (WarlockAssist_FastFear && TryCastSpell(WarlockAssist_FastFear, pDuelEnemy) == SpellCastResult::SPELL_CAST_OK)
        {
            return;
        }
        if (WarlockAssist_BaseFear)
        {
            if (!BotUtility::ControllSpellDiminishing /*|| TargetIsNotDiminishingByType2(pDuelEnemy, DiminishingGroup::DIMINISHING_FEAR)*/)
            {
                me->StopMoving();
                if (TryCastSpell(WarlockAssist_BaseFear, pDuelEnemy) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
        }
    }
    ProcessPetSpell(pDuelEnemy, true);

    if (m_BotTalentType == 1 && WarlockAssist_DemonPower && TryCastSpell(WarlockAssist_DemonPower, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (WarlockAOE_MeleeFire && TryCastSpell(WarlockAOE_MeleeFire, pDuelEnemy) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 2 && WarlockAOE_ShadowRage)
    {
        if (TryCastSpell(WarlockAOE_ShadowRage, pDuelEnemy) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    if (m_BotTalentType == 2 && WarlockCast_ShadowShock)
    {
        if (!pDuelEnemy->HasAura(WarlockCast_ShadowShock) && TryCastSpell(WarlockCast_ShadowShock, pDuelEnemy, true) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    ProcessDot(pDuelEnemy, false);
}

void DuelWarlockAI::ProcessPetSpell(Unit* pTarget, bool /*fleeing*/)
{
    Pet* pPet = me->GetPet();
    if (!pPet || pPet->HasUnitState(UNIT_STATE_CASTING))
        return;

    if (pTarget->HasUnitState(UNIT_STATE_CASTING) && WarlockPetDog_Silence)
    {
        if (PetTryCastSpell(WarlockPetDog_Silence, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    if (WarlockPetSuccubus_Charm)
    {
        if (TargetIsFear(pTarget))
            return;
        //if (TargetIsNotDiminishingByType2(pTarget, DiminishingGroup::DIMINISHING_FEAR))
        //{
        //	if (PetTryCastSpell(WarlockPetSuccubus_Charm, pTarget) == SpellCastResult::SPELL_CAST_OK)
        //	{
        //		m_LastCharmTarget = pTarget->GetGUID();
        //		m_LastCharmTick = getMSTime();
        //		return;
        //	}
        //}
    }
}

bool DuelWarlockAI::ProcessGate(Unit* pTarget, bool onlyBuild)
{
    if (!pTarget || !WarlockIDLE_OpenGate || !WarlockIDLE_TeleGate || !me->InArena())
        return false;
    uint32 manaPct = GetManaPowerPer();
    if (manaPct < 15)
        return false;
    float distGate = me->GetDistance(m_GatePos);
    if (me->HasAura(WarlockFlag_OpenGate) && distGate > 8 && distGate < 30 && m_GatePos.GetPositionZ() != 0)
    {
        if (TryCastSpell(WarlockIDLE_TeleGate, me) == SpellCastResult::SPELL_CAST_OK)
        {
            OnCastTeleGate();
            return true;
        }
    }
    else if (me->GetDistance(pTarget->GetPosition()) < BOTAI_RANGESPELL_DISTANCE && distGate > 25)
    {
        m_Movement->ClearMovement();
        if (onlyBuild && TryCastSpell(WarlockIDLE_OpenGate, me, true) == SpellCastResult::SPELL_CAST_OK)
        {
            m_GatePos = me->GetPosition();
            return true;
        }
    }
    else if (!me->HasAura(WarlockFlag_OpenGate))
    {
        m_GatePos = Position();
    }
    return false;
}

bool DuelWarlockAI::ProcessMana(bool isMoveing)
{
    uint32 manaPct = GetManaPowerPer();
    if (manaPct > 25)
        return false;
    if (m_BotTalentType == 0 && WarlockAssist_ExtractMana)
    {
        if (TryCastSpell(WarlockAssist_ExtractMana, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (!isMoveing && me->InArena())
    {
        if (Unit* pTarget = me->GetSelectedUnit())
        {
            if (WarlockAssist_StealMana && pTarget->IsAlive() && TryCastSpell(WarlockAssist_StealMana, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
    }
    if (me->GetHealthPct() > 65)
    {
        if (TryCastSpell(WarlockAssist_ConvertMana, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    return false;
}

bool DuelWarlockAI::ProcessDot(Unit* pTarget, bool canCastTime)
{
    if (!pTarget)
        return false;
    if (!pTarget->HasAura(WarlockDot_LowDmg) && TryCastSpell(WarlockDot_LowDmg, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return true;
    if (canCastTime)
    {
        if (m_BotTalentType == 0)
        {
            if (!pTarget->HasAura(WarlockDot_LeechSoul) && TryCastSpell(WarlockDot_LeechSoul, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return true;
            if (!pTarget->HasAura(WarlockDot_HighDmg) && TryCastSpell(WarlockDot_HighDmg, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
        else if (!pTarget->HasAura(WarlockDot_Sacrifice) && TryCastSpell(WarlockDot_Sacrifice, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }

    if (WarlockCurse_MoveLow && m_BotTalentType == 0 && !TargetIsFear(pTarget) && TargetIsMelee(pTarget->ToPlayer()) && !pTarget->HasAura(WarlockCurse_MoveLow))
    {
        if (TryCastSpell(WarlockCurse_MoveLow, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (pTarget->HasAura(WarlockCurse_MoveLow))
        return false;
    if (pTarget->GetTarget() == me->GetGUID())//GetTargetGUID
    {
        Player* pPlayer = (Player*)pTarget->ToPlayer();
        if (TargetIsCastMagic(pPlayer))
        {
            if (!pTarget->HasAura(WarlockCurse_CastLow) && TryCastSpell(WarlockCurse_CastLow, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
        else
        {
            if (!pTarget->HasAura(WarlockCurse_MeleeLow) && TryCastSpell(WarlockCurse_MeleeLow, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
    }
    else
    {
        if (!pTarget->HasAura(WarlockCurse_MgcDmg) && TryCastSpell(WarlockCurse_MgcDmg, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }

    return false;
}

bool DuelWarlockAI::ProcessFear(Unit* pTarget)
{
    if (!pTarget || !WarlockAssist_BaseFear)
        return false;

    //if (BotUtility::ControllSpellDiminishing && !TargetIsNotDiminishingByType2(pTarget, DiminishingGroup::DIMINISHING_FEAR))
    //{
    //	return false;
    //}
    //if (m_LastCharmTarget == pTarget->GetGUID())
    //	return false;

    me->StopMoving();
    if (TryCastSpell(WarlockAssist_BaseFear, pTarget) == SpellCastResult::SPELL_CAST_OK)
    {
        return true;
    }
    return false;
}

void DuelWarlockAI::ProcessMeleeSpell(Unit* pTarget)
{
    if (ProcessGate(pTarget, false))
        return;
}

void DuelWarlockAI::ProcessRangeSpell(Unit* pTarget)
{
    PetAction(me->GetPet(), pTarget);
    if (ProcessMana(false))
        return;
    if (ProcessGate(pTarget, true))
        return;

    if (m_BotTalentType == 2 && TryCastSpell(WarlockAOE_ShadowRage, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    ProcessPetSpell(pTarget, false);
    if (ProcessFear(pTarget))
        return;
    if (ProcessDot(pTarget, true))
        return;

    if (m_BotTalentType == 0 && WarlockAssist_StealLife)
    {
        if (TryCastSpell(WarlockAssist_StealLife, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (m_BotTalentType == 2 && WarlockCast_ChaosArrow && TryCastSpell(WarlockCast_ChaosArrow, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 2 && pTarget->HasAura(WarlockDot_Sacrifice))
    {
        if (WarlockCast_FullBurn && TryCastSpell(WarlockCast_FullBurn, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (WarlockCast_FireBurn && TryCastSpell(WarlockCast_FireBurn, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    if (pTarget->GetHealthPct() < 65)
    {
        if (TryCastSpell(WarlockCast_ShadowArrow, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else
    {
        if (TryCastSpell(WarlockCast_BigFireBall, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
}

void DuelWarlockAI::PetAction(Pet* pPet, Unit* pTarget)
{
    Position pos;
    if (!pPet)
        return;
    if (pPet->GetVictim() == pTarget)
        return;
    WorldSession* pSession = me->GetSession();
    if (pTarget)
        pSession->HandlePetActionHelper(pPet, pPet->GetGUID(), 2, 7, pTarget->GetGUID(),pos);
    else
        pSession->HandlePetActionHelper(pPet, pPet->GetGUID(), 1, 7, ObjectGuid::Empty, pos);
}

bool DuelWarlockAI::TargetIsFear(Unit* pTarget)
{
    if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_CHARM))
        return true;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_DISORIENTED))
        return true;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_FEAR))
        return true;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_SLEEP))
        return true;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_STUN))
        return true;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_FREEZE))
        return true;
    //else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_KNOCKOUT))
    //	return true;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_POLYMORPH))
        return true;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_BANISH))
        return true;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_HORROR))
        return true;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_SAPPED))
        return true;
    return false;
}

void DuelWarlockAI::OnCastTeleGate()
{
    if (m_GatePos.GetPositionZ() == 0)
        return;
    me->GetMotionMaster()->Clear();
    m_Movement->ClearMovement();
    SetTeleport(m_GatePos);
    //me->UpdatePosition(m_GatePos, true);
    //m_Movement->SyncPosition(m_GatePos, true);
}

void DuelWarlockAI::InsureSoulItem()
{
    for (uint8 slot = InventoryPackSlots::INVENTORY_SLOT_ITEM_START; slot < InventoryPackSlots::INVENTORY_SLOT_ITEM_END; slot++)
    {
        Item* pItem = me->GetItemByPos(255, slot);
        if (!pItem)
            continue;
        const ItemTemplate* pTemplate = pItem->GetTemplate();
        if (!pTemplate)
            continue;
        if (pTemplate->GetId() == WarlockFlag_SoulItem)
            return;
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
                if (pTemplate->GetId() == WarlockFlag_SoulItem)
                    return;
            }
        }
    }

    ItemTemplate const* pTemplate = sObjectMgr->GetItemTemplate(WarlockFlag_SoulItem);
    if (!pTemplate)
        return;
    uint32 count = 2;
    uint32 noSpaceForCount = 0;
    ItemPosCountVec dest;
    InventoryResult msg = me->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, pTemplate->GetId(), count, &noSpaceForCount);
    if (msg != EQUIP_ERR_OK)
        count -= noSpaceForCount;
    if (count <= 0 || dest.empty())
        return;
    //me->StoreNewItem(dest, pTemplate->GetId(), true, Item::GenerateItemRandomPropertyId(pTemplate->GetId()));
}
