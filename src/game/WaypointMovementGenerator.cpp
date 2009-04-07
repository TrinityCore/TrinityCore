/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
//Basic headers
#include "WaypointMovementGenerator.h"
#include "DestinationHolderImp.h"
//Extended headers
#include "ObjectMgr.h"
#include "World.h"
//Creature-specific headers
#include "Creature.h"
#include "CreatureAI.h"
#include "CreatureGroups.h"
//Player-specific
#include "Player.h"

template<class T>
void
WaypointMovementGenerator<T>::Initialize(T &u){}

template<>
void
WaypointMovementGenerator<Creature>::Finalize(Creature &u){}

template<>
void
WaypointMovementGenerator<Player>::Finalize(Player &u){}

template<class T>
void
WaypointMovementGenerator<T>::MovementInform(T &unit){}

template<>
void WaypointMovementGenerator<Creature>::MovementInform(Creature &unit)
{
    unit.AI()->MovementInform(WAYPOINT_MOTION_TYPE, i_currentNode);
}

template<>
bool WaypointMovementGenerator<Creature>::GetDestination(float &x, float &y, float &z) const
{
    if(i_destinationHolder.HasArrived())
        return false;
    
    i_destinationHolder.GetDestination(x, y, z);
    return true;
}

template<>
bool WaypointMovementGenerator<Player>::GetDestination(float &x, float &y, float &z) const
{
    return false;
}

template<>
void WaypointMovementGenerator<Creature>::Reset(Creature &unit)
{
    StopedByPlayer = true;
    i_nextMoveTime.Reset(0);
}

template<>
void WaypointMovementGenerator<Player>::Reset(Player &unit){}

template<>
void WaypointMovementGenerator<Creature>::InitTraveller(Creature &unit, const WaypointData &node)
{
    node.run ? unit.RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE):
        unit.AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);

    unit.SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
    unit.SetUInt32Value(UNIT_FIELD_BYTES_1, 0);

    if(unit.canFly())
        unit.AddUnitMovementFlag(MOVEMENTFLAG_FLYING2);

    unit.addUnitState(UNIT_STAT_ROAMING);
}

template<>
void
WaypointMovementGenerator<Creature>::Initialize(Creature &u)
{
    u.StopMoving();
    //i_currentNode = -1; // uint32, become 0 in the first update
    //i_nextMoveTime.Reset(0);
    StopedByPlayer = false;
    if(!path_id)
        path_id = u.GetWaypointPath();
    waypoints = WaypointMgr.GetPath(path_id);
    i_currentNode = 0;
    if(waypoints && waypoints->size())
    {
        node = waypoints->front();
        Traveller<Creature> traveller(u);
        InitTraveller(u, *node);
        i_destinationHolder.SetDestination(traveller, node->x, node->y, node->z);
        i_nextMoveTime.Reset(i_destinationHolder.GetTotalTravelTime());

        //Call for creature group update
        if(u.GetFormation() && u.GetFormation()->getLeader() == &u)
            u.GetFormation()->LeaderMoveTo(node->x, node->y, node->z);
    }
    else
        node = NULL;
}

template<>
void WaypointMovementGenerator<Player>::InitTraveller(Player &unit, const WaypointData &node){}

template<class T>
bool
WaypointMovementGenerator<T>::Update(T &unit, const uint32 &diff)
{
    return false;
}

