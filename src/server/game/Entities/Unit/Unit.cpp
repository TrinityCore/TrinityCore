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
#include "BattlegroundScore.h"
#include "CellImpl.h"
#include "CharacterCache.h"
#include "Chat.h"
#include "ChatPackets.h"
#include "ChatTextBuilder.h"
#include "CombatPackets.h"
#include "Common.h"
#include "ConditionMgr.h"
#include "Containers.h"
#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "CreatureGroups.h"
#include "Formulas.h"
#include "GameClient.h"
#include "GameObjectAI.h"
#include "GameTime.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "InstanceSaveMgr.h"
#include "InstanceScript.h"
#include "Item.h"
#include "Log.h"
#include "LootMgr.h"
#include "MotionMaster.h"
#include "MovementGenerator.h"
#include "MovementPacketBuilder.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "OutdoorPvP.h"
#include "MovementPacketSender.h"
#include "PassiveAI.h"
#include "PetAI.h"
#include "Pet.h"
#include "Player.h"
#include "PlayerAI.h"
#include "QuestDef.h"
#include "ReputationMgr.h"
#include "ScheduledChangeAI.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "StringConvert.h"
#include "TemporarySummon.h"
#include "Transport.h"
#include "Totem.h"
#include "UnitAI.h"
#include "UpdateFieldFlags.h"
#include "Util.h"
#include "Vehicle.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"
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

DamageInfo::DamageInfo(Unit* attacker, Unit* victim, uint32 damage, SpellInfo const* spellInfo, SpellSchoolMask schoolMask, DamageEffectType damageType, WeaponAttackType attackType)
    : m_attacker(attacker), m_victim(victim), m_damage(damage), m_spellInfo(spellInfo), m_schoolMask(schoolMask), m_damageType(damageType), m_attackType(attackType),
    m_absorb(0), m_resist(0), m_block(0), m_hitMask(0)
{
}

DamageInfo::DamageInfo(DamageInfo const& dmg1, DamageInfo const& dmg2)
    : m_attacker(dmg1.m_attacker), m_victim(dmg1.m_victim), m_damage(dmg1.m_damage + dmg2.m_damage), m_spellInfo(dmg1.m_spellInfo), m_schoolMask(SpellSchoolMask(dmg1.m_schoolMask | dmg2.m_schoolMask)),
    m_damageType(dmg1.m_damageType), m_attackType(dmg1.m_attackType), m_absorb(dmg1.m_absorb + dmg2.m_absorb), m_resist(dmg1.m_resist + dmg2.m_resist), m_block(dmg1.m_block), m_hitMask(dmg1.m_hitMask | dmg2.m_hitMask)
{
}

DamageInfo::DamageInfo(CalcDamageInfo const& dmgInfo) : DamageInfo(DamageInfo(dmgInfo, 0), DamageInfo(dmgInfo, 1))
{
}

DamageInfo::DamageInfo(CalcDamageInfo const& dmgInfo, uint8 damageIndex)
    : m_attacker(dmgInfo.Attacker), m_victim(dmgInfo.Target), m_damage(dmgInfo.Damages[damageIndex].Damage), m_spellInfo(nullptr), m_schoolMask(SpellSchoolMask(dmgInfo.Damages[damageIndex].DamageSchoolMask)),
    m_damageType(DIRECT_DAMAGE), m_attackType(dmgInfo.AttackType), m_absorb(dmgInfo.Damages[damageIndex].Absorb), m_resist(dmgInfo.Damages[damageIndex].Resist), m_block(dmgInfo.Blocked), m_hitMask(0)
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
    : m_attacker(spellNonMeleeDamage.attacker), m_victim(spellNonMeleeDamage.target), m_damage(spellNonMeleeDamage.damage),
    m_spellInfo(sSpellMgr->GetSpellInfo(spellNonMeleeDamage.SpellID)), m_schoolMask(SpellSchoolMask(spellNonMeleeDamage.schoolMask)), m_damageType(damageType),
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
    : _healer(healer), _target(target), _heal(heal), _effectiveHeal(0), _absorb(0), _spellInfo(spellInfo), _schoolMask(schoolMask), _hitMask(0)
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

DispelableAura::DispelableAura(Aura* aura, int32 dispelChance, uint8 dispelCharges) :
    _aura(aura), _chance(dispelChance), _charges(dispelCharges)
{
}

DispelableAura::~DispelableAura() = default;

bool DispelableAura::RollDispel() const
{
    return roll_chance_i(_chance);
}

Unit::Unit(bool isWorldObject) :
    WorldObject(isWorldObject), m_lastSanctuaryTime(0), LastCharmerGUID(), movespline(new Movement::MoveSpline()),
    m_ControlledByPlayer(false), m_AutoRepeatFirstCast(false), m_procDeep(0), m_transformSpell(0),
    m_removedAurasCount(0), m_charmer(nullptr), m_charmed(nullptr),
    i_motionMaster(new MotionMaster(this)), m_regenTimer(0), m_vehicle(nullptr), m_vehicleKit(nullptr),
    m_unitTypeMask(UNIT_MASK_NONE), m_Diminishing(), m_combatManager(this), m_threatManager(this),
    m_aiLocked(false), m_comboTarget(nullptr), m_comboPoints(0), _spellHistory(new SpellHistory(this))
{
    m_objectType |= TYPEMASK_UNIT;
    m_objectTypeId = TYPEID_UNIT;

    m_updateFlag = (UPDATEFLAG_LIVING | UPDATEFLAG_STATIONARY_POSITION);

    m_attackTimer[BASE_ATTACK] = 0;
    m_attackTimer[OFF_ATTACK] = 0;
    m_attackTimer[RANGED_ATTACK] = 0;
    m_modAttackSpeedPct[BASE_ATTACK] = 1.0f;
    m_modAttackSpeedPct[OFF_ATTACK] = 1.0f;
    m_modAttackSpeedPct[RANGED_ATTACK] = 1.0f;

    m_canDualWield = false;

    m_movementCounter = 0;

    m_rootTimes = 0;

    m_state = 0;
    m_deathState = ALIVE;

    for (uint8 i = 0; i < CURRENT_MAX_SPELL; ++i)
        m_currentSpells[i] = nullptr;

    for (uint8 i = 0; i < MAX_SUMMON_SLOT; ++i)
        m_SummonSlot[i].Clear();

    for (uint8 i = 0; i < MAX_GAMEOBJECT_SLOT; ++i)
        m_ObjectSlot[i].Clear();

    m_auraUpdateIterator = m_ownedAuras.end();

    m_interruptMask = 0;
    m_canModifyStats = false;

    for (uint8 i = 0; i < UNIT_MOD_END; ++i)
    {
        m_auraFlatModifiersGroup[i][BASE_VALUE] = 0.0f;
        m_auraFlatModifiersGroup[i][TOTAL_VALUE] = 0.0f;
        m_auraPctModifiersGroup[i][BASE_PCT] = 1.0f;
        m_auraPctModifiersGroup[i][TOTAL_PCT] = 1.0f;
    }
                                                            // implement 50% base damage from offhand
    m_auraPctModifiersGroup[UNIT_MOD_DAMAGE_OFFHAND][TOTAL_PCT] = 0.5f;

    for (uint8 i = 0; i < MAX_ATTACK; ++i)
    {
        m_weaponDamage[i][MINDAMAGE][0] = BASE_MINDAMAGE;
        m_weaponDamage[i][MAXDAMAGE][0] = BASE_MAXDAMAGE;

        m_weaponDamage[i][MINDAMAGE][1] = 0.f;
        m_weaponDamage[i][MAXDAMAGE][1] = 0.f;
    }

    for (uint8 i = 0; i < MAX_STATS; ++i)
        m_createStats[i] = 0.0f;

    m_attacking = nullptr;
    m_modMeleeHitChance = 0.0f;
    m_modRangedHitChance = 0.0f;
    m_modSpellHitChance = 0.0f;
    m_baseSpellCritChance = 5.0f;

    m_lastManaUse = 0;

    for (uint8 i = 0; i < MAX_MOVE_TYPE; ++i)
        m_speed_rate[i] = 1.0f;

    m_charmInfo = nullptr;
    _gameClientMovingMe = nullptr;

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
    _isCombatDisallowed = false;

    _lastExtraAttackSpell = 0;
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
    ASSERT(!_gameClientMovingMe || _gameClientMovingMe->GetBasePlayer() == this);
}

void Unit::Update(uint32 p_time)
{
    // WARNING! Order of execution here is important, do not change.
    // Spells must be processed with event system BEFORE they go to _UpdateSpells.
    // Or else we may have some SPELL_STATE_FINISHED spells stalled in pointers, that is bad.
    m_Events.Update(p_time);

    CheckPendingMovementAcks();

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
        ModifyAuraState(AURA_STATE_HEALTHLESS_20_PERCENT, HealthBelowPct(20));
        ModifyAuraState(AURA_STATE_HEALTHLESS_35_PERCENT, HealthBelowPct(35));
        ModifyAuraState(AURA_STATE_HEALTH_ABOVE_75_PERCENT, HealthAbovePct(75));
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

            WorldPacket data(SMSG_FLIGHT_SPLINE_SYNC, 4 + GetPackGUID().size());
            Movement::PacketBuilder::WriteSplineSync(*movespline, data);
            data.appendPackGUID(GetGUID());
            SendMessageToSet(&data, true);
        }
    }

    if (arrived)
    {
        DisableSpline();

        if (movespline->HasAnimation())
            SetAnimTier(movespline->GetAnimTier());
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

    if (HasUnitState(UNIT_STATE_CANNOT_TURN))
        loc.orientation = GetOrientation();

    UpdatePosition(loc.x, loc.y, loc.z, loc.orientation);
}

void Unit::InterruptMovementBasedAuras()
{
    // TODO: Check if orientation transport offset changed instead of only global orientation
    if (_positionUpdateInfo.Turned)
        RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TURNING);

    if (_positionUpdateInfo.Relocated && !GetVehicle())
        RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_MOVE);
}

void Unit::DisableSpline()
{
    m_movementInfo.RemoveMovementFlag(MovementFlags(MOVEMENTFLAG_SPLINE_ENABLED|MOVEMENTFLAG_FORWARD));
    movespline->_Interrupt();
}

void Unit::resetAttackTimer(WeaponAttackType type)
{
    m_attackTimer[type] = uint32(GetAttackTime(type) * m_modAttackSpeedPct[type]);
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

    float maxdist = GetMeleeRange(obj);

    return distsq <= maxdist * maxdist;
}

float Unit::GetMeleeRange(Unit const* target) const
{
    float range = GetCombatReach() + target->GetCombatReach() + 4.0f / 3.0f;
    return std::max(range, NOMINAL_MELEE_RANGE);
}

AuraApplication* Unit::GetVisibleAura(uint8 slot) const
{
    VisibleAuraMap::const_iterator itr = m_visibleAuras.find(slot);
    if (itr != m_visibleAuras.end())
        return itr->second;
    return 0;
}

void Unit::SetVisibleAura(uint8 slot, AuraApplication * aur)
{
    m_visibleAuras[slot]=aur;
    UpdateAuraForGroup(slot);
}

void Unit::RemoveVisibleAura(uint8 slot)
{
    m_visibleAuras.erase(slot);
    UpdateAuraForGroup(slot);
}

void Unit::UpdateInterruptMask()
{
    m_interruptMask = 0;
    for (AuraApplicationList::const_iterator i = m_interruptableAuras.begin(); i != m_interruptableAuras.end(); ++i)
        m_interruptMask |= (*i)->GetBase()->GetSpellInfo()->AuraInterruptFlags;

    if (Spell* spell = m_currentSpells[CURRENT_CHANNELED_SPELL])
        if (spell->getState() == SPELL_STATE_CASTING)
            m_interruptMask |= spell->m_spellInfo->ChannelInterruptFlags;
}

bool Unit::HasAuraTypeWithFamilyFlags(AuraType auraType, uint32 familyName, flag96 familyFlags) const
{
    if (!HasAuraType(auraType))
        return false;
    AuraEffectList const& auras = GetAuraEffectsByType(auraType);
    for (AuraEffectList::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
        if (SpellInfo const* iterSpellProto = (*itr)->GetSpellInfo())
            if (iterSpellProto->SpellFamilyName == familyName && iterSpellProto->SpellFamilyFlags & familyFlags)
                return true;
    return false;
}

bool Unit::HasBreakableByDamageAuraType(AuraType type, uint32 excludeAura) const
{
    AuraEffectList const& auras = GetAuraEffectsByType(type);
    for (AuraEffectList::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
        if ((!excludeAura || excludeAura != (*itr)->GetSpellInfo()->Id) && //Avoid self interrupt of channeled Crowd Control spells like Seduction
            ((*itr)->GetSpellInfo()->AuraInterruptFlags & AURA_INTERRUPT_FLAG_TAKE_DAMAGE))
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
            || HasBreakableByDamageAuraType(SPELL_AURA_TRANSFORM, excludeAura));
}

/*static*/ void Unit::DealDamageMods(Unit const* victim, uint32& damage, uint32* absorb)
{
    if (!victim || !victim->IsAlive() || victim->HasUnitState(UNIT_STATE_IN_FLIGHT) || (victim->GetTypeId() == TYPEID_UNIT && victim->ToCreature()->IsEvadingAttacks()))
    {
        if (absorb)
            *absorb += damage;
        damage = 0;
    }
}

/*static*/ uint32 Unit::DealDamage(Unit* attacker, Unit* victim, uint32 damage, CleanDamage const* cleanDamage, DamageEffectType damagetype, SpellSchoolMask damageSchoolMask, SpellInfo const* spellProto, bool durabilityLoss)
{
    uint32 rage_damage = damage + (cleanDamage ? cleanDamage->absorbed_damage : 0);

    if (UnitAI* victimAI = victim->GetAI())
        victimAI->DamageTaken(attacker, damage, damagetype, spellProto);

    if (UnitAI* attackerAI = attacker ? attacker->GetAI() : nullptr)
        attackerAI->DamageDealt(victim, damage, damagetype);

    // Hook for OnDamage Event
    sScriptMgr->OnDamage(attacker, victim, damage);

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
        // interrupting auras with AURA_INTERRUPT_FLAG_DAMAGE before checking !damage (absorbed damage breaks that type of auras)
        if (spellProto)
        {
            if (!spellProto->HasAttribute(SPELL_ATTR4_DAMAGE_DOESNT_BREAK_AURAS))
                victim->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TAKE_DAMAGE, spellProto->Id);
        }
        else
            victim->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TAKE_DAMAGE, 0);

        // interrupt spells with SPELL_INTERRUPT_FLAG_ABORT_ON_DMG on absorbed damage (no dots)
        if (!damage && damagetype != DOT && cleanDamage && cleanDamage->absorbed_damage)
        {
            if (victim != attacker && victim->GetTypeId() == TYPEID_PLAYER)
            {
                if (Spell* spell = victim->m_currentSpells[CURRENT_GENERIC_SPELL])
                    if (spell->getState() == SPELL_STATE_PREPARING)
                    {
                        uint32 interruptFlags = spell->m_spellInfo->InterruptFlags;
                        if ((interruptFlags & SPELL_INTERRUPT_FLAG_ABORT_ON_DMG) != 0)
                            victim->InterruptNonMeleeSpells(false);
                    }
            }
        }

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
            Unit::DealDamageMods(shareDamageTarget, share, nullptr);
            Unit::DealDamage(attacker, shareDamageTarget, share, nullptr, NODAMAGE, spell->GetSchoolMask(), spell, false);
        }
    }

    // Rage from Damage made (only from direct weapon damage)
    if (attacker && cleanDamage && damagetype == DIRECT_DAMAGE && attacker != victim && attacker->GetPowerType() == POWER_RAGE)
    {
        uint32 weaponSpeedHitFactor;

        switch (cleanDamage->attackType)
        {
            case BASE_ATTACK:
            case OFF_ATTACK:
            {
                weaponSpeedHitFactor = uint32(attacker->GetAttackTime(cleanDamage->attackType) / 1000.0f * (cleanDamage->attackType == BASE_ATTACK ? 3.5f : 1.75f));
                if (cleanDamage->hitOutCome == MELEE_HIT_CRIT)
                    weaponSpeedHitFactor *= 2;

                attacker->RewardRage(rage_damage, weaponSpeedHitFactor, true);
                break;
            }
            case RANGED_ATTACK:
                break;
            default:
                break;
        }
    }

    if (!damage)
    {
        // Rage from absorbed damage
        if (cleanDamage && cleanDamage->absorbed_damage && victim->GetPowerType() == POWER_RAGE)
            victim->RewardRage(cleanDamage->absorbed_damage, 0, false);

        return 0;
    }

    uint32 health = victim->GetHealth();

    // duel ends when player has 1 or less hp
    bool duel_hasEnded = false;
    bool duel_wasMounted = false;
    if (victim->GetTypeId() == TYPEID_PLAYER && victim->ToPlayer()->duel && damage >= (health-1))
    {
        if (!attacker)
            return 0;

        // prevent kill only if killed in duel and killed by opponent or opponent controlled creature
        if (victim->ToPlayer()->duel->Opponent == attacker->GetControllingPlayer())
            damage = health - 1;

        duel_hasEnded = true;
    }
    else if (victim->IsVehicle() && damage >= (health-1) && victim->GetCharmer() && victim->GetCharmer()->GetTypeId() == TYPEID_PLAYER)
    {
        Player* victimRider = victim->GetCharmer()->ToPlayer();

        if (victimRider && victimRider->duel && victimRider->duel->IsMounted)
        {
            if (!attacker)
                return 0;

            // prevent kill only if killed in duel and killed by opponent or opponent controlled creature
            if (victimRider->duel->Opponent == attacker->GetControllingPlayer())
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

            killer->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_DAMAGE_DONE, health > damage ? damage : health, 0, victim);
            killer->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HIT_DEALT, damage);
        }
    }

    if (victim->GetTypeId() == TYPEID_PLAYER)
        victim->ToPlayer()->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HIT_RECEIVED, damage);
    else if (!victim->IsControlledByPlayer() || victim->IsVehicle())
    {
        if (!victim->ToCreature()->hasLootRecipient())
            victim->ToCreature()->SetLootRecipient(attacker);

        if (!attacker || attacker->IsControlledByPlayer() || (attacker->ToTempSummon() && attacker->ToTempSummon()->GetSummonerUnit() && attacker->ToTempSummon()->GetSummonerUnit()->GetTypeId() == TYPEID_PLAYER))
            victim->ToCreature()->LowerPlayerDamageReq(health < damage ?  health : damage);
    }

    if (health <= damage)
    {
        if (victim->GetTypeId() == TYPEID_PLAYER && victim != attacker)
            victim->ToPlayer()->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_TOTAL_DAMAGE_RECEIVED, health);

        Unit::Kill(attacker, victim, durabilityLoss);
    }
    else
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            victim->ToPlayer()->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_TOTAL_DAMAGE_RECEIVED, damage);

        victim->ModifyHealth(-(int32)damage);

        if (damagetype == DIRECT_DAMAGE || damagetype == SPELL_DIRECT_DAMAGE)
            victim->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_DIRECT_DAMAGE, spellProto ? spellProto->Id : 0);

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

        // Rage from damage received
        if (attacker != victim && victim->GetPowerType() == POWER_RAGE)
        {
            rage_damage = damage + (cleanDamage ? cleanDamage->absorbed_damage : 0);
            victim->RewardRage(rage_damage, 0, false);
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

        if (damagetype != NODAMAGE && damagetype != DOT && damage)
        {
            if (victim != attacker && victim->GetTypeId() == TYPEID_PLAYER && (!spellProto || !(spellProto->HasAttribute(SPELL_ATTR7_NO_PUSHBACK_ON_DAMAGE) || spellProto->HasAttribute(SPELL_ATTR3_TREAT_AS_PERIODIC))))
            {
                if (Spell* spell = victim->m_currentSpells[CURRENT_GENERIC_SPELL])
                {
                    if (spell->getState() == SPELL_STATE_PREPARING)
                    {
                        uint32 interruptFlags = spell->m_spellInfo->InterruptFlags;
                        if (interruptFlags & SPELL_INTERRUPT_FLAG_ABORT_ON_DMG)
                            victim->InterruptNonMeleeSpells(false);
                        else
                            spell->Delayed();
                    }
                }

                if (Spell* spell = victim->m_currentSpells[CURRENT_CHANNELED_SPELL])
                    if (spell->getState() == SPELL_STATE_CASTING)
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
    if (victim->GetStandState() && victim->IsPlayer() && damagetype != NODAMAGE && damagetype != DOT)
        victim->SetStandState(UNIT_STAND_STATE_STAND);

    return damage;
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
    uint32 crTypeMask = victim->GetCreatureTypeMask();

    // Spells with SPELL_ATTR4_FIXED_DAMAGE ignore resilience because their damage is based off another spell's damage.
    if (!spellInfo->HasAttribute(SPELL_ATTR4_FIXED_DAMAGE))
    {
        if (Unit::IsDamageReducedByArmor(damageSchoolMask, spellInfo))
            damage = Unit::CalcArmorReducedDamage(this, victim, damage, spellInfo, attackType);

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
                        modOwner->ApplySpellMod(spellInfo->Id, SPELLMOD_CRIT_DAMAGE_BONUS, crit_bonus);
                    damage += crit_bonus;

                    // Apply SPELL_AURA_MOD_ATTACKER_RANGED_CRIT_DAMAGE or SPELL_AURA_MOD_ATTACKER_MELEE_CRIT_DAMAGE
                    float critPctDamageMod = 0.0f;
                    if (attackType == RANGED_ATTACK)
                        critPctDamageMod += victim->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_RANGED_CRIT_DAMAGE);
                    else
                        critPctDamageMod += victim->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_MELEE_CRIT_DAMAGE);

                    // Increase crit damage from SPELL_AURA_MOD_CRIT_DAMAGE_BONUS
                    critPctDamageMod += (GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_CRIT_DAMAGE_BONUS, spellInfo->GetSchoolMask()) - 1.0f) * 100;

                    // Increase crit damage from SPELL_AURA_MOD_CRIT_PERCENT_VERSUS
                    critPctDamageMod += GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_CRIT_PERCENT_VERSUS, crTypeMask);

                    if (critPctDamageMod != 0)
                        AddPct(damage, critPctDamageMod);
                }

                // Spell weapon based damage CAN BE crit & blocked at same time
                if (blocked)
                {
                    damageInfo->blocked = victim->GetShieldBlockValue();
                    // double blocked amount if block is critical
                    if (victim->IsBlockCritical())
                        damageInfo->blocked += damageInfo->blocked;
                    if (damage <= int32(damageInfo->blocked))
                    {
                        damageInfo->blocked = uint32(damage);
                        damageInfo->fullBlock = true;
                    }
                    damage -= damageInfo->blocked;
                }

                if (CanApplyResilience())
                    Unit::ApplyResilience(victim, nullptr, &damage, crit, (attackType == RANGED_ATTACK ? CR_CRIT_TAKEN_RANGED : CR_CRIT_TAKEN_MELEE));
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
                    Unit::ApplyResilience(victim, nullptr, &damage, crit, CR_CRIT_TAKEN_SPELL);
                break;
            }
            default:
                break;
        }
    }

    // Script Hook For CalculateSpellDamageTaken -- Allow scripts to change the Damage post class mitigation calculations
    sScriptMgr->ModifySpellDamageTaken(damageInfo->target, damageInfo->attacker, damage);

    // Calculate absorb resist
    if (damage < 0)
        damage = 0;

    damageInfo->damage = damage;
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

    SpellInfo const* spellProto = sSpellMgr->GetSpellInfo(damageInfo->SpellID);
    if (spellProto == nullptr)
    {
        TC_LOG_DEBUG("entities.unit", "Unit::DealSpellDamage has wrong damageInfo->SpellID: {}", damageInfo->SpellID);
        return;
    }

    // Call default DealDamage
    CleanDamage cleanDamage(damageInfo->cleanDamage, damageInfo->absorb, BASE_ATTACK, MELEE_HIT_NORMAL);
    Unit::DealDamage(this, victim, damageInfo->damage, &cleanDamage, SPELL_DIRECT_DAMAGE, SpellSchoolMask(damageInfo->schoolMask), spellProto, durabilityLoss);
}

/// @todo for melee need create structure as in
void Unit::CalculateMeleeDamage(Unit* victim, CalcDamageInfo* damageInfo, WeaponAttackType attackType)
{
    damageInfo->Attacker         = this;
    damageInfo->Target           = victim;

    for (uint8 i = 0; i < MAX_ITEM_PROTO_DAMAGES; ++i)
    {
        damageInfo->Damages[i].DamageSchoolMask = GetMeleeDamageSchoolMask(attackType, i);
        damageInfo->Damages[i].Damage = 0;
        damageInfo->Damages[i].Absorb = 0;
        damageInfo->Damages[i].Resist = 0;
    }

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

    // Physical Immune check (must immune to all damages)
    uint8 immunedMask = 0;
    for (uint8 i = 0; i < MAX_ITEM_PROTO_DAMAGES; ++i)
        if (damageInfo->Target->IsImmunedToDamage(SpellSchoolMask(damageInfo->Damages[i].DamageSchoolMask)))
            immunedMask |= (1 << i);

    if (immunedMask == ((1 << 0) | (1 << 1)))
    {
        damageInfo->HitInfo |= HITINFO_NORMALSWING;
        damageInfo->TargetState = VICTIMSTATE_IS_IMMUNE;
        damageInfo->CleanDamage = 0;
        return;
    }

    for (uint8 i = 0; i < MAX_ITEM_PROTO_DAMAGES; ++i)
    {
        // only players have secondary weapon damage
        if (i > 0 && GetTypeId() != TYPEID_PLAYER)
            break;

        if (immunedMask & (1 << i))
            continue;

        SpellSchoolMask schoolMask = SpellSchoolMask(damageInfo->Damages[i].DamageSchoolMask);
        bool const addPctMods = (schoolMask & SPELL_SCHOOL_MASK_NORMAL);

        uint32 damage = 0;
        uint8 itemDamagesMask = (GetTypeId() == TYPEID_PLAYER) ? (1 << i) : 0;
        damage += CalculateDamage(damageInfo->AttackType, false, addPctMods, itemDamagesMask);
        // Add melee damage bonus
        damage = MeleeDamageBonusDone(damageInfo->Target, damage, damageInfo->AttackType, nullptr, schoolMask);
        damage = damageInfo->Target->MeleeDamageBonusTaken(this, damage, damageInfo->AttackType, nullptr, schoolMask);

        // Script Hook For CalculateMeleeDamage -- Allow scripts to change the Damage pre class mitigation calculations
        sScriptMgr->ModifyMeleeDamage(damageInfo->Target, damageInfo->Attacker, damage);

        // Calculate armor reduction
        if (Unit::IsDamageReducedByArmor(SpellSchoolMask(damageInfo->Damages[i].DamageSchoolMask)))
        {
            damageInfo->Damages[i].Damage = Unit::CalcArmorReducedDamage(damageInfo->Attacker, damageInfo->Target, damage, nullptr, damageInfo->AttackType);
            damageInfo->CleanDamage += damage - damageInfo->Damages[i].Damage;
        }
        else
            damageInfo->Damages[i].Damage = damage;
    }

    damageInfo->HitOutCome = RollMeleeOutcomeAgainst(damageInfo->Target, damageInfo->AttackType);

    switch (damageInfo->HitOutCome)
    {
        case MELEE_HIT_EVADE:
            damageInfo->HitInfo        |= HITINFO_MISS | HITINFO_SWINGNOHITSOUND;
            damageInfo->TargetState     = VICTIMSTATE_EVADES;

            for (uint8 i = 0; i < MAX_ITEM_PROTO_DAMAGES; ++i)
                damageInfo->Damages[i].Damage = 0;
            damageInfo->CleanDamage = 0;
            return;
        case MELEE_HIT_MISS:
            damageInfo->HitInfo        |= HITINFO_MISS;
            damageInfo->TargetState     = VICTIMSTATE_INTACT;

            for (uint8 i = 0; i < MAX_ITEM_PROTO_DAMAGES; ++i)
                damageInfo->Damages[i].Damage = 0;
            damageInfo->CleanDamage     = 0;
            break;
        case MELEE_HIT_NORMAL:
            damageInfo->TargetState     = VICTIMSTATE_HIT;
            break;
        case MELEE_HIT_CRIT:
        {
            damageInfo->HitInfo        |= HITINFO_CRITICALHIT;
            damageInfo->TargetState     = VICTIMSTATE_HIT;

            // Crit bonus calc
            for (uint8 i = 0; i < MAX_ITEM_PROTO_DAMAGES; ++i)
            {
                damageInfo->Damages[i].Damage *= 2;

                float mod = 0.0f;
                // Apply SPELL_AURA_MOD_ATTACKER_RANGED_CRIT_DAMAGE or SPELL_AURA_MOD_ATTACKER_MELEE_CRIT_DAMAGE
                if (damageInfo->AttackType == RANGED_ATTACK)
                    mod += damageInfo->Target->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_RANGED_CRIT_DAMAGE);
                else
                    mod += damageInfo->Target->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_MELEE_CRIT_DAMAGE);

                // Increase crit damage from SPELL_AURA_MOD_CRIT_DAMAGE_BONUS
                mod += (GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_CRIT_DAMAGE_BONUS, damageInfo->Damages[i].DamageSchoolMask) - 1.0f) * 100;

                uint32 crTypeMask = damageInfo->Target->GetCreatureTypeMask();

                // Increase crit damage from SPELL_AURA_MOD_CRIT_PERCENT_VERSUS
                mod += GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_CRIT_PERCENT_VERSUS, crTypeMask);
                if (mod != 0)
                    AddPct(damageInfo->Damages[i].Damage, mod);
            }
            break;
        }
        case MELEE_HIT_PARRY:
            damageInfo->TargetState  = VICTIMSTATE_PARRY;
            damageInfo->CleanDamage = 0;

            for (uint8 i = 0; i < MAX_ITEM_PROTO_DAMAGES; ++i)
            {
                damageInfo->CleanDamage += damageInfo->Damages[i].Damage;
                damageInfo->Damages[i].Damage = 0;
            }
            break;
        case MELEE_HIT_DODGE:
            damageInfo->TargetState  = VICTIMSTATE_DODGE;
            damageInfo->CleanDamage = 0;

            for (uint8 i = 0; i < MAX_ITEM_PROTO_DAMAGES; ++i)
            {
                damageInfo->CleanDamage += damageInfo->Damages[i].Damage;
                damageInfo->Damages[i].Damage = 0;
            }
            break;
        case MELEE_HIT_BLOCK:
        {
            damageInfo->TargetState = VICTIMSTATE_HIT;
            damageInfo->HitInfo    |= HITINFO_BLOCK;
            damageInfo->Blocked     = damageInfo->Target->GetShieldBlockValue();
            // double blocked amount if block is critical
            if (damageInfo->Target->IsBlockCritical())
                damageInfo->Blocked *= 2;

            uint32 remainingBlock = damageInfo->Blocked;
            uint8  fullBlockMask = 0;
            for (uint8 i = 0; i < MAX_ITEM_PROTO_DAMAGES; ++i)
            {
                if (remainingBlock && remainingBlock >= damageInfo->Damages[i].Damage)
                {
                    fullBlockMask |= (1 << i);

                    remainingBlock               -= damageInfo->Damages[i].Damage;
                    damageInfo->CleanDamage      += damageInfo->Damages[i].Damage;
                    damageInfo->Damages[i].Damage = 0;
                }
                else
                {
                    damageInfo->CleanDamage       += remainingBlock;
                    damageInfo->Damages[i].Damage -= remainingBlock;
                    remainingBlock                 = 0;
                }
            }

            // full block
            if (fullBlockMask == ((1 << 0) | (1 << 1)))
            {
                damageInfo->TargetState = VICTIMSTATE_BLOCKS;
                damageInfo->Blocked    -= remainingBlock;
            }
            break;
        }
        case MELEE_HIT_GLANCING:
        {
            damageInfo->HitInfo     |= HITINFO_GLANCING;
            damageInfo->TargetState  = VICTIMSTATE_HIT;
            int32 leveldif = int32(victim->GetLevelForTarget(this)) - int32(GetLevel());
            if (leveldif < 0)
            {
                TC_LOG_DEBUG("entities.unit", "Unit::CalculateMeleeDamage: (Player) {} attacked {}. Glancing should never happen against lower level target", GetGUID().ToString(), victim->GetGUID().ToString());
                break;
            }
            if (leveldif == 0)
                leveldif = 1;
            if (leveldif > 3)
                leveldif = 3;

            // against boss-level targets - 24% chance of 25% average damage reduction (damage reduction range : 20-30%)
            // against level 82 elites - 18% chance of 15% average damage reduction (damage reduction range : 10-20%)
            int32 const reductionMax = leveldif * 10;
            int32 const reductionMin = std::max(1, reductionMax - 10);

            float reducePercent = 1.f - irand(reductionMin, reductionMax) / 100.0f;

            for (uint8 i = 0; i < MAX_ITEM_PROTO_DAMAGES; ++i)
            {
                uint32 reducedDamage = uint32(reducePercent * damageInfo->Damages[i].Damage);
                damageInfo->CleanDamage += damageInfo->Damages[i].Damage - reducedDamage;
                damageInfo->Damages[i].Damage = reducedDamage;
            }
            break;
        }
        case MELEE_HIT_CRUSHING:
            damageInfo->HitInfo     |= HITINFO_CRUSHING;
            damageInfo->TargetState  = VICTIMSTATE_HIT;

            // 150% normal damage
            for (uint8 i = 0; i < MAX_ITEM_PROTO_DAMAGES; ++i)
                damageInfo->Damages[i].Damage += (damageInfo->Damages[i].Damage / 2);
            break;
        default:
            break;
    }

    // Always apply HITINFO_AFFECTS_VICTIM in case its not a miss
    if (!(damageInfo->HitInfo & HITINFO_MISS))
        damageInfo->HitInfo |= HITINFO_AFFECTS_VICTIM;

    uint32 tmpHitInfo[MAX_ITEM_PROTO_DAMAGES] = { };

    for (uint8 i = 0; i < MAX_ITEM_PROTO_DAMAGES; ++i)
    {
        int32 resilienceReduction = damageInfo->Damages[i].Damage;
        // attackType is checked already for BASE_ATTACK or OFF_ATTACK so it can't be RANGED_ATTACK here
        if (CanApplyResilience())
            Unit::ApplyResilience(victim, nullptr, &resilienceReduction, (damageInfo->HitOutCome == MELEE_HIT_CRIT), CR_CRIT_TAKEN_MELEE);
        resilienceReduction = damageInfo->Damages[i].Damage - resilienceReduction;
        damageInfo->Damages[i].Damage -= resilienceReduction;
        damageInfo->CleanDamage += resilienceReduction;

        // Calculate absorb resist
        if (int32(damageInfo->Damages[i].Damage) > 0)
        {
            damageInfo->ProcVictim |= PROC_FLAG_TAKEN_DAMAGE;
            // Calculate absorb & resists
            DamageInfo dmgInfo(*damageInfo, i);
            Unit::CalcAbsorbResist(dmgInfo);
            damageInfo->Damages[i].Absorb = dmgInfo.GetAbsorb();
            damageInfo->Damages[i].Resist = dmgInfo.GetResist();

            if (damageInfo->Damages[i].Absorb)
                tmpHitInfo[i] |= (damageInfo->Damages[i].Damage - damageInfo->Damages[i].Absorb == 0 ? HITINFO_FULL_ABSORB : HITINFO_PARTIAL_ABSORB);

            if (damageInfo->Damages[i].Resist)
                tmpHitInfo[i] |= (damageInfo->Damages[i].Damage - damageInfo->Damages[i].Resist == 0 ? HITINFO_FULL_RESIST : HITINFO_PARTIAL_RESIST);

            damageInfo->CleanDamage += damageInfo->Damages[i].Damage - dmgInfo.GetDamage();
            damageInfo->Damages[i].Damage = dmgInfo.GetDamage();
        }
        else // Impossible get negative result but....
            damageInfo->Damages[i].Damage = 0;
    }

    // set proper HitInfo flags
    if ((tmpHitInfo[0] & HITINFO_FULL_ABSORB) != 0)
    {
        // set partial absorb when secondary damage isn't full absorbed
        damageInfo->HitInfo |= ((tmpHitInfo[1] & HITINFO_PARTIAL_ABSORB) != 0) ? HITINFO_PARTIAL_ABSORB : HITINFO_FULL_ABSORB;
    }
    else
        damageInfo->HitInfo |= (tmpHitInfo[0] & HITINFO_PARTIAL_ABSORB);

    if ((tmpHitInfo[0] & HITINFO_FULL_RESIST) != 0)
    {
        // set partial resist when secondary damage isn't full resisted
        damageInfo->HitInfo |= ((tmpHitInfo[1] & HITINFO_PARTIAL_RESIST) != 0) ? HITINFO_PARTIAL_RESIST : HITINFO_FULL_RESIST;
    }
    else
        damageInfo->HitInfo |= (tmpHitInfo[0] & HITINFO_PARTIAL_RESIST);
}

