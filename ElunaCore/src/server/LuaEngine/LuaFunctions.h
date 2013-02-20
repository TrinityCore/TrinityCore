#ifndef FUNCTION_TABLES_H
#define FUNCTION_TABLES_H

ElunaRegister<Player> PlayerMethods[] =
{
	{ "Teleport", &LuaPlayer::Teleport },
	{ "AddItem", &LuaPlayer::AddItem },
	{ "RemoveItem", &LuaPlayer::RemoveItem },
	{ "GetX", &LuaPlayer::GetX },
	{ "GetY", &LuaPlayer::GetY },
	{ "GetZ", &LuaPlayer::GetZ },
	{ "GetO", &LuaPlayer::GetO },
	{ "GetLocation", &LuaPlayer::GetLocation },
	{ "GetGUID", &LuaPlayer::GetGUID },
	{ "GetZoneID", &LuaPlayer::GetZoneID },
	{ "GetByteValue", &LuaPlayer::GetByteValue },
	{ "GetName", &LuaPlayer::GetName }, 
	{ "HasQuest", &LuaPlayer::HasQuest },
	{ "IsAlive", &LuaPlayer::IsAlive },
	{ "IsInWorld", &LuaPlayer::IsInWorld },
	{ "IsPvPFlagged", &LuaPlayer::IsPvPFlagged },
	{ NULL, NULL },
};

template<typename T> ElunaRegister<T>* GetMethodTable() { return NULL; }
template <> ElunaRegister<Player>* GetMethodTable<Player>() { return PlayerMethods; }
#endif