/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "TaxiPathGraph.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "DB2Stores.h"
#include "Config.h"
#include "Util.h"
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/property_map/transform_value_property_map.hpp>

TaxiPathGraph& TaxiPathGraph::Instance()
{
    static TaxiPathGraph instance;
    return instance;
}

void TaxiPathGraph::Initialize()
{
    if (GetVertexCount() > 0)
        return;

    std::vector<std::pair<edge, EdgeCost>> edges;

    // Initialize here
    for (TaxiPathEntry const* path : sTaxiPathStore)
    {
        TaxiNodesEntry const* from = sTaxiNodesStore.LookupEntry(path->FromTaxiNode);
        TaxiNodesEntry const* to = sTaxiNodesStore.LookupEntry(path->ToTaxiNode);
        if (from && to && from->Flags & (TAXI_NODE_FLAG_ALLIANCE | TAXI_NODE_FLAG_HORDE) && to->Flags & (TAXI_NODE_FLAG_ALLIANCE | TAXI_NODE_FLAG_HORDE))
            AddVerticeAndEdgeFromNodeInfo(from, to, path->ID, edges);
    }

    // create graph
    m_graph = Graph(GetVertexCount());
    WeightMap weightmap = boost::get(boost::edge_weight, m_graph);

    for (std::size_t j = 0; j < edges.size(); ++j)
    {
        edge_descriptor e = boost::add_edge(edges[j].first.first, edges[j].first.second, m_graph).first;
        weightmap[e] = edges[j].second;
    }
}

uint32 TaxiPathGraph::GetNodeIDFromVertexID(vertex_descriptor vertexID)
{
    if (vertexID < m_vertices.size())
        return m_vertices[vertexID]->ID;

    return std::numeric_limits<uint32>::max();
}

TaxiPathGraph::vertex_descriptor TaxiPathGraph::GetVertexIDFromNodeID(TaxiNodesEntry const* node)
{
    return node->CharacterBitNumber;
}

std::size_t TaxiPathGraph::GetVertexCount()
{
    //So we can use this function for readability, we define either max defined vertices or already loaded in graph count
    return std::max(boost::num_vertices(m_graph), m_vertices.size());
}

void TaxiPathGraph::AddVerticeAndEdgeFromNodeInfo(TaxiNodesEntry const* from, TaxiNodesEntry const* to, uint32 pathId, std::vector<std::pair<edge, EdgeCost>>& edges)
{
    if (from != to)
    {
        vertex_descriptor fromVertexID = CreateVertexFromFromNodeInfoIfNeeded(from);
        vertex_descriptor toVertexID = CreateVertexFromFromNodeInfoIfNeeded(to);

        float totalDist = 0.0f;
        TaxiPathNodeList const& nodes = sTaxiPathNodesByPath[pathId];
        if (nodes.size() < 2)
        {
            edges.push_back(std::make_pair(edge(fromVertexID, toVertexID), EdgeCost{ to, 0xFFFF }));
            return;
        }

        std::size_t last = nodes.size();
        std::size_t first = 0;
        if (nodes.size() > 2)
        {
            --last;
            ++first;
        }

        for (std::size_t i = first + 1; i < last; ++i)
        {
            if (nodes[i - 1]->Flags & TAXI_PATH_NODE_FLAG_TELEPORT)
                continue;

            uint32 map1, map2;
            DBCPosition2D pos1, pos2;

            DB2Manager::DeterminaAlternateMapPosition(nodes[i - 1]->ContinentID, nodes[i - 1]->Loc.X, nodes[i - 1]->Loc.Y, nodes[i - 1]->Loc.Z, &map1, &pos1);
            DB2Manager::DeterminaAlternateMapPosition(nodes[i]->ContinentID, nodes[i]->Loc.X, nodes[i]->Loc.Y, nodes[i]->Loc.Z, &map2, &pos2);

            if (map1 != map2)
                continue;

            totalDist += std::sqrt(
                std::pow(pos2.X - pos1.X, 2) +
                std::pow(pos2.Y - pos1.Y, 2) +
                std::pow(nodes[i]->Loc.Z - nodes[i - 1]->Loc.Z, 2));
        }

        uint32 dist = uint32(totalDist);
        if (dist > 0xFFFF)
            dist = 0xFFFF;

        edges.push_back(std::make_pair(edge(fromVertexID, toVertexID), EdgeCost{ to, dist }));
    }
}