void Unit::DealMeleeDamage(CalcDamageInfo* damageInfo, bool durabilityLoss)
{
    Unit* victim = damageInfo->Target;

    auto canTakeMeleeDamage = [&]()
    {
        return victim->IsAlive() && !victim->HasUnitState(UNIT_STATE_IN_FLIGHT) && (victim->GetTypeId() != TYPEID_UNIT || !victim->ToCreature()->IsEvadingAttacks());
    };

    if (!canTakeMeleeDamage())
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
            float percent20 = victim->GetAttackTime(OFF_ATTACK) * 0.20f;
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
            float percent20 = victim->GetAttackTime(BASE_ATTACK) * 0.20f;
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

    for (uint8 i = 0; i < MAX_ITEM_PROTO_DAMAGES; ++i)
    {
        if (!canTakeMeleeDamage() || (!damageInfo->Damages[i].Damage && !damageInfo->Damages[i].Absorb && !damageInfo->Damages[i].Resist))
            continue;

        // Call default DealDamage
        CleanDamage cleanDamage(damageInfo->CleanDamage, damageInfo->Damages[i].Absorb, damageInfo->AttackType, damageInfo->HitOutCome);
        Unit::DealDamage(this, victim, damageInfo->Damages[i].Damage, &cleanDamage, DIRECT_DAMAGE, SpellSchoolMask(damageInfo->Damages[i].DamageSchoolMask), nullptr, durabilityLoss);
    }

    // If this is a creature and it attacks from behind it has a probability to daze it's victim
    if ((damageInfo->HitOutCome == MELEE_HIT_CRIT || damageInfo->HitOutCome == MELEE_HIT_CRUSHING || damageInfo->HitOutCome == MELEE_HIT_NORMAL || damageInfo->HitOutCome == MELEE_HIT_GLANCING) &&
        GetTypeId() != TYPEID_PLAYER && !ToCreature()->IsControlledByPlayer() && !victim->HasInArc(float(M_PI), this)
        && (victim->GetTypeId() == TYPEID_PLAYER || !victim->ToCreature()->isWorldBoss())&& !victim->IsVehicle())
    {
        // 20% base chance
        float chance = 20.0f;

        // there is a newbie protection, at level 10 just 7% base chance; assuming linear function
        if (victim->GetLevel() < 30)
            chance = 0.65f * victim->GetLevel() + 0.5f;

        uint32 const victimDefense = victim->GetDefenseSkillValue();
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
    if (damageInfo->Damages[0].Damage + damageInfo->Damages[1].Damage)
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
                victim->SendSpellDamageImmune(this, spellInfo->Id);
                continue;
            }

            uint32 damage = aurEff->GetAmount();
            if (Unit* caster = aurEff->GetCaster())
            {
                damage = caster->SpellDamageBonusDone(this, spellInfo, damage, SPELL_DIRECT_DAMAGE, aurEff->GetSpellEffectInfo(), { });
                damage = SpellDamageBonusTaken(caster, spellInfo, damage, SPELL_DIRECT_DAMAGE);
            }

            // No Unit::CalcAbsorbResist here - opcode doesn't send that data - this damage is probably not affected by that
            Unit::DealDamageMods(this, damage, nullptr);

            /// @todo Move this to a packet handler
            WorldPacket data(SMSG_SPELLDAMAGESHIELD, 8 + 8 + 4 + 4 + 4 + 4 + 4);
            data << uint64(victim->GetGUID());
            data << uint64(GetGUID());
            data << uint32(spellInfo->Id);
            data << uint32(damage);                  // Damage
            int32 const overkill = int32(damage) - int32(GetHealth());
            data << uint32(std::max(overkill, 0)); // Overkill
            data << uint32(spellInfo->SchoolMask);
            victim->SendMessageToSet(&data, true);

            Unit::DealDamage(victim, this, damage, nullptr, SPELL_DIRECT_DAMAGE, spellInfo->GetSchoolMask(), spellInfo, true);
        }
    }
}

void Unit::HandleEmoteCommand(Emote emoteId)
{
    WorldPackets::Chat::Emote packet;
    packet.EmoteID = emoteId;
    packet.Guid = GetGUID();
    SendMessageToSet(packet.Write(), true);
}

/*static*/ bool Unit::IsDamageReducedByArmor(SpellSchoolMask schoolMask, SpellInfo const* spellInfo /*= nullptr*/)
{
    // only physical spells damage gets reduced by armor
    if ((schoolMask & SPELL_SCHOOL_MASK_NORMAL) == 0)
        return false;

    return !spellInfo || !spellInfo->HasAttribute(SPELL_ATTR0_CU_IGNORE_ARMOR);
}

/*static*/ uint32 Unit::CalcArmorReducedDamage(Unit const* attacker, Unit* victim, uint32 damage, SpellInfo const* spellInfo, WeaponAttackType attackType /*= MAX_ATTACK*/, uint8 attackerLevel /*= 0*/)
{
    float armor = float(victim->GetArmor());

    // Ignore enemy armor by SPELL_AURA_MOD_TARGET_RESISTANCE aura
    if (attacker)
    {
        armor += attacker->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_TARGET_RESISTANCE, SPELL_SCHOOL_MASK_NORMAL);

        if (spellInfo)
            if (Player* modOwner = attacker->GetSpellModOwner())
                modOwner->ApplySpellMod(spellInfo->Id, SPELLMOD_IGNORE_ARMOR, armor);

        AuraEffectList const& resIgnoreAurasAb = attacker->GetAuraEffectsByType(SPELL_AURA_MOD_ABILITY_IGNORE_TARGET_RESIST);
        for (AuraEffect const* aurEff : resIgnoreAurasAb)
        {
            if (aurEff->GetMiscValue() & SPELL_SCHOOL_MASK_NORMAL && aurEff->IsAffectedOnSpell(spellInfo))
                armor = std::floor(AddPct(armor, -aurEff->GetAmount()));
        }

        AuraEffectList const& resIgnoreAuras = attacker->GetAuraEffectsByType(SPELL_AURA_MOD_IGNORE_TARGET_RESIST);
        for (AuraEffect const* aurEff : resIgnoreAuras)
        {
            if (aurEff->GetMiscValue() & SPELL_SCHOOL_MASK_NORMAL)
                armor = std::floor(AddPct(armor, -aurEff->GetAmount()));
        }

        // Apply Player CR_ARMOR_PENETRATION rating and buffs from stances\specializations etc.
        if (attacker->GetTypeId() == TYPEID_PLAYER)
        {
            float arpPct = attacker->ToPlayer()->GetRatingBonusValue(CR_ARMOR_PENETRATION);

            Item const* weapon = attacker->ToPlayer()->GetWeaponForAttack(attackType, true);
            arpPct += attacker->GetTotalAuraModifier(SPELL_AURA_MOD_ARMOR_PENETRATION_PCT, [weapon](AuraEffect const* aurEff) -> bool
            {
                return aurEff->GetSpellInfo()->IsItemFitToSpellRequirements(weapon);
            });

            // no more than 100%
            RoundToInterval(arpPct, 0.f, 100.f);

            float maxArmorPen = 0.f;
            if (victim->GetLevel() < 60)
                maxArmorPen = float(400 + 85 * victim->GetLevel());
            else
                maxArmorPen = 400 + 85 * victim->GetLevel() + 4.5f * 85 * (victim->GetLevel() - 59);

            // Cap armor penetration to this number
            maxArmorPen = std::min((armor + maxArmorPen) / 3.f, armor);
            // Figure out how much armor do we ignore
            armor -= CalculatePct(maxArmorPen, arpPct);
        }
    }

    if (armor < 0.0f)
        armor = 0.0f;

    float levelModifier = attacker ? attacker->GetLevel() : attackerLevel;
    if (levelModifier > 59.f)
        levelModifier = levelModifier + 4.5f * (levelModifier - 59.f);

    float damageReduction = 0.1f * armor / (8.5f * levelModifier + 40.f);
    damageReduction /= (1.0f + damageReduction);

    RoundToInterval(damageReduction, 0.f, 0.75f);
    return uint32(std::ceil(std::max(damage * (1.0f - damageReduction), 0.0f)));
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
        {
            ignoredResistance += attacker->GetTotalAuraModifier(SPELL_AURA_MOD_ABILITY_IGNORE_TARGET_RESIST, [schoolMask, spellInfo](AuraEffect const* aurEff) -> bool
            {
                if ((aurEff->GetMiscValue() & schoolMask) && aurEff->IsAffectedOnSpell(spellInfo))
                    return true;
                return false;
            });

            ignoredResistance += attacker->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_IGNORE_TARGET_RESIST, schoolMask);
        }

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

/*static*/ float Unit::CalculateAverageResistReduction(WorldObject const* caster, SpellSchoolMask schoolMask, Unit const* victim, SpellInfo const* spellInfo)
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
    if (spellInfo && spellInfo->SpellFamilyName == SPELLFAMILY_WARLOCK && spellInfo->SpellIconID == 3178)
        victimResistance = 0.0f;

    victimResistance = std::max(victimResistance, 0.0f);

    // level-based resistance does not apply to binary spells, and cannot be overcome by spell penetration
    // gameobject caster -- should it have level based resistance?
    if (caster && caster->GetTypeId() != TYPEID_GAMEOBJECT && (!spellInfo || !spellInfo->HasAttribute(SPELL_ATTR0_CU_BINARY_SPELL)))
        victimResistance += std::max((float(victim->GetLevelForTarget(caster)) - float(caster->GetLevelForTarget(victim))) * 5.0f, 0.0f);

    static uint32 const BOSS_LEVEL = 83;
    static float const BOSS_RESISTANCE_CONSTANT = 510.0f;
    uint32 level = victim->GetLevel();
    float resistanceConstant = 0.0f;

    if (level == BOSS_LEVEL)
        resistanceConstant = BOSS_RESISTANCE_CONSTANT;
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
    {
        auraAbsorbMod = attacker->GetMaxPositiveAuraModifierByMiscMask(SPELL_AURA_MOD_TARGET_ABSORB_SCHOOL, damageInfo.GetSchoolMask());
        auraAbsorbMod = std::max(auraAbsorbMod, static_cast<float>(attacker->GetMaxPositiveAuraModifier(SPELL_AURA_MOD_TARGET_ABILITY_ABSORB_SCHOOL, [&damageInfo](AuraEffect const* aurEff) -> bool
        {
            if (!(aurEff->GetMiscValue() & damageInfo.GetSchoolMask()))
                return false;

            if (!aurEff->IsAffectedOnSpell(damageInfo.GetSpellInfo()))
                return false;

            return true;
        })));
    }

    RoundToInterval(auraAbsorbMod, 0.0f, 100.0f);

    int32 absorbIgnoringDamage = CalculatePct(damageInfo.GetDamage(), auraAbsorbMod);

    if (spell)
        spell->CallScriptOnResistAbsorbCalculateHandlers(damageInfo, resistedDamage, absorbIgnoringDamage);

    damageInfo.ResistDamage(resistedDamage);
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

        if (defaultPrevented)
            continue;

        // absorb must be smaller than the damage itself
        currentAbsorb = RoundToInterval(currentAbsorb, 0, int32(damageInfo.GetDamage()));

        damageInfo.AbsorbDamage(currentAbsorb);

        tempAbsorb = currentAbsorb;
        absorbAurEff->GetBase()->CallScriptEffectAfterAbsorbHandlers(absorbAurEff, aurApp, damageInfo, tempAbsorb);

        // Check if our aura is using amount to count damage
        if (absorbAurEff->GetAmount() >= 0)
        {
            // Reduce shield amount
            absorbAurEff->SetAmount(absorbAurEff->GetAmount() - currentAbsorb);
            // Aura cannot absorb anything more - remove it
            if (absorbAurEff->GetAmount() <= 0)
                absorbAurEff->GetBase()->Remove(AURA_REMOVE_BY_ENEMY_SPELL);
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

        if (defaultPrevented)
            continue;

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
            absorbAurEff->SetAmount(absorbAurEff->GetAmount() - currentAbsorb);
            if ((absorbAurEff->GetAmount() <= 0))
                absorbAurEff->GetBase()->Remove(AURA_REMOVE_BY_ENEMY_SPELL);
        }
    }

    damageInfo.ModifyDamage(absorbIgnoringDamage);

    // split damage auras - only when not damaging self
    if (damageInfo.GetVictim() != damageInfo.GetAttacker())
    {
        // We're going to call functions which can modify content of the list during iteration over it's elements
        // Let's copy the list so we can prevent iterator invalidation
        AuraEffectList vSplitDamageFlatCopy(damageInfo.GetVictim()->GetAuraEffectsByType(SPELL_AURA_SPLIT_DAMAGE_FLAT));
        for (AuraEffectList::iterator itr = vSplitDamageFlatCopy.begin(); (itr != vSplitDamageFlatCopy.end()) && (damageInfo.GetDamage() > 0); ++itr)
        {
            // Check if aura was removed during iteration - we don't need to work on such auras
            if (!((*itr)->GetBase()->IsAppliedOnTarget(damageInfo.GetVictim()->GetGUID())))
                continue;
            // check damage school mask
            if (!((*itr)->GetMiscValue() & damageInfo.GetSchoolMask()))
                continue;

            // Damage can be splitted only if aura has an alive caster
            Unit* caster = (*itr)->GetCaster();
            if (!caster || (caster == damageInfo.GetVictim()) || !caster->IsInWorld() || !caster->IsAlive())
                continue;

            int32 splitDamage = (*itr)->GetAmount();

            // absorb must be smaller than the damage itself
            splitDamage = RoundToInterval(splitDamage, 0, int32(damageInfo.GetDamage()));

            damageInfo.AbsorbDamage(splitDamage);

            // check if caster is immune to damage
            if (caster->IsImmunedToDamage(damageInfo.GetSchoolMask()))
            {
                damageInfo.GetVictim()->SendSpellMiss(caster, (*itr)->GetSpellInfo()->Id, SPELL_MISS_IMMUNE);
                continue;
            }

            uint32 splitted = splitDamage;
            uint32 splitted_absorb = 0;
            Unit::DealDamageMods(caster, splitted, &splitted_absorb);

            if (Unit* attacker = damageInfo.GetAttacker())
                attacker->SendSpellNonMeleeDamageLog(caster, (*itr)->GetSpellInfo()->Id, splitted, damageInfo.GetSchoolMask(), splitted_absorb, 0, damageInfo.GetDamageType() == DOT, 0, false, true);

            CleanDamage cleanDamage = CleanDamage(splitted, 0, BASE_ATTACK, MELEE_HIT_NORMAL);
            Unit::DealDamage(damageInfo.GetAttacker(), caster, splitted, &cleanDamage, DIRECT_DAMAGE, damageInfo.GetSchoolMask(), (*itr)->GetSpellInfo(), false);
        }

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
            Unit::DealDamageMods(caster, splitDamage, &split_absorb);

            if (Unit* attacker = damageInfo.GetAttacker())
                attacker->SendSpellNonMeleeDamageLog(caster, (*itr)->GetSpellInfo()->Id, splitDamage, damageInfo.GetSchoolMask(), split_absorb, 0, damageInfo.GetDamageType() == DOT, 0, false, true);

            CleanDamage cleanDamage = CleanDamage(splitDamage, 0, BASE_ATTACK, MELEE_HIT_NORMAL);
            Unit::DealDamage(damageInfo.GetAttacker(), caster, splitDamage, &cleanDamage, DIRECT_DAMAGE, damageInfo.GetSchoolMask(), (*itr)->GetSpellInfo(), false);

            // break 'Fear' and similar auras
            Unit::ProcSkillsAndAuras(damageInfo.GetAttacker(), caster, PROC_FLAG_NONE, PROC_FLAG_TAKEN_SPELL_MAGIC_DMG_CLASS_NEG, PROC_SPELL_TYPE_DAMAGE, PROC_SPELL_PHASE_HIT, PROC_HIT_NONE, nullptr, &damageInfo, nullptr);
        }
    }
}

/*static*/ void Unit::CalcHealAbsorb(HealInfo& healInfo)
{
    if (!healInfo.GetHeal())
        return;

    int32 const healing = static_cast<int32>(healInfo.GetHeal());
    int32 absorbAmount = 0;

    // Need remove expired auras after
    bool existExpired = false;

    // absorb without mana cost
    AuraEffectList const& vHealAbsorb = healInfo.GetTarget()->GetAuraEffectsByType(SPELL_AURA_SCHOOL_HEAL_ABSORB);
    for (AuraEffectList::const_iterator i = vHealAbsorb.begin(); i != vHealAbsorb.end() && absorbAmount <= healing; ++i)
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
        if (healing < currentAbsorb + absorbAmount)
            currentAbsorb = healing - absorbAmount;

        absorbAmount += currentAbsorb;

        // Reduce shield amount
        (*i)->SetAmount((*i)->GetAmount() - currentAbsorb);
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

    if (absorbAmount > 0)
        healInfo.AbsorbHeal(absorbAmount);
}

void Unit::AttackerStateUpdate(Unit* victim, WeaponAttackType attType, bool extra)
{
    if (HasUnitFlag(UNIT_FLAG_PACIFIED))
        return;

    if (HasUnitState(UNIT_STATE_CANNOT_AUTOATTACK) && !extra)
        return;

    if (!victim->IsAlive())
        return;

    if ((attType == BASE_ATTACK || attType == OFF_ATTACK) && !IsWithinLOSInMap(victim))
        return;

    AtTargetAttacked(victim, true);
    RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_MELEE_ATTACK);

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

        CalcDamageInfo damageInfo;
        CalculateMeleeDamage(victim, &damageInfo, attType);
        // Send log damage message to client

        for (uint8 i = 0; i < MAX_ITEM_PROTO_DAMAGES; ++i)
            Unit::DealDamageMods(victim, damageInfo.Damages[i].Damage, &damageInfo.Damages[i].Absorb);
        SendAttackStateUpdate(&damageInfo);

        _lastDamagedTargetGuid = victim->GetGUID();

        DealMeleeDamage(&damageInfo, true);

        DamageInfo dmgInfo(damageInfo);
        Unit::ProcSkillsAndAuras(damageInfo.Attacker, damageInfo.Target, damageInfo.ProcAttacker, damageInfo.ProcVictim, PROC_SPELL_TYPE_NONE, PROC_SPELL_PHASE_NONE, dmgInfo.GetHitMask(), nullptr, &dmgInfo, nullptr);

        if (GetTypeId() == TYPEID_PLAYER)
            TC_LOG_DEBUG("entities.unit", "AttackerStateUpdate: (Player) {} attacked {} for {} dmg, absorbed {}, blocked {}, resisted {}.",
                GetGUID().ToString(), victim->GetGUID().ToString(), dmgInfo.GetDamage(), dmgInfo.GetAbsorb(), dmgInfo.GetBlock(), dmgInfo.GetResist());
        else
            TC_LOG_DEBUG("entities.unit", "AttackerStateUpdate: (NPC)    {} attacked {} for {} dmg, absorbed {}, blocked {}, resisted {}.",
                GetGUID().ToString(), victim->GetGUID().ToString(), dmgInfo.GetDamage(), dmgInfo.GetAbsorb(), dmgInfo.GetBlock(), dmgInfo.GetResist());
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
        if (ObjectGuid selection = GetTarget())
            targetGUID = selection; // Spell was cast directly (not triggered by aura)
        else
            return;
    }

    extraAttacksTargets[targetGUID] += count;
}

