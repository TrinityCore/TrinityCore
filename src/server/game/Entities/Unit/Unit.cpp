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
#include "Battlefield.h"
#include "BattlefieldMgr.h"
#include "Battleground.h"
#include "BattlegroundPackets.h"
#include "BattlegroundScore.h"
#include "CellImpl.h"
#include "CharacterCache.h"
#include "ChatPackets.h"
#include "ChatTextBuilder.h"
#include "CombatLogPackets.h"
#include "CombatPackets.h"
#include "Common.h"
#include "ConditionMgr.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "CreatureGroups.h"
#include "Formulas.h"
#include "GameTime.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "InstanceSaveMgr.h"
#include "InstanceScript.h"
#include "Item.h"
#include "Log.h"
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
#include "PassiveAI.h"
#include "Pet.h"
#include "PetAI.h"
#include "PetPackets.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "PlayerAI.h"
#include "QuestDef.h"
#include "ReputationMgr.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellHistory.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "SpellPackets.h"
#include "TemporarySummon.h"
#include "Totem.h"
#include "Transport.h"
#include "Util.h"
#include "Vehicle.h"
#include "VehiclePackets.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"
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
    m_absorb(0), m_resist(0), m_block(0), m_hitMask(0)
{
}

DamageInfo::DamageInfo(CalcDamageInfo const& dmgInfo)
    : m_attacker(dmgInfo.Attacker), m_victim(dmgInfo.Target), m_damage(dmgInfo.Damage), m_originalDamage(dmgInfo.Damage), m_spellInfo(nullptr), m_schoolMask(SpellSchoolMask(dmgInfo.DamageSchoolMask)),
    m_damageType(DIRECT_DAMAGE), m_attackType(dmgInfo.AttackType), m_absorb(dmgInfo.Absorb), m_resist(dmgInfo.Resist), m_block(dmgInfo.Blocked), m_hitMask(0)
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

DamageInfo::DamageInfo(SpellNonMeleeDamage const& spellNonMeleeDamage, DamageEffectType damageType, WeaponAttackType attackType, uint32 hitMask)
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

uint32 DamageInfo::GetHitMask() const
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
                             uint32 typeMask, uint32 spellTypeMask,
                             uint32 spellPhaseMask, uint32 hitMask,
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
    WorldObject(isWorldObject), m_playerMovingMe(nullptr), m_lastSanctuaryTime(0),
    IsAIEnabled(false), NeedChangeAI(false), LastCharmerGUID(), m_ControlledByPlayer(false),
    movespline(new Movement::MoveSpline()), i_AI(nullptr), i_disabledAI(nullptr),
    m_AutoRepeatFirstCast(false), m_procDeep(0), m_removedAurasCount(0),
    m_interruptMask(SpellAuraInterruptFlags::None), m_interruptMask2(SpellAuraInterruptFlags2::None),
    i_motionMaster(new MotionMaster(this)), m_regenTimer(0), m_vehicle(nullptr),
    m_vehicleKit(nullptr), m_unitTypeMask(UNIT_MASK_NONE), m_Diminishing(), m_combatManager(this),
    m_threatManager(this), _aiAnimKitId(0), _movementAnimKitId(0), _meleeAnimKitId(0),
    _spellHistory(new SpellHistory(this))
{
    m_objectType |= TYPEMASK_UNIT;
    m_objectTypeId = TYPEID_UNIT;

    m_updateFlag.MovementUpdate = true;

    for (uint32 i = 0; i < MAX_ATTACK; ++i)
    {
        m_baseAttackSpeed[i] = 0;
        m_modAttackSpeedPct[i] = 1.0f;
        m_attackTimer[i] = 0;
    }

    m_extraAttacks = 0;
    m_canDualWield = false;

    m_movementCounter = 0;

    m_state = 0;
    m_deathState = ALIVE;

    for (uint8 i = 0; i < CURRENT_MAX_SPELL; ++i)
        m_currentSpells[i] = nullptr;

    for (uint8 i = 0; i < MAX_SUMMON_SLOT; ++i)
        m_SummonSlot[i].Clear();

    for (uint8 i = 0; i < MAX_GAMEOBJECT_SLOT; ++i)
        m_ObjectSlot[i].Clear();

    m_auraUpdateIterator = m_ownedAuras.end();

    m_transform = 0;
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

    for (uint8 i = 0; i < MAX_STATS; ++i)
    {
        m_createStats[i] = 0.0f;
        m_floatStatPosBuff[i] = 0.0f;
        m_floatStatNegBuff[i] = 0.0f;
    }

    m_attacking = nullptr;
    if (GetTypeId() == TYPEID_PLAYER)
    {
        m_modMeleeHitChance = 7.5f;
        m_modRangedHitChance = 7.5f;
        m_modSpellHitChance = 15.0f;
    }
    else
    {
        m_modMeleeHitChance = 0.0f;
        m_modRangedHitChance = 0.0f;
        m_modSpellHitChance = 0.0f;
    }
    m_baseSpellCritChance = 5;


    for (uint8 i = 0; i < MAX_MOVE_TYPE; ++i)
        m_speed_rate[i] = 1.0f;

    m_charmInfo = nullptr;

    // remove aurastates allowing special moves
    for (uint8 i = 0; i < MAX_REACTIVE; ++i)
        m_reactiveTimer[i] = 0;

    m_cleanupDone = false;
    m_duringRemoveFromWorld = false;

    m_serverSideVisibility.SetValue(SERVERSIDE_VISIBILITY_GHOST, GHOST_VISIBILITY_ALIVE);

    _lastLiquid = nullptr;

    _oldFactionId = 0;
    _isWalkingBeforeCharm = false;
    _instantCast = false;
}

////////////////////////////////////////////////////////////
// Methods of class Unit
Unit::~Unit()
{
    // set current spells as deletable
    for (uint8 i = 0; i < CURRENT_MAX_SPELL; ++i)
        if (m_currentSpells[i])
        {
            m_currentSpells[i]->SetReferencedFromCurrent(false);
            m_currentSpells[i] = nullptr;
        }

    m_Events.KillAllEvents(true);

    _DeleteRemovedAuras();

    delete i_motionMaster;
    delete m_charmInfo;
    delete movespline;
    delete _spellHistory;

    ASSERT(!m_duringRemoveFromWorld);
    ASSERT(!m_attacking);
    ASSERT(m_attackers.empty());
    ASSERT(m_sharedVision.empty());
    ASSERT(m_Controlled.empty());
    ASSERT(m_appliedAuras.empty());
    ASSERT(m_ownedAuras.empty());
    ASSERT(m_removedAuras.empty());
    ASSERT(m_gameObj.empty());
    ASSERT(m_dynObj.empty());
}

void Unit::Update(uint32 p_time)
{
    // WARNING! Order of execution here is important, do not change.
    // Spells must be processed with event system BEFORE they go to _UpdateSpells.
    // Or else we may have some SPELL_STATE_FINISHED spells stalled in pointers, that is bad.
    m_Events.Update(p_time);

    if (!IsInWorld())
        return;

    _UpdateSpells(p_time);

    // If this is set during update SetCantProc(false) call is missing somewhere in the code
    // Having this would prevent spells from being proced, so let's crash
    ASSERT(!m_procDeep);

    m_combatManager.Update(p_time);

    // not implemented before 3.0.2
    if (uint32 base_att = getAttackTimer(BASE_ATTACK))
        setAttackTimer(BASE_ATTACK, (p_time >= base_att ? 0 : base_att - p_time));
    if (uint32 ranged_att = getAttackTimer(RANGED_ATTACK))
        setAttackTimer(RANGED_ATTACK, (p_time >= ranged_att ? 0 : ranged_att - p_time));
    if (uint32 off_att = getAttackTimer(OFF_ATTACK))
        setAttackTimer(OFF_ATTACK, (p_time >= off_att ? 0 : off_att - p_time));

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
    i_motionMaster->UpdateMotion(p_time);
}

bool Unit::haveOffhandWeapon() const
{
    if (Player const* player = ToPlayer())
        return player->GetWeaponForAttack(OFF_ATTACK, true) != nullptr;

    return CanDualWield();
}

void Unit::MonsterMoveWithSpeed(float x, float y, float z, float speed, bool generatePath, bool forceDestination)
{
    Movement::MoveSplineInit init(this);
    init.MoveTo(x, y, z, generatePath, forceDestination);
    init.SetVelocity(speed);
    init.Launch();
}

void Unit::UpdateSplineMovement(uint32 t_diff)
{
    if (movespline->Finalized())
        return;

    movespline->updateState(t_diff);
    bool arrived = movespline->Finalized();

    if (arrived)
        DisableSpline();

    m_movesplineTimer.Update(t_diff);
    if (m_movesplineTimer.Passed() || arrived)
        UpdateSplinePosition();
}

void Unit::UpdateSplinePosition()
{
    static uint32 const positionUpdateDelay = 400;

    m_movesplineTimer.Reset(positionUpdateDelay);
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
    }

    if (HasUnitState(UNIT_STATE_CANNOT_TURN))
        loc.orientation = GetOrientation();

    UpdatePosition(loc.x, loc.y, loc.z, loc.orientation);
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
    if (!obj || !IsInMap(obj) || !IsInPhase(obj))
        return false;

    float dx = GetPositionX() - obj->GetPositionX();
    float dy = GetPositionY() - obj->GetPositionY();
    float dz = GetPositionZ() - obj->GetPositionZ();
    float distsq = dx * dx + dy * dy + dz * dz;

    float sizefactor = GetCombatReach() + obj->GetCombatReach();
    float maxdist = dist2compare + sizefactor;

    return distsq < maxdist * maxdist;
}

bool Unit::IsWithinMeleeRange(Unit const* obj) const
{
    if (!obj || !IsInMap(obj) || !IsInPhase(obj))
        return false;

    float dx = GetPositionX() - obj->GetPositionX();
    float dy = GetPositionY() - obj->GetPositionY();
    float dz = GetPositionZMinusOffset() - obj->GetPositionZMinusOffset();
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
    if (!obj || !IsInMap(obj) || !IsInPhase(obj))
        return false;

    float objBoundaryRadius = std::max(obj->GetBoundingRadius(), MIN_MELEE_REACH);

    return IsInDist(obj, objBoundaryRadius);
}

void Unit::GetRandomContactPoint(Unit const* obj, float &x, float &y, float &z, float distance2dMin, float distance2dMax) const
{
    float combat_reach = GetCombatReach();
    if (combat_reach < 0.1f) // sometimes bugged for players
        combat_reach = DEFAULT_PLAYER_COMBAT_REACH;

    uint32 attacker_number = uint32(getAttackers().size());
    if (attacker_number > 0)
        --attacker_number;
    GetNearPoint(obj, x, y, z, obj->GetCombatReach(), distance2dMin+(distance2dMax-distance2dMin) * (float)rand_norm(),
        GetAngle(obj) + (attacker_number ? (static_cast<float>(M_PI/2) - static_cast<float>(M_PI) * (float)rand_norm()) * float(attacker_number) / combat_reach * 0.3f : 0));
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

/*static*/ uint32 Unit::DealDamage(Unit* attacker, Unit* victim, uint32 damage, CleanDamage const* cleanDamage, DamageEffectType damagetype, SpellSchoolMask damageSchoolMask, SpellInfo const* spellProto, bool durabilityLoss)
{
    if (victim->IsAIEnabled)
        victim->GetAI()->DamageTaken(attacker, damage);

    if (attacker && attacker->IsAIEnabled)
        attacker->GetAI()->DamageDealt(victim, damage, damagetype);

    // Hook for OnDamage Event
    sScriptMgr->OnDamage(attacker, victim, damage);

    if (victim->GetTypeId() == TYPEID_PLAYER && attacker != victim)
    {
        // Signal to pets that their owner was attacked - except when DOT.
        if (damagetype != DOT)
        {
            for (Unit* controlled : victim->m_Controlled)
                if (Creature* cControlled = controlled->ToCreature())
                    if (cControlled->IsAIEnabled)
                        cControlled->AI()->OwnerAttackedBy(attacker);
        }

        if (victim->ToPlayer()->GetCommandStatus(CHEAT_GOD))
            return 0;
    }

    if (damagetype != NODAMAGE)
    {
        // interrupting auras with SpellAuraInterruptFlags::Damage before checking !damage (absorbed damage breaks that type of auras)
        if (spellProto)
        {
            if (!spellProto->HasAttribute(SPELL_ATTR4_DAMAGE_DOESNT_BREAK_AURAS))
                victim->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::Damage, spellProto->Id);
        }
        else
            victim->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::Damage, 0);

        if (!damage && damagetype != DOT && cleanDamage && cleanDamage->absorbed_damage)
            if (victim != attacker && victim->GetTypeId() == TYPEID_PLAYER)
                if (Spell* spell = victim->m_currentSpells[CURRENT_GENERIC_SPELL])
                    if (spell->getState() == SPELL_STATE_PREPARING && spell->m_spellInfo->InterruptFlags.HasFlag(SpellInterruptFlags::DamageAbsorb))
                           victim->InterruptNonMeleeSpells(false);

        // We're going to call functions which can modify content of the list during iteration over it's elements
        // Let's copy the list so we can prevent iterator invalidation
        AuraEffectList vCopyDamageCopy(victim->GetAuraEffectsByType(SPELL_AURA_SHARE_DAMAGE_PCT));
        // copy damage to casters of this aura
        for (AuraEffectList::iterator i = vCopyDamageCopy.begin(); i != vCopyDamageCopy.end(); ++i)
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

            uint32 share = CalculatePct(damage, (*i)->GetAmount());

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

    if (!damage)
        return 0;

    uint32 health = victim->GetHealth();

    // duel ends when player has 1 or less hp
    bool duel_hasEnded = false;
    bool duel_wasMounted = false;
    if (victim->GetTypeId() == TYPEID_PLAYER && victim->ToPlayer()->duel && damage >= (health-1))
    {
        if (!attacker)
            return 0;

        // prevent kill only if killed in duel and killed by opponent or opponent controlled creature
        if (victim->ToPlayer()->duel->opponent == attacker || victim->ToPlayer()->duel->opponent->GetGUID() == attacker->GetOwnerGUID())
            damage = health - 1;

        duel_hasEnded = true;
    }
    else if (victim->IsVehicle() && damage >= (health-1) && victim->GetCharmer() && victim->GetCharmer()->GetTypeId() == TYPEID_PLAYER)
    {
        Player* victimRider = victim->GetCharmer()->ToPlayer();

        if (victimRider && victimRider->duel && victimRider->duel->isMounted)
        {
            if (!attacker)
                return 0;

            // prevent kill only if killed in duel and killed by opponent or opponent controlled creature
            if (victimRider->duel->opponent == attacker || victimRider->duel->opponent->GetGUID() == attacker->GetCharmerGUID())
                damage = health - 1;

            duel_wasMounted = true;
            duel_hasEnded = true;
        }
    }

    if (attacker && attacker != victim)
    {
        if (Player* killer = attacker->ToPlayer())
        {
            // in bg, count dmg if victim is also a player
            if (victim->GetTypeId() == TYPEID_PLAYER)
                if (Battleground* bg = killer->GetBattleground())
                    bg->UpdatePlayerScore(killer, SCORE_DAMAGE_DONE, damage);

            killer->UpdateCriteria(CRITERIA_TYPE_DAMAGE_DONE, health > damage ? damage : health, 0, 0, victim);
            killer->UpdateCriteria(CRITERIA_TYPE_HIGHEST_HIT_DEALT, damage);
        }
    }

    if (victim->GetTypeId() == TYPEID_PLAYER)
        victim->ToPlayer()->UpdateCriteria(CRITERIA_TYPE_HIGHEST_HIT_RECEIVED, damage);

    if (attacker)
        damage /= victim->GetHealthMultiplierForTarget(attacker);

    if (victim->GetTypeId() != TYPEID_PLAYER && (!victim->IsControlledByPlayer() || victim->IsVehicle()))
    {
        if (!victim->ToCreature()->hasLootRecipient())
            victim->ToCreature()->SetLootRecipient(attacker);

        if (!attacker || attacker->IsControlledByPlayer())
            victim->ToCreature()->LowerPlayerDamageReq(health < damage ?  health : damage);
    }

    bool killed = false;
    bool skipSettingDeathState = false;

    if (health <= damage)
    {
        killed = true;

        if (victim->GetTypeId() == TYPEID_PLAYER && victim != attacker)
            victim->ToPlayer()->UpdateCriteria(CRITERIA_TYPE_TOTAL_DAMAGE_RECEIVED, health);

        if (damagetype != NODAMAGE && damagetype != SELF_DAMAGE && victim->HasAuraType(SPELL_AURA_SCHOOL_ABSORB_OVERKILL))
        {
            AuraEffectList vAbsorbOverkill = victim->GetAuraEffectsByType(SPELL_AURA_SCHOOL_ABSORB_OVERKILL);
            DamageInfo damageInfo = DamageInfo(attacker, victim, damage, spellProto, damageSchoolMask, damagetype,
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
                if (damage >= victim->CountPctFromMaxHealth(100 + absorbAurEff->GetMiscValueB()))
                    continue;

                // get amount which can be still absorbed by the aura
                int32 currentAbsorb = absorbAurEff->GetAmount();
                // aura with infinite absorb amount - let the scripts handle absorbtion amount, set here to 0 for safety
                if (currentAbsorb < 0)
                    currentAbsorb = 0;

                uint32 tempAbsorb = uint32(currentAbsorb);

                // This aura type is used both by Spirit of Redemption (death not really prevented, must grant all credit immediately) and Cheat Death (death prevented)
                // repurpose PreventDefaultAction for this
                bool deathFullyPrevented = false;

                absorbAurEff->GetBase()->CallScriptEffectAbsorbHandlers(absorbAurEff, aurApp, damageInfo, tempAbsorb, deathFullyPrevented);
                currentAbsorb = tempAbsorb;

                // absorb must be smaller than the damage itself
                currentAbsorb = RoundToInterval(currentAbsorb, 0, int32(damageInfo.GetDamage()));
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

            damage = damageInfo.GetDamage();
        }
    }

    if (killed)
        Unit::Kill(attacker, victim, durabilityLoss, skipSettingDeathState);
    else
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            victim->ToPlayer()->UpdateCriteria(CRITERIA_TYPE_TOTAL_DAMAGE_RECEIVED, damage);

        victim->ModifyHealth(-(int32)damage);

        if (damagetype == DIRECT_DAMAGE || damagetype == SPELL_DIRECT_DAMAGE)
            victim->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::NonPeriodicDamage, spellProto ? spellProto->Id : 0);

        if (victim->GetTypeId() != TYPEID_PLAYER)
        {
            // Part of Evade mechanics. DoT's and Thorns / Retribution Aura do not contribute to this
            if (damagetype != DOT && damage > 0 && !victim->GetOwnerGUID().IsPlayer() && (!spellProto || !spellProto->HasAura(SPELL_AURA_DAMAGE_SHIELD)))
                victim->ToCreature()->SetLastDamagedTime(GameTime::GetGameTime() + MAX_AGGRO_RESET_TIME);

            if (attacker)
                victim->GetThreatManager().AddThreat(attacker, float(damage), spellProto);
        }
        else                                                // victim is a player
        {
            // random durability for items (HIT TAKEN)
            if (roll_chance_f(sWorld->getRate(RATE_DURABILITY_LOSS_DAMAGE)))
            {
                EquipmentSlots slot = EquipmentSlots(urand(0, EQUIPMENT_SLOT_END-1));
                victim->ToPlayer()->DurabilityPointLossForEquipSlot(slot);
            }
        }

        if (attacker && attacker->GetTypeId() == TYPEID_PLAYER)
        {
            // random durability for items (HIT DONE)
            if (roll_chance_f(sWorld->getRate(RATE_DURABILITY_LOSS_DAMAGE)))
            {
                EquipmentSlots slot = EquipmentSlots(urand(0, EQUIPMENT_SLOT_END-1));
                attacker->ToPlayer()->DurabilityPointLossForEquipSlot(slot);
            }
        }

        if (damagetype != NODAMAGE)
        {
            if (victim != attacker
                && (!spellProto || !(spellProto->HasAttribute(SPELL_ATTR7_NO_PUSHBACK_ON_DAMAGE) || spellProto->HasAttribute(SPELL_ATTR3_TREAT_AS_PERIODIC))))
            {
                if (damagetype != DOT)
                {
                    if (Spell* spell = victim->m_currentSpells[CURRENT_GENERIC_SPELL])
                    {
                        if (spell->getState() == SPELL_STATE_PREPARING)
                        {
                            auto isCastInterrupted = [&]()
                            {
                                if (!damage)
                                    return spell->m_spellInfo->InterruptFlags.HasFlag(SpellInterruptFlags::ZeroDamageCancels);

                                if ((victim->IsPlayer() && spell->m_spellInfo->InterruptFlags.HasFlag(SpellInterruptFlags::DamageCancelsPlayerOnly)))
                                    return true;

                                if (spell->m_spellInfo->InterruptFlags.HasFlag(SpellInterruptFlags::DamageCancels))
                                    return true;

                                return false;
                            };

                            auto isCastDelayed = [&]()
                            {
                                if (!damage)
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

                    if (damage && victim->IsPlayer())
                        if (Spell* spell = victim->m_currentSpells[CURRENT_CHANNELED_SPELL])
                            if (spell->getState() == SPELL_STATE_CASTING && spell->m_spellInfo->HasChannelInterruptFlag(SpellAuraInterruptFlags::DamageChannelDuration))
                                spell->DelayedChannel();
                }
            }
        }

        // last damage from duel opponent
        if (duel_hasEnded)
        {
            Player* he = duel_wasMounted ? victim->GetCharmer()->ToPlayer() : victim->ToPlayer();

            ASSERT(he && he->duel);

            if (duel_wasMounted) // In this case victim == mount
                victim->SetHealth(1);
            else
                he->SetHealth(1);

            he->duel->opponent->CombatStopWithPets(true);
            he->CombatStopWithPets(true);

            he->CastSpell(he, 7267, true);                  // beg
            he->DuelComplete(DUEL_WON);
        }
    }

    return damage;
}

void Unit::CastStop(uint32 except_spellid)
{
    for (uint32 i = CURRENT_FIRST_NON_MELEE_SPELL; i < CURRENT_MAX_SPELL; i++)
        if (m_currentSpells[i] && m_currentSpells[i]->m_spellInfo->Id != except_spellid)
            InterruptSpell(CurrentSpellTypes(i), false);
}

void Unit::CastSpell(SpellCastTargets const& targets, uint32 spellId, CastSpellExtraArgs const& args)
{
    SpellInfo const* info = sSpellMgr->GetSpellInfo(spellId, args.CastDifficulty != DIFFICULTY_NONE ? args.CastDifficulty : GetMap()->GetDifficultyID());
    if (!info)
    {
        TC_LOG_ERROR("entities.unit", "CastSpell: unknown spell %u by caster %s", spellId, GetGUID().ToString().c_str());
        return;
    }

    Spell* spell = new Spell(this, info, args.TriggerFlags, args.OriginalCaster);
    for (auto const& pair : args.SpellValueOverrides)
        spell->SetSpellValue(pair.first, pair.second);

    spell->m_CastItem = args.CastItem;
    spell->prepare(targets, args.TriggeringAura);
}

void Unit::CastSpell(WorldObject* target, uint32 spellId, CastSpellExtraArgs const& args)
{
    SpellCastTargets targets;
    if (target)
    {
        if (Unit* unitTarget = target->ToUnit())
            targets.SetUnitTarget(unitTarget);
        else if (GameObject* goTarget = target->ToGameObject())
            targets.SetGOTarget(goTarget);
        else
        {
            TC_LOG_ERROR("entities.unit", "CastSpell: Invalid target %s passed to spell cast by %s", target->GetGUID().ToString().c_str(), GetGUID().ToString().c_str());
            return;
        }
    }
    CastSpell(targets, spellId, args);
}

void Unit::CastSpell(Position const& dest, uint32 spellId, CastSpellExtraArgs const& args)
{
    SpellCastTargets targets;
    targets.SetDst(dest);
    CastSpell(targets, spellId, args);
}

void Unit::CalculateSpellDamageTaken(SpellNonMeleeDamage* damageInfo, int32 damage, SpellInfo const* spellInfo, WeaponAttackType attackType, bool crit)
{
    if (damage < 0)
        return;

    Unit* victim = damageInfo->target;
    if (!victim || !victim->IsAlive())
        return;

    SpellSchoolMask damageSchoolMask = SpellSchoolMask(damageInfo->schoolMask);

    // Spells with SPELL_ATTR4_FIXED_DAMAGE ignore resilience because their damage is based off another spell's damage.
    if (!spellInfo->HasAttribute(SPELL_ATTR4_FIXED_DAMAGE))
    {
        if (Unit::IsDamageReducedByArmor(damageSchoolMask, spellInfo))
            damage = Unit::CalcArmorReducedDamage(damageInfo->attacker, victim, damage, spellInfo, attackType);

        bool blocked = false;
        // Per-school calc
        switch (spellInfo->DmgClass)
        {
            // Melee and Ranged Spells
            case SPELL_DAMAGE_CLASS_RANGED:
            case SPELL_DAMAGE_CLASS_MELEE:
            {
                // Physical Damage
                if (damageSchoolMask & SPELL_SCHOOL_MASK_NORMAL)
                {
                    // Spells with this attribute were already calculated in MeleeSpellHitResult
                    if (!spellInfo->HasAttribute(SPELL_ATTR3_BLOCKABLE_SPELL))
                    {
                        // Get blocked status
                        blocked = isSpellBlocked(victim, spellInfo, attackType);
                    }
                }

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
                    uint32 value = victim->GetBlockPercent(getLevel());
                    if (victim->isBlockCritical())
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
    Unit::CalcAbsorbResist(dmgInfo);
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
            damageInfo->ProcAttacker = PROC_FLAG_DONE_MELEE_AUTO_ATTACK | PROC_FLAG_DONE_MAINHAND_ATTACK;
            damageInfo->ProcVictim   = PROC_FLAG_TAKEN_MELEE_AUTO_ATTACK;
            break;
        case OFF_ATTACK:
            damageInfo->ProcAttacker = PROC_FLAG_DONE_MELEE_AUTO_ATTACK | PROC_FLAG_DONE_OFFHAND_ATTACK;
            damageInfo->ProcVictim   = PROC_FLAG_TAKEN_MELEE_AUTO_ATTACK;
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
    damage = MeleeDamageBonusDone(damageInfo->Target, damage, damageInfo->AttackType, DIRECT_DAMAGE, nullptr, SpellSchoolMask(damageInfo->DamageSchoolMask));
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
            damageInfo->Blocked = CalculatePct(damageInfo->Damage, damageInfo->Target->GetBlockPercent(getLevel()));
            if (damageInfo->Target->isBlockCritical())
                damageInfo->Blocked *= 2;

            damageInfo->OriginalDamage = damageInfo->Damage;
            damageInfo->Damage      -= damageInfo->Blocked;
            damageInfo->CleanDamage += damageInfo->Blocked;
            break;
        case MELEE_HIT_GLANCING:
        {
            damageInfo->HitInfo     |= HITINFO_GLANCING;
            damageInfo->TargetState  = VICTIMSTATE_HIT;
            int32 leveldif = int32(victim->getLevel()) - int32(getLevel());
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
        damageInfo->ProcVictim |= PROC_FLAG_TAKEN_DAMAGE;
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

    // Hmmmm dont like this emotes client must by self do all animations
    if (damageInfo->HitInfo & HITINFO_CRITICALHIT)
        victim->HandleEmoteCommand(EMOTE_ONESHOT_WOUND_CRITICAL);
    if (damageInfo->Blocked && damageInfo->TargetState != VICTIMSTATE_BLOCKS)
        victim->HandleEmoteCommand(EMOTE_ONESHOT_PARRY_SHIELD);

    if (damageInfo->TargetState == VICTIMSTATE_PARRY &&
        (GetTypeId() != TYPEID_UNIT || (ToCreature()->GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_NO_PARRY_HASTEN) == 0))
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
        if (victim->getLevel() < 30)
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
        AuraEffectList vDamageShieldsCopy(victim->GetAuraEffectsByType(SPELL_AURA_DAMAGE_SHIELD));
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

void Unit::HandleEmoteCommand(uint32 anim_id, Trinity::IteratorPair<int32 const*> spellVisualKitIds /*= {}*/)
{
    WorldPackets::Chat::Emote packet;
    packet.Guid = GetGUID();
    packet.EmoteID = anim_id;

    if (EmotesEntry const* emotesEntry = sEmotesStore.LookupEntry(anim_id))
        if (emotesEntry->AnimID == ANIM_MOUNT_SPECIAL || emotesEntry->AnimID == ANIM_MOUNT_SELF_SPECIAL)
            std::copy(spellVisualKitIds.begin(), spellVisualKitIds.end(), std::back_inserter(packet.SpellVisualKitIDs));

    SendMessageToSet(packet.Write(), true);
}

/*static*/ bool Unit::IsDamageReducedByArmor(SpellSchoolMask schoolMask, SpellInfo const* spellInfo /*= nullptr*/, int8 effIndex /*= -1*/)
{
    // only physical spells damage gets reduced by armor
    if ((schoolMask & SPELL_SCHOOL_MASK_NORMAL) == 0)
        return false;
    if (spellInfo)
    {
        // there are spells with no specific attribute but they have "ignores armor" in tooltip
        if (spellInfo->HasAttribute(SPELL_ATTR0_CU_IGNORE_ARMOR))
            return false;

        // bleeding effects are not reduced by armor
        if (effIndex != -1)
        {
            // bleeding effects are not reduced by armor
            if (SpellEffectInfo const* effect = spellInfo->GetEffect(effIndex))
            {
                if (effect->ApplyAuraName == SPELL_AURA_PERIODIC_DAMAGE ||
                    effect->Effect == SPELL_EFFECT_SCHOOL_DAMAGE)
                    if (spellInfo->GetEffectMechanicMask(effIndex) & (1 << MECHANIC_BLEED))
                        return false;
            }
        }
    }
    return true;
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
        attackerClass = Classes(attacker->getClass());
    }

    // Expansion and ContentTuningID necessary? Does Player get a ContentTuningID too ?
    float armorConstant = sDB2Manager.EvaluateExpectedStat(ExpectedStatType::ArmorConstant, attackerLevel, -2, 0, attackerClass);

    if (!(armor + armorConstant))
        return damage;

    float mitigation = std::min(armor / (armor + armorConstant), 0.85f);
    return std::max<uint32>(damage * (1.0f - mitigation), 0);
}

/*static*/ uint32 Unit::CalcSpellResistedDamage(Unit const* attacker, Unit* victim, uint32 damage, SpellSchoolMask schoolMask, SpellInfo const* spellInfo)
{
    // Magic damage, check for resists
    if (!(schoolMask & SPELL_SCHOOL_MASK_MAGIC))
        return 0;

    // Npcs can have holy resistance
    if ((schoolMask & SPELL_SCHOOL_MASK_HOLY) && victim->GetTypeId() != TYPEID_UNIT)
        return 0;

    // Ignore spells that can't be resisted
    if (spellInfo)
    {
        if (spellInfo->HasAttribute(SPELL_ATTR4_IGNORE_RESISTANCES))
            return 0;

        // Binary spells can't have damage part resisted
        if (spellInfo->HasAttribute(SPELL_ATTR0_CU_BINARY_SPELL))
            return 0;
    }

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

    float roll = float(rand_norm());
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

/*static*/ float Unit::CalculateAverageResistReduction(Unit const* attacker, SpellSchoolMask schoolMask, Unit const* victim, SpellInfo const* spellInfo /*= nullptr*/)
{
    float victimResistance = float(victim->GetResistance(schoolMask));
    if (attacker)
    {
        // pets inherit 100% of masters penetration
        // excluding traps
        Player const* player = attacker->GetSpellModOwner();
        if (player && attacker->GetEntry() != WORLD_TRIGGER)
        {
            victimResistance += float(player->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_TARGET_RESISTANCE, schoolMask));
            victimResistance -= float(player->GetSpellPenetrationItemMod());
        }
        else
            victimResistance += float(attacker->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_TARGET_RESISTANCE, schoolMask));
    }

    // holy resistance exists in pve and comes from level difference, ignore template values
    if (schoolMask & SPELL_SCHOOL_MASK_HOLY)
        victimResistance = 0.0f;

    // Chaos Bolt exception, ignore all target resistances (unknown attribute?)
    if (spellInfo && spellInfo->SpellFamilyName == SPELLFAMILY_WARLOCK && spellInfo->Id == 116858)
        victimResistance = 0.0f;

    victimResistance = std::max(victimResistance, 0.0f);

    // level-based resistance does not apply to binary spells, and cannot be overcome by spell penetration
    if (attacker && (!spellInfo || !spellInfo->HasAttribute(SPELL_ATTR0_CU_BINARY_SPELL)))
        victimResistance += std::max((float(victim->GetLevelForTarget(attacker)) - float(attacker->GetLevelForTarget(victim))) * 5.0f, 0.0f);

    static uint32 const bossLevel = 83;
    static float const bossResistanceConstant = 510.0f;
    uint32 level = attacker ? victim->GetLevelForTarget(attacker) : victim->getLevel();
    float resistanceConstant = 0.0f;

    if (level == bossLevel)
        resistanceConstant = bossResistanceConstant;
    else
        resistanceConstant = level * 5.0f;

    return victimResistance / (victimResistance + resistanceConstant);
}

/*static*/ void Unit::CalcAbsorbResist(DamageInfo& damageInfo)
{
    if (!damageInfo.GetVictim() || !damageInfo.GetVictim()->IsAlive() || !damageInfo.GetDamage())
        return;

    uint32 resistedDamage = Unit::CalcSpellResistedDamage(damageInfo.GetAttacker(), damageInfo.GetVictim(), damageInfo.GetDamage(), damageInfo.GetSchoolMask(), damageInfo.GetSpellInfo());
    damageInfo.ResistDamage(resistedDamage);

    // Ignore Absorption Auras
    float auraAbsorbMod = 0.f;
    if (Unit* attacker = damageInfo.GetAttacker())
        auraAbsorbMod = attacker->GetMaxPositiveAuraModifierByMiscMask(SPELL_AURA_MOD_TARGET_ABSORB_SCHOOL, damageInfo.GetSchoolMask());

    RoundToInterval(auraAbsorbMod, 0.0f, 100.0f);

    int32 absorbIgnoringDamage = CalculatePct(damageInfo.GetDamage(), auraAbsorbMod);
    damageInfo.ModifyDamage(-absorbIgnoringDamage);

    // We're going to call functions which can modify content of the list during iteration over it's elements
    // Let's copy the list so we can prevent iterator invalidation
    AuraEffectList vSchoolAbsorbCopy(damageInfo.GetVictim()->GetAuraEffectsByType(SPELL_AURA_SCHOOL_ABSORB));
    vSchoolAbsorbCopy.sort(Trinity::AbsorbAuraOrderPred());

    // absorb without mana cost
    for (AuraEffectList::iterator itr = vSchoolAbsorbCopy.begin(); (itr != vSchoolAbsorbCopy.end()) && (damageInfo.GetDamage() > 0); ++itr)
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
    AuraEffectList vManaShieldCopy(damageInfo.GetVictim()->GetAuraEffectsByType(SPELL_AURA_MANA_SHIELD));
    for (AuraEffectList::const_iterator itr = vManaShieldCopy.begin(); (itr != vManaShieldCopy.end()) && (damageInfo.GetDamage() > 0); ++itr)
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
            if (float manaMultiplier = absorbAurEff->GetSpellEffectInfo()->CalcValueMultiplier(absorbAurEff->GetCaster()))
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

    damageInfo.ModifyDamage(absorbIgnoringDamage);

    // split damage auras - only when not damaging self
    if (damageInfo.GetVictim() != damageInfo.GetAttacker())
    {
        // We're going to call functions which can modify content of the list during iteration over it's elements
        // Let's copy the list so we can prevent iterator invalidation
        AuraEffectList vSplitDamagePctCopy(damageInfo.GetVictim()->GetAuraEffectsByType(SPELL_AURA_SPLIT_DAMAGE_PCT));
        for (AuraEffectList::iterator itr = vSplitDamagePctCopy.begin(); itr != vSplitDamagePctCopy.end() && damageInfo.GetDamage() > 0; ++itr)
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

            SpellNonMeleeDamage log(damageInfo.GetAttacker(), caster, (*itr)->GetSpellInfo(), (*itr)->GetBase()->GetSpellVisual(), damageInfo.GetSchoolMask(), (*itr)->GetBase()->GetCastGUID());
            CleanDamage cleanDamage = CleanDamage(splitDamage, 0, BASE_ATTACK, MELEE_HIT_NORMAL);
            Unit::DealDamage(damageInfo.GetAttacker(), caster, splitDamage, &cleanDamage, DIRECT_DAMAGE, damageInfo.GetSchoolMask(), (*itr)->GetSpellInfo(), false);
            log.damage = splitDamage;
            log.originalDamage = splitDamage;
            log.absorb = split_absorb;
            caster->SendSpellNonMeleeDamageLog(&log);

            // break 'Fear' and similar auras
            Unit::ProcSkillsAndAuras(damageInfo.GetAttacker(), caster, PROC_FLAG_NONE, PROC_FLAG_TAKEN_SPELL_MAGIC_DMG_CLASS_NEG, PROC_SPELL_TYPE_DAMAGE, PROC_SPELL_PHASE_HIT, PROC_HIT_NONE, nullptr, &damageInfo, nullptr);
        }
    }
}

/*static*/ void Unit::CalcHealAbsorb(HealInfo& healInfo)
{
    if (!healInfo.GetHeal())
        return;

    // Need remove expired auras after
    bool existExpired = false;

    // absorb without mana cost
    AuraEffectList const& vHealAbsorb = healInfo.GetTarget()->GetAuraEffectsByType(SPELL_AURA_SCHOOL_HEAL_ABSORB);
    for (AuraEffectList::const_iterator i = vHealAbsorb.begin(); i != vHealAbsorb.end() && healInfo.GetHeal() > 0; ++i)
    {
        if (!((*i)->GetMiscValue() & healInfo.GetSpellInfo()->SchoolMask))
            continue;

        // Max Amount can be absorbed by this aura
        int32 currentAbsorb = (*i)->GetAmount();

        // Found empty aura (impossible but..)
        if (currentAbsorb <= 0)
        {
            existExpired = true;
            continue;
        }

        // currentAbsorb - damage can be absorbed by shield
        // If need absorb less damage
        currentAbsorb = std::min<int32>(healInfo.GetHeal(), currentAbsorb);

        healInfo.AbsorbHeal(currentAbsorb);

        // Reduce shield amount
        (*i)->ChangeAmount((*i)->GetAmount() - currentAbsorb);
        // Need remove it later
        if ((*i)->GetAmount() <= 0)
            existExpired = true;
    }

    // Remove all expired absorb auras
    if (existExpired)
    {
        for (AuraEffectList::const_iterator i = vHealAbsorb.begin(); i != vHealAbsorb.end();)
        {
            AuraEffect* auraEff = *i;
            ++i;
            if (auraEff->GetAmount() <= 0)
            {
                uint32 removedAuras = healInfo.GetTarget()->m_removedAurasCount;
                auraEff->GetBase()->Remove(AURA_REMOVE_BY_ENEMY_SPELL);
                if (removedAuras + 1 < healInfo.GetTarget()->m_removedAurasCount)
                    i = vHealAbsorb.begin();
            }
        }
    }
}

void Unit::AttackerStateUpdate(Unit* victim, WeaponAttackType attType, bool extra)
{
    if (HasUnitState(UNIT_STATE_CANNOT_AUTOATTACK) || HasUnitFlag(UNIT_FLAG_PACIFIED))
        return;

    if (!victim->IsAlive())
        return;

    if ((attType == BASE_ATTACK || attType == OFF_ATTACK) && !IsWithinLOSInMap(victim))
        return;

    AttackedTarget(victim, true);
    RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::Attacking);

    if (attType != BASE_ATTACK && attType != OFF_ATTACK)
        return;                                             // ignore ranged case

    if (GetTypeId() == TYPEID_UNIT && !HasUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED) && !HasUnitFlag2(UNIT_FLAG2_DISABLE_TURN))
        SetFacingToObject(victim, false); // update client side facing to face the target (prevents visual glitches when casting untargeted spells)

    // melee attack spell cast at main hand attack only - no normal melee dmg dealt
    if (attType == BASE_ATTACK && m_currentSpells[CURRENT_MELEE_SPELL] && !extra)
        m_currentSpells[CURRENT_MELEE_SPELL]->cast();
    else
    {
        // attack can be redirected to another target
        victim = GetMeleeHitRedirectTarget(victim);

        AuraEffectList const& meleeAttackOverrides = GetAuraEffectsByType(SPELL_AURA_OVERRIDE_AUTOATTACK_WITH_MELEE_SPELL);
        AuraEffect const* meleeAttackAuraEffect = nullptr;
        uint32 meleeAttackSpellId = 0;
        if (attType == BASE_ATTACK)
        {
            if (!meleeAttackOverrides.empty())
            {
                meleeAttackAuraEffect = meleeAttackOverrides.front();
                meleeAttackSpellId = meleeAttackAuraEffect->GetSpellEffectInfo()->TriggerSpell;
            }
        }
        else
        {
            auto itr = std::find_if(meleeAttackOverrides.begin(), meleeAttackOverrides.end(), [&](AuraEffect const* aurEff)
            {
                return aurEff->GetSpellEffectInfo()->MiscValue != 0;
            });
            if (itr != meleeAttackOverrides.end())
            {
                meleeAttackAuraEffect = *itr;
                meleeAttackSpellId = meleeAttackAuraEffect->GetSpellEffectInfo()->MiscValue;
            }
        }

        if (!meleeAttackAuraEffect)
        {
            CalcDamageInfo damageInfo;
            CalculateMeleeDamage(victim, &damageInfo, attType);
            // Send log damage message to client
            Unit::DealDamageMods(damageInfo.Attacker, victim, damageInfo.Damage, &damageInfo.Absorb);
            SendAttackStateUpdate(&damageInfo);

            DealMeleeDamage(&damageInfo, true);

            DamageInfo dmgInfo(damageInfo);
            Unit::ProcSkillsAndAuras(damageInfo.Attacker, damageInfo.Target, damageInfo.ProcAttacker, damageInfo.ProcVictim, PROC_SPELL_TYPE_NONE, PROC_SPELL_PHASE_NONE, dmgInfo.GetHitMask(), nullptr, &dmgInfo, nullptr);

            TC_LOG_DEBUG("entities.unit", "AttackerStateUpdate: %s attacked %s for %u dmg, absorbed %u, blocked %u, resisted %u.",
                GetGUID().ToString().c_str(), victim->GetGUID().ToString().c_str(), damageInfo.Damage, damageInfo.Absorb, damageInfo.Blocked, damageInfo.Resist);
        }
        else
        {
            CastSpellExtraArgs args;
            args.TriggerFlags = TRIGGERED_FULL_MASK;
            args.TriggeringAura = meleeAttackAuraEffect;
            CastSpell(victim, meleeAttackSpellId, args);

            uint32 hitInfo = HITINFO_AFFECTS_VICTIM | HITINFO_NO_ANIMATION;
            if (attType == OFF_ATTACK)
                hitInfo |= HITINFO_OFFHAND;

            SendAttackStateUpdate(hitInfo, victim, 0, GetMeleeDamageSchoolMask(), 0, 0, 0, VICTIMSTATE_HIT, 0);
        }
    }
}

void Unit::FakeAttackerStateUpdate(Unit* victim, WeaponAttackType attType /*= BASE_ATTACK*/)
{
    if (HasUnitState(UNIT_STATE_CANNOT_AUTOATTACK) || HasUnitFlag(UNIT_FLAG_PACIFIED))
        return;

    if (!victim->IsAlive())
        return;

    if ((attType == BASE_ATTACK || attType == OFF_ATTACK) && !IsWithinLOSInMap(victim))
        return;

    AttackedTarget(victim, true);
    RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::Attacking);

    if (attType != BASE_ATTACK && attType != OFF_ATTACK)
        return;                                             // ignore ranged case

    if (GetTypeId() == TYPEID_UNIT && !HasUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED) && !HasUnitFlag2(UNIT_FLAG2_DISABLE_TURN))
        SetFacingToObject(victim, false); // update client side facing to face the target (prevents visual glitches when casting untargeted spells)

    CalcDamageInfo damageInfo;
    damageInfo.Attacker = this;
    damageInfo.Target = victim;

    damageInfo.DamageSchoolMask = GetMeleeDamageSchoolMask();
    damageInfo.OriginalDamage = 0;
    damageInfo.Damage = 0;
    damageInfo.Absorb = 0;
    damageInfo.Resist = 0;

    damageInfo.AttackType = attType;
    damageInfo.CleanDamage = 0;
    damageInfo.Blocked = 0;

    damageInfo.TargetState = VICTIMSTATE_HIT;
    damageInfo.HitInfo = HITINFO_AFFECTS_VICTIM | HITINFO_NORMALSWING | HITINFO_FAKE_DAMAGE;
    if (attType == OFF_ATTACK)
        damageInfo.HitInfo |= HITINFO_OFFHAND;

    damageInfo.ProcAttacker = PROC_FLAG_NONE;
    damageInfo.ProcVictim = PROC_FLAG_NONE;
    damageInfo.HitOutCome = MELEE_HIT_NORMAL;

    SendAttackStateUpdate(&damageInfo);
}

