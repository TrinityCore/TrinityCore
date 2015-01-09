/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
#include "WorldSession.h"
#include "ScriptedCreature.h"

void BattlegroundIC::InstallBattleground()
{
    for (uint8 i = 0; i < 2; ++i)
        _factionReinforcements[i] = MAX_REINFORCEMENTS;

    for (uint8 i = 0; i < BG_IC_MAXDOOR; ++i)
        _gateStatus[i] = BG_IC_GATE_OK;

    _closeFortressDoorsTimer = CLOSE_DOORS_TIME; // the doors are closed again... in a special way
    _doorsClosed = false;

    for (uint8 i = NODE_TYPE_REFINERY; i < MAX_NODE_TYPES; ++i)
        nodePoint[i] = nodePointInitial[i];

    _siegeEngineWorkshopTimer = WORKSHOP_UPDATE_TIME;

    _gunshipHorde = NULL;
    _gunshipAlliance = NULL;
}

void BattlegroundIC::InitializeObjects()
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

void BattlegroundIC::PostUpdateImpl(uint32 diff)
{
    _gunshipAlliance->BuildCreateUpdateBlockForPlayer(&transData, player);
    _gunshipHorde->BuildCreateUpdateBlockForPlayer(&transData, player);
    if (!plr || !gunshipAlliance || !gunshipHorde)
    plr->SetTransport(plr->GetBGTeam() == BG_TEAM_ALLIANCE ? _gunshipAlliance : _gunshipHorde);
    plr->TeleportTo(GetId(), TeleportToTransportPosition.GetPositionX(), TeleportToTransportPosition.GetPositionY(), TeleportToTransportPosition.GetPositionZ(), TeleportToTransportPosition.GetOrientation(), TELE_TO_NOT_LEAVE_TRANSPORT);
void BattlegroundIC::Update(uint32 diff)
    BattlegroundMap::ProcessInProgress(diff);

    if (!_doorsClosed)
    {
        if (_closeFortressDoorsTimer <= diff)
        {
            GetGameObject(BG_IC_GO_DOODAD_ND_HUMAN_GATE_CLOSEDFX_DOOR01)->RemoveFromWorld();
            GetGameObject(BG_IC_GO_DOODAD_ND_WINTERORC_WALL_GATEFX_DOOR01)->RemoveFromWorld();
            GetBGObject(BG_IC_GO_DOODAD_ND_HUMAN_GATE_CLOSEDFX_DOOR02)->RemoveFromWorld();
            GetBGObject(BG_IC_GO_DOODAD_ND_WINTERORC_WALL_GATEFX_DOOR02)->RemoveFromWorld();
            GetBGObject(BG_IC_GO_DOODAD_ND_HUMAN_GATE_CLOSEDFX_DOOR03)->RemoveFromWorld();
            GetBGObject(BG_IC_GO_DOODAD_ND_WINTERORC_WALL_GATEFX_DOOR03)->RemoveFromWorld();

            GetBGObject(BG_IC_GO_ALLIANCE_GATE_1)->SetDestructibleState(GO_DESTRUCTIBLE_DAMAGED);
            GetBGObject(BG_IC_GO_HORDE_GATE_1)->SetDestructibleState(GO_DESTRUCTIBLE_DAMAGED);
            GetBGObject(BG_IC_GO_ALLIANCE_GATE_2)->SetDestructibleState(GO_DESTRUCTIBLE_DAMAGED);
            GetBGObject(BG_IC_GO_HORDE_GATE_2)->SetDestructibleState(GO_DESTRUCTIBLE_DAMAGED);
            GetBGObject(BG_IC_GO_ALLIANCE_GATE_3)->SetDestructibleState(GO_DESTRUCTIBLE_DAMAGED);
            GetBGObject(BG_IC_GO_HORDE_GATE_3)->SetDestructibleState(GO_DESTRUCTIBLE_DAMAGED);

            _doorsClosed = true;
        }
        else
            _closeFortressDoorsTimer -= diff;
    }

    for (uint8 i = NODE_TYPE_REFINERY; i < MAX_NODE_TYPES; ++i)
    {
        if (_nodePoint[i].nodeType == NODE_TYPE_DOCKS)
        {
            if (_nodePoint[i].nodeState == NODE_STATE_CONTROLLED_A ||
                _nodePoint[i].nodeState == NODE_STATE_CONTROLLED_H)
            {
                if (_nodePoint[i].timer <= diff)
                {
                    // we need to confirm this, i am not sure if this every 3 minutes
                    for (uint8 u = (nodePoint[i].faction == TEAM_ALLIANCE ? BG_IC_NPC_CATAPULT_1_A : BG_IC_NPC_CATAPULT_1_H); u < (nodePoint[i].faction  == TEAM_ALLIANCE ? BG_IC_NPC_CATAPULT_4_A : BG_IC_NPC_CATAPULT_4_H); u++)
                    {
                        if (Creature* catapult = GetCreature(u))
                        {
                            if (!catapult->IsAlive())
                                catapult->Respawn(true);
                        }
                    }

                    // we need to confirm this is blizzlike, not sure if it is every 3 minutes
                    for (uint8 u = (_nodePoint[i].faction == BG_TEAM_ALLIANCE ? BG_IC_NPC_GLAIVE_THROWER_1_A : BG_IC_NPC_GLAIVE_THROWER_1_H); u < (_nodePoint[i].faction == BG_TEAM_ALLIANCE ? BG_IC_NPC_GLAIVE_THROWER_2_A : BG_IC_NPC_GLAIVE_THROWER_2_H); u++)
                    {
                        if (Creature* glaiveThrower = GetCreature(u))
                        {
                            if (!glaiveThrower->IsAlive())
                                glaiveThrower->Respawn(true);
                        }
                    }

                    _docksTimer = DOCKS_UPDATE_TIME;
                } else docksTimer -= diff;
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
                        if (siege->IsAlive())
                        {
                            if (siege->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_UNK_14|UNIT_FLAG_IMMUNE_TO_PC))
                                // following sniffs the vehicle always has UNIT_FLAG_UNK_14
                                siege->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_IMMUNE_TO_PC);
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
                            if (!demolisher->IsAlive())
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
        for (uint8 i = 0; i < NODE_TYPE_DOCKS; ++i)
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
    DoorOpen(BG_IC_GO_DOODAD_ND_HUMAN_GATE_CLOSEDFX_DOOR02);
    DoorOpen(BG_IC_GO_DOODAD_ND_WINTERORC_WALL_GATEFX_DOOR02);
    DoorOpen(BG_IC_GO_DOODAD_ND_HUMAN_GATE_CLOSEDFX_DOOR03);
    DoorOpen(BG_IC_GO_DOODAD_ND_WINTERORC_WALL_GATEFX_DOOR03);
    else
        _resourceTimer -= diff;

    for (uint8 i = 0; i < MAX_FORTRESS_TELEPORTER_EFFECTS_SPAWNS; ++i)
        GetBGObject(BG_IC_TeleporterEffects[i].type)->SetGoState(GO_STATE_ACTIVE);
}

void BattlegroundIC::OnPlayerJoin(Player *plr)
{
    BattlegroundMap::OnPlayerJoin(plr);
    PlayerScores[player->GetGUID()] = new BattlegroundICScore(player->GetGUID(), player->GetBGTeam());
    PlayerScores[plr->GetGUIDLow()] = sc;
    if (nodePoint[NODE_TYPE_QUARRY].nodeState == (plr->GetTeamId() == TEAM_ALLIANCE ? NODE_STATE_CONTROLLED_A : NODE_STATE_CONTROLLED_H))

    if (_nodePoint[NODE_TYPE_REFINERY].nodeState == (plr->GetBGTeam() == BG_TEAM_ALLIANCE ? NODE_STATE_CONTROLLED_A : NODE_STATE_CONTROLLED_H))
        player->CastSpell(player, SPELL_QUARRY, true);

    if (nodePoint[NODE_TYPE_REFINERY].nodeState == (player->GetTeamId() == TEAM_ALLIANCE ? NODE_STATE_CONTROLLED_A : NODE_STATE_CONTROLLED_H))
        player->CastSpell(player, SPELL_OIL_REFINERY, true);
}

void BattlegroundIC::RemovePlayer(Player* player, ObjectGuid /*guid*/, uint32 /*team*/)
{
    if (player)
    {
        player->RemoveAura(SPELL_QUARRY);
        player->RemoveAura(SPELL_OIL_REFINERY);
    }
}

void BattlegroundIC::HandleAreaTrigger(Player* player, uint32 trigger)
{
    // this is wrong way to implement these things. On official it done by gameobject spell cast.
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    /// @hack: this spell should be cast by npc 22515 (World Trigger) and not by the player
    if (trigger == 5555 && player->GetTeamId() == TEAM_HORDE)
    {
    BattlegroundScoreMap::const_iterator itr = PlayerScores.find(Source->GetGUIDLow());
    if (itr == PlayerScores.end())                         // player not found...
        player->CastSpell(player, SPELL_BACK_DOOR_JOB_ACHIEVEMENT, true);
    }
    switch(type)
    {
        if (GateStatus[BG_IC_H_FRONT] != BG_IC_GATE_DESTROYED
            && GateStatus[BG_IC_H_WEST] != BG_IC_GATE_DESTROYED
            && GateStatus[BG_IC_H_EAST] != BG_IC_GATE_DESTROYED)
        player->CastSpell(player, SPELL_BACK_DOOR_JOB_ACHIEVEMENT, true);
            BattlegroundMap::UpdatePlayerScore(Source, type, value, doAddHonor);
    }
}

void BattlegroundIC::FillInitialWorldStates(WorldPacket& data)
{
    data << uint32(BG_IC_ALLIANCE_RENFORT_SET) << uint32(1);
    data << uint32(BG_IC_HORDE_RENFORT_SET) << uint32(1);
    data << uint32(BG_IC_ALLIANCE_RENFORT) << uint32(_factionReinforcements[BG_TEAM_ALLIANCE]);
    data << uint32(BG_IC_HORDE_RENFORT) << uint32(_factionReinforcements[BG_TEAM_HORDE]);

    for (uint8 i = 0; i < MAX_FORTRESS_GATES_SPAWNS; ++i)
    {
        uint32 uws = GetWorldStateFromGateEntry(BG_IC_ObjSpawnlocs[i].entry, (_gateStatus[GetGateIDFromEntry(BG_IC_ObjSpawnlocs[i].entry)] == BG_IC_GATE_DESTROYED ? true : false));
        data << uint32(uws) << uint32(1);
    }

    for (uint8 i = 0; i < MAX_NODE_TYPES; ++i)
        data << uint32(_nodePoint[i].worldStates[_nodePoint[i].nodeState]) << uint32(1);
}

void BattlegroundIC::OnUnitKill(Creature* unit, Player* killer)
{
    for (uint8 i = 0; i < MAX_NORMAL_GAMEOBJECTS_SPAWNS; ++i)
            sLog->outError("Isle of Conquest: There was an error spawning gameobject %u", BG_IC_ObjSpawnlocs[i].entry);
        if (!AddObject(BG_IC_Teleporters[i].type, BG_IC_Teleporters[i].entry, BG_IC_Teleporters[i].x, BG_IC_Teleporters[i].y, BG_IC_Teleporters[i].z, BG_IC_Teleporters[i].o, 0, 0, 0, 0, RESPAWN_ONE_DAY))
    if (!AddSpiritGuide(BG_IC_NPC_SPIRIT_GUIDE_1+5, BG_IC_SpiritGuidePos[5][0], BG_IC_SpiritGuidePos[5][1], BG_IC_SpiritGuidePos[5][2], BG_IC_SpiritGuidePos[5][3], ALLIANCE)
        {
            TC_LOG_ERROR("bg.battleground", "Isle of Conquest | Starting Event Open Doors: There was an error spawning gameobject %u", BG_IC_Teleporters[i].entry);
            return false;
        }
    }
    gunshipHorde = CreateTransport(GO_HORDE_GUNSHIP, TRANSPORT_PERIOD_TIME);
    gunshipAlliance = CreateTransport(GO_ALLIANCE_GUNSHIP, TRANSPORT_PERIOD_TIME);
        if (!AddCreature(BG_IC_NpcSpawnlocs[i].entry, BG_IC_NpcSpawnlocs[i].type, BG_IC_NpcSpawnlocs[i].x, BG_IC_NpcSpawnlocs[i].y, BG_IC_NpcSpawnlocs[i].z, BG_IC_NpcSpawnlocs[i].o, BG_IC_NpcSpawnlocs[i].team, RESPAWN_ONE_DAY))
        {
            TC_LOG_ERROR("bg.battleground", "Isle of Conquest: There was an error spawning creature %u", BG_IC_NpcSpawnlocs[i].entry);
            return false;
        }
    }
        || !AddSpiritGuide(BG_IC_NPC_SPIRIT_GUIDE_1+4, BG_IC_SpiritGuidePos[6], TEAM_HORDE)
        || !AddSpiritGuide(BG_IC_NPC_SPIRIT_GUIDE_1+5, BG_IC_SpiritGuidePos[7], TEAM_ALLIANCE)
        || !AddSpiritGuide(BG_IC_NPC_SPIRIT_GUIDE_1+6, BG_IC_SpiritGuidePos[8], TEAM_HORDE))
        TC_LOG_ERROR("bg.battleground", "Isle of Conquest: Failed to spawn initial spirit guide!");
    gunshipHorde = sTransportMgr->CreateTransport(GO_HORDE_GUNSHIP, UI64LIT(0), GetBgMap());
    gunshipAlliance = sTransportMgr->CreateTransport(GO_ALLIANCE_GUNSHIP, UI64LIT(0), GetBgMap());

    if (!gunshipAlliance || !gunshipHorde)
        TC_LOG_ERROR("bg.battleground", "Isle of Conquest: There was an error creating gunships!");
        return false;
    gunshipHorde->EnableMovement(false);
    gunshipAlliance->EnableMovement(false);

    for (uint8 i = BG_IC_NPC_KEEP_CANNON_13; i < BG_IC_NPC_KEEP_CANNON_25; i++)
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

                plr->TeleportTo(GetId(), ClosestGrave->x, ClosestGrave->y, ClosestGrave->z, plr->GetOrientation());
void BattlegroundIC::EventPlayerClickedOnFlag(Player* player, GameObject* target_obj)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    // All the node points are iterated to find the clicked one
    for (uint8 i = 0; i < MAX_NODE_TYPES; ++i)
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
            if (nodePoint[i].banners[BANNER_A_CONTESTED] == nextBanner ||
                nodePoint[i].banners[BANNER_H_CONTESTED] == nextBanner)
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
            } else if (nextBanner == nodePoint[i].banners[BANNER_A_CONTROLLED] ||
                       nextBanner == nodePoint[i].banners[BANNER_H_CONTROLLED])

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
    for (uint8 i = 0; i < 5; ++i)
    {
        if (nodePoint->worldStates[i] == worldstate)
            continue;
        UpdateWorldState(nodePoint->worldStates[i], 0);
    }

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
    TC_LOG_ERROR("bg.battleground", "Isle Of Conquest: Unexpected return in GetNextBanner function");
    return 0;
}

