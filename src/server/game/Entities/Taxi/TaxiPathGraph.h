#ifndef TAXIPATHGRAPH_HPP
#define TAXIPATHGRAPH_HPP

#include <boost/graph/astar_search.hpp>
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
        TaxiNodeInfo(uint32 id, std::string const& flightName, float posX, float posY, float posZ): nodeID(id), name(flightName), pos(posX, posY, posZ)
        {
            name.erase(std::remove(name.begin(), name.end(), '\"' ), name.end());
        }
        uint32 nodeID;
        std::string name;
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

    struct found_goal {}; // exception for termination

    // visitor that terminates when we find the goal
    template <class Vertex>
    class astar_goal_visitor : public boost::default_astar_visitor
    {
    public:
        astar_goal_visitor(Vertex goal) : m_goal(goal) {}
        template <class Graph>
        void examine_vertex(Vertex u, Graph& /* g */) {
            if(u == m_goal)
                throw found_goal();
        }
    private:
        Vertex m_goal;
    };
    
    // specify some types
    typedef boost::adjacency_list<boost::listS, boost::vecS, boost::directedS, boost::property<boost::vertex_index_t, uint32>, boost::property<boost::edge_weight_t, cost> > Graph;
    typedef boost::property_map<Graph, boost::edge_weight_t>::type WeightMap;
    typedef boost::property_map<Graph, boost::vertex_index_t>::type IndexMap;
    typedef Graph::vertex_descriptor vertex;
    typedef Graph::edge_descriptor edge_descriptor;
    typedef Graph::vertex_descriptor vertex_descriptor;
    typedef Graph::vertex_iterator vertex_iterator;
    typedef std::pair<uint32, uint32> edge;
    
    static Graph m_graph;
    static std::vector<TaxiNodeInfo> m_vertices;
    static std::map<uint32, vertex> m_nodeIDToVertexID;
    static std::set<edge> m_edgeDuplicateControl;
    static const int MaxFlightDistanceThreshold;
    
    static void _addVerticeAndEdgeFromNodeInfo(TaxiNodeInfo const& /* from */, TaxiNodeInfo const& /* to */, uint32 /* money */, std::vector<std::pair<edge, cost>>& /* edgeList */);
    TaxiPathGraph();
    TaxiPathGraph(TaxiPathGraph const&) = delete;
    TaxiPathGraph& operator=(TaxiPathGraph const&) = delete;
    
    static vertex _getVertexIDFromNodeID(uint32 nodeID);
    static vertex _getVertexIDFromNodeID(TaxiNodeInfo const& nodeInfo);
    static uint32 _getNodeIDFromVertexID(vertex vertexID);
    static vertex _createVertexFromFromNodeInfoIfNeeded(TaxiNodeInfo const&);
    static size_t _getVertexCount();
};

#define sTaxiPathGraph TaxiPathGraph::instance()

#endif	/* TAXIPATHGRAPH_HPP */
