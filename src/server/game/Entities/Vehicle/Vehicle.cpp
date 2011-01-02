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

Vehicle::Vehicle(Unit *unit, VehicleEntry const *vehInfo) : me(unit), m_vehicleInfo(vehInfo), m_usableSeatNum(0), m_bonusHP(0)
{
    for (uint32 i = 0; i < MAX_VEHICLE_SEATS; ++i)
    {
        if (uint32 seatId = m_vehicleInfo->m_seatID[i])
            if (VehicleSeatEntry const *veSeat = sVehicleSeatStore.LookupEntry(seatId))
            {
                m_Seats.insert(std::make_pair(i, VehicleSeat(veSeat)));
                if (veSeat->CanEnterOrExit())
                    ++m_usableSeatNum;
            }
    }

    // HACKY WAY, We must found a more generic way to handle this
    // Set inmunities since db ones are rewritten with player's ones
    switch (GetVehicleInfo()->m_ID)
    {
        case 160:
            me->SetControlled(true, UNIT_STAT_ROOT);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK_DEST, true);
        case 158:
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_HEAL, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_FEAR, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_PERIODIC_HEAL, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_STUN, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_ROOT, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_DECREASE_SPEED, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
            me->ApplySpellImmune(0, IMMUNITY_ID, 49560, true); // Death Grip jump effect
            break;
        default:
            break;
    }
}

Vehicle::~Vehicle()
{
    for (SeatMap::const_iterator itr = m_Seats.begin(); itr != m_Seats.end(); ++itr)
        ASSERT(!itr->second.passenger);
}

void Vehicle::Install()
{
    if (Creature *pCreature = me->ToCreature())
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
                    if (!pCreature->m_spells[i])
                        continue;

                    SpellEntry const *spellInfo = sSpellStore.LookupEntry(pCreature->m_spells[i]);
                    if (!spellInfo)
                        continue;

                    if (spellInfo->powerType == POWER_MANA)
                        break;

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

    Reset();

    if (GetBase()->GetTypeId() == TYPEID_UNIT)
        sScriptMgr->OnInstall(this);
}

void Vehicle::InstallAllAccessories(uint32 entry)
{
    VehicleAccessoryList const* mVehicleList = sObjectMgr->GetVehicleAccessoryList(entry);
    if (!mVehicleList)
        return;

    for (VehicleAccessoryList::const_iterator itr = mVehicleList->begin(); itr != mVehicleList->end(); ++itr)
        InstallAccessory(itr->uiAccessory, itr->uiSeat, itr->bMinion);
}

void Vehicle::Uninstall()
{
    sLog->outDebug("Vehicle::Uninstall %u", me->GetEntry());
    for (SeatMap::iterator itr = m_Seats.begin(); itr != m_Seats.end(); ++itr)
        if (Unit *passenger = ObjectAccessor::GetUnit(*GetBase(), itr->second.passenger))
            if (passenger->HasUnitTypeMask(UNIT_MASK_ACCESSORY))
                passenger->ToTempSummon()->UnSummon();

    RemoveAllPassengers();

    if (GetBase()->GetTypeId() == TYPEID_UNIT)
        sScriptMgr->OnUninstall(this);
}

void Vehicle::Die()
{
    sLog->outDebug("Vehicle::Die %u", me->GetEntry());
    for (SeatMap::iterator itr = m_Seats.begin(); itr != m_Seats.end(); ++itr)
        if (Unit *passenger = ObjectAccessor::GetUnit(*GetBase(), itr->second.passenger))
            if (passenger->HasUnitTypeMask(UNIT_MASK_ACCESSORY))
                passenger->setDeathState(JUST_DIED);

    RemoveAllPassengers();

    if (GetBase()->GetTypeId() == TYPEID_UNIT)
        sScriptMgr->OnDie(this);
}

void Vehicle::Reset()
{
    sLog->outDebug("Vehicle::Reset");
    if (me->GetTypeId() == TYPEID_PLAYER)
    {
        if (m_usableSeatNum)
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_PLAYER_VEHICLE);
    }
    else
    {
        InstallAllAccessories(me->GetEntry());
        if (m_usableSeatNum)
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
    }

    if (GetBase()->GetTypeId() == TYPEID_UNIT)
        sScriptMgr->OnReset(this);
}

