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

#include "ScriptMgr.h"
#include "GameObject.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "OutdoorPvPTF.h"
#include "Player.h"
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

go_type const TFCapturePoints[TF_TOWER_NUM] =
{
    { 183104, 530, { -3081.65f, 5335.03f, 17.1853f, -2.146750f }, { 0.0f, 0.0f, 0.878817f, -0.477159f } },
    { 183411, 530, { -2939.90f, 4788.73f, 18.9870f,  2.775070f }, { 0.0f, 0.0f, 0.983255f,  0.182236f } },
    { 183412, 530, { -3174.94f, 4440.97f, 16.2281f,  1.867500f }, { 0.0f, 0.0f, 0.803857f,  0.594823f } },
    { 183413, 530, { -3603.31f, 4529.15f, 20.9077f,  0.994838f }, { 0.0f, 0.0f, 0.477159f,  0.878817f } },
    { 183414, 530, { -3812.37f, 4899.30f, 17.7249f,  0.087266f }, { 0.0f, 0.0f, 0.043619f,  0.999048f } }
};

struct tf_tower_world_state
{
    uint32 n;
    uint32 h;
    uint32 a;
};

tf_tower_world_state const TFTowerWorldStates[TF_TOWER_NUM] =
{
    { 0xa79, 0xa7a, 0xa7b },
    { 0xa7e, 0xa7d, 0xa7c },
    { 0xa82, 0xa81, 0xa80 },
    { 0xa88, 0xa87, 0xa86 },
    { 0xa85, 0xa84, 0xa83 }
};

/*
uint32 const TFTowerPlayerEnterEvents[TF_TOWER_NUM] =
{
    12226,
    12497,
    12486,
    12499,
    12501
};

uint32 const TFTowerPlayerLeaveEvents[TF_TOWER_NUM] =
{
    12225,
    12496,
    12487,
    12498,
    12500
};
*/

OutdoorPvPTF::OutdoorPvPTF()
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
}

OPvPCapturePointTF::OPvPCapturePointTF(OutdoorPvP* pvp, OutdoorPvPTF_TowerType type)
: OPvPCapturePoint(pvp), m_TowerType(type), m_TowerState(TF_TOWERSTATE_N)
{
    SetCapturePointData(TFCapturePoints[type].entry, TFCapturePoints[type].map, TFCapturePoints[type].pos, TFCapturePoints[type].rot);
}

void OPvPCapturePointTF::FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet)
{
    packet.Worldstates.emplace_back(uint32(TFTowerWorldStates[m_TowerType].n), int32((m_TowerState & TF_TOWERSTATE_N) != 0));
    packet.Worldstates.emplace_back(uint32(TFTowerWorldStates[m_TowerType].h), int32((m_TowerState & TF_TOWERSTATE_H) != 0));
    packet.Worldstates.emplace_back(uint32(TFTowerWorldStates[m_TowerType].a), int32((m_TowerState & TF_TOWERSTATE_A) != 0));
}

void OutdoorPvPTF::FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet)
{
    packet.Worldstates.emplace_back(uint32(TF_UI_TOWER_COUNT_H), int32(m_HordeTowersControlled));
    packet.Worldstates.emplace_back(uint32(TF_UI_TOWER_COUNT_A), int32(m_AllianceTowersControlled));
    packet.Worldstates.emplace_back(uint32(TF_UI_TOWERS_CONTROLLED_DISPLAY), int32(!m_IsLocked));
    packet.Worldstates.emplace_back(uint32(TF_UI_LOCKED_TIME_MINUTES_FIRST_DIGIT), int32(first_digit));
    packet.Worldstates.emplace_back(uint32(TF_UI_LOCKED_TIME_MINUTES_SECOND_DIGIT), int32(second_digit));
    packet.Worldstates.emplace_back(uint32(TF_UI_LOCKED_TIME_HOURS), int32(hours_left));

    packet.Worldstates.emplace_back(uint32(TF_UI_LOCKED_DISPLAY_NEUTRAL), int32(m_IsLocked && !m_HordeTowersControlled && !m_AllianceTowersControlled));
    packet.Worldstates.emplace_back(uint32(TF_UI_LOCKED_DISPLAY_HORDE), int32(m_IsLocked && (m_HordeTowersControlled > m_AllianceTowersControlled)));
    packet.Worldstates.emplace_back(uint32(TF_UI_LOCKED_DISPLAY_ALLIANCE), int32(m_IsLocked && (m_HordeTowersControlled < m_AllianceTowersControlled)));

    for (OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        itr->second->FillInitialWorldStates(packet);
}

void OutdoorPvPTF::SendRemoveWorldStates(Player* player)
{
    player->SendUpdateWorldState(TF_UI_TOWER_COUNT_H, uint32(0));
    player->SendUpdateWorldState(TF_UI_TOWER_COUNT_A, uint32(0));
    player->SendUpdateWorldState(TF_UI_TOWERS_CONTROLLED_DISPLAY, uint32(0));

    player->SendUpdateWorldState(TF_UI_LOCKED_TIME_MINUTES_FIRST_DIGIT, uint32(0));
    player->SendUpdateWorldState(TF_UI_LOCKED_TIME_MINUTES_SECOND_DIGIT, uint32(0));
    player->SendUpdateWorldState(TF_UI_LOCKED_TIME_HOURS, uint32(0));

    player->SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_NEUTRAL, uint32(0));
    player->SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_HORDE, uint32(0));
    player->SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_ALLIANCE, uint32(0));

    for (int i = 0; i < TF_TOWER_NUM; ++i)
    {
        player->SendUpdateWorldState(uint32(TFTowerWorldStates[i].n), uint32(0));
        player->SendUpdateWorldState(uint32(TFTowerWorldStates[i].h), uint32(0));
        player->SendUpdateWorldState(uint32(TFTowerWorldStates[i].a), uint32(0));
    }
}

