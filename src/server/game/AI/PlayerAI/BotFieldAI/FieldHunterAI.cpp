
#include "BotFieldClassAI.h"
#include "BotBGAIMovement.h"
#include "PlayerBotSession.h"
#include "Pet.h"

void FieldHunterAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();// PlayerBotSetting::FindPlayerTalentType(me);
}

void FieldHunterAI::ResetBotAI()
{
    BotFieldAI::ResetBotAI();
    m_IsSupplemented = false;
    UpdateTalentType();
    InitializeSpells(me);
    //if (Pet* pet = me->GetPet())
    //{
    //	if (pet->m_spells.empty())
    //		pet->InitPetCreateSpells();
    //	pet->FlushTalentsByPoints();
    //	pet->SettingAllSpellAutocast(true);
    //}
}

void FieldHunterAI::OnLevelUp(uint32 talentType)
{
    if (talentType < 3)
        m_BotTalentType = talentType;
    InitializeSpells(me);
    if (Pet* pet = me->GetPet())
    {
        pet->InitLevelupSpellsForLevel();
        //pet->SettingAllSpellAutocast(true);
    }
    m_IsSupplemented = false;
}

uint32 FieldHunterAI::GetManaPowerPer()
{
    float per = (float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA);
    return (uint32)(per * 100);
}

bool FieldHunterAI::NeedFlee()
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

