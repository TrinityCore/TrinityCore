#include "GameObject.h"

#ifndef GAMEOBJECTMETHODS_H
#define GAMEOBJECTMETHODS_H

class LuaGameObject
{
public:

    // Gossip Methods
    // GossipMenuAddItem(icon, msg, Intid, code, accept_decline_message, money)
    static int GossipMenuAddItem(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        Player* receiver = Eluna::get()->CHECK_PLAYER(L, 1);
        int _icon = luaL_checknumber(L, 2);
        const char* msg = luaL_checkstring(L, 3);
        int _intid = luaL_checknumber(L, 4);
        bool _code = luaL_optint(L, 5, false);
        const char* _promptMsg = luaL_optstring(L, 6, "");
        int _money = luaL_optint(L, 7, 0);
        receiver->ADD_GOSSIP_ITEM_EXTENDED(_icon, msg, GOSSIP_SENDER_MAIN, _intid, _promptMsg, _money, _code);
        return 0;
    }

    // GossipComplete()
    static int GossipComplete(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        Player* receiver = Eluna::get()->CHECK_PLAYER(L, 1);
        receiver->CLOSE_GOSSIP_MENU();
        return 0;
    }

    // GossipSendMenu(npc_text, unit)
    static int GossipSendMenu(lua_State* L, GameObject* go)
    {
        if (!go || !go->IsInWorld())
            return 0;

        int _npcText = luaL_checknumber(L, 1);
        Player* receiver = Eluna::get()->CHECK_PLAYER(L, 2);
        receiver->SEND_GOSSIP_MENU(_npcText, go->GetGUID());
        return 0;
    }
};

#endif