void BattlegroundIC::HandleContestedNodes(ICNodePoint* nodePoint)
{
    if (nodePoint->nodeType == NODE_TYPE_HANGAR)
    {
        if (_gunshipAlliance && _gunshipHorde)
            (nodePoint->faction == TEAM_ALLIANCE ? gunshipHorde : gunshipAlliance)->BuildStopMovePacket(GetBgMap());

        for (uint8 u = BG_IC_GO_HANGAR_TELEPORTER_1; u <= BG_IC_GO_HANGAR_TELEPORTER_3; ++u)
            DeleteGameObject(u);

        for (uint8 u = BG_IC_GO_HANGAR_TELEPORTER_EFFECT_1; u <= BG_IC_GO_HANGAR_TELEPORTER_EFFECT_3; ++u)
            DelObject(u);

        DelCreature(BG_IC_NPC_WORLD_TRIGGER_NOT_FLOATING);

        for (uint8 u = 0; u < MAX_CAPTAIN_SPAWNS_PER_FACTION; ++u)
        {
            uint8 type = BG_IC_NPC_GUNSHIP_CAPTAIN_1 + u;
            DelCreature(type);
        }

        std::list<Creature*> cannons;
        if (nodePoint->faction == TEAM_HORDE)
            gunshipAlliance->GetCreatureListWithEntryInGrid(cannons, NPC_ALLIANCE_GUNSHIP_CANNON, 150.0f);
        else
            gunshipHorde->GetCreatureListWithEntryInGrid(cannons, NPC_HORDE_GUNSHIP_CANNON, 150.0f);

        for (Creature* cannon : cannons)
        {
            cannon->GetVehicleKit()->RemoveAllPassengers();
            cannon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }
    }
    else if (nodePoint->nodeType == NODE_TYPE_WORKSHOP)
    {
        DelObject(BG_IC_GO_SEAFORIUM_BOMBS_1);
        DelObject(BG_IC_GO_SEAFORIUM_BOMBS_2);
    }
}

