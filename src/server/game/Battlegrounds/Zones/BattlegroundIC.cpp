/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Player.h"
#include "BattlegroundMap.h"
#include "BattlegroundScore.h"
#include "BattlegroundIC.h"
#include "Language.h"
#include "WorldPacket.h"
#include "GameObject.h"
#include "ObjectMgr.h"
#include "Vehicle.h"
#include "Transport.h"

void BattlegroundIC::InstallBattleground()
{
    for (uint8 i = 0; i < 2; i++)
        _factionReinforcements[i] = MAX_REINFORCEMENTS;

    for (uint8 i = 0; i < BG_IC_MAXDOOR; i++)
        _gateStatus[i] = BG_IC_GATE_OK;

    _closeFortressDoorsTimer = CLOSE_DOORS_TIME; // the doors are closed again... in a special way
    _doorsClosed = false;
    _resourceTimer = IC_RESOURCE_TIME;

    for (uint8 i = NODE_TYPE_REFINERY; i < MAX_NODE_TYPES; i++)
        _nodePoint[i] =  nodePointInitial[i];

    _siegeEngineWorkshopTimer = WORKSHOP_UPDATE_TIME;

    _gunshipHorde = NULL;
    _gunshipAlliance = NULL;
}

void BattlegroundIC::InitializeObjects()
{
    ObjectGUIDsByType.resize(MAX_NORMAL_GAMEOBJECTS_SPAWNS + MAX_AIRSHIPS_SPAWNS + MAX_HANGAR_TELEPORTERS_SPAWNS + MAX_FORTRESS_TELEPORTERS_SPAWNS + 
    MAX_NORMAL_NPCS_SPAWNS + MAX_WORKSHOP_SPAWNS + MAX_DOCKS_SPAWNS + MAX_SPIRIT_GUIDES_SPAWNS);

    for (uint8 i = 0; i < MAX_NORMAL_GAMEOBJECTS_SPAWNS; i++)
    {
        AddGameObject(BG_IC_ObjSpawnlocs[i].type, BG_IC_ObjSpawnlocs[i].entry,
            BG_IC_ObjSpawnlocs[i].x, BG_IC_ObjSpawnlocs[i].y,
            BG_IC_ObjSpawnlocs[i].z, BG_IC_ObjSpawnlocs[i].o,
            0, 0, 0, 0, RESPAWN_ONE_DAY);
    }

    for (uint8 i = 0; i < MAX_NORMAL_NPCS_SPAWNS; i++)
    {
        AddCreature(BG_IC_NpcSpawnlocs[i].entry, BG_IC_NpcSpawnlocs[i].type, BG_IC_NpcSpawnlocs[i].team,
            BG_IC_NpcSpawnlocs[i].x, BG_IC_NpcSpawnlocs[i].y,
            BG_IC_NpcSpawnlocs[i].z, BG_IC_NpcSpawnlocs[i].o,
            RESPAWN_ONE_DAY);
    }

    AddSpiritGuide(BG_IC_NPC_SPIRIT_GUIDE_1+5, BG_IC_SpiritGuidePos[5][0], BG_IC_SpiritGuidePos[5][1], BG_IC_SpiritGuidePos[5][2], BG_IC_SpiritGuidePos[5][3], BG_TEAM_ALLIANCE);
    AddSpiritGuide(BG_IC_NPC_SPIRIT_GUIDE_1+6, BG_IC_SpiritGuidePos[6][0], BG_IC_SpiritGuidePos[6][1], BG_IC_SpiritGuidePos[6][2], BG_IC_SpiritGuidePos[6][3], BG_TEAM_HORDE);
    AddSpiritGuide(BG_IC_NPC_SPIRIT_GUIDE_1+3, BG_IC_SpiritGuidePos[7][0], BG_IC_SpiritGuidePos[7][1], BG_IC_SpiritGuidePos[7][2], BG_IC_SpiritGuidePos[7][3], BG_TEAM_ALLIANCE);
    AddSpiritGuide(BG_IC_NPC_SPIRIT_GUIDE_1+4, BG_IC_SpiritGuidePos[8][0], BG_IC_SpiritGuidePos[8][1], BG_IC_SpiritGuidePos[8][2], BG_IC_SpiritGuidePos[8][3], BG_TEAM_HORDE);

    _gunshipHorde = CreateTransport(GO_HORDE_GUNSHIP, TRANSPORT_PERIOD_TIME);
    _gunshipAlliance = CreateTransport(GO_ALLIANCE_GUNSHIP, TRANSPORT_PERIOD_TIME);

    //Send transport init packet to all player in map
    for (MapRefManager::iterator itr = m_mapRefManager.begin(); itr != m_mapRefManager.end(); ++itr)
        if (Player* player = itr->getSource())
            SendTransportInit(player);

    // setting correct factions for Keep Cannons
    for (uint8 i = BG_IC_NPC_KEEP_CANNON_1; i < BG_IC_NPC_KEEP_CANNON_12; i++)
        GetCreature(i)->setFaction(BG_IC_Factions[0]);
    for (uint8 i = BG_IC_NPC_KEEP_CANNON_13; i < BG_IC_NPC_KEEP_CANNON_25; i++)
        GetCreature(i)->setFaction(BG_IC_Factions[1]);

    // correcting spawn time for keeps bombs
    for (uint8 i = BG_IC_GO_HUGE_SEAFORIUM_BOMBS_A_1; i < BG_IC_GO_HUGE_SEAFORIUM_BOMBS_H_4; i++)
        GetGameObject(i)->SetRespawnTime(10);

    // Show Full Gate Displays
    GetGameObject(BG_IC_GO_ALLIANCE_GATE_1)->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED); // Alliance door
    GetGameObject(BG_IC_GO_ALLIANCE_GATE_2)->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED); // Alliance door
    GetGameObject(BG_IC_GO_HORDE_GATE_2)->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED); // Horde door
    GetGameObject(BG_IC_GO_HORDE_GATE_3)->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED); // Horde door
}

