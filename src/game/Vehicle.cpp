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

Vehicle::Vehicle() : Creature(), m_vehicleId(0)
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
    }
}

void Vehicle::RemoveFromWorld()
{
    if(IsInWorld())
    {
        ///- Don't call the function for Creature, normal mobs + totems go in a different storage
        Unit::RemoveFromWorld();
        ObjectAccessor::Instance().RemoveObject(this);
    }
}

void Vehicle::setDeathState(DeathState s)                       // overwrite virtual Creature::setDeathState and Unit::setDeathState
{
    if(Unit *charmer = GetCharmer())
        if(charmer->GetTypeId() == TYPEID_PLAYER)
            ((Player*)charmer)->ExitVehicle(this);
    Creature::setDeathState(s);
}

void Vehicle::Update(uint32 diff)
{
    Creature::Update(diff);
}

bool Vehicle::Create(uint32 guidlow, Map *map, uint32 phaseMask, uint32 Entry, uint32 vehicleId, uint32 team)
{
    SetMapId(map->GetId());
    SetInstanceId(map->GetInstanceId());

    Object::_Create(guidlow, Entry, HIGHGUID_VEHICLE);

    if(!InitEntry(Entry, team))
        return false;

    m_defaultMovementType = IDLE_MOTION_TYPE;

    SetVehicleId(vehicleId);

    SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
    SetFloatValue(UNIT_FIELD_HOVERHEIGHT, 1.0f);

    CreatureInfo const *ci = GetCreatureInfo();
    setFaction(team == ALLIANCE ? ci->faction_A : ci->faction_H);
    SetMaxHealth(ci->maxhealth);
    SelectLevel(ci);
    SetHealth(GetMaxHealth());

    return true;
}

void Vehicle::Dismiss()
{
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
    if(!Create(guid,map,data->phaseMask,data->id,id,team))
        return false;

    Relocate(data->posX,data->posY,data->posZ,data->orientation);

    if(!IsPositionValid())
    {
        sLog.outError("Creature (guidlow %d, entry %d) not loaded. Suggested coordinates isn't valid (X: %f Y: %f)",GetGUIDLow(),GetEntry(),GetPositionX(),GetPositionY());
        return false;
    }
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
