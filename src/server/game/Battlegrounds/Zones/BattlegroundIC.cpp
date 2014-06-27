/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "Battleground.h"
#include "BattlegroundIC.h"
#include "Language.h"
#include "WorldPacket.h"
#include "GameObject.h"
#include "ObjectMgr.h"
#include "Vehicle.h"
#include "Transport.h"
#include "WorldSession.h"

BattlegroundIC::BattlegroundIC()
{
    BgObjects.resize(MAX_NORMAL_GAMEOBJECTS_SPAWNS + MAX_AIRSHIPS_SPAWNS + MAX_HANGAR_TELEPORTERS_SPAWNS + MAX_FORTRESS_TELEPORTERS_SPAWNS);
    BgCreatures.resize(MAX_NORMAL_NPCS_SPAWNS + MAX_WORKSHOP_SPAWNS + MAX_DOCKS_SPAWNS + MAX_SPIRIT_GUIDES_SPAWNS);

    StartMessageIds[BG_STARTING_EVENT_FIRST]  = LANG_BG_IC_START_TWO_MINUTES;
    StartMessageIds[BG_STARTING_EVENT_SECOND] = LANG_BG_IC_START_ONE_MINUTE;
    StartMessageIds[BG_STARTING_EVENT_THIRD]  = LANG_BG_IC_START_HALF_MINUTE;
    StartMessageIds[BG_STARTING_EVENT_FOURTH] = LANG_BG_IC_HAS_BEGUN;

    for (uint8 i = 0; i < 2; ++i)
        factionReinforcements[i] = MAX_REINFORCEMENTS;

    for (uint8 i = 0; i < BG_IC_MAXDOOR; ++i)
        GateStatus[i] = BG_IC_GATE_OK;

    closeFortressDoorsTimer = CLOSE_DOORS_TIME; // the doors are closed again... in a special way
    doorsClosed = false;
    docksTimer = DOCKS_UPDATE_TIME;
    resourceTimer = IC_RESOURCE_TIME;

    for (uint8 i = NODE_TYPE_REFINERY; i < MAX_NODE_TYPES; ++i)
        nodePoint[i] = nodePointInitial[i];

    siegeEngineWorkshopTimer = WORKSHOP_UPDATE_TIME;

    gunshipHorde = NULL;
    gunshipAlliance = NULL;
}

BattlegroundIC::~BattlegroundIC() { }

void BattlegroundIC::HandlePlayerResurrect(Player* player)
{
    if (nodePoint[NODE_TYPE_QUARRY].nodeState == (player->GetTeamId() == TEAM_ALLIANCE ? NODE_STATE_CONTROLLED_A : NODE_STATE_CONTROLLED_H))
        player->CastSpell(player, SPELL_QUARRY, true);

    if (nodePoint[NODE_TYPE_REFINERY].nodeState == (player->GetTeamId() == TEAM_ALLIANCE ? NODE_STATE_CONTROLLED_A : NODE_STATE_CONTROLLED_H))
        player->CastSpell(player, SPELL_OIL_REFINERY, true);
}

void BattlegroundIC::DoAction(uint32 action, uint64 var)
{
    if (action != ACTION_TELEPORT_PLAYER_TO_TRANSPORT)
        return;

    if (!gunshipAlliance || !gunshipHorde)
        return;

    Player* player = ObjectAccessor::FindPlayer(var);
    if (!player)
        return;

    (player->GetTeamId() == TEAM_ALLIANCE ? gunshipAlliance : gunshipHorde)->AddPassenger(player);

    player->m_movementInfo.transport.pos.m_positionX = TransportMovementInfo.GetPositionX();
    player->m_movementInfo.transport.pos.m_positionY = TransportMovementInfo.GetPositionY();
    player->m_movementInfo.transport.pos.m_positionZ = TransportMovementInfo.GetPositionZ();

    if (player->TeleportTo(GetMapId(), TeleportToTransportPosition.GetPositionX(),
                        TeleportToTransportPosition.GetPositionY(),
                        TeleportToTransportPosition.GetPositionZ(),
                        TeleportToTransportPosition.GetOrientation(),
                        TELE_TO_NOT_LEAVE_TRANSPORT))
    {
        player->CastSpell(player, SPELL_PARACHUTE, true); // this must be changed, there is a trigger in each transport that casts the spell.
        player->CastSpell(player, SPELL_SLOW_FALL, true);
    }
}

