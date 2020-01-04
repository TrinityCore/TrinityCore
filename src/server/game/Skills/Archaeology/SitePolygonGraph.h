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

#ifndef SITE_POLYGON_GRAPH_GENERATOR_H
#define SITE_POLYGON_GRAPH_GENERATOR_H

#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include <cmath>       /* math, roundf */

//===========================================================================//
//      GLOBAL DEFINE
//===========================================================================//

#define SITE_POLYGON_GRAPH_MAX_VERTEX 12

//===========================================================================//
//      POLYGON SUB-STRUCT FOR NODES
//===========================================================================//

struct SitePolygonGraphNode
{
public:
    SitePolygonGraphNode()
    {
        _pointX = float();
        _pointY = float();
    }

    bool operator==(const SitePolygonGraphNode &other) const
    {
        float tX   = other.getX();
        float tY   = other.getY();

        float cX_m = _pointX - 0.1;
        float cY_m = _pointY - 0.1;
        float cX_p = _pointX + 0.1;
        float cY_p = _pointY + 0.1;

        bool x     = (cX_m <= tX && tX <= cX_p);
        bool y     = (cY_m <= tY && tY <= cY_p);

        if(x && y) return true;
        else return false;
    }

    void set(const SitePolygonGraphNode &node)  { _pointX = node.getX(); _pointY = node.getY(); _round_p(); }
    void set(const float &x, const float &y)    { _pointX = x; _pointY = y; _round_p(); }

    void setX(const float &x)                   { _pointX = x; _round_p(); }
    void setY(const float &y)                   { _pointY = y; _round_p(); }

    float getX() const                          { return _pointX; }
    float getY() const                          { return _pointY; }

    const SitePolygonGraphNode get() const      { return (*this); }

private:
    void _round_p()
    {
        _pointX = roundf(_pointX * 10) / 10;
        _pointY = roundf(_pointY * 10) / 10;
    }

    float _pointX;
    float _pointY;
};

//===========================================================================//
//      POLYGON SUB-STRUCT FOR ARCHES
//===========================================================================//

struct SitePolygonGraphArch
{
public:
    SitePolygonGraphArch()
    {
        _pointA   = SitePolygonGraphNode();
        _pointB   = SitePolygonGraphNode();
        _midpoint = SitePolygonGraphNode();
    }

    void set(const SitePolygonGraphArch &arch)
    {
        _pointA.set(arch.getA());
        _pointB.set(arch.getB());

        _calculateMidPoint();
    }

    bool operator==(const SitePolygonGraphArch &other) const
    {
        bool an = (other.getA() == _pointA);
        bool bn = (other.getB() == _pointB);
        bool ai = (other.getA() == _pointB);
        bool bi = (other.getB() == _pointA);

        if((an && bn) || (ai && bi)) return true;
        else return false;
    }

    void setA(const SitePolygonGraphNode &node)         { _pointA.set(node.get()); _calculateMidPoint(); }
    void setB(const SitePolygonGraphNode &node)         { _pointB.set(node.get()); _calculateMidPoint(); }

    void setA(const float &x, const float &y)           { _pointA.set(x, y); _calculateMidPoint(); }
    void setB(const float &x, const float &y)           { _pointB.set(x, y); _calculateMidPoint(); }

    const SitePolygonGraphArch get()         const      { return (*this); }
    const SitePolygonGraphNode getA()        const      { return _pointA; }
    const SitePolygonGraphNode getB()        const      { return _pointB; }
    const SitePolygonGraphNode getMidPoint() const      { return _midpoint; }

private:
    void _calculateMidPoint()
    {
        float midX = (_pointB.getX() + _pointA.getX()) / 2;
        float midY = (_pointB.getY() + _pointA.getY()) / 2;

        _midpoint.set(midX, midY);
    }

    SitePolygonGraphNode _pointA;
    SitePolygonGraphNode _pointB;
    SitePolygonGraphNode _midpoint;
};

//===========================================================================//
//      POLYGON SUB-STRUCT FOR GEOMETRY
//===========================================================================//

struct SitePolygonGraphGeometry
{
public:
    SitePolygonGraphGeometry()
    {
        _archL  = SitePolygonGraphArch();
        _archB  = SitePolygonGraphArch();
        _archR  = SitePolygonGraphArch();
        _archT  = SitePolygonGraphArch();
        _isNull = true;
    }

