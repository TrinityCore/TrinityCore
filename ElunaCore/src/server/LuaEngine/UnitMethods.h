#include "ScriptPCH.h"

#ifndef UNITMETHODS_H
#define UNITMETHODS_H

#define TO_PLAYER()  Player* player; if(!unit || !unit->IsInWorld() || !(player = unit->ToPlayer()))     { return 0; } else (void)0;
#define TO_CREATURE()  Creature* creature; if(!unit || !unit->IsInWorld() || !(creature = unit->ToCreature())) { return 0; } else (void)0;
#define TO_UNIT()  if(!unit || !unit->IsInWorld() || !unit->ToUnit())  { return 0; } else (void)0;

#define TO_PLAYER_BOOL()  Player* player;  if(!unit || !unit->IsInWorld() || !(player = unit->ToPlayer()))     { Eluna::get()->PushBoolean(L, false); return 1; } else (void)0;
#define TO_CREATURE_BOOL()  Creature* creature; if(!unit || !unit->IsInWorld() || !(creature = unit->ToCreature())) { Eluna::get()->PushBoolean(L, false); return 1; } else (void)0;
#define TO_UNIT_BOOL() if(!unit || !unit->IsInWorld() || !unit->ToUnit()) { Eluna::get()->PushBoolean(L, false); return 1; } else (void)0;

class LuaUnit
{
public:
    // Get Methods
    //GetSelection()
    static int GetSelection(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        Eluna::get()->PushUnit(L, player->GetSelectedUnit());
        return 1;
    }

    //GetCoinage()
    static int GetCoinage(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        Eluna::get()->PushUnsigned(L, player->GetMoney());
        return 1;
    }

    // GetDisplayID()
    static int GetDisplayID(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        Eluna::get()->PushUnsigned(L, unit->GetDisplayId());
        return 1;
    }

    // GetName()
    static int GetName(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        Eluna::get()->PushString(L, unit->GetName().c_str());
        return 1;
    }

    // GetLevel()
    static int GetLevel(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        Eluna::get()->PushUnsigned(L, unit->getLevel());
        return 1;
    }

    // GetHealth()
    static int GetHealth(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        Eluna::get()->PushUnsigned(L, unit->GetHealth());
        return 1;
    }

    // GetGuildId()
    static int GetGuildID(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        if(!player->GetGuildId())
            return 0;
        
        Eluna::get()->PushUnsigned(L, player->GetGuildId());
        return 1;
    }

    // GetX()
    static int GetX(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        Eluna::get()->PushFloat(L, unit->GetPositionX());
        return 1;
    }

    // GetY()
    static int GetY(lua_State* L, Unit* unit)
    {			
        TO_UNIT();

        Eluna::get()->PushFloat(L, unit->GetPositionY());
        return 1;
    }

    // GetZ()
    static int GetZ(lua_State* L, Unit* unit)
    {			
        TO_UNIT();

        Eluna::get()->PushFloat(L, unit->GetPositionZ());
        return 1;
    }

    // GetO()
    static int GetO(lua_State* L, Unit* unit)
    {			
        TO_UNIT();

        Eluna::get()->PushFloat(L, unit->GetOrientation());
        return 1;
    }

    // GetLocation()
    static int GetLocation(lua_State* L, Unit* unit)
    {			
        TO_UNIT();

        Eluna::get()->PushFloat(L, unit->GetPositionX());
        Eluna::get()->PushFloat(L, unit->GetPositionY());
        Eluna::get()->PushFloat(L, unit->GetPositionZ());
        Eluna::get()->PushFloat(L, unit->GetOrientation());
        return 4;
    }

    // GetZoneID()
    static int GetZoneID(lua_State* L, Unit* unit)
    {			
        TO_UNIT();

        Eluna::get()->PushUnsigned(L, unit->GetZoneId());
        return 1;
    }

    // GetAreaID()
    static int GetAreaID(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        Eluna::get()->PushUnsigned(L, unit->GetAreaId());
        return 1;
    }

    // GetTeam()
    static int GetTeam(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        Eluna::get()->PushInteger(L, player->GetTeamId());
        return 1;
    }

    // GetGUID()
    static int GetGUID(lua_State* L, Unit* unit)
    {			
        TO_UNIT();

        Eluna::get()->PushGUID(L, unit->GetGUID());
        return 1;
    }

    // GetByteValue(index, offset)
    static int GetByteValue(lua_State* L, Unit* unit)
    {			
        TO_UNIT();

        uint32 index = luaL_checkint(L, 1);
        uint32 offset = luaL_checkint(L, 2);
        Eluna::get()->PushUnsigned(L, unit->GetByteValue(index, offset));
        return 1;
    }

