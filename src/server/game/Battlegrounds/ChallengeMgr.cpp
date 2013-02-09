#include "ChallengeMgr.h"
#include "DatabaseEnv.h"
#include "ObjectAccessor.h"
#include "DisableMgr.h"
#include "Chat.h"
#include "Group.h"
 
void ChallengeMgr::LoadOptions()
{
    uint32 oldMSTime = getMSTime();
 
    QueryResult result = CharacterDatabase.Query("SELECT `guid`, `mode`, `enable` FROM `challenge_options`");
    if (!result)
    {
        sLog->outString(">> Loaded 0 options. Table `challenge_options` is empty!");
        sLog->outString();
        return;
    }
 
    do
    {
        Field* fields = result->Fetch();
 
        ChallengeOption *option = new ChallengeOption;
        option->changed  = false;
        option->enable  = fields[2].GetBool();
        option->mode    = fields[1].GetUInt8();
 
        m_options[fields[0].GetUInt64()] = option;
    }
    while (result->NextRow());
 
    sLog->outString(">> Loaded %u options. In %u ms.", m_options.size(), GetMSTimeDiffToNow(oldMSTime));
    sLog->outString();
}
 
void ChallengeMgr::Update(uint32 diff)
{
    m_events.Update(diff);
}
 
bool ChallengeMgr::InviteGroupsToArena(Player *leader1, Player *leader2, ArenaChallengeType type)
{
    uint8 arenatype = (type == ARENA_CHALLENGE_TYPE_1v1) ? ARENA_CHALLENGE_TYPE_2v2 : type;
    uint32 matchmakerRating = 0;
 
    //check existance
    Battleground* bg = sBattlegroundMgr->GetBattlegroundTemplate(BATTLEGROUND_AA);
    if (!bg)
    {
        sLog->outError("Battleground: template bg (all arenas) not found");
        return false;
    }
 
    BattlegroundTypeId bgTypeId = bg->GetTypeID();
    BattlegroundQueueTypeId bgQueueTypeId = BattlegroundMgr::BGQueueTypeId(bgTypeId, arenatype);
    PvPDifficultyEntry const* bracketEntry = GetBattlegroundBracketByLevel(bg->GetMapId(), 80);
    if (!bracketEntry)
        return false;
 
    GroupQueueInfo *group1, *group2;
    if (type == ARENA_CHALLENGE_TYPE_1v1)
    {
        group1 = CreateGroupQueueInfo(leader1, bgTypeId, arenatype);
        group2 = CreateGroupQueueInfo(leader2, bgTypeId, arenatype);
    }
    else
    {
        group1 = CreateGroupQueueInfo(leader1->GetGroup(), bgTypeId, arenatype);
        group2 = CreateGroupQueueInfo(leader2->GetGroup(), bgTypeId, arenatype);
    }
 
    if (!group1 || !group2)
        return false;
 
    for (std::map<uint64, PlayerQueueInfo*>::iterator itr = group1->Players.begin(); itr != group1->Players.end(); ++itr)
    {
        Player *player = ObjectAccessor::FindPlayer(itr->first);
        if (!player)
            return false;
 
        if (!CanInvitePlayer(player, bgQueueTypeId))
            return false;
    }
 
    for (std::map<uint64, PlayerQueueInfo*>::iterator itr = group2->Players.begin(); itr != group2->Players.end(); ++itr)
    {
        Player *player = ObjectAccessor::FindPlayer(itr->first);
        if (!player)
            return false;
 
        if (!CanInvitePlayer(player, bgQueueTypeId))
            return false;
    }
 
    sBattlegroundMgr->ScheduleQueueUpdate(matchmakerRating, arenatype, bgQueueTypeId, bgTypeId, bracketEntry->GetBracketId());
 
    Battleground *arena = sBattlegroundMgr->CreateNewBattleground(bgTypeId, bracketEntry, arenatype, true);
    arena->SetRated(false);
  	
    if (type == ARENA_CHALLENGE_TYPE_1v1)
        arena->Set1vs1(true);
 
    for (std::map<uint64, PlayerQueueInfo*>::iterator itr = group1->Players.begin(); itr != group1->Players.end(); ++itr)
    {
        Player *player = ObjectAccessor::FindPlayer(itr->first);
        if (!player)
            return false;
 
        uint32 queueSlot = player->AddBattlegroundQueueId(bgQueueTypeId);
 
        WorldPacket data;
        // send status packet (in queue)
        sBattlegroundMgr->BuildBattlegroundStatusPacket(&data, bg, queueSlot, STATUS_WAIT_QUEUE, 0, 0, arenatype);
        player->GetSession()->SendPacket(&data);
 
        player->challengeData->bg = arena;
        player->challengeData->ginfo = CreateGroupQueueInfo(player, bgTypeId, arenatype);
        player->challengeData->ginfo->IsInvitedToBGInstanceGUID = arena->GetInstanceID();
        player->challengeData->ginfo->Team = ALLIANCE;
    }
 
    for (std::map<uint64, PlayerQueueInfo*>::iterator itr = group2->Players.begin(); itr != group2->Players.end(); ++itr)
    {
        Player *player = ObjectAccessor::FindPlayer(itr->first);
        if (!player)
            return false;
 
        uint32 queueSlot = player->AddBattlegroundQueueId(bgQueueTypeId);
 
        WorldPacket data;
        // send status packet (in queue)
        sBattlegroundMgr->BuildBattlegroundStatusPacket(&data, bg, queueSlot, STATUS_WAIT_QUEUE, 0, 0, arenatype);
        player->GetSession()->SendPacket(&data);
 
        player->challengeData->bg = arena;
        player->challengeData->ginfo = CreateGroupQueueInfo(player, bgTypeId, arenatype);
        player->challengeData->ginfo->IsInvitedToBGInstanceGUID = arena->GetInstanceID();
        player->challengeData->ginfo->Team = HORDE;
    }
 
    InviteGroupToArena(group1, arena, ALLIANCE);
    InviteGroupToArena(group2, arena, HORDE);
 
    arena->StartBattleground();
 
    if (!sBattlegroundMgr->HasBattleground(arena))
        sBattlegroundMgr->AddBattleground(group1->IsInvitedToBGInstanceGUID, bgTypeId, arena);
 
    return true;
}
 
