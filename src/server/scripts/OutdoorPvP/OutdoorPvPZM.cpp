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

#include "OutdoorPvPZM.h"
#include "Creature.h"
#include "GameObject.h"
#include "GossipDef.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "WorldSession.h"
#include "WorldStatePackets.h"

uint8 const OutdoorPvPZMBuffZonesNum = 5;

// the buff is cast in these zones
uint32 const OutdoorPvPZMBuffZones[OutdoorPvPZMBuffZonesNum] = { 3521, 3607, 3717, 3715, 3716 };

// linked when the central tower is controlled
uint32 const ZM_GRAVEYARD_ZONE = 3521;

ZMControlZoneHandler::ZMControlZoneHandler(OutdoorPvPZM* pvp, uint32 textBeaconTakenHorde, uint32 textBeaconTakenAlliance, uint32 worldstateNeutralUi, uint32 worldstateNeutralMap, uint32 worldstateHordeUi, uint32 worldstateHordeMap, uint32 worldstateAllianceUi, uint32 worldstateAllianceMap)
    : OutdoorPvPControlZoneHandler(pvp), _textBeaconTakenHorde(textBeaconTakenHorde), _textBeaconTakenAlliance(textBeaconTakenAlliance), _worldstateNeutralUi(worldstateNeutralUi), _worldstateNeutralMap(worldstateNeutralMap),
    _worldstateHordeUi(worldstateHordeUi), _worldstateHordeMap(worldstateHordeMap), _worldstateAllianceUi(worldstateAllianceUi), _worldstateAllianceMap(worldstateAllianceMap)
{
}

void ZMControlZoneHandler::HandleProgressEventHorde(GameObject* controlZone)
{
    OutdoorPvPControlZoneHandler::HandleProgressEventHorde(controlZone);
    GetOutdoorPvpZM()->SetHordeTowersControlled(GetOutdoorPvpZM()->GetHordeTowersControlled() + 1);
    GetOutdoorPvpZM()->SendDefenseMessage(ZM_GRAVEYARD_ZONE, _textBeaconTakenHorde);

    GetOutdoorPvpZM()->SetWorldState(_worldstateAllianceMap, 0);
    GetOutdoorPvpZM()->SetWorldState(_worldstateAllianceUi, 0);
    GetOutdoorPvpZM()->SetWorldState(_worldstateNeutralMap, 0);
    GetOutdoorPvpZM()->SetWorldState(_worldstateNeutralUi, 0);
    GetOutdoorPvpZM()->SetWorldState(_worldstateHordeMap, 1);
    GetOutdoorPvpZM()->SetWorldState(_worldstateHordeUi, 1);
}

void ZMControlZoneHandler::HandleProgressEventAlliance(GameObject* controlZone)
{
    OutdoorPvPControlZoneHandler::HandleProgressEventAlliance(controlZone);
    GetOutdoorPvpZM()->SetAllianceTowersControlled(GetOutdoorPvpZM()->GetAllianceTowersControlled() + 1);
    GetOutdoorPvpZM()->SendDefenseMessage(ZM_GRAVEYARD_ZONE, _textBeaconTakenAlliance);

    GetOutdoorPvpZM()->SetWorldState(_worldstateAllianceMap, 1);
    GetOutdoorPvpZM()->SetWorldState(_worldstateAllianceUi, 1);
    GetOutdoorPvpZM()->SetWorldState(_worldstateNeutralMap, 0);
    GetOutdoorPvpZM()->SetWorldState(_worldstateNeutralUi, 0);
    GetOutdoorPvpZM()->SetWorldState(_worldstateHordeMap, 0);
    GetOutdoorPvpZM()->SetWorldState(_worldstateHordeUi, 0);
}

void ZMControlZoneHandler::HandleNeutralEventHorde(GameObject* controlZone)
{
    GetOutdoorPvpZM()->SetHordeTowersControlled(GetOutdoorPvpZM()->GetHordeTowersControlled() - 1);

    OutdoorPvPControlZoneHandler::HandleNeutralEventHorde(controlZone);
}

void ZMControlZoneHandler::HandleNeutralEventAlliance(GameObject* controlZone)
{
    GetOutdoorPvpZM()->SetAllianceTowersControlled(GetOutdoorPvpZM()->GetAllianceTowersControlled() - 1);

    OutdoorPvPControlZoneHandler::HandleNeutralEventAlliance(controlZone);
}

