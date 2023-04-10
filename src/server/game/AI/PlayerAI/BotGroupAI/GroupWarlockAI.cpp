
#include "BotGroupClassAI.h"
#include "PlayerBotSession.h"
#include "Pet.h"
#include "Group.h"

void GroupWarlockAI::InitializePetSpells()
{
    if (m_IsInitedPetSpells)
        return;
    Pet* pPet = me->GetPet();
    if (!pPet || !pPet->IsAlive())
        return;

    WarlockPetDemon_Charge = BotUtility::FindPetMaxRankSpellByExist(me, 47996);
    WarlockPetDemon_Melee = BotUtility::FindPetMaxRankSpellByExist(me, 47994);
    WarlockPetDog_MagicBuf = BotUtility::FindPetMaxRankSpellByExist(me, 57567);
    WarlockPetDog_EatMgc = BotUtility::FindPetMaxRankSpellByExist(me, 48011);
    WarlockPetDog_Bite = BotUtility::FindPetMaxRankSpellByExist(me, 54053);
    WarlockPetDog_Silence = BotUtility::FindPetMaxRankSpellByExist(me, 19647);
    WarlockPetSuccubus_Lash = BotUtility::FindPetMaxRankSpellByExist(me, 47992);
    WarlockPetSuccubus_Sneak = BotUtility::FindPetMaxRankSpellByExist(me, 7870);
    WarlockPetSuccubus_Charm = BotUtility::FindPetMaxRankSpellByExist(me, 6358);
    WarlockPetGhost_Shield = BotUtility::FindPetMaxRankSpellByExist(me, 47983);
    WarlockPetGhost_Sneak = BotUtility::FindPetMaxRankSpellByExist(me, 4511);
    WarlockPetGhost_Stamp = BotUtility::FindPetMaxRankSpellByExist(me, 47982);
    WarlockPetGhost_FireArrow = BotUtility::FindPetMaxRankSpellByExist(me, 47964);

    SettingPetAutoCastSpell(WarlockPetDemon_Charge, true);
    SettingPetAutoCastSpell(WarlockPetDemon_Melee, true);
    SettingPetAutoCastSpell(WarlockPetDog_MagicBuf, false);
    SettingPetAutoCastSpell(WarlockPetDog_EatMgc, false);
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

void GroupWarlockAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();// PlayerBotSetting::FindPlayerTalentType(me);
}

void GroupWarlockAI::ResetBotAI()
{
    BotGroupAI::ResetBotAI();
    m_IsInitedPetSpells = false;
    UpdateTalentType();
    InitializeSpells(me);
}

uint32 GroupWarlockAI::GetSeducePriority()
{
    if (!me->IsAlive())
        return 0;
    return 2;
}

void GroupWarlockAI::OnLevelUp(uint32 talentType)
{
    BotGroupAI::OnLevelUp(talentType);
    if (talentType < 3)
        m_BotTalentType = talentType;
    InitializeSpells(me);
    m_IsInitedPetSpells = false;
    InitializePetSpells();
}

uint32 GroupWarlockAI::GetManaPowerPer()
{
    float per = (float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA);
    return (uint32)(per * 100);
}

bool GroupWarlockAI::NeedFlee()
{
    if (m_Flee.Fleeing())
        return true;
    if (RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE).size() > 0)
        return true;
    Unit* pTarget = me->GetSelectedUnit();
    if (!pTarget)
        return false;
    float fleeDistance = m_Flee.CalcMaxFleeDistance(pTarget);
    if (me->GetDistance(pTarget->GetPosition()) < fleeDistance)//BOTAI_FLEE_JUDGE)
        return true;
    return false;
}