template<>
bool
WaypointMovementGenerator<Creature>::Update(Creature &unit, const uint32 &diff)
{
    if(!&unit)
        return true;

    if(!path_id)
        return false;

    // Waypoint movement can be switched on/off
    // This is quite handy for escort quests and other stuff
    if(unit.hasUnitState(UNIT_STAT_ROOT | UNIT_STAT_STUNNED | UNIT_STAT_DISTRACTED))
        return true;

    // Clear the generator if the path doesn't exist
    if(!waypoints || !waypoints->size())
        return false;

    Traveller<Creature> traveller(unit);

    i_nextMoveTime.Update(diff);
    i_destinationHolder.UpdateTraveller(traveller, diff, false, true);

    if(i_nextMoveTime.Passed())
    {
        if(unit.IsStopped())
        {
            if(StopedByPlayer)
            {
                assert(node);
                InitTraveller(unit, *node);
                i_destinationHolder.SetDestination(traveller, node->x, node->y, node->z);
                i_nextMoveTime.Reset(i_destinationHolder.GetTotalTravelTime());
                StopedByPlayer = false;
                return true;
            }

            if(i_currentNode == waypoints->size() - 1) //If that's our last waypoint
            {
                if(repeating) //If the movement is repeating
                    i_currentNode = 0; //Start moving all over again
                else
                {
                    unit.SetHomePosition(node->x, node->y, node->z, unit.GetOrientation());
                    unit.GetMotionMaster()->Initialize();
                    return false; //Clear the waypoint movement
                }
            }
            else
                i_currentNode++;

            node = waypoints->at(i_currentNode);
            InitTraveller(unit, *node);
            i_destinationHolder.SetDestination(traveller, node->x, node->y, node->z);
            i_nextMoveTime.Reset(i_destinationHolder.GetTotalTravelTime());

            //Call for creature group update
            if(unit.GetFormation() && unit.GetFormation()->getLeader() == &unit)
                unit.GetFormation()->LeaderMoveTo(node->x, node->y, node->z);
        }
        else
        {
            //Determine waittime
            if(node->delay)
                i_nextMoveTime.Reset(node->delay);

            if(node->event_id && rand()%100 < node->event_chance)
                sWorld.ScriptsStart(sWaypointScripts, node->event_id, &unit, NULL);

            MovementInform(unit);
            unit.UpdateWaypointID(i_currentNode);
            unit.clearUnitState(UNIT_STAT_MOVING);
            unit.Relocate(node->x, node->y, node->z);
        }
    }
    else
    {
        if(unit.IsStopped() && !i_destinationHolder.HasArrived())
        {
            if(!StopedByPlayer)
            {
                i_destinationHolder.IncreaseTravelTime(STOP_TIME_FOR_PLAYER);
                i_nextMoveTime.Reset(STOP_TIME_FOR_PLAYER);
                StopedByPlayer = true;
            }
        }
    }
    return true;
}

template void WaypointMovementGenerator<Player>::Initialize(Player &);
template bool WaypointMovementGenerator<Player>::Update(Player &, const uint32 &);
template void WaypointMovementGenerator<Player>::MovementInform(Player &);

//----------------------------------------------------//
void
FlightPathMovementGenerator::LoadPath(Player &)
{
    objmgr.GetTaxiPathNodes(i_pathId, i_path,i_mapIds);
}

uint32
FlightPathMovementGenerator::GetPathAtMapEnd() const
{
    if(i_currentNode >= i_mapIds.size())
        return i_mapIds.size();

    uint32 curMapId = i_mapIds[i_currentNode];
    for(uint32 i = i_currentNode; i < i_mapIds.size(); ++i)
    {
        if(i_mapIds[i] != curMapId)
            return i;
    }

    return i_mapIds.size();
}

void
FlightPathMovementGenerator::Initialize(Player &player)
{
    player.getHostilRefManager().setOnlineOfflineState(false);
    player.addUnitState(UNIT_STAT_IN_FLIGHT);
    player.SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_TAXI_FLIGHT);
    LoadPath(player);
    Traveller<Player> traveller(player);
    // do not send movement, it was sent already
    i_destinationHolder.SetDestination(traveller, i_path[i_currentNode].x, i_path[i_currentNode].y, i_path[i_currentNode].z, false);

    player.SendMonsterMoveByPath(GetPath(),GetCurrentNode(),GetPathAtMapEnd());
}

void FlightPathMovementGenerator::Finalize(Player & player)
{
    // remove flag to prevent send object build movement packets for flight state and crash (movement generator already not at top of stack)
    player.clearUnitState(UNIT_STAT_IN_FLIGHT);

    float x, y, z;
    i_destinationHolder.GetLocationNow(player.GetMapId(), x, y, z);
    player.SetPosition(x, y, z, player.GetOrientation());

    player.Unmount();
    player.RemoveFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_TAXI_FLIGHT);

    if(player.m_taxi.empty())
    {
        player.getHostilRefManager().setOnlineOfflineState(true);
        if(player.pvpInfo.inHostileArea)
            player.CastSpell(&player, 2479, true);

        player.SetUnitMovementFlags(MOVEMENTFLAG_WALK_MODE);
        player.StopMoving();
    }
}