void ZMControlZoneHandler::HandleNeutralEvent(GameObject* controlZone)
{
    OutdoorPvPControlZoneHandler::HandleNeutralEvent(controlZone);

    GetOutdoorPvpZM()->SetWorldState(_worldstateAllianceMap, 0);
    GetOutdoorPvpZM()->SetWorldState(_worldstateAllianceUi, 0);
    GetOutdoorPvpZM()->SetWorldState(_worldstateNeutralMap, 1);
    GetOutdoorPvpZM()->SetWorldState(_worldstateNeutralUi, 1);
    GetOutdoorPvpZM()->SetWorldState(_worldstateHordeMap, 0);
    GetOutdoorPvpZM()->SetWorldState(_worldstateHordeUi, 0);
}

OutdoorPvPZM* ZMControlZoneHandler::GetOutdoorPvpZM()
{
    return static_cast<OutdoorPvPZM*>(OutdoorPvPControlZoneHandler::GetOutdoorPvP());
}

void OutdoorPvPZM::Update(uint32 diff)
{
    OutdoorPvP::Update(diff);
    if (m_AllianceTowersControlled == ZM_NUM_BEACONS)
        m_Graveyard->SetBeaconState(ALLIANCE);
    else if (m_HordeTowersControlled == ZM_NUM_BEACONS)
        m_Graveyard->SetBeaconState(HORDE);
    else
        m_Graveyard->SetBeaconState(0);
}

void OutdoorPvPZM::HandlePlayerEnterZone(Player* player, uint32 zone)
{
    if (player->GetTeam() == ALLIANCE)
    {
        if (m_Graveyard->GetGraveyardState() & ZM_GRAVEYARD_A)
            player->CastSpell(player, ZM_CAPTURE_BUFF, true);
    }
    else if (player->GetTeam() == HORDE)
    {
        if (m_Graveyard->GetGraveyardState() & ZM_GRAVEYARD_H)
            player->CastSpell(player, ZM_CAPTURE_BUFF, true);
    }
    OutdoorPvP::HandlePlayerEnterZone(player, zone);
}

void OutdoorPvPZM::HandlePlayerLeaveZone(Player* player, uint32 zone)
{
    // remove buffs
    player->RemoveAurasDueToSpell(ZM_CAPTURE_BUFF);
    // remove flag
    player->RemoveAurasDueToSpell(ZM_BATTLE_STANDARD_A);
    player->RemoveAurasDueToSpell(ZM_BATTLE_STANDARD_H);
    OutdoorPvP::HandlePlayerLeaveZone(player, zone);
}

OutdoorPvPZM::OutdoorPvPZM(Map* map) : OutdoorPvP(map)
{
    m_TypeId = OUTDOOR_PVP_ZM;
    m_Graveyard = nullptr;
    m_AllianceTowersControlled = 0;
    m_HordeTowersControlled = 0;

    ControlZoneHandlers[ZM_GO_ENTRY_BEACON_EAST] = std::make_unique<ZMControlZoneHandler>(
        this,
        TEXT_EAST_BEACON_TAKEN_HORDE,
        TEXT_EAST_BEACON_TAKEN_ALLIANCE,
        ZM_UI_TOWER_EAST_N,
        ZM_MAP_TOWER_EAST_N,
        ZM_UI_TOWER_EAST_H,
        ZM_MAP_TOWER_EAST_H,
        ZM_UI_TOWER_EAST_A,
        ZM_MAP_TOWER_EAST_A
    );

    ControlZoneHandlers[ZM_GO_ENTRY_BEACON_WEST] = std::make_unique<ZMControlZoneHandler>(
        this,
        TEXT_WEST_BEACON_TAKEN_HORDE,
        TEXT_WEST_BEACON_TAKEN_ALLIANCE,
        ZM_UI_TOWER_WEST_N,
        ZM_MAP_TOWER_WEST_N,
        ZM_UI_TOWER_WEST_H,
        ZM_MAP_TOWER_WEST_H,
        ZM_UI_TOWER_WEST_A,
        ZM_MAP_TOWER_WEST_A
    );
}

