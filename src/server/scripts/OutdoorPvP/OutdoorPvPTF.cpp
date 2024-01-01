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

#include "GameObject.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "OutdoorPvPTF.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "WorldStatePackets.h"

uint8 const OutdoorPvPTFBuffZonesNum = 5;
uint32 const OutdoorPvPTFBuffZones[OutdoorPvPTFBuffZonesNum] =
{
    3519 /*Terokkar Forest*/,
    3791 /*Sethekk Halls*/,
    3789 /*Shadow Labyrinth*/,
    3792 /*Mana-Tombs*/,
    3790 /*Auchenai Crypts*/
};

// locked for 6 hours after capture
uint32 const TF_LOCK_TIME = 3600 * 6 * 1000;

// update lock timer every 1/4 minute (overkill, but this way it's sure the timer won't "jump" 2 minutes at once.)
uint32 const TF_LOCK_TIME_UPDATE = 15000;

// blessing of auchindoun, used in TeamCastSpell which uses signed int, so signed
int32 const TF_CAPTURE_BUFF = 33377;

uint32 const TF_ALLY_QUEST = 11505;
uint32 const TF_HORDE_QUEST = 11506;

OutdoorPvPTF::OutdoorPvPTF(Map* map) : OutdoorPvP(map)
{
    m_TypeId = OUTDOOR_PVP_TF;
    m_IsLocked = false;
    m_LockTimer = TF_LOCK_TIME;
    m_LockTimerUpdate = 0;
    m_AllianceTowersControlled = 0;
    m_HordeTowersControlled = 0;
    hours_left = 6;
    second_digit = 0;
    first_digit = 0;

    ControlZoneHandlers[TF_ENTRY_TOWER_NW] = std::make_unique<TFControlZoneHandler>(this, 2682, 2683, 2681);
    ControlZoneHandlers[TF_ENTRY_TOWER_N] = std::make_unique<TFControlZoneHandler>(this, 2685, 2684, 2686);
    ControlZoneHandlers[TF_ENTRY_TOWER_NE] = std::make_unique<TFControlZoneHandler>(this, 2689, 2688, 2690);
    ControlZoneHandlers[TF_ENTRY_TOWER_SE] = std::make_unique<TFControlZoneHandler>(this, 2695, 2694, 2696);
    ControlZoneHandlers[TF_ENTRY_TOWER_S] = std::make_unique<TFControlZoneHandler>(this, 2692, 2691, 2693);
}

void OutdoorPvPTF::SendRemoveWorldStates(Player* player)
{
    WorldPackets::WorldState::InitWorldStates initWorldStates;
    initWorldStates.MapID = player->GetMapId();
    initWorldStates.AreaID = player->GetZoneId();
    initWorldStates.SubareaID = player->GetAreaId();
    initWorldStates.Worldstates.emplace_back(TF_UI_TOWER_COUNT_H, 0);
    initWorldStates.Worldstates.emplace_back(TF_UI_TOWER_COUNT_A, 0);
    initWorldStates.Worldstates.emplace_back(TF_UI_TOWERS_CONTROLLED_DISPLAY, 0);

    initWorldStates.Worldstates.emplace_back(TF_UI_LOCKED_TIME_MINUTES_FIRST_DIGIT, 0);
    initWorldStates.Worldstates.emplace_back(TF_UI_LOCKED_TIME_MINUTES_SECOND_DIGIT, 0);
    initWorldStates.Worldstates.emplace_back(TF_UI_LOCKED_TIME_HOURS, 0);

    initWorldStates.Worldstates.emplace_back(TF_UI_LOCKED_DISPLAY_NEUTRAL, 0);
    initWorldStates.Worldstates.emplace_back(TF_UI_LOCKED_DISPLAY_HORDE, 0);
    initWorldStates.Worldstates.emplace_back(TF_UI_LOCKED_DISPLAY_ALLIANCE, 0);

    for (auto& itr : ControlZoneHandlers)
    {
        TFControlZoneHandler* handler = static_cast<TFControlZoneHandler*>(itr.second.get());
        initWorldStates.Worldstates.emplace_back(handler->GetWorldStateNeutral(), 0);
        initWorldStates.Worldstates.emplace_back(handler->GetWorldStateHorde(), 0);
        initWorldStates.Worldstates.emplace_back(handler->GetWorldStateAlliance(), 0);
    }

    player->SendDirectMessage(initWorldStates.Write());
}

