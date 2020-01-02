/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include <boost/graph/depth_first_search.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/property_map/transform_value_property_map.hpp>

TaxiPathGraph& TaxiPathGraph::Instance()
{
    static TaxiPathGraph instance;
    return instance;
}

void TaxiPathGraph::Initialize()
{
    if (boost::num_vertices(m_graph) > 0)
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
    m_graph = Graph(m_nodesByVertex.size());
    WeightMap weightmap = boost::get(boost::edge_weight, m_graph);

    for (std::size_t j = 0; j < edges.size(); ++j)
    {
        edge_descriptor e = boost::add_edge(edges[j].first.first, edges[j].first.second, m_graph).first;
        weightmap[e] = edges[j].second;
    }
}

uint32 TaxiPathGraph::GetNodeIDFromVertexID(vertex_descriptor vertexID)
{
    if (vertexID < m_nodesByVertex.size())
        return m_nodesByVertex[vertexID]->ID;

    return std::numeric_limits<uint32>::max();
}

TaxiPathGraph::vertex_descriptor TaxiPathGraph::GetVertexIDFromNodeID(TaxiNodesEntry const* node)
{
    auto itr = m_verticesByNode.find(node->ID);
    return itr != m_verticesByNode.end() ? itr->second : std::numeric_limits<vertex_descriptor>::max();
}

void GetTaxiMapPosition(DBCPosition3D const& position, int32 mapId, DBCPosition2D* uiMapPosition, int32* uiMapId)
{
    if (!DB2Manager::GetUiMapPosition(position.X, position.Y, position.Z, mapId, 0, 0, 0, UI_MAP_SYSTEM_ADVENTURE, false, uiMapId, uiMapPosition))
        DB2Manager::GetUiMapPosition(position.X, position.Y, position.Z, mapId, 0, 0, 0, UI_MAP_SYSTEM_TAXI, false, uiMapId, uiMapPosition);
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

            int32 uiMap1, uiMap2;
            DBCPosition2D pos1, pos2;

            GetTaxiMapPosition(nodes[i - 1]->Loc, nodes[i - 1]->ContinentID, &pos1, &uiMap1);
            GetTaxiMapPosition(nodes[i]->Loc, nodes[i]->ContinentID, &pos2, &uiMap2);

            if (uiMap1 != uiMap2)
                continue;

            totalDist += std::sqrt(
                std::pow(pos2.X - pos1.X, 2) +
                std::pow(pos2.Y - pos1.Y, 2));
        }

        uint32 dist = uint32(totalDist * 32767.0f);
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

template<typename T>
struct DiscoverVertexVisitor : public boost::base_visitor<DiscoverVertexVisitor<T>>
{
    using event_filter = boost::on_discover_vertex;

    DiscoverVertexVisitor(T&& func) : _func(std::forward<T>(func)) { }

    template <class Vertex, class Graph>
    void operator()(Vertex v, Graph& /*g*/)
    {
        _func(v);
    }

private:
    T _func;
};

template<typename T>
inline auto make_discover_vertex_dfs_visitor(T&& t)
{
    return boost::make_dfs_visitor(DiscoverVertexVisitor<T>(std::forward<T>(t)));
}

void TaxiPathGraph::GetReachableNodesMask(TaxiNodesEntry const* from, TaxiMask* mask)
{
    boost::vector_property_map<boost::default_color_type> color(boost::num_vertices(m_graph));
    std::fill(color.storage_begin(), color.storage_end(), boost::white_color);
    boost::depth_first_visit(m_graph, GetVertexIDFromNodeID(from), make_discover_vertex_dfs_visitor([this, mask](vertex_descriptor vertex)
    {
        if (TaxiNodesEntry const* taxiNode = sTaxiNodesStore.LookupEntry(GetNodeIDFromVertexID(vertex)))
            (*mask)[(taxiNode->ID - 1) / 8] |= 1 << ((taxiNode->ID - 1) % 8);
    }), color);
}

TaxiPathGraph::vertex_descriptor TaxiPathGraph::CreateVertexFromFromNodeInfoIfNeeded(TaxiNodesEntry const* node)
{
    auto itr = m_verticesByNode.find(node->ID);
    if (itr == m_verticesByNode.end())
    {
        itr = m_verticesByNode.emplace(node->ID, m_nodesByVertex.size()).first;
        m_nodesByVertex.push_back(node);
    }

    return itr->second;
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