MeleeHitOutcome Unit::RollMeleeOutcomeAgainst(Unit const* victim, WeaponAttackType attType) const
{
    if (victim->GetTypeId() == TYPEID_UNIT && victim->ToCreature()->IsInEvadeMode())
        return MELEE_HIT_EVADE;

    int32 const attackerMaxSkillValueForLevel = GetMaxSkillValueForLevel(victim);
    int32 const victimMaxSkillValueForLevel = victim->GetMaxSkillValueForLevel(this);

    int32 const attackerWeaponSkill = GetWeaponSkillValue(attType, victim);
    int32 const victimDefenseSkill = victim->GetDefenseSkillValue(this);

    // Miss chance based on melee
    int32 miss_chance = int32(MeleeSpellMissChance(victim, attType, attackerWeaponSkill - victimMaxSkillValueForLevel, 0) * 100.0f);

    // Critical hit chance
    int32 crit_chance = int32(GetUnitCriticalChanceAgainst(attType, victim) * 100.0f);

    int32 dodge_chance = int32(GetUnitDodgeChance(attType, victim) * 100.0f);
    int32 block_chance = int32(GetUnitBlockChance(attType, victim) * 100.0f);
    int32 parry_chance = int32(GetUnitParryChance(attType, victim) * 100.0f);

    // melee attack table implementation
    // outcome priority:
    //   1. >    2. >    3. >       4. >    5. >   6. >       7. >  8.
    // MISS > DODGE > PARRY > GLANCING > BLOCK > CRIT > CRUSHING > HIT

    int32    sum = 0, tmp = 0;
    int32    roll = urand(0, 9999);

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
    // Max 40% chance to score a glancing blow against mobs of the same or higher level (only players and pets, not for ranged weapons).
    if ((GetTypeId() == TYPEID_PLAYER || IsPet()) &&
        victim->GetTypeId() != TYPEID_PLAYER && !victim->IsPet() &&
        GetLevel() <= victim->GetLevelForTarget(this))
    {
        // cap possible value (with bonuses > max skill)
        int32 skill = attackerWeaponSkill;
        int32 maxskill = attackerMaxSkillValueForLevel;
        skill = (skill > maxskill) ? maxskill : skill;

        // against boss-level targets - 24% chance of 25% average damage reduction (damage reduction range : 20-30%)
        // against level 82 elites - 18% chance of 15% average damage reduction (damage reduction range : 10-20%)
        tmp = 600 + (victimDefenseSkill - skill) * 120;
        tmp = std::min(tmp, 4000);
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
    if (GetLevelForTarget(victim) >= victim->GetLevelForTarget(this) + 4 &&
        // can be from by creature (if can) or from controlled player that considered as creature
        !IsControlledByPlayer() &&
        !(GetTypeId() == TYPEID_UNIT && ToCreature()->GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_NO_CRUSHING_BLOWS))
    {
        // when their weapon skill is 15 or more above victim's defense skill
        tmp = victimDefenseSkill;
        // having defense above your maximum (from items, talents etc.) has no effect
        tmp = std::min(tmp, victimMaxSkillValueForLevel);
        // tmp = mob's level * 5 - player's current defense skill
        tmp = attackerMaxSkillValueForLevel - tmp;
        // minimum of 20 points diff (4 levels difference)
        tmp = std::max(tmp, 20);

        // add 2% chance per lacking skill point
        tmp = tmp * 200 - 1500;
        if (tmp > 0 && roll < (sum += tmp))
            return MELEE_HIT_CRUSHING;
    }

    // 8. HIT
    return MELEE_HIT_NORMAL;
}

uint32 Unit::CalculateDamage(WeaponAttackType attType, bool normalized, bool addTotalPct, uint8 itemDamagesMask /*= 0*/) const
{
    float minDamage = 0.0f;
    float maxDamage = 0.0f;

    if (normalized || !addTotalPct || itemDamagesMask)
    {
        // get both by default
        if (!itemDamagesMask)
            itemDamagesMask = (1 << 0) | (1 << 1);

        for (uint8 i = 0; i < MAX_ITEM_PROTO_DAMAGES; ++i)
        {
            if (itemDamagesMask & (1 << i))
            {
                float minTmp, maxTmp;
                CalculateMinMaxDamage(attType, normalized, addTotalPct, minTmp, maxTmp, i);
                minDamage += minTmp;
                maxDamage += maxTmp;
            }
        }
    }
    else
    {
        switch (attType)
        {
            case RANGED_ATTACK:
                minDamage = GetFloatValue(UNIT_FIELD_MINRANGEDDAMAGE);
                maxDamage = GetFloatValue(UNIT_FIELD_MAXRANGEDDAMAGE);
                break;
            case BASE_ATTACK:
                minDamage = GetFloatValue(UNIT_FIELD_MINDAMAGE);
                maxDamage = GetFloatValue(UNIT_FIELD_MAXDAMAGE);
                break;
            case OFF_ATTACK:
                minDamage = GetFloatValue(UNIT_FIELD_MINOFFHANDDAMAGE);
                maxDamage = GetFloatValue(UNIT_FIELD_MAXOFFHANDDAMAGE);
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

float Unit::CalculateSpellpowerCoefficientLevelPenalty(SpellInfo const* spellInfo) const
{
    if (!spellInfo->MaxLevel || GetLevel() < spellInfo->MaxLevel)
        return 1.0f;

    return std::max(0.0f, std::min(1.0f, (22.0f + spellInfo->MaxLevel - GetLevel()) / 20.0f));
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
    WeaponAttackType attType = BASE_ATTACK;

    // Check damage class instead of attack type to correctly handle judgements
    // - they are meele, but can't be dodged/parried/deflected because of ranged dmg class
    if (spellInfo->DmgClass == SPELL_DAMAGE_CLASS_RANGED)
        attType = RANGED_ATTACK;

    int32 attackerWeaponSkill;
    // skill value for these spells (for example judgements) is 5 * level
    if (spellInfo->DmgClass == SPELL_DAMAGE_CLASS_RANGED && !spellInfo->IsRangedWeaponSpell())
        attackerWeaponSkill = GetMaxSkillValueForLevel();
    else
        attackerWeaponSkill = int32(GetWeaponSkillValue(attType, victim));

    int32 skillDiff = attackerWeaponSkill - int32(victim->GetMaxSkillValueForLevel(this));

    uint32 roll = urand(0, 9999);

    uint32 missChance = uint32(MeleeSpellMissChance(victim, attType, skillDiff, spellInfo->Id) * 100.0f);
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

    bool canDodge = !spellInfo->HasAttribute(SPELL_ATTR7_CANT_DODGE);
    bool canParry = !spellInfo->HasAttribute(SPELL_ATTR7_CANT_PARRY);
    bool canBlock = true; // all melee and ranged attacks can be blocked

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
        if (!aurEff->IsAffectedOnSpell(spellInfo))
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

uint32 Unit::GetShieldBlockValue(uint32 soft_cap, uint32 hard_cap) const
{
    uint32 value = GetShieldBlockValue();
    if (value >= hard_cap)
    {
        value = (soft_cap + hard_cap) / 2;
    }
    else if (value > soft_cap)
    {
        value = soft_cap + ((value - soft_cap) / 2);
    }

    return value;
}

uint32 Unit::GetDefenseSkillValue(Unit const* target) const
{
    if (GetTypeId() == TYPEID_PLAYER)
    {
        // in PvP use full skill instead current skill value
        uint32 value = (target && target->GetTypeId() == TYPEID_PLAYER)
            ? ToPlayer()->GetMaxSkillValue(SKILL_DEFENSE)
            : ToPlayer()->GetSkillValue(SKILL_DEFENSE);
        value += uint32(ToPlayer()->GetRatingBonusValue(CR_DEFENSE_SKILL));
        return value;
    }
    else
        return GetMaxSkillValueForLevel(target);
}

float Unit::GetUnitDodgeChance(WeaponAttackType attType, Unit const* victim) const
{
    int32 const attackerWeaponSkill = GetWeaponSkillValue(attType, victim);
    int32 const victimMaxSkillValueForLevel = victim->GetMaxSkillValueForLevel(this);
    int32 const skillDiff = victimMaxSkillValueForLevel - attackerWeaponSkill;

    float chance = 0.0f;
    float skillBonus = 0.0f;
    if (victim->GetTypeId() == TYPEID_PLAYER)
    {
        chance = victim->GetFloatValue(PLAYER_DODGE_PERCENTAGE);
        skillBonus = 0.04f * skillDiff;
    }
    else
    {
        if (!victim->IsTotem())
        {
            chance = 5.0f;
            chance += victim->GetTotalAuraModifier(SPELL_AURA_MOD_DODGE_PERCENT);

            if (skillDiff <= 10)
                skillBonus = skillDiff * 0.1f;
            else
                skillBonus = 1.0f + (skillDiff - 10) * 0.1f;
        }
    }

    chance += skillBonus;

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
    int32 const attackerWeaponSkill = GetWeaponSkillValue(attType, victim);
    int32 const victimMaxSkillValueForLevel = victim->GetMaxSkillValueForLevel(this);
    int32 const skillDiff = victimMaxSkillValueForLevel - attackerWeaponSkill;

    float chance = 0.0f;
    float skillBonus = 0.0f;
    if (Player const* playerVictim = victim->ToPlayer())
    {
        if (playerVictim->CanParry())
        {
            Item* tmpitem = playerVictim->GetWeaponForAttack(BASE_ATTACK, true);
            if (!tmpitem)
                tmpitem = playerVictim->GetWeaponForAttack(OFF_ATTACK, true);

            if (tmpitem)
                chance = playerVictim->GetFloatValue(PLAYER_PARRY_PERCENTAGE);

            skillBonus = 0.04f * skillDiff;
        }
    }
    else
    {
        if (!victim->IsTotem() && !(victim->ToCreature()->GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_NO_PARRY))
        {
            chance = 5.0f;
            chance += victim->GetTotalAuraModifier(SPELL_AURA_MOD_PARRY_PERCENT);

            if (skillDiff <= 10)
                skillBonus = skillDiff * 0.1f;
            else
                skillBonus = 1.0f + (skillDiff - 10) * 1.6f;
        }
    }

    chance += skillBonus;

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

    if (Player const* player = ToPlayer())
        miss_chance += player->GetMissPercentageFromDefense();

    return miss_chance;
}

float Unit::GetUnitBlockChance(WeaponAttackType attType, Unit const* victim) const
{
    int32 const attackerWeaponSkill = GetWeaponSkillValue(attType, victim);
    int32 const victimMaxSkillValueForLevel = victim->GetMaxSkillValueForLevel(this);
    int32 const skillDiff = victimMaxSkillValueForLevel - attackerWeaponSkill;

    float chance = 0.0f;
    float skillBonus = 0.0f;
    if (Player const* playerVictim = victim->ToPlayer())
    {
        if (playerVictim->CanBlock())
        {
            Item* tmpitem = playerVictim->GetUseableItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
            if (tmpitem && !tmpitem->IsBroken() && tmpitem->GetTemplate()->Block)
            {
                chance = playerVictim->GetFloatValue(PLAYER_BLOCK_PERCENTAGE);
                skillBonus = 0.04f * skillDiff;
            }
        }
    }
    else
    {
        if (!victim->IsTotem() && !(victim->ToCreature()->GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_NO_BLOCK))
        {
            chance = 5.0f;
            chance += victim->GetTotalAuraModifier(SPELL_AURA_MOD_BLOCK_PERCENT);

            if (skillDiff <= 10)
                skillBonus = skillDiff * 0.1f;
            else
                skillBonus = 1.0f + (skillDiff - 10) * 0.1f;
        }
    }

    chance += skillBonus;
    return std::max(chance, 0.0f);
}

float Unit::GetUnitCriticalChanceDone(WeaponAttackType attackType) const
{
    float chance = 0.f;
    if (GetTypeId() == TYPEID_PLAYER)
    {
        switch (attackType)
        {
            case BASE_ATTACK:
                chance = GetFloatValue(PLAYER_CRIT_PERCENTAGE);
                break;
            case OFF_ATTACK:
                chance = GetFloatValue(PLAYER_OFFHAND_CRIT_PERCENTAGE);
                break;
            case RANGED_ATTACK:
                chance = GetFloatValue(PLAYER_RANGED_CRIT_PERCENTAGE);
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
    int32 const attackerWeaponSkill = attacker->GetWeaponSkillValue(attackType, this);
    int32 const victimDefenseSkill = GetDefenseSkillValue(attacker);
    int32 const skillDiff = victimDefenseSkill - attackerWeaponSkill;

    float skillBonus = 0.0f;
    float chance = critDone;

    // flat aura mods
    if (attackType == RANGED_ATTACK)
        chance += GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_RANGED_CRIT_CHANCE);
    else
        chance += GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_MELEE_CRIT_CHANCE);

    // reduce crit chance from Rating for players
    if (attacker->CanApplyResilience())
        Unit::ApplyResilience(this, &chance, nullptr, false, (attackType == RANGED_ATTACK ? CR_CRIT_TAKEN_RANGED : CR_CRIT_TAKEN_MELEE));

    // applied after resilience
    chance += GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_SPELL_AND_WEAPON_CRIT_CHANCE);

    // Apply crit chance from defense skill
    if (GetTypeId() == TYPEID_PLAYER)
        skillBonus = -skillDiff * 0.04f;
    else
    {
        skillBonus = -skillDiff * 0.12f;
        if (skillDiff >= 15)
            skillBonus -= 3.0f;
    }

    chance += skillBonus;
    return std::max(chance, 0.f);
}

float Unit::GetUnitCriticalChanceAgainst(WeaponAttackType attackType, Unit const* victim) const
{
    float chance = GetUnitCriticalChanceDone(attackType);
    return victim->GetUnitCriticalChanceTaken(this, attackType, chance);
}

uint32 Unit::GetWeaponSkillValue(WeaponAttackType attType, Unit const* target) const
{
    uint32 value = 0;
    if (Player const* player = ToPlayer())
    {
        Item* item = player->GetWeaponForAttack(attType, true);

        // feral or unarmed skill only for base attack
        if (attType != BASE_ATTACK && !item)
            return 0;

        if (IsInFeralForm())
            return GetMaxSkillValueForLevel();              // always maximized SKILL_FERAL_COMBAT in fact

        // weapon skill or (unarmed for base attack)
        uint32 skill = SKILL_UNARMED;
        if (item)
            skill = item->GetSkill();

        // in PvP use full skill instead current skill value
        value = (target && target->IsControlledByPlayer())
            ? player->GetMaxSkillValue(skill)
            : player->GetSkillValue(skill);
        // Modify value from ratings
        value += uint32(player->GetRatingBonusValue(CR_WEAPON_SKILL));
        switch (attType)
        {
            case BASE_ATTACK:
                value += uint32(player->GetRatingBonusValue(CR_WEAPON_SKILL_MAINHAND));
                break;
            case OFF_ATTACK:
                value += uint32(player->GetRatingBonusValue(CR_WEAPON_SKILL_OFFHAND));
                break;
            case RANGED_ATTACK:
                value += uint32(player->GetRatingBonusValue(CR_WEAPON_SKILL_RANGED));
                break;
            default:
                break;
        }
    }
    else
        value = GetMaxSkillValueForLevel(target);
    return value;
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
        else if (i->second->GetSpellInfo()->IsChanneled() && i->second->GetCasterGUID() != GetGUID() && !ObjectAccessor::GetWorldObject(*this, i->second->GetCasterGUID()))
            RemoveOwnedAura(i, AURA_REMOVE_BY_CANCEL); // remove channeled auras when caster is not on the same map
        else
            ++i;
    }

    for (VisibleAuraMap::iterator itr = m_visibleAuras.begin(); itr != m_visibleAuras.end(); ++itr)
        if (itr->second->IsNeedClientUpdate())
            itr->second->ClientUpdate();

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
    if ((GetTypeId() == TYPEID_PLAYER && ToPlayer()->isMoving()) || IsNonMeleeSpellCast(false, false, true, autoRepeatSpellInfo->Id == 75))
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
                Spell::SendCastResult(ToPlayer(), autoRepeatSpellInfo, 1, result);

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

void Unit::InterruptSpell(CurrentSpellTypes spellType, bool withDelayed, bool withInstant, SpellCastResult result, Optional<SpellCastResult> resultOther /*= {}*/)
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
            spell->cancel(result, resultOther);
        else
        {
            m_currentSpells[spellType] = nullptr;
            spell->SetReferencedFromCurrent(false);
        }

        if (GetTypeId() == TYPEID_UNIT && IsAIEnabled())
            ToCreature()->AI()->OnSpellFailed(spell->GetSpellInfo());
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

    if (Spell* spell = m_currentSpells[CURRENT_GENERIC_SPELL])
        if (spell->getState() == SPELL_STATE_FINISHED ||
            !(spell->m_spellInfo->InterruptFlags & SPELL_INTERRUPT_FLAG_MOVEMENT))
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
        return c->CanEnterWater();
    else
        return c->CanWalk() || c->CanFly();
}

bool Unit::IsInWater() const
{
    return GetLiquidStatus() & (LIQUID_MAP_IN_WATER | LIQUID_MAP_UNDER_WATER);
}

bool Unit::IsUnderWater() const
{
    return GetLiquidStatus() & LIQUID_MAP_UNDER_WATER;
}

void Unit::ProcessPositionDataChanged(PositionFullTerrainStatus const& data)
{
    ZLiquidStatus oldLiquidStatus = GetLiquidStatus();
    WorldObject::ProcessPositionDataChanged(data);
    ProcessTerrainStatusUpdate(oldLiquidStatus, data.liquidInfo);
}

void Unit::ProcessTerrainStatusUpdate(ZLiquidStatus /*oldLiquidStatus*/, Optional<LiquidData> const& newLiquidData)
{
    if (!IsControlledByPlayer())
        return;

    // remove appropriate auras if we are swimming/not swimming respectively
    if (IsInWater())
        RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_NOT_ABOVEWATER);
    else
        RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_NOT_UNDERWATER);

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
}

void Unit::DeMorph()
{
    SetDisplayId(GetNativeDisplayId());
}

Aura* Unit::_TryStackingOrRefreshingExistingAura(AuraCreateInfo& createInfo)
{
    ASSERT(createInfo.CasterGUID || createInfo.Caster);

    // Check if these can stack anyway
    if (!createInfo.CasterGUID && !createInfo.GetSpellInfo()->IsStackableOnOneSlotWithDifferentCasters())
        createInfo.CasterGUID = createInfo.Caster->GetGUID();

    // world gameobjects can't own auras and they send empty casterguid
    // checked on sniffs with spell 22247
    if (createInfo.CasterGUID.IsGameObject())
    {
        createInfo.Caster = nullptr;
        createInfo.CasterGUID.Clear();
    }

    // passive and Incanter's Absorption and auras with different type can stack with themselves any number of times
    if (!createInfo.GetSpellInfo()->IsMultiSlotAura())
    {
        // check if cast item changed
        ObjectGuid castItemGUID = createInfo.CastItemGUID;

        // find current aura from spell and change it's stackamount, or refresh it's duration
        if (Aura* foundAura = GetOwnedAura(createInfo.GetSpellInfo()->Id, createInfo.GetSpellInfo()->IsStackableOnOneSlotWithDifferentCasters() ? ObjectGuid::Empty : createInfo.CasterGUID, createInfo.GetSpellInfo()->HasAttribute(SPELL_ATTR0_CU_ENCHANT_PROC) ? castItemGUID : ObjectGuid::Empty))
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

                int32 bp = spellEffectInfo.BasePoints;
                if (createInfo.BaseAmount)
                    bp = *(createInfo.BaseAmount + spellEffectInfo.EffectIndex);

                int32* oldBP = const_cast<int32*>(&(auraEff->m_baseAmount));
                *oldBP = bp;
            }

            // correct cast item guid if needed
            if (castItemGUID != foundAura->GetCastItemGUID())
            {
                ObjectGuid* oldGUID = const_cast<ObjectGuid*>(&foundAura->m_castItemGuid);
                *oldGUID = castItemGUID;
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
AuraApplication* Unit::_CreateAuraApplication(Aura* aura, uint8 effMask)
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

    if (aurSpellInfo->AuraInterruptFlags)
    {
        m_interruptableAuras.push_back(aurApp);
        AddInterruptMask(aurSpellInfo->AuraInterruptFlags);
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
void Unit::_ApplyAura(AuraApplication* aurApp, uint8 effMask)
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
        if ((aStateMask & PER_CASTER_AURA_STATE_MASK) && HasFlag(UNIT_FIELD_AURASTATE, aStateMask))
            ForceValuesUpdateAtIndex(UNIT_FIELD_AURASTATE);
        else
            ModifyAuraState(aState, true);
    }

    if (aurApp->GetRemoveMode())
        return;

    // Sitdown on apply aura req seated
    if (aura->GetSpellInfo()->AuraInterruptFlags & AURA_INTERRUPT_FLAG_NOT_SEATED && GetStandState() == UNIT_STAND_STATE_STAND)
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
        if (sConditionMgr->IsSpellUsedInSpellClickConditions(aurApp->GetBase()->GetId()))
            player->UpdateVisibleGameobjectsOrSpellClicks();
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

    if (aura->GetSpellInfo()->AuraInterruptFlags)
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
                ForceValuesUpdateAtIndex(UNIT_FIELD_AURASTATE);
        }
    }

    aura->HandleAuraSpecificMods(aurApp, caster, false, false);

    if (Player* player = ToPlayer())
        if (sConditionMgr->IsSpellUsedInSpellClickConditions(aurApp->GetBase()->GetId()))
            player->UpdateVisibleGameobjectsOrSpellClicks();

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
        m_modAuras[aurEff->GetAuraType()].push_back(aurEff);
    else
        m_modAuras[aurEff->GetAuraType()].remove(aurEff);
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
    m_removedAuras.push_back(aura);

    // Unregister single target aura
    if (aura->IsSingleTarget())
        aura->UnregisterSingleTarget();

    aura->_Remove(removeMode);

    i = m_ownedAuras.begin();
}

void Unit::RemoveOwnedAura(uint32 spellId, ObjectGuid casterGUID, uint8 reqEffMask, AuraRemoveMode removeMode)
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

Aura* Unit::GetOwnedAura(uint32 spellId, ObjectGuid casterGUID, ObjectGuid itemCasterGUID, uint8 reqEffMask, Aura* except) const
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

void Unit::RemoveAura(uint32 spellId, ObjectGuid caster, uint8 reqEffMask, AuraRemoveMode removeMode)
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

void Unit::RemoveAurasDueToSpell(uint32 spellId, ObjectGuid casterGUID, uint8 reqEffMask, AuraRemoveMode removeMode)
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

