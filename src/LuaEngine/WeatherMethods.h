/* 
* Copyright (C) 2010 - 2013 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information 
*/
#ifndef WEATHERMETHODS_H
#define WEATHERMETHODS_H

class LuaWeather
{
public:

    static int GetScriptId(lua_State* L, Weather* weather)
    {
        if (!weather)
            return 0;

        sEluna->PushUnsigned(L, weather->GetScriptId());
        return 1;
    }

    static int GetZoneId(lua_State* L, Weather* weather)
    {
        if (!weather)
            return 0;

        sEluna->PushUnsigned(L, weather->GetZone());
        return 1;
    }

    static int SetWeather(lua_State* L, Weather* weather)
    {
        if (!weather)
            return 0;

        uint32 weatherType = luaL_checkunsigned(L, 1);
        float grade = luaL_checknumber(L, 2);

        weather->SetWeather((WeatherType)weatherType, grade);
        return 0;
    }

    static int SendWeatherUpdateToPlayer(lua_State* L, Weather* weather)
    {
        if (!weather)
            return 0;

        Player* player = sEluna->CHECK_PLAYER(L, 1);
        if (!player)
            return 0;

        weather->SendWeatherUpdateToPlayer(player);
        return 0;
    }

    static int Regenerate(lua_State* L, Weather* weather)
    {
        if (!weather)
            return 0;

        sEluna->PushBoolean(L, weather->ReGenerate());
        return 1;
    }

    static int UpdateWeather(lua_State* L, Weather* weather)
    {
        if (!weather)
            return 0;

        sEluna->PushBoolean(L, weather->UpdateWeather());
        return 1;
    }
};

#endif