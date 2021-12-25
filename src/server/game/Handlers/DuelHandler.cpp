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

#include "Common.h"
#include "DuelPackets.h"
#include "GameTime.h"
#include "WorldSession.h"
#include "Log.h"
#include "Player.h"
#include "ObjectAccessor.h"

#define SPELL_DUEL  7266
#define SPELL_MOUNTED_DUEL  62875

void WorldSession::HandleCanDuel(WorldPackets::Duel::CanDuel& packet)
{
    Player* player = ObjectAccessor::FindPlayer(packet.TargetGUID);

    if (!player)
        return;

    WorldPackets::Duel::CanDuelResult response;
    response.TargetGUID = packet.TargetGUID;
    response.Result = !player->duel;
    SendPacket(response.Write());

    if (response.Result)
    {
        if (_player->IsMounted())
            _player->CastSpell(player, SPELL_MOUNTED_DUEL);
        else
            _player->CastSpell(player, SPELL_DUEL);
    }
}

void WorldSession::HandleDuelResponseOpcode(WorldPackets::Duel::DuelResponse& duelResponse)
{
    if (duelResponse.Accepted && !duelResponse.Forfeited)
        HandleDuelAccepted(duelResponse.ArbiterGUID);
    else
        HandleDuelCancelled();
}

void WorldSession::HandleDuelAccepted(ObjectGuid arbiterGuid)
{
    Player* player = GetPlayer();
    if (!player->duel || player == player->duel->Initiator || player->duel->State != DUEL_STATE_CHALLENGED)
        return;

    Player* target = player->duel->Opponent;
    if (*target->m_playerData->DuelArbiter != arbiterGuid)
        return;

    TC_LOG_DEBUG("network", "Player 1 is: %s (%s)", player->GetGUID().ToString().c_str(), player->GetName().c_str());
    TC_LOG_DEBUG("network", "Player 2 is: %s (%s)", target->GetGUID().ToString().c_str(), target->GetName().c_str());

    time_t now = GameTime::GetGameTime();
    player->duel->StartTime = now + 3;
    target->duel->StartTime = now + 3;

    WorldPackets::Duel::DuelCountdown packet(3000); // milliseconds
    WorldPacket const* worldPacket = packet.Write();
    player->GetSession()->SendPacket(worldPacket);
    target->GetSession()->SendPacket(worldPacket);
    player->EnablePvpRules();
    target->EnablePvpRules();
}

void WorldSession::HandleDuelCancelled()
{
    Player* player = GetPlayer();

    // no duel requested
    if (!player->duel || player->duel->State == DUEL_STATE_COMPLETED)
        return;

    // player surrendered in a duel using /forfeit
    if (GetPlayer()->duel->State == DUEL_STATE_IN_PROGRESS)
    {
        GetPlayer()->CombatStopWithPets(true);
        GetPlayer()->duel->Opponent->CombatStopWithPets(true);

        GetPlayer()->CastSpell(GetPlayer(), 7267, true);    // beg
        GetPlayer()->DuelComplete(DUEL_WON);
        return;
    }

    GetPlayer()->DuelComplete(DUEL_INTERRUPTED);
}
