#include "ScriptPCH.h"

#ifndef AURAMETHODS_H
#define AURAMETHODS_H

class LuaAura
{
public:
    
    static int GetUnitType(lua_State* L, Aura* aura)
    {
        if(!aura)
            return 0;

        Eluna::get()->PushString(L, "Aura");
        return 1;
    }
};
#endif