void OutdoorPvPTF::Update(uint32 diff)
{
    OutdoorPvP::Update(diff);

    if (m_IsLocked)
    {
        // lock timer is down, release lock
        if (m_LockTimer < diff)
        {
            m_LockTimer = TF_LOCK_TIME;
            m_LockTimerUpdate = 0;
            m_IsLocked = false;

            for (ObjectGuid const& controlZoneGUID : _controlZoneGUIDs)
            {
                if (GameObject* gameObject = GetMap()->GetGameObject(controlZoneGUID))
                {
                    gameObject->HandleCustomTypeCommand(GameObjectType::SetControlZoneValue());
                    gameObject->ActivateObject(GameObjectActions::MakeActive, 0);
                }
            }

            SetWorldState(TF_UI_TOWERS_CONTROLLED_DISPLAY, 1);
            SetWorldState(TF_UI_LOCKED_DISPLAY_NEUTRAL, 0);
            SetWorldState(TF_UI_LOCKED_DISPLAY_HORDE, 0);
            SetWorldState(TF_UI_LOCKED_DISPLAY_ALLIANCE, 0);
        }
        else
        {
            // worldstateui update timer is down, update ui with new time data
            if (m_LockTimerUpdate < diff)
            {
                m_LockTimerUpdate = TF_LOCK_TIME_UPDATE;
                uint32 minutes_left = m_LockTimer / 60000;
                hours_left = minutes_left / 60;
                minutes_left -= hours_left * 60;
                second_digit = minutes_left % 10;
                first_digit = minutes_left / 10;

                SetWorldState(TF_UI_LOCKED_TIME_MINUTES_FIRST_DIGIT, first_digit);
                SetWorldState(TF_UI_LOCKED_TIME_MINUTES_SECOND_DIGIT, second_digit);
                SetWorldState(TF_UI_LOCKED_TIME_HOURS, hours_left);
            } else m_LockTimerUpdate -= diff;
            m_LockTimer -= diff;
        }
    }
}

void OutdoorPvPTF::HandlePlayerEnterZone(Player* player, uint32 zone)
{
    if (player->GetTeam() == ALLIANCE)
    {
        if (m_AllianceTowersControlled >= TF_TOWER_NUM)
            player->CastSpell(player, TF_CAPTURE_BUFF, true);
    }
    else
    {
        if (m_HordeTowersControlled >= TF_TOWER_NUM)
            player->CastSpell(player, TF_CAPTURE_BUFF, true);
    }
    OutdoorPvP::HandlePlayerEnterZone(player, zone);
}

void OutdoorPvPTF::HandlePlayerLeaveZone(Player* player, uint32 zone)
{
    // remove buffs
    player->RemoveAurasDueToSpell(TF_CAPTURE_BUFF);
    OutdoorPvP::HandlePlayerLeaveZone(player, zone);
}

uint32 OutdoorPvPTF::GetAllianceTowersControlled() const
{
    return m_AllianceTowersControlled;
}

void OutdoorPvPTF::SetAllianceTowersControlled(uint32 count)
{
    m_AllianceTowersControlled = count;
}

uint32 OutdoorPvPTF::GetHordeTowersControlled() const
{
    return m_HordeTowersControlled;
}

void OutdoorPvPTF::SetHordeTowersControlled(uint32 count)
{
    m_HordeTowersControlled = count;
}

bool OutdoorPvPTF::IsLocked() const
{
    return m_IsLocked;
}

