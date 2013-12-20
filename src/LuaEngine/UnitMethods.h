/*
* Copyright (C) 2010 - 2013 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information
*/

#ifndef UNITMETHODS_H
#define UNITMETHODS_H

namespace LuaUnit
{
    int Attack(lua_State* L, Unit* unit)
    {
        Unit* who = sEluna->CHECK_UNIT(L, 1);
        bool meleeAttack = luaL_optbool(L, 2, false);

        if (!who)
            sEluna->Push(L, false);
        else
            sEluna->Push(L, unit->Attack(who, meleeAttack));
        return 1;
    }

    int ClearThreatList(lua_State* L, Unit* unit)
    {
        unit->getThreatManager().clearReferences();
        return 0;
    }

    int SetOwnerGUID(lua_State* L, Unit* unit)
    {
        uint64 guid = sEluna->CHECK_ULONG(L, 1);

        unit->SetOwnerGUID(guid);
        return 0;
    }

    int GetOwner(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->GetOwner());
        return 1;
    }

    int GetOwnerGUID(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->GetOwnerGUID());
        return 1;
    }

    int GetMap(lua_State* L, Unit* unit)
    {
        Map* map = unit->GetMap();
        sEluna->Push(L, map);
        return 1;
    }

    int GetRelativePoint(lua_State* L, Unit* unit)
    {
        float dist = luaL_checknumber(L, 1);
        float rad = luaL_checknumber(L, 2);

        float o = Position::NormalizeOrientation(unit->GetOrientation() + rad);
        sEluna->Push(L, unit->GetPositionX() + (dist * cosf(o)));
        sEluna->Push(L, unit->GetPositionY() + (dist * sinf(o)));
        sEluna->Push(L, o);
        return 3;
    }

    int Mount(lua_State* L, Unit* unit)
    {
        uint32 displayId = luaL_checkunsigned(L, 1);

        unit->Mount(displayId);
        return 0;
    }

    int Dismount(lua_State* L, Unit* unit)
    {
        if (unit->IsMounted())
        {
            unit->Dismount();
            unit->RemoveAurasByType(SPELL_AURA_MOUNTED);
        }
        return 0;
    }

    int IsMounted(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->IsMounted());
        return 1;
    }

    int IsWithinLoS(lua_State* L, Unit* unit)
    {
        float x = luaL_checknumber(L, 1);
        float y = luaL_checknumber(L, 2);
        float z = luaL_checknumber(L, 3);

        sEluna->Push(L, unit->IsWithinLOS(x, y, z));
        return 1;
    }

    /*int IsRooted(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->isRooted());
        return 1;
    }*/

    int IsFullHealth(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->IsFullHealth());
        return 1;
    }

    int IsWithinDistInMap(lua_State* L, Unit* unit)
    {
        WorldObject* obj = sEluna->CHECK_WORLDOBJECT(L, 1);
        if (!obj)
            return 0;
        float radius = luaL_checknumber(L, 2);

        sEluna->Push(L, unit->IsWithinDistInMap(obj, radius));
        return 1;
    }

    int IsInAccessiblePlaceFor(lua_State* L, Unit* unit)
    {
        Creature* creature = sEluna->CHECK_CREATURE(L, 1);
        if (!creature)
            return 0;

        sEluna->Push(L, unit->isInAccessiblePlaceFor(creature));
        return 1;
    }

    int GetMountId(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->GetMountID());
        return 1;
    }

    int GetDistance(lua_State* L, Unit* unit)
    {
        WorldObject* obj = sEluna->CHECK_WORLDOBJECT(L, 1);
        if (obj && obj->IsInWorld())
            sEluna->Push(L, unit->GetDistance(obj));
        else
        {
            float X = luaL_checknumber(L, 1);
            float Y = luaL_checknumber(L, 2);
            float Z = luaL_checknumber(L, 3);
            sEluna->Push(L, unit->GetDistance(X, Y, Z));
        }
        return 1;
    }

    int GetCreatorGUID(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->GetCreatorGUID());
        return 1;
    }

    int GetMinionGUID(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->GetPetGUID());
        return 1;
    }

    int GetCharmerGUID(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->GetCharmerGUID());
        return 1;
    }

    int GetCharmGUID(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->GetCharmGUID());
        return 1;
    }

    int GetPetGUID(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->GetPetGUID());
        return 1;
    }

    int GetCritterGUID(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->GetCritterGUID());
        return 1;
    }

    int GetControllerGUID(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->GetCharmerOrOwnerGUID());
        return 1;
    }

    int GetControllerGUIDS(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->GetCharmerOrOwnerOrOwnGUID());
        return 1;
    }

    int GetStat(lua_State* L, Unit* unit)
    {
        uint32 stat = luaL_checkunsigned(L, 1);

        if (stat >= MAX_STATS)
            return 0;

        sEluna->Push(L, unit->GetStat((Stats)stat));
        return 1;
    }

    int GetBaseSpellPower(lua_State* L, Unit* unit)
    {
        uint32 spellschool = luaL_checkunsigned(L, 1);

        if (spellschool >= MAX_SPELL_SCHOOL)
            return 0;

        sEluna->Push(L, unit->GetUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_POS + spellschool));
        return 1;
    }

    int SetPvP(lua_State* L, Unit* unit)
    {
        bool apply = luaL_optbool(L, 1, true);

        unit->SetPvP(apply);
        return 0;
    }

    int SetFFA(lua_State* L, Unit* unit)
    {
        bool apply = luaL_optbool(L, 1, true);

        if (apply)
            unit->SetByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP);
        else
            unit->RemoveByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP);

        return 0;
    }

    int SetSanctuary(lua_State* L, Unit* unit)
    {
        bool apply = luaL_optbool(L, 1, true);

        if (apply)
        {
            unit->SetByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_SANCTUARY);
            unit->CombatStop();
            unit->CombatStopWithPets();
        }
        else
            unit->RemoveByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_SANCTUARY);

        return 0;
    }

    int IsAuctioneer(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->IsAuctioner());
        return 1;
    }

    int IsGuildMaster(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->IsGuildMaster());
        return 1;
    }

    int IsInnkeeper(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->IsInnkeeper());
        return 1;
    }

    int IsTrainer(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->IsTrainer());
        return 1;
    }

    int IsGossip(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->IsGossip());
        return 1;
    }

    int IsTaxi(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->IsTaxi());
        return 1;
    }

    int IsSpiritHealer(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->IsSpiritHealer());
        return 1;
    }

    int IsSpiritGuide(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->IsSpiritGuide());
        return 1;
    }

    int IsTabardDesigner(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->IsTabardDesigner());
        return 1;
    }

    int IsServiceProvider(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->IsServiceProvider());
        return 1;
    }

    int IsSpiritService(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->IsSpiritService());
        return 1;
    }

    int HealthBelowPct(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->HealthBelowPct(luaL_checkint(L, 1)));
        return 1;
    }

    int HealthAbovePct(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->HealthAbovePct(luaL_checkint(L, 1)));
        return 1;
    }

    int Emote(lua_State* L, Unit* unit)
    {
        unit->HandleEmoteCommand(luaL_checkunsigned(L, 1));
        return 0;
    }

    int CountPctFromCurHealth(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->CountPctFromCurHealth(luaL_checkint(L, 1)));
        return 1;
    }

    int CountPctFromMaxHealth(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->CountPctFromMaxHealth(luaL_checkint(L, 1)));
        return 1;
    }

    int SetSheath(lua_State* L, Unit* unit)
    {
        uint32 sheathed = luaL_checkunsigned(L, 1);
        if (sheathed >= MAX_SHEATH_STATE)
            return 0;
        
        unit->SetSheath((SheathState)sheathed);
        return 0;
    }

    int IsUnderWater(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->IsUnderWater());
        return 1;
    }

    int IsInWater(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->IsInWater());
        return 1;
    }

    int GetVictim(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->GetVictim());
        return 1;
    }

    int GetNearbyTarget(lua_State* L, Unit* unit)
    {
        float dist = luaL_optnumber(L, 1, 5.0f);
        Unit* exclude = sEluna->CHECK_UNIT(L, 2);

        sEluna->Push(L, unit->SelectNearbyTarget(exclude, dist));
        return 1;
    }

    int SendChatMessageToPlayer(lua_State* L, Unit* unit)
    {
        uint8 type = luaL_checkunsigned(L, 1);
        uint32 lang = luaL_checkunsigned(L, 2);
        const char* msg = luaL_checkstring(L, 3);
        Player* target = sEluna->CHECK_PLAYER(L, 4);
        if (!target || type == CHAT_MSG_CHANNEL)
            return 0;

        WorldPacket* data = new WorldPacket();
        uint32 messageLength = (uint32)strlen(msg) + 1;
        data->Initialize(SMSG_MESSAGECHAT, 100);
        *data << (uint8)type;
        *data << lang;
        *data << unit->GetGUIDLow();
        *data << uint32(0);
        *data << unit->GetGUIDLow();
        *data << messageLength;
        *data << msg;
        if (unit->ToPlayer() && type != CHAT_MSG_WHISPER_INFORM && type != CHAT_MSG_DND && type != CHAT_MSG_AFK)
            *data << uint8(unit->ToPlayer()->GetChatTag());
        else
            *data << uint8(0);
        target->GetSession()->SendPacket(data);
        return 0;
    }

    int GetCurrentSpell(lua_State* L, Unit* unit)
    {
        uint32 type = luaL_checkunsigned(L, 1);
        if (type >= CURRENT_MAX_SPELL)
        {
            luaL_error(L, "Invalid spell type (%d)", type);
            return 0;
        }
        sEluna->Push(L, unit->GetCurrentSpell(type));
        return 1;
    }

    int SummonGameObject(lua_State* L, Unit* unit)
    {
        uint32 entry = luaL_checkunsigned(L, 1);
        float x = luaL_checknumber(L, 2);
        float y = luaL_checknumber(L, 3);
        float z = luaL_checknumber(L, 4);
        float o = luaL_checknumber(L, 5);
        uint32 respawnDelay = luaL_optunsigned(L, 6, 30);
        sEluna->Push(L, unit->SummonGameObject(entry, x, y, z, o, 0, 0, 0, 0, respawnDelay));
        return 1;
    }

    int SpawnCreature(lua_State* L, Unit* unit)
    {
        uint32 entry = luaL_checkunsigned(L, 1);
        float x = luaL_checknumber(L, 2);
        float y = luaL_checknumber(L, 3);
        float z = luaL_checknumber(L, 4);
        float o = luaL_checknumber(L, 5);
        uint32 spawnType = luaL_optunsigned(L, 6, 0);
        uint32 despawnTimer = luaL_optunsigned(L, 7, 0);

        TempSummonType type;
        switch (spawnType)
        {
            case 1:
                type = TEMPSUMMON_TIMED_OR_DEAD_DESPAWN;
                break;
            case 2:
                type = TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN;
                break;
            case 3:
                type = TEMPSUMMON_TIMED_DESPAWN;
                break;
            case 5:
                type = TEMPSUMMON_CORPSE_DESPAWN;
                break;
            case 6:
                type = TEMPSUMMON_CORPSE_TIMED_DESPAWN;
                break;
            case 7:
                type = TEMPSUMMON_DEAD_DESPAWN;
                break;
            case 8:
                type = TEMPSUMMON_MANUAL_DESPAWN;
                break;
        }
        sEluna->Push(L, unit->SummonCreature(entry, x, y, z, o, type, despawnTimer));
        return 1;
    }

    int DealDamage(lua_State* L, Unit* unit)
    {
        Unit* target = sEluna->CHECK_UNIT(L, 1);
        uint32 amount = luaL_checkunsigned(L, 2);

        if (!target)
        unit->DealDamage(unit, amount);
        else
        unit->DealDamage(target, amount);
        return 0;
    }

    int GetStandState(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->getStandState());
        return 0;
    }

    int KnockbackFrom(lua_State* L, Unit* unit)
    {
        float x = luaL_checknumber(L, 1);
        float y = luaL_checknumber(L, 2);
        float speedXY = luaL_checknumber(L, 3);
        float speedZ = luaL_checknumber(L, 4);
        unit->KnockbackFrom(x, y, speedXY, speedZ);
        return 0;
    }

    int JumpTo(lua_State* L, Unit* unit)
    {
        WorldObject* obj = sEluna->CHECK_WORLDOBJECT(L, 1);
        float speedZ = luaL_checknumber(L, 2);
        if (!obj)
            return 0;

        unit->JumpTo(obj, speedZ);
        return 0;
    }

    int Jump(lua_State* L, Unit* unit)
    {
        float speedXY = luaL_checknumber(L, 1);
        float speedZ = luaL_checknumber(L, 2);
        bool forward = luaL_optbool(L, 3, true);
        unit->JumpTo(speedXY, speedZ, forward);
        return 0;
    }

    int JumpToCoords(lua_State* L, Unit* unit)
    {
        float x = luaL_checknumber(L, 1);
        float y = luaL_checknumber(L, 2);
        float z = luaL_checknumber(L, 3);
        float speedXY = luaL_checknumber(L, 4);
        float speedZ = luaL_checknumber(L, 5);
        unit->GetMotionMaster()->MoveJump(x, y, z, speedXY, speedZ);
        return 0;
    }

    int MoveCharge(lua_State* L, Unit* unit)
    {
        float x = luaL_checknumber(L, 1);
        float y = luaL_checknumber(L, 2);
        float z = luaL_checknumber(L, 3);
        float speed = luaL_checknumber(L, 4);
        unit->GetMotionMaster()->MoveCharge(x, y, z, speed);
        return 0;
    }

    int MoveChase(lua_State* L, Unit* unit)
    {
        Unit* target = sEluna->CHECK_UNIT(L, 1);
        float dist = luaL_optnumber(L, 2, 0.0f);
        float angle = luaL_optnumber(L, 3, 0.0f);
        unit->GetMotionMaster()->MoveChase(target, dist, angle);
        return 0;
    }

    int SetName(lua_State* L, Unit* unit)
    {
        const char* name = luaL_checkstring(L, 1);
        if (std::string(name).length() > 0)
            unit->SetName(name);
        return 0;
    }

    int SetStunned(lua_State* L, Unit* unit)
    {
        bool apply = luaL_optbool(L, 1, true);
        unit->SetControlled(apply, UNIT_STATE_STUNNED);
        return 0;
    }

    int SetRooted(lua_State* L, Unit* unit)
    {
        bool apply = luaL_optbool(L, 1, true);
        unit->SetControlled(apply, UNIT_STATE_ROOT);
        return 0;
    }

    int SetConfused(lua_State* L, Unit* unit)
    {
        bool apply = luaL_optbool(L, 1, true);
        unit->SetControlled(apply, UNIT_STATE_CONFUSED);
        return 0;
    }

    int SetFeared(lua_State* L, Unit* unit)
    {
        bool apply = luaL_optbool(L, 1, true);
        unit->SetControlled(apply, UNIT_STATE_FLEEING);
        return 0;
    }

    int MoveTo(lua_State* L, Unit* unit)
    {
        float id = luaL_checknumber(L, 1);
        float x = luaL_checknumber(L, 2);
        float y = luaL_checknumber(L, 3);
        float z = luaL_checknumber(L, 4);
        bool generatePath = luaL_optbool(L, 5, true);
        unit->GetMotionMaster()->MovePoint(id, x, y, z, generatePath);
        return 0;
    }

    int MoveFollow(lua_State* L, Unit* unit)
    {
        Unit* target = sEluna->CHECK_UNIT(L, 1);
        float dist = luaL_checknumber(L, 2);
        float angle = luaL_checknumber(L, 3);
        unit->GetMotionMaster()->MoveFollow(target, dist, angle);
        return 0;
    }

    int MoveClear(lua_State* L, Unit* unit)
    {
        unit->GetMotionMaster()->Clear();
        return 0;
    }

    int MoveRandom(lua_State* L, Unit* unit)
    {
        float radius = luaL_checknumber(L, 1);
        unit->GetMotionMaster()->MoveRandom(radius);
        return 0;
    }

    int MoveRotate(lua_State* L, Unit* unit)
    {
        uint32 time = luaL_checkunsigned(L, 1);
        bool left = luaL_optbool(L, 2, true);
        unit->GetMotionMaster()->MoveRotate(time, left ? ROTATE_DIRECTION_LEFT : ROTATE_DIRECTION_RIGHT);
        return 0;
    }

    int SetSpeed(lua_State* L, Unit* unit)
    {
        uint32 type = luaL_checkunsigned(L, 1);
        float rate = luaL_checknumber(L, 2);
        bool forced = luaL_optbool(L, 3, false);
        if (type >= MAX_MOVE_TYPE)
            luaL_error(L, "Invalid movement type (%d)", type);
        else
            unit->SetSpeed((UnitMoveType)type, rate, forced);
        return 0;
    }

    int GetDisplayId(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->GetDisplayId());
        return 1;
    }

    int GetNativeDisplayId(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->GetNativeDisplayId());
        return 1;
    }

    int GetLevel(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->getLevel());
        return 1;
    }

    int GetHealth(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->GetHealth());
        return 1;
    }

    int GetPower(lua_State* L, Unit* unit)
    {
        int type = luaL_optint(L, 1, -1);
        if (type == -1)
        {

            switch (unit->getClass())
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
            luaL_error(L, "Invalid power type (%d)", type);
            return 0;
        }

        sEluna->Push(L, unit->GetPower((Powers) type));
        return 1;
    }

    int GetMaxPower(lua_State* L, Unit* unit)
    {
        int type = luaL_optint(L, 1, -1);
        if (type == -1)
        {

            switch (unit->getClass())
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
        else if (type < 0 || type >= POWER_ALL)
        {
            luaL_error(L, "Invalid index (%d)", type);
            return 0;
        }

        sEluna->Push(L, unit->GetMaxPower((Powers) type));
        return 1;
    }

    int GetPowerType(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->getPowerType());
        return 1;
    }

    int GetMaxHealth(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->GetMaxHealth());
        return 1;
    }

    int GetHealthPct(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->GetHealthPct());
        return 1;
    }

    int GetPowerPct(lua_State* L, Unit* unit)
    {
        float percent = (unit->GetPower(unit->getPowerType()) / unit->GetMaxPower(unit->getPowerType())) * 100;
        sEluna->Push(L, percent);
        return 1;
    }

    int GetGender(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->getGender());
        return 1;
    }

    int GetRace(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->getRace());
        return 1;
    }

    int GetClass(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->getClass());
        return 1;
    }

    int GetCreatureType(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->GetCreatureType());
        return 1;
    }

    int GetClassAsString(lua_State* L, Unit* unit)
    {
        const char* str = NULL;
        switch (unit->getClass())
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
                str = "Death Knight";
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

        sEluna->Push(L, str);
        return 1;
    }

    int GetFaction(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->getFaction());
        return 1;
    }

    int SetFaction(lua_State* L, Unit* unit)
    {
        uint32 factionId = luaL_checkunsigned(L, 1);
        unit->setFaction(factionId);
        return 0;
    }

    int SetLevel(lua_State* L, Unit* unit)
    {
        uint32 newLevel = luaL_checkunsigned(L, 1);
        unit->SetLevel(newLevel);
        return 0;
    }

    int SetPhaseMask(lua_State* L, Unit* unit)
    {
        uint32 phaseMask = luaL_checkunsigned(L, 1);
        bool Update = luaL_optbool(L, 2, true);
        unit->SetPhaseMask(phaseMask, Update);
        return 0;
    }

    int SetHealth(lua_State* L, Unit* unit)
    {
        uint32 amt = luaL_checkunsigned(L, 1);
        unit->SetHealth(amt);
        return 0;
    }

    int SetMaxHealth(lua_State* L, Unit* unit)
    {
        uint32 amt = luaL_checkunsigned(L, 1);
        unit->SetMaxHealth(amt);
        return 0;
    }

    int SetPower(lua_State* L, Unit* unit)
    {
        int type = luaL_checkinteger(L, 1);
        uint32 amt = luaL_checkunsigned(L, 2);

        switch (type)
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
                luaL_error(L, "Invalid power type (%d)", type);
                break;
        }
        return 0;
    }

    int SetMaxPower(lua_State* L, Unit* unit)
    {
        int type = luaL_checkinteger(L, 1);
        int amt = luaL_checkunsigned(L, 2);

        switch (type)
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
                luaL_error(L, "Invalid power type (%d)", type);
                break;
        }
        return 0;
    }

    int SetDisplayId(lua_State* L, Unit* unit)
    {
        uint32 model = luaL_checkunsigned(L, 1);
        unit->SetDisplayId(model);
        return 0;
    }

    int SetNativeDisplayId(lua_State* L, Unit* unit)
    {
        uint32 model = luaL_checkunsigned(L, 1);
        unit->SetNativeDisplayId(model);
        return 0;
    }

    int SetFacing(lua_State* L, Unit* unit)
    {
        float o = luaL_checknumber(L, 1);
        unit->SetFacingTo(o);
        return 0;
    }

    int SetCreatorGUID(lua_State* L, Unit* unit)
    {
        uint64 guid = sEluna->CHECK_ULONG(L, 1);
        unit->SetCreatorGUID(guid);
        return 0;
    }

    int SetMinionGUID(lua_State* L, Unit* unit)
    {
        uint64 guid = sEluna->CHECK_ULONG(L, 1);
        unit->SetPetGUID(guid); // TC MinionGuid methods = same field as Mangos PetGuid
        return 0;
    }

    int SetCharmerGUID(lua_State* L, Unit* unit)
    {
        uint64 guid = sEluna->CHECK_ULONG(L, 1);
        unit->SetCharmerGUID(guid);
        return 0;
    }

    int SetPetGUID(lua_State* L, Unit* unit)
    {
        uint64 guid = sEluna->CHECK_ULONG(L, 1);
        unit->SetPetGUID(guid);
        return 0;
    }

    int SetCritterGUID(lua_State* L, Unit* unit)
    {
        uint64 guid = sEluna->CHECK_ULONG(L, 1);
        unit->SetCritterGUID(guid);
        return 0;
    }

    int SetWaterWalk(lua_State* L, Unit* unit)
    {
        bool enable = luaL_optbool(L, 1, true);

        unit->SetWaterWalking(enable);
        return 0;
    }

    int IsAlive(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->IsAlive());
        return 1;
    }

    int IsDead(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->isDead());
        return 1;
    }

    int IsDying(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->isDying());
        return 1;
    }

    int IsBanker(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->IsBanker());
        return 1;
    }

    int IsVendor(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->IsVendor());
        return 1;
    }

    int IsBattleMaster(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->IsBattleMaster());
        return 1;
    }

    int IsCharmed(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->IsCharmed());
        return 1;
    }

    int IsArmorer(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->IsArmorer());
        return 1;
    }

    int IsAttackingPlayer(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->isAttackingPlayer());
        return 1;
    }

    int IsInWorld(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->IsInWorld());
        return 1;
    }

    int IsPvPFlagged(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->IsPvP());
        return 1;
    }

    int IsInCombat(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->IsInCombat());
        return 1;
    }

    int SendUnitWhisper(lua_State* L, Unit* unit)
    {
        const char* msg = luaL_checkstring(L, 1);
        Unit* receiver = sEluna->CHECK_UNIT(L, 2);
        bool bossWhisper = luaL_optbool(L, 3, false);
        if (receiver && std::string(msg).length() > 0)
            unit->MonsterWhisper(msg, receiver->GetGUID(), bossWhisper);
        return 0;
    }

    int SendUnitEmote(lua_State* L, Unit* unit)
    {
        const char* msg = luaL_checkstring(L, 1);
        Unit* receiver = sEluna->CHECK_UNIT(L, 2);
        bool bossEmote = luaL_optbool(L, 3, false);
        if (std::string(msg).length() > 0)
            unit->MonsterTextEmote(msg, receiver ? receiver->GetGUID() : 0, bossEmote);
        return 0;
    }

    int SendUnitSay(lua_State* L, Unit* unit)
    {
        const char* msg = luaL_checkstring(L, 1);
        uint32 language = luaL_checknumber(L, 2);
        if (std::string(msg).length() > 0)
            unit->MonsterSay(msg, language, unit->GetGUID());
        return 0;
    }

    int SendUnitYell(lua_State* L, Unit* unit)
    {
        const char* msg = luaL_checkstring(L, 1);
        uint32 language = luaL_checknumber(L, 2);
        if (std::string(msg).length() > 0)
            unit->MonsterYell(msg, language, unit->GetGUID());
        return 0;
    }

    int DeMorph(lua_State* L, Unit* unit)
    {
        unit->DeMorph();
        return 0;
    }

    int CastSpell(lua_State* L, Unit* unit)
    {
        Object* obj = sEluna->CHECK_OBJECT(L, 1);
        if (!obj)
            return 0;
        uint32 spell = luaL_checkunsigned(L, 2);
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spell);
        if (!spellInfo)
            return 0;
        bool triggered = luaL_optbool(L, 3, true);

        SpellCastTargets targets;
        if (Unit* unitTarget = obj->ToUnit())
            targets.SetUnitTarget(unitTarget);
        else if (GameObject* goTarget = obj->ToGameObject())
            targets.SetGOTarget(goTarget);
        else if (obj->GetTypeId() == TYPEID_ITEM)
        {
            if (Item* itemTarget = (Item*)obj)
                targets.SetItemTarget(itemTarget);
        }
        else
            return 0;

        unit->CastSpell(targets, spellInfo, NULL, triggered ? TRIGGERED_FULL_MASK : TRIGGERED_NONE);
        return 0;
    }

    int CastSpellAoF(lua_State* L, Unit* unit)
    {
        float _x = luaL_checknumber(L, 1);
        float _y = luaL_checknumber(L, 2);
        float _z = luaL_checknumber(L, 3);
        uint32 spell = luaL_checkunsigned(L, 4);
        bool triggered = luaL_optbool(L, 5, true);
        unit->CastSpell(_x, _y, _z, spell, triggered);
        return 0;
    }

    int GetAura(lua_State* L, Unit* unit)
    {
        uint32 spellID = luaL_checkunsigned(L, 1);
        sEluna->Push(L, unit->GetAura(spellID));
        return 1;
    }

    int GetCombatTime(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->GetCombatTimer());
        return 1;
    }

    int ClearInCombat(lua_State* L, Unit* unit)
    {
        unit->ClearInCombat();
        return 0;
    }

    int StopSpellCast(lua_State* L, Unit* unit)
    {
        uint32 spellId = luaL_optunsigned(L, 1, 0);
        unit->CastStop(spellId);
        return 0;
    }

    int InterruptSpell(lua_State* L, Unit* unit)
    {
        int spellType = luaL_checkint(L, 1);
        bool delayed = luaL_optbool(L, 2, true);
        bool instant = luaL_optbool(L, 3, true);
        switch (spellType)
        {
            case 0:
                spellType = CURRENT_MELEE_SPELL;
                break;
            case 1:
                spellType = CURRENT_GENERIC_SPELL;
                break;
            case 2:
                spellType = CURRENT_CHANNELED_SPELL;
                break;
            case 3:
                spellType = CURRENT_AUTOREPEAT_SPELL;
                break;
        }
        unit->InterruptSpell((CurrentSpellTypes)spellType, delayed, instant);
        return 0;
    }

    int AddAura(lua_State* L, Unit* unit)
    {
        uint32 spellId = luaL_checkunsigned(L, 1);
        Unit* target = sEluna->CHECK_UNIT(L, 2);
        if (!target)
            return 0;
        sEluna->Push(L, unit->AddAura(spellId, target));
        return 1;
    }

    int RemoveAura(lua_State* L, Unit* unit)
    {
        uint32 spellId = luaL_checkunsigned(L, 1);
        unit->RemoveAurasDueToSpell(spellId);
        return 0;
    }

    int RemoveAllAuras(lua_State* L, Unit* unit)
    {
        unit->RemoveAllAuras();
        return 0;
    }

    int PlayDirectSound(lua_State* L, Unit* unit)
    {
        uint32 soundId = luaL_checkunsigned(L, 1);
        Player* player = sEluna->CHECK_PLAYER(L, 2);
        if (!sSoundEntriesStore.LookupEntry(soundId))
            return 0;

        if (player)
            unit->PlayDirectSound(soundId, player);
        else
            unit->PlayDirectSound(soundId);
        return 0;
    }

    int PlayDistanceSound(lua_State* L, Unit* unit)
    {
        uint32 soundId = luaL_checkunsigned(L, 1);
        Player* player = sEluna->CHECK_PLAYER(L, 2);
        if (!sSoundEntriesStore.LookupEntry(soundId))
            return 0;

        if (player)
            unit->PlayDistanceSound(soundId, player);
        else
            unit->PlayDistanceSound(soundId);
        return 0;
    }

    int Kill(lua_State* L, Unit* unit)
    {
        Unit* target = sEluna->CHECK_UNIT(L, 1);
        bool durLoss = luaL_optbool(L, 2, true);
        unit->Kill((target ? target : unit), durLoss);
        return 0;
    }

    int RegisterEvent(lua_State* L, Unit* unit)
    {
        luaL_checktype(L, 1, LUA_TFUNCTION);
        uint32 delay = luaL_checkunsigned(L, 2);
        uint32 repeats = luaL_checkunsigned(L, 3);

        lua_settop(L, 1);
        int functionRef = lua_ref(L, true);
        sEluna->Push(L, sEluna->EventMgr.AddEvent(&unit->m_Events, functionRef, delay, repeats, unit));
        return 1;
    }

    int RemoveEventById(lua_State* L, Unit* unit)
    {
        int eventId = luaL_checkinteger(L, 1);
        sEluna->EventMgr.RemoveEvent(&unit->m_Events, eventId);
        return 0;
    }

    int RemoveEvents(lua_State* L, Unit* unit)
    {
        sEluna->EventMgr.RemoveEvents(&unit->m_Events);
        return 0;
    }

    /* Vehicle */

    int IsOnVehicle(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->GetVehicle() || (unit->GetTypeId() == TYPEID_PLAYER && unit->IsVehicle()));
        return 1;
    }

    int DismissVehicle(lua_State* L, Unit* unit)
    {
        if (Creature* vehicle = unit->GetVehicleCreatureBase())
        vehicle->DespawnOrUnsummon();
        return 0;
    }

    int AddVehiclePassenger(lua_State* L, Unit* unit)
    {
        Unit* passenger = sEluna->CHECK_UNIT(L, 1);
        int8 seatId = luaL_checkunsigned(L, 2);
        Vehicle* _vehicle = unit->GetVehicle();
        if (!_vehicle)
            return 0;

        _vehicle->AddPassenger(passenger, seatId);
        return 0;
    }

    // Not coded in core (TC)
    /*int EjectPassenger(lua_State* L, Unit* unit)
    {
        Unit* passenger = sEluna->CHECK_UNIT(L, 1);
        Vehicle* _vehicle = unit->GetVehicle();
        if (!_vehicle)
            return 0;

        _vehicle->EjectPassenger(passenger, unit);
        return 0;
    }*/

    int RemovePassenger(lua_State* L, Unit* unit)
    {
        Unit* passenger = sEluna->CHECK_UNIT(L, 1);
        Vehicle* _vehicle = unit->GetVehicle();
        if (!_vehicle)
            return 0;

        _vehicle->RemovePassenger(passenger);
        return 0;
    }

    int RemoveAllPassengers(lua_State* L, Unit* unit)
    {
        Unit* _unit = unit->GetVehicleBase();
        if (!_unit)
            return 0;

        _unit->GetVehicle()->RemoveAllPassengers();
        return 0;
    }

    int GetPassenger(lua_State* L, Unit* unit)
    {
        int8 seatId = luaL_checkunsigned(L, 1);
        Unit* _unit = unit->GetVehicleBase();
        if (!_unit)
            return 0;

        sEluna->Push(L, _unit->GetVehicle()->GetPassenger(seatId));
        return 1;
    }

    /*int GetNextEmptySeat(lua_State* L, Unit* unit)
    {
        int8 seatId = luaL_checkunsigned(L, 1);
        Unit* _unit = unit->GetVehicleBase();
        if (!_unit)
            return 0;

        return 0;
    }*/

    int GetAvailableSeats(lua_State* L, Unit* unit)
    {
        Unit* _unit = unit->GetVehicleBase();
        if (!_unit)
            return 0;

        sEluna->Push(L, _unit->GetVehicle()->GetAvailableSeatCount());
        return 1;
    }

    int GetVehicleBase(lua_State* L, Unit* unit)
    {
        Unit* _unit = unit->GetVehicleBase();
        if (_unit)
            sEluna->Push(L, _unit);
        else
            lua_pushnil(L);
        return 1;
    }

    int HasEmptySeat(lua_State* L, Unit* unit)
    {
        int8 seatId = luaL_checkunsigned(L, 1);
        Unit* _unit = unit->GetVehicleBase();
        if (!_unit)
            return 0;

        sEluna->Push(L, _unit->GetVehicle()->HasEmptySeat(seatId));
        return 1;
    }

    int GetFriendlyUnitsInRange(lua_State* L, Unit* unit)
    {
        float range = luaL_optnumber(L, 1, SIZE_OF_GRIDS);

        UnitList list;
        Trinity::AnyFriendlyUnitInObjectRangeCheck checker(unit, unit, range);
        Trinity::UnitListSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> searcher(unit, list, checker);
        unit->VisitNearbyObject(range, searcher);
        Eluna::ObjectGUIDCheck guidCheck(unit->GetGUID());
        list.remove_if (guidCheck);

        lua_newtable(L);
        int tbl = lua_gettop(L);
        uint32 i = 0;

        for (UnitList::const_iterator it = list.begin(); it != list.end(); ++it)
        {
            sEluna->Push(L, ++i);
            sEluna->Push(L, *it);
            lua_settable(L, tbl);
        }

        lua_settop(L, tbl);
        return 1;
    }

    int GetUnfriendlyUnitsInRange(lua_State* L, Unit* unit)
    {
        float range = luaL_optnumber(L, 1, SIZE_OF_GRIDS);

        UnitList list;
        Trinity::AnyUnfriendlyUnitInObjectRangeCheck checker(unit, unit, range);
        Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> searcher(unit, list, checker);
        unit->VisitNearbyObject(range, searcher);
        Eluna::ObjectGUIDCheck guidCheck(unit->GetGUID());
        list.remove_if (guidCheck);

        lua_newtable(L);
        int tbl = lua_gettop(L);
        uint32 i = 0;

        for (UnitList::const_iterator it = list.begin(); it != list.end(); ++it)
        {
            sEluna->Push(L, ++i);
            sEluna->Push(L, *it);
            lua_settable(L, tbl);
        }

        lua_settop(L, tbl);
        return 1;
    }

    int AttackStop(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->AttackStop());
        return 1;
    }

    int SetCanFly(lua_State* L, Unit* unit)
    {
        bool apply = luaL_optbool(L, 1, true);
        unit->SetCanFly(apply);
        return 0;
    }

    int SetVisible(lua_State* L, Unit* unit)
    {
        bool x = luaL_optbool(L, 1, true);
        unit->SetVisible(x);
        return 0;
    }

    int IsVisible(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->IsVisible());
        return 1;
    }

    int IsMoving(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->isMoving());
        return 1;
    }

    int IsFlying(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->IsFlying());
        return 1;
    }

    int IsStopped(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->IsStopped());
        return 1;
    }

    int IsQuestGiver(lua_State* L, Unit* unit)
    {
        sEluna->Push(L, unit->IsQuestGiver());
        return 1;
    }

    int RestoreDisplayId(lua_State* L, Unit* unit)
    {
        unit->RestoreDisplayId();
        return 0;
    }

    int RestoreFaction(lua_State* L, Unit* unit)
    {
        unit->RestoreFaction();
        return 0;
    }

    int RemoveBindSightAuras(lua_State* L, Unit* unit)
    {
        unit->RemoveBindSightAuras();
        return 0;
    }

    int RemoveCharmAuras(lua_State* L, Unit* unit)
    {
        unit->RemoveCharmAuras();
        return 0;
    }

    int StopMoving(lua_State* L, Unit* unit)
    {
        unit->StopMoving();
        return 0;
    }

    int AddUnitState(lua_State* L, Unit* unit)
    {
        uint32 state = luaL_checkunsigned(L, 1);

        unit->AddUnitState(state);
        return 0;
    }

    int ClearUnitState(lua_State* L, Unit* unit)
    {
        uint32 state = luaL_checkunsigned(L, 1);

        unit->ClearUnitState(state);
        return 0;
    }

    int HasUnitState(lua_State* L, Unit* unit)
    {
        uint32 state = luaL_checkunsigned(L, 1);

        sEluna->Push(L, unit->HasUnitState(state));
        return 1;
    }

    int DisableMelee(lua_State* L, Unit* unit)
    {
        bool apply = luaL_optbool(L, 1, true);

        if (apply)
            unit->AddUnitState(UNIT_STATE_CANNOT_AUTOATTACK);
        else
            unit->ClearUnitState(UNIT_STATE_CANNOT_AUTOATTACK);
        return 0;
    }

    int SummonGuardian(lua_State* L, Unit* unit)
    {
        uint32 entry = luaL_checkunsigned(L, 1);
        float x = luaL_checknumber(L, 2);
        float y = luaL_checknumber(L, 3);
        float z = luaL_checknumber(L, 4);
        float o = luaL_checknumber(L, 5);
        uint32 desp = luaL_optunsigned(L, 6, 0);

        SummonPropertiesEntry const* properties = sSummonPropertiesStore.LookupEntry(61);
        if (!properties)
            return 0;
        Position pos;
        pos.Relocate(x,y,z,o);
        TempSummon* summon = unit->GetMap()->SummonCreature(entry, pos, properties, desp, unit);

        if (!summon)
            return 0;
        if (summon->HasUnitTypeMask(UNIT_MASK_GUARDIAN))
            ((Guardian*)summon)->InitStatsForLevel(unit->getLevel());
        if (properties && properties->Category == SUMMON_CATEGORY_ALLY)
            summon->setFaction(unit->getFaction());
        if (summon->GetEntry() == 27893)
        {
            if (uint32 weapon = unit->GetUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID))
            {
                summon->SetDisplayId(11686);
                summon->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, weapon);
            }
            else
                summon->SetDisplayId(1126);
        }
        summon->AI()->EnterEvadeMode();

        sEluna->Push(L, summon);
        return 1;
    }
};
#endif
