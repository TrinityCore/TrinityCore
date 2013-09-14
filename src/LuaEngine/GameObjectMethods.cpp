#include "LuaEngine.h"
#include "GameObjectMethods.h"

int LuaGameObject::GetMap(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    sEluna->PushMap(L, go->GetMap());
    return 1;
}

int LuaGameObject::GetRelativePoint(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    float dist = luaL_checknumber(L, 1);
    int deg = luaL_checkinteger(L, 2);

    float o = Position::NormalizeOrientation(go->GetOrientation() + (deg*M_PI/180));
    sEluna->PushFloat(L, go->GetPositionX()+(dist*cosf(o)));
    sEluna->PushFloat(L, go->GetPositionY()+(dist*sinf(o)));
    sEluna->PushFloat(L, o);
    return 3;
}

int LuaGameObject::GetUnitType(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    sEluna->PushString(L, "GameObject");
    return 1;
}

int LuaGameObject::GetGUID(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    sEluna->PushULong(L, go->GetGUID());
    return 1;
}

int LuaGameObject::CastSpell(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    uint32 spell = luaL_checkunsigned(L, 1);
    Unit* target = sEluna->CHECK_UNIT(L, 2);
    if (target)
        go->CastSpell(target, spell);
    return 0;
}

int LuaGameObject::GetX(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    sEluna->PushFloat(L, go->GetPositionX());
    return 1;
}

int LuaGameObject::GetY(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    sEluna->PushFloat(L, go->GetPositionY());
    return 1;
}

int LuaGameObject::GetZ(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    sEluna->PushFloat(L, go->GetPositionZ());
    return 1;
}

int LuaGameObject::GetO(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    sEluna->PushFloat(L, go->GetOrientation());
    return 1;
}

int LuaGameObject::GetLocation(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    sEluna->PushFloat(L, go->GetPositionX());
    sEluna->PushFloat(L, go->GetPositionY());
    sEluna->PushFloat(L, go->GetPositionZ());
    sEluna->PushFloat(L, go->GetOrientation());
    return 4;
}

int LuaGameObject::GetMapId(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    sEluna->PushFloat(L, go->GetMapId());
    return 1;
}

int LuaGameObject::GetZoneId(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    sEluna->PushFloat(L, go->GetZoneId());
    return 1;
}

int LuaGameObject::GetAreaId(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    sEluna->PushFloat(L, go->GetAreaId());
    return 1;
}

int LuaGameObject::GetName(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    sEluna->PushString(L, go->GetName().c_str());
    return 1;
}

int LuaGameObject::GetEntry(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    sEluna->PushUnsigned(L, go->GetEntry());
    return 1;
}

int LuaGameObject::SummonCreature(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    uint32 entry = luaL_checkunsigned(L, 1);
    float x = luaL_checknumber(L, 2);
    float y = luaL_checknumber(L, 3);
    float z = luaL_checknumber(L, 4);
    float o = luaL_checknumber(L, 5);
    uint32 despawn = luaL_optunsigned(L, 6, 0);

    TempSummonType summontype;
    if (despawn)
        summontype = TEMPSUMMON_TIMED_OR_DEAD_DESPAWN;
    else
        summontype = TEMPSUMMON_MANUAL_DESPAWN;
    sEluna->PushUnit(L, go->SummonCreature(entry, x, y, z, o, summontype, despawn));
    return 1;
}

int LuaGameObject::SummonGameObject(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    uint32 entry = luaL_checkunsigned(L, 1);
    float x = luaL_checknumber(L, 2);
    float y = luaL_checknumber(L, 3);
    float z = luaL_checknumber(L, 4);
    float o = luaL_checknumber(L, 5);
    uint32 respawnDelay = luaL_optunsigned(L, 6, 30);
    sEluna->PushGO(L, go->SummonGameObject(entry, x, y, z, o, 0, 0, 0, 0, respawnDelay));
    return 1;
}

int LuaGameObject::Despawn(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    go->RemoveFromWorld();
    return 0;
}

int LuaGameObject::GetDisplayId(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    sEluna->PushUnsigned(L, go->GetDisplayId());
    return 1;
}

int LuaGameObject::GetScale(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    sEluna->PushFloat(L, go->GetObjectSize());
    return 1;
}

int LuaGameObject::IsInWorld(lua_State* L, GameObject* go)
{
    if (!go)
        sEluna->PushBoolean(L, false);
    else
        sEluna->PushBoolean(L, go->IsInWorld());
    return 1;
}