void BattlegroundIC::StartBattleground()
{
    // after 20 seconds they should be despawned
    uint32 doorsToOpen[6] = {BG_IC_GO_DOODAD_ND_HUMAN_GATE_CLOSEDFX_DOOR01, BG_IC_GO_DOODAD_ND_WINTERORC_WALL_GATEFX_DOOR01,
        BG_IC_GO_DOODAD_HU_PORTCULLIS01_1, BG_IC_GO_DOODAD_HU_PORTCULLIS01_2, BG_IC_GO_DOODAD_VR_PORTCULLIS01_1, BG_IC_GO_DOODAD_VR_PORTCULLIS01_2};
    for (uint8 i = 0; i < 6; i++)
        DoorOpen(doorsToOpen[i]);

    for (uint8 i = 0; i < MAX_FORTRESS_TELEPORTERS_SPAWNS; i++)
    {
        if (!AddGameObject(BG_IC_Teleporters[i].type, BG_IC_Teleporters[i].entry,
            BG_IC_Teleporters[i].x, BG_IC_Teleporters[i].y,
            BG_IC_Teleporters[i].z, BG_IC_Teleporters[i].o,
            0, 0, 0, 0, RESPAWN_ONE_DAY))
            sLog->outError("Isle of Conquest | Starting Event Open Doors: There was an error spawning gameobject %u", BG_IC_Teleporters[i].entry);
    }
}

void BattlegroundIC::OnPlayerResurrect(Player* player)
{
    BattlegroundMap::OnPlayerResurrect(player);

    if (_nodePoint[NODE_TYPE_QUARRY].nodeState == (player->GetBGTeam() == BG_TEAM_ALLIANCE ? NODE_STATE_CONTROLLED_A : NODE_STATE_CONTROLLED_H))
        player->CastSpell(player, SPELL_QUARRY, true);

    if (_nodePoint[NODE_TYPE_REFINERY].nodeState == (player->GetBGTeam() == BG_TEAM_ALLIANCE ? NODE_STATE_CONTROLLED_A : NODE_STATE_CONTROLLED_H))
        player->CastSpell(player, SPELL_OIL_REFINERY, true);
}

void BattlegroundIC::SendTransportInit(Player* player)
{
    if (!_gunshipAlliance || !_gunshipHorde)
        return;

    UpdateData transData;

    _gunshipAlliance->BuildCreateUpdateBlockForPlayer(&transData, player);
    _gunshipHorde->BuildCreateUpdateBlockForPlayer(&transData, player);

    WorldPacket packet;

    transData.BuildPacket(&packet);
    player->GetSession()->SendPacket(&packet);
}

void BattlegroundIC::DoAction(uint32 action, uint64 const& var)
{
    if (action != ACTION_TELEPORT_PLAYER_TO_TRANSPORT)
        return;

    Player* plr = sObjectMgr->GetPlayer(var);

    if (!plr || !_gunshipAlliance || !_gunshipHorde)
        return;

    plr->CastSpell(plr, SPELL_PARACHUTE, true); // this must be changed, there is a trigger in each transport that casts the spell.
    plr->CastSpell(plr, SPELL_SLOW_FALL, true);

    plr->SetTransport(plr->GetBGTeam() == BG_TEAM_ALLIANCE ? _gunshipAlliance : _gunshipHorde);

    plr->m_movementInfo.t_pos.m_positionX = TransportMovementInfo.GetPositionX();
    plr->m_movementInfo.t_pos.m_positionY = TransportMovementInfo.GetPositionY();
    plr->m_movementInfo.t_pos.m_positionZ = TransportMovementInfo.GetPositionZ();
    plr->m_movementInfo.t_guid = (plr->GetBGTeam() == BG_TEAM_ALLIANCE ? _gunshipAlliance : _gunshipHorde)->GetGUID();

    plr->TeleportTo(GetId(), TeleportToTransportPosition.GetPositionX(), TeleportToTransportPosition.GetPositionY(), TeleportToTransportPosition.GetPositionZ(), TeleportToTransportPosition.GetOrientation(), TELE_TO_NOT_LEAVE_TRANSPORT);
}