void OutdoorPvPTF::ProcessEvent(WorldObject* obj, uint32 eventId, WorldObject* invoker)
{
    OutdoorPvP::ProcessEvent(obj, eventId, invoker);

    SetWorldState(TF_UI_TOWER_COUNT_A, m_AllianceTowersControlled);
    SetWorldState(TF_UI_TOWER_COUNT_H, m_HordeTowersControlled);

    // now check if everything is capped
    if (m_HordeTowersControlled == TF_TOWER_NUM)
        HandleCapture(TEAM_HORDE);
    else if (m_AllianceTowersControlled == TF_TOWER_NUM)
        HandleCapture(TEAM_ALLIANCE);
    else
    {
        TeamCastSpell(TEAM_ALLIANCE, -TF_CAPTURE_BUFF);
        TeamCastSpell(TEAM_HORDE, -TF_CAPTURE_BUFF);
    }
}

void OutdoorPvPTF::HandleCapture(TeamId team)
{
    m_IsLocked = true;

    for (ObjectGuid const& controlZoneGUID : _controlZoneGUIDs)
        if (GameObject* gameObject = GetMap()->GetGameObject(controlZoneGUID))
            gameObject->ActivateObject(GameObjectActions::MakeInert, 0);

    TeamApplyBuff(team, TF_CAPTURE_BUFF);
    SetWorldState(TF_UI_LOCKED_DISPLAY_NEUTRAL, 0);
    SetWorldState(TF_UI_LOCKED_DISPLAY_HORDE, team == TEAM_HORDE ? 1 : 0);
    SetWorldState(TF_UI_LOCKED_DISPLAY_ALLIANCE, team == TEAM_ALLIANCE ? 1 : 0);
    SetWorldState(TF_UI_TOWERS_CONTROLLED_DISPLAY, 0);
}

bool OutdoorPvPTF::SetupOutdoorPvP()
{
    m_AllianceTowersControlled = 0;
    m_HordeTowersControlled = 0;

    m_IsLocked = false;
    m_LockTimer = TF_LOCK_TIME;
    m_LockTimerUpdate = 0;
    hours_left = 6;
    second_digit = 0;
    first_digit = 0;

    // add the zones affected by the pvp buff
    for (uint8 i = 0; i < OutdoorPvPTFBuffZonesNum; ++i)
        RegisterZone(OutdoorPvPTFBuffZones[i]);

    return true;
}

void OutdoorPvPTF::OnGameObjectCreate(GameObject* go)
{
    switch (go->GetEntry())
    {
        case TF_ENTRY_TOWER_NW:
        case TF_ENTRY_TOWER_N:
        case TF_ENTRY_TOWER_NE:
        case TF_ENTRY_TOWER_SE:
        case TF_ENTRY_TOWER_S:
            _controlZoneGUIDs.insert(go->GetGUID());
            break;
        default:
            break;
    }

    OutdoorPvP::OnGameObjectCreate(go);
}

TFControlZoneHandler::TFControlZoneHandler(OutdoorPvPTF* pvp, uint32 worldstateHorde, uint32 worldstateAlliance, uint32 worldstateNeutral) : OutdoorPvPControlZoneHandler(pvp),
_worldstateHorde(worldstateHorde), _worldstateAlliance(worldstateAlliance), _worldstateNeutral(worldstateNeutral)
{
}

void TFControlZoneHandler::HandleProgressEventHorde(GameObject* controlZone)
{
    controlZone->SetGoArtKit(1);
    GetOutdoorPvPTF()->SetHordeTowersControlled(GetOutdoorPvPTF()->GetHordeTowersControlled() + 1);
    GetOutdoorPvP()->SendDefenseMessage(OutdoorPvPTFBuffZones[0], TEXT_SPIRIT_TOWER_TAKEN_HORDE);
    controlZone->GetMap()->SetWorldStateValue(_worldstateHorde, 1, false);
    controlZone->GetMap()->SetWorldStateValue(_worldstateAlliance, 0, false);
    controlZone->GetMap()->SetWorldStateValue(_worldstateNeutral, 0, false);

    if (GuidUnorderedSet const* guidSet = controlZone->GetInsidePlayers())
        for (ObjectGuid const& guid : *guidSet)
            if (Player* player = ObjectAccessor::GetPlayer(*controlZone, guid))
                if (player->GetTeam() == HORDE)
                    player->AreaExploredOrEventHappens(TF_HORDE_QUEST);

    OutdoorPvPControlZoneHandler::HandleProgressEventHorde(controlZone);
}

