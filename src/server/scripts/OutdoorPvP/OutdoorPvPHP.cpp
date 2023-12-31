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

#include "OutdoorPvPHP.h"
#include "GameObject.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "WorldStatePackets.h"

uint32 const OutdoorPvPHPBuffZonesNum = 6;
uint32 const OutdoorPvPHPBuffZones[OutdoorPvPHPBuffZonesNum] = { 3483, 3563, 3562, 3713, 3714, 3836 }; //  HP, citadel, ramparts, blood furnace, shattered halls, mag's lair

OutdoorPvPHP::OutdoorPvPHP(Map* map) : OutdoorPvP(map)
{
    m_TypeId = OUTDOOR_PVP_HP;
    m_AllianceTowersControlled = 0;
    m_HordeTowersControlled = 0;

    ControlZoneHandlers[HP_GO_ENTRY_TOWER_S] = std::make_unique<HPControlZoneHandler>(this);
    GetControlZoneTowerSouthHandler().SetFlagArtKitAlliance(65);
    GetControlZoneTowerSouthHandler().SetFlagArtKitHorde(64);
    GetControlZoneTowerSouthHandler().SetFlagArtKitNeutral(66);
    GetControlZoneTowerSouthHandler().SetTextCaptureAlliance(TEXT_BROKEN_HILL_TAKEN_ALLIANCE);
    GetControlZoneTowerSouthHandler().SetTextCaptureHorde(TEXT_BROKEN_HILL_TAKEN_HORDE);
    GetControlZoneTowerSouthHandler().SetWorldstateAlliance(HP_UI_TOWER_S_A);
    GetControlZoneTowerSouthHandler().SetWorldstateHorde(HP_UI_TOWER_S_H);
    GetControlZoneTowerSouthHandler().SetWorldstateNeutral(HP_UI_TOWER_S_N);
    GetControlZoneTowerSouthHandler().SetKillCredit(HP_KILL_CREDIT_TOWER_S);

    ControlZoneHandlers[HP_GO_ENTRY_TOWER_N] = std::make_unique<HPControlZoneHandler>(this);
    GetControlZoneTowerNorthHandler().SetFlagArtKitAlliance(62);
    GetControlZoneTowerNorthHandler().SetFlagArtKitHorde(61);
    GetControlZoneTowerNorthHandler().SetFlagArtKitNeutral(63);
    GetControlZoneTowerNorthHandler().SetTextCaptureAlliance(TEXT_OVERLOOK_TAKEN_ALLIANCE);
    GetControlZoneTowerNorthHandler().SetTextCaptureHorde(TEXT_OVERLOOK_TAKEN_HORDE);
    GetControlZoneTowerNorthHandler().SetWorldstateAlliance(HP_UI_TOWER_N_A);
    GetControlZoneTowerNorthHandler().SetWorldstateHorde(HP_UI_TOWER_N_H);
    GetControlZoneTowerNorthHandler().SetWorldstateNeutral(HP_UI_TOWER_N_N);
    GetControlZoneTowerNorthHandler().SetKillCredit(HP_KILL_CREDIT_TOWER_N);

    ControlZoneHandlers[HP_GO_ENTRY_TOWER_W] = std::make_unique<HPControlZoneHandler>(this);
    GetControlZoneTowerWestHandler().SetFlagArtKitAlliance(67);
    GetControlZoneTowerWestHandler().SetFlagArtKitHorde(68);
    GetControlZoneTowerWestHandler().SetFlagArtKitNeutral(69);
    GetControlZoneTowerWestHandler().SetTextCaptureAlliance(TEXT_STADIUM_TAKEN_ALLIANCE);
    GetControlZoneTowerWestHandler().SetTextCaptureHorde(TEXT_STADIUM_TAKEN_HORDE);
    GetControlZoneTowerWestHandler().SetWorldstateAlliance(HP_UI_TOWER_W_A);
    GetControlZoneTowerWestHandler().SetWorldstateHorde(HP_UI_TOWER_W_H);
    GetControlZoneTowerWestHandler().SetWorldstateNeutral(HP_UI_TOWER_W_N);
    GetControlZoneTowerWestHandler().SetKillCredit(HP_KILL_CREDIT_TOWER_W);
}

bool OutdoorPvPHP::SetupOutdoorPvP()
{
    m_AllianceTowersControlled = 0;
    m_HordeTowersControlled = 0;

    // add the zones affected by the pvp buff
    for (uint32 i = 0; i < OutdoorPvPHPBuffZonesNum; ++i)
        RegisterZone(OutdoorPvPHPBuffZones[i]);

    return true;
}