void Unit::RemoveAuraFromStack(uint32 spellId, ObjectGuid casterGUID, AuraRemoveMode removeMode)
{
    AuraMapBoundsNonConst range = m_ownedAuras.equal_range(spellId);
    for (AuraMap::iterator iter = range.first; iter != range.second;)
    {
        Aura* aura = iter->second;
        if ((aura->GetType() == UNIT_AURA_TYPE)
                && (!casterGUID || aura->GetCasterGUID() == casterGUID))
        {
            aura->ModStackAmount(-1, removeMode);
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

void Unit::RemoveAurasDueToSpellBySteal(uint32 spellId, ObjectGuid casterGUID, WorldObject* stealer)
{
    AuraMapBoundsNonConst range = m_ownedAuras.equal_range(spellId);
    for (AuraMap::iterator iter = range.first; iter != range.second;)
    {
        Aura* aura = iter->second;
        if (aura->GetCasterGUID() == casterGUID)
        {
            int32 damage[MAX_SPELL_EFFECTS];
            int32 baseDamage[MAX_SPELL_EFFECTS];
            uint8 effMask = 0;
            uint8 recalculateMask = 0;
            Unit* caster = aura->GetCaster();
            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
            {
                if (aura->GetEffect(i))
                {
                    baseDamage[i] = aura->GetEffect(i)->GetBaseAmount();
                    damage[i] = aura->GetEffect(i)->GetAmount();
                    effMask |= (1<<i);
                    if (aura->GetEffect(i)->CanBeRecalculated())
                        recalculateMask |= (1<<i);
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

            if (Unit* unitStealer = stealer->ToUnit())
            {
                if (Aura* oldAura = unitStealer->GetAura(aura->GetId(), aura->GetCasterGUID()))
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

                    AuraCreateInfo createInfo(aura->GetSpellInfo(), effMask, unitStealer);
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
                            caster->GetSingleCastAuras().push_back(aura);
                        }
                        // FIXME: using aura->GetMaxDuration() maybe not blizzlike but it fixes stealing of spells like Innervate
                        newAura->SetLoadedState(aura->GetMaxDuration(), int32(dur), stealCharge ? 1 : aura->GetCharges(), 1, recalculateMask, aura->GetCritChance(), aura->CanApplyResilience(), &damage[0]);
                        newAura->ApplyForTargets();
                    }
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

void Unit::RemoveNotOwnSingleTargetAuras(uint32 newPhase)
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
            if (!newPhase)
                RemoveOwnedAura(iter);
            else
            {
                Unit* caster = aura->GetCaster();
                if (!caster || !caster->InSamePhase(newPhase))
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
        if (aura->GetUnitOwner() != this && !aura->GetUnitOwner()->InSamePhase(newPhase))
        {
            aura->Remove();
            iter = scAuras.begin();
        }
        else
            ++iter;
    }
}

void Unit::RemoveAurasWithInterruptFlags(uint32 flag, uint32 except)
{
    if (!(m_interruptMask & flag))
        return;

    // interrupt auras
    for (AuraApplicationList::iterator iter = m_interruptableAuras.begin(); iter != m_interruptableAuras.end();)
    {
        Aura* aura = (*iter)->GetBase();
        ++iter;
        if ((aura->GetSpellInfo()->AuraInterruptFlags & flag) && (!except || aura->GetId() != except))
        {
            uint32 removedAuras = m_removedAurasCount;
            RemoveAura(aura);
            if (m_removedAurasCount > removedAuras + 1)
                iter = m_interruptableAuras.begin();
        }
    }

    // interrupt channeled spell
    if (Spell* spell = m_currentSpells[CURRENT_CHANNELED_SPELL])
        if (spell->getState() == SPELL_STATE_CASTING
            && (spell->m_spellInfo->ChannelInterruptFlags & flag)
            && spell->m_spellInfo->Id != except)
            InterruptNonMeleeSpells(false);

    UpdateInterruptMask();
}

void Unit::RemoveAurasWithFamily(SpellFamilyNames family, uint32 familyFlag1, uint32 familyFlag2, uint32 familyFlag3, ObjectGuid casterGUID)
{
    for (AuraApplicationMap::iterator iter = m_appliedAuras.begin(); iter != m_appliedAuras.end();)
    {
        Aura const* aura = iter->second->GetBase();
        if (!casterGUID || aura->GetCasterGUID() == casterGUID)
        {
            SpellInfo const* spell = aura->GetSpellInfo();
            if (spell->SpellFamilyName == uint32(family) && spell->SpellFamilyFlags.HasFlag(familyFlag1, familyFlag2, familyFlag3))
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

void Unit::RemoveAurasWithMechanic(uint32 mechanicMaskToRemove, AuraRemoveMode removeMode, uint32 exceptSpellId, bool withEffectMechanics)
{
    std::vector<Aura*> aurasToUpdateTargets;
    RemoveAppliedAuras([=, &aurasToUpdateTargets](AuraApplication const* aurApp)
    {
        Aura* aura = aurApp->GetBase();
        if (exceptSpellId && aura->GetId() == exceptSpellId)
            return false;

        uint32 appliedMechanicMask = aura->GetSpellInfo()->GetSpellMechanicMaskByEffectMask(aurApp->GetEffectMask());
        if (!(appliedMechanicMask & mechanicMaskToRemove))
            return false;

        // spell mechanic matches required mask for removal
        if ((1 << aura->GetSpellInfo()->Mechanic) & mechanicMaskToRemove || withEffectMechanics)
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
        return (!aura->GetSpellInfo()->HasAttribute(SPELL_ATTR4_DONT_REMOVE_IN_ARENA)                          // don't remove stances, shadowform, pally/hunter auras
            && !aura->IsPassive()                                                                              // don't remove passive auras
            && (aurApp->IsPositive() || !aura->GetSpellInfo()->HasAttribute(SPELL_ATTR3_DEATH_PERSISTENT))) || // not negative death persistent auras
            aura->GetSpellInfo()->HasAttribute(SPELL_ATTR5_REMOVE_ON_ARENA_ENTER);                             // special marker, always remove
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

AuraEffect* Unit::GetAuraEffect(AuraType type, SpellFamilyNames name, uint32 iconId, uint8 effIndex) const
{
    AuraEffectList const& auras = GetAuraEffectsByType(type);
    for (Unit::AuraEffectList::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
    {
        if (effIndex != (*itr)->GetEffIndex())
            continue;
        SpellInfo const* spell = (*itr)->GetSpellInfo();
        if (spell->SpellIconID == iconId && spell->SpellFamilyName == uint32(name) && !spell->SpellFamilyFlags)
            return *itr;
    }
    return nullptr;
}

AuraEffect* Unit::GetAuraEffect(AuraType type, SpellFamilyNames family, uint32 familyFlag1, uint32 familyFlag2, uint32 familyFlag3, ObjectGuid casterGUID) const
{
    AuraEffectList const& auras = GetAuraEffectsByType(type);
    for (AuraEffectList::const_iterator i = auras.begin(); i != auras.end(); ++i)
    {
        SpellInfo const* spell = (*i)->GetSpellInfo();
        if (spell->SpellFamilyName == uint32(family) && spell->SpellFamilyFlags.HasFlag(familyFlag1, familyFlag2, familyFlag3))
        {
            if (casterGUID && (*i)->GetCasterGUID() != casterGUID)
                continue;
            return (*i);
        }
    }
    return nullptr;
}

AuraEffect* Unit::GetDummyAuraEffect(SpellFamilyNames name, uint32 iconId, uint8 effIndex) const
{
    return GetAuraEffect(SPELL_AURA_DUMMY, name, iconId, effIndex);
}

AuraApplication * Unit::GetAuraApplication(uint32 spellId, ObjectGuid casterGUID, ObjectGuid itemCasterGUID, uint8 reqEffMask, AuraApplication * except) const
{
    AuraApplicationMapBounds range = m_appliedAuras.equal_range(spellId);
    for (; range.first != range.second; ++range.first)
    {
        AuraApplication* app = range.first->second;
        Aura const* aura = app->GetBase();

        if (((aura->GetEffectMask() & reqEffMask) == reqEffMask)
                && (!casterGUID || aura->GetCasterGUID() == casterGUID)
                && (!itemCasterGUID || aura->GetCastItemGUID() == itemCasterGUID)
                && (!except || except != app))
        {
            return app;
        }
    }
    return nullptr;
}

Aura* Unit::GetAura(uint32 spellId, ObjectGuid casterGUID, ObjectGuid itemCasterGUID, uint8 reqEffMask) const
{
    AuraApplication * aurApp = GetAuraApplication(spellId, casterGUID, itemCasterGUID, reqEffMask);
    return aurApp ? aurApp->GetBase() : nullptr;
}

AuraApplication * Unit::GetAuraApplicationOfRankedSpell(uint32 spellId, ObjectGuid casterGUID, ObjectGuid itemCasterGUID, uint8 reqEffMask, AuraApplication* except) const
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

Aura* Unit::GetAuraOfRankedSpell(uint32 spellId, ObjectGuid casterGUID, ObjectGuid itemCasterGUID, uint8 reqEffMask) const
{
    AuraApplication * aurApp = GetAuraApplicationOfRankedSpell(spellId, casterGUID, itemCasterGUID, reqEffMask);
    return aurApp ? aurApp->GetBase() : nullptr;
}

void Unit::GetDispellableAuraList(WorldObject const* caster, uint32 dispelMask, DispelChargesList& dispelList, bool isReflect /*= false*/) const
{
    // we should not be able to dispel diseases if the target is affected by unholy blight
    if (dispelMask & (1 << DISPEL_DISEASE) && HasAura(50536))
        dispelMask &= ~(1 << DISPEL_DISEASE);

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

bool Unit::HasAura(uint32 spellId, ObjectGuid casterGUID, ObjectGuid itemCasterGUID, uint8 reqEffMask) const
{
    if (GetAuraApplication(spellId, casterGUID, itemCasterGUID, reqEffMask))
        return true;
    return false;
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
        if ((*i)->IsAffectedOnSpell(affectedSpell))
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

bool Unit::HasNegativeAuraWithInterruptFlag(uint32 flag, ObjectGuid guid) const
{
    if (!(m_interruptMask & flag))
        return false;
    for (AuraApplicationList::const_iterator iter = m_interruptableAuras.begin(); iter != m_interruptableAuras.end(); ++iter)
    {
        if (!(*iter)->IsPositive() && (*iter)->GetBase()->GetSpellInfo()->AuraInterruptFlags & flag && (!guid || (*iter)->GetBase()->GetCasterGUID() == guid))
            return true;
    }
    return false;
}

bool Unit::HasAuraWithMechanic(uint32 mechanicMask) const
{
    for (AuraApplicationMap::const_iterator iter = m_appliedAuras.begin(); iter != m_appliedAuras.end(); ++iter)
    {
        SpellInfo const* spellInfo = iter->second->GetBase()->GetSpellInfo();
        if (spellInfo->Mechanic && (mechanicMask & (1 << spellInfo->Mechanic)))
            return true;

        for (SpellEffectInfo const& spellEffectInfo : spellInfo->GetEffects())
            if (iter->second->HasEffect(spellEffectInfo.EffectIndex) && spellEffectInfo.IsEffect() && spellEffectInfo.Mechanic)
                if (mechanicMask & (1 << spellEffectInfo.Mechanic))
                    return true;
    }

    return false;
}

bool Unit::HasStrongerAuraWithDR(SpellInfo const* auraSpellInfo, Unit* caster, bool triggered) const
{
    DiminishingGroup diminishGroup = auraSpellInfo->GetDiminishingReturnsGroupForSpell(triggered);
    DiminishingLevels level = GetDiminishing(diminishGroup);
    for (auto itr = m_appliedAuras.begin(); itr != m_appliedAuras.end(); ++itr)
    {
        SpellInfo const* spellInfo = itr->second->GetBase()->GetSpellInfo();
        if (spellInfo->GetDiminishingReturnsGroupForSpell(triggered) != diminishGroup)
            continue;

        int32 existingDuration = itr->second->GetBase()->GetDuration();
        int32 newDuration = auraSpellInfo->GetMaxDuration();
        ApplyDiminishingToDuration(auraSpellInfo, triggered, newDuration, caster, level);
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
            if ((*i)->IsAffectedOnSpell(spell))
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
        if (aurEff->IsAffectedOnSpell(affectedSpell))
            return true;
        return false;
    });
}

float Unit::GetTotalAuraMultiplierByAffectMask(AuraType auraType, SpellInfo const* affectedSpell) const
{
    return GetTotalAuraMultiplier(auraType, [affectedSpell](AuraEffect const* aurEff) -> bool
    {
        if (aurEff->IsAffectedOnSpell(affectedSpell))
            return true;
        return false;
    });
}

int32 Unit::GetMaxPositiveAuraModifierByAffectMask(AuraType auraType, SpellInfo const* affectedSpell) const
{
    return GetMaxPositiveAuraModifier(auraType, [affectedSpell](AuraEffect const* aurEff) -> bool
    {
        if (aurEff->IsAffectedOnSpell(affectedSpell))
            return true;
        return false;
    });
}

int32 Unit::GetMaxNegativeAuraModifierByAffectMask(AuraType auraType, SpellInfo const* affectedSpell) const
{
    return GetMaxNegativeAuraModifier(auraType, [affectedSpell](AuraEffect const* aurEff) -> bool
    {
        if (aurEff->IsAffectedOnSpell(affectedSpell))
            return true;
        return false;
    });
}

void Unit::UpdateResistanceBuffModsMod(SpellSchools school)
{
    float modPos = 0.0f;
    float modNeg = 0.0f;

    // these auras are always positive
    modPos = GetMaxPositiveAuraModifierByMiscMask(SPELL_AURA_MOD_RESISTANCE_EXCLUSIVE, 1 << school);
    modPos += GetTotalAuraModifier(SPELL_AURA_MOD_RESISTANCE, [school](AuraEffect const* aurEff) -> bool
    {
        if ((aurEff->GetMiscValue() & (1 << school)) && aurEff->GetAmount() > 0)
            return true;
        return false;
    });

    modNeg = GetTotalAuraModifier(SPELL_AURA_MOD_RESISTANCE, [school](AuraEffect const* aurEff) -> bool
    {
        if ((aurEff->GetMiscValue() & (1 << school)) && aurEff->GetAmount() < 0)
            return true;
        return false;
    });

    float factor = GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_RESISTANCE_PCT, 1 << school);
    modPos *= factor;
    modNeg *= factor;

    SetFloatValue(UNIT_FIELD_RESISTANCEBUFFMODSPOSITIVE + AsUnderlyingType(school), modPos);
    SetFloatValue(UNIT_FIELD_RESISTANCEBUFFMODSNEGATIVE + AsUnderlyingType(school), modNeg);
}

void Unit::InitStatBuffMods()
{
    for (uint8 i = STAT_STRENGTH; i < MAX_STATS; ++i)
        SetFloatValue(UNIT_FIELD_POSSTAT0+i, 0);
    for (uint8 i = STAT_STRENGTH; i < MAX_STATS; ++i)
        SetFloatValue(UNIT_FIELD_NEGSTAT0+i, 0);
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

    SetFloatValue(UNIT_FIELD_POSSTAT0 + AsUnderlyingType(stat), modPos);
    SetFloatValue(UNIT_FIELD_NEGSTAT0 + AsUnderlyingType(stat), modNeg);
}

void Unit::_RegisterDynObject(DynamicObject* dynObj)
{
    m_dynObj.push_back(dynObj);
}

void Unit::_UnregisterDynObject(DynamicObject* dynObj)
{
    m_dynObj.remove(dynObj);
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
    if (!gameObj || gameObj->GetOwnerGUID())
        return;

    m_gameObj.push_back(gameObj);
    gameObj->SetOwnerGUID(GetGUID());

    if (gameObj->GetSpellId())
    {
        SpellInfo const* createBySpell = sSpellMgr->GetSpellInfo(gameObj->GetSpellId());
        // Need disable spell use for owner
        if (createBySpell && createBySpell->IsCooldownStartedOnEvent())
            // note: item based cooldowns and cooldown spell mods with charges ignored (unknown existing cases)
            GetSpellHistory()->StartCooldown(createBySpell, 0, nullptr, true);
    }
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

        SpellInfo const* createBySpell = sSpellMgr->GetSpellInfo(spellid);
        // Need activate spell use for owner
        if (createBySpell && createBySpell->IsCooldownStartedOnEvent())
            // note: item based cooldowns and cooldown spell mods with charges ignored (unknown existing cases)
            GetSpellHistory()->SendCooldownEvent(createBySpell);
    }

    m_gameObj.remove(gameObj);

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

void Unit::SendSpellNonMeleeDamageLog(SpellNonMeleeDamage const* log)
{
    WorldPacket data(SMSG_SPELLNONMELEEDAMAGELOG, (16+4+4+4+1+4+4+1+1+4+4+1)); // we guess size
    data << log->target->GetPackGUID();
    data << log->attacker->GetPackGUID();
    data << uint32(log->SpellID);
    data << uint32(log->damage);                            // damage amount
    int32 overkill = log->damage - log->target->GetHealth();
    data << uint32(overkill > 0 ? overkill : 0);            // overkill
    data << uint8 (log->schoolMask);                        // damage school
    data << uint32(log->absorb);                            // AbsorbedDamage
    data << uint32(log->resist);                            // resist
    data << uint8 (log->periodicLog);                       // if 1, then client show spell name (example: %s's ranged shot hit %s for %u school or %s suffers %u school damage from %s's spell_name
    data << uint8 (log->unused);                            // unused
    data << uint32(log->blocked);                           // blocked
    data << uint32(log->HitInfo);
    data << uint8 (log->HitInfo & (SPELL_HIT_TYPE_CRIT_DEBUG | SPELL_HIT_TYPE_HIT_DEBUG | SPELL_HIT_TYPE_ATTACK_TABLE_DEBUG));
    //if (log->HitInfo & SPELL_HIT_TYPE_CRIT_DEBUG)
    //{
    //    data << float(log->CritRoll);
    //    data << float(log->CritNeeded);
    //}
    //if (log->HitInfo & SPELL_HIT_TYPE_HIT_DEBUG)
    //{
    //    data << float(log->HitRoll);
    //    data << float(log->HitNeeded);
    //}
    //if (log->HitInfo & SPELL_HIT_TYPE_ATTACK_TABLE_DEBUG)
    //{
    //    data << float(log->MissChance);
    //    data << float(log->DodgeChance);
    //    data << float(log->ParryChance);
    //    data << float(log->BlockChance);
    //    data << float(log->GlanceChance);
    //    data << float(log->CrushChance);
    //}
    SendMessageToSet(&data, true);
}

void Unit::SendSpellNonMeleeDamageLog(Unit* target, uint32 spellID, uint32 damage, SpellSchoolMask damageSchoolMask, uint32 absorbedDamage, uint32 resist, bool isPeriodic, uint32 blocked, bool criticalHit, bool split)
{
    SpellNonMeleeDamage log(this, target, spellID, damageSchoolMask);
    log.damage = damage - absorbedDamage - resist - blocked;
    log.absorb = absorbedDamage;
    log.resist = resist;
    log.periodicLog = isPeriodic;
    log.blocked = blocked;
    log.HitInfo = 0;
    if (criticalHit)
        log.HitInfo |= SPELL_HIT_TYPE_CRIT;
    if (split)
        log.HitInfo |= SPELL_HIT_TYPE_SPLIT;
    SendSpellNonMeleeDamageLog(&log);
}

/*static*/ void Unit::ProcSkillsAndAuras(Unit* actor, Unit* actionTarget, uint32 typeMaskActor, uint32 typeMaskActionTarget, uint32 spellTypeMask, uint32 spellPhaseMask, uint32 hitMask, Spell* spell, DamageInfo* damageInfo, HealInfo* healInfo)
{
    WeaponAttackType attType = damageInfo ? damageInfo->GetAttackType() : BASE_ATTACK;
    if (typeMaskActor && actor)
        actor->ProcSkillsAndReactives(false, actionTarget, typeMaskActor, hitMask, attType);

    if (typeMaskActionTarget && actionTarget)
        actionTarget->ProcSkillsAndReactives(true, actor, typeMaskActionTarget, hitMask, attType);

    if (actor)
        actor->TriggerAurasProcOnEvent(actionTarget, typeMaskActor, typeMaskActionTarget, spellTypeMask, spellPhaseMask, hitMask, spell, damageInfo, healInfo);
}

void Unit::SendPeriodicAuraLog(SpellPeriodicAuraLogInfo* pInfo)
{
    AuraEffect const* aura = pInfo->auraEff;

    WorldPacket data(SMSG_PERIODICAURALOG, 30);
    data << GetPackGUID();
    data << aura->GetCasterGUID().WriteAsPacked();
    data << uint32(aura->GetId());                          // spellId
    data << uint32(1);                                      // count
    data << uint32(aura->GetAuraType());                    // auraId
    switch (aura->GetAuraType())
    {
        case SPELL_AURA_PERIODIC_DAMAGE:
        case SPELL_AURA_PERIODIC_DAMAGE_PERCENT:
            data << uint32(pInfo->damage);                  // damage
            data << uint32(pInfo->overDamage);              // overkill?
            data << uint32(aura->GetSpellInfo()->GetSchoolMask());
            data << uint32(pInfo->absorb);                  // absorb
            data << uint32(pInfo->resist);                  // resist
            data << uint8(pInfo->critical);                 // new 3.1.2 critical tick
            break;
        case SPELL_AURA_PERIODIC_HEAL:
        case SPELL_AURA_OBS_MOD_HEALTH:
            data << uint32(pInfo->damage);                  // damage
            data << uint32(pInfo->overDamage);              // overheal
            data << uint32(pInfo->absorb);                  // absorb
            data << uint8(pInfo->critical);                 // new 3.1.2 critical tick
            break;
        case SPELL_AURA_OBS_MOD_POWER:
        case SPELL_AURA_PERIODIC_ENERGIZE:
            data << uint32(aura->GetMiscValue());           // power type
            data << uint32(pInfo->damage);                  // damage
            break;
        case SPELL_AURA_PERIODIC_MANA_LEECH:
            data << uint32(aura->GetMiscValue());           // power type
            data << uint32(pInfo->damage);                  // amount
            data << float(pInfo->multiplier);               // gain multiplier
            break;
        default:
            TC_LOG_ERROR("entities.unit", "Unit::SendPeriodicAuraLog: unknown aura {}", uint32(aura->GetAuraType()));
            return;
    }

    SendMessageToSet(&data, true);
}

void Unit::SendSpellDamageResist(Unit* target, uint32 spellId)
{
    WorldPacket data(SMSG_PROCRESIST, 8+8+4+1);
    data << uint64(GetGUID());
    data << uint64(target->GetGUID());
    data << uint32(spellId);
    data << uint8(0); // bool - log format: 0-default, 1-debug
    SendMessageToSet(&data, true);
}

void Unit::SendSpellDamageImmune(Unit* target, uint32 spellId)
{
    WorldPacket data(SMSG_SPELLORDAMAGE_IMMUNE, 8+8+4+1);
    data << uint64(GetGUID());
    data << uint64(target->GetGUID());
    data << uint32(spellId);
    data << uint8(0); // bool - log format: 0-default, 1-debug
    SendMessageToSet(&data, true);
}

void Unit::SendAttackStateUpdate(CalcDamageInfo* damageInfo)
{
    uint32 count = 1;
    if (damageInfo->Damages[1].Damage || damageInfo->Damages[1].Absorb || damageInfo->Damages[1].Resist)
        ++count;

    // guess size
    size_t const maxsize = 4+5+5+4+4+1+(4+4+4)*2+4*2+4*2+1+4+4+4+4+4*12;
    WorldPacket data(SMSG_ATTACKERSTATEUPDATE, maxsize);

    data << uint32(damageInfo->HitInfo);
    data << damageInfo->Attacker->GetPackGUID();
    data << damageInfo->Target->GetPackGUID();
    data << uint32(damageInfo->Damages[0].Damage + damageInfo->Damages[1].Damage); // Full damage
    int32 overkill = damageInfo->Damages[0].Damage + damageInfo->Damages[1].Damage - damageInfo->Target->GetHealth();
    data << uint32(overkill < 0 ? 0 : overkill);            // Overkill
    data << uint8(count);                                   // Sub damage count

    for (uint32 i = 0; i < count; ++i)
    {
        data << uint32(damageInfo->Damages[i].DamageSchoolMask);       // School of sub damage
        data << float(damageInfo->Damages[i].Damage);                  // sub damage
        data << uint32(damageInfo->Damages[i].Damage);                 // Sub Damage
    }

    if (damageInfo->HitInfo & (HITINFO_FULL_ABSORB | HITINFO_PARTIAL_ABSORB))
    {
        for (uint32 i = 0; i < count; ++i)
            data << uint32(damageInfo->Damages[i].Absorb);             // Absorb
    }

    if (damageInfo->HitInfo & (HITINFO_FULL_RESIST | HITINFO_PARTIAL_RESIST))
    {
        for (uint32 i = 0; i < count; ++i)
            data << uint32(damageInfo->Damages[i].Resist);             // Resist
    }

    data << uint8(damageInfo->TargetState);
    data << uint32(0);  // Unknown attackerstate
    data << uint32(0);  // Melee spellid

    if (damageInfo->HitInfo & HITINFO_BLOCK)
        data << uint32(damageInfo->Blocked);

    if (damageInfo->HitInfo & HITINFO_RAGE_GAIN)
        data << uint32(0);

    //! Probably used for debugging purposes, as it is not known to appear on retail servers
    if (damageInfo->HitInfo & HITINFO_UNK1)
    {
        data << uint32(0);
        data << float(0);
        data << float(0);
        data << float(0);
        data << float(0);
        data << float(0);
        data << float(0);
        data << float(0);
        data << float(0);
        data << float(0);       // Found in a loop with 1 iteration
        data << float(0);       // ditto ^
        data << uint32(0);
    }

    SendMessageToSet(&data, true);
}

void Unit::SendAttackStateUpdate(uint32 HitInfo, Unit* target, uint8 /*SwingType*/, SpellSchoolMask damageSchoolMask, uint32 Damage, uint32 AbsorbDamage, uint32 Resist, VictimState TargetState, uint32 BlockedAmount)
{
    CalcDamageInfo dmgInfo;
    dmgInfo.HitInfo = HitInfo;
    dmgInfo.Attacker = this;
    dmgInfo.Target = target;

    dmgInfo.Damages[0].Damage = Damage - AbsorbDamage - Resist - BlockedAmount;
    dmgInfo.Damages[0].DamageSchoolMask = damageSchoolMask;
    dmgInfo.Damages[0].Absorb = AbsorbDamage;
    dmgInfo.Damages[0].Resist = Resist;

    dmgInfo.Damages[1].Damage = 0;
    dmgInfo.Damages[1].DamageSchoolMask = 0;
    dmgInfo.Damages[1].Absorb = 0;
    dmgInfo.Damages[1].Resist = 0;

    dmgInfo.TargetState = TargetState;
    dmgInfo.Blocked = BlockedAmount;
    SendAttackStateUpdate(&dmgInfo);
}

void Unit::SetPowerType(Powers new_powertype, bool sendUpdate/* = true*/)
{
    if (GetPowerType() == new_powertype)
        return;

    SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_POWER_TYPE, new_powertype);

    if (!sendUpdate)
        return;

    if (GetTypeId() == TYPEID_PLAYER)
    {
        if (ToPlayer()->GetGroup())
            ToPlayer()->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_POWER_TYPE);
    }
    else if (Pet* pet = ToCreature()->ToPet())
    {
        if (pet->isControlled())
        {
            Unit* owner = GetOwner();
            if (owner && (owner->GetTypeId() == TYPEID_PLAYER) && owner->ToPlayer()->GetGroup())
                owner->ToPlayer()->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_PET_POWER_TYPE);
        }
    }

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
        case FORM_CAT:
            displayPower = POWER_ENERGY;
            break;
        case FORM_BEAR:
        case FORM_DIREBEAR:
            displayPower = POWER_RAGE;
            break;
        case FORM_TRAVEL:
        case FORM_GHOSTWOLF:
            displayPower = POWER_MANA;
            break;
        default:
        {
            if (GetTypeId() == TYPEID_PLAYER)
            {
                ChrClassesEntry const* cEntry = sChrClassesStore.LookupEntry(GetClass());
                if (cEntry && cEntry->DisplayPower < MAX_POWERS)
                    displayPower = Powers(cEntry->DisplayPower);
            }
            else if (GetTypeId() == TYPEID_UNIT)
            {
                if (Vehicle* vehicle = GetVehicleKit())
                {
                    if (PowerDisplayEntry const* powerDisplay = sPowerDisplayStore.LookupEntry(vehicle->GetVehicleInfo()->PowerDisplayID))
                        displayPower = Powers(powerDisplay->ActualType);
                    else if (GetClass() == CLASS_ROGUE)
                        displayPower = POWER_ENERGY;
                }
                else if (Pet* pet = ToPet())
                {
                    if (pet->getPetType() == HUNTER_PET) // Hunter pets have focus
                        displayPower = POWER_FOCUS;
                    else if (pet->IsPetGhoul() || pet->IsRisenAlly()) // DK pets have energy
                        displayPower = POWER_ENERGY;
                }
            }
            break;
        }
    }

    SetPowerType(displayPower);
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
        if ((!IsPet() && !IsCharmerOrSelfPlayer()) || IsInCombatWith(victim))
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

        // Remove emote state - will be restored on creature reset
        SetEmoteState(EMOTE_ONESHOT_NONE);
    }

    // delay offhand weapon attack by 50% of the base attack time
    if (haveOffhandWeapon() && GetTypeId() != TYPEID_PLAYER)
        setAttackTimer(OFF_ATTACK, std::max(getAttackTimer(OFF_ATTACK), getAttackTimer(BASE_ATTACK) + uint32(CalculatePct(GetFloatValue(UNIT_FIELD_BASEATTACKTIME), 50))));

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
        if (m_SummonSlot[i])
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
    if (apply)
    {
        if (!HasFlag(UNIT_FIELD_AURASTATE, 1<<(flag-1)))
        {
            SetFlag(UNIT_FIELD_AURASTATE, 1<<(flag-1));
            if (GetTypeId() == TYPEID_PLAYER)
            {
                PlayerSpellMap const& sp_list = ToPlayer()->GetSpellMap();
                for (PlayerSpellMap::const_iterator itr = sp_list.begin(); itr != sp_list.end(); ++itr)
                {
                    if (itr->second.state == PLAYERSPELL_REMOVED || itr->second.disabled)
                        continue;
                    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(itr->first);
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
                    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(itr->first);
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
        if (HasFlag(UNIT_FIELD_AURASTATE, 1<<(flag-1)))
        {
            RemoveFlag(UNIT_FIELD_AURASTATE, 1<<(flag-1));

            Unit::AuraApplicationMap& tAuras = GetAppliedAuras();
            for (Unit::AuraApplicationMap::iterator itr = tAuras.begin(); itr != tAuras.end();)
            {
                SpellInfo const* spellProto = itr->second->GetBase()->GetSpellInfo();
                if (itr->second->GetBase()->GetCasterGUID() == GetGUID() && spellProto->CasterAuraState == uint32(flag) && (spellProto->IsPassive() || flag != AURA_STATE_ENRAGE))
                    RemoveAura(itr);
                else
                    ++itr;
            }
        }
    }
}

uint32 Unit::BuildAuraStateUpdateForTarget(Unit const* target) const
{
    uint32 auraStates = GetUInt32Value(UNIT_FIELD_AURASTATE) &~(PER_CASTER_AURA_STATE_MASK);
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

    return HasFlag(UNIT_FIELD_AURASTATE, 1 << (flag - 1));
}

void Unit::SetOwnerGUID(ObjectGuid owner)
{
    if (GetOwnerGUID() == owner)
        return;

    SetGuidValue(UNIT_FIELD_SUMMONEDBY, owner);
    if (!owner)
        return;

    // Update owner dependent fields
    Player* player = ObjectAccessor::GetPlayer(*this, owner);
    if (!player || !player->HaveAtClient(this)) // if player cannot see this unit yet, he will receive needed data with create object
        return;

    SetFieldNotifyFlag(UF_FLAG_OWNER);

    UpdateData udata;
    WorldPacket packet;
    BuildValuesUpdateBlockForPlayer(&udata, player);
    udata.BuildPacket(&packet);
    player->SendDirectMessage(&packet);

    RemoveFieldNotifyFlag(UF_FLAG_OWNER);
}

Player* Unit::GetControllingPlayer() const
{
    if (ObjectGuid guid = GetCharmerOrOwnerGUID())
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
    if (ObjectGuid pet_guid = GetMinionGUID())
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
    if (ObjectGuid pet_guid = GetPetGUID())
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
        if (minion->GetOwnerGUID())
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
            AddGuidValue(UNIT_FIELD_SUMMON, minion->GetGUID());

        if (minion->m_Properties && minion->m_Properties->Title == SUMMON_TYPE_MINIPET)
            SetCritterGUID(minion->GetGUID());

        // PvP, FFAPvP
        minion->ReplaceAllPvpFlags(GetPvpFlags());

        // FIXME: hack, speed must be set only at follow
        if (GetTypeId() == TYPEID_PLAYER && minion->IsPet())
            for (uint8 i = 0; i < MAX_MOVE_TYPE; ++i)
                minion->SetSpeedRate(UnitMoveType(i), m_speed_rate[i]);

        // Send infinity cooldown - client does that automatically but after relog cooldown needs to be set again
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(minion->GetUInt32Value(UNIT_CREATED_BY_SPELL));
        if (spellInfo && spellInfo->IsCooldownStartedOnEvent())
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

        if (minion->m_Properties && minion->m_Properties->Title == SUMMON_TYPE_MINIPET)
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
            if (SpellInfo const* spInfo = sSpellMgr->GetSpellInfo(minion->ToTotem()->GetSpell()))
            {
                for (SpellEffectInfo const& spellEffectInfo : spInfo->GetEffects())
                {
                    if (!spellEffectInfo.IsEffect(SPELL_EFFECT_SUMMON))
                        continue;

                    RemoveAllMinionsByEntry(spellEffectInfo.MiscValue);
                }
            }
        }

        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(minion->GetUInt32Value(UNIT_CREATED_BY_SPELL));
        // Remove infinity cooldown
        if (spellInfo && (spellInfo->IsCooldownStartedOnEvent()))
            GetSpellHistory()->SendCooldownEvent(spellInfo);

        //if (minion->HasUnitTypeMask(UNIT_MASK_GUARDIAN))
        {
            if (RemoveGuidValue(UNIT_FIELD_SUMMON, minion->GetGUID()))
            {
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

                    if (AddGuidValue(UNIT_FIELD_SUMMON, (*itr)->GetGUID()))
                    {
                        // show another pet bar if there is no charm bar
                        if (GetTypeId() == TYPEID_PLAYER && !GetCharmedGUID())
                        {
                            if ((*itr)->IsPet())
                                ToPlayer()->PetSpellInitialize();
                            else
                                ToPlayer()->CharmSpellInitialize();
                        }
                    }
                    break;
                }
            }
        }
    }
    UpdatePetCombatState();
}

void Unit::GetAllMinionsByEntry(std::list<Creature*>& Minions, uint32 entry)
{
    for (Unit::ControlList::iterator itr = m_Controlled.begin(); itr != m_Controlled.end();)
    {
        Unit* unit = *itr;
        ++itr;
        if (unit->GetEntry() == entry && unit->GetTypeId() == TYPEID_UNIT
            && unit->IsSummon()) // minion, actually
            Minions.push_back(unit->ToCreature());
    }
}

void Unit::RemoveAllMinionsByEntry(uint32 entry)
{
    for (Unit::ControlList::iterator itr = m_Controlled.begin(); itr != m_Controlled.end();)
    {
        Unit* unit = *itr;
        ++itr;
        if (unit->GetEntry() == entry && unit->GetTypeId() == TYPEID_UNIT
            && unit->IsSummon()) // minion, actually
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
            ASSERT_WITH_SIDE_EFFECTS(AddGuidValue(UNIT_FIELD_CHARM, charm->GetGUID()),
                "Player %s is trying to charm unit %u, but it already has a charmed unit %s", GetName().c_str(), charm->GetEntry(), GetCharmedGUID().ToString().c_str());
            m_charmed = charm;

            charm->m_ControlledByPlayer = true;
            /// @todo maybe we can use this flag to check if controlled by player
            charm->SetUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED);
        }
        else
            charm->m_ControlledByPlayer = false;

        // PvP, FFAPvP
        charm->ReplaceAllPvpFlags(GetPvpFlags());

        ASSERT_WITH_SIDE_EFFECTS(charm->AddGuidValue(UNIT_FIELD_CHARMEDBY, GetGUID()),
            "Unit %u is being charmed, but it already has a charmer %s", charm->GetEntry(), charm->GetCharmerGUID().ToString().c_str());
        charm->m_charmer = this;

        _isWalkingBeforeCharm = charm->IsWalking();
        if (_isWalkingBeforeCharm)
        {
            charm->SetWalk(false);
            charm->SendMovementFlagUpdate();
        }

        m_Controlled.insert(charm);
    }
    else
    {
        charm->ClearUnitState(UNIT_STATE_CHARMED);

        if (GetTypeId() == TYPEID_PLAYER)
        {
            ASSERT_WITH_SIDE_EFFECTS(RemoveGuidValue(UNIT_FIELD_CHARM, charm->GetGUID()),
                "Player %s is trying to uncharm unit %u, but it has another charmed unit %s", GetName().c_str(), charm->GetEntry(), GetCharmedGUID().ToString().c_str());
            m_charmed = nullptr;
        }

        ASSERT_WITH_SIDE_EFFECTS(charm->RemoveGuidValue(UNIT_FIELD_CHARMEDBY, GetGUID()),
            "Unit %u is being uncharmed, but it has another charmer %s", charm->GetEntry(), charm->GetCharmerGUID().ToString().c_str());
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
        {
            charm->SetWalk(_isWalkingBeforeCharm);
            charm->SendMovementFlagUpdate(true); // send packet to self, to update movement state on player.
        }

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
            if (Battleground* bg = player->GetBattleground())
                bg->UpdatePlayerScore(player, SCORE_HEALING_DONE, gain);

            // use the actual gain, as the overheal shall not be counted, skip gain 0 (it ignored anyway in to criteria)
            if (gain)
                player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_HEALING_DONE, gain, 0, victim);

            player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HEAL_CAST, addhealth);
        }
    }

    if (Player* player = victim->ToPlayer())
    {
        player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_TOTAL_HEALING_RECEIVED, gain);
        player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HEALING_RECEIVED, addhealth);
    }

    if (gain)
        healInfo.SetEffectiveHeal(gain > 0 ? static_cast<uint32>(gain) : 0UL);
}

bool Unit::IsMagnet() const
{
    // Grounding Totem
    if (GetUInt32Value(UNIT_CREATED_BY_SPELL) == 8177) /// @todo: find a more generic solution
        return true;

    return false;
}

Unit* Unit::GetMeleeHitRedirectTarget(Unit* victim, SpellInfo const* spellInfo)
{
    AuraEffectList const& hitTriggerAuras = victim->GetAuraEffectsByType(SPELL_AURA_ADD_CASTER_HIT_TRIGGER);
    for (AuraEffectList::const_iterator i = hitTriggerAuras.begin(); i != hitTriggerAuras.end(); ++i)
    {
        if (Unit* magnet = (*i)->GetBase()->GetCaster())
            if (IsValidAttackTarget(magnet, spellInfo) && magnet->IsWithinLOSInMap(this)
                && (!spellInfo || (spellInfo->CheckExplicitTarget(this, magnet) == SPELL_CAST_OK
                && spellInfo->CheckTarget(this, magnet, false) == SPELL_CAST_OK)))
                if (roll_chance_i((*i)->GetAmount()))
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
        if (ObjectGuid guid = GetMinionGUID())
            unit = ObjectAccessor::GetUnit(*this, guid);

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
    if (GetPetGUID())
        TC_LOG_FATAL("entities.unit", "Unit {} is not able to release its pet {}", GetEntry(), GetPetGUID().ToString());
    if (GetMinionGUID())
        TC_LOG_FATAL("entities.unit", "Unit {} is not able to release its minion {}", GetEntry(), GetMinionGUID().ToString());
    if (GetCharmedGUID())
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

Unit* Unit::GetCharmerOrSelf() const
{
    if (IsCharmed())
        return GetCharmer();
    else
        return const_cast<Unit*>(this);
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
    // we guess size
    WorldPacket data(SMSG_SPELLHEALLOG, 8 + 8 + 4 + 4 + 4 + 4 + 1 + 1);
    data << healInfo.GetTarget()->GetPackGUID();
    data << healInfo.GetHealer()->GetPackGUID();
    data << uint32(healInfo.GetSpellInfo()->Id);
    data << uint32(healInfo.GetHeal());
    data << uint32(healInfo.GetHeal() - healInfo.GetEffectiveHeal());
    data << uint32(healInfo.GetAbsorb()); // Absorb amount
    data << uint8(critical ? 1 : 0);
    data << uint8(0); // unused
    SendMessageToSet(&data, true);
}

int32 Unit::HealBySpell(HealInfo& healInfo, bool critical /*= false*/)
{
    // calculate heal absorb and reduce healing
    Unit::CalcHealAbsorb(healInfo);
    Unit::DealHeal(healInfo);
    SendHealSpellLog(healInfo, critical);
    return healInfo.GetEffectiveHeal();
}

void Unit::SendEnergizeSpellLog(Unit* victim, uint32 spellId, int32 damage, Powers powerType)
{
    WorldPacket data(SMSG_SPELLENERGIZELOG, (8+8+4+4+4+1));
    data << victim->GetPackGUID();
    data << GetPackGUID();
    data << uint32(spellId);
    data << uint32(powerType);
    data << int32(damage);
    SendMessageToSet(&data, true);
}

void Unit::EnergizeBySpell(Unit* victim, uint32 spellId, int32 damage, Powers powerType)
{
    if (SpellInfo const* info = sSpellMgr->GetSpellInfo(spellId))
        EnergizeBySpell(victim, info, damage, powerType);
}

void Unit::EnergizeBySpell(Unit* victim, SpellInfo const* spellInfo, int32 damage, Powers powerType)
{
    victim->ModifyPower(powerType, damage, false);
    victim->GetThreatManager().ForwardThreatForAssistingMe(this, float(damage)/2, spellInfo, true);
    SendEnergizeSpellLog(victim, spellInfo->Id, damage, powerType);
}

uint32 Unit::SpellDamageBonusDone(Unit* victim, SpellInfo const* spellProto, uint32 pdamage, DamageEffectType damagetype, SpellEffectInfo const& spellEffectInfo, Optional<float> const& donePctTotal, uint32 stack /*= 1*/) const
{
    if (!spellProto || !victim || damagetype == DIRECT_DAMAGE)
        return pdamage;

    // Some spells don't benefit from done mods
    if (spellProto->HasAttribute(SPELL_ATTR3_NO_DONE_BONUS))
        return pdamage;

    // For totems get damage bonus from owner
    if (GetTypeId() == TYPEID_UNIT && IsTotem())
        if (Unit* owner = GetOwner())
            return owner->SpellDamageBonusDone(victim, spellProto, pdamage, damagetype, spellEffectInfo, donePctTotal, stack);

    float ApCoeffMod = 1.0f;
    int32 DoneTotal = 0;
    float DoneTotalMod = donePctTotal ? *donePctTotal : SpellDamagePctDone(victim, spellProto, damagetype);

    // done scripted mod (take it from owner)
    Unit const* owner = GetOwner() ? GetOwner() : this;
    DoneTotal += owner->GetTotalAuraModifier(SPELL_AURA_OVERRIDE_CLASS_SCRIPTS, [spellProto](AuraEffect const* aurEff) -> bool
    {
        if (!aurEff->IsAffectedOnSpell(spellProto))
            return false;

        switch (aurEff->GetMiscValue())
        {
            case 4418: // Increased Shock Damage
            case 4554: // Increased Lightning Damage
            case 4555: // Improved Moonfire
            case 5142: // Increased Lightning Damage
            case 5147: // Improved Consecration / Libram of Resurgence
            case 5148: // Idol of the Shooting Star
            case 6008: // Increased Lightning Damage
            case 8627: // Totem of Hex
                return true;
            default:
                break;
        }

        return false;
    });

    // Some spells don't benefit from pct done mods
    if (!spellProto->HasAttribute(SPELL_ATTR6_LIMIT_PCT_DAMAGE_MODS))
        DoneTotal += GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_FLAT_SPELL_DAMAGE_VERSUS, victim->GetCreatureTypeMask());

    // Custom scripted damage
    switch (spellProto->SpellFamilyName)
    {
        case SPELLFAMILY_DEATHKNIGHT:
            // Impurity (dummy effect)
            if (GetTypeId() == TYPEID_PLAYER)
            {
                PlayerSpellMap const& playerSpells = ToPlayer()->GetSpellMap();
                for (auto itr = playerSpells.begin(); itr != playerSpells.end(); ++itr)
                {
                    if (itr->second.state == PLAYERSPELL_REMOVED || itr->second.disabled)
                        continue;

                    switch (itr->first)
                    {
                        case 49220:
                        case 49633:
                        case 49635:
                        case 49636:
                        case 49638:
                            if (SpellInfo const* proto = sSpellMgr->GetSpellInfo(itr->first))
                                AddPct(ApCoeffMod, proto->GetEffect(EFFECT_0).CalcValue());
                            break;
                    }
                }
            }
            break;
    }

    // Done fixed damage bonus auras
    int32 DoneAdvertisedBenefit  = SpellBaseDamageBonusDone(spellProto->GetSchoolMask());
    // modify spell power by victim's SPELL_AURA_MOD_DAMAGE_TAKEN auras (eg Amplify/Dampen Magic)
    DoneAdvertisedBenefit += victim->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_DAMAGE_TAKEN, spellProto->GetSchoolMask());

    // Pets just add their bonus damage to their spell damage
    // note that their spell damage is just gain of their own auras
    if (HasUnitTypeMask(UNIT_MASK_GUARDIAN))
        DoneAdvertisedBenefit += static_cast<Guardian const*>(this)->GetBonusDamage();

    // Check for table values
    float coeff = spellEffectInfo.BonusMultiplier;
    if (SpellBonusEntry const* bonus = sSpellMgr->GetSpellBonusData(spellProto->Id))
    {
        WeaponAttackType const attType = (spellProto->IsRangedWeaponSpell() && spellProto->DmgClass != SPELL_DAMAGE_CLASS_MELEE) ? RANGED_ATTACK : BASE_ATTACK;
        float APbonus = float(victim->GetTotalAuraModifier(attType == BASE_ATTACK ? SPELL_AURA_MELEE_ATTACK_POWER_ATTACKER_BONUS : SPELL_AURA_RANGED_ATTACK_POWER_ATTACKER_BONUS));
        APbonus += GetTotalAttackPowerValue(attType);

        if (damagetype == DOT)
        {
            coeff = bonus->dot_damage;
            if (bonus->ap_dot_bonus > 0)
                DoneTotal += int32(bonus->ap_dot_bonus * stack * ApCoeffMod * APbonus);
        }
        else
        {
            coeff = bonus->direct_damage;
            if (bonus->ap_bonus > 0)
                DoneTotal += int32(bonus->ap_bonus * stack * ApCoeffMod * APbonus);
        }
    }
    else
    {
        // No bonus damage for SPELL_DAMAGE_CLASS_NONE class spells by default
        if (spellProto->DmgClass == SPELL_DAMAGE_CLASS_NONE)
            return uint32(std::max(pdamage * DoneTotalMod, 0.0f));
    }

    // Default calculation
    if (DoneAdvertisedBenefit)
    {
        if (coeff < 0.f)
            coeff = CalculateDefaultCoefficient(spellProto, damagetype);  // As wowwiki says: C = (Cast Time / 3.5)

        float factorMod = CalculateSpellpowerCoefficientLevelPenalty(spellProto) * stack;
        if (Player* modOwner = GetSpellModOwner())
        {
            coeff *= 100.0f;
            modOwner->ApplySpellMod(spellProto->Id, SPELLMOD_BONUS_MULTIPLIER, coeff);
            coeff /= 100.0f;
        }

        DoneTotal += int32(DoneAdvertisedBenefit * coeff * factorMod);
    }

    float tmpDamage = float(int32(pdamage) + DoneTotal) * DoneTotalMod;

    // apply spellmod to Done damage (flat and pct)
    if (Player* modOwner = GetSpellModOwner())
        modOwner->ApplySpellMod(spellProto->Id, damagetype == DOT ? SPELLMOD_DOT : SPELLMOD_DAMAGE, tmpDamage);

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
    if (spellProto->HasAttribute(SPELL_ATTR6_LIMIT_PCT_DAMAGE_MODS))
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

    float maxModDamagePercentSchool = 0.0f;
    if (GetTypeId() == TYPEID_PLAYER)
    {
        for (uint32 i = 0; i < MAX_SPELL_SCHOOL; ++i)
            if (spellProto->GetSchoolMask() & (1 << i))
                maxModDamagePercentSchool = std::max(maxModDamagePercentSchool, GetFloatValue(PLAYER_FIELD_MOD_DAMAGE_DONE_PCT + i));
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

    // done scripted mod (take it from owner)
    Unit const* owner = GetOwner() ? GetOwner() : this;
    AuraEffectList const& mOverrideClassScript = owner->GetAuraEffectsByType(SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
    for (AuraEffectList::const_iterator i = mOverrideClassScript.begin(); i != mOverrideClassScript.end(); ++i)
    {
        if (!(*i)->IsAffectedOnSpell(spellProto))
            continue;

        switch ((*i)->GetMiscValue())
        {
            case 4920: // Molten Fury
            case 4919:
            case 6917: // Death's Embrace
            case 6926:
            case 6928:
            {
                if (victim->HasAuraState(AURA_STATE_HEALTHLESS_35_PERCENT, spellProto, this))
                    AddPct(DoneTotalMod, (*i)->GetAmount());
                break;
            }
            // Soul Siphon
            case 4992:
            case 4993:
            {
                // effect 1 m_amount
                int32 maxPercent = (*i)->GetAmount();
                // effect 0 m_amount
                int32 stepPercent = CalculateSpellDamage((*i)->GetSpellInfo()->GetEffect(EFFECT_0));
                // count affliction effects and calc additional damage in percentage
                int32 modPercent = 0;
                AuraApplicationMap const& victimAuras = victim->GetAppliedAuras();
                for (AuraApplicationMap::const_iterator itr = victimAuras.begin(); itr != victimAuras.end(); ++itr)
                {
                    Aura const* aura = itr->second->GetBase();
                    SpellInfo const* spell = aura->GetSpellInfo();
                    if (spell->SpellFamilyName != SPELLFAMILY_WARLOCK || !(spell->SpellFamilyFlags[1] & 0x0004071B || spell->SpellFamilyFlags[0] & 0x8044C402))
                        continue;
                    modPercent += stepPercent * aura->GetStackAmount();
                    if (modPercent >= maxPercent)
                    {
                        modPercent = maxPercent;
                        break;
                    }
                }
                AddPct(DoneTotalMod, modPercent);
                break;
            }
            case 6916: // Death's Embrace
            case 6925:
            case 6927:
                if (HasAuraState(AURA_STATE_HEALTHLESS_20_PERCENT, spellProto, this))
                    AddPct(DoneTotalMod, (*i)->GetAmount());
                break;
            case 5481: // Starfire Bonus
            {
                if (victim->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DRUID, 0x200002, 0, 0))
                    AddPct(DoneTotalMod, (*i)->GetAmount());
                break;
            }
            // Tundra Stalker
            // Merciless Combat
            case 7277:
            {
                // Merciless Combat
                if ((*i)->GetSpellInfo()->SpellIconID == 2656)
                {
                    if (!victim->HealthAbovePct(35))
                        AddPct(DoneTotalMod, (*i)->GetAmount());
                }
                // Tundra Stalker
                else
                {
                    // Frost Fever (target debuff)
                    if (victim->HasAura(55095))
                        AddPct(DoneTotalMod, (*i)->GetAmount());
                    break;
                }
                break;
            }
            // Rage of Rivendare
            case 7293:
            {
                if (victim->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DEATHKNIGHT, 0, 0x02000000, 0))
                    AddPct(DoneTotalMod, (*i)->GetSpellInfo()->GetRank() * 2.0f);
                break;
            }
            // Twisted Faith
            case 7377:
            {
                if (victim->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_PRIEST, 0x8000, 0, 0, GetGUID()))
                    AddPct(DoneTotalMod, (*i)->GetAmount());
                break;
            }
            // Marked for Death
            case 7598:
            case 7599:
            case 7600:
            case 7601:
            case 7602:
            {
                if (victim->GetAuraEffect(SPELL_AURA_MOD_STALKED, SPELLFAMILY_HUNTER, 0x400, 0, 0))
                    AddPct(DoneTotalMod, (*i)->GetAmount());
                break;
            }
            // Dirty Deeds
            case 6427:
            case 6428:
            case 6579:
            case 6580:
            {
                if (victim->HasAuraState(AURA_STATE_HEALTHLESS_35_PERCENT, spellProto, this))
                {
                    // effect 0 has expected value but in negative state
                    int32 bonus = -(*i)->GetBase()->GetEffect(0)->GetAmount();
                    AddPct(DoneTotalMod, bonus);
                }
                break;
            }
        }
    }

    // Custom scripted damage
    switch (spellProto->SpellFamilyName)
    {
        case SPELLFAMILY_MAGE:
            // Ice Lance
            if (spellProto->SpellIconID == 186)
            {
                if (victim->HasAuraState(AURA_STATE_FROZEN, spellProto, this))
                {
                    // Glyph of Ice Lance
                    if (owner->HasAura(56377) && victim->GetLevel() > owner->GetLevel())
                        DoneTotalMod *= 4.0f;
                    else
                        DoneTotalMod *= 3.0f;
                }
            }

            // Torment the weak
            if (spellProto->SpellFamilyFlags[0] & 0x20600021 || spellProto->SpellFamilyFlags[1] & 0x9000)
            {
                if (victim->HasAuraWithMechanic((1 << MECHANIC_SNARE) | (1 << MECHANIC_SLOW_ATTACK)))
                {
                    AuraEffectList const& mDumyAuras = GetAuraEffectsByType(SPELL_AURA_DUMMY);
                    for (AuraEffectList::const_iterator i = mDumyAuras.begin(); i != mDumyAuras.end(); ++i)
                    {
                        if ((*i)->GetSpellInfo()->SpellIconID == 3263)
                        {
                            AddPct(DoneTotalMod, (*i)->GetAmount());
                            break;
                        }
                    }
                }
            }
            break;
        case SPELLFAMILY_PRIEST:
            // Mind Flay
            if (spellProto->SpellFamilyFlags[0] & 0x800000)
            {
                // Glyph of Shadow Word: Pain
                if (AuraEffect* aurEff = GetAuraEffect(55687, 0))
                    // Increase Mind Flay damage if Shadow Word: Pain present on target
                    if (victim->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_PRIEST, 0x8000, 0, 0, GetGUID()))
                        AddPct(DoneTotalMod, aurEff->GetAmount());

                // Twisted Faith - Mind Flay part
                if (AuraEffect* aurEff = GetAuraEffect(SPELL_AURA_OVERRIDE_CLASS_SCRIPTS, SPELLFAMILY_PRIEST, 2848, 1))
                    // Increase Mind Flay damage if Shadow Word: Pain present on target
                    if (victim->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_PRIEST, 0x8000, 0, 0, GetGUID()))
                        AddPct(DoneTotalMod, aurEff->GetAmount());
            }
            // Smite
            else if (spellProto->SpellFamilyFlags[0] & 0x80)
            {
                // Glyph of Smite
                if (AuraEffect* aurEff = GetAuraEffect(55692, 0))
                    if (victim->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_PRIEST, 0x100000, 0, 0, GetGUID()))
                        AddPct(DoneTotalMod, aurEff->GetAmount());
            }
            // Shadow Word: Death
            else if (spellProto->SpellFamilyFlags[1] & 0x2)
            {
                // Glyph of Shadow Word: Death
                if (AuraEffect* aurEff = GetAuraEffect(55682, 1))
                    if (victim->HasAuraState(AURA_STATE_HEALTHLESS_35_PERCENT))
                        AddPct(DoneTotalMod, aurEff->GetAmount());
            }
            break;
        case SPELLFAMILY_PALADIN:
            // Judgement of Vengeance/Judgement of Corruption
            if ((spellProto->SpellFamilyFlags[1] & 0x400000) && spellProto->SpellIconID == 2292)
            {
                // Get stack of Holy Vengeance/Blood Corruption on the target added by caster
                uint32 stacks = 0;
                Unit::AuraEffectList const& auras = victim->GetAuraEffectsByType(SPELL_AURA_PERIODIC_DAMAGE);
                for (Unit::AuraEffectList::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
                {
                    if (((*itr)->GetId() == 31803 || (*itr)->GetId() == 53742) && (*itr)->GetCasterGUID() == GetGUID())
                    {
                        stacks = (*itr)->GetBase()->GetStackAmount();
                        break;
                    }
                }
                // + 10% for each application of Holy Vengeance/Blood Corruption on the target
                if (stacks)
                    AddPct(DoneTotalMod, 10 * stacks);
            }
            break;
        case SPELLFAMILY_DRUID:
            // Thorns
            if (spellProto->SpellFamilyFlags[0] & 0x100)
            {
                // Brambles
                if (AuraEffect* aurEff = GetAuraEffectOfRankedSpell(16836, 0))
                    AddPct(DoneTotalMod, aurEff->GetAmount());
            }
            break;
        case SPELLFAMILY_WARLOCK:
            // Fire and Brimstone
            if (spellProto->SpellFamilyFlags[1] & 0x00020040)
            {
                if (victim->HasAuraState(AURA_STATE_CONFLAGRATE, nullptr, this))
                {
                    if (AuraEffect const* aurEFf = GetDummyAuraEffect(SPELLFAMILY_WARLOCK, 3173, EFFECT_0))
                        AddPct(DoneTotalMod, aurEFf->GetAmount());
                }
            }
            // Shadow Bite (15% increase from each dot)
            if (spellProto->SpellFamilyFlags[1] & 0x00400000 && IsPet())
                if (uint8 count = victim->GetDoTsByCaster(GetOwnerGUID()))
                    AddPct(DoneTotalMod, 15 * count);

            // Drain Soul - If the target is at or below 25% health, Drain Soul causes four times the normal damage
            if (spellProto->SpellFamilyFlags[0] & 0x00004000 && !victim->HealthAbovePct(25))
                DoneTotalMod *= 4;

            // Don't let Conflagrate double dip from damage done bonuses (from Immolate/Shadowflame and then for itself)
            if (spellProto->SpellFamilyFlags[1] & 0x800000)
                DoneTotalMod = 1.0f;
            break;
        case SPELLFAMILY_HUNTER:
            // Steady Shot
            if (spellProto->SpellFamilyFlags[1] & 0x1)
                if (AuraEffect* aurEff = GetAuraEffect(56826, 0))  // Glyph of Steady Shot
                    if (victim->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_HUNTER, 0x00004000, 0, 0, GetGUID()))
                        AddPct(DoneTotalMod, aurEff->GetAmount());
            break;
        case SPELLFAMILY_DEATHKNIGHT:
            // Improved Icy Touch
            if (spellProto->SpellFamilyFlags[0] & 0x2)
                if (AuraEffect* aurEff = GetDummyAuraEffect(SPELLFAMILY_DEATHKNIGHT, 2721, 0))
                    AddPct(DoneTotalMod, aurEff->GetAmount());

            // Glacier Rot
            if (spellProto->SpellFamilyFlags[0] & 0x2 || spellProto->SpellFamilyFlags[1] & 0x6)
                if (AuraEffect* aurEff = GetDummyAuraEffect(SPELLFAMILY_DEATHKNIGHT, 196, 0))
                    if (victim->GetDiseasesByCaster(owner->GetGUID()) > 0)
                        AddPct(DoneTotalMod, aurEff->GetAmount());
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

    //.. taken pct: dummy auras
    AuraEffectList const& mDummyAuras = GetAuraEffectsByType(SPELL_AURA_DUMMY);
    for (AuraEffectList::const_iterator i = mDummyAuras.begin(); i != mDummyAuras.end(); ++i)
    {
        switch ((*i)->GetSpellInfo()->SpellIconID)
        {
            // Cheat Death
            case 2109:
                if ((*i)->GetMiscValue() & SPELL_SCHOOL_MASK_NORMAL)
                {
                    // Patch 2.4.3: The resilience required to reach the 90% damage reduction cap
                    //  is 22.5% critical strike damage reduction, or 444 resilience.
                    // To calculate for 90%, we multiply the 100% by 4 (22.5% * 4 = 90%)
                    float mod = -1.0f * GetMeleeCritDamageReduction(400);
                    AddPct(TakenTotalMod, std::max(mod, float((*i)->GetAmount())));
                }
                break;
        }
    }

    // Spells with SPELL_ATTR4_FIXED_DAMAGE should only benefit from mechanic damage mod auras.
    if (!spellProto->HasAttribute(SPELL_ATTR4_FIXED_DAMAGE))
    {
        // from positive and negative SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN
        // multiplicative bonus, for example Dispersion + Shadowform (0.10*0.85=0.085)
        TakenTotalMod *= GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, spellProto->GetSchoolMask());

        // From caster spells
        if (caster)
        {
            TakenTotalMod *= GetTotalAuraMultiplier(SPELL_AURA_MOD_DAMAGE_FROM_CASTER, [caster, spellProto](AuraEffect const* aurEff) -> bool
            {
                if (aurEff->GetCasterGUID() == caster->GetGUID() && aurEff->IsAffectedOnSpell(spellProto))
                    return true;
                return false;
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
    int32 DoneAdvertisedBenefit = GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_DAMAGE_DONE, schoolMask);

    if (GetTypeId() == TYPEID_PLAYER)
    {
        // Base value
        DoneAdvertisedBenefit += ToPlayer()->GetBaseSpellPowerBonus();

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

        // ... and attack power
        DoneAdvertisedBenefit += static_cast<int32>(CalculatePct(GetTotalAttackPowerValue(BASE_ATTACK), GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_SPELL_DAMAGE_OF_ATTACK_POWER, schoolMask)));
    }

    return DoneAdvertisedBenefit;
}

