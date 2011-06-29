/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "Common.h"
#include "CreatureAIImpl.h"
#include "Log.h"
#include "Opcodes.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "World.h"
#include "ObjectMgr.h"
#include "SpellMgr.h"
#include "Unit.h"
#include "QuestDef.h"
#include "Player.h"
#include "Creature.h"
#include "Spell.h"
#include "Group.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "MapManager.h"
#include "ObjectAccessor.h"
#include "CreatureAI.h"
#include "Formulas.h"
#include "Pet.h"
#include "Util.h"
#include "Totem.h"
#include "Battleground.h"
#include "OutdoorPvP.h"
#include "InstanceSaveMgr.h"
#include "GridNotifiersImpl.h"
#include "CellImpl.h"
#include "Path.h"
#include "CreatureGroups.h"
#include "PetAI.h"
#include "PassiveAI.h"
#include "Traveller.h"
#include "TemporarySummon.h"
#include "Vehicle.h"
#include "Transport.h"
#include "InstanceScript.h"

#include <math.h>

float baseMoveSpeed[MAX_MOVE_TYPE] =
{
    2.5f,                  // MOVE_WALK
    7.0f,                  // MOVE_RUN
    2.5f,                  // MOVE_RUN_BACK
    4.722222f,             // MOVE_SWIM
    4.5f,                  // MOVE_SWIM_BACK
    3.141594f,             // MOVE_TURN_RATE
    7.0f,                  // MOVE_FLIGHT
    4.5f,                  // MOVE_FLIGHT_BACK
    3.14f                  // MOVE_PITCH_RATE
};
float playerBaseMoveSpeed[MAX_MOVE_TYPE] = {
    2.5f,                  // MOVE_WALK
    7.0f,                  // MOVE_RUN
    2.5f,                  // MOVE_RUN_BACK
    4.722222f,             // MOVE_SWIM
    4.5f,                  // MOVE_SWIM_BACK
    3.141594f,             // MOVE_TURN_RATE
    7.0f,                  // MOVE_FLIGHT
    4.5f,                  // MOVE_FLIGHT_BACK
    3.14f                  // MOVE_PITCH_RATE
};

// Used for prepare can/can`t triggr aura
static bool InitTriggerAuraData();
// Define can trigger auras
static bool isTriggerAura[TOTAL_AURAS];
// Define can`t trigger auras (need for disable second trigger)
static bool isNonTriggerAura[TOTAL_AURAS];
// Triggered always, even from triggered spells
static bool isAlwaysTriggeredAura[TOTAL_AURAS];
// Prepare lists
static bool procPrepared = InitTriggerAuraData();

// we can disable this warning for this since it only
// causes undefined behavior when passed to the base class constructor
#ifdef _MSC_VER
#pragma warning(disable:4355)
#endif
Unit::Unit(): WorldObject(),
m_movedPlayer(NULL), m_lastSanctuaryTime(0), IsAIEnabled(false), NeedChangeAI(false),
m_ControlledByPlayer(false), i_AI(NULL), i_disabledAI(NULL), m_procDeep(0),
m_removedAurasCount(0), i_motionMaster(this), m_ThreatManager(this), m_vehicle(NULL),
m_vehicleKit(NULL), m_unitTypeMask(UNIT_MASK_NONE), m_HostileRefManager(this)
{
#ifdef _MSC_VER
#pragma warning(default:4355)
#endif
    m_objectType |= TYPEMASK_UNIT;
    m_objectTypeId = TYPEID_UNIT;

    m_updateFlag = (UPDATEFLAG_HIGHGUID | UPDATEFLAG_LIVING | UPDATEFLAG_HAS_POSITION);

    m_attackTimer[BASE_ATTACK] = 0;
    m_attackTimer[OFF_ATTACK] = 0;
    m_attackTimer[RANGED_ATTACK] = 0;
    m_modAttackSpeedPct[BASE_ATTACK] = 1.0f;
    m_modAttackSpeedPct[OFF_ATTACK] = 1.0f;
    m_modAttackSpeedPct[RANGED_ATTACK] = 1.0f;

    m_extraAttacks = 0;
    m_canDualWield = false;

    m_rootTimes = 0;

    m_state = 0;
    m_deathState = ALIVE;

    for (uint8 i = 0; i < CURRENT_MAX_SPELL; ++i)
        m_currentSpells[i] = NULL;

    m_addDmgOnce = 0;

    for (uint8 i = 0; i < MAX_SUMMON_SLOT; ++i)
        m_SummonSlot[i] = 0;

    m_ObjectSlot[0] = m_ObjectSlot[1] = m_ObjectSlot[2] = m_ObjectSlot[3] = 0;

    m_auraUpdateIterator = m_ownedAuras.end();

    m_interruptMask = 0;
    m_transform = 0;
    m_canModifyStats = false;

    for (uint8 i = 0; i < MAX_SPELL_IMMUNITY; ++i)
        m_spellImmune[i].clear();
    for (uint8 i = 0; i < UNIT_MOD_END; ++i)
    {
        m_auraModifiersGroup[i][BASE_VALUE] = 0.0f;
        m_auraModifiersGroup[i][BASE_PCT] = 1.0f;
        m_auraModifiersGroup[i][TOTAL_VALUE] = 0.0f;
        m_auraModifiersGroup[i][TOTAL_PCT] = 1.0f;
    }
                                                            // implement 50% base damage from offhand
    m_auraModifiersGroup[UNIT_MOD_DAMAGE_OFFHAND][TOTAL_PCT] = 0.5f;

    for (uint8 i = 0; i < MAX_ATTACK; ++i)
    {
        m_weaponDamage[i][MINDAMAGE] = BASE_MINDAMAGE;
        m_weaponDamage[i][MAXDAMAGE] = BASE_MAXDAMAGE;
    }
    for (uint8 i = 0; i < MAX_STATS; ++i)
        m_createStats[i] = 0.0f;

    m_attacking = NULL;
    m_modMeleeHitChance = 0.0f;
    m_modRangedHitChance = 0.0f;
    m_modSpellHitChance = 0.0f;
    m_baseSpellCritChance = 5;

    m_CombatTimer = 0;
    m_lastManaUse = 0;

    for (uint8 i = 0; i < MAX_SPELL_SCHOOL; ++i)
        m_threatModifier[i] = 1.0f;
    m_isSorted = true;
    for (uint8 i = 0; i < MAX_MOVE_TYPE; ++i)
        m_speed_rate[i] = 1.0f;

    m_charmInfo = NULL;
    m_reducedThreatPercent = 0;
    m_misdirectionTargetGUID = 0;

    // remove aurastates allowing special moves
    for (uint8 i = 0; i < MAX_REACTIVE; ++i)
        m_reactiveTimer[i] = 0;

    m_cleanupDone = false;
    m_duringRemoveFromWorld = false;

    m_serverSideVisibility.SetValue(SERVERSIDE_VISIBILITY_GHOST, GHOST_VISIBILITY_ALIVE);
}

////////////////////////////////////////////////////////////
// Methods of class GlobalCooldownMgr
bool GlobalCooldownMgr::HasGlobalCooldown(SpellEntry const* spellInfo) const
{
    GlobalCooldownList::const_iterator itr = m_GlobalCooldowns.find(spellInfo->StartRecoveryCategory);
    return itr != m_GlobalCooldowns.end() && itr->second.duration && getMSTimeDiff(itr->second.cast_time, getMSTime()) < itr->second.duration;
}

void GlobalCooldownMgr::AddGlobalCooldown(SpellEntry const* spellInfo, uint32 gcd)
{
    m_GlobalCooldowns[spellInfo->StartRecoveryCategory] = GlobalCooldown(gcd, getMSTime());
}

void GlobalCooldownMgr::CancelGlobalCooldown(SpellEntry const* spellInfo)
{
    m_GlobalCooldowns[spellInfo->StartRecoveryCategory].duration = 0;
}

////////////////////////////////////////////////////////////
// Methods of class Unit
Unit::~Unit()
{
    // set current spells as deletable
    for (uint8 i = 0; i < CURRENT_MAX_SPELL; ++i)
    {
        if (m_currentSpells[i])
        {
            m_currentSpells[i]->SetReferencedFromCurrent(false);
            m_currentSpells[i] = NULL;
        }
    }

    _DeleteRemovedAuras();

    delete m_charmInfo;
    delete m_vehicleKit;

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

    if (CanHaveThreatList() && getThreatManager().isNeedUpdateToClient(p_time))
        SendThreatListUpdate();

    // update combat timer only for players and pets (only pets with PetAI)
    if (isInCombat() && (GetTypeId() == TYPEID_PLAYER || (ToCreature()->isPet() && IsControlledByPlayer())))
    {
        // Check UNIT_STAT_MELEE_ATTACKING or UNIT_STAT_CHASE (without UNIT_STAT_FOLLOW in this case) so pets can reach far away
        // targets without stopping half way there and running off.
        // These flags are reset after target dies or another command is given.
        if (m_HostileRefManager.isEmpty())
        {
            // m_CombatTimer set at aura start and it will be freeze until aura removing
            if (m_CombatTimer <= p_time)
                ClearInCombat();
            else
                m_CombatTimer -= p_time;
        }
    }

    // not implemented before 3.0.2
    //if (!HasUnitState(UNIT_STAT_CASTING))
    {
        if (uint32 base_att = getAttackTimer(BASE_ATTACK))
            setAttackTimer(BASE_ATTACK, (p_time >= base_att ? 0 : base_att - p_time));
        if (uint32 ranged_att = getAttackTimer(RANGED_ATTACK))
            setAttackTimer(RANGED_ATTACK, (p_time >= ranged_att ? 0 : ranged_att - p_time));
        if (uint32 off_att = getAttackTimer(OFF_ATTACK))
            setAttackTimer(OFF_ATTACK, (p_time >= off_att ? 0 : off_att - p_time));
    }

    // update abilities available only for fraction of time
    UpdateReactives(p_time);

    ModifyAuraState(AURA_STATE_HEALTHLESS_20_PERCENT, HealthBelowPct(20));
    ModifyAuraState(AURA_STATE_HEALTHLESS_35_PERCENT, HealthBelowPct(35));
    ModifyAuraState(AURA_STATE_HEALTH_ABOVE_75_PERCENT, HealthAbovePct(75));

    i_motionMaster.UpdateMotion(p_time);
}

bool Unit::haveOffhandWeapon() const
{
    if (GetTypeId() == TYPEID_PLAYER)
        return ToPlayer()->GetWeaponForAttack(OFF_ATTACK, true);
    else
        return m_canDualWield;
}

void Unit::SendMonsterMoveWithSpeedToCurrentDestination(Player* player)
{
    float x, y, z;
    if (GetMotionMaster()->GetDestination(x, y, z))
        SendMonsterMoveWithSpeed(x, y, z, 0, player);
}

void Unit::SendMonsterMoveWithSpeed(float x, float y, float z, uint32 transitTime, Player* player)
{
    if (!transitTime)
    {
        if (GetTypeId() == TYPEID_PLAYER)
        {
            Traveller<Player> traveller(*(Player*)this);
            transitTime = traveller.GetTotalTrevelTimeTo(x, y, z);
        }
        else
        {
            Traveller<Creature> traveller(*this->ToCreature());
            transitTime = traveller.GetTotalTrevelTimeTo(x, y, z);
        }
    }
    //float orientation = (float)atan2((double)dy, (double)dx);
    SendMonsterMove(x, y, z, transitTime, player);
}

void Unit::SetFacing(float ori, WorldObject* obj)
{
    SetOrientation(obj ? GetAngle(obj) : ori);

    WorldPacket data(SMSG_MONSTER_MOVE, (1+12+4+1+(obj ? 8 : 4)+4+4+4+12+GetPackGUID().size()));
    data.append(GetPackGUID());
    data << uint8(0); // unk
    data << GetPositionX() << GetPositionY() << GetPositionZ();
    data << getMSTime();
    if (obj)
    {
        data << uint8(SPLINETYPE_FACING_TARGET);
        data << uint64(obj->GetGUID());
    }
    else
    {
        data << uint8(SPLINETYPE_FACING_ANGLE);
        data << ori;
    }
    data << uint32(SPLINEFLAG_NONE);
    data << uint32(0); // move time 0
    data << uint32(1); // one point
    data << GetPositionX() << GetPositionY() << GetPositionZ();
    SendMessageToSet(&data, true);
}

void Unit::SendMonsterStop(bool on_death)
{
    WorldPacket data(SMSG_MONSTER_MOVE, (17 + GetPackGUID().size()));
    data.append(GetPackGUID());
    data << uint8(0);                                       // new in 3.1
    data << GetPositionX() << GetPositionY() << GetPositionZ();
    data << getMSTime();

    if (on_death == true)
    {
        data << uint8(0);
        data << uint32((GetUnitMovementFlags() & MOVEMENTFLAG_LEVITATING) ? SPLINEFLAG_FLYING : SPLINEFLAG_WALKING);
        data << uint32(0);                                      // Time in between points
        data << uint32(1);                                      // 1 single waypoint
        data << GetPositionX() << GetPositionY() << GetPositionZ();
    }
    else
        data << uint8(1);

    SendMessageToSet(&data, true);

    ClearUnitState(UNIT_STAT_MOVE);
}

void Unit::SendMonsterMove(float NewPosX, float NewPosY, float NewPosZ, uint32 Time, Player* player)
{
    WorldPacket data(SMSG_MONSTER_MOVE, 1+12+4+1+4+4+4+12+GetPackGUID().size());
    data.append(GetPackGUID());

    data << uint8(0);                                       // new in 3.1
    data << GetPositionX() << GetPositionY() << GetPositionZ();
    data << getMSTime();

    data << uint8(0);
    data << uint32((GetUnitMovementFlags() & MOVEMENTFLAG_LEVITATING) ? SPLINEFLAG_FLYING : SPLINEFLAG_WALKING);
    data << Time;                                           // Time in between points
    data << uint32(1);                                      // 1 single waypoint
    data << NewPosX << NewPosY << NewPosZ;                  // the single waypoint Point B

    if (player)
        player->GetSession()->SendPacket(&data);
    else
        SendMessageToSet(&data, true);

    AddUnitState(UNIT_STAT_MOVE);
}

void Unit::SendMonsterMove(float NewPosX, float NewPosY, float NewPosZ, uint32 MoveFlags, uint32 time, float speedZ, Player* player)
{
    WorldPacket data(SMSG_MONSTER_MOVE, 12+4+1+4+4+4+12+GetPackGUID().size());
    data.append(GetPackGUID());

    data << uint8(0);                                       // new in 3.1
    data << GetPositionX() << GetPositionY() << GetPositionZ();
    data << getMSTime();

    data << uint8(0);
    data << MoveFlags;

    if (MoveFlags & SPLINEFLAG_TRAJECTORY)
    {
        data << time;
        data << speedZ;
        data << (uint32)0; // walk time after jump
    }
    else
        data << time;

    data << uint32(1);                                      // 1 single waypoint
    data << NewPosX << NewPosY << NewPosZ;                  // the single waypoint Point B

    if (player)
        player->GetSession()->SendPacket(&data);
    else
        SendMessageToSet(&data, true);
}

void Unit::SendMonsterMoveExitVehicle(Position const* newPos)
{
    WorldPacket data(SMSG_MONSTER_MOVE, 1+12+4+1+4+4+4+12+GetPackGUID().size());
    data.append(GetPackGUID());

    data << uint8(GetTypeId() == TYPEID_PLAYER ? 1 : 0);    // new in 3.1, bool
    data << GetPositionX() << GetPositionY() << GetPositionZ();
    data << getMSTime();

    data << uint8(SPLINETYPE_FACING_ANGLE);
    data << float(GetOrientation());                        // guess
    data << uint32(SPLINEFLAG_EXIT_VEHICLE);
    data << uint32(0);                                      // Time in between points
    data << uint32(1);                                      // 1 single waypoint
    data << newPos->GetPositionX();
    data << newPos->GetPositionY();
    data << newPos->GetPositionZ();

    SendMessageToSet(&data, true);
}

void Unit::SendMonsterMoveTransport(Unit *vehicleOwner)
{
    // TODO: Turn into BuildMonsterMoveTransport packet and allow certain variables (for npc movement aboard vehicles)
    WorldPacket data(SMSG_MONSTER_MOVE_TRANSPORT, GetPackGUID().size()+vehicleOwner->GetPackGUID().size() + 47);
    data.append(GetPackGUID());
    data.append(vehicleOwner->GetPackGUID());
    data << int8(GetTransSeat());
    data << uint8(GetTypeId() == TYPEID_PLAYER ? 1 : 0); // boolean
    data << GetPositionX() - vehicleOwner->GetPositionX();
    data << GetPositionY() - vehicleOwner->GetPositionY();
    data << GetPositionZ() - vehicleOwner->GetPositionZ();
    data << uint32(getMSTime());            // should be an increasing constant that indicates movement packet count
    data << uint8(SPLINETYPE_FACING_ANGLE);
    data << GetTransOffsetO();              // facing angle?
    data << uint32(SPLINEFLAG_TRANSPORT);
    data << uint32(GetTransTime());         // move time
    data << uint32(1);                      // amount of waypoints
    data << uint32(0);                      // waypoint X
    data << uint32(0);                      // waypoint Y
    data << uint32(0);                      // waypoint Z
    SendMessageToSet(&data, true);
}

void Unit::resetAttackTimer(WeaponAttackType type)
{
    m_attackTimer[type] = uint32(GetAttackTime(type) * m_modAttackSpeedPct[type]);
}

bool Unit::IsWithinCombatRange(const Unit *obj, float dist2compare) const
{
    if (!obj || !IsInMap(obj)) return false;

    float dx = GetPositionX() - obj->GetPositionX();
    float dy = GetPositionY() - obj->GetPositionY();
    float dz = GetPositionZ() - obj->GetPositionZ();
    float distsq = dx*dx + dy*dy + dz*dz;

    float sizefactor = GetCombatReach() + obj->GetCombatReach();
    float maxdist = dist2compare + sizefactor;

    return distsq < maxdist * maxdist;
}

bool Unit::IsWithinMeleeRange(const Unit *obj, float dist) const
{
    if (!obj || !IsInMap(obj)) return false;

    float dx = GetPositionX() - obj->GetPositionX();
    float dy = GetPositionY() - obj->GetPositionY();
    float dz = GetPositionZ() - obj->GetPositionZ();
    float distsq = dx*dx + dy*dy + dz*dz;

    float sizefactor = GetMeleeReach() + obj->GetMeleeReach();
    float maxdist = dist + sizefactor;

    return distsq < maxdist * maxdist;
}

void Unit::GetRandomContactPoint(const Unit* obj, float &x, float &y, float &z, float distance2dMin, float distance2dMax) const
{
    float combat_reach = GetCombatReach();
    if (combat_reach < 0.1) // sometimes bugged for players
    {
        //sLog->outError("Unit %u (Type: %u) has invalid combat_reach %f", GetGUIDLow(), GetTypeId(), combat_reach);
        //if (GetTypeId() == TYPEID_UNIT)
        //    sLog->outError("Creature entry %u has invalid combat_reach", ToCreature()->GetEntry());
        combat_reach = DEFAULT_COMBAT_REACH;
    }
    uint32 attacker_number = getAttackers().size();
    if (attacker_number > 0)
        --attacker_number;
    GetNearPoint(obj, x, y, z, obj->GetCombatReach(), distance2dMin+(distance2dMax-distance2dMin) * (float)rand_norm()
        , GetAngle(obj) + (attacker_number ? (static_cast<float>(M_PI/2) - static_cast<float>(M_PI) * (float)rand_norm()) * float(attacker_number) / combat_reach * 0.3f : 0));
}

void Unit::UpdateInterruptMask()
{
    m_interruptMask = 0;
    for (AuraApplicationList::const_iterator i = m_interruptableAuras.begin(); i != m_interruptableAuras.end(); ++i)
        m_interruptMask |= (*i)->GetBase()->GetSpellProto()->AuraInterruptFlags;

    if (Spell* spell = m_currentSpells[CURRENT_CHANNELED_SPELL])
        if (spell->getState() == SPELL_STATE_CASTING)
            m_interruptMask |= spell->m_spellInfo->ChannelInterruptFlags;
}

bool Unit::HasAuraTypeWithFamilyFlags(AuraType auraType, uint32 familyName, uint32 familyFlags) const
{
    if (!HasAuraType(auraType))
        return false;
    AuraEffectList const& auras = GetAuraEffectsByType(auraType);
    for (AuraEffectList::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
        if (SpellEntry const* iterSpellProto = (*itr)->GetSpellProto())
            if (iterSpellProto->SpellFamilyName == familyName && iterSpellProto->SpellFamilyFlags[0] & familyFlags)
                return true;
    return false;
}

void Unit::DealDamageMods(Unit *pVictim, uint32 &damage, uint32* absorb)
{
    if (!pVictim->isAlive() || pVictim->HasUnitState(UNIT_STAT_IN_FLIGHT) || (pVictim->GetTypeId() == TYPEID_UNIT && pVictim->ToCreature()->IsInEvadeMode()))
    {
        if (absorb)
            *absorb += damage;
        damage = 0;
        return;
    }

    uint32 originalDamage = damage;

    if (absorb && originalDamage > damage)
        *absorb += (originalDamage - damage);
}

uint32 Unit::DealDamage(Unit *pVictim, uint32 damage, CleanDamage const* cleanDamage, DamageEffectType damagetype, SpellSchoolMask damageSchoolMask, SpellEntry const *spellProto, bool durabilityLoss)
{
    if (pVictim->IsAIEnabled)
        pVictim->GetAI()->DamageTaken(this, damage);

    if (IsAIEnabled)
        GetAI()->DamageDealt(pVictim, damage, damagetype);

    if (damagetype != NODAMAGE)
    {
        // interrupting auras with AURA_INTERRUPT_FLAG_DAMAGE before checking !damage (absorbed damage breaks that type of auras)
        if (spellProto)
        {
            if (!(spellProto->AttributesEx4 & SPELL_ATTR4_DAMAGE_DOESNT_BREAK_AURAS))
                pVictim->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TAKE_DAMAGE, spellProto->Id);
        }
        else
            pVictim->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TAKE_DAMAGE, 0);

        // We're going to call functions which can modify content of the list during iteration over it's elements
        // Let's copy the list so we can prevent iterator invalidation
        AuraEffectList vCopyDamageCopy(pVictim->GetAuraEffectsByType(SPELL_AURA_SHARE_DAMAGE_PCT));
        // copy damage to casters of this aura
        for (AuraEffectList::iterator i = vCopyDamageCopy.begin(); i != vCopyDamageCopy.end(); ++i)
        {
            // Check if aura was removed during iteration - we don't need to work on such auras
            if (!((*i)->GetBase()->IsAppliedOnTarget(pVictim->GetGUID())))
                continue;
            // check damage school mask
            if (((*i)->GetMiscValue() & damageSchoolMask) == 0)
                continue;

            Unit* shareDamageTarget = (*i)->GetCaster();
            if (!shareDamageTarget)
                continue;
            SpellEntry const* spell = (*i)->GetSpellProto();

            uint32 share = CalculatePctN(damage, (*i)->GetAmount());

            // TODO: check packets if damage is done by pVictim, or by attacker of pVictim
            DealDamageMods(shareDamageTarget, share, NULL);
            DealDamage(shareDamageTarget, share, NULL, NODAMAGE, GetSpellSchoolMask(spell), spell, false);
        }
    }

    // Rage from Damage made (only from direct weapon damage)
    if (cleanDamage && damagetype == DIRECT_DAMAGE && this != pVictim && getPowerType() == POWER_RAGE)
    {
        uint32 weaponSpeedHitFactor;
        uint32 rage_damage = damage + cleanDamage->absorbed_damage;

        switch(cleanDamage->attackType)
        {
            case BASE_ATTACK:
            {
                weaponSpeedHitFactor = uint32(GetAttackTime(cleanDamage->attackType) / 1000.0f * 3.5f);
                if (cleanDamage->hitOutCome == MELEE_HIT_CRIT)
                    weaponSpeedHitFactor *= 2;

                RewardRage(rage_damage, weaponSpeedHitFactor, true);

                break;
            }
            case OFF_ATTACK:
            {
                weaponSpeedHitFactor = uint32(GetAttackTime(cleanDamage->attackType) / 1000.0f * 1.75f);
                if (cleanDamage->hitOutCome == MELEE_HIT_CRIT)
                    weaponSpeedHitFactor *= 2;

                RewardRage(rage_damage, weaponSpeedHitFactor, true);

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
        if (cleanDamage && cleanDamage->absorbed_damage && pVictim->getPowerType() == POWER_RAGE)
            pVictim->RewardRage(cleanDamage->absorbed_damage, 0, false);

        return 0;
    }

    sLog->outStaticDebug("DealDamageStart");

    uint32 health = pVictim->GetHealth();
    sLog->outDetail("deal dmg:%d to health:%d ", damage, health);

    // duel ends when player has 1 or less hp
    bool duel_hasEnded = false;
    if (pVictim->GetTypeId() == TYPEID_PLAYER && pVictim->ToPlayer()->duel && damage >= (health-1))
    {
        // prevent kill only if killed in duel and killed by opponent or opponent controlled creature
        if (pVictim->ToPlayer()->duel->opponent == this || pVictim->ToPlayer()->duel->opponent->GetGUID() == GetOwnerGUID())
            damage = health - 1;

        duel_hasEnded = true;
    }

    if (GetTypeId() == TYPEID_PLAYER && this != pVictim)
    {
        Player* killer = ToPlayer();

        // in bg, count dmg if victim is also a player
        if (pVictim->GetTypeId() == TYPEID_PLAYER)
            if (Battleground *bg = killer->GetBattleground())
                bg->UpdatePlayerScore(killer, SCORE_DAMAGE_DONE, damage);

        killer->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_DAMAGE_DONE, damage, 0, pVictim);
        killer->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HIT_DEALT, damage);
    }

    if (pVictim->GetTypeId() == TYPEID_PLAYER)
        pVictim->ToPlayer()->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HIT_RECEIVED, damage);
    else if (!pVictim->IsControlledByPlayer() || pVictim->IsVehicle())
    {
        if (!pVictim->ToCreature()->hasLootRecipient())
            pVictim->ToCreature()->SetLootRecipient(this);

        if (IsControlledByPlayer())
            pVictim->ToCreature()->LowerPlayerDamageReq(health < damage ?  health : damage);
    }

    if (health <= damage)
    {
        sLog->outStaticDebug("DealDamage: victim just died");

        if (pVictim->GetTypeId() == TYPEID_PLAYER && pVictim != this)
        {
            pVictim->ToPlayer()->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_TOTAL_DAMAGE_RECEIVED, health);

            // call before auras are removed
            if (Player* killer = ToPlayer())
                killer->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_SPECIAL_PVP_KILL, 1, 0, pVictim);
        }

        Kill(pVictim, durabilityLoss);
    }
    else
    {
        sLog->outStaticDebug("DealDamageAlive");

        if (pVictim->GetTypeId() == TYPEID_PLAYER)
            pVictim->ToPlayer()->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_TOTAL_DAMAGE_RECEIVED, damage);

        pVictim->ModifyHealth(- (int32)damage);

        if (damagetype == DIRECT_DAMAGE || damagetype == SPELL_DIRECT_DAMAGE)
            pVictim->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_DIRECT_DAMAGE, spellProto ? spellProto->Id : 0);

        if (pVictim->GetTypeId() != TYPEID_PLAYER)
        {
            if (spellProto && IsDamageToThreatSpell(spellProto))
                pVictim->AddThreat(this, damage * 2.0f, damageSchoolMask, spellProto);
            else
                pVictim->AddThreat(this, (float)damage, damageSchoolMask, spellProto);
        }
        else                                                // victim is a player
        {
            // random durability for items (HIT TAKEN)
            if (roll_chance_f(sWorld->getRate(RATE_DURABILITY_LOSS_DAMAGE)))
            {
                EquipmentSlots slot = EquipmentSlots(urand(0, EQUIPMENT_SLOT_END-1));
                pVictim->ToPlayer()->DurabilityPointLossForEquipSlot(slot);
            }
        }

        // Rage from damage received
        if (this != pVictim && pVictim->getPowerType() == POWER_RAGE)
        {
            uint32 rage_damage = damage + (cleanDamage ? cleanDamage->absorbed_damage : 0);
            pVictim->RewardRage(rage_damage, 0, false);
        }

        if (GetTypeId() == TYPEID_PLAYER)
        {
            // random durability for items (HIT DONE)
            if (roll_chance_f(sWorld->getRate(RATE_DURABILITY_LOSS_DAMAGE)))
            {
                EquipmentSlots slot = EquipmentSlots(urand(0, EQUIPMENT_SLOT_END-1));
                ToPlayer()->DurabilityPointLossForEquipSlot(slot);
            }
        }

        if (damagetype != NODAMAGE && damage)
        {
            if (pVictim != this && pVictim->GetTypeId() == TYPEID_PLAYER) // does not support creature push_back
            {
                if (damagetype != DOT)
                {
                    if (Spell* spell = pVictim->m_currentSpells[CURRENT_GENERIC_SPELL])
                    {
                        if (spell->getState() == SPELL_STATE_PREPARING)
                        {
                            uint32 interruptFlags = spell->m_spellInfo->InterruptFlags;
                            if (interruptFlags & SPELL_INTERRUPT_FLAG_ABORT_ON_DMG)
                                pVictim->InterruptNonMeleeSpells(false);
                            else if (interruptFlags & SPELL_INTERRUPT_FLAG_PUSH_BACK)
                                spell->Delayed();
                        }
                    }
                }

                if (Spell* spell = pVictim->m_currentSpells[CURRENT_CHANNELED_SPELL])
                {
                    if (spell->getState() == SPELL_STATE_CASTING)
                    {
                        uint32 channelInterruptFlags = spell->m_spellInfo->ChannelInterruptFlags;
                        if (((channelInterruptFlags & CHANNEL_FLAG_DELAY) != 0) && (damagetype != DOT))
                            spell->DelayedChannel();
                    }
                }
            }
        }

        // last damage from duel opponent
        if (duel_hasEnded)
        {
            ASSERT(pVictim->GetTypeId() == TYPEID_PLAYER);
            Player* he = pVictim->ToPlayer();

            ASSERT(he->duel);

            he->SetHealth(1);

            he->duel->opponent->CombatStopWithPets(true);
            he->CombatStopWithPets(true);

            he->CastSpell(he, 7267, true);                  // beg
            he->DuelComplete(DUEL_WON);
        }
    }

    sLog->outStaticDebug("DealDamageEnd returned %d damage", damage);

    return damage;
}

void Unit::CastStop(uint32 except_spellid)
{
    for (uint32 i = CURRENT_FIRST_NON_MELEE_SPELL; i < CURRENT_MAX_SPELL; i++)
        if (m_currentSpells[i] && m_currentSpells[i]->m_spellInfo->Id != except_spellid)
            InterruptSpell(CurrentSpellTypes(i), false);
}

void Unit::CastSpell(Unit* Victim, uint32 spellId, bool triggered, Item *castItem, AuraEffect const* triggeredByAura, uint64 originalCaster)
{
    SpellEntry const* spellInfo = sSpellStore.LookupEntry(spellId);

    if (!spellInfo)
    {
        sLog->outError("CastSpell: unknown spell id %i by caster: %s %u)", spellId, (GetTypeId() == TYPEID_PLAYER ? "player (GUID:" : "creature (Entry:"), (GetTypeId() == TYPEID_PLAYER ? GetGUIDLow() : GetEntry()));
        return;
    }

    CastSpell(Victim, spellInfo, triggered, castItem, triggeredByAura, originalCaster);
}

void Unit::CastSpell(Unit* Victim, SpellEntry const *spellInfo, bool triggered, Item *castItem, AuraEffect const* triggeredByAura, uint64 originalCaster)
{
    if (!spellInfo)
    {
        sLog->outError("CastSpell: unknown spell by caster: %s %u)", (GetTypeId() == TYPEID_PLAYER ? "player (GUID:" : "creature (Entry:"), (GetTypeId() == TYPEID_PLAYER ? GetGUIDLow() : GetEntry()));
        return;
    }

    if (!originalCaster && GetTypeId() == TYPEID_UNIT && ToCreature()->isTotem() && IsControlledByPlayer())
        if (Unit* owner = GetOwner())
            originalCaster=owner->GetGUID();

    SpellCastTargets targets;
    targets.SetUnitTarget(Victim);

    if (castItem)
        sLog->outStaticDebug("WORLD: cast Item spellId - %i", spellInfo->Id);

    if (!originalCaster && triggeredByAura)
        originalCaster = triggeredByAura->GetCasterGUID();

    Spell* spell = new Spell(this, spellInfo, triggered, originalCaster);

    spell->m_CastItem = castItem;
    spell->prepare(&targets, triggeredByAura);
}

void Unit::CastCustomSpell(Unit* target, uint32 spellId, int32 const* bp0, int32 const* bp1, int32 const* bp2, bool triggered, Item *castItem, AuraEffect const* triggeredByAura, uint64 originalCaster)
{
    CustomSpellValues values;
    if (bp0)
        values.AddSpellMod(SPELLVALUE_BASE_POINT0, *bp0);
    if (bp1)
        values.AddSpellMod(SPELLVALUE_BASE_POINT1, *bp1);
    if (bp2)
        values.AddSpellMod(SPELLVALUE_BASE_POINT2, *bp2);
    CastCustomSpell(spellId, values, target, triggered, castItem, triggeredByAura, originalCaster);
}

void Unit::CastCustomSpell(uint32 spellId, SpellValueMod mod, int32 value, Unit* target, bool triggered, Item *castItem, AuraEffect const* triggeredByAura, uint64 originalCaster)
{
    CustomSpellValues values;
    values.AddSpellMod(mod, value);
    CastCustomSpell(spellId, values, target, triggered, castItem, triggeredByAura, originalCaster);
}

void Unit::CastCustomSpell(uint32 spellId, CustomSpellValues const &value, Unit* Victim, bool triggered, Item *castItem, AuraEffect const* triggeredByAura, uint64 originalCaster)
{
    SpellEntry const* spellInfo = sSpellStore.LookupEntry(spellId);
    if (!spellInfo)
    {
        sLog->outError("CastSpell: unknown spell id %i by caster: %s %u)", spellId, (GetTypeId() == TYPEID_PLAYER ? "player (GUID:" : "creature (Entry:"), (GetTypeId() == TYPEID_PLAYER ? GetGUIDLow() : GetEntry()));
        return;
    }

    SpellCastTargets targets;
    targets.SetUnitTarget(Victim);

    if (!originalCaster && triggeredByAura)
        originalCaster = triggeredByAura->GetCasterGUID();

    Spell* spell = new Spell(this, spellInfo, triggered, originalCaster);

    if (castItem)
    {
        sLog->outStaticDebug("WORLD: cast Item spellId - %i", spellInfo->Id);
        spell->m_CastItem = castItem;
    }

    for (CustomSpellValues::const_iterator itr = value.begin(); itr != value.end(); ++itr)
        spell->SetSpellValue(itr->first, itr->second);

    spell->prepare(&targets, triggeredByAura);
}

// used for scripting
void Unit::CastSpell(float x, float y, float z, uint32 spellId, bool triggered, Item *castItem, AuraEffect const* triggeredByAura, uint64 originalCaster, Unit* OriginalVictim)
{
    SpellEntry const* spellInfo = sSpellStore.LookupEntry(spellId);

    if (!spellInfo)
    {
        sLog->outError("CastSpell(x, y, z): unknown spell id %i by caster: %s %u)", spellId, (GetTypeId() == TYPEID_PLAYER ? "player (GUID:" : "creature (Entry:"), (GetTypeId() == TYPEID_PLAYER ? GetGUIDLow() : GetEntry()));
        return;
    }

    if (castItem)
        sLog->outStaticDebug("WORLD: cast Item spellId - %i", spellInfo->Id);

    if (!originalCaster && triggeredByAura)
        originalCaster = triggeredByAura->GetCasterGUID();

    Spell* spell = new Spell(this, spellInfo, triggered, originalCaster);

    SpellCastTargets targets;
    targets.SetDst(x, y, z, GetOrientation());
    if (OriginalVictim)
        targets.SetUnitTarget(OriginalVictim);
    spell->m_CastItem = castItem;
    spell->prepare(&targets, triggeredByAura);
}

// used for scripting
void Unit::CastSpell(GameObject *go, uint32 spellId, bool triggered, Item *castItem, AuraEffect* triggeredByAura, uint64 originalCaster)
{
    if (!go)
        return;

    SpellEntry const* spellInfo = sSpellStore.LookupEntry(spellId);

    if (!spellInfo)
    {
        sLog->outError("CastSpell(x, y, z): unknown spell id %i by caster: %s %u)", spellId, (GetTypeId() == TYPEID_PLAYER ? "player (GUID:" : "creature (Entry:"), (GetTypeId() == TYPEID_PLAYER ? GetGUIDLow() : GetEntry()));
        return;
    }

    if (!(spellInfo->Targets & (TARGET_FLAG_OBJECT | TARGET_FLAG_OBJECT_CASTER)))
    {
        sLog->outError("CastSpell: spell id %i by caster: %s %u) is not gameobject spell", spellId, (GetTypeId() == TYPEID_PLAYER ? "player (GUID:" : "creature (Entry:"), (GetTypeId() == TYPEID_PLAYER ? GetGUIDLow() : GetEntry()));
        return;
    }

    if (castItem)
        sLog->outStaticDebug("WORLD: cast Item spellId - %i", spellInfo->Id);

    if (!originalCaster && triggeredByAura)
        originalCaster = triggeredByAura->GetCasterGUID();

    Spell* spell = new Spell(this, spellInfo, triggered, originalCaster);

    SpellCastTargets targets;
    targets.SetGOTarget(go);
    spell->m_CastItem = castItem;
    spell->prepare(&targets, triggeredByAura);
}

// Obsolete func need remove, here only for comotability vs another patches
uint32 Unit::SpellNonMeleeDamageLog(Unit *pVictim, uint32 spellID, uint32 damage)
{
    SpellEntry const* spellInfo = sSpellStore.LookupEntry(spellID);
    SpellNonMeleeDamage damageInfo(this, pVictim, spellInfo->Id, spellInfo->SchoolMask);
    damage = SpellDamageBonus(pVictim, spellInfo, damage, SPELL_DIRECT_DAMAGE);
    CalculateSpellDamageTaken(&damageInfo, damage, spellInfo);
    DealDamageMods(damageInfo.target, damageInfo.damage, &damageInfo.absorb);
    SendSpellNonMeleeDamageLog(&damageInfo);
    DealSpellDamage(&damageInfo, true);
    return damageInfo.damage;
}

void Unit::CalculateSpellDamageTaken(SpellNonMeleeDamage *damageInfo, int32 damage, SpellEntry const *spellInfo, WeaponAttackType attackType, bool crit)
{
    if (damage < 0)
        return;

    if (spellInfo->AttributesEx4 & SPELL_ATTR4_FIXED_DAMAGE)
    {
        damageInfo->damage = damage;
        return;
    }

    Unit* pVictim = damageInfo->target;
    if (!pVictim || !pVictim->isAlive())
        return;

    SpellSchoolMask damageSchoolMask = SpellSchoolMask(damageInfo->schoolMask);
    uint32 crTypeMask = pVictim->GetCreatureTypeMask();

    if (IsDamageReducedByArmor(damageSchoolMask, spellInfo))
        damage = CalcArmorReducedDamage(pVictim, damage, spellInfo, attackType);

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
                    // Get blocked status
                    blocked = isSpellBlocked(pVictim, spellInfo, attackType);
                }

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
                    int32 critPctDamageMod = 0;
                    if (attackType == RANGED_ATTACK)
                        critPctDamageMod += pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_RANGED_CRIT_DAMAGE);
                    else
                    {
                        critPctDamageMod += pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_MELEE_CRIT_DAMAGE);
                        critPctDamageMod += GetTotalAuraModifier(SPELL_AURA_MOD_CRIT_DAMAGE_BONUS_MELEE);
                    }
                    // Increase crit damage from SPELL_AURA_MOD_CRIT_PERCENT_VERSUS
                    critPctDamageMod += GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_CRIT_PERCENT_VERSUS, crTypeMask);

                    if (critPctDamageMod != 0)
                        AddPctN(damage, critPctDamageMod);
                }

                // Spell weapon based damage CAN BE crit & blocked at same time
                if (blocked)
                {
                    damageInfo->blocked = pVictim->GetShieldBlockValue();
                    // double blocked amount if block is critical
                    if (pVictim->isBlockCritical())
                        damageInfo->blocked += damageInfo->blocked;
                    if (damage < int32(damageInfo->blocked))
                        damageInfo->blocked = uint32(damage);
                    damage -= damageInfo->blocked;
                }

                if (attackType != RANGED_ATTACK)
                    ApplyResilience(pVictim, NULL, &damage, crit, CR_CRIT_TAKEN_MELEE);
                else
                    ApplyResilience(pVictim, NULL, &damage, crit, CR_CRIT_TAKEN_RANGED);
            }
            break;
        // Magical Attacks
        case SPELL_DAMAGE_CLASS_NONE:
        case SPELL_DAMAGE_CLASS_MAGIC:
            {
                // If crit add critical bonus
                if (crit)
                {
                    damageInfo->HitInfo |= SPELL_HIT_TYPE_CRIT;
                    damage = SpellCriticalDamageBonus(spellInfo, damage, pVictim);
                }

                ApplyResilience(pVictim, NULL, &damage, crit, CR_CRIT_TAKEN_SPELL);
            }
            break;
    }

    // Calculate absorb resist
    if (damage > 0)
    {
        CalcAbsorbResist(pVictim, damageSchoolMask, SPELL_DIRECT_DAMAGE, damage, &damageInfo->absorb, &damageInfo->resist, spellInfo);
        damage -= damageInfo->absorb + damageInfo->resist;
    }
    else
        damage = 0;

    damageInfo->damage = damage;
}

void Unit::DealSpellDamage(SpellNonMeleeDamage *damageInfo, bool durabilityLoss)
{
    if (damageInfo == 0)
        return;

    Unit* pVictim = damageInfo->target;

    if (!pVictim)
        return;

    if (!pVictim->isAlive() || pVictim->HasUnitState(UNIT_STAT_IN_FLIGHT) || (pVictim->HasUnitState(UNIT_STAT_ONVEHICLE) && pVictim->GetVehicleBase() != this) || (pVictim->GetTypeId() == TYPEID_UNIT && pVictim->ToCreature()->IsInEvadeMode()))
        return;

    SpellEntry const* spellProto = sSpellStore.LookupEntry(damageInfo->SpellID);
    if (spellProto == NULL)
    {
        sLog->outDebug(LOG_FILTER_UNITS, "Unit::DealSpellDamage have wrong damageInfo->SpellID: %u", damageInfo->SpellID);
        return;
    }

    // Call default DealDamage
    CleanDamage cleanDamage(damageInfo->cleanDamage, damageInfo->absorb, BASE_ATTACK, MELEE_HIT_NORMAL);
    DealDamage(pVictim, damageInfo->damage, &cleanDamage, SPELL_DIRECT_DAMAGE, SpellSchoolMask(damageInfo->schoolMask), spellProto, durabilityLoss);
}

// TODO for melee need create structure as in
void Unit::CalculateMeleeDamage(Unit *pVictim, uint32 damage, CalcDamageInfo *damageInfo, WeaponAttackType attackType)
{
    damageInfo->attacker         = this;
    damageInfo->target           = pVictim;
    damageInfo->damageSchoolMask = GetMeleeDamageSchoolMask();
    damageInfo->attackType       = attackType;
    damageInfo->damage           = 0;
    damageInfo->cleanDamage      = 0;
    damageInfo->absorb           = 0;
    damageInfo->resist           = 0;
    damageInfo->blocked_amount   = 0;

    damageInfo->TargetState      = 0;
    damageInfo->HitInfo          = 0;
    damageInfo->procAttacker     = PROC_FLAG_NONE;
    damageInfo->procVictim       = PROC_FLAG_NONE;
    damageInfo->procEx           = PROC_EX_NONE;
    damageInfo->hitOutCome       = MELEE_HIT_EVADE;

    if (!pVictim)
        return;
    if (!isAlive() || !pVictim->isAlive())
        return;

    // Select HitInfo/procAttacker/procVictim flag based on attack type
    switch (attackType)
    {
        case BASE_ATTACK:
            damageInfo->procAttacker = PROC_FLAG_DONE_MELEE_AUTO_ATTACK | PROC_FLAG_DONE_MAINHAND_ATTACK;
            damageInfo->procVictim   = PROC_FLAG_TAKEN_MELEE_AUTO_ATTACK;
            damageInfo->HitInfo      = HITINFO_NORMALSWING2;
            break;
        case OFF_ATTACK:
            damageInfo->procAttacker = PROC_FLAG_DONE_MELEE_AUTO_ATTACK | PROC_FLAG_DONE_OFFHAND_ATTACK;
            damageInfo->procVictim   = PROC_FLAG_TAKEN_MELEE_AUTO_ATTACK;
            damageInfo->HitInfo = HITINFO_LEFTSWING;
            break;
        default:
            return;
    }

    // Physical Immune check
    if (damageInfo->target->IsImmunedToDamage(SpellSchoolMask(damageInfo->damageSchoolMask)))
    {
       damageInfo->HitInfo       |= HITINFO_NORMALSWING;
       damageInfo->TargetState    = VICTIMSTATE_IS_IMMUNE;

       damageInfo->procEx        |= PROC_EX_IMMUNE;
       damageInfo->damage         = 0;
       damageInfo->cleanDamage    = 0;
       return;
    }

    damage += CalculateDamage(damageInfo->attackType, false, true);
    // Add melee damage bonus
    MeleeDamageBonus(damageInfo->target, &damage, damageInfo->attackType);

    // Calculate armor reduction
    if (IsDamageReducedByArmor((SpellSchoolMask)(damageInfo->damageSchoolMask)))
    {
        damageInfo->damage = CalcArmorReducedDamage(damageInfo->target, damage, NULL , damageInfo->attackType);
        damageInfo->cleanDamage += damage - damageInfo->damage;
    }
    else
        damageInfo->damage = damage;

    damageInfo->hitOutCome = RollMeleeOutcomeAgainst(damageInfo->target, damageInfo->attackType);

    switch (damageInfo->hitOutCome)
    {
        case MELEE_HIT_EVADE:
            {
                damageInfo->HitInfo    |= HITINFO_MISS|HITINFO_SWINGNOHITSOUND;
                damageInfo->TargetState = VICTIMSTATE_EVADES;

                damageInfo->procEx|=PROC_EX_EVADE;
                damageInfo->damage = 0;
                damageInfo->cleanDamage = 0;
            }
            return;
        case MELEE_HIT_MISS:
            {
                damageInfo->HitInfo    |= HITINFO_MISS;
                damageInfo->TargetState = VICTIMSTATE_INTACT;

                damageInfo->procEx |= PROC_EX_MISS;
                damageInfo->damage  = 0;
                damageInfo->cleanDamage = 0;
            }
            break;
        case MELEE_HIT_NORMAL:
            damageInfo->TargetState = VICTIMSTATE_HIT;
            damageInfo->procEx|=PROC_EX_NORMAL_HIT;
            break;
        case MELEE_HIT_CRIT:
            {
                damageInfo->HitInfo     |= HITINFO_CRITICALHIT;
                damageInfo->TargetState  = VICTIMSTATE_HIT;

                damageInfo->procEx      |= PROC_EX_CRITICAL_HIT;
                // Crit bonus calc
                damageInfo->damage += damageInfo->damage;
                int32 mod = 0;
                // Apply SPELL_AURA_MOD_ATTACKER_RANGED_CRIT_DAMAGE or SPELL_AURA_MOD_ATTACKER_MELEE_CRIT_DAMAGE
                if (damageInfo->attackType == RANGED_ATTACK)
                    mod += damageInfo->target->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_RANGED_CRIT_DAMAGE);
                else
                {
                    mod += damageInfo->target->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_MELEE_CRIT_DAMAGE);
                    mod += GetTotalAuraModifier(SPELL_AURA_MOD_CRIT_DAMAGE_BONUS_MELEE);
                }

                uint32 crTypeMask = damageInfo->target->GetCreatureTypeMask();

                // Increase crit damage from SPELL_AURA_MOD_CRIT_PERCENT_VERSUS
                mod += GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_CRIT_PERCENT_VERSUS, crTypeMask);
                if (mod != 0)
                    AddPctN(damageInfo->damage, mod);
            }
            break;
        case MELEE_HIT_PARRY:
            damageInfo->TargetState  = VICTIMSTATE_PARRY;
            damageInfo->procEx      |= PROC_EX_PARRY;
            damageInfo->cleanDamage += damageInfo->damage;
            damageInfo->damage = 0;
            break;
        case MELEE_HIT_DODGE:
            damageInfo->TargetState  = VICTIMSTATE_DODGE;
            damageInfo->procEx      |= PROC_EX_DODGE;
            damageInfo->cleanDamage += damageInfo->damage;
            damageInfo->damage = 0;
            break;
        case MELEE_HIT_BLOCK:
            {
                damageInfo->TargetState = VICTIMSTATE_HIT;
                damageInfo->HitInfo    |= HITINFO_BLOCK;
                damageInfo->procEx     |= PROC_EX_BLOCK;
                damageInfo->blocked_amount = damageInfo->target->GetShieldBlockValue();
                // double blocked amount if block is critical
                if (damageInfo->target->isBlockCritical())
                    damageInfo->blocked_amount+=damageInfo->blocked_amount;
                if (damageInfo->blocked_amount >= damageInfo->damage)
                {
                    damageInfo->TargetState = VICTIMSTATE_BLOCKS;
                    damageInfo->blocked_amount = damageInfo->damage;
                    damageInfo->procEx |= PROC_EX_FULL_BLOCK;
                }
                else
                    damageInfo->procEx  |= PROC_EX_NORMAL_HIT;
                damageInfo->damage      -= damageInfo->blocked_amount;
                damageInfo->cleanDamage += damageInfo->blocked_amount;
            }
            break;
        case MELEE_HIT_GLANCING:
            {
                damageInfo->HitInfo     |= HITINFO_GLANCING;
                damageInfo->TargetState  = VICTIMSTATE_HIT;
                damageInfo->procEx      |= PROC_EX_NORMAL_HIT;
                int32 leveldif = int32(pVictim->getLevel()) - int32(getLevel());
                if (leveldif > 3)
                    leveldif = 3;
                float reducePercent = 1 - leveldif * 0.1f;
                damageInfo->cleanDamage += damageInfo->damage-uint32(reducePercent * damageInfo->damage);
                damageInfo->damage   = uint32(reducePercent * damageInfo->damage);
            }
            break;
        case MELEE_HIT_CRUSHING:
            {
                damageInfo->HitInfo     |= HITINFO_CRUSHING;
                damageInfo->TargetState  = VICTIMSTATE_HIT;
                damageInfo->procEx      |= PROC_EX_NORMAL_HIT;
                // 150% normal damage
                damageInfo->damage += (damageInfo->damage / 2);
            }
        break;
        default:
            break;
    }

    int32 resilienceReduction = damageInfo->damage;
    if (attackType != RANGED_ATTACK)
        ApplyResilience(pVictim, NULL, &resilienceReduction, (damageInfo->hitOutCome == MELEE_HIT_CRIT), CR_CRIT_TAKEN_MELEE);
    else
        ApplyResilience(pVictim, NULL, &resilienceReduction, (damageInfo->hitOutCome == MELEE_HIT_CRIT), CR_CRIT_TAKEN_RANGED);
    resilienceReduction = damageInfo->damage - resilienceReduction;
    damageInfo->damage      -= resilienceReduction;
    damageInfo->cleanDamage += resilienceReduction;

    // Calculate absorb resist
    if (int32(damageInfo->damage) > 0)
    {
        damageInfo->procVictim |= PROC_FLAG_TAKEN_DAMAGE;
        // Calculate absorb & resists
        CalcAbsorbResist(damageInfo->target, SpellSchoolMask(damageInfo->damageSchoolMask), DIRECT_DAMAGE, damageInfo->damage, &damageInfo->absorb, &damageInfo->resist);
        damageInfo->damage -= damageInfo->absorb + damageInfo->resist;
        if (damageInfo->absorb)
        {
            damageInfo->HitInfo |= HITINFO_ABSORB;
            damageInfo->procEx  |= PROC_EX_ABSORB;
        }
        if (damageInfo->resist)
            damageInfo->HitInfo |= HITINFO_RESIST;
    }
    else // Impossible get negative result but....
        damageInfo->damage = 0;
}

void Unit::DealMeleeDamage(CalcDamageInfo *damageInfo, bool durabilityLoss)
{
    Unit* pVictim = damageInfo->target;

    if (!pVictim->isAlive() || pVictim->HasUnitState(UNIT_STAT_IN_FLIGHT) || (pVictim->HasUnitState(UNIT_STAT_ONVEHICLE) && pVictim->GetVehicleBase() != this) || (pVictim->GetTypeId() == TYPEID_UNIT && pVictim->ToCreature()->IsInEvadeMode()))
        return;

    // Hmmmm dont like this emotes client must by self do all animations
    if (damageInfo->HitInfo & HITINFO_CRITICALHIT)
        pVictim->HandleEmoteCommand(EMOTE_ONESHOT_WOUNDCRITICAL);
    if (damageInfo->blocked_amount && damageInfo->TargetState != VICTIMSTATE_BLOCKS)
        pVictim->HandleEmoteCommand(EMOTE_ONESHOT_PARRYSHIELD);

    if (damageInfo->TargetState == VICTIMSTATE_PARRY)
    {
        // Get attack timers
        float offtime  = float(pVictim->getAttackTimer(OFF_ATTACK));
        float basetime = float(pVictim->getAttackTimer(BASE_ATTACK));
        // Reduce attack time
        if (pVictim->haveOffhandWeapon() && offtime < basetime)
        {
            float percent20 = pVictim->GetAttackTime(OFF_ATTACK) * 0.20f;
            float percent60 = 3.0f * percent20;
            if (offtime > percent20 && offtime <= percent60)
                pVictim->setAttackTimer(OFF_ATTACK, uint32(percent20));
            else if (offtime > percent60)
            {
                offtime -= 2.0f * percent20;
                pVictim->setAttackTimer(OFF_ATTACK, uint32(offtime));
            }
        }
        else
        {
            float percent20 = pVictim->GetAttackTime(BASE_ATTACK) * 0.20f;
            float percent60 = 3.0f * percent20;
            if (basetime > percent20 && basetime <= percent60)
                pVictim->setAttackTimer(BASE_ATTACK, uint32(percent20));
            else if (basetime > percent60)
            {
                basetime -= 2.0f * percent20;
                pVictim->setAttackTimer(BASE_ATTACK, uint32(basetime));
            }
        }
    }

    // Call default DealDamage
    CleanDamage cleanDamage(damageInfo->cleanDamage, damageInfo->absorb, damageInfo->attackType, damageInfo->hitOutCome);
    DealDamage(pVictim, damageInfo->damage, &cleanDamage, DIRECT_DAMAGE, SpellSchoolMask(damageInfo->damageSchoolMask), NULL, durabilityLoss);

    // If this is a creature and it attacks from behind it has a probability to daze it's victim
    if ((damageInfo->hitOutCome == MELEE_HIT_CRIT || damageInfo->hitOutCome == MELEE_HIT_CRUSHING || damageInfo->hitOutCome == MELEE_HIT_NORMAL || damageInfo->hitOutCome == MELEE_HIT_GLANCING) &&
        GetTypeId() != TYPEID_PLAYER && !ToCreature()->IsControlledByPlayer() && !pVictim->HasInArc(M_PI, this)
        && (pVictim->GetTypeId() == TYPEID_PLAYER || !pVictim->ToCreature()->isWorldBoss()))
    {
        // -probability is between 0% and 40%
        // 20% base chance
        float Probability = 20.0f;

        // there is a newbie protection, at level 10 just 7% base chance; assuming linear function
        if (pVictim->getLevel() < 30)
            Probability = 0.65f * pVictim->getLevel() + 0.5f;

        uint32 VictimDefense=pVictim->GetDefenseSkillValue();
        uint32 AttackerMeleeSkill=GetUnitMeleeSkill();

        Probability *= AttackerMeleeSkill/(float)VictimDefense;

        if (Probability > 40.0f)
            Probability = 40.0f;

        if (roll_chance_f(Probability))
            CastSpell(pVictim, 1604, true);
    }

    if (GetTypeId() == TYPEID_PLAYER)
        ToPlayer()->CastItemCombatSpell(pVictim, damageInfo->attackType, damageInfo->procVictim, damageInfo->procEx);

    // Do effect if any damage done to target
    if (damageInfo->damage)
    {
        // We're going to call functions which can modify content of the list during iteration over it's elements
        // Let's copy the list so we can prevent iterator invalidation
        AuraEffectList vDamageShieldsCopy(pVictim->GetAuraEffectsByType(SPELL_AURA_DAMAGE_SHIELD));
        for (AuraEffectList::const_iterator dmgShieldItr = vDamageShieldsCopy.begin(); dmgShieldItr != vDamageShieldsCopy.end(); ++dmgShieldItr)
        {
            SpellEntry const* i_spellProto = (*dmgShieldItr)->GetSpellProto();
            // Damage shield can be resisted...
            if (SpellMissInfo missInfo = pVictim->SpellHitResult(this, i_spellProto , false))
            {
                pVictim->SendSpellMiss(this, i_spellProto->Id, missInfo);
                continue;
            }

            // ...or immuned
            if (IsImmunedToDamage(i_spellProto))
            {
                pVictim->SendSpellDamageImmune(this, i_spellProto->Id);
                continue;
            }

            uint32 damage = (*dmgShieldItr)->GetAmount();

            if (Unit* caster = (*dmgShieldItr)->GetCaster())
                damage = caster->SpellDamageBonus(this, i_spellProto, damage, SPELL_DIRECT_DAMAGE);

            // No Unit::CalcAbsorbResist here - opcode doesn't send that data - this damage is probably not affected by that
            pVictim->DealDamageMods(this, damage, NULL);

            // TODO: Move this to a packet handler
            WorldPacket data(SMSG_SPELLDAMAGESHIELD, (8+8+4+4+4+4));
            data << uint64(pVictim->GetGUID());
            data << uint64(GetGUID());
            data << uint32(i_spellProto->Id);
            data << uint32(damage);                  // Damage
            int32 overkill = int32(damage) - int32(GetHealth());
            data << uint32(overkill > 0 ? overkill : 0); // Overkill
            data << uint32(i_spellProto->SchoolMask);
            pVictim->SendMessageToSet(&data, true);

            pVictim->DealDamage(this, damage, 0, SPELL_DIRECT_DAMAGE, GetSpellSchoolMask(i_spellProto), i_spellProto, true);
        }
    }
}

void Unit::HandleEmoteCommand(uint32 anim_id)
{
    WorldPacket data(SMSG_EMOTE, 4 + 8);
    data << uint32(anim_id);
    data << uint64(GetGUID());
    SendMessageToSet(&data, true);
}

bool Unit::IsDamageReducedByArmor(SpellSchoolMask schoolMask, SpellEntry const *spellInfo, uint8 effIndex)
{
    // only physical spells damage gets reduced by armor
    if ((schoolMask & SPELL_SCHOOL_MASK_NORMAL) == 0)
        return false;
    if (spellInfo)
    {
        // there are spells with no specific attribute but they have "ignores armor" in tooltip
        if (sSpellMgr->GetSpellCustomAttr(spellInfo->Id) & SPELL_ATTR0_CU_IGNORE_ARMOR)
            return false;

        // bleeding effects are not reduced by armor
        if (effIndex != MAX_SPELL_EFFECTS && spellInfo->EffectApplyAuraName[effIndex] == SPELL_AURA_PERIODIC_DAMAGE)
            if (GetSpellMechanicMask(spellInfo, effIndex) & (1<<MECHANIC_BLEED))
                return false;
    }
    return true;
}

uint32 Unit::CalcArmorReducedDamage(Unit* pVictim, const uint32 damage, SpellEntry const *spellInfo, WeaponAttackType /*attackType*/)
{
    uint32 newdamage = 0;
    float armor = float(pVictim->GetArmor());

    // Ignore enemy armor by SPELL_AURA_MOD_TARGET_RESISTANCE aura
    armor += GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_TARGET_RESISTANCE, SPELL_SCHOOL_MASK_NORMAL);

    if (spellInfo)
        if (Player* modOwner = GetSpellModOwner())
            modOwner->ApplySpellMod(spellInfo->Id, SPELLMOD_IGNORE_ARMOR, armor);

    AuraEffectList const& ResIgnoreAurasAb = GetAuraEffectsByType(SPELL_AURA_MOD_ABILITY_IGNORE_TARGET_RESIST);
    for (AuraEffectList::const_iterator j = ResIgnoreAurasAb.begin(); j != ResIgnoreAurasAb.end(); ++j)
    {
        if ((*j)->GetMiscValue() & SPELL_SCHOOL_MASK_NORMAL
            && (*j)->IsAffectedOnSpell(spellInfo))
            armor = floor(AddPctN(armor, -(*j)->GetAmount()));
    }

    AuraEffectList const& ResIgnoreAuras = GetAuraEffectsByType(SPELL_AURA_MOD_IGNORE_TARGET_RESIST);
    for (AuraEffectList::const_iterator j = ResIgnoreAuras.begin(); j != ResIgnoreAuras.end(); ++j)
    {
        if ((*j)->GetMiscValue() & SPELL_SCHOOL_MASK_NORMAL)
            armor = floor(AddPctN(armor, -(*j)->GetAmount()));
    }

    if (GetTypeId() == TYPEID_PLAYER)
    {
        AuraEffectList const& ResIgnoreAuras = GetAuraEffectsByType(SPELL_AURA_MOD_ARMOR_PENETRATION_PCT);
        for (AuraEffectList::const_iterator itr = ResIgnoreAuras.begin(); itr != ResIgnoreAuras.end(); ++itr)
        {
            // item neutral spell
            if ((*itr)->GetSpellProto()->EquippedItemClass == -1)
            {
                armor = floor(AddPctN(armor, -(*itr)->GetAmount()));
                continue;
            }

            // item dependent spell - check curent weapons
            for (int i = 0; i < MAX_ATTACK; ++i)
            {
                Item* weapon = ToPlayer()->GetWeaponForAttack(WeaponAttackType(i), true);

                if (weapon && weapon->IsFitToSpellRequirements((*itr)->GetSpellProto()))
                {
                    armor = floor(AddPctN(armor, -(*itr)->GetAmount()));
                    break;
                }
            }
        }
    }

    // Apply Player CR_ARMOR_PENETRATION rating
    if (GetTypeId() == TYPEID_PLAYER)
    {
        float maxArmorPen = 0;
        if (getLevel() < 60)
            maxArmorPen = float(400 + 85 * pVictim->getLevel());
        else
            maxArmorPen = 400 + 85 * pVictim->getLevel() + 4.5f * 85 * (pVictim->getLevel() - 59);
        // Cap armor penetration to this number
        maxArmorPen = std::min((armor + maxArmorPen) / 3, armor);
        // Figure out how much armor do we ignore
        float armorPen = CalculatePctF(maxArmorPen, ToPlayer()->GetRatingBonusValue(CR_ARMOR_PENETRATION));
        // Got the value, apply it
        armor -= armorPen;
    }

    if (armor < 0.0f)
        armor = 0.0f;

    float levelModifier = getLevel();
    if (levelModifier > 59)
        levelModifier = levelModifier + (4.5f * (levelModifier - 59));

    float tmpvalue = 0.1f * armor / (8.5f * levelModifier + 40);
    tmpvalue = tmpvalue / (1.0f + tmpvalue);

    if (tmpvalue < 0.0f)
        tmpvalue = 0.0f;
    if (tmpvalue > 0.75f)
        tmpvalue = 0.75f;

    newdamage = uint32(damage - (damage * tmpvalue));

    return (newdamage > 1) ? newdamage : 1;
}

void Unit::CalcAbsorbResist(Unit *pVictim, SpellSchoolMask schoolMask, DamageEffectType damagetype, const uint32 damage, uint32 *absorb, uint32 *resist, SpellEntry const *spellInfo)
{
    if (!pVictim || !pVictim->isAlive() || !damage)
        return;

    DamageInfo dmgInfo = DamageInfo(this, pVictim, damage, spellInfo, schoolMask, damagetype);

    // Magic damage, check for resists
    if ((schoolMask & SPELL_SCHOOL_MASK_NORMAL) == 0)
    {
        float baseVictimResistance = float(pVictim->GetResistance(GetFirstSchoolInMask(schoolMask)));
        float ignoredResistance = float(GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_TARGET_RESISTANCE, schoolMask));
        if (Player* player = ToPlayer())
            ignoredResistance += float(player->GetSpellPenetrationItemMod());
        float victimResistance = baseVictimResistance + ignoredResistance;

        static const uint32 BOSS_LEVEL = 83;
        static const float BOSS_RESISTANCE_CONSTANT = 510.0;
        uint32 level = getLevel();
        float resistanceConstant = 0.0f;

        if (level == BOSS_LEVEL)
            resistanceConstant = BOSS_RESISTANCE_CONSTANT;
        else
            resistanceConstant = level * 5.0f;

        float averageResist = victimResistance / (victimResistance + resistanceConstant);
        float discreteResistProbability[11];
        for (uint32 i = 0; i < 11; ++i)
        {
            discreteResistProbability[i] = 0.5f - 2.5f * fabs(0.1f * i - averageResist);
            if (discreteResistProbability[i] < 0.0f)
                discreteResistProbability[i] = 0.0f;
        }

        if (averageResist <= 0.1f)
        {
            discreteResistProbability[0] = 1.0f - 7.5f * averageResist;
            discreteResistProbability[1] = 5.0f * averageResist;
            discreteResistProbability[2] = 2.5f * averageResist;
        }

        float r = float(rand_norm());
        uint32 i = 0;
        float probabilitySum = discreteResistProbability[0];

        while (r >= probabilitySum && i < 10)
            probabilitySum += discreteResistProbability[++i];

        float damageResisted = float(damage * i / 10);

        AuraEffectList const& ResIgnoreAurasAb = GetAuraEffectsByType(SPELL_AURA_MOD_ABILITY_IGNORE_TARGET_RESIST);
        for (AuraEffectList::const_iterator j = ResIgnoreAurasAb.begin(); j != ResIgnoreAurasAb.end(); ++j)
            if (((*j)->GetMiscValue() & schoolMask) && (*j)->IsAffectedOnSpell(spellInfo))
                AddPctN(damageResisted, -(*j)->GetAmount());

        AuraEffectList const& ResIgnoreAuras = GetAuraEffectsByType(SPELL_AURA_MOD_IGNORE_TARGET_RESIST);
        for (AuraEffectList::const_iterator j = ResIgnoreAuras.begin(); j != ResIgnoreAuras.end(); ++j)
            if ((*j)->GetMiscValue() & schoolMask)
                AddPctN(damageResisted, -(*j)->GetAmount());

        dmgInfo.ResistDamage(uint32(damageResisted));
    }

    // Ignore Absorption Auras
    float auraAbsorbMod = 0;
    AuraEffectList const& AbsIgnoreAurasA = GetAuraEffectsByType(SPELL_AURA_MOD_TARGET_ABSORB_SCHOOL);
    for (AuraEffectList::const_iterator itr = AbsIgnoreAurasA.begin(); itr != AbsIgnoreAurasA.end(); ++itr)
    {
        if (!((*itr)->GetMiscValue() & schoolMask))
            continue;

        if ((*itr)->GetAmount() > auraAbsorbMod)
            auraAbsorbMod = float((*itr)->GetAmount());
    }

    AuraEffectList const& AbsIgnoreAurasB = GetAuraEffectsByType(SPELL_AURA_MOD_TARGET_ABILITY_ABSORB_SCHOOL);
    for (AuraEffectList::const_iterator itr = AbsIgnoreAurasB.begin(); itr != AbsIgnoreAurasB.end(); ++itr)
    {
        if (!((*itr)->GetMiscValue() & schoolMask))
            continue;

        if (((*itr)->GetAmount() > auraAbsorbMod) && (*itr)->IsAffectedOnSpell(spellInfo))
            auraAbsorbMod = float((*itr)->GetAmount());
    }
    RoundToInterval(auraAbsorbMod, 0.0f, 100.0f);

    // We're going to call functions which can modify content of the list during iteration over it's elements
    // Let's copy the list so we can prevent iterator invalidation
    AuraEffectList vSchoolAbsorbCopy(pVictim->GetAuraEffectsByType(SPELL_AURA_SCHOOL_ABSORB));
    vSchoolAbsorbCopy.sort(Trinity::AbsorbAuraOrderPred());

    // absorb without mana cost
    for (AuraEffectList::iterator itr = vSchoolAbsorbCopy.begin(); (itr != vSchoolAbsorbCopy.end()) && (dmgInfo.GetDamage() > 0); ++itr)
    {
        AuraEffect* absorbAurEff = *itr;
        // Check if aura was removed during iteration - we don't need to work on such auras
        AuraApplication const* aurApp = absorbAurEff->GetBase()->GetApplicationOfTarget(pVictim->GetGUID());
        if (!aurApp)
            continue;
        if (!(absorbAurEff->GetMiscValue() & schoolMask))
            continue;

        // get amount which can be still absorbed by the aura
        int32 currentAbsorb = absorbAurEff->GetAmount();
        // aura with infinite absorb amount - let the scripts handle absorbtion amount, set here to 0 for safety
        if (currentAbsorb < 0)
            currentAbsorb = 0;

        uint32 absorb = currentAbsorb;

        bool defaultPrevented = false;

        absorbAurEff->GetBase()->CallScriptEffectAbsorbHandlers(absorbAurEff, aurApp, dmgInfo, absorb, defaultPrevented);
        currentAbsorb = absorb;

        if (defaultPrevented)
            continue;

        // Apply absorb mod auras
        AddPctF(currentAbsorb, -auraAbsorbMod);

        // absorb must be smaller than the damage itself
        currentAbsorb = RoundToInterval(currentAbsorb, 0, int32(dmgInfo.GetDamage()));

        dmgInfo.AbsorbDamage(currentAbsorb);

        absorb = currentAbsorb;
        absorbAurEff->GetBase()->CallScriptEffectAfterAbsorbHandlers(absorbAurEff, aurApp, dmgInfo, absorb);

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
    AuraEffectList vManaShieldCopy(pVictim->GetAuraEffectsByType(SPELL_AURA_MANA_SHIELD));
    for (AuraEffectList::const_iterator itr = vManaShieldCopy.begin(); (itr != vManaShieldCopy.end()) && (dmgInfo.GetDamage() > 0); ++itr)
    {
        AuraEffect* absorbAurEff = *itr;
        // Check if aura was removed during iteration - we don't need to work on such auras
        AuraApplication const* aurApp = absorbAurEff->GetBase()->GetApplicationOfTarget(pVictim->GetGUID());
        if (!aurApp)
            continue;
        // check damage school mask
        if (!(absorbAurEff->GetMiscValue() & schoolMask))
            continue;

        // get amount which can be still absorbed by the aura
        int32 currentAbsorb = absorbAurEff->GetAmount();
        // aura with infinite absorb amount - let the scripts handle absorbtion amount, set here to 0 for safety
        if (currentAbsorb < 0)
            currentAbsorb = 0;

        uint32 absorb = currentAbsorb;

        bool defaultPrevented = false;

        absorbAurEff->GetBase()->CallScriptEffectManaShieldHandlers(absorbAurEff, aurApp, dmgInfo, absorb, defaultPrevented);
        currentAbsorb = absorb;

        if (defaultPrevented)
            continue;

        AddPctF(currentAbsorb, -auraAbsorbMod);

        // absorb must be smaller than the damage itself
        currentAbsorb = RoundToInterval(currentAbsorb, 0, int32(dmgInfo.GetDamage()));

        int32 manaReduction = currentAbsorb;

        // lower absorb amount by talents
        if (float manaMultiplier = SpellMgr::CalculateSpellEffectValueMultiplier(absorbAurEff->GetSpellProto(), absorbAurEff->GetEffIndex(), absorbAurEff->GetCaster()))
            manaReduction = int32(float(manaReduction) * manaMultiplier);

        int32 manaTaken = -pVictim->ModifyPower(POWER_MANA, -manaReduction);

        // take case when mana has ended up into account
        currentAbsorb = currentAbsorb ? int32(float(currentAbsorb) * (float(manaTaken) / float(manaReduction))) : 0;

        dmgInfo.AbsorbDamage(currentAbsorb);

        absorb = currentAbsorb;
        absorbAurEff->GetBase()->CallScriptEffectAfterManaShieldHandlers(absorbAurEff, aurApp, dmgInfo, absorb);

        // Check if our aura is using amount to count damage
        if (absorbAurEff->GetAmount() >= 0)
        {
            absorbAurEff->SetAmount(absorbAurEff->GetAmount() - currentAbsorb);
            if ((absorbAurEff->GetAmount() <= 0))
                absorbAurEff->GetBase()->Remove(AURA_REMOVE_BY_ENEMY_SPELL);
        }
    }

    // split damage auras - only when not damaging self
    if (pVictim != this)
    {
        // We're going to call functions which can modify content of the list during iteration over it's elements
        // Let's copy the list so we can prevent iterator invalidation
        AuraEffectList vSplitDamageFlatCopy(pVictim->GetAuraEffectsByType(SPELL_AURA_SPLIT_DAMAGE_FLAT));
        for (AuraEffectList::iterator itr = vSplitDamageFlatCopy.begin(); (itr != vSplitDamageFlatCopy.end()) && (dmgInfo.GetDamage() > 0); ++itr)
        {
            // Check if aura was removed during iteration - we don't need to work on such auras
            if (!((*itr)->GetBase()->IsAppliedOnTarget(pVictim->GetGUID())))
                continue;
            // check damage school mask
            if (!((*itr)->GetMiscValue() & schoolMask))
                continue;

            // Damage can be splitted only if aura has an alive caster
            Unit* caster = (*itr)->GetCaster();
            if (!caster || (caster == pVictim) || !caster->IsInWorld() || !caster->isAlive())
                continue;

            int32 splitDamage = (*itr)->GetAmount();

            // absorb must be smaller than the damage itself
            splitDamage = RoundToInterval(splitDamage, 0, int32(dmgInfo.GetDamage()));

            dmgInfo.AbsorbDamage(splitDamage);

            uint32 splitted = splitDamage;
            uint32 splitted_absorb = 0;
            DealDamageMods(caster, splitted, &splitted_absorb);

            SendSpellNonMeleeDamageLog(caster, (*itr)->GetSpellProto()->Id, splitted, schoolMask, splitted_absorb, 0, false, 0, false);

            CleanDamage cleanDamage = CleanDamage(splitted, 0, BASE_ATTACK, MELEE_HIT_NORMAL);
            DealDamage(caster, splitted, &cleanDamage, DIRECT_DAMAGE, schoolMask, (*itr)->GetSpellProto(), false);
        }

        // We're going to call functions which can modify content of the list during iteration over it's elements
        // Let's copy the list so we can prevent iterator invalidation
        AuraEffectList vSplitDamagePctCopy(pVictim->GetAuraEffectsByType(SPELL_AURA_SPLIT_DAMAGE_PCT));
        for (AuraEffectList::iterator itr = vSplitDamagePctCopy.begin(), next; (itr != vSplitDamagePctCopy.end()) &&  (dmgInfo.GetDamage() > 0); ++itr)
        {
            // Check if aura was removed during iteration - we don't need to work on such auras
            if (!((*itr)->GetBase()->IsAppliedOnTarget(pVictim->GetGUID())))
                continue;
            // check damage school mask
            if (!((*itr)->GetMiscValue() & schoolMask))
                continue;

            // Damage can be splitted only if aura has an alive caster
            Unit* caster = (*itr)->GetCaster();
            if (!caster || (caster == pVictim) || !caster->IsInWorld() || !caster->isAlive())
                continue;

            int32 splitDamage = CalculatePctN(dmgInfo.GetDamage(), (*itr)->GetAmount());

            // absorb must be smaller than the damage itself
            splitDamage = RoundToInterval(splitDamage, 0, int32(dmgInfo.GetDamage()));

            dmgInfo.AbsorbDamage(splitDamage);

            uint32 splitted = splitDamage;
            uint32 split_absorb = 0;
            DealDamageMods(caster, splitted, &split_absorb);

            SendSpellNonMeleeDamageLog(caster, (*itr)->GetSpellProto()->Id, splitted, schoolMask, split_absorb, 0, false, 0, false);

            CleanDamage cleanDamage = CleanDamage(splitted, 0, BASE_ATTACK, MELEE_HIT_NORMAL);
            DealDamage(caster, splitted, &cleanDamage, DIRECT_DAMAGE, schoolMask, (*itr)->GetSpellProto(), false);
        }
    }

    *resist = dmgInfo.GetResist();
    *absorb = dmgInfo.GetAbsorb();
}

void Unit::CalcHealAbsorb(Unit *pVictim, const SpellEntry *healSpell, uint32 &healAmount, uint32 &absorb)
{
    if (!healAmount)
        return;

    int32 RemainingHeal = healAmount;

    // Need remove expired auras after
    bool existExpired = false;

    // absorb without mana cost
    AuraEffectList const& vHealAbsorb = pVictim->GetAuraEffectsByType(SPELL_AURA_SCHOOL_HEAL_ABSORB);
    for (AuraEffectList::const_iterator i = vHealAbsorb.begin(); i != vHealAbsorb.end() && RemainingHeal > 0; ++i)
    {
        if (!((*i)->GetMiscValue() & healSpell->SchoolMask))
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
        if (RemainingHeal < currentAbsorb)
            currentAbsorb = RemainingHeal;

        RemainingHeal -= currentAbsorb;

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
                uint32 removedAuras = pVictim->m_removedAurasCount;
                auraEff->GetBase()->Remove(AURA_REMOVE_BY_ENEMY_SPELL);
                if (removedAuras+1 < pVictim->m_removedAurasCount)
                    i = vHealAbsorb.begin();
            }
        }
    }

    absorb = RemainingHeal > 0 ? (healAmount - RemainingHeal) : healAmount;
    healAmount = RemainingHeal;
}

void Unit::AttackerStateUpdate (Unit *pVictim, WeaponAttackType attType, bool extra)
{
    if (HasUnitState(UNIT_STAT_CANNOT_AUTOATTACK) || HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED))
        return;

    if (!pVictim->isAlive())
        return;

    if ((attType == BASE_ATTACK || attType == OFF_ATTACK) && !IsWithinLOSInMap(pVictim))
        return;

    CombatStart(pVictim);
    RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_MELEE_ATTACK);

    uint32 hitInfo;
    if (attType == BASE_ATTACK)
        hitInfo = HITINFO_NORMALSWING2;
    else if (attType == OFF_ATTACK)
        hitInfo = HITINFO_LEFTSWING;
    else
        return;                                             // ignore ranged case

    // melee attack spell casted at main hand attack only - no normal melee dmg dealt
    if (attType == BASE_ATTACK && m_currentSpells[CURRENT_MELEE_SPELL])
        m_currentSpells[CURRENT_MELEE_SPELL]->cast();
    else
    {
        // attack can be redirected to another target
        pVictim = SelectMagnetTarget(pVictim);

        CalcDamageInfo damageInfo;
        CalculateMeleeDamage(pVictim, 0, &damageInfo, attType);
        // Send log damage message to client
        DealDamageMods(pVictim, damageInfo.damage, &damageInfo.absorb);
        SendAttackStateUpdate(&damageInfo);

        ProcDamageAndSpell(damageInfo.target, damageInfo.procAttacker, damageInfo.procVictim, damageInfo.procEx, damageInfo.damage, damageInfo.attackType);
        DealMeleeDamage(&damageInfo, true);

        if (GetTypeId() == TYPEID_PLAYER)
            sLog->outStaticDebug("AttackerStateUpdate: (Player) %u attacked %u (TypeId: %u) for %u dmg, absorbed %u, blocked %u, resisted %u.",
                GetGUIDLow(), pVictim->GetGUIDLow(), pVictim->GetTypeId(), damageInfo.damage, damageInfo.absorb, damageInfo.blocked_amount, damageInfo.resist);
        else
            sLog->outStaticDebug("AttackerStateUpdate: (NPC)    %u attacked %u (TypeId: %u) for %u dmg, absorbed %u, blocked %u, resisted %u.",
                GetGUIDLow(), pVictim->GetGUIDLow(), pVictim->GetTypeId(), damageInfo.damage, damageInfo.absorb, damageInfo.blocked_amount, damageInfo.resist);
    }

    if (!extra && m_extraAttacks)
    {
        while(m_extraAttacks)
        {
            AttackerStateUpdate(pVictim, BASE_ATTACK, true);
            if (m_extraAttacks > 0)
                --m_extraAttacks;
        }
    }
}

MeleeHitOutcome Unit::RollMeleeOutcomeAgainst(const Unit *pVictim, WeaponAttackType attType) const
{
    // This is only wrapper

    // Miss chance based on melee
    //float miss_chance = MeleeMissChanceCalc(pVictim, attType);
    float miss_chance = MeleeSpellMissChance(pVictim, attType, int32(GetWeaponSkillValue(attType, pVictim)) - int32(pVictim->GetDefenseSkillValue(this)), 0);

    // Critical hit chance
    float crit_chance = GetUnitCriticalChance(attType, pVictim);

    // stunned target cannot dodge and this is check in GetUnitDodgeChance() (returned 0 in this case)
    float dodge_chance = pVictim->GetUnitDodgeChance();
    float block_chance = pVictim->GetUnitBlockChance();
    float parry_chance = pVictim->GetUnitParryChance();

    // Useful if want to specify crit & miss chances for melee, else it could be removed
    sLog->outStaticDebug("MELEE OUTCOME: miss %f crit %f dodge %f parry %f block %f", miss_chance, crit_chance, dodge_chance, parry_chance, block_chance);

    return RollMeleeOutcomeAgainst(pVictim, attType, int32(crit_chance*100), int32(miss_chance*100), int32(dodge_chance*100), int32(parry_chance*100), int32(block_chance*100));
}

MeleeHitOutcome Unit::RollMeleeOutcomeAgainst (const Unit *pVictim, WeaponAttackType attType, int32 crit_chance, int32 miss_chance, int32 dodge_chance, int32 parry_chance, int32 block_chance) const
{
    if (pVictim->GetTypeId() == TYPEID_UNIT && pVictim->ToCreature()->IsInEvadeMode())
        return MELEE_HIT_EVADE;

    int32 attackerMaxSkillValueForLevel = GetMaxSkillValueForLevel(pVictim);
    int32 victimMaxSkillValueForLevel = pVictim->GetMaxSkillValueForLevel(this);

    int32 attackerWeaponSkill = GetWeaponSkillValue(attType, pVictim);
    int32 victimDefenseSkill = pVictim->GetDefenseSkillValue(this);

    // bonus from skills is 0.04%
    int32    skillBonus  = 4 * (attackerWeaponSkill - victimMaxSkillValueForLevel);
    int32    sum = 0, tmp = 0;
    int32    roll = urand (0, 10000);

    sLog->outStaticDebug ("RollMeleeOutcomeAgainst: skill bonus of %d for attacker", skillBonus);
    sLog->outStaticDebug ("RollMeleeOutcomeAgainst: rolled %d, miss %d, dodge %d, parry %d, block %d, crit %d",
        roll, miss_chance, dodge_chance, parry_chance, block_chance, crit_chance);

    tmp = miss_chance;

    if (tmp > 0 && roll < (sum += tmp))
    {
        sLog->outStaticDebug ("RollMeleeOutcomeAgainst: MISS");
        return MELEE_HIT_MISS;
    }

    // always crit against a sitting target (except 0 crit chance)
    if (pVictim->GetTypeId() == TYPEID_PLAYER && crit_chance > 0 && !pVictim->IsStandState())
    {
        sLog->outStaticDebug ("RollMeleeOutcomeAgainst: CRIT (sitting victim)");
        return MELEE_HIT_CRIT;
    }

    // Dodge chance

    // only players can't dodge if attacker is behind
    if (pVictim->GetTypeId() == TYPEID_PLAYER && !pVictim->HasInArc(M_PI, this) && !pVictim->HasAuraType(SPELL_AURA_IGNORE_HIT_DIRECTION))
    {
        sLog->outStaticDebug ("RollMeleeOutcomeAgainst: attack came from behind and victim was a player.");
    }
    else
    {
        // Reduce dodge chance by attacker expertise rating
        if (GetTypeId() == TYPEID_PLAYER)
            dodge_chance -= int32(ToPlayer()->GetExpertiseDodgeOrParryReduction(attType) * 100);
        else
            dodge_chance -= GetTotalAuraModifier(SPELL_AURA_MOD_EXPERTISE) * 25;

        // Modify dodge chance by attacker SPELL_AURA_MOD_COMBAT_RESULT_CHANCE
        dodge_chance+= GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_COMBAT_RESULT_CHANCE, VICTIMSTATE_DODGE) * 100;
        dodge_chance = int32 (float (dodge_chance) * GetTotalAuraMultiplier(SPELL_AURA_MOD_ENEMY_DODGE));

        tmp = dodge_chance;
        if ((tmp > 0)                                        // check if unit _can_ dodge
            && ((tmp -= skillBonus) > 0)
            && roll < (sum += tmp))
        {
            sLog->outStaticDebug ("RollMeleeOutcomeAgainst: DODGE <%d, %d)", sum-tmp, sum);
            return MELEE_HIT_DODGE;
        }
    }

    // parry & block chances

    // check if attack comes from behind, nobody can parry or block if attacker is behind
    if (!pVictim->HasInArc(M_PI, this) && !pVictim->HasAuraType(SPELL_AURA_IGNORE_HIT_DIRECTION))
        sLog->outStaticDebug ("RollMeleeOutcomeAgainst: attack came from behind.");
    else
    {
        // Reduce parry chance by attacker expertise rating
        if (GetTypeId() == TYPEID_PLAYER)
            parry_chance -= int32(ToPlayer()->GetExpertiseDodgeOrParryReduction(attType) * 100);
        else
            parry_chance -= GetTotalAuraModifier(SPELL_AURA_MOD_EXPERTISE) * 25;

        if (pVictim->GetTypeId() == TYPEID_PLAYER || !(pVictim->ToCreature()->GetCreatureInfo()->flags_extra & CREATURE_FLAG_EXTRA_NO_PARRY))
        {
            int32 tmp2 = int32(parry_chance);
            if (tmp2 > 0                                         // check if unit _can_ parry
                && (tmp2 -= skillBonus) > 0
                && roll < (sum += tmp2))
            {
                sLog->outStaticDebug ("RollMeleeOutcomeAgainst: PARRY <%d, %d)", sum-tmp2, sum);
                return MELEE_HIT_PARRY;
            }
        }

        if (pVictim->GetTypeId() == TYPEID_PLAYER || !(pVictim->ToCreature()->GetCreatureInfo()->flags_extra & CREATURE_FLAG_EXTRA_NO_BLOCK))
        {
            tmp = block_chance;
            if (tmp > 0                                          // check if unit _can_ block
                && (tmp -= skillBonus) > 0
                && roll < (sum += tmp))
            {
                sLog->outStaticDebug ("RollMeleeOutcomeAgainst: BLOCK <%d, %d)", sum-tmp, sum);
                return MELEE_HIT_BLOCK;
            }
        }
    }

    // Critical chance
    tmp = crit_chance;

    if (tmp > 0 && roll < (sum += tmp))
    {
        sLog->outStaticDebug ("RollMeleeOutcomeAgainst: CRIT <%d, %d)", sum-tmp, sum);
        if (GetTypeId() == TYPEID_UNIT && (ToCreature()->GetCreatureInfo()->flags_extra & CREATURE_FLAG_EXTRA_NO_CRIT))
            sLog->outStaticDebug ("RollMeleeOutcomeAgainst: CRIT DISABLED)");
        else
            return MELEE_HIT_CRIT;
    }

    // Max 40% chance to score a glancing blow against mobs that are higher level (can do only players and pets and not with ranged weapon)
    if (attType != RANGED_ATTACK &&
        (GetTypeId() == TYPEID_PLAYER || ToCreature()->isPet()) &&
        pVictim->GetTypeId() != TYPEID_PLAYER && !pVictim->ToCreature()->isPet() &&
        getLevel() < pVictim->getLevelForTarget(this))
    {
        // cap possible value (with bonuses > max skill)
        int32 skill = attackerWeaponSkill;
        int32 maxskill = attackerMaxSkillValueForLevel;
        skill = (skill > maxskill) ? maxskill : skill;

        tmp = (10 + (victimDefenseSkill - skill)) * 100;
        tmp = tmp > 4000 ? 4000 : tmp;
        if (roll < (sum += tmp))
        {
            sLog->outStaticDebug ("RollMeleeOutcomeAgainst: GLANCING <%d, %d)", sum-4000, sum);
            return MELEE_HIT_GLANCING;
        }
    }

    // mobs can score crushing blows if they're 4 or more levels above victim
    if (getLevelForTarget(pVictim) >= pVictim->getLevelForTarget(this) + 4 &&
        // can be from by creature (if can) or from controlled player that considered as creature
        !IsControlledByPlayer() &&
        !(GetTypeId() == TYPEID_UNIT && ToCreature()->GetCreatureInfo()->flags_extra & CREATURE_FLAG_EXTRA_NO_CRUSH))
    {
        // when their weapon skill is 15 or more above victim's defense skill
        tmp = victimDefenseSkill;
        int32 tmpmax = victimMaxSkillValueForLevel;
        // having defense above your maximum (from items, talents etc.) has no effect
        tmp = tmp > tmpmax ? tmpmax : tmp;
        // tmp = mob's level * 5 - player's current defense skill
        tmp = attackerMaxSkillValueForLevel - tmp;
        if (tmp >= 15)
        {
            // add 2% chance per lacking skill point, min. is 15%
            tmp = tmp * 200 - 1500;
            if (roll < (sum += tmp))
            {
                sLog->outStaticDebug ("RollMeleeOutcomeAgainst: CRUSHING <%d, %d)", sum-tmp, sum);
                return MELEE_HIT_CRUSHING;
            }
        }
    }

    sLog->outStaticDebug ("RollMeleeOutcomeAgainst: NORMAL");
    return MELEE_HIT_NORMAL;
}

uint32 Unit::CalculateDamage(WeaponAttackType attType, bool normalized, bool addTotalPct)
{
    float min_damage, max_damage;

    if (GetTypeId() == TYPEID_PLAYER && (normalized || !addTotalPct))
        ToPlayer()->CalculateMinMaxDamage(attType, normalized, addTotalPct, min_damage, max_damage);
    else
    {
        switch (attType)
        {
            case RANGED_ATTACK:
                min_damage = GetFloatValue(UNIT_FIELD_MINRANGEDDAMAGE);
                max_damage = GetFloatValue(UNIT_FIELD_MAXRANGEDDAMAGE);
                break;
            case BASE_ATTACK:
                min_damage = GetFloatValue(UNIT_FIELD_MINDAMAGE);
                max_damage = GetFloatValue(UNIT_FIELD_MAXDAMAGE);
                break;
            case OFF_ATTACK:
                min_damage = GetFloatValue(UNIT_FIELD_MINOFFHANDDAMAGE);
                max_damage = GetFloatValue(UNIT_FIELD_MAXOFFHANDDAMAGE);
                break;
                // Just for good manner
            default:
                min_damage = 0.0f;
                max_damage = 0.0f;
                break;
        }
    }

    if (min_damage > max_damage)
        std::swap(min_damage, max_damage);

    if (max_damage == 0.0f)
        max_damage = 5.0f;

    return urand((uint32)min_damage, (uint32)max_damage);
}

float Unit::CalculateLevelPenalty(SpellEntry const* spellProto) const
{
    if (spellProto->spellLevel <= 0 || spellProto->spellLevel >= spellProto->maxLevel)
        return 1.0f;

    float LvlPenalty = 0.0f;

    if (spellProto->spellLevel < 20)
        LvlPenalty = 20.0f - spellProto->spellLevel * 3.75f;
    float LvlFactor = (float(spellProto->spellLevel) + 6.0f) / float(getLevel());
    if (LvlFactor > 1.0f)
        LvlFactor = 1.0f;

    return AddPctF(LvlFactor, -LvlPenalty);
}

void Unit::SendMeleeAttackStart(Unit* pVictim)
{
    WorldPacket data(SMSG_ATTACKSTART, 8 + 8);
    data << uint64(GetGUID());
    data << uint64(pVictim->GetGUID());

    SendMessageToSet(&data, true);
    sLog->outStaticDebug("WORLD: Sent SMSG_ATTACKSTART");
}

void Unit::SendMeleeAttackStop(Unit* victim)
{
    if (!victim)
        return;

    WorldPacket data(SMSG_ATTACKSTOP, (8+8+4));            // we guess size
    data.append(GetPackGUID());
    data.append(victim->GetPackGUID());                     // can be 0x00...
    data << uint32(0);                                      // can be 0x1
    SendMessageToSet(&data, true);
    sLog->outDetail("%s %u stopped attacking %s %u", (GetTypeId() == TYPEID_PLAYER ? "player" : "creature"), GetGUIDLow(), (victim->GetTypeId() == TYPEID_PLAYER ? "player" : "creature"), victim->GetGUIDLow());
}

bool Unit::isSpellBlocked(Unit* victim, SpellEntry const* spellProto, WeaponAttackType attackType)
{
    // These spells can't be blocked
    if (spellProto && spellProto->Attributes & SPELL_ATTR0_IMPOSSIBLE_DODGE_PARRY_BLOCK)
        return false;

    if (victim->HasAuraType(SPELL_AURA_IGNORE_HIT_DIRECTION) || victim->HasInArc(M_PI, this))
    {
        // Check creatures flags_extra for disable block
        if (victim->GetTypeId() == TYPEID_UNIT &&
            victim->ToCreature()->GetCreatureInfo()->flags_extra & CREATURE_FLAG_EXTRA_NO_BLOCK)
                return false;

        float blockChance = victim->GetUnitBlockChance();
        blockChance += (int32(GetWeaponSkillValue(attackType)) - int32(victim->GetMaxSkillValueForLevel())) * 0.04f;
        if (roll_chance_f(blockChance))
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

int32 Unit::GetMechanicResistChance(const SpellEntry *spell)
{
    if (!spell)
        return 0;
    int32 resist_mech = 0;
    for (uint8 eff = 0; eff < MAX_SPELL_EFFECTS; ++eff)
    {
        if (spell->Effect[eff] == 0)
           break;
        int32 effect_mech = GetEffectMechanic(spell, eff);
        if (effect_mech)
        {
            int32 temp = GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_MECHANIC_RESISTANCE, effect_mech);
            if (resist_mech < temp)
                resist_mech = temp;
        }
    }
    return resist_mech;
}

// Melee based spells hit result calculations
SpellMissInfo Unit::MeleeSpellHitResult(Unit *pVictim, SpellEntry const *spell)
{
    // Spells with SPELL_ATTR3_IGNORE_HIT_RESULT will additionally fully ignore
    // resist and deflect chances
    if (spell->AttributesEx3 & SPELL_ATTR3_IGNORE_HIT_RESULT)
        return SPELL_MISS_NONE;

    WeaponAttackType attType = BASE_ATTACK;

    // Check damage class instead of attack type to correctly handle judgements
    // - they are meele, but can't be dodged/parried/deflected because of ranged dmg class
    if (spell->DmgClass == SPELL_DAMAGE_CLASS_RANGED)
        attType = RANGED_ATTACK;

    int32 attackerWeaponSkill;
    // skill value for these spells (for example judgements) is 5* level
    if (spell->DmgClass == SPELL_DAMAGE_CLASS_RANGED && !IsRangedWeaponSpell(spell))
        attackerWeaponSkill = getLevel() * 5;
    // bonus from skills is 0.04% per skill Diff
    else
        attackerWeaponSkill = int32(GetWeaponSkillValue(attType, pVictim));

    int32 skillDiff = attackerWeaponSkill - int32(pVictim->GetMaxSkillValueForLevel(this));
    int32 fullSkillDiff = attackerWeaponSkill - int32(pVictim->GetDefenseSkillValue(this));

    uint32 roll = urand (0, 10000);

    uint32 missChance = uint32(MeleeSpellMissChance(pVictim, attType, fullSkillDiff, spell->Id) * 100.0f);
    // Roll miss
    uint32 tmp = missChance;
    if (roll < tmp)
        return SPELL_MISS_MISS;

    // Chance resist mechanic (select max value from every mechanic spell effect)
    int32 resist_mech = 0;
    // Get effects mechanic and chance
    for (uint8 eff = 0; eff < MAX_SPELL_EFFECTS; ++eff)
    {
        int32 effect_mech = GetEffectMechanic(spell, eff);
        if (effect_mech)
        {
            int32 temp = pVictim->GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_MECHANIC_RESISTANCE, effect_mech);
            if (resist_mech < temp*100)
                resist_mech = temp*100;
        }
    }
    // Roll chance
    tmp += resist_mech;
    if (roll < tmp)
        return SPELL_MISS_RESIST;

    bool canDodge = true;
    bool canParry = true;
    bool canBlock = spell->AttributesEx3 & SPELL_ATTR3_BLOCKABLE_SPELL;

    // Same spells cannot be parry/dodge
    if (spell->Attributes & SPELL_ATTR0_IMPOSSIBLE_DODGE_PARRY_BLOCK)
        return SPELL_MISS_NONE;

    // Chance resist mechanic
    int32 resist_chance = pVictim->GetMechanicResistChance(spell) * 100;
    tmp += resist_chance;
    if (roll < tmp)
        return SPELL_MISS_RESIST;

    // Ranged attacks can only miss, resist and deflect
    if (attType == RANGED_ATTACK)
    {
        // only if in front
        if (pVictim->HasInArc(M_PI, this) || pVictim->HasAuraType(SPELL_AURA_IGNORE_HIT_DIRECTION))
        {
            int32 deflect_chance = pVictim->GetTotalAuraModifier(SPELL_AURA_DEFLECT_SPELLS) * 100;
            tmp+=deflect_chance;
            if (roll < tmp)
                return SPELL_MISS_DEFLECT;
        }
        return SPELL_MISS_NONE;
    }

    // Check for attack from behind
    if (!pVictim->HasInArc(M_PI, this) && !pVictim->HasAuraType(SPELL_AURA_IGNORE_HIT_DIRECTION))
    {
        // Can`t dodge from behind in PvP (but its possible in PvE)
        if (pVictim->GetTypeId() == TYPEID_PLAYER)
            canDodge = false;
        // Can`t parry or block
        canParry = false;
        canBlock = false;
    }
    // Check creatures flags_extra for disable parry
    if (pVictim->GetTypeId() == TYPEID_UNIT)
    {
        uint32 flagEx = pVictim->ToCreature()->GetCreatureInfo()->flags_extra;
        if (flagEx & CREATURE_FLAG_EXTRA_NO_PARRY)
            canParry = false;
        // Check creatures flags_extra for disable block
        if (flagEx & CREATURE_FLAG_EXTRA_NO_BLOCK)
            canBlock = false;
    }
    // Ignore combat result aura
    AuraEffectList const& ignore = GetAuraEffectsByType(SPELL_AURA_IGNORE_COMBAT_RESULT);
    for (AuraEffectList::const_iterator i = ignore.begin(); i != ignore.end(); ++i)
    {
        if (!(*i)->IsAffectedOnSpell(spell))
            continue;
        switch ((*i)->GetMiscValue())
        {
            case MELEE_HIT_DODGE: canDodge = false; break;
            case MELEE_HIT_BLOCK: canBlock = false; break;
            case MELEE_HIT_PARRY: canParry = false; break;
            default:
                sLog->outStaticDebug("Spell %u SPELL_AURA_IGNORE_COMBAT_RESULT have unhandled state %d", (*i)->GetId(), (*i)->GetMiscValue());
                break;
        }
    }

    if (canDodge)
    {
        // Roll dodge
        int32 dodgeChance = int32(pVictim->GetUnitDodgeChance() * 100.0f) - skillDiff * 4;
        // Reduce enemy dodge chance by SPELL_AURA_MOD_COMBAT_RESULT_CHANCE
        dodgeChance += GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_COMBAT_RESULT_CHANCE, VICTIMSTATE_DODGE) * 100;
        dodgeChance = int32(float(dodgeChance) * GetTotalAuraMultiplier(SPELL_AURA_MOD_ENEMY_DODGE));
        // Reduce dodge chance by attacker expertise rating
        if (GetTypeId() == TYPEID_PLAYER)
            dodgeChance -= int32(ToPlayer()->GetExpertiseDodgeOrParryReduction(attType) * 100.0f);
        else
            dodgeChance -= GetTotalAuraModifier(SPELL_AURA_MOD_EXPERTISE) * 25;
        if (dodgeChance < 0)
            dodgeChance = 0;

        if (roll < (tmp += dodgeChance))
            return SPELL_MISS_DODGE;
    }

    if (canParry)
    {
        // Roll parry
        int32 parryChance = int32(pVictim->GetUnitParryChance() * 100.0f)  - skillDiff * 4;
        // Reduce parry chance by attacker expertise rating
        if (GetTypeId() == TYPEID_PLAYER)
            parryChance -= int32(ToPlayer()->GetExpertiseDodgeOrParryReduction(attType) * 100.0f);
        else
            parryChance -= GetTotalAuraModifier(SPELL_AURA_MOD_EXPERTISE) * 25;
        if (parryChance < 0)
            parryChance = 0;

        tmp += parryChance;
        if (roll < tmp)
            return SPELL_MISS_PARRY;
    }

    if (canBlock)
    {
        int32 blockChance = int32(pVictim->GetUnitBlockChance() * 100.0f) - skillDiff * 4;
        if (blockChance < 0)
            blockChance = 0;
        tmp += blockChance;

        if (roll < tmp)
            return SPELL_MISS_BLOCK;
    }

    return SPELL_MISS_NONE;
}

// TODO need use unit spell resistances in calculations
SpellMissInfo Unit::MagicSpellHitResult(Unit *pVictim, SpellEntry const *spell)
{
    // Can`t miss on dead target (on skinning for example)
    if (!pVictim->isAlive() && pVictim->GetTypeId() != TYPEID_PLAYER)
        return SPELL_MISS_NONE;

    SpellSchoolMask schoolMask = GetSpellSchoolMask(spell);
    // PvP - PvE spell misschances per leveldif > 2
    int32 lchance = pVictim->GetTypeId() == TYPEID_PLAYER ? 7 : 11;
    int32 thisLevel = getLevelForTarget(pVictim);
    if (GetTypeId() == TYPEID_UNIT && ToCreature()->isTrigger())
        thisLevel = std::max<int32>(thisLevel, spell->spellLevel);
    int32 leveldif = int32(pVictim->getLevelForTarget(this)) - thisLevel;

    // Base hit chance from attacker and victim levels
    int32 modHitChance;
    if (leveldif < 3)
        modHitChance = 96 - leveldif;
    else
        modHitChance = 94 - (leveldif - 2) * lchance;

    // Spellmod from SPELLMOD_RESIST_MISS_CHANCE
    if (Player* modOwner = GetSpellModOwner())
        modOwner->ApplySpellMod(spell->Id, SPELLMOD_RESIST_MISS_CHANCE, modHitChance);

    // Increase from attacker SPELL_AURA_MOD_INCREASES_SPELL_PCT_TO_HIT auras
    modHitChance += GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_INCREASES_SPELL_PCT_TO_HIT, schoolMask);

    // Spells with SPELL_ATTR3_IGNORE_HIT_RESULT will ignore target's avoidance effects
    if (!(spell->AttributesEx3 & SPELL_ATTR3_IGNORE_HIT_RESULT))
    {
        // Chance hit from victim SPELL_AURA_MOD_ATTACKER_SPELL_HIT_CHANCE auras
        modHitChance += pVictim->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_ATTACKER_SPELL_HIT_CHANCE, schoolMask);
        // Reduce spell hit chance for Area of effect spells from victim SPELL_AURA_MOD_AOE_AVOIDANCE aura
        if (IsAreaOfEffectSpell(spell))
            modHitChance -= pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_AOE_AVOIDANCE);

        // Decrease hit chance from victim rating bonus
        if (pVictim->GetTypeId() == TYPEID_PLAYER)
            modHitChance -= int32(pVictim->ToPlayer()->GetRatingBonusValue(CR_HIT_TAKEN_SPELL));
    }

    int32 HitChance = modHitChance * 100;
    // Increase hit chance from attacker SPELL_AURA_MOD_SPELL_HIT_CHANCE and attacker ratings
    HitChance += int32(m_modSpellHitChance * 100.0f);

    if (HitChance < 100)
        HitChance = 100;
    else if (HitChance > 10000)
        HitChance = 10000;

    int32 tmp = 10000 - HitChance;

    int32 rand = irand(0, 10000);

    if (rand < tmp)
        return SPELL_MISS_MISS;

    // Spells with SPELL_ATTR3_IGNORE_HIT_RESULT will additionally fully ignore
    // resist and deflect chances
    if (spell->AttributesEx3 & SPELL_ATTR3_IGNORE_HIT_RESULT)
        return SPELL_MISS_NONE;

    // Chance resist mechanic (select max value from every mechanic spell effect)
    int32 resist_chance = pVictim->GetMechanicResistChance(spell) * 100;
    tmp += resist_chance;

    // Chance resist debuff
    if (!IsPositiveSpell(spell->Id))
    {
        bool bNegativeAura = false;
        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        {
            if (spell->EffectApplyAuraName[i] != 0)
            {
                bNegativeAura = true;
                break;
            }
        }

        if (bNegativeAura)
        {
            tmp += pVictim->GetMaxPositiveAuraModifierByMiscValue(SPELL_AURA_MOD_DEBUFF_RESISTANCE, int32(spell->Dispel)) * 100;
            tmp += pVictim->GetMaxNegativeAuraModifierByMiscValue(SPELL_AURA_MOD_DEBUFF_RESISTANCE, int32(spell->Dispel)) * 100;
        }
    }

   // Roll chance
    if (rand < tmp)
        return SPELL_MISS_RESIST;

    // cast by caster in front of victim
    if (pVictim->HasInArc(M_PI, this) || pVictim->HasAuraType(SPELL_AURA_IGNORE_HIT_DIRECTION))
    {
        int32 deflect_chance = pVictim->GetTotalAuraModifier(SPELL_AURA_DEFLECT_SPELLS) * 100;
        tmp += deflect_chance;
        if (rand < tmp)
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
SpellMissInfo Unit::SpellHitResult(Unit *pVictim, SpellEntry const *spell, bool CanReflect)
{
    // Check for immune
    if (pVictim->IsImmunedToSpell(spell))
        return SPELL_MISS_IMMUNE;

    // All positive spells can`t miss
    // TODO: client not show miss log for this spells - so need find info for this in dbc and use it!
    if (IsPositiveSpell(spell->Id)
        &&(!IsHostileTo(pVictim)))  // prevent from affecting enemy by "positive" spell
        return SPELL_MISS_NONE;
    // Check for immune
    if (pVictim->IsImmunedToDamage(spell))
        return SPELL_MISS_IMMUNE;

    if (this == pVictim)
        return SPELL_MISS_NONE;

    // Return evade for units in evade mode
    if (pVictim->GetTypeId() == TYPEID_UNIT && pVictim->ToCreature()->IsInEvadeMode())
        return SPELL_MISS_EVADE;

    // Try victim reflect spell
    if (CanReflect)
    {
        int32 reflectchance = pVictim->GetTotalAuraModifier(SPELL_AURA_REFLECT_SPELLS);
        Unit::AuraEffectList const& mReflectSpellsSchool = pVictim->GetAuraEffectsByType(SPELL_AURA_REFLECT_SPELLS_SCHOOL);
        for (Unit::AuraEffectList::const_iterator i = mReflectSpellsSchool.begin(); i != mReflectSpellsSchool.end(); ++i)
            if ((*i)->GetMiscValue() & GetSpellSchoolMask(spell))
                reflectchance += (*i)->GetAmount();
        if (reflectchance > 0 && roll_chance_i(reflectchance))
        {
            // Start triggers for remove charges if need (trigger only for victim, and mark as active spell)
            ProcDamageAndSpell(pVictim, PROC_FLAG_NONE, PROC_FLAG_TAKEN_SPELL_MAGIC_DMG_CLASS_NEG, PROC_EX_REFLECT, 1, BASE_ATTACK, spell);
            return SPELL_MISS_REFLECT;
        }
    }

    switch (spell->DmgClass)
    {
        case SPELL_DAMAGE_CLASS_RANGED:
        case SPELL_DAMAGE_CLASS_MELEE:
            return MeleeSpellHitResult(pVictim, spell);
        case SPELL_DAMAGE_CLASS_NONE:
            return SPELL_MISS_NONE;
        case SPELL_DAMAGE_CLASS_MAGIC:
            return MagicSpellHitResult(pVictim, spell);
    }
    return SPELL_MISS_NONE;
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
        return GetUnitMeleeSkill(target);
}

float Unit::GetUnitDodgeChance() const
{
    if (IsNonMeleeSpellCasted(false) || HasUnitState(UNIT_STAT_STUNNED))
        return 0.0f;

    if (GetTypeId() == TYPEID_PLAYER)
        return GetFloatValue(PLAYER_DODGE_PERCENTAGE);
    else
    {
        if (ToCreature()->isTotem())
            return 0.0f;
        else
        {
            float dodge = 5.0f;
            dodge += GetTotalAuraModifier(SPELL_AURA_MOD_DODGE_PERCENT);
            return dodge > 0.0f ? dodge : 0.0f;
        }
    }
}

float Unit::GetUnitParryChance() const
{
    if (IsNonMeleeSpellCasted(false) || HasUnitState(UNIT_STAT_STUNNED))
        return 0.0f;

    float chance = 0.0f;

    if (Player const* player = ToPlayer())
    {
        if (player->CanParry())
        {
            Item* tmpitem = player->GetWeaponForAttack(BASE_ATTACK, true);
            if (!tmpitem)
                tmpitem = player->GetWeaponForAttack(OFF_ATTACK, true);

            if (tmpitem)
                chance = GetFloatValue(PLAYER_PARRY_PERCENTAGE);
        }
    }
    else if (GetTypeId() == TYPEID_UNIT)
    {
        if (GetCreatureType() == CREATURE_TYPE_HUMANOID)
        {
            chance = 5.0f;
            chance += GetTotalAuraModifier(SPELL_AURA_MOD_PARRY_PERCENT);
        }
    }

    return chance > 0.0f ? chance : 0.0f;
}

float Unit::GetUnitBlockChance() const
{
    if (IsNonMeleeSpellCasted(false) || HasUnitState(UNIT_STAT_STUNNED))
        return 0.0f;

    if (Player const* player = ToPlayer())
    {
        if (player->CanBlock())
        {
            Item* tmpitem = player->GetUseableItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
            if (tmpitem && !tmpitem->IsBroken() && tmpitem->GetTemplate()->Block)
                return GetFloatValue(PLAYER_BLOCK_PERCENTAGE);
        }
        // is player but has no block ability or no not broken shield equipped
        return 0.0f;
    }
    else
    {
        if (ToCreature()->isTotem())
            return 0.0f;
        else
        {
            float block = 5.0f;
            block += GetTotalAuraModifier(SPELL_AURA_MOD_BLOCK_PERCENT);
            return block > 0.0f ? block : 0.0f;
        }
    }
}

float Unit::GetUnitCriticalChance(WeaponAttackType attackType, const Unit *pVictim) const
{
    float crit;

    if (GetTypeId() == TYPEID_PLAYER)
    {
        switch(attackType)
        {
            case BASE_ATTACK:
                crit = GetFloatValue(PLAYER_CRIT_PERCENTAGE);
                break;
            case OFF_ATTACK:
                crit = GetFloatValue(PLAYER_OFFHAND_CRIT_PERCENTAGE);
                break;
            case RANGED_ATTACK:
                crit = GetFloatValue(PLAYER_RANGED_CRIT_PERCENTAGE);
                break;
                // Just for good manner
            default:
                crit = 0.0f;
                break;
        }
    }
    else
    {
        crit = 5.0f;
        crit += GetTotalAuraModifier(SPELL_AURA_MOD_WEAPON_CRIT_PERCENT);
        crit += GetTotalAuraModifier(SPELL_AURA_MOD_CRIT_PCT);
    }

    // flat aura mods
    if (attackType == RANGED_ATTACK)
        crit += pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_RANGED_CRIT_CHANCE);
    else
        crit += pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_MELEE_CRIT_CHANCE);

    crit += pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_SPELL_AND_WEAPON_CRIT_CHANCE);

    // reduce crit chance from Rating for players
    if (attackType != RANGED_ATTACK)
    {
        ApplyResilience(pVictim, &crit, NULL, false, CR_CRIT_TAKEN_MELEE);
        // Glyph of barkskin
        if (pVictim->HasAura(63057) && pVictim->HasAura(22812))
            crit -= 25.0f;
    }
    else
        ApplyResilience(pVictim, &crit, NULL, false, CR_CRIT_TAKEN_RANGED);

    // Apply crit chance from defence skill
    crit += (int32(GetMaxSkillValueForLevel(pVictim)) - int32(pVictim->GetDefenseSkillValue(this))) * 0.04f;

    if (crit < 0.0f)
        crit = 0.0f;
    return crit;
}

uint32 Unit::GetWeaponSkillValue (WeaponAttackType attType, Unit const* target) const
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

        // weapon skill or (unarmed for base attack and fist weapons)
        uint32 skill;
        if (item && item->GetSkill() != SKILL_FIST_WEAPONS)
            skill = item->GetSkill();
        else
            skill = SKILL_UNARMED;

        // in PvP use full skill instead current skill value
        value = (target && target->IsControlledByPlayer())
            ? player->GetMaxSkillValue(skill)
            : player->GetSkillValue(skill);
        // Modify value from ratings
        value += uint32(player->GetRatingBonusValue(CR_WEAPON_SKILL));
        switch (attType)
        {
            case BASE_ATTACK:   value += uint32(player->GetRatingBonusValue(CR_WEAPON_SKILL_MAINHAND)); break;
            case OFF_ATTACK:    value += uint32(player->GetRatingBonusValue(CR_WEAPON_SKILL_OFFHAND));  break;
            case RANGED_ATTACK: value += uint32(player->GetRatingBonusValue(CR_WEAPON_SKILL_RANGED));   break;
            default: break;
        }
    }
    else
        value = GetUnitMeleeSkill(target);
   return value;
}

void Unit::_DeleteRemovedAuras()
{
    while (!m_removedAuras.empty())
    {
        delete m_removedAuras.front();
        m_removedAuras.pop_front();
    }
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
            m_currentSpells[i] = NULL;                      // remove pointer
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
                (*itr)->SetOwnerGUID(0);
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
    // check "realtime" interrupts
    if ((GetTypeId() == TYPEID_PLAYER && ToPlayer()->isMoving()) || IsNonMeleeSpellCasted(false, false, true, m_currentSpells[CURRENT_AUTOREPEAT_SPELL]->m_spellInfo->Id == 75))
    {
        // cancel wand shoot
        if (m_currentSpells[CURRENT_AUTOREPEAT_SPELL]->m_spellInfo->Id != 75)
            InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
        m_AutoRepeatFirstCast = true;
        return;
    }

    // apply delay (Auto Shot (spellID 75) not affected)
    if (m_AutoRepeatFirstCast && getAttackTimer(RANGED_ATTACK) < 500 && m_currentSpells[CURRENT_AUTOREPEAT_SPELL]->m_spellInfo->Id != 75)
        setAttackTimer(RANGED_ATTACK, 500);
    m_AutoRepeatFirstCast = false;

    // castroutine
    if (isAttackReady(RANGED_ATTACK))
    {
        // Check if able to cast
        if (m_currentSpells[CURRENT_AUTOREPEAT_SPELL]->CheckCast(true) != SPELL_CAST_OK)
        {
            InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
            return;
        }

        // we want to shoot
        Spell* spell = new Spell(this, m_currentSpells[CURRENT_AUTOREPEAT_SPELL]->m_spellInfo, true);
        spell->prepare(&(m_currentSpells[CURRENT_AUTOREPEAT_SPELL]->m_targets));

        // all went good, reset attack
        resetAttackTimer(RANGED_ATTACK);
    }
}

void Unit::SetCurrentCastedSpell(Spell* pSpell)
{
    ASSERT(pSpell);                                         // NULL may be never passed here, use InterruptSpell or InterruptNonMeleeSpells

    CurrentSpellTypes CSpellType = pSpell->GetCurrentContainer();

    if (pSpell == m_currentSpells[CSpellType]) return;      // avoid breaking self

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
                if (m_currentSpells[CURRENT_AUTOREPEAT_SPELL]->m_spellInfo->Id != 75)
                    InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
                m_AutoRepeatFirstCast = true;
            }
            AddUnitState(UNIT_STAT_CASTING);
        } break;

        case CURRENT_CHANNELED_SPELL:
        {
            // channel spells always break generic non-delayed and any channeled spells
            InterruptSpell(CURRENT_GENERIC_SPELL, false);
            InterruptSpell(CURRENT_CHANNELED_SPELL);

            // it also does break autorepeat if not Auto Shot
            if (m_currentSpells[CURRENT_AUTOREPEAT_SPELL] &&
                m_currentSpells[CURRENT_AUTOREPEAT_SPELL]->m_spellInfo->Id != 75)
                InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
            AddUnitState(UNIT_STAT_CASTING);
        } break;

        case CURRENT_AUTOREPEAT_SPELL:
        {
            // only Auto Shoot does not break anything
            if (pSpell->m_spellInfo->Id != 75)
            {
                // generic autorepeats break generic non-delayed and channeled non-delayed spells
                InterruptSpell(CURRENT_GENERIC_SPELL, false);
                InterruptSpell(CURRENT_CHANNELED_SPELL, false);
            }
            // special action: set first cast flag
            m_AutoRepeatFirstCast = true;
        } break;

        default:
        {
            // other spell types don't break anything now
        } break;
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
    ASSERT(spellType < CURRENT_MAX_SPELL);

    //sLog->outDebug(LOG_FILTER_UNITS, "Interrupt spell for unit %u.", GetEntry());
    Spell* spell = m_currentSpells[spellType];
    if (spell
        && (withDelayed || spell->getState() != SPELL_STATE_DELAYED)
        && (withInstant || spell->GetCastTime() > 0))
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

        m_currentSpells[spellType] = NULL;
        spell->SetReferencedFromCurrent(false);
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

bool Unit::IsNonMeleeSpellCasted(bool withDelayed, bool skipChanneled, bool skipAutorepeat, bool isAutoshoot, bool skipInstant) const
{
    // We don't do loop here to explicitly show that melee spell is excluded.
    // Maybe later some special spells will be excluded too.

    // if checkInstant then instant spells shouldn't count as being casted
    if (!skipInstant && m_currentSpells[CURRENT_GENERIC_SPELL] && !m_currentSpells[CURRENT_GENERIC_SPELL]->GetCastTime())
        return false;

    // generic spells are casted when they are not finished and not delayed
    if (m_currentSpells[CURRENT_GENERIC_SPELL] &&
        (m_currentSpells[CURRENT_GENERIC_SPELL]->getState() != SPELL_STATE_FINISHED) &&
        (withDelayed || m_currentSpells[CURRENT_GENERIC_SPELL]->getState() != SPELL_STATE_DELAYED))
    {
        if (!isAutoshoot || !(m_currentSpells[CURRENT_GENERIC_SPELL]->m_spellInfo->AttributesEx2 & SPELL_ATTR2_NOT_RESET_AUTO_ACTIONS))
            return(true);
    }
    // channeled spells may be delayed, but they are still considered casted
    else if (!skipChanneled && m_currentSpells[CURRENT_CHANNELED_SPELL] &&
        (m_currentSpells[CURRENT_CHANNELED_SPELL]->getState() != SPELL_STATE_FINISHED))
    {
        if (!isAutoshoot || !(m_currentSpells[CURRENT_CHANNELED_SPELL]->m_spellInfo->AttributesEx2 & SPELL_ATTR2_NOT_RESET_AUTO_ACTIONS))
            return(true);
    }
    // autorepeat spells may be finished or delayed, but they are still considered casted
    else if (!skipAutorepeat && m_currentSpells[CURRENT_AUTOREPEAT_SPELL])
        return(true);

    return(false);
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
    return NULL;
}

int32 Unit::GetCurrentSpellCastTime(uint32 spell_id) const
{
    if (Spell const* spell = FindCurrentSpellBySpellId(spell_id))
        return spell->GetCastTime();
    return 0;
}

bool Unit::isInFrontInMap(Unit const* target, float distance,  float arc) const
{
    return IsWithinDistInMap(target, distance) && HasInArc(arc, target);
}

bool Unit::isInBackInMap(Unit const* target, float distance, float arc) const
{
    return IsWithinDistInMap(target, distance) && !HasInArc(2 * M_PI - arc, target);
}

void Unit::SetFacingToObject(WorldObject* pObject)
{
    // update orientation at server
    SetOrientation(GetAngle(pObject));

    // and client
    WorldPacket data;
    BuildHeartBeatMsg(&data);
    SendMessageToSet(&data, false);
}

bool Unit::isInAccessiblePlaceFor(Creature const* c) const
{
    if (IsInWater())
        return c->canSwim();
    else
        return c->canWalk() || c->canFly();
}

bool Unit::IsInWater() const
{
    return GetBaseMap()->IsInWater(GetPositionX(), GetPositionY(), GetPositionZ());
}

bool Unit::IsUnderWater() const
{
    return GetBaseMap()->IsUnderWater(GetPositionX(), GetPositionY(), GetPositionZ());
}

void Unit::DeMorph()
{
    SetDisplayId(GetNativeDisplayId());
}

Aura* Unit::_TryStackingOrRefreshingExistingAura(SpellEntry const* newAura, uint8 effMask, Unit* caster, int32* baseAmount /*= NULL*/, Item* castItem /*= NULL*/, uint64 casterGUID /*= 0*/)
{
    ASSERT(casterGUID || caster);
    if (!casterGUID)
        casterGUID = caster->GetGUID();

    // passive and Incanter's Absorption and auras with different type can stack with themselves any number of times
    if (!IsMultiSlotAura(newAura))
    {
        // check if cast item changed
        uint64 castItemGUID = 0;
        if (castItem)
            castItemGUID = castItem->GetGUID();

        // find current aura from spell and change it's stackamount, or refresh it's duration
        if (Aura* foundAura = GetOwnedAura(newAura->Id, casterGUID, (sSpellMgr->GetSpellCustomAttr(newAura->Id) & SPELL_ATTR0_CU_ENCHANT_PROC) ? castItemGUID : 0, 0))
        {
            // effect masks do not match
            // extremely rare case
            // let's just recreate aura
            if (effMask != foundAura->GetEffectMask())
                return NULL;

            // update basepoints with new values - effect amount will be recalculated in ModStackAmount
            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
            {
                if (!foundAura->HasEffect(i))
                    continue;

                int bp;
                if (baseAmount)
                    bp = *(baseAmount + i);
                else
                    bp = foundAura->GetSpellProto()->EffectBasePoints[i];

                int32* oldBP = const_cast<int32*>(&(foundAura->GetEffect(i)->m_baseAmount));
                *oldBP = bp;
            }

            // correct cast item guid if needed
            if (castItemGUID != foundAura->GetCastItemGUID())
            {
                uint64* oldGUID = const_cast<uint64 *>(&foundAura->m_castItemGuid);
                *oldGUID = castItemGUID;
            }

            // try to increase stack amount
            foundAura->ModStackAmount(1);
            return foundAura;
        }
    }

    return NULL;
}

void Unit::_AddAura(UnitAura* aura, Unit* caster)
{
    ASSERT(!m_cleanupDone);
    m_ownedAuras.insert(AuraMap::value_type(aura->GetId(), aura));

    _RemoveNoStackAurasDueToAura(aura);

    if (aura->IsRemoved())
        return;

    aura->SetIsSingleTarget(caster && IsSingleTargetSpell(aura->GetSpellProto()));
    if (aura->IsSingleTarget())
    {
        ASSERT((IsInWorld() && !IsDuringRemoveFromWorld()) || (aura->GetCasterGUID() == GetGUID()));
        // register single target aura
        caster->GetSingleCastAuras().push_back(aura);
        // remove other single target auras
        Unit::AuraList& scAuras = caster->GetSingleCastAuras();
        for (Unit::AuraList::iterator itr = scAuras.begin(); itr != scAuras.end();)
        {
            if ((*itr) != aura &&
                IsSingleTargetSpells((*itr)->GetSpellProto(), aura->GetSpellProto()))
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
AuraApplication * Unit::_CreateAuraApplication(Aura * aura, uint8 effMask)
{
    // can't apply aura on unit which is going to be deleted - to not create a memory leak
    ASSERT(!m_cleanupDone);
    // aura musn't be removed
    ASSERT(!aura->IsRemoved());

    // aura mustn't be already applied on target
    ASSERT (!aura->IsAppliedOnTarget(GetGUID()) && "Unit::_CreateAuraApplication: aura musn't be applied on target");

    SpellEntry const* aurSpellInfo = aura->GetSpellProto();
    uint32 aurId = aurSpellInfo->Id;

    // ghost spell check, allow apply any auras at player loading in ghost mode (will be cleanup after load)
    if (!isAlive() && !IsDeathPersistentSpell(aurSpellInfo) &&
        (GetTypeId() != TYPEID_PLAYER || !ToPlayer()->GetSession()->PlayerLoading()))
        return NULL;

    Unit* caster = aura->GetCaster();

    AuraApplication * aurApp = new AuraApplication(this, caster, aura, effMask);
    m_appliedAuras.insert(AuraApplicationMap::value_type(aurId, aurApp));

    if (aurSpellInfo->AuraInterruptFlags)
    {
        m_interruptableAuras.push_back(aurApp);
        AddInterruptMask(aurSpellInfo->AuraInterruptFlags);
    }

    if (AuraState aState = GetSpellAuraState(aura->GetSpellProto()))
        m_auraStateAuras.insert(AuraStateAurasMap::value_type(aState, aurApp));

    aura->_ApplyForTarget(this, caster, aurApp);
    return aurApp;
}

void Unit::_ApplyAuraEffect(Aura * aura, uint8 effIndex)
{
    ASSERT(aura);
    ASSERT(aura->HasEffect(effIndex));
    AuraApplication * aurApp = aura->GetApplicationOfTarget(GetGUID());
    ASSERT(aurApp);
    if (!aurApp->GetEffectMask())
        _ApplyAura(aurApp, 1<<effIndex);
    else
        aurApp->_HandleEffect(effIndex, true);
}

// handles effects of aura application
// should be done after registering aura in lists
void Unit::_ApplyAura(AuraApplication * aurApp, uint8 effMask)
{
    Aura* aura = aurApp->GetBase();

    _RemoveNoStackAurasDueToAura(aura);

    if (aurApp->GetRemoveMode())
        return;

    // Update target aura state flag
    if (AuraState aState = GetSpellAuraState(aura->GetSpellProto()))
        ModifyAuraState(aState, true);

    if (aurApp->GetRemoveMode())
        return;

    // Sitdown on apply aura req seated
    if (aura->GetSpellProto()->AuraInterruptFlags & AURA_INTERRUPT_FLAG_NOT_SEATED && !IsSitState())
        SetStandState(UNIT_STAND_STATE_SIT);

    Unit* caster = aura->GetCaster();

    if (aurApp->GetRemoveMode())
        return;

    aura->HandleAuraSpecificMods(aurApp, caster, true, false);

    // apply effects of the aura
    for (uint8 i = 0 ; i < MAX_SPELL_EFFECTS; ++i)
    {
        if (effMask & 1<<i && (!aurApp->GetRemoveMode()))
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
    sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "Aura %u now is remove mode %d", aura->GetId(), removeMode);

    // dead loop is killing the server probably
    ASSERT(m_removedAurasCount < 0xFFFFFFFF);

    ++m_removedAurasCount;

    Unit* caster = aura->GetCaster();

    // Remove all pointers from lists here to prevent possible pointer invalidation on spellcast/auraapply/auraremove
    m_appliedAuras.erase(i);

    if (aura->GetSpellProto()->AuraInterruptFlags)
    {
        m_interruptableAuras.remove(aurApp);
        UpdateInterruptMask();
    }

    bool auraStateFound = false;
    AuraState auraState = GetSpellAuraState(aura->GetSpellProto());
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
    for (uint8 itr = 0 ; itr < MAX_SPELL_EFFECTS; ++itr)
    {
        if (aurApp->HasEffect(itr))
            aurApp->_HandleEffect(itr, false);
    }

    // all effect mustn't be applied
    ASSERT(!aurApp->GetEffectMask());

    // Remove totem at next update if totem loses its aura
    if (aurApp->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE && GetTypeId() == TYPEID_UNIT && ToCreature()->isTotem()&& ToTotem()->GetSummonerGUID() == aura->GetCasterGUID())
    {
        if (ToTotem()->GetSpell() == aura->GetId() && ToTotem()->GetTotemType() == TOTEM_PASSIVE)
            ToTotem()->setDeathState(JUST_DIED);
    }

    // Remove aurastates only if were not found
    if (!auraStateFound)
        ModifyAuraState(auraState, false);

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
    for (AuraApplicationMap::iterator iter = m_appliedAuras.lower_bound(spellId); iter != m_appliedAuras.upper_bound(spellId);)
    {
        if (iter->second == aurApp)
        {
            _UnapplyAura(iter, removeMode);
            return;
        }
        else
            ++iter;
    }
    ASSERT(false);
}

void Unit::_RemoveNoStackAuraApplicationsDueToAura(Aura * aura)
{
    // dynobj auras can stack infinite number of times
    if (aura->GetType() == DYNOBJ_AURA_TYPE)
        return;

    SpellEntry const* spellProto = aura->GetSpellProto();

    uint32 spellId = spellProto->Id;

    // passive spell special case (only non stackable with ranks)
    if (IsPassiveSpell(spellId) && IsPassiveSpellStackableWithRanks(spellProto))
        return;

    bool remove = false;
    for (AuraApplicationMap::iterator i = m_appliedAuras.begin(); i != m_appliedAuras.end(); ++i)
    {
        if (remove)
        {
            remove = false;
            i = m_appliedAuras.begin();
        }

        if (!_IsNoStackAuraDueToAura(aura, i->second->GetBase()))
            continue;

        RemoveAura(i, AURA_REMOVE_BY_DEFAULT);
        if (i == m_appliedAuras.end())
            break;
        remove = true;
    }
}

void Unit::_RemoveNoStackAurasDueToAura(Aura * aura)
{
    SpellEntry const* spellProto = aura->GetSpellProto();

    uint32 spellId = spellProto->Id;

    // passive spell special case (only non stackable with ranks)
    if (IsPassiveSpell(spellId) && IsPassiveSpellStackableWithRanks(spellProto))
        return;

    bool remove = false;
    for (AuraMap::iterator i = m_ownedAuras.begin(); i != m_ownedAuras.end(); ++i)
    {
        if (remove)
        {
            remove = false;
            i = m_ownedAuras.begin();
        }

        if (!_IsNoStackAuraDueToAura(aura, i->second))
            continue;

        RemoveOwnedAura(i, AURA_REMOVE_BY_DEFAULT);
        if (i == m_ownedAuras.end())
            break;
        remove = true;
    }
}

bool Unit::_IsNoStackAuraDueToAura(Aura * appliedAura, Aura * existingAura) const
{
    SpellEntry const* spellProto = appliedAura->GetSpellProto();
    // Do not check already applied aura
    if (existingAura == appliedAura)
        return false;

    // Do not check dynobj auras for stacking
    if (existingAura->GetType() != UNIT_AURA_TYPE)
        return false;

    SpellEntry const* i_spellProto = existingAura->GetSpellProto();
    uint32 i_spellId = i_spellProto->Id;
    bool sameCaster = appliedAura->GetCasterGUID() == existingAura->GetCasterGUID();

    if (IsPassiveSpell(i_spellId))
    {
        // passive non-stackable spells not stackable only for same caster
        if (!sameCaster)
            return false;

        // passive non-stackable spells not stackable only with another rank of same spell
        if (!sSpellMgr->IsRankSpellDueToSpell(spellProto, i_spellId))
            return false;
    }

    bool is_triggered_by_spell = false;
    // prevent triggering aura of removing aura that triggered it
    // prevent triggered aura of removing aura that triggering it (triggered effect early some aura of parent spell
    for (uint8 j = 0; j < MAX_SPELL_EFFECTS; ++j)
    {
        if (i_spellProto->EffectTriggerSpell[j] == spellProto->Id
            || spellProto->EffectTriggerSpell[j] == i_spellProto->Id) // I do not know what is this for
        {
            is_triggered_by_spell = true;
            break;
        }
    }

    if (is_triggered_by_spell)
        return false;

    if (sSpellMgr->CanAurasStack(appliedAura, existingAura, sameCaster))
        return false;
    return true;
}

void Unit::_RegisterAuraEffect(AuraEffect * aurEff, bool apply)
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

void Unit::RemoveOwnedAura(uint32 spellId, uint64 caster, uint8 reqEffMask, AuraRemoveMode removeMode)
{
    for (AuraMap::iterator itr = m_ownedAuras.lower_bound(spellId); itr != m_ownedAuras.upper_bound(spellId);)
        if (((itr->second->GetEffectMask() & reqEffMask) == reqEffMask) && (!caster || itr->second->GetCasterGUID() == caster))
        {
            RemoveOwnedAura(itr, removeMode);
            itr = m_ownedAuras.lower_bound(spellId);
        }
        else
            ++itr;
}

void Unit::RemoveOwnedAura(Aura * aura, AuraRemoveMode removeMode)
{
    if (aura->IsRemoved())
        return;

    ASSERT(aura->GetOwner() == this);

    uint32 spellId = aura->GetId();
    for (AuraMap::iterator itr = m_ownedAuras.lower_bound(spellId); itr != m_ownedAuras.upper_bound(spellId); ++itr)
        if (itr->second == aura)
        {
            RemoveOwnedAura(itr, removeMode);
            return;
        }
    ASSERT(false);
}

Aura * Unit::GetOwnedAura(uint32 spellId, uint64 casterGUID, uint64 itemCasterGUID, uint8 reqEffMask, Aura* except) const
{
    for (AuraMap::const_iterator itr = m_ownedAuras.lower_bound(spellId); itr != m_ownedAuras.upper_bound(spellId); ++itr)
        if (((itr->second->GetEffectMask() & reqEffMask) == reqEffMask) && (!casterGUID || itr->second->GetCasterGUID() == casterGUID) && (!itemCasterGUID || itr->second->GetCastItemGUID() == itemCasterGUID) && (!except || except != itr->second))
            return itr->second;
    return NULL;
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

void Unit::RemoveAura(uint32 spellId, uint64 caster, uint8 reqEffMask, AuraRemoveMode removeMode)
{
    for (AuraApplicationMap::iterator iter = m_appliedAuras.lower_bound(spellId); iter != m_appliedAuras.upper_bound(spellId);)
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
        for (uint8 itr = 0 ; itr < MAX_SPELL_EFFECTS; ++itr)
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
    for (AuraApplicationMap::iterator iter = m_appliedAuras.lower_bound(spellId); iter != m_appliedAuras.upper_bound(spellId);)
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

void Unit::RemoveAura(Aura * aura, AuraRemoveMode mode)
{
    if (aura->IsRemoved())
        return;
    if (AuraApplication * aurApp = aura->GetApplicationOfTarget(GetGUID()))
        RemoveAura(aurApp, mode);
}

void Unit::RemoveAurasDueToSpell(uint32 spellId, uint64 caster, uint8 reqEffMask, AuraRemoveMode removeMode)
{
    for (AuraApplicationMap::iterator iter = m_appliedAuras.lower_bound(spellId); iter != m_appliedAuras.upper_bound(spellId);)
    {
        Aura const* aura = iter->second->GetBase();
        if (((aura->GetEffectMask() & reqEffMask) == reqEffMask)
            && (!caster || aura->GetCasterGUID() == caster))
        {
            RemoveAura(iter, removeMode);
            iter = m_appliedAuras.lower_bound(spellId);
        }
        else
            ++iter;
    }
}

void Unit::RemoveAuraFromStack(uint32 spellId, uint64 caster, AuraRemoveMode removeMode)
{
    for (AuraMap::iterator iter = m_ownedAuras.lower_bound(spellId); iter != m_ownedAuras.upper_bound(spellId);)
    {
        Aura* aura = iter->second;
        if ((aura->GetType() == UNIT_AURA_TYPE)
            && (!caster || aura->GetCasterGUID() == caster))
        {
            aura->ModStackAmount(-1,removeMode);
            return;
        }
        else
            ++iter;
    }
}

void Unit::RemoveAurasDueToSpellByDispel(uint32 spellId, uint64 casterGUID, Unit* dispeller, uint8 chargesRemoved/*= 1*/)
{
    for (AuraMap::iterator iter = m_ownedAuras.lower_bound(spellId); iter != m_ownedAuras.upper_bound(spellId);)
    {
        Aura* aura = iter->second;
        if (aura->GetCasterGUID() == casterGUID)
        {
            if (aura->GetSpellProto()->AttributesEx7 & SPELL_ATTR7_DISPEL_CHARGES)
                aura->ModCharges(-chargesRemoved, AURA_REMOVE_BY_ENEMY_SPELL);
            else
                aura->ModStackAmount(-chargesRemoved, AURA_REMOVE_BY_ENEMY_SPELL);

            switch (aura->GetSpellProto()->SpellFamilyName)
            {
                case SPELLFAMILY_WARLOCK:
                {
                    // Unstable Affliction (crash if before removeaura?)
                    if (aura->GetSpellProto()->SpellFamilyFlags[1] & 0x0100)
                    {
                        if (AuraEffect const* aurEff = aura->GetEffect(EFFECT_0))
                        {
                            int32 damage = aurEff->GetAmount() * 9;
                            // backfire damage and silence
                            dispeller->CastCustomSpell(dispeller, 31117, &damage, NULL, NULL, true, NULL, NULL, aura->GetCasterGUID());
                        }
                    }
                    break;
                }
                case SPELLFAMILY_DRUID:
                {
                    // Lifebloom
                    if (aura->GetSpellProto()->SpellFamilyFlags[1] & 0x10)
                    {
                        if (AuraEffect const* aurEff = aura->GetEffect(EFFECT_1))
                        {
                            // final heal
                            int32 healAmount = aurEff->GetAmount();
                            int32 stack = chargesRemoved;
                            CastCustomSpell(this, 33778, &healAmount, &stack, NULL, true, NULL, NULL, aura->GetCasterGUID());

                            // mana
                            if (Unit* caster = aura->GetCaster())
                            {
                                int32 mana = CalculatePctU(caster->GetCreateMana(), aura->GetSpellProto()->ManaCostPercentage) * chargesRemoved / 2;
                                caster->CastCustomSpell(caster, 64372, &mana, NULL, NULL, true, NULL, NULL, aura->GetCasterGUID());
                            }
                        }
                    }
                    break;
                }
                case SPELLFAMILY_SHAMAN:
                {
                    // Flame Shock
                    if (aura->GetSpellProto()->SpellFamilyFlags[0] & 0x10000000)
                    {
                        if (Unit* caster = aura->GetCaster())
                        {
                            uint32 triggeredSpellId = 0;
                            // Lava Flows
                            if (AuraEffect const* aurEff = caster->GetDummyAuraEffect(SPELLFAMILY_SHAMAN, 3087, 0))
                            {
                                switch (aurEff->GetId())
                                {
                                    case 51482: // Rank 3
                                        triggeredSpellId = 65264;
                                        break;
                                    case 51481: // Rank 2
                                        triggeredSpellId = 65263;
                                        break;
                                    case 51480: // Rank 1
                                        triggeredSpellId = 64694;
                                        break;
                                    default:
                                        sLog->outError("Unit::RemoveAurasDueToSpellByDispel: Unknown rank of Lava Flows (%d) found", aurEff->GetId());
                                }
                            }

                            if (triggeredSpellId)
                                caster->CastSpell(caster, triggeredSpellId, true);
                        }
                    }
                    break;
                }
                default:
                    break;
            }
            return;
        }
        else
            ++iter;
    }
}

void Unit::RemoveAurasDueToSpellBySteal(uint32 spellId, uint64 casterGUID, Unit *stealer)
{
    for (AuraMap::iterator iter = m_ownedAuras.lower_bound(spellId); iter != m_ownedAuras.upper_bound(spellId);)
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

            bool stealCharge = aura->GetSpellProto()->AttributesEx7 & SPELL_ATTR7_DISPEL_CHARGES;
            int32 dur = std::min(2 * MINUTE * IN_MILLISECONDS, aura->GetDuration());

            if (Aura* newAura = stealer->GetAura(aura->GetId(), aura->GetCasterGUID()))
            {
                if (stealCharge)
                    newAura->ModCharges(1);
                else
                    newAura->ModStackAmount(1);
                newAura->SetDuration(dur);
            }
            else
            {
                // single target state must be removed before aura creation to preserve existing single target aura
                if (aura->IsSingleTarget())
                    aura->UnregisterSingleTarget();

                if (newAura = Aura::TryRefreshStackOrCreate(aura->GetSpellProto(), effMask, stealer, NULL, &baseDamage[0], NULL, aura->GetCasterGUID()))
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
                    newAura->SetLoadedState(aura->GetMaxDuration(), dur, stealCharge ? 1 : aura->GetCharges(), 1, recalculateMask, &damage[0]);
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

void Unit::RemoveAurasDueToItemSpell(Item* castItem, uint32 spellId)
{
    for (AuraApplicationMap::iterator iter = m_appliedAuras.lower_bound(spellId); iter != m_appliedAuras.upper_bound(spellId);)
    {
        if (!castItem || iter->second->GetBase()->GetCastItemGUID() == castItem->GetGUID())
        {
            RemoveAura(iter);
            iter = m_appliedAuras.upper_bound(spellId);          // overwrite by more appropriate
        }
        else
            ++iter;
    }
}

void Unit::RemoveAurasByType(AuraType auraType, uint64 casterGUID, Aura * except, bool negative, bool positive)
{
    for (AuraEffectList::iterator iter = m_modAuras[auraType].begin(); iter != m_modAuras[auraType].end();)
    {
        Aura* aura = (*iter)->GetBase();
        AuraApplication * aurApp = aura->GetApplicationOfTarget(GetGUID());

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
        SpellEntry const* spell = iter->second->GetBase()->GetSpellProto();
        if (spell->Attributes & flags)
            RemoveAura(iter);
        else
            ++iter;
    }
}

void Unit::RemoveNotOwnSingleTargetAuras(uint32 newPhase)
{
    // single target auras from other casters
    for (AuraApplicationMap::iterator iter = m_appliedAuras.begin(); iter != m_appliedAuras.end();)
    {
        AuraApplication const* aurApp = iter->second;
        Aura const* aura = aurApp->GetBase();

        if (aura->GetCasterGUID() != GetGUID() && IsSingleTargetSpell(aura->GetSpellProto()))
        {
            if (!newPhase)
                RemoveAura(iter);
            else
            {
                Unit* caster = aura->GetCaster();
                if (!caster || !caster->InSamePhase(newPhase))
                    RemoveAura(iter);
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
        if ((aura->GetSpellProto()->AuraInterruptFlags & flag) && (!except || aura->GetId() != except))
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

void Unit::RemoveAurasWithFamily(SpellFamilyNames family, uint32 familyFlag1, uint32 familyFlag2, uint32 familyFlag3, uint64 casterGUID)
{
    for (AuraApplicationMap::iterator iter = m_appliedAuras.begin(); iter != m_appliedAuras.end();)
    {
        Aura const* aura = iter->second->GetBase();
        if (!casterGUID || aura->GetCasterGUID() == casterGUID)
        {
            SpellEntry const* spell = aura->GetSpellProto();
            if (spell->SpellFamilyName == uint32(family) && spell->SpellFamilyFlags.HasFlag(familyFlag1, familyFlag2, familyFlag3))
            {
                RemoveAura(iter);
                continue;
            }
        }
        ++iter;
    }
}

void Unit::RemoveMovementImpairingAuras()
{
    RemoveAurasWithMechanic((1<<MECHANIC_SNARE)|(1<<MECHANIC_ROOT));
}

void Unit::RemoveAurasWithMechanic(uint32 mechanic_mask, AuraRemoveMode removemode, uint32 except)
{
    for (AuraApplicationMap::iterator iter = m_appliedAuras.begin(); iter != m_appliedAuras.end();)
    {
        Aura const* aura = iter->second->GetBase();
        if (!except || aura->GetId() != except)
        {
            if (GetAllSpellMechanicMask(aura->GetSpellProto()) & mechanic_mask)
            {
                RemoveAura(iter, removemode);
                continue;
            }
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
    for (AuraApplicationMap::iterator iter = m_appliedAuras.begin(); iter != m_appliedAuras.end();)
    {
        AuraApplication const* aurApp = iter->second;
        Aura const* aura = aurApp->GetBase();
        if (!(aura->GetSpellProto()->AttributesEx4 & SPELL_ATTR4_UNK21) // don't remove stances, shadowform, pally/hunter auras
            && !aura->IsPassive()                               // don't remove passive auras
            && (aurApp->IsPositive() || !(aura->GetSpellProto()->AttributesEx3 & SPELL_ATTR3_DEATH_PERSISTENT))) // not negative death persistent auras
            RemoveAura(iter);
        else
            ++iter;
    }
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
        if (!aura->IsPassive() && IsRequiringDeadTargetSpell(aura->GetSpellProto()))
            _UnapplyAura(iter, AURA_REMOVE_BY_DEFAULT);
        else
            ++iter;
    }

    for (AuraMap::iterator iter = m_ownedAuras.begin(); iter != m_ownedAuras.end();)
    {
        Aura* aura = iter->second;
        if (!aura->IsPassive() && IsRequiringDeadTargetSpell(aura->GetSpellProto()))
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
        if (!IsSpellHaveAura(aura->GetSpellProto(), type))
            _UnapplyAura(iter, AURA_REMOVE_BY_DEFAULT);
        else
            ++iter;
    }

    for (AuraMap::iterator iter = m_ownedAuras.begin(); iter != m_ownedAuras.end();)
    {
        Aura* aura = iter->second;
        if (!IsSpellHaveAura(aura->GetSpellProto(), type))
            RemoveOwnedAura(iter, AURA_REMOVE_BY_DEFAULT);
        else
            ++iter;
    }
}

void Unit::DelayOwnedAuras(uint32 spellId, uint64 caster, int32 delaytime)
{
    for (AuraMap::iterator iter = m_ownedAuras.lower_bound(spellId); iter != m_ownedAuras.upper_bound(spellId);++iter)
    {
        Aura* aura = iter->second;
        if (!caster || aura->GetCasterGUID() == caster)
        {
            if (aura->GetDuration() < delaytime)
                aura->SetDuration(0);
            else
                aura->SetDuration(aura->GetDuration() - delaytime);

            // update for out of range group members (on 1 slot use)
            aura->SetNeedClientUpdateForTargets();
            sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "Aura %u partially interrupted on unit %u, new duration: %u ms", aura->GetId() , GetGUIDLow(), aura->GetDuration());
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

AuraEffect * Unit::GetAuraEffect(uint32 spellId, uint8 effIndex, uint64 caster) const
{
    for (AuraApplicationMap::const_iterator itr = m_appliedAuras.lower_bound(spellId); itr != m_appliedAuras.upper_bound(spellId); ++itr)
        if (itr->second->HasEffect(effIndex) && (!caster || itr->second->GetBase()->GetCasterGUID() == caster))
            return itr->second->GetBase()->GetEffect(effIndex);
    return NULL;
}

AuraEffect * Unit::GetAuraEffectOfRankedSpell(uint32 spellId, uint8 effIndex, uint64 caster) const
{
    uint32 rankSpell = sSpellMgr->GetFirstSpellInChain(spellId);
    while (true)
    {
        if (AuraEffect* aurEff = GetAuraEffect(rankSpell, effIndex, caster))
            return aurEff;
        SpellChainNode const* chainNode = sSpellMgr->GetSpellChainNode(rankSpell);
        if (!chainNode)
            break;
        else
            rankSpell = chainNode->next;
    }
    return NULL;
}

AuraEffect* Unit::GetAuraEffect(AuraType type, SpellFamilyNames name, uint32 iconId, uint8 effIndex) const
{
    AuraEffectList const& auras = GetAuraEffectsByType(type);
    for (Unit::AuraEffectList::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
    {
        if (effIndex != (*itr)->GetEffIndex())
            continue;
        SpellEntry const* spell = (*itr)->GetSpellProto();
        if (spell->SpellIconID == iconId && spell->SpellFamilyName == uint32(name) && !spell->SpellFamilyFlags)
            return *itr;
    }
    return NULL;
}

AuraEffect* Unit::GetAuraEffect(AuraType type, SpellFamilyNames family, uint32 familyFlag1, uint32 familyFlag2, uint32 familyFlag3, uint64 casterGUID)
{
    AuraEffectList const& auras = GetAuraEffectsByType(type);
    for (AuraEffectList::const_iterator i = auras.begin(); i != auras.end(); ++i)
    {
        SpellEntry const* spell = (*i)->GetSpellProto();
        if (spell->SpellFamilyName == uint32(family) && spell->SpellFamilyFlags.HasFlag(familyFlag1, familyFlag2, familyFlag3))
        {
            if (casterGUID && (*i)->GetCasterGUID() != casterGUID)
                continue;
            return (*i);
        }
    }
    return NULL;
}

AuraApplication * Unit::GetAuraApplication(uint32 spellId, uint64 casterGUID, uint64 itemCasterGUID, uint8 reqEffMask, AuraApplication * except) const
{
    for (AuraApplicationMap::const_iterator itr = m_appliedAuras.lower_bound(spellId); itr != m_appliedAuras.upper_bound(spellId); ++itr)
    {
        Aura const* aura = itr->second->GetBase();
        if (((aura->GetEffectMask() & reqEffMask) == reqEffMask) && (!casterGUID || aura->GetCasterGUID() == casterGUID) && (!itemCasterGUID || aura->GetCastItemGUID() == itemCasterGUID) && (!except || except != itr->second))
            return itr->second;
    }
    return NULL;
}

Aura * Unit::GetAura(uint32 spellId, uint64 casterGUID, uint64 itemCasterGUID, uint8 reqEffMask) const
{
    AuraApplication * aurApp = GetAuraApplication(spellId, casterGUID, itemCasterGUID, reqEffMask);
    return aurApp ? aurApp->GetBase() : NULL;
}

AuraApplication * Unit::GetAuraApplicationOfRankedSpell(uint32 spellId, uint64 casterGUID, uint64 itemCasterGUID, uint8 reqEffMask, AuraApplication* except) const
{
    uint32 rankSpell = sSpellMgr->GetFirstSpellInChain(spellId);
    while (true)
    {
        if (AuraApplication * aurApp = GetAuraApplication(rankSpell, casterGUID, itemCasterGUID, reqEffMask, except))
            return aurApp;
        SpellChainNode const* chainNode = sSpellMgr->GetSpellChainNode(rankSpell);
        if (!chainNode)
            break;
        else
            rankSpell = chainNode->next;
    }
    return NULL;
}

Aura * Unit::GetAuraOfRankedSpell(uint32 spellId, uint64 casterGUID, uint64 itemCasterGUID, uint8 reqEffMask) const
{
    AuraApplication * aurApp = GetAuraApplicationOfRankedSpell(spellId, casterGUID, itemCasterGUID, reqEffMask);
    return aurApp ? aurApp->GetBase() : NULL;
}

bool Unit::HasAuraEffect(uint32 spellId, uint8 effIndex, uint64 caster) const
{
    for (AuraApplicationMap::const_iterator itr = m_appliedAuras.lower_bound(spellId); itr != m_appliedAuras.upper_bound(spellId); ++itr)
        if (itr->second->HasEffect(effIndex) && (!caster || itr->second->GetBase()->GetCasterGUID() == caster))
            return true;
    return false;
}

uint32 Unit::GetAuraCount(uint32 spellId) const
{
    uint32 count = 0;
    for (AuraApplicationMap::const_iterator itr = m_appliedAuras.lower_bound(spellId); itr != m_appliedAuras.upper_bound(spellId); ++itr)
    {
        if (!itr->second->GetBase()->GetStackAmount())
            count++;
        else
            count += (uint32)itr->second->GetBase()->GetStackAmount();
    }
    return count;
}

bool Unit::HasAura(uint32 spellId, uint64 casterGUID, uint64 itemCasterGUID, uint8 reqEffMask) const
{
    if (GetAuraApplication(spellId, casterGUID, itemCasterGUID, reqEffMask))
        return true;
    return false;
}

bool Unit::HasAuraType(AuraType auraType) const
{
    return (!m_modAuras[auraType].empty());
}

bool Unit::HasAuraTypeWithCaster(AuraType auratype, uint64 caster) const
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

bool Unit::HasAuraTypeWithAffectMask(AuraType auratype, SpellEntry const* affectedSpell) const
{
    AuraEffectList const& mTotalAuraList = GetAuraEffectsByType(auratype);
    for (AuraEffectList::const_iterator i = mTotalAuraList.begin(); i != mTotalAuraList.end(); ++i)
        if ((*i)->IsAffectedOnSpell(affectedSpell))
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

bool Unit::HasNegativeAuraWithInterruptFlag(uint32 flag, uint64 guid)
{
    if (!(m_interruptMask & flag))
        return false;
    for (AuraApplicationList::iterator iter = m_interruptableAuras.begin(); iter != m_interruptableAuras.end(); ++iter)
    {
        if (!(*iter)->IsPositive() && (*iter)->GetBase()->GetSpellProto()->AuraInterruptFlags & flag && (!guid || (*iter)->GetBase()->GetCasterGUID() == guid))
            return true;
    }
    return false;
}

bool Unit::HasNegativeAuraWithAttribute(uint32 flag, uint64 guid)
{
    for (AuraApplicationMap::iterator iter = m_appliedAuras.begin(); iter != m_appliedAuras.end(); ++iter)
    {
        Aura const* aura = iter->second->GetBase();
        if (!iter->second->IsPositive() && aura->GetSpellProto()->Attributes & flag && (!guid || aura->GetCasterGUID() == guid))
            return true;
    }
    return false;
}

bool Unit::HasAuraWithMechanic(uint32 mechanicMask)
{
    for (AuraApplicationMap::iterator iter = m_appliedAuras.begin(); iter != m_appliedAuras.end(); ++iter)
    {
        SpellEntry const* spellInfo  = iter->second->GetBase()->GetSpellProto();
        if (spellInfo->Mechanic && (mechanicMask & (1 << spellInfo->Mechanic)))
            return true;

        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
            if (iter->second->HasEffect(i) && spellInfo->Effect[i] && spellInfo->EffectMechanic[i])
                if (mechanicMask & (1 << spellInfo->EffectMechanic[i]))
                    return true;
    }

    return false;
}

AuraEffect * Unit::IsScriptOverriden(SpellEntry const* spell, int32 script) const
{
    AuraEffectList const& auras = GetAuraEffectsByType(SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
    for (AuraEffectList::const_iterator i = auras.begin(); i != auras.end(); ++i)
    {
        if ((*i)->GetMiscValue() == script)
            if ((*i)->IsAffectedOnSpell(spell))
                return (*i);
    }
    return NULL;
}

uint32 Unit::GetDiseasesByCaster(uint64 casterGUID, bool remove)
{
    static const AuraType diseaseAuraTypes[] =
    {
        SPELL_AURA_PERIODIC_DAMAGE, // Frost Fever and Blood Plague
        SPELL_AURA_LINKED,          // Crypt Fever and Ebon Plague
        SPELL_AURA_NONE
    };

    uint32 diseases = 0;
    for (AuraType const* itr = &diseaseAuraTypes[0]; itr && itr[0] != SPELL_AURA_NONE; ++itr)
    {
        for (AuraEffectList::iterator i = m_modAuras[*itr].begin(); i != m_modAuras[*itr].end();)
        {
            // Get auras with disease dispel type by caster
            if ((*i)->GetSpellProto()->Dispel == DISPEL_DISEASE
                && (*i)->GetCasterGUID() == casterGUID)
            {
                ++diseases;

                if (remove)
                {
                    RemoveAura((*i)->GetId(), (*i)->GetCasterGUID());
                    i = m_modAuras[*itr].begin();
                    continue;
                }
            }
            ++i;
        }
    }
    return diseases;
}

uint32 Unit::GetDoTsByCaster(uint64 casterGUID) const
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

int32 Unit::GetTotalAuraModifier(AuraType auratype) const
{
    int32 modifier = 0;

    AuraEffectList const& mTotalAuraList = GetAuraEffectsByType(auratype);
    for (AuraEffectList::const_iterator i = mTotalAuraList.begin(); i != mTotalAuraList.end(); ++i)
        modifier += (*i)->GetAmount();

    return modifier;
}

float Unit::GetTotalAuraMultiplier(AuraType auratype) const
{
    float multiplier = 1.0f;

    AuraEffectList const& mTotalAuraList = GetAuraEffectsByType(auratype);
    for (AuraEffectList::const_iterator i = mTotalAuraList.begin(); i != mTotalAuraList.end(); ++i)
        AddPctN(multiplier, (*i)->GetAmount());

    return multiplier;
}

int32 Unit::GetMaxPositiveAuraModifier(AuraType auratype)
{
    int32 modifier = 0;

    AuraEffectList const& mTotalAuraList = GetAuraEffectsByType(auratype);
    for (AuraEffectList::const_iterator i = mTotalAuraList.begin(); i != mTotalAuraList.end(); ++i)
    {
        if ((*i)->GetAmount() > modifier)
            modifier = (*i)->GetAmount();
    }

    return modifier;
}

int32 Unit::GetMaxNegativeAuraModifier(AuraType auratype) const
{
    int32 modifier = 0;

    AuraEffectList const& mTotalAuraList = GetAuraEffectsByType(auratype);
    for (AuraEffectList::const_iterator i = mTotalAuraList.begin(); i != mTotalAuraList.end(); ++i)
        if ((*i)->GetAmount() < modifier)
            modifier = (*i)->GetAmount();

    return modifier;
}

int32 Unit::GetTotalAuraModifierByMiscMask(AuraType auratype, uint32 misc_mask) const
{
    int32 modifier = 0;

    AuraEffectList const& mTotalAuraList = GetAuraEffectsByType(auratype);
    for (AuraEffectList::const_iterator i = mTotalAuraList.begin(); i != mTotalAuraList.end(); ++i)
    {
        if ((*i)->GetMiscValue()& misc_mask)
            modifier += (*i)->GetAmount();
    }
    return modifier;
}

float Unit::GetTotalAuraMultiplierByMiscMask(AuraType auratype, uint32 misc_mask) const
{
    float multiplier = 1.0f;

    AuraEffectList const& mTotalAuraList = GetAuraEffectsByType(auratype);
    for (AuraEffectList::const_iterator i = mTotalAuraList.begin(); i != mTotalAuraList.end(); ++i)
    {
        if ((*i)->GetMiscValue()& misc_mask)
            AddPctN(multiplier, (*i)->GetAmount());
    }
    return multiplier;
}

int32 Unit::GetMaxPositiveAuraModifierByMiscMask(AuraType auratype, uint32 misc_mask, const AuraEffect* except) const
{
    int32 modifier = 0;

    AuraEffectList const& mTotalAuraList = GetAuraEffectsByType(auratype);
    for (AuraEffectList::const_iterator i = mTotalAuraList.begin(); i != mTotalAuraList.end(); ++i)
    {
        if (except != (*i) && (*i)->GetMiscValue()& misc_mask && (*i)->GetAmount() > modifier)
            modifier = (*i)->GetAmount();
    }

    return modifier;
}

int32 Unit::GetMaxNegativeAuraModifierByMiscMask(AuraType auratype, uint32 misc_mask) const
{
    int32 modifier = 0;

    AuraEffectList const& mTotalAuraList = GetAuraEffectsByType(auratype);
    for (AuraEffectList::const_iterator i = mTotalAuraList.begin(); i != mTotalAuraList.end(); ++i)
    {
        if ((*i)->GetMiscValue()& misc_mask && (*i)->GetAmount() < modifier)
            modifier = (*i)->GetAmount();
    }

    return modifier;
}

int32 Unit::GetTotalAuraModifierByMiscValue(AuraType auratype, int32 misc_value) const
{
    int32 modifier = 0;

    AuraEffectList const& mTotalAuraList = GetAuraEffectsByType(auratype);
    for (AuraEffectList::const_iterator i = mTotalAuraList.begin(); i != mTotalAuraList.end(); ++i)
    {
        if ((*i)->GetMiscValue() == misc_value)
            modifier += (*i)->GetAmount();
    }
    return modifier;
}

float Unit::GetTotalAuraMultiplierByMiscValue(AuraType auratype, int32 misc_value) const
{
    float multiplier = 1.0f;

    AuraEffectList const& mTotalAuraList = GetAuraEffectsByType(auratype);
    for (AuraEffectList::const_iterator i = mTotalAuraList.begin(); i != mTotalAuraList.end(); ++i)
    {
        if ((*i)->GetMiscValue() == misc_value)
            AddPctN(multiplier, (*i)->GetAmount());
    }
    return multiplier;
}

int32 Unit::GetMaxPositiveAuraModifierByMiscValue(AuraType auratype, int32 misc_value) const
{
    int32 modifier = 0;

    AuraEffectList const& mTotalAuraList = GetAuraEffectsByType(auratype);
    for (AuraEffectList::const_iterator i = mTotalAuraList.begin(); i != mTotalAuraList.end(); ++i)
    {
        if ((*i)->GetMiscValue() == misc_value && (*i)->GetAmount() > modifier)
            modifier = (*i)->GetAmount();
    }

    return modifier;
}

int32 Unit::GetMaxNegativeAuraModifierByMiscValue(AuraType auratype, int32 misc_value) const
{
    int32 modifier = 0;

    AuraEffectList const& mTotalAuraList = GetAuraEffectsByType(auratype);
    for (AuraEffectList::const_iterator i = mTotalAuraList.begin(); i != mTotalAuraList.end(); ++i)
    {
        if ((*i)->GetMiscValue() == misc_value && (*i)->GetAmount() < modifier)
            modifier = (*i)->GetAmount();
    }

    return modifier;
}

int32 Unit::GetTotalAuraModifierByAffectMask(AuraType auratype, SpellEntry const* affectedSpell) const
{
    int32 modifier = 0;

    AuraEffectList const& mTotalAuraList = GetAuraEffectsByType(auratype);
    for (AuraEffectList::const_iterator i = mTotalAuraList.begin(); i != mTotalAuraList.end(); ++i)
    {
        if ((*i)->IsAffectedOnSpell(affectedSpell))
            modifier += (*i)->GetAmount();
    }
    return modifier;
}

float Unit::GetTotalAuraMultiplierByAffectMask(AuraType auratype, SpellEntry const* affectedSpell) const
{
    float multiplier = 1.0f;

    AuraEffectList const& mTotalAuraList = GetAuraEffectsByType(auratype);
    for (AuraEffectList::const_iterator i = mTotalAuraList.begin(); i != mTotalAuraList.end(); ++i)
    {
        if ((*i)->IsAffectedOnSpell(affectedSpell))
            AddPctN(multiplier, (*i)->GetAmount());
    }
    return multiplier;
}

int32 Unit::GetMaxPositiveAuraModifierByAffectMask(AuraType auratype, SpellEntry const* affectedSpell) const
{
    int32 modifier = 0;

    AuraEffectList const& mTotalAuraList = GetAuraEffectsByType(auratype);
    for (AuraEffectList::const_iterator i = mTotalAuraList.begin(); i != mTotalAuraList.end(); ++i)
    {
        if ((*i)->IsAffectedOnSpell(affectedSpell) && (*i)->GetAmount() > modifier)
            modifier = (*i)->GetAmount();
    }

    return modifier;
}

int32 Unit::GetMaxNegativeAuraModifierByAffectMask(AuraType auratype, SpellEntry const* affectedSpell) const
{
    int32 modifier = 0;

    AuraEffectList const& mTotalAuraList = GetAuraEffectsByType(auratype);
    for (AuraEffectList::const_iterator i = mTotalAuraList.begin(); i != mTotalAuraList.end(); ++i)
    {
        if ((*i)->IsAffectedOnSpell(affectedSpell) && (*i)->GetAmount() < modifier)
            modifier = (*i)->GetAmount();
    }

    return modifier;
}

void Unit::_RegisterDynObject(DynamicObject* dynObj)
{
    m_dynObj.push_back(dynObj);
}

void Unit::_UnregisterDynObject(DynamicObject* dynObj)
{
    m_dynObj.remove(dynObj);
}

DynamicObject * Unit::GetDynObject(uint32 spellId)
{
    if (m_dynObj.empty())
        return NULL;
    for (DynObjectList::const_iterator i = m_dynObj.begin(); i != m_dynObj.end();++i)
    {
        DynamicObject* dynObj = *i;
        if (dynObj->GetSpellId() == spellId)
            return dynObj;
    }
    return NULL;
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
    for (GameObjectList::const_iterator i = m_gameObj.begin(); i != m_gameObj.end(); ++i)
        if ((*i)->GetSpellId() == spellId)
            return *i;

    return NULL;
}

void Unit::AddGameObject(GameObject* gameObj)
{
    if (!gameObj || !gameObj->GetOwnerGUID() == 0) return;
    m_gameObj.push_back(gameObj);
    gameObj->SetOwnerGUID(GetGUID());

    if (GetTypeId() == TYPEID_PLAYER && gameObj->GetSpellId())
    {
        SpellEntry const* createBySpell = sSpellStore.LookupEntry(gameObj->GetSpellId());
        // Need disable spell use for owner
        if (createBySpell && createBySpell->Attributes & SPELL_ATTR0_DISABLED_WHILE_ACTIVE)
            // note: item based cooldowns and cooldown spell mods with charges ignored (unknown existed cases)
            ToPlayer()->AddSpellAndCategoryCooldowns(createBySpell, 0, NULL, true);
    }
}

void Unit::RemoveGameObject(GameObject* gameObj, bool del)
{
    if (!gameObj || !gameObj->GetOwnerGUID() == GetGUID()) return;

    gameObj->SetOwnerGUID(0);

    for (uint32 i = 0; i < 4; ++i)
    {
        if (m_ObjectSlot[i] == gameObj->GetGUID())
        {
            m_ObjectSlot[i] = 0;
            break;
        }
    }

    // GO created by some spell
    if (uint32 spellid = gameObj->GetSpellId())
    {
        RemoveAurasDueToSpell(spellid);

        if (GetTypeId() == TYPEID_PLAYER)
        {
            SpellEntry const* createBySpell = sSpellStore.LookupEntry(spellid);
            // Need activate spell use for owner
            if (createBySpell && createBySpell->Attributes & SPELL_ATTR0_DISABLED_WHILE_ACTIVE)
                // note: item based cooldowns and cooldown spell mods with charges ignored (unknown existed cases)
                ToPlayer()->SendCooldownEvent(createBySpell);
        }
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
            (*i)->SetOwnerGUID(0);
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
    for (GameObjectList::iterator i = m_gameObj.begin(); i != m_gameObj.end();)
    {
        (*i)->SetOwnerGUID(0);
        (*i)->SetRespawnTime(0);
        (*i)->Delete();
        i = m_gameObj.erase(i);
    }
}

void Unit::SendSpellNonMeleeDamageLog(SpellNonMeleeDamage *log)
{
    WorldPacket data(SMSG_SPELLNONMELEEDAMAGELOG, (16+4+4+4+1+4+4+1+1+4+4+1)); // we guess size
    data.append(log->target->GetPackGUID());
    data.append(log->attacker->GetPackGUID());
    data << uint32(log->SpellID);
    data << uint32(log->damage);                            // damage amount
    int32 overkill = log->damage - log->target->GetHealth();
    data << uint32(overkill > 0 ? overkill : 0);            // overkill
    data << uint8 (log->schoolMask);                        // damage school
    data << uint32(log->absorb);                            // AbsorbedDamage
    data << uint32(log->resist);                            // resist
    data << uint8 (log->physicalLog);                       // if 1, then client show spell name (example: %s's ranged shot hit %s for %u school or %s suffers %u school damage from %s's spell_name
    data << uint8 (log->unused);                            // unused
    data << uint32(log->blocked);                           // blocked
    data << uint32(log->HitInfo);
    data << uint8 (0);                                      // flag to use extend data
    SendMessageToSet(&data, true);
}

void Unit::SendSpellNonMeleeDamageLog(Unit* target, uint32 SpellID, uint32 Damage, SpellSchoolMask damageSchoolMask, uint32 AbsorbedDamage, uint32 Resist, bool PhysicalDamage, uint32 Blocked, bool CriticalHit)
{
    SpellNonMeleeDamage log(this, target, SpellID, damageSchoolMask);
    log.damage = Damage - AbsorbedDamage - Resist - Blocked;
    log.absorb = AbsorbedDamage;
    log.resist = Resist;
    log.physicalLog = PhysicalDamage;
    log.blocked = Blocked;
    log.HitInfo = SPELL_HIT_TYPE_UNK1 | SPELL_HIT_TYPE_UNK3 | SPELL_HIT_TYPE_UNK6;
    if (CriticalHit)
        log.HitInfo |= SPELL_HIT_TYPE_CRIT;
    SendSpellNonMeleeDamageLog(&log);
}

void Unit::ProcDamageAndSpell(Unit *pVictim, uint32 procAttacker, uint32 procVictim, uint32 procExtra, uint32 amount, WeaponAttackType attType, SpellEntry const *procSpell, SpellEntry const* procAura)
{
     // Not much to do if no flags are set.
    if (procAttacker)
        ProcDamageAndSpellFor(false, pVictim, procAttacker, procExtra, attType, procSpell, amount, procAura);
    // Now go on with a victim's events'n'auras
    // Not much to do if no flags are set or there is no victim
    if (pVictim && pVictim->isAlive() && procVictim)
        pVictim->ProcDamageAndSpellFor(true, this, procVictim, procExtra, attType, procSpell, amount, procAura);
}

void Unit::SendPeriodicAuraLog(SpellPeriodicAuraLogInfo *pInfo)
{
    AuraEffect const* aura = pInfo->auraEff;

    WorldPacket data(SMSG_PERIODICAURALOG, 30);
    data.append(GetPackGUID());
    data.appendPackGUID(aura->GetCasterGUID());
    data << uint32(aura->GetId());                          // spellId
    data << uint32(1);                                      // count
    data << uint32(aura->GetAuraType());                    // auraId
    switch(aura->GetAuraType())
    {
        case SPELL_AURA_PERIODIC_DAMAGE:
        case SPELL_AURA_PERIODIC_DAMAGE_PERCENT:
            data << uint32(pInfo->damage);                  // damage
            data << uint32(pInfo->overDamage);              // overkill?
            data << uint32(GetSpellSchoolMask(aura->GetSpellProto()));
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
            sLog->outError("Unit::SendPeriodicAuraLog: unknown aura %u", uint32(aura->GetAuraType()));
            return;
    }

    SendMessageToSet(&data, true);
}

void Unit::SendSpellMiss(Unit* target, uint32 spellID, SpellMissInfo missInfo)
{
    WorldPacket data(SMSG_SPELLLOGMISS, (4+8+1+4+8+1));
    data << uint32(spellID);
    data << uint64(GetGUID());
    data << uint8(0);                                       // can be 0 or 1
    data << uint32(1);                                      // target count
    // for (i = 0; i < target count; ++i)
    data << uint64(target->GetGUID());                      // target GUID
    data << uint8(missInfo);
    // end loop
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

void Unit::SendAttackStateUpdate(CalcDamageInfo *damageInfo)
{
    sLog->outDebug(LOG_FILTER_UNITS, "WORLD: Sending SMSG_ATTACKERSTATEUPDATE");

    uint32 count = 1;
    size_t maxsize = 4+5+5+4+4+1+4+4+4+4+4+1+4+4+4+4+4*12;
    WorldPacket data(SMSG_ATTACKERSTATEUPDATE, maxsize);    // we guess size
    data << uint32(damageInfo->HitInfo);
    data.append(damageInfo->attacker->GetPackGUID());
    data.append(damageInfo->target->GetPackGUID());
    data << uint32(damageInfo->damage);                     // Full damage
    int32 overkill = damageInfo->damage - damageInfo->target->GetHealth();
    data << uint32(overkill < 0 ? 0 : overkill);            // Overkill
    data << uint8(count);                                   // Sub damage count

    for (uint32 i = 0; i < count; ++i)
    {
        data << uint32(damageInfo->damageSchoolMask);       // School of sub damage
        data << float(damageInfo->damage);                  // sub damage
        data << uint32(damageInfo->damage);                 // Sub Damage
    }

    if (damageInfo->HitInfo & (HITINFO_ABSORB | HITINFO_ABSORB2))
    {
        for (uint32 i = 0; i < count; ++i)
            data << uint32(damageInfo->absorb);             // Absorb
    }

    if (damageInfo->HitInfo & (HITINFO_RESIST | HITINFO_RESIST2))
    {
        for (uint32 i = 0; i < count; ++i)
            data << uint32(damageInfo->resist);             // Resist
    }

    data << uint8(damageInfo->TargetState);
    data << uint32(0);
    data << uint32(0);

    if (damageInfo->HitInfo & HITINFO_BLOCK)
        data << uint32(damageInfo->blocked_amount);

    if (damageInfo->HitInfo & HITINFO_UNK3)
        data << uint32(0);

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
    dmgInfo.attacker = this;
    dmgInfo.target = target;
    dmgInfo.damage = Damage - AbsorbDamage - Resist - BlockedAmount;
    dmgInfo.damageSchoolMask = damageSchoolMask;
    dmgInfo.absorb = AbsorbDamage;
    dmgInfo.resist = Resist;
    dmgInfo.TargetState = TargetState;
    dmgInfo.blocked_amount = BlockedAmount;
    SendAttackStateUpdate(&dmgInfo);
}

bool Unit::HandleHasteAuraProc(Unit *pVictim, uint32 damage, AuraEffect* triggeredByAura, SpellEntry const* /*procSpell*/, uint32 /*procFlag*/, uint32 /*procEx*/, uint32 cooldown)
{
    SpellEntry const* hasteSpell = triggeredByAura->GetSpellProto();

    Item* castItem = triggeredByAura->GetBase()->GetCastItemGUID() && GetTypeId() == TYPEID_PLAYER
        ? ToPlayer()->GetItemByGuid(triggeredByAura->GetBase()->GetCastItemGUID()) : NULL;

    uint32 triggered_spell_id = 0;
    Unit* target = pVictim;
    int32 basepoints0 = 0;

    switch(hasteSpell->SpellFamilyName)
    {
        case SPELLFAMILY_ROGUE:
        {
            switch(hasteSpell->Id)
            {
                // Blade Flurry
                case 13877:
                case 33735:
                {
                    target = SelectNearbyTarget();
                    if (!target || target == pVictim)
                        return false;
                    basepoints0 = damage;
                    triggered_spell_id = 22482;
                    break;
                }
            }
            break;
        }
    }

    // processed charge only counting case
    if (!triggered_spell_id)
        return true;

    SpellEntry const* triggerEntry = sSpellStore.LookupEntry(triggered_spell_id);

    if (!triggerEntry)
    {
        sLog->outError("Unit::HandleHasteAuraProc: Spell %u have not existed triggered spell %u", hasteSpell->Id, triggered_spell_id);
        return false;
    }

    // default case
    if ((!target && !sSpellMgr->IsSrcTargetSpell(triggerEntry)) || (target && target != this && !target->isAlive()))
        return false;

    if (cooldown && GetTypeId() == TYPEID_PLAYER && ToPlayer()->HasSpellCooldown(triggered_spell_id))
        return false;

    if (basepoints0)
        CastCustomSpell(target, triggered_spell_id, &basepoints0, NULL, NULL, true, castItem, triggeredByAura);
    else
        CastSpell(target, triggered_spell_id, true, castItem, triggeredByAura);

    if (cooldown && GetTypeId() == TYPEID_PLAYER)
        ToPlayer()->AddSpellCooldown(triggered_spell_id, 0, time(NULL) + cooldown);

    return true;
}

bool Unit::HandleSpellCritChanceAuraProc(Unit *pVictim, uint32 /*damage*/, AuraEffect* triggeredByAura, SpellEntry const* /*procSpell*/, uint32 /*procFlag*/, uint32 /*procEx*/, uint32 cooldown)
{
    SpellEntry const* triggeredByAuraSpell = triggeredByAura->GetSpellProto();

    Item* castItem = triggeredByAura->GetBase()->GetCastItemGUID() && GetTypeId() == TYPEID_PLAYER
        ? ToPlayer()->GetItemByGuid(triggeredByAura->GetBase()->GetCastItemGUID()) : NULL;

    uint32 triggered_spell_id = 0;
    Unit* target = pVictim;
    int32 basepoints0 = 0;

    switch(triggeredByAuraSpell->SpellFamilyName)
    {
        case SPELLFAMILY_MAGE:
        {
            switch(triggeredByAuraSpell->Id)
            {
                // Focus Magic
                case 54646:
                {
                    Unit* caster = triggeredByAura->GetCaster();
                    if (!caster)
                        return false;

                    triggered_spell_id = 54648;
                    target = caster;
                    break;
                }
            }
        }
    }

    // processed charge only counting case
    if (!triggered_spell_id)
        return true;

    SpellEntry const* triggerEntry = sSpellStore.LookupEntry(triggered_spell_id);

    if (!triggerEntry)
    {
        sLog->outError("Unit::HandleHasteAuraProc: Spell %u have not existed triggered spell %u", triggeredByAuraSpell->Id, triggered_spell_id);
        return false;
    }

    // default case
    if (!target || (target != this && !target->isAlive()))
        return false;

    if (cooldown && GetTypeId() == TYPEID_PLAYER && ToPlayer()->HasSpellCooldown(triggered_spell_id))
        return false;

    if (basepoints0)
        CastCustomSpell(target, triggered_spell_id, &basepoints0, NULL, NULL, true, castItem, triggeredByAura);
    else
        CastSpell(target, triggered_spell_id, true, castItem, triggeredByAura);

    if (cooldown && GetTypeId() == TYPEID_PLAYER)
        ToPlayer()->AddSpellCooldown(triggered_spell_id, 0, time(NULL) + cooldown);

    return true;
}

bool Unit::HandleDummyAuraProc(Unit *pVictim, uint32 damage, AuraEffect* triggeredByAura, SpellEntry const* procSpell, uint32 procFlag, uint32 procEx, uint32 cooldown)
{
    SpellEntry const* dummySpell = triggeredByAura->GetSpellProto();
    uint32 effIndex = triggeredByAura->GetEffIndex();
    int32  triggerAmount = triggeredByAura->GetAmount();

    Item* castItem = triggeredByAura->GetBase()->GetCastItemGUID() && GetTypeId() == TYPEID_PLAYER
        ? ToPlayer()->GetItemByGuid(triggeredByAura->GetBase()->GetCastItemGUID()) : NULL;

    uint32 triggered_spell_id = 0;
    uint32 cooldown_spell_id = 0; // for random trigger, will be one of the triggered spell to avoid repeatable triggers
                                  // otherwise, it's the triggered_spell_id by default
    Unit* target = pVictim;
    int32 basepoints0 = 0;
    uint64 originalCaster = 0;

    switch(dummySpell->SpellFamilyName)
    {
        case SPELLFAMILY_GENERIC:
        {
            switch (dummySpell->Id)
            {
                // Bloodworms Health Leech
                case 50453:
                {
                    if (Unit* owner = GetOwner())
                    {
                        basepoints0 = int32(damage*1.50);
                        target = owner;
                        triggered_spell_id = 50454;
                        break;
                    }
                    return false;
                }
                // Eye for an Eye
                case 9799:
                case 25988:
                {
                    // return damage % to attacker but < 50% own total health
                    basepoints0 = int32(std::min(CalculatePctN(damage, triggerAmount), CountPctFromMaxHealth(50)));
                    triggered_spell_id = 25997;
                    break;
                }
                // Sweeping Strikes
                case 18765:
                case 35429:
                {
                    target = SelectNearbyTarget();
                    if (!target)
                        return false;

                    triggered_spell_id = 26654;
                    break;
                }
                // Unstable Power
                case 24658:
                {
                    if (!procSpell || procSpell->Id == 24659)
                        return false;
                    // Need remove one 24659 aura
                    RemoveAuraFromStack(24659);
                    return true;
                }
                // Restless Strength
                case 24661:
                {
                    // Need remove one 24662 aura
                    RemoveAuraFromStack(24662);
                    return true;
                }
                // Adaptive Warding (Frostfire Regalia set)
                case 28764:
                {
                    if (!procSpell)
                        return false;

                    // find Mage Armor
                    if (!GetAuraEffect(SPELL_AURA_MOD_MANA_REGEN_INTERRUPT, SPELLFAMILY_MAGE, 0x10000000, 0, 0))
                        return false;

                    switch(GetFirstSchoolInMask(GetSpellSchoolMask(procSpell)))
                    {
                        case SPELL_SCHOOL_NORMAL:
                        case SPELL_SCHOOL_HOLY:
                            return false;                   // ignored
                        case SPELL_SCHOOL_FIRE:   triggered_spell_id = 28765; break;
                        case SPELL_SCHOOL_NATURE: triggered_spell_id = 28768; break;
                        case SPELL_SCHOOL_FROST:  triggered_spell_id = 28766; break;
                        case SPELL_SCHOOL_SHADOW: triggered_spell_id = 28769; break;
                        case SPELL_SCHOOL_ARCANE: triggered_spell_id = 28770; break;
                        default:
                            return false;
                    }

                    target = this;
                    break;
                }
                // Obsidian Armor (Justice Bearer`s Pauldrons shoulder)
                case 27539:
                {
                    if (!procSpell)
                        return false;

                    switch(GetFirstSchoolInMask(GetSpellSchoolMask(procSpell)))
                    {
                        case SPELL_SCHOOL_NORMAL:
                            return false;                   // ignore
                        case SPELL_SCHOOL_HOLY:   triggered_spell_id = 27536; break;
                        case SPELL_SCHOOL_FIRE:   triggered_spell_id = 27533; break;
                        case SPELL_SCHOOL_NATURE: triggered_spell_id = 27538; break;
                        case SPELL_SCHOOL_FROST:  triggered_spell_id = 27534; break;
                        case SPELL_SCHOOL_SHADOW: triggered_spell_id = 27535; break;
                        case SPELL_SCHOOL_ARCANE: triggered_spell_id = 27540; break;
                        default:
                            return false;
                    }

                    target = this;
                    break;
                }
                // Mana Leech (Passive) (Priest Pet Aura)
                case 28305:
                {
                    // Cast on owner
                    target = GetOwner();
                    if (!target)
                        return false;

                    triggered_spell_id = 34650;
                    break;
                }
                // Mark of Malice
                case 33493:
                {
                    // Cast finish spell at last charge
                    if (triggeredByAura->GetBase()->GetCharges() > 1)
                        return false;

                    target = this;
                    triggered_spell_id = 33494;
                    break;
                }
                // Twisted Reflection (boss spell)
                case 21063:
                    triggered_spell_id = 21064;
                    break;
                // Vampiric Aura (boss spell)
                case 38196:
                {
                    basepoints0 = 3 * damage;               // 300%
                    if (basepoints0 < 0)
                        return false;

                    triggered_spell_id = 31285;
                    target = this;
                    break;
                }
                // Aura of Madness (Darkmoon Card: Madness trinket)
                //=====================================================
                // 39511 Sociopath: +35 strength (Paladin, Rogue, Druid, Warrior)
                // 40997 Delusional: +70 attack power (Rogue, Hunter, Paladin, Warrior, Druid)
                // 40998 Kleptomania: +35 agility (Warrior, Rogue, Paladin, Hunter, Druid)
                // 40999 Megalomania: +41 damage/healing (Druid, Shaman, Priest, Warlock, Mage, Paladin)
                // 41002 Paranoia: +35 spell/melee/ranged crit strike rating (All classes)
                // 41005 Manic: +35 haste (spell, melee and ranged) (All classes)
                // 41009 Narcissism: +35 intellect (Druid, Shaman, Priest, Warlock, Mage, Paladin, Hunter)
                // 41011 Martyr Complex: +35 stamina (All classes)
                // 41406 Dementia: Every 5 seconds either gives you +5% damage/healing. (Druid, Shaman, Priest, Warlock, Mage, Paladin)
                // 41409 Dementia: Every 5 seconds either gives you -5% damage/healing. (Druid, Shaman, Priest, Warlock, Mage, Paladin)
                case 39446:
                {
                    if (GetTypeId() != TYPEID_PLAYER || !isAlive())
                        return false;

                    // Select class defined buff
                    switch (getClass())
                    {
                        case CLASS_PALADIN:                 // 39511, 40997, 40998, 40999, 41002, 41005, 41009, 41011, 41409
                        case CLASS_DRUID:                   // 39511, 40997, 40998, 40999, 41002, 41005, 41009, 41011, 41409
                            triggered_spell_id = RAND(39511, 40997, 40998, 40999, 41002, 41005, 41009, 41011, 41409);
                            cooldown_spell_id = 39511;
                            break;
                        case CLASS_ROGUE:                   // 39511, 40997, 40998, 41002, 41005, 41011
                        case CLASS_WARRIOR:                 // 39511, 40997, 40998, 41002, 41005, 41011
                            triggered_spell_id = RAND(39511, 40997, 40998, 41002, 41005, 41011);
                            cooldown_spell_id = 39511;
                            break;
                        case CLASS_PRIEST:                  // 40999, 41002, 41005, 41009, 41011, 41406, 41409
                        case CLASS_SHAMAN:                  // 40999, 41002, 41005, 41009, 41011, 41406, 41409
                        case CLASS_MAGE:                    // 40999, 41002, 41005, 41009, 41011, 41406, 41409
                        case CLASS_WARLOCK:                 // 40999, 41002, 41005, 41009, 41011, 41406, 41409
                            triggered_spell_id = RAND(40999, 41002, 41005, 41009, 41011, 41406, 41409);
                            cooldown_spell_id = 40999;
                            break;
                        case CLASS_HUNTER:                  // 40997, 40999, 41002, 41005, 41009, 41011, 41406, 41409
                            triggered_spell_id = RAND(40997, 40999, 41002, 41005, 41009, 41011, 41406, 41409);
                            cooldown_spell_id = 40997;
                            break;
                        default:
                            return false;
                    }

                    target = this;
                    if (roll_chance_i(10))
                        ToPlayer()->Say("This is Madness!", LANG_UNIVERSAL); // TODO: It should be moved to database, shouldn't it?
                    break;
                }
                // Sunwell Exalted Caster Neck (??? neck)
                // cast ??? Light's Wrath if Exalted by Aldor
                // cast ??? Arcane Bolt if Exalted by Scryers
                case 46569:
                    return false;                           // old unused version
                // Sunwell Exalted Caster Neck (Shattered Sun Pendant of Acumen neck)
                // cast 45479 Light's Wrath if Exalted by Aldor
                // cast 45429 Arcane Bolt if Exalted by Scryers
                case 45481:
                {
                    if (GetTypeId() != TYPEID_PLAYER)
                        return false;

                    // Get Aldor reputation rank
                    if (ToPlayer()->GetReputationRank(932) == REP_EXALTED)
                    {
                        target = this;
                        triggered_spell_id = 45479;
                        break;
                    }
                    // Get Scryers reputation rank
                    if (ToPlayer()->GetReputationRank(934) == REP_EXALTED)
                    {
                        // triggered at positive/self casts also, current attack target used then
                        if (IsFriendlyTo(target))
                        {
                            target = getVictim();
                            if (!target)
                            {
                                uint64 selected_guid = ToPlayer()->GetSelection();
                                target = ObjectAccessor::GetUnit(*this, selected_guid);
                                if (!target)
                                    return false;
                            }
                            if (IsFriendlyTo(target))
                                return false;
                        }

                        triggered_spell_id = 45429;
                        break;
                    }
                    return false;
                }
                // Sunwell Exalted Melee Neck (Shattered Sun Pendant of Might neck)
                // cast 45480 Light's Strength if Exalted by Aldor
                // cast 45428 Arcane Strike if Exalted by Scryers
                case 45482:
                {
                    if (GetTypeId() != TYPEID_PLAYER)
                        return false;

                    // Get Aldor reputation rank
                    if (ToPlayer()->GetReputationRank(932) == REP_EXALTED)
                    {
                        target = this;
                        triggered_spell_id = 45480;
                        break;
                    }
                    // Get Scryers reputation rank
                    if (ToPlayer()->GetReputationRank(934) == REP_EXALTED)
                    {
                        triggered_spell_id = 45428;
                        break;
                    }
                    return false;
                }
                // Sunwell Exalted Tank Neck (Shattered Sun Pendant of Resolve neck)
                // cast 45431 Arcane Insight if Exalted by Aldor
                // cast 45432 Light's Ward if Exalted by Scryers
                case 45483:
                {
                    if (GetTypeId() != TYPEID_PLAYER)
                        return false;

                    // Get Aldor reputation rank
                    if (ToPlayer()->GetReputationRank(932) == REP_EXALTED)
                    {
                        target = this;
                        triggered_spell_id = 45432;
                        break;
                    }
                    // Get Scryers reputation rank
                    if (ToPlayer()->GetReputationRank(934) == REP_EXALTED)
                    {
                        target = this;
                        triggered_spell_id = 45431;
                        break;
                    }
                    return false;
                }
                // Sunwell Exalted Healer Neck (Shattered Sun Pendant of Restoration neck)
                // cast 45478 Light's Salvation if Exalted by Aldor
                // cast 45430 Arcane Surge if Exalted by Scryers
                case 45484:
                {
                    if (GetTypeId() != TYPEID_PLAYER)
                        return false;

                    // Get Aldor reputation rank
                    if (ToPlayer()->GetReputationRank(932) == REP_EXALTED)
                    {
                        target = this;
                        triggered_spell_id = 45478;
                        break;
                    }
                    // Get Scryers reputation rank
                    if (ToPlayer()->GetReputationRank(934) == REP_EXALTED)
                    {
                        triggered_spell_id = 45430;
                        break;
                    }
                    return false;
                }
                // Living Seed
                case 48504:
                {
                    triggered_spell_id = 48503;
                    basepoints0 = triggerAmount;
                    target = this;
                    break;
                }
                // Kill command
                case 58914:
                {
                    // Remove aura stack from pet
                    RemoveAuraFromStack(58914);
                    Unit* owner = GetOwner();
                    if (!owner)
                        return true;
                    // reduce the owner's aura stack
                    owner->RemoveAuraFromStack(34027);
                    return true;
                }
                // Vampiric Touch (generic, used by some boss)
                case 52723:
                case 60501:
                {
                    triggered_spell_id = 52724;
                    basepoints0 = damage / 2;
                    target = this;
                    break;
                }
                // Shadowfiend Death (Gain mana if pet dies with Glyph of Shadowfiend)
                case 57989:
                {
                    Unit* owner = GetOwner();
                    if (!owner || owner->GetTypeId() != TYPEID_PLAYER)
                        return false;
                    // Glyph of Shadowfiend (need cast as self cast for owner, no hidden cooldown)
                    owner->CastSpell(owner, 58227, true, castItem, triggeredByAura);
                    return true;
                }
                // Divine purpose
                case 31871:
                case 31872:
                {
                    // Roll chane
                    if (!pVictim || !pVictim->isAlive() || !roll_chance_i(triggerAmount))
                        return false;

                    // Remove any stun effect on target
                    pVictim->RemoveAurasWithMechanic(1<<MECHANIC_STUN, AURA_REMOVE_BY_ENEMY_SPELL);
                    return true;
                }
                // Glyph of Life Tap
                case 63320:
                {
                    triggered_spell_id = 63321; // Life Tap
                    break;
                }
                // Purified Shard of the Scale - Onyxia 10 Caster Trinket
                case 69755:
                {
                    triggered_spell_id = (procFlag & PROC_FLAG_DONE_SPELL_MAGIC_DMG_CLASS_POS) ? 69733 : 69729;
                    break;
                }
                // Shiny Shard of the Scale - Onyxia 25 Caster Trinket
                case 69739:
                {
                    triggered_spell_id = (procFlag & PROC_FLAG_DONE_SPELL_MAGIC_DMG_CLASS_POS) ? 69734 : 69730;
                    break;
                }
                case 71519: // Deathbringer's Will Normal
                {
                    if (GetTypeId() != TYPEID_PLAYER)
                        return false;

                    std::vector<uint32> RandomSpells;
                    switch (getClass())
                    {
                        case CLASS_WARRIOR:
                        case CLASS_PALADIN:
                        case CLASS_DEATH_KNIGHT:
                            RandomSpells.push_back(71484);
                            RandomSpells.push_back(71491);
                            RandomSpells.push_back(71492);
                            break;
                        case CLASS_SHAMAN:
                        case CLASS_ROGUE:
                            RandomSpells.push_back(71486);
                            RandomSpells.push_back(71485);
                            RandomSpells.push_back(71492);
                            break;
                        case CLASS_DRUID:
                            RandomSpells.push_back(71484);
                            RandomSpells.push_back(71485);
                            RandomSpells.push_back(71486);
                            break;
                        case CLASS_HUNTER:
                            RandomSpells.push_back(71486);
                            RandomSpells.push_back(71491);
                            RandomSpells.push_back(71485);
                            break;
                        default:
                            return false;
                    }
                    if (RandomSpells.empty()) // shouldn't happen
                        return false;

                    uint8 rand_spell = irand(0, (RandomSpells.size() - 1));
                    CastSpell(target, RandomSpells[rand_spell], true, castItem, triggeredByAura, originalCaster);
                    for (std::vector<uint32>::iterator itr = RandomSpells.begin(); itr != RandomSpells.end(); ++itr)
                    {
                        if (!ToPlayer()->HasSpellCooldown(*itr))
                            ToPlayer()->AddSpellCooldown(*itr, 0, time(NULL) + cooldown);
                    }
                    break;
                }
                case 71562: // Deathbringer's Will Heroic
                {
                    if (GetTypeId() != TYPEID_PLAYER)
                        return false;

                    std::vector<uint32> RandomSpells;
                    switch (getClass())
                    {
                        case CLASS_WARRIOR:
                        case CLASS_PALADIN:
                        case CLASS_DEATH_KNIGHT:
                            RandomSpells.push_back(71561);
                            RandomSpells.push_back(71559);
                            RandomSpells.push_back(71560);
                            break;
                        case CLASS_SHAMAN:
                        case CLASS_ROGUE:
                            RandomSpells.push_back(71558);
                            RandomSpells.push_back(71556);
                            RandomSpells.push_back(71560);
                            break;
                        case CLASS_DRUID:
                            RandomSpells.push_back(71561);
                            RandomSpells.push_back(71556);
                            RandomSpells.push_back(71558);
                            break;
                        case CLASS_HUNTER:
                            RandomSpells.push_back(71558);
                            RandomSpells.push_back(71559);
                            RandomSpells.push_back(71556);
                            break;
                        default:
                            return false;
                    }
                    if (RandomSpells.empty()) // shouldn't happen
                        return false;

                    uint8 rand_spell = irand(0, (RandomSpells.size() - 1));
                    CastSpell(target, RandomSpells[rand_spell], true, castItem, triggeredByAura, originalCaster);
                    for (std::vector<uint32>::iterator itr = RandomSpells.begin(); itr != RandomSpells.end(); ++itr)
                    {
                        if (!ToPlayer()->HasSpellCooldown(*itr))
                            ToPlayer()->AddSpellCooldown(*itr, 0, time(NULL) + cooldown);
                    }
                    break;
                }
                // Item - Shadowmourne Legendary
                case 71903:
                {
                    if (!pVictim || !pVictim->isAlive() || HasAura(73422))  // cant collect shards while under effect of Chaos Bane buff
                        return false;

                    CastSpell(this, 71905, true, NULL, triggeredByAura);

                    // this can't be handled in AuraScript because we need to know pVictim
                    Aura const* dummy = GetAura(71905);
                    if (!dummy || dummy->GetStackAmount() < 10)
                        return false;

                    RemoveAurasDueToSpell(71905);
                    triggered_spell_id = 71904;
                    target = pVictim;
                    break;
                }
                // Shadow's Fate (Shadowmourne questline)
                case 71169:
                {
                    target = triggeredByAura->GetCaster();
                    if (!target)
                        return false;
                    Player* player = target->ToPlayer();
                    if (!player)
                        return false;
                    // not checking Infusion auras because its in targetAuraSpell of credit spell
                    if (player->GetQuestStatus(24749) == QUEST_STATUS_INCOMPLETE)       // Unholy Infusion
                    {
                        if (GetEntry() != 36678)                                        // Professor Putricide
                            return false;
                        CastSpell(target, 71518, true);                                 // Quest Credit
                        return true;
                    }
                    else if (player->GetQuestStatus(24756) == QUEST_STATUS_INCOMPLETE)  // Blood Infusion
                    {
                        if (GetEntry() != 37955)                                        // Blood-Queen Lana'thel
                            return false;
                        CastSpell(target, 72934, true);                                 // Quest Credit
                        return true;
                    }
                    else if (player->GetQuestStatus(24757) == QUEST_STATUS_INCOMPLETE)  // Frost Infusion
                    {
                        if (GetEntry() != 36853)                                        // Sindragosa
                            return false;
                        CastSpell(target, 72289, true);                                 // Quest Credit
                        return true;
                    }
                    else if (player->GetQuestStatus(24547) == QUEST_STATUS_INCOMPLETE)  // A Feast of Souls
                        triggered_spell_id = 71203;
                    break;
                }
                // Gaseous Bloat (Professor Putricide add)
                case 70215:
                case 72858:
                case 72859:
                case 72860:
                {
                    target = getVictim();
                    triggered_spell_id = 70701;
                    break;
                }
                case 70871:
                {
                    target = this;
                    triggered_spell_id = 70872;
                    basepoints0 = CalculatePctN(int32(damage), triggerAmount);
                    break;
                }
                case 65032: // Boom aura (321 Boombot)
                {
                    if (pVictim->GetEntry() != 33343)   // Scrapbot
                        return false;

                    InstanceScript* instance = GetInstanceScript();
                    if (!instance)
                        return false;

                    instance->DoCastSpellOnPlayers(65037);  // Achievement criteria marker
                    break;
                }
            }
            break;
        }
        case SPELLFAMILY_MAGE:
        {
            // Magic Absorption
            if (dummySpell->SpellIconID == 459)             // only this spell have SpellIconID == 459 and dummy aura
            {
                if (getPowerType() != POWER_MANA)
                    return false;

                // mana reward
                basepoints0 = CalculatePctN(int32(GetMaxPower(POWER_MANA)), triggerAmount);
                target = this;
                triggered_spell_id = 29442;
                break;
            }
            // Master of Elements
            if (dummySpell->SpellIconID == 1920)
            {
                if (!procSpell)
                    return false;

                // mana cost save
                int32 cost = int32(procSpell->manaCost + CalculatePctU(GetCreateMana(), procSpell->ManaCostPercentage));
                basepoints0 = CalculatePctN(cost, triggerAmount);
                if (basepoints0 <= 0)
                    return false;

                target = this;
                triggered_spell_id = 29077;
                break;
            }
            // Arcane Potency
            if (dummySpell->SpellIconID == 2120)
            {
                if (!procSpell)
                    return false;

                target = this;
                switch (dummySpell->Id)
                {
                    case 31571: triggered_spell_id = 57529; break;
                    case 31572: triggered_spell_id = 57531; break;
                    default:
                        sLog->outError("Unit::HandleDummyAuraProc: non handled spell id: %u", dummySpell->Id);
                        return false;
                }
                break;
            }

            // Hot Streak
            if (dummySpell->SpellIconID == 2999)
            {
                if (effIndex != 0)
                    return false;
                AuraEffect* counter = triggeredByAura->GetBase()->GetEffect(EFFECT_1);
                if (!counter)
                    return true;

                // Count spell criticals in a row in second aura
                if (procEx & PROC_EX_CRITICAL_HIT)
                {
                    counter->SetAmount(counter->GetAmount() * 2);
                    if (counter->GetAmount() < 100) // not enough
                        return true;
                    // Crititcal counted -> roll chance
                    if (roll_chance_i(triggerAmount))
                        CastSpell(this, 48108, true, castItem, triggeredByAura);
                }
                counter->SetAmount(25);
                return true;
            }
            // Burnout
            if (dummySpell->SpellIconID == 2998)
            {
                if (!procSpell)
                    return false;

                int32 cost = int32(procSpell->manaCost + CalculatePctU(GetCreateMana(), procSpell->ManaCostPercentage));
                basepoints0 = CalculatePctN(cost, triggerAmount);
                if (basepoints0 <= 0)
                    return false;
                triggered_spell_id = 44450;
                target = this;
                break;
            }
            // Incanter's Regalia set (add trigger chance to Mana Shield)
            if (dummySpell->SpellFamilyFlags[0] & 0x8000)
            {
                if (GetTypeId() != TYPEID_PLAYER)
                    return false;

                target = this;
                triggered_spell_id = 37436;
                break;
            }
            switch(dummySpell->Id)
            {
                // Glyph of Polymorph
                case 56375:
                {
                    target->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE, 0, target->GetAura(32409)); // SW:D shall not be removed.
                    target->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE_PERCENT);
                    target->RemoveAurasByType(SPELL_AURA_PERIODIC_LEECH);
                    return true;
                }
                // Glyph of Icy Veins
                case 56374:
                {
                    RemoveAurasByType(SPELL_AURA_HASTE_SPELLS, 0, 0, true, false);
                    RemoveAurasByType(SPELL_AURA_MOD_DECREASE_SPEED);
                    return true;
                }
                // Ignite
                case 11119:
                case 11120:
                case 12846:
                case 12847:
                case 12848:
                {
                    switch (dummySpell->Id)
                    {
                        case 11119: basepoints0 = int32(0.04f*damage); break;
                        case 11120: basepoints0 = int32(0.08f*damage); break;
                        case 12846: basepoints0 = int32(0.12f*damage); break;
                        case 12847: basepoints0 = int32(0.16f*damage); break;
                        case 12848: basepoints0 = int32(0.20f*damage); break;
                        default:
                            sLog->outError("Unit::HandleDummyAuraProc: non handled spell id: %u (IG)", dummySpell->Id);
                            return false;
                    }

                    triggered_spell_id = 12654;
                    basepoints0 += pVictim->GetRemainingPeriodicAmount(GetGUID(), triggered_spell_id, SPELL_AURA_PERIODIC_DAMAGE);
                    break;
                }
                // Glyph of Ice Block
                case 56372:
                {
                    Player* plr = ToPlayer();
                    if (!plr)
                        return false;

                    SpellCooldowns const cooldowns = plr->GetSpellCooldowns();
                    // remove cooldowns on all ranks of Frost Nova
                    for (SpellCooldowns::const_iterator itr = cooldowns.begin(); itr != cooldowns.end(); ++itr)
                    {
                        SpellEntry const* cdSpell = sSpellStore.LookupEntry(itr->first);
                        // Frost Nova
                        if (cdSpell && cdSpell->SpellFamilyName == SPELLFAMILY_MAGE
                            && cdSpell->SpellFamilyFlags[0] & 0x00000040)
                            plr->RemoveSpellCooldown(cdSpell->Id, true);
                    }
                    break;
                }
                // Blessing of Ancient Kings (Val'anyr, Hammer of Ancient Kings)
                case 64411:
                {
                    basepoints0 = int32(CalculatePctN(damage, 15));
                    if (AuraEffect* aurEff = pVictim->GetAuraEffect(64413, 0, GetGUID()))
                    {
                        // The shield can grow to a maximum size of 20, 000 damage absorbtion
                        aurEff->SetAmount(std::max<int32>(aurEff->GetAmount() + basepoints0, 20000));

                        // Refresh and return to prevent replacing the aura
                        aurEff->GetBase()->RefreshDuration();
                        return true;
                    }
                    target = pVictim;
                    triggered_spell_id = 64413;
                    break;
                }
                case 47020: // Enter vehicle XT-002 (Scrapbot)
                {
                    if (GetTypeId() != TYPEID_UNIT)
                        return false;

                    Unit* vehicleBase = GetVehicleBase();
                    if (!vehicleBase)
                        return false;

                    // Todo: Check if this amount is blizzlike
                    vehicleBase->ModifyHealth(int32(vehicleBase->CountPctFromMaxHealth(1)));
                    break;
                }
            }
            break;
        }
        case SPELLFAMILY_WARRIOR:
        {
            switch(dummySpell->Id)
            {
                // Sweeping Strikes
                case 12328:
                {
                    target = SelectNearbyTarget();
                    if (!target)
                        return false;

                    triggered_spell_id = 26654;
                    break;
                }
                // Victorious
                case 32216:
                {
                    RemoveAura(dummySpell->Id);
                    return false;
                }
                // Improved Spell Reflection
                case 59088:
                case 59089:
                {
                    triggered_spell_id = 59725;
                    target = this;
                    break;
                }
            }

            // Retaliation
            if (dummySpell->SpellFamilyFlags[1] & 0x8)
            {
                // check attack comes not from behind
                if (!HasInArc(M_PI, pVictim))
                    return false;

                triggered_spell_id = 22858;
                break;
            }
            // Second Wind
            if (dummySpell->SpellIconID == 1697)
            {
                // only for spells and hit/crit (trigger start always) and not start from self casted spells (5530 Mace Stun Effect for example)
                if (procSpell == 0 || !(procEx & (PROC_EX_NORMAL_HIT|PROC_EX_CRITICAL_HIT)) || this == pVictim)
                    return false;
                // Need stun or root mechanic
                if (!(GetAllSpellMechanicMask(procSpell) & ((1<<MECHANIC_ROOT)|(1<<MECHANIC_STUN))))
                    return false;

                switch (dummySpell->Id)
                {
                    case 29838: triggered_spell_id=29842; break;
                    case 29834: triggered_spell_id=29841; break;
                    case 42770: triggered_spell_id=42771; break;
                    default:
                        sLog->outError("Unit::HandleDummyAuraProc: non handled spell id: %u (SW)", dummySpell->Id);
                    return false;
                }

                target = this;
                break;
            }
            // Damage Shield
            if (dummySpell->SpellIconID == 3214)
            {
                triggered_spell_id = 59653;
                // % of amount blocked
                basepoints0 = CalculatePctN(int32(GetShieldBlockValue()), triggerAmount);
                break;
            }
            // Glyph of Blocking
            if (dummySpell->Id == 58375)
            {
                triggered_spell_id = 58374;
                break;
            }
            // Glyph of Sunder Armor
            if (dummySpell->Id == 58387)
            {
                if (!pVictim || !pVictim->isAlive() || !procSpell)
                    return false;

                target = SelectNearbyTarget();
                if (!target || target == pVictim)
                    return false;

                CastSpell(target, 58567, true);
                return true;
            }
            break;
        }
        case SPELLFAMILY_WARLOCK:
        {
            // Seed of Corruption
            if (dummySpell->SpellFamilyFlags[1] & 0x00000010)
            {
                if (procSpell && procSpell->SpellFamilyFlags[1] & 0x8000)
                    return false;
                // if damage is more than need or target die from damage deal finish spell
                if (triggeredByAura->GetAmount() <= int32(damage) || GetHealth() <= damage)
                {
                    // remember guid before aura delete
                    uint64 casterGuid = triggeredByAura->GetCasterGUID();

                    // Remove aura (before cast for prevent infinite loop handlers)
                    RemoveAurasDueToSpell(triggeredByAura->GetId());

                    uint32 spell = sSpellMgr->GetSpellWithRank(27285, sSpellMgr->GetSpellRank(dummySpell->Id));

                    // Cast finish spell (triggeredByAura already not exist!)
                    if (Unit* caster = GetUnit(*this, casterGuid))
                        caster->CastSpell(this, spell, true, castItem);
                    return true;                            // no hidden cooldown
                }

                // Damage counting
                triggeredByAura->SetAmount(triggeredByAura->GetAmount() - damage);
                return true;
            }
            // Seed of Corruption (Mobs cast) - no die req
            if (dummySpell->SpellFamilyFlags.IsEqual(0, 0, 0) && dummySpell->SpellIconID == 1932)
            {
                // if damage is more than need deal finish spell
                if (triggeredByAura->GetAmount() <= int32(damage))
                {
                    // remember guid before aura delete
                    uint64 casterGuid = triggeredByAura->GetCasterGUID();

                    // Remove aura (before cast for prevent infinite loop handlers)
                    RemoveAurasDueToSpell(triggeredByAura->GetId());

                    // Cast finish spell (triggeredByAura already not exist!)
                    if (Unit* caster = GetUnit(*this, casterGuid))
                        caster->CastSpell(this, 32865, true, castItem);
                    return true;                            // no hidden cooldown
                }
                // Damage counting
                triggeredByAura->SetAmount(triggeredByAura->GetAmount() - damage);
                return true;
            }
            // Fel Synergy
            if (dummySpell->SpellIconID == 3222)
            {
                target = GetGuardianPet();
                if (!target)
                    return false;
                basepoints0 = CalculatePctN(int32(damage), triggerAmount);
                triggered_spell_id = 54181;
                break;
            }
            switch (dummySpell->Id)
            {
                // Siphon Life
                case 63108:
                {
                    // Glyph of Siphon Life
                    if (HasAura(56216))
                        triggerAmount += triggerAmount / 4;
                    triggered_spell_id = 63106;
                    target = this;
                    basepoints0 = CalculatePctN(int32(damage), triggerAmount);
                    break;
                }
                // Glyph of Shadowflame
                case 63310:
                {
                    triggered_spell_id = 63311;
                    break;
                }
                // Nightfall
                case 18094:
                case 18095:
                // Glyph of corruption
                case 56218:
                {
                    target = this;
                    triggered_spell_id = 17941;
                    break;
                }
                // Soul Leech
                case 30293:
                case 30295:
                case 30296:
                {
                    // Improved Soul Leech
                    AuraEffectList const& SoulLeechAuras = GetAuraEffectsByType(SPELL_AURA_DUMMY);
                    for (Unit::AuraEffectList::const_iterator i = SoulLeechAuras.begin(); i != SoulLeechAuras.end(); ++i)
                    {
                        if ((*i)->GetId() == 54117 || (*i)->GetId() == 54118)
                        {
                            if ((*i)->GetEffIndex() != 0)
                                continue;
                            basepoints0 = int32((*i)->GetAmount());
                            target = GetGuardianPet();
                            if (target)
                            {
                                // regen mana for pet
                                CastCustomSpell(target, 54607, &basepoints0, NULL, NULL, true, castItem, triggeredByAura);
                            }
                            // regen mana for caster
                            CastCustomSpell(this, 59117, &basepoints0, NULL, NULL, true, castItem, triggeredByAura);
                            // Get second aura of spell for replenishment effect on party
                            if (AuraEffect const* aurEff = (*i)->GetBase()->GetEffect(EFFECT_1))
                            {
                                // Replenishment - roll chance
                                if (roll_chance_i(aurEff->GetAmount()))
                                {
                                    CastSpell(this, 57669, true, castItem, triggeredByAura);
                                }
                            }
                            break;
                        }
                    }
                    // health
                    basepoints0 = CalculatePctN(int32(damage), triggerAmount);
                    target = this;
                    triggered_spell_id = 30294;
                    break;
                }
                // Shadowflame (Voidheart Raiment set bonus)
                case 37377:
                {
                    triggered_spell_id = 37379;
                    break;
                }
                // Pet Healing (Corruptor Raiment or Rift Stalker Armor)
                case 37381:
                {
                    target = GetGuardianPet();
                    if (!target)
                        return false;

                    // heal amount
                    basepoints0 = CalculatePctN(int32(damage), triggerAmount);
                    triggered_spell_id = 37382;
                    break;
                }
                // Shadowflame Hellfire (Voidheart Raiment set bonus)
                case 39437:
                {
                    triggered_spell_id = 37378;
                    break;
                }
            }
            break;
        }
        case SPELLFAMILY_PRIEST:
        {
            // Vampiric Touch
            if (dummySpell->SpellFamilyFlags[1] & 0x00000400)
            {
                if (!pVictim || !pVictim->isAlive())
                    return false;

                if (effIndex != 0)
                    return false;

                // pVictim is caster of aura
                if (triggeredByAura->GetCasterGUID() != pVictim->GetGUID())
                    return false;

                // Energize 0.25% of max. mana
                pVictim->CastSpell(pVictim, 57669, true, castItem, triggeredByAura);
                return true;                                // no hidden cooldown
            }
            // Divine Aegis
            if (dummySpell->SpellIconID == 2820)
            {
                // Multiple effects stack, so let's try to find this aura.
                int32 bonus = 0;
                if (AuraEffect const* aurEff = target->GetAuraEffect(47753, 0))
                    bonus = aurEff->GetAmount();

                basepoints0 = CalculatePctN(int32(damage), triggerAmount) + bonus;
                if (basepoints0 > target->getLevel() * 125)
                    basepoints0 = target->getLevel() * 125;

                triggered_spell_id = 47753;
                break;
            }
            // Body and Soul
            if (dummySpell->SpellIconID == 2218)
            {
                // Proc only from Abolish desease on self cast
                if (procSpell->Id != 552 || pVictim != this || !roll_chance_i(triggerAmount))
                    return false;
                triggered_spell_id = 64136;
                target = this;
                break;
            }
            switch (dummySpell->Id)
            {
                // Vampiric Embrace
                case 15286:
                {
                    if (!pVictim || !pVictim->isAlive() || procSpell->SpellFamilyFlags[1] & 0x80000)
                        return false;

                    // heal amount
                    int32 total = CalculatePctN(int32(damage), triggerAmount);
                    int32 team = total / 5;
                    int32 self = total - team;
                    CastCustomSpell(this, 15290, &team, &self, NULL, true, castItem, triggeredByAura);
                    return true;                                // no hidden cooldown
                }
                // Priest Tier 6 Trinket (Ashtongue Talisman of Acumen)
                case 40438:
                {
                    // Shadow Word: Pain
                    if (procSpell->SpellFamilyFlags[0] & 0x8000)
                        triggered_spell_id = 40441;
                    // Renew
                    else if (procSpell->SpellFamilyFlags[0] & 0x40)
                        triggered_spell_id = 40440;
                    else
                        return false;

                    target = this;
                    break;
                }
                // Glyph of Prayer of Healing
                case 55680:
                {
                    triggered_spell_id = 56161;

                    SpellEntry const* GoPoH = sSpellStore.LookupEntry(triggered_spell_id);
                    if (!GoPoH)
                        return false;

                    int EffIndex = 0;
                    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
                    {
                        if (GoPoH->Effect[i] == SPELL_EFFECT_APPLY_AURA)
                        {
                            EffIndex = i;
                            break;
                        }
                    }
                    int32 tickcount = GetSpellMaxDuration(GoPoH) / GoPoH->EffectAmplitude[EffIndex];
                    if (!tickcount)
                        return false;

                    basepoints0 = CalculatePctN(int32(damage), triggerAmount) / tickcount;
                    break;
                }
                // Improved Shadowform
                case 47570:
                case 47569:
                {
                    if (!roll_chance_i(triggerAmount))
                        return false;

                    RemoveMovementImpairingAuras();
                    break;
                }
                // Glyph of Dispel Magic
                case 55677:
                {
                    // Dispel Magic shares spellfamilyflag with abolish disease
                    if (procSpell->SpellIconID != 74)
                        return false;
                    if (!target || !target->IsFriendlyTo(this))
                        return false;

                    basepoints0 = int32(target->CountPctFromMaxHealth(triggerAmount));
                    triggered_spell_id = 56131;
                    break;
                }
                // Oracle Healing Bonus ("Garments of the Oracle" set)
                case 26169:
                {
                    // heal amount
                    basepoints0 = int32(CalculatePctN(damage, 10));
                    target = this;
                    triggered_spell_id = 26170;
                    break;
                }
                // Frozen Shadoweave (Shadow's Embrace set) warning! its not only priest set
                case 39372:
                {
                    if (!procSpell || (GetSpellSchoolMask(procSpell) & (SPELL_SCHOOL_MASK_FROST | SPELL_SCHOOL_MASK_SHADOW)) == 0)
                        return false;

                    // heal amount
                    basepoints0 = CalculatePctN(int32(damage), triggerAmount);
                    target = this;
                    triggered_spell_id = 39373;
                    break;
                }
                // Greater Heal (Vestments of Faith (Priest Tier 3) - 4 pieces bonus)
                case 28809:
                {
                    triggered_spell_id = 28810;
                    break;
                }
                // Priest T10 Healer 2P Bonus
                case 70770:
                    // Flash Heal
                    if (procSpell->SpellFamilyFlags[0] & 0x800)
                    {
                        triggered_spell_id = 70772;
                        SpellEntry const* blessHealing = sSpellStore.LookupEntry(triggered_spell_id);
                        if (!blessHealing)
                            return false;
                        basepoints0 = int32(CalculatePctN(damage, triggerAmount) / (GetSpellMaxDuration(blessHealing) / blessHealing->EffectAmplitude[0]));
                    }
                    break;
            }
            break;
        }
        case SPELLFAMILY_DRUID:
        {
            switch(dummySpell->Id)
            {
                // Glyph of Innervate
                case 54832:
                {
                    if (procSpell->SpellIconID != 62)
                        return false;

                    int32 mana_perc = SpellMgr::CalculateSpellEffectAmount(triggeredByAura->GetSpellProto(), triggeredByAura->GetEffIndex());
                    basepoints0 = int32(CalculatePctN(GetCreatePowers(POWER_MANA), mana_perc) / 10);
                    triggered_spell_id = 54833;
                    target = this;
                    break;
                }
                // Glyph of Starfire
                case 54845:
                {
                    triggered_spell_id = 54846;
                    break;
                }
                // Glyph of Shred
                case 54815:
                {
                    // try to find spell Rip on the target
                    if (AuraEffect const* AurEff = target->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DRUID, 0x00800000, 0x0, 0x0, GetGUID()))
                    {
                        // Rip's max duration, note: spells which modifies Rip's duration also counted like Glyph of Rip
                        uint32 CountMin = AurEff->GetBase()->GetMaxDuration();

                        // just Rip's max duration without other spells
                        uint32 CountMax = GetSpellMaxDuration(AurEff->GetSpellProto());

                        // add possible auras' and Glyph of Shred's max duration
                        CountMax += 3 * triggerAmount * IN_MILLISECONDS;      // Glyph of Shred               -> +6 seconds
                        CountMax += HasAura(54818) ? 4 * IN_MILLISECONDS : 0; // Glyph of Rip                 -> +4 seconds
                        CountMax += HasAura(60141) ? 4 * IN_MILLISECONDS : 0; // Rip Duration/Lacerate Damage -> +4 seconds

                        // if min < max -> that means caster didn't cast 3 shred yet
                        // so set Rip's duration and max duration
                        if (CountMin < CountMax)
                        {
                            AurEff->GetBase()->SetDuration(AurEff->GetBase()->GetDuration() + triggerAmount * IN_MILLISECONDS);
                            AurEff->GetBase()->SetMaxDuration(CountMin + triggerAmount * IN_MILLISECONDS);
                            return true;
                        }
                    }
                    // if not found Rip
                    return false;
                }
                // Glyph of Rake
                case 54821:
                {
                    if (procSpell->SpellVisual[0] == 750 && procSpell->EffectApplyAuraName[1] == 3)
                    {
                        if (target->GetTypeId() == TYPEID_UNIT)
                        {
                            triggered_spell_id = 54820;
                            break;
                        }
                    }
                    return false;
                }
                // Leader of the Pack
                case 24932:
                {
                   if (triggerAmount <= 0)
                        return false;
                    basepoints0 = int32(CountPctFromMaxHealth(triggerAmount));
                    target = this;
                    triggered_spell_id = 34299;
                    if (triggeredByAura->GetCasterGUID() != GetGUID())
                        break;
                    int32 basepoints1 = triggerAmount * 2;
                    // Improved Leader of the Pack
                    // Check cooldown of heal spell cooldown
                    if (GetTypeId() == TYPEID_PLAYER && !ToPlayer()->HasSpellCooldown(34299))
                        CastCustomSpell(this, 60889, &basepoints1, 0, 0, true, 0, triggeredByAura);
                    break;
                }
                // Healing Touch (Dreamwalker Raiment set)
                case 28719:
                {
                    // mana back
                    basepoints0 = int32(CalculatePctN(procSpell->manaCost, 30));
                    target = this;
                    triggered_spell_id = 28742;
                    break;
                }
                // Glyph of Rejuvenation
                case 54754:
                {
                    if (!pVictim || !pVictim->HealthBelowPct(uint32(triggerAmount)))
                        return false;
                    basepoints0 = CalculatePctN(int32(damage), triggerAmount);
                    triggered_spell_id = 54755;
                    break;
                }
                // Healing Touch Refund (Idol of Longevity trinket)
                case 28847:
                {
                    target = this;
                    triggered_spell_id = 28848;
                    break;
                }
                // Mana Restore (Malorne Raiment set / Malorne Regalia set)
                case 37288:
                case 37295:
                {
                    target = this;
                    triggered_spell_id = 37238;
                    break;
                }
                // Druid Tier 6 Trinket
                case 40442:
                {
                    float  chance;

                    // Starfire
                    if (procSpell->SpellFamilyFlags[0] & 0x4)
                    {
                        triggered_spell_id = 40445;
                        chance = 25.0f;
                    }
                    // Rejuvenation
                    else if (procSpell->SpellFamilyFlags[0] & 0x10)
                    {
                        triggered_spell_id = 40446;
                        chance = 25.0f;
                    }
                    // Mangle (Bear) and Mangle (Cat)
                    else if (procSpell->SpellFamilyFlags[1] & 0x00000440)
                    {
                        triggered_spell_id = 40452;
                        chance = 40.0f;
                    }
                    else
                        return false;

                    if (!roll_chance_f(chance))
                        return false;

                    target = this;
                    break;
                }
                // Maim Interrupt
                case 44835:
                {
                    // Deadly Interrupt Effect
                    triggered_spell_id = 32747;
                    break;
                }
                // Item - Druid T10 Balance 4P Bonus
                case 70723:
                {
                    // Wrath & Starfire
                    if ((procSpell->SpellFamilyFlags[0] & 0x5) && (procEx & PROC_EX_CRITICAL_HIT))
                    {
                        triggered_spell_id = 71023;
                        SpellEntry const* triggeredSpell = sSpellStore.LookupEntry(triggered_spell_id);
                        if (!triggeredSpell)
                            return false;
                        basepoints0 = CalculatePctN(int32(damage), triggerAmount) / (GetSpellMaxDuration(triggeredSpell) / triggeredSpell->EffectAmplitude[0]);
                        // Add remaining ticks to damage done
                        basepoints0 += pVictim->GetRemainingPeriodicAmount(GetGUID(), triggered_spell_id, SPELL_AURA_PERIODIC_DAMAGE);
                    }
                    break;
                }
                // Item - Druid T10 Restoration 4P Bonus (Rejuvenation)
                case 70664:
                {
                    // Proc only from normal Rejuvenation
                    if (procSpell->SpellVisual[0] != 32)
                        return false;

                    Player* caster = ToPlayer();
                    if (!caster)
                        return false;
                    if (!caster->GetGroup() && pVictim == this)
                        return false;

                    CastCustomSpell(70691, SPELLVALUE_BASE_POINT0, damage, pVictim, true);
                    return true;
                }
            }
            // Eclipse
            if (dummySpell->SpellIconID == 2856 && GetTypeId() == TYPEID_PLAYER)
            {
                if (!procSpell || effIndex != 0)
                    return false;

                bool isWrathSpell = (procSpell->SpellFamilyFlags[0] & 1);

                if (!roll_chance_f(dummySpell->procChance * (isWrathSpell ? 0.6f : 1.0f)))
                    return false;

                target = this;
                if (target->HasAura(isWrathSpell ? 48517 : 48518))
                    return false;

                triggered_spell_id = isWrathSpell ? 48518 : 48517;
                break;
            }
            // Living Seed
            else if (dummySpell->SpellIconID == 2860)
            {
                triggered_spell_id = 48504;
                basepoints0 = CalculatePctN(int32(damage), triggerAmount);
                break;
            }
            // King of the Jungle
            else if (dummySpell->SpellIconID == 2850)
            {
                // Effect 0 - mod damage while having Enrage
                if (effIndex == 0)
                {
                    if (!(procSpell->SpellFamilyFlags[0] & 0x00080000))
                        return false;
                    triggered_spell_id = 51185;
                    basepoints0 = triggerAmount;
                    target = this;
                    break;
                }
                // Effect 1 - Tiger's Fury restore energy
                else if (effIndex == 1)
                {
                    if (!(procSpell->SpellFamilyFlags[2] & 0x00000800))
                        return false;
                    triggered_spell_id = 51178;
                    basepoints0 = triggerAmount;
                    target = this;
                    break;
                }
            }
            break;
        }
        case SPELLFAMILY_ROGUE:
        {
            switch(dummySpell->Id)
            {
                // Glyph of Backstab
                case 56800:
                {
                    triggered_spell_id = 63975;
                    break;
                }
                // Deadly Throw Interrupt
                case 32748:
                {
                    // Prevent cast Deadly Throw Interrupt on self from last effect (apply dummy) of Deadly Throw
                    if (this == pVictim)
                        return false;

                    triggered_spell_id = 32747;
                    break;
                }
            }
            // Cut to the Chase
            if (dummySpell->SpellIconID == 2909)
            {
                // "refresh your Slice and Dice duration to its 5 combo point maximum"
                // lookup Slice and Dice
                if (AuraEffect const* aur = GetAuraEffect(SPELL_AURA_MOD_MELEE_HASTE, SPELLFAMILY_ROGUE, 0x40000, 0, 0))
                {
                    aur->GetBase()->SetDuration(GetSpellMaxDuration(aur->GetSpellProto()), true);
                    return true;
                }
                return false;
            }
            // Deadly Brew
            else if (dummySpell->SpellIconID == 2963)
            {
                triggered_spell_id = 3409;
                break;
            }
            // Quick Recovery
            else if (dummySpell->SpellIconID == 2116)
            {
                if (!procSpell)
                    return false;

                // energy cost save
                basepoints0 = CalculatePctN(int32(procSpell->manaCost), triggerAmount);
                if (basepoints0 <= 0)
                    return false;

                target = this;
                triggered_spell_id = 31663;
                break;
            }
            break;
        }
        case SPELLFAMILY_HUNTER:
        {
            // Thrill of the Hunt
            if (dummySpell->SpellIconID == 2236)
            {
                if (!procSpell)
                    return false;

                Spell* spell = ToPlayer()->m_spellModTakingSpell;

                // Disable charge drop because of Lock and Load
                ToPlayer()->SetSpellModTakingSpell(spell, false);

                // Explosive Shot
                if (procSpell->SpellFamilyFlags[2] & 0x200)
                {
                    if (AuraEffect const* pEff = pVictim->GetAuraEffect(SPELL_AURA_PERIODIC_DUMMY, SPELLFAMILY_HUNTER, 0x0, 0x80000000, 0x0, GetGUID()))
                        basepoints0 = CalculatePowerCost(pEff->GetSpellProto(), this, SpellSchoolMask(pEff->GetSpellProto()->SchoolMask)) * 4/10/3;
                }
                else
                    basepoints0 = CalculatePowerCost(procSpell, this, SpellSchoolMask(procSpell->SchoolMask)) * 4/10;

                ToPlayer()->SetSpellModTakingSpell(spell, true);

                if (basepoints0 <= 0)
                    return false;

                target = this;
                triggered_spell_id = 34720;
                break;
            }
            // Hunting Party
            if (dummySpell->SpellIconID == 3406)
            {
                triggered_spell_id = 57669;
                target = this;
                break;
            }
            // Improved Mend Pet
            if (dummySpell->SpellIconID == 267)
            {
                int32 chance = SpellMgr::CalculateSpellEffectAmount(triggeredByAura->GetSpellProto(), triggeredByAura->GetEffIndex());
                if (!roll_chance_i(chance))
                    return false;

                triggered_spell_id = 24406;
                break;
            }
            // Lock and Load
            if (dummySpell->SpellIconID == 3579)
            {
                // Proc only from periodic (from trap activation proc another aura of this spell)
                if (!(procFlag & PROC_FLAG_DONE_PERIODIC) || !roll_chance_i(triggerAmount))
                    return false;
                triggered_spell_id = 56453;
                target = this;
                break;
            }
            // Rapid Recuperation
            if (dummySpell->SpellIconID == 3560)
            {
                // This effect only from Rapid Killing (mana regen)
                if (!(procSpell->SpellFamilyFlags[1] & 0x01000000))
                    return false;

                target = this;

                switch(dummySpell->Id)
                {
                    case 53228:                             // Rank 1
                        triggered_spell_id = 56654;
                        break;
                    case 53232:                             // Rank 2
                        triggered_spell_id = 58882;
                        break;
                }
                break;
            }
            // Glyph of Mend Pet
            if (dummySpell->Id == 57870)
            {
                pVictim->CastSpell(pVictim, 57894, true, NULL, NULL, GetGUID());
                return true;
            }
            break;
        }
        case SPELLFAMILY_PALADIN:
        {
            // Seal of Righteousness - melee proc dummy (addition ${$MWS*(0.022*$AP+0.044*$SPH)} damage)
            if (dummySpell->SpellFamilyFlags[0] & 0x8000000)
            {
                if (effIndex != 0)
                    return false;
                triggered_spell_id = 25742;
                float ap = GetTotalAttackPowerValue(BASE_ATTACK);
                int32 holy = SpellBaseDamageBonus(SPELL_SCHOOL_MASK_HOLY) +
                             SpellBaseDamageBonusForVictim(SPELL_SCHOOL_MASK_HOLY, pVictim);
                basepoints0 = (int32)GetAttackTime(BASE_ATTACK) * int32(ap * 0.022f + 0.044f * holy) / 1000;
                break;
            }
            // Light's Beacon - Beacon of Light
            if (dummySpell->Id == 53651)
            {
                // Get target of beacon of light
                if (Unit* beaconTarget = triggeredByAura->GetBase()->GetCaster())
                {
                    // do not proc when target of beacon of light is healed
                    if (beaconTarget == this)
                        return false;
                    // check if it was heal by paladin which casted this beacon of light
                    if (beaconTarget->GetAura(53563, pVictim->GetGUID()))
                    {
                        if (beaconTarget->IsWithinLOSInMap(pVictim))
                        {
                            basepoints0 = damage;
                            triggered_spell_id = 53654;
                            target = beaconTarget;
                            break;
                        }
                    }
                }
                return false;
            }
            // Judgements of the Wise
            if (dummySpell->SpellIconID == 3017)
            {
                target = this;
                triggered_spell_id = 31930;
                // replenishment
                CastSpell(this, 57669, true, castItem, triggeredByAura);
                break;
            }
            // Sanctified Wrath
            if (dummySpell->SpellIconID == 3029)
            {
                triggered_spell_id = 57318;
                target = this;
                basepoints0 = triggerAmount;
                CastCustomSpell(target, triggered_spell_id, &basepoints0, &basepoints0, NULL, true, castItem, triggeredByAura);
                return true;
            }
            // Sacred Shield
            if (dummySpell->SpellFamilyFlags[1] & 0x80000)
            {
                if (procFlag & PROC_FLAG_TAKEN_SPELL_MAGIC_DMG_CLASS_POS)
                {
                    if (procSpell->SpellFamilyName == SPELLFAMILY_PALADIN && (procSpell->SpellFamilyFlags[0] & 0x40000000))
                    {
                        basepoints0 = damage / 12;

                        if (basepoints0)
                            CastCustomSpell(this, 66922, &basepoints0, NULL, NULL, true, 0, triggeredByAura, pVictim->GetGUID());

                        return true;
                    }
                    else
                        return false;
                }
                else if (damage > 0)
                    triggered_spell_id = 58597;

                // Item - Paladin T8 Holy 4P Bonus
                if (Unit* caster = triggeredByAura->GetCaster())
                    if (AuraEffect const* aurEff = caster->GetAuraEffect(64895, 0))
                        cooldown = aurEff->GetAmount();

                target = this;
                break;
            }
            // Righteous Vengeance
            if (dummySpell->SpellIconID == 3025)
            {
                // 4 damage tick
                basepoints0 = triggerAmount * damage / 400;
                triggered_spell_id = 61840;
                // Add remaining ticks to damage done
                basepoints0 += pVictim->GetRemainingPeriodicAmount(GetGUID(), triggered_spell_id, SPELL_AURA_PERIODIC_DAMAGE);
                break;
            }
            // Sheath of Light
            if (dummySpell->SpellIconID == 3030)
            {
                // 4 healing tick
                basepoints0 = triggerAmount * damage / 400;
                triggered_spell_id = 54203;
                break;
            }
            switch (dummySpell->Id)
            {
                // Heart of the Crusader
                case 20335: // rank 1
                    triggered_spell_id = 21183;
                    break;
                case 20336: // rank 2
                    triggered_spell_id = 54498;
                    break;
                case 20337: // rank 3
                    triggered_spell_id = 54499;
                    break;
                // Judgement of Light
                case 20185:
                {
                        // 2% of base mana
                        basepoints0 = int32(pVictim->CountPctFromMaxHealth(2));
                        pVictim->CastCustomSpell(pVictim, 20267, &basepoints0, 0, 0, true, 0, triggeredByAura);
                        return true;
                }
                // Judgement of Wisdom
                case 20186:
                {
                    if (pVictim && pVictim->isAlive() && pVictim->getPowerType() == POWER_MANA)
                    {
                        // 2% of base mana
                        basepoints0 = int32(CalculatePctN(pVictim->GetCreateMana(), 2));
                        pVictim->CastCustomSpell(pVictim, 20268, &basepoints0, NULL, NULL, true, 0, triggeredByAura);
                    }
                    return true;
                }
                // Holy Power (Redemption Armor set)
                case 28789:
                {
                    if (!pVictim)
                        return false;

                    // Set class defined buff
                    switch (pVictim->getClass())
                    {
                        case CLASS_PALADIN:
                        case CLASS_PRIEST:
                        case CLASS_SHAMAN:
                        case CLASS_DRUID:
                            triggered_spell_id = 28795;     // Increases the friendly target's mana regeneration by $s1 per 5 sec. for $d.
                            break;
                        case CLASS_MAGE:
                        case CLASS_WARLOCK:
                            triggered_spell_id = 28793;     // Increases the friendly target's spell damage and healing by up to $s1 for $d.
                            break;
                        case CLASS_HUNTER:
                        case CLASS_ROGUE:
                            triggered_spell_id = 28791;     // Increases the friendly target's attack power by $s1 for $d.
                            break;
                        case CLASS_WARRIOR:
                            triggered_spell_id = 28790;     // Increases the friendly target's armor
                            break;
                        default:
                            return false;
                    }
                    break;
                }
                case 25899:                                 // Greater Blessing of Sanctuary
                case 20911:                                 // Blessing of Sanctuary
                {
                    target = this;
                    switch (target->getPowerType())
                    {
                        case POWER_MANA:
                            triggered_spell_id = 57319;
                            break;
                        default:
                            return false;
                    }
                    break;
                }
                // Seal of Vengeance (damage calc on apply aura)
                case 31801:
                {
                    if (effIndex != 0)                       // effect 1, 2 used by seal unleashing code
                        return false;

                    // At melee attack or Hammer of the Righteous spell damage considered as melee attack
                    bool stacker = !procSpell || procSpell->Id == 53595;
                    // spells with SPELL_DAMAGE_CLASS_MELEE excluding Judgements
                    bool damager = procSpell && procSpell->EquippedItemClass != -1;

                    if (!stacker && !damager)
                        return false;

                    triggered_spell_id = 31803;

                    // On target with 5 stacks of Holy Vengeance direct damage is done
                    if (Aura* aur = pVictim->GetAura(triggered_spell_id, GetGUID()))
                    {
                        if (aur->GetStackAmount() == 5)
                        {
                            if (stacker)
                                aur->RefreshDuration();
                            CastSpell(pVictim, 42463, true);
                            return true;
                        }
                    }

                    if (!stacker)
                        return false;
                    break;
                }
                // Seal of Corruption
                case 53736:
                {
                    if (effIndex != 0)                       // effect 1, 2 used by seal unleashing code
                        return false;

                    // At melee attack or Hammer of the Righteous spell damage considered as melee attack
                    bool stacker = !procSpell || procSpell->Id == 53595;
                    // spells with SPELL_DAMAGE_CLASS_MELEE excluding Judgements
                    bool damager = procSpell && procSpell->EquippedItemClass != -1;

                    if (!stacker && !damager)
                        return false;

                    triggered_spell_id = 53742;

                    // On target with 5 stacks of Blood Corruption direct damage is done
                    if (Aura* aur = pVictim->GetAura(triggered_spell_id, GetGUID()))
                    {
                        if (aur->GetStackAmount() == 5)
                        {
                            if (stacker)
                                aur->RefreshDuration();
                            CastSpell(pVictim, 53739, true);
                            return true;
                        }
                    }

                    if (!stacker)
                        return false;
                    break;
                }
                // Spiritual Attunement
                case 31785:
                case 33776:
                {
                    // if healed by another unit (pVictim)
                    if (this == pVictim)
                        return false;

                    // heal amount
                    basepoints0 = int32(CalculatePctN(std::min(damage, GetMaxHealth() - GetHealth()), triggerAmount));
                    target = this;

                    if (basepoints0)
                        triggered_spell_id = 31786;
                    break;
                }
                // Paladin Tier 6 Trinket (Ashtongue Talisman of Zeal)
                case 40470:
                {
                    if (!procSpell)
                        return false;

                    float  chance;

                    // Flash of light/Holy light
                    if (procSpell->SpellFamilyFlags[0] & 0xC0000000)
                    {
                        triggered_spell_id = 40471;
                        chance = 15.0f;
                    }
                    // Judgement (any)
                    else if (GetSpellSpecific(procSpell) == SPELL_SPECIFIC_JUDGEMENT)
                    {
                        triggered_spell_id = 40472;
                        chance = 50.0f;
                    }
                    else
                        return false;

                    if (!roll_chance_f(chance))
                        return false;

                    break;
                }
                // Glyph of Holy Light
                case 54937:
                {
                    triggered_spell_id = 54968;
                    basepoints0 = CalculatePctN(int32(damage), triggerAmount);
                    break;
                }
                // Item - Paladin T8 Holy 2P Bonus
                case 64890:
                {
                    triggered_spell_id = 64891;
                    basepoints0 = triggerAmount * damage / 300;
                    break;
                }
                case 71406: // Tiny Abomination in a Jar
                case 71545: // Tiny Abomination in a Jar (Heroic)
                {
                    if (!pVictim || !pVictim->isAlive())
                        return false;

                    CastSpell(this, 71432, true, NULL, triggeredByAura);

                    Aura const* dummy = GetAura(71432);
                    if (!dummy || dummy->GetStackAmount() < (dummySpell->Id == 71406 ? 8 : 7))
                        return false;

                    RemoveAurasDueToSpell(71432);
                    triggered_spell_id = 71433;  // default main hand attack
                    // roll if offhand
                    if (Player const* player = ToPlayer())
                        if (player->GetWeaponForAttack(OFF_ATTACK, true) && urand(0, 1))
                            triggered_spell_id = 71434;
                    target = pVictim;
                    break;
                }
                // Item - Icecrown 25 Normal Dagger Proc
                case 71880:
                {
                    switch (getPowerType())
                    {
                        case POWER_MANA:
                            triggered_spell_id = 71881;
                            break;
                        case POWER_RAGE:
                            triggered_spell_id = 71883;
                            break;
                        case POWER_ENERGY:
                            triggered_spell_id = 71882;
                            break;
                        case POWER_RUNIC_POWER:
                            triggered_spell_id = 71884;
                            break;
                        default:
                            return false;
                    }
                    break;
                }
                // Item - Icecrown 25 Heroic Dagger Proc
                case 71892:
                {
                    switch (getPowerType())
                    {
                        case POWER_MANA:
                            triggered_spell_id = 71888;
                            break;
                        case POWER_RAGE:
                            triggered_spell_id = 71886;
                            break;
                        case POWER_ENERGY:
                            triggered_spell_id = 71887;
                            break;
                        case POWER_RUNIC_POWER:
                            triggered_spell_id = 71885;
                            break;
                        default:
                            return false;
                    }
                    break;
                }
            }
            break;
        }
        case SPELLFAMILY_SHAMAN:
        {
            switch(dummySpell->Id)
            {
                // Earthen Power (Rank 1, 2)
                case 51523:
                case 51524:
                {
                    // Totem itself must be a caster of this spell
                    Unit* caster = NULL;
                    for (ControlList::iterator itr = m_Controlled.begin(); itr != m_Controlled.end(); ++itr) {
                        if ((*itr)->GetEntry() != 2630)
                            continue;

                        caster = *itr;
                        break;
                    }

                    if (!caster)
                        return false;

                    caster->CastSpell(caster, 59566, true, castItem, triggeredByAura, originalCaster);
                    return true;
                }
                // Tidal Force
                case 55198:
                {
                    // Remove aura stack from  caster
                    RemoveAuraFromStack(55166);
                    // drop charges
                    return false;
                }
                // Totemic Power (The Earthshatterer set)
                case 28823:
                {
                    if (!pVictim)
                        return false;

                    // Set class defined buff
                    switch (pVictim->getClass())
                    {
                        case CLASS_PALADIN:
                        case CLASS_PRIEST:
                        case CLASS_SHAMAN:
                        case CLASS_DRUID:
                            triggered_spell_id = 28824;     // Increases the friendly target's mana regeneration by $s1 per 5 sec. for $d.
                            break;
                        case CLASS_MAGE:
                        case CLASS_WARLOCK:
                            triggered_spell_id = 28825;     // Increases the friendly target's spell damage and healing by up to $s1 for $d.
                            break;
                        case CLASS_HUNTER:
                        case CLASS_ROGUE:
                            triggered_spell_id = 28826;     // Increases the friendly target's attack power by $s1 for $d.
                            break;
                        case CLASS_WARRIOR:
                            triggered_spell_id = 28827;     // Increases the friendly target's armor
                            break;
                        default:
                            return false;
                    }
                    break;
                }
                // Lesser Healing Wave (Totem of Flowing Water Relic)
                case 28849:
                {
                    target = this;
                    triggered_spell_id = 28850;
                    break;
                }
                // Windfury Weapon (Passive) 1-5 Ranks
                case 33757:
                {
                    Player* plr = ToPlayer();
                    if (!plr || !castItem || !castItem->IsEquipped() || !pVictim || !pVictim->isAlive())
                        return false;

                    // custom cooldown processing case
                    if (cooldown && plr->HasSpellCooldown(dummySpell->Id))
                        return false;

                    if (triggeredByAura->GetBase() && castItem->GetGUID() != triggeredByAura->GetBase()->GetCastItemGUID())
                        return false;

                    WeaponAttackType attType = WeaponAttackType(plr->GetAttackBySlot(castItem->GetSlot()));
                    if ((attType != BASE_ATTACK && attType != OFF_ATTACK) || !isAttackReady(attType))
                        return false;

                    // Now compute real proc chance...
                    uint32 chance = 20;
                    plr->ApplySpellMod(dummySpell->Id, SPELLMOD_CHANCE_OF_SUCCESS, chance);

                    Item* addWeapon = plr->GetWeaponForAttack(attType == BASE_ATTACK ? OFF_ATTACK : BASE_ATTACK, true);
                    uint32 enchant_id_add = addWeapon ? addWeapon->GetEnchantmentId(EnchantmentSlot(TEMP_ENCHANTMENT_SLOT)) : 0;
                    SpellItemEnchantmentEntry const* pEnchant = sSpellItemEnchantmentStore.LookupEntry(enchant_id_add);
                    if (pEnchant && pEnchant->spellid[0] == dummySpell->Id)
                        chance += 14;

                    if (!roll_chance_i(chance))
                        return false;

                    // Now amount of extra power stored in 1 effect of Enchant spell
                    // Get it by item enchant id
                    uint32 spellId;
                    switch (castItem->GetEnchantmentId(EnchantmentSlot(TEMP_ENCHANTMENT_SLOT)))
                    {
                        case 283: spellId =  8232; break;   // 1 Rank
                        case 284: spellId =  8235; break;   // 2 Rank
                        case 525: spellId = 10486; break;   // 3 Rank
                        case 1669:spellId = 16362; break;   // 4 Rank
                        case 2636:spellId = 25505; break;   // 5 Rank
                        case 3785:spellId = 58801; break;   // 6 Rank
                        case 3786:spellId = 58803; break;   // 7 Rank
                        case 3787:spellId = 58804; break;   // 8 Rank
                        default:
                        {
                            sLog->outError("Unit::HandleDummyAuraProc: non handled item enchantment (rank?) %u for spell id: %u (Windfury)",
                                castItem->GetEnchantmentId(EnchantmentSlot(TEMP_ENCHANTMENT_SLOT)), dummySpell->Id);
                            return false;
                        }
                    }

                    SpellEntry const* windfurySpellEntry = sSpellStore.LookupEntry(spellId);
                    if (!windfurySpellEntry)
                    {
                        sLog->outError("Unit::HandleDummyAuraProc: non existed spell id: %u (Windfury)", spellId);
                        return false;
                    }

                    int32 extra_attack_power = CalculateSpellDamage(pVictim, windfurySpellEntry, 1);

                    // Value gained from additional AP
                    basepoints0 = int32(extra_attack_power / 14.0f * GetAttackTime(BASE_ATTACK) / 1000);
                    triggered_spell_id = 25504;

                    // apply cooldown before cast to prevent processing itself
                    if (cooldown)
                        plr->AddSpellCooldown(dummySpell->Id, 0, time(NULL) + cooldown);

                    // Attack Twice
                    for (uint32 i = 0; i < 2; ++i)
                        CastCustomSpell(pVictim, triggered_spell_id, &basepoints0, NULL, NULL, true, castItem, triggeredByAura);

                    return true;
                }
                // Shaman Tier 6 Trinket
                case 40463:
                {
                    if (!procSpell)
                        return false;

                    float chance;
                    if (procSpell->SpellFamilyFlags[0] & 0x1)
                    {
                        triggered_spell_id = 40465;         // Lightning Bolt
                        chance = 15.0f;
                    }
                    else if (procSpell->SpellFamilyFlags[0] & 0x80)
                    {
                        triggered_spell_id = 40465;         // Lesser Healing Wave
                        chance = 10.0f;
                    }
                    else if (procSpell->SpellFamilyFlags[1] & 0x00000010)
                    {
                        triggered_spell_id = 40466;         // Stormstrike
                        chance = 50.0f;
                    }
                    else
                        return false;

                    if (!roll_chance_f(chance))
                        return false;

                    target = this;
                    break;
                }
                // Glyph of Healing Wave
                case 55440:
                {
                    // Not proc from self heals
                    if (this == pVictim)
                        return false;
                    basepoints0 = CalculatePctN(int32(damage), triggerAmount);
                    target = this;
                    triggered_spell_id = 55533;
                    break;
                }
                // Spirit Hunt
                case 58877:
                {
                    // Cast on owner
                    target = GetOwner();
                    if (!target)
                        return false;
                    basepoints0 = CalculatePctN(int32(damage), triggerAmount);
                    triggered_spell_id = 58879;
                    break;
                }
                // Shaman T8 Elemental 4P Bonus
                case 64928:
                {
                    basepoints0 = CalculatePctN(int32(damage), triggerAmount);
                    triggered_spell_id = 64930;            // Electrified
                    break;
                }
                // Shaman T9 Elemental 4P Bonus
                case 67228:
                {
                    // Lava Burst
                    if (procSpell->SpellFamilyFlags[1] & 0x1000)
                    {
                        triggered_spell_id = 71824;
                        SpellEntry const* triggeredSpell = sSpellStore.LookupEntry(triggered_spell_id);
                        if (!triggeredSpell)
                            return false;
                        basepoints0 = CalculatePctN(int32(damage), triggerAmount) / (GetSpellMaxDuration(triggeredSpell) / triggeredSpell->EffectAmplitude[0]);
                    }
                    break;
                }
                // Item - Shaman T10 Restoration 4P Bonus
                case 70808:
                {
                    // Chain Heal
                    if ((procSpell->SpellFamilyFlags[0] & 0x100) && (procEx & PROC_EX_CRITICAL_HIT))
                    {
                        triggered_spell_id = 70809;
                        SpellEntry const* triggeredSpell = sSpellStore.LookupEntry(triggered_spell_id);
                        if (!triggeredSpell)
                            return false;
                        basepoints0 = CalculatePctN(int32(damage), triggerAmount) / (GetSpellMaxDuration(triggeredSpell) / triggeredSpell->EffectAmplitude[0]);
                    }
                    break;
                }
                // Item - Shaman T10 Elemental 2P Bonus
                case 70811:
                {
                    // Lightning Bolt & Chain Lightning
                    if (procSpell->SpellFamilyFlags[0] & 0x3)
                    {
                        if (ToPlayer()->HasSpellCooldown(16166))
                        {
                            uint32 newCooldownDelay = ToPlayer()->GetSpellCooldownDelay(16166);
                            if (newCooldownDelay < 3)
                                newCooldownDelay = 0;
                            else
                                newCooldownDelay -= 2;
                            ToPlayer()->AddSpellCooldown(16166, 0, uint32(time(NULL) + newCooldownDelay));

                            WorldPacket data(SMSG_MODIFY_COOLDOWN, 4+8+4);
                            data << uint32(16166);                  // Spell ID
                            data << uint64(GetGUID());              // Player GUID
                            data << int32(-2000);                   // Cooldown mod in milliseconds
                            ToPlayer()->GetSession()->SendPacket(&data);
                            return true;
                        }
                    }
                    return false;
                }
                // Item - Shaman T10 Elemental 4P Bonus
                case 70817:
                {
                    // try to find spell Flame Shock on the target
                    if (AuraEffect const* aurEff = target->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_SHAMAN, 0x10000000, 0x0, 0x0, GetGUID()))
                    {
                        Aura* flameShock  = aurEff->GetBase();
                        int32 maxDuration = flameShock->GetMaxDuration();
                        int32 newDuration = flameShock->GetDuration() + 2 * aurEff->GetAmplitude();

                        flameShock->SetDuration(newDuration);
                        // is it blizzlike to change max duration for FS?
                        if (newDuration > maxDuration)
                            flameShock->SetMaxDuration(newDuration);

                        return true;
                    }
                    // if not found Flame Shock
                    return false;
                }
                case 63280: // Glyph of Totem of Wrath
                {
                    if (procSpell->SpellIconID != 2019)
                        return false;

                    AuraEffect* aurEffA = NULL;
                    AuraEffectList const& auras = GetAuraEffectsByType(SPELL_AURA_MOD_DAMAGE_DONE);
                    for (AuraEffectList::const_iterator i = auras.begin(); i != auras.end(); ++i)
                    {
                        SpellEntry const* spell = (*i)->GetSpellProto();
                        if (spell->SpellFamilyName == uint32(SPELLFAMILY_SHAMAN) && spell->SpellFamilyFlags.HasFlag(0, 0x02000000, 0))
                        {
                            if ((*i)->GetCasterGUID() != GetGUID())
                                continue;
                            if (spell->Id == 63283)
                                continue;
                            aurEffA = (*i);
                            break;
                        }
                    }
                    if (aurEffA)
                    {
                        int32 bp0 = 0, bp1 = 0;
                        bp0 = CalculatePctN(triggerAmount, aurEffA->GetAmount());
                        if (AuraEffect* aurEffB = aurEffA->GetBase()->GetEffect(EFFECT_1))
                            bp1 = CalculatePctN(triggerAmount, aurEffB->GetAmount());
                        CastCustomSpell(this, 63283, &bp0, &bp1, NULL, true, NULL, triggeredByAura);
                        return true;
                    }
                    return false;
                }
                break;
            }
            // Frozen Power
            if (dummySpell->SpellIconID == 3780)
            {
                if (GetDistance(target) < 15.0f)
                    return false;
                float chance = (float)triggerAmount;
                if (!roll_chance_f(chance))
                    return false;

                triggered_spell_id = 63685;
                break;
            }
            // Storm, Earth and Fire
            if (dummySpell->SpellIconID == 3063)
            {
                // Earthbind Totem summon only
                if (procSpell->Id != 2484)
                    return false;

                float chance = (float)triggerAmount;
                if (!roll_chance_f(chance))
                    return false;

                triggered_spell_id = 64695;
                break;
            }
            // Ancestral Awakening
            if (dummySpell->SpellIconID == 3065)
            {
                triggered_spell_id = 52759;
                basepoints0 = CalculatePctN(int32(damage), triggerAmount);
                target = this;
                break;
            }
            // Earth Shield
            if (dummySpell->SpellFamilyFlags[1] & 0x00000400)
            {
                // 3.0.8: Now correctly uses the Shaman's own spell critical strike chance to determine the chance of a critical heal.
                originalCaster = triggeredByAura->GetCasterGUID();
                target = this;
                basepoints0 = triggerAmount;

                // Glyph of Earth Shield
                if (AuraEffect* aur = GetAuraEffect(63279, 0))
                    AddPctN(basepoints0, aur->GetAmount());
                triggered_spell_id = 379;
                break;
            }
            // Flametongue Weapon (Passive)
            if (dummySpell->SpellFamilyFlags[0] & 0x200000)
            {
                if (GetTypeId() != TYPEID_PLAYER  || !pVictim || !pVictim->isAlive() || !castItem || !castItem->IsEquipped())
                    return false;

                float fire_onhit = float(CalculatePctF(SpellMgr::CalculateSpellEffectAmount(dummySpell, 0), 1.0f));

                float add_spellpower = (float)(SpellBaseDamageBonus(SPELL_SCHOOL_MASK_FIRE)
                                     + SpellBaseDamageBonusForVictim(SPELL_SCHOOL_MASK_FIRE, pVictim));

                // 1.3speed = 5%, 2.6speed = 10%, 4.0 speed = 15%, so, 1.0speed = 3.84%
                ApplyPctF(add_spellpower, 3.84f);

                // Enchant on Off-Hand and ready?
                if (castItem->GetSlot() == EQUIPMENT_SLOT_OFFHAND && isAttackReady(OFF_ATTACK))
                {
                    float BaseWeaponSpeed = GetAttackTime(OFF_ATTACK) / 1000.0f;

                    // Value1: add the tooltip damage by swingspeed + Value2: add spelldmg by swingspeed
                    basepoints0 = int32((fire_onhit * BaseWeaponSpeed) + (add_spellpower * BaseWeaponSpeed));
                    triggered_spell_id = 10444;
                }

                // Enchant on Main-Hand and ready?
                else if (castItem->GetSlot() == EQUIPMENT_SLOT_MAINHAND && isAttackReady(BASE_ATTACK))
                {
                    float BaseWeaponSpeed = GetAttackTime(BASE_ATTACK) / 1000.0f;

                    // Value1: add the tooltip damage by swingspeed +  Value2: add spelldmg by swingspeed
                    basepoints0 = int32((fire_onhit * BaseWeaponSpeed) + (add_spellpower * BaseWeaponSpeed));
                    triggered_spell_id = 10444;
                }

                // If not ready, we should  return, shouldn't we?!
                else
                    return false;

                CastCustomSpell(pVictim, triggered_spell_id, &basepoints0, NULL, NULL, true, castItem, triggeredByAura);
                return true;
            }
            // Improved Water Shield
            if (dummySpell->SpellIconID == 2287)
            {
                // Default chance for Healing Wave and Riptide
                float chance = (float)triggeredByAura->GetAmount();

                if (procSpell->SpellFamilyFlags[0] & 0x80)
                    // Lesser Healing Wave - 0.6 of default
                    chance *= 0.6f;
                else if (procSpell->SpellFamilyFlags[0] & 0x100)
                    // Chain heal - 0.3 of default
                    chance *= 0.3f;

                if (!roll_chance_f(chance))
                    return false;

                // Water Shield
                if (AuraEffect const* aurEff = GetAuraEffect(SPELL_AURA_PROC_TRIGGER_SPELL, SPELLFAMILY_SHAMAN, 0, 0x00000020, 0))
                {
                    uint32 spell = aurEff->GetSpellProto()->EffectTriggerSpell[aurEff->GetEffIndex()];
                    CastSpell(this, spell, true, castItem, triggeredByAura);
                    return true;
                }
                return false;
            }
            // Lightning Overload
            if (dummySpell->SpellIconID == 2018)            // only this spell have SpellFamily Shaman SpellIconID == 2018 and dummy aura
            {
                if (!procSpell || GetTypeId() != TYPEID_PLAYER || !pVictim)
                    return false;

                // custom cooldown processing case
                if (cooldown && GetTypeId() == TYPEID_PLAYER && ToPlayer()->HasSpellCooldown(dummySpell->Id))
                    return false;

                uint32 spellId = 0;
                // Every Lightning Bolt and Chain Lightning spell have duplicate vs half damage and zero cost
                switch (procSpell->Id)
                {
                    // Lightning Bolt
                    case   403: spellId = 45284; break;     // Rank  1
                    case   529: spellId = 45286; break;     // Rank  2
                    case   548: spellId = 45287; break;     // Rank  3
                    case   915: spellId = 45288; break;     // Rank  4
                    case   943: spellId = 45289; break;     // Rank  5
                    case  6041: spellId = 45290; break;     // Rank  6
                    case 10391: spellId = 45291; break;     // Rank  7
                    case 10392: spellId = 45292; break;     // Rank  8
                    case 15207: spellId = 45293; break;     // Rank  9
                    case 15208: spellId = 45294; break;     // Rank 10
                    case 25448: spellId = 45295; break;     // Rank 11
                    case 25449: spellId = 45296; break;     // Rank 12
                    case 49237: spellId = 49239; break;     // Rank 13
                    case 49238: spellId = 49240; break;     // Rank 14
                    // Chain Lightning
                    case   421: spellId = 45297; break;     // Rank  1
                    case   930: spellId = 45298; break;     // Rank  2
                    case  2860: spellId = 45299; break;     // Rank  3
                    case 10605: spellId = 45300; break;     // Rank  4
                    case 25439: spellId = 45301; break;     // Rank  5
                    case 25442: spellId = 45302; break;     // Rank  6
                    case 49270: spellId = 49268; break;     // Rank  7
                    case 49271: spellId = 49269; break;     // Rank  8
                    default:
                        sLog->outError("Unit::HandleDummyAuraProc: non handled spell id: %u (LO)", procSpell->Id);
                        return false;
                }

                // Chain Lightning
                if (procSpell->SpellFamilyFlags[0] & 0x2)
                {
                    // Chain lightning has [LightOverload_Proc_Chance] / [Max_Number_of_Targets] chance to proc of each individual target hit.
                    // A maxed LO would have a 33% / 3 = 11% chance to proc of each target.
                    // LO chance was already "accounted" at the proc chance roll, now need to divide the chance by [Max_Number_of_Targets]
                    float chance = 100.0f / procSpell->EffectChainTarget[effIndex];
                    if (!roll_chance_f(chance))
                        return false;

                    // Remove cooldown (Chain Lightning - have Category Recovery time)
                    ToPlayer()->RemoveSpellCooldown(spellId);
                }

                CastSpell(pVictim, spellId, true, castItem, triggeredByAura);

                if (cooldown && GetTypeId() == TYPEID_PLAYER)
                    ToPlayer()->AddSpellCooldown(dummySpell->Id, 0, time(NULL) + cooldown);

                return true;
            }
            // Static Shock
            if (dummySpell->SpellIconID == 3059)
            {
                // Lightning Shield
                if (AuraEffect const* aurEff = GetAuraEffect(SPELL_AURA_PROC_TRIGGER_SPELL, SPELLFAMILY_SHAMAN, 0x400, 0, 0))
                {
                    uint32 spell = sSpellMgr->GetSpellWithRank(26364, sSpellMgr->GetSpellRank(aurEff->GetId()));

                    // custom cooldown processing case
                    if (GetTypeId() == TYPEID_PLAYER && ToPlayer()->HasSpellCooldown(spell))
                        ToPlayer()->RemoveSpellCooldown(spell);

                    CastSpell(target, spell, true, castItem, triggeredByAura);
                    aurEff->GetBase()->DropCharge();
                    return true;
                }
                return false;
            }
            break;
        }
        case SPELLFAMILY_DEATHKNIGHT:
        {
            // Blood-Caked Strike - Blood-Caked Blade
            if (dummySpell->SpellIconID == 138)
            {
                if (!target || !target->isAlive())
                    return false;

                triggered_spell_id = dummySpell->EffectTriggerSpell[effIndex];
                break;
            }
            // Improved Blood Presence
            if (dummySpell->SpellIconID == 2636)
            {
                if (GetTypeId() != TYPEID_PLAYER)
                    return false;
                basepoints0 = CalculatePctN(int32(damage), triggerAmount);
                break;
            }
            // Butchery
            if (dummySpell->SpellIconID == 2664)
            {
                basepoints0 = triggerAmount;
                triggered_spell_id = 50163;
                target = this;
                break;
            }
            // Dancing Rune Weapon
            if (dummySpell->Id == 49028)
            {
                // 1 dummy aura for dismiss rune blade
                if (effIndex != 1)
                    return false;

                Unit* pPet = NULL;
                for (ControlList::const_iterator itr = m_Controlled.begin(); itr != m_Controlled.end(); ++itr) // Find Rune Weapon
                    if ((*itr)->GetEntry() == 27893)
                    {
                        pPet = *itr;
                        break;
                    }

                if (pPet && pPet->getVictim() && damage && procSpell)
                {
                    uint32 procDmg = damage / 2;
                    pPet->SendSpellNonMeleeDamageLog(pPet->getVictim(), procSpell->Id, procDmg, GetSpellSchoolMask(procSpell), 0, 0, false, 0, false);
                    pPet->DealDamage(pPet->getVictim(), procDmg, NULL, SPELL_DIRECT_DAMAGE, GetSpellSchoolMask(procSpell), procSpell, true);
                    break;
                }
                else
                    return false;
            }
            // Mark of Blood
            if (dummySpell->Id == 49005)
            {
                // TODO: need more info (cooldowns/PPM)
                triggered_spell_id = 61607;
                break;
            }
            // Unholy Blight
            if (dummySpell->Id == 49194)
            {
                basepoints0 = CalculatePctN(int32(damage), triggerAmount);
                // Glyph of Unholy Blight
                if (AuraEffect* glyph=GetAuraEffect(63332, 0))
                    AddPctN(basepoints0, glyph->GetAmount());

                triggered_spell_id = 50536;
                basepoints0 += pVictim->GetRemainingPeriodicAmount(GetGUID(), triggered_spell_id, SPELL_AURA_PERIODIC_DAMAGE);
                break;
            }
            // Vendetta
            if (dummySpell->SpellFamilyFlags[0] & 0x10000)
            {
                basepoints0 = int32(CountPctFromMaxHealth(triggerAmount));
                triggered_spell_id = 50181;
                target = this;
                break;
            }
            // Necrosis
            if (dummySpell->SpellIconID == 2709)
            {
                basepoints0 = CalculatePctN(int32(damage), triggerAmount);
                triggered_spell_id = 51460;
                break;
            }
            // Threat of Thassarian
            if (dummySpell->SpellIconID == 2023)
            {
                // Must Dual Wield
                if (!procSpell || !haveOffhandWeapon())
                    return false;
                // Chance as basepoints for dummy aura
                if (!roll_chance_i(triggerAmount))
                    return false;

                switch (procSpell->Id)
                {
                    // Obliterate
                    case 49020: triggered_spell_id = 66198; break;                            // Rank 1
                    case 51423: triggered_spell_id = 66972; break;                            // Rank 2
                    case 51424: triggered_spell_id = 66973; break;                            // Rank 3
                    case 51425: triggered_spell_id = 66974; break;                            // Rank 4

                    // Frost Strike
                    case 49143: triggered_spell_id = 66196; break;                            // Rank 1
                    case 51416: triggered_spell_id = 66958; break;                            // Rank 2
                    case 51417: triggered_spell_id = 66959; break;                            // Rank 3
                    case 51418: triggered_spell_id = 66960; break;                            // Rank 4
                    case 51419: triggered_spell_id = 66961; break;                            // Rank 5
                    case 55268: triggered_spell_id = 66962; break;                            // Rank 6

                    // Plague Strike
                    case 45462: triggered_spell_id = 66216; break;                            // Rank 1
                    case 49917: triggered_spell_id = 66988; break;                            // Rank 2
                    case 49918: triggered_spell_id = 66989; break;                            // Rank 3
                    case 49919: triggered_spell_id = 66990; break;                            // Rank 4
                    case 49920: triggered_spell_id = 66991; break;                            // Rank 5
                    case 49921: triggered_spell_id = 66992; break;                            // Rank 6

                    // Death Strike
                    case 49998: triggered_spell_id = 66188; break;                            // Rank 1
                    case 49999: triggered_spell_id = 66950; break;                            // Rank 2
                    case 45463: triggered_spell_id = 66951; break;                            // Rank 3
                    case 49923: triggered_spell_id = 66952; break;                            // Rank 4
                    case 49924: triggered_spell_id = 66953; break;                            // Rank 5

                    // Rune Strike
                    case 56815: triggered_spell_id = 66217; break;                            // Rank 1

                    // Blood Strike
                    case 45902: triggered_spell_id = 66215; break;                            // Rank 1
                    case 49926: triggered_spell_id = 66975; break;                            // Rank 2
                    case 49927: triggered_spell_id = 66976; break;                            // Rank 3
                    case 49928: triggered_spell_id = 66977; break;                            // Rank 4
                    case 49929: triggered_spell_id = 66978; break;                            // Rank 5
                    case 49930: triggered_spell_id = 66979; break;                            // Rank 6
                    default:
                        return false;
                }
                break;
            }
            // Runic Power Back on Snare/Root
            if (dummySpell->Id == 61257)
            {
                // only for spells and hit/crit (trigger start always) and not start from self casted spells
                if (procSpell == 0 || !(procEx & (PROC_EX_NORMAL_HIT|PROC_EX_CRITICAL_HIT)) || this == pVictim)
                    return false;
                // Need snare or root mechanic
                if (!(GetAllSpellMechanicMask(procSpell) & ((1<<MECHANIC_ROOT)|(1<<MECHANIC_SNARE))))
                    return false;
                triggered_spell_id = 61258;
                target = this;
                break;
            }
            // Wandering Plague
            if (dummySpell->SpellIconID == 1614)
            {
                if (!roll_chance_f(GetUnitCriticalChance(BASE_ATTACK, pVictim)))
                    return false;
                basepoints0 = CalculatePctN(int32(damage), triggerAmount);
                triggered_spell_id = 50526;
                break;
            }
            // Sudden Doom
            if (dummySpell->SpellIconID == 1939 && GetTypeId() == TYPEID_PLAYER)
            {
                SpellChainNode const* chain = NULL;
                // get highest rank of the Death Coil spell
                PlayerSpellMap const& sp_list = ToPlayer()->GetSpellMap();
                for (PlayerSpellMap::const_iterator itr = sp_list.begin(); itr != sp_list.end(); ++itr)
                {
                    // check if shown in spell book
                    if (!itr->second->active || itr->second->disabled || itr->second->state == PLAYERSPELL_REMOVED)
                        continue;

                    SpellEntry const* spellProto = sSpellStore.LookupEntry(itr->first);
                    if (!spellProto)
                        continue;

                    if (spellProto->SpellFamilyName == SPELLFAMILY_DEATHKNIGHT
                        && spellProto->SpellFamilyFlags[0] & 0x2000)
                    {
                        SpellChainNode const* newChain = sSpellMgr->GetSpellChainNode(itr->first);

                        // No chain entry or entry lower than found entry
                        if (!chain || !newChain || (chain->rank < newChain->rank))
                        {
                            triggered_spell_id = itr->first;
                            chain = newChain;
                        }
                        else
                            continue;
                        // Found spell is last in chain - do not need to look more
                        // Optimisation for most common case
                        if (chain && chain->last == itr->first)
                            break;
                    }
                }
            }
            // Item - Death Knight T10 Melee 4P Bonus
            if (dummySpell->Id == 70656)
            {
                if (GetTypeId() != TYPEID_PLAYER)
                    return false;

                Player* player = ToPlayer();

                for (uint32 i = 0; i < MAX_RUNES; ++i)
                    if (player->GetRuneCooldown(i) == 0)
                        return false;
            }
            break;
        }
        case SPELLFAMILY_POTION:
        {
            // alchemist's stone
            if (dummySpell->Id == 17619)
            {
                if (procSpell->SpellFamilyName == SPELLFAMILY_POTION)
                {
                    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
                    {
                        if (procSpell->Effect[i] == SPELL_EFFECT_HEAL)
                        {
                            triggered_spell_id = 21399;
                        }
                        else if (procSpell->Effect[i] == SPELL_EFFECT_ENERGIZE)
                        {
                            triggered_spell_id = 21400;
                        }
                        else
                            continue;

                        basepoints0 = int32(CalculateSpellDamage(this, procSpell, i) * 0.4f);
                        CastCustomSpell(this, triggered_spell_id, &basepoints0, NULL, NULL, true, NULL, triggeredByAura);
                    }
                    return true;
                }
            }
            break;
        }
        case SPELLFAMILY_PET:
        {
            switch (dummySpell->SpellIconID)
            {
                // Guard Dog
                case 201:
                {
                    triggered_spell_id = 54445;
                    target = this;
                    float addThreat = float(CalculatePctN(SpellMgr::CalculateSpellEffectAmount(procSpell, 0, this), triggerAmount));
                    pVictim->AddThreat(this, addThreat);
                    break;
                }
                // Silverback
                case 1582:
                    triggered_spell_id = dummySpell->Id == 62765 ? 62801 : 62800;
                    target = this;
                    break;
            }
            break;
        }
        default:
            break;
    }

    // if not handled by custom case, get triggered spell from dummySpell proto
    if (!triggered_spell_id)
        triggered_spell_id = dummySpell->EffectTriggerSpell[triggeredByAura->GetEffIndex()];

    // processed charge only counting case
    if (!triggered_spell_id)
        return true;

    SpellEntry const* triggerEntry = sSpellStore.LookupEntry(triggered_spell_id);
    if (!triggerEntry)
    {
        sLog->outError("Unit::HandleDummyAuraProc: Spell %u have not existed triggered spell %u", dummySpell->Id, triggered_spell_id);
        return false;
    }

    // default case
    if ((!target && !sSpellMgr->IsSrcTargetSpell(triggerEntry)) || (target && target != this && !target->isAlive()))
        return false;

    if (cooldown_spell_id == 0)
        cooldown_spell_id = triggered_spell_id;

    if (cooldown && GetTypeId() == TYPEID_PLAYER && ToPlayer()->HasSpellCooldown(cooldown_spell_id))
        return false;

    if (basepoints0)
        CastCustomSpell(target, triggered_spell_id, &basepoints0, NULL, NULL, true, castItem, triggeredByAura, originalCaster);
    else
        CastSpell(target, triggered_spell_id, true, castItem, triggeredByAura, originalCaster);

    if (cooldown && GetTypeId() == TYPEID_PLAYER)
        ToPlayer()->AddSpellCooldown(cooldown_spell_id, 0, time(NULL) + cooldown);

    return true;
}
bool Unit::HandleObsModEnergyAuraProc(Unit *pVictim, uint32 /*damage*/, AuraEffect* triggeredByAura, SpellEntry const* /*procSpell*/, uint32 /*procFlag*/, uint32 /*procEx*/, uint32 cooldown)
{
    SpellEntry const* dummySpell = triggeredByAura->GetSpellProto();
    //uint32 effIndex = triggeredByAura->GetEffIndex();
    //int32  triggerAmount = triggeredByAura->GetAmount();

    Item* castItem = triggeredByAura->GetBase()->GetCastItemGUID() && GetTypeId() == TYPEID_PLAYER
        ? ToPlayer()->GetItemByGuid(triggeredByAura->GetBase()->GetCastItemGUID()) : NULL;

    uint32 triggered_spell_id = 0;
    Unit* target = pVictim;
    int32 basepoints0 = 0;

    switch(dummySpell->SpellFamilyName)
    {
        case SPELLFAMILY_HUNTER:
        {
            // Aspect of the Viper
            if (dummySpell->SpellFamilyFlags[1] & 0x40000)
            {
                uint32 maxmana = GetMaxPower(POWER_MANA);
                basepoints0 = CalculatePctF(maxmana, GetAttackTime(RANGED_ATTACK) / 1000.0f);
                target = this;
                triggered_spell_id = 34075;
                break;
            }
            break;
        }
    }
    // processed charge only counting case
    if (!triggered_spell_id)
        return true;

    SpellEntry const* triggerEntry = sSpellStore.LookupEntry(triggered_spell_id);

    // Try handle unknown trigger spells
    if (!triggerEntry)
    {
        sLog->outError("Unit::HandleObsModEnergyAuraProc: Spell %u have not existed triggered spell %u", dummySpell->Id, triggered_spell_id);
        return false;
    }

    // default case
    if ((!target && !sSpellMgr->IsSrcTargetSpell(triggerEntry)) || (target && target != this && !target->isAlive()))
        return false;

    if (cooldown && GetTypeId() == TYPEID_PLAYER && ToPlayer()->HasSpellCooldown(triggered_spell_id))
        return false;
    if (basepoints0)
        CastCustomSpell(target, triggered_spell_id, &basepoints0, NULL, NULL, true, castItem, triggeredByAura);
    else
        CastSpell(target, triggered_spell_id, true, castItem, triggeredByAura);

    if (cooldown && GetTypeId() == TYPEID_PLAYER)
        ToPlayer()->AddSpellCooldown(triggered_spell_id, 0, time(NULL) + cooldown);
    return true;
}
bool Unit::HandleModDamagePctTakenAuraProc(Unit *pVictim, uint32 /*damage*/, AuraEffect* triggeredByAura, SpellEntry const* /*procSpell*/, uint32 /*procFlag*/, uint32 /*procEx*/, uint32 cooldown)
{
    SpellEntry const* dummySpell = triggeredByAura->GetSpellProto();
    //uint32 effIndex = triggeredByAura->GetEffIndex();
    //int32  triggerAmount = triggeredByAura->GetAmount();

    Item* castItem = triggeredByAura->GetBase()->GetCastItemGUID() && GetTypeId() == TYPEID_PLAYER
        ? ToPlayer()->GetItemByGuid(triggeredByAura->GetBase()->GetCastItemGUID()) : NULL;

    uint32 triggered_spell_id = 0;
    Unit* target = pVictim;
    int32 basepoints0 = 0;

    switch(dummySpell->SpellFamilyName)
    {
        case SPELLFAMILY_PALADIN:
        {
            // Blessing of Sanctuary
            if (dummySpell->SpellFamilyFlags[0] & 0x10000000)
            {
                switch (getPowerType())
                {
                    case POWER_MANA:   triggered_spell_id = 57319; break;
                    default:
                        return false;
                }
            }
            break;
        }
    }
    // processed charge only counting case
    if (!triggered_spell_id)
        return true;

    SpellEntry const* triggerEntry = sSpellStore.LookupEntry(triggered_spell_id);

    if (!triggerEntry)
    {
        sLog->outError("Unit::HandleModDamagePctTakenAuraProc: Spell %u have not existed triggered spell %u", dummySpell->Id, triggered_spell_id);
        return false;
    }

    // default case
    if ((!target && !sSpellMgr->IsSrcTargetSpell(triggerEntry)) || (target && target != this && !target->isAlive()))
        return false;

    if (cooldown && GetTypeId() == TYPEID_PLAYER && ToPlayer()->HasSpellCooldown(triggered_spell_id))
        return false;

    if (basepoints0)
        CastCustomSpell(target, triggered_spell_id, &basepoints0, NULL, NULL, true, castItem, triggeredByAura);
    else
        CastSpell(target, triggered_spell_id, true, castItem, triggeredByAura);

    if (cooldown && GetTypeId() == TYPEID_PLAYER)
        ToPlayer()->AddSpellCooldown(triggered_spell_id, 0, time(NULL) + cooldown);

    return true;
}

// Used in case when access to whole aura is needed
// All procs should be handled like this...
bool Unit::HandleAuraProc(Unit* pVictim, uint32 damage, Aura * triggeredByAura, SpellEntry const* procSpell, uint32 /*procFlag*/, uint32 procEx, uint32 cooldown, bool * handled)
{
    SpellEntry const* dummySpell = triggeredByAura->GetSpellProto();

    switch(dummySpell->SpellFamilyName)
    {
        case SPELLFAMILY_GENERIC:
            switch (dummySpell->Id)
            {
                // Nevermelting Ice Crystal
                case 71564:
                    RemoveAuraFromStack(71564);
                    *handled = true;
                    break;
                case 71756:
                case 72782:
                case 72783:
                case 72784:
                    RemoveAuraFromStack(dummySpell->Id);
                    *handled = true;
                    break;
                // Discerning Eye of the Beast
                case 59915:
                {
                    CastSpell(this, 59914, true);   // 59914 already has correct basepoints in DBC, no need for custom bp
                    *handled = true;
                    break;
                }
                // Swift Hand of Justice
                case 59906:
                {
                    int32 bp0 = CalculatePctN(GetMaxHealth(), SpellMgr::CalculateSpellEffectAmount(dummySpell, 0));
                    CastCustomSpell(this, 59913, &bp0, NULL, NULL, true);
                    *handled = true;
                    break;
                }
            }

            break;
        case SPELLFAMILY_PALADIN:
        {
            // Infusion of Light
            if (dummySpell->SpellIconID == 3021)
            {
                // Flash of Light HoT on Flash of Light when Sacred Shield active
                if (procSpell->SpellFamilyFlags[0] & 0x40000000 && procSpell->SpellIconID == 242)
                {
                    *handled = true;
                    if (pVictim->HasAura(53601))
                    {
                        int32 bp0 = CalculatePctN(int32(damage / 12), SpellMgr::CalculateSpellEffectAmount(dummySpell, 2));
                        // Item - Paladin T9 Holy 4P Bonus
                        if (AuraEffect const* aurEff = GetAuraEffect(67191, 0))
                            AddPctN(bp0, aurEff->GetAmount());
                        CastCustomSpell(pVictim, 66922, &bp0, NULL, NULL, true);
                        return true;
                    }
                }
                // but should not proc on non-critical Holy Shocks
                else if ((procSpell->SpellFamilyFlags[0] & 0x200000 || procSpell->SpellFamilyFlags[1] & 0x10000) && !(procEx & PROC_EX_CRITICAL_HIT))
                    *handled = true;
                break;
            }
            // Judgements of the Just
            else if (dummySpell->SpellIconID == 3015)
            {
                *handled = true;
                if (procSpell->Category == SPELLCATEGORY_JUDGEMENT)
                {
                    CastSpell(pVictim, 68055, true);
                    return true;
                }
            }
            // Glyph of Divinity
            else if (dummySpell->Id == 54939)
            {
                *handled = true;
                // Check if we are the target and prevent mana gain
                if (triggeredByAura->GetCasterGUID() == pVictim->GetGUID())
                    return false;
                // Lookup base amount mana restore
                for (uint8 i = 0; i<MAX_SPELL_EFFECTS; i++)
                {
                    if (procSpell->Effect[i] == SPELL_EFFECT_ENERGIZE)
                    {
                        // value multiplied by 2 because you should get twice amount
                        int32 mana = SpellMgr::CalculateSpellEffectAmount(procSpell, i) * 2;
                        CastCustomSpell(this, 54986, 0, &mana, NULL, true);
                    }
                }
                return true;
            }
            break;
        }
        case SPELLFAMILY_MAGE:
        {
            // Combustion
            switch (dummySpell->Id)
            {
                case 11129:
                {
                    *handled = true;
                    Unit* caster = triggeredByAura->GetCaster();
                    if (!caster || !damage)
                        return false;

                    // last charge and crit
                    if (triggeredByAura->GetCharges() <= 1 && (procEx & PROC_EX_CRITICAL_HIT))
                        return true;                        // charge counting (will removed)

                    CastSpell(this, 28682, true);

                    return (procEx & PROC_EX_CRITICAL_HIT) ? true : false;
                }
                // Empowered Fire
                case 31656:
                case 31657:
                case 31658:
                {
                    *handled = true;

                    SpellEntry const* spInfo = sSpellStore.LookupEntry(67545);
                    if (!spInfo)
                        return false;

                    int32 bp0 = int32(CalculatePctN(GetCreateMana(), SpellMgr::CalculateSpellEffectAmount(spInfo, 0)));
                    CastCustomSpell(this, 67545, &bp0, NULL, NULL, true, NULL, triggeredByAura->GetEffect(EFFECT_0), GetGUID());
                    return true;
                }
            }
            break;
        }
        case SPELLFAMILY_DEATHKNIGHT:
        {
            // Blood of the North
            // Reaping
            // Death Rune Mastery
            if (dummySpell->SpellIconID == 3041 || dummySpell->SpellIconID == 22 || dummySpell->SpellIconID == 2622)
            {
                *handled = true;
                // Convert recently used Blood Rune to Death Rune
                if (Player* plr = ToPlayer())
                {
                    if (plr->getClass() != CLASS_DEATH_KNIGHT)
                        return false;
                    RuneType rune = ToPlayer()->GetLastUsedRune();
                    // can't proc from death rune use
                    if (rune == RUNE_DEATH)
                        return false;
                    AuraEffect* aurEff = triggeredByAura->GetEffect(EFFECT_0);
                    if (!aurEff)
                        return false;
                    // Reset amplitude - set death rune remove timer to 30s
                    aurEff->ResetPeriodic(true);
                    uint32 runesLeft;

                    if (dummySpell->SpellIconID == 2622)
                        runesLeft = 2;
                    else
                        runesLeft = 1;

                    for (uint8 i = 0; i < MAX_RUNES && runesLeft; ++i)
                    {
                        if (dummySpell->SpellIconID == 2622)
                        {
                            if (plr->GetCurrentRune(i) == RUNE_DEATH ||
                                plr->GetBaseRune(i) == RUNE_BLOOD)
                                continue;
                        }
                        else
                        {
                            if (plr->GetCurrentRune(i) == RUNE_DEATH ||
                                plr->GetBaseRune(i) != RUNE_BLOOD)
                                continue;
                        }
                        if (plr->GetRuneCooldown(i) != plr->GetRuneBaseCooldown(i))
                            continue;

                        --runesLeft;
                        // Mark aura as used
                        plr->AddRuneByAuraEffect(i, RUNE_DEATH, aurEff);
                    }
                    return true;
                }
                return false;
            }

            switch(dummySpell->Id)
            {
                // Bone Shield cooldown
                case 49222:
                {
                    *handled = true;
                    if (cooldown && GetTypeId() == TYPEID_PLAYER)
                    {
                        if (ToPlayer()->HasSpellCooldown(100000))
                            return false;
                        ToPlayer()->AddSpellCooldown(100000, 0, time(NULL) + cooldown);
                    }
                    return true;
                }
                // Hungering Cold aura drop
                case 51209:
                    *handled = true;
                    // Drop only in not disease case
                    if (procSpell && procSpell->Dispel == DISPEL_DISEASE)
                        return false;
                    return true;
            }
            break;
        }
        case SPELLFAMILY_WARRIOR:
        {
            switch (dummySpell->Id)
            {
                // Item - Warrior T10 Protection 4P Bonus
                case 70844:
                {
                    int32 basepoints0 = CalculatePctN(GetMaxHealth(), SpellMgr::CalculateSpellEffectAmount(dummySpell, 1));
                    CastCustomSpell(this, 70845, &basepoints0, NULL, NULL, true);
                    break;
                }
            }
        }
    }
    return false;
}

bool Unit::HandleProcTriggerSpell(Unit *pVictim, uint32 damage, AuraEffect* triggeredByAura, SpellEntry const *procSpell, uint32 procFlags, uint32 procEx, uint32 cooldown)
{
    // Get triggered aura spell info
    SpellEntry const* auraSpellInfo = triggeredByAura->GetSpellProto();

    // Basepoints of trigger aura
    int32 triggerAmount = triggeredByAura->GetAmount();

    // Set trigger spell id, target, custom basepoints
    uint32 trigger_spell_id = auraSpellInfo->EffectTriggerSpell[triggeredByAura->GetEffIndex()];

    Unit*  target = NULL;
    int32  basepoints0 = 0;

    if (triggeredByAura->GetAuraType() == SPELL_AURA_PROC_TRIGGER_SPELL_WITH_VALUE)
        basepoints0 = triggerAmount;

    Item* castItem = triggeredByAura->GetBase()->GetCastItemGUID() && GetTypeId() == TYPEID_PLAYER
        ? ToPlayer()->GetItemByGuid(triggeredByAura->GetBase()->GetCastItemGUID()) : NULL;

    // Try handle unknown trigger spells
    if (sSpellStore.LookupEntry(trigger_spell_id) == NULL)
    {
        switch (auraSpellInfo->SpellFamilyName)
        {
            case SPELLFAMILY_GENERIC:
                switch (auraSpellInfo->Id)
                {
                    case 23780:             // Aegis of Preservation (Aegis of Preservation trinket)
                        trigger_spell_id = 23781;
                        break;
                    case 33896:             // Desperate Defense (Stonescythe Whelp, Stonescythe Alpha, Stonescythe Ambusher)
                        trigger_spell_id = 33898;
                        break;
                    case 43820:             // Charm of the Witch Doctor (Amani Charm of the Witch Doctor trinket)
                        // Pct value stored in dummy
                        basepoints0 = pVictim->GetCreateHealth() * SpellMgr::CalculateSpellEffectAmount(auraSpellInfo, 1) / 100;
                        target = pVictim;
                        break;
                    case 57345:             // Darkmoon Card: Greatness
                    {
                        float stat = 0.0f;
                        // strength
                        if (GetStat(STAT_STRENGTH) > stat) { trigger_spell_id = 60229;stat = GetStat(STAT_STRENGTH); }
                        // agility
                        if (GetStat(STAT_AGILITY)  > stat) { trigger_spell_id = 60233;stat = GetStat(STAT_AGILITY);  }
                        // intellect
                        if (GetStat(STAT_INTELLECT)> stat) { trigger_spell_id = 60234;stat = GetStat(STAT_INTELLECT);}
                        // spirit
                        if (GetStat(STAT_SPIRIT)   > stat) { trigger_spell_id = 60235;                               }
                        break;
                    }
                    case 64568:             // Blood Reserve
                    {
                        if (HealthBelowPctDamaged(35, damage))
                        {
                            CastCustomSpell(this, 64569, &triggerAmount, NULL, NULL, true);
                            RemoveAura(64568);
                        }
                        return false;
                    }
                    case 67702:             // Death's Choice, Item - Coliseum 25 Normal Melee Trinket
                    {
                        float stat = 0.0f;
                        // strength
                        if (GetStat(STAT_STRENGTH) > stat) { trigger_spell_id = 67708;stat = GetStat(STAT_STRENGTH); }
                        // agility
                        if (GetStat(STAT_AGILITY)  > stat) { trigger_spell_id = 67703;                               }
                        break;
                    }
                    case 67771:             // Death's Choice (heroic), Item - Coliseum 25 Heroic Melee Trinket
                    {
                        float stat = 0.0f;
                        // strength
                        if (GetStat(STAT_STRENGTH) > stat) { trigger_spell_id = 67773;stat = GetStat(STAT_STRENGTH); }
                        // agility
                        if (GetStat(STAT_AGILITY)  > stat) { trigger_spell_id = 67772;                               }
                        break;
                    }
                    // Mana Drain Trigger
                    case 27522:
                    case 40336:
                    {
                        // On successful melee or ranged attack gain $29471s1 mana and if possible drain $27526s1 mana from the target.
                        if (this && isAlive())
                            CastSpell(this, 29471, true, castItem, triggeredByAura);
                        if (pVictim && pVictim->isAlive())
                            CastSpell(pVictim, 27526, true, castItem, triggeredByAura);
                        return true;
                    }
                }
                break;
            case SPELLFAMILY_MAGE:
                if (auraSpellInfo->SpellIconID == 2127)     // Blazing Speed
                {
                    switch (auraSpellInfo->Id)
                    {
                        case 31641:  // Rank 1
                        case 31642:  // Rank 2
                            trigger_spell_id = 31643;
                            break;
                        default:
                            sLog->outError("Unit::HandleProcTriggerSpell: Spell %u miss posibly Blazing Speed", auraSpellInfo->Id);
                            return false;
                    }
                }
                break;
            case SPELLFAMILY_WARRIOR:
                if (auraSpellInfo->Id == 50421)             // Scent of Blood
                {
                    CastSpell(this, 50422, true);
                    RemoveAuraFromStack(auraSpellInfo->Id);
                    return false;
                }
                break;
            case SPELLFAMILY_WARLOCK:
            {
                // Drain Soul
                if (auraSpellInfo->SpellFamilyFlags[0] & 0x4000)
                {
                    // Improved Drain Soul
                    Unit::AuraEffectList const& mAddFlatModifier = GetAuraEffectsByType(SPELL_AURA_DUMMY);
                    for (Unit::AuraEffectList::const_iterator i = mAddFlatModifier.begin(); i != mAddFlatModifier.end(); ++i)
                    {
                        if ((*i)->GetMiscValue() == SPELLMOD_CHANCE_OF_SUCCESS && (*i)->GetSpellProto()->SpellIconID == 113)
                        {
                            int32 value2 = CalculateSpellDamage(this, (*i)->GetSpellProto(), 2);
                            basepoints0 = int32(CalculatePctN(GetMaxPower(POWER_MANA), value2));
                            // Drain Soul
                            CastCustomSpell(this, 18371, &basepoints0, NULL, NULL, true, castItem, triggeredByAura);
                            break;
                        }
                    }
                    // Not remove charge (aura removed on death in any cases)
                    // Need for correct work Drain Soul SPELL_AURA_CHANNEL_DEATH_ITEM aura
                    return false;
                }
                // Nether Protection
                else if (auraSpellInfo->SpellIconID == 1985)
                {
                    if (!procSpell)
                        return false;
                    switch(GetFirstSchoolInMask(GetSpellSchoolMask(procSpell)))
                    {
                        case SPELL_SCHOOL_NORMAL:
                            return false;                   // ignore
                        case SPELL_SCHOOL_HOLY:   trigger_spell_id = 54370; break;
                        case SPELL_SCHOOL_FIRE:   trigger_spell_id = 54371; break;
                        case SPELL_SCHOOL_NATURE: trigger_spell_id = 54375; break;
                        case SPELL_SCHOOL_FROST:  trigger_spell_id = 54372; break;
                        case SPELL_SCHOOL_SHADOW: trigger_spell_id = 54374; break;
                        case SPELL_SCHOOL_ARCANE: trigger_spell_id = 54373; break;
                        default:
                            return false;
                    }
                }
                break;
            }
            case SPELLFAMILY_PRIEST:
            {
                // Greater Heal Refund
                if (auraSpellInfo->Id == 37594)
                    trigger_spell_id = 37595;
                // Blessed Recovery
                else if (auraSpellInfo->SpellIconID == 1875)
                {
                    switch (auraSpellInfo->Id)
                    {
                        case 27811: trigger_spell_id = 27813; break;
                        case 27815: trigger_spell_id = 27817; break;
                        case 27816: trigger_spell_id = 27818; break;
                        default:
                            sLog->outError("Unit::HandleProcTriggerSpell: Spell %u not handled in BR", auraSpellInfo->Id);
                        return false;
                    }
                    basepoints0 = CalculatePctN(int32(damage), triggerAmount) / 3;
                    target = this;
                    // Add remaining ticks to healing done
                    basepoints0 += GetRemainingPeriodicAmount(GetGUID(), trigger_spell_id, SPELL_AURA_PERIODIC_HEAL);
                }
                break;
            }
            case SPELLFAMILY_DRUID:
            {
                switch (auraSpellInfo->Id)
                {
                    // Druid Forms Trinket
                    case 37336:
                    {
                        switch (GetShapeshiftForm())
                        {
                            case FORM_NONE:     trigger_spell_id = 37344; break;
                            case FORM_CAT:      trigger_spell_id = 37341; break;
                            case FORM_BEAR:
                            case FORM_DIREBEAR: trigger_spell_id = 37340; break;
                            case FORM_TREE:     trigger_spell_id = 37342; break;
                            case FORM_MOONKIN:  trigger_spell_id = 37343; break;
                            default:
                                return false;
                        }
                        break;
                    }
                    // Druid T9 Feral Relic (Lacerate, Swipe, Mangle, and Shred)
                    case 67353:
                    {
                        switch (GetShapeshiftForm())
                        {
                            case FORM_CAT:      trigger_spell_id = 67355; break;
                            case FORM_BEAR:
                            case FORM_DIREBEAR: trigger_spell_id = 67354; break;
                            default:
                                return false;
                        }
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case SPELLFAMILY_HUNTER:
            {
                if (auraSpellInfo->SpellIconID == 3247)     // Piercing Shots
                {
                    switch (auraSpellInfo->Id)
                    {
                        case 53234:  // Rank 1
                        case 53237:  // Rank 2
                        case 53238:  // Rank 3
                            trigger_spell_id = 63468;
                            break;
                        default:
                            sLog->outError("Unit::HandleProcTriggerSpell: Spell %u miss posibly Piercing Shots", auraSpellInfo->Id);
                            return false;
                    }
                    SpellEntry const* TriggerPS = sSpellStore.LookupEntry(trigger_spell_id);
                    if (!TriggerPS)
                        return false;

                    basepoints0 = CalculatePctN(int32(damage), triggerAmount) / (GetSpellMaxDuration(TriggerPS) / TriggerPS->EffectAmplitude[0]);
                    basepoints0 += pVictim->GetRemainingPeriodicAmount(GetGUID(), trigger_spell_id, SPELL_AURA_PERIODIC_DAMAGE);
                    break;
                }
                break;
            }
            case SPELLFAMILY_PALADIN:
            {
                switch (auraSpellInfo->Id)
                {
                    // Healing Discount
                    case 37705:
                    {
                        trigger_spell_id = 37706;
                        target = this;
                        break;
                    }
                    // Soul Preserver
                    case 60510:
                    {
                        trigger_spell_id = 60515;
                        target = this;
                        break;
                    }
                    // Lightning Capacitor
                    case 37657:
                    {
                        if (!pVictim || !pVictim->isAlive())
                            return false;
                        // stacking
                        CastSpell(this, 37658, true, NULL, triggeredByAura);

                        Aura* dummy = GetAura(37658);
                        // release at 3 aura in stack (cont contain in basepoint of trigger aura)
                        if (!dummy || dummy->GetStackAmount() < triggerAmount)
                            return false;

                        RemoveAurasDueToSpell(37658);
                        trigger_spell_id = 37661;
                        target = pVictim;
                        break;
                    }
                    // Thunder Capacitor
                    case 54841:
                    {
                        if (!pVictim || !pVictim->isAlive())
                            return false;
                        // stacking
                        CastSpell(this, 54842, true, NULL, triggeredByAura);

                        // counting
                        Aura* dummy = GetAura(54842);
                        // release at 3 aura in stack (cont contain in basepoint of trigger aura)
                        if (!dummy || dummy->GetStackAmount() < triggerAmount)
                            return false;

                        RemoveAurasDueToSpell(54842);
                        trigger_spell_id = 54843;
                        target = pVictim;
                        break;
                    }
                    //Item - Coliseum 25 Normal Caster Trinket
                    case 67712:
                    {
                        if (!pVictim || !pVictim->isAlive())
                            return false;
                        // stacking
                        CastSpell(this, 67713, true, NULL, triggeredByAura);

                        Aura* dummy = GetAura(67713);
                        // release at 3 aura in stack (cont contain in basepoint of trigger aura)
                        if (!dummy || dummy->GetStackAmount() < triggerAmount)
                            return false;

                        RemoveAurasDueToSpell(67713);
                        trigger_spell_id = 67714;
                        target = pVictim;
                        break;
                    }
                    //Item - Coliseum 25 Heroic Caster Trinket
                    case 67758:
                    {
                        if (!pVictim || !pVictim->isAlive())
                            return false;
                        // stacking
                        CastSpell(this, 67759, true, NULL, triggeredByAura);

                        Aura* dummy = GetAura(67759);
                        // release at 3 aura in stack (cont contain in basepoint of trigger aura)
                        if (!dummy || dummy->GetStackAmount() < triggerAmount)
                            return false;

                        RemoveAurasDueToSpell(67759);
                        trigger_spell_id = 67760;
                        target = pVictim;
                        break;
                    }
                    default:
                        // Illumination
                        if (auraSpellInfo->SpellIconID == 241)
                        {
                            if (!procSpell)
                                return false;
                            // procspell is triggered spell but we need mana cost of original casted spell
                            uint32 originalSpellId = procSpell->Id;
                            // Holy Shock heal
                            if (procSpell->SpellFamilyFlags[1] & 0x00010000)
                            {
                                switch(procSpell->Id)
                                {
                                    case 25914: originalSpellId = 20473; break;
                                    case 25913: originalSpellId = 20929; break;
                                    case 25903: originalSpellId = 20930; break;
                                    case 27175: originalSpellId = 27174; break;
                                    case 33074: originalSpellId = 33072; break;
                                    case 48820: originalSpellId = 48824; break;
                                    case 48821: originalSpellId = 48825; break;
                                    default:
                                        sLog->outError("Unit::HandleProcTriggerSpell: Spell %u not handled in HShock", procSpell->Id);
                                       return false;
                                }
                            }
                            SpellEntry const* originalSpell = sSpellStore.LookupEntry(originalSpellId);
                            if (!originalSpell)
                            {
                                sLog->outError("Unit::HandleProcTriggerSpell: Spell %u unknown but selected as original in Illu", originalSpellId);
                                return false;
                            }
                            // percent stored in effect 1 (class scripts) base points
                            int32 cost = int32(originalSpell->manaCost + CalculatePctU(GetCreateMana(), originalSpell->ManaCostPercentage));
                            basepoints0 = CalculatePctN(cost, SpellMgr::CalculateSpellEffectAmount(auraSpellInfo, 1));
                            trigger_spell_id = 20272;
                            target = this;
                        }
                        break;
                }
                break;
            }
            case SPELLFAMILY_SHAMAN:
            {
                switch (auraSpellInfo->Id)
                {
                    // Lightning Shield (The Ten Storms set)
                    case 23551:
                    {
                        trigger_spell_id = 23552;
                        target = pVictim;
                        break;
                    }
                    // Damage from Lightning Shield (The Ten Storms set)
                    case 23552:
                    {
                        trigger_spell_id = 27635;
                        break;
                    }
                    // Mana Surge (The Earthfury set)
                    case 23572:
                    {
                        if (!procSpell)
                            return false;
                        basepoints0 = int32(CalculatePctN(procSpell->manaCost, 35));
                        trigger_spell_id = 23571;
                        target = this;
                        break;
                    }
                    default:
                    {
                        // Lightning Shield (overwrite non existing triggered spell call in spell.dbc
                        if (auraSpellInfo->SpellFamilyFlags[0] & 0x400)
                        {
                            trigger_spell_id = sSpellMgr->GetSpellWithRank(26364, sSpellMgr->GetSpellRank(auraSpellInfo->Id));
                        }
                        // Nature's Guardian
                        else if (auraSpellInfo->SpellIconID == 2013)
                        {
                            // Check health condition - should drop to less 30% (damage deal after this!)
                            if (!HealthBelowPctDamaged(30, damage))
                                return false;

                             if (pVictim && pVictim->isAlive())
                                 pVictim->getThreatManager().modifyThreatPercent(this, -10);

                            basepoints0 = int32(CountPctFromMaxHealth(triggerAmount));
                            trigger_spell_id = 31616;
                            target = this;
                        }
                    }
                }
                break;
            }
            case SPELLFAMILY_DEATHKNIGHT:
            {
                // Acclimation
                if (auraSpellInfo->SpellIconID == 1930)
                {
                    if (!procSpell)
                        return false;
                    switch(GetFirstSchoolInMask(GetSpellSchoolMask(procSpell)))
                    {
                        case SPELL_SCHOOL_NORMAL:
                            return false;                   // ignore
                        case SPELL_SCHOOL_HOLY:   trigger_spell_id = 50490; break;
                        case SPELL_SCHOOL_FIRE:   trigger_spell_id = 50362; break;
                        case SPELL_SCHOOL_NATURE: trigger_spell_id = 50488; break;
                        case SPELL_SCHOOL_FROST:  trigger_spell_id = 50485; break;
                        case SPELL_SCHOOL_SHADOW: trigger_spell_id = 50489; break;
                        case SPELL_SCHOOL_ARCANE: trigger_spell_id = 50486; break;
                        default:
                            return false;
                    }
                }
                // Blood Presence (Improved)
                else if (auraSpellInfo->Id == 63611)
                {
                    if (GetTypeId() != TYPEID_PLAYER)
                        return false;

                    trigger_spell_id = 50475;
                    basepoints0 = CalculatePctN(int32(damage), triggerAmount);
                }
                break;
            }
            default:
                 break;
        }
    }

    // All ok. Check current trigger spell
    SpellEntry const* triggerEntry = sSpellStore.LookupEntry(trigger_spell_id);
    if (triggerEntry == NULL)
    {
        // Not cast unknown spell
        // sLog->outError("Unit::HandleProcTriggerSpell: Spell %u have 0 in EffectTriggered[%d], not handled custom case?", auraSpellInfo->Id, triggeredByAura->GetEffIndex());
        return false;
    }

    // not allow proc extra attack spell at extra attack
    if (m_extraAttacks && IsSpellHaveEffect(triggerEntry, SPELL_EFFECT_ADD_EXTRA_ATTACKS))
        return false;

    // Custom requirements (not listed in procEx) Warning! damage dealing after this
    // Custom triggered spells
    switch (auraSpellInfo->Id)
    {
        // Persistent Shield (Scarab Brooch trinket)
        // This spell originally trigger 13567 - Dummy Trigger (vs dummy efect)
        case 26467:
        {
            basepoints0 = int32(CalculatePctN(damage, 15));
            target = pVictim;
            trigger_spell_id = 26470;
            break;
        }
        // Unyielding Knights (item exploit 29108\29109)
        case 38164:
        {
            if (!pVictim || pVictim->GetEntry() != 19457)  // Proc only if your target is Grillok
                return false;
            break;
        }
        // Deflection
        case 52420:
        {
            if (!HealthBelowPct(35))
                return false;
            break;
        }

        // Cheat Death
        case 28845:
        {
            // When your health drops below 20%
            if (HealthBelowPctDamaged(20, damage) || HealthBelowPct(20))
                return false;
            break;
        }
        // Deadly Swiftness (Rank 1)
        case 31255:
        {
            // whenever you deal damage to a target who is below 20% health.
            if (!pVictim || !pVictim->isAlive() || pVictim->HealthAbovePct(20))
                return false;

            target = this;
            trigger_spell_id = 22588;
        }
        // Greater Heal Refund (Avatar Raiment set)
        case 37594:
        {
            if (!pVictim || !pVictim->isAlive())
                return false;

            // Not give if target already have full health
            if (pVictim->IsFullHealth())
                return false;
            // If your Greater Heal brings the target to full health, you gain $37595s1 mana.
            if (pVictim->GetHealth() + damage < pVictim->GetMaxHealth())
                return false;
            break;
        }
        // Bonus Healing (Crystal Spire of Karabor mace)
        case 40971:
        {
            // If your target is below $s1% health
            if (!pVictim || !pVictim->isAlive() || pVictim->HealthAbovePct(triggerAmount))
                return false;
            break;
        }
        // Rapid Recuperation
        case 53228:
        case 53232:
        {
            // This effect only from Rapid Fire (ability cast)
            if (!(procSpell->SpellFamilyFlags[0] & 0x20))
                return false;
            break;
        }
        // Decimation
        case 63156:
        case 63158:
            // Can proc only if target has hp below 35%
            if (!pVictim->HasAuraState(AURA_STATE_HEALTHLESS_35_PERCENT, procSpell, this))
                return false;
            break;
        // Deathbringer Saurfang - Rune of Blood
        case 72408:
            // can proc only if target is marked with rune
            // this should be handled by targetAuraSpell, but because 72408 is not passive
            // one failed proc will remove the entire aura
            if (!pVictim->HasAura(72410))
                return false;
            break;
        // Deathbringer Saurfang - Blood Beast's Blood Link
        case 72176:
            basepoints0 = 3;
            break;
        // Deathbringer Saurfang - Mark of the Fallen Champion
        case 72256:
            // this should be handled by targetAuraSpell, but because 72408 is not passive
            // one failed proc will remove the entire aura
            CastSpell(NULL, trigger_spell_id, true, NULL, triggeredByAura);
            return true;
        case 15337: // Improved Spirit Tap (Rank 1)
        case 15338: // Improved Spirit Tap (Rank 2)
        {
            if (procSpell->SpellFamilyFlags[0] & 0x800000)
                if ((procSpell->Id != 58381) || !roll_chance_i(50))
                    return false;

            target = pVictim;
            break;
        }
        // Professor Putricide - Ooze Spell Tank Protection
        case 71770:
            if (pVictim)
                pVictim->CastSpell(pVictim, trigger_spell_id, true);    // EffectImplicitTarget is self
            return true;
        case 45057: // Evasive Maneuvers (Commendation of Kael`thas trinket)
        case 71634: // Item - Icecrown 25 Normal Tank Trinket 1
        case 71640: // Item - Icecrown 25 Heroic Tank Trinket 1
        case 75475: // Item - Chamber of Aspects 25 Normal Tank Trinket
        case 75481: // Item - Chamber of Aspects 25 Heroic Tank Trinket
        {
            // Procs only if damage takes health below $s1%
            if (!HealthBelowPctDamaged(triggerAmount, damage))
                return false;
            break;
        }
        default:
            break;
    }

    // Sword Specialization
    if (auraSpellInfo->SpellFamilyName == SPELLFAMILY_GENERIC && auraSpellInfo->SpellIconID == 1462 && procSpell)
    {
        if (Player* plr = ToPlayer())
        {
            if (cooldown && plr->HasSpellCooldown(16459))
                return false;

            // this required for attacks like Mortal Strike
            plr->RemoveSpellCooldown(procSpell->Id);

            CastSpell(pVictim, procSpell->Id, true);

            if (cooldown)
                plr->AddSpellCooldown(16459, 0, time(NULL) + cooldown);
            return true;
        }
    }

    // Blade Barrier
    if (auraSpellInfo->SpellFamilyName == SPELLFAMILY_DEATHKNIGHT && auraSpellInfo->SpellIconID == 85)
    {
        Player* plr = ToPlayer();
        if (!plr || plr->getClass() != CLASS_DEATH_KNIGHT)
            return false;

        if (!plr->IsBaseRuneSlotsOnCooldown(RUNE_BLOOD))
            return false;
    }

    // Rime
    else if (auraSpellInfo->SpellFamilyName == SPELLFAMILY_DEATHKNIGHT && auraSpellInfo->SpellIconID == 56)
    {
        if (GetTypeId() != TYPEID_PLAYER)
            return false;

        // Howling Blast
        ToPlayer()->RemoveSpellCategoryCooldown(1248, true);
    }

    // Custom basepoints/target for exist spell
    // dummy basepoints or other customs
    switch (trigger_spell_id)
    {
        // Auras which should proc on area aura source (caster in this case):
        // Turn the Tables
        case 52914:
        case 52915:
        case 52910:
        // Honor Among Thieves
        case 52916:
        {
            target = triggeredByAura->GetBase()->GetCaster();
            if (!target)
                return false;

            if (cooldown && target->GetTypeId() == TYPEID_PLAYER && target->ToPlayer()->HasSpellCooldown(trigger_spell_id))
                return false;

            target->CastSpell(target, trigger_spell_id, true, castItem, triggeredByAura);

            if (cooldown && GetTypeId() == TYPEID_PLAYER)
                ToPlayer()->AddSpellCooldown(trigger_spell_id, 0, time(NULL) + cooldown);
            return true;
        }
        // Cast positive spell on enemy target
        case 7099:  // Curse of Mending
        case 39703: // Curse of Mending
        case 29494: // Temptation
        case 20233: // Improved Lay on Hands (cast on target)
        {
            target = pVictim;
            break;
        }
        // Combo points add triggers (need add combopoint only for main target, and after possible combopoints reset)
        case 15250: // Rogue Setup
        {
            // applied only for main target
            if (!pVictim || (GetTypeId() == TYPEID_PLAYER && pVictim != ToPlayer()->GetSelectedUnit()))
                return false;
            break;                                   // continue normal case
        }
        // Finish movies that add combo
        case 14189: // Seal Fate (Netherblade set)
        case 14157: // Ruthlessness
        {
            if (!pVictim || pVictim == this)
                return false;
            // Need add combopoint AFTER finish movie (or they dropped in finish phase)
            break;
        }
        // Item - Druid T10 Balance 2P Bonus
        case 16870:
        {
            if (HasAura(70718))
                CastSpell(this, 70721, true);
            break;
        }
        // Bloodthirst (($m/100)% of max health)
        case 23880:
        {
            basepoints0 = int32(CountPctFromMaxHealth(triggerAmount));
            break;
        }
        // Shamanistic Rage triggered spell
        case 30824:
        {
            basepoints0 = int32(CalculatePctN(GetTotalAttackPowerValue(BASE_ATTACK), triggerAmount));
            break;
        }
        // Enlightenment (trigger only from mana cost spells)
        case 35095:
        {
            if (!procSpell || procSpell->powerType != POWER_MANA || (procSpell->manaCost == 0 && procSpell->ManaCostPercentage == 0 && procSpell->manaCostPerlevel == 0))
                return false;
            break;
        }
        // Demonic Pact
        case 48090:
        {
            // Get talent aura from owner
            if (isPet())
                if (Unit* owner = GetOwner())
                {
                    if (AuraEffect* aurEff = owner->GetDummyAuraEffect(SPELLFAMILY_WARLOCK, 3220, 0))
                    {
                        basepoints0 = int32((aurEff->GetAmount() * owner->SpellBaseDamageBonus(SpellSchoolMask(SPELL_SCHOOL_MASK_MAGIC)) + 100.0f) / 100.0f); // TODO: Is it right?
                        CastCustomSpell(this, trigger_spell_id, &basepoints0, &basepoints0, NULL, true, castItem, triggeredByAura);
                        return true;
                    }
                }
            break;
        }
        // Sword and Board
        case 50227:
        {
            // Remove cooldown on Shield Slam
            if (GetTypeId() == TYPEID_PLAYER)
                ToPlayer()->RemoveSpellCategoryCooldown(1209, true);
            break;
        }
        // Maelstrom Weapon
        case 53817:
        {
            // Item - Shaman T10 Enhancement 4P Bonus
            if (AuraEffect const* aurEff = GetAuraEffect(70832, 0))
                if (Aura const* maelstrom = GetAura(53817))
                    if ((maelstrom->GetStackAmount() == maelstrom->GetSpellProto()->StackAmount) && roll_chance_i(aurEff->GetAmount()))
                        CastSpell(this, 70831, true, castItem, triggeredByAura);

            // have rank dependent proc chance, ignore too often cases
            // PPM = 2.5 * (rank of talent),
            uint32 rank = sSpellMgr->GetSpellRank(auraSpellInfo->Id);
            // 5 rank -> 100% 4 rank -> 80% and etc from full rate
            if (!roll_chance_i(20*rank))
                return false;
            break;
        }
        // Astral Shift
        case 52179:
        {
            if (procSpell == 0 || !(procEx & (PROC_EX_NORMAL_HIT|PROC_EX_CRITICAL_HIT)) || this == pVictim)
                return false;

            // Need stun, fear or silence mechanic
            if (!(GetAllSpellMechanicMask(procSpell) & ((1<<MECHANIC_SILENCE)|(1<<MECHANIC_STUN)|(1<<MECHANIC_FEAR))))
                return false;
            break;
        }
        // Burning Determination
        case 54748:
        {
            if (!procSpell)
                return false;
            // Need Interrupt or Silenced mechanic
            if (!(GetAllSpellMechanicMask(procSpell) & ((1<<MECHANIC_INTERRUPT)|(1<<MECHANIC_SILENCE))))
                return false;
            break;
        }
        // Lock and Load
        case 56453:
        {
            // Proc only from Frost/Freezing trap activation or from Freezing Arrow (the periodic dmg proc handled elsewhere)
            if (!(procFlags & PROC_FLAG_DONE_TRAP_ACTIVATION) || !procSpell || !(procSpell->SchoolMask & SPELL_SCHOOL_MASK_FROST) || !roll_chance_i(triggerAmount))
                return false;
            break;
        }
        // Glyph of Death's Embrace
        case 58679:
        {
            // Proc only from healing part of Death Coil. Check is essential as all Death Coil spells have 0x2000 mask in SpellFamilyFlags
            if (!procSpell || !(procSpell->SpellFamilyName == SPELLFAMILY_DEATHKNIGHT && procSpell->SpellFamilyFlags[0] == 0x80002000))
                return false;
            break;
        }
        // Glyph of Death Grip
        case 58628:
        {
            // remove cooldown of Death Grip
            if (GetTypeId() == TYPEID_PLAYER)
                ToPlayer()->RemoveSpellCooldown(49576, true);
            return true;
        }
        // Savage Defense
        case 62606:
        {
            basepoints0 = CalculatePctF(triggerAmount, GetTotalAttackPowerValue(BASE_ATTACK));
            break;
        }
        // Body and Soul
        case 64128:
        case 65081:
        {
            // Proc only from PW:S cast
            if (!(procSpell->SpellFamilyFlags[0] & 0x00000001))
                return false;
            break;
        }
        // Culling the Herd
        case 70893:
        {
            // check if we're doing a critical hit
            if (!(procSpell->SpellFamilyFlags[1] & 0x10000000) && (procEx != PROC_EX_CRITICAL_HIT) )
                return false;
            // check if we're procced by Claw, Bite or Smack (need to use the spell icon ID to detect it)
            if (!(procSpell->SpellIconID == 262 || procSpell->SpellIconID == 1680 || procSpell->SpellIconID == 473 ))
                return false;
            break;
        }
        // Shadow's Fate (Shadowmourne questline)
        case 71169:
        {
            if (GetTypeId() != TYPEID_PLAYER)
                return false;

            Player* player = ToPlayer();
            if (player->GetQuestStatus(24749) == QUEST_STATUS_INCOMPLETE)       // Unholy Infusion
            {
                if (!player->HasAura(71516) || pVictim->GetEntry() != 36678)    // Shadow Infusion && Professor Putricide
                    return false;
            }
            else if (player->GetQuestStatus(24756) == QUEST_STATUS_INCOMPLETE)  // Blood Infusion
            {
                if (!player->HasAura(72154) || pVictim->GetEntry() != 37955)    // Thirst Quenched && Blood-Queen Lana'thel
                    return false;
            }
            else if (player->GetQuestStatus(24757) == QUEST_STATUS_INCOMPLETE)  // Frost Infusion
            {
                if (!player->HasAura(72290) || pVictim->GetEntry() != 36853)    // Frost-Imbued Blade && Sindragosa
                    return false;
            }
            else if (player->GetQuestStatus(24547) != QUEST_STATUS_INCOMPLETE)  // A Feast of Souls
                return false;

            if (pVictim->GetTypeId() != TYPEID_UNIT)
                return false;
            // critters are not allowed
            if (pVictim->GetCreatureType() == CREATURE_TYPE_CRITTER)
                return false;
            break;
        }
    }

    if (cooldown && GetTypeId() == TYPEID_PLAYER && ToPlayer()->HasSpellCooldown(trigger_spell_id))
        return false;

    // try detect target manually if not set
    if (target == NULL)
        target = !(procFlags & (PROC_FLAG_DONE_SPELL_MAGIC_DMG_CLASS_POS | PROC_FLAG_DONE_SPELL_NONE_DMG_CLASS_POS)) && IsPositiveSpell(trigger_spell_id) ? this : pVictim;

    // default case
    if ((!target && !sSpellMgr->IsSrcTargetSpell(triggerEntry)) || (target && target != this && !target->isAlive()))
        return false;

    if (basepoints0)
        CastCustomSpell(target, trigger_spell_id, &basepoints0, NULL, NULL, true, castItem, triggeredByAura);
    else
        CastSpell(target, trigger_spell_id, true, castItem, triggeredByAura);

    if (cooldown && GetTypeId() == TYPEID_PLAYER)
        ToPlayer()->AddSpellCooldown(trigger_spell_id, 0, time(NULL) + cooldown);

    return true;
}

bool Unit::HandleOverrideClassScriptAuraProc(Unit *pVictim, uint32 /*damage*/, AuraEffect *triggeredByAura, SpellEntry const *procSpell, uint32 cooldown)
{
    int32 scriptId = triggeredByAura->GetMiscValue();

    if (!pVictim || !pVictim->isAlive())
        return false;

    Item* castItem = triggeredByAura->GetBase()->GetCastItemGUID() && GetTypeId() == TYPEID_PLAYER
        ? ToPlayer()->GetItemByGuid(triggeredByAura->GetBase()->GetCastItemGUID()) : NULL;

    uint32 triggered_spell_id = 0;

    switch(scriptId)
    {
        case 836:                                           // Improved Blizzard (Rank 1)
        {
            if (!procSpell || procSpell->SpellVisual[0] != 9487)
                return false;
            triggered_spell_id = 12484;
            break;
        }
        case 988:                                           // Improved Blizzard (Rank 2)
        {
            if (!procSpell || procSpell->SpellVisual[0] != 9487)
                return false;
            triggered_spell_id = 12485;
            break;
        }
        case 989:                                           // Improved Blizzard (Rank 3)
        {
            if (!procSpell || procSpell->SpellVisual[0] != 9487)
                return false;
            triggered_spell_id = 12486;
            break;
        }
        case 4533:                                          // Dreamwalker Raiment 2 pieces bonus
        {
            // Chance 50%
            if (!roll_chance_i(50))
                return false;

            switch (pVictim->getPowerType())
            {
                case POWER_MANA:   triggered_spell_id = 28722; break;
                case POWER_RAGE:   triggered_spell_id = 28723; break;
                case POWER_ENERGY: triggered_spell_id = 28724; break;
                default:
                    return false;
            }
            break;
        }
        case 4537:                                          // Dreamwalker Raiment 6 pieces bonus
            triggered_spell_id = 28750;                     // Blessing of the Claw
            break;
        case 5497:                                          // Improved Mana Gems
            triggered_spell_id = 37445;                     // Mana Surge
            break;
        case 7010:  // Revitalize - can proc on full hp target
        case 7011:
        case 7012:
        {
            if (!roll_chance_i(triggeredByAura->GetAmount()))
                return false;
            switch(pVictim->getPowerType())
            {
                case POWER_MANA:   triggered_spell_id = 48542; break;
                case POWER_RAGE:   triggered_spell_id = 48541; break;
                case POWER_ENERGY: triggered_spell_id = 48540; break;
                case POWER_RUNIC_POWER: triggered_spell_id = 48543; break;
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }

    // not processed
    if (!triggered_spell_id)
        return false;

    // standard non-dummy case
    SpellEntry const* triggerEntry = sSpellStore.LookupEntry(triggered_spell_id);

    if (!triggerEntry)
    {
        sLog->outError("Unit::HandleOverrideClassScriptAuraProc: Spell %u triggering for class script id %u", triggered_spell_id, scriptId);
        return false;
    }

    if (cooldown && GetTypeId() == TYPEID_PLAYER && ToPlayer()->HasSpellCooldown(triggered_spell_id))
        return false;

    CastSpell(pVictim, triggered_spell_id, true, castItem, triggeredByAura);

    if (cooldown && GetTypeId() == TYPEID_PLAYER)
        ToPlayer()->AddSpellCooldown(triggered_spell_id, 0, time(NULL) + cooldown);

    return true;
}

void Unit::setPowerType(Powers new_powertype)
{
    SetByteValue(UNIT_FIELD_BYTES_0, 3, new_powertype);

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

    switch(new_powertype)
    {
        default:
        case POWER_MANA:
            break;
        case POWER_RAGE:
            SetMaxPower(POWER_RAGE, GetCreatePowers(POWER_RAGE));
            SetPower(POWER_RAGE, 0);
            break;
        case POWER_FOCUS:
            SetMaxPower(POWER_FOCUS, GetCreatePowers(POWER_FOCUS));
            SetPower(POWER_FOCUS, GetCreatePowers(POWER_FOCUS));
            break;
        case POWER_ENERGY:
            SetMaxPower(POWER_ENERGY, GetCreatePowers(POWER_ENERGY));
            break;
        case POWER_HAPPINESS:
            SetMaxPower(POWER_HAPPINESS, GetCreatePowers(POWER_HAPPINESS));
            SetPower(POWER_HAPPINESS, GetCreatePowers(POWER_HAPPINESS));
            break;
    }
}

FactionTemplateEntry const* Unit::getFactionTemplateEntry() const
{
    FactionTemplateEntry const* entry = sFactionTemplateStore.LookupEntry(getFaction());
    if (!entry)
    {
        static uint64 guid = 0;                             // prevent repeating spam same faction problem

        if (GetGUID() != guid)
        {
            if (Player const* player = ToPlayer())
                sLog->outError("Player %s has invalid faction (faction template id) #%u", player->GetName(), getFaction());
            else if (Creature const* creature = ToCreature())
                sLog->outError("Creature (template id: %u) has invalid faction (faction template id) #%u", creature->GetCreatureInfo()->Entry, getFaction());
            else
                sLog->outError("Unit (name=%s, type=%u) has invalid faction (faction template id) #%u", GetName(), uint32(GetTypeId()), getFaction());

            guid = GetGUID();
        }
    }
    return entry;
}

bool Unit::IsHostileTo(Unit const* unit) const
{
    if (!unit)
        return false;
    // always non-hostile to self
    if (unit == this)
        return false;

    // always non-hostile to GM in GM mode
    if (unit->GetTypeId() == TYPEID_PLAYER && ((Player const*)unit)->isGameMaster())
        return false;

    // always hostile to enemy
    if (getVictim() == unit || unit->getVictim() == this)
        return true;

    // test pet/charm masters instead pers/charmeds
    Unit const* testerOwner = GetCharmerOrOwner();
    Unit const* targetOwner = unit->GetCharmerOrOwner();

    // always hostile to owner's enemy
    if (testerOwner && (testerOwner->getVictim() == unit || unit->getVictim() == testerOwner))
        return true;

    // always hostile to enemy owner
    if (targetOwner && (getVictim() == targetOwner || targetOwner->getVictim() == this))
        return true;

    // always hostile to owner of owner's enemy
    if (testerOwner && targetOwner && (testerOwner->getVictim() == targetOwner || targetOwner->getVictim() == testerOwner))
        return true;

    Unit const* tester = testerOwner ? testerOwner : this;
    Unit const* target = targetOwner ? targetOwner : unit;

    // always non-hostile to target with common owner, or to owner/pet
    if (tester == target)
        return false;

    // special cases (Duel, etc)
    if (tester->GetTypeId() == TYPEID_PLAYER && target->GetTypeId() == TYPEID_PLAYER)
    {
        Player const* pTester = (Player const*)tester;
        Player const* pTarget = (Player const*)target;

        // Duel
        if (pTester->duel && pTester->duel->opponent == pTarget && pTester->duel->startTime != 0)
            return true;

        // Group
        if (pTester->GetGroup() && pTester->GetGroup() == pTarget->GetGroup())
            return false;

        // Sanctuary
        if (pTarget->HasByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_SANCTUARY) && pTester->HasByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_SANCTUARY))
            return false;

        // PvP FFA state
        if (pTester->HasByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP) && pTarget->HasByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP))
            return true;

        //= PvP states
        // Green/Blue (can't attack)
        if (!pTester->HasAuraType(SPELL_AURA_MOD_FACTION) && !pTarget->HasAuraType(SPELL_AURA_MOD_FACTION))
        {
            if (pTester->GetTeam() == pTarget->GetTeam())
                return false;

            // Red (can attack) if true, Blue/Yellow (can't attack) in another case
            return pTester->IsPvP() && pTarget->IsPvP();
        }
    }

    // faction base cases
    FactionTemplateEntry const*tester_faction = tester->getFactionTemplateEntry();
    FactionTemplateEntry const*target_faction = target->getFactionTemplateEntry();
    if (!tester_faction || !target_faction)
        return false;

    if (target->isAttackingPlayer() && tester->IsContestedGuard())
        return true;

    // PvC forced reaction and reputation case
    if (tester->GetTypeId() == TYPEID_PLAYER && !tester->HasAuraType(SPELL_AURA_MOD_FACTION))
    {
        // forced reaction
        if (target_faction->faction)
        {
            if (ReputationRank const* force = tester->ToPlayer()->GetReputationMgr().GetForcedRankIfAny(target_faction))
                return *force <= REP_HOSTILE;

            // if faction have reputation then hostile state for tester at 100% dependent from at_war state
            if (FactionEntry const* raw_target_faction = sFactionStore.LookupEntry(target_faction->faction))
                if (FactionState const* factionState = tester->ToPlayer()->GetReputationMgr().GetState(raw_target_faction))
                    return (factionState->Flags & FACTION_FLAG_AT_WAR);
        }
    }
    // CvP forced reaction and reputation case
    else if (target->GetTypeId() == TYPEID_PLAYER && !target->HasAuraType(SPELL_AURA_MOD_FACTION))
    {
        // forced reaction
        if (tester_faction->faction)
        {
            if (ReputationRank const* force = target->ToPlayer()->GetReputationMgr().GetForcedRankIfAny(tester_faction))
                return *force <= REP_HOSTILE;

            // apply reputation state
            FactionEntry const* raw_tester_faction = sFactionStore.LookupEntry(tester_faction->faction);
            if (raw_tester_faction && raw_tester_faction->reputationListID >= 0)
                return ((Player const*)target)->GetReputationMgr().GetRank(raw_tester_faction) <= REP_HOSTILE;
        }
    }

    // common faction based case (CvC, PvC, CvP)
    return tester_faction->IsHostileTo(*target_faction);
}

bool Unit::IsFriendlyTo(Unit const* unit) const
{
    // always friendly to self
    if (unit == this)
        return true;

    // always friendly to GM in GM mode
    if (unit->GetTypeId() == TYPEID_PLAYER && ((Player const*)unit)->isGameMaster())
        return true;

    // always non-friendly to enemy
    if (getVictim() == unit || unit->getVictim() == this)
        return false;

    // test pet/charm masters instead pers/charmeds
    Unit const* testerOwner = GetCharmerOrOwner();
    Unit const* targetOwner = unit->GetCharmerOrOwner();

    // always non-friendly to owner's enemy
    if (testerOwner && (testerOwner->getVictim() == unit || unit->getVictim() == testerOwner))
        return false;

    // always non-friendly to enemy owner
    if (targetOwner && (getVictim() == targetOwner || targetOwner->getVictim() == this))
        return false;

    // always non-friendly to owner of owner's enemy
    if (testerOwner && targetOwner && (testerOwner->getVictim() == targetOwner || targetOwner->getVictim() == testerOwner))
        return false;

    Unit const* tester = testerOwner ? testerOwner : this;
    Unit const* target = targetOwner ? targetOwner : unit;

    // always friendly to target with common owner, or to owner/pet
    if (tester == target)
        return true;

    // special cases (Duel)
    if (tester->GetTypeId() == TYPEID_PLAYER && target->GetTypeId() == TYPEID_PLAYER)
    {
        Player const* pTester = (Player const*)tester;
        Player const* pTarget = (Player const*)target;

        // Duel
        if (pTester->duel && pTester->duel->opponent == target && pTester->duel->startTime != 0)
            return false;

        // Group
        if (pTester->GetGroup() && pTester->GetGroup() == pTarget->GetGroup())
            return true;

        // Sanctuary
        if (pTarget->HasByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_SANCTUARY) && pTester->HasByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_SANCTUARY))
            return true;

        // PvP FFA state
        if (pTester->HasByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP) && pTarget->HasByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP))
            return false;

        //= PvP states
        // Green/Blue (non-attackable)
        if (!pTester->HasAuraType(SPELL_AURA_MOD_FACTION) && !pTarget->HasAuraType(SPELL_AURA_MOD_FACTION))
        {
            if (pTester->GetTeam() == pTarget->GetTeam())
                return true;

            // Blue (friendly/non-attackable) if not PVP, or Yellow/Red in another case (attackable)
            return !pTarget->IsPvP();
        }
    }

    // faction base cases
    FactionTemplateEntry const* tester_faction = tester->getFactionTemplateEntry();
    FactionTemplateEntry const* target_faction = target->getFactionTemplateEntry();
    if (!tester_faction || !target_faction)
        return false;

    if (target->isAttackingPlayer() && tester->IsContestedGuard())
        return false;

    // PvC forced reaction and reputation case
    if (tester->GetTypeId() == TYPEID_PLAYER && !tester->HasAuraType(SPELL_AURA_MOD_FACTION))
    {
        // forced reaction
        if (target_faction->faction)
        {
            if (ReputationRank const* force = tester->ToPlayer()->GetReputationMgr().GetForcedRankIfAny(target_faction))
                return *force >= REP_FRIENDLY;

            // if faction have reputation then friendly state for tester at 100% dependent from at_war state
            if (FactionEntry const* raw_target_faction = sFactionStore.LookupEntry(target_faction->faction))
                if (FactionState const* factionState = tester->ToPlayer()->GetReputationMgr().GetState(raw_target_faction))
                    return !(factionState->Flags & FACTION_FLAG_AT_WAR);
        }
    }
    // CvP forced reaction and reputation case
    else if (target->GetTypeId() == TYPEID_PLAYER && !target->HasAuraType(SPELL_AURA_MOD_FACTION))
    {
        // forced reaction
        if (tester_faction->faction)
        {
            if (ReputationRank const* force = target->ToPlayer()->GetReputationMgr().GetForcedRankIfAny(tester_faction))
                return *force >= REP_FRIENDLY;

            // apply reputation state
            if (FactionEntry const* raw_tester_faction = sFactionStore.LookupEntry(tester_faction->faction))
                if (raw_tester_faction->reputationListID >= 0)
                    return ((Player const*)target)->GetReputationMgr().GetRank(raw_tester_faction) >= REP_FRIENDLY;
        }
    }

    // common faction based case (CvC, PvC, CvP)
    return tester_faction->IsFriendlyTo(*target_faction);
}

bool Unit::IsHostileToPlayers() const
{
    FactionTemplateEntry const* my_faction = getFactionTemplateEntry();
    if (!my_faction || !my_faction->faction)
        return false;

    FactionEntry const* raw_faction = sFactionStore.LookupEntry(my_faction->faction);
    if (raw_faction && raw_faction->reputationListID >= 0)
        return false;

    return my_faction->IsHostileToPlayers();
}

bool Unit::IsNeutralToAll() const
{
    FactionTemplateEntry const* my_faction = getFactionTemplateEntry();
    if (!my_faction || !my_faction->faction)
        return true;

    FactionEntry const* raw_faction = sFactionStore.LookupEntry(my_faction->faction);
    if (raw_faction && raw_faction->reputationListID >= 0)
        return false;

    return my_faction->IsNeutralToAll();
}

bool Unit::Attack(Unit* victim, bool meleeAttack)
{
    if (!victim || victim == this)
        return false;

    // dead units can neither attack nor be attacked
    if (!isAlive() || !victim->IsInWorld() || !victim->isAlive())
        return false;

    // player cannot attack in mount state
    if (GetTypeId() == TYPEID_PLAYER && IsMounted())
        return false;

    // nobody can attack GM in GM-mode
    if (victim->GetTypeId() == TYPEID_PLAYER)
    {
        if (victim->ToPlayer()->isGameMaster())
            return false;
    }
    else
    {
        if (victim->ToCreature()->IsInEvadeMode())
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
                if (!HasUnitState(UNIT_STAT_MELEE_ATTACKING))
                {
                    AddUnitState(UNIT_STAT_MELEE_ATTACKING);
                    SendMeleeAttackStart(victim);
                    return true;
                }
            }
            else if (HasUnitState(UNIT_STAT_MELEE_ATTACKING))
            {
                ClearUnitState(UNIT_STAT_MELEE_ATTACKING);
                SendMeleeAttackStop(victim);
                return true;
            }
            return false;
        }

        // switch target
        InterruptSpell(CURRENT_MELEE_SPELL);
        if (!meleeAttack)
            ClearUnitState(UNIT_STAT_MELEE_ATTACKING);
    }

    if (m_attacking)
        m_attacking->_removeAttacker(this);

    m_attacking = victim;
    m_attacking->_addAttacker(this);

    // Set our target
    SetUInt64Value(UNIT_FIELD_TARGET, victim->GetGUID());

    if (meleeAttack)
        AddUnitState(UNIT_STAT_MELEE_ATTACKING);

    // set position before any AI calls/assistance
    //if (GetTypeId() == TYPEID_UNIT)
    //    ToCreature()->SetCombatStartPosition(GetPositionX(), GetPositionY(), GetPositionZ());

    if (GetTypeId() == TYPEID_UNIT && !ToCreature()->isPet())
    {
        // should not let player enter combat by right clicking target - doesn't helps
        SetInCombatWith(victim);
        if (victim->GetTypeId() == TYPEID_PLAYER)
            victim->SetInCombatWith(this);
        AddThreat(victim, 0.0f);

        ToCreature()->SendAIReaction(AI_REACTION_HOSTILE);
        ToCreature()->CallAssistance();
    }

    // delay offhand weapon attack to next attack time
    if (haveOffhandWeapon())
        resetAttackTimer(OFF_ATTACK);

    if (meleeAttack)
        SendMeleeAttackStart(victim);

    return true;
}

bool Unit::AttackStop()
{
    if (!m_attacking)
        return false;

    Unit* victim = m_attacking;

    m_attacking->_removeAttacker(this);
    m_attacking = NULL;

    // Clear our target
    SetUInt64Value(UNIT_FIELD_TARGET, 0);

    ClearUnitState(UNIT_STAT_MELEE_ATTACKING);

    InterruptSpell(CURRENT_MELEE_SPELL);

    // reset only at real combat stop
    if (Creature* creature = ToCreature())
    {
        creature->SetNoCallAssistance(false);

        if (creature->HasSearchedAssistance())
        {
            creature->SetNoSearchAssistance(false);
            UpdateSpeed(MOVE_RUN, false);
        }
    }

    SendMeleeAttackStop(victim);

    return true;
}

void Unit::CombatStop(bool includingCast)
{
    if (includingCast && IsNonMeleeSpellCasted(false))
        InterruptNonMeleeSpells(false);

    AttackStop();
    RemoveAllAttackers();
    if (GetTypeId() == TYPEID_PLAYER)
        ToPlayer()->SendAttackSwingCancelAttack();     // melee and ranged forced attack cancel
    ClearInCombat();
}

void Unit::CombatStopWithPets(bool includingCast)
{
    CombatStop(includingCast);

    for (ControlList::const_iterator itr = m_Controlled.begin(); itr != m_Controlled.end(); ++itr)
        (*itr)->CombatStop(includingCast);
}

bool Unit::isAttackingPlayer() const
{
    if (HasUnitState(UNIT_STAT_ATTACK_PLAYER))
        return true;

    for (ControlList::const_iterator itr = m_Controlled.begin(); itr != m_Controlled.end(); ++itr)
        if ((*itr)->isAttackingPlayer())
            return true;

    for (uint8 i = 0; i < MAX_SUMMON_SLOT; ++i)
        if (m_SummonSlot[i])
            if (Creature *summon = GetMap()->GetCreature(m_SummonSlot[i]))
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
            sLog->outError("WORLD: Unit has an attacker that isn't attacking it!");
            m_attackers.erase(iter);
        }
    }
}

void Unit::ModifyAuraState(AuraState flag, bool apply)
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
                    if (itr->second->state == PLAYERSPELL_REMOVED || itr->second->disabled)
                        continue;
                    SpellEntry const* spellInfo = sSpellStore.LookupEntry(itr->first);
                    if (!spellInfo || !IsPassiveSpell(itr->first))
                        continue;
                    if (spellInfo->CasterAuraState == uint32(flag))
                        CastSpell(this, itr->first, true, NULL);
                }
            }
            else if (Pet* pet = ToCreature()->ToPet())
            {
                for (PetSpellMap::const_iterator itr = pet->m_spells.begin(); itr != pet->m_spells.end(); ++itr)
                {
                    if (itr->second.state == PETSPELL_REMOVED)
                        continue;
                    SpellEntry const* spellInfo = sSpellStore.LookupEntry(itr->first);
                    if (!spellInfo || !IsPassiveSpell(itr->first))
                        continue;
                    if (spellInfo->CasterAuraState == uint32(flag))
                        CastSpell(this, itr->first, true, NULL);
                }
            }
        }
    }
    else
    {
        if (HasFlag(UNIT_FIELD_AURASTATE, 1<<(flag-1)))
        {
            RemoveFlag(UNIT_FIELD_AURASTATE, 1<<(flag-1));

            if (flag != AURA_STATE_ENRAGE)                  // enrage aura state triggering continues auras
            {
                Unit::AuraApplicationMap& tAuras = GetAppliedAuras();
                for (Unit::AuraApplicationMap::iterator itr = tAuras.begin(); itr != tAuras.end();)
                {
                    SpellEntry const* spellProto = (*itr).second->GetBase()->GetSpellProto();
                    if (spellProto->CasterAuraState == uint32(flag))
                        RemoveAura(itr);
                    else
                        ++itr;
                }
            }
        }
    }
}

uint32 Unit::BuildAuraStateUpdateForTarget(Unit* target) const
{
    uint32 auraStates = GetUInt32Value(UNIT_FIELD_AURASTATE) &~(PER_CASTER_AURA_STATE_MASK);
    for (AuraStateAurasMap::const_iterator itr = m_auraStateAuras.begin(); itr != m_auraStateAuras.end(); ++itr)
        if ((1<<(itr->first-1)) & PER_CASTER_AURA_STATE_MASK)
            if (itr->second->GetBase()->GetCasterGUID() == target->GetGUID())
                auraStates |= (1<<(itr->first-1));

    return auraStates;
}

bool Unit::HasAuraState(AuraState flag, SpellEntry const *spellProto, Unit const* Caster) const
{
    if (Caster)
    {
        if (spellProto)
        {
            AuraEffectList const& stateAuras = Caster->GetAuraEffectsByType(SPELL_AURA_ABILITY_IGNORE_AURASTATE);
            for (AuraEffectList::const_iterator j = stateAuras.begin(); j != stateAuras.end(); ++j)
                if ((*j)->IsAffectedOnSpell(spellProto))
                    return true;
        }
        // Check per caster aura state
        // If aura with aurastate by caster not found return false
        if ((1<<(flag-1)) & PER_CASTER_AURA_STATE_MASK)
        {
            for (AuraStateAurasMap::const_iterator itr = m_auraStateAuras.lower_bound(flag); itr != m_auraStateAuras.upper_bound(flag); ++itr)
                if (itr->second->GetBase()->GetCasterGUID() == Caster->GetGUID())
                    return true;
            return false;
        }
    }

    return HasFlag(UNIT_FIELD_AURASTATE, 1<<(flag-1));
}

Unit *Unit::GetOwner() const
{
    if (uint64 ownerid = GetOwnerGUID())
    {
        return ObjectAccessor::GetUnit(*this, ownerid);
    }
    return NULL;
}

Unit *Unit::GetCharmer() const
{
    if (uint64 charmerid = GetCharmerGUID())
        return ObjectAccessor::GetUnit(*this, charmerid);
    return NULL;
}

Player* Unit::GetCharmerOrOwnerPlayerOrPlayerItself() const
{
    uint64 guid = GetCharmerOrOwnerGUID();
    if (IS_PLAYER_GUID(guid))
        return ObjectAccessor::GetPlayer(*this, guid);

    return GetTypeId() == TYPEID_PLAYER ? (Player*)this : NULL;
}

Minion *Unit::GetFirstMinion() const
{
    if (uint64 pet_guid = GetMinionGUID())
    {
        if (Creature* pet = ObjectAccessor::GetCreatureOrPetOrVehicle(*this, pet_guid))
            if (pet->HasUnitTypeMask(UNIT_MASK_MINION))
                return (Minion*)pet;

        sLog->outError("Unit::GetFirstMinion: Minion %u not exist.", GUID_LOPART(pet_guid));
        const_cast<Unit*>(this)->SetMinionGUID(0);
    }

    return NULL;
}

Guardian* Unit::GetGuardianPet() const
{
    if (uint64 pet_guid = GetPetGUID())
    {
        if (Creature* pet = ObjectAccessor::GetCreatureOrPetOrVehicle(*this, pet_guid))
            if (pet->HasUnitTypeMask(UNIT_MASK_GUARDIAN))
                return (Guardian*)pet;

        sLog->outCrash("Unit::GetGuardianPet: Guardian " UI64FMTD " not exist.", pet_guid);
        const_cast<Unit*>(this)->SetPetGUID(0);
    }

    return NULL;
}

Unit* Unit::GetCharm() const
{
    if (uint64 charm_guid = GetCharmGUID())
    {
        if (Unit* pet = ObjectAccessor::GetUnit(*this, charm_guid))
            return pet;

        sLog->outError("Unit::GetCharm: Charmed creature %u not exist.", GUID_LOPART(charm_guid));
        const_cast<Unit*>(this)->SetUInt64Value(UNIT_FIELD_CHARM, 0);
    }

    return NULL;
}

void Unit::SetMinion(Minion *minion, bool apply)
{
    sLog->outDebug(LOG_FILTER_UNITS, "SetMinion %u for %u, apply %u", minion->GetEntry(), GetEntry(), apply);

    if (apply)
    {
        if (!minion->AddUInt64Value(UNIT_FIELD_SUMMONEDBY, GetGUID()))
        {
            sLog->outCrash("SetMinion: Minion %u is not the minion of owner %u", minion->GetEntry(), GetEntry());
            return;
        }

        m_Controlled.insert(minion);

        if (GetTypeId() == TYPEID_PLAYER)
        {
            minion->m_ControlledByPlayer = true;
            minion->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP_ATTACKABLE);
        }

        // Can only have one pet. If a new one is summoned, dismiss the old one.
        if (minion->IsGuardianPet())
        {
            if (Guardian* oldPet = GetGuardianPet())
            {
                if (oldPet != minion && (oldPet->isPet() || minion->isPet() || oldPet->GetEntry() != minion->GetEntry()))
                {
                    // remove existing minion pet
                    if (oldPet->isPet())
                        ((Pet*)oldPet)->Remove(PET_SAVE_AS_CURRENT);
                    else
                        oldPet->UnSummon();
                    SetPetGUID(minion->GetGUID());
                    SetMinionGUID(0);
                }
            }
            else
            {
                SetPetGUID(minion->GetGUID());
                SetMinionGUID(0);
            }
        }

        if (minion->HasUnitTypeMask(UNIT_MASK_CONTROLABLE_GUARDIAN))
        {
            if (AddUInt64Value(UNIT_FIELD_SUMMON, minion->GetGUID()))
            {
            }
        }

        if (minion->m_Properties && minion->m_Properties->Type == SUMMON_TYPE_MINIPET)
        {
            SetCritterGUID(minion->GetGUID());
        }

        // PvP, FFAPvP
        minion->SetByteValue(UNIT_FIELD_BYTES_2, 1, GetByteValue(UNIT_FIELD_BYTES_2, 1));

        // FIXME: hack, speed must be set only at follow
        if (GetTypeId() == TYPEID_PLAYER && minion->isPet())
            for (uint8 i = 0; i < MAX_MOVE_TYPE; ++i)
                minion->SetSpeed(UnitMoveType(i), m_speed_rate[i], true);

        // Ghoul pets have energy instead of mana (is anywhere better place for this code?)
        if (minion->IsPetGhoul())
            minion->setPowerType(POWER_ENERGY);

        if (GetTypeId() == TYPEID_PLAYER)
        {
            // Send infinity cooldown - client does that automatically but after relog cooldown needs to be set again
            SpellEntry const* spellInfo = sSpellStore.LookupEntry(minion->GetUInt32Value(UNIT_CREATED_BY_SPELL));
            if (spellInfo && (spellInfo->Attributes & SPELL_ATTR0_DISABLED_WHILE_ACTIVE))
                ToPlayer()->AddSpellAndCategoryCooldowns(spellInfo, 0, NULL, true);
        }
    }
    else
    {
        if (minion->GetOwnerGUID() != GetGUID())
        {
            sLog->outCrash("SetMinion: Minion %u is not the minion of owner %u", minion->GetEntry(), GetEntry());
            return;
        }

        m_Controlled.erase(minion);

        if (minion->m_Properties && minion->m_Properties->Type == SUMMON_TYPE_MINIPET)
        {
            if (GetCritterGUID() == minion->GetGUID())
                SetCritterGUID(0);
        }

        if (minion->IsGuardianPet())
        {
            if (GetPetGUID() == minion->GetGUID())
                SetPetGUID(0);
        }
        else if (minion->isTotem())
        {
            // All summoned by totem minions must disappear when it is removed.
        if (SpellEntry const* spInfo = sSpellStore.LookupEntry(minion->ToTotem()->GetSpell()))
            for (int i = 0; i < MAX_SPELL_EFFECTS; ++i)
            {
                if (spInfo->Effect[i] != SPELL_EFFECT_SUMMON)
                    continue;

                RemoveAllMinionsByEntry(spInfo->EffectMiscValue[i]);
            }
        }

        if (GetTypeId() == TYPEID_PLAYER)
        {
            SpellEntry const* spellInfo = sSpellStore.LookupEntry(minion->GetUInt32Value(UNIT_CREATED_BY_SPELL));
            // Remove infinity cooldown
            if (spellInfo && (spellInfo->Attributes & SPELL_ATTR0_DISABLED_WHILE_ACTIVE))
                ToPlayer()->SendCooldownEvent(spellInfo);
        }

        //if (minion->HasUnitTypeMask(UNIT_MASK_GUARDIAN))
        {
            if (RemoveUInt64Value(UNIT_FIELD_SUMMON, minion->GetGUID()))
            {
                //Check if there is another minion
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
                        ASSERT(false);
                    }
                    ASSERT((*itr)->GetTypeId() == TYPEID_UNIT);

                    if (!(*itr)->HasUnitTypeMask(UNIT_MASK_CONTROLABLE_GUARDIAN))
                        continue;

                    if (AddUInt64Value(UNIT_FIELD_SUMMON, (*itr)->GetGUID()))
                    {
                        // show another pet bar if there is no charm bar
                        if (GetTypeId() == TYPEID_PLAYER && !GetCharmGUID())
                        {
                            if ((*itr)->isPet())
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
}

void Unit::GetAllMinionsByEntry(std::list<Creature*>& Minions, uint32 entry)
{
    for (Unit::ControlList::iterator itr = m_Controlled.begin(); itr != m_Controlled.end();)
    {
        Unit* unit = *itr;
        ++itr;
        if (unit->GetEntry() == entry && unit->GetTypeId() == TYPEID_UNIT
            && unit->ToCreature()->isSummon()) // minion, actually
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
            && unit->ToCreature()->isSummon()) // minion, actually
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
            if (!AddUInt64Value(UNIT_FIELD_CHARM, charm->GetGUID()))
                sLog->outCrash("Player %s is trying to charm unit %u, but it already has a charmed unit " UI64FMTD "", GetName(), charm->GetEntry(), GetCharmGUID());

            charm->m_ControlledByPlayer = true;
            // TODO: maybe we can use this flag to check if controlled by player
            charm->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP_ATTACKABLE);
        }
        else
            charm->m_ControlledByPlayer = false;

        // PvP, FFAPvP
        charm->SetByteValue(UNIT_FIELD_BYTES_2, 1, GetByteValue(UNIT_FIELD_BYTES_2, 1));

        if (!charm->AddUInt64Value(UNIT_FIELD_CHARMEDBY, GetGUID()))
            sLog->outCrash("Unit %u is being charmed, but it already has a charmer " UI64FMTD "", charm->GetEntry(), charm->GetCharmerGUID());

        if (charm->HasUnitMovementFlag(MOVEMENTFLAG_WALKING))
        {
            charm->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
            charm->SendMovementFlagUpdate();
        }

        m_Controlled.insert(charm);
    }
    else
    {
        if (GetTypeId() == TYPEID_PLAYER)
        {
            if (!RemoveUInt64Value(UNIT_FIELD_CHARM, charm->GetGUID()))
                sLog->outCrash("Player %s is trying to uncharm unit %u, but it has another charmed unit " UI64FMTD "", GetName(), charm->GetEntry(), GetCharmGUID());
        }

        if (!charm->RemoveUInt64Value(UNIT_FIELD_CHARMEDBY, GetGUID()))
            sLog->outCrash("Unit %u is being uncharmed, but it has another charmer " UI64FMTD "", charm->GetEntry(), charm->GetCharmerGUID());

        if (charm->GetTypeId() == TYPEID_PLAYER)
        {
            charm->m_ControlledByPlayer = true;
            charm->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP_ATTACKABLE);
            charm->ToPlayer()->UpdatePvPState();
        }
        else if (Player* player = charm->GetCharmerOrOwnerPlayerOrPlayerItself())
        {
            charm->m_ControlledByPlayer = true;
            charm->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP_ATTACKABLE);
            charm->SetByteValue(UNIT_FIELD_BYTES_2, 1, player->GetByteValue(UNIT_FIELD_BYTES_2, 1));
        }
        else
        {
            charm->m_ControlledByPlayer = false;
            charm->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP_ATTACKABLE);
            charm->SetByteValue(UNIT_FIELD_BYTES_2, 1, 0);
        }

        if (charm->GetTypeId() == TYPEID_PLAYER
            || !charm->ToCreature()->HasUnitTypeMask(UNIT_MASK_MINION)
            || charm->GetOwnerGUID() != GetGUID())
            m_Controlled.erase(charm);
    }
}

int32 Unit::DealHeal(Unit *pVictim, uint32 addhealth)
{
    int32 gain = 0;

    if (pVictim->IsAIEnabled)
        pVictim->GetAI()->HealReceived(this, addhealth);

    if (IsAIEnabled)
        GetAI()->HealDone(pVictim, addhealth);

    if (addhealth)
        gain = pVictim->ModifyHealth(int32(addhealth));

    Unit* unit = this;

    if (GetTypeId() == TYPEID_UNIT && ToCreature()->isTotem())
        unit = GetOwner();

    if (unit->GetTypeId() == TYPEID_PLAYER)
    {
        if (Battleground *bg = unit->ToPlayer()->GetBattleground())
            bg->UpdatePlayerScore((Player*)unit, SCORE_HEALING_DONE, gain);

        // use the actual gain, as the overheal shall not be counted, skip gain 0 (it ignored anyway in to criteria)
        if (gain)
            unit->ToPlayer()->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_HEALING_DONE, gain, 0, pVictim);

        unit->ToPlayer()->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HEAL_CASTED, addhealth);
    }

    if (pVictim->GetTypeId() == TYPEID_PLAYER)
    {
        pVictim->ToPlayer()->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_TOTAL_HEALING_RECEIVED, gain);
        pVictim->ToPlayer()->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HEALING_RECEIVED, addhealth);
    }

    return gain;
}

Unit* Unit::SelectMagnetTarget(Unit* victim, SpellEntry const *spellInfo)
{
    if (!victim)
        return NULL;

    // Magic case
    if (spellInfo && (spellInfo->DmgClass == SPELL_DAMAGE_CLASS_NONE || spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MAGIC))
    {
        // I am not sure if this should be redirected.
        if (spellInfo->DmgClass == SPELL_DAMAGE_CLASS_NONE)
            return victim;

        Unit::AuraEffectList const& magnetAuras = victim->GetAuraEffectsByType(SPELL_AURA_SPELL_MAGNET);
        for (Unit::AuraEffectList::const_iterator itr = magnetAuras.begin(); itr != magnetAuras.end(); ++itr)
            if (Unit* magnet = (*itr)->GetBase()->GetUnitOwner())
                if (magnet->isAlive())
                {
                    (*itr)->GetBase()->DropCharge(AURA_REMOVE_BY_EXPIRE);
                    return magnet;
                }
    }
    // Melee && ranged case
    else
    {
        AuraEffectList const& hitTriggerAuras = victim->GetAuraEffectsByType(SPELL_AURA_ADD_CASTER_HIT_TRIGGER);
        for (AuraEffectList::const_iterator i = hitTriggerAuras.begin(); i != hitTriggerAuras.end(); ++i)
            if (Unit* magnet = (*i)->GetBase()->GetCaster())
                if (magnet->isAlive() && magnet->IsWithinLOSInMap(this))
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
    Unit* unit = GetCharm();
    if (!unit)
        if (uint64 guid = GetUInt64Value(UNIT_FIELD_SUMMON))
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
        else if (target->GetOwnerGUID() == GetGUID() && target->isSummon())
            target->ToTempSummon()->UnSummon();
        else
            sLog->outError("Unit %u is trying to release unit %u which is neither charmed nor owned by it", GetEntry(), target->GetEntry());
    }
    if (GetPetGUID())
        sLog->outCrash("Unit %u is not able to release its pet " UI64FMTD, GetEntry(), GetPetGUID());
    if (GetMinionGUID())
        sLog->outCrash("Unit %u is not able to release its minion " UI64FMTD, GetEntry(), GetMinionGUID());
    if (GetCharmGUID())
        sLog->outCrash("Unit %u is not able to release its charm " UI64FMTD, GetEntry(), GetCharmGUID());
}

Unit* Unit::GetNextRandomRaidMemberOrPet(float radius)
{
    Player* player = NULL;
    if (GetTypeId() == TYPEID_PLAYER)
        player = ToPlayer();
    // Should we enable this also for charmed units?
    else if (GetTypeId() == TYPEID_UNIT && ToCreature()->isPet())
        player = GetOwner()->ToPlayer();

    if (!player)
        return NULL;
    Group* pGroup = player->GetGroup();
    // When there is no group check pet presence
    if (!pGroup)
    {
        // We are pet now, return owner
        if (player != this)
            return IsWithinDistInMap(player, radius) ? player : NULL;
        Unit* pet = GetGuardianPet();
        // No pet, no group, nothing to return
        if (!pet)
            return NULL;
        // We are owner now, return pet
        return IsWithinDistInMap(pet, radius) ? pet : NULL;
    }

    std::vector<Unit*> nearMembers;
    // reserve place for players and pets because resizing vector every unit push is unefficient (vector is reallocated then)
    nearMembers.reserve(pGroup->GetMembersCount() * 2);

    for (GroupReference *itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
        if (Player* Target = itr->getSource())
        {
            // IsHostileTo check duel and controlled by enemy
            if (Target != this && Target->isAlive() && IsWithinDistInMap(Target, radius) && !IsHostileTo(Target))
                nearMembers.push_back(Target);

        // Push player's pet to vector
        if (Unit* pet = Target->GetGuardianPet())
            if (pet != this && pet->isAlive() && IsWithinDistInMap(pet, radius) && !IsHostileTo(pet))
                nearMembers.push_back(pet);
        }

    if (nearMembers.empty())
        return NULL;

    uint32 randTarget = urand(0, nearMembers.size()-1);
    return nearMembers[randTarget];
}

// only called in Player::SetSeer
// so move it to Player?
void Unit::AddPlayerToVision(Player* plr)
{
    if (m_sharedVision.empty())
    {
        setActive(true);
        SetWorldObject(true);
    }
    m_sharedVision.push_back(plr);
}

// only called in Player::SetSeer
void Unit::RemovePlayerFromVision(Player* plr)
{
    m_sharedVision.remove(plr);
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

        if (Creature *OldTotem = GetMap()->GetCreature(m_SummonSlot[i]))
            if (OldTotem->isSummon())
                OldTotem->ToTempSummon()->UnSummon();
    }
}

void Unit::SendHealSpellLog(Unit *pVictim, uint32 SpellID, uint32 Damage, uint32 OverHeal, uint32 Absorb, bool critical)
{
    // we guess size
    WorldPacket data(SMSG_SPELLHEALLOG, (8+8+4+4+4+4+1+1));
    data.append(pVictim->GetPackGUID());
    data.append(GetPackGUID());
    data << uint32(SpellID);
    data << uint32(Damage);
    data << uint32(OverHeal);
    data << uint32(Absorb); // Absorb amount
    data << uint8(critical ? 1 : 0);
    data << uint8(0); // unused
    SendMessageToSet(&data, true);
}

int32 Unit::HealBySpell(Unit* pVictim, SpellEntry const* spellInfo, uint32 addHealth, bool critical)
{
    uint32 absorb = 0;
    // calculate heal absorb and reduce healing
    CalcHealAbsorb(pVictim, spellInfo, addHealth, absorb);

    int32 gain = DealHeal(pVictim, addHealth);
    SendHealSpellLog(pVictim, spellInfo->Id, addHealth, uint32(addHealth - gain), absorb, critical);
    return gain;
}

void Unit::SendEnergizeSpellLog(Unit *pVictim, uint32 SpellID, uint32 Damage, Powers powertype)
{
    WorldPacket data(SMSG_SPELLENERGIZELOG, (8+8+4+4+4+1));
    data.append(pVictim->GetPackGUID());
    data.append(GetPackGUID());
    data << uint32(SpellID);
    data << uint32(powertype);
    data << uint32(Damage);
    SendMessageToSet(&data, true);
}

void Unit::EnergizeBySpell(Unit *pVictim, uint32 SpellID, uint32 Damage, Powers powertype)
{
    SendEnergizeSpellLog(pVictim, SpellID, Damage, powertype);
    // needs to be called after sending spell log
    pVictim->ModifyPower(powertype, Damage);
}

uint32 Unit::SpellDamageBonus(Unit *pVictim, SpellEntry const *spellProto, uint32 pdamage, DamageEffectType damagetype, uint32 stack)
{
    if (!spellProto || !pVictim || damagetype == DIRECT_DAMAGE)
        return pdamage;

    // For totems get damage bonus from owner
    if (GetTypeId() == TYPEID_UNIT && ToCreature()->isTotem())
        if (Unit* owner = GetOwner())
            return owner->SpellDamageBonus(pVictim, spellProto, pdamage, damagetype);

    // Taken/Done total percent damage auras
    float DoneTotalMod = 1.0f;
    float ApCoeffMod = 1.0f;
    int32 DoneTotal = 0;
    int32 TakenTotal = 0;

    // ..done
    // Pet damage?
    if (GetTypeId() == TYPEID_UNIT && !ToCreature()->isPet())
        DoneTotalMod *= ToCreature()->GetSpellDamageMod(ToCreature()->GetCreatureInfo()->rank);

    if (spellProto)
    {
        AuraEffectList const& mModDamagePercentDone = GetAuraEffectsByType(SPELL_AURA_MOD_DAMAGE_PERCENT_DONE);
        for (AuraEffectList::const_iterator i = mModDamagePercentDone.begin(); i != mModDamagePercentDone.end(); ++i)
            if ((*i)->GetMiscValue() & GetSpellSchoolMask(spellProto))
            {
                if ((*i)->GetSpellProto()->EquippedItemClass == -1)
                {
                    AddPctN(DoneTotalMod, (*i)->GetAmount());
                }
                else if (!((*i)->GetSpellProto()->AttributesEx5 & SPELL_ATTR5_SPECIAL_ITEM_CLASS_CHECK))
                {
                    if ((*i)->GetSpellProto()->EquippedItemClass & spellProto->EquippedItemClass)
                        if (((*i)->GetSpellProto()->EquippedItemSubClassMask == 0) ||
                            ((*i)->GetSpellProto()->EquippedItemSubClassMask & spellProto->EquippedItemSubClassMask))
                            AddPctN(DoneTotalMod, (*i)->GetAmount());
                }
                else if (ToPlayer() && ToPlayer()->HasItemFitToSpellRequirements((*i)->GetSpellProto()))
                    AddPctN(DoneTotalMod, (*i)->GetAmount());
            }
    }

    uint32 creatureTypeMask = pVictim->GetCreatureTypeMask();
    // Add flat bonus from spell damage versus
    DoneTotal += GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_FLAT_SPELL_DAMAGE_VERSUS, creatureTypeMask);
    AuraEffectList const& mDamageDoneVersus = GetAuraEffectsByType(SPELL_AURA_MOD_DAMAGE_DONE_VERSUS);
    for (AuraEffectList::const_iterator i = mDamageDoneVersus.begin(); i != mDamageDoneVersus.end(); ++i)
        if (creatureTypeMask & uint32((*i)->GetMiscValue()))
            AddPctN(DoneTotalMod, (*i)->GetAmount());

    // bonus against aurastate
    AuraEffectList const& mDamageDoneVersusAurastate = GetAuraEffectsByType(SPELL_AURA_MOD_DAMAGE_DONE_VERSUS_AURASTATE);
    for (AuraEffectList::const_iterator i = mDamageDoneVersusAurastate.begin(); i != mDamageDoneVersusAurastate.end(); ++i)
        if (pVictim->HasAuraState(AuraState((*i)->GetMiscValue())))
            AddPctN(DoneTotalMod, (*i)->GetAmount());

    // done scripted mod (take it from owner)
    Unit* owner = GetOwner() ? GetOwner() : this;
    AuraEffectList const& mOverrideClassScript= owner->GetAuraEffectsByType(SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
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
                if (pVictim->HasAuraState(AURA_STATE_HEALTHLESS_35_PERCENT, spellProto, this))
                    AddPctN(DoneTotalMod, (*i)->GetAmount());
                break;
            }
            // Soul Siphon
            case 4992:
            case 4993:
            {
                // effect 1 m_amount
                int32 maxPercent = (*i)->GetAmount();
                // effect 0 m_amount
                int32 stepPercent = CalculateSpellDamage(this, (*i)->GetSpellProto(), 0);
                // count affliction effects and calc additional damage in percentage
                int32 modPercent = 0;
                AuraApplicationMap const& victimAuras = pVictim->GetAppliedAuras();
                for (AuraApplicationMap::const_iterator itr = victimAuras.begin(); itr != victimAuras.end(); ++itr)
                {
                    Aura const* aura = itr->second->GetBase();
                    SpellEntry const* m_spell = aura->GetSpellProto();
                    if (m_spell->SpellFamilyName != SPELLFAMILY_WARLOCK || !(m_spell->SpellFamilyFlags[1] & 0x0004071B || m_spell->SpellFamilyFlags[0] & 0x8044C402))
                        continue;
                    modPercent += stepPercent * aura->GetStackAmount();
                    if (modPercent >= maxPercent)
                    {
                        modPercent = maxPercent;
                        break;
                    }
                }
                AddPctN(DoneTotalMod, modPercent);
                break;
            }
            case 6916: // Death's Embrace
            case 6925:
            case 6927:
                if (HasAuraState(AURA_STATE_HEALTHLESS_20_PERCENT, spellProto, this))
                    AddPctN(DoneTotalMod, (*i)->GetAmount());
                break;
            case 5481: // Starfire Bonus
            {
                if (pVictim->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DRUID, 0x200002, 0, 0))
                    AddPctN(DoneTotalMod, (*i)->GetAmount());
                break;
            }
            case 4418: // Increased Shock Damage
            case 4554: // Increased Lightning Damage
            case 4555: // Improved Moonfire
            case 5142: // Increased Lightning Damage
            case 5147: // Improved Consecration / Libram of Resurgence
            case 5148: // Idol of the Shooting Star
            case 6008: // Increased Lightning Damage
            case 8627: // Totem of Hex
            {
                DoneTotal += (*i)->GetAmount();
                break;
            }
            // Tundra Stalker
            // Merciless Combat
            case 7277:
            {
                // Merciless Combat
                if ((*i)->GetSpellProto()->SpellIconID == 2656)
                {
                    if (!pVictim->HealthAbovePct(35))
                        AddPctN(DoneTotalMod, (*i)->GetAmount());
                }
                // Tundra Stalker
                else
                {
                    // Frost Fever (target debuff)
                    if (pVictim->HasAura(55095))
                        AddPctN(DoneTotalMod, (*i)->GetAmount());
                    break;
                }
                break;
            }
            // Rage of Rivendare
            case 7293:
            {
                if (pVictim->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DEATHKNIGHT, 0, 0x02000000, 0))
                {
                    if (SpellChainNode const* chain = sSpellMgr->GetSpellChainNode((*i)->GetId()))
                        AddPctF(DoneTotalMod, chain->rank * 2.0f);
                }
                break;
            }
            // Twisted Faith
            case 7377:
            {
                if (pVictim->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_PRIEST, 0x8000, 0, 0, GetGUID()))
                    AddPctN(DoneTotalMod, (*i)->GetAmount());
                break;
            }
            // Marked for Death
            case 7598:
            case 7599:
            case 7600:
            case 7601:
            case 7602:
            {
                if (pVictim->GetAuraEffect(SPELL_AURA_MOD_STALKED, SPELLFAMILY_HUNTER, 0x400, 0, 0))
                    AddPctN(DoneTotalMod, (*i)->GetAmount());
                break;
            }
        }
    }

    // Custom scripted damage
    switch(spellProto->SpellFamilyName)
    {
        case SPELLFAMILY_MAGE:
            // Ice Lance
            if (spellProto->SpellIconID == 186)
            {
                if (pVictim->HasAuraState(AURA_STATE_FROZEN, spellProto, this))
                {
                    // Glyph of Ice Lance
                    if (owner->HasAura(56377) && pVictim->getLevel() > owner->getLevel())
                        DoneTotalMod *= 4.0f;
                    else
                        DoneTotalMod *= 3.0f;
                }
            }

            // Torment the weak
            if (spellProto->SpellFamilyFlags[0] & 0x20600021 || spellProto->SpellFamilyFlags[1] & 0x9000)
                if (pVictim->HasAuraWithMechanic((1<<MECHANIC_SNARE)|(1<<MECHANIC_SLOW_ATTACK)))
                {
                    AuraEffectList const& mDumyAuras = GetAuraEffectsByType(SPELL_AURA_DUMMY);
                    for (AuraEffectList::const_iterator i = mDumyAuras.begin(); i != mDumyAuras.end(); ++i)
                        if ((*i)->GetSpellProto()->SpellIconID == 3263)
                        {
                            AddPctN(DoneTotalMod, (*i)->GetAmount());
                            break;
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
                    if (pVictim->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_PRIEST, 0x8000, 0, 0, GetGUID()))
                        AddPctN(DoneTotalMod, aurEff->GetAmount());

                // Twisted Faith - Mind Flay part
                if (AuraEffect* aurEff = GetAuraEffect(SPELL_AURA_OVERRIDE_CLASS_SCRIPTS, SPELLFAMILY_PRIEST, 2848, 1))
                    // Increase Mind Flay damage if Shadow Word: Pain present on target
                    if (pVictim->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_PRIEST, 0x8000, 0, 0, GetGUID()))
                        AddPctN(DoneTotalMod, aurEff->GetAmount());
            }
            // Smite
            else if (spellProto->SpellFamilyFlags[0] & 0x80)
            {
                // Glyph of Smite
                if (AuraEffect* aurEff = GetAuraEffect(55692, 0))
                    if (pVictim->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_PRIEST, 0x100000, 0, 0, GetGUID()))
                        AddPctN(DoneTotalMod, aurEff->GetAmount());
            }
        break;
        case SPELLFAMILY_PALADIN:
            // Judgement of Vengeance/Judgement of Corruption
            if ((spellProto->SpellFamilyFlags[1] & 0x400000) && spellProto->SpellIconID == 2292)
            {
                // Get stack of Holy Vengeance/Blood Corruption on the target added by caster
                uint32 stacks = 0;
                Unit::AuraEffectList const& auras = pVictim->GetAuraEffectsByType(SPELL_AURA_PERIODIC_DAMAGE);
                for (Unit::AuraEffectList::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
                    if (((*itr)->GetId() == 31803 || (*itr)->GetId() == 53742) && (*itr)->GetCasterGUID() == GetGUID())
                    {
                        stacks = (*itr)->GetBase()->GetStackAmount();
                        break;
                    }
                // + 10% for each application of Holy Vengeance/Blood Corruption on the target
                if (stacks)
                    AddPctU(DoneTotalMod, 10 * stacks);
            }
        break;
        case SPELLFAMILY_DRUID:
            // Thorns
            if (spellProto->SpellFamilyFlags[0] & 0x100)
            {
                // Brambles
                if (AuraEffect* aurEff = GetAuraEffectOfRankedSpell(16836, 0))
                    AddPctN(DoneTotalMod, aurEff->GetAmount());
            }
        break;
        case SPELLFAMILY_WARLOCK:
            // Fire and Brimstone
            if (spellProto->SpellFamilyFlags[1] & 0x00020040)
                if (pVictim->HasAuraState(AURA_STATE_CONFLAGRATE))
                {
                    AuraEffectList const& mDumyAuras = GetAuraEffectsByType(SPELL_AURA_DUMMY);
                    for (AuraEffectList::const_iterator i = mDumyAuras.begin(); i != mDumyAuras.end(); ++i)
                        if ((*i)->GetSpellProto()->SpellIconID == 3173)
                        {
                            AddPctN(DoneTotalMod, (*i)->GetAmount());
                            break;
                        }
                }
            // Drain Soul - increased damage for targets under 25 % HP
            if (spellProto->SpellFamilyFlags[0] & 0x00004000)
                if (HasAura(100001))
                    DoneTotalMod *= 4;
            // Shadow Bite (15% increase from each dot)
            if (spellProto->SpellFamilyFlags[1] & 0x00400000 && isPet())
                if (uint8 count = pVictim->GetDoTsByCaster(GetOwnerGUID()))
                    AddPctN(DoneTotalMod, 15 * count);
        break;
        case SPELLFAMILY_HUNTER:
            // Steady Shot
            if (spellProto->SpellFamilyFlags[1] & 0x1)
                if (AuraEffect* aurEff = GetAuraEffect(56826, 0))  // Glyph of Steady Shot
                    if (pVictim->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_HUNTER, 0x00004000, 0, 0, GetGUID()))
                        AddPctN(DoneTotalMod, aurEff->GetAmount());
        break;
        case SPELLFAMILY_DEATHKNIGHT:
            // Improved Icy Touch
            if (spellProto->SpellFamilyFlags[0] & 0x2)
                if (AuraEffect* aurEff = GetDummyAuraEffect(SPELLFAMILY_DEATHKNIGHT, 2721, 0))
                    AddPctN(DoneTotalMod, aurEff->GetAmount());

            // Sigil of the Vengeful Heart
           if (spellProto->SpellFamilyFlags[0] & 0x2000)
               if (AuraEffect* aurEff = GetAuraEffect(64962, EFFECT_1))
                   AddPctN(DoneTotal, aurEff->GetAmount());

            // Glacier Rot
            if (spellProto->SpellFamilyFlags[0] & 0x2 || spellProto->SpellFamilyFlags[1] & 0x6)
                if (AuraEffect* aurEff = GetDummyAuraEffect(SPELLFAMILY_DEATHKNIGHT, 196, 0))
                    if (pVictim->GetDiseasesByCaster(owner->GetGUID()) > 0)
                        AddPctN(DoneTotalMod, aurEff->GetAmount());

            // Impurity (dummy effect)
            if (GetTypeId() == TYPEID_PLAYER)
            {
                PlayerSpellMap playerSpells = ToPlayer()->GetSpellMap();
                for (PlayerSpellMap::const_iterator itr = playerSpells.begin(); itr != playerSpells.end(); ++itr)
                {
                    if (itr->second->state == PLAYERSPELL_REMOVED || itr->second->disabled)
                        continue;
                    switch (itr->first)
                    {
                        case 49220:
                        case 49633:
                        case 49635:
                        case 49636:
                        case 49638:
                        {
                            if (SpellEntry const* proto = sSpellStore.LookupEntry(itr->first))
                                AddPctN(ApCoeffMod, SpellMgr::CalculateSpellEffectAmount(proto, 0));
                        }
                        break;
                    }
                }
            }
        break;
    }

    // ..taken
    int32 maxPositiveMod = 0; // max of the positive amount aura (that increase the damage taken)
    int32 sumNegativeMod = 0; // sum the negative amount aura (that reduce the damage taken)
    AuraEffectList const& mModDamagePercentTaken = pVictim->GetAuraEffectsByType(SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN);
    for (AuraEffectList::const_iterator i = mModDamagePercentTaken.begin(); i != mModDamagePercentTaken.end(); ++i)
        if ((*i)->GetMiscValue() & GetSpellSchoolMask(spellProto))
        {
            if ((*i)->GetAmount() > 0)
            {
                if ((*i)->GetAmount() > maxPositiveMod)
                    maxPositiveMod = (*i)->GetAmount();
            }
            else
                sumNegativeMod += (*i)->GetAmount();
        }

    // .. taken pct: dummy auras
    AuraEffectList const& mDummyAuras = pVictim->GetAuraEffectsByType(SPELL_AURA_DUMMY);
    for (AuraEffectList::const_iterator i = mDummyAuras.begin(); i != mDummyAuras.end(); ++i)
    {
        switch((*i)->GetSpellProto()->SpellIconID)
        {
            // Cheat Death
            case 2109:
                if ((*i)->GetMiscValue() & SPELL_SCHOOL_MASK_NORMAL)
                {
                    if (pVictim->GetTypeId() != TYPEID_PLAYER)
                        continue;
                    float mod = pVictim->ToPlayer()->GetRatingBonusValue(CR_CRIT_TAKEN_MELEE) * (-8.0f);
                    if (mod < (*i)->GetAmount())
                        mod = (float)(*i)->GetAmount();
                    sumNegativeMod += int32(mod);
                }
                break;
            // Ebon Plague
            case 1933:
                if ((*i)->GetMiscValue() & (spellProto ? GetSpellSchoolMask(spellProto) : 0))
                {
                    if ((*i)->GetAmount() > maxPositiveMod)
                        maxPositiveMod = (*i)->GetAmount();
                }
                break;
        }
    }

    // From caster spells
    AuraEffectList const& mOwnerTaken = pVictim->GetAuraEffectsByType(SPELL_AURA_MOD_DAMAGE_FROM_CASTER);
    for (AuraEffectList::const_iterator i = mOwnerTaken.begin(); i != mOwnerTaken.end(); ++i)
        if ((*i)->GetCasterGUID() == GetGUID() && (*i)->IsAffectedOnSpell(spellProto))
            sumNegativeMod += (*i)->GetAmount();

    // Mod damage from spell mechanic
    if (uint32 mechanicMask = GetAllSpellMechanicMask(spellProto))
    {
        AuraEffectList const& mDamageDoneMechanic = pVictim->GetAuraEffectsByType(SPELL_AURA_MOD_MECHANIC_DAMAGE_TAKEN_PERCENT);
        for (AuraEffectList::const_iterator i = mDamageDoneMechanic.begin(); i != mDamageDoneMechanic.end(); ++i)
            if (mechanicMask & uint32(1<<((*i)->GetMiscValue())))
                sumNegativeMod += (*i)->GetAmount();
    }

    float TakenTotalMod = (sumNegativeMod + maxPositiveMod + 100.0f) / 100.0f;

    // Taken/Done fixed damage bonus auras
    int32 DoneAdvertisedBenefit  = SpellBaseDamageBonus(GetSpellSchoolMask(spellProto));
    int32 TakenAdvertisedBenefit = SpellBaseDamageBonusForVictim(GetSpellSchoolMask(spellProto), pVictim);
    // Pets just add their bonus damage to their spell damage
    // note that their spell damage is just gain of their own auras
    if (HasUnitTypeMask(UNIT_MASK_GUARDIAN))
        DoneAdvertisedBenefit += ((Guardian*)this)->GetBonusDamage();

    // Check for table values
    float coeff = 0;
    SpellBonusEntry const* bonus = sSpellMgr->GetSpellBonusData(spellProto->Id);
    if (bonus)
    {
        if (damagetype == DOT)
        {
            coeff = bonus->dot_damage;
            if (bonus->ap_dot_bonus > 0)
            {
                WeaponAttackType attType = (IsRangedWeaponSpell(spellProto) && spellProto->DmgClass != SPELL_DAMAGE_CLASS_MELEE) ? RANGED_ATTACK : BASE_ATTACK;
                float APbonus = (float) pVictim->GetTotalAuraModifier(attType == BASE_ATTACK ? SPELL_AURA_MELEE_ATTACK_POWER_ATTACKER_BONUS : SPELL_AURA_RANGED_ATTACK_POWER_ATTACKER_BONUS);
                APbonus += GetTotalAttackPowerValue(attType);
                DoneTotal += int32(bonus->ap_dot_bonus * stack * ApCoeffMod * APbonus);
            }
        }
        else
        {
            coeff = bonus->direct_damage;
            if (bonus->ap_bonus > 0)
            {
                WeaponAttackType attType = (IsRangedWeaponSpell(spellProto) && spellProto->DmgClass != SPELL_DAMAGE_CLASS_MELEE) ? RANGED_ATTACK : BASE_ATTACK;
                float APbonus = (float) pVictim->GetTotalAuraModifier(attType == BASE_ATTACK ? SPELL_AURA_MELEE_ATTACK_POWER_ATTACKER_BONUS : SPELL_AURA_RANGED_ATTACK_POWER_ATTACKER_BONUS);
                APbonus += GetTotalAttackPowerValue(attType);
                DoneTotal += int32(bonus->ap_bonus * stack * ApCoeffMod * APbonus);
            }
        }
    }
    // Default calculation
    if (DoneAdvertisedBenefit || TakenAdvertisedBenefit)
    {
        if (!bonus || coeff < 0)
        {
            // Damage Done from spell damage bonus
            int32 CastingTime = IsChanneledSpell(spellProto) ? GetSpellDuration(spellProto) : GetSpellCastTime(spellProto);
            // Damage over Time spells bonus calculation
            float DotFactor = 1.0f;
            if (damagetype == DOT)
            {
                int32 DotDuration = GetSpellDuration(spellProto);
                // 200% limit
                if (DotDuration > 0)
                {
                    if (DotDuration > 30000)
                        DotDuration = 30000;
                    if (!IsChanneledSpell(spellProto))
                        DotFactor = DotDuration / 15000.0f;
                    uint8 x = 0;
                    for (uint8 j = 0; j < MAX_SPELL_EFFECTS; ++j)
                    {
                        if (spellProto->Effect[j] == SPELL_EFFECT_APPLY_AURA && (
                            spellProto->EffectApplyAuraName[j] == SPELL_AURA_PERIODIC_DAMAGE ||
                            spellProto->EffectApplyAuraName[j] == SPELL_AURA_PERIODIC_LEECH))
                        {
                            x = j;
                            break;
                        }
                    }
                    int32 DotTicks = 6;
                    if (spellProto->EffectAmplitude[x] != 0)
                        DotTicks = DotDuration / spellProto->EffectAmplitude[x];
                    if (DotTicks)
                    {
                        DoneAdvertisedBenefit /= DotTicks;
                        TakenAdvertisedBenefit /= DotTicks;
                    }
                }
            }
            // Distribute Damage over multiple effects, reduce by AoE
            CastingTime = GetCastingTimeForBonus(spellProto, damagetype, CastingTime);

            // 50% for damage and healing spells for leech spells from damage bonus and 0% from healing
            for (uint8 j = 0; j < MAX_SPELL_EFFECTS; ++j)
            {
                if (spellProto->Effect[j] == SPELL_EFFECT_HEALTH_LEECH ||
                    (spellProto->Effect[j] == SPELL_EFFECT_APPLY_AURA && spellProto->EffectApplyAuraName[j] == SPELL_AURA_PERIODIC_LEECH))
                {
                    CastingTime /= 2;
                    break;
                }
            }
            if (spellProto->SchoolMask != SPELL_SCHOOL_MASK_NORMAL)
                coeff = (CastingTime / 3500.0f) * DotFactor;
            else
                coeff = DotFactor;
        }

        float coeff2 = CalculateLevelPenalty(spellProto) * stack;
        if (spellProto->SpellFamilyName) // TODO: fix this
            TakenTotal+= int32(TakenAdvertisedBenefit * coeff * coeff2);
        if (Player* modOwner = GetSpellModOwner())
        {
            coeff *= 100.0f;
            modOwner->ApplySpellMod(spellProto->Id, SPELLMOD_BONUS_MULTIPLIER, coeff);
            coeff /= 100.0f;
        }
        DoneTotal += int32(DoneAdvertisedBenefit * coeff * coeff2);
    }

    // Some spells don't benefit from done mods
    if (spellProto->AttributesEx3 & SPELL_ATTR3_NO_DONE_BONUS)
    {
        DoneTotal = 0;
        DoneTotalMod = 1.0f;
    }

    float tmpDamage = (int32(pdamage) + DoneTotal) * DoneTotalMod;
    // apply spellmod to Done damage (flat and pct)
    if (Player* modOwner = GetSpellModOwner())
        modOwner->ApplySpellMod(spellProto->Id, damagetype == DOT ? SPELLMOD_DOT : SPELLMOD_DAMAGE, tmpDamage);

    tmpDamage = (tmpDamage + TakenTotal) * TakenTotalMod;

    return uint32(std::max(tmpDamage, 0.0f));
}

int32 Unit::SpellBaseDamageBonus(SpellSchoolMask schoolMask)
{
    int32 DoneAdvertisedBenefit = 0;

    // ..done
    AuraEffectList const& mDamageDone = GetAuraEffectsByType(SPELL_AURA_MOD_DAMAGE_DONE);
    for (AuraEffectList::const_iterator i = mDamageDone.begin(); i != mDamageDone.end(); ++i)
        if (((*i)->GetMiscValue() & schoolMask) != 0 &&
        (*i)->GetSpellProto()->EquippedItemClass == -1 &&
                                                            // -1 == any item class (not wand then)
        (*i)->GetSpellProto()->EquippedItemInventoryTypeMask == 0)
                                                            // 0 == any inventory type (not wand then)
            DoneAdvertisedBenefit += (*i)->GetAmount();

    if (GetTypeId() == TYPEID_PLAYER)
    {
        // Base value
        DoneAdvertisedBenefit += ToPlayer()->GetBaseSpellPowerBonus();

        // Damage bonus from stats
        AuraEffectList const& mDamageDoneOfStatPercent = GetAuraEffectsByType(SPELL_AURA_MOD_SPELL_DAMAGE_OF_STAT_PERCENT);
        for (AuraEffectList::const_iterator i = mDamageDoneOfStatPercent.begin(); i != mDamageDoneOfStatPercent.end(); ++i)
        {
            if ((*i)->GetMiscValue() & schoolMask)
            {
                // stat used stored in miscValueB for this aura
                Stats usedStat = Stats((*i)->GetMiscValueB());
                DoneAdvertisedBenefit += int32(CalculatePctN(GetStat(usedStat), (*i)->GetAmount()));
            }
        }
        // ... and attack power
        AuraEffectList const& mDamageDonebyAP = GetAuraEffectsByType(SPELL_AURA_MOD_SPELL_DAMAGE_OF_ATTACK_POWER);
        for (AuraEffectList::const_iterator i =mDamageDonebyAP.begin(); i != mDamageDonebyAP.end(); ++i)
            if ((*i)->GetMiscValue() & schoolMask)
                DoneAdvertisedBenefit += int32(CalculatePctN(GetTotalAttackPowerValue(BASE_ATTACK), (*i)->GetAmount()));

    }
    return DoneAdvertisedBenefit > 0 ? DoneAdvertisedBenefit : 0;
}

int32 Unit::SpellBaseDamageBonusForVictim(SpellSchoolMask schoolMask, Unit *pVictim)
{
    uint32 creatureTypeMask = pVictim->GetCreatureTypeMask();

    int32 TakenAdvertisedBenefit = 0;
    // ..done (for creature type by mask) in taken
    AuraEffectList const& mDamageDoneCreature = GetAuraEffectsByType(SPELL_AURA_MOD_DAMAGE_DONE_CREATURE);
    for (AuraEffectList::const_iterator i = mDamageDoneCreature.begin(); i != mDamageDoneCreature.end(); ++i)
        if (creatureTypeMask & uint32((*i)->GetMiscValue()))
            TakenAdvertisedBenefit += (*i)->GetAmount();

    // ..taken
    AuraEffectList const& mDamageTaken = pVictim->GetAuraEffectsByType(SPELL_AURA_MOD_DAMAGE_TAKEN);
    for (AuraEffectList::const_iterator i = mDamageTaken.begin(); i != mDamageTaken.end(); ++i)
        if (((*i)->GetMiscValue() & schoolMask) != 0)
            TakenAdvertisedBenefit += (*i)->GetAmount();

    return TakenAdvertisedBenefit > 0 ? TakenAdvertisedBenefit : 0;
}

bool Unit::isSpellCrit(Unit *pVictim, SpellEntry const *spellProto, SpellSchoolMask schoolMask, WeaponAttackType attackType) const
{
    // Mobs can't crit with spells.
    if (IS_CREATURE_GUID(GetGUID()))
        return false;

    // not critting spell
    if ((spellProto->AttributesEx2 & SPELL_ATTR2_CANT_CRIT))
        return false;

    float crit_chance = 0.0f;
    switch(spellProto->DmgClass)
    {
        case SPELL_DAMAGE_CLASS_NONE:  // Exception for Earth Shield and Lifebloom Final Bloom
            if (spellProto->Id != 379 && spellProto->Id != 33778) // We need more spells to find a general way (if there is any)
                return false;
        case SPELL_DAMAGE_CLASS_MAGIC:
        {
            if (schoolMask & SPELL_SCHOOL_MASK_NORMAL)
                crit_chance = 0.0f;
            // For other schools
            else if (GetTypeId() == TYPEID_PLAYER)
                crit_chance = GetFloatValue(PLAYER_SPELL_CRIT_PERCENTAGE1 + GetFirstSchoolInMask(schoolMask));
            else
            {
                crit_chance = (float)m_baseSpellCritChance;
                crit_chance += GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_SPELL_CRIT_CHANCE_SCHOOL, schoolMask);
            }
            // taken
            if (pVictim)
            {
                if (!IsPositiveSpell(spellProto->Id))
                {
                    // Modify critical chance by victim SPELL_AURA_MOD_ATTACKER_SPELL_CRIT_CHANCE
                    crit_chance += pVictim->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_ATTACKER_SPELL_CRIT_CHANCE, schoolMask);
                    // Modify critical chance by victim SPELL_AURA_MOD_ATTACKER_SPELL_AND_WEAPON_CRIT_CHANCE
                    crit_chance += pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_SPELL_AND_WEAPON_CRIT_CHANCE);
                    ApplyResilience(pVictim, &crit_chance, NULL, false, CR_CRIT_TAKEN_SPELL);
                }
                // scripted (increase crit chance ... against ... target by x%
                AuraEffectList const& mOverrideClassScript = GetAuraEffectsByType(SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
                for (AuraEffectList::const_iterator i = mOverrideClassScript.begin(); i != mOverrideClassScript.end(); ++i)
                {
                    if (!((*i)->IsAffectedOnSpell(spellProto)))
                        continue;
                    int32 modChance = 0;
                    switch((*i)->GetMiscValue())
                    {
                        // Shatter
                        case  911: modChance+= 16;
                        case  910: modChance+= 17;
                        case  849: modChance+= 17;
                            if (!pVictim->HasAuraState(AURA_STATE_FROZEN, spellProto, this))
                                break;
                            crit_chance+=modChance;
                            break;
                        case 7917: // Glyph of Shadowburn
                            if (pVictim->HasAuraState(AURA_STATE_HEALTHLESS_35_PERCENT, spellProto, this))
                                crit_chance+=(*i)->GetAmount();
                            break;
                        case 7997: // Renewed Hope
                        case 7998:
                            if (pVictim->HasAura(6788))
                                crit_chance+=(*i)->GetAmount();
                            break;
                        case   21: // Test of Faith
                        case 6935:
                        case 6918:
                            if (pVictim->HealthBelowPct(50))
                                crit_chance+=(*i)->GetAmount();
                            break;
                        default:
                            break;
                    }
                }
                // Custom crit by class
                switch (spellProto->SpellFamilyName)
                {
                    case SPELLFAMILY_DRUID:
                        // Improved Faerie Fire
                        if (pVictim->HasAuraState(AURA_STATE_FAERIE_FIRE))
                            if (AuraEffect const* aurEff = GetDummyAuraEffect(SPELLFAMILY_DRUID, 109, 0))
                                crit_chance += aurEff->GetAmount();

                        // cumulative effect - don't break

                        // Starfire
                        if (spellProto->SpellFamilyFlags[0] & 0x4 && spellProto->SpellIconID == 1485)
                        {
                            // Improved Insect Swarm
                            if (AuraEffect const* aurEff = GetDummyAuraEffect(SPELLFAMILY_DRUID, 1771, 0))
                                if (pVictim->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DRUID, 0x00000002, 0, 0))
                                    crit_chance += aurEff->GetAmount();
                           break;
                        }
                    break;
                    case SPELLFAMILY_ROGUE:
                        // Shiv-applied poisons can't crit
                        if (FindCurrentSpellBySpellId(5938))
                            crit_chance = 0.0f;
                        break;
                    case SPELLFAMILY_PALADIN:
                        // Flash of light
                        if (spellProto->SpellFamilyFlags[0] & 0x40000000)
                        {
                            // Sacred Shield
                            if (AuraEffect const* aura = pVictim->GetAuraEffect(58597, 1, GetGUID()))
                                crit_chance += aura->GetAmount();
                            break;
                        }
                        // Exorcism
                        else if (spellProto->Category == 19)
                        {
                            if (pVictim->GetCreatureTypeMask() & CREATURE_TYPEMASK_DEMON_OR_UNDEAD)
                                return true;
                            break;
                        }
                    break;
                    case SPELLFAMILY_SHAMAN:
                        // Lava Burst
                        if (spellProto->SpellFamilyFlags[1] & 0x00001000)
                        {
                            if (pVictim->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_SHAMAN, 0x10000000, 0, 0, GetGUID()))
                                if (pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_SPELL_AND_WEAPON_CRIT_CHANCE) > -100)
                                    return true;
                            break;
                        }
                    break;
                }
            }
            break;
        }
        case SPELL_DAMAGE_CLASS_MELEE:
            if (pVictim)
            {
                // Custom crit by class
                switch(spellProto->SpellFamilyName)
                {
                    case SPELLFAMILY_DRUID:
                        // Rend and Tear - bonus crit chance for Ferocious Bite on bleeding targets
                        if (spellProto->SpellFamilyFlags[0] & 0x00800000
                            && spellProto->SpellIconID == 1680
                            && pVictim->HasAuraState(AURA_STATE_BLEEDING))
                        {
                            if (AuraEffect const* rendAndTear = GetDummyAuraEffect(SPELLFAMILY_DRUID, 2859, 1))
                                crit_chance += rendAndTear->GetAmount();
                            break;
                        }
                    break;
                    case SPELLFAMILY_WARRIOR:
                       // Victory Rush
                       if (spellProto->SpellFamilyFlags[1] & 0x100)
                       {
                           // Glyph of Victory Rush
                           if (AuraEffect const* aurEff = GetAuraEffect(58382, 0))
                               crit_chance += aurEff->GetAmount();
                           break;
                       }
                    break;
                }
            }
        case SPELL_DAMAGE_CLASS_RANGED:
        {
            if (pVictim)
            {
                crit_chance += GetUnitCriticalChance(attackType, pVictim);
                crit_chance += GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_SPELL_CRIT_CHANCE_SCHOOL, schoolMask);
            }
            break;
        }
        default:
            return false;
    }
    // percent done
    // only players use intelligence for critical chance computations
    if (Player* modOwner = GetSpellModOwner())
        modOwner->ApplySpellMod(spellProto->Id, SPELLMOD_CRITICAL_CHANCE, crit_chance);

    crit_chance = crit_chance > 0.0f ? crit_chance : 0.0f;
    if (roll_chance_f(crit_chance))
        return true;
    return false;
}

uint32 Unit::SpellCriticalDamageBonus(SpellEntry const *spellProto, uint32 damage, Unit *pVictim)
{
    // Calculate critical bonus
    int32 crit_bonus;
    switch(spellProto->DmgClass)
    {
        case SPELL_DAMAGE_CLASS_MELEE:                      // for melee based spells is 100%
        case SPELL_DAMAGE_CLASS_RANGED:
            // TODO: write here full calculation for melee/ranged spells
            crit_bonus = damage;
            break;
        default:
            crit_bonus = damage / 2;                        // for spells is 50%
            break;
    }

    // adds additional damage to crit_bonus (from talents)
    if (Player* modOwner = GetSpellModOwner())
        modOwner->ApplySpellMod(spellProto->Id, SPELLMOD_CRIT_DAMAGE_BONUS, crit_bonus);

    if (pVictim)
    {
        uint32 creatureTypeMask = pVictim->GetCreatureTypeMask();
        crit_bonus = int32(crit_bonus * GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_CRIT_PERCENT_VERSUS, creatureTypeMask));
    }

    if (crit_bonus > 0)
        damage += crit_bonus;

    return damage;
}

uint32 Unit::SpellCriticalHealingBonus(SpellEntry const *spellProto, uint32 damage, Unit *pVictim)
{
    // Calculate critical bonus
    int32 crit_bonus;
    switch(spellProto->DmgClass)
    {
        case SPELL_DAMAGE_CLASS_MELEE:                      // for melee based spells is 100%
        case SPELL_DAMAGE_CLASS_RANGED:
            // TODO: write here full calculation for melee/ranged spells
            crit_bonus = damage;
            break;
        default:
            crit_bonus = damage / 2;                        // for spells is 50%
            break;
    }

    if (pVictim)
    {
        uint32 creatureTypeMask = pVictim->GetCreatureTypeMask();
        crit_bonus = int32(crit_bonus * GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_CRIT_PERCENT_VERSUS, creatureTypeMask));
    }

    if (crit_bonus > 0)
        damage += crit_bonus;

    damage = int32(float(damage) * GetTotalAuraMultiplier(SPELL_AURA_MOD_CRITICAL_HEALING_AMOUNT));

    return damage;
}

uint32 Unit::SpellHealingBonus(Unit *pVictim, SpellEntry const *spellProto, uint32 healamount, DamageEffectType damagetype, uint32 stack)
{
    // For totems get healing bonus from owner (statue isn't totem in fact)
    if (GetTypeId() == TYPEID_UNIT && ToCreature()->isTotem())
        if (Unit* owner = GetOwner())
            return owner->SpellHealingBonus(pVictim, spellProto, healamount, damagetype, stack);

    // no bonus for heal potions/bandages
    if (spellProto->SpellFamilyName == SPELLFAMILY_POTION)
        return healamount;

    // Healing Done
    // Taken/Done total percent damage auras
    float  DoneTotalMod = 1.0f;
    float  TakenTotalMod = 1.0f;
    int32  DoneTotal = 0;
    int32  TakenTotal = 0;

    // Healing done percent
    AuraEffectList const& mHealingDonePct = GetAuraEffectsByType(SPELL_AURA_MOD_HEALING_DONE_PERCENT);
    for (AuraEffectList::const_iterator i = mHealingDonePct.begin(); i != mHealingDonePct.end(); ++i)
        AddPctN(DoneTotalMod, (*i)->GetAmount());

    // done scripted mod (take it from owner)
    Unit* owner = GetOwner() ? GetOwner() : this;
    AuraEffectList const& mOverrideClassScript= owner->GetAuraEffectsByType(SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
    for (AuraEffectList::const_iterator i = mOverrideClassScript.begin(); i != mOverrideClassScript.end(); ++i)
    {
        if (!(*i)->IsAffectedOnSpell(spellProto))
            continue;
        switch((*i)->GetMiscValue())
        {
            case 4415: // Increased Rejuvenation Healing
            case 4953:
            case 3736: // Hateful Totem of the Third Wind / Increased Lesser Healing Wave / LK Arena (4/5/6) Totem of the Third Wind / Savage Totem of the Third Wind
                DoneTotal += (*i)->GetAmount();
                break;
            case 7997: // Renewed Hope
            case 7998:
                if (pVictim->HasAura(6788))
                    AddPctN(DoneTotalMod, (*i)->GetAmount());
                break;
            case   21: // Test of Faith
            case 6935:
            case 6918:
                if (pVictim->HealthBelowPct(50))
                    AddPctN(DoneTotalMod, (*i)->GetAmount());
                break;
            case 7798: // Glyph of Regrowth
            {
                if (pVictim->GetAuraEffect(SPELL_AURA_PERIODIC_HEAL, SPELLFAMILY_DRUID, 0x40, 0, 0))
                    AddPctN(DoneTotalMod, (*i)->GetAmount());
                break;
            }
            case 8477: // Nourish Heal Boost
            {
                int32 stepPercent = (*i)->GetAmount();
                int32 modPercent = 0;
                AuraApplicationMap const& victimAuras = pVictim->GetAppliedAuras();
                for (AuraApplicationMap::const_iterator itr = victimAuras.begin(); itr != victimAuras.end(); ++itr)
                {
                    Aura const* aura = itr->second->GetBase();
                    if (aura->GetCasterGUID() != GetGUID())
                        continue;
                    SpellEntry const* m_spell = aura->GetSpellProto();
                    if (m_spell->SpellFamilyName != SPELLFAMILY_DRUID ||
                        !(m_spell->SpellFamilyFlags[1] & 0x00000010 || m_spell->SpellFamilyFlags[0] & 0x50))
                        continue;
                    modPercent += stepPercent * aura->GetStackAmount();
                }
                AddPctN(DoneTotalMod, modPercent);
                break;
            }
            case 7871: // Glyph of Lesser Healing Wave
            {
                if (pVictim->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_SHAMAN, 0 , 0x00000400, 0, GetGUID()))
                    AddPctN(DoneTotalMod, (*i)->GetAmount());
                break;
            }
            default:
                break;
        }
    }

    // Taken/Done fixed damage bonus auras
    int32 DoneAdvertisedBenefit  = SpellBaseHealingBonus(GetSpellSchoolMask(spellProto));
    int32 TakenAdvertisedBenefit = SpellBaseHealingBonusForVictim(GetSpellSchoolMask(spellProto), pVictim);

    bool scripted = false;

    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
    {
        switch (spellProto->EffectApplyAuraName[i])
        {
            // These auras do not use healing coeff
            case SPELL_AURA_PERIODIC_LEECH:
            case SPELL_AURA_PERIODIC_HEALTH_FUNNEL:
                scripted = true;
                break;
        }
        if (spellProto->Effect[i] == SPELL_EFFECT_HEALTH_LEECH)
            scripted = true;
    }

    // Check for table values
    SpellBonusEntry const* bonus = !scripted ? sSpellMgr->GetSpellBonusData(spellProto->Id) : NULL;
    float coeff = 0;
    float factorMod = 1.0f;
    if (bonus)
    {
        if (damagetype == DOT)
        {
            coeff = bonus->dot_damage;
            if (bonus->ap_dot_bonus > 0)
                DoneTotal += int32(bonus->ap_dot_bonus * stack * GetTotalAttackPowerValue(
                    (IsRangedWeaponSpell(spellProto) && spellProto->DmgClass !=SPELL_DAMAGE_CLASS_MELEE)? RANGED_ATTACK : BASE_ATTACK));
        }
        else
        {
            coeff = bonus->direct_damage;
            if (bonus->ap_bonus > 0)
                DoneTotal += int32(bonus->ap_bonus * stack * GetTotalAttackPowerValue(
                    (IsRangedWeaponSpell(spellProto) && spellProto->DmgClass !=SPELL_DAMAGE_CLASS_MELEE)? RANGED_ATTACK : BASE_ATTACK));
        }
    }
    else // scripted bonus
    {
        // Gift of the Naaru
        if (spellProto->SpellFamilyFlags[2] & 0x80000000 && spellProto->SpellIconID == 329)
        {
            scripted = true;
            int32 apBonus = int32(std::max(GetTotalAttackPowerValue(BASE_ATTACK), GetTotalAttackPowerValue(RANGED_ATTACK)));
            if (apBonus > DoneAdvertisedBenefit)
                DoneTotal += int32(apBonus * 0.22f); // 22% of AP per tick
            else
                DoneTotal += int32(DoneAdvertisedBenefit * 0.377f); //37.7% of BH per tick
        }
        // Earthliving - 0.45% of normal hot coeff
        else if (spellProto->SpellFamilyName == SPELLFAMILY_SHAMAN && spellProto->SpellFamilyFlags[1] & 0x80000)
            factorMod *= 0.45f;
        // Already set to scripted? so not uses healing bonus coefficient
        // No heal coeff for SPELL_DAMAGE_CLASS_NONE class spells by default
        else if (scripted || spellProto->DmgClass == SPELL_DAMAGE_CLASS_NONE)
        {
            scripted = true;
            coeff = 0.0f;
        }
    }

    // Default calculation
    if (DoneAdvertisedBenefit || TakenAdvertisedBenefit)
    {
        if ((!bonus && !scripted) || coeff < 0)
        {
            // Damage Done from spell damage bonus
            int32 CastingTime = !IsChanneledSpell(spellProto) ? GetSpellCastTime(spellProto) : GetSpellDuration(spellProto);
            // Damage over Time spells bonus calculation
            float DotFactor = 1.0f;
            if (damagetype == DOT)
            {
                int32 DotDuration = GetSpellDuration(spellProto);
                // 200% limit
                if (DotDuration > 0)
                {
                    if (DotDuration > 30000) DotDuration = 30000;
                    if (!IsChanneledSpell(spellProto)) DotFactor = DotDuration / 15000.0f;
                    uint32 x = 0;
                    for (uint8 j = 0; j < MAX_SPELL_EFFECTS; j++)
                    {
                        if (spellProto->Effect[j] == SPELL_EFFECT_APPLY_AURA && (
                            spellProto->EffectApplyAuraName[j] == SPELL_AURA_PERIODIC_DAMAGE ||
                            spellProto->EffectApplyAuraName[j] == SPELL_AURA_PERIODIC_LEECH))
                        {
                            x = j;
                            break;
                        }
                    }
                    int32 DotTicks = 6;
                    if (spellProto->EffectAmplitude[x] != 0)
                        DotTicks = DotDuration / spellProto->EffectAmplitude[x];
                    if (DotTicks)
                    {
                        DoneAdvertisedBenefit = DoneAdvertisedBenefit * int32(stack) / DotTicks;
                        TakenAdvertisedBenefit = TakenAdvertisedBenefit * int32(stack) / DotTicks;
                    }
                }
            }
            // Distribute Damage over multiple effects, reduce by AoE
            CastingTime = GetCastingTimeForBonus(spellProto, damagetype, CastingTime);
            // 50% for damage and healing spells for leech spells from damage bonus and 0% from healing
            for (uint8 j = 0; j < MAX_SPELL_EFFECTS; ++j)
            {
                if (spellProto->Effect[j] == SPELL_EFFECT_HEALTH_LEECH ||
                    (spellProto->Effect[j] == SPELL_EFFECT_APPLY_AURA && spellProto->EffectApplyAuraName[j] == SPELL_AURA_PERIODIC_LEECH))
                {
                    CastingTime /= 2;
                    break;
                }
            }
            // As wowwiki says: C = (Cast Time / 3.5) * 1.88 (for healing spells)
            coeff = (CastingTime / 3500.0f) * DotFactor * 1.88f;
        }

        factorMod *= CalculateLevelPenalty(spellProto) * stack;
        TakenTotal += int32(TakenAdvertisedBenefit * coeff * factorMod);
        if (Player* modOwner = GetSpellModOwner())
        {
            coeff *= 100.0f;
            modOwner->ApplySpellMod(spellProto->Id, SPELLMOD_BONUS_MULTIPLIER, coeff);
            coeff /= 100.0f;
        }
        DoneTotal += int32(DoneAdvertisedBenefit * coeff * factorMod);
    }

    // use float as more appropriate for negative values and percent applying
    float heal = (int32(healamount) + DoneTotal) * DoneTotalMod;
    // apply spellmod to Done amount
    if (Player* modOwner = GetSpellModOwner())
        modOwner->ApplySpellMod(spellProto->Id, damagetype == DOT ? SPELLMOD_DOT : SPELLMOD_DAMAGE, heal);

    // Nourish cast
    if (spellProto->SpellFamilyName == SPELLFAMILY_DRUID && spellProto->SpellFamilyFlags[1] & 0x2000000)
    {
        // Rejuvenation, Regrowth, Lifebloom, or Wild Growth
        if (pVictim->GetAuraEffect(SPELL_AURA_PERIODIC_HEAL, SPELLFAMILY_DRUID, 0x50, 0x4000010, 0))
            // increase healing by 20%
            TakenTotalMod *= 1.2f;
    }

    // Taken mods

    // Tenacity increase healing % taken
    if (AuraEffect const* Tenacity = pVictim->GetAuraEffect(58549, 0))
        AddPctN(TakenTotalMod, Tenacity->GetAmount());

    // Healing taken percent
    float minval = (float)pVictim->GetMaxNegativeAuraModifier(SPELL_AURA_MOD_HEALING_PCT);
    if (minval)
        AddPctF(TakenTotalMod, minval);

    float maxval = (float)pVictim->GetMaxPositiveAuraModifier(SPELL_AURA_MOD_HEALING_PCT);
    if (maxval)
        AddPctF(TakenTotalMod, maxval);

    if (damagetype == DOT)
    {
        // Healing over time taken percent
        float minval_hot = (float)pVictim->GetMaxNegativeAuraModifier(SPELL_AURA_MOD_HOT_PCT);
        if (minval_hot)
            AddPctF(TakenTotalMod, minval_hot);

        float maxval_hot = (float)pVictim->GetMaxPositiveAuraModifier(SPELL_AURA_MOD_HOT_PCT);
        if (maxval_hot)
            AddPctF(TakenTotalMod, maxval_hot);
    }

    AuraEffectList const& mHealingGet= pVictim->GetAuraEffectsByType(SPELL_AURA_MOD_HEALING_RECEIVED);
    for (AuraEffectList::const_iterator i = mHealingGet.begin(); i != mHealingGet.end(); ++i)
        if (GetGUID() == (*i)->GetCasterGUID() && (*i)->IsAffectedOnSpell(spellProto))
            AddPctN(TakenTotalMod, (*i)->GetAmount());

    heal = (int32(heal) + TakenTotal) * TakenTotalMod;

    return uint32(std::max(heal, 0.0f));
}

int32 Unit::SpellBaseHealingBonus(SpellSchoolMask schoolMask)
{
    int32 AdvertisedBenefit = 0;

    AuraEffectList const& mHealingDone = GetAuraEffectsByType(SPELL_AURA_MOD_HEALING_DONE);
    for (AuraEffectList::const_iterator i = mHealingDone.begin(); i != mHealingDone.end(); ++i)
        if (!(*i)->GetMiscValue() || ((*i)->GetMiscValue() & schoolMask) != 0)
            AdvertisedBenefit += (*i)->GetAmount();

    // Healing bonus of spirit, intellect and strength
    if (GetTypeId() == TYPEID_PLAYER)
    {
        // Base value
        AdvertisedBenefit += ToPlayer()->GetBaseSpellPowerBonus();

        // Healing bonus from stats
        AuraEffectList const& mHealingDoneOfStatPercent = GetAuraEffectsByType(SPELL_AURA_MOD_SPELL_HEALING_OF_STAT_PERCENT);
        for (AuraEffectList::const_iterator i = mHealingDoneOfStatPercent.begin(); i != mHealingDoneOfStatPercent.end(); ++i)
        {
            // stat used dependent from misc value (stat index)
            Stats usedStat = Stats((*i)->GetSpellProto()->EffectMiscValue[(*i)->GetEffIndex()]);
            AdvertisedBenefit += int32(CalculatePctN(GetStat(usedStat), (*i)->GetAmount()));
        }

        // ... and attack power
        AuraEffectList const& mHealingDonebyAP = GetAuraEffectsByType(SPELL_AURA_MOD_SPELL_HEALING_OF_ATTACK_POWER);
        for (AuraEffectList::const_iterator i = mHealingDonebyAP.begin(); i != mHealingDonebyAP.end(); ++i)
            if ((*i)->GetMiscValue() & schoolMask)
                AdvertisedBenefit += int32(CalculatePctN(GetTotalAttackPowerValue(BASE_ATTACK), (*i)->GetAmount()));
    }
    return AdvertisedBenefit;
}

int32 Unit::SpellBaseHealingBonusForVictim(SpellSchoolMask schoolMask, Unit *pVictim)
{
    int32 AdvertisedBenefit = 0;
    AuraEffectList const& mDamageTaken = pVictim->GetAuraEffectsByType(SPELL_AURA_MOD_HEALING);
    for (AuraEffectList::const_iterator i = mDamageTaken.begin(); i != mDamageTaken.end(); ++i)
        if (((*i)->GetMiscValue() & schoolMask) != 0)
            AdvertisedBenefit += (*i)->GetAmount();
    return AdvertisedBenefit;
}

bool Unit::IsImmunedToDamage(SpellSchoolMask shoolMask)
{
    // If m_immuneToSchool type contain this school type, IMMUNE damage.
    SpellImmuneList const& schoolList = m_spellImmune[IMMUNITY_SCHOOL];
    for (SpellImmuneList::const_iterator itr = schoolList.begin(); itr != schoolList.end(); ++itr)
        if (itr->type & shoolMask)
            return true;

    // If m_immuneToDamage type contain magic, IMMUNE damage.
    SpellImmuneList const& damageList = m_spellImmune[IMMUNITY_DAMAGE];
    for (SpellImmuneList::const_iterator itr = damageList.begin(); itr != damageList.end(); ++itr)
        if (itr->type & shoolMask)
            return true;

    return false;
}

bool Unit::IsImmunedToDamage(SpellEntry const* spellInfo)
{
    if (spellInfo->Attributes & SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY)
        return false;

    uint32 shoolMask = GetSpellSchoolMask(spellInfo);
    if (spellInfo->Id != 42292 && spellInfo->Id !=59752)
    {
        // If m_immuneToSchool type contain this school type, IMMUNE damage.
        SpellImmuneList const& schoolList = m_spellImmune[IMMUNITY_SCHOOL];
        for (SpellImmuneList::const_iterator itr = schoolList.begin(); itr != schoolList.end(); ++itr)
            if (itr->type & shoolMask && !CanSpellPierceImmuneAura(spellInfo, sSpellStore.LookupEntry(itr->spellId)))
                return true;
    }

    // If m_immuneToDamage type contain magic, IMMUNE damage.
    SpellImmuneList const& damageList = m_spellImmune[IMMUNITY_DAMAGE];
    for (SpellImmuneList::const_iterator itr = damageList.begin(); itr != damageList.end(); ++itr)
        if (itr->type & shoolMask)
            return true;

    return false;
}

bool Unit::IsImmunedToSpell(SpellEntry const* spellInfo)
{
    if (!spellInfo)
        return false;

    // Single spell immunity.
    SpellImmuneList const& idList = m_spellImmune[IMMUNITY_ID];
    for (SpellImmuneList::const_iterator itr = idList.begin(); itr != idList.end(); ++itr)
        if (itr->type == spellInfo->Id)
            return true;

    if (spellInfo->Attributes & SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY)
        return false;

    if (spellInfo->Dispel)
    {
        SpellImmuneList const& dispelList = m_spellImmune[IMMUNITY_DISPEL];
        for (SpellImmuneList::const_iterator itr = dispelList.begin(); itr != dispelList.end(); ++itr)
            if (itr->type == spellInfo->Dispel)
                return true;
    }

    if (spellInfo->Mechanic)
    {
        SpellImmuneList const& mechanicList = m_spellImmune[IMMUNITY_MECHANIC];
        for (SpellImmuneList::const_iterator itr = mechanicList.begin(); itr != mechanicList.end(); ++itr)
            if (itr->type == spellInfo->Mechanic)
                return true;
    }

    for (int i = 0; i < MAX_SPELL_EFFECTS; ++i)
    {
        // State/effect immunities applied by aura expect full spell immunity
        // Ignore effects with mechanic, they are supposed to be checked separately
        if (!spellInfo->EffectMechanic[i])
            if (IsImmunedToSpellEffect(spellInfo, i))
                return true;
    }

    if (spellInfo->Id != 42292 && spellInfo->Id !=59752)
    {
        SpellImmuneList const& schoolList = m_spellImmune[IMMUNITY_SCHOOL];
        for (SpellImmuneList::const_iterator itr = schoolList.begin(); itr != schoolList.end(); ++itr)
            if ((itr->type & GetSpellSchoolMask(spellInfo))
                && !(IsPositiveSpell(itr->spellId) && IsPositiveSpell(spellInfo->Id))
                && !CanSpellPierceImmuneAura(spellInfo, sSpellStore.LookupEntry(itr->spellId)))
                return true;
    }

    return false;
}

bool Unit::IsImmunedToSpellEffect(SpellEntry const* spellInfo, uint32 index) const
{
    if (!spellInfo)
        return false;
    // If m_immuneToEffect type contain this effect type, IMMUNE effect.
    uint32 effect = spellInfo->Effect[index];
    SpellImmuneList const& effectList = m_spellImmune[IMMUNITY_EFFECT];
    for (SpellImmuneList::const_iterator itr = effectList.begin(); itr != effectList.end(); ++itr)
        if (itr->type == effect)
            return true;

    if (uint32 mechanic = spellInfo->EffectMechanic[index])
    {
        SpellImmuneList const& mechanicList = m_spellImmune[IMMUNITY_MECHANIC];
        for (SpellImmuneList::const_iterator itr = mechanicList.begin(); itr != mechanicList.end(); ++itr)
            if (itr->type == mechanic)
                return true;
    }

    if (uint32 aura = spellInfo->EffectApplyAuraName[index])
    {
        SpellImmuneList const& list = m_spellImmune[IMMUNITY_STATE];
        for (SpellImmuneList::const_iterator itr = list.begin(); itr != list.end(); ++itr)
            if (itr->type == aura)
                return true;
        // Check for immune to application of harmful magical effects
        AuraEffectList const& immuneAuraApply = GetAuraEffectsByType(SPELL_AURA_MOD_IMMUNE_AURA_APPLY_SCHOOL);
        for (AuraEffectList::const_iterator iter = immuneAuraApply.begin(); iter != immuneAuraApply.end(); ++iter)
            if (spellInfo->Dispel == DISPEL_MAGIC &&                                      // Magic debuff
                ((*iter)->GetMiscValue() & GetSpellSchoolMask(spellInfo)) &&  // Check school
                !IsPositiveEffect(spellInfo->Id, index))                                  // Harmful
                return true;
    }

    return false;
}

bool Unit::IsDamageToThreatSpell(SpellEntry const* spellInfo) const
{
    if (!spellInfo)
        return false;

    switch(spellInfo->SpellFamilyName)
    {
        case SPELLFAMILY_WARLOCK:
            if (spellInfo->SpellFamilyFlags[0] == 0x100) // Searing Pain
                return true;
            break;
        case SPELLFAMILY_SHAMAN:
            if (spellInfo->SpellFamilyFlags[0] == SPELLFAMILYFLAG_SHAMAN_FROST_SHOCK)
                return true;
            break;
        case SPELLFAMILY_DEATHKNIGHT:
            if (spellInfo->SpellFamilyFlags[1] == 0x20000000) // Rune Strike
                return true;
            break;
    }

    return false;
}

void Unit::MeleeDamageBonus(Unit *pVictim, uint32 *pdamage, WeaponAttackType attType, SpellEntry const *spellProto)
{
    if (!pVictim)
        return;

    if (*pdamage == 0)
        return;

    uint32 creatureTypeMask = pVictim->GetCreatureTypeMask();

    // Taken/Done fixed damage bonus auras
    int32 DoneFlatBenefit = 0;
    int32 TakenFlatBenefit = 0;

    // ..done (for creature type by mask) in taken
    AuraEffectList const& mDamageDoneCreature = GetAuraEffectsByType(SPELL_AURA_MOD_DAMAGE_DONE_CREATURE);
    for (AuraEffectList::const_iterator i = mDamageDoneCreature.begin(); i != mDamageDoneCreature.end(); ++i)
        if (creatureTypeMask & uint32((*i)->GetMiscValue()))
            DoneFlatBenefit += (*i)->GetAmount();

    // ..done
    // SPELL_AURA_MOD_DAMAGE_DONE included in weapon damage

    // ..done (base at attack power for marked target and base at attack power for creature type)
    int32 APbonus = 0;

    if (attType == RANGED_ATTACK)
    {
        APbonus += pVictim->GetTotalAuraModifier(SPELL_AURA_RANGED_ATTACK_POWER_ATTACKER_BONUS);

        // ..done (base at attack power and creature type)
        AuraEffectList const& mCreatureAttackPower = GetAuraEffectsByType(SPELL_AURA_MOD_RANGED_ATTACK_POWER_VERSUS);
        for (AuraEffectList::const_iterator i = mCreatureAttackPower.begin(); i != mCreatureAttackPower.end(); ++i)
            if (creatureTypeMask & uint32((*i)->GetMiscValue()))
                APbonus += (*i)->GetAmount();
    }
    else
    {
        APbonus += pVictim->GetTotalAuraModifier(SPELL_AURA_MELEE_ATTACK_POWER_ATTACKER_BONUS);

        // ..done (base at attack power and creature type)
        AuraEffectList const& mCreatureAttackPower = GetAuraEffectsByType(SPELL_AURA_MOD_MELEE_ATTACK_POWER_VERSUS);
        for (AuraEffectList::const_iterator i = mCreatureAttackPower.begin(); i != mCreatureAttackPower.end(); ++i)
            if (creatureTypeMask & uint32((*i)->GetMiscValue()))
                APbonus += (*i)->GetAmount();
    }

    if (APbonus != 0)                                       // Can be negative
    {
        bool normalized = false;
        if (spellProto)
            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                if (spellProto->Effect[i] == SPELL_EFFECT_NORMALIZED_WEAPON_DMG)
                {
                    normalized = true;
                    break;
                }
        DoneFlatBenefit += int32(APbonus/14.0f * GetAPMultiplier(attType, normalized));
    }

    // ..taken
    AuraEffectList const& mDamageTaken = pVictim->GetAuraEffectsByType(SPELL_AURA_MOD_DAMAGE_TAKEN);
    for (AuraEffectList::const_iterator i = mDamageTaken.begin(); i != mDamageTaken.end(); ++i)
        if ((*i)->GetMiscValue() & GetMeleeDamageSchoolMask())
            TakenFlatBenefit += (*i)->GetAmount();

    if (attType != RANGED_ATTACK)
        TakenFlatBenefit += pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_MELEE_DAMAGE_TAKEN);
    else
        TakenFlatBenefit += pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_RANGED_DAMAGE_TAKEN);

    // Done/Taken total percent damage auras
    float DoneTotalMod = 1.0f;
    float TakenTotalMod = 1.0f;

    // ..done
    AuraEffectList const& mModDamagePercentDone = GetAuraEffectsByType(SPELL_AURA_MOD_DAMAGE_PERCENT_DONE);
    for (AuraEffectList::const_iterator i = mModDamagePercentDone.begin(); i != mModDamagePercentDone.end(); ++i)
        if (spellProto)
        {
                if ((*i)->GetMiscValue() & GetSpellSchoolMask(spellProto))
                {
                    if ((*i)->GetSpellProto()->EquippedItemClass == -1)
                    {
                        AddPctN(DoneTotalMod, (*i)->GetAmount());
                    }
                    else if (!((*i)->GetSpellProto()->AttributesEx5 & SPELL_ATTR5_SPECIAL_ITEM_CLASS_CHECK))
                    {
                        if ((*i)->GetSpellProto()->EquippedItemClass & spellProto->EquippedItemClass)
                            if (((*i)->GetSpellProto()->EquippedItemSubClassMask == 0) ||
                                ((*i)->GetSpellProto()->EquippedItemSubClassMask & spellProto->EquippedItemSubClassMask))
                                AddPctN(DoneTotalMod, (*i)->GetAmount());
                    }
                    else if (ToPlayer() && ToPlayer()->HasItemFitToSpellRequirements((*i)->GetSpellProto()))
                        AddPctN(DoneTotalMod, (*i)->GetAmount());
                }
        }
        else if (ToPlayer())
        {
            if (!((*i)->GetSpellProto()->AttributesEx5 & SPELL_ATTR5_SPECIAL_ITEM_CLASS_CHECK))
            {
                EquipmentSlots slot;

                switch (attType)
                {
                    case BASE_ATTACK:   slot = EQUIPMENT_SLOT_MAINHAND; break;
                    case OFF_ATTACK:    slot = EQUIPMENT_SLOT_OFFHAND;  break;
                    case RANGED_ATTACK: slot = EQUIPMENT_SLOT_RANGED;   break;
                    default: return;
                }

                Item* item = ToPlayer()->GetItemByPos(INVENTORY_SLOT_BAG_0, slot);

                if (item && !item->IsBroken() && item->IsFitToSpellRequirements((*i)->GetSpellProto()))
                    AddPctN(DoneTotalMod, (*i)->GetAmount());
            }
            else if (ToPlayer()->HasItemFitToSpellRequirements((*i)->GetSpellProto()))
                AddPctN(DoneTotalMod, (*i)->GetAmount());
        }

    AuraEffectList const& mDamageDoneVersus = GetAuraEffectsByType(SPELL_AURA_MOD_DAMAGE_DONE_VERSUS);
    for (AuraEffectList::const_iterator i = mDamageDoneVersus.begin(); i != mDamageDoneVersus.end(); ++i)
        if (creatureTypeMask & uint32((*i)->GetMiscValue()))
            AddPctN(DoneTotalMod, (*i)->GetAmount());

    // bonus against aurastate
    AuraEffectList const& mDamageDoneVersusAurastate = GetAuraEffectsByType(SPELL_AURA_MOD_DAMAGE_DONE_VERSUS_AURASTATE);
    for (AuraEffectList::const_iterator i = mDamageDoneVersusAurastate.begin(); i != mDamageDoneVersusAurastate.end(); ++i)
        if (pVictim->HasAuraState(AuraState((*i)->GetMiscValue())))
            AddPctN(DoneTotalMod, (*i)->GetAmount());

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
                if ((*i)->GetSpellProto()->SpellIconID == 2656)
                {
                    if (!pVictim->HealthAbovePct(35))
                        AddPctN(DoneTotalMod, (*i)->GetAmount());
                }
                // Tundra Stalker
                else
                {
                    // Frost Fever (target debuff)
                    if (pVictim->HasAura(55095))
                        AddPctN(DoneTotalMod, (*i)->GetAmount());
                }
                break;
            }
            // Rage of Rivendare
            case 7293:
            {
                if (pVictim->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DEATHKNIGHT, 0, 0x02000000, 0))
                    if (SpellChainNode const* chain = sSpellMgr->GetSpellChainNode((*i)->GetId()))
                        AddPctF(DoneTotalMod, chain->rank * 2.0f);
                break;
            }
            // Marked for Death
            case 7598:
            case 7599:
            case 7600:
            case 7601:
            case 7602:
            {
                if (pVictim->GetAuraEffect(SPELL_AURA_MOD_STALKED, SPELLFAMILY_HUNTER, 0x400, 0, 0))
                    AddPctN(DoneTotalMod, (*i)->GetAmount());
                break;
            }
        }
    }

    // Custom scripted damage
    if (spellProto)
        switch(spellProto->SpellFamilyName)
        {
            case SPELLFAMILY_DEATHKNIGHT:
                // Glacier Rot
                if (spellProto->SpellFamilyFlags[0] & 0x2 || spellProto->SpellFamilyFlags[1] & 0x6)
                    if (AuraEffect* aurEff = GetDummyAuraEffect(SPELLFAMILY_DEATHKNIGHT, 196, 0))
                        if (pVictim->GetDiseasesByCaster(owner->GetGUID()) > 0)
                            AddPctN(DoneTotalMod, aurEff->GetAmount());
            break;
        }

    // ..taken
    AuraEffectList const& mModDamagePercentTaken = pVictim->GetAuraEffectsByType(SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN);
    for (AuraEffectList::const_iterator i = mModDamagePercentTaken.begin(); i != mModDamagePercentTaken.end(); ++i)
        if ((*i)->GetMiscValue() & GetMeleeDamageSchoolMask())
            AddPctN(TakenTotalMod, (*i)->GetAmount());

    // From caster spells
    AuraEffectList const& mOwnerTaken = pVictim->GetAuraEffectsByType(SPELL_AURA_MOD_DAMAGE_FROM_CASTER);
    for (AuraEffectList::const_iterator i = mOwnerTaken.begin(); i != mOwnerTaken.end(); ++i)
        if ((*i)->GetCasterGUID() == GetGUID() && (*i)->IsAffectedOnSpell(spellProto))
            AddPctN(TakenTotalMod, (*i)->GetAmount());

    // .. taken pct (special attacks)
    if (spellProto)
    {
        // Mod damage from spell mechanic
        uint32 mechanicMask = GetAllSpellMechanicMask(spellProto);

        // Shred, Maul - "Effects which increase Bleed damage also increase Shred damage"
        if (spellProto->SpellFamilyName == SPELLFAMILY_DRUID && spellProto->SpellFamilyFlags[0] & 0x00008800)
            mechanicMask |= (1<<MECHANIC_BLEED);

        if (mechanicMask)
        {
            AuraEffectList const& mDamageDoneMechanic = pVictim->GetAuraEffectsByType(SPELL_AURA_MOD_MECHANIC_DAMAGE_TAKEN_PERCENT);
            for (AuraEffectList::const_iterator i = mDamageDoneMechanic.begin(); i != mDamageDoneMechanic.end(); ++i)
                if (mechanicMask & uint32(1<<((*i)->GetMiscValue())))
                    AddPctN(TakenTotalMod, (*i)->GetAmount());
        }
    }

    // .. taken pct: dummy auras
    AuraEffectList const& mDummyAuras = pVictim->GetAuraEffectsByType(SPELL_AURA_DUMMY);
    for (AuraEffectList::const_iterator i = mDummyAuras.begin(); i != mDummyAuras.end(); ++i)
    {
        switch((*i)->GetSpellProto()->SpellIconID)
        {
            //Cheat Death
            case 2109:
                if ((*i)->GetMiscValue() & SPELL_SCHOOL_MASK_NORMAL)
                {
                    if (pVictim->GetTypeId() != TYPEID_PLAYER)
                        continue;
                    float mod = pVictim->ToPlayer()->GetRatingBonusValue(CR_CRIT_TAKEN_MELEE) * (-8.0f);
                    AddPctF(TakenTotalMod, std::max(mod, float((*i)->GetAmount())));
                }
                break;
            // Blessing of Sanctuary
            // Greater Blessing of Sanctuary
            case 19:
            case 1804:
            {
                if ((*i)->GetSpellProto()->SpellFamilyName != SPELLFAMILY_PALADIN)
                    continue;

                if ((*i)->GetMiscValue() & (spellProto ? GetSpellSchoolMask(spellProto) : 0))
                    AddPctN(TakenTotalMod, (*i)->GetAmount());
                break;
            }
            // Ebon Plague
            case 1933:
                if ((*i)->GetMiscValue() & (spellProto ? GetSpellSchoolMask(spellProto) : 0))
                    AddPctN(TakenTotalMod, (*i)->GetAmount());
                break;
        }
    }

    // .. taken pct: class scripts
    AuraEffectList const& mclassScritAuras = GetAuraEffectsByType(SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
    for (AuraEffectList::const_iterator i = mclassScritAuras.begin(); i != mclassScritAuras.end(); ++i)
    {
        switch((*i)->GetMiscValue())
        {
            case 6427: case 6428:                           // Dirty Deeds
                if (pVictim->HasAuraState(AURA_STATE_HEALTHLESS_35_PERCENT, spellProto, this))
                {
                    AuraEffect* eff0 = (*i)->GetBase()->GetEffect(EFFECT_0);
                    if (!eff0 || (*i)->GetEffIndex() != 1)
                    {
                        sLog->outError("Spell structure of DD (%u) changed.", (*i)->GetId());
                        continue;
                    }

                    // effect 0 have expected value but in negative state
                    AddPctN(TakenTotalMod, -eff0->GetAmount());
                }
                break;
        }
    }

    if (attType != RANGED_ATTACK)
    {
        AuraEffectList const& mModMeleeDamageTakenPercent = pVictim->GetAuraEffectsByType(SPELL_AURA_MOD_MELEE_DAMAGE_TAKEN_PCT);
        for (AuraEffectList::const_iterator i = mModMeleeDamageTakenPercent.begin(); i != mModMeleeDamageTakenPercent.end(); ++i)
            AddPctN(TakenTotalMod, (*i)->GetAmount());
    }
    else
    {
        AuraEffectList const& mModRangedDamageTakenPercent = pVictim->GetAuraEffectsByType(SPELL_AURA_MOD_RANGED_DAMAGE_TAKEN_PCT);
        for (AuraEffectList::const_iterator i = mModRangedDamageTakenPercent.begin(); i != mModRangedDamageTakenPercent.end(); ++i)
            AddPctN(TakenTotalMod, (*i)->GetAmount());
    }

    float tmpDamage = float(int32(*pdamage) + DoneFlatBenefit) * DoneTotalMod;

    // apply spellmod to Done damage
    if (spellProto)
        if (Player* modOwner = GetSpellModOwner())
            modOwner->ApplySpellMod(spellProto->Id, SPELLMOD_DAMAGE, tmpDamage);

    tmpDamage = (tmpDamage + TakenFlatBenefit) * TakenTotalMod;

    // bonus result can be negative
    *pdamage = uint32(std::max(tmpDamage, 0.0f));
}

void Unit::ApplySpellImmune(uint32 spellId, uint32 op, uint32 type, bool apply)
{
    if (apply)
    {
        for (SpellImmuneList::iterator itr = m_spellImmune[op].begin(), next; itr != m_spellImmune[op].end(); itr = next)
        {
            next = itr; ++next;
            if (itr->type == type)
            {
                m_spellImmune[op].erase(itr);
                next = m_spellImmune[op].begin();
            }
        }
        SpellImmune Immune;
        Immune.spellId = spellId;
        Immune.type = type;
        m_spellImmune[op].push_back(Immune);
    }
    else
    {
        for (SpellImmuneList::iterator itr = m_spellImmune[op].begin(); itr != m_spellImmune[op].end(); ++itr)
        {
            if (itr->spellId == spellId && itr->type == type)
            {
                m_spellImmune[op].erase(itr);
                break;
            }
        }
    }
}

void Unit::ApplySpellDispelImmunity(const SpellEntry * spellProto, DispelType type, bool apply)
{
    ApplySpellImmune(spellProto->Id, IMMUNITY_DISPEL, type, apply);

    if (apply && spellProto->AttributesEx & SPELL_ATTR1_DISPEL_AURAS_ON_IMMUNITY)
    {
        // Create dispel mask by dispel type
        uint32 dispelMask = GetDispellMask(type);
        // Dispel all existing auras vs current dispel type
        AuraApplicationMap& auras = GetAppliedAuras();
        for (AuraApplicationMap::iterator itr = auras.begin(); itr != auras.end();)
        {
            SpellEntry const* spell = itr->second->GetBase()->GetSpellProto();
            if ((1<<spell->Dispel) & dispelMask)
            {
                // Dispel aura
                RemoveAura(itr);
            }
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

float Unit::GetPPMProcChance(uint32 WeaponSpeed, float PPM, const SpellEntry * spellProto) const
{
    // proc per minute chance calculation
    if (PPM <= 0) return 0.0f;
    // Apply chance modifer aura
    if (spellProto)
        if (Player* modOwner = GetSpellModOwner())
            modOwner->ApplySpellMod(spellProto->Id, SPELLMOD_PROC_PER_MINUTE, PPM);

    return floor((WeaponSpeed * PPM) / 600.0f);   // result is chance in percents (probability = Speed_in_sec * (PPM / 60))
}

void Unit::Mount(uint32 mount, uint32 VehicleId, uint32 creatureEntry)
{
    if (mount)
        SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, mount);

    SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_MOUNT);

    if (Player* plr = ToPlayer())
    {
        // mount as a vehicle
        if (VehicleId)
        {
            if (CreateVehicleKit(VehicleId, creatureEntry))
            {
                GetVehicleKit()->Reset();

                // Send others that we now have a vehicle
                WorldPacket data(SMSG_PLAYER_VEHICLE_DATA, GetPackGUID().size()+4);
                data.appendPackGUID(GetGUID());
                data << uint32(VehicleId);
                SendMessageToSet(&data, true);

                data.Initialize(SMSG_ON_CANCEL_EXPECTED_RIDE_VEHICLE_AURA, 0);
                plr->GetSession()->SendPacket(&data);

                // mounts can also have accessories
                GetVehicleKit()->InstallAllAccessories(false);
            }
        }

        // unsummon pet
        Pet* pet = plr->GetPet();
        if (pet)
        {
            Battleground *bg = ToPlayer()->GetBattleground();
            // don't unsummon pet in arena but SetFlag UNIT_FLAG_STUNNED to disable pet's interface
            if (bg && bg->isArena())
                pet->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
            else
                plr->UnsummonPetTemporaryIfAny();
        }
    }

    RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_MOUNT);
}

void Unit::Unmount()
{
    if (!IsMounted())
        return;

    SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, 0);
    RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_MOUNT);

    WorldPacket data(SMSG_DISMOUNT, 8);
    data.appendPackGUID(GetGUID());
    SendMessageToSet(&data, true);

    // unmount as a vehicle
    if (GetTypeId() == TYPEID_PLAYER && GetVehicleKit())
    {
        // Send other players that we are no longer a vehicle
        WorldPacket data(SMSG_PLAYER_VEHICLE_DATA, 8+4);
        data.appendPackGUID(GetGUID());
        data << uint32(0);
        ToPlayer()->SendMessageToSet(&data, true);
        // Remove vehicle from player
        RemoveVehicleKit();
    }

    RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_NOT_MOUNTED);

    // only resummon old pet if the player is already added to a map
    // this prevents adding a pet to a not created map which would otherwise cause a crash
    // (it could probably happen when logging in after a previous crash)
    if (Player* plr = ToPlayer())
    {
        if (Pet* pPet = plr->GetPet())
        {
            if (pPet->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED) && !pPet->HasUnitState(UNIT_STAT_STUNNED))
                pPet->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
        }
        else
            plr->ResummonPetTemporaryUnSummonedIfAny();
    }
}

void Unit::SetInCombatWith(Unit* enemy)
{
    Unit* eOwner = enemy->GetCharmerOrOwnerOrSelf();
    if (eOwner->IsPvP())
    {
        SetInCombatState(true, enemy);
        return;
    }

    //check for duel
    if (eOwner->GetTypeId() == TYPEID_PLAYER && eOwner->ToPlayer()->duel)
    {
        Unit const* myOwner = GetCharmerOrOwnerOrSelf();
        if (((Player const*)eOwner)->duel->opponent == myOwner)
        {
            SetInCombatState(true, enemy);
            return;
        }
    }
    SetInCombatState(false, enemy);
}

void Unit::CombatStart(Unit* target, bool initialAggro)
{
    if (initialAggro)
    {
        if (!target->IsStandState())
            target->SetStandState(UNIT_STAND_STATE_STAND);

        if (!target->isInCombat() && target->GetTypeId() != TYPEID_PLAYER
            && !target->ToCreature()->HasReactState(REACT_PASSIVE) && target->ToCreature()->IsAIEnabled)
        {
            target->ToCreature()->AI()->AttackStart(this);
        }

        SetInCombatWith(target);
        target->SetInCombatWith(this);
    }
    Unit* who = target->GetCharmerOrOwnerOrSelf();
    if (who->GetTypeId() == TYPEID_PLAYER)
      SetContestedPvP(who->ToPlayer());

    Player* me = GetCharmerOrOwnerPlayerOrPlayerItself();
    if (me && who->IsPvP()
        && (who->GetTypeId() != TYPEID_PLAYER
        || !me->duel || me->duel->opponent != who))
    {
        me->UpdatePvP(true);
        me->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_ENTER_PVP_COMBAT);
    }
}

void Unit::SetInCombatState(bool PvP, Unit* enemy)
{
    // only alive units can be in combat
    if (!isAlive())
        return;

    if (PvP)
        m_CombatTimer = 5000;

    if (isInCombat() || HasUnitState(UNIT_STAT_EVADE))
        return;

    SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT);

    if (Creature* creature = ToCreature())
    {
        // Set home position at place of engaging combat for escorted creatures
        if ((IsAIEnabled && creature->AI()->IsEscorted()) ||
            GetMotionMaster()->GetCurrentMovementGeneratorType() == WAYPOINT_MOTION_TYPE ||
            GetMotionMaster()->GetCurrentMovementGeneratorType() == POINT_MOTION_TYPE)
            creature->SetHomePosition(GetPositionX(), GetPositionY(), GetPositionZ(), GetOrientation());

        if (enemy)
        {
            if (IsAIEnabled)
            {
                creature->AI()->EnterCombat(enemy);
                RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE); // always remove Out of Combat Non Attackable flag if we enter combat and AI is enabled
            }
            if (creature->GetFormation())
                creature->GetFormation()->MemberAttackStart(creature, enemy);
        }

        if (isPet())
        {
            UpdateSpeed(MOVE_RUN, true);
            UpdateSpeed(MOVE_SWIM, true);
            UpdateSpeed(MOVE_FLIGHT, true);
        }

        if (!(creature->GetCreatureInfo()->type_flags & CREATURE_TYPEFLAGS_MOUNTED_COMBAT))
            Unmount();
    }

    for (Unit::ControlList::iterator itr = m_Controlled.begin(); itr != m_Controlled.end(); ++itr)
    {
        (*itr)->SetInCombatState(PvP, enemy);
        (*itr)->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PET_IN_COMBAT);
    }
}

void Unit::ClearInCombat()
{
    m_CombatTimer = 0;
    RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT);

    // Player's state will be cleared in Player::UpdateContestedPvP
    if (Creature* creature = ToCreature())
    {
        if (creature->GetCreatureInfo() && creature->GetCreatureInfo()->unit_flags & UNIT_FLAG_OOC_NOT_ATTACKABLE)
            SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE); // re-apply Out of Combat Non Attackable flag if we leave combat, can be overriden in scripts in EnterEvadeMode()

        ClearUnitState(UNIT_STAT_ATTACK_PLAYER);
        if (HasFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_TAPPED))
            SetUInt32Value(UNIT_DYNAMIC_FLAGS, creature->GetCreatureInfo()->dynamicflags);
    }
    else
        ToPlayer()->UpdatePotionCooldown();

    if (GetTypeId() != TYPEID_PLAYER && ToCreature()->isPet())
    {
        if (Unit* owner = GetOwner())
            for (uint8 i = 0; i < MAX_MOVE_TYPE; ++i)
                if (owner->GetSpeedRate(UnitMoveType(i)) > GetSpeedRate(UnitMoveType(i)))
                    SetSpeed(UnitMoveType(i), owner->GetSpeedRate(UnitMoveType(i)), true);
    }
    else if (!isCharmed())
        return;

    RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PET_IN_COMBAT);
}

// TODO: remove this function
bool Unit::isTargetableForAttack() const
{
    return isAttackableByAOE() && !HasUnitState(UNIT_STAT_DIED);
}

bool Unit::canAttack(Unit const* target, bool force) const
{
    ASSERT(target);

    if (force)
    {
        if (IsFriendlyTo(target))
            return false;

        if (GetTypeId() != TYPEID_PLAYER)
        {
            if (isPet())
            {
                if (Unit* owner = GetOwner())
                    if (!(owner->canAttack(target)))
                        return false;
            }
            else if (!IsHostileTo(target))
                return false;
        }
    }
    else if (!IsHostileTo(target))
        return false;

    if (!target->isAttackableByAOE())
        return false;

    if (target->HasUnitState(UNIT_STAT_DIED))
    {
        if (!ToCreature() || !ToCreature()->isGuard())
            return false;

        // guards can detect fake death
        if (!target->HasFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH))
            return false;
    }

    if (m_vehicle)
        if (IsOnVehicle(target) || m_vehicle->GetBase()->IsOnVehicle(target))
            return false;

    if (!canSeeOrDetect(target))
        return false;

    return true;
}

bool Unit::isAttackableByAOE(SpellEntry const* spellProto) const
{
    bool targetMustBeDead = spellProto ? bool(spellProto->AttributesEx3 & SPELL_ATTR3_REQUIRE_DEAD_TARGET) : false;
    bool targetCanBeDead = spellProto ? bool(spellProto->AttributesEx2 & SPELL_ATTR2_ALLOW_DEAD_TARGET) : false;

    if (targetMustBeDead && isAlive())
        return false;

    if (!targetMustBeDead && !targetCanBeDead && !isAlive())
        return false;

    if (HasFlag(UNIT_FIELD_FLAGS,
        UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE))
        return false;

    if (GetTypeId() == TYPEID_PLAYER && ToPlayer()->isGameMaster())
        return false;

    return !HasUnitState(UNIT_STAT_UNATTACKABLE);
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
int32 Unit::ModifyPower(Powers power, int32 dVal)
{
    int32 gain = 0;

    if (dVal == 0)
        return 0;

    int32 curPower = (int32)GetPower(power);

    int32 val = dVal + curPower;
    if (val <= 0)
    {
        SetPower(power, 0);
        return -curPower;
    }

    int32 maxPower = (int32)GetMaxPower(power);

    if (val < maxPower)
    {
        SetPower(power, val);
        gain = val - curPower;
    }
    else if (curPower != maxPower)
    {
        SetPower(power, maxPower);
        gain = maxPower - curPower;
    }

    return gain;
}

bool Unit::isAlwaysVisibleFor(WorldObject const* seer) const
{
    if (WorldObject::isAlwaysVisibleFor(seer))
        return true;

    // Always seen by owner
    if (uint64 guid = GetCharmerOrOwnerGUID())
        if (seer->GetGUID() == guid)
            return true;

    return false;
}

bool Unit::isAlwaysDetectableFor(WorldObject const* seer) const
{
    if (WorldObject::isAlwaysDetectableFor(seer))
        return true;

    if (HasAuraTypeWithCaster(SPELL_AURA_MOD_STALKED, seer->GetGUID()))
        return true;

    return false;
}

void Unit::SetVisible(bool x)
{
    if (!x)
        m_serverSideVisibility.SetValue(SERVERSIDE_VISIBILITY_GM, SEC_GAMEMASTER);
    else
        m_serverSideVisibility.SetValue(SERVERSIDE_VISIBILITY_GM, SEC_PLAYER);

    UpdateObjectVisibility();
}

void Unit::UpdateSpeed(UnitMoveType mtype, bool forced)
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
                GetVehicleBase()->UpdateSpeed(MOVE_FLIGHT, true);
            break;
        }
        default:
            sLog->outError("Unit::UpdateSpeed: Unsupported move type (%d)", mtype);
            return;
    }

    // now we ready for speed calculation
    float speed = std::max(non_stack_bonus, stack_bonus);
    if (main_speed_mod)
        AddPctN(speed, main_speed_mod);

    switch (mtype)
    {
        case MOVE_RUN:
        case MOVE_SWIM:
        case MOVE_FLIGHT:
        {
            // Set creature speed rate from CreatureInfo
            if (GetTypeId() == TYPEID_UNIT)
                speed *= ToCreature()->GetCreatureInfo()->speed_walk;

            // Normalize speed by 191 aura SPELL_AURA_USE_NORMAL_MOVEMENT_SPEED if need
            // TODO: possible affect only on MOVE_RUN
            if (int32 normalization = GetMaxPositiveAuraModifier(SPELL_AURA_USE_NORMAL_MOVEMENT_SPEED))
            {
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

    // for creature case, we check explicit if mob searched for assistance
    if (GetTypeId() == TYPEID_UNIT)
    {
        if (ToCreature()->HasSearchedAssistance())
            speed *= 0.66f;                                 // best guessed value, so this will be 33% reduction. Based off initial speed, mob can then "run", "walk fast" or "walk".
    }

    // Apply strongest slow aura mod to speed
    int32 slow = GetMaxNegativeAuraModifier(SPELL_AURA_MOD_DECREASE_SPEED);
    if (slow)
    {
        AddPctN(speed, slow);
        if (float minSpeedMod = (float)GetMaxPositiveAuraModifier(SPELL_AURA_MOD_MINIMUM_SPEED))
        {
            float min_speed = minSpeedMod / 100.0f;
            if (speed < min_speed)
                speed = min_speed;
        }
    }
    SetSpeed(mtype, speed, forced);
}

float Unit::GetSpeed(UnitMoveType mtype) const
{
    return m_speed_rate[mtype]*(IsControlledByPlayer() ? playerBaseMoveSpeed[mtype] : baseMoveSpeed[mtype]);
}

void Unit::SetSpeed(UnitMoveType mtype, float rate, bool forced)
{
    if (rate < 0)
        rate = 0.0f;

    // Update speed only on change
    if (m_speed_rate[mtype] == rate)
        return;

    m_speed_rate[mtype] = rate;

    propagateSpeedChange();

    WorldPacket data;
    if (!forced)
    {
        switch(mtype)
        {
            case MOVE_WALK:
                data.Initialize(MSG_MOVE_SET_WALK_SPEED, 8+4+2+4+4+4+4+4+4+4);
                break;
            case MOVE_RUN:
                data.Initialize(MSG_MOVE_SET_RUN_SPEED, 8+4+2+4+4+4+4+4+4+4);
                break;
            case MOVE_RUN_BACK:
                data.Initialize(MSG_MOVE_SET_RUN_BACK_SPEED, 8+4+2+4+4+4+4+4+4+4);
                break;
            case MOVE_SWIM:
                data.Initialize(MSG_MOVE_SET_SWIM_SPEED, 8+4+2+4+4+4+4+4+4+4);
                break;
            case MOVE_SWIM_BACK:
                data.Initialize(MSG_MOVE_SET_SWIM_BACK_SPEED, 8+4+2+4+4+4+4+4+4+4);
                break;
            case MOVE_TURN_RATE:
                data.Initialize(MSG_MOVE_SET_TURN_RATE, 8+4+2+4+4+4+4+4+4+4);
                break;
            case MOVE_FLIGHT:
                data.Initialize(MSG_MOVE_SET_FLIGHT_SPEED, 8+4+2+4+4+4+4+4+4+4);
                break;
            case MOVE_FLIGHT_BACK:
                data.Initialize(MSG_MOVE_SET_FLIGHT_BACK_SPEED, 8+4+2+4+4+4+4+4+4+4);
                break;
            case MOVE_PITCH_RATE:
                data.Initialize(MSG_MOVE_SET_PITCH_RATE, 8+4+2+4+4+4+4+4+4+4);
                break;
            default:
                sLog->outError("Unit::SetSpeed: Unsupported move type (%d), data not sent to client.", mtype);
                return;
        }

        data.append(GetPackGUID());
        data << uint32(0);                                  // movement flags
        data << uint16(0);                                  // unk flags
        data << uint32(getMSTime());
        data << float(GetPositionX());
        data << float(GetPositionY());
        data << float(GetPositionZ());
        data << float(GetOrientation());
        data << uint32(0);                                  // fall time
        data << float(GetSpeed(mtype));
        SendMessageToSet(&data, true);
    }
    else
    {
        if (GetTypeId() == TYPEID_PLAYER)
        {
            // register forced speed changes for WorldSession::HandleForceSpeedChangeAck
            // and do it only for real sent packets and use run for run/mounted as client expected
            ++ToPlayer()->m_forced_speed_changes[mtype];

            if (!isInCombat())
                if (Pet* pet = ToPlayer()->GetPet())
                    pet->SetSpeed(mtype, m_speed_rate[mtype], forced);
        }

        switch(mtype)
        {
            case MOVE_WALK:
                data.Initialize(SMSG_FORCE_WALK_SPEED_CHANGE, 16);
                break;
            case MOVE_RUN:
                data.Initialize(SMSG_FORCE_RUN_SPEED_CHANGE, 17);
                break;
            case MOVE_RUN_BACK:
                data.Initialize(SMSG_FORCE_RUN_BACK_SPEED_CHANGE, 16);
                break;
            case MOVE_SWIM:
                data.Initialize(SMSG_FORCE_SWIM_SPEED_CHANGE, 16);
                break;
            case MOVE_SWIM_BACK:
                data.Initialize(SMSG_FORCE_SWIM_BACK_SPEED_CHANGE, 16);
                break;
            case MOVE_TURN_RATE:
                data.Initialize(SMSG_FORCE_TURN_RATE_CHANGE, 16);
                break;
            case MOVE_FLIGHT:
                data.Initialize(SMSG_FORCE_FLIGHT_SPEED_CHANGE, 16);
                break;
            case MOVE_FLIGHT_BACK:
                data.Initialize(SMSG_FORCE_FLIGHT_BACK_SPEED_CHANGE, 16);
                break;
            case MOVE_PITCH_RATE:
                data.Initialize(SMSG_FORCE_PITCH_RATE_CHANGE, 16);
                break;
            default:
                sLog->outError("Unit::SetSpeed: Unsupported move type (%d), data not sent to client.", mtype);
                return;
        }
        data.append(GetPackGUID());
        data << (uint32)0;                                  // moveEvent, NUM_PMOVE_EVTS = 0x39
        if (mtype == MOVE_RUN)
            data << uint8(0);                               // new 2.1.0
        data << float(GetSpeed(mtype));
        SendMessageToSet(&data, true);
    }
}

void Unit::SetHover(bool on)
{
    if (on)
        CastSpell(this, 11010, true);
    else
        RemoveAurasDueToSpell(11010);
}

void Unit::setDeathState(DeathState s)
{
    // death state needs to be updated before RemoveAllAurasOnDeath() calls HandleChannelDeathItem(..) so that
    // it can be used to check creation of death items (such as soul shards).
    DeathState oldDeathState = m_deathState;
    m_deathState = s;

    if (s != ALIVE && s != JUST_ALIVED)
    {
        CombatStop();
        DeleteThreatList();
        getHostileRefManager().deleteReferences();
        ClearComboPointHolders();                           // any combo points pointed to unit lost at it death

        if (IsNonMeleeSpellCasted(false))
            InterruptNonMeleeSpells(false);

        UnsummonAllTotems();
        RemoveAllControlled();
        RemoveAllAurasOnDeath();
    }

    if (s == JUST_DIED)
    {
        ModifyAuraState(AURA_STATE_HEALTHLESS_20_PERCENT, false);
        ModifyAuraState(AURA_STATE_HEALTHLESS_35_PERCENT, false);
        // remove aurastates allowing special moves
        ClearAllReactives();
        ClearDiminishings();
        GetMotionMaster()->Clear(false);
        GetMotionMaster()->MoveIdle();
        SendMonsterStop(true);
        // without this when removing IncreaseMaxHealth aura player may stuck with 1 hp
        // do not why since in IncreaseMaxHealth currenthealth is checked
        SetHealth(0);
        SetPower(getPowerType(), 0);
    }
    else if (s == JUST_ALIVED)
        RemoveFlag (UNIT_FIELD_FLAGS, UNIT_FLAG_SKINNABLE); // clear skinnable for creature and player (at battleground)

    if (oldDeathState != ALIVE && s == ALIVE)
    {
        // Reset display id on resurection - needed by corpse explosion to cleanup after display change
        // TODO: fix this
        if (!HasAuraType(SPELL_AURA_TRANSFORM))
            SetDisplayId(GetNativeDisplayId());
    }
}

/*########################################
########                          ########
########       AGGRO SYSTEM       ########
########                          ########
########################################*/
bool Unit::CanHaveThreatList() const
{
    // only creatures can have threat list
    if (GetTypeId() != TYPEID_UNIT)
        return false;

    // only alive units can have threat list
    if (!isAlive() || isDying())
        return false;

    // totems can not have threat list
    if (ToCreature()->isTotem())
        return false;

    // vehicles can not have threat list
    //if (ToCreature()->IsVehicle())
    //    return false;

    // summons can not have a threat list, unless they are controlled by a creature
    if (HasUnitTypeMask(UNIT_MASK_MINION | UNIT_MASK_GUARDIAN | UNIT_MASK_CONTROLABLE_GUARDIAN) && IS_PLAYER_GUID(((Pet*)this)->GetOwnerGUID()))
        return false;

    return true;
}

//======================================================================

float Unit::ApplyTotalThreatModifier(float fThreat, SpellSchoolMask schoolMask)
{
    if (!HasAuraType(SPELL_AURA_MOD_THREAT) || fThreat < 0)
        return fThreat;

    SpellSchools school = GetFirstSchoolInMask(schoolMask);

    return fThreat * m_threatModifier[school];
}

//======================================================================

void Unit::AddThreat(Unit* pVictim, float fThreat, SpellSchoolMask schoolMask, SpellEntry const *threatSpell)
{
    // Only mobs can manage threat lists
    if (CanHaveThreatList())
        m_ThreatManager.addThreat(pVictim, fThreat, schoolMask, threatSpell);
}

//======================================================================

void Unit::DeleteThreatList()
{
    if (CanHaveThreatList() && !m_ThreatManager.isThreatListEmpty())
        SendClearThreatListOpcode();
    m_ThreatManager.clearReferences();
}

//======================================================================

void Unit::TauntApply(Unit* taunter)
{
    ASSERT(GetTypeId() == TYPEID_UNIT);

    if (!taunter || (taunter->GetTypeId() == TYPEID_PLAYER && taunter->ToPlayer()->isGameMaster()))
        return;

    if (!CanHaveThreatList())
        return;

    Creature* creature = ToCreature();

    if (creature->HasReactState(REACT_PASSIVE))
        return;

    Unit* target = getVictim();
    if (target && target == taunter)
        return;

    SetInFront(taunter);
    if (creature->IsAIEnabled)
        creature->AI()->AttackStart(taunter);

    //m_ThreatManager.tauntApply(taunter);
}

//======================================================================

void Unit::TauntFadeOut(Unit *taunter)
{
    ASSERT(GetTypeId() == TYPEID_UNIT);

    if (!taunter || (taunter->GetTypeId() == TYPEID_PLAYER && taunter->ToPlayer()->isGameMaster()))
        return;

    if (!CanHaveThreatList())
        return;

    Creature* creature = ToCreature();

    if (creature->HasReactState(REACT_PASSIVE))
        return;

    Unit* target = getVictim();
    if (!target || target != taunter)
        return;

    if (m_ThreatManager.isThreatListEmpty())
    {
        if (creature->IsAIEnabled)
            creature->AI()->EnterEvadeMode();
        return;
    }

    //m_ThreatManager.tauntFadeOut(taunter);
    target = m_ThreatManager.getHostilTarget();

    if (target && target != taunter)
    {
        SetInFront(target);
        if (creature->IsAIEnabled)
            creature->AI()->AttackStart(target);
    }
}

//======================================================================

Unit* Creature::SelectVictim()
{
    // function provides main threat functionality
    // next-victim-selection algorithm and evade mode are called
    // threat list sorting etc.

    Unit* target = NULL;
    // First checking if we have some taunt on us
    AuraEffectList const& tauntAuras = GetAuraEffectsByType(SPELL_AURA_MOD_TAUNT);
    if (!tauntAuras.empty())
    {
        Unit* caster = tauntAuras.back()->GetCaster();

        // The last taunt aura caster is alive an we are happy to attack him
        if (caster && caster->isAlive())
            return getVictim();
        else if (tauntAuras.size() > 1)
        {
            // We do not have last taunt aura caster but we have more taunt auras,
            // so find first available target

            // Auras are pushed_back, last caster will be on the end
            AuraEffectList::const_iterator aura = --tauntAuras.end();
            do
            {
                --aura;
                caster = (*aura)->GetCaster();
                if (caster && canSeeOrDetect(caster, true) && canAttack(caster) && caster->isInAccessiblePlaceFor(ToCreature()))
                {
                    target = caster;
                    break;
                }
            } while (aura != tauntAuras.begin());
        }
        else
            target = getVictim();
    }

    if (CanHaveThreatList())
    {
        if (!target && !m_ThreatManager.isThreatListEmpty())
            // No taunt aura or taunt aura caster is dead standard target selection
            target = m_ThreatManager.getHostilTarget();
    }
    else if (!HasReactState(REACT_PASSIVE))
    {
        // We have player pet probably
        target = getAttackerForHelper();
        if (!target && isSummon())
        {
            if (Unit* owner = ToTempSummon()->GetOwner())
            {
                if (owner->isInCombat())
                    target = owner->getAttackerForHelper();
                if (!target)
                {
                    for (ControlList::const_iterator itr = owner->m_Controlled.begin(); itr != owner->m_Controlled.end(); ++itr)
                    {
                        if ((*itr)->isInCombat())
                        {
                            target = (*itr)->getAttackerForHelper();
                            if (target)
                                break;
                        }
                    }
                }
            }
        }
    }
    else
        return NULL;

    if (target && _IsTargetAcceptable(target))
    {
        SetInFront(target);
        return target;
    }

    // last case when creature don't must go to evade mode:
    // it in combat but attacker not make any damage and not enter to aggro radius to have record in threat list
    // for example at owner command to pet attack some far away creature
    // Note: creature not have targeted movement generator but have attacker in this case
    for (AttackerSet::const_iterator itr = m_attackers.begin(); itr != m_attackers.end(); ++itr)
    {
        if ((*itr) && !canCreatureAttack(*itr) && (*itr)->GetTypeId() != TYPEID_PLAYER
        && !(*itr)->ToCreature()->HasUnitTypeMask(UNIT_MASK_CONTROLABLE_GUARDIAN))
            return NULL;
    }

    // TODO: a vehicle may eat some mob, so mob should not evade
    if (GetVehicle())
        return NULL;

    // search nearby enemy before enter evade mode
    if (HasReactState(REACT_AGGRESSIVE))
    {
        target = SelectNearestTargetInAttackDistance(m_CombatDistance ? m_CombatDistance : ATTACK_DISTANCE);

        if (target && _IsTargetAcceptable(target))
            return target;
    }

    Unit::AuraEffectList const& iAuras = GetAuraEffectsByType(SPELL_AURA_MOD_INVISIBILITY);
    if (!iAuras.empty())
    {
        for (Unit::AuraEffectList::const_iterator itr = iAuras.begin(); itr != iAuras.end(); ++itr)
        {
            if ((*itr)->GetBase()->IsPermanent())
            {
                AI()->EnterEvadeMode();
                break;
            }
        }
        return NULL;
    }

    // enter in evade mode in other case
    AI()->EnterEvadeMode();

    return NULL;
}

//======================================================================
//======================================================================
//======================================================================

float Unit::ApplyEffectModifiers(SpellEntry const* spellProto, uint8 effect_index, float value) const
{
    if (Player* modOwner = GetSpellModOwner())
    {
        modOwner->ApplySpellMod(spellProto->Id, SPELLMOD_ALL_EFFECTS, value);
        switch (effect_index)
        {
            case 0:
                modOwner->ApplySpellMod(spellProto->Id, SPELLMOD_EFFECT1, value);
                break;
            case 1:
                modOwner->ApplySpellMod(spellProto->Id, SPELLMOD_EFFECT2, value);
                break;
            case 2:
                modOwner->ApplySpellMod(spellProto->Id, SPELLMOD_EFFECT3, value);
                break;
        }
    }
    return value;
}

// function uses real base points (typically value - 1)
int32 Unit::CalculateSpellDamage(Unit const* target, SpellEntry const* spellProto, uint8 effect_index, int32 const* basePoints) const
{
    return SpellMgr::CalculateSpellEffectAmount(spellProto, effect_index, this, basePoints, target);
}

int32 Unit::CalcSpellDuration(SpellEntry const* spellProto)
{
    uint8 comboPoints = m_movedPlayer ? m_movedPlayer->GetComboPoints() : 0;

    int32 minduration = GetSpellDuration(spellProto);
    int32 maxduration = GetSpellMaxDuration(spellProto);

    int32 duration;

    if (comboPoints && minduration != -1 && minduration != maxduration)
        duration = minduration + int32((maxduration - minduration) * comboPoints / 5);
    else
        duration = minduration;

    return duration;
}

int32 Unit::ModSpellDuration(SpellEntry const* spellProto, Unit const* target, int32 duration, bool positive)
{
    // don't mod permament auras duration
    if (duration < 0)
        return duration;

    // cut duration only of negative effects
    if (!positive)
    {
        int32 mechanic = GetAllSpellMechanicMask(spellProto);

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
            AddPctN(duration, durationMod);

        // there are only negative mods currently
        durationMod_always = target->GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_AURA_DURATION_BY_DISPEL, spellProto->Dispel);
        durationMod_not_stack = target->GetMaxNegativeAuraModifierByMiscValue(SPELL_AURA_MOD_AURA_DURATION_BY_DISPEL_NOT_STACK, spellProto->Dispel);

        durationMod = 0;
        if (durationMod_always > durationMod_not_stack)
            durationMod += durationMod_not_stack;
        else
            durationMod += durationMod_always;

        if (durationMod != 0)
            AddPctN(duration, durationMod);
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
                if (target->HasAura(53042) && target->HasSpell(spellProto->EffectTriggerSpell[0]))
                    duration *= 2;
            }
        }
    }

    // Glyphs which increase duration of selfcasted buffs
    if (target == this)
    {
        switch (spellProto->SpellFamilyName)
        {
            case SPELLFAMILY_DRUID:
                if (spellProto->SpellFamilyFlags[0] & 0x100)
                {
                    // Glyph of Thorns
                    if (AuraEffect* aurEff = GetAuraEffect(57862, 0))
                        duration += aurEff->GetAmount() * MINUTE * IN_MILLISECONDS;
                }
                break;
            case SPELLFAMILY_PALADIN:
                if (spellProto->SpellFamilyFlags[0] & 0x00000002)
                {
                    // Glyph of Blessing of Might
                    if (AuraEffect* aurEff = GetAuraEffect(57958, 0))
                        duration += aurEff->GetAmount() * MINUTE * IN_MILLISECONDS;
                }
                else if (spellProto->SpellFamilyFlags[0] & 0x00010000)
                {
                    // Glyph of Blessing of Wisdom
                    if (AuraEffect* aurEff = GetAuraEffect(57979, 0))
                        duration += aurEff->GetAmount() * MINUTE * IN_MILLISECONDS;
                }
                break;
        }
    }
    return std::max(duration, 0);
}

void Unit::ModSpellCastTime(SpellEntry const* spellProto, int32 & castTime, Spell* spell)
{
    if (!spellProto || castTime < 0)
        return;
    //called from caster
    if (Player* modOwner = GetSpellModOwner())
        modOwner->ApplySpellMod(spellProto->Id, SPELLMOD_CASTING_TIME, castTime, spell);

    if (!(spellProto->Attributes & (SPELL_ATTR0_ABILITY|SPELL_ATTR0_TRADESPELL)) && spellProto->SpellFamilyName)
        castTime = int32(float(castTime) * GetFloatValue(UNIT_MOD_CAST_SPEED));
    else if (spellProto->Attributes & SPELL_ATTR0_REQ_AMMO && !(spellProto->AttributesEx2 & SPELL_ATTR2_AUTOREPEAT_FLAG))
        castTime = int32(float(castTime) * m_modAttackSpeedPct[RANGED_ATTACK]);
    else if (spellProto->SpellVisual[0] == 3881 && HasAura(67556)) // cooking with Chef Hat.
        castTime = 500;
}

DiminishingLevels Unit::GetDiminishing(DiminishingGroup group)
{
    for (Diminishing::iterator i = m_Diminishing.begin(); i != m_Diminishing.end(); ++i)
    {
        if (i->DRGroup != group)
            continue;

        if (!i->hitCount)
            return DIMINISHING_LEVEL_1;

        if (!i->hitTime)
            return DIMINISHING_LEVEL_1;

        // If last spell was casted more than 15 seconds ago - reset the count.
        if (i->stack == 0 && getMSTimeDiff(i->hitTime, getMSTime()) > 15000)
        {
            i->hitCount = DIMINISHING_LEVEL_1;
            return DIMINISHING_LEVEL_1;
        }
        // or else increase the count.
        else
            return DiminishingLevels(i->hitCount);
    }
    return DIMINISHING_LEVEL_1;
}

void Unit::IncrDiminishing(DiminishingGroup group)
{
    // Checking for existing in the table
    for (Diminishing::iterator i = m_Diminishing.begin(); i != m_Diminishing.end(); ++i)
    {
        if (i->DRGroup != group)
            continue;
        if (int32(i->hitCount) < GetDiminishingReturnsMaxLevel(group))
            i->hitCount += 1;
        return;
    }
    m_Diminishing.push_back(DiminishingReturn(group, getMSTime(), DIMINISHING_LEVEL_2));
}

float Unit::ApplyDiminishingToDuration(DiminishingGroup group, int32 &duration, Unit *caster, DiminishingLevels Level, int32 limitduration)
{
    if (duration == -1 || group == DIMINISHING_NONE)
        return 1.0f;

    // test pet/charm masters instead pets/charmeds
    Unit const* targetOwner = GetCharmerOrOwner();
    Unit const* casterOwner = caster->GetCharmerOrOwner();

    // Duration of crowd control abilities on pvp target is limited by 10 sec. (2.2.0)
    if (limitduration > 0 && duration > limitduration)
    {
        Unit const* target = targetOwner ? targetOwner : this;
        Unit const* source = casterOwner ? casterOwner : caster;

        if ((target->GetTypeId() == TYPEID_PLAYER
            || ((Creature*)target)->GetCreatureInfo()->flags_extra & CREATURE_FLAG_EXTRA_ALL_DIMINISH)
            && source->GetTypeId() == TYPEID_PLAYER)
            duration = limitduration;
    }

    float mod = 1.0f;

    if (group == DIMINISHING_TAUNT)
    {
        if (GetTypeId() == TYPEID_UNIT && (ToCreature()->GetCreatureInfo()->flags_extra & CREATURE_FLAG_EXTRA_TAUNT_DIMINISH))
        {
            DiminishingLevels diminish = Level;
            switch(diminish)
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
    else if ((GetDiminishingReturnsGroupType(group) == DRTYPE_PLAYER
        && ((targetOwner ? (targetOwner->GetTypeId() == TYPEID_PLAYER) : (GetTypeId() == TYPEID_PLAYER))
        || (GetTypeId() == TYPEID_UNIT && ToCreature()->GetCreatureInfo()->flags_extra & CREATURE_FLAG_EXTRA_ALL_DIMINISH)))
        || GetDiminishingReturnsGroupType(group) == DRTYPE_ALL)
    {
        DiminishingLevels diminish = Level;
        switch(diminish)
        {
            case DIMINISHING_LEVEL_1: break;
            case DIMINISHING_LEVEL_2: mod = 0.5f; break;
            case DIMINISHING_LEVEL_3: mod = 0.25f; break;
            case DIMINISHING_LEVEL_IMMUNE: mod = 0.0f; break;
            default: break;
        }
    }

    duration = int32(duration * mod);
    return mod;
}

void Unit::ApplyDiminishingAura(DiminishingGroup group, bool apply)
{
    // Checking for existing in the table
    for (Diminishing::iterator i = m_Diminishing.begin(); i != m_Diminishing.end(); ++i)
    {
        if (i->DRGroup != group)
            continue;

        if (apply)
            i->stack += 1;
        else if (i->stack)
        {
            i->stack -= 1;
            // Remember time after last aura from group removed
            if (i->stack == 0)
                i->hitTime = getMSTime();
        }
        break;
    }
}

uint32 Unit::GetSpellMaxRangeForTarget(Unit* target, const SpellRangeEntry * rangeEntry)
{
    if (!rangeEntry)
        return 0;
    if (rangeEntry->maxRangeHostile == rangeEntry->maxRangeFriend)
        return uint32(rangeEntry->maxRangeFriend);
    if (IsHostileTo(target))
        return uint32(rangeEntry->maxRangeHostile);
    return uint32(rangeEntry->maxRangeFriend);
};
uint32 Unit::GetSpellMinRangeForTarget(Unit* target, const SpellRangeEntry * rangeEntry)
{
    if (!rangeEntry)
        return 0;
    if (rangeEntry->minRangeHostile == rangeEntry->minRangeFriend)
        return uint32(rangeEntry->minRangeFriend);
    if (IsHostileTo(target))
        return uint32(rangeEntry->minRangeHostile);
    return uint32(rangeEntry->minRangeFriend);
};
uint32 Unit::GetSpellRadiusForTarget(Unit* target, const SpellRadiusEntry * radiusEntry)
{
    if (!radiusEntry)
        return 0;
    if (radiusEntry->radiusHostile == radiusEntry->radiusFriend)
        return uint32(radiusEntry->radiusFriend);
    if (IsHostileTo(target))
        return uint32(radiusEntry->radiusHostile);
    return uint32(radiusEntry->radiusFriend);
};

Unit* Unit::GetUnit(WorldObject& object, uint64 guid)
{
    return ObjectAccessor::GetUnit(object, guid);
}

Player* Unit::GetPlayer(WorldObject& object, uint64 guid)
{
    return ObjectAccessor::GetPlayer(object, guid);
}

Creature* Unit::GetCreature(WorldObject& object, uint64 guid)
{
    return object.GetMap()->GetCreature(guid);
}

uint32 Unit::GetCreatureType() const
{
    if (GetTypeId() == TYPEID_PLAYER)
    {
        ShapeshiftForm form = GetShapeshiftForm();
        SpellShapeshiftEntry const* ssEntry = sSpellShapeshiftStore.LookupEntry(form);
        if (ssEntry && ssEntry->creatureType > 0)
            return ssEntry->creatureType;
        else
            return CREATURE_TYPE_HUMANOID;
    }
    else
        return ToCreature()->GetCreatureInfo()->type;
}

/*#######################################
########                         ########
########       STAT SYSTEM       ########
########                         ########
#######################################*/

bool Unit::HandleStatModifier(UnitMods unitMod, UnitModifierType modifierType, float amount, bool apply)
{
    if (unitMod >= UNIT_MOD_END || modifierType >= MODIFIER_TYPE_END)
    {
        sLog->outError("ERROR in HandleStatModifier(): non existed UnitMods or wrong UnitModifierType!");
        return false;
    }

    switch (modifierType)
    {
        case BASE_VALUE:
        case TOTAL_VALUE:
            m_auraModifiersGroup[unitMod][modifierType] += apply ? amount : -amount;
            break;
        case BASE_PCT:
        case TOTAL_PCT:
            m_auraModifiersGroup[unitMod][modifierType] += (apply ? amount : -amount) / 100.0f;
            break;
        default:
            break;
    }

    if (!CanModifyStats())
        return false;

    switch(unitMod)
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

    return true;
}

float Unit::GetModifierValue(UnitMods unitMod, UnitModifierType modifierType) const
{
    if (unitMod >= UNIT_MOD_END || modifierType >= MODIFIER_TYPE_END)
    {
        sLog->outError("trial to access non existed modifier value from UnitMods!");
        return 0.0f;
    }

    if (modifierType == TOTAL_PCT && m_auraModifiersGroup[unitMod][modifierType] <= 0.0f)
        return 0.0f;

    return m_auraModifiersGroup[unitMod][modifierType];
}

float Unit::GetTotalStatValue(Stats stat) const
{
    UnitMods unitMod = UnitMods(UNIT_MOD_STAT_START + stat);

    if (m_auraModifiersGroup[unitMod][TOTAL_PCT] <= 0.0f)
        return 0.0f;

    // value = ((base_value * base_pct) + total_value) * total_pct
    float value  = m_auraModifiersGroup[unitMod][BASE_VALUE] + GetCreateStat(stat);
    value *= m_auraModifiersGroup[unitMod][BASE_PCT];
    value += m_auraModifiersGroup[unitMod][TOTAL_VALUE];
    value *= m_auraModifiersGroup[unitMod][TOTAL_PCT];

    return value;
}

float Unit::GetTotalAuraModValue(UnitMods unitMod) const
{
    if (unitMod >= UNIT_MOD_END)
    {
        sLog->outError("trial to access non existed UnitMods in GetTotalAuraModValue()!");
        return 0.0f;
    }

    if (m_auraModifiersGroup[unitMod][TOTAL_PCT] <= 0.0f)
        return 0.0f;

    float value = m_auraModifiersGroup[unitMod][BASE_VALUE];
    value *= m_auraModifiersGroup[unitMod][BASE_PCT];
    value += m_auraModifiersGroup[unitMod][TOTAL_VALUE];
    value *= m_auraModifiersGroup[unitMod][TOTAL_PCT];

    return value;
}

SpellSchools Unit::GetSpellSchoolByAuraGroup(UnitMods unitMod) const
{
    SpellSchools school = SPELL_SCHOOL_NORMAL;

    switch(unitMod)
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

    switch(unitMod)
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
        int32 ap = GetInt32Value(UNIT_FIELD_RANGED_ATTACK_POWER) + GetInt32Value(UNIT_FIELD_RANGED_ATTACK_POWER_MODS);
        if (ap < 0)
            return 0.0f;
        return ap * (1.0f + GetFloatValue(UNIT_FIELD_RANGED_ATTACK_POWER_MULTIPLIER));
    }
    else
    {
        int32 ap = GetInt32Value(UNIT_FIELD_ATTACK_POWER) + GetInt32Value(UNIT_FIELD_ATTACK_POWER_MODS);
        if (ap < 0)
            return 0.0f;
        return ap * (1.0f + GetFloatValue(UNIT_FIELD_ATTACK_POWER_MULTIPLIER));
    }
}

float Unit::GetWeaponDamageRange(WeaponAttackType attType , WeaponDamageRange type) const
{
    if (attType == OFF_ATTACK && !haveOffhandWeapon())
        return 0.0f;

    return m_weaponDamage[attType][type];
}

void Unit::SetLevel(uint8 lvl)
{
    SetUInt32Value(UNIT_FIELD_LEVEL, lvl);

    // group update
    if (GetTypeId() == TYPEID_PLAYER && ToPlayer()->GetGroup())
        ToPlayer()->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_LEVEL);
}

void Unit::SetHealth(uint32 val)
{
    if (getDeathState() == JUST_DIED)
        val = 0;
    else if (GetTypeId() == TYPEID_PLAYER && (getDeathState() == DEAD || getDeathState() == DEAD_FALLING))
        val = 1;
    else
    {
        uint32 maxHealth = GetMaxHealth();
        if (maxHealth < val)
            val = maxHealth;
    }

    SetUInt32Value(UNIT_FIELD_HEALTH, val);

    // group update
    if (Player* plr = ToPlayer())
    {
        if (plr->GetGroup())
            plr->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_CUR_HP);
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

void Unit::SetPower(Powers power, uint32 val)
{
    if (GetPower(power) == val)
        return;

    uint32 maxPower = GetMaxPower(power);
    if (maxPower < val)
        val = maxPower;

    SetStatInt32Value(UNIT_FIELD_POWER1 + power, val);

    WorldPacket data(SMSG_POWER_UPDATE);
    data.append(GetPackGUID());
    data << uint8(power);
    data << uint32(val);
    SendMessageToSet(&data, GetTypeId() == TYPEID_PLAYER ? true : false);

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
    SetStatInt32Value(UNIT_FIELD_MAXPOWER1 + power, val);

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

uint32 Unit::GetCreatePowers(Powers power) const
{
    // POWER_FOCUS and POWER_HAPPINESS only have hunter pet
    switch (power)
    {
        case POWER_MANA:      return GetCreateMana();
        case POWER_RAGE:      return 1000;
        case POWER_FOCUS:     return (GetTypeId() == TYPEID_PLAYER || !((Creature const*)this)->isPet() || ((Pet const*)this)->getPetType() != HUNTER_PET ? 0 : 100);
        case POWER_ENERGY:    return 100;
        case POWER_HAPPINESS: return (GetTypeId() == TYPEID_PLAYER || !((Creature const*)this)->isPet() || ((Pet const*)this)->getPetType() != HUNTER_PET ? 0 : 1050000);
        case POWER_RUNIC_POWER: return 1000;
        case POWER_RUNE:      return 0;
        case POWER_HEALTH:    return 0;
        default:
            break;
    }

    return 0;
}

void Unit::AddToWorld()
{
    if (!IsInWorld())
    {
        WorldObject::AddToWorld();
    }
}

void Unit::RemoveFromWorld()
{
    // cleanup
    ASSERT(GetGUID());

    if (IsInWorld())
    {
        m_duringRemoveFromWorld = true;
        if (IsVehicle())
            GetVehicleKit()->Uninstall();

        RemoveCharmAuras();
        RemoveBindSightAuras();
        RemoveNotOwnSingleTargetAuras();

        RemoveAllGameObjects();
        RemoveAllDynObjects();

        ExitVehicle();
        UnsummonAllTotems();
        RemoveAllControlled();

        RemoveAreaAurasDueToLeaveWorld();

        if (GetCharmerGUID())
        {
            sLog->outCrash("Unit %u has charmer guid when removed from world", GetEntry());
            ASSERT(false);
        }

        if (Unit* owner = GetOwner())
        {
            if (owner->m_Controlled.find(this) != owner->m_Controlled.end())
            {
                sLog->outCrash("Unit %u is in controlled list of %u when removed from world", GetEntry(), owner->GetEntry());
                ASSERT(false);
            }
        }

        WorldObject::RemoveFromWorld();
        m_duringRemoveFromWorld = false;
    }
}

void Unit::CleanupsBeforeDelete(bool finalCleanup)
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

    m_Events.KillAllEvents(false);                      // non-delatable (currently casted spells) will not deleted now but it will deleted at call in Map::RemoveAllObjectsInRemoveList
    CombatStop();
    ClearComboPointHolders();
    DeleteThreatList();
    getHostileRefManager().setOnlineOfflineState(false);
    GetMotionMaster()->Clear(false);                    // remove different non-standard movement generators.

    if (Creature* thisCreature = ToCreature())
        if (GetTransport())
            GetTransport()->RemovePassenger(thisCreature);
}

void Unit::UpdateCharmAI()
{
    if (GetTypeId() == TYPEID_PLAYER)
        return;

    if (i_disabledAI) // disabled AI must be primary AI
    {
        if (!isCharmed())
        {
            delete i_AI;
            i_AI = i_disabledAI;
            i_disabledAI = NULL;
        }
    }
    else
    {
        if (isCharmed())
        {
            i_disabledAI = i_AI;
            if (isPossessed() || IsVehicle())
                i_AI = new PossessedAI(ToCreature());
            else
                i_AI = new PetAI(ToCreature());
        }
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
    m_charmInfo = NULL;
}

CharmInfo::CharmInfo(Unit* unit)
: m_unit(unit), m_CommandState(COMMAND_FOLLOW), m_petnumber(0), m_barInit(false),
  m_isCommandAttack(false), m_isAtStay(false), m_isFollowing(false), m_isReturning(false)
{
    for (uint8 i = 0; i < MAX_SPELL_CHARM; ++i)
        m_charmspells[i].SetActionAndType(0, ACT_DISABLED);

    if (m_unit->GetTypeId() == TYPEID_UNIT)
    {
        m_oldReactState = m_unit->ToCreature()->GetReactState();
        m_unit->ToCreature()->SetReactState(REACT_PASSIVE);
    }
}

CharmInfo::~CharmInfo()
{
}

void CharmInfo::RestoreState()
{
    if (m_unit->GetTypeId() == TYPEID_UNIT)
        if (Creature *pCreature = m_unit->ToCreature())
            pCreature->SetReactState(m_oldReactState);
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
    InitEmptyActionBar();
    if (m_unit->GetTypeId() == TYPEID_UNIT)
    {
        for (uint32 i = 0; i < CREATURE_MAX_SPELLS; ++i)
        {
            uint32 spellId = m_unit->ToCreature()->m_spells[i];
            SpellEntry const* spellInfo = sSpellStore.LookupEntry(spellId);
            if (spellInfo && spellInfo->Attributes & SPELL_ATTR0_CASTABLE_WHILE_DEAD)
                spellId = 0;
            if (IsPassiveSpell(spellId))
                m_unit->CastSpell(m_unit, spellId, true);
            else
                AddSpellToActionBar(m_unit->ToCreature()->m_spells[i], ACT_PASSIVE);
        }
    }
}

void CharmInfo::InitCharmCreateSpells()
{
    if (m_unit->GetTypeId() == TYPEID_PLAYER)                //charmed players don't have spells
    {
        InitEmptyActionBar();
        return;
    }

    InitPetActionBar();

    for (uint32 x = 0; x < MAX_SPELL_CHARM; ++x)
    {
        uint32 spellId = m_unit->ToCreature()->m_spells[x];
        SpellEntry const* spellInfo = sSpellStore.LookupEntry(spellId);
        if (spellInfo && spellInfo->Attributes & SPELL_ATTR0_CASTABLE_WHILE_DEAD)
            spellId = 0;

        if (!spellId)
        {
            m_charmspells[x].SetActionAndType(spellId, ACT_DISABLED);
            continue;
        }

        if (IsPassiveSpell(spellId))
        {
            m_unit->CastSpell(m_unit, spellId, true);
            m_charmspells[x].SetActionAndType(spellId, ACT_PASSIVE);
        }
        else
        {
            m_charmspells[x].SetActionAndType(spellId, ACT_DISABLED);

            ActiveStates newstate = ACT_PASSIVE;
            if (spellInfo)
            {
                if (!IsAutocastableSpell(spellId))
                    newstate = ACT_PASSIVE;
                else
                {
                    bool autocast = false;
                    for (uint32 i = 0; i < MAX_SPELL_EFFECTS && !autocast; ++i)
                        if (SpellTargetType[spellInfo->EffectImplicitTargetA[i]] == TARGET_TYPE_UNIT_TARGET)
                            autocast = true;

                    if (autocast)
                    {
                        newstate = ACT_ENABLED;
                        ToggleCreatureAutocast(spellId, true);
                    }
                    else
                        newstate = ACT_DISABLED;
                }
            }

            AddSpellToActionBar(spellId, newstate);
        }
    }
}

bool CharmInfo::AddSpellToActionBar(uint32 spell_id, ActiveStates newstate)
{
    uint32 first_id = sSpellMgr->GetFirstSpellInChain(spell_id);

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
        if (!PetActionBar[i].GetAction() && PetActionBar[i].IsActionBarForSpell())
        {
            SetActionBar(i, spell_id, newstate == ACT_DECIDE ? IsAutocastableSpell(spell_id) ? ACT_DISABLED : ACT_PASSIVE : newstate);
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

void CharmInfo::ToggleCreatureAutocast(uint32 spellid, bool apply)
{
    if (IsPassiveSpell(spellid))
        return;

    for (uint32 x = 0; x < MAX_SPELL_CHARM; ++x)
        if (spellid == m_charmspells[x].GetAction())
            m_charmspells[x].SetType(apply ? ACT_ENABLED : ACT_DISABLED);
}

void CharmInfo::SetPetNumber(uint32 petnumber, bool statwindow)
{
    m_petnumber = petnumber;
    if (statwindow)
        m_unit->SetUInt32Value(UNIT_FIELD_PETNUMBER, m_petnumber);
    else
        m_unit->SetUInt32Value(UNIT_FIELD_PETNUMBER, 0);
}

void CharmInfo::LoadPetActionBar(const std::string& data)
{
    InitPetActionBar();

    Tokens tokens(data, ' ');

    if (tokens.size() != (ACTION_BAR_INDEX_END-ACTION_BAR_INDEX_START) * 2)
        return;                                             // non critical, will reset to default

    uint8 index;
    Tokens::iterator iter;
    for (iter = tokens.begin(), index = ACTION_BAR_INDEX_START; index < ACTION_BAR_INDEX_END; ++iter, ++index)
    {
        // use unsigned cast to avoid sign negative format use at long-> ActiveStates (int) conversion
        ActiveStates type  = ActiveStates(atol(*iter));
        ++iter;
        uint32 action = uint32(atol(*iter));

        PetActionBar[index].SetActionAndType(action, type);

        // check correctness
        if (PetActionBar[index].IsActionBarForSpell())
        {
            if (!sSpellStore.LookupEntry(PetActionBar[index].GetAction()))
                SetActionBar(index, 0, ACT_PASSIVE);
            else if (!IsAutocastableSpell(PetActionBar[index].GetAction()))
                SetActionBar(index, PetActionBar[index].GetAction(), ACT_PASSIVE);
        }
    }
}

void CharmInfo::BuildActionBar(WorldPacket* data)
{
    for (uint32 i = 0; i < MAX_UNIT_ACTION_BAR_INDEX; ++i)
        *data << uint32(PetActionBar[i].packedData);
}

void CharmInfo::SetSpellAutocast(uint32 spell_id, bool state)
{
    for (uint8 i = 0; i < MAX_UNIT_ACTION_BAR_INDEX; ++i)
    {
        if (spell_id == PetActionBar[i].GetAction() && PetActionBar[i].IsActionBarForSpell())
        {
            PetActionBar[i].SetType(state ? ACT_ENABLED : ACT_DISABLED);
            break;
        }
    }
}

bool Unit::isFrozen() const
{
    return HasAuraState(AURA_STATE_FROZEN);
}

struct ProcTriggeredData
{
    ProcTriggeredData(Aura* _aura)
        : aura(_aura)
    {
        effMask = 0;
        spellProcEvent = NULL;
    }
    SpellProcEventEntry const* spellProcEvent;
    Aura* aura;
    uint32 effMask;
};

typedef std::list< ProcTriggeredData > ProcTriggeredList;

// List of auras that CAN be trigger but may not exist in spell_proc_event
// in most case need for drop charges
// in some types of aura need do additional check
// for example SPELL_AURA_MECHANIC_IMMUNITY - need check for mechanic
bool InitTriggerAuraData()
{
    for (uint16 i = 0; i < TOTAL_AURAS; ++i)
    {
        isTriggerAura[i] = false;
        isNonTriggerAura[i] = false;
        isAlwaysTriggeredAura[i] = false;
    }
    isTriggerAura[SPELL_AURA_DUMMY] = true;
    isTriggerAura[SPELL_AURA_MOD_CONFUSE] = true;
    isTriggerAura[SPELL_AURA_MOD_THREAT] = true;
    isTriggerAura[SPELL_AURA_MOD_STUN] = true; // Aura not have charges but need remove him on trigger
    isTriggerAura[SPELL_AURA_MOD_DAMAGE_DONE] = true;
    isTriggerAura[SPELL_AURA_MOD_DAMAGE_TAKEN] = true;
    isTriggerAura[SPELL_AURA_MOD_RESISTANCE] = true;
    isTriggerAura[SPELL_AURA_MOD_STEALTH] = true;
    isTriggerAura[SPELL_AURA_MOD_FEAR] = true; // Aura not have charges but need remove him on trigger
    isTriggerAura[SPELL_AURA_MOD_ROOT] = true;
    isTriggerAura[SPELL_AURA_TRANSFORM] = true;
    isTriggerAura[SPELL_AURA_REFLECT_SPELLS] = true;
    isTriggerAura[SPELL_AURA_DAMAGE_IMMUNITY] = true;
    isTriggerAura[SPELL_AURA_PROC_TRIGGER_SPELL] = true;
    isTriggerAura[SPELL_AURA_PROC_TRIGGER_DAMAGE] = true;
    isTriggerAura[SPELL_AURA_MOD_CASTING_SPEED_NOT_STACK] = true;
    isTriggerAura[SPELL_AURA_SCHOOL_ABSORB] = true; // Savage Defense untested
    isTriggerAura[SPELL_AURA_MOD_POWER_COST_SCHOOL_PCT] = true;
    isTriggerAura[SPELL_AURA_MOD_POWER_COST_SCHOOL] = true;
    isTriggerAura[SPELL_AURA_REFLECT_SPELLS_SCHOOL] = true;
    isTriggerAura[SPELL_AURA_MECHANIC_IMMUNITY] = true;
    isTriggerAura[SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN] = true;
    isTriggerAura[SPELL_AURA_SPELL_MAGNET] = true;
    isTriggerAura[SPELL_AURA_MOD_ATTACK_POWER] = true;
    isTriggerAura[SPELL_AURA_ADD_CASTER_HIT_TRIGGER] = true;
    isTriggerAura[SPELL_AURA_OVERRIDE_CLASS_SCRIPTS] = true;
    isTriggerAura[SPELL_AURA_MOD_MECHANIC_RESISTANCE] = true;
    isTriggerAura[SPELL_AURA_RANGED_ATTACK_POWER_ATTACKER_BONUS] = true;
    isTriggerAura[SPELL_AURA_MOD_MELEE_HASTE] = true;
    isTriggerAura[SPELL_AURA_MOD_ATTACKER_MELEE_HIT_CHANCE] = true;
    isTriggerAura[SPELL_AURA_RAID_PROC_FROM_CHARGE] = true;
    isTriggerAura[SPELL_AURA_RAID_PROC_FROM_CHARGE_WITH_VALUE] = true;
    isTriggerAura[SPELL_AURA_PROC_TRIGGER_SPELL_WITH_VALUE] = true;
    isTriggerAura[SPELL_AURA_MOD_DAMAGE_FROM_CASTER] = true;
    isTriggerAura[SPELL_AURA_MOD_SPELL_CRIT_CHANCE] = true;
    isTriggerAura[SPELL_AURA_ABILITY_IGNORE_AURASTATE] = true;

    isNonTriggerAura[SPELL_AURA_MOD_POWER_REGEN] = true;
    isNonTriggerAura[SPELL_AURA_REDUCE_PUSHBACK] = true;

    isAlwaysTriggeredAura[SPELL_AURA_OVERRIDE_CLASS_SCRIPTS] = true;
    isAlwaysTriggeredAura[SPELL_AURA_MOD_FEAR] = true;
    isAlwaysTriggeredAura[SPELL_AURA_MOD_ROOT] = true;
    isAlwaysTriggeredAura[SPELL_AURA_MOD_STUN] = true;
    isAlwaysTriggeredAura[SPELL_AURA_TRANSFORM] = true;
    isAlwaysTriggeredAura[SPELL_AURA_SPELL_MAGNET] = true;
    isAlwaysTriggeredAura[SPELL_AURA_SCHOOL_ABSORB] = true;
    isAlwaysTriggeredAura[SPELL_AURA_MOD_STEALTH] = true;

    return true;
}

uint32 createProcExtendMask(SpellNonMeleeDamage *damageInfo, SpellMissInfo missCondition)
{
    uint32 procEx = PROC_EX_NONE;
    // Check victim state
    if (missCondition != SPELL_MISS_NONE)
        switch (missCondition)
        {
            case SPELL_MISS_MISS:    procEx|=PROC_EX_MISS;   break;
            case SPELL_MISS_RESIST:  procEx|=PROC_EX_RESIST; break;
            case SPELL_MISS_DODGE:   procEx|=PROC_EX_DODGE;  break;
            case SPELL_MISS_PARRY:   procEx|=PROC_EX_PARRY;  break;
            case SPELL_MISS_BLOCK:   procEx|=PROC_EX_BLOCK;  break;
            case SPELL_MISS_EVADE:   procEx|=PROC_EX_EVADE;  break;
            case SPELL_MISS_IMMUNE:  procEx|=PROC_EX_IMMUNE; break;
            case SPELL_MISS_IMMUNE2: procEx|=PROC_EX_IMMUNE; break;
            case SPELL_MISS_DEFLECT: procEx|=PROC_EX_DEFLECT;break;
            case SPELL_MISS_ABSORB:  procEx|=PROC_EX_ABSORB; break;
            case SPELL_MISS_REFLECT: procEx|=PROC_EX_REFLECT;break;
            default:
                break;
        }
    else
    {
        // On block
        if (damageInfo->blocked)
            procEx|=PROC_EX_BLOCK;
        // On absorb
        if (damageInfo->absorb)
            procEx|=PROC_EX_ABSORB;
        // On crit
        if (damageInfo->HitInfo & SPELL_HIT_TYPE_CRIT)
            procEx|=PROC_EX_CRITICAL_HIT;
        else
            procEx|=PROC_EX_NORMAL_HIT;
    }
    return procEx;
}

void Unit::ProcDamageAndSpellFor(bool isVictim, Unit* pTarget, uint32 procFlag, uint32 procExtra, WeaponAttackType attType, SpellEntry const* procSpell, uint32 damage, SpellEntry const* procAura)
{
    // Player is loaded now - do not allow passive spell casts to proc
    if (GetTypeId() == TYPEID_PLAYER && ToPlayer()->GetSession()->PlayerLoading())
        return;
    // For melee/ranged based attack need update skills and set some Aura states if victim present
    if (procFlag & MELEE_BASED_TRIGGER_MASK && pTarget)
    {
        // Update skills here for players
        if (GetTypeId() == TYPEID_PLAYER)
        {
            // On melee based hit/miss/resist need update skill (for victim and attacker)
            if (procExtra & (PROC_EX_NORMAL_HIT|PROC_EX_MISS|PROC_EX_RESIST))
            {
                if (pTarget->GetTypeId() != TYPEID_PLAYER && pTarget->GetCreatureType() != CREATURE_TYPE_CRITTER)
                    ToPlayer()->UpdateCombatSkills(pTarget, attType, isVictim);
            }
            // Update defence if player is victim and parry/dodge/block
            else if (isVictim && procExtra & (PROC_EX_DODGE|PROC_EX_PARRY|PROC_EX_BLOCK))
                ToPlayer()->UpdateCombatSkills(pTarget, attType, true);
        }
        // If exist crit/parry/dodge/block need update aura state (for victim and attacker)
        if (procExtra & (PROC_EX_CRITICAL_HIT|PROC_EX_PARRY|PROC_EX_DODGE|PROC_EX_BLOCK))
        {
            // for victim
            if (isVictim)
            {
                // if victim and dodge attack
                if (procExtra & PROC_EX_DODGE)
                {
                    // Update AURA_STATE on dodge
                    if (getClass() != CLASS_ROGUE) // skip Rogue Riposte
                    {
                        ModifyAuraState(AURA_STATE_DEFENSE, true);
                        StartReactiveTimer(REACTIVE_DEFENSE);
                    }
                }
                // if victim and parry attack
                if (procExtra & PROC_EX_PARRY)
                {
                    // For Hunters only Counterattack (skip Mongoose bite)
                    if (getClass() == CLASS_HUNTER)
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
                if (procExtra & PROC_EX_BLOCK)
                {
                    ModifyAuraState(AURA_STATE_DEFENSE, true);
                    StartReactiveTimer(REACTIVE_DEFENSE);
                }
            }
            else // For attacker
            {
                // Overpower on victim dodge
                if (procExtra & PROC_EX_DODGE && GetTypeId() == TYPEID_PLAYER && getClass() == CLASS_WARRIOR)
                {
                    ToPlayer()->AddComboPoints(pTarget, 1);
                    StartReactiveTimer(REACTIVE_OVERPOWER);
                }
            }
        }
    }

    ProcTriggeredList procTriggered;
    // Fill procTriggered list
    for (AuraApplicationMap::const_iterator itr = GetAppliedAuras().begin(); itr!= GetAppliedAuras().end(); ++itr)
    {
        // Do not allow auras to proc from effect triggered by itself
        if (procAura && procAura->Id == itr->first)
            continue;
        ProcTriggeredData triggerData(itr->second->GetBase());
        // Defensive procs are active on absorbs (so absorption effects are not a hindrance)
        bool active = (damage > 0) || (procExtra & (PROC_EX_ABSORB|PROC_EX_BLOCK) && isVictim);
        if (isVictim)
            procExtra &= ~PROC_EX_INTERNAL_REQ_FAMILY;
        SpellEntry const* spellProto = itr->second->GetBase()->GetSpellProto();
        if (!IsTriggeredAtSpellProcEvent(pTarget, triggerData.aura, procSpell, procFlag, procExtra, attType, isVictim, active, triggerData.spellProcEvent))
            continue;

        // Triggered spells not triggering additional spells
        bool triggered= !(spellProto->AttributesEx3 & SPELL_ATTR3_CAN_PROC_TRIGGERED) ?
            (procExtra & PROC_EX_INTERNAL_TRIGGERED && !(procFlag & PROC_FLAG_DONE_TRAP_ACTIVATION)) : false;

        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        {
            if (itr->second->HasEffect(i))
            {
                AuraEffect* aurEff = itr->second->GetBase()->GetEffect(i);
                // Skip this auras
                if (isNonTriggerAura[aurEff->GetAuraType()])
                    continue;
                // If not trigger by default and spellProcEvent == NULL - skip
                if (!isTriggerAura[aurEff->GetAuraType()] && triggerData.spellProcEvent == NULL)
                    continue;
                // Some spells must always trigger
                if (!triggered || isAlwaysTriggeredAura[aurEff->GetAuraType()])
                    triggerData.effMask |= 1<<i;
            }
        }
        if (triggerData.effMask)
            procTriggered.push_front(triggerData);
    }

    // Nothing found
    if (procTriggered.empty())
        return;

    if (procExtra & (PROC_EX_INTERNAL_TRIGGERED | PROC_EX_INTERNAL_CANT_PROC))
        SetCantProc(true);

    // Handle effects proceed this time
    for (ProcTriggeredList::const_iterator i = procTriggered.begin(); i != procTriggered.end(); ++i)
    {
        // look for aura in auras list, it may be removed while proc event processing
        if (i->aura->IsRemoved())
            continue;

        bool useCharges  = i->aura->GetCharges() > 0;
        bool takeCharges = false;
        SpellEntry const* spellInfo = i->aura->GetSpellProto();
        uint32 Id = i->aura->GetId();

        // For players set spell cooldown if need
        uint32 cooldown = 0;
        if (GetTypeId() == TYPEID_PLAYER && i->spellProcEvent && i->spellProcEvent->cooldown)
            cooldown = i->spellProcEvent->cooldown;

        if (spellInfo->AttributesEx3 & SPELL_ATTR3_DISABLE_PROC)
            SetCantProc(true);

        // This bool is needed till separate aura effect procs are still here
        bool handled = false;
        if (HandleAuraProc(pTarget, damage, i->aura, procSpell, procFlag, procExtra, cooldown, &handled))
        {
            sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "ProcDamageAndSpell: casting spell %u (triggered with value by %s aura of spell %u)", spellInfo->Id, (isVictim?"a victim's":"an attacker's"), Id);
            takeCharges = true;
        }

        if (!handled)
        for (uint8 effIndex = 0; effIndex<MAX_SPELL_EFFECTS; ++effIndex)
        {
            if (!(i->effMask & (1<<effIndex)))
                continue;

            AuraEffect* triggeredByAura = i->aura->GetEffect(effIndex);
            ASSERT(triggeredByAura);

            switch(triggeredByAura->GetAuraType())
            {
                case SPELL_AURA_PROC_TRIGGER_SPELL:
                {
                    sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "ProcDamageAndSpell: casting spell %u (triggered by %s aura of spell %u)", spellInfo->Id, (isVictim?"a victim's":"an attacker's"), triggeredByAura->GetId());
                    // Don`t drop charge or add cooldown for not started trigger
                    if (HandleProcTriggerSpell(pTarget, damage, triggeredByAura, procSpell, procFlag, procExtra, cooldown))
                        takeCharges = true;
                    break;
                }
                case SPELL_AURA_PROC_TRIGGER_DAMAGE:
                {
                    sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "ProcDamageAndSpell: doing %u damage from spell id %u (triggered by %s aura of spell %u)", triggeredByAura->GetAmount() , spellInfo->Id, (isVictim?"a victim's":"an attacker's"), triggeredByAura->GetId());
                    SpellNonMeleeDamage damageInfo(this, pTarget, spellInfo->Id, spellInfo->SchoolMask);
                    uint32 damage = SpellDamageBonus(pTarget, spellInfo, triggeredByAura->GetAmount(), SPELL_DIRECT_DAMAGE);
                    CalculateSpellDamageTaken(&damageInfo, damage, spellInfo);
                    DealDamageMods(damageInfo.target, damageInfo.damage, &damageInfo.absorb);
                    SendSpellNonMeleeDamageLog(&damageInfo);
                    DealSpellDamage(&damageInfo, true);
                    takeCharges = true;
                    break;
                }
                case SPELL_AURA_MANA_SHIELD:
                case SPELL_AURA_DUMMY:
                {
                    sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "ProcDamageAndSpell: casting spell id %u (triggered by %s dummy aura of spell %u)", spellInfo->Id, (isVictim?"a victim's":"an attacker's"), triggeredByAura->GetId());
                    if (HandleDummyAuraProc(pTarget, damage, triggeredByAura, procSpell, procFlag, procExtra, cooldown))
                        takeCharges = true;
                    break;
                }
                case SPELL_AURA_OBS_MOD_POWER:
                    sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "ProcDamageAndSpell: casting spell id %u (triggered by %s aura of spell %u)", spellInfo->Id, (isVictim?"a victim's":"an attacker's"), triggeredByAura->GetId());
                    if (HandleObsModEnergyAuraProc(pTarget, damage, triggeredByAura, procSpell, procFlag, procExtra, cooldown))
                        takeCharges = true;
                    break;
                case SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN:
                    sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "ProcDamageAndSpell: casting spell id %u (triggered by %s aura of spell %u)", spellInfo->Id, (isVictim?"a victim's":"an attacker's"), triggeredByAura->GetId());
                    if (HandleModDamagePctTakenAuraProc(pTarget, damage, triggeredByAura, procSpell, procFlag, procExtra, cooldown))
                        takeCharges = true;
                    break;
                case SPELL_AURA_MOD_MELEE_HASTE:
                {
                    sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "ProcDamageAndSpell: casting spell id %u (triggered by %s haste aura of spell %u)", spellInfo->Id, (isVictim?"a victim's":"an attacker's"), triggeredByAura->GetId());
                    if (HandleHasteAuraProc(pTarget, damage, triggeredByAura, procSpell, procFlag, procExtra, cooldown))
                        takeCharges = true;
                    break;
                }
                case SPELL_AURA_OVERRIDE_CLASS_SCRIPTS:
                {
                    sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "ProcDamageAndSpell: casting spell id %u (triggered by %s aura of spell %u)", spellInfo->Id, (isVictim?"a victim's":"an attacker's"), triggeredByAura->GetId());
                    if (HandleOverrideClassScriptAuraProc(pTarget, damage, triggeredByAura, procSpell, cooldown))
                        takeCharges = true;
                    break;
                }
                case SPELL_AURA_RAID_PROC_FROM_CHARGE_WITH_VALUE:
                {
                    sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "ProcDamageAndSpell: casting mending (triggered by %s dummy aura of spell %u)",
                        (isVictim?"a victim's":"an attacker's"), triggeredByAura->GetId());

                    HandleAuraRaidProcFromChargeWithValue(triggeredByAura);
                    takeCharges = true;
                    break;
                }
                case SPELL_AURA_RAID_PROC_FROM_CHARGE:
                {
                    sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "ProcDamageAndSpell: casting mending (triggered by %s dummy aura of spell %u)",
                        (isVictim?"a victim's":"an attacker's"), triggeredByAura->GetId());

                    HandleAuraRaidProcFromCharge(triggeredByAura);
                    takeCharges = true;
                    break;
                }
                case SPELL_AURA_PROC_TRIGGER_SPELL_WITH_VALUE:
                {
                    sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "ProcDamageAndSpell: casting spell %u (triggered with value by %s aura of spell %u)", spellInfo->Id, (isVictim?"a victim's":"an attacker's"), triggeredByAura->GetId());

                    if (HandleProcTriggerSpell(pTarget, damage, triggeredByAura, procSpell, procFlag, procExtra, cooldown))
                        takeCharges = true;
                    break;
                }
                case SPELL_AURA_MOD_CASTING_SPEED_NOT_STACK:
                    // Skip melee hits or instant cast spells
                    if (procSpell && GetSpellCastTime(procSpell) != 0)
                        takeCharges = true;
                    break;
                case SPELL_AURA_REFLECT_SPELLS_SCHOOL:
                    // Skip Melee hits and spells ws wrong school
                    if (procSpell && (triggeredByAura->GetMiscValue() & procSpell->SchoolMask))         // School check
                        takeCharges = true;
                    break;
                case SPELL_AURA_MOD_POWER_COST_SCHOOL_PCT:
                case SPELL_AURA_MOD_POWER_COST_SCHOOL:
                    // Skip melee hits and spells ws wrong school or zero cost
                    if (procSpell &&
                        (procSpell->manaCost != 0 || procSpell->ManaCostPercentage != 0) && // Cost check
                        (triggeredByAura->GetMiscValue() & procSpell->SchoolMask))          // School check
                        takeCharges = true;
                    break;
                case SPELL_AURA_MECHANIC_IMMUNITY:
                    // Compare mechanic
                    if (procSpell && procSpell->Mechanic == uint32(triggeredByAura->GetMiscValue()))
                        takeCharges = true;
                    break;
                case SPELL_AURA_MOD_MECHANIC_RESISTANCE:
                    // Compare mechanic
                    if (procSpell && procSpell->Mechanic == uint32(triggeredByAura->GetMiscValue()))
                        takeCharges = true;
                    break;
                case SPELL_AURA_MOD_DAMAGE_FROM_CASTER:
                    // Compare casters
                    if (triggeredByAura->GetCasterGUID() == pTarget->GetGUID())
                        takeCharges = true;
                    break;
                case SPELL_AURA_MOD_SPELL_CRIT_CHANCE:
                    sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "ProcDamageAndSpell: casting spell id %u (triggered by %s spell crit chance aura of spell %u)", spellInfo->Id, (isVictim?"a victim's":"an attacker's"), triggeredByAura->GetId());
                    if (procSpell && HandleSpellCritChanceAuraProc(pTarget, damage, triggeredByAura, procSpell, procFlag, procExtra, cooldown))
                        takeCharges = true;
                    break;
                // CC Auras which use their amount amount to drop
                // Are there any more auras which need this?
                case SPELL_AURA_MOD_CONFUSE:
                case SPELL_AURA_MOD_FEAR:
                case SPELL_AURA_MOD_STUN:
                case SPELL_AURA_MOD_ROOT:
                case SPELL_AURA_TRANSFORM:
                {
                    // chargeable mods are breaking on hit
                    if (useCharges)
                        takeCharges = true;
                    else
                    {
                        // Spell own direct damage at apply wont break the CC
                        if (procSpell && (procSpell->Id == triggeredByAura->GetId()))
                        {
                            Aura* aura = triggeredByAura->GetBase();
                            // called from spellcast, should not have ticked yet
                            if (aura->GetDuration() == aura->GetMaxDuration())
                                break;
                        }
                        int32 damageLeft = triggeredByAura->GetAmount();
                        // No damage left
                        if (damageLeft < int32(damage))
                            i->aura->Remove();
                        else
                            triggeredByAura->SetAmount(damageLeft - damage);
                    }
                    break;
                }
                //case SPELL_AURA_ADD_FLAT_MODIFIER:
                //case SPELL_AURA_ADD_PCT_MODIFIER:
                    // HandleSpellModAuraProc
                    //break;
                default:
                    // nothing do, just charges counter
                    takeCharges = true;
                    break;
            }
        }
        // Remove charge (aura can be removed by triggers)
        if (useCharges && takeCharges)
            i->aura->DropCharge(AURA_REMOVE_BY_EXPIRE);

        if (spellInfo->AttributesEx3 & SPELL_ATTR3_DISABLE_PROC)
            SetCantProc(false);
    }

    // Cleanup proc requirements
    if (procExtra & (PROC_EX_INTERNAL_TRIGGERED | PROC_EX_INTERNAL_CANT_PROC))
        SetCantProc(false);
}

SpellSchoolMask Unit::GetMeleeDamageSchoolMask() const
{
    return SPELL_SCHOOL_MASK_NORMAL;
}

Player* Unit::GetSpellModOwner() const
{
    if (GetTypeId() == TYPEID_PLAYER)
        return (Player*)this;
    if (ToCreature()->isPet() || ToCreature()->isTotem())
    {
        Unit* owner = GetOwner();
        if (owner && owner->GetTypeId() == TYPEID_PLAYER)
            return (Player*)owner;
    }
    return NULL;
}

///----------Pet responses methods-----------------
void Unit::SendPetCastFail(uint32 spellid, SpellCastResult msg)
{
    if (msg == SPELL_CAST_OK)
        return;

    Unit* owner = GetCharmerOrOwner();
    if (!owner || owner->GetTypeId() != TYPEID_PLAYER)
        return;

    WorldPacket data(SMSG_PET_CAST_FAILED, 1 + 4 + 1);
    data << uint8(0);                                       // cast count?
    data << uint32(spellid);
    data << uint8(msg);
    // uint32 for some reason
    // uint32 for some reason
    owner->ToPlayer()->GetSession()->SendPacket(&data);
}

void Unit::SendPetActionFeedback (uint8 msg)
{
    Unit* owner = GetOwner();
    if (!owner || owner->GetTypeId() != TYPEID_PLAYER)
        return;

    WorldPacket data(SMSG_PET_ACTION_FEEDBACK, 1);
    data << uint8(msg);
    owner->ToPlayer()->GetSession()->SendPacket(&data);
}

void Unit::SendPetTalk (uint32 pettalk)
{
    Unit* owner = GetOwner();
    if (!owner || owner->GetTypeId() != TYPEID_PLAYER)
        return;

    WorldPacket data(SMSG_PET_ACTION_SOUND, 8 + 4);
    data << uint64(GetGUID());
    data << uint32(pettalk);
    owner->ToPlayer()->GetSession()->SendPacket(&data);
}

void Unit::SendPetAIReaction(uint64 guid)
{
    Unit* owner = GetOwner();
    if (!owner || owner->GetTypeId() != TYPEID_PLAYER)
        return;

    WorldPacket data(SMSG_AI_REACTION, 8 + 4);
    data << uint64(guid);
    data << uint32(AI_REACTION_HOSTILE);
    owner->ToPlayer()->GetSession()->SendPacket(&data);
}

///----------End of Pet responses methods----------

void Unit::StopMoving()
{
    ClearUnitState(UNIT_STAT_MOVING);

    // send explicit stop packet
    // rely on vmaps here because for example stormwind is in air
    //float z = sMapMgr->GetBaseMap(GetMapId())->GetHeight(GetPositionX(), GetPositionY(), GetPositionZ(), true);
    //if (fabs(GetPositionZ() - z) < 2.0f)
    //    Relocate(GetPositionX(), GetPositionY(), z);
    //Relocate(GetPositionX(), GetPositionY(), GetPositionZ());

    if (!(GetUnitMovementFlags() & MOVEMENTFLAG_ONTRANSPORT))
        SendMonsterStop();
}

void Unit::SendMovementFlagUpdate()
{
    WorldPacket data;
    BuildHeartBeatMsg(&data);
    SendMessageToSet(&data, false);
}

bool Unit::IsSitState() const
{
    uint8 s = getStandState();
    return
        s == UNIT_STAND_STATE_SIT_CHAIR        || s == UNIT_STAND_STATE_SIT_LOW_CHAIR  ||
        s == UNIT_STAND_STATE_SIT_MEDIUM_CHAIR || s == UNIT_STAND_STATE_SIT_HIGH_CHAIR ||
        s == UNIT_STAND_STATE_SIT;
}

bool Unit::IsStandState() const
{
    uint8 s = getStandState();
    return !IsSitState() && s != UNIT_STAND_STATE_SLEEP && s != UNIT_STAND_STATE_KNEEL;
}

void Unit::SetStandState(uint8 state)
{
    SetByteValue(UNIT_FIELD_BYTES_1, 0, state);

    if (IsStandState())
       RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_NOT_SEATED);

    if (GetTypeId() == TYPEID_PLAYER)
    {
        WorldPacket data(SMSG_STANDSTATE_UPDATE, 1);
        data << (uint8)state;
        ToPlayer()->GetSession()->SendPacket(&data);
    }
}

bool Unit::IsPolymorphed() const
{
    uint32 transformId = getTransForm();
    if (!transformId)
        return false;

    SpellEntry const* spellInfo = sSpellStore.LookupEntry(transformId);
    if (!spellInfo)
        return false;

    return GetSpellSpecific(spellInfo) == SPELL_SPECIFIC_MAGE_POLYMORPH;
}

void Unit::SetDisplayId(uint32 modelId)
{
    SetUInt32Value(UNIT_FIELD_DISPLAYID, modelId);

    if (GetTypeId() == TYPEID_UNIT && ToCreature()->isPet())
    {
        Pet* pet = ToPet();
        if (!pet->isControlled())
            return;
        Unit* owner = GetOwner();
        if (owner && (owner->GetTypeId() == TYPEID_PLAYER) && owner->ToPlayer()->GetGroup())
            owner->ToPlayer()->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_PET_MODEL_ID);
    }
}

void Unit::RestoreDisplayId()
{
    AuraEffect* handledAura = NULL;
    // try to receive model from transform auras
    Unit::AuraEffectList const& transforms = GetAuraEffectsByType(SPELL_AURA_TRANSFORM);
    if (!transforms.empty())
    {
        // iterate over already applied transform auras - from newest to oldest
        for (Unit::AuraEffectList::const_reverse_iterator i = transforms.rbegin(); i != transforms.rend(); ++i)
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
    // transform aura was found
    if (handledAura)
        handledAura->HandleEffect(this, AURA_EFFECT_HANDLE_SEND_FOR_CLIENT, true);
    // we've found shapeshift
    else if (uint32 modelId = GetModelForForm(GetShapeshiftForm()))
        SetDisplayId(modelId);
    // no auras found - set modelid to default
    else
        SetDisplayId(GetNativeDisplayId());
}

void Unit::ClearComboPointHolders()
{
    while (!m_ComboPointHolders.empty())
    {
        uint32 lowguid = *m_ComboPointHolders.begin();

        Player* plr = sObjectMgr->GetPlayer(MAKE_NEW_GUID(lowguid, 0, HIGHGUID_PLAYER));
        if (plr && plr->GetComboTarget() == GetGUID())         // recheck for safe
            plr->ClearComboPoints();                        // remove also guid from m_ComboPointHolders;
        else
            m_ComboPointHolders.erase(lowguid);             // or remove manually
    }
}

void Unit::ClearAllReactives()
{
    for (uint8 i = 0; i < MAX_REACTIVE; ++i)
        m_reactiveTimer[i] = 0;

    if (HasAuraState(AURA_STATE_DEFENSE))
        ModifyAuraState(AURA_STATE_DEFENSE, false);
    if (getClass() == CLASS_HUNTER && HasAuraState(AURA_STATE_HUNTER_PARRY))
        ModifyAuraState(AURA_STATE_HUNTER_PARRY, false);
    if (getClass() == CLASS_WARRIOR && GetTypeId() == TYPEID_PLAYER)
        ToPlayer()->ClearComboPoints();
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
                    if (getClass() == CLASS_HUNTER && HasAuraState(AURA_STATE_HUNTER_PARRY))
                        ModifyAuraState(AURA_STATE_HUNTER_PARRY, false);
                    break;
                case REACTIVE_OVERPOWER:
                    if (getClass() == CLASS_WARRIOR && GetTypeId() == TYPEID_PLAYER)
                        ToPlayer()->ClearComboPoints();
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

Unit* Unit::SelectNearbyTarget(float dist) const
{
    std::list<Unit *> targets;
    Trinity::AnyUnfriendlyUnitInObjectRangeCheck u_check(this, this, dist);
    Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> searcher(this, targets, u_check);
    VisitNearbyObject(dist, searcher);

    // remove current target
    if (getVictim())
        targets.remove(getVictim());

    // remove not LoS targets
    for (std::list<Unit*>::iterator tIter = targets.begin(); tIter != targets.end();)
    {
        if (!IsWithinLOSInMap(*tIter) || (*tIter)->isTotem() || (*tIter)->isSpiritService() || (*tIter)->GetCreatureType() == CREATURE_TYPE_CRITTER)
            targets.erase(tIter++);
        else
            ++tIter;
    }

    // no appropriate targets
    if (targets.empty())
        return NULL;

    // select random
    std::list<Unit*>::const_iterator tcIter = targets.begin();
    std::advance(tcIter, urand(0, targets.size()-1));
    return *tcIter;
}

void Unit::ApplyAttackTimePercentMod(WeaponAttackType att, float val, bool apply)
{
    float remainingTimePct = (float)m_attackTimer[att] / (GetAttackTime(att) * m_modAttackSpeedPct[att]);
    if (val > 0)
    {
        ApplyPercentModFloatVar(m_modAttackSpeedPct[att], val, !apply);
        ApplyPercentModFloatValue(UNIT_FIELD_BASEATTACKTIME+att, val, !apply);
    }
    else
    {
        ApplyPercentModFloatVar(m_modAttackSpeedPct[att], -val, apply);
        ApplyPercentModFloatValue(UNIT_FIELD_BASEATTACKTIME+att, -val, apply);
    }
    m_attackTimer[att] = uint32(GetAttackTime(att) * m_modAttackSpeedPct[att] * remainingTimePct);
}

void Unit::ApplyCastTimePercentMod(float val, bool apply)
{
    if (val > 0)
        ApplyPercentModFloatValue(UNIT_MOD_CAST_SPEED, val, !apply);
    else
        ApplyPercentModFloatValue(UNIT_MOD_CAST_SPEED, -val, apply);
}

uint32 Unit::GetCastingTimeForBonus(SpellEntry const *spellProto, DamageEffectType damagetype, uint32 CastingTime)
{
    // Not apply this to creature casted spells with casttime == 0
    if (CastingTime == 0 && GetTypeId() == TYPEID_UNIT && !ToCreature()->isPet())
        return 3500;

    if (CastingTime > 7000) CastingTime = 7000;
    if (CastingTime < 1500) CastingTime = 1500;

    if (damagetype == DOT && !IsChanneledSpell(spellProto))
        CastingTime = 3500;

    int32 overTime    = 0;
    uint8 effects     = 0;
    bool DirectDamage = false;
    bool AreaEffect   = false;

    for (uint32 i = 0; i < MAX_SPELL_EFFECTS; i++)
    {
        switch (spellProto->Effect[i])
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
                switch (spellProto->EffectApplyAuraName[i])
                {
                    case SPELL_AURA_PERIODIC_DAMAGE:
                    case SPELL_AURA_PERIODIC_HEAL:
                    case SPELL_AURA_PERIODIC_LEECH:
                        if (GetSpellDuration(spellProto))
                            overTime = GetSpellDuration(spellProto);
                        break;
                    default:
                        // -5% per additional effect
                        ++effects;
                        break;
                }
            default:
                break;
        }

        if (IsAreaEffectTarget[spellProto->EffectImplicitTargetA[i]] || IsAreaEffectTarget[spellProto->EffectImplicitTargetB[i]])
            AreaEffect = true;
    }

    // Combined Spells with Both Over Time and Direct Damage
    if (overTime > 0 && CastingTime > 0 && DirectDamage)
    {
        // mainly for DoTs which are 3500 here otherwise
        uint32 OriginalCastTime = GetSpellCastTime(spellProto);
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

    // -5% of total per any additional effect
    for (uint8 i = 0; i < effects; ++i)
    {
        if (CastingTime > 175)
        {
            CastingTime -= 175;
        }
        else
        {
            CastingTime = 0;
            break;
        }
    }

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
    else if (GetTypeId() == TYPEID_UNIT && ToCreature()->isPet())
    {
        Pet *pet = ((Pet*)this);
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

float Unit::GetAPMultiplier(WeaponAttackType attType, bool normalized)
{
    if (!normalized || GetTypeId() != TYPEID_PLAYER)
        return float(GetAttackTime(attType)) / 1000.0f;

    Item* Weapon = ToPlayer()->GetWeaponForAttack(attType, true);
    if (!Weapon)
        return 2.4f;                                         // fist attack

    switch (Weapon->GetTemplate()->InventoryType)
    {
        case INVTYPE_2HWEAPON:
            return 3.3f;
        case INVTYPE_RANGED:
        case INVTYPE_RANGEDRIGHT:
        case INVTYPE_THROWN:
            return 2.8f;
        case INVTYPE_WEAPON:
        case INVTYPE_WEAPONMAINHAND:
        case INVTYPE_WEAPONOFFHAND:
        default:
            return Weapon->GetTemplate()->SubClass == ITEM_SUBCLASS_WEAPON_DAGGER ? 1.7f : 2.4f;
    }
}

bool Unit::IsUnderLastManaUseEffect() const
{
    return  getMSTimeDiff(m_lastManaUse, getMSTime()) < 5000;
}

void Unit::SetContestedPvP(Player *attackedPlayer)
{
    Player* player = GetCharmerOrOwnerPlayerOrPlayerItself();

    if (!player || (attackedPlayer && (attackedPlayer == player || (player->duel && player->duel->opponent == attackedPlayer))))
        return;

    player->SetContestedPvPTimer(30000);
    if (!player->HasUnitState(UNIT_STAT_ATTACK_PLAYER))
    {
        player->AddUnitState(UNIT_STAT_ATTACK_PLAYER);
        player->SetFlag(PLAYER_FLAGS, PLAYER_FLAGS_CONTESTED_PVP);
        // call MoveInLineOfSight for nearby contested guards
        UpdateObjectVisibility();
    }
    if (!HasUnitState(UNIT_STAT_ATTACK_PLAYER))
    {
        AddUnitState(UNIT_STAT_ATTACK_PLAYER);
        // call MoveInLineOfSight for nearby contested guards
        UpdateObjectVisibility();
    }
}

void Unit::AddPetAura(PetAura const* petSpell)
{
    if (GetTypeId() != TYPEID_PLAYER)
        return;

    m_petAuras.insert(petSpell);
    if (Pet* pet = ToPlayer()->GetPet())
        pet->CastPetAura(petSpell);
}

void Unit::RemovePetAura(PetAura const* petSpell)
{
    if (GetTypeId() != TYPEID_PLAYER)
        return;

    m_petAuras.erase(petSpell);
    if (Pet* pet = ToPlayer()->GetPet())
        pet->RemoveAurasDueToSpell(petSpell->GetAura(pet->GetEntry()));
}

Pet* Unit::CreateTamedPetFrom(Creature* creatureTarget, uint32 spell_id)
{
    if (GetTypeId() != TYPEID_PLAYER)
        return NULL;

    Pet* pet = new Pet((Player*)this, HUNTER_PET);

    if (!pet->CreateBaseAtCreature(creatureTarget))
    {
        delete pet;
        return NULL;
    }

    uint8 level = creatureTarget->getLevel() + 5 < getLevel() ? (getLevel() - 5) : creatureTarget->getLevel();

    InitTamedPet(pet, level, spell_id);

    return pet;
}

Pet* Unit::CreateTamedPetFrom(uint32 creatureEntry, uint32 spell_id)
{
    if (GetTypeId() != TYPEID_PLAYER)
        return NULL;

    CreatureTemplate const* creatureInfo = sObjectMgr->GetCreatureTemplate(creatureEntry);
    if (!creatureInfo)
        return NULL;

    Pet* pet = new Pet((Player*)this, HUNTER_PET);

    if (!pet->CreateBaseAtCreatureInfo(creatureInfo, this) || !InitTamedPet(pet, getLevel(), spell_id))
    {
        delete pet;
        return NULL;
    }

    return pet;
}

bool Unit::InitTamedPet(Pet * pet, uint8 level, uint32 spell_id)
{
    pet->SetCreatorGUID(GetGUID());
    pet->setFaction(getFaction());
    pet->SetUInt32Value(UNIT_CREATED_BY_SPELL, spell_id);

    if (GetTypeId() == TYPEID_PLAYER)
        pet->SetUInt32Value(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP_ATTACKABLE);

    if (!pet->InitStatsForLevel(level))
    {
        sLog->outError("Pet::InitStatsForLevel() failed for creature (Entry: %u)!", pet->GetEntry());
        return false;
    }

    pet->GetCharmInfo()->SetPetNumber(sObjectMgr->GeneratePetNumber(), true);
    // this enables pet details window (Shift+P)
    pet->InitPetCreateSpells();
    //pet->InitLevelupSpellsForLevel();
    pet->SetFullHealth();
    return true;
}

bool Unit::IsTriggeredAtSpellProcEvent(Unit *pVictim, Aura * aura, SpellEntry const* procSpell, uint32 procFlag, uint32 procExtra, WeaponAttackType attType, bool isVictim, bool active, SpellProcEventEntry const *& spellProcEvent)
{
    SpellEntry const* spellProto = aura->GetSpellProto();

    // Get proc Event Entry
    spellProcEvent = sSpellMgr->GetSpellProcEvent(spellProto->Id);

    // Get EventProcFlag
    uint32 EventProcFlag;
    if (spellProcEvent && spellProcEvent->procFlags) // if exist get custom spellProcEvent->procFlags
        EventProcFlag = spellProcEvent->procFlags;
    else
        EventProcFlag = spellProto->procFlags;       // else get from spell proto
    // Continue if no trigger exist
    if (!EventProcFlag)
        return false;

    // Additional checks for triggered spells (ignore trap casts)
    if (procExtra & PROC_EX_INTERNAL_TRIGGERED && !(procFlag & PROC_FLAG_DONE_TRAP_ACTIVATION))
    {
        if (!(spellProto->AttributesEx3 & SPELL_ATTR3_CAN_PROC_TRIGGERED))
            return false;
    }

    // Check spellProcEvent data requirements
    if (!sSpellMgr->IsSpellProcEventCanTriggeredBy(spellProcEvent, EventProcFlag, procSpell, procFlag, procExtra, active))
        return false;
    // In most cases req get honor or XP from kill
    if (EventProcFlag & PROC_FLAG_KILL && GetTypeId() == TYPEID_PLAYER)
    {
        bool allow = false;

        if (pVictim)
            allow = ToPlayer()->isHonorOrXPTarget(pVictim);

        // Shadow Word: Death - can trigger from every kill
        if (aura->GetId() == 32409)
            allow = true;
        if (!allow)
            return false;
    }
    // Aura added by spell can`t trigger from self (prevent drop charges/do triggers)
    // But except periodic and kill triggers (can triggered from self)
    if (procSpell && procSpell->Id == spellProto->Id
        && !(spellProto->procFlags&(PROC_FLAG_TAKEN_PERIODIC | PROC_FLAG_KILL)))
        return false;

    // Check if current equipment allows aura to proc
    if (!isVictim && GetTypeId() == TYPEID_PLAYER)
    {
        Player* player = ToPlayer();
        if (spellProto->EquippedItemClass == ITEM_CLASS_WEAPON)
        {
            Item* item = NULL;
            if (attType == BASE_ATTACK)
                item = player->GetUseableItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
            else if (attType == OFF_ATTACK)
                item = player->GetUseableItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
            else
                item = player->GetUseableItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED);

            if (player->IsInFeralForm())
                return false;

            if (!item || item->IsBroken() || item->GetTemplate()->Class != ITEM_CLASS_WEAPON || !((1<<item->GetTemplate()->SubClass) & spellProto->EquippedItemSubClassMask))
                return false;
        }
        else if (spellProto->EquippedItemClass == ITEM_CLASS_ARMOR)
        {
            // Check if player is wearing shield
            Item* item = player->GetUseableItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
            if (!item || item->IsBroken() || item->GetTemplate()->Class != ITEM_CLASS_ARMOR || !((1<<item->GetTemplate()->SubClass) & spellProto->EquippedItemSubClassMask))
                return false;
        }
    }
    // Get chance from spell
    float chance = float(spellProto->procChance);
    // If in spellProcEvent exist custom chance, chance = spellProcEvent->customChance;
    if (spellProcEvent && spellProcEvent->customChance)
        chance = spellProcEvent->customChance;
    // If PPM exist calculate chance from PPM
    if (spellProcEvent && spellProcEvent->ppmRate != 0)
    {
        if (!isVictim)
        {
            uint32 WeaponSpeed = GetAttackTime(attType);
            chance = GetPPMProcChance(WeaponSpeed, spellProcEvent->ppmRate, spellProto);
        }
        else
        {
            uint32 WeaponSpeed = pVictim->GetAttackTime(attType);
            chance = pVictim->GetPPMProcChance(WeaponSpeed, spellProcEvent->ppmRate, spellProto);
        }
    }
    // Apply chance modifer aura
    if (Player* modOwner = GetSpellModOwner())
    {
        modOwner->ApplySpellMod(spellProto->Id, SPELLMOD_CHANCE_OF_SUCCESS, chance);
    }
    return roll_chance_f(chance);
}

bool Unit::HandleAuraRaidProcFromChargeWithValue(AuraEffect *triggeredByAura)
{
    // aura can be deleted at casts
    SpellEntry const* spellProto = triggeredByAura->GetSpellProto();
    uint32 effIdx = triggeredByAura->GetEffIndex();
    int32 heal = triggeredByAura->GetAmount();
    uint64 caster_guid = triggeredByAura->GetCasterGUID();

    //Currently only Prayer of Mending
    if (!(spellProto->SpellFamilyName == SPELLFAMILY_PRIEST && spellProto->SpellFamilyFlags[1] & 0x20))
    {
        sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "Unit::HandleAuraRaidProcFromChargeWithValue, received not handled spell: %u", spellProto->Id);
        return false;
    }

    // jumps
    int32 jumps = triggeredByAura->GetBase()->GetCharges()-1;

    // current aura expire
    triggeredByAura->GetBase()->SetCharges(1);             // will removed at next charges decrease

    // next target selection
    if (jumps > 0)
    {
        float radius;
        if (spellProto->EffectRadiusIndex[effIdx])
            radius = (float)GetSpellRadiusForTarget(triggeredByAura->GetCaster(), sSpellRadiusStore.LookupEntry(spellProto->EffectRadiusIndex[effIdx]));
        else
            radius = (float)GetSpellMaxRangeForTarget(triggeredByAura->GetCaster(), sSpellRangeStore.LookupEntry(spellProto->rangeIndex));

        if (Unit* caster = triggeredByAura->GetCaster())
        {
            if (Player* modOwner = caster->GetSpellModOwner())
                modOwner->ApplySpellMod(spellProto->Id, SPELLMOD_RADIUS, radius, NULL);

            if (Unit* target = GetNextRandomRaidMemberOrPet(radius))
            {
                CastCustomSpell(target, spellProto->Id, &heal, NULL, NULL, true, NULL, triggeredByAura, caster_guid);
                if (Aura* aura = target->GetAura(spellProto->Id, caster->GetGUID()))
                    aura->SetCharges(jumps);
            }
        }
    }

    // heal
    CastCustomSpell(this, 33110, &heal, NULL, NULL, true, NULL, NULL, caster_guid);
    return true;

}
bool Unit::HandleAuraRaidProcFromCharge(AuraEffect* triggeredByAura)
{
    // aura can be deleted at casts
    SpellEntry const* spellProto = triggeredByAura->GetSpellProto();

    uint32 damageSpellId;
    switch (spellProto->Id)
    {
        case 57949:            // shiver
            damageSpellId = 57952;
            //animationSpellId = 57951; dummy effects for jump spell have unknown use (see also 41637)
            break;
        case 59978:            // shiver
            damageSpellId = 59979;
            break;
        case 43593:            // Cold Stare
            damageSpellId = 43594;
            break;
        default:
            sLog->outError("Unit::HandleAuraRaidProcFromCharge, received not handled spell: %u", spellProto->Id);
            return false;
    }

    uint64 caster_guid = triggeredByAura->GetCasterGUID();
    uint32 effIdx = triggeredByAura->GetEffIndex();

    // jumps
    int32 jumps = triggeredByAura->GetBase()->GetCharges()-1;

    // current aura expire
    triggeredByAura->GetBase()->SetCharges(1);             // will removed at next charges decrease

    // next target selection
    if (jumps > 0)
    {
        float radius;
        if (spellProto->EffectRadiusIndex[effIdx])
            radius = (float)GetSpellRadiusForTarget(triggeredByAura->GetCaster(), sSpellRadiusStore.LookupEntry(spellProto->EffectRadiusIndex[effIdx]));
        else
            radius = (float)GetSpellMaxRangeForTarget(triggeredByAura->GetCaster() , sSpellRangeStore.LookupEntry(spellProto->rangeIndex));

        if (Unit* caster = triggeredByAura->GetCaster())
        {
            if (Player* modOwner = caster->GetSpellModOwner())
                modOwner->ApplySpellMod(spellProto->Id, SPELLMOD_RADIUS, radius, NULL);

            if (Unit* target= GetNextRandomRaidMemberOrPet(radius))
            {
                CastSpell(target, spellProto, true, NULL, triggeredByAura, caster_guid);
                if (Aura* aura = target->GetAura(spellProto->Id, caster->GetGUID()))
                    aura->SetCharges(jumps);
            }
        }
    }

    CastSpell(this, damageSpellId, true, NULL, triggeredByAura, caster_guid);

    return true;
}

void Unit::Kill(Unit* victim, bool durabilityLoss)
{
    // Prevent killing unit twice (and giving reward from kill twice)
    if (!victim->GetHealth())
        return;

    // Inform pets (if any) when player kills target)
    if (Player* plr = ToPlayer())
    {
        Pet* pet = plr->GetPet();
        if (pet && pet->isAlive() && pet->isControlled())
            pet->AI()->KilledUnit(victim);
    }

    // find player: owner of controlled `this` or `this` itself maybe
    Player* player = GetCharmerOrOwnerPlayerOrPlayerItself();
    Creature* creature = victim->ToCreature();

    bool isRewardAllowed = true;
    if (creature)
    {
        isRewardAllowed = creature->IsDamageEnoughForLootingAndReward();
        if (!isRewardAllowed)
            creature->SetLootRecipient(NULL);
    }

    if (isRewardAllowed && creature && creature->GetLootRecipient())
        player = creature->GetLootRecipient();

    // Reward player, his pets, and group/raid members
    // call kill spell proc event (before real die and combat stop to triggering auras removed at death/combat stop)
    if (isRewardAllowed && player && player != victim)
    {
        WorldPacket data(SMSG_PARTYKILLLOG, (8+8)); // send event PARTY_KILL
        data << uint64(player->GetGUID()); // player with killing blow
        data << uint64(victim->GetGUID()); // victim

        Player* looter = player;

        if (Group* group = player->GetGroup())
        {
            group->BroadcastPacket(&data, group->GetMemberGroup(player->GetGUID()));

            if (creature)
            {
                group->UpdateLooterGuid(creature, true);
                if (group->GetLooterGuid())
                {
                    looter = sObjectMgr->GetPlayer(group->GetLooterGuid());
                    if (looter)
                    {
                        creature->SetLootRecipient(looter);   // update creature loot recipient to the allowed looter.
                        group->SendLooter(creature, looter);
                    }
                    else
                        group->SendLooter(creature, NULL);
                }
                else
                    group->SendLooter(creature, NULL);

                group->UpdateLooterGuid(creature);
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

        if (creature)
        {
            Loot* loot = &creature->loot;
            if (creature->lootForPickPocketed)
                creature->lootForPickPocketed = false;

            loot->clear();
            if (uint32 lootid = creature->GetCreatureInfo()->lootid)
                loot->FillLoot(lootid, LootTemplates_Creature, looter, false, false, creature->GetLootMode());

            loot->generateMoneyLoot(creature->GetCreatureInfo()->mingold, creature->GetCreatureInfo()->maxgold);
        }

        player->RewardPlayerAndGroupAtKill(victim, false);
    }

    // Do KILL and KILLED procs. KILL proc is called only for the unit who landed the killing blow (and its owner - for pets and totems) regardless of who tapped the victim
    if (isPet() || isTotem())
        if (Unit* owner = GetOwner())
            owner->ProcDamageAndSpell(victim, PROC_FLAG_KILL, PROC_FLAG_NONE, PROC_EX_NONE, 0);

    if (victim->GetCreatureType() != CREATURE_TYPE_CRITTER)
        ProcDamageAndSpell(victim, PROC_FLAG_KILL, PROC_FLAG_KILLED, PROC_EX_NONE, 0);

    // Proc auras on death - must be before aura/combat remove
    victim->ProcDamageAndSpell(NULL, PROC_FLAG_DEATH, PROC_FLAG_NONE, PROC_EX_NONE, 0, BASE_ATTACK, 0);

    // update get killing blow achievements, must be done before setDeathState to be able to require auras on target
    // and before Spirit of Redemption as it also removes auras
    if (player)
        player->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_GET_KILLING_BLOWS, 1, 0, victim);

    // if talent known but not triggered (check priest class for speedup check)
    bool spiritOfRedemption = false;
    if (victim->GetTypeId() == TYPEID_PLAYER && victim->getClass() == CLASS_PRIEST)
    {
        AuraEffectList const& dummyAuras = victim->GetAuraEffectsByType(SPELL_AURA_DUMMY);
        for (AuraEffectList::const_iterator itr = dummyAuras.begin(); itr != dummyAuras.end(); ++itr)
        {
            if ((*itr)->GetSpellProto()->SpellIconID == 1654)
            {
                AuraEffect const* aurEff = *itr;
                // save value before aura remove
                uint32 ressSpellId = victim->GetUInt32Value(PLAYER_SELF_RES_SPELL);
                if (!ressSpellId)
                    ressSpellId = victim->ToPlayer()->GetResurrectionSpellId();
                // Remove all expected to remove at death auras (most important negative case like DoT or periodic triggers)
                victim->RemoveAllAurasOnDeath();
                // restore for use at real death
                victim->SetUInt32Value(PLAYER_SELF_RES_SPELL, ressSpellId);

                // FORM_SPIRITOFREDEMPTION and related auras
                victim->CastSpell(victim, 27827, true, NULL, aurEff);
                spiritOfRedemption = true;
                break;
            }
        }
    }

    if (!spiritOfRedemption)
    {
        sLog->outStaticDebug("SET JUST_DIED");
        victim->setDeathState(JUST_DIED);
    }

    // 10% durability loss on death
    // clean InHateListOf
    if (Player* plrVictim = victim->ToPlayer())
    {
        // remember victim PvP death for corpse type and corpse reclaim delay
        // at original death (not at SpiritOfRedemtionTalent timeout)
        plrVictim->SetPvPDeath(player != NULL);

        // only if not player and not controlled by player pet. And not at BG
        if ((durabilityLoss && !player && !victim->ToPlayer()->InBattleground()) || (player && sWorld->getBoolConfig(CONFIG_DURABILITY_LOSS_IN_PVP)))
        {
            sLog->outStaticDebug("We are dead, losing %f percent durability", sWorld->getRate(RATE_DURABILITY_LOSS_ON_DEATH));
            plrVictim->DurabilityLossAll(sWorld->getRate(RATE_DURABILITY_LOSS_ON_DEATH), false);
            // durability lost message
            WorldPacket data(SMSG_DURABILITY_DAMAGE_DEATH, 0);
            plrVictim->GetSession()->SendPacket(&data);
        }
        // Call KilledUnit for creatures
        if (GetTypeId() == TYPEID_UNIT && IsAIEnabled)
            ToCreature()->AI()->KilledUnit(victim);

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
        sLog->outStaticDebug("DealDamageNotPlayer");

        if (!creature->isPet())
        {
            creature->DeleteThreatList();
            CreatureTemplate const* cInfo = creature->GetCreatureInfo();
            if (cInfo && (cInfo->lootid || cInfo->maxgold > 0))
                creature->SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
        }

        // Call KilledUnit for creatures, this needs to be called after the lootable flag is set
        if (GetTypeId() == TYPEID_UNIT && IsAIEnabled)
            ToCreature()->AI()->KilledUnit(victim);

        // Call creature just died function
        if (creature->IsAIEnabled)
            creature->AI()->JustDied(this);

        if (TempSummon* summon = creature->ToTempSummon())
            if (Unit* summoner = summon->GetSummoner())
                if (summoner->ToCreature() && summoner->IsAIEnabled)
                    summoner->ToCreature()->AI()->SummonedCreatureDies(creature, this);

        // Dungeon specific stuff, only applies to players killing creatures
        if (creature->GetInstanceId())
        {
            Map* instanceMap = creature->GetMap();
            Player* creditedPlayer = GetCharmerOrOwnerPlayerOrPlayerItself();
            // TODO: do instance binding anyway if the charmer/owner is offline

            if (instanceMap->IsDungeon() && creditedPlayer)
            {
                if (instanceMap->IsRaidOrHeroicDungeon())
                {
                    if (creature->GetCreatureInfo()->flags_extra & CREATURE_FLAG_EXTRA_INSTANCE_BIND)
                        ((InstanceMap*)instanceMap)->PermBindAllPlayers(creditedPlayer);
                }
                else
                {
                    // the reset time is set but not added to the scheduler
                    // until the players leave the instance
                    time_t resettime = creature->GetRespawnTimeEx() + 2 * HOUR;
                    if (InstanceSave *save = sInstanceSaveMgr->GetInstanceSave(creature->GetInstanceId()))
                        if (save->GetResetTime() < resettime) save->SetResetTime(resettime);
                }
            }
        }
    }

    // outdoor pvp things, do these after setting the death state, else the player activity notify won't work... doh...
    // handle player kill only if not suicide (spirit of redemption for example)
    if (player && this != victim)
        if (OutdoorPvP* pvp = player->GetOutdoorPvP())
            pvp->HandleKill(player, victim);

    //if (pVictim->GetTypeId() == TYPEID_PLAYER)
    //    if (OutdoorPvP* pvp = pVictim->ToPlayer()->GetOutdoorPvP())
    //        pvp->HandlePlayerActivityChangedpVictim->ToPlayer();

    // battleground things (do this at the end, so the death state flag will be properly set to handle in the bg->handlekill)
    if (player && player->InBattleground())
    {
        if (Battleground* bg = player->GetBattleground())
        {
            if (victim->GetTypeId() == TYPEID_PLAYER)
                bg->HandleKillPlayer((Player*)victim, player);
            else
                bg->HandleKillUnit(victim->ToCreature(), player);
        }
    }

    // achievement stuff
    if (victim->GetTypeId() == TYPEID_PLAYER)
    {
        if (GetTypeId() == TYPEID_UNIT)
            victim->ToPlayer()->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_CREATURE, GetEntry());
        else if (GetTypeId() == TYPEID_PLAYER && victim != this)
            victim->ToPlayer()->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_PLAYER, 1, ToPlayer()->GetTeam());
    }

    // Hook for OnPVPKill Event
    if (GetTypeId() == TYPEID_PLAYER)
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
        {
            Player* killer = ToPlayer();
            Player* killed = victim->ToPlayer();
            sScriptMgr->OnPVPKill(killer, killed);
        }
        else if (victim->GetTypeId() == TYPEID_UNIT)
        {
            Player* killer = ToPlayer();
            Creature* killed = victim->ToCreature();
            sScriptMgr->OnCreatureKill(killer, killed);
        }
    }
    else if (GetTypeId() == TYPEID_UNIT)
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
        {
            Creature* killer = ToCreature();
            Player* killed = victim->ToPlayer();
            sScriptMgr->OnPlayerKilledByCreature(killer, killed);
        }
    }

    if (victim->GetVehicle())
        victim->ExitVehicle();
}

void Unit::SetControlled(bool apply, UnitState state)
{
    if (apply)
    {
        if (HasUnitState(state))
            return;

        AddUnitState(state);
        switch(state)
        {
            case UNIT_STAT_STUNNED:
                SetStunned(true);
                CastStop();
                break;
            case UNIT_STAT_ROOT:
                if (!HasUnitState(UNIT_STAT_STUNNED))
                    SetRooted(true);
                break;
            case UNIT_STAT_CONFUSED:
                if (!HasUnitState(UNIT_STAT_STUNNED))
                {
                    SetConfused(true);
                    CastStop();
                }
                break;
            case UNIT_STAT_FLEEING:
                if (!HasUnitState(UNIT_STAT_STUNNED | UNIT_STAT_CONFUSED))
                {
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
        switch(state)
        {
            case UNIT_STAT_STUNNED: if (HasAuraType(SPELL_AURA_MOD_STUN))    return;
                                    else    SetStunned(false);    break;
            case UNIT_STAT_ROOT:    if (HasAuraType(SPELL_AURA_MOD_ROOT) || GetVehicle())    return;
                                    else    SetRooted(false);     break;
            case UNIT_STAT_CONFUSED:if (HasAuraType(SPELL_AURA_MOD_CONFUSE)) return;
                                    else    SetConfused(false);   break;
            case UNIT_STAT_FLEEING: if (HasAuraType(SPELL_AURA_MOD_FEAR))    return;
                                    else    SetFeared(false);     break;
            default: return;
        }

        ClearUnitState(state);

        if (HasUnitState(UNIT_STAT_STUNNED))
            SetStunned(true);
        else
        {
            if (HasUnitState(UNIT_STAT_ROOT))
                SetRooted(true);

            if (HasUnitState(UNIT_STAT_CONFUSED))
                SetConfused(true);
            else if (HasUnitState(UNIT_STAT_FLEEING))
                SetFeared(true);
        }
    }
}

void Unit::SetStunned(bool apply)
{
    if (apply)
    {
        SetUInt64Value(UNIT_FIELD_TARGET, 0);
        SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);

        // MOVEMENTFLAG_ROOT cannot be used in conjunction with
        // MOVEMENTFLAG_FORWARD, MOVEMENTFLAG_BACKWARD, MOVEMENTFLAG_STRAFE_LEFT, MOVEMENTFLAG_STRAFE RIGHT (tested 3.3.5a)
        // this will freeze clients. That's why we remove any current movement flags before
        // setting MOVEMENTFLAG_ROOT
        RemoveUnitMovementFlag(MOVEMENTFLAG_FORWARD | MOVEMENTFLAG_BACKWARD | MOVEMENTFLAG_STRAFE_LEFT | MOVEMENTFLAG_STRAFE_RIGHT);
        AddUnitMovementFlag(MOVEMENTFLAG_ROOT);

        // Creature specific
        if (GetTypeId() != TYPEID_PLAYER)
            ToCreature()->StopMoving();
        else
            SetStandState(UNIT_STAND_STATE_STAND);

        WorldPacket data(SMSG_FORCE_MOVE_ROOT, 8);
        data.append(GetPackGUID());
        data << uint32(0);
        SendMessageToSet(&data, true);

        CastStop();
    }
    else
    {
        if (isAlive() && getVictim())
            SetUInt64Value(UNIT_FIELD_TARGET, getVictim()->GetGUID());

        // don't remove UNIT_FLAG_STUNNED for pet when owner is mounted (disabled pet's interface)
        Unit* pOwner = GetOwner();
        if (!pOwner || (pOwner->GetTypeId() == TYPEID_PLAYER && !pOwner->ToPlayer()->IsMounted()))
            RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);

        if (!HasUnitState(UNIT_STAT_ROOT))         // prevent allow move if have also root effect
        {
            WorldPacket data(SMSG_FORCE_MOVE_UNROOT, 8+4);
            data.append(GetPackGUID());
            data << uint32(0);
            SendMessageToSet(&data, true);

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

        // MOVEMENTFLAG_ROOT cannot be used in conjunction with
        // MOVEMENTFLAG_FORWARD, MOVEMENTFLAG_BACKWARD, MOVEMENTFLAG_STRAFE_LEFT, MOVEMENTFLAG_STRAFE RIGHT (tested 3.3.5a)
        // this will freeze clients. That's why we remove any current movement flags before
        // setting MOVEMENTFLAG_ROOT
        RemoveUnitMovementFlag(MOVEMENTFLAG_FORWARD | MOVEMENTFLAG_BACKWARD | MOVEMENTFLAG_STRAFE_LEFT | MOVEMENTFLAG_STRAFE_RIGHT);
        AddUnitMovementFlag(MOVEMENTFLAG_ROOT);

        if (GetTypeId() == TYPEID_PLAYER)
        {
            WorldPacket data(SMSG_FORCE_MOVE_ROOT, 10);
            data.append(GetPackGUID());
            data << m_rootTimes;
            SendMessageToSet(&data, true);
        }
        else
        {
            WorldPacket data(SMSG_SPLINE_MOVE_ROOT, 8);
            data.append(GetPackGUID());
            SendMessageToSet(&data, true);
            ToCreature()->StopMoving();
        }
    }
    else
    {
        if (!HasUnitState(UNIT_STAT_STUNNED))      // prevent allow move if have also stun effect
        {
            if (GetTypeId() == TYPEID_PLAYER)
            {
                WorldPacket data(SMSG_FORCE_MOVE_UNROOT, 10);
                data.append(GetPackGUID());
                data << ++m_rootTimes;
                SendMessageToSet(&data, true);
            }
            else
            {
                WorldPacket data(SMSG_SPLINE_MOVE_UNROOT, 8);
                data.append(GetPackGUID());
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
        SetUInt64Value(UNIT_FIELD_TARGET, 0);

        Unit* caster = NULL;
        Unit::AuraEffectList const& fearAuras = GetAuraEffectsByType(SPELL_AURA_MOD_FEAR);
        if (!fearAuras.empty())
            caster = ObjectAccessor::GetUnit(*this, fearAuras.front()->GetCasterGUID());
        if (!caster)
            caster = getAttackerForHelper();
        GetMotionMaster()->MoveFleeing(caster, fearAuras.empty() ? sWorld->getIntConfig(CONFIG_CREATURE_FAMILY_FLEE_DELAY) : 0);             // caster == NULL processed in MoveFleeing
    }
    else
    {
        if (isAlive())
        {
            if (GetMotionMaster()->GetCurrentMovementGeneratorType() == FLEEING_MOTION_TYPE)
                GetMotionMaster()->MovementExpired();
            if (getVictim())
                SetUInt64Value(UNIT_FIELD_TARGET, getVictim()->GetGUID());
        }
    }

    if (GetTypeId() == TYPEID_PLAYER)
        ToPlayer()->SetClientControl(this, !apply);
}

void Unit::SetConfused(bool apply)
{
    if (apply)
    {
        SetUInt64Value(UNIT_FIELD_TARGET, 0);
        GetMotionMaster()->MoveConfused();
    }
    else
    {
        if (isAlive())
        {
            if (GetMotionMaster()->GetCurrentMovementGeneratorType() == CONFUSED_MOTION_TYPE)
                GetMotionMaster()->MovementExpired();
            if (getVictim())
                SetUInt64Value(UNIT_FIELD_TARGET, getVictim()->GetGUID());
        }
    }

    if (GetTypeId() == TYPEID_PLAYER)
        ToPlayer()->SetClientControl(this, !apply);
}

bool Unit::SetCharmedBy(Unit* charmer, CharmType type, AuraApplication const* aurApp)
{
    if (!charmer)
        return false;

    // unmount players when charmed
    if (GetTypeId() == TYPEID_PLAYER)
        Unmount();

    ASSERT(type != CHARM_TYPE_POSSESS || charmer->GetTypeId() == TYPEID_PLAYER);
    ASSERT((type == CHARM_TYPE_VEHICLE) == IsVehicle());

    sLog->outDebug(LOG_FILTER_UNITS, "SetCharmedBy: charmer %u (GUID %u), charmed %u (GUID %u), type %u.", charmer->GetEntry(), charmer->GetGUIDLow(), GetEntry(), GetGUIDLow(), uint32(type));

    if (this == charmer)
    {
        sLog->outCrash("Unit::SetCharmedBy: Unit %u (GUID %u) is trying to charm itself!", GetEntry(), GetGUIDLow());
        return false;
    }

    //if (HasUnitState(UNIT_STAT_UNATTACKABLE))
    //    return false;

    if (GetTypeId() == TYPEID_PLAYER && ToPlayer()->GetTransport())
    {
        sLog->outCrash("Unit::SetCharmedBy: Player on transport is trying to charm %u (GUID %u)", GetEntry(), GetGUIDLow());
        return false;
    }

    // Already charmed
    if (GetCharmerGUID())
    {
        sLog->outCrash("Unit::SetCharmedBy: %u (GUID %u) has already been charmed but %u (GUID %u) is trying to charm it!", GetEntry(), GetGUIDLow(), charmer->GetEntry(), charmer->GetGUIDLow());
        return false;
    }

    CastStop();
    CombatStop(); // TODO: CombatStop(true) may cause crash (interrupt spells)
    DeleteThreatList();

    // Charmer stop charming
    if (charmer->GetTypeId() == TYPEID_PLAYER)
    {
        charmer->ToPlayer()->StopCastingCharm();
        charmer->ToPlayer()->StopCastingBindSight();
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
        sLog->outCrash("Unit::SetCharmedBy: %u (GUID %u) is not in world but %u (GUID %u) is trying to charm it!", GetEntry(), GetGUIDLow(), charmer->GetEntry(), charmer->GetGUIDLow());
        return false;
    }

    // charm is set by aura, and aura effect remove handler was called during apply handler execution
    // prevent undefined behaviour
    if (aurApp && aurApp->GetRemoveMode())
        return false;

    // Set charmed
    Map* pMap = GetMap();
    if (!IsVehicle() || (IsVehicle() && pMap && !pMap->IsBattleground()))
        setFaction(charmer->getFaction());

    charmer->SetCharm(this, true);

    if (GetTypeId() == TYPEID_UNIT)
    {
        ToCreature()->AI()->OnCharmed(true);
        GetMotionMaster()->MoveIdle();
    }
    else
    {
        Player* plr = ToPlayer();
        if (plr->isAFK())
            plr->ToggleAFK();
        plr->SetClientControl(this, 0);
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

    if (charmer->GetTypeId() == TYPEID_PLAYER)
    {
        switch(type)
        {
            case CHARM_TYPE_VEHICLE:
                SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED);
                charmer->ToPlayer()->SetClientControl(this, 1);
                charmer->ToPlayer()->SetViewpoint(this, true);
                charmer->ToPlayer()->VehicleSpellInitialize();
                break;
            case CHARM_TYPE_POSSESS:
                AddUnitState(UNIT_STAT_POSSESSED);
                SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED);
                charmer->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                charmer->ToPlayer()->SetClientControl(this, 1);
                charmer->ToPlayer()->SetViewpoint(this, true);
                charmer->ToPlayer()->PossessSpellInitialize();
                break;
            case CHARM_TYPE_CHARM:
                if (GetTypeId() == TYPEID_UNIT && charmer->getClass() == CLASS_WARLOCK)
                {
                    CreatureTemplate const* cinfo = ToCreature()->GetCreatureInfo();
                    if (cinfo && cinfo->type == CREATURE_TYPE_DEMON)
                    {
                        // to prevent client crash
                        SetByteValue(UNIT_FIELD_BYTES_0, 1, (uint8)CLASS_MAGE);

                        // just to enable stat window
                        if (GetCharmInfo())
                            GetCharmInfo()->SetPetNumber(sObjectMgr->GeneratePetNumber(), true);

                        // if charmed two demons the same session, the 2nd gets the 1st one's name
                        SetUInt32Value(UNIT_FIELD_PET_NAME_TIMESTAMP, uint32(time(NULL))); // cast can't be helped
                    }
                }
                charmer->ToPlayer()->CharmSpellInitialize();
                break;
            default:
            case CHARM_TYPE_CONVERT:
                break;
        }
    }
    return true;
}

void Unit::RemoveCharmedBy(Unit *charmer)
{
    if (!isCharmed())
        return;

    if (!charmer)
        charmer = GetCharmer();
    if (charmer != GetCharmer()) // one aura overrides another?
    {
//        sLog->outCrash("Unit::RemoveCharmedBy: this: " UI64FMTD " true charmer: " UI64FMTD " false charmer: " UI64FMTD,
//            GetGUID(), GetCharmerGUID(), charmer->GetGUID());
//        ASSERT(false);
        return;
    }

    CharmType type;
    if (HasUnitState(UNIT_STAT_POSSESSED))
        type = CHARM_TYPE_POSSESS;
    else if (charmer && charmer->IsOnVehicle(this))
        type = CHARM_TYPE_VEHICLE;
    else
        type = CHARM_TYPE_CHARM;

    CastStop();
    CombatStop(); // TODO: CombatStop(true) may cause crash (interrupt spells)
    getHostileRefManager().deleteReferences();
    DeleteThreatList();
    Map* pMap = GetMap();
    if (!IsVehicle() || (IsVehicle() && pMap && !pMap->IsBattleground()))
        RestoreFaction();
    GetMotionMaster()->InitDefault();

    if (type == CHARM_TYPE_POSSESS)
    {
        ClearUnitState(UNIT_STAT_POSSESSED);
        RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED);
    }

    if (Creature* creature = ToCreature())
    {
        creature->AI()->OnCharmed(false);

        if (type != CHARM_TYPE_VEHICLE) // Vehicles' AI is never modified
        {
            creature->AIM_Initialize();

            if (creature->AI() && charmer && charmer->isAlive())
                creature->AI()->AttackStart(charmer);
        }
    }
    else
        ToPlayer()->SetClientControl(this, 1);

    // If charmer still exists
    if (!charmer)
        return;

    ASSERT(type != CHARM_TYPE_POSSESS || charmer->GetTypeId() == TYPEID_PLAYER);
    ASSERT(type != CHARM_TYPE_VEHICLE || (GetTypeId() == TYPEID_UNIT && IsVehicle()));

    charmer->SetCharm(this, false);

    if (charmer->GetTypeId() == TYPEID_PLAYER)
    {
        switch(type)
        {
            case CHARM_TYPE_VEHICLE:
                charmer->ToPlayer()->SetClientControl(charmer, 1);
                charmer->ToPlayer()->SetViewpoint(this, false);
                charmer->ToPlayer()->SetClientControl(this, 0);
                break;
            case CHARM_TYPE_POSSESS:
                charmer->ToPlayer()->SetClientControl(charmer, 1);
                charmer->ToPlayer()->SetViewpoint(this, false);
                charmer->ToPlayer()->SetClientControl(this, 0);
                charmer->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                break;
            case CHARM_TYPE_CHARM:
                if (GetTypeId() == TYPEID_UNIT && charmer->getClass() == CLASS_WARLOCK)
                {
                    CreatureTemplate const* cinfo = ToCreature()->GetCreatureInfo();
                    if (cinfo && cinfo->type == CREATURE_TYPE_DEMON)
                    {
                        SetByteValue(UNIT_FIELD_BYTES_0, 1, uint8(cinfo->unit_class));
                        if (GetCharmInfo())
                            GetCharmInfo()->SetPetNumber(0, true);
                        else
                            sLog->outError("Aura::HandleModCharm: target="UI64FMTD" with typeid=%d has a charm aura but no charm info!", GetGUID(), GetTypeId());
                    }
                }
                break;
            default:
            case CHARM_TYPE_CONVERT:
                break;
        }
    }

    // a guardian should always have charminfo
    if (charmer->GetTypeId() == TYPEID_PLAYER && this != charmer->GetFirstControlled())
        charmer->ToPlayer()->SendRemoveControlBar();
    else if (GetTypeId() == TYPEID_PLAYER || (GetTypeId() == TYPEID_UNIT && !ToCreature()->isGuardian()))
        DeleteCharmInfo();
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
                setFaction(owner->getFaction());
                return;
            }
        }

        if (CreatureTemplate const* cinfo = ToCreature()->GetCreatureInfo())  // normal creature
        {
            FactionTemplateEntry const* faction = getFactionTemplateEntry();
            setFaction((faction && faction->friendlyMask & 0x004) ? cinfo->faction_H : cinfo->faction_A);
        }
    }
}

bool Unit::CreateVehicleKit(uint32 id, uint32 creatureEntry)
{
    VehicleEntry const* vehInfo = sVehicleStore.LookupEntry(id);
    if (!vehInfo)
        return false;

    m_vehicleKit = new Vehicle(this, vehInfo, creatureEntry);
    m_updateFlag |= UPDATEFLAG_VEHICLE;
    m_unitTypeMask |= UNIT_MASK_VEHICLE;
    return true;
}

void Unit::RemoveVehicleKit()
{
    if (!m_vehicleKit)
        return;

    m_vehicleKit->Uninstall();
    delete m_vehicleKit;

    m_vehicleKit = NULL;

    m_updateFlag &= ~UPDATEFLAG_VEHICLE;
    m_unitTypeMask &= ~UNIT_MASK_VEHICLE;
    RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
    RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_PLAYER_VEHICLE);
}

Unit *Unit::GetVehicleBase() const
{
    return m_vehicle ? m_vehicle->GetBase() : NULL;
}

Creature *Unit::GetVehicleCreatureBase() const
{
    if (Unit *veh = GetVehicleBase())
        if (Creature *c = veh->ToCreature())
            return c;

    return NULL;
}

uint64 Unit::GetTransGUID() const
{
    if (GetVehicle())
        return GetVehicle()->GetBase()->GetGUID();
    if (GetTransport())
        return GetTransport()->GetGUID();

    return 0;
}

bool Unit::IsInPartyWith(Unit const *unit) const
{
    if (this == unit)
        return true;

    const Unit *u1 = GetCharmerOrOwnerOrSelf();
    const Unit *u2 = unit->GetCharmerOrOwnerOrSelf();
    if (u1 == u2)
        return true;

    if (u1->GetTypeId() == TYPEID_PLAYER && u2->GetTypeId() == TYPEID_PLAYER)
      return u1->ToPlayer()->IsInSameGroupWith(u2->ToPlayer());
    else
        return false;
}

bool Unit::IsInRaidWith(Unit const *unit) const
{
    if (this == unit)
        return true;

    const Unit *u1 = GetCharmerOrOwnerOrSelf();
    const Unit *u2 = unit->GetCharmerOrOwnerOrSelf();
    if (u1 == u2)
        return true;

    if (u1->GetTypeId() == TYPEID_PLAYER && u2->GetTypeId() == TYPEID_PLAYER)
      return u1->ToPlayer()->IsInSameRaidWith(u2->ToPlayer());
    else
        return false;
}

void Unit::GetRaidMember(std::list<Unit*> &nearMembers, float radius)
{
    Player* owner = GetCharmerOrOwnerPlayerOrPlayerItself();
    if (!owner)
        return;

    Group* pGroup = owner->GetGroup();
    if (pGroup)
    {
        for (GroupReference *itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
        {
            Player* Target = itr->getSource();

            if (Target && !IsHostileTo(Target))
            {
                if (Target->isAlive() && IsWithinDistInMap(Target, radius))
                    nearMembers.push_back(Target);

                if (Guardian* pet = Target->GetGuardianPet())
                    if (pet->isAlive() &&  IsWithinDistInMap(pet, radius))
                        nearMembers.push_back(pet);
            }
        }
    }
    else
    {
        if (owner->isAlive() && (owner == this || IsWithinDistInMap(owner, radius)))
            nearMembers.push_back(owner);
        if (Guardian* pet = owner->GetGuardianPet())
            if (pet->isAlive() && (pet == this && IsWithinDistInMap(pet, radius)))
                nearMembers.push_back(pet);
    }
}

void Unit::GetPartyMemberInDist(std::list<Unit*> &TagUnitMap, float radius)
{
    Unit* owner = GetCharmerOrOwnerOrSelf();
    Group* pGroup = NULL;
    if (owner->GetTypeId() == TYPEID_PLAYER)
        pGroup = owner->ToPlayer()->GetGroup();

    if (pGroup)
    {
        uint8 subgroup = owner->ToPlayer()->GetSubGroup();

        for (GroupReference *itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
        {
            Player* Target = itr->getSource();

            // IsHostileTo check duel and controlled by enemy
            if (Target && Target->GetSubGroup() == subgroup && !IsHostileTo(Target))
            {
                if (Target->isAlive() && IsWithinDistInMap(Target, radius))
                    TagUnitMap.push_back(Target);

                if (Guardian* pet = Target->GetGuardianPet())
                    if (pet->isAlive() &&  IsWithinDistInMap(pet, radius))
                        TagUnitMap.push_back(pet);
            }
        }
    }
    else
    {
        if (owner->isAlive() && (owner == this || IsWithinDistInMap(owner, radius)))
            TagUnitMap.push_back(owner);
        if (Guardian* pet = owner->GetGuardianPet())
            if (pet->isAlive() && (pet == this && IsWithinDistInMap(pet, radius)))
                TagUnitMap.push_back(pet);
    }
}

void Unit::GetPartyMembers(std::list<Unit*> &TagUnitMap)
{
    Unit* owner = GetCharmerOrOwnerOrSelf();
    Group* pGroup = NULL;
    if (owner->GetTypeId() == TYPEID_PLAYER)
        pGroup = owner->ToPlayer()->GetGroup();

    if (pGroup)
    {
        uint8 subgroup = owner->ToPlayer()->GetSubGroup();

        for (GroupReference *itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
        {
            Player* Target = itr->getSource();

            // IsHostileTo check duel and controlled by enemy
            if (Target && Target->GetSubGroup() == subgroup && !IsHostileTo(Target))
            {
                if (Target->isAlive() && IsInMap(Target))
                    TagUnitMap.push_back(Target);

                if (Guardian* pet = Target->GetGuardianPet())
                    if (pet->isAlive() && IsInMap(Target))
                        TagUnitMap.push_back(pet);
            }
        }
    }
    else
    {
        if (owner->isAlive() && (owner == this || IsInMap(owner)))
            TagUnitMap.push_back(owner);
        if (Guardian* pet = owner->GetGuardianPet())
            if (pet->isAlive() && (pet == this || IsInMap(pet)))
                TagUnitMap.push_back(pet);
    }
}

Aura * Unit::AddAura(uint32 spellId, Unit* target)
{
    if (!target)
        return NULL;

    SpellEntry const* spellInfo = sSpellStore.LookupEntry(spellId);
    if (!spellInfo)
        return NULL;

    if (!target->isAlive() && !(spellInfo->Attributes & SPELL_ATTR0_PASSIVE) && !(spellInfo->AttributesEx2 & SPELL_ATTR2_ALLOW_DEAD_TARGET))
        return NULL;

    return AddAura(spellInfo, MAX_EFFECT_MASK, target);
}

Aura * Unit::AddAura(SpellEntry const *spellInfo, uint8 effMask, Unit* target)
{
    if (!spellInfo)
        return NULL;

    if (target->IsImmunedToSpell(spellInfo))
        return NULL;

    for (uint32 i = 0; i < MAX_SPELL_EFFECTS; ++i)
    {
        if (!(effMask & (1<<i)))
            continue;
        if (target->IsImmunedToSpellEffect(spellInfo, i))
            effMask &= ~(1<<i);
    }

    if (Aura* aura = Aura::TryRefreshStackOrCreate(spellInfo, effMask, target, this))
    {
        aura->ApplyForTargets();
        return aura;
    }
    return NULL;
}

void Unit::SetAuraStack(uint32 spellId, Unit* target, uint32 stack)
{
    Aura *aura = target->GetAura(spellId, GetGUID());
    if (!aura)
        aura = AddAura(spellId, target);
    if (aura && stack)
        aura->SetStackAmount(stack);
}

void Unit::ApplyResilience(Unit const* victim, float* crit, int32* damage, bool isCrit, CombatRating type) const
{
    // player mounted on multi-passenger mount is also classified as vehicle
    if (IsVehicle() || (victim->IsVehicle() && victim->GetTypeId() != TYPEID_PLAYER))
        return;

    Unit const* source = NULL;
    if (GetTypeId() == TYPEID_PLAYER)
        source = this;
    else if (GetTypeId() == TYPEID_UNIT && GetOwner() && GetOwner()->GetTypeId() == TYPEID_PLAYER)
        source = GetOwner();

    Unit const* target = NULL;
    if (victim->GetTypeId() == TYPEID_PLAYER)
        target = victim;
    else if (victim->GetTypeId() == TYPEID_UNIT && victim->GetOwner() && victim->GetOwner()->GetTypeId() == TYPEID_PLAYER)
        target = victim->GetOwner();

    if (!target)
        return;

    switch (type)
    {
        case CR_CRIT_TAKEN_MELEE:
            // Crit chance reduction works against nonpets
            if (crit)
                *crit -= target->GetMeleeCritChanceReduction();
            if (source && damage)
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
            if (source && damage)
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
            if (source && damage)
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

// Melee based spells can be miss, parry or dodge on this step
// Crit or block - determined on damage calculation phase! (and can be both in some time)
float Unit::MeleeSpellMissChance(const Unit *pVictim, WeaponAttackType attType, int32 skillDiff, uint32 spellId) const
{
    // Calculate hit chance (more correct for chance mod)
    int32 HitChance;

    // PvP - PvE melee chances
    if (spellId || attType == RANGED_ATTACK || !haveOffhandWeapon())
        HitChance = 95;
    else
        HitChance = 76;

    // Hit chance depends from victim auras
    if (attType == RANGED_ATTACK)
        HitChance += pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_RANGED_HIT_CHANCE);
    else
        HitChance += pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_MELEE_HIT_CHANCE);

    // Spellmod from SPELLMOD_RESIST_MISS_CHANCE
    if (spellId)
    {
        if (Player* modOwner = GetSpellModOwner())
            modOwner->ApplySpellMod(spellId, SPELLMOD_RESIST_MISS_CHANCE, HitChance);
    }

    // Miss = 100 - hit
    float miss_chance = 100.0f - HitChance;

    // Bonuses from attacker aura and ratings
    if (attType == RANGED_ATTACK)
        miss_chance -= m_modRangedHitChance;
    else
        miss_chance -= m_modMeleeHitChance;

    // bonus from skills is 0.04%
    //miss_chance -= skillDiff * 0.04f;
    int32 diff = -skillDiff;
    if (pVictim->GetTypeId() == TYPEID_PLAYER)
        miss_chance += diff > 0 ? diff * 0.04f : diff * 0.02f;
    else
        miss_chance += diff > 10 ? 2 + (diff - 10) * 0.4f : diff * 0.1f;

    // Limit miss chance from 0 to 60%
    if (miss_chance < 0.0f)
        return 0.0f;
    if (miss_chance > 60.0f)
        return 60.0f;
    return miss_chance;
}

void Unit::SetPhaseMask(uint32 newPhaseMask, bool update)
{
    if (newPhaseMask == GetPhaseMask())
        return;

    if (IsInWorld())
        RemoveNotOwnSingleTargetAuras(newPhaseMask);        // we can lost access to caster or target

    WorldObject::SetPhaseMask(newPhaseMask, update);

    if (!IsInWorld())
        return;

    for (ControlList::const_iterator itr = m_Controlled.begin(); itr != m_Controlled.end(); ++itr)
        if ((*itr)->GetTypeId() == TYPEID_UNIT)
            (*itr)->SetPhaseMask(newPhaseMask, true);

    for (uint8 i = 0; i < MAX_SUMMON_SLOT; ++i)
        if (m_SummonSlot[i])
            if (Creature *summon = GetMap()->GetCreature(m_SummonSlot[i]))
                summon->SetPhaseMask(newPhaseMask, true);
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
        VisitNearbyObject(GetVisibilityRange(), notifier);
    }
}

void Unit::KnockbackFrom(float x, float y, float speedXY, float speedZ)
{
    Player* player = NULL;
    if (GetTypeId() == TYPEID_PLAYER)
        player = (Player*)this;
    else if (GetCharmer())
    {
        player = GetCharmer()->ToPlayer();
        if (player && player->m_mover != this)
            player = NULL;
    }

    if (!player)
    {
        GetMotionMaster()->MoveKnockbackFrom(x, y, speedXY, speedZ);
    }
    else
    {
        float vcos, vsin;
        GetSinCos(x, y, vsin, vcos);

        WorldPacket data(SMSG_MOVE_KNOCK_BACK, (8+4+4+4+4+4));
        data.append(GetPackGUID());
        data << uint32(0);                                      // Sequence
        data << float(vcos);                                    // x direction
        data << float(vsin);                                    // y direction
        data << float(speedXY);                                 // Horizontal speed
        data << float(-speedZ);                                 // Z Movement speed (vertical)

        player->GetSession()->SendPacket(&data);
    }
}

float Unit::GetCombatRatingReduction(CombatRating cr) const
{
    if (Player const* player = ToPlayer())
        return player->GetRatingBonusValue(cr);
    // Player's pet get resilience from owner
    else if (isPet())
        if (Unit* owner = GetOwner())
            if (Player* player = owner->ToPlayer())
                return player->GetRatingBonusValue(cr);

    return 0.0f;
}

uint32 Unit::GetCombatRatingDamageReduction(CombatRating cr, float rate, float cap, uint32 damage) const
{
    float percent = std::min(GetCombatRatingReduction(cr) * rate, cap);
    return CalculatePctF(damage, percent);
}

uint32 Unit::GetModelForForm(ShapeshiftForm form)
{
    switch (form)
    {
        case FORM_CAT:
            // Based on Hair color
            if (getRace() == RACE_NIGHTELF)
            {
                uint8 hairColor = GetByteValue(PLAYER_BYTES, 3);
                switch (hairColor)
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
            else if (getRace() == RACE_TAUREN)
            {
                uint8 skinColor = GetByteValue(PLAYER_BYTES, 0);
                // Male
                if (getGender() == GENDER_MALE)
                {
                    switch(skinColor)
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
            else if (Player::TeamForRace(getRace()) == ALLIANCE)
                return 892;
            else
                return 8571;
        case FORM_DIREBEAR:
        case FORM_BEAR:
            // Based on Hair color
            if (getRace() == RACE_NIGHTELF)
            {
                uint8 hairColor = GetByteValue(PLAYER_BYTES, 3);
                switch (hairColor)
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
            else if (getRace() == RACE_TAUREN)
            {
                uint8 skinColor = GetByteValue(PLAYER_BYTES, 0);
                // Male
                if (getGender() == GENDER_MALE)
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
            else if (Player::TeamForRace(getRace()) == ALLIANCE)
                return 2281;
            else
                return 2289;
        case FORM_FLIGHT:
            if (Player::TeamForRace(getRace()) == ALLIANCE)
                return 20857;
            return 20872;
        case FORM_FLIGHT_EPIC:
            if (Player::TeamForRace(getRace()) == ALLIANCE)
                return 21243;
            return 21244;
        default:
            break;
    }

    uint32 modelid = 0;
    SpellShapeshiftEntry const* formEntry = sSpellShapeshiftStore.LookupEntry(form);
    if (formEntry && formEntry->modelID_A)
    {
        // Take the alliance modelid as default
        if (GetTypeId() != TYPEID_PLAYER)
            return formEntry->modelID_A;
        else
        {
            if (Player::TeamForRace(getRace()) == ALLIANCE)
                modelid = formEntry->modelID_A;
            else
                modelid = formEntry->modelID_H;

            // If the player is horde but there are no values for the horde modelid - take the alliance modelid
            if (!modelid && Player::TeamForRace(getRace()) == HORDE)
                modelid = formEntry->modelID_A;
        }
    }

    return modelid;
}

uint32 Unit::GetModelForTotem(PlayerTotemType totemType)
{
    switch (getRace())
    {
        case RACE_ORC:
        {
            switch (totemType)
            {
                case SUMMON_TYPE_TOTEM_FIRE:    // fire
                    return 30758;
                case SUMMON_TYPE_TOTEM_EARTH:   // earth
                    return 30757;
                case SUMMON_TYPE_TOTEM_WATER:   // water
                    return 30759;
                case SUMMON_TYPE_TOTEM_AIR:     // air
                    return 30756;
            }
            break;
        }
        case RACE_DWARF:
        {
            switch (totemType)
            {
                case SUMMON_TYPE_TOTEM_FIRE:    // fire
                    return 30754;
                case SUMMON_TYPE_TOTEM_EARTH:   // earth
                    return 30753;
                case SUMMON_TYPE_TOTEM_WATER:   // water
                    return 30755;
                case SUMMON_TYPE_TOTEM_AIR:     // air
                    return 30736;
            }
            break;
        }
        case RACE_TROLL:
        {
            switch (totemType)
            {
                case SUMMON_TYPE_TOTEM_FIRE:    // fire
                    return 30762;
                case SUMMON_TYPE_TOTEM_EARTH:   // earth
                    return 30761;
                case SUMMON_TYPE_TOTEM_WATER:   // water
                    return 30763;
                case SUMMON_TYPE_TOTEM_AIR:     // air
                    return 30760;
            }
            break;
        }
        case RACE_TAUREN:
        {
            switch (totemType)
            {
                case SUMMON_TYPE_TOTEM_FIRE:    // fire
                    return 4589;
                case SUMMON_TYPE_TOTEM_EARTH:   // earth
                    return 4588;
                case SUMMON_TYPE_TOTEM_WATER:   // water
                    return 4587;
                case SUMMON_TYPE_TOTEM_AIR:     // air
                    return 4590;
            }
            break;
        }
        case RACE_DRAENEI:
        {
            switch (totemType)
            {
                case SUMMON_TYPE_TOTEM_FIRE:    // fire
                    return 19074;
                case SUMMON_TYPE_TOTEM_EARTH:   // earth
                    return 19073;
                case SUMMON_TYPE_TOTEM_WATER:   // water
                    return 19075;
                case SUMMON_TYPE_TOTEM_AIR:     // air
                    return 19071;
            }
            break;
        }
    }
    return 0;
}

void Unit::JumpTo(float speedXY, float speedZ, bool forward)
{
    float angle = forward ? 0 : M_PI;
    if (GetTypeId() == TYPEID_UNIT)
        GetMotionMaster()->MoveJumpTo(angle, speedXY, speedZ);
    else
    {
        float vcos = cos(angle+GetOrientation());
        float vsin = sin(angle+GetOrientation());

        WorldPacket data(SMSG_MOVE_KNOCK_BACK, (8+4+4+4+4+4));
        data.append(GetPackGUID());
        data << uint32(0);                                      // Sequence
        data << float(vcos);                                    // x direction
        data << float(vsin);                                    // y direction
        data << float(speedXY);                                 // Horizontal speed
        data << float(-speedZ);                                 // Z Movement speed (vertical)

        ToPlayer()->GetSession()->SendPacket(&data);
    }
}

void Unit::JumpTo(WorldObject *obj, float speedZ)
{
    float x, y, z;
    obj->GetContactPoint(this, x, y, z);
    float speedXY = GetExactDist2d(x, y) * 10.0f / speedZ;
    GetMotionMaster()->MoveJump(x, y, z, speedXY, speedZ);
}

bool Unit::CheckPlayerCondition(Player* pPlayer)
{
    switch(GetEntry())
    {
            case 35644: // Argent Warhorse
            case 36558: // Argent Battleworg
                if (!pPlayer->HasItemOrGemWithIdEquipped(46106, 1)) // Check item Argent Lance
                    return false;
            default:
                return true;
    }
}

bool Unit::HandleSpellClick(Unit* clicker, int8 seatId)
{
    bool success = false;
    uint32 spellClickEntry = GetVehicleKit() ? GetVehicleKit()->GetCreatureEntry() : GetEntry();
    SpellClickInfoMapBounds clickPair = sObjectMgr->GetSpellClickInfoMapBounds(spellClickEntry);
    for (SpellClickInfoMap::const_iterator itr = clickPair.first; itr != clickPair.second; ++itr)
    {
        if (itr->second.IsFitToRequirements(clicker, this))
        {
            Unit* caster = (itr->second.castFlags & NPC_CLICK_CAST_CASTER_CLICKER) ? clicker : this;
            Unit* target = (itr->second.castFlags & NPC_CLICK_CAST_TARGET_CLICKER) ? clicker : this;
            uint64 origCasterGUID = (itr->second.castFlags & NPC_CLICK_CAST_ORIG_CASTER_OWNER) ? GetOwnerGUID() : clicker->GetGUID();

            SpellEntry const* spellEntry = sSpellStore.LookupEntry(itr->second.spellId);
            // if (!spellEntry) should be checked at npc_spellclick load

            if (seatId > -1)
            {
                uint8 i = 0;
                bool valid = false;
                while (i < MAX_SPELL_EFFECTS && !valid)
                {
                    if (spellEntry->EffectApplyAuraName[i] == SPELL_AURA_CONTROL_VEHICLE)
                    {
                        valid = true;
                        break;
                    }
                    ++i;
                }

                if (!valid)
                {
                    sLog->outErrorDb("Spell %u specified in npc_spellclick_spells is not a valid vehicle enter aura!", itr->second.spellId);
                    return false;
                }

                if (IsInMap(caster))
                    caster->CastCustomSpell(itr->second.spellId, SpellValueMod(SPELLVALUE_BASE_POINT0+i), seatId+1, target, true, NULL, NULL, origCasterGUID);
                else    // This can happen during Player::_LoadAuras
                {
                    int32 bp0 = seatId;
                    Aura::TryRefreshStackOrCreate(spellEntry, MAX_EFFECT_MASK, this, clicker, &bp0, NULL, origCasterGUID);
                }
            }
            else
            {
                if (IsInMap(caster))
                    caster->CastSpell(target, spellEntry, true, NULL, NULL, origCasterGUID);
                else
                    Aura::TryRefreshStackOrCreate(spellEntry, MAX_EFFECT_MASK, this, clicker, NULL, NULL, origCasterGUID);
            }

            success = true;
        }
    }

    Creature* creature = ToCreature();
    if (creature && creature->IsAIEnabled)
        creature->AI()->DoAction(EVENT_SPELLCLICK);

    return success;
}

void Unit::EnterVehicle(Unit *base, int8 seatId)
{
    CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, seatId+1, base, false);
}

void Unit::_EnterVehicle(Vehicle* vehicle, int8 seatId, AuraApplication const* aurApp)
{
    // Must be called only from aura handler
    if (!isAlive() || GetVehicleKit() == vehicle || vehicle->GetBase()->IsOnVehicle(this))
        return;

    if (m_vehicle)
    {
        if (m_vehicle == vehicle)
        {
            if (seatId >= 0 && seatId != GetTransSeat())
            {
                sLog->outDebug(LOG_FILTER_VEHICLES, "EnterVehicle: %u leave vehicle %u seat %d and enter %d.", GetEntry(), m_vehicle->GetBase()->GetEntry(), GetTransSeat(), seatId);
                ChangeSeat(seatId);
            }
            return;
        }
        else
        {
            sLog->outDebug(LOG_FILTER_VEHICLES, "EnterVehicle: %u exit %u and enter %u.", GetEntry(), m_vehicle->GetBase()->GetEntry(), vehicle->GetBase()->GetEntry());
            ExitVehicle();
        }
    }

    if (aurApp && aurApp->GetRemoveMode())
        return;

    if (Player* plr = ToPlayer())
    {
        if (vehicle->GetBase()->GetTypeId() == TYPEID_PLAYER && plr->isInCombat())
            return;

        InterruptNonMeleeSpells(false);
        plr->StopCastingCharm();
        plr->StopCastingBindSight();
        Unmount();
        RemoveAurasByType(SPELL_AURA_MOUNTED);

        // drop flag at invisible in bg
        if (Battleground *bg = plr->GetBattleground())
            bg->EventPlayerDroppedFlag(plr);

        WorldPacket data(SMSG_ON_CANCEL_EXPECTED_RIDE_VEHICLE_AURA, 0);
        plr->GetSession()->SendPacket(&data);

        plr->UnsummonPetTemporaryIfAny();
    }

    ASSERT(!m_vehicle);
    m_vehicle = vehicle;
    if (!m_vehicle->AddPassenger(this, seatId))
    {
        m_vehicle = NULL;
        return;
    }
}

void Unit::ChangeSeat(int8 seatId, bool next)
{
    if (!m_vehicle)
        return;

    if (seatId < 0)
    {
        seatId = m_vehicle->GetNextEmptySeat(GetTransSeat(), next);
        if (seatId < 0)
            return;
    }
    else if (seatId == GetTransSeat() || !m_vehicle->HasEmptySeat(seatId))
        return;

    m_vehicle->RemovePassenger(this);
    if (!m_vehicle->AddPassenger(this, seatId))
        ASSERT(false);
}

void Unit::ExitVehicle(Position const* exitPosition)
{
    // This function can be called at upper level code to initialize an exit from the passenger's side.
    if (!m_vehicle)
        return;

    GetVehicleBase()->RemoveAurasByType(SPELL_AURA_CONTROL_VEHICLE, GetGUID());
   _ExitVehicle(exitPosition);
}

void Unit::_ExitVehicle(Position const* exitPosition)
{
    if (!m_vehicle)
        return;

    m_vehicle->RemovePassenger(this);

    // This should be done before dismiss, because there may be some aura removal
    Vehicle *vehicle = m_vehicle;
    m_vehicle = NULL;

    SetControlled(false, UNIT_STAT_ROOT);       // SMSG_MOVE_FORCE_UNROOT, ~MOVEMENTFLAG_ROOT

    Position pos;
    if (!exitPosition)                           // Exit position not specified
        vehicle->GetBase()->GetPosition(&pos);
    else
        pos = *exitPosition;

    AddUnitState(UNIT_STAT_MOVE);

    if (GetTypeId() == TYPEID_PLAYER)
        ToPlayer()->SetFallInformation(0, GetPositionZ());
    else if (HasUnitMovementFlag(MOVEMENTFLAG_ROOT))
    {
        WorldPacket data(SMSG_SPLINE_MOVE_UNROOT, 8);
        data.append(GetPackGUID());
        SendMessageToSet(&data, false);
    }

    SendMonsterMoveExitVehicle(&pos);
    Relocate(&pos);

    if (Player* plr = ToPlayer())
        plr->ResummonPetTemporaryUnSummonedIfAny();

    WorldPacket data2;
    BuildHeartBeatMsg(&data2);
    SendMessageToSet(&data2, false);

    if (vehicle->GetBase()->HasUnitTypeMask(UNIT_MASK_MINION))
        if (((Minion*)vehicle->GetBase())->GetOwner() == this)
            vehicle->Dismiss();

    if (HasUnitTypeMask(UNIT_MASK_ACCESSORY))
    {
        // Vehicle just died, we die too
        if (vehicle->GetBase()->getDeathState() == JUST_DIED)
            setDeathState(JUST_DIED);
        // If for other reason we as minion are exiting the vehicle (ejected, master unmounted) - unsummon
        else
            ToTempSummon()->UnSummon(2000); // Approximation
    }
}

void Unit::BuildMovementPacket(ByteBuffer *data) const
{
    switch (GetTypeId())
    {
        case TYPEID_UNIT:
            if (canFly())
                const_cast<Unit*>(this)->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
            break;
        case TYPEID_PLAYER:
            // remove unknown, unused etc flags for now
            const_cast<Unit*>(this)->RemoveUnitMovementFlag(MOVEMENTFLAG_SPLINE_ENABLED);
            if (isInFlight())
            {
                WPAssert(const_cast<Unit*>(this)->GetMotionMaster()->GetCurrentMovementGeneratorType() == FLIGHT_MOTION_TYPE);
                const_cast<Unit*>(this)->AddUnitMovementFlag(MOVEMENTFLAG_FORWARD | MOVEMENTFLAG_SPLINE_ENABLED);
            }
            break;
        default:
            break;
    }

    *data << uint32(GetUnitMovementFlags()); // movement flags
    *data << uint16(m_movementInfo.flags2);    // 2.3.0
    *data << uint32(getMSTime());            // time
    *data << GetPositionX();
    *data << GetPositionY();
    *data << GetPositionZ();
    *data << GetOrientation();

    // 0x00000200
    if (GetUnitMovementFlags() & MOVEMENTFLAG_ONTRANSPORT)
    {
        if (m_vehicle)
            data->append(m_vehicle->GetBase()->GetPackGUID());
        else if (GetTransport())
            data->append(GetTransport()->GetPackGUID());
        else
            *data << (uint8)0;

        *data << float (GetTransOffsetX());
        *data << float (GetTransOffsetY());
        *data << float (GetTransOffsetZ());
        *data << float (GetTransOffsetO());
        *data << uint32(GetTransTime());
        *data << uint8 (GetTransSeat());
    }

    // 0x02200000
    if ((GetUnitMovementFlags() & (MOVEMENTFLAG_SWIMMING | MOVEMENTFLAG_FLYING))
        || (m_movementInfo.flags2 & MOVEMENTFLAG2_ALWAYS_ALLOW_PITCHING))
        *data << (float)m_movementInfo.pitch;

    *data << (uint32)m_movementInfo.fallTime;

    // 0x00001000
    if (GetUnitMovementFlags() & MOVEMENTFLAG_JUMPING)
    {
        *data << (float)m_movementInfo.j_zspeed;
        *data << (float)m_movementInfo.j_sinAngle;
        *data << (float)m_movementInfo.j_cosAngle;
        *data << (float)m_movementInfo.j_xyspeed;
    }

    // 0x04000000
    if (GetUnitMovementFlags() & MOVEMENTFLAG_SPLINE_ELEVATION)
        *data << (float)m_movementInfo.splineElevation;
}

void Unit::SetFlying(bool apply)
{
    if (apply)
    {
        SetByteFlag(UNIT_FIELD_BYTES_1, 3, 0x02);
        AddUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING);
    }
    else
    {
        RemoveByteFlag(UNIT_FIELD_BYTES_1, 3, 0x02);
        RemoveUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING);
    }
}

void Unit::NearTeleportTo(float x, float y, float z, float orientation, bool casting /*= false*/)
{
    if (GetTypeId() == TYPEID_PLAYER)
        ToPlayer()->TeleportTo(GetMapId(), x, y, z, orientation, TELE_TO_NOT_LEAVE_TRANSPORT | TELE_TO_NOT_LEAVE_COMBAT | TELE_TO_NOT_UNSUMMON_PET | (casting ? TELE_TO_SPELL : 0));
    else
    {
        // FIXME: this interrupts spell visual
        DestroyForNearbyPlayers();
        SetPosition(x, y, z, orientation, true);
    }
}

bool Unit::SetPosition(float x, float y, float z, float orientation, bool teleport)
{
    // prevent crash when a bad coord is sent by the client
    if (!Trinity::IsValidMapCoord(x, y, z, orientation))
    {
        sLog->outDebug(LOG_FILTER_UNITS, "Unit::SetPosition(%f, %f, %f) .. bad coordinates!", x, y, z);
        return false;
    }

    bool turn = (GetOrientation() != orientation);
    bool relocated = (teleport || GetPositionX() != x || GetPositionY() != y || GetPositionZ() != z);

    if (turn)
        RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TURNING);

    if (relocated)
    {
        RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_MOVE);

        // move and update visible state if need
        if (GetTypeId() == TYPEID_PLAYER)
            GetMap()->PlayerRelocation(ToPlayer(), x, y, z, orientation);
        else
            GetMap()->CreatureRelocation(ToCreature(), x, y, z, orientation);
    }
    else if (turn)
        SetOrientation(orientation);

    if ((relocated || turn) && IsVehicle())
        GetVehicleKit()->RelocatePassengers(x, y, z, orientation);

    return (relocated || turn);
}

void Unit::SendThreatListUpdate()
{
    if (uint32 count = getThreatManager().getThreatList().size())
    {
        //sLog->outDebug(LOG_FILTER_UNITS, "WORLD: Send SMSG_THREAT_UPDATE Message");
        WorldPacket data(SMSG_THREAT_UPDATE, 8 + count * 8);
        data.append(GetPackGUID());
        data << uint32(count);
        std::list<HostileReference*>& tlist = getThreatManager().getThreatList();
        for (std::list<HostileReference*>::const_iterator itr = tlist.begin(); itr != tlist.end(); ++itr)
        {
            data.appendPackGUID((*itr)->getUnitGuid());
            data << uint32((*itr)->getThreat() * 100);
        }
        SendMessageToSet(&data, false);
    }
}

void Unit::SendChangeCurrentVictimOpcode(HostileReference* pHostileReference)
{
    if (uint32 count = getThreatManager().getThreatList().size())
    {
        sLog->outDebug(LOG_FILTER_UNITS, "WORLD: Send SMSG_HIGHEST_THREAT_UPDATE Message");
        WorldPacket data(SMSG_HIGHEST_THREAT_UPDATE, 8 + 8 + count * 8);
        data.append(GetPackGUID());
        data.appendPackGUID(pHostileReference->getUnitGuid());
        data << uint32(count);
        std::list<HostileReference*>& tlist = getThreatManager().getThreatList();
        for (std::list<HostileReference*>::const_iterator itr = tlist.begin(); itr != tlist.end(); ++itr)
        {
            data.appendPackGUID((*itr)->getUnitGuid());
            data << uint32((*itr)->getThreat());
        }
        SendMessageToSet(&data, false);
    }
}

void Unit::SendClearThreatListOpcode()
{
    sLog->outDebug(LOG_FILTER_UNITS, "WORLD: Send SMSG_THREAT_CLEAR Message");
    WorldPacket data(SMSG_THREAT_CLEAR, 8);
    data.append(GetPackGUID());
    SendMessageToSet(&data, false);
}

void Unit::SendRemoveFromThreatListOpcode(HostileReference* pHostileReference)
{
    sLog->outDebug(LOG_FILTER_UNITS, "WORLD: Send SMSG_THREAT_REMOVE Message");
    WorldPacket data(SMSG_THREAT_REMOVE, 8 + 8);
    data.append(GetPackGUID());
    data.appendPackGUID(pHostileReference->getUnitGuid());
    SendMessageToSet(&data, false);
}

void Unit::RewardRage(uint32 damage, uint32 weaponSpeedHitFactor, bool attacker)
{
    float addRage;

    float rageconversion = ((0.0091107836f * getLevel() * getLevel()) + 3.225598133f * getLevel()) + 4.2652911f;

    // Unknown if correct, but lineary adjust rage conversion above level 70
    if (getLevel() > 70)
        rageconversion += 13.27f * (getLevel() - 70);

    if (attacker)
    {
        addRage = (damage / rageconversion * 7.5f + weaponSpeedHitFactor) / 2;

        // talent who gave more rage on attack
        AddPctN(addRage, GetTotalAuraModifier(SPELL_AURA_MOD_RAGE_FROM_DAMAGE_DEALT));
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
    if (Unit* victim = getVictim())
    {
        if (victim->getFactionTemplateEntry()->faction == faction_id)
        {
            AttackStop();
            if (IsNonMeleeSpellCasted(false))
                InterruptNonMeleeSpells(false);

            // melee and ranged forced attack cancel
            if (GetTypeId() == TYPEID_PLAYER)
                ToPlayer()->SendAttackSwingCancelAttack();
        }
    }

    AttackerSet const& attackers = getAttackers();
    for (AttackerSet::const_iterator itr = attackers.begin(); itr != attackers.end();)
    {
        if ((*itr)->getFactionTemplateEntry()->faction == faction_id)
        {
            (*itr)->AttackStop();
            itr = attackers.begin();
        }
        else
            ++itr;
    }

    getHostileRefManager().deleteReferencesForFaction(faction_id);

    for (ControlList::const_iterator itr = m_Controlled.begin(); itr != m_Controlled.end(); ++itr)
            (*itr)->StopAttackFaction(faction_id);
}

void Unit::OutDebugInfo() const
{
    sLog->outError("Unit::OutDebugInfo");
    sLog->outString("GUID "UI64FMTD", entry %u, type %u, name %s", GetGUID(), GetEntry(), (uint32)GetTypeId(), GetName());
    sLog->outString("OwnerGUID "UI64FMTD", MinionGUID "UI64FMTD", CharmerGUID "UI64FMTD", CharmedGUID "UI64FMTD, GetOwnerGUID(), GetMinionGUID(), GetCharmerGUID(), GetCharmGUID());
    sLog->outString("In world %u, unit type mask %u", (uint32)(IsInWorld() ? 1 : 0), m_unitTypeMask);
    if (IsInWorld())
        sLog->outString("Mapid %u", GetMapId());

    sLog->outStringInLine("Summon Slot: ");
    for (uint32 i = 0; i < MAX_SUMMON_SLOT; ++i)
        sLog->outStringInLine(UI64FMTD", ", m_SummonSlot[i]);
    sLog->outString();

    sLog->outStringInLine("Controlled List: ");
    for (ControlList::const_iterator itr = m_Controlled.begin(); itr != m_Controlled.end(); ++itr)
        sLog->outStringInLine(UI64FMTD", ", (*itr)->GetGUID());
    sLog->outString();

    sLog->outStringInLine("Aura List: ");
    for (AuraApplicationMap::const_iterator itr = m_appliedAuras.begin(); itr != m_appliedAuras.end(); ++itr)
        sLog->outStringInLine("%u, ", itr->first);
    sLog->outString();

    if (IsVehicle())
    {
        sLog->outStringInLine("Passenger List: ");
        for (SeatMap::iterator itr = GetVehicleKit()->Seats.begin(); itr != GetVehicleKit()->Seats.end(); ++itr)
            if (Unit* passenger = ObjectAccessor::GetUnit(*GetVehicleBase(), itr->second.Passenger))
                sLog->outStringInLine(UI64FMTD", ", passenger->GetGUID());
        sLog->outString();
    }

    if (GetVehicle())
        sLog->outString("On vehicle %u.", GetVehicleBase()->GetEntry());
}

uint32 Unit::GetRemainingPeriodicAmount(uint64 caster, uint32 spellId, AuraType auraType, uint8 effectIndex) const
{
    uint32 amount = 0;
    AuraEffectList const& periodicAuras = GetAuraEffectsByType(auraType);
    for (AuraEffectList::const_iterator i = periodicAuras.begin(); i != periodicAuras.end(); ++i)
    {
        if ((*i)->GetCasterGUID() != caster || (*i)->GetId() != spellId || (*i)->GetEffIndex() != effectIndex)
            continue;
        amount += uint32(((*i)->GetAmount() * std::max<int32>((*i)->GetTotalTicks() - int32((*i)->GetTickNumber()), 0)) / (*i)->GetTotalTicks());
        break;
    }

    return amount;
}

void Unit::SendClearTarget()
{
    WorldPacket data(SMSG_BREAK_TARGET, GetPackGUID().size());
    data.append(GetPackGUID());
    SendMessageToSet(&data, false);
}

void CharmInfo::SetIsCommandAttack(bool val)
{
    m_isCommandAttack = val;
}

bool CharmInfo::IsCommandAttack()
{
    return m_isCommandAttack;
}

void CharmInfo::SaveStayPosition()
{
    m_unit->GetPosition(m_stayX, m_stayY, m_stayZ);
}

void CharmInfo::GetStayPosition(float &x, float &y, float &z)
{
    x = m_stayX;
    y = m_stayY;
    z = m_stayZ;
}

void CharmInfo::SetIsAtStay(bool val)
{
    m_isAtStay = val;
}

bool CharmInfo::IsAtStay()
{
    return m_isAtStay;
}

void CharmInfo::SetIsFollowing(bool val)
{
    m_isFollowing = val;
}

bool CharmInfo::IsFollowing()
{
    return m_isFollowing;
}

void CharmInfo::SetIsReturning(bool val)
{
    m_isReturning = val;
}

bool CharmInfo::IsReturning()
{
    return m_isReturning;
}
