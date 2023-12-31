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

#include "OutdoorPvP.h"
#include "CellImpl.h"
#include "ChatPackets.h"
#include "DatabaseEnv.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "Log.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "OutdoorPvPMgr.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "WorldStateMgr.h"

class DefenseMessageBuilder
{
    public:
        DefenseMessageBuilder(uint32 zoneId, uint32 id)
            : _zoneId(zoneId), _id(id) { }

        Trinity::PacketSenderOwning<WorldPackets::Chat::DefenseMessage>* operator()(LocaleConstant locale) const
        {
            std::string text = sOutdoorPvPMgr->GetDefenseMessage(_zoneId, _id, locale);

            Trinity::PacketSenderOwning<WorldPackets::Chat::DefenseMessage>* defenseMessage = new Trinity::PacketSenderOwning<WorldPackets::Chat::DefenseMessage>();
            defenseMessage->Data.ZoneID = _zoneId;
            defenseMessage->Data.MessageText = text;
            defenseMessage->Data.Write();
            return defenseMessage;
        }

    private:
        uint32 _zoneId; ///< ZoneId
        uint32 _id;     ///< BroadcastTextId
};

OPvPCapturePoint::OPvPCapturePoint(OutdoorPvP* pvp):
    m_team(TEAM_NEUTRAL), m_OldState(OBJECTIVESTATE_NEUTRAL),
    m_State(OBJECTIVESTATE_NEUTRAL), m_PvP(pvp)
{ }

OutdoorPvP::OutdoorPvP(Map* map) : m_TypeId(0), m_map(map) { }

OutdoorPvP::~OutdoorPvP() = default;

void OutdoorPvP::HandlePlayerEnterZone(Player* player, uint32 /*zone*/)
{
    m_players[player->GetTeamId()].insert(player->GetGUID());
}

void OutdoorPvP::HandlePlayerLeaveZone(Player* player, uint32 /*zone*/)
{
    // remove the world state information from the player (we can't keep everyone up to date, so leave out those who are not in the concerning zones)
    if (!player->GetSession()->PlayerLogout())
        SendRemoveWorldStates(player);
    m_players[player->GetTeamId()].erase(player->GetGUID());
    TC_LOG_DEBUG("outdoorpvp", "Player {} left an outdoorpvp zone", player->GetName());
}

void OutdoorPvP::HandlePlayerResurrects(Player* /*player*/, uint32 /*zone*/) { }

void OutdoorPvP::Update(uint32 diff)
{
    for (OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        itr->second->Update(diff);
}

int32 OutdoorPvP::GetWorldState(int32 worldStateId) const
{
    return sWorldStateMgr->GetValue(worldStateId, m_map);
}

void OutdoorPvP::SetWorldState(int32 worldStateId, int32 value)
{
    sWorldStateMgr->SetValue(worldStateId, value, false, m_map);
}

void OutdoorPvP::HandleKill(Player* killer, Unit* killed)
{
    if (Group* group = killer->GetGroup())
    {
        for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            Player* groupGuy = itr->GetSource();

            if (!groupGuy)
                continue;

            // skip if too far away
            if (!groupGuy->IsAtGroupRewardDistance(killed))
                continue;

            // creature kills must be notified, even if not inside objective / not outdoor pvp active
            // player kills only count if active and inside objective
            if ((groupGuy->IsOutdoorPvPActive()) || killed->GetTypeId() == TYPEID_UNIT)
                HandleKillImpl(groupGuy, killed);
        }
    }
    else
    {
        // creature kills must be notified, even if not inside objective / not outdoor pvp active
        if ((killer->IsOutdoorPvPActive()) || killed->GetTypeId() == TYPEID_UNIT)
            HandleKillImpl(killer, killed);
    }
}

