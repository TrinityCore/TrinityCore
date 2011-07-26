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
#include "SpellMgr.h"
#include "SpellInfo.h"

Vehicle::Vehicle(Unit* unit, VehicleEntry const* vehInfo, uint32 creatureEntry) : _me(unit), _vehicleInfo(vehInfo), _usableSeatNum(0), _creatureEntry(creatureEntry)
{
    for (uint32 i = 0; i < MAX_VEHICLE_SEATS; ++i)
    {
        if (uint32 seatId = _vehicleInfo->m_seatID[i])
            if (VehicleSeatEntry const* veSeat = sVehicleSeatStore.LookupEntry(seatId))
            {
                Seats.insert(std::make_pair(i, VehicleSeat(veSeat)));
                if (veSeat->CanEnterOrExit())
                    ++_usableSeatNum;
            }
    }

    InitMovementInfoForBase();
}

Vehicle::~Vehicle()
{
    for (SeatMap::const_iterator itr = Seats.begin(); itr != Seats.end(); ++itr)
        ASSERT(!itr->second.Passenger);
}

void Vehicle::Install()
{
    if (Creature* creature = _me->ToCreature())
    {
        switch (_vehicleInfo->m_powerType)
        {
            case POWER_STEAM:
            case POWER_HEAT:
            case POWER_BLOOD:
            case POWER_OOZE:
            case POWER_WRATH:
                _me->setPowerType(POWER_ENERGY);
                _me->SetMaxPower(POWER_ENERGY, 100);
                break;
            case POWER_PYRITE:
                _me->setPowerType(POWER_ENERGY);
                _me->SetMaxPower(POWER_ENERGY, 50);
                break;
            default:
                for (uint32 i = 0; i < MAX_SPELL_VEHICLE; ++i)
                {
                    if (!creature->m_spells[i])
                        continue;

                    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(creature->m_spells[i]);
                    if (!spellInfo)
                        continue;

                    if (spellInfo->PowerType == POWER_ENERGY)
                    {
                        _me->setPowerType(POWER_ENERGY);
                        _me->SetMaxPower(POWER_ENERGY, 100);
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
    sLog->outDebug(LOG_FILTER_VEHICLES, "Vehicle::Uninstall Entry: %u, GuidLow: %u", _creatureEntry, _me->GetGUIDLow());
    RemoveAllPassengers();

    if (GetBase()->GetTypeId() == TYPEID_UNIT)
        sScriptMgr->OnUninstall(this);
}

void Vehicle::Reset(bool evading /*= false*/)
{
    sLog->outDebug(LOG_FILTER_VEHICLES, "Vehicle::Reset Entry: %u, GuidLow: %u", _creatureEntry, _me->GetGUIDLow());
    if (_me->GetTypeId() == TYPEID_PLAYER)
    {
        if (_usableSeatNum)
            _me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_PLAYER_VEHICLE);
    }
    else
    {
        ApplyAllImmunities();
        InstallAllAccessories(evading);
        if (_usableSeatNum)
            _me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
    }

    if (GetBase()->GetTypeId() == TYPEID_UNIT)
        sScriptMgr->OnReset(this);
}

void Vehicle::ApplyAllImmunities()
{
    // This couldn't be done in DB, because some spells have MECHANIC_NONE

    // Vehicles should be immune on Knockback ...
    _me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
    _me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK_DEST, true);

    // Mechanical units & vehicles ( which are not Bosses, they have own immunities in DB ) should be also immune on healing ( exceptions in switch below )
    if (_me->ToCreature() && _me->ToCreature()->GetCreatureInfo()->type == CREATURE_TYPE_MECHANICAL && !_me->ToCreature()->isWorldBoss())
    {
        // Heal & dispel ...
        _me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_HEAL, true);
        _me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_HEAL_PCT, true);
        _me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_DISPEL, true);
        _me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_PERIODIC_HEAL, true);

        // ... Shield & Immunity grant spells ...
        _me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_SCHOOL_IMMUNITY, true);
        _me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_UNATTACKABLE, true);
        _me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_SCHOOL_ABSORB, true);
        _me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SHIELD, true);
        _me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_IMMUNE_SHIELD , true);

        // ... Resistance, Split damage, Change stats ...
        _me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_DAMAGE_SHIELD, true);
        _me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_SPLIT_DAMAGE_PCT, true);
        _me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_RESISTANCE, true);
        _me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_STAT, true);
        _me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, true);
    }

    // Different immunities for vehicles goes below
    switch (GetVehicleInfo()->m_ID)
    {
        case 160:
            _me->SetControlled(true, UNIT_STAT_ROOT);
            _me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_DECREASE_SPEED, true);
            break;
        default:
            break;
    }
}

