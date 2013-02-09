/*  .Challenge Script for Saqirmdev/TrinityCore -> Thanks L30m4nc3r*/

#include "ScriptPCH.h"
#include "BattlegroundMgr.h"
#include "DisableMgr.h"

class challenge_commands : public CommandScript
{
public:
    challenge_commands() : CommandScript("challenge_commands") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand challengeCommandTable[] =
        {
            { "players",        SEC_MODERATOR,      false, &HandleChallengePlayersCommand,      "", NULL },
            { "",               SEC_PLAYER,         false, &HandleChallengeCommand,             "", NULL },
            { NULL,             0,                  false, NULL,                                "", NULL }
        };


        static ChatCommand commandTable[] =
        {
            { "challenge",      SEC_PLAYER,         false, NULL,                                "", challengeCommandTable },
            { NULL,             0,                  false, NULL,                                "", NULL }
        };
        return commandTable;
    }

    static bool HandleChallengeCommand(ChatHandler* handler, const char* args)
    {
        Player *target = NULL;
        Battleground *arena = NULL;

        if (!handler->extractPlayerTarget((char*)args, &target))
        {
            handler->PSendSysMessage("Cant find player.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (target == handler->GetSession()->GetPlayer())
        {
            handler->PSendSysMessage("You must select player.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!(arena = JoinPlayer(target, arena)))
        {
            handler->PSendSysMessage("Cant join Challenge");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!JoinPlayer(handler->GetSession()->GetPlayer(), arena))
        {
            if (target->challengeData)
            {
                target->challengeData->removeEvent->Execute(0, 0);
                delete (target->challengeData->removeEvent);
                delete target->challengeData;
                target->challengeData = NULL;
            }

            handler->PSendSysMessage("Cant join Challenge.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        return true;
    }

    static bool HandleChallengePlayersCommand(ChatHandler* handler, const char* args)
    {
        std::string sargs = args;
        Tokens playersTokens(sargs, ' ');
        if (playersTokens.size() != 2)
        {
            handler->PSendSysMessage("Neend 2 args!");
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player *player1 = sObjectMgr->GetPlayer(playersTokens[0]);
        Player *player2 = sObjectMgr->GetPlayer(playersTokens[1]);

        if (!player1 || !player2)
        {
            handler->PSendSysMessage("Cant find player.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        Battleground *arena = NULL;

        if (!(arena = JoinPlayer(player1, arena)))
        {
            handler->PSendSysMessage("Cant join Challenge.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!JoinPlayer(player2, arena))
        {
            if (player1->challengeData)
            {
                player1->challengeData->removeEvent->Execute(0, 0);
                delete (player1->challengeData->removeEvent);
                delete player1->challengeData;
                player1->challengeData = NULL;
            }

            handler->PSendSysMessage("Cant join Challenge.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        return true;
    }

private:
    static Battleground* JoinPlayer(Player *player, Battleground *arena)
    {
        // ignore if we already in BG or BG queue
       if (player->InBattleground())
            return NULL;

        uint8 arenatype = ARENA_TYPE_2v2;
        uint32 matchmakerRating = 0;

        //check existance
        Battleground* bg = sBattlegroundMgr->GetBattlegroundTemplate(BATTLEGROUND_AA);
        if (!bg)
        {
            sLog->outError("Battleground: template bg (all arenas) not found");
            return NULL;
        }

        if (sDisableMgr->IsDisabledFor(DISABLE_TYPE_BATTLEGROUND, BATTLEGROUND_AA, NULL))
        {
            ChatHandler(player).PSendSysMessage(LANG_ARENA_DISABLED);
            return NULL;
        }

        BattlegroundTypeId bgTypeId = bg->GetTypeID();
        BattlegroundQueueTypeId bgQueueTypeId = BattlegroundMgr::BGQueueTypeId(bgTypeId, arenatype);
        PvPDifficultyEntry const* bracketEntry = GetBattlegroundBracketByLevel(bg->GetMapId(), player->getLevel());
        if (!bracketEntry)
            return NULL;

        // check if already in queue
        if (player->GetBattlegroundQueueIndex(bgQueueTypeId) < PLAYER_MAX_BATTLEGROUND_QUEUES)
            //player is already in this queue
            return NULL;
        // check if has free queue slots
        if (!player->HasFreeBattlegroundQueueId())
            return NULL;

        uint32 queueSlot = player->AddBattlegroundQueueId(bgQueueTypeId);

        WorldPacket data;
        // send status packet (in queue)
        sBattlegroundMgr->BuildBattlegroundStatusPacket(&data, bg, queueSlot, STATUS_WAIT_QUEUE, 0, 0, arenatype);
        player->GetSession()->SendPacket(&data);
        sLog->outDebug(LOG_FILTER_BATTLEGROUND, "Battleground: player joined queue for arena, skirmish, bg queue type %u bg type %u: GUID %u, NAME %s", bgQueueTypeId, bgTypeId, player->GetGUIDLow(), player->GetName());

        sBattlegroundMgr->ScheduleQueueUpdate(matchmakerRating, arenatype, bgQueueTypeId, bgTypeId, bracketEntry->GetBracketId());

        GroupQueueInfo* ginfo            = new GroupQueueInfo;
        ginfo->BgTypeId                  = bgTypeId;
        ginfo->ArenaType                 = arenatype;
        ginfo->ArenaTeamId               = 0;
        ginfo->IsRated                   = 0;
        ginfo->IsInvitedToBGInstanceGUID = 0;
        ginfo->JoinTime                  = getMSTime();
        ginfo->RemoveInviteTime          = 0;
        ginfo->Team                      = player->GetTeam();
        ginfo->ArenaTeamRating           = 0;
        ginfo->ArenaMatchmakerRating     = 0;
        ginfo->OpponentsTeamRating       = 0;
        ginfo->OpponentsMatchmakerRating = 0;
        ginfo->Players.clear();

        PlayerQueueInfo* info = new PlayerQueueInfo;
        info->GroupInfo = ginfo;
        info->LastOnlineTime = getMSTime();

        ginfo->Players[player->GetGUID()]  = info;

        if (!arena)
        {
            arena = sBattlegroundMgr->CreateNewBattleground(bgTypeId, bracketEntry, arenatype, true);
            arena->SetRated(false);
            arena->SetChallenge(true);

            player->challengeData = new ChallengeData;
            player->challengeData->bg = arena;
            player->challengeData->ginfo = ginfo;

            InviteGroupToBG(ginfo, arena, ALLIANCE);
        }
        else
        {
            player->challengeData = new ChallengeData;
            player->challengeData->bg = arena;
            player->challengeData->ginfo = ginfo;

            InviteGroupToBG(ginfo, arena, HORDE);
            arena->StartBattleground();
            if (!sBattlegroundMgr->HasBattleground(arena))
                sBattlegroundMgr->AddBattleground(ginfo->IsInvitedToBGInstanceGUID, bgTypeId, arena);
        }

        return arena;
    }

    static bool InviteGroupToBG(GroupQueueInfo* ginfo, Battleground* bg, uint32 side)
    {
        // set side if needed
        if (side)
            ginfo->Team = side;

        if (!ginfo->IsInvitedToBGInstanceGUID)
        {
            // not yet invited
            // set invitation
            ginfo->IsInvitedToBGInstanceGUID = bg->GetInstanceID();
            BattlegroundTypeId bgTypeId = bg->GetTypeID();
            BattlegroundQueueTypeId bgQueueTypeId = BattlegroundMgr::BGQueueTypeId(bgTypeId, bg->GetArenaType());

            // set ArenaTeamId for rated matches
            if (bg->isArena() && bg->isRated())
                bg->SetArenaTeamIdForTeam(ginfo->Team, ginfo->ArenaTeamId);

            ginfo->RemoveInviteTime = getMSTime() + INVITE_ACCEPT_WAIT_TIME;

            // loop through the players
            for (std::map<uint64, PlayerQueueInfo*>::iterator itr = ginfo->Players.begin(); itr != ginfo->Players.end(); ++itr)
            {
                // get the player
                Player* player = ObjectAccessor::FindPlayer(itr->first);
                // if offline, skip him, this should not happen - player is removed from queue when he logs out
                if (!player)
                    continue;

                // set invited player counters
                bg->IncreaseInvitedCount(ginfo->Team);

                player->SetInviteForBattlegroundQueueType(bgQueueTypeId, ginfo->IsInvitedToBGInstanceGUID);

                BGQueueRemoveEvent* removeEvent = new BGQueueRemoveEvent(player->GetGUID(), ginfo->IsInvitedToBGInstanceGUID, bgTypeId, bgQueueTypeId, ginfo->RemoveInviteTime);
                player->challengeData->removeEvent = removeEvent;

                WorldPacket data;

                uint32 queueSlot = player->GetBattlegroundQueueIndex(bgQueueTypeId);

                sLog->outDebug(LOG_FILTER_BATTLEGROUND, "Battleground: invited player %s (%u) to BG instance %u queueindex %u bgtype %u, I can't help it if they don't press the enter battle button.", player->GetName(), player->GetGUIDLow(), bg->GetInstanceID(), queueSlot, bg->GetTypeID());

                // send status packet
                sBattlegroundMgr->BuildBattlegroundStatusPacket(&data, bg, queueSlot, STATUS_WAIT_JOIN, INVITE_ACCEPT_WAIT_TIME, 0, ginfo->ArenaType);
                player->GetSession()->SendPacket(&data);
            }
            return true;
        }

        return false;
    }

};

void AddSC_challenge_script()
{
    new challenge_commands();
}