void Unit::HandleProcExtraAttackFor(Unit* victim)
{
    while (m_extraAttacks)
    {
        AttackerStateUpdate(victim, BASE_ATTACK, true);
        --m_extraAttacks;
    }
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
    if (victim->IsNonMeleeSpellCast(false) || victim->HasUnitState(UNIT_STATE_CONTROLLED))
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
        !(GetTypeId() == TYPEID_UNIT && ToCreature()->GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_NO_CRUSH))
    {
        // add 2% chance per level, min. is 15%
        tmp = attackerLevel - victimLevel * 1000 - 1500;
        if (roll < (sum += tmp))
        {
            TC_LOG_DEBUG("entities.unit", "RollMeleeOutcomeAgainst: CRUSHING <%d, %d)", sum-tmp, sum);
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
        TC_LOG_DEBUG("entities.unit", "%s stopped attacking %s", GetGUID().ToString().c_str(), victim->GetGUID().ToString().c_str());
    else
        TC_LOG_DEBUG("entities.unit", "%s stopped attacking", GetGUID().ToString().c_str());
}

bool Unit::isSpellBlocked(Unit* victim, SpellInfo const* spellProto, WeaponAttackType attackType)
{
    // These spells can't be blocked
    if (spellProto && (spellProto->HasAttribute(SPELL_ATTR0_IMPOSSIBLE_DODGE_PARRY_BLOCK) || spellProto->HasAttribute(SPELL_ATTR3_IGNORE_HIT_RESULT)))
        return false;

    // Can't block when casting/controlled
    if (victim->IsNonMeleeSpellCast(false) || victim->HasUnitState(UNIT_STATE_CONTROLLED))
        return false;

    if (victim->HasAuraType(SPELL_AURA_IGNORE_HIT_DIRECTION) || victim->HasInArc(float(M_PI), this))
    {
        float blockChance = GetUnitBlockChance(attackType, victim);
        if (blockChance && roll_chance_f(blockChance))
            return true;
    }

    return false;
}

bool Unit::isBlockCritical()
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
    for (SpellEffectInfo const* effect : spellInfo->GetEffects())
    {
        if (!effect || !effect->IsEffect())
            break;

        int32 effectMech = spellInfo->GetEffectMechanic(effect->EffectIndex);
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
    if (spellInfo->HasAttribute(SPELL_ATTR0_IMPOSSIBLE_DODGE_PARRY_BLOCK))
        return SPELL_MISS_NONE;

    bool canDodge = true;
    bool canParry = true;
    bool canBlock = spellInfo->HasAttribute(SPELL_ATTR3_BLOCKABLE_SPELL);

    // if victim is casting or cc'd it can't avoid attacks
    if (victim->IsNonMeleeSpellCast(false) || victim->HasUnitState(UNIT_STATE_CONTROLLED))
    {
        canDodge = false;
        canParry = false;
        canBlock = false;
    }

    // Ranged attacks can only miss, resist and deflect
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
        return SPELL_MISS_NONE;
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
                TC_LOG_DEBUG("entities.unit", "Spell %u SPELL_AURA_IGNORE_COMBAT_RESULT has unhandled state %d", aurEff->GetId(), aurEff->GetMiscValue());
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

SpellMissInfo Unit::MagicSpellHitResult(Unit* victim, SpellInfo const* spellInfo) const
{
    // Can`t miss on dead target (on skinning for example)
    if (!victim->IsAlive() && victim->GetTypeId() != TYPEID_PLAYER)
        return SPELL_MISS_NONE;

    SpellSchoolMask schoolMask = spellInfo->GetSchoolMask();
    // PvP - PvE spell misschances per leveldif > 2
    int32 lchance = victim->GetTypeId() == TYPEID_PLAYER ? 7 : 11;
    int32 thisLevel = GetLevelForTarget(victim);
    if (GetTypeId() == TYPEID_UNIT && ToCreature()->IsTrigger())
        thisLevel = std::max<int32>(thisLevel, spellInfo->SpellLevel);
    int32 leveldif = int32(victim->GetLevelForTarget(this)) - thisLevel;
    int32 levelBasedHitDiff = leveldif;

    // Base hit chance from attacker and victim levels
    int32 modHitChance = 100;
    if (levelBasedHitDiff >= 0)
    {
        if (victim->GetTypeId() != TYPEID_PLAYER)
        {
            modHitChance = 94 - 3 * std::min(levelBasedHitDiff, 3);
            levelBasedHitDiff -= 3;
        }
        else
        {
            modHitChance = 96 - std::min(levelBasedHitDiff, 2);
            levelBasedHitDiff -= 2;
        }
        if (levelBasedHitDiff > 0)
            modHitChance -= lchance * std::min(levelBasedHitDiff, 7);
    }
    else
        modHitChance = 97 - levelBasedHitDiff;

    // Spellmod from SpellModOp::HitChance
    if (Player* modOwner = GetSpellModOwner())
        modOwner->ApplySpellMod(spellInfo, SpellModOp::HitChance, modHitChance);

    // Spells with SPELL_ATTR3_IGNORE_HIT_RESULT will ignore target's avoidance effects
    if (!spellInfo->HasAttribute(SPELL_ATTR3_IGNORE_HIT_RESULT))
    {
        // Chance hit from victim SPELL_AURA_MOD_ATTACKER_SPELL_HIT_CHANCE auras
        modHitChance += victim->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_ATTACKER_SPELL_HIT_CHANCE, schoolMask);
    }

    int32 HitChance = modHitChance * 100;
    // Increase hit chance from attacker SPELL_AURA_MOD_SPELL_HIT_CHANCE and attacker ratings
    HitChance += int32(m_modSpellHitChance * 100.0f);

    RoundToInterval(HitChance, 0, 10000);

    int32 tmp = 10000 - HitChance;

    int32 rand = irand(0, 9999);
    if (tmp > 0 && rand < tmp)
        return SPELL_MISS_MISS;

    // Chance resist mechanic (select max value from every mechanic spell effect)
    int32 resist_chance = victim->GetMechanicResistChance(spellInfo) * 100;

    // Roll chance
    if (resist_chance > 0 && rand < (tmp += resist_chance))
        return SPELL_MISS_RESIST;

    // cast by caster in front of victim
    if (!victim->HasUnitState(UNIT_STATE_CONTROLLED) && (victim->HasInArc(float(M_PI), this) || victim->HasAuraType(SPELL_AURA_IGNORE_HIT_DIRECTION)))
    {
        int32 deflect_chance = victim->GetTotalAuraModifier(SPELL_AURA_DEFLECT_SPELLS) * 100;
        if (deflect_chance > 0 && rand < (tmp += deflect_chance))
            return SPELL_MISS_DEFLECT;
    }

    return SPELL_MISS_NONE;
}

// Calculate spell hit result can be:
// Every spell can: Evade/Immune/Reflect/Sucesful hit
// For melee based spells:
//   Miss
//   Dodge
//   Parry
// For spells
//   Resist
SpellMissInfo Unit::SpellHitResult(Unit* victim, SpellInfo const* spellInfo, bool canReflect /*= false*/)
{
    // All positive spells can`t miss
    /// @todo client not show miss log for this spells - so need find info for this in dbc and use it!
    if (spellInfo->IsPositive() && !IsHostileTo(victim)) // prevent from affecting enemy by "positive" spell
        return SPELL_MISS_NONE;

    if (this == victim)
        return SPELL_MISS_NONE;

    // Return evade for units in evade mode
    if (victim->GetTypeId() == TYPEID_UNIT && victim->ToCreature()->IsEvadingAttacks())
        return SPELL_MISS_EVADE;

    // Try victim reflect spell
    if (canReflect)
    {
        int32 reflectchance = victim->GetTotalAuraModifier(SPELL_AURA_REFLECT_SPELLS);
        reflectchance += victim->GetTotalAuraModifierByMiscMask(SPELL_AURA_REFLECT_SPELLS_SCHOOL, spellInfo->GetSchoolMask());

        if (reflectchance > 0 && roll_chance_i(reflectchance))
            return SPELL_MISS_REFLECT;
    }

    if (spellInfo->HasAttribute(SPELL_ATTR3_IGNORE_HIT_RESULT))
        return SPELL_MISS_NONE;

    // Check for immune
    if (victim->IsImmunedToSpell(spellInfo, this))
        return SPELL_MISS_IMMUNE;

    // Damage immunity is only checked if the spell has damage effects, this immunity must not prevent aura apply
    // returns SPELL_MISS_IMMUNE in that case, for other spells, the SMSG_SPELL_GO must show hit
    if (spellInfo->HasOnlyDamageEffects() && victim->IsImmunedToDamage(spellInfo))
        return SPELL_MISS_IMMUNE;

    switch (spellInfo->DmgClass)
    {
        case SPELL_DAMAGE_CLASS_RANGED:
        case SPELL_DAMAGE_CLASS_MELEE:
            return MeleeSpellHitResult(victim, spellInfo);
        case SPELL_DAMAGE_CLASS_NONE:
            return SPELL_MISS_NONE;
        case SPELL_DAMAGE_CLASS_MAGIC:
            return MagicSpellHitResult(victim, spellInfo);
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
    if (attackType == RANGED_ATTACK)
        chance += GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_RANGED_CRIT_CHANCE);
    else
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

    _spellHistory->Update();
}

void Unit::_UpdateAutoRepeatSpell()
{
    SpellInfo const* autoRepeatSpellInfo = m_currentSpells[CURRENT_AUTOREPEAT_SPELL]->m_spellInfo;

    // check "realtime" interrupts
    // don't cancel spells which are affected by a SPELL_AURA_CAST_WHILE_WALKING effect
    if (((GetTypeId() == TYPEID_PLAYER && ToPlayer()->isMoving()) || IsNonMeleeSpellCast(false, false, true, autoRepeatSpellInfo->Id == 75)) &&
        !HasAuraTypeWithAffectMask(SPELL_AURA_CAST_WHILE_WALKING, autoRepeatSpellInfo))
    {
        // cancel wand shoot
        if (autoRepeatSpellInfo->Id != 75)
            InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
        m_AutoRepeatFirstCast = true;
        return;
    }

    // apply delay (Auto Shot (spellID 75) not affected)
    if (m_AutoRepeatFirstCast && getAttackTimer(RANGED_ATTACK) < 500 && autoRepeatSpellInfo->Id != 75)
        setAttackTimer(RANGED_ATTACK, 500);
    m_AutoRepeatFirstCast = false;

    // castroutine
    if (isAttackReady(RANGED_ATTACK))
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
        Spell* spell = new Spell(this, autoRepeatSpellInfo, TRIGGERED_FULL_MASK);
        spell->prepare(m_currentSpells[CURRENT_AUTOREPEAT_SPELL]->m_targets);

        // all went good, reset attack
        resetAttackTimer(RANGED_ATTACK);
    }
}

void Unit::SetCurrentCastSpell(Spell* pSpell)
{
    ASSERT(pSpell);                                         // NULL may be never passed here, use InterruptSpell or InterruptNonMeleeSpells

    CurrentSpellTypes CSpellType = pSpell->GetCurrentContainer();

    if (pSpell == m_currentSpells[CSpellType])             // avoid breaking self
        return;

    // break same type spell if it is not delayed
    InterruptSpell(CSpellType, false);

    // special breakage effects:
    switch (CSpellType)
    {
        case CURRENT_GENERIC_SPELL:
        {
            // generic spells always break channeled not delayed spells
            InterruptSpell(CURRENT_CHANNELED_SPELL, false);

            // autorepeat breaking
            if (m_currentSpells[CURRENT_AUTOREPEAT_SPELL])
            {
                // break autorepeat if not Auto Shot
                if (m_currentSpells[CURRENT_AUTOREPEAT_SPELL]->GetSpellInfo()->Id != 75)
                    InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
                m_AutoRepeatFirstCast = true;
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
            // only Auto Shoot does not break anything
            if (pSpell->GetSpellInfo()->Id != 75)
            {
                // generic autorepeats break generic non-delayed and channeled non-delayed spells
                InterruptSpell(CURRENT_GENERIC_SPELL, false);
                InterruptSpell(CURRENT_CHANNELED_SPELL, false);
            }
            // special action: set first cast flag
            m_AutoRepeatFirstCast = true;

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
    //TC_LOG_DEBUG("entities.unit", "Interrupt spell for unit %u.", GetEntry());
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

        if (GetTypeId() == TYPEID_UNIT && IsAIEnabled)
            ToCreature()->AI()->OnSpellCastInterrupt(spell->GetSpellInfo());
    }
}

void Unit::FinishSpell(CurrentSpellTypes spellType, bool ok /*= true*/)
{
    Spell* spell = m_currentSpells[spellType];
    if (!spell)
        return;

    if (spellType == CURRENT_CHANNELED_SPELL)
        spell->SendChannelUpdate(0);

    spell->finish(ok);
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
            if (!isAutoshoot || !(m_currentSpells[CURRENT_GENERIC_SPELL]->m_spellInfo->HasAttribute(SPELL_ATTR2_NOT_RESET_AUTO_ACTIONS)))
                return true;
        }
    }
    // channeled spells may be delayed, but they are still considered cast
    if (!skipChanneled && m_currentSpells[CURRENT_CHANNELED_SPELL] &&
        (m_currentSpells[CURRENT_CHANNELED_SPELL]->getState() != SPELL_STATE_FINISHED))
    {
        if (!isAutoshoot || !(m_currentSpells[CURRENT_CHANNELED_SPELL]->m_spellInfo->HasAttribute(SPELL_ATTR2_NOT_RESET_AUTO_ACTIONS)))
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

    // channeled spells during channel stage (after the initial cast timer) allow movement with a specific spell attribute
    if (Spell* spell = m_currentSpells[CURRENT_CHANNELED_SPELL])
        if (spell->getState() != SPELL_STATE_FINISHED && spell->IsChannelActive())
            if (spell->GetSpellInfo()->IsMoveAllowedChannel())
                return false;

    // prohibit movement for all other spell casts
    return true;
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
    if (IsInWater())
        return c->CanSwim();
    else
        return c->CanWalk() || c->CanFly();
}

bool Unit::IsInWater() const
{
    return GetMap()->IsInWater(GetPhaseShift(), GetPositionX(), GetPositionY(), GetPositionZ());
}

bool Unit::IsUnderWater() const
{
    return GetMap()->IsUnderWater(GetPhaseShift(), GetPositionX(), GetPositionY(), GetPositionZ());
}

void Unit::ProcessPositionDataChanged(PositionFullTerrainStatus const& data)
{
    WorldObject::ProcessPositionDataChanged(data);
    ProcessTerrainStatusUpdate(data.liquidStatus, data.liquidInfo);
}

void Unit::SetInWater(bool inWater)
{
    // remove appropriate auras if we are swimming/not swimming respectively
    if (inWater)
        RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::UnderWater);
    else
        RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::AboveWater);
}

void Unit::ProcessTerrainStatusUpdate(ZLiquidStatus status, Optional<LiquidData> const& liquidData)
{
    if (IsFlying() || (!IsControlledByPlayer()))
        return;

    SetInWater(status & MAP_LIQUID_STATUS_SWIMMING);

    // liquid aura handling
    LiquidTypeEntry const* curLiquid = nullptr;
    if ((status & MAP_LIQUID_STATUS_SWIMMING) && liquidData)
        curLiquid = sLiquidTypeStore.LookupEntry(liquidData->entry);
    if (curLiquid != _lastLiquid)
    {
        if (_lastLiquid && _lastLiquid->SpellID)
            RemoveAurasDueToSpell(_lastLiquid->SpellID);
        Player* player = GetCharmerOrOwnerPlayerOrPlayerItself();
        if (curLiquid && curLiquid->SpellID && (!player || !player->IsGameMaster()))
            CastSpell(this, curLiquid->SpellID, true);
        _lastLiquid = curLiquid;
    }
}

void Unit::DeMorph()
{
    SetDisplayId(GetNativeDisplayId());
}

