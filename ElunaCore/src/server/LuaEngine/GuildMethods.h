#include "ScriptPCH.h"
#include "Guild.h"
#include "GuildMgr.h"

#ifndef GUILDMETHODS_H
#define GUILDMETHODS_H

class LuaGuild
{
public:

    static int GetMembers(lua_State* L, Guild* pGuild)
    {
        if(!pGuild)
            return 0;

        lua_newtable(L);
        int tbl = lua_gettop(L);
        uint32 i = 0;

        // Note that the following is very hacky, I don't like it and it SHOULD be changed ASAP.

        TRINITY_READ_GUARD(HashMapHolder<Player>::LockType, *HashMapHolder<Player>::GetLock());
        HashMapHolder<Player>::MapType const& m = sObjectAccessor->GetPlayers();
        for (HashMapHolder<Player>::MapType::const_iterator itr = m.begin(); itr != m.end(); ++itr)
        {
            if(itr->second->GetGuildId() == pGuild->GetId())
            {
                ++i;
                Eluna::get()->PushUnsigned(L, i);
                Eluna::get()->PushUnit(L, itr->second);
                lua_settable(L, tbl);
            }
        }

        lua_settop(L, tbl); // push table to top of stack
        return 1;
    }

    static int GetUnitType(lua_State* L, Guild* pGuild)
    {
        if(!pGuild)
            return 0;

        Eluna::get()->PushString(L, "Guild");
        return 1;
    }

    static int GetLeaderGUID(lua_State* L, Guild* pGuild)
    {
        if(!pGuild)
            return 0;

        Eluna::get()->PushGUID(L, pGuild->GetLeaderGUID());
        return 1;
    }

    // SendPacketToGuild(packet)
    static int SendPacket(lua_State* L, Guild* pGuild)
    {
        if(!pGuild)
            return 0;

        WorldPacket* data = Eluna::get()->CHECK_PACKET(L, 1);

        if (data)
            pGuild->BroadcastPacket(data);
        return 0;
    }

    // SendPacketToRankedInGuild(packet, rankId)
    static int SendPacketToRanked(lua_State* L, Guild* pGuild)
    {
        if(!pGuild)
            return 0;

        WorldPacket* data = Eluna::get()->CHECK_PACKET(L, 1);
        uint8 ranked = luaL_checkunsigned(L, 2);

        if (data)
            pGuild->BroadcastPacketToRank(data, ranked);
        return 0;
    }

    static int Disband(lua_State* L, Guild* pGuild)
    {
        if(!pGuild)
            return 0;

        pGuild->Disband();
        return 0;
    }

    static int GetId(lua_State* L, Guild* pGuild)
    {
        if(!pGuild)
            return 0;

        Eluna::get()->PushUnsigned(L, pGuild->GetId());
        return 1;
    }

    static int GetName(lua_State* L, Guild* pGuild)
    {
        if(!pGuild)
            return 0;

        Eluna::get()->PushString(L, pGuild->GetName().c_str());
        return 1;
    }

    static int GetMOTD(lua_State* L, Guild* pGuild)
    {
        if(!pGuild)
            return 0;

        Eluna::get()->PushString(L, pGuild->GetMOTD().c_str());
        return 1;
    }

    static int GetInfo(lua_State* L, Guild* pGuild)
    {
        if(!pGuild)
            return 0;

        Eluna::get()->PushString(L, pGuild->GetInfo().c_str());
        return 1;
    }

    static int AddMember(lua_State* L, Guild* pGuild)
    {
        if(!pGuild)
            return 0;

        Player* player = Eluna::get()->CHECK_PLAYER(L, 1);
        uint8 rankId = luaL_optint(L, 2, GUILD_RANK_NONE);

        if(player)
            pGuild->AddMember(player->GetGUID(), rankId);
        return 0;
    }

    static int DeleteMember(lua_State* L, Guild* pGuild)
    {
        if(!pGuild)
            return 0;

        Player* player = Eluna::get()->CHECK_PLAYER(L, 1);
        bool isDisbanding = luaL_optbool(L, 2, false);
        bool isKicked = luaL_optbool(L, 3, false);

        if(player)
            pGuild->DeleteMember(player->GetGUID(), isDisbanding, isKicked);
        return 0;
    }

    static int ChangeMemberRank(lua_State* L, Guild* pGuild)
    {
        if(!pGuild)
            return 0;

        Player* player = Eluna::get()->CHECK_PLAYER(L, 1);
        uint8 newRank = luaL_checkunsigned(L, 2);

        if(player)
            pGuild->ChangeMemberRank(player->GetGUID(), newRank);
        return 0;
    }

    static int SetBankTabText(lua_State* L, Guild* pGuild)
    {
        if(!pGuild)
            return 0;

        uint8 tabId = luaL_checkunsigned(L, 1);
        const char* text = luaL_checkstring(L, 2);

        pGuild->SetBankTabText(tabId, text);
        return 0;
    }
};
#endif