void BattlegroundIC::ProcessInProgress(uint32 const& diff)
{
    BattlegroundMap::ProcessInProgress(diff);

    if (!_doorsClosed)
    {
        if (_closeFortressDoorsTimer <= diff)
        {
            GetGameObject(BG_IC_GO_DOODAD_ND_HUMAN_GATE_CLOSEDFX_DOOR01)->RemoveFromWorld();
            GetGameObject(BG_IC_GO_DOODAD_ND_WINTERORC_WALL_GATEFX_DOOR01)->RemoveFromWorld();

            GetGameObject(BG_IC_GO_ALLIANCE_GATE_3)->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED); // Alliance door
            GetGameObject(BG_IC_GO_HORDE_GATE_1)->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED); // Horde door

            _doorsClosed = true;
        }
        else
            _closeFortressDoorsTimer -= diff;
    }

    for (uint8 i = NODE_TYPE_REFINERY; i < MAX_NODE_TYPES; i++)
    {
        if (_nodePoint[i].nodeType == NODE_TYPE_DOCKS)
        {
            if (_nodePoint[i].nodeState == NODE_STATE_CONTROLLED_A ||
                _nodePoint[i].nodeState == NODE_STATE_CONTROLLED_H)
            {
                if (_nodePoint[i].timer <= diff)
                {
                    // we need to confirm this, i am not sure if this every 3 minutes
                    for (uint8 u = (_nodePoint[i].faction == BG_TEAM_ALLIANCE ? BG_IC_NPC_CATAPULT_1_A : BG_IC_NPC_CATAPULT_1_H); u < (_nodePoint[i].faction  == BG_TEAM_ALLIANCE ? BG_IC_NPC_CATAPULT_4_A : BG_IC_NPC_CATAPULT_4_H); u++)
                    {
                        if (Creature* catapult = GetCreature(u))
                        {
                            if (!catapult->isAlive())
                                catapult->Respawn(true);
                        }
                    }

                    // we need to confirm this is blizzlike, not sure if it is every 3 minutes
                    for (uint8 u = (_nodePoint[i].faction == BG_TEAM_ALLIANCE ? BG_IC_NPC_GLAIVE_THROWER_1_A : BG_IC_NPC_GLAIVE_THROWER_1_H); u < (_nodePoint[i].faction == BG_TEAM_ALLIANCE ? BG_IC_NPC_GLAIVE_THROWER_2_A : BG_IC_NPC_GLAIVE_THROWER_2_H); u++)
                    {
                        if (Creature* glaiveThrower = GetCreature(u))
                        {
                            if (!glaiveThrower->isAlive())
                                glaiveThrower->Respawn(true);
                        }
                    }

                    _docksTimer = DOCKS_UPDATE_TIME;
                }
                else
                    _nodePoint[i].timer -= diff;
            }
        }

        if (_nodePoint[i].nodeType == NODE_TYPE_WORKSHOP)
        {
            if (_nodePoint[i].nodeState == NODE_STATE_CONTROLLED_A ||
                _nodePoint[i].nodeState == NODE_STATE_CONTROLLED_H)
            {
                if (_siegeEngineWorkshopTimer <= diff)
                {
                    uint8 siegeType = (_nodePoint[i].faction == BG_TEAM_ALLIANCE ? BG_IC_NPC_SIEGE_ENGINE_A : BG_IC_NPC_SIEGE_ENGINE_H);

                    if (Creature* siege = GetCreature(siegeType)) // this always should be true
                    {
                        if (siege->isAlive())
                        {
                            if (siege->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_UNK_14|UNIT_FLAG_OOC_NOT_ATTACKABLE))
                                // following sniffs the vehicle always has UNIT_FLAG_UNK_14
                                siege->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_OOC_NOT_ATTACKABLE);
                            else
                                siege->SetHealth(siege->GetMaxHealth());
                        }
                        else
                            siege->Respawn(true);
                    }

                    // we need to confirm if it is every 3 minutes
                    for (uint8 u = (_nodePoint[i].faction == BG_TEAM_ALLIANCE ? BG_IC_NPC_DEMOLISHER_1_A : BG_IC_NPC_DEMOLISHER_1_H); u < (_nodePoint[i].faction == BG_TEAM_ALLIANCE ? BG_IC_NPC_DEMOLISHER_4_A : BG_IC_NPC_DEMOLISHER_4_H); u++)
                    {
                        if (Creature* demolisher = GetCreature(u))
                        {
                            if (!demolisher->isAlive())
                                demolisher->Respawn(true);
                        }
                    }
                    _siegeEngineWorkshopTimer = WORKSHOP_UPDATE_TIME;
                } else _siegeEngineWorkshopTimer -= diff;
            }
        }

        // the point is waiting for a change on its banner
        if (_nodePoint[i].needChange)
        {
            if (_nodePoint[i].timer <= diff)
            {
                uint32 nextBanner = GetNextBanner(&_nodePoint[i], _nodePoint[i].faction, true);

                _nodePoint[i].last_entry = _nodePoint[i].gameobject_entry;
                _nodePoint[i].gameobject_entry = nextBanner;
                // nodePoint[i].faction = the faction should be the same one...

                GameObject* banner = GetGameObject(_nodePoint[i].gameobject_type);

                if (!banner) // this should never happen
                    return;

                float cords[4] = {banner->GetPositionX(), banner->GetPositionY(), banner->GetPositionZ(), banner->GetOrientation() };

                DeleteGameObject(_nodePoint[i].gameobject_type);
                AddGameObject(_nodePoint[i].gameobject_type, _nodePoint[i].gameobject_entry, cords[0], cords[1], cords[2], cords[3], 0, 0, 0, 0, RESPAWN_ONE_DAY);

                GetGameObject(_nodePoint[i].gameobject_type)->SetUInt32Value(GAMEOBJECT_FACTION, _nodePoint[i].faction == BG_TEAM_ALLIANCE ? BG_IC_Factions[1] : BG_IC_Factions[0]);

                UpdateNodeWorldState(&_nodePoint[i]);
                HandleCapturedNodes(&_nodePoint[i], false);

                SendMessageToAll(ParseStrings(LANG_BG_IC_TEAM_HAS_TAKEN_NODE,  (_nodePoint[i].faction == BG_TEAM_ALLIANCE ? LANG_BG_IC_ALLIANCE : LANG_BG_IC_HORDE), _nodePoint[i].string), CHAT_MSG_BG_SYSTEM_NEUTRAL, NULL);

                _nodePoint[i].needChange = false;
                _nodePoint[i].timer = BANNER_STATE_CHANGE_TIME;
            }
            else
                _nodePoint[i].timer -= diff;
        }
    }

    if (_resourceTimer <= diff)
    {
        for (uint8 i = 0; i < NODE_TYPE_DOCKS; i++)
        {
            if (_nodePoint[i].nodeState == NODE_STATE_CONTROLLED_A ||
                _nodePoint[i].nodeState == NODE_STATE_CONTROLLED_H)
            {
                _factionReinforcements[_nodePoint[i].faction] += 1;
                RewardHonorToTeam(RESOURCE_HONOR_AMOUNT, _nodePoint[i].faction == BG_TEAM_ALLIANCE ? BG_TEAM_ALLIANCE : BG_TEAM_HORDE);
                UpdateWorldState((_nodePoint[i].faction == BG_TEAM_ALLIANCE ? BG_IC_ALLIANCE_RENFORT : BG_IC_HORDE_RENFORT), _factionReinforcements[_nodePoint[i].faction]);
            }
        }
        _resourceTimer = IC_RESOURCE_TIME;
    }
    else
        _resourceTimer -= diff;
}

bool BattlegroundIC::IsAllNodesConrolledByTeam(uint32 team) const
{
    uint32 count = 0;
    ICNodeState controlledState = team == BG_TEAM_ALLIANCE ? NODE_STATE_CONTROLLED_A : NODE_STATE_CONTROLLED_H;
    for (int i = 0; i < NODE_TYPE_WORKSHOP; ++i)
    {
        if (_nodePoint[i].nodeState == controlledState)
            count++;
    }

    return count == NODE_TYPE_WORKSHOP;
}

void BattlegroundIC::OnPlayerJoin(Player *plr)
{
    BattlegroundMap::OnPlayerJoin(plr);
    //create score and add it to map, default values are set in constructor
    BattlegroundICScore* sc = new BattlegroundICScore;

    PlayerScores[plr->GetGUIDLow()] = sc;

    if (_nodePoint[NODE_TYPE_QUARRY].nodeState == (plr->GetBGTeam() == BG_TEAM_ALLIANCE ? NODE_STATE_CONTROLLED_A : NODE_STATE_CONTROLLED_H))
        plr->CastSpell(plr, SPELL_QUARRY, true);

    if (_nodePoint[NODE_TYPE_REFINERY].nodeState == (plr->GetBGTeam() == BG_TEAM_ALLIANCE ? NODE_STATE_CONTROLLED_A : NODE_STATE_CONTROLLED_H))
        plr->CastSpell(plr, SPELL_OIL_REFINERY, true);

    SendTransportInit(plr);
}

