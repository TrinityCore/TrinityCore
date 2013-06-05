#ifndef AURAMETHODS_H
#define AURAMETHODS_H

namespace LuaAura
{
    int GetUnitType(lua_State*, Aura*);
    int GetCaster(lua_State*, Aura*);
    int GetCasterGUID(lua_State*, Aura*);
    int GetCasterLevel(lua_State*, Aura*);
    int GetDuration(lua_State*, Aura*);
    int GetCharges(lua_State*, Aura*);
    int GetAuraId(lua_State*, Aura*);
    int GetMaxDuration(lua_State*, Aura*);
    int GetStackAmount(lua_State*, Aura*);
    int SetDuration(lua_State*, Aura*);
    int SetMaxDuration(lua_State*, Aura*);
    int SetStackAmount(lua_State*, Aura*);
    int Remove(lua_State*, Aura*);
    int GetOwner(lua_State*, Aura*);
};
#endif