bool
FlightPathMovementGenerator::Update(Player &player, const uint32 &diff)
{
    if( MovementInProgress() )
    {
        Traveller<Player> traveller(player);
        if( i_destinationHolder.UpdateTraveller(traveller, diff, false) )
        {
            i_destinationHolder.ResetUpdate(FLIGHT_TRAVEL_UPDATE);
            if( i_destinationHolder.HasArrived() )
            {
                uint32 curMap = i_mapIds[i_currentNode];
                ++i_currentNode;
                if( MovementInProgress() )
                {
                    DEBUG_LOG("loading node %u for player %s", i_currentNode, player.GetName());
                    if(i_mapIds[i_currentNode]==curMap)
                    {
                        // do not send movement, it was sent already
                        i_destinationHolder.SetDestination(traveller, i_path[i_currentNode].x, i_path[i_currentNode].y, i_path[i_currentNode].z, false);
                    }
                    return true;
                }
                //else HasArrived()
            }
            else
                return true;
        }
        else
            return true;
    }

    // we have arrived at the end of the path
    return false;
}

void
FlightPathMovementGenerator::SetCurrentNodeAfterTeleport()
{
    if(i_mapIds.empty())
        return;

    uint32 map0 = i_mapIds[0];
    for(int i = 1; i < i_mapIds.size(); ++i)
    {
        if(i_mapIds[i]!=map0)
        {
            i_currentNode = i;
            return;
        }
    }
}

//
// Unique1's ASTAR Pathfinding Code... For future use & reference...
//

#ifdef __PATHFINDING__

int GetFCost(int to, int num, int parentNum, float *gcost); // Below...

int ShortenASTARRoute(short int *pathlist, int number)
{                                                           // Wrote this to make the routes a little smarter (shorter)... No point looping back to the same places... Unique1
    short int temppathlist[MAX_PATHLIST_NODES];
    int count = 0;
    //    int count2 = 0;
    int temp, temp2;
    int link;
    int upto = 0;

    for (temp = number; temp >= 0; temp--)
    {
        qboolean shortened = qfalse;

        for (temp2 = 0; temp2 < temp; temp2++)
        {
            for (link = 0; link < nodes[pathlist[temp]].enodenum; link++)
            {
                if (nodes[pathlist[temp]].links[link].flags & PATH_BLOCKED)
                    continue;

                //if ((bot->client->ps.eFlags & EF_TANK) && nodes[bot->current_node].links[link].flags & PATH_NOTANKS)    //if this path is blocked, skip it
                //    continue;

                //if (nodes[nodes[pathlist[temp]].links[link].targetNode].origin[2] > nodes[pathlist[temp]].origin[2] + 32)
                //    continue;

                if (nodes[pathlist[temp]].links[link].targetNode == pathlist[temp2])
                {                                           // Found a shorter route...
                    //if (OrgVisible(nodes[pathlist[temp2]].origin, nodes[pathlist[temp]].origin, -1))
                    {
                        temppathlist[count] = pathlist[temp2];
                        temp = temp2;
                        ++count;
                        shortened = qtrue;
                    }
                }
            }
        }

        if (!shortened)
        {
            temppathlist[count] = pathlist[temp];
            ++count;
        }
    }

    upto = count;

    for (temp = 0; temp < count; temp++)
    {
        pathlist[temp] = temppathlist[upto];
        --upto;
    }

    G_Printf("ShortenASTARRoute: Path size reduced from %i to %i nodes...n", number, count);
    return count;
}

