/* Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * Thanks to the original authors: ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#include "ScriptPCH.h"
#include "Item.h"
#include "Spell.h"
#include "ObjectMgr.h"
#include "TemporarySummon.h"

// Spell summary for ScriptedAI::SelectSpell
struct TSpellSummary
{
    uint8 Targets;                                          // set of enum SelectTarget
    uint8 Effects;                                          // set of enum SelectEffect
} extern *SpellSummary;

void SummonList::DoZoneInCombat(uint32 entry)
{
    for (iterator i = begin(); i != end();)
    {
        Creature *summon = Unit::GetCreature(*me, *i);
        ++i;
        if (summon && summon->IsAIEnabled
            && (!entry || summon->GetEntry() == entry))
            summon->AI()->DoZoneInCombat();
    }
}

void SummonList::DoAction(uint32 entry, uint32 info)
{
    for (iterator i = begin(); i != end();)
    {
        Creature *summon = Unit::GetCreature(*me, *i);
        ++i;
        if (summon && summon->IsAIEnabled
            && (!entry || summon->GetEntry() == entry))
            summon->AI()->DoAction(info);
    }
}

void SummonList::DespawnEntry(uint32 entry)
{
    for (iterator i = begin(); i != end();)
    {
        Creature *summon = Unit::GetCreature(*me, *i);
        if (!summon)
            erase(i++);
        else if (summon->GetEntry() == entry)
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
    while (!empty())
    {
        Creature *summon = Unit::GetCreature(*me, *begin());
        if (!summon)
            erase(begin());
        else
        {
            erase(begin());
            if (summon->isSummon())
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
    me(pCreature),
    IsFleeing(false),
    m_bCombatMovement(true),
    m_uiEvadeCheckCooldown(2500)
{
    m_heroicMode = me->GetMap()->IsHeroic();
    m_difficulty = Difficulty(me->GetMap()->GetSpawnMode());
}

void ScriptedAI::AttackStartNoMove(Unit* pWho)
{
    if (!pWho)
        return;

    if (me->Attack(pWho, false))
        DoStartNoMovement(pWho);
}

void ScriptedAI::UpdateAI(const uint32 /*uiDiff*/)
{
    //Check if we have a current target
    if (!UpdateVictim())
        return;

    if (me->isAttackReady())
    {
        //If we are within range melee the target
        if (me->IsWithinMeleeRange(me->getVictim()))
        {
            me->AttackerStateUpdate(me->getVictim());
            me->resetAttackTimer();
        }
    }
}

void ScriptedAI::DoStartMovement(Unit* pVictim, float fDistance, float fAngle)
{
    if (pVictim)
        me->GetMotionMaster()->MoveChase(pVictim, fDistance, fAngle);
}

void ScriptedAI::DoStartNoMovement(Unit* pVictim)
{
    if (!pVictim)
        return;

    me->GetMotionMaster()->MoveIdle();
}

void ScriptedAI::DoStopAttack()
{
    if (me->getVictim())
        me->AttackStop();
}

void ScriptedAI::DoCastSpell(Unit* pTarget, SpellEntry const* pSpellInfo, bool bTriggered)
{
    if (!pTarget || me->IsNonMeleeSpellCasted(false))
        return;

    me->StopMoving();
    me->CastSpell(pTarget, pSpellInfo, bTriggered);
}

void ScriptedAI::DoPlaySoundToSet(WorldObject* pSource, uint32 uiSoundId)
{
    if (!pSource)
        return;

    if (!GetSoundEntriesStore()->LookupEntry(uiSoundId))
    {
        sLog.outError("TSCR: Invalid soundId %u used in DoPlaySoundToSet (Source: TypeId %u, GUID %u)", uiSoundId, pSource->GetTypeId(), pSource->GetGUIDLow());
        return;
    }

    pSource->PlayDirectSound(uiSoundId);
}

Creature* ScriptedAI::DoSpawnCreature(uint32 uiId, float fX, float fY, float fZ, float fAngle, uint32 uiType, uint32 uiDespawntime)
{
    return me->SummonCreature(uiId, me->GetPositionX()+fX, me->GetPositionY()+fY, me->GetPositionZ()+fZ, fAngle, (TempSummonType)uiType, uiDespawntime);
}