std::size_t TaxiPathGraph::GetCompleteNodeRoute(TaxiNodesEntry const* from, TaxiNodesEntry const* to, Player const* player, std::vector<uint32>& shortestPath)
{
    /*
        Information about node algorithm from client
        Since client does not give information about *ALL* nodes you have to pass by when going from sourceNodeID to destinationNodeID, we need to use Dijkstra algorithm.
        Examining several paths I discovered the following algorithm:
        * If destinationNodeID has is the next destination, connected directly to sourceNodeID, then, client just pick up this route regardless of distance
        * else we use dijkstra to find the shortest path.
        * When early landing is requested, according to behavior on retail, you can never end in a node you did not discovered before
    */

    // Find if we have a direct path
    uint32 pathId, goldCost;
    sObjectMgr->GetTaxiPath(from->ID, to->ID, pathId, goldCost);
    if (pathId)
        shortestPath = { from->ID, to->ID };
    else
    {
        shortestPath.clear();
        std::vector<vertex_descriptor> p(boost::num_vertices(m_graph));
        std::vector<uint32> d(boost::num_vertices(m_graph));

        boost::dijkstra_shortest_paths(m_graph, GetVertexIDFromNodeID(from),
            boost::predecessor_map(boost::make_iterator_property_map(p.begin(), boost::get(boost::vertex_index, m_graph)))
            .distance_map(boost::make_iterator_property_map(d.begin(), boost::get(boost::vertex_index, m_graph)))
            .vertex_index_map(boost::get(boost::vertex_index, m_graph))
            .distance_compare(std::less<uint32>())
            .distance_combine(boost::closed_plus<uint32>())
            .distance_inf(std::numeric_limits<uint32>::max())
            .distance_zero(0)
            .visitor(boost::dijkstra_visitor<boost::null_visitor>())
            .weight_map(boost::make_transform_value_property_map(
                [player](EdgeCost const& edgeCost) { return edgeCost.EvaluateDistance(player); },
                boost::get(boost::edge_weight, m_graph))));

        // found a path to the goal
        for (vertex_descriptor v = GetVertexIDFromNodeID(to); ; v = p[v])
        {
            shortestPath.push_back(GetNodeIDFromVertexID(v));
            if (v == p[v])
                break;
        }

        std::reverse(shortestPath.begin(), shortestPath.end());
    }

    return shortestPath.size();
}

TaxiPathGraph::vertex_descriptor TaxiPathGraph::CreateVertexFromFromNodeInfoIfNeeded(TaxiNodesEntry const* node)
{
    //Check if we need a new one or if it may be already created
    if (m_vertices.size() <= node->CharacterBitNumber)
        m_vertices.resize(node->CharacterBitNumber + 1);

    m_vertices[node->CharacterBitNumber] = node;
    return node->CharacterBitNumber;
}

uint32 TaxiPathGraph::EdgeCost::EvaluateDistance(Player const* player) const
{
    uint32 requireFlag = (player->GetTeam() == ALLIANCE) ? TAXI_NODE_FLAG_ALLIANCE : TAXI_NODE_FLAG_HORDE;
    if (!(To->Flags & requireFlag))
        return std::numeric_limits<uint16>::max();

    if (PlayerConditionEntry const* condition = sPlayerConditionStore.LookupEntry(To->ConditionID))
        if (!sConditionMgr->IsPlayerMeetingCondition(player, condition))
            return std::numeric_limits<uint16>::max();

    return Distance;
}
