#ifndef PLAYERMETHODS_H
#define PLAYERMETHODS_H
#include "Player.h"
#include "GuildMgr.h"
#include "Group.h"

class LuaPlayer
{
	public:

			// Get Methods

		//GetCoinage()
		static int GetCoinage(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}

			lua_pushnumber(L, player->GetMoney());
			return 1;
		}

		// GetDisplayID()
		static int GetDisplayID(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}
	
			lua_pushnumber(L, player->GetDisplayId());
			return 1;
		}

		// GetName()
		static int GetName(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}

			lua_pushstring(L, player->GetName().c_str());
			return 1;
		}

		// GetLevel()
		static int GetLevel(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}

			lua_pushinteger(L, player->getLevel());
			return 1;
		}

		// GetHealth()
		static int GetHealth(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}
		
			lua_pushnumber(L, player->GetHealth());
			return 1;
		}

		// GetGuildId()
		static int GetGuildID(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}

			if(player->GetGuildId() == NULL || player->GetGuildId() == 0)
			{
				lua_pushnil(L);
				return 1;
			}

			lua_pushnumber(L, player->GetGuildId());
			return 1;
		}

		// GetX()
		static int GetX(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}

			lua_pushnumber(L, player->GetPositionX());
			return 1;
		}

		// GetY()
		static int GetY(lua_State* L, Player* player)
		{			
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}

			lua_pushnumber(L, player->GetPositionY());
			return 1;
		}

		// GetZ()
		static int GetZ(lua_State* L, Player* player)
		{			
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}

			lua_pushnumber(L, player->GetPositionZ());
			return 1;
		}

		// GetO()
		static int GetO(lua_State* L, Player* player)
		{			
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}

			lua_pushnumber(L, player->GetOrientation());
			return 1;
		}

		// GetLocation()
		static int GetLocation(lua_State* L, Player* player)
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

		// GetZoneID()
		static int GetZoneID(lua_State* L, Player* player)
		{			
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}

			lua_pushnumber(L, player->GetZoneId());
			return 1;
		}

		// GetAreaID()
		static int GetAreaID(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}
	
			lua_pushnumber(L, player->GetAreaId());
			return 1;
		}

		// GetTeam()
		static int GetTeam(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}
	
			lua_pushnumber(L, player->GetTeamId());
			return 1;
		}

		// GetGUID()
		static int GetGUID(lua_State* L, Player* player)
		{			
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}

			lua_pushnumber(L, player->GetGUID());
			return 1;
		}

		// GetByteValue(index, offset)
		static int GetByteValue(lua_State* L, Player* player)
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

		// GetPower([powertype])
		static int GetPower(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}
			int type = luaL_optint(L, 1, -1);
			if(type == -1)
			{
				// We didn't specify a type, so get the default type for our class
				switch(player->getClass())
				{
				case 1: { type = POWER_RAGE; break; }
				case 4: { type = POWER_ENERGY; break; }
				case 6: { type = POWER_RUNIC_POWER; break; }
				case 2:
				case 3:
				case 5:
				case 7:
				case 8:
				case 9:
				case 11:
					{ type = POWER_MANA; break; }
				default:
					type = POWER_MANA;
				}
			} else if (type >= POWER_ALL) {
				luaL_error(L, "Bad argument #1 to :GetPower(index) - specified out of range index.");
				return 0;
			}

			lua_pushnumber(L, player->GetPower((Powers) type));
			return 1;
		}

		// GetMaxPower([index])
		static int GetMaxPower(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}
			int type = luaL_optint(L, 1, -1);
			if(type == -1)
			{
				// We didn't specify a type, so get the default type for our class
				switch(player->getClass())
				{
				case 1: { type = POWER_RAGE; break; }
				case 4: { type = POWER_ENERGY; break; }
				case 6: { type = POWER_RUNIC_POWER; break; }
				case 2:
				case 3:
				case 5:
				case 7:
				case 8:
				case 9:
				case 11:
					{ type = POWER_MANA; break; }
				default:
					type = POWER_MANA;
				}
			} else if (type >= POWER_ALL) {
				luaL_error(L, "Bad argument #1 to :GetMaxPower(index) - specified out of range index.");
				return 0;
			}

			lua_pushnumber(L, player->GetMaxPower((Powers) type));
			return 1;
		}

		// GetMaxHealth()
		static int GetMaxHealth(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
				return 0;

			lua_pushnumber(L, player->GetMaxHealth());
			return 1;
		}

		// GetHealthPct()
		static int GetHealthPct(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
				return 0;

			lua_pushnumber(L, player->GetHealthPct());
			return 1;
		}

		// GetPowerPct()
		static int GetPowerPct(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
				return 0;

			float percent = (player->GetPower(player->getPowerType())  / player->GetMaxPower(player->getPowerType())) * 100;
			lua_pushnumber(L, percent);
			return 1;
		}

		// GetRace()
		static int GetRace(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
				return 0;

			lua_pushnumber(L, player->getRace());
			return 1;
		}

		// GetClass() - returns numerical index of class
		static int GetClass(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
				return 0;

			lua_pushnumber(L, player->getClass());
			return 1;
		}

		// GetClassAsString()
		static int GetClassAsString(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}

			const char* str = NULL;
			switch(player->getClass())
			{
				case 1: { str = "Warrior"; break; }
				case 2: { str = "Paladin"; break; }
				case 3: { str = "Hunter"; break; }
				case 4:	{ str = "Rogue"; break; }
				case 5:	{ str = "Priest"; break; }
				case 6:	{ str = "DeathKnight"; break; }
				case 7:	{ str = "Shaman"; break; }
				case 8:	{ str = "Mage"; break; }
				case 9:	{ str = "Warlock"; break; }
				case 11:{ str = "Druid"; break; }
				default:{ str = "NULL"; break; }
			}

			lua_pushstring(L, str);
			return 1;
		}

		// GetItemCount(id)
		static int GetItemCount(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}
	
			int id = luaL_checknumber(L, 1);
			bool checkinBank = luaL_optnumber(L, 2, 0); // if 1, check in bank, otherwise don't
			lua_pushnumber(L, player->GetItemCount(id, checkinBank)); 
			return 1;
		}

		// GetUnitType()
		static int GetUnitType(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld()) 
			{
				lua_pushnil(L);
				return 1;
			}

			lua_pushstring(L, "Player");
			return 1;
		}


			// Set Methods

		// SetLevel(level)
		static int SetLevel(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
				return 0;
	
			int amt = luaL_checknumber(L, 1);
			if((player->getLevel() + amt > 80) || amt < 1) // in case user supplies negative number
				player->SetLevel(amt);
			else
				luaL_error(L, "Got out of range value for :SetLevel(level).");


			return 0;
		}

		// SetHealth(amount)
		static int SetHealth(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
				return 0;
	
			int amt = luaL_checknumber(L, 1);
			player->SetHealth(amt);
			return 0;
		}

		// SetMaxHealth(amount)
		static int SetMaxHealth(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
				return 0;
	
			int amt = luaL_checknumber(L, 1);
			player->SetMaxHealth(amt);
			return 0;
		}
	
		// SetPower(powerType, amount)
		static int SetPower(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
				return 0;
	
			int type = luaL_checknumber(L, 1);
			if(type > POWER_RUNIC_POWER) 
			{
				luaL_error(L, "Bad argument #1 to SetPower - Out of bounds.");
				return 0;
			}

			int amt = luaL_checknumber(L, 2);

			switch(type)
			{
			case POWER_MANA:
				player->SetPower(POWER_MANA, amt);
				break;
			case POWER_RAGE:
				player->SetPower(POWER_RAGE, amt);
				break;
			case POWER_ENERGY:
				player->SetPower(POWER_ENERGY, amt);
				break;
			case POWER_RUNIC_POWER:
				player->SetPower(POWER_RUNIC_POWER, amt);
				break;
			// should add a "default" clause that breaks here
			}
			return 0;
		}

		// SetMaxPower(Type, amt)
		static int SetMaxPower(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
				return 0;
	
			int type = luaL_checknumber(L, 1);
			if(type > POWER_RUNIC_POWER)
			{
				luaL_error(L, "Bad argument #1 to SetMaxPower - Out of bounds.");
				return 0;
			}

			int amt = luaL_checknumber(L, 2);
					switch(type)
			{
			case POWER_MANA:
				player->SetMaxPower(POWER_MANA, amt);
				break;
			case POWER_RAGE:
				player->SetMaxPower(POWER_RAGE, amt);
				break;
			case POWER_ENERGY:
				player->SetMaxPower(POWER_ENERGY, amt);
				break;
			case POWER_RUNIC_POWER:
				player->SetMaxPower(POWER_RUNIC_POWER, amt);
				break;
			}
			return 0;
		}

		// SetDisplayID(id)
		static int SetDisplayID(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
				return 0;
	
			int model = luaL_checknumber(L, 1);
			player->SetDisplayId(model);
			return 0;
		}

		// SetCoinage(amount)
		static int SetCoinage(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
				return 0;
	
			int amt = luaL_checknumber(L, 1);
			player->SetMoney(amt);
			return 0;
		}

		// SetKnownTitle(id)
		static int SetKnownTitle(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
				return 0;
	
			int id = luaL_checknumber(L, 1);
			CharTitlesEntry const* t = sCharTitlesStore.LookupEntry(id);
			if(t != NULL)
				player->SetTitle(t, false);
			return 0;
		}

		// UnsetKnownTitle(id)
		static int UnsetKnownTitle(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
				return 0;
	
			int id = luaL_checknumber(L, 1);
			CharTitlesEntry const* t = sCharTitlesStore.LookupEntry(id);
			if(t != NULL)
				player->SetTitle(t, true);
			return 0;
		}


			// Boolean Methods

		// IsInGroup()
		static int IsInGroup(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}

			lua_pushboolean(L, (player->GetGroup() != NULL));
			return 1;
		}

		// IsInGuild()
		static int IsInGuild(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}
			lua_pushboolean(L, (player->GetGuildId() != 0));
			return 1;
		}

		// IsGM()
		static int IsGM(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}
	
			lua_pushboolean(L, player->isGameMaster());
			return 1;
		}

		// IsAlive()
		static int IsAlive(lua_State* L, Player* player)
		{			
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}

			lua_pushboolean(L, player->isAlive());
			return 1;
		}

		// IsInWorld()
		static int IsInWorld(lua_State* L, Player* player)
		{			
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}

			lua_pushboolean(L, player->IsInWorld());
			return 1;
		}

		// IsPvPFlagged()
		static int IsPvPFlagged(lua_State* L, Player* player)
		{			
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}

			lua_pushboolean(L, player->IsPvP());
			return 1;
		}

		// HasQuest(id)
		static int HasQuest(lua_State* L, Player* player)
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

		// IsHorde()
		static int IsHorde(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushboolean(L, false);
				return 1;
			}

			lua_pushboolean(L, (player->GetTeam() == HORDE));
			return 1;
		}

		// IsAlliance()
		static int IsAlliance(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushboolean(L, false);
				return 1;
			}
			lua_pushboolean(L, (player->GetTeam() == ALLIANCE));
			return 1;
		}

		// IsInCombat();
		static int IsInCombat(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}

			lua_pushboolean(L, player->isInCombat());
			return 1;
		}

		// HasTitle(id)
		static int HasTitle(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}

			int id = luaL_checknumber(L, 1);
			lua_pushboolean(L, player->HasTitle(id));
			return 1;
		}

		// HasSpell(id)
		static int HasSpell(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
			{
				lua_pushnil(L);
				return 1;
			}

			int id = luaL_checknumber(L, 1);
			lua_pushboolean(L, player->HasSpell(id));
			return 1;
		}


			// Other Methods
		
		// Teleport(mapid, x, y, z, o)
		static int Teleport(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
				return 0;

			uint32 mapId = luaL_checknumber(L, 1);
			float X = luaL_checknumber(L, 2);
			float Y = luaL_checknumber(L, 3);
			float Z = luaL_checknumber(L, 4);
			float O = luaL_checknumber(L, 5);
			player->TeleportTo(mapId, X, Y, Z, O);
			return 0;
		}

		// AddItem(entry, amount)
		static int AddItem(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
				return 0;

			int itemId = luaL_checknumber(L, 1);
			int itemCount = luaL_checknumber(L, 2);
			player->AddItem(itemId, itemCount);
			return 0;
		}

		// RemoveItem(entry, amount)
		static int RemoveItem(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
				return 0;

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

		// SendBroadcastMessage(msg)
		static int SendBroadcastMessage(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
				return 0;

			const char* message = luaL_checkstring(L, 1);
			if(std::string(message).length() > 0)
			{
				sWorld->SendServerMessage(SERVER_MSG_STRING, message, player);
			} 
			return 0;
		}

		// GiveCoinage(amount)
		static int GiveCoinage(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
				return 0;
	
			int amt = luaL_checknumber(L, 1);
			if(player->GetMoney() + amt >= 2147483646) // prevent going over gold cap (which resets to 0)
			{
				player->SetMoney(2147483646);
				return 0;
			}

			player->SetMoney( player->GetMoney() + amt );
			return 0;
		}

		// RemoveCoinage(amount)
		static int RemoveCoinage(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
				return 0;
	
			int amt = luaL_checknumber(L, 1);
			if((player->GetMoney() == 0) || (player->GetMoney() - amt < 0)) // removing coinage from a player with 0 coinage makes us hit the gold cap
			{
				player->SetMoney(0);
				return 0;
			}

			player->SetMoney(player->GetMoney() - amt);
			return 0;
		}

		// LearnSpell(id)
		static int LearnSpell(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
				return 0;
	
			int id = luaL_checknumber(L, 1);
			player->learnSpell(id,  false);
			return 0;
		}

		// DeMorph()
		static int DeMorph(lua_State* L, Player* player)
		{
			if (player == NULL || !player->IsInWorld())
				return 0;
	
			player->RestoreDisplayId();
			return 0;
		}
};
#endif