void Vehicle::RemoveAllPassengers()
{
    sLog->outDebug("Vehicle::RemoveAllPassengers");
    for (SeatMap::iterator itr = m_Seats.begin(); itr != m_Seats.end(); ++itr)
        if (Unit *passenger = ObjectAccessor::GetUnit(*GetBase(), itr->second.passenger))
        {
            ASSERT(passenger->IsInWorld());
            ASSERT(passenger->IsOnVehicle(GetBase()));
            ASSERT(GetSeatForPassenger(passenger));

            if (passenger->IsVehicle())
                passenger->GetVehicleKit()->RemoveAllPassengers();

            if (passenger->GetVehicle() != this)
                sLog->outCrash("Vehicle %u has invalid passenger %u. Seat: %i", me->GetEntry(), passenger->GetEntry(), itr->first);

            passenger->ExitVehicle();
            if (itr->second.passenger)
            {
                sLog->outCrash("Vehicle %u cannot remove passenger %u. "UI64FMTD" is still on vehicle.", me->GetEntry(), passenger->GetEntry(), itr->second.passenger);
                itr->second.passenger = 0;
            }

            // creature passengers mounted on player mounts should be despawned at dismount
            if (GetBase()->GetTypeId() == TYPEID_PLAYER && passenger->ToCreature())
                passenger->ToCreature()->DespawnOrUnsummon();
        }
}

bool Vehicle::HasEmptySeat(int8 seatId) const
{
    SeatMap::const_iterator seat = m_Seats.find(seatId);
    if (seat == m_Seats.end())
        return false;
    return !seat->second.passenger;
}

Unit *Vehicle::GetPassenger(int8 seatId) const
{
    SeatMap::const_iterator seat = m_Seats.find(seatId);
    if (seat == m_Seats.end())
        return NULL;

    return ObjectAccessor::GetUnit(*GetBase(), seat->second.passenger);
}

