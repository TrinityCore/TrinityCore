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
#include "Log.h"
#include "ObjectMgr.h"
#include "Vehicle.h"
#include "Unit.h"
#include "Util.h"
#include "WorldPacket.h"
#include "ScriptMgr.h"
#include "CreatureAI.h"
#include "ZoneScript.h"

Vehicle::Vehicle(Unit* unit, VehicleEntry const* vehInfo, uint32 creatureEntry) : me(unit), m_vehicleInfo(vehInfo), m_usableSeatNum(0), m_bonusHP(0), m_creatureEntry(creatureEntry)
{
    for (uint32 i = 0; i < MAX_VEHICLE_SEATS; ++i)
    {
        if (uint32 seatId = m_vehicleInfo->m_seatID[i])
            if (VehicleSeatEntry const* veSeat = sVehicleSeatStore.LookupEntry(seatId))
            {
                m_Seats.insert(std::make_pair(i, VehicleSeat(veSeat)));
                if (veSeat->CanEnterOrExit())
                    ++m_usableSeatNum;
            }
    }

    InitMovementInfoForBase();
}

Vehicle::~Vehicle()
{
    for (SeatMap::const_iterator itr = m_Seats.begin(); itr != m_Seats.end(); ++itr)
        ASSERT(!itr->second.passenger);
}

void Vehicle::Install()
{
    if (Creature* creature = me->ToCreature())
    {
        switch (m_vehicleInfo->m_powerType)
        {
            case POWER_STEAM:
            case POWER_HEAT:
            case POWER_BLOOD:
            case POWER_OOZE:
            case POWER_WRATH:
                me->setPowerType(POWER_ENERGY);
                me->SetMaxPower(POWER_ENERGY, 100);
                break;
            case POWER_PYRITE:
                me->setPowerType(POWER_ENERGY);
                me->SetMaxPower(POWER_ENERGY, 50);
                break;
            default:
                for (uint32 i = 0; i < MAX_SPELL_VEHICLE; ++i)
                {
                    if (!creature->m_spells[i])
                        continue;

                    SpellEntry const* spellInfo = sSpellStore.LookupEntry(creature->m_spells[i]);
                    if (!spellInfo)
                        continue;

                    if (spellInfo->powerType == POWER_ENERGY)
                    {
                        me->setPowerType(POWER_ENERGY);
                        me->SetMaxPower(POWER_ENERGY, 100);
                        break;
                    }
                }
                break;
        }
    }

    if (GetBase()->GetTypeId() == TYPEID_UNIT)
        sScriptMgr->OnInstall(this);
}

void Vehicle::InstallAllAccessories(bool evading)
{
    if (GetBase()->GetTypeId() == TYPEID_PLAYER || !evading)
        RemoveAllPassengers();   // We might have aura's saved in the DB with now invalid casters - remove

    VehicleAccessoryList const* accessories = sObjectMgr->GetVehicleAccessoryList(this);
    if (!accessories)
        return;

    for (VehicleAccessoryList::const_iterator itr = accessories->begin(); itr != accessories->end(); ++itr)
        if (!evading || itr->IsMinion)  // only install minions on evade mode
            InstallAccessory(itr->AccessoryEntry, itr->SeatId, itr->IsMinion, itr->SummonedType, itr->SummonTime);
}

void Vehicle::Uninstall()
{
    sLog->outDebug(LOG_FILTER_VEHICLES, "Vehicle::Uninstall Entry: %u, GuidLow: %u", m_creatureEntry, me->GetGUIDLow());
    RemoveAllPassengers();

    if (GetBase()->GetTypeId() == TYPEID_UNIT)
        sScriptMgr->OnUninstall(this);
}

void Vehicle::Reset(bool evading /*= false*/)
{
    sLog->outDebug(LOG_FILTER_VEHICLES, "Vehicle::Reset Entry: %u, GuidLow: %u", m_creatureEntry, me->GetGUIDLow());
    if (me->GetTypeId() == TYPEID_PLAYER)
    {
        if (m_usableSeatNum)
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_PLAYER_VEHICLE);
    }
    else
    {
        ApplyAllImmunities();
        InstallAllAccessories(evading);
        if (m_usableSeatNum)
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
    }

    if (GetBase()->GetTypeId() == TYPEID_UNIT)
        sScriptMgr->OnReset(this);
}

