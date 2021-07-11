/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "Object.h"
#include "Player.h"
#include "BattleGround.h"
#include "BattleGroundMgr.h"
#include "Creature.h"
#include "Language.h"
#include "SpellAuraDefines.h"
#include "World.h"
#include "Group.h"
#include "ObjectGuid.h"
#include "ObjectMgr.h"
#include "Mail.h"
#include "WorldPacket.h"
#include "Util.h"
#include "Formulas.h"
#include "GridNotifiersImpl.h"
#include "Chat.h"

namespace MaNGOS
{
class BattleGroundChatBuilder
{
public:
    BattleGroundChatBuilder(ChatMsg msgtype, int32 textId, Player const* source, va_list* args = nullptr)
        : i_msgtype(msgtype), i_textId(textId), i_source(source), i_args(args) {}
    void operator()(WorldPacket& data, int32 loc_idx)
    {
        char const* text = sObjectMgr.GetMangosString(i_textId, loc_idx);

        ObjectGuid sourceGuid = i_source ? i_source->GetObjectGuid() : ObjectGuid();
        std::string sourceName = i_source ? i_source->GetName() : "";

        if (i_args)
        {
            // we need copy va_list before use or original va_list will corrupted
            va_list ap;
            va_copy(ap, *i_args);

            char str [2048];
            vsnprintf(str, 2048, text, ap);
            va_end(ap);

            ChatHandler::BuildChatPacket(data, i_msgtype, &str[0], LANG_UNIVERSAL, CHAT_TAG_NONE, sourceGuid, sourceName.c_str());
        }
        else
            ChatHandler::BuildChatPacket(data, i_msgtype, text, LANG_UNIVERSAL, CHAT_TAG_NONE, sourceGuid, sourceName.c_str(), sourceGuid, sourceName.c_str());
    }
private:
    ChatMsg i_msgtype;
    int32 i_textId;
    Player const* i_source;
    va_list* i_args;
};

class BattleGroundYellBuilder
{
public:
    BattleGroundYellBuilder(Language language, int32 textId, Creature const* source, va_list* args = nullptr)
        : i_language(language), i_textId(textId), i_source(source), i_args(args) {}
    void operator()(WorldPacket& data, int32 loc_idx)
    {
        char const* text = sObjectMgr.GetMangosString(i_textId, loc_idx);

        if (i_args)
        {
            // we need copy va_list before use or original va_list will corrupted
            va_list ap;
            va_copy(ap, *i_args);

            char str [2048];
            vsnprintf(str, 2048, text, ap);
            va_end(ap);

            ChatHandler::BuildChatPacket(data, CHAT_MSG_MONSTER_YELL, &str[0], i_language, CHAT_TAG_NONE, i_source->GetObjectGuid(), i_source->GetName());
        }
        else
            ChatHandler::BuildChatPacket(data, CHAT_MSG_MONSTER_YELL, text, i_language, CHAT_TAG_NONE, i_source->GetObjectGuid(), i_source->GetName());
    }
private:
    Language i_language;
    int32 i_textId;
    Creature const* i_source;
    va_list* i_args;
};


class BattleGround2ChatBuilder
{
public:
    BattleGround2ChatBuilder(ChatMsg msgtype, int32 textId, Player const* source, int32 arg1, int32 arg2)
        : i_msgtype(msgtype), i_textId(textId), i_source(source), i_arg1(arg1), i_arg2(arg2) {}
    void operator()(WorldPacket& data, int32 loc_idx)
    {
        char const* text = sObjectMgr.GetMangosString(i_textId, loc_idx);
        char const* arg1str = i_arg1 ? sObjectMgr.GetMangosString(i_arg1, loc_idx) : "";
        char const* arg2str = i_arg2 ? sObjectMgr.GetMangosString(i_arg2, loc_idx) : "";

        char str [2048];
        snprintf(str, 2048, text, arg1str, arg2str);

        ObjectGuid targetGuid = i_source  ? i_source ->GetObjectGuid() : ObjectGuid();

        ChatHandler::BuildChatPacket(data, i_msgtype, str, LANG_UNIVERSAL, CHAT_TAG_NONE, targetGuid);
    }
private:
    ChatMsg i_msgtype;
    int32 i_textId;
    Player const* i_source;
    int32 i_arg1;
    int32 i_arg2;
};

class BattleGround2YellBuilder
{
public:
    BattleGround2YellBuilder(Language language, int32 textId, Creature const* source, int32 arg1, int32 arg2)
        : i_language(language), i_textId(textId), i_source(source), i_arg1(arg1), i_arg2(arg2) {}
    void operator()(WorldPacket& data, int32 loc_idx)
    {
        char const* text = sObjectMgr.GetMangosString(i_textId, loc_idx);
        char const* arg1str = i_arg1 ? sObjectMgr.GetMangosString(i_arg1, loc_idx) : "";
        char const* arg2str = i_arg2 ? sObjectMgr.GetMangosString(i_arg2, loc_idx) : "";

        char str [2048];
        snprintf(str, 2048, text, arg1str, arg2str);

        ChatHandler::BuildChatPacket(data, CHAT_MSG_MONSTER_YELL, str, i_language, CHAT_TAG_NONE, i_source ? i_source->GetObjectGuid() : ObjectGuid(), i_source ? i_source->GetName() : "");
    }
private:
    Language i_language;
    int32 i_textId;
    Creature const* i_source;
    int32 i_arg1;
    int32 i_arg2;
};
}                                                           // namespace MaNGOS

template<class Do>
void BattleGround::BroadcastWorker(Do& _do)
{
    for (const auto& itr : m_Players)
        if (Player* pPlayer = ObjectAccessor::FindPlayer(itr.first))
            _do(pPlayer);
}

BattleGround::BattleGround()
{
    m_TypeID            = BATTLEGROUND_TYPE_NONE;
    m_Status            = STATUS_NONE;
    m_ClientInstanceID  = 0;
    m_EndTime           = 0;
    m_BracketId         = BG_BRACKET_ID_NONE;        // use as mark bg template
    m_InvitedAlliance   = 0;
    m_InvitedHorde      = 0;
    m_Winner            = WINNER_NONE;
    m_StartTime         = 0;
    m_Events            = 0;
    m_BuffChange        = false;
    m_Name              = "";
    m_LevelMin          = 0;
    m_LevelMax          = 0;
    m_InBGFreeSlotQueue = false;

    m_MaxPlayersPerTeam = 0;
    m_MaxPlayers        = 0;
    m_MinPlayersPerTeam = 0;
    m_MinPlayers        = 0;

    m_MapId             = 0;
    m_Map               = nullptr;

    m_TeamStartLocX[BG_TEAM_ALLIANCE]   = 0;
    m_TeamStartLocX[BG_TEAM_HORDE]      = 0;

    m_TeamStartLocY[BG_TEAM_ALLIANCE]   = 0;
    m_TeamStartLocY[BG_TEAM_HORDE]      = 0;

    m_TeamStartLocZ[BG_TEAM_ALLIANCE]   = 0;
    m_TeamStartLocZ[BG_TEAM_HORDE]      = 0;

    m_TeamStartLocO[BG_TEAM_ALLIANCE]   = 0;
    m_TeamStartLocO[BG_TEAM_HORDE]      = 0;

    m_BgRaids[BG_TEAM_ALLIANCE]         = nullptr;
    m_BgRaids[BG_TEAM_HORDE]            = nullptr;

    m_PlayersCount[BG_TEAM_ALLIANCE]    = 0;
    m_PlayersCount[BG_TEAM_HORDE]       = 0;

    m_TeamScores[BG_TEAM_ALLIANCE]      = 0;
    m_TeamScores[BG_TEAM_HORDE]         = 0;

    m_PrematureCountDown = false;
    m_PrematureCountDownTimer = 0;

    m_StartDelayTime = 0;
    m_StartDelayTimes[BG_STARTING_EVENT_FIRST]  = BG_START_DELAY_2M;
    m_StartDelayTimes[BG_STARTING_EVENT_SECOND] = BG_START_DELAY_1M;
    m_StartDelayTimes[BG_STARTING_EVENT_THIRD]  = BG_START_DELAY_30S;
    m_StartDelayTimes[BG_STARTING_EVENT_FOURTH] = BG_START_DELAY_NONE;
    //we must set to some default existing values
    m_StartMessageIds[BG_STARTING_EVENT_FIRST]  = 0;
    m_StartMessageIds[BG_STARTING_EVENT_SECOND] = LANG_BG_WS_START_ONE_MINUTE;
    m_StartMessageIds[BG_STARTING_EVENT_THIRD]  = LANG_BG_WS_START_HALF_MINUTE;
    m_StartMessageIds[BG_STARTING_EVENT_FOURTH] = LANG_BG_WS_HAS_BEGUN;
}

