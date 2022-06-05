/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptedCreature.h"
#include "AreaBoundary.h"
#include "Cell.h"
#include "CellImpl.h"
#include "DBCStores.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "InstanceScript.h"
#include "Log.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Spell.h"
#include "SpellMgr.h"
#include "TemporarySummon.h"

// Spell summary for ScriptedAI::SelectSpell
struct TSpellSummary
{
    uint8 Targets; // set of enum SelectTarget
    uint8 Effects; // set of enum SelectEffect
};

extern TSpellSummary* SpellSummary;

void SummonList::Summon(Creature const* summon)
{
    _storage.push_back(summon->GetGUID());
}

void SummonList::Despawn(Creature const* summon)
{
    _storage.remove(summon->GetGUID());
}

void SummonList::DoZoneInCombat(uint32 entry)
{
    for (StorageType::iterator i = _storage.begin(); i != _storage.end();)
    {
        Creature* summon = ObjectAccessor::GetCreature(*_me, *i);
        ++i;
        if (summon && summon->IsAIEnabled()
                && (!entry || summon->GetEntry() == entry))
        {
            summon->AI()->DoZoneInCombat(nullptr);
        }
    }
}

void SummonList::DespawnEntry(uint32 entry)
{
    for (StorageType::iterator i = _storage.begin(); i != _storage.end();)
    {
        Creature* summon = ObjectAccessor::GetCreature(*_me, *i);
        if (!summon)
            i = _storage.erase(i);
        else if (summon->GetEntry() == entry)
        {
            i = _storage.erase(i);
            summon->DespawnOrUnsummon();
        }
        else
            ++i;
    }
}

void SummonList::DespawnAll()
{
    while (!_storage.empty())
    {
        Creature* summon = ObjectAccessor::GetCreature(*_me, _storage.front());
        _storage.pop_front();
        if (summon)
            summon->DespawnOrUnsummon();
    }
}

void SummonList::RemoveNotExisting()
{
    for (StorageType::iterator i = _storage.begin(); i != _storage.end();)
    {
        if (ObjectAccessor::GetCreature(*_me, *i))
            ++i;
        else
            i = _storage.erase(i);
    }
}

bool SummonList::HasEntry(uint32 entry) const
{
    for (ObjectGuid const& guid : _storage)
    {
        Creature* summon = ObjectAccessor::GetCreature(*_me, guid);
        if (summon && summon->GetEntry() == entry)
            return true;
    }

    return false;
}

void SummonList::DoActionImpl(int32 action, StorageType const& summons)
{
    for (ObjectGuid const& guid : summons)
    {
        Creature* summon = ObjectAccessor::GetCreature(*_me, guid);
        if (summon && summon->IsAIEnabled())
            summon->AI()->DoAction(action);
    }
}

ScriptedAI::ScriptedAI(Creature* creature) : CreatureAI(creature), IsFleeing(false), _isCombatMovementAllowed(true)
{
    _isHeroic = me->GetMap()->IsHeroic();
    _difficulty = Difficulty(me->GetMap()->GetSpawnMode());
}

void ScriptedAI::AttackStartNoMove(Unit* who)
{
    if (!who)
        return;

    if (me->Attack(who, true))
        DoStartNoMovement(who);
}

void ScriptedAI::AttackStart(Unit* who)
{
    if (IsCombatMovementAllowed())
        CreatureAI::AttackStart(who);
    else
        AttackStartNoMove(who);
}

void ScriptedAI::UpdateAI(uint32 /*diff*/)
{
    // Check if we have a current target
    if (!UpdateVictim())
        return;

    DoMeleeAttackIfReady();
}

void ScriptedAI::DoStartMovement(Unit* victim, float distance, float angle)
{
    if (victim)
        me->GetMotionMaster()->MoveChase(victim, distance, angle);
}

void ScriptedAI::DoStartNoMovement(Unit* victim)
{
    if (!victim)
        return;

    me->GetMotionMaster()->MoveIdle();
}

void ScriptedAI::DoStopAttack()
{
    if (me->GetVictim())
        me->AttackStop();
}