void Vehicle::ApplyAllImmunities()
{
    // This couldn't be done in DB, because Vehicle's immunities are overriden by Player's ones

    // Vehicles should be immune on Knockback, Deathgrip ...
    me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
    me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK_DEST, true);
    me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);

    // ... Fear, Snare, Root, Stun ...
    me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
    me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SNARE, true);
    me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
    me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
    me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_STUN, true);
    me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
    me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);

    // Mechanical units & vehicles ( which are not Bosses, they have own immunities in DB ) should be also immune on healing ( exceptions in switch below )
    if (me->ToCreature() && me->ToCreature()->GetCreatureInfo()->type == CREATURE_TYPE_MECHANICAL && !me->ToCreature()->isWorldBoss())
    {
        // Heal & dispel ...
        me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_HEAL, true);
        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_PERIODIC_HEAL, true);

        // ... Shield & Immunity grant spells ...
        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_SCHOOL_IMMUNITY, true);
        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_UNATTACKABLE, true);
        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_SCHOOL_ABSORB, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SHIELD, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_IMMUNE_SHIELD , true);

        // ... Resistance, Split damage, Speed Increase, ...
        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_DAMAGE_SHIELD, true);
        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_SPLIT_DAMAGE_PCT, true);
        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_RESISTANCE, true);
        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_STAT, true);
        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, true);
        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_INCREASE_SPEED, true);
    }

    // Different immunities for vehicles goes below
    switch (GetVehicleInfo()->m_ID)
    {
        case 160:
            me->SetControlled(true, UNIT_STAT_ROOT);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_DECREASE_SPEED, true);
            break;
        default:
            break;
    }
}

void Vehicle::RemoveAllPassengers()
{
    sLog->outDebug(LOG_FILTER_VEHICLES, "Vehicle::RemoveAllPassengers. Entry: %u, GuidLow: %u", m_creatureEntry, me->GetGUIDLow());

    // Passengers always cast an aura with SPELL_AURA_CONTROL_VEHICLE on the vehicle
    // We just remove the aura and the unapply handler will make the target leave the vehicle.
    // We don't need to iterate over m_Seats
    me->RemoveAurasByType(SPELL_AURA_CONTROL_VEHICLE);

    // Following the above logic, this assertion should NEVER fail.
    // Even in 'hacky' cases, there should at least be VEHICLE_SPELL_RIDE_HARDCODED on us.
    // SeatMap::const_iterator itr;
    // for (itr = m_Seats.begin(); itr != m_Seats.end(); ++itr)
    //    ASSERT(!itr->second.passenger);
}

bool Vehicle::HasEmptySeat(int8 seatId) const
{
    SeatMap::const_iterator seat = m_Seats.find(seatId);
    if (seat == m_Seats.end())
        return false;
    return !seat->second.passenger;
}

Unit* Vehicle::GetPassenger(int8 seatId) const
{
    SeatMap::const_iterator seat = m_Seats.find(seatId);
    if (seat == m_Seats.end())
        return NULL;

    return ObjectAccessor::GetUnit(*GetBase(), seat->second.passenger);
}

int8 Vehicle::GetNextEmptySeat(int8 seatId, bool next) const
{
    SeatMap::const_iterator seat = m_Seats.find(seatId);
    if (seat == m_Seats.end())
        return -1;

    while (seat->second.passenger || (!seat->second.seatInfo->CanEnterOrExit() && !seat->second.seatInfo->IsUsableByOverride()))
    {
        if (next)
        {
            ++seat;
            if (seat == m_Seats.end())
                seat = m_Seats.begin();
        }
        else
        {
            if (seat == m_Seats.begin())
                seat = m_Seats.end();
            --seat;
        }

        if (seat->first == seatId)
            return -1; // no available seat
    }

    return seat->first;
}