BattleGround::~BattleGround()
{
    // remove objects and creatures
    // (this is done automatically in mapmanager update, when the instance is reset after the reset time)

    int size = m_BgObjects.size();
    for (int i = 0; i < size; ++i)
        DelObject(i);

    sBattleGroundMgr.RemoveBattleGround(GetInstanceID(), GetTypeID());
    if (GetInstanceID()) // Do not log deleted battleground templates.
        sLog.out(LOG_BG, "[%u,%u]: winner=%u, duration=%s", GetTypeID(), GetInstanceID(), GetWinner(), secsToTimeString(GetStartTime() / 1000, true).c_str());

    // Pas un BG 'template'
    if (GetBracketId() != BG_BRACKET_ID_NONE)
        sBattleGroundMgr.DeleteClientVisibleInstanceId(GetTypeID(), GetBracketId(), GetClientInstanceID());

    // unload map
    // map can be null at bg destruction
    if (m_Map)
    {
        m_Map->SetUnload();
        m_Map->SetBG(nullptr);
    }
    // remove from bg free slot queue
    this->RemoveFromBGFreeSlotQueue();

    for (const auto& itr : m_PlayerScores)
        delete itr.second;
}

void BattleGround::Update(uint32 diff)
{
    if (!GetPlayersSize())
    {
        // BG is empty
        // if there are no players invited, delete BG
        // this will delete arena or bg object, where any player entered
        // [[   but if you use battleground object again (more battles possible to be played on 1 instance)
        //      then this condition should be removed and code:
        //      if (!GetInvitedCount(HORDE) && !GetInvitedCount(ALLIANCE))
        //          this->AddToFreeBGObjectsQueue(); // not yet implemented
        //      should be used instead of current
        // ]]
        // BattleGround Template instance cannot be updated, because it would be deleted
        if (!GetInvitedCount(HORDE) && !GetInvitedCount(ALLIANCE))
            delete this;

        return;
    }

    /*********************************************************/
    /***           BATTLEGROUND BALLANCE SYSTEM            ***/
    /*********************************************************/

    // if less then minimum players are in on one side, then start premature finish timer
    if (GetTypeID() != BATTLEGROUND_AV && GetStatus() == STATUS_IN_PROGRESS && sBattleGroundMgr.GetPrematureFinishTime() && (GetPlayersCountByTeam(ALLIANCE) < GetMinPlayersPerTeam() || GetPlayersCountByTeam(HORDE) < GetMinPlayersPerTeam()))
    {
        if (!m_PrematureCountDown)
        {
            m_PrematureCountDown = true;
            m_PrematureCountDownTimer = sBattleGroundMgr.GetPrematureFinishTime();
        }
        else if (m_PrematureCountDownTimer < diff)
        {
            // time's up!
            Team winner = TEAM_NONE;
            if (GetPlayersCountByTeam(ALLIANCE) >= GetMinPlayersPerTeam())
                winner = ALLIANCE;
            else if (GetPlayersCountByTeam(HORDE) >= GetMinPlayersPerTeam())
                winner = HORDE;

            EndBattleGround(winner);
            m_PrematureCountDown = false;
        }
        else if (!sBattleGroundMgr.isTesting())
        {
            uint32 newtime = m_PrematureCountDownTimer - diff;
            // announce every minute
            if (newtime > (MINUTE * IN_MILLISECONDS))
            {
                if (newtime / (MINUTE * IN_MILLISECONDS) != m_PrematureCountDownTimer / (MINUTE * IN_MILLISECONDS))
                    PSendMessageToAll(LANG_BATTLEGROUND_PREMATURE_FINISH_WARNING, CHAT_MSG_SYSTEM, nullptr, (uint32)(m_PrematureCountDownTimer / (MINUTE * IN_MILLISECONDS)));
            }
            else
            {
                //announce every 15 seconds
                if (newtime / (15 * IN_MILLISECONDS) != m_PrematureCountDownTimer / (15 * IN_MILLISECONDS))
                    PSendMessageToAll(LANG_BATTLEGROUND_PREMATURE_FINISH_WARNING_SECS, CHAT_MSG_SYSTEM, nullptr, (uint32)(m_PrematureCountDownTimer / IN_MILLISECONDS));
            }
            m_PrematureCountDownTimer = newtime;
        }

    }
    else if (m_PrematureCountDown)
        m_PrematureCountDown = false;

    /*********************************************************/
    /***           BATTLEGROUND STARTING SYSTEM            ***/
    /*********************************************************/

    if (GetStatus() == STATUS_WAIT_JOIN && GetPlayersSize())
    {
        ModifyStartDelayTime(diff);

        if (!(m_Events & BG_STARTING_EVENT_1))
        {
            m_Events |= BG_STARTING_EVENT_1;

            // setup here, only when at least one player has ported to the map
            if (!SetupBattleGround())
            {
                EndNow();
                return;
            }

            StartingEventCloseDoors();
            SetStartDelayTime(m_StartDelayTimes[BG_STARTING_EVENT_FIRST]);
            //first start warning - 2 or 1 minute, only if defined
            if (m_StartMessageIds[BG_STARTING_EVENT_FIRST])
                SendMessageToAll(m_StartMessageIds[BG_STARTING_EVENT_FIRST], CHAT_MSG_BG_SYSTEM_NEUTRAL);
        }
        // After 1 minute or 30 seconds, warning is signalled
        else if (GetStartDelayTime() <= m_StartDelayTimes[BG_STARTING_EVENT_SECOND] && !(m_Events & BG_STARTING_EVENT_2))
        {
            m_Events |= BG_STARTING_EVENT_2;
            SendMessageToAll(m_StartMessageIds[BG_STARTING_EVENT_SECOND], CHAT_MSG_BG_SYSTEM_NEUTRAL);
        }
        // After 30 or 15 seconds, warning is signalled
        else if (GetStartDelayTime() <= m_StartDelayTimes[BG_STARTING_EVENT_THIRD] && !(m_Events & BG_STARTING_EVENT_3))
        {
            m_Events |= BG_STARTING_EVENT_3;
            SendMessageToAll(m_StartMessageIds[BG_STARTING_EVENT_THIRD], CHAT_MSG_BG_SYSTEM_NEUTRAL);
        }
        // delay expired (atfer 2 or 1 minute)
        else if (GetStartDelayTime() <= 0 && !(m_Events & BG_STARTING_EVENT_4))
        {
            m_Events |= BG_STARTING_EVENT_4;

            StartingEventOpenDoors();

            ReturnPlayersToHomeGY();

            SendMessageToAll(m_StartMessageIds[BG_STARTING_EVENT_FOURTH], CHAT_MSG_BG_SYSTEM_NEUTRAL);
            SetStatus(STATUS_IN_PROGRESS);
            SetStartDelayTime(m_StartDelayTimes[BG_STARTING_EVENT_FOURTH]);

            PlaySoundToAll(SOUND_BG_START);

            //Announce BG starting
            if (sWorld.getConfig(CONFIG_BOOL_BATTLEGROUND_QUEUE_ANNOUNCER_START))
                sWorld.SendWorldText(LANG_BG_STARTED_ANNOUNCE_WORLD, GetName(), GetMinLevel(), GetMaxLevel());
        }
    }
    // Despawn des portes apres 2min (preparation) + 1min
    if (!(m_Events & BG_DOORS_DESPAWNED) && GetStatus() == STATUS_IN_PROGRESS && m_StartTime > 180000)
    {
        StartingEventDespawnDoors();
        m_Events |= BG_DOORS_DESPAWNED;
    }

    /*********************************************************/
    /***           BATTLEGROUND ENDING SYSTEM              ***/
    /*********************************************************/

    if (GetStatus() == STATUS_WAIT_LEAVE)
    {
        // remove all players from battleground after 2 minutes
        m_EndTime -= diff;
        if (m_EndTime <= 0)
        {
            m_EndTime = 0;
            BattleGroundPlayerMap::iterator itr, next;
            for (itr = m_Players.begin(); itr != m_Players.end(); itr = next)
            {
                next = itr;
                ++next;
                //itr is erased here!
                RemovePlayerAtLeave(itr->first, true, true);// remove player from BG
                // do not change any battleground's private variables
            }
        }
    }

    //update start time
    m_StartTime += diff;
}