void BattlegroundIC::PostUpdateImpl(uint32 diff)
{

    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    if (!doorsClosed)
    {
        if (closeFortressDoorsTimer <= diff)
        {
            GetBGObject(BG_IC_GO_DOODAD_ND_HUMAN_GATE_CLOSEDFX_DOOR01)->RemoveFromWorld();
            GetBGObject(BG_IC_GO_DOODAD_ND_WINTERORC_WALL_GATEFX_DOOR01)->RemoveFromWorld();

            GetBGObject(BG_IC_GO_ALLIANCE_GATE_3)->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED); // Alliance door
            GetBGObject(BG_IC_GO_HORDE_GATE_1)->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED); // Horde door

            doorsClosed = true;
        } else closeFortressDoorsTimer -= diff;
    }

    for (uint8 i = NODE_TYPE_REFINERY; i < MAX_NODE_TYPES; ++i)
    {
        if (nodePoint[i].nodeType == NODE_TYPE_DOCKS)
        {
            if (nodePoint[i].nodeState == NODE_STATE_CONTROLLED_A ||
                nodePoint[i].nodeState == NODE_STATE_CONTROLLED_H)
            {
                if (docksTimer <= diff)
                {
                    // we need to confirm this, i am not sure if this every 3 minutes
                    for (uint8 u = (nodePoint[i].faction == TEAM_ALLIANCE ? BG_IC_NPC_CATAPULT_1_A : BG_IC_NPC_CATAPULT_1_H); u < (nodePoint[i].faction  == TEAM_ALLIANCE ? BG_IC_NPC_CATAPULT_4_A : BG_IC_NPC_CATAPULT_4_H); ++u)
                    {
                        if (Creature* catapult = GetBGCreature(u))
                        {
                            if (!catapult->IsAlive())
                                catapult->Respawn(true);
                        }
                    }

                    // we need to confirm this is blizzlike, not sure if it is every 3 minutes
                    for (uint8 u = (nodePoint[i].faction == TEAM_ALLIANCE ? BG_IC_NPC_GLAIVE_THROWER_1_A : BG_IC_NPC_GLAIVE_THROWER_1_H); u < (nodePoint[i].faction == TEAM_ALLIANCE ? BG_IC_NPC_GLAIVE_THROWER_2_A : BG_IC_NPC_GLAIVE_THROWER_2_H); ++u)
                    {
                        if (Creature* glaiveThrower = GetBGCreature(u))
                        {
                            if (!glaiveThrower->IsAlive())
                                glaiveThrower->Respawn(true);
                        }
                    }

                    docksTimer = DOCKS_UPDATE_TIME;
                } else docksTimer -= diff;
            }
        }

        if (nodePoint[i].nodeType == NODE_TYPE_WORKSHOP)
        {
            if (nodePoint[i].nodeState == NODE_STATE_CONTROLLED_A ||
                nodePoint[i].nodeState == NODE_STATE_CONTROLLED_H)
            {
                if (siegeEngineWorkshopTimer <= diff)
                {
                    uint8 siegeType = (nodePoint[i].faction == TEAM_ALLIANCE ? BG_IC_NPC_SIEGE_ENGINE_A : BG_IC_NPC_SIEGE_ENGINE_H);

                    if (Creature* siege = GetBGCreature(siegeType)) // this always should be true
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
                    for (uint8 u = (nodePoint[i].faction == TEAM_ALLIANCE ? BG_IC_NPC_DEMOLISHER_1_A : BG_IC_NPC_DEMOLISHER_1_H); u < (nodePoint[i].faction == TEAM_ALLIANCE ? BG_IC_NPC_DEMOLISHER_4_A : BG_IC_NPC_DEMOLISHER_4_H); ++u)
                    {
                        if (Creature* demolisher = GetBGCreature(u))
                        {
                            if (!demolisher->IsAlive())
                                demolisher->Respawn(true);
                        }
                    }
                    siegeEngineWorkshopTimer = WORKSHOP_UPDATE_TIME;
                } else siegeEngineWorkshopTimer -= diff;
            }
        }

        // the point is waiting for a change on its banner
        if (nodePoint[i].needChange)
        {
            if (nodePoint[i].timer <= diff)
            {
                uint32 nextBanner = GetNextBanner(&nodePoint[i], nodePoint[i].faction, true);

                nodePoint[i].last_entry = nodePoint[i].gameobject_entry;
                nodePoint[i].gameobject_entry = nextBanner;
                // nodePoint[i].faction = the faction should be the same one...

                GameObject* banner = GetBGObject(nodePoint[i].gameobject_type);

                if (!banner) // this should never happen
                    return;

                float cords[4] = {banner->GetPositionX(), banner->GetPositionY(), banner->GetPositionZ(), banner->GetOrientation() };

                DelObject(nodePoint[i].gameobject_type);
                AddObject(nodePoint[i].gameobject_type, nodePoint[i].gameobject_entry, cords[0], cords[1], cords[2], cords[3], 0, 0, 0, 0, RESPAWN_ONE_DAY);

                GetBGObject(nodePoint[i].gameobject_type)->SetUInt32Value(GAMEOBJECT_FACTION, nodePoint[i].faction == TEAM_ALLIANCE ? BG_IC_Factions[1] : BG_IC_Factions[0]);

                UpdateNodeWorldState(&nodePoint[i]);
                HandleCapturedNodes(&nodePoint[i], false);

                SendMessage2ToAll(LANG_BG_IC_TEAM_HAS_TAKEN_NODE, CHAT_MSG_BG_SYSTEM_NEUTRAL, NULL, (nodePoint[i].faction == TEAM_ALLIANCE ? LANG_BG_IC_ALLIANCE : LANG_BG_IC_HORDE), nodePoint[i].string);

                nodePoint[i].needChange = false;
                nodePoint[i].timer = BANNER_STATE_CHANGE_TIME;
            } else nodePoint[i].timer -= diff;
        }
    }

    if (resourceTimer <= diff)
    {
        for (uint8 i = 0; i < NODE_TYPE_DOCKS; ++i)
        {
            if (nodePoint[i].nodeState == NODE_STATE_CONTROLLED_A ||
                nodePoint[i].nodeState == NODE_STATE_CONTROLLED_H)
            {
                factionReinforcements[nodePoint[i].faction] += 1;
                RewardHonorToTeam(RESOURCE_HONOR_AMOUNT, nodePoint[i].faction == TEAM_ALLIANCE ? ALLIANCE : HORDE);
                UpdateWorldState((nodePoint[i].faction == TEAM_ALLIANCE ? BG_IC_ALLIANCE_RENFORT : BG_IC_HORDE_RENFORT), factionReinforcements[nodePoint[i].faction]);
            }
        }
        resourceTimer = IC_RESOURCE_TIME;
    } else resourceTimer -= diff;
}