float Unit::SpellCritChanceDone(SpellInfo const* spellInfo, SpellSchoolMask schoolMask, WeaponAttackType attackType /*= BASE_ATTACK*/, bool isPeriodic /*= false*/) const
{
    //! Mobs can't crit with spells. (Except player controlled)
    if (GetTypeId() == TYPEID_UNIT && !GetSpellModOwner())
        return 0.0f;

    // not critting spell
    if (!isPeriodic && !spellInfo->HasAttribute(SPELL_ATTR0_CU_CAN_CRIT))
        return 0.0f;

    float crit_chance = 0.0f;
    switch (spellInfo->DmgClass)
    {
        case SPELL_DAMAGE_CLASS_NONE:
        case SPELL_DAMAGE_CLASS_MAGIC:
        {
            auto getPhysicalCritChance = [&]
            {
                return GetUnitCriticalChanceDone(attackType) + GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_SPELL_CRIT_CHANCE_SCHOOL, schoolMask);
            };

            auto getMagicCritChance = [&]
            {
                if (IsPlayer())
                    return GetFloatValue(PLAYER_SPELL_CRIT_PERCENTAGE1 + AsUnderlyingType(GetFirstSchoolInMask(schoolMask)));

                return m_baseSpellCritChance + GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_SPELL_CRIT_CHANCE_SCHOOL, schoolMask);
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
            crit_chance += GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_SPELL_CRIT_CHANCE_SCHOOL, schoolMask);
            break;
        }
        default:
            return 0.0f;
    }
    // percent done
    // only players use intelligence for critical chance computations
    if (Player* modOwner = GetSpellModOwner())
        modOwner->ApplySpellMod(spellInfo->Id, SPELLMOD_CRITICAL_CHANCE, crit_chance);

    return std::max(crit_chance, 0.0f);
}

float Unit::SpellCritChanceTaken(Unit const* caster, SpellInfo const* spellInfo, SpellSchoolMask schoolMask, float doneChance, WeaponAttackType attackType /*= BASE_ATTACK*/, bool isPeriodic /*= false*/) const
{
    // not critting spell
    if (!isPeriodic && !spellInfo->HasAttribute(SPELL_ATTR0_CU_CAN_CRIT))
        return 0.0f;

    float crit_chance = doneChance;
    switch (spellInfo->DmgClass)
    {
        case SPELL_DAMAGE_CLASS_MAGIC:
        {
            // taken
            if (!spellInfo->IsPositive())
            {
                // Modify critical chance by victim SPELL_AURA_MOD_ATTACKER_SPELL_CRIT_CHANCE
                crit_chance += GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_ATTACKER_SPELL_CRIT_CHANCE, schoolMask);

                if (caster && caster->CanApplyResilience())
                    Unit::ApplyResilience(this, &crit_chance, nullptr, false, CR_CRIT_TAKEN_SPELL);

                // Modify critical chance by victim SPELL_AURA_MOD_ATTACKER_SPELL_AND_WEAPON_CRIT_CHANCE
                // applied after resilience
                crit_chance += GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_SPELL_AND_WEAPON_CRIT_CHANCE);
            }

            // scripted (increase crit chance ... against ... target by x%
            if (caster)
            {
                AuraEffectList const& mOverrideClassScript = caster->GetAuraEffectsByType(SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
                for (AuraEffect const* aurEff : mOverrideClassScript)
                {
                    if (!aurEff->IsAffectedOnSpell(spellInfo))
                        continue;

                    float modChance = 0.f;
                    switch (aurEff->GetMiscValue())
                    {
                        case 911: // Shatter (Rank 3)
                            modChance += 16.f;
                            [[fallthrough]];
                        case 910: // Shatter (Rank 2)
                            modChance += 17.f;
                            [[fallthrough]];
                        case 849: // Shatter (Rank 1)
                            modChance += 17.f;
                            if (!HasAuraState(AURA_STATE_FROZEN, spellInfo, caster))
                                break;

                            crit_chance += modChance;
                            break;
                        case 7917: // Glyph of Shadowburn
                            if (HasAuraState(AURA_STATE_HEALTHLESS_35_PERCENT, spellInfo, caster))
                                crit_chance += aurEff->GetAmount();
                            break;
                        case 7997: // Renewed Hope
                        case 7998:
                            if (HasAura(6788))
                                crit_chance += aurEff->GetAmount();
                            break;
                        default:
                            break;
                    }
                }
                // Custom crit by class
                switch (spellInfo->SpellFamilyName)
                {
                    case SPELLFAMILY_MAGE:
                        // Glyph of Fire Blast
                        if (spellInfo->SpellFamilyFlags[0] == 0x2 && spellInfo->SpellIconID == 12)
                            if (HasAuraWithMechanic((1 << MECHANIC_STUN) | (1 << MECHANIC_KNOCKOUT)))
                                if (AuraEffect const* aurEff = caster->GetAuraEffect(56369, EFFECT_0))
                                    crit_chance += aurEff->GetAmount();
                        break;
                    case SPELLFAMILY_DRUID:
                        // Improved Faerie Fire
                        if (HasAuraState(AURA_STATE_FAERIE_FIRE))
                            if (AuraEffect const* aurEff = caster->GetDummyAuraEffect(SPELLFAMILY_DRUID, 109, 0))
                                crit_chance += aurEff->GetAmount();

                        // cumulative effect - don't break

                        // Starfire
                        if (spellInfo->SpellFamilyFlags[0] & 0x4 && spellInfo->SpellIconID == 1485)
                        {
                            // Improved Insect Swarm
                            if (AuraEffect const* aurEff = caster->GetDummyAuraEffect(SPELLFAMILY_DRUID, 1771, 0))
                                if (GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DRUID, 0x00000002, 0, 0))
                                    crit_chance += aurEff->GetAmount();
                            break;
                        }
                        break;
                    case SPELLFAMILY_ROGUE:
                        // Shiv-applied poisons can't crit
                        if (caster->FindCurrentSpellBySpellId(5938))
                            crit_chance = 0.0f;
                        break;
                    case SPELLFAMILY_PALADIN:
                        // Flash of light
                        if (spellInfo->SpellFamilyFlags[0] & 0x40000000)
                        {
                            // Sacred Shield
                            if (AuraEffect const* aura = GetAuraEffect(58597, 1, GetGUID()))
                                crit_chance += aura->GetAmount();
                            break;
                        }
                        // Exorcism
                        else if (spellInfo->GetCategory() == 19)
                        {
                            if (GetCreatureTypeMask() & CREATURE_TYPEMASK_DEMON_OR_UNDEAD)
                                return 100.0f;
                            break;
                        }
                        break;
                    case SPELLFAMILY_SHAMAN:
                        // Lava Burst
                        if (spellInfo->SpellFamilyFlags[1] & 0x00001000)
                        {
                            if (GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_SHAMAN, 0x10000000, 0, 0, caster->GetGUID()))
                                if (GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_SPELL_AND_WEAPON_CRIT_CHANCE) > -100)
                                    return 100.0f;
                            break;
                        }
                        break;
                }

                // Spell crit suppression
                if (GetTypeId() == TYPEID_UNIT)
                {
                    int32 const levelDiff = static_cast<int32>(GetLevelForTarget(caster)) - caster->GetLevel();
                    crit_chance -= levelDiff * 0.7f;
                }
            }
            break;
        }
        case SPELL_DAMAGE_CLASS_MELEE:
        {
            // Custom crit by class
            if (caster)
            {
                switch (spellInfo->SpellFamilyName)
                {
                    case SPELLFAMILY_DRUID:
                        // Rend and Tear - bonus crit chance for Ferocious Bite on bleeding targets
                        if (spellInfo->SpellFamilyFlags[0] & 0x00800000
                            && spellInfo->SpellIconID == 1680
                            && HasAuraState(AURA_STATE_BLEEDING))
                        {
                            if (AuraEffect const* rendAndTear = caster->GetDummyAuraEffect(SPELLFAMILY_DRUID, 2859, 1))
                                crit_chance += rendAndTear->GetAmount();
                            break;
                        }
                        break;
                    case SPELLFAMILY_WARRIOR:
                        // Victory Rush
                        if (spellInfo->SpellFamilyFlags[1] & 0x100)
                        {
                            // Glyph of Victory Rush
                            if (AuraEffect const* aurEff = caster->GetAuraEffect(58382, 0))
                                crit_chance += aurEff->GetAmount();
                            break;
                        }
                        break;
                }
            }
            [[fallthrough]]; // Calculate critical strike chance for both Ranged and Melee spells
        }
        case SPELL_DAMAGE_CLASS_RANGED:
            if (caster)
                crit_chance = GetUnitCriticalChanceTaken(caster, attackType, crit_chance);
            break;
        case SPELL_DAMAGE_CLASS_NONE:
        default:
            return 0.f;
    }

    if (caster)
    {
        crit_chance += GetTotalAuraModifier(SPELL_AURA_MOD_CRIT_CHANCE_FOR_CASTER, [caster, spellInfo](AuraEffect const* aurEff) -> bool
        {
            if (aurEff->GetCasterGUID() == caster->GetGUID() && aurEff->IsAffectedOnSpell(spellInfo))
                return true;
            return false;
        });
    }

    return std::max(crit_chance, 0.0f);
}

/*static*/ uint32 Unit::SpellCriticalDamageBonus(Unit const* caster, SpellInfo const* spellProto, uint32 damage, Unit* victim)
{
    // Calculate critical bonus
    int32 crit_bonus = damage;
    float crit_mod = 0.0f;

    switch (spellProto->DmgClass)
    {
        case SPELL_DAMAGE_CLASS_MELEE:                      // for melee based spells is 100%
        case SPELL_DAMAGE_CLASS_RANGED:
            /// @todo write here full calculation for melee/ranged spells
            crit_bonus += damage;
            break;
        default:
            crit_bonus += damage / 2;                       // for spells is 50%
            break;
    }

    if (caster)
    {
        crit_mod += (caster->GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_CRIT_DAMAGE_BONUS, spellProto->GetSchoolMask()) - 1.0f) * 100;

        if (victim)
            crit_mod += caster->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_CRIT_PERCENT_VERSUS, victim->GetCreatureTypeMask());

        if (crit_bonus != 0)
            AddPct(crit_bonus, crit_mod);

        crit_bonus -= damage;

        if (damage > uint32(crit_bonus))
        {
            // adds additional damage to critBonus (from talents)
            if (Player* modOwner = caster->GetSpellModOwner())
                modOwner->ApplySpellMod(spellProto->Id, SPELLMOD_CRIT_DAMAGE_BONUS, crit_bonus);
        }

        crit_bonus += damage;
    }

    return crit_bonus;
}

/*static*/ uint32 Unit::SpellCriticalHealingBonus(Unit const* caster, SpellInfo const* spellProto, uint32 damage, Unit* victim)
{
    // Calculate critical bonus
    int32 crit_bonus;
    switch (spellProto->DmgClass)
    {
        case SPELL_DAMAGE_CLASS_MELEE:                      // for melee based spells is 100%
        case SPELL_DAMAGE_CLASS_RANGED:
            /// @todo write here full calculation for melee/ranged spells
            crit_bonus = damage;
            break;
        default:
            crit_bonus = damage / 2;                        // for spells is 50%
            break;
    }

    if (caster)
    {
        if (victim)
        {
            uint32 creatureTypeMask = victim->GetCreatureTypeMask();
            crit_bonus = int32(crit_bonus * caster->GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_CRIT_PERCENT_VERSUS, creatureTypeMask));
        }
    }

    if (crit_bonus > 0)
        damage += crit_bonus;

    if (caster)
        damage = int32(float(damage) * caster->GetTotalAuraMultiplier(SPELL_AURA_MOD_CRITICAL_HEALING_AMOUNT));

    return damage;
}

uint32 Unit::SpellHealingBonusDone(Unit* victim, SpellInfo const* spellProto, uint32 healamount, DamageEffectType damagetype, SpellEffectInfo const& spellEffectInfo, Optional<float> const& donePctTotal, uint32 stack /*= 1*/) const
{
    // For totems get healing bonus from owner (statue isn't totem in fact)
    if (GetTypeId() == TYPEID_UNIT && IsTotem())
        if (Unit* owner = GetOwner())
            return owner->SpellHealingBonusDone(victim, spellProto, healamount, damagetype, spellEffectInfo, donePctTotal, stack);

    // No bonus healing for potion spells
    if (spellProto->SpellFamilyName == SPELLFAMILY_POTION)
        return healamount;

    float ApCoeffMod = 1.0f;
    int32 DoneTotal = 0;
    float DoneTotalMod = donePctTotal ? *donePctTotal : SpellHealingPctDone(victim, spellProto);

    // done scripted mod (take it from owner)
    Unit const* owner = GetOwner() ? GetOwner() : this;
    AuraEffectList const& mOverrideClassScript= owner->GetAuraEffectsByType(SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
    for (AuraEffect const* aurEff : mOverrideClassScript)
    {
        if (!aurEff->IsAffectedOnSpell(spellProto))
            continue;

        switch (aurEff->GetMiscValue())
        {
            case 4415: // Increased Rejuvenation Healing
            case 4953:
            case 3736: // Hateful Totem of the Third Wind / Increased Lesser Healing Wave / LK Arena (4/5/6) Totem of the Third Wind / Savage Totem of the Third Wind
                DoneTotal += aurEff->GetAmount();
                break;
            default:
                break;
        }
    }

    // Custom scripted damage
    switch (spellProto->SpellFamilyName)
    {
        case SPELLFAMILY_DEATHKNIGHT:
            // Impurity (dummy effect)
            if (GetTypeId() == TYPEID_PLAYER)
            {
                PlayerSpellMap const& playerSpells = ToPlayer()->GetSpellMap();
                for (auto itr = playerSpells.begin(); itr != playerSpells.end(); ++itr)
                {
                    if (itr->second.state == PLAYERSPELL_REMOVED || itr->second.disabled)
                        continue;

                    switch (itr->first)
                    {
                        case 49220:
                        case 49633:
                        case 49635:
                        case 49636:
                        case 49638:
                            if (SpellInfo const* proto = sSpellMgr->GetSpellInfo(itr->first))
                                AddPct(ApCoeffMod, proto->GetEffect(EFFECT_0).CalcValue());
                            break;
                    }
                }
            }
            break;
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
    float coeff = spellEffectInfo.BonusMultiplier;
    if (SpellBonusEntry const* bonus = sSpellMgr->GetSpellBonusData(spellProto->Id))
    {
        WeaponAttackType const attType = (spellProto->IsRangedWeaponSpell() && spellProto->DmgClass != SPELL_DAMAGE_CLASS_MELEE) ? RANGED_ATTACK : BASE_ATTACK;
        float APbonus = float(victim->GetTotalAuraModifier(attType == BASE_ATTACK ? SPELL_AURA_MELEE_ATTACK_POWER_ATTACKER_BONUS : SPELL_AURA_RANGED_ATTACK_POWER_ATTACKER_BONUS));
        APbonus += GetTotalAttackPowerValue(attType);

        if (damagetype == DOT)
        {
            coeff = bonus->dot_damage;
            if (bonus->ap_dot_bonus > 0)
                DoneTotal += int32(bonus->ap_dot_bonus * stack * ApCoeffMod * APbonus);
        }
        else
        {
            coeff = bonus->direct_damage;
            if (bonus->ap_bonus > 0)
                DoneTotal += int32(bonus->ap_bonus * stack * ApCoeffMod * APbonus);
        }
    }
    else
    {
        // No bonus healing for SPELL_DAMAGE_CLASS_NONE class spells by default
        if (spellProto->DmgClass == SPELL_DAMAGE_CLASS_NONE)
            return uint32(std::max(healamount * DoneTotalMod, 0.0f));
    }

    // Default calculation
    if (DoneAdvertisedBenefit)
    {
        if (coeff < 0.f)
            coeff = CalculateDefaultCoefficient(spellProto, damagetype) * 1.88f;  // As wowwiki says: C = (Cast Time / 3.5) * 1.88 (for healing spells)

        float factorMod = CalculateSpellpowerCoefficientLevelPenalty(spellProto) * stack;
        if (Player* modOwner = GetSpellModOwner())
        {
            coeff *= 100.0f;
            modOwner->ApplySpellMod(spellProto->Id, SPELLMOD_BONUS_MULTIPLIER, coeff);
            coeff /= 100.0f;
        }

        DoneTotal += int32(DoneAdvertisedBenefit * coeff * factorMod);
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

    float heal = float(int32(healamount) + DoneTotal) * DoneTotalMod;

    // apply spellmod to Done amount
    if (Player* modOwner = GetSpellModOwner())
        modOwner->ApplySpellMod(spellProto->Id, damagetype == DOT ? SPELLMOD_DOT : SPELLMOD_DAMAGE, heal);

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
    if (spellProto->HasAttribute(SPELL_ATTR6_LIMIT_PCT_HEALING_MODS))
        return 1.0f;

    // No bonus healing for potion spells
    if (spellProto->SpellFamilyName == SPELLFAMILY_POTION)
        return 1.0f;

    float DoneTotalMod = 1.0f;

    // Healing done percent
    DoneTotalMod *= GetTotalAuraMultiplier(SPELL_AURA_MOD_HEALING_DONE_PERCENT);

    // done scripted mod (take it from owner)
    Unit const* owner = GetOwner() ? GetOwner() : this;
    AuraEffectList const& mOverrideClassScript= owner->GetAuraEffectsByType(SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
    for (AuraEffect const* aurEff : mOverrideClassScript)
    {
        if (!aurEff->IsAffectedOnSpell(spellProto))
            continue;

        switch (aurEff->GetMiscValue())
        {
            case   21: // Test of Faith
            case 6935:
            case 6918:
                if (victim->HealthBelowPct(50))
                    AddPct(DoneTotalMod, aurEff->GetAmount());
                break;
            case 7798: // Glyph of Regrowth
            {
                if (victim->GetAuraEffect(SPELL_AURA_PERIODIC_HEAL, SPELLFAMILY_DRUID, 0x40, 0, 0))
                    AddPct(DoneTotalMod, aurEff->GetAmount());
                break;
            }
            case 8477: // Nourish Heal Boost
            {
                int32 stepPercent = aurEff->GetAmount();
                int32 modPercent = 0;
                AuraApplicationMap const& victimAuras = victim->GetAppliedAuras();
                for (AuraApplicationMap::const_iterator itr = victimAuras.begin(); itr != victimAuras.end(); ++itr)
                {
                    Aura const* aura = itr->second->GetBase();
                    if (aura->GetCasterGUID() != GetGUID())
                        continue;

                    SpellInfo const* m_spell = aura->GetSpellInfo();
                    if (m_spell->SpellFamilyName != SPELLFAMILY_DRUID ||
                        !(m_spell->SpellFamilyFlags[1] & 0x00000010 || m_spell->SpellFamilyFlags[0] & 0x50))
                        continue;
                    modPercent += stepPercent * aura->GetStackAmount();
                }
                AddPct(DoneTotalMod, modPercent);
                break;
            }
            case 7871: // Glyph of Lesser Healing Wave
            {
                if (victim->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_SHAMAN, 0, 0x00000400, 0))
                    AddPct(DoneTotalMod, aurEff->GetAmount());
                break;
            }
            default:
                break;
        }
    }

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
        if (GetAuraEffect(SPELL_AURA_PERIODIC_HEAL, SPELLFAMILY_DRUID, 0x50, 0x4000010, 0))
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
            if (caster->GetGUID() == aurEff->GetCasterGUID() && aurEff->IsAffectedOnSpell(spellProto))
                return true;
            return false;
        });
    }

    float heal = healamount * TakenTotalMod;
    return uint32(std::max(heal, 0.0f));
}

int32 Unit::SpellBaseHealingBonusDone(SpellSchoolMask schoolMask) const
{
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

        // Healing bonus from stats
        AuraEffectList const& mHealingDoneOfStatPercent = GetAuraEffectsByType(SPELL_AURA_MOD_SPELL_HEALING_OF_STAT_PERCENT);
        for (AuraEffectList::const_iterator i = mHealingDoneOfStatPercent.begin(); i != mHealingDoneOfStatPercent.end(); ++i)
        {
            // stat used dependent from misc value (stat index)
            Stats usedStat = Stats((*i)->GetSpellEffectInfo().MiscValue);
            advertisedBenefit += int32(CalculatePct(GetStat(usedStat), (*i)->GetAmount()));
        }

        // ... and attack power
        AuraEffectList const& mHealingDonebyAP = GetAuraEffectsByType(SPELL_AURA_MOD_SPELL_HEALING_OF_ATTACK_POWER);
        for (AuraEffectList::const_iterator i = mHealingDonebyAP.begin(); i != mHealingDonebyAP.end(); ++i)
            if ((*i)->GetMiscValue() & schoolMask)
                advertisedBenefit += int32(CalculatePct(GetTotalAttackPowerValue(BASE_ATTACK), (*i)->GetAmount()));
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
            if ((itr->first & schoolMask) && !spellInfo->CanPierceImmuneAura(sSpellMgr->GetSpellInfo(itr->second)))
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
            if (SpellInfo const* immunitySourceSpell = sSpellMgr->GetSpellInfo(entry.second))
                if (immunitySourceSpell->HasAttribute(SPELL_ATTR1_DISPEL_AURAS_ON_IMMUNITY))
                    return true;

            return false;
        });
    };

    // Single spell immunity.
    SpellImmuneContainer const& idList = m_spellImmune[IMMUNITY_ID];
    if (hasImmunity(idList, spellInfo->Id))
        return true;

    if (spellInfo->HasAttribute(SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY))
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

            SpellInfo const* immuneSpellInfo = sSpellMgr->GetSpellInfo(itr->second);
            if (requireImmunityPurgesEffectAttribute)
                if (!immuneSpellInfo || !immuneSpellInfo->HasAttribute(SPELL_ATTR1_DISPEL_AURAS_ON_IMMUNITY))
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

uint32 Unit::GetMechanicImmunityMask() const
{
    uint32 mask = 0;
    SpellImmuneContainer const& mechanicList = m_spellImmune[IMMUNITY_MECHANIC];
    for (auto itr = mechanicList.begin(); itr != mechanicList.end(); ++itr)
        mask |= (1 << itr->first);

    return mask;
}

bool Unit::IsImmunedToSpellEffect(SpellInfo const* spellInfo, SpellEffectInfo const& spellEffectInfo, WorldObject const* caster,
    bool requireImmunityPurgesEffectAttribute /*= false*/) const
{
    if (!spellInfo || !spellEffectInfo.IsEffect())
        return false;

    if (spellInfo->HasAttribute(SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY))
        return false;

    auto hasImmunity = [requireImmunityPurgesEffectAttribute](SpellImmuneContainer const& container, uint32 key)
    {
        Trinity::IteratorPair<SpellImmuneContainer::const_iterator> range = Trinity::Containers::MapEqualRange(container, key);
        if (!requireImmunityPurgesEffectAttribute)
            return range.begin() != range.end();

        return std::any_of(range.begin(), range.end(), [](SpellImmuneContainer::value_type const& entry)
        {
            if (SpellInfo const* immunitySourceSpell = sSpellMgr->GetSpellInfo(entry.second))
                if (immunitySourceSpell->HasAttribute(SPELL_ATTR1_DISPEL_AURAS_ON_IMMUNITY))
                    return true;

            return false;
        });
    };

    // If m_immuneToEffect type contain this effect type, IMMUNE effect.
    SpellImmuneContainer const& effectList = m_spellImmune[IMMUNITY_EFFECT];
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
        if (!spellInfo->HasAttribute(SPELL_ATTR3_IGNORE_HIT_RESULT))
        {
            SpellImmuneContainer const& list = m_spellImmune[IMMUNITY_STATE];
            if (hasImmunity(list, aura))
                return true;
        }

        if (!spellInfo->HasAttribute(SPELL_ATTR2_UNAFFECTED_BY_AURA_SCHOOL_IMMUNE))
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

uint32 Unit::MeleeDamageBonusDone(Unit* victim, uint32 pdamage, WeaponAttackType attType, SpellInfo const* spellProto /*= nullptr*/, SpellSchoolMask damageSchoolMask /*= SPELL_SCHOOL_MASK_NORMAL*/)
{
    if (!victim || pdamage == 0)
        return 0;

    uint32 creatureTypeMask = victim->GetCreatureTypeMask();

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
        APbonus += victim->GetTotalAuraModifier(SPELL_AURA_RANGED_ATTACK_POWER_ATTACKER_BONUS);

        // ..done (base at attack power and creature type)
        APbonus += GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_RANGED_ATTACK_POWER_VERSUS, creatureTypeMask);
    }
    else
    {
        APbonus += victim->GetTotalAuraModifier(SPELL_AURA_MELEE_ATTACK_POWER_ATTACKER_BONUS);

        // ..done (base at attack power and creature type)
        APbonus += GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_MELEE_ATTACK_POWER_VERSUS, creatureTypeMask);
    }

    if (APbonus != 0)                                       // Can be negative
    {
        bool const normalized = spellProto && spellProto->HasEffect(SPELL_EFFECT_NORMALIZED_WEAPON_DMG);
        DoneFlatBenefit += int32(APbonus / 14.0f * GetAPMultiplier(attType, normalized));
    }

    // Done total percent damage auras
    float DoneTotalMod = 1.0f;

    SpellSchoolMask schoolMask = spellProto ? spellProto->GetSchoolMask() : damageSchoolMask;

    // mods for SPELL_SCHOOL_MASK_NORMAL are already factored in base melee damage calculation
    if (!(schoolMask & SPELL_SCHOOL_MASK_NORMAL))
    {
        // Some spells don't benefit from pct done mods
        if (!spellProto || !spellProto->HasAttribute(SPELL_ATTR6_LIMIT_PCT_DAMAGE_MODS))
        {
            float maxModDamagePercentSchool = 0.0f;
            if (GetTypeId() == TYPEID_PLAYER)
            {
                for (uint32 i = SPELL_SCHOOL_HOLY; i < MAX_SPELL_SCHOOL; ++i)
                    if (schoolMask & (1 << i))
                        maxModDamagePercentSchool = std::max(maxModDamagePercentSchool, GetFloatValue(PLAYER_FIELD_MOD_DAMAGE_DONE_PCT + i));
            }
            else
                maxModDamagePercentSchool = GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, schoolMask);

            DoneTotalMod *= maxModDamagePercentSchool;
        }
    }

    DoneTotalMod *= GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_DAMAGE_DONE_VERSUS, creatureTypeMask);

    // bonus against aurastate
    DoneTotalMod *= GetTotalAuraMultiplier(SPELL_AURA_MOD_DAMAGE_DONE_VERSUS_AURASTATE, [victim](AuraEffect const* aurEff) -> bool
    {
        if (victim->HasAuraState(AuraStateType(aurEff->GetMiscValue())))
            return true;
        return false;
    });

    // done scripted mod (take it from owner)
    Unit* owner = GetOwner() ? GetOwner() : this;
    AuraEffectList const& mOverrideClassScript = owner->GetAuraEffectsByType(SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
    for (AuraEffectList::const_iterator i = mOverrideClassScript.begin(); i != mOverrideClassScript.end(); ++i)
    {
        if (!(*i)->IsAffectedOnSpell(spellProto))
            continue;

        switch ((*i)->GetMiscValue())
        {
            // Tundra Stalker
            // Merciless Combat
            case 7277:
            {
                // Merciless Combat
                if ((*i)->GetSpellInfo()->SpellIconID == 2656)
                {
                    if (!victim->HealthAbovePct(35))
                        AddPct(DoneTotalMod, (*i)->GetAmount());
                }
                // Tundra Stalker
                else
                {
                    // Frost Fever (target debuff)
                    if (victim->HasAura(55095))
                        AddPct(DoneTotalMod, (*i)->GetAmount());
                }
                break;
            }
            // Rage of Rivendare
            case 7293:
            {
                if (victim->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DEATHKNIGHT, 0, 0x02000000, 0))
                    AddPct(DoneTotalMod, (*i)->GetSpellInfo()->GetRank() * 2.0f);
                break;
            }
            // Marked for Death
            case 7598:
            case 7599:
            case 7600:
            case 7601:
            case 7602:
            {
                if (victim->GetAuraEffect(SPELL_AURA_MOD_STALKED, SPELLFAMILY_HUNTER, 0x400, 0, 0))
                    AddPct(DoneTotalMod, (*i)->GetAmount());
                break;
            }
            // Dirty Deeds
            case 6427:
            case 6428:
            {
                if (victim->HasAuraState(AURA_STATE_HEALTHLESS_35_PERCENT, spellProto, this))
                {
                    // effect 0 has expected value but in negative state
                    int32 bonus = -(*i)->GetBase()->GetEffect(0)->GetAmount();
                    AddPct(DoneTotalMod, bonus);
                }
                break;
            }
        }
    }

    // Custom scripted damage
    if (spellProto)
    {
        switch (spellProto->SpellFamilyName)
        {
            case SPELLFAMILY_DEATHKNIGHT:
                // Glacier Rot
                if (spellProto->SpellFamilyFlags[0] & 0x2 || spellProto->SpellFamilyFlags[1] & 0x6)
                    if (AuraEffect* aurEff = GetDummyAuraEffect(SPELLFAMILY_DEATHKNIGHT, 196, 0))
                        if (victim->GetDiseasesByCaster(owner->GetGUID()) > 0)
                            AddPct(DoneTotalMod, aurEff->GetAmount());
                break;
        }
    }

    float tmpDamage = float(int32(pdamage) + DoneFlatBenefit) * DoneTotalMod;

    // bonus result can be negative
    return uint32(std::max(tmpDamage, 0.0f));
}