void TFControlZoneHandler::HandleProgressEventAlliance(GameObject* controlZone)
{
    controlZone->SetGoArtKit(2);
    GetOutdoorPvPTF()->SetAllianceTowersControlled(GetOutdoorPvPTF()->GetAllianceTowersControlled() + 1);
    GetOutdoorPvP()->SendDefenseMessage(OutdoorPvPTFBuffZones[0], TEXT_SPIRIT_TOWER_TAKEN_ALLIANCE);
    controlZone->GetMap()->SetWorldStateValue(_worldstateHorde, 0, false);
    controlZone->GetMap()->SetWorldStateValue(_worldstateAlliance, 1, false);
    controlZone->GetMap()->SetWorldStateValue(_worldstateNeutral, 0, false);

    if (GuidUnorderedSet const* guidSet = controlZone->GetInsidePlayers())
        for (ObjectGuid const& guid : *guidSet)
            if (Player* player = ObjectAccessor::GetPlayer(*controlZone, guid))
                if (player->GetTeam() == ALLIANCE)
                    player->AreaExploredOrEventHappens(TF_ALLY_QUEST);

    OutdoorPvPControlZoneHandler::HandleProgressEventAlliance(controlZone);
}

void TFControlZoneHandler::HandleNeutralEventHorde(GameObject* controlZone)
{
    GetOutdoorPvPTF()->SetHordeTowersControlled(GetOutdoorPvPTF()->GetHordeTowersControlled() - 1);
    GetOutdoorPvP()->SendDefenseMessage(OutdoorPvPTFBuffZones[0], TEXT_SPIRIT_TOWER_LOSE_HORDE);
    OutdoorPvPControlZoneHandler::HandleNeutralEventHorde(controlZone);
}

void TFControlZoneHandler::HandleNeutralEventAlliance(GameObject* controlZone)
{
    GetOutdoorPvPTF()->SetAllianceTowersControlled(GetOutdoorPvPTF()->GetAllianceTowersControlled() - 1);
    GetOutdoorPvP()->SendDefenseMessage(OutdoorPvPTFBuffZones[0], TEXT_SPIRIT_TOWER_LOSE_ALLIANCE);
    OutdoorPvPControlZoneHandler::HandleNeutralEventAlliance(controlZone);
}

void TFControlZoneHandler::HandleNeutralEvent(GameObject* controlZone)
{
    controlZone->SetGoArtKit(21);
    controlZone->GetMap()->SetWorldStateValue(_worldstateHorde, 0, false);
    controlZone->GetMap()->SetWorldStateValue(_worldstateAlliance, 0, false);
    controlZone->GetMap()->SetWorldStateValue(_worldstateNeutral, 1, false);
    OutdoorPvPControlZoneHandler::HandleNeutralEvent(controlZone);
}

OutdoorPvPTF* TFControlZoneHandler::GetOutdoorPvPTF() const
{
    return static_cast<OutdoorPvPTF*>(OutdoorPvPControlZoneHandler::GetOutdoorPvP());
}

class OutdoorPvP_terokkar_forest : public OutdoorPvPScript
{
    public:
        OutdoorPvP_terokkar_forest() : OutdoorPvPScript("outdoorpvp_tf") { }

        OutdoorPvP* GetOutdoorPvP(Map* map) const override
        {
            return new OutdoorPvPTF(map);
        }
};

void AddSC_outdoorpvp_tf()
{
    new OutdoorPvP_terokkar_forest();
}