void BattlegroundIC::StartingEventCloseDoors()
{
    // Show Full Gate Displays
    GetBGObject(BG_IC_GO_ALLIANCE_GATE_1)->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED); // Alliance door
    GetBGObject(BG_IC_GO_ALLIANCE_GATE_2)->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED); // Alliance door
    GetBGObject(BG_IC_GO_HORDE_GATE_2)->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED); // Horde door
    GetBGObject(BG_IC_GO_HORDE_GATE_3)->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED); // Horde door
}

void BattlegroundIC::StartingEventOpenDoors()
{
    //after 20 seconds they should be despawned
    DoorOpen(BG_IC_GO_DOODAD_ND_HUMAN_GATE_CLOSEDFX_DOOR01);
    DoorOpen(BG_IC_GO_DOODAD_ND_WINTERORC_WALL_GATEFX_DOOR01);

    DoorOpen(BG_IC_GO_DOODAD_HU_PORTCULLIS01_1);
    DoorOpen(BG_IC_GO_DOODAD_HU_PORTCULLIS01_2);
    DoorOpen(BG_IC_GO_DOODAD_VR_PORTCULLIS01_1);
    DoorOpen(BG_IC_GO_DOODAD_VR_PORTCULLIS01_2);

    for (uint8 i = 0; i < MAX_FORTRESS_TELEPORTERS_SPAWNS; ++i)
    {
        if (!AddObject(BG_IC_Teleporters[i].type, BG_IC_Teleporters[i].entry,
                       BG_IC_Teleporters[i].x, BG_IC_Teleporters[i].y,
                       BG_IC_Teleporters[i].z, BG_IC_Teleporters[i].o,
                       0, 0, 0, 0, RESPAWN_ONE_DAY))
        {
            TC_LOG_ERROR("bg.battleground", "Isle of Conquest | Starting Event Open Doors: There was an error spawning gameobject %u", BG_IC_Teleporters[i].entry);
        }
    }
}

void BattlegroundIC::AddPlayer(Player* player)
{
    Battleground::AddPlayer(player);
    PlayerScores[player->GetGUIDLow()] = new BattlegroundICScore(player->GetGUID());

    if (nodePoint[NODE_TYPE_QUARRY].nodeState == (player->GetTeamId() == TEAM_ALLIANCE ? NODE_STATE_CONTROLLED_A : NODE_STATE_CONTROLLED_H))
        player->CastSpell(player, SPELL_QUARRY, true);

    if (nodePoint[NODE_TYPE_REFINERY].nodeState == (player->GetTeamId() == TEAM_ALLIANCE ? NODE_STATE_CONTROLLED_A : NODE_STATE_CONTROLLED_H))
        player->CastSpell(player, SPELL_OIL_REFINERY, true);
}

void BattlegroundIC::RemovePlayer(Player* player, uint64 /*guid*/, uint32 /*team*/)
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
        if (GateStatus[BG_IC_A_FRONT] != BG_IC_GATE_DESTROYED
            && GateStatus[BG_IC_A_WEST] != BG_IC_GATE_DESTROYED
            && GateStatus[BG_IC_A_EAST] != BG_IC_GATE_DESTROYED)
        player->CastSpell(player, SPELL_BACK_DOOR_JOB_ACHIEVEMENT, true);
    }
    else if (trigger == 5535 && player->GetTeamId() == TEAM_ALLIANCE)
    {
        if (GateStatus[BG_IC_H_FRONT] != BG_IC_GATE_DESTROYED
            && GateStatus[BG_IC_H_WEST] != BG_IC_GATE_DESTROYED
            && GateStatus[BG_IC_H_EAST] != BG_IC_GATE_DESTROYED)
        player->CastSpell(player, SPELL_BACK_DOOR_JOB_ACHIEVEMENT, true);
    }
}

void BattlegroundIC::FillInitialWorldStates(WorldPacket& data)
{
    data << uint32(BG_IC_ALLIANCE_RENFORT_SET) << uint32(1);
    data << uint32(BG_IC_HORDE_RENFORT_SET) << uint32(1);
    data << uint32(BG_IC_ALLIANCE_RENFORT) << uint32(factionReinforcements[TEAM_ALLIANCE]);
    data << uint32(BG_IC_HORDE_RENFORT) << uint32(factionReinforcements[TEAM_HORDE]);

    for (uint8 i = 0; i < MAX_FORTRESS_GATES_SPAWNS; ++i)
    {
        uint32 uws = GetWorldStateFromGateEntry(BG_IC_ObjSpawnlocs[i].entry, (GateStatus[GetGateIDFromEntry(BG_IC_ObjSpawnlocs[i].entry)] == BG_IC_GATE_DESTROYED ? true : false));
        data << uint32(uws) << uint32(1);
    }

    for (uint8 i = 0; i < MAX_NODE_TYPES; ++i)
        data << uint32(nodePoint[i].worldStates[nodePoint[i].nodeState]) << uint32(1);
}