void ScriptedAI::DoCastSpell(Unit* target, SpellInfo const* spellInfo, bool triggered)
{
    if (!target || me->IsNonMeleeSpellCast(false))
        return;

    me->StopMoving();
    me->CastSpell(target, spellInfo->Id, triggered ? TRIGGERED_FULL_MASK : TRIGGERED_NONE);
}

void ScriptedAI::DoPlaySoundToSet(WorldObject* source, uint32 soundId)
{
    if (!source)
        return;

    if (!sSoundEntriesStore.LookupEntry(soundId))
    {
        TC_LOG_ERROR("scripts.ai", "ScriptedAI::DoPlaySoundToSet: Invalid soundId %u used in DoPlaySoundToSet (Source: %s)", soundId, source->GetGUID().ToString().c_str());
        return;
    }

    source->PlayDirectSound(soundId);
}

void ScriptedAI::AddThreat(Unit* victim, float amount, Unit* who)
{
    if (!victim)
        return;
    if (!who)
        who = me;
    who->GetThreatManager().AddThreat(victim, amount, nullptr, true, true);
}

void ScriptedAI::ModifyThreatByPercent(Unit* victim, int32 pct, Unit* who)
{
    if (!victim)
        return;
    if (!who)
        who = me;
    who->GetThreatManager().ModifyThreatByPercent(victim, pct);
}

void ScriptedAI::ResetThreat(Unit* victim, Unit* who)
{
    if (!victim)
        return;
    if (!who)
        who = me;
    who->GetThreatManager().ResetThreat(victim);
}

void ScriptedAI::ResetThreatList(Unit* who)
{
    if (!who)
        who = me;
    who->GetThreatManager().ResetAllThreat();
}

float ScriptedAI::GetThreat(Unit const* victim, Unit const* who)
{
    if (!victim)
        return 0.0f;
    if (!who)
        who = me;
    return who->GetThreatManager().GetThreat(victim);
}

void ScriptedAI::ForceCombatStop(Creature* who, bool reset /*= true*/)
{
    if (!who || !who->IsInCombat())
        return;

    who->CombatStop(true);
    who->DoNotReacquireSpellFocusTarget();
    who->GetMotionMaster()->Clear(MOTION_PRIORITY_NORMAL);

    if (reset) {
        who->LoadCreaturesAddon();
        who->SetLootRecipient(nullptr);
        who->ResetPlayerDamageReq();
        who->SetLastDamagedTime(0);
        who->SetCannotReachTarget(false);
    }
}

void ScriptedAI::ForceCombatStopForCreatureEntry(uint32 entry, float maxSearchRange /*= 250.0f*/, bool samePhase /*= true*/, bool reset /*= true*/)
{
    TC_LOG_DEBUG("scripts.ai", "ScriptedAI::ForceCombatStopForCreatureEntry: called on '%s'. Debug info: %s", me->GetGUID().ToString().c_str(), me->GetDebugInfo().c_str());

    std::list<Creature*> creatures;
    Trinity::AllCreaturesOfEntryInRange check(me, entry, maxSearchRange);
    Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange> searcher(me, creatures, check);

    if (!samePhase)
        searcher.i_phaseMask = PHASEMASK_ANYWHERE;

    Cell::VisitGridObjects(me, searcher, maxSearchRange);

    for (Creature* creature : creatures)
        ForceCombatStop(creature, reset);
}

void ScriptedAI::ForceCombatStopForCreatureEntry(std::vector<uint32> creatureEntries, float maxSearchRange /*= 250.0f*/, bool samePhase /*= true*/, bool reset /*= true*/)
{
    for (uint32 const entry : creatureEntries)
        ForceCombatStopForCreatureEntry(entry, maxSearchRange, samePhase, reset);
}

Creature* ScriptedAI::DoSpawnCreature(uint32 entry, float offsetX, float offsetY, float offsetZ, float angle, uint32 type, Milliseconds despawntime)
{
    return me->SummonCreature(entry, me->GetPositionX() + offsetX, me->GetPositionY() + offsetY, me->GetPositionZ() + offsetZ, angle, TempSummonType(type), despawntime);
}

