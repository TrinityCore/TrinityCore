/*
* Copyright (C) 2010 - 2014 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information
*/

#ifndef GUILDMETHODS_H
#define GUILDMETHODS_H

namespace LuaGuild
{
    int GetMembers(lua_State* L, Guild* guild)
    {
        lua_newtable(L);
        int tbl = lua_gettop(L);
        uint32 i = 0;

        SessionMap const& sessions = sWorld->GetAllSessions();
        for (SessionMap::const_iterator it = sessions.begin(); it != sessions.end(); ++it)
        {
            if (Player* player = it->second->GetPlayer())
            {
                if (player->GetSession() && (player->GetGuildId() == guild->GetId()))
                {
                    ++i;
                    sEluna->Push(L, i);
                    sEluna->Push(L, player);
                    lua_settable(L, tbl);
                }
            }
        }

        lua_settop(L, tbl); // push table to top of stack
        return 1;
    }

    int GetMemberCount(lua_State* L, Guild* guild)
    {
        sEluna->Push(L, guild->GetMemberSize());
        return 1;
    }

    int GetLeader(lua_State* L, Guild* guild)
    {
#ifdef MANGOS
        sEluna->Push(L, sObjectAccessor->FindPlayer(guild->GetLeaderGuid()));
#else
        sEluna->Push(L, sObjectAccessor->FindPlayer(guild->GetLeaderGUID()));
#endif
        return 1;
    }

#ifndef CATA
    int SetLeader(lua_State* L, Guild* guild)
    {
        Player* player = sEluna->CHECKOBJ<Player>(L, 2);

#ifdef MANGOS
        guild->SetLeader(player->GET_GUID());
#else
        guild->HandleSetLeader(player->GetSession(), player->GetName());
#endif
        return 0;
    }
#endif

    int GetLeaderGUID(lua_State* L, Guild* guild)
    {
#ifdef MANGOS
        sEluna->Push(L, guild->GetLeaderGuid());
#else
        sEluna->Push(L, guild->GetLeaderGUID());
#endif
        return 1;
    }

    // SendPacketToGuild(packet)
    int SendPacket(lua_State* L, Guild* guild)
    {
        WorldPacket* data = sEluna->CHECKOBJ<WorldPacket>(L, 2);

        guild->BroadcastPacket(data);
        return 0;
    }

    // SendPacketToRankedInGuild(packet, rankId)
    int SendPacketToRanked(lua_State* L, Guild* guild)
    {
        WorldPacket* data = sEluna->CHECKOBJ<WorldPacket>(L, 2);
        uint8 ranked = sEluna->CHECKVAL<uint8>(L, 3);

        guild->BroadcastPacketToRank(data, ranked);
        return 0;
    }

    int Disband(lua_State* L, Guild* guild)
    {
        guild->Disband();
        return 0;
    }

    int GetId(lua_State* L, Guild* guild)
    {
        sEluna->Push(L, guild->GetId());
        return 1;
    }

    int GetName(lua_State* L, Guild* guild)
    {
        sEluna->Push(L, guild->GetName());
        return 1;
    }

    int GetMOTD(lua_State* L, Guild* guild)
    {
        sEluna->Push(L, guild->GetMOTD());
        return 1;
    }

    int GetInfo(lua_State* L, Guild* guild)
    {
#ifdef MANGOS
        sEluna->Push(L, guild->GetGINFO());
#else
        sEluna->Push(L, guild->GetInfo());
#endif
        return 1;
    }

    int AddMember(lua_State* L, Guild* guild)
    {
        Player* player = sEluna->CHECKOBJ<Player>(L, 2);
        uint8 rankId = sEluna->CHECKVAL<uint8>(L, 3, GUILD_RANK_NONE);

        guild->AddMember(player->GET_GUID(), rankId);
        return 0;
    }

    int DeleteMember(lua_State* L, Guild* guild)
    {
        Player* player = sEluna->CHECKOBJ<Player>(L, 2);
        bool isDisbanding = sEluna->CHECKVAL<bool>(L, 3, false);

#ifdef MANGOS
        guild->DelMember(player->GET_GUID(), isDisbanding);
#else
        guild->DeleteMember(player->GET_GUID(), isDisbanding);
#endif
        return 0;
    }

    int ChangeMemberRank(lua_State* L, Guild* guild)
    {
        Player* player = sEluna->CHECKOBJ<Player>(L, 2);
        uint8 newRank = sEluna->CHECKVAL<uint8>(L, 3);

        guild->ChangeMemberRank(player->GET_GUID(), newRank);
        return 0;
    }

    int SetBankTabText(lua_State* L, Guild* guild)
    {
        uint8 tabId = sEluna->CHECKVAL<uint8>(L, 2);
        const char* text = sEluna->CHECKVAL<const char*>(L, 3);
#ifdef MANGOS
        guild->SetGuildBankTabText(tabId, text);
#else
        guild->SetBankTabText(tabId, text);
#endif
        return 0;
    }

    // Move to Player methods
    int WithdrawBankMoney(lua_State* L, Guild* guild)
    {
        Player* player = sEluna->CHECKOBJ<Player>(L, 2);
        uint32 money = sEluna->CHECKVAL<uint32>(L, 3);
#ifdef MANGOS
        if (guild->GetGuildBankMoney() < money)
            return 0;
        guild->SetBankMoney(guild->GetGuildBankMoney() - money);
#else
        guild->HandleMemberWithdrawMoney(player->GetSession(), money);
#endif
        return 0;
    }

    // Move to Player methods
    int DepositBankMoney(lua_State* L, Guild* guild)
    {
        Player* player = sEluna->CHECKOBJ<Player>(L, 2);
        uint32 money = sEluna->CHECKVAL<uint32>(L, 3);

#ifdef MANGOS
        guild->SetBankMoney(guild->GetGuildBankMoney() + money);
#else
        guild->HandleMemberDepositMoney(player->GetSession(), money);
#endif
        return 0;
    }
};
#endif
