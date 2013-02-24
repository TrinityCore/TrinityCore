#include "GameObject.h"

#ifndef GAMEOBJECTMETHODS_H
#define GAMEOBJECTMETHODS_H

class LuaGameObject
{
public:

    // GetUnitType()
    static int GetUnitType(lua_State* L, GameObject* go)
    {
        if(!go || !go->IsInWorld())
            return 0;

        Eluna::get()->PushString(L, "GameObject");
        return 1;
    }
    
    // GetGUID()
    static int GetGUID(lua_State* L, GameObject* go)
    {
        if(!go || !go->IsInWorld())
            return 0;

        Eluna::get()->PushGUID(L, go->GetGUID());
        return 1;
    }
};

#endif