bool OutdoorPvPZM::SetupOutdoorPvP()
{
    m_AllianceTowersControlled = 0;
    m_HordeTowersControlled = 0;

    // add the zones affected by the pvp buff
    for (uint8 i = 0; i < OutdoorPvPZMBuffZonesNum; ++i)
        RegisterZone(OutdoorPvPZMBuffZones[i]);

    m_Graveyard = new OPvPCapturePointZM_Graveyard(this);

    return true;
}

void OutdoorPvPZM::HandleKillImpl(Player* player, Unit* killed)
{
    if (killed->GetTypeId() != TYPEID_PLAYER)
        return;

    if (player->GetTeam() == ALLIANCE && killed->ToPlayer()->GetTeam() != ALLIANCE)
        player->CastSpell(player, ZM_AlliancePlayerKillReward, true);
    else if (player->GetTeam() == HORDE && killed->ToPlayer()->GetTeam() != HORDE)
        player->CastSpell(player, ZM_HordePlayerKillReward, true);
}

void OPvPCapturePointZM_Graveyard::Update(uint32 /*diff*/)
{
    m_State = m_OldState;
}

int32 OPvPCapturePointZM_Graveyard::HandleOpenGo(Player* player, GameObject* go)
{
    switch (go->GetEntry())
    {
        case 182529:
        case 182527:
        case 182528:
            if (player->HasAura(ZM_BATTLE_STANDARD_A) && m_GraveyardState != ZM_GRAVEYARD_A)
            {
                m_GraveyardState = ZM_GRAVEYARD_A;
                m_PvP->TeamApplyBuff(TEAM_ALLIANCE, ZM_CAPTURE_BUFF);
                player->RemoveAurasDueToSpell(ZM_BATTLE_STANDARD_A);
                m_PvP->SendDefenseMessage(ZM_GRAVEYARD_ZONE, TEXT_TWIN_SPIRE_RUINS_TAKEN_ALLIANCE);
            }
            else if (player->HasAura(ZM_BATTLE_STANDARD_H) && m_GraveyardState != ZM_GRAVEYARD_H)
            {
                m_GraveyardState = ZM_GRAVEYARD_H;
                m_PvP->TeamApplyBuff(TEAM_HORDE, ZM_CAPTURE_BUFF);
                player->RemoveAurasDueToSpell(ZM_BATTLE_STANDARD_H);
                m_PvP->SendDefenseMessage(ZM_GRAVEYARD_ZONE, TEXT_TWIN_SPIRE_RUINS_TAKEN_HORDE);
            }
            UpdateTowerState();
            return 0;
        default:
            return OPvPCapturePoint::HandleOpenGo(player, go);
    }
}

OPvPCapturePointZM_Graveyard::OPvPCapturePointZM_Graveyard(OutdoorPvP* pvp) : OPvPCapturePoint(pvp)
{
    m_BothControllingFaction = 0;
    m_GraveyardState = ZM_GRAVEYARD_N;
    m_FlagCarrierGUID.Clear();
}

void OPvPCapturePointZM_Graveyard::UpdateTowerState()
{
    m_PvP->SetWorldState(ZM_MAP_GRAVEYARD_N, int32((m_GraveyardState & ZM_GRAVEYARD_N) != 0));
    m_PvP->SetWorldState(ZM_MAP_GRAVEYARD_H, int32((m_GraveyardState & ZM_GRAVEYARD_H) != 0));
    m_PvP->SetWorldState(ZM_MAP_GRAVEYARD_A, int32((m_GraveyardState & ZM_GRAVEYARD_A) != 0));

    bool allianceFlagReady = m_BothControllingFaction == ALLIANCE && m_GraveyardState != ZM_GRAVEYARD_A;
    m_PvP->SetWorldState(ZM_MAP_ALLIANCE_FLAG_READY, int32(allianceFlagReady));
    m_PvP->SetWorldState(ZM_MAP_ALLIANCE_FLAG_NOT_READY, int32(!allianceFlagReady));

    bool hordeFlagReady = m_BothControllingFaction == HORDE && m_GraveyardState != ZM_GRAVEYARD_H;
    m_PvP->SetWorldState(ZM_MAP_HORDE_FLAG_READY, int32(hordeFlagReady));
    m_PvP->SetWorldState(ZM_MAP_HORDE_FLAG_NOT_READY, int32(!hordeFlagReady));
}