uint32 Unit::MeleeDamageBonusTaken(Unit* attacker, uint32 pdamage, WeaponAttackType attType, SpellInfo const* spellProto /*= nullptr*/, SpellSchoolMask damageSchoolMask /*= SPELL_SCHOOL_MASK_NORMAL*/)
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

    if ((TakenFlatBenefit < 0) && (pdamage < static_cast<uint32>(-TakenFlatBenefit)))
        return 0;

    // Taken total percent damage auras
    float TakenTotalMod = 1.0f;

    // ..taken
    TakenTotalMod *= GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, attacker->GetMeleeDamageSchoolMask());

    // .. taken pct (special attacks)
    if (spellProto)
    {
        // From caster spells
        TakenTotalMod *= GetTotalAuraMultiplier(SPELL_AURA_MOD_DAMAGE_FROM_CASTER, [attacker, spellProto](AuraEffect const* aurEff) -> bool
        {
            if (aurEff->GetCasterGUID() == attacker->GetGUID() && aurEff->IsAffectedOnSpell(spellProto))
                return true;
            return false;
        });

        // Mod damage from spell mechanic
        uint32 mechanicMask = spellProto->GetAllEffectsMechanicMask();

        // Shred, Maul - "Effects which increase Bleed damage also increase Shred damage"
        if (spellProto->SpellFamilyName == SPELLFAMILY_DRUID && spellProto->SpellFamilyFlags[0] & 0x00008800)
            mechanicMask |= (1 << MECHANIC_BLEED);

        if (mechanicMask)
        {
            TakenTotalMod *= GetTotalAuraMultiplier(SPELL_AURA_MOD_MECHANIC_DAMAGE_TAKEN_PERCENT, [mechanicMask](AuraEffect const* aurEff) -> bool
            {
                if (mechanicMask & uint32(1 << (aurEff->GetMiscValue())))
                    return true;
                return false;
            });
        }
    }

    // .. taken pct: dummy auras
    AuraEffectList const& mDummyAuras = GetAuraEffectsByType(SPELL_AURA_DUMMY);
    for (AuraEffectList::const_iterator i = mDummyAuras.begin(); i != mDummyAuras.end(); ++i)
    {
        switch ((*i)->GetSpellInfo()->SpellIconID)
        {
            // Cheat Death
            case 2109:
                if ((*i)->GetMiscValue() & SPELL_SCHOOL_MASK_NORMAL)
                {
                    // Patch 2.4.3: The resilience required to reach the 90% damage reduction cap
                    //  is 22.5% critical strike damage reduction, or 444 resilience.
                    // To calculate for 90%, we multiply the 100% by 4 (22.5% * 4 = 90%)
                    float mod = -1.0f * GetMeleeCritDamageReduction(400);
                    AddPct(TakenTotalMod, std::max(mod, float((*i)->GetAmount())));
                }
                break;
        }
    }

    // .. taken pct: class scripts
    //*AuraEffectList const& mclassScritAuras = GetAuraEffectsByType(SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
    //for (AuraEffectList::const_iterator i = mclassScritAuras.begin(); i != mclassScritAuras.end(); ++i)
    //{
    //    switch ((*i)->GetMiscValue())
    //    {
    //    }
    //}*/

    if (attType != RANGED_ATTACK)
        TakenTotalMod *= GetTotalAuraMultiplier(SPELL_AURA_MOD_MELEE_DAMAGE_TAKEN_PCT);
    else
        TakenTotalMod *= GetTotalAuraMultiplier(SPELL_AURA_MOD_RANGED_DAMAGE_TAKEN_PCT);

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
        return (GetAttackTime(BASE_ATTACK) * 1.8f / 1000.0f);
    else if (haveOffhandWeapon() && isAttackReady(OFF_ATTACK))
        return (GetAttackTime(OFF_ATTACK) * 1.6f / 1000.0f);
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
            modOwner->ApplySpellMod(spellProto->Id, SPELLMOD_PROC_PER_MINUTE, PPM);

    return std::floor((WeaponSpeed * PPM) / 600.0f);   // result is chance in percents (probability = Speed_in_sec * (PPM / 60))
}

void Unit::Mount(uint32 mount, uint32 VehicleId, uint32 creatureEntry)
{
    if (mount)
        SetMountDisplayId(mount);

    SetUnitFlag(UNIT_FLAG_MOUNT);

    if (Player* player = ToPlayer())
    {
        // mount as a vehicle
        if (VehicleId)
        {
            if (CreateVehicleKit(VehicleId, creatureEntry))
            {
                // Send others that we now have a vehicle
                WorldPacket data(SMSG_PLAYER_VEHICLE_DATA, GetPackGUID().size() + 4);
                data << GetPackGUID();
                data << uint32(VehicleId);
                SendMessageToSet(&data, true);

                data.Initialize(SMSG_ON_CANCEL_EXPECTED_RIDE_VEHICLE_AURA, 0);
                player->SendDirectMessage(&data);

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
                pet->SetUnitFlag(UNIT_FLAG_STUNNED);
            else
                player->UnsummonPetTemporaryIfAny();
        }

        // if we have charmed npc, stun him also (everywhere)
        if (Unit* charm = player->GetCharmed())
            if (charm->GetTypeId() == TYPEID_UNIT)
                charm->SetUnitFlag(UNIT_FLAG_STUNNED);

        WorldPacket data(SMSG_MOVE_SET_COLLISION_HGT, GetPackGUID().size() + 4 + 4);
        data << GetPackGUID();
        data << uint32(GameTime::GetGameTime());   // Packet counter
        data << player->GetCollisionHeight();
        player->SendDirectMessage(&data);
    }

    RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_MOUNT);
}

void Unit::Dismount()
{
    if (!IsMounted())
        return;

    SetMountDisplayId(0);
    RemoveUnitFlag(UNIT_FLAG_MOUNT);

    if (Player* thisPlayer = ToPlayer())
    {
        WorldPacket data(SMSG_MOVE_SET_COLLISION_HGT, GetPackGUID().size() + 4 + 4);
        data << GetPackGUID();
        data << uint32(GameTime::GetGameTime());   // Packet counter
        data << thisPlayer->GetCollisionHeight();
        thisPlayer->SendDirectMessage(&data);
    }

    WorldPacket data(SMSG_DISMOUNT, 8);
    data << GetPackGUID();
    SendMessageToSet(&data, true);

    // dismount as a vehicle
    if (GetTypeId() == TYPEID_PLAYER && GetVehicleKit())
    {
        // Send other players that we are no longer a vehicle
        data.Initialize(SMSG_PLAYER_VEHICLE_DATA, 8 + 4);
        data << GetPackGUID();
        data << uint32(0);
        ToPlayer()->SendMessageToSet(&data, true);
        // Remove vehicle from player
        RemoveVehicleKit();
    }

    RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_NOT_MOUNTED);

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
        if (Unit* charm = player->GetCharmed())
            if (charm->GetTypeId() == TYPEID_UNIT && charm->HasUnitFlag(UNIT_FLAG_STUNNED) && !charm->HasUnitState(UNIT_STATE_STUNNED))
                charm->RemoveUnitFlag(UNIT_FLAG_STUNNED);
    }
}

bool Unit::IsServiceProvider() const
{
    return HasNpcFlag(
        UNIT_NPC_FLAG_VENDOR | UNIT_NPC_FLAG_TRAINER | UNIT_NPC_FLAG_FLIGHTMASTER |
        UNIT_NPC_FLAG_PETITIONER | UNIT_NPC_FLAG_BATTLEMASTER | UNIT_NPC_FLAG_BANKER |
        UNIT_NPC_FLAG_INNKEEPER | UNIT_NPC_FLAG_SPIRITHEALER |
        UNIT_NPC_FLAG_SPIRITGUIDE | UNIT_NPC_FLAG_TABARDDESIGNER | UNIT_NPC_FLAG_AUCTIONEER);
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

bool Unit::IsThreatened() const
{
    return !m_threatManager.IsThreatListEmpty();
}

bool Unit::isTargetableForAttack(bool checkFakeDeath) const
{
    if (!IsAlive())
        return false;

    if (HasUnitFlag(        UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_UNINTERACTIBLE))
        return false;

    if (GetTypeId() == TYPEID_PLAYER && ToPlayer()->IsGameMaster())
        return false;

    return !HasUnitState(UNIT_STATE_UNATTACKABLE) && (!checkFakeDeath || !HasUnitState(UNIT_STATE_DIED));
}

int32 Unit::ModifyHealth(int32 dVal)
{
    int32 gain = 0;

    if (dVal == 0)
        return 0;

    int32 curHealth = (int32)GetHealth();

    int32 val = dVal + curHealth;
    if (val <= 0)
    {
        SetHealth(0);
        return -curHealth;
    }

    int32 maxHealth = (int32)GetMaxHealth();

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

    return gain;
}

int32 Unit::GetHealthGain(int32 dVal)
{
    int32 gain = 0;

    if (dVal == 0)
        return 0;

    int32 curHealth = (int32)GetHealth();

    int32 val = dVal + curHealth;
    if (val <= 0)
    {
        return -curHealth;
    }

    int32 maxHealth = (int32)GetMaxHealth();

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

    int32 curPower = (int32)GetPower(power);

    int32 val = dVal + curPower;
    if (val <= 0)
    {
        SetPower(power, 0, withPowerUpdate);
        return -curPower;
    }

    int32 maxPower = (int32)GetMaxPower(power);

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

uint32 Unit::GetAttackTime(WeaponAttackType att) const
{
    float f_BaseAttackTime = GetFloatValue(UNIT_FIELD_BASEATTACKTIME + AsUnderlyingType(att)) / m_modAttackSpeedPct[att];
    return (uint32)f_BaseAttackTime;
}

bool Unit::IsAlwaysVisibleFor(WorldObject const* seer) const
{
    if (WorldObject::IsAlwaysVisibleFor(seer))
        return true;

    // Always seen by owner
    if (ObjectGuid guid = GetCharmerOrOwnerGUID())
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
    if (rate < 0)
        rate = 0.0f;

    // Update speed only on change
    MovementChangeType changeType = MovementPacketSender::GetChangeTypeByMoveType(mtype);
    if (m_speed_rate[mtype] == rate && !HasPendingMovementChange(changeType)) //todo: is the "!HasPendingMovementChange" part necessary here?
        return;

    float newSpeedFlat = rate * (IsControlledByPlayer() ? playerBaseMoveSpeed[mtype] : baseMoveSpeed[mtype]);
    if (IsMovedByClient() && IsInWorld())
        MovementPacketSender::SendSpeedChangeToMover(this, mtype, newSpeedFlat);
    else if (IsMovedByClient() && !IsInWorld()) // (1)
        SetSpeedRateReal(mtype, rate);
    else // <=> if(!IsMovedByPlayer())
    {
        SetSpeedRateReal(mtype, rate);
        MovementPacketSender::SendSpeedChangeToAll(this, mtype, newSpeedFlat);
    }

    // explaination of (1):
    // If the player is not in the world yet, it won't reply to the packets requiring an ack. And once the player is in the world, next time a movement
    // packet which requires an ack is sent to the client (change of speed for example), the client is kicked from the
    // server on the ground that it should have replied to the first packet first. That line is a hacky fix
    // in the sense that it doesn't work like that in retail since buffs are applied only after the player has been
    // initialized in the world. cf description of PR #18771
}

void Unit::SetSpeedRateReal(UnitMoveType mtype, float rate)
{
    if (!IsInCombat() && ToPlayer())
        if (Pet* pet = ToPlayer()->GetPet())
            pet->SetSpeedRate(mtype, rate);

    m_speed_rate[mtype] = rate;
    PropagateSpeedChange();
}

void Unit::RemoveAllFollowers()
{
    while (!m_followingMe.empty())
        (*m_followingMe.begin())->SetTarget(nullptr);
}

bool Unit::IsGhouled() const
{
    return HasAura(SPELL_DK_RAISE_ALLY);
}

void Unit::setDeathState(DeathState s)
{
    // Death state needs to be updated before RemoveAllAurasOnDeath() is called, to prevent entering combat
    m_deathState = s;

    bool isOnVehicle = GetVehicle() != nullptr;

    if (s != ALIVE && s != JUST_RESPAWNED)
    {
        CombatStop();
        ClearComboPointHolders();                           // any combo points pointed to unit lost at it death

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

        // players in instance don't have ZoneScript, but they have InstanceScript
        if (ZoneScript* zoneScript = GetZoneScript() ? GetZoneScript() : GetInstanceScript())
            zoneScript->OnUnitDeath(this);
    }
    else if (s == JUST_RESPAWNED)
        RemoveUnitFlag(UNIT_FLAG_SKINNABLE); // clear skinnable for creature and player (at battleground)
}

//======================================================================

void Unit::AtExitCombat()
{
    RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_LEAVE_COMBAT);
}

void Unit::AtTargetAttacked(Unit* target, bool canInitialAggro)
{
    if (!target->IsEngaged() && !canInitialAggro)
        return;
    target->EngageWithTarget(this);
    if (Unit* targetOwner = target->GetCharmerOrOwner())
        targetOwner->EngageWithTarget(this);

    //Patch 3.0.8: All player spells which cause a creature to become aggressive to you will now also immediately cause the creature to be tapped.
    if (Creature* creature = target->ToCreature())
        if (!creature->hasLootRecipient() && GetTypeId() == TYPEID_PLAYER)
            creature->SetLootRecipient(this);

    Player* myPlayerOwner = GetCharmerOrOwnerPlayerOrPlayerItself();
    Player* targetPlayerOwner = target->GetCharmerOrOwnerPlayerOrPlayerItself();
    if (myPlayerOwner && targetPlayerOwner && !(myPlayerOwner->duel && myPlayerOwner->duel->Opponent == targetPlayerOwner))
    {
        myPlayerOwner->UpdatePvP(true);
        myPlayerOwner->SetContestedPvP(targetPlayerOwner);
        myPlayerOwner->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_ENTER_PVP_COMBAT);
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

//======================================================================

DiminishingLevels Unit::GetDiminishing(DiminishingGroup group) const
{
    DiminishingReturn const& diminish = m_Diminishing[group];
    if (!diminish.hitCount)
        return DIMINISHING_LEVEL_1;

    // If last spell was cast more than 15 seconds ago - reset level
    if (!diminish.stack && GetMSTimeDiffToNow(diminish.hitTime) > 15000)
        return DIMINISHING_LEVEL_1;

    return DiminishingLevels(diminish.hitCount);
}

void Unit::IncrDiminishing(SpellInfo const* auraSpellInfo, bool triggered)
{
    DiminishingGroup group = auraSpellInfo->GetDiminishingReturnsGroupForSpell(triggered);
    uint32 currentLevel = GetDiminishing(group);
    uint32 const maxLevel = auraSpellInfo->GetDiminishingReturnsMaxLevel(triggered);

    DiminishingReturn& diminish = m_Diminishing[group];
    if (currentLevel < maxLevel)
        diminish.hitCount = currentLevel + 1;
}

bool Unit::ApplyDiminishingToDuration(SpellInfo const* auraSpellInfo, bool triggered, int32& duration, WorldObject* caster, DiminishingLevels previousLevel) const
{
    DiminishingGroup const group = auraSpellInfo->GetDiminishingReturnsGroupForSpell(triggered);
    if (duration == -1 || group == DIMINISHING_NONE)
        return true;

    int32 const limitDuration = auraSpellInfo->GetDiminishingReturnsLimitDuration(triggered);

    // test pet/charm masters instead pets/charmeds
    Unit const* targetOwner = GetCharmerOrOwner();
    Unit const* casterOwner = caster->GetCharmerOrOwner();

    // Duration of crowd control abilities on pvp target is limited by 10 sec. (2.2.0)
    if (limitDuration > 0 && duration > limitDuration)
    {
        Unit const* target = targetOwner ? targetOwner : this;
        WorldObject const* source = casterOwner ? casterOwner : caster;

        if (target->IsAffectedByDiminishingReturns() && source->GetTypeId() == TYPEID_PLAYER)
            duration = limitDuration;
    }

    float mod = 1.0f;
    if (group == DIMINISHING_TAUNT)
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
    }
    // Some diminishings applies to mobs too (for example, Stun)
    else if (auraSpellInfo->GetDiminishingReturnsGroupType(triggered) == DRTYPE_ALL ||
        (auraSpellInfo->GetDiminishingReturnsGroupType(triggered) == DRTYPE_PLAYER &&
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
    SetByteValue(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_SHAPESHIFT_FORM, form);
}

bool Unit::IsInFeralForm() const
{
    ShapeshiftForm form = GetShapeshiftForm();
    return form == FORM_CAT || form == FORM_BEAR || form == FORM_DIREBEAR;
}

bool Unit::IsInDisallowedMountForm() const
{
    if (SpellInfo const* transformSpellInfo = sSpellMgr->GetSpellInfo(GetTransformSpell()))
        if (transformSpellInfo->HasAttribute(SPELL_ATTR0_CASTABLE_WHILE_MOUNTED))
            return false;

    if (ShapeshiftForm form = GetShapeshiftForm())
    {
        SpellShapeshiftFormEntry const* shapeshift = sSpellShapeshiftFormStore.LookupEntry(form);
        if (!shapeshift)
            return true;

        if (!(shapeshift->Flags & 0x1))
            return true;
    }

    if (GetDisplayId() == GetNativeDisplayId())
        return false;

    CreatureDisplayInfoEntry const* display = sCreatureDisplayInfoStore.LookupEntry(GetDisplayId());
    if (!display)
        return true;

    CreatureDisplayInfoExtraEntry const* displayExtra = sCreatureDisplayInfoExtraStore.LookupEntry(display->ExtendedDisplayInfoID);
    if (!displayExtra)
        return true;

    CreatureModelDataEntry const* model = sCreatureModelDataStore.LookupEntry(display->ModelID);
    ChrRacesEntry const* race = sChrRacesStore.LookupEntry(displayExtra->DisplayRaceID);

    if (model && !(model->HasFlag(CREATURE_MODEL_DATA_FLAGS_CAN_MOUNT)))
        if (race && !(race->HasFlag(CHRRACES_FLAGS_CAN_MOUNT)))
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
        case UNIT_MOD_STAT_INTELLECT:
        case UNIT_MOD_STAT_SPIRIT:         UpdateStats(GetStatByAuraGroup(unitMod));  break;

        case UNIT_MOD_ARMOR:               UpdateArmor();           break;
        case UNIT_MOD_HEALTH:              UpdateMaxHealth();       break;

        case UNIT_MOD_MANA:
        case UNIT_MOD_RAGE:
        case UNIT_MOD_FOCUS:
        case UNIT_MOD_ENERGY:
        case UNIT_MOD_HAPPINESS:
        case UNIT_MOD_RUNE:
        case UNIT_MOD_RUNIC_POWER:          UpdateMaxPower(GetPowerTypeByAuraGroup(unitMod));          break;

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
    UnitMods unitMod = UnitMods(UNIT_MOD_STAT_START + AsUnderlyingType(stat));

    // value = ((base_value * base_pct) + total_value) * total_pct
    float value  = GetFlatModifierValue(unitMod, BASE_VALUE) + GetCreateStat(stat);
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

    float value = GetFlatModifierValue(unitMod, BASE_VALUE);
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
        case UNIT_MOD_STAT_SPIRIT:      stat = STAT_SPIRIT;        break;

        default:
            break;
    }

    return stat;
}

Powers Unit::GetPowerTypeByAuraGroup(UnitMods unitMod) const
{
    switch (unitMod)
    {
        case UNIT_MOD_RAGE:        return POWER_RAGE;
        case UNIT_MOD_FOCUS:       return POWER_FOCUS;
        case UNIT_MOD_ENERGY:      return POWER_ENERGY;
        case UNIT_MOD_HAPPINESS:   return POWER_HAPPINESS;
        case UNIT_MOD_RUNE:        return POWER_RUNE;
        case UNIT_MOD_RUNIC_POWER: return POWER_RUNIC_POWER;
        default:
        case UNIT_MOD_MANA:        return POWER_MANA;
    }
}

float Unit::GetTotalAttackPowerValue(WeaponAttackType attType) const
{
    if (attType == RANGED_ATTACK)
    {
        int32 ap = GetInt32Value(UNIT_FIELD_RANGED_ATTACK_POWER) + int16(GetUInt16Value(UNIT_FIELD_RANGED_ATTACK_POWER_MODS, 0)) + int16(GetUInt16Value(UNIT_FIELD_RANGED_ATTACK_POWER_MODS, 1));
        if (ap < 0)
            return 0.0f;
        return ap * (1.0f + GetFloatValue(UNIT_FIELD_RANGED_ATTACK_POWER_MULTIPLIER));
    }
    else
    {
        int32 ap = GetInt32Value(UNIT_FIELD_ATTACK_POWER) + int16(GetUInt16Value(UNIT_FIELD_ATTACK_POWER_MODS, 0)) + int16(GetUInt16Value(UNIT_FIELD_ATTACK_POWER_MODS, 1));
        if (ap < 0)
            return 0.0f;
        return ap * (1.0f + GetFloatValue(UNIT_FIELD_ATTACK_POWER_MULTIPLIER));
    }
}

float Unit::GetWeaponDamageRange(WeaponAttackType attType, WeaponDamageRange type, uint8 damageIndex /*= 0*/) const
{
    if (attType == OFF_ATTACK && !haveOffhandWeapon())
        return 0.0f;

    return m_weaponDamage[attType][type][damageIndex];
}

bool Unit::CanFreeMove() const
{
    return !HasUnitState(UNIT_STATE_CONFUSED | UNIT_STATE_FLEEING | UNIT_STATE_IN_FLIGHT |
        UNIT_STATE_ROOT | UNIT_STATE_STUNNED | UNIT_STATE_DISTRACTED) && GetOwnerGUID().IsEmpty();
}

void Unit::SetLevel(uint8 lvl, bool sendUpdate/* = true*/)
{
    SetUInt32Value(UNIT_FIELD_LEVEL, lvl);

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

void Unit::SetHealth(uint32 val)
{
    if (getDeathState() == JUST_DIED || getDeathState() == CORPSE)
        val = 0;
    else if (GetTypeId() == TYPEID_PLAYER && getDeathState() == DEAD)
        val = 1;
    else
    {
        uint32 maxHealth = GetMaxHealth();
        if (maxHealth < val)
            val = maxHealth;
    }

    SetUInt32Value(UNIT_FIELD_HEALTH, val);

    // group update
    if (Player* player = ToPlayer())
    {
        if (player->GetGroup())
            player->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_CUR_HP);
    }
    else if (Pet* pet = ToCreature()->ToPet())
    {
        if (pet->isControlled())
        {
            Unit* owner = GetOwner();
            if (owner && (owner->GetTypeId() == TYPEID_PLAYER) && owner->ToPlayer()->GetGroup())
                owner->ToPlayer()->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_PET_CUR_HP);
        }
    }
}

void Unit::SetMaxHealth(uint32 val)
{
    if (!val)
        val = 1;

    uint32 health = GetHealth();
    SetUInt32Value(UNIT_FIELD_MAXHEALTH, val);

    // group update
    if (GetTypeId() == TYPEID_PLAYER)
    {
        if (ToPlayer()->GetGroup())
            ToPlayer()->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_MAX_HP);
    }
    else if (Pet* pet = ToCreature()->ToPet())
    {
        if (pet->isControlled())
        {
            Unit* owner = GetOwner();
            if (owner && (owner->GetTypeId() == TYPEID_PLAYER) && owner->ToPlayer()->GetGroup())
                owner->ToPlayer()->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_PET_MAX_HP);
        }
    }

    if (val < health)
        SetHealth(val);
}

void Unit::SetPower(Powers power, uint32 val, bool withPowerUpdate /*= true*/, bool force /*= false*/)
{
    if (!force && GetPower(power) == val)
        return;

    uint32 maxPower = GetMaxPower(power);
    if (maxPower < val)
        val = maxPower;

    SetStatInt32Value(UNIT_FIELD_POWER1 + AsUnderlyingType(power), val);

    if (withPowerUpdate)
    {
        WorldPacket data(SMSG_POWER_UPDATE, 8 + 1 + 4);
        data << GetPackGUID();
        data << uint8(power);
        data << uint32(val);
        SendMessageToSet(&data, GetTypeId() == TYPEID_PLAYER);
    }

    // group update
    if (Player* player = ToPlayer())
    {
        if (player->GetGroup())
            player->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_CUR_POWER);
    }
    else if (Pet* pet = ToCreature()->ToPet())
    {
        if (pet->isControlled())
        {
            Unit* owner = GetOwner();
            if (owner && (owner->GetTypeId() == TYPEID_PLAYER) && owner->ToPlayer()->GetGroup())
                owner->ToPlayer()->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_PET_CUR_POWER);
        }

        // Update the pet's character sheet with happiness damage bonus
        if (pet->getPetType() == HUNTER_PET && power == POWER_HAPPINESS)
            pet->UpdateDamagePhysical(BASE_ATTACK);
    }
}

void Unit::SetMaxPower(Powers power, uint32 val)
{
    uint32 cur_power = GetPower(power);
    SetStatInt32Value(UNIT_FIELD_MAXPOWER1 + AsUnderlyingType(power), val);

    // group update
    if (GetTypeId() == TYPEID_PLAYER)
    {
        if (ToPlayer()->GetGroup())
            ToPlayer()->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_MAX_POWER);
    }
    else if (Pet* pet = ToCreature()->ToPet())
    {
        if (pet->isControlled())
        {
            Unit* owner = GetOwner();
            if (owner && (owner->GetTypeId() == TYPEID_PLAYER) && owner->ToPlayer()->GetGroup())
                owner->ToPlayer()->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_PET_MAX_POWER);
        }
    }

    if (val < cur_power)
        SetPower(power, val);
}

uint32 Unit::GetCreatePowerValue(Powers power) const
{
    // Only hunter pets have POWER_FOCUS and POWER_HAPPINESS
    switch (power)
    {
        case POWER_MANA:
            return GetCreateMana();
        case POWER_RAGE:
            return 1000;
        case POWER_FOCUS:
            return (GetTypeId() != TYPEID_UNIT || !ToCreature()->IsPet() || ToPet()->getPetType() != HUNTER_PET) ? 0 : 100;
        case POWER_ENERGY:
            return 100;
        case POWER_HAPPINESS:
            return (GetTypeId() != TYPEID_UNIT || !ToCreature()->IsPet() || ToPet()->getPetType() != HUNTER_PET) ? 0 : 1050000;
        case POWER_RUNIC_POWER:
            return 1000;
        case POWER_RUNE:
        case POWER_HEALTH:
            return 0;
        default:
            break;
    }

    return 0;
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
        return new ScheduledChangeAI(creature);
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
    if (IsInWorld())
        return;

    WorldObject::AddToWorld();
    i_motionMaster->AddToWorld();
}

void Unit::RemoveFromWorld()
{
    // cleanup
    ASSERT(GetGUID());

    if (IsInWorld())
    {
        m_duringRemoveFromWorld = true;
        if (UnitAI* ai = GetAI())
            ai->OnDespawn();

        if (IsVehicle())
            RemoveVehicleKit();

        RemoveCharmAuras();
        RemoveBindSightAuras();
        RemoveNotOwnSingleTargetAuras();

        RemoveAllGameObjects();
        RemoveAllDynObjects();

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

    if (IsInWorld())
        RemoveFromWorld();
    else
    {
        // cleanup that must happen even if not in world
        if (IsVehicle())
            RemoveVehicleKit();
    }

    ASSERT(GetGUID());

    // A unit may be in removelist and not in world, but it is still in grid
    // and may have some references during delete
    RemoveAllAuras();
    RemoveAllGameObjects();

    if (finalCleanup)
        m_cleanupDone = true;

    m_Events.KillAllEvents(false);                      // non-delatable (currently cast spells) will not deleted now but it will deleted at call in Map::RemoveAllObjectsInRemoveList
    CombatStop();
    ClearComboPoints();
    ClearComboPointHolders();
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
                newAI = new PossessedAI(ToCreature());
            else
                newAI = new PetAI(ToCreature());
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

    if (Creature* creature = _unit->ToCreature())
    {
        _oldReactState = creature->GetReactState();
        creature->SetReactState(REACT_PASSIVE);
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
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
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
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);

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

    std::vector<std::string_view> tokens = Trinity::Tokenize(data, ' ', false);
    if (tokens.size() != (ACTION_BAR_INDEX_END-ACTION_BAR_INDEX_START) * 2)
        return;                                             // non critical, will reset to default

    auto iter = tokens.begin();
    for (uint8 index = ACTION_BAR_INDEX_START; index < ACTION_BAR_INDEX_END; ++index)
    {
        Optional<uint8> type = Trinity::StringTo<uint8>(*(iter++));
        Optional<uint32> action = Trinity::StringTo<uint32>(*(iter++));

        if (!type || !action)
            continue;

        PetActionBar[index].SetActionAndType(*action, static_cast<ActiveStates>(*type));

        // check correctness
        if (PetActionBar[index].IsActionBarForSpell())
        {
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(PetActionBar[index].GetAction());
            if (!spellInfo)
                SetActionBar(index, 0, ACT_PASSIVE);
            else if (!spellInfo->IsAutocastable())
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

void Unit::ProcSkillsAndReactives(bool isVictim, Unit* procTarget, uint32 typeMask, uint32 hitMask, WeaponAttackType attType)
{
    // Player is loaded now - do not allow passive spell casts to proc
    if (GetTypeId() == TYPEID_PLAYER && ToPlayer()->GetSession()->PlayerLoading())
        return;

    // For melee/ranged based attack need update skills and set some Aura states if victim present
    if (typeMask & MELEE_BASED_TRIGGER_MASK && procTarget)
    {
        // Update skills here for players
        // only when you are not fighting other players or their pets/totems (pvp)
        if (GetTypeId() == TYPEID_PLAYER &&
                procTarget->GetTypeId() != TYPEID_PLAYER &&
                !(procTarget->IsTotem() && procTarget->ToTotem()->GetOwner()->IsPlayer()) &&
                !procTarget->IsPet()
           )
        {
            // On melee based hit/miss/resist need update skill (for victim and attacker)
            if (hitMask & (PROC_HIT_NORMAL | PROC_HIT_MISS | PROC_HIT_FULL_RESIST))
            {
                if (procTarget->GetTypeId() != TYPEID_PLAYER && !procTarget->IsCritter())
                    ToPlayer()->UpdateCombatSkills(procTarget, attType, isVictim);
            }
            // Update defense if player is victim and parry/dodge/block
            else if (isVictim && (hitMask & (PROC_HIT_DODGE | PROC_HIT_PARRY | PROC_HIT_BLOCK)))
                ToPlayer()->UpdateCombatSkills(procTarget, attType, true);
        }
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
                        ModifyAuraState(AURA_STATE_DEFENSE, true);
                        StartReactiveTimer(REACTIVE_DEFENSE);
                    }
                }
                // if victim and parry attack
                if (hitMask & PROC_HIT_PARRY)
                {
                    // For Hunters only Counterattack (skip Mongoose bite)
                    if (GetClass() == CLASS_HUNTER)
                    {
                        ModifyAuraState(AURA_STATE_HUNTER_PARRY, true);
                        StartReactiveTimer(REACTIVE_HUNTER_PARRY);
                    }
                    else
                    {
                        ModifyAuraState(AURA_STATE_DEFENSE, true);
                        StartReactiveTimer(REACTIVE_DEFENSE);
                    }
                }
                // if and victim block attack
                if (hitMask & PROC_HIT_BLOCK)
                {
                    ModifyAuraState(AURA_STATE_DEFENSE, true);
                    StartReactiveTimer(REACTIVE_DEFENSE);
                }
            }
            else // For attacker
            {
                // Overpower on victim dodge
                if ((hitMask & PROC_HIT_DODGE) && GetTypeId() == TYPEID_PLAYER && GetClass() == CLASS_WARRIOR)
                {
                    AddComboPoints(procTarget, 1);
                    StartReactiveTimer(REACTIVE_OVERPOWER);
                }
                else if ((hitMask & PROC_HIT_CRITICAL) && IsHunterPet())
                {
                    AddComboPoints(procTarget, 1);
                    StartReactiveTimer(REACTIVE_WOLVERINE_BITE);
                }
            }
        }
    }
}

