/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "Battlefield.h"
#include "BattlefieldMgr.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Map.h"
#include "MapManager.h"
#include "Group.h"
#include "WorldPacket.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CellImpl.h"
#include "CreatureTextMgr.h"

#include "GroupMgr.h"

Battlefield::Battlefield()
{
    m_Timer = 0;
    m_enable = true;
    m_BattlefieldActive = false;
    m_DefenderTeam = TEAM_NEUTRAL;

    m_TypeId = 0;
    m_BattleId = 0;
    m_ZoneId = 0;
    m_MapId = 0;
    m_MaxPlayer = 0;
    m_MinPlayer = 0;
    m_BattleTime = 0;
    m_NoWarBattleTime = 0;
    m_TimeForAcceptInvite = 20;
    m_uiKickDontAcceptTimer = 1000;

    m_uiKickAfkTimer = 1000;

    m_LastResurectTimer = 30000;
    m_StartGroupingTimer = 0;
    m_StartGrouping = false;
    StalkerGuid = 0;
}

Battlefield::~Battlefield()
{
}

void Battlefield::HandlePlayerEnterZone(Player *plr, uint32 /*zone */ )
{
    //If battle is start, 
    //  if it not fully > invite player to join the war
    //  if it fully > announce to player that BF is full and kick after few second if he dont leave
    if (IsWarTime())
    {
        if (m_PlayersInWar[plr->GetTeamId()].size() + m_InvitedPlayers[plr->GetTeamId()].size() < m_MaxPlayer)  //Not fully
        {
            InvitePlayerToWar(plr);
        }
        else                                                //Full
        {
            //TODO:Send packet for announce it to player
            m_PlayersWillBeKick[plr->GetTeamId()][plr->GetGUID()] = time(NULL) + 10;
            InvitePlayerToQueue(plr);
        }
    }
    else
    {
        //If time left is <15 minutes invite player to join queue
        if (m_Timer <= m_StartGroupingTimer)
            InvitePlayerToQueue(plr);
    }

    //Add player in list of player in zone
    m_players[plr->GetTeamId()].insert(plr->GetGUID());
    OnPlayerEnterZone(plr);                                 //for scripting
}