void Vehicle::RemoveAllPassengers()
{
    sLog->outDebug(LOG_FILTER_VEHICLES, "Vehicle::RemoveAllPassengers. Entry: %u, GuidLow: %u", _creatureEntry, _me->GetGUIDLow());

    // Passengers always cast an aura with SPELL_AURA_CONTROL_VEHICLE on the vehicle
    // We just remove the aura and the unapply handler will make the target leave the vehicle.
    // We don't need to iterate over m_Seats
    _me->RemoveAurasByType(SPELL_AURA_CONTROL_VEHICLE);

    // Following the above logic, this assertion should NEVER fail.
    // Even in 'hacky' cases, there should at least be VEHICLE_SPELL_RIDE_HARDCODED on us.
    // SeatMap::const_iterator itr;
    // for (itr = m_Seats.begin(); itr != m_Seats.end(); ++itr)
    //    ASSERT(!itr->second.passenger);
}

bool Vehicle::HasEmptySeat(int8 seatId) const
{
    SeatMap::const_iterator seat = Seats.find(seatId);
    if (seat == Seats.end())
        return false;
    return !seat->second.Passenger;
}

Unit* Vehicle::GetPassenger(int8 seatId) const
{
    SeatMap::const_iterator seat = Seats.find(seatId);
    if (seat == Seats.end())
        return NULL;

    return ObjectAccessor::GetUnit(*GetBase(), seat->second.Passenger);
}