void BattlegroundIC::OnPlayerExit(Player* plr)
{
    BattlegroundMap::OnPlayerExit(plr);

    plr->RemoveAura(SPELL_QUARRY);
    plr->RemoveAura(SPELL_OIL_REFINERY);
}

void BattlegroundIC::HandleAreaTrigger(Player* /*Source*/, uint32 /*Trigger*/)
{
    // this is wrong way to implement these things. On official it done by gameobject spell cast.
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;
}

void BattlegroundIC::UpdatePlayerScore(Player* Source, uint32 type, uint32 value, bool doAddHonor)
{
    BattlegroundScoreMap::const_iterator itr = PlayerScores.find(Source->GetGUIDLow());
    if (itr == PlayerScores.end())                         // player not found...
        return;

    switch (type)
    {
        case SCORE_BASES_ASSAULTED:
            ((BattlegroundICScore*)itr->second)->BasesAssaulted += value;
            break;
        case SCORE_BASES_DEFENDED:
            ((BattlegroundICScore*)itr->second)->BasesDefended += value;
            break;
        default:
            BattlegroundMap::UpdatePlayerScore(Source, type, value, doAddHonor);
            break;
    }
}

void BattlegroundIC::FillInitialWorldStates(WorldPacket& data)
{
    data << uint32(BG_IC_ALLIANCE_RENFORT_SET) << uint32(1);
    data << uint32(BG_IC_HORDE_RENFORT_SET) << uint32(1);
    data << uint32(BG_IC_ALLIANCE_RENFORT) << uint32(_factionReinforcements[BG_TEAM_ALLIANCE]);
    data << uint32(BG_IC_HORDE_RENFORT) << uint32(_factionReinforcements[BG_TEAM_HORDE]);

    for (uint8 i = 0; i < MAX_FORTRESS_GATES_SPAWNS; i++)
    {
        uint32 uws = GetWorldStateFromGateEntry(BG_IC_ObjSpawnlocs[i].entry, (_gateStatus[GetGateIDFromEntry(BG_IC_ObjSpawnlocs[i].entry)] == BG_IC_GATE_DESTROYED ? true : false));
        data << uint32(uws) << uint32(1);
    }

    for (uint8 i = 0 ; i < MAX_NODE_TYPES ; i++)
        data << uint32(_nodePoint[i].worldStates[_nodePoint[i].nodeState]) << uint32(1);
}

void BattlegroundIC::OnUnitKill(Creature* unit, Player* killer)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
       return;

    uint32 entry = unit->GetEntry();
    if (entry == NPC_HIGH_COMMANDER_HALFORD_WYRMBANE)
    {
        RewardHonorToTeam(WINNER_HONOR_AMOUNT, BG_TEAM_HORDE);
        EndBattleground(WINNER_HORDE);
    }
    else if (entry == NPC_OVERLORD_AGMAR)
    {
        RewardHonorToTeam(WINNER_HONOR_AMOUNT, BG_TEAM_ALLIANCE);
        EndBattleground(WINNER_ALLIANCE);
    }

    //Achievement Mowed Down
    // TO-DO: This should be done on the script of each vehicle of the BG.
    if (unit->IsVehicle())
        killer->CastSpell(killer, SPELL_DESTROYED_VEHICLE_ACHIEVEMENT, true);
}

void BattlegroundIC::OnPlayerKill(Player* player, Player* killer)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    BattlegroundMap::OnPlayerKill(player, killer);

    _factionReinforcements[player->GetBGTeam()] -= 1;

    UpdateWorldState((player->GetBGTeam() == BG_TEAM_ALLIANCE ? BG_IC_ALLIANCE_RENFORT : BG_IC_HORDE_RENFORT), _factionReinforcements[player->GetBGTeam()]);

    // we must end the battleground
    if (_factionReinforcements[player->GetBGTeam()] < 1)
        EndBattleground( killer->GetBGTeam() == BG_TEAM_ALLIANCE ? WINNER_ALLIANCE : WINNER_HORDE);
}

void BattlegroundIC::EndBattleground(BattlegroundWinner winner)
{
    SendMessageToAll(ParseStrings(LANG_BG_IC_TEAM_WINS, (winner == WINNER_ALLIANCE ? LANG_BG_IC_ALLIANCE : LANG_BG_IC_HORDE)), CHAT_MSG_BG_SYSTEM_NEUTRAL);

    BattlegroundMap::EndBattleground(winner);
}

void BattlegroundIC::RealocatePlayers(ICNodePointType nodeType)
{
    // Those who are waiting to resurrect at this node are taken to the closest own node's graveyard
    std::vector<uint64> ghost_list = ReviveQueue[ObjectGUIDsByType[BG_IC_NPC_SPIRIT_GUIDE_1+nodeType-2]];
    if (!ghost_list.empty())
    {
        WorldSafeLocsEntry const *ClosestGrave = NULL;
        for (std::vector<uint64>::const_iterator itr = ghost_list.begin(); itr != ghost_list.end(); ++itr)
        {
            Player* plr = sObjectMgr->GetPlayer(*itr);
            if (!plr)
                continue;

            if (!ClosestGrave)                              // cache
                ClosestGrave = GetClosestGraveYard(plr);

            if (ClosestGrave)
                plr->TeleportTo(GetId(), ClosestGrave->x, ClosestGrave->y, ClosestGrave->z, plr->GetOrientation());
        }
    }
}

