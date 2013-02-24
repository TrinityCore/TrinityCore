#include "ScriptPCH.h"
#include "Item.h"

#ifndef ITEMMETHODS_H
#define ITEMMETHODS_H

class LuaItem
{
public:

    static int GetUnitType(lua_State* L, Item* item)
    {
        if(!item || !item->IsInWorld())
            return 0;

        Eluna::get()->PushString(L, "Item");
        return 1;
    }

    static int GetGUID(lua_State* L, Item* item)
    {
        if(!item || !item->IsInWorld())
            return 0;

        Eluna::get()->PushGUID(L, item->GetGUID());
        return 1;
    }

};
#endif