void GroupWarlockAI::ProcessSeduceSpell(Unit* pTarget)
{
    if (!pTarget)
        return;
    PetAction(me->GetPet(), NULL);
    if (WarlockDot_AOEDmg && !pTarget->HasAura(WarlockDot_LowDmg, me->GetGUID()) && TryCastSpell(WarlockDot_LowDmg, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (WarlockCurse_MoveLow && m_BotTalentType == 0)
    {
        if (!pTarget->HasAura(WarlockCurse_MoveLow, me->GetGUID()) && TryCastSpell(WarlockCurse_MoveLow, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else if (!pTarget->HasAura(WarlockCurse_MgcDmg, me->GetGUID()) && TryCastSpell(WarlockCurse_MgcDmg, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 2 && WarlockCast_ShadowShock)
    {
        if (!pTarget->HasAura(WarlockCast_ShadowShock) && TryCastSpell(WarlockCast_ShadowShock, pTarget, true) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
}

void GroupWarlockAI::ProcessFlee()
{
    if (!me->HasUnitState(UNIT_STATE_CASTING))
        FleeMovement();
    if (ProcessMana())
        return;

    NearUnitVec enemys = RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE);
    if (enemys.empty())
        return;
    Unit* pRndPlayer = NULL;
    for (Unit* player : enemys)
    {
        if (!TargetIsFear(player))
        {
            pRndPlayer = player;
            break;
        }
    }
    if (pRndPlayer == NULL)
        pRndPlayer = enemys[urand(0, enemys.size() - 1)];
    Pet* pPet = me->GetPet();
    if (pPet && !pPet->HasUnitState(UNIT_STATE_CASTING))
    {
        Unit* pPetTarget = pPet->GetVictim();
        bool isValidTarget = false;
        for (Unit* player : enemys)
        {
            if (pPetTarget == player)
            {
                isValidTarget = true;
                break;
            }
        }
        if (!isValidTarget)
        {
            PetAction(pPet, pRndPlayer);
        }
    }

    if (enemys.size() <= 2 && !TargetIsFear(pRndPlayer))
    {
        if (enemys.size() > 1)
        {
            //if (WarlockAssist_AOEFear && TargetIsNotDiminishingByType2(pRndPlayer, DiminishingGroup::DIMINISHING_FEAR))
            //{
            //	me->StopMoving();
            //	if (TryCastSpell(WarlockAssist_AOEFear, pRndPlayer) == SpellCastResult::SPELL_CAST_OK)
            //		return;
            //}
        }
        if (TryCastSpell(WarlockAssist_FastFear, pRndPlayer) == SpellCastResult::SPELL_CAST_OK)
        {
            return;
        }
        if (WarlockAssist_BaseFear)
        {
            //if (!BotUtility::ControllSpellDiminishing || TargetIsNotDiminishingByType2(pRndPlayer, DiminishingGroup::DIMINISHING_FEAR))
            //{
            //	me->StopMoving();
            //	if (TryCastSpell(WarlockAssist_BaseFear, pRndPlayer) == SpellCastResult::SPELL_CAST_OK)
            //		return;
            //}
        }
    }
    ProcessPetSpell(pRndPlayer, true);

    if (m_BotTalentType == 1 && WarlockAssist_DemonPower && TryCastSpell(WarlockAssist_DemonPower, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (WarlockAOE_MeleeFire && TryCastSpell(WarlockAOE_MeleeFire, pRndPlayer) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 2 && enemys.size() > 1 && WarlockAOE_ShadowRage)
    {
        if (TryCastSpell(WarlockAOE_ShadowRage, pRndPlayer) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (WarlockCurse_MoveLow && m_BotTalentType == 0 && !pRndPlayer->HasAura(WarlockCurse_MoveLow, me->GetGUID()) && TryCastSpell(WarlockCurse_MoveLow, pRndPlayer) == SpellCastResult::SPELL_CAST_OK)
        return;

    if (m_BotTalentType == 2 && WarlockCast_ShadowShock)
    {
        if (!pRndPlayer->HasAura(WarlockCast_ShadowShock) && TryCastSpell(WarlockCast_ShadowShock, pRndPlayer, true) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    if (!pRndPlayer->HasAura(WarlockCurse_MoveLow, me->GetGUID()))
    {
        if (TryCastSpell(WarlockCurse_MoveLow, pRndPlayer) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (m_BotTalentType == 0)
    {
        NearUnitVec nearEnemys = RangeEnemyListByHasAura(0, BOTAI_RANGESPELL_DISTANCE);
        for (Unit* pUnit : nearEnemys)
        {
            if (!pUnit->IsInCombat() || !me->IsWithinLOSInMap(pUnit))
                continue;
            if (ProcessDot(pUnit, false))
                return;
        }
    }
    else
        ProcessDot(pRndPlayer, false);
}

void GroupWarlockAI::ProcessPetSpell(Unit* pTarget, bool fleeing)
{
    Pet* pPet = me->GetPet();
    if (!pPet || pPet->HasUnitState(UNIT_STATE_CASTING))
        return;

    Unit* pPetTarget = RandomRangeEnemyByCasting(BOTAI_RANGESPELL_DISTANCE);
    if (pPetTarget && WarlockPetDog_Silence)
    {
        if (PetTryCastSpell(WarlockPetDog_Silence, pPetTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    if (WarlockPetSuccubus_Charm)
    {
        NearUnitVec enemys;
        if (fleeing)
            enemys = RangeEnemyListByTargetIsMe(BOTAI_RANGESPELL_DISTANCE);
        else
            enemys = RangeEnemyListByHasAura(0, BOTAI_RANGESPELL_DISTANCE);
        for (Unit* pEnemy : enemys)
        {
            if (!fleeing && pEnemy == pTarget)
                continue;
            if (TargetIsFear(pEnemy))
                continue;
            if (SearchFriendTargetIsTarget(pEnemy, BOTAI_RANGESPELL_DISTANCE).size() > 0)
                continue;
            //if (TargetIsNotDiminishingByType2(pEnemy, DiminishingGroup::DIMINISHING_FEAR))
            //{
            //	if (PetTryCastSpell(WarlockPetSuccubus_Charm, pEnemy) == SpellCastResult::SPELL_CAST_OK)
            //	{
            //		return;
            //	}
            //}
        }
    }
}

bool GroupWarlockAI::ProcessMana()
{
    uint32 manaPct = GetManaPowerPer();
    if (manaPct > 35)
        return false;
    if (m_BotTalentType == 0 && WarlockAssist_ExtractMana)
    {
        if (TryCastSpell(WarlockAssist_ExtractMana, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (me->GetHealthPct() > 50)
    {
        if (TryCastSpell(WarlockAssist_ConvertMana, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    return false;
}

bool GroupWarlockAI::ProcessDot(Unit* pTarget, bool canCastTime)
{
    if (!pTarget)
        return false;
    uint32 targetRangeCount = RangeEnemyListByTargetRange(pTarget, NEEDFLEE_CHECKRANGE).size();
    if (!WarlockDot_AOEDmg || targetRangeCount <= 2)
    {
        if (!pTarget->HasAura(WarlockDot_LowDmg, me->GetGUID()) && TryCastSpell(WarlockDot_LowDmg, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (canCastTime)
    {
        if (!WarlockDot_HighDmg || m_BotTalentType != 0)
        {
            if (!pTarget->HasAura(WarlockDot_Sacrifice, me->GetGUID()) && TryCastSpell(WarlockDot_Sacrifice, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
        //if (WarlockDot_AOEDmg && targetRangeCount > 2 && !pTarget->HasAura(WarlockDot_AOEDmg, me->GetGUID()))
        //{
        //	uint32 curTick = getMSTime();
        //	if (curTick > m_LastAOEDotTick && TryCastSpell(WarlockDot_AOEDmg, pTarget) == SpellCastResult::SPELL_CAST_OK)
        //	{
        //		m_LastAOEDotTick = curTick + 8000;
        //		return true;
        //	}
        //}
        if (m_BotTalentType == 0)
        {
            if (!pTarget->HasAura(WarlockDot_LeechSoul, me->GetGUID()) && TryCastSpell(WarlockDot_LeechSoul, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return true;
            if (!pTarget->HasAura(WarlockDot_HighDmg, me->GetGUID()) && TryCastSpell(WarlockDot_HighDmg, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
    }

    if (pTarget->GetTarget() == me->GetGUID())//GetTargetGUID
    {
        Player* pPlayer = (Player*)pTarget->ToPlayer();
        if (TargetIsCastMagic(pPlayer))
        {
            if (!pTarget->HasAura(WarlockCurse_CastLow, me->GetGUID()) && TryCastSpell(WarlockCurse_CastLow, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
        else
        {
            if (!pTarget->HasAura(WarlockCurse_MeleeLow, me->GetGUID()) && TryCastSpell(WarlockCurse_MeleeLow, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
    }
    else
    {
        if (!pTarget->HasAura(WarlockCurse_MgcDmg, me->GetGUID()) && TryCastSpell(WarlockCurse_MgcDmg, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }

    return false;
}

bool GroupWarlockAI::ProcessNormalSpell()
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return true;
    InitializePetSpells();

    if (WarlockPetDog_MagicBuf && !me->HasAura(WarlockPetDog_MagicBuf))
        PetTryCastSpell(WarlockPetDog_MagicBuf, me);
    if (WarlockIDLE_HighArmor)
    {
        if (!me->HasAura(WarlockIDLE_HighArmor) && TryCastSpell(WarlockIDLE_HighArmor, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    else if (WarlockIDLE_Armor)
    {
        if (!me->HasAura(WarlockIDLE_Armor) && TryCastSpell(WarlockIDLE_Armor, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    else if (WarlockIDLE_LowArmor)
    {
        if (!me->HasAura(WarlockIDLE_LowArmor) && TryCastSpell(WarlockIDLE_LowArmor, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (WarlockIDLE_ShadowShield)
    {
        if (!me->HasAura(WarlockIDLE_ShadowShield) && TryCastSpell(WarlockIDLE_ShadowShield, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (!me->HasAura(m_UseMountID))
    {
        if (me->GetPetGUID().IsEmpty())
        {
            if (WarlockIDLE_FastSummon)
                TryCastSpell(WarlockIDLE_FastSummon, me);
            InsureSoulItem();
            if (m_BotTalentType == 1 && WarlockIDLE_SummonGuardDemon && me->getLevel() >= 60)
            {
                if (TryCastSpell(WarlockIDLE_SummonGuardDemon, me) == SpellCastResult::SPELL_CAST_OK)
                {
                    m_IsInitedPetSpells = false;
                    return true;
                }
            }
            else
            {
                uint32 rndRate = urand(0, 99);
                if (rndRate <= 50)
                {
                    if (TryCastSpell(WarlockIDLE_SummonFireDemon, me) == SpellCastResult::SPELL_CAST_OK)
                    {
                        m_IsInitedPetSpells = false;
                        return true;
                    }
                }
                else// if (rndRate > 50)
                {
                    if (TryCastSpell(WarlockIDLE_SummonSuccubus, me) == SpellCastResult::SPELL_CAST_OK)
                    {
                        m_IsInitedPetSpells = false;
                        return true;
                    }
                }
                //else
                //{
                //	if (TryCastSpell(WarlockIDLE_SummonDogDemon, me) == SpellCastResult::SPELL_CAST_OK)
                //	{
                //		m_IsInitedPetSpells = false;
                //		return true;
                //	}
                //}
            }
        }
        else if (m_BotTalentType == 1 && WarlockIDLE_SoulLink)
        {
            if (!me->HasAura(WarlockFlag_SoulLink) && TryCastSpell(WarlockIDLE_SoulLink, me) == SpellCastResult::SPELL_CAST_OK)
                return false;
        }
    }
    return TryUpMount();
}

void GroupWarlockAI::ProcessMeleeSpell(Unit* /*pTarget*/)
{

}

void GroupWarlockAI::ProcessRangeSpell(Unit* pTarget)
{
    PetAction(me->GetPet(), pTarget);
    if (ProcessMana())
        return;

    NearUnitVec enemys = RangeEnemyListByTargetRange(pTarget, NEEDFLEE_CHECKRANGE);
    if (enemys.size() > 3)
    {
        if (m_BotTalentType == 2 && TryCastSpell(WarlockAOE_ShadowRage, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (WarlockDot_AOEDmg && !pTarget->HasAura(WarlockDot_AOEDmg, me->GetGUID()))
        {
            uint32 curTick = getMSTime();
            if (curTick > m_LastAOEDotTick && TryCastSpell(WarlockDot_AOEDmg, pTarget) == SpellCastResult::SPELL_CAST_OK)
            {
                m_LastAOEDotTick = curTick + 8000;
                return;
            }
        }
        if (TryCastSpell(WarlockAOE_RainFire, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    ProcessPetSpell(pTarget, false);
    if (m_BotTalentType == 0)
    {
        NearUnitVec nearEnemys = RangeEnemyListByHasAura(0, BOTAI_RANGESPELL_DISTANCE);
        for (Unit* pUnit : nearEnemys)
        {
            if (!pUnit->IsInCombat() || !me->IsWithinLOSInMap(pUnit))
                continue;
            if (ProcessDot(pUnit, true))
                return;
        }
    }
    else if (ProcessDot(pTarget, true))
        return;

    if (m_BotTalentType == 0 && WarlockAssist_StealLife && me->GetHealthPct() < 65)
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
        InsureSoulItem();
        if (TryCastSpell(WarlockCast_BigFireBall, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
}

void GroupWarlockAI::PetAction(Pet* pPet, Unit* pTarget)
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

bool GroupWarlockAI::TargetIsFear(Unit* pTarget)
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

void GroupWarlockAI::InsureSoulItem()
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

void GroupWarlockAI::UpEnergy()
{
    uint32 max = me->GetMaxPower(Powers::POWER_MANA);
    uint32 power = me->GetPower(Powers::POWER_MANA);
    me->SetPower(Powers::POWER_MANA, (max / 650) + power);
}

uint32 GroupWarlockAI::TryCastSummonRiteSpell()
{
    if (WarlockIDLE_SummonRite == 0 || !me->HasSpell(WarlockIDLE_SummonRite))
        return 0;
    if (!me->IsAlive() || me->IsInCombat() || me->HasUnitState(UNIT_STATE_CASTING))
        return 0;
    std::list<GameObject*> goResults;
    Trinity::GameObjectInRangeCheck checkerGO(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), BOTAI_SEARCH_RANGE);
    Trinity::GameObjectListSearcher<Trinity::GameObjectInRangeCheck> searcherGO(me, goResults, checkerGO);
    //me->VisitNearbyGridObject(BOTAI_SEARCH_RANGE, searcherGO);
    for (GameObject* go : goResults)
    {
        if (go->GetSpellId() == WarlockIDLE_SummonRite)
            return 0;
    }
    Group* pGroup = me->GetGroup();
    if (pGroup)
    {
        Group::MemberSlotList const& memList = pGroup->GetMemberSlots();
        for (Group::MemberSlot const& slot : memList)
        {
            Player* player = ObjectAccessor::FindPlayer(slot.guid);
            if (!player || !player->IsAlive() || me->GetMap() != player->GetMap() || !player->IsInWorld())
                continue;
            if (BotGroupAI* pAI = dynamic_cast<BotGroupAI*>(me->GetAI()))
            {
                if (pAI->CastingSummonRite())
                    return 0;
            }
        }
    }

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(WarlockIDLE_SummonRite,DIFFICULTY_40);//DIFFICULTY_40
    if (!spellInfo || spellInfo->IsPassive() || m_Flying.HasFlying())
        return SpellCastResult::SPELL_FAILED_UNKNOWN;
    /*TriggerCastData data;
    data.triggerFlags = TriggerCastFlags(TriggerCastFlags::TRIGGERED_IGNORE_POWER_AND_REAGENT_COST | TriggerCastFlags::TRIGGERED_IGNORE_CAST_ITEM);
    Spell* spell = new Spell(me, spellInfo, data);
    spell->m_CastItem = NULL;
    SpellCastTargets targets;
    targets.SetUnitTarget(me);
    Dismount();
    SpellCastResult castResult = spell->prepare(&targets);
    if (castResult == SPELL_CAST_OK)
        return WarlockIDLE_SummonRite;*/
    return 0;
}
