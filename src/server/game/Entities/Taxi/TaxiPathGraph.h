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

#ifndef TAXIPATHGRAPH_HPP
#define TAXIPATHGRAPH_HPP

#include "Position.h"
#include "Define.h"
#include <boost/graph/adjacency_list.hpp>

class Player;
struct TaxiNodesEntry;

class TC_GAME_API TaxiPathGraph
{
public:
    static TaxiPathGraph& Instance();

    void Initialize();
    std::size_t GetCompleteNodeRoute(TaxiNodesEntry const* from, TaxiNodesEntry const* to, Player const* player, std::vector<uint32>& shortestPath);

private:
    struct EdgeCost
    {
        TaxiNodesEntry const* To;
        uint32 Distance;
        uint32 EvaluateDistance(Player const* player) const;
    };
    typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, boost::property<boost::vertex_index_t, uint32>, boost::property<boost::edge_weight_t, EdgeCost>> Graph;
    typedef boost::property_map<Graph, boost::edge_weight_t>::type WeightMap;
    typedef Graph::vertex_descriptor vertex_descriptor;
    typedef Graph::edge_descriptor edge_descriptor;
    typedef std::pair<vertex_descriptor, vertex_descriptor> edge;

    TaxiPathGraph() { }
    ~TaxiPathGraph() { }

    void AddVerticeAndEdgeFromNodeInfo(TaxiNodesEntry const* from, TaxiNodesEntry const* to, uint32 pathId, std::vector<std::pair<edge, EdgeCost>>& edges);
    vertex_descriptor GetVertexIDFromNodeID(TaxiNodesEntry const* node);
    uint32 GetNodeIDFromVertexID(vertex_descriptor vertexID);
    vertex_descriptor CreateVertexFromFromNodeInfoIfNeeded(TaxiNodesEntry const* node);
    std::size_t GetVertexCount();

    Graph m_graph;
    std::vector<TaxiNodesEntry const*> m_vertices;

    TaxiPathGraph(TaxiPathGraph const&) = delete;
    TaxiPathGraph& operator=(TaxiPathGraph const&) = delete;
};

#define sTaxiPathGraph TaxiPathGraph::Instance()

#endif    /* TAXIPATHGRAPH_HPP */
