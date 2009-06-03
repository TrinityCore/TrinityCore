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

#include "Chat.h"
#include "CreatureAI.h"

Vehicle::Vehicle() : Creature(), m_vehicleInfo(NULL), m_usableSeatNum(0)
{
    m_summonMask |= SUMMON_MASK_VEHICLE;
    m_updateFlag = (UPDATEFLAG_LOWGUID | UPDATEFLAG_HIGHGUID | UPDATEFLAG_LIVING | UPDATEFLAG_HAS_POSITION | UPDATEFLAG_VEHICLE);
}

Vehicle::~Vehicle()
{
}

void Vehicle::AddToWorld()
{
    if(!IsInWorld())
    {
        ObjectAccessor::Instance().AddObject(this);
        Unit::AddToWorld();
        AIM_Initialize();
        switch(GetEntry())
        {
            case 27850:InstallAccessory(27905,1);break;
            case 28312:InstallAccessory(28319,7);break;
            case 32627:InstallAccessory(32629,7);break;
        }
        //setPowerType(POWER_ENERGY);SetMaxPower(POWER_ENERGY, 100);
    }
}

void Vehicle::RemoveFromWorld()
{
    if(IsInWorld())
    {
        RemoveAllPassengers();
        ///- Don't call the function for Creature, normal mobs + totems go in a different storage
        Unit::RemoveFromWorld();
        ObjectAccessor::Instance().RemoveObject(this);
    }
}

void Vehicle::setDeathState(DeathState s)                       // overwrite virtual Creature::setDeathState and Unit::setDeathState
{
    if(s == JUST_DIED)
    {
        for(SeatMap::iterator itr = m_Seats.begin(); itr != m_Seats.end(); ++itr)
        {
            if(Unit *passenger = itr->second.passenger)
                if(passenger->GetTypeId() == TYPEID_UNIT && ((Creature*)passenger)->isVehicle())
                {
                    passenger->ExitVehicle();
                    ((Vehicle*)passenger)->setDeathState(s);
                }
        }
        RemoveAllPassengers();
    }
    Creature::setDeathState(s);
}

void Vehicle::Update(uint32 diff)
{
    Creature::Update(diff);
    //310
    //if(getPowerType() == POWER_ENERGY)
    //    ModifyPower(POWER_ENERGY, 1);
}

bool Vehicle::Create(uint32 guidlow, Map *map, uint32 phaseMask, uint32 Entry, uint32 vehicleId, uint32 team, float x, float y, float z, float o, const CreatureData * data)
{
    if(!Creature::Create(guidlow, map, phaseMask, Entry, team, x, y, z, o, data))
        return false;

    SetVehicleId(vehicleId);
    return true;
}

void Vehicle::RemoveAllPassengers()
{
    for(SeatMap::iterator itr = m_Seats.begin(); itr != m_Seats.end(); ++itr)
        if(Unit *passenger = itr->second.passenger)
        {
            if(passenger->GetTypeId() == TYPEID_UNIT && ((Creature*)passenger)->isVehicle())
                ((Vehicle*)passenger)->RemoveAllPassengers();
            passenger->ExitVehicle();
            assert(!itr->second.passenger);
        }
}

void Vehicle::SetVehicleId(uint32 id)
{
    if(m_vehicleInfo && id == m_vehicleInfo->m_ID)
        return;

    VehicleEntry const *ve = sVehicleStore.LookupEntry(id);
    if(!ve)
        return;

    m_vehicleInfo = ve;

    RemoveAllPassengers();
    m_Seats.clear();
    m_usableSeatNum = 0;

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
    if(m_usableSeatNum)
        SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
}

bool Vehicle::HasEmptySeat(int8 seatId) const
{
    SeatMap::const_iterator seat = m_Seats.find(seatId);
    if(seat == m_Seats.end()) return false;
    return !seat->second.passenger;
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

void Vehicle::InstallAccessory(uint32 entry, int8 seatId)
{
    //Creature *accessory = SummonCreature(entry, GetPositionX(), GetPositionY(), GetPositionZ());
    Creature *accessory = SummonVehicle(entry, GetPositionX(), GetPositionY(), GetPositionZ());
    if(!accessory)
        return;

    accessory->m_Vehicle = this;
    AddPassenger(accessory, seatId);
}

bool Vehicle::AddPassenger(Unit *unit, int8 seatId)
{
    if(unit->m_Vehicle != this)
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

    sLog.outDebug("Unit %s enter vehicle entry %u id %u dbguid %u", unit->GetName(), GetEntry(), m_vehicleInfo->m_ID, GetDBTableGUIDLow());

    seat->second.passenger = unit;
    if(seat->second.seatInfo->IsUsable())
    {
        assert(m_usableSeatNum);
        --m_usableSeatNum;
        if(!m_usableSeatNum)
            RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
    }

    //SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNK_24);

    unit->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT);
    VehicleSeatEntry const *veSeat = seat->second.seatInfo;
    unit->m_movementInfo.t_x = veSeat->m_attachmentOffsetX;
    unit->m_movementInfo.t_y = veSeat->m_attachmentOffsetY;
    unit->m_movementInfo.t_z = veSeat->m_attachmentOffsetZ;
    unit->m_movementInfo.t_o = 0;
    unit->m_movementInfo.t_time = 4;
    unit->m_movementInfo.t_seat = seat->first;

    unit->Relocate(GetPositionX() + unit->m_movementInfo.t_x,
        GetPositionY() + unit->m_movementInfo.t_y,
        GetPositionZ() + unit->m_movementInfo.t_z,
        GetOrientation());

    unit->GetMotionMaster()->MoveIdle(MOTION_SLOT_IDLE);

    WorldPacket data;
    if(unit->GetTypeId() == TYPEID_PLAYER)
    {
        //ChatHandler(player).PSendSysMessage("Enter seat %u %u", veSeat->m_ID, seat->first);

        if(seat->first == 0 && seat->second.seatInfo->IsUsable()) // not right
        {
            setFaction(unit->getFaction());
            AI()->OnCharmed(true);
            GetMotionMaster()->MoveIdle();
            ((Player*)unit)->SetCharm(this, true);
            ((Player*)unit)->SetViewpoint(this, true);
            ((Player*)unit)->VehicleSpellInitialize();
        }

        ((Player*)unit)->BuildTeleportAckMsg(&data, unit->GetPositionX(), unit->GetPositionY(), unit->GetPositionZ(), unit->GetOrientation());
        ((Player*)unit)->GetSession()->SendPacket(&data);
    }

    unit->BuildHeartBeatMsg(&data);
    unit->SendMessageToSet(&data, false);

    return true;
}