void OPvPCapturePointZM_Graveyard::SetBeaconState(uint32 controlling_faction)
{
    // nothing to do here
    if (m_BothControllingFaction == controlling_faction)
        return;
    m_BothControllingFaction = controlling_faction;

    switch (controlling_faction)
    {
    case ALLIANCE:
        // if ally already controls the gy and taken back both beacons, return, nothing to do for us
        if (m_GraveyardState & ZM_GRAVEYARD_A)
            return;
        // ally doesn't control the gy, but controls the side beacons -> add gossip option, add neutral banner
        break;
    case HORDE:
        // if horde already controls the gy and taken back both beacons, return, nothing to do for us
        if (m_GraveyardState & ZM_GRAVEYARD_H)
            return;
        // horde doesn't control the gy, but controls the side beacons -> add gossip option, add neutral banner
        break;
    default:
        // if the graveyard is not neutral, then leave it that way
        // if the graveyard is neutral, then we have to dispel the buff from the flag carrier
        if (m_GraveyardState & ZM_GRAVEYARD_N)
        {
            // gy was neutral, thus neutral banner was spawned, it is possible that someone was taking the flag to the gy
            if (!m_FlagCarrierGUID.IsEmpty())
            {
                // remove flag from carrier, reset flag carrier guid
                Player* p = ObjectAccessor::FindPlayer(m_FlagCarrierGUID);
                if (p)
                {
                   p->RemoveAurasDueToSpell(ZM_BATTLE_STANDARD_A);
                   p->RemoveAurasDueToSpell(ZM_BATTLE_STANDARD_H);
                }
                m_FlagCarrierGUID.Clear();
            }
        }
        break;
    }
    // send worldstateupdate
    UpdateTowerState();
}

bool OPvPCapturePointZM_Graveyard::HandleDropFlag(Player* /*player*/, uint32 spellId)
{
    switch (spellId)
    {
        case ZM_BATTLE_STANDARD_A:
        case ZM_BATTLE_STANDARD_H:
            m_FlagCarrierGUID.Clear();
            return true;
        default:
            break;
    }
    return false;
}

uint32 OPvPCapturePointZM_Graveyard::GetGraveyardState() const
{
    return m_GraveyardState;
}

uint32 OutdoorPvPZM::GetAllianceTowersControlled() const
{
    return m_AllianceTowersControlled;
}

void OutdoorPvPZM::SetAllianceTowersControlled(uint32 count)
{
    m_AllianceTowersControlled = count;
}

uint32 OutdoorPvPZM::GetHordeTowersControlled() const
{
    return m_HordeTowersControlled;
}

void OutdoorPvPZM::SetHordeTowersControlled(uint32 count)
{
    m_HordeTowersControlled = count;
}

void OutdoorPvPZM::SendRemoveWorldStates(Player* player)
{
    WorldPackets::WorldState::InitWorldStates initWorldStates;
    initWorldStates.MapID = player->GetMapId();
    initWorldStates.AreaID = player->GetZoneId();
    initWorldStates.SubareaID = player->GetAreaId();

    for (auto& itr : ControlZoneHandlers)
    {
        ZMControlZoneHandler* handler = static_cast<ZMControlZoneHandler*>(itr.second.get());
        initWorldStates.Worldstates.emplace_back(handler->GetWorldStateNeutralUI(), 0);
        initWorldStates.Worldstates.emplace_back(handler->GetWorldStateNeutralMap(), 0);
        initWorldStates.Worldstates.emplace_back(handler->GetWorldStateHordeUI(), 0);
        initWorldStates.Worldstates.emplace_back(handler->GetWorldStateHordeMap(), 0);
        initWorldStates.Worldstates.emplace_back(handler->GetWorldStateAllianceUI(), 0);
        initWorldStates.Worldstates.emplace_back(handler->GetWorldStateAllianceMap(), 0);
    }
    initWorldStates.Worldstates.emplace_back(ZM_MAP_GRAVEYARD_H, 0);
    initWorldStates.Worldstates.emplace_back(ZM_MAP_GRAVEYARD_A, 0);
    initWorldStates.Worldstates.emplace_back(ZM_MAP_GRAVEYARD_N, 0);
    initWorldStates.Worldstates.emplace_back(ZM_MAP_HORDE_FLAG_READY, 0);
    initWorldStates.Worldstates.emplace_back(ZM_MAP_HORDE_FLAG_NOT_READY, 0);
    initWorldStates.Worldstates.emplace_back(ZM_MAP_ALLIANCE_FLAG_NOT_READY, 0);
    initWorldStates.Worldstates.emplace_back(ZM_MAP_ALLIANCE_FLAG_READY, 0);
    player->SendDirectMessage(initWorldStates.Write());
}