void BattlegroundIC::EventPlayerClickedOnFlag(Player* player, GameObject* target_obj)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    // All the node points are iterated to find the clicked one
    for (uint8 i = 0; i < MAX_NODE_TYPES; i++)
    {
        if (_nodePoint[i].gameobject_entry == target_obj->GetEntry())
        {
            // THIS SHOULD NEEVEER HAPPEN
            if (_nodePoint[i].faction == player->GetBGTeam())
                return;

            uint32 nextBanner = GetNextBanner(&_nodePoint[i], player->GetBGTeam(), false);

            // we set the new settings of the nodePoint
            _nodePoint[i].faction = player->GetBGTeam();
            _nodePoint[i].last_entry = _nodePoint[i].gameobject_entry;
            _nodePoint[i].gameobject_entry = nextBanner;

            // this is just needed if the next banner is grey
            if (_nodePoint[i].banners[BANNER_A_CONTESTED] == nextBanner ||
                _nodePoint[i].banners[BANNER_H_CONTESTED] == nextBanner)
            {
                _nodePoint[i].timer = BANNER_STATE_CHANGE_TIME; // 1 minute for last change (real faction banner)
                _nodePoint[i].needChange = true;

                RealocatePlayers(_nodePoint[i].nodeType);

                // if we are here means that the point has been lost, or it is the first capture

                if (_nodePoint[i].nodeType != NODE_TYPE_REFINERY && _nodePoint[i].nodeType != NODE_TYPE_QUARRY)
                    DeleteCreature(BG_IC_NPC_SPIRIT_GUIDE_1+(_nodePoint[i].nodeType)-2);

                UpdatePlayerScore(player, SCORE_BASES_ASSAULTED, 1);

                SendMessageToAll(ParseStrings(LANG_BG_IC_TEAM_ASSAULTED_NODE_1, _nodePoint[i].string), CHAT_MSG_BG_SYSTEM_NEUTRAL, player);
                
                char string[512];
                snprintf(string, 1024, sObjectMgr->GetTrinityStringForDBCLocale(LANG_BG_IC_TEAM_ASSAULTED_NODE_2), 
                    _nodePoint[i].string, sObjectMgr->GetTrinityStringForDBCLocale(player->GetBGTeam() == BG_TEAM_ALLIANCE ? LANG_BG_IC_ALLIANCE : LANG_BG_IC_HORDE));

                SendMessageToAll(string, CHAT_MSG_BG_SYSTEM_NEUTRAL, player);
                HandleContestedNodes(&_nodePoint[i]);
            }
            else if (nextBanner == _nodePoint[i].banners[BANNER_A_CONTROLLED] || nextBanner == _nodePoint[i].banners[BANNER_H_CONTROLLED])
            // if we are going to spawn the definitve faction banner, we dont need the timer anymore
            {
                _nodePoint[i].timer = BANNER_STATE_CHANGE_TIME;
                _nodePoint[i].needChange = false;
                SendMessageToAll(ParseStrings(LANG_BG_IC_TEAM_DEFENDED_NODE, _nodePoint[i].string), CHAT_MSG_BG_SYSTEM_NEUTRAL, player);
                HandleCapturedNodes(&_nodePoint[i], true);
                UpdatePlayerScore(player, SCORE_BASES_DEFENDED, 1);
            }

            GameObject* banner = GetGameObject(_nodePoint[i].gameobject_type);

            if (!banner) // this should never happen
                return;

            float cords[4] = {banner->GetPositionX(), banner->GetPositionY(), banner->GetPositionZ(), banner->GetOrientation() };

            DeleteGameObject(_nodePoint[i].gameobject_type);
            AddGameObject(_nodePoint[i].gameobject_type, _nodePoint[i].gameobject_entry, cords[0], cords[1], cords[2], cords[3], 0, 0, 0, 0, RESPAWN_ONE_DAY);

            GetGameObject(_nodePoint[i].gameobject_type)->SetUInt32Value(GAMEOBJECT_FACTION, _nodePoint[i].faction == BG_TEAM_ALLIANCE ? BG_IC_Factions[1] : BG_IC_Factions[0]);

            if (_nodePoint[i].nodeType == NODE_TYPE_WORKSHOP)
            {
                DeleteGameObject(BG_IC_GO_SEAFORIUM_BOMBS_1);
                DeleteGameObject(BG_IC_GO_SEAFORIUM_BOMBS_2);
            }

            UpdateNodeWorldState(&_nodePoint[i]);
            // we dont need iterating if we are here
            // If the needChange bool was set true, we will handle the rest in the Update Map function.
            return;
        }
    }
}

void BattlegroundIC::UpdateNodeWorldState(ICNodePoint* nodePoint)
{
    //updating worldstate
    if (nodePoint->gameobject_entry == nodePoint->banners[BANNER_A_CONTROLLED])
        nodePoint->nodeState = NODE_STATE_CONTROLLED_A;
    else if (nodePoint->gameobject_entry == nodePoint->banners[BANNER_A_CONTESTED])
        nodePoint->nodeState = NODE_STATE_CONFLICT_A;
    else if (nodePoint->gameobject_entry == nodePoint->banners[BANNER_H_CONTROLLED])
        nodePoint->nodeState = NODE_STATE_CONTROLLED_H;
    else if (nodePoint->gameobject_entry == nodePoint->banners[BANNER_H_CONTESTED])
        nodePoint->nodeState = NODE_STATE_CONFLICT_H;

    uint32 worldstate = nodePoint->worldStates[nodePoint->nodeState];

    // with this we are sure we dont bug the client
    for (uint8 i = 0; i < 4; i++)
        UpdateWorldState(nodePoint->worldStates[i], 0);

    UpdateWorldState(worldstate, 1);
}

uint32 BattlegroundIC::GetNextBanner(ICNodePoint* nodePoint, uint32 team, bool returnDefinitve)
{
    // this is only used in the update map function
    if (returnDefinitve)
        // here is a special case, here we must return the definitve faction banner after the grey banner was spawned 1 minute
        return nodePoint->banners[(team == BG_TEAM_ALLIANCE ? BANNER_A_CONTROLLED : BANNER_H_CONTROLLED)];

    // there were no changes, this point has never been captured by any faction or at least clicked
    if (nodePoint->last_entry == 0)
        // 1 returns the CONTESTED BG_TEAM_ALLIANCE BANNER, 3 returns the BG_TEAM_HORDE one
        return nodePoint->banners[(team == BG_TEAM_ALLIANCE ? BANNER_A_CONTESTED : BANNER_H_CONTESTED)];

    // If the actual banner is the definitive faction banner, we must return the grey banner of the player's faction
    if (nodePoint->gameobject_entry == nodePoint->banners[BANNER_A_CONTROLLED] || nodePoint->gameobject_entry == nodePoint->banners[BANNER_H_CONTROLLED])
        return nodePoint->banners[(team == BG_TEAM_ALLIANCE ? BANNER_A_CONTESTED : BANNER_H_CONTESTED)];

    // If the actual banner is the grey faction banner, we must return the previous banner
    if (nodePoint->gameobject_entry == nodePoint->banners[BANNER_A_CONTESTED] || nodePoint->banners[BANNER_H_CONTESTED])
        return nodePoint->last_entry;

    // we should never be here...
    sLog->outError("Isle Of Conquest: Unexpected return in GetNextBanner function");
    return 0;
}

