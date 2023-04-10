
#include "BotGroupClassAI.h"
#include "BotBGAIMovement.h"
#include "Item.h"
#include "Bag.h"
#include "Spell.h"

void GroupRogueAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();// PlayerBotSetting::FindPlayerTalentType(me);
}

void GroupRogueAI::ResetBotAI()
{
    BotGroupAI::ResetBotAI();
    m_IsUpedPoison = 0;
    UpdateTalentType();
    InitializeSpells(me);
}

uint32 GroupRogueAI::GetSeducePriority()
{
    if (!me->IsAlive())
        return 0;
    return 3;
}

void GroupRogueAI::OnLevelUp(uint32 talentType)
{
    BotGroupAI::OnLevelUp(talentType);
    if (talentType < 3)
        m_BotTalentType = talentType;
    InitializeSpells(me);
    m_IsUpedPoison = 0;
}

uint32 GroupRogueAI::GetEnergyPowerPer()
{
    float per = (float)me->GetPower(POWER_ENERGY) / (float)me->GetMaxPower(POWER_ENERGY);
    return (uint32)(per * 100);
}

uint32 GroupRogueAI::GetPoisonEntryByWeaponType(EquipmentSlots equipSlot)
{
    if (equipSlot == EQUIPMENT_SLOT_MAINHAND)
    {
        uint32 level = me->getLevel();
        if (level < 20)
            return 0;
        else if (level < 28)
            return 6947;
        else if (level < 36)
            return 6949;
        else if (level < 44)
            return 6950;
        else if (level < 52)
            return 8926;
        else if (level < 60)
            return 8927;
        else if (level < 68)
            return 8928;
        else if (level < 73)
            return 21927;
        else if (level < 79)
            return 43230;
        else
            return 43231;
    }
    else if (equipSlot == EQUIPMENT_SLOT_OFFHAND)
    {
        uint32 level = me->getLevel();
        if (level < 20)
            return 0;
        else if (level < 30)
            return 6947;
        else if (level < 38)
            return 2892;
        else if (level < 46)
            return 2893;
        else if (level < 54)
            return 8984;
        else if (level < 60)
            return 8985;
        else if (level < 70)
            return 20844;
        else if (level < 80)
            return 22054;
        else
            return 43233;
        //return 3775;
    }
    return 0;
}

bool GroupRogueAI::ProcessUpPoison()
{
    if (m_IsUpedPoison >= 2)
        return false;
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return true;
    if (me->getLevel() < 20)
    {
        ++m_IsUpedPoison;
        return false;
    }
    ++m_IsUpedPoison;
    std::lock_guard<std::mutex> lock(m_ItemLock);
    //for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
    //{
    //	if (Bag* pBag = me->GetBagByPos(i))
    //	{
    //		for (uint32 j = 0; j < pBag->GetBagSize(); j++)
    //		{
    //			Item* pItem = pBag->GetItemByPos(uint8(j));
    //			if (!pItem)
    //				continue;
    //			me->DestroyItem(i, uint8(j), true);
    //		}
    //	}
    //}
    EquipmentSlots equipSlot = (m_IsUpedPoison <= 1) ? EquipmentSlots::EQUIPMENT_SLOT_MAINHAND : EquipmentSlots::EQUIPMENT_SLOT_OFFHAND;
    Item* pWeaponItem = me->GetItemByPos(255, equipSlot);
    if (!pWeaponItem)
        return false;
    uint32 poisonEntry = GetPoisonEntryByWeaponType(equipSlot);
    if (poisonEntry == 0)
        return false;
    Item* itemInst = BotUtility::FindItemFromAllBag(me, poisonEntry);
    if (!itemInst)
        itemInst = BotUtility::StoreNewItemByEntry(me, poisonEntry);
    if (!itemInst)
        return false;
    //ItemTemplate const* pTemplate = sObjectMgr->GetItemTemplate(poisonEntry);
    //if (!pTemplate)
    //	return false;
    //uint32 count = 1;
    //uint32 noSpaceForCount = 0;
    //ItemPosCountVec dest;
    //InventoryResult msg = me->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, pTemplate->ItemId, count, &noSpaceForCount);
    //if (msg != EQUIP_ERR_OK)
    //	count -= noSpaceForCount;
    //if (count <= 0 || dest.empty())
    //	return false;
    //Item* itemInst = me->StoreNewItem(dest, pTemplate->ItemId, true, Item::GenerateItemRandomPropertyId(pTemplate->ItemId));
    //if (!itemInst)
    //	return false;

    SpellCastTargets targets;
    targets.SetTargetMask(TARGET_FLAG_ITEM);
    targets.SetItemTarget(pWeaponItem);
    targets.SetSrc(me->GetPosition());
    targets.SetDst(me->GetPosition());
    targets.Update(me);
    me->CastItemUseSpell(itemInst, targets,ObjectGuid::Empty,0);
    return true;
}