void BattleGround::SetTeamStartLoc(Team team, float X, float Y, float Z, float O)
{
    BattleGroundTeamIndex teamIdx = GetTeamIndexByTeamId(team);
    m_TeamStartLocX[teamIdx] = X;
    m_TeamStartLocY[teamIdx] = Y;
    m_TeamStartLocZ[teamIdx] = Z;
    m_TeamStartLocO[teamIdx] = O;
}

void BattleGround::SendPacketToAll(WorldPacket* packet)
{
    for (const auto& itr : m_Players)
    {
        if (Player* pPlayer = sObjectMgr.GetPlayer(itr.first))
            pPlayer->GetSession()->SendPacket(packet);
        else
            sLog.outError("BattleGround:SendPacketToAll: %s not found!", itr.first.GetString().c_str());
    }
}

void BattleGround::SendPacketToTeam(Team teamId, WorldPacket* packet, Player* sender, bool self)
{
    for (const auto& itr : m_Players)
    {
        Player* pPlayer = sObjectMgr.GetPlayer(itr.first);
        if (!pPlayer)
        {
            sLog.outError("BattleGround:SendPacketToTeam: %s not found!", itr.first.GetString().c_str());
            continue;
        }

        if (!self && sender == pPlayer)
            continue;

        Team team = itr.second.PlayerTeam;
        if (!team) team = pPlayer->GetTeam();

        if (team == teamId)
            pPlayer->GetSession()->SendPacket(packet);
    }
}

void BattleGround::PlaySoundToAll(uint32 SoundID)
{
    WorldPacket data;
    sBattleGroundMgr.BuildPlaySoundPacket(&data, SoundID);
    SendPacketToAll(&data);
}

void BattleGround::PlaySoundToTeam(uint32 SoundID, Team teamId)
{
    WorldPacket data;

    for (const auto& itr : m_Players)
    {
        Player* pPlayer = sObjectMgr.GetPlayer(itr.first);
        if (!pPlayer)
        {
            sLog.outError("BattleGround:PlaySoundToTeam: %s not found!", itr.first.GetString().c_str());
            continue;
        }

        Team team = itr.second.PlayerTeam;
        if (!team) team = pPlayer->GetTeam();

        if (team == teamId)
        {
            sBattleGroundMgr.BuildPlaySoundPacket(&data, SoundID);
            pPlayer->GetSession()->SendPacket(&data);
        }
    }
}

void BattleGround::CastSpellOnTeam(uint32 SpellID, Team teamId)
{
    for (const auto& itr : m_Players)
    {
        Player* pPlayer = sObjectMgr.GetPlayer(itr.first);

        if (!pPlayer)
        {
            sLog.outError("BattleGround:CastSpellOnTeam: %s not found!", itr.first.GetString().c_str());
            continue;
        }

        Team team = itr.second.PlayerTeam;
        if (!team) team = pPlayer->GetTeam();

        if (team == teamId)
            pPlayer->CastSpell(pPlayer, SpellID, true);
    }
}

void BattleGround::RewardHonorToTeam(uint32 Honor, Team teamId)
{
    for (const auto& itr : m_Players)
    {
        Player* pPlayer = sObjectMgr.GetPlayer(itr.first);

        if (!pPlayer)
        {
            sLog.outError("BattleGround:RewardHonorToTeam: %s not found!", itr.first.GetString().c_str());
            continue;
        }

        Team team = itr.second.PlayerTeam;
        if (!team) team = pPlayer->GetTeam();

        if (team == teamId)
            UpdatePlayerScore(pPlayer, SCORE_BONUS_HONOR, Honor);
    }
}

void BattleGround::RewardReputationToTeam(uint32 faction_id, uint32 Reputation, Team teamId)
{
    FactionEntry const* factionEntry = sObjectMgr.GetFactionEntry(faction_id);

    if (!factionEntry)
        return;

    for (const auto& itr : m_Players)
    {
        Player* pPlayer = sObjectMgr.GetPlayer(itr.first);

        if (!pPlayer)
        {
            sLog.outError("BattleGround:RewardReputationToTeam: %s not found!", itr.first.GetString().c_str());
            continue;
        }

        Team team = itr.second.PlayerTeam;
        if (!team) team = pPlayer->GetTeam();

        if (team == teamId)
        {
            int32 rep_change;
            rep_change = pPlayer->CalculateReputationGain(REPUTATION_SOURCE_SPELL, Reputation, faction_id);
            pPlayer->GetReputationMgr().ModifyReputation(factionEntry, rep_change);
        }
    }
}

void BattleGround::UpdateWorldState(uint32 Field, uint32 Value)
{
    WorldPacket data;
    sBattleGroundMgr.BuildUpdateWorldStatePacket(&data, Field, Value);
    SendPacketToAll(&data);
}

void BattleGround::UpdateWorldStateForPlayer(uint32 Field, uint32 Value, Player* Source)
{
    WorldPacket data;
    sBattleGroundMgr.BuildUpdateWorldStatePacket(&data, Field, Value);
    Source->GetSession()->SendPacket(&data);
}

void BattleGround::EndBattleGround(Team winner)
{
    uint32 bgTypeID = BATTLEGROUND_TYPE_NONE;

    if (m_MaxPlayers == 40)
        bgTypeID = BATTLEGROUND_AV;

    RemoveFromBGFreeSlotQueue();

    WorldPacket data;
    int32 winmsg_id = 0;

    if (winner == ALLIANCE)
    {
        winmsg_id = LANG_BG_A_WINS;

        PlaySoundToAll(SOUND_ALLIANCE_WINS);                // alliance wins sound

        SetWinner(WINNER_ALLIANCE);
    }
    else if (winner == HORDE)
    {
        winmsg_id = LANG_BG_H_WINS;

        PlaySoundToAll(SOUND_HORDE_WINS);                   // horde wins sound

        SetWinner(WINNER_HORDE);
    }
    else
        SetWinner(WINNER_NONE);

    SetStatus(STATUS_WAIT_LEAVE);
    //we must set it this way, because end time is sent in packet!
    m_EndTime = TIME_TO_AUTOREMOVE;

    for (const auto& itr : m_Players)
    {
        Team team = itr.second.PlayerTeam;

        Player* pPlayer = sObjectMgr.GetPlayer(itr.first);
        if (!pPlayer)
        {
            sLog.outError("BattleGround:EndBattleGround %s not found!", itr.first.GetString().c_str());
            continue;
        }

        // should remove spirit of redemption
        if (pPlayer->HasAuraType(SPELL_AURA_SPIRIT_OF_REDEMPTION))
            pPlayer->RemoveSpellsCausingAura(SPELL_AURA_MOD_SHAPESHIFT);

        if (!pPlayer->IsAlive())
        {
            pPlayer->ResurrectPlayer(1.0f);
            pPlayer->SpawnCorpseBones();
        }
        else
        {
            //needed cause else in av some creatures will kill the players at the end
            pPlayer->CombatStop();
            pPlayer->GetHostileRefManager().deleteReferences();
        }

        if (team == winner)
            RewardMark(pPlayer, true);
        // World of Warcraft Client Patch 1.8.4 (2005-12-06)
        // - Battles must now last at least ten minutes after the start of the 
        //   battle in order for the losing team to receive a Mark of Honor.
        else if (GetStartTime() > 10 * MINUTE * IN_MILLISECONDS)
            RewardMark(pPlayer, false);

        pPlayer->CombatStopWithPets(true);

        BlockMovement(pPlayer);

        sBattleGroundMgr.BuildPvpLogDataPacket(&data, this);
        pPlayer->GetSession()->SendPacket(&data);

        BattleGroundQueueTypeId bgQueueTypeId = BattleGroundMgr::BGQueueTypeId(GetTypeID());
        sBattleGroundMgr.BuildBattleGroundStatusPacket(&data, this, pPlayer->GetBattleGroundQueueIndex(bgQueueTypeId), STATUS_IN_PROGRESS, TIME_TO_AUTOREMOVE, GetStartTime());
        pPlayer->GetSession()->SendPacket(&data);

        if (LogsDatabase && sWorld.getConfig(CONFIG_BOOL_LOGSDB_BATTLEGROUNDS))
        {
            BattleGroundScoreMap::const_iterator score = m_PlayerScores.find(itr.first);
            if (score != m_PlayerScores.end())
            {
                static SqlStatementID insLogBg;
                SqlStatement logStmt = LogsDatabase.CreateStatement(insLogBg,
                        "INSERT INTO logs_battleground SET "
                        "bgid=?, bgtype=?, bgduration=?, bgteamcount=?, "
                        "playerGuid=?, team=?, deaths=?, honorBonus=?, "
                        "honorableKills=?");

                logStmt.addUInt32(GetInstanceID());
                logStmt.addUInt32(GetTypeID());
                logStmt.addUInt32(GetStartTime() / 1000);
                logStmt.addUInt32(GetPlayersCountByTeam(team));

                logStmt.addUInt32(itr.first);
                logStmt.addUInt32(team);
                logStmt.addUInt32(score->second->Deaths);
                logStmt.addUInt32(score->second->BonusHonor);

                logStmt.addUInt32(score->second->HonorableKills);

                logStmt.Execute();
            }
        }
    }

    if (winmsg_id)
        SendMessageToAll(winmsg_id, CHAT_MSG_BG_SYSTEM_NEUTRAL);
}

