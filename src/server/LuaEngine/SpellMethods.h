#ifndef SPELLMETHODS_H
#define SPELLMETHODS_H

class LuaSpell
{
public:
    // GetCaster()
    static int GetCaster(lua_State* L, Spell* spell)
    {
        if (!spell)
            return 0;

        Eluna::get()->PushUnit(L, spell->GetCaster());
        return 1;
    }

    // GetCastTime()
    static int GetCastTime(lua_State* L, Spell* spell)
    {
        if (!spell)
            return 0;

        Eluna::get()->PushInteger(L, spell->GetCastTime());
        return 1;
    }

    // GetId()
    static int GetId(lua_State* L, Spell* spell)
    {
        if (!spell)
            return 0;

        Eluna::get()->PushUnsigned(L, spell->GetSpellInfo()->Id);
        return 1;
    }

    // Cancel()
    static int cancel(lua_State* L, Spell* spell)
    {
        if (!spell)
            return 0;

        spell->cancel();
        return 0;
    }
};
#endif