void BattlegroundIC::HandleCapturedNodes(ICNodePoint* nodePoint, bool recapture)
{
    if (nodePoint->nodeType != NODE_TYPE_REFINERY && nodePoint->nodeType != NODE_TYPE_QUARRY)
    {
        if (!AddSpiritGuide(BG_IC_NPC_SPIRIT_GUIDE_1+nodePoint->nodeType-2,
            TC_LOG_ERROR("bg.battleground", "Isle of Conquest: Failed to spawn spirit guide! point: %u, team: %u, ", nodePoint->nodeType, nodePoint->faction);
    }

    switch (nodePoint->gameobject_type)
    {
        case BG_IC_GO_HANGAR_BANNER:
            {
                if (!gunshipAlliance || !gunshipHorde)
                    break;

                std::list<Creature*> cannons;
                if (nodePoint->faction == TEAM_ALLIANCE)
                    gunshipAlliance->GetCreatureListWithEntryInGrid(cannons, NPC_ALLIANCE_GUNSHIP_CANNON, 150.0f);
                else
                    gunshipHorde->GetCreatureListWithEntryInGrid(cannons, NPC_HORDE_GUNSHIP_CANNON, 150.0f);

                for (Creature* cannon : cannons)
                    cannon->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                for (uint8 u = 0; u < MAX_HANGAR_TELEPORTERS_SPAWNS; ++u)
                {
                    uint8 type = BG_IC_GO_HANGAR_TELEPORTER_1 + u;
                    if (!AddObject(type, (nodePoint->faction == TEAM_ALLIANCE ? GO_ALLIANCE_GUNSHIP_PORTAL : GO_HORDE_GUNSHIP_PORTAL), BG_IC_HangarTeleporters[u], 0, 0, 0, 0, RESPAWN_ONE_DAY))
                        TC_LOG_ERROR("bg.battleground", "Isle of Conquest: There was an error spawning a gunship portal. Type: %u", BG_IC_GO_HANGAR_TELEPORTER_1 + u);
                }

                for (uint8 u = 0; u < MAX_HANGAR_TELEPORTER_EFFECTS_SPAWNS; ++u)
                {
                    uint8 type = BG_IC_GO_HANGAR_TELEPORTER_EFFECT_1 + u;
                    if (!AddObject(type, (nodePoint->faction == TEAM_ALLIANCE ? GO_ALLIANCE_GUNSHIP_PORTAL_EFFECTS : GO_HORDE_GUNSHIP_PORTAL_EFFECTS), BG_IC_HangarTeleporterEffects[u], 0, 0, 0, 0, RESPAWN_ONE_DAY, GO_STATE_ACTIVE))
                        TC_LOG_ERROR("bg.battleground", "Isle of Conquest: There was an error spawning a gunship portal effects. Type: %u", BG_IC_GO_HANGAR_TELEPORTER_1 + u);
                }

                for (uint8 u = 0; u < MAX_TRIGGER_SPAWNS_PER_FACTION; ++u)
                {
                    if (!AddCreature(NPC_WORLD_TRIGGER_NOT_FLOATING, BG_IC_NPC_WORLD_TRIGGER_NOT_FLOATING, BG_IC_HangarTrigger[nodePoint->faction], nodePoint->faction, RESPAWN_ONE_DAY, nodePoint->faction == TEAM_ALLIANCE ? gunshipAlliance : gunshipHorde))
                        TC_LOG_ERROR("bg.battleground", "Isle of Conquest: There was an error spawning a world trigger. Type: %u", BG_IC_NPC_WORLD_TRIGGER_NOT_FLOATING);
                }

                for (uint8 u = 0; u < MAX_CAPTAIN_SPAWNS_PER_FACTION; ++u)
                {
                    uint8 type = BG_IC_NPC_GUNSHIP_CAPTAIN_1 + u;

                    if (type == BG_IC_NPC_GUNSHIP_CAPTAIN_1)
                        if (AddCreature(nodePoint->faction == TEAM_ALLIANCE ? NPC_ALLIANCE_GUNSHIP_CAPTAIN : NPC_HORDE_GUNSHIP_CAPTAIN, type, BG_IC_HangarCaptains[nodePoint->faction == TEAM_ALLIANCE ? 2 : 0], nodePoint->faction, RESPAWN_ONE_DAY))
                            GetBGCreature(BG_IC_NPC_GUNSHIP_CAPTAIN_1)->GetAI()->DoAction(ACTION_GUNSHIP_READY);

                    if (type == BG_IC_NPC_GUNSHIP_CAPTAIN_2)
                        if (!AddCreature(nodePoint->faction == TEAM_ALLIANCE ? NPC_ALLIANCE_GUNSHIP_CAPTAIN : NPC_HORDE_GUNSHIP_CAPTAIN, type, BG_IC_HangarCaptains[nodePoint->faction == TEAM_ALLIANCE ? 3 : 1], nodePoint->faction, RESPAWN_ONE_DAY, nodePoint->faction == TEAM_ALLIANCE ? gunshipAlliance : gunshipHorde))
                            TC_LOG_ERROR("bg.battleground", "Isle of Conquest: There was an error spawning a world trigger. Type: %u", BG_IC_NPC_GUNSHIP_CAPTAIN_2);
                }

                (nodePoint->faction == TEAM_ALLIANCE ? gunshipAlliance : gunshipHorde)->EnableMovement(true);
                break;
            }
        case BG_IC_GO_QUARRY_BANNER:
            RemoveAuraOnTeam(SPELL_QUARRY, (nodePoint->faction == TEAM_ALLIANCE ? HORDE : ALLIANCE));
            CastSpellOnTeam(SPELL_QUARRY, (nodePoint->faction == TEAM_ALLIANCE ? ALLIANCE : HORDE));
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
        for (uint8 i = (nodePoint->faction == TEAM_ALLIANCE ? BG_IC_NPC_GLAIVE_THROWER_1_H : BG_IC_NPC_GLAIVE_THROWER_1_A); i < (nodePoint->faction == TEAM_ALLIANCE ? BG_IC_NPC_GLAIVE_THROWER_2_H : BG_IC_NPC_GLAIVE_THROWER_2_A); i++)
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
                        DelCreature(i);
                    }
                }
            }

            // spawning glaive throwers
            for (uint8 i = 0; i < MAX_GLAIVE_THROWERS_SPAWNS_PER_FACTION; ++i)
            {
                uint8 type = (nodePoint->faction == TEAM_ALLIANCE ? BG_IC_NPC_GLAIVE_THROWER_1_A : BG_IC_NPC_GLAIVE_THROWER_1_H)+i;

            if (GetCreature(type) && GetCreature(type)->isAlive())
                    continue;

            if (AddCreature(nodePoint->faction == BG_TEAM_ALLIANCE ? NPC_GLAIVE_THROWER_A : NPC_GLAIVE_THROWER_H, type, nodePoint->faction,
                    GetCreature(type)->setFaction(BG_IC_Factions[(nodePoint->faction == BG_TEAM_ALLIANCE ? 0 : 1)]);
            }

            // spawning catapults
            for (uint8 i = 0; i < MAX_CATAPULTS_SPAWNS_PER_FACTION; ++i)
            {
            uint8 type = (nodePoint->faction == BG_TEAM_ALLIANCE ? BG_IC_NPC_CATAPULT_1_A : BG_IC_NPC_CATAPULT_1_H)+i;

            if (GetCreature(type) && GetCreature(type)->isAlive())
                    continue;

                if (AddCreature(NPC_CATAPULT, type, BG_IC_DocksVehiclesCatapults[i], nodePoint->faction, RESPAWN_ONE_DAY))
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
                        if (Creature* demolisher = GetBGCreature(i, false))
                        {
                            if (Vehicle* vehicleDemolisher = demolisher->GetVehicleKit())
                            {
                                // is IsVehicleInUse working as expected?
                                if (!vehicleDemolisher->IsVehicleInUse())
                                    DelCreature(i);
                            }
                        }
                    }

                    for (uint8 i = 0; i < MAX_DEMOLISHERS_SPAWNS_PER_FACTION; ++i)
                    {
                    uint8 type = (nodePoint->faction == BG_TEAM_ALLIANCE ? BG_IC_NPC_DEMOLISHER_1_A : BG_IC_NPC_DEMOLISHER_1_H)+i;

                    if (GetBGCreature(type) && GetBGCreature(type)->isAlive())
                            continue;

                        if (AddCreature(NPC_DEMOLISHER, type, BG_IC_WorkshopVehicles[i], nodePoint->faction, RESPAWN_ONE_DAY))
                            GetBGCreature(type)->setFaction(BG_IC_Factions[(nodePoint->faction == TEAM_ALLIANCE ? 0 : 1)]);
                    }

                    // we check if the opossing siege engine is in use
                int8 enemySiege = (nodePoint->faction == BG_TEAM_ALLIANCE ? BG_IC_NPC_SIEGE_ENGINE_H : BG_IC_NPC_SIEGE_ENGINE_A);

                if (Creature* siegeEngine = GetBGCreature(enemySiege))
                    {
                        if (Vehicle* vehicleSiege = siegeEngine->GetVehicleKit())
                        {
                            // is VehicleInUse working as expected ?
                            if (!vehicleSiege->IsVehicleInUse())
                            DeleteCreature(enemySiege);
                        }
                    }

                    uint8 siegeType = (nodePoint->faction == TEAM_ALLIANCE ? BG_IC_NPC_SIEGE_ENGINE_A : BG_IC_NPC_SIEGE_ENGINE_H);
                if (!GetCreature(siegeType) || !GetCreature(siegeType)->isAlive())
                    {
                    AddCreature((nodePoint->faction == TEAM_ALLIANCE ? NPC_SIEGE_ENGINE_A : NPC_SIEGE_ENGINE_H), siegeType, nodePoint->faction,
                            BG_IC_WorkshopVehicles[4], nodePoint->faction, RESPAWN_ONE_DAY);

                    if (Creature* siegeEngine = GetCreature(siegeType))
                        {
                            siegeEngine->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_UNK_14|UNIT_FLAG_IMMUNE_TO_PC);
                            siegeEngine->setFaction(BG_IC_Factions[(nodePoint->faction == TEAM_ALLIANCE ? 0 : 1)]);
                        }
                    }
                }

                for (uint8 i = 0; i < MAX_WORKSHOP_BOMBS_SPAWNS_PER_FACTION; ++i)
                {
                AddGameObject(BG_IC_GO_SEAFORIUM_BOMBS_1+i, GO_SEAFORIUM_BOMBS,
                    workshopBombs[i].GetPositionX(), workshopBombs[i].GetPositionY(),
                    workshopBombs[i].GetPositionZ(), workshopBombs[i].GetOrientation(),
                    0, 0, 0, 0, 10);

                if (GameObject* seaforiumBombs = GetBGObject(BG_IC_GO_SEAFORIUM_BOMBS_1+i))
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

void BattlegroundIC::DestroyGate(Player* player, GameObject* go)
{
    _gateStatus[GetGateIDFromEntry(go->GetEntry())] = BG_IC_GATE_DESTROYED;
    uint32 uws_open = GetWorldStateFromGateEntry(go->GetEntry(), true);
    uint32 uws_close = GetWorldStateFromGateEntry(go->GetEntry(), false);
    if (uws_open)
    {
        UpdateWorldState(uws_close, 0);
        UpdateWorldState(uws_open, 1);
    }
    if (player->GetTeamId() == TEAM_ALLIANCE)
    {
        DoorOpen(BG_IC_GO_HORDE_KEEP_PORTCULLIS);
        GetBGObject(BG_IC_GO_HORDE_BANNER)->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
    }
    else
    {
        DoorOpen(BG_IC_GO_DOODAD_PORTCULLISACTIVE02);
        GetBGObject(BG_IC_GO_ALLIANCE_BANNER)->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
    }

    uint32 lang_entry = 0;

    switch (go->GetEntry())
    {
        case GO_HORDE_GATE_1:
            lang_entry = LANG_BG_IC_NORTH_GATE_DESTROYED;
            break;
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

    SendMessage2ToAll(lang_entry, CHAT_MSG_BG_SYSTEM_NEUTRAL, NULL, (pl->GetTeamId() == TEAM_ALLIANCE ? LANG_BG_IC_HORDE_KEEP : LANG_BG_IC_ALLIANCE_KEEP));
    {
        if (!GetBgMap()->GetCreature(BgCreatures[BG_IC_NpcSpawnlocs[BG_IC_NPC_OVERLORD_AGMAR].type]) && !AddCreature(BG_IC_NpcSpawnlocs[BG_IC_NPC_OVERLORD_AGMAR].entry, BG_IC_NpcSpawnlocs[BG_IC_NPC_OVERLORD_AGMAR].type, BG_IC_NpcSpawnlocs[BG_IC_NPC_OVERLORD_AGMAR].x, BG_IC_NpcSpawnlocs[BG_IC_NPC_OVERLORD_AGMAR].y, BG_IC_NpcSpawnlocs[BG_IC_NPC_OVERLORD_AGMAR].z, BG_IC_NpcSpawnlocs[BG_IC_NPC_OVERLORD_AGMAR].o, BG_IC_NpcSpawnlocs[BG_IC_NPC_OVERLORD_AGMAR].team, RESPAWN_ONE_DAY))
            TC_LOG_ERROR("bg.battleground", "Isle of Conquest: There was an error spawning creature %u", BG_IC_NpcSpawnlocs[BG_IC_NPC_OVERLORD_AGMAR].entry);
    else if (go->GetEntry() == GO_ALLIANCE_GATE_1 || go->GetEntry() == GO_ALLIANCE_GATE_2 || go->GetEntry() == GO_ALLIANCE_GATE_3)
        if (!GetBgMap()->GetCreature(BgCreatures[BG_IC_NpcSpawnlocs[BG_IC_NPC_HIGH_COMMANDER_HALFORD_WYRMBANE].type]) && !AddCreature(BG_IC_NpcSpawnlocs[BG_IC_NPC_HIGH_COMMANDER_HALFORD_WYRMBANE].entry, BG_IC_NpcSpawnlocs[BG_IC_NPC_HIGH_COMMANDER_HALFORD_WYRMBANE].type, BG_IC_NpcSpawnlocs[BG_IC_NPC_HIGH_COMMANDER_HALFORD_WYRMBANE].x, BG_IC_NpcSpawnlocs[BG_IC_NPC_HIGH_COMMANDER_HALFORD_WYRMBANE].y, BG_IC_NpcSpawnlocs[BG_IC_NPC_HIGH_COMMANDER_HALFORD_WYRMBANE].z, BG_IC_NpcSpawnlocs[BG_IC_NPC_HIGH_COMMANDER_HALFORD_WYRMBANE].o, BG_IC_NpcSpawnlocs[BG_IC_NPC_HIGH_COMMANDER_HALFORD_WYRMBANE].team, RESPAWN_ONE_DAY))
            TC_LOG_ERROR("bg.battleground", "Isle of Conquest: There was an error spawning creature %u", BG_IC_NpcSpawnlocs[BG_IC_NPC_HIGH_COMMANDER_HALFORD_WYRMBANE].entry);
    }
    SendMessage2ToAll(lang_entry, CHAT_MSG_BG_SYSTEM_NEUTRAL, NULL, (player->GetTeamId() == TEAM_ALLIANCE ? LANG_BG_IC_HORDE_KEEP : LANG_BG_IC_ALLIANCE_KEEP));
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
        float player_x = player->GetPositionX();
        float player_y = player->GetPositionY();

        float mindist = 999999.0f;
        for (uint8 i = 0; i < nodes.size(); ++i)
        {
            WorldSafeLocsEntry const*entry = sWorldSafeLocsStore.LookupEntry(BG_IC_GraveyardIds[nodes[i]]);
            if (!entry)
                continue;
            float dist = (entry->Loc.X - player_x)*(entry->Loc.X - player_x)+(entry->Loc.Y - player_y)*(entry->Loc.Y - player_y);
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

bool BattlegroundIC::IsAllNodesControlledByTeam(uint32 team) const
{
    uint32 count = 0;
    ICNodeState controlledState = team == ALLIANCE ? NODE_STATE_CONTROLLED_A : NODE_STATE_CONTROLLED_H;
    for (int i = 0; i < NODE_TYPE_WORKSHOP; ++i)
    {
        if (nodePoint[i].nodeState == controlledState)
            ++count;
    }

    return count == NODE_TYPE_WORKSHOP;
}

bool BattlegroundIC::IsSpellAllowed(uint32 spellId, Player const* player) const
{
    switch (spellId)
    {
        case SPELL_OIL_REFINERY:
        case SPELL_QUARRY:
        {
            uint32 team = player->GetTeamId();
            uint8 nodeType = spellId == SPELL_OIL_REFINERY ? NODE_TYPE_REFINERY : NODE_TYPE_QUARRY;
            uint8 nodeState = team == TEAM_ALLIANCE ? NODE_STATE_CONTROLLED_A : NODE_STATE_CONTROLLED_H;
            return GetNodeState(nodeType) == nodeState;
        }
        default:
           break;
    }

    return true;
    t->SetMap(GetBgMap());
}

void BattlegroundIC::InitializeTextIds()
{
    PreparationPhaseTextIds[BG_STARTING_EVENT_FIRST]  = LANG_BG_IC_START_TWO_MINUTES;
    PreparationPhaseTextIds[BG_STARTING_EVENT_SECOND] = LANG_BG_IC_START_ONE_MINUTE;
    PreparationPhaseTextIds[BG_STARTING_EVENT_THIRD]  = LANG_BG_IC_START_HALF_MINUTE;
    PreparationPhaseTextIds[BG_STARTING_EVENT_FOURTH] = LANG_BG_IC_HAS_BEGUN;
}