    // GetPower([powertype])
    static int GetPower(lua_State* L, Unit* unit)
    {
        TO_UNIT();
        int type = luaL_optint(L, 1, -1);
        if(type == -1)
        {
            // We didn't specify a type, so get the default type for our class
            switch(unit->getClass())
            {
				case 1: 
					type = POWER_RAGE; 
					break;
				case 4: 
					type = POWER_ENERGY; 
					break;
				case 6: 
					type = POWER_RUNIC_POWER; 
					break;
				case 2:
				case 3:
				case 5:
				case 7:
				case 8:
				case 9:
				case 11:
					type = POWER_MANA; 
					break;
				default:
					type = POWER_MANA;
            }
        } 
		else if (type >= POWER_ALL) 
		{
            luaL_error(L, "Bad argument #1 to :GetPower(index) - specified out of range index.");
            return 0;
        }

        Eluna::get()->PushUnsigned(L, unit->GetPower((Powers) type));
        return 1;
    }

    // GetMaxPower([index])
    static int GetMaxPower(lua_State* L, Unit* unit)
    {
        TO_UNIT();
        int type = luaL_optint(L, 1, -1);
        if(type == -1)
        {
            // We didn't specify a type, so get the default type for our class
            switch(unit->getClass())
            {
				case 1: 
					type = POWER_RAGE; 
					break;
				case 4: 
					type = POWER_ENERGY; 
					break;
				case 6: 
					type = POWER_RUNIC_POWER; 
					break;
				case 2:
				case 3:
				case 5:
				case 7:
				case 8:
				case 9:
				case 11:
					type = POWER_MANA; 
					break;
				default:
					type = POWER_MANA;
            }
        } 
		else if (type >= POWER_ALL) 
		{
            luaL_error(L, "Bad argument #1 to :GetMaxPower(index) - specified out of range index.");
            return 0;
        }

        Eluna::get()->PushUnsigned(L, unit->GetMaxPower((Powers) type));
        return 1;
    }

    // GetMaxHealth()
    static int GetMaxHealth(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        Eluna::get()->PushUnsigned(L, unit->GetMaxHealth());
        return 1;
    }

    // GetHealthPct()
    static int GetHealthPct(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        Eluna::get()->PushFloat(L, unit->GetHealthPct());
        return 1;
    }

    // GetPowerPct()
    static int GetPowerPct(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        float percent = (unit->GetPower(unit->getPowerType())  / unit->GetMaxPower(unit->getPowerType())) * 100;
        Eluna::get()->PushFloat(L, percent);
        return 1;
    }

    // GetRace()
    static int GetRace(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        Eluna::get()->PushUnsigned(L, unit->getRace());
        return 1;
    }

    // GetClass() - returns numerical index of class
    static int GetClass(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        Eluna::get()->PushUnsigned(L, unit->getClass());
        return 1;
    }

    // GetClassAsString()
    static int GetClassAsString(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        const char* str = NULL;
        switch(unit->getClass())
        {
			case 1: 
				str = "Warrior"; 
				break;
			case 2: 
				str = "Paladin"; 
				break;
			case 3: 
				str = "Hunter"; 
				break;
			case 4:	
				str = "Rogue"; 
				break;
			case 5:	
				str = "Priest"; 
				break;
			case 6:	
				str = "DeathKnight"; 
				break;
			case 7:	
				str = "Shaman"; 
				break;
			case 8:	
				str = "Mage"; 
				break;
			case 9:	
				str = "Warlock"; 
				break;
			case 11:
				str = "Druid"; 
				break;
			default:
				str = "NULL"; 
				break;
        }

        Eluna::get()->PushString(L, str);
        return 1;
    }

    // GetItemCount(id)
    static int GetItemCount(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        int id = luaL_checknumber(L, 1);
        bool checkinBank = luaL_optnumber(L, 2, 0); // if 1, check in bank, otherwise don't
        Eluna::get()->PushUnsigned(L, player->GetItemCount(id, checkinBank)); 
        return 1;
    }

    // GetUnitType()
    static int GetUnitType(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        if(unit->ToPlayer())
            Eluna::get()->PushString(L, "Player");
        else if(unit->ToCreature())
            Eluna::get()->PushString(L, "Creature");
        else
            Eluna::get()->PushString(L, "Unknown");
        return 1;
    }

    // GetGuild()
    static int GetGuild(lua_State* L, Unit* unit)
    {
        TO_PLAYER();
        
        Eluna::get()->PushGuild(L, player->GetGuild());
		return 1;
    }