//Called when a player leave the zone
void Battlefield::HandlePlayerLeaveZone(Player *plr, uint32 /*zone */ )
{
    if (IsWarTime())
    {
        //if player is in war list
        if (m_PlayersInWar[plr->GetTeamId()].find(plr->GetGUID()) != m_PlayersInWar[plr->GetTeamId()].end())
        {
            m_PlayersInWar[plr->GetTeamId()].erase(plr->GetGUID());
            plr->GetSession()->SendBfLeaveMessage(m_BattleId);
            if (Group* group = GetGroupPlayer(plr->GetGUID(), plr->GetTeamId()))       // remove from raid group if player is member
            {
                // I think that now is not a hack
                if (!group->RemoveMember(plr->GetGUID()))   // group was disbanded
                {
                    m_Groups[plr->GetTeamId()].erase(group->GetGUID());
                    group->SetBattlefieldGroup(NULL);
                    sGroupMgr->RemoveGroup(group);
                    delete group;
                }
            }
            OnPlayerLeaveWar(plr);                          //For scripting
        }
    }

    for (BfCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        itr->second->HandlePlayerLeave(plr);

    m_InvitedPlayers[plr->GetTeamId()].erase(plr->GetGUID());
    m_PlayersWillBeKick[plr->GetTeamId()].erase(plr->GetGUID());
    m_players[plr->GetTeamId()].erase(plr->GetGUID());
    SendRemoveWorldStates(plr);
    RemovePlayerFromResurrectQueue(plr->GetGUID());
    OnPlayerLeaveZone(plr);                                 //For scripting
}

bool Battlefield::Update(uint32 diff)
{
    //When global timer is end
    if (m_Timer <= diff)
    {
        //Here end of battle by timer
        if (IsWarTime())
            EndBattle(true);
        //Start of battle
        else
            StartBattle();
    }
    else
        m_Timer -= diff;

    //Some times before battle start invite player to queue
    if (!m_StartGrouping && m_Timer <= m_StartGroupingTimer)
    {
        m_StartGrouping = true;
        InvitePlayerInZoneToQueue();
        OnStartGrouping();                                  // for scripting
    }

    bool objective_changed = false;
    if (IsWarTime())
    {
        if (m_uiKickAfkTimer <= diff)
        {
            m_uiKickAfkTimer = 1000;
            KickAfk();
        }
        else
            m_uiKickAfkTimer -= diff;

        //Here kick player witch dont have accept invitation to join the war when time is end (time of windows)
        if (m_uiKickDontAcceptTimer <= diff)
        {
            for (int team = 0; team < 2; team++)
                for (PlayerTimerMap::iterator itr = m_InvitedPlayers[team].begin(); itr != m_InvitedPlayers[team].end(); itr++)
                    if ((*itr).second <= time(NULL))
                        KickPlayerFromBf((*itr).first);
            InvitePlayerInZoneToWar();
            for (int team = 0; team < 2; team++)
                for (PlayerTimerMap::iterator itr = m_PlayersWillBeKick[team].begin(); itr != m_PlayersWillBeKick[team].end(); itr++)
                    if ((*itr).second <= time(NULL))
                        KickPlayerFromBf((*itr).first);

            m_uiKickDontAcceptTimer = 1000;
        }
        else
            m_uiKickDontAcceptTimer -= diff;

        for (BfCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
            if (itr->second->Update(diff))
                objective_changed = true;
    }


    if (m_LastResurectTimer <= diff)
    {
        for (uint8 i = 0; i < m_GraveYardList.size(); i++)
            if (GetGraveYardById(i))
                m_GraveYardList[i]->Resurrect();
        m_LastResurectTimer = RESURRECTION_INTERVAL;
    }
    else
        m_LastResurectTimer -= diff;

    return objective_changed;
}

void Battlefield::InvitePlayerInZoneToQueue()
{
    for (uint8 team = 0; team < 2; ++team)
        for (GuidSet::const_iterator p_itr = m_players[team].begin(); p_itr != m_players[team].end(); ++p_itr)
            if (Player* plr = sObjectMgr->GetPlayer((*p_itr)))
                InvitePlayerToQueue(plr);
}

void Battlefield::InvitePlayerToQueue(Player *plr)
{
    if (m_PlayersInQueue[plr->GetTeamId()].count(plr->GetGUID()))
        return;

    if (m_PlayersInQueue[plr->GetTeam()].size() <= m_MinPlayer || m_PlayersInQueue[plr->GetTeam() == TEAM_ALLIANCE ? TEAM_HORDE : TEAM_ALLIANCE].size() >= m_MinPlayer)
        plr->GetSession()->SendBfInvitePlayerToQueue(m_BattleId);
}

void Battlefield::InvitePlayerInQueueToWar()
{
    for (uint8 team = 0; team < BG_TEAMS_COUNT; ++team)
    {
        for (GuidSet::const_iterator p_itr = m_PlayersInQueue[team].begin(); p_itr != m_PlayersInQueue[team].end(); ++p_itr)
        {
            if (Player* plr = sObjectAccessor->FindPlayer(*p_itr))
            {
                if (m_PlayersInWar[plr->GetTeamId()].size() + m_InvitedPlayers[plr->GetTeamId()].size() < m_MaxPlayer)
                    InvitePlayerToWar(plr);
                else
                {
                    //Full
                }
            }
        }
        m_PlayersInQueue[team].clear();
    }
}

void Battlefield::InvitePlayerInZoneToWar()
{
    for (uint8 team = 0; team < BG_TEAMS_COUNT; ++team)
        for (GuidSet::const_iterator p_itr = m_players[team].begin(); p_itr != m_players[team].end(); ++p_itr)
        {
            if (Player* plr = sObjectMgr->GetPlayer((*p_itr)))
            {
                if (m_PlayersInWar[plr->GetTeamId()].count(plr->GetGUID()) || m_InvitedPlayers[plr->GetTeamId()].count(plr->GetGUID()))
                    continue;
                if (m_PlayersInWar[plr->GetTeamId()].size() + m_InvitedPlayers[plr->GetTeamId()].size() < m_MaxPlayer)
                    InvitePlayerToWar(plr);
                else
                {
                    //full
                    m_PlayersWillBeKick[plr->GetTeamId()][plr->GetGUID()] = time(NULL) + 10;
                }
            }
        }
}

void Battlefield::InvitePlayerToWar(Player *plr)
{
    if (!plr)
        return;

    //TODO : needed ?
    if (plr->isInFlight())
        return;

    if (plr->InArena() || plr->GetBattleground())
    {
        m_PlayersInQueue[plr->GetTeamId()].erase(plr->GetGUID());
        return;
    }

    if (plr->getLevel() < m_MinLevel)
    {
        if (m_PlayersWillBeKick[plr->GetTeamId()].count(plr->GetGUID()) == 0)
            m_PlayersWillBeKick[plr->GetTeamId()][plr->GetGUID()] = time(NULL) + 10;
        return;
    }
    //Check if player is not already in war
    if (m_PlayersInWar[plr->GetTeamId()].count(plr->GetGUID()) || m_InvitedPlayers[plr->GetTeamId()].count(plr->GetGUID()))
        return;

    m_PlayersWillBeKick[plr->GetTeamId()].erase(plr->GetGUID());
    m_InvitedPlayers[plr->GetTeamId()][plr->GetGUID()] = time(NULL) + m_TimeForAcceptInvite;
    plr->GetSession()->SendBfInvitePlayerToWar(m_BattleId, m_ZoneId, m_TimeForAcceptInvite);
}

void Battlefield::InitStalker(uint32 entry, float x, float y, float z, float o)
{
    if (Creature* creature = SpawnCreature(entry, x, y, z, o, TEAM_NEUTRAL))
        StalkerGuid = creature->GetGUID();
    else
        sLog->outError("Battlefield::InitStalker: could not spawn Stalker (Creature entry %u), zone messeges will be un-available", entry);
}

void Battlefield::KickAfk()
{
    for (uint8 team = 0; team < BG_TEAMS_COUNT; ++team)
        for (GuidSet::const_iterator p_itr = m_PlayersInWar[team].begin(); p_itr != m_PlayersInWar[team].end(); ++p_itr)
            if (Player* plr = sObjectAccessor->FindPlayer((*p_itr)))
                if (plr->isAFK())
                    KickPlayerFromBf((*p_itr));
}

void Battlefield::KickPlayerFromBf(uint64 guid)
{
    if (Player* plr = sObjectAccessor->FindPlayer(guid))
        if (plr->GetZoneId() == GetZoneId())
            plr->TeleportTo(KickPosition);
}

void Battlefield::StartBattle()
{
    if (m_BattlefieldActive)
        return;

    for (int team = 0; team < BG_TEAMS_COUNT; team++)
    {
        m_PlayersInWar[team].clear();
        m_Groups[team].clear();
    }

    m_Timer = m_BattleTime;
    m_BattlefieldActive = true;

    InvitePlayerInZoneToWar();
    InvitePlayerInQueueToWar();

    PlaySoundToAll(BF_START);

    OnBattleStart();
}

void Battlefield::EndBattle(bool endbytimer)
{
    m_BattlefieldActive = false;

    m_StartGrouping = false;

    if (!endbytimer)
        SetDefenderTeam(GetAttackerTeam());

    if (GetDefenderTeam() == TEAM_ALLIANCE)
        PlaySoundToAll(BF_ALLIANCE_WINS);                   // alliance wins sound
    else
        PlaySoundToAll(BF_HORDE_WINS);                      // horde wins sound


    OnBattleEnd(endbytimer);

    //reset bf timer
    m_Timer = m_NoWarBattleTime;
    SendInitWorldStatesToAll();
}

void Battlefield::PlaySoundToAll(uint32 SoundID)
{
    WorldPacket data;
    data.Initialize(SMSG_PLAY_SOUND, 4);
    data << uint32(SoundID);

    for (int team = 0; team < BG_TEAMS_COUNT; team++)
        for (GuidSet::const_iterator itr = m_PlayersInWar[team].begin(); itr != m_PlayersInWar[team].end(); ++itr)
        {
            Player *plr = sObjectMgr->GetPlayer((*itr));
            if (plr)
                plr->GetSession()->SendPacket(&data);
        }
}

bool Battlefield::HasPlayer(Player *plr) const
{
    return m_players[plr->GetTeamId()].find(plr->GetGUID()) != m_players[plr->GetTeamId()].end();
}

// Called in WorldSession::HandleBfQueueInviteResponse
void Battlefield::PlayerAcceptInviteToQueue(Player *plr)
{
    // Add player in queueVenez
    m_PlayersInQueue[plr->GetTeamId()].insert(plr->GetGUID());
    // Send notification
    plr->GetSession()->SendBfQueueInviteResponce(m_BattleId, m_ZoneId);
}
// Called in WorldSession::HandleBfExitRequest
void Battlefield::AskToLeaveQueue(Player *plr)
{
    // Remove player from queue
    m_PlayersInQueue[plr->GetTeamId()].erase(plr->GetGUID());
}

// Called in WorldSession::HandleBfEntryInviteResponse
void Battlefield::PlayerAcceptInviteToWar(Player *plr)
{
    if (!IsWarTime())
        return;

    if (AddOrSetPlayerToCorrectBfGroup(plr))
    {
        plr->GetSession()->SendBfEntered(m_BattleId);
        m_PlayersInWar[plr->GetTeamId()].insert(plr->GetGUID());
        m_InvitedPlayers[plr->GetTeamId()].erase(plr->GetGUID());
        //Remove player AFK
        if (plr->isAFK())
            plr->ToggleAFK();

        OnPlayerJoinWar(plr);                               //for scripting
    }
}

void Battlefield::TeamCastSpell(TeamId team, int32 spellId)
{
    if (spellId > 0)
        for (GuidSet::const_iterator p_itr = m_PlayersInWar[team].begin(); p_itr != m_PlayersInWar[team].end(); ++p_itr)
            if (Player* plr = sObjectMgr->GetPlayer((*p_itr)))
                plr->CastSpell(plr, (uint32) spellId, true);
    else
        for (GuidSet::const_iterator p_itr = m_PlayersInWar[team].begin(); p_itr != m_PlayersInWar[team].end(); ++p_itr)
            if (Player* plr = sObjectMgr->GetPlayer((*p_itr)))
                plr->RemoveAuraFromStack((uint32) - spellId);
}

void Battlefield::BroadcastPacketZone(WorldPacket & data) const
{
    for (uint8 team = 0; team < BG_TEAMS_COUNT; ++team)
        for (GuidSet::const_iterator itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
            if (Player* plr = sObjectMgr->GetPlayer((*itr)))
                plr->GetSession()->SendPacket(&data);
}

void Battlefield::BroadcastPacketQueue(WorldPacket & data) const
{
    for (uint8 team = 0; team < BG_TEAMS_COUNT; ++team)
        for (GuidSet::const_iterator itr = m_PlayersInQueue[team].begin(); itr != m_PlayersInQueue[team].end(); ++itr)
            if (Player* plr = sObjectMgr->GetPlayer((*itr)))
                plr->GetSession()->SendPacket(&data);
}

void Battlefield::BroadcastPacketWar(WorldPacket & data) const
{
    for (uint8 team = 0; team < BG_TEAMS_COUNT; ++team)
        for (GuidSet::const_iterator itr = m_PlayersInWar[team].begin(); itr != m_PlayersInWar[team].end(); ++itr)
            if (Player* plr = sObjectMgr->GetPlayer((*itr)))
                plr->GetSession()->SendPacket(&data);
}

WorldPacket Battlefield::BuildWarningAnnPacket(std::string msg)
{
    WorldPacket data(SMSG_MESSAGECHAT, 200);

    data << uint8(CHAT_MSG_RAID_BOSS_EMOTE);
    data << uint32(LANG_UNIVERSAL);
    data << uint64(0);
    data << uint32(0);                                      // 2.1.0
    data << uint32(1);
    data << uint8(0);
    data << uint64(0);
    data << uint32(strlen(msg.c_str()) + 1);
    data << msg.c_str();
    data << uint8(0);

    return data;
}

void Battlefield::SendWarningToAllInZone(uint32 entry)
{
    if (Unit* unit = sObjectAccessor->FindUnit(StalkerGuid))
        if (Creature* stalker = unit->ToCreature())
            // FIXME: replaced CHAT_TYPE_END with CHAT_MSG_BG_SYSTEM_NEUTRAL to fix compile, it's a guessed change :/
            sCreatureTextMgr->SendChat(stalker, (uint8) entry, NULL, CHAT_MSG_BG_SYSTEM_NEUTRAL, LANG_ADDON, TEXT_RANGE_ZONE);
}

/*void Battlefield::SendWarningToAllInWar(int32 entry,...)
{
    const char *format = sObjectMgr->GetTrinityStringForDBCLocale(entry);
    va_list ap;
    char str [1024];
    va_start(ap, entry);
    vsnprintf(str,1024,format, ap);
    va_end(ap);
    std::string msg = (std::string)str;

    WorldPacket data = BuildWarningAnnPacket(msg);
    BroadcastPacketWar(data);
}*/
void Battlefield::SendWarningToPlayer(Player *plr, uint32 entry)
{
    if (!plr)
        return;

    if (Unit* unit = sObjectAccessor->FindUnit(StalkerGuid))
        if (Creature* stalker = unit->ToCreature())
            sCreatureTextMgr->SendChat(stalker, (uint8)entry, plr->GetGUID());
}

void Battlefield::SendUpdateWorldState(uint32 field, uint32 value)
{
    for (uint8 i = 0; i < BG_TEAMS_COUNT; ++i)
        for (GuidSet::iterator itr = m_players[i].begin(); itr != m_players[i].end(); ++itr)
            if (Player *plr = sObjectMgr->GetPlayer((*itr)))
                plr->SendUpdateWorldState(field, value);
}

void Battlefield::RegisterZone(uint32 zoneId)
{
    sBattlefieldMgr.AddZone(zoneId, this);
}

void Battlefield::HideNpc(Creature *p_Creature)
{
    p_Creature->CombatStop();
    p_Creature->SetReactState(REACT_PASSIVE);
    p_Creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
    p_Creature->SetPhaseMask(2, true);
    p_Creature->DisappearAndDie();
    p_Creature->SetVisible(false);
}

void Battlefield::ShowNpc(Creature *p_Creature, bool p_Aggressive)
{
    p_Creature->SetPhaseMask(1, true);
    p_Creature->SetVisible(true);
    p_Creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
    if (!p_Creature->isAlive())
        p_Creature->Respawn(true);
    if (p_Aggressive)
        p_Creature->SetReactState(REACT_AGGRESSIVE);
    else
    {
        p_Creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        p_Creature->SetReactState(REACT_PASSIVE);
    }
}

//*****************************************************
//*******************Group System**********************
//*****************************************************
Group *Battlefield::GetFreeBfRaid(TeamId TeamId)
{
    //if found free group we return it
    for (GuidSet::const_iterator itr = m_Groups[TeamId].begin(); itr != m_Groups[TeamId].end(); ++itr)
        if (Group* group = sGroupMgr->GetGroupByGUID(*itr))
            if (!group->IsFull())
                return group;

    return NULL;
}

Group *Battlefield::GetGroupPlayer(uint64 guid, TeamId TeamId)
{
    for (GuidSet::const_iterator itr = m_Groups[TeamId].begin(); itr != m_Groups[TeamId].end(); ++itr)
        if (Group* group = sGroupMgr->GetGroupByGUID(*itr))
            if (group->IsMember(guid))
                return group;

    return NULL;
}

bool Battlefield::AddOrSetPlayerToCorrectBfGroup(Player *plr)
{
    if (!plr->IsInWorld())
        return false;

    if (Group* group = plr->GetGroup())
        group->RemoveMember(plr->GetGUID());

    Group* group = GetFreeBfRaid(plr->GetTeamId());
    if (!group)
    {
        group = new Group;
        group->SetBattlefieldGroup(this);
        group->Create(plr);
        sGroupMgr->AddGroup(group);
        m_Groups[plr->GetTeamId()].insert(group->GetGUID());
    }
    else if (group->IsMember(plr->GetGUID()))
    {
        uint8 subgroup = group->GetMemberGroup(plr->GetGUID());
        plr->SetBattlegroundOrBattlefieldRaid(group, subgroup);
    }
    else
        group->AddMember(plr);

    return true;
}

//***************End of Group System*******************

//*****************************************************
//***************Spirit Guide System*******************
//*****************************************************
//--------------------
//-Battlefield Method-
//--------------------
BfGraveYard *Battlefield::GetGraveYardById(uint32 id)
{
    if (id < m_GraveYardList.size())
    {
        if (m_GraveYardList[id])
            return m_GraveYardList[id];
        else
            sLog->outError("Battlefield::GetGraveYardById Id:%u not existed", id);
    }
    else
        sLog->outError("Battlefield::GetGraveYardById Id:%u cant be found", id);

    return NULL;
}

WorldSafeLocsEntry const *Battlefield::GetClosestGraveYard(Player *plr)
{
    BfGraveYard* closestGY = NULL;
    float maxdist = -1;
    for (uint8 i = 0; i < m_GraveYardList.size(); i++)
    {
        if (m_GraveYardList[i])
        {
            if (m_GraveYardList[i]->GetControlTeamId() != plr->GetTeamId())
                continue;

            float dist = m_GraveYardList[i]->GetDistance(plr);
            if (dist < maxdist || maxdist < 0)
            {
                closestGY = m_GraveYardList[i];
                maxdist = dist;
            }
        }
    }

    if (closestGY)
        return sWorldSafeLocsStore.LookupEntry(closestGY->GetGraveYardId());

    return NULL;
}

void Battlefield::AddPlayerToResurrectQueue(uint64 npc_guid, uint64 player_guid)
{
    for (uint8 i = 0; i < m_GraveYardList.size(); i++)
    {
        if (!m_GraveYardList[i])
            continue;

        if (m_GraveYardList[i]->HasNpc(npc_guid))
        {
            m_GraveYardList[i]->AddPlayer(player_guid);
            break;
        }
    }
}

void Battlefield::RemovePlayerFromResurrectQueue(uint64 player_guid)
{
    for (uint8 i = 0; i < m_GraveYardList.size(); i++)
    {
        if (!m_GraveYardList[i])
            continue;

        if (m_GraveYardList[i]->HasPlayer(player_guid))
        {
            m_GraveYardList[i]->RemovePlayer(player_guid);
            break;
        }
    }
}

void Battlefield::SendAreaSpiritHealerQueryOpcode(Player *pl, const uint64 &guid)
{
    sLog->outError("SendAreaSpiritHealerQueryOpcode");
    WorldPacket data(SMSG_AREA_SPIRIT_HEALER_TIME, 12);
    uint32 time = m_LastResurectTimer;  // resurrect every 30 seconds

    data << guid << time;
    ASSERT(pl && pl->GetSession());
    pl->GetSession()->SendPacket(&data);
}

bool Battlefield::IncrementQuest(Player *player, uint32 quest, bool complete)
{
    if (!player)
        return false;

    Quest const* pQuest = sObjectMgr->GetQuestTemplate(quest);
    if (!pQuest || player->GetQuestStatus(quest) == QUEST_STATUS_NONE)
        return false;

    if (complete)
    {
        player->CompleteQuest(quest);
        return true;
    }
    else
    {
        for (uint8 i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
        {
            int32 creature = pQuest->ReqCreatureOrGOId[i];
            if (uint32 spell_id = pQuest->ReqSpell[i])
            {
                player->CastedCreatureOrGO(creature, 0, spell_id);
                return true;
            }
            else if (creature > 0)
            {
                player->KilledMonsterCredit(creature, 0);
                return true;
            }
            else if (creature < 0)
            {
                player->CastedCreatureOrGO(creature, 0, 0);
                return true;
            }
        }
    }
    return false;
}

//--------------------
//-BfGraveYard Method-
//--------------------
BfGraveYard::BfGraveYard(Battlefield *Bf)
{
    m_Bf = Bf;
    m_GraveyardId = 0;
    m_ControlTeam = TEAM_NEUTRAL;
    m_SpiritGuide[0] = NULL;
    m_SpiritGuide[1] = NULL;
    m_ResurrectQueue.clear();
}

void BfGraveYard::Init(uint32 horde_entry, uint32 alliance_entry, float x, float y, float z, float o, TeamId startcontrol, uint32 gy)
{
    m_ControlTeam = startcontrol;
    if (Creature* cre = m_Bf->SpawnCreature(horde_entry, x, y, z, o, TEAM_HORDE))
    {
        m_SpiritGuide[TEAM_HORDE] = cre;
        m_SpiritGuide[TEAM_HORDE]->SetReactState(REACT_PASSIVE);
        if (m_ControlTeam == TEAM_ALLIANCE)
            m_SpiritGuide[TEAM_HORDE]->SetVisible(false);
    }
    else
        sLog->outError("BfGraveYard::Init can't spawn horde spiritguide %u", horde_entry);

    if (Creature* cre = m_Bf->SpawnCreature(alliance_entry, x, y, z, o, TEAM_ALLIANCE))
    {
        m_SpiritGuide[TEAM_ALLIANCE] = cre;
        m_SpiritGuide[TEAM_ALLIANCE]->SetReactState(REACT_PASSIVE);
        if (m_ControlTeam == TEAM_HORDE)
            m_SpiritGuide[TEAM_ALLIANCE]->SetVisible(false);
    }
    else
        sLog->outError("BfGraveYard::Init can't spawn alliance spiritguide %u", alliance_entry);

    m_GraveyardId = gy;
}

float BfGraveYard::GetDistance(Player *plr)
{
    const WorldSafeLocsEntry* ws = sWorldSafeLocsStore.LookupEntry(m_GraveyardId);
    return plr->GetDistance2d(ws->x, ws->y);
}

void BfGraveYard::AddPlayer(uint64 player_guid)
{
    if (!m_ResurrectQueue.count(player_guid))
    {
        m_ResurrectQueue.insert(player_guid);

        Player* plr = sObjectMgr->GetPlayer(player_guid);
        if (plr)
            plr->CastSpell(plr, SPELL_WAITING_FOR_RESURRECT, true);
    }
}

void BfGraveYard::RemovePlayer(uint64 player_guid)
{
    m_ResurrectQueue.erase(m_ResurrectQueue.find(player_guid));
    Player* plr = sObjectMgr->GetPlayer(player_guid);

    if (plr)
        plr->RemoveAurasDueToSpell(SPELL_WAITING_FOR_RESURRECT);
}

void BfGraveYard::Resurrect()
{
    if (m_ResurrectQueue.empty())
        return;

    for (GuidSet::const_iterator itr = m_ResurrectQueue.begin(); itr != m_ResurrectQueue.end(); ++itr)
    {
        //Get player object from his guid
        Player* plr = sObjectMgr->GetPlayer(*itr);
        if (!plr)
            continue;

        //Cherck player isinworld and player is on good graveyard
        if (plr->IsInWorld())
            if (m_SpiritGuide[m_ControlTeam])
                m_SpiritGuide[m_ControlTeam]->CastSpell(m_SpiritGuide[m_ControlTeam], SPELL_SPIRIT_HEAL, true);

        //Resurect player
        plr->CastSpell(plr, SPELL_RESURRECTION_VISUAL, true);
        plr->ResurrectPlayer(1.0f);
        plr->CastSpell(plr, 6962, true);
        plr->CastSpell(plr, SPELL_SPIRIT_HEAL_MANA, true);

        sObjectAccessor->ConvertCorpseForPlayer(plr->GetGUID());
    }

    m_ResurrectQueue.clear();
}

//For changing graveyard control
void BfGraveYard::ChangeControl(TeamId team)
{
    //Guide switching
    if (m_SpiritGuide[1 - team])
        m_SpiritGuide[1 - team]->SetVisible(false);
    if (m_SpiritGuide[team])
        m_SpiritGuide[team]->SetVisible(true);

    m_ControlTeam = team;
    //Teleport to other graveyard, player witch were on this graveyard
    RelocateDeadPlayers();
}

void BfGraveYard::RelocateDeadPlayers()
{
    WorldSafeLocsEntry const* ClosestGrave = NULL;
    for (GuidSet::const_iterator itr = m_ResurrectQueue.begin(); itr != m_ResurrectQueue.end(); ++itr)
    {
        Player* plr = sObjectMgr->GetPlayer(*itr);
        if (!plr)
            continue;

        if (ClosestGrave)
            plr->TeleportTo(plr->GetMapId(), ClosestGrave->x, ClosestGrave->y, ClosestGrave->z, plr->GetOrientation());
        else
        {
            ClosestGrave = m_Bf->GetClosestGraveYard(plr);
            if (ClosestGrave)
                plr->TeleportTo(plr->GetMapId(), ClosestGrave->x, ClosestGrave->y, ClosestGrave->z, plr->GetOrientation());
        }
    }
}

//***************End Spirit Guide system***************

//*****************************************************
//**********************Misc***************************
//*****************************************************
//Method for spawn creature on map
Creature *Battlefield::SpawnCreature(uint32 entry, Position pos, TeamId team)
{
    return SpawnCreature(entry, pos.m_positionX, pos.m_positionY, pos.m_positionZ, pos.m_orientation, team);
}

Creature *Battlefield::SpawnCreature(uint32 entry, float x, float y, float z, float o, TeamId team)
{
    //Get map object
    Map* map = const_cast < Map * >(sMapMgr->CreateBaseMap(m_MapId));
    if (!map)
    {
        sLog->outError("Can't create creature entry: %u map not found", entry);
        return 0;
    }

    //Create creature
    Creature* pCreature = new Creature;
    if (!pCreature->Create(sObjectMgr->GenerateLowGuid(HIGHGUID_UNIT), map, PHASEMASK_NORMAL, entry, 0, team, x, y, z, o))
    {
        sLog->outError("Can't create creature entry: %u", entry);
        delete pCreature;
        return NULL;
    }

    pCreature->SetHomePosition(x, y, z, o);

    CreatureTemplate const* cinfo = sObjectMgr->GetCreatureTemplate(entry);
    if (!cinfo)
    {
        sLog->outErrorDb("Battleground::AddCreature: entry %u does not exist.", entry);
        return NULL;
    }
    //force using DB speeds
    pCreature->SetSpeed(MOVE_WALK, cinfo->speed_walk);
    pCreature->SetSpeed(MOVE_RUN, cinfo->speed_run);

    //Set creature in world
    map->Add(pCreature);
    pCreature->setActive(true);

    return pCreature;
}

//Method for spawning gameobject on map
GameObject *Battlefield::SpawnGameObject(uint32 entry, float x, float y, float z, float o)
{
    //Get map object
    Map* map = const_cast < Map * >(sMapMgr->CreateBaseMap(571));
    if (!map)
        return 0;

    //Create gameobject
    GameObject* go = new GameObject;
    if (!go->Create(sObjectMgr->GenerateLowGuid(HIGHGUID_GAMEOBJECT), entry, map, PHASEMASK_NORMAL, x, y, z, o, 0, 0, 0, 0, 100, GO_STATE_READY))
    {
        sLog->outErrorDb("Gameobject template %u not found in database! Battleground not created!", entry);
        sLog->outError("Cannot create gameobject template %u! Battleground not created!", entry);
        delete go;
        return NULL;
    }

    //Add in the world
    map->Add(go);
    go->setActive(true);
    return go;
}

//*****************************************************
//*******************CapturePoint**********************
//*****************************************************

BfCapturePoint::BfCapturePoint(Battlefield *Bf):m_Bf(Bf), m_capturePoint(NULL)
{
    m_team = TEAM_NEUTRAL;
    m_value = 0;
    m_maxValue = 0;
    m_State = BF_CAPTUREPOINT_OBJECTIVESTATE_NEUTRAL;
    m_OldState = BF_CAPTUREPOINT_OBJECTIVESTATE_NEUTRAL;
    m_capturePointEntry = 0;
    m_neutralValuePct = 0;
    m_maxSpeed = 0;
}

bool BfCapturePoint::HandlePlayerEnter(Player *plr)
{
    if (m_capturePoint)
    {
        plr->SendUpdateWorldState(m_capturePoint->GetGOInfo()->capturePoint.worldState1, 1);
        plr->SendUpdateWorldState(m_capturePoint->GetGOInfo()->capturePoint.worldstate2, (uint32) ceil((m_value + m_maxValue) / (2 * m_maxValue) * 100.0f));
        plr->SendUpdateWorldState(m_capturePoint->GetGOInfo()->capturePoint.worldstate3, m_neutralValuePct);
    }
    return m_activePlayers[plr->GetTeamId()].insert(plr->GetGUID()).second;
}

void BfCapturePoint::HandlePlayerLeave(Player *plr)
{
    if (m_capturePoint)
        plr->SendUpdateWorldState(m_capturePoint->GetGOInfo()->capturePoint.worldState1, 0);
    m_activePlayers[plr->GetTeamId()].erase(plr->GetGUID());
}

void BfCapturePoint::SendChangePhase()
{
    if (!m_capturePoint)
        return;

    // send this too, sometimes the slider disappears, dunno why :(
    SendUpdateWorldState(m_capturePoint->GetGOInfo()->capturePoint.worldState1, 1);
    // send these updates to only the ones in this objective
    SendUpdateWorldState(m_capturePoint->GetGOInfo()->capturePoint.worldstate2, (uint32) ceil((m_value + m_maxValue) / (2 * m_maxValue) * 100.0f));
    // send this too, sometimes it resets :S
    SendUpdateWorldState(m_capturePoint->GetGOInfo()->capturePoint.worldstate3, m_neutralValuePct);
}

bool BfCapturePoint::SetCapturePointData(uint32 entry, uint32 /*map */ , float x, float y, float z, float o)
{
    sLog->outDebug(LOG_FILTER_BATTLEFIELD, "Creating capture point %u", entry);

    // check info existence
    GameObjectTemplate const* goinfo = sObjectMgr->GetGameObjectTemplate(entry);
    if (!goinfo || goinfo->type != GAMEOBJECT_TYPE_CAPTURE_POINT)
    {
        sLog->outError("OutdoorPvP: GO %u is not capture point!", entry);
        return false;
    }
    m_capturePoint =  m_Bf->SpawnGameObject(entry, x, y, z, o);
    if (m_capturePoint)
    {
        // get the needed values from goinfo
        m_maxValue = goinfo->capturePoint.maxTime;
        m_maxSpeed = m_maxValue / (goinfo->capturePoint.minTime ? goinfo->capturePoint.minTime : 60);
        m_neutralValuePct = goinfo->capturePoint.neutralPercent;
        m_minValue = m_maxValue * goinfo->capturePoint.neutralPercent / 100;
        m_capturePointEntry = entry;
        if (m_team == TEAM_ALLIANCE)
        {
            m_value = m_maxValue;
            m_State = BF_CAPTUREPOINT_OBJECTIVESTATE_ALLIANCE;
        }
        else
        {
            m_value = -m_maxValue;
            m_State = BF_CAPTUREPOINT_OBJECTIVESTATE_HORDE;
        }
        return true;
    }

    return false;
}

bool BfCapturePoint::DelCapturePoint()
{
    if (m_capturePoint)
    {
        m_capturePoint->SetRespawnTime(0);                  // not save respawn time
        m_capturePoint->Delete();
        m_capturePoint = NULL;
    }

    return true;
}

bool BfCapturePoint::Update(uint32 diff)
{
    if (!m_capturePoint)
        return false;

    float radius = m_capturePoint->GetGOInfo()->capturePoint.radius;

    for (uint8 team = 0; team < 2; ++team)
        for (GuidSet::iterator itr = m_activePlayers[team].begin(); itr != m_activePlayers[team].end(); ++itr)
            if (Player* plr = sObjectMgr->GetPlayer((*itr)))
                if (!m_capturePoint->IsWithinDistInMap(plr, radius) || !plr->IsOutdoorPvPActive())
                    HandlePlayerLeave(plr);

    std::list < Player * >players;
    Trinity::AnyPlayerInObjectRangeCheck checker(m_capturePoint, radius);
    Trinity::PlayerListSearcher < Trinity::AnyPlayerInObjectRangeCheck > searcher(m_capturePoint, players, checker);
    m_capturePoint->VisitNearbyWorldObject(radius, searcher);

    for (std::list < Player * >::iterator itr = players.begin(); itr != players.end(); ++itr)
        if ((*itr)->IsOutdoorPvPActive())
            if (m_activePlayers[(*itr)->GetTeamId()].insert((*itr)->GetGUID()).second)
                HandlePlayerEnter(*itr);

    // get the difference of numbers
    float fact_diff = ((float) m_activePlayers[0].size() - (float) m_activePlayers[1].size()) * diff / BATTLEFIELD_OBJECTIVE_UPDATE_INTERVAL;
    if (!fact_diff)
        return false;

    uint32 Challenger = 0;
    float maxDiff = m_maxSpeed * diff;

    if (fact_diff < 0)
    {
        // horde is in majority, but it's already horde-controlled -> no change
        if (m_State == BF_CAPTUREPOINT_OBJECTIVESTATE_HORDE && m_value <= -m_maxValue)
            return false;

        if (fact_diff < -maxDiff)
            fact_diff = -maxDiff;

        Challenger = HORDE;
    }
    else
    {
        // ally is in majority, but it's already ally-controlled -> no change
        if (m_State == BF_CAPTUREPOINT_OBJECTIVESTATE_ALLIANCE && m_value >= m_maxValue)
            return false;

        if (fact_diff > maxDiff)
            fact_diff = maxDiff;

        Challenger = ALLIANCE;
    }

    float oldValue = m_value;
    TeamId oldTeam = m_team;

    m_OldState = m_State;

    m_value += fact_diff;

    if (m_value < -m_minValue)                              // red
    {
        if (m_value < -m_maxValue)
            m_value = -m_maxValue;
        m_State = BF_CAPTUREPOINT_OBJECTIVESTATE_HORDE;
        m_team = TEAM_HORDE;
    }
    else if (m_value > m_minValue)                          // blue
    {
        if (m_value > m_maxValue)
            m_value = m_maxValue;
        m_State = BF_CAPTUREPOINT_OBJECTIVESTATE_ALLIANCE;
        m_team = TEAM_ALLIANCE;
    }
    else if (oldValue * m_value <= 0)                       // grey, go through mid point
    {
        // if challenger is ally, then n->a challenge
        if (Challenger == ALLIANCE)
            m_State = BF_CAPTUREPOINT_OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE;
        // if challenger is horde, then n->h challenge
        else if (Challenger == HORDE)
            m_State = BF_CAPTUREPOINT_OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE;
        m_team = TEAM_NEUTRAL;
    }
    else                                                    // grey, did not go through mid point
    {
        // old phase and current are on the same side, so one team challenges the other
        if (Challenger == ALLIANCE && (m_OldState == BF_CAPTUREPOINT_OBJECTIVESTATE_HORDE || m_OldState == BF_CAPTUREPOINT_OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE))
            m_State = BF_CAPTUREPOINT_OBJECTIVESTATE_HORDE_ALLIANCE_CHALLENGE;
        else if (Challenger == HORDE && (m_OldState == BF_CAPTUREPOINT_OBJECTIVESTATE_ALLIANCE || m_OldState == BF_CAPTUREPOINT_OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE))
            m_State = BF_CAPTUREPOINT_OBJECTIVESTATE_ALLIANCE_HORDE_CHALLENGE;
        m_team = TEAM_NEUTRAL;
    }

    if (m_value != oldValue)
        SendChangePhase();

    if (m_OldState != m_State)
    {
        //sLog->outError("%u->%u", m_OldState, m_State);
        if (oldTeam != m_team)
            ChangeTeam(oldTeam);
        return true;
    }

    return false;
}

void BfCapturePoint::SendUpdateWorldState(uint32 field, uint32 value)
{
    for (uint8 team = 0; team < 2; ++team)
        for (GuidSet::iterator itr = m_activePlayers[team].begin(); itr != m_activePlayers[team].end(); ++itr)  // send to all players present in the area
            if (Player* plr = sObjectMgr->GetPlayer((*itr)))
                plr->SendUpdateWorldState(field, value);
}

void BfCapturePoint::SendObjectiveComplete(uint32 id, uint64 guid)
{
    uint8 team;
    switch (m_State)
    {
        case BF_CAPTUREPOINT_OBJECTIVESTATE_ALLIANCE:
            team = 0;
            break;
        case BF_CAPTUREPOINT_OBJECTIVESTATE_HORDE:
            team = 1;
            break;
        default:
            return;
    }

    // send to all players present in the area
    for (GuidSet::iterator itr = m_activePlayers[team].begin(); itr != m_activePlayers[team].end(); ++itr)
        if (Player* plr = sObjectMgr->GetPlayer((*itr)))
            plr->KilledMonsterCredit(id, guid);
}

bool BfCapturePoint::IsInsideObjective(Player *plr) const
{
    return m_activePlayers[plr->GetTeamId()].find(plr->GetGUID()) != m_activePlayers[plr->GetTeamId()].end();
}
