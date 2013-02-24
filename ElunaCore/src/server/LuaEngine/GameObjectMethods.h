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

    // CastSpellOnTarget(target, spellid)
    static int CastSpellOnTarget(lua_State* L, GameObject* go)
    {
        if(!go || !go->IsInWorld())
            return 0;

        uint32 spell = luaL_checkunsigned(L, 1);
        Unit* target = Eluna::get()->CHECK_UNIT(L, 2);

        if(target)
            go->CastSpell(target, spell);
        return 0;
    }

    // GetX()
    static int GetX(lua_State* L, GameObject* go)
    {
        if(!go || !go->IsInWorld())
            return 0;

        Eluna::get()->PushFloat(L, go->GetPositionX());
        return 1;
    }

    // GetY()
    static int GetY(lua_State* L, GameObject* go)
    {
        if(!go || !go->IsInWorld())
            return 0;

        Eluna::get()->PushFloat(L, go->GetPositionY());
        return 1;
    }

    // GetZ()
    static int GetZ(lua_State* L, GameObject* go)
    {
        if(!go || !go->IsInWorld())
            return 0;

        Eluna::get()->PushFloat(L, go->GetPositionZ());
        return 1;
    }

    // GetO()
    static int GetO(lua_State* L, GameObject* go)
    {
        if(!go || !go->IsInWorld())
            return 0;

        Eluna::get()->PushFloat(L, go->GetOrientation());
        return 1;
    }

    // GetLocation()
    static int GetLocation(lua_State* L, GameObject* go)
    {
        if(!go || !go->IsInWorld())
            return 0;

        Eluna::get()->PushFloat(L, go->GetPositionX());
        Eluna::get()->PushFloat(L, go->GetPositionY());
        Eluna::get()->PushFloat(L, go->GetPositionZ());
        Eluna::get()->PushFloat(L, go->GetOrientation());

        return 4;
    }

    // GetMapId()
    static int GetMapId(lua_State* L, GameObject* go)
    {
        if(!go || !go->IsInWorld())
            return 0;

        Eluna::get()->PushFloat(L, go->GetMapId());
        return 1;
    }

    // GetZoneId()
    static int GetZoneId(lua_State* L, GameObject* go)
    {
        if(!go || !go->IsInWorld())
            return 0;

        Eluna::get()->PushFloat(L, go->GetZoneId());
        return 1;
    }

    // GetAreaId()
    static int GetAreaId(lua_State* L, GameObject* go)
    {
        if(!go || !go->IsInWorld())
            return 0;

        Eluna::get()->PushFloat(L, go->GetAreaId());
        return 1;
    }

    // GetName()
    static int GetName(lua_State* L, GameObject* go)
    {
        if(!go || !go->IsInWorld())
            return 0;

        Eluna::get()->PushString(L, go->GetName().c_str());
        return 1;
    }

    // GetEntry()
    static int GetEntry(lua_State* L, GameObject* go)
    {
        if(!go || !go->IsInWorld())
            return 0;

        Eluna::get()->PushUnsigned(L, go->GetEntry());
        return 1;
    }

    // SummonCreature() uint32 spell = luaL_checkunsigned(L, 1);
    /*static int SummonCreature(lua_State* L, GameObject* go)
    {
        if(!go || !go->IsInWorld())
            return 0;

        uint32 entry = luaL_checkunsigned(L, 1);
        float x = luaL_checknumber(L, 2);
        float y = luaL_checknumber(L, 3);
        float z = luaL_checknumber(L, 4);

        Eluna::get()->PushUnsigned(L, go->SummonCreature(entry, x, y, z, 0.0f, TEMPSUMMON_ANUAL_DESPAWN, despawntime)); // NO clue what the last 3 args should be. Rochet/Tommy?
        return 0;
    }*/

    // GetDisplayId()
    static int GetDisplayId(lua_State* L, GameObject* go)
    {
        if(!go || !go->IsInWorld())
            return 0;

        Eluna::get()->PushUnsigned(L, go->GetDisplayId());
        return 1;
    }

    // GetScale()
    static int GetScale(lua_State* L, GameObject* go)
    {
        if(!go || !go->IsInWorld())
            return 0;

        Eluna::get()->PushFloat(L, go->GetObjectSize());
        return 1;
    }

    // IsInWorld()
    static int IsInWorld(lua_State* L, GameObject* go)
    {
        if(!go)
            Eluna::get()->PushBoolean(L, false);
        else
            Eluna::get()->PushBoolean(L, go->IsInWorld());
        return 1;
    }

    // HasQuest(questId)
    static int HasQuest(lua_State* L, GameObject* go)
    {
        if(!go || !go->IsInWorld())
            Eluna::get()->PushBoolean(L, false);
        else
        {
            uint32 questId = luaL_checkunsigned(L, 1);
            Eluna::get()->PushBoolean(L, go->hasQuest(questId));
        }
        return 1;
    }

    // IsTransport()
    static int IsTransport(lua_State* L, GameObject* go)
    {
        if(!go || !go->IsInWorld())
            Eluna::get()->PushBoolean(L, false);
        else
            Eluna::get()->PushBoolean(L, go->IsTransport());
        return 1;
    }

    // IsDestructible()
    static int IsDestructible(lua_State* L, GameObject* go)
    {
        if(!go || !go->IsInWorld())
            Eluna::get()->PushBoolean(L, false);
        else
            Eluna::get()->PushBoolean(L, go->IsDestructibleBuilding());
        return 1;
    }

    // IsActive()
    static int IsActive(lua_State* L, GameObject* go)
    {
        if(!go || !go->IsInWorld())
            Eluna::get()->PushBoolean(L, false);
        else
            Eluna::get()->PushBoolean(L, go->isActiveObject());
        return 1;
    }

    // Move(x, y, z, o)
    static int Move(lua_State* L, GameObject* go)
    {
        if(!go || !go->IsInWorld())
            return 0;

        float X = luaL_checknumber(L, 1);
        float Y = luaL_checknumber(L, 2);
        float Z = luaL_checknumber(L, 3);
        float O = luaL_checknumber(L, 4);

        go->Relocate(X, Y, Z, O);
        return 0;
    }

    // SetScale(scale)
    static int SetScale(lua_State* L, GameObject* go)
    {
        if(!go || !go->IsInWorld())
            return 0;

        float scale = luaL_checknumber(L, 1);

        go->SetObjectScale(scale);
        return 0;
    }
};

#endif