bool ScriptedAI::HealthBelowPct(uint32 pct) const
{
    return me->HealthBelowPct(pct);
}

bool ScriptedAI::HealthAbovePct(uint32 pct) const
{
    return me->HealthAbovePct(pct);
}

SpellInfo const* ScriptedAI::SelectSpell(Unit* target, uint32 school, uint32 mechanic, SelectTargetType targets, uint32 powerCostMin, uint32 powerCostMax, float rangeMin, float rangeMax, SelectEffect effects)
{
    // No target so we can't cast
    if (!target)
        return nullptr;

    // Silenced so we can't cast
    if (me->HasUnitFlag(UNIT_FLAG_SILENCED))
        return nullptr;

    // Using the extended script system we first create a list of viable spells
    SpellInfo const* apSpell[MAX_CREATURE_SPELLS];
    memset(apSpell, 0, MAX_CREATURE_SPELLS * sizeof(SpellInfo*));

    uint32 spellCount = 0;

    SpellInfo const* tempSpell = nullptr;

    // Check if each spell is viable(set it to null if not)
    for (uint32 spell : me->m_spells)
    {
        tempSpell = sSpellMgr->GetSpellInfo(spell);

        // This spell doesn't exist
        if (!tempSpell)
            continue;

        // Targets and Effects checked first as most used restrictions
        // Check the spell targets if specified
        if (targets && !(SpellSummary[spell].Targets & (1 << (targets-1))))
            continue;

        // Check the type of spell if we are looking for a specific spell type
        if (effects && !(SpellSummary[spell].Effects & (1 << (effects-1))))
            continue;

        // Check for school if specified
        if (school && (tempSpell->SchoolMask & school) == 0)
            continue;

        // Check for spell mechanic if specified
        if (mechanic && tempSpell->Mechanic != mechanic)
            continue;

        // Make sure that the spell uses the requested amount of power
        if (powerCostMin && tempSpell->ManaCost < powerCostMin)
            continue;

        if (powerCostMax && tempSpell->ManaCost > powerCostMax)
            continue;

        // Continue if we don't have the mana to actually cast this spell
        if (tempSpell->ManaCost > me->GetPower(tempSpell->PowerType))
            continue;

        // Check if the spell meets our range requirements
        if (rangeMin && me->GetSpellMinRangeForTarget(target, tempSpell) < rangeMin)
            continue;
        if (rangeMax && me->GetSpellMaxRangeForTarget(target, tempSpell) > rangeMax)
            continue;

        // Check if our target is in range
        if (me->IsWithinDistInMap(target, float(me->GetSpellMinRangeForTarget(target, tempSpell))) || !me->IsWithinDistInMap(target, float(me->GetSpellMaxRangeForTarget(target, tempSpell))))
            continue;

        // All good so lets add it to the spell list
        apSpell[spellCount] = tempSpell;
        ++spellCount;
    }

    // We got our usable spells so now lets randomly pick one
    if (!spellCount)
        return nullptr;

    return apSpell[urand(0, spellCount - 1)];
}

void ScriptedAI::DoTeleportTo(float x, float y, float z, uint32 time)
{
    me->Relocate(x, y, z);
    float speed = me->GetDistance(x, y, z) / ((float)time * 0.001f);
    me->MonsterMoveWithSpeed(x, y, z, speed);
}

void ScriptedAI::DoTeleportTo(const float position[4])
{
    me->NearTeleportTo(position[0], position[1], position[2], position[3]);
}

void ScriptedAI::DoTeleportPlayer(Unit* unit, float x, float y, float z, float o)
{
    if (!unit)
        return;

    if (Player* player = unit->ToPlayer())
        player->TeleportTo(unit->GetMapId(), x, y, z, o, TELE_TO_NOT_LEAVE_COMBAT);
    else
        TC_LOG_ERROR("scripts.ai", "ScriptedAI::DoTeleportPlayer: Creature %s Tried to teleport non-player unit (%s) to x: %f y:%f z: %f o: %f. Aborted.",
            me->GetGUID().ToString().c_str(), unit->GetGUID().ToString().c_str(), x, y, z, o);
}