    void set(const SitePolygonGraphGeometry &geo)
    {
        _archL.set(geo.getLeft());
        _archB.set(geo.getBottom());
        _archR.set(geo.getRight());
        _archT.set(geo.getTop());
    }

    void setLeft(const SitePolygonGraphArch &arch)    { _archL.set(arch.get()); }
    void setBottom(const SitePolygonGraphArch &arch)  { _archB.set(arch.get()); }
    void setRight(const SitePolygonGraphArch &arch)   { _archR.set(arch.get()); }
    void setTop(const SitePolygonGraphArch &arch)     { _archT.set(arch.get()); }
    void setNull(const bool &val)                     { _isNull = val; }

    void setLeft(const SitePolygonGraphNode &nodeA,
                 const SitePolygonGraphNode &nodeB)   { _archL.setA(nodeA); _archL.setB(nodeB); }
    void setBottom(const SitePolygonGraphNode &nodeA,
                   const SitePolygonGraphNode &nodeB) { _archB.setA(nodeA); _archB.setB(nodeB); }
    void setRight(const SitePolygonGraphNode &nodeA,
                  const SitePolygonGraphNode &nodeB)  { _archR.setA(nodeA); _archR.setB(nodeB); }
    void setTop(const SitePolygonGraphNode &nodeA,
                const SitePolygonGraphNode &nodeB)    { _archT.setA(nodeA); _archT.setB(nodeB); }

    void setLeft(const float &ax, const float &ay,
                 const float &bx, const float &by)    { _archL.setA(ax, ay); _archL.setB(bx, by); }
    void setBottom(const float &ax, const float &ay,
                   const float &bx, const float &by)  { _archB.setA(ax, ay); _archB.setB(bx, by); }
    void setRight(const float &ax, const float &ay,
                  const float &bx, const float &by)   { _archR.setA(ax, ay); _archR.setB(bx, by); }
    void setTop(const float &ax, const float &ay,
                const float &bx, const float &by)     { _archT.setA(ax, ay); _archT.setB(bx, by); }

    const SitePolygonGraphGeometry get()       const  { return (*this); }
    const SitePolygonGraphArch     getLeft()   const  { return _archL; }
    const SitePolygonGraphArch     getBottom() const  { return _archB; }
    const SitePolygonGraphArch     getRight()  const  { return _archR; }
    const SitePolygonGraphArch     getTop()    const  { return _archT; }
    bool isNull()                              const  { return _isNull; }

private:
    SitePolygonGraphArch _archL;
    SitePolygonGraphArch _archR;
    SitePolygonGraphArch _archT;
    SitePolygonGraphArch _archB;
    bool                 _isNull;
};

//===========================================================================//
//      POLYGON GRAPH MASTER CLASS
//===========================================================================//

class SitePolygonGraph
{
public:
    SitePolygonGraph();
    ~SitePolygonGraph();

    bool add_node(const SitePolygonGraphNode &node);
    bool add_node(const float &x, const float &y);
    bool add_arch(const SitePolygonGraphNode &nodeA, const SitePolygonGraphNode &nodeB, bool skip_check = false);

    void finalize_polygon();
    SitePolygonGraphNode randomize_poi();

private:
    bool resize_nodes();
    bool resize_arches();

    bool merge_perimeter();
    bool arch_exists(const SitePolygonGraphArch &arch);

    void generate_geometry();
    void generate_geometry_inscribed();
    bool generate_geometry_fragmentation(SitePolygonGraphArch &base_arch);

    bool get_xy_intersect(const SitePolygonGraphArch &arch1, const SitePolygonGraphArch &arch2, float &TX, float &TY, bool &dcheck);

    typedef unsigned int        index_type;
    typedef float               value_type;

    SitePolygonGraphNode*       _nodes;
    SitePolygonGraphArch*       _arches;
    SitePolygonGraphGeometry    _geometry;

    index_type                  _size_nodes;
    index_type                  _size_arches;
};

//---------------------------------------------------------------------------//

#endif  // SITE_POLYGON_GRAPH_GENERATOR_H
