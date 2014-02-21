/*
* Copyright (C) 2010 - 2014 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information
*/

#ifndef TBC
#ifndef VEHICLEMETHODS_H
#define VEHICLEMETHODS_H

namespace LuaVehicle
{
    int GetOwner(lua_State* L, Vehicle* vehicle)
    {
#ifdef MANGOS
        sEluna->Push(L, vehicle->GetOwner());
#else
        sEluna->Push(L, vehicle->GetBase());
#endif
        return 1;
    }

    int GetEntry(lua_State* L, Vehicle* vehicle)
    {
#ifdef MANGOS
        sEluna->Push(L, vehicle->GetVehicleEntry()->m_ID);
#else
        sEluna->Push(L, vehicle->GetVehicleInfo()->m_ID);
#endif
        return 1;
    }

    int GetPassenger(lua_State* L, Vehicle* vehicle)
    {
        int8 seatId = sEluna->CHECKVAL<int8>(L, 2);
        sEluna->Push(L, vehicle->GetPassenger(seatId));
        return 1;
    }

    int AddPassenger(lua_State* L, Vehicle* vehicle)
    {
        Unit* passenger = sEluna->CHECKOBJ<Unit>(L, 2);
        int8 seatId = sEluna->CHECKVAL<int8>(L, 3);
#ifdef MANGOS
        if (vehicle->CanBoard(passenger))
            vehicle->Board(passenger, seatId);
#else
        vehicle->AddPassenger(passenger, seatId);
#endif
        return 0;
    }

    int RemovePassenger(lua_State* L, Vehicle* vehicle)
    {
        Unit* passenger = sEluna->CHECKOBJ<Unit>(L, 2);
#ifdef MANGOS
        vehicle->UnBoard(passenger, false);
#else
        vehicle->RemovePassenger(passenger);
#endif
        return 0;
    }

    int IsOnBoard(lua_State* L, Vehicle* vehicle)
    {
        Unit* passenger = sEluna->CHECKOBJ<Unit>(L, 2);
#ifdef MANGOS
        sEluna->Push(L, vehicle->HasOnBoard(passenger));
#else
        sEluna->Push(L, passenger->IsOnVehicle(vehicle->GetBase()));
#endif
        return 1;
    }
}

#endif
#endif