void FieldHunterAI::ProcessFlee()
{
    FleeMovement();

    NearUnitVec enemys = RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE);
    if (enemys.empty())
        return;
    Unit* pRndPlayer = enemys[urand(0, enemys.size() - 1)];
    Pet* pPet = me->GetPet();
    if (pPet)
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

    if (enemys.size() > 1 && TryCastSpell(HunterTrap_Ice, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    else if (TryCastSpell(HunterTrap_Frozen, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    //if (HunterIDLE_DragonAura)
    //{
    //	if (!me->HasAura(HunterIDLE_DragonAura) && TryCastSpell(HunterIDLE_DragonAura, me) == SpellCastResult::SPELL_CAST_OK)
    //		return;
    //}
    //else
    //{
    //	if (!me->HasAura(HunterIDLE_DodgeAura) && TryCastSpell(HunterIDLE_DodgeAura, me) == SpellCastResult::SPELL_CAST_OK)
    //		return;
    //}
    if (enemys.size() > 1 && TryCastSpell(HunterMelee_NoDamage, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 2 && HunterMelee_BackRoot)
    {
        if (TryCastSpell(HunterMelee_BackRoot, pRndPlayer) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (!pRndPlayer->HasAura(HunterMelee_DecSpeed) && TryCastSpell(HunterMelee_DecSpeed, pRndPlayer) == SpellCastResult::SPELL_CAST_OK)
        return;
    bool hasRoot = HasRootMechanic();
    if (hasRoot && HunterAssist_ClearRoot && TryCastSpell(HunterAssist_ClearRoot, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 0)
    {
        if (hasRoot && HunterAssist_PetRage && TryCastSpell(HunterAssist_PetRage, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (TryCastSpell(HunterAssist_PetStun, pRndPlayer) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (enemys.size() > 1 && TryCastSpell(HunterAssist_FalseDead, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!me->HasAura(HunterMelee_NextAtt) && TryCastSpell(HunterMelee_NextAtt, pRndPlayer) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(HunterMelee_MeleeAtt, pRndPlayer) == SpellCastResult::SPELL_CAST_OK)
        return;

    NearUnitVec farEnemys = SearchFarEnemy(NEEDFLEE_CHECKRANGE + 1, BOTAI_RANGESPELL_DISTANCE);
    if (farEnemys.size() > 0)
    {
        for (Unit* enemy : farEnemys)
        {
            if (TargetIsSuppress(enemy))
                continue;
            if (enemy->GetHealthPct() < 20)
            {
                if (TryCastSpell(HunterShot_KillShot, enemy) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
            if (enemy->HasUnitState(UNIT_STATE_CASTING))
            {
                if (m_BotTalentType == 2)
                {
                    if (TryCastSpell(HunterShot_CharmShot, enemy) == SpellCastResult::SPELL_CAST_OK)
                        return;
                }
                else if (m_BotTalentType == 1)
                {
                    if (TryCastSpell(HunterShot_Silence, enemy) == SpellCastResult::SPELL_CAST_OK)
                        return;
                }
            }
            if (m_BotTalentType == 1)
            {
                if (TryCastSpell(HunterShot_Aim, enemy) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
            else if (m_BotTalentType == 2)
            {
                if (TryCastSpell(HunterShot_Explode, enemy) == SpellCastResult::SPELL_CAST_OK)
                    return;
                if (TryCastSpell(HunterTrap_Shot, enemy) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
            if (TryCastSpell(HunterShot_MgcShot, enemy) == SpellCastResult::SPELL_CAST_OK)
                return;
            return;
        }
    }
}

bool FieldHunterAI::ProcessNormalSpell()
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return true;
    if (!m_IsSupplemented)
    {
        m_IsSupplemented = true;
        std::lock_guard<std::mutex> lock(m_ItemLock);
        //me->SupplementAmmo();
        return true;
    }

    //if (me->GetPetGUID().IsEmpty() && CanCastSpell(HunterIDLE_SummonPet, me) == SpellCastResult::SPELL_CAST_OK)
    //	return false;
    if (!me->HasAura(m_UseMountID))
    {
        Pet* pPet = me->GetPet();
        if (pPet && !pPet->IsAlive())
        {
            m_Movement->ClearMovement();
            TryCastSpell(HunterIDLE_RevivePet, pPet);
            return true;
        }
        else if (pPet && pPet->GetHealthPct() < 85 && !pPet->HasAura(HunterAssist_HealPet))
        {
            if (TryCastSpell(HunterAssist_HealPet, pPet) == SpellCastResult::SPELL_CAST_OK)
                return false;
        }
        else if (!pPet && TryCastSpell(HunterIDLE_SummonPet, me) == SpellCastResult::SPELL_CAST_OK)
        {
            return false;
        }
        else if (me->GetPetGUID().IsEmpty())
        {
            //TC_LOG_INFO("BotBGAI", "Hunter Ai check pet, is no pet!");
            PlayerBotSetting::CheckHunterPet(me);
            return true;
        }
        PetAction(pPet, NULL);
    }
    if (me->HasAura(m_UseMountID))
        return false;
    if (m_BotTalentType == 1)
    {
        if (HunterIDLE_ShotAura && !me->HasAura(HunterIDLE_ShotAura) && TryCastSpell(HunterIDLE_ShotAura, me) == SpellCastResult::SPELL_CAST_OK)
            return false;
    }
    //if (HunterIDLE_DragonAura)
    //{
    //	if (!me->HasAura(HunterIDLE_DragonAura) && TryCastSpell(HunterIDLE_DragonAura, me) == SpellCastResult::SPELL_CAST_OK)
    //		return false;
    //}
    //else
    //{
    //	if (!me->HasAura(HunterIDLE_EagleAura) && TryCastSpell(HunterIDLE_EagleAura, me) == SpellCastResult::SPELL_CAST_OK)
    //		return false;
    //}

    return TryUpMount();
}

void FieldHunterAI::ProcessMeleeSpell(Unit* /*pTarget*/)
{
}

void FieldHunterAI::ProcessRangeSpell(Unit* pTarget)
{
    uint32 manaPct = GetManaPowerPer();
    Pet* pPet = me->GetPet();
    if (!pPet && TryCastSpell(HunterIDLE_SummonPet, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    PetAction(pPet, pTarget);
    if (pPet && pPet->IsAlive() && manaPct > 15)
    {
        if (pPet->GetHealthPct() < 75 && !pPet->HasAura(HunterAssist_HealPet) && TryCastSpell(HunterAssist_HealPet, pPet) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (manaPct > 75)
    {
        if (HunterIDLE_DragonAura)
        {
            if (!me->HasAura(HunterIDLE_DragonAura) && TryCastSpell(HunterIDLE_DragonAura, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        else
        {
            if (!me->HasAura(HunterIDLE_EagleAura) && TryCastSpell(HunterIDLE_EagleAura, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
    }
    else if (manaPct < 20)
    {
        if (!me->HasAura(HunterIDLE_ManaAura) && TryCastSpell(HunterIDLE_ManaAura, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (manaPct < 20)
    {
        if (!pTarget->HasAura(HunterDebug_Mana) && TryCastSpell(HunterDebug_Mana, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else if (manaPct > 40)
    {
        if (!pTarget->HasAura(HunterDebug_Damage) && TryCastSpell(HunterDebug_Damage, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    NearUnitVec selMeEnemys = RangeEnemyListByTargetIsMe(BOTAI_RANGESPELL_DISTANCE);
    if (selMeEnemys.size() > 0)
    {
        if (selMeEnemys.size() > 1 && TryCastSpell(HunterAssist_FalseDead, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        Unit* pRndPlayer = selMeEnemys[urand(0, selMeEnemys.size() - 1)];
        if (HunterTrap_FarFrozen && pRndPlayer != pTarget && TryCastSpell(HunterTrap_FarFrozen, pRndPlayer) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (m_BotTalentType == 2 && HunterDebug_Sleep && pRndPlayer != pTarget && TryCastSpell(HunterDebug_Sleep, pRndPlayer) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    Unit* pCastEnemy = RandomRangeEnemyByCasting(BOTAI_RANGESPELL_DISTANCE);
    if (pCastEnemy)
    {
        if (m_BotTalentType == 1 && HunterShot_Silence && TryCastSpell(HunterShot_Silence, pCastEnemy) == SpellCastResult::SPELL_CAST_OK)
            return;
        else if (m_BotTalentType == 2 && HunterShot_CharmShot && TryCastSpell(HunterShot_CharmShot, pCastEnemy) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    NearUnitVec targetRanges = RangeEnemyListByTargetRange(pTarget, NEEDFLEE_CHECKRANGE);
    if (targetRanges.size() > 5)
    {
        if (HunterShot_MulShot && TryCastSpell(HunterShot_MulShot, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (HunterShot_AOEShot && TryCastSpell(HunterShot_AOEShot, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    if (HunterShot_KillShot && pTarget->GetHealthPct() < 20 && TryCastSpell(HunterShot_KillShot, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!pTarget->HasAura(HunterAssist_Stamp) && TryCastSpell(HunterAssist_Stamp, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(HunterAssist_FastSpeed, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (pTarget->GetTarget() == me->GetGUID())//GetTargetGUID
    {
        if (TryCastSpell(HunterShot_Shock, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (m_BotTalentType == 1 && HunterShot_Aim && TryCastSpell(HunterShot_Aim, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (TryCastSpell(HunterShot_MgcShot, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (m_BotTalentType == 2 && HunterShot_Explode && TryCastSpell(HunterShot_Explode, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else
    {
        if (m_BotTalentType == 1 && HunterShot_Aim && TryCastSpell(HunterShot_Aim, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (TryCastSpell(HunterShot_MgcShot, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (m_BotTalentType == 2 && HunterShot_Explode && TryCastSpell(HunterShot_Explode, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (TryCastSpell(HunterShot_Cast, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
}

void FieldHunterAI::PetAction(Pet* pPet, Unit* pTarget)
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

bool FieldHunterAI::HasRootMechanic()
{
    if (HasAuraMechanic(me, Mechanics::MECHANIC_CHARM) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_FEAR) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_ROOT) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_SLEEP) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_POLYMORPH) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_HORROR) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_STUN))
        return true;
    return false;
}

bool FieldHunterAI::TargetIsSuppress(Unit* pTarget)
{
    if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_CHARM) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_FEAR) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_ROOT) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_SLEEP) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_POLYMORPH) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_HORROR) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_STUN))
        return true;
    return false;
}
