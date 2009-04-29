/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "Object.h"
#include "Player.h"
#include "BattleGround.h"
#include "BattleGroundNA.h"
#include "ObjectMgr.h"
#include "WorldPacket.h"
#include "Language.h"

BattleGroundNA::BattleGroundNA()
{
    m_BgObjects.resize(BG_NA_OBJECT_MAX);

    m_StartDelayTimes[BG_STARTING_EVENT_FIRST]  = BG_START_DELAY_1M;
    m_StartDelayTimes[BG_STARTING_EVENT_SECOND] = BG_START_DELAY_30S;
    m_StartDelayTimes[BG_STARTING_EVENT_THIRD]  = BG_START_DELAY_15S;
    m_StartDelayTimes[BG_STARTING_EVENT_FOURTH] = BG_START_DELAY_NONE;
    //we must set messageIds
    m_StartMessageIds[BG_STARTING_EVENT_FIRST]  = LANG_ARENA_ONE_MINUTE;
    m_StartMessageIds[BG_STARTING_EVENT_SECOND] = LANG_ARENA_THIRTY_SECONDS;
    m_StartMessageIds[BG_STARTING_EVENT_THIRD]  = LANG_ARENA_FIFTEEN_SECONDS;
    m_StartMessageIds[BG_STARTING_EVENT_FOURTH] = LANG_ARENA_HAS_BEGUN;
}

BattleGroundNA::~BattleGroundNA()
{

}

void BattleGroundNA::Update(uint32 diff)
{
    BattleGround::Update(diff);

    /*if (GetStatus() == STATUS_IN_PROGRESS)
    {
        // update something
    }*/
}

void BattleGroundNA::StartingEventCloseDoors()
{
    for(uint32 i = BG_NA_OBJECT_DOOR_1; i <= BG_NA_OBJECT_DOOR_4; ++i)
        SpawnBGObject(i, RESPAWN_IMMEDIATELY);
}

void BattleGroundNA::StartingEventOpenDoors()
{
    for(uint32 i = BG_NA_OBJECT_DOOR_1; i <= BG_NA_OBJECT_DOOR_2; ++i)
        DoorOpen(i);

    for(uint32 i = BG_NA_OBJECT_BUFF_1; i <= BG_NA_OBJECT_BUFF_2; ++i)
        SpawnBGObject(i, 60);
}

void BattleGroundNA::AddPlayer(Player *plr)
{
    BattleGround::AddPlayer(plr);
    //create score and add it to map, default values are set in constructor
    BattleGroundNAScore* sc = new BattleGroundNAScore;

    m_PlayerScores[plr->GetGUID()] = sc;

    UpdateWorldState(0xa0f, GetAlivePlayersCountByTeam(ALLIANCE));
    UpdateWorldState(0xa10, GetAlivePlayersCountByTeam(HORDE));
}

void BattleGroundNA::RemovePlayer(Player* /*plr*/, uint64 /*guid*/)
{
    if (GetStatus() == STATUS_WAIT_LEAVE)
        return;

    UpdateWorldState(0xa0f, GetAlivePlayersCountByTeam(ALLIANCE));
    UpdateWorldState(0xa10, GetAlivePlayersCountByTeam(HORDE));

    CheckArenaWinConditions();
}

void BattleGroundNA::HandleKillPlayer(Player *player, Player *killer)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    if (!killer)
    {
        sLog.outError("BattleGroundNA: Killer player not found");
        return;
    }

    BattleGround::HandleKillPlayer(player,killer);

    UpdateWorldState(0xa0f, GetAlivePlayersCountByTeam(ALLIANCE));
    UpdateWorldState(0xa10, GetAlivePlayersCountByTeam(HORDE));

    CheckArenaWinConditions();
}

bool BattleGroundNA::HandlePlayerUnderMap(Player *player)
{
    player->TeleportTo(GetMapId(),4055.504395,2919.660645,13.611241,player->GetOrientation(),false);
    return true;
}

void BattleGroundNA::HandleAreaTrigger(Player *Source, uint32 Trigger)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    //uint32 SpellId = 0;
    //uint64 buff_guid = 0;
    switch(Trigger)
    {
        case 4536:                                          // buff trigger?
        case 4537:                                          // buff trigger?
            break;
        default:
            sLog.outError("WARNING: Unhandled AreaTrigger in Battleground: %u", Trigger);
            Source->GetSession()->SendAreaTriggerMessage("Warning: Unhandled AreaTrigger in Battleground: %u", Trigger);
            break;
    }

    //if (buff_guid)
    //    HandleTriggerBuff(buff_guid,Source);
}

void BattleGroundNA::FillInitialWorldStates(WorldPacket &data)
{
    data << uint32(0xa0f) << uint32(GetAlivePlayersCountByTeam(ALLIANCE));           // 7
    data << uint32(0xa10) << uint32(GetAlivePlayersCountByTeam(HORDE));           // 8
    data << uint32(0xa11) << uint32(1);           // 9
}

void BattleGroundNA::Reset()
{
    //call parent's class reset
    BattleGround::Reset();
}

bool BattleGroundNA::SetupBattleGround()
{
    // gates
    if (!AddObject(BG_NA_OBJECT_DOOR_1, BG_NA_OBJECT_TYPE_DOOR_1, 4031.854, 2966.833, 12.6462, -2.648788, 0, 0, 0.9697962, -0.2439165, RESPAWN_IMMEDIATELY)
        || !AddObject(BG_NA_OBJECT_DOOR_2, BG_NA_OBJECT_TYPE_DOOR_2, 4081.179, 2874.97, 12.39171, 0.4928045, 0, 0, 0.2439165, 0.9697962, RESPAWN_IMMEDIATELY)
        || !AddObject(BG_NA_OBJECT_DOOR_3, BG_NA_OBJECT_TYPE_DOOR_3, 4023.709, 2981.777, 10.70117, -2.648788, 0, 0, 0.9697962, -0.2439165, RESPAWN_IMMEDIATELY)
        || !AddObject(BG_NA_OBJECT_DOOR_4, BG_NA_OBJECT_TYPE_DOOR_4, 4090.064, 2858.438, 10.23631, 0.4928045, 0, 0, 0.2439165, 0.9697962, RESPAWN_IMMEDIATELY)
    // buffs
        || !AddObject(BG_NA_OBJECT_BUFF_1, BG_NA_OBJECT_TYPE_BUFF_1, 4009.189941, 2895.250000, 13.052700, -1.448624, 0, 0, 0.6626201, -0.7489557, 120)
        || !AddObject(BG_NA_OBJECT_BUFF_2, BG_NA_OBJECT_TYPE_BUFF_2, 4103.330078, 2946.350098, 13.051300, -0.06981307, 0, 0, 0.03489945, -0.9993908, 120))
    {
        sLog.outErrorDb("BatteGroundNA: Failed to spawn some object!");
        return false;
    }

    return true;
}

/*
20:12:14 id:036668 [S2C] SMSG_INIT_WORLD_STATES (706 = 0x02C2) len: 86
0000: 2f 02 00 00 72 0e 00 00 00 00 00 00 09 00 11 0a  |  /...r...........
0010: 00 00 01 00 00 00 0f 0a 00 00 00 00 00 00 10 0a  |  ................
0020: 00 00 00 00 00 00 d4 08 00 00 00 00 00 00 d8 08  |  ................
0030: 00 00 00 00 00 00 d7 08 00 00 00 00 00 00 d6 08  |  ................
0040: 00 00 00 00 00 00 d5 08 00 00 00 00 00 00 d3 08  |  ................
0050: 00 00 00 00 00 00                                |  ......
*/