Unit* ScriptedAI::SelectUnit(SelectAggroTarget pTarget, uint32 uiPosition)
{
    //ThreatList m_threatlist;
    std::list<HostileReference*>& threatlist = me->getThreatManager().getThreatList();
    std::list<HostileReference*>::iterator itr = threatlist.begin();
    std::list<HostileReference*>::reverse_iterator ritr = threatlist.rbegin();

    if (uiPosition >= threatlist.size() || !threatlist.size())
        return NULL;

    switch (pTarget)
    {
    case SELECT_TARGET_RANDOM:
        advance (itr , uiPosition +  (rand() % (threatlist.size() - uiPosition)));
        return Unit::GetUnit((*me),(*itr)->getUnitGuid());
        break;

    case SELECT_TARGET_TOPAGGRO:
        advance (itr , uiPosition);
        return Unit::GetUnit((*me),(*itr)->getUnitGuid());
        break;

    case SELECT_TARGET_BOTTOMAGGRO:
        advance (ritr , uiPosition);
        return Unit::GetUnit((*me),(*ritr)->getUnitGuid());
        break;

    default:
        return UnitAI::SelectTarget(pTarget, uiPosition);
    }
}

SpellEntry const* ScriptedAI::SelectSpell(Unit* pTarget, uint32 uiSchool, uint32 uiMechanic, SelectTargetType selectTargets, uint32 uiPowerCostMin, uint32 uiPowerCostMax, float fRangeMin, float fRangeMax, SelectEffect selectEffects)
{
    //No target so we can't cast
    if (!pTarget)
        return false;

    //Silenced so we can't cast
    if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SILENCED))
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
        pTempSpell = GetSpellStore()->LookupEntry(me->m_spells[i]);

        //This spell doesn't exist
        if (!pTempSpell)
            continue;

        // Targets and Effects checked first as most used restrictions
        //Check the spell targets if specified
        if (selectTargets && !(SpellSummary[me->m_spells[i]].Targets & (1 << (selectTargets-1))))
            continue;

        //Check the type of spell if we are looking for a specific spell type
        if (selectEffects && !(SpellSummary[me->m_spells[i]].Effects & (1 << (selectEffects-1))))
            continue;

        //Check for school if specified
        if (uiSchool && (pTempSpell->SchoolMask & uiSchool) == 0)
            continue;

        //Check for spell mechanic if specified
        if (uiMechanic && pTempSpell->Mechanic != uiMechanic)
            continue;

        //Make sure that the spell uses the requested amount of power
        if (uiPowerCostMin && pTempSpell->manaCost < uiPowerCostMin)
            continue;

        if (uiPowerCostMax && pTempSpell->manaCost > uiPowerCostMax)
            continue;

        //Continue if we don't have the mana to actually cast this spell
        if (pTempSpell->manaCost > me->GetPower((Powers)pTempSpell->powerType))
            continue;

        //Get the Range
        pTempRange = GetSpellRangeStore()->LookupEntry(pTempSpell->rangeIndex);

        //Spell has invalid range store so we can't use it
        if (!pTempRange)
            continue;

        //Check if the spell meets our range requirements
        if (fRangeMin && me->GetSpellMinRangeForTarget(pTarget, pTempRange) < fRangeMin)
            continue;
        if (fRangeMax && me->GetSpellMaxRangeForTarget(pTarget, pTempRange) > fRangeMax)
            continue;

        //Check if our target is in range
         if (me->IsWithinDistInMap(pTarget, (float)me->GetSpellMinRangeForTarget(pTarget, pTempRange)) || !me->IsWithinDistInMap(pTarget, (float)me->GetSpellMaxRangeForTarget(pTarget, pTempRange)))
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
    if (me->IsInRange(pTarget, (float)me->GetSpellMinRangeForTarget(pTarget, pTempRange), (float)me->GetSpellMaxRangeForTarget(pTarget, pTempRange)))
        return false;

    return true;
}