void OPvPCapturePointTF::UpdateTowerState()
{
    m_PvP->SendUpdateWorldState(uint32(TFTowerWorldStates[m_TowerType].n), uint32((m_TowerState & TF_TOWERSTATE_N) != 0));
    m_PvP->SendUpdateWorldState(uint32(TFTowerWorldStates[m_TowerType].h), uint32((m_TowerState & TF_TOWERSTATE_H) != 0));
    m_PvP->SendUpdateWorldState(uint32(TFTowerWorldStates[m_TowerType].a), uint32((m_TowerState & TF_TOWERSTATE_A) != 0));
}

bool OutdoorPvPTF::Update(uint32 diff)
{
    bool changed = OutdoorPvP::Update(diff);

    if (changed)
    {
        if (m_AllianceTowersControlled == TF_TOWER_NUM)
        {
            TeamApplyBuff(TEAM_ALLIANCE, TF_CAPTURE_BUFF);
            m_IsLocked = true;
            SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_NEUTRAL, uint32(0));
            SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_HORDE, uint32(0));
            SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_ALLIANCE, uint32(1));
            SendUpdateWorldState(TF_UI_TOWERS_CONTROLLED_DISPLAY, uint32(0));
        }
        else if (m_HordeTowersControlled == TF_TOWER_NUM)
        {
            TeamApplyBuff(TEAM_HORDE, TF_CAPTURE_BUFF);
            m_IsLocked = true;
            SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_NEUTRAL, uint32(0));
            SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_HORDE, uint32(1));
            SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_ALLIANCE, uint32(0));
            SendUpdateWorldState(TF_UI_TOWERS_CONTROLLED_DISPLAY, uint32(0));
        }
        else
        {
            TeamCastSpell(TEAM_ALLIANCE, -TF_CAPTURE_BUFF);
            TeamCastSpell(TEAM_HORDE, -TF_CAPTURE_BUFF);
        }
        SendUpdateWorldState(TF_UI_TOWER_COUNT_A, m_AllianceTowersControlled);
        SendUpdateWorldState(TF_UI_TOWER_COUNT_H, m_HordeTowersControlled);
    }
    if (m_IsLocked)
    {
        // lock timer is down, release lock
        if (m_LockTimer < diff)
        {
            m_LockTimer = TF_LOCK_TIME;
            m_LockTimerUpdate = 0;
            m_IsLocked = false;
            SendUpdateWorldState(TF_UI_TOWERS_CONTROLLED_DISPLAY, uint32(1));
            SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_NEUTRAL, uint32(0));
            SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_HORDE, uint32(0));
            SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_ALLIANCE, uint32(0));
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

                SendUpdateWorldState(TF_UI_LOCKED_TIME_MINUTES_FIRST_DIGIT, first_digit);
                SendUpdateWorldState(TF_UI_LOCKED_TIME_MINUTES_SECOND_DIGIT, second_digit);
                SendUpdateWorldState(TF_UI_LOCKED_TIME_HOURS, hours_left);
            } else m_LockTimerUpdate -= diff;
            m_LockTimer -= diff;
        }
    }
    return changed;
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

    SetMapFromZone(OutdoorPvPTFBuffZones[0]);

    // add the zones affected by the pvp buff
    for (uint8 i = 0; i < OutdoorPvPTFBuffZonesNum; ++i)
        RegisterZone(OutdoorPvPTFBuffZones[i]);

    AddCapturePoint(new OPvPCapturePointTF(this, TF_TOWER_NW));
    AddCapturePoint(new OPvPCapturePointTF(this, TF_TOWER_N));
    AddCapturePoint(new OPvPCapturePointTF(this, TF_TOWER_NE));
    AddCapturePoint(new OPvPCapturePointTF(this, TF_TOWER_SE));
    AddCapturePoint(new OPvPCapturePointTF(this, TF_TOWER_S));

    return true;
}