void BattlegroundIC::HandleContestedNodes(ICNodePoint* nodePoint)
{
    if (nodePoint->nodeType == NODE_TYPE_HANGAR)
    {
        if (_gunshipAlliance && _gunshipHorde)
            (nodePoint->faction == BG_TEAM_ALLIANCE ? _gunshipHorde : _gunshipAlliance)->BuildStopMovePacket(this);

        for (uint8 u = BG_IC_GO_HANGAR_TELEPORTER_1; u < BG_IC_GO_HANGAR_TELEPORTER_3; u++)
            DeleteGameObject(u);
    }
}

void BattlegroundIC::HandleCapturedNodes(ICNodePoint* nodePoint, bool recapture)
{
    if (nodePoint->nodeType != NODE_TYPE_REFINERY && nodePoint->nodeType != NODE_TYPE_QUARRY)
    {
        AddSpiritGuide(BG_IC_NPC_SPIRIT_GUIDE_1+nodePoint->nodeType-2,
            BG_IC_SpiritGuidePos[nodePoint->nodeType][0], BG_IC_SpiritGuidePos[nodePoint->nodeType][1],
            BG_IC_SpiritGuidePos[nodePoint->nodeType][2], BG_IC_SpiritGuidePos[nodePoint->nodeType][3],
            (nodePoint->faction == BG_TEAM_ALLIANCE ? BG_TEAM_ALLIANCE : BG_TEAM_HORDE));
    }

    switch(nodePoint->gameobject_type)
    {
    case BG_IC_GO_HANGAR_BANNER:
        // all the players on the stopped transport should be teleported out
        if (!_gunshipAlliance || !_gunshipHorde)
            break;

        for (uint8 u = 0; u < MAX_HANGAR_TELEPORTERS_SPAWNS; u++)
        {
            uint8 type = BG_IC_GO_HANGAR_TELEPORTER_1+u;
            AddGameObject(type, (nodePoint->faction == BG_TEAM_ALLIANCE ? GO_ALLIANCE_GUNSHIP_PORTAL : GO_HORDE_GUNSHIP_PORTAL),
                BG_IC_HangarTeleporters[u].GetPositionX(), BG_IC_HangarTeleporters[u].GetPositionY(),
                BG_IC_HangarTeleporters[u].GetPositionZ(), BG_IC_HangarTeleporters[u].GetOrientation(),
                0, 0, 0, 0, RESPAWN_ONE_DAY);
        }

        //sLog->outError("BG_IC_GO_HANGAR_BANNER CAPTURED Faction: %u", nodePoint->faction);

        (nodePoint->faction == BG_TEAM_ALLIANCE ? _gunshipAlliance : _gunshipHorde)->BuildStartMovePacket(this);
        (nodePoint->faction == BG_TEAM_ALLIANCE ? _gunshipHorde : _gunshipAlliance)->BuildStopMovePacket(this);
        // we should spawn teleporters
        break;
    case BG_IC_GO_QUARRY_BANNER:
        RemoveAuraOnTeam(SPELL_QUARRY, (nodePoint->faction == BG_TEAM_ALLIANCE ? BG_TEAM_HORDE : BG_TEAM_ALLIANCE));
        CastSpellOnTeam(SPELL_QUARRY, (nodePoint->faction == BG_TEAM_ALLIANCE ? BG_TEAM_ALLIANCE : BG_TEAM_HORDE));
        break;
    case BG_IC_GO_REFINERY_BANNER:
        RemoveAuraOnTeam(SPELL_OIL_REFINERY, (nodePoint->faction == BG_TEAM_ALLIANCE ? BG_TEAM_HORDE : BG_TEAM_ALLIANCE));
        CastSpellOnTeam(SPELL_OIL_REFINERY, (nodePoint->faction == BG_TEAM_ALLIANCE ? BG_TEAM_ALLIANCE : BG_TEAM_HORDE));
        break;
    case BG_IC_GO_DOCKS_BANNER:

        if (recapture)
            break;

        if (_docksTimer < DOCKS_UPDATE_TIME)
            _docksTimer = DOCKS_UPDATE_TIME;

        // we must del opposing faction vehicles when the node is captured (unused ones)
        for (uint8 i = (nodePoint->faction == BG_TEAM_ALLIANCE ? BG_IC_NPC_GLAIVE_THROWER_1_H : BG_IC_NPC_GLAIVE_THROWER_1_A); i < (nodePoint->faction == BG_TEAM_ALLIANCE ? BG_IC_NPC_GLAIVE_THROWER_2_H : BG_IC_NPC_GLAIVE_THROWER_2_A); i++)
        {
            if (Creature* glaiveThrower = GetCreature(i))
            {
                if (Vehicle* vehicleGlaive = glaiveThrower->GetVehicleKit())
                {
                    if (!vehicleGlaive->GetPassenger(0))
                        DeleteCreature(i);
                }
            }
        }

        for (uint8 i = (nodePoint->faction == BG_TEAM_ALLIANCE ? BG_IC_NPC_CATAPULT_1_H : BG_IC_NPC_CATAPULT_1_A); i < (nodePoint->faction == BG_TEAM_ALLIANCE ? BG_IC_NPC_CATAPULT_4_H  : BG_IC_NPC_CATAPULT_4_A); i++)
        {
            if (Creature* catapult = GetCreature(i))
            {
                if (Vehicle* vehicleGlaive = catapult->GetVehicleKit())
                {
                    if (!vehicleGlaive->GetPassenger(0))
                        DeleteCreature(i);
                }
            }
        }

        // spawning glaive throwers
        for (uint8 i = 0; i < MAX_GLAIVE_THROWERS_SPAWNS_PER_FACTION; i++)
        {
            uint8 type = (nodePoint->faction == BG_TEAM_ALLIANCE ? BG_IC_NPC_GLAIVE_THROWER_1_A : BG_IC_NPC_GLAIVE_THROWER_1_H)+i;

            if (GetCreature(type) && GetCreature(type)->isAlive())
                continue;

            if (AddCreature(nodePoint->faction == BG_TEAM_ALLIANCE ? NPC_GLAIVE_THROWER_A : NPC_GLAIVE_THROWER_H, type, nodePoint->faction,
                    BG_IC_DocksVehiclesGlaives[i].GetPositionX(), BG_IC_DocksVehiclesGlaives[i].GetPositionY(),
                    BG_IC_DocksVehiclesGlaives[i].GetPositionZ(), BG_IC_DocksVehiclesGlaives[i].GetOrientation(),
                    RESPAWN_ONE_DAY))
                    GetCreature(type)->setFaction(BG_IC_Factions[(nodePoint->faction == BG_TEAM_ALLIANCE ? 0 : 1)]);
        }

        // spawning catapults
        for (uint8 i = 0; i < MAX_CATAPULTS_SPAWNS_PER_FACTION; i++)
        {
            uint8 type = (nodePoint->faction == BG_TEAM_ALLIANCE ? BG_IC_NPC_CATAPULT_1_A : BG_IC_NPC_CATAPULT_1_H)+i;

            if (GetCreature(type) && GetCreature(type)->isAlive())
                continue;

            if (AddCreature(NPC_CATAPULT, type, nodePoint->faction,
                    BG_IC_DocksVehiclesCatapults[i].GetPositionX(), BG_IC_DocksVehiclesCatapults[i].GetPositionY(),
                    BG_IC_DocksVehiclesCatapults[i].GetPositionZ(), BG_IC_DocksVehiclesCatapults[i].GetOrientation(),
                    RESPAWN_ONE_DAY))
                    GetCreature(type)->setFaction(BG_IC_Factions[(nodePoint->faction == BG_TEAM_ALLIANCE ? 0 : 1)]);
        }
        break;
    case BG_IC_GO_WORKSHOP_BANNER:
        {
            if (_siegeEngineWorkshopTimer < WORKSHOP_UPDATE_TIME)
                _siegeEngineWorkshopTimer = WORKSHOP_UPDATE_TIME;

            if (!recapture)
            {
                // we must del opposing faction vehicles when the node is captured (unused ones)
                for (uint8 i = (nodePoint->faction == BG_TEAM_ALLIANCE ? BG_IC_NPC_DEMOLISHER_1_H : BG_IC_NPC_DEMOLISHER_1_A); i < (nodePoint->faction == BG_TEAM_ALLIANCE ? BG_IC_NPC_DEMOLISHER_4_H : BG_IC_NPC_DEMOLISHER_4_A); i++)
                {
                    if (Creature* demolisher = GetCreature(i))
                    {
                        if (Vehicle* vehicleDemolisher = demolisher->GetVehicleKit())
                        {
                            // is IsVehicleInUse working as expected?
                            if (!vehicleDemolisher->IsVehicleInUse())
                                DeleteCreature(i);
                        }
                    }
                }

                for (uint8 i = 0; i < MAX_DEMOLISHERS_SPAWNS_PER_FACTION; i++)
                {
                    uint8 type = (nodePoint->faction == BG_TEAM_ALLIANCE ? BG_IC_NPC_DEMOLISHER_1_A : BG_IC_NPC_DEMOLISHER_1_H)+i;

                    if (GetCreature(type) && GetCreature(type)->isAlive())
                        continue;

                    if (AddCreature(NPC_DEMOLISHER, type, nodePoint->faction,
                        BG_IC_WorkshopVehicles[i].GetPositionX(), BG_IC_WorkshopVehicles[i].GetPositionY(),
                        BG_IC_WorkshopVehicles[i].GetPositionZ(), BG_IC_WorkshopVehicles[i].GetOrientation(),
                        RESPAWN_ONE_DAY))
                        GetCreature(type)->setFaction(BG_IC_Factions[(nodePoint->faction == BG_TEAM_ALLIANCE ? 0 : 1)]);
                }

                // we check if the opossing siege engine is in use
                int8 enemySiege = (nodePoint->faction == BG_TEAM_ALLIANCE ? BG_IC_NPC_SIEGE_ENGINE_H : BG_IC_NPC_SIEGE_ENGINE_A);

                if (Creature* siegeEngine = GetCreature(enemySiege))
                {
                    if (Vehicle* vehicleSiege = siegeEngine->GetVehicleKit())
                    {
                        // is VehicleInUse working as expected ?
                        if (!vehicleSiege->IsVehicleInUse())
                            DeleteCreature(enemySiege);
                    }
                }

                uint8 siegeType = (nodePoint->faction == BG_TEAM_ALLIANCE ? BG_IC_NPC_SIEGE_ENGINE_A : BG_IC_NPC_SIEGE_ENGINE_H);
                if (!GetCreature(siegeType) || !GetCreature(siegeType)->isAlive())
                {
                    AddCreature((nodePoint->faction == BG_TEAM_ALLIANCE ? NPC_SIEGE_ENGINE_A : NPC_SIEGE_ENGINE_H), siegeType, nodePoint->faction,
                        BG_IC_WorkshopVehicles[4].GetPositionX(), BG_IC_WorkshopVehicles[4].GetPositionY(),
                        BG_IC_WorkshopVehicles[4].GetPositionZ(), BG_IC_WorkshopVehicles[4].GetOrientation(),
                        RESPAWN_ONE_DAY);

                    if (Creature* siegeEngine = GetCreature(siegeType))
                    {
                        siegeEngine->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_UNK_14|UNIT_FLAG_OOC_NOT_ATTACKABLE);
                        siegeEngine->setFaction(BG_IC_Factions[(nodePoint->faction == BG_TEAM_ALLIANCE ? 0 : 1)]);
                    }
                }
            }

            for (uint8 i = 0; i < MAX_WORKSHOP_BOMBS_SPAWNS_PER_FACTION; i++)
            {
                AddGameObject(BG_IC_GO_SEAFORIUM_BOMBS_1+i, GO_SEAFORIUM_BOMBS,
                workshopBombs[i].GetPositionX(), workshopBombs[i].GetPositionY(),
                workshopBombs[i].GetPositionZ(), workshopBombs[i].GetOrientation(),
                0, 0, 0, 0, 10);

                if (GameObject* seaforiumBombs = GetGameObject(BG_IC_GO_SEAFORIUM_BOMBS_1+i))
                {
                    seaforiumBombs->SetRespawnTime(10);
                    seaforiumBombs->SetUInt32Value(GAMEOBJECT_FACTION, BG_IC_Factions[(nodePoint->faction == BG_TEAM_ALLIANCE ? 0 : 1)]);
                }
            }
            break;
        }
    default:
        break;
    }
}

