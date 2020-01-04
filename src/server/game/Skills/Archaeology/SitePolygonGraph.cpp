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

#include "SitePolygonGraph.h"
#include "Random.h"

//===========================================================================//
//      CLASS BASE METHODS
//===========================================================================//

SitePolygonGraph::SitePolygonGraph()
{
    // Commons
    _arches      = 0;
    _nodes       = 0;
    _size_nodes  = 0;
    _size_arches = 0;
    _geometry    = SitePolygonGraphGeometry();

    // use current time as seed for random generator
    std::srand(std::time(0));
}

SitePolygonGraph::~SitePolygonGraph()
{
    // Mem. Leaks free
    if(!_nodes) return;
    delete[] _nodes;

    // Mem. Leaks free
    if(!_arches) return;
    delete[] _arches;
}

//===========================================================================//
//      ADD NEW NODE TO POOL
//===========================================================================//

bool SitePolygonGraph::add_node(const SitePolygonGraphNode &node)
{
    return add_node(node.getX(), node.getY());
}

bool SitePolygonGraph::add_node(const float &x, const float &y)
{
    if(!resize_nodes())
        return false;

    _nodes[_size_nodes - 1].setX(x);
    _nodes[_size_nodes - 1].setY(y);

    // Generate boundary rectangle
    generate_geometry();

    if(_size_nodes > 1)
        return this->merge_perimeter();

    return true;
}

//===========================================================================//
//      ADD NEW ARCH TO POOL
//===========================================================================//

bool SitePolygonGraph::add_arch(const SitePolygonGraphNode &nodeA, const SitePolygonGraphNode &nodeB, bool skip_check)
{
    SitePolygonGraphArch tmp;
    tmp.setA(nodeA);
    tmp.setB(nodeB);

    // Check selector
    bool check = skip_check ? true : generate_geometry_fragmentation(tmp);

    // CHECK FOR FRAGMENTATION
    if(check)
    {
        if(!resize_arches())
            return false;

        // SAVE ARCH AND RETURN
        _arches[_size_arches - 1].set(tmp);
    }
    else return false;

    // Force TRUE
    return true;
}

//===========================================================================//
//      FINALIZE CREATION OF POLYGON (GEOMETRY INSCRIBED)
//===========================================================================//

void SitePolygonGraph::finalize_polygon()
{
    // Arches filtering
    generate_geometry_inscribed();
}

//===========================================================================//
//      CALCULATE RANDOM POINT ON RANDOM ARCH FOR SPAWN POI
//===========================================================================//

SitePolygonGraphNode SitePolygonGraph::randomize_poi()
{
    SitePolygonGraphNode poi_node;
    index_type i_poi[SITE_POLYGON_GRAPH_MAX_VERTEX];

    if (_size_arches <= 0)
        return poi_node;

    for (index_type i = 0; i < SITE_POLYGON_GRAPH_MAX_VERTEX; i++)
        i_poi[i] = urand(0, _size_arches - 2);

    index_type i_idx            = urand(0, SITE_POLYGON_GRAPH_MAX_VERTEX - 1);
    float i_segment             = frand(0, 1.0f);
    SitePolygonGraphArch arch   = _arches[i_poi[i_idx]];
    float x_segment             = arch.getA().getX() + i_segment * (arch.getB().getX() - arch.getA().getX());
    float y_segment             = arch.getA().getY() + i_segment * (arch.getB().getY() - arch.getA().getY());

    poi_node.setX(x_segment);
    poi_node.setY(y_segment);

    return poi_node;
}
