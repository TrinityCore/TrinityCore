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
        sEluna->Push(L, sObjectAccessor->FindPlayer(guild->GetLeaderGUID()));
        return 1;
    }

    int SetLeader(lua_State* L, Guild* guild)
    {
        Player* player = sEluna->CHECK_PLAYER(L, 1);
        if (!player)
            return 0;

        guild->HandleSetLeader(player->GetSession(), player->GetName());
        return 0;
    }

    int GetLeaderGUID(lua_State* L, Guild* guild)
    {
        sEluna->Push(L, guild->GetLeaderGUID());
        return 1;
    }

    // SendPacketToGuild(packet)
    int SendPacket(lua_State* L, Guild* guild)
    {
        WorldPacket* data = sEluna->CHECK_PACKET(L, 1);

        if (data)
            guild->BroadcastPacket(data);
        return 0;
    }

    // SendPacketToRankedInGuild(packet, rankId)
    int SendPacketToRanked(lua_State* L, Guild* guild)
    {
        WorldPacket* data = sEluna->CHECK_PACKET(L, 1);
        uint8 ranked = luaL_checkunsigned(L, 2);

        if (data)
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
        sEluna->Push(L, guild->GetInfo());
        return 1;
    }

    int AddMember(lua_State* L, Guild* guild)
    {
        Player* player = sEluna->CHECK_PLAYER(L, 1);
        uint8 rankId = luaL_optint(L, 2, GUILD_RANK_NONE);

        if (player)
            guild->AddMember(player->GetGUID(), rankId);
        return 0;
    }

    int DeleteMember(lua_State* L, Guild* guild)
    {
        Player* player = sEluna->CHECK_PLAYER(L, 1);
        bool isDisbanding = luaL_optbool(L, 2, false);

        if (player)
            guild->DeleteMember(player->GetGUID(), isDisbanding);
        return 0;
    }

    int ChangeMemberRank(lua_State* L, Guild* guild)
    {
        Player* player = sEluna->CHECK_PLAYER(L, 1);
        uint8 newRank = luaL_checkunsigned(L, 2);

        if (player)
            guild->ChangeMemberRank(player->GetGUID(), newRank);
        return 0;
    }

    int SetBankTabText(lua_State* L, Guild* guild)
    {
        uint8 tabId = luaL_checkunsigned(L, 1);
        const char* text = luaL_checkstring(L, 2);
        guild->SetBankTabText(tabId, text);
        return 0;
    }

    /*int GetBankMoney(lua_State* L, Guild* guild)
    {
        sEluna->Push(L, guild->GetGuildBankMoney());
        return 1;
    }*/

    /*int WithdrawBankMoney(lua_State* L, Guild* guild)
    {
        Player* player = sEluna->CHECK_PLAYER(L, 1);
        uint32 money = luaL_checknumber(L, 2);

        if (!player || (guild->GetGuildBankMoney() - money) < 0)
            return 0;

        player->SetMoney(player->GetMoney() + money);
        guild->SetBankMoney(guild->GetGuildBankMoney() - money);
        return 0;
    }*/

    /*int DepositBankMoney(lua_State* L, Guild* guild)
    {
        Player* player = sEluna->CHECK_PLAYER(L, 1);
        uint32 money = luaL_checknumber(L, 2);

        if (!player || (player->GetMoney() - money) < 0)
            return 0;

        player->SetMoney(player->GetMoney() - money);
        guild->DepositBankMoney(guild->GetGuildBankMoney() + money);
        return 0;
    }*/
};
#endif