void Vehicle::InstallAccessory(uint32 entry, int8 seatId, bool minion, uint8 type, uint32 summonTime)
{
    sLog->outDebug(LOG_FILTER_VEHICLES, "Vehicle: Installing accessory entry %u on vehicle entry %u (seat:%i)", entry, GetCreatureEntry(), seatId);
    if (Unit* passenger = GetPassenger(seatId))
    {
        // already installed
        if (passenger->GetEntry() == entry)
        {
            ASSERT(passenger->GetTypeId() == TYPEID_UNIT);
            if (me->GetTypeId() == TYPEID_UNIT)
            {
                if (me->ToCreature()->IsInEvadeMode() && passenger->ToCreature()->IsAIEnabled)
                    passenger->ToCreature()->AI()->EnterEvadeMode();
                return;
            }
        }
        else
            passenger->ExitVehicle(); // this should not happen
    }

    if (TempSummon* accessory = me->SummonCreature(entry, *me, TempSummonType(type), summonTime))
    {
        if (minion)
            accessory->AddUnitTypeMask(UNIT_MASK_ACCESSORY);

        if (!me->HandleSpellClick(accessory, seatId))
        {
            accessory->UnSummon();
            return;
        }

        // this cannot be checked instantly like this
        // spellsystem is delaying everything to next update tick
        //if (!accessory->IsOnVehicle(me))
        //{
        //    accessory->UnSummon();
        //    return;         // Something went wrong in the spellsystem
        //}

        // This is not good, we have to send update twice
        accessory->SendMovementFlagUpdate();

        if (GetBase()->GetTypeId() == TYPEID_UNIT)
            sScriptMgr->OnInstallAccessory(this, accessory);
    }
}

bool Vehicle::AddPassenger(Unit* unit, int8 seatId)
{
    if (unit->GetVehicle() != this)
        return false;

    SeatMap::iterator seat;
    if (seatId < 0) // no specific seat requirement
    {
        for (seat = m_Seats.begin(); seat != m_Seats.end(); ++seat)
            if (!seat->second.passenger && (seat->second.seatInfo->CanEnterOrExit() || seat->second.seatInfo->IsUsableByOverride()))
                break;

        if (seat == m_Seats.end()) // no available seat
            return false;
    }
    else
    {
        seat = m_Seats.find(seatId);
        if (seat == m_Seats.end())
            return false;

        if (seat->second.passenger)
        {
            if (Unit* passenger = ObjectAccessor::GetUnit(*GetBase(), seat->second.passenger))
                passenger->ExitVehicle();
            else
                seat->second.passenger = 0;
        }

        ASSERT(!seat->second.passenger);
    }

    sLog->outDebug(LOG_FILTER_VEHICLES, "Unit %s enter vehicle entry %u id %u dbguid %u seat %d", unit->GetName(), me->GetEntry(), m_vehicleInfo->m_ID, me->GetGUIDLow(), (int32)seat->first);

    seat->second.passenger = unit->GetGUID();
    if (seat->second.seatInfo->CanEnterOrExit())
    {
        ASSERT(m_usableSeatNum);
        --m_usableSeatNum;
        if (!m_usableSeatNum)
        {
            if (me->GetTypeId() == TYPEID_PLAYER)
                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_PLAYER_VEHICLE);
            else
                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
        }
    }

    if (seat->second.seatInfo->m_flags && !(seat->second.seatInfo->m_flags & VEHICLE_SEAT_FLAG_UNK11))
        unit->AddUnitState(UNIT_STAT_ONVEHICLE);

    unit->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT);
    VehicleSeatEntry const* veSeat = seat->second.seatInfo;
    unit->m_movementInfo.t_pos.m_positionX = veSeat->m_attachmentOffsetX;
    unit->m_movementInfo.t_pos.m_positionY = veSeat->m_attachmentOffsetY;
    unit->m_movementInfo.t_pos.m_positionZ = veSeat->m_attachmentOffsetZ;
    unit->m_movementInfo.t_pos.m_orientation = 0;
    unit->m_movementInfo.t_time = 0; // 1 for player
    unit->m_movementInfo.t_seat = seat->first;

    if (me->GetTypeId() == TYPEID_UNIT
        && unit->GetTypeId() == TYPEID_PLAYER
        && seat->first == 0 && seat->second.seatInfo->m_flags & VEHICLE_SEAT_FLAG_CAN_CONTROL)
    {
        if (!me->SetCharmedBy(unit, CHARM_TYPE_VEHICLE))
            ASSERT(false);

        // hack: should be done by aura system
        if (VehicleScalingInfo const* scalingInfo = sObjectMgr->GetVehicleScalingInfo(m_vehicleInfo->m_ID))
        {
            Player* player = unit->ToPlayer();
            float averageItemLevel = player->GetAverageItemLevel();
            if (averageItemLevel < scalingInfo->baseItemLevel)
                averageItemLevel = scalingInfo->baseItemLevel;
            averageItemLevel -= scalingInfo->baseItemLevel;

            float currentHealthPct = float(me->GetHealth() / me->GetMaxHealth());
            m_bonusHP = uint32(me->GetMaxHealth() * (averageItemLevel * scalingInfo->scalingFactor));
            me->SetMaxHealth(me->GetMaxHealth() + m_bonusHP);
            me->SetHealth(uint32((me->GetHealth() + m_bonusHP) * currentHealthPct));
        }
    }

    if (me->IsInWorld())
    {
        unit->SendClearTarget();                                // SMSG_BREAK_TARGET
        unit->SetControlled(true, UNIT_STAT_ROOT);              // SMSG_FORCE_ROOT - In some cases we send SMSG_SPLINE_MOVE_ROOT here (for creatures)
                                                                // also adds MOVEMENTFLAG_ROOT
        unit->SendMonsterMoveTransport(me);                     // SMSG_MONSTER_MOVE_TRANSPORT

        if (me->GetTypeId() == TYPEID_UNIT)
        {
            if (me->ToCreature()->IsAIEnabled)
                me->ToCreature()->AI()->PassengerBoarded(unit, seat->first, true);

            // update all passenger's positions
            RelocatePassengers(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
        }
    }

    if (GetBase()->GetTypeId() == TYPEID_UNIT)
        sScriptMgr->OnAddPassenger(this, unit, seatId);

    return true;
}