/*
===========================================================================
CreatePathAStar
This function uses the A* pathfinding algorithm to determine the
shortest path between any two nodes.
It's fairly complex, so I'm not really going to explain it much.
Look up A* and binary heaps for more info.
pathlist stores the ideal path between the nodes, in reverse order,
and the return value is the number of nodes in that path
===========================================================================
*/
int CreatePathAStar(gentity_t *bot, int from, int to, short int *pathlist)
{
    //all the data we have to hold...since we can't do dynamic allocation, has to be MAX_NODES
    //we can probably lower this later - eg, the open list should never have more than at most a few dozen items on it
    short int openlist[MAX_NODES+1];                        //add 1 because it's a binary heap, and they don't use 0 - 1 is the first used index
    float gcost[MAX_NODES];
    int fcost[MAX_NODES];
    char list[MAX_NODES];                                   //0 is neither, 1 is open, 2 is closed - char because it's the smallest data type
    short int parent[MAX_NODES];

    short int numOpen = 0;
    short int atNode, temp, newnode=-1;
    qboolean found = qfalse;
    int count = -1;
    float gc;
    int i, u, v, m;
    vec3_t vec;

    //clear out all the arrays
    memset(openlist, 0, sizeof(short int)*(MAX_NODES+1));
    memset(fcost, 0, sizeof(int)*MAX_NODES);
    memset(list, 0, sizeof(char)*MAX_NODES);
    memset(parent, 0, sizeof(short int)*MAX_NODES);
    memset(gcost, -1, sizeof(float)*MAX_NODES);

    //make sure we have valid data before calculating everything
    if ((from == NODE_INVALID) || (to == NODE_INVALID) || (from >= MAX_NODES) || (to >= MAX_NODES) || (from == to))
        return -1;

    openlist[1] = from;                                     //add the starting node to the open list
    ++numOpen;
    gcost[from] = 0;                                        //its f and g costs are obviously 0
    fcost[from] = 0;

    while (1)
    {
        if (numOpen != 0)                                   //if there are still items in the open list
        {
            //pop the top item off of the list
            atNode = openlist[1];
            list[atNode] = 2;                               //put the node on the closed list so we don't check it again
            --numOpen;

            openlist[1] = openlist[numOpen+1];              //move the last item in the list to the top position
            v = 1;

            //this while loop reorders the list so that the new lowest fcost is at the top again
            while (1)
            {
                u = v;
                if ((2*u+1) < numOpen)                      //if both children exist
                {
                    if (fcost[openlist[u]] >= fcost[openlist[2*u]])
                        v = 2*u;
                    if (fcost[openlist[v]] >= fcost[openlist[2*u+1]])
                        v = 2*u+1;
                }
                else
                {
                    if ((2*u) < numOpen)                    //if only one child exists
                    {
                        if (fcost[openlist[u]] >= fcost[openlist[2*u]])
                            v = 2*u;
                    }
                }

                if (u != v)                                 //if they're out of order, swap this item with its parent
                {
                    temp = openlist[u];
                    openlist[u] = openlist[v];
                    openlist[v] = temp;
                }
                else
                    break;
            }

            for (i = 0; i < nodes[atNode].enodenum; i++)    //loop through all the links for this node
            {
                newnode = nodes[atNode].links[i].targetNode;

                //if this path is blocked, skip it
                if (nodes[atNode].links[i].flags & PATH_BLOCKED)
                    continue;
                //if this path is blocked, skip it
                if (bot->client && (bot->client->ps.eFlags & EF_TANK) && nodes[atNode].links[i].flags & PATH_NOTANKS)
                    continue;
                //skip any unreachable nodes
                if (bot->client && (nodes[newnode].type & NODE_ALLY_UNREACHABLE) && (bot->client->sess.sessionTeam == TEAM_ALLIES))
                    continue;
                if (bot->client && (nodes[newnode].type & NODE_AXIS_UNREACHABLE) && (bot->client->sess.sessionTeam == TEAM_AXIS))
                    continue;

                if (list[newnode] == 2)                     //if this node is on the closed list, skip it
                    continue;

                if (list[newnode] != 1)                     //if this node is not already on the open list
                {
                    openlist[++numOpen] = newnode;          //add the new node to the open list
                    list[newnode] = 1;
                    parent[newnode] = atNode;               //record the node's parent

                    if (newnode == to)                      //if we've found the goal, don't keep computing paths!
                        break;                              //this will break the 'for' and go all the way to 'if (list[to] == 1)'

                    //store it's f cost value
                    fcost[newnode] = GetFCost(to, newnode, parent[newnode], gcost);

                    //this loop re-orders the heap so that the lowest fcost is at the top
                    m = numOpen;
                    while (m != 1)                          //while this item isn't at the top of the heap already
                    {
                        //if it has a lower fcost than its parent
                        if (fcost[openlist[m]] <= fcost[openlist[m/2]])
                        {
                            temp = openlist[m/2];
                            openlist[m/2] = openlist[m];
                            openlist[m] = temp;             //swap them
                            m /= 2;
                        }
                        else
                            break;
                    }
                }
                else                                        //if this node is already on the open list
                {
                    gc = gcost[atNode];
                    VectorSubtract(nodes[newnode].origin, nodes[atNode].origin, vec);
                    gc += VectorLength(vec);                //calculate what the gcost would be if we reached this node along the current path

                    if (gc < gcost[newnode])                //if the new gcost is less (ie, this path is shorter than what we had before)
                    {
                        parent[newnode] = atNode;           //set the new parent for this node
                        gcost[newnode] = gc;                //and the new g cost

                        for (i = 1; i < numOpen; i++)       //loop through all the items on the open list
                        {
                            if (openlist[i] == newnode)     //find this node in the list
                            {
                                //calculate the new fcost and store it
                                fcost[newnode] = GetFCost(to, newnode, parent[newnode], gcost);

                                //reorder the list again, with the lowest fcost item on top
                                m = i;
                                while (m != 1)
                                {
                                    //if the item has a lower fcost than it's parent
                                    if (fcost[openlist[m]] < fcost[openlist[m/2]])
                                    {
                                        temp = openlist[m/2];
                                        openlist[m/2] = openlist[m];
                                        openlist[m] = temp; //swap them
                                        m /= 2;
                                    }
                                    else
                                        break;
                                }
                                break;                      //exit the 'for' loop because we already changed this node
                            }                               //if
                        }                                   //for
                    }                                       //if (gc < gcost[newnode])
                }                                           //if (list[newnode] != 1) --> else
            }                                               //for (loop through links)
        }                                                   //if (numOpen != 0)
        else
        {
            found = qfalse;                                 //there is no path between these nodes
            break;
        }

        if (list[to] == 1)                                  //if the destination node is on the open list, we're done
        {
            found = qtrue;
            break;
        }
    }                                                       //while (1)

    if (found == qtrue)                                     //if we found a path
    {
        //G_Printf("%s - path found!n", bot->client->pers.netname);
        count = 0;

        temp = to;                                          //start at the end point
        while (temp != from)                                //travel along the path (backwards) until we reach the starting point
        {
            pathlist[count++] = temp;                       //add the node to the pathlist and increment the count
            temp = parent[temp];                            //move to the parent of this node to continue the path
        }

        pathlist[count++] = from;                           //add the beginning node to the end of the pathlist

        #ifdef __BOT_SHORTEN_ROUTING__
        count = ShortenASTARRoute(pathlist, count);         // This isn't working... Dunno why.. Unique1
        #endif                                              //__BOT_SHORTEN_ROUTING__
    }
    else
    {
        //G_Printf("^1*** ^4BOT DEBUG^5: (CreatePathAStar) There is no route between node ^7%i^5 and node ^7%i^5.n", from, to);
        count = CreateDumbRoute(from, to, pathlist);

        if (count > 0)
        {
            #ifdef __BOT_SHORTEN_ROUTING__
            count = ShortenASTARRoute(pathlist, count);     // This isn't working... Dunno why.. Unique1
            #endif                                          //__BOT_SHORTEN_ROUTING__
            return count;
        }
    }

    return count;                                           //return the number of nodes in the path, -1 if not found
}

/*
===========================================================================
GetFCost
Utility function used by A* pathfinding to calculate the
cost to move between nodes towards a goal.  Using the A*
algorithm F = G + H, G here is the distance along the node
paths the bot must travel, and H is the straight-line distance
to the goal node.
Returned as an int because more precision is unnecessary and it
will slightly speed up heap access
===========================================================================
*/
int GetFCost(int to, int num, int parentNum, float *gcost)
{
    float gc = 0;
    float hc = 0;
    vec3_t v;

    if (gcost[num] == -1)
    {
        if (parentNum != -1)
        {
            gc = gcost[parentNum];
            VectorSubtract(nodes[num].origin, nodes[parentNum].origin, v);
            gc += VectorLength(v);
        }
        gcost[num] = gc;
    }
    else
        gc = gcost[num];

    VectorSubtract(nodes[to].origin, nodes[num].origin, v);
    hc = VectorLength(v);

    return (int)(gc + hc);
}
#endif                                                      //__PATHFINDING__