uint32 BattleGround::GetBonusHonorFromKill(uint32 kills) const
{
    // BHU is determined by the CP that would be awarded to the highest level in the range
    // if they made an honorable kill on a Rank 1 target
    return kills * (uint32)MaNGOS::Honor::GetHonorGain(GetMaxLevel(), GetMaxLevel(), 1);
}

float BattleGround::GetHonorModifier() {
    // If the game ends in under one hour, less Bonus Honor will be earned from control of mines, graveyards and for the General kill (win).
    float elapsed = (float)GetStartTime() / IN_MILLISECONDS / HOUR;
    return elapsed < 1.0f ? pow(60, elapsed - 1) : 1.0f;
}

uint32 BattleGround::GetBattlemasterEntry() const
{
    switch (GetTypeID())
    {
        case BATTLEGROUND_AV:
            return 15972;
        case BATTLEGROUND_WS:
            return 14623;
        case BATTLEGROUND_AB:
            return 14879;
        default:
            return 0;
    }
}

void BattleGround::RewardMark(Player* pPlayer, bool winner)
{
    if (pPlayer->IsBot())
        return;

    if (winner)
        RewardSpellCast(pPlayer, pPlayer->GetTeamId() ? GetHordeWinSpell() : GetAllianceWinSpell());
    else
        RewardSpellCast(pPlayer, pPlayer->GetTeamId() ? GetHordeLoseSpell() : GetAllianceLoseSpell());
}

void BattleGround::RewardSpellCast(Player* pPlayer, uint32 spell_id)
{
    if (!spell_id)
        return;

    SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(spell_id);
    if (!spellInfo)
    {
        sLog.outError("Battleground reward spell %u does not exist.", spell_id);
        return;
    }

    pPlayer->CastSpell(pPlayer, spellInfo, true);
}

void BattleGround::RewardItem(Player* pPlayer, uint32 item_id, uint32 count)
{
    ItemPosCountVec dest;
    uint32 no_space_count = 0;
    uint8 msg = pPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, item_id, count, &no_space_count);

    if (msg == EQUIP_ERR_ITEM_NOT_FOUND)
    {
        sLog.outErrorDb("Battleground reward item (Entry %u) not exist in `item_template`.", item_id);
        return;
    }

    if (msg != EQUIP_ERR_OK)                                // convert to possible store amount
        count -= no_space_count;

    if (count != 0 && !dest.empty())                        // can add some
        if (Item* item = pPlayer->StoreNewItem(dest, item_id, true, 0))
            pPlayer->SendNewItem(item, count, true, false);

    if (no_space_count > 0)
        SendRewardMarkByMail(pPlayer, item_id, no_space_count);
}

void BattleGround::SendRewardMarkByMail(Player* pPlayer, uint32 mark, uint32 count)
{
    uint32 bmEntry = GetBattlemasterEntry();
    if (!bmEntry)
        return;

    ItemPrototype const* markProto = ObjectMgr::GetItemPrototype(mark);
    if (!markProto)
        return;

    if (Item* markItem = Item::CreateItem(mark, count, pPlayer->GetObjectGuid()))
    {
        // save new item before send
        markItem->SaveToDB();                               // save for prevent lost at next mail load, if send fail then item will deleted

        // subject: item name
        std::string subject = markProto->Name1;
        int loc_idx = pPlayer->GetSession()->GetSessionDbLocaleIndex();
        if (loc_idx >= 0)
            if (ItemLocale const* il = sObjectMgr.GetItemLocale(markProto->ItemId))
                if (il->Name.size() > size_t(loc_idx) && !il->Name[loc_idx].empty())
                    subject = il->Name[loc_idx];

        // text
        std::string textFormat = pPlayer->GetSession()->GetMangosString(LANG_BG_MARK_BY_MAIL);
        char textBuf[300];
        snprintf(textBuf, 300, textFormat.c_str(), GetName(), GetName());

        MailDraft(subject, textBuf)
        .AddItem(markItem)
        .SendMailTo(pPlayer, MailSender(MAIL_CREATURE, bmEntry), MAIL_CHECK_MASK_COPIED, 15 * MINUTE, 1 * DAY);
    }
}

void BattleGround::RewardQuestComplete(Player* pPlayer)
{
    /*
        uint32 quest;
        switch(GetTypeID())
        {
            case BATTLEGROUND_AV:
                quest = SPELL_AV_QUEST_REWARD;
                break;
            case BATTLEGROUND_WS:
                quest = SPELL_WS_QUEST_REWARD;
                break;
            case BATTLEGROUND_AB:
                quest = SPELL_AB_QUEST_REWARD;
                break;
            default:
                return;
        }

        RewardSpellCast(pPlayer, quest);*/
}

void BattleGround::BlockMovement(Player* pPlayer)
{
    pPlayer->SetClientControl(pPlayer, 0);                          // movement disabled NOTE: the effect will be automatically removed by client when the player is teleported from the battleground, so no need to send with uint8(1) in RemovePlayerAtLeave()
}

void BattleGround::RemovePlayerAtLeave(ObjectGuid guid, bool Transport, bool SendPacket)
{
    Team team = GetPlayerTeam(guid);
    bool participant = false;
    // Remove from lists/maps
    BattleGroundPlayerMap::iterator itr = m_Players.find(guid);
    if (itr != m_Players.end())
    {
        UpdatePlayersCountByTeam(team, true);               // -1 player
        m_Players.erase(itr);
        // check if the player was a participant of the match, or only entered through gm command (goname)
        participant = true;
    }

    BattleGroundScoreMap::iterator itr2 = m_PlayerScores.find(guid);
    if (itr2 != m_PlayerScores.end())
    {
        delete itr2->second;                                // delete player's score
        m_PlayerScores.erase(itr2);
    }

    Player* pPlayer = sObjectMgr.GetPlayer(guid);

    // should remove spirit of redemption
    if (pPlayer && pPlayer->HasAuraType(SPELL_AURA_SPIRIT_OF_REDEMPTION))
        pPlayer->RemoveSpellsCausingAura(SPELL_AURA_MOD_SHAPESHIFT);

    if (pPlayer && !pPlayer->IsAlive())                             // resurrect on exit
    {
        pPlayer->ResurrectPlayer(1.0f);
        pPlayer->SpawnCorpseBones();
    }

    RemovePlayer(pPlayer, guid);                                // BG subclass specific code

    if (participant) // if the player was a match participant, remove auras, calc rating, update queue
    {
        BattleGroundTypeId bgTypeId = GetTypeID();
        BattleGroundQueueTypeId bgQueueTypeId = BattleGroundMgr::BGQueueTypeId(GetTypeID());
        if (pPlayer)
        {
            if (!team) team = pPlayer->GetTeam();

            if (SendPacket)
            {
                WorldPacket data;
                sBattleGroundMgr.BuildBattleGroundStatusPacket(&data, this, pPlayer->GetBattleGroundQueueIndex(bgQueueTypeId), STATUS_NONE, 0, 0);
                pPlayer->GetSession()->SendPacket(&data);
            }

            // this call is important, because player, when joins to battleground, this method is not called, so it must be called when leaving bg
            pPlayer->RemoveBattleGroundQueueId(bgQueueTypeId);
        }

        // remove from raid group if player is member
        if (Group* group = GetBgRaid(team))
        {
            if (!group->RemoveMember(guid, 0))              // group was disbanded
            {
                SetBgRaid(team, nullptr);
                delete group;
            }
        }
        DecreaseInvitedCount(team);
        //we should update battleground queue, but only if bg isn't ending
        if (GetStatus() < STATUS_WAIT_LEAVE)
        {
            // a player has left the battleground, so there are free slots -> add to queue
            AddToBGFreeSlotQueue();
            sBattleGroundMgr.ScheduleQueueUpdate(bgQueueTypeId, bgTypeId, GetBracketId());
        }

        // Let others know
        WorldPacket data;
        sBattleGroundMgr.BuildPlayerLeftBattleGroundPacket(&data, guid);
        SendPacketToTeam(team, &data, pPlayer, false);
    }

    if (pPlayer)
    {
        // Do next only if found in battleground
        pPlayer->SetBattleGroundId(0, BATTLEGROUND_TYPE_NONE);  // We're not in BG.
        // reset destination bg team
        pPlayer->SetBGTeam(TEAM_NONE);

        if (Transport && pPlayer->FindMap() == GetBgMap())
            pPlayer->TeleportToBGEntryPoint();

        DETAIL_LOG("BATTLEGROUND: Removed player %s from BattleGround.", pPlayer->GetName());
    }

    //battleground object will be deleted next BattleGround::Update() call
}