void ScriptedAI::DoResetThreat()
{
    if (!me->CanHaveThreatList() || me->getThreatManager().isThreatListEmpty())
    {
        sLog.outError("TSCR: DoResetThreat called for creature that either cannot have threat list or has empty threat list (me entry = %d)", me->GetEntry());
        return;
    }

    std::list<HostileReference*>& threatlist = me->getThreatManager().getThreatList();

    for (std::list<HostileReference*>::iterator itr = threatlist.begin(); itr != threatlist.end(); ++itr)
    {
        Unit* pUnit = Unit::GetUnit((*me), (*itr)->getUnitGuid());

        if (pUnit && DoGetThreat(pUnit))
            DoModifyThreatPercent(pUnit, -100);
    }
}

float ScriptedAI::DoGetThreat(Unit* pUnit)
{
    if (!pUnit) return 0.0f;
    return me->getThreatManager().getThreat(pUnit);
}

void ScriptedAI::DoModifyThreatPercent(Unit* pUnit, int32 pct)
{
    if (!pUnit) return;
    me->getThreatManager().modifyThreatPercent(pUnit, pct);
}

void ScriptedAI::DoTeleportTo(float fX, float fY, float fZ, uint32 uiTime)
{
    me->Relocate(fX, fY, fZ);
    me->SendMonsterMove(fX, fY, fZ, uiTime);
}

void ScriptedAI::DoTeleportTo(const float fPos[4])
{
    me->NearTeleportTo(fPos[0], fPos[1], fPos[2], fPos[3]);
}

void ScriptedAI::DoTeleportPlayer(Unit* pUnit, float fX, float fY, float fZ, float fO)
{
    if (!pUnit || pUnit->GetTypeId() != TYPEID_PLAYER)
    {
        if (pUnit)
            sLog.outError("TSCR: Creature %u (Entry: %u) Tried to teleport non-player unit (Type: %u GUID: %u) to x: %f y:%f z: %f o: %f. Aborted.", me->GetGUID(), me->GetEntry(), pUnit->GetTypeId(), pUnit->GetGUID(), fX, fY, fZ, fO);
        return;
    }

    CAST_PLR(pUnit)->TeleportTo(pUnit->GetMapId(), fX, fY, fZ, fO, TELE_TO_NOT_LEAVE_COMBAT);
}

void ScriptedAI::DoTeleportAll(float fX, float fY, float fZ, float fO)
{
    Map *map = me->GetMap();
    if (!map->IsDungeon())
        return;

    Map::PlayerList const &PlayerList = map->GetPlayers();
    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
        if (Player* i_pl = i->getSource())
            if (i_pl->isAlive())
                i_pl->TeleportTo(me->GetMapId(), fX, fY, fZ, fO, TELE_TO_NOT_LEAVE_COMBAT);
}

Unit* ScriptedAI::DoSelectLowestHpFriendly(float fRange, uint32 uiMinHPDiff)
{
    Unit* pUnit = NULL;
    Trinity::MostHPMissingInRange u_check(me, fRange, uiMinHPDiff);
    Trinity::UnitLastSearcher<Trinity::MostHPMissingInRange> searcher(me, pUnit, u_check);
    me->VisitNearbyObject(fRange, searcher);

    return pUnit;
}

std::list<Creature*> ScriptedAI::DoFindFriendlyCC(float fRange)
{
    std::list<Creature*> pList;
    Trinity::FriendlyCCedInRange u_check(me, fRange);
    Trinity::CreatureListSearcher<Trinity::FriendlyCCedInRange> searcher(me, pList, u_check);
    me->VisitNearbyObject(fRange, searcher);
    return pList;
}

std::list<Creature*> ScriptedAI::DoFindFriendlyMissingBuff(float fRange, uint32 uiSpellid)
{
    std::list<Creature*> pList;
    Trinity::FriendlyMissingBuffInRange u_check(me, fRange, uiSpellid);
    Trinity::CreatureListSearcher<Trinity::FriendlyMissingBuffInRange> searcher(me, pList, u_check);
    me->VisitNearbyObject(fRange, searcher);
    return pList;
}

