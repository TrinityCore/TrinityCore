#ifndef PLAYERMETHODS_H
#define PLAYERMETHODS_H
#include "Player.h"

class LuaPlayer
{
	public:
		static int Teleport(lua_State * L, Player * player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 0;
			}

			uint32 mapId = luaL_checknumber(L, 1);
			float X = luaL_checknumber(L, 2);
			float Y = luaL_checknumber(L, 3);
			float Z = luaL_checknumber(L, 4);
			float O = luaL_checknumber(L, 5);
			player->TeleportTo(mapId, X, Y, Z, O);
			return 0;
		}

		static int AddItem(lua_State * L, Player * player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 0;
			}

			int itemId = luaL_checknumber(L, 1);
			int itemCount = luaL_checknumber(L, 2);
			player->AddItem(itemId, itemCount);
			return 0;
		}

		static int RemoveItem(lua_State * L, Player * player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 0;
			}

			int itemId = luaL_checknumber(L, 1);
			int itemCount = luaL_checknumber(L, 2);

			int cnt = player->GetItemCount(itemId);
			
			if (cnt == 0)
				return 0;

			if (itemCount > cnt)
				itemCount = cnt;

			player->DestroyItemCount(itemId, itemCount, true);
			return 0;
		}

		static int GetName(lua_State * L, Player * player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}

			lua_pushstring(L, player->GetName().c_str());
			return 1;
		}

		static int GetX(lua_State * L, Player * player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}

			lua_pushnumber(L, player->GetPositionX());
			return 1;
		}

		static int GetY(lua_State * L, Player * player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}

			lua_pushnumber(L, player->GetPositionY());
			return 1;
		}

		static int GetZ(lua_State * L, Player * player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}

			lua_pushnumber(L, player->GetPositionZ());
			return 1;
		}

		static int GetO(lua_State * L, Player * player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}

			lua_pushnumber(L, player->GetOrientation());
			return 1;
		}

		static int GetLocation(lua_State * L, Player * player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}

			lua_pushnumber(L, player->GetPositionX());
			lua_pushnumber(L, player->GetPositionY());
			lua_pushnumber(L, player->GetPositionZ());
			lua_pushnumber(L, player->GetOrientation());
			return 4;
		}

		static int GetZoneID(lua_State * L, Player * player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}

			lua_pushnumber(L, player->GetZoneId());
			return 1;
		}

		static int GetGUID(lua_State * L, Player * player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}

			lua_pushnumber(L, player->GetGUID());
			return 1;
		}

		static int GetByteValue(lua_State * L, Player * player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}

			uint32 index = luaL_checkint(L, 1);
			uint32 offset = luaL_checkint(L, 2);
			lua_pushinteger(L, player->GetByteValue(index, offset));
			return 1;
		}

		static int HasQuest(lua_State * L, Player * player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}

			int questId = luaL_checknumber(L, 1);
			lua_pushnumber(L, player->hasQuest(questId));
			return 1;
		}

		static int IsAlive(lua_State * L, Player * player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}

			lua_pushboolean(L, player->isAlive());
			return 1;
		}

		static int IsInWorld(lua_State * L, Player * player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}

			lua_pushboolean(L, player->IsInWorld());
			return 1;
		}

		static int IsPvPFlagged(lua_State * L, Player * player)
		{
			return 1;
		}
};
#endif