int LuaGameObject::HasQuest(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        sEluna->PushBoolean(L, false);
    else
    {
        uint32 questId = luaL_checkunsigned(L, 1);
        sEluna->PushBoolean(L, go->hasQuest(questId));
    }
    return 1;
}

int LuaGameObject::IsInvisibleDueToDespawn(lua_State* L, GameObject * go)
{
    if (!go || !go->IsInWorld())
        sEluna->PushBoolean(L, false);
    else
    {
        sEluna->PushBoolean(L, go->IsInvisibleDueToDespawn());
    }
    return 1;
}

int LuaGameObject::IsTransport(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        sEluna->PushBoolean(L, false);
    else
        sEluna->PushBoolean(L, go->IsTransport());
    return 1;
}

int LuaGameObject::IsDestructible(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        sEluna->PushBoolean(L, false);
    else
        sEluna->PushBoolean(L, go->IsDestructibleBuilding());
    return 1;
}

int LuaGameObject::IsActive(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        sEluna->PushBoolean(L, false);
    else
        sEluna->PushBoolean(L, go->isActiveObject());
    return 1;
}

int LuaGameObject::Move(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    float x = luaL_checknumber(L, 1);
    float y = luaL_checknumber(L, 2);
    float z = luaL_checknumber(L, 3);
    float o = luaL_checknumber(L, 4);
    go->Relocate(x, y, z, o);
    return 0;
}

int LuaGameObject::SetScale(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    float scale = luaL_checknumber(L, 1);
    go->SetObjectScale(scale);
    return 0;
}

int LuaGameObject::RegisterEvent(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    luaL_checktype(L, 1, LUA_TFUNCTION);
    uint32 delay = luaL_checkunsigned(L, 2);
    uint32 repeats = luaL_checkunsigned(L, 3);

    lua_settop(L, 1);
    Eluna::LuaEventMap* eventMap = Eluna::LuaEventMap::GetEvents(go);
    if (!eventMap)
    {
        luaL_error(L, "You need to use RegisterGameObjectEvent for the gameobject first");
        return 0;
    }

    int functionRef = lua_ref(L, true);
    eventMap->ScriptEventCreate(functionRef, delay, repeats);
    sEluna->PushInteger(L, functionRef);
    return 1;
}

int LuaGameObject::RemoveEventById(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    int eventID = luaL_checkinteger(L, 1);
    Eluna::LuaEventMap* eventMap = Eluna::LuaEventMap::GetEvents(go);
    if (eventMap)
        eventMap->ScriptEventCancel(eventID);
    return 0;
}

int LuaGameObject::RemoveEvents(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    Eluna::LuaEventMap* eventMap = Eluna::LuaEventMap::GetEvents(go);
    if (eventMap)
        eventMap->ScriptEventsReset();
    return 0;
}

int LuaGameObject::GetInt32Value(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    uint16 index = luaL_checkunsigned(L, 1);
    sEluna->PushInteger(L, go->GetInt32Value(index));
    return 1;
}

int LuaGameObject::GetUInt32Value(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    uint16 index = luaL_checkunsigned(L, 1);
    sEluna->PushUnsigned(L, go->GetUInt32Value(index));
    return 1;
}

int LuaGameObject::GetFloatValue(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    uint16 index = luaL_checkunsigned(L, 1);
    sEluna->PushFloat(L, go->GetFloatValue(index));
    return 1;
}

int LuaGameObject::GetByteValue(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    uint16 index = luaL_checkunsigned(L, 1);
    uint8 offset = luaL_checkunsigned(L, 2);
    sEluna->PushUnsigned(L, go->GetByteValue(index, offset));
    return 1;
}

int LuaGameObject::GetUInt16Value(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    uint16 index = luaL_checkunsigned(L, 1);
    uint8 offset = luaL_checkunsigned(L, 2);
    sEluna->PushUnsigned(L, go->GetUInt16Value(index, offset));
    return 1;
}

int LuaGameObject::SetInt32Value(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    uint16 index = luaL_checkunsigned(L, 1);
    int32 value = luaL_checkinteger(L, 2);
    go->SetInt32Value(index, value);
    return 0;
}

int LuaGameObject::SetUInt32Value(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    uint16 index = luaL_checkunsigned(L, 1);
    uint32 value = luaL_checkunsigned(L, 2);
    go->SetUInt32Value(index, value);
    return 0;
}

int LuaGameObject::UpdateUInt32Value(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    uint16 index = luaL_checkunsigned(L, 1);
    uint32 value = luaL_checkunsigned(L, 2);
    go->UpdateUInt32Value(index, value);
    return 0;
}