// this method is called when no players remains in battleground
void BattleGround::Reset()
{
    SetWinner(WINNER_NONE);
    SetStatus(STATUS_WAIT_QUEUE);
    SetStartTime(0);
    SetEndTime(0);

    m_Events = 0;

    // door-event2 is always 0
    m_ActiveEvents[BG_EVENT_DOOR] = 0;

    if (m_InvitedAlliance > 0 || m_InvitedHorde > 0)
        sLog.outError("BattleGround system: bad counter, m_InvitedAlliance: %d, m_InvitedHorde: %d", m_InvitedAlliance, m_InvitedHorde);

    m_InvitedAlliance = 0;
    m_InvitedHorde = 0;
    m_InBGFreeSlotQueue = false;

    m_Players.clear();

    for (const auto& itr : m_PlayerScores)
        delete itr.second;
    m_PlayerScores.clear();
}

void BattleGround::StartBattleGround()
{
    SetStartTime(0);

    // add BG to free slot queue
    AddToBGFreeSlotQueue();

    // add bg to update list
    // This must be done here, because we need to have already invited some players when first BG::Update() method is executed
    // and it doesn't matter if we call StartBattleGround() more times, because m_BattleGrounds is a map and instance id never changes
    sBattleGroundMgr.AddBattleGround(GetInstanceID(), GetTypeID(), this);
}

void BattleGround::AddPlayer(Player* pPlayer)
{
    // score struct must be created in inherited class

    ObjectGuid guid = pPlayer->GetObjectGuid();
    Team team = pPlayer->GetBGTeam();

    BattleGroundPlayer bp;
    bp.PlayerTeam = team;

    // Add to list/maps
    m_Players[guid] = bp;

    UpdatePlayersCountByTeam(team, false);                  // +1 player

    WorldPacket data;
    sBattleGroundMgr.BuildPlayerJoinedBattleGroundPacket(&data, pPlayer);
    SendPacketToTeam(team, &data, pPlayer, false);

    // setup BG group membership
    PlayerAddedToBGCheckIfBGIsRunning(pPlayer);
    AddOrSetPlayerToCorrectBgGroup(pPlayer, guid, team);

    // Log
    DETAIL_LOG("BATTLEGROUND: Player %s joined the battle.", pPlayer->GetName());
}

/* this method adds player to his team's bg group, or sets his correct group if player is already in bg group */
void BattleGround::AddOrSetPlayerToCorrectBgGroup(Player* pPlayer, ObjectGuid plr_guid, Team team)
{
    if (Group* group = GetBgRaid(team))                     // raid already exist
    {
        if (group->IsMember(plr_guid))
        {
            uint8 subgroup = group->GetMemberGroup(plr_guid);
            pPlayer->SetBattleGroundRaid(group, subgroup);
        }
        else
        {
            group->AddMember(plr_guid, pPlayer->GetName());
            if (Group* originalGroup = pPlayer->GetOriginalGroup())
                if (originalGroup->IsLeader(plr_guid))
                    group->ChangeLeader(plr_guid);
        }
    }
    else                                                    // first player joined
    {
        group = new Group;
        SetBgRaid(team, group);
        group->Create(plr_guid, pPlayer->GetName());
    }
}

/* This method should be called only once ... it adds pointer to queue */
void BattleGround::AddToBGFreeSlotQueue()
{
    // make sure to add only once
    if (!m_InBGFreeSlotQueue)
    {
        sBattleGroundMgr.BGFreeSlotQueue[m_TypeID].push_front(this);
        m_InBGFreeSlotQueue = true;
    }
}

/* This method removes this battleground from free queue - it must be called when deleting battleground - not used now*/
void BattleGround::RemoveFromBGFreeSlotQueue()
{
    // set to be able to re-add if needed
    m_InBGFreeSlotQueue = false;
    BGFreeSlotQueueType& bgFreeSlot = sBattleGroundMgr.BGFreeSlotQueue[m_TypeID];

    for (BGFreeSlotQueueType::iterator itr = bgFreeSlot.begin(); itr != bgFreeSlot.end(); ++itr)
    {
        if ((*itr)->GetInstanceID() == GetInstanceID())
        {
            bgFreeSlot.erase(itr);
            return;
        }
    }
}

// get the number of free slots for team
// returns the number how many players can join battleground to MaxPlayersPerTeam
uint32 BattleGround::GetFreeSlotsForTeam(Team team) const
{
    /*
        //if BG is starting ... invite anyone
    //    if (GetStatus() == STATUS_WAIT_JOIN)
    //        return (GetInvitedCount(Team) < GetMaxPlayersPerTeam()) ? GetMaxPlayersPerTeam() - GetInvitedCount(Team) : 0;
        //if BG is already started .. do not allow to join too much players of one faction
        uint32 otherTeam;
        uint32 otherIn;
        if (Team == ALLIANCE)
        {
            otherTeam = GetInvitedCount(HORDE);
            otherIn = GetPlayersCountByTeam(HORDE);
        }
        else
        {
            otherTeam = GetInvitedCount(ALLIANCE);
            otherIn = GetPlayersCountByTeam(ALLIANCE);
        }
        //if (GetStatus() == STATUS_IN_PROGRESS)
        {
            // difference based on ppl invited (not necessarily entered battle)
            // default: allow 0
            uint32 diff = 0;
            // allow join one person if the sides are equal (to fill up bg to minplayersperteam)
            if (otherTeam == GetInvitedCount(Team))
                diff = 1;
            // allow join more ppl if the other side has more players
            else if (otherTeam > GetInvitedCount(Team))
                diff = otherTeam - GetInvitedCount(Team);

            // difference based on max players per team (don't allow inviting more)
            uint32 diff2 = (GetInvitedCount(Team) < GetMaxPlayersPerTeam()) ? GetMaxPlayersPerTeam() - GetInvitedCount(Team) : 0;

            // difference based on players who already entered
            // default: allow 0
            uint32 diff3 = 0;
            // allow join one person if the sides are equal (to fill up bg minplayersperteam)
            if (otherIn == GetPlayersCountByTeam(Team))
                diff3 = 1;
            // allow join more ppl if the other side has more players
            else if (otherIn > GetPlayersCountByTeam(Team))
                diff3 = otherIn - GetPlayersCountByTeam(Team);
            // or other side has less than minPlayersPerTeam
            else if (GetInvitedCount(Team) <= GetMinPlayersPerTeam())
                diff3 = GetMinPlayersPerTeam() - GetInvitedCount(Team) + 1;

            // return the minimum of the 3 differences

            // min of diff and diff 2
            diff = diff < diff2 ? diff : diff2;

            // min of diff, diff2 and diff3
            return diff < diff3 ? diff : diff3 ;
        }
    */
    //return free slot count to MaxPlayerPerTeam
    if (GetStatus() == STATUS_WAIT_JOIN || GetStatus() == STATUS_IN_PROGRESS)
        return (GetInvitedCount(team) < GetMaxPlayersPerTeam()) ? GetMaxPlayersPerTeam() - GetInvitedCount(team) : 0;

    return 0;
}

