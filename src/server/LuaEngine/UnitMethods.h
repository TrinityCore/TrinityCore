#ifndef UNITMETHODS_H
#define UNITMETHODS_H

#define TO_PLAYER()  Player* player; if (!unit || !unit->IsInWorld() || !(player = unit->ToPlayer()))     { return 0; } else (void)0;
#define TO_CREATURE()  Creature* creature; if (!unit || !unit->IsInWorld() || !(creature = unit->ToCreature())) { return 0; } else (void)0;
#define TO_UNIT()  if (!unit || !unit->IsInWorld() || !unit->ToUnit())  { return 0; } else (void)0;


#define TO_PLAYER_BOOL()  Player* player;  if (!unit || !unit->IsInWorld() || !(player = unit->ToPlayer()))     { Eluna::get()->PushBoolean(L, false); return 1; } else (void)0;
#define TO_CREATURE_BOOL()  Creature* creature; if (!unit || !unit->IsInWorld() || !(creature = unit->ToCreature())) { Eluna::get()->PushBoolean(L, false); return 1; } else (void)0;
#define TO_UNIT_BOOL() if (!unit || !unit->IsInWorld() || !unit->ToUnit()) { Eluna::get()->PushBoolean(L, false); return 1; } else (void)0;

class LuaUnit
{
public:

    //SpawnGameObject(entry, x, y, z, o[, respawnDelay])
    static int SummonGameObject(lua_State* L, Unit* unit)
    {
        TO_UNIT();
        
        uint32 entry = luaL_checkunsigned(L, 1);
        float x = luaL_checknumber(L, 2);
        float y = luaL_checknumber(L, 3);
        float z = luaL_checknumber(L, 4);
        float o = luaL_checknumber(L, 5);
        uint32 respawnDelay = luaL_optunsigned(L, 6, 30);
        Eluna::get()->PushGO(L, unit->SummonGameObject(entry, x, y, z, o, 0, 0, 0, 0, respawnDelay));
        return 1;
    }

    //SpawnCreature(entry, x, y, z, o[, despawnDelay])
    static int SpawnCreature(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint32 entry = luaL_checkunsigned(L, 1);
        float x = luaL_checknumber(L, 2);
        float y = luaL_checknumber(L, 3);
        float z = luaL_checknumber(L, 4);
        float o = luaL_checknumber(L, 5);
        uint32 desp = luaL_optunsigned(L, 6, 0);
        Eluna::get()->PushUnit(L, unit->SummonCreature(entry, x, y, z, o, desp ? TEMPSUMMON_TIMED_OR_DEAD_DESPAWN : TEMPSUMMON_MANUAL_DESPAWN, desp));
        return 1;
    }

    //Despawn([despawnDelay])
    static int Despawn(lua_State* L, Unit* unit)
    {
        TO_CREATURE();
        
        uint32 time = luaL_optunsigned(L, 1, 0);
        creature->DespawnOrUnsummon(time);
        return 0;
    }

    //GetArenaPoints()
    static int GetArenaPoints(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        Eluna::get()->PushUnsigned(L, player->GetArenaPoints());
        return 1;
    }

    //KnockbackFrom()
    static int KnockbackFrom(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        float x = luaL_checknumber(L, 1);
        float y = luaL_checknumber(L, 2);
        float speedXY = luaL_checknumber(L, 3);
        float speedZ = luaL_checknumber(L, 4);
        unit->KnockbackFrom(x, y, speedXY, speedZ);
        return 0;
    }

    //JumpTo(WorldObj, speedZ)
    static int JumpTo(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        WorldObject* obj = Eluna::get()->CHECK_WORLDOBJECT(L, 1);
        float speedZ = luaL_checknumber(L, 2);
        if(!obj)
            return 0;

        unit->JumpTo(obj, speedZ);
        return 0;
    }

    //Jump(speedXY, speedZ[, forward])
    static int Jump(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        float speedXY = luaL_checknumber(L, 1);
        float speedZ = luaL_checknumber(L, 2);
        bool forward = luaL_optbool(L, 3, true);
        unit->JumpTo(speedXY, speedZ, forward);
        return 0;
    }

    //JumpToCoords(x, y, z, speedXY, speedZ)
    static int JumpToCoords(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        float x = luaL_checknumber(L, 1);
        float y = luaL_checknumber(L, 2);
        float z = luaL_checknumber(L, 3);
        float speedXY = luaL_checknumber(L, 4);
        float speedZ = luaL_checknumber(L, 5);
        unit->GetMotionMaster()->MoveJump(x, y, z, speedXY, speedZ);
        return 0;
    }

