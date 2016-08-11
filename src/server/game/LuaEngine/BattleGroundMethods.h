/*
* Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef BATTLEGROUNDMETHODS_H
#define BATTLEGROUNDMETHODS_H

/***
 * Contains the state of a battleground, e.g. Warsong Gulch, Arathi Basin, etc.
 *
 * Inherits all methods from: none
 */
namespace LuaBattleGround
{
    /**
     * Returns the name of the [BattleGround].
     *
     * @return string name
     */
    int GetName(Eluna* /*E*/, lua_State* L, BattleGround* bg)
    {
        Eluna::Push(L, bg->GetName());
        return 1;
    }

    /**
     * Returns the amount of alive players in the [BattleGround] by the team ID.
     *
     * @param [Team] team : team ID
     * @return uint32 count
     */
    int GetAlivePlayersCountByTeam(Eluna* /*E*/, lua_State* L, BattleGround* bg)
    {
        uint32 team = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, bg->GetAlivePlayersCountByTeam((Team)team));
        return 1;
    }

    /**
     * Returns the [Map] of the [BattleGround].
     *
     * @return [Map] map
     */
    int GetMap(Eluna* /*E*/, lua_State* L, BattleGround* bg)
    {
        Eluna::Push(L, bg->GetBgMap());
        return 1;
    }

    /**
     * Returns the bonus honor given by amount of kills in the specific [BattleGround].
     *
     * @param uint32 kills : amount of kills
     * @return uint32 bonusHonor
     */
    int GetBonusHonorFromKillCount(Eluna* /*E*/, lua_State* L, BattleGround* bg)
    {
        uint32 kills = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, bg->GetBonusHonorFromKill(kills));
        return 1;
    }

    /**
     * Returns the bracket ID of the specific [BattleGround].
     *
     * @return [BattleGroundBracketId] bracketId
     */
    int GetBracketId(Eluna* /*E*/, lua_State* L, BattleGround* bg)
    {
        Eluna::Push(L, bg->GetBracketId());
        return 1;
    }

    /**
     * Returns the end time of the [BattleGround].
     *
     * @return uint32 endTime
     */
    int GetEndTime(Eluna* /*E*/, lua_State* L, BattleGround* bg)
    {
#ifdef CATA
        Eluna::Push(L, bg->GetRemainingTime());
#else
        Eluna::Push(L, bg->GetEndTime());
#endif
        return 1;
    }

    /**
     * Returns the amount of free slots for the selected team in the specific [BattleGround].
     *
     * @param [Team] team : team ID
     * @return uint32 freeSlots
     */
    int GetFreeSlotsForTeam(Eluna* /*E*/, lua_State* L, BattleGround* bg)
    {
        uint32 team = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, bg->GetFreeSlotsForTeam((Team)team));
        return 1;
    }

    /**
     * Returns the instance ID of the [BattleGround].
     *
     * @return uint32 instanceId
     */
    int GetInstanceId(Eluna* /*E*/, lua_State* L, BattleGround* bg)
    {
        Eluna::Push(L, bg->GetInstanceID());
        return 1;
    }

    /**
     * Returns the map ID of the [BattleGround].
     *
     * @return uint32 mapId
     */
    int GetMapId(Eluna* /*E*/, lua_State* L, BattleGround* bg)
    {
        Eluna::Push(L, bg->GetMapId());
        return 1;
    }

    /**
     * Returns the type ID of the [BattleGround].
     *
     * @return [BattleGroundTypeId] typeId
     */
    int GetTypeId(Eluna* /*E*/, lua_State* L, BattleGround* bg)
    {
        Eluna::Push(L, bg->GetTypeID());
        return 1;
    }

    /**
     * Returns the max allowed [Player] level of the specific [BattleGround].
     *
     * @return uint32 maxLevel
     */
    int GetMaxLevel(Eluna* /*E*/, lua_State* L, BattleGround* bg)
    {
        Eluna::Push(L, bg->GetMaxLevel());
        return 1;
    }

    /**
     * Returns the minimum allowed [Player] level of the specific [BattleGround].
     *
     * @return uint32 minLevel
     */
    int GetMinLevel(Eluna* /*E*/, lua_State* L, BattleGround* bg)
    {
        Eluna::Push(L, bg->GetMinLevel());
        return 1;
    }

    /**
     * Returns the maximum allowed [Player] count of the specific [BattleGround].
     *
     * @return uint32 maxPlayerCount
     */
    int GetMaxPlayers(Eluna* /*E*/, lua_State* L, BattleGround* bg)
    {
        Eluna::Push(L, bg->GetMaxPlayers());
        return 1;
    }

    /**
     * Returns the minimum allowed [Player] count of the specific [BattleGround].
     *
     * @return uint32 minPlayerCount
     */
    int GetMinPlayers(Eluna* /*E*/, lua_State* L, BattleGround* bg)
    {
        Eluna::Push(L, bg->GetMinPlayers());
        return 1;
    }

    /**
     * Returns the maximum allowed [Player] count per team of the specific [BattleGround].
     *
     * @return uint32 maxTeamPlayerCount
     */
    int GetMaxPlayersPerTeam(Eluna* /*E*/, lua_State* L, BattleGround* bg)
    {
        Eluna::Push(L, bg->GetMaxPlayersPerTeam());
        return 1;
    }

    /**
     * Returns the minimum allowed [Player] count per team of the specific [BattleGround].
     *
     * @return uint32 minTeamPlayerCount
     */
    int GetMinPlayersPerTeam(Eluna* /*E*/, lua_State* L, BattleGround* bg)
    {
        Eluna::Push(L, bg->GetMinPlayersPerTeam());
        return 1;
    }

    /**
     * Returns the winning team of the specific [BattleGround].
     *
     * @return [Team] team
     */
    int GetWinner(Eluna* /*E*/, lua_State* L, BattleGround* bg)
    {
        Eluna::Push(L, bg->GetWinner());
        return 1;
    }

    /**
     * Returns the status of the specific [BattleGround].
     *
     * @return [BattleGroundStatus] status
     */
    int GetStatus(Eluna* /*E*/, lua_State* L, BattleGround* bg)
    {
        Eluna::Push(L, bg->GetStatus());
        return 1;
    }
};
#endif