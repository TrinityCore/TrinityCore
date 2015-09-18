#ifndef TAXIPATHGRAPH_HPP
#define TAXIPATHGRAPH_HPP

#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <vector>
#include "Define.h"

class TaxiPathGraph
{
public:
    struct Location
    {
        Location(float posX, float posY, float posZ): x(posX), y(posY), z(posZ) { }
        float Distance(Location const& to) const { return sqrt(pow(to.x - x, 2) + pow(to.y - y, 2) + pow(to.z - z, 2)); }
        float x;
        float y;
        float z;
    };
    struct TaxiNodeInfo
    {
        TaxiNodeInfo(uint32 id, std::string const& flightName, uint32 mapid, float posX, float posY, float posZ): nodeID(id), name(flightName), mapId(mapid), pos(posX, posY, posZ)
        {
            name.erase(std::remove(name.begin(), name.end(), '\"' ), name.end());
        }
        uint32 nodeID;
        std::string name;
        uint32 mapId;
        Location pos;
    };
    static TaxiPathGraph* instance()
    {
        static TaxiPathGraph instance;
        return &instance;
    }
    ~TaxiPathGraph();

    static void Initialize();
    static size_t GetCompleteNodeRoute(uint32 /* sourceNodeID */, uint32 /* destinationNodeID */, std::vector<uint32>& /* shortestPath */);
    static TaxiNodeInfo const* GetTaxiNodeInfoByID(uint32 nodeID);

private:
    typedef float cost;

    // specify some types
    typedef boost::adjacency_list<boost::listS, boost::vecS, boost::directedS, boost::property<boost::vertex_index_t, uint32>, boost::property<boost::edge_weight_t, cost>> Graph;
    typedef boost::property_map<Graph, boost::edge_weight_t>::type WeightMap;
    typedef Graph::vertex_descriptor vertex_descriptor;
    typedef Graph::edge_descriptor edge_descriptor;
    typedef std::pair<uint32, uint32> edge;

    static Graph m_graph;
    static std::vector<TaxiNodeInfo> m_vertices;
    static std::map<uint32, vertex_descriptor> m_nodeIDToVertexID;
    static std::set<edge> m_edgeDuplicateControl;
    static const int MaxFlightDistanceThreshold;

    static void _addVerticeAndEdgeFromNodeInfo(TaxiNodeInfo const& /* from */, TaxiNodeInfo const& /* to */, uint32 /* money */, std::vector<std::pair<edge, cost>>& /* edgeList */);
    TaxiPathGraph();
    TaxiPathGraph(TaxiPathGraph const&) = delete;
    TaxiPathGraph& operator=(TaxiPathGraph const&) = delete;

    static vertex_descriptor _getVertexIDFromNodeID(uint32 nodeID);
    static vertex_descriptor _getVertexIDFromNodeID(TaxiNodeInfo const& nodeInfo);
    static uint32 _getNodeIDFromVertexID(vertex_descriptor vertexID);
    static vertex_descriptor _createVertexFromFromNodeInfoIfNeeded(TaxiNodeInfo const&);
    static size_t _getVertexCount();
};

#define sTaxiPathGraph TaxiPathGraph::instance()

#endif    /* TAXIPATHGRAPH_HPP */