void Unit::GetProcAurasTriggeredOnEvent(AuraApplicationProcContainer& aurasTriggeringProc, AuraApplicationList* procAuras, ProcEventInfo& eventInfo)
{
    TimePoint now = GameTime::Now();

    // use provided list of auras which can proc
    if (procAuras)
    {
        for (AuraApplication* aurApp : *procAuras)
        {
            ASSERT(aurApp->GetTarget() == this);
            if (uint8 procEffectMask = aurApp->GetBase()->GetProcEffectMask(aurApp, eventInfo, now))
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
            if (uint8 procEffectMask = itr->second->GetBase()->GetProcEffectMask(itr->second, eventInfo, now))
            {
                itr->second->GetBase()->PrepareProcToTrigger(itr->second, eventInfo, now);
                aurasTriggeringProc.emplace_back(procEffectMask, itr->second);
            }
        }
    }
}

void Unit::TriggerAurasProcOnEvent(Unit* actionTarget, uint32 typeMaskActor, uint32 typeMaskActionTarget, uint32 spellTypeMask, uint32 spellPhaseMask, uint32 hitMask, Spell* spell, DamageInfo* damageInfo, HealInfo* healInfo)
{
    // prepare data for self trigger
    ProcEventInfo myProcEventInfo(this, actionTarget, actionTarget, typeMaskActor, spellTypeMask, spellPhaseMask, hitMask, spell, damageInfo, healInfo);
    if (typeMaskActor)
    {
        AuraApplicationProcContainer myAurasTriggeringProc;
        GetProcAurasTriggeredOnEvent(myAurasTriggeringProc, nullptr, myProcEventInfo);

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
        TriggerAurasProcOnEvent(myProcEventInfo, myAurasTriggeringProc);
    }

    // prepare data for target trigger
    ProcEventInfo targetProcEventInfo(this, actionTarget, this, typeMaskActionTarget, spellTypeMask, spellPhaseMask, hitMask, spell, damageInfo, healInfo);
    if (typeMaskActionTarget && actionTarget)
    {
        AuraApplicationProcContainer targetAurasTriggeringProc;
        actionTarget->GetProcAurasTriggeredOnEvent(targetAurasTriggeringProc, nullptr, targetProcEventInfo);
        actionTarget->TriggerAurasProcOnEvent(targetProcEventInfo, targetAurasTriggeringProc);
    }
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
        uint8 procEffectMask;
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

///----------Pet responses methods-----------------
void Unit::SendPetActionFeedback(uint8 msg)
{
    Unit* owner = GetOwner();
    if (!owner || owner->GetTypeId() != TYPEID_PLAYER)
        return;

    WorldPacket data(SMSG_PET_ACTION_FEEDBACK, 1);
    data << uint8(msg);
    owner->ToPlayer()->SendDirectMessage(&data);
}

void Unit::SendPetTalk(uint32 pettalk)
{
    Unit* owner = GetOwner();
    if (!owner || owner->GetTypeId() != TYPEID_PLAYER)
        return;

    WorldPacket data(SMSG_PET_ACTION_SOUND, 8 + 4);
    data << uint64(GetGUID());
    data << uint32(pettalk);
    owner->ToPlayer()->SendDirectMessage(&data);
}

void Unit::SendPetAIReaction(ObjectGuid guid)
{
    Unit* owner = GetOwner();
    if (!owner || owner->GetTypeId() != TYPEID_PLAYER)
        return;

    WorldPacket data(SMSG_AI_REACTION, 8 + 4);
    data << uint64(guid);
    data << uint32(AI_REACTION_HOSTILE);
    owner->ToPlayer()->SendDirectMessage(&data);
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

void Unit::SendMovementFlagUpdate(bool self /* = false */)
{
    WorldPacket data;
    BuildHeartBeatMsg(&data);
    SendMessageToSet(&data, self);
}

bool Unit::IsSitState() const
{
    uint8 s = GetStandState();
    return
        s == UNIT_STAND_STATE_SIT_CHAIR        || s == UNIT_STAND_STATE_SIT_LOW_CHAIR  ||
        s == UNIT_STAND_STATE_SIT_MEDIUM_CHAIR || s == UNIT_STAND_STATE_SIT_HIGH_CHAIR ||
        s == UNIT_STAND_STATE_SIT;
}

bool Unit::IsStandState() const
{
    uint8 s = GetStandState();
    return !IsSitState() && s != UNIT_STAND_STATE_SLEEP && s != UNIT_STAND_STATE_KNEEL;
}

void Unit::SetStandState(UnitStandStateType state)
{
    SetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_STAND_STATE, state);

    if (state == UNIT_STAND_STATE_STAND)
       RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_NOT_SEATED);

    if (GetTypeId() == TYPEID_PLAYER)
    {
        WorldPacket data(SMSG_STANDSTATE_UPDATE, 1);
        data << (uint8)state;
        ToPlayer()->SendDirectMessage(&data);
    }
}

bool Unit::IsPolymorphed() const
{
    uint32 transformId = GetTransformSpell();
    if (!transformId)
        return false;

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(transformId);
    if (!spellInfo)
        return false;

    return spellInfo->GetSpellSpecific() == SPELL_SPECIFIC_MAGE_POLYMORPH;
}

void Unit::SetAnimTier(AnimTier tier)
{
    if (!IsCreature())
        return;

    SetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_ANIM_TIER, static_cast<uint8>(tier));
}

void Unit::RecalculateObjectScale()
{
    int32 scaleAuras = GetTotalAuraModifier(SPELL_AURA_MOD_SCALE) + GetTotalAuraModifier(SPELL_AURA_MOD_SCALE_2);
    float scale = GetNativeObjectScale() + CalculatePct(1.0f, scaleAuras);
    float scaleMin = GetTypeId() == TYPEID_PLAYER ? 0.1 : 0.01;
    SetObjectScale(std::max(scale, scaleMin));
}

void Unit::SetDisplayId(uint32 modelId)
{
    SetUInt32Value(UNIT_FIELD_DISPLAYID, modelId);
    // Set Gender by modelId
    if (CreatureModelInfo const* minfo = sObjectMgr->GetCreatureModelInfo(modelId))
        SetGender(Gender(minfo->gender));
}

void Unit::RestoreDisplayId()
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
                    handledAura = (*i);
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
    else if (!shapeshiftAura.empty()) // we've found shapeshift
    {
        // only one such aura possible at a time
        if (uint32 modelId = GetModelForForm(GetShapeshiftForm(), shapeshiftAura.front()->GetId()))
        {
            SetDisplayId(modelId);
            return;
        }
    }

    // no auras found - set modelid to default
    SetDisplayId(GetNativeDisplayId());
}

void Unit::AddComboPoints(Unit* target, int8 count)
{
    if (!count)
        return;

    if (target && target != m_comboTarget)
    {
        if (m_comboTarget)
            m_comboTarget->RemoveComboPointHolder(this);
        m_comboTarget = target;
        m_comboPoints = count;
        target->AddComboPointHolder(this);
    }
    else
        m_comboPoints = std::max<int8>(std::min<int8>(m_comboPoints + count, 5),0);

    SendComboPoints();
}

void Unit::ClearComboPoints()
{
    if (!m_comboTarget)
        return;

    // remove Premed-like effects
    // (NB: this Aura retains the CP while it's active - now that CP have reset, it shouldn't be there anymore)
    RemoveAurasByType(SPELL_AURA_RETAIN_COMBO_POINTS);

    m_comboPoints = 0;
    SendComboPoints();
    m_comboTarget->RemoveComboPointHolder(this);
    m_comboTarget = nullptr;
}

void Unit::SendComboPoints()
{
    if (m_cleanupDone)
        return;

    PackedGuid const packGUID = m_comboTarget ? m_comboTarget->GetPackGUID() : PackedGuid();
    if (Player* playerMe = ToPlayer())
    {
        WorldPacket data;
        data.Initialize(SMSG_UPDATE_COMBO_POINTS, packGUID.size() + 1);
        data << packGUID;
        data << uint8(m_comboPoints);
        playerMe->SendDirectMessage(&data);
    }
    Player* movingMe = GetCharmerOrSelfPlayer();
    ObjectGuid ownerGuid = GetCharmerOrOwnerGUID();
    Player* owner = nullptr;
    if (ownerGuid.IsPlayer())
        owner = ObjectAccessor::GetPlayer(*this, ownerGuid);
    if (movingMe || owner)
    {
        WorldPacket data;
        data.Initialize(SMSG_PET_UPDATE_COMBO_POINTS, GetPackGUID().size() + packGUID.size() + 1);
        data << GetPackGUID();
        data << packGUID;
        data << uint8(m_comboPoints);
        if (movingMe)
            movingMe->SendDirectMessage(&data);
        if (owner && owner != movingMe)
            owner->SendDirectMessage(&data);
    }
}

void Unit::ClearComboPointHolders()
{
    while (!m_ComboPointHolders.empty())
        (*m_ComboPointHolders.begin())->ClearComboPoints(); // this also removes it from m_comboPointHolders
}

void Unit::ClearAllReactives()
{
    for (uint8 i = 0; i < MAX_REACTIVE; ++i)
        m_reactiveTimer[i] = 0;

    if (HasAuraState(AURA_STATE_DEFENSE))
        ModifyAuraState(AURA_STATE_DEFENSE, false);
    if (GetClass() == CLASS_HUNTER && HasAuraState(AURA_STATE_HUNTER_PARRY))
        ModifyAuraState(AURA_STATE_HUNTER_PARRY, false);
    if (GetClass() == CLASS_WARRIOR && GetTypeId() == TYPEID_PLAYER)
        ClearComboPoints();
    if (IsHunterPet())
        ClearComboPoints();
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
                    if (HasAuraState(AURA_STATE_DEFENSE))
                        ModifyAuraState(AURA_STATE_DEFENSE, false);
                    break;
                case REACTIVE_HUNTER_PARRY:
                    if (GetClass() == CLASS_HUNTER && HasAuraState(AURA_STATE_HUNTER_PARRY))
                        ModifyAuraState(AURA_STATE_HUNTER_PARRY, false);
                    break;
                case REACTIVE_OVERPOWER:
                    if (GetClass() == CLASS_WARRIOR && GetTypeId() == TYPEID_PLAYER)
                        ClearComboPoints();
                    break;
                case REACTIVE_WOLVERINE_BITE:
                    if (IsHunterPet())
                        ClearComboPoints();
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

void ApplyPercentModFloatVar(float& var, float val, bool apply)
{
    var *= (apply ? (100.0f + val) / 100.0f : 100.0f / (100.0f + val));
}

void Unit::ApplyAttackTimePercentMod(WeaponAttackType att, float val, bool apply)
{
    float amount = GetFloatValue(UNIT_FIELD_BASEATTACKTIME + AsUnderlyingType(att));

    float remainingTimePct = (float)m_attackTimer[att] / (GetAttackTime(att) * m_modAttackSpeedPct[att]);
    if (val > 0.f)
    {
        ApplyPercentModFloatVar(m_modAttackSpeedPct[att], val, !apply);
        ApplyPercentModFloatVar(amount, val, !apply);
    }
    else
    {
        ApplyPercentModFloatVar(m_modAttackSpeedPct[att], -val, apply);
        ApplyPercentModFloatVar(amount, -val, apply);
    }

    SetFloatValue(UNIT_FIELD_BASEATTACKTIME + AsUnderlyingType(att), amount);
    m_attackTimer[att] = uint32(GetAttackTime(att) * m_modAttackSpeedPct[att] * remainingTimePct);
}

void Unit::ApplyCastTimePercentMod(float val, bool apply)
{
    float amount = GetFloatValue(UNIT_MOD_CAST_SPEED);

    if (val > 0.f)
        ApplyPercentModFloatVar(amount, val, !apply);
    else
        ApplyPercentModFloatVar(amount, -val, apply);

    SetModCastingSpeed(amount);
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

    for (SpellEffectInfo const& spellEffectInfo : spellProto->GetEffects())
    {
        switch (spellEffectInfo.Effect)
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
                switch (spellEffectInfo.ApplyAuraName)
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
                break;
            default:
                break;
        }

        if (spellEffectInfo.IsTargetingArea())
            AreaEffect = true;
    }

    // Combined Spells with Both Over Time and Direct Damage
    if (overTime > 0 && DirectDamage)
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
    for (SpellEffectInfo const& spellEffectInfo : spellProto->GetEffects())
    {
        if (spellEffectInfo.IsEffect(SPELL_EFFECT_HEALTH_LEECH) ||
            (spellEffectInfo.IsEffect(SPELL_EFFECT_APPLY_AURA) && spellEffectInfo.ApplyAuraName == SPELL_AURA_PERIODIC_LEECH))
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

void Unit::UpdateAuraForGroup(uint8 slot)
{
    if (slot >= MAX_AURAS)                        // slot not found, return
        return;
    if (Player* player = ToPlayer())
    {
        if (player->GetGroup())
        {
            player->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_AURAS);
            player->SetAuraUpdateMaskForRaid(slot);
        }
    }
    else if (GetTypeId() == TYPEID_UNIT && IsPet())
    {
        Pet* pet = ((Pet*)this);
        if (pet->isControlled())
        {
            Unit* owner = GetOwner();
            if (owner && (owner->GetTypeId() == TYPEID_PLAYER) && owner->ToPlayer()->GetGroup())
            {
                owner->ToPlayer()->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_PET_AURAS);
                pet->SetAuraUpdateMaskForRaid(slot);
            }
        }
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
        return GetAttackTime(attType) / 1000.0f;

    Item* weapon = ToPlayer()->GetWeaponForAttack(attType, true);
    if (!weapon)
        return BASE_ATTACK_TIME / 1000.0f;

    if (!normalized)
        return weapon->GetTemplate()->Delay / 1000.0f;

    switch (weapon->GetTemplate()->SubClass)
    {
        case ITEM_SUBCLASS_WEAPON_AXE2:
        case ITEM_SUBCLASS_WEAPON_MACE2:
        case ITEM_SUBCLASS_WEAPON_POLEARM:
        case ITEM_SUBCLASS_WEAPON_SWORD2:
        case ITEM_SUBCLASS_WEAPON_STAFF:
        case ITEM_SUBCLASS_WEAPON_FISHING_POLE:
            return 3.3f;
        case ITEM_SUBCLASS_WEAPON_BOW:
        case ITEM_SUBCLASS_WEAPON_GUN:
        case ITEM_SUBCLASS_WEAPON_CROSSBOW:
        case ITEM_SUBCLASS_WEAPON_THROWN:
            return 2.8f;
        case ITEM_SUBCLASS_WEAPON_AXE:
        case ITEM_SUBCLASS_WEAPON_MACE:
        case ITEM_SUBCLASS_WEAPON_SWORD:
        case ITEM_SUBCLASS_WEAPON_EXOTIC:
        case ITEM_SUBCLASS_WEAPON_EXOTIC2:
        case ITEM_SUBCLASS_WEAPON_FIST:
            return 2.4f;
        case ITEM_SUBCLASS_WEAPON_DAGGER:
            return 1.7f;
        default:
            return weapon->GetTemplate()->Delay / 1000.0f;
    }
}

bool Unit::IsUnderLastManaUseEffect() const
{
    return getMSTimeDiff(m_lastManaUse, GameTime::GetGameTimeMS()) < 5000;
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

    uint8 level = creatureTarget->GetLevel() + 5 < GetLevel() ? (GetLevel() - 5) : creatureTarget->GetLevel();

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
    if (petStable.CurrentPet || petStable.GetUnslottedHunterPet())
        return false;

    pet->SetCreatorGUID(GetGUID());
    pet->SetFaction(GetFaction());
    pet->SetCreatedBySpell(spell_id);

    if (GetTypeId() == TYPEID_PLAYER)
        pet->ReplaceAllUnitFlags(UNIT_FLAG_PLAYER_CONTROLLED);

    if (!pet->InitStatsForLevel(level))
    {
        TC_LOG_ERROR("entities.unit", "Pet::InitStatsForLevel() failed for creature (Entry: {})!", pet->GetEntry());
        return false;
    }

    pet->GetCharmInfo()->SetPetNumber(sObjectMgr->GeneratePetNumber(), true);
    // this enables pet details window (Shift+P)
    pet->InitPetCreateSpells();
    //pet->InitLevelupSpellsForLevel();
    pet->SetFullHealth();

    pet->FillPetInfo(&petStable.CurrentPet.emplace());
    return true;
}

/*static*/ void Unit::Kill(Unit* attacker, Unit* victim, bool durabilityLoss /*= true*/)
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

    if (isRewardAllowed && creature)
    {
        if (Player* lootRecipient = creature->GetLootRecipient())
        {
            // Loot recipient can be in a different map
            if (!creature->IsInMap(lootRecipient))
            {
                if (Group* group = creature->GetLootRecipientGroup())
                {
                    for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
                    {
                        Player* member = itr->GetSource();
                        if (!member || !creature->IsInMap(member))
                            continue;

                        player = member;
                        break;
                    }
                }
            }
            else
                player = creature->GetLootRecipient();
        }
    }

    // Exploit fix
    if (creature && creature->IsPet() && creature->GetOwnerGUID().IsPlayer())
        isRewardAllowed = false;

    // Reward player, his pets, and group/raid members
    // call kill spell proc event (before real die and combat stop to triggering auras removed at death/combat stop)
    if (isRewardAllowed && player && player != victim)
    {
        WorldPacket data(SMSG_PARTYKILLLOG, (8+8)); // send event PARTY_KILL
        data << uint64(player->GetGUID()); // player with killing blow
        data << uint64(victim->GetGUID()); // victim

        Player* looter = player;
        Group* group = player->GetGroup();
        bool hasLooterGuid = false;

        if (group)
        {
            group->BroadcastPacket(&data, group->GetMemberGroup(player->GetGUID()) != 0);

            if (creature)
            {
                group->UpdateLooterGuid(creature, true);
                if (group->GetLooterGuid())
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
            player->SendDirectMessage(&data);

            if (creature)
            {
                WorldPacket data2(SMSG_LOOT_LIST, 8 + 1 + 1);
                data2 << uint64(creature->GetGUID());
                data2 << uint8(0); // unk1
                data2 << uint8(0); // no group looter
                player->SendMessageToSet(&data2, true);
            }
        }

        // Generate loot before updating looter
        if (creature)
        {
            Loot* loot = &creature->loot;
            loot->clear();

            if (uint32 lootid = creature->GetCreatureTemplate()->lootid)
                loot->FillLoot(lootid, LootTemplates_Creature, looter, false, false, creature->GetLootMode());

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
            killerPlayer->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_GET_KILLING_BLOWS, 1, 0, victim);

    // Spirit of Redemption
    // if talent known but not triggered
    bool spiritOfRedemption = false;
    if (AuraEffect const* aurEff = victim->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_PRIEST, 0, 0, 0x200))
    {
        // save value before aura remove
        uint32 ressSpellId = victim->GetUInt32Value(PLAYER_SELF_RES_SPELL);
        if (!ressSpellId)
            ressSpellId = victim->ToPlayer()->GetResurrectionSpellId();
        // Remove all expected to remove at death auras (most important negative case like DoT or periodic triggers)
        victim->RemoveAllAurasOnDeath();
        // restore for use at real death
        victim->SetUInt32Value(PLAYER_SELF_RES_SPELL, ressSpellId);

        // FORM_SPIRITOFREDEMPTION and related auras
        victim->CastSpell(victim, 27827, aurEff);
        spiritOfRedemption = true;
    }

    if (!spiritOfRedemption)
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
            TC_LOG_DEBUG("entities.unit", "We are dead, losing {} percent durability", sWorld->getRate(RATE_DURABILITY_LOSS_ON_DEATH));
            plrVictim->DurabilityLossAll(sWorld->getRate(RATE_DURABILITY_LOSS_ON_DEATH), false);
            // durability lost message
            plrVictim->SendDurabilityLoss();
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
            if (!creature->loot.isLooted())
                creature->SetDynamicFlag(UNIT_DYNFLAG_LOOTABLE);
            else
                creature->AllLootRemovedFromCorpse();
        }

        // Call KilledUnit for creatures, this needs to be called after the lootable flag is set
        if (attacker && attacker->GetTypeId() == TYPEID_UNIT && attacker->IsAIEnabled())
            attacker->ToCreature()->AI()->KilledUnit(victim);

        // Call creature just died function
        if (CreatureAI* ai = creature->AI())
            ai->JustDied(attacker);

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
            victim->ToPlayer()->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_CREATURE, attacker->GetEntry());
        else if (attacker->GetTypeId() == TYPEID_PLAYER && victim != attacker)
            victim->ToPlayer()->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_PLAYER, 1, attacker->ToPlayer()->GetTeam());
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
                    ClearUnitState(UNIT_STATE_MELEE_ATTACKING);
                    SendMeleeAttackStop();
                    // SendAutoRepeatCancel ?
                    SetConfused(true);
                }
                break;
            case UNIT_STATE_FLEEING:
                if (!HasUnitState(UNIT_STATE_STUNNED | UNIT_STATE_CONFUSED))
                {
                    ClearUnitState(UNIT_STATE_MELEE_ATTACKING);
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
                if (HasAuraType(SPELL_AURA_MOD_STUN))
                    return;

                ClearUnitState(state);
                SetStunned(false);
                break;
            case UNIT_STATE_ROOT:
                if (HasAuraType(SPELL_AURA_MOD_ROOT) || GetVehicle() || (ToCreature() && ToCreature()->GetMovementTemplate().IsRooted()))
                    return;

                ClearUnitState(state);
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

    if (HasUnitState(UNIT_STATE_ROOT) || HasAuraType(SPELL_AURA_MOD_ROOT))
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
        if (m_rootTimes > 0) // blizzard internal check?
            m_rootTimes++;

        SetTarget(ObjectGuid::Empty);
        SetUnitFlag(UNIT_FLAG_STUNNED);

        // MOVEMENTFLAG_ROOT cannot be used in conjunction with MOVEMENTFLAG_MASK_MOVING (tested 3.3.5a)
        // this will freeze clients. That's why we remove MOVEMENTFLAG_MASK_MOVING before
        // setting MOVEMENTFLAG_ROOT
        RemoveUnitMovementFlag(MOVEMENTFLAG_MASK_MOVING);
        AddUnitMovementFlag(MOVEMENTFLAG_ROOT);
        StopMoving();

        if (GetTypeId() == TYPEID_PLAYER)
            SetStandState(UNIT_STAND_STATE_STAND);

        if (GetTypeId() == TYPEID_PLAYER)
        {
            WorldPacket data(SMSG_FORCE_MOVE_ROOT, 10);
            data << GetPackGUID();
            data << m_rootTimes;
            SendMessageToSet(&data, true);
        }
        else
        {
            WorldPacket data(SMSG_SPLINE_MOVE_ROOT, 8);
            data << GetPackGUID();
            SendMessageToSet(&data, true);
        }

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
        {
            if (GetTypeId() == TYPEID_PLAYER)
            {
                WorldPacket data(SMSG_FORCE_MOVE_UNROOT, 10);
                data << GetPackGUID();
                data << ++m_rootTimes;
                SendMessageToSet(&data, true);
            }
            else
            {
                WorldPacket data(SMSG_SPLINE_MOVE_UNROOT, 8);
                data << GetPackGUID();
                SendMessageToSet(&data, true);
            }

            RemoveUnitMovementFlag(MOVEMENTFLAG_ROOT);
        }
    }
}

void Unit::SetRooted(bool apply)
{
    if (apply)
    {
        if (m_rootTimes > 0) // blizzard internal check?
            m_rootTimes++;

        // MOVEMENTFLAG_ROOT cannot be used in conjunction with MOVEMENTFLAG_MASK_MOVING (tested 3.3.5a)
        // this will freeze clients. That's why we remove MOVEMENTFLAG_MASK_MOVING before
        // setting MOVEMENTFLAG_ROOT
        RemoveUnitMovementFlag(MOVEMENTFLAG_MASK_MOVING);
        AddUnitMovementFlag(MOVEMENTFLAG_ROOT);
        StopMoving();

        if (GetTypeId() == TYPEID_PLAYER)
        {
            WorldPacket data(SMSG_FORCE_MOVE_ROOT, 10);
            data << GetPackGUID();
            data << m_rootTimes;
            SendMessageToSet(&data, true);
        }
        else
        {
            WorldPacket data(SMSG_SPLINE_MOVE_ROOT, 8);
            data << GetPackGUID();
            SendMessageToSet(&data, true);
        }
    }
    else
    {
        if (!HasUnitState(UNIT_STATE_STUNNED))      // prevent moving if it also has stun effect
        {
            if (GetTypeId() == TYPEID_PLAYER)
            {
                WorldPacket data(SMSG_FORCE_MOVE_UNROOT, 10);
                data << GetPackGUID();
                data << ++m_rootTimes;
                SendMessageToSet(&data, true);
            }
            else
            {
                WorldPacket data(SMSG_SPLINE_MOVE_UNROOT, 8);
                data << GetPackGUID();
                SendMessageToSet(&data, true);
            }

            RemoveUnitMovementFlag(MOVEMENTFLAG_ROOT);
        }
    }
}

void Unit::SetFeared(bool apply)
{
    if (apply)
    {
        // block control to real player in control (eg charmer)
        if (GetCharmerOrSelfPlayer())
            GetCharmerOrSelfPlayer()->SetClientControl(this, false);

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
            GetMotionMaster()->Remove(FLEEING_MOTION_TYPE);
            if (GetVictim())
                SetTarget(EnsureVictim()->GetGUID());
            if (!IsPlayer() && !IsInCombat())
                GetMotionMaster()->MoveTargetedHome();
        }

        // allow control to real player in control (eg charmer)
        if (GetCharmerOrSelfPlayer())
            GetCharmerOrSelfPlayer()->SetClientControl(this, true);
    }
}