void GroupRogueAI::ProcessSeduceSpell(Unit* pTarget)
{
    if (!pTarget)
        return;
    ProcessMeleeSpell(pTarget);
}

bool GroupRogueAI::ProcessNormalSpell()
{
    if (!me->IsMounted() && ProcessUpPoison())
        return true;
    Unit* pUnit = me->GetSelectedUnit();
    if (pUnit && pUnit->IsAlive())
    {
        if (!me->IsInCombat() && TryCastSpell(RogueGuard_Sneak, me) == SpellCastResult::SPELL_CAST_OK)
        {
            OnCastSneak();
            return false;
        }
    }
    else
    {
        if (me->HasAura(RogueGuard_Sneak))
        {
            me->RemoveOwnedAura(RogueGuard_Sneak, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
        }
    }
    if (!me->HasAura(RogueGuard_Sneak) && TryUpMount())
        return true;
    return false;
}

bool GroupRogueAI::ProcessSneakSpell(Unit* pTarget)
{
    if (!pTarget || !me->HasAura(RogueGuard_Sneak))
        return false;
    Unit* pNoSappedUnit = HasAuraMechanic(pTarget, Mechanics::MECHANIC_SAPPED) ? NULL : pTarget;
    NearUnitVec enemys = RangeEnemyListByHasAura(0, NEEDFLEE_CHECKRANGE);
    for (Unit* player : enemys)
    {
        if (player == pTarget || player->IsInCombat())
            continue;
        if (HasAuraMechanic(player, Mechanics::MECHANIC_SAPPED))
            continue;
        if (TryCastSpell(RogueSneak_Stick, player) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (!pNoSappedUnit)
            pNoSappedUnit = player;
    }

    if (pNoSappedUnit && pNoSappedUnit != pTarget)
    {
        me->SetSelection(pNoSappedUnit->GetGUID());
        pTarget = pNoSappedUnit;
    }
    if (RogueSneak_Premeditate && TryCastSpell(RogueSneak_Premeditate, pTarget) == SpellCastResult::SPELL_CAST_OK)
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
        if (RogueAttack_BackAtt && TryCastSpell(RogueAttack_BackAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (TryCastSpell(RogueSneak_Surprise, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    return false;
}

bool GroupRogueAI::ProcessMeleeBlind(Unit* pTarget)
{
    NearUnitVec enemys = RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE);
    for (Unit* player : enemys)
    {
        if (player == pTarget || !CanBlind(pTarget))
            continue;
        if (me->HasAura(RogueFlag_Dance))
        {
            if (TryCastSpell(RogueSneak_Surprise, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
        else if (m_BotTalentType == 2 && RogueAssist_ShadowDance)
        {
            if (TryCastSpell(RogueAssist_ShadowDance, me) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
        if (TryCastSpell(RogueAssist_Blind, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        return false;
    }
    return false;
}

void GroupRogueAI::ProcessMeleeSpell(Unit* pTarget)
{
    if (me->GetSelectedUnit() && !me->IsInCombat() && TryCastSpell(RogueGuard_Sneak, me) == SpellCastResult::SPELL_CAST_OK)
    {
        OnCastSneak();
        return;
    }
    if (!CanStartSpell())
        return;
    if (ProcessSneakSpell(pTarget))
        return;
    if (ProcessMeleeBlind(pTarget))
        return;
    NearUnitVec enemys = RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE);
    if (enemys.size() > 1 && TryCastSpell(RogueGuard_Dodge, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (RangeEnemyListByNonAura(0, NEEDFLEE_CHECKRANGE).size() > 2)
    {
        if (RogueAOE_AllDance && TryCastSpell(RogueAOE_AllDance, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (RogueAOE_Knife && TryCastSpell(RogueAOE_Knife, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    if (CastCloakByNeed())
        return;
    if (m_BotTalentType == 0 && RogueAssist_NextCrit)
        TryCastSpell(RogueAssist_NextCrit, pTarget);
    if (RogueAssist_BlockCast && pTarget->HasUnitState(UNIT_STATE_CASTING) && TryCastSpell(RogueAssist_BlockCast, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 1 && RogueAssist_FastSpeed && TryCastSpell(RogueAssist_FastSpeed, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (CanConsumeCombo(pTarget))
    {
        if (pTarget->GetTarget() == me->GetGUID())//GetTargetGUID
        {
            if (RogueAttack_Stun && !HasAuraMechanic(pTarget, Mechanics::MECHANIC_STUN))
            {
                if (TryCastSpell(RogueAttack_Stun, pTarget) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
        }
        if (m_BotTalentType == 1 && RogueAttack_Incision && !me->HasAura(RogueAttack_Incision))
        {
            if (TryCastSpell(RogueAttack_Incision, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        if (m_BotTalentType == 0 && RogueAttack_PoisonDmg /*&& pTarget->HasAuraState(AuraStateType::AURA_STATE_DEADLY_POISON, NULL, me)*/)
        {
            if (TryCastSpell(RogueAttack_PoisonDmg, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        else if (pTarget->HasAura(RogueAttack_Separate, me->GetGUID()))
        {
            if (RogueAttack_PoisonDmg /*&& pTarget->HasAuraState(AuraStateType::AURA_STATE_DEADLY_POISON, NULL, me)*/)
            {
                if (TryCastSpell(RogueAttack_PoisonDmg, pTarget) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
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
        //if (RogueAttack_PoisonAtt && !HasAuraMechanic(pTarget, Mechanics::MECHANIC_SNARE))
        //{
        //	if (TryCastSpell(RogueAttack_PoisonAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        //		return;
        //}
        if (m_BotTalentType == 0)
        {
            if (RogueAttack_Injure && TryCastSpell(RogueAttack_Injure, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
            else if (m_BotTalentType != 0 && RogueAttack_BackAtt && TryCastSpell(RogueAttack_BackAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
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

void GroupRogueAI::ProcessRangeSpell(Unit* pTarget)
{
    if (me->GetSelectedUnit() != pTarget)
        return;
    if (me->GetSelectedUnit() && me->GetDistance(pTarget) < 20)
    {
        if (!me->IsInCombat() && TryCastSpell(RogueGuard_Sneak, me) == SpellCastResult::SPELL_CAST_OK)
        {
            OnCastSneak();
            return;
        }
        if (ProcessSneakSpell(pTarget))
            return;
        if (ProcessMeleeBlind(pTarget))
            return;
    }
    if (RogueAssist_ShadowFlash)
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
    else if (RogueRange_Throw && combo > 2)
    {
        if (TryCastSpell(RogueRange_Throw, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (CastCloakByNeed())
        return;
}

void GroupRogueAI::ProcessFlee()
{
    FleeMovement();
    if (!me->IsInCombat() && TryCastSpell(RogueGuard_Sneak, me) == SpellCastResult::SPELL_CAST_OK)
    {
        OnCastSneak();
        return;
    }
    if (me->HasAura(RogueGuard_Sneak))
        return;

    if (CastCloakByNeed())
        return;
    NearUnitVec enemys = RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE);
    for (Unit* player : enemys)
    {
        if (!HasAuraMechanic(player, Mechanics::MECHANIC_CHARM) && !HasAuraMechanic(player, Mechanics::MECHANIC_DISORIENTED))
        {
            if (TryCastSpell(RogueAssist_Blind, player) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        //if (!HasAuraMechanic(player, Mechanics::MECHANIC_KNOCKOUT))
        //{
        //	if (TryCastSpell(RogueAssist_Paralyze, player) == SpellCastResult::SPELL_CAST_OK)
        //		return;
        //}
        if (me->HasAura(RogueFlag_Dance) && !HasAuraMechanic(player, Mechanics::MECHANIC_STUN))
        {
            if (TryCastSpell(RogueSneak_Surprise, player) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
    }
    if (enemys.size() > 1)
    {
        if (TryCastSpell(RogueGuard_Sprint, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (TryCastSpell(RogueGuard_Dodge, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (!HasAuraMechanic(me, Mechanics::MECHANIC_BLEED))
        {
            if (TryCastSpell(RogueGuard_Disappear, me) == SpellCastResult::SPELL_CAST_OK)
            {
                me->AttackStop();
                return;
            }
        }
        if (m_BotTalentType == 2)
        {
            if (RogueAssist_ShadowDance && !me->HasAura(RogueFlag_Dance) && TryCastSpell(RogueAssist_ShadowDance, me) == SpellCastResult::SPELL_CAST_OK)
                return;
            if (RogueAssist_ReadyCD && TryCastSpell(RogueAssist_ReadyCD, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
    }
}

bool GroupRogueAI::CastCloakByNeed()
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

bool GroupRogueAI::CanBlind(Unit* pTarget)
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

bool GroupRogueAI::CanConsumeCombo(Unit* pTarget)
{
    uint8 combo = me->GetComboPoints();
    if (combo == 0)
        return false;
    float targetLife = pTarget->GetHealthPct();
    if (targetLife < 3)
        return true;
    else if (targetLife < 10 && combo > 2)
        return true;
    else if (combo >= 5)
        return true;
    return false;
}

bool GroupRogueAI::CanStartSpell()
{
    //if (m_BotTalentType == 0)
    //	return GetEnergyPowerPer() >= 60;
    return GetEnergyPowerPer() >= 60;
}

void GroupRogueAI::OnCastSneak()
{
    NearUnitVec enemys = RangeEnemyListByTargetIsMe(BOTAI_SEARCH_RANGE);
    for (Unit* player : enemys)
    {
        player->SetTarget(ObjectGuid::Empty);
        //player->SetSelection(ObjectGuid::Empty);
    }
}

void GroupRogueAI::OnCastFlash(Unit* pTarget)
{
    me->GetMotionMaster()->Clear();
    Position pos = pTarget->GetPosition();
    me->TeleportTo(me->GetMapId(), pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), me->GetOrientation());
    //WorldSession* pSession = me->GetSession();

   /* WorldPacket opcode2(CMSG_MOVE_TELEPORT_ACK);
    WorldPackets::Movement::MoveTeleportAck pakcet(std::move(opcode2));
    pakcet.MoverGUID = me->GetGUID();
    pSession->HandleMoveTeleportAck(pakcet);*/

    m_Movement->SyncPosition(pos, true);
}

void GroupRogueAI::UpEnergy()
{
    uint32 max = me->GetMaxPower(Powers::POWER_ENERGY);
    uint32 power = me->GetPower(Powers::POWER_ENERGY);
    me->SetPower(Powers::POWER_ENERGY, (max / 36) + power);
}

bool GroupRogueAI::TryBlockCastingByTarget(Unit* pTarget)
{
    if (!pTarget)
        return false;
    if (RogueAssist_BlockCast && TryCastSpell(RogueAssist_BlockCast, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return true;
    return false;
}
