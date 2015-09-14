#include "TaxiPathGraph.h"
#include <utility>
#include "Util.h"
#include "DB2Stores.h"
#include "Config.h"
#include <boost/property_map/transform_value_property_map.hpp>


TaxiPathGraph::Graph TaxiPathGraph::m_graph = TaxiPathGraph::Graph();
std::vector<TaxiPathGraph::TaxiNodeInfo> TaxiPathGraph::m_vertices = std::vector<TaxiPathGraph::TaxiNodeInfo>();
std::map<uint32, TaxiPathGraph::vertex> TaxiPathGraph::m_nodeIDToVertexID = std::map<uint32, TaxiPathGraph::vertex>();
std::set<TaxiPathGraph::edge> TaxiPathGraph::m_edgeDuplicateControl = std::set<TaxiPathGraph::edge>();
const int TaxiPathGraph::MaxFlightDistanceThreshold = 4000; //Because the client seems not to chose long flight paths even if that means the chosen path is not the minimum one

TaxiPathGraph::TaxiPathGraph() { }

TaxiPathGraph::~TaxiPathGraph() { }

void TaxiPathGraph::Initialize()
{
    if (_getVertexCount() > 0)
        return;
    
    m_edgeDuplicateControl.clear();
    std::vector<std::pair<edge, cost>> edges;
    
    std::set<uint32> returnableNodeIDs; // Used to omit special nodes which you can't return from
    
    for (TaxiPathEntry const* nodeInfo : sTaxiPathStore)
        if (nodeInfo->From != nodeInfo->To)
            returnableNodeIDs.insert(nodeInfo->From);
    
    // Initialize here
    for (TaxiPathEntry const* nodeInfo : sTaxiPathStore)
    {
        TaxiNodesEntry const* from = sTaxiNodesStore.LookupEntry(nodeInfo->From);
        TaxiNodesEntry const* to = sTaxiNodesStore.LookupEntry(nodeInfo->To);
        if (from && to && 
            returnableNodeIDs.find(nodeInfo->From) != returnableNodeIDs.end() && returnableNodeIDs.find(nodeInfo->To) != returnableNodeIDs.end())
        {
            _addVerticeAndEdgeFromNodeInfo(TaxiNodeInfo(from->ID, from->Name->Str[sConfigMgr->GetIntDefault("DBC.Locale", LOCALE_enUS)], from->Pos.X, from->Pos.Y, from->Pos.Z),
                                        TaxiNodeInfo(to->ID, to->Name->Str[sConfigMgr->GetIntDefault("DBC.Locale", LOCALE_enUS)], to->Pos.X, to->Pos.Y, to->Pos.Z), nodeInfo->Cost, edges);
        }
    }

    returnableNodeIDs.clear();
    // create graph
    m_graph = Graph(_getVertexCount());
    WeightMap weightmap = boost::get(boost::edge_weight, m_graph);
    /*IndexMap indexmap = boost::get(boost::vertex_index, m_graph);*/
    
    for(std::size_t j = 0; j < edges.size(); ++j) {
        edge_descriptor e; bool inserted;
        boost::tie(e, inserted) = boost::add_edge(edges[j].first.first,
                                                  edges[j].first.second,
                                                  m_graph);
        weightmap[e] = edges[j].second;
    }
    m_edgeDuplicateControl.clear();
}

uint32 TaxiPathGraph::_getNodeIDFromVertexID(vertex vertexID)
{
    if (vertexID < m_vertices.size())
        return m_vertices[vertexID].nodeID;
    
    return std::numeric_limits<uint32>::max();
}

TaxiPathGraph::vertex TaxiPathGraph::_getVertexIDFromNodeID(uint32_t nodeID)
{
    if (m_nodeIDToVertexID.find(nodeID) != m_nodeIDToVertexID.end())
        return m_nodeIDToVertexID[nodeID];
    
    return std::numeric_limits<vertex>::max();
}

TaxiPathGraph::vertex TaxiPathGraph::_getVertexIDFromNodeID(TaxiNodeInfo const& nodeInfo)
{
    if (m_nodeIDToVertexID.find(nodeInfo.nodeID) != m_nodeIDToVertexID.end())
        return m_nodeIDToVertexID[nodeInfo.nodeID];
    
    return std::numeric_limits<vertex>::max();
}

size_t TaxiPathGraph::_getVertexCount()
{
    //So we can use this function for readability, we define either max defined vertices or already loaded in graph count
    return std::max(boost::num_vertices(m_graph), m_vertices.size());
}