    // GetGroup()
    static int GetGroup(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        Eluna::get()->PushGroup(L, player->GetGroup());
        return 1;
    }

    // Set Methods

    // SetLevel(level)
    static int SetLevel(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint32 newLevel = luaL_checkunsigned(L, 1);
        unit->SetLevel(newLevel);

        return 0;
    }

    // SetHealth(amount)
    static int SetHealth(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint32 amt = luaL_checkunsigned(L, 1);
        unit->SetHealth(amt);
        return 0;
    }

    // SetMaxHealth(amount)
    static int SetMaxHealth(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint32 amt = luaL_checkunsigned(L, 1);
        unit->SetMaxHealth(amt);
        return 0;
    }

    // SetPower(powerType, amount)
    static int SetPower(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        int type = luaL_checkinteger(L, 1);
        uint32 amt = luaL_checkunsigned(L, 2);

        switch(type)
        {
        case POWER_MANA:
            unit->SetPower(POWER_MANA, amt);
            break;
        case POWER_RAGE:
            unit->SetPower(POWER_RAGE, amt);
            break;
        case POWER_ENERGY:
            unit->SetPower(POWER_ENERGY, amt);
            break;
        case POWER_RUNIC_POWER:
            unit->SetPower(POWER_RUNIC_POWER, amt);
            break;
        default:
            luaL_error(L, "Bad argument #1 for SetPower - Unknown power type (%i)", type);
            break;
        }
        return 0;
    }

    // SetMaxPower(Type, amt)
    static int SetMaxPower(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        int type = luaL_checkinteger(L, 1);
        int amt = luaL_checkunsigned(L, 2);

        switch(type)
        {
        case POWER_MANA:
            unit->SetMaxPower(POWER_MANA, amt);
            break;
        case POWER_RAGE:
            unit->SetMaxPower(POWER_RAGE, amt);
            break;
        case POWER_ENERGY:
            unit->SetMaxPower(POWER_ENERGY, amt);
            break;
        case POWER_RUNIC_POWER:
            unit->SetMaxPower(POWER_RUNIC_POWER, amt);
            break;
        default:
            luaL_error(L, "Bad argument #1 for SetPower - Unknown power type (%i)", type);
            break;
        }
        return 0;
    }

    // SetDisplayID(id)
    static int SetDisplayID(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint32 model = luaL_checkunsigned(L, 1);
        unit->SetDisplayId(model);
        return 0;
    }

    // SetCoinage(amount)
    static int SetCoinage(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 amt = luaL_checkunsigned(L, 1);
        player->SetMoney(amt);
        return 0;
    }

    // SetKnownTitle(id)
    static int SetKnownTitle(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 id = luaL_checkunsigned(L, 1);
        CharTitlesEntry const* t = sCharTitlesStore.LookupEntry(id);
        if(t)
            player->SetTitle(t, false);
        return 0;
    }

    // UnsetKnownTitle(id)
    static int UnsetKnownTitle(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 id = luaL_checkunsigned(L, 1);
        CharTitlesEntry const* t = sCharTitlesStore.LookupEntry(id);
        if(t)
            player->SetTitle(t, true);
        return 0;
    }


    // Boolean Methods

    // IsInGroup()
    static int IsInGroup(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        Eluna::get()->PushBoolean(L, (player->GetGroup() != NULL));
        return 1;
    }

    // IsInGuild()
    static int IsInGuild(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        Eluna::get()->PushBoolean(L, (player->GetGuildId() != 0));
        return 1;
    }

    // IsGM()
    static int IsGM(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        Eluna::get()->PushBoolean(L, player->isGameMaster());
        return 1;
    }

    // IsAlive()
    static int IsAlive(lua_State* L, Unit* unit)
    {			
        TO_UNIT_BOOL();

        Eluna::get()->PushBoolean(L, unit->isAlive());
        return 1;
    }

    // IsInWorld()
    static int IsInWorld(lua_State* L, Unit* unit)
    {			
        TO_UNIT_BOOL();

        Eluna::get()->PushBoolean(L, unit->IsInWorld());
        return 1;
    }

    // IsPvPFlagged()
    static int IsPvPFlagged(lua_State* L, Unit* unit)
    {			
        TO_UNIT_BOOL();

        Eluna::get()->PushBoolean(L, unit->IsPvP());
        return 1;
    }

    // HasQuest(id)
    static int HasQuest(lua_State* L, Unit* unit)
    {			
        TO_UNIT_BOOL();

        uint32 questId = luaL_checkunsigned(L, 1);
        Eluna::get()->PushBoolean(L, unit->hasQuest(questId));
        return 1;
    }