void BattlegroundIC::DestroyGate(Player* pl, GameObject* go, uint32 /*destroyedEvent*/)
{
    _gateStatus[GetGateIDFromEntry(go->GetEntry())] = BG_IC_GATE_DESTROYED;
    uint32 uws_open = GetWorldStateFromGateEntry(go->GetEntry(), true);
    uint32 uws_close = GetWorldStateFromGateEntry(go->GetEntry(), false);
    if (uws_open)
    {
        UpdateWorldState(uws_close, 0);
        UpdateWorldState(uws_open, 1);
    }
    DoorOpen((pl->GetBGTeam() == BG_TEAM_ALLIANCE ? BG_IC_GO_HORDE_KEEP_PORTCULLIS : BG_IC_GO_DOODAD_PORTCULLISACTIVE02));

    uint32 lang_entry = 0;

    switch(go->GetEntry())
    {
        case GO_HORDE_GATE_1:
            lang_entry = LANG_BG_IC_NORTH_GATE_DESTROYED;
        case GO_HORDE_GATE_2:
        case GO_ALLIANCE_GATE_1:
            lang_entry = LANG_BG_IC_WEST_GATE_DESTROYED;
            break;
        case GO_HORDE_GATE_3:
        case GO_ALLIANCE_GATE_2:
            lang_entry = LANG_BG_IC_EAST_GATE_DESTROYED;
            break;
        case GO_ALLIANCE_GATE_3:
            lang_entry = LANG_BG_IC_SOUTH_GATE_DESTROYED;
            break;
    default:
        break;
    }

    SendMessageToAll(ParseStrings(lang_entry, (pl->GetBGTeam() == BG_TEAM_ALLIANCE ? LANG_BG_IC_HORDE_KEEP : LANG_BG_IC_ALLIANCE_KEEP)), CHAT_MSG_BG_SYSTEM_NEUTRAL, NULL);
}