void Vehicle::RemovePassenger(Unit* unit)
{
    if (unit->GetVehicle() != this)
        return;

    SeatMap::iterator seat = GetSeatIteratorForPassenger(unit);
    ASSERT(seat != m_Seats.end());

    sLog->outDebug(LOG_FILTER_VEHICLES, "Unit %s exit vehicle entry %u id %u dbguid %u seat %d", unit->GetName(), me->GetEntry(), m_vehicleInfo->m_ID, me->GetGUIDLow(), (int32)seat->first);

    seat->second.passenger = 0;
    if (seat->second.seatInfo->CanEnterOrExit())
    {
        if (!m_usableSeatNum)
        {
            if (me->GetTypeId() == TYPEID_PLAYER)
                me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_PLAYER_VEHICLE);
            else
                me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
        }
        ++m_usableSeatNum;
    }

    unit->ClearUnitState(UNIT_STAT_ONVEHICLE);

    if (me->GetTypeId() == TYPEID_UNIT && unit->GetTypeId() == TYPEID_PLAYER && seat->first == 0 && seat->second.seatInfo->m_flags & VEHICLE_SEAT_FLAG_CAN_CONTROL)
    {
        me->RemoveCharmedBy(unit);

        if (m_bonusHP)
        {
            me->SetHealth(me->GetHealth() - m_bonusHP);
            me->SetMaxHealth(me->GetMaxHealth() - m_bonusHP);
            m_bonusHP = 0;
        }
    }

    if (me->IsInWorld())
    {
        unit->RemoveUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT);
        unit->m_movementInfo.t_pos.Relocate(0, 0, 0, 0);
        unit->m_movementInfo.t_time = 0;
        unit->m_movementInfo.t_seat = 0;
    }

    if (me->GetTypeId() == TYPEID_UNIT && me->ToCreature()->IsAIEnabled)
        me->ToCreature()->AI()->PassengerBoarded(unit, seat->first, false);

    // only for flyable vehicles
    if (unit->HasUnitMovementFlag(MOVEMENTFLAG_FLYING))
        me->CastSpell(unit, VEHICLE_SPELL_PARACHUTE, true);

    if (GetBase()->GetTypeId() == TYPEID_UNIT)
        sScriptMgr->OnRemovePassenger(this, unit);
}

