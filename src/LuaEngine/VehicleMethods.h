/*
* Copyright (C) 2010 - 2014 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information
*/

#ifndef VEHICLEMETHODS_H
#define VEHICLEMETHODS_H

namespace LuaVehicle
{
    int GetBase(lua_State* L, Vehicle* vehicle)
    {
        sEluna->Push(L, vehicle->GetBase());
        return 1;
    }

    int GetAvailableSeatCount(lua_State* L, Vehicle* vehicle)
    {
        sEluna->Push(L, vehicle->GetAvailableSeatCount());
        return 1;
    }

    int GetCreatureEntry(lua_State* L, Vehicle* vehicle)
    {
        sEluna->Push(L, vehicle->GetCreatureEntry());
        return 1;
    }

    int GetPassenger(lua_State* L, Vehicle* vehicle)
    {
        int8 seatId = luaL_checkinteger(L, 1);
        sEluna->Push(L, vehicle->GetPassenger(seatId));
        return 1;
    }

    int HasEmptySeat(lua_State* L, Vehicle* vehicle)
    {
        int8 seatId = luaL_checkinteger(L, 1);
        sEluna->Push(L, vehicle->HasEmptySeat(seatId));
        return 1;
    }

    int IsVehicleInUse(lua_State* L, Vehicle* vehicle)
    {
        sEluna->Push(L, vehicle->IsVehicleInUse());
        return 1;
    }

    int InstallAccessory(lua_State* L, Vehicle* vehicle)
    {
        uint32 entry = luaL_checkunsigned(L, 1);
        int8 seatId = luaL_checkinteger(L, 2);
        bool minion = luaL_checkbool(L, 3);
        uint8 typeId = luaL_checkunsigned(L, 4);
        uint32 summonTime = luaL_checkunsigned(L, 5);
        vehicle->InstallAccessory(entry, seatId, minion, typeId, summonTime);
        return 0;
    }

    int ApplyAllImmunities(lua_State* L, Vehicle* vehicle)
    {
        vehicle->ApplyAllImmunities();
        return 0;
    }

    int AddPassenger(lua_State* L, Vehicle* vehicle)
    {
        Unit* passenger = sEluna->CHECK_UNIT(L, 1);
        if (!passenger)
            return 0;

        int8 seatId = luaL_checkinteger(L, 2);

        vehicle->AddPassenger(passenger, seatId);
        return 0;
    }

    int EjectPassenger(lua_State* L, Vehicle* vehicle)
    {
        Unit* passenger = sEluna->CHECK_UNIT(L, 1);
        Unit* controller = sEluna->CHECK_UNIT(L, 2);
        if (!passenger || controller)
            return 0;

        //vehicle->EjectPassenger(passenger, controller);
        return 0;
    }

    int RelocatePassengers(lua_State* L, Vehicle* vehicle)
    {
        vehicle->RelocatePassengers();
        return 0;
    }

    int RemoveAllPassengers(lua_State* L, Vehicle* vehicle)
    {
        vehicle->RemoveAllPassengers();
        return 0;
    }

    int RemovePassenger(lua_State* L, Vehicle* vehicle)
    {
        Unit* passenger = sEluna->CHECK_UNIT(L, 1);
        if (!passenger)
            return 0;

        vehicle->RemovePassenger(passenger);
        return 0;
    }

    int RemovePendingEventsForPassenger(lua_State* L, Vehicle* vehicle)
    {
        Unit* passenger = sEluna->CHECK_UNIT(L, 1);
        if (!passenger)
            return 0;

        vehicle->RemovePendingEventsForPassenger(passenger);
        return 0;
    }

    int Reset(lua_State* L, Vehicle* vehicle)
    {
        bool evading = luaL_optbool(L, 1, false);
        vehicle->Reset(evading);
        return 0;
    }
}

#endif