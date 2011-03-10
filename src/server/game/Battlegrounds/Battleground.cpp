/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "Player.h"
#include "ObjectMgr.h"
#include "World.h"
#include "WorldPacket.h"

#include "ArenaTeam.h"
#include "Battleground.h"
#include "BattlegroundMgr.h"
#include "Creature.h"
#include "Formulas.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "Language.h"
#include "MapManager.h"
#include "Object.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "Util.h"

namespace Trinity
{
    class BattlegroundChatBuilder
    {
        public:
            BattlegroundChatBuilder(ChatMsg msgtype, int32 textId, Player const* source, va_list* args = NULL)
                : i_msgtype(msgtype), i_textId(textId), i_source(source), i_args(args) {}
            void operator()(WorldPacket& data, LocaleConstant loc_idx)
            {
                char const* text = sObjectMgr->GetTrinityString(i_textId,loc_idx);

                if (i_args)
                {
                    // we need copy va_list before use or original va_list will corrupted
                    va_list ap;
                    va_copy(ap,*i_args);

                    char str [2048];
                    vsnprintf(str,2048,text, ap);
                    va_end(ap);

                    do_helper(data,&str[0]);
                }
                else
                    do_helper(data,text);
            }
        private:
            void do_helper(WorldPacket& data, char const* text)
            {
                uint64 target_guid = i_source  ? i_source ->GetGUID() : 0;

                data << uint8(i_msgtype);
                data << uint32(LANG_UNIVERSAL);
                data << uint64(target_guid);                // there 0 for BG messages
                data << uint32(0);                          // can be chat msg group or something
                data << uint64(target_guid);
                data << uint32(strlen(text)+1);
                data << text;
                data << uint8(i_source ? i_source->chatTag() : uint8(0));
            }

            ChatMsg i_msgtype;
            int32 i_textId;
            Player const* i_source;
            va_list* i_args;
    };

    class Battleground2ChatBuilder
    {
        public:
            Battleground2ChatBuilder(ChatMsg msgtype, int32 textId, Player const* source, int32 arg1, int32 arg2)
                : i_msgtype(msgtype), i_textId(textId), i_source(source), i_arg1(arg1), i_arg2(arg2) {}
            void operator()(WorldPacket& data, LocaleConstant loc_idx)
            {
                char const* text = sObjectMgr->GetTrinityString(i_textId,loc_idx);
                char const* arg1str = i_arg1 ? sObjectMgr->GetTrinityString(i_arg1,loc_idx) : "";
                char const* arg2str = i_arg2 ? sObjectMgr->GetTrinityString(i_arg2,loc_idx) : "";

                char str [2048];
                snprintf(str,2048,text, arg1str, arg2str);

                uint64 target_guid = i_source  ? i_source ->GetGUID() : 0;

                data << uint8(i_msgtype);
                data << uint32(LANG_UNIVERSAL);
                data << uint64(target_guid);                // there 0 for BG messages
                data << uint32(0);                          // can be chat msg group or something
                data << uint64(target_guid);
                data << uint32(strlen(str)+1);
                data << str;
                data << uint8(i_source ? i_source->chatTag() : uint8(0));
            }
        private:

            ChatMsg i_msgtype;
            int32 i_textId;
            Player const* i_source;
            int32 i_arg1;
            int32 i_arg2;
    };
}                                                           // namespace Trinity

