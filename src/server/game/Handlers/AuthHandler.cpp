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

#include "ObjectMgr.h"
#include "Opcodes.h"
#include "WorldSession.h"
#include "WorldPacket.h"

void WorldSession::SendAuthResponse(uint8 code, bool queued, uint32 queuePos)
{
    ExpansionRequirementContainer const& raceExpansions =  sObjectMgr->GetRaceExpansionRequirements();
    ExpansionRequirementContainer const& classExpansions =  sObjectMgr->GetClassExpansionRequirements();

    std::list<uint32> realmsToSend;
    // Send current home realm. Also there is no need to send it later in realm queries.
    realmsToSend.push_back(realmHandle.Index);

    WorldPacket packet(SMSG_AUTH_RESPONSE, 1 /*bits*/ + 4 + 1 + 4 + 1 + 4 + 1 + 1 + (queued ? 4 : 0));
    packet << uint8(code);
    packet.WriteBit(code == AUTH_OK);
    packet.WriteBit(queued);

    if (code == AUTH_OK)
    {
        packet << uint32(realmHandle.Index);
        packet << uint32(realmsToSend.size());      // RealmNamesCount
        packet << uint32(0);                        // BillingTimeRemaining
        packet << uint32(0);                        // BillingPlanFlags
        packet << uint32(0);                        // BillingTimeRested
        packet << uint8(Expansion());               // ActiveExpansion
        packet << uint8(Expansion());               // AccountExpansion
        packet << uint32(0);                        // TimeSecondsUntilPCKick
        packet << uint32(raceExpansions.size());    // Races
        packet << uint32(classExpansions.size());   // Classes
        packet << uint32(0);                        // Templates
        packet << uint32(0);                        // AccountCurrency (probably for ingame shop)

        for (auto realm : realmsToSend)
        {
            std::string realmName = sObjectMgr->GetRealmName(realm);

            packet << uint32(realm);                    // realmID
            packet.WriteBit(realm == realmHandle.Index);// IsHomeRealm
            packet.WriteBit(0);                         // IsInternalRealm = guessed
            packet.WriteBits(realmName.length(), 8);
            packet.WriteBits(realmName.length(), 8);
            packet.WriteString(realmName);              // RealmNameActual
            packet.WriteString(realmName);              // RealmNameNormalized
        }

        for (auto raceExpansion : raceExpansions)
        {
            packet << uint8(raceExpansion.first);       // Race
            packet << uint8(raceExpansion.second);      // RequiredExpansion
        }

        for (auto classExpansion : classExpansions)
        {
            packet << uint8(classExpansion.first);      // Class
            packet << uint8(classExpansion.second);     // RequiredExpansion
        }

        packet.WriteBit(0);                         // Trial
        packet.WriteBit(0);                         // ForceCharacterTemplate
        packet.WriteBit(0);                         // NumPlayersHorde (uint16)
        packet.WriteBit(0);                         // NumPlayersAlliance (uint16)
        packet.WriteBit(0);                         // IsVeteranTrial
    }

    if (queued)
    {
        packet << uint32(queuePos);                 // Queue position
        packet.WriteBit(0);                         // HasFCM
    }

    packet.FlushBits();
    SendPacket(&packet);
}

void WorldSession::SendClientCacheVersion(uint32 version)
{
    WorldPacket data(SMSG_CLIENTCACHE_VERSION, 4);
    data << uint32(version);
    SendPacket(&data);
}