bool BattleGround::HasFreeSlots() const
{
    return GetPlayersSize() < GetMaxPlayers();
}

void BattleGround::UpdatePlayerScore(Player* Source, uint32 type, uint32 value)
{
    //this procedure is called from virtual function implemented in bg subclass
    BattleGroundScoreMap::const_iterator itr = m_PlayerScores.find(Source->GetObjectGuid());

    if (itr == m_PlayerScores.end())                        // player not found...
        return;

    switch (type)
    {
        case SCORE_KILLING_BLOWS:                           // Killing blows
            itr->second->KillingBlows += value;
            break;
        case SCORE_DEATHS:                                  // Deaths
            itr->second->Deaths += value;
            break;
        case SCORE_HONORABLE_KILLS:                         // Honorable kills
            itr->second->HonorableKills += value;
            break;
        case SCORE_BONUS_HONOR:                             // Honor bonus
            // reward honor instantly
            if (Source->GetHonorMgr().Add(value, BONUS))
                itr->second->BonusHonor += value;
            break;
        default:
            sLog.outError("BattleGround: Unknown player score type %u", type);
            break;
    }
}

bool BattleGround::AddObject(uint32 type, uint32 entry, float x, float y, float z, float o, float rotation0, float rotation1, float rotation2, float rotation3, uint32 /*respawnTime*/)
{
    // must be created this way, adding to godatamap would add it to the base map of the instance
    // and when loading it (in go::LoadFromDB()), a new guid would be assigned to the object, and a new object would be created
    // so we must create it specific for this instance
    GameObject* go = new GameObject;
    if (!go->Create(GetBgMap()->GenerateLocalLowGuid(HIGHGUID_GAMEOBJECT), entry, GetBgMap(),
                    x, y, z, o, rotation0, rotation1, rotation2, rotation3, GO_ANIMPROGRESS_DEFAULT, GO_STATE_READY))
    {
        sLog.outErrorDb("Gameobject template %u not found in database! BattleGround not created!", entry);
        sLog.outError("Cannot create gameobject template %u! BattleGround not created!", entry);
        delete go;
        return false;
    }
    /*
        uint32 guid = go->GetGUIDLow();

        // without this, UseButtonOrDoor caused the crash, since it tried to get go info from godata
        // iirc that was changed, so adding to go data map is no longer required if that was the only function using godata from GameObject without checking if it existed
        GameObjectData& data = sObjectMgr.NewGOData(guid);

        data.id             = entry;
        data.position.mapId = GetMapId();
        data.position.x     = x;
        data.position.y     = y;
        data.position.z     = z;
        data.orientation    = o;
        data.rotation0      = rotation0;
        data.rotation1      = rotation1;
        data.rotation2      = rotation2;
        data.rotation3      = rotation3;
        data.spawntimesecs  = respawnTime;
        data.spawnMask      = 1;
        data.animprogress   = 100;
        data.go_state       = 1;
    */
    // add to world, so it can be later looked up from HashMapHolder
    go->AddToWorld();
    m_BgObjects[type] = go->GetObjectGuid();
    return true;
}

//some doors aren't despawned so we cannot handle their closing in gameobject::update()
//it would be nice to correctly implement GO_ACTIVATED state and open/close doors in gameobject code
void BattleGround::DoorClose(ObjectGuid guid)
{
    GameObject* obj = GetBgMap()->GetGameObject(guid);
    if (obj)
    {
        //if doors are open, close it
        if (obj->getLootState() == GO_ACTIVATED && obj->GetGoState() != GO_STATE_READY)
        {
            //change state to allow door to be closed
            obj->SetLootState(GO_READY);
            obj->UseDoorOrButton(RESPAWN_ONE_DAY);
        }
    }
    else
        sLog.outError("BattleGround: Door %s not found (cannot close doors)", guid.GetString().c_str());
}

void BattleGround::DoorOpen(ObjectGuid guid)
{
    GameObject* obj = GetBgMap()->GetGameObject(guid);
    if (obj)
    {
        //change state to be sure they will be opened
        obj->SetLootState(GO_READY);
        obj->UseDoorOrButton(RESPAWN_ONE_DAY);
    }
    else
        sLog.outError("BattleGround: Door %s not found! - doors will be closed.", guid.GetString().c_str());
}

void BattleGround::OnObjectDBLoad(Creature* creature)
{
    std::vector<BattleGroundEventIdx> const& eventsVector = sBattleGroundMgr.GetCreatureEventsVector(creature->GetGUIDLow());
    ASSERT(eventsVector.size());
    if (eventsVector[0].event1 == BG_EVENT_NONE)
        return;
    for (const auto& i : eventsVector)
    {
        m_EventObjects[MAKE_PAIR32(i.event1, i.event2)].creatures.push_back(creature->GetObjectGuid());
        if (!IsActiveEvent(i.event1, i.event2))
            SpawnBGCreature(creature->GetObjectGuid(), DESPAWN_FORCED);
    }
}

ObjectGuid BattleGround::GetSingleCreatureGuid(uint8 event1, uint8 event2)
{
    BGCreatures::const_iterator itr = m_EventObjects[MAKE_PAIR32(event1, event2)].creatures.begin();
    if (itr != m_EventObjects[MAKE_PAIR32(event1, event2)].creatures.end())
        return *itr;
    return ObjectGuid();
}

ObjectGuid BattleGround::GetSingleGameObjectGuid(uint8 event1, uint8 event2)
{
    BGObjects::const_iterator itr = m_EventObjects[MAKE_PAIR32(event1, event2)].gameobjects.begin();
    if (itr != m_EventObjects[MAKE_PAIR32(event1, event2)].gameobjects.end())
        return *itr;
    return ObjectGuid();
}

void BattleGround::OnObjectDBLoad(GameObject* obj)
{
    std::vector<BattleGroundEventIdx> const& eventsVector = sBattleGroundMgr.GetGameObjectEventsVector(obj->GetGUIDLow());
    ASSERT(eventsVector.size());
    if (eventsVector[0].event1 == BG_EVENT_NONE)
        return;
    for (const auto& i : eventsVector)
    {
        m_EventObjects[MAKE_PAIR32(i.event1, i.event2)].gameobjects.push_back(obj->GetObjectGuid());
        if (!IsActiveEvent(i.event1, i.event2))
            SpawnBGObject(obj->GetObjectGuid(), RESPAWN_ONE_DAY);
        else
        {
            // it's possible, that doors aren't spawned anymore (wsg)
            if (GetStatus() >= STATUS_IN_PROGRESS && IsDoor(i.event1, i.event2))
                DoorOpen(obj->GetObjectGuid());
        }
    }
}

bool BattleGround::IsDoor(uint8 event1, uint8 event2)
{
    if (event1 == BG_EVENT_DOOR)
    {
        if (event2 > 0)
        {
            sLog.outError("BattleGround too high event2 for event1:%i", event1);
            return false;
        }
        return true;
    }
    return false;
}

void BattleGround::OpenDoorEvent(uint8 event1, uint8 event2 /*=0*/)
{
    if (!IsDoor(event1, event2))
    {
        sLog.outError("BattleGround:OpenDoorEvent this is no door event1:%u event2:%u", event1, event2);
        return;
    }
    if (!IsActiveEvent(event1, event2))                 // maybe already despawned (eye)
    {
        sLog.outError("BattleGround:OpenDoorEvent this event isn't active event1:%u event2:%u", event1, event2);
        return;
    }
    BGObjects::const_iterator itr = m_EventObjects[MAKE_PAIR32(event1, event2)].gameobjects.begin();
    for (; itr != m_EventObjects[MAKE_PAIR32(event1, event2)].gameobjects.end(); ++itr)
        DoorOpen(*itr);
}

