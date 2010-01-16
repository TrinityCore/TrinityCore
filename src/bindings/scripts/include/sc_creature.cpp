/* Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * Thanks to the original authors: ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#include "precompiled.h"
#include "Item.h"
#include "Spell.h"
#include "ObjectMgr.h"
#include "TemporarySummon.h"

// Spell summary for ScriptedAI::SelectSpell
struct TSpellSummary
{
    uint8 Targets;                                          // set of enum SelectTarget
    uint8 Effects;                                          // set of enum SelectEffect
} *SpellSummary;

void SummonList::DoZoneInCombat(uint32 entry)
{
    for (iterator i = begin(); i != end();)
    {
        Creature *summon = Unit::GetCreature(*m_creature, *i);
        ++i;
        if(summon && summon->IsAIEnabled
            && (!entry || summon->GetEntry() == entry))
            summon->AI()->DoZoneInCombat();
    }
}

void SummonList::DoAction(uint32 entry, uint32 info)
{
    for (iterator i = begin(); i != end();)
    {
        Creature *summon = Unit::GetCreature(*m_creature, *i);
        ++i;
        if(summon && summon->IsAIEnabled
            && (!entry || summon->GetEntry() == entry))
            summon->AI()->DoAction(info);
    }
}

void SummonList::DespawnEntry(uint32 entry)
{
    for (iterator i = begin(); i != end();)
    {
        Creature *summon = Unit::GetCreature(*m_creature, *i);
        if(!summon)
            erase(i++);
        else if(summon->GetEntry() == entry)
        {
            erase(i++);
            summon->setDeathState(JUST_DIED);
            summon->RemoveCorpse();
        }
        else
            ++i;
    }
}

void SummonList::DespawnAll()
{
    while(!empty())
    {
        Creature *summon = Unit::GetCreature(*m_creature, *begin());
        if(!summon)
            erase(begin());
        else
        {
            erase(begin());
            if(summon->isSummon())
            {
                summon->DestroyForNearbyPlayers();
                CAST_SUM(summon)->UnSummon();
            }
            else
                summon->DisappearAndDie();
        }
    }
}

ScriptedAI::ScriptedAI(Creature* pCreature) : CreatureAI(pCreature),
    m_creature(pCreature),
    IsFleeing(false),
    m_bCombatMovement(true),
    m_uiEvadeCheckCooldown(2500)
{
    m_heroicMode = m_creature->GetMap()->IsHeroic();
    m_difficulty = Difficulty(m_creature->GetMap()->GetSpawnMode());
}

void ScriptedAI::AttackStartNoMove(Unit* pWho)
{
    if (!pWho)
        return;

    if(m_creature->Attack(pWho, false))
        DoStartNoMovement(pWho);
}

void ScriptedAI::UpdateAI(const uint32 uiDiff)
{
    //Check if we have a current target
    if (!UpdateVictim())
        return;

    if (m_creature->isAttackReady())
    {
        //If we are within range melee the target
        if (m_creature->IsWithinMeleeRange(m_creature->getVictim()))
        {
            m_creature->AttackerStateUpdate(m_creature->getVictim());
            m_creature->resetAttackTimer();
        }
    }
}

void ScriptedAI::DoStartMovement(Unit* pVictim, float fDistance, float fAngle)
{
    if (pVictim)
        m_creature->GetMotionMaster()->MoveChase(pVictim, fDistance, fAngle);
}

void ScriptedAI::DoStartNoMovement(Unit* pVictim)
{
    if (!pVictim)
        return;

    m_creature->GetMotionMaster()->MoveIdle();
}

void ScriptedAI::DoStopAttack()
{
    if (m_creature->getVictim())
        m_creature->AttackStop();
}

void ScriptedAI::DoCastSpell(Unit* pTarget, SpellEntry const* pSpellInfo, bool bTriggered)
{
    if (!pTarget || m_creature->IsNonMeleeSpellCasted(false))
        return;

    m_creature->StopMoving();
    m_creature->CastSpell(pTarget, pSpellInfo, bTriggered);
}

void ScriptedAI::DoPlaySoundToSet(WorldObject* pSource, uint32 uiSoundId)
{
    if (!pSource)
        return;

    if (!GetSoundEntriesStore()->LookupEntry(uiSoundId))
    {
        error_log("TSCR: Invalid soundId %u used in DoPlaySoundToSet (Source: TypeId %u, GUID %u)", uiSoundId, pSource->GetTypeId(), pSource->GetGUIDLow());
        return;
    }

    pSource->PlayDirectSound(uiSoundId);
}

Creature* ScriptedAI::DoSpawnCreature(uint32 uiId, float fX, float fY, float fZ, float fAngle, uint32 uiType, uint32 uiDespawntime)
{
    return m_creature->SummonCreature(uiId, m_creature->GetPositionX()+fX, m_creature->GetPositionY()+fY, m_creature->GetPositionZ()+fZ, fAngle, (TempSummonType)uiType, uiDespawntime);
}

Unit* ScriptedAI::SelectUnit(SelectAggroTarget pTarget, uint32 uiPosition)
{
    //ThreatList m_threatlist;
    std::list<HostilReference*>& threatlist = m_creature->getThreatManager().getThreatList();
    std::list<HostilReference*>::iterator itr = threatlist.begin();
    std::list<HostilReference*>::reverse_iterator ritr = threatlist.rbegin();

    if (uiPosition >= threatlist.size() || !threatlist.size())
        return NULL;

    switch (pTarget)
    {
    case SELECT_TARGET_RANDOM:
        advance (itr , uiPosition +  (rand() % (threatlist.size() - uiPosition ) ));
        return Unit::GetUnit((*m_creature),(*itr)->getUnitGuid());
        break;

    case SELECT_TARGET_TOPAGGRO:
        advance (itr , uiPosition);
        return Unit::GetUnit((*m_creature),(*itr)->getUnitGuid());
        break;

    case SELECT_TARGET_BOTTOMAGGRO:
        advance (ritr , uiPosition);
        return Unit::GetUnit((*m_creature),(*ritr)->getUnitGuid());
        break;
    }

    return NULL;
}

SpellEntry const* ScriptedAI::SelectSpell(Unit* pTarget, int32 uiSchool, int32 uiMechanic, SelectTargetType selectTargets, uint32 uiPowerCostMin, uint32 uiPowerCostMax, float fRangeMin, float fRangeMax, SelectEffect selectEffects)
{
    //No target so we can't cast
    if (!pTarget)
        return false;

    //Silenced so we can't cast
    if (m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SILENCED))
        return false;

    //Using the extended script system we first create a list of viable spells
    SpellEntry const* apSpell[CREATURE_MAX_SPELLS];
    memset(apSpell, 0, sizeof(SpellEntry*)*CREATURE_MAX_SPELLS);

    uint32 uiSpellCount = 0;

    SpellEntry const* pTempSpell;
    SpellRangeEntry const* pTempRange;

    //Check if each spell is viable(set it to null if not)
    for (uint32 i = 0; i < CREATURE_MAX_SPELLS; i++)
    {
        pTempSpell = GetSpellStore()->LookupEntry(m_creature->m_spells[i]);

        //This spell doesn't exist
        if (!pTempSpell)
            continue;

        // Targets and Effects checked first as most used restrictions
        //Check the spell targets if specified
        if (selectTargets && !(SpellSummary[m_creature->m_spells[i]].Targets & (1 << (selectTargets-1))))
            continue;

        //Check the type of spell if we are looking for a specific spell type
        if (selectEffects && !(SpellSummary[m_creature->m_spells[i]].Effects & (1 << (selectEffects-1))))
            continue;

        //Check for school if specified
        if (uiSchool >= 0 && pTempSpell->SchoolMask & uiSchool)
            continue;

        //Check for spell mechanic if specified
        if (uiMechanic >= 0 && pTempSpell->Mechanic != uiMechanic)
            continue;

        //Make sure that the spell uses the requested amount of power
        if (uiPowerCostMin && pTempSpell->manaCost < uiPowerCostMin)
            continue;

        if (uiPowerCostMax && pTempSpell->manaCost > uiPowerCostMax)
            continue;

        //Continue if we don't have the mana to actually cast this spell
        if (pTempSpell->manaCost > m_creature->GetPower((Powers)pTempSpell->powerType))
            continue;

        //Get the Range
        pTempRange = GetSpellRangeStore()->LookupEntry(pTempSpell->rangeIndex);

        //Spell has invalid range store so we can't use it
        if (!pTempRange)
            continue;

        //Check if the spell meets our range requirements
        if (fRangeMin && m_creature->GetSpellMinRangeForTarget(pTarget, pTempRange) < fRangeMin)
            continue;
        if (fRangeMax && m_creature->GetSpellMaxRangeForTarget(pTarget, pTempRange) > fRangeMax)
            continue;

        //Check if our target is in range
         if (m_creature->IsWithinDistInMap(pTarget, m_creature->GetSpellMinRangeForTarget(pTarget, pTempRange)) || !m_creature->IsWithinDistInMap(pTarget, m_creature->GetSpellMaxRangeForTarget(pTarget, pTempRange)))
            continue;

        //All good so lets add it to the spell list
        apSpell[uiSpellCount] = pTempSpell;
        ++uiSpellCount;
    }

    //We got our usable spells so now lets randomly pick one
    if (!uiSpellCount)
        return NULL;

    return apSpell[rand()%uiSpellCount];
}

bool ScriptedAI::CanCast(Unit* pTarget, SpellEntry const* pSpell, bool bTriggered)
{
    //No target so we can't cast
    if (!pTarget || !pSpell)
        return false;

    //Silenced so we can't cast
    if (!bTriggered && me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SILENCED))
        return false;

    //Check for power
    if (!bTriggered && me->GetPower((Powers)pSpell->powerType) < pSpell->manaCost)
        return false;

    SpellRangeEntry const* pTempRange = GetSpellRangeStore()->LookupEntry(pSpell->rangeIndex);

    //Spell has invalid range store so we can't use it
    if (!pTempRange)
        return false;

    //Unit is out of range of this spell
    if (me->IsInRange(pTarget, m_creature->GetSpellMinRangeForTarget(pTarget, pTempRange), m_creature->GetSpellMaxRangeForTarget(pTarget, pTempRange)))
        return false;

    return true;
}

void FillSpellSummary()
{
    SpellSummary = new TSpellSummary[GetSpellStore()->GetNumRows()];

    SpellEntry const* pTempSpell;

    for (uint32 i = 0; i < GetSpellStore()->GetNumRows(); ++i)
    {
        SpellSummary[i].Effects = 0;
        SpellSummary[i].Targets = 0;

        pTempSpell = GetSpellStore()->LookupEntry(i);
        //This spell doesn't exist
        if (!pTempSpell)
            continue;

        for (uint32 j = 0; j < 3; ++j)
        {
            //Spell targets self
            if (pTempSpell->EffectImplicitTargetA[j] == TARGET_UNIT_CASTER )
                SpellSummary[i].Targets |= 1 << (SELECT_TARGET_SELF-1);

            //Spell targets a single enemy
            if (pTempSpell->EffectImplicitTargetA[j] == TARGET_UNIT_TARGET_ENEMY ||
                pTempSpell->EffectImplicitTargetA[j] == TARGET_DST_TARGET_ENEMY )
                SpellSummary[i].Targets |= 1 << (SELECT_TARGET_SINGLE_ENEMY-1);

            //Spell targets AoE at enemy
            if (pTempSpell->EffectImplicitTargetA[j] == TARGET_UNIT_AREA_ENEMY_SRC ||
                pTempSpell->EffectImplicitTargetA[j] == TARGET_UNIT_AREA_ENEMY_DST ||
                pTempSpell->EffectImplicitTargetA[j] == TARGET_SRC_CASTER ||
                pTempSpell->EffectImplicitTargetA[j] == TARGET_DEST_DYNOBJ_ENEMY )
                SpellSummary[i].Targets |= 1 << (SELECT_TARGET_AOE_ENEMY-1);

            //Spell targets an enemy
            if (pTempSpell->EffectImplicitTargetA[j] == TARGET_UNIT_TARGET_ENEMY ||
                pTempSpell->EffectImplicitTargetA[j] == TARGET_DST_TARGET_ENEMY ||
                pTempSpell->EffectImplicitTargetA[j] == TARGET_UNIT_AREA_ENEMY_SRC ||
                pTempSpell->EffectImplicitTargetA[j] == TARGET_UNIT_AREA_ENEMY_DST ||
                pTempSpell->EffectImplicitTargetA[j] == TARGET_SRC_CASTER ||
                pTempSpell->EffectImplicitTargetA[j] == TARGET_DEST_DYNOBJ_ENEMY )
                SpellSummary[i].Targets |= 1 << (SELECT_TARGET_ANY_ENEMY-1);

            //Spell targets a single friend(or self)
            if (pTempSpell->EffectImplicitTargetA[j] == TARGET_UNIT_CASTER ||
                pTempSpell->EffectImplicitTargetA[j] == TARGET_UNIT_TARGET_ALLY ||
                pTempSpell->EffectImplicitTargetA[j] == TARGET_UNIT_TARGET_PARTY )
                SpellSummary[i].Targets |= 1 << (SELECT_TARGET_SINGLE_FRIEND-1);

            //Spell targets aoe friends
            if (pTempSpell->EffectImplicitTargetA[j] == TARGET_UNIT_PARTY_CASTER ||
                pTempSpell->EffectImplicitTargetA[j] == TARGET_UNIT_PARTY_TARGET ||
                pTempSpell->EffectImplicitTargetA[j] == TARGET_SRC_CASTER)
                SpellSummary[i].Targets |= 1 << (SELECT_TARGET_AOE_FRIEND-1);

            //Spell targets any friend(or self)
            if (pTempSpell->EffectImplicitTargetA[j] == TARGET_UNIT_CASTER ||
                pTempSpell->EffectImplicitTargetA[j] == TARGET_UNIT_TARGET_ALLY ||
                pTempSpell->EffectImplicitTargetA[j] == TARGET_UNIT_TARGET_PARTY ||
                pTempSpell->EffectImplicitTargetA[j] == TARGET_UNIT_PARTY_CASTER ||
                pTempSpell->EffectImplicitTargetA[j] == TARGET_UNIT_PARTY_TARGET ||
                pTempSpell->EffectImplicitTargetA[j] == TARGET_SRC_CASTER)
                SpellSummary[i].Targets |= 1 << (SELECT_TARGET_ANY_FRIEND-1);

            //Make sure that this spell includes a damage effect
            if (pTempSpell->Effect[j] == SPELL_EFFECT_SCHOOL_DAMAGE ||
                pTempSpell->Effect[j] == SPELL_EFFECT_INSTAKILL ||
                pTempSpell->Effect[j] == SPELL_EFFECT_ENVIRONMENTAL_DAMAGE ||
                pTempSpell->Effect[j] == SPELL_EFFECT_HEALTH_LEECH )
                SpellSummary[i].Effects |= 1 << (SELECT_EFFECT_DAMAGE-1);

            //Make sure that this spell includes a healing effect (or an apply aura with a periodic heal)
            if (pTempSpell->Effect[j] == SPELL_EFFECT_HEAL ||
                pTempSpell->Effect[j] == SPELL_EFFECT_HEAL_MAX_HEALTH ||
                pTempSpell->Effect[j] == SPELL_EFFECT_HEAL_MECHANICAL ||
                (pTempSpell->Effect[j] == SPELL_EFFECT_APPLY_AURA  && pTempSpell->EffectApplyAuraName[j]== 8 ))
                SpellSummary[i].Effects |= 1 << (SELECT_EFFECT_HEALING-1);

            //Make sure that this spell applies an aura
            if (pTempSpell->Effect[j] == SPELL_EFFECT_APPLY_AURA )
                SpellSummary[i].Effects |= 1 << (SELECT_EFFECT_AURA-1);
        }
    }
}

void ScriptedAI::DoResetThreat()
{
    if (!m_creature->CanHaveThreatList() || m_creature->getThreatManager().isThreatListEmpty())
    {
        error_log("TSCR: DoResetThreat called for creature that either cannot have threat list or has empty threat list (m_creature entry = %d)", m_creature->GetEntry());
        return;
    }

    std::list<HostilReference*>& threatlist = m_creature->getThreatManager().getThreatList();

    for (std::list<HostilReference*>::iterator itr = threatlist.begin(); itr != threatlist.end(); ++itr)
    {
        Unit* pUnit = Unit::GetUnit((*m_creature), (*itr)->getUnitGuid());

        if(pUnit && DoGetThreat(pUnit))
            DoModifyThreatPercent(pUnit, -100);
    }
}

float ScriptedAI::DoGetThreat(Unit* pUnit)
{
    if(!pUnit) return 0.0f;
    return m_creature->getThreatManager().getThreat(pUnit);
}

void ScriptedAI::DoModifyThreatPercent(Unit* pUnit, int32 pct)
{
    if(!pUnit) return;
    m_creature->getThreatManager().modifyThreatPercent(pUnit, pct);
}

void ScriptedAI::DoTeleportTo(float fX, float fY, float fZ, uint32 uiTime)
{
    m_creature->Relocate(fX, fY, fZ);
    m_creature->SendMonsterMove(fX, fY, fZ, uiTime);
}

void ScriptedAI::DoTeleportTo(const float fPos[4])
{
    me->NearTeleportTo(fPos[0], fPos[1], fPos[2], fPos[3]);
}

void ScriptedAI::DoTeleportPlayer(Unit* pUnit, float fX, float fY, float fZ, float fO)
{
    if(!pUnit || pUnit->GetTypeId() != TYPEID_PLAYER)
    {
        if(pUnit)
            error_log("TSCR: Creature %u (Entry: %u) Tried to teleport non-player unit (Type: %u GUID: %u) to x: %f y:%f z: %f o: %f. Aborted.", m_creature->GetGUID(), m_creature->GetEntry(), pUnit->GetTypeId(), pUnit->GetGUID(), fX, fY, fZ, fO);
        return;
    }

    CAST_PLR(pUnit)->TeleportTo(pUnit->GetMapId(), fX, fY, fZ, fO, TELE_TO_NOT_LEAVE_COMBAT);
}

void ScriptedAI::DoTeleportAll(float fX, float fY, float fZ, float fO)
{
    Map *map = m_creature->GetMap();
    if (!map->IsDungeon())
        return;

    Map::PlayerList const &PlayerList = map->GetPlayers();
    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
        if (Player* i_pl = i->getSource())
            if (i_pl->isAlive())
                i_pl->TeleportTo(m_creature->GetMapId(), fX, fY, fZ, fO, TELE_TO_NOT_LEAVE_COMBAT);
}

Unit* ScriptedAI::DoSelectLowestHpFriendly(float fRange, uint32 uiMinHPDiff)
{
    Unit* pUnit = NULL;
    Trinity::MostHPMissingInRange u_check(m_creature, fRange, uiMinHPDiff);
    Trinity::UnitLastSearcher<Trinity::MostHPMissingInRange> searcher(m_creature, pUnit, u_check);
    m_creature->VisitNearbyObject(fRange, searcher);

    return pUnit;
}

std::list<Creature*> ScriptedAI::DoFindFriendlyCC(float fRange)
{
    std::list<Creature*> pList;
    Trinity::FriendlyCCedInRange u_check(m_creature, fRange);
    Trinity::CreatureListSearcher<Trinity::FriendlyCCedInRange> searcher(m_creature, pList, u_check);
    m_creature->VisitNearbyObject(fRange, searcher);
    return pList;
}

std::list<Creature*> ScriptedAI::DoFindFriendlyMissingBuff(float fRange, uint32 uiSpellid)
{
    std::list<Creature*> pList;
    Trinity::FriendlyMissingBuffInRange u_check(m_creature, fRange, uiSpellid);
    Trinity::CreatureListSearcher<Trinity::FriendlyMissingBuffInRange> searcher(m_creature, pList, u_check);
    m_creature->VisitNearbyObject(fRange, searcher);
    return pList;
}

Player* ScriptedAI::GetPlayerAtMinimumRange(float fMinimumRange)
{
    Player* pPlayer = NULL;

    CellPair pair(Trinity::ComputeCellPair(m_creature->GetPositionX(), m_creature->GetPositionY()));
    Cell cell(pair);
    cell.data.Part.reserved = ALL_DISTRICT;
    cell.SetNoCreate();

    Trinity::PlayerAtMinimumRangeAway check(m_creature, fMinimumRange);
    Trinity::PlayerSearcher<Trinity::PlayerAtMinimumRangeAway> searcher(m_creature, pPlayer, check);
    TypeContainerVisitor<Trinity::PlayerSearcher<Trinity::PlayerAtMinimumRangeAway>, GridTypeMapContainer> visitor(searcher);

    CellLock<GridReadGuard> cell_lock(cell, pair);
    cell_lock->Visit(cell_lock, visitor, *(m_creature->GetMap()));

    return pPlayer;
}

void ScriptedAI::SetEquipmentSlots(bool bLoadDefault, int32 uiMainHand, int32 uiOffHand, int32 uiRanged)
{
    if (bLoadDefault)
    {
        if (CreatureInfo const* pInfo = GetCreatureTemplateStore(m_creature->GetEntry()))
            m_creature->LoadEquipment(pInfo->equipmentId,true);

        return;
    }

    if (uiMainHand >= 0)
        m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, uint32(uiMainHand));

    if (uiOffHand >= 0)
        m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 1, uint32(uiOffHand));

    if (uiRanged >= 0)
        m_creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 2, uint32(uiRanged));
}

void ScriptedAI::SetCombatMovement(bool bCombatMove)
{
    m_bCombatMovement = bCombatMove;
}

enum eNPCs
{
    NPC_BROODLORD   = 12017,
    NPC_VOID_REAVER = 19516,
    NPC_JAN_ALAI    = 23578,
    NPC_SARTHARION  = 28860
};

// Hacklike storage used for misc creatures that are expected to evade of outside of a certain area.
// It is assumed the information is found elswehere and can be handled by mangos. So far no luck finding such information/way to extract it.
bool ScriptedAI::EnterEvadeIfOutOfCombatArea(const uint32 uiDiff)
{
    if (m_uiEvadeCheckCooldown <= uiDiff)
        m_uiEvadeCheckCooldown = 2500;
    else
    {
        m_uiEvadeCheckCooldown -= uiDiff;
        return false;
    }

    if (m_creature->IsInEvadeMode() || !m_creature->getVictim())
        return false;

    float fX = m_creature->GetPositionX();
    float fY = m_creature->GetPositionY();
    float fZ = m_creature->GetPositionZ();

    switch(m_creature->GetEntry())
    {
        case NPC_BROODLORD:                                         // broodlord (not move down stairs)
            if (fZ > 448.60f)
                return false;
            break;
        case NPC_VOID_REAVER:                                         // void reaver (calculate from center of room)
            if (m_creature->GetDistance2d(432.59f, 371.93f) < 105.0f)
                return false;
            break;
        case NPC_JAN_ALAI:                                         // jan'alai (calculate by Z)
            if (fZ > 12.0f)
                return false;
            break;
        case NPC_SARTHARION:                                         // sartharion (calculate box)
            if (fX > 3218.86f && fX < 3275.69f && fY < 572.40f && fY > 484.68f)
                return false;
            break;
        default:
            error_log("TSCR: EnterEvadeIfOutOfCombatArea used for creature entry %u, but does not have any definition.", m_creature->GetEntry());
            return false;
    }

    EnterEvadeMode();
    return true;
}

void Scripted_NoMovementAI::AttackStart(Unit* pWho)
{
    if (!pWho)
        return;

    if (m_creature->Attack(pWho, true))
    {
        DoStartNoMovement(pWho);
    }
}

BossAI::BossAI(Creature *c, uint32 id) : ScriptedAI(c)
, bossId(id), summons(me), instance(c->GetInstanceData())
, boundary(instance ? instance->GetBossBoundary(id) : NULL)
{
}

void BossAI::_Reset()
{
    if(!me->isAlive())
        return;

    events.Reset();
    summons.DespawnAll();
    if(instance)
        instance->SetBossState(bossId, NOT_STARTED);
}

void BossAI::_JustDied()
{
    events.Reset();
    summons.DespawnAll();
    if(instance)
    {
        instance->SetBossState(bossId, DONE);
        instance->SaveToDB();
    }
}

void BossAI::_EnterCombat()
{
    me->setActive(true);
    DoZoneInCombat();
    if(instance)
        instance->SetBossState(bossId, IN_PROGRESS);
}

void BossAI::TeleportCheaters()
{
    float x, y, z;
    me->GetPosition(x, y, z);
    std::list<HostilReference*> &m_threatlist = me->getThreatManager().getThreatList();
    for (std::list<HostilReference*>::iterator itr = m_threatlist.begin(); itr != m_threatlist.end(); ++itr)
        if((*itr)->getTarget()->GetTypeId() == TYPEID_PLAYER && !CheckBoundary((*itr)->getTarget()))
            (*itr)->getTarget()->NearTeleportTo(x, y, z, 0);
}

bool BossAI::CheckBoundary(Unit *who)
{
    if (!boundary || !who)
        return true;

    for (BossBoundaryMap::const_iterator itr = boundary->begin(); itr != boundary->end(); ++itr)
    {
        switch (itr->first)
        {
            case BOUNDARY_N:
                if (me->GetPositionX() > itr->second)
                    return false;
                break;
            case BOUNDARY_S:
                if (me->GetPositionX() < itr->second)
                    return false;
                break;
            case BOUNDARY_E:
                if (me->GetPositionY() < itr->second)
                    return false;
                break;
            case BOUNDARY_W:
                if (me->GetPositionY() > itr->second)
                    return false;
                break;
            case BOUNDARY_NW:
                if (me->GetPositionX() + me->GetPositionY() > itr->second)
                    return false;
                break;
            case BOUNDARY_SE:
                if (me->GetPositionX() + me->GetPositionY() < itr->second)
                    return false;
                break;
            case BOUNDARY_NE:
                if (me->GetPositionX() - me->GetPositionY() > itr->second)
                    return false;
                break;
            case BOUNDARY_SW:
                if (me->GetPositionX() - me->GetPositionY() < itr->second)
                    return false;
                break;
        }
    }

    return true;
}

void BossAI::JustSummoned(Creature *summon)
{
    summons.Summon(summon);
    if(me->isInCombat())
        DoZoneInCombat(summon);
}

void BossAI::SummonedCreatureDespawn(Creature *summon)
{
    summons.Despawn(summon);
}

#define GOBJECT(x) (const_cast<GameObjectInfo*>(GetGameObjectInfo(x)))

void LoadOverridenSQLData()
{
    GameObjectInfo *goInfo;

    // Sunwell Plateau : Kalecgos : Spectral Rift
    if(goInfo = GOBJECT(187055))
        if(goInfo->type == GAMEOBJECT_TYPE_GOOBER)
            goInfo->goober.lockId = 57; // need LOCKTYPE_QUICK_OPEN

    // Naxxramas : Sapphiron Birth
    if(goInfo = GOBJECT(181356))
        if(goInfo->type == GAMEOBJECT_TYPE_TRAP)
            goInfo->trap.radius = 50;
}

void LoadOverridenDBCData()
{
    SpellEntry *spellInfo;
    for (uint32 i = 0; i < GetSpellStore()->GetNumRows(); ++i)
    {
        spellInfo = GET_SPELL(i);
        if(!spellInfo)
            continue;

        switch(i)
        {
            // Black Temple : Illidan : Parasitic Shadowfiend Passive
            case 41013:
                spellInfo->EffectApplyAuraName[0] = 4; // proc debuff, and summon infinite fiends
                break;
            // Naxxramas : Gothik : Inform Inf range
            case 27892:
            case 27928:
            case 27935:
            case 27915:
            case 27931:
            case 27937:
                spellInfo->rangeIndex = 13;
                break;
            // Ulduar : Flame Leviathan : Pursued
            case 62374:
                spellInfo->MaxAffectedTargets = 1;
                spellInfo->EffectImplicitTargetB[0] = TARGET_UNIT_AREA_ENTRY_SRC;
                spellInfo->EffectImplicitTargetB[1] = TARGET_UNIT_AREA_ENTRY_SRC;
                break;
        }
    }
}

// SD2 grid searchers.
Creature *GetClosestCreatureWithEntry(WorldObject *pSource, uint32 uiEntry, float fMaxSearchRange, bool bAlive)
{
    return pSource->FindNearestCreature(uiEntry, fMaxSearchRange, bAlive);
}
GameObject *GetClosestGameObjectWithEntry(WorldObject *pSource, uint32 uiEntry, float fMaxSearchRange)
{
    return pSource->FindNearestGameObject(uiEntry, fMaxSearchRange);
}
void GetCreatureListWithEntryInGrid(std::list<Creature*>& lList, WorldObject *pSource, uint32 uiEntry, float fMaxSearchRange)
{
    return pSource->GetCreatureListWithEntryInGrid(lList, uiEntry, fMaxSearchRange);
}
void GetGameObjectListWithEntryInGrid(std::list<GameObject*>& lList, WorldObject *pSource, uint32 uiEntry, float fMaxSearchRange)
{
    return pSource->GetGameObjectListWithEntryInGrid(lList, uiEntry, fMaxSearchRange);
}