    //MoveCharge(x, y, z, speed)
    static int MoveCharge(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        float x = luaL_checknumber(L, 1);
        float y = luaL_checknumber(L, 2);
        float z = luaL_checknumber(L, 3);
        float speed = luaL_checknumber(L, 4);
        unit->GetMotionMaster()->MoveCharge(x, y, z, speed);
        return 0;
    }

    //MoveChase(target[, dist, angle])
    static int MoveChase(lua_State* L, Unit* unit)
    {
        TO_UNIT();
        
        Unit* target = Eluna::get()->CHECK_UNIT(L, 1);
        float dist = luaL_optnumber(L, 2, 0.0f);
        float angle = luaL_optnumber(L, 3, 0.0f);
        unit->GetMotionMaster()->MoveChase(target, dist, angle);
        return 0;
    }

    //SetStunned(apply)
    static int SetStunned(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        bool apply = luaL_optbool(L, 1, true);
        unit->SetControlled(apply, UNIT_STATE_STUNNED);
        return 0;
    }

    //SetRooted(apply)
    static int SetRooted(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        bool apply = luaL_optbool(L, 1, true);
        unit->SetControlled(apply, UNIT_STATE_ROOT);
        return 0;
    }

    //SetConfused(apply)
    static int SetConfused(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        bool apply = luaL_optbool(L, 1, true);
        unit->SetControlled(apply, UNIT_STATE_CONFUSED);
        return 0;
    }

    //SetFeared(apply)
    static int SetFeared(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        bool apply = luaL_optbool(L, 1, true);
        unit->SetControlled(apply, UNIT_STATE_FLEEING);
        return 0;
    }

    //MoveTo(id, x, y, z[, generatePath])
    static int MovePoint(lua_State* L, Unit* unit)
    {
        TO_UNIT();
        
        float id = luaL_checknumber(L, 1);
        float x = luaL_checknumber(L, 2);
        float y = luaL_checknumber(L, 3);
        float z = luaL_checknumber(L, 4);
        bool generatePath = luaL_optbool(L, 5, true);
        unit->GetMotionMaster()->MovePoint(id, x, y, z, generatePath);
        return 0;
    }

    //MoveFollow(target, dist, angle)
    static int MoveFollow(lua_State* L, Unit* unit)
    {
        TO_UNIT();
        
        Unit* target = Eluna::get()->CHECK_UNIT(L, 1);
        float dist = luaL_checknumber(L, 2);
        float angle = luaL_checknumber(L, 3);
        unit->GetMotionMaster()->MoveFollow(target, dist, angle);
        return 0;
    }

    //MoveClear()
    static int MoveClear(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        unit->GetMotionMaster()->Clear();
        return 0;
    }

    //MoveRandom(radius)
    static int MoveRandom(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        float radius = luaL_checknumber(L, 1);
        unit->GetMotionMaster()->MoveRandom(radius);
        return 0;
    }

    //MoveRotate(time, left)
    static int MoveRotate(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint32 time = luaL_checkunsigned(L, 1);
        bool left = luaL_optbool(L, 2, true);
        unit->GetMotionMaster()->MoveRotate(time, left ? ROTATE_DIRECTION_LEFT : ROTATE_DIRECTION_RIGHT);
        return 0;
    }

    //SetWalk(enable)
    static int SetWalk(lua_State* L, Unit* unit)
    {
        TO_UNIT();
        
        bool enable = luaL_optbool(L, 1, true);
        unit->SetWalk(enable);
        return 0;
    }

    //SetSpeed(type, speed[, forced])
    static int SetSpeed(lua_State* L, Unit* unit)
    {
        TO_UNIT();
        
        uint32 type = luaL_checkunsigned(L, 1);
        float rate = luaL_checknumber(L, 2);
        bool forced = luaL_optbool(L, 3, false);
        if(type >= MAX_MOVE_TYPE)
            sLog->outError(LOG_FILTER_GENERAL, "Eluna::Invalid movement type (%u)  for SetSpeed", type);
        else
            unit->SetSpeed((UnitMoveType)type, rate, forced);
        return 0;
    }

    //GetHonorPoints()
    static int GetHonorPoints(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        Eluna::get()->PushUnsigned(L, player->GetHonorPoints());
        return 1;
    }
    //GetSelection()
    static int GetSelection(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        Eluna::get()->PushUnit(L, player->GetSelectedUnit());
        return 1;
    }