void TaxiPathGraph::_addVerticeAndEdgeFromNodeInfo(const TaxiNodeInfo& from, const TaxiNodeInfo& to, uint32 /* money */, std::vector<std::pair<edge, cost>>& edges)
{
    if (from.nodeID != to.nodeID && m_edgeDuplicateControl.find(edge(from.nodeID, to.nodeID)) == m_edgeDuplicateControl.end())
    {
        vertex fromVertexID = _createVertexFromFromNodeInfoIfNeeded(from);
        vertex toVertexID = _createVertexFromFromNodeInfoIfNeeded(to);
        
        edges.push_back(std::make_pair(edge(fromVertexID, toVertexID), from.pos.Distance(to.pos)));
        m_edgeDuplicateControl.insert(edge(from.nodeID, to.nodeID));
    }
}

size_t TaxiPathGraph::GetCompleteNodeRoute(uint32_t sourceNodeID, uint32_t destinationNodeID, std::vector<uint32>& shortestPath)
{
    /*
        Information about node algorithm from client
    Since client does not give information about *ALL* nodes you have to pass by when going from sourceNodeID to destinationNodeID, algorithms like A* on directed graph of taxi
    nodes are needed. But since, 6.x implemented early landing request feature, client seems not to be picking the least expensive path in terms in neither distance neither money cost.
    Examining several paths I discovered the following algorithm:
        * If destinationNodeID has is the next destination, connected directly to sourceNodeID, then, client just pick up this route regardless of distance
        * else, client will avoid to pick a node which distance is equal or greater than TaxiPathGraph::MaxFlightDistanceThreshold to avoid long node to node distances for requesting
        early landings, so we use A* algorithm with a custom weight property map to reflect this condition.

        * When early landing is requested, according to behavior on retail, you can never end in a node you did not discovered before
    */
    bool hasDirectPath = false;
    shortestPath.clear();
    
    // Find if we have a direct path from sourceNodeID to destinationNodeID in graph
    typename boost::graph_traits<Graph>::out_edge_iterator ei, ei_end;
    for (boost::tie(ei, ei_end) = boost::out_edges(_getVertexIDFromNodeID(sourceNodeID), m_graph); ei != ei_end && !hasDirectPath; ++ei)
        if (boost::target(*ei, m_graph) == _getVertexIDFromNodeID(destinationNodeID))
            hasDirectPath = true;
    
    if (hasDirectPath)
        shortestPath = { sourceNodeID, destinationNodeID };
    else
    {
        std::vector<Graph::vertex_descriptor> p(boost::num_vertices(m_graph));
        std::vector<cost> d(boost::num_vertices(m_graph));

        vertex start = _getVertexIDFromNodeID(sourceNodeID);
        vertex goal = _getVertexIDFromNodeID(destinationNodeID);

        try
        {
            auto wow_custom_weight_map = boost::make_transform_value_property_map(
                [](float w) { return w>MaxFlightDistanceThreshold ? w*1000 : w; },
                boost::get(boost::edge_weight, m_graph)
            );
            boost::astar_search(m_graph, start,
                boost::astar_heuristic<Graph, cost>(),
                boost::weight_map(wow_custom_weight_map)
                .predecessor_map(boost::make_iterator_property_map(p.begin(), get(boost::vertex_index, m_graph)))
                .distance_map(boost::make_iterator_property_map(d.begin(), get(boost::vertex_index, m_graph)))
                .visitor(astar_goal_visitor<vertex>(goal)));
        }
        catch(found_goal fg)
        { // found a path to the goal
            std::list<vertex> shortest_path;
            for(vertex v = goal;; v = p[v]) {
                shortest_path.push_front(v);
                if(p[v] == v)
                    break;
            }

            for(std::list<vertex>::const_iterator spi = shortest_path.begin(); spi != shortest_path.end(); spi++)
                shortestPath.push_back(_getNodeIDFromVertexID(*spi));
        }
    }
    return shortestPath.size();
}

TaxiPathGraph::TaxiNodeInfo const* TaxiPathGraph::GetTaxiNodeInfoByID(uint32_t nodeID)
{
    vertex vertexID = _getVertexIDFromNodeID(nodeID);
    if (m_vertices.size() < vertexID)
        return nullptr;
    return &m_vertices[vertexID];
}

TaxiPathGraph::vertex TaxiPathGraph::_createVertexFromFromNodeInfoIfNeeded(const TaxiNodeInfo& nodeInfo)
{
    //Check if we need a new one or if it may be already created
    if (m_nodeIDToVertexID.find(nodeInfo.nodeID) == m_nodeIDToVertexID.end())
    {
        vertex verID = m_vertices.size();
        m_vertices.push_back(nodeInfo);
        m_nodeIDToVertexID[nodeInfo.nodeID] = verID;
        return verID;
    }
    return m_nodeIDToVertexID[nodeInfo.nodeID];
}