template<class Do>
void Battleground::BroadcastWorker(Do& _do)
{
    for (BattlegroundPlayerMap::const_iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
        if (Player *plr = ObjectAccessor::FindPlayer(MAKE_NEW_GUID(itr->first, 0, HIGHGUID_PLAYER)))
            _do(plr);
}

Battleground::Battleground()
{
    m_TypeID            = BattlegroundTypeId(0);
    m_RandomTypeID      = BattlegroundTypeId(0);
    m_InstanceID        = 0;
    m_Status            = STATUS_NONE;
    m_ClientInstanceID  = 0;
    m_EndTime           = 0;
    m_LastResurrectTime = 0;
    m_BracketId         = BG_BRACKET_ID_FIRST;
    m_InvitedAlliance   = 0;
    m_InvitedHorde      = 0;
    m_ArenaType         = 0;
    m_IsArena           = false;
    m_Winner            = 2;
    m_StartTime         = 0;
    m_ResetStatTimer    = 0;
    m_Events            = 0;
    m_IsRated           = false;
    m_BuffChange        = false;
    m_IsRandom          = false;
    m_Name              = "";
    m_LevelMin          = 0;
    m_LevelMax          = 0;
    m_InBGFreeSlotQueue = false;
    m_SetDeleteThis     = false;

    m_MaxPlayersPerTeam = 0;
    m_MaxPlayers        = 0;
    m_MinPlayersPerTeam = 0;
    m_MinPlayers        = 0;

    m_MapId             = 0;
    m_Map               = NULL;

    m_TeamStartLocX[BG_TEAM_ALLIANCE]   = 0;
    m_TeamStartLocX[BG_TEAM_HORDE]      = 0;

    m_TeamStartLocY[BG_TEAM_ALLIANCE]   = 0;
    m_TeamStartLocY[BG_TEAM_HORDE]      = 0;

    m_TeamStartLocZ[BG_TEAM_ALLIANCE]   = 0;
    m_TeamStartLocZ[BG_TEAM_HORDE]      = 0;

    m_TeamStartLocO[BG_TEAM_ALLIANCE]   = 0;
    m_TeamStartLocO[BG_TEAM_HORDE]      = 0;

    m_ArenaTeamIds[BG_TEAM_ALLIANCE]   = 0;
    m_ArenaTeamIds[BG_TEAM_HORDE]      = 0;

    m_ArenaTeamRatingChanges[BG_TEAM_ALLIANCE]   = 0;
    m_ArenaTeamRatingChanges[BG_TEAM_HORDE]      = 0;

    m_BgRaids[BG_TEAM_ALLIANCE]         = NULL;
    m_BgRaids[BG_TEAM_HORDE]            = NULL;

    m_PlayersCount[BG_TEAM_ALLIANCE]    = 0;
    m_PlayersCount[BG_TEAM_HORDE]       = 0;

    m_TeamScores[BG_TEAM_ALLIANCE]      = 0;
    m_TeamScores[BG_TEAM_HORDE]         = 0;

    m_PrematureCountDown = false;

    m_HonorMode = BG_NORMAL;

    m_StartDelayTimes[BG_STARTING_EVENT_FIRST]  = BG_START_DELAY_2M;
    m_StartDelayTimes[BG_STARTING_EVENT_SECOND] = BG_START_DELAY_1M;
    m_StartDelayTimes[BG_STARTING_EVENT_THIRD]  = BG_START_DELAY_30S;
    m_StartDelayTimes[BG_STARTING_EVENT_FOURTH] = BG_START_DELAY_NONE;
    //we must set to some default existing values
    m_StartMessageIds[BG_STARTING_EVENT_FIRST]  = LANG_BG_WS_START_TWO_MINUTES;
    m_StartMessageIds[BG_STARTING_EVENT_SECOND] = LANG_BG_WS_START_ONE_MINUTE;
    m_StartMessageIds[BG_STARTING_EVENT_THIRD]  = LANG_BG_WS_START_HALF_MINUTE;
    m_StartMessageIds[BG_STARTING_EVENT_FOURTH] = LANG_BG_WS_HAS_BEGUN;
}

Battleground::~Battleground()
{
    // remove objects and creatures
    // (this is done automatically in mapmanager update, when the instance is reset after the reset time)
    int size = m_BgCreatures.size();
    for (int i = 0; i < size; ++i)
        DelCreature(i);

    size = m_BgObjects.size();
    for (int i = 0; i < size; ++i)
        DelObject(i);

    sBattlegroundMgr->RemoveBattleground(GetInstanceID(), GetTypeID());
    // unload map
    if (m_Map)
        m_Map->SetUnload();
    // remove from bg free slot queue
    this->RemoveFromBGFreeSlotQueue();

    for (BattlegroundScoreMap::const_iterator itr = m_PlayerScores.begin(); itr != m_PlayerScores.end(); ++itr)
        delete itr->second;
}

void Battleground::Update(uint32 diff)
{
    if (!GetPlayersSize())
    {
        //BG is empty
        // if there are no players invited, delete BG
        // this will delete arena or bg object, where any player entered
        // [[   but if you use battleground object again (more battles possible to be played on 1 instance)
        //      then this condition should be removed and code:
        //      if (!GetInvitedCount(HORDE) && !GetInvitedCount(ALLIANCE))
        //          this->AddToFreeBGObjectsQueue(); // not yet implemented
        //      should be used instead of current
        // ]]
        // Battleground Template instance cannot be updated, because it would be deleted
        if (!GetInvitedCount(HORDE) && !GetInvitedCount(ALLIANCE))
            m_SetDeleteThis = true;
        return;
    }

    // remove offline players from bg after 5 minutes
    if (!m_OfflineQueue.empty())
    {
        BattlegroundPlayerMap::iterator itr = m_Players.find(*(m_OfflineQueue.begin()));
        if (itr != m_Players.end())
        {
            if (itr->second.OfflineRemoveTime <= sWorld->GetGameTime())
            {
                RemovePlayerAtLeave(itr->first, true, true);// remove player from BG
                m_OfflineQueue.pop_front();                 // remove from offline queue
                //do not use itr for anything, because it is erased in RemovePlayerAtLeave()
            }
        }
    }

    /*********************************************************/
    /***        BATTLEGROUND RESSURECTION SYSTEM           ***/
    /*********************************************************/

    //this should be handled by spell system
    m_LastResurrectTime += diff;
    if (m_LastResurrectTime >= RESURRECTION_INTERVAL)
    {
        if (GetReviveQueueSize())
        {
            for (std::map<uint64, std::vector<uint64> >::iterator itr = m_ReviveQueue.begin(); itr != m_ReviveQueue.end(); ++itr)
            {
                Creature *sh = NULL;
                for (std::vector<uint64>::const_iterator itr2 = (itr->second).begin(); itr2 != (itr->second).end(); ++itr2)
                {
                    Player *plr = sObjectMgr->GetPlayer(*itr2);
                    if (!plr)
                        continue;

                    if (!sh && plr->IsInWorld())
                    {
                        sh = plr->GetMap()->GetCreature(itr->first);
                        // only for visual effect
                        if (sh)
                            // Spirit Heal, effect 117
                            sh->CastSpell(sh, SPELL_SPIRIT_HEAL, true);
                    }

                    // Resurrection visual
                    plr->CastSpell(plr, SPELL_RESURRECTION_VISUAL, true);
                    m_ResurrectQueue.push_back(*itr2);
                }
                (itr->second).clear();
            }

            m_ReviveQueue.clear();
            m_LastResurrectTime = 0;
        }
        else
            // queue is clear and time passed, just update last resurrection time
            m_LastResurrectTime = 0;
    }
    else if (m_LastResurrectTime > 500)    // Resurrect players only half a second later, to see spirit heal effect on NPC
    {
        for (std::vector<uint64>::const_iterator itr = m_ResurrectQueue.begin(); itr != m_ResurrectQueue.end(); ++itr)
        {
            Player *plr = sObjectMgr->GetPlayer(*itr);
            if (!plr)
                continue;
            plr->ResurrectPlayer(1.0f);
            plr->CastSpell(plr, 6962, true);
            plr->CastSpell(plr, SPELL_SPIRIT_HEAL_MANA, true);
            sObjectAccessor->ConvertCorpseForPlayer(*itr);
        }
        m_ResurrectQueue.clear();
    }

    /*********************************************************/
    /***           BATTLEGROUND BALLANCE SYSTEM            ***/
    /*********************************************************/

    // if less then minimum players are in on one side, then start premature finish timer
    if (GetStatus() == STATUS_IN_PROGRESS && !isArena() && sBattlegroundMgr->GetPrematureFinishTime() && (GetPlayersCountByTeam(ALLIANCE) < GetMinPlayersPerTeam() || GetPlayersCountByTeam(HORDE) < GetMinPlayersPerTeam()))
    {
        if (!m_PrematureCountDown)
        {
            m_PrematureCountDown = true;
            m_PrematureCountDownTimer = sBattlegroundMgr->GetPrematureFinishTime();
        }
        else if (m_PrematureCountDownTimer < diff)
        {
            // time's up!
            uint32 winner = 0;
            if (GetPlayersCountByTeam(ALLIANCE) >= GetMinPlayersPerTeam())
                winner = ALLIANCE;
            else if (GetPlayersCountByTeam(HORDE) >= GetMinPlayersPerTeam())
                winner = HORDE;

            EndBattleground(winner);
            m_PrematureCountDown = false;
        }
        else if (!sBattlegroundMgr->isTesting())
        {
            uint32 newtime = m_PrematureCountDownTimer - diff;
            // announce every minute
            if (newtime > (MINUTE * IN_MILLISECONDS))
            {
                if (newtime / (MINUTE * IN_MILLISECONDS) != m_PrematureCountDownTimer / (MINUTE * IN_MILLISECONDS))
                    PSendMessageToAll(LANG_BATTLEGROUND_PREMATURE_FINISH_WARNING, CHAT_MSG_SYSTEM, NULL, (uint32)(m_PrematureCountDownTimer / (MINUTE * IN_MILLISECONDS)));
            }
            else
            {
                //announce every 15 seconds
                if (newtime / (15 * IN_MILLISECONDS) != m_PrematureCountDownTimer / (15 * IN_MILLISECONDS))
                    PSendMessageToAll(LANG_BATTLEGROUND_PREMATURE_FINISH_WARNING_SECS, CHAT_MSG_SYSTEM, NULL, (uint32)(m_PrematureCountDownTimer / IN_MILLISECONDS));
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

        if (m_ResetStatTimer <= 5000)
        {
            m_ResetStatTimer = 0;
            for (BattlegroundPlayerMap::const_iterator itr = GetPlayers().begin(); itr != GetPlayers().end(); ++itr)
                if (Player *plr = sObjectMgr->GetPlayer(itr->first))
                    plr->ResetAllPowers();
        }

        if (!(m_Events & BG_STARTING_EVENT_1))
        {
            m_Events |= BG_STARTING_EVENT_1;

            // setup here, only when at least one player has ported to the map
            if (!SetupBattleground())
            {
                EndNow();
                return;
            }

            StartingEventCloseDoors();
            SetStartDelayTime(m_StartDelayTimes[BG_STARTING_EVENT_FIRST]);
            //first start warning - 2 or 1 minute
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

            SendWarningToAll(m_StartMessageIds[BG_STARTING_EVENT_FOURTH]);
            SetStatus(STATUS_IN_PROGRESS);
            SetStartDelayTime(m_StartDelayTimes[BG_STARTING_EVENT_FOURTH]);

            //remove preparation
            if (isArena())
            {
                //TODO : add arena sound PlaySoundToAll(SOUND_ARENA_START);

                for (BattlegroundPlayerMap::const_iterator itr = GetPlayers().begin(); itr != GetPlayers().end(); ++itr)
                    if (Player *plr = sObjectMgr->GetPlayer(itr->first))
                    {
                        // BG Status packet
                        WorldPacket status;
                        BattlegroundQueueTypeId bgQueueTypeId = sBattlegroundMgr->BGQueueTypeId(m_TypeID, GetArenaType());
                        uint32 queueSlot = plr->GetBattlegroundQueueIndex(bgQueueTypeId);
                        sBattlegroundMgr->BuildBattlegroundStatusPacket(&status, this, queueSlot, STATUS_IN_PROGRESS, 0, GetStartTime(), GetArenaType());
                        plr->GetSession()->SendPacket(&status);

                        plr->RemoveAurasDueToSpell(SPELL_ARENA_PREPARATION);
                        plr->ResetAllPowers();
                        // remove auras with duration lower than 30s
                        Unit::AuraApplicationMap & auraMap = plr->GetAppliedAuras();
                        for (Unit::AuraApplicationMap::iterator iter = auraMap.begin(); iter != auraMap.end();)
                        {
                            AuraApplication * aurApp = iter->second;
                            Aura * aura = aurApp->GetBase();
                            if (!aura->IsPermanent()
                                && aura->GetDuration() <= 30*IN_MILLISECONDS
                                && aurApp->IsPositive()
                                && (!(aura->GetSpellProto()->Attributes & SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY))
                                && (!aura->HasEffectType(SPELL_AURA_MOD_INVISIBILITY)))
                                plr->RemoveAura(iter);
                            else
                                ++iter;
                        }
                    }

                CheckArenaWinConditions();
            }
            else
            {
                PlaySoundToAll(SOUND_BG_START);

                for (BattlegroundPlayerMap::const_iterator itr = GetPlayers().begin(); itr != GetPlayers().end(); ++itr)
                    if (Player* plr = sObjectMgr->GetPlayer(itr->first))
                    {
                        plr->RemoveAurasDueToSpell(SPELL_PREPARATION);
                        plr->ResetAllPowers();
                    }
                //Announce BG starting
                if (sWorld->getBoolConfig(CONFIG_BATTLEGROUND_QUEUE_ANNOUNCER_ENABLE))
                {
                    sWorld->SendWorldText(LANG_BG_STARTED_ANNOUNCE_WORLD, GetName(), GetMinLevel(), GetMaxLevel());
                }
            }
        }
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
            BattlegroundPlayerMap::iterator itr, next;
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

    // Update start time and reset stats timer
    m_StartTime += diff;
    m_ResetStatTimer += diff;
}

void Battleground::SetTeamStartLoc(uint32 TeamID, float X, float Y, float Z, float O)
{
    BattlegroundTeamId idx = GetTeamIndexByTeamId(TeamID);
    m_TeamStartLocX[idx] = X;
    m_TeamStartLocY[idx] = Y;
    m_TeamStartLocZ[idx] = Z;
    m_TeamStartLocO[idx] = O;
}

void Battleground::SendPacketToAll(WorldPacket *packet)
{
    for (BattlegroundPlayerMap::const_iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
    {
        if (itr->second.OfflineRemoveTime)
            continue;
        Player *plr = sObjectMgr->GetPlayer(itr->first);
        if (plr)
            plr->GetSession()->SendPacket(packet);
        else
            sLog->outError("Battleground:SendPacketToAll: Player (GUID: %u) not found!", GUID_LOPART(itr->first));
    }
}

void Battleground::SendPacketToTeam(uint32 TeamID, WorldPacket *packet, Player *sender, bool self)
{
    for (BattlegroundPlayerMap::const_iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
    {
        if (itr->second.OfflineRemoveTime)
            continue;
        Player *plr = sObjectMgr->GetPlayer(itr->first);
        if (!plr)
        {
            sLog->outError("Battleground:SendPacketToTeam: Player (GUID: %u) not found!", GUID_LOPART(itr->first));
            continue;
        }

        if (!self && sender == plr)
            continue;

        uint32 team = itr->second.Team;
        if (!team) team = plr->GetTeam();

        if (team == TeamID)
            plr->GetSession()->SendPacket(packet);
    }
}

void Battleground::PlaySoundToAll(uint32 SoundID)
{
    WorldPacket data;
    sBattlegroundMgr->BuildPlaySoundPacket(&data, SoundID);
    SendPacketToAll(&data);
}

void Battleground::PlaySoundToTeam(uint32 SoundID, uint32 TeamID)
{
    WorldPacket data;

    for (BattlegroundPlayerMap::const_iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
    {
        if (itr->second.OfflineRemoveTime)
            continue;
        Player *plr = sObjectMgr->GetPlayer(itr->first);

        if (!plr)
        {
            sLog->outError("Battleground:PlaySoundToTeam: Player (GUID: %u) not found!", GUID_LOPART(itr->first));
            continue;
        }

        uint32 team = itr->second.Team;
        if (!team) team = plr->GetTeam();

        if (team == TeamID)
        {
            sBattlegroundMgr->BuildPlaySoundPacket(&data, SoundID);
            plr->GetSession()->SendPacket(&data);
        }
    }
}

void Battleground::CastSpellOnTeam(uint32 SpellID, uint32 TeamID)
{
    for (BattlegroundPlayerMap::const_iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
    {
        if (itr->second.OfflineRemoveTime)
            continue;
        Player *plr = sObjectMgr->GetPlayer(itr->first);

        if (!plr)
        {
            sLog->outError("Battleground:CastSpellOnTeam: Player (GUID: %u) not found!", GUID_LOPART(itr->first));
            continue;
        }

        uint32 team = itr->second.Team;
        if (!team) team = plr->GetTeam();

        if (team == TeamID)
            plr->CastSpell(plr, SpellID, true);
    }
}

void Battleground::RemoveAuraOnTeam(uint32 SpellID, uint32 TeamID)
{
    for (BattlegroundPlayerMap::const_iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
    {
        if (itr->second.OfflineRemoveTime)
            continue;
        Player *plr = sObjectMgr->GetPlayer(itr->first);

        if (!plr)
        {
            sLog->outError("Battleground:RemoveAuraOnTeam: Player (GUID: %u) not found!", GUID_LOPART(itr->first));
            continue;
        }

        uint32 team = itr->second.Team;
        if (!team) team = plr->GetTeam();

        if (team == TeamID)
            plr->RemoveAura(SpellID);
    }
}

void Battleground::YellToAll(Creature* creature, const char* text, uint32 language)
{
    for (std::map<uint64, BattlegroundPlayer>::iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
    {
        WorldPacket data(SMSG_MESSAGECHAT, 200);
        Player *plr = sObjectMgr->GetPlayer(itr->first);
        if (!plr)
        {
            sLog->outError("Battleground: Player " UI64FMTD " not found!", itr->first);
            continue;
        }
        creature->BuildMonsterChat(&data,CHAT_MSG_MONSTER_YELL,text,language,creature->GetName(),itr->first);
        plr->GetSession()->SendPacket(&data);
    }
}

void Battleground::RewardHonorToTeam(uint32 Honor, uint32 TeamID)
{
    for (BattlegroundPlayerMap::const_iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
    {
        if (itr->second.OfflineRemoveTime)
            continue;
        Player *plr = sObjectMgr->GetPlayer(itr->first);

        if (!plr)
        {
            sLog->outError("Battleground:RewardHonorToTeam: Player (GUID: %u) not found!", GUID_LOPART(itr->first));
            continue;
        }

        uint32 team = itr->second.Team;
        if (!team) team = plr->GetTeam();

        if (team == TeamID)
            UpdatePlayerScore(plr, SCORE_BONUS_HONOR, Honor);
    }
}

void Battleground::RewardReputationToTeam(uint32 faction_id, uint32 Reputation, uint32 TeamID)
{
    FactionEntry const* factionEntry = sFactionStore.LookupEntry(faction_id);

    if (!factionEntry)
        return;

    for (BattlegroundPlayerMap::const_iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
    {
        if (itr->second.OfflineRemoveTime)
            continue;
        Player *plr = sObjectMgr->GetPlayer(itr->first);

        if (!plr)
        {
            sLog->outError("Battleground:RewardReputationToTeam: Player (GUID: %u) not found!", GUID_LOPART(itr->first));
            continue;
        }

        uint32 team = itr->second.Team;
        if (!team) team = plr->GetTeam();

        if (team == TeamID)
            plr->GetReputationMgr().ModifyReputation(factionEntry, Reputation);
    }
}

void Battleground::UpdateWorldState(uint32 Field, uint32 Value)
{
    WorldPacket data;
    sBattlegroundMgr->BuildUpdateWorldStatePacket(&data, Field, Value);
    SendPacketToAll(&data);
}

void Battleground::UpdateWorldStateForPlayer(uint32 Field, uint32 Value, Player *Source)
{
    WorldPacket data;
    sBattlegroundMgr->BuildUpdateWorldStatePacket(&data, Field, Value);
    Source->GetSession()->SendPacket(&data);
}

void Battleground::EndBattleground(uint32 winner)
{
    this->RemoveFromBGFreeSlotQueue();

    ArenaTeam * winner_arena_team = NULL;
    ArenaTeam * loser_arena_team = NULL;
    uint32 loser_team_rating = 0;
    uint32 loser_matchmaker_rating = 0;
    int32  loser_change = 0;
    uint32 winner_team_rating = 0;
    uint32 winner_matchmaker_rating = 0;
    int32  winner_change = 0;
    WorldPacket data;
    int32 winmsg_id = 0;

    if (winner == ALLIANCE)
    {
        winmsg_id = isBattleground() ? LANG_BG_A_WINS : LANG_ARENA_GOLD_WINS;

        PlaySoundToAll(SOUND_ALLIANCE_WINS);                // alliance wins sound

        SetWinner(WINNER_ALLIANCE);
    }
    else if (winner == HORDE)
    {
        winmsg_id = isBattleground() ? LANG_BG_H_WINS : LANG_ARENA_GREEN_WINS;

        PlaySoundToAll(SOUND_HORDE_WINS);                   // horde wins sound

        SetWinner(WINNER_HORDE);
    }
    else
    {
        SetWinner(3);
    }

    SetStatus(STATUS_WAIT_LEAVE);
    //we must set it this way, because end time is sent in packet!
    m_EndTime = TIME_TO_AUTOREMOVE;

    // arena rating calculation
    if (isArena() && isRated())
    {
        winner_arena_team = sObjectMgr->GetArenaTeamById(GetArenaTeamIdForTeam(winner));
        loser_arena_team = sObjectMgr->GetArenaTeamById(GetArenaTeamIdForTeam(GetOtherTeam(winner)));
        if (winner_arena_team && loser_arena_team && winner_arena_team != loser_arena_team)
        {
            if (winner != WINNER_NONE)
            {
                loser_team_rating = loser_arena_team->GetRating();
                loser_matchmaker_rating = GetArenaMatchmakerRating(GetOtherTeam(winner));
                winner_team_rating = winner_arena_team->GetRating();
                winner_matchmaker_rating = GetArenaMatchmakerRating(winner);
                winner_change = winner_arena_team->WonAgainst(loser_matchmaker_rating);
                loser_change = loser_arena_team->LostAgainst(winner_matchmaker_rating);
                sLog->outArena("--- Winner rating: %u, Loser rating: %u, Winner MMR: %u, Loser MMR: %u, Winner change: %u, Loser change: %u ---", winner_team_rating, loser_team_rating,
                    winner_matchmaker_rating, loser_matchmaker_rating, winner_change, loser_change);
                SetArenaTeamRatingChangeForTeam(winner, winner_change);
                SetArenaTeamRatingChangeForTeam(GetOtherTeam(winner), loser_change);
                sLog->outArena("Arena match Type: %u for Team1Id: %u - Team2Id: %u ended. WinnerTeamId: %u. Winner rating: +%d, Loser rating: %d", m_ArenaType, m_ArenaTeamIds[BG_TEAM_ALLIANCE], m_ArenaTeamIds[BG_TEAM_HORDE], winner_arena_team->GetId(), winner_change, loser_change);
                if (sWorld->getBoolConfig(CONFIG_ARENA_LOG_EXTENDED_INFO))
                    for (Battleground::BattlegroundScoreMap::const_iterator itr = GetPlayerScoresBegin(); itr != GetPlayerScoresEnd(); itr++)
                        if (Player* player = sObjectMgr->GetPlayer(itr->first))
                            sLog->outArena("Statistics for %s (GUID: " UI64FMTD ", Team: %d, IP: %s): %u damage, %u healing, %u killing blows", player->GetName(), itr->first, player->GetArenaTeamId(m_ArenaType == 5 ? 2 : m_ArenaType == 3), player->GetSession()->GetRemoteAddress().c_str(), itr->second->DamageDone, itr->second->HealingDone, itr->second->KillingBlows);
            }
            // Deduct 16 points from each teams arena-rating if there are no winners after 45+2 minutes
            else
            {
                SetArenaTeamRatingChangeForTeam(ALLIANCE, ARENA_TIMELIMIT_POINTS_LOSS);
                SetArenaTeamRatingChangeForTeam(HORDE, ARENA_TIMELIMIT_POINTS_LOSS);
                winner_arena_team->FinishGame(ARENA_TIMELIMIT_POINTS_LOSS);
                loser_arena_team->FinishGame(ARENA_TIMELIMIT_POINTS_LOSS);
            }
        }
        else
        {
            SetArenaTeamRatingChangeForTeam(ALLIANCE, 0);
            SetArenaTeamRatingChangeForTeam(HORDE, 0);
        }
    }

    for (BattlegroundPlayerMap::iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
    {
        uint32 team = itr->second.Team;

        if (itr->second.OfflineRemoveTime)
        {
            //if rated arena match - make member lost!
            if (isArena() && isRated() && winner_arena_team && loser_arena_team && winner_arena_team != loser_arena_team)
            {
                if (team == winner)
                    winner_arena_team->OfflineMemberLost(itr->first, loser_matchmaker_rating, winner_change);
                else
                    loser_arena_team->OfflineMemberLost(itr->first, winner_matchmaker_rating, loser_change);
            }
            continue;
        }
        Player *plr = sObjectMgr->GetPlayer(itr->first);
        if (!plr)
        {
            sLog->outError("Battleground:EndBattleground Player (GUID: %u) not found!", GUID_LOPART(itr->first));
            continue;
        }

        // should remove spirit of redemption
        if (plr->HasAuraType(SPELL_AURA_SPIRIT_OF_REDEMPTION))
            plr->RemoveAurasByType(SPELL_AURA_MOD_SHAPESHIFT);

        if (!plr->isAlive())
        {
            plr->ResurrectPlayer(1.0f);
            plr->SpawnCorpseBones();
        }
        else
        {
            //needed cause else in av some creatures will kill the players at the end
            plr->CombatStop();
            plr->getHostileRefManager().deleteReferences();
        }

        //this line is obsolete - team is set ALWAYS
        //if (!team) team = plr->GetTeam();

        // per player calculation
        if (isArena() && isRated() && winner_arena_team && loser_arena_team && winner_arena_team != loser_arena_team)
        {
            if (team == winner)
            {
                // update achievement BEFORE personal rating update
                ArenaTeamMember* member = winner_arena_team->GetMember(plr->GetGUID());
                if (member)
                    plr->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_WIN_RATED_ARENA, member->personal_rating);

                winner_arena_team->MemberWon(plr,loser_matchmaker_rating, winner_change);
            }
            else
            {
                loser_arena_team->MemberLost(plr, winner_matchmaker_rating, loser_change);

                // Arena lost => reset the win_rated_arena having the "no_lose" condition
                plr->GetAchievementMgr().ResetAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_WIN_RATED_ARENA, ACHIEVEMENT_CRITERIA_CONDITION_NO_LOSE);
            }
        }

        uint32 winner_kills = plr->GetRandomWinner() ? BG_REWARD_WINNER_HONOR_LAST : BG_REWARD_WINNER_HONOR_FIRST;
        uint32 loser_kills = plr->GetRandomWinner() ? BG_REWARD_LOSER_HONOR_LAST : BG_REWARD_LOSER_HONOR_FIRST;
        uint32 winner_arena = plr->GetRandomWinner() ? BG_REWARD_WINNER_ARENA_LAST : BG_REWARD_WINNER_ARENA_FIRST;

        // Reward winner team
        if (team == winner)
        {
            if (IsRandom() || BattlegroundMgr::IsBGWeekend(GetTypeID()))
            {
                UpdatePlayerScore(plr, SCORE_BONUS_HONOR, GetBonusHonorFromKill(winner_kills));
                if (CanAwardArenaPoints())
                    plr->ModifyArenaPoints(winner_arena);
                if (!plr->GetRandomWinner())
                    plr->SetRandomWinner(true);
            }

            plr->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_WIN_BG, 1);
        }
        else
        {
            if (IsRandom() || BattlegroundMgr::IsBGWeekend(GetTypeID()))
                UpdatePlayerScore(plr, SCORE_BONUS_HONOR, GetBonusHonorFromKill(loser_kills));
        }


        plr->ResetAllPowers();
        plr->CombatStopWithPets(true);

        BlockMovement(plr);

        sBattlegroundMgr->BuildPvpLogDataPacket(&data, this);
        plr->GetSession()->SendPacket(&data);

        BattlegroundQueueTypeId bgQueueTypeId = BattlegroundMgr::BGQueueTypeId(GetTypeID(), GetArenaType());
        sBattlegroundMgr->BuildBattlegroundStatusPacket(&data, this, plr->GetBattlegroundQueueIndex(bgQueueTypeId), STATUS_IN_PROGRESS, TIME_TO_AUTOREMOVE, GetStartTime(), GetArenaType());
        plr->GetSession()->SendPacket(&data);
        plr->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_BATTLEGROUND, 1);
    }

    if (isArena() && isRated() && winner_arena_team && loser_arena_team && winner_arena_team != loser_arena_team)
    {
        // update arena points only after increasing the player's match count!
        //obsolete: winner_arena_team->UpdateArenaPointsHelper();
        //obsolete: loser_arena_team->UpdateArenaPointsHelper();
        // save the stat changes
        winner_arena_team->SaveToDB();
        loser_arena_team->SaveToDB();
        // send updated arena team stats to players
        // this way all arena team members will get notified, not only the ones who participated in this match
        winner_arena_team->NotifyStatsChanged();
        loser_arena_team->NotifyStatsChanged();
    }

    if (winmsg_id)
        SendMessageToAll(winmsg_id, CHAT_MSG_BG_SYSTEM_NEUTRAL);
}

uint32 Battleground::GetBonusHonorFromKill(uint32 kills) const
{
    //variable kills means how many honorable kills you scored (so we need kills * honor_for_one_kill)
    uint32 maxLevel = std::min(GetMaxLevel(), 80U);
    return Trinity::Honor::hk_honor_at_level(maxLevel, float(kills));
}

uint32 Battleground::GetBattlemasterEntry() const
{
    switch(GetTypeID(true))
    {
        case BATTLEGROUND_AV: return 15972;
        case BATTLEGROUND_WS: return 14623;
        case BATTLEGROUND_AB: return 14879;
        case BATTLEGROUND_EY: return 22516;
        case BATTLEGROUND_NA: return 20200;
        default:              return 0;
    }
}

void Battleground::BlockMovement(Player *plr)
{
    plr->SetClientControl(plr, 0);                          // movement disabled NOTE: the effect will be automatically removed by client when the player is teleported from the battleground, so no need to send with uint8(1) in RemovePlayerAtLeave()
}

void Battleground::RemovePlayerAtLeave(uint64 guid, bool Transport, bool SendPacket)
{
    uint32 team = GetPlayerTeam(guid);
    bool participant = false;
    // Remove from lists/maps
    BattlegroundPlayerMap::iterator itr = m_Players.find(guid);
    if (itr != m_Players.end())
    {
        UpdatePlayersCountByTeam(team, true);               // -1 player
        m_Players.erase(itr);
        // check if the player was a participant of the match, or only entered through gm command (goname)
        participant = true;
    }

    BattlegroundScoreMap::iterator itr2 = m_PlayerScores.find(guid);
    if (itr2 != m_PlayerScores.end())
    {
        delete itr2->second;                                // delete player's score
        m_PlayerScores.erase(itr2);
    }

    RemovePlayerFromResurrectQueue(guid);

    Player *plr = sObjectMgr->GetPlayer(guid);

    // should remove spirit of redemption
    if (plr && plr->HasAuraType(SPELL_AURA_SPIRIT_OF_REDEMPTION))
        plr->RemoveAurasByType(SPELL_AURA_MOD_SHAPESHIFT);

    if (plr && !plr->isAlive())                              // resurrect on exit
    {
        plr->ResurrectPlayer(1.0f);
        plr->SpawnCorpseBones();
    }

    RemovePlayer(plr, guid);                                // BG subclass specific code

    if (participant) // if the player was a match participant, remove auras, calc rating, update queue
    {
        BattlegroundTypeId bgTypeId = GetTypeID();
        BattlegroundQueueTypeId bgQueueTypeId = BattlegroundMgr::BGQueueTypeId(GetTypeID(), GetArenaType());
        if (plr)
        {
            plr->ClearAfkReports();

            if (!team) team = plr->GetTeam();

            // if arena, remove the specific arena auras
            if (isArena())
            {
                plr->RemoveArenaAuras(true);                // removes debuffs / dots etc., we don't want the player to die after porting out
                bgTypeId=BATTLEGROUND_AA;                   // set the bg type to all arenas (it will be used for queue refreshing)

                // unsummon current and summon old pet if there was one and there isn't a current pet
                plr->RemovePet(NULL, PET_SAVE_NOT_IN_SLOT);
                plr->ResummonPetTemporaryUnSummonedIfAny();

                if (isRated() && GetStatus() == STATUS_IN_PROGRESS)
                {
                    //left a rated match while the encounter was in progress, consider as loser
                    ArenaTeam * winner_arena_team = sObjectMgr->GetArenaTeamById(GetArenaTeamIdForTeam(GetOtherTeam(team)));
                    ArenaTeam * loser_arena_team = sObjectMgr->GetArenaTeamById(GetArenaTeamIdForTeam(team));
                    if (winner_arena_team && loser_arena_team && winner_arena_team != loser_arena_team)
                        loser_arena_team->MemberLost(plr, GetArenaMatchmakerRating(GetOtherTeam(team)));
                }
            }
            if (SendPacket)
            {
                WorldPacket data;
                sBattlegroundMgr->BuildBattlegroundStatusPacket(&data, this, plr->GetBattlegroundQueueIndex(bgQueueTypeId), STATUS_NONE, 0, 0, 0);
                plr->GetSession()->SendPacket(&data);
            }

            // this call is important, because player, when joins to battleground, this method is not called, so it must be called when leaving bg
            plr->RemoveBattlegroundQueueId(bgQueueTypeId);
        }
        else
        // removing offline participant
        {
            if (isRated() && GetStatus() == STATUS_IN_PROGRESS)
            {
                //left a rated match while the encounter was in progress, consider as loser
                ArenaTeam * others_arena_team = sObjectMgr->GetArenaTeamById(GetArenaTeamIdForTeam(GetOtherTeam(team)));
                ArenaTeam * players_arena_team = sObjectMgr->GetArenaTeamById(GetArenaTeamIdForTeam(team));
                if (others_arena_team && players_arena_team)
                    players_arena_team->OfflineMemberLost(guid, GetArenaMatchmakerRating(GetOtherTeam(team)));
            }
        }

        // remove from raid group if player is member
        if (Group *group = GetBgRaid(team))
        {
            if (!group->RemoveMember(guid))                // group was disbanded
            {
                SetBgRaid(team, NULL);
            }
        }
        DecreaseInvitedCount(team);
        //we should update battleground queue, but only if bg isn't ending
        if (isBattleground() && GetStatus() < STATUS_WAIT_LEAVE)
        {
            // a player has left the battleground, so there are free slots -> add to queue
            AddToBGFreeSlotQueue();
            sBattlegroundMgr->ScheduleQueueUpdate(0, 0, bgQueueTypeId, bgTypeId, GetBracketId());
        }
        // Let others know
        WorldPacket data;
        sBattlegroundMgr->BuildPlayerLeftBattlegroundPacket(&data, guid);
        SendPacketToTeam(team, &data, plr, false);
    }

    if (plr)
    {
        // Do next only if found in battleground
        plr->SetBattlegroundId(0, BATTLEGROUND_TYPE_NONE);  // We're not in BG.
        // reset destination bg team
        plr->SetBGTeam(0);

        if (Transport)
            plr->TeleportToBGEntryPoint();

        sLog->outDetail("BATTLEGROUND: Removed player %s from Battleground.", plr->GetName());
        plr->GetAchievementMgr().ResetAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE, ACHIEVEMENT_CRITERIA_CONDITION_MAP, GetMapId(), true);
    }

    //battleground object will be deleted next Battleground::Update() call
}

// this method is called when no players remains in battleground
void Battleground::Reset()
{
    SetWinner(WINNER_NONE);
    SetStatus(STATUS_WAIT_QUEUE);
    SetStartTime(0);
    SetEndTime(0);
    SetLastResurrectTime(0);
    SetArenaType(0);
    SetRated(false);

    m_Events = 0;

    if (m_InvitedAlliance > 0 || m_InvitedHorde > 0)
        sLog->outError("Battleground system: bad counter, m_InvitedAlliance: %d, m_InvitedHorde: %d", m_InvitedAlliance, m_InvitedHorde);

    m_InvitedAlliance = 0;
    m_InvitedHorde = 0;
    m_InBGFreeSlotQueue = false;

    m_Players.clear();

    for (BattlegroundScoreMap::const_iterator itr = m_PlayerScores.begin(); itr != m_PlayerScores.end(); ++itr)
        delete itr->second;
    m_PlayerScores.clear();

    ResetBGSubclass();
}

void Battleground::StartBattleground()
{
    SetStartTime(0);
    SetLastResurrectTime(0);
    // add BG to free slot queue
    AddToBGFreeSlotQueue();

    // add bg to update list
    // This must be done here, because we need to have already invited some players when first BG::Update() method is executed
    // and it doesn't matter if we call StartBattleground() more times, because m_Battlegrounds is a map and instance id never changes
    sBattlegroundMgr->AddBattleground(GetInstanceID(), GetTypeID(), this);
    if (m_IsRated)
        sLog->outArena("Arena match type: %u for Team1Id: %u - Team2Id: %u started.", m_ArenaType, m_ArenaTeamIds[BG_TEAM_ALLIANCE], m_ArenaTeamIds[BG_TEAM_HORDE]);
}

void Battleground::AddPlayer(Player *plr)
{
    // remove afk from player
    if (plr->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_AFK))
        plr->ToggleAFK();

    // score struct must be created in inherited class

    uint64 guid = plr->GetGUID();
    uint32 team = plr->GetBGTeam();

    BattlegroundPlayer bp;
    bp.OfflineRemoveTime = 0;
    bp.Team = team;

    // Add to list/maps
    m_Players[guid] = bp;

    UpdatePlayersCountByTeam(team, false);                  // +1 player

    WorldPacket data;
    sBattlegroundMgr->BuildPlayerJoinedBattlegroundPacket(&data, plr);
    SendPacketToTeam(team, &data, plr, false);

    // BG Status packet
    WorldPacket status;
    BattlegroundQueueTypeId bgQueueTypeId = sBattlegroundMgr->BGQueueTypeId(m_TypeID, GetArenaType());
    uint32 queueSlot = plr->GetBattlegroundQueueIndex(bgQueueTypeId);
    sBattlegroundMgr->BuildBattlegroundStatusPacket(&status, this, queueSlot, STATUS_IN_PROGRESS, 0, GetStartTime(), GetArenaType(), isArena() ? 0 : 1);
    plr->GetSession()->SendPacket(&status);

    plr->RemoveAurasByType(SPELL_AURA_MOUNTED);

    // add arena specific auras
    if (isArena())
    {
        plr->RemoveArenaEnchantments(TEMP_ENCHANTMENT_SLOT);
        if (team == ALLIANCE)                                // gold
        {
            if (plr->GetTeam() == HORDE)
                plr->CastSpell(plr, SPELL_HORDE_GOLD_FLAG,true);
            else
                plr->CastSpell(plr, SPELL_ALLIANCE_GOLD_FLAG,true);
        }
        else                                                // green
        {
            if (plr->GetTeam() == HORDE)
                plr->CastSpell(plr, SPELL_HORDE_GREEN_FLAG,true);
            else
                plr->CastSpell(plr, SPELL_ALLIANCE_GREEN_FLAG,true);
        }

        plr->DestroyConjuredItems(true);
        plr->UnsummonPetTemporaryIfAny();

        if (GetStatus() == STATUS_WAIT_JOIN)                 // not started yet
        {
            plr->CastSpell(plr, SPELL_ARENA_PREPARATION, true);
            plr->ResetAllPowers();
        }
        WorldPacket teammate;
        teammate.Initialize(SMSG_ARENA_OPPONENT_UPDATE, 8);
        teammate << uint64(plr->GetGUID());
        SendPacketToTeam(team, &teammate, plr, false);
    }
    else
    {
        if (GetStatus() == STATUS_WAIT_JOIN)                 // not started yet
            plr->CastSpell(plr, SPELL_PREPARATION, true);   // reduces all mana cost of spells.
    }

    plr->GetAchievementMgr().ResetAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_HEALING_DONE, ACHIEVEMENT_CRITERIA_CONDITION_MAP, GetMapId());
    plr->GetAchievementMgr().ResetAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_DAMAGE_DONE, ACHIEVEMENT_CRITERIA_CONDITION_MAP, GetMapId());

    // setup BG group membership
    PlayerAddedToBGCheckIfBGIsRunning(plr);
    AddOrSetPlayerToCorrectBgGroup(plr, team);

    // Log
    sLog->outDetail("BATTLEGROUND: Player %s joined the battle.", plr->GetName());
}

/* this method adds player to his team's bg group, or sets his correct group if player is already in bg group */
void Battleground::AddOrSetPlayerToCorrectBgGroup(Player *player, uint32 team)
{
    uint64 playerGuid = player->GetGUID();
    Group* group = GetBgRaid(team);
    if (!group)                                      // first player joined
    {
        group = new Group;
        SetBgRaid(team, group);
        group->Create(player);
    }
    else                                            // raid already exist
    {
        if (group->IsMember(playerGuid))
        {
            uint8 subgroup = group->GetMemberGroup(playerGuid);
            player->SetBattlegroundRaid(group, subgroup);
        }
        else
        {
            group->AddMember(player);
            if (Group* originalGroup = player->GetOriginalGroup())
                if (originalGroup->IsLeader(playerGuid))
                {
                    group->ChangeLeader(playerGuid);
                    group->SendUpdate();
                }
        }
    }
}

// This method should be called when player logs into running battleground
void Battleground::EventPlayerLoggedIn(Player* player)
{
    // player is correct pointer
    for (std::deque<uint64>::iterator itr = m_OfflineQueue.begin(); itr != m_OfflineQueue.end(); ++itr)
    {
        if (*itr == player->GetGUID())
        {
            m_OfflineQueue.erase(itr);
            break;
        }
    }
    m_Players[player->GetGUID()].OfflineRemoveTime = 0;
    PlayerAddedToBGCheckIfBGIsRunning(player);
    // if battleground is starting, then add preparation aura
    // we don't have to do that, because preparation aura isn't removed when player logs out
}

// This method should be called when player logs out from running battleground
void Battleground::EventPlayerLoggedOut(Player* player)
{
    // player is correct pointer, it is checked in WorldSession::LogoutPlayer()
    m_OfflineQueue.push_back(player->GetGUID());
    m_Players[player->GetGUID()].OfflineRemoveTime = sWorld->GetGameTime() + MAX_OFFLINE_TIME;
    if (GetStatus() == STATUS_IN_PROGRESS)
    {
        // drop flag and handle other cleanups
        RemovePlayer(player, player->GetGUID());

        // 1 player is logging out, if it is the last, then end arena!
        if (isArena())
            if (GetAlivePlayersCountByTeam(player->GetTeam()) <= 1 && GetPlayersCountByTeam(GetOtherTeam(player->GetTeam())))
                EndBattleground(GetOtherTeam(player->GetTeam()));
    }

    player->LeaveBattleground();
}

/* This method should be called only once ... it adds pointer to queue */
void Battleground::AddToBGFreeSlotQueue()
{
    // make sure to add only once
    if (!m_InBGFreeSlotQueue && isBattleground())
    {
        sBattlegroundMgr->BGFreeSlotQueue[m_TypeID].push_front(this);
        m_InBGFreeSlotQueue = true;
    }
}

/* This method removes this battleground from free queue - it must be called when deleting battleground - not used now*/
void Battleground::RemoveFromBGFreeSlotQueue()
{
    // set to be able to re-add if needed
    m_InBGFreeSlotQueue = false;
    // uncomment this code when battlegrounds will work like instances
    for (BGFreeSlotQueueType::iterator itr = sBattlegroundMgr->BGFreeSlotQueue[m_TypeID].begin(); itr != sBattlegroundMgr->BGFreeSlotQueue[m_TypeID].end(); ++itr)
    {
        if ((*itr)->GetInstanceID() == m_InstanceID)
        {
            sBattlegroundMgr->BGFreeSlotQueue[m_TypeID].erase(itr);
            return;
        }
    }
}

// get the number of free slots for team
// returns the number how many players can join battleground to MaxPlayersPerTeam
uint32 Battleground::GetFreeSlotsForTeam(uint32 Team) const
{
    //if BG is starting ... invite anyone
    if (GetStatus() == STATUS_WAIT_JOIN)
        return (GetInvitedCount(Team) < GetMaxPlayersPerTeam()) ? GetMaxPlayersPerTeam() - GetInvitedCount(Team) : 0;
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
    if (GetStatus() == STATUS_IN_PROGRESS)
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
    return 0;
}

bool Battleground::HasFreeSlots() const
{
    return GetPlayersSize() < GetMaxPlayers();
}

void Battleground::UpdatePlayerScore(Player *Source, uint32 type, uint32 value, bool doAddHonor)
{
    //this procedure is called from virtual function implemented in bg subclass
    BattlegroundScoreMap::const_iterator itr = m_PlayerScores.find(Source->GetGUID());

    if (itr == m_PlayerScores.end())                         // player not found...
        return;

    switch(type)
    {
        case SCORE_KILLING_BLOWS:                           // Killing blows
            itr->second->KillingBlows += value;
            break;
        case SCORE_DEATHS:                                  // Deaths
            itr->second->Deaths += value;
            Source->GetAchievementMgr().ResetAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE, ACHIEVEMENT_CRITERIA_CONDITION_NO_DEATH);
            break;
        case SCORE_HONORABLE_KILLS:                         // Honorable kills
            itr->second->HonorableKills += value;
            break;
        case SCORE_BONUS_HONOR:                             // Honor bonus
            // do not add honor in arenas
            if (isBattleground())
            {
                // reward honor instantly
                if (doAddHonor)
                {
                    Source->RewardHonor(NULL, 1, value);//RewardHonor calls UpdatePlayerScore with doAddHonor = false
                }else itr->second->BonusHonor += value;
            }
            break;
            //used only in EY, but in MSG_PVP_LOG_DATA opcode
        case SCORE_DAMAGE_DONE:                             // Damage Done
            itr->second->DamageDone += value;
            break;
        case SCORE_HEALING_DONE:                            // Healing Done
            itr->second->HealingDone += value;
            break;
        default:
            sLog->outError("Battleground: Unknown player score type %u", type);
            break;
    }
}

void Battleground::AddPlayerToResurrectQueue(uint64 npc_guid, uint64 player_guid)
{
    m_ReviveQueue[npc_guid].push_back(player_guid);

    Player *plr = sObjectMgr->GetPlayer(player_guid);
    if (!plr)
        return;

    plr->CastSpell(plr, SPELL_WAITING_FOR_RESURRECT, true);
}

void Battleground::RemovePlayerFromResurrectQueue(uint64 player_guid)
{
    for (std::map<uint64, std::vector<uint64> >::iterator itr = m_ReviveQueue.begin(); itr != m_ReviveQueue.end(); ++itr)
    {
        for (std::vector<uint64>::iterator itr2 =(itr->second).begin(); itr2 != (itr->second).end(); ++itr2)
        {
            if (*itr2 == player_guid)
            {
                (itr->second).erase(itr2);

                Player *plr = sObjectMgr->GetPlayer(player_guid);
                if (!plr)
                    return;

                plr->RemoveAurasDueToSpell(SPELL_WAITING_FOR_RESURRECT);

                return;
            }
        }
    }
}

bool Battleground::AddObject(uint32 type, uint32 entry, float x, float y, float z, float o, float rotation0, float rotation1, float rotation2, float rotation3, uint32 /*respawnTime*/)
{
    // If the assert is called, means that m_BgObjects must be resized!
    ASSERT(type < m_BgObjects.size());

    Map *map = GetBgMap();
    if (!map)
        return false;
    // must be created this way, adding to godatamap would add it to the base map of the instance
    // and when loading it (in go::LoadFromDB()), a new guid would be assigned to the object, and a new object would be created
    // so we must create it specific for this instance
    GameObject * go = new GameObject;
    if (!go->Create(sObjectMgr->GenerateLowGuid(HIGHGUID_GAMEOBJECT),entry, GetBgMap(),
        PHASEMASK_NORMAL, x,y,z,o,rotation0,rotation1,rotation2,rotation3,100,GO_STATE_READY))
    {
        sLog->outErrorDb("Gameobject template %u not found in database! Battleground not created!", entry);
        sLog->outError("Cannot create gameobject template %u! Battleground not created!", entry);
        delete go;
        return false;
    }
/*
    uint32 guid = go->GetGUIDLow();

    // without this, UseButtonOrDoor caused the crash, since it tried to get go info from godata
    // iirc that was changed, so adding to go data map is no longer required if that was the only function using godata from GameObject without checking if it existed
    GameObjectData& data = sObjectMgr->NewGOData(guid);

    data.id             = entry;
    data.mapid          = GetMapId();
    data.posX           = x;
    data.posY           = y;
    data.posZ           = z;
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
    map->Add(go);
    m_BgObjects[type] = go->GetGUID();
    return true;
}

//some doors aren't despawned so we cannot handle their closing in gameobject::update()
//it would be nice to correctly implement GO_ACTIVATED state and open/close doors in gameobject code
void Battleground::DoorClose(uint32 type)
{
    GameObject *obj = GetBgMap()->GetGameObject(m_BgObjects[type]);
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
    {
        sLog->outError("Battleground: Door object not found (cannot close doors)");
    }
}

void Battleground::DoorOpen(uint32 type)
{
    GameObject *obj = GetBgMap()->GetGameObject(m_BgObjects[type]);
    if (obj)
    {
        //change state to be sure they will be opened
        obj->SetLootState(GO_READY);
        obj->UseDoorOrButton(RESPAWN_ONE_DAY);
    }
    else
    {
        sLog->outError("Battleground: Door object not found! - doors will be closed.");
    }
}

GameObject* Battleground::GetBGObject(uint32 type)
{
    GameObject *obj = GetBgMap()->GetGameObject(m_BgObjects[type]);
    if (!obj)
        sLog->outError("couldn't get gameobject %i",type);
    return obj;
}

Creature* Battleground::GetBGCreature(uint32 type)
{
    Creature *creature = GetBgMap()->GetCreature(m_BgCreatures[type]);
    if (!creature)
        sLog->outError("Could not get BG creature %i (BG: %s Instance: %u)", type, GetBgMap()->GetBG()->GetName(), GetBgMap()->GetInstanceId());
    return creature;
}

void Battleground::SpawnBGObject(uint32 type, uint32 respawntime)
{
    Map * map = GetBgMap();
    if (!map)
        return;
    if (respawntime == 0)
    {
        GameObject *obj = map->GetGameObject(m_BgObjects[type]);
        if (obj)
        {
            //we need to change state from GO_JUST_DEACTIVATED to GO_READY in case battleground is starting again
            if (obj->getLootState() == GO_JUST_DEACTIVATED)
                obj->SetLootState(GO_READY);
            obj->SetRespawnTime(0);
            map->Add(obj);
        }
    }
    else
    {
        GameObject *obj = map->GetGameObject(m_BgObjects[type]);
        if (obj)
        {
            map->Add(obj);
            obj->SetRespawnTime(respawntime);
            obj->SetLootState(GO_JUST_DEACTIVATED);
        }
    }
}

Creature* Battleground::AddCreature(uint32 entry, uint32 type, uint32 teamval, float x, float y, float z, float o, uint32 respawntime)
{
    // If the assert is called, means that m_BgCreatures must be resized!
    ASSERT(type < m_BgCreatures.size());

    Map * map = GetBgMap();
    if (!map)
        return NULL;

    Creature* pCreature = new Creature;
    if (!pCreature->Create(sObjectMgr->GenerateLowGuid(HIGHGUID_UNIT), map, PHASEMASK_NORMAL, entry, 0, teamval, x, y, z, o))
    {
        sLog->outError("Can't create creature entry: %u",entry);
        delete pCreature;
        return NULL;
    }

    pCreature->SetHomePosition(x, y, z, o);

    CreatureInfo const *cinfo = ObjectMgr::GetCreatureTemplate(entry);
    if (!cinfo)
    {
        sLog->outErrorDb("Battleground::AddCreature: entry %u does not exist.", entry);
        return NULL;
    }
    //force using DB speeds
    pCreature->SetSpeed(MOVE_WALK,  cinfo->speed_walk);
    pCreature->SetSpeed(MOVE_RUN,   cinfo->speed_run);

    map->Add(pCreature);
    m_BgCreatures[type] = pCreature->GetGUID();

    if (respawntime)
        pCreature->SetRespawnDelay(respawntime);

    return  pCreature;
}
/*
void Battleground::SpawnBGCreature(uint32 type, uint32 respawntime)
{
    Map * map = sMapMgr->FindMap(GetMapId(),GetInstanceId());
    if (!map)
        return false;

    if (respawntime == 0)
    {
        Creature *obj = HashMapHolder<Creature>::Find(m_BgCreatures[type]);
        if (obj)
        {
            //obj->Respawn();                               // bugged
            obj->SetRespawnTime(0);
            sObjectMgr->RemoveCreatureRespawnTime(obj->GetGUIDLow(), GetInstanceID());
            map->Add(obj);
        }
    }
    else
    {
        Creature *obj = HashMapHolder<Creature>::Find(m_BgCreatures[type]);
        if (obj)
        {
            obj->setDeathState(DEAD);
            obj->SetRespawnTime(respawntime);
            map->Add(obj);
        }
    }
}
*/
bool Battleground::DelCreature(uint32 type)
{
    if (!m_BgCreatures[type])
        return true;

    Creature *cr = GetBgMap()->GetCreature(m_BgCreatures[type]);
    if (!cr)
    {
        sLog->outError("Can't find creature guid: %u",GUID_LOPART(m_BgCreatures[type]));
        return false;
    }
    cr->AddObjectToRemoveList();
    m_BgCreatures[type] = 0;
    return true;
}

bool Battleground::DelObject(uint32 type)
{
    if (!m_BgObjects[type])
        return true;

    GameObject *obj = GetBgMap()->GetGameObject(m_BgObjects[type]);
    if (!obj)
    {
        sLog->outError("Can't find gobject guid: %u",GUID_LOPART(m_BgObjects[type]));
        return false;
    }
    obj->SetRespawnTime(0);                                 // not save respawn time
    obj->Delete();
    m_BgObjects[type] = 0;
    return true;
}

bool Battleground::AddSpiritGuide(uint32 type, float x, float y, float z, float o, uint32 team)
{
    uint32 entry = 0;

    if (team == ALLIANCE)
        entry = BG_CREATURE_ENTRY_A_SPIRITGUIDE;
    else
        entry = BG_CREATURE_ENTRY_H_SPIRITGUIDE;

    Creature* pCreature = AddCreature(entry,type,team,x,y,z,o);
    if (!pCreature)
    {
        sLog->outError("Can't create Spirit guide. Battleground not created!");
        EndNow();
        return false;
    }

    pCreature->setDeathState(DEAD);

    pCreature->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, pCreature->GetGUID());
    // aura
    //TODO: Fix display here
    //pCreature->SetVisibleAura(0, SPELL_SPIRIT_HEAL_CHANNEL);
    // casting visual effect
    pCreature->SetUInt32Value(UNIT_CHANNEL_SPELL, SPELL_SPIRIT_HEAL_CHANNEL);
    // correct cast speed
    pCreature->SetFloatValue(UNIT_MOD_CAST_SPEED, 1.0f);

    //pCreature->CastSpell(pCreature, SPELL_SPIRIT_HEAL_CHANNEL, true);

    return true;
}

void Battleground::SendMessageToAll(int32 entry, ChatMsg type, Player const* source)
{
    Trinity::BattlegroundChatBuilder bg_builder(type, entry, source);
    Trinity::LocalizedPacketDo<Trinity::BattlegroundChatBuilder> bg_do(bg_builder);
    BroadcastWorker(bg_do);
}

void Battleground::PSendMessageToAll(int32 entry, ChatMsg type, Player const* source, ...)
{
    va_list ap;
    va_start(ap, source);

    Trinity::BattlegroundChatBuilder bg_builder(type, entry, source, &ap);
    Trinity::LocalizedPacketDo<Trinity::BattlegroundChatBuilder> bg_do(bg_builder);
    BroadcastWorker(bg_do);

    va_end(ap);
}

void Battleground::SendWarningToAll(int32 entry, ...)
{
    const char *format = sObjectMgr->GetTrinityStringForDBCLocale(entry);
    va_list ap;
    char str [1024];
    va_start(ap, entry);
    vsnprintf(str,1024,format, ap);
    va_end(ap);
    std::string msg = (std::string)str;

    WorldPacket data(SMSG_MESSAGECHAT, 200);

    data << (uint8)CHAT_MSG_RAID_BOSS_EMOTE;
    data << (uint32)LANG_UNIVERSAL;
    data << (uint64)0;
    data << (uint32)0;                                     // 2.1.0
    data << (uint32)1;
    data << (uint8)0;
    data << (uint64)0;
    data << (uint32)(strlen(msg.c_str())+1);
    data << msg.c_str();
    data << (uint8)0;
    for (BattlegroundPlayerMap::const_iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
        if (Player *plr = ObjectAccessor::FindPlayer(MAKE_NEW_GUID(itr->first, 0, HIGHGUID_PLAYER)))
            if (plr->GetSession())
                plr->GetSession()->SendPacket(&data);
}

void Battleground::SendMessage2ToAll(int32 entry, ChatMsg type, Player const* source, int32 arg1, int32 arg2)
{
    Trinity::Battleground2ChatBuilder bg_builder(type, entry, source, arg1, arg2);
    Trinity::LocalizedPacketDo<Trinity::Battleground2ChatBuilder> bg_do(bg_builder);
    BroadcastWorker(bg_do);
}

void Battleground::EndNow()
{
    RemoveFromBGFreeSlotQueue();
    SetStatus(STATUS_WAIT_LEAVE);
    SetEndTime(0);
}

//to be removed
const char *Battleground::GetTrinityString(int32 entry)
{
    // FIXME: now we have different DBC locales and need localized message for each target client
    return sObjectMgr->GetTrinityStringForDBCLocale(entry);
}

/*
important notice:
buffs aren't spawned/despawned when players captures anything
buffs are in their positions when battleground starts
*/
void Battleground::HandleTriggerBuff(uint64 const& go_guid)
{
    GameObject *obj = GetBgMap()->GetGameObject(go_guid);
    if (!obj || obj->GetGoType() != GAMEOBJECT_TYPE_TRAP || !obj->isSpawned())
        return;

    //change buff type, when buff is used:
    int32 index = m_BgObjects.size() - 1;
    while (index >= 0 && m_BgObjects[index] != go_guid)
        index--;
    if (index < 0)
    {
        sLog->outError("Battleground (Type: %u) has buff gameobject (Guid: %u Entry: %u Type:%u) but it hasn't that object in its internal data",GetTypeID(true),GUID_LOPART(go_guid),obj->GetEntry(),obj->GetGoType());
        return;
    }

    //randomly select new buff
    uint8 buff = urand(0, 2);
    uint32 entry = obj->GetEntry();
    if (m_BuffChange && entry != Buff_Entries[buff])
    {
        //despawn current buff
        SpawnBGObject(index, RESPAWN_ONE_DAY);
        //set index for new one
        for (uint8 currBuffTypeIndex = 0; currBuffTypeIndex < 3; ++currBuffTypeIndex)
            if (entry == Buff_Entries[currBuffTypeIndex])
            {
                index -= currBuffTypeIndex;
                index += buff;
            }
    }

    SpawnBGObject(index, BUFF_RESPAWN_TIME);
}

void Battleground::HandleKillPlayer(Player *player, Player *killer)
{
    //keep in mind that for arena this will have to be changed a bit

    // add +1 deaths
    UpdatePlayerScore(player, SCORE_DEATHS, 1);
    // add +1 kills to group and +1 killing_blows to killer
    if (killer)
    {
        UpdatePlayerScore(killer, SCORE_HONORABLE_KILLS, 1);
        UpdatePlayerScore(killer, SCORE_KILLING_BLOWS, 1);

        for (BattlegroundPlayerMap::const_iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
        {
            Player *plr = sObjectMgr->GetPlayer(itr->first);

            if (!plr || plr == killer)
                continue;

            if (plr->GetTeam() == killer->GetTeam() && plr->IsAtGroupRewardDistance(player))
                UpdatePlayerScore(plr, SCORE_HONORABLE_KILLS, 1);
        }
    }

    // to be able to remove insignia -- ONLY IN Battlegrounds
    // give xp only in Battlegrounds
    if (!isArena())
    {
        player->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SKINNABLE);
        RewardXPAtKill(killer, player);
    }
}

// return the player's team based on battlegroundplayer info
// used in same faction arena matches mainly
uint32 Battleground::GetPlayerTeam(uint64 guid) const
{
    BattlegroundPlayerMap::const_iterator itr = m_Players.find(guid);
    if (itr != m_Players.end())
        return itr->second.Team;
    return 0;
}

uint32 Battleground::GetOtherTeam(uint32 teamId) const
{
    return (teamId) ? ((teamId == ALLIANCE) ? HORDE : ALLIANCE) : 0;
}

bool Battleground::IsPlayerInBattleground(uint64 guid) const
{
    BattlegroundPlayerMap::const_iterator itr = m_Players.find(guid);
    if (itr != m_Players.end())
        return true;
    return false;
}

void Battleground::PlayerAddedToBGCheckIfBGIsRunning(Player* plr)
{
    if (GetStatus() != STATUS_WAIT_LEAVE)
        return;

    WorldPacket data;
    BattlegroundQueueTypeId bgQueueTypeId = BattlegroundMgr::BGQueueTypeId(GetTypeID(), GetArenaType());

    BlockMovement(plr);

    sBattlegroundMgr->BuildPvpLogDataPacket(&data, this);
    plr->GetSession()->SendPacket(&data);

    sBattlegroundMgr->BuildBattlegroundStatusPacket(&data, this, plr->GetBattlegroundQueueIndex(bgQueueTypeId), STATUS_IN_PROGRESS, GetEndTime(), GetStartTime(), GetArenaType());
    plr->GetSession()->SendPacket(&data);
}

uint32 Battleground::GetAlivePlayersCountByTeam(uint32 Team) const
{
    int count = 0;
    for (BattlegroundPlayerMap::const_iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
    {
        if (itr->second.Team == Team)
        {
            Player * pl = sObjectMgr->GetPlayer(itr->first);
            if (pl && pl->isAlive() && !pl->HasByteFlag(UNIT_FIELD_BYTES_2, 3, FORM_SPIRITOFREDEMPTION))
                ++count;
        }
    }
    return count;
}

void Battleground::SetHoliday(bool is_holiday)
{
    if (is_holiday)
        m_HonorMode = BG_HOLIDAY;
    else
        m_HonorMode = BG_NORMAL;
}

int32 Battleground::GetObjectType(uint64 guid)
{
    for (uint32 i = 0; i < m_BgObjects.size(); ++i)
        if (m_BgObjects[i] == guid)
            return i;
    sLog->outError("Battleground: cheating? a player used a gameobject which isnt supposed to be a usable object!");
    return -1;
}

void Battleground::HandleKillUnit(Creature * /*creature*/, Player * /*killer*/)
{
}

void Battleground::CheckArenaAfterTimerConditions()
{
    EndBattleground(WINNER_NONE);
}

void Battleground::CheckArenaWinConditions()
{
    if (!GetAlivePlayersCountByTeam(ALLIANCE) && GetPlayersCountByTeam(HORDE))
        EndBattleground(HORDE);
    else if (GetPlayersCountByTeam(ALLIANCE) && !GetAlivePlayersCountByTeam(HORDE))
        EndBattleground(ALLIANCE);
}

void Battleground::UpdateArenaWorldState()
{
    UpdateWorldState(0xe10, GetAlivePlayersCountByTeam(HORDE));
    UpdateWorldState(0xe11, GetAlivePlayersCountByTeam(ALLIANCE));
}

void Battleground::SetBgRaid(uint32 TeamID, Group *bg_raid)
{
    Group* &old_raid = TeamID == ALLIANCE ? m_BgRaids[BG_TEAM_ALLIANCE] : m_BgRaids[BG_TEAM_HORDE];
    if (old_raid) old_raid->SetBattlegroundGroup(NULL);
    if (bg_raid) bg_raid->SetBattlegroundGroup(this);
    old_raid = bg_raid;
}

WorldSafeLocsEntry const* Battleground::GetClosestGraveYard(Player* player)
{
    return sObjectMgr->GetClosestGraveYard(player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetMapId(), player->GetTeam());
}

bool Battleground::IsTeamScoreInRange(uint32 team, uint32 minScore, uint32 maxScore) const
{
    BattlegroundTeamId team_idx = GetTeamIndexByTeamId(team);
    uint32 score = (m_TeamScores[team_idx] < 0) ? 0 : uint32(m_TeamScores[team_idx]);
    return score >= minScore && score <= maxScore;
}

void Battleground::StartTimedAchievement(AchievementCriteriaTimedTypes type, uint32 entry)
{
    for (BattlegroundPlayerMap::const_iterator itr = GetPlayers().begin(); itr != GetPlayers().end(); ++itr)
        if (Player* pPlayer = sObjectMgr->GetPlayer(itr->first))
            pPlayer->GetAchievementMgr().StartTimedAchievement(type, entry);
}

void Battleground::SetBracket(PvPDifficultyEntry const* bracketEntry)
{
    m_BracketId  = bracketEntry->GetBracketId();
    SetLevelRange(bracketEntry->minLevel,bracketEntry->maxLevel);
}

void Battleground::RewardXPAtKill(Player* plr, Player* victim)
{
    if (!sWorld->getBoolConfig(CONFIG_BG_XP_FOR_KILL) || !plr || !victim)
        return;

    uint32 xp = 0;
    Player* member_with_max_level = NULL;
    Player* not_gray_member_with_max_level = NULL;

    if (Group *pGroup = plr->GetGroup())//should be always in a raid group while in any bg
    {
        uint32 count = 0;
        uint32 sum_level = 0;
        for (GroupReference *itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
        {
            Player* member = itr->getSource();
            if (!member || !member->isAlive())                   // only for alive
                continue;

            if (!member->IsAtGroupRewardDistance(victim))        // at req. distance
                continue;

            ++count;
            sum_level += member->getLevel();
            if (!member_with_max_level || member_with_max_level->getLevel() < member->getLevel())
                member_with_max_level = member;

            uint32 gray_level = Trinity::XP::GetGrayLevel(member->getLevel());
            if (victim->getLevel() > gray_level && (!not_gray_member_with_max_level
               || not_gray_member_with_max_level->getLevel() < member->getLevel()))
                not_gray_member_with_max_level = member;
        }

        if (member_with_max_level)
        {
            xp = !not_gray_member_with_max_level ? 0 : Trinity::XP::Gain(not_gray_member_with_max_level, victim);

            if (!xp)
                return;

            float group_rate = 1.0f;

            for (GroupReference *itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
            {
                Player* pGroupGuy = itr->getSource();
                if (!pGroupGuy)
                    continue;

                if (!pGroupGuy->IsAtGroupRewardDistance(victim))
                    continue;                               // member (alive or dead) or his corpse at req. distance

                float rate = group_rate * float(pGroupGuy->getLevel()) / sum_level;

                // XP updated only for alive group member
                if (pGroupGuy->isAlive() && not_gray_member_with_max_level && pGroupGuy->getLevel() <= not_gray_member_with_max_level->getLevel())
                {
                    uint32 itr_xp = (member_with_max_level == not_gray_member_with_max_level) ? uint32(xp * rate) : uint32((xp * rate / 2) + 1);

                    // handle SPELL_AURA_MOD_XP_PCT auras
                    Unit::AuraEffectList const& ModXPPctAuras = plr->GetAuraEffectsByType(SPELL_AURA_MOD_XP_PCT);
                    for (Unit::AuraEffectList::const_iterator i = ModXPPctAuras.begin(); i != ModXPPctAuras.end(); ++i)
                        AddPctN(itr_xp, (*i)->GetAmount());

                    pGroupGuy->GiveXP(itr_xp, victim);
                    if (Pet* pet = pGroupGuy->GetPet())
                        pet->GivePetXP(itr_xp / 2);
                }
            }
        }
    }
    else//should be always in a raid group while in any BG, but you never know...
    {
        xp = Trinity::XP::Gain(plr, victim);

        if (!xp)
            return;

        // handle SPELL_AURA_MOD_XP_PCT auras
        Unit::AuraEffectList const& ModXPPctAuras = plr->GetAuraEffectsByType(SPELL_AURA_MOD_XP_PCT);
        for (Unit::AuraEffectList::const_iterator i = ModXPPctAuras.begin(); i != ModXPPctAuras.end(); ++i)
            AddPctN(xp, (*i)->GetAmount());

        plr->GiveXP(xp, victim);

        if (Pet* pet = plr->GetPet())
            pet->GivePetXP(xp);
    }
}