void BattleGround::StartingEventDespawnDoors()
{
    if (!IsDoor(BG_EVENT_DOOR, 0))
        return;

    if (!IsActiveEvent(BG_EVENT_DOOR, 0))                 // maybe already despawned (eye)
        return;

    BGObjects::const_iterator itr = m_EventObjects[MAKE_PAIR32(BG_EVENT_DOOR, 0)].gameobjects.begin();
    for (; itr != m_EventObjects[MAKE_PAIR32(BG_EVENT_DOOR, 0)].gameobjects.end(); ++itr)
    {
        GameObject* obj = GetBgMap()->GetGameObject(*itr);
        if (obj)
            obj->AddObjectToRemoveList();
    }
}

void BattleGround::ReturnPlayersToHomeGY()
{
    // return bastards back homie
    for (const auto& itr : m_Players)
    {
        auto player = sObjectMgr.GetPlayer(itr.first);

        if (!player || player->IsGameMaster())
            continue;

        float x, y, z, o;

        GetTeamStartLoc(player->GetTeam(), x, y, z, o);

        // probably distance need some tweaking, but should be ok almost always
        if (!player->IsWithinDist3d(x, y, z, 100.0f))
            player->RepopAtGraveyard();
    }
}

void BattleGround::SpawnEvent(uint8 event1, uint8 event2, bool spawn, bool forced_despawn, uint32 delay)
{
    // stop if we want to spawn something which was already spawned
    // or despawn something which was already despawned
    if (event2 == BG_EVENT_NONE || (spawn && m_ActiveEvents[event1] == event2)
            || (!spawn && m_ActiveEvents[event1] != event2))
        return;

    if (spawn)
    {
        // if event gets spawned, the current active event must get despawned
        SpawnEvent(event1, m_ActiveEvents[event1], false, forced_despawn);
        m_ActiveEvents[event1] = event2;                    // set this event to active
    }
    else
        m_ActiveEvents[event1] = BG_EVENT_NONE;             // no event active if event2 gets despawned

    BGCreatures::const_iterator itr = m_EventObjects[MAKE_PAIR32(event1, event2)].creatures.begin();
    for (; itr != m_EventObjects[MAKE_PAIR32(event1, event2)].creatures.end(); ++itr)
    {
        std::vector<BattleGroundEventIdx> const& eventsVector = sBattleGroundMgr.GetCreatureEventsVector(itr->GetCounter());
        ASSERT(eventsVector.size());
        bool spawnThisCreature = spawn;
        for (const auto& i : eventsVector)
        {
            if (!IsActiveEvent(i.event1, i.event2))
            {
                spawnThisCreature = false;
                break;
            }
        }
        SpawnBGCreature(*itr, spawnThisCreature ? RESPAWN_FORCED : (forced_despawn ? DESPAWN_FORCED : RESPAWN_STOP));
    }

    BGObjects::const_iterator itr2 = m_EventObjects[MAKE_PAIR32(event1, event2)].gameobjects.begin();
    for (; itr2 != m_EventObjects[MAKE_PAIR32(event1, event2)].gameobjects.end(); ++itr2)
        SpawnBGObject(*itr2, (spawn) ? delay : RESPAWN_ONE_DAY);

    OnEventStateChanged(event1, event2, spawn);
}

void BattleGround::SetSpawnEventMode(uint8 event1, uint8 event2, BattleGroundCreatureSpawnMode mode)
{
    if (event2 == BG_EVENT_NONE)
        return;

    bool isSpawnMode = mode == RESPAWN_FORCED;
    BGCreatures::const_iterator itr = m_EventObjects[MAKE_PAIR32(event1, event2)].creatures.begin();
    for (; itr != m_EventObjects[MAKE_PAIR32(event1, event2)].creatures.end(); ++itr)
    {
        std::vector<BattleGroundEventIdx> const& eventsVector = sBattleGroundMgr.GetCreatureEventsVector(itr->GetCounter());
        ASSERT(eventsVector.size());
        bool spawnThisCreature = true;
        for (const auto& i : eventsVector)
        {
            if (!IsActiveEvent(i.event1, i.event2))
            {
                spawnThisCreature = false;
                break;
            }
        }
        if (spawnThisCreature == isSpawnMode)
            SpawnBGCreature(*itr, mode);
    }
}

void BattleGround::SpawnBGObject(ObjectGuid guid, uint32 respawntime)
{
    Map* map = GetBgMap();

    GameObject* obj = map->GetGameObject(guid);
    if (!obj)
        return;
    if (respawntime != RESPAWN_ONE_DAY)
    {
        //we need to change state from GO_JUST_DEACTIVATED to GO_READY in case battleground is starting again
        if (obj->getLootState() == GO_JUST_DEACTIVATED)
            obj->SetLootState(GO_READY);

        if (obj->GetGOInfo()->type != GAMEOBJECT_TYPE_FLAGSTAND)
            obj->SetGoState(GO_STATE_READY);

        obj->SetRespawnTime(respawntime);
        if (obj->GetEntry() == 178786 || obj->GetEntry() == 178787 || obj->GetEntry() == 178788 || obj->GetEntry() == 178789)
            obj->SetRespawnDelay(60);

        if (!obj->GetRespawnTime())
            map->Add(obj);
    }
    else
    {
        if (obj->GetGOInfo()->type != GAMEOBJECT_TYPE_FLAGSTAND)
            obj->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);

        obj->SetRespawnTime(respawntime);
        obj->SetLootState(GO_JUST_DEACTIVATED);
    }
}

void BattleGround::SpawnBGCreature(ObjectGuid guid, BattleGroundCreatureSpawnMode mode)
{
    Map* map = GetBgMap();

    Creature* obj = map->GetCreature(guid);
    if (!obj)
        return;

    if (mode == RESPAWN_FORCED)
    {
        obj->SetRespawnDelay(RESPAWN_2MINUTES);
        if (obj->GetRespawnTime() > time(nullptr))
            obj->SetRespawnTime(1);
    }
    else if (mode == DESPAWN_FORCED)
    {
        obj->SetRespawnDelay(RESPAWN_FOUR_DAYS);
        obj->SetDeathState(JUST_DIED);
        obj->RemoveCorpse();
    }
    else if (mode == RESPAWN_START)
    {
        obj->SetRespawnDelay(RESPAWN_2MINUTES);
        if (obj->GetRespawnTime() > time(nullptr))
            obj->SetRespawnTime(1);
    }
    else if (mode == RESPAWN_STOP)
    {
        obj->SetRespawnDelay(RESPAWN_FOUR_DAYS);
        if (obj->IsDespawned())
        {
            obj->SetDeathState(JUST_DIED);
            obj->RemoveCorpse();
        }
        else
        {
            if (obj->GetRespawnTime() < time(nullptr))
                obj->SetRespawnTime(1);
        }
    }
}

bool BattleGround::DelObject(uint32 type)
{
    if (!m_BgObjects[type])
        return true;

    GameObject* obj = GetBgMap()->GetGameObject(m_BgObjects[type]);
    if (!obj)
    {
        sLog.outError("Can't find gobject: %s", m_BgObjects[type].GetString().c_str());
        return false;
    }

    obj->SetRespawnTime(0);                                 // not save respawn time
    obj->Delete();
    m_BgObjects[type].Clear();
    return true;
}

void BattleGround::SendMessageToAll(int32 entry, ChatMsg type, Player const* source)
{
    MaNGOS::BattleGroundChatBuilder bg_builder(type, entry, source);
    MaNGOS::LocalizedPacketDo<MaNGOS::BattleGroundChatBuilder> bg_do(bg_builder);
    BroadcastWorker(bg_do);
}

void BattleGround::SendYellToAll(int32 entry, uint32 language, ObjectGuid guid)
{
    Creature* source = GetBgMap()->GetCreature(guid);
    if (!source)
        return;
    MaNGOS::BattleGroundYellBuilder bg_builder(Language(language), entry, source);
    MaNGOS::LocalizedPacketDo<MaNGOS::BattleGroundYellBuilder> bg_do(bg_builder);
    BroadcastWorker(bg_do);
}

void BattleGround::PSendMessageToAll(int32 entry, ChatMsg type, Player const* source, ...)
{
    va_list ap;
    va_start(ap, source);

    MaNGOS::BattleGroundChatBuilder bg_builder(type, entry, source, &ap);
    MaNGOS::LocalizedPacketDo<MaNGOS::BattleGroundChatBuilder> bg_do(bg_builder);
    BroadcastWorker(bg_do);

    va_end(ap);
}