bool OPvPCapturePointTF::Update(uint32 diff)
{
    // can update even in locked state if gathers the controlling faction
    bool canupdate = ((((OutdoorPvPTF*)m_PvP)->GetAllianceTowersControlled() > 0) && m_activePlayers[0].size() > m_activePlayers[1].size()) ||
            ((((OutdoorPvPTF*)m_PvP)->GetHordeTowersControlled() > 0) && m_activePlayers[0].size() < m_activePlayers[1].size());
    // if gathers the other faction, then only update if the pvp is unlocked
    canupdate = canupdate || !((OutdoorPvPTF*)m_PvP)->IsLocked();
    return canupdate && OPvPCapturePoint::Update(diff);
}

void OPvPCapturePointTF::ChangeState()
{
    // if changing from controlling alliance to horde
    if (m_OldState == OBJECTIVESTATE_ALLIANCE)
    {
        if (uint32 alliance_towers = ((OutdoorPvPTF*)m_PvP)->GetAllianceTowersControlled())
            ((OutdoorPvPTF*)m_PvP)->SetAllianceTowersControlled(--alliance_towers);
        m_PvP->SendDefenseMessage(OutdoorPvPTFBuffZones[0], TEXT_SPIRIT_TOWER_LOSE_ALLIANCE);
    }
    // if changing from controlling horde to alliance
    else if (m_OldState == OBJECTIVESTATE_HORDE)
    {
        if (uint32 horde_towers = ((OutdoorPvPTF*)m_PvP)->GetHordeTowersControlled())
            ((OutdoorPvPTF*)m_PvP)->SetHordeTowersControlled(--horde_towers);
        m_PvP->SendDefenseMessage(OutdoorPvPTFBuffZones[0], TEXT_SPIRIT_TOWER_LOSE_HORDE);
    }

    uint32 artkit = 21;

    switch (m_State)
    {
        case OBJECTIVESTATE_ALLIANCE:
        {
            m_TowerState = TF_TOWERSTATE_A;
            artkit = 2;
            uint32 alliance_towers = ((OutdoorPvPTF*)m_PvP)->GetAllianceTowersControlled();
            if (alliance_towers < TF_TOWER_NUM)
                ((OutdoorPvPTF*)m_PvP)->SetAllianceTowersControlled(++alliance_towers);

            m_PvP->SendDefenseMessage(OutdoorPvPTFBuffZones[0], TEXT_SPIRIT_TOWER_TAKEN_ALLIANCE);

            for (GuidSet::iterator itr = m_activePlayers[0].begin(); itr != m_activePlayers[0].end(); ++itr)
                if (Player* player = ObjectAccessor::FindPlayer(*itr))
                    player->AreaExploredOrEventHappens(TF_ALLY_QUEST);
            break;
        }
        case OBJECTIVESTATE_HORDE:
        {
            m_TowerState = TF_TOWERSTATE_H;
            artkit = 1;
            uint32 horde_towers = ((OutdoorPvPTF*)m_PvP)->GetHordeTowersControlled();
            if (horde_towers < TF_TOWER_NUM)
                ((OutdoorPvPTF*)m_PvP)->SetHordeTowersControlled(++horde_towers);

            m_PvP->SendDefenseMessage(OutdoorPvPTFBuffZones[0], TEXT_SPIRIT_TOWER_TAKEN_HORDE);

            for (GuidSet::iterator itr = m_activePlayers[1].begin(); itr != m_activePlayers[1].end(); ++itr)
                if (Player* player = ObjectAccessor::FindPlayer(*itr))
                    player->AreaExploredOrEventHappens(TF_HORDE_QUEST);
            break;
        }
        case OBJECTIVESTATE_NEUTRAL:
        case OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE:
        case OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE:
        case OBJECTIVESTATE_ALLIANCE_HORDE_CHALLENGE:
        case OBJECTIVESTATE_HORDE_ALLIANCE_CHALLENGE:
            m_TowerState = TF_TOWERSTATE_N;
            break;
    }

    auto bounds = m_PvP->GetMap()->GetGameObjectBySpawnIdStore().equal_range(m_capturePointSpawnId);
    for (auto itr = bounds.first; itr != bounds.second; ++itr)
        itr->second->SetGoArtKit(artkit);

    UpdateTowerState();
}

class OutdoorPvP_terokkar_forest : public OutdoorPvPScript
{
    public:
        OutdoorPvP_terokkar_forest() : OutdoorPvPScript("outdoorpvp_tf") { }

        OutdoorPvP* GetOutdoorPvP() const override
        {
            return new OutdoorPvPTF();
        }
};

void AddSC_outdoorpvp_tf()
{
    new OutdoorPvP_terokkar_forest();
}