int8 Vehicle::GetNextEmptySeat(int8 seatId, bool next) const
{
    SeatMap::const_iterator seat = Seats.find(seatId);
    if (seat == Seats.end())
        return -1;

    while (seat->second.Passenger || (!seat->second.SeatInfo->CanEnterOrExit() && !seat->second.SeatInfo->IsUsableByOverride()))
    {
        if (next)
        {
            ++seat;
            if (seat == Seats.end())
                seat = Seats.begin();
        }
        else
        {
            if (seat == Seats.begin())
                seat = Seats.end();
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
            if (_me->GetTypeId() == TYPEID_UNIT)
            {
                if (_me->ToCreature()->IsInEvadeMode() && passenger->ToCreature()->IsAIEnabled)
                    passenger->ToCreature()->AI()->EnterEvadeMode();
                return;
            }
        }
        else
            passenger->ExitVehicle(); // this should not happen
    }

    if (TempSummon* accessory = _me->SummonCreature(entry, *_me, TempSummonType(type), summonTime))
    {
        if (minion)
            accessory->AddUnitTypeMask(UNIT_MASK_ACCESSORY);

        if (!_me->HandleSpellClick(accessory, seatId))
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
        for (seat = Seats.begin(); seat != Seats.end(); ++seat)
            if (!seat->second.Passenger && (seat->second.SeatInfo->CanEnterOrExit() || seat->second.SeatInfo->IsUsableByOverride()))
                break;

        if (seat == Seats.end()) // no available seat
            return false;
    }
    else
    {
        seat = Seats.find(seatId);
        if (seat == Seats.end())
            return false;

        if (seat->second.Passenger)
        {
            if (Unit* passenger = ObjectAccessor::GetUnit(*GetBase(), seat->second.Passenger))
                passenger->ExitVehicle();
            else
                seat->second.Passenger = 0;
        }

        ASSERT(!seat->second.Passenger);
    }

    sLog->outDebug(LOG_FILTER_VEHICLES, "Unit %s enter vehicle entry %u id %u dbguid %u seat %d", unit->GetName(), _me->GetEntry(), _vehicleInfo->m_ID, _me->GetGUIDLow(), (int32)seat->first);

    seat->second.Passenger = unit->GetGUID();
    if (seat->second.SeatInfo->CanEnterOrExit())
    {
        ASSERT(_usableSeatNum);
        --_usableSeatNum;
        if (!_usableSeatNum)
        {
            if (_me->GetTypeId() == TYPEID_PLAYER)
                _me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_PLAYER_VEHICLE);
            else
                _me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
        }
    }

    if (seat->second.SeatInfo->m_flags && !(seat->second.SeatInfo->m_flags & VEHICLE_SEAT_FLAG_UNK11))
        unit->AddUnitState(UNIT_STAT_ONVEHICLE);

    unit->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT);
    VehicleSeatEntry const* veSeat = seat->second.SeatInfo;
    unit->m_movementInfo.t_pos.m_positionX = veSeat->m_attachmentOffsetX;
    unit->m_movementInfo.t_pos.m_positionY = veSeat->m_attachmentOffsetY;
    unit->m_movementInfo.t_pos.m_positionZ = veSeat->m_attachmentOffsetZ;
    unit->m_movementInfo.t_pos.m_orientation = 0;
    unit->m_movementInfo.t_time = 0; // 1 for player
    unit->m_movementInfo.t_seat = seat->first;

    if (_me->GetTypeId() == TYPEID_UNIT
        && unit->GetTypeId() == TYPEID_PLAYER
        && seat->first == 0 && seat->second.SeatInfo->m_flags & VEHICLE_SEAT_FLAG_CAN_CONTROL)
    {
        if (!_me->SetCharmedBy(unit, CHARM_TYPE_VEHICLE))
            ASSERT(false);
    }

    if (_me->IsInWorld())
    {
        unit->SendClearTarget();                                // SMSG_BREAK_TARGET
        unit->SetControlled(true, UNIT_STAT_ROOT);              // SMSG_FORCE_ROOT - In some cases we send SMSG_SPLINE_MOVE_ROOT here (for creatures)
                                                                // also adds MOVEMENTFLAG_ROOT
        unit->SendMonsterMoveTransport(_me);                     // SMSG_MONSTER_MOVE_TRANSPORT

        if (_me->GetTypeId() == TYPEID_UNIT)
        {
            if (_me->ToCreature()->IsAIEnabled)
                _me->ToCreature()->AI()->PassengerBoarded(unit, seat->first, true);

            // update all passenger's positions
            RelocatePassengers(_me->GetPositionX(), _me->GetPositionY(), _me->GetPositionZ(), _me->GetOrientation());
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
    ASSERT(seat != Seats.end());

    sLog->outDebug(LOG_FILTER_VEHICLES, "Unit %s exit vehicle entry %u id %u dbguid %u seat %d", unit->GetName(), _me->GetEntry(), _vehicleInfo->m_ID, _me->GetGUIDLow(), (int32)seat->first);

    seat->second.Passenger = 0;
    if (seat->second.SeatInfo->CanEnterOrExit())
    {
        if (!_usableSeatNum)
        {
            if (_me->GetTypeId() == TYPEID_PLAYER)
                _me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_PLAYER_VEHICLE);
            else
                _me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
        }
        ++_usableSeatNum;
    }

    unit->ClearUnitState(UNIT_STAT_ONVEHICLE);

    if (_me->GetTypeId() == TYPEID_UNIT && unit->GetTypeId() == TYPEID_PLAYER && seat->first == 0 && seat->second.SeatInfo->m_flags & VEHICLE_SEAT_FLAG_CAN_CONTROL)
        _me->RemoveCharmedBy(unit);

    if (_me->IsInWorld())
    {
        unit->RemoveUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT);
        unit->m_movementInfo.t_pos.Relocate(0, 0, 0, 0);
        unit->m_movementInfo.t_time = 0;
        unit->m_movementInfo.t_seat = 0;
    }

    if (_me->GetTypeId() == TYPEID_UNIT && _me->ToCreature()->IsAIEnabled)
        _me->ToCreature()->AI()->PassengerBoarded(unit, seat->first, false);

    // only for flyable vehicles
    if (unit->HasUnitMovementFlag(MOVEMENTFLAG_FLYING))
        _me->CastSpell(unit, VEHICLE_SPELL_PARACHUTE, true);

    if (GetBase()->GetTypeId() == TYPEID_UNIT)
        sScriptMgr->OnRemovePassenger(this, unit);
}