void BattleGround::SendMessage2ToAll(int32 entry, ChatMsg type, Player const* source, int32 arg1, int32 arg2)
{
    MaNGOS::BattleGround2ChatBuilder bg_builder(type, entry, source, arg1, arg2);
    MaNGOS::LocalizedPacketDo<MaNGOS::BattleGround2ChatBuilder> bg_do(bg_builder);
    BroadcastWorker(bg_do);
}

void BattleGround::SendYell2ToAll(int32 entry, uint32 language, ObjectGuid guid, int32 arg1, int32 arg2)
{
    Creature* source = GetBgMap()->GetCreature(guid);
    if (!source)
        return;
    MaNGOS::BattleGround2YellBuilder bg_builder(Language(language), entry, source, arg1, arg2);
    MaNGOS::LocalizedPacketDo<MaNGOS::BattleGround2YellBuilder> bg_do(bg_builder);
    BroadcastWorker(bg_do);
}

void BattleGround::EndNow()
{
    uint32 bgTypeID = BATTLEGROUND_TYPE_NONE;

    if (m_MaxPlayers == 40)
        bgTypeID = BATTLEGROUND_AV;

    RemoveFromBGFreeSlotQueue();
    SetStatus(STATUS_WAIT_LEAVE);
    SetEndTime(0);
}

/*
important notice:
buffs aren't spawned/despawned when players captures anything
buffs are in their positions when battleground starts
*/
void BattleGround::HandleTriggerBuff(ObjectGuid go_guid)
{
    GameObject* obj = GetBgMap()->GetGameObject(go_guid);
    if (!obj || obj->GetGoType() != GAMEOBJECT_TYPE_TRAP || !obj->isSpawned())
        return;

    // static buffs are already handled just by database and don't need
    // battleground code
    if (!m_BuffChange)
    {
        obj->SetLootState(GO_JUST_DEACTIVATED);             // can be despawned or destroyed
        return;
    }

    // change buff type, when buff is used:
    // TODO this can be done when poolsystem works for instances
    int32 index = m_BgObjects.size() - 1;
    while (index >= 0 && m_BgObjects[index] != go_guid)
        index--;
    if (index < 0)
    {
        sLog.outError("BattleGround (Type: %u) has buff trigger %s GOType: %u but it hasn't that object in its internal data",
                      GetTypeID(), go_guid.GetString().c_str(), obj->GetGoType());
        return;
    }

    //randomly select new buff
    uint8 buff = urand(0, 2);
    uint32 entry = obj->GetEntry();
    if (m_BuffChange && entry != Buff_Entries[buff])
    {
        //despawn current buff
        SpawnBGObject(m_BgObjects[index], RESPAWN_ONE_DAY);
        //set index for new one
        for (uint8 currBuffTypeIndex = 0; currBuffTypeIndex < 3; ++currBuffTypeIndex)
        {
            if (entry == Buff_Entries[currBuffTypeIndex])
            {
                index -= currBuffTypeIndex;
                index += buff;
            }
        }
    }

    SpawnBGObject(m_BgObjects[index], BUFF_RESPAWN_TIME);
}

void BattleGround::HandleKillPlayer(Player* pVictim, Player* pKiller)
{
    // Nostalrius:
    // 2 appels pour un pretre avec l'esprit de redemption.
    // - Avant le declenchement du talent (Aura 27827)
    // - Apres la fin du buff - a ce moment la killer=nullptr

    // add +1 kills to group and +1 killing_blows to killer
    if (pKiller && pVictim->GetFactionTemplateId() != pKiller->GetFactionTemplateId())
    {
        UpdatePlayerScore(pKiller, SCORE_HONORABLE_KILLS, 1);
        UpdatePlayerScore(pKiller, SCORE_KILLING_BLOWS, 1);

        for (const auto& itr : m_Players)
        {
            Player* pPlayer = sObjectMgr.GetPlayer(itr.first);

            if (!pPlayer || pPlayer == pKiller)
                continue;

            if (pPlayer->GetTeam() == pKiller->GetTeam() && pPlayer->IsAtGroupRewardDistance(pVictim))
                UpdatePlayerScore(pPlayer, SCORE_HONORABLE_KILLS, 1);
        }
    }

    if (!pVictim->HasAura(27827))
    {
        // add +1 deaths
        UpdatePlayerScore(pVictim, SCORE_DEATHS, 1);
        pVictim->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SKINNABLE);
    }
}

// return the player's team based on battlegroundplayer info
// used in same faction arena matches mainly
Team BattleGround::GetPlayerTeam(ObjectGuid guid)
{
    BattleGroundPlayerMap::const_iterator itr = m_Players.find(guid);
    if (itr != m_Players.end())
        return itr->second.PlayerTeam;
    return TEAM_NONE;
}

bool BattleGround::IsPlayerInBattleGround(ObjectGuid guid)
{
    BattleGroundPlayerMap::const_iterator itr = m_Players.find(guid);
    return itr != m_Players.end();
}

void BattleGround::PlayerAddedToBGCheckIfBGIsRunning(Player* pPlayer)
{
    if (GetStatus() != STATUS_WAIT_LEAVE)
        return;

    WorldPacket data;
    BattleGroundQueueTypeId bgQueueTypeId = BattleGroundMgr::BGQueueTypeId(GetTypeID());

    BlockMovement(pPlayer);

    sBattleGroundMgr.BuildPvpLogDataPacket(&data, this);
    pPlayer->GetSession()->SendPacket(&data);

    sBattleGroundMgr.BuildBattleGroundStatusPacket(&data, this, pPlayer->GetBattleGroundQueueIndex(bgQueueTypeId), STATUS_IN_PROGRESS, GetEndTime(), GetStartTime());
    pPlayer->GetSession()->SendPacket(&data);
}

uint32 BattleGround::GetAlivePlayersCountByTeam(Team team) const
{
    int count = 0;
    for (const auto& itr : m_Players)
    {
        if (itr.second.PlayerTeam == team)
        {
            Player* pl = sObjectMgr.GetPlayer(itr.first);
            if (pl && pl->IsAlive())
                ++count;
        }
    }
    return count;
}

void BattleGround::SetBgRaid(Team team, Group* bg_raid)
{
    Group* &old_raid = m_BgRaids[GetTeamIndexByTeamId(team)];

    if (old_raid)
        old_raid->SetBattlegroundGroup(nullptr);

    if (bg_raid)
        bg_raid->SetBattlegroundGroup(this);

    old_raid = bg_raid;
}

WorldSafeLocsEntry const* BattleGround::GetClosestGraveYard(Player* player)
{
    return sObjectMgr.GetClosestGraveYard(player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetMapId(), player->GetTeam());
}

void BattleGround::StopBattleGround()
{
    m_PrematureCountDown      = true;
    m_PrematureCountDownTimer = 100;
}

void BattleGround::HandleCommand(Player* player, ChatHandler* handler, char* args)
{
    std::stringstream in(args);
    std::string commandType;
    in >> commandType;
    if (commandType == "event")
    {
        in >> commandType;
        bool spawn = false;
        bool force = true;
        int event1, event2;
        if (commandType == "spawn")
            spawn = true;
        in >> event1 >> event2;
        in >> commandType;
        if (commandType == "respawn")
            force = false;
        SpawnEvent(event1, event2, spawn, force);
        handler->PSendSysMessage("Event (%u, %u) %s", event1, event2, spawn ? "spawned" : "despawned");
    }
    else if (commandType == "eventi")
    {
        int eventIdx;
        in >> eventIdx;
        handler->PSendSysMessage("Event %u current status: %u", eventIdx, m_ActiveEvents[eventIdx]);
        for (int j = 0; j < 0xFF; ++j)
            if (!m_EventObjects[MAKE_PAIR32(eventIdx, j)].gameobjects.empty() || !m_EventObjects[MAKE_PAIR32(eventIdx, j)].creatures.empty())
                handler->PSendSysMessage("Event (%u, %u): %u gobj / %u creatures", eventIdx, j, m_EventObjects[MAKE_PAIR32(eventIdx, j)].gameobjects.size(), m_EventObjects[MAKE_PAIR32(eventIdx, j)].creatures.size());
    }
}