bool BattlegroundIC::SetupBattleground()
{
    for (uint8 i = 0; i < MAX_NORMAL_GAMEOBJECTS_SPAWNS; ++i)
    {
        if (!AddObject(BG_IC_ObjSpawnlocs[i].type, BG_IC_ObjSpawnlocs[i].entry,
            BG_IC_ObjSpawnlocs[i].x, BG_IC_ObjSpawnlocs[i].y,
            BG_IC_ObjSpawnlocs[i].z, BG_IC_ObjSpawnlocs[i].o,
            0, 0, 0, 0, RESPAWN_ONE_DAY))
        {
            TC_LOG_ERROR("bg.battleground", "Isle of Conquest: There was an error spawning gameobject %u", BG_IC_ObjSpawnlocs[i].entry);
            return false;
        }
    }

    for (uint8 i = 2; i < MAX_NORMAL_NPCS_SPAWNS; ++i)
    {
        if (!AddCreature(BG_IC_NpcSpawnlocs[i].entry, BG_IC_NpcSpawnlocs[i].type,
            BG_IC_NpcSpawnlocs[i].x, BG_IC_NpcSpawnlocs[i].y,
            BG_IC_NpcSpawnlocs[i].z, BG_IC_NpcSpawnlocs[i].o,
            BG_IC_NpcSpawnlocs[i].team, RESPAWN_ONE_DAY))
        {
            TC_LOG_ERROR("bg.battleground", "Isle of Conquest: There was an error spawning creature %u", BG_IC_NpcSpawnlocs[i].entry);
            return false;
        }
    }

    if (!AddSpiritGuide(BG_IC_NPC_SPIRIT_GUIDE_1+5, BG_IC_SpiritGuidePos[5], TEAM_ALLIANCE)
        || !AddSpiritGuide(BG_IC_NPC_SPIRIT_GUIDE_1+6, BG_IC_SpiritGuidePos[6], TEAM_HORDE)
        || !AddSpiritGuide(BG_IC_NPC_SPIRIT_GUIDE_1+3, BG_IC_SpiritGuidePos[7], TEAM_ALLIANCE)
        || !AddSpiritGuide(BG_IC_NPC_SPIRIT_GUIDE_1+4, BG_IC_SpiritGuidePos[8], TEAM_HORDE))
    {
        TC_LOG_ERROR("bg.battleground", "Isle of Conquest: Failed to spawn initial spirit guide!");
        return false;
    }

    gunshipHorde = sTransportMgr->CreateTransport(GO_HORDE_GUNSHIP, 0, GetBgMap());
    gunshipAlliance = sTransportMgr->CreateTransport(GO_ALLIANCE_GUNSHIP, 0, GetBgMap());

    if (!gunshipAlliance || !gunshipHorde)
    {
        TC_LOG_ERROR("bg.battleground", "Isle of Conquest: There was an error creating gunships!");
        return false;
    }

    gunshipHorde->EnableMovement(false);
    gunshipAlliance->EnableMovement(false);

    // setting correct factions for Keep Cannons
    for (uint8 i = BG_IC_NPC_KEEP_CANNON_1; i < BG_IC_NPC_KEEP_CANNON_12; ++i)
        GetBGCreature(i)->setFaction(BG_IC_Factions[0]);
    for (uint8 i = BG_IC_NPC_KEEP_CANNON_13; i < BG_IC_NPC_KEEP_CANNON_25; ++i)
        GetBGCreature(i)->setFaction(BG_IC_Factions[1]);

    // correcting spawn time for keeps bombs
    for (uint8 i = BG_IC_GO_HUGE_SEAFORIUM_BOMBS_A_1; i < BG_IC_GO_HUGE_SEAFORIUM_BOMBS_H_4; ++i)
        GetBGObject(i)->SetRespawnTime(10);

    return true;
}

void BattlegroundIC::HandleKillUnit(Creature* unit, Player* killer)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
       return;

    uint32 entry = unit->GetEntry();
    if (entry == NPC_HIGH_COMMANDER_HALFORD_WYRMBANE)
    {
        RewardHonorToTeam(WINNER_HONOR_AMOUNT, HORDE);
        EndBattleground(HORDE);
    }
    else if (entry == NPC_OVERLORD_AGMAR)
    {
        RewardHonorToTeam(WINNER_HONOR_AMOUNT, ALLIANCE);
        EndBattleground(ALLIANCE);
    }

    //Achievement Mowed Down
    // TO-DO: This should be done on the script of each vehicle of the BG.
    if (unit->IsVehicle())
        killer->CastSpell(killer, SPELL_DESTROYED_VEHICLE_ACHIEVEMENT, true);
}

void BattlegroundIC::HandleKillPlayer(Player* player, Player* killer)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    Battleground::HandleKillPlayer(player, killer);

    factionReinforcements[player->GetTeamId()] -= 1;

    UpdateWorldState((player->GetTeamId() == TEAM_ALLIANCE ? BG_IC_ALLIANCE_RENFORT : BG_IC_HORDE_RENFORT), factionReinforcements[player->GetTeamId()]);

    // we must end the battleground
    if (factionReinforcements[player->GetTeamId()] < 1)
        EndBattleground(killer->GetTeam());
}

