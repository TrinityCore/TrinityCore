/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
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
#include "BattleGroundRL.h"
#include "Creature.h"
#include "ObjectMgr.h"
#include "MapManager.h"
#include "Language.h"

BattleGroundRL::BattleGroundRL()
{
    m_BgObjects.resize(BG_RL_OBJECT_MAX);
}

BattleGroundRL::~BattleGroundRL()
{

}

void BattleGroundRL::Update(time_t diff)
{
    BattleGround::Update(diff);

    if (GetStatus() == STATUS_WAIT_JOIN && GetPlayersSize())
    {
        ModifyStartDelayTime(diff);

        if (!(m_Events & 0x01))
        {
            m_Events |= 0x01;

            // setup here, only when at least one player has ported to the map
            if(!SetupBattleGround())
            {
                EndNow();
                return;
            }

            for(uint32 i = BG_RL_OBJECT_DOOR_1; i <= BG_RL_OBJECT_DOOR_2; i++)
                SpawnBGObject(i, RESPAWN_IMMEDIATELY);

            SetStartDelayTime(START_DELAY1);
            SendMessageToAll(LANG_ARENA_ONE_MINUTE);
        }
        // After 30 seconds, warning is signalled
        else if (GetStartDelayTime() <= START_DELAY2 && !(m_Events & 0x04))
        {
            m_Events |= 0x04;
            SendMessageToAll(LANG_ARENA_THIRTY_SECONDS);
        }
        // After 15 seconds, warning is signalled
        else if (GetStartDelayTime() <= START_DELAY3 && !(m_Events & 0x08))
        {
            m_Events |= 0x08;
            SendMessageToAll(LANG_ARENA_FIFTEEN_SECONDS);
        }
        // delay expired (1 minute)
        else if (GetStartDelayTime() <= 0 && !(m_Events & 0x10))
        {
            m_Events |= 0x10;

            for(uint32 i = BG_RL_OBJECT_DOOR_1; i <= BG_RL_OBJECT_DOOR_2; i++)
                DoorOpen(i);

            for(uint32 i = BG_RL_OBJECT_BUFF_1; i <= BG_RL_OBJECT_BUFF_2; i++)
                SpawnBGObject(i, 60);

            SendMessageToAll(LANG_ARENA_BEGUN);
            SetStatus(STATUS_IN_PROGRESS);
            SetStartDelayTime(0);

            for(BattleGroundPlayerMap::const_iterator itr = GetPlayers().begin(); itr != GetPlayers().end(); ++itr)
                if(Player *plr = objmgr.GetPlayer(itr->first))
                    plr->RemoveAurasDueToSpell(SPELL_ARENA_PREPARATION);

            if(!GetPlayersCountByTeam(ALLIANCE) && GetPlayersCountByTeam(HORDE))
                EndBattleGround(HORDE);
            else if(GetPlayersCountByTeam(ALLIANCE) && !GetPlayersCountByTeam(HORDE))
                EndBattleGround(ALLIANCE);
        }
    }

    /*if(GetStatus() == STATUS_IN_PROGRESS)
    {
        // update something
    }*/
}

void BattleGroundRL::AddPlayer(Player *plr)
{
    BattleGround::AddPlayer(plr);
    //create score and add it to map, default values are set in constructor
    BattleGroundRLScore* sc = new BattleGroundRLScore;

    m_PlayerScores[plr->GetGUID()] = sc;

    UpdateWorldState(0xbb8, GetAlivePlayersCountByTeam(ALLIANCE));
    UpdateWorldState(0xbb9, GetAlivePlayersCountByTeam(HORDE));
}

void BattleGroundRL::RemovePlayer(Player* /*plr*/, uint64 /*guid*/)
{
    if(GetStatus() == STATUS_WAIT_LEAVE)
        return;

    UpdateWorldState(0xbb8, GetAlivePlayersCountByTeam(ALLIANCE));
    UpdateWorldState(0xbb9, GetAlivePlayersCountByTeam(HORDE));

    if(!GetAlivePlayersCountByTeam(ALLIANCE) && GetPlayersCountByTeam(HORDE))
        EndBattleGround(HORDE);
    else if(GetPlayersCountByTeam(ALLIANCE) && !GetAlivePlayersCountByTeam(HORDE))
        EndBattleGround(ALLIANCE);
}