int8 Vehicle::GetNextEmptySeat(int8 seatId, bool next, bool byAura) const
{
    SeatMap::const_iterator seat = m_Seats.find(seatId);
    if (seat == m_Seats.end())
        return -1;

    while (seat->second.passenger || (!byAura && !seat->second.seatInfo->CanEnterOrExit()) || (byAura && !seat->second.seatInfo->IsUsableByAura()))
    {
        sLog->outDebug("Vehicle::GetNextEmptySeat: m_flags: %u, m_flagsB:%u", seat->second.seatInfo->m_flags, seat->second.seatInfo->m_flagsB);
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

void Vehicle::InstallAccessory(uint32 entry, int8 seatId, bool minion)
{
    if (Unit *passenger = GetPassenger(seatId))
    {
        // already installed
        if (passenger->GetEntry() == entry)
        {
            ASSERT(passenger->GetTypeId() == TYPEID_UNIT);
            if (me->GetTypeId() == TYPEID_UNIT && me->ToCreature()->IsInEvadeMode() && passenger->ToCreature()->IsAIEnabled)
                passenger->ToCreature()->AI()->EnterEvadeMode();
            return;
        }
        passenger->ExitVehicle(); // this should not happen
    }

    if (Creature *accessory = me->SummonCreature(entry, *me, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000))
    {
        if (minion)
            accessory->AddUnitTypeMask(UNIT_MASK_ACCESSORY);

        accessory->EnterVehicle(this, seatId);
        // This is not good, we have to send update twice
        accessory->SendMovementFlagUpdate();

        if (GetBase()->GetTypeId() == TYPEID_UNIT)
            sScriptMgr->OnInstallAccessory(this, accessory);
    }
}

bool Vehicle::AddPassenger(Unit *unit, int8 seatId, bool byAura)
{
    if (unit->GetVehicle() != this)
        return false;

    SeatMap::iterator seat;
    if (seatId < 0) // no specific seat requirement
    {
        for (seat = m_Seats.begin(); seat != m_Seats.end(); ++seat)
            if (!seat->second.passenger && (!byAura && seat->second.seatInfo->CanEnterOrExit()) || (byAura && seat->second.seatInfo->IsUsableByAura()))
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
            if (Unit* passenger = ObjectAccessor::GetUnit(*GetBase(), seat->second.passenger))
                passenger->ExitVehicle();
            else
                seat->second.passenger = 0;

        ASSERT(!seat->second.passenger);
    }

    sLog->outDebug("Unit %s enter vehicle entry %u id %u dbguid %u seat %d", unit->GetName(), me->GetEntry(), m_vehicleInfo->m_ID, me->GetGUIDLow(), (int32)seat->first);

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

    unit->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT | MOVEMENTFLAG_ROOT);
    VehicleSeatEntry const *veSeat = seat->second.seatInfo;
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

        if (VehicleScalingInfo const *scalingInfo = sObjectMgr->GetVehicleScalingInfo(m_vehicleInfo->m_ID))
        {
            Player *plr = unit->ToPlayer();
            float averageItemLevel = plr->GetAverageItemLevel();
            if (averageItemLevel < scalingInfo->baseItemLevel)
                averageItemLevel = scalingInfo->baseItemLevel;
            averageItemLevel -= scalingInfo->baseItemLevel;

            m_bonusHP = uint32(me->GetMaxHealth() * (averageItemLevel * scalingInfo->scalingFactor));
            me->SetMaxHealth(me->GetMaxHealth() + m_bonusHP);
            me->SetHealth(me->GetHealth() + m_bonusHP);
        }
    }

    if (me->IsInWorld())
    {
        unit->SendMonsterMoveTransport(me);

        if (me->GetTypeId() == TYPEID_UNIT)
        {
            if (me->ToCreature()->IsAIEnabled)
                me->ToCreature()->AI()->PassengerBoarded(unit, seat->first, true);

            // update all passenger's positions
            RelocatePassengers(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
        }
    }
    unit->DestroyForNearbyPlayers();
    unit->UpdateObjectVisibility(false);

    if (GetBase()->GetTypeId() == TYPEID_UNIT)
        sScriptMgr->OnAddPassenger(this, unit, seatId);

    return true;
}

void Vehicle::RemovePassenger(Unit *unit)
{
    if (unit->GetVehicle() != this)
        return;

    SeatMap::iterator seat = GetSeatIteratorForPassenger(unit);
    ASSERT(seat != m_Seats.end());

    sLog->outDebug("Unit %s exit vehicle entry %u id %u dbguid %u seat %d", unit->GetName(), me->GetEntry(), m_vehicleInfo->m_ID, me->GetGUIDLow(), (int32)seat->first);

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

    if (me->GetTypeId() == TYPEID_UNIT
        && unit->GetTypeId() == TYPEID_PLAYER
        && seat->first == 0 && seat->second.seatInfo->m_flags & VEHICLE_SEAT_FLAG_CAN_CONTROL)
    {
        me->RemoveCharmedBy(unit);

        if (m_bonusHP)
        {
            me->SetHealth(me->GetHealth() - m_bonusHP);
            me->SetMaxHealth(me->GetMaxHealth() - m_bonusHP);
            m_bonusHP = 0;
        }
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
    Map *map = me->GetMap();
    ASSERT(map != NULL);

    // not sure that absolute position calculation is correct, it must depend on vehicle orientation and pitch angle
    for (SeatMap::const_iterator itr = m_Seats.begin(); itr != m_Seats.end(); ++itr)
        if (Unit *passenger = ObjectAccessor::GetUnit(*GetBase(), itr->second.passenger))
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
    sLog->outDebug("Vehicle::Dismiss %u", me->GetEntry());
    Uninstall();
    me->SendObjectDeSpawnAnim(me->GetGUID());
    me->CombatStop();
    me->AddObjectToRemoveList();
}

uint16 Vehicle::GetExtraMovementFlagsForBase() const
{
    uint16 movementMask = MOVEMENTFLAG2_NONE;
    uint32 vehicleFlags = GetVehicleInfo()->m_flags;

    if (vehicleFlags & VEHICLE_FLAG_NO_STRAFE)
        movementMask |= MOVEMENTFLAG2_NO_STRAFE;
    if (vehicleFlags & VEHICLE_FLAG_NO_JUMPING)
        movementMask |= MOVEMENTFLAG2_NO_JUMPING;
    if (vehicleFlags & VEHICLE_FLAG_FULLSPEEDTURNING)
        movementMask |= MOVEMENTFLAG2_FULL_SPEED_TURNING;
    if (vehicleFlags & VEHICLE_FLAG_ALLOW_PITCHING)
        movementMask |= MOVEMENTFLAG2_ALWAYS_ALLOW_PITCHING;
    if (vehicleFlags & VEHICLE_FLAG_FULLSPEEDPITCHING)
        movementMask |= MOVEMENTFLAG2_FULL_SPEED_PITCHING;

    sLog->outDebug("Vehicle::GetExtraMovementFlagsForBase() returned %u", movementMask);
    return movementMask;
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