Player* ScriptedAI::GetPlayerAtMinimumRange(float fMinimumRange)
{
    Player* pPlayer = NULL;

    CellPair pair(Trinity::ComputeCellPair(me->GetPositionX(), me->GetPositionY()));
    Cell cell(pair);
    cell.data.Part.reserved = ALL_DISTRICT;
    cell.SetNoCreate();

    Trinity::PlayerAtMinimumRangeAway check(me, fMinimumRange);
    Trinity::PlayerSearcher<Trinity::PlayerAtMinimumRangeAway> searcher(me, pPlayer, check);
    TypeContainerVisitor<Trinity::PlayerSearcher<Trinity::PlayerAtMinimumRangeAway>, GridTypeMapContainer> visitor(searcher);

    cell.Visit(pair, visitor, *(me->GetMap()));

    return pPlayer;
}

void ScriptedAI::SetEquipmentSlots(bool bLoadDefault, int32 uiMainHand, int32 uiOffHand, int32 uiRanged)
{
    if (bLoadDefault)
    {
        if (CreatureInfo const* pInfo = GetCreatureTemplateStore(me->GetEntry()))
            me->LoadEquipment(pInfo->equipmentId,true);

        return;
    }

    if (uiMainHand >= 0)
        me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, uint32(uiMainHand));

    if (uiOffHand >= 0)
        me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 1, uint32(uiOffHand));

    if (uiRanged >= 0)
        me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 2, uint32(uiRanged));
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
// It is assumed the information is found elswehere and can be handled by the core. So far no luck finding such information/way to extract it.
bool ScriptedAI::EnterEvadeIfOutOfCombatArea(const uint32 uiDiff)
{
    if (m_uiEvadeCheckCooldown <= uiDiff)
        m_uiEvadeCheckCooldown = 2500;
    else
    {
        m_uiEvadeCheckCooldown -= uiDiff;
        return false;
    }

    if (me->IsInEvadeMode() || !me->getVictim())
        return false;

    float fX = me->GetPositionX();
    float fY = me->GetPositionY();
    float fZ = me->GetPositionZ();

    switch(me->GetEntry())
    {
        case NPC_BROODLORD:                                         // broodlord (not move down stairs)
            if (fZ > 448.60f)
                return false;
            break;
        case NPC_VOID_REAVER:                                         // void reaver (calculate from center of room)
            if (me->GetDistance2d(432.59f, 371.93f) < 105.0f)
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
            sLog.outError("TSCR: EnterEvadeIfOutOfCombatArea used for creature entry %u, but does not have any definition.", me->GetEntry());
            return false;
    }

    EnterEvadeMode();
    return true;
}

void Scripted_NoMovementAI::AttackStart(Unit* pWho)
{
    if (!pWho)
        return;

    if (me->Attack(pWho, true))
    {
        DoStartNoMovement(pWho);
    }
}

BossAI::BossAI(Creature *c, uint32 id) : ScriptedAI(c)
, bossId(id), summons(me), instance(c->GetInstanceScript())
, boundary(instance ? instance->GetBossBoundary(id) : NULL)
{
}

void BossAI::_Reset()
{
    if (!me->isAlive())
        return;

    events.Reset();
    summons.DespawnAll();
    if (instance)
        instance->SetBossState(bossId, NOT_STARTED);
}

void BossAI::_JustDied()
{
    events.Reset();
    summons.DespawnAll();
    if (instance)
    {
        instance->SetBossState(bossId, DONE);
        instance->SaveToDB();
    }
}

void BossAI::_EnterCombat()
{
    me->setActive(true);
    DoZoneInCombat();
    if (instance)
        instance->SetBossState(bossId, IN_PROGRESS);
}

void BossAI::TeleportCheaters()
{
    float x, y, z;
    me->GetPosition(x, y, z);
    std::list<HostileReference*> &m_threatlist = me->getThreatManager().getThreatList();
    for (std::list<HostileReference*>::iterator itr = m_threatlist.begin(); itr != m_threatlist.end(); ++itr)
        if ((*itr)->getTarget()->GetTypeId() == TYPEID_PLAYER && !CheckBoundary((*itr)->getTarget()))
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
            default:
                break;
        }
    }

    return true;
}

void BossAI::JustSummoned(Creature *summon)
{
    summons.Summon(summon);
    if (me->isInCombat())
        DoZoneInCombat(summon);
}

void BossAI::SummonedCreatureDespawn(Creature *summon)
{
    summons.Despawn(summon);
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