void OutdoorPvPHP::OnGameObjectCreate(GameObject* go)
{
    if (go->GetGoType() == GAMEOBJECT_TYPE_CONTROL_ZONE)
        _controlZoneGUIDs.insert(go->GetGUID());

    switch (go->GetEntry())
    {
        case 183514:
            GetControlZoneTowerSouthHandler().SetFlagGuid(go->GetGUID());
            break;
        case 182525:
            GetControlZoneTowerNorthHandler().SetFlagGuid(go->GetGUID());
            break;
        case 183515:
            GetControlZoneTowerWestHandler().SetFlagGuid(go->GetGUID());
            break;
        default:
            break;
    }

    OutdoorPvP::OnGameObjectCreate(go);
}

void OutdoorPvPHP::HandlePlayerEnterZone(Player* player, uint32 zone)
{
    // add buffs
    if (player->GetTeam() == ALLIANCE)
    {
        if (m_AllianceTowersControlled >=3)
            player->CastSpell(player, AllianceBuff, true);
    }
    else
    {
        if (m_HordeTowersControlled >=3)
            player->CastSpell(player, HordeBuff, true);
    }
    OutdoorPvP::HandlePlayerEnterZone(player, zone);
}

void OutdoorPvPHP::HandlePlayerLeaveZone(Player* player, uint32 zone)
{
    // remove buffs
    if (player->GetTeam() == ALLIANCE)
    {
        player->RemoveAurasDueToSpell(AllianceBuff);
    }
    else
    {
        player->RemoveAurasDueToSpell(HordeBuff);
    }
    OutdoorPvP::HandlePlayerLeaveZone(player, zone);
}

void OutdoorPvPHP::Update(uint32 diff)
{
    OutdoorPvP::Update(diff);
    if (m_AllianceTowersControlled == 3)
        TeamApplyBuff(TEAM_ALLIANCE, AllianceBuff, HordeBuff);
    else if (m_HordeTowersControlled == 3)
        TeamApplyBuff(TEAM_HORDE, HordeBuff, AllianceBuff);
    else
    {
        TeamCastSpell(TEAM_ALLIANCE, -AllianceBuff);
        TeamCastSpell(TEAM_HORDE, -HordeBuff);
    }
    SetWorldState(HP_UI_TOWER_COUNT_A, m_AllianceTowersControlled);
    SetWorldState(HP_UI_TOWER_COUNT_H, m_HordeTowersControlled);
}

void OutdoorPvPHP::SendRemoveWorldStates(Player* player)
{
    WorldPackets::WorldState::InitWorldStates initWorldStates;
    initWorldStates.MapID = player->GetMapId();
    initWorldStates.AreaID = player->GetZoneId();
    initWorldStates.SubareaID = player->GetAreaId();
    initWorldStates.Worldstates.emplace_back(HP_UI_TOWER_DISPLAY_A, 0);
    initWorldStates.Worldstates.emplace_back(HP_UI_TOWER_DISPLAY_H, 0);
    initWorldStates.Worldstates.emplace_back(HP_UI_TOWER_COUNT_H, 0);
    initWorldStates.Worldstates.emplace_back(HP_UI_TOWER_COUNT_A, 0);

    for (auto& itr : ControlZoneHandlers)
    {
        HPControlZoneHandler* handler = static_cast<HPControlZoneHandler*>(itr.second.get());
        initWorldStates.Worldstates.emplace_back(handler->GetWorldStateNeutral(), 0);
        initWorldStates.Worldstates.emplace_back(handler->GetWorldStateHorde(), 0);
        initWorldStates.Worldstates.emplace_back(handler->GetWorldStateAlliance(), 0);
    }

    player->SendDirectMessage(initWorldStates.Write());
}

void OutdoorPvPHP::HandleKillImpl(Player* player, Unit* killed)
{
    if (killed->GetTypeId() != TYPEID_PLAYER)
        return;

    // need to check if player is inside an capture zone
    bool isInsideCaptureZone = false;
    for (ObjectGuid const& guid : _controlZoneGUIDs)
    {
        if (GameObject* gameObject = GetMap()->GetGameObject(guid))
        {
            if (GuidUnorderedSet const* insidePlayerGuids = gameObject->GetInsidePlayers())
            {
                if (insidePlayerGuids->contains(player->GetGUID()))
                {
                    isInsideCaptureZone = true;
                    break;
                }
            }
        }
    }

    if (isInsideCaptureZone)
    {
        if (player->GetTeam() == ALLIANCE && killed->ToPlayer()->GetTeam() != ALLIANCE)
            player->CastSpell(player, AlliancePlayerKillReward, true);
        else if (player->GetTeam() == HORDE && killed->ToPlayer()->GetTeam() != HORDE)
            player->CastSpell(player, HordePlayerKillReward, true);
    }
}

uint32 OutdoorPvPHP::GetAllianceTowersControlled() const
{
    return m_AllianceTowersControlled;
}

void OutdoorPvPHP::SetAllianceTowersControlled(uint32 count)
{
    m_AllianceTowersControlled = count;
}

uint32 OutdoorPvPHP::GetHordeTowersControlled() const
{
    return m_HordeTowersControlled;
}

void OutdoorPvPHP::SetHordeTowersControlled(uint32 count)
{
    m_HordeTowersControlled = count;
}