Aura* Unit::_TryStackingOrRefreshingExistingAura(SpellInfo const* newAura, uint32 effMask, Unit* caster, int32* baseAmount /*= nullptr*/, Item* castItem /*= nullptr*/, ObjectGuid casterGUID /*= ObjectGuid::Empty*/, bool resetPeriodicTimer /*= true*/, ObjectGuid castItemGuid /*= ObjectGuid::Empty*/, uint32 castItemId /*= 0*/, int32 castItemLevel /*= -1*/)
{
    ASSERT(!casterGUID.IsEmpty() || caster);

    // Check if these can stack anyway
    if (!casterGUID && !newAura->IsStackableOnOneSlotWithDifferentCasters())
        casterGUID = caster->GetGUID();

    // passive and Incanter's Absorption and auras with different type can stack with themselves any number of times
    if (!newAura->IsMultiSlotAura())
    {
        // check if cast item changed
        if (castItem)
        {
            castItemGuid = castItem->GetGUID();
            if (Player* owner = castItem->GetOwner())
            {
                castItemId = castItem->GetEntry();
                castItemLevel = int32(castItem->GetItemLevel(owner));
            }
            else if (castItem->GetOwnerGUID() == caster->GetGUID())
            {
                castItemId = castItem->GetEntry();
                castItemLevel = int32(castItem->GetItemLevel(caster->ToPlayer()));
            }
        }

        // find current aura from spell and change it's stackamount, or refresh it's duration
        if (Aura* foundAura = GetOwnedAura(newAura->Id, casterGUID, (newAura->HasAttribute(SPELL_ATTR0_CU_ENCHANT_PROC)) ? castItemGuid : ObjectGuid::Empty, 0))
        {
            // effect masks do not match
            // extremely rare case
            // let's just recreate aura
            if (effMask != foundAura->GetEffectMask())
                return nullptr;

            // update basepoints with new values - effect amount will be recalculated in ModStackAmount
            for (SpellEffectInfo const* effect : newAura->GetEffects())
            {
                if (!effect)
                    continue;

                AuraEffect const* eff = foundAura->GetEffect(effect->EffectIndex);
                if (!eff)
                    continue;

                int bp;
                if (baseAmount)
                    bp = *(baseAmount + effect->EffectIndex);
                else
                    bp = effect->BasePoints;

                int32* oldBP = const_cast<int32*>(&(foundAura->GetEffect(effect->EffectIndex)->m_baseAmount)); // todo 6.x review GetBaseAmount and GetCastItemGUID in this case
                *oldBP = bp;
            }

            // correct cast item guid if needed
            if (castItemGuid != foundAura->GetCastItemGUID())
            {
                ObjectGuid* oldGUID = const_cast<ObjectGuid*>(&foundAura->m_castItemGuid);
                *oldGUID = castItemGuid;
                uint32* oldItemId = const_cast<uint32*>(&foundAura->m_castItemId);
                *oldItemId = castItemId;
                int32* oldItemLevel = const_cast<int32*>(&foundAura->m_castItemLevel);
                *oldItemLevel = castItemLevel;
            }

            // try to increase stack amount
            foundAura->ModStackAmount(1, AURA_REMOVE_BY_DEFAULT, resetPeriodicTimer);
            return foundAura;
        }
    }

    return nullptr;
}

void Unit::_AddAura(UnitAura* aura, Unit* caster)
{
    ASSERT(!m_cleanupDone);
    m_ownedAuras.insert(AuraMap::value_type(aura->GetId(), aura));

    _RemoveNoStackAurasDueToAura(aura);

    if (aura->IsRemoved())
        return;

    aura->SetIsSingleTarget(caster && (aura->GetSpellInfo()->IsSingleTarget() || aura->HasEffectType(SPELL_AURA_CONTROL_VEHICLE)));
    if (aura->IsSingleTarget())
    {
        ASSERT((IsInWorld() && !IsDuringRemoveFromWorld()) || (aura->GetCasterGUID() == GetGUID()) ||
                (IsLoading() && aura->HasEffectType(SPELL_AURA_CONTROL_VEHICLE)));
                /* @HACK: Player is not in world during loading auras.
                 *        Single target auras are not saved or loaded from database
                 *        but may be created as a result of aura links (player mounts with passengers)
                 */

        // register single target aura
        caster->GetSingleCastAuras().push_back(aura);
        // remove other single target auras
        Unit::AuraList& scAuras = caster->GetSingleCastAuras();
        for (Unit::AuraList::iterator itr = scAuras.begin(); itr != scAuras.end();)
        {
            if ((*itr) != aura &&
                (*itr)->IsSingleTargetWith(aura))
            {
                (*itr)->Remove();
                itr = scAuras.begin();
            }
            else
                ++itr;
        }
    }
}

// creates aura application instance and registers it in lists
// aura application effects are handled separately to prevent aura list corruption
AuraApplication * Unit::_CreateAuraApplication(Aura* aura, uint32 effMask)
{
    // can't apply aura on unit which is going to be deleted - to not create a memory leak
    ASSERT(!m_cleanupDone);
    // aura musn't be removed
    ASSERT(!aura->IsRemoved());

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
        m_interruptableAuras.push_back(aurApp);
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
void Unit::_ApplyAura(AuraApplication * aurApp, uint32 effMask)
{
    Aura* aura = aurApp->GetBase();

    _RemoveNoStackAurasDueToAura(aura);

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
}

// removes aura application from lists and unapplies effects
void Unit::_UnapplyAura(AuraApplicationMap::iterator &i, AuraRemoveMode removeMode)
{
    AuraApplication * aurApp = i->second;
    ASSERT(aurApp);
    ASSERT(!aurApp->GetRemoveMode());
    ASSERT(aurApp->GetTarget() == this);

    aurApp->SetRemoveMode(removeMode);
    Aura* aura = aurApp->GetBase();
    TC_LOG_DEBUG("spells", "Aura %u now is remove mode %d", aura->GetId(), removeMode);

    // dead loop is killing the server probably
    ASSERT(m_removedAurasCount < 0xFFFFFFFF);

    ++m_removedAurasCount;

    Unit* caster = aura->GetCaster();

    // Remove all pointers from lists here to prevent possible pointer invalidation on spellcast/auraapply/auraremove
    m_appliedAuras.erase(i);

    if (aura->GetSpellInfo()->HasAnyAuraInterruptFlag())
    {
        m_interruptableAuras.remove(aurApp);
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

    // only way correctly remove all auras from list
    //if (removedAuras != m_removedAurasCount) new aura may be added
        i = m_appliedAuras.begin();
}

void Unit::_UnapplyAura(AuraApplication * aurApp, AuraRemoveMode removeMode)
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

void Unit::_RemoveNoStackAurasDueToAura(Aura* aura)
{
    SpellInfo const* spellProto = aura->GetSpellInfo();

    // passive spell special case (only non stackable with ranks)
    if (spellProto->IsPassiveStackableWithRanks())
        return;

    if (!IsHighestExclusiveAura(aura))
    {
        if (!aura->GetSpellInfo()->IsAffectingArea())
        {
            Unit* caster = aura->GetCaster();
            if (caster && caster->GetTypeId() == TYPEID_PLAYER)
                Spell::SendCastResult(caster->ToPlayer(), aura->GetSpellInfo(), aura->GetSpellVisual(), aura->GetCastGUID(), SPELL_FAILED_AURA_BOUNCED);
        }

        aura->Remove();
        return;
    }

    bool remove = false;
    for (AuraApplicationMap::iterator i = m_appliedAuras.begin(); i != m_appliedAuras.end(); ++i)
    {
        if (remove)
        {
            remove = false;
            i = m_appliedAuras.begin();
        }

        if (aura->CanStackWith(i->second->GetBase()))
            continue;

        RemoveAura(i, AURA_REMOVE_BY_DEFAULT);
        if (i == m_appliedAuras.end())
            break;
        remove = true;
    }
}

void Unit::_RegisterAuraEffect(AuraEffect* aurEff, bool apply)
{
    if (apply)
        m_modAuras[aurEff->GetAuraType()].push_back(aurEff);
    else
        m_modAuras[aurEff->GetAuraType()].remove(aurEff);
}

// All aura base removes should go threw this function!
void Unit::RemoveOwnedAura(AuraMap::iterator &i, AuraRemoveMode removeMode)
{
    Aura* aura = i->second;
    ASSERT(!aura->IsRemoved());

    // if unit currently update aura list then make safe update iterator shift to next
    if (m_auraUpdateIterator == i)
        ++m_auraUpdateIterator;

    m_ownedAuras.erase(i);
    m_removedAuras.push_back(aura);

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
        TC_LOG_ERROR("spells", "Unit::RemoveOwnedAura() called with unallowed removeMode AURA_REMOVE_NONE, spellId %u", aura->GetId());
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

void Unit::RemoveAppliedAuras(std::function<bool(AuraApplication const*)> const& check)
{
    for (AuraApplicationMap::iterator iter = m_appliedAuras.begin(); iter != m_appliedAuras.end();)
    {
        if (check(iter->second))
        {
            RemoveAura(iter);
            continue;
        }
        ++iter;
    }
}

void Unit::RemoveOwnedAuras(std::function<bool(Aura const*)> const& check)
{
    for (AuraMap::iterator iter = m_ownedAuras.begin(); iter != m_ownedAuras.end();)
    {
        if (check(iter->second))
        {
            RemoveOwnedAura(iter);
            continue;
        }
        ++iter;
    }
}

void Unit::RemoveAppliedAuras(uint32 spellId, std::function<bool(AuraApplication const*)> const& check)
{
    for (AuraApplicationMap::iterator iter = m_appliedAuras.lower_bound(spellId); iter != m_appliedAuras.upper_bound(spellId);)
    {
        if (check(iter->second))
        {
            RemoveAura(iter);
            continue;
        }
        ++iter;
    }
}

void Unit::RemoveOwnedAuras(uint32 spellId, std::function<bool(Aura const*)> const& check)
{
    for (AuraMap::iterator iter = m_ownedAuras.lower_bound(spellId); iter != m_ownedAuras.upper_bound(spellId);)
    {
        if (check(iter->second))
        {
            RemoveOwnedAura(iter);
            continue;
        }
        ++iter;
    }
}

void Unit::RemoveAurasByType(AuraType auraType, std::function<bool(AuraApplication const*)> const& check)
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
            RemoveAura(aurApp);
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

void Unit::RemoveAurasDueToSpellByDispel(uint32 spellId, uint32 dispellerSpellId, ObjectGuid casterGUID, Unit* dispeller, uint8 chargesRemoved/*= 1*/)
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

            if (aura->GetSpellInfo()->HasAttribute(SPELL_ATTR7_DISPEL_CHARGES))
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

void Unit::RemoveAurasDueToSpellBySteal(uint32 spellId, ObjectGuid casterGUID, Unit* stealer)
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

            bool stealCharge = aura->GetSpellInfo()->HasAttribute(SPELL_ATTR7_DISPEL_CHARGES);
            // Cast duration to unsigned to prevent permanent aura's such as Righteous Fury being permanently added to caster
            uint32 dur = std::min(2u * MINUTE * IN_MILLISECONDS, uint32(aura->GetDuration()));

            if (Aura* oldAura = stealer->GetAura(aura->GetId(), aura->GetCasterGUID()))
            {
                if (stealCharge)
                    oldAura->ModCharges(1);
                else
                    oldAura->ModStackAmount(1);
                oldAura->SetDuration(int32(dur));
            }
            else
            {
                // single target state must be removed before aura creation to preserve existing single target aura
                if (aura->IsSingleTarget())
                    aura->UnregisterSingleTarget();

                if (Aura* newAura = Aura::TryRefreshStackOrCreate(aura->GetSpellInfo(), aura->GetCastGUID(), effMask, stealer, nullptr, aura->GetCastDifficulty(), &baseDamage[0], nullptr, aura->GetCasterGUID()))
                {
                    // created aura must not be single target aura,, so stealer won't loose it on recast
                    if (newAura->IsSingleTarget())
                    {
                        newAura->UnregisterSingleTarget();
                        // bring back single target aura status to the old aura
                        aura->SetIsSingleTarget(true);
                        caster->GetSingleCastAuras().push_back(aura);
                    }
                    // FIXME: using aura->GetMaxDuration() maybe not blizzlike but it fixes stealing of spells like Innervate
                    newAura->SetLoadedState(aura->GetMaxDuration(), int32(dur), stealCharge ? 1 : aura->GetCharges(), 1, recalculateMask, &damage[0]);
                    newAura->ApplyForTargets();
                }
            }

            if (stealCharge)
                aura->ModCharges(-1, AURA_REMOVE_BY_ENEMY_SPELL);
            else
                aura->ModStackAmount(-1, AURA_REMOVE_BY_ENEMY_SPELL);

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
                if (!caster || !caster->IsInPhase(this))
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
        if (aura->GetUnitOwner() != this && (!onPhaseChange || !aura->GetUnitOwner()->IsInPhase(this)))
        {
            aura->Remove();
            iter = scAuras.begin();
        }
        else
            ++iter;
    }
}

template<typename InterruptFlag>
bool IsInterruptFlagIgnoredForSpell(InterruptFlag /*flag*/, Unit const* /*unit*/, SpellInfo const* /*spellInfo*/)
{
    return false;
}

template<>
bool IsInterruptFlagIgnoredForSpell(SpellAuraInterruptFlags flag, Unit const* unit, SpellInfo const* spellInfo)
{
    return flag == SpellAuraInterruptFlags::Moving && unit->HasAuraTypeWithAffectMask(SPELL_AURA_CAST_WHILE_WALKING, spellInfo);
}

template <typename InterruptFlags>
void Unit::RemoveAurasWithInterruptFlags(InterruptFlags flag, uint32 except)
{
    if (!HasInterruptFlag(flag))
        return;

    // interrupt auras
    for (AuraApplicationList::iterator iter = m_interruptableAuras.begin(); iter != m_interruptableAuras.end();)
    {
        Aura* aura = (*iter)->GetBase();
        ++iter;
        if (aura->GetSpellInfo()->HasAuraInterruptFlag(flag)
            && (!except || aura->GetId() != except)
            && !IsInterruptFlagIgnoredForSpell(flag, this, aura->GetSpellInfo()))
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
            && spell->GetSpellInfo()->Id != except
            && !IsInterruptFlagIgnoredForSpell(flag, this, spell->GetSpellInfo()))
            InterruptNonMeleeSpells(false);

    UpdateInterruptMask();
}

template TC_GAME_API void Unit::RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags flag, uint32 except);
template TC_GAME_API void Unit::RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags2 flag, uint32 except);

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
        RemoveAurasWithMechanic(1 << MECHANIC_ROOT);

    // Snares
    for (AuraApplicationMap::iterator iter = m_appliedAuras.begin(); iter != m_appliedAuras.end();)
    {
        Aura const* aura = iter->second->GetBase();
        if (aura->GetSpellInfo()->Mechanic == MECHANIC_SNARE)
        {
            RemoveAura(iter);
            continue;
        }

        // turn off snare auras by setting amount to 0
        for (SpellEffectInfo const* effect : aura->GetSpellInfo()->GetEffects())
        {
            if (!effect || !effect->IsEffect())
                continue;

            if (((1 << effect->EffectIndex) & iter->second->GetEffectMask()))
                aura->GetEffect(effect->EffectIndex)->ChangeAmount(0);
        }

        ++iter;
    }
}

void Unit::RemoveAurasWithMechanic(uint32 mechanic_mask, AuraRemoveMode removemode, uint32 except)
{
    for (AuraApplicationMap::iterator iter = m_appliedAuras.begin(); iter != m_appliedAuras.end();)
    {
        Aura const* aura = iter->second->GetBase();
        if (!except || aura->GetId() != except)
        {
            if (aura->GetSpellInfo()->GetAllEffectsMechanicMask() & mechanic_mask)
            {
                RemoveAura(iter, removemode);
                continue;
            }
        }
        ++iter;
    }
}

void Unit::RemoveAurasByShapeShift()
{
    uint32 mechanic_mask = (1 << MECHANIC_SNARE) | (1 << MECHANIC_ROOT);
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
    while (!m_appliedAuras.empty() || !m_ownedAuras.empty())
    {
        AuraApplicationMap::iterator aurAppIter;
        for (aurAppIter = m_appliedAuras.begin(); aurAppIter != m_appliedAuras.end();)
            _UnapplyAura(aurAppIter, AURA_REMOVE_BY_DEFAULT);

        AuraMap::iterator aurIter;
        for (aurIter = m_ownedAuras.begin(); aurIter != m_ownedAuras.end();)
            RemoveOwnedAura(aurIter);
    }
}

void Unit::RemoveArenaAuras()
{
    // in join, remove positive buffs, on end, remove negative
    // used to remove positive visible auras in arenas
    RemoveAppliedAuras([](AuraApplication const* aurApp)
    {
        Aura const* aura = aurApp->GetBase();
        return (!aura->GetSpellInfo()->HasAttribute(SPELL_ATTR4_DONT_REMOVE_IN_ARENA)                          // don't remove stances, shadowform, pally/hunter auras
            && !aura->IsPassive()                                                                              // don't remove passive auras
            && (aurApp->IsPositive() || !aura->GetSpellInfo()->HasAttribute(SPELL_ATTR3_DEATH_PERSISTENT))) || // not negative death persistent auras
            aura->GetSpellInfo()->HasAttribute(SPELL_ATTR5_REMOVE_ENTERING_ARENA);                             // special marker, always remove
    });
}

void Unit::RemoveAurasOnEvade()
{
    if (IsCharmedOwnedByPlayerOrPlayer()) // if it is a player owned creature it should not remove the aura
        return;

    // don't remove vehicle auras, passengers aren't supposed to drop off the vehicle
    // don't remove clone caster on evade (to be verified)
    RemoveAllAurasExceptType(SPELL_AURA_CONTROL_VEHICLE, SPELL_AURA_CLONE_CASTER);
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
            TC_LOG_DEBUG("spells", "Aura %u partially interrupted on %s, new duration: %u ms", aura->GetId(), GetGUID().ToString().c_str(), aura->GetDuration());
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

void Unit::GetDispellableAuraList(Unit* caster, uint32 dispelMask, DispelChargesList& dispelList, bool isReflect /*= false*/)  const
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
            bool const dispelCharges = aura->GetSpellInfo()->HasAttribute(SPELL_ATTR7_DISPEL_CHARGES);
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

bool Unit::HasAuraTypeWithCaster(AuraType auratype, ObjectGuid caster) const
{
    AuraEffectList const& mTotalAuraList = GetAuraEffectsByType(auratype);
    for (AuraEffectList::const_iterator i = mTotalAuraList.begin(); i != mTotalAuraList.end(); ++i)
        if (caster == (*i)->GetCasterGUID())
            return true;
    return false;
}

bool Unit::HasAuraTypeWithMiscvalue(AuraType auratype, int32 miscvalue) const
{
    AuraEffectList const& mTotalAuraList = GetAuraEffectsByType(auratype);
    for (AuraEffectList::const_iterator i = mTotalAuraList.begin(); i != mTotalAuraList.end(); ++i)
        if (miscvalue == (*i)->GetMiscValue())
            return true;
    return false;
}

bool Unit::HasAuraTypeWithAffectMask(AuraType auratype, SpellInfo const* affectedSpell) const
{
    AuraEffectList const& mTotalAuraList = GetAuraEffectsByType(auratype);
    for (AuraEffectList::const_iterator i = mTotalAuraList.begin(); i != mTotalAuraList.end(); ++i)
        if ((*i)->IsAffectingSpell(affectedSpell))
            return true;
    return false;
}

bool Unit::HasAuraTypeWithValue(AuraType auratype, int32 value) const
{
    AuraEffectList const& mTotalAuraList = GetAuraEffectsByType(auratype);
    for (AuraEffectList::const_iterator i = mTotalAuraList.begin(); i != mTotalAuraList.end(); ++i)
        if (value == (*i)->GetAmount())
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

bool Unit::HasAuraWithMechanic(uint32 mechanicMask) const
{
    for (AuraApplicationMap::const_iterator iter = m_appliedAuras.begin(); iter != m_appliedAuras.end(); ++iter)
    {
        SpellInfo const* spellInfo = iter->second->GetBase()->GetSpellInfo();
        if (spellInfo->Mechanic && (mechanicMask & (1 << spellInfo->Mechanic)))
            return true;

        for (SpellEffectInfo const* effect : spellInfo->GetEffects())
            if (effect && effect->Effect && effect->Mechanic)
                if (mechanicMask & (1 << effect->Mechanic))
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

int32 Unit::GetTotalAuraModifier(AuraType auratype, std::function<bool(AuraEffect const*)> const& predicate) const
{
    AuraEffectList const& mTotalAuraList = GetAuraEffectsByType(auratype);
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
            if (!sSpellMgr->AddSameEffectStackRuleSpellGroups(aurEff->GetSpellInfo(), static_cast<uint32>(auratype), aurEff->GetAmount(), sameEffectSpellGroup))
                modifier += aurEff->GetAmount();
        }
    }

    // Add the highest of the Same Effect Stack Rule SpellGroups to the accumulator
    for (auto itr = sameEffectSpellGroup.begin(); itr != sameEffectSpellGroup.end(); ++itr)
        modifier += itr->second;

    return modifier;
}

float Unit::GetTotalAuraMultiplier(AuraType auratype, std::function<bool(AuraEffect const*)> const& predicate) const
{
    AuraEffectList const& mTotalAuraList = GetAuraEffectsByType(auratype);
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
            if (!sSpellMgr->AddSameEffectStackRuleSpellGroups(aurEff->GetSpellInfo(), static_cast<uint32>(auratype), aurEff->GetAmount(), sameEffectSpellGroup))
                AddPct(multiplier, aurEff->GetAmount());
        }
    }

    // Add the highest of the Same Effect Stack Rule SpellGroups to the multiplier
    for (auto itr = sameEffectSpellGroup.begin(); itr != sameEffectSpellGroup.end(); ++itr)
        AddPct(multiplier, itr->second);

    return multiplier;
}

int32 Unit::GetMaxPositiveAuraModifier(AuraType auratype, std::function<bool(AuraEffect const*)> const& predicate) const
{
    AuraEffectList const& mTotalAuraList = GetAuraEffectsByType(auratype);
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

int32 Unit::GetMaxNegativeAuraModifier(AuraType auratype, std::function<bool(AuraEffect const*)> const& predicate) const
{
    AuraEffectList const& mTotalAuraList = GetAuraEffectsByType(auratype);
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

int32 Unit::GetTotalAuraModifier(AuraType auratype) const
{
    return GetTotalAuraModifier(auratype, [](AuraEffect const* /*aurEff*/) { return true; });
}

float Unit::GetTotalAuraMultiplier(AuraType auratype) const
{
    return GetTotalAuraMultiplier(auratype, [](AuraEffect const* /*aurEff*/) { return true; });
}

int32 Unit::GetMaxPositiveAuraModifier(AuraType auratype) const
{
    return GetMaxPositiveAuraModifier(auratype, [](AuraEffect const* /*aurEff*/) { return true; });
}

int32 Unit::GetMaxNegativeAuraModifier(AuraType auratype) const
{
    return GetMaxNegativeAuraModifier(auratype, [](AuraEffect const* /*aurEff*/) { return true; });
}

int32 Unit::GetTotalAuraModifierByMiscMask(AuraType auratype, uint32 miscMask) const
{
    return GetTotalAuraModifier(auratype, [miscMask](AuraEffect const* aurEff) -> bool
    {
        if ((aurEff->GetMiscValue() & miscMask) != 0)
            return true;
        return false;
    });
}

float Unit::GetTotalAuraMultiplierByMiscMask(AuraType auratype, uint32 miscMask) const
{
    return GetTotalAuraMultiplier(auratype, [miscMask](AuraEffect const* aurEff) -> bool
    {
        if ((aurEff->GetMiscValue() & miscMask) != 0)
            return true;
        return false;
    });
}

int32 Unit::GetMaxPositiveAuraModifierByMiscMask(AuraType auratype, uint32 miscMask, AuraEffect const* except /*= nullptr*/) const
{
    return GetMaxPositiveAuraModifier(auratype, [miscMask, except](AuraEffect const* aurEff) -> bool
    {
        if (except != aurEff && (aurEff->GetMiscValue() & miscMask) != 0)
            return true;
        return false;
    });
}

int32 Unit::GetMaxNegativeAuraModifierByMiscMask(AuraType auratype, uint32 miscMask) const
{
    return GetMaxNegativeAuraModifier(auratype, [miscMask](AuraEffect const* aurEff) -> bool
    {
        if ((aurEff->GetMiscValue() & miscMask) != 0)
            return true;
        return false;
    });
}

int32 Unit::GetTotalAuraModifierByMiscValue(AuraType auratype, int32 miscValue) const
{
    return GetTotalAuraModifier(auratype, [miscValue](AuraEffect const* aurEff) -> bool
    {
        if (aurEff->GetMiscValue() == miscValue)
            return true;
        return false;
    });
}

float Unit::GetTotalAuraMultiplierByMiscValue(AuraType auratype, int32 miscValue) const
{
    return GetTotalAuraMultiplier(auratype, [miscValue](AuraEffect const* aurEff) -> bool
    {
        if (aurEff->GetMiscValue() == miscValue)
            return true;
        return false;
    });
}

int32 Unit::GetMaxPositiveAuraModifierByMiscValue(AuraType auratype, int32 miscValue) const
{
    return GetMaxPositiveAuraModifier(auratype, [miscValue](AuraEffect const* aurEff) -> bool
    {
        if (aurEff->GetMiscValue() == miscValue)
            return true;
        return false;
    });
}

int32 Unit::GetMaxNegativeAuraModifierByMiscValue(AuraType auratype, int32 miscValue) const
{
    return GetMaxNegativeAuraModifier(auratype, [miscValue](AuraEffect const* aurEff) -> bool
    {
        if (aurEff->GetMiscValue() == miscValue)
            return true;
        return false;
    });
}

int32 Unit::GetTotalAuraModifierByAffectMask(AuraType auratype, SpellInfo const* affectedSpell) const
{
    return GetTotalAuraModifier(auratype, [affectedSpell](AuraEffect const* aurEff) -> bool
    {
        if (aurEff->IsAffectingSpell(affectedSpell))
            return true;
        return false;
    });
}

float Unit::GetTotalAuraMultiplierByAffectMask(AuraType auratype, SpellInfo const* affectedSpell) const
{
    return GetTotalAuraMultiplier(auratype, [affectedSpell](AuraEffect const* aurEff) -> bool
    {
        if (aurEff->IsAffectingSpell(affectedSpell))
            return true;
        return false;
    });
}

int32 Unit::GetMaxPositiveAuraModifierByAffectMask(AuraType auratype, SpellInfo const* affectedSpell) const
{
    return GetMaxPositiveAuraModifier(auratype, [affectedSpell](AuraEffect const* aurEff) -> bool
    {
        if (aurEff->IsAffectingSpell(affectedSpell))
            return true;
        return false;
    });
}

int32 Unit::GetMaxNegativeAuraModifierByAffectMask(AuraType auratype, SpellInfo const* affectedSpell) const
{
    return GetMaxNegativeAuraModifier(auratype, [affectedSpell](AuraEffect const* aurEff) -> bool
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

    UnitMods const unitMod = static_cast<UnitMods>(UNIT_MOD_STAT_START + stat);

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
    if (GetTypeId() == TYPEID_UNIT && IsAIEnabled)
        ToCreature()->AI()->JustRegisteredDynObject(dynObj);
}

void Unit::_UnregisterDynObject(DynamicObject* dynObj)
{
    m_dynObj.remove(dynObj);
    if (GetTypeId() == TYPEID_UNIT && IsAIEnabled)
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
    if (m_dynObj.empty())
        return;
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
        m_dynObj.front()->Remove();
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

    if (GetTypeId() == TYPEID_UNIT && ToCreature()->IsAIEnabled)
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

    if (GetTypeId() == TYPEID_UNIT && ToCreature()->IsAIEnabled)
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
    if (GetTypeId() == TYPEID_UNIT && IsAIEnabled)
        ToCreature()->AI()->JustRegisteredAreaTrigger(areaTrigger);
}

void Unit::_UnregisterAreaTrigger(AreaTrigger* areaTrigger)
{
    m_areaTrigger.erase(std::remove(m_areaTrigger.begin(), m_areaTrigger.end(), areaTrigger));
    if (GetTypeId() == TYPEID_UNIT && IsAIEnabled)
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
    if (m_areaTrigger.empty())
        return;
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
    if (m_areaTrigger.empty())
        return;
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
        m_areaTrigger.front()->Remove();
}

void Unit::SendSpellNonMeleeDamageLog(SpellNonMeleeDamage const* log)
{
    WorldPackets::CombatLog::SpellNonMeleeDamageLog packet;
    packet.Me = log->target->GetGUID();
    packet.CasterGUID = log->attacker->GetGUID();
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

/*static*/ void Unit::ProcSkillsAndAuras(Unit* actor, Unit* actionTarget, uint32 typeMaskActor, uint32 typeMaskActionTarget, uint32 spellTypeMask, uint32 spellPhaseMask, uint32 hitMask, Spell* spell, DamageInfo* damageInfo, HealInfo* healInfo)
{
    WeaponAttackType attType = damageInfo ? damageInfo->GetAttackType() : BASE_ATTACK;
    if (typeMaskActor && actor)
        actor->ProcSkillsAndReactives(false, actionTarget, typeMaskActor, hitMask, attType);

    if (typeMaskActionTarget && actionTarget)
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

void Unit::SendSpellMiss(Unit* target, uint32 spellID, SpellMissInfo missInfo)
{
    WorldPackets::CombatLog::SpellMissLog spellMissLog;
    spellMissLog.SpellID = spellID;
    spellMissLog.Caster = GetGUID();
    spellMissLog.Entries.emplace_back(target->GetGUID(), missInfo);
    SendMessageToSet(spellMissLog.Write(), true);
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

    packet.SubDmg = boost::in_place();
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

void Unit::SetPowerType(Powers new_powertype)
{
    if (GetPowerType() == new_powertype)
        return;

    SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::DisplayPower), new_powertype);

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

    // Update max power
    UpdateMaxPower(new_powertype);

    // Update current power
    switch (new_powertype)
    {
        case POWER_MANA: // Keep the same (druid form switching...)
        case POWER_ENERGY:
            break;
        case POWER_RAGE: // Reset to zero
            SetPower(POWER_RAGE, 0);
            break;
        case POWER_FOCUS: // Make it full
            SetFullPower(new_powertype);
            break;
        default:
            break;
    }
}

void Unit::UpdateDisplayPower()
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
            else if (GetTypeId() == TYPEID_PLAYER)
            {
                ChrClassesEntry const* cEntry = sChrClassesStore.LookupEntry(getClass());
                if (cEntry && cEntry->DisplayPower < MAX_POWERS)
                    displayPower = Powers(cEntry->DisplayPower);
            }
            else if (GetTypeId() == TYPEID_UNIT)
            {
                if (Vehicle* vehicle = GetVehicleKit())
                {
                    if (PowerDisplayEntry const* powerDisplay = sPowerDisplayStore.LookupEntry(vehicle->GetVehicleInfo()->PowerDisplayID[0]))
                        displayPower = Powers(powerDisplay->ActualType);
                    else if (getClass() == CLASS_ROGUE)
                        displayPower = POWER_ENERGY;
                }
                else if (Pet* pet = ToPet())
                {
                    if (pet->getPetType() == HUNTER_PET) // Hunter pets have focus
                        displayPower = POWER_FOCUS;
                    else if (pet->IsPetGhoul() || pet->IsPetAbomination()) // DK pets have energy
                        displayPower = POWER_ENERGY;
                }
            }
            break;
        }
    }

    SetPowerType(displayPower);
}

void Unit::SetSheath(SheathState sheathed)
{
    SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::SheatheState), sheathed);
    if (sheathed == SHEATH_STATE_UNARMED)
        RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::Sheathing);
}

FactionTemplateEntry const* Unit::GetFactionTemplateEntry() const
{
    FactionTemplateEntry const* entry = sFactionTemplateStore.LookupEntry(GetFaction());
    if (!entry)
    {
        if (Player const* player = ToPlayer())
            TC_LOG_ERROR("entities.unit", "Player %s has invalid faction (faction template id) #%u", player->GetName().c_str(), GetFaction());
        else if (Creature const* creature = ToCreature())
            TC_LOG_ERROR("entities.unit", "Creature (template id: %u) has invalid faction (faction template id) #%u", creature->GetCreatureTemplate()->Entry, GetFaction());
        else
            TC_LOG_ERROR("entities.unit", "Unit (name=%s, type=%u) has invalid faction (faction template id) #%u", GetName().c_str(), uint32(GetTypeId()), GetFaction());

        ABORT();
    }
    return entry;
}