WorldSafeLocsEntry const* BattlegroundIC::GetClosestGraveYard(Player* player)
{
    BattlegroundTeamId teamIndex = BattlegroundTeamId(player->GetBGTeam());

    // Is there any occupied node for this team?
    std::vector<uint8> nodes;
    for (uint8 i = 0; i < MAX_NODE_TYPES; ++i)
        if (_nodePoint[i].faction == player->GetBGTeam())
            nodes.push_back(i);

    WorldSafeLocsEntry const* good_entry = NULL;
    // If so, select the closest node to place ghost on
    if (!nodes.empty())
    {
        float plr_x = player->GetPositionX();
        float plr_y = player->GetPositionY();

        float mindist = 999999.0f;
        for (uint8 i = 0; i < nodes.size(); ++i)
        {
            WorldSafeLocsEntry const*entry = sWorldSafeLocsStore.LookupEntry(BG_IC_GraveyardIds[nodes[i]]);
            if (!entry)
                continue;
            float dist = (entry->x - plr_x)*(entry->x - plr_x)+(entry->y - plr_y)*(entry->y - plr_y);
            if (mindist > dist)
            {
                mindist = dist;
                good_entry = entry;
            }
        }
        nodes.clear();
    }
    // If not, place ghost on starting location
    if (!good_entry)
        good_entry = sWorldSafeLocsStore.LookupEntry(BG_IC_GraveyardIds[teamIndex+MAX_NODE_TYPES]);

    return good_entry;
}

Transport* BattlegroundIC::CreateTransport(uint32 goEntry, uint32 period)
{
    Transport* t = new Transport(period, 0);

    const GameObjectTemplate* goinfo = sObjectMgr->GetGameObjectTemplate(goEntry);

    if (!goinfo)
    {
        sLog->outErrorDb("Transport ID: %u will not be loaded, gameobject_template missing", goEntry);
        delete t;
        return NULL;
    }

    std::set<uint32> mapsUsed;

    if (!t->GenerateWaypoints(goinfo->moTransport.taxiPathId, mapsUsed))
        // skip transports with empty waypoints list
    {
        sLog->outErrorDb("Transport (path id %u) path size = 0. Transport ignored, check DBC files or transport GO data0 field.", goinfo->moTransport.taxiPathId);
        delete t;
        return NULL;
    }

    uint32 mapid = t->m_WayPoints[0].mapid;

    float x = t->m_WayPoints[0].x;
    float y = t->m_WayPoints[0].y;
    float z =  t->m_WayPoints[0].z;
    float o = 1;

    // creates the Gameobject
    if (!t->Create(sObjectMgr->GenerateLowGuid(HIGHGUID_MO_TRANSPORT), goEntry, mapid, x, y, z, o, 100, 0))
    {
        delete t;
        return NULL;
    }

    //If we someday decide to use the grid to track transports, here:
    t->SetMap(this);

    for (uint8 i = 0; i < 5; i++)
        t->AddNPCPassenger(0, (goEntry == GO_HORDE_GUNSHIP ? NPC_HORDE_GUNSHIP_CANNON : NPC_ALLIANCE_GUNSHIP_CANNON), (goEntry == GO_HORDE_GUNSHIP ? hordeGunshipPassengers[i].GetPositionX() : allianceGunshipPassengers[i].GetPositionX()) , (goEntry == GO_HORDE_GUNSHIP ? hordeGunshipPassengers[i].GetPositionY() : allianceGunshipPassengers[i].GetPositionY()), (goEntry == GO_HORDE_GUNSHIP ? hordeGunshipPassengers[i].GetPositionZ() : allianceGunshipPassengers[i].GetPositionZ()), (goEntry == GO_HORDE_GUNSHIP ? hordeGunshipPassengers[i].GetOrientation() : allianceGunshipPassengers[i].GetOrientation()));

    return t;
}

void BattlegroundIC::InitializeTextIds()
{
    PreparationPhaseTextIds[BG_STARTING_EVENT_FIRST]  = LANG_BG_IC_START_TWO_MINUTES;
    PreparationPhaseTextIds[BG_STARTING_EVENT_SECOND] = LANG_BG_IC_START_ONE_MINUTE;
    PreparationPhaseTextIds[BG_STARTING_EVENT_THIRD]  = LANG_BG_IC_START_HALF_MINUTE;
    PreparationPhaseTextIds[BG_STARTING_EVENT_FOURTH] = LANG_BG_IC_HAS_BEGUN;
}
