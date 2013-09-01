#ifndef GAMEOBJECTMETHODS_H
#define GAMEOBJECTMETHODS_H

namespace LuaGameObject
{
    int GetMap(lua_State*, GameObject*);
    int GetRelativePoint(lua_State*, GameObject*);
    int GetUnitType(lua_State*, GameObject*);
    int GetGUID(lua_State*, GameObject*);
    int CastSpell(lua_State*, GameObject*);
    int GetX(lua_State*, GameObject*);
    int GetY(lua_State*, GameObject*);
    int GetZ(lua_State*, GameObject*);
    int GetO(lua_State*, GameObject*);
    int GetLocation(lua_State*, GameObject*);
    int GetMapId(lua_State*, GameObject*);
    int GetZoneId(lua_State*, GameObject*);
    int GetAreaId(lua_State*, GameObject*);
    int GetName(lua_State*, GameObject*);
    int GetEntry(lua_State*, GameObject*);
    int SummonCreature(lua_State*, GameObject*);
    int SummonGameObject(lua_State*, GameObject*);
    int Despawn(lua_State*, GameObject*);
    int GetDisplayId(lua_State*, GameObject*);
    int GetScale(lua_State*, GameObject*);
    int IsInWorld(lua_State*, GameObject*);
    int HasQuest(lua_State*, GameObject*);
    int IsInvisibleDueToDespawn(lua_State*, GameObject*);
    int IsTransport(lua_State*, GameObject*);
    int IsDestructible(lua_State*, GameObject*);
    int IsActive(lua_State*, GameObject*);
    int Move(lua_State*, GameObject*);
    int SetScale(lua_State*, GameObject*);
    int RegisterEvent(lua_State*, GameObject*);
    int RemoveEventById(lua_State*, GameObject*);
    int RemoveEvents(lua_State*, GameObject*);
    int GetInt32Value(lua_State*, GameObject*);
    int GetUInt32Value(lua_State*, GameObject*);
    int GetFloatValue(lua_State*, GameObject*);
    int GetByteValue(lua_State*, GameObject*);
    int GetUInt16Value(lua_State*, GameObject*);
    int SetInt32Value(lua_State*, GameObject*);
    int SetUInt32Value(lua_State*, GameObject*);
    int UpdateUInt32Value(lua_State*, GameObject*);
    int SetFloatValue(lua_State*, GameObject*);
    int SetByteValue(lua_State*, GameObject*);
    int SetUInt16Value(lua_State*, GameObject*);
    int SetInt16Value(lua_State*, GameObject*);
    int GetGUIDLow(lua_State*, GameObject*);
    int GetNearestPlayer(lua_State*, GameObject*);
    int GetNearestGameObject(lua_State*, GameObject*);
    int GetNearestCreature(lua_State*, GameObject*);
    int UseDoorOrButton(lua_State*, GameObject*);
    int SetGoState(lua_State*, GameObject*);
    int GetGoState(lua_State*, GameObject*);
    int GetLootState(lua_State*, GameObject*);
    int SetLootState(lua_State*, GameObject*);
    int SetFlag(lua_State*, GameObject*);
    int RemoveFlag(lua_State*, GameObject*);
};
#endif