// function based on function Unit::UnitReaction from 13850 client
ReputationRank Unit::GetReactionTo(Unit const* target) const
{
    // always friendly to self
    if (this == target)
        return REP_FRIENDLY;

    // always friendly to charmer or owner
    if (GetCharmerOrOwnerOrSelf() == target->GetCharmerOrOwnerOrSelf())
        return REP_FRIENDLY;

    Player const* selfPlayerOwner = GetAffectingPlayer();
    Player const* targetPlayerOwner = target->GetAffectingPlayer();

    // check forced reputation to support SPELL_AURA_FORCE_REACTION
    if (selfPlayerOwner)
    {
        if (FactionTemplateEntry const* targetFactionTemplateEntry = target->GetFactionTemplateEntry())
            if (ReputationRank const* repRank = selfPlayerOwner->GetReputationMgr().GetForcedRankIfAny(targetFactionTemplateEntry))
                return *repRank;
    }
    else if (targetPlayerOwner)
    {
        if (FactionTemplateEntry const* selfFactionTemplateEntry = GetFactionTemplateEntry())
            if (ReputationRank const* repRank = targetPlayerOwner->GetReputationMgr().GetForcedRankIfAny(selfFactionTemplateEntry))
                return *repRank;
    }

    if (HasUnitFlag(UNIT_FLAG_PVP_ATTACKABLE))
    {
        if (target->HasUnitFlag(UNIT_FLAG_PVP_ATTACKABLE))
        {
            if (selfPlayerOwner && targetPlayerOwner)
            {
                // always friendly to other unit controlled by player, or to the player himself
                if (selfPlayerOwner == targetPlayerOwner)
                    return REP_FRIENDLY;

                // duel - always hostile to opponent
                if (selfPlayerOwner->duel && selfPlayerOwner->duel->opponent == targetPlayerOwner && selfPlayerOwner->duel->startTime != 0)
                    return REP_HOSTILE;

                // same group - checks dependant only on our faction - skip FFA_PVP for example
                if (selfPlayerOwner->IsInRaidWith(targetPlayerOwner))
                    return REP_FRIENDLY; // return true to allow config option AllowTwoSide.Interaction.Group to work
                    // however client seems to allow mixed group parties, because in 13850 client it works like:
                    // return GetFactionReactionTo(GetFactionTemplateEntry(), target);
            }

            // check FFA_PVP
            if (IsFFAPvP() && target->IsFFAPvP())
                return REP_HOSTILE;

            if (selfPlayerOwner)
            {
                if (FactionTemplateEntry const* targetFactionTemplateEntry = target->GetFactionTemplateEntry())
                {
                    if (!selfPlayerOwner->HasUnitFlag2(UNIT_FLAG2_IGNORE_REPUTATION))
                    {
                        if (FactionEntry const* targetFactionEntry = sFactionStore.LookupEntry(targetFactionTemplateEntry->Faction))
                        {
                            if (targetFactionEntry->CanHaveReputation())
                            {
                                // check contested flags
                                if (targetFactionTemplateEntry->Flags & FACTION_TEMPLATE_FLAG_CONTESTED_GUARD
                                    && selfPlayerOwner->HasPlayerFlag(PLAYER_FLAGS_CONTESTED_PVP))
                                    return REP_HOSTILE;

                                // if faction has reputation, hostile state depends only from AtWar state
                                if (selfPlayerOwner->GetReputationMgr().IsAtWar(targetFactionEntry))
                                    return REP_HOSTILE;
                                return REP_FRIENDLY;
                            }
                        }
                    }
                }
            }
        }
    }
    // do checks dependant only on our faction
    return GetFactionReactionTo(GetFactionTemplateEntry(), target);
}

ReputationRank Unit::GetFactionReactionTo(FactionTemplateEntry const* factionTemplateEntry, Unit const* target)
{
    // always neutral when no template entry found
    if (!factionTemplateEntry)
        return REP_NEUTRAL;

    FactionTemplateEntry const* targetFactionTemplateEntry = target->GetFactionTemplateEntry();

    if (Player const* targetPlayerOwner = target->GetAffectingPlayer())
    {
        // check contested flags
        if (factionTemplateEntry->Flags & FACTION_TEMPLATE_FLAG_CONTESTED_GUARD
            && targetPlayerOwner->HasPlayerFlag(PLAYER_FLAGS_CONTESTED_PVP))
            return REP_HOSTILE;
        if (ReputationRank const* repRank = targetPlayerOwner->GetReputationMgr().GetForcedRankIfAny(factionTemplateEntry))
            return *repRank;
        if (!target->HasUnitFlag2(UNIT_FLAG2_IGNORE_REPUTATION))
        {
            if (FactionEntry const* factionEntry = sFactionStore.LookupEntry(factionTemplateEntry->Faction))
            {
                if (factionEntry->CanHaveReputation())
                {
                    // CvP case - check reputation, don't allow state higher than neutral when at war
                    ReputationRank repRank = targetPlayerOwner->GetReputationMgr().GetRank(factionEntry);
                    if (targetPlayerOwner->GetReputationMgr().IsAtWar(factionEntry))
                        repRank = std::min(REP_NEUTRAL, repRank);
                    return repRank;
                }
            }
        }
    }

    // common faction based check
    if (factionTemplateEntry->IsHostileTo(targetFactionTemplateEntry))
        return REP_HOSTILE;
    if (factionTemplateEntry->IsFriendlyTo(targetFactionTemplateEntry))
        return REP_FRIENDLY;
    if (targetFactionTemplateEntry->IsFriendlyTo(factionTemplateEntry))
        return REP_FRIENDLY;
    if (factionTemplateEntry->Flags & FACTION_TEMPLATE_FLAG_HOSTILE_BY_DEFAULT)
        return REP_HOSTILE;
    // neutral by default
    return REP_NEUTRAL;
}

bool Unit::IsHostileTo(Unit const* unit) const
{
    return GetReactionTo(unit) <= REP_HOSTILE;
}

bool Unit::IsFriendlyTo(Unit const* unit) const
{
    return GetReactionTo(unit) >= REP_FRIENDLY;
}

bool Unit::IsHostileToPlayers() const
{
    FactionTemplateEntry const* my_faction = GetFactionTemplateEntry();
    if (!my_faction->Faction)
        return false;

    FactionEntry const* raw_faction = sFactionStore.LookupEntry(my_faction->Faction);
    if (raw_faction && raw_faction->ReputationIndex >= 0)
        return false;

    return my_faction->IsHostileToPlayers();
}

