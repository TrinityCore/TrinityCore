#include "TaxiPathGraph.h"
#include "ObjectMgr.h"
#include "DBCStores.h"
#include "DB2Stores.h"
#include "Config.h"
#include "Util.h"

TaxiPathGraph::Graph TaxiPathGraph::m_graph = TaxiPathGraph::Graph();
std::vector<TaxiPathGraph::TaxiNodeInfo> TaxiPathGraph::m_vertices = std::vector<TaxiPathGraph::TaxiNodeInfo>();
std::map<uint32, TaxiPathGraph::vertex_descriptor> TaxiPathGraph::m_nodeIDToVertexID = std::map<uint32, TaxiPathGraph::vertex_descriptor>();
std::set<TaxiPathGraph::edge> TaxiPathGraph::m_edgeDuplicateControl = std::set<TaxiPathGraph::edge>();
const int TaxiPathGraph::MaxFlightDistanceThreshold = 4000; //Because the client seems not to chose long flight paths even if that means the chosen path is not the minimum one

TaxiPathGraph::TaxiPathGraph() { }

TaxiPathGraph::~TaxiPathGraph() { }

void DeterminaAlternateMapPosition(TaxiPathGraph::TaxiNodeInfo& info)
{
    WorldMapTransformsEntry const* transformation = nullptr;
    for (WorldMapTransformsEntry const* transform : sWorldMapTransformsStore)
    {
        if (transform->MapID != info.mapId)
            continue;

        if (transform->RegionMin.X > info.pos.x || transform->RegionMax.X < info.pos.x)
            continue;
        if (transform->RegionMin.Y > info.pos.y || transform->RegionMax.Y < info.pos.y)
            continue;
        if (transform->RegionMin.Z > info.pos.z || transform->RegionMax.Z < info.pos.z)
            continue;

        transformation = transform;
        break;
    }

    if (!transformation)
        return;

    if (transformation->RegionScale > 0.0f && transformation->RegionScale < 1.0f)
    {
        info.pos.x = (info.pos.x - transformation->RegionMin.X) * transformation->RegionScale + transformation->RegionMin.X;
        info.pos.y = (info.pos.y - transformation->RegionMin.Y) * transformation->RegionScale + transformation->RegionMin.Y;
    }

    info.pos.x += transformation->RegionOffset.X;
    info.pos.y += transformation->RegionOffset.Y;
}

void TaxiPathGraph::Initialize()
{
    if (_getVertexCount() > 0)
        return;

    m_edgeDuplicateControl.clear();
    std::vector<std::pair<edge, cost>> edges;

    // Initialize here
    for (TaxiPathEntry const* nodeInfo : sTaxiPathStore)
    {
        TaxiNodesEntry const* from = sTaxiNodesStore.LookupEntry(nodeInfo->From);
        TaxiNodesEntry const* to = sTaxiNodesStore.LookupEntry(nodeInfo->To);
        if (from && to && from->Flags & (TAXI_NODE_FLAG_ALLIANCE | TAXI_NODE_FLAG_HORDE) && to->Flags & (TAXI_NODE_FLAG_ALLIANCE | TAXI_NODE_FLAG_HORDE))
        {
            TaxiNodeInfo fromInfo(from->ID, from->Name->Str[sConfigMgr->GetIntDefault("DBC.Locale", LOCALE_enUS)], from->MapID, from->Pos.X, from->Pos.Y, from->Pos.Z);
            TaxiNodeInfo toInfo(to->ID, to->Name->Str[sConfigMgr->GetIntDefault("DBC.Locale", LOCALE_enUS)], to->MapID, to->Pos.X, to->Pos.Y, to->Pos.Z);

            DeterminaAlternateMapPosition(fromInfo);
            DeterminaAlternateMapPosition(toInfo);

            _addVerticeAndEdgeFromNodeInfo(fromInfo, toInfo, nodeInfo->Cost, edges);
        }
    }

    // create graph
    m_graph = Graph(_getVertexCount());
    WeightMap weightmap = boost::get(boost::edge_weight, m_graph);

    for (std::size_t j = 0; j < edges.size(); ++j)
    {
        edge_descriptor e;
        bool inserted;
        boost::tie(e, inserted) = boost::add_edge(edges[j].first.first,
            edges[j].first.second,
            m_graph);
        weightmap[e] = edges[j].second;
    }
    m_edgeDuplicateControl.clear();
}

