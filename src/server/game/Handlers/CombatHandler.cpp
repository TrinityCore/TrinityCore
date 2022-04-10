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

#include "WorldSession.h"
#include "Common.h"
#include "CreatureAI.h"
#include "CombatPackets.h"
#include "DBCStores.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "Vehicle.h"
#include "WorldPacket.h"

void WorldSession::HandleAttackSwingOpcode(WorldPackets::Combat::AttackSwing& attackSwing)
{
    Unit* victim = ObjectAccessor::GetUnit(*_player, attackSwing.Victim);

    if (!victim)
    {
        // stop attack state at client
        SendAttackStop(nullptr);
        return;
    }

    if (!_player->IsValidAttackTarget(victim))
    {
        // stop attack state at client
        SendAttackStop(victim);
        return;
    }

    //! Client explicitly checks the following before sending CMSG_ATTACKSWING packet,
    //! so we'll place the same check here. Note that it might be possible to reuse this snippet
    //! in other places as well.
    if (Vehicle* vehicle = _player->GetVehicle())
    {
        VehicleSeatEntry const* seat = vehicle->GetSeatForPassenger(_player);
        ASSERT(seat);
        if (!(seat->Flags & VEHICLE_SEAT_FLAG_CAN_ATTACK))
        {
            SendAttackStop(victim);
            return;
        }
    }

    _player->Attack(victim, true);
}

void WorldSession::HandleAttackStopOpcode(WorldPackets::Combat::CAttackStop& /*attackStop*/)
{
    GetPlayer()->AttackStop();
}

void WorldSession::HandleSetSheathedOpcode(WorldPackets::Combat::SetSheathed& setSheathed)
{
    if (setSheathed.CurrentSheathState >= MAX_SHEATH_STATE)
    {
        TC_LOG_ERROR("network", "Player %s tried to change his sheath state to an unknown value (%u)", _player->GetGUID().ToString().c_str(), setSheathed.CurrentSheathState);
        return;
    }

    GetPlayer()->SetSheath(SheathState(setSheathed.CurrentSheathState));
}

void WorldSession::SendAttackStop(Unit const* enemy)
{
    SendPacket(WorldPackets::Combat::SAttackStop(GetPlayer(), enemy).Write());
}