void Vehicle::RelocatePassengers(float x, float y, float z, float ang)
{
    Map* map = me->GetMap();
    ASSERT(map != NULL);

    // not sure that absolute position calculation is correct, it must depend on vehicle orientation and pitch angle
    for (SeatMap::const_iterator itr = m_Seats.begin(); itr != m_Seats.end(); ++itr)
        if (Unit* passenger = ObjectAccessor::GetUnit(*GetBase(), itr->second.passenger))
        {
            ASSERT(passenger->IsInWorld());
            ASSERT(passenger->IsOnVehicle(GetBase()));
            ASSERT(GetSeatForPassenger(passenger));

            float px = x + passenger->m_movementInfo.t_pos.m_positionX;
            float py = y + passenger->m_movementInfo.t_pos.m_positionY;
            float pz = z + passenger->m_movementInfo.t_pos.m_positionZ;
            float po = ang + passenger->m_movementInfo.t_pos.m_orientation;

            passenger->SetPosition(px, py, pz, po);
        }
}

void Vehicle::Dismiss()
{
    sLog->outDebug(LOG_FILTER_VEHICLES, "Vehicle::Dismiss Entry: %u, GuidLow %u", m_creatureEntry, me->GetGUIDLow());
    Uninstall();
    me->DestroyForNearbyPlayers();
    me->CombatStop();
    me->AddObjectToRemoveList();
}

void Vehicle::InitMovementInfoForBase()
{
    uint32 vehicleFlags = GetVehicleInfo()->m_flags;

    if (vehicleFlags & VEHICLE_FLAG_NO_STRAFE)
        me->AddExtraUnitMovementFlag(MOVEMENTFLAG2_NO_STRAFE);
    if (vehicleFlags & VEHICLE_FLAG_NO_JUMPING)
        me->AddExtraUnitMovementFlag(MOVEMENTFLAG2_NO_JUMPING);
    if (vehicleFlags & VEHICLE_FLAG_FULLSPEEDTURNING)
        me->AddExtraUnitMovementFlag(MOVEMENTFLAG2_FULL_SPEED_TURNING);
    if (vehicleFlags & VEHICLE_FLAG_ALLOW_PITCHING)
        me->AddExtraUnitMovementFlag(MOVEMENTFLAG2_ALWAYS_ALLOW_PITCHING);
    if (vehicleFlags & VEHICLE_FLAG_FULLSPEEDPITCHING)
        me->AddExtraUnitMovementFlag(MOVEMENTFLAG2_FULL_SPEED_PITCHING);
}

VehicleSeatEntry const* Vehicle::GetSeatForPassenger(Unit* passenger)
{
    SeatMap::iterator itr;
    for (itr = m_Seats.begin(); itr != m_Seats.end(); ++itr)
        if (itr->second.passenger == passenger->GetGUID())
            return itr->second.seatInfo;

    return NULL;
}

SeatMap::iterator Vehicle::GetSeatIteratorForPassenger(Unit* passenger)
{
    SeatMap::iterator itr;
    for (itr = m_Seats.begin(); itr != m_Seats.end(); ++itr)
        if (itr->second.passenger == passenger->GetGUID())
            return itr;

    return m_Seats.end();
}

uint8 Vehicle::GetAvailableSeatCount() const
{
    uint8 ret = 0;
    SeatMap::const_iterator itr;
    for (itr = m_Seats.begin(); itr != m_Seats.end(); ++itr)
        if (!itr->second.passenger && (itr->second.seatInfo->CanEnterOrExit() || itr->second.seatInfo->IsUsableByOverride()))
            ++ret;

    return ret;
}