void ScriptedAI::DoTeleportAll(float x, float y, float z, float o)
{
    Map* map = me->GetMap();
    if (!map->IsDungeon())
        return;

    for (MapReference const& mapref : map->GetPlayers())
        if (Player* player = mapref.GetSource())
            if (player->IsAlive())
                player->TeleportTo(me->GetMapId(), x, y, z, o, TELE_TO_NOT_LEAVE_COMBAT);
}

Unit* ScriptedAI::DoSelectLowestHpFriendly(float range, uint32 minHPDiff)
{
    Unit* unit = nullptr;
    Trinity::MostHPMissingInRange u_check(me, range, minHPDiff);
    Trinity::UnitLastSearcher<Trinity::MostHPMissingInRange> searcher(me, unit, u_check);
    Cell::VisitAllObjects(me, searcher, range);

    return unit;
}

Unit* ScriptedAI::DoSelectBelowHpPctFriendlyWithEntry(uint32 entry, float range, uint8 minHPDiff, bool excludeSelf)
{
    Unit* unit = nullptr;
    Trinity::FriendlyBelowHpPctEntryInRange u_check(me, entry, range, minHPDiff, excludeSelf);
    Trinity::UnitLastSearcher<Trinity::FriendlyBelowHpPctEntryInRange> searcher(me, unit, u_check);
    Cell::VisitAllObjects(me, searcher, range);

    return unit;
}

std::list<Creature*> ScriptedAI::DoFindFriendlyCC(float range)
{
    std::list<Creature*> list;
    Trinity::FriendlyCCedInRange u_check(me, range);
    Trinity::CreatureListSearcher<Trinity::FriendlyCCedInRange> searcher(me, list, u_check);
    Cell::VisitAllObjects(me, searcher, range);

    return list;
}

std::list<Creature*> ScriptedAI::DoFindFriendlyMissingBuff(float range, uint32 uiSpellid)
{
    std::list<Creature*> list;
    Trinity::FriendlyMissingBuffInRange u_check(me, range, uiSpellid);
    Trinity::CreatureListSearcher<Trinity::FriendlyMissingBuffInRange> searcher(me, list, u_check);
    Cell::VisitAllObjects(me, searcher, range);

    return list;
}

Player* ScriptedAI::GetPlayerAtMinimumRange(float minimumRange)
{
    Player* player = nullptr;

    Trinity::PlayerAtMinimumRangeAway check(me, minimumRange);
    Trinity::PlayerSearcher<Trinity::PlayerAtMinimumRangeAway> searcher(me, player, check);
    Cell::VisitWorldObjects(me, searcher, minimumRange);

    return player;
}

void ScriptedAI::SetEquipmentSlots(bool loadDefault, int32 mainHand /*= EQUIP_NO_CHANGE*/, int32 offHand /*= EQUIP_NO_CHANGE*/, int32 ranged /*= EQUIP_NO_CHANGE*/)
{
    if (loadDefault)
    {
        me->LoadEquipment(me->GetOriginalEquipmentId(), true);
        return;
    }

    if (mainHand >= 0)
        me->SetVirtualItem(0, uint32(mainHand));

    if (offHand >= 0)
        me->SetVirtualItem(1, uint32(offHand));

    if (ranged >= 0)
        me->SetVirtualItem(2, uint32(ranged));
}

void ScriptedAI::SetCombatMovement(bool allowMovement)
{
    _isCombatMovementAllowed = allowMovement;
}

// BossAI - for instanced bosses
BossAI::BossAI(Creature* creature, uint32 bossId) : ScriptedAI(creature), instance(creature->GetInstanceScript()), summons(creature), _bossId(bossId)
{
    if (instance)
        SetBoundary(instance->GetBossBoundary(bossId));
    scheduler.SetValidator([this]
    {
        return !me->HasUnitState(UNIT_STATE_CASTING);
    });
}

void BossAI::_Reset()
{
    if (!me->IsAlive())
        return;

    me->SetCombatPulseDelay(0);
    me->ResetLootMode();
    events.Reset();
    summons.DespawnAll();
    scheduler.CancelAll();
    if (instance && instance->GetBossState(_bossId) != DONE)
        instance->SetBossState(_bossId, NOT_STARTED);
}