class OutdoorPvP_zangarmarsh : public OutdoorPvPScript
{
    public:
        OutdoorPvP_zangarmarsh() : OutdoorPvPScript("outdoorpvp_zm") { }

        OutdoorPvP* GetOutdoorPvP(Map* map) const override
        {
            return new OutdoorPvPZM(map);
        }
};

enum ZMFieldScoutMisc
{
    GOSSIP_MENU_FIELD_SCOUT_HORDE               = 7722,
    GOSSIP_MENU_FIELD_SCOUT_ALLIANCE            = 7724,

    GOSSIP_OPTION_FIELD_SCOUT_BATTLE_STANDARD   = 0,
    GOSSIP_OPTION_FIELD_SCOUT_VENDOR            = 1,
};

// 18581 - Alliance Field Scout
// 18564 - Horde Field Scout
struct npc_zm_field_scout : public ScriptedAI
{
    npc_zm_field_scout(Creature* creature) : ScriptedAI(creature) { }

    bool CanObtainBanner(Player* player)
    {
        OutdoorPvP* pvp = player->GetOutdoorPvP();
        if (!pvp)
            return false;

        OutdoorPvPZM* zmPvp = reinterpret_cast<OutdoorPvPZM*>(pvp);
        if (!zmPvp)
            return false;

        OPvPCapturePointZM_Graveyard* gy = zmPvp->GetGraveyard();
        if (!gy)
            return false;

        if (!gy->GetFlagCarrierGUID().IsEmpty())
            return false;

        switch (me->GetEntry())
        {
            case ZM_ALLIANCE_FIELD_SCOUT:
                return player->GetTeam() == ALLIANCE && pvp->GetWorldState(ZM_MAP_ALLIANCE_FLAG_READY);
            case ZM_HORDE_FIELD_SCOUT:
                return player->GetTeam() == HORDE && pvp->GetWorldState(ZM_MAP_HORDE_FLAG_READY);
            default:
                break;
        }
        return true;
    }

    bool OnGossipHello(Player* player) override
    {
        uint32 gossipMenuId = GOSSIP_MENU_FIELD_SCOUT_HORDE;
        if (me->GetEntry() == ZM_ALLIANCE_FIELD_SCOUT)
            gossipMenuId = GOSSIP_MENU_FIELD_SCOUT_ALLIANCE;

        InitGossipMenuFor(player, gossipMenuId);
        if (CanObtainBanner(player))
            AddGossipItemFor(player, gossipMenuId, GOSSIP_OPTION_FIELD_SCOUT_BATTLE_STANDARD, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

        AddGossipItemFor(player, gossipMenuId, GOSSIP_OPTION_FIELD_SCOUT_VENDOR, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);
        SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
    {
        uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF:
            {
                player->PlayerTalkClass->SendCloseGossip();

                OutdoorPvP* pvp = player->GetOutdoorPvP();
                if (!pvp)
                    return true;

                OutdoorPvPZM* zmPvp = reinterpret_cast<OutdoorPvPZM*>(pvp);
                if (!zmPvp)
                    return true;

                OPvPCapturePointZM_Graveyard* gy = zmPvp->GetGraveyard();
                if (!gy)
                    return true;

                // if the flag is already taken, then return
                if (!gy->GetFlagCarrierGUID().IsEmpty())
                    return true;

                uint32 battleStandardSpell = ZM_BATTLE_STANDARD_H;
                if (me->GetEntry() == ZM_ALLIANCE_FIELD_SCOUT)
                    battleStandardSpell = ZM_BATTLE_STANDARD_A;

                me->CastSpell(player, battleStandardSpell, true);
                gy->SetFlagCarrierGUID(player->GetGUID());
                gy->UpdateTowerState();
                break;
            }
            case GOSSIP_ACTION_TRADE:
                player->GetSession()->SendListInventory(me->GetGUID());
                break;
            default:
                break;
        }
        return true;
    }
};

void AddSC_outdoorpvp_zm()
{
    new OutdoorPvP_zangarmarsh();
    RegisterCreatureAI(npc_zm_field_scout);
}
