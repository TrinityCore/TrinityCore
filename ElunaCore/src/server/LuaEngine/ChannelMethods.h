#include "ScriptPCH.h"
#include "ChannelMgr.h"

#ifndef CHANNELMETHODS_H
#define CHANNELMETHODS_H

class LuaChannel
{
public:
    
    static int GetUnitType(lua_State* L, Channel* channel)
    {
        if(!channel)
            return 0;

        Eluna::get()->PushString(L, "Channel");
        return 1;
    }
};
#endif