    // IsHorde()
    static int IsHorde(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        Eluna::get()->PushBoolean(L, (player->GetTeam() == HORDE));
        return 1;
    }

    // IsAlliance()
    static int IsAlliance(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        Eluna::get()->PushBoolean(L, (player->GetTeam() == ALLIANCE));
        return 1;
    }

    // IsInCombat();
    static int IsInCombat(lua_State* L, Unit* unit)
    {
        TO_UNIT_BOOL();

        Eluna::get()->PushBoolean(L, unit->isInCombat());
        return 1;
    }

    // HasTitle(id)
    static int HasTitle(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        uint32 id = luaL_checkunsigned(L, 1);
        Eluna::get()->PushBoolean(L, player->HasTitle(id));
        return 1;
    }

    // HasSpell(id)
    static int HasSpell(lua_State* L, Unit* unit)
    {
        TO_UNIT_BOOL();

        uint32 id = luaL_checkunsigned(L, 1);
        Eluna::get()->PushBoolean(L, unit->HasSpell(id));
        return 1;
    }


    // Other Methods

    // Teleport(mapid, x, y, z, o)
    static int Teleport(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        uint32 mapId = luaL_checkunsigned(L, 1);
        float X = luaL_checknumber(L, 2);
        float Y = luaL_checknumber(L, 3);
        float Z = luaL_checknumber(L, 4);
        float O = luaL_checknumber(L, 5);
        Eluna::get()->PushBoolean(L, player->TeleportTo(mapId, X, Y, Z, O));
        return 1;
    }

    // AddItem(entry, amount)
    static int AddItem(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        uint32 itemId = luaL_checkunsigned(L, 1);
        uint32 itemCount = luaL_checkunsigned(L, 2);
        Eluna::get()->PushBoolean(L, player->AddItem(itemId, itemCount));
        return 0;
    }

    // RemoveItem(entry, amount)
    static int RemoveItem(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 itemId = luaL_checkunsigned(L, 1);
        uint32 itemCount = luaL_checkunsigned(L, 2);

        player->DestroyItemCount(itemId, itemCount, true);
        return 0;
    }

    // SendBroadcastMessage(msg)
    static int SendBroadcastMessage(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        const char* message = luaL_checkstring(L, 1);
        if(std::string(message).length() > 0)
        {
            ChatHandler(player->GetSession()).PSendSysMessage(message);
        }
        return 0;
    }

    // GiveCoinage(amount)
    static int GiveCoinage(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        int amt = luaL_checkinteger(L, 1);
        if(amt > 0)
            Eluna::get()->PushBoolean(L, player->ModifyMoney(amt));
        else
            Eluna::get()->PushBoolean(L, false);
        return 1;
    }

    // RemoveCoinage(amount)
    static int RemoveCoinage(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        int amt = luaL_checkinteger(L, 1);
        if(amt > 0)
            Eluna::get()->PushBoolean(L, player->ModifyMoney(amt));
        else
            Eluna::get()->PushBoolean(L, false);
        return 1;
    }

    // LearnSpell(id)
    static int LearnSpell(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 id = luaL_checkunsigned(L, 1);
        player->learnSpell(id,  false);
        return 0;
    }

    // DeMorph()
    static int DeMorph(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        unit->DeMorph();
        return 0;
    }

    // GossipMenuAddItem(icon, msg, Intid, code, accept_decline_message, money)
    static int GossipMenuAddItem(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        int _icon = luaL_checknumber(L, 1);
        const char* msg = luaL_checkstring(L, 2);
        int _sender = luaL_checknumber(L, 3);
        int _intid = luaL_checknumber(L, 4);
        bool _code = luaL_optint(L, 5, false);
        const char* _promptMsg = luaL_optstring(L, 6, "");
        int _money = luaL_optint(L, 7, 0);

        player->ADD_GOSSIP_ITEM_EXTENDED(_icon, msg, _sender, _intid, _promptMsg, _money, _code);
        return 0;
    }

    // GossipComplete()
    static int GossipComplete(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        player->CLOSE_GOSSIP_MENU();
        return 0;
    }

    // GossipSendMenu(npc_text, unit)
    static int GossipSendMenu(lua_State* L, Unit* unit)
    {
        TO_PLAYER();
        
        int _npcText = luaL_checknumber(L, 1);
        Unit* sender = Eluna::get()->CHECK_UNIT(L, 2);
        player->SEND_GOSSIP_MENU(_npcText, sender->GetGUID());
        return 0;
    }
};
#endif
