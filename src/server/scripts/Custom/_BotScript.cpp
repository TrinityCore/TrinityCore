#pragma execution_character_set("utf-8")
#include "_Bot.h"
#include "Player.h"
#include "Config.h"
#include "..\..\src\server\game\Globals\ObjectAccessor.h"
#include "LoginQueryHolder.h"
#include "DatabaseEnv.h"
#include "..\..\src\server\game\Server\WorldSession.h"
#include "..\..\src\server\game\Maps\MapManager.h"
#include "ScriptMgr.h"
#include "Chat.h"
#include "CustomTalkMenu.h"
#include <PlayerBotMgr.h>
#include "group.h"
#include "SocialMgr.h"
#include <FieldBotMgr.h>
#include <ArenaTeam.h>
#include <ArenaTeamMgr.h>
#include "Guild.h"

bool BindingHomePosition(Player* player)
{
    if (!player || !player->IsInWorld() || player->GetMap()->IsDungeon())
        return false;
    if (!MapManager::IsValidMapCoord(player->GetMapId(), player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetOrientation()))
        return false;

    uint32 bindspell = 3286;

    // send spell for homebinding (3286)
    player->CastSpell(player, bindspell, true);
    return true;
}

bool SuperMenu(Player* player)
{
    sCustomTalkMenu->DisplayMainMenu(player);
    return true;
}

bool OnlineCmd(Player* player, uint32 cls)
{
    if (cls < 1 || cls > 11 || cls == 6 || cls == 10)
        return false;
   /* sPlayerBotMgr->AddNewPlayerBot(((player->GetTeamId() == TEAM_ALLIANCE) ? true : false), Classes(cls), 1);*/   //org

    sPlayerBotMgr->AddNewPlayerBot(player->GetTeamId(), Classes(cls), 1);


    return true;
}

bool AccountCmd(Player* player, uint32 cls)
{
    if (cls < 1 || cls > 11 || cls == 10)
        return false;
    //sPlayerBotMgr->AddNewAccountBot(((player->GetTeamId() == TEAM_ALLIANCE) ? true : false), Classes(cls));//org
    sPlayerBotMgr->AddNewAccountBot(player->GetTeamId(), Classes(cls));
    return true;
}

bool OfflineCmd(Player* /*player*/)
{
    sPlayerBotMgr->AllPlayerBotLogout();
    return true;
}

bool ResetDungeon(Player* player)
{
    if (!player || !player->IsInWorld())
        return false;
    if (player->GetMap()->IsDungeon())
        return true;
    Group* pGroup = player->GetGroup();
    if (pGroup)
    {
        //pGroup->ResetRaidDungeon();//org
        pGroup->ResetInstances(InstanceResetMethod::Manual,player);
        
    }
    else
    {
        //player->ResetInstances(INSTANCE_RESET_ALL, false);    //org
        //player->ResetInstances(INSTANCE_RESET_ALL, true);     //org

        player->ResetInstances(InstanceResetMethod::Manual);
       
    }
    return true;
}

bool AddGroupFriend(Player* player)
{
    Group* pGroup = player->GetGroup();
    PlayerSocial* pSocial = player->GetSocial();
    if (!pSocial || !pGroup || pGroup->isBGGroup() || pGroup->isBFGroup())
        return false;
    Group::MemberSlotList const& memList = pGroup->GetMemberSlots();
    for (Group::MemberSlot const& slot : memList)
    {
        ObjectGuid ignoreAccountGuid ;//I
        Player* friendPlayer = ObjectAccessor::FindPlayer(slot.guid);
        if (!friendPlayer || friendPlayer == player || friendPlayer->GetTeamId() != player->GetTeamId() ||
            pSocial->HasFriend(friendPlayer->GetGUID()) || pSocial->HasIgnore(friendPlayer->GetGUID(),ignoreAccountGuid)) //,ignoreAccountGuid --> I
            continue;
        WorldPacket opcode(1);
        opcode << friendPlayer->GetName();
        opcode << "";

        //player->GetSession()->HandleAddFriendOpcode(opcode);//WorldPackets::Social::AddFriend& opcode2;
        pSocial->SendSocialList(player,0);//,0-->I
        break;
    }
    return true;
}

bool OnlineFriends(Player* player)
{
    if (player)
        sPlayerBotMgr->LoginFriendBotByPlayer(player);
    return true;
}

bool Saveall(Player* player)
{
    ObjectAccessor::SaveAllPlayers();
    Group* pGroup = player->GetGroup();
    if (pGroup)
    {
        sPlayerBotMgr->LogoutAllGroupPlayerBot(pGroup, true);
    }
    return true;
}

bool ToggleWarfareAid(Player* /*player*/)
{
    if (sFieldBotMgr->ExistWarfare())
    {
        FieldWarfare::AID_TARGET_TEAM = !FieldWarfare::AID_TARGET_TEAM;
        return true;
    }
    return false;
}

bool OnlineArenaTeamMember(Player* player, uint32 /*arenaType*/)
{
    ArenaTeam* arenaTeam = sArenaTeamMgr->GetArenaTeamById(player->GetGUID().GetCounter());//GetArenaTypeTeamByGUID
    if (arenaTeam)
    {
        for (ArenaTeam::MemberList::iterator itaMem = arenaTeam->m_membersBegin(); itaMem != arenaTeam->m_membersEnd(); itaMem++)
        {
            ArenaTeamMember& mem = *itaMem;
            ObjectGuid guid = mem.Guid;
            if (guid == player->GetGUID())
                continue;
            sPlayerBotMgr->DelayLoginPlayerBotByGUID(guid);
        }
        return true;
    }
    return true;
}

bool OnlineGuildMember(Player* player)
{
    Guild* pGuild = player->GetGuild();
    if (!pGuild)
        return true;
    //std::list<ObjectGuid>& guids = pGuild->GetAllMemberGUID();
    //for (ObjectGuid& guid : guids)
    //{
    //    if (guid == player->GetGUID())
    //        continue;
    //    sPlayerBotMgr->DelayLoginPlayerBotByGUID(guid);
    //}
    return true;
}



bool MyBot::ProcessCommand(Player* player, std::string cmd)
{
    if (!player)
        return false;
    uint32 index = cmd.find(' ');
    if (index < 1)
        return false;
    std::string cmdText = cmd.substr(0, index);
    std::string paramText = cmd.substr(index + 1);
    int param = atoi(paramText.c_str());

    if (cmdText == "bindinghome")
        return BindingHomePosition(player);
    else if (cmdText == "supermenu")
        return SuperMenu(player);
    else if (cmdText == "offlineallbot")
        return OfflineCmd(player);
    else if (cmdText == "onlineselfbot")
        return OnlineCmd(player, param);
    else if (cmdText == "onlineaccbot")
        return AccountCmd(player, param);
    else if (cmdText == "groupfriend")
        return AddGroupFriend(player);
    else if (cmdText == "resetdungeon")
        return ResetDungeon(player);
    else if (cmdText == "onlinefriends")
        return OnlineFriends(player);
    else if (cmdText == "saveall")
        return Saveall(player);
    else if (cmdText == "warfareaid")
        return ToggleWarfareAid(player);
    else if (cmdText == "onlinearenateam2")
        return OnlineArenaTeamMember(player, 2);
    else if (cmdText == "onlinearenateam3")
        return OnlineArenaTeamMember(player, 3);
    else if (cmdText == "onlinearenateam5")
        return OnlineArenaTeamMember(player, 5);
    else if (cmdText == "onlineguildmember")
        return OnlineGuildMember(player);
    return false;
}
