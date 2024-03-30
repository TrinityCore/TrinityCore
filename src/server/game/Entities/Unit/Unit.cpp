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

#include "Unit.h"
#include "AbstractFollower.h"
#include "Battlefield.h"
#include "BattlefieldMgr.h"
#include "Battleground.h"
#include "BattlegroundPackets.h"
#include "BattlegroundScore.h"
#include "BattlePetMgr.h"
#include "CellImpl.h"
#include "CharacterCache.h"
#include "CharmInfo.h"
#include "ChatPackets.h"
#include "ChatTextBuilder.h"
#include "CombatLogPackets.h"
#include "CombatPackets.h"
#include "Common.h"
#include "ConditionMgr.h"
#include "Containers.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "CreatureAIFactory.h"
#include "CreatureGroups.h"
#include "DB2Stores.h"
#include "Formulas.h"
#include "GameObjectAI.h"
#include "GameTime.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "InstanceScript.h"
#include "Item.h"
#include "ItemBonusMgr.h"
#include "KillRewarder.h"
#include "ListUtils.h"
#include "Log.h"
#include "Loot.h"
#include "LootMgr.h"
#include "LootPackets.h"
#include "MiscPackets.h"
#include "MotionMaster.h"
#include "MovementGenerator.h"
#include "MovementPackets.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "OutdoorPvP.h"
#include "PartyPackets.h"
#include "Pet.h"
#include "PetPackets.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "PlayerAI.h"
#include "QuestDef.h"
#include "Spell.h"
#include "ScheduledChangeAI.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellHistory.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "SpellPackets.h"
#include "StringConvert.h"
#include "TemporarySummon.h"
#include "Totem.h"
#include "Transport.h"
#include "Util.h"
#include "Vehicle.h"
#include "VehiclePackets.h"
#include "Vignette.h"
#include "VignettePackets.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include <queue>
#include <sstream>
#include <cmath>

float baseMoveSpeed[MAX_MOVE_TYPE] =
{
    2.5f,                  // MOVE_WALK
    7.0f,                  // MOVE_RUN
    4.5f,                  // MOVE_RUN_BACK
    4.722222f,             // MOVE_SWIM
    2.5f,                  // MOVE_SWIM_BACK
    3.141594f,             // MOVE_TURN_RATE
    7.0f,                  // MOVE_FLIGHT
    4.5f,                  // MOVE_FLIGHT_BACK
    3.14f                  // MOVE_PITCH_RATE
};

float playerBaseMoveSpeed[MAX_MOVE_TYPE] =
{
    2.5f,                  // MOVE_WALK
    7.0f,                  // MOVE_RUN
    4.5f,                  // MOVE_RUN_BACK
    4.722222f,             // MOVE_SWIM
    2.5f,                  // MOVE_SWIM_BACK
    3.141594f,             // MOVE_TURN_RATE
    7.0f,                  // MOVE_FLIGHT
    4.5f,                  // MOVE_FLIGHT_BACK
    3.14f                  // MOVE_PITCH_RATE
};

DispelableAura::DispelableAura(Aura* aura, int32 dispelChance, uint8 dispelCharges) :
    _aura(aura), _chance(dispelChance), _charges(dispelCharges)
{
}

DispelableAura::~DispelableAura() = default;

bool DispelableAura::RollDispel() const
{
    return roll_chance_i(_chance);
}

DamageInfo::DamageInfo(Unit* attacker, Unit* victim, uint32 damage, SpellInfo const* spellInfo, SpellSchoolMask schoolMask, DamageEffectType damageType, WeaponAttackType attackType)
    : m_attacker(attacker), m_victim(victim), m_damage(damage), m_originalDamage(damage), m_spellInfo(spellInfo), m_schoolMask(schoolMask), m_damageType(damageType), m_attackType(attackType),
    m_absorb(0), m_resist(0), m_block(0), m_hitMask(PROC_HIT_NONE)
{
}

DamageInfo::DamageInfo(CalcDamageInfo const& dmgInfo)
    : m_attacker(dmgInfo.Attacker), m_victim(dmgInfo.Target), m_damage(dmgInfo.Damage), m_originalDamage(dmgInfo.Damage), m_spellInfo(nullptr), m_schoolMask(SpellSchoolMask(dmgInfo.DamageSchoolMask)),
    m_damageType(DIRECT_DAMAGE), m_attackType(dmgInfo.AttackType), m_absorb(dmgInfo.Absorb), m_resist(dmgInfo.Resist), m_block(dmgInfo.Blocked), m_hitMask(PROC_HIT_NONE)
{
    switch (dmgInfo.TargetState)
    {
        case VICTIMSTATE_IS_IMMUNE:
            m_hitMask |= PROC_HIT_IMMUNE;
            break;
        case VICTIMSTATE_BLOCKS:
            m_hitMask |= PROC_HIT_FULL_BLOCK;
            break;
    }

    if (dmgInfo.HitInfo & (HITINFO_PARTIAL_ABSORB | HITINFO_FULL_ABSORB))
        m_hitMask |= PROC_HIT_ABSORB;

    if (dmgInfo.HitInfo & HITINFO_FULL_RESIST)
        m_hitMask |= PROC_HIT_FULL_RESIST;

    if (m_block)
        m_hitMask |= PROC_HIT_BLOCK;

    bool const damageNullified = (dmgInfo.HitInfo & (HITINFO_FULL_ABSORB | HITINFO_FULL_RESIST)) != 0 ||
        (m_hitMask & (PROC_HIT_IMMUNE | PROC_HIT_FULL_BLOCK)) != 0;
    switch (dmgInfo.HitOutCome)
    {
        case MELEE_HIT_MISS:
            m_hitMask |= PROC_HIT_MISS;
            break;
        case MELEE_HIT_DODGE:
            m_hitMask |= PROC_HIT_DODGE;
            break;
        case MELEE_HIT_PARRY:
            m_hitMask |= PROC_HIT_PARRY;
            break;
        case MELEE_HIT_EVADE:
            m_hitMask |= PROC_HIT_EVADE;
            break;
        case MELEE_HIT_BLOCK:
        case MELEE_HIT_CRUSHING:
        case MELEE_HIT_GLANCING:
        case MELEE_HIT_NORMAL:
            if (!damageNullified)
                m_hitMask |= PROC_HIT_NORMAL;
            break;
        case MELEE_HIT_CRIT:
            if (!damageNullified)
                m_hitMask |= PROC_HIT_CRITICAL;
            break;
    }
}

DamageInfo::DamageInfo(SpellNonMeleeDamage const& spellNonMeleeDamage, DamageEffectType damageType, WeaponAttackType attackType, ProcFlagsHit hitMask)
    : m_attacker(spellNonMeleeDamage.attacker), m_victim(spellNonMeleeDamage.target), m_damage(spellNonMeleeDamage.damage), m_originalDamage(spellNonMeleeDamage.originalDamage),
    m_spellInfo(spellNonMeleeDamage.Spell), m_schoolMask(SpellSchoolMask(spellNonMeleeDamage.schoolMask)), m_damageType(damageType),
    m_attackType(attackType), m_absorb(spellNonMeleeDamage.absorb), m_resist(spellNonMeleeDamage.resist), m_block(spellNonMeleeDamage.blocked), m_hitMask(hitMask)
{
    if (spellNonMeleeDamage.blocked)
        m_hitMask |= PROC_HIT_BLOCK;
    if (spellNonMeleeDamage.absorb)
        m_hitMask |= PROC_HIT_ABSORB;
}

void DamageInfo::ModifyDamage(int32 amount)
{
    amount = std::max(amount, -static_cast<int32>(GetDamage()));
    m_damage += amount;
}

void DamageInfo::AbsorbDamage(uint32 amount)
{
    amount = std::min(amount, GetDamage());
    m_absorb += amount;
    m_damage -= amount;
    m_hitMask |= PROC_HIT_ABSORB;
}

void DamageInfo::ResistDamage(uint32 amount)
{
    amount = std::min(amount, GetDamage());
    m_resist += amount;
    m_damage -= amount;
    if (!m_damage)
    {
        m_hitMask |= PROC_HIT_FULL_RESIST;
        m_hitMask &= ~(PROC_HIT_NORMAL | PROC_HIT_CRITICAL);
    }
}

void DamageInfo::BlockDamage(uint32 amount)
{
    amount = std::min(amount, GetDamage());
    m_block += amount;
    m_damage -= amount;
    m_hitMask |= PROC_HIT_BLOCK;
    if (!m_damage)
    {
        m_hitMask |= PROC_HIT_FULL_BLOCK;
        m_hitMask &= ~(PROC_HIT_NORMAL | PROC_HIT_CRITICAL);
    }
}

ProcFlagsHit DamageInfo::GetHitMask() const
{
    return m_hitMask;
}

HealInfo::HealInfo(Unit* healer, Unit* target, uint32 heal, SpellInfo const* spellInfo, SpellSchoolMask schoolMask)
    : _healer(healer), _target(target), _heal(heal), _originalHeal(heal), _effectiveHeal(0), _absorb(0), _spellInfo(spellInfo), _schoolMask(schoolMask), _hitMask(0)
{
}

void HealInfo::AbsorbHeal(uint32 amount)
{
    amount = std::min(amount, GetHeal());
    _absorb += amount;
    _heal -= amount;
    amount = std::min(amount, GetEffectiveHeal());
    _effectiveHeal -= amount;
    _hitMask |= PROC_HIT_ABSORB;
}

uint32 HealInfo::GetHitMask() const
{
    return _hitMask;
}

ProcEventInfo::ProcEventInfo(Unit* actor, Unit* actionTarget, Unit* procTarget,
                             ProcFlagsInit const& typeMask, ProcFlagsSpellType spellTypeMask,
                             ProcFlagsSpellPhase spellPhaseMask, ProcFlagsHit hitMask,
                             Spell* spell, DamageInfo* damageInfo,
                             HealInfo* healInfo) :
    _actor(actor), _actionTarget(actionTarget), _procTarget(procTarget),
    _typeMask(typeMask), _spellTypeMask(spellTypeMask),
    _spellPhaseMask(spellPhaseMask), _hitMask(hitMask), _spell(spell),
    _damageInfo(damageInfo), _healInfo(healInfo)
{ }

SpellInfo const* ProcEventInfo::GetSpellInfo() const
{
    if (_spell)
        return _spell->GetSpellInfo();
    if (_damageInfo)
        return _damageInfo->GetSpellInfo();
    if (_healInfo)
        return _healInfo->GetSpellInfo();
    return nullptr;
}

SpellSchoolMask ProcEventInfo::GetSchoolMask() const
{
    if (_spell)
        return _spell->GetSpellInfo()->GetSchoolMask();
    if (_damageInfo)
        return _damageInfo->GetSchoolMask();
    if (_healInfo)
        return _healInfo->GetSchoolMask();
    return SPELL_SCHOOL_MASK_NONE;
}

SpellNonMeleeDamage::SpellNonMeleeDamage(Unit* _attacker, Unit* _target, SpellInfo const* _spellInfo, SpellCastVisual spellVisual, uint32 _schoolMask, ObjectGuid _castId)
    : target(_target), attacker(_attacker), castId(_castId), Spell(_spellInfo), SpellVisual(spellVisual), damage(0), originalDamage(0),
    schoolMask(_schoolMask), absorb(0), resist(0), periodicLog(false), blocked(0), HitInfo(0), cleanDamage(0), fullBlock(false), preHitHealth(_target->GetHealth())
{
}

Unit::Unit(bool isWorldObject) :
    WorldObject(isWorldObject), m_lastSanctuaryTime(0), LastCharmerGUID(), movespline(std::make_unique<Movement::MoveSpline>()),
    m_ControlledByPlayer(false), m_procDeep(0), m_procChainLength(0), m_transformSpell(0),
    m_removedAurasCount(0), m_interruptMask(SpellAuraInterruptFlags::None), m_interruptMask2(SpellAuraInterruptFlags2::None),
    m_unitMovedByMe(nullptr), m_playerMovingMe(nullptr), m_charmer(nullptr), m_charmed(nullptr),
    i_motionMaster(std::make_unique<MotionMaster>(this)), m_regenTimer(0), m_vehicle(nullptr),
    m_unitTypeMask(UNIT_MASK_NONE), m_Diminishing(), m_combatManager(this),
    m_threatManager(this), m_aiLocked(false), _playHoverAnim(false), _aiAnimKitId(0), _movementAnimKitId(0), _meleeAnimKitId(0),
    _spellHistory(std::make_unique<SpellHistory>(this))
{
    m_objectType |= TYPEMASK_UNIT;
    m_objectTypeId = TYPEID_UNIT;

    m_updateFlag.MovementUpdate = true;

    m_baseAttackSpeed = { };
    m_attackTimer = { };
    m_modAttackSpeedPct.fill(1.0f);

    m_canDualWield = false;

    m_movementCounter = 0;

    m_state = 0;
    m_deathState = ALIVE;

    m_currentSpells = { };

    m_auraUpdateIterator = m_ownedAuras.end();

    m_canModifyStats = false;

    for (uint8 i = 0; i < UNIT_MOD_END; ++i)
    {
        m_auraFlatModifiersGroup[i][BASE_VALUE] = 0.0f;
        m_auraFlatModifiersGroup[i][BASE_PCT_EXCLUDE_CREATE] = 100.0f;
        m_auraFlatModifiersGroup[i][TOTAL_VALUE] = 0.0f;
        m_auraPctModifiersGroup[i][BASE_PCT] = 1.0f;
        m_auraPctModifiersGroup[i][TOTAL_PCT] = 1.0f;
    }
                                                            // implement 50% base damage from offhand
    m_auraPctModifiersGroup[UNIT_MOD_DAMAGE_OFFHAND][TOTAL_PCT] = 0.5f;

    for (uint8 i = 0; i < MAX_ATTACK; ++i)
    {
        m_weaponDamage[i][MINDAMAGE] = BASE_MINDAMAGE;
        m_weaponDamage[i][MAXDAMAGE] = BASE_MAXDAMAGE;
    }

    m_createStats = { };
    m_floatStatPosBuff = { };
    m_floatStatNegBuff = { };

    m_attacking = nullptr;
    m_modMeleeHitChance = 0.0f;
    m_modRangedHitChance = 0.0f;
    m_modSpellHitChance = 0.0f;
    m_baseSpellCritChance = 5.0f;

    m_speed_rate.fill(1.0f);

    // remove aurastates allowing special moves
    m_reactiveTimer = { };

    m_cleanupDone = false;
    m_duringRemoveFromWorld = false;

    m_serverSideVisibility.SetValue(SERVERSIDE_VISIBILITY_GHOST, GHOST_VISIBILITY_ALIVE);

    _lastLiquid = nullptr;

    _oldFactionId = 0;
    _isWalkingBeforeCharm = false;
    _instantCast = false;
    _isCombatDisallowed = false;

    _lastExtraAttackSpell = 0;
}

////////////////////////////////////////////////////////////
// Methods of class Unit
Unit::~Unit()
{
    // set current spells as deletable
    for (size_t i = 0; i < m_currentSpells.size(); ++i)
    {
        if (m_currentSpells[i])
        {
            m_currentSpells[i]->SetReferencedFromCurrent(false);
            m_currentSpells[i] = nullptr;
        }
    }

    m_Events.KillAllEvents(true);

    _DeleteRemovedAuras();

    ASSERT(!m_duringRemoveFromWorld);
    ASSERT(!m_attacking);
    ASSERT(m_attackers.empty());
    ASSERT(m_sharedVision.empty());
    ASSERT(m_Controlled.empty());
    ASSERT(m_appliedAuras.empty());
    ASSERT(m_ownedAuras.empty());
    ASSERT(m_removedAuras.empty());
    ASSERT(m_dynObj.empty());
    ASSERT(m_gameObj.empty());
    ASSERT(m_areaTrigger.empty());
    ASSERT(!m_unitMovedByMe || (m_unitMovedByMe == this));
    ASSERT(!m_playerMovingMe || (m_playerMovingMe == this));
}

void Unit::Update(uint32 p_time)
{
    // WARNING! Order of execution here is important, do not change.
    // Spells must be processed with event system BEFORE they go to _UpdateSpells.
    // Or else we may have some SPELL_STATE_FINISHED spells stalled in pointers, that is bad.
    WorldObject::Update(p_time);

    if (!IsInWorld())
        return;

    _UpdateSpells(p_time);

    // If this is set during update SetCantProc(false) call is missing somewhere in the code
    // Having this would prevent spells from being proced, so let's crash
    ASSERT(!m_procDeep);

    m_combatManager.Update(p_time);

    _lastDamagedTargetGuid = ObjectGuid::Empty;
    if (_lastExtraAttackSpell)
    {
        while (!extraAttacksTargets.empty())
        {
            auto itr = extraAttacksTargets.begin();
            ObjectGuid targetGuid = itr->first;
            uint32 count = itr->second;
            extraAttacksTargets.erase(itr);
            if (Unit* victim = ObjectAccessor::GetUnit(*this, targetGuid))
                HandleProcExtraAttackFor(victim, count);
        }
        _lastExtraAttackSpell = 0;
    }

    auto spellPausesCombatTimer = [&](CurrentSpellTypes type)
    {
        return GetCurrentSpell(type) && GetCurrentSpell(type)->GetSpellInfo()->HasAttribute(SPELL_ATTR6_DELAY_COMBAT_TIMER_DURING_CAST);
    };

    if (!spellPausesCombatTimer(CURRENT_GENERIC_SPELL) && !spellPausesCombatTimer(CURRENT_CHANNELED_SPELL))
    {
        if (uint32 base_att = getAttackTimer(BASE_ATTACK))
            setAttackTimer(BASE_ATTACK, (p_time >= base_att ? 0 : base_att - p_time));
        if (uint32 off_att = getAttackTimer(OFF_ATTACK))
            setAttackTimer(OFF_ATTACK, (p_time >= off_att ? 0 : off_att - p_time));
        if (uint32 ranged_att = getAttackTimer(RANGED_ATTACK))
            setAttackTimer(RANGED_ATTACK, (p_time >= ranged_att ? 0 : ranged_att - p_time));
    }

    // update abilities available only for fraction of time
    UpdateReactives(p_time);

    if (IsAlive())
    {
        ModifyAuraState(AURA_STATE_WOUNDED_20_PERCENT, HealthBelowPct(20));
        ModifyAuraState(AURA_STATE_WOUNDED_25_PERCENT, HealthBelowPct(25));
        ModifyAuraState(AURA_STATE_WOUNDED_35_PERCENT, HealthBelowPct(35));
        ModifyAuraState(AURA_STATE_WOUND_HEALTH_20_80, HealthBelowPct(20) || HealthAbovePct(80));
        ModifyAuraState(AURA_STATE_HEALTHY_75_PERCENT, HealthAbovePct(75));
        ModifyAuraState(AURA_STATE_WOUND_HEALTH_35_80, HealthBelowPct(35) || HealthAbovePct(80));
    }

    UpdateSplineMovement(p_time);
    i_motionMaster->Update(p_time);

    // Wait with the aura interrupts until we have updated our movement generators and position
    if (GetTypeId() == TYPEID_PLAYER)
        InterruptMovementBasedAuras();
    else if (!movespline->Finalized())
        InterruptMovementBasedAuras();

    // All position info based actions have been executed, reset info
    _positionUpdateInfo.Reset();

    if (HasScheduledAIChange() && (GetTypeId() != TYPEID_PLAYER || (IsCharmed() && GetCharmerGUID().IsCreature())))
        UpdateCharmAI();
    RefreshAI();
}

bool Unit::haveOffhandWeapon() const
{
    if (Player const* player = ToPlayer())
        return player->GetWeaponForAttack(OFF_ATTACK, true) != nullptr;

    return CanDualWield();
}

void Unit::MonsterMoveWithSpeed(float x, float y, float z, float speed, bool generatePath, bool forceDestination)
{
    std::function<void(Movement::MoveSplineInit&)> initializer = [=](Movement::MoveSplineInit& init)
    {
        init.MoveTo(x, y, z, generatePath, forceDestination);
        init.SetVelocity(speed);
    };
    GetMotionMaster()->LaunchMoveSpline(std::move(initializer), 0, MOTION_PRIORITY_NORMAL, POINT_MOTION_TYPE);
}

void Unit::AtStartOfEncounter(EncounterType type)
{
    RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags2::StartOfEncounter);

    switch (type)
    {
        case EncounterType::DungeonEncounter:
            RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags2::StartOfDungeonEncounter);
            break;
        case EncounterType::MythicPlusRun:
            RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags2::StartOfMythicPlusRun);
            break;
        default:
            break;
    }

    if (IsAlive())
        Unit::ProcSkillsAndAuras(this, nullptr, PROC_FLAG_ENCOUNTER_START, PROC_FLAG_NONE, PROC_SPELL_TYPE_MASK_ALL, PROC_SPELL_PHASE_NONE, PROC_HIT_NONE, nullptr, nullptr, nullptr);
}

void Unit::AtEndOfEncounter(EncounterType type)
{
    RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags2::EndOfEncounter);

    switch (type)
    {
        case EncounterType::DungeonEncounter:
            RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags2::EndOfDungeonEncounter);
            break;
        default:
            break;
    }

    GetSpellHistory()->ResetCooldowns([](SpellHistory::CooldownStorageType::iterator itr)
    {
        SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(itr->first, DIFFICULTY_NONE);

        return spellInfo->HasAttribute(SPELL_ATTR10_RESET_COOLDOWN_ON_ENCOUNTER_END);
    }, true);
}

void Unit::UpdateSplineMovement(uint32 t_diff)
{
    if (movespline->Finalized())
        return;

    movespline->updateState(t_diff);
    bool arrived = movespline->Finalized();

    if (movespline->isCyclic())
    {
        m_splineSyncTimer.Update(t_diff);
        if (m_splineSyncTimer.Passed())
        {
            m_splineSyncTimer.Reset(5000); // Retail value, do not change

            WorldPackets::Movement::FlightSplineSync flightSplineSync;
            flightSplineSync.Guid = GetGUID();
            flightSplineSync.SplineDist = movespline->timePassed() / movespline->Duration();
            SendMessageToSet(flightSplineSync.Write(), true);
        }
    }

    if (arrived)
    {
        DisableSpline();

        if (Optional<AnimTier> animTier = movespline->GetAnimation())
            SetAnimTier(*animTier);
    }

    UpdateSplinePosition();
}

void Unit::UpdateSplinePosition()
{
    Movement::Location loc = movespline->ComputePosition();

    if (movespline->onTransport)
    {
        Position& pos = m_movementInfo.transport.pos;
        pos.m_positionX = loc.x;
        pos.m_positionY = loc.y;
        pos.m_positionZ = loc.z;
        pos.SetOrientation(loc.orientation);

        if (TransportBase* transport = GetDirectTransport())
            transport->CalculatePassengerPosition(loc.x, loc.y, loc.z, &loc.orientation);
        else
            return;
    }

    if (HasUnitState(UNIT_STATE_LOST_CONTROL | UNIT_STATE_FOCUSING))
        loc.orientation = GetOrientation();

    UpdatePosition(loc.x, loc.y, loc.z, loc.orientation);
}

void Unit::InterruptMovementBasedAuras()
{
    // TODO: Check if orientation transport offset changed instead of only global orientation
    if (_positionUpdateInfo.Turned)
        RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::Turning);

    if (_positionUpdateInfo.Relocated && !GetVehicle())
        RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::Moving);
}

void Unit::DisableSpline()
{
    m_movementInfo.RemoveMovementFlag(MOVEMENTFLAG_FORWARD);
    movespline->_Interrupt();
}

void Unit::resetAttackTimer(WeaponAttackType type)
{
    m_attackTimer[type] = uint32(GetBaseAttackTime(type) * m_modAttackSpeedPct[type]);
}

bool Unit::IsWithinCombatRange(Unit const* obj, float dist2compare) const
{
    if (!obj || !IsInMap(obj) || !InSamePhase(obj))
        return false;

    float dx = GetPositionX() - obj->GetPositionX();
    float dy = GetPositionY() - obj->GetPositionY();
    float dz = GetPositionZ() - obj->GetPositionZ();
    float distsq = dx * dx + dy * dy + dz * dz;

    float sizefactor = GetCombatReach() + obj->GetCombatReach();
    float maxdist = dist2compare + sizefactor;

    return distsq < maxdist * maxdist;
}

bool Unit::IsWithinMeleeRangeAt(Position const& pos, Unit const* obj) const
{
    if (!obj || !IsInMap(obj) || !InSamePhase(obj))
        return false;

    float dx = pos.GetPositionX() - obj->GetPositionX();
    float dy = pos.GetPositionY() - obj->GetPositionY();
    float dz = pos.GetPositionZ() - obj->GetPositionZ();
    float distsq = dx*dx + dy*dy + dz*dz;

    float maxdist = GetMeleeRange(obj) + GetTotalAuraModifier(SPELL_AURA_MOD_AUTOATTACK_RANGE);

    return distsq <= maxdist * maxdist;
}

float Unit::GetMeleeRange(Unit const* target) const
{
    float range = GetCombatReach() + target->GetCombatReach() + 4.0f / 3.0f;
    return std::max(range, NOMINAL_MELEE_RANGE);
}

bool Unit::IsWithinBoundaryRadius(const Unit* obj) const
{
    if (!obj || !IsInMap(obj) || !InSamePhase(obj))
        return false;

    float objBoundaryRadius = std::max(obj->GetBoundingRadius(), MIN_MELEE_REACH);

    return IsInDist(obj, objBoundaryRadius);
}

void Unit::SetVisibleAura(AuraApplication* aurApp)
{
    m_visibleAuras.insert(aurApp);
    m_visibleAurasToUpdate.insert(aurApp);
    UpdateAuraForGroup();
}

void Unit::RemoveVisibleAura(AuraApplication* aurApp)
{
    m_visibleAuras.erase(aurApp);
    m_visibleAurasToUpdate.erase(aurApp);
    UpdateAuraForGroup();
}

void Unit::UpdateInterruptMask()
{
    m_interruptMask = SpellAuraInterruptFlags::None;
    m_interruptMask2 = SpellAuraInterruptFlags2::None;
    for (AuraApplication const* aurApp : m_interruptableAuras)
    {
        m_interruptMask |= aurApp->GetBase()->GetSpellInfo()->AuraInterruptFlags;
        m_interruptMask2 |= aurApp->GetBase()->GetSpellInfo()->AuraInterruptFlags2;
    }

    if (Spell* spell = m_currentSpells[CURRENT_CHANNELED_SPELL])
    {
        if (spell->getState() == SPELL_STATE_CASTING)
        {
            m_interruptMask |= spell->m_spellInfo->ChannelInterruptFlags;
            m_interruptMask2 |= spell->m_spellInfo->ChannelInterruptFlags2;
        }
    }
}

bool Unit::HasAuraTypeWithFamilyFlags(AuraType auraType, uint32 familyName, flag128 familyFlags) const
{
    for (AuraEffect const* aura : GetAuraEffectsByType(auraType))
        if (aura->GetSpellInfo()->SpellFamilyName == familyName && aura->GetSpellInfo()->SpellFamilyFlags & familyFlags)
            return true;
    return false;
}

bool Unit::HasBreakableByDamageAuraType(AuraType type, uint32 excludeAura) const
{
    AuraEffectList const& auras = GetAuraEffectsByType(type);
    for (AuraEffectList::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
        if ((!excludeAura || excludeAura != (*itr)->GetSpellInfo()->Id) && //Avoid self interrupt of channeled Crowd Control spells like Seduction
            (*itr)->GetSpellInfo()->HasAuraInterruptFlag(SpellAuraInterruptFlags::Damage))
            return true;
    return false;
}

bool Unit::HasBreakableByDamageCrowdControlAura(Unit* excludeCasterChannel) const
{
    uint32 excludeAura = 0;
    if (Spell* currentChanneledSpell = excludeCasterChannel ? excludeCasterChannel->GetCurrentSpell(CURRENT_CHANNELED_SPELL) : nullptr)
        excludeAura = currentChanneledSpell->GetSpellInfo()->Id; //Avoid self interrupt of channeled Crowd Control spells like Seduction

    return (   HasBreakableByDamageAuraType(SPELL_AURA_MOD_CONFUSE, excludeAura)
            || HasBreakableByDamageAuraType(SPELL_AURA_MOD_FEAR, excludeAura)
            || HasBreakableByDamageAuraType(SPELL_AURA_MOD_STUN, excludeAura)
            || HasBreakableByDamageAuraType(SPELL_AURA_MOD_ROOT, excludeAura)
            || HasBreakableByDamageAuraType(SPELL_AURA_MOD_ROOT_2, excludeAura)
            || HasBreakableByDamageAuraType(SPELL_AURA_TRANSFORM, excludeAura));
}

/*static*/ void Unit::DealDamageMods(Unit const* attacker, Unit const* victim, uint32& damage, uint32* absorb)
{
    if (!victim || !victim->IsAlive() || victim->HasUnitState(UNIT_STATE_IN_FLIGHT) || (victim->GetTypeId() == TYPEID_UNIT && victim->ToCreature()->IsEvadingAttacks()))
    {
        if (absorb)
            *absorb += damage;
        damage = 0;
        return;
    }

    if (attacker)
        damage *= attacker->GetDamageMultiplierForTarget(victim);
}

/*static*/ AuraEffectVector Unit::CopyAuraEffectList(Unit::AuraEffectList const& list)
{
    AuraEffectVector effects;
    std::copy(list.begin(), list.end(), std::back_inserter(effects));
    return effects;
}

/*static*/ uint32 Unit::DealDamage(Unit* attacker, Unit* victim, uint32 damage, CleanDamage const* cleanDamage, DamageEffectType damagetype, SpellSchoolMask damageSchoolMask, SpellInfo const* spellProto, bool durabilityLoss)
{
    uint32 damageDone = damage;
    uint32 damageTaken = damage;
    if (attacker)
        damageTaken = damage / victim->GetHealthMultiplierForTarget(attacker);

    // call script hooks
    {
        uint32 tmpDamage = damageTaken;

        // sparring
        if (Creature* victimCreature = victim->ToCreature())
            tmpDamage = victimCreature->CalculateDamageForSparring(attacker, tmpDamage);

        if (UnitAI* victimAI = victim->GetAI())
            victimAI->DamageTaken(attacker, tmpDamage, damagetype, spellProto);

        if (UnitAI* attackerAI = attacker ? attacker->GetAI() : nullptr)
            attackerAI->DamageDealt(victim, tmpDamage, damagetype);

        // Hook for OnDamage Event
        sScriptMgr->OnDamage(attacker, victim, tmpDamage);

        // if any script modified damage, we need to also apply the same modification to unscaled damage value
        if (tmpDamage != damageTaken)
        {
            if (attacker)
                damageDone = tmpDamage * victim->GetHealthMultiplierForTarget(attacker);
            else
                damageDone = tmpDamage;

            damageTaken = tmpDamage;
        }
    }

    // Signal to pets that their owner was attacked - except when DOT.
    if (attacker != victim && damagetype != DOT)
    {
        for (Unit* controlled : victim->m_Controlled)
            if (Creature* cControlled = controlled->ToCreature())
                if (CreatureAI* controlledAI = cControlled->AI())
                    controlledAI->OwnerAttackedBy(attacker);
    }

    if (Player* player = victim->ToPlayer())
        if (player->GetCommandStatus(CHEAT_GOD))
            return 0;

    if (damagetype != NODAMAGE)
    {
        // interrupting auras with SpellAuraInterruptFlags::Damage before checking !damage (absorbed damage breaks that type of auras)
        if (spellProto)
        {
            if (!spellProto->HasAttribute(SPELL_ATTR4_REACTIVE_DAMAGE_PROC))
                victim->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::Damage, spellProto);
        }
        else
            victim->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::Damage);

        if (!damageTaken && damagetype != DOT && cleanDamage && cleanDamage->absorbed_damage)
            if (victim != attacker && victim->GetTypeId() == TYPEID_PLAYER)
                if (Spell* spell = victim->m_currentSpells[CURRENT_GENERIC_SPELL])
                    if (spell->getState() == SPELL_STATE_PREPARING && spell->m_spellInfo->InterruptFlags.HasFlag(SpellInterruptFlags::DamageAbsorb))
                           victim->InterruptNonMeleeSpells(false);

        // We're going to call functions which can modify content of the list during iteration over it's elements
        // Let's copy the list so we can prevent iterator invalidation
        AuraEffectVector vCopyDamageCopy = CopyAuraEffectList(victim->GetAuraEffectsByType(SPELL_AURA_SHARE_DAMAGE_PCT));
        // copy damage to casters of this aura
        for (auto i = vCopyDamageCopy.begin(); i != vCopyDamageCopy.end(); ++i)
        {
            // Check if aura was removed during iteration - we don't need to work on such auras
            if (!((*i)->GetBase()->IsAppliedOnTarget(victim->GetGUID())))
                continue;
            // check damage school mask
            if (((*i)->GetMiscValue() & damageSchoolMask) == 0)
                continue;

            Unit* shareDamageTarget = (*i)->GetCaster();
            if (!shareDamageTarget)
                continue;
            SpellInfo const* spell = (*i)->GetSpellInfo();

            uint32 share = CalculatePct(damageDone, (*i)->GetAmount());

            /// @todo check packets if damage is done by victim, or by attacker of victim
            Unit::DealDamageMods(attacker, shareDamageTarget, share, nullptr);
            Unit::DealDamage(attacker, shareDamageTarget, share, nullptr, NODAMAGE, spell->GetSchoolMask(), spell, false);
        }
    }

    // Rage from Damage made (only from direct weapon damage)
    if (attacker && cleanDamage && (cleanDamage->attackType == BASE_ATTACK || cleanDamage->attackType == OFF_ATTACK) && damagetype == DIRECT_DAMAGE && attacker != victim && attacker->GetPowerType() == POWER_RAGE)
    {
        uint32 rage = uint32(attacker->GetBaseAttackTime(cleanDamage->attackType) / 1000.f * 1.75f);
        if (cleanDamage->attackType == OFF_ATTACK)
            rage /= 2;
        attacker->RewardRage(rage);
    }

    if (!damageDone)
        return 0;

    uint32 health = victim->GetHealth();

    // duel ends when player has 1 or less hp
    bool duel_hasEnded = false;
    bool duel_wasMounted = false;
    if (victim->GetTypeId() == TYPEID_PLAYER && victim->ToPlayer()->duel && damageTaken >= (health-1))
    {
        if (!attacker)
            return 0;

        // prevent kill only if killed in duel and killed by opponent or opponent controlled creature
        if (victim->ToPlayer()->duel->Opponent == attacker->GetControllingPlayer())
            damageTaken = health - 1;

        duel_hasEnded = true;
    }
    else if (victim->IsCreature() && victim != attacker && damageTaken >= health && victim->ToCreature()->HasFlag(CREATURE_STATIC_FLAG_UNKILLABLE))
    {
        damageTaken = health - 1;

        // If we had damage (aka health was not 1 already) trigger OnHealthDepleted
        if (damageTaken > 0)
        {
            if (CreatureAI* victimAI = victim->ToCreature()->AI())
                victimAI->OnHealthDepleted(attacker, false);
        }
    }
    else if (victim->IsVehicle() && damageTaken >= (health-1) && victim->GetCharmer() && victim->GetCharmer()->GetTypeId() == TYPEID_PLAYER)
    {
        Player* victimRider = victim->GetCharmer()->ToPlayer();

        if (victimRider && victimRider->duel && victimRider->duel->IsMounted)
        {
            if (!attacker)
                return 0;

            // prevent kill only if killed in duel and killed by opponent or opponent controlled creature
            if (victimRider->duel->Opponent == attacker->GetControllingPlayer())
                damageTaken = health - 1;

            duel_wasMounted = true;
            duel_hasEnded = true;
        }
    }

    if (attacker && attacker != victim)
    {
        if (Player* killer = attacker->ToPlayer())
        {
            // in bg, count dmg if victim is also a player
            if (victim->GetTypeId() == TYPEID_PLAYER && !(spellProto && spellProto->HasAttribute(SPELL_ATTR7_DO_NOT_COUNT_FOR_PVP_SCOREBOARD)))
                if (Battleground* bg = killer->GetBattleground())
                    bg->UpdatePlayerScore(killer, SCORE_DAMAGE_DONE, damageDone);

            killer->UpdateCriteria(CriteriaType::DamageDealt, health > damageDone ? damageDone : health, 0, 0, victim);
            killer->UpdateCriteria(CriteriaType::HighestDamageDone, damageDone);
        }
    }

    if (victim->GetTypeId() == TYPEID_PLAYER)
        victim->ToPlayer()->UpdateCriteria(CriteriaType::HighestDamageTaken, damageTaken);

    if (victim->GetTypeId() != TYPEID_PLAYER && (!victim->IsControlledByPlayer() || victim->IsVehicle()))
    {
        victim->ToCreature()->SetTappedBy(attacker);

        if (!attacker || attacker->IsControlledByPlayer())
            victim->ToCreature()->LowerPlayerDamageReq(health < damageTaken ?  health : damageTaken);
    }

    bool killed = false;
    bool skipSettingDeathState = false;

    if (health <= damageTaken)
    {
        killed = true;

        if (victim->GetTypeId() == TYPEID_PLAYER && victim != attacker)
            victim->ToPlayer()->UpdateCriteria(CriteriaType::TotalDamageTaken, health);

        if (damagetype != NODAMAGE && damagetype != SELF_DAMAGE && victim->HasAuraType(SPELL_AURA_SCHOOL_ABSORB_OVERKILL))
        {
            AuraEffectVector vAbsorbOverkill = CopyAuraEffectList(victim->GetAuraEffectsByType(SPELL_AURA_SCHOOL_ABSORB_OVERKILL));
            DamageInfo damageInfo = DamageInfo(attacker, victim, damageTaken, spellProto, damageSchoolMask, damagetype,
                cleanDamage ? cleanDamage->attackType : BASE_ATTACK);
            for (AuraEffect* absorbAurEff : vAbsorbOverkill)
            {
                Aura* base = absorbAurEff->GetBase();
                AuraApplication const* aurApp = base->GetApplicationOfTarget(victim->GetGUID());
                if (!aurApp)
                    continue;

                if (!(absorbAurEff->GetMiscValue() & damageInfo.GetSchoolMask()))
                    continue;

                // cannot absorb over limit
                if (damageTaken >= victim->CountPctFromMaxHealth(100 + absorbAurEff->GetMiscValueB()))
                    continue;

                // absorb all damage by default
                uint32 currentAbsorb = damageInfo.GetDamage();

                // This aura type is used both by Spirit of Redemption (death not really prevented, must grant all credit immediately) and Cheat Death (death prevented)
                // repurpose PreventDefaultAction for this
                bool deathFullyPrevented = false;

                absorbAurEff->GetBase()->CallScriptEffectAbsorbHandlers(absorbAurEff, aurApp, damageInfo, currentAbsorb, deathFullyPrevented);

                // absorb must be smaller than the damage itself
                currentAbsorb = std::min(currentAbsorb, damageInfo.GetDamage());

                // if nothing is absorbed (for example because of a scripted cooldown) then skip this aura and proceed with dying
                if (!currentAbsorb)
                    continue;

                damageInfo.AbsorbDamage(currentAbsorb);

                if (deathFullyPrevented)
                    killed = false;

                skipSettingDeathState = true;

                if (currentAbsorb)
                {
                    WorldPackets::CombatLog::SpellAbsorbLog absorbLog;
                    absorbLog.Attacker = attacker ? attacker->GetGUID() : ObjectGuid::Empty;
                    absorbLog.Victim = victim->GetGUID();
                    absorbLog.Caster = base->GetCasterGUID();
                    absorbLog.AbsorbedSpellID = spellProto ? spellProto->Id : 0;
                    absorbLog.AbsorbSpellID = base->GetId();
                    absorbLog.Absorbed = currentAbsorb;
                    absorbLog.OriginalDamage = damageInfo.GetOriginalDamage();
                    absorbLog.LogData.Initialize(victim);
                    victim->SendCombatLogMessage(&absorbLog);
                }
            }

            damageTaken = damageInfo.GetDamage();
        }
    }

    if (spellProto && spellProto->HasAttribute(SPELL_ATTR3_NO_DURABILITY_LOSS))
        durabilityLoss = false;

    if (killed)
        Unit::Kill(attacker, victim, durabilityLoss, skipSettingDeathState);
    else
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            victim->ToPlayer()->UpdateCriteria(CriteriaType::TotalDamageTaken, damageTaken);

        victim->ModifyHealth(-(int32)damageTaken);

        if (damagetype == DIRECT_DAMAGE || damagetype == SPELL_DIRECT_DAMAGE)
            victim->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::NonPeriodicDamage, spellProto);

        if (victim->GetTypeId() != TYPEID_PLAYER)
        {
            // Part of Evade mechanics. DoT's and Thorns / Retribution Aura do not contribute to this
            if (damagetype != DOT && damageTaken > 0 && !victim->GetOwnerGUID().IsPlayer() && (!spellProto || !spellProto->HasAura(SPELL_AURA_DAMAGE_SHIELD)))
                victim->ToCreature()->SetLastDamagedTime(GameTime::GetGameTime() + MAX_AGGRO_RESET_TIME);

            if (attacker && (!spellProto || !spellProto->HasAttribute(SPELL_ATTR4_NO_HARMFUL_THREAT)))
                victim->GetThreatManager().AddThreat(attacker, float(damageTaken), spellProto);
        }
        else                                                // victim is a player
        {
            // random durability for items (HIT TAKEN)
            if (durabilityLoss && roll_chance_f(sWorld->getRate(RATE_DURABILITY_LOSS_DAMAGE)))
            {
                EquipmentSlots slot = EquipmentSlots(urand(0, EQUIPMENT_SLOT_END-1));
                victim->ToPlayer()->DurabilityPointLossForEquipSlot(slot);
            }
        }

        if (attacker && attacker->GetTypeId() == TYPEID_PLAYER)
        {
            // random durability for items (HIT DONE)
            if (durabilityLoss && roll_chance_f(sWorld->getRate(RATE_DURABILITY_LOSS_DAMAGE)))
            {
                EquipmentSlots slot = EquipmentSlots(urand(0, EQUIPMENT_SLOT_END-1));
                attacker->ToPlayer()->DurabilityPointLossForEquipSlot(slot);
            }
        }

        if (damagetype != NODAMAGE && damagetype != DOT)
        {
            if (victim != attacker && (!spellProto || !(spellProto->HasAttribute(SPELL_ATTR6_NO_PUSHBACK) || spellProto->HasAttribute(SPELL_ATTR7_DONT_CAUSE_SPELL_PUSHBACK) || spellProto->HasAttribute(SPELL_ATTR3_TREAT_AS_PERIODIC))))
            {
                if (Spell* spell = victim->m_currentSpells[CURRENT_GENERIC_SPELL])
                {
                    if (spell->getState() == SPELL_STATE_PREPARING)
                    {
                        auto isCastInterrupted = [&]()
                        {
                            if (!damageTaken)
                                return spell->m_spellInfo->InterruptFlags.HasFlag(SpellInterruptFlags::ZeroDamageCancels);

                            if ((victim->IsPlayer() && spell->m_spellInfo->InterruptFlags.HasFlag(SpellInterruptFlags::DamageCancelsPlayerOnly)))
                                return true;

                            if (spell->m_spellInfo->InterruptFlags.HasFlag(SpellInterruptFlags::DamageCancels))
                                return true;

                            return false;
                        };

                        auto isCastDelayed = [&]()
                        {
                            if (!damageTaken)
                                return false;

                            if ((victim->IsPlayer() && spell->m_spellInfo->InterruptFlags.HasFlag(SpellInterruptFlags::DamagePushbackPlayerOnly)))
                                return true;

                            if (spell->m_spellInfo->InterruptFlags.HasFlag(SpellInterruptFlags::DamagePushback))
                                return true;

                            return false;
                        };

                        if (isCastInterrupted())
                            victim->InterruptNonMeleeSpells(false);
                        else if (isCastDelayed())
                            spell->Delayed();
                    }
                }

                if (damageTaken && victim->IsPlayer())
                    if (Spell* spell = victim->m_currentSpells[CURRENT_CHANNELED_SPELL])
                        if (spell->getState() == SPELL_STATE_CASTING && spell->m_spellInfo->HasChannelInterruptFlag(SpellAuraInterruptFlags::DamageChannelDuration))
                            spell->DelayedChannel();
            }
        }

        // last damage from duel opponent
        if (duel_hasEnded)
        {
            Player* he = duel_wasMounted ? victim->GetCharmer()->ToPlayer() : victim->ToPlayer();

            ASSERT_NODEBUGINFO(he && he->duel);

            if (duel_wasMounted) // In this case victim == mount
                victim->SetHealth(1);
            else
                he->SetHealth(1);

            he->duel->Opponent->CombatStopWithPets(true);
            he->CombatStopWithPets(true);

            he->CastSpell(he, 7267, true);                  // beg
            he->DuelComplete(DUEL_WON);
        }
    }

    // make player victims stand up automatically
    if (victim->GetStandState() && victim->IsPlayer())
        victim->SetStandState(UNIT_STAND_STATE_STAND);

    return damageTaken;
}

void Unit::CastStop(uint32 except_spellid)
{
    for (uint32 i = CURRENT_FIRST_NON_MELEE_SPELL; i < CURRENT_MAX_SPELL; i++)
        if (m_currentSpells[i] && m_currentSpells[i]->m_spellInfo->Id != except_spellid)
            InterruptSpell(CurrentSpellTypes(i), false);
}

void Unit::CalculateSpellDamageTaken(SpellNonMeleeDamage* damageInfo, int32 damage, SpellInfo const* spellInfo, WeaponAttackType attackType, bool crit /*= false*/, bool blocked /*= false*/, Spell* spell /*= nullptr*/)
{
    if (damage < 0)
        return;

    Unit* victim = damageInfo->target;
    if (!victim || !victim->IsAlive())
        return;

    SpellSchoolMask damageSchoolMask = SpellSchoolMask(damageInfo->schoolMask);

    // Spells with SPELL_ATTR4_IGNORE_DAMAGE_TAKEN_MODIFIERS ignore resilience because their damage is based off another spell's damage.
    if (!spellInfo->HasAttribute(SPELL_ATTR4_IGNORE_DAMAGE_TAKEN_MODIFIERS))
    {
        if (Unit::IsDamageReducedByArmor(damageSchoolMask, spellInfo))
            damage = Unit::CalcArmorReducedDamage(damageInfo->attacker, victim, damage, spellInfo, attackType);

        // Per-school calc
        switch (spellInfo->DmgClass)
        {
            // Melee and Ranged Spells
            case SPELL_DAMAGE_CLASS_RANGED:
            case SPELL_DAMAGE_CLASS_MELEE:
            {
                if (crit)
                {
                    damageInfo->HitInfo |= SPELL_HIT_TYPE_CRIT;

                    // Calculate crit bonus
                    uint32 crit_bonus = damage;
                    // Apply crit_damage bonus for melee spells
                    if (Player* modOwner = GetSpellModOwner())
                        modOwner->ApplySpellMod(spellInfo, SpellModOp::CritDamageAndHealing, crit_bonus);
                    damage += crit_bonus;

                    // Increase crit damage from SPELL_AURA_MOD_CRIT_DAMAGE_BONUS
                    float critPctDamageMod = (GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_CRIT_DAMAGE_BONUS, spellInfo->GetSchoolMask()) - 1.0f) * 100;

                    if (critPctDamageMod != 0)
                        AddPct(damage, critPctDamageMod);
                }

                // Spell weapon based damage CAN BE crit & blocked at same time
                if (blocked)
                {
                    // double blocked amount if block is critical
                    uint32 value = victim->GetBlockPercent(GetLevel());
                    if (victim->IsBlockCritical())
                        value *= 2; // double blocked percent
                    damageInfo->blocked = CalculatePct(damage, value);
                    if (damage <= int32(damageInfo->blocked))
                    {
                        damageInfo->blocked = uint32(damage);
                        damageInfo->fullBlock = true;
                    }
                    damage -= damageInfo->blocked;
                }

                if (CanApplyResilience())
                    Unit::ApplyResilience(victim, &damage);
                break;
            }
            // Magical Attacks
            case SPELL_DAMAGE_CLASS_NONE:
            case SPELL_DAMAGE_CLASS_MAGIC:
            {
                // If crit add critical bonus
                if (crit)
                {
                    damageInfo->HitInfo |= SPELL_HIT_TYPE_CRIT;
                    damage = Unit::SpellCriticalDamageBonus(this, spellInfo, damage, victim);
                }

                if (CanApplyResilience())
                    Unit::ApplyResilience(victim, &damage);
                break;

            }
            default:
                break;
        }
    }

    // Script Hook For CalculateSpellDamageTaken -- Allow scripts to change the Damage post class mitigation calculations
    sScriptMgr->ModifySpellDamageTaken(damageInfo->target, damageInfo->attacker, damage, spellInfo);

    // Calculate absorb resist
    if (damage < 0)
        damage = 0;

    damageInfo->damage = damage;
    damageInfo->originalDamage = damage;
    DamageInfo dmgInfo(*damageInfo, SPELL_DIRECT_DAMAGE, BASE_ATTACK, PROC_HIT_NONE);
    Unit::CalcAbsorbResist(dmgInfo, spell);
    damageInfo->absorb = dmgInfo.GetAbsorb();
    damageInfo->resist = dmgInfo.GetResist();

    if (damageInfo->absorb)
        damageInfo->HitInfo |= (damageInfo->damage - damageInfo->absorb == 0 ? HITINFO_FULL_ABSORB : HITINFO_PARTIAL_ABSORB);

    if (damageInfo->resist)
        damageInfo->HitInfo |= (damageInfo->damage - damageInfo->resist == 0 ? HITINFO_FULL_RESIST : HITINFO_PARTIAL_RESIST);

    damageInfo->damage = dmgInfo.GetDamage();
}

void Unit::DealSpellDamage(SpellNonMeleeDamage const* damageInfo, bool durabilityLoss)
{
    if (!damageInfo)
        return;

    Unit* victim = damageInfo->target;
    if (!victim)
        return;

    if (!victim->IsAlive() || victim->HasUnitState(UNIT_STATE_IN_FLIGHT) || (victim->GetTypeId() == TYPEID_UNIT && victim->ToCreature()->IsEvadingAttacks()))
        return;

    if (!damageInfo->Spell)
    {
        TC_LOG_DEBUG("entities.unit", "Unit::DealSpellDamage has no spell");
        return;
    }

    // Call default DealDamage
    CleanDamage cleanDamage(damageInfo->cleanDamage, damageInfo->absorb, BASE_ATTACK, MELEE_HIT_NORMAL);
    Unit::DealDamage(this, victim, damageInfo->damage, &cleanDamage, SPELL_DIRECT_DAMAGE, SpellSchoolMask(damageInfo->schoolMask), damageInfo->Spell, durabilityLoss);
}

/// @todo for melee need create structure as in
void Unit::CalculateMeleeDamage(Unit* victim, CalcDamageInfo* damageInfo, WeaponAttackType attackType /*= BASE_ATTACK*/)
{
    damageInfo->Attacker         = this;
    damageInfo->Target           = victim;

    damageInfo->DamageSchoolMask = GetMeleeDamageSchoolMask(attackType);
    damageInfo->Damage           = 0;
    damageInfo->OriginalDamage   = 0;
    damageInfo->Absorb           = 0;
    damageInfo->Resist           = 0;

    damageInfo->Blocked          = 0;
    damageInfo->HitInfo          = 0;
    damageInfo->TargetState      = 0;

    damageInfo->AttackType       = attackType;
    damageInfo->ProcAttacker     = PROC_FLAG_NONE;
    damageInfo->ProcVictim       = PROC_FLAG_NONE;
    damageInfo->CleanDamage      = 0;
    damageInfo->HitOutCome       = MELEE_HIT_EVADE;

    if (!victim)
        return;

    if (!IsAlive() || !victim->IsAlive())
        return;

    // Select HitInfo/procAttacker/procVictim flag based on attack type
    switch (attackType)
    {
        case BASE_ATTACK:
            damageInfo->ProcAttacker = PROC_FLAG_DEAL_MELEE_SWING | PROC_FLAG_MAIN_HAND_WEAPON_SWING;
            damageInfo->ProcVictim   = PROC_FLAG_TAKE_MELEE_SWING;
            break;
        case OFF_ATTACK:
            damageInfo->ProcAttacker = PROC_FLAG_DEAL_MELEE_SWING | PROC_FLAG_OFF_HAND_WEAPON_SWING;
            damageInfo->ProcVictim   = PROC_FLAG_TAKE_MELEE_SWING;
            damageInfo->HitInfo      = HITINFO_OFFHAND;
            break;
        default:
            return;
    }

    // Physical Immune check
    if (damageInfo->Target->IsImmunedToDamage(SpellSchoolMask(damageInfo->DamageSchoolMask)))
    {
       damageInfo->HitInfo       |= HITINFO_NORMALSWING;
       damageInfo->TargetState    = VICTIMSTATE_IS_IMMUNE;

       damageInfo->Damage         = 0;
       damageInfo->CleanDamage    = 0;
       return;
    }

    uint32 damage = 0;
    damage += CalculateDamage(damageInfo->AttackType, false, true);
    // Add melee damage bonus
    damage = MeleeDamageBonusDone(damageInfo->Target, damage, damageInfo->AttackType, DIRECT_DAMAGE, nullptr, MECHANIC_NONE, SpellSchoolMask(damageInfo->DamageSchoolMask));
    damage = damageInfo->Target->MeleeDamageBonusTaken(this, damage, damageInfo->AttackType, DIRECT_DAMAGE, nullptr, SpellSchoolMask(damageInfo->DamageSchoolMask));

    // Script Hook For CalculateMeleeDamage -- Allow scripts to change the Damage pre class mitigation calculations
    sScriptMgr->ModifyMeleeDamage(damageInfo->Target, damageInfo->Attacker, damage);

    // Calculate armor reduction
    if (Unit::IsDamageReducedByArmor(SpellSchoolMask(damageInfo->DamageSchoolMask)))
    {
        damageInfo->Damage = Unit::CalcArmorReducedDamage(damageInfo->Attacker, damageInfo->Target, damage, nullptr, damageInfo->AttackType);
        damageInfo->CleanDamage += damage - damageInfo->Damage;
    }
    else
        damageInfo->Damage = damage;

    damageInfo->HitOutCome = RollMeleeOutcomeAgainst(damageInfo->Target, damageInfo->AttackType);

    switch (damageInfo->HitOutCome)
    {
        case MELEE_HIT_EVADE:
            damageInfo->HitInfo        |= HITINFO_MISS | HITINFO_SWINGNOHITSOUND;
            damageInfo->TargetState     = VICTIMSTATE_EVADES;
            damageInfo->OriginalDamage = damageInfo->Damage;

            damageInfo->Damage = 0;
            damageInfo->CleanDamage = 0;
            return;
        case MELEE_HIT_MISS:
            damageInfo->HitInfo        |= HITINFO_MISS;
            damageInfo->TargetState     = VICTIMSTATE_INTACT;
            damageInfo->OriginalDamage = damageInfo->Damage;

            damageInfo->Damage          = 0;
            damageInfo->CleanDamage     = 0;
            break;
        case MELEE_HIT_NORMAL:
            damageInfo->TargetState     = VICTIMSTATE_HIT;
            damageInfo->OriginalDamage = damageInfo->Damage;
            break;
        case MELEE_HIT_CRIT:
        {
            damageInfo->HitInfo        |= HITINFO_CRITICALHIT;
            damageInfo->TargetState     = VICTIMSTATE_HIT;

            // Crit bonus calc
            damageInfo->Damage *= 2;

            // Increase crit damage from SPELL_AURA_MOD_CRIT_DAMAGE_BONUS
            float mod = (GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_CRIT_DAMAGE_BONUS, damageInfo->DamageSchoolMask) - 1.0f) * 100;

            if (mod != 0)
                AddPct(damageInfo->Damage, mod);

            damageInfo->OriginalDamage = damageInfo->Damage;
            break;
        }
        case MELEE_HIT_PARRY:
            damageInfo->TargetState  = VICTIMSTATE_PARRY;
            damageInfo->CleanDamage += damageInfo->Damage;

            damageInfo->OriginalDamage = damageInfo->Damage;
            damageInfo->Damage = 0;
            break;
        case MELEE_HIT_DODGE:
            damageInfo->TargetState  = VICTIMSTATE_DODGE;
            damageInfo->CleanDamage += damageInfo->Damage;

            damageInfo->OriginalDamage = damageInfo->Damage;
            damageInfo->Damage = 0;
            break;
        case MELEE_HIT_BLOCK:
            damageInfo->TargetState = VICTIMSTATE_HIT;
            damageInfo->HitInfo    |= HITINFO_BLOCK;
            // 30% damage blocked, double blocked amount if block is critical
            damageInfo->Blocked = CalculatePct(damageInfo->Damage, damageInfo->Target->GetBlockPercent(GetLevel()));
            if (damageInfo->Target->IsBlockCritical())
                damageInfo->Blocked *= 2;

            damageInfo->OriginalDamage = damageInfo->Damage;
            damageInfo->Damage      -= damageInfo->Blocked;
            damageInfo->CleanDamage += damageInfo->Blocked;
            break;
        case MELEE_HIT_GLANCING:
        {
            damageInfo->HitInfo     |= HITINFO_GLANCING;
            damageInfo->TargetState  = VICTIMSTATE_HIT;
            int32 leveldif = int32(victim->GetLevel()) - int32(GetLevel());
            if (leveldif > 3)
                leveldif = 3;

            damageInfo->OriginalDamage = damageInfo->Damage;
            float reducePercent = 1.f - leveldif * 0.1f;
            damageInfo->CleanDamage += damageInfo->Damage - uint32(reducePercent * damageInfo->Damage);
            damageInfo->Damage = uint32(reducePercent * damageInfo->Damage);
            break;
        }
        case MELEE_HIT_CRUSHING:
            damageInfo->HitInfo     |= HITINFO_CRUSHING;
            damageInfo->TargetState  = VICTIMSTATE_HIT;
            // 150% normal damage
            damageInfo->Damage += (damageInfo->Damage / 2);
            damageInfo->OriginalDamage = damageInfo->Damage;
            break;
        default:
            break;
    }

    // Always apply HITINFO_AFFECTS_VICTIM in case its not a miss
    if (!(damageInfo->HitInfo & HITINFO_MISS))
        damageInfo->HitInfo |= HITINFO_AFFECTS_VICTIM;

    int32 resilienceReduction = damageInfo->Damage;
    if (CanApplyResilience())
        Unit::ApplyResilience(victim, &resilienceReduction);
    resilienceReduction = damageInfo->Damage - resilienceReduction;
    damageInfo->Damage      -= resilienceReduction;
    damageInfo->CleanDamage += resilienceReduction;
    damageInfo->OriginalDamage -= resilienceReduction;

    // Calculate absorb resist
    if (int32(damageInfo->Damage) > 0)
    {
        damageInfo->ProcVictim |= PROC_FLAG_TAKE_ANY_DAMAGE;
        // Calculate absorb & resists
        DamageInfo dmgInfo(*damageInfo);
        Unit::CalcAbsorbResist(dmgInfo);
        damageInfo->Absorb = dmgInfo.GetAbsorb();
        damageInfo->Resist = dmgInfo.GetResist();

        if (damageInfo->Absorb)
            damageInfo->HitInfo |= (damageInfo->Damage - damageInfo->Absorb == 0 ? HITINFO_FULL_ABSORB : HITINFO_PARTIAL_ABSORB);

        if (damageInfo->Resist)
            damageInfo->HitInfo |= (damageInfo->Damage - damageInfo->Resist == 0 ? HITINFO_FULL_RESIST : HITINFO_PARTIAL_RESIST);

        damageInfo->Damage = dmgInfo.GetDamage();
    }
    else // Impossible get negative result but....
        damageInfo->Damage = 0;
}

void Unit::DealMeleeDamage(CalcDamageInfo* damageInfo, bool durabilityLoss)
{
    Unit* victim = damageInfo->Target;

    if (!victim->IsAlive() || victim->HasUnitState(UNIT_STATE_IN_FLIGHT) || (victim->GetTypeId() == TYPEID_UNIT && victim->ToCreature()->IsEvadingAttacks()))
        return;

    if (damageInfo->TargetState == VICTIMSTATE_PARRY &&
        (victim->GetTypeId() != TYPEID_UNIT || (victim->ToCreature()->GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_NO_PARRY_HASTEN) == 0))
    {
        // Get attack timers
        float offtime  = float(victim->getAttackTimer(OFF_ATTACK));
        float basetime = float(victim->getAttackTimer(BASE_ATTACK));
        // Reduce attack time
        if (victim->haveOffhandWeapon() && offtime < basetime)
        {
            float percent20 = victim->GetBaseAttackTime(OFF_ATTACK) * 0.20f;
            float percent60 = 3.0f * percent20;
            if (offtime > percent20 && offtime <= percent60)
                victim->setAttackTimer(OFF_ATTACK, uint32(percent20));
            else if (offtime > percent60)
            {
                offtime -= 2.0f * percent20;
                victim->setAttackTimer(OFF_ATTACK, uint32(offtime));
            }
        }
        else
        {
            float percent20 = victim->GetBaseAttackTime(BASE_ATTACK) * 0.20f;
            float percent60 = 3.0f * percent20;
            if (basetime > percent20 && basetime <= percent60)
                victim->setAttackTimer(BASE_ATTACK, uint32(percent20));
            else if (basetime > percent60)
            {
                basetime -= 2.0f * percent20;
                victim->setAttackTimer(BASE_ATTACK, uint32(basetime));
            }
        }
    }

    // Call default DealDamage
    CleanDamage cleanDamage(damageInfo->CleanDamage, damageInfo->Absorb, damageInfo->AttackType, damageInfo->HitOutCome);
    Unit::DealDamage(this, victim, damageInfo->Damage, &cleanDamage, DIRECT_DAMAGE, SpellSchoolMask(damageInfo->DamageSchoolMask), nullptr, durabilityLoss);

    // If this is a creature and it attacks from behind it has a probability to daze it's victim
    if ((damageInfo->HitOutCome == MELEE_HIT_CRIT || damageInfo->HitOutCome == MELEE_HIT_CRUSHING || damageInfo->HitOutCome == MELEE_HIT_NORMAL || damageInfo->HitOutCome == MELEE_HIT_GLANCING) &&
        GetTypeId() != TYPEID_PLAYER && !ToCreature()->IsControlledByPlayer() && !victim->HasInArc(float(M_PI), this)
        && (victim->GetTypeId() == TYPEID_PLAYER || !victim->ToCreature()->isWorldBoss())&& !victim->IsVehicle())
    {
        // 20% base chance
        float chance = 20.0f;

        // there is a newbie protection, at level 10 just 7% base chance; assuming linear function
        if (victim->GetLevel() < 30)
            chance = 0.65f * victim->GetLevelForTarget(this) + 0.5f;

        uint32 const victimDefense = victim->GetMaxSkillValueForLevel(this);
        uint32 const attackerMeleeSkill = GetMaxSkillValueForLevel();

        chance *= attackerMeleeSkill / float(victimDefense) * 0.16f;

        // -probability is between 0% and 40%
        RoundToInterval(chance, 0.0f, 40.0f);
        if (roll_chance_f(chance))
            CastSpell(victim, 1604 /*SPELL_DAZED*/, true);
    }

    if (GetTypeId() == TYPEID_PLAYER)
    {
        DamageInfo dmgInfo(*damageInfo);
        ToPlayer()->CastItemCombatSpell(dmgInfo);
    }

    // Do effect if any damage done to target
    if (damageInfo->Damage)
    {
        // We're going to call functions which can modify content of the list during iteration over it's elements
        // Let's copy the list so we can prevent iterator invalidation
        AuraEffectVector vDamageShieldsCopy = CopyAuraEffectList(victim->GetAuraEffectsByType(SPELL_AURA_DAMAGE_SHIELD));
        for (AuraEffect const* aurEff : vDamageShieldsCopy)
        {
            SpellInfo const* spellInfo = aurEff->GetSpellInfo();

            // Damage shield can be resisted...
            SpellMissInfo missInfo = victim->SpellHitResult(this, spellInfo, false);
            if (missInfo != SPELL_MISS_NONE)
            {
                victim->SendSpellMiss(this, spellInfo->Id, missInfo);
                continue;
            }

            // ...or immuned
            if (IsImmunedToDamage(spellInfo))
            {
                victim->SendSpellDamageImmune(this, spellInfo->Id, false);
                continue;
            }

            uint32 damage = aurEff->GetAmount();
            if (Unit* caster = aurEff->GetCaster())
            {
                damage = caster->SpellDamageBonusDone(this, spellInfo, damage, SPELL_DIRECT_DAMAGE, aurEff->GetSpellEffectInfo());
                damage = SpellDamageBonusTaken(caster, spellInfo, damage, SPELL_DIRECT_DAMAGE);
            }

            DamageInfo damageInfo(this, victim, damage, spellInfo, spellInfo->GetSchoolMask(), SPELL_DIRECT_DAMAGE, BASE_ATTACK);
            victim->CalcAbsorbResist(damageInfo);
            damage = damageInfo.GetDamage();
            Unit::DealDamageMods(victim, this, damage, nullptr);

            WorldPackets::CombatLog::SpellDamageShield damageShield;
            damageShield.Attacker = victim->GetGUID();
            damageShield.Defender = GetGUID();
            damageShield.SpellID = spellInfo->Id;
            damageShield.TotalDamage = damage;
            damageShield.OriginalDamage = damageInfo.GetOriginalDamage();
            damageShield.OverKill = std::max(int32(damage) - int32(GetHealth()), 0);
            damageShield.SchoolMask = spellInfo->SchoolMask;
            damageShield.LogAbsorbed = damageInfo.GetAbsorb();

            Unit::DealDamage(victim, this, damage, nullptr, SPELL_DIRECT_DAMAGE, spellInfo->GetSchoolMask(), spellInfo, true);

            damageShield.LogData.Initialize(this);
            victim->SendCombatLogMessage(&damageShield);
        }
    }
}

void Unit::HandleEmoteCommand(Emote emoteId, Player* target /*=nullptr*/, Trinity::IteratorPair<int32 const*> spellVisualKitIds /*= {}*/, int32 sequenceVariation /*= 0*/)
{
    WorldPackets::Chat::Emote packet;
    packet.Guid = GetGUID();
    packet.EmoteID = emoteId;

    if (EmotesEntry const* emotesEntry = sEmotesStore.LookupEntry(emoteId))
        if (emotesEntry->AnimID == ANIM_MOUNT_SPECIAL || emotesEntry->AnimID == ANIM_MOUNT_SELF_SPECIAL)
            std::copy(spellVisualKitIds.begin(), spellVisualKitIds.end(), std::back_inserter(packet.SpellVisualKitIDs));

    packet.SequenceVariation = sequenceVariation;

    if (target)
        target->SendDirectMessage(packet.Write());
    else
        SendMessageToSet(packet.Write(), true);
}

/*static*/ bool Unit::IsDamageReducedByArmor(SpellSchoolMask schoolMask, SpellInfo const* spellInfo /*= nullptr*/)
{
    // only physical spells damage gets reduced by armor
    if ((schoolMask & SPELL_SCHOOL_MASK_NORMAL) == 0)
        return false;

    return !spellInfo || !spellInfo->HasAttribute(SPELL_ATTR0_CU_IGNORE_ARMOR);
}

/*static*/ uint32 Unit::CalcArmorReducedDamage(Unit const* attacker, Unit* victim, uint32 damage, SpellInfo const* spellInfo, WeaponAttackType /*attackType*/ /*= MAX_ATTACK*/, uint8 attackerLevel /*= 0*/)
{
    float armor = float(victim->GetArmor());

    if (attacker)
    {
        armor *= victim->GetArmorMultiplierForTarget(attacker);

        // bypass enemy armor by SPELL_AURA_BYPASS_ARMOR_FOR_CASTER
        int32 armorBypassPct = 0;
        AuraEffectList const & reductionAuras = victim->GetAuraEffectsByType(SPELL_AURA_BYPASS_ARMOR_FOR_CASTER);
        for (AuraEffectList::const_iterator i = reductionAuras.begin(); i != reductionAuras.end(); ++i)
            if ((*i)->GetCasterGUID() == attacker->GetGUID())
                armorBypassPct += (*i)->GetAmount();
        armor = CalculatePct(armor, 100 - std::min(armorBypassPct, 100));

        // Ignore enemy armor by SPELL_AURA_MOD_TARGET_RESISTANCE aura
        armor += attacker->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_TARGET_RESISTANCE, SPELL_SCHOOL_MASK_NORMAL);

        if (spellInfo)
            if (Player* modOwner = attacker->GetSpellModOwner())
                modOwner->ApplySpellMod(spellInfo, SpellModOp::TargetResistance, armor);

        AuraEffectList const& resIgnoreAuras = attacker->GetAuraEffectsByType(SPELL_AURA_MOD_IGNORE_TARGET_RESIST);
        for (AuraEffect const* aurEff : resIgnoreAuras)
        {
            if (aurEff->GetMiscValue() & SPELL_SCHOOL_MASK_NORMAL && aurEff->IsAffectingSpell(spellInfo))
                armor = std::floor(AddPct(armor, -aurEff->GetAmount()));
        }

        // Apply Player CR_ARMOR_PENETRATION rating
        if (attacker->GetTypeId() == TYPEID_PLAYER)
        {
            float arpPct = attacker->ToPlayer()->GetRatingBonusValue(CR_ARMOR_PENETRATION);

            // no more than 100%
            RoundToInterval(arpPct, 0.f, 100.f);

            float maxArmorPen = 0.f;
            if (victim->GetLevelForTarget(attacker) < 60)
                maxArmorPen = float(400 + 85 * victim->GetLevelForTarget(attacker));
            else
                maxArmorPen = 400 + 85 * victim->GetLevelForTarget(attacker) + 4.5f * 85 * (victim->GetLevelForTarget(attacker) - 59);

            // Cap armor penetration to this number
            maxArmorPen = std::min((armor + maxArmorPen) / 3.f, armor);
            // Figure out how much armor do we ignore
            armor -= CalculatePct(maxArmorPen, arpPct);
        }
    }

    if (G3D::fuzzyLe(armor, 0.0f))
        return damage;

    Classes attackerClass = CLASS_WARRIOR;
    if (attacker)
    {
        attackerLevel = attacker->GetLevelForTarget(victim);
        attackerClass = Classes(attacker->GetClass());
    }

    // Expansion and ContentTuningID necessary? Does Player get a ContentTuningID too ?
    float armorConstant = sDB2Manager.EvaluateExpectedStat(ExpectedStatType::ArmorConstant, attackerLevel, -2, 0, attackerClass, 0);

    if (!(armor + armorConstant))
        return damage;

    float mitigation = std::min(armor / (armor + armorConstant), 0.85f);
    return uint32(std::max(damage * (1.0f - mitigation), 0.0f));
}

/*static*/ uint32 Unit::CalcSpellResistedDamage(Unit const* attacker, Unit* victim, uint32 damage, SpellSchoolMask schoolMask, SpellInfo const* spellInfo)
{
    // Magic damage, check for resists
    if (!(schoolMask & SPELL_SCHOOL_MASK_MAGIC))
        return 0;

    // Npcs can have holy resistance
    if ((schoolMask & SPELL_SCHOOL_MASK_HOLY) && victim->GetTypeId() != TYPEID_UNIT)
        return 0;

    float const averageResist = Unit::CalculateAverageResistReduction(attacker, schoolMask, victim, spellInfo);
    float discreteResistProbability[11] = { };
    if (averageResist <= 0.1f)
    {
        discreteResistProbability[0] = 1.0f - 7.5f * averageResist;
        discreteResistProbability[1] = 5.0f * averageResist;
        discreteResistProbability[2] = 2.5f * averageResist;
    }
    else
    {
        for (uint32 i = 0; i < 11; ++i)
            discreteResistProbability[i] = std::max(0.5f - 2.5f * std::fabs(0.1f * i - averageResist), 0.0f);
    }

    float roll = rand_norm();
    float probabilitySum = 0.0f;

    uint32 resistance = 0;
    for (; resistance < 11; ++resistance)
        if (roll < (probabilitySum += discreteResistProbability[resistance]))
            break;

    float damageResisted = damage * resistance / 10.f;
    if (damageResisted > 0.0f) // if any damage was resisted
    {
        int32 ignoredResistance = 0;

        if (attacker)
            ignoredResistance += attacker->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_IGNORE_TARGET_RESIST, schoolMask);

        ignoredResistance = std::min<int32>(ignoredResistance, 100);
        ApplyPct(damageResisted, 100 - ignoredResistance);

        // Spells with melee and magic school mask, decide whether resistance or armor absorb is higher
        if (spellInfo && spellInfo->HasAttribute(SPELL_ATTR0_CU_SCHOOLMASK_NORMAL_WITH_MAGIC))
        {
            uint32 damageAfterArmor = Unit::CalcArmorReducedDamage(attacker, victim, damage, spellInfo, spellInfo->GetAttackType());
            float armorReduction = damage - damageAfterArmor;

            // pick the lower one, the weakest resistance counts
            damageResisted = std::min(damageResisted, armorReduction);
        }
    }

    damageResisted = std::max(damageResisted, 0.f);
    return uint32(damageResisted);
}

/*static*/ float Unit::CalculateAverageResistReduction(WorldObject const* caster, SpellSchoolMask schoolMask, Unit const* victim, SpellInfo const* spellInfo /*= nullptr*/)
{
    float victimResistance = float(victim->GetResistance(schoolMask));
    if (caster)
    {
        // pets inherit 100% of masters penetration
        if (Player const* player = caster->GetSpellModOwner())
        {
            victimResistance += float(player->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_TARGET_RESISTANCE, schoolMask));
            victimResistance -= float(player->GetSpellPenetrationItemMod());
        }
        else if (Unit const* unitCaster = caster->ToUnit())
            victimResistance += float(unitCaster->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_TARGET_RESISTANCE, schoolMask));
    }

    // holy resistance exists in pve and comes from level difference, ignore template values
    if (schoolMask & SPELL_SCHOOL_MASK_HOLY)
        victimResistance = 0.0f;

    // Chaos Bolt exception, ignore all target resistances (unknown attribute?)
    if (spellInfo && spellInfo->SpellFamilyName == SPELLFAMILY_WARLOCK && spellInfo->Id == 116858)
        victimResistance = 0.0f;

    victimResistance = std::max(victimResistance, 0.0f);

    // level-based resistance does not apply to binary spells, and cannot be overcome by spell penetration
    // gameobject caster -- should it have level based resistance?
    if (caster && caster->GetTypeId() != TYPEID_GAMEOBJECT && (!spellInfo || !spellInfo->HasAttribute(SPELL_ATTR0_CU_BINARY_SPELL)))
        victimResistance += std::max((float(victim->GetLevelForTarget(caster)) - float(caster->GetLevelForTarget(victim))) * 5.0f, 0.0f);

    static uint32 const bossLevel = 83;
    static float const bossResistanceConstant = 510.0f;
    uint32 level = caster ? victim->GetLevelForTarget(caster) : victim->GetLevel();
    float resistanceConstant = 0.0f;

    if (level == bossLevel)
        resistanceConstant = bossResistanceConstant;
    else
        resistanceConstant = level * 5.0f;

    return victimResistance / (victimResistance + resistanceConstant);
}

/*static*/ void Unit::CalcAbsorbResist(DamageInfo& damageInfo, Spell* spell /*= nullptr*/)
{
    if (!damageInfo.GetVictim() || !damageInfo.GetVictim()->IsAlive() || !damageInfo.GetDamage())
        return;

    uint32 resistedDamage = Unit::CalcSpellResistedDamage(damageInfo.GetAttacker(), damageInfo.GetVictim(), damageInfo.GetDamage(), damageInfo.GetSchoolMask(), damageInfo.GetSpellInfo());

    // Ignore Absorption Auras
    float auraAbsorbMod = 0.f;
    if (Unit* attacker = damageInfo.GetAttacker())
        auraAbsorbMod = attacker->GetMaxPositiveAuraModifierByMiscMask(SPELL_AURA_MOD_TARGET_ABSORB_SCHOOL, damageInfo.GetSchoolMask());

    RoundToInterval(auraAbsorbMod, 0.0f, 100.0f);

    int32 absorbIgnoringDamage = CalculatePct(damageInfo.GetDamage(), auraAbsorbMod);

    if (spell)
        spell->CallScriptOnResistAbsorbCalculateHandlers(damageInfo, resistedDamage, absorbIgnoringDamage);

    damageInfo.ResistDamage(resistedDamage);

    // We're going to call functions which can modify content of the list during iteration over it's elements
    // Let's copy the list so we can prevent iterator invalidation
    AuraEffectVector vSchoolAbsorbCopy = CopyAuraEffectList(damageInfo.GetVictim()->GetAuraEffectsByType(SPELL_AURA_SCHOOL_ABSORB));
    std::sort(vSchoolAbsorbCopy.begin(), vSchoolAbsorbCopy.end(), Trinity::AbsorbAuraOrderPred());

    // absorb without mana cost
    for (auto itr = vSchoolAbsorbCopy.begin(); (itr != vSchoolAbsorbCopy.end()) && (damageInfo.GetDamage() > 0); ++itr)
    {
        AuraEffect* absorbAurEff = *itr;
        // Check if aura was removed during iteration - we don't need to work on such auras
        AuraApplication const* aurApp = absorbAurEff->GetBase()->GetApplicationOfTarget(damageInfo.GetVictim()->GetGUID());
        if (!aurApp)
            continue;
        if (!(absorbAurEff->GetMiscValue() & damageInfo.GetSchoolMask()))
            continue;

        // get amount which can be still absorbed by the aura
        int32 currentAbsorb = absorbAurEff->GetAmount();
        // aura with infinite absorb amount - let the scripts handle absorbtion amount, set here to 0 for safety
        if (currentAbsorb < 0)
            currentAbsorb = 0;

        if (!absorbAurEff->GetSpellInfo()->HasAttribute(SPELL_ATTR6_ABSORB_CANNOT_BE_IGNORE))
            damageInfo.ModifyDamage(-absorbIgnoringDamage);

        uint32 tempAbsorb = uint32(currentAbsorb);

        bool defaultPrevented = false;

        absorbAurEff->GetBase()->CallScriptEffectAbsorbHandlers(absorbAurEff, aurApp, damageInfo, tempAbsorb, defaultPrevented);
        currentAbsorb = tempAbsorb;

        if (!defaultPrevented)
        {
            // absorb must be smaller than the damage itself
            currentAbsorb = RoundToInterval(currentAbsorb, 0, int32(damageInfo.GetDamage()));

            damageInfo.AbsorbDamage(currentAbsorb);

            tempAbsorb = currentAbsorb;
            absorbAurEff->GetBase()->CallScriptEffectAfterAbsorbHandlers(absorbAurEff, aurApp, damageInfo, tempAbsorb);

            // Check if our aura is using amount to count damage
            if (absorbAurEff->GetAmount() >= 0)
            {
                // Reduce shield amount
                absorbAurEff->ChangeAmount(absorbAurEff->GetAmount() - currentAbsorb);
                // Aura cannot absorb anything more - remove it
                if (absorbAurEff->GetAmount() <= 0)
                    absorbAurEff->GetBase()->Remove(AURA_REMOVE_BY_ENEMY_SPELL);
            }
        }

        if (!absorbAurEff->GetSpellInfo()->HasAttribute(SPELL_ATTR6_ABSORB_CANNOT_BE_IGNORE))
            damageInfo.ModifyDamage(absorbIgnoringDamage);

        if (currentAbsorb)
        {
            WorldPackets::CombatLog::SpellAbsorbLog absorbLog;
            absorbLog.Attacker = damageInfo.GetAttacker() ? damageInfo.GetAttacker()->GetGUID() : ObjectGuid::Empty;
            absorbLog.Victim = damageInfo.GetVictim()->GetGUID();
            absorbLog.Caster = absorbAurEff->GetBase()->GetCasterGUID();
            absorbLog.AbsorbedSpellID = damageInfo.GetSpellInfo() ? damageInfo.GetSpellInfo()->Id : 0;
            absorbLog.AbsorbSpellID = absorbAurEff->GetId();
            absorbLog.Absorbed = currentAbsorb;
            absorbLog.OriginalDamage = damageInfo.GetOriginalDamage();
            absorbLog.LogData.Initialize(damageInfo.GetVictim());
            damageInfo.GetVictim()->SendCombatLogMessage(&absorbLog);
        }
    }

    // absorb by mana cost
    AuraEffectVector vManaShieldCopy = CopyAuraEffectList(damageInfo.GetVictim()->GetAuraEffectsByType(SPELL_AURA_MANA_SHIELD));
    for (auto itr = vManaShieldCopy.begin(); (itr != vManaShieldCopy.end()) && (damageInfo.GetDamage() > 0); ++itr)
    {
        AuraEffect* absorbAurEff = *itr;
        // Check if aura was removed during iteration - we don't need to work on such auras
        AuraApplication const* aurApp = absorbAurEff->GetBase()->GetApplicationOfTarget(damageInfo.GetVictim()->GetGUID());
        if (!aurApp)
            continue;
        // check damage school mask
        if (!(absorbAurEff->GetMiscValue() & damageInfo.GetSchoolMask()))
            continue;

        // get amount which can be still absorbed by the aura
        int32 currentAbsorb = absorbAurEff->GetAmount();
        // aura with infinite absorb amount - let the scripts handle absorbtion amount, set here to 0 for safety
        if (currentAbsorb < 0)
            currentAbsorb = 0;

        if (!absorbAurEff->GetSpellInfo()->HasAttribute(SPELL_ATTR6_ABSORB_CANNOT_BE_IGNORE))
            damageInfo.ModifyDamage(-absorbIgnoringDamage);

        uint32 tempAbsorb = currentAbsorb;

        bool defaultPrevented = false;

        absorbAurEff->GetBase()->CallScriptEffectManaShieldHandlers(absorbAurEff, aurApp, damageInfo, tempAbsorb, defaultPrevented);
        currentAbsorb = tempAbsorb;

        if (!defaultPrevented)
        {
            // absorb must be smaller than the damage itself
            currentAbsorb = RoundToInterval(currentAbsorb, 0, int32(damageInfo.GetDamage()));

            int32 manaReduction = currentAbsorb;

            // lower absorb amount by talents
            if (float manaMultiplier = absorbAurEff->GetSpellEffectInfo().CalcValueMultiplier(absorbAurEff->GetCaster()))
                manaReduction = int32(float(manaReduction) * manaMultiplier);

            int32 manaTaken = -damageInfo.GetVictim()->ModifyPower(POWER_MANA, -manaReduction);

            // take case when mana has ended up into account
            currentAbsorb = currentAbsorb ? int32(float(currentAbsorb) * (float(manaTaken) / float(manaReduction))) : 0;

            damageInfo.AbsorbDamage(currentAbsorb);

            tempAbsorb = currentAbsorb;
            absorbAurEff->GetBase()->CallScriptEffectAfterManaShieldHandlers(absorbAurEff, aurApp, damageInfo, tempAbsorb);

            // Check if our aura is using amount to count damage
            if (absorbAurEff->GetAmount() >= 0)
            {
                absorbAurEff->ChangeAmount(absorbAurEff->GetAmount() - currentAbsorb);
                if ((absorbAurEff->GetAmount() <= 0))
                    absorbAurEff->GetBase()->Remove(AURA_REMOVE_BY_ENEMY_SPELL);
            }
        }

        if (!absorbAurEff->GetSpellInfo()->HasAttribute(SPELL_ATTR6_ABSORB_CANNOT_BE_IGNORE))
            damageInfo.ModifyDamage(absorbIgnoringDamage);

        if (currentAbsorb)
        {
            WorldPackets::CombatLog::SpellAbsorbLog absorbLog;
            absorbLog.Attacker = damageInfo.GetAttacker() ? damageInfo.GetAttacker()->GetGUID() : ObjectGuid::Empty;
            absorbLog.Victim = damageInfo.GetVictim()->GetGUID();
            absorbLog.Caster = absorbAurEff->GetBase()->GetCasterGUID();
            absorbLog.AbsorbedSpellID = damageInfo.GetSpellInfo() ? damageInfo.GetSpellInfo()->Id : 0;
            absorbLog.AbsorbSpellID = absorbAurEff->GetId();
            absorbLog.Absorbed = currentAbsorb;
            absorbLog.OriginalDamage = damageInfo.GetOriginalDamage();
            absorbLog.LogData.Initialize(damageInfo.GetVictim());
            damageInfo.GetVictim()->SendCombatLogMessage(&absorbLog);
        }
    }

    // split damage auras - only when not damaging self
    if (damageInfo.GetVictim() != damageInfo.GetAttacker())
    {
        // We're going to call functions which can modify content of the list during iteration over it's elements
        // Let's copy the list so we can prevent iterator invalidation
        AuraEffectVector vSplitDamagePctCopy = CopyAuraEffectList(damageInfo.GetVictim()->GetAuraEffectsByType(SPELL_AURA_SPLIT_DAMAGE_PCT));
        for (auto itr = vSplitDamagePctCopy.begin(); itr != vSplitDamagePctCopy.end() && damageInfo.GetDamage() > 0; ++itr)
        {
            // Check if aura was removed during iteration - we don't need to work on such auras
            AuraApplication const* aurApp = (*itr)->GetBase()->GetApplicationOfTarget(damageInfo.GetVictim()->GetGUID());
            if (!aurApp)
                continue;

            // check damage school mask
            if (!((*itr)->GetMiscValue() & damageInfo.GetSchoolMask()))
                continue;

            // Damage can be splitted only if aura has an alive caster
            Unit* caster = (*itr)->GetCaster();
            if (!caster || (caster == damageInfo.GetVictim()) || !caster->IsInWorld() || !caster->IsAlive())
                continue;

            uint32 splitDamage = CalculatePct(damageInfo.GetDamage(), (*itr)->GetAmount());

            (*itr)->GetBase()->CallScriptEffectSplitHandlers((*itr), aurApp, damageInfo, splitDamage);

            // absorb must be smaller than the damage itself
            splitDamage = RoundToInterval(splitDamage, uint32(0), uint32(damageInfo.GetDamage()));

            damageInfo.AbsorbDamage(splitDamage);

            // check if caster is immune to damage
            if (caster->IsImmunedToDamage(damageInfo.GetSchoolMask()))
            {
                damageInfo.GetVictim()->SendSpellMiss(caster, (*itr)->GetSpellInfo()->Id, SPELL_MISS_IMMUNE);
                continue;
            }

            uint32 split_absorb = 0;
            Unit::DealDamageMods(damageInfo.GetAttacker(), caster, splitDamage, &split_absorb);

            // sparring
            if (Creature* victimCreature = damageInfo.GetVictim()->ToCreature())
            {
                if (victimCreature->ShouldFakeDamageFrom(damageInfo.GetAttacker()))
                    damageInfo.ModifyDamage(damageInfo.GetDamage() * -1);
            }

            SpellNonMeleeDamage log(damageInfo.GetAttacker(), caster, (*itr)->GetSpellInfo(), (*itr)->GetBase()->GetSpellVisual(), damageInfo.GetSchoolMask(), (*itr)->GetBase()->GetCastId());
            CleanDamage cleanDamage = CleanDamage(splitDamage, 0, BASE_ATTACK, MELEE_HIT_NORMAL);
            Unit::DealDamage(damageInfo.GetAttacker(), caster, splitDamage, &cleanDamage, DIRECT_DAMAGE, damageInfo.GetSchoolMask(), (*itr)->GetSpellInfo(), false);
            log.damage = splitDamage;
            log.originalDamage = splitDamage;
            log.absorb = split_absorb;
            caster->SendSpellNonMeleeDamageLog(&log);

            // break 'Fear' and similar auras
            Unit::ProcSkillsAndAuras(damageInfo.GetAttacker(), caster, PROC_FLAG_NONE, PROC_FLAG_TAKE_HARMFUL_SPELL, PROC_SPELL_TYPE_DAMAGE, PROC_SPELL_PHASE_HIT, PROC_HIT_NONE, nullptr, &damageInfo, nullptr);
        }
    }
}

/*static*/ void Unit::CalcHealAbsorb(HealInfo& healInfo)
{
    if (!healInfo.GetHeal())
        return;

    AuraEffectVector vHealAbsorb = CopyAuraEffectList(healInfo.GetTarget()->GetAuraEffectsByType(SPELL_AURA_SCHOOL_HEAL_ABSORB));
    for (auto i = vHealAbsorb.begin(); i != vHealAbsorb.end() && healInfo.GetHeal() > 0; ++i)
    {
        AuraEffect* absorbAurEff = *i;
        // Check if aura was removed during iteration - we don't need to work on such auras
        AuraApplication const* aurApp = absorbAurEff->GetBase()->GetApplicationOfTarget(healInfo.GetTarget()->GetGUID());
        if (!aurApp)
            continue;
        if (!(absorbAurEff->GetMiscValue() & healInfo.GetSchoolMask()))
            continue;

        // get amount which can be still absorbed by the aura
        int32 currentAbsorb = absorbAurEff->GetAmount();
        // aura with infinite absorb amount - let the scripts handle absorbtion amount, set here to 0 for safety
        if (currentAbsorb < 0)
            currentAbsorb = 0;

        uint32 tempAbsorb = uint32(currentAbsorb);

        bool defaultPrevented = false;

        absorbAurEff->GetBase()->CallScriptEffectAbsorbHandlers(absorbAurEff, aurApp, healInfo, tempAbsorb, defaultPrevented);
        currentAbsorb = tempAbsorb;

        if (!defaultPrevented)
        {
            // absorb must be smaller than the heal itself
            currentAbsorb = RoundToInterval(currentAbsorb, 0, int32(healInfo.GetHeal()));

            healInfo.AbsorbHeal(currentAbsorb);

            tempAbsorb = currentAbsorb;
            absorbAurEff->GetBase()->CallScriptEffectAfterAbsorbHandlers(absorbAurEff, aurApp, healInfo, tempAbsorb);

            // Check if our aura is using amount to count heal
            if (absorbAurEff->GetAmount() >= 0)
            {
                // Reduce shield amount
                absorbAurEff->ChangeAmount(absorbAurEff->GetAmount() - currentAbsorb);
                // Aura cannot absorb anything more - remove it
                if (absorbAurEff->GetAmount() <= 0)
                    absorbAurEff->GetBase()->Remove(AURA_REMOVE_BY_ENEMY_SPELL);
            }
        }

        if (currentAbsorb)
        {
            WorldPackets::CombatLog::SpellHealAbsorbLog absorbLog;
            absorbLog.Healer = healInfo.GetHealer() ? healInfo.GetHealer()->GetGUID() : ObjectGuid::Empty;
            absorbLog.Target = healInfo.GetTarget()->GetGUID();
            absorbLog.AbsorbCaster = absorbAurEff->GetBase()->GetCasterGUID();
            absorbLog.AbsorbedSpellID = healInfo.GetSpellInfo() ? healInfo.GetSpellInfo()->Id : 0;
            absorbLog.AbsorbSpellID = absorbAurEff->GetId();
            absorbLog.Absorbed = currentAbsorb;
            absorbLog.OriginalHeal = healInfo.GetOriginalHeal();
            healInfo.GetTarget()->SendMessageToSet(absorbLog.Write(), true);
        }
    }
}

void Unit::DoMeleeAttackIfReady()
{
    if (!HasUnitState(UNIT_STATE_MELEE_ATTACKING))
        return;

    if (HasUnitState(UNIT_STATE_CHARGING))
        return;

    if (IsCreature() && !ToCreature()->CanMelee())
        return;

    if (HasUnitState(UNIT_STATE_CASTING))
    {
        Spell* channeledSpell = GetCurrentSpell(CURRENT_CHANNELED_SPELL);
        if (!channeledSpell || !channeledSpell->GetSpellInfo()->HasAttribute(SPELL_ATTR5_ALLOW_ACTIONS_DURING_CHANNEL))
            return;
    }

    Unit* victim = GetVictim();
    if (!victim)
        return;

    auto getAutoAttackError = [&]() -> Optional<AttackSwingErr>
    {
        if (!IsWithinMeleeRange(victim))
            return AttackSwingErr::NotInRange;

        //120 degrees of radiant range, if player is not in boundary radius
        if (!IsWithinBoundaryRadius(victim) && !HasInArc(2 * float(M_PI) / 3, victim))
            return AttackSwingErr::BadFacing;

        return {};
    };

    if (isAttackReady(BASE_ATTACK))
    {
        Optional<AttackSwingErr> autoAttackError = getAutoAttackError();
        if (!autoAttackError)
        {
            // prevent base and off attack in same time, delay attack at 0.2 sec
            if (haveOffhandWeapon())
                if (getAttackTimer(OFF_ATTACK) < ATTACK_DISPLAY_DELAY)
                    setAttackTimer(OFF_ATTACK, ATTACK_DISPLAY_DELAY);

            // do attack
            AttackerStateUpdate(victim, BASE_ATTACK);
            resetAttackTimer(BASE_ATTACK);
        }
        else
            setAttackTimer(BASE_ATTACK, 100);

        if (Player* attackerPlayer = ToPlayer())
            attackerPlayer->SetAttackSwingError(autoAttackError);
    }

    if (!IsInFeralForm() && haveOffhandWeapon() && isAttackReady(OFF_ATTACK))
    {
        Optional<AttackSwingErr> autoAttackError = getAutoAttackError();
        if (!autoAttackError)
        {
            // prevent base and off attack in same time, delay attack at 0.2 sec
            if (getAttackTimer(BASE_ATTACK) < ATTACK_DISPLAY_DELAY)
                setAttackTimer(BASE_ATTACK, ATTACK_DISPLAY_DELAY);

            // do attack
            AttackerStateUpdate(victim, OFF_ATTACK);
            resetAttackTimer(OFF_ATTACK);
        }
        else
            setAttackTimer(OFF_ATTACK, 100);
    }
}

void Unit::AttackerStateUpdate(Unit* victim, WeaponAttackType attType, bool extra)
{
    if (HasUnitFlag(UNIT_FLAG_PACIFIED))
        return;

    if (HasUnitState(UNIT_STATE_CANNOT_AUTOATTACK) && !extra)
        return;

    if (HasAuraType(SPELL_AURA_DISABLE_ATTACKING_EXCEPT_ABILITIES))
        return;

    if (!victim->IsAlive())
        return;

    if ((attType == BASE_ATTACK || attType == OFF_ATTACK) && !IsWithinLOSInMap(victim))
        return;

    AtTargetAttacked(victim, true);
    RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::Attacking);

    if (attType != BASE_ATTACK && attType != OFF_ATTACK)
        return;                                             // ignore ranged case

    if (!extra && _lastExtraAttackSpell)
        _lastExtraAttackSpell = 0;

    // melee attack spell cast at main hand attack only - no normal melee dmg dealt
    if (attType == BASE_ATTACK && m_currentSpells[CURRENT_MELEE_SPELL] && !extra)
        m_currentSpells[CURRENT_MELEE_SPELL]->cast();
    else
    {
        // attack can be redirected to another target
        victim = GetMeleeHitRedirectTarget(victim);

        AuraEffectList const& meleeAttackOverrides = GetAuraEffectsByType(SPELL_AURA_OVERRIDE_AUTOATTACK_WITH_MELEE_SPELL);
        uint32 meleeAttackSpellId = 0;
        if (attType == BASE_ATTACK)
        {
            if (!meleeAttackOverrides.empty())
                meleeAttackSpellId = meleeAttackOverrides.front()->GetSpellEffectInfo().TriggerSpell;
        }
        else
        {
            auto itr = std::find_if(meleeAttackOverrides.begin(), meleeAttackOverrides.end(), [&](AuraEffect const* aurEff)
            {
                return aurEff->GetSpellEffectInfo().MiscValue != 0;
            });
            if (itr != meleeAttackOverrides.end())
                meleeAttackSpellId = (*itr)->GetSpellEffectInfo().MiscValue;
        }

        if (!meleeAttackSpellId)
        {
            CalcDamageInfo damageInfo;
            CalculateMeleeDamage(victim, &damageInfo, attType);
            // Send log damage message to client
            Unit::DealDamageMods(damageInfo.Attacker, victim, damageInfo.Damage, &damageInfo.Absorb);

            // sparring
            if (Creature* victimCreature = victim->ToCreature())
            {
                if (victimCreature->ShouldFakeDamageFrom(damageInfo.Attacker))
                    damageInfo.HitInfo |= HITINFO_FAKE_DAMAGE;
            }

            SendAttackStateUpdate(&damageInfo);

            _lastDamagedTargetGuid = victim->GetGUID();

            DealMeleeDamage(&damageInfo, true);

            DamageInfo dmgInfo(damageInfo);
            Unit::ProcSkillsAndAuras(damageInfo.Attacker, damageInfo.Target, damageInfo.ProcAttacker, damageInfo.ProcVictim, PROC_SPELL_TYPE_NONE, PROC_SPELL_PHASE_NONE, dmgInfo.GetHitMask(), nullptr, &dmgInfo, nullptr);

            TC_LOG_DEBUG("entities.unit", "AttackerStateUpdate: {} attacked {} for {} dmg, absorbed {}, blocked {}, resisted {}.",
                GetGUID().ToString(), victim->GetGUID().ToString(), damageInfo.Damage, damageInfo.Absorb, damageInfo.Blocked, damageInfo.Resist);
        }
        else
        {
            CastSpell(victim, meleeAttackSpellId, true);

            uint32 hitInfo = HITINFO_AFFECTS_VICTIM | HITINFO_NO_ANIMATION;
            if (attType == OFF_ATTACK)
                hitInfo |= HITINFO_OFFHAND;

            SendAttackStateUpdate(hitInfo, victim, 0, GetMeleeDamageSchoolMask(), 0, 0, 0, VICTIMSTATE_HIT, 0);
        }
    }
}

void Unit::HandleProcExtraAttackFor(Unit* victim, uint32 count)
{
    while (count)
    {
        --count;
        AttackerStateUpdate(victim, BASE_ATTACK, true);
    }
}

void Unit::AddExtraAttacks(uint32 count)
{
    ObjectGuid targetGUID = _lastDamagedTargetGuid;
    if (!targetGUID)
    {
        ObjectGuid selection = GetTarget();
        if (!selection.IsEmpty())
            targetGUID = selection; // Spell was cast directly (not triggered by aura)
        else
            return;
    }

    extraAttacksTargets[targetGUID] += count;
}

MeleeHitOutcome Unit::RollMeleeOutcomeAgainst(Unit const* victim, WeaponAttackType attType) const
{
    if (victim->GetTypeId() == TYPEID_UNIT && victim->ToCreature()->IsEvadingAttacks())
        return MELEE_HIT_EVADE;

    // Miss chance based on melee
    int32 miss_chance = int32(MeleeSpellMissChance(victim, attType, nullptr) * 100.0f);

    // Critical hit chance
    int32 crit_chance = int32((GetUnitCriticalChanceAgainst(attType, victim) + GetTotalAuraModifier(SPELL_AURA_MOD_AUTOATTACK_CRIT_CHANCE)) * 100.0f);

    int32 dodge_chance = int32(GetUnitDodgeChance(attType, victim) * 100.0f);
    int32 block_chance = int32(GetUnitBlockChance(attType, victim) * 100.0f);
    int32 parry_chance = int32(GetUnitParryChance(attType, victim) * 100.0f);

    // melee attack table implementation
    // outcome priority:
    //   1. >    2. >    3. >       4. >    5. >   6. >       7. >  8.
    // MISS > DODGE > PARRY > GLANCING > BLOCK > CRIT > CRUSHING > HIT

    int32    sum = 0, tmp = 0;
    int32    roll = urand(0, 9999);

    int32 attackerLevel = GetLevelForTarget(victim);
    int32 victimLevel = GetLevelForTarget(this);

    // check if attack comes from behind, nobody can parry or block if attacker is behind
    bool canParryOrBlock = victim->HasInArc(float(M_PI), this) || victim->HasAuraType(SPELL_AURA_IGNORE_HIT_DIRECTION);

    // only creatures can dodge if attacker is behind
    bool canDodge = victim->GetTypeId() != TYPEID_PLAYER || canParryOrBlock;

    // if victim is casting or cc'd it can't avoid attacks
    if (victim->IsNonMeleeSpellCast(false, false, true) || victim->HasUnitState(UNIT_STATE_CONTROLLED))
    {
        canDodge = false;
        canParryOrBlock = false;
    }

    // 1. MISS
    tmp = miss_chance;
    if (tmp > 0 && roll < (sum += tmp))
        return MELEE_HIT_MISS;

    // always crit against a sitting target (except 0 crit chance)
    if (victim->GetTypeId() == TYPEID_PLAYER && crit_chance > 0 && !victim->IsStandState())
        return MELEE_HIT_CRIT;

    // 2. DODGE
    if (canDodge)
    {
        tmp = dodge_chance;
        if (tmp > 0                                         // check if unit _can_ dodge
            && roll < (sum += tmp))
            return MELEE_HIT_DODGE;
    }

    // 3. PARRY
    if (canParryOrBlock)
    {
        tmp = parry_chance;
        if (tmp > 0                                         // check if unit _can_ parry
            && roll < (sum += tmp))
            return MELEE_HIT_PARRY;
    }

    // 4. GLANCING
    // Max 40% chance to score a glancing blow against mobs that are higher level (can do only players and pets and not with ranged weapon)
    if ((GetTypeId() == TYPEID_PLAYER || IsPet()) &&
        victim->GetTypeId() != TYPEID_PLAYER && !victim->IsPet() &&
        attackerLevel + 3 < victimLevel)
    {
        // cap possible value (with bonuses > max skill)
        tmp = (10 + 10 * (victimLevel - attackerLevel)) * 100;
        if (tmp > 0 && roll < (sum += tmp))
            return MELEE_HIT_GLANCING;
    }

    // 5. BLOCK
    if (canParryOrBlock)
    {
        tmp = block_chance;
        if (tmp > 0                                          // check if unit _can_ block
            && roll < (sum += tmp))
            return MELEE_HIT_BLOCK;
    }

    // 6.CRIT
    tmp = crit_chance;
    if (tmp > 0 && roll < (sum += tmp))
        return MELEE_HIT_CRIT;

    // 7. CRUSHING
    // mobs can score crushing blows if they're 4 or more levels above victim
    if (attackerLevel >= victimLevel + 4 &&
        // can be from by creature (if can) or from controlled player that considered as creature
        !IsControlledByPlayer() &&
        !(GetTypeId() == TYPEID_UNIT && ToCreature()->GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_NO_CRUSHING_BLOWS))
    {
        // add 2% chance per level, min. is 15%
        tmp = attackerLevel - victimLevel * 1000 - 1500;
        if (roll < (sum += tmp))
        {
            TC_LOG_DEBUG("entities.unit", "RollMeleeOutcomeAgainst: CRUSHING <{}, {})", sum-tmp, sum);
            return MELEE_HIT_CRUSHING;
        }
    }

    // 8. HIT
    return MELEE_HIT_NORMAL;
}

uint32 Unit::CalculateDamage(WeaponAttackType attType, bool normalized, bool addTotalPct) const
{
    float minDamage = 0.0f;
    float maxDamage = 0.0f;

    if (normalized || !addTotalPct)
    {
        CalculateMinMaxDamage(attType, normalized, addTotalPct, minDamage, maxDamage);
        if (IsInFeralForm() && attType == BASE_ATTACK)
        {
            float minOffhandDamage = 0.0f;
            float maxOffhandDamage = 0.0f;
            CalculateMinMaxDamage(OFF_ATTACK, normalized, addTotalPct, minOffhandDamage, maxOffhandDamage);
            minDamage += minOffhandDamage;
            maxDamage += maxOffhandDamage;
        }
    }
    else
    {
        switch (attType)
        {
            case RANGED_ATTACK:
                minDamage = m_unitData->MinRangedDamage;
                maxDamage = m_unitData->MaxRangedDamage;
                break;
            case BASE_ATTACK:
                minDamage = m_unitData->MinDamage;
                maxDamage = m_unitData->MaxDamage;
                if (IsInFeralForm())
                {
                    minDamage += m_unitData->MinOffHandDamage;
                    maxDamage += m_unitData->MaxOffHandDamage;
                }
                break;
            case OFF_ATTACK:
                minDamage = m_unitData->MinOffHandDamage;
                maxDamage = m_unitData->MaxOffHandDamage;
                break;
            default:
                break;
        }
    }

    minDamage = std::max(0.f, minDamage);
    maxDamage = std::max(0.f, maxDamage);

    if (minDamage > maxDamage)
        std::swap(minDamage, maxDamage);

    return urand(uint32(minDamage), uint32(maxDamage));
}

void Unit::SendMeleeAttackStart(Unit* victim)
{
    WorldPackets::Combat::AttackStart packet;
    packet.Attacker = GetGUID();
    packet.Victim = victim->GetGUID();
    SendMessageToSet(packet.Write(), true);
}

void Unit::SendMeleeAttackStop(Unit* victim)
{
    SendMessageToSet(WorldPackets::Combat::SAttackStop(this, victim).Write(), true);

    if (victim)
        TC_LOG_DEBUG("entities.unit", "{} stopped attacking {}", GetGUID().ToString(), victim->GetGUID().ToString());
    else
        TC_LOG_DEBUG("entities.unit", "{} stopped attacking", GetGUID().ToString());
}

bool Unit::IsBlockCritical()
{
    if (roll_chance_i(GetTotalAuraModifier(SPELL_AURA_MOD_BLOCK_CRIT_CHANCE)))
        return true;
    return false;
}

int32 Unit::GetMechanicResistChance(SpellInfo const* spellInfo) const
{
    if (!spellInfo)
        return 0;

    int32 resistMech = 0;
    for (SpellEffectInfo const& effect : spellInfo->GetEffects())
    {
        if (!effect.IsEffect())
            break;

        int32 effectMech = spellInfo->GetEffectMechanic(effect.EffectIndex);
        if (effectMech)
        {
            int32 temp = GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_MECHANIC_RESISTANCE, effectMech);
            if (resistMech < temp)
                resistMech = temp;
        }
    }

    return std::max(resistMech, 0);
}

bool Unit::CanUseAttackType(uint8 attacktype) const
{
    switch (attacktype)
    {
        case BASE_ATTACK:
            return !HasUnitFlag(UNIT_FLAG_DISARMED);
        case OFF_ATTACK:
            return !HasUnitFlag2(UNIT_FLAG2_DISARM_OFFHAND);
        case RANGED_ATTACK:
            return !HasUnitFlag2(UNIT_FLAG2_DISARM_RANGED);
        default:
            return true;
    }
}

// Melee based spells hit result calculations
SpellMissInfo Unit::MeleeSpellHitResult(Unit* victim, SpellInfo const* spellInfo) const
{
    if (spellInfo->HasAttribute(SPELL_ATTR3_NO_AVOIDANCE))
        return SPELL_MISS_NONE;

    WeaponAttackType attType = BASE_ATTACK;

    // Check damage class instead of attack type to correctly handle judgements
    // - they are meele, but can't be dodged/parried/deflected because of ranged dmg class
    if (spellInfo->DmgClass == SPELL_DAMAGE_CLASS_RANGED)
        attType = RANGED_ATTACK;

    uint32 roll = urand(0, 9999);

    uint32 missChance = uint32(MeleeSpellMissChance(victim, attType, spellInfo) * 100.0f);

    // Roll miss
    uint32 tmp = missChance;
    if (roll < tmp)
        return SPELL_MISS_MISS;

    // Chance resist mechanic
    int32 resist_chance = victim->GetMechanicResistChance(spellInfo) * 100;
    tmp += resist_chance;
    if (roll < tmp)
        return SPELL_MISS_RESIST;

    // Same spells cannot be parried/dodged
    if (spellInfo->HasAttribute(SPELL_ATTR0_NO_ACTIVE_DEFENSE))
        return SPELL_MISS_NONE;

    bool canDodge = !spellInfo->HasAttribute(SPELL_ATTR7_NO_ATTACK_DODGE);
    bool canParry = !spellInfo->HasAttribute(SPELL_ATTR7_NO_ATTACK_PARRY);
    bool canBlock = !spellInfo->HasAttribute(SPELL_ATTR8_NO_ATTACK_BLOCK);

    // if victim is casting or cc'd it can't avoid attacks
    if (victim->IsNonMeleeSpellCast(false, false, true) || victim->HasUnitState(UNIT_STATE_CONTROLLED))
    {
        canDodge = false;
        canParry = false;
        canBlock = false;
    }

    // Ranged attacks can only miss, resist and deflect and get blocked
    if (attType == RANGED_ATTACK)
    {
        canParry = false;
        canDodge = false;

        // only if in front
        if (!victim->HasUnitState(UNIT_STATE_CONTROLLED) && (victim->HasInArc(float(M_PI), this) || victim->HasAuraType(SPELL_AURA_IGNORE_HIT_DIRECTION)))
        {
            int32 deflect_chance = victim->GetTotalAuraModifier(SPELL_AURA_DEFLECT_SPELLS) * 100;
            tmp += deflect_chance;
            if (roll < tmp)
                return SPELL_MISS_DEFLECT;
        }
    }

    // Check for attack from behind
    if (!victim->HasInArc(float(M_PI), this))
    {
        if (!victim->HasAuraType(SPELL_AURA_IGNORE_HIT_DIRECTION))
        {
            // Can't dodge from behind in PvP (but its possible in PvE)
            if (victim->GetTypeId() == TYPEID_PLAYER)
                canDodge = false;
            // Can't parry or block
            canParry = false;
            canBlock = false;
        }
        else // Only deterrence as of 3.3.5
        {
            if (spellInfo->HasAttribute(SPELL_ATTR0_CU_REQ_CASTER_BEHIND_TARGET))
                canParry = false;
        }
    }

    // Ignore combat result aura
    AuraEffectList const& ignore = GetAuraEffectsByType(SPELL_AURA_IGNORE_COMBAT_RESULT);
    for (AuraEffect const* aurEff : ignore)
    {
        if (!aurEff->IsAffectingSpell(spellInfo))
            continue;

        switch (aurEff->GetMiscValue())
        {
            case MELEE_HIT_DODGE:
                canDodge = false;
                break;
            case MELEE_HIT_BLOCK:
                canBlock = false;
                break;
            case MELEE_HIT_PARRY:
                canParry = false;
                break;
            default:
                TC_LOG_DEBUG("entities.unit", "Spell {} SPELL_AURA_IGNORE_COMBAT_RESULT has unhandled state {}", aurEff->GetId(), aurEff->GetMiscValue());
                break;
        }
    }

    if (canDodge)
    {
        // Roll dodge
        int32 dodgeChance = int32(GetUnitDodgeChance(attType, victim) * 100.0f);
        if (dodgeChance < 0)
            dodgeChance = 0;

        if (roll < (tmp += dodgeChance))
            return SPELL_MISS_DODGE;
    }

    if (canParry)
    {
        // Roll parry
        int32 parryChance = int32(GetUnitParryChance(attType, victim) * 100.0f);
        if (parryChance < 0)
            parryChance = 0;

        tmp += parryChance;
        if (roll < tmp)
            return SPELL_MISS_PARRY;
    }

    if (canBlock)
    {
        int32 blockChance = int32(GetUnitBlockChance(attType, victim) * 100.0f);
        if (blockChance < 0)
            blockChance = 0;
        tmp += blockChance;

        if (roll < tmp)
            return SPELL_MISS_BLOCK;
    }

    return SPELL_MISS_NONE;
}

float Unit::GetUnitDodgeChance(WeaponAttackType attType, Unit const* victim) const
{
    int32 const levelDiff = victim->GetLevelForTarget(this) - GetLevelForTarget(victim);

    float chance = 0.0f;
    float levelBonus = 0.0f;
    if (Player const* playerVictim = victim->ToPlayer())
        chance = playerVictim->m_activePlayerData->DodgePercentage;
    else
    {
        if (!victim->IsTotem())
        {
            chance = 3.0f;
            chance += victim->GetTotalAuraModifier(SPELL_AURA_MOD_DODGE_PERCENT);

            if (levelDiff > 0)
                levelBonus = 1.5f * levelDiff;
        }
    }

    chance += levelBonus;

    // Reduce enemy dodge chance by SPELL_AURA_MOD_COMBAT_RESULT_CHANCE
    chance += GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_COMBAT_RESULT_CHANCE, VICTIMSTATE_DODGE);

    // reduce dodge by SPELL_AURA_MOD_ENEMY_DODGE
    chance += GetTotalAuraModifier(SPELL_AURA_MOD_ENEMY_DODGE);

    // Reduce dodge chance by attacker expertise rating
    if (GetTypeId() == TYPEID_PLAYER)
        chance -= ToPlayer()->GetExpertiseDodgeOrParryReduction(attType);
    else
        chance -= GetTotalAuraModifier(SPELL_AURA_MOD_EXPERTISE) / 4.0f;
    return std::max(chance, 0.0f);
}

float Unit::GetUnitParryChance(WeaponAttackType attType, Unit const* victim) const
{
    int32 const levelDiff = victim->GetLevelForTarget(this) - GetLevelForTarget(victim);

    float chance = 0.0f;
    float levelBonus = 0.0f;
    if (Player const* playerVictim = victim->ToPlayer())
    {
        if (playerVictim->CanParry())
        {
            Item* tmpitem = playerVictim->GetWeaponForAttack(BASE_ATTACK, true);
            if (!tmpitem)
                tmpitem = playerVictim->GetWeaponForAttack(OFF_ATTACK, true);

            if (tmpitem)
                chance = playerVictim->m_activePlayerData->ParryPercentage;
        }
    }
    else
    {
        if (!victim->IsTotem() && !(victim->ToCreature()->GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_NO_PARRY))
        {
            chance = 6.0f;
            chance += victim->GetTotalAuraModifier(SPELL_AURA_MOD_PARRY_PERCENT);

            if (levelDiff > 0)
                levelBonus = 1.5f * levelDiff;
        }
    }

    chance += levelBonus;

    // Reduce parry chance by attacker expertise rating
    if (GetTypeId() == TYPEID_PLAYER)
        chance -= ToPlayer()->GetExpertiseDodgeOrParryReduction(attType);
    else
        chance -= GetTotalAuraModifier(SPELL_AURA_MOD_EXPERTISE) / 4.0f;
    return std::max(chance, 0.0f);
}

float Unit::GetUnitMissChance() const
{
    float miss_chance = 5.0f;

    return miss_chance;
}

float Unit::GetUnitBlockChance(WeaponAttackType /*attType*/, Unit const* victim) const
{
    int32 const levelDiff = victim->GetLevelForTarget(this) - GetLevelForTarget(victim);

    float chance = 0.0f;
    float levelBonus = 0.0f;
    if (Player const* playerVictim = victim->ToPlayer())
    {
        if (playerVictim->CanBlock())
        {
            Item* tmpitem = playerVictim->GetUseableItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
            if (tmpitem && !tmpitem->IsBroken() && tmpitem->GetTemplate()->GetInventoryType() == INVTYPE_SHIELD)
                chance = playerVictim->m_activePlayerData->BlockPercentage;
        }
    }
    else
    {
        if (!victim->IsTotem() && !(victim->ToCreature()->GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_NO_BLOCK))
        {
            chance = 3.0f;
            chance += victim->GetTotalAuraModifier(SPELL_AURA_MOD_BLOCK_PERCENT);

            if (levelDiff > 0)
                levelBonus = 1.5f * levelDiff;
        }
    }

    chance += levelBonus;
    return std::max(chance, 0.0f);
}

float Unit::GetUnitCriticalChanceDone(WeaponAttackType attackType) const
{
    float chance = 0.0f;
    if (Player const* thisPlayer = ToPlayer())
    {
        switch (attackType)
        {
            case BASE_ATTACK:
                chance = thisPlayer->m_activePlayerData->CritPercentage;
                break;
            case OFF_ATTACK:
                chance = thisPlayer->m_activePlayerData->OffhandCritPercentage;
                break;
            case RANGED_ATTACK:
                chance = thisPlayer->m_activePlayerData->RangedCritPercentage;
                break;
                // Just for good manner
            default:
                chance = 0.0f;
                break;
        }
    }
    else
    {
        if (!(ToCreature()->GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_NO_CRIT))
        {
            chance = 5.0f;
            chance += GetTotalAuraModifier(SPELL_AURA_MOD_WEAPON_CRIT_PERCENT);
            chance += GetTotalAuraModifier(SPELL_AURA_MOD_CRIT_PCT);
        }
    }

    return chance;
}

float Unit::GetUnitCriticalChanceTaken(Unit const* attacker, WeaponAttackType attackType, float critDone) const
{
    float chance = critDone;

    // flat aura mods
    if (attackType != RANGED_ATTACK)
        chance += GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_MELEE_CRIT_CHANCE);

    chance += GetTotalAuraModifier(SPELL_AURA_MOD_CRIT_CHANCE_VERSUS_TARGET_HEALTH, [this](AuraEffect const* aurEff)
    {
        return !HealthBelowPct(aurEff->GetMiscValueB());
    });

    chance += GetTotalAuraModifier(SPELL_AURA_MOD_CRIT_CHANCE_FOR_CASTER, [attacker](AuraEffect const* aurEff) -> bool
    {
        return aurEff->GetCasterGUID() == attacker->GetGUID();
    });

    if (TempSummon const* tempSummon = attacker->ToTempSummon())
    {
        chance += GetTotalAuraModifier(SPELL_AURA_MOD_CRIT_CHANCE_FOR_CASTER_PET, [tempSummon](AuraEffect const* aurEff) -> bool
        {
            return aurEff->GetCasterGUID() == tempSummon->GetSummonerGUID();
        });
    }

    chance += GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_SPELL_AND_WEAPON_CRIT_CHANCE);

    return std::max(chance, 0.0f);
}

float Unit::GetUnitCriticalChanceAgainst(WeaponAttackType attackType, Unit const* victim) const
{
    float chance = GetUnitCriticalChanceDone(attackType);
    return victim->GetUnitCriticalChanceTaken(this, attackType, chance);
}

void Unit::_DeleteRemovedAuras()
{
    while (!m_removedAuras.empty())
    {
        delete m_removedAuras.front();
        m_removedAuras.pop_front();
    }

    m_removedAurasCount = 0;
}

void Unit::_UpdateSpells(uint32 time)
{
    if (!_spellHistory->IsPaused())
        _spellHistory->Update();

    if (m_currentSpells[CURRENT_AUTOREPEAT_SPELL])
        _UpdateAutoRepeatSpell();

    // remove finished spells from current pointers
    for (uint32 i = 0; i < CURRENT_MAX_SPELL; ++i)
    {
        if (m_currentSpells[i] && m_currentSpells[i]->getState() == SPELL_STATE_FINISHED)
        {
            m_currentSpells[i]->SetReferencedFromCurrent(false);
            m_currentSpells[i] = nullptr;                      // remove pointer
        }
    }

    // m_auraUpdateIterator can be updated in indirect called code at aura remove to skip next planned to update but removed auras
    for (m_auraUpdateIterator = m_ownedAuras.begin(); m_auraUpdateIterator != m_ownedAuras.end();)
    {
        Aura* i_aura = m_auraUpdateIterator->second;
        ++m_auraUpdateIterator;                            // need shift to next for allow update if need into aura update
        i_aura->UpdateOwner(time, this);
    }

    // remove expired auras - do that after updates(used in scripts?)
    for (AuraMap::iterator i = m_ownedAuras.begin(); i != m_ownedAuras.end();)
    {
        if (i->second->IsExpired())
            RemoveOwnedAura(i, AURA_REMOVE_BY_EXPIRE);
        else if (i->second->GetSpellInfo()->IsChanneled() && i->second->GetCasterGUID() != GetGUID() && !ObjectAccessor::GetWorldObject(*this, i->second->GetCasterGUID()))
            RemoveOwnedAura(i, AURA_REMOVE_BY_CANCEL); // remove channeled auras when caster is not on the same map
        else
            ++i;
    }

    for (AuraApplication* visibleAura : m_visibleAurasToUpdate)
        visibleAura->ClientUpdate();

    m_visibleAurasToUpdate.clear();

    _DeleteRemovedAuras();

    if (!m_gameObj.empty())
    {
        GameObjectList::iterator itr;
        for (itr = m_gameObj.begin(); itr != m_gameObj.end();)
        {
            if (!(*itr)->isSpawned())
            {
                (*itr)->SetOwnerGUID(ObjectGuid::Empty);
                (*itr)->SetRespawnTime(0);
                (*itr)->Delete();
                m_gameObj.erase(itr++);
            }
            else
                ++itr;
        }
    }
}

void Unit::_UpdateAutoRepeatSpell()
{
    SpellInfo const* autoRepeatSpellInfo = m_currentSpells[CURRENT_AUTOREPEAT_SPELL]->m_spellInfo;

    // check "realtime" interrupts
    // don't cancel spells which are affected by a SPELL_AURA_CAST_WHILE_WALKING effect
    if ((isMoving() && m_currentSpells[CURRENT_AUTOREPEAT_SPELL]->CheckMovement() != SPELL_CAST_OK) || IsNonMeleeSpellCast(false, false, true, autoRepeatSpellInfo->Id == 75))
    {
        // cancel wand shoot
        if (autoRepeatSpellInfo->Id != 75)
            InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
        return;
    }

    // castroutine
    if (isAttackReady(RANGED_ATTACK) && m_currentSpells[CURRENT_AUTOREPEAT_SPELL]->getState() != SPELL_STATE_PREPARING)
    {
        // Check if able to cast
        SpellCastResult result = m_currentSpells[CURRENT_AUTOREPEAT_SPELL]->CheckCast(true);
        if (result != SPELL_CAST_OK)
        {
            if (autoRepeatSpellInfo->Id != 75)
                InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
            else if (GetTypeId() == TYPEID_PLAYER)
                Spell::SendCastResult(ToPlayer(), autoRepeatSpellInfo, m_currentSpells[CURRENT_AUTOREPEAT_SPELL]->m_SpellVisual, m_currentSpells[CURRENT_AUTOREPEAT_SPELL]->m_castId, result);

            return;
        }

        // we want to shoot
        Spell* spell = new Spell(this, autoRepeatSpellInfo, TRIGGERED_IGNORE_GCD);
        spell->prepare(m_currentSpells[CURRENT_AUTOREPEAT_SPELL]->m_targets);
    }
}

void Unit::SetCurrentCastSpell(Spell* pSpell)
{
    ASSERT(pSpell);                                         // NULL may be never passed here, use InterruptSpell or InterruptNonMeleeSpells

    CurrentSpellTypes CSpellType = pSpell->GetCurrentContainer();

    if (pSpell == m_currentSpells[CSpellType])             // avoid breaking self
        return;

    // special breakage effects:
    switch (CSpellType)
    {
        case CURRENT_GENERIC_SPELL:
        {
            InterruptSpell(CURRENT_GENERIC_SPELL, false);

            // generic spells always break channeled not delayed spells
            if (m_currentSpells[CURRENT_CHANNELED_SPELL] && !m_currentSpells[CURRENT_CHANNELED_SPELL]->GetSpellInfo()->HasAttribute(SPELL_ATTR5_ALLOW_ACTIONS_DURING_CHANNEL))
                InterruptSpell(CURRENT_CHANNELED_SPELL, false);

            // autorepeat breaking
            if (m_currentSpells[CURRENT_AUTOREPEAT_SPELL])
            {
                // break autorepeat if not Auto Shot
                if (m_currentSpells[CURRENT_AUTOREPEAT_SPELL]->GetSpellInfo()->Id != 75)
                    InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
            }
            if (pSpell->GetCastTime() > 0)
                AddUnitState(UNIT_STATE_CASTING);

            break;
        }
        case CURRENT_CHANNELED_SPELL:
        {
            // channel spells always break generic non-delayed and any channeled spells
            InterruptSpell(CURRENT_GENERIC_SPELL, false);
            InterruptSpell(CURRENT_CHANNELED_SPELL);

            // it also does break autorepeat if not Auto Shot
            if (m_currentSpells[CURRENT_AUTOREPEAT_SPELL] &&
                m_currentSpells[CURRENT_AUTOREPEAT_SPELL]->GetSpellInfo()->Id != 75)
                InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
            AddUnitState(UNIT_STATE_CASTING);

            break;
        }
        case CURRENT_AUTOREPEAT_SPELL:
        {
            if (m_currentSpells[CSpellType] && m_currentSpells[CSpellType]->getState() == SPELL_STATE_IDLE)
                m_currentSpells[CSpellType]->setState(SPELL_STATE_FINISHED);

            // only Auto Shoot does not break anything
            if (pSpell->GetSpellInfo()->Id != 75)
            {
                // generic autorepeats break generic non-delayed and channeled non-delayed spells
                InterruptSpell(CURRENT_GENERIC_SPELL, false);
                InterruptSpell(CURRENT_CHANNELED_SPELL, false);
            }

            break;
        }
        default:
            break; // other spell types don't break anything now
    }

    // current spell (if it is still here) may be safely deleted now
    if (m_currentSpells[CSpellType])
        m_currentSpells[CSpellType]->SetReferencedFromCurrent(false);

    // set new current spell
    m_currentSpells[CSpellType] = pSpell;
    pSpell->SetReferencedFromCurrent(true);

    pSpell->m_selfContainer = &(m_currentSpells[pSpell->GetCurrentContainer()]);
}

void Unit::InterruptSpell(CurrentSpellTypes spellType, bool withDelayed, bool withInstant)
{
    //TC_LOG_DEBUG("entities.unit", "Interrupt spell for unit {}.", GetEntry());
    Spell* spell = m_currentSpells[spellType];
    if (spell
        && (withDelayed || spell->getState() != SPELL_STATE_DELAYED)
        && (withInstant || spell->GetCastTime() > 0 || spell->getState() == SPELL_STATE_CASTING))
    {
        // for example, do not let self-stun aura interrupt itself
        if (!spell->IsInterruptable())
            return;

        // send autorepeat cancel message for autorepeat spells
        if (spellType == CURRENT_AUTOREPEAT_SPELL)
            if (GetTypeId() == TYPEID_PLAYER)
                ToPlayer()->SendAutoRepeatCancel(this);

        if (spell->getState() != SPELL_STATE_FINISHED)
            spell->cancel();
        else
        {
            m_currentSpells[spellType] = nullptr;
            spell->SetReferencedFromCurrent(false);
        }

        if (GetTypeId() == TYPEID_UNIT && IsAIEnabled())
            ToCreature()->AI()->OnSpellFailed(spell->GetSpellInfo());
    }
}

void Unit::FinishSpell(CurrentSpellTypes spellType, SpellCastResult result /*= SPELL_CAST_OK*/)
{
    Spell* spell = m_currentSpells[spellType];
    if (!spell)
        return;

    if (spellType == CURRENT_CHANNELED_SPELL)
        spell->SendChannelUpdate(0);

    spell->finish(result);
}

bool Unit::IsNonMeleeSpellCast(bool withDelayed, bool skipChanneled, bool skipAutorepeat, bool isAutoshoot, bool skipInstant) const
{
    // We don't do loop here to explicitly show that melee spell is excluded.
    // Maybe later some special spells will be excluded too.

    // generic spells are cast when they are not finished and not delayed
    if (m_currentSpells[CURRENT_GENERIC_SPELL] &&
        (m_currentSpells[CURRENT_GENERIC_SPELL]->getState() != SPELL_STATE_FINISHED) &&
        (withDelayed || m_currentSpells[CURRENT_GENERIC_SPELL]->getState() != SPELL_STATE_DELAYED))
    {
        if (!skipInstant || m_currentSpells[CURRENT_GENERIC_SPELL]->GetCastTime())
        {
            if (!isAutoshoot || !(m_currentSpells[CURRENT_GENERIC_SPELL]->m_spellInfo->HasAttribute(SPELL_ATTR2_DO_NOT_RESET_COMBAT_TIMERS)))
                return true;
        }
    }
    // channeled spells may be delayed, but they are still considered cast
    if (!skipChanneled && m_currentSpells[CURRENT_CHANNELED_SPELL] &&
        (m_currentSpells[CURRENT_CHANNELED_SPELL]->getState() != SPELL_STATE_FINISHED))
    {
        if (!isAutoshoot || !(m_currentSpells[CURRENT_CHANNELED_SPELL]->m_spellInfo->HasAttribute(SPELL_ATTR2_DO_NOT_RESET_COMBAT_TIMERS)))
            return true;
    }
    // autorepeat spells may be finished or delayed, but they are still considered cast
    if (!skipAutorepeat && m_currentSpells[CURRENT_AUTOREPEAT_SPELL])
        return true;

    return false;
}

void Unit::InterruptNonMeleeSpells(bool withDelayed, uint32 spell_id, bool withInstant)
{
    // generic spells are interrupted if they are not finished or delayed
    if (m_currentSpells[CURRENT_GENERIC_SPELL] && (!spell_id || m_currentSpells[CURRENT_GENERIC_SPELL]->m_spellInfo->Id == spell_id))
        InterruptSpell(CURRENT_GENERIC_SPELL, withDelayed, withInstant);

    // autorepeat spells are interrupted if they are not finished or delayed
    if (m_currentSpells[CURRENT_AUTOREPEAT_SPELL] && (!spell_id || m_currentSpells[CURRENT_AUTOREPEAT_SPELL]->m_spellInfo->Id == spell_id))
        InterruptSpell(CURRENT_AUTOREPEAT_SPELL, withDelayed, withInstant);

    // channeled spells are interrupted if they are not finished, even if they are delayed
    if (m_currentSpells[CURRENT_CHANNELED_SPELL] && (!spell_id || m_currentSpells[CURRENT_CHANNELED_SPELL]->m_spellInfo->Id == spell_id))
        InterruptSpell(CURRENT_CHANNELED_SPELL, true, true);
}

Spell* Unit::FindCurrentSpellBySpellId(uint32 spell_id) const
{
    for (uint32 i = 0; i < CURRENT_MAX_SPELL; i++)
        if (m_currentSpells[i] && m_currentSpells[i]->m_spellInfo->Id == spell_id)
            return m_currentSpells[i];
    return nullptr;
}

int32 Unit::GetCurrentSpellCastTime(uint32 spell_id) const
{
    if (Spell const* spell = FindCurrentSpellBySpellId(spell_id))
        return spell->GetCastTime();
    return 0;
}

bool Unit::IsMovementPreventedByCasting() const
{
    // can always move when not casting
    if (!HasUnitState(UNIT_STATE_CASTING))
        return false;

    if (Spell* spell = m_currentSpells[CURRENT_GENERIC_SPELL])
        if (CanCastSpellWhileMoving(spell->GetSpellInfo()) || spell->getState() == SPELL_STATE_FINISHED ||
            !spell->m_spellInfo->InterruptFlags.HasFlag(SpellInterruptFlags::Movement))
            return false;

    // channeled spells during channel stage (after the initial cast timer) allow movement with a specific spell attribute
    if (Spell* spell = m_currentSpells[CURRENT_CHANNELED_SPELL])
        if (spell->getState() != SPELL_STATE_FINISHED && spell->IsChannelActive())
            if (spell->GetSpellInfo()->IsMoveAllowedChannel() || CanCastSpellWhileMoving(spell->GetSpellInfo()))
                return false;

    // prohibit movement for all other spell casts
    return true;
}

bool Unit::CanCastSpellWhileMoving(SpellInfo const* spellInfo) const
{
    if (HasAuraTypeWithAffectMask(SPELL_AURA_CAST_WHILE_WALKING, spellInfo))
        return true;

    if (HasAuraType(SPELL_AURA_CAST_WHILE_WALKING_ALL))
        return true;

    for (uint32 label : spellInfo->Labels)
        if (HasAuraTypeWithMiscvalue(SPELL_AURA_CAST_WHILE_WALKING_BY_SPELL_LABEL, label))
            return true;

    return false;
}

bool Unit::isInFrontInMap(Unit const* target, float distance,  float arc) const
{
    return IsWithinDistInMap(target, distance) && HasInArc(arc, target);
}

bool Unit::isInBackInMap(Unit const* target, float distance, float arc) const
{
    return IsWithinDistInMap(target, distance) && !HasInArc(2 * float(M_PI) - arc, target);
}

bool Unit::isInAccessiblePlaceFor(Creature const* c) const
{
    // Aquatic creatures are not allowed to leave liquids
    if (!IsInWater() && c->IsAquatic())
        return false;

    // Underwater special case. Some creatures may not go below liquid surfaces
    if (IsUnderWater() && c->CannotPenetrateWater())
        return false;

    // Water checks
    if (IsInWater() && !c->CanEnterWater())
        return false;

    // Some creatures are tied to the ocean floor and cannot chase swimming targets.
    if (!IsOnOceanFloor() && c->IsUnderWater() && c->HasUnitFlag(UNIT_FLAG_CANT_SWIM))
        return false;

    return true;
}

bool Unit::IsInWater() const
{
    return GetLiquidStatus() & (LIQUID_MAP_IN_WATER | LIQUID_MAP_UNDER_WATER);
}

bool Unit::IsUnderWater() const
{
    return GetLiquidStatus() & LIQUID_MAP_UNDER_WATER;
}

bool Unit::IsOnOceanFloor() const
{
    return GetLiquidStatus() & LIQUID_MAP_OCEAN_FLOOR;
}

void Unit::ProcessPositionDataChanged(PositionFullTerrainStatus const& data)
{
    ZLiquidStatus oldLiquidStatus = GetLiquidStatus();
    WorldObject::ProcessPositionDataChanged(data);
    ProcessTerrainStatusUpdate(oldLiquidStatus, data.liquidInfo);
}

void Unit::ProcessTerrainStatusUpdate(ZLiquidStatus oldLiquidStatus, Optional<LiquidData> const& newLiquidData)
{
    if (!IsControlledByPlayer())
        return;

    // remove appropriate auras if we are swimming/not swimming respectively
    if (IsInWater())
        RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::UnderWater);
    else
        RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::AboveWater);

    // liquid aura handling
    LiquidTypeEntry const* curLiquid = nullptr;
    if (IsInWater() && newLiquidData)
        curLiquid = sLiquidTypeStore.LookupEntry(newLiquidData->entry);
    if (curLiquid != _lastLiquid)
    {
        if (_lastLiquid && _lastLiquid->SpellID)
            RemoveAurasDueToSpell(_lastLiquid->SpellID);
        Player* player = GetCharmerOrOwnerPlayerOrPlayerItself();

        // Set _lastLiquid before casting liquid spell to avoid infinite loops
        _lastLiquid = curLiquid;

        if (curLiquid && curLiquid->SpellID && (!player || !player->IsGameMaster()))
            CastSpell(this, curLiquid->SpellID, true);
    }

    // mount capability depends on liquid state change
    if (oldLiquidStatus != GetLiquidStatus())
        UpdateMountCapability();
}

void Unit::DeMorph()
{
    SetDisplayId(GetNativeDisplayId());
}

Aura* Unit::_TryStackingOrRefreshingExistingAura(AuraCreateInfo& createInfo)
{
    ASSERT(!createInfo.CasterGUID.IsEmpty() || createInfo.Caster);

    // Check if these can stack anyway
    if (!createInfo.CasterGUID && !createInfo.GetSpellInfo()->IsStackableOnOneSlotWithDifferentCasters())
        createInfo.CasterGUID = createInfo.Caster->GetGUID();

    // passive and Incanter's Absorption and auras with different type can stack with themselves any number of times
    if (!createInfo.GetSpellInfo()->IsMultiSlotAura())
    {
        // check if cast item changed
        ObjectGuid castItemGUID = createInfo.CastItemGUID;

        // find current aura from spell and change it's stackamount, or refresh it's duration
        if (Aura* foundAura = GetOwnedAura(createInfo.GetSpellInfo()->Id, createInfo.GetSpellInfo()->IsStackableOnOneSlotWithDifferentCasters() ? ObjectGuid::Empty : createInfo.CasterGUID, createInfo.GetSpellInfo()->HasAttribute(SPELL_ATTR0_CU_ENCHANT_PROC) ? castItemGUID : ObjectGuid::Empty, 0))
        {
            // effect masks do not match
            // extremely rare case
            // let's just recreate aura
            if (createInfo.GetAuraEffectMask() != foundAura->GetEffectMask())
                return nullptr;

            // update basepoints with new values - effect amount will be recalculated in ModStackAmount
            for (SpellEffectInfo const& spellEffectInfo : createInfo.GetSpellInfo()->GetEffects())
            {
                AuraEffect const* auraEff = foundAura->GetEffect(spellEffectInfo.EffectIndex);
                if (!auraEff)
                    continue;

                int32 bp;
                if (createInfo.BaseAmount)
                    bp = *(createInfo.BaseAmount + spellEffectInfo.EffectIndex);
                else
                    bp = int32(spellEffectInfo.BasePoints);

                int32* oldBP = const_cast<int32*>(&(auraEff->m_baseAmount));
                if (spellEffectInfo.EffectAttributes.HasFlag(SpellEffectAttributes::AuraPointsStack))
                    *oldBP += bp;
                else
                    *oldBP = bp;
            }

            // correct cast item guid if needed
            if (castItemGUID != foundAura->GetCastItemGUID())
            {
                ObjectGuid* oldGUID = const_cast<ObjectGuid*>(&foundAura->m_castItemGuid);
                *oldGUID = castItemGUID;
                uint32* oldItemId = const_cast<uint32*>(&foundAura->m_castItemId);
                *oldItemId = createInfo.CastItemId;
                int32* oldItemLevel = const_cast<int32*>(&foundAura->m_castItemLevel);
                *oldItemLevel = createInfo.CastItemLevel;
            }

            // try to increase stack amount
            foundAura->ModStackAmount(1, AURA_REMOVE_BY_DEFAULT, createInfo.ResetPeriodicTimer);
            return foundAura;
        }
    }

    return nullptr;
}

void Unit::_AddAura(UnitAura* aura, Unit* caster)
{
    ASSERT(!m_cleanupDone);
    m_ownedAuras.emplace(aura->GetId(), aura);

    _RemoveNoStackAurasDueToAura(aura, true);

    if (aura->IsRemoved())
        return;

    aura->SetIsSingleTarget(caster && aura->GetSpellInfo()->IsSingleTarget());
    if (aura->IsSingleTarget())
    {
        ASSERT((IsInWorld() && !IsDuringRemoveFromWorld()) || aura->GetCasterGUID() == GetGUID());
                /* @HACK: Player is not in world during loading auras.
                 *        Single target auras are not saved or loaded from database
                 *        but may be created as a result of aura links.
                 */

        std::vector<Aura*> aurasSharingLimit;
        // remove other single target auras
        for (Aura* scAura : caster->GetSingleCastAuras())
            if (scAura->IsSingleTargetWith(aura))
                aurasSharingLimit.push_back(scAura);

        // register single target aura
        caster->GetSingleCastAuras().push_front(aura);

        uint32 maxOtherAuras = aura->GetSpellInfo()->MaxAffectedTargets - 1;
        while (aurasSharingLimit.size() > maxOtherAuras)
        {
            aurasSharingLimit.back()->Remove();
            aurasSharingLimit.pop_back();
        }
    }
}

// creates aura application instance and registers it in lists
// aura application effects are handled separately to prevent aura list corruption
AuraApplication* Unit::_CreateAuraApplication(Aura* aura, uint32 effMask)
{
    // can't apply aura on unit which is going to be deleted - to not create a memory leak
    ASSERT(!m_cleanupDone);

    // just return if the aura has been already removed
    // this can happen if OnEffectHitTarget() script hook killed the unit or the aura owner (which can be different)
    if (aura->IsRemoved())
    {
        TC_LOG_ERROR("spells", "Unit::_CreateAuraApplication() called with a removed aura. Check if OnEffectHitTarget() is triggering any spell with apply aura effect (that's not allowed!)\nUnit: {}\nAura: {}", GetDebugInfo(), aura->GetDebugInfo());
        return nullptr;
    }

    // aura mustn't be already applied on target
    ASSERT (!aura->IsAppliedOnTarget(GetGUID()) && "Unit::_CreateAuraApplication: aura musn't be applied on target");

    SpellInfo const* aurSpellInfo = aura->GetSpellInfo();
    uint32 aurId = aurSpellInfo->Id;

    // ghost spell check, allow apply any auras at player loading in ghost mode (will be cleanup after load)
    if (!IsAlive() && !aurSpellInfo->IsDeathPersistent() &&
        (GetTypeId() != TYPEID_PLAYER || !ToPlayer()->GetSession()->PlayerLoading()))
        return nullptr;

    Unit* caster = aura->GetCaster();

    AuraApplication * aurApp = new AuraApplication(this, caster, aura, effMask);
    m_appliedAuras.insert(AuraApplicationMap::value_type(aurId, aurApp));

    if (aurSpellInfo->HasAnyAuraInterruptFlag())
    {
        m_interruptableAuras.push_front(aurApp);
        AddInterruptMask(aurSpellInfo->AuraInterruptFlags, aurSpellInfo->AuraInterruptFlags2);
    }

    if (AuraStateType aState = aura->GetSpellInfo()->GetAuraState())
        m_auraStateAuras.insert(AuraStateAurasMap::value_type(aState, aurApp));

    aura->_ApplyForTarget(this, caster, aurApp);
    return aurApp;
}

void Unit::_ApplyAuraEffect(Aura* aura, uint8 effIndex)
{
    ASSERT(aura);
    ASSERT(aura->HasEffect(effIndex));
    AuraApplication * aurApp = aura->GetApplicationOfTarget(GetGUID());
    ASSERT(aurApp);
    if (!aurApp->GetEffectMask())
        _ApplyAura(aurApp, 1 << effIndex);
    else
        aurApp->_HandleEffect(effIndex, true);
}

// handles effects of aura application
// should be done after registering aura in lists
void Unit::_ApplyAura(AuraApplication* aurApp, uint32 effMask)
{
    Aura* aura = aurApp->GetBase();

    _RemoveNoStackAurasDueToAura(aura, false);

    if (aurApp->GetRemoveMode())
        return;

    // Update target aura state flag
    if (AuraStateType aState = aura->GetSpellInfo()->GetAuraState())
    {
        uint32 aStateMask = (1 << (aState - 1));
        // force update so the new caster registers it
        if ((aStateMask & PER_CASTER_AURA_STATE_MASK) && *m_unitData->AuraState & aStateMask)
            ForceUpdateFieldChange(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::AuraState));
        else
            ModifyAuraState(aState, true);
    }

    if (aurApp->GetRemoveMode())
        return;

    // Sitdown on apply aura req seated
    if (aura->GetSpellInfo()->HasAuraInterruptFlag(SpellAuraInterruptFlags::Standing) && !IsSitState())
        SetStandState(UNIT_STAND_STATE_SIT);

    Unit* caster = aura->GetCaster();

    if (aurApp->GetRemoveMode())
        return;

    aura->HandleAuraSpecificMods(aurApp, caster, true, false);

    // apply effects of the aura
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
    {
        if (effMask & 1 << i && (!aurApp->GetRemoveMode()))
            aurApp->_HandleEffect(i, true);
    }

    if (Player* player = ToPlayer())
    {
        if (sConditionMgr->IsSpellUsedInSpellClickConditions(aurApp->GetBase()->GetId()))
            player->UpdateVisibleObjectInteractions(false, true, false, false);

        player->FailCriteria(CriteriaFailEvent::GainAura, aurApp->GetBase()->GetId());
        player->StartCriteria(CriteriaStartEvent::GainAura, aurApp->GetBase()->GetId());
        player->UpdateCriteria(CriteriaType::GainAura, aurApp->GetBase()->GetId());
    }
}

// removes aura application from lists and unapplies effects
void Unit::_UnapplyAura(AuraApplicationMap::iterator& i, AuraRemoveMode removeMode)
{
    AuraApplication * aurApp = i->second;
    ASSERT(aurApp);
    ASSERT(!aurApp->GetRemoveMode());
    ASSERT(aurApp->GetTarget() == this);

    aurApp->SetRemoveMode(removeMode);
    Aura* aura = aurApp->GetBase();
    TC_LOG_DEBUG("spells", "Aura {} now is remove mode {}", aura->GetId(), removeMode);

    // dead loop is killing the server probably
    ASSERT(m_removedAurasCount < 0xFFFFFFFF);

    ++m_removedAurasCount;

    Unit* caster = aura->GetCaster();

    // Remove all pointers from lists here to prevent possible pointer invalidation on spellcast/auraapply/auraremove
    m_appliedAuras.erase(i);

    if (aura->GetSpellInfo()->HasAnyAuraInterruptFlag())
    {
        Trinity::Containers::Lists::RemoveUnique(m_interruptableAuras, aurApp);
        UpdateInterruptMask();
    }

    bool auraStateFound = false;
    AuraStateType auraState = aura->GetSpellInfo()->GetAuraState();
    if (auraState)
    {
        bool canBreak = false;
        // Get mask of all aurastates from remaining auras
        for (AuraStateAurasMap::iterator itr = m_auraStateAuras.lower_bound(auraState); itr != m_auraStateAuras.upper_bound(auraState) && !(auraStateFound && canBreak);)
        {
            if (itr->second == aurApp)
            {
                m_auraStateAuras.erase(itr);
                itr = m_auraStateAuras.lower_bound(auraState);
                canBreak = true;
                continue;
            }
            auraStateFound = true;
            ++itr;
        }
    }

    aurApp->_Remove();
    aura->_UnapplyForTarget(this, caster, aurApp);

    // remove effects of the spell - needs to be done after removing aura from lists
    for (uint8 itr = 0; itr < MAX_SPELL_EFFECTS; ++itr)
    {
        if (aurApp->HasEffect(itr))
            aurApp->_HandleEffect(itr, false);
    }

    // all effect mustn't be applied
    ASSERT(!aurApp->GetEffectMask());

    // Remove totem at next update if totem loses its aura
    if (aurApp->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE && GetTypeId() == TYPEID_UNIT && IsTotem())
    {
        if (ToTotem()->GetSpell() == aura->GetId() && ToTotem()->GetTotemType() == TOTEM_PASSIVE)
            ToTotem()->setDeathState(JUST_DIED);
    }

    // Remove aurastates only if needed and were not found
    if (auraState)
    {
        if (!auraStateFound)
            ModifyAuraState(auraState, false);
        else
        {
            // update for casters, some shouldn't 'see' the aura state
            uint32 aStateMask = (1 << (auraState - 1));
            if ((aStateMask & PER_CASTER_AURA_STATE_MASK) != 0)
                ForceUpdateFieldChange(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::AuraState));
        }
    }

    aura->HandleAuraSpecificMods(aurApp, caster, false, false);

    if (Player* player = ToPlayer())
    {
        if (sConditionMgr->IsSpellUsedInSpellClickConditions(aurApp->GetBase()->GetId()))
            player->UpdateVisibleObjectInteractions(false, true, false, false);

        player->FailCriteria(CriteriaFailEvent::LoseAura, aurApp->GetBase()->GetId());
    }

    i = m_appliedAuras.begin();
}

void Unit::_UnapplyAura(AuraApplication* aurApp, AuraRemoveMode removeMode)
{
    // aura can be removed from unit only if it's applied on it, shouldn't happen
    ASSERT(aurApp->GetBase()->GetApplicationOfTarget(GetGUID()) == aurApp);

    uint32 spellId = aurApp->GetBase()->GetId();
    AuraApplicationMapBoundsNonConst range = m_appliedAuras.equal_range(spellId);

    for (AuraApplicationMap::iterator iter = range.first; iter != range.second;)
    {
        if (iter->second == aurApp)
        {
            _UnapplyAura(iter, removeMode);
            return;
        }
        else
            ++iter;
    }
    ABORT();
}

void Unit::_RemoveNoStackAurasDueToAura(Aura* aura, bool owned)
{
    SpellInfo const* spellProto = aura->GetSpellInfo();

    // passive spell special case (only non stackable with ranks)
    if (spellProto->IsPassiveStackableWithRanks())
        return;

    if (!IsHighestExclusiveAura(aura))
    {
        aura->Remove();
        return;
    }

    if (owned)
        RemoveOwnedAuras([aura](Aura const* ownedAura) { return !aura->CanStackWith(ownedAura); }, AURA_REMOVE_BY_DEFAULT);
    else
        RemoveAppliedAuras([aura](AuraApplication const* appliedAura) { return !aura->CanStackWith(appliedAura->GetBase()); }, AURA_REMOVE_BY_DEFAULT);
}

void Unit::_RegisterAuraEffect(AuraEffect* aurEff, bool apply)
{
    if (apply)
    {
        m_modAuras[aurEff->GetAuraType()].push_front(aurEff);
        if (Player* player = ToPlayer())
        {
            player->StartCriteria(CriteriaStartEvent::GainAuraEffect, aurEff->GetAuraType());
            player->FailCriteria(CriteriaFailEvent::GainAuraEffect, aurEff->GetAuraType());
        }
    }
    else
        Trinity::Containers::Lists::RemoveUnique(m_modAuras[aurEff->GetAuraType()], aurEff);
}

// All aura base removes should go through this function!
void Unit::RemoveOwnedAura(AuraMap::iterator& i, AuraRemoveMode removeMode)
{
    Aura* aura = i->second;
    ASSERT(!aura->IsRemoved());

    // if unit currently update aura list then make safe update iterator shift to next
    if (m_auraUpdateIterator == i)
        ++m_auraUpdateIterator;

    m_ownedAuras.erase(i);
    m_removedAuras.push_front(aura);

    // Unregister single target aura
    if (aura->IsSingleTarget())
        aura->UnregisterSingleTarget();

    aura->_Remove(removeMode);

    i = m_ownedAuras.begin();
}

void Unit::RemoveOwnedAura(uint32 spellId, ObjectGuid casterGUID, uint32 reqEffMask, AuraRemoveMode removeMode)
{
    for (AuraMap::iterator itr = m_ownedAuras.lower_bound(spellId); itr != m_ownedAuras.upper_bound(spellId);)
        if (((itr->second->GetEffectMask() & reqEffMask) == reqEffMask) && (!casterGUID || itr->second->GetCasterGUID() == casterGUID))
        {
            RemoveOwnedAura(itr, removeMode);
            itr = m_ownedAuras.lower_bound(spellId);
        }
        else
            ++itr;
}

void Unit::RemoveOwnedAura(Aura* aura, AuraRemoveMode removeMode)
{
    if (aura->IsRemoved())
        return;

    ASSERT(aura->GetOwner() == this);

    if (removeMode == AURA_REMOVE_NONE)
    {
        TC_LOG_ERROR("spells", "Unit::RemoveOwnedAura() called with unallowed removeMode AURA_REMOVE_NONE, spellId {}", aura->GetId());
        return;
    }

    uint32 spellId = aura->GetId();
    AuraMapBoundsNonConst range = m_ownedAuras.equal_range(spellId);

    for (AuraMap::iterator itr = range.first; itr != range.second; ++itr)
    {
        if (itr->second == aura)
        {
            RemoveOwnedAura(itr, removeMode);
            return;
        }
    }

    ABORT();
}

Aura* Unit::GetOwnedAura(uint32 spellId, ObjectGuid casterGUID, ObjectGuid itemCasterGUID, uint32 reqEffMask, Aura* except) const
{
    AuraMapBounds range = m_ownedAuras.equal_range(spellId);
    for (AuraMap::const_iterator itr = range.first; itr != range.second; ++itr)
    {
        if (((itr->second->GetEffectMask() & reqEffMask) == reqEffMask)
                && (!casterGUID || itr->second->GetCasterGUID() == casterGUID)
                && (!itemCasterGUID || itr->second->GetCastItemGUID() == itemCasterGUID)
                && (!except || except != itr->second))
        {
            return itr->second;
        }
    }
    return nullptr;
}

void Unit::RemoveAura(AuraApplicationMap::iterator &i, AuraRemoveMode mode)
{
    AuraApplication * aurApp = i->second;
    // Do not remove aura which is already being removed
    if (aurApp->GetRemoveMode())
        return;
    Aura* aura = aurApp->GetBase();
    _UnapplyAura(i, mode);
    // Remove aura - for Area and Target auras
    if (aura->GetOwner() == this)
        aura->Remove(mode);
}

void Unit::RemoveAura(uint32 spellId, ObjectGuid caster, uint32 reqEffMask, AuraRemoveMode removeMode)
{
    AuraApplicationMapBoundsNonConst range = m_appliedAuras.equal_range(spellId);
    for (AuraApplicationMap::iterator iter = range.first; iter != range.second;)
    {
        Aura const* aura = iter->second->GetBase();
        if (((aura->GetEffectMask() & reqEffMask) == reqEffMask)
                && (!caster || aura->GetCasterGUID() == caster))
        {
            RemoveAura(iter, removeMode);
            return;
        }
        else
            ++iter;
    }
}

void Unit::RemoveAura(AuraApplication * aurApp, AuraRemoveMode mode)
{
    // we've special situation here, RemoveAura called while during aura removal
    // this kind of call is needed only when aura effect removal handler
    // or event triggered by it expects to remove
    // not yet removed effects of an aura
    if (aurApp->GetRemoveMode())
    {
        // remove remaining effects of an aura
        for (uint8 itr = 0; itr < MAX_SPELL_EFFECTS; ++itr)
        {
            if (aurApp->HasEffect(itr))
                aurApp->_HandleEffect(itr, false);
        }
        return;
    }
    // no need to remove
    if (aurApp->GetBase()->GetApplicationOfTarget(GetGUID()) != aurApp || aurApp->GetBase()->IsRemoved())
        return;

    uint32 spellId = aurApp->GetBase()->GetId();
    AuraApplicationMapBoundsNonConst range = m_appliedAuras.equal_range(spellId);

    for (AuraApplicationMap::iterator iter = range.first; iter != range.second;)
    {
        if (aurApp == iter->second)
        {
            RemoveAura(iter, mode);
            return;
        }
        else
            ++iter;
    }
}

void Unit::RemoveAura(Aura* aura, AuraRemoveMode mode)
{
    if (aura->IsRemoved())
        return;
    if (AuraApplication * aurApp = aura->GetApplicationOfTarget(GetGUID()))
        RemoveAura(aurApp, mode);
}

void Unit::RemoveAppliedAuras(std::function<bool(AuraApplication const*)> const& check, AuraRemoveMode removeMode /*= AURA_REMOVE_BY_DEFAULT*/)
{
    for (AuraApplicationMap::iterator iter = m_appliedAuras.begin(); iter != m_appliedAuras.end();)
    {
        if (check(iter->second))
        {
            RemoveAura(iter, removeMode);
            continue;
        }
        ++iter;
    }
}

void Unit::RemoveOwnedAuras(std::function<bool(Aura const*)> const& check, AuraRemoveMode removeMode /*= AURA_REMOVE_BY_DEFAULT*/)
{
    for (AuraMap::iterator iter = m_ownedAuras.begin(); iter != m_ownedAuras.end();)
    {
        if (check(iter->second))
        {
            RemoveOwnedAura(iter, removeMode);
            continue;
        }
        ++iter;
    }
}

void Unit::RemoveAppliedAuras(uint32 spellId, std::function<bool(AuraApplication const*)> const& check, AuraRemoveMode removeMode /*= AURA_REMOVE_BY_DEFAULT*/)
{
    for (AuraApplicationMap::iterator iter = m_appliedAuras.lower_bound(spellId); iter != m_appliedAuras.upper_bound(spellId);)
    {
        if (check(iter->second))
        {
            RemoveAura(iter, removeMode);
            iter = m_appliedAuras.lower_bound(spellId);
            continue;
        }
        ++iter;
    }
}

void Unit::RemoveOwnedAuras(uint32 spellId, std::function<bool(Aura const*)> const& check, AuraRemoveMode removeMode /*= AURA_REMOVE_BY_DEFAULT*/)
{
    for (AuraMap::iterator iter = m_ownedAuras.lower_bound(spellId); iter != m_ownedAuras.upper_bound(spellId);)
    {
        if (check(iter->second))
        {
            RemoveOwnedAura(iter, removeMode);
            iter = m_ownedAuras.lower_bound(spellId);
            continue;
        }
        ++iter;
    }
}

void Unit::RemoveAurasByType(AuraType auraType, std::function<bool(AuraApplication const*)> const& check, AuraRemoveMode removeMode /*= AURA_REMOVE_BY_DEFAULT*/)
{
    for (AuraEffectList::iterator iter = m_modAuras[auraType].begin(); iter != m_modAuras[auraType].end();)
    {
        Aura* aura = (*iter)->GetBase();
        AuraApplication * aurApp = aura->GetApplicationOfTarget(GetGUID());
        ASSERT(aurApp);

        ++iter;
        if (check(aurApp))
        {
            uint32 removedAuras = m_removedAurasCount;
            RemoveAura(aurApp, removeMode);
            if (m_removedAurasCount > removedAuras + 1)
                iter = m_modAuras[auraType].begin();
        }
    }
}

void Unit::RemoveAurasDueToSpell(uint32 spellId, ObjectGuid casterGUID, uint32 reqEffMask, AuraRemoveMode removeMode)
{
    for (AuraApplicationMap::iterator iter = m_appliedAuras.lower_bound(spellId); iter != m_appliedAuras.upper_bound(spellId);)
    {
        Aura const* aura = iter->second->GetBase();
        if (((aura->GetEffectMask() & reqEffMask) == reqEffMask)
            && (!casterGUID || aura->GetCasterGUID() == casterGUID))
        {
            RemoveAura(iter, removeMode);
            iter = m_appliedAuras.lower_bound(spellId);
        }
        else
            ++iter;
    }
}

void Unit::RemoveAuraFromStack(uint32 spellId, ObjectGuid casterGUID, AuraRemoveMode removeMode, uint16 num)
{
    AuraMapBoundsNonConst range = m_ownedAuras.equal_range(spellId);
    for (AuraMap::iterator iter = range.first; iter != range.second;)
    {
        Aura* aura = iter->second;
        if ((aura->GetType() == UNIT_AURA_TYPE)
                && (!casterGUID || aura->GetCasterGUID() == casterGUID))
        {
            aura->ModStackAmount(-num, removeMode);
            return;
        }
        else
            ++iter;
    }
}

void Unit::RemoveAurasDueToSpellByDispel(uint32 spellId, uint32 dispellerSpellId, ObjectGuid casterGUID, WorldObject* dispeller, uint8 chargesRemoved /*= 1*/)
{
    AuraMapBoundsNonConst range = m_ownedAuras.equal_range(spellId);
    for (AuraMap::iterator iter = range.first; iter != range.second;)
    {
        Aura* aura = iter->second;
        if (aura->GetCasterGUID() == casterGUID)
        {
            DispelInfo dispelInfo(dispeller, dispellerSpellId, chargesRemoved);

            // Call OnDispel hook on AuraScript
            aura->CallScriptDispel(&dispelInfo);

            if (aura->GetSpellInfo()->HasAttribute(SPELL_ATTR7_DISPEL_REMOVES_CHARGES))
                aura->ModCharges(-dispelInfo.GetRemovedCharges(), AURA_REMOVE_BY_ENEMY_SPELL);
            else
                aura->ModStackAmount(-dispelInfo.GetRemovedCharges(), AURA_REMOVE_BY_ENEMY_SPELL);

            // Call AfterDispel hook on AuraScript
            aura->CallScriptAfterDispel(&dispelInfo);

            return;
        }
        else
            ++iter;
    }
}

void Unit::RemoveAurasDueToSpellBySteal(uint32 spellId, ObjectGuid casterGUID, WorldObject* stealer, int32 stolenCharges /*= 1*/)
{
    AuraMapBoundsNonConst range = m_ownedAuras.equal_range(spellId);
    for (AuraMap::iterator iter = range.first; iter != range.second;)
    {
        Aura* aura = iter->second;
        if (aura->GetCasterGUID() == casterGUID)
        {
            int32 damage[MAX_SPELL_EFFECTS];
            int32 baseDamage[MAX_SPELL_EFFECTS];
            uint32 effMask = 0;
            uint32 recalculateMask = 0;
            Unit* caster = aura->GetCaster();
            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
            {
                if (aura->GetEffect(i))
                {
                    baseDamage[i] = aura->GetEffect(i)->GetBaseAmount();
                    damage[i] = aura->GetEffect(i)->GetAmount();
                    effMask |= 1 << i;
                    if (aura->GetEffect(i)->CanBeRecalculated())
                        recalculateMask |= 1 << i;
                }
                else
                {
                    baseDamage[i] = 0;
                    damage[i] = 0;
                }
            }

            bool stealCharge = aura->GetSpellInfo()->HasAttribute(SPELL_ATTR7_DISPEL_REMOVES_CHARGES);
            // Cast duration to unsigned to prevent permanent aura's such as Righteous Fury being permanently added to caster
            uint32 dur = std::min(2u * MINUTE * IN_MILLISECONDS, uint32(aura->GetDuration()));

            if (Unit* unitStealer = stealer->ToUnit())
            {
                if (Aura* oldAura = unitStealer->GetAura(aura->GetId(), aura->GetCasterGUID()))
                {
                    if (stealCharge)
                        oldAura->ModCharges(stolenCharges);
                    else
                        oldAura->ModStackAmount(stolenCharges);
                    oldAura->SetDuration(int32(dur));
                }
                else
                {
                    // single target state must be removed before aura creation to preserve existing single target aura
                    if (aura->IsSingleTarget())
                        aura->UnregisterSingleTarget();

                    AuraCreateInfo createInfo(aura->GetCastId(), aura->GetSpellInfo(), aura->GetCastDifficulty(), effMask, unitStealer);
                    createInfo
                        .SetCasterGUID(aura->GetCasterGUID())
                        .SetBaseAmount(baseDamage);

                    if (Aura* newAura = Aura::TryRefreshStackOrCreate(createInfo))
                    {
                        // created aura must not be single target aura,, so stealer won't loose it on recast
                        if (newAura->IsSingleTarget())
                        {
                            newAura->UnregisterSingleTarget();
                            // bring back single target aura status to the old aura
                            aura->SetIsSingleTarget(true);
                            caster->GetSingleCastAuras().push_front(aura);
                        }
                        // FIXME: using aura->GetMaxDuration() maybe not blizzlike but it fixes stealing of spells like Innervate
                        newAura->SetLoadedState(aura->GetMaxDuration(), int32(dur), stealCharge ? stolenCharges : aura->GetCharges(), stolenCharges, recalculateMask, &damage[0]);
                        newAura->ApplyForTargets();
                    }
                }
            }

            if (stealCharge)
                aura->ModCharges(-stolenCharges, AURA_REMOVE_BY_ENEMY_SPELL);
            else
                aura->ModStackAmount(-stolenCharges, AURA_REMOVE_BY_ENEMY_SPELL);

            return;
        }
        else
            ++iter;
    }
}

void Unit::RemoveAurasDueToItemSpell(uint32 spellId, ObjectGuid castItemGuid)
{
    for (AuraApplicationMap::iterator iter = m_appliedAuras.lower_bound(spellId); iter != m_appliedAuras.upper_bound(spellId);)
    {
        if (iter->second->GetBase()->GetCastItemGUID() == castItemGuid)
        {
            RemoveAura(iter);
            iter = m_appliedAuras.lower_bound(spellId);
        }
        else
            ++iter;
    }
}

void Unit::RemoveAurasByType(AuraType auraType, ObjectGuid casterGUID, Aura* except, bool negative, bool positive)
{
    for (AuraEffectList::iterator iter = m_modAuras[auraType].begin(); iter != m_modAuras[auraType].end();)
    {
        Aura* aura = (*iter)->GetBase();
        AuraApplication * aurApp = aura->GetApplicationOfTarget(GetGUID());
        ASSERT(aurApp);

        ++iter;
        if (aura != except && (!casterGUID || aura->GetCasterGUID() == casterGUID)
            && ((negative && !aurApp->IsPositive()) || (positive && aurApp->IsPositive())))
        {
            uint32 removedAuras = m_removedAurasCount;
            RemoveAura(aurApp);
            if (m_removedAurasCount > removedAuras + 1)
                iter = m_modAuras[auraType].begin();
        }
    }
}

void Unit::RemoveAurasWithAttribute(uint32 flags)
{
    for (AuraApplicationMap::iterator iter = m_appliedAuras.begin(); iter != m_appliedAuras.end();)
    {
        SpellInfo const* spell = iter->second->GetBase()->GetSpellInfo();
        if (spell->Attributes & flags)
            RemoveAura(iter);
        else
            ++iter;
    }
}

void Unit::RemoveNotOwnSingleTargetAuras(bool onPhaseChange /*= false*/)
{
    // single target auras from other casters
    // Iterate m_ownedAuras - aura is marked as single target in Unit::AddAura (and pushed to m_ownedAuras).
    // m_appliedAuras will NOT contain the aura before first Unit::Update after adding it to m_ownedAuras.
    // Quickly removing such an aura will lead to it not being unregistered from caster's single cast auras container
    // leading to assertion failures if the aura was cast on a player that can
    // (and is changing map at the point where this function is called).
    // Such situation occurs when player is logging in inside an instance and fails the entry check for any reason.
    // The aura that was loaded from db (indirectly, via linked casts) gets removed before it has a chance
    // to register in m_appliedAuras
    for (AuraMap::iterator iter = m_ownedAuras.begin(); iter != m_ownedAuras.end();)
    {
        Aura const* aura = iter->second;

        if (aura->GetCasterGUID() != GetGUID() && aura->IsSingleTarget())
        {
            if (!onPhaseChange)
                RemoveOwnedAura(iter);
            else
            {
                Unit* caster = aura->GetCaster();
                if (!caster || !caster->InSamePhase(this))
                    RemoveOwnedAura(iter);
                else
                    ++iter;
            }
        }
        else
            ++iter;
    }

    // single target auras at other targets
    AuraList& scAuras = GetSingleCastAuras();
    for (AuraList::iterator iter = scAuras.begin(); iter != scAuras.end();)
    {
        Aura* aura = *iter;
        if (aura->GetUnitOwner() != this && (!onPhaseChange || !aura->GetUnitOwner()->InSamePhase(this)))
        {
            aura->Remove();
            iter = scAuras.begin();
        }
        else
            ++iter;
    }
}

template<typename InterruptFlag>
bool IsInterruptFlagIgnoredForSpell(InterruptFlag /*flag*/, Unit const* /*unit*/, SpellInfo const* /*auraSpellInfo*/, SpellInfo const* /*interruptSource*/)
{
    return false;
}

template<>
bool IsInterruptFlagIgnoredForSpell(SpellAuraInterruptFlags flag, Unit const* unit, SpellInfo const* auraSpellInfo, SpellInfo const* interruptSource)
{
    switch (flag)
    {
        case SpellAuraInterruptFlags::Moving:
            return unit->CanCastSpellWhileMoving(auraSpellInfo);
        case SpellAuraInterruptFlags::Action:
        case SpellAuraInterruptFlags::ActionDelayed:
            if (interruptSource)
            {
                if (interruptSource->HasAttribute(SPELL_ATTR1_ALLOW_WHILE_STEALTHED) && auraSpellInfo->Dispel == DISPEL_STEALTH)
                    return true;

                if (interruptSource->HasAttribute(SPELL_ATTR2_ALLOW_WHILE_INVISIBLE) && auraSpellInfo->Dispel == DISPEL_INVISIBILITY)
                    return true;
            }
            break;
        default:
            break;
    }

    return false;
}

template <typename InterruptFlags>
void Unit::RemoveAurasWithInterruptFlags(InterruptFlags flag, SpellInfo const* source)
{
    if (!HasInterruptFlag(flag))
        return;

    // interrupt auras
    for (AuraApplicationList::iterator iter = m_interruptableAuras.begin(); iter != m_interruptableAuras.end();)
    {
        Aura* aura = (*iter)->GetBase();
        ++iter;
        if (aura->GetSpellInfo()->HasAuraInterruptFlag(flag)
            && (!source || aura->GetId() != source->Id)
            && !IsInterruptFlagIgnoredForSpell(flag, this, aura->GetSpellInfo(), source))
        {
            uint32 removedAuras = m_removedAurasCount;
            RemoveAura(aura, AURA_REMOVE_BY_INTERRUPT);
            if (m_removedAurasCount > removedAuras + 1)
                iter = m_interruptableAuras.begin();
        }
    }

    // interrupt channeled spell
    if (Spell* spell = m_currentSpells[CURRENT_CHANNELED_SPELL])
        if (spell->getState() == SPELL_STATE_CASTING
            && spell->GetSpellInfo()->HasChannelInterruptFlag(flag)
            && (!source || spell->GetSpellInfo()->Id != source->Id)
            && !IsInterruptFlagIgnoredForSpell(flag, this, spell->GetSpellInfo(), source))
            InterruptNonMeleeSpells(false);

    UpdateInterruptMask();
}

template TC_GAME_API void Unit::RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags flag, SpellInfo const* source);
template TC_GAME_API void Unit::RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags2 flag, SpellInfo const* source);

void Unit::RemoveAurasWithFamily(SpellFamilyNames family, flag128 const& familyFlag, ObjectGuid casterGUID)
{
    for (AuraApplicationMap::iterator iter = m_appliedAuras.begin(); iter != m_appliedAuras.end();)
    {
        Aura const* aura = iter->second->GetBase();
        if (!casterGUID || aura->GetCasterGUID() == casterGUID)
        {
            SpellInfo const* spell = aura->GetSpellInfo();
            if (spell->SpellFamilyName == uint32(family) && spell->SpellFamilyFlags & familyFlag)
            {
                RemoveAura(iter);
                continue;
            }
        }
        ++iter;
    }
}

void Unit::RemoveMovementImpairingAuras(bool withRoot)
{
    if (withRoot)
        RemoveAurasWithMechanic(1 << MECHANIC_ROOT, AURA_REMOVE_BY_DEFAULT, 0, true);

    RemoveAurasWithMechanic(1 << MECHANIC_SNARE, AURA_REMOVE_BY_DEFAULT, 0, false);
}

void Unit::RemoveAurasWithMechanic(uint64 mechanicMaskToRemove, AuraRemoveMode removeMode, uint32 exceptSpellId, bool withEffectMechanics)
{
    std::vector<Aura*> aurasToUpdateTargets;
    RemoveAppliedAuras([=, &aurasToUpdateTargets](AuraApplication const* aurApp)
    {
        Aura* aura = aurApp->GetBase();
        if (exceptSpellId && aura->GetId() == exceptSpellId)
            return false;

        uint64 appliedMechanicMask = aura->GetSpellInfo()->GetSpellMechanicMaskByEffectMask(aurApp->GetEffectMask());
        if (!(appliedMechanicMask & mechanicMaskToRemove))
            return false;

        // spell mechanic matches required mask for removal
        if ((UI64LIT(1) << aura->GetSpellInfo()->Mechanic) & mechanicMaskToRemove || withEffectMechanics)
            return true;

        // effect mechanic matches required mask for removal - don't remove, only update targets
        aurasToUpdateTargets.push_back(aura);
        return false;
    }, removeMode);

    for (Aura* aura : aurasToUpdateTargets)
    {
        aura->UpdateTargetMap(aura->GetCaster());

        // Fully remove the aura if all effects were removed
        if (!aura->IsPassive() && aura->GetOwner() == this && !aura->GetApplicationOfTarget(GetGUID()))
            aura->Remove(removeMode);
    }
}

void Unit::RemoveAurasByShapeShift()
{
    uint64 mechanic_mask = (1 << MECHANIC_SNARE) | (1 << MECHANIC_ROOT);
    for (AuraApplicationMap::iterator iter = m_appliedAuras.begin(); iter != m_appliedAuras.end();)
    {
        Aura const* aura = iter->second->GetBase();
        if ((aura->GetSpellInfo()->GetAllEffectsMechanicMask() & mechanic_mask) && !aura->GetSpellInfo()->HasAttribute(SPELL_ATTR0_CU_AURA_CC))
        {
            RemoveAura(iter);
            continue;
        }
        ++iter;
    }
}

void Unit::RemoveAreaAurasDueToLeaveWorld()
{
    // make sure that all area auras not applied on self are removed - prevent access to deleted pointer later
    for (AuraMap::iterator iter = m_ownedAuras.begin(); iter != m_ownedAuras.end();)
    {
        Aura* aura = iter->second;
        ++iter;
        Aura::ApplicationMap const& appMap = aura->GetApplicationMap();
        for (Aura::ApplicationMap::const_iterator itr = appMap.begin(); itr!= appMap.end();)
        {
            AuraApplication * aurApp = itr->second;
            ++itr;
            Unit* target = aurApp->GetTarget();
            if (target == this)
                continue;
            target->RemoveAura(aurApp);
            // things linked on aura remove may apply new area aura - so start from the beginning
            iter = m_ownedAuras.begin();
        }
    }

    // remove area auras owned by others
    for (AuraApplicationMap::iterator iter = m_appliedAuras.begin(); iter != m_appliedAuras.end();)
    {
        if (iter->second->GetBase()->GetOwner() != this)
        {
            RemoveAura(iter);
        }
        else
            ++iter;
    }
}

void Unit::RemoveAllAuras()
{
    // this may be a dead loop if some events on aura remove will continiously apply aura on remove
    // we want to have all auras removed, so use your brain when linking events
    for (int counter = 0; !m_appliedAuras.empty() || !m_ownedAuras.empty(); counter++)
    {
        AuraApplicationMap::iterator aurAppIter;
        for (aurAppIter = m_appliedAuras.begin(); aurAppIter != m_appliedAuras.end();)
            _UnapplyAura(aurAppIter, AURA_REMOVE_BY_DEFAULT);

        AuraMap::iterator aurIter;
        for (aurIter = m_ownedAuras.begin(); aurIter != m_ownedAuras.end();)
            RemoveOwnedAura(aurIter);

        const int maxIteration = 50;
        // give this loop a few tries, if there are still auras then log as much information as possible
        if (counter >= maxIteration)
        {
            std::stringstream sstr;
            sstr << "Unit::RemoveAllAuras() iterated " << maxIteration << " times already but there are still "
                << m_appliedAuras.size() << " m_appliedAuras and " << m_ownedAuras.size() << " m_ownedAuras. Details:" << "\n";
            sstr << GetDebugInfo() << "\n";

            if (!m_appliedAuras.empty())
            {
                sstr << "m_appliedAuras:" << "\n";

                for (std::pair<uint32 const, AuraApplication*>& auraAppPair : m_appliedAuras)
                    sstr << auraAppPair.second->GetDebugInfo() << "\n";
            }

            if (!m_ownedAuras.empty())
            {
                sstr << "m_ownedAuras:" << "\n";

                for (auto const& [spellId, aura] : m_ownedAuras)
                    sstr << aura->GetDebugInfo() << "\n";
            }

            TC_LOG_ERROR("entities.unit", "{}", sstr.str());
            ABORT_MSG("%s", sstr.str().c_str());

            break;
        }
    }
}

void Unit::RemoveArenaAuras()
{
    // in join, remove positive buffs, on end, remove negative
    // used to remove positive visible auras in arenas
    RemoveAppliedAuras([](AuraApplication const* aurApp)
    {
        Aura const* aura = aurApp->GetBase();
        return (!aura->GetSpellInfo()->HasAttribute(SPELL_ATTR4_ALLOW_ENTERING_ARENA)                          // don't remove stances, shadowform, pally/hunter auras
            && !aura->IsPassive()                                                                              // don't remove passive auras
            && (aurApp->IsPositive() || !aura->GetSpellInfo()->HasAttribute(SPELL_ATTR3_ALLOW_AURA_WHILE_DEAD))) || // not negative death persistent auras
            aura->GetSpellInfo()->HasAttribute(SPELL_ATTR5_REMOVE_ENTERING_ARENA);                             // special marker, always remove
    });
}

void Unit::RemoveAurasOnEvade()
{
    if (IsCharmedOwnedByPlayerOrPlayer()) // if it is a player owned creature it should not remove the aura
        return;

    // don't remove vehicle auras, passengers aren't supposed to drop off the vehicle
    // don't remove clone caster on evade (to be verified)
    auto evadeAuraCheck = [](Aura const* aura)
    {
        if (aura->HasEffectType(SPELL_AURA_CONTROL_VEHICLE))
            return false;

        if (aura->HasEffectType(SPELL_AURA_CLONE_CASTER))
            return false;

        if (aura->GetSpellInfo()->HasAttribute(SPELL_ATTR1_AURA_STAYS_AFTER_COMBAT))
            return false;

        return true;
    };

    auto evadeAuraApplicationCheck = [&evadeAuraCheck](AuraApplication const* aurApp)
    {
        return evadeAuraCheck(aurApp->GetBase());
    };

    RemoveAppliedAuras(evadeAuraApplicationCheck);
    RemoveOwnedAuras(evadeAuraCheck);
}

void Unit::RemoveAllAurasOnDeath()
{
    // used just after dieing to remove all visible auras
    // and disable the mods for the passive ones
    for (AuraApplicationMap::iterator iter = m_appliedAuras.begin(); iter != m_appliedAuras.end();)
    {
        Aura const* aura = iter->second->GetBase();
        if (!aura->IsPassive() && !aura->IsDeathPersistent())
            _UnapplyAura(iter, AURA_REMOVE_BY_DEATH);
        else
            ++iter;
    }

    for (AuraMap::iterator iter = m_ownedAuras.begin(); iter != m_ownedAuras.end();)
    {
        Aura* aura = iter->second;
        if (!aura->IsPassive() && !aura->IsDeathPersistent())
            RemoveOwnedAura(iter, AURA_REMOVE_BY_DEATH);
        else
            ++iter;
    }
}

void Unit::RemoveAllAurasRequiringDeadTarget()
{
    for (AuraApplicationMap::iterator iter = m_appliedAuras.begin(); iter != m_appliedAuras.end();)
    {
        Aura const* aura = iter->second->GetBase();
        if (!aura->IsPassive() && aura->GetSpellInfo()->IsRequiringDeadTarget())
            _UnapplyAura(iter, AURA_REMOVE_BY_DEFAULT);
        else
            ++iter;
    }

    for (AuraMap::iterator iter = m_ownedAuras.begin(); iter != m_ownedAuras.end();)
    {
        Aura* aura = iter->second;
        if (!aura->IsPassive() && aura->GetSpellInfo()->IsRequiringDeadTarget())
            RemoveOwnedAura(iter, AURA_REMOVE_BY_DEFAULT);
        else
            ++iter;
    }
}

void Unit::RemoveAllAurasExceptType(AuraType type)
{
    for (AuraApplicationMap::iterator iter = m_appliedAuras.begin(); iter != m_appliedAuras.end();)
    {
        Aura const* aura = iter->second->GetBase();
        if (aura->GetSpellInfo()->HasAura(type))
            ++iter;
        else
            _UnapplyAura(iter, AURA_REMOVE_BY_DEFAULT);
    }

    for (AuraMap::iterator iter = m_ownedAuras.begin(); iter != m_ownedAuras.end();)
    {
        Aura* aura = iter->second;
        if (aura->GetSpellInfo()->HasAura(type))
            ++iter;
        else
            RemoveOwnedAura(iter, AURA_REMOVE_BY_DEFAULT);
    }
}

void Unit::RemoveAllAurasExceptType(AuraType type1, AuraType type2)
{
    for (AuraApplicationMap::iterator iter = m_appliedAuras.begin(); iter != m_appliedAuras.end();)
    {
        Aura const* aura = iter->second->GetBase();
        if (aura->GetSpellInfo()->HasAura(type1) || aura->GetSpellInfo()->HasAura(type2))
            ++iter;
        else
            _UnapplyAura(iter, AURA_REMOVE_BY_DEFAULT);
    }

    for (AuraMap::iterator iter = m_ownedAuras.begin(); iter != m_ownedAuras.end();)
    {
        Aura* aura = iter->second;
        if (aura->GetSpellInfo()->HasAura(type1) || aura->GetSpellInfo()->HasAura(type2))
            ++iter;
        else
            RemoveOwnedAura(iter, AURA_REMOVE_BY_DEFAULT);
    }
}

void Unit::RemoveAllGroupBuffsFromCaster(ObjectGuid casterGUID)
{
    for (AuraMap::iterator iter = m_ownedAuras.begin(); iter != m_ownedAuras.end();)
    {
        Aura* aura = iter->second;
        if (aura->GetCasterGUID() == casterGUID && aura->GetSpellInfo()->IsGroupBuff())
        {
            RemoveOwnedAura(iter);
            continue;
        }
        ++iter;
    }
}

void Unit::DelayOwnedAuras(uint32 spellId, ObjectGuid caster, int32 delaytime)
{
    AuraMapBoundsNonConst range = m_ownedAuras.equal_range(spellId);
    for (; range.first != range.second; ++range.first)
    {
        Aura* aura = range.first->second;
        if (!caster || aura->GetCasterGUID() == caster)
        {
            if (aura->GetDuration() < delaytime)
                aura->SetDuration(0);
            else
                aura->SetDuration(aura->GetDuration() - delaytime);

            // update for out of range group members (on 1 slot use)
            aura->SetNeedClientUpdateForTargets();
        }
    }
}

void Unit::_RemoveAllAuraStatMods()
{
    for (AuraApplicationMap::iterator i = m_appliedAuras.begin(); i != m_appliedAuras.end(); ++i)
        (*i).second->GetBase()->HandleAllEffects(i->second, AURA_EFFECT_HANDLE_STAT, false);
}

void Unit::_ApplyAllAuraStatMods()
{
    for (AuraApplicationMap::iterator i = m_appliedAuras.begin(); i != m_appliedAuras.end(); ++i)
        (*i).second->GetBase()->HandleAllEffects(i->second, AURA_EFFECT_HANDLE_STAT, true);
}

AuraEffect* Unit::GetAuraEffect(uint32 spellId, uint8 effIndex, ObjectGuid caster) const
{
    AuraApplicationMapBounds range = m_appliedAuras.equal_range(spellId);
    for (AuraApplicationMap::const_iterator itr = range.first; itr != range.second; ++itr)
    {
        if (itr->second->HasEffect(effIndex)
                && (!caster || itr->second->GetBase()->GetCasterGUID() == caster))
        {
            return itr->second->GetBase()->GetEffect(effIndex);
        }
    }
    return nullptr;
}

AuraEffect* Unit::GetAuraEffectOfRankedSpell(uint32 spellId, uint8 effIndex, ObjectGuid caster) const
{
    uint32 rankSpell = sSpellMgr->GetFirstSpellInChain(spellId);
    while (rankSpell)
    {
        if (AuraEffect* aurEff = GetAuraEffect(rankSpell, effIndex, caster))
            return aurEff;
        rankSpell = sSpellMgr->GetNextSpellInChain(rankSpell);
    }
    return nullptr;
}

AuraEffect* Unit::GetAuraEffect(AuraType type, SpellFamilyNames family, flag128 const& familyFlag, ObjectGuid casterGUID) const
{
    AuraEffectList const& auras = GetAuraEffectsByType(type);
    for (AuraEffectList::const_iterator i = auras.begin(); i != auras.end(); ++i)
    {
        SpellInfo const* spell = (*i)->GetSpellInfo();
        if (spell->SpellFamilyName == uint32(family) && spell->SpellFamilyFlags & familyFlag)
        {
            if (!casterGUID.IsEmpty() && (*i)->GetCasterGUID() != casterGUID)
                continue;
            return (*i);
        }
    }
    return nullptr;
}

AuraApplication * Unit::GetAuraApplication(uint32 spellId, ObjectGuid casterGUID, ObjectGuid itemCasterGUID, uint32 reqEffMask, AuraApplication * except) const
{
    return GetAuraApplication(spellId, [&](AuraApplication const* app)
    {
        Aura const* aura = app->GetBase();

        if (((aura->GetEffectMask() & reqEffMask) == reqEffMask)
            && (!casterGUID || aura->GetCasterGUID() == casterGUID)
            && (!itemCasterGUID || aura->GetCastItemGUID() == itemCasterGUID)
            && (!except || except != app))
        {
            return true;
        }

        return false;
    });
}

AuraApplication* Unit::GetAuraApplication(uint32 spellId, std::function<bool(AuraApplication const*)> const& predicate) const
{
    for (AuraApplicationMap::value_type const& pair : Trinity::Containers::MapEqualRange(m_appliedAuras, spellId))
        if (predicate(pair.second))
            return pair.second;

    return nullptr;
}

AuraApplication* Unit::GetAuraApplication(uint32 spellId, std::function<bool(Aura const*)> const& predicate) const
{
    for (AuraApplicationMap::value_type const& pair : Trinity::Containers::MapEqualRange(m_appliedAuras, spellId))
        if (predicate(pair.second->GetBase()))
            return pair.second;

    return nullptr;
}

AuraApplication* Unit::GetAuraApplication(std::function<bool(AuraApplication const*)> const& predicate) const
{
    for (AuraApplicationMap::value_type const& pair : m_appliedAuras)
        if (predicate(pair.second))
            return pair.second;

    return nullptr;
}

AuraApplication* Unit::GetAuraApplication(std::function<bool(Aura const*)> const& predicate) const
{
    for (AuraApplicationMap::value_type const& pair : m_appliedAuras)
        if (predicate(pair.second->GetBase()))
            return pair.second;

    return nullptr;
}

Aura* Unit::GetAura(uint32 spellId, ObjectGuid casterGUID, ObjectGuid itemCasterGUID, uint32 reqEffMask) const
{
    AuraApplication* aurApp = GetAuraApplication(spellId, casterGUID, itemCasterGUID, reqEffMask);
    return aurApp ? aurApp->GetBase() : nullptr;
}

Aura* Unit::GetAura(uint32 spellId, std::function<bool(Aura const*)> const& predicate) const
{
    AuraApplication* aurApp = GetAuraApplication(spellId, predicate);
    return aurApp ? aurApp->GetBase() : nullptr;
}

Aura* Unit::GetAura(std::function<bool(Aura const*)> const& predicate) const
{
    AuraApplication* aurApp = GetAuraApplication(predicate);
    return aurApp ? aurApp->GetBase() : nullptr;
}

AuraApplication * Unit::GetAuraApplicationOfRankedSpell(uint32 spellId, ObjectGuid casterGUID, ObjectGuid itemCasterGUID, uint32 reqEffMask, AuraApplication* except) const
{
    uint32 rankSpell = sSpellMgr->GetFirstSpellInChain(spellId);
    while (rankSpell)
    {
        if (AuraApplication * aurApp = GetAuraApplication(rankSpell, casterGUID, itemCasterGUID, reqEffMask, except))
            return aurApp;
        rankSpell = sSpellMgr->GetNextSpellInChain(rankSpell);
    }
    return nullptr;
}

Aura* Unit::GetAuraOfRankedSpell(uint32 spellId, ObjectGuid casterGUID, ObjectGuid itemCasterGUID, uint32 reqEffMask) const
{
    AuraApplication * aurApp = GetAuraApplicationOfRankedSpell(spellId, casterGUID, itemCasterGUID, reqEffMask);
    return aurApp ? aurApp->GetBase() : nullptr;
}

void Unit::GetDispellableAuraList(WorldObject const* caster, uint32 dispelMask, DispelChargesList& dispelList, bool isReflect /*= false*/) const
{
    AuraMap const& auras = GetOwnedAuras();
    for (auto itr = auras.begin(); itr != auras.end(); ++itr)
    {
        Aura* aura = itr->second;
        AuraApplication const* aurApp = aura->GetApplicationOfTarget(GetGUID());
        if (!aurApp)
            continue;

        // don't try to remove passive auras
        if (aura->IsPassive())
            continue;

        if (aura->GetSpellInfo()->GetDispelMask() & dispelMask)
        {
            // do not remove positive auras if friendly target
            //               negative auras if non-friendly
            // unless we're reflecting (dispeller eliminates one of it's benefitial buffs)
            if (isReflect != (aurApp->IsPositive() == IsFriendlyTo(caster)))
                continue;

            // 2.4.3 Patch Notes: "Dispel effects will no longer attempt to remove effects that have 100% dispel resistance."
            int32 chance = aura->CalcDispelChance(this, !IsFriendlyTo(caster));
            if (!chance)
                continue;

            // The charges / stack amounts don't count towards the total number of auras that can be dispelled.
            // Ie: A dispel on a target with 5 stacks of Winters Chill and a Polymorph has 1 / (1 + 1) -> 50% chance to dispell
            // Polymorph instead of 1 / (5 + 1) -> 16%.
            bool const dispelCharges = aura->GetSpellInfo()->HasAttribute(SPELL_ATTR7_DISPEL_REMOVES_CHARGES);
            uint8 charges = dispelCharges ? aura->GetCharges() : aura->GetStackAmount();
            if (charges > 0)
                dispelList.emplace_back(aura, chance, charges);
        }
    }
}

bool Unit::HasAuraEffect(uint32 spellId, uint8 effIndex, ObjectGuid caster) const
{
    AuraApplicationMapBounds range = m_appliedAuras.equal_range(spellId);
    for (AuraApplicationMap::const_iterator itr = range.first; itr != range.second; ++itr)
    {
        if (itr->second->HasEffect(effIndex)
                && (!caster || itr->second->GetBase()->GetCasterGUID() == caster))
        {
            return true;
        }
    }
    return false;
}

uint32 Unit::GetAuraCount(uint32 spellId) const
{
    uint32 count = 0;
    AuraApplicationMapBounds range = m_appliedAuras.equal_range(spellId);

    for (AuraApplicationMap::const_iterator itr = range.first; itr != range.second; ++itr)
    {
        if (itr->second->GetBase()->GetStackAmount() == 0)
            ++count;
        else
            count += (uint32)itr->second->GetBase()->GetStackAmount();
    }

    return count;
}

bool Unit::HasAura(uint32 spellId, ObjectGuid casterGUID, ObjectGuid itemCasterGUID, uint32 reqEffMask) const
{
    return GetAuraApplication(spellId, casterGUID, itemCasterGUID, reqEffMask) != nullptr;
}

bool Unit::HasAura(std::function<bool(Aura const*)> const& predicate) const
{
    return GetAuraApplication(predicate) != nullptr;
}

bool Unit::HasAuraType(AuraType auraType) const
{
    return (!m_modAuras[auraType].empty());
}

bool Unit::HasAuraTypeWithCaster(AuraType auraType, ObjectGuid caster) const
{
    for (AuraEffect const* eff : GetAuraEffectsByType(auraType))
        if (caster == eff->GetCasterGUID())
            return true;
    return false;
}

bool Unit::HasAuraTypeWithMiscvalue(AuraType auraType, int32 miscvalue) const
{
    AuraEffectList const& mTotalAuraList = GetAuraEffectsByType(auraType);
    for (AuraEffectList::const_iterator i = mTotalAuraList.begin(); i != mTotalAuraList.end(); ++i)
        if (miscvalue == (*i)->GetMiscValue())
            return true;
    return false;
}

bool Unit::HasAuraTypeWithAffectMask(AuraType auraType, SpellInfo const* affectedSpell) const
{
    AuraEffectList const& mTotalAuraList = GetAuraEffectsByType(auraType);
    for (AuraEffectList::const_iterator i = mTotalAuraList.begin(); i != mTotalAuraList.end(); ++i)
        if ((*i)->IsAffectingSpell(affectedSpell))
            return true;
    return false;
}

bool Unit::HasAuraTypeWithValue(AuraType auraType, int32 value) const
{
    AuraEffectList const& mTotalAuraList = GetAuraEffectsByType(auraType);
    for (AuraEffectList::const_iterator i = mTotalAuraList.begin(); i != mTotalAuraList.end(); ++i)
        if (value == (*i)->GetAmount())
            return true;
    return false;
}

bool Unit::HasAuraTypeWithTriggerSpell(AuraType auratype, uint32 triggerSpell) const
{
    for (AuraEffect const* aura : GetAuraEffectsByType(auratype))
        if (aura->GetSpellEffectInfo().TriggerSpell == triggerSpell)
            return true;
    return false;
}

template <typename InterruptFlags>
bool Unit::HasNegativeAuraWithInterruptFlag(InterruptFlags flag, ObjectGuid guid) const
{
    if (!HasInterruptFlag(flag))
        return false;

    for (AuraApplicationList::const_iterator iter = m_interruptableAuras.begin(); iter != m_interruptableAuras.end(); ++iter)
        if (!(*iter)->IsPositive() && (*iter)->GetBase()->GetSpellInfo()->HasAuraInterruptFlag(flag) &&
            (!guid || (*iter)->GetBase()->GetCasterGUID() == guid))
            return true;

    return false;
}

template TC_GAME_API bool Unit::HasNegativeAuraWithInterruptFlag(SpellAuraInterruptFlags flag, ObjectGuid guid) const;
template TC_GAME_API bool Unit::HasNegativeAuraWithInterruptFlag(SpellAuraInterruptFlags2 flag, ObjectGuid guid) const;

bool Unit::HasAuraWithMechanic(uint64 mechanicMask) const
{
    for (AuraApplicationMap::const_iterator iter = m_appliedAuras.begin(); iter != m_appliedAuras.end(); ++iter)
    {
        SpellInfo const* spellInfo = iter->second->GetBase()->GetSpellInfo();
        if (spellInfo->Mechanic && (mechanicMask & (UI64LIT(1) << spellInfo->Mechanic)))
            return true;

        for (SpellEffectInfo const& spellEffectInfo : spellInfo->GetEffects())
            if (iter->second->HasEffect(spellEffectInfo.EffectIndex) && spellEffectInfo.IsEffect() && spellEffectInfo.Mechanic)
                if (mechanicMask & (UI64LIT(1) << spellEffectInfo.Mechanic))
                    return true;
    }

    return false;
}

bool Unit::HasStrongerAuraWithDR(SpellInfo const* auraSpellInfo, Unit* caster) const
{
    DiminishingGroup diminishGroup = auraSpellInfo->GetDiminishingReturnsGroupForSpell();
    DiminishingLevels level = GetDiminishing(diminishGroup);
    for (auto itr = m_appliedAuras.begin(); itr != m_appliedAuras.end(); ++itr)
    {
        SpellInfo const* spellInfo = itr->second->GetBase()->GetSpellInfo();
        if (spellInfo->GetDiminishingReturnsGroupForSpell() != diminishGroup)
            continue;

        int32 existingDuration = itr->second->GetBase()->GetDuration();
        int32 newDuration = auraSpellInfo->GetMaxDuration();
        ApplyDiminishingToDuration(auraSpellInfo, newDuration, caster, level);
        if (newDuration > 0 && newDuration < existingDuration)
            return true;
    }

    return false;
}

AuraEffect* Unit::IsScriptOverriden(SpellInfo const* spell, int32 script) const
{
    AuraEffectList const& auras = GetAuraEffectsByType(SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
    for (AuraEffectList::const_iterator i = auras.begin(); i != auras.end(); ++i)
    {
        if ((*i)->GetMiscValue() == script)
            if ((*i)->IsAffectingSpell(spell))
                return (*i);
    }
    return nullptr;
}

uint32 Unit::GetDiseasesByCaster(ObjectGuid casterGUID, bool remove)
{
    static const AuraType diseaseAuraTypes[] =
    {
        SPELL_AURA_PERIODIC_DAMAGE, // Frost Fever and Blood Plague
        SPELL_AURA_LINKED           // Crypt Fever and Ebon Plague
    };

    uint32 diseases = 0;
    for (AuraType aType : diseaseAuraTypes)
    {
        for (auto itr = m_modAuras[aType].begin(); itr != m_modAuras[aType].end();)
        {
            // Get auras with disease dispel type by caster
            if ((*itr)->GetSpellInfo()->Dispel == DISPEL_DISEASE
                && (*itr)->GetCasterGUID() == casterGUID)
            {
                ++diseases;

                if (remove)
                {
                    RemoveAura((*itr)->GetId(), (*itr)->GetCasterGUID());
                    itr = m_modAuras[aType].begin();
                    continue;
                }
            }
            ++itr;
        }
    }
    return diseases;
}

uint32 Unit::GetDoTsByCaster(ObjectGuid casterGUID) const
{
    static const AuraType diseaseAuraTypes[] =
    {
        SPELL_AURA_PERIODIC_DAMAGE,
        SPELL_AURA_PERIODIC_DAMAGE_PERCENT,
        SPELL_AURA_NONE
    };

    uint32 dots = 0;
    for (AuraType const* itr = &diseaseAuraTypes[0]; itr && itr[0] != SPELL_AURA_NONE; ++itr)
    {
        Unit::AuraEffectList const& auras = GetAuraEffectsByType(*itr);
        for (AuraEffectList::const_iterator i = auras.begin(); i != auras.end(); ++i)
        {
            // Get auras by caster
            if ((*i)->GetCasterGUID() == casterGUID)
                ++dots;
        }
    }
    return dots;
}

int32 Unit::GetTotalAuraModifier(AuraType auraType, std::function<bool(AuraEffect const*)> const& predicate) const
{
    AuraEffectList const& mTotalAuraList = GetAuraEffectsByType(auraType);
    if (mTotalAuraList.empty())
        return 0;

    std::map<SpellGroup, int32> sameEffectSpellGroup;
    int32 modifier = 0;

    for (AuraEffect const* aurEff : mTotalAuraList)
    {
        if (predicate(aurEff))
        {
            // Check if the Aura Effect has a the Same Effect Stack Rule and if so, use the highest amount of that SpellGroup
            // If the Aura Effect does not have this Stack Rule, it returns false so we can add to the multiplier as usual
            if (!sSpellMgr->AddSameEffectStackRuleSpellGroups(aurEff->GetSpellInfo(), static_cast<uint32>(auraType), aurEff->GetAmount(), sameEffectSpellGroup))
                modifier += aurEff->GetAmount();
        }
    }

    // Add the highest of the Same Effect Stack Rule SpellGroups to the accumulator
    for (auto itr = sameEffectSpellGroup.begin(); itr != sameEffectSpellGroup.end(); ++itr)
        modifier += itr->second;

    return modifier;
}

float Unit::GetTotalAuraMultiplier(AuraType auraType, std::function<bool(AuraEffect const*)> const& predicate) const
{
    AuraEffectList const& mTotalAuraList = GetAuraEffectsByType(auraType);
    if (mTotalAuraList.empty())
        return 1.0f;

    std::map<SpellGroup, int32> sameEffectSpellGroup;
    float multiplier = 1.0f;

    for (AuraEffect const* aurEff : mTotalAuraList)
    {
        if (predicate(aurEff))
        {
            // Check if the Aura Effect has a the Same Effect Stack Rule and if so, use the highest amount of that SpellGroup
            // If the Aura Effect does not have this Stack Rule, it returns false so we can add to the multiplier as usual
            if (!sSpellMgr->AddSameEffectStackRuleSpellGroups(aurEff->GetSpellInfo(), static_cast<uint32>(auraType), aurEff->GetAmount(), sameEffectSpellGroup))
                AddPct(multiplier, aurEff->GetAmount());
        }
    }

    // Add the highest of the Same Effect Stack Rule SpellGroups to the multiplier
    for (auto itr = sameEffectSpellGroup.begin(); itr != sameEffectSpellGroup.end(); ++itr)
        AddPct(multiplier, itr->second);

    return multiplier;
}

int32 Unit::GetMaxPositiveAuraModifier(AuraType auraType, std::function<bool(AuraEffect const*)> const& predicate) const
{
    AuraEffectList const& mTotalAuraList = GetAuraEffectsByType(auraType);
    if (mTotalAuraList.empty())
        return 0;

    int32 modifier = 0;
    for (AuraEffect const* aurEff : mTotalAuraList)
    {
        if (predicate(aurEff))
            modifier = std::max(modifier, aurEff->GetAmount());
    }

    return modifier;
}

int32 Unit::GetMaxNegativeAuraModifier(AuraType auraType, std::function<bool(AuraEffect const*)> const& predicate) const
{
    AuraEffectList const& mTotalAuraList = GetAuraEffectsByType(auraType);
    if (mTotalAuraList.empty())
        return 0;

    int32 modifier = 0;
    for (AuraEffect const* aurEff : mTotalAuraList)
    {
        if (predicate(aurEff))
            modifier = std::min(modifier, aurEff->GetAmount());
    }

    return modifier;
}

int32 Unit::GetTotalAuraModifier(AuraType auraType) const
{
    return GetTotalAuraModifier(auraType, [](AuraEffect const* /*aurEff*/) { return true; });
}

float Unit::GetTotalAuraMultiplier(AuraType auraType) const
{
    return GetTotalAuraMultiplier(auraType, [](AuraEffect const* /*aurEff*/) { return true; });
}

int32 Unit::GetMaxPositiveAuraModifier(AuraType auraType) const
{
    return GetMaxPositiveAuraModifier(auraType, [](AuraEffect const* /*aurEff*/) { return true; });
}

int32 Unit::GetMaxNegativeAuraModifier(AuraType auraType) const
{
    return GetMaxNegativeAuraModifier(auraType, [](AuraEffect const* /*aurEff*/) { return true; });
}

int32 Unit::GetTotalAuraModifierByMiscMask(AuraType auraType, uint32 miscMask) const
{
    return GetTotalAuraModifier(auraType, [miscMask](AuraEffect const* aurEff) -> bool
    {
        if ((aurEff->GetMiscValue() & miscMask) != 0)
            return true;
        return false;
    });
}

float Unit::GetTotalAuraMultiplierByMiscMask(AuraType auraType, uint32 miscMask) const
{
    return GetTotalAuraMultiplier(auraType, [miscMask](AuraEffect const* aurEff) -> bool
    {
        if ((aurEff->GetMiscValue() & miscMask) != 0)
            return true;
        return false;
    });
}

int32 Unit::GetMaxPositiveAuraModifierByMiscMask(AuraType auraType, uint32 miscMask, AuraEffect const* except /*= nullptr*/) const
{
    return GetMaxPositiveAuraModifier(auraType, [miscMask, except](AuraEffect const* aurEff) -> bool
    {
        if (except != aurEff && (aurEff->GetMiscValue() & miscMask) != 0)
            return true;
        return false;
    });
}

int32 Unit::GetMaxNegativeAuraModifierByMiscMask(AuraType auraType, uint32 miscMask) const
{
    return GetMaxNegativeAuraModifier(auraType, [miscMask](AuraEffect const* aurEff) -> bool
    {
        if ((aurEff->GetMiscValue() & miscMask) != 0)
            return true;
        return false;
    });
}

int32 Unit::GetTotalAuraModifierByMiscValue(AuraType auraType, int32 miscValue) const
{
    return GetTotalAuraModifier(auraType, [miscValue](AuraEffect const* aurEff) -> bool
    {
        if (aurEff->GetMiscValue() == miscValue)
            return true;
        return false;
    });
}

float Unit::GetTotalAuraMultiplierByMiscValue(AuraType auraType, int32 miscValue) const
{
    return GetTotalAuraMultiplier(auraType, [miscValue](AuraEffect const* aurEff) -> bool
    {
        if (aurEff->GetMiscValue() == miscValue)
            return true;
        return false;
    });
}

int32 Unit::GetMaxPositiveAuraModifierByMiscValue(AuraType auraType, int32 miscValue) const
{
    return GetMaxPositiveAuraModifier(auraType, [miscValue](AuraEffect const* aurEff) -> bool
    {
        if (aurEff->GetMiscValue() == miscValue)
            return true;
        return false;
    });
}

int32 Unit::GetMaxNegativeAuraModifierByMiscValue(AuraType auraType, int32 miscValue) const
{
    return GetMaxNegativeAuraModifier(auraType, [miscValue](AuraEffect const* aurEff) -> bool
    {
        if (aurEff->GetMiscValue() == miscValue)
            return true;
        return false;
    });
}

int32 Unit::GetTotalAuraModifierByAffectMask(AuraType auraType, SpellInfo const* affectedSpell) const
{
    return GetTotalAuraModifier(auraType, [affectedSpell](AuraEffect const* aurEff) -> bool
    {
        if (aurEff->IsAffectingSpell(affectedSpell))
            return true;
        return false;
    });
}

float Unit::GetTotalAuraMultiplierByAffectMask(AuraType auraType, SpellInfo const* affectedSpell) const
{
    return GetTotalAuraMultiplier(auraType, [affectedSpell](AuraEffect const* aurEff) -> bool
    {
        if (aurEff->IsAffectingSpell(affectedSpell))
            return true;
        return false;
    });
}

int32 Unit::GetMaxPositiveAuraModifierByAffectMask(AuraType auraType, SpellInfo const* affectedSpell) const
{
    return GetMaxPositiveAuraModifier(auraType, [affectedSpell](AuraEffect const* aurEff) -> bool
    {
        if (aurEff->IsAffectingSpell(affectedSpell))
            return true;
        return false;
    });
}

int32 Unit::GetMaxNegativeAuraModifierByAffectMask(AuraType auraType, SpellInfo const* affectedSpell) const
{
    return GetMaxNegativeAuraModifier(auraType, [affectedSpell](AuraEffect const* aurEff) -> bool
    {
        if (aurEff->IsAffectingSpell(affectedSpell))
            return true;
        return false;
    });
}

void Unit::InitStatBuffMods()
{
    for (uint8 i = STAT_STRENGTH; i < MAX_STATS; ++i)
    {
        m_floatStatPosBuff[i] = 0.0f;
        m_floatStatNegBuff[i] = 0.0f;
        UpdateStatBuffModForClient(Stats(i));
    }
}

void Unit::UpdateStatBuffMod(Stats stat)
{
    float modPos = 0.0f;
    float modNeg = 0.0f;
    float factor = 0.0f;

    UnitMods const unitMod = static_cast<UnitMods>(UNIT_MOD_STAT_START + AsUnderlyingType(stat));

    // includes value from items and enchantments
    float modValue = GetFlatModifierValue(unitMod, BASE_VALUE);
    if (modValue > 0.f)
        modPos += modValue;
    else
        modNeg += modValue;

    if (IsGuardian())
    {
        modValue = static_cast<Guardian*>(this)->GetBonusStatFromOwner(stat);
        if (modValue > 0.f)
            modPos += modValue;
        else
            modNeg += modValue;
    }

    // SPELL_AURA_MOD_STAT_BONUS_PCT only affects BASE_VALUE
    modPos = CalculatePct(modPos, std::max(GetFlatModifierValue(unitMod, BASE_PCT_EXCLUDE_CREATE), -100.0f));
    modNeg = CalculatePct(modNeg, std::max(GetFlatModifierValue(unitMod, BASE_PCT_EXCLUDE_CREATE), -100.0f));

    modPos += GetTotalAuraModifier(SPELL_AURA_MOD_STAT, [stat](AuraEffect const* aurEff) -> bool
        {
            if ((aurEff->GetMiscValue() < 0 || aurEff->GetMiscValue() == stat) && aurEff->GetAmount() > 0)
                return true;
            return false;
        });

    modNeg += GetTotalAuraModifier(SPELL_AURA_MOD_STAT, [stat](AuraEffect const* aurEff) -> bool
        {
            if ((aurEff->GetMiscValue() < 0 || aurEff->GetMiscValue() == stat) && aurEff->GetAmount() < 0)
                return true;
            return false;
        });

    factor = GetTotalAuraMultiplier(SPELL_AURA_MOD_PERCENT_STAT, [stat](AuraEffect const* aurEff) -> bool
        {
            if (aurEff->GetMiscValue() == -1 || aurEff->GetMiscValue() == stat)
                return true;
            return false;
        });

    factor *= GetTotalAuraMultiplier(SPELL_AURA_MOD_TOTAL_STAT_PERCENTAGE, [stat](AuraEffect const* aurEff) -> bool
        {
            if (aurEff->GetMiscValue() == -1 || aurEff->GetMiscValue() == stat)
                return true;
            return false;
        });

    modPos *= factor;
    modNeg *= factor;

    m_floatStatPosBuff[stat] = modPos;
    m_floatStatNegBuff[stat] = modNeg;

    UpdateStatBuffModForClient(stat);
}

void Unit::UpdateStatBuffModForClient(Stats stat)
{
    SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::StatPosBuff, stat), int32(m_floatStatPosBuff[stat]));
    SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::StatNegBuff, stat), int32(m_floatStatNegBuff[stat]));
}

void Unit::_RegisterDynObject(DynamicObject* dynObj)
{
    m_dynObj.push_back(dynObj);
    if (GetTypeId() == TYPEID_UNIT && IsAIEnabled())
        ToCreature()->AI()->JustRegisteredDynObject(dynObj);
}

void Unit::_UnregisterDynObject(DynamicObject* dynObj)
{
    std::erase(m_dynObj, dynObj);
    if (GetTypeId() == TYPEID_UNIT && IsAIEnabled())
        ToCreature()->AI()->JustUnregisteredDynObject(dynObj);
}

DynamicObject* Unit::GetDynObject(uint32 spellId) const
{
    std::vector<DynamicObject*> dynamicobjects = GetDynObjects(spellId);
    return dynamicobjects.empty() ? nullptr : dynamicobjects.front();
}

std::vector<DynamicObject*> Unit::GetDynObjects(uint32 spellId) const
{
    std::vector<DynamicObject*> dynamicobjects;
    for (DynObjectList::const_iterator i = m_dynObj.begin(); i != m_dynObj.end(); ++i)
        if ((*i)->GetSpellId() == spellId)
            dynamicobjects.push_back(*i);

    return dynamicobjects;
}

void Unit::RemoveDynObject(uint32 spellId)
{
    for (DynObjectList::iterator i = m_dynObj.begin(); i != m_dynObj.end();)
    {
        DynamicObject* dynObj = *i;
        if (dynObj->GetSpellId() == spellId)
        {
            dynObj->Remove();
            i = m_dynObj.begin();
        }
        else
            ++i;
    }
}

void Unit::RemoveAllDynObjects()
{
    while (!m_dynObj.empty())
        m_dynObj.back()->Remove();
}

GameObject* Unit::GetGameObject(uint32 spellId) const
{
    std::vector<GameObject*> gameobjects = GetGameObjects(spellId);
    return gameobjects.empty() ? nullptr : gameobjects.front();
}

std::vector<GameObject*> Unit::GetGameObjects(uint32 spellId) const
{
    std::vector<GameObject*> gameobjects;
    for (GameObjectList::const_iterator i = m_gameObj.begin(); i != m_gameObj.end(); ++i)
        if ((*i)->GetSpellId() == spellId)
            gameobjects.push_back(*i);

    return gameobjects;
}

void Unit::AddGameObject(GameObject* gameObj)
{
    if (!gameObj || !gameObj->GetOwnerGUID().IsEmpty())
        return;

    m_gameObj.push_back(gameObj);
    gameObj->SetOwnerGUID(GetGUID());

    if (gameObj->GetSpellId())
    {
        SpellInfo const* createBySpell = sSpellMgr->GetSpellInfo(gameObj->GetSpellId(), GetMap()->GetDifficultyID());
        // Need disable spell use for owner
        if (createBySpell && createBySpell->IsCooldownStartedOnEvent())
            // note: item based cooldowns and cooldown spell mods with charges ignored (unknown existing cases)
            GetSpellHistory()->StartCooldown(createBySpell, 0, nullptr, true);
    }

    if (GetTypeId() == TYPEID_UNIT && ToCreature()->IsAIEnabled())
        ToCreature()->AI()->JustSummonedGameobject(gameObj);
}

void Unit::RemoveGameObject(GameObject* gameObj, bool del)
{
    if (!gameObj || gameObj->GetOwnerGUID() != GetGUID())
        return;

    gameObj->SetOwnerGUID(ObjectGuid::Empty);

    for (uint8 i = 0; i < MAX_GAMEOBJECT_SLOT; ++i)
    {
        if (m_ObjectSlot[i] == gameObj->GetGUID())
        {
            m_ObjectSlot[i].Clear();
            break;
        }
    }

    // GO created by some spell
    if (uint32 spellid = gameObj->GetSpellId())
    {
        RemoveAurasDueToSpell(spellid);

        SpellInfo const* createBySpell = sSpellMgr->GetSpellInfo(spellid, GetMap()->GetDifficultyID());
        // Need activate spell use for owner
        if (createBySpell && createBySpell->IsCooldownStartedOnEvent())
            // note: item based cooldowns and cooldown spell mods with charges ignored (unknown existing cases)
            GetSpellHistory()->SendCooldownEvent(createBySpell);
    }

    m_gameObj.remove(gameObj);

    if (GetTypeId() == TYPEID_UNIT && ToCreature()->IsAIEnabled())
        ToCreature()->AI()->SummonedGameobjectDespawn(gameObj);

    if (del)
    {
        gameObj->SetRespawnTime(0);
        gameObj->Delete();
    }
}

void Unit::RemoveGameObject(uint32 spellid, bool del)
{
    if (m_gameObj.empty())
        return;
    GameObjectList::iterator i, next;
    for (i = m_gameObj.begin(); i != m_gameObj.end(); i = next)
    {
        next = i;
        if (spellid == 0 || (*i)->GetSpellId() == spellid)
        {
            (*i)->SetOwnerGUID(ObjectGuid::Empty);
            if (del)
            {
                (*i)->SetRespawnTime(0);
                (*i)->Delete();
            }

            next = m_gameObj.erase(i);
        }
        else
            ++next;
    }
}

void Unit::RemoveAllGameObjects()
{
    // remove references to unit
    while (!m_gameObj.empty())
    {
        GameObjectList::iterator i = m_gameObj.begin();
        (*i)->SetOwnerGUID(ObjectGuid::Empty);
        (*i)->SetRespawnTime(0);
        (*i)->Delete();
        m_gameObj.erase(i);
    }
}

void Unit::_RegisterAreaTrigger(AreaTrigger* areaTrigger)
{
    m_areaTrigger.push_back(areaTrigger);
    if (GetTypeId() == TYPEID_UNIT && IsAIEnabled())
        ToCreature()->AI()->JustRegisteredAreaTrigger(areaTrigger);
}

void Unit::_UnregisterAreaTrigger(AreaTrigger* areaTrigger)
{
    std::erase(m_areaTrigger, areaTrigger);
    if (GetTypeId() == TYPEID_UNIT && IsAIEnabled())
        ToCreature()->AI()->JustUnregisteredAreaTrigger(areaTrigger);
}

AreaTrigger* Unit::GetAreaTrigger(uint32 spellId) const
{
    std::vector<AreaTrigger*> areaTriggers = GetAreaTriggers(spellId);
    return areaTriggers.empty() ? nullptr : areaTriggers.front();
}

std::vector<AreaTrigger*> Unit::GetAreaTriggers(uint32 spellId) const
{
    std::vector<AreaTrigger*> areaTriggers;
    for (AreaTriggerList::const_iterator i = m_areaTrigger.begin(); i != m_areaTrigger.end(); ++i)
        if ((*i)->GetSpellId() == spellId)
            areaTriggers.push_back(*i);

    return areaTriggers;
}

void Unit::RemoveAreaTrigger(uint32 spellId)
{
    for (AreaTriggerList::iterator i = m_areaTrigger.begin(); i != m_areaTrigger.end();)
    {
        AreaTrigger* areaTrigger = *i;
        if (areaTrigger->GetSpellId() == spellId)
        {
            areaTrigger->Remove();
            i = m_areaTrigger.begin();
        }
        else
            ++i;
    }
}

void Unit::RemoveAreaTrigger(AuraEffect const* aurEff)
{
    for (AreaTrigger* areaTrigger : m_areaTrigger)
    {
        if (areaTrigger->GetAuraEffect() == aurEff)
        {
            areaTrigger->Remove();
            break; // There can only be one AreaTrigger per AuraEffect
        }
    }
}

void Unit::RemoveAllAreaTriggers()
{
    while (!m_areaTrigger.empty())
        m_areaTrigger.back()->Remove();
}

void Unit::SendSpellNonMeleeDamageLog(SpellNonMeleeDamage const* log)
{
    WorldPackets::CombatLog::SpellNonMeleeDamageLog packet;
    packet.Me = log->target->GetGUID();
    packet.CasterGUID = log->attacker ? log->attacker->GetGUID() : ObjectGuid::Empty;
    packet.CastID = log->castId;
    packet.SpellID = log->Spell ? log->Spell->Id : 0;
    packet.Visual = log->SpellVisual;
    packet.Damage = log->damage;
    packet.OriginalDamage = log->originalDamage;
    if (log->damage > log->preHitHealth)
        packet.Overkill = log->damage - log->preHitHealth;
    else
        packet.Overkill = -1;

    packet.SchoolMask = log->schoolMask;
    packet.Absorbed = log->absorb;
    packet.Resisted = log->resist;
    packet.ShieldBlock = log->blocked;
    packet.Periodic = log->periodicLog;
    packet.Flags = log->HitInfo;

    WorldPackets::Spells::ContentTuningParams contentTuningParams;
    if (contentTuningParams.GenerateDataForUnits(log->attacker, log->target))
        packet.ContentTuning = contentTuningParams;

    SendCombatLogMessage(&packet);
}

/*static*/ void Unit::ProcSkillsAndAuras(Unit* actor, Unit* actionTarget, ProcFlagsInit const& typeMaskActor, ProcFlagsInit const& typeMaskActionTarget,
                                         ProcFlagsSpellType spellTypeMask, ProcFlagsSpellPhase spellPhaseMask, ProcFlagsHit hitMask,
                                         Spell* spell, DamageInfo* damageInfo, HealInfo* healInfo)
{
    static constexpr int32 ProcChainHardLimit = 10;
    if (spell && spell->GetProcChainLength() >= ProcChainHardLimit)
    {
        TC_LOG_ERROR("spells.aura.effect", "Unit::ProcSkillsAndAuras: Possible infinite proc loop detected, current triggering spell {}", spell->GetDebugInfo().c_str());
        return;
    }

    WeaponAttackType attType = damageInfo ? damageInfo->GetAttackType() : BASE_ATTACK;
    SpellInfo const* spellInfo = [&]() -> SpellInfo const*
    {
        if (spell)
            return spell->GetSpellInfo();
        if (damageInfo)
            return damageInfo->GetSpellInfo();
        if (healInfo)
            return healInfo->GetSpellInfo();
        return nullptr;
    }();
    if (typeMaskActor && actor && !(spellInfo && spellInfo->HasAttribute(SPELL_ATTR3_SUPPRESS_CASTER_PROCS)))
        actor->ProcSkillsAndReactives(false, actionTarget, typeMaskActor, hitMask, attType);

    if (typeMaskActionTarget && actionTarget && !(spellInfo && spellInfo->HasAttribute(SPELL_ATTR3_SUPPRESS_TARGET_PROCS)))
        actionTarget->ProcSkillsAndReactives(true, actor, typeMaskActionTarget, hitMask, attType);

    if (actor)
        actor->TriggerAurasProcOnEvent(nullptr, nullptr, actionTarget, typeMaskActor, typeMaskActionTarget, spellTypeMask, spellPhaseMask, hitMask, spell, damageInfo, healInfo);
}

void Unit::SendPeriodicAuraLog(SpellPeriodicAuraLogInfo* info)
{
    AuraEffect const* aura = info->auraEff;
    WorldPackets::CombatLog::SpellPeriodicAuraLog data;
    data.TargetGUID = GetGUID();
    data.CasterGUID = aura->GetCasterGUID();
    data.SpellID = aura->GetId();
    data.LogData.Initialize(this);

    WorldPackets::CombatLog::SpellPeriodicAuraLog::SpellLogEffect spellLogEffect;
    spellLogEffect.Effect = aura->GetAuraType();
    spellLogEffect.Amount = info->damage;
    spellLogEffect.OriginalDamage = info->originalDamage;
    spellLogEffect.OverHealOrKill = info->overDamage;
    spellLogEffect.SchoolMaskOrPower = aura->GetSpellInfo()->GetSchoolMask();
    spellLogEffect.AbsorbedOrAmplitude = info->absorb;
    spellLogEffect.Resisted = info->resist;
    spellLogEffect.Crit = info->critical;
    /// @todo: implement debug info

    WorldPackets::Spells::ContentTuningParams contentTuningParams;
    if (Unit* caster = ObjectAccessor::GetUnit(*this, aura->GetCasterGUID()))
        if (contentTuningParams.GenerateDataForUnits(caster, this))
            spellLogEffect.ContentTuning = contentTuningParams;

    data.Effects.push_back(spellLogEffect);

    SendCombatLogMessage(&data);
}

void Unit::SendSpellDamageResist(Unit* target, uint32 spellId)
{
    WorldPackets::CombatLog::ProcResist procResist;
    procResist.Caster = GetGUID();
    procResist.SpellID = spellId;
    procResist.Target = target->GetGUID();
    SendMessageToSet(procResist.Write(), true);
}

void Unit::SendSpellDamageImmune(Unit* target, uint32 spellId, bool isPeriodic)
{
    WorldPackets::CombatLog::SpellOrDamageImmune spellOrDamageImmune;
    spellOrDamageImmune.CasterGUID = GetGUID();
    spellOrDamageImmune.VictimGUID = target->GetGUID();
    spellOrDamageImmune.SpellID = spellId;
    spellOrDamageImmune.IsPeriodic = isPeriodic;
    SendMessageToSet(spellOrDamageImmune.Write(), true);
}

void Unit::SendAttackStateUpdate(CalcDamageInfo* damageInfo)
{
    WorldPackets::CombatLog::AttackerStateUpdate packet;
    packet.HitInfo = damageInfo->HitInfo;
    packet.AttackerGUID = damageInfo->Attacker->GetGUID();
    packet.VictimGUID = damageInfo->Target->GetGUID();
    packet.Damage = damageInfo->Damage;
    packet.OriginalDamage = damageInfo->OriginalDamage;
    int32 overkill = damageInfo->Damage - damageInfo->Target->GetHealth();
    packet.OverDamage = (overkill < 0 ? -1 : overkill);

    packet.SubDmg.emplace();
    packet.SubDmg->SchoolMask = damageInfo->DamageSchoolMask;   // School of sub damage
    packet.SubDmg->FDamage = damageInfo->Damage;                // sub damage
    packet.SubDmg->Damage = damageInfo->Damage;                 // Sub Damage
    packet.SubDmg->Absorbed = damageInfo->Absorb;
    packet.SubDmg->Resisted = damageInfo->Resist;

    packet.VictimState = damageInfo->TargetState;
    packet.BlockAmount = damageInfo->Blocked;

    packet.LogData.Initialize(damageInfo->Attacker);

    WorldPackets::Spells::ContentTuningParams contentTuningParams;
    if (contentTuningParams.GenerateDataForUnits(damageInfo->Attacker, damageInfo->Target))
        packet.ContentTuning = contentTuningParams;

    SendCombatLogMessage(&packet);
}

void Unit::SendAttackStateUpdate(uint32 HitInfo, Unit* target, uint8 /*SwingType*/, SpellSchoolMask damageSchoolMask, uint32 Damage, uint32 AbsorbDamage, uint32 Resist, VictimState TargetState, uint32 BlockedAmount)
{
    CalcDamageInfo dmgInfo;
    dmgInfo.HitInfo = HitInfo;
    dmgInfo.Attacker = this;
    dmgInfo.Target = target;
    dmgInfo.Damage = Damage - AbsorbDamage - Resist - BlockedAmount;
    dmgInfo.OriginalDamage = Damage;
    dmgInfo.DamageSchoolMask = damageSchoolMask;
    dmgInfo.Absorb = AbsorbDamage;
    dmgInfo.Resist = Resist;
    dmgInfo.TargetState = TargetState;
    dmgInfo.Blocked = BlockedAmount;
    SendAttackStateUpdate(&dmgInfo);
}

void Unit::SetPowerType(Powers power, bool sendUpdate/* = true*/, bool onInit /*= false*/)
{
    if (!onInit && GetPowerType() == power)
        return;

    PowerTypeEntry const* powerTypeEntry = sDB2Manager.GetPowerTypeEntry(power);
    if (!powerTypeEntry)
        return;

    if (IsCreature() && !powerTypeEntry->GetFlags().HasFlag(PowerTypeFlags::IsUsedByNPCs))
        return;

    SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::DisplayPower), power);

    // Update max power
    UpdateMaxPower(power);

    // Update current power
    if (!onInit)
    {
        switch (power)
        {
            case POWER_MANA: // Keep the same (druid form switching...)
            case POWER_ENERGY:
                break;
            case POWER_RAGE: // Reset to zero
                SetPower(POWER_RAGE, 0);
            break;
            case POWER_FOCUS: // Make it full
                SetFullPower(power);
            break;
            default:
                break;
        }
    }
    else
        SetInitialPowerValue(power);

    if (!sendUpdate)
        return;

    if (Player* thisPlayer = ToPlayer())
    {
        if (thisPlayer->GetGroup())
            thisPlayer->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_POWER_TYPE);
    }
    /*else if (Pet* pet = ToCreature()->ToPet()) TODO 6.x
    {
        if (pet->isControlled())
            pet->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_PET_POWER_TYPE);
    }*/
}

void Unit::SetInitialPowerValue(Powers powerType)
{
    PowerTypeEntry const* powerTypeEntry = sDB2Manager.GetPowerTypeEntry(powerType);
    if (!powerTypeEntry)
        return;

    if (powerTypeEntry->GetFlags().HasFlag(PowerTypeFlags::UnitsUseDefaultPowerOnInit))
        SetPower(powerType, powerTypeEntry->DefaultPower);
    else
        SetFullPower(powerType);
}

Powers Unit::CalculateDisplayPowerType() const
{
    Powers displayPower = POWER_MANA;
    switch (GetShapeshiftForm())
    {
        case FORM_GHOUL:
        case FORM_CAT_FORM:
            displayPower = POWER_ENERGY;
            break;
        case FORM_BEAR_FORM:
            displayPower = POWER_RAGE;
            break;
        case FORM_TRAVEL_FORM:
        case FORM_GHOST_WOLF:
            displayPower = POWER_MANA;
            break;
        default:
        {
            Unit::AuraEffectList const& powerTypeAuras = GetAuraEffectsByType(SPELL_AURA_MOD_POWER_DISPLAY);
            if (!powerTypeAuras.empty())
            {
                AuraEffect const* powerTypeAura = powerTypeAuras.front();
                displayPower = Powers(powerTypeAura->GetMiscValue());
            }
            else
            {
                ChrClassesEntry const* cEntry = sChrClassesStore.LookupEntry(GetClass());
                if (cEntry && cEntry->DisplayPower < MAX_POWERS)
                    displayPower = Powers(cEntry->DisplayPower);

                if (Vehicle* vehicle = GetVehicleKit())
                {
                    if (PowerDisplayEntry const* powerDisplay = sPowerDisplayStore.LookupEntry(vehicle->GetVehicleInfo()->PowerDisplayID[0]))
                        displayPower = Powers(powerDisplay->ActualType);
                }
                else if (IsHunterPet())
                    displayPower = POWER_FOCUS;
            }
            break;
        }
    }

    return displayPower;
}

void Unit::UpdateDisplayPower()
{
    SetPowerType(CalculateDisplayPowerType());
}

void Unit::SetSheath(SheathState sheathed)
{
    SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::SheatheState), sheathed);
    if (sheathed == SHEATH_STATE_UNARMED)
        RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::Sheathing);
}

void Unit::_addAttacker(Unit* pAttacker)
{
    m_attackers.insert(pAttacker);
}

void Unit::_removeAttacker(Unit* pAttacker)
{
    m_attackers.erase(pAttacker);
}

Unit* Unit::getAttackerForHelper() const                 // If someone wants to help, who to give them
{
    if (!IsEngaged())
        return nullptr;

    if (Unit* victim = GetVictim())
        if ((!IsPet() && !GetPlayerMovingMe()) || IsInCombatWith(victim))
            return victim;

    CombatManager const& mgr = GetCombatManager();
    // pick arbitrary targets; our pvp combat > owner's pvp combat > our pve combat > owner's pve combat
    Unit* owner = GetCharmerOrOwner();
    if (mgr.HasPvPCombat())
        return mgr.GetPvPCombatRefs().begin()->second->GetOther(this);
    if (owner && (owner->GetCombatManager().HasPvPCombat()))
        return owner->GetCombatManager().GetPvPCombatRefs().begin()->second->GetOther(owner);
    if (mgr.HasPvECombat())
        return mgr.GetPvECombatRefs().begin()->second->GetOther(this);
    if (owner && (owner->GetCombatManager().HasPvECombat()))
        return owner->GetCombatManager().GetPvECombatRefs().begin()->second->GetOther(owner);
    return nullptr;
}

bool Unit::Attack(Unit* victim, bool meleeAttack)
{
    if (!victim || victim == this)
        return false;

    // dead units can neither attack nor be attacked
    if (!IsAlive() || !victim->IsInWorld() || !victim->IsAlive())
        return false;

    // player cannot attack in mount state
    if (GetTypeId() == TYPEID_PLAYER && IsMounted())
        return false;

    Creature* creature = ToCreature();
    // creatures cannot attack while evading
    if (creature && creature->IsInEvadeMode())
        return false;

    // nobody can attack GM in GM-mode
    if (victim->GetTypeId() == TYPEID_PLAYER)
    {
        if (victim->ToPlayer()->IsGameMaster())
            return false;
    }
    else
    {
        if (victim->ToCreature()->IsEvadingAttacks())
            return false;
    }

    // remove SPELL_AURA_MOD_UNATTACKABLE at attack (in case non-interruptible spells stun aura applied also that not let attack)
    if (HasAuraType(SPELL_AURA_MOD_UNATTACKABLE))
        RemoveAurasByType(SPELL_AURA_MOD_UNATTACKABLE);

    if (m_attacking)
    {
        if (m_attacking == victim)
        {
            // switch to melee attack from ranged/magic
            if (meleeAttack)
            {
                if (!HasUnitState(UNIT_STATE_MELEE_ATTACKING))
                {
                    AddUnitState(UNIT_STATE_MELEE_ATTACKING);
                    SendMeleeAttackStart(victim);
                    return true;
                }
            }
            else if (HasUnitState(UNIT_STATE_MELEE_ATTACKING))
            {
                ClearUnitState(UNIT_STATE_MELEE_ATTACKING);
                SendMeleeAttackStop(victim);
                return true;
            }
            return false;
        }

        // switch target
        InterruptSpell(CURRENT_MELEE_SPELL);
        if (!meleeAttack)
            ClearUnitState(UNIT_STATE_MELEE_ATTACKING);
    }

    if (m_attacking)
        m_attacking->_removeAttacker(this);

    m_attacking = victim;
    m_attacking->_addAttacker(this);

    // Set our target
    SetTarget(victim->GetGUID());

    if (meleeAttack)
        AddUnitState(UNIT_STATE_MELEE_ATTACKING);

    // set position before any AI calls/assistance
    //if (GetTypeId() == TYPEID_UNIT)
    //    ToCreature()->SetCombatStartPosition(GetPositionX(), GetPositionY(), GetPositionZ());

    if (creature && !IsControlledByPlayer())
    {
        EngageWithTarget(victim); // ensure that anything we're attacking has threat

        creature->SendAIReaction(AI_REACTION_HOSTILE);
        creature->CallAssistance();

        // Remove emote and stand state - will be restored on creature reset
        SetEmoteState(EMOTE_ONESHOT_NONE);
        SetStandState(UNIT_STAND_STATE_STAND);
    }

    // delay offhand weapon attack by 50% of the base attack time
    if (haveOffhandWeapon() && GetTypeId() != TYPEID_PLAYER)
        setAttackTimer(OFF_ATTACK, std::max(getAttackTimer(OFF_ATTACK), getAttackTimer(BASE_ATTACK) + uint32(CalculatePct(GetBaseAttackTime(BASE_ATTACK), 50))));

    if (meleeAttack)
        SendMeleeAttackStart(victim);

    // Let the pet know we've started attacking someting. Handles melee attacks only
    // Spells such as auto-shot and others handled in WorldSession::HandleCastSpellOpcode
    if (GetTypeId() == TYPEID_PLAYER)
    {
        for (Unit* controlled : m_Controlled)
            if (Creature* cControlled = controlled->ToCreature())
                if (CreatureAI* controlledAI = cControlled->AI())
                    controlledAI->OwnerAttacked(victim);
    }

    return true;
}

bool Unit::AttackStop()
{
    if (!m_attacking)
        return false;

    Unit* victim = m_attacking;

    m_attacking->_removeAttacker(this);
    m_attacking = nullptr;

    // Clear our target
    SetTarget(ObjectGuid::Empty);

    ClearUnitState(UNIT_STATE_MELEE_ATTACKING);

    InterruptSpell(CURRENT_MELEE_SPELL);

    // reset only at real combat stop
    if (Creature* creature = ToCreature())
    {
        creature->SetNoCallAssistance(false);
    }

    SendMeleeAttackStop(victim);

    return true;
}

void Unit::ValidateAttackersAndOwnTarget()
{
    // iterate attackers
    UnitVector toRemove;
    AttackerSet const& attackers = getAttackers();
    for (Unit* attacker : attackers)
        if (!attacker->IsValidAttackTarget(this))
            toRemove.push_back(attacker);

    for (Unit* attacker : toRemove)
        attacker->AttackStop();

    // remove our own victim
    if (Unit* victim = GetVictim())
        if (!IsValidAttackTarget(victim))
            AttackStop();
}

void Unit::CombatStop(bool includingCast, bool mutualPvP, bool (*unitFilter)(Unit const* otherUnit))
{
    if (includingCast && IsNonMeleeSpellCast(false))
        InterruptNonMeleeSpells(false);

    AttackStop();
    if (!unitFilter)
        RemoveAllAttackers();
    else
    {
        std::vector<Unit*> attackersToRemove;
        attackersToRemove.reserve(m_attackers.size());
        std::copy_if(m_attackers.begin(), m_attackers.end(), std::back_inserter(attackersToRemove), unitFilter);

        for (Unit* attacker : attackersToRemove)
            attacker->AttackStop();
    }

    if (GetTypeId() == TYPEID_PLAYER)
        ToPlayer()->SendAttackSwingCancelAttack();     // melee and ranged forced attack cancel

    m_combatManager.EndAllPvECombat(unitFilter);
    if (mutualPvP)
        m_combatManager.EndAllPvPCombat(unitFilter);
    else // vanish and brethren are weird
        m_combatManager.SuppressPvPCombat(unitFilter);
}

void Unit::CombatStopWithPets(bool includingCast)
{
    CombatStop(includingCast);

    for (Unit* minion : m_Controlled)
        minion->CombatStop(includingCast);
}

bool Unit::isAttackingPlayer() const
{
    if (HasUnitState(UNIT_STATE_ATTACK_PLAYER))
        return true;

    for (ControlList::const_iterator itr = m_Controlled.begin(); itr != m_Controlled.end(); ++itr)
        if ((*itr)->isAttackingPlayer())
            return true;

    for (uint8 i = 0; i < MAX_SUMMON_SLOT; ++i)
        if (!m_SummonSlot[i].IsEmpty())
            if (Creature* summon = GetMap()->GetCreature(m_SummonSlot[i]))
                if (summon->isAttackingPlayer())
                    return true;

    return false;
}

void Unit::RemoveAllAttackers()
{
    while (!m_attackers.empty())
    {
        AttackerSet::iterator iter = m_attackers.begin();
        if (!(*iter)->AttackStop())
        {
            TC_LOG_ERROR("entities.unit", "WORLD: Unit has an attacker that isn't attacking it!");
            m_attackers.erase(iter);
        }
    }
}

void Unit::ModifyAuraState(AuraStateType flag, bool apply)
{
    uint32 mask = 1 << (flag - 1);
    if (apply)
    {
        if (!(*m_unitData->AuraState & mask))
        {
            SetUpdateFieldFlagValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::AuraState), mask);
            if (GetTypeId() == TYPEID_PLAYER)
            {
                PlayerSpellMap const& sp_list = ToPlayer()->GetSpellMap();
                for (PlayerSpellMap::const_iterator itr = sp_list.begin(); itr != sp_list.end(); ++itr)
                {
                    if (itr->second.state == PLAYERSPELL_REMOVED || itr->second.disabled)
                        continue;
                    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(itr->first, DIFFICULTY_NONE);
                    if (!spellInfo || !spellInfo->IsPassive())
                        continue;
                    if (spellInfo->CasterAuraState == uint32(flag))
                        CastSpell(this, itr->first, true);
                }
            }
            else if (Pet* pet = ToCreature()->ToPet())
            {
                for (PetSpellMap::const_iterator itr = pet->m_spells.begin(); itr != pet->m_spells.end(); ++itr)
                {
                    if (itr->second.state == PETSPELL_REMOVED)
                        continue;
                    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(itr->first, DIFFICULTY_NONE);
                    if (!spellInfo || !spellInfo->IsPassive())
                        continue;
                    if (spellInfo->CasterAuraState == uint32(flag))
                        CastSpell(this, itr->first, true);
                }
            }
        }
    }
    else
    {
        if (*m_unitData->AuraState & mask)
        {
            RemoveUpdateFieldFlagValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::AuraState), mask);

            Unit::AuraApplicationMap& tAuras = GetAppliedAuras();
            for (Unit::AuraApplicationMap::iterator itr = tAuras.begin(); itr != tAuras.end();)
            {
                SpellInfo const* spellProto = itr->second->GetBase()->GetSpellInfo();
                if (itr->second->GetBase()->GetCasterGUID() == GetGUID() && spellProto->CasterAuraState == uint32(flag) && (spellProto->IsPassive() || flag != AURA_STATE_ENRAGED))
                    RemoveAura(itr);
                else
                    ++itr;
            }
        }
    }
}

uint32 Unit::BuildAuraStateUpdateForTarget(Unit const* target) const
{
    uint32 auraStates = *m_unitData->AuraState & ~(PER_CASTER_AURA_STATE_MASK);
    for (AuraStateAurasMap::const_iterator itr = m_auraStateAuras.begin(); itr != m_auraStateAuras.end(); ++itr)
        if ((1 << (itr->first - 1)) & PER_CASTER_AURA_STATE_MASK)
            if (itr->second->GetBase()->GetCasterGUID() == target->GetGUID())
                auraStates |= (1 << (itr->first - 1));

    return auraStates;
}

bool Unit::HasAuraState(AuraStateType flag, SpellInfo const* spellProto, Unit const* Caster) const
{
    if (Caster)
    {
        if (spellProto)
        {
            if (Caster->HasAuraTypeWithAffectMask(SPELL_AURA_ABILITY_IGNORE_AURASTATE, spellProto))
                return true;
        }

        // Check per caster aura state
        // If aura with aurastate by caster not found return false
        if ((1 << (flag - 1)) & PER_CASTER_AURA_STATE_MASK)
        {
            AuraStateAurasMapBounds range = m_auraStateAuras.equal_range(flag);
            for (AuraStateAurasMap::const_iterator itr = range.first; itr != range.second; ++itr)
                if (itr->second->GetBase()->GetCasterGUID() == Caster->GetGUID())
                    return true;
            return false;
        }
    }

    return (*m_unitData->AuraState & (1 << (flag - 1))) != 0;
}

void Unit::SetOwnerGUID(ObjectGuid owner)
{
    if (GetOwnerGUID() == owner)
        return;

    SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::SummonedBy), owner);
    if (!owner)
        return;

    // Update owner dependent fields
    Player* player = ObjectAccessor::GetPlayer(*this, owner);
    if (!player || !player->HaveAtClient(this)) // if player cannot see this unit yet, he will receive needed data with create object
        return;

    UpdateData udata(GetMapId());
    WorldPacket packet;
    BuildValuesUpdateBlockForPlayerWithFlag(&udata, UF::UpdateFieldFlag::Owner, player);
    udata.BuildPacket(&packet);
    player->SendDirectMessage(&packet);
}

Unit* Unit::GetDemonCreator() const
{
    return ObjectAccessor::GetUnit(*this, GetDemonCreatorGUID());
}

Player* Unit::GetDemonCreatorPlayer() const
{
    return ObjectAccessor::GetPlayer(*this, GetDemonCreatorGUID());
}

Player* Unit::GetControllingPlayer() const
{
    ObjectGuid guid = GetCharmerOrOwnerGUID();
    if (!guid.IsEmpty())
    {
        if (Unit* master = ObjectAccessor::GetUnit(*this, guid))
            return master->GetControllingPlayer();
        return nullptr;
    }
    else
        return const_cast<Player*>(ToPlayer());
}

Minion* Unit::GetFirstMinion() const
{
    ObjectGuid pet_guid = GetMinionGUID();
    if (!pet_guid.IsEmpty())
    {
        if (Creature* pet = ObjectAccessor::GetCreatureOrPetOrVehicle(*this, pet_guid))
            if (pet->HasUnitTypeMask(UNIT_MASK_MINION))
                return (Minion*)pet;

        TC_LOG_ERROR("entities.unit", "Unit::GetFirstMinion: Minion {} not exist.", pet_guid.ToString());
        const_cast<Unit*>(this)->SetMinionGUID(ObjectGuid::Empty);
    }

    return nullptr;
}

Guardian* Unit::GetGuardianPet() const
{
    ObjectGuid pet_guid = GetPetGUID();
    if (!pet_guid.IsEmpty())
    {
        if (Creature* pet = ObjectAccessor::GetCreatureOrPetOrVehicle(*this, pet_guid))
            if (pet->HasUnitTypeMask(UNIT_MASK_GUARDIAN))
                return (Guardian*)pet;

        TC_LOG_FATAL("entities.unit", "Unit::GetGuardianPet: Guardian {} not exist.", pet_guid.ToString());
        const_cast<Unit*>(this)->SetPetGUID(ObjectGuid::Empty);
    }

    return nullptr;
}

void Unit::SetMinion(Minion *minion, bool apply)
{
    TC_LOG_DEBUG("entities.unit", "SetMinion {} for {}, apply {}", minion->GetEntry(), GetEntry(), apply);

    if (apply)
    {
        if (!minion->GetOwnerGUID().IsEmpty())
        {
            TC_LOG_FATAL("entities.unit", "SetMinion: Minion {} is not the minion of owner {}", minion->GetEntry(), GetEntry());
            return;
        }

        if (!IsInWorld())
        {
            TC_LOG_FATAL("entities.unit", "SetMinion: Minion being added to owner not in world. Minion: {}, Owner: {}", minion->GetGUID().ToString(), GetDebugInfo());
            return;
        }

        minion->SetOwnerGUID(GetGUID());

        m_Controlled.insert(minion);

        if (GetTypeId() == TYPEID_PLAYER)
        {
            minion->m_ControlledByPlayer = true;
            minion->SetUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED);
        }

        // Can only have one pet. If a new one is summoned, dismiss the old one.
        if (minion->IsGuardianPet())
        {
            if (Guardian* oldPet = GetGuardianPet())
            {
                if (oldPet != minion && (oldPet->IsPet() || minion->IsPet() || oldPet->GetEntry() != minion->GetEntry()))
                {
                    // remove existing minion pet
                    if (Pet* oldPetAsPet = oldPet->ToPet())
                        oldPetAsPet->Remove(PET_SAVE_NOT_IN_SLOT);
                    else
                        oldPet->UnSummon();
                    SetPetGUID(minion->GetGUID());
                    SetMinionGUID(ObjectGuid::Empty);
                }
            }
            else
            {
                SetPetGUID(minion->GetGUID());
                SetMinionGUID(ObjectGuid::Empty);
            }
        }

        if (minion->HasUnitTypeMask(UNIT_MASK_CONTROLABLE_GUARDIAN))
        {
            if (GetMinionGUID().IsEmpty())
                SetMinionGUID(minion->GetGUID());
        }

        SummonPropertiesEntry const* properties = minion->m_Properties;
        if (properties && SummonTitle(properties->Title) == SummonTitle::Companion)
        {
            SetCritterGUID(minion->GetGUID());
            if (Player const* thisPlayer = ToPlayer())
            {
                if (properties->GetFlags().HasFlag(SummonPropertiesFlags::SummonFromBattlePetJournal))
                {
                    if (BattlePets::BattlePet const* pet = thisPlayer->GetSession()->GetBattlePetMgr()->GetPet(thisPlayer->GetSummonedBattlePetGUID()))
                    {
                        minion->SetBattlePetCompanionGUID(thisPlayer->GetSummonedBattlePetGUID());
                        minion->SetBattlePetCompanionNameTimestamp(pet->NameTimestamp);
                        minion->SetWildBattlePetLevel(pet->PacketInfo.Level);

                        if (uint32 display = pet->PacketInfo.DisplayID)
                            minion->SetDisplayId(display, true);
                    }
                }
            }
        }

        // PvP, FFAPvP
        minion->ReplaceAllPvpFlags(GetPvpFlags());

        // FIXME: hack, speed must be set only at follow
        if (GetTypeId() == TYPEID_PLAYER && minion->IsPet())
            for (uint8 i = 0; i < MAX_MOVE_TYPE; ++i)
                minion->SetSpeedRate(UnitMoveType(i), m_speed_rate[i]);

        // Send infinity cooldown - client does that automatically but after relog cooldown needs to be set again
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(minion->m_unitData->CreatedBySpell, DIFFICULTY_NONE);

        if (spellInfo && (spellInfo->IsCooldownStartedOnEvent()))
            GetSpellHistory()->StartCooldown(spellInfo, 0, nullptr, true);
    }
    else
    {
        if (minion->GetOwnerGUID() != GetGUID())
        {
            TC_LOG_FATAL("entities.unit", "SetMinion: Minion {} is not the minion of owner {}", minion->GetEntry(), GetEntry());
            return;
        }

        m_Controlled.erase(minion);

        if (minion->m_Properties && SummonTitle(minion->m_Properties->Title) == SummonTitle::Companion)
            if (GetCritterGUID() == minion->GetGUID())
                SetCritterGUID(ObjectGuid::Empty);

        if (minion->IsGuardianPet())
        {
            if (GetPetGUID() == minion->GetGUID())
                SetPetGUID(ObjectGuid::Empty);
        }
        else if (minion->IsTotem())
        {
            // All summoned by totem minions must disappear when it is removed.
            if (SpellInfo const* spInfo = sSpellMgr->GetSpellInfo(minion->ToTotem()->GetSpell(), DIFFICULTY_NONE))
            {
                for (SpellEffectInfo const& spellEffectInfo : spInfo->GetEffects())
                {
                    if (!spellEffectInfo.IsEffect(SPELL_EFFECT_SUMMON))
                        continue;

                    RemoveAllMinionsByEntry(spellEffectInfo.MiscValue);
                }
            }
        }

        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(minion->m_unitData->CreatedBySpell, DIFFICULTY_NONE);
        // Remove infinity cooldown
        if (spellInfo && (spellInfo->IsCooldownStartedOnEvent()))
            GetSpellHistory()->SendCooldownEvent(spellInfo);

        //if (minion->HasUnitTypeMask(UNIT_MASK_GUARDIAN))
        {
            if (GetMinionGUID() == minion->GetGUID())
            {
                SetMinionGUID(ObjectGuid::Empty);
                // Check if there is another minion
                for (ControlList::iterator itr = m_Controlled.begin(); itr != m_Controlled.end(); ++itr)
                {
                    // do not use this check, creature do not have charm guid
                    //if (GetCharmedGUID() == (*itr)->GetGUID())
                    if (GetGUID() == (*itr)->GetCharmerGUID())
                        continue;

                    //ASSERT((*itr)->GetOwnerGUID() == GetGUID());
                    if ((*itr)->GetOwnerGUID() != GetGUID())
                    {
                        OutDebugInfo();
                        (*itr)->OutDebugInfo();
                        ABORT();
                    }
                    ASSERT((*itr)->GetTypeId() == TYPEID_UNIT);

                    if (!(*itr)->HasUnitTypeMask(UNIT_MASK_CONTROLABLE_GUARDIAN))
                        continue;

                    SetMinionGUID((*itr)->GetGUID());
                    // show another pet bar if there is no charm bar
                    if (GetTypeId() == TYPEID_PLAYER && !GetCharmedGUID())
                    {
                        if ((*itr)->IsPet())
                            ToPlayer()->PetSpellInitialize();
                        else
                            ToPlayer()->CharmSpellInitialize();
                    }
                    break;
                }
            }
        }
    }
    UpdatePetCombatState();
}

void Unit::GetAllMinionsByEntry(std::list<TempSummon*>& Minions, uint32 entry)
{
    for (Unit::ControlList::iterator itr = m_Controlled.begin(); itr != m_Controlled.end(); ++itr)
    {
        Unit* unit = *itr;
        if (unit->GetEntry() == entry && unit->IsSummon()) // minion, actually
            Minions.push_back(unit->ToTempSummon());
    }
}

void Unit::RemoveAllMinionsByEntry(uint32 entry)
{
    for (Unit::ControlList::iterator itr = m_Controlled.begin(); itr != m_Controlled.end();)
    {
        Unit* unit = *itr;
        ++itr;
        if (unit->GetEntry() == entry && unit->GetTypeId() == TYPEID_UNIT
            && unit->ToCreature()->IsSummon()) // minion, actually
            unit->ToTempSummon()->UnSummon();
        // i think this is safe because i have never heard that a despawned minion will trigger a same minion
    }
}

void Unit::SetCharm(Unit* charm, bool apply)
{
    if (apply)
    {
        if (GetTypeId() == TYPEID_PLAYER)
        {
            ASSERT(GetCharmedGUID().IsEmpty(),
                "Player %s is trying to charm unit %u, but it already has a charmed unit %s", GetName().c_str(), charm->GetEntry(), GetCharmedGUID().ToString().c_str());
            SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::Charm), charm->GetGUID());
            m_charmed = charm;

            charm->m_ControlledByPlayer = true;
            /// @todo maybe we can use this flag to check if controlled by player
            charm->SetUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED);
        }
        else
            charm->m_ControlledByPlayer = false;

        // PvP, FFAPvP
        charm->ReplaceAllPvpFlags(GetPvpFlags());

        ASSERT(charm->GetCharmerGUID().IsEmpty(),
            "Unit %u is being charmed, but it already has a charmer %s", charm->GetEntry(), charm->GetCharmerGUID().ToString().c_str());
        charm->SetUpdateFieldValue(charm->m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::CharmedBy), GetGUID());
        charm->m_charmer = this;

        _isWalkingBeforeCharm = charm->IsWalking();
        if (_isWalkingBeforeCharm)
            charm->SetWalk(false);

        m_Controlled.insert(charm);
    }
    else
    {
        charm->ClearUnitState(UNIT_STATE_CHARMED);

        if (GetTypeId() == TYPEID_PLAYER)
        {
            ASSERT(GetCharmedGUID() == charm->GetGUID(),
                "Player %s is trying to uncharm unit %u, but it has another charmed unit %s", GetName().c_str(), charm->GetEntry(), GetCharmedGUID().ToString().c_str());
            SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::Charm), ObjectGuid::Empty);
            m_charmed = nullptr;
        }

        ASSERT(charm->GetCharmerGUID() == GetGUID(),
            "Unit %u is being uncharmed, but it has another charmer %s", charm->GetEntry(), charm->GetCharmerGUID().ToString().c_str());
        charm->SetUpdateFieldValue(charm->m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::CharmedBy), ObjectGuid::Empty);
        charm->m_charmer = nullptr;

        if (charm->GetTypeId() == TYPEID_PLAYER)
        {
            charm->m_ControlledByPlayer = true;
            charm->SetUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED);
            charm->ToPlayer()->UpdatePvPState();
        }
        else if (Player* player = charm->GetCharmerOrOwnerPlayerOrPlayerItself())
        {
            charm->m_ControlledByPlayer = true;
            charm->SetUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED);
            charm->ReplaceAllPvpFlags(player->GetPvpFlags());
        }
        else
        {
            charm->m_ControlledByPlayer = false;
            charm->RemoveUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED);
            charm->ReplaceAllPvpFlags(UNIT_BYTE2_FLAG_NONE);
        }

        if (charm->IsWalking() != _isWalkingBeforeCharm)
            charm->SetWalk(_isWalkingBeforeCharm);

        if (charm->GetTypeId() == TYPEID_PLAYER
            || !charm->ToCreature()->HasUnitTypeMask(UNIT_MASK_MINION)
            || charm->GetOwnerGUID() != GetGUID())
        {
            m_Controlled.erase(charm);
        }
    }
    UpdatePetCombatState();
}

/*static*/ void Unit::DealHeal(HealInfo& healInfo)
{
    int32 gain = 0;
    Unit* healer = healInfo.GetHealer();
    Unit* victim = healInfo.GetTarget();
    uint32 addhealth = healInfo.GetHeal();

    if (UnitAI* victimAI = victim->GetAI())
        victimAI->HealReceived(healer, addhealth);

    if (UnitAI* healerAI = healer ? healer->GetAI() : nullptr)
        healerAI->HealDone(victim, addhealth);

    if (addhealth)
        gain = victim->ModifyHealth(int32(addhealth));

    // Hook for OnHeal Event
    sScriptMgr->OnHeal(healer, victim, (uint32&)gain);

    Unit* unit = healer;
    if (healer && healer->GetTypeId() == TYPEID_UNIT && healer->IsTotem())
        unit = healer->GetOwner();

    if (unit)
    {
        if (Player* player = unit->ToPlayer())
        {
            if (!healInfo.GetSpellInfo() || !healInfo.GetSpellInfo()->HasAttribute(SPELL_ATTR7_DO_NOT_COUNT_FOR_PVP_SCOREBOARD))
                if (Battleground* bg = player->GetBattleground())
                    bg->UpdatePlayerScore(player, SCORE_HEALING_DONE, gain);

            // use the actual gain, as the overheal shall not be counted, skip gain 0 (it ignored anyway in to criteria)
            if (gain)
                player->UpdateCriteria(CriteriaType::HealingDone, gain, 0, 0, victim);

            player->UpdateCriteria(CriteriaType::HighestHealCast, addhealth);
        }
    }

    if (Player* player = victim->ToPlayer())
    {
        player->UpdateCriteria(CriteriaType::TotalHealReceived, gain);
        player->UpdateCriteria(CriteriaType::HighestHealReceived, addhealth);
    }

    if (gain)
        healInfo.SetEffectiveHeal(gain > 0 ? static_cast<uint32>(gain) : 0UL);
}

bool Unit::IsMagnet() const
{
    // Grounding Totem
    if (*m_unitData->CreatedBySpell == 8177) /// @todo: find a more generic solution
        return true;

    return false;
}

Unit* Unit::GetMeleeHitRedirectTarget(Unit* victim, SpellInfo const* spellInfo /*= nullptr*/)
{
    AuraEffectList const& interceptAuras = victim->GetAuraEffectsByType(SPELL_AURA_INTERCEPT_MELEE_RANGED_ATTACKS);
    for (AuraEffectList::const_iterator i = interceptAuras.begin(); i != interceptAuras.end(); ++i)
    {
        if (Unit* magnet = (*i)->GetBase()->GetCaster())
            if (IsValidAttackTarget(magnet, spellInfo) && magnet->IsWithinLOSInMap(this)
                && (!spellInfo || (spellInfo->CheckExplicitTarget(this, magnet) == SPELL_CAST_OK
                && spellInfo->CheckTarget(this, magnet, false) == SPELL_CAST_OK)))
            {
                (*i)->GetBase()->DropCharge(AURA_REMOVE_BY_EXPIRE);
                return magnet;
            }
    }
    return victim;
}

Unit* Unit::GetFirstControlled() const
{
    // Sequence: charmed, pet, other guardians
    Unit* unit = GetCharmed();
    if (!unit)
    {
        ObjectGuid guid = GetMinionGUID();
        if (!guid.IsEmpty())
            unit = ObjectAccessor::GetUnit(*this, guid);
    }

    return unit;
}

void Unit::RemoveAllControlled()
{
    // possessed pet and vehicle
    if (GetTypeId() == TYPEID_PLAYER)
        ToPlayer()->StopCastingCharm();

    while (!m_Controlled.empty())
    {
        Unit* target = *m_Controlled.begin();
        m_Controlled.erase(m_Controlled.begin());
        if (target->GetCharmerGUID() == GetGUID())
            target->RemoveCharmAuras();
        else if (target->GetOwnerGUID() == GetGUID() && target->IsSummon())
            target->ToTempSummon()->UnSummon();
        else
            TC_LOG_ERROR("entities.unit", "Unit {} is trying to release unit {} which is neither charmed nor owned by it", GetEntry(), target->GetEntry());
    }
    if (!GetPetGUID().IsEmpty())
        TC_LOG_FATAL("entities.unit", "Unit {} is not able to release its pet {}", GetEntry(), GetPetGUID().ToString());
    if (!GetMinionGUID().IsEmpty())
        TC_LOG_FATAL("entities.unit", "Unit {} is not able to release its minion {}", GetEntry(), GetMinionGUID().ToString());
    if (!GetCharmedGUID().IsEmpty())
        TC_LOG_FATAL("entities.unit", "Unit {} is not able to release its charm {}", GetEntry(), GetCharmedGUID().ToString());
    if (!IsPet()) // pets don't use the flag for this
        RemoveUnitFlag(UNIT_FLAG_PET_IN_COMBAT); // m_controlled is now empty, so we know none of our minions are in combat
}

bool Unit::isPossessedByPlayer() const
{
    return HasUnitState(UNIT_STATE_POSSESSED) && GetCharmerGUID().IsPlayer();
}

bool Unit::isPossessing(Unit* u) const
{
    return u->isPossessed() && GetCharmedGUID() == u->GetGUID();
}

bool Unit::isPossessing() const
{
    if (Unit* u = GetCharmed())
        return u->isPossessed();
    else
        return false;
}

Unit* Unit::GetNextRandomRaidMemberOrPet(float radius)
{
    Player* player = nullptr;
    if (GetTypeId() == TYPEID_PLAYER)
        player = ToPlayer();
    // Should we enable this also for charmed units?
    else if (GetTypeId() == TYPEID_UNIT && IsPet())
        player = GetOwner()->ToPlayer();

    if (!player)
        return nullptr;
    Group* group = player->GetGroup();
    // When there is no group check pet presence
    if (!group)
    {
        // We are pet now, return owner
        if (player != this)
            return IsWithinDistInMap(player, radius) ? player : nullptr;
        Unit* pet = GetGuardianPet();
        // No pet, no group, nothing to return
        if (!pet)
            return nullptr;
        // We are owner now, return pet
        return IsWithinDistInMap(pet, radius) ? pet : nullptr;
    }

    std::vector<Unit*> nearMembers;
    // reserve place for players and pets because resizing vector every unit push is unefficient (vector is reallocated then)
    nearMembers.reserve(group->GetMembersCount() * 2);

    for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
        if (Player* Target = itr->GetSource())
        {
            // IsHostileTo check duel and controlled by enemy
            if (Target != this && IsWithinDistInMap(Target, radius) && Target->IsAlive() && !IsHostileTo(Target))
                nearMembers.push_back(Target);

        // Push player's pet to vector
        if (Unit* pet = Target->GetGuardianPet())
            if (pet != this && IsWithinDistInMap(pet, radius) && pet->IsAlive() && !IsHostileTo(pet))
                nearMembers.push_back(pet);
        }

    if (nearMembers.empty())
        return nullptr;

    uint32 randTarget = urand(0, nearMembers.size()-1);
    return nearMembers[randTarget];
}

// only called in Player::SetSeer
// so move it to Player?
void Unit::AddPlayerToVision(Player* player)
{
    if (m_sharedVision.empty())
    {
        setActive(true);
        SetIsStoredInWorldObjectGridContainer(true);
    }
    m_sharedVision.push_back(player);
}

// only called in Player::SetSeer
void Unit::RemovePlayerFromVision(Player* player)
{
    m_sharedVision.remove(player);
    if (m_sharedVision.empty())
    {
        setActive(false);
        SetIsStoredInWorldObjectGridContainer(false);
    }
}

void Unit::RemoveBindSightAuras()
{
    RemoveAurasByType(SPELL_AURA_BIND_SIGHT);
}

void Unit::RemoveCharmAuras()
{
    RemoveAurasByType(SPELL_AURA_MOD_CHARM);
    RemoveAurasByType(SPELL_AURA_MOD_POSSESS_PET);
    RemoveAurasByType(SPELL_AURA_MOD_POSSESS);
    RemoveAurasByType(SPELL_AURA_AOE_CHARM);
}

void Unit::UnsummonAllTotems()
{
    for (uint8 i = 0; i < MAX_SUMMON_SLOT; ++i)
    {
        if (!m_SummonSlot[i])
            continue;

        if (Creature* OldTotem = GetMap()->GetCreature(m_SummonSlot[i]))
            if (OldTotem->IsSummon())
                OldTotem->ToTempSummon()->UnSummon();
    }
}

void Unit::SendHealSpellLog(HealInfo& healInfo, bool critical /*= false*/)
{
    WorldPackets::CombatLog::SpellHealLog spellHealLog;

    TC_LOG_DEBUG("spells", "HealSpellLog -- SpellId: {} Caster: {} Target: {} (Health: {} OverHeal: {} Absorbed: {} Crit: {})", healInfo.GetSpellInfo()->Id, healInfo.GetHealer()->GetGUID().ToString(), healInfo.GetTarget()->GetGUID().ToString(),
        healInfo.GetHeal(), healInfo.GetHeal() - healInfo.GetEffectiveHeal(), healInfo.GetAbsorb(), critical);

    spellHealLog.TargetGUID = healInfo.GetTarget()->GetGUID();
    spellHealLog.CasterGUID = healInfo.GetHealer()->GetGUID();
    spellHealLog.SpellID = healInfo.GetSpellInfo()->Id;
    spellHealLog.Health = healInfo.GetHeal();
    spellHealLog.OriginalHeal = healInfo.GetOriginalHeal();
    spellHealLog.OverHeal = int32(healInfo.GetHeal()) - healInfo.GetEffectiveHeal();
    spellHealLog.Absorbed = healInfo.GetAbsorb();
    spellHealLog.Crit = critical;
    spellHealLog.LogData.Initialize(healInfo.GetTarget());
    SendCombatLogMessage(&spellHealLog);
}

int32 Unit::HealBySpell(HealInfo& healInfo, bool critical /*= false*/)
{
    // calculate heal absorb and reduce healing
    Unit::CalcHealAbsorb(healInfo);
    Unit::DealHeal(healInfo);
    SendHealSpellLog(healInfo, critical);
    return healInfo.GetEffectiveHeal();
}

void Unit::SendEnergizeSpellLog(Unit* victim, uint32 spellID, int32 damage, int32 overEnergize, Powers powertype)
{
    WorldPackets::CombatLog::SpellEnergizeLog data;
    data.CasterGUID = GetGUID();
    data.TargetGUID = victim->GetGUID();
    data.SpellID = spellID;
    data.Type = powertype;
    data.Amount = damage;
    data.OverEnergize = overEnergize;
    data.LogData.Initialize(victim);
    SendCombatLogMessage(&data);
}

void Unit::EnergizeBySpell(Unit* victim, SpellInfo const* spellInfo, int32 damage, Powers powerType)
{
    if (Player* player = victim->ToPlayer())
        if (PowerTypeEntry const* powerTypeEntry = sDB2Manager.GetPowerTypeEntry(powerType))
            if (powerTypeEntry->GetFlags().HasFlag(PowerTypeFlags::UseRegenInterrupt))
                player->InterruptPowerRegen(powerType);

    int32 gain = victim->ModifyPower(powerType, damage, false);
    int32 overEnergize = damage - gain;
    victim->GetThreatManager().ForwardThreatForAssistingMe(this, float(damage) / 2, spellInfo, true);
    SendEnergizeSpellLog(victim, spellInfo->Id, gain, overEnergize, powerType);
}

int32 Unit::SpellDamageBonusDone(Unit* victim, SpellInfo const* spellProto, int32 pdamage, DamageEffectType damagetype, SpellEffectInfo const& spellEffectInfo, uint32 stack /*= 1*/, Spell* spell /*= nullptr*/, AuraEffect const* aurEff /*= nullptr*/) const
{
    if (!spellProto || !victim)
        return pdamage;

    int32 DoneTotal = 0;
    float DoneTotalMod = 1.0f;

    auto callDamageScript = [&](int32& dmg, int32& flatMod, float& pctMod)
    {
        if (spell)
            spell->CallScriptCalcDamageHandlers(victim, dmg, flatMod, pctMod);
        else if (aurEff)
            aurEff->GetBase()->CallScriptCalcDamageAndHealingHandlers(aurEff, aurEff->GetBase()->GetApplicationOfTarget(victim->GetGUID()), victim, dmg, flatMod, pctMod);
    };

    // Some spells don't benefit from done mods
    if (damagetype == DIRECT_DAMAGE || spellProto->HasAttribute(SPELL_ATTR3_IGNORE_CASTER_MODIFIERS))
    {
        callDamageScript(pdamage, DoneTotal, DoneTotalMod);
        return int32(std::max(float(pdamage + DoneTotal) * DoneTotalMod, 0.0f));
    }

    // For totems get damage bonus from owner
    if (GetTypeId() == TYPEID_UNIT && IsTotem())
        if (Unit* owner = GetOwner())
            return owner->SpellDamageBonusDone(victim, spellProto, pdamage, damagetype, spellEffectInfo, stack, spell, aurEff);

    DoneTotalMod = SpellDamagePctDone(victim, spellProto, damagetype, spellEffectInfo);

    // Done fixed damage bonus auras
    int32 DoneAdvertisedBenefit  = SpellBaseDamageBonusDone(spellProto->GetSchoolMask());
    // modify spell power by victim's SPELL_AURA_MOD_DAMAGE_TAKEN auras (eg Amplify/Dampen Magic)
    DoneAdvertisedBenefit += victim->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_DAMAGE_TAKEN, spellProto->GetSchoolMask());

    // Pets just add their bonus damage to their spell damage
    // note that their spell damage is just gain of their own auras
    if (HasUnitTypeMask(UNIT_MASK_GUARDIAN))
        DoneAdvertisedBenefit += static_cast<Guardian const*>(this)->GetBonusDamage();

    // Check for table values
    if (spellEffectInfo.BonusCoefficientFromAP > 0.0f)
    {
        float ApCoeffMod = spellEffectInfo.BonusCoefficientFromAP;
        if (Player* modOwner = GetSpellModOwner())
        {
            ApCoeffMod *= 100.0f;
            modOwner->ApplySpellMod(spellProto, SpellModOp::BonusCoefficient, ApCoeffMod);
            ApCoeffMod /= 100.0f;
        }

        WeaponAttackType const attType = [&]()
        {
            if ((spellProto->IsRangedWeaponSpell() && spellProto->DmgClass != SPELL_DAMAGE_CLASS_MELEE))
                return RANGED_ATTACK;

            if (spellProto->HasAttribute(SPELL_ATTR3_REQUIRES_OFF_HAND_WEAPON) && !spellProto->HasAttribute(SPELL_ATTR3_REQUIRES_MAIN_HAND_WEAPON))
                return OFF_ATTACK;

            return BASE_ATTACK;
        }();
        float APbonus = float(victim->GetTotalAuraModifier(attType != RANGED_ATTACK ? SPELL_AURA_MELEE_ATTACK_POWER_ATTACKER_BONUS : SPELL_AURA_RANGED_ATTACK_POWER_ATTACKER_BONUS));
        APbonus += GetTotalAttackPowerValue(attType);
        DoneTotal += int32(stack * ApCoeffMod * APbonus);
    }

    // Default calculation
    if (DoneAdvertisedBenefit)
    {
        float coeff = spellEffectInfo.BonusCoefficient;
        if (Player* modOwner = GetSpellModOwner())
        {
            coeff *= 100.0f;
            modOwner->ApplySpellMod(spellProto, SpellModOp::BonusCoefficient, coeff);
            coeff /= 100.0f;
        }

        DoneTotal += int32(DoneAdvertisedBenefit * coeff * stack);
    }

    callDamageScript(pdamage, DoneTotal, DoneTotalMod);

    float tmpDamage = float(pdamage + DoneTotal) * DoneTotalMod;

    // apply spellmod to Done damage (flat and pct)
    if (Player* modOwner = GetSpellModOwner())
        modOwner->ApplySpellMod(spellProto, damagetype == DOT ? SpellModOp::PeriodicHealingAndDamage : SpellModOp::HealingAndDamage, tmpDamage);

    return int32(std::max(tmpDamage, 0.0f));
}

float Unit::SpellDamagePctDone(Unit* victim, SpellInfo const* spellProto, DamageEffectType damagetype, SpellEffectInfo const& spellEffectInfo) const
{
    if (!spellProto || !victim || damagetype == DIRECT_DAMAGE)
        return 1.0f;

    // Some spells don't benefit from done mods
    if (spellProto->HasAttribute(SPELL_ATTR3_IGNORE_CASTER_MODIFIERS))
        return 1.0f;

    // Some spells don't benefit from pct done mods
    if (spellProto->HasAttribute(SPELL_ATTR6_IGNORE_CASTER_DAMAGE_MODIFIERS))
        return 1.0f;

    // For totems get damage bonus from owner
    if (GetTypeId() == TYPEID_UNIT && IsTotem())
        if (Unit* owner = GetOwner())
            return owner->SpellDamagePctDone(victim, spellProto, damagetype, spellEffectInfo);

    // Done total percent damage auras
    float DoneTotalMod = 1.0f;

    // Pet damage?
    if (GetTypeId() == TYPEID_UNIT && !IsPet())
        DoneTotalMod *= ToCreature()->GetSpellDamageMod(ToCreature()->GetCreatureTemplate()->Classification);

    // Versatility
    if (Player* modOwner = GetSpellModOwner())
        AddPct(DoneTotalMod, modOwner->GetRatingBonusValue(CR_VERSATILITY_DAMAGE_DONE) + modOwner->GetTotalAuraModifier(SPELL_AURA_MOD_VERSATILITY));

    float maxModDamagePercentSchool = 0.0f;
    if (Player const* thisPlayer = ToPlayer())
    {
        for (uint32 i = 0; i < MAX_SPELL_SCHOOL; ++i)
            if (spellProto->GetSchoolMask() & (1 << i))
                maxModDamagePercentSchool = std::max(maxModDamagePercentSchool, thisPlayer->m_activePlayerData->ModDamageDonePercent[i]);
    }
    else
        maxModDamagePercentSchool = GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, spellProto->GetSchoolMask());

    DoneTotalMod *= maxModDamagePercentSchool;

    uint32 creatureTypeMask = victim->GetCreatureTypeMask();

    DoneTotalMod *= GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_DAMAGE_DONE_VERSUS, creatureTypeMask);

    // bonus against aurastate
    DoneTotalMod *= GetTotalAuraMultiplier(SPELL_AURA_MOD_DAMAGE_DONE_VERSUS_AURASTATE, [victim](AuraEffect const* aurEff) -> bool
    {
        if (victim->HasAuraState(static_cast<AuraStateType>(aurEff->GetMiscValue())))
            return true;
        return false;
    });

    // bonus against target aura mechanic
    DoneTotalMod *= GetTotalAuraMultiplier(SPELL_AURA_MOD_DAMAGE_PERCENT_DONE_BY_TARGET_AURA_MECHANIC, [victim](AuraEffect const* aurEff) -> bool
    {
        if (victim->HasAuraWithMechanic(UI64LIT(1) << aurEff->GetMiscValue()))
            return true;
        return false;
    });

    // Add SPELL_AURA_MOD_DAMAGE_DONE_FOR_MECHANIC percent bonus
    if (spellEffectInfo.Mechanic)
        AddPct(DoneTotalMod, GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_DAMAGE_DONE_FOR_MECHANIC, spellEffectInfo.Mechanic));
    else if (spellProto->Mechanic)
        AddPct(DoneTotalMod, GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_DAMAGE_DONE_FOR_MECHANIC, spellProto->Mechanic));

    // Custom scripted damage
    switch (spellProto->SpellFamilyName)
    {
        case SPELLFAMILY_MAGE:
            // Ice Lance (no unique family flag)
            if (spellProto->Id == 228598)
                if (victim->HasAuraState(AURA_STATE_FROZEN, spellProto, this))
                    DoneTotalMod *= 3.0f;
            break;
        case SPELLFAMILY_WARLOCK:
            // Shadow Bite (30% increase from each dot)
            if (spellProto->SpellFamilyFlags[1] & 0x00400000 && IsPet())
                if (uint8 count = victim->GetDoTsByCaster(GetOwnerGUID()))
                    AddPct(DoneTotalMod, 30 * count);

            // Drain Soul - increased damage for targets under 20% HP
            if (spellProto->Id == 198590)
                if (HasAuraState(AURA_STATE_WOUNDED_20_PERCENT))
                    DoneTotalMod *= 2;
            break;
    }

    return DoneTotalMod;
}

int32 Unit::SpellDamageBonusTaken(Unit* caster, SpellInfo const* spellProto, int32 pdamage, DamageEffectType damagetype) const
{
    if (!spellProto || damagetype == DIRECT_DAMAGE)
        return pdamage;

    float TakenTotalMod = 1.0f;

    // Mod damage from spell mechanic
    if (uint64 mechanicMask = spellProto->GetAllEffectsMechanicMask())
    {
        TakenTotalMod *= GetTotalAuraMultiplier(SPELL_AURA_MOD_MECHANIC_DAMAGE_TAKEN_PERCENT, [mechanicMask](AuraEffect const* aurEff) -> bool
        {
            if (mechanicMask & uint64(UI64LIT(1) << aurEff->GetMiscValue()))
                return true;
            return false;
        });
    }

    if (AuraEffect const* cheatDeath = GetAuraEffect(45182, EFFECT_0))
        if (cheatDeath->GetMiscValue() & SPELL_SCHOOL_MASK_NORMAL)
            AddPct(TakenTotalMod, cheatDeath->GetAmount());

    // Spells with SPELL_ATTR4_IGNORE_DAMAGE_TAKEN_MODIFIERS should only benefit from mechanic damage mod auras.
    if (!spellProto->HasAttribute(SPELL_ATTR4_IGNORE_DAMAGE_TAKEN_MODIFIERS))
    {
        // Versatility
        if (Player* modOwner = GetSpellModOwner())
        {
            // only 50% of SPELL_AURA_MOD_VERSATILITY for damage reduction
            float versaBonus = modOwner->GetTotalAuraModifier(SPELL_AURA_MOD_VERSATILITY) / 2.0f;
            AddPct(TakenTotalMod, -(modOwner->GetRatingBonusValue(CR_VERSATILITY_DAMAGE_TAKEN) + versaBonus));
        }

        // from positive and negative SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN
        // multiplicative bonus, for example Dispersion + Shadowform (0.10*0.85=0.085)
        TakenTotalMod *= GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, spellProto->GetSchoolMask());

        // From caster spells
        if (caster)
        {
            TakenTotalMod *= GetTotalAuraMultiplier(SPELL_AURA_MOD_SCHOOL_MASK_DAMAGE_FROM_CASTER, [caster, spellProto](AuraEffect const* aurEff) -> bool
            {
                return aurEff->GetCasterGUID() == caster->GetGUID() && (aurEff->GetMiscValue() & spellProto->GetSchoolMask());
            });

            TakenTotalMod *= GetTotalAuraMultiplier(SPELL_AURA_MOD_SPELL_DAMAGE_FROM_CASTER, [caster, spellProto](AuraEffect const* aurEff) -> bool
            {
                return aurEff->GetCasterGUID() == caster->GetGUID() && aurEff->IsAffectingSpell(spellProto);
            });

            TakenTotalMod *= GetTotalAuraMultiplier(SPELL_AURA_MOD_DAMAGE_TAKEN_FROM_CASTER_BY_LABEL, [caster, spellProto](AuraEffect const* aurEff) -> bool
            {
                return aurEff->GetCasterGUID() == caster->GetGUID() && spellProto->HasLabel(aurEff->GetMiscValue());
            });
        }

        if (damagetype == DOT)
        {
            TakenTotalMod *= GetTotalAuraMultiplier(SPELL_AURA_MOD_PERIODIC_DAMAGE_TAKEN, [spellProto](AuraEffect const* aurEff) -> bool
            {
                return aurEff->GetMiscValue() & spellProto->GetSchoolMask();
            });
        }
    }

    // Sanctified Wrath (bypass damage reduction)
    if (caster && TakenTotalMod < 1.0f)
    {
        float damageReduction = 1.0f - TakenTotalMod;
        Unit::AuraEffectList const& casterIgnoreResist = caster->GetAuraEffectsByType(SPELL_AURA_MOD_IGNORE_TARGET_RESIST);
        for (AuraEffect const* aurEff : casterIgnoreResist)
        {
            if (!(aurEff->GetMiscValue() & spellProto->GetSchoolMask()))
                continue;

            AddPct(damageReduction, -aurEff->GetAmount());
        }

        TakenTotalMod = 1.0f - damageReduction;
    }

    float tmpDamage = pdamage * TakenTotalMod;
    return int32(std::max(tmpDamage, 0.0f));
}

int32 Unit::SpellBaseDamageBonusDone(SpellSchoolMask schoolMask) const
{
    if (Player const* thisPlayer = ToPlayer())
    {
        float overrideSP = thisPlayer->m_activePlayerData->OverrideSpellPowerByAPPercent;
        if (overrideSP > 0.0f)
            return int32(CalculatePct(GetTotalAttackPowerValue(BASE_ATTACK), overrideSP) + 0.5f);
    }

    int32 DoneAdvertisedBenefit = GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_DAMAGE_DONE, schoolMask);

    if (GetTypeId() == TYPEID_PLAYER)
    {
        // Base value
        DoneAdvertisedBenefit += ToPlayer()->GetBaseSpellPowerBonus();

        // Check if we are ever using mana - PaperDollFrame.lua
        if (GetPowerIndex(POWER_MANA) != MAX_POWERS)
            DoneAdvertisedBenefit += std::max(0, int32(GetStat(STAT_INTELLECT)));  // spellpower from intellect

        // Damage bonus from stats
        AuraEffectList const& mDamageDoneOfStatPercent = GetAuraEffectsByType(SPELL_AURA_MOD_SPELL_DAMAGE_OF_STAT_PERCENT);
        for (AuraEffect const* aurEff : mDamageDoneOfStatPercent)
        {
            if ((aurEff->GetMiscValue() & schoolMask) != 0)
            {
                // stat used stored in miscValueB for this aura
                Stats const usedStat = static_cast<Stats>(aurEff->GetMiscValueB());
                DoneAdvertisedBenefit += static_cast<int32>(CalculatePct(GetStat(usedStat), aurEff->GetAmount()));
            }
        }

    }

    return DoneAdvertisedBenefit;
}

float Unit::SpellCritChanceDone(Spell* spell, AuraEffect const* aurEff, SpellSchoolMask schoolMask, WeaponAttackType attackType /*= BASE_ATTACK*/) const
{
    SpellInfo const* spellInfo = spell ? spell->GetSpellInfo() : aurEff->GetSpellInfo();
    //! Mobs can't crit with spells. (Except player controlled)
    if (GetTypeId() == TYPEID_UNIT && !GetSpellModOwner())
        return 0.0f;

    // not critting spell
    if (spell && !spellInfo->HasAttribute(SPELL_ATTR0_CU_CAN_CRIT))
        return 0.0f;

    float crit_chance = 0.0f;
    switch (spellInfo->DmgClass)
    {
        case SPELL_DAMAGE_CLASS_NONE:
        case SPELL_DAMAGE_CLASS_MAGIC:
        {
            auto getPhysicalCritChance = [&]
            {
                return GetUnitCriticalChanceDone(attackType);
            };

            auto getMagicCritChance = [&]
            {
                if (Player const* thisPlayer = ToPlayer())
                    return *thisPlayer->m_activePlayerData->SpellCritPercentage;

                return m_baseSpellCritChance;
            };

            if (schoolMask & SPELL_SCHOOL_MASK_NORMAL)
                crit_chance = std::max(crit_chance, getPhysicalCritChance());

            if (schoolMask & ~SPELL_SCHOOL_MASK_NORMAL)
                crit_chance = std::max(crit_chance, getMagicCritChance());
            break;
        }
        case SPELL_DAMAGE_CLASS_MELEE:
        case SPELL_DAMAGE_CLASS_RANGED:
        {
            crit_chance += GetUnitCriticalChanceDone(attackType);
            break;
        }
        default:
            return 0.0f;
    }
    // percent done
    // only players use intelligence for critical chance computations
    if (Player* modOwner = GetSpellModOwner())
        modOwner->ApplySpellMod(spellInfo, SpellModOp::CritChance, crit_chance);

    return std::max(crit_chance, 0.0f);
}

float Unit::SpellCritChanceTaken(Unit const* caster, Spell* spell, AuraEffect const* aurEff, SpellSchoolMask /*schoolMask*/, float doneChance, WeaponAttackType attackType /*= BASE_ATTACK*/) const
{
    SpellInfo const* spellInfo = spell ? spell->GetSpellInfo() : aurEff->GetSpellInfo();
    // not critting spell
    if (spell && !spellInfo->HasAttribute(SPELL_ATTR0_CU_CAN_CRIT))
        return 0.0f;

    float crit_chance = doneChance;
    switch (spellInfo->DmgClass)
    {
        case SPELL_DAMAGE_CLASS_MAGIC:
        {
            // taken
            if (!spellInfo->IsPositive())
            {
                // Modify critical chance by victim SPELL_AURA_MOD_ATTACKER_SPELL_AND_WEAPON_CRIT_CHANCE
                crit_chance += GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_SPELL_AND_WEAPON_CRIT_CHANCE);
            }

            if (caster)
            {
                // scripted (increase crit chance ... against ... target by x%
                AuraEffectList const& mOverrideClassScript = caster->GetAuraEffectsByType(SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
                for (AuraEffect const* aurEff : mOverrideClassScript)
                {
                    if (!aurEff->IsAffectingSpell(spellInfo))
                        continue;

                    switch (aurEff->GetMiscValue())
                    {
                        case 911: // Shatter
                            if (HasAuraState(AURA_STATE_FROZEN, spellInfo, caster))
                            {
                                crit_chance *= 1.5f;
                                if (AuraEffect const* eff = aurEff->GetBase()->GetEffect(EFFECT_1))
                                    crit_chance += eff->GetAmount();
                            }
                            break;
                        default:
                            break;
                    }
                }
                // Custom crit by class
                switch (spellInfo->SpellFamilyName)
                {
                    case SPELLFAMILY_ROGUE:
                        // Shiv-applied poisons can't crit
                        if (caster->FindCurrentSpellBySpellId(5938))
                            crit_chance = 0.0f;
                        break;
                }

                // Spell crit suppression
                if (GetTypeId() == TYPEID_UNIT)
                {
                    int32 const levelDiff = static_cast<int32>(GetLevelForTarget(caster)) - caster->GetLevel();
                    crit_chance -= levelDiff * 1.0f;
                }
            }
            break;
        }
        case SPELL_DAMAGE_CLASS_MELEE:

        case SPELL_DAMAGE_CLASS_RANGED:
            if (caster)
                crit_chance = GetUnitCriticalChanceTaken(caster, attackType, crit_chance);
            break;
        case SPELL_DAMAGE_CLASS_NONE:
        default:
            return 0.f;
    }

    // for this types the bonus was already added in GetUnitCriticalChance, do not add twice
    if (caster && spellInfo->DmgClass != SPELL_DAMAGE_CLASS_MELEE && spellInfo->DmgClass != SPELL_DAMAGE_CLASS_RANGED)
    {
        crit_chance += GetTotalAuraModifier(SPELL_AURA_MOD_CRIT_CHANCE_FOR_CASTER_WITH_ABILITIES, [caster, spellInfo](AuraEffect const* aurEff) -> bool
        {
            return aurEff->GetCasterGUID() == caster->GetGUID() && aurEff->IsAffectingSpell(spellInfo);
        });
        crit_chance += GetTotalAuraModifier(SPELL_AURA_MOD_CRIT_CHANCE_FOR_CASTER, [caster](AuraEffect const* aurEff) -> bool
        {
            return aurEff->GetCasterGUID() == caster->GetGUID();
        });
        crit_chance += caster->GetTotalAuraModifier(SPELL_AURA_MOD_CRIT_CHANCE_VERSUS_TARGET_HEALTH, [this](AuraEffect const* aurEff)
        {
            return !HealthBelowPct(aurEff->GetMiscValueB());
        });
        if (TempSummon const* tempSummon = caster->ToTempSummon())
        {
            crit_chance += GetTotalAuraModifier(SPELL_AURA_MOD_CRIT_CHANCE_FOR_CASTER_PET, [tempSummon](AuraEffect const* aurEff) -> bool
            {
                return aurEff->GetCasterGUID() == tempSummon->GetSummonerGUID();
            });
        }
    }

    // call script handlers
    if (spell)
        spell->CallScriptCalcCritChanceHandlers(this, crit_chance);
    else
        aurEff->GetBase()->CallScriptEffectCalcCritChanceHandlers(aurEff, aurEff->GetBase()->GetApplicationOfTarget(GetGUID()), this, crit_chance);

    return std::max(crit_chance, 0.0f);
}

/*static*/ uint32 Unit::SpellCriticalDamageBonus(Unit const* caster, SpellInfo const* spellProto, uint32 damage, Unit* victim)
{
    // Calculate critical bonus
    int32 crit_bonus = damage * 2;
    float crit_mod = 0.0f;

    if (caster)
    {
        crit_mod += (caster->GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_CRIT_DAMAGE_BONUS, spellProto->GetSchoolMask()) - 1.0f) * 100;

        if (crit_bonus != 0)
            AddPct(crit_bonus, crit_mod);

        AddPct(crit_bonus, victim->GetTotalAuraModifier(SPELL_AURA_MOD_CRITICAL_DAMAGE_TAKEN_FROM_CASTER, [&](AuraEffect const* aurEff)
        {
            return aurEff->GetCasterGUID() == caster->GetGUID();
        }));

        crit_bonus -= damage;

        // adds additional damage to critBonus (from talents)
        if (Player* modOwner = caster->GetSpellModOwner())
            modOwner->ApplySpellMod(spellProto, SpellModOp::CritDamageAndHealing, crit_bonus);

        crit_bonus += damage;
    }

    return crit_bonus;
}

/*static*/ uint32 Unit::SpellCriticalHealingBonus(Unit const* caster, SpellInfo const* spellProto, uint32 damage, Unit* /*victim*/)
{
    // Calculate critical bonus
    int32 crit_bonus = damage;

    // adds additional damage to critBonus (from talents)
    if (caster)
        if (Player* modOwner = caster->GetSpellModOwner())
            modOwner->ApplySpellMod(spellProto, SpellModOp::CritDamageAndHealing, crit_bonus);

    damage += crit_bonus;

    if (caster)
        damage = int32(float(damage) * caster->GetTotalAuraMultiplier(SPELL_AURA_MOD_CRITICAL_HEALING_AMOUNT));

    return damage;
}

int32 Unit::SpellHealingBonusDone(Unit* victim, SpellInfo const* spellProto, int32 healamount, DamageEffectType damagetype, SpellEffectInfo const& spellEffectInfo, uint32 stack /*= 1*/, Spell* spell /*= nullptr*/, AuraEffect const* aurEff /*= nullptr*/) const
{
    // For totems get healing bonus from owner (statue isn't totem in fact)
    if (GetTypeId() == TYPEID_UNIT && IsTotem())
        if (Unit* owner = GetOwner())
            return owner->SpellHealingBonusDone(victim, spellProto, healamount, damagetype, spellEffectInfo, stack, spell, aurEff);

    // No bonus healing for potion spells
    if (spellProto->SpellFamilyName == SPELLFAMILY_POTION)
        return healamount;

    int32 DoneTotal = 0;
    float DoneTotalMod = SpellHealingPctDone(victim, spellProto);

    // done scripted mod (take it from owner)
    Unit const* owner = GetOwner() ? GetOwner() : this;
    AuraEffectList const& mOverrideClassScript= owner->GetAuraEffectsByType(SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
    for (AuraEffect const* aurEff : mOverrideClassScript)
    {
        if (!aurEff->IsAffectingSpell(spellProto))
            continue;

        switch (aurEff->GetMiscValue())
        {
            case 3736: // Hateful Totem of the Third Wind / Increased Lesser Healing Wave / LK Arena (4/5/6) Totem of the Third Wind / Savage Totem of the Third Wind
                DoneTotal += aurEff->GetAmount();
                break;
            default:
                break;
        }
    }

    // Done fixed damage bonus auras
    int32 DoneAdvertisedBenefit = SpellBaseHealingBonusDone(spellProto->GetSchoolMask());
    // modify spell power by victim's SPELL_AURA_MOD_HEALING auras (eg Amplify/Dampen Magic)
    DoneAdvertisedBenefit += victim->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_HEALING, spellProto->GetSchoolMask());

    // Pets just add their bonus damage to their spell damage
    // note that their spell damage is just gain of their own auras
    if (HasUnitTypeMask(UNIT_MASK_GUARDIAN))
        DoneAdvertisedBenefit += static_cast<Guardian const*>(this)->GetBonusDamage();

    // Check for table values
    if (spellEffectInfo.BonusCoefficientFromAP > 0.0f)
    {
        WeaponAttackType const attType = (spellProto->IsRangedWeaponSpell() && spellProto->DmgClass != SPELL_DAMAGE_CLASS_MELEE) ? RANGED_ATTACK : BASE_ATTACK;
        float APbonus = float(victim->GetTotalAuraModifier(attType == BASE_ATTACK ? SPELL_AURA_MELEE_ATTACK_POWER_ATTACKER_BONUS : SPELL_AURA_RANGED_ATTACK_POWER_ATTACKER_BONUS));
        APbonus += GetTotalAttackPowerValue(attType);

        DoneTotal += int32(spellEffectInfo.BonusCoefficientFromAP * stack * APbonus);
    }

    // Default calculation
    if (DoneAdvertisedBenefit)
    {
        float coeff = spellEffectInfo.BonusCoefficient;
        if (Player* modOwner = GetSpellModOwner())
        {
            coeff *= 100.0f;
            modOwner->ApplySpellMod(spellProto, SpellModOp::BonusCoefficient, coeff);
            coeff /= 100.0f;
        }

        DoneTotal += int32(DoneAdvertisedBenefit * coeff * stack);
    }

    for (SpellEffectInfo const& otherSpellEffect : spellProto->GetEffects())
    {
        switch (otherSpellEffect.ApplyAuraName)
        {
            // Bonus healing does not apply to these spells
            case SPELL_AURA_PERIODIC_LEECH:
            case SPELL_AURA_PERIODIC_HEALTH_FUNNEL:
                DoneTotal = 0;
                break;
            default:
                break;
        }
        if (otherSpellEffect.IsEffect(SPELL_EFFECT_HEALTH_LEECH))
            DoneTotal = 0;
    }

    if (spell)
        spell->CallScriptCalcHealingHandlers(victim, healamount, DoneTotal, DoneTotalMod);
    else if (aurEff)
        aurEff->GetBase()->CallScriptCalcDamageAndHealingHandlers(aurEff, aurEff->GetBase()->GetApplicationOfTarget(victim->GetGUID()), victim, healamount, DoneTotal, DoneTotalMod);

    float heal = float(healamount + DoneTotal) * DoneTotalMod;

    // apply spellmod to Done amount
    if (Player* modOwner = GetSpellModOwner())
        modOwner->ApplySpellMod(spellProto, damagetype == DOT ? SpellModOp::PeriodicHealingAndDamage : SpellModOp::HealingAndDamage, heal);

    return int32(std::max(heal, 0.0f));
}

float Unit::SpellHealingPctDone(Unit* victim, SpellInfo const* spellProto) const
{
    // For totems get healing bonus from owner
    if (GetTypeId() == TYPEID_UNIT && IsTotem())
        if (Unit* owner = GetOwner())
            return owner->SpellHealingPctDone(victim, spellProto);

    // Some spells don't benefit from done mods
    if (spellProto->HasAttribute(SPELL_ATTR3_IGNORE_CASTER_MODIFIERS))
        return 1.0f;

    // Some spells don't benefit from done mods
    if (spellProto->HasAttribute(SPELL_ATTR6_IGNORE_HEALING_MODIFIERS))
        return 1.0f;

    // No bonus healing for potion spells
    if (spellProto->SpellFamilyName == SPELLFAMILY_POTION)
        return 1.0f;

    float DoneTotalMod = 1.0f;

    // Healing done percent
    if (Player const* thisPlayer = ToPlayer())
    {
        float maxModDamagePercentSchool = 0.0f;
        for (uint32 i = 0; i < MAX_SPELL_SCHOOL; ++i)
            if (spellProto->GetSchoolMask() & (1 << i))
                maxModDamagePercentSchool = std::max(maxModDamagePercentSchool, thisPlayer->m_activePlayerData->ModHealingDonePercent[i]);

        DoneTotalMod *= maxModDamagePercentSchool;
    }
    else // SPELL_AURA_MOD_HEALING_DONE_PERCENT is included in m_activePlayerData->ModHealingDonePercent for players
        DoneTotalMod *= GetTotalAuraMultiplier(SPELL_AURA_MOD_HEALING_DONE_PERCENT);

    // bonus against aurastate
    DoneTotalMod *= GetTotalAuraMultiplier(SPELL_AURA_MOD_DAMAGE_DONE_VERSUS_AURASTATE, [victim](AuraEffect const* aurEff) -> bool
    {
        if (victim->HasAuraState(static_cast<AuraStateType>(aurEff->GetMiscValue())))
            return true;
        return false;
    });

    // bonus from missing health of target
    float healthPctDiff = 100.0f - victim->GetHealthPct();
    for (AuraEffect const* healingDonePctVsTargetHealth : GetAuraEffectsByType(SPELL_AURA_MOD_HEALING_DONE_PCT_VERSUS_TARGET_HEALTH))
        if (healingDonePctVsTargetHealth->IsAffectingSpell(spellProto))
            AddPct(DoneTotalMod, CalculatePct(float(healingDonePctVsTargetHealth->GetAmount()), healthPctDiff));

    return DoneTotalMod;
}

int32 Unit::SpellHealingBonusTaken(Unit* caster, SpellInfo const* spellProto, int32 healamount, DamageEffectType damagetype) const
{
    float TakenTotalMod = 1.0f;

    // Healing taken percent
    float minval = float(GetMaxNegativeAuraModifier(SPELL_AURA_MOD_HEALING_PCT));
    if (minval)
        AddPct(TakenTotalMod, minval);

    float maxval = float(GetMaxPositiveAuraModifier(SPELL_AURA_MOD_HEALING_PCT));
    if (maxval)
        AddPct(TakenTotalMod, maxval);

    // Nourish cast
    if (spellProto->SpellFamilyName == SPELLFAMILY_DRUID && spellProto->SpellFamilyFlags[1] & 0x2000000)
    {
        // Rejuvenation, Regrowth, Lifebloom, or Wild Growth
        if (GetAuraEffect(SPELL_AURA_PERIODIC_HEAL, SPELLFAMILY_DRUID, flag128(0x50, 0x4000010, 0)))
            // increase healing by 20%
            TakenTotalMod *= 1.2f;
    }

    if (damagetype == DOT)
    {
        // Healing over time taken percent
        float minval_hot = float(GetMaxNegativeAuraModifier(SPELL_AURA_MOD_HOT_PCT));
        if (minval_hot)
            AddPct(TakenTotalMod, minval_hot);

        float maxval_hot = float(GetMaxPositiveAuraModifier(SPELL_AURA_MOD_HOT_PCT));
        if (maxval_hot)
            AddPct(TakenTotalMod, maxval_hot);
    }

    if (caster)
    {
        TakenTotalMod *= GetTotalAuraMultiplier(SPELL_AURA_MOD_HEALING_RECEIVED, [caster, spellProto](AuraEffect const* aurEff) -> bool
        {
            if (caster->GetGUID() == aurEff->GetCasterGUID() && aurEff->IsAffectingSpell(spellProto))
                return true;
            return false;
        });

        TakenTotalMod *= GetTotalAuraMultiplier(SPELL_AURA_MOD_HEALING_TAKEN_FROM_CASTER, [caster](AuraEffect const* aurEff) -> bool
        {
            return aurEff->GetCasterGUID() == caster->GetGUID();
        });
    }

    float heal = healamount * TakenTotalMod;
    return int32(std::max(heal, 0.0f));
}

int32 Unit::SpellBaseHealingBonusDone(SpellSchoolMask schoolMask) const
{
    if (Player const* thisPlayer = ToPlayer())
    {
        float overrideSP = thisPlayer->m_activePlayerData->OverrideSpellPowerByAPPercent;
        if (overrideSP > 0.0f)
            return int32(CalculatePct(GetTotalAttackPowerValue(BASE_ATTACK), overrideSP) + 0.5f);
    }

    int32 advertisedBenefit = GetTotalAuraModifier(SPELL_AURA_MOD_HEALING_DONE, [schoolMask](AuraEffect const* aurEff) -> bool
    {
        if (!aurEff->GetMiscValue() || (aurEff->GetMiscValue() & schoolMask) != 0)
            return true;
        return false;
    });

    // Healing bonus of spirit, intellect and strength
    if (GetTypeId() == TYPEID_PLAYER)
    {
        // Base value
        advertisedBenefit += ToPlayer()->GetBaseSpellPowerBonus();

        // Check if we are ever using mana - PaperDollFrame.lua
        if (GetPowerIndex(POWER_MANA) != MAX_POWERS)
            advertisedBenefit += std::max(0, int32(GetStat(STAT_INTELLECT)));  // spellpower from intellect

        // Healing bonus from stats
        AuraEffectList const& mHealingDoneOfStatPercent = GetAuraEffectsByType(SPELL_AURA_MOD_SPELL_HEALING_OF_STAT_PERCENT);
        for (AuraEffectList::const_iterator i = mHealingDoneOfStatPercent.begin(); i != mHealingDoneOfStatPercent.end(); ++i)
        {
            // stat used dependent from misc value (stat index)
            Stats usedStat = Stats((*i)->GetSpellEffectInfo().MiscValue);
            advertisedBenefit += int32(CalculatePct(GetStat(usedStat), (*i)->GetAmount()));
        }
    }
    return advertisedBenefit;
}

bool Unit::IsImmunedToDamage(SpellSchoolMask schoolMask) const
{
    if (schoolMask == SPELL_SCHOOL_MASK_NONE)
        return false;

    // If m_immuneToSchool type contain this school type, IMMUNE damage.
    uint32 schoolImmunityMask = GetSchoolImmunityMask();
    if ((schoolImmunityMask & schoolMask) == schoolMask) // We need to be immune to all types
        return true;

    // If m_immuneToDamage type contain magic, IMMUNE damage.
    uint32 damageImmunityMask = GetDamageImmunityMask();
    if ((damageImmunityMask & schoolMask) == schoolMask) // We need to be immune to all types
        return true;

    return false;
}

bool Unit::IsImmunedToDamage(SpellInfo const* spellInfo, SpellEffectInfo const* spellEffectInfo /*= nullptr*/) const
{
    if (!spellInfo)
        return false;

    // for example 40175
    if (spellInfo->HasAttribute(SPELL_ATTR0_NO_IMMUNITIES) && spellInfo->HasAttribute(SPELL_ATTR3_ALWAYS_HIT))
        return false;

    if (spellInfo->HasAttribute(SPELL_ATTR1_IMMUNITY_TO_HOSTILE_AND_FRIENDLY_EFFECTS) || spellInfo->HasAttribute(SPELL_ATTR2_NO_SCHOOL_IMMUNITIES))
        return false;

    if (spellEffectInfo && spellEffectInfo->EffectAttributes.HasFlag(SpellEffectAttributes::NoImmunity))
        return false;

    if (uint32 schoolMask = spellInfo->GetSchoolMask())
    {
        // If m_immuneToSchool type contain this school type, IMMUNE damage.
        uint32 schoolImmunityMask = 0;
        SpellImmuneContainer const& schoolList = m_spellImmune[IMMUNITY_SCHOOL];
        for (auto itr = schoolList.begin(); itr != schoolList.end(); ++itr)
            if ((itr->first & schoolMask) && !spellInfo->CanPierceImmuneAura(sSpellMgr->GetSpellInfo(itr->second, GetMap()->GetDifficultyID())))
                schoolImmunityMask |= itr->first;

        // // We need to be immune to all types
        if ((schoolImmunityMask & schoolMask) == schoolMask)
            return true;

        // If m_immuneToDamage type contain magic, IMMUNE damage.
        uint32 damageImmunityMask = GetDamageImmunityMask();
        if ((damageImmunityMask & schoolMask) == schoolMask) // We need to be immune to all types
            return true;
    }

    return false;
}

bool Unit::IsImmunedToSpell(SpellInfo const* spellInfo, WorldObject const* caster, bool requireImmunityPurgesEffectAttribute /*= false*/) const
{
    if (!spellInfo)
        return false;

    auto hasImmunity = [requireImmunityPurgesEffectAttribute](SpellImmuneContainer const& container, uint32 key)
    {
        Trinity::IteratorPair<SpellImmuneContainer::const_iterator> range = Trinity::Containers::MapEqualRange(container, key);
        if (!requireImmunityPurgesEffectAttribute)
            return range.begin() != range.end();

        return std::any_of(range.begin(), range.end(), [](SpellImmuneContainer::value_type const& entry)
        {
            if (SpellInfo const* immunitySourceSpell = sSpellMgr->GetSpellInfo(entry.second, DIFFICULTY_NONE))
                if (immunitySourceSpell->HasAttribute(SPELL_ATTR1_IMMUNITY_PURGES_EFFECT))
                    return true;

            return false;
        });
    };

    // Single spell immunity.
    SpellImmuneContainer const& idList = m_spellImmune[IMMUNITY_ID];
    if (hasImmunity(idList, spellInfo->Id))
        return true;

    if (spellInfo->HasAttribute(SPELL_ATTR0_NO_IMMUNITIES))
        return false;

    if (uint32 dispel = spellInfo->Dispel)
    {
        SpellImmuneContainer const& dispelList = m_spellImmune[IMMUNITY_DISPEL];
        if (hasImmunity(dispelList, dispel))
            return true;
    }

    // Spells that don't have effectMechanics.
    if (uint32 mechanic = spellInfo->Mechanic)
    {
        SpellImmuneContainer const& mechanicList = m_spellImmune[IMMUNITY_MECHANIC];
        if (hasImmunity(mechanicList, mechanic))
            return true;
    }

    bool immuneToAllEffects = true;
    for (SpellEffectInfo const& spellEffectInfo : spellInfo->GetEffects())
    {
        // State/effect immunities applied by aura expect full spell immunity
        // Ignore effects with mechanic, they are supposed to be checked separately
        if (!spellEffectInfo.IsEffect())
            continue;
        if (!IsImmunedToSpellEffect(spellInfo, spellEffectInfo, caster, requireImmunityPurgesEffectAttribute))
        {
            immuneToAllEffects = false;
            break;
        }
        if (spellInfo->HasAttribute(SPELL_ATTR4_NO_PARTIAL_IMMUNITY))
            return true;
    }

    if (immuneToAllEffects) //Return immune only if the target is immune to all spell effects.
        return true;

    if (uint32 schoolMask = spellInfo->GetSchoolMask())
    {
        uint32 schoolImmunityMask = 0;
        SpellImmuneContainer const& schoolList = m_spellImmune[IMMUNITY_SCHOOL];
        for (auto itr = schoolList.begin(); itr != schoolList.end(); ++itr)
        {
            if ((itr->first & schoolMask) == 0)
                continue;

            SpellInfo const* immuneSpellInfo = sSpellMgr->GetSpellInfo(itr->second, GetMap()->GetDifficultyID());
            if (requireImmunityPurgesEffectAttribute)
                if (!immuneSpellInfo || !immuneSpellInfo->HasAttribute(SPELL_ATTR1_IMMUNITY_PURGES_EFFECT))
                    continue;

            // Consider the school immune if any of these conditions are not satisfied.
            // In case of no immuneSpellInfo, ignore that condition and check only the other conditions
            if ((immuneSpellInfo && !immuneSpellInfo->IsPositive()) || !spellInfo->IsPositive() || !caster || !IsFriendlyTo(caster))
                if (!spellInfo->CanPierceImmuneAura(immuneSpellInfo))
                    schoolImmunityMask |= itr->first;
        }
        if ((schoolImmunityMask & schoolMask) == schoolMask)
            return true;
    }

    return false;
}

uint32 Unit::GetSchoolImmunityMask() const
{
    uint32 mask = 0;
    SpellImmuneContainer const& schoolList = m_spellImmune[IMMUNITY_SCHOOL];
    for (auto itr = schoolList.begin(); itr != schoolList.end(); ++itr)
        mask |= itr->first;

    return mask;
}

uint32 Unit::GetDamageImmunityMask() const
{
    uint32 mask = 0;
    SpellImmuneContainer const& damageList = m_spellImmune[IMMUNITY_DAMAGE];
    for (auto itr = damageList.begin(); itr != damageList.end(); ++itr)
        mask |= itr->first;

    return mask;
}

uint64 Unit::GetMechanicImmunityMask() const
{
    uint64 mask = 0;
    SpellImmuneContainer const& mechanicList = m_spellImmune[IMMUNITY_MECHANIC];
    for (auto itr = mechanicList.begin(); itr != mechanicList.end(); ++itr)
        mask |= (UI64LIT(1) << itr->first);

    return mask;
}

EnumFlag<SpellOtherImmunity> Unit::GetSpellOtherImmunityMask() const
{
    SpellOtherImmunity mask = { };
    SpellImmuneContainer const& damageList = m_spellImmune[IMMUNITY_OTHER];
    for (auto itr = damageList.begin(); itr != damageList.end(); ++itr)
        mask |= SpellOtherImmunity(itr->first);

    return mask;
}

bool Unit::IsImmunedToSpellEffect(SpellInfo const* spellInfo, SpellEffectInfo const& spellEffectInfo, WorldObject const* caster,
    bool requireImmunityPurgesEffectAttribute /*= false*/) const
{
    if (!spellInfo)
        return false;

    if (spellInfo->HasAttribute(SPELL_ATTR0_NO_IMMUNITIES))
        return false;

    if (spellEffectInfo.EffectAttributes.HasFlag(SpellEffectAttributes::NoImmunity))
        return false;

    auto hasImmunity = [requireImmunityPurgesEffectAttribute](SpellImmuneContainer const& container, uint32 key)
    {
        Trinity::IteratorPair<SpellImmuneContainer::const_iterator> range = Trinity::Containers::MapEqualRange(container, key);
        if (!requireImmunityPurgesEffectAttribute)
            return range.begin() != range.end();

        return std::any_of(range.begin(), range.end(), [](SpellImmuneContainer::value_type const& entry)
        {
            if (SpellInfo const* immunitySourceSpell = sSpellMgr->GetSpellInfo(entry.second, DIFFICULTY_NONE))
                if (immunitySourceSpell->HasAttribute(SPELL_ATTR1_IMMUNITY_PURGES_EFFECT))
                    return true;

            return false;
        });
    };

    // If m_immuneToEffect type contain this effect type, IMMUNE effect.
    auto const& effectList = m_spellImmune[IMMUNITY_EFFECT];
    if (hasImmunity(effectList, spellEffectInfo.Effect))
        return true;

    if (uint32 mechanic = spellEffectInfo.Mechanic)
    {
        SpellImmuneContainer const& mechanicList = m_spellImmune[IMMUNITY_MECHANIC];
        if (hasImmunity(mechanicList, mechanic))
            return true;
    }

    if (AuraType aura = spellEffectInfo.ApplyAuraName)
    {
        if (!spellInfo->HasAttribute(SPELL_ATTR3_ALWAYS_HIT))
        {
            SpellImmuneContainer const& list = m_spellImmune[IMMUNITY_STATE];
            if (hasImmunity(list, aura))
                return true;
        }

        if (!spellInfo->HasAttribute(SPELL_ATTR2_NO_SCHOOL_IMMUNITIES))
        {
            // Check for immune to application of harmful magical effects
            AuraEffectList const& immuneAuraApply = GetAuraEffectsByType(SPELL_AURA_MOD_IMMUNE_AURA_APPLY_SCHOOL);
            for (AuraEffectList::const_iterator iter = immuneAuraApply.begin(); iter != immuneAuraApply.end(); ++iter)
                if (((*iter)->GetMiscValue() & spellInfo->GetSchoolMask()) &&                   // Check school
                    ((caster && !IsFriendlyTo(caster)) || !spellInfo->IsPositiveEffect(spellEffectInfo.EffectIndex))) // Harmful
                    return true;
        }
    }

    return false;
}

int32 Unit::MeleeDamageBonusDone(Unit* pVictim, int32 damage, WeaponAttackType attType, DamageEffectType damagetype, SpellInfo const* spellProto /*= nullptr*/, Mechanics mechanic /*= nullptr*/, SpellSchoolMask damageSchoolMask /*= SPELL_SCHOOL_MASK_NORMAL*/, Spell* spell /*= nullptr*/, AuraEffect const* aurEff /*= nullptr*/)
{
    if (!pVictim || damage == 0)
        return 0;

    uint32 creatureTypeMask = pVictim->GetCreatureTypeMask();

    // Done fixed damage bonus auras
    int32 DoneFlatBenefit = 0;

    // ..done
    DoneFlatBenefit += GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_DAMAGE_DONE_CREATURE, creatureTypeMask);

    // ..done
    // SPELL_AURA_MOD_DAMAGE_DONE included in weapon damage

    // ..done (base at attack power for marked target and base at attack power for creature type)
    int32 APbonus = 0;

    if (attType == RANGED_ATTACK)
    {
        APbonus += pVictim->GetTotalAuraModifier(SPELL_AURA_RANGED_ATTACK_POWER_ATTACKER_BONUS);

        // ..done (base at attack power and creature type)
        APbonus += GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_RANGED_ATTACK_POWER_VERSUS, creatureTypeMask);
    }
    else
    {
        APbonus += pVictim->GetTotalAuraModifier(SPELL_AURA_MELEE_ATTACK_POWER_ATTACKER_BONUS);

        // ..done (base at attack power and creature type)
        APbonus += GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_MELEE_ATTACK_POWER_VERSUS, creatureTypeMask);
    }

    if (APbonus != 0)                                       // Can be negative
    {
        bool const normalized = spellProto && spellProto->HasEffect(SPELL_EFFECT_NORMALIZED_WEAPON_DMG);
        DoneFlatBenefit += int32(APbonus / 3.5f * GetAPMultiplier(attType, normalized));
    }

    // Done total percent damage auras
    float DoneTotalMod = 1.0f;

    SpellSchoolMask schoolMask = spellProto ? spellProto->GetSchoolMask() : damageSchoolMask;

    if (!(schoolMask & SPELL_SCHOOL_MASK_NORMAL))
    {
        // Some spells don't benefit from pct done mods
        // mods for SPELL_SCHOOL_MASK_NORMAL are already factored in base melee damage calculation
        if (!spellProto || !spellProto->HasAttribute(SPELL_ATTR6_IGNORE_CASTER_DAMAGE_MODIFIERS))
        {
            float maxModDamagePercentSchool = 0.0f;
            if (Player const* thisPlayer = ToPlayer())
            {
                for (uint32 i = SPELL_SCHOOL_HOLY; i < MAX_SPELL_SCHOOL; ++i)
                    if (schoolMask & (1 << i))
                        maxModDamagePercentSchool = std::max(maxModDamagePercentSchool, thisPlayer->m_activePlayerData->ModDamageDonePercent[i]);
            }
            else
                maxModDamagePercentSchool = GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, schoolMask);

            DoneTotalMod *= maxModDamagePercentSchool;
        }
    }

    if (!spellProto)
    {
        // melee attack
        for (AuraEffect const* autoAttackDamage : GetAuraEffectsByType(SPELL_AURA_MOD_AUTOATTACK_DAMAGE))
            AddPct(DoneTotalMod, autoAttackDamage->GetAmount());
    }

    DoneTotalMod *= GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_DAMAGE_DONE_VERSUS, creatureTypeMask);

    // bonus against aurastate
    DoneTotalMod *= GetTotalAuraMultiplier(SPELL_AURA_MOD_DAMAGE_DONE_VERSUS_AURASTATE, [pVictim](AuraEffect const* aurEff) -> bool
    {
        if (pVictim->HasAuraState(AuraStateType(aurEff->GetMiscValue())))
            return true;
        return false;
    });

    // bonus against target aura mechanic
    DoneTotalMod *= GetTotalAuraMultiplier(SPELL_AURA_MOD_DAMAGE_PERCENT_DONE_BY_TARGET_AURA_MECHANIC, [pVictim](AuraEffect const* aurEff) -> bool
    {
        if (pVictim->HasAuraWithMechanic(UI64LIT(1) << aurEff->GetMiscValue()))
            return true;
        return false;
    });

    // Add SPELL_AURA_MOD_DAMAGE_DONE_FOR_MECHANIC percent bonus
    if (mechanic != MECHANIC_NONE)
        AddPct(DoneTotalMod, GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_DAMAGE_DONE_FOR_MECHANIC, mechanic));
    else if (spellProto && spellProto->Mechanic)
        AddPct(DoneTotalMod, GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_DAMAGE_DONE_FOR_MECHANIC, spellProto->Mechanic));

    if (spell)
        spell->CallScriptCalcDamageHandlers(pVictim, damage, DoneFlatBenefit, DoneTotalMod);
    else if (aurEff)
        aurEff->GetBase()->CallScriptCalcDamageAndHealingHandlers(aurEff, aurEff->GetBase()->GetApplicationOfTarget(pVictim->GetGUID()), pVictim, damage, DoneFlatBenefit, DoneTotalMod);

    float damageF = float(damage + DoneFlatBenefit) * DoneTotalMod;

    // apply spellmod to Done damage
    if (spellProto)
        if (Player* modOwner = GetSpellModOwner())
            modOwner->ApplySpellMod(spellProto, damagetype == DOT ? SpellModOp::PeriodicHealingAndDamage : SpellModOp::HealingAndDamage, damageF);

    // bonus result can be negative
    return int32(std::max(damageF, 0.0f));
}

int32 Unit::MeleeDamageBonusTaken(Unit* attacker, int32 pdamage, WeaponAttackType attType, DamageEffectType damagetype, SpellInfo const* spellProto /*= nullptr*/, SpellSchoolMask damageSchoolMask /*= SPELL_SCHOOL_MASK_NORMAL*/)
{
    if (pdamage == 0)
        return 0;

    int32 TakenFlatBenefit = 0;

    // ..taken
    TakenFlatBenefit += GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_DAMAGE_TAKEN, attacker->GetMeleeDamageSchoolMask());

    if (attType != RANGED_ATTACK)
        TakenFlatBenefit += GetTotalAuraModifier(SPELL_AURA_MOD_MELEE_DAMAGE_TAKEN);
    else
        TakenFlatBenefit += GetTotalAuraModifier(SPELL_AURA_MOD_RANGED_DAMAGE_TAKEN);

    if ((TakenFlatBenefit < 0) && (pdamage < -TakenFlatBenefit))
        return 0;

    // Taken total percent damage auras
    float TakenTotalMod = 1.0f;

    // ..taken
    TakenTotalMod *= GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, attacker->GetMeleeDamageSchoolMask());

    // .. taken pct (special attacks)
    if (spellProto)
    {
        // From caster spells
        TakenTotalMod *= GetTotalAuraMultiplier(SPELL_AURA_MOD_SCHOOL_MASK_DAMAGE_FROM_CASTER, [attacker, spellProto](AuraEffect const* aurEff) -> bool
        {
            return aurEff->GetCasterGUID() == attacker->GetGUID() && (aurEff->GetMiscValue() & spellProto->GetSchoolMask());
        });

        TakenTotalMod *= GetTotalAuraMultiplier(SPELL_AURA_MOD_SPELL_DAMAGE_FROM_CASTER, [attacker, spellProto](AuraEffect const* aurEff) -> bool
        {
            return aurEff->GetCasterGUID() == attacker->GetGUID() && aurEff->IsAffectingSpell(spellProto);
        });

        // Mod damage from spell mechanic
        uint64 mechanicMask = spellProto->GetAllEffectsMechanicMask();

        // Shred, Maul - "Effects which increase Bleed damage also increase Shred damage"
        if (spellProto->SpellFamilyName == SPELLFAMILY_DRUID && spellProto->SpellFamilyFlags[0] & 0x00008800)
            mechanicMask |= (1 << MECHANIC_BLEED);

        if (mechanicMask)
        {
            TakenTotalMod *= GetTotalAuraMultiplier(SPELL_AURA_MOD_MECHANIC_DAMAGE_TAKEN_PERCENT, [mechanicMask](AuraEffect const* aurEff) -> bool
            {
                if (mechanicMask & uint64(UI64LIT(1) << (aurEff->GetMiscValue())))
                    return true;
                return false;
            });
        }

        if (damagetype == DOT)
        {
            TakenTotalMod *= GetTotalAuraMultiplier(SPELL_AURA_MOD_PERIODIC_DAMAGE_TAKEN, [spellProto](AuraEffect const* aurEff) -> bool
            {
                return aurEff->GetMiscValue() & spellProto->GetSchoolMask();
            });
        }
    }
    else // melee attack
    {
        TakenTotalMod *= GetTotalAuraMultiplier(SPELL_AURA_MOD_MELEE_DAMAGE_FROM_CASTER, [attacker](AuraEffect const* aurEff) -> bool
        {
            return aurEff->GetCasterGUID() == attacker->GetGUID();
        });
    }

    if (AuraEffect const* cheatDeath = GetAuraEffect(45182, EFFECT_0))
        AddPct(TakenTotalMod, cheatDeath->GetAmount());

    if (attType != RANGED_ATTACK)
        TakenTotalMod *= GetTotalAuraMultiplier(SPELL_AURA_MOD_MELEE_DAMAGE_TAKEN_PCT);
    else
        TakenTotalMod *= GetTotalAuraMultiplier(SPELL_AURA_MOD_RANGED_DAMAGE_TAKEN_PCT);

    // Versatility
    if (Player* modOwner = GetSpellModOwner())
    {
        // only 50% of SPELL_AURA_MOD_VERSATILITY for damage reduction
        float versaBonus = modOwner->GetTotalAuraModifier(SPELL_AURA_MOD_VERSATILITY) / 2.0f;
        AddPct(TakenTotalMod, -(modOwner->GetRatingBonusValue(CR_VERSATILITY_DAMAGE_TAKEN) + versaBonus));
    }

    // Sanctified Wrath (bypass damage reduction)
    if (TakenTotalMod < 1.0f)
    {
        SpellSchoolMask const attackSchoolMask = spellProto ? spellProto->GetSchoolMask() : damageSchoolMask;

        float damageReduction = 1.0f - TakenTotalMod;
        Unit::AuraEffectList const& casterIgnoreResist = attacker->GetAuraEffectsByType(SPELL_AURA_MOD_IGNORE_TARGET_RESIST);
        for (AuraEffect const* aurEff : casterIgnoreResist)
        {
            if (!(aurEff->GetMiscValue() & attackSchoolMask))
                continue;

            AddPct(damageReduction, -aurEff->GetAmount());
        }

        TakenTotalMod = 1.0f - damageReduction;
    }

    float tmpDamage = float(pdamage + TakenFlatBenefit) * TakenTotalMod;
    return int32(std::max(tmpDamage, 0.0f));
}

void Unit::ApplySpellImmune(uint32 spellId, SpellImmunity op, uint32 type, bool apply)
{
    if (apply)
        m_spellImmune[op].emplace(type, spellId);
    else
    {
        auto bounds = m_spellImmune[op].equal_range(type);
        for (auto itr = bounds.first; itr != bounds.second;)
        {
            if (itr->second == spellId)
                itr = m_spellImmune[op].erase(itr);
            else
                ++itr;
        }
    }
}

float Unit::GetWeaponProcChance() const
{
    // normalized proc chance for weapon attack speed
    // (odd formula...)
    if (isAttackReady(BASE_ATTACK))
        return (GetBaseAttackTime(BASE_ATTACK) * 1.8f / 1000.0f);
    else if (haveOffhandWeapon() && isAttackReady(OFF_ATTACK))
        return (GetBaseAttackTime(OFF_ATTACK) * 1.6f / 1000.0f);
    return 0;
}

float Unit::GetPPMProcChance(uint32 WeaponSpeed, float PPM, SpellInfo const* spellProto) const
{
    // proc per minute chance calculation
    if (PPM <= 0)
        return 0.0f;

    // Apply chance modifer aura
    if (spellProto)
        if (Player* modOwner = GetSpellModOwner())
            modOwner->ApplySpellMod(spellProto, SpellModOp::ProcFrequency, PPM);

    return std::floor((WeaponSpeed * PPM) / 600.0f);   // result is chance in percents (probability = Speed_in_sec * (PPM / 60))
}

void Unit::Mount(uint32 mount, uint32 VehicleId, uint32 creatureEntry)
{
    RemoveAurasByType(SPELL_AURA_COSMETIC_MOUNTED);
    if (mount)
        SetMountDisplayId(mount);

    SetUnitFlag(UNIT_FLAG_MOUNT);

    CalculateHoverHeight();

    if (Player* player = ToPlayer())
    {
        // mount as a vehicle
        if (VehicleId)
        {
            if (CreateVehicleKit(VehicleId, creatureEntry))
            {
                player->SendOnCancelExpectedVehicleRideAura();

                // mounts can also have accessories
                GetVehicleKit()->InstallAllAccessories(false);
            }
        }

        // disable pet controls
        player->DisablePetControlsOnMount(REACT_PASSIVE, COMMAND_FOLLOW);

        player->SendMovementSetCollisionHeight(player->GetCollisionHeight(), WorldPackets::Movement::UpdateCollisionHeightReason::Mount);
    }

    RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::Mount);
}

void Unit::Dismount()
{
    if (!IsMounted())
        return;

    SetMountDisplayId(0);
    RemoveUnitFlag(UNIT_FLAG_MOUNT);

    if (Player* thisPlayer = ToPlayer())
        thisPlayer->SendMovementSetCollisionHeight(thisPlayer->GetCollisionHeight(), WorldPackets::Movement::UpdateCollisionHeightReason::Mount);

    CalculateHoverHeight();

    // dismount as a vehicle
    if (GetTypeId() == TYPEID_PLAYER && GetVehicleKit())
    {
        // Remove vehicle from player
        RemoveVehicleKit();
    }

    RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::Dismount);

    // only resummon old pet if the player is already added to a map
    // this prevents adding a pet to a not created map which would otherwise cause a crash
    // (it could probably happen when logging in after a previous crash)
    if (Player* player = ToPlayer())
    {
        player->EnablePetControlsOnDismount();
        player->ResummonPetTemporaryUnSummonedIfAny();
        player->ResummonBattlePetTemporaryUnSummonedIfAny();
    }
}

MountCapabilityEntry const* Unit::GetMountCapability(uint32 mountType) const
{
    if (!mountType)
        return nullptr;

    DB2Manager::MountTypeXCapabilitySet const* capabilities = sDB2Manager.GetMountCapabilities(mountType);
    if (!capabilities)
        return nullptr;

    uint32 areaId = GetAreaId();
    uint32 ridingSkill = 5000;
    EnumFlag<AreaMountFlags> mountFlags = AreaMountFlags::None;
    bool isSubmerged = false;
    bool isInWater = false;

    if (GetTypeId() == TYPEID_PLAYER)
        ridingSkill = ToPlayer()->GetSkillValue(SKILL_RIDING);

    if (HasAuraType(SPELL_AURA_MOUNT_RESTRICTIONS))
    {
        for (AuraEffect const* auraEffect : GetAuraEffectsByType(SPELL_AURA_MOUNT_RESTRICTIONS))
            mountFlags |= AreaMountFlags(auraEffect->GetMiscValue());
    }
    else if (AreaTableEntry const* areaTable = sAreaTableStore.LookupEntry(areaId))
        mountFlags = areaTable->GetMountFlags();

    LiquidData liquid;
    ZLiquidStatus liquidStatus = GetMap()->GetLiquidStatus(GetPhaseShift(), GetPositionX(), GetPositionY(), GetPositionZ(), {}, &liquid);
    isSubmerged = (liquidStatus & LIQUID_MAP_UNDER_WATER) != 0 || HasUnitMovementFlag(MOVEMENTFLAG_SWIMMING);
    isInWater = (liquidStatus & (LIQUID_MAP_IN_WATER | LIQUID_MAP_UNDER_WATER)) != 0;

    for (MountTypeXCapabilityEntry const* mountTypeXCapability : *capabilities)
    {
        MountCapabilityEntry const* mountCapability = sMountCapabilityStore.LookupEntry(mountTypeXCapability->MountCapabilityID);
        if (!mountCapability)
            continue;

        if (ridingSkill < mountCapability->ReqRidingSkill)
            continue;

        if (!(mountCapability->Flags & MOUNT_CAPABIILTY_FLAG_IGNORE_RESTRICTIONS))
        {
            if (mountCapability->Flags & MOUNT_CAPABILITY_FLAG_GROUND && !(mountFlags.HasFlag(AreaMountFlags::AllowGroundMounts)))
                continue;
            if (mountCapability->Flags & MOUNT_CAPABILITY_FLAG_FLYING && !(mountFlags.HasFlag(AreaMountFlags::AllowFlyingMounts)))
                continue;
            if (mountCapability->Flags & MOUNT_CAPABILITY_FLAG_FLOAT && !(mountFlags.HasFlag(AreaMountFlags::AllowSurfaceSwimmingMounts)))
                continue;
            if (mountCapability->Flags & MOUNT_CAPABILITY_FLAG_UNDERWATER && !(mountFlags.HasFlag(AreaMountFlags::AllowUnderwaterSwimmingMounts)))
                continue;
        }

        if (!isSubmerged)
        {
            if (!isInWater)
            {
                // player is completely out of water
                if (!(mountCapability->Flags & MOUNT_CAPABILITY_FLAG_GROUND))
                    continue;
            }
            // player is on water surface
            else if (!(mountCapability->Flags & MOUNT_CAPABILITY_FLAG_FLOAT))
                continue;
        }
        else if (isInWater)
        {
            if (!(mountCapability->Flags & MOUNT_CAPABILITY_FLAG_UNDERWATER))
                continue;
        }
        else if (!(mountCapability->Flags & MOUNT_CAPABILITY_FLAG_FLOAT))
            continue;

        if (mountCapability->ReqMapID != -1 &&
            int32(GetMapId()) != mountCapability->ReqMapID &&
            GetMap()->GetEntry()->CosmeticParentMapID != mountCapability->ReqMapID &&
            GetMap()->GetEntry()->ParentMapID != mountCapability->ReqMapID)
            continue;

        if (mountCapability->ReqAreaID && !DB2Manager::IsInArea(areaId, mountCapability->ReqAreaID))
            continue;

        if (mountCapability->ReqSpellAuraID && !HasAura(mountCapability->ReqSpellAuraID))
            continue;

        if (mountCapability->ReqSpellKnownID && !HasSpell(mountCapability->ReqSpellKnownID))
            continue;

        if (Player const* thisPlayer = ToPlayer())
            if (!ConditionMgr::IsPlayerMeetingCondition(thisPlayer, mountCapability->PlayerConditionID))
                continue;

        return mountCapability;
    }

    return nullptr;
}

void Unit::UpdateMountCapability()
{
    if (IsLoading())
        return;

    AuraEffectVector mounts = CopyAuraEffectList(GetAuraEffectsByType(SPELL_AURA_MOUNTED));
    for (AuraEffect* aurEff : mounts)
    {
        aurEff->RecalculateAmount();
        if (!aurEff->GetAmount())
            aurEff->GetBase()->Remove();
        else if (MountCapabilityEntry const* capability = sMountCapabilityStore.LookupEntry(aurEff->GetAmount())) // aura may get removed by interrupt flag, reapply
            if (!HasAura(capability->ModSpellAuraID))
                CastSpell(this, capability->ModSpellAuraID, aurEff);
    }
}

bool Unit::IsServiceProvider() const
{
    return HasNpcFlag(
        UNIT_NPC_FLAG_VENDOR | UNIT_NPC_FLAG_TRAINER | UNIT_NPC_FLAG_FLIGHTMASTER |
        UNIT_NPC_FLAG_PETITIONER | UNIT_NPC_FLAG_BATTLEMASTER | UNIT_NPC_FLAG_BANKER |
        UNIT_NPC_FLAG_INNKEEPER | UNIT_NPC_FLAG_SPIRIT_HEALER |
        UNIT_NPC_FLAG_AREA_SPIRIT_HEALER | UNIT_NPC_FLAG_TABARDDESIGNER | UNIT_NPC_FLAG_AUCTIONEER);
}

void Unit::EngageWithTarget(Unit* enemy)
{
    if (!enemy)
        return;

    if (CanHaveThreatList())
        m_threatManager.AddThreat(enemy, 0.0f, nullptr, true, true);
    else
        SetInCombatWith(enemy);
}

void Unit::SetImmuneToAll(bool apply, bool keepCombat)
{
    if (apply)
    {
        SetUnitFlag(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
        ValidateAttackersAndOwnTarget();
        if (!keepCombat)
            m_combatManager.EndAllCombat();
    }
    else
        RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
}

void Unit::SetImmuneToPC(bool apply, bool keepCombat)
{
    if (apply)
    {
        SetUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
        ValidateAttackersAndOwnTarget();
        if (!keepCombat)
        {
            std::list<CombatReference*> toEnd;
            for (auto const& pair : m_combatManager.GetPvECombatRefs())
                if (pair.second->GetOther(this)->HasUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED))
                    toEnd.push_back(pair.second);
            for (auto const& pair : m_combatManager.GetPvPCombatRefs())
                if (pair.second->GetOther(this)->HasUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED))
                    toEnd.push_back(pair.second);
            for (CombatReference* ref : toEnd)
                ref->EndCombat();
        }
    }
    else
        RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
}

void Unit::SetImmuneToNPC(bool apply, bool keepCombat)
{
    if (apply)
    {
        SetUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
        ValidateAttackersAndOwnTarget();
        if (!keepCombat)
        {
            std::list<CombatReference*> toEnd;
            for (auto const& pair : m_combatManager.GetPvECombatRefs())
                if (!pair.second->GetOther(this)->HasUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED))
                    toEnd.push_back(pair.second);
            for (auto const& pair : m_combatManager.GetPvPCombatRefs())
                if (!pair.second->GetOther(this)->HasUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED))
                    toEnd.push_back(pair.second);
            for (CombatReference* ref : toEnd)
                ref->EndCombat();
        }
    }
    else
        RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
}

void Unit::SetUninteractible(bool apply)
{
    if (apply)
        SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
    else
        RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
}

void Unit::SetCannotTurn(bool apply)
{
    if (apply)
        SetUnitFlag2(UNIT_FLAG2_CANNOT_TURN);
    else
        RemoveUnitFlag2(UNIT_FLAG2_CANNOT_TURN);
}

bool Unit::IsThreatened() const
{
    return !m_threatManager.IsThreatListEmpty();
}

bool Unit::isTargetableForAttack(bool checkFakeDeath) const
{
    if (!IsAlive())
        return false;

    if (HasUnitFlag(UNIT_FLAG_NON_ATTACKABLE) || IsUninteractible())
        return false;

    if (GetTypeId() == TYPEID_PLAYER && ToPlayer()->IsGameMaster())
        return false;

    return !HasUnitState(UNIT_STATE_UNATTACKABLE) && (!checkFakeDeath || !HasUnitState(UNIT_STATE_DIED));
}

int64 Unit::ModifyHealth(int64 dVal)
{
    int64 gain = 0;

    if (dVal == 0)
        return 0;

    int64 curHealth = (int64)GetHealth();

    int64 val = dVal + curHealth;
    if (val <= 0)
    {
        SetHealth(0);
        return -curHealth;
    }

    int64 maxHealth = (int64)GetMaxHealth();

    if (val < maxHealth)
    {
        SetHealth(val);
        gain = val - curHealth;
    }
    else if (curHealth != maxHealth)
    {
        SetHealth(maxHealth);
        gain = maxHealth - curHealth;
    }

    if (dVal < 0)
    {
        WorldPackets::Combat::HealthUpdate packet;
        packet.Guid = GetGUID();
        packet.Health = GetHealth();

        if (Player* player = GetCharmerOrOwnerPlayerOrPlayerItself())
            player->GetSession()->SendPacket(packet.Write());
    }

    return gain;
}

int64 Unit::GetHealthGain(int64 dVal)
{
    int64 gain = 0;

    if (dVal == 0)
        return 0;

    int64 curHealth = (int64)GetHealth();

    int64 val = dVal + curHealth;
    if (val <= 0)
    {
        return -curHealth;
    }

    int64 maxHealth = (int64)GetMaxHealth();

    if (val < maxHealth)
        gain = dVal;
    else if (curHealth != maxHealth)
        gain = maxHealth - curHealth;

    return gain;
}

void Unit::TriggerOnHealthChangeAuras(uint64 oldVal, uint64 newVal)
{
    if (!HasAuraType(SPELL_AURA_TRIGGER_SPELL_ON_HEALTH_PCT))
        return;

    AuraEffectVector effects = CopyAuraEffectList(GetAuraEffectsByType(SPELL_AURA_TRIGGER_SPELL_ON_HEALTH_PCT));
    for (AuraEffect const* effect : effects)
    {
        uint32 triggerHealthPct = effect->GetAmount();
        uint32 triggerSpell = effect->GetSpellEffectInfo().TriggerSpell;
        uint64 threshold = CountPctFromMaxHealth(triggerHealthPct);

        switch (AuraTriggerOnHealthChangeDirection(effect->GetMiscValue()))
        {
            case AuraTriggerOnHealthChangeDirection::Above:
                if (newVal < threshold || oldVal > threshold)
                    continue;
                break;
            case AuraTriggerOnHealthChangeDirection::Below:
                if (newVal > threshold || oldVal < threshold)
                    continue;
                break;
            default:
                break;
        }

        CastSpell(this, triggerSpell, effect);
    }
}

// returns negative amount on power reduction
int32 Unit::ModifyPower(Powers power, int32 dVal, bool withPowerUpdate /*= true*/)
{
    int32 gain = 0;

    if (dVal == 0)
        return 0;

    if (dVal > 0)
        dVal *= GetTotalAuraMultiplierByMiscValue(SPELL_AURA_MOD_POWER_GAIN_PCT, power);

    int32 curPower = GetPower(power);

    int32 val = dVal + curPower;
    if (val <= GetMinPower(power))
    {
        SetPower(power, GetMinPower(power), withPowerUpdate);
        return -curPower;
    }

    int32 maxPower = GetMaxPower(power);

    if (val < maxPower)
    {
        SetPower(power, val, withPowerUpdate);
        gain = val - curPower;
    }
    else if (curPower != maxPower)
    {
        SetPower(power, maxPower, withPowerUpdate);
        gain = maxPower - curPower;
    }

    return gain;
}

bool Unit::IsAlwaysVisibleFor(WorldObject const* seer) const
{
    if (WorldObject::IsAlwaysVisibleFor(seer))
        return true;

    // Always seen by owner
    ObjectGuid guid = GetCharmerOrOwnerGUID();
    if (!guid.IsEmpty())
        if (seer->GetGUID() == guid)
            return true;

    if (Player const* seerPlayer = seer->ToPlayer())
        if (Unit* owner =  GetOwner())
            if (Player* ownerPlayer = owner->ToPlayer())
                if (ownerPlayer->IsGroupVisibleFor(seerPlayer))
                    return true;

    return false;
}

bool Unit::IsAlwaysDetectableFor(WorldObject const* seer) const
{
    if (WorldObject::IsAlwaysDetectableFor(seer))
        return true;

    if (HasAuraTypeWithCaster(SPELL_AURA_MOD_STALKED, seer->GetGUID()))
        return true;

    return false;
}

bool Unit::IsVisible() const
{
    return (m_serverSideVisibility.GetValue(SERVERSIDE_VISIBILITY_GM) > SEC_PLAYER) ? false : true;
}

void Unit::SetVisible(bool x)
{
    if (!x)
        m_serverSideVisibility.SetValue(SERVERSIDE_VISIBILITY_GM, SEC_GAMEMASTER);
    else
        m_serverSideVisibility.SetValue(SERVERSIDE_VISIBILITY_GM, SEC_PLAYER);

    UpdateObjectVisibility();
}

void Unit::UpdateSpeed(UnitMoveType mtype)
{
    int32 main_speed_mod  = 0;
    float stack_bonus     = 1.0f;
    float non_stack_bonus = 1.0f;

    switch (mtype)
    {
        // Only apply debuffs
        case MOVE_FLIGHT_BACK:
        case MOVE_RUN_BACK:
        case MOVE_SWIM_BACK:
            break;
        case MOVE_WALK:
            return;
        case MOVE_RUN:
        {
            if (IsMounted()) // Use on mount auras
            {
                main_speed_mod  = GetMaxPositiveAuraModifier(SPELL_AURA_MOD_INCREASE_MOUNTED_SPEED);
                stack_bonus     = GetTotalAuraMultiplier(SPELL_AURA_MOD_MOUNTED_SPEED_ALWAYS);
                non_stack_bonus += GetMaxPositiveAuraModifier(SPELL_AURA_MOD_MOUNTED_SPEED_NOT_STACK) / 100.0f;
            }
            else
            {
                main_speed_mod  = GetMaxPositiveAuraModifier(SPELL_AURA_MOD_INCREASE_SPEED);
                stack_bonus     = GetTotalAuraMultiplier(SPELL_AURA_MOD_SPEED_ALWAYS);
                non_stack_bonus += GetMaxPositiveAuraModifier(SPELL_AURA_MOD_SPEED_NOT_STACK) / 100.0f;
            }
            break;
        }
        case MOVE_SWIM:
        {
            main_speed_mod  = GetMaxPositiveAuraModifier(SPELL_AURA_MOD_INCREASE_SWIM_SPEED);
            break;
        }
        case MOVE_FLIGHT:
        {
            if (GetTypeId() == TYPEID_UNIT && IsControlledByPlayer()) // not sure if good for pet
            {
                main_speed_mod  = GetMaxPositiveAuraModifier(SPELL_AURA_MOD_INCREASE_VEHICLE_FLIGHT_SPEED);
                stack_bonus     = GetTotalAuraMultiplier(SPELL_AURA_MOD_VEHICLE_SPEED_ALWAYS);

                // for some spells this mod is applied on vehicle owner
                int32 owner_speed_mod = 0;

                if (Unit* owner = GetCharmer())
                    owner_speed_mod = owner->GetMaxPositiveAuraModifier(SPELL_AURA_MOD_INCREASE_VEHICLE_FLIGHT_SPEED);

                main_speed_mod = std::max(main_speed_mod, owner_speed_mod);
            }
            else if (IsMounted())
            {
                main_speed_mod  = GetMaxPositiveAuraModifier(SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED);
                stack_bonus     = GetTotalAuraMultiplier(SPELL_AURA_MOD_MOUNTED_FLIGHT_SPEED_ALWAYS);
            }
            else             // Use not mount (shapeshift for example) auras (should stack)
                main_speed_mod  = GetTotalAuraModifier(SPELL_AURA_MOD_INCREASE_FLIGHT_SPEED) + GetTotalAuraModifier(SPELL_AURA_MOD_INCREASE_VEHICLE_FLIGHT_SPEED);

            non_stack_bonus += GetMaxPositiveAuraModifier(SPELL_AURA_MOD_FLIGHT_SPEED_NOT_STACK) / 100.0f;

            // Update speed for vehicle if available
            if (GetTypeId() == TYPEID_PLAYER && GetVehicle())
                GetVehicleBase()->UpdateSpeed(MOVE_FLIGHT);
            break;
        }
        default:
            TC_LOG_ERROR("entities.unit", "Unit::UpdateSpeed: Unsupported move type ({})", mtype);
            return;
    }

    // now we ready for speed calculation
    float speed = std::max(non_stack_bonus, stack_bonus);
    if (main_speed_mod)
        AddPct(speed, main_speed_mod);

    switch (mtype)
    {
        case MOVE_RUN:
        case MOVE_SWIM:
        case MOVE_FLIGHT:
        {
            // Set creature speed rate
            if (GetTypeId() == TYPEID_UNIT)
                speed *= ToCreature()->GetCreatureTemplate()->speed_run;    // at this point, MOVE_WALK is never reached

            // Normalize speed by 191 aura SPELL_AURA_USE_NORMAL_MOVEMENT_SPEED if need
            /// @todo possible affect only on MOVE_RUN
            if (int32 normalization = GetMaxPositiveAuraModifier(SPELL_AURA_USE_NORMAL_MOVEMENT_SPEED))
            {
                if (Creature* creature = ToCreature())
                    if (CreatureImmunities const* immunities = SpellMgr::GetCreatureImmunities(creature->GetCreatureTemplate()->CreatureImmunitiesId))
                        if (immunities->Mechanic[MECHANIC_SNARE] || immunities->Mechanic[MECHANIC_DAZE])
                            break;

                // Use speed from aura
                float max_speed = normalization / (IsControlledByPlayer() ? playerBaseMoveSpeed[mtype] : baseMoveSpeed[mtype]);
                if (speed > max_speed)
                    speed = max_speed;
            }

            if (mtype == MOVE_RUN)
            {
                // force minimum speed rate @ aura 437 SPELL_AURA_MOD_MINIMUM_SPEED_RATE
                if (int32 minSpeedMod = GetMaxPositiveAuraModifier(SPELL_AURA_MOD_MINIMUM_SPEED_RATE))
                {
                    float minSpeed = minSpeedMod / (IsControlledByPlayer() ? playerBaseMoveSpeed[mtype] : baseMoveSpeed[mtype]);
                    if (speed < minSpeed)
                        speed = minSpeed;
                }
            }
            break;
        }
        default:
            break;
    }

    if (Creature* creature = ToCreature())
    {
        if (creature->HasUnitTypeMask(UNIT_MASK_MINION) && !creature->IsInCombat())
        {
            if (GetMotionMaster()->GetCurrentMovementGeneratorType() == FOLLOW_MOTION_TYPE)
            {
                Unit* followed = ASSERT_NOTNULL(dynamic_cast<AbstractFollower*>(GetMotionMaster()->GetCurrentMovementGenerator()))->GetTarget();
                if (followed && followed->GetGUID() == GetOwnerGUID() && !followed->IsInCombat())
                {
                    float ownerSpeed = followed->GetSpeedRate(mtype);
                    if (speed < ownerSpeed || creature->IsWithinDist3d(followed, 10.0f))
                        speed = ownerSpeed;
                    speed *= std::min(std::max(1.0f, 0.75f + (GetDistance(followed) - PET_FOLLOW_DIST) * 0.05f), 1.3f);
                }
            }
        }
    }

    // Apply strongest slow aura mod to speed
    int32 slow = GetMaxNegativeAuraModifier(SPELL_AURA_MOD_DECREASE_SPEED);
    if (slow)
        AddPct(speed, slow);

    if (float minSpeedMod = (float)GetMaxPositiveAuraModifier(SPELL_AURA_MOD_MINIMUM_SPEED))
    {
        float baseMinSpeed = 1.0f;
        if (!GetOwnerGUID().IsPlayer() && !IsHunterPet() && GetTypeId() == TYPEID_UNIT)
            baseMinSpeed = ToCreature()->GetCreatureTemplate()->speed_run;

        float min_speed = CalculatePct(baseMinSpeed, minSpeedMod);
        if (speed < min_speed)
            speed = min_speed;
    }

    SetSpeedRate(mtype, speed);
}

float Unit::GetSpeed(UnitMoveType mtype) const
{
    return m_speed_rate[mtype]*(IsControlledByPlayer() ? playerBaseMoveSpeed[mtype] : baseMoveSpeed[mtype]);
}

void Unit::SetSpeed(UnitMoveType mtype, float newValue)
{
    SetSpeedRate(mtype, newValue / (IsControlledByPlayer() ? playerBaseMoveSpeed[mtype] : baseMoveSpeed[mtype]));
}

void Unit::SetSpeedRate(UnitMoveType mtype, float rate)
{
    rate = std::max(rate, 0.01f);

    // Update speed only on change
    if (m_speed_rate[mtype] == rate)
        return;

    m_speed_rate[mtype] = rate;

    PropagateSpeedChange();

    // Spline packets are for creatures and move_update are for players
    static OpcodeServer const moveTypeToOpcode[MAX_MOVE_TYPE][3] =
    {
        {SMSG_MOVE_SPLINE_SET_WALK_SPEED,        SMSG_MOVE_SET_WALK_SPEED,        SMSG_MOVE_UPDATE_WALK_SPEED       },
        {SMSG_MOVE_SPLINE_SET_RUN_SPEED,         SMSG_MOVE_SET_RUN_SPEED,         SMSG_MOVE_UPDATE_RUN_SPEED        },
        {SMSG_MOVE_SPLINE_SET_RUN_BACK_SPEED,    SMSG_MOVE_SET_RUN_BACK_SPEED,    SMSG_MOVE_UPDATE_RUN_BACK_SPEED   },
        {SMSG_MOVE_SPLINE_SET_SWIM_SPEED,        SMSG_MOVE_SET_SWIM_SPEED,        SMSG_MOVE_UPDATE_SWIM_SPEED       },
        {SMSG_MOVE_SPLINE_SET_SWIM_BACK_SPEED,   SMSG_MOVE_SET_SWIM_BACK_SPEED,   SMSG_MOVE_UPDATE_SWIM_BACK_SPEED  },
        {SMSG_MOVE_SPLINE_SET_TURN_RATE,         SMSG_MOVE_SET_TURN_RATE,         SMSG_MOVE_UPDATE_TURN_RATE        },
        {SMSG_MOVE_SPLINE_SET_FLIGHT_SPEED,      SMSG_MOVE_SET_FLIGHT_SPEED,      SMSG_MOVE_UPDATE_FLIGHT_SPEED     },
        {SMSG_MOVE_SPLINE_SET_FLIGHT_BACK_SPEED, SMSG_MOVE_SET_FLIGHT_BACK_SPEED, SMSG_MOVE_UPDATE_FLIGHT_BACK_SPEED},
        {SMSG_MOVE_SPLINE_SET_PITCH_RATE,        SMSG_MOVE_SET_PITCH_RATE,        SMSG_MOVE_UPDATE_PITCH_RATE       },
    };

    if (GetTypeId() == TYPEID_PLAYER)
    {
        // register forced speed changes for WorldSession::HandleForceSpeedChangeAck
        // and do it only for real sent packets and use run for run/mounted as client expected
        ++ToPlayer()->m_forced_speed_changes[mtype];

        if (!IsInCombat())
            if (Pet* pet = ToPlayer()->GetPet())
                pet->SetSpeedRate(mtype, m_speed_rate[mtype]);
    }

    if (Player* playerMover = Unit::ToPlayer(GetUnitBeingMoved())) // unit controlled by a player.
    {
        // Send notification to self
        WorldPackets::Movement::MoveSetSpeed selfpacket(moveTypeToOpcode[mtype][1]);
        selfpacket.MoverGUID = GetGUID();
        selfpacket.SequenceIndex = m_movementCounter++;
        selfpacket.Speed = GetSpeed(mtype);
        playerMover->GetSession()->SendPacket(selfpacket.Write());

        // Send notification to other players
        WorldPackets::Movement::MoveUpdateSpeed packet(moveTypeToOpcode[mtype][2]);
        packet.Status = &m_movementInfo;
        packet.Speed = GetSpeed(mtype);
        playerMover->SendMessageToSet(packet.Write(), false);
    }
    else
    {
        WorldPackets::Movement::MoveSplineSetSpeed packet(moveTypeToOpcode[mtype][0]);
        packet.MoverGUID = GetGUID();
        packet.Speed = GetSpeed(mtype);
        SendMessageToSet(packet.Write(), true);
    }
}

void Unit::RemoveAllFollowers()
{
    while (!m_followingMe.empty())
        (*m_followingMe.begin())->SetTarget(nullptr);
}

void Unit::setDeathState(DeathState s)
{
    // Death state needs to be updated before RemoveAllAurasOnDeath() is called, to prevent entering combat
    m_deathState = s;

    bool isOnVehicle = GetVehicle() != nullptr;

    if (s != ALIVE && s != JUST_RESPAWNED)
    {
        CombatStop();

        if (IsNonMeleeSpellCast(false))
            InterruptNonMeleeSpells(false);

        ExitVehicle();                                      // Exit vehicle before calling RemoveAllControlled
                                                            // vehicles use special type of charm that is not removed by the next function
                                                            // triggering an assert
        UnsummonAllTotems();
        RemoveAllControlled();
        RemoveAllAurasOnDeath();
    }

    if (s == JUST_DIED)
    {
        // remove aurastates allowing special moves
        ClearAllReactives();
        ClearDiminishings();

        // Don't clear the movement if the Unit was on a vehicle as we are exiting now
        if (!isOnVehicle)
        {
            if (GetMotionMaster()->StopOnDeath())
                DisableSpline();
        }

        // without this when removing IncreaseMaxHealth aura player may stuck with 1 hp
        // do not why since in IncreaseMaxHealth currenthealth is checked
        SetHealth(0);
        SetPower(GetPowerType(), 0);
        SetEmoteState(EMOTE_ONESHOT_NONE);
        SetStandState(UNIT_STAND_STATE_STAND);

        if (m_vignette && !m_vignette->Data->GetFlags().HasFlag(VignetteFlags::PersistsThroughDeath))
            SetVignette(0);

        // players in instance don't have ZoneScript, but they have InstanceScript
        if (ZoneScript* zoneScript = GetZoneScript() ? GetZoneScript() : GetInstanceScript())
            zoneScript->OnUnitDeath(this);
    }
    else if (s == JUST_RESPAWNED)
        RemoveUnitFlag(UNIT_FLAG_SKINNABLE); // clear skinnable for creature and player (at battleground)
}

//======================================================================

void Unit::AtEnterCombat()
{
    for (auto itr = m_appliedAuras.begin(); itr != m_appliedAuras.end();)
    {
        AuraApplication* aurApp = itr->second;
        ++itr;

        aurApp->GetBase()->CallScriptEnterLeaveCombatHandlers(aurApp, true);
    }

    if (Spell* spell = m_currentSpells[CURRENT_GENERIC_SPELL])
        if (spell->getState() == SPELL_STATE_PREPARING
            && spell->m_spellInfo->HasAttribute(SPELL_ATTR0_NOT_IN_COMBAT_ONLY_PEACEFUL)
            && spell->m_spellInfo->InterruptFlags.HasFlag(SpellInterruptFlags::Combat))
            InterruptNonMeleeSpells(false);

    RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::EnteringCombat);
    Unit::ProcSkillsAndAuras(this, nullptr, PROC_FLAG_ENTER_COMBAT, PROC_FLAG_NONE, PROC_SPELL_TYPE_MASK_ALL, PROC_SPELL_PHASE_NONE, PROC_HIT_NONE, nullptr, nullptr, nullptr);

    if (!IsInteractionAllowedInCombat())
        UpdateNearbyPlayersInteractions();
}

void Unit::AtExitCombat()
{
    for (auto itr = m_appliedAuras.begin(); itr != m_appliedAuras.end();)
    {
        AuraApplication* aurApp = itr->second;
        ++itr;

        aurApp->GetBase()->CallScriptEnterLeaveCombatHandlers(aurApp, false);
    }

    RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::LeavingCombat);

    if (!IsInteractionAllowedInCombat())
        UpdateNearbyPlayersInteractions();
}

void Unit::AtTargetAttacked(Unit* target, bool canInitialAggro)
{
    if (!target->IsEngaged() && !canInitialAggro)
        return;
    target->EngageWithTarget(this);
    if (Unit* targetOwner = target->GetCharmerOrOwner())
        targetOwner->EngageWithTarget(this);

    Player* myPlayerOwner = GetCharmerOrOwnerPlayerOrPlayerItself();
    Player* targetPlayerOwner = target->GetCharmerOrOwnerPlayerOrPlayerItself();
    if (myPlayerOwner && targetPlayerOwner && !(myPlayerOwner->duel && myPlayerOwner->duel->Opponent == targetPlayerOwner))
    {
        myPlayerOwner->UpdatePvP(true);
        myPlayerOwner->SetContestedPvP(targetPlayerOwner);
        myPlayerOwner->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::PvPActive);
    }
}

void Unit::UpdatePetCombatState()
{
    ASSERT(!IsPet()); // player pets do not use UNIT_FLAG_PET_IN_COMBAT for this purpose - but player pets should also never have minions of their own to call this

    bool state = false;
    for (Unit* minion : m_Controlled)
        if (minion->IsInCombat())
        {
            state = true;
            break;
        }

    if (state)
        SetUnitFlag(UNIT_FLAG_PET_IN_COMBAT);
    else
        RemoveUnitFlag(UNIT_FLAG_PET_IN_COMBAT);
}

void Unit::SetInteractionAllowedWhileHostile(bool interactionAllowed)
{
    if (interactionAllowed)
        SetUnitFlag2(UNIT_FLAG2_INTERACT_WHILE_HOSTILE);
    else
        RemoveUnitFlag2(UNIT_FLAG2_INTERACT_WHILE_HOSTILE);

    UpdateNearbyPlayersInteractions();
}

void Unit::SetInteractionAllowedInCombat(bool interactionAllowed)
{
    if (interactionAllowed)
        SetUnitFlag3(UNIT_FLAG3_ALLOW_INTERACTION_WHILE_IN_COMBAT);
    else
        RemoveUnitFlag3(UNIT_FLAG3_ALLOW_INTERACTION_WHILE_IN_COMBAT);

    if (IsInCombat())
        UpdateNearbyPlayersInteractions();
}

void Unit::UpdateNearbyPlayersInteractions()
{
    for (uint32 i = 0; i < m_unitData->NpcFlags.size(); ++i)
        if (m_unitData->NpcFlags[i])
            ForceUpdateFieldChange(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::NpcFlags, i));
}

//======================================================================

DiminishingLevels Unit::GetDiminishing(DiminishingGroup group) const
{
    DiminishingReturn const& diminish = m_Diminishing[group];
    if (!diminish.hitCount)
        return DIMINISHING_LEVEL_1;

    // If last spell was cast more than 18 seconds ago - reset level.
    if (!diminish.stack && GetMSTimeDiffToNow(diminish.hitTime) > 18 * IN_MILLISECONDS)
        return DIMINISHING_LEVEL_1;

    return DiminishingLevels(diminish.hitCount);
}

void Unit::IncrDiminishing(SpellInfo const* auraSpellInfo)
{
    DiminishingGroup group = auraSpellInfo->GetDiminishingReturnsGroupForSpell();
    uint32 currentLevel = GetDiminishing(group);
    uint32 const maxLevel = auraSpellInfo->GetDiminishingReturnsMaxLevel();

    DiminishingReturn& diminish = m_Diminishing[group];
    if (currentLevel < maxLevel)
        diminish.hitCount = currentLevel + 1;
}

bool Unit::ApplyDiminishingToDuration(SpellInfo const* auraSpellInfo, int32& duration, WorldObject* caster, DiminishingLevels previousLevel) const
{
    DiminishingGroup const group = auraSpellInfo->GetDiminishingReturnsGroupForSpell();
    if (duration == -1 || group == DIMINISHING_NONE)
        return true;

    int32 const limitDuration = auraSpellInfo->GetDiminishingReturnsLimitDuration();

    // test pet/charm masters instead pets/charmeds
    Unit const* targetOwner = GetCharmerOrOwner();
    Unit const* casterOwner = caster->GetCharmerOrOwner();

    if (limitDuration > 0 && duration > limitDuration)
    {
        Unit const* target = targetOwner ? targetOwner : this;
        WorldObject const* source = casterOwner ? casterOwner : caster;

        if (target->IsAffectedByDiminishingReturns() && source->GetTypeId() == TYPEID_PLAYER)
            duration = limitDuration;
    }

    float mod = 1.0f;
    switch (group)
    {
        case DIMINISHING_TAUNT:
        {
            if (GetTypeId() == TYPEID_UNIT && (ToCreature()->GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_OBEYS_TAUNT_DIMINISHING_RETURNS))
            {
                DiminishingLevels diminish = previousLevel;
                switch (diminish)
                {
                    case DIMINISHING_LEVEL_1: break;
                    case DIMINISHING_LEVEL_2: mod = 0.65f; break;
                    case DIMINISHING_LEVEL_3: mod = 0.4225f; break;
                    case DIMINISHING_LEVEL_4: mod = 0.274625f; break;
                    case DIMINISHING_LEVEL_TAUNT_IMMUNE: mod = 0.0f; break;
                    default: break;
                }
            }
            break;
        }
        case DIMINISHING_AOE_KNOCKBACK:
        {
            if (auraSpellInfo->GetDiminishingReturnsGroupType() == DRTYPE_ALL ||
                (auraSpellInfo->GetDiminishingReturnsGroupType() == DRTYPE_PLAYER &&
                    (targetOwner ? targetOwner->IsAffectedByDiminishingReturns() : IsAffectedByDiminishingReturns())))
            {
                DiminishingLevels diminish = previousLevel;
                switch (diminish)
                {
                    case DIMINISHING_LEVEL_1: break;
                    case DIMINISHING_LEVEL_2: mod = 0.0f; break;
                    default: break;
                }
            }
            break;
        }
        default:
        {
            if (auraSpellInfo->GetDiminishingReturnsGroupType() == DRTYPE_ALL ||
                (auraSpellInfo->GetDiminishingReturnsGroupType() == DRTYPE_PLAYER &&
                    (targetOwner ? targetOwner->IsAffectedByDiminishingReturns() : IsAffectedByDiminishingReturns())))
            {
                DiminishingLevels diminish = previousLevel;
                switch (diminish)
                {
                    case DIMINISHING_LEVEL_1: break;
                    case DIMINISHING_LEVEL_2: mod = 0.5f; break;
                    case DIMINISHING_LEVEL_3: mod = 0.25f; break;
                    case DIMINISHING_LEVEL_IMMUNE: mod = 0.0f; break;
                    default: break;
                }
            }
            break;
        }
    }

    duration = int32(duration * mod);
    return (duration != 0);
}

void Unit::ApplyDiminishingAura(DiminishingGroup group, bool apply)
{
    // Checking for existing in the table
    DiminishingReturn& diminish = m_Diminishing[group];

    if (apply)
        ++diminish.stack;
    else if (diminish.stack)
    {
        --diminish.stack;

        // Remember time after last aura from group removed
        if (!diminish.stack)
            diminish.hitTime = GameTime::GetGameTimeMS();
    }
}

void Unit::ClearDiminishings()
{
    for (DiminishingReturn& dim : m_Diminishing)
        dim.Clear();
}

uint32 Unit::GetCreatureType() const
{
    if (GetTypeId() == TYPEID_PLAYER)
    {
        ShapeshiftForm form = GetShapeshiftForm();
        SpellShapeshiftFormEntry const* ssEntry = sSpellShapeshiftFormStore.LookupEntry(form);
        if (ssEntry && ssEntry->CreatureType > 0)
            return ssEntry->CreatureType;
        else
        {
            ChrRacesEntry const* raceEntry = sChrRacesStore.AssertEntry(GetRace());
            return raceEntry->CreatureType;
        }
    }
    else
        return ToCreature()->GetCreatureTemplate()->type;
}

uint32 Unit::GetCreatureTypeMask() const
{
    uint32 creatureType = GetCreatureType();
    return (creatureType >= 1) ? (1 << (creatureType - 1)) : 0;
}

void Unit::SetShapeshiftForm(ShapeshiftForm form)
{
    SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::ShapeshiftForm), form);
}

bool Unit::IsInFeralForm() const
{
    ShapeshiftForm form = GetShapeshiftForm();
    return form == FORM_CAT_FORM || form == FORM_BEAR_FORM || form == FORM_DIRE_BEAR_FORM || form == FORM_GHOST_WOLF;
}

bool Unit::IsInDisallowedMountForm() const
{
    return IsDisallowedMountForm(GetTransformSpell(), GetShapeshiftForm(), GetDisplayId());
}

bool Unit::IsDisallowedMountForm(uint32 spellId, ShapeshiftForm form, uint32 displayId) const
{
    if (SpellInfo const* transformSpellInfo = sSpellMgr->GetSpellInfo(spellId, GetMap()->GetDifficultyID()))
        if (transformSpellInfo->HasAttribute(SPELL_ATTR0_ALLOW_WHILE_MOUNTED))
            return false;

    if (form)
    {
        SpellShapeshiftFormEntry const* shapeshift = sSpellShapeshiftFormStore.LookupEntry(form);
        if (!shapeshift)
            return true;

        if (!shapeshift->GetFlags().HasFlag(SpellShapeshiftFormFlags::Stance))
            return true;
    }

    if (displayId == GetNativeDisplayId())
        return false;

    CreatureDisplayInfoEntry const* display = sCreatureDisplayInfoStore.LookupEntry(displayId);
    if (!display)
        return true;

    CreatureDisplayInfoExtraEntry const* displayExtra = sCreatureDisplayInfoExtraStore.LookupEntry(display->ExtendedDisplayInfoID);
    if (!displayExtra)
        return true;

    CreatureModelDataEntry const* model = sCreatureModelDataStore.LookupEntry(display->ModelID);
    ChrRacesEntry const* race = sChrRacesStore.LookupEntry(displayExtra->DisplayRaceID);

    if (model && !model->GetFlags().HasFlag(CreatureModelDataFlags::CanMountWhileTransformedAsThis))
        if (race && !race->GetFlags().HasFlag(ChrRacesFlag::CanMount))
            return true;

    return false;
}

/*#######################################
########                         ########
########       STAT SYSTEM       ########
########                         ########
#######################################*/

void Unit::HandleStatFlatModifier(UnitMods unitMod, UnitModifierFlatType modifierType, float amount, bool apply)
{
    if (unitMod >= UNIT_MOD_END || modifierType >= MODIFIER_TYPE_FLAT_END)
    {
        TC_LOG_ERROR("entities.unit", "ERROR in HandleStatFlatModifier(): non-existing UnitMods or wrong UnitModifierType!");
        return;
    }

    if (!amount)
        return;

    switch (modifierType)
    {
        case BASE_VALUE:
        case BASE_PCT_EXCLUDE_CREATE:
        case TOTAL_VALUE:
            m_auraFlatModifiersGroup[unitMod][modifierType] += apply ? amount : -amount;
            break;
        default:
            break;
    }

    UpdateUnitMod(unitMod);
}

void Unit::ApplyStatPctModifier(UnitMods unitMod, UnitModifierPctType modifierType, float pct)
{
    if (unitMod >= UNIT_MOD_END || modifierType >= MODIFIER_TYPE_PCT_END)
    {
        TC_LOG_ERROR("entities.unit", "ERROR in ApplyStatPctModifier(): non-existing UnitMods or wrong UnitModifierType!");
        return;
    }

    if (!pct)
        return;

    switch (modifierType)
    {
        case BASE_PCT:
        case TOTAL_PCT:
            AddPct(m_auraPctModifiersGroup[unitMod][modifierType], pct);
            break;
        default:
            break;
    }

    UpdateUnitMod(unitMod);
}

void Unit::SetStatFlatModifier(UnitMods unitMod, UnitModifierFlatType modifierType, float val)
{
    if (m_auraFlatModifiersGroup[unitMod][modifierType] == val)
        return;

    m_auraFlatModifiersGroup[unitMod][modifierType] = val;
    UpdateUnitMod(unitMod);
}

void Unit::SetStatPctModifier(UnitMods unitMod, UnitModifierPctType modifierType, float val)
{
    if (m_auraPctModifiersGroup[unitMod][modifierType] == val)
        return;

    m_auraPctModifiersGroup[unitMod][modifierType] = val;
    UpdateUnitMod(unitMod);
}

float Unit::GetFlatModifierValue(UnitMods unitMod, UnitModifierFlatType modifierType) const
{
    if (unitMod >= UNIT_MOD_END || modifierType >= MODIFIER_TYPE_FLAT_END)
    {
        TC_LOG_ERROR("entities.unit", "attempt to access non-existing modifier value from UnitMods!");
        return 0.0f;
    }

    return m_auraFlatModifiersGroup[unitMod][modifierType];
}

float Unit::GetPctModifierValue(UnitMods unitMod, UnitModifierPctType modifierType) const
{
    if (unitMod >= UNIT_MOD_END || modifierType >= MODIFIER_TYPE_PCT_END)
    {
        TC_LOG_ERROR("entities.unit", "attempt to access non-existing modifier value from UnitMods!");
        return 0.0f;
    }

    return m_auraPctModifiersGroup[unitMod][modifierType];
}

void Unit::UpdateUnitMod(UnitMods unitMod)
{
    if (!CanModifyStats())
        return;

    switch (unitMod)
    {
        case UNIT_MOD_STAT_STRENGTH:
        case UNIT_MOD_STAT_AGILITY:
        case UNIT_MOD_STAT_STAMINA:
        case UNIT_MOD_STAT_INTELLECT:      UpdateStats(GetStatByAuraGroup(unitMod));  break;

        case UNIT_MOD_ARMOR:               UpdateArmor();           break;
        case UNIT_MOD_HEALTH:              UpdateMaxHealth();       break;

        case UNIT_MOD_MANA:
        case UNIT_MOD_RAGE:
        case UNIT_MOD_FOCUS:
        case UNIT_MOD_ENERGY:
        case UNIT_MOD_COMBO_POINTS:
        case UNIT_MOD_RUNES:
        case UNIT_MOD_RUNIC_POWER:
        case UNIT_MOD_SOUL_SHARDS:
        case UNIT_MOD_LUNAR_POWER:
        case UNIT_MOD_HOLY_POWER:
        case UNIT_MOD_ALTERNATE:
        case UNIT_MOD_MAELSTROM:
        case UNIT_MOD_CHI:
        case UNIT_MOD_INSANITY:
        case UNIT_MOD_BURNING_EMBERS:
        case UNIT_MOD_DEMONIC_FURY:
        case UNIT_MOD_ARCANE_CHARGES:
        case UNIT_MOD_FURY:
        case UNIT_MOD_PAIN:
        case UNIT_MOD_ESSENCE:
        case UNIT_MOD_RUNE_BLOOD:
        case UNIT_MOD_RUNE_FROST:
        case UNIT_MOD_RUNE_UNHOLY:
        case UNIT_MOD_ALTERNATE_QUEST:
        case UNIT_MOD_ALTERNATE_ENCOUNTER:
        case UNIT_MOD_ALTERNATE_MOUNT:     UpdateMaxPower(Powers(unitMod - UNIT_MOD_POWER_START));     break;

        case UNIT_MOD_RESISTANCE_HOLY:
        case UNIT_MOD_RESISTANCE_FIRE:
        case UNIT_MOD_RESISTANCE_NATURE:
        case UNIT_MOD_RESISTANCE_FROST:
        case UNIT_MOD_RESISTANCE_SHADOW:
        case UNIT_MOD_RESISTANCE_ARCANE:   UpdateResistances(GetSpellSchoolByAuraGroup(unitMod));      break;

        case UNIT_MOD_ATTACK_POWER:        UpdateAttackPowerAndDamage();         break;
        case UNIT_MOD_ATTACK_POWER_RANGED: UpdateAttackPowerAndDamage(true);     break;

        case UNIT_MOD_DAMAGE_MAINHAND:     UpdateDamagePhysical(BASE_ATTACK);    break;
        case UNIT_MOD_DAMAGE_OFFHAND:      UpdateDamagePhysical(OFF_ATTACK);     break;
        case UNIT_MOD_DAMAGE_RANGED:       UpdateDamagePhysical(RANGED_ATTACK);  break;

        default:
            ABORT_MSG("Not implemented UnitMod %u", unitMod);
            break;
    }
}

void Unit::UpdateDamageDoneMods(WeaponAttackType attackType, int32 /*skipEnchantSlot = -1*/)
{
    UnitMods unitMod;
    switch (attackType)
    {
        case BASE_ATTACK:
            unitMod = UNIT_MOD_DAMAGE_MAINHAND;
            break;
        case OFF_ATTACK:
            unitMod = UNIT_MOD_DAMAGE_OFFHAND;
            break;
        case RANGED_ATTACK:
            unitMod = UNIT_MOD_DAMAGE_RANGED;
            break;
        default:
            ABORT();
            break;
    }

    float amount = GetTotalAuraModifier(SPELL_AURA_MOD_DAMAGE_DONE, [&](AuraEffect const* aurEff) -> bool
    {
        if (!(aurEff->GetMiscValue() & SPELL_SCHOOL_MASK_NORMAL))
            return false;

        return CheckAttackFitToAuraRequirement(attackType, aurEff);
    });

    SetStatFlatModifier(unitMod, TOTAL_VALUE, amount);
}

void Unit::UpdateAllDamageDoneMods()
{
    for (uint8 i = BASE_ATTACK; i < MAX_ATTACK; ++i)
        UpdateDamageDoneMods(WeaponAttackType(i));
}

void Unit::UpdateDamagePctDoneMods(WeaponAttackType attackType)
{
    float factor;
    UnitMods unitMod;
    switch (attackType)
    {
    case BASE_ATTACK:
        factor = 1.0f;
        unitMod = UNIT_MOD_DAMAGE_MAINHAND;
        break;
    case OFF_ATTACK:
        // off hand has 50% penalty
        factor = 0.5f;
        unitMod = UNIT_MOD_DAMAGE_OFFHAND;
        break;
    case RANGED_ATTACK:
        factor = 1.0f;
        unitMod = UNIT_MOD_DAMAGE_RANGED;
        break;
    default:
        ABORT();
        break;
    }

    factor *= GetTotalAuraMultiplier(SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, [attackType, this](AuraEffect const* aurEff) -> bool
    {
        if (!(aurEff->GetMiscValue() & SPELL_SCHOOL_MASK_NORMAL))
            return false;

        return CheckAttackFitToAuraRequirement(attackType, aurEff);
    });

    if (attackType == OFF_ATTACK)
        factor *= GetTotalAuraModifier(SPELL_AURA_MOD_OFFHAND_DAMAGE_PCT, [this, attackType](AuraEffect const* aurEff)
        {
            return CheckAttackFitToAuraRequirement(attackType, aurEff);
        });

    SetStatPctModifier(unitMod, TOTAL_PCT, factor);
}

void Unit::UpdateAllDamagePctDoneMods()
{
    for (uint8 i = BASE_ATTACK; i < MAX_ATTACK; ++i)
        UpdateDamagePctDoneMods(WeaponAttackType(i));
}

float Unit::GetTotalStatValue(Stats stat) const
{
    UnitMods unitMod = UnitMods(UNIT_MOD_STAT_START + AsUnderlyingType(stat));

    // value = ((base_value * base_pct) + total_value) * total_pct
    float value = CalculatePct(GetFlatModifierValue(unitMod, BASE_VALUE), std::max(GetFlatModifierValue(unitMod, BASE_PCT_EXCLUDE_CREATE), -100.0f));
    value += GetCreateStat(stat);
    value *= GetPctModifierValue(unitMod, BASE_PCT);
    value += GetFlatModifierValue(unitMod, TOTAL_VALUE);
    value *= GetPctModifierValue(unitMod, TOTAL_PCT);

    return value;
}

float Unit::GetTotalAuraModValue(UnitMods unitMod) const
{
    if (unitMod >= UNIT_MOD_END)
    {
        TC_LOG_ERROR("entities.unit", "attempt to access non-existing UnitMods in GetTotalAuraModValue()!");
        return 0.0f;
    }

    float value = CalculatePct(GetFlatModifierValue(unitMod, BASE_VALUE), std::max(GetFlatModifierValue(unitMod, BASE_PCT_EXCLUDE_CREATE), -100.0f));
    value *= GetPctModifierValue(unitMod, BASE_PCT);
    value += GetFlatModifierValue(unitMod, TOTAL_VALUE);
    value *= GetPctModifierValue(unitMod, TOTAL_PCT);

    return value;
}

SpellSchools Unit::GetSpellSchoolByAuraGroup(UnitMods unitMod) const
{
    SpellSchools school = SPELL_SCHOOL_NORMAL;

    switch (unitMod)
    {
        case UNIT_MOD_RESISTANCE_HOLY:     school = SPELL_SCHOOL_HOLY;          break;
        case UNIT_MOD_RESISTANCE_FIRE:     school = SPELL_SCHOOL_FIRE;          break;
        case UNIT_MOD_RESISTANCE_NATURE:   school = SPELL_SCHOOL_NATURE;        break;
        case UNIT_MOD_RESISTANCE_FROST:    school = SPELL_SCHOOL_FROST;         break;
        case UNIT_MOD_RESISTANCE_SHADOW:   school = SPELL_SCHOOL_SHADOW;        break;
        case UNIT_MOD_RESISTANCE_ARCANE:   school = SPELL_SCHOOL_ARCANE;        break;

        default:
            break;
    }

    return school;
}

Stats Unit::GetStatByAuraGroup(UnitMods unitMod) const
{
    Stats stat = STAT_STRENGTH;

    switch (unitMod)
    {
        case UNIT_MOD_STAT_STRENGTH:    stat = STAT_STRENGTH;      break;
        case UNIT_MOD_STAT_AGILITY:     stat = STAT_AGILITY;       break;
        case UNIT_MOD_STAT_STAMINA:     stat = STAT_STAMINA;       break;
        case UNIT_MOD_STAT_INTELLECT:   stat = STAT_INTELLECT;     break;
        default:
            break;
    }

    return stat;
}

void Unit::UpdateResistances(uint32 school)
{
    if (school > SPELL_SCHOOL_NORMAL)
    {
        UnitMods unitMod = UnitMods(UNIT_MOD_RESISTANCE_START + school);

        float value = CalculatePct(GetFlatModifierValue(unitMod, BASE_VALUE), std::max(GetFlatModifierValue(unitMod, BASE_PCT_EXCLUDE_CREATE), -100.0f));
        value *= GetPctModifierValue(unitMod, BASE_PCT);

        float baseValue = value;

        value += GetFlatModifierValue(unitMod, TOTAL_VALUE);
        value *= GetPctModifierValue(unitMod, TOTAL_PCT);

        SetResistance(SpellSchools(school), int32(value));
        SetBonusResistanceMod(SpellSchools(school), int32(value - baseValue));
    }
    else
        UpdateArmor();
}

float Unit::GetTotalAttackPowerValue(WeaponAttackType attType, bool includeWeapon /*= true*/) const
{
    if (attType == RANGED_ATTACK)
    {
        float ap = m_unitData->RangedAttackPower + m_unitData->RangedAttackPowerModPos + m_unitData->RangedAttackPowerModNeg;
        if (includeWeapon)
            ap += std::max<float>(m_unitData->MainHandWeaponAttackPower, m_unitData->RangedWeaponAttackPower);
        if (ap < 0)
            return 0.0f;
        return ap * (1.0f + m_unitData->RangedAttackPowerMultiplier);
    }
    else
    {
        float ap = m_unitData->AttackPower + m_unitData->AttackPowerModPos + m_unitData->AttackPowerModNeg;
        if (includeWeapon)
        {
            if (attType == BASE_ATTACK)
                ap += std::max<float>(m_unitData->MainHandWeaponAttackPower, m_unitData->RangedWeaponAttackPower);
            else
            {
                ap += m_unitData->OffHandWeaponAttackPower;
                ap /= 2;
            }
        }
        if (ap < 0)
            return 0.0f;
        return ap * (1.0f + m_unitData->AttackPowerMultiplier);
    }
}

float Unit::GetWeaponDamageRange(WeaponAttackType attType, WeaponDamageRange type) const
{
    if (attType == OFF_ATTACK && !haveOffhandWeapon())
        return 0.0f;

    return m_weaponDamage[attType][type];
}

bool Unit::CanFreeMove() const
{
    return !HasUnitState(UNIT_STATE_CONFUSED | UNIT_STATE_FLEEING | UNIT_STATE_IN_FLIGHT |
        UNIT_STATE_ROOT | UNIT_STATE_STUNNED | UNIT_STATE_DISTRACTED) && GetOwnerGUID().IsEmpty();
}

void Unit::SetLevel(uint8 lvl, bool sendUpdate/* = true*/)
{
    SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::Level), lvl);

    if (!sendUpdate)
        return;

    if (Player* player = ToPlayer())
    {
        // group update
        if (player->GetGroup())
            player->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_LEVEL);

        sCharacterCache->UpdateCharacterLevel(GetGUID(), lvl);
    }
}

void Unit::SetHealth(uint64 val)
{
    if (getDeathState() == JUST_DIED || getDeathState() == CORPSE)
        val = 0;
    else if (GetTypeId() == TYPEID_PLAYER && getDeathState() == DEAD)
        val = 1;
    else
    {
        uint64 maxHealth = GetMaxHealth();
        if (maxHealth < val)
            val = maxHealth;
    }

    uint64 oldVal = GetHealth();
    SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::Health), val);

    TriggerOnHealthChangeAuras(oldVal, val);

    // group update
    if (Player* player = ToPlayer())
    {
        if (player->GetGroup())
            player->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_CUR_HP);
    }
    else if (Pet* pet = ToCreature()->ToPet())
    {
        if (pet->isControlled())
            pet->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_PET_CUR_HP);
    }
}

void Unit::SetMaxHealth(uint64 val)
{
    if (!val)
        val = 1;

    uint64 health = GetHealth();
    SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::MaxHealth), val);

    // group update
    if (GetTypeId() == TYPEID_PLAYER)
    {
        if (ToPlayer()->GetGroup())
            ToPlayer()->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_MAX_HP);
    }
    else if (Pet* pet = ToCreature()->ToPet())
    {
        if (pet->isControlled())
            pet->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_PET_MAX_HP);
    }

    if (val < health)
        SetHealth(val);
}

int32 Unit::GetPower(Powers power) const
{
    uint32 powerIndex = GetPowerIndex(power);
    if (powerIndex == MAX_POWERS || powerIndex >= MAX_POWERS_PER_CLASS)
        return 0;

    return m_unitData->Power[powerIndex];
}

int32 Unit::GetMaxPower(Powers power) const
{
    uint32 powerIndex = GetPowerIndex(power);
    if (powerIndex == MAX_POWERS || powerIndex >= MAX_POWERS_PER_CLASS)
        return 0;

    return m_unitData->MaxPower[powerIndex];
}

void Unit::SetPower(Powers power, int32 val, bool withPowerUpdate /*= true*/)
{
    uint32 powerIndex = GetPowerIndex(power);
    if (powerIndex == MAX_POWERS || powerIndex >= MAX_POWERS_PER_CLASS)
        return;

    int32 maxPower = GetMaxPower(power);
    if (maxPower < val)
        val = maxPower;

    int32 oldPower = m_unitData->Power[powerIndex];
    SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::Power, powerIndex), val);

    if (IsInWorld() && withPowerUpdate)
    {
        WorldPackets::Combat::PowerUpdate packet;
        packet.Guid = GetGUID();
        /// @todo: Support multiple counts ?
        packet.Powers.emplace_back(val, power);
        SendMessageToSet(packet.Write(), GetTypeId() == TYPEID_PLAYER);
    }

    TriggerOnPowerChangeAuras(power, oldPower, val);

    // group update
    if (Player* player = ToPlayer())
    {
        if (player->GetGroup())
            player->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_CUR_POWER);
    }
    /*else if (Pet* pet = ToCreature()->ToPet()) TODO 6.x
    {
        if (pet->isControlled())
            pet->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_PET_CUR_POWER);
    }*/
}

void Unit::SetMaxPower(Powers power, int32 val)
{
    uint32 powerIndex = GetPowerIndex(power);
    if (powerIndex == MAX_POWERS || powerIndex >= MAX_POWERS_PER_CLASS)
        return;

    int32 cur_power = GetPower(power);
    SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::MaxPower, powerIndex), val);

    // group update
    if (GetTypeId() == TYPEID_PLAYER)
    {
        if (ToPlayer()->GetGroup())
            ToPlayer()->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_MAX_POWER);
    }
    /*else if (Pet* pet = ToCreature()->ToPet()) TODO 6.x
    {
        if (pet->isControlled())
            pet->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_PET_MAX_POWER);
    }*/

    if (val < cur_power)
        SetPower(power, val);
}

void Unit::TriggerOnPowerChangeAuras(Powers power, int32 oldVal, int32 newVal)
{
    auto processAuras = [&](AuraEffectVector const& effects)
    {
        for (AuraEffect const* effect : effects)
        {
            if (effect->GetMiscValue() == power)
            {
                uint32 effectAmount = effect->GetAmount();
                uint32 triggerSpell = effect->GetSpellEffectInfo().TriggerSpell;

                float oldValueCheck = oldVal;
                float newValueCheck = newVal;

                if (effect->GetAuraType() == SPELL_AURA_TRIGGER_SPELL_ON_POWER_PCT)
                {
                    int32 maxPower = GetMaxPower(power);
                    oldValueCheck = GetPctOf(oldVal, maxPower);
                    newValueCheck = GetPctOf(newVal, maxPower);
                }

                switch (AuraTriggerOnPowerChangeDirection(effect->GetMiscValueB()))
                {
                    case AuraTriggerOnPowerChangeDirection::Gain:
                        if (oldValueCheck >= effect->GetAmount() || newValueCheck < effectAmount)
                            continue;
                        break;
                    case AuraTriggerOnPowerChangeDirection::Loss:
                        if (oldValueCheck <= effect->GetAmount() || newValueCheck > effectAmount)
                            continue;
                        break;
                    default:
                        break;
                }

                CastSpell(this, triggerSpell, effect);
            }
        }
    };

    processAuras(CopyAuraEffectList(GetAuraEffectsByType(SPELL_AURA_TRIGGER_SPELL_ON_POWER_PCT)));
    processAuras(CopyAuraEffectList(GetAuraEffectsByType(SPELL_AURA_TRIGGER_SPELL_ON_POWER_AMOUNT)));
}

void Unit::AIUpdateTick(uint32 diff)
{
    if (UnitAI* ai = GetAI())
    {
        m_aiLocked = true;
        ai->UpdateAI(diff);
        m_aiLocked = false;
    }
}

void Unit::PushAI(UnitAI* newAI)
{
    i_AIs.emplace(newAI);
}

void Unit::SetAI(UnitAI* newAI)
{
    PushAI(newAI);
    RefreshAI();
}

bool Unit::PopAI()
{
    if (!i_AIs.empty())
    {
        i_AIs.pop();
        return true;
    }
    else
        return false;
}

void Unit::RefreshAI()
{
    ASSERT(!m_aiLocked, "Tried to change current AI during UpdateAI()");
    if (i_AIs.empty())
        i_AI = nullptr;
    else
        i_AI = i_AIs.top();
}

void Unit::ScheduleAIChange()
{
    bool const charmed = IsCharmed();

    if (charmed)
        PushAI(GetScheduledChangeAI());
    else
    {
        RestoreDisabledAI();
        PushAI(GetScheduledChangeAI()); //This could actually be PopAI() to get the previous AI but it's required atm to trigger UpdateCharmAI()
    }
}

void Unit::RestoreDisabledAI()
{
    // Keep popping the stack until we either reach the bottom or find a valid AI
    while (PopAI())
        if (GetTopAI() && dynamic_cast<ScheduledChangeAI*>(GetTopAI()) == nullptr)
            return;
}

UnitAI* Unit::GetScheduledChangeAI()
{
    if (Creature* creature = ToCreature())
        return sCreatureAIRegistry->GetRegistryItem("ScheduledChangeAI")->Create(creature);
    else
        return nullptr;
}

bool Unit::HasScheduledAIChange() const
{
    if (UnitAI* ai = GetAI())
        return dynamic_cast<ScheduledChangeAI*>(ai) != nullptr;
    else
        return true;
}

void Unit::AddToWorld()
{
    WorldObject::AddToWorld();
    i_motionMaster->AddToWorld();

    RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::EnterWorld);
}

void Unit::RemoveFromWorld()
{
    // cleanup
    ASSERT(GetGUID());

    if (IsInWorld())
    {
        if (IsAreaSpiritHealer())
        {
            if (Creature* creature = ToCreature())
                creature->SummonGraveyardTeleporter();
        }

        m_duringRemoveFromWorld = true;
        if (UnitAI* ai = GetAI())
            ai->OnDespawn();

        if (IsVehicle())
            RemoveVehicleKit(true);

        RemoveCharmAuras();
        RemoveBindSightAuras();
        RemoveNotOwnSingleTargetAuras();
        RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::LeaveWorld);

        RemoveAllGameObjects();
        RemoveAllDynObjects();
        RemoveAllAreaTriggers();

        ExitVehicle();  // Remove applied auras with SPELL_AURA_CONTROL_VEHICLE
        UnsummonAllTotems();
        RemoveAllControlled();

        RemoveAreaAurasDueToLeaveWorld();

        RemoveAllFollowers();

        if (IsCharmed())
            RemoveCharmedBy(nullptr);

        ASSERT(!GetCharmedGUID(), "Unit %u has charmed guid when removed from world", GetEntry());
        ASSERT(!GetCharmerGUID(), "Unit %u has charmer guid when removed from world", GetEntry());

        if (Unit* owner = GetOwner())
        {
            if (owner->m_Controlled.find(this) != owner->m_Controlled.end())
            {
                TC_LOG_FATAL("entities.unit", "Unit {} is in controlled list of {} when removed from world", GetEntry(), owner->GetEntry());
                ABORT();
            }
        }

        WorldObject::RemoveFromWorld();
        m_duringRemoveFromWorld = false;
    }
}

void Unit::CleanupBeforeRemoveFromMap(bool finalCleanup)
{
    // This needs to be before RemoveFromWorld to make GetCaster() return a valid pointer on aura removal
    InterruptNonMeleeSpells(true);

    SetVignette(0);

    if (IsInWorld())
        RemoveFromWorld();
    else
    {
        // cleanup that must happen even if not in world
        if (IsVehicle())
            RemoveVehicleKit(true);
    }

    ASSERT(GetGUID());

    // A unit may be in removelist and not in world, but it is still in grid
    // and may have some references during delete
    RemoveAllAuras();
    RemoveAllGameObjects();

    if (finalCleanup)
        m_cleanupDone = true;

    CombatStop();
}

void Unit::CleanupsBeforeDelete(bool finalCleanup)
{
    CleanupBeforeRemoveFromMap(finalCleanup);

    WorldObject::CleanupsBeforeDelete(finalCleanup);
}

void Unit::UpdateCharmAI()
{
    if (IsCharmed())
    {
        UnitAI* newAI = nullptr;
        if (GetTypeId() == TYPEID_PLAYER)
        {
            if (Unit* charmer = GetCharmer())
            {
                // first, we check if the creature's own AI specifies an override playerai for its owned players
                if (Creature* creatureCharmer = charmer->ToCreature())
                {
                    if (CreatureAI* charmerAI = creatureCharmer->AI())
                        newAI = charmerAI->GetAIForCharmedPlayer(ToPlayer());
                }
                else
                    TC_LOG_ERROR("entities.unit.ai", "Attempt to assign charm AI to player {} who is charmed by non-creature {}.", GetGUID().ToString(), GetCharmerGUID().ToString());
            }
            if (!newAI) // otherwise, we default to the generic one
                newAI = new SimpleCharmedPlayerAI(ToPlayer());
        }
        else
        {
            ASSERT(GetTypeId() == TYPEID_UNIT);
            if (isPossessed() || IsVehicle())
                newAI = ASSERT_NOTNULL(sCreatureAIRegistry->GetRegistryItem("PossessedAI"))->Create(ToCreature());
            else
                newAI = ASSERT_NOTNULL(sCreatureAIRegistry->GetRegistryItem("PetAI"))->Create(ToCreature());
        }

        ASSERT(newAI);
        SetAI(newAI);
        newAI->OnCharmed(true);
    }
    else
    {
        RestoreDisabledAI();
        // Hack: this is required because we want to call OnCharmed(true) on the restored AI
        RefreshAI();
        if (UnitAI* ai = GetAI())
            ai->OnCharmed(true);
    }
}

CharmInfo* Unit::InitCharmInfo()
{
    if (!m_charmInfo)
        m_charmInfo = std::make_unique<CharmInfo>(this);

    return m_charmInfo.get();
}

void Unit::DeleteCharmInfo()
{
    if (!m_charmInfo)
        return;

    m_charmInfo->RestoreState();
    m_charmInfo = nullptr;
}

void Unit::SetMovedUnit(Unit* target)
{
    m_unitMovedByMe->m_playerMovingMe = nullptr;
    m_unitMovedByMe = ASSERT_NOTNULL(target);
    m_unitMovedByMe->m_playerMovingMe = ASSERT_NOTNULL(ToPlayer());

    WorldPackets::Movement::MoveSetActiveMover packet;
    packet.MoverGUID = target->GetGUID();
    ToPlayer()->SendDirectMessage(packet.Write());
}

ProcFlagsHit createProcHitMask(SpellNonMeleeDamage* damageInfo, SpellMissInfo missCondition)
{
    ProcFlagsHit hitMask = PROC_HIT_NONE;
    // Check victim state
    if (missCondition != SPELL_MISS_NONE)
    {
        switch (missCondition)
        {
            case SPELL_MISS_MISS:
                hitMask |= PROC_HIT_MISS;
                break;
            case SPELL_MISS_DODGE:
                hitMask |= PROC_HIT_DODGE;
                break;
            case SPELL_MISS_PARRY:
                hitMask |= PROC_HIT_PARRY;
                break;
            case SPELL_MISS_BLOCK:
                // spells can't be partially blocked (it's damage can though)
                hitMask |= PROC_HIT_BLOCK | PROC_HIT_FULL_BLOCK;
                break;
            case SPELL_MISS_EVADE:
                hitMask |= PROC_HIT_EVADE;
                break;
            case SPELL_MISS_IMMUNE:
            case SPELL_MISS_IMMUNE2:
                hitMask |= PROC_HIT_IMMUNE;
                break;
            case SPELL_MISS_DEFLECT:
                hitMask |= PROC_HIT_DEFLECT;
                break;
            case SPELL_MISS_ABSORB:
                hitMask |= PROC_HIT_ABSORB;
                break;
            case SPELL_MISS_REFLECT:
                hitMask |= PROC_HIT_REFLECT;
                break;
            case SPELL_MISS_RESIST:
                hitMask |= PROC_HIT_FULL_RESIST;
                break;
            default:
                break;
        }
    }
    else
    {
        // On block
        if (damageInfo->blocked)
        {
            hitMask |= PROC_HIT_BLOCK;
            if (damageInfo->fullBlock)
                hitMask |= PROC_HIT_FULL_BLOCK;
        }
        // On absorb
        if (damageInfo->absorb)
            hitMask |= PROC_HIT_ABSORB;

        // Don't set hit/crit hitMask if damage is nullified
        bool const damageNullified = (damageInfo->HitInfo & (HITINFO_FULL_ABSORB | HITINFO_FULL_RESIST)) != 0 || (hitMask & PROC_HIT_FULL_BLOCK) != 0;
        if (!damageNullified)
        {
            // On crit
            if (damageInfo->HitInfo & SPELL_HIT_TYPE_CRIT)
                hitMask |= PROC_HIT_CRITICAL;
            else
                hitMask |= PROC_HIT_NORMAL;
        }
        else if ((damageInfo->HitInfo & HITINFO_FULL_RESIST) != 0)
            hitMask |= PROC_HIT_FULL_RESIST;
    }

    return hitMask;
}

void Unit::ProcSkillsAndReactives(bool isVictim, Unit* procTarget, ProcFlagsInit const& typeMask, ProcFlagsHit hitMask, WeaponAttackType /*attType*/)
{
    // Player is loaded now - do not allow passive spell casts to proc
    if (GetTypeId() == TYPEID_PLAYER && ToPlayer()->GetSession()->PlayerLoading())
        return;

    // For melee/ranged based attack need update skills and set some Aura states if victim present
    if (typeMask & MELEE_BASED_TRIGGER_MASK && procTarget)
    {
        // If exist crit/parry/dodge/block need update aura state (for victim and attacker)
        if (hitMask & (PROC_HIT_CRITICAL | PROC_HIT_PARRY | PROC_HIT_DODGE | PROC_HIT_BLOCK))
        {
            // for victim
            if (isVictim)
            {
                // if victim and dodge attack
                if (hitMask & PROC_HIT_DODGE)
                {
                    // Update AURA_STATE on dodge
                    if (GetClass() != CLASS_ROGUE) // skip Rogue Riposte
                    {
                        ModifyAuraState(AURA_STATE_DEFENSIVE, true);
                        StartReactiveTimer(REACTIVE_DEFENSE);
                    }
                }
                // if victim and parry attack
                if (hitMask & PROC_HIT_PARRY)
                {
                    ModifyAuraState(AURA_STATE_DEFENSIVE, true);
                    StartReactiveTimer(REACTIVE_DEFENSE);
                }
                // if and victim block attack
                if (hitMask & PROC_HIT_BLOCK)
                {
                    ModifyAuraState(AURA_STATE_DEFENSIVE, true);
                    StartReactiveTimer(REACTIVE_DEFENSE);
                }
            }
        }
    }
}

void Unit::GetProcAurasTriggeredOnEvent(AuraApplicationProcContainer& aurasTriggeringProc, AuraApplicationList* procAuras, ProcEventInfo& eventInfo)
{
    TimePoint now = GameTime::Now();

    auto processAuraApplication = [&](AuraApplication* aurApp)
    {
        if (uint32 procEffectMask = aurApp->GetBase()->GetProcEffectMask(aurApp, eventInfo, now))
        {
            aurApp->GetBase()->PrepareProcToTrigger(aurApp, eventInfo, now);
            aurasTriggeringProc.emplace_back(procEffectMask, aurApp);
        }
        else
        {
            if (aurApp->GetBase()->GetSpellInfo()->HasAttribute(SPELL_ATTR0_PROC_FAILURE_BURNS_CHARGE))
            {
                if (SpellProcEntry const* procEntry = sSpellMgr->GetSpellProcEntry(aurApp->GetBase()->GetSpellInfo()))
                {
                    aurApp->GetBase()->PrepareProcChargeDrop(procEntry, eventInfo);
                    aurasTriggeringProc.emplace_back(0, aurApp);
                }
            }

            if (aurApp->GetBase()->GetSpellInfo()->HasAttribute(SPELL_ATTR2_PROC_COOLDOWN_ON_FAILURE))
                if (SpellProcEntry const* procEntry = sSpellMgr->GetSpellProcEntry(aurApp->GetBase()->GetSpellInfo()))
                    aurApp->GetBase()->AddProcCooldown(procEntry, now);
        }
    };

    // use provided list of auras which can proc
    if (procAuras)
    {
        for (AuraApplication* aurApp : *procAuras)
        {
            ASSERT(aurApp->GetTarget() == this);
            processAuraApplication(aurApp);
        }
    }
    // or generate one on our own
    else
    {
        for (AuraApplicationMap::iterator itr = GetAppliedAuras().begin(); itr != GetAppliedAuras().end(); ++itr)
            processAuraApplication(itr->second);
    }
}

void Unit::TriggerAurasProcOnEvent(AuraApplicationList* myProcAuras, AuraApplicationList* targetProcAuras, Unit* actionTarget,
                                   ProcFlagsInit const& typeMaskActor, ProcFlagsInit const& typeMaskActionTarget, ProcFlagsSpellType spellTypeMask,
                                   ProcFlagsSpellPhase spellPhaseMask, ProcFlagsHit hitMask, Spell* spell, DamageInfo* damageInfo, HealInfo* healInfo)
{
    // prepare data for self trigger
    ProcEventInfo myProcEventInfo(this, actionTarget, actionTarget, typeMaskActor, spellTypeMask, spellPhaseMask, hitMask, spell, damageInfo, healInfo);
    AuraApplicationProcContainer myAurasTriggeringProc;
    if (typeMaskActor)
    {
        GetProcAurasTriggeredOnEvent(myAurasTriggeringProc, myProcAuras, myProcEventInfo);

        // needed for example for Cobra Strikes, pet does the attack, but aura is on owner
        if (Player* modOwner = GetSpellModOwner())
        {
            if (modOwner != this && spell)
            {
                AuraApplicationList modAuras;
                for (auto itr = modOwner->GetAppliedAuras().begin(); itr != modOwner->GetAppliedAuras().end(); ++itr)
                {
                    if (spell->m_appliedMods.count(itr->second->GetBase()) != 0)
                        modAuras.push_front(itr->second);
                }
                modOwner->GetProcAurasTriggeredOnEvent(myAurasTriggeringProc, &modAuras, myProcEventInfo);
            }
        }
    }

    // prepare data for target trigger
    ProcEventInfo targetProcEventInfo(this, actionTarget, this, typeMaskActionTarget, spellTypeMask, spellPhaseMask, hitMask, spell, damageInfo, healInfo);
    AuraApplicationProcContainer targetAurasTriggeringProc;
    if (typeMaskActionTarget && actionTarget)
        actionTarget->GetProcAurasTriggeredOnEvent(targetAurasTriggeringProc, targetProcAuras, targetProcEventInfo);

    TriggerAurasProcOnEvent(myProcEventInfo, myAurasTriggeringProc);

    if (typeMaskActionTarget && actionTarget)
        actionTarget->TriggerAurasProcOnEvent(targetProcEventInfo, targetAurasTriggeringProc);
}

void Unit::TriggerAurasProcOnEvent(ProcEventInfo& eventInfo, AuraApplicationProcContainer& aurasTriggeringProc)
{
    Spell const* triggeringSpell = eventInfo.GetProcSpell();
    bool const disableProcs = triggeringSpell && triggeringSpell->IsProcDisabled();

    int32 oldProcChainLength = std::exchange(m_procChainLength, std::max(m_procChainLength + 1, triggeringSpell ? triggeringSpell->GetProcChainLength() : 0));

    if (disableProcs)
        SetCantProc(true);

    for (auto const& [procEffectMask, aurApp] : aurasTriggeringProc)
    {
        if (aurApp->GetRemoveMode())
            continue;

        aurApp->GetBase()->TriggerProcOnEvent(procEffectMask, aurApp, eventInfo);
    }

    if (disableProcs)
        SetCantProc(false);

    m_procChainLength = oldProcChainLength;
}

///----------Pet responses methods-----------------
void Unit::SendPetActionFeedback(PetActionFeedback msg, uint32 spellId)
{
    Unit* owner = GetOwner();
    if (!owner || owner->GetTypeId() != TYPEID_PLAYER)
        return;

    WorldPackets::Pet::PetActionFeedback petActionFeedback;
    petActionFeedback.SpellID = spellId;
    petActionFeedback.Response = msg;
    owner->ToPlayer()->SendDirectMessage(petActionFeedback.Write());
}

void Unit::SendPetTalk(uint32 pettalk)
{
    Unit* owner = GetOwner();
    if (!owner || owner->GetTypeId() != TYPEID_PLAYER)
        return;

    WorldPackets::Pet::PetActionSound petActionSound;
    petActionSound.UnitGUID = GetGUID();
    petActionSound.Action = pettalk;
    owner->ToPlayer()->SendDirectMessage(petActionSound.Write());
}

void Unit::SendPetAIReaction(ObjectGuid guid)
{
    Unit* owner = GetOwner();
    if (!owner || owner->GetTypeId() != TYPEID_PLAYER)
        return;

    WorldPackets::Combat::AIReaction packet;
    packet.UnitGUID = guid;
    packet.Reaction = AI_REACTION_HOSTILE;
    owner->ToPlayer()->SendDirectMessage(packet.Write());
}

///----------End of Pet responses methods----------

void Unit::PropagateSpeedChange()
{
    GetMotionMaster()->PropagateSpeedChange();
}

MovementGeneratorType Unit::GetDefaultMovementType() const
{
    return IDLE_MOTION_TYPE;
}

void Unit::StopMoving()
{
    ClearUnitState(UNIT_STATE_MOVING);

    // not need send any packets if not in world or not moving
    if (!IsInWorld() || movespline->Finalized())
        return;

    // Update position now since Stop does not start a new movement that can be updated later
    if (movespline->HasStarted())
        UpdateSplinePosition();
    Movement::MoveSplineInit init(this);
    init.Stop();
}

void Unit::PauseMovement(uint32 timer/* = 0*/, uint8 slot/* = 0*/, bool forced/* = true*/)
{
    if (IsInvalidMovementSlot(slot))
        return;

    if (MovementGenerator* movementGenerator = GetMotionMaster()->GetCurrentMovementGenerator(MovementSlot(slot)))
        movementGenerator->Pause(timer);

    if (forced && GetMotionMaster()->GetCurrentSlot() == MovementSlot(slot))
        StopMoving();
}

void Unit::ResumeMovement(uint32 timer/* = 0*/, uint8 slot/* = 0*/)
{
    if (IsInvalidMovementSlot(slot))
        return;

    if (MovementGenerator* movementGenerator = GetMotionMaster()->GetCurrentMovementGenerator(MovementSlot(slot)))
        movementGenerator->Resume(timer);
}

bool Unit::IsSitState() const
{
    UnitStandStateType s = GetStandState();
    return
        s == UNIT_STAND_STATE_SIT_CHAIR        || s == UNIT_STAND_STATE_SIT_LOW_CHAIR  ||
        s == UNIT_STAND_STATE_SIT_MEDIUM_CHAIR || s == UNIT_STAND_STATE_SIT_HIGH_CHAIR ||
        s == UNIT_STAND_STATE_SIT;
}

bool Unit::IsStandState() const
{
    UnitStandStateType s = GetStandState();
    return !IsSitState() && s != UNIT_STAND_STATE_SLEEP && s != UNIT_STAND_STATE_KNEEL;
}

void Unit::SetStandState(UnitStandStateType state, uint32 animKitID /* = 0*/)
{
    SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::StandState), state);

    if (IsStandState())
       RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::Standing);

    if (GetTypeId() == TYPEID_PLAYER)
    {
        WorldPackets::Misc::StandStateUpdate packet(state, animKitID);
        ToPlayer()->SendDirectMessage(packet.Write());
    }
}

void Unit::SetAnimTier(AnimTier animTier, bool notifyClient /*= true*/)
{
    SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::AnimTier), AsUnderlyingType(animTier));

    if (notifyClient)
    {
        WorldPackets::Misc::SetAnimTier setAnimTier;
        setAnimTier.Unit = GetGUID();
        setAnimTier.Tier = AsUnderlyingType(animTier);
        SendMessageToSet(setAnimTier.Write(), true);
    }
}

bool Unit::IsPolymorphed() const
{
    uint32 transformId = GetTransformSpell();
    if (!transformId)
        return false;

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(transformId, GetMap()->GetDifficultyID());
    if (!spellInfo)
        return false;

    return spellInfo->GetSpellSpecific() == SPELL_SPECIFIC_MAGE_POLYMORPH;
}

void Unit::RecalculateObjectScale()
{
    int32 scaleAuras = GetTotalAuraModifier(SPELL_AURA_MOD_SCALE) + GetTotalAuraModifier(SPELL_AURA_MOD_SCALE_2);
    float scale = GetNativeObjectScale() + CalculatePct(1.0f, scaleAuras);
    float scaleMin = GetTypeId() == TYPEID_PLAYER ? 0.1 : 0.01;
    SetObjectScale(std::max(scale, scaleMin));
}

void Unit::SetDisplayId(uint32 displayId, bool setNative /*= false*/)
{
    float displayScale = DEFAULT_PLAYER_DISPLAY_SCALE;

    if (IsCreature() && !IsPet())
        if (CreatureModel const* model = ToCreature()->GetCreatureTemplate()->GetModelWithDisplayId(displayId))
            displayScale = model->DisplayScale;

    SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::DisplayID), displayId);
    SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::DisplayScale), displayScale);

    if (setNative)
    {
        SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::NativeDisplayID), displayId);
        SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::NativeXDisplayScale), displayScale);
    }

    // Set Gender by ModelInfo
    if (CreatureModelInfo const* modelInfo = sObjectMgr->GetCreatureModelInfo(displayId))
        SetGender(Gender(modelInfo->gender));

    CalculateHoverHeight();
}

void Unit::RestoreDisplayId(bool ignorePositiveAurasPreventingMounting /*= false*/)
{
    AuraEffect* handledAura = nullptr;
    // try to receive model from transform auras
    AuraEffectList const& transforms = GetAuraEffectsByType(SPELL_AURA_TRANSFORM);
    if (!transforms.empty())
    {
        // iterate over already applied transform auras - from newest to oldest
        for (auto i = transforms.begin(); i != transforms.end(); ++i)
        {
            if (AuraApplication const* aurApp = (*i)->GetBase()->GetApplicationOfTarget(GetGUID()))
            {
                if (!handledAura)
                {
                    if (!ignorePositiveAurasPreventingMounting)
                        handledAura = (*i);
                    else if (CreatureTemplate const* ci = sObjectMgr->GetCreatureTemplate((*i)->GetMiscValue()))
                        if (!IsDisallowedMountForm((*i)->GetId(), FORM_NONE, ObjectMgr::ChooseDisplayId(ci)->CreatureDisplayID))
                            handledAura = (*i);
                }
                // prefer negative auras
                if (!aurApp->IsPositive())
                {
                    handledAura = (*i);
                    break;
                }
            }
        }
    }

    AuraEffectList const& shapeshiftAura = GetAuraEffectsByType(SPELL_AURA_MOD_SHAPESHIFT);

    // transform aura was found
    if (handledAura)
    {
        handledAura->HandleEffect(this, AURA_EFFECT_HANDLE_SEND_FOR_CLIENT, true);
        return;
    }
    // we've found shapeshift
    else if (!shapeshiftAura.empty()) // we've found shapeshift
    {
        // only one such aura possible at a time
        if (uint32 modelId = GetModelForForm(GetShapeshiftForm(), shapeshiftAura.front()->GetId()))
        {
            if (!ignorePositiveAurasPreventingMounting || !IsDisallowedMountForm(0, GetShapeshiftForm(), modelId))
                SetDisplayId(modelId);
            else
                SetDisplayId(GetNativeDisplayId());
            return;
        }
    }
    // no auras found - set modelid to default
    SetDisplayId(GetNativeDisplayId());
}

void Unit::ClearAllReactives()
{
    for (uint8 i = 0; i < MAX_REACTIVE; ++i)
        m_reactiveTimer[i] = 0;

    if (HasAuraState(AURA_STATE_DEFENSIVE))
        ModifyAuraState(AURA_STATE_DEFENSIVE, false);
    if (HasAuraState(AURA_STATE_DEFENSIVE_2))
        ModifyAuraState(AURA_STATE_DEFENSIVE_2, false);
}

void Unit::UpdateReactives(uint32 p_time)
{
    for (uint8 i = 0; i < MAX_REACTIVE; ++i)
    {
        ReactiveType reactive = ReactiveType(i);

        if (!m_reactiveTimer[reactive])
            continue;

        if (m_reactiveTimer[reactive] <= p_time)
        {
            m_reactiveTimer[reactive] = 0;

            switch (reactive)
            {
                case REACTIVE_DEFENSE:
                    if (HasAuraState(AURA_STATE_DEFENSIVE))
                        ModifyAuraState(AURA_STATE_DEFENSIVE, false);
                    break;
                case REACTIVE_DEFENSE_2:
                    if (HasAuraState(AURA_STATE_DEFENSIVE_2))
                        ModifyAuraState(AURA_STATE_DEFENSIVE_2, false);
                    break;
                default:
                    break;
            }
        }
        else
        {
            m_reactiveTimer[reactive] -= p_time;
        }
    }
}

Unit* Unit::SelectNearbyTarget(Unit* exclude, float dist) const
{
    std::list<Unit*> targets;
    Trinity::AnyUnfriendlyUnitInObjectRangeCheck u_check(this, this, dist);
    Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> searcher(this, targets, u_check);
    Cell::VisitAllObjects(this, searcher, dist);

    // remove current target
    if (GetVictim())
        targets.remove(GetVictim());

    if (exclude)
        targets.remove(exclude);

    // remove not LoS targets
    for (std::list<Unit*>::iterator tIter = targets.begin(); tIter != targets.end();)
    {
        if (!IsWithinLOSInMap(*tIter) || (*tIter)->IsTotem() || (*tIter)->IsSpiritService() || (*tIter)->IsCritter())
            targets.erase(tIter++);
        else
            ++tIter;
    }

    // no appropriate targets
    if (targets.empty())
        return nullptr;

    // select random
    return Trinity::Containers::SelectRandomContainerElement(targets);
}

uint32 Unit::GetBaseAttackTime(WeaponAttackType att) const
{
    return m_baseAttackSpeed[att];
}

void Unit::SetBaseAttackTime(WeaponAttackType att, uint32 val)
{
    m_baseAttackSpeed[att] = val;
    UpdateAttackTimeField(att);
}

void Unit::UpdateAttackTimeField(WeaponAttackType att)
{
    switch (att)
    {
        case BASE_ATTACK:
        case OFF_ATTACK:
            SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::AttackRoundBaseTime, att), uint32(m_baseAttackSpeed[att] * m_modAttackSpeedPct[att]));
            break;
        case RANGED_ATTACK:
            SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::RangedAttackRoundBaseTime), uint32(m_baseAttackSpeed[RANGED_ATTACK] * m_modAttackSpeedPct[RANGED_ATTACK]));
            break;
        default:
            break;;
    }
}

void ApplyPercentModFloatVar(float& var, float val, bool apply)
{
    var *= (apply ? (100.0f + val) / 100.0f : 100.0f / (100.0f + val));
}

void Unit::ApplyAttackTimePercentMod(WeaponAttackType att, float val, bool apply)
{
    float remainingTimePct = float(m_attackTimer[att]) / (m_baseAttackSpeed[att] * m_modAttackSpeedPct[att]);
    if (val > 0.f)
    {
        ApplyPercentModFloatVar(m_modAttackSpeedPct[att], val, !apply);

        if (att == BASE_ATTACK)
            ApplyPercentModUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::ModHaste), val, !apply);
        else if (att == RANGED_ATTACK)
            ApplyPercentModUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::ModRangedHaste), val, !apply);
    }
    else
    {
        ApplyPercentModFloatVar(m_modAttackSpeedPct[att], -val, apply);

        if (att == BASE_ATTACK)
            ApplyPercentModUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::ModHaste), -val, apply);
        else if (att == RANGED_ATTACK)
            ApplyPercentModUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::ModRangedHaste), -val, apply);
    }

    UpdateAttackTimeField(att);
    m_attackTimer[att] = uint32(m_baseAttackSpeed[att] * m_modAttackSpeedPct[att] * remainingTimePct);
}

void Unit::ApplyCastTimePercentMod(float val, bool apply)
{
    if (val > 0.f)
    {
        ApplyPercentModUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::ModCastingSpeed), val, !apply);
        ApplyPercentModUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::ModSpellHaste), val, !apply);
        ApplyPercentModUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::ModHasteRegen), val, !apply);
    }
    else
    {
        ApplyPercentModUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::ModCastingSpeed), -val, apply);
        ApplyPercentModUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::ModSpellHaste), -val, apply);
        ApplyPercentModUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::ModHasteRegen), -val, apply);
    }
}

void Unit::UpdateAuraForGroup()
{
    if (Player* player = ToPlayer())
    {
        if (player->GetGroup())
            player->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_AURAS);
    }
    else if (GetTypeId() == TYPEID_UNIT && IsPet())
    {
        Pet* pet = ((Pet*)this);
        if (pet->isControlled())
            pet->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_PET_AURAS);
    }
}

void Unit::SetCantProc(bool apply)
{
    if (apply)
        ++m_procDeep;
    else
    {
        ASSERT(m_procDeep);
        --m_procDeep;
    }
}

float Unit::GetAPMultiplier(WeaponAttackType attType, bool normalized) const
{
    if (GetTypeId() != TYPEID_PLAYER || (IsInFeralForm() && !normalized))
        return GetBaseAttackTime(attType) / 1000.0f;

    Item* weapon = ToPlayer()->GetWeaponForAttack(attType, true);
    if (!weapon)
        return 2.0f;

    if (!normalized)
        return weapon->GetTemplate()->GetDelay() / 1000.0f;

    switch (weapon->GetTemplate()->GetSubClass())
    {
        case ITEM_SUBCLASS_WEAPON_AXE2:
        case ITEM_SUBCLASS_WEAPON_MACE2:
        case ITEM_SUBCLASS_WEAPON_POLEARM:
        case ITEM_SUBCLASS_WEAPON_SWORD2:
        case ITEM_SUBCLASS_WEAPON_STAFF:
        case ITEM_SUBCLASS_WEAPON_FISHING_POLE:
            return 3.3f;
        case ITEM_SUBCLASS_WEAPON_AXE:
        case ITEM_SUBCLASS_WEAPON_MACE:
        case ITEM_SUBCLASS_WEAPON_SWORD:
        case ITEM_SUBCLASS_WEAPON_WARGLAIVES:
        case ITEM_SUBCLASS_WEAPON_EXOTIC:
        case ITEM_SUBCLASS_WEAPON_EXOTIC2:
        case ITEM_SUBCLASS_WEAPON_FIST_WEAPON:
            return 2.4f;
        case ITEM_SUBCLASS_WEAPON_DAGGER:
            return 1.7f;
        case ITEM_SUBCLASS_WEAPON_THROWN:
            return 2.0f;
        default:
            return weapon->GetTemplate()->GetDelay() / 1000.0f;
    }
}

Pet* Unit::CreateTamedPetFrom(Creature* creatureTarget, uint32 spell_id)
{
    if (GetTypeId() != TYPEID_PLAYER)
        return nullptr;

    Pet* pet = new Pet(ToPlayer(), HUNTER_PET);

    if (!pet->CreateBaseAtCreature(creatureTarget))
    {
        delete pet;
        return nullptr;
    }

    uint8 level = creatureTarget->GetLevelForTarget(this) + 5 < GetLevel() ? (GetLevel() - 5) : creatureTarget->GetLevelForTarget(this);

    if (!InitTamedPet(pet, level, spell_id))
    {
        delete pet;
        return nullptr;
    }

    return pet;
}

Pet* Unit::CreateTamedPetFrom(uint32 creatureEntry, uint32 spell_id)
{
    if (GetTypeId() != TYPEID_PLAYER)
        return nullptr;

    CreatureTemplate const* creatureInfo = sObjectMgr->GetCreatureTemplate(creatureEntry);
    if (!creatureInfo)
        return nullptr;

    Pet* pet = new Pet(ToPlayer(), HUNTER_PET);

    if (!pet->CreateBaseAtCreatureInfo(creatureInfo, this) || !InitTamedPet(pet, GetLevel(), spell_id))
    {
        delete pet;
        return nullptr;
    }

    return pet;
}

bool Unit::InitTamedPet(Pet* pet, uint8 level, uint32 spell_id)
{
    Player* player = ToPlayer();
    PetStable& petStable = player->GetOrInitPetStable();
    auto freeActiveSlotItr = std::find_if(petStable.ActivePets.begin(), petStable.ActivePets.end(), [](Optional<PetStable::PetInfo> const& petInfo)
    {
        return !petInfo.has_value();
    });

    if (freeActiveSlotItr == petStable.ActivePets.end())
        return false;

    pet->SetCreatorGUID(GetGUID());
    pet->SetFaction(GetFaction());
    pet->SetCreatedBySpell(spell_id);
    pet->SetUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED);

    if (!pet->InitStatsForLevel(level))
    {
        TC_LOG_ERROR("entities.unit", "Pet::InitStatsForLevel() failed for creature (Entry: {})!", pet->GetEntry());
        return false;
    }

    PhasingHandler::InheritPhaseShift(pet, this);

    pet->GetCharmInfo()->SetPetNumber(sObjectMgr->GeneratePetNumber(), true);
    // this enables pet details window (Shift+P)
    pet->InitPetCreateSpells();
    //pet->InitLevelupSpellsForLevel();
    pet->SetFullHealth();

    petStable.SetCurrentActivePetIndex(std::distance(petStable.ActivePets.begin(), freeActiveSlotItr));
    pet->FillPetInfo(&freeActiveSlotItr->emplace());
    player->AddPetToUpdateFields(**freeActiveSlotItr, PetSaveMode(*petStable.GetCurrentActivePetIndex()), PET_STABLE_ACTIVE);
    return true;
}

void Unit::SendDurabilityLoss(Player* receiver, uint32 percent)
{
    WorldPackets::Misc::DurabilityDamageDeath packet;
    packet.Percent = percent;
    receiver->GetSession()->SendPacket(packet.Write());
}

void Unit::PlayOneShotAnimKitId(uint16 animKitId)
{
    if (!sAnimKitStore.LookupEntry(animKitId))
    {
        TC_LOG_ERROR("entities.unit", "Unit::PlayOneShotAnimKitId using invalid AnimKit ID: {}", animKitId);
        return;
    }

    WorldPackets::Misc::PlayOneShotAnimKit data;
    data.Unit = GetGUID();
    data.AnimKitID = animKitId;
    SendMessageToSet(data.Write(), true);
}

void Unit::SetAIAnimKitId(uint16 animKitId)
{
    if (_aiAnimKitId == animKitId)
        return;

    if (animKitId && !sAnimKitStore.LookupEntry(animKitId))
        return;

    _aiAnimKitId = animKitId;

    WorldPackets::Misc::SetAIAnimKit data;
    data.Unit = GetGUID();
    data.AnimKitID = animKitId;
    SendMessageToSet(data.Write(), true);
}

void Unit::SetMovementAnimKitId(uint16 animKitId)
{
    if (_movementAnimKitId == animKitId)
        return;

    if (animKitId && !sAnimKitStore.LookupEntry(animKitId))
        return;

    _movementAnimKitId = animKitId;

    WorldPackets::Misc::SetMovementAnimKit data;
    data.Unit = GetGUID();
    data.AnimKitID = animKitId;
    SendMessageToSet(data.Write(), true);
}

void Unit::SetMeleeAnimKitId(uint16 animKitId)
{
    if (_meleeAnimKitId == animKitId)
        return;

    if (animKitId && !sAnimKitStore.LookupEntry(animKitId))
        return;

    _meleeAnimKitId = animKitId;

    WorldPackets::Misc::SetMeleeAnimKit data;
    data.Unit = GetGUID();
    data.AnimKitID = animKitId;
    SendMessageToSet(data.Write(), true);
}

/*static*/ void Unit::Kill(Unit* attacker, Unit* victim, bool durabilityLoss /*= true*/, bool skipSettingDeathState /*= false*/)
{
    // Prevent killing unit twice (and giving reward from kill twice)
    if (!victim->GetHealth())
        return;

    if (attacker && !attacker->IsInMap(victim))
        attacker = nullptr;

    // find player: owner of controlled `this` or `this` itself maybe
    Player* player = nullptr;
    if (attacker)
        player = attacker->GetCharmerOrOwnerPlayerOrPlayerItself();

    Creature* creature = victim->ToCreature();

    bool isRewardAllowed = attacker != victim;
    if (creature)
        isRewardAllowed = isRewardAllowed && !creature->GetTapList().empty();

    std::vector<Player*> tappers;
    if (isRewardAllowed && creature)
    {
        for (ObjectGuid tapperGuid : creature->GetTapList())
            if (Player* tapper = ObjectAccessor::GetPlayer(*creature, tapperGuid))
                tappers.push_back(tapper);

        if (!creature->CanHaveLoot())
            isRewardAllowed = false;
    }

    // Exploit fix
    if (creature && creature->IsPet() && creature->GetOwnerGUID().IsPlayer())
        isRewardAllowed = false;

    // Reward player, his pets, and group/raid members
    // call kill spell proc event (before real die and combat stop to triggering auras removed at death/combat stop)
    if (isRewardAllowed)
    {
        std::unordered_set<Group*> groups;
        for (Player* tapper : tappers)
        {
            if (Group* tapperGroup = tapper->GetGroup())
            {
                if (groups.insert(tapperGroup).second)
                {
                    WorldPackets::Party::PartyKillLog partyKillLog;
                    partyKillLog.Player = player && tapperGroup->IsMember(player->GetGUID()) ? player->GetGUID() : tapper->GetGUID();
                    partyKillLog.Victim = victim->GetGUID();
                    partyKillLog.Write();

                    tapperGroup->BroadcastPacket(partyKillLog.GetRawPacket(), tapperGroup->GetMemberGroup(tapper->GetGUID()) != 0);

                    if (creature)
                        tapperGroup->UpdateLooterGuid(creature, true);
                }
            }
            else
            {
                WorldPackets::Party::PartyKillLog partyKillLog;
                partyKillLog.Player = tapper->GetGUID();
                partyKillLog.Victim = victim->GetGUID();
                tapper->SendDirectMessage(partyKillLog.Write());
            }
        }

        // Generate loot before updating looter
        if (creature)
        {
            DungeonEncounterEntry const* dungeonEncounter = nullptr;
            if (InstanceScript const* instance = creature->GetInstanceScript())
                dungeonEncounter = instance->GetBossDungeonEncounter(creature);

            if (creature->GetMap()->IsDungeon())
            {
                if (dungeonEncounter)
                {
                    creature->m_personalLoot = GenerateDungeonEncounterPersonalLoot(dungeonEncounter->ID, creature->GetLootId(),
                        LootTemplates_Creature, LOOT_CORPSE, creature, creature->GetCreatureDifficulty()->GoldMin, creature->GetCreatureDifficulty()->GoldMax,
                        creature->GetLootMode(), creature->GetMap()->GetMapDifficulty(), tappers);
                }
                else if (!tappers.empty())
                {
                    Group* group = !groups.empty() ? *groups.begin() : nullptr;
                    Player* looter = group ? ASSERT_NOTNULL(ObjectAccessor::GetPlayer(*creature, group->GetLooterGuid())) : tappers[0];

                    Loot* loot = new Loot(creature->GetMap(), creature->GetGUID(), LOOT_CORPSE, dungeonEncounter ? group : nullptr);

                    if (uint32 lootid = creature->GetLootId())
                        loot->FillLoot(lootid, LootTemplates_Creature, looter, dungeonEncounter != nullptr, false, creature->GetLootMode(), ItemBonusMgr::GetContextForPlayer(creature->GetMap()->GetMapDifficulty(), looter));

                    if (creature->GetLootMode() > 0)
                        loot->generateMoneyLoot(creature->GetCreatureDifficulty()->GoldMin, creature->GetCreatureDifficulty()->GoldMax);

                    if (group)
                        loot->NotifyLootList(creature->GetMap());

                    creature->m_personalLoot[looter->GetGUID()].reset(loot);   // trash mob loot is personal, generated with round robin rules

                    // Update round robin looter only if the creature had loot
                    if (!loot->isLooted())
                        for (Group* tapperGroup : groups)
                            tapperGroup->UpdateLooterGuid(creature);
                }
            }
            else
            {
                for (Player* tapper : tappers)
                {
                    Loot* loot = new Loot(creature->GetMap(), creature->GetGUID(), LOOT_CORPSE, nullptr);

                    if (dungeonEncounter)
                        loot->SetDungeonEncounterId(dungeonEncounter->ID);

                    if (uint32 lootid = creature->GetLootId())
                        loot->FillLoot(lootid, LootTemplates_Creature, tapper, true, false, creature->GetLootMode(), ItemBonusMgr::GetContextForPlayer(creature->GetMap()->GetMapDifficulty(), tapper));

                    if (creature->GetLootMode() > 0)
                        loot->generateMoneyLoot(creature->GetCreatureDifficulty()->GoldMin, creature->GetCreatureDifficulty()->GoldMax);

                    creature->m_personalLoot[tapper->GetGUID()].reset(loot);
                }
            }
        }

        if (Vignettes::VignetteData const* vignette = victim->GetVignette())
        {
            for (Player* tapper : tappers)
            {
                if (Quest const* reward = sObjectMgr->GetQuestTemplate(vignette->Data->RewardQuestID))
                    tapper->RewardQuest(reward, LootItemType::Item, 0, victim, false);

                if (vignette->Data->VisibleTrackingQuestID)
                    tapper->SetRewardedQuest(vignette->Data->VisibleTrackingQuestID);
            }
        }

        KillRewarder(Trinity::IteratorPair(tappers.data(), tappers.data() + tappers.size()), victim, false).Reward();
    }

    // Do KILL and KILLED procs. KILL proc is called only for the unit who landed the killing blow (and its owner - for pets and totems) regardless of who tapped the victim
    if (attacker && (attacker->IsPet() || attacker->IsTotem()))
    {
        // proc only once for victim
        if (Unit* owner = attacker->GetOwner())
            Unit::ProcSkillsAndAuras(owner, victim, PROC_FLAG_KILL, PROC_FLAG_NONE, PROC_SPELL_TYPE_MASK_ALL, PROC_SPELL_PHASE_NONE, PROC_HIT_NONE, nullptr, nullptr, nullptr);
    }

    if (!victim->IsCritter())
    {
        Unit::ProcSkillsAndAuras(attacker, victim, PROC_FLAG_KILL, PROC_FLAG_NONE, PROC_SPELL_TYPE_MASK_ALL, PROC_SPELL_PHASE_NONE, PROC_HIT_NONE, nullptr, nullptr, nullptr);

        for (Player* tapper : tappers)
            if (tapper->IsAtGroupRewardDistance(victim))
                Unit::ProcSkillsAndAuras(tapper, victim, { PROC_FLAG_NONE, PROC_FLAG_2_TARGET_DIES }, PROC_FLAG_NONE, PROC_SPELL_TYPE_MASK_ALL, PROC_SPELL_PHASE_NONE, PROC_HIT_NONE, nullptr, nullptr, nullptr);
    }

    // Proc auras on death - must be before aura/combat remove
    Unit::ProcSkillsAndAuras(victim, victim, PROC_FLAG_NONE, PROC_FLAG_DEATH, PROC_SPELL_TYPE_MASK_ALL, PROC_SPELL_PHASE_NONE, PROC_HIT_NONE, nullptr, nullptr, nullptr);

    // update get killing blow achievements, must be done before setDeathState to be able to require auras on target
    // and before Spirit of Redemption as it also removes auras
    if (attacker)
        if (Player* killerPlayer = attacker->GetCharmerOrOwnerPlayerOrPlayerItself())
            killerPlayer->UpdateCriteria(CriteriaType::DeliveredKillingBlow, 1, 0, 0, victim);

    if (!skipSettingDeathState)
    {
        TC_LOG_DEBUG("entities.unit", "SET JUST_DIED");
        victim->setDeathState(JUST_DIED);
    }

    // Inform pets (if any) when player kills target)
    // MUST come after victim->setDeathState(JUST_DIED); or pet next target
    // selection will get stuck on same target and break pet react state
    for (Player* tapper : tappers)
    {
        Pet* pet = tapper->GetPet();
        if (pet && pet->IsAlive() && pet->isControlled())
        {
            if (pet->IsAIEnabled())
                pet->AI()->KilledUnit(victim);
            else
                TC_LOG_ERROR("entities.unit", "Pet doesn't have any AI in Unit::Kill(). {}", pet->GetDebugInfo());
        }
    }

    // 10% durability loss on death
    if (Player* plrVictim = victim->ToPlayer())
    {
        // remember victim PvP death for corpse type and corpse reclaim delay
        // at original death (not at SpiritOfRedemtionTalent timeout)
        plrVictim->SetPvPDeath(player != nullptr);

        // only if not player and not controlled by player pet. And not at BG
        if ((durabilityLoss && !player && !victim->ToPlayer()->InBattleground()) || (player && sWorld->getBoolConfig(CONFIG_DURABILITY_LOSS_IN_PVP)))
        {
            double baseLoss = sWorld->getRate(RATE_DURABILITY_LOSS_ON_DEATH);
            uint32 loss = uint32(baseLoss - (baseLoss * plrVictim->GetTotalAuraMultiplier(SPELL_AURA_MOD_DURABILITY_LOSS)));
            TC_LOG_DEBUG("entities.unit", "We are dead, losing {} percent durability", loss);
            // Durability loss is calculated more accurately again for each item in Player::DurabilityLoss
            plrVictim->DurabilityLossAll(baseLoss, false);
            // durability lost message
            plrVictim->SendDurabilityLoss(plrVictim, loss);
        }
        // Call KilledUnit for creatures
        if (attacker && attacker->GetTypeId() == TYPEID_UNIT && attacker->IsAIEnabled())
            attacker->ToCreature()->AI()->KilledUnit(victim);

        // last damage from non duel opponent or opponent controlled creature
        if (plrVictim->duel)
        {
            plrVictim->duel->Opponent->CombatStopWithPets(true);
            plrVictim->CombatStopWithPets(true);
            plrVictim->DuelComplete(DUEL_INTERRUPTED);
        }
    }
    else                                                // creature died
    {
        TC_LOG_DEBUG("entities.unit", "DealDamageNotPlayer");
        ASSERT_NODEBUGINFO(creature);

        if (!creature->IsPet())
        {
            // must be after setDeathState which resets dynamic flags
            if (!creature->IsFullyLooted())
                creature->SetDynamicFlag(UNIT_DYNFLAG_LOOTABLE);
            else
                creature->AllLootRemovedFromCorpse();

            if (creature->CanHaveLoot() && LootTemplates_Skinning.HaveLootFor(creature->GetCreatureDifficulty()->SkinLootID))
            {
                creature->SetDynamicFlag(UNIT_DYNFLAG_CAN_SKIN);
                creature->SetUnitFlag(UNIT_FLAG_SKINNABLE);
            }
        }

        // Call KilledUnit for creatures, this needs to be called after the lootable flag is set
        if (attacker && attacker->GetTypeId() == TYPEID_UNIT && attacker->IsAIEnabled())
            attacker->ToCreature()->AI()->KilledUnit(victim);

        // Call creature just died function
        if (CreatureAI* ai = creature->AI())
        {
            ai->OnHealthDepleted(attacker, true);
            ai->JustDied(attacker);
        }

        if (TempSummon * summon = creature->ToTempSummon())
        {
            if (WorldObject * summoner = summon->GetSummoner())
            {
                if (summoner->ToCreature() && summoner->ToCreature()->IsAIEnabled())
                    summoner->ToCreature()->AI()->SummonedCreatureDies(creature, attacker);
                else if (summoner->ToGameObject() && summoner->ToGameObject()->AI())
                    summoner->ToGameObject()->AI()->SummonedCreatureDies(creature, attacker);
            }
        }
    }

    // outdoor pvp things, do these after setting the death state, else the player activity notify won't work... doh...
    // handle player kill only if not suicide (spirit of redemption for example)
    if (player && attacker != victim)
    {
        if (OutdoorPvP* pvp = player->GetOutdoorPvP())
            pvp->HandleKill(player, victim);

        if (Battlefield* bf = sBattlefieldMgr->GetBattlefieldToZoneId(player->GetMap(), player->GetZoneId()))
            bf->HandleKill(player, victim);
    }

    //if (victim->GetTypeId() == TYPEID_PLAYER)
    //    if (OutdoorPvP* pvp = victim->ToPlayer()->GetOutdoorPvP())
    //        pvp->HandlePlayerActivityChangedpVictim->ToPlayer();

    // battleground things (do this at the end, so the death state flag will be properly set to handle in the bg->handlekill)
    if (attacker)
    {
        if (BattlegroundMap* bgMap = victim->GetMap()->ToBattlegroundMap())
        {
            if (Battleground* bg = bgMap->GetBG())
            {
                if (Player* playerVictim = victim->ToPlayer())
                {
                    if (player)
                        bg->HandleKillPlayer(playerVictim, player);
                }
                else
                    bg->HandleKillUnit(victim->ToCreature(), attacker);
            }
        }
    }

    // achievement stuff
    if (attacker && victim->GetTypeId() == TYPEID_PLAYER)
    {
        if (attacker->GetTypeId() == TYPEID_UNIT)
            victim->ToPlayer()->UpdateCriteria(CriteriaType::KilledByCreature, attacker->GetEntry());
        else if (attacker->GetTypeId() == TYPEID_PLAYER && victim != attacker)
            victim->ToPlayer()->UpdateCriteria(CriteriaType::KilledByPlayer, 1, attacker->ToPlayer()->GetEffectiveTeam());
    }

    // Hook for OnPVPKill Event
    if (attacker)
    {
        if (Player* killerPlr = attacker->ToPlayer())
        {
            if (Player* killedPlr = victim->ToPlayer())
                sScriptMgr->OnPVPKill(killerPlr, killedPlr);
            else if (Creature* killedCre = victim->ToCreature())
                sScriptMgr->OnCreatureKill(killerPlr, killedCre);
        }
        else if (Creature* killerCre = attacker->ToCreature())
        {
            if (Player* killed = victim->ToPlayer())
                sScriptMgr->OnPlayerKilledByCreature(killerCre, killed);
        }
    }
}

void Unit::SetControlled(bool apply, UnitState state)
{
    if (apply)
    {
        if (HasUnitState(state))
            return;

        if (state & UNIT_STATE_CONTROLLED)
            CastStop();

        AddUnitState(state);
        switch (state)
        {
            case UNIT_STATE_STUNNED:
                SetStunned(true);
                break;
            case UNIT_STATE_ROOT:
                if (!HasUnitState(UNIT_STATE_STUNNED))
                    SetRooted(true);
                break;
            case UNIT_STATE_CONFUSED:
                if (!HasUnitState(UNIT_STATE_STUNNED))
                {
                    SendMeleeAttackStop();
                    // SendAutoRepeatCancel ?
                    SetConfused(true);
                }
                break;
            case UNIT_STATE_FLEEING:
                if (!HasUnitState(UNIT_STATE_STUNNED | UNIT_STATE_CONFUSED))
                {
                    SendMeleeAttackStop();
                    // SendAutoRepeatCancel ?
                    SetFeared(true);
                }
                break;
            default:
                break;
        }
    }
    else
    {
        switch (state)
        {
            case UNIT_STATE_STUNNED:
                if (HasAuraType(SPELL_AURA_MOD_STUN) || HasAuraType(SPELL_AURA_MOD_STUN_DISABLE_GRAVITY))
                    return;

                ClearUnitState(state);
                SetStunned(false);
                break;
            case UNIT_STATE_ROOT:
                if (HasAuraType(SPELL_AURA_MOD_ROOT) || HasAuraType(SPELL_AURA_MOD_ROOT_2) || HasAuraType(SPELL_AURA_MOD_ROOT_DISABLE_GRAVITY) || GetVehicle() || (ToCreature() && ToCreature()->IsSessile()))
                    return;

                ClearUnitState(state);
                if (!HasUnitState(UNIT_STATE_STUNNED))
                    SetRooted(false);
                break;
            case UNIT_STATE_CONFUSED:
                if (HasAuraType(SPELL_AURA_MOD_CONFUSE))
                    return;

                ClearUnitState(state);
                SetConfused(false);
                break;
            case UNIT_STATE_FLEEING:
                if (HasAuraType(SPELL_AURA_MOD_FEAR))
                    return;

                ClearUnitState(state);
                SetFeared(false);
                break;
            default:
                return;
        }

        ApplyControlStatesIfNeeded();
    }
}

void Unit::ApplyControlStatesIfNeeded()
{
    // Unit States might have been already cleared but auras still present. I need to check with HasAuraType
    if (HasUnitState(UNIT_STATE_STUNNED) || HasAuraType(SPELL_AURA_MOD_STUN) || HasAuraType(SPELL_AURA_MOD_STUN_DISABLE_GRAVITY))
        SetStunned(true);

    if (HasUnitState(UNIT_STATE_ROOT) || HasAuraType(SPELL_AURA_MOD_ROOT) || HasAuraType(SPELL_AURA_MOD_ROOT_2) || HasAuraType(SPELL_AURA_MOD_ROOT_DISABLE_GRAVITY))
        SetRooted(true);

    if (HasUnitState(UNIT_STATE_CONFUSED) || HasAuraType(SPELL_AURA_MOD_CONFUSE))
        SetConfused(true);

    if (HasUnitState(UNIT_STATE_FLEEING) || HasAuraType(SPELL_AURA_MOD_FEAR))
        SetFeared(true);
}

void Unit::SetStunned(bool apply)
{
    if (apply)
    {
        SetTarget(ObjectGuid::Empty);
        SetUnitFlag(UNIT_FLAG_STUNNED);

        StopMoving();

        if (GetTypeId() == TYPEID_PLAYER)
            SetStandState(UNIT_STAND_STATE_STAND);

        SetRooted(true);

        CastStop();
    }
    else
    {
        if (IsAlive() && GetVictim())
            SetTarget(EnsureVictim()->GetGUID());

        // don't remove UNIT_FLAG_STUNNED for pet when owner is mounted (disabled pet's interface)
        Unit* owner = GetCharmerOrOwner();
        if (!owner || owner->GetTypeId() != TYPEID_PLAYER || !owner->ToPlayer()->IsMounted())
            RemoveUnitFlag(UNIT_FLAG_STUNNED);

        if (!HasUnitState(UNIT_STATE_ROOT))         // prevent moving if it also has root effect
            SetRooted(false);
    }
}

void Unit::SetRooted(bool apply, bool packetOnly /*= false*/)
{
    if (!packetOnly)
    {
        if (apply)
        {
            // MOVEMENTFLAG_ROOT cannot be used in conjunction with MOVEMENTFLAG_MASK_MOVING (tested 3.3.5a)
            // this will freeze clients. That's why we remove MOVEMENTFLAG_MASK_MOVING before
            // setting MOVEMENTFLAG_ROOT
            RemoveUnitMovementFlag(MOVEMENTFLAG_MASK_MOVING);
            AddUnitMovementFlag(MOVEMENTFLAG_ROOT);
            StopMoving();
        }
        else
            RemoveUnitMovementFlag(MOVEMENTFLAG_ROOT);
    }

    static OpcodeServer const rootOpcodeTable[2][2] =
    {
        { SMSG_MOVE_SPLINE_UNROOT, SMSG_MOVE_UNROOT },
        { SMSG_MOVE_SPLINE_ROOT, SMSG_MOVE_ROOT }
    };

    if (Player* playerMover = Unit::ToPlayer(GetUnitBeingMoved())) // unit controlled by a player.
    {
        WorldPackets::Movement::MoveSetFlag packet(rootOpcodeTable[apply][1]);
        packet.MoverGUID = GetGUID();
        packet.SequenceIndex = m_movementCounter++;
        playerMover->SendDirectMessage(packet.Write());

        WorldPackets::Movement::MoveUpdate moveUpdate;
        moveUpdate.Status = &m_movementInfo;
        SendMessageToSet(moveUpdate.Write(), playerMover);
    }
    else
    {
        WorldPackets::Movement::MoveSplineSetFlag packet(rootOpcodeTable[apply][0]);
        packet.MoverGUID = GetGUID();
        SendMessageToSet(packet.Write(), true);
    }
}

void Unit::SetFeared(bool apply)
{
    if (apply)
    {
        SetTarget(ObjectGuid::Empty);

        Unit* caster = nullptr;
        AuraEffectList const& fearAuras = GetAuraEffectsByType(SPELL_AURA_MOD_FEAR);
        if (!fearAuras.empty())
            caster = ObjectAccessor::GetUnit(*this, fearAuras.front()->GetCasterGUID());
        if (!caster)
            caster = getAttackerForHelper();
        GetMotionMaster()->MoveFleeing(caster, fearAuras.empty() ? Milliseconds(sWorld->getIntConfig(CONFIG_CREATURE_FAMILY_FLEE_DELAY)) : 0ms);             // caster == NULL processed in MoveFleeing
        SetUnitFlag(UNIT_FLAG_FLEEING);
    }
    else
    {
        RemoveUnitFlag(UNIT_FLAG_FLEEING);
        if (IsAlive())
        {
            GetMotionMaster()->Remove(FLEEING_MOTION_TYPE);
            if (Unit const* victim = GetVictim())
                SetTarget(victim->GetGUID());
            if (!IsPlayer() && !IsInCombat())
                GetMotionMaster()->MoveTargetedHome();
        }
    }

    // block / allow control to real player in control (eg charmer)
    if (GetTypeId() == TYPEID_PLAYER)
    {
        if (m_playerMovingMe)
            m_playerMovingMe->SetClientControl(this, !apply);
    }
}

void Unit::SetConfused(bool apply)
{
    if (apply)
    {
        SetTarget(ObjectGuid::Empty);
        GetMotionMaster()->MoveConfused();
    }
    else
    {
        if (IsAlive())
        {
            GetMotionMaster()->Remove(CONFUSED_MOTION_TYPE);
            if (GetVictim())
                SetTarget(EnsureVictim()->GetGUID());
        }
    }

    // block / allow control to real player in control (eg charmer)
    if (GetTypeId() == TYPEID_PLAYER)
    {
        if (m_playerMovingMe)
            m_playerMovingMe->SetClientControl(this, !apply);
    }
}

bool Unit::SetCharmedBy(Unit* charmer, CharmType type, AuraApplication const* aurApp)
{
    if (!charmer)
        return false;

    // dismount players when charmed
    if (GetTypeId() == TYPEID_PLAYER)
        RemoveAurasByType(SPELL_AURA_MOUNTED);

    if (charmer->GetTypeId() == TYPEID_PLAYER)
        charmer->RemoveAurasByType(SPELL_AURA_MOUNTED);

    ASSERT(type != CHARM_TYPE_POSSESS || charmer->GetTypeId() == TYPEID_PLAYER);
    ASSERT((type == CHARM_TYPE_VEHICLE) == (GetVehicleKit() && GetVehicleKit()->IsControllableVehicle()));

    TC_LOG_DEBUG("entities.unit", "SetCharmedBy: charmer {}, charmed {}, type {}.", charmer->GetGUID().ToString(), GetGUID().ToString(), uint32(type));

    if (this == charmer)
    {
        TC_LOG_FATAL("entities.unit", "Unit::SetCharmedBy: Unit {} is trying to charm itself!", GetGUID().ToString());
        return false;
    }

    //if (HasUnitState(UNIT_STATE_UNATTACKABLE))
    //    return false;

    if (GetTypeId() == TYPEID_PLAYER && ToPlayer()->GetTransport())
    {
        TC_LOG_FATAL("entities.unit", "Unit::SetCharmedBy: {} is trying to charm Player {} on transport", charmer->GetGUID().ToString(), GetGUID().ToString());
        return false;
    }

    // Already charmed
    if (!GetCharmerGUID().IsEmpty())
    {
        TC_LOG_FATAL("entities.unit", "Unit::SetCharmedBy: {} has already been charmed but {} is trying to charm it!", GetGUID().ToString(), charmer->GetGUID().ToString());
        return false;
    }

    CastStop();
    AttackStop();

    Player* playerCharmer = charmer->ToPlayer();

    // Charmer stop charming
    if (playerCharmer)
    {
        playerCharmer->StopCastingCharm();
        playerCharmer->StopCastingBindSight();
    }

    // Charmed stop charming
    if (GetTypeId() == TYPEID_PLAYER)
    {
        ToPlayer()->StopCastingCharm();
        ToPlayer()->StopCastingBindSight();
    }

    // StopCastingCharm may remove a possessed pet?
    if (!IsInWorld())
    {
        TC_LOG_FATAL("entities.unit", "Unit::SetCharmedBy: {} is not in world but {} is trying to charm it!", GetGUID().ToString(), charmer->GetGUID().ToString());
        return false;
    }

    // charm is set by aura, and aura effect remove handler was called during apply handler execution
    // prevent undefined behaviour
    if (aurApp && aurApp->GetRemoveMode())
        return false;

    _oldFactionId = GetFaction();
    SetFaction(charmer->GetFaction());

    // Pause any Idle movement
    PauseMovement(0, 0, false);

    // Remove any active voluntary movement
    GetMotionMaster()->Clear(MOTION_PRIORITY_NORMAL);

    // Stop any remaining spline, if no involuntary movement is found
    auto criteria = [](MovementGenerator const* movement) -> bool
    {
        return movement->Priority == MOTION_PRIORITY_HIGHEST;
    };
    if (!GetMotionMaster()->HasMovementGenerator(criteria))
        StopMoving();

    // Set charmed
    charmer->SetCharm(this, true);

    if (Player* player = ToPlayer())
    {
        if (player->isAFK())
            player->ToggleAFK();

        player->SetClientControl(this, false);
    }

    // charm is set by aura, and aura effect remove handler was called during apply handler execution
    // prevent undefined behaviour
    if (aurApp && aurApp->GetRemoveMode())
    {
        // properly clean up charm changes up to this point to avoid leaving the unit in partially charmed state
        SetFaction(_oldFactionId);
        GetMotionMaster()->InitializeDefault();
        charmer->SetCharm(this, false);
        return false;
    }

    // Pets already have a properly initialized CharmInfo, don't overwrite it.
    if (type != CHARM_TYPE_VEHICLE && !GetCharmInfo())
    {
        InitCharmInfo();
        if (type == CHARM_TYPE_POSSESS)
            GetCharmInfo()->InitPossessCreateSpells();
        else
            GetCharmInfo()->InitCharmCreateSpells();
    }

    if (playerCharmer)
    {
        switch (type)
        {
            case CHARM_TYPE_VEHICLE:
                SetUnitFlag(UNIT_FLAG_POSSESSED);
                playerCharmer->SetClientControl(this, true);
                playerCharmer->VehicleSpellInitialize();
                break;
            case CHARM_TYPE_POSSESS:
                SetUnitFlag(UNIT_FLAG_POSSESSED);
                charmer->SetUnitFlag(UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                playerCharmer->SetClientControl(this, true);
                playerCharmer->PossessSpellInitialize();
                AddUnitState(UNIT_STATE_POSSESSED);
                break;
            case CHARM_TYPE_CHARM:
                if (GetTypeId() == TYPEID_UNIT && charmer->GetClass() == CLASS_WARLOCK)
                {
                    CreatureTemplate const* cinfo = ToCreature()->GetCreatureTemplate();
                    if (cinfo && cinfo->type == CREATURE_TYPE_DEMON)
                    {
                        // to prevent client crash
                        SetClass(CLASS_MAGE);

                        // just to enable stat window
                        if (GetCharmInfo())
                            GetCharmInfo()->SetPetNumber(sObjectMgr->GeneratePetNumber(), true);

                        // if charmed two demons the same session, the 2nd gets the 1st one's name
                        SetPetNameTimestamp(uint32(GameTime::GetGameTime()));
                    }
                }
                playerCharmer->CharmSpellInitialize();
                break;
            default:
            case CHARM_TYPE_CONVERT:
                break;
        }
    }

    AddUnitState(UNIT_STATE_CHARMED);

    if ((GetTypeId() != TYPEID_PLAYER) || (charmer->GetTypeId() != TYPEID_PLAYER))
    {
        // AI will schedule its own change if appropriate
        if (UnitAI* ai = GetAI())
            ai->OnCharmed(false);
        else
            ScheduleAIChange();
    }
    return true;
}

void Unit::RemoveCharmedBy(Unit* charmer)
{
    if (!IsCharmed())
        return;

    if (charmer)
        ASSERT(charmer == GetCharmer());
    else
        charmer = GetCharmer();

    ASSERT(charmer);

    CharmType type;
    if (HasUnitState(UNIT_STATE_POSSESSED))
        type = CHARM_TYPE_POSSESS;
    else if (charmer->IsOnVehicle(this))
        type = CHARM_TYPE_VEHICLE;
    else
        type = CHARM_TYPE_CHARM;

    CastStop();
    AttackStop();

    if (_oldFactionId)
    {
        SetFaction(_oldFactionId);
        _oldFactionId = 0;
    }
    else
        RestoreFaction();

    ///@todo Handle SLOT_IDLE motion resume
    GetMotionMaster()->InitializeDefault();

    // Vehicle should not attack its passenger after he exists the seat
    if (type != CHARM_TYPE_VEHICLE)
        LastCharmerGUID = charmer->GetGUID();

    ASSERT(type != CHARM_TYPE_POSSESS || charmer->GetTypeId() == TYPEID_PLAYER);
    ASSERT(type != CHARM_TYPE_VEHICLE || (GetTypeId() == TYPEID_UNIT && IsVehicle()));

    charmer->SetCharm(this, false);
    m_combatManager.RevalidateCombat();

    Player* playerCharmer = charmer->ToPlayer();
    if (playerCharmer)
    {
        switch (type)
        {
            case CHARM_TYPE_VEHICLE:
                playerCharmer->SetClientControl(this, false);
                playerCharmer->SetClientControl(charmer, true);
                RemoveUnitFlag(UNIT_FLAG_POSSESSED);
                break;
            case CHARM_TYPE_POSSESS:
                ClearUnitState(UNIT_STATE_POSSESSED);
                playerCharmer->SetClientControl(this, false);
                playerCharmer->SetClientControl(charmer, true);
                charmer->RemoveUnitFlag(UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                RemoveUnitFlag(UNIT_FLAG_POSSESSED);
                break;
            case CHARM_TYPE_CHARM:
                if (GetTypeId() == TYPEID_UNIT && charmer->GetClass() == CLASS_WARLOCK)
                {
                    CreatureTemplate const* cinfo = ToCreature()->GetCreatureTemplate();
                    if (cinfo && cinfo->type == CREATURE_TYPE_DEMON)
                    {
                        SetClass(uint8(cinfo->unit_class));
                        if (GetCharmInfo())
                            GetCharmInfo()->SetPetNumber(0, true);
                        else
                            TC_LOG_ERROR("entities.unit", "Aura::HandleModCharm: {} has a charm aura but no charm info!", GetGUID().ToString());
                    }
                }
                break;
            case CHARM_TYPE_CONVERT:
                break;
        }
    }

    if (Player* player = ToPlayer())
        player->SetClientControl(this, true);

    if (playerCharmer && this != charmer->GetFirstControlled())
        playerCharmer->SendRemoveControlBar();

    // a guardian should always have charminfo
    if (!IsGuardian())
        DeleteCharmInfo();

    // reset confused movement for example
    ApplyControlStatesIfNeeded();

    if (GetTypeId() != TYPEID_PLAYER || charmer->GetTypeId() == TYPEID_UNIT)
    {
        if (UnitAI* charmedAI = GetAI())
            charmedAI->OnCharmed(false); // AI will potentially schedule a charm ai update
        else
            ScheduleAIChange();
    }
}

void Unit::RestoreFaction()
{
    if  (HasAuraType(SPELL_AURA_MOD_FACTION))
    {
        SetFaction(GetAuraEffectsByType(SPELL_AURA_MOD_FACTION).front()->GetMiscValue());
        return;
    }

    if (GetTypeId() == TYPEID_PLAYER)
        ToPlayer()->SetFactionForRace(GetRace());
    else
    {
        if (HasUnitTypeMask(UNIT_MASK_MINION))
        {
            if (Unit* owner = GetOwner())
            {
                SetFaction(owner->GetFaction());
                return;
            }
        }

        if (CreatureTemplate const* cinfo = ToCreature()->GetCreatureTemplate())  // normal creature
            SetFaction(cinfo->faction);
    }
}

bool Unit::CreateVehicleKit(uint32 id, uint32 creatureEntry, bool loading /*= false*/)
{
    VehicleEntry const* vehInfo = sVehicleStore.LookupEntry(id);
    if (!vehInfo)
        return false;

    m_vehicleKit = Trinity::make_unique_trackable<Vehicle>(this, vehInfo, creatureEntry);
    m_updateFlag.Vehicle = true;
    m_unitTypeMask |= UNIT_MASK_VEHICLE;

    if (!loading)
        SendSetVehicleRecId(id);

    return true;
}

void Unit::RemoveVehicleKit(bool onRemoveFromWorld /*= false*/)
{
    if (!m_vehicleKit)
        return;

    if (!onRemoveFromWorld)
        SendSetVehicleRecId(0);

    m_vehicleKit->Uninstall();
    m_vehicleKit = nullptr;

    m_updateFlag.Vehicle = false;
    m_unitTypeMask &= ~UNIT_MASK_VEHICLE;
    RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK | UNIT_NPC_FLAG_PLAYER_VEHICLE);
}

bool Unit::IsOnVehicle(Unit const* vehicle) const
{
    return m_vehicle && m_vehicle == vehicle->GetVehicleKit();
}

Unit* Unit::GetVehicleBase() const
{
    return m_vehicle ? m_vehicle->GetBase() : nullptr;
}

Unit* Unit::GetVehicleRoot() const
{
    Unit* vehicleRoot = GetVehicleBase();

    if (!vehicleRoot)
        return nullptr;

    for (;;)
    {
        if (!vehicleRoot->GetVehicleBase())
            return vehicleRoot;

        vehicleRoot = vehicleRoot->GetVehicleBase();
    }
}

Creature* Unit::GetVehicleCreatureBase() const
{
    if (Unit* veh = GetVehicleBase())
        if (Creature* c = veh->ToCreature())
            return c;

    return nullptr;
}

ObjectGuid Unit::GetTransGUID() const
{
    if (GetVehicle())
        return GetVehicleBase()->GetGUID();
    if (GetTransport())
        return GetTransport()->GetTransportGUID();

    return ObjectGuid::Empty;
}

TransportBase* Unit::GetDirectTransport() const
{
    if (Vehicle* veh = GetVehicle())
        return veh;
    return GetTransport();
}

bool Unit::IsInPartyWith(Unit const* unit) const
{
    if (this == unit)
        return true;

    Unit const* u1 = GetCharmerOrOwnerOrSelf();
    Unit const* u2 = unit->GetCharmerOrOwnerOrSelf();
    if (u1 == u2)
        return true;

    if (u1->GetTypeId() == TYPEID_PLAYER && u2->GetTypeId() == TYPEID_PLAYER)
        return u1->ToPlayer()->IsInSameGroupWith(u2->ToPlayer());
    else if ((u2->GetTypeId() == TYPEID_PLAYER && u1->GetTypeId() == TYPEID_UNIT && u1->ToCreature()->IsTreatedAsRaidUnit()) ||
        (u1->GetTypeId() == TYPEID_PLAYER && u2->GetTypeId() == TYPEID_UNIT && u2->ToCreature()->IsTreatedAsRaidUnit()))
        return true;

    return u1->GetTypeId() == TYPEID_UNIT && u2->GetTypeId() == TYPEID_UNIT && u1->GetFaction() == u2->GetFaction();
}

bool Unit::IsInRaidWith(Unit const* unit) const
{
    if (this == unit)
        return true;

    Unit const* u1 = GetCharmerOrOwnerOrSelf();
    Unit const* u2 = unit->GetCharmerOrOwnerOrSelf();
    if (u1 == u2)
        return true;

    if (u1->GetTypeId() == TYPEID_PLAYER && u2->GetTypeId() == TYPEID_PLAYER)
        return u1->ToPlayer()->IsInSameRaidWith(u2->ToPlayer());
    else if ((u2->GetTypeId() == TYPEID_PLAYER && u1->GetTypeId() == TYPEID_UNIT && u1->ToCreature()->IsTreatedAsRaidUnit()) ||
            (u1->GetTypeId() == TYPEID_PLAYER && u2->GetTypeId() == TYPEID_UNIT && u2->ToCreature()->IsTreatedAsRaidUnit()))
        return true;

    return u1->GetTypeId() == TYPEID_UNIT && u2->GetTypeId() == TYPEID_UNIT && u1->GetFaction() == u2->GetFaction();
}

void Unit::GetPartyMembers(std::list<Unit*> &TagUnitMap)
{
    Unit* owner = GetCharmerOrOwnerOrSelf();
    Group* group = nullptr;
    if (owner->GetTypeId() == TYPEID_PLAYER)
        group = owner->ToPlayer()->GetGroup();

    if (group)
    {
        uint8 subgroup = owner->ToPlayer()->GetSubGroup();

        for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            Player* Target = itr->GetSource();

            // IsHostileTo check duel and controlled by enemy
            if (Target && Target->IsInMap(owner) && Target->GetSubGroup() == subgroup && !IsHostileTo(Target))
            {
                if (Target->IsAlive())
                    TagUnitMap.push_back(Target);

                if (Guardian* pet = Target->GetGuardianPet())
                    if (pet->IsAlive())
                        TagUnitMap.push_back(pet);
            }
        }
    }
    else
    {
        if ((owner == this || IsInMap(owner)) && owner->IsAlive())
            TagUnitMap.push_back(owner);
        if (Guardian* pet = owner->GetGuardianPet())
            if ((pet == this || IsInMap(pet)) && pet->IsAlive())
                TagUnitMap.push_back(pet);
    }
}

bool Unit::IsContestedGuard() const
{
    if (FactionTemplateEntry const* entry = GetFactionTemplateEntry())
        return entry->IsContestedGuardFaction();

    return false;
}

void Unit::SetPvP(bool state)
{
    if (state)
        SetPvpFlag(UNIT_BYTE2_FLAG_PVP);
    else
        RemovePvpFlag(UNIT_BYTE2_FLAG_PVP);
}

Aura* Unit::AddAura(uint32 spellId, Unit* target)
{
    if (!target)
        return nullptr;

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId, GetMap()->GetDifficultyID());
    if (!spellInfo)
        return nullptr;

    return AddAura(spellInfo, MAX_EFFECT_MASK, target);
}

Aura* Unit::AddAura(SpellInfo const* spellInfo, uint32 effMask, Unit* target)
{
    if (!spellInfo)
        return nullptr;

    if (!target->IsAlive() && !spellInfo->IsPassive() && !spellInfo->HasAttribute(SPELL_ATTR2_ALLOW_DEAD_TARGET))
        return nullptr;

    if (target->IsImmunedToSpell(spellInfo, this))
        return nullptr;

    for (SpellEffectInfo const& spellEffectInfo : spellInfo->GetEffects())
    {
        if (!(effMask & (1 << spellEffectInfo.EffectIndex)))
            continue;

        if (target->IsImmunedToSpellEffect(spellInfo, spellEffectInfo, this))
            effMask &= ~(1 << spellEffectInfo.EffectIndex);
    }

    if (!effMask)
        return nullptr;

    ObjectGuid castId = ObjectGuid::Create<HighGuid::Cast>(SPELL_CAST_SOURCE_NORMAL, GetMapId(), spellInfo->Id, GetMap()->GenerateLowGuid<HighGuid::Cast>());
    AuraCreateInfo createInfo(castId, spellInfo, GetMap()->GetDifficultyID(), effMask, target);
    createInfo.SetCaster(this);

    if (Aura* aura = Aura::TryRefreshStackOrCreate(createInfo))
    {
        aura->ApplyForTargets();
        return aura;
    }
    return nullptr;
}

void Unit::SetAuraStack(uint32 spellId, Unit* target, uint32 stack)
{
    Aura* aura = target->GetAura(spellId, GetGUID());
    if (!aura)
        aura = AddAura(spellId, target);
    if (aura && stack)
        aura->SetStackAmount(stack);
}

void Unit::SendPlaySpellVisual(Unit* target, uint32 spellVisualId, uint16 missReason, uint16 reflectStatus, float travelSpeed, bool speedAsTime /*= false*/, float launchDelay /*= 0.0f*/)
{
    WorldPackets::Spells::PlaySpellVisual playSpellVisual;
    playSpellVisual.Source = GetGUID();
    playSpellVisual.Target = target->GetGUID();
    playSpellVisual.TargetPosition = target->GetPosition();
    playSpellVisual.SpellVisualID = spellVisualId;
    playSpellVisual.TravelSpeed = travelSpeed;
    playSpellVisual.MissReason = missReason;
    playSpellVisual.ReflectStatus = reflectStatus;
    playSpellVisual.SpeedAsTime = speedAsTime;
    playSpellVisual.LaunchDelay = launchDelay;
    SendMessageToSet(playSpellVisual.Write(), true);
}

void Unit::SendPlaySpellVisual(Position const& targetPosition, uint32 spellVisualId, uint16 missReason, uint16 reflectStatus, float travelSpeed, bool speedAsTime /*= false*/, float launchDelay /*= 0.0f*/)
{
    WorldPackets::Spells::PlaySpellVisual playSpellVisual;
    playSpellVisual.Source = GetGUID();
    playSpellVisual.TargetPosition = targetPosition;
    playSpellVisual.SpellVisualID = spellVisualId;
    playSpellVisual.TravelSpeed = travelSpeed;
    playSpellVisual.MissReason = missReason;
    playSpellVisual.ReflectStatus = reflectStatus;
    playSpellVisual.SpeedAsTime = speedAsTime;
    playSpellVisual.LaunchDelay = launchDelay;
    SendMessageToSet(playSpellVisual.Write(), true);
}

void Unit::SendCancelSpellVisual(uint32 id)
{
    WorldPackets::Spells::CancelSpellVisual cancelSpellVisual;
    cancelSpellVisual.Source = GetGUID();
    cancelSpellVisual.SpellVisualID = id;
    SendMessageToSet(cancelSpellVisual.Write(), true);
}

void Unit::SendPlaySpellVisualKit(uint32 id, uint32 type, uint32 duration) const
{
    WorldPackets::Spells::PlaySpellVisualKit playSpellVisualKit;
    playSpellVisualKit.Unit = GetGUID();
    playSpellVisualKit.KitRecID = id;
    playSpellVisualKit.KitType = type;
    playSpellVisualKit.Duration = duration;
    SendMessageToSet(playSpellVisualKit.Write(), true);
}

void Unit::SendCancelSpellVisualKit(uint32 id)
{
    WorldPackets::Spells::CancelSpellVisualKit cancelSpellVisualKit;
    cancelSpellVisualKit.Source = GetGUID();
    cancelSpellVisualKit.SpellVisualKitID = id;
    SendMessageToSet(cancelSpellVisualKit.Write(), true);
}

void Unit::CancelSpellMissiles(uint32 spellId, bool reverseMissile /*= false*/, bool abortSpell /*= false*/)
{
    bool hasMissile = false;
    if (abortSpell)
    {
        for (std::pair<uint64 const, BasicEvent*> const& itr : m_Events.GetEvents())
        {
            if (Spell const* spell = Spell::ExtractSpellFromEvent(itr.second))
            {
                if (spell->GetSpellInfo()->Id == spellId)
                {
                    itr.second->ScheduleAbort();
                    hasMissile = true;
                }
            }
        }
    }
    else
        hasMissile = true;

    if (hasMissile)
    {
        WorldPackets::Spells::MissileCancel packet;
        packet.OwnerGUID = GetGUID();
        packet.SpellID = spellId;
        packet.Reverse = reverseMissile;
        SendMessageToSet(packet.Write(), false);
    }
}

bool Unit::CanApplyResilience() const
{
    return !IsVehicle() && GetOwnerGUID().IsPlayer();
}

/*static*/ void Unit::ApplyResilience(Unit const* victim, int32* damage)
{
    // player mounted on multi-passenger mount is also classified as vehicle
    if (victim->IsVehicle() && victim->GetTypeId() != TYPEID_PLAYER)
        return;

    Unit const* target = nullptr;
    if (victim->GetTypeId() == TYPEID_PLAYER)
        target = victim;
    else // victim->GetTypeId() == TYPEID_UNIT
    {
        if (Unit* owner = victim->GetOwner())
            if (owner->GetTypeId() == TYPEID_PLAYER)
                target = owner;
    }

    if (!target)
        return;

    *damage -= target->GetDamageReduction(*damage);
}

int32 Unit::CalculateAOEAvoidance(int32 damage, uint32 schoolMask, bool npcCaster) const
{
    damage = int32(float(damage) * GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_AOE_DAMAGE_AVOIDANCE, schoolMask));
    if (npcCaster)
        damage = int32(float(damage) * GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_CREATURE_AOE_DAMAGE_AVOIDANCE, schoolMask));

    return damage;
}

// Melee based spells can be miss, parry or dodge on this step
// Crit or block - determined on damage calculation phase! (and can be both in some time)
float Unit::MeleeSpellMissChance(Unit const* victim, WeaponAttackType attType, SpellInfo const* spellInfo) const
{
    if (spellInfo && spellInfo->HasAttribute(SPELL_ATTR7_NO_ATTACK_MISS))
        return 0.f;

    //calculate miss chance
    float missChance = victim->GetUnitMissChance();

    // melee attacks while dual wielding have +19% chance to miss
    if (!spellInfo && haveOffhandWeapon() && !IsInFeralForm() && !HasAuraType(SPELL_AURA_IGNORE_DUAL_WIELD_HIT_PENALTY))
        missChance += 19.0f;

    // Spellmod from SpellModOp::HitChance
    float resistMissChance = 100.0f;
    if (spellInfo)
        if (Player* modOwner = GetSpellModOwner())
            modOwner->ApplySpellMod(spellInfo, SpellModOp::HitChance, resistMissChance);

    missChance -= resistMissChance - 100.0f;

    if (attType == RANGED_ATTACK)
        missChance -= m_modRangedHitChance;
    else
        missChance -= m_modMeleeHitChance;

    // miss chance from auras after calculating skill based miss
    missChance -= GetTotalAuraModifier(SPELL_AURA_MOD_HIT_CHANCE);
    if (attType == RANGED_ATTACK)
        missChance -= victim->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_RANGED_HIT_CHANCE);
    else
        missChance -= victim->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_MELEE_HIT_CHANCE);

    return std::max(missChance, 0.f);
}

void Unit::OnPhaseChange()
{
}

void Unit::UpdateObjectVisibility(bool forced)
{
    if (!forced)
        AddToNotify(NOTIFY_VISIBILITY_CHANGED);
    else
    {
        WorldObject::UpdateObjectVisibility(true);
        // call MoveInLineOfSight for nearby creatures
        Trinity::AIRelocationNotifier notifier(*this);
        Cell::VisitAllObjects(this, notifier, GetVisibilityRange());
    }
}

void Unit::SendMoveKnockBack(Player* player, float speedXY, float speedZ, float vcos, float vsin)
{
    WorldPackets::Movement::MoveKnockBack moveKnockBack;
    moveKnockBack.MoverGUID = GetGUID();
    moveKnockBack.SequenceIndex = m_movementCounter++;
    moveKnockBack.Speeds.HorzSpeed = speedXY;
    moveKnockBack.Speeds.VertSpeed = speedZ;
    moveKnockBack.Direction = Position(vcos, vsin);
    player->GetSession()->SendPacket(moveKnockBack.Write());
}

void Unit::KnockbackFrom(Position const& origin, float speedXY, float speedZ, Movement::SpellEffectExtraData const* spellEffectExtraData /*= nullptr*/)
{
    Player* player = ToPlayer();
    if (!player)
    {
        if (Unit* charmer = GetCharmer())
        {
            player = charmer->ToPlayer();
            if (player && player->GetUnitBeingMoved() != this)
                player = nullptr;
        }
    }

    if (!player)
        GetMotionMaster()->MoveKnockbackFrom(origin, speedXY, speedZ, spellEffectExtraData);
    else
    {
        float o = GetPosition() == origin ? GetOrientation() + M_PI : origin.GetAbsoluteAngle(this);
        if (speedXY < 0)
        {
            speedXY = -speedXY;
            o = o - M_PI;
        }

        float vcos = std::cos(o);
        float vsin = std::sin(o);
        SendMoveKnockBack(player, speedXY, -speedZ, vcos, vsin);
    }
}

float Unit::GetCombatRatingReduction(CombatRating cr) const
{
    if (Player const* player = ToPlayer())
        return player->GetRatingBonusValue(cr);
    // Player's pet get resilience from owner
    else if (IsPet() && GetOwner())
        if (Player* owner = GetOwner()->ToPlayer())
            return owner->GetRatingBonusValue(cr);

    return 0.0f;
}

uint32 Unit::GetCombatRatingDamageReduction(CombatRating cr, float rate, float cap, uint32 damage) const
{
    float percent = std::min(GetCombatRatingReduction(cr) * rate, cap);
    return CalculatePct(damage, percent);
}

uint32 Unit::GetModelForForm(ShapeshiftForm form, uint32 spellId) const
{
    // Hardcoded cases
    switch (spellId)
    {
        case 7090: // Bear Form
            return 29414;
        case 35200: // Roc Form
            return 4877;
        case 24858: // Moonkin Form
        {
            if (HasAura(114301)) // Glyph of Stars
                return 0;
            break;
        }
        default:
            break;
    }

    if (Player const* player = ToPlayer())
    {
        if (Aura* artifactAura = GetAura(ARTIFACTS_ALL_WEAPONS_GENERAL_WEAPON_EQUIPPED_PASSIVE))
            if (Item* artifact = player->GetItemByGuid(artifactAura->GetCastItemGUID()))
                if (ArtifactAppearanceEntry const* artifactAppearance = sArtifactAppearanceStore.LookupEntry(artifact->GetModifier(ITEM_MODIFIER_ARTIFACT_APPEARANCE_ID)))
                    if (ShapeshiftForm(artifactAppearance->OverrideShapeshiftFormID) == form)
                        return artifactAppearance->OverrideShapeshiftDisplayID;

        if (ShapeshiftFormModelData const* formModelData = sDB2Manager.GetShapeshiftFormModelData(GetRace(), player->GetNativeGender(), form))
        {
            bool useRandom = false;
            switch (form)
            {
                case FORM_CAT_FORM:     useRandom = HasAura(210333); break; // Glyph of the Feral Chameleon
                case FORM_TRAVEL_FORM:  useRandom = HasAura(344336); break; // Glyph of the Swift Chameleon
                case FORM_AQUATIC_FORM: useRandom = HasAura(344338); break; // Glyph of the Aquatic Chameleon
                case FORM_BEAR_FORM:    useRandom = HasAura(107059); break; // Glyph of the Ursol Chameleon
                case FORM_FLIGHT_FORM_EPIC:
                case FORM_FLIGHT_FORM:  useRandom = HasAura(344342); break; // Glyph of the Aerial Chameleon
                default:
                    break;
            }

            if (useRandom)
            {
                std::vector<uint32> displayIds;
                displayIds.reserve(formModelData->Choices->size());

                for (std::size_t i = 0; i < formModelData->Choices->size(); ++i)
                {
                    if (ChrCustomizationDisplayInfoEntry const* displayInfo = formModelData->Displays[i])
                    {
                        ChrCustomizationReqEntry const* choiceReq = sChrCustomizationReqStore.LookupEntry((*formModelData->Choices)[i]->ChrCustomizationReqID);
                        if (!choiceReq || player->GetSession()->MeetsChrCustomizationReq(choiceReq, Races(GetRace()), Classes(GetClass()), false,
                            MakeChrCustomizationChoiceRange(player->m_playerData->Customizations)))
                            displayIds.push_back(displayInfo->DisplayID);
                    }
                }

                if (!displayIds.empty())
                    return Trinity::Containers::SelectRandomContainerElement(displayIds);
            }
            else
            {
                if (uint32 formChoice = player->GetCustomizationChoice(formModelData->OptionID))
                {
                    auto choiceItr = std::find_if(formModelData->Choices->begin(), formModelData->Choices->end(), [formChoice](ChrCustomizationChoiceEntry const* choice)
                    {
                        return choice->ID == formChoice;
                    });

                    if (choiceItr != formModelData->Choices->end())
                        if (ChrCustomizationDisplayInfoEntry const* displayInfo = formModelData->Displays[std::distance(formModelData->Choices->begin(), choiceItr)])
                            return displayInfo->DisplayID;
                }
            }
        }
        switch (form)
        {
            case FORM_GHOST_WOLF:
            {
                if (HasAura(58135)) // Glyph of Spectral Wolf
                    return 60247;
                break;
            }
            default:
                break;
        }
    }

    SpellShapeshiftFormEntry const* formEntry = sSpellShapeshiftFormStore.LookupEntry(form);
    if (formEntry && formEntry->CreatureDisplayID)
        return formEntry->CreatureDisplayID;

    return 0;
}

void Unit::JumpTo(float speedXY, float speedZ, float angle, Optional<Position> dest)
{
    if (dest)
        angle += GetRelativeAngle(*dest);

    if (GetTypeId() == TYPEID_UNIT)
        GetMotionMaster()->MoveJumpTo(angle, speedXY, speedZ);
    else
    {
        float vcos = std::cos(angle+GetOrientation());
        float vsin = std::sin(angle+GetOrientation());
        SendMoveKnockBack(ToPlayer(), speedXY, -speedZ, vcos, vsin);
    }
}

void Unit::JumpTo(WorldObject* obj, float speedZ, bool withOrientation)
{
    float x, y, z;
    obj->GetContactPoint(this, x, y, z);
    float speedXY = GetExactDist2d(x, y) * 10.0f / speedZ;
    GetMotionMaster()->MoveJump(x, y, z, GetAbsoluteAngle(obj), speedXY, speedZ, EVENT_JUMP, withOrientation);
}

void Unit::HandleSpellClick(Unit* clicker, int8 seatId /*= -1*/)
{
    bool spellClickHandled = false;
    uint32 spellClickEntry = GetVehicleKit() ? GetVehicleKit()->GetCreatureEntry() : GetEntry();
    TriggerCastFlags const flags = GetVehicleKit() ? TRIGGERED_IGNORE_CASTER_MOUNTED_OR_ON_VEHICLE : TRIGGERED_NONE;

    auto clickBounds = sObjectMgr->GetSpellClickInfoMapBounds(spellClickEntry);
    for (auto const& clickPair : clickBounds)
    {
        //! First check simple relations from clicker to clickee
        if (!clickPair.second.IsFitToRequirements(clicker, this))
            continue;

        //! Check database conditions
        if (!sConditionMgr->IsObjectMeetingSpellClickConditions(spellClickEntry, clickPair.second.spellId, clicker, this))
            continue;

        Unit* caster = (clickPair.second.castFlags & NPC_CLICK_CAST_CASTER_CLICKER) ? clicker : this;
        Unit* target = (clickPair.second.castFlags & NPC_CLICK_CAST_TARGET_CLICKER) ? clicker : this;
        ObjectGuid origCasterGUID = (clickPair.second.castFlags & NPC_CLICK_CAST_ORIG_CASTER_OWNER) ? GetOwnerGUID() : clicker->GetGUID();

        SpellInfo const* spellEntry = sSpellMgr->AssertSpellInfo(clickPair.second.spellId, caster->GetMap()->GetDifficultyID());
        // if (!spellEntry) should be checked at npc_spellclick load

        if (seatId > -1)
        {
            uint8 i = 0;
            bool valid = false;
            for (SpellEffectInfo const& spellEffectInfo : spellEntry->GetEffects())
            {
                if (spellEffectInfo.ApplyAuraName == SPELL_AURA_CONTROL_VEHICLE)
                {
                    valid = true;
                    break;
                }
                ++i;
            }

            if (!valid)
            {
                TC_LOG_ERROR("sql.sql", "Spell {} specified in npc_spellclick_spells is not a valid vehicle enter aura!", clickPair.second.spellId);
                continue;
            }

            if (IsInMap(caster))
            {
                CastSpellExtraArgs args(flags);
                args.OriginalCaster = origCasterGUID;
                args.AddSpellMod(SpellValueMod(SPELLVALUE_BASE_POINT0 + i), seatId + 1);
                caster->CastSpell(target, clickPair.second.spellId, args);
            }
            else    // This can happen during Player::_LoadAuras
            {
                int32 bp[MAX_SPELL_EFFECTS] = { };
                for (SpellEffectInfo const& spellEffectInfo : spellEntry->GetEffects())
                    bp[spellEffectInfo.EffectIndex] = int32(spellEffectInfo.BasePoints);

                bp[i] = seatId;

                AuraCreateInfo createInfo(ObjectGuid::Create<HighGuid::Cast>(SPELL_CAST_SOURCE_NORMAL, GetMapId(), spellEntry->Id, GetMap()->GenerateLowGuid<HighGuid::Cast>()), spellEntry, GetMap()->GetDifficultyID(), MAX_EFFECT_MASK, this);
                createInfo
                    .SetCaster(clicker)
                    .SetBaseAmount(bp)
                    .SetCasterGUID(origCasterGUID);

                Aura::TryRefreshStackOrCreate(createInfo);
            }
        }
        else
        {
            if (IsInMap(caster))
                caster->CastSpell(target, spellEntry->Id, CastSpellExtraArgs().SetOriginalCaster(origCasterGUID));
            else
            {
                AuraCreateInfo createInfo(ObjectGuid::Create<HighGuid::Cast>(SPELL_CAST_SOURCE_NORMAL, GetMapId(), spellEntry->Id, GetMap()->GenerateLowGuid<HighGuid::Cast>()), spellEntry, GetMap()->GetDifficultyID(), MAX_EFFECT_MASK, this);
                createInfo
                    .SetCaster(clicker)
                    .SetCasterGUID(origCasterGUID);

                Aura::TryRefreshStackOrCreate(createInfo);
            }
        }

        spellClickHandled = true;
    }

    Creature* creature = ToCreature();
    if (creature && creature->IsAIEnabled())
        creature->AI()->OnSpellClick(clicker, spellClickHandled);
}

void Unit::EnterVehicle(Unit* base, int8 seatId /*= -1*/)
{
    CastSpellExtraArgs args(TRIGGERED_IGNORE_CASTER_MOUNTED_OR_ON_VEHICLE);
    args.AddSpellMod(SPELLVALUE_BASE_POINT0, seatId + 1);
    CastSpell(base, VEHICLE_SPELL_RIDE_HARDCODED, args);
}

void Unit::_EnterVehicle(Vehicle* vehicle, int8 seatId, AuraApplication const* aurApp)
{
    // Must be called only from aura handler
    ASSERT(aurApp);

    if (!IsAlive() || GetVehicleKit() == vehicle || vehicle->GetBase()->IsOnVehicle(this))
        return;

    if (m_vehicle)
    {
        if (m_vehicle != vehicle)
        {
            TC_LOG_DEBUG("entities.vehicle", "EnterVehicle: {} exit {} and enter {}.", GetEntry(), m_vehicle->GetBase()->GetEntry(), vehicle->GetBase()->GetEntry());
            ExitVehicle();
        }
        else if (seatId >= 0 && seatId == GetTransSeat())
            return;
        else
        {
            //Exit the current vehicle because unit will reenter in a new seat.
            m_vehicle->GetBase()->RemoveAurasByType(SPELL_AURA_CONTROL_VEHICLE, GetGUID(), aurApp->GetBase());
        }
    }

    if (aurApp->GetRemoveMode())
        return;

    if (Player* player = ToPlayer())
    {
        if (vehicle->GetBase()->GetTypeId() == TYPEID_PLAYER && player->IsInCombat())
        {
            vehicle->GetBase()->RemoveAura(const_cast<AuraApplication*>(aurApp));
            return;
        }

        if (vehicle->GetBase()->GetTypeId() == TYPEID_UNIT)
        {
            // If a player entered a vehicle that is part of a formation, remove it from said formation
            if (CreatureGroup* creatureGroup = vehicle->GetBase()->ToCreature()->GetFormation())
                creatureGroup->RemoveMember(vehicle->GetBase()->ToCreature());
        }
    }

    ASSERT(!m_vehicle);
    (void)vehicle->AddVehiclePassenger(this, seatId);
}

void Unit::ChangeSeat(int8 seatId, bool next)
{
    if (!m_vehicle)
        return;

    // Don't change if current and new seat are identical
    if (seatId == GetTransSeat())
        return;

    SeatMap::const_iterator seat = (seatId < 0 ? m_vehicle->GetNextEmptySeat(GetTransSeat(), next) : m_vehicle->Seats.find(seatId));
    // The second part of the check will only return true if seatId >= 0. @Vehicle::GetNextEmptySeat makes sure of that.
    if (seat == m_vehicle->Seats.end() || !seat->second.IsEmpty())
        return;

    AuraEffect* rideVehicleEffect = nullptr;
    AuraEffectList const& vehicleAuras = m_vehicle->GetBase()->GetAuraEffectsByType(SPELL_AURA_CONTROL_VEHICLE);
    for (AuraEffectList::const_iterator itr = vehicleAuras.begin(); itr != vehicleAuras.end(); ++itr)
    {
        if ((*itr)->GetCasterGUID() != GetGUID())
            continue;

        // Make sure there is only one ride vehicle aura on target cast by the unit changing seat
        ASSERT(!rideVehicleEffect);
        rideVehicleEffect = *itr;
    }

    // Unit riding a vehicle must always have control vehicle aura on target
    ASSERT(rideVehicleEffect);

    rideVehicleEffect->ChangeAmount(seat->first + 1);
}

void Unit::ExitVehicle(Position const* /*exitPosition*/)
{
    //! This function can be called at upper level code to initialize an exit from the passenger's side.
    if (!m_vehicle)
        return;

    GetVehicleBase()->RemoveAurasByType(SPELL_AURA_CONTROL_VEHICLE, GetGUID());
    //! The following call would not even be executed successfully as the
    //! SPELL_AURA_CONTROL_VEHICLE unapply handler already calls _ExitVehicle without
    //! specifying an exitposition. The subsequent call below would return on if (!m_vehicle).
    /*_ExitVehicle(exitPosition);*/
    //! To do:
    //! We need to allow SPELL_AURA_CONTROL_VEHICLE unapply handlers in spellscripts
    //! to specify exit coordinates and either store those per passenger, or we need to
    //! init spline movement based on those coordinates in unapply handlers, and
    //! relocate exiting passengers based on Unit::moveSpline data. Either way,
    //! Coming Soon(TM)
}

void Unit::_ExitVehicle(Position const* exitPosition)
{
    /// It's possible m_vehicle is NULL, when this function is called indirectly from @VehicleJoinEvent::Abort.
    /// In that case it was not possible to add the passenger to the vehicle. The vehicle aura has already been removed
    /// from the target in the aforementioned function and we don't need to do anything else at this point.
    if (!m_vehicle)
        return;

    // This should be done before dismiss, because there may be some aura removal
    VehicleSeatAddon const* seatAddon = m_vehicle->GetSeatAddonForSeatOfPassenger(this);
    Vehicle* vehicle = m_vehicle->RemovePassenger(this);

    if (!vehicle)
    {
        TC_LOG_ERROR("entities.vehicle", "RemovePassenger() couldn't remove current unit from vehicle. Debug info: {}", GetDebugInfo());
        return;
    }

    Player* player = ToPlayer();

    // If the player is on mounted duel and exits the mount, he should immediatly lose the duel
    if (player && player->duel && player->duel->IsMounted)
        player->DuelComplete(DUEL_FLED);

    SetControlled(false, UNIT_STATE_ROOT);      // SMSG_MOVE_FORCE_UNROOT, ~MOVEMENTFLAG_ROOT

    AddUnitState(UNIT_STATE_MOVE);

    if (player)
        player->SetFallInformation(0, GetPositionZ());

    Position pos;
    // If we ask for a specific exit position, use that one. Otherwise allow scripts to modify it
    if (exitPosition)
        pos = *exitPosition;
    else
    {
        // Set exit position to vehicle position and use the current orientation
        pos = vehicle->GetBase()->GetPosition();
        pos.SetOrientation(GetOrientation());

        // Change exit position based on seat entry addon data
        if (seatAddon)
        {
            if (seatAddon->ExitParameter == VehicleExitParameters::VehicleExitParamOffset)
                pos.RelocateOffset({ seatAddon->ExitParameterX, seatAddon->ExitParameterY, seatAddon->ExitParameterZ, seatAddon->ExitParameterO });
            else if (seatAddon->ExitParameter == VehicleExitParameters::VehicleExitParamDest)
                pos.Relocate({ seatAddon->ExitParameterX, seatAddon->ExitParameterY, seatAddon->ExitParameterZ, seatAddon->ExitParameterO });
        }
    }

    std::function<void(Movement::MoveSplineInit&)> initializer = [=, this, vehicleCollisionHeight = vehicle->GetBase()->GetCollisionHeight()](Movement::MoveSplineInit& init)
    {
        float height = pos.GetPositionZ() + vehicleCollisionHeight;

        // Creatures without inhabit type air should begin falling after exiting the vehicle
        if (GetTypeId() == TYPEID_UNIT && !CanFly() && height > GetMap()->GetWaterOrGroundLevel(GetPhaseShift(), pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ() + vehicleCollisionHeight, &height))
            init.SetFall();

        init.MoveTo(pos.GetPositionX(), pos.GetPositionY(), height, false);
        init.SetFacing(pos.GetOrientation());
        init.SetTransportExit();
    };
    GetMotionMaster()->LaunchMoveSpline(std::move(initializer), EVENT_VEHICLE_EXIT, MOTION_PRIORITY_HIGHEST);

    if (player)
        player->ResummonPetTemporaryUnSummonedIfAny();

    if (vehicle->GetBase()->HasUnitTypeMask(UNIT_MASK_MINION) && vehicle->GetBase()->GetTypeId() == TYPEID_UNIT)
        if (((Minion*)vehicle->GetBase())->GetOwner() == this)
            vehicle->GetBase()->ToCreature()->DespawnOrUnsummon(vehicle->GetDespawnDelay());

    if (HasUnitTypeMask(UNIT_MASK_ACCESSORY))
    {
        // Vehicle just died, we die too
        if (vehicle->GetBase()->getDeathState() == JUST_DIED)
            setDeathState(JUST_DIED);
        // If for other reason we as minion are exiting the vehicle (ejected, master dismounted) - unsummon
        else
            ToTempSummon()->UnSummon(2000); // Approximation
    }

    RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags2::AbandonVehicle);
}

bool Unit::IsFalling() const
{
    return m_movementInfo.HasMovementFlag(MOVEMENTFLAG_FALLING | MOVEMENTFLAG_FALLING_FAR) || movespline->isFalling();
}

bool Unit::CanSwim() const
{
    // Mirror client behavior, if this method returns false then client will not use swimming animation and for players will apply gravity as if there was no water
    if (HasUnitFlag(UNIT_FLAG_CANT_SWIM))
        return false;
    if (HasUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED)) // is player
        return true;
    if (HasUnitFlag2(UNIT_FLAG2_AI_WILL_ONLY_SWIM_IF_TARGET_SWIMS))
        return false;
    if (HasUnitFlag(UNIT_FLAG_PET_IN_COMBAT))
        return true;
    return HasUnitFlag(UNIT_FLAG_RENAME | UNIT_FLAG_CAN_SWIM);
}

void Unit::NearTeleportTo(Position const& pos, bool casting /*= false*/)
{
    DisableSpline();
    if (GetTypeId() == TYPEID_PLAYER)
    {
        WorldLocation target(GetMapId(), pos);
        ToPlayer()->TeleportTo(target, TELE_TO_NOT_LEAVE_TRANSPORT | TELE_TO_NOT_LEAVE_COMBAT | TELE_TO_NOT_UNSUMMON_PET | (casting ? TELE_TO_SPELL : TELE_TO_NONE));
    }
    else
    {
        SendTeleportPacket(pos);
        UpdatePosition(pos, true);
        UpdateObjectVisibility();
    }
}

void Unit::SendTeleportPacket(Position const& pos)
{
    // SMSG_MOVE_UPDATE_TELEPORT is sent to nearby players to signal the teleport
    // SMSG_MOVE_TELEPORT is sent to self in order to trigger CMSG_MOVE_TELEPORT_ACK and update the position server side

    WorldPackets::Movement::MoveUpdateTeleport moveUpdateTeleport;
    moveUpdateTeleport.Status = &m_movementInfo;
    if (_movementForces)
        moveUpdateTeleport.MovementForces = _movementForces->GetForces();
    Unit* broadcastSource = this;

    // should this really be the unit _being_ moved? not the unit doing the moving?
    if (Player* playerMover = Unit::ToPlayer(GetUnitBeingMoved()))
    {
        float x, y, z, o;
        pos.GetPosition(x, y, z, o);
        if (TransportBase* transportBase = GetDirectTransport())
            transportBase->CalculatePassengerOffset(x, y, z, &o);

        WorldPackets::Movement::MoveTeleport moveTeleport;
        moveTeleport.MoverGUID = GetGUID();
        moveTeleport.Pos = Position(x, y, z);
        moveTeleport.TransportGUID = GetTransGUID();
        moveTeleport.Facing = o;
        moveTeleport.SequenceIndex = m_movementCounter++;
        playerMover->SendDirectMessage(moveTeleport.Write());

        broadcastSource = playerMover;
    }
    else
    {
        // This is the only packet sent for creatures which contains MovementInfo structure
        // we do not update m_movementInfo for creatures so it needs to be done manually here
        moveUpdateTeleport.Status->guid = GetGUID();
        moveUpdateTeleport.Status->pos.Relocate(pos);
        moveUpdateTeleport.Status->time = getMSTime();
        if (TransportBase* transportBase = GetDirectTransport())
        {
            float tx, ty, tz, to;
            pos.GetPosition(tx, ty, tz, to);
            transportBase->CalculatePassengerOffset(tx, ty, tz, &to);
            moveUpdateTeleport.Status->transport.pos.Relocate(tx, ty, tz, to);
        }
    }

    // Broadcast the packet to everyone except self.
    broadcastSource->SendMessageToSet(moveUpdateTeleport.Write(), false);
}

bool Unit::UpdatePosition(float x, float y, float z, float orientation, bool teleport)
{
    // prevent crash when a bad coord is sent by the client
    if (!Trinity::IsValidMapCoord(x, y, z, orientation))
    {
        TC_LOG_DEBUG("entities.unit", "Unit::UpdatePosition({}, {}, {}) .. bad coordinates!", x, y, z);
        return false;
    }

    // Check if angular distance changed
    bool const turn = G3D::fuzzyGt(M_PI - fabs(fabs(GetOrientation() - orientation) - M_PI), 0.0f);

    // G3D::fuzzyEq won't help here, in some cases magnitudes differ by a little more than G3D::eps, but should be considered equal
    bool const relocated = (teleport ||
        std::fabs(GetPositionX() - x) > 0.001f ||
        std::fabs(GetPositionY() - y) > 0.001f ||
        std::fabs(GetPositionZ() - z) > 0.001f);

    if (relocated)
    {
        // move and update visible state if need
        if (GetTypeId() == TYPEID_PLAYER)
            GetMap()->PlayerRelocation(ToPlayer(), x, y, z, orientation);
        else
            GetMap()->CreatureRelocation(ToCreature(), x, y, z, orientation);
    }
    else if (turn)
        UpdateOrientation(orientation);

    _positionUpdateInfo.Relocated = relocated;
    _positionUpdateInfo.Turned = turn;

    if (IsFalling())
        RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags2::Falling);

    bool isInWater = IsInWater();
    if (!IsFalling() || isInWater || IsFlying())
        RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags2::Ground);

    if (isInWater)
        RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags2::Swimming);

    // TODO: on heartbeat
    if (m_vignette)
        Vignettes::Update(*m_vignette, this);

    return (relocated || turn);
}

bool Unit::UpdatePosition(Position const& pos, bool teleport)
{
    return UpdatePosition(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation(), teleport);
}

//! Only server-side orientation update, does not broadcast to client
void Unit::UpdateOrientation(float orientation)
{
    SetOrientation(orientation);
    if (IsVehicle())
        GetVehicleKit()->RelocatePassengers();
}

//! Only server-side height update, does not broadcast to client
void Unit::UpdateHeight(float newZ)
{
    Relocate(GetPositionX(), GetPositionY(), newZ);
    if (IsVehicle())
        GetVehicleKit()->RelocatePassengers();
}

// baseRage means damage taken when attacker = false
void Unit::RewardRage(uint32 baseRage)
{
    float addRage = baseRage;

    // talent who gave more rage on attack
    AddPct(addRage, GetTotalAuraModifier(SPELL_AURA_MOD_RAGE_FROM_DAMAGE_DEALT));

    addRage *= sWorld->getRate(RATE_POWER_RAGE_INCOME);

    ModifyPower(POWER_RAGE, uint32(addRage * 10));
}

void Unit::StopAttackFaction(uint32 faction_id)
{
    if (Unit* victim = GetVictim())
    {
        if (victim->GetFactionTemplateEntry()->Faction == faction_id)
        {
            AttackStop();
            if (IsNonMeleeSpellCast(false))
                InterruptNonMeleeSpells(false);

            // melee and ranged forced attack cancel
            if (GetTypeId() == TYPEID_PLAYER)
                ToPlayer()->SendAttackSwingCancelAttack();
        }
    }

    AttackerSet const& attackers = getAttackers();
    for (AttackerSet::const_iterator itr = attackers.begin(); itr != attackers.end();)
    {
        if ((*itr)->GetFactionTemplateEntry()->Faction == faction_id)
        {
            (*itr)->AttackStop();
            itr = attackers.begin();
        }
        else
            ++itr;
    }

    std::vector<CombatReference*> refsToEnd;
    for (auto const& pair : m_combatManager.GetPvECombatRefs())
        if (pair.second->GetOther(this)->GetFactionTemplateEntry()->Faction == faction_id)
            refsToEnd.push_back(pair.second);
    for (CombatReference* ref : refsToEnd)
        ref->EndCombat();

    for (Unit* minion : m_Controlled)
        minion->StopAttackFaction(faction_id);
}

void Unit::OutDebugInfo() const
{
    TC_LOG_ERROR("entities.unit", "Unit::OutDebugInfo");
    TC_LOG_DEBUG("entities.unit", "{} name {}", GetGUID().ToString(), GetName());
    TC_LOG_DEBUG("entities.unit", "Owner {}, Minion {}, Charmer {}, Charmed {}", GetOwnerGUID().ToString(), GetMinionGUID().ToString(), GetCharmerGUID().ToString(), GetCharmedGUID().ToString());
    TC_LOG_DEBUG("entities.unit", "In world {}, unit type mask {}", (uint32)(IsInWorld() ? 1 : 0), m_unitTypeMask);
    if (IsInWorld())
        TC_LOG_DEBUG("entities.unit", "Mapid {}", GetMapId());

    std::ostringstream o;
    o << "Summon Slot: ";
    for (uint32 i = 0; i < MAX_SUMMON_SLOT; ++i)
        o << m_SummonSlot[i].ToString() << ", ";

    TC_LOG_DEBUG("entities.unit", "{}", o.str());
    o.str("");

    o << "Controlled List: ";
    for (ControlList::const_iterator itr = m_Controlled.begin(); itr != m_Controlled.end(); ++itr)
        o << (*itr)->GetGUID().ToString() << ", ";
    TC_LOG_DEBUG("entities.unit", "{}", o.str());
    o.str("");

    o << "Aura List: ";
    for (AuraApplicationMap::const_iterator itr = m_appliedAuras.begin(); itr != m_appliedAuras.end(); ++itr)
        o << itr->first << ", ";
    TC_LOG_DEBUG("entities.unit", "{}", o.str());
    o.str("");

    if (IsVehicle())
    {
        o << "Passenger List: ";
        for (SeatMap::iterator itr = GetVehicleKit()->Seats.begin(); itr != GetVehicleKit()->Seats.end(); ++itr)
            if (Unit* passenger = ObjectAccessor::GetUnit(*GetVehicleBase(), itr->second.Passenger.Guid))
                o << passenger->GetGUID().ToString() << ", ";
        TC_LOG_DEBUG("entities.unit", "{}", o.str());
    }

    if (GetVehicle())
        TC_LOG_DEBUG("entities.unit", "On vehicle {}.", GetVehicleBase()->GetEntry());
}

void Unit::SendClearTarget()
{
    WorldPackets::Combat::BreakTarget breakTarget;
    breakTarget.UnitGUID = GetGUID();
    SendMessageToSet(breakTarget.Write(), false);
}

int32 Unit::GetResistance(SpellSchoolMask mask) const
{
    Optional<int32> resist;
    for (int32 i = SPELL_SCHOOL_NORMAL; i < MAX_SPELL_SCHOOL; ++i)
    {
        int32 schoolResistance = GetResistance(SpellSchools(i));
        if (mask & (1 << i) && (!resist || *resist > schoolResistance))
            resist = schoolResistance;
    }

    return resist.value_or(0);
}

void CharmInfo::SetIsCommandAttack(bool val)
{
    _isCommandAttack = val;
}

bool CharmInfo::IsCommandAttack()
{
    return _isCommandAttack;
}

void CharmInfo::SetIsCommandFollow(bool val)
{
    _isCommandFollow = val;
}

bool CharmInfo::IsCommandFollow()
{
    return _isCommandFollow;
}

void CharmInfo::SaveStayPosition()
{
    //! At this point a new spline destination is enabled because of Unit::StopMoving()
    G3D::Vector3 stayPos = _unit->movespline->FinalDestination();

    if (_unit->movespline->onTransport)
        if (TransportBase* transport = _unit->GetDirectTransport())
            transport->CalculatePassengerPosition(stayPos.x, stayPos.y, stayPos.z);

    _stayX = stayPos.x;
    _stayY = stayPos.y;
    _stayZ = stayPos.z;
}

void CharmInfo::GetStayPosition(float &x, float &y, float &z)
{
    x = _stayX;
    y = _stayY;
    z = _stayZ;
}

void CharmInfo::SetIsAtStay(bool val)
{
    _isAtStay = val;
}

bool CharmInfo::IsAtStay()
{
    return _isAtStay;
}

void CharmInfo::SetIsFollowing(bool val)
{
    _isFollowing = val;
}

bool CharmInfo::IsFollowing()
{
    return _isFollowing;
}

void CharmInfo::SetIsReturning(bool val)
{
    _isReturning = val;
}

bool CharmInfo::IsReturning()
{
    return _isReturning;
}

void Unit::SetInFront(WorldObject const* target)
{
    if (!HasUnitState(UNIT_STATE_CANNOT_TURN))
        SetOrientation(GetAbsoluteAngle(target));
}

void Unit::SetFacingTo(float ori, bool force)
{
    // do not face when already moving
    if (!force && (!IsStopped() || !movespline->Finalized()))
        return;

    Movement::MoveSplineInit init(this);
    init.MoveTo(GetPositionX(), GetPositionY(), GetPositionZ(), false);
    if (GetTransport())
        init.DisableTransportPathTransformations(); // It makes no sense to target global orientation
    init.SetFacing(ori);

    //GetMotionMaster()->LaunchMoveSpline(std::move(init), EVENT_FACE, MOTION_PRIORITY_HIGHEST);
    UpdateSplineMovement(init.Launch());
    if (Creature* creature = ToCreature())
        creature->AI()->MovementInform(EFFECT_MOTION_TYPE, EVENT_FACE);
}

void Unit::SetFacingToObject(WorldObject const* object, bool force)
{
    // do not face when already moving
    if (!force && (!IsStopped() || !movespline->Finalized()))
        return;

    /// @todo figure out under what conditions creature will move towards object instead of facing it where it currently is.
    Movement::MoveSplineInit init(this);
    init.MoveTo(GetPositionX(), GetPositionY(), GetPositionZ(), false);
    init.SetFacing(GetAbsoluteAngle(object));   // when on transport, GetAbsoluteAngle will still return global coordinates (and angle) that needs transforming

    //GetMotionMaster()->LaunchMoveSpline(std::move(init), EVENT_FACE, MOTION_PRIORITY_HIGHEST);
    UpdateSplineMovement(init.Launch());
    if (Creature* creature = ToCreature())
        creature->AI()->MovementInform(EFFECT_MOTION_TYPE, EVENT_FACE);
}

void Unit::SetFacingToPoint(Position const& point, bool force)
{
    // do not face when already moving
    if (!force && (!IsStopped() || !movespline->Finalized()))
        return;

    /// @todo figure out under what conditions creature will move towards object instead of facing it where it currently is.
    Movement::MoveSplineInit init(this);
    init.MoveTo(GetPositionX(), GetPositionY(), GetPositionZ(), false);
    if (GetTransport())
        init.DisableTransportPathTransformations(); // It makes no sense to target global orientation
    init.SetFacing(point.GetPositionX(), point.GetPositionY(), point.GetPositionZ());

    //GetMotionMaster()->LaunchMoveSpline(std::move(init), EVENT_FACE, MOTION_PRIORITY_HIGHEST);
    UpdateSplineMovement(init.Launch());
    if (Creature* creature = ToCreature())
        creature->AI()->MovementInform(EFFECT_MOTION_TYPE, EVENT_FACE);
}

bool Unit::SetWalk(bool enable)
{
    if (enable == IsWalking())
        return false;

    if (enable)
        AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
    else
        RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);

    static OpcodeServer const walkModeTable[2] = { SMSG_MOVE_SPLINE_SET_RUN_MODE, SMSG_MOVE_SPLINE_SET_WALK_MODE };

    WorldPackets::Movement::MoveSplineSetFlag packet(walkModeTable[enable]);
    packet.MoverGUID = GetGUID();
    SendMessageToSet(packet.Write(), true);
    return true;
}

bool Unit::SetDisableGravity(bool disable, bool updateAnimTier /*= true*/)
{
    if (disable == IsGravityDisabled())
        return false;

    if (disable)
    {
        AddUnitMovementFlag(MOVEMENTFLAG_DISABLE_GRAVITY);
        RemoveUnitMovementFlag(MOVEMENTFLAG_SWIMMING | MOVEMENTFLAG_SPLINE_ELEVATION);
    }
    else
        RemoveUnitMovementFlag(MOVEMENTFLAG_DISABLE_GRAVITY);

    static OpcodeServer const gravityOpcodeTable[2][2] =
    {
        { SMSG_MOVE_SPLINE_ENABLE_GRAVITY,  SMSG_MOVE_ENABLE_GRAVITY  },
        { SMSG_MOVE_SPLINE_DISABLE_GRAVITY, SMSG_MOVE_DISABLE_GRAVITY }
    };

    if (Player* playerMover = Unit::ToPlayer(GetUnitBeingMoved()))
    {
        WorldPackets::Movement::MoveSetFlag packet(gravityOpcodeTable[disable][1]);
        packet.MoverGUID = GetGUID();
        packet.SequenceIndex = m_movementCounter++;
        playerMover->SendDirectMessage(packet.Write());

        WorldPackets::Movement::MoveUpdate moveUpdate;
        moveUpdate.Status = &m_movementInfo;
        SendMessageToSet(moveUpdate.Write(), playerMover);
    }
    else
    {
        WorldPackets::Movement::MoveSplineSetFlag packet(gravityOpcodeTable[disable][0]);
        packet.MoverGUID = GetGUID();
        SendMessageToSet(packet.Write(), true);
    }

    if (IsCreature() && updateAnimTier && IsAlive() && !HasUnitState(UNIT_STATE_ROOT))
    {
        if (IsGravityDisabled())
            SetAnimTier(AnimTier::Fly);
        else if (IsHovering())
            SetAnimTier(AnimTier::Hover);
        else
            SetAnimTier(AnimTier::Ground);
    }

    if (IsAlive())
    {
        if (IsGravityDisabled() || IsHovering())
            SetPlayHoverAnim(true);
        else
            SetPlayHoverAnim(false);
    }
    else if (IsPlayer()) // To update player who dies while flying/hovering
        SetPlayHoverAnim(false, false);

    return true;
}

bool Unit::SetFall(bool enable)
{
    if (enable == HasUnitMovementFlag(MOVEMENTFLAG_FALLING))
        return false;

    if (enable)
    {
        AddUnitMovementFlag(MOVEMENTFLAG_FALLING);
        m_movementInfo.SetFallTime(0);
    }
    else
        RemoveUnitMovementFlag(MOVEMENTFLAG_FALLING | MOVEMENTFLAG_FALLING_FAR);

    return true;
}

bool Unit::SetSwim(bool enable)
{
    if (enable == HasUnitMovementFlag(MOVEMENTFLAG_SWIMMING))
        return false;

    if (enable)
        AddUnitMovementFlag(MOVEMENTFLAG_SWIMMING);
    else
        RemoveUnitMovementFlag(MOVEMENTFLAG_SWIMMING);

    static OpcodeServer const swimOpcodeTable[2] = { SMSG_MOVE_SPLINE_STOP_SWIM, SMSG_MOVE_SPLINE_START_SWIM};

    WorldPackets::Movement::MoveSplineSetFlag packet(swimOpcodeTable[enable]);
    packet.MoverGUID = GetGUID();
    SendMessageToSet(packet.Write(), true);

    return true;
}

bool Unit::SetCanFly(bool enable)
{
    if (enable == HasUnitMovementFlag(MOVEMENTFLAG_CAN_FLY))
        return false;

    if (enable)
    {
        AddUnitMovementFlag(MOVEMENTFLAG_CAN_FLY);
        RemoveUnitMovementFlag(MOVEMENTFLAG_SWIMMING | MOVEMENTFLAG_SPLINE_ELEVATION);
    }
    else
        RemoveUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_MASK_MOVING_FLY);

    static OpcodeServer const flyOpcodeTable[2][2] =
    {
        { SMSG_MOVE_SPLINE_UNSET_FLYING, SMSG_MOVE_UNSET_CAN_FLY },
        { SMSG_MOVE_SPLINE_SET_FLYING,   SMSG_MOVE_SET_CAN_FLY   }
    };

    if (!enable && GetTypeId() == TYPEID_PLAYER)
        ToPlayer()->SetFallInformation(0, GetPositionZ());

    if (Player* playerMover = Unit::ToPlayer(GetUnitBeingMoved()))
    {
        WorldPackets::Movement::MoveSetFlag packet(flyOpcodeTable[enable][1]);
        packet.MoverGUID = GetGUID();
        packet.SequenceIndex = m_movementCounter++;
        playerMover->SendDirectMessage(packet.Write());

        WorldPackets::Movement::MoveUpdate moveUpdate;
        moveUpdate.Status = &m_movementInfo;
        SendMessageToSet(moveUpdate.Write(), playerMover);
    }
    else
    {
        WorldPackets::Movement::MoveSplineSetFlag packet(flyOpcodeTable[enable][0]);
        packet.MoverGUID = GetGUID();
        SendMessageToSet(packet.Write(), true);
    }

    return true;
}

bool Unit::SetWaterWalking(bool enable)
{
    if (enable == HasUnitMovementFlag(MOVEMENTFLAG_WATERWALKING))
        return false;

    if (enable)
        AddUnitMovementFlag(MOVEMENTFLAG_WATERWALKING);
    else
        RemoveUnitMovementFlag(MOVEMENTFLAG_WATERWALKING);

    static OpcodeServer const waterWalkingOpcodeTable[2][2] =
    {
        { SMSG_MOVE_SPLINE_SET_LAND_WALK,  SMSG_MOVE_SET_LAND_WALK  },
        { SMSG_MOVE_SPLINE_SET_WATER_WALK, SMSG_MOVE_SET_WATER_WALK }
    };

    if (Player* playerMover = Unit::ToPlayer(GetUnitBeingMoved()))
    {
        WorldPackets::Movement::MoveSetFlag packet(waterWalkingOpcodeTable[enable][1]);
        packet.MoverGUID = GetGUID();
        packet.SequenceIndex = m_movementCounter++;
        playerMover->SendDirectMessage(packet.Write());

        WorldPackets::Movement::MoveUpdate moveUpdate;
        moveUpdate.Status = &m_movementInfo;
        SendMessageToSet(moveUpdate.Write(), playerMover);
    }
    else
    {
        WorldPackets::Movement::MoveSplineSetFlag packet(waterWalkingOpcodeTable[enable][0]);
        packet.MoverGUID = GetGUID();
        SendMessageToSet(packet.Write(), true);
    }

    return true;
}

bool Unit::SetFeatherFall(bool enable)
{
    // Temporarily disabled for short lived auras that unapply before client had time to ACK applying
    //if (enable == HasUnitMovementFlag(MOVEMENTFLAG_FALLING_SLOW))
    //    return false;

    if (enable)
        AddUnitMovementFlag(MOVEMENTFLAG_FALLING_SLOW);
    else
        RemoveUnitMovementFlag(MOVEMENTFLAG_FALLING_SLOW);

    static OpcodeServer const featherFallOpcodeTable[2][2] =
    {
        { SMSG_MOVE_SPLINE_SET_NORMAL_FALL,  SMSG_MOVE_SET_NORMAL_FALL  },
        { SMSG_MOVE_SPLINE_SET_FEATHER_FALL, SMSG_MOVE_SET_FEATHER_FALL }
    };

    if (Player* playerMover = Unit::ToPlayer(GetUnitBeingMoved()))
    {
        WorldPackets::Movement::MoveSetFlag packet(featherFallOpcodeTable[enable][1]);
        packet.MoverGUID = GetGUID();
        packet.SequenceIndex = m_movementCounter++;
        playerMover->SendDirectMessage(packet.Write());

        WorldPackets::Movement::MoveUpdate moveUpdate;
        moveUpdate.Status = &m_movementInfo;
        SendMessageToSet(moveUpdate.Write(), playerMover);
    }
    else
    {
        WorldPackets::Movement::MoveSplineSetFlag packet(featherFallOpcodeTable[enable][0]);
        packet.MoverGUID = GetGUID();
        SendMessageToSet(packet.Write(), true);
    }

    return true;
}

bool Unit::SetHover(bool enable, bool updateAnimTier /*= true*/)
{
    if (enable == HasUnitMovementFlag(MOVEMENTFLAG_HOVER))
        return false;

    float hoverHeight = m_unitData->HoverHeight;

    if (enable)
    {
        //! No need to check height on ascent
        AddUnitMovementFlag(MOVEMENTFLAG_HOVER);
        if (hoverHeight && GetPositionZ() - GetFloorZ() < hoverHeight)
            UpdateHeight(GetPositionZ() + hoverHeight);
    }
    else
    {
        RemoveUnitMovementFlag(MOVEMENTFLAG_HOVER);
        //! Dying creatures will MoveFall from setDeathState
        if (hoverHeight && (!isDying() || GetTypeId() != TYPEID_UNIT))
        {
            float newZ = std::max<float>(GetFloorZ(), GetPositionZ() - hoverHeight);
            UpdateAllowedPositionZ(GetPositionX(), GetPositionY(), newZ);
            UpdateHeight(newZ);
        }
    }

    static OpcodeServer const hoverOpcodeTable[2][2] =
    {
        { SMSG_MOVE_SPLINE_UNSET_HOVER, SMSG_MOVE_UNSET_HOVERING },
        { SMSG_MOVE_SPLINE_SET_HOVER,   SMSG_MOVE_SET_HOVERING   }
    };

    if (Player* playerMover = Unit::ToPlayer(GetUnitBeingMoved()))
    {
        WorldPackets::Movement::MoveSetFlag packet(hoverOpcodeTable[enable][1]);
        packet.MoverGUID = GetGUID();
        packet.SequenceIndex = m_movementCounter++;
        playerMover->SendDirectMessage(packet.Write());

        WorldPackets::Movement::MoveUpdate moveUpdate;
        moveUpdate.Status = &m_movementInfo;
        SendMessageToSet(moveUpdate.Write(), playerMover);
    }
    else
    {
        WorldPackets::Movement::MoveSplineSetFlag packet(hoverOpcodeTable[enable][0]);
        packet.MoverGUID = GetGUID();
        SendMessageToSet(packet.Write(), true);
    }

    if (IsCreature() && updateAnimTier && IsAlive() && !HasUnitState(UNIT_STATE_ROOT))
    {
        if (IsGravityDisabled())
            SetAnimTier(AnimTier::Fly);
        else if (IsHovering())
            SetAnimTier(AnimTier::Hover);
        else
            SetAnimTier(AnimTier::Ground);
    }

    if (IsAlive())
    {
        if (IsGravityDisabled() || IsHovering())
            SetPlayHoverAnim(true);
        else
            SetPlayHoverAnim(false);
    }
    else if (IsPlayer()) // To update player who dies while flying/hovering
        SetPlayHoverAnim(false, false);

    return true;
}

bool Unit::SetCollision(bool disable)
{
    if (disable == HasUnitMovementFlag(MOVEMENTFLAG_DISABLE_COLLISION))
        return false;

    if (disable)
        AddUnitMovementFlag(MOVEMENTFLAG_DISABLE_COLLISION);
    else
        RemoveUnitMovementFlag(MOVEMENTFLAG_DISABLE_COLLISION);

    static OpcodeServer const collisionOpcodeTable[2][2] =
    {
        { SMSG_MOVE_SPLINE_ENABLE_COLLISION,  SMSG_MOVE_ENABLE_COLLISION },
        { SMSG_MOVE_SPLINE_DISABLE_COLLISION, SMSG_MOVE_DISABLE_COLLISION }
    };

    if (Player* playerMover = Unit::ToPlayer(GetUnitBeingMoved()))
    {
        WorldPackets::Movement::MoveSetFlag packet(collisionOpcodeTable[disable][1]);
        packet.MoverGUID = GetGUID();
        packet.SequenceIndex = m_movementCounter++;
        playerMover->SendDirectMessage(packet.Write());

        WorldPackets::Movement::MoveUpdate moveUpdate;
        moveUpdate.Status = &m_movementInfo;
        SendMessageToSet(moveUpdate.Write(), playerMover);
    }
    else
    {
        WorldPackets::Movement::MoveSplineSetFlag packet(collisionOpcodeTable[disable][0]);
        packet.MoverGUID = GetGUID();
        SendMessageToSet(packet.Write(), true);
    }

    return true;
}

bool Unit::SetCanTransitionBetweenSwimAndFly(bool enable)
{
    if (GetTypeId() != TYPEID_PLAYER)
        return false;

    if (enable == HasExtraUnitMovementFlag(MOVEMENTFLAG2_CAN_SWIM_TO_FLY_TRANS))
        return false;

    if (enable)
        AddExtraUnitMovementFlag(MOVEMENTFLAG2_CAN_SWIM_TO_FLY_TRANS);
    else
        RemoveExtraUnitMovementFlag(MOVEMENTFLAG2_CAN_SWIM_TO_FLY_TRANS);

    static OpcodeServer const swimToFlyTransOpcodeTable[2] =
    {
        SMSG_MOVE_DISABLE_TRANSITION_BETWEEN_SWIM_AND_FLY,
        SMSG_MOVE_ENABLE_TRANSITION_BETWEEN_SWIM_AND_FLY
    };

    if (Player* playerMover = Unit::ToPlayer(GetUnitBeingMoved()))
    {
        WorldPackets::Movement::MoveSetFlag packet(swimToFlyTransOpcodeTable[enable]);
        packet.MoverGUID = GetGUID();
        packet.SequenceIndex = m_movementCounter++;
        playerMover->SendDirectMessage(packet.Write());

        WorldPackets::Movement::MoveUpdate moveUpdate;
        moveUpdate.Status = &m_movementInfo;
        SendMessageToSet(moveUpdate.Write(), playerMover);
    }

    return true;
}

bool Unit::SetCanTurnWhileFalling(bool enable)
{
    // Temporarily disabled for short lived auras that unapply before client had time to ACK applying
    //if (enable == HasExtraUnitMovementFlag(MOVEMENTFLAG2_CAN_TURN_WHILE_FALLING))
    //    return false;

    if (enable)
        AddExtraUnitMovementFlag(MOVEMENTFLAG2_CAN_TURN_WHILE_FALLING);
    else
        RemoveExtraUnitMovementFlag(MOVEMENTFLAG2_CAN_TURN_WHILE_FALLING);

    static OpcodeServer const canTurnWhileFallingOpcodeTable[2] =
    {
        SMSG_MOVE_UNSET_CAN_TURN_WHILE_FALLING,
        SMSG_MOVE_SET_CAN_TURN_WHILE_FALLING
    };

    if (Player* playerMover = Unit::ToPlayer(GetUnitBeingMoved()))
    {
        WorldPackets::Movement::MoveSetFlag packet(canTurnWhileFallingOpcodeTable[enable]);
        packet.MoverGUID = GetGUID();
        packet.SequenceIndex = m_movementCounter++;
        playerMover->SendDirectMessage(packet.Write());

        WorldPackets::Movement::MoveUpdate moveUpdate;
        moveUpdate.Status = &m_movementInfo;
        SendMessageToSet(moveUpdate.Write(), playerMover);
    }

    return true;
}

bool Unit::SetCanDoubleJump(bool enable)
{
    if (enable == HasExtraUnitMovementFlag(MOVEMENTFLAG2_CAN_DOUBLE_JUMP))
        return false;

    if (enable)
        AddExtraUnitMovementFlag(MOVEMENTFLAG2_CAN_DOUBLE_JUMP);
    else
        RemoveExtraUnitMovementFlag(MOVEMENTFLAG2_CAN_DOUBLE_JUMP);

    static OpcodeServer const doubleJumpOpcodeTable[2] =
    {
        SMSG_MOVE_DISABLE_DOUBLE_JUMP,
        SMSG_MOVE_ENABLE_DOUBLE_JUMP
    };

    if (Player* playerMover = Unit::ToPlayer(GetUnitBeingMoved()))
    {
        WorldPackets::Movement::MoveSetFlag packet(doubleJumpOpcodeTable[enable]);
        packet.MoverGUID = GetGUID();
        packet.SequenceIndex = m_movementCounter++;
        playerMover->SendDirectMessage(packet.Write());

        WorldPackets::Movement::MoveUpdate moveUpdate;
        moveUpdate.Status = &m_movementInfo;
        SendMessageToSet(moveUpdate.Write(), playerMover);
    }

    return true;
}

bool Unit::SetDisableInertia(bool disable)
{
    if (disable == HasExtraUnitMovementFlag2(MOVEMENTFLAG3_DISABLE_INERTIA))
        return false;

    if (disable)
        AddExtraUnitMovementFlag2(MOVEMENTFLAG3_DISABLE_INERTIA);
    else
        RemoveExtraUnitMovementFlag2(MOVEMENTFLAG3_DISABLE_INERTIA);

    static OpcodeServer const disableInertiaOpcodeTable[2] =
    {
        SMSG_MOVE_DISABLE_INERTIA,
        SMSG_MOVE_ENABLE_INERTIA
    };

    if (Player* playerMover = Unit::ToPlayer(GetUnitBeingMoved()))
    {
        WorldPackets::Movement::MoveSetFlag packet(disableInertiaOpcodeTable[disable]);
        packet.MoverGUID = GetGUID();
        packet.SequenceIndex = m_movementCounter++;
        playerMover->SendDirectMessage(packet.Write());

        WorldPackets::Movement::MoveUpdate moveUpdate;
        moveUpdate.Status = &m_movementInfo;
        SendMessageToSet(moveUpdate.Write(), playerMover);
    }

    return true;
}

void Unit::SendSetVehicleRecId(uint32 vehicleId)
{
    if (Player* player = ToPlayer())
    {
        WorldPackets::Vehicle::MoveSetVehicleRecID moveSetVehicleRec;
        moveSetVehicleRec.MoverGUID = GetGUID();
        moveSetVehicleRec.SequenceIndex = m_movementCounter++;
        moveSetVehicleRec.VehicleRecID = vehicleId;
        player->SendDirectMessage(moveSetVehicleRec.Write());
    }

    WorldPackets::Vehicle::SetVehicleRecID setVehicleRec;
    setVehicleRec.VehicleGUID = GetGUID();
    setVehicleRec.VehicleRecID = vehicleId;
    SendMessageToSet(setVehicleRec.Write(), true);
}

void Unit::ApplyMovementForce(ObjectGuid id, Position origin, float magnitude, MovementForceType type, Position direction /*= {}*/, ObjectGuid transportGuid /*= ObjectGuid::Empty*/)
{
    if (!_movementForces)
        _movementForces = std::make_unique<MovementForces>();

    MovementForce force;
    force.ID = id;
    force.Origin = origin;
    force.Direction = direction;
    if (transportGuid.IsMOTransport())
        force.TransportID = transportGuid.GetCounter();

    force.Magnitude = magnitude;
    force.Type = type;

    if (_movementForces->Add(force))
    {
        if (Player const* movingPlayer = GetPlayerMovingMe())
        {
            WorldPackets::Movement::MoveApplyMovementForce applyMovementForce;
            applyMovementForce.MoverGUID = GetGUID();
            applyMovementForce.SequenceIndex = m_movementCounter++;
            applyMovementForce.Force = &force;
            movingPlayer->SendDirectMessage(applyMovementForce.Write());
        }
        else
        {
            WorldPackets::Movement::MoveUpdateApplyMovementForce updateApplyMovementForce;
            updateApplyMovementForce.Status = &m_movementInfo;
            updateApplyMovementForce.Force = &force;
            SendMessageToSet(updateApplyMovementForce.Write(), true);
        }
    }
}

void Unit::RemoveMovementForce(ObjectGuid id)
{
    if (!_movementForces)
        return;

    if (_movementForces->Remove(id))
    {
        if (Player const* movingPlayer = GetPlayerMovingMe())
        {
            WorldPackets::Movement::MoveRemoveMovementForce moveRemoveMovementForce;
            moveRemoveMovementForce.MoverGUID = GetGUID();
            moveRemoveMovementForce.SequenceIndex = m_movementCounter++;
            moveRemoveMovementForce.ID = id;
            movingPlayer->SendDirectMessage(moveRemoveMovementForce.Write());
        }
        else
        {
            WorldPackets::Movement::MoveUpdateRemoveMovementForce updateRemoveMovementForce;
            updateRemoveMovementForce.Status = &m_movementInfo;
            updateRemoveMovementForce.TriggerGUID = id;
            SendMessageToSet(updateRemoveMovementForce.Write(), true);
        }
    }

    if (_movementForces->IsEmpty())
        _movementForces.reset();
}

bool Unit::SetIgnoreMovementForces(bool ignore)
{
    if (ignore == HasExtraUnitMovementFlag(MOVEMENTFLAG2_IGNORE_MOVEMENT_FORCES))
        return false;

    if (ignore)
        AddExtraUnitMovementFlag(MOVEMENTFLAG2_IGNORE_MOVEMENT_FORCES);
    else
        RemoveExtraUnitMovementFlag(MOVEMENTFLAG2_IGNORE_MOVEMENT_FORCES);

    static OpcodeServer const ignoreMovementForcesOpcodeTable[2] =
    {
        SMSG_MOVE_UNSET_IGNORE_MOVEMENT_FORCES,
        SMSG_MOVE_SET_IGNORE_MOVEMENT_FORCES
    };

    if (Player const* movingPlayer = GetPlayerMovingMe())
    {
        WorldPackets::Movement::MoveSetFlag packet(ignoreMovementForcesOpcodeTable[ignore]);
        packet.MoverGUID = GetGUID();
        packet.SequenceIndex = m_movementCounter++;
        movingPlayer->SendDirectMessage(packet.Write());

        WorldPackets::Movement::MoveUpdate moveUpdate;
        moveUpdate.Status = &m_movementInfo;
        SendMessageToSet(moveUpdate.Write(), movingPlayer);
    }

    return true;
}

void Unit::UpdateMovementForcesModMagnitude()
{
    float modMagnitude = GetTotalAuraMultiplier(SPELL_AURA_MOD_MOVEMENT_FORCE_MAGNITUDE);

    if (Player* movingPlayer = GetPlayerMovingMe())
    {
        WorldPackets::Movement::MoveSetSpeed setModMovementForceMagnitude(SMSG_MOVE_SET_MOD_MOVEMENT_FORCE_MAGNITUDE);
        setModMovementForceMagnitude.MoverGUID = GetGUID();
        setModMovementForceMagnitude.SequenceIndex = m_movementCounter++;
        setModMovementForceMagnitude.Speed = modMagnitude;
        movingPlayer->SendDirectMessage(setModMovementForceMagnitude.Write());
        ++movingPlayer->m_movementForceModMagnitudeChanges;
    }
    else
    {
        WorldPackets::Movement::MoveUpdateSpeed updateModMovementForceMagnitude(SMSG_MOVE_UPDATE_MOD_MOVEMENT_FORCE_MAGNITUDE);
        updateModMovementForceMagnitude.Status = &m_movementInfo;
        updateModMovementForceMagnitude.Speed = modMagnitude;
        SendMessageToSet(updateModMovementForceMagnitude.Write(), true);
    }

    if (modMagnitude != 1.0f && !_movementForces)
        _movementForces = std::make_unique<MovementForces>();

    if (_movementForces)
    {
        _movementForces->SetModMagnitude(modMagnitude);
        if (_movementForces->IsEmpty())
            _movementForces.reset();
    }
}

void Unit::SetPlayHoverAnim(bool enable, bool sendUpdate /*= true*/)
{
    if (IsPlayingHoverAnim() == enable)
        return;

    _playHoverAnim = enable;

    if (!sendUpdate)
        return;

    WorldPackets::Misc::SetPlayHoverAnim data;
    data.UnitGUID = GetGUID();
    data.PlayHoverAnim = enable;

    SendMessageToSet(data.Write(), true);
}

void Unit::CalculateHoverHeight()
{
    float hoverHeight = DEFAULT_PLAYER_HOVER_HEIGHT;
    float displayScale = DEFAULT_PLAYER_DISPLAY_SCALE;

    uint32 displayId = IsMounted() ? GetMountDisplayId() : GetDisplayId();

    // Get DisplayScale for creatures
    if (IsCreature())
        if (CreatureModel const* model = ToCreature()->GetCreatureTemplate()->GetModelWithDisplayId(displayId))
            displayScale = model->DisplayScale;

    if (CreatureDisplayInfoEntry const* displayInfo = sCreatureDisplayInfoStore.LookupEntry(displayId))
        if (CreatureModelDataEntry const* modelData = sCreatureModelDataStore.LookupEntry(displayInfo->ModelID))
            hoverHeight = modelData->HoverHeight * modelData->ModelScale * displayInfo->CreatureModelScale * displayScale;

    SetHoverHeight(hoverHeight ? hoverHeight : DEFAULT_PLAYER_HOVER_HEIGHT);
}

bool Unit::IsSplineEnabled() const
{
    return movespline->Initialized() && !movespline->Finalized();
}

UF::UpdateFieldFlag Unit::GetUpdateFieldFlagsFor(Player const* target) const
{
    UF::UpdateFieldFlag flags = UF::UpdateFieldFlag::None;
    if (target == this || GetOwnerGUID() == target->GetGUID())
        flags |= UF::UpdateFieldFlag::Owner;

    if (HasDynamicFlag(UNIT_DYNFLAG_SPECIALINFO))
        if (HasAuraTypeWithCaster(SPELL_AURA_EMPATHY, target->GetGUID()))
            flags |= UF::UpdateFieldFlag::Empath;

    return flags;
}

void Unit::BuildValuesCreate(ByteBuffer* data, Player const* target) const
{
    UF::UpdateFieldFlag flags = GetUpdateFieldFlagsFor(target);
    std::size_t sizePos = data->wpos();
    *data << uint32(0);
    *data << uint8(flags);
    m_objectData->WriteCreate(*data, flags, this, target);
    m_unitData->WriteCreate(*data, flags, this, target);
    data->put<uint32>(sizePos, data->wpos() - sizePos - 4);
}

void Unit::BuildValuesUpdate(ByteBuffer* data, Player const* target) const
{
    UF::UpdateFieldFlag flags = GetUpdateFieldFlagsFor(target);
    std::size_t sizePos = data->wpos();
    *data << uint32(0);
    *data << uint32(m_values.GetChangedObjectTypeMask());

    if (m_values.HasChanged(TYPEID_OBJECT))
        m_objectData->WriteUpdate(*data, flags, this, target);

    if (m_values.HasChanged(TYPEID_UNIT))
        m_unitData->WriteUpdate(*data, flags, this, target);

    data->put<uint32>(sizePos, data->wpos() - sizePos - 4);
}

void Unit::BuildValuesUpdateWithFlag(ByteBuffer* data, UF::UpdateFieldFlag flags, Player const* target) const
{
    UpdateMask<NUM_CLIENT_OBJECT_TYPES> valuesMask;
    valuesMask.Set(TYPEID_UNIT);

    std::size_t sizePos = data->wpos();
    *data << uint32(0);
    *data << uint32(valuesMask.GetBlock(0));

    UF::UnitData::Mask mask;
    m_unitData->AppendAllowedFieldsMaskForFlag(mask, flags);
    m_unitData->WriteUpdate(*data, mask, true, this, target);

    data->put<uint32>(sizePos, data->wpos() - sizePos - 4);
}

void Unit::BuildValuesUpdateForPlayerWithMask(UpdateData* data, UF::ObjectData::Mask const& requestedObjectMask,
    UF::UnitData::Mask const& requestedUnitMask, Player const* target) const
{
    UF::UpdateFieldFlag flags = GetUpdateFieldFlagsFor(target);
    UpdateMask<NUM_CLIENT_OBJECT_TYPES> valuesMask;
    if (requestedObjectMask.IsAnySet())
        valuesMask.Set(TYPEID_OBJECT);

    UF::UnitData::Mask unitMask = requestedUnitMask;
    m_unitData->FilterDisallowedFieldsMaskForFlag(unitMask, flags);
    if (unitMask.IsAnySet())
        valuesMask.Set(TYPEID_UNIT);

    ByteBuffer& buffer = PrepareValuesUpdateBuffer(data);
    std::size_t sizePos = buffer.wpos();
    buffer << uint32(0);
    buffer << uint32(valuesMask.GetBlock(0));

    if (valuesMask[TYPEID_OBJECT])
        m_objectData->WriteUpdate(buffer, requestedObjectMask, true, this, target);

    if (valuesMask[TYPEID_UNIT])
        m_unitData->WriteUpdate(buffer, unitMask, true, this, target);

    buffer.put<uint32>(sizePos, buffer.wpos() - sizePos - 4);

    data->AddUpdateBlock();
}

void Unit::ValuesUpdateForPlayerWithMaskSender::operator()(Player const* player) const
{
    UpdateData udata(Owner->GetMapId());
    WorldPacket packet;

    Owner->BuildValuesUpdateForPlayerWithMask(&udata, ObjectMask.GetChangesMask(), UnitMask.GetChangesMask(), player);

    udata.BuildPacket(&packet);
    player->SendDirectMessage(&packet);
}

void Unit::DestroyForPlayer(Player* target) const
{
    if (Battleground* bg = target->GetBattleground())
    {
        if (bg->isArena())
        {
            WorldPackets::Battleground::DestroyArenaUnit destroyArenaUnit;
            destroyArenaUnit.Guid = GetGUID();
            target->GetSession()->SendPacket(destroyArenaUnit.Write());
        }
    }

    WorldObject::DestroyForPlayer(target);
}

void Unit::ClearUpdateMask(bool remove)
{
    m_values.ClearChangesMask(&Unit::m_unitData);
    Object::ClearUpdateMask(remove);
}

int32 Unit::GetHighestExclusiveSameEffectSpellGroupValue(AuraEffect const* aurEff, AuraType auraType, bool checkMiscValue /*= false*/, int32 miscValue /*= 0*/) const
{
    int32 val = 0;
    SpellSpellGroupMapBounds spellGroup = sSpellMgr->GetSpellSpellGroupMapBounds(aurEff->GetSpellInfo()->GetFirstRankSpell()->Id);
    for (SpellSpellGroupMap::const_iterator itr = spellGroup.first; itr != spellGroup.second ; ++itr)
    {
        if (sSpellMgr->GetSpellGroupStackRule(itr->second) == SPELL_GROUP_STACK_RULE_EXCLUSIVE_SAME_EFFECT)
        {
            AuraEffectList const& auraEffList = GetAuraEffectsByType(auraType);
            for (AuraEffectList::const_iterator auraItr = auraEffList.begin(); auraItr != auraEffList.end(); ++auraItr)
            {
                if (aurEff != (*auraItr) && (!checkMiscValue || (*auraItr)->GetMiscValue() == miscValue) &&
                    sSpellMgr->IsSpellMemberOfSpellGroup((*auraItr)->GetSpellInfo()->Id, itr->second))
                {
                    // absolute value only
                    if (abs(val) < abs((*auraItr)->GetAmount()))
                        val = (*auraItr)->GetAmount();
                }
            }
        }
    }
    return val;
}

bool Unit::IsHighestExclusiveAura(Aura const* aura, bool removeOtherAuraApplications /*= false*/)
{
    for (AuraEffect const* aurEff : aura->GetAuraEffects())
    {
        if (!aurEff)
            continue;

        if (!IsHighestExclusiveAuraEffect(aura->GetSpellInfo(), aurEff->GetAuraType(), aurEff->GetAmount(), aura->GetEffectMask(), removeOtherAuraApplications))
            return false;
    }

    return true;
}

bool Unit::IsHighestExclusiveAuraEffect(SpellInfo const* spellInfo, AuraType auraType, int32 effectAmount, uint32 auraEffectMask, bool removeOtherAuraApplications /*= false*/)
{
    AuraEffectList const& auras = GetAuraEffectsByType(auraType);
    for (Unit::AuraEffectList::const_iterator itr = auras.begin(); itr != auras.end();)
    {
        AuraEffect const* existingAurEff = (*itr);
        ++itr;

        if (sSpellMgr->CheckSpellGroupStackRules(spellInfo, existingAurEff->GetSpellInfo()) == SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST)
        {
            int64 diff = int64(abs(effectAmount)) - int64(abs(existingAurEff->GetAmount()));
            if (!diff)
                for (int32 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                    diff += int64((auraEffectMask & (1 << i)) >> i) - int64((existingAurEff->GetBase()->GetEffectMask() & (1 << i)) >> i);

            if (diff > 0)
            {
                Aura const* base = existingAurEff->GetBase();
                // no removing of area auras from the original owner, as that completely cancels them
                if (removeOtherAuraApplications && (!base->IsArea() || base->GetOwner() != this))
                {
                    if (AuraApplication* aurApp = existingAurEff->GetBase()->GetApplicationOfTarget(GetGUID()))
                    {
                        bool hasMoreThanOneEffect = base->HasMoreThanOneEffectForType(auraType);
                        uint32 removedAuras = m_removedAurasCount;
                        RemoveAura(aurApp);
                        if (hasMoreThanOneEffect || m_removedAurasCount > removedAuras + 1)
                            itr = auras.begin();
                    }
                }
            }
            else if (diff < 0)
                return false;
        }
    }

    return true;
}

void Unit::Talk(std::string_view text, ChatMsg msgType, Language language, float textRange, WorldObject const* target)
{
    Trinity::CustomChatTextBuilder builder(this, msgType, text, language, target);
    Trinity::LocalizedDo<Trinity::CustomChatTextBuilder> localizer(builder);
    Trinity::PlayerDistWorker<Trinity::LocalizedDo<Trinity::CustomChatTextBuilder> > worker(this, textRange, localizer);
    Cell::VisitWorldObjects(this, worker, textRange);
}

void Unit::Say(std::string_view text, Language language, WorldObject const* target /*= nullptr*/)
{
    Talk(text, CHAT_MSG_MONSTER_SAY, language, sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_SAY), target);
}

void Unit::Yell(std::string_view text, Language language, WorldObject const* target /*= nullptr*/)
{
    Talk(text, CHAT_MSG_MONSTER_YELL, language, sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_YELL), target);
}

void Unit::TextEmote(std::string_view text, WorldObject const* target /*= nullptr*/, bool isBossEmote /*= false*/)
{
    Talk(text, isBossEmote ? CHAT_MSG_RAID_BOSS_EMOTE : CHAT_MSG_MONSTER_EMOTE, LANG_UNIVERSAL, sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_TEXTEMOTE), target);
}

void Unit::Whisper(std::string_view text, Language language, Player* target, bool isBossWhisper /*= false*/)
{
    if (!target)
        return;

    LocaleConstant locale = target->GetSession()->GetSessionDbLocaleIndex();
    WorldPackets::Chat::Chat packet;
    packet.Initialize(isBossWhisper ? CHAT_MSG_RAID_BOSS_WHISPER : CHAT_MSG_MONSTER_WHISPER, language, this, target, text, 0, "", locale);
    target->SendDirectMessage(packet.Write());
}

uint32 Unit::GetVirtualItemId(uint32 slot) const
{
    if (slot >= MAX_EQUIPMENT_ITEMS)
        return 0;

    return m_unitData->VirtualItems[slot].ItemID;
}

uint16 Unit::GetVirtualItemAppearanceMod(uint32 slot) const
{
    if (slot >= MAX_EQUIPMENT_ITEMS)
        return 0;

    return m_unitData->VirtualItems[slot].ItemAppearanceModID;
}

void Unit::SetVirtualItem(uint32 slot, uint32 itemId, uint16 appearanceModId /*= 0*/, uint16 itemVisual /*= 0*/)
{
    if (slot >= MAX_EQUIPMENT_ITEMS)
        return;

    auto virtualItemField = m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::VirtualItems, slot);
    SetUpdateFieldValue(virtualItemField.ModifyValue(&UF::VisibleItem::ItemID), itemId);
    SetUpdateFieldValue(virtualItemField.ModifyValue(&UF::VisibleItem::ItemAppearanceModID), appearanceModId);
    SetUpdateFieldValue(virtualItemField.ModifyValue(&UF::VisibleItem::ItemVisual), itemVisual);
}

void Unit::Talk(uint32 textId, ChatMsg msgType, float textRange, WorldObject const* target)
{
    if (!sBroadcastTextStore.LookupEntry(textId))
    {
        TC_LOG_ERROR("entities.unit", "WorldObject::MonsterText: `broadcast_text` (ID: {}) was not found", textId);
        return;
    }

    Trinity::BroadcastTextBuilder builder(this, msgType, textId, GetGender(), target);
    Trinity::LocalizedDo<Trinity::BroadcastTextBuilder> localizer(builder);
    Trinity::PlayerDistWorker<Trinity::LocalizedDo<Trinity::BroadcastTextBuilder> > worker(this, textRange, localizer);
    Cell::VisitWorldObjects(this, worker, textRange);
}

void Unit::Say(uint32 textId, WorldObject const* target /*= nullptr*/)
{
    Talk(textId, CHAT_MSG_MONSTER_SAY, sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_SAY), target);
}

void Unit::Yell(uint32 textId, WorldObject const* target /*= nullptr*/)
{
    Talk(textId, CHAT_MSG_MONSTER_YELL, sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_YELL), target);
}

void Unit::TextEmote(uint32 textId, WorldObject const* target /*= nullptr*/, bool isBossEmote /*= false*/)
{
    Talk(textId, isBossEmote ? CHAT_MSG_RAID_BOSS_EMOTE : CHAT_MSG_MONSTER_EMOTE, sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_TEXTEMOTE), target);
}

void Unit::Whisper(uint32 textId, Player* target, bool isBossWhisper /*= false*/)
{
    if (!target)
        return;

    BroadcastTextEntry const* bct = sBroadcastTextStore.LookupEntry(textId);
    if (!bct)
    {
        TC_LOG_ERROR("entities.unit", "WorldObject::Whisper: `broadcast_text` was not {} found", textId);
        return;
    }

    LocaleConstant locale = target->GetSession()->GetSessionDbLocaleIndex();
    WorldPackets::Chat::Chat packet;
    packet.Initialize(isBossWhisper ? CHAT_MSG_RAID_BOSS_WHISPER : CHAT_MSG_MONSTER_WHISPER, LANG_UNIVERSAL, this, target, DB2Manager::GetBroadcastTextValue(bct, locale, GetGender()), 0, "", locale);
    target->SendDirectMessage(packet.Write());
}

void Unit::ClearBossEmotes(Optional<uint32> zoneId, Player const* target) const
{
    WorldPackets::Chat::ClearBossEmotes clearBossEmotes;
    clearBossEmotes.Write();

    if (target)
    {
        target->SendDirectMessage(clearBossEmotes.GetRawPacket());
        return;
    }

    for (MapReference const& ref : GetMap()->GetPlayers())
        if (!zoneId || DB2Manager::IsInArea(ref.GetSource()->GetAreaId(), *zoneId))
            ref.GetSource()->SendDirectMessage(clearBossEmotes.GetRawPacket());
}

SpellInfo const* Unit::GetCastSpellInfo(SpellInfo const* spellInfo, TriggerCastFlags& triggerFlag) const
{
    auto findMatchingAuraEffectIn = [this, spellInfo, &triggerFlag](AuraType type) -> SpellInfo const*
    {
        for (AuraEffect const* auraEffect : GetAuraEffectsByType(type))
        {
            bool matches = auraEffect->GetMiscValue() ? uint32(auraEffect->GetMiscValue()) == spellInfo->Id : auraEffect->IsAffectingSpell(spellInfo);
            if (matches)
            {
                if (SpellInfo const* newInfo = sSpellMgr->GetSpellInfo(auraEffect->GetAmount(), GetMap()->GetDifficultyID()))
                {
                    if (auraEffect->GetSpellInfo()->HasAttribute(SPELL_ATTR8_IGNORE_SPELLCAST_OVERRIDE_COST))
                        triggerFlag |= TRIGGERED_IGNORE_POWER_AND_REAGENT_COST;

                    return newInfo;
                }
            }
        }

        return nullptr;
    };

    if (SpellInfo const* newInfo = findMatchingAuraEffectIn(SPELL_AURA_OVERRIDE_ACTIONBAR_SPELLS))
        return newInfo;

    if (SpellInfo const* newInfo = findMatchingAuraEffectIn(SPELL_AURA_OVERRIDE_ACTIONBAR_SPELLS_TRIGGERED))
        return newInfo;

    return spellInfo;
}

uint32 Unit::GetCastSpellXSpellVisualId(SpellInfo const* spellInfo) const
{
    Unit::AuraEffectList const& visualOverrides = GetAuraEffectsByType(SPELL_AURA_OVERRIDE_SPELL_VISUAL);
    for (AuraEffect const* effect : visualOverrides)
    {
        if (uint32(effect->GetMiscValue()) == spellInfo->Id)
        {
            if (SpellInfo const* visualSpell = sSpellMgr->GetSpellInfo(effect->GetMiscValueB(), GetMap()->GetDifficultyID()))
            {
                spellInfo = visualSpell;
                break;
            }
        }
    }

    return WorldObject::GetCastSpellXSpellVisualId(spellInfo);
}

bool Unit::VisibleAuraSlotCompare::operator()(AuraApplication* left, AuraApplication* right) const
{
    return left->GetSlot() < right->GetSlot();
}

// Returns collisionheight of the unit. If it is 0, it returns DEFAULT_COLLISION_HEIGHT.
float Unit::GetCollisionHeight() const
{
    float scaleMod = GetObjectScale(); // 99% sure about this

    if (IsMounted())
    {
        if (CreatureDisplayInfoEntry const* mountDisplayInfo = sCreatureDisplayInfoStore.LookupEntry(GetMountDisplayId()))
        {
            if (CreatureModelDataEntry const* mountModelData = sCreatureModelDataStore.LookupEntry(mountDisplayInfo->ModelID))
            {
                CreatureDisplayInfoEntry const* displayInfo = sCreatureDisplayInfoStore.AssertEntry(GetNativeDisplayId());
                CreatureModelDataEntry const* modelData = sCreatureModelDataStore.AssertEntry(displayInfo->ModelID);
                float const collisionHeight = scaleMod * ((mountModelData->MountHeight * mountDisplayInfo->CreatureModelScale) + (modelData->CollisionHeight * modelData->ModelScale * displayInfo->CreatureModelScale * 0.5f));
                return collisionHeight == 0.0f ? DEFAULT_COLLISION_HEIGHT : collisionHeight;
            }
        }
    }

    //! Dismounting case - use basic default model data
    CreatureDisplayInfoEntry const* displayInfo = sCreatureDisplayInfoStore.AssertEntry(GetNativeDisplayId());
    CreatureModelDataEntry const* modelData = sCreatureModelDataStore.AssertEntry(displayInfo->ModelID);

    float const collisionHeight = scaleMod * modelData->CollisionHeight * modelData->ModelScale * displayInfo->CreatureModelScale;
    return collisionHeight == 0.0f ? DEFAULT_COLLISION_HEIGHT : collisionHeight;
}

void Unit::SetVignette(uint32 vignetteId)
{
    if (m_vignette)
    {
        if (m_vignette->Data->ID == vignetteId)
            return;

        Vignettes::Remove(*m_vignette, this);
        m_vignette = nullptr;
    }

    if (VignetteEntry const* vignette = sVignetteStore.LookupEntry(vignetteId))
        m_vignette = Vignettes::Create(vignette, this);
}

std::string Unit::GetDebugInfo() const
{
    std::stringstream sstr;
    sstr << WorldObject::GetDebugInfo() << "\n"
        << std::boolalpha
        << "IsAIEnabled: " << IsAIEnabled() << " DeathState: " << std::to_string(getDeathState())
        << " UnitMovementFlags: " << GetUnitMovementFlags() << " ExtraUnitMovementFlags: " << GetExtraUnitMovementFlags()
        << " Class: " << std::to_string(GetClass()) << "\n"
        << "" << (movespline ? movespline->ToString() : "Movespline: <none>\n")
        << "GetCharmedGUID(): " << GetCharmedGUID().ToString() << "\n"
        << "GetCharmerGUID(): " << GetCharmerGUID().ToString() << "\n"
        << "" << (GetVehicleKit() ? GetVehicleKit()->GetDebugInfo() : "No vehicle kit") << "\n"
        << "m_Controlled size: " << m_Controlled.size();

    size_t controlledCount = 0;
    for (Unit* controlled : m_Controlled)
    {
        ++controlledCount;
        sstr << "\n" << "m_Controlled " << controlledCount << " : " << controlled->GetGUID().ToString();
    }

    return sstr.str();
}

DeclinedName::DeclinedName(UF::DeclinedNames const& uf)
{
    for (std::size_t i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
        name[i] = uf.Name[i];
}
