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
#include "BattleGroundBE.h"
#include "Creature.h"
#include "ObjectMgr.h"
#include "MapManager.h"
#include "Language.h"

BattleGroundBE::BattleGroundBE()
{
    m_BgObjects.resize(BG_BE_OBJECT_MAX);
}

BattleGroundBE::~BattleGroundBE()
{

}

void BattleGroundBE::Update(time_t diff)
{
    BattleGround::Update(diff);

    // after bg start we get there
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
            for(uint32 i = BG_BE_OBJECT_DOOR_1; i <= BG_BE_OBJECT_DOOR_4; i++)
                SpawnBGObject(i, RESPAWN_IMMEDIATELY);

            for(uint32 i = BG_BE_OBJECT_BUFF_1; i <= BG_BE_OBJECT_BUFF_2; i++)
                SpawnBGObject(i, RESPAWN_ONE_DAY);

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

            for(uint32 i = BG_BE_OBJECT_DOOR_1; i <= BG_BE_OBJECT_DOOR_2; i++)
                DoorOpen(i);

            for(uint32 i = BG_BE_OBJECT_BUFF_1; i <= BG_BE_OBJECT_BUFF_2; i++)
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

void BattleGroundBE::AddPlayer(Player *plr)
{
    BattleGround::AddPlayer(plr);
    //create score and add it to map, default values are set in constructor
    BattleGroundBEScore* sc = new BattleGroundBEScore;

    m_PlayerScores[plr->GetGUID()] = sc;

    UpdateWorldState(0x9f1, GetAlivePlayersCountByTeam(ALLIANCE));
    UpdateWorldState(0x9f0, GetAlivePlayersCountByTeam(HORDE));
}

void BattleGroundBE::RemovePlayer(Player* /*plr*/, uint64 /*guid*/)
{
    if(GetStatus() == STATUS_WAIT_LEAVE)
        return;

    UpdateWorldState(0x9f1, GetAlivePlayersCountByTeam(ALLIANCE));
    UpdateWorldState(0x9f0, GetAlivePlayersCountByTeam(HORDE));

    if(!GetAlivePlayersCountByTeam(ALLIANCE) && GetPlayersCountByTeam(HORDE))
        EndBattleGround(HORDE);
    else if(GetPlayersCountByTeam(ALLIANCE) && !GetAlivePlayersCountByTeam(HORDE))
        EndBattleGround(ALLIANCE);
}

void BattleGroundBE::HandleKillPlayer(Player *player, Player *killer)
{
    if(GetStatus() != STATUS_IN_PROGRESS)
        return;

    if(!killer)
    {
        sLog.outError("Killer player not found");
        return;
    }

    BattleGround::HandleKillPlayer(player,killer);

    UpdateWorldState(0x9f1, GetAlivePlayersCountByTeam(ALLIANCE));
    UpdateWorldState(0x9f0, GetAlivePlayersCountByTeam(HORDE));

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

bool BattleGroundBE::HandlePlayerUnderMap(Player *player)
{
    player->TeleportTo(GetMapId(),6238.930176,262.963470,0.889519,player->GetOrientation(),false);
    return true;
}

void BattleGroundBE::HandleAreaTrigger(Player *Source, uint32 Trigger)
{
    // this is wrong way to implement these things. On official it done by gameobject spell cast.
    if(GetStatus() != STATUS_IN_PROGRESS)
        return;

    //uint32 SpellId = 0;
    //uint64 buff_guid = 0;
    switch(Trigger)
    {
        case 4538:                                          // buff trigger?
            //buff_guid = m_BgObjects[BG_BE_OBJECT_BUFF_1];
            break;
        case 4539:                                          // buff trigger?
            //buff_guid = m_BgObjects[BG_BE_OBJECT_BUFF_2];
            break;
        default:
            sLog.outError("WARNING: Unhandled AreaTrigger in Battleground: %u", Trigger);
            Source->GetSession()->SendAreaTriggerMessage("Warning: Unhandled AreaTrigger in Battleground: %u", Trigger);
            break;
    }

    //if(buff_guid)
    //    HandleTriggerBuff(buff_guid,Source);
}

void BattleGroundBE::FillInitialWorldStates(WorldPacket &data)
{
    data << uint32(0x9f1) << uint32(GetAlivePlayersCountByTeam(ALLIANCE));           // 7
    data << uint32(0x9f0) << uint32(GetAlivePlayersCountByTeam(HORDE));           // 8
    data << uint32(0x9f3) << uint32(1);           // 9
}

void BattleGroundBE::ResetBGSubclass()
{

}

bool BattleGroundBE::SetupBattleGround()
{
    // gates
    if(    !AddObject(BG_BE_OBJECT_DOOR_1, BG_BE_OBJECT_TYPE_DOOR_1, 6287.277f, 282.1877f, 3.810925f, -2.260201f, 0, 0, 0.9044551f, -0.4265689f, RESPAWN_IMMEDIATELY)
        || !AddObject(BG_BE_OBJECT_DOOR_2, BG_BE_OBJECT_TYPE_DOOR_2, 6189.546f, 241.7099f, 3.101481f, 0.8813917f, 0, 0, 0.4265689f, 0.9044551f, RESPAWN_IMMEDIATELY)
        || !AddObject(BG_BE_OBJECT_DOOR_3, BG_BE_OBJECT_TYPE_DOOR_3, 6299.116f, 296.5494f, 3.308032f, 0.8813917f, 0, 0, 0.4265689f, 0.9044551f, RESPAWN_IMMEDIATELY)
        || !AddObject(BG_BE_OBJECT_DOOR_4, BG_BE_OBJECT_TYPE_DOOR_4, 6177.708f, 227.3481f, 3.604374f, -2.260201f, 0, 0, 0.9044551f, -0.4265689f, RESPAWN_IMMEDIATELY)
        // buffs
        || !AddObject(BG_BE_OBJECT_BUFF_1, BG_BE_OBJECT_TYPE_BUFF_1, 6249.042f, 275.3239f, 11.22033f, -1.448624f, 0, 0, 0.6626201f, -0.7489557f, 120)
        || !AddObject(BG_BE_OBJECT_BUFF_2, BG_BE_OBJECT_TYPE_BUFF_2, 6228.26f, 249.566f, 11.21812f, -0.06981307f, 0, 0, 0.03489945f, -0.9993908f, 120))
    {
        sLog.outErrorDb("BatteGroundBE: Failed to spawn some object!");
        return false;
    }

    return true;
}

void BattleGroundBE::UpdatePlayerScore(Player* Source, uint32 type, uint32 value)
{

    std::map<uint64, BattleGroundScore*>::iterator itr = m_PlayerScores.find(Source->GetGUID());

    if(itr == m_PlayerScores.end())                         // player not found...
        return;

    //there is nothing special in this score
    BattleGround::UpdatePlayerScore(Source,type,value);

}

/*
21:45:46 id:231310 [S2C] SMSG_INIT_WORLD_STATES (706 = 0x02C2) len: 86
0000: 32 02 00 00 76 0e 00 00 00 00 00 00 09 00 f3 09  |  2...v...........
0010: 00 00 01 00 00 00 f1 09 00 00 01 00 00 00 f0 09  |  ................
0020: 00 00 02 00 00 00 d4 08 00 00 00 00 00 00 d8 08  |  ................
0030: 00 00 00 00 00 00 d7 08 00 00 00 00 00 00 d6 08  |  ................
0040: 00 00 00 00 00 00 d5 08 00 00 00 00 00 00 d3 08  |  ................
0050: 00 00 00 00 00 00                                |  ......

spell 32724 - Gold Team
spell 32725 - Green Team
35774 Gold Team
35775 Green Team
*/