void BattleGroundRL::HandleKillPlayer(Player *player, Player *killer)
{
    if(GetStatus() != STATUS_IN_PROGRESS)
        return;

    if(!killer)
    {
        sLog.outError("Killer player not found");
        return;
    }

    BattleGround::HandleKillPlayer(player,killer);

    UpdateWorldState(0xbb8, GetAlivePlayersCountByTeam(ALLIANCE));
    UpdateWorldState(0xbb9, GetAlivePlayersCountByTeam(HORDE));

    if(!GetAlivePlayersCountByTeam(ALLIANCE))
    {
        // all opponents killed
        EndBattleGround(HORDE);
    }
    else if(!GetAlivePlayersCountByTeam(HORDE))
    {
        // all opponents killed
        EndBattleGround(ALLIANCE);
    }
}

bool BattleGroundRL::HandlePlayerUnderMap(Player *player)
{
    player->TeleportTo(GetMapId(),1285.810547,1667.896851,39.957642,player->GetOrientation(),false);
    return true;
}

void BattleGroundRL::HandleAreaTrigger(Player *Source, uint32 Trigger)
{
    // this is wrong way to implement these things. On official it done by gameobject spell cast.
    if(GetStatus() != STATUS_IN_PROGRESS)
        return;

    //uint32 SpellId = 0;
    //uint64 buff_guid = 0;
    switch(Trigger)
    {
        case 4696:                                          // buff trigger?
        case 4697:                                          // buff trigger?
            break;
        default:
            sLog.outError("WARNING: Unhandled AreaTrigger in Battleground: %u", Trigger);
            Source->GetSession()->SendAreaTriggerMessage("Warning: Unhandled AreaTrigger in Battleground: %u", Trigger);
            break;
    }

    //if(buff_guid)
    //    HandleTriggerBuff(buff_guid,Source);
}

void BattleGroundRL::FillInitialWorldStates(WorldPacket &data)
{
    data << uint32(0xbb8) << uint32(GetAlivePlayersCountByTeam(ALLIANCE));           // 7
    data << uint32(0xbb9) << uint32(GetAlivePlayersCountByTeam(HORDE));           // 8
    data << uint32(0xbba) << uint32(1);           // 9
}

void BattleGroundRL::ResetBGSubclass()
{

}

bool BattleGroundRL::SetupBattleGround()
{
    // gates
    if(    !AddObject(BG_RL_OBJECT_DOOR_1, BG_RL_OBJECT_TYPE_DOOR_1, 1293.561, 1601.938, 31.60557, -1.457349, 0, 0, -0.6658813, 0.7460576, RESPAWN_IMMEDIATELY)
        || !AddObject(BG_RL_OBJECT_DOOR_2, BG_RL_OBJECT_TYPE_DOOR_2, 1278.648, 1730.557, 31.60557, 1.684245, 0, 0, 0.7460582, 0.6658807, RESPAWN_IMMEDIATELY)
    // buffs
        || !AddObject(BG_RL_OBJECT_BUFF_1, BG_RL_OBJECT_TYPE_BUFF_1, 1328.719971, 1632.719971, 36.730400, -1.448624, 0, 0, 0.6626201, -0.7489557, 120)
        || !AddObject(BG_RL_OBJECT_BUFF_2, BG_RL_OBJECT_TYPE_BUFF_2, 1243.300049, 1699.170044, 34.872601, -0.06981307, 0, 0, 0.03489945, -0.9993908, 120))
    {
        sLog.outErrorDb("BatteGroundRL: Failed to spawn some object!");
        return false;
    }

    return true;
}

/*
Packet S->C, id 600, SMSG_INIT_WORLD_STATES (706), len 86
0000: 3C 02 00 00 80 0F 00 00 00 00 00 00 09 00 BA 0B | <...............
0010: 00 00 01 00 00 00 B9 0B 00 00 02 00 00 00 B8 0B | ................
0020: 00 00 00 00 00 00 D8 08 00 00 00 00 00 00 D7 08 | ................
0030: 00 00 00 00 00 00 D6 08 00 00 00 00 00 00 D5 08 | ................
0040: 00 00 00 00 00 00 D3 08 00 00 00 00 00 00 D4 08 | ................
0050: 00 00 00 00 00 00                               | ......
*/