bool Unit::IsNeutralToAll() const
{
    FactionTemplateEntry const* my_faction = GetFactionTemplateEntry();
    if (!my_faction->Faction)
        return true;

    FactionEntry const* raw_faction = sFactionStore.LookupEntry(my_faction->Faction);
    if (raw_faction && raw_faction->ReputationIndex >= 0)
        return false;

    return my_faction->IsNeutralToAll();
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

    if (HasUnitFlag(UNIT_FLAG_PACIFIED))
        return false;

    if (HasAuraType(SPELL_AURA_DISABLE_ATTACKING_EXCEPT_ABILITIES))
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

    if (creature && !IsPet())
    {
        EngageWithTarget(victim); // ensure that anything we're attacking has threat

        creature->SendAIReaction(AI_REACTION_HOSTILE);
        creature->CallAssistance();

        // Remove emote state - will be restored on creature reset
        SetEmoteState(EMOTE_ONESHOT_NONE);
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
                if (cControlled->IsAIEnabled)
                    cControlled->AI()->OwnerAttacked(victim);
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

        if (creature->HasSearchedAssistance())
        {
            creature->SetNoSearchAssistance(false);
            UpdateSpeed(MOVE_RUN);
        }
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

void Unit::CombatStop(bool includingCast, bool mutualPvP)
{
    if (includingCast && IsNonMeleeSpellCast(false))
        InterruptNonMeleeSpells(false);

    AttackStop();
    RemoveAllAttackers();
    if (GetTypeId() == TYPEID_PLAYER)
        ToPlayer()->SendAttackSwingCancelAttack();     // melee and ranged forced attack cancel

    if (mutualPvP)
        ClearInCombat();
    else
    { // vanish and brethren are weird
        m_combatManager.EndAllPvECombat();
        m_combatManager.SuppressPvPCombat();
    }
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
                    if (itr->second->state == PLAYERSPELL_REMOVED || itr->second->disabled)
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

Unit* Unit::GetOwner() const
{
    ObjectGuid ownerGUID = GetOwnerGUID();
    if (!ownerGUID.IsEmpty())
        return ObjectAccessor::GetUnit(*this, ownerGUID);

    return nullptr;
}

Unit* Unit::GetCharmer() const
{
    ObjectGuid charmerGUID = GetCharmerGUID();
    if (!charmerGUID.IsEmpty())
        return ObjectAccessor::GetUnit(*this, charmerGUID);

    return nullptr;
}

Player* Unit::GetCharmerOrOwnerPlayerOrPlayerItself() const
{
    ObjectGuid guid = GetCharmerOrOwnerGUID();
    if (guid.IsPlayer())
        return ObjectAccessor::GetPlayer(*this, guid);

    return const_cast<Unit*>(this)->ToPlayer();
}

Player* Unit::GetAffectingPlayer() const
{
    if (!GetCharmerOrOwnerGUID())
        return const_cast<Unit*>(this)->ToPlayer();

    if (Unit* owner = GetCharmerOrOwner())
        return owner->GetCharmerOrOwnerPlayerOrPlayerItself();

    return nullptr;
}

Minion* Unit::GetFirstMinion() const
{
    ObjectGuid pet_guid = GetMinionGUID();
    if (!pet_guid.IsEmpty())
    {
        if (Creature* pet = ObjectAccessor::GetCreatureOrPetOrVehicle(*this, pet_guid))
            if (pet->HasUnitTypeMask(UNIT_MASK_MINION))
                return (Minion*)pet;

        TC_LOG_ERROR("entities.unit", "Unit::GetFirstMinion: Minion %s not exist.", pet_guid.ToString().c_str());
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

        TC_LOG_FATAL("entities.unit", "Unit::GetGuardianPet: Guardian %s not exist.", pet_guid.ToString().c_str());
        const_cast<Unit*>(this)->SetPetGUID(ObjectGuid::Empty);
    }

    return nullptr;
}

Unit* Unit::GetCharm() const
{
    ObjectGuid charm_guid = GetCharmGUID();
    if (!charm_guid.IsEmpty())
    {
        if (Unit* pet = ObjectAccessor::GetUnit(*this, charm_guid))
            return pet;

        TC_LOG_ERROR("entities.unit", "Unit::GetCharm: Charmed creature %s not exist.", charm_guid.ToString().c_str());
        const_cast<Unit*>(this)->SetCharmGUID(ObjectGuid::Empty);
    }

    return nullptr;
}

Unit* Unit::GetCharmerOrOwner() const
{
    return !GetCharmerGUID().IsEmpty() ? GetCharmer() : GetOwner();
}

Unit* Unit::GetCharmerOrOwnerOrSelf() const
{
    if (Unit* u = GetCharmerOrOwner())
        return u;

    return (Unit*)this;
}

void Unit::SetMinion(Minion *minion, bool apply)
{
    TC_LOG_DEBUG("entities.unit", "SetMinion %u for %u, apply %u", minion->GetEntry(), GetEntry(), apply);

    if (apply)
    {
        if (!minion->GetOwnerGUID().IsEmpty())
        {
            TC_LOG_FATAL("entities.unit", "SetMinion: Minion %u is not the minion of owner %u", minion->GetEntry(), GetEntry());
            return;
        }

        minion->SetOwnerGUID(GetGUID());

        m_Controlled.insert(minion);

        if (GetTypeId() == TYPEID_PLAYER)
        {
            minion->m_ControlledByPlayer = true;
            minion->AddUnitFlag(UNIT_FLAG_PVP_ATTACKABLE);
        }

        // Can only have one pet. If a new one is summoned, dismiss the old one.
        if (minion->IsGuardianPet())
        {
            if (Guardian* oldPet = GetGuardianPet())
            {
                if (oldPet != minion && (oldPet->IsPet() || minion->IsPet() || oldPet->GetEntry() != minion->GetEntry()))
                {
                    // remove existing minion pet
                    if (oldPet->IsPet())
                        ((Pet*)oldPet)->Remove(PET_SAVE_AS_CURRENT);
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

        if (minion->m_Properties && SummonTitle(minion->m_Properties->Title) == SummonTitle::Companion)
        {
            SetCritterGUID(minion->GetGUID());
            if (Player const* thisPlayer = ToPlayer())
                minion->SetBattlePetCompanionGUID(thisPlayer->m_activePlayerData->SummonedBattlePetGUID);
        }

        // PvP, FFAPvP
        minion->SetPvpFlags(GetPvpFlags());

        // FIXME: hack, speed must be set only at follow
        if (GetTypeId() == TYPEID_PLAYER && minion->IsPet())
            for (uint8 i = 0; i < MAX_MOVE_TYPE; ++i)
                minion->SetSpeedRate(UnitMoveType(i), m_speed_rate[i]);

        // Send infinity cooldown - client does that automatically but after relog cooldown needs to be set again
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(minion->m_unitData->CreatedBySpell, GetMap()->GetDifficultyID());

        if (spellInfo && (spellInfo->IsCooldownStartedOnEvent()))
            GetSpellHistory()->StartCooldown(spellInfo, 0, nullptr, true);
    }
    else
    {
        if (minion->GetOwnerGUID() != GetGUID())
        {
            TC_LOG_FATAL("entities.unit", "SetMinion: Minion %u is not the minion of owner %u", minion->GetEntry(), GetEntry());
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
            if (SpellInfo const* spInfo = sSpellMgr->GetSpellInfo(minion->ToTotem()->GetSpell(), GetMap()->GetDifficultyID()))
                for (SpellEffectInfo const* effect : spInfo->GetEffects())
                    {
                        if (!effect || effect->Effect != SPELL_EFFECT_SUMMON)
                            continue;

                        RemoveAllMinionsByEntry(effect->MiscValue);
                    }
        }

        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(minion->m_unitData->CreatedBySpell, GetMap()->GetDifficultyID());
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
                    //if (GetCharmGUID() == (*itr)->GetGUID())
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
                    if (GetTypeId() == TYPEID_PLAYER && !GetCharmGUID())
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
            if (GetCharmGUID().IsEmpty())
                SetCharmGUID(charm->GetGUID());
            else
                TC_LOG_FATAL("entities.unit", "Player %s is trying to charm unit %u, but it already has a charmed unit %s", GetName().c_str(), charm->GetEntry(), GetCharmGUID().ToString().c_str());

            charm->m_ControlledByPlayer = true;
            /// @todo maybe we can use this flag to check if controlled by player
            charm->AddUnitFlag(UNIT_FLAG_PVP_ATTACKABLE);
        }
        else
            charm->m_ControlledByPlayer = false;

        // PvP, FFAPvP
        charm->SetPvpFlags(GetPvpFlags());

        if (charm->GetCharmGUID().IsEmpty())
            charm->SetCharmerGUID(GetGUID());
        else
            TC_LOG_FATAL("entities.unit", "Unit %u is being charmed, but it already has a charmer %s", charm->GetEntry(), charm->GetCharmerGUID().ToString().c_str());

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
            if (GetCharmGUID() == charm->GetGUID())
                SetCharmGUID(ObjectGuid::Empty);
            else
                TC_LOG_FATAL("entities.unit", "Player %s is trying to uncharm unit %u, but it has another charmed unit %s", GetName().c_str(), charm->GetEntry(), GetCharmGUID().ToString().c_str());
        }

        if (charm->GetCharmerGUID() == GetGUID())
            charm->SetCharmerGUID(ObjectGuid::Empty);
        else
            TC_LOG_FATAL("entities.unit", "Unit %u is being uncharmed, but it has another charmer %s", charm->GetEntry(), charm->GetCharmerGUID().ToString().c_str());

        if (charm->GetTypeId() == TYPEID_PLAYER)
        {
            charm->m_ControlledByPlayer = true;
            charm->AddUnitFlag(UNIT_FLAG_PVP_ATTACKABLE);
            charm->ToPlayer()->UpdatePvPState();
        }
        else if (Player* player = charm->GetCharmerOrOwnerPlayerOrPlayerItself())
        {
            charm->m_ControlledByPlayer = true;
            charm->AddUnitFlag(UNIT_FLAG_PVP_ATTACKABLE);
            charm->SetPvpFlags(player->GetPvpFlags());
        }
        else
        {
            charm->m_ControlledByPlayer = false;
            charm->RemoveUnitFlag(UNIT_FLAG_PVP_ATTACKABLE);
            charm->SetPvpFlags(UNIT_BYTE2_FLAG_NONE);
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

    if (healer)
    {
        if (victim->IsAIEnabled)
            victim->GetAI()->HealReceived(healer, addhealth);

        if (healer->IsAIEnabled)
            healer->GetAI()->HealDone(victim, addhealth);
    }

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
            if (Battleground* bg = player->GetBattleground())
                bg->UpdatePlayerScore(player, SCORE_HEALING_DONE, gain);

            // use the actual gain, as the overheal shall not be counted, skip gain 0 (it ignored anyway in to criteria)
            if (gain)
                player->UpdateCriteria(CRITERIA_TYPE_HEALING_DONE, gain, 0, 0, victim);

            player->UpdateCriteria(CRITERIA_TYPE_HIGHEST_HEAL_CAST, addhealth);
        }
    }

    if (Player* player = victim->ToPlayer())
    {
        player->UpdateCriteria(CRITERIA_TYPE_TOTAL_HEALING_RECEIVED, gain);
        player->UpdateCriteria(CRITERIA_TYPE_HIGHEST_HEALING_RECEIVED, addhealth);
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

Unit* Unit::GetMagicHitRedirectTarget(Unit* victim, SpellInfo const* spellInfo)
{
    // Patch 1.2 notes: Spell Reflection no longer reflects abilities
    if (spellInfo->HasAttribute(SPELL_ATTR0_ABILITY) || spellInfo->HasAttribute(SPELL_ATTR1_CANT_BE_REDIRECTED) || spellInfo->HasAttribute(SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY))
        return victim;

    Unit::AuraEffectList const& magnetAuras = victim->GetAuraEffectsByType(SPELL_AURA_SPELL_MAGNET);
    for (Unit::AuraEffectList::const_iterator itr = magnetAuras.begin(); itr != magnetAuras.end(); ++itr)
    {
        if (Unit* magnet = (*itr)->GetBase()->GetCaster())
            if (spellInfo->CheckExplicitTarget(this, magnet) == SPELL_CAST_OK
                && _IsValidAttackTarget(magnet, spellInfo))
            {
                /// @todo handle this charge drop by proc in cast phase on explicit target
                if (spellInfo->HasHitDelay())
                {
                    // Set up missile speed based delay
                    float hitDelay = spellInfo->LaunchDelay;
                    if (spellInfo->HasAttribute(SPELL_ATTR9_SPECIAL_DELAY_CALCULATION))
                        hitDelay += spellInfo->Speed;
                    else if (spellInfo->Speed > 0.0f)
                        hitDelay += std::max(victim->GetDistance(this), 5.0f) / spellInfo->Speed;

                    uint32 delay = uint32(std::floor(hitDelay * 1000.0f));
                    // Schedule charge drop
                    (*itr)->GetBase()->DropChargeDelayed(delay, AURA_REMOVE_BY_EXPIRE);
                }
                else
                    (*itr)->GetBase()->DropCharge(AURA_REMOVE_BY_EXPIRE);

                return magnet;
            }
    }
    return victim;
}

Unit* Unit::GetMeleeHitRedirectTarget(Unit* victim, SpellInfo const* spellInfo /*= nullptr*/)
{
    AuraEffectList const& interceptAuras = victim->GetAuraEffectsByType(SPELL_AURA_INTERCEPT_MELEE_RANGED_ATTACKS);
    for (AuraEffectList::const_iterator i = interceptAuras.begin(); i != interceptAuras.end(); ++i)
    {
        if (Unit* magnet = (*i)->GetBase()->GetCaster())
            if (_IsValidAttackTarget(magnet, spellInfo) && magnet->IsWithinLOSInMap(this)
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
    Unit* unit = GetCharm();
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
            TC_LOG_ERROR("entities.unit", "Unit %u is trying to release unit %u which is neither charmed nor owned by it", GetEntry(), target->GetEntry());
    }
    if (!GetPetGUID().IsEmpty())
        TC_LOG_FATAL("entities.unit", "Unit %u is not able to release its pet %s", GetEntry(), GetPetGUID().ToString().c_str());
    if (!GetMinionGUID().IsEmpty())
        TC_LOG_FATAL("entities.unit", "Unit %u is not able to release its minion %s", GetEntry(), GetMinionGUID().ToString().c_str());
    if (!GetCharmGUID().IsEmpty())
        TC_LOG_FATAL("entities.unit", "Unit %u is not able to release its charm %s", GetEntry(), GetCharmGUID().ToString().c_str());
    if (!IsPet()) // pets don't use the flag for this
        RemoveUnitFlag(UNIT_FLAG_PET_IN_COMBAT); // m_controlled is now empty, so we know none of our minions are in combat
}

bool Unit::isPossessedByPlayer() const
{
    return HasUnitState(UNIT_STATE_POSSESSED) && GetCharmerGUID().IsPlayer();
}

bool Unit::isPossessing(Unit* u) const
{
    return u->isPossessed() && GetCharmGUID() == u->GetGUID();
}

bool Unit::isPossessing() const
{
    if (Unit* u = GetCharm())
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
        SetWorldObject(true);
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
        SetWorldObject(false);
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

    TC_LOG_DEBUG("spells", "HealSpellLog -- SpellId: %u Caster: %s Target: %s (Health: %u OverHeal: %u Absorbed: %u Crit: %d)", healInfo.GetSpellInfo()->Id, healInfo.GetHealer()->GetGUID().ToString().c_str(), healInfo.GetTarget()->GetGUID().ToString().c_str(),
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
    int32 gain = victim->ModifyPower(powerType, damage, false);
    int32 overEnergize = damage - gain;
    victim->GetThreatManager().ForwardThreatForAssistingMe(this, float(damage) / 2, spellInfo, true);
    SendEnergizeSpellLog(victim, spellInfo->Id, gain, overEnergize, powerType);
}

uint32 Unit::SpellDamageBonusDone(Unit* victim, SpellInfo const* spellProto, uint32 pdamage, DamageEffectType damagetype, SpellEffectInfo const* effect, uint32 stack /*= 1*/) const
{
    if (!spellProto || !victim || damagetype == DIRECT_DAMAGE)
        return pdamage;

    // Some spells don't benefit from done mods
    if (spellProto->HasAttribute(SPELL_ATTR3_NO_DONE_BONUS))
        return pdamage;

    // For totems get damage bonus from owner
    if (GetTypeId() == TYPEID_UNIT && IsTotem())
        if (Unit* owner = GetOwner())
            return owner->SpellDamageBonusDone(victim, spellProto, pdamage, damagetype, effect, stack);

    int32 DoneTotal = 0;
    float DoneTotalMod = SpellDamagePctDone(victim, spellProto, damagetype);

    // Done fixed damage bonus auras
    int32 DoneAdvertisedBenefit  = SpellBaseDamageBonusDone(spellProto->GetSchoolMask());
    // modify spell power by victim's SPELL_AURA_MOD_DAMAGE_TAKEN auras (eg Amplify/Dampen Magic)
    DoneAdvertisedBenefit += victim->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_DAMAGE_TAKEN, spellProto->GetSchoolMask());

    // Pets just add their bonus damage to their spell damage
    // note that their spell damage is just gain of their own auras
    if (HasUnitTypeMask(UNIT_MASK_GUARDIAN))
        DoneAdvertisedBenefit += static_cast<Guardian const*>(this)->GetBonusDamage();

    // Check for table values
    if (effect->BonusCoefficientFromAP > 0.0f)
    {
        float ApCoeffMod = effect->BonusCoefficientFromAP;
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

            if (spellProto->HasAttribute(SPELL_ATTR3_REQ_OFFHAND) && !spellProto->HasAttribute(SPELL_ATTR3_MAIN_HAND))
                return OFF_ATTACK;

            return BASE_ATTACK;
        }();
        float APbonus = float(victim->GetTotalAuraModifier(attType != RANGED_ATTACK ? SPELL_AURA_MELEE_ATTACK_POWER_ATTACKER_BONUS : SPELL_AURA_RANGED_ATTACK_POWER_ATTACKER_BONUS));
        APbonus += GetTotalAttackPowerValue(attType);
        DoneTotal += int32(stack * ApCoeffMod * APbonus);
    }
    else
    {
        // No bonus damage for SPELL_DAMAGE_CLASS_NONE class spells by default
        if (spellProto->DmgClass == SPELL_DAMAGE_CLASS_NONE)
            return uint32(std::max(pdamage * DoneTotalMod, 0.0f));
    }

    // Default calculation
    float coeff = effect->BonusCoefficient;
    if (DoneAdvertisedBenefit)
    {
        if (Player* modOwner = GetSpellModOwner())
        {
            coeff *= 100.0f;
            modOwner->ApplySpellMod(spellProto, SpellModOp::BonusCoefficient, coeff);
            coeff /= 100.0f;
        }

        DoneTotal += int32(DoneAdvertisedBenefit * coeff * stack);
    }

    float tmpDamage = float(int32(pdamage) + DoneTotal) * DoneTotalMod;

    // apply spellmod to Done damage (flat and pct)
    if (Player* modOwner = GetSpellModOwner())
        modOwner->ApplySpellMod(spellProto, damagetype == DOT ? SpellModOp::PeriodicHealingAndDamage : SpellModOp::HealingAndDamage, tmpDamage);

    return uint32(std::max(tmpDamage, 0.0f));
}

float Unit::SpellDamagePctDone(Unit* victim, SpellInfo const* spellProto, DamageEffectType damagetype) const
{
    if (!spellProto || !victim || damagetype == DIRECT_DAMAGE)
        return 1.0f;

    // Some spells don't benefit from done mods
    if (spellProto->HasAttribute(SPELL_ATTR3_NO_DONE_BONUS))
        return 1.0f;

    // Some spells don't benefit from pct done mods
    if (spellProto->HasAttribute(SPELL_ATTR6_IGNORE_CASTER_DAMAGE_MODIFIERS))
        return 1.0f;

    // For totems get damage bonus from owner
    if (GetTypeId() == TYPEID_UNIT && IsTotem())
        if (Unit* owner = GetOwner())
            return owner->SpellDamagePctDone(victim, spellProto, damagetype);

    // Done total percent damage auras
    float DoneTotalMod = 1.0f;

    // Pet damage?
    if (GetTypeId() == TYPEID_UNIT && !IsPet())
        DoneTotalMod *= ToCreature()->GetSpellDamageMod(ToCreature()->GetCreatureTemplate()->rank);

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

    // Add SPELL_AURA_MOD_DAMAGE_DONE_FOR_MECHANIC percent bonus
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

uint32 Unit::SpellDamageBonusTaken(Unit* caster, SpellInfo const* spellProto, uint32 pdamage, DamageEffectType damagetype) const
{
    if (!spellProto || damagetype == DIRECT_DAMAGE)
        return pdamage;

    float TakenTotalMod = 1.0f;

    // Mod damage from spell mechanic
    if (uint32 mechanicMask = spellProto->GetAllEffectsMechanicMask())
    {
        TakenTotalMod *= GetTotalAuraMultiplier(SPELL_AURA_MOD_MECHANIC_DAMAGE_TAKEN_PERCENT, [mechanicMask](AuraEffect const* aurEff) -> bool
        {
            if (mechanicMask & uint32(1 << (aurEff->GetMiscValue())))
                return true;
            return false;
        });
    }

    if (AuraEffect const* cheatDeath = GetAuraEffect(45182, EFFECT_0))
        if (cheatDeath->GetMiscValue() & SPELL_SCHOOL_MASK_NORMAL)
            AddPct(TakenTotalMod, cheatDeath->GetAmount());

    // Spells with SPELL_ATTR4_FIXED_DAMAGE should only benefit from mechanic damage mod auras.
    if (!spellProto->HasAttribute(SPELL_ATTR4_FIXED_DAMAGE))
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
    return uint32(std::max(tmpDamage, 0.0f));
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
        case SPELL_DAMAGE_CLASS_MAGIC:
        {
            if (schoolMask & SPELL_SCHOOL_MASK_NORMAL)
                crit_chance = 0.0f;
            // For other schools
            else if (Player const* thisPlayer = ToPlayer())
                crit_chance = thisPlayer->m_activePlayerData->SpellCritPercentage;
            else
                crit_chance = (float)m_baseSpellCritChance;
            break;
        }
        case SPELL_DAMAGE_CLASS_MELEE:
        case SPELL_DAMAGE_CLASS_RANGED:
        {
            crit_chance += GetUnitCriticalChanceDone(attackType);
            break;
        }
        case SPELL_DAMAGE_CLASS_NONE:
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
                    case SPELLFAMILY_SHAMAN:
                        // Lava Burst
                        if (spellInfo->SpellFamilyFlags[1] & 0x00001000)
                        {
                            if (GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_SHAMAN, flag128(0x10000000, 0, 0), caster->GetGUID()))
                                if (GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_SPELL_AND_WEAPON_CRIT_CHANCE) > -100)
                                    return 100.0f;
                            break;
                        }
                        break;
                }

                // Spell crit suppression
                if (GetTypeId() == TYPEID_UNIT)
                {
                    int32 const levelDiff = static_cast<int32>(GetLevelForTarget(caster)) - caster->getLevel();
                    crit_chance -= levelDiff * 1.0f;
                }
            }
            break;
        }
        case SPELL_DAMAGE_CLASS_MELEE:

        /// Intentional fallback. Calculate critical strike chance for both Ranged and Melee spells
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

uint32 Unit::SpellHealingBonusDone(Unit* victim, SpellInfo const* spellProto, uint32 healamount, DamageEffectType damagetype, SpellEffectInfo const* spellEffect, uint32 stack /*= 1*/) const
{
    // For totems get healing bonus from owner (statue isn't totem in fact)
    if (GetTypeId() == TYPEID_UNIT && IsTotem())
        if (Unit* owner = GetOwner())
            return owner->SpellHealingBonusDone(victim, spellProto, healamount, damagetype, spellEffect, stack);

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
    float coeff = spellEffect->BonusCoefficient;
    if (spellEffect->BonusCoefficientFromAP > 0.0f)
    {
        WeaponAttackType const attType = (spellProto->IsRangedWeaponSpell() && spellProto->DmgClass != SPELL_DAMAGE_CLASS_MELEE) ? RANGED_ATTACK : BASE_ATTACK;
        float APbonus = float(victim->GetTotalAuraModifier(attType == BASE_ATTACK ? SPELL_AURA_MELEE_ATTACK_POWER_ATTACKER_BONUS : SPELL_AURA_RANGED_ATTACK_POWER_ATTACKER_BONUS));
        APbonus += GetTotalAttackPowerValue(attType);

        DoneTotal += int32(spellEffect->BonusCoefficientFromAP * stack * APbonus);
    }
    else if (coeff <= 0.0f) // no AP and no SP coefs, skip
    {
        // No bonus healing for SPELL_DAMAGE_CLASS_NONE class spells by default
        if (spellProto->DmgClass == SPELL_DAMAGE_CLASS_NONE)
            return uint32(std::max(healamount * DoneTotalMod, 0.0f));
    }

    // Default calculation
    if (DoneAdvertisedBenefit)
    {
        if (Player* modOwner = GetSpellModOwner())
        {
            coeff *= 100.0f;
            modOwner->ApplySpellMod(spellProto, SpellModOp::BonusCoefficient, coeff);
            coeff /= 100.0f;
        }

        DoneTotal += int32(DoneAdvertisedBenefit * coeff * stack);
    }

    for (SpellEffectInfo const* effect : spellProto->GetEffects())
    {
        if (!effect)
            continue;
        switch (effect->ApplyAuraName)
        {
            // Bonus healing does not apply to these spells
            case SPELL_AURA_PERIODIC_LEECH:
            case SPELL_AURA_PERIODIC_HEALTH_FUNNEL:
                DoneTotal = 0;
                break;
        }
        if (effect->Effect == SPELL_EFFECT_HEALTH_LEECH)
            DoneTotal = 0;
    }

    float heal = float(int32(healamount) + DoneTotal) * DoneTotalMod;

    // apply spellmod to Done amount
    if (Player* modOwner = GetSpellModOwner())
        modOwner->ApplySpellMod(spellProto, damagetype == DOT ? SpellModOp::PeriodicHealingAndDamage : SpellModOp::HealingAndDamage, heal);

    return uint32(std::max(heal, 0.0f));
}

float Unit::SpellHealingPctDone(Unit* victim, SpellInfo const* spellProto) const
{
    // For totems get healing bonus from owner
    if (GetTypeId() == TYPEID_UNIT && IsTotem())
        if (Unit* owner = GetOwner())
            return owner->SpellHealingPctDone(victim, spellProto);

    // Some spells don't benefit from done mods
    if (spellProto->HasAttribute(SPELL_ATTR3_NO_DONE_BONUS))
        return 1.0f;

    // Some spells don't benefit from done mods
    if (spellProto->HasAttribute(SPELL_ATTR6_IGNORE_HEALING_MODIFIERS))
        return 1.0f;

    // No bonus healing for potion spells
    if (spellProto->SpellFamilyName == SPELLFAMILY_POTION)
        return 1.0f;

    if (Player const* thisPlayer = ToPlayer())
    {
        float maxModDamagePercentSchool = 0.0f;
        for (uint32 i = 0; i < MAX_SPELL_SCHOOL; ++i)
            if (spellProto->GetSchoolMask() & (1 << i))
                maxModDamagePercentSchool = std::max(maxModDamagePercentSchool, thisPlayer->m_activePlayerData->ModHealingDonePercent[i]);

        return maxModDamagePercentSchool;
    }

    float DoneTotalMod = 1.0f;

    // bonus against aurastate
    DoneTotalMod *= GetTotalAuraMultiplier(SPELL_AURA_MOD_DAMAGE_DONE_VERSUS_AURASTATE, [victim](AuraEffect const* aurEff) -> bool
    {
        if (victim->HasAuraState(static_cast<AuraStateType>(aurEff->GetMiscValue())))
            return true;
        return false;
    });

    // Healing done percent
    DoneTotalMod *= GetTotalAuraMultiplier(SPELL_AURA_MOD_HEALING_DONE_PERCENT);

    // bonus from missing health of target
    float healthPctDiff = 100.0f - victim->GetHealthPct();
    for (AuraEffect const* healingDonePctVsTargetHealth : GetAuraEffectsByType(SPELL_AURA_MOD_HEALING_DONE_PCT_VERSUS_TARGET_HEALTH))
        if (healingDonePctVsTargetHealth->IsAffectingSpell(spellProto))
            AddPct(DoneTotalMod, CalculatePct(float(healingDonePctVsTargetHealth->GetAmount()), healthPctDiff));

    return DoneTotalMod;
}

uint32 Unit::SpellHealingBonusTaken(Unit* caster, SpellInfo const* spellProto, uint32 healamount, DamageEffectType damagetype) const
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
    return uint32(std::max(heal, 0.0f));
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
            Stats usedStat = Stats((*i)->GetSpellEffectInfo()->MiscValue);
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

bool Unit::IsImmunedToDamage(SpellInfo const* spellInfo) const
{
    if (!spellInfo)
        return false;

    // for example 40175
    if (spellInfo->HasAttribute(SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY) && spellInfo->HasAttribute(SPELL_ATTR3_IGNORE_HIT_RESULT))
        return false;

    if (spellInfo->HasAttribute(SPELL_ATTR1_UNAFFECTED_BY_SCHOOL_IMMUNE) || spellInfo->HasAttribute(SPELL_ATTR2_UNAFFECTED_BY_AURA_SCHOOL_IMMUNE))
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

bool Unit::IsImmunedToSpell(SpellInfo const* spellInfo, Unit* caster) const
{
    if (!spellInfo)
        return false;

    // Single spell immunity.
    SpellImmuneContainer const& idList = m_spellImmune[IMMUNITY_ID];
    if (idList.count(spellInfo->Id) > 0)
        return true;

    if (spellInfo->HasAttribute(SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY))
        return false;

    if (uint32 dispel = spellInfo->Dispel)
    {
        SpellImmuneContainer const& dispelList = m_spellImmune[IMMUNITY_DISPEL];
        if (dispelList.count(dispel) > 0)
            return true;
    }

    // Spells that don't have effectMechanics.
    if (uint32 mechanic = spellInfo->Mechanic)
    {
        SpellImmuneContainer const& mechanicList = m_spellImmune[IMMUNITY_MECHANIC];
        if (mechanicList.count(mechanic) > 0)
            return true;
    }

    bool immuneToAllEffects = true;
    for (SpellEffectInfo const* effect : spellInfo->GetEffects())
    {
        // State/effect immunities applied by aura expect full spell immunity
        // Ignore effects with mechanic, they are supposed to be checked separately
        if (!effect || !effect->IsEffect())
            continue;
        if (!IsImmunedToSpellEffect(spellInfo, effect->EffectIndex, caster))
        {
            immuneToAllEffects = false;
            break;
        }
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
            if (!(immuneSpellInfo && immuneSpellInfo->IsPositive() && spellInfo->IsPositive() && caster && IsFriendlyTo(caster)))
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

uint32 Unit::GetMechanicImmunityMask() const
{
    uint32 mask = 0;
    SpellImmuneContainer const& mechanicList = m_spellImmune[IMMUNITY_MECHANIC];
    for (auto itr = mechanicList.begin(); itr != mechanicList.end(); ++itr)
        mask |= (1 << itr->first);

    return mask;
}

bool Unit::IsImmunedToSpellEffect(SpellInfo const* spellInfo, uint32 index, Unit* caster) const
{
    if (!spellInfo)
        return false;

    SpellEffectInfo const* effect = spellInfo->GetEffect(index);
    if (!effect)
        return false;

    if (spellInfo->HasAttribute(SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY))
        return false;

    // If m_immuneToEffect type contain this effect type, IMMUNE effect.
    uint32 eff = effect->Effect;
    auto const& effectList = m_spellImmune[IMMUNITY_EFFECT];
    if (effectList.count(eff) > 0)
        return true;

    if (uint32 mechanic = effect->Mechanic)
    {
        SpellImmuneContainer const& mechanicList = m_spellImmune[IMMUNITY_MECHANIC];
        if (mechanicList.count(mechanic) > 0)
            return true;
    }

    if (!spellInfo->HasAttribute(SPELL_ATTR3_IGNORE_HIT_RESULT))
    {
        if (uint32 aura = effect->ApplyAuraName)
        {
            SpellImmuneContainer const& list = m_spellImmune[IMMUNITY_STATE];
            if (list.count(aura) > 0)
                return true;

            if (!spellInfo->HasAttribute(SPELL_ATTR2_UNAFFECTED_BY_AURA_SCHOOL_IMMUNE))
            {
                // Check for immune to application of harmful magical effects
                AuraEffectList const& immuneAuraApply = GetAuraEffectsByType(SPELL_AURA_MOD_IMMUNE_AURA_APPLY_SCHOOL);
                for (AuraEffectList::const_iterator iter = immuneAuraApply.begin(); iter != immuneAuraApply.end(); ++iter)
                    if (((*iter)->GetMiscValue() & spellInfo->GetSchoolMask()) &&                   // Check school
                        ((caster && !IsFriendlyTo(caster)) || !spellInfo->IsPositiveEffect(index))) // Harmful
                        return true;
            }
        }
    }

    return false;
}

uint32 Unit::MeleeDamageBonusDone(Unit* pVictim, uint32 damage, WeaponAttackType attType, DamageEffectType damagetype, SpellInfo const* spellProto /*= nullptr*/, SpellSchoolMask damageSchoolMask /*= SPELL_SCHOOL_MASK_NORMAL*/)
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

    // Add SPELL_AURA_MOD_DAMAGE_DONE_FOR_MECHANIC percent bonus
    if (spellProto)
        AddPct(DoneTotalMod, GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_DAMAGE_DONE_FOR_MECHANIC, spellProto->Mechanic));

    float damageF = damage;

    // apply spellmod to Done damage
    if (spellProto)
        if (Player* modOwner = GetSpellModOwner())
            modOwner->ApplySpellMod(spellProto, damagetype == DOT ? SpellModOp::PeriodicHealingAndDamage : SpellModOp::HealingAndDamage, damageF);

    damageF = (damageF + DoneFlatBenefit) * DoneTotalMod;

    // bonus result can be negative
    return uint32(std::max(damageF, 0.0f));
}

uint32 Unit::MeleeDamageBonusTaken(Unit* attacker, uint32 pdamage, WeaponAttackType attType, DamageEffectType damagetype, SpellInfo const* spellProto /*= nullptr*/, SpellSchoolMask damageSchoolMask /*= SPELL_SCHOOL_MASK_NORMAL*/)
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
        uint32 mechanicMask = spellProto->GetAllEffectsMechanicMask();

        // Shred, Maul - "Effects which increase Bleed damage also increase Shred damage"
        if (spellProto->SpellFamilyName == SPELLFAMILY_DRUID && spellProto->SpellFamilyFlags[0] & 0x00008800)
            mechanicMask |= (1<<MECHANIC_BLEED);

        if (mechanicMask)
        {
            TakenTotalMod *= GetTotalAuraMultiplier(SPELL_AURA_MOD_MECHANIC_DAMAGE_TAKEN_PERCENT, [mechanicMask](AuraEffect const* aurEff) -> bool
            {
                if (mechanicMask & uint32(1 << (aurEff->GetMiscValue())))
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
    return uint32(std::max(tmpDamage, 0.0f));
}

void Unit::ApplySpellImmune(uint32 spellId, uint32 op, uint32 type, bool apply)
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
    if (mount)
        SetMountDisplayId(mount);

    AddUnitFlag(UNIT_FLAG_MOUNT);

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

        // unsummon pet
        Pet* pet = player->GetPet();
        if (pet)
        {
            Battleground* bg = ToPlayer()->GetBattleground();
            // don't unsummon pet in arena but SetFlag UNIT_FLAG_STUNNED to disable pet's interface
            if (bg && bg->isArena())
                pet->AddUnitFlag(UNIT_FLAG_STUNNED);
            else
                player->UnsummonPetTemporaryIfAny();
        }

        // if we have charmed npc, stun him also (everywhere)
        if (Unit* charm = player->GetCharm())
            if (charm->GetTypeId() == TYPEID_UNIT)
                charm->AddUnitFlag(UNIT_FLAG_STUNNED);

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
        if (Pet* pPet = player->GetPet())
        {
            if (pPet->HasUnitFlag(UNIT_FLAG_STUNNED) && !pPet->HasUnitState(UNIT_STATE_STUNNED))
                pPet->RemoveUnitFlag(UNIT_FLAG_STUNNED);
        }
        else
            player->ResummonPetTemporaryUnSummonedIfAny();

        // if we have charmed npc, remove stun also
        if (Unit* charm = player->GetCharm())
            if (charm->GetTypeId() == TYPEID_UNIT && charm->HasUnitFlag(UNIT_FLAG_STUNNED) && !charm->HasUnitState(UNIT_STATE_STUNNED))
                charm->RemoveUnitFlag(UNIT_FLAG_STUNNED);
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
    uint32 mountFlags = 0;
    bool isSubmerged = false;
    bool isInWater = false;

    if (GetTypeId() == TYPEID_PLAYER)
        ridingSkill = ToPlayer()->GetSkillValue(SKILL_RIDING);

    if (HasAuraType(SPELL_AURA_MOUNT_RESTRICTIONS))
    {
        for (AuraEffect const* auraEffect : GetAuraEffectsByType(SPELL_AURA_MOUNT_RESTRICTIONS))
            mountFlags |= auraEffect->GetMiscValue();
    }
    else if (AreaTableEntry const* areaTable = sAreaTableStore.LookupEntry(areaId))
        mountFlags = areaTable->MountFlags;

    LiquidData liquid;
    ZLiquidStatus liquidStatus = GetMap()->GetLiquidStatus(GetPhaseShift(), GetPositionX(), GetPositionY(), GetPositionZ(), map_liquidHeaderTypeFlags::AllLiquids, &liquid);
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
            if (mountCapability->Flags & MOUNT_CAPABILITY_FLAG_GROUND && !(mountFlags & AREA_MOUNT_FLAG_GROUND_ALLOWED))
                continue;
            if (mountCapability->Flags & MOUNT_CAPABILITY_FLAG_FLYING && !(mountFlags & AREA_MOUNT_FLAG_FLYING_ALLOWED))
                continue;
            if (mountCapability->Flags & MOUNT_CAPABILITY_FLAG_FLOAT && !(mountFlags & AREA_MOUNT_FLAG_FLOAT_ALLOWED))
                continue;
            if (mountCapability->Flags & MOUNT_CAPABILITY_FLAG_UNDERWATER && !(mountFlags & AREA_MOUNT_FLAG_UNDERWATER_ALLOWED))
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
            else if (!(mountCapability->Flags & MOUNT_CAPABILITY_FLAG_UNDERWATER))
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
            if (PlayerConditionEntry const* playerCondition = sPlayerConditionStore.LookupEntry(mountCapability->PlayerConditionID))
                if (!ConditionMgr::IsPlayerMeetingCondition(thisPlayer, playerCondition))
                    continue;

        return mountCapability;
    }

    return nullptr;
}

bool Unit::IsServiceProvider() const
{
    return HasNpcFlag(NPCFlags(
        UNIT_NPC_FLAG_VENDOR | UNIT_NPC_FLAG_TRAINER | UNIT_NPC_FLAG_FLIGHTMASTER |
        UNIT_NPC_FLAG_PETITIONER | UNIT_NPC_FLAG_BATTLEMASTER | UNIT_NPC_FLAG_BANKER |
        UNIT_NPC_FLAG_INNKEEPER | UNIT_NPC_FLAG_SPIRITHEALER |
        UNIT_NPC_FLAG_SPIRITGUIDE | UNIT_NPC_FLAG_TABARDDESIGNER | UNIT_NPC_FLAG_AUCTIONEER));
}

void Unit::EngageWithTarget(Unit* enemy)
{
    if (!enemy)
        return;

    if (IsEngagedBy(enemy))
        return;

    if (CanHaveThreatList())
        m_threatManager.AddThreat(enemy, 0.0f, nullptr, true, true);
    else
        SetInCombatWith(enemy);

    if (Creature* creature = ToCreature())
        if (CreatureGroup* formation = creature->GetFormation())
            formation->MemberEngagingTarget(creature, enemy);
}

void Unit::AttackedTarget(Unit* target, bool canInitialAggro)
{
    if (!target->IsEngaged() && !canInitialAggro)
        return;
    target->EngageWithTarget(this);
    if (Unit* targetOwner = target->GetCharmerOrOwner())
        targetOwner->EngageWithTarget(this);

    Player* myPlayerOwner = GetCharmerOrOwnerPlayerOrPlayerItself();
    Player* targetPlayerOwner = target->GetCharmerOrOwnerPlayerOrPlayerItself();
    if (myPlayerOwner && targetPlayerOwner && !(myPlayerOwner->duel && myPlayerOwner->duel->opponent == targetPlayerOwner))
    {
        myPlayerOwner->UpdatePvP(true);
        myPlayerOwner->SetContestedPvP(targetPlayerOwner);
        myPlayerOwner->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::PvPActive);
    }
}

void Unit::SetImmuneToAll(bool apply, bool keepCombat)
{
    if (apply)
    {
        AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
        ValidateAttackersAndOwnTarget();
        if (keepCombat)
            m_threatManager.UpdateOnlineStates(true, true);
        else
            m_combatManager.EndAllCombat();
    }
    else
    {
        RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
        m_threatManager.UpdateOnlineStates(true, true);
    }
}

void Unit::SetImmuneToPC(bool apply, bool keepCombat)
{
    if (apply)
    {
        AddUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
        ValidateAttackersAndOwnTarget();
        if (keepCombat)
            m_threatManager.UpdateOnlineStates(true, true);
        else
        {
            std::list<CombatReference*> toEnd;
            for (auto const& pair : m_combatManager.GetPvECombatRefs())
                if (pair.second->GetOther(this)->HasUnitFlag(UNIT_FLAG_PVP_ATTACKABLE))
                    toEnd.push_back(pair.second);
            for (auto const& pair : m_combatManager.GetPvPCombatRefs())
                if (pair.second->GetOther(this)->HasUnitFlag(UNIT_FLAG_PVP_ATTACKABLE))
                    toEnd.push_back(pair.second);
            for (CombatReference* ref : toEnd)
                ref->EndCombat();
        }
    }
    else
    {
        RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
        m_threatManager.UpdateOnlineStates(true, true);
    }
}

void Unit::SetImmuneToNPC(bool apply, bool keepCombat)
{
    if (apply)
    {
        AddUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
        ValidateAttackersAndOwnTarget();
        if (keepCombat)
            m_threatManager.UpdateOnlineStates(true, true);
        else
        {
            std::list<CombatReference*> toEnd;
            for (auto const& pair : m_combatManager.GetPvECombatRefs())
                if (!pair.second->GetOther(this)->HasUnitFlag(UNIT_FLAG_PVP_ATTACKABLE))
                    toEnd.push_back(pair.second);
            for (auto const& pair : m_combatManager.GetPvPCombatRefs())
                if (!pair.second->GetOther(this)->HasUnitFlag(UNIT_FLAG_PVP_ATTACKABLE))
                    toEnd.push_back(pair.second);
            for (CombatReference* ref : toEnd)
                ref->EndCombat();
        }
    }
    else
    {
        RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
        m_threatManager.UpdateOnlineStates(true, true);
    }
}

bool Unit::IsThreatened() const
{
    return !m_threatManager.IsThreatListEmpty();
}

bool Unit::isTargetableForAttack(bool checkFakeDeath) const
{
    if (!IsAlive())
        return false;

    if (HasUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE)))
        return false;

    if (GetTypeId() == TYPEID_PLAYER && ToPlayer()->IsGameMaster())
        return false;

    return !HasUnitState(UNIT_STATE_UNATTACKABLE) && (!checkFakeDeath || !HasUnitState(UNIT_STATE_DIED));
}

bool Unit::IsValidAttackTarget(Unit const* target) const
{
    return _IsValidAttackTarget(target, nullptr);
}

// function based on function Unit::CanAttack from 13850 client
bool Unit::_IsValidAttackTarget(Unit const* target, SpellInfo const* bySpell, WorldObject const* obj) const
{
    ASSERT(target);

    // can't attack self
    if (this == target)
        return false;

    // can't attack unattackable units or GMs
    if (target->HasUnitState(UNIT_STATE_UNATTACKABLE)
        || (target->GetTypeId() == TYPEID_PLAYER && target->ToPlayer()->IsGameMaster()))
        return false;

    // visibility checks
    // skip visibility check for GO casts, needs removal when go cast is implemented. Also ignore for gameobject and dynauras
    if (GetEntry() != WORLD_TRIGGER && (!obj || !obj->isType(TYPEMASK_GAMEOBJECT | TYPEMASK_DYNAMICOBJECT)))
    {
        // can't attack invisible
        if (!bySpell || !bySpell->HasAttribute(SPELL_ATTR6_CAN_TARGET_INVISIBLE))
        {
            if (obj && !obj->CanSeeOrDetect(target, bySpell && bySpell->IsAffectingArea()))
                return false;
            else if (!obj)
            {
                // ignore stealth for aoe spells. Ignore stealth if target is player and unit in combat with same player
                bool const ignoreStealthCheck = (bySpell && bySpell->IsAffectingArea()) ||
                    (target->GetTypeId() == TYPEID_PLAYER && target->HasStealthAura() && IsInCombatWith(target));

                if (!CanSeeOrDetect(target, ignoreStealthCheck))
                    return false;
            }
        }
    }

    // can't attack dead
    if ((!bySpell || !bySpell->IsAllowingDeadTarget()) && !target->IsAlive())
       return false;

    // can't attack untargetable
    if ((!bySpell || !bySpell->HasAttribute(SPELL_ATTR6_CAN_TARGET_UNTARGETABLE))
        && target->HasUnitFlag(UNIT_FLAG_NOT_SELECTABLE))
        return false;

    if (Player const* playerAttacker = ToPlayer())
    {
        if (playerAttacker->HasPlayerFlag(PLAYER_FLAGS_UBER))
            return false;
    }

    // check flags
    if (target->HasUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_TAXI_FLIGHT | UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_UNK_16))
        || (!HasUnitFlag(UNIT_FLAG_PVP_ATTACKABLE) && target->IsImmuneToNPC())
        || (!target->HasUnitFlag(UNIT_FLAG_PVP_ATTACKABLE) && IsImmuneToNPC()))
        return false;

    if ((!bySpell || !bySpell->HasAttribute(SPELL_ATTR8_ATTACK_IGNORE_IMMUNE_TO_PC_FLAG))
        && (HasUnitFlag(UNIT_FLAG_PVP_ATTACKABLE) && target->IsImmuneToPC())
        // check if this is a world trigger cast - GOs are using world triggers to cast their spells, so we need to ignore their immunity flag here, this is a temp workaround, needs removal when go cast is implemented properly
        && GetEntry() != WORLD_TRIGGER)
        return false;

    // CvC case - can attack each other only when one of them is hostile
    if (!HasUnitFlag(UNIT_FLAG_PVP_ATTACKABLE) && !target->HasUnitFlag(UNIT_FLAG_PVP_ATTACKABLE))
        return GetReactionTo(target) <= REP_HOSTILE || target->GetReactionTo(this) <= REP_HOSTILE;

    // PvP, PvC, CvP case
    // can't attack friendly targets
    if (GetReactionTo(target) > REP_NEUTRAL
        || target->GetReactionTo(this) > REP_NEUTRAL)
        return false;

    Player const* playerAffectingAttacker = HasUnitFlag(UNIT_FLAG_PVP_ATTACKABLE) ? GetAffectingPlayer() : nullptr;
    Player const* playerAffectingTarget = target->HasUnitFlag(UNIT_FLAG_PVP_ATTACKABLE) ? target->GetAffectingPlayer() : nullptr;

    // Not all neutral creatures can be attacked (even some unfriendly faction does not react aggresive to you, like Sporaggar)
    if ((playerAffectingAttacker && !playerAffectingTarget) ||
        (!playerAffectingAttacker && playerAffectingTarget))
    {
        Player const* player = playerAffectingAttacker ? playerAffectingAttacker : playerAffectingTarget;
        Unit const* creature = playerAffectingAttacker ? target : this;

        if (creature->IsContestedGuard() && player->HasPlayerFlag(PLAYER_FLAGS_CONTESTED_PVP))
            return true;

        if (FactionTemplateEntry const* factionTemplate = creature->GetFactionTemplateEntry())
        {
            if (!(player->GetReputationMgr().GetForcedRankIfAny(factionTemplate)))
                    if (FactionEntry const* factionEntry = sFactionStore.LookupEntry(factionTemplate->Faction))
                    if (FactionState const* repState = player->GetReputationMgr().GetState(factionEntry))
                        if (!repState->Flags.HasFlag(ReputationFlags::AtWar))
                            return false;

        }
    }

    Creature const* creatureAttacker = ToCreature();
    if (creatureAttacker && creatureAttacker->GetCreatureTemplate()->type_flags & CREATURE_TYPE_FLAG_TREAT_AS_RAID_UNIT)
        return false;

    // check duel - before sanctuary checks
    if (playerAffectingAttacker && playerAffectingTarget)
        if (playerAffectingAttacker->duel && playerAffectingAttacker->duel->opponent == playerAffectingTarget && playerAffectingAttacker->duel->startTime != 0)
            return true;

    // PvP case - can't attack when attacker or target are in sanctuary
    // however, 13850 client doesn't allow to attack when one of the unit's has sanctuary flag and is pvp
    if (target->HasUnitFlag(UNIT_FLAG_PVP_ATTACKABLE) && HasUnitFlag(UNIT_FLAG_PVP_ATTACKABLE) && (target->IsInSanctuary() || IsInSanctuary()))
        return false;

    // additional checks - only PvP case
    if (playerAffectingAttacker && playerAffectingTarget)
    {
        if (target->IsPvP())
            return true;

        if (IsFFAPvP() && target->IsFFAPvP())
            return true;

        return HasPvpFlag(UNIT_BYTE2_FLAG_UNK1)
            || target->HasPvpFlag(UNIT_BYTE2_FLAG_UNK1);
    }
    return true;
}

bool Unit::IsValidAssistTarget(Unit const* target) const
{
    return _IsValidAssistTarget(target, nullptr);
}