void BossAI::_JustDied()
{
    events.Reset();
    summons.DespawnAll();
    scheduler.CancelAll();
    if (instance)
        instance->SetBossState(_bossId, DONE);
}

void BossAI::_JustReachedHome()
{
    me->setActive(false);
}

void BossAI::_JustEngagedWith(Unit* who)
{
    if (instance)
    {
        // bosses do not respawn, check only on enter combat
        if (!instance->CheckRequiredBosses(_bossId, who->ToPlayer()))
        {
            EnterEvadeMode(EVADE_REASON_SEQUENCE_BREAK);
            return;
        }
        instance->SetBossState(_bossId, IN_PROGRESS);
    }

    me->SetCombatPulseDelay(5);
    me->setActive(true);
    DoZoneInCombat();
    ScheduleTasks();
}

void BossAI::TeleportCheaters()
{
    float x, y, z;
    me->GetPosition(x, y, z);

    for (auto const& pair : me->GetCombatManager().GetPvECombatRefs())
    {
        Unit* target = pair.second->GetOther(me);
        if (target->IsControlledByPlayer() && !IsInBoundary(target))
            target->NearTeleportTo(x, y, z, 0);
    }
}

void BossAI::JustSummoned(Creature* summon)
{
    summons.Summon(summon);
    if (me->IsEngaged())
        DoZoneInCombat(summon);
}

void BossAI::SummonedCreatureDespawn(Creature* summon)
{
    summons.Despawn(summon);
}

void BossAI::UpdateAI(uint32 diff)
{
    if (!UpdateVictim())
        return;

    events.Update(diff);

    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;

    while (uint32 eventId = events.ExecuteEvent())
    {
        ExecuteEvent(eventId);
        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;
    }

    DoMeleeAttackIfReady();
}

bool BossAI::CanAIAttack(Unit const* target) const
{
    return IsInBoundary(target);
}

void BossAI::_DespawnAtEvade(Seconds delayToRespawn /*= 30s*/, Creature* who /*= nullptr*/)
{
    if (delayToRespawn < 2s)
    {
        TC_LOG_ERROR("scripts.ai", "BossAI::_DespawnAtEvade: called with delay of " UI64FMTD " seconds, defaulting to 2 (me: %s)", delayToRespawn.count(), me->GetGUID().ToString().c_str());
        delayToRespawn = 2s;
    }

    if (!who)
        who = me;

    if (TempSummon* whoSummon = who->ToTempSummon())
    {
        TC_LOG_WARN("scripts.ai", "BossAI::_DespawnAtEvade: called on a temporary summon (who: %s)", who->GetGUID().ToString().c_str());
        whoSummon->UnSummon();
        return;
    }

    who->DespawnOrUnsummon(0s, delayToRespawn);

    if (instance && who == me)
        instance->SetBossState(_bossId, FAIL);
}

// WorldBossAI - for non-instanced bosses
WorldBossAI::WorldBossAI(Creature* creature) : ScriptedAI(creature), summons(creature) { }

void WorldBossAI::_Reset()
{
    if (!me->IsAlive())
        return;

    events.Reset();
    summons.DespawnAll();
}

void WorldBossAI::_JustDied()
{
    events.Reset();
    summons.DespawnAll();
}

void WorldBossAI::_JustEngagedWith()
{
    Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true);
    if (target)
        AttackStart(target);
}

void WorldBossAI::JustSummoned(Creature* summon)
{
    summons.Summon(summon);
    Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true);
    if (target)
        summon->AI()->AttackStart(target);
}

void WorldBossAI::SummonedCreatureDespawn(Creature* summon)
{
    summons.Despawn(summon);
}

void WorldBossAI::UpdateAI(uint32 diff)
{
    if (!UpdateVictim())
        return;

    events.Update(diff);

    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;

    while (uint32 eventId = events.ExecuteEvent())
    {
        ExecuteEvent(eventId);
        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;
    }

    DoMeleeAttackIfReady();
}