void BattlegroundIC::EndBattleground(uint32 winner)
{
    SendMessage2ToAll(LANG_BG_IC_TEAM_WINS, CHAT_MSG_BG_SYSTEM_NEUTRAL, NULL, (winner == ALLIANCE ? LANG_BG_IC_ALLIANCE : LANG_BG_IC_HORDE));

    Battleground::EndBattleground(winner);
}

void BattlegroundIC::EventPlayerClickedOnFlag(Player* player, GameObject* target_obj)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    // All the node points are iterated to find the clicked one
    for (uint8 i = 0; i < MAX_NODE_TYPES; ++i)
    {
        if (nodePoint[i].gameobject_entry == target_obj->GetEntry())
        {
            // THIS SHOULD NEEVEER HAPPEN
            if (nodePoint[i].faction == player->GetTeamId())
                return;

            uint32 nextBanner = GetNextBanner(&nodePoint[i], player->GetTeamId(), false);

            // we set the new settings of the nodePoint
            nodePoint[i].faction = player->GetTeamId();
            nodePoint[i].last_entry = nodePoint[i].gameobject_entry;
            nodePoint[i].gameobject_entry = nextBanner;

            // this is just needed if the next banner is grey
            if (nodePoint[i].banners[BANNER_A_CONTESTED] == nextBanner ||
                nodePoint[i].banners[BANNER_H_CONTESTED] == nextBanner)
            {
                nodePoint[i].timer = BANNER_STATE_CHANGE_TIME; // 1 minute for last change (real faction banner)
                nodePoint[i].needChange = true;

                RelocateDeadPlayers(BgCreatures[BG_IC_NPC_SPIRIT_GUIDE_1 + nodePoint[i].nodeType - 2]);

                // if we are here means that the point has been lost, or it is the first capture

                if (nodePoint[i].nodeType != NODE_TYPE_REFINERY && nodePoint[i].nodeType != NODE_TYPE_QUARRY)
                    if (BgCreatures[BG_IC_NPC_SPIRIT_GUIDE_1+(nodePoint[i].nodeType)-2])
                        DelCreature(BG_IC_NPC_SPIRIT_GUIDE_1+(nodePoint[i].nodeType)-2);

                UpdatePlayerScore(player, SCORE_BASES_ASSAULTED, 1);

                SendMessage2ToAll(LANG_BG_IC_TEAM_ASSAULTED_NODE_1, CHAT_MSG_BG_SYSTEM_NEUTRAL, player, nodePoint[i].string);
                SendMessage2ToAll(LANG_BG_IC_TEAM_ASSAULTED_NODE_2, CHAT_MSG_BG_SYSTEM_NEUTRAL, player, nodePoint[i].string, (player->GetTeamId() == TEAM_ALLIANCE ? LANG_BG_IC_ALLIANCE : LANG_BG_IC_HORDE));
                HandleContestedNodes(&nodePoint[i]);
            } else if (nextBanner == nodePoint[i].banners[BANNER_A_CONTROLLED] ||
                       nextBanner == nodePoint[i].banners[BANNER_H_CONTROLLED])
                       // if we are going to spawn the definitve faction banner, we dont need the timer anymore
            {
                nodePoint[i].timer = BANNER_STATE_CHANGE_TIME;
                nodePoint[i].needChange = false;
                SendMessage2ToAll(LANG_BG_IC_TEAM_DEFENDED_NODE, CHAT_MSG_BG_SYSTEM_NEUTRAL, player, nodePoint[i].string);
                HandleCapturedNodes(&nodePoint[i], true);
                UpdatePlayerScore(player, SCORE_BASES_DEFENDED, 1);
            }

            GameObject* banner = GetBGObject(nodePoint[i].gameobject_type);

            if (!banner) // this should never happen
                return;

            float cords[4] = {banner->GetPositionX(), banner->GetPositionY(), banner->GetPositionZ(), banner->GetOrientation() };

            DelObject(nodePoint[i].gameobject_type);
            if (!AddObject(nodePoint[i].gameobject_type, nodePoint[i].gameobject_entry, cords[0], cords[1], cords[2], cords[3], 0, 0, 0, 0, RESPAWN_ONE_DAY))
            {
                TC_LOG_ERROR("bg.battleground", "Isle of Conquest: There was an error spawning a banner (type: %u, entry: %u). Isle of Conquest BG cancelled.", nodePoint[i].gameobject_type, nodePoint[i].gameobject_entry);
                Battleground::EndBattleground(WINNER_NONE);
            }

            GetBGObject(nodePoint[i].gameobject_type)->SetUInt32Value(GAMEOBJECT_FACTION, nodePoint[i].faction == TEAM_ALLIANCE ? BG_IC_Factions[1] : BG_IC_Factions[0]);

            if (nodePoint[i].nodeType == NODE_TYPE_WORKSHOP)
            {
                DelObject(BG_IC_GO_SEAFORIUM_BOMBS_1);
                DelObject(BG_IC_GO_SEAFORIUM_BOMBS_2);
            }

            UpdateNodeWorldState(&nodePoint[i]);
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
        return nodePoint->banners[(team == TEAM_ALLIANCE ? BANNER_A_CONTROLLED : BANNER_H_CONTROLLED)];

    // there were no changes, this point has never been captured by any faction or at least clicked
    if (nodePoint->last_entry == 0)
        // 1 returns the CONTESTED ALLIANCE BANNER, 3 returns the HORDE one
        return nodePoint->banners[(team == TEAM_ALLIANCE ? BANNER_A_CONTESTED : BANNER_H_CONTESTED)];

    // If the actual banner is the definitive faction banner, we must return the grey banner of the player's faction
    if (nodePoint->gameobject_entry == nodePoint->banners[BANNER_A_CONTROLLED] || nodePoint->gameobject_entry == nodePoint->banners[BANNER_H_CONTROLLED])
        return nodePoint->banners[(team == TEAM_ALLIANCE ? BANNER_A_CONTESTED : BANNER_H_CONTESTED)];

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
         if (gunshipAlliance && gunshipHorde)
             (nodePoint->faction == TEAM_ALLIANCE ? gunshipHorde : gunshipAlliance)->EnableMovement(false);

        for (uint8 u = BG_IC_GO_HANGAR_TELEPORTER_1; u < BG_IC_GO_HANGAR_TELEPORTER_3; ++u)
            DelObject(u);
    }
}