// function based on function Unit::CanAssist from 13850 client
bool Unit::_IsValidAssistTarget(Unit const* target, SpellInfo const* bySpell) const
{
    ASSERT(target);

    // can assist to self
    if (this == target)
        return true;

    // can't assist unattackable units or GMs
    if (target->HasUnitState(UNIT_STATE_UNATTACKABLE)
        || (target->GetTypeId() == TYPEID_PLAYER && target->ToPlayer()->IsGameMaster()))
        return false;

    // can't assist own vehicle or passenger
    if (m_vehicle)
        if (IsOnVehicle(target) || m_vehicle->GetBase()->IsOnVehicle(target))
            return false;

    // can't assist invisible
    if ((!bySpell || !bySpell->HasAttribute(SPELL_ATTR6_CAN_TARGET_INVISIBLE)) && !CanSeeOrDetect(target, bySpell && bySpell->IsAffectingArea()))
        return false;

    // can't assist dead
    if ((!bySpell || !bySpell->IsAllowingDeadTarget()) && !target->IsAlive())
       return false;

    // can't assist untargetable
    if ((!bySpell || !bySpell->HasAttribute(SPELL_ATTR6_CAN_TARGET_UNTARGETABLE))
        && target->HasUnitFlag(UNIT_FLAG_NOT_SELECTABLE))
        return false;

    if (!bySpell || !bySpell->HasAttribute(SPELL_ATTR6_ASSIST_IGNORE_IMMUNE_FLAG))
    {
        if (HasUnitFlag(UNIT_FLAG_PVP_ATTACKABLE))
        {
            if (target->IsImmuneToPC())
                return false;
        }
        else
        {
            if (target->IsImmuneToNPC())
                return false;
        }
    }

    // can't assist non-friendly targets
    if (GetReactionTo(target) < REP_NEUTRAL
        && target->GetReactionTo(this) < REP_NEUTRAL
        && (!ToCreature() || !(ToCreature()->GetCreatureTemplate()->type_flags & CREATURE_TYPE_FLAG_TREAT_AS_RAID_UNIT)))
        return false;

    // Controlled player case, we can assist creatures (reaction already checked above, our faction == charmer faction)
    if (GetTypeId() == TYPEID_PLAYER && IsCharmed() && GetCharmerGUID().IsCreature())
        return true;
    // PvP case
    else if (target->HasUnitFlag(UNIT_FLAG_PVP_ATTACKABLE))
    {
        Player const* targetPlayerOwner = target->GetAffectingPlayer();
        if (HasUnitFlag(UNIT_FLAG_PVP_ATTACKABLE))
        {
            Player const* selfPlayerOwner = GetAffectingPlayer();
            if (selfPlayerOwner && targetPlayerOwner)
            {
                // can't assist player which is dueling someone
                if (selfPlayerOwner != targetPlayerOwner
                    && targetPlayerOwner->duel)
                    return false;
            }
            // can't assist player in ffa_pvp zone from outside
            if (target->HasPvpFlag(UNIT_BYTE2_FLAG_FFA_PVP)
                && !HasPvpFlag(UNIT_BYTE2_FLAG_FFA_PVP))
                return false;
            // can't assist player out of sanctuary from sanctuary if has pvp enabled
            if (target->HasPvpFlag(UNIT_BYTE2_FLAG_PVP))
                if (IsInSanctuary() && !target->IsInSanctuary())
                    return false;
        }
    }
    // PvC case - player can assist creature only if has specific type flags
    // !target->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP_ATTACKABLE) &&
    else if (HasUnitFlag(UNIT_FLAG_PVP_ATTACKABLE)
        && (!bySpell || !bySpell->HasAttribute(SPELL_ATTR6_ASSIST_IGNORE_IMMUNE_FLAG))
        && !target->HasPvpFlag(UNIT_BYTE2_FLAG_PVP))
    {
        if (Creature const* creatureTarget = target->ToCreature())
            return creatureTarget->GetCreatureTemplate()->type_flags & CREATURE_TYPE_FLAG_TREAT_AS_RAID_UNIT || creatureTarget->GetCreatureTemplate()->type_flags & CREATURE_TYPE_FLAG_CAN_ASSIST;
    }
    return true;
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
            TC_LOG_ERROR("entities.unit", "Unit::UpdateSpeed: Unsupported move type (%d)", mtype);
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
            {
                Unit* pOwner = GetCharmerOrOwner();
                if ((IsPet() || IsGuardian()) && !IsInCombat() && pOwner) // Must check for owner or crash on "Tame Beast"
                {
                    // For every yard over 5, increase speed by 0.01
                    //  to help prevent pet from lagging behind and despawning
                    float dist = GetDistance(pOwner);
                    float base_rate = 1.00f; // base speed is 100% of owner speed

                    if (dist < 5)
                        dist = 5;

                    float mult = base_rate + ((dist - 5) * 0.01f);

                    speed *= pOwner->GetSpeedRate(mtype) * mult; // pets derive speed from owner when not in combat
                }
                else
                    speed *= ToCreature()->GetCreatureTemplate()->speed_run;    // at this point, MOVE_WALK is never reached
            }

            // Normalize speed by 191 aura SPELL_AURA_USE_NORMAL_MOVEMENT_SPEED if need
            /// @todo possible affect only on MOVE_RUN
            if (int32 normalization = GetMaxPositiveAuraModifier(SPELL_AURA_USE_NORMAL_MOVEMENT_SPEED))
            {
                if (Creature* creature = ToCreature())
                {
                    uint32 immuneMask = creature->GetCreatureTemplate()->MechanicImmuneMask;
                    if (immuneMask & (1 << (MECHANIC_SNARE - 1)) || immuneMask & (1 << (MECHANIC_DAZE - 1)))
                        break;
                }

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

    // for creature case, we check explicit if mob searched for assistance
    if (GetTypeId() == TYPEID_UNIT)
    {
        if (ToCreature()->HasSearchedAssistance())
            speed *= 0.66f;                                 // best guessed value, so this will be 33% reduction. Based off initial speed, mob can then "run", "walk fast" or "walk".
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

    if (Player* playerMover = GetPlayerBeingMoved()) // unit controlled by a player.
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

void Unit::setDeathState(DeathState s)
{
    // Death state needs to be updated before RemoveAllAurasOnDeath() is called, to prevent entering combat
    m_deathState = s;

    if (s != ALIVE && s != JUST_RESPAWNED)
    {
        CombatStop();
        GetThreatManager().ClearAllThreat();

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
        if (IsInWorld())
        {
            // Only clear MotionMaster for entities that exists in world
            // Avoids crashes in the following conditions :
            //  * Using 'call pet' on dead pets
            //  * Using 'call stabled pet'
            //  * Logging in with dead pets
            GetMotionMaster()->Clear(false);
            GetMotionMaster()->MoveIdle();
        }
        StopMoving();
        DisableSpline();
        // without this when removing IncreaseMaxHealth aura player may stuck with 1 hp
        // do not why since in IncreaseMaxHealth currenthealth is checked
        SetHealth(0);
        SetPower(GetPowerType(), 0);
        SetEmoteState(EMOTE_ONESHOT_NONE);

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
            && spell->m_spellInfo->HasAttribute(SPELL_ATTR0_CANT_USED_IN_COMBAT)
            && spell->m_spellInfo->InterruptFlags.HasFlag(SpellInterruptFlags::Combat))
            InterruptNonMeleeSpells(false);

    RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::EnteringCombat);
    Unit::ProcSkillsAndAuras(this, nullptr, PROC_FLAG_ENTER_COMBAT, PROC_FLAG_NONE, PROC_SPELL_TYPE_MASK_ALL, PROC_SPELL_PHASE_NONE, PROC_HIT_NONE, nullptr, nullptr, nullptr);
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
        AddUnitFlag(UNIT_FLAG_PET_IN_COMBAT);
    else
        RemoveUnitFlag(UNIT_FLAG_PET_IN_COMBAT);
}

//======================================================================

float Unit::ApplyEffectModifiers(SpellInfo const* spellProto, uint8 effect_index, float value) const
{
    if (Player* modOwner = GetSpellModOwner())
    {
        modOwner->ApplySpellMod(spellProto, SpellModOp::Points, value);
        switch (effect_index)
        {
            case EFFECT_0:
                modOwner->ApplySpellMod(spellProto, SpellModOp::PointsIndex0, value);
                break;
            case EFFECT_1:
                modOwner->ApplySpellMod(spellProto, SpellModOp::PointsIndex1, value);
                break;
            case EFFECT_2:
                modOwner->ApplySpellMod(spellProto, SpellModOp::PointsIndex2, value);
                break;
            case EFFECT_3:
                modOwner->ApplySpellMod(spellProto, SpellModOp::PointsIndex3, value);
                break;
            case EFFECT_4:
                modOwner->ApplySpellMod(spellProto, SpellModOp::PointsIndex4, value);
                break;
        }
    }
    return value;
}

// function uses real base points (typically value - 1)
int32 Unit::CalculateSpellDamage(Unit const* target, SpellInfo const* spellProto, uint8 effect_index, int32 const* basePoints /*= nullptr*/, float* variance /*= nullptr*/, uint32 castItemId /*= 0*/, int32 itemLevel /*= -1*/) const
{
    SpellEffectInfo const* effect = spellProto->GetEffect(effect_index);
    if (variance)
        *variance = 0.0f;

    return effect ? effect->CalcValue(this, basePoints, target, variance, castItemId, itemLevel) : 0;
}

int32 Unit::CalcSpellDuration(SpellInfo const* spellProto)
{
    uint32 comboPoints = m_playerMovingMe ? m_playerMovingMe->GetComboPoints() : 0;

    int32 minduration = spellProto->GetDuration();
    int32 maxduration = spellProto->GetMaxDuration();

    int32 duration;

    if (comboPoints && minduration != -1 && minduration != maxduration)
        duration = minduration + int32((maxduration - minduration) * comboPoints / 5);
    else
        duration = minduration;

    return duration;
}

int32 Unit::ModSpellDuration(SpellInfo const* spellProto, Unit const* target, int32 duration, bool positive, uint32 effectMask)
{
    // don't mod permanent auras duration
    if (duration < 0)
        return duration;

    // some auras are not affected by duration modifiers
    if (spellProto->HasAttribute(SPELL_ATTR7_IGNORE_DURATION_MODS))
        return duration;

    // cut duration only of negative effects
    if (!positive)
    {
        int32 mechanic = spellProto->GetSpellMechanicMaskByEffectMask(effectMask);

        int32 durationMod;
        int32 durationMod_always = 0;
        int32 durationMod_not_stack = 0;

        for (uint8 i = 1; i <= MECHANIC_ENRAGED; ++i)
        {
            if (!(mechanic & 1<<i))
                continue;
            // Find total mod value (negative bonus)
            int32 new_durationMod_always = target->GetTotalAuraModifierByMiscValue(SPELL_AURA_MECHANIC_DURATION_MOD, i);
            // Find max mod (negative bonus)
            int32 new_durationMod_not_stack = target->GetMaxNegativeAuraModifierByMiscValue(SPELL_AURA_MECHANIC_DURATION_MOD_NOT_STACK, i);
            // Check if mods applied before were weaker
            if (new_durationMod_always < durationMod_always)
                durationMod_always = new_durationMod_always;
            if (new_durationMod_not_stack < durationMod_not_stack)
                durationMod_not_stack = new_durationMod_not_stack;
        }

        // Select strongest negative mod
        if (durationMod_always > durationMod_not_stack)
            durationMod = durationMod_not_stack;
        else
            durationMod = durationMod_always;

        if (durationMod != 0)
            AddPct(duration, durationMod);

        // there are only negative mods currently
        durationMod_always = target->GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_AURA_DURATION_BY_DISPEL, spellProto->Dispel);
        durationMod_not_stack = target->GetMaxNegativeAuraModifierByMiscValue(SPELL_AURA_MOD_AURA_DURATION_BY_DISPEL_NOT_STACK, spellProto->Dispel);

        durationMod = 0;
        if (durationMod_always > durationMod_not_stack)
            durationMod += durationMod_not_stack;
        else
            durationMod += durationMod_always;

        if (durationMod != 0)
            AddPct(duration, durationMod);
    }
    else
    {
        // else positive mods here, there are no currently
        // when there will be, change GetTotalAuraModifierByMiscValue to GetTotalPositiveAuraModifierByMiscValue

        // Mixology - duration boost
        if (target->GetTypeId() == TYPEID_PLAYER)
        {
            if (spellProto->SpellFamilyName == SPELLFAMILY_POTION && (
                sSpellMgr->IsSpellMemberOfSpellGroup(spellProto->Id, SPELL_GROUP_ELIXIR_BATTLE) ||
                sSpellMgr->IsSpellMemberOfSpellGroup(spellProto->Id, SPELL_GROUP_ELIXIR_GUARDIAN)))
            {
                SpellEffectInfo const* effect = spellProto->GetEffect(EFFECT_0);
                if (target->HasAura(53042) && effect && target->HasSpell(effect->TriggerSpell))
                    duration *= 2;
            }
        }
    }

    return std::max(duration, 0);
}

void Unit::ModSpellCastTime(SpellInfo const* spellInfo, int32 & castTime, Spell* spell)
{
    if (!spellInfo || castTime < 0)
        return;

    // called from caster
    if (Player* modOwner = GetSpellModOwner())
        modOwner->ApplySpellMod(spellInfo, SpellModOp::ChangeCastTime, castTime, spell);

    if (!(spellInfo->HasAttribute(SPELL_ATTR0_ABILITY) || spellInfo->HasAttribute(SPELL_ATTR0_TRADESPELL) || spellInfo->HasAttribute(SPELL_ATTR3_NO_DONE_BONUS)) &&
        ((GetTypeId() == TYPEID_PLAYER && spellInfo->SpellFamilyName) || GetTypeId() == TYPEID_UNIT))
        castTime = CanInstantCast() ? 0 : int32(float(castTime) * m_unitData->ModCastingSpeed);
    else if (spellInfo->HasAttribute(SPELL_ATTR0_REQ_AMMO) && !spellInfo->HasAttribute(SPELL_ATTR2_AUTOREPEAT_FLAG))
        castTime = int32(float(castTime) * m_modAttackSpeedPct[RANGED_ATTACK]);
    else if (IsPartOfSkillLine(SKILL_COOKING, spellInfo->Id) && HasAura(67556)) // cooking with Chef Hat.
        castTime = 500;
}

void Unit::ModSpellDurationTime(SpellInfo const* spellInfo, int32 & duration, Spell* spell)
{
    if (!spellInfo || duration < 0)
        return;

    if (spellInfo->IsChanneled() && !spellInfo->HasAttribute(SPELL_ATTR5_HASTE_AFFECT_DURATION))
        return;

    // called from caster
    if (Player* modOwner = GetSpellModOwner())
        modOwner->ApplySpellMod(spellInfo, SpellModOp::ChangeCastTime, duration, spell);

    if (!(spellInfo->HasAttribute(SPELL_ATTR0_ABILITY) || spellInfo->HasAttribute(SPELL_ATTR0_TRADESPELL) || spellInfo->HasAttribute(SPELL_ATTR3_NO_DONE_BONUS)) &&
        ((GetTypeId() == TYPEID_PLAYER && spellInfo->SpellFamilyName) || GetTypeId() == TYPEID_UNIT))
        duration = int32(float(duration) * m_unitData->ModCastingSpeed);
    else if (spellInfo->HasAttribute(SPELL_ATTR0_REQ_AMMO) && !spellInfo->HasAttribute(SPELL_ATTR2_AUTOREPEAT_FLAG))
        duration = int32(float(duration) * m_modAttackSpeedPct[RANGED_ATTACK]);
}

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

bool Unit::ApplyDiminishingToDuration(SpellInfo const* auraSpellInfo, int32& duration, Unit* caster, DiminishingLevels previousLevel) const
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
        Unit const* source = casterOwner ? casterOwner : caster;

        if (target->IsAffectedByDiminishingReturns() && source->GetTypeId() == TYPEID_PLAYER)
            duration = limitDuration;
    }

    float mod = 1.0f;
    switch (group)
    {
        case DIMINISHING_TAUNT:
        {
            if (GetTypeId() == TYPEID_UNIT && (ToCreature()->GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_TAUNT_DIMINISH))
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

float Unit::GetSpellMaxRangeForTarget(Unit const* target, SpellInfo const* spellInfo) const
{
    if (!spellInfo->RangeEntry)
        return 0;
    if (spellInfo->RangeEntry->RangeMax[0] == spellInfo->RangeEntry->RangeMax[1])
        return spellInfo->GetMaxRange();
    if (!target)
        return spellInfo->GetMaxRange(true);
    return spellInfo->GetMaxRange(!IsHostileTo(target));
}

float Unit::GetSpellMinRangeForTarget(Unit const* target, SpellInfo const* spellInfo) const
{
    if (!spellInfo->RangeEntry)
        return 0;
    if (spellInfo->RangeEntry->RangeMin[0] == spellInfo->RangeEntry->RangeMin[1])
        return spellInfo->GetMinRange();
    if (!target)
        return spellInfo->GetMinRange(true);
    return spellInfo->GetMinRange(!IsHostileTo(target));
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
            return CREATURE_TYPE_HUMANOID;
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
    return IsDisallowedMountForm(getTransForm(), GetShapeshiftForm(), GetDisplayId());
}

bool Unit::IsDisallowedMountForm(uint32 spellId, ShapeshiftForm form, uint32 displayId) const
{
    if (SpellInfo const* transformSpellInfo = sSpellMgr->GetSpellInfo(spellId, GetMap()->GetDifficultyID()))
        if (transformSpellInfo->HasAttribute(SPELL_ATTR0_CASTABLE_WHILE_MOUNTED))
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

    if (model && !(model->Flags & 0x80))
        if (race && !(race->Flags & 0x4))
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
        case UNIT_MOD_PAIN:                UpdateMaxPower(Powers(unitMod - UNIT_MOD_POWER_START));     break;

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
            ASSERT(false, "Not implemented UnitMod %u", unitMod);
            break;
    }
}

void Unit::UpdateDamageDoneMods(WeaponAttackType attackType)
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
        factor *= GetTotalAuraMultiplier(SPELL_AURA_MOD_OFFHAND_DAMAGE_PCT, std::bind(&Unit::CheckAttackFitToAuraRequirement, this, attackType, std::placeholders::_1));

    SetStatPctModifier(unitMod, TOTAL_PCT, factor);
}

void Unit::UpdateAllDamagePctDoneMods()
{
    for (uint8 i = BASE_ATTACK; i < MAX_ATTACK; ++i)
        UpdateDamagePctDoneMods(WeaponAttackType(i));
}

float Unit::GetTotalStatValue(Stats stat) const
{
    UnitMods unitMod = UnitMods(UNIT_MOD_STAT_START + stat);

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

void Unit::SetLevel(uint8 lvl)
{
    SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::Level), lvl);

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
    if (getDeathState() == JUST_DIED)
        val = 0;
    else if (GetTypeId() == TYPEID_PLAYER && getDeathState() == DEAD)
        val = 1;
    else
    {
        uint64 maxHealth = GetMaxHealth();
        if (maxHealth < val)
            val = maxHealth;
    }

    SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::Health), val);

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
    AuraEffectList effects       = GetAuraEffectsByType(SPELL_AURA_TRIGGER_SPELL_ON_POWER_PCT);
    AuraEffectList effectsAmount = GetAuraEffectsByType(SPELL_AURA_TRIGGER_SPELL_ON_POWER_AMOUNT);
    effects.splice(effects.end(), effectsAmount);

    for (AuraEffect const* effect : effects)
    {
        if (effect->GetMiscValue() == power)
        {
            uint32 effectAmount = effect->GetAmount();
            uint32 triggerSpell = effect->GetSpellEffectInfo()->TriggerSpell;

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

            CastSpellExtraArgs args;
            args.TriggerFlags = TRIGGERED_FULL_MASK;
            args.TriggeringAura = effect;
            CastSpell(this, triggerSpell, args);
        }
    }
}

int32 Unit::GetCreatePowers(Powers power) const
{
    if (power == POWER_MANA)
        return GetCreateMana();

    if (PowerTypeEntry const* powerType = sDB2Manager.GetPowerTypeEntry(power))
        return powerType->MaxBasePower;

    return 0;
}

void Unit::AddToWorld()
{
    WorldObject::AddToWorld();

    RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::EnterWorld);
}

void Unit::RemoveFromWorld()
{
    // cleanup
    ASSERT(GetGUID());

    if (IsInWorld())
    {
        m_duringRemoveFromWorld = true;
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

        if (!GetCharmerGUID().IsEmpty())
        {
            TC_LOG_FATAL("entities.unit", "Unit %u has charmer guid when removed from world", GetEntry());
            ABORT();
        }

        if (Unit* owner = GetOwner())
        {
            if (owner->m_Controlled.find(this) != owner->m_Controlled.end())
            {
                TC_LOG_FATAL("entities.unit", "Unit %u is in controlled list of %u when removed from world", GetEntry(), owner->GetEntry());
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

    if (IsInWorld())
        RemoveFromWorld();

    ASSERT(GetGUID());

    // A unit may be in removelist and not in world, but it is still in grid
    // and may have some references during delete
    RemoveAllAuras();
    RemoveAllGameObjects();

    if (finalCleanup)
        m_cleanupDone = true;

    m_Events.KillAllEvents(false);                      // non-delatable (currently cast spells) will not deleted now but it will deleted at call in Map::RemoveAllObjectsInRemoveList
    CombatStop();
}

void Unit::CleanupsBeforeDelete(bool finalCleanup)
{
    CleanupBeforeRemoveFromMap(finalCleanup);

    WorldObject::CleanupsBeforeDelete(finalCleanup);
}

void Unit::UpdateCharmAI()
{
    switch (GetTypeId())
    {
        case TYPEID_UNIT:
            if (i_disabledAI) // disabled AI must be primary AI
            {
                if (!IsCharmed())
                {
                    delete i_AI;
                    i_AI = i_disabledAI;
                    i_disabledAI = nullptr;

                    if (GetTypeId() == TYPEID_UNIT)
                        ToCreature()->AI()->OnCharmed(false);
                }
            }
            else
            {
                if (IsCharmed())
                {
                    i_disabledAI = i_AI;
                    if (isPossessed() || IsVehicle())
                        i_AI = new PossessedAI(ToCreature());
                    else
                        i_AI = new PetAI(ToCreature());
                }
            }
            break;
        case TYPEID_PLAYER:
        {
            if (IsCharmed()) // if we are currently being charmed, then we should apply charm AI
            {
                i_disabledAI = i_AI;

                UnitAI* newAI = nullptr;
                // first, we check if the creature's own AI specifies an override playerai for its owned players
                if (Unit* charmer = GetCharmer())
                {
                    if (Creature* creatureCharmer = charmer->ToCreature())
                    {
                        if (PlayerAI* charmAI = creatureCharmer->IsAIEnabled ? creatureCharmer->AI()->GetAIForCharmedPlayer(ToPlayer()) : nullptr)
                            newAI = charmAI;
                    }
                    else
                    {
                        TC_LOG_ERROR("misc", "Attempt to assign charm AI to player %s who is charmed by non-creature %s.", GetGUID().ToString().c_str(), GetCharmerGUID().ToString().c_str());
                    }
                }
                if (!newAI) // otherwise, we default to the generic one
                    newAI = new SimpleCharmedPlayerAI(ToPlayer());
                i_AI = newAI;
                newAI->OnCharmed(true);
            }
            else
            {
                if (i_AI)
                {
                    // we allow the charmed PlayerAI to clean up
                    i_AI->OnCharmed(false);
                    // then delete it
                    delete i_AI;
                }
                else
                {
                    TC_LOG_ERROR("misc", "Attempt to remove charm AI from player %s who doesn't currently have charm AI.", GetGUID().ToString().c_str());
                }
                // and restore our previous PlayerAI (if we had one)
                i_AI = i_disabledAI;
                i_disabledAI = nullptr;
                // IsAIEnabled gets handled in the caller
            }
            break;
        }
        default:
            TC_LOG_ERROR("misc", "Attempt to update charm AI for unit %s, which is neither player nor creature.", GetGUID().ToString().c_str());
    }
}

CharmInfo* Unit::InitCharmInfo()
{
    if (!m_charmInfo)
        m_charmInfo = new CharmInfo(this);

    return m_charmInfo;
}

void Unit::DeleteCharmInfo()
{
    if (!m_charmInfo)
        return;

    m_charmInfo->RestoreState();
    delete m_charmInfo;
    m_charmInfo = nullptr;
}

CharmInfo::CharmInfo(Unit* unit)
: _unit(unit), _CommandState(COMMAND_FOLLOW), _petnumber(0), _oldReactState(REACT_PASSIVE),
  _isCommandAttack(false), _isCommandFollow(false), _isAtStay(false), _isFollowing(false), _isReturning(false),
  _stayX(0.0f), _stayY(0.0f), _stayZ(0.0f)
{
    for (uint8 i = 0; i < MAX_SPELL_CHARM; ++i)
        _charmspells[i].SetActionAndType(0, ACT_DISABLED);

    if (_unit->GetTypeId() == TYPEID_UNIT)
    {
        _oldReactState = _unit->ToCreature()->GetReactState();
        _unit->ToCreature()->SetReactState(REACT_PASSIVE);
    }
}

CharmInfo::~CharmInfo() { }

void CharmInfo::RestoreState()
{
    if (Creature* creature = _unit->ToCreature())
        creature->SetReactState(_oldReactState);
}

void CharmInfo::InitPetActionBar()
{
    // the first 3 SpellOrActions are attack, follow and stay
    for (uint32 i = 0; i < ACTION_BAR_INDEX_PET_SPELL_START - ACTION_BAR_INDEX_START; ++i)
        SetActionBar(ACTION_BAR_INDEX_START + i, COMMAND_ATTACK - i, ACT_COMMAND);

    // middle 4 SpellOrActions are spells/special attacks/abilities
    for (uint32 i = 0; i < ACTION_BAR_INDEX_PET_SPELL_END-ACTION_BAR_INDEX_PET_SPELL_START; ++i)
        SetActionBar(ACTION_BAR_INDEX_PET_SPELL_START + i, 0, ACT_PASSIVE);

    // last 3 SpellOrActions are reactions
    for (uint32 i = 0; i < ACTION_BAR_INDEX_END - ACTION_BAR_INDEX_PET_SPELL_END; ++i)
        SetActionBar(ACTION_BAR_INDEX_PET_SPELL_END + i, COMMAND_ATTACK - i, ACT_REACTION);
}

void CharmInfo::InitEmptyActionBar(bool withAttack)
{
    if (withAttack)
        SetActionBar(ACTION_BAR_INDEX_START, COMMAND_ATTACK, ACT_COMMAND);
    else
        SetActionBar(ACTION_BAR_INDEX_START, 0, ACT_PASSIVE);
    for (uint32 x = ACTION_BAR_INDEX_START+1; x < ACTION_BAR_INDEX_END; ++x)
        SetActionBar(x, 0, ACT_PASSIVE);
}

void CharmInfo::InitPossessCreateSpells()
{
    if (_unit->GetTypeId() == TYPEID_UNIT)
    {
        // Adding switch until better way is found. Malcrom
        // Adding entrys to this switch will prevent COMMAND_ATTACK being added to pet bar.
        switch (_unit->GetEntry())
        {
            case 23575: // Mindless Abomination
            case 24783: // Trained Rock Falcon
            case 27664: // Crashin' Thrashin' Racer
            case 40281: // Crashin' Thrashin' Racer
            case 28511: // Eye of Acherus
                break;
            default:
                InitEmptyActionBar();
                break;
        }

        for (uint8 i = 0; i < MAX_CREATURE_SPELLS; ++i)
        {
            uint32 spellId = _unit->ToCreature()->m_spells[i];
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId, _unit->GetMap()->GetDifficultyID());
            if (spellInfo)
            {
                if (spellInfo->IsPassive())
                    _unit->CastSpell(_unit, spellInfo->Id, true);
                else
                    AddSpellToActionBar(spellInfo, ACT_PASSIVE, i % MAX_UNIT_ACTION_BAR_INDEX);
            }
        }
    }
    else
        InitEmptyActionBar();
}

void CharmInfo::InitCharmCreateSpells()
{
    if (_unit->GetTypeId() == TYPEID_PLAYER)                // charmed players don't have spells
    {
        InitEmptyActionBar();
        return;
    }

    InitPetActionBar();

    for (uint32 x = 0; x < MAX_SPELL_CHARM; ++x)
    {
        uint32 spellId = _unit->ToCreature()->m_spells[x];
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId, _unit->GetMap()->GetDifficultyID());

        if (!spellInfo)
        {
            _charmspells[x].SetActionAndType(spellId, ACT_DISABLED);
            continue;
        }

        if (spellInfo->IsPassive())
        {
            _unit->CastSpell(_unit, spellInfo->Id, true);
            _charmspells[x].SetActionAndType(spellId, ACT_PASSIVE);
        }
        else
        {
            _charmspells[x].SetActionAndType(spellId, ACT_DISABLED);

            ActiveStates newstate = ACT_PASSIVE;

            if (!spellInfo->IsAutocastable())
                newstate = ACT_PASSIVE;
            else
            {
                if (spellInfo->NeedsExplicitUnitTarget())
                {
                    newstate = ACT_ENABLED;
                    ToggleCreatureAutocast(spellInfo, true);
                }
                else
                    newstate = ACT_DISABLED;
            }

            AddSpellToActionBar(spellInfo, newstate);
        }
    }
}

bool CharmInfo::AddSpellToActionBar(SpellInfo const* spellInfo, ActiveStates newstate, uint8 preferredSlot)
{
    uint32 spell_id = spellInfo->Id;
    uint32 first_id = spellInfo->GetFirstRankSpell()->Id;

    ASSERT(preferredSlot < MAX_UNIT_ACTION_BAR_INDEX);
    // new spell rank can be already listed
    for (uint8 i = 0; i < MAX_UNIT_ACTION_BAR_INDEX; ++i)
    {
        if (uint32 action = PetActionBar[i].GetAction())
        {
            if (PetActionBar[i].IsActionBarForSpell() && sSpellMgr->GetFirstSpellInChain(action) == first_id)
            {
                PetActionBar[i].SetAction(spell_id);
                return true;
            }
        }
    }

    // or use empty slot in other case
    for (uint8 i = 0; i < MAX_UNIT_ACTION_BAR_INDEX; ++i)
    {
        uint8 j = (preferredSlot + i) % MAX_UNIT_ACTION_BAR_INDEX;
        if (!PetActionBar[j].GetAction() && PetActionBar[j].IsActionBarForSpell())
        {
            SetActionBar(j, spell_id, newstate == ACT_DECIDE ? spellInfo->IsAutocastable() ? ACT_DISABLED : ACT_PASSIVE : newstate);
            return true;
        }
    }
    return false;
}

bool CharmInfo::RemoveSpellFromActionBar(uint32 spell_id)
{
    uint32 first_id = sSpellMgr->GetFirstSpellInChain(spell_id);

    for (uint8 i = 0; i < MAX_UNIT_ACTION_BAR_INDEX; ++i)
    {
        if (uint32 action = PetActionBar[i].GetAction())
        {
            if (PetActionBar[i].IsActionBarForSpell() && sSpellMgr->GetFirstSpellInChain(action) == first_id)
            {
                SetActionBar(i, 0, ACT_PASSIVE);
                return true;
            }
        }
    }

    return false;
}

void CharmInfo::ToggleCreatureAutocast(SpellInfo const* spellInfo, bool apply)
{
    if (spellInfo->IsPassive())
        return;

    for (uint32 x = 0; x < MAX_SPELL_CHARM; ++x)
        if (spellInfo->Id == _charmspells[x].GetAction())
            _charmspells[x].SetType(apply ? ACT_ENABLED : ACT_DISABLED);
}

void CharmInfo::SetPetNumber(uint32 petnumber, bool statwindow)
{
    _petnumber = petnumber;
    if (statwindow)
        _unit->SetPetNumberForClient(_petnumber);
    else
        _unit->SetPetNumberForClient(0);
}

void CharmInfo::LoadPetActionBar(const std::string& data)
{
    InitPetActionBar();

    Tokenizer tokens(data, ' ');

    if (tokens.size() != (ACTION_BAR_INDEX_END-ACTION_BAR_INDEX_START) * 2)
        return;                                             // non critical, will reset to default

    uint8 index = ACTION_BAR_INDEX_START;
    Tokenizer::const_iterator iter = tokens.begin();
    for (; index < ACTION_BAR_INDEX_END; ++iter, ++index)
    {
        // use unsigned cast to avoid sign negative format use at long-> ActiveStates (int) conversion
        ActiveStates type  = ActiveStates(atol(*iter));
        ++iter;
        uint32 action = atoul(*iter);

        PetActionBar[index].SetActionAndType(action, type);

        // check correctness
        if (PetActionBar[index].IsActionBarForSpell())
        {
            SpellInfo const* spelInfo = sSpellMgr->GetSpellInfo(PetActionBar[index].GetAction(), _unit->GetMap()->GetDifficultyID());
            if (!spelInfo)
                SetActionBar(index, 0, ACT_PASSIVE);
            else if (!spelInfo->IsAutocastable())
                SetActionBar(index, PetActionBar[index].GetAction(), ACT_PASSIVE);
        }
    }
}

void CharmInfo::BuildActionBar(WorldPacket* data)
{
    for (uint32 i = 0; i < MAX_UNIT_ACTION_BAR_INDEX; ++i)
        *data << uint32(PetActionBar[i].packedData);
}

void CharmInfo::SetSpellAutocast(SpellInfo const* spellInfo, bool state)
{
    for (uint8 i = 0; i < MAX_UNIT_ACTION_BAR_INDEX; ++i)
    {
        if (spellInfo->Id == PetActionBar[i].GetAction() && PetActionBar[i].IsActionBarForSpell())
        {
            PetActionBar[i].SetType(state ? ACT_ENABLED : ACT_DISABLED);
            break;
        }
    }
}

Unit* Unit::GetUnitBeingMoved() const
{
    if (Player const* player = ToPlayer())
        return player->m_unitMovedByMe;
    return nullptr;
}

Player* Unit::GetPlayerBeingMoved() const
{
    if (Unit* mover = GetUnitBeingMoved())
        return mover->ToPlayer();
    return nullptr;
}

bool Unit::isFrozen() const
{
    return HasAuraState(AURA_STATE_FROZEN);
}

uint32 createProcHitMask(SpellNonMeleeDamage* damageInfo, SpellMissInfo missCondition)
{
    uint32 hitMask = PROC_HIT_NONE;
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

void Unit::ProcSkillsAndReactives(bool isVictim, Unit* procTarget, uint32 typeMask, uint32 hitMask, WeaponAttackType /*attType*/)
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
                    if (getClass() != CLASS_ROGUE) // skip Rogue Riposte
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
    std::chrono::steady_clock::time_point now = GameTime::GetGameTimeSteadyPoint();

    // use provided list of auras which can proc
    if (procAuras)
    {
        for (AuraApplication* aurApp : *procAuras)
        {
            ASSERT(aurApp->GetTarget() == this);
            if (uint32 procEffectMask = aurApp->GetBase()->GetProcEffectMask(aurApp, eventInfo, now))
            {
                aurApp->GetBase()->PrepareProcToTrigger(aurApp, eventInfo, now);
                aurasTriggeringProc.emplace_back(procEffectMask, aurApp);
            }
        }
    }
    // or generate one on our own
    else
    {
        for (AuraApplicationMap::iterator itr = GetAppliedAuras().begin(); itr != GetAppliedAuras().end(); ++itr)
        {
            if (uint32 procEffectMask = itr->second->GetBase()->GetProcEffectMask(itr->second, eventInfo, now))
            {
                itr->second->GetBase()->PrepareProcToTrigger(itr->second, eventInfo, now);
                aurasTriggeringProc.emplace_back(procEffectMask, itr->second);
            }
        }
    }
}

void Unit::TriggerAurasProcOnEvent(AuraApplicationList* myProcAuras, AuraApplicationList* targetProcAuras, Unit* actionTarget, uint32 typeMaskActor, uint32 typeMaskActionTarget, uint32 spellTypeMask, uint32 spellPhaseMask, uint32 hitMask, Spell* spell, DamageInfo* damageInfo, HealInfo* healInfo)
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
                        modAuras.push_back(itr->second);
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
    if (disableProcs)
        SetCantProc(true);

    for (auto const& aurAppProc : aurasTriggeringProc)
    {
        AuraApplication* aurApp;
        uint32 procEffectMask;
        std::tie(procEffectMask, aurApp) = aurAppProc;

        if (aurApp->GetRemoveMode())
            continue;

        SpellInfo const* spellInfo = aurApp->GetBase()->GetSpellInfo();
        if (spellInfo->HasAttribute(SPELL_ATTR3_DISABLE_PROC))
            SetCantProc(true);

        aurApp->GetBase()->TriggerProcOnEvent(procEffectMask, aurApp, eventInfo);

        if (spellInfo->HasAttribute(SPELL_ATTR3_DISABLE_PROC))
            SetCantProc(false);
    }

    if (disableProcs)
        SetCantProc(false);
}