    //GetSecurity
    static int GetSecurity(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        Eluna::get()->PushInteger(L, player->GetSession()->GetSecurity());
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

        if (!player->GetGuildId())
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

    // GetZoneId()
    static int GetZoneId(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        Eluna::get()->PushUnsigned(L, unit->GetZoneId());
        return 1;
    }

    //GetInstanceId()
    static int GetInstanceId(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        Eluna::get()->PushUnsigned(L, unit->GetInstanceId());
        return 1;
    }

    //GetPhaseMask()
    static int GetPhaseMask(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        Eluna::get()->PushUnsigned(L, unit->GetPhaseMask());
        return 1;
    }

    // GetAreaId()
    static int GetAreaId(lua_State* L, Unit* unit)
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

    // GetPower([powertype])
    static int GetPower(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        int type = luaL_optint(L, 1, -1);
        if (type == -1)
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
            luaL_error(L, "Bad argument #1 to :GetPower(index) - specified out of range index (%i)", type);
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
        if (type == -1)
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

    //GetPowerType()
    static int GetPowerType(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        Eluna::get()->PushInteger(L, unit->getPowerType());
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

        float percent = (unit->GetPower(unit->getPowerType()) / unit->GetMaxPower(unit->getPowerType())) * 100;
        Eluna::get()->PushFloat(L, percent);
        return 1;
    }

    // GetGender()
    static int GetGender(lua_State* L, Unit* unit)
    {
        TO_UNIT();
        Eluna::get()->PushUnsigned(L, unit->getGender());
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

    // GetItemCount(id[, checkbank])
    static int GetItemCount(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        int id = luaL_checknumber(L, 1);
        bool checkinBank = luaL_checkbool(L, 2);
        Eluna::get()->PushUnsigned(L, player->GetItemCount(id, checkinBank));
        return 1;
    }

	// GetLifetimeKills()
	static int GetLifetimeKills(lua_State* L, Unit* unit)
	{
		TO_PLAYER();

		uint32 currentKills = player->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS);
		Eluna::get()->PushUnsigned(L, currentKills);
		return 1;
	}

    // GetUnitType()
    static int GetUnitType(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        if (unit->ToPlayer())
            Eluna::get()->PushString(L, "Player");
        else if (unit->ToCreature())
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

    // GetGearLevel()
    static int GetGearLevel(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        Eluna::get()->PushFloat(L, player->GetAverageItemLevel());
        return 1;
    }

    // GetEntry()
    static int GetEntry(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        Eluna::get()->PushUnsigned(L, unit->GetEntry());
        return 1;
    }

	// GetFaction()
	static int GetFaction(lua_State* L, Unit* unit)
	{
		TO_UNIT();

		Eluna::get()->PushUnsigned(L, unit->getFaction());
		return 1;
	}

    // Set Methods

	// SetFaction(id)
	static int SetFaction(lua_State* L, Unit* unit)
	{
		TO_UNIT();

		uint32 factionId = luaL_checkunsigned(L, 1);
		unit->setFaction(factionId);
		return 0;
	}

    // SetLevel(level)
    static int SetLevel(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint32 newLevel = luaL_checkunsigned(L, 1);
        unit->SetLevel(newLevel);
        return 0;
    }

    //SetPhaseMask(Phase, update)
    static int SetPhaseMask(lua_State* L, Unit* unit)
    {
        TO_UNIT();
        uint32 phaseMask = luaL_checkunsigned(L, 1);
        bool Update = luaL_optbool(L, 2, true);
        unit->SetPhaseMask(phaseMask, Update);
        return 0;
    }

    //SetArenaPoints(amount)
    static int SetArenaPoints(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 arenaP = luaL_checkunsigned(L, 1);
        player->SetArenaPoints(arenaP);
        return 0;
    }

    //SetHonorPoints(amount)
    static int SetHonorPoints(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 honorP = luaL_checkunsigned(L, 1);
        player->SetHonorPoints(honorP);
        return 0;
    }

	// SetLifetimeKills(val)
	static int SetLifetimeKills(lua_State* L, Unit* unit)
	{
		TO_PLAYER();

		uint32 val = luaL_checkunsigned(L, 1);
		player->SetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS, val);
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

    // SetFacing(o)
    static int SetFacing(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        float o = luaL_checknumber(L, 1);
        unit->SetFacingTo(o);
        return 0;
    }

    //SetDeathState(value)
    static int SetDeathState(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint8 ds = luaL_checkunsigned(L, 1);
        unit->setDeathState((DeathState)ds);
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

    //SetBindPoint(x, y, z, mapid, areaid)
    static int SetBindPoint(lua_State * L, Unit* unit)
    {
        TO_PLAYER();

        float x = luaL_checknumber(L, 1);
        float y = luaL_checknumber(L, 2);
        float z = luaL_checknumber(L, 3);
        uint32 mapId = luaL_checkunsigned(L, 4);
        uint32 areaId = luaL_checkunsigned(L, 5);

        WorldLocation loc(mapId, x, y, z);
        player->SetHomebind(loc, areaId);
        return 0;
    }

    //SetBindPointAtPlayerLoc()
    static int SetBindPointAtPlayerLoc(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        WorldLocation loc;
        player->GetPosition(&loc);
        loc.m_mapId = player->GetMapId();
        player->SetHomebind(loc, player->GetAreaId());
        return 0;
    }

    // SetKnownTitle(id)
    static int SetKnownTitle(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 id = luaL_checkunsigned(L, 1);
        CharTitlesEntry const* t = sCharTitlesStore.LookupEntry(id);
        if (t)
            player->SetTitle(t, false);
        return 0;
    }

    // UnsetKnownTitle(id)
    static int UnsetKnownTitle(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 id = luaL_checkunsigned(L, 1);
        CharTitlesEntry const* t = sCharTitlesStore.LookupEntry(id);
        if (t)
            player->SetTitle(t, true);
        return 0;
    }

    // AdvanceSkillsToMax()
    static int AdvanceSkillsToMax(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        player->UpdateSkillsToMaxSkillsForLevel();
        return 0;
    }

    // AdvanceAllSkills(value)
    static int AdvanceAllSkills(lua_State* L, Unit * unit)
    {
        TO_PLAYER();

        uint32 skillsArray[] = { SKILL_BOWS, SKILL_CROSSBOWS, SKILL_DAGGERS, SKILL_DEFENSE, SKILL_UNARMED, SKILL_GUNS, SKILL_AXES, SKILL_MACES, SKILL_SWORDS, SKILL_POLEARMS,
            SKILL_STAVES, SKILL_2H_AXES, SKILL_2H_MACES, SKILL_2H_SWORDS, SKILL_WANDS, SKILL_SHIELD, SKILL_FISHING, SKILL_MINING, SKILL_ENCHANTING, SKILL_BLACKSMITHING,
            SKILL_ALCHEMY, SKILL_HERBALISM, SKILL_ENGINEERING, SKILL_JEWELCRAFTING, SKILL_LEATHERWORKING, SKILL_LOCKPICKING, SKILL_INSCRIPTION, SKILL_SKINNING, SKILL_TAILORING };
        uint32 step = luaL_checkunsigned(L, 1);

        if (!step)
            return 0;

        for (int i = 0; i < sizeof(skillsArray); ++i)
        {
            if (player->HasSkill(skillsArray[i]))
                player->UpdateSkill(skillsArray[i], step);
        }
        return 0;
    }

    // AdvanceSkill(skill_id, step)
    static int AdvanceSkill(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 _skillId = luaL_checkunsigned(L, 1);
        uint32 _step = luaL_checkunsigned(L, 2);
        if (_skillId && _step)
        {
            if (player->HasSkill(_skillId))
                player->UpdateSkill(_skillId, _step);
        }
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

	// IsDead()
	static int IsDead(lua_State* L, Unit* unit)
	{
		TO_UNIT_BOOL();

		Eluna::get()->PushBoolean(L, unit->isDead());
		return 1;
	}

    //IsInArenaTeam(type) type : 0 = 2v2, 1 = 3v3, 2 = 5v5
    static int IsInArenaTeam(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        uint32 type = luaL_checkunsigned(L, 1);
        if (type < MAX_ARENA_SLOT && player->GetArenaTeamId(type))
            Eluna::get()->PushBoolean(L, true);
        else
            Eluna::get()->PushBoolean(L, false);
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

	// HasItem(itemId, count)
	static int HasItem(lua_State* L, Unit* unit)
	{
		TO_PLAYER_BOOL();

		uint32 itemId = luaL_checkunsigned(L, 1);
		uint32 count = luaL_optunsigned(L, 2, 1);
		Eluna::get()->PushBoolean(L, player->HasItemCount(itemId, count));
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

	// AddLifetimeKills(val)
	static int AddLifetimeKills(lua_State* L, Unit* unit)
	{
		TO_PLAYER();

		uint32 val = luaL_checkunsigned(L, 1);
		uint32 currentKills = player->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS);
		player->SetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS, currentKills + val);
		return 0;
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

	// RemoveLifetimeKills(val)
	static int RemoveLifetimeKills(lua_State* L, Unit* unit)
	{
		TO_PLAYER();

		uint32 val = luaL_checkunsigned(L, 1);
		uint32 currentKills = player->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS);
		if (currentKills == 0 || val > currentKills)
		{
			luaL_error(L, "Bad value. Player's Lifetime Kills must be greater than 0 and the value cannot be greater than the actual kills.");
			return 0;
		}
		player->SetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS, currentKills - val);
		return 0;
	}

    // SendBroadcastMessage(msg)
    static int SendBroadcastMessage(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        const char* message = luaL_checkstring(L, 1);
        if (string(message).length() > 0)
            ChatHandler(player->GetSession()).SendSysMessage(message);
        return 0;
    }

    // SendAreaTriggerMessage(msg)
    static int SendAreaTriggerMessage(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        const char* msg = luaL_checkstring(L, 1);
        if (string(msg).length() > 0)
            player->GetSession()->SendAreaTriggerMessage(msg);
        return 0;
    }

    // SendNotification(msg)
    static int SendNotification(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        const char* msg = luaL_checkstring(L, 1);
        if (string(msg).length() > 0)
            player->GetSession()->SendNotification(msg);
        return 0;
    }

    // SendUnitWhisper(msg, receiver, bossWhisper)
    static int SendUnitWhisper(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        const char* msg = luaL_checkstring(L, 1);
        Unit* receiver = Eluna::get()->CHECK_UNIT(L, 2);
        if (receiver && string(msg).length() > 0)
            unit->MonsterWhisper(msg, receiver->GetGUID(), false);
        return 0;
    }

    // SendUnitSay(msg, language)
    static int SendUnitSay(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        const char* msg = luaL_checkstring(L, 1);
        uint32 language = luaL_checknumber(L, 2);
        if (string(msg).length() > 0)
            unit->MonsterSay(msg, language, unit->GetGUID());
        return 0;
    }

    // SendUnitYell(msg, language)
    static int SendUnitYell(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        const char* msg = luaL_checkstring(L, 1);
        uint32 language = luaL_checknumber(L, 2);
        if (string(msg).length() > 0)
            unit->MonsterYell(msg, language, unit->GetGUID());
        return 0;
    }

    // SendPacketToPlayer(packet)
    static int SendPacketToPlayer(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        WorldPacket* data = Eluna::get()->CHECK_PACKET(L, 1);
        if (data)
            player->GetSession()->SendPacket(data);
        return 0;
    }

    // SendPacket(packet)
    static int SendPacket(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        WorldPacket* data = Eluna::get()->CHECK_PACKET(L, 1);
        if (data)
            player->SendMessageToSet(data, false);
        return 0;
    }

    // SendPacketToGroup(packet, sendToPlayersInBattleground)
    static int SendPacketToGroup(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        WorldPacket* data = Eluna::get()->CHECK_PACKET(L, 1);
        bool ignorePlayersInBg = luaL_checkbool(L, 2);
        if (data && player->GetGroup())
            player->GetGroup()->BroadcastPacket(data, ignorePlayersInBg, -1, player->GetGUID());
        return 0;
    }

    // SendPacketToGuild(packet)
    static int SendPacketToGuild(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        WorldPacket* data = Eluna::get()->CHECK_PACKET(L, 1);
        if (data && player->GetGuild())
            player->GetGuild()->BroadcastPacket(data);
        return 0;
    }

    // SendPacketToRankedInGuild(packet, rankId)
    static int SendPacketToRankedInGuild(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        WorldPacket* data = Eluna::get()->CHECK_PACKET(L, 1);
        uint8 ranked = luaL_checkunsigned(L, 2);
        if (data && player->GetGuild())
            player->GetGuild()->BroadcastPacketToRank(data, ranked);
        return 0;
    }

	// :SendVendorWindow(unit)
	static int SendVendorWindow(lua_State* L, Unit* unit)
	{
		TO_PLAYER();

		Unit* sendTo = Eluna::get()->CHECK_UNIT(L, 1);
		if (!sendTo)
			return 0;
		player->GetSession()->SendListInventory(sendTo->GetGUID());
		return 0;
	}

    // GiveCoinage(amount)
    static int GiveCoinage(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        int amt = luaL_checkinteger(L, 1);
        if (amt > 0)
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
        if (amt > 0)
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

    // ResurrectPlayer(percent, sickness(bool))
    static int ResurrectPlayer(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        float percent = luaL_optnumber(L, 1, 100.0f);
        bool sickness = luaL_optbool(L, 2, false);
        player->ResurrectPlayer(percent, sickness);
        return 0;
    }

    // CastSpell(spellID) - self
    static int CastSpell(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint32 spell = luaL_checkunsigned(L, 1);
        unit->CastSpell(unit, spell, true);
        return 0;
    }

    // CastSpellOnTarget(spellID, unit, triggered) - See if can be gameobject target
    static int CastSpellOnTarget(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint32 spell = luaL_checkunsigned(L, 1);
        Unit* target = Eluna::get()->CHECK_UNIT(L, 2);
        bool triggered = luaL_optbool(L, 3, true);
        if (target)
            unit->CastSpell(target, spell, triggered);
        return 0;
    }

    // CastSpellAoF(x, y, z, id) - to coords
    static int CastSpellAoF(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        float _x = luaL_checknumber(L, 1);
        float _y = luaL_checknumber(L, 2);
        float _z = luaL_checknumber(L, 3);
        uint32 spell = luaL_checkunsigned(L, 4);
        unit->CastSpell(_x, _y, _z, spell, true);
        return 0;
    }

    // FullCastSpell(spellID) - self
    static int FullCastSpell(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint32 spell = luaL_checkunsigned(L, 1);
        unit->CastSpell(unit, spell, false);
        return 0;
    }

    // FullCastSpellOnTarget(spellID, unit) - See if can be gameobject target
    static int FullCastSpellOnTarget(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint32 spell = luaL_checkunsigned(L, 1);
        Unit* target = Eluna::get()->CHECK_UNIT(L, 2);
        if (target)
            unit->CastSpell(target, spell, false);
        return 0;
    }

    // GetAccountId()
    static int GetAccountId(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        Eluna::get()->PushUnsigned(L, player->GetSession()->GetAccountId());
        return 1;
    }

    // GetAccountName()
    static int GetAccountName(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        std::string accName;
        if (sAccountMgr->GetName(player->GetSession()->GetAccountId(), accName))
            Eluna::get()->PushString(L, accName.c_str());
        else
            return 0;
        return 1;
    }

    // GetAITargets()
    static int GetAITargets(lua_State* L, Unit* unit)
    {
        TO_CREATURE();

        lua_newtable(L);
        int tbl = lua_gettop(L);
        uint32 i = 0;

        ThreatContainer::StorageType const &threatList = creature->getThreatManager().getThreatList();
        ThreatContainer::StorageType::const_iterator itr;
        for (itr = threatList.begin(); itr != threatList.end(); ++itr)
        {
            Unit* target = (*itr)->getTarget();
            if (!target)
                continue;
            ++i;
            Eluna::get()->PushUnsigned(L, i);
            Eluna::get()->PushUnit(L, target);
            lua_settable(L, tbl);
        }

        lua_settop(L, tbl);
        return 1;
    }

    // GetAITargetsCount()
    static int GetAITargetsCount(lua_State* L, Unit* unit)
    {
        TO_CREATURE();

        Eluna::get()->PushUnsigned(L, creature->getThreatManager().getThreatList().size());
        return 1;
    }

    // GetAura(spellID)
    static int GetAura(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint32 spellID = luaL_checkunsigned(L, 1);
        Eluna::get()->PushAura(L, unit->GetAura(spellID));
        return 1;
    }

    // GetMapId()
    static int GetMapId(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        Eluna::get()->PushUnsigned(L, unit->GetMapId());
        return 1;
    }

	// GetCombatTime()
	static int GetCombatTime(lua_State* L, Unit* unit)
	{
		TO_UNIT();

		Eluna::get()->PushUnsigned(L, unit->GetCombatTimer());
		return 1;
	}

	// ClearInCombat()
	static int ClearInCombat(lua_State* L, Unit* unit)
	{
		TO_UNIT();

		unit->ClearInCombat();
		return 0;
	}

    // GossipMenuAddItem(icon, msg, Intid, code, accept_decline_message, money)
    static int GossipMenuAddItem(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 _icon = luaL_checkunsigned(L, 1);
        const char* msg = luaL_checkstring(L, 2);
        uint32 _sender = luaL_checkunsigned(L, 3);
        uint32 _intid = luaL_checkunsigned(L, 4);
        bool _code = luaL_optbool(L, 5, false);
        const char* _promptMsg = luaL_optstring(L, 6, "");
        uint32 _money = luaL_optunsigned(L, 7, 0);
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

        uint32 _npcText = luaL_checkunsigned(L, 1);
        Unit* sender = Eluna::get()->CHECK_UNIT(L, 2);
        if (sender)
        {
            if (sender->ToPlayer())
            {
                uint32 menu_id = luaL_checkunsigned(L, 3);
                player->PlayerTalkClass->GetGossipMenu().SetMenuId(menu_id);
            }
            player->SEND_GOSSIP_MENU(_npcText, sender->GetGUID());
        }
        return 0;
    }

    // GossipClearMenu()
    static int GossipClearMenu(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        player->PlayerTalkClass->ClearMenus();
        return 0;
    }

    // PlaySoundToPlayer(soundId)
    static int PlaySoundToPlayer(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 soundId = luaL_checkunsigned(L, 1);
        SoundEntriesEntry const* soundEntry = sSoundEntriesStore.LookupEntry(soundId);
        if (!soundEntry)
            return 0;

        player->PlayDirectSound(soundId, player);
        return 0;
    }

    // PlayDirectSound(soundId,  player)
    static int PlayDirectSound(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint32 soundId = luaL_checkunsigned(L, 1);
        Player* player = Eluna::get()->CHECK_PLAYER(L, 2);
        if (!sSoundEntriesStore.LookupEntry(soundId))
            return 0;

        if (player)
            unit->PlayDirectSound(soundId, player);
        else
            unit->PlayDirectSound(soundId);
        return 0;
    }

    // PlayDistanceSound(soundId,  player)
    static int PlayDistanceSound(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint32 soundId = luaL_checkunsigned(L, 1);
        Player* player = Eluna::get()->CHECK_PLAYER(L, 2);
        if (!sSoundEntriesStore.LookupEntry(soundId))
            return 0;

        if (player)
            unit->PlayDistanceSound(soundId, player);
        else
            unit->PlayDistanceSound(soundId);
        return 0;
    }

    // Kill([target, durabilityLoss]) - Creates a timed event. Calls set to 0 will call inf returns eventID.
    static int Kill(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        Unit* target = Eluna::get()->CHECK_UNIT(L, 1);
        bool durLoss = luaL_optbool(L, 2, true);
        unit->Kill((target ? target : unit), durLoss);
        return 0;
    }

    // RegisterEvent(function, delay, calls)
    static int RegisterEvent(lua_State* L, Unit* unit)
    {
        TO_CREATURE();

        uint32 delay = luaL_checkunsigned(L, 2);
        uint32 repeats = luaL_checkunsigned(L, 3);
        Eluna::LuaCreatureScript::LuaCreatureAI* luaAI = sLuaCreatureScript->GetAI(creature);
        if (!luaAI)
        {
            luaL_error(L, "Creature has no registered creature events, please register one before using RegisterEvent");
            return 0;
        }
        if (!strcmp(luaL_typename(L, 1), "function") || delay > 0)
        {
            lua_settop(L, 1);
            int functionRef = lua_ref(L, true);
            luaAI->LuaEventCreate(functionRef, delay, repeats);
            Eluna::get()->PushInteger(L, functionRef);
        }
        else
            return 0;
        return 1;

    }

    // RemoveEventByID(eventID)
    static int RemoveEventByID(lua_State* L, Unit* unit)
    {
        TO_CREATURE();

        int eventID = luaL_checkinteger(L, 1);
        Eluna::LuaCreatureScript::LuaCreatureAI* luaAI = sLuaCreatureScript->GetAI(creature);
        if (luaAI)
            luaAI->LuaEventCancel(eventID);
        return 0;
    }

    // RemoveEvents()
    static int RemoveEvents(lua_State* L, Unit* unit)
    {
        TO_CREATURE();

        Eluna::LuaCreatureScript::LuaCreatureAI* luaAI = sLuaCreatureScript->GetAI(creature);
        if (luaAI)
            luaAI->LuaEventsReset();
        return 0;
    }

    static int GetInt32Value(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint16 index = luaL_checkunsigned(L, 1);
        Eluna::get()->PushInteger(L, unit->GetInt32Value(index));
        return 1;
    }

    static int GetUInt32Value(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint16 index = luaL_checkunsigned(L, 1);
        Eluna::get()->PushUnsigned(L, unit->GetUInt32Value(index));
        return 1;
    }

    static int GetFloatValue(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint16 index = luaL_checkunsigned(L, 1);
        Eluna::get()->PushFloat(L, unit->GetFloatValue(index));
        return 1;
    }

    static int GetByteValue(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint16 index = luaL_checkunsigned(L, 1);
        uint8 offset = luaL_checkunsigned(L, 2);
        Eluna::get()->PushUnsigned(L, unit->GetByteValue(index, offset));
        return 1;
    }

    static int GetUInt16Value(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint16 index = luaL_checkunsigned(L, 1);
        uint8 offset = luaL_checkunsigned(L, 2);
        Eluna::get()->PushUnsigned(L, unit->GetUInt16Value(index, offset));
        return 1;
    }

    static int SetInt32Value(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint16 index = luaL_checkunsigned(L, 1);
        int32 value = luaL_checkinteger(L, 2);
        unit->SetInt32Value(index, value);
        return 0;
    }

    static int SetUInt32Value(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint16 index = luaL_checkunsigned(L, 1);
        uint32 value = luaL_checkunsigned(L, 2);
        unit->SetUInt32Value(index, value);
        return 0;
    }

    static int UpdateUInt32Value(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint16 index = luaL_checkunsigned(L, 1);
        uint32 value = luaL_checkunsigned(L, 2);
        unit->UpdateUInt32Value(index, value);
        return 0;
    }

    static int SetFloatValue(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint16 index = luaL_checkunsigned(L, 1);
        float value = luaL_checknumber(L, 2);

        unit->SetFloatValue(index, value);
        return 0;
    }

    static int SetByteValue(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint16 index = luaL_checkunsigned(L, 1);
        uint8 offset = luaL_checkunsigned(L, 2);
        uint8 value = luaL_checkunsigned(L, 3);
        unit->SetByteValue(index, offset, value);
        return 0;
    }

    static int SetUInt16Value(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint16 index = luaL_checkunsigned(L, 1);
        uint8 offset = luaL_checkunsigned(L, 2);
        uint16 value = luaL_checkunsigned(L, 3);
        unit->SetUInt16Value(index, offset, value);
        return 0;
    }

    static int SetInt16Value(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint16 index = luaL_checkunsigned(L, 1);
        uint8 offset = luaL_checkunsigned(L, 2);
        int16 value = luaL_checkinteger(L, 3);
        unit->SetInt16Value(index, offset, value);
        return 0;
    }

    /* Vehicle */

    // IsOnVehicle()
    static int IsOnVehicle(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        if ((unit->GetVehicle()) || (unit->ToPlayer() && unit->IsVehicle()))
            lua_pushboolean(L, 1);
        else
            lua_pushboolean(L, 0);
        return 1;
    }

    // DismissVehicle()
    static int DismissVehicle(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        if (unit->GetVehicle())
            unit->GetVehicle()->Dismiss();
        return 0;
    }

    // AddVehiclePassenger(unit, seatId)
    static int AddVehiclePassenger(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        Unit* passenger = Eluna::get()->CHECK_UNIT(L, 1);
        int8 seatId = luaL_checkunsigned(L, 2);
        Vehicle* _vehicle = unit->GetVehicle();
        if (!_vehicle)
            return 0;

        _vehicle->AddPassenger(passenger, seatId);
        return 0;
    }

    // EjectPassenger(unit) (GIVES LINKER ERROR)
    /*
    static int EjectPassenger(lua_State* L, Unit* unit) 
    {
    TO_UNIT();

    Unit* passenger = Eluna::get()->CHECK_UNIT(L, 1);
    Vehicle* _vehicle = unit->GetVehicle();
    if (!_vehicle)
    return 0;

    _vehicle->EjectPassenger(passenger, unit);
    return 0;
    }*/

    // RemovePassenger(unit)
    static int RemovePassenger(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        Unit* passenger = Eluna::get()->CHECK_UNIT(L, 1);
        Vehicle* _vehicle = unit->GetVehicle();
        if (!_vehicle)
            return 0;

        _vehicle->RemovePassenger(passenger);
        return 0;
    }

    // RemoveAllPassengers()
    static int RemoveAllPassengers(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        Unit* _unit = unit->GetVehicleBase();
        if (!_unit)
            return 0;

        _unit->GetVehicle()->RemoveAllPassengers();
        return 0;
    }

    // GetPassenger(seatId)
    static int GetPassenger(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        int8 seatId = luaL_checkunsigned(L, 1);
        Unit* _unit = unit->GetVehicleBase();
        if (!_unit)
            return 0;

        Eluna::get()->PushUnit(L, _unit->GetVehicle()->GetPassenger(seatId));
        return 1;
    }

    // GetNextEmptySeat(seatId)
    static int GetNextEmptySeat(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        int8 seatId = luaL_checkunsigned(L, 1);
        Unit* _unit = unit->GetVehicleBase();
        if (!_unit)
            return 0;

        //Eluna::get()->PushInteger(L, _unit->GetVehicle()->GetNextEmptySeat(seatId, true));
        //return 1;
        return 0;
    }

    // GetAvailableSeats()
    static int GetAvailableSeats(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        Unit* _unit = unit->GetVehicleBase();
        if (!_unit)
            return 0;

        Eluna::get()->PushUnsigned(L, _unit->GetVehicle()->GetAvailableSeatCount());
        return 1;
    }

    // GetVehicleBase()
    static int GetVehicleBase(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        Unit* _unit = unit->GetVehicleBase();
        if (_unit)
            Eluna::get()->PushUnit(L, _unit);
        else
            lua_pushnil(L);
        return 1;
    }

    // HasEmptySeat(seatId)
    static int HasEmptySeat(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        int8 seatId = luaL_checkunsigned(L, 1);
        Unit* _unit = unit->GetVehicleBase();
        if (!_unit)
            return 0;

        Eluna::get()->PushBoolean(L, _unit->GetVehicle()->HasEmptySeat(seatId));
        return 1;
    }
};
#endif