int LuaGameObject::SetFloatValue(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    uint16 index = luaL_checkunsigned(L, 1);
    float value = luaL_checknumber(L, 2);
    go->SetFloatValue(index, value);
    return 0;
}

int LuaGameObject::SetByteValue(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    uint16 index = luaL_checkunsigned(L, 1);
    uint8 offset = luaL_checkunsigned(L, 2);
    uint8 value = luaL_checkunsigned(L, 3);
    go->SetByteValue(index, offset, value);
    return 0;
}

int LuaGameObject::SetUInt16Value(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    uint16 index = luaL_checkunsigned(L, 1);
    uint8 offset = luaL_checkunsigned(L, 2);
    uint16 value = luaL_checkunsigned(L, 3);
    go->SetUInt16Value(index, offset, value);
    return 0;
}

int LuaGameObject::SetInt16Value(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    uint16 index = luaL_checkunsigned(L, 1);
    uint8 offset = luaL_checkunsigned(L, 2);
    int16 value = luaL_checkinteger(L, 3);
    go->SetInt16Value(index, offset, value);
    return 0;
}

int LuaGameObject::GetGUIDLow(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    sEluna->PushUnsigned(L, go->GetGUIDLow());
    return 1;
}

int LuaGameObject::GetNearestPlayer(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    float distance = luaL_optnumber(L, 1, SIZE_OF_GRIDS);

    Player* target = NULL;
    Eluna::NearestTypeWithEntryInRangeCheck checker(go, distance, TYPEID_PLAYER);
    Trinity::PlayerLastSearcher<Eluna::NearestTypeWithEntryInRangeCheck> searcher(go, target, checker);
    go->VisitNearbyObject(distance, searcher);

    sEluna->PushUnit(L, target);
    return 1;
}

int LuaGameObject::GetNearestGameObject(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    uint32 entry = luaL_optunsigned(L, 1, 0);
    float range = luaL_optnumber(L, 2, SIZE_OF_GRIDS);

    GameObject* target = NULL;
    Eluna::NearestTypeWithEntryInRangeCheck checker(go, range, TYPEID_GAMEOBJECT, entry);
    Trinity::GameObjectLastSearcher<Eluna::NearestTypeWithEntryInRangeCheck> searcher(go, target, checker);
    go->VisitNearbyGridObject(range, searcher);

    sEluna->PushGO(L, target);
    return 1;
}

int LuaGameObject::GetNearestCreature(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    uint32 entry = luaL_optunsigned(L, 1, 0);
    float range = luaL_optnumber(L, 2, SIZE_OF_GRIDS);

    Creature* target = NULL;
    Eluna::NearestTypeWithEntryInRangeCheck checker(go, range, TYPEID_UNIT, entry);
    Trinity::CreatureLastSearcher<Eluna::NearestTypeWithEntryInRangeCheck> searcher(go, target, checker);
    go->VisitNearbyGridObject(range, searcher);

    sEluna->PushUnit(L, target);
    return 1;
}

int LuaGameObject::UseDoorOrButton(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    uint32 delay = luaL_optunsigned(L, 1, 0);

    go->UseDoorOrButton(delay);
    return 0;
}

int LuaGameObject::SetGoState(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    uint32 state = luaL_optunsigned(L, 1, 0);

    if(state == 0)
        go->SetGoState(GO_STATE_ACTIVE);
    else if(state == 1)
        go->SetGoState(GO_STATE_READY);
    else if(state == 2)
        go->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);

    return 0;
}

int LuaGameObject::GetGoState(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    sEluna->PushUnsigned(L, go->GetGoState());
    return 1;
}

int LuaGameObject::SetLootState(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    uint32 state = luaL_optunsigned(L, 1, 0);

    if(state == 0)
        go->SetLootState(GO_NOT_READY);
    else if(state == 1)
        go->SetLootState(GO_READY);
    else if(state == 2)
        go->SetLootState(GO_ACTIVATED);
    else if(state == 3)
        go->SetLootState(GO_JUST_DEACTIVATED);

    return 0;
}

int LuaGameObject::GetLootState(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    sEluna->PushUnsigned(L, go->getLootState());
    return 1;
}

int LuaGameObject::SetFlag(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    uint32 flag = luaL_optunsigned(L, 1, 0);

    go->SetFlag(GAMEOBJECT_FLAGS, flag);
    return 0;
}

int LuaGameObject::RemoveFlag(lua_State* L, GameObject* go)
{
    if (!go || !go->IsInWorld())
        return 0;

    uint32 flag = luaL_optunsigned(L, 1, 0);

    go->RemoveFlag(GAMEOBJECT_FLAGS, flag);
    return 0;
}