ObjectGuid Unit::GetCharmerOrOwnerGUID() const
{
    return !GetCharmerGUID().IsEmpty() ? GetCharmerGUID() : GetOwnerGUID();
}

ObjectGuid Unit::GetCharmerOrOwnerOrOwnGUID() const
{
    ObjectGuid guid = GetCharmerOrOwnerGUID();
    if (!guid.IsEmpty())
        return guid;

    return GetGUID();
}

Player* Unit::GetSpellModOwner() const
{
    if (Player* player = const_cast<Unit*>(this)->ToPlayer())
        return player;

    if (HasUnitTypeMask(UNIT_MASK_PET | UNIT_MASK_TOTEM | UNIT_MASK_GUARDIAN))
    {
        if (Unit* owner = GetOwner())
            return owner->ToPlayer();
    }
    return nullptr;
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

void Unit::StopMoving()
{
    ClearUnitState(UNIT_STATE_MOVING);

    // not need send any packets if not in world or not moving
    if (!IsInWorld() || movespline->Finalized())
        return;

    // Update position now since Stop does not start a new movement that can be updated later
    UpdateSplinePosition();
    Movement::MoveSplineInit init(this);
    init.Stop();
}

void Unit::PauseMovement(uint32 timer/* = 0*/, uint8 slot/* = 0*/, bool forced/* = true*/)
{
    if (slot >= MAX_MOTION_SLOT)
        return;

    if (MovementGenerator* movementGenerator = GetMotionMaster()->GetMotionSlot(MovementSlot(slot)))
        movementGenerator->Pause(timer);

    if (forced)
        StopMoving();
}

void Unit::ResumeMovement(uint32 timer/* = 0*/, uint8 slot/* = 0*/)
{
    if (slot >= MAX_MOTION_SLOT)
        return;

    if (MovementGenerator* movementGenerator = GetMotionMaster()->GetMotionSlot(MovementSlot(slot)))
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

void Unit::SetAnimTier(UnitBytes1_Flags animTier, bool notifyClient)
{
    SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::AnimTier), animTier);

    if (notifyClient)
    {
        WorldPackets::Misc::SetAnimTier setAnimTier;
        setAnimTier.Unit = GetGUID();
        setAnimTier.Tier = animTier;
        SendMessageToSet(setAnimTier.Write(), true);
    }
}

bool Unit::IsPolymorphed() const
{
    uint32 transformId = getTransForm();
    if (!transformId)
        return false;

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(transformId, GetMap()->GetDifficultyID());
    if (!spellInfo)
        return false;

    return spellInfo->GetSpellSpecific() == SPELL_SPECIFIC_MAGE_POLYMORPH;
}

void Unit::SetDisplayId(uint32 modelId, float displayScale /*= 1.f*/)
{
    SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::DisplayID), modelId);
    SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::DisplayScale), displayScale);

    // Set Gender by modelId
    if (CreatureModelInfo const* minfo = sObjectMgr->GetCreatureModelInfo(modelId))
        SetGender(minfo->gender);
}

void Unit::RestoreDisplayId(bool ignorePositiveAurasPreventingMounting /*= false*/)
{
    AuraEffect* handledAura = nullptr;
    // try to receive model from transform auras
    AuraEffectList const& transforms = GetAuraEffectsByType(SPELL_AURA_TRANSFORM);
    if (!transforms.empty())
    {
        // iterate over already applied transform auras - from newest to oldest
        for (auto i = transforms.rbegin(); i != transforms.rend(); ++i)
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

uint32 Unit::GetCastingTimeForBonus(SpellInfo const* spellProto, DamageEffectType damagetype, uint32 CastingTime) const
{
    // Not apply this to creature cast spells with casttime == 0
    if (CastingTime == 0 && GetTypeId() == TYPEID_UNIT && !IsPet())
        return 3500;

    if (CastingTime > 7000) CastingTime = 7000;
    if (CastingTime < 1500) CastingTime = 1500;

    if (damagetype == DOT && !spellProto->IsChanneled())
        CastingTime = 3500;

    int32 overTime    = 0;
    uint8 effects     = 0;
    bool DirectDamage = false;
    bool AreaEffect   = false;

    for (SpellEffectInfo const* effect : spellProto->GetEffects())
    {
        if (!effect)
            continue;
        switch (effect->Effect)
        {
            case SPELL_EFFECT_SCHOOL_DAMAGE:
            case SPELL_EFFECT_POWER_DRAIN:
            case SPELL_EFFECT_HEALTH_LEECH:
            case SPELL_EFFECT_ENVIRONMENTAL_DAMAGE:
            case SPELL_EFFECT_POWER_BURN:
            case SPELL_EFFECT_HEAL:
                DirectDamage = true;
                break;
            case SPELL_EFFECT_APPLY_AURA:
                switch (effect->ApplyAuraName)
                {
                    case SPELL_AURA_PERIODIC_DAMAGE:
                    case SPELL_AURA_PERIODIC_HEAL:
                    case SPELL_AURA_PERIODIC_LEECH:
                        if (spellProto->GetDuration())
                            overTime = spellProto->GetDuration();
                        break;
                    default:
                        // -5% per additional effect
                        ++effects;
                        break;
                }
            default:
                break;
        }

        if (effect->IsTargetingArea())
            AreaEffect = true;
    }

    // Combined Spells with Both Over Time and Direct Damage
    if (overTime > 0 && CastingTime > 0 && DirectDamage)
    {
        // mainly for DoTs which are 3500 here otherwise
        uint32 OriginalCastTime = spellProto->CalcCastTime();
        if (OriginalCastTime > 7000) OriginalCastTime = 7000;
        if (OriginalCastTime < 1500) OriginalCastTime = 1500;
        // Portion to Over Time
        float PtOT = (overTime / 15000.0f) / ((overTime / 15000.0f) + (OriginalCastTime / 3500.0f));

        if (damagetype == DOT)
            CastingTime = uint32(CastingTime * PtOT);
        else if (PtOT < 1.0f)
            CastingTime  = uint32(CastingTime * (1 - PtOT));
        else
            CastingTime = 0;
    }

    // Area Effect Spells receive only half of bonus
    if (AreaEffect)
        CastingTime /= 2;

    // 50% for damage and healing spells for leech spells from damage bonus and 0% from healing
    for (SpellEffectInfo const* effect : spellProto->GetEffects())
    {
        if (!effect)
            continue;
        if (effect->Effect == SPELL_EFFECT_HEALTH_LEECH ||
            (effect->Effect == SPELL_EFFECT_APPLY_AURA && effect->ApplyAuraName == SPELL_AURA_PERIODIC_LEECH))
        {
            CastingTime /= 2;
            break;
        }
    }

    // -5% of total per any additional effect
    for (uint8 i = 0; i < effects; ++i)
        CastingTime *= 0.95f;

    return CastingTime;
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

float Unit::CalculateDefaultCoefficient(SpellInfo const* spellInfo, DamageEffectType damagetype) const
{
    // Damage over Time spells bonus calculation
    float DotFactor = 1.0f;
    if (damagetype == DOT)
    {
        int32 DotDuration = spellInfo->GetDuration();
        if (!spellInfo->IsChanneled() && DotDuration > 0)
            DotFactor = DotDuration / 15000.0f;

        if (uint32 DotTicks = spellInfo->GetMaxTicks())
            DotFactor /= DotTicks;
    }

    int32 CastingTime = spellInfo->IsChanneled() ? spellInfo->GetDuration() : spellInfo->CalcCastTime();
    // Distribute Damage over multiple effects, reduce by AoE
    CastingTime = GetCastingTimeForBonus(spellInfo, damagetype, CastingTime);

    // As wowwiki says: C = (Cast Time / 3.5)
    return (CastingTime / 3500.0f) * DotFactor;
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

    uint8 level = creatureTarget->GetLevelForTarget(this) + 5 < getLevel() ? (getLevel() - 5) : creatureTarget->GetLevelForTarget(this);

    InitTamedPet(pet, level, spell_id);

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

    if (!pet->CreateBaseAtCreatureInfo(creatureInfo, this) || !InitTamedPet(pet, getLevel(), spell_id))
    {
        delete pet;
        return nullptr;
    }

    return pet;
}

bool Unit::InitTamedPet(Pet* pet, uint8 level, uint32 spell_id)
{
    pet->SetCreatorGUID(GetGUID());
    pet->SetFaction(GetFaction());
    pet->SetCreatedBySpell(spell_id);

    if (GetTypeId() == TYPEID_PLAYER)
        pet->AddUnitFlag(UNIT_FLAG_PVP_ATTACKABLE);

    if (!pet->InitStatsForLevel(level))
    {
        TC_LOG_ERROR("entities.unit", "Pet::InitStatsForLevel() failed for creature (Entry: %u)!", pet->GetEntry());
        return false;
    }

    PhasingHandler::InheritPhaseShift(pet, this);

    pet->GetCharmInfo()->SetPetNumber(sObjectMgr->GeneratePetNumber(), true);
    // this enables pet details window (Shift+P)
    pet->InitPetCreateSpells();
    //pet->InitLevelupSpellsForLevel();
    pet->SetFullHealth();
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
        TC_LOG_ERROR("entities.unit", "Unit::PlayOneShotAnimKitId using invalid AnimKit ID: %u", animKitId);
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

    bool isRewardAllowed = true;
    if (creature)
    {
        isRewardAllowed = creature->IsDamageEnoughForLootingAndReward();
        if (!isRewardAllowed)
            creature->SetLootRecipient(nullptr);
    }

    if (isRewardAllowed && creature && creature->GetLootRecipient())
        player = creature->GetLootRecipient();

    // Exploit fix
    if (creature && creature->IsPet() && creature->GetOwnerGUID().IsPlayer())
        isRewardAllowed = false;

    // Reward player, his pets, and group/raid members
    // call kill spell proc event (before real die and combat stop to triggering auras removed at death/combat stop)
    if (isRewardAllowed && player && player != victim)
    {
        WorldPackets::Party::PartyKillLog partyKillLog;
        partyKillLog.Player = player->GetGUID();
        partyKillLog.Victim = victim->GetGUID();

        Player* looter = player;
        Group* group = player->GetGroup();
        bool hasLooterGuid = false;

        if (group)
        {
            group->BroadcastPacket(partyKillLog.Write(), group->GetMemberGroup(player->GetGUID()) != 0);

            if (creature)
            {
                group->UpdateLooterGuid(creature, true);
                if (!group->GetLooterGuid().IsEmpty())
                {
                    looter = ObjectAccessor::FindPlayer(group->GetLooterGuid());
                    if (looter)
                    {
                        hasLooterGuid = true;
                        creature->SetLootRecipient(looter);   // update creature loot recipient to the allowed looter.
                    }
                }
            }
        }
        else
        {
            player->SendDirectMessage(partyKillLog.Write());

            if (creature)
            {
                WorldPackets::Loot::LootList lootList;
                lootList.Owner = creature->GetGUID();
                lootList.LootObj = creature->loot.GetGUID();

                player->SendMessageToSet(lootList.Write(), true);
            }
        }

        // Generate loot before updating looter
        if (creature)
        {
            Loot* loot = &creature->loot;
            loot->clear();
            if (uint32 lootid = creature->GetCreatureTemplate()->lootid)
                loot->FillLoot(lootid, LootTemplates_Creature, looter, false, false, creature->GetLootMode(), creature->GetMap()->GetDifficultyLootItemContext());

            if (creature->GetLootMode() > 0)
                loot->generateMoneyLoot(creature->GetCreatureTemplate()->mingold, creature->GetCreatureTemplate()->maxgold);

            if (group)
            {
                if (hasLooterGuid)
                    group->SendLooter(creature, looter);
                else
                    group->SendLooter(creature, nullptr);

                // Update round robin looter only if the creature had loot
                if (!loot->empty())
                    group->UpdateLooterGuid(creature);
            }
        }

        player->RewardPlayerAndGroupAtKill(victim, false);
    }

    // Do KILL and KILLED procs. KILL proc is called only for the unit who landed the killing blow (and its owner - for pets and totems) regardless of who tapped the victim
    if (attacker && (attacker->IsPet() || attacker->IsTotem()))
    {
        // proc only once for victim
        if (Unit* owner = attacker->GetOwner())
            Unit::ProcSkillsAndAuras(owner, victim, PROC_FLAG_KILL, PROC_FLAG_NONE, PROC_SPELL_TYPE_MASK_ALL, PROC_SPELL_PHASE_NONE, PROC_HIT_NONE, nullptr, nullptr, nullptr);
    }

    if (!victim->IsCritter())
        Unit::ProcSkillsAndAuras(attacker, victim, PROC_FLAG_KILL, PROC_FLAG_KILLED, PROC_SPELL_TYPE_MASK_ALL, PROC_SPELL_PHASE_NONE, PROC_HIT_NONE, nullptr, nullptr, nullptr);

    // Proc auras on death - must be before aura/combat remove
    Unit::ProcSkillsAndAuras(victim, victim, PROC_FLAG_NONE, PROC_FLAG_DEATH, PROC_SPELL_TYPE_MASK_ALL, PROC_SPELL_PHASE_NONE, PROC_HIT_NONE, nullptr, nullptr, nullptr);

    // update get killing blow achievements, must be done before setDeathState to be able to require auras on target
    // and before Spirit of Redemption as it also removes auras
    if (attacker)
        if (Player* killerPlayer = attacker->GetCharmerOrOwnerPlayerOrPlayerItself())
            killerPlayer->UpdateCriteria(CRITERIA_TYPE_GET_KILLING_BLOWS, 1, 0, 0, victim);

    if (!skipSettingDeathState)
    {
        TC_LOG_DEBUG("entities.unit", "SET JUST_DIED");
        victim->setDeathState(JUST_DIED);
    }

    // Inform pets (if any) when player kills target)
    // MUST come after victim->setDeathState(JUST_DIED); or pet next target
    // selection will get stuck on same target and break pet react state
    if (player)
    {
        Pet* pet = player->GetPet();
        if (pet && pet->IsAlive() && pet->isControlled())
            pet->AI()->KilledUnit(victim);
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
            TC_LOG_DEBUG("entities.unit", "We are dead, losing %u percent durability", loss);
            // Durability loss is calculated more accurately again for each item in Player::DurabilityLoss
            plrVictim->DurabilityLossAll(baseLoss, false);
            // durability lost message
            plrVictim->SendDurabilityLoss(plrVictim, loss);
        }
        // Call KilledUnit for creatures
        if (attacker && attacker->GetTypeId() == TYPEID_UNIT && attacker->IsAIEnabled)
            attacker->ToCreature()->AI()->KilledUnit(victim);

        // last damage from non duel opponent or opponent controlled creature
        if (plrVictim->duel)
        {
            plrVictim->duel->opponent->CombatStopWithPets(true);
            plrVictim->CombatStopWithPets(true);
            plrVictim->DuelComplete(DUEL_INTERRUPTED);
        }
    }
    else                                                // creature died
    {
        TC_LOG_DEBUG("entities.unit", "DealDamageNotPlayer");

        if (!creature->IsPet())
        {
            creature->GetThreatManager().ClearAllThreat();

            // must be after setDeathState which resets dynamic flags
            if (!creature->loot.isLooted())
                creature->AddDynamicFlag(UNIT_DYNFLAG_LOOTABLE);
            else
                creature->AllLootRemovedFromCorpse();
        }

        // Call KilledUnit for creatures, this needs to be called after the lootable flag is set
        if (attacker && attacker->GetTypeId() == TYPEID_UNIT && attacker->IsAIEnabled)
            attacker->ToCreature()->AI()->KilledUnit(victim);

        // Call creature just died function
        if (creature->IsAIEnabled)
            creature->AI()->JustDied(attacker);

        if (TempSummon* summon = creature->ToTempSummon())
            if (Unit* summoner = summon->GetSummoner())
                if (summoner->ToCreature() && summoner->IsAIEnabled)
                    summoner->ToCreature()->AI()->SummonedCreatureDies(creature, attacker);

        // Dungeon specific stuff, only applies to players killing creatures
        if (creature->GetInstanceId())
        {
            Map* instanceMap = creature->GetMap();

            /// @todo do instance binding anyway if the charmer/owner is offline
            if (instanceMap->IsDungeon() && ((attacker && attacker->GetCharmerOrOwnerPlayerOrPlayerItself()) || attacker == victim))
            {
                if (instanceMap->IsRaidOrHeroicDungeon())
                {
                    if (creature->GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_INSTANCE_BIND)
                        instanceMap->ToInstanceMap()->PermBindAllPlayers();
                }
                else
                {
                    // the reset time is set but not added to the scheduler
                    // until the players leave the instance
                    time_t resettime = GameTime::GetGameTime() + 2 * HOUR;
                    if (InstanceSave* save = sInstanceSaveMgr->GetInstanceSave(creature->GetInstanceId()))
                        if (save->GetResetTime() < resettime)
                            save->SetResetTime(resettime);
                }
            }
        }
    }

    // outdoor pvp things, do these after setting the death state, else the player activity notify won't work... doh...
    // handle player kill only if not suicide (spirit of redemption for example)
    if (player && attacker != victim)
    {
        if (OutdoorPvP* pvp = player->GetOutdoorPvP())
            pvp->HandleKill(player, victim);

        if (Battlefield* bf = sBattlefieldMgr->GetBattlefieldToZoneId(player->GetZoneId()))
            bf->HandleKill(player, victim);
    }

    //if (victim->GetTypeId() == TYPEID_PLAYER)
    //    if (OutdoorPvP* pvp = victim->ToPlayer()->GetOutdoorPvP())
    //        pvp->HandlePlayerActivityChangedpVictim->ToPlayer();

    // battleground things (do this at the end, so the death state flag will be properly set to handle in the bg->handlekill)
    if (player && player->InBattleground())
    {
        if (Battleground* bg = player->GetBattleground())
        {
            if (Player* playerVictim = victim->ToPlayer())
                bg->HandleKillPlayer(playerVictim, player);
            else
                bg->HandleKillUnit(victim->ToCreature(), player);
        }
    }

    // achievement stuff
    if (attacker && victim->GetTypeId() == TYPEID_PLAYER)
    {
        if (attacker->GetTypeId() == TYPEID_UNIT)
            victim->ToPlayer()->UpdateCriteria(CRITERIA_TYPE_KILLED_BY_CREATURE, attacker->GetEntry());
        else if (attacker->GetTypeId() == TYPEID_PLAYER && victim != attacker)
            victim->ToPlayer()->UpdateCriteria(CRITERIA_TYPE_KILLED_BY_PLAYER, 1, attacker->ToPlayer()->GetTeam());
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

float Unit::GetPositionZMinusOffset() const
{
    float offset = 0.0f;
    if (HasUnitMovementFlag(MOVEMENTFLAG_HOVER))
        offset = m_unitData->HoverHeight;

    return GetPositionZ() - offset;
}

void Unit::SetControlled(bool apply, UnitState state)
{
    if (apply)
    {
        if (HasUnitState(state))
            return;

        AddUnitState(state);
        switch (state)
        {
            case UNIT_STATE_STUNNED:
                SetStunned(true);
                CastStop();
                break;
            case UNIT_STATE_ROOT:
                if (!HasUnitState(UNIT_STATE_STUNNED))
                    SetRooted(true);
                break;
            case UNIT_STATE_CONFUSED:
                if (!HasUnitState(UNIT_STATE_STUNNED))
                {
                    ClearUnitState(UNIT_STATE_MELEE_ATTACKING);
                    SendMeleeAttackStop();
                    // SendAutoRepeatCancel ?
                    SetConfused(true);
                    CastStop();
                }
                break;
            case UNIT_STATE_FLEEING:
                if (!HasUnitState(UNIT_STATE_STUNNED | UNIT_STATE_CONFUSED))
                {
                    ClearUnitState(UNIT_STATE_MELEE_ATTACKING);
                    SendMeleeAttackStop();
                    // SendAutoRepeatCancel ?
                    SetFeared(true);
                    CastStop();
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
                if (HasAuraType(SPELL_AURA_MOD_STUN))
                    return;

                ClearUnitState(state);
                SetStunned(false);
                break;
            case UNIT_STATE_ROOT:
                if (HasAuraType(SPELL_AURA_MOD_ROOT) || HasAuraType(SPELL_AURA_MOD_ROOT_2) || GetVehicle())
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
    if (HasUnitState(UNIT_STATE_STUNNED) || HasAuraType(SPELL_AURA_MOD_STUN))
        SetStunned(true);

    if (HasUnitState(UNIT_STATE_ROOT) || HasAuraType(SPELL_AURA_MOD_ROOT) || HasAuraType(SPELL_AURA_MOD_ROOT_2))
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
        AddUnitFlag(UNIT_FLAG_STUNNED);

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

    if (Player* playerMover = GetPlayerBeingMoved()) // unit controlled by a player.
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
        Unit::AuraEffectList const& fearAuras = GetAuraEffectsByType(SPELL_AURA_MOD_FEAR);
        if (!fearAuras.empty())
            caster = ObjectAccessor::GetUnit(*this, fearAuras.front()->GetCasterGUID());
        if (!caster)
            caster = getAttackerForHelper();
        GetMotionMaster()->MoveFleeing(caster, fearAuras.empty() ? sWorld->getIntConfig(CONFIG_CREATURE_FAMILY_FLEE_DELAY) : 0);             // caster == NULL processed in MoveFleeing
    }
    else
    {
        if (IsAlive())
        {
            if (GetMotionMaster()->GetCurrentMovementGeneratorType() == FLEEING_MOTION_TYPE)
                GetMotionMaster()->MovementExpired();
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
            if (GetMotionMaster()->GetCurrentMovementGeneratorType() == CONFUSED_MOTION_TYPE)
                GetMotionMaster()->MovementExpired();
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
    ASSERT((type == CHARM_TYPE_VEHICLE) == IsVehicle());

    TC_LOG_DEBUG("entities.unit", "SetCharmedBy: charmer %u (%s), charmed %u (%s), type %u.", charmer->GetEntry(), charmer->GetGUID().ToString().c_str(), GetEntry(), GetGUID().ToString().c_str(), uint32(type));

    if (this == charmer)
    {
        TC_LOG_FATAL("entities.unit", "Unit::SetCharmedBy: Unit %u (%s) is trying to charm itself!", GetEntry(), GetGUID().ToString().c_str());
        return false;
    }

    //if (HasUnitState(UNIT_STATE_UNATTACKABLE))
    //    return false;

    if (GetTypeId() == TYPEID_PLAYER && ToPlayer()->GetTransport())
    {
        TC_LOG_FATAL("entities.unit", "Unit::SetCharmedBy: Player on transport is trying to charm %u (%s)", GetEntry(), GetGUID().ToString().c_str());
        return false;
    }

    // Already charmed
    if (!GetCharmerGUID().IsEmpty())
    {
        TC_LOG_FATAL("entities.unit", "Unit::SetCharmedBy: %u (%s) has already been charmed but %u (%s) is trying to charm it!", GetEntry(), GetGUID().ToString().c_str(), charmer->GetEntry(), charmer->GetGUID().ToString().c_str());
        return false;
    }

    CastStop();
    CombatStop(); /// @todo CombatStop(true) may cause crash (interrupt spells)

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
        TC_LOG_FATAL("entities.unit", "Unit::SetCharmedBy: %u (%s) is not in world but %u (%s) is trying to charm it!", GetEntry(), GetGUID().ToString().c_str(), charmer->GetEntry(), charmer->GetGUID().ToString().c_str());
        return false;
    }

    // charm is set by aura, and aura effect remove handler was called during apply handler execution
    // prevent undefined behaviour
    if (aurApp && aurApp->GetRemoveMode())
        return false;

    _oldFactionId = GetFaction();
    SetFaction(charmer->GetFaction());

    // Set charmed
    charmer->SetCharm(this, true);

    if (GetTypeId() == TYPEID_UNIT)
    {
        if (MovementGenerator* movementGenerator = GetMotionMaster()->GetMotionSlot(MOTION_SLOT_IDLE))
            movementGenerator->Pause(0);

        GetMotionMaster()->Clear(MOTION_SLOT_ACTIVE);

        StopMoving();

        ToCreature()->AI()->OnCharmed(true);
    }
    else if (Player* player = ToPlayer())
    {
        if (player->isAFK())
            player->ToggleAFK();

        if (charmer->GetTypeId() == TYPEID_UNIT) // we are charmed by a creature
        {
            // change AI to charmed AI on next Update tick
            NeedChangeAI = true;
            if (IsAIEnabled)
            {
                IsAIEnabled = false;
                player->AI()->OnCharmed(true);
            }
        }
        player->SetClientControl(this, false);
    }

    // charm is set by aura, and aura effect remove handler was called during apply handler execution
    // prevent undefined behaviour
    if (aurApp && aurApp->GetRemoveMode())
        return false;

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
                AddUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED);
                playerCharmer->SetClientControl(this, true);
                playerCharmer->VehicleSpellInitialize();
                break;
            case CHARM_TYPE_POSSESS:
                AddUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED);
                charmer->AddUnitFlag(UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                playerCharmer->SetClientControl(this, true);
                playerCharmer->PossessSpellInitialize();
                AddUnitState(UNIT_STATE_POSSESSED);
                break;
            case CHARM_TYPE_CHARM:
                if (GetTypeId() == TYPEID_UNIT && charmer->getClass() == CLASS_WARLOCK)
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
    return true;
}

void Unit::RemoveCharmedBy(Unit* charmer)
{
    if (!IsCharmed())
        return;

    if (!charmer)
        charmer = GetCharmer();
    if (charmer != GetCharmer()) // one aura overrides another?
    {
//        TC_LOG_FATAL("entities.unit", "Unit::RemoveCharmedBy: this: " UI64FMTD " true charmer: " UI64FMTD " false charmer: " UI64FMTD,
//            GetGUID(), GetCharmerGUID(), charmer->GetGUID());
//        ABORT();
        return;
    }

    CharmType type;
    if (HasUnitState(UNIT_STATE_POSSESSED))
        type = CHARM_TYPE_POSSESS;
    else if (charmer && charmer->IsOnVehicle(this))
        type = CHARM_TYPE_VEHICLE;
    else
        type = CHARM_TYPE_CHARM;

    CastStop();
    CombatStop(); /// @todo CombatStop(true) may cause crash (interrupt spells)

    if (_oldFactionId)
    {
        SetFaction(_oldFactionId);
        _oldFactionId = 0;
    }
    else
        RestoreFaction();

    ///@todo Handle SLOT_IDLE motion resume
    GetMotionMaster()->InitDefault();

    if (Creature* creature = ToCreature())
    {
        // Creature will restore its old AI on next update
        if (creature->AI())
            creature->AI()->OnCharmed(false);

        // Vehicle should not attack its passenger after he exists the seat
        if (type != CHARM_TYPE_VEHICLE)
            LastCharmerGUID = ASSERT_NOTNULL(charmer)->GetGUID();
    }

    // If charmer still exists
    if (!charmer)
        return;

    ASSERT(type != CHARM_TYPE_POSSESS || charmer->GetTypeId() == TYPEID_PLAYER);
    ASSERT(type != CHARM_TYPE_VEHICLE || (GetTypeId() == TYPEID_UNIT && IsVehicle()));

    charmer->SetCharm(this, false);

    Player* playerCharmer = charmer->ToPlayer();
    if (playerCharmer)
    {
        switch (type)
        {
            case CHARM_TYPE_VEHICLE:
                playerCharmer->SetClientControl(this, false);
                playerCharmer->SetClientControl(charmer, true);
                RemoveUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED);
                break;
            case CHARM_TYPE_POSSESS:
                ClearUnitState(UNIT_STATE_POSSESSED);
                playerCharmer->SetClientControl(this, false);
                playerCharmer->SetClientControl(charmer, true);
                charmer->RemoveUnitFlag(UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                RemoveUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED);
                break;
            case CHARM_TYPE_CHARM:
                if (GetTypeId() == TYPEID_UNIT && charmer->getClass() == CLASS_WARLOCK)
                {
                    CreatureTemplate const* cinfo = ToCreature()->GetCreatureTemplate();
                    if (cinfo && cinfo->type == CREATURE_TYPE_DEMON)
                    {
                        SetClass(uint8(cinfo->unit_class));
                        if (GetCharmInfo())
                            GetCharmInfo()->SetPetNumber(0, true);
                        else
                            TC_LOG_ERROR("entities.unit", "Aura::HandleModCharm: %s has a charm aura but no charm info!", GetGUID().ToString().c_str());
                    }
                }
                break;
            case CHARM_TYPE_CONVERT:
                break;
        }
    }

    if (Player* player = ToPlayer())
    {
        if (charmer->GetTypeId() == TYPEID_UNIT) // charmed by a creature, this means we had PlayerAI
        {
            NeedChangeAI = true;
            IsAIEnabled = false;
        }

        player->SetClientControl(this, true);
    }

    EngageWithTarget(charmer);

    // a guardian should always have charminfo
    if (playerCharmer && this != charmer->GetFirstControlled())
        playerCharmer->SendRemoveControlBar();
    else if (GetTypeId() == TYPEID_PLAYER || (GetTypeId() == TYPEID_UNIT && !IsGuardian()))
        DeleteCharmInfo();

    // reset confused movement for example
    ApplyControlStatesIfNeeded();
}

void Unit::RestoreFaction()
{
    if (GetTypeId() == TYPEID_PLAYER)
        ToPlayer()->setFactionForRace(getRace());
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

    m_vehicleKit = new Vehicle(this, vehInfo, creatureEntry);
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
    delete m_vehicleKit;

    m_vehicleKit = nullptr;

    m_updateFlag.Vehicle = false;
    m_unitTypeMask &= ~UNIT_MASK_VEHICLE;
    RemoveNpcFlag(NPCFlags(UNIT_NPC_FLAG_SPELLCLICK | UNIT_NPC_FLAG_PLAYER_VEHICLE));
}

bool Unit::IsOnVehicle(Unit const* vehicle) const
{
    return m_vehicle && m_vehicle == vehicle->GetVehicleKit();
}

Unit* Unit::GetVehicleBase() const
{
    return m_vehicle ? m_vehicle->GetBase() : nullptr;
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
        return GetTransport()->GetGUID();

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
    else if ((u2->GetTypeId() == TYPEID_PLAYER && u1->GetTypeId() == TYPEID_UNIT && u1->ToCreature()->GetCreatureTemplate()->type_flags & CREATURE_TYPE_FLAG_TREAT_AS_RAID_UNIT) ||
        (u1->GetTypeId() == TYPEID_PLAYER && u2->GetTypeId() == TYPEID_UNIT && u2->ToCreature()->GetCreatureTemplate()->type_flags & CREATURE_TYPE_FLAG_TREAT_AS_RAID_UNIT))
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
    else if ((u2->GetTypeId() == TYPEID_PLAYER && u1->GetTypeId() == TYPEID_UNIT && u1->ToCreature()->GetCreatureTemplate()->type_flags & CREATURE_TYPE_FLAG_TREAT_AS_RAID_UNIT) ||
            (u1->GetTypeId() == TYPEID_PLAYER && u2->GetTypeId() == TYPEID_UNIT && u2->ToCreature()->GetCreatureTemplate()->type_flags & CREATURE_TYPE_FLAG_TREAT_AS_RAID_UNIT))
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
        AddPvpFlag(UNIT_BYTE2_FLAG_PVP);
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

    if (!target->IsAlive() && !spellInfo->IsPassive() && !spellInfo->HasAttribute(SPELL_ATTR2_CAN_TARGET_DEAD))
        return nullptr;

    return AddAura(spellInfo, MAX_EFFECT_MASK, target);
}

Aura* Unit::AddAura(SpellInfo const* spellInfo, uint32 effMask, Unit* target)
{
    if (!spellInfo)
        return nullptr;

    if (target->IsImmunedToSpell(spellInfo, this))
        return nullptr;

    for (uint32 i = 0; i < MAX_SPELL_EFFECTS; ++i)
    {
        if (!(effMask & (1 << i)))
            continue;
        if (target->IsImmunedToSpellEffect(spellInfo, i, this))
            effMask &= ~(1 << i);
    }

    ObjectGuid castId = ObjectGuid::Create<HighGuid::Cast>(SPELL_CAST_SOURCE_NORMAL, GetMapId(), spellInfo->Id, GetMap()->GenerateLowGuid<HighGuid::Cast>());
    if (Aura* aura = Aura::TryRefreshStackOrCreate(spellInfo, castId, effMask, target, this, GetMap()->GetDifficultyID()))
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

void Unit::SendCancelOrphanSpellVisual(uint32 id)
{
    WorldPackets::Spells::CancelOrphanSpellVisual cancelOrphanSpellVisual;
    cancelOrphanSpellVisual.SpellVisualID = id;
    SendMessageToSet(cancelOrphanSpellVisual.Write(), true);
}

void Unit::SendPlayOrphanSpellVisual(ObjectGuid const& target, uint32 spellVisualId, float travelSpeed, bool speedAsTime /*= false*/, bool withSourceOrientation /*= false*/)
{
    WorldPackets::Spells::PlayOrphanSpellVisual playOrphanSpellVisual;
    playOrphanSpellVisual.SourceLocation = GetPosition();
    if (withSourceOrientation)
        playOrphanSpellVisual.SourceRotation = Position(0.0f, 0.0f, GetOrientation());
    playOrphanSpellVisual.Target = target; // exclusive with TargetLocation
    playOrphanSpellVisual.SpellVisualID = spellVisualId;
    playOrphanSpellVisual.TravelSpeed = travelSpeed;
    playOrphanSpellVisual.SpeedAsTime = speedAsTime;
    playOrphanSpellVisual.LaunchDelay = 0.0f;
    SendMessageToSet(playOrphanSpellVisual.Write(), true);
}

void Unit::SendPlayOrphanSpellVisual(Position const& targetLocation, uint32 spellVisualId, float travelSpeed, bool speedAsTime /*= false*/, bool withSourceOrientation /*= false*/)
{
    WorldPackets::Spells::PlayOrphanSpellVisual playOrphanSpellVisual;
    playOrphanSpellVisual.SourceLocation = GetPosition();
    if (withSourceOrientation)
        playOrphanSpellVisual.SourceRotation = Position(0.0f, 0.0f, GetOrientation());
    playOrphanSpellVisual.TargetLocation = targetLocation; // exclusive with Target
    playOrphanSpellVisual.SpellVisualID = spellVisualId;
    playOrphanSpellVisual.TravelSpeed = travelSpeed;
    playOrphanSpellVisual.SpeedAsTime = speedAsTime;
    playOrphanSpellVisual.LaunchDelay = 0.0f;
    SendMessageToSet(playOrphanSpellVisual.Write(), true);
}

void Unit::SendCancelSpellVisual(uint32 id)
{
    WorldPackets::Spells::CancelSpellVisual cancelSpellVisual;
    cancelSpellVisual.Source = GetGUID();
    cancelSpellVisual.SpellVisualID = id;
    SendMessageToSet(cancelSpellVisual.Write(), true);
}

void Unit::SendPlaySpellVisual(ObjectGuid const& targetGuid, uint32 spellVisualId, uint16 missReason, uint16 reflectStatus, float travelSpeed, bool speedAsTime /*= false*/)
{
    WorldPackets::Spells::PlaySpellVisual playSpellVisual;
    playSpellVisual.Source = GetGUID();
    playSpellVisual.Target = targetGuid; // exclusive with TargetPosition
    playSpellVisual.SpellVisualID = spellVisualId;
    playSpellVisual.TravelSpeed = travelSpeed;
    playSpellVisual.MissReason = missReason;
    playSpellVisual.ReflectStatus = reflectStatus;
    playSpellVisual.SpeedAsTime = speedAsTime;
    SendMessageToSet(playSpellVisual.Write(), true);
}

void Unit::SendPlaySpellVisual(Position const& targetPosition, float launchDelay, uint32 spellVisualId, uint16 missReason, uint16 reflectStatus, float travelSpeed, bool speedAsTime /*= false*/)
{
    WorldPackets::Spells::PlaySpellVisual playSpellVisual;
    playSpellVisual.Source = GetGUID();
    playSpellVisual.TargetPosition = targetPosition; // exclusive with Target
    playSpellVisual.LaunchDelay = launchDelay;
    playSpellVisual.SpellVisualID = spellVisualId;
    playSpellVisual.TravelSpeed = travelSpeed;
    playSpellVisual.MissReason = missReason;
    playSpellVisual.ReflectStatus = reflectStatus;
    playSpellVisual.SpeedAsTime = speedAsTime;
    SendMessageToSet(playSpellVisual.Write(), true);
}

void Unit::SendCancelSpellVisualKit(uint32 id)
{
    WorldPackets::Spells::CancelSpellVisualKit cancelSpellVisualKit;
    cancelSpellVisualKit.Source = GetGUID();
    cancelSpellVisualKit.SpellVisualKitID = id;
    SendMessageToSet(cancelSpellVisualKit.Write(), true);
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

void Unit::CancelSpellMissiles(uint32 spellId, bool reverseMissile /*= false*/)
{
    bool hasMissile = false;
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

int32 Unit::CalculateAOEAvoidance(int32 damage, uint32 schoolMask, ObjectGuid const& casterGuid) const
{
    damage = int32(float(damage) * GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_AOE_DAMAGE_AVOIDANCE, schoolMask));
    if (casterGuid.IsAnyTypeCreature())
        damage = int32(float(damage) * GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_CREATURE_AOE_DAMAGE_AVOIDANCE, schoolMask));

    return damage;
}

// Melee based spells can be miss, parry or dodge on this step
// Crit or block - determined on damage calculation phase! (and can be both in some time)
float Unit::MeleeSpellMissChance(Unit const* victim, WeaponAttackType attType, SpellInfo const* spellInfo) const
{
    //calculate miss chance
    float missChance = victim->GetUnitMissChance();

    // melee attacks while dual wielding have +19% chance to miss
    if (!spellInfo && haveOffhandWeapon() && !IsInFeralForm())
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

    // Limit miss chance to 60%
    missChance = std::min(missChance, 60.f);

    // miss chance from SPELL_AURA_MOD_ATTACKER_xxx_HIT_CHANCE can exceed 60% miss cap (eg aura 50240)
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
        m_threatManager.UpdateOnlineStates(true, true);
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

void Unit::KnockbackFrom(float x, float y, float speedXY, float speedZ, Movement::SpellEffectExtraData const* spellEffectExtraData /*= nullptr*/)
{
    Player* player = ToPlayer();
    if (!player)
    {
        if (Unit* charmer = GetCharmer())
        {
            player = charmer->ToPlayer();
            if (player && player->m_unitMovedByMe != this)
                player = nullptr;
        }
    }

    if (!player)
        GetMotionMaster()->MoveKnockbackFrom(x, y, speedXY, speedZ, spellEffectExtraData);
    else
    {
        float vcos, vsin;
        GetSinCos(x, y, vsin, vcos);
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
    default:
        break;
    }

    if (Player const* thisPlayer = ToPlayer())
    {
        if (Aura* artifactAura = GetAura(ARTIFACTS_ALL_WEAPONS_GENERAL_WEAPON_EQUIPPED_PASSIVE))
            if (Item* artifact = ToPlayer()->GetItemByGuid(artifactAura->GetCastItemGUID()))
                if (ArtifactAppearanceEntry const* artifactAppearance = sArtifactAppearanceStore.LookupEntry(artifact->GetModifier(ITEM_MODIFIER_ARTIFACT_APPEARANCE_ID)))
                    if (ShapeshiftForm(artifactAppearance->OverrideShapeshiftFormID) == form)
                        return artifactAppearance->OverrideShapeshiftDisplayID;

        if (ShapeshiftFormModelData const* formModelData = sDB2Manager.GetShapeshiftFormModelData(getRace(), thisPlayer->GetNativeSex(), form))
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
                        if (!choiceReq || thisPlayer->GetSession()->MeetsChrCustomizationReq(choiceReq, Classes(getClass()), false,
                            MakeChrCustomizationChoiceRange(thisPlayer->m_playerData->Customizations)))
                            displayIds.push_back(displayInfo->DisplayID);
                    }
                }

                if (!displayIds.empty())
                    return Trinity::Containers::SelectRandomContainerElement(displayIds);
            }
            else
            {
                if (uint32 formChoice = thisPlayer->GetCustomizationChoice(formModelData->OptionID))
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
            }
            default:
                break;
        }
    }

    uint32 modelid = 0;
    SpellShapeshiftFormEntry const* formEntry = sSpellShapeshiftFormStore.LookupEntry(form);
    if (formEntry && formEntry->CreatureDisplayID[0])
    {
        // Take the alliance modelid as default
        if (GetTypeId() != TYPEID_PLAYER)
            return formEntry->CreatureDisplayID[0];
        else
        {
            if (Player::TeamForRace(getRace()) == ALLIANCE)
                modelid = formEntry->CreatureDisplayID[0];
            else
                modelid = formEntry->CreatureDisplayID[1];

            // If the player is horde but there are no values for the horde modelid - take the alliance modelid
            if (!modelid && Player::TeamForRace(getRace()) == HORDE)
                modelid = formEntry->CreatureDisplayID[0];
        }
    }

    return modelid;
}

void Unit::JumpTo(float speedXY, float speedZ, bool forward)
{
    float angle = forward ? 0 : float(M_PI);
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
    GetMotionMaster()->MoveJump(x, y, z, GetAngle(obj), speedXY, speedZ, EVENT_JUMP, withOrientation);
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

        SpellInfo const* spellEntry = sSpellMgr->GetSpellInfo(clickPair.second.spellId, caster->GetMap()->GetDifficultyID());
        // if (!spellEntry) should be checked at npc_spellclick load

        if (seatId > -1)
        {
            uint8 i = 0;
            bool valid = false;
            for (SpellEffectInfo const* effect : spellEntry->GetEffects())
            {
                if (!effect)
                    continue;

                if (effect->ApplyAuraName == SPELL_AURA_CONTROL_VEHICLE)
                {
                    valid = true;
                    break;
                }
                ++i;
            }

            if (!valid)
            {
                TC_LOG_ERROR("sql.sql", "Spell %u specified in npc_spellclick_spells is not a valid vehicle enter aura!", clickPair.second.spellId);
                continue;
            }

            if (IsInMap(caster))
            {
                CastSpellExtraArgs args(flags);
                args.OriginalCaster = origCasterGUID;
                args.AddSpellMod(SpellValueMod(SPELLVALUE_BASE_POINT0+i), seatId+1);
                caster->CastSpell(target, clickPair.second.spellId, args);
            }
            else    // This can happen during Player::_LoadAuras
            {
                int32 bp0[MAX_SPELL_EFFECTS];
                for (SpellEffectInfo const* effect : spellEntry->GetEffects())
                    if (effect)
                        bp0[effect->EffectIndex] = effect->BasePoints;

                bp0[i] = seatId;
                Aura::TryRefreshStackOrCreate(spellEntry, ObjectGuid::Create<HighGuid::Cast>(SPELL_CAST_SOURCE_NORMAL, GetMapId(), spellEntry->Id, GetMap()->GenerateLowGuid<HighGuid::Cast>()), MAX_EFFECT_MASK, this, clicker, GetMap()->GetDifficultyID(), bp0, nullptr, origCasterGUID);
            }
        }
        else
        {
            if (IsInMap(caster))
                caster->CastSpell(target, spellEntry->Id, CastSpellExtraArgs().SetOriginalCaster(origCasterGUID));
            else
                Aura::TryRefreshStackOrCreate(spellEntry, ObjectGuid::Create<HighGuid::Cast>(SPELL_CAST_SOURCE_NORMAL, GetMapId(), spellEntry->Id, GetMap()->GenerateLowGuid<HighGuid::Cast>()), MAX_EFFECT_MASK, this, clicker, GetMap()->GetDifficultyID(), nullptr, nullptr, origCasterGUID);
        }

        spellClickHandled = true;
    }

    Creature* creature = ToCreature();
    if (creature && creature->IsAIEnabled)
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
            TC_LOG_DEBUG("entities.vehicle", "EnterVehicle: %u exit %u and enter %u.", GetEntry(), m_vehicle->GetBase()->GetEntry(), vehicle->GetBase()->GetEntry());
            ExitVehicle();
        }
        else if (seatId >= 0 && seatId == GetTransSeat())
            return;
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
    }

    ASSERT(!m_vehicle);
    (void)vehicle->AddPassenger(this, seatId);
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
    Vehicle* vehicle = m_vehicle->RemovePassenger(this);

    Player* player = ToPlayer();

    // If the player is on mounted duel and exits the mount, he should immediatly lose the duel
    if (player && player->duel && player->duel->isMounted)
        player->DuelComplete(DUEL_FLED);

    SetControlled(false, UNIT_STATE_ROOT);      // SMSG_MOVE_FORCE_UNROOT, ~MOVEMENTFLAG_ROOT

    Position pos;
    if (!exitPosition)                          // Exit position not specified
        pos = vehicle->GetBase()->GetPosition();  // This should use passenger's current position, leaving it as it is now
                                                // because we calculate positions incorrect (sometimes under map)
    else
        pos = *exitPosition;

    AddUnitState(UNIT_STATE_MOVE);

    if (player)
        player->SetFallInformation(0, GetPositionZ());

    float height = pos.GetPositionZ() + vehicle->GetBase()->GetCollisionHeight();

    Movement::MoveSplineInit init(this);

    // Creatures without inhabit type air should begin falling after exiting the vehicle
    if (GetTypeId() == TYPEID_UNIT && !CanFly() && height > GetMap()->GetWaterOrGroundLevel(GetPhaseShift(), pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ() + vehicle->GetBase()->GetCollisionHeight(), &height))
        init.SetFall();

    init.MoveTo(pos.GetPositionX(), pos.GetPositionY(), height, false);
    init.SetFacing(GetOrientation());
    init.SetTransportExit();
    init.Launch();

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
}