void Unit::SetConfused(bool apply)
{
    if (apply)
    {
        // block control to real player in control (eg charmer)
        if (GetCharmerOrSelfPlayer())
            GetCharmerOrSelfPlayer()->SetClientControl(this, false);

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

        // allow control to real player in control (eg charmer)
        if (GetCharmerOrSelfPlayer())
            GetCharmerOrSelfPlayer()->SetClientControl(this, true);
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
    if (GetCharmerGUID())
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
                        SetPetNameTimestamp(uint32(GameTime::GetGameTime())); // cast can't be helped
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

    if (Creature* creature = ToCreature())
        creature->RefreshCanSwimFlag();

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

bool Unit::CreateVehicleKit(uint32 id, uint32 creatureEntry)
{
    VehicleEntry const* vehInfo = sVehicleStore.LookupEntry(id);
    if (!vehInfo)
        return false;

    m_vehicleKit = Trinity::make_unique_trackable<Vehicle>(this, vehInfo, creatureEntry);
    m_updateFlag |= UPDATEFLAG_VEHICLE;
    m_unitTypeMask |= UNIT_MASK_VEHICLE;
    return true;
}

void Unit::RemoveVehicleKit()
{
    if (!m_vehicleKit)
        return;

    m_vehicleKit->Uninstall();
    m_vehicleKit = nullptr;

    m_updateFlag &= ~UPDATEFLAG_VEHICLE;
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
        SetPvpFlag(UNIT_BYTE2_FLAG_PVP);
    else
        RemovePvpFlag(UNIT_BYTE2_FLAG_PVP);
}

Aura* Unit::AddAura(uint32 spellId, Unit* target)
{
    if (!target)
        return nullptr;

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
    if (!spellInfo)
        return nullptr;

    return AddAura(spellInfo, MAX_EFFECT_MASK, target);
}

Aura* Unit::AddAura(SpellInfo const* spellInfo, uint8 effMask, Unit* target)
{
    if (!spellInfo)
        return nullptr;

    if (!target->IsAlive() && !spellInfo->IsPassive() && !spellInfo->HasAttribute(SPELL_ATTR2_CAN_TARGET_DEAD))
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

    AuraCreateInfo createInfo(spellInfo, effMask, target);
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

void Unit::SendPlaySpellVisual(uint32 id) const
{
    WorldPacket data(SMSG_PLAY_SPELL_VISUAL, 8 + 4);
    data << uint64(GetGUID());
    data << uint32(id); // SpellVisualKit.dbc index
    SendMessageToSet(&data, true);
}

void Unit::SendPlaySpellImpact(ObjectGuid guid, uint32 id) const
{
    WorldPacket data(SMSG_PLAY_SPELL_IMPACT, 8 + 4);
    data << uint64(guid); // target
    data << uint32(id); // SpellVisualKit.dbc index
    SendMessageToSet(&data, false);
}

bool Unit::CanApplyResilience() const
{
    return !IsVehicle() && GetOwnerGUID().IsPlayer();
}

/*static*/ void Unit::ApplyResilience(Unit const* victim, float* crit, int32* damage, bool isCrit, CombatRating type)
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

    switch (type)
    {
        case CR_CRIT_TAKEN_MELEE:
            // Crit chance reduction works against nonpets
            if (crit)
                *crit -= target->GetMeleeCritChanceReduction();
            if (damage)
            {
                if (isCrit)
                    *damage -= target->GetMeleeCritDamageReduction(*damage);
                *damage -= target->GetMeleeDamageReduction(*damage);
            }
            break;
        case CR_CRIT_TAKEN_RANGED:
            // Crit chance reduction works against nonpets
            if (crit)
                *crit -= target->GetRangedCritChanceReduction();
            if (damage)
            {
                if (isCrit)
                    *damage -= target->GetRangedCritDamageReduction(*damage);
                *damage -= target->GetRangedDamageReduction(*damage);
            }
            break;
        case CR_CRIT_TAKEN_SPELL:
            // Crit chance reduction works against nonpets
            if (crit)
                *crit -= target->GetSpellCritChanceReduction();
            if (damage)
            {
                if (isCrit)
                    *damage -= target->GetSpellCritDamageReduction(*damage);
                *damage -= target->GetSpellDamageReduction(*damage);
            }
            break;
        default:
            break;
    }
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
float Unit::MeleeSpellMissChance(Unit const* victim, WeaponAttackType attType, int32 skillDiff, uint32 spellId) const
{
    SpellInfo const* spellInfo = spellId ? sSpellMgr->GetSpellInfo(spellId) : nullptr;
    if (spellInfo && spellInfo->HasAttribute(SPELL_ATTR7_CANT_MISS))
        return 0.f;

    //calculate miss chance
    float missChance = victim->GetUnitMissChance();

    // melee attacks while dual wielding have +19% chance to miss
    if (!spellId && haveOffhandWeapon())
        missChance += 19.0f;

    // bonus from skills is 0.04%
    //miss_chance -= skillDiff * 0.04f;
    int32 diff = -skillDiff;
    if (victim->GetTypeId() == TYPEID_PLAYER)
        missChance += diff > 0 ? diff * 0.04f : diff * 0.02f;
    else
    {
        missChance += diff > 10 ? 1 + (diff - 10) * 0.4f : diff * 0.1f;
        float levelFactor = victim->GetLevelForTarget(this);
        if (levelFactor < 10.f)
            missChance *= (levelFactor / 10.f);
    }

    // Spellmod from SPELLMOD_RESIST_MISS_CHANCE
    float resistMissChance = 100.0f;
    if (spellId)
    {
        if (Player* modOwner = GetSpellModOwner())
            modOwner->ApplySpellMod(spellId, SPELLMOD_RESIST_MISS_CHANCE, resistMissChance);
    }
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

void Unit::SetPhaseMask(uint32 newPhaseMask, bool update)
{
    if (newPhaseMask == GetPhaseMask())
        return;

    // Phase player, dont update
    WorldObject::SetPhaseMask(newPhaseMask, false);

    // Phase pets and summons
    if (IsInWorld())
    {
        for (ControlList::const_iterator itr = m_Controlled.begin(); itr != m_Controlled.end(); ++itr)
            if ((*itr)->GetTypeId() == TYPEID_UNIT)
                (*itr)->SetPhaseMask(newPhaseMask, true);

        for (uint8 i = 0; i < MAX_SUMMON_SLOT; ++i)
            if (m_SummonSlot[i])
                if (Creature* summon = GetMap()->GetCreature(m_SummonSlot[i]))
                    summon->SetPhaseMask(newPhaseMask, true);

        RemoveNotOwnSingleTargetAuras(newPhaseMask); // we can lost access to caster or target
    }

    // Update visibility after phasing pets and summons so they wont despawn
    if (update)
        UpdateObjectVisibility();
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

void Unit::KnockbackFrom(float x, float y, float speedXY, float speedZ)
{
    if (IsMovedByServer())
    {
        GetMotionMaster()->MoveKnockbackFrom(x, y, speedXY, speedZ);
    }
    else
    {
        float vcos, vsin;
        GetSinCos(x, y, vsin, vcos);

        WorldPacket data(SMSG_MOVE_KNOCK_BACK, (8 + 4 + 4 + 4 + 4 + 4));
        data << GetPackGUID();
        data << uint32(0);                                      // counter
        data << TaggedPosition<Position::XY>(vcos, vsin);
        data << float(speedXY);                                 // Horizontal speed
        data << float(-speedZ);                                 // Z Movement speed (vertical)

        GetGameClientMovingMe()->SendDirectMessage(&data);

        if (HasAuraType(SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED) || HasAuraType(SPELL_AURA_FLY))
            SetCanFly(true, true);
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

    if (Player const* player = ToPlayer())
    {
        switch (form)
        {
            case FORM_CAT:
                // Based on Hair color
                if (GetRace() == RACE_NIGHTELF)
                {
                    switch (player->GetHairColorId())
                    {
                        case 7: // Violet
                        case 8:
                            return 29405;
                        case 3: // Light Blue
                            return 29406;
                        case 0: // Green
                        case 1: // Light Green
                        case 2: // Dark Green
                            return 29407;
                        case 4: // White
                            return 29408;
                        default: // original - Dark Blue
                            return 892;
                    }
                }
                // Based on Skin color
                else if (GetRace() == RACE_TAUREN)
                {
                    uint8 skinColor = player->GetSkinId();
                    // Male
                    if (GetNativeGender() == GENDER_MALE)
                    {
                        switch (skinColor)
                        {
                            case 12: // White
                            case 13:
                            case 14:
                            case 18: // Completly White
                                return 29409;
                            case 9: // Light Brown
                            case 10:
                            case 11:
                                return 29410;
                            case 6: // Brown
                            case 7:
                            case 8:
                                return 29411;
                            case 0: // Dark
                            case 1:
                            case 2:
                            case 3: // Dark Grey
                            case 4:
                            case 5:
                                return 29412;
                            default: // original - Grey
                                return 8571;
                        }
                    }
                    // Female
                    else switch (skinColor)
                    {
                        case 10: // White
                            return 29409;
                        case 6: // Light Brown
                        case 7:
                            return 29410;
                        case 4: // Brown
                        case 5:
                            return 29411;
                        case 0: // Dark
                        case 1:
                        case 2:
                        case 3:
                            return 29412;
                        default: // original - Grey
                            return 8571;
                    }
                }
                else if (Player::TeamForRace(GetRace()) == ALLIANCE)
                    return 892;
                else
                    return 8571;
            case FORM_DIREBEAR:
            case FORM_BEAR:
                // Based on Hair color
                if (GetRace() == RACE_NIGHTELF)
                {
                    switch (player->GetHairColorId())
                    {
                        case 0: // Green
                        case 1: // Light Green
                        case 2: // Dark Green
                            return 29413; // 29415?
                        case 6: // Dark Blue
                            return 29414;
                        case 4: // White
                            return 29416;
                        case 3: // Light Blue
                            return 29417;
                        default: // original - Violet
                            return 2281;
                    }
                }
                // Based on Skin color
                else if (GetRace() == RACE_TAUREN)
                {
                    uint8 skinColor = player->GetSkinId();
                    // Male
                    if (GetNativeGender() == GENDER_MALE)
                    {
                        switch (skinColor)
                        {
                            case 0: // Dark (Black)
                            case 1:
                            case 2:
                                return 29418;
                            case 3: // White
                            case 4:
                            case 5:
                            case 12:
                            case 13:
                            case 14:
                                return 29419;
                            case 9: // Light Brown/Grey
                            case 10:
                            case 11:
                            case 15:
                            case 16:
                            case 17:
                                return 29420;
                            case 18: // Completly White
                                return 29421;
                            default: // original - Brown
                                return 2289;
                        }
                    }
                    // Female
                    else switch (skinColor)
                    {
                        case 0: // Dark (Black)
                        case 1:
                            return 29418;
                        case 2: // White
                        case 3:
                            return 29419;
                        case 6: // Light Brown/Grey
                        case 7:
                        case 8:
                        case 9:
                            return 29420;
                        case 10: // Completly White
                            return 29421;
                        default: // original - Brown
                            return 2289;
                    }
                }
                else if (Player::TeamForRace(GetRace()) == ALLIANCE)
                    return 2281;
                else
                    return 2289;
            case FORM_FLIGHT:
                if (Player::TeamForRace(GetRace()) == ALLIANCE)
                    return 20857;
                return 20872;
            case FORM_FLIGHT_EPIC:
                if (Player::TeamForRace(GetRace()) == ALLIANCE)
                    return 21243;
                return 21244;
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
            if (Player::TeamForRace(GetRace()) == ALLIANCE)
                modelid = formEntry->CreatureDisplayID[0];
            else
                modelid = formEntry->CreatureDisplayID[1];

            // If the player is horde but there are no values for the horde modelid - take the alliance modelid
            if (!modelid && Player::TeamForRace(GetRace()) == HORDE)
                modelid = formEntry->CreatureDisplayID[0];
        }
    }

    return modelid;
}

void Unit::JumpTo(float speedXY, float speedZ, bool forward, Optional<Position> dest)
{
    float angle = forward ? 0 : float(M_PI);
    if (dest)
        angle += GetRelativeAngle(*dest);

    if (GetTypeId() == TYPEID_UNIT)
        GetMotionMaster()->MoveJumpTo(angle, speedXY, speedZ);
    else
    {
        float vcos = std::cos(angle+GetOrientation());
        float vsin = std::sin(angle+GetOrientation());

        WorldPacket data(SMSG_MOVE_KNOCK_BACK, (8+4+4+4+4+4));
        data << GetPackGUID();
        data << uint32(0);                                      // Sequence
        data << TaggedPosition<Position::XY>(vcos, vsin);
        data << float(speedXY);                                 // Horizontal speed
        data << float(-speedZ);                                 // Z Movement speed (vertical)

        ToPlayer()->SendDirectMessage(&data);
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

        SpellInfo const* spellEntry = sSpellMgr->AssertSpellInfo(clickPair.second.spellId);
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
                    bp[spellEffectInfo.EffectIndex] = spellEffectInfo.BasePoints;

                bp[i] = seatId;

                AuraCreateInfo createInfo(spellEntry, MAX_EFFECT_MASK, this);
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
                AuraCreateInfo createInfo(spellEntry, MAX_EFFECT_MASK, this);
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
    args.AddSpellBP0(seatId + 1);
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

    // If vehicle flag for fixed position set (cannons), or if the following hardcoded units, then set state rooted
    //  30236 | Argent Cannon
    //  39759 | Tankbuster Cannon
    if ((vehicle->GetVehicleInfo()->Flags & VEHICLE_FLAG_FIXED_POSITION) || vehicle->GetBase()->GetEntry() == 30236 || vehicle->GetBase()->GetEntry() == 39759)
        SetControlled(true, UNIT_STATE_ROOT);

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
    else if (HasUnitMovementFlag(MOVEMENTFLAG_ROOT))
    {
        WorldPacket data(SMSG_SPLINE_MOVE_UNROOT, 8);
        data << GetPackGUID();
        SendMessageToSet(&data, false);
    }

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
        if (GetTypeId() == TYPEID_UNIT && !CanFly() && height > GetMap()->GetWaterOrGroundLevel(GetPhaseMask(), pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ() + vehicleCollisionHeight, &height))
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
}

void Unit::BuildMovementPacket(ByteBuffer *data) const
{
    Unit::BuildMovementPacket(*this, m_movementInfo.transport.pos, m_movementInfo, data);
}

void Unit::BuildMovementPacket(Position const& pos, Position const& transportPos, MovementInfo const& movementInfo, ByteBuffer* data)
{
    *data << uint32(movementInfo.GetMovementFlags());
    *data << uint16(movementInfo.GetExtraMovementFlags());
    *data << uint32(GameTime::GetGameTimeMS());         // time / counter
    *data << TaggedPosition<Position::XYZO>(pos);

    // 0x00000200
    if (movementInfo.HasMovementFlag(MOVEMENTFLAG_ONTRANSPORT))
    {
        *data << movementInfo.transport.guid.WriteAsPacked();
        *data << TaggedPosition<Position::XYZO>(transportPos);
        *data << uint32(movementInfo.transport.time);
        *data << int8(movementInfo.transport.seat);

        if (movementInfo.HasExtraMovementFlag(MOVEMENTFLAG2_INTERPOLATED_MOVEMENT))
            *data << uint32(movementInfo.transport.time2);
    }

    // 0x02200000
    if ((movementInfo.HasMovementFlag(MOVEMENTFLAG_SWIMMING | MOVEMENTFLAG_FLYING)) || (movementInfo.HasExtraMovementFlag(MOVEMENTFLAG2_ALWAYS_ALLOW_PITCHING)))
        *data << float(movementInfo.pitch);

    *data << uint32(movementInfo.fallTime);

    // 0x00001000
    if (movementInfo.HasMovementFlag(MOVEMENTFLAG_FALLING))
    {
        *data << float(movementInfo.jump.zspeed);
        *data << float(movementInfo.jump.sinAngle);
        *data << float(movementInfo.jump.cosAngle);
        *data << float(movementInfo.jump.xyspeed);
    }

    // 0x04000000
    if (movementInfo.HasMovementFlag(MOVEMENTFLAG_SPLINE_ELEVATION))
        *data << float(movementInfo.splineElevation);
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
    if (HasUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED)) // is player
        return true;
    if (HasUnitFlag2(UNIT_FLAG2_UNUSED_6))
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
        ToPlayer()->TeleportTo(target, TELE_TO_NOT_LEAVE_TRANSPORT | TELE_TO_NOT_LEAVE_COMBAT | TELE_TO_NOT_UNSUMMON_PET | (casting ? TELE_TO_SPELL : 0));
    }
    else
    {
        SendTeleportPacket(pos);
        UpdatePosition(pos, true);
        UpdateObjectVisibility();
    }
}

void Unit::SendTeleportPacket(Position const& pos, bool teleportingTransport /*= false*/)
{
    // MSG_MOVE_TELEPORT is sent to nearby players to signal the teleport
    // MSG_MOVE_TELEPORT_ACK is sent to self in order to trigger ACK and update the position server side

    MovementInfo teleportMovementInfo = m_movementInfo;
    teleportMovementInfo.pos.Relocate(pos);
    Position transportPos = m_movementInfo.transport.pos;
    if (TransportBase* transportBase = GetDirectTransport())
    {
        // if its the transport that is teleported then we have old transport position here and cannot use it to calculate offsets
        // assume that both transport teleport and teleport within transport cannot happen at the same time
        if (!teleportingTransport)
        {
            float x, y, z, o;
            pos.GetPosition(x, y, z, o);
            transportBase->CalculatePassengerOffset(x, y, z, &o);
            transportPos.Relocate(x, y, z, o);
        }
    }

    WorldPacket moveUpdateTeleport(MSG_MOVE_TELEPORT, 38);
    moveUpdateTeleport << GetPackGUID();
    Unit* broadcastSource = this;

    if (IsMovedByClient())
    {
        Player* playerMover = GetGameClientMovingMe()->GetBasePlayer();
        WorldPacket moveTeleport(MSG_MOVE_TELEPORT_ACK, 41);
        moveTeleport << GetPackGUID();
        moveTeleport << uint32(0);                                     // this value increments every time
        Unit::BuildMovementPacket(pos, transportPos, teleportMovementInfo, &moveTeleport);
        playerMover->SendDirectMessage(&moveTeleport);

        broadcastSource = playerMover;
    }

    Unit::BuildMovementPacket(pos, transportPos, teleportMovementInfo, &moveUpdateTeleport);

    // Broadcast the packet to everyone except self.
    broadcastSource->SendMessageToSet(&moveUpdateTeleport, false);
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

    UpdatePositionData();

    _positionUpdateInfo.Relocated = relocated;
    _positionUpdateInfo.Turned = turn;

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

PlayerMovementPendingChange& Unit::PeakFirstPendingMovementChange()
{
    return m_pendingMovementChanges.front();
}

PlayerMovementPendingChange Unit::PopPendingMovementChange()
{
    PlayerMovementPendingChange result = m_pendingMovementChanges.front();
    m_pendingMovementChanges.pop_front();
    return result;
}

void Unit::PushPendingMovementChange(PlayerMovementPendingChange newChange)
{
    m_pendingMovementChanges.emplace_back(std::move(newChange));
}

bool Unit::HasPendingMovementChange(MovementChangeType changeType) const
{
    return std::find_if(m_pendingMovementChanges.begin(), m_pendingMovementChanges.end(),
        [changeType](PlayerMovementPendingChange const& pendingChange)
    {
        return pendingChange.movementChangeType == changeType;
    }) != m_pendingMovementChanges.end();
}

void Unit::CheckPendingMovementAcks()
{
    if (sWorld->getIntConfig(CONFIG_PENDING_MOVE_CHANGES_TIMEOUT) == 0)
        return;

    if (!HasPendingMovementChange())
        return;

    PlayerMovementPendingChange const& oldestChangeToAck = m_pendingMovementChanges.front();
    if (GameTime::GetGameTimeMS() > oldestChangeToAck.time + sWorld->getIntConfig(CONFIG_PENDING_MOVE_CHANGES_TIMEOUT))
    {
        /*
        when players are teleported from one corner of a map to an other (example: from Dragonblight to the entrance of Naxxramas, both in the same map: Northend),
        is it done through what is called a 'near' teleport. A near teleport always involve teleporting a player from one point to an other in the same map, even if
        the distance is huge. When that distance is big enough, a loading screen appears on the client side. During that time, the client loads the surrounding zone
        of the new location (and everything it contains). The problem is that, as long as the client hasn't finished loading the new zone, it will NOT ack the near
        teleport. So if the server sends a near teleport order at a certain time and the client takes 20s to load the new zone (let's imagine a very slow computer),
        even with zero latency, the server will receive an ack from the client only after 20s.

        For this reason and because the current implementation is simple (you dear reader, feel free to improve it if you can), we will just ignore checking for
        near teleport acks (for now. @todo).
        */
        if (oldestChangeToAck.movementChangeType == MovementChangeType::TELEPORT)
            return;

        GameClient* controller = GetGameClientMovingMe();
        controller->GetWorldSession()->KickPlayer("Took too long to ack a movement change");
        TC_LOG_INFO("cheat", "Unit::CheckPendingMovementAcks: Player GUID: {} took too long to acknowledge a movement change. He was therefore kicked.", controller->GetBasePlayer()->GetGUID().ToString());
    }
}

void Unit::PurgeAndApplyPendingMovementChanges(bool informObservers /* = true */)
{
    for (auto pendingChange = m_pendingMovementChanges.cbegin(); pendingChange != m_pendingMovementChanges.cend(); ++pendingChange)
    {
        float speedFlat = pendingChange->newValue;
        MovementChangeType changeType = pendingChange->movementChangeType;
        UnitMoveType moveType;
        switch (changeType)
        {
            case MovementChangeType::SPEED_CHANGE_WALK:                 moveType = MOVE_WALK; break;
            case MovementChangeType::SPEED_CHANGE_RUN:                  moveType = MOVE_RUN; break;
            case MovementChangeType::SPEED_CHANGE_RUN_BACK:             moveType = MOVE_RUN_BACK; break;
            case MovementChangeType::SPEED_CHANGE_SWIM:                 moveType = MOVE_SWIM; break;
            case MovementChangeType::SPEED_CHANGE_SWIM_BACK:            moveType = MOVE_SWIM_BACK; break;
            case MovementChangeType::RATE_CHANGE_TURN:                  moveType = MOVE_TURN_RATE; break;
            case MovementChangeType::SPEED_CHANGE_FLIGHT_SPEED:         moveType = MOVE_FLIGHT; break;
            case MovementChangeType::SPEED_CHANGE_FLIGHT_BACK_SPEED:    moveType = MOVE_FLIGHT_BACK; break;
            case MovementChangeType::RATE_CHANGE_PITCH:                 moveType = MOVE_PITCH_RATE; break;
            default:
                ASSERT(false);
                return;
        }

        float newSpeedRate = speedFlat / (IsControlledByPlayer() ? playerBaseMoveSpeed[moveType] : baseMoveSpeed[moveType]);
        SetSpeedRateReal(moveType, newSpeedRate);

        if (informObservers)
            MovementPacketSender::SendSpeedChangeToObservers(this, moveType, speedFlat);
    }

    m_pendingMovementChanges.clear();
}

PlayerMovementPendingChange::PlayerMovementPendingChange()
{
    time = GameTime::GetGameTimeMS();
}

void Unit::RewardRage(uint32 damage, uint32 weaponSpeedHitFactor, bool attacker)
{
    float addRage;

    float rageconversion = ((0.0091107836f * GetLevel() * GetLevel()) + 3.225598133f * GetLevel()) + 4.2652911f;

    // Unknown if correct, but lineary adjust rage conversion above level 70
    if (GetLevel() > 70)
        rageconversion += 13.27f * (GetLevel() - 70);

    if (attacker)
    {
        addRage = (damage / rageconversion * 7.5f + weaponSpeedHitFactor) / 2;

        // talent who gave more rage on attack
        AddPct(addRage, GetTotalAuraModifier(SPELL_AURA_MOD_RAGE_FROM_DAMAGE_DEALT));
    }
    else
    {
        addRage = damage / rageconversion * 2.5f;

        // Berserker Rage effect
        if (HasAura(18499))
            addRage *= 2.0f;
    }

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
    WorldPacket data(SMSG_BREAK_TARGET, GetPackGUID().size());
    data << GetPackGUID();
    SendMessageToSet(&data, false);
}

int32 Unit::GetResistance(SpellSchoolMask mask) const
{
    int32 resist = -1;
    for (int32 i = SPELL_SCHOOL_NORMAL; i < MAX_SPELL_SCHOOL; ++i)
        if (mask & (1 << i) && (resist < 0 || resist > int32(GetResistance(SpellSchools(i)))))
            resist = int32(GetResistance(SpellSchools(i)));

    // resist value will never be negative here
    return resist;
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
    if (HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT) && GetTransGUID())
        init.DisableTransportPathTransformations(); // It makes no sense to target global orientation
    init.SetFacing(ori);

    //GetMotionMaster()->LaunchMoveSpline(std::move(init), EVENT_FACE, MOTION_PRIORITY_HIGHEST);
    init.Launch();
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
    return true;
}

bool Unit::SetDisableGravity(bool disable, bool /*packetOnly = false*/, bool /*updateAnimTier = true*/)
{
    if (disable == IsGravityDisabled())
        return false;

    if (disable)
    {
        AddUnitMovementFlag(MOVEMENTFLAG_DISABLE_GRAVITY);
        RemoveUnitMovementFlag(MOVEMENTFLAG_FALLING);
    }
    else
        RemoveUnitMovementFlag(MOVEMENTFLAG_DISABLE_GRAVITY);

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
    return true;
}

bool Unit::SetCanFly(bool enable, bool /*packetOnly = false */)
{
    if (enable == HasUnitMovementFlag(MOVEMENTFLAG_CAN_FLY))
        return false;

    if (enable)
    {
        AddUnitMovementFlag(MOVEMENTFLAG_CAN_FLY);
        RemoveUnitMovementFlag(MOVEMENTFLAG_FALLING);
    }
    else
        RemoveUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_MASK_MOVING_FLY);
    return true;
}

bool Unit::SetWaterWalking(bool enable, bool /*packetOnly = false */)
{
    if (enable == HasUnitMovementFlag(MOVEMENTFLAG_WATERWALKING))
        return false;

    if (enable)
        AddUnitMovementFlag(MOVEMENTFLAG_WATERWALKING);
    else
        RemoveUnitMovementFlag(MOVEMENTFLAG_WATERWALKING);
    return true;
}

bool Unit::SetFeatherFall(bool enable, bool /*packetOnly = false */)
{
    if (enable == HasUnitMovementFlag(MOVEMENTFLAG_FALLING_SLOW))
        return false;

    if (enable)
        AddUnitMovementFlag(MOVEMENTFLAG_FALLING_SLOW);
    else
        RemoveUnitMovementFlag(MOVEMENTFLAG_FALLING_SLOW);
    return true;
}

bool Unit::SetHover(bool enable, bool /*packetOnly = false*/, bool /*updateAnimTier = true*/)
{
    if (enable == HasUnitMovementFlag(MOVEMENTFLAG_HOVER))
        return false;

    float hoverHeight = GetFloatValue(UNIT_FIELD_HOVERHEIGHT);

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
    return true;
}

bool Unit::IsSplineEnabled() const
{
    return movespline->Initialized() && !movespline->Finalized();
}

void Unit::BuildValuesUpdate(uint8 updateType, ByteBuffer* data, Player const* target) const
{
    if (!target)
        return;

    ByteBuffer fieldBuffer;

    UpdateMaskPacketBuilder updateMask(m_valuesCount);

    uint32* flags = UnitUpdateFieldFlags;
    uint32 visibleFlag = UF_FLAG_PUBLIC;

    if (target == this)
        visibleFlag |= UF_FLAG_PRIVATE;

    Player* plr = GetCharmerOrOwnerPlayerOrPlayerItself();
    if (GetOwnerGUID() == target->GetGUID())
        visibleFlag |= UF_FLAG_OWNER;

    if (HasDynamicFlag(UNIT_DYNFLAG_SPECIALINFO))
        if (HasAuraTypeWithCaster(SPELL_AURA_EMPATHY, target->GetGUID()))
            visibleFlag |= UF_FLAG_SPECIAL_INFO;

    if (plr && plr->IsInSameRaidWith(target))
        visibleFlag |= UF_FLAG_PARTY_MEMBER;

    Creature const* creature = ToCreature();
    for (uint16 index = 0; index < m_valuesCount; ++index)
    {
        if (_fieldNotifyFlags & flags[index] ||
            ((flags[index] & visibleFlag) & UF_FLAG_SPECIAL_INFO) ||
            ((updateType == UPDATETYPE_VALUES ? _changesMask.GetBit(index) : m_uint32Values[index]) && (flags[index] & visibleFlag)) ||
            (index == UNIT_FIELD_AURASTATE && HasFlag(UNIT_FIELD_AURASTATE, PER_CASTER_AURA_STATE_MASK)))
        {
            updateMask.SetBit(index);

            if (index == UNIT_NPC_FLAGS)
            {
                uint32 appendValue = m_uint32Values[UNIT_NPC_FLAGS];

                if (creature)
                    if (!target->CanSeeSpellClickOn(creature))
                        appendValue &= ~UNIT_NPC_FLAG_SPELLCLICK;

                fieldBuffer << uint32(appendValue);
            }
            else if (index == UNIT_FIELD_AURASTATE)
            {
                // Check per caster aura states to not enable using a spell in client if specified aura is not by target
                fieldBuffer << BuildAuraStateUpdateForTarget(target);
            }
            // FIXME: Some values at server stored in float format but must be sent to client in uint32 format
            else if (index >= UNIT_FIELD_BASEATTACKTIME && index <= UNIT_FIELD_RANGEDATTACKTIME)
            {
                // convert from float to uint32 and send
                fieldBuffer << uint32(m_floatValues[index] < 0 ? 0 : m_floatValues[index]);
            }
            // there are some float values which may be negative or can't get negative due to other checks
            else if ((index >= UNIT_FIELD_NEGSTAT0   && index <= UNIT_FIELD_NEGSTAT4) ||
                (index >= UNIT_FIELD_RESISTANCEBUFFMODSPOSITIVE  && index <= (UNIT_FIELD_RESISTANCEBUFFMODSPOSITIVE + 6)) ||
                (index >= UNIT_FIELD_RESISTANCEBUFFMODSNEGATIVE  && index <= (UNIT_FIELD_RESISTANCEBUFFMODSNEGATIVE + 6)) ||
                (index >= UNIT_FIELD_POSSTAT0   && index <= UNIT_FIELD_POSSTAT4))
            {
                fieldBuffer << uint32(m_floatValues[index]);
            }
            // Gamemasters should be always able to interact with units - remove uninteractible flag
            else if (index == UNIT_FIELD_FLAGS)
            {
                uint32 appendValue = m_uint32Values[UNIT_FIELD_FLAGS];
                if (target->IsGameMaster())
                    appendValue &= ~UNIT_FLAG_UNINTERACTIBLE;

                fieldBuffer << uint32(appendValue);
            }
            // use modelid_a if not gm, _h if gm for CREATURE_FLAG_EXTRA_TRIGGER creatures
            else if (index == UNIT_FIELD_DISPLAYID)
            {
                uint32 displayId = m_uint32Values[UNIT_FIELD_DISPLAYID];
                if (creature)
                {
                    CreatureTemplate const* cinfo = creature->GetCreatureTemplate();

                    // this also applies for transform auras
                    if (SpellInfo const* transform = sSpellMgr->GetSpellInfo(GetTransformSpell()))
                    {
                        for (SpellEffectInfo const& spellEffectInfo : transform->GetEffects())
                        {
                            if (spellEffectInfo.IsAura(SPELL_AURA_TRANSFORM))
                            {
                                if (CreatureTemplate const* transformInfo = sObjectMgr->GetCreatureTemplate(spellEffectInfo.MiscValue))
                                {
                                    cinfo = transformInfo;
                                    break;
                                }
                            }
                        }
                    }

                    if (cinfo->flags_extra & CREATURE_FLAG_EXTRA_TRIGGER)
                        if (target->IsGameMaster())
                            displayId = cinfo->GetFirstVisibleModel();
                }

                fieldBuffer << uint32(displayId);
            }
            // hide lootable animation for unallowed players
            else if (index == UNIT_DYNAMIC_FLAGS)
            {
                uint32 dynamicFlags = m_uint32Values[UNIT_DYNAMIC_FLAGS] & ~(UNIT_DYNFLAG_TAPPED | UNIT_DYNFLAG_TAPPED_BY_PLAYER);

                if (creature)
                {
                    if (creature->hasLootRecipient())
                    {
                        dynamicFlags |= UNIT_DYNFLAG_TAPPED;
                        if (creature->isTappedBy(target))
                            dynamicFlags |= UNIT_DYNFLAG_TAPPED_BY_PLAYER;
                    }

                    if (!target->isAllowedToLoot(creature))
                        dynamicFlags &= ~UNIT_DYNFLAG_LOOTABLE;
                }

                // unit UNIT_DYNFLAG_TRACK_UNIT should only be sent to caster of SPELL_AURA_MOD_STALKED auras
                if (dynamicFlags & UNIT_DYNFLAG_TRACK_UNIT)
                    if (!HasAuraTypeWithCaster(SPELL_AURA_MOD_STALKED, target->GetGUID()))
                        dynamicFlags &= ~UNIT_DYNFLAG_TRACK_UNIT;

                fieldBuffer << dynamicFlags;
            }
            // FG: pretend that OTHER players in own group are friendly ("blue")
            else if (index == UNIT_FIELD_BYTES_2 || index == UNIT_FIELD_FACTIONTEMPLATE)
            {
                if (IsControlledByPlayer() && target != this && sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GROUP) && IsInRaidWith(target))
                {
                    FactionTemplateEntry const* ft1 = GetFactionTemplateEntry();
                    FactionTemplateEntry const* ft2 = target->GetFactionTemplateEntry();
                    if (!ft1->IsFriendlyTo(*ft2))
                    {
                        if (index == UNIT_FIELD_BYTES_2)
                            // Allow targetting opposite faction in party when enabled in config
                            fieldBuffer << (m_uint32Values[UNIT_FIELD_BYTES_2] & ((UNIT_BYTE2_FLAG_SANCTUARY /*| UNIT_BYTE2_FLAG_AURAS | UNIT_BYTE2_FLAG_UNK5*/) << 8)); // this flag is at uint8 offset 1 !!
                        else
                            // pretend that all other HOSTILE players have own faction, to allow follow, heal, rezz (trade wont work)
                            fieldBuffer << uint32(target->GetFaction());
                    }
                    else
                        fieldBuffer << m_uint32Values[index];
                }
                else
                    fieldBuffer << m_uint32Values[index];
            }
            else
            {
                // send in current format (float as float, uint32 as uint32)
                fieldBuffer << m_uint32Values[index];
            }
        }
    }

    updateMask.AppendToPacket(data);
    data->append(fieldBuffer);
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
    for (uint32 i = 0 ; i < MAX_SPELL_EFFECTS; ++i)
        if (AuraEffect const* aurEff = aura->GetEffect(i))
            if (!IsHighestExclusiveAuraEffect(aura->GetSpellInfo(), aurEff->GetAuraType(), aurEff->GetAmount(), aura->GetEffectMask(), removeOtherAuraApplications))
                return false;

    return true;
}

bool Unit::IsHighestExclusiveAuraEffect(SpellInfo const* spellInfo, AuraType auraType, int32 effectAmount, uint8 auraEffectMask, bool removeOtherAuraApplications /*= false*/)
{
    AuraEffectList const& auras = GetAuraEffectsByType(auraType);
    for (Unit::AuraEffectList::const_iterator itr = auras.begin(); itr != auras.end();)
    {
        AuraEffect const* existingAurEff = (*itr);
        ++itr;

        if (sSpellMgr->CheckSpellGroupStackRules(spellInfo, existingAurEff->GetSpellInfo()) == SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST)
        {
            int32 diff = abs(effectAmount) - abs(existingAurEff->GetAmount());
            if (!diff)
                for (int32 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                    diff += int32((auraEffectMask & (1 << i)) >> i) - int32((existingAurEff->GetBase()->GetEffectMask() & (1 << i)) >> i);

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
    Trinity::LocalizedPacketDo<Trinity::CustomChatTextBuilder> localizer(builder);
    Trinity::PlayerDistWorker<Trinity::LocalizedPacketDo<Trinity::CustomChatTextBuilder> > worker(this, textRange, localizer);
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
    WorldPacket data;
    ChatHandler::BuildChatPacket(data, isBossWhisper ? CHAT_MSG_RAID_BOSS_WHISPER : CHAT_MSG_MONSTER_WHISPER, language, this, target, text, 0, "", locale);
    target->SendDirectMessage(&data);
}

uint32 Unit::GetVirtualItemId(uint32 slot) const
{
    if (slot >= MAX_EQUIPMENT_ITEMS)
        return 0;

    return GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + slot);
}

void Unit::SetVirtualItem(uint32 slot, uint32 itemId)
{
    if (slot >= MAX_EQUIPMENT_ITEMS)
        return;

    SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + slot, itemId);
}

void Unit::Talk(uint32 textId, ChatMsg msgType, float textRange, WorldObject const* target)
{
    if (!sObjectMgr->GetBroadcastText(textId))
    {
        TC_LOG_ERROR("entities.unit", "WorldObject::MonsterText: `broadcast_text` (ID: {}) was not found", textId);
        return;
    }

    Trinity::BroadcastTextBuilder builder(this, msgType, textId, GetGender(), target);
    Trinity::LocalizedPacketDo<Trinity::BroadcastTextBuilder> localizer(builder);
    Trinity::PlayerDistWorker<Trinity::LocalizedPacketDo<Trinity::BroadcastTextBuilder> > worker(this, textRange, localizer);
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

    BroadcastText const* bct = sObjectMgr->GetBroadcastText(textId);
    if (!bct)
    {
        TC_LOG_ERROR("entities.unit", "WorldObject::MonsterWhisper: `broadcast_text` was not {} found", textId);
        return;
    }

    LocaleConstant locale = target->GetSession()->GetSessionDbLocaleIndex();
    WorldPacket data;
    ChatHandler::BuildChatPacket(data, isBossWhisper ? CHAT_MSG_RAID_BOSS_WHISPER : CHAT_MSG_MONSTER_WHISPER, LANG_UNIVERSAL, this, target, bct->GetText(locale, GetGender()), 0, "", locale);
    target->SendDirectMessage(&data);
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
        << "GetGameClientMovingMe(): " << (GetGameClientMovingMe() ? GetGameClientMovingMe()->GetDebugInfo() : "NULL") << "\n"
        << "m_Controlled size: " << m_Controlled.size();

    size_t controlledCount = 0;
    for (Unit* controlled : m_Controlled)
    {
        ++controlledCount;
        sstr << "\n" << "m_Controlled " << controlledCount << " : " << controlled->GetGUID().ToString();
    }

    return sstr.str();
}