void BattlegroundIC::HandleCapturedNodes(ICNodePoint* nodePoint, bool recapture)
{
    if (nodePoint->nodeType != NODE_TYPE_REFINERY && nodePoint->nodeType != NODE_TYPE_QUARRY)
    {
        if (!AddSpiritGuide(BG_IC_NPC_SPIRIT_GUIDE_1+nodePoint->nodeType-2, BG_IC_SpiritGuidePos[nodePoint->nodeType], nodePoint->faction))
            TC_LOG_ERROR("bg.battleground", "Isle of Conquest: Failed to spawn spirit guide! point: %u, team: %u, ", nodePoint->nodeType, nodePoint->faction);
    }

    switch (nodePoint->gameobject_type)
    {
        case BG_IC_GO_HANGAR_BANNER:
            // all the players on the stopped transport should be teleported out
            if (!gunshipAlliance || !gunshipHorde)
                break;

            for (uint8 u = 0; u < MAX_HANGAR_TELEPORTERS_SPAWNS; ++u)
            {
                uint8 type = BG_IC_GO_HANGAR_TELEPORTER_1+u;
                if (!AddObject(type, (nodePoint->faction == TEAM_ALLIANCE ? GO_ALLIANCE_GUNSHIP_PORTAL : GO_HORDE_GUNSHIP_PORTAL),
                    BG_IC_HangarTeleporters[u], 0, 0, 0, 0, RESPAWN_ONE_DAY))
                {
                    TC_LOG_ERROR("bg.battleground", "Isle of Conquest: There was an error spawning a gunship portal. Type: %u", BG_IC_GO_HANGAR_TELEPORTER_1+u);
                }
            }

            //TC_LOG_ERROR("bg.battleground", "BG_IC_GO_HANGAR_BANNER CAPTURED Faction: %u", nodePoint->faction);

            (nodePoint->faction == TEAM_ALLIANCE ? gunshipAlliance : gunshipHorde)->EnableMovement(true);
            (nodePoint->faction == TEAM_ALLIANCE ? gunshipHorde : gunshipAlliance)->EnableMovement(false);
            // we should spawn teleporters
            break;
        case BG_IC_GO_QUARRY_BANNER:
            RemoveAuraOnTeam(SPELL_QUARRY, (nodePoint->faction == TEAM_ALLIANCE ? HORDE : ALLIANCE));
            CastSpellOnTeam(SPELL_QUARRY, (nodePoint->faction == TEAM_ALLIANCE ? ALLIANCE : HORDE));
            break;
        case BG_IC_GO_REFINERY_BANNER:
            RemoveAuraOnTeam(SPELL_OIL_REFINERY, (nodePoint->faction == TEAM_ALLIANCE ? HORDE : ALLIANCE));
            CastSpellOnTeam(SPELL_OIL_REFINERY, (nodePoint->faction == TEAM_ALLIANCE ? ALLIANCE : HORDE));
            break;
        case BG_IC_GO_DOCKS_BANNER:

            if (recapture)
                break;

            if (docksTimer < DOCKS_UPDATE_TIME)
                docksTimer = DOCKS_UPDATE_TIME;

            // we must del opposing faction vehicles when the node is captured (unused ones)
            for (uint8 i = (nodePoint->faction == TEAM_ALLIANCE ? BG_IC_NPC_GLAIVE_THROWER_1_H : BG_IC_NPC_GLAIVE_THROWER_1_A); i < (nodePoint->faction == TEAM_ALLIANCE ? BG_IC_NPC_GLAIVE_THROWER_2_H : BG_IC_NPC_GLAIVE_THROWER_2_A); ++i)
            {
                if (Creature* glaiveThrower = GetBGCreature(i, false))
                {
                    if (Vehicle* vehicleGlaive = glaiveThrower->GetVehicleKit())
                    {
                        if (!vehicleGlaive->GetPassenger(0))
                            DelCreature(i);
                    }
                }
            }

            for (uint8 i = (nodePoint->faction == TEAM_ALLIANCE ? BG_IC_NPC_CATAPULT_1_H : BG_IC_NPC_CATAPULT_1_A); i < (nodePoint->faction == TEAM_ALLIANCE ? BG_IC_NPC_CATAPULT_4_H  : BG_IC_NPC_CATAPULT_4_A); ++i)
            {
                if (Creature* catapult = GetBGCreature(i, false))
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

                if (GetBGCreature(type, false) && GetBGCreature(type)->IsAlive())
                    continue;

                if (AddCreature(nodePoint->faction == TEAM_ALLIANCE ? NPC_GLAIVE_THROWER_A : NPC_GLAIVE_THROWER_H, type,
                        BG_IC_DocksVehiclesGlaives[i], nodePoint->faction, RESPAWN_ONE_DAY))
                    GetBGCreature(type)->setFaction(BG_IC_Factions[(nodePoint->faction == TEAM_ALLIANCE ? 0 : 1)]);
            }

            // spawning catapults
            for (uint8 i = 0; i < MAX_CATAPULTS_SPAWNS_PER_FACTION; ++i)
            {
                uint8 type = (nodePoint->faction == TEAM_ALLIANCE ? BG_IC_NPC_CATAPULT_1_A : BG_IC_NPC_CATAPULT_1_H)+i;

                if (GetBGCreature(type, false) && GetBGCreature(type)->IsAlive())
                    continue;

                if (AddCreature(NPC_CATAPULT, type, BG_IC_DocksVehiclesCatapults[i], nodePoint->faction, RESPAWN_ONE_DAY))
                    GetBGCreature(type)->setFaction(BG_IC_Factions[(nodePoint->faction == TEAM_ALLIANCE ? 0 : 1)]);
            }
            break;
        case BG_IC_GO_WORKSHOP_BANNER:
            {
                if (siegeEngineWorkshopTimer < WORKSHOP_UPDATE_TIME)
                    siegeEngineWorkshopTimer = WORKSHOP_UPDATE_TIME;

                if (!recapture)
                {
                    // we must del opposing faction vehicles when the node is captured (unused ones)
                    for (uint8 i = (nodePoint->faction == TEAM_ALLIANCE ? BG_IC_NPC_DEMOLISHER_1_H : BG_IC_NPC_DEMOLISHER_1_A); i < (nodePoint->faction == TEAM_ALLIANCE ? BG_IC_NPC_DEMOLISHER_4_H : BG_IC_NPC_DEMOLISHER_4_A); ++i)
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
                        uint8 type = (nodePoint->faction == TEAM_ALLIANCE ? BG_IC_NPC_DEMOLISHER_1_A : BG_IC_NPC_DEMOLISHER_1_H)+i;

                        if (GetBGCreature(type, false) && GetBGCreature(type)->IsAlive())
                            continue;

                        if (AddCreature(NPC_DEMOLISHER, type, BG_IC_WorkshopVehicles[i], nodePoint->faction, RESPAWN_ONE_DAY))
                            GetBGCreature(type)->setFaction(BG_IC_Factions[(nodePoint->faction == TEAM_ALLIANCE ? 0 : 1)]);
                    }

                    // we check if the opossing siege engine is in use
                    int8 enemySiege = (nodePoint->faction == TEAM_ALLIANCE ? BG_IC_NPC_SIEGE_ENGINE_H : BG_IC_NPC_SIEGE_ENGINE_A);

                    if (Creature* siegeEngine = GetBGCreature(enemySiege, false))
                    {
                        if (Vehicle* vehicleSiege = siegeEngine->GetVehicleKit())
                        {
                            // is VehicleInUse working as expected ?
                            if (!vehicleSiege->IsVehicleInUse())
                                DelCreature(enemySiege);
                        }
                    }

                    uint8 siegeType = (nodePoint->faction == TEAM_ALLIANCE ? BG_IC_NPC_SIEGE_ENGINE_A : BG_IC_NPC_SIEGE_ENGINE_H);
                    if (!GetBGCreature(siegeType, false) || !GetBGCreature(siegeType)->IsAlive())
                    {
                        AddCreature((nodePoint->faction == TEAM_ALLIANCE ? NPC_SIEGE_ENGINE_A : NPC_SIEGE_ENGINE_H), siegeType,
                            BG_IC_WorkshopVehicles[4], nodePoint->faction, RESPAWN_ONE_DAY);

                        if (Creature* siegeEngine = GetBGCreature(siegeType))
                        {
                            siegeEngine->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_UNK_14|UNIT_FLAG_IMMUNE_TO_PC);
                            siegeEngine->setFaction(BG_IC_Factions[(nodePoint->faction == TEAM_ALLIANCE ? 0 : 1)]);
                        }
                    }
                }

                for (uint8 i = 0; i < MAX_WORKSHOP_BOMBS_SPAWNS_PER_FACTION; ++i)
                {
                    AddObject(BG_IC_GO_SEAFORIUM_BOMBS_1+i, GO_SEAFORIUM_BOMBS,
                    workshopBombs[i].GetPositionX(), workshopBombs[i].GetPositionY(),
                    workshopBombs[i].GetPositionZ(), workshopBombs[i].GetOrientation(),
                    0, 0, 0, 0, 10);

                    if (GameObject* seaforiumBombs = GetBGObject(BG_IC_GO_SEAFORIUM_BOMBS_1+i))
                    {
                        seaforiumBombs->SetRespawnTime(10);
                        seaforiumBombs->SetFaction(BG_IC_Factions[(nodePoint->faction == TEAM_ALLIANCE ? 0 : 1)]);
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
    GateStatus[GetGateIDFromEntry(go->GetEntry())] = BG_IC_GATE_DESTROYED;
    uint32 uws_open = GetWorldStateFromGateEntry(go->GetEntry(), true);
    uint32 uws_close = GetWorldStateFromGateEntry(go->GetEntry(), false);
    if (uws_open)
    {
        UpdateWorldState(uws_close, 0);
        UpdateWorldState(uws_open, 1);
    }
    DoorOpen((player->GetTeamId() == TEAM_ALLIANCE ? BG_IC_GO_HORDE_KEEP_PORTCULLIS : BG_IC_GO_DOODAD_PORTCULLISACTIVE02));

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

    if (go->GetEntry() == GO_HORDE_GATE_1 || go->GetEntry() == GO_HORDE_GATE_2 || go->GetEntry() == GO_HORDE_GATE_3)
    {
        if (!GetBgMap()->GetCreature(BgCreatures[BG_IC_NpcSpawnlocs[BG_IC_NPC_OVERLORD_AGMAR].type]) && !AddCreature(BG_IC_NpcSpawnlocs[BG_IC_NPC_OVERLORD_AGMAR].entry, BG_IC_NpcSpawnlocs[BG_IC_NPC_OVERLORD_AGMAR].type, BG_IC_NpcSpawnlocs[BG_IC_NPC_OVERLORD_AGMAR].x, BG_IC_NpcSpawnlocs[BG_IC_NPC_OVERLORD_AGMAR].y, BG_IC_NpcSpawnlocs[BG_IC_NPC_OVERLORD_AGMAR].z, BG_IC_NpcSpawnlocs[BG_IC_NPC_OVERLORD_AGMAR].o, BG_IC_NpcSpawnlocs[BG_IC_NPC_OVERLORD_AGMAR].team, RESPAWN_ONE_DAY))
            TC_LOG_ERROR("bg.battleground", "Isle of Conquest: There was an error spawning creature %u", BG_IC_NpcSpawnlocs[BG_IC_NPC_OVERLORD_AGMAR].entry);
    }
    else if (go->GetEntry() == GO_ALLIANCE_GATE_1 || go->GetEntry() == GO_ALLIANCE_GATE_2 || go->GetEntry() == GO_ALLIANCE_GATE_3)
    {
        if (!GetBgMap()->GetCreature(BgCreatures[BG_IC_NpcSpawnlocs[BG_IC_NPC_HIGH_COMMANDER_HALFORD_WYRMBANE].type]) && !AddCreature(BG_IC_NpcSpawnlocs[BG_IC_NPC_HIGH_COMMANDER_HALFORD_WYRMBANE].entry, BG_IC_NpcSpawnlocs[BG_IC_NPC_HIGH_COMMANDER_HALFORD_WYRMBANE].type, BG_IC_NpcSpawnlocs[BG_IC_NPC_HIGH_COMMANDER_HALFORD_WYRMBANE].x, BG_IC_NpcSpawnlocs[BG_IC_NPC_HIGH_COMMANDER_HALFORD_WYRMBANE].y, BG_IC_NpcSpawnlocs[BG_IC_NPC_HIGH_COMMANDER_HALFORD_WYRMBANE].z, BG_IC_NpcSpawnlocs[BG_IC_NPC_HIGH_COMMANDER_HALFORD_WYRMBANE].o, BG_IC_NpcSpawnlocs[BG_IC_NPC_HIGH_COMMANDER_HALFORD_WYRMBANE].team, RESPAWN_ONE_DAY))
            TC_LOG_ERROR("bg.battleground", "Isle of Conquest: There was an error spawning creature %u", BG_IC_NpcSpawnlocs[BG_IC_NPC_HIGH_COMMANDER_HALFORD_WYRMBANE].entry);
    }

    SendMessage2ToAll(lang_entry, CHAT_MSG_BG_SYSTEM_NEUTRAL, NULL, (player->GetTeamId() == TEAM_ALLIANCE ? LANG_BG_IC_HORDE_KEEP : LANG_BG_IC_ALLIANCE_KEEP));
}

WorldSafeLocsEntry const* BattlegroundIC::GetClosestGraveYard(Player* player)
{
    TeamId teamIndex = GetTeamIndexByTeamId(player->GetTeam());

    // Is there any occupied node for this team?
    std::vector<uint8> nodes;
    for (uint8 i = 0; i < MAX_NODE_TYPES; ++i)
        if (nodePoint[i].faction == player->GetTeamId())
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
            float dist = (entry->x - player_x)*(entry->x - player_x)+(entry->y - player_y)*(entry->y - player_y);
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
            uint8 nodeType = spellId = SPELL_OIL_REFINERY ? NODE_TYPE_REFINERY : NODE_TYPE_QUARRY;
            uint8 nodeState = team == TEAM_ALLIANCE ? NODE_STATE_CONTROLLED_A : NODE_STATE_CONTROLLED_H;
            return GetNodeState(nodeType) == nodeState;
        }
        default:
           break;
    }

    return true;
}