bool Unit::IsFalling() const
{
    return m_movementInfo.HasMovementFlag(MOVEMENTFLAG_FALLING | MOVEMENTFLAG_FALLING_FAR) || movespline->isFalling();
}

bool Unit::CanSwim() const
{
    // Mirror client behavior, if this method returns false then client will not use swimming animation and for players will apply gravity as if there was no water
    if (HasUnitFlag(UNIT_FLAG_CANNOT_SWIM))
        return false;
    if (HasUnitFlag(UNIT_FLAG_PVP_ATTACKABLE)) // is player
        return true;
    if (HasUnitFlag2(UnitFlags2(0x1000000)))
        return false;
    if (IsPet() && HasUnitFlag(UNIT_FLAG_PET_IN_COMBAT))
        return true;
    return HasUnitFlag(UnitFlags(UNIT_FLAG_RENAME | UNIT_FLAG_UNK_15));
}

void Unit::NearTeleportTo(Position const& pos, bool casting /*= false*/)
{
    DisableSpline();
    if (GetTypeId() == TYPEID_PLAYER)
    {
        WorldLocation target(GetMapId(), pos);
        ToPlayer()->TeleportTo(target, TELE_TO_NOT_LEAVE_TRANSPORT | TELE_TO_NOT_LEAVE_COMBAT | TELE_TO_NOT_UNSUMMON_PET | (casting ? TELE_TO_SPELL : 0));
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

    if (Player* playerMover = GetPlayerBeingMoved())
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
    }

    // Broadcast the packet to everyone except self.
    broadcastSource->SendMessageToSet(moveUpdateTeleport.Write(), false);
}

bool Unit::UpdatePosition(float x, float y, float z, float orientation, bool teleport)
{
    // prevent crash when a bad coord is sent by the client
    if (!Trinity::IsValidMapCoord(x, y, z, orientation))
    {
        TC_LOG_DEBUG("entities.unit", "Unit::UpdatePosition(%f, %f, %f) .. bad coordinates!", x, y, z);
        return false;
    }

    // Check if angular distance changed
    bool const turn = G3D::fuzzyGt(M_PI - fabs(fabs(GetOrientation() - orientation) - M_PI), 0.0f);

    // G3D::fuzzyEq won't help here, in some cases magnitudes differ by a little more than G3D::eps, but should be considered equal
    bool const relocated = (teleport ||
        std::fabs(GetPositionX() - x) > 0.001f ||
        std::fabs(GetPositionY() - y) > 0.001f ||
        std::fabs(GetPositionZ() - z) > 0.001f);

    // TODO: Check if orientation transport offset changed instead of only global orientation
    if (turn)
        RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::Turning);

    if (relocated)
    {
        if (!GetVehicle())
            RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::Moving);

        // move and update visible state if need
        if (GetTypeId() == TYPEID_PLAYER)
            GetMap()->PlayerRelocation(ToPlayer(), x, y, z, orientation);
        else
            GetMap()->CreatureRelocation(ToCreature(), x, y, z, orientation);
    }
    else if (turn)
        UpdateOrientation(orientation);

    UpdatePositionData();

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
    TC_LOG_DEBUG("entities.unit", "%s name %s", GetGUID().ToString().c_str(), GetName().c_str());
    TC_LOG_DEBUG("entities.unit", "Owner %s, Minion %s, Charmer %s, Charmed %s", GetOwnerGUID().ToString().c_str(), GetMinionGUID().ToString().c_str(), GetCharmerGUID().ToString().c_str(), GetCharmGUID().ToString().c_str());
    TC_LOG_DEBUG("entities.unit", "In world %u, unit type mask %u", (uint32)(IsInWorld() ? 1 : 0), m_unitTypeMask);
    if (IsInWorld())
        TC_LOG_DEBUG("entities.unit", "Mapid %u", GetMapId());

    std::ostringstream o;
    o << "Summon Slot: ";
    for (uint32 i = 0; i < MAX_SUMMON_SLOT; ++i)
        o << m_SummonSlot[i].ToString() << ", ";

    TC_LOG_DEBUG("entities.unit", "%s", o.str().c_str());
    o.str("");

    o << "Controlled List: ";
    for (ControlList::const_iterator itr = m_Controlled.begin(); itr != m_Controlled.end(); ++itr)
        o << (*itr)->GetGUID().ToString() << ", ";
    TC_LOG_DEBUG("entities.unit", "%s", o.str().c_str());
    o.str("");

    o << "Aura List: ";
    for (AuraApplicationMap::const_iterator itr = m_appliedAuras.begin(); itr != m_appliedAuras.end(); ++itr)
        o << itr->first << ", ";
    TC_LOG_DEBUG("entities.unit", "%s", o.str().c_str());
    o.str("");

    if (IsVehicle())
    {
        o << "Passenger List: ";
        for (SeatMap::iterator itr = GetVehicleKit()->Seats.begin(); itr != GetVehicleKit()->Seats.end(); ++itr)
            if (Unit* passenger = ObjectAccessor::GetUnit(*GetVehicleBase(), itr->second.Passenger.Guid))
                o << passenger->GetGUID().ToString() << ", ";
        TC_LOG_DEBUG("entities.unit", "%s", o.str().c_str());
    }

    if (GetVehicle())
        TC_LOG_DEBUG("entities.unit", "On vehicle %u.", GetVehicleBase()->GetEntry());
}

uint32 Unit::GetRemainingPeriodicAmount(ObjectGuid caster, uint32 spellId, AuraType auraType, uint8 effectIndex) const
{
    uint32 amount = 0;
    AuraEffectList const& periodicAuras = GetAuraEffectsByType(auraType);
    for (AuraEffect const* aurEff : periodicAuras)
    {
        if (aurEff->GetCasterGUID() != caster || aurEff->GetId() != spellId || aurEff->GetEffIndex() != effectIndex || !aurEff->GetTotalTicks())
            continue;
        amount += uint32((aurEff->GetAmount() * static_cast<int32>(aurEff->GetRemainingTicks())) / aurEff->GetTotalTicks());
        break;
    }

    return amount;
}

void Unit::SendClearTarget()
{
    WorldPackets::Combat::BreakTarget breakTarget;
    breakTarget.UnitGUID = GetGUID();
    SendMessageToSet(breakTarget.Write(), false);
}

int32 Unit::GetResistance(SpellSchoolMask mask) const
{
    Optional<int32> resist = boost::make_optional(false, 0);
    for (int32 i = SPELL_SCHOOL_NORMAL; i < MAX_SPELL_SCHOOL; ++i)
    {
        int32 schoolResistance = GetResistance(SpellSchools(i));
        if (mask & (1 << i) && (!resist || *resist > schoolResistance))
            resist = schoolResistance;
    }

    return resist ? *resist : 0;
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
        SetOrientation(GetAngle(target));
}

void Unit::SetFacingTo(float ori, bool force)
{
    // do not face when already moving
    if (!force && (!IsStopped() || !movespline->Finalized()))
        return;

    Movement::MoveSplineInit init(this);
    init.MoveTo(GetPositionX(), GetPositionY(), GetPositionZMinusOffset(), false);
    if (GetTransport())
        init.DisableTransportPathTransformations(); // It makes no sense to target global orientation
    init.SetFacing(ori);
    init.Launch();
}

void Unit::SetFacingToObject(WorldObject const* object, bool force)
{
    // do not face when already moving
    if (!force && (!IsStopped() || !movespline->Finalized()))
        return;

    /// @todo figure out under what conditions creature will move towards object instead of facing it where it currently is.
    Movement::MoveSplineInit init(this);
    init.MoveTo(GetPositionX(), GetPositionY(), GetPositionZMinusOffset(), false);
    init.SetFacing(GetAngle(object));   // when on transport, GetAngle will still return global coordinates (and angle) that needs transforming
    init.Launch();
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

bool Unit::SetDisableGravity(bool disable)
{
    if (disable == IsLevitating())
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

    if (Player* playerMover = GetPlayerBeingMoved())
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

    if (Player* playerMover = GetPlayerBeingMoved())
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

    if (Player* playerMover = GetPlayerBeingMoved())
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
    if (enable == HasUnitMovementFlag(MOVEMENTFLAG_FALLING_SLOW))
        return false;

    if (enable)
        AddUnitMovementFlag(MOVEMENTFLAG_FALLING_SLOW);
    else
        RemoveUnitMovementFlag(MOVEMENTFLAG_FALLING_SLOW);

    static OpcodeServer const featherFallOpcodeTable[2][2] =
    {
        { SMSG_MOVE_SPLINE_SET_NORMAL_FALL,  SMSG_MOVE_SET_NORMAL_FALL  },
        { SMSG_MOVE_SPLINE_SET_FEATHER_FALL, SMSG_MOVE_SET_FEATHER_FALL }
    };

    if (Player* playerMover = GetPlayerBeingMoved())
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

bool Unit::SetHover(bool enable)
{
    if (enable == HasUnitMovementFlag(MOVEMENTFLAG_HOVER))
        return false;

    float hoverHeight = m_unitData->HoverHeight;

    if (enable)
    {
        //! No need to check height on ascent
        AddUnitMovementFlag(MOVEMENTFLAG_HOVER);
        if (hoverHeight)
            UpdateHeight(GetPositionZ() + hoverHeight);
    }
    else
    {
        RemoveUnitMovementFlag(MOVEMENTFLAG_HOVER);
        if (hoverHeight)
        {
            float newZ = GetPositionZ() - hoverHeight;
            UpdateAllowedPositionZ(GetPositionX(), GetPositionY(), newZ);
            UpdateHeight(newZ);
        }
    }

    static OpcodeServer const hoverOpcodeTable[2][2] =
    {
        { SMSG_MOVE_SPLINE_UNSET_HOVER, SMSG_MOVE_UNSET_HOVERING },
        { SMSG_MOVE_SPLINE_SET_HOVER,   SMSG_MOVE_SET_HOVERING   }
    };

    if (Player* playerMover = GetPlayerBeingMoved())
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

    if (Player* playerMover = GetPlayerBeingMoved())
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

    if (Player* playerMover = GetPlayerBeingMoved())
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
    if (enable == HasExtraUnitMovementFlag(MOVEMENTFLAG2_CAN_TURN_WHILE_FALLING))
        return false;

    if (enable)
        AddExtraUnitMovementFlag(MOVEMENTFLAG2_CAN_TURN_WHILE_FALLING);
    else
        RemoveExtraUnitMovementFlag(MOVEMENTFLAG2_CAN_TURN_WHILE_FALLING);

    static OpcodeServer const canTurnWhileFallingOpcodeTable[2] =
    {
        SMSG_MOVE_UNSET_CAN_TURN_WHILE_FALLING,
        SMSG_MOVE_SET_CAN_TURN_WHILE_FALLING
    };

    if (Player* playerMover = GetPlayerBeingMoved())
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

    if (Player* playerMover = GetPlayerBeingMoved())
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

void Unit::ApplyMovementForce(ObjectGuid id, Position origin, float magnitude, uint8 type, Position direction /*= {}*/, ObjectGuid transportGuid /*= ObjectGuid::Empty*/)
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

void Unit::SendSetPlayHoverAnim(bool enable)
{
    WorldPackets::Misc::SetPlayHoverAnim data;
    data.UnitGUID = GetGUID();
    data.PlayHoverAnim = enable;

    SendMessageToSet(data.Write(), true);
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

    ByteBuffer buffer = PrepareValuesUpdateBuffer();
    std::size_t sizePos = buffer.wpos();
    buffer << uint32(0);
    buffer << uint32(valuesMask.GetBlock(0));

    if (valuesMask[TYPEID_OBJECT])
        m_objectData->WriteUpdate(buffer, requestedObjectMask, true, this, target);

    if (valuesMask[TYPEID_UNIT])
        m_unitData->WriteUpdate(buffer, unitMask, true, this, target);

    buffer.put<uint32>(sizePos, buffer.wpos() - sizePos - 4);

    data->AddUpdateBlock(buffer);
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
    for (AuraEffect* aurEff : aura->GetAuraEffects())
    {
        if (!aurEff)
            continue;
        AuraType const auraType = AuraType(aurEff->GetSpellEffectInfo()->ApplyAuraName);
        AuraEffectList const& auras = GetAuraEffectsByType(auraType);
        for (Unit::AuraEffectList::const_iterator itr = auras.begin(); itr != auras.end();)
        {
            AuraEffect const* existingAurEff = (*itr);
            ++itr;

            if (sSpellMgr->CheckSpellGroupStackRules(aura->GetSpellInfo(), existingAurEff->GetSpellInfo())
                == SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST)
            {
                int32 diff = abs(aurEff->GetAmount()) - abs(existingAurEff->GetAmount());
                if (!diff)
                    diff = int32(aura->GetEffectMask()) - int32(existingAurEff->GetBase()->GetEffectMask());

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
    }

    return true;
}

void Unit::Talk(std::string const& text, ChatMsg msgType, Language language, float textRange, WorldObject const* target)
{
    Trinity::CustomChatTextBuilder builder(this, msgType, text, language, target);
    Trinity::LocalizedDo<Trinity::CustomChatTextBuilder> localizer(builder);
    Trinity::PlayerDistWorker<Trinity::LocalizedDo<Trinity::CustomChatTextBuilder> > worker(this, textRange, localizer);
    Cell::VisitWorldObjects(this, worker, textRange);
}

void Unit::Say(std::string const& text, Language language, WorldObject const* target /*= nullptr*/)
{
    Talk(text, CHAT_MSG_MONSTER_SAY, language, sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_SAY), target);
}

void Unit::Yell(std::string const& text, Language language, WorldObject const* target /*= nullptr*/)
{
    Talk(text, CHAT_MSG_MONSTER_YELL, language, sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_YELL), target);
}

void Unit::TextEmote(std::string const& text, WorldObject const* target /*= nullptr*/, bool isBossEmote /*= false*/)
{
    Talk(text, isBossEmote ? CHAT_MSG_RAID_BOSS_EMOTE : CHAT_MSG_MONSTER_EMOTE, LANG_UNIVERSAL, sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_TEXTEMOTE), target);
}

void Unit::Whisper(std::string const& text, Language language, Player* target, bool isBossWhisper /*= false*/)
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
        TC_LOG_ERROR("entities.unit", "WorldObject::MonsterText: `broadcast_text` (ID: %u) was not found", textId);
        return;
    }

    Trinity::BroadcastTextBuilder builder(this, msgType, textId, getGender(), target);
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
        TC_LOG_ERROR("entities.unit", "WorldObject::MonsterWhisper: `broadcast_text` was not %u found", textId);
        return;
    }

    LocaleConstant locale = target->GetSession()->GetSessionDbLocaleIndex();
    WorldPackets::Chat::Chat packet;
    packet.Initialize(isBossWhisper ? CHAT_MSG_RAID_BOSS_WHISPER : CHAT_MSG_MONSTER_WHISPER, LANG_UNIVERSAL, this, target, DB2Manager::GetBroadcastTextValue(bct, locale, getGender()), 0, "", locale);
    target->SendDirectMessage(packet.Write());
}

SpellInfo const* Unit::GetCastSpellInfo(SpellInfo const* spellInfo) const
{
    auto findMatchingAuraEffectIn = [this, spellInfo](AuraType type) -> SpellInfo const*
    {
        for (AuraEffect const* auraEffect : GetAuraEffectsByType(type))
        {
            bool matches = auraEffect->GetMiscValue() ? uint32(auraEffect->GetMiscValue()) == spellInfo->Id : auraEffect->IsAffectingSpell(spellInfo);
            if (matches)
                if (SpellInfo const* newInfo = sSpellMgr->GetSpellInfo(auraEffect->GetAmount(), GetMap()->GetDifficultyID()))
                    return newInfo;
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

    return spellInfo->GetSpellXSpellVisualId(this);
}

struct CombatLogSender
{
    WorldPackets::CombatLog::CombatLogServerPacket const* i_message;

    explicit CombatLogSender(WorldPackets::CombatLog::CombatLogServerPacket* msg)
        : i_message(msg)
    {
        msg->Write();
    }

    void operator()(Player const* player) const
    {
        if (player->IsAdvancedCombatLoggingEnabled())
            player->SendDirectMessage(i_message->GetFullLogPacket());
        else
            player->SendDirectMessage(i_message->GetBasicLogPacket());
    }
};

void Unit::SendCombatLogMessage(WorldPackets::CombatLog::CombatLogServerPacket* combatLog) const
{
    CombatLogSender combatLogSender(combatLog);

    if (Player const* self = ToPlayer())
        combatLogSender(self);

    Trinity::MessageDistDeliverer<CombatLogSender> notifier(this, combatLogSender, GetVisibilityRange());
    Cell::VisitWorldObjects(this, notifier, GetVisibilityRange());
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
                float const collisionHeight = scaleMod * (mountModelData->MountHeight + modelData->CollisionHeight * modelData->ModelScale * displayInfo->CreatureModelScale * 0.5f);
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