bool ChallengeMgr::CanInvitePlayer(Player *player, BattlegroundQueueTypeId bgQueueTypeId)
{
    if (player->getLevel() != 80)
        return false;
 
    // ignore if we already in BG or BG queue
    if (player->InBattleground())
        return false;
 
    if (sDisableMgr->IsDisabledFor(DISABLE_TYPE_BATTLEGROUND, BATTLEGROUND_AA, NULL))
    {
        ChatHandler(player).PSendSysMessage(LANG_ARENA_DISABLED);
        return false;
    }
 
    // check if already in queue
    if (player->GetBattlegroundQueueIndex(bgQueueTypeId) < PLAYER_MAX_BATTLEGROUND_QUEUES)
        //player is already in this queue
        return false;
    // check if has free queue slots
    if (!player->HasFreeBattlegroundQueueId())
        return false;
 
    return true;
}
 
bool ChallengeMgr::InviteGroupToArena(GroupQueueInfo *ginfo, Battleground *bg, uint32 side)
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
            m_events.AddEvent(removeEvent, m_events.CalculateTime(CHALLENGE_START_COUNTDOWN));
            //            player->challengeData->removeEvent = removeEvent;
 
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
 
GroupQueueInfo* ChallengeMgr::CreateGroupQueueInfo(Group *group, BattlegroundTypeId bgTypeId, uint8 arenatype)
{
    Player *leader = ObjectAccessor::FindPlayer(group->GetLeaderGUID());
    if (!leader)
        return NULL;
 
    GroupQueueInfo* ginfo            = new GroupQueueInfo;
    ginfo->BgTypeId                  = bgTypeId;
    ginfo->ArenaType                 = arenatype;
    ginfo->ArenaTeamId               = 0;
    ginfo->IsRated                   = 0;
    ginfo->IsInvitedToBGInstanceGUID = 0;
    ginfo->JoinTime                  = getMSTime();
    ginfo->RemoveInviteTime          = 0;
    ginfo->Team                      = leader->GetTeam();
    ginfo->ArenaTeamRating           = 0;
    ginfo->ArenaMatchmakerRating     = 0;
    ginfo->OpponentsTeamRating       = 0;
    ginfo->OpponentsMatchmakerRating = 0;
    ginfo->Players.clear();
 
    PlayerQueueInfo* info = new PlayerQueueInfo;
    info->GroupInfo = ginfo;
    info->LastOnlineTime = getMSTime();
 
    Group::MemberSlotList hList = group->GetMemberSlots();
    for (Group::MemberSlotList::iterator itr = hList.begin(); itr != hList.end(); ++itr)
        ginfo->Players[(*itr).guid]  = info;
 
    return ginfo;
}
 