void Vehicle::RemovePassenger(Unit *unit)
{
    if(unit->m_Vehicle != this)
        return;

    SeatMap::iterator seat;
    for(seat = m_Seats.begin(); seat != m_Seats.end(); ++seat)
    {
        if(seat->second.passenger == unit)
        {
            seat->second.passenger = NULL;
            if(seat->second.seatInfo->IsUsable())
            {
                if(!m_usableSeatNum)
                    SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                ++m_usableSeatNum;
            }
            break;
        }
    }

    assert(seat != m_Seats.end());

    sLog.outDebug("Unit %s exit vehicle entry %u id %u dbguid %u", unit->GetName(), GetEntry(), m_vehicleInfo->m_ID, GetDBTableGUIDLow());

    //SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);

    if(unit->GetTypeId() == TYPEID_PLAYER && seat->first == 0 && seat->second.seatInfo->IsUsable())
    {
        RestoreFaction();
        AI()->OnCharmed(false);
        ((Player*)unit)->SetCharm(this, false);
        ((Player*)unit)->SetViewpoint(this, false);
        ((Player*)unit)->SendRemoveControlBar();
    }

    // only for flyable vehicles?
    //CastSpell(this, 45472, true);                           // Parachute
}

void Vehicle::Dismiss()
{
    for(SeatMap::iterator itr = m_Seats.begin(); itr != m_Seats.end(); ++itr)
    {
        if(Unit *passenger = itr->second.passenger)
            if(passenger->GetTypeId() == TYPEID_UNIT && ((Creature*)passenger)->isVehicle())
            {
                passenger->ExitVehicle();
                ((Vehicle*)passenger)->Dismiss();
            }
    }
    RemoveAllPassengers();
    SendObjectDeSpawnAnim(GetGUID());
    CombatStop();
    CleanupsBeforeDelete();
    AddObjectToRemoveList();
}

bool Vehicle::LoadFromDB(uint32 guid, Map *map)
{
    CreatureData const* data = objmgr.GetCreatureData(guid);

    if(!data)
    {
        sLog.outErrorDb("Creature (GUID: %u) not found in table `creature`, can't load. ",guid);
        return false;
    }

    uint32 id = 0;
    if(const CreatureInfo *cInfo = objmgr.GetCreatureTemplate(data->id))
        id = cInfo->VehicleId;
    if(!id || !sVehicleStore.LookupEntry(id))
        return false;

    m_DBTableGuid = guid;
    if (map->GetInstanceId() != 0) guid = objmgr.GenerateLowGuid(HIGHGUID_VEHICLE);

    uint16 team = 0;
    if(!Create(guid,map,data->phaseMask,data->id,id,team,data->posX,data->posY,data->posZ,data->orientation,data))
        return false;

    //We should set first home position, because then AI calls home movement
    SetHomePosition(data->posX,data->posY,data->posZ,data->orientation);

    m_respawnradius = data->spawndist;

    m_respawnDelay = data->spawntimesecs;
    m_isDeadByDefault = data->is_dead;
    m_deathState = m_isDeadByDefault ? DEAD : ALIVE;

    m_respawnTime  = objmgr.GetCreatureRespawnTime(m_DBTableGuid,GetInstanceId());
    if(m_respawnTime > time(NULL))                          // not ready to respawn
    {
        m_deathState = DEAD;
        if(canFly())
        {
            float tz = GetMap()->GetHeight(data->posX,data->posY,data->posZ,false);
            if(data->posZ - tz > 0.1)
                Relocate(data->posX,data->posY,tz);
        }
    }
    else if(m_respawnTime)                                  // respawn time set but expired
    {
        m_respawnTime = 0;
        objmgr.SaveCreatureRespawnTime(m_DBTableGuid,GetInstanceId(),0);
    }

    uint32 curhealth = data->curhealth;
    if(curhealth)
    {
        curhealth = uint32(curhealth*_GetHealthMod(GetCreatureInfo()->rank));
        if(curhealth < 1)
            curhealth = 1;
    }

    SetHealth(m_deathState == ALIVE ? curhealth : 0);
    SetPower(POWER_MANA,data->curmana);

    // checked at creature_template loading
    m_defaultMovementType = MovementGeneratorType(data->movementType);

    return true;
}
