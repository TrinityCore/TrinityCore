/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "Common.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "Vehicle.h"
#include "Unit.h"
#include "Util.h"
#include "WorldPacket.h"

#include "CreatureAI.h"
#include "ZoneScript.h"

Vehicle::Vehicle(Unit *unit, VehicleEntry const *vehInfo) : me(unit), m_vehicleInfo(vehInfo), m_usableSeatNum(0)
{
    for(uint32 i = 0; i < 8; ++i)
    {
        if(uint32 seatId = m_vehicleInfo->m_seatID[i])
            if(VehicleSeatEntry const *veSeat = sVehicleSeatStore.LookupEntry(seatId))
            {
                m_Seats.insert(std::make_pair(i, VehicleSeat(veSeat)));
                if(veSeat->IsUsable())
                    ++m_usableSeatNum;
            }                    
    }
    assert(!m_Seats.empty());
}

Vehicle::~Vehicle()
{
    for(SeatMap::const_iterator itr = m_Seats.begin(); itr != m_Seats.end(); ++itr)
        assert(!itr->second.passenger);
}

void Vehicle::Install()
{
    if(Creature *cre = dynamic_cast<Creature*>(me))
    {
        for(uint32 i = 0; i < MAX_SPELL_VEHICLE; ++i)
        {
            if(!cre->m_spells[i])
                continue;

            SpellEntry const *spellInfo = sSpellStore.LookupEntry(cre->m_spells[i]);
            if(!spellInfo)
                continue;

            if(spellInfo->powerType == POWER_MANA)
                break;

            if(spellInfo->powerType == POWER_ENERGY)
            {
                me->setPowerType(POWER_ENERGY);
                me->SetMaxPower(POWER_ENERGY, 100);
                break;
            }
        }
    }

    Reset();
}

void Vehicle::InstallAllAccessories()
{
    switch(me->GetEntry())
    {
        //case 27850:InstallAccessory(27905,1);break;
        case 28782:InstallAccessory(28768,0,false);break; // Acherus Deathcharger
        case 28312:InstallAccessory(28319,7);break;
        case 32627:InstallAccessory(32629,7);break;
        case 32930:
            InstallAccessory(32933,2);
            InstallAccessory(32934,1);
            break;
        case 33109:InstallAccessory(33167,1);break;
        case 33060:InstallAccessory(33067,7);break;
        case 33113:
            InstallAccessory(33114,0);
            InstallAccessory(33114,1);
            InstallAccessory(33114,2);
            InstallAccessory(33114,3);
            InstallAccessory(33139,7);
            break;
        case 33114:
            InstallAccessory(33143,2); // Overload Control Device
            InstallAccessory(33142,1); // Leviathan Defense Turret
            break;
        case 33214:InstallAccessory(33218,1,false);break; // Mechanolift 304-A
    }
}

void Vehicle::Uninstall()
{
    sLog.outDebug("Vehicle::Uninstall %u", me->GetEntry());
    for(SeatMap::iterator itr = m_Seats.begin(); itr != m_Seats.end(); ++itr)
        if(Unit *passenger = itr->second.passenger)
            if(passenger->HasUnitTypeMask(UNIT_MASK_ACCESSORY))
                ((TempSummon*)passenger)->UnSummon();
    RemoveAllPassengers();
}

void Vehicle::Die()
{
    sLog.outDebug("Vehicle::Die %u", me->GetEntry());
    for(SeatMap::iterator itr = m_Seats.begin(); itr != m_Seats.end(); ++itr)
        if(Unit *passenger = itr->second.passenger)
            if(passenger->HasUnitTypeMask(UNIT_MASK_ACCESSORY))
                passenger->setDeathState(JUST_DIED);
    RemoveAllPassengers();
}

void Vehicle::Reset()
{
    sLog.outDebug("Vehicle::Reset");
    InstallAllAccessories();
    if(m_usableSeatNum)
        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
}

void Vehicle::RemoveAllPassengers()
{
    sLog.outDebug("Vehicle::RemoveAllPassengers");
    for(SeatMap::iterator itr = m_Seats.begin(); itr != m_Seats.end(); ++itr)
        if(Unit *passenger = itr->second.passenger)
        {
            if(passenger->IsVehicle())
                passenger->GetVehicleKit()->RemoveAllPassengers();
            if(passenger->GetVehicle() != this)
                sLog.outCrash("Vehicle %u has invalid passenger %u.", me->GetEntry(), passenger->GetEntry());
            passenger->ExitVehicle();
            if(itr->second.passenger)
            {
                sLog.outCrash("Vehicle %u cannot remove passenger %u. %u is still on it.", me->GetEntry(), passenger->GetEntry(), itr->second.passenger->GetEntry());
                //assert(!itr->second.passenger);
                itr->second.passenger = NULL;
            }
        }
}

bool Vehicle::HasEmptySeat(int8 seatId) const
{
    SeatMap::const_iterator seat = m_Seats.find(seatId);
    if(seat == m_Seats.end()) return false;
    return !seat->second.passenger;
}

Unit *Vehicle::GetPassenger(int8 seatId) const
{
    SeatMap::const_iterator seat = m_Seats.find(seatId);
    if(seat == m_Seats.end()) return NULL;
    return seat->second.passenger;
}

int8 Vehicle::GetNextEmptySeat(int8 seatId, bool next) const
{
    SeatMap::const_iterator seat = m_Seats.find(seatId);
    if(seat == m_Seats.end()) return -1;
    while(seat->second.passenger || !seat->second.seatInfo->IsUsable())
    {
        if(next)
        {
            ++seat;
            if(seat == m_Seats.end())
                seat = m_Seats.begin();
        }
        else
        {
            if(seat == m_Seats.begin())
                seat = m_Seats.end();
            --seat;
        }
        if(seat->first == seatId)
            return -1; // no available seat
    }
    return seat->first;
}