GroupQueueInfo* ChallengeMgr::CreateGroupQueueInfo(Player *player, BattlegroundTypeId bgTypeId, uint8 arenatype)
{
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
 
    return ginfo;
}
 
ChallengeOption* ChallengeMgr::GetChallengeOption(uint64 playerGuid)
{
    OptionsContainer::iterator itr = m_options.find(playerGuid);
    if (itr == m_options.end())
    {
        ChallengeOption *option = new ChallengeOption;
        option->changed = true;
        option->enable = true;
        option->mode   = 0;
        m_options[playerGuid] = option;
 
        return option;
    }
 
    return itr->second;
}
 
bool ChallengeMgr::MakeChallengeOffer(Player *challenger, Player *challengeTo, ArenaChallengeType type)
{
    if (challenger->challengeData->challengeTo || challenger->challengeData->challenger)
    {
        ChatHandler(challenger).PSendSysMessage("Someone must make decision.");
        return false;
    }
 
    if (challengeTo->challengeData->challengeTo || challengeTo->challengeData->challenger)
    {
        ChatHandler(challenger).PSendSysMessage("He is already in queue.");
        return false;
    }
 
    challenger->challengeData->challengeTo    = challengeTo->GetGUID();
    challenger->challengeData->challengeType  = type;
 
    challengeTo->challengeData->challenger    = challenger->GetGUID();
    challengeTo->challengeData->challengeType = type;
 
    ChatHandler(challengeTo).PSendSysMessage("Player %s, has challenged you in %ux%u. To accept offer, write .challenge accept.",
                                             challenger->GetName(), type, type);
 
    ChallengeWaitingAcceptEvent *waitEvent = new ChallengeWaitingAcceptEvent(challengeTo->GetGUID());
    m_events.AddEvent(waitEvent, m_events.CalculateTime(CHALLENGE_OFFER_WAITING));
 
    return true;
}
 
bool ChallengeWaitingAcceptEvent::Execute(uint64 /*e_time*/, uint32 /*p_time*/)
{
    sLog->outString("LOL");
    Player *player = ObjectAccessor::FindPlayer(m_PlayerGuid);
    if (!player)
        return true;
 
    ChatHandler(player).PSendSysMessage("Offer for challenge was canceled!");
 
    if (Player *challenger = ObjectAccessor::FindPlayer(player->challengeData->challenger))
    {
        challenger->challengeData->challengeTo = 0;
        ChatHandler(challenger).PSendSysMessage("Offer for challenge was canceled!");
    }
 
    player->challengeData->challenger = 0;
    return true;
}
 
void ChallengeWaitingAcceptEvent::Abort(uint64 /*e_time*/)
{
}