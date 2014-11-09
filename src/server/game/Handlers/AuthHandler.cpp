/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "ObjectMgr.h"
#include "AuthenticationPackets.h"
#include "ClientConfigPackets.h"
#include "SystemPackets.h"

void WorldSession::SendAuthResponse(uint8 code, bool queued, uint32 queuePos)
{
    WorldPackets::Auth::AuthResponse response;
    response.SuccessInfo.HasValue = code == AUTH_OK;
    response.Result = code;
    response.WaitInfo.HasValue = queued;
    response.WaitInfo.value.WaitCount = queuePos;
    if (code == AUTH_OK)
    {
        response.SuccessInfo.value.AccountExpansionLevel = Expansion();
        response.SuccessInfo.value.ActiveExpansionLevel = Expansion();
        response.SuccessInfo.value.VirtualRealmAddress = GetVirtualRealmAddress();

        std::string realmName = sObjectMgr->GetRealmName(realmHandle.Index);

        // Send current home realm. Also there is no need to send it later in realm queries.
        response.SuccessInfo.value.VirtualRealms.emplace_back(GetVirtualRealmAddress(), true, false, realmName, realmName);

        response.SuccessInfo.value.AvailableClasses = &sObjectMgr->GetClassExpansionRequirements();
        response.SuccessInfo.value.AvailableRaces = &sObjectMgr->GetRaceExpansionRequirements();
    }

    SendPacket(response.Write());
}

void WorldSession::SendAuthWaitQue(uint32 position)
{
    WorldPackets::Auth::AuthResponse response;

    if (position == 0)
    {
        response.Result = AUTH_OK;
        response.SuccessInfo.HasValue = false;
        response.WaitInfo.HasValue = false;
    }
    else
    {
        response.WaitInfo.HasValue = true;
        response.SuccessInfo.HasValue = false;
        response.WaitInfo.value.WaitCount = position;
        response.Result = AUTH_WAIT_QUEUE;
    }

    SendPacket(response.Write());
}

void WorldSession::SendClientCacheVersion(uint32 version)
{
    WorldPackets::ClientConfig::ClientCacheVersion cache;
    cache.CacheVersion = version;

    SendPacket(cache.Write());
}

void WorldSession::SendSetTimeZoneInformation()
{
    /// @todo: replace dummy values
    WorldPackets::System::SetTimeZoneInformation packet;
    packet.ServerTimeTZ = "Europe/Paris";
    packet.GameTimeTZ = "Europe/Paris";

    SendPacket(packet.Write());
}

void WorldSession::SendFeatureSystemStatusGlueScreen()
{
    WorldPackets::System::FeatureSystemStatusGlueScreen features;
    features.BpayStoreAvailable = false;
    features.BpayStoreDisabledByParentalControls = false;
    features.CharUndeleteEnabled = sWorld->getBoolConfig(CONFIG_FEATURE_SYSTEM_CHARACTER_UNDELETE_ENABLED);
    features.BpayStoreEnabled = sWorld->getBoolConfig(CONFIG_FEATURE_SYSTEM_BPAY_STORE_ENABLED);

    SendPacket(features.Write());
}