void Vehicle::RelocatePassengers(float x, float y, float z, float ang)
{
    Map* map = _me->GetMap();
    ASSERT(map != NULL);

    // not sure that absolute position calculation is correct, it must depend on vehicle orientation and pitch angle
    for (SeatMap::const_iterator itr = Seats.begin(); itr != Seats.end(); ++itr)
        if (Unit* passenger = ObjectAccessor::GetUnit(*GetBase(), itr->second.Passenger))
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
    sLog->outDebug(LOG_FILTER_VEHICLES, "Vehicle::Dismiss Entry: %u, GuidLow %u", _creatureEntry, _me->GetGUIDLow());
    Uninstall();
    _me->DestroyForNearbyPlayers();
    _me->CombatStop();
    _me->AddObjectToRemoveList();
}

void Vehicle::InitMovementInfoForBase()
{
    uint32 vehicleFlags = GetVehicleInfo()->m_flags;

    if (vehicleFlags & VEHICLE_FLAG_NO_STRAFE)
        _me->AddExtraUnitMovementFlag(MOVEMENTFLAG2_NO_STRAFE);
    if (vehicleFlags & VEHICLE_FLAG_NO_JUMPING)
        _me->AddExtraUnitMovementFlag(MOVEMENTFLAG2_NO_JUMPING);
    if (vehicleFlags & VEHICLE_FLAG_FULLSPEEDTURNING)
        _me->AddExtraUnitMovementFlag(MOVEMENTFLAG2_FULL_SPEED_TURNING);
    if (vehicleFlags & VEHICLE_FLAG_ALLOW_PITCHING)
        _me->AddExtraUnitMovementFlag(MOVEMENTFLAG2_ALWAYS_ALLOW_PITCHING);
    if (vehicleFlags & VEHICLE_FLAG_FULLSPEEDPITCHING)
        _me->AddExtraUnitMovementFlag(MOVEMENTFLAG2_FULL_SPEED_PITCHING);
}

VehicleSeatEntry const* Vehicle::GetSeatForPassenger(Unit* passenger)
{
    SeatMap::iterator itr;
    for (itr = Seats.begin(); itr != Seats.end(); ++itr)
        if (itr->second.Passenger == passenger->GetGUID())
            return itr->second.SeatInfo;

    return NULL;
}

SeatMap::iterator Vehicle::GetSeatIteratorForPassenger(Unit* passenger)
{
    SeatMap::iterator itr;
    for (itr = Seats.begin(); itr != Seats.end(); ++itr)
        if (itr->second.Passenger == passenger->GetGUID())
            return itr;

    return Seats.end();
}

uint8 Vehicle::GetAvailableSeatCount() const
{
    uint8 ret = 0;
    SeatMap::const_iterator itr;
    for (itr = Seats.begin(); itr != Seats.end(); ++itr)
        if (!itr->second.Passenger && (itr->second.SeatInfo->CanEnterOrExit() || itr->second.SeatInfo->IsUsableByOverride()))
            ++ret;

    return ret;
}