HPControlZoneHandler::HPControlZoneHandler(OutdoorPvPHP* pvp) : OutdoorPvPControlZoneHandler(pvp),
    _flagGuid(ObjectGuid::Empty), _textCaptureAlliance(0), _textCaptureHorde(0),
    _flagArtKitNeutral(0), _flagArtKitHorde(0), _flagArtKitAlliance(0),
    _worldstateNeutral(0), _worldstateHorde(0), _worldstateAlliance(0),
    _killCredit(0)
{
}

void HPControlZoneHandler::HandleProgressEventHorde(GameObject* controlZone)
{
    ControlZoneHandler::HandleProgressEventHorde(controlZone);

    controlZone->SetGoArtKit(1);
    controlZone->SendCustomAnim(0);
    if (GameObject* flag = controlZone->GetMap()->GetGameObject(_flagGuid))
        flag->SetGoArtKit(_flagArtKitHorde);

    controlZone->GetMap()->SetWorldStateValue(_worldstateHorde, 1, false);
    controlZone->GetMap()->SetWorldStateValue(_worldstateAlliance, 0, false);
    controlZone->GetMap()->SetWorldStateValue(_worldstateNeutral, 0, false);

    GetOutdoorPvPHP()->SendDefenseMessage(OutdoorPvPHPBuffZones[0], _textCaptureHorde);

    if (GuidUnorderedSet const* guidSet = controlZone->GetInsidePlayers())
        for (ObjectGuid const& guid : *guidSet)
            if (Player* player = ObjectAccessor::GetPlayer(*controlZone, guid))
                if (player->GetTeam() == HORDE)
                    player->KilledMonsterCredit(_killCredit);
}

void HPControlZoneHandler::HandleProgressEventAlliance(GameObject* controlZone)
{
    ControlZoneHandler::HandleProgressEventAlliance(controlZone);

    controlZone->SetGoArtKit(2);
    controlZone->SendCustomAnim(1);
    if (GameObject* flag = controlZone->GetMap()->GetGameObject(_flagGuid))
        flag->SetGoArtKit(_flagArtKitAlliance);

    controlZone->GetMap()->SetWorldStateValue(_worldstateHorde, 0, false);
    controlZone->GetMap()->SetWorldStateValue(_worldstateAlliance, 1, false);
    controlZone->GetMap()->SetWorldStateValue(_worldstateNeutral, 0, false);

    GetOutdoorPvPHP()->SendDefenseMessage(OutdoorPvPHPBuffZones[0], _textCaptureAlliance);

    if (GuidUnorderedSet const* guidSet = controlZone->GetInsidePlayers())
        for (ObjectGuid const& guid : *guidSet)
            if (Player* player = ObjectAccessor::GetPlayer(*controlZone, guid))
                if (player->GetTeam() == ALLIANCE)
                    player->KilledMonsterCredit(_killCredit);
}

void HPControlZoneHandler::HandleNeutralEventHorde(GameObject* controlZone)
{
    ControlZoneHandler::HandleNeutralEventHorde(controlZone);
    GetOutdoorPvPHP()->SetHordeTowersControlled(GetOutdoorPvPHP()->GetHordeTowersControlled() - 1);
}

void HPControlZoneHandler::HandleNeutralEventAlliance(GameObject* controlZone)
{
    ControlZoneHandler::HandleNeutralEventAlliance(controlZone);
    GetOutdoorPvPHP()->SetAllianceTowersControlled(GetOutdoorPvPHP()->GetAllianceTowersControlled() - 1);
}

void HPControlZoneHandler::HandleNeutralEvent(GameObject* controlZone)
{
    ControlZoneHandler::HandleNeutralEvent(controlZone);
    controlZone->SetGoArtKit(21);
    controlZone->SendCustomAnim(2);
    if (GameObject* flag = controlZone->GetMap()->GetGameObject(_flagGuid))
        flag->SetGoArtKit(_flagArtKitNeutral);

    controlZone->GetMap()->SetWorldStateValue(_worldstateHorde, 0, false);
    controlZone->GetMap()->SetWorldStateValue(_worldstateAlliance, 0, false);
    controlZone->GetMap()->SetWorldStateValue(_worldstateNeutral, 1, false);
}

OutdoorPvPHP* HPControlZoneHandler::GetOutdoorPvPHP() const
{
    return static_cast<OutdoorPvPHP*>(OutdoorPvPControlZoneHandler::GetOutdoorPvP());
}

class OutdoorPvP_hellfire_peninsula : public OutdoorPvPScript
{
    public:
        OutdoorPvP_hellfire_peninsula() : OutdoorPvPScript("outdoorpvp_hp") { }

        OutdoorPvP* GetOutdoorPvP(Map* map) const override
        {
            return new OutdoorPvPHP(map);
        }
};

void AddSC_outdoorpvp_hp()
{
    new OutdoorPvP_hellfire_peninsula();
}