uint32 TaxiPathGraph::_getNodeIDFromVertexID(vertex_descriptor vertexID)
{
    if (vertexID < m_vertices.size())
        return m_vertices[vertexID].nodeID;

    return std::numeric_limits<uint32>::max();
}

TaxiPathGraph::vertex_descriptor TaxiPathGraph::_getVertexIDFromNodeID(uint32 nodeID)
{
    if (m_nodeIDToVertexID.find(nodeID) != m_nodeIDToVertexID.end())
        return m_nodeIDToVertexID[nodeID];

    return std::numeric_limits<vertex_descriptor>::max();
}

TaxiPathGraph::vertex_descriptor TaxiPathGraph::_getVertexIDFromNodeID(TaxiNodeInfo const& nodeInfo)
{
    if (m_nodeIDToVertexID.find(nodeInfo.nodeID) != m_nodeIDToVertexID.end())
        return m_nodeIDToVertexID[nodeInfo.nodeID];

    return std::numeric_limits<vertex_descriptor>::max();
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
        vertex_descriptor fromVertexID = _createVertexFromFromNodeInfoIfNeeded(from);
        vertex_descriptor toVertexID = _createVertexFromFromNodeInfoIfNeeded(to);

        // TODO: Calculate distance using TaxiPathNode
        edges.push_back(std::make_pair(edge(fromVertexID, toVertexID), from.pos.Distance(to.pos)));
        m_edgeDuplicateControl.insert(edge(from.nodeID, to.nodeID));
    }
}

size_t TaxiPathGraph::GetCompleteNodeRoute(uint32 sourceNodeID, uint32 destinationNodeID, std::vector<uint32>& shortestPath)
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
    sObjectMgr->GetTaxiPath(sourceNodeID, destinationNodeID, pathId, goldCost);
    if (pathId)
        shortestPath = { sourceNodeID, destinationNodeID };
    else
    {
        shortestPath.clear();
        std::vector<vertex_descriptor> p(boost::num_vertices(m_graph));

        boost::dijkstra_shortest_paths(m_graph, _getVertexIDFromNodeID(sourceNodeID),
            boost::predecessor_map(boost::make_iterator_property_map(p.begin(), get(boost::vertex_index, m_graph))));

        // found a path to the goal
        for (vertex_descriptor v = _getVertexIDFromNodeID(destinationNodeID); ; v = p[v])
        {
            shortestPath.push_back(_getNodeIDFromVertexID(v));
            if (v == p[v])
                break;
        }

        std::reverse(shortestPath.begin(), shortestPath.end());
    }

    return shortestPath.size();
}

TaxiPathGraph::TaxiNodeInfo const* TaxiPathGraph::GetTaxiNodeInfoByID(uint32 nodeID)
{
    vertex_descriptor vertexID = _getVertexIDFromNodeID(nodeID);
    if (m_vertices.size() < vertexID)
        return nullptr;

    return &m_vertices[vertexID];
}

TaxiPathGraph::vertex_descriptor TaxiPathGraph::_createVertexFromFromNodeInfoIfNeeded(TaxiNodeInfo const& nodeInfo)
{
    //Check if we need a new one or if it may be already created
    if (m_nodeIDToVertexID.find(nodeInfo.nodeID) == m_nodeIDToVertexID.end())
    {
        vertex_descriptor verID = m_vertices.size();
        m_vertices.push_back(nodeInfo);
        m_nodeIDToVertexID[nodeInfo.nodeID] = verID;
        return verID;
    }

    return m_nodeIDToVertexID[nodeInfo.nodeID];
}