bool OutdoorPvP::HandleCustomSpell(Player* player, uint32 spellId, GameObject* go)
{
    for (OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        if (itr->second->HandleCustomSpell(player, spellId, go))
            return true;

    return false;
}

bool OPvPCapturePoint::HandleCustomSpell(Player* player, uint32 /*spellId*/, GameObject* /*go*/)
{
    if (!player->IsOutdoorPvPActive())
        return false;
    return true;
}

bool OutdoorPvP::HandleOpenGo(Player* player, GameObject* go)
{
    for (OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        if (itr->second->HandleOpenGo(player, go) >= 0)
            return true;

    return false;
}

bool OutdoorPvP::HandleDropFlag(Player* player, uint32 id)
{
    for (OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        if (itr->second->HandleDropFlag(player, id))
            return true;

    return false;
}

int32 OPvPCapturePoint::HandleOpenGo(Player* /*player*/, GameObject* /*go*/)
{
    return -1;
}

void OutdoorPvP::BroadcastPacket(WorldPacket const* data) const
{
    // This is faster than sWorld->SendZoneMessage
    for (uint32 team = 0; team < PVP_TEAMS_COUNT; ++team)
        for (GuidSet::const_iterator itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
            if (Player* const player = ObjectAccessor::FindPlayer(*itr))
                player->SendDirectMessage(data);
}

void OutdoorPvP::RegisterZone(uint32 zoneId)
{
    sOutdoorPvPMgr->AddZone(zoneId, this);
}

bool OutdoorPvP::HasPlayer(Player const* player) const
{
    GuidSet const& plSet = m_players[player->GetTeamId()];
    return plSet.find(player->GetGUID()) != plSet.end();
}

void OutdoorPvP::TeamCastSpell(TeamId team, int32 spellId)
{
    if (spellId > 0)
    {
        for (GuidSet::iterator itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
            if (Player* const player = ObjectAccessor::FindPlayer(*itr))
                player->CastSpell(player, (uint32)spellId, true);
    }
    else
    {
        for (GuidSet::iterator itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
            if (Player* const player = ObjectAccessor::FindPlayer(*itr))
                player->RemoveAura((uint32)-spellId); // by stack?
    }
}

void OutdoorPvP::TeamApplyBuff(TeamId team, uint32 spellId, uint32 spellId2)
{
    TeamCastSpell(team, spellId);
    TeamCastSpell(OTHER_TEAM(team), spellId2 ? -(int32)spellId2 : -(int32)spellId);
}

void OutdoorPvP::SendDefenseMessage(uint32 zoneId, uint32 id)
{
    DefenseMessageBuilder builder(zoneId, id);
    Trinity::LocalizedDo<DefenseMessageBuilder> localizer(builder);
    BroadcastWorker(localizer, zoneId);
}

void OutdoorPvP::ProcessEvent([[maybe_unused]] WorldObject * target, [[maybe_unused]] uint32 eventId, [[maybe_unused]] WorldObject * invoker)
{
    if (invoker)
    {
        if (GameObject* gameobject = invoker->ToGameObject())
        {
            if (gameobject->GetGoType() == GAMEOBJECT_TYPE_CONTROL_ZONE)
            {
                if (!ControlZoneHandlers.contains(gameobject->GetEntry()))
                    return;

                auto controlzone = gameobject->GetGOInfo()->controlZone;
                OutdoorPvPControlZoneHandler& handler = *ControlZoneHandlers[invoker->GetEntry()];
                if (eventId == controlzone.CaptureEventAlliance)
                    handler.HandleCaptureEventAlliance(gameobject);
                else if (eventId == controlzone.CaptureEventHorde)
                    handler.HandleCaptureEventHorde(gameobject);
                else if (eventId == controlzone.ContestedEventAlliance)
                    handler.HandleContestedEventAlliance(gameobject);
                else if (eventId == controlzone.ContestedEventHorde)
                    handler.HandleContestedEventHorde(gameobject);
                else if (eventId == controlzone.NeutralEventAlliance)
                    handler.HandleNeutralEventAlliance(gameobject);
                else if (eventId == controlzone.NeutralEventHorde)
                    handler.HandleNeutralEventHorde(gameobject);
                else if (eventId == controlzone.ProgressEventAlliance)
                    handler.HandleProgressEventAlliance(gameobject);
                else if (eventId == controlzone.ProgressEventHorde)
                    handler.HandleProgressEventHorde(gameobject);
            }
        }
    }
}

template<class Worker>
void OutdoorPvP::BroadcastWorker(Worker& _worker, uint32 zoneId)
{
    for (uint32 i = 0; i < PVP_TEAMS_COUNT; ++i)
        for (GuidSet::iterator itr = m_players[i].begin(); itr != m_players[i].end(); ++itr)
            if (Player* player = ObjectAccessor::FindPlayer(*itr))
                if (player->GetZoneId() == zoneId)
                    _worker(player);
}
