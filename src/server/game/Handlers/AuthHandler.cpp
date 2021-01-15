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
#include "AuthenticationPackets.h"
#include "BattlenetRpcErrorCodes.h"
#include "CharacterTemplateDataStore.h"
#include "ClientConfigPackets.h"
#include "GameTime.h"
#include "ObjectMgr.h"
#include "RBAC.h"
#include "Realm.h"
#include "SystemPackets.h"
#include "World.h"

void WorldSession::SendAuthResponse(uint32 code, bool queued, uint32 queuePos)
{
    WorldPackets::Auth::AuthResponse response;
    response.Result = code;

    if (code == ERROR_OK)
    {
        response.SuccessInfo = boost::in_place();

        response.SuccessInfo->ActiveExpansionLevel = GetExpansion();
        response.SuccessInfo->AccountExpansionLevel = GetAccountExpansion();
        response.SuccessInfo->VirtualRealmAddress = realm.Id.GetAddress();
        response.SuccessInfo->Time = int32(GameTime::GetGameTime());

        // Send current home realm. Also there is no need to send it later in realm queries.
        response.SuccessInfo->VirtualRealms.emplace_back(realm.Id.GetAddress(), true, false, realm.Name, realm.NormalizedName);

        if (HasPermission(rbac::RBAC_PERM_USE_CHARACTER_TEMPLATES))
            for (auto&& templ : sCharacterTemplateDataStore->GetCharacterTemplates())
                response.SuccessInfo->Templates.push_back(&templ.second);

        response.SuccessInfo->AvailableClasses = &sObjectMgr->GetClassExpansionRequirements();
    }

    if (queued)
    {
        response.WaitInfo = boost::in_place();
        response.WaitInfo->WaitCount = queuePos;
    }

    SendPacket(response.Write());
}

void WorldSession::SendAuthWaitQue(uint32 position)
{
    if (position)
    {
        WorldPackets::Auth::WaitQueueUpdate waitQueueUpdate;
        waitQueueUpdate.WaitInfo.WaitCount = position;
        waitQueueUpdate.WaitInfo.WaitTime = 0;
        waitQueueUpdate.WaitInfo.HasFCM = false;
        SendPacket(waitQueueUpdate.Write());
    }
    else
        SendPacket(WorldPackets::Auth::WaitQueueFinish().Write());
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
    features.MaxCharactersPerRealm = sWorld->getIntConfig(CONFIG_CHARACTERS_PER_REALM);
    features.MinimumExpansionLevel = EXPANSION_CLASSIC;
    features.MaximumExpansionLevel = sWorld->getIntConfig(CONFIG_EXPANSION);

    features.EuropaTicketSystemStatus.emplace();
    features.EuropaTicketSystemStatus->ThrottleState.MaxTries = 10;
    features.EuropaTicketSystemStatus->ThrottleState.PerMilliseconds = 60000;
    features.EuropaTicketSystemStatus->ThrottleState.TryCount = 1;
    features.EuropaTicketSystemStatus->ThrottleState.LastResetTimeBeforeNow = 111111;
    features.EuropaTicketSystemStatus->TicketsEnabled = sWorld->getBoolConfig(CONFIG_SUPPORT_TICKETS_ENABLED);
    features.EuropaTicketSystemStatus->BugsEnabled = sWorld->getBoolConfig(CONFIG_SUPPORT_BUGS_ENABLED);
    features.EuropaTicketSystemStatus->ComplaintsEnabled = sWorld->getBoolConfig(CONFIG_SUPPORT_COMPLAINTS_ENABLED);
    features.EuropaTicketSystemStatus->SuggestionsEnabled = sWorld->getBoolConfig(CONFIG_SUPPORT_SUGGESTIONS_ENABLED);

    SendPacket(features.Write());
}