void Vehicle::InstallAccessory(uint32 entry, int8 seatId, bool minion)
{
    if(Unit *passenger = GetPassenger(seatId))
    {
        // already installed
        if(passenger->GetEntry() == entry)
        {
            assert(passenger->GetTypeId() == TYPEID_UNIT);
            if(me->GetTypeId() == TYPEID_UNIT && ((Creature*)me)->IsInEvadeMode() && ((Creature*)passenger)->IsAIEnabled)
                ((Creature*)passenger)->AI()->EnterEvadeMode();
            return;
        }
        passenger->ExitVehicle(); // this should not happen
    }

    //TODO: accessory should be minion
    if(Creature *accessory = me->SummonCreature(entry, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000))
    {
        if(minion)
            accessory->AddUnitTypeMask(UNIT_MASK_ACCESSORY);
        accessory->EnterVehicle(this, seatId);
        // This is not good, we have to send update twice
        accessory->SendMovementFlagUpdate();
    }
}

bool Vehicle::AddPassenger(Unit *unit, int8 seatId)
{
    if(unit->GetVehicle() != this)
        return false;

    SeatMap::iterator seat;
    if(seatId < 0) // no specific seat requirement
    {
        for(seat = m_Seats.begin(); seat != m_Seats.end(); ++seat)
            if(!seat->second.passenger && seat->second.seatInfo->IsUsable())
                break;

        if(seat == m_Seats.end()) // no available seat
            return false;
    }
    else
    {
        seat = m_Seats.find(seatId);
        if(seat == m_Seats.end())
            return false;

        if(seat->second.passenger)
            seat->second.passenger->ExitVehicle();

        assert(!seat->second.passenger);
    }

    sLog.outDebug("Unit %s enter vehicle entry %u id %u dbguid %u seat %d", unit->GetName(), me->GetEntry(), m_vehicleInfo->m_ID, me->GetGUIDLow(), (int32)seat->first);

    seat->second.passenger = unit;
    if(seat->second.seatInfo->IsUsable())
    {
        assert(m_usableSeatNum);
        --m_usableSeatNum;
        if(!m_usableSeatNum)
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
    }

    if(!(seat->second.seatInfo->m_flags & 0x4000))
        unit->addUnitState(UNIT_STAT_ONVEHICLE);

    //SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNK_24);

    unit->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT);
    VehicleSeatEntry const *veSeat = seat->second.seatInfo;
    unit->m_movementInfo.t_x = veSeat->m_attachmentOffsetX;
    unit->m_movementInfo.t_y = veSeat->m_attachmentOffsetY;
    unit->m_movementInfo.t_z = veSeat->m_attachmentOffsetZ;
    unit->m_movementInfo.t_o = 0;
    unit->m_movementInfo.t_time = 0; // 1 for player
    unit->m_movementInfo.t_seat = seat->first;

    if(unit->GetTypeId() == TYPEID_PLAYER && seat->first == 0 && seat->second.seatInfo->m_flags & 0x800) // not right
        if (!me->SetCharmedBy(unit, CHARM_TYPE_VEHICLE))
            assert(false);

    if(me->GetTypeId() == TYPEID_UNIT)
    {
        if(me->IsInWorld())
        {
            unit->SendMonsterMoveTransport(me);
            // move self = move all passengers
            me->GetMap()->CreatureRelocation((Creature*)me, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
        }

        if(((Creature*)me)->IsAIEnabled)
            ((Creature*)me)->AI()->PassengerBoarded(unit, seat->first, true);
    }

    //if(unit->GetTypeId() == TYPEID_PLAYER)
    //    ((Player*)unit)->SendTeleportAckMsg();
    //unit->SendMovementFlagUpdate();

    return true;
}

void Vehicle::RemovePassenger(Unit *unit)
{
    if(unit->GetVehicle() != this)
        return;

    SeatMap::iterator seat;
    for(seat = m_Seats.begin(); seat != m_Seats.end(); ++seat)
        if(seat->second.passenger == unit)
            break;

    assert(seat != m_Seats.end());

    sLog.outDebug("Unit %s exit vehicle entry %u id %u dbguid %u seat %d", unit->GetName(), me->GetEntry(), m_vehicleInfo->m_ID, me->GetGUIDLow(), (int32)seat->first);

    seat->second.passenger = NULL;
    if(seat->second.seatInfo->IsUsable())
    {
        if(!m_usableSeatNum)
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
        ++m_usableSeatNum;
    }

    if(!(seat->second.seatInfo->m_flags & 0x4000))
        unit->clearUnitState(UNIT_STAT_ONVEHICLE);

    //SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);

    if(unit->GetTypeId() == TYPEID_PLAYER && seat->first == 0 && seat->second.seatInfo->m_flags & 0x800)
        me->RemoveCharmedBy(unit);

    if(me->GetTypeId() == TYPEID_UNIT && ((Creature*)me)->IsAIEnabled)
        ((Creature*)me)->AI()->PassengerBoarded(unit, seat->first, false);

    // only for flyable vehicles?
    //CastSpell(this, 45472, true);                           // Parachute
}

void Vehicle::Dismiss()
{
    sLog.outDebug("Vehicle::Dismiss %u", me->GetEntry());
    Uninstall();
    me->SendObjectDeSpawnAnim(me->GetGUID());
    me->CombatStop();
    me->AddObjectToRemoveList();
}
