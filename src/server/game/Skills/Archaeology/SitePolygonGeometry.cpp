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

//===========================================================================//
//      RESIZE NODES
//===========================================================================//

bool SitePolygonGraph::resize_nodes()
{
    SitePolygonGraphNode* tmpNodes = _nodes;
    index_type tmpSize             = _size_nodes++;
    _nodes                         = 0;

    try
    {
        if(_size_nodes > 0) _nodes = new SitePolygonGraphNode[_size_nodes];
        else _nodes                = 0;

        for(index_type i = 0; i < tmpSize; i++)
            _nodes[i].set(tmpNodes[i].get());

        delete[] tmpNodes;
    }
    catch(...)
    {
        _nodes      = tmpNodes;
        _size_nodes = tmpSize;

        return false;
    }

    return true;
}

//===========================================================================//
//      RESIZE ARCHES
//===========================================================================//

bool SitePolygonGraph::resize_arches()
{
    if(_size_nodes <= 0)
        return false;

    SitePolygonGraphArch* tmpArches  = _arches;
    index_type tmpSizeArches         = _size_arches++;
    _arches                          = 0;

    try
    {
        if(_size_arches > 0) _arches = new SitePolygonGraphArch[_size_arches];
        else _arches                 = 0;

        for(index_type i = 0; i < tmpSizeArches; i++)
            _arches[i].set(tmpArches[i].get());

        delete[] tmpArches;
    }
    catch(...)
    {
        _arches      = tmpArches;
        _size_arches = tmpSizeArches;

        return false;
    }

    return true;
}

//===========================================================================//
//      BOUNDARY GEOMETRY GENERATOR
//===========================================================================//

void SitePolygonGraph::generate_geometry()
{
    SitePolygonGraphNode last = _nodes[_size_nodes - 1];
    float x                   = last.getX();
    float y                   = last.getY();

    float x_plus              = x + 1.0;
    float x_minus             = x - 1.0;
    float y_plus              = y + 1.0;
    float y_minus             = y - 1.0;

    float ax_point            = float();
    float ay_point            = float();
    float bx_point            = float();
    float by_point            = float();

    if(_geometry.isNull())
    {
        _geometry.setLeft(x_minus, y_plus, x_minus, y_minus);
        _geometry.setBottom(x_minus, y_minus, x_plus, y_minus);
        _geometry.setRight(x_plus, y_minus, x_plus, y_plus);
        _geometry.setTop(x_plus, y_plus, x_minus, y_plus);

        _geometry.setNull(false);
        return;
    }

    // LEFT ARCH
    ax_point                  = _geometry.getLeft().getA().getX();
    ax_point                  = (ax_point >= x - 1.0) ? x_minus : ax_point;
    ay_point                  = _geometry.getLeft().getA().getY();
    ay_point                  = (ay_point <= y + 1.0) ? y_plus : ay_point;

    bx_point                  = _geometry.getLeft().getB().getX();
    bx_point                  = (bx_point >= x - 1.0) ? x_minus : bx_point;
    by_point                  = _geometry.getLeft().getB().getY();
    by_point                  = (by_point >= y - 1.0) ? y_minus : by_point;

    _geometry.setLeft(ax_point, ay_point, bx_point, by_point);

    // BOTTOM ARCH
    ax_point                  = _geometry.getBottom().getA().getX();
    ax_point                  = (ax_point >= x - 1.0) ? x_minus : ax_point;
    ay_point                  = _geometry.getBottom().getA().getY();
    ay_point                  = (ay_point >= y - 1.0) ? y_minus : ay_point;

    bx_point                  = _geometry.getBottom().getB().getX();
    bx_point                  = (bx_point <= x + 1.0) ? x_plus : bx_point;
    by_point                  = _geometry.getBottom().getB().getY();
    by_point                  = (by_point >= y - 1.0) ? y_minus : by_point;

    _geometry.setBottom(ax_point, ay_point, bx_point, by_point);

    // RIGHT ARCH
    ax_point                  = _geometry.getRight().getA().getX();
    ax_point                  = (ax_point <= x + 1.0) ? x_plus : ax_point;
    ay_point                  = _geometry.getRight().getA().getY();
    ay_point                  = (ay_point >= y - 1.0) ? y_minus : ay_point;

    bx_point                  = _geometry.getRight().getB().getX();
    bx_point                  = (bx_point <= x + 1.0) ? x_plus : bx_point;
    by_point                  = _geometry.getRight().getB().getY();
    by_point                  = (by_point <= y + 1.0) ? y_plus : by_point;

    _geometry.setRight(ax_point, ay_point, bx_point, by_point);

    // TOP ARCH
    ax_point                  = _geometry.getTop().getA().getX();
    ax_point                  = (ax_point <= x + 1.0) ? x_plus : ax_point;
    ay_point                  = _geometry.getTop().getA().getY();
    ay_point                  = (ay_point <= y + 1.0) ? y_plus : ay_point;

    bx_point                  = _geometry.getTop().getB().getX();
    bx_point                  = (bx_point >= x - 1.0) ? x_minus : bx_point;
    by_point                  = _geometry.getTop().getB().getY();
    by_point                  = (by_point <= y + 1.0) ? y_plus : by_point;

    _geometry.setTop(ax_point, ay_point, bx_point, by_point);
}

//===========================================================================//
//      GEOMETRY INSCRIBED GENERATOR
//===========================================================================//

void SitePolygonGraph::generate_geometry_inscribed()
{
    if(_size_nodes <= 1 && _size_arches <= 0)
        return;

    index_type max_value = _size_arches;

    for(index_type i = 0; i < _size_nodes; i++)
    {
        SitePolygonGraphNode node = _nodes[i];

        for(index_type n = 0; n < max_value; n++)
        {
            // Temporary arch
            SitePolygonGraphArch arch = _arches[n];

            // Create temporary arch for check
            SitePolygonGraphArch tmp;
            tmp.setA(node);
            tmp.setB(arch.getMidPoint());

            // Skip loops on nodes
            if(node == arch.getA() || node == arch.getB())
                continue;

            // Check if arches contains tmp
            if(arch_exists(tmp))
                continue;

            add_arch(tmp.getA(), tmp.getB());
        }
    }
}

//===========================================================================//
//      GEOMETRY INSCRIBED GENERATOR
//===========================================================================//

bool SitePolygonGraph::generate_geometry_fragmentation(SitePolygonGraphArch &base_arch)
{
    if(_size_arches <= 0)
        return false;

    // Number of intersection
    index_type N_INTSECD = 0;
    index_type N_REACHED = 0;

    // Test node
    SitePolygonGraphNode node_test;
    SitePolygonGraphNode node_test_boundary;

    // FRAGMENTATION WITH GEOMETRY BOUNDARY
    //-------------------------------------------------------------------------
    SitePolygonGraphArch geometry_arches[4];
    geometry_arches[0] = _geometry.getLeft();
    geometry_arches[1] = _geometry.getBottom();
    geometry_arches[2] = _geometry.getRight();
    geometry_arches[3] = _geometry.getTop();

    for(index_type n = 0; n < 4; n++)
    {
        // Arch from geometry
        SitePolygonGraphArch boundary_arch = geometry_arches[n];
        float intersect_X                  = float();
        float intersect_Y                  = float();
        bool  check_intersect_strict       = false;
        bool  check_intersect              = get_xy_intersect(base_arch, boundary_arch, intersect_X, intersect_Y, check_intersect_strict);
        bool  skip_check                   = false;

        // Save for current step
        SitePolygonGraphNode tmp_check;
        tmp_check.setX(intersect_X);
        tmp_check.setY(intersect_Y);

        if(n > 0)
        {
            // Check for duplicate start/end point
            skip_check = (node_test_boundary == tmp_check && check_intersect_strict);
        }

        // Save for next step
        node_test_boundary.setX(intersect_X);
        node_test_boundary.setY(intersect_Y);

        if(check_intersect && !skip_check)
            N_INTSECD += 1;
    }

    // FRAGMENTATION WITH GEOMETRY INSCRIBED
    //-------------------------------------------------------------------------
    bool is_ab_start      = false;
    bool is_md_start      = false;
    //-------------------------------------------------------------------------
    SitePolygonGraphNode ab_point;
    SitePolygonGraphNode md_point;

    for(index_type n = 0; n < SITE_POLYGON_GRAPH_MAX_VERTEX; n++)
    {
        // Arch from perimeter
        SitePolygonGraphArch boundary_arch = _arches[n];
        float intersect_X                  = float();
        float intersect_Y                  = float();
        bool  check_intersect_strict       = false;
        bool  check_intersect_line         = get_xy_intersect(base_arch, boundary_arch, intersect_X, intersect_Y, check_intersect_strict);

        // Set new values for test
        node_test.setX(intersect_X);
        node_test.setY(intersect_Y);

        // Pre-Check for possibile skip
        bool check_is_ab_point             = ((node_test == boundary_arch.getA() || node_test == boundary_arch.getB()) && check_intersect_strict);
        bool check_is_md_point             = ((node_test == boundary_arch.getMidPoint()) && check_intersect_strict);

        // Check for possibile skip
        if(check_is_ab_point && !is_ab_start)
        {
            is_ab_start = true;
            N_REACHED  += 1;

            ab_point.setX(intersect_X);
            ab_point.setY(intersect_Y);
        }
        else if(check_is_md_point && !is_md_start)
        {
            is_md_start = true;
            N_REACHED  += 1;

            md_point.setX(intersect_X);
            md_point.setY(intersect_Y);
        }
        // SAVE OTHERWISE!
        else if(check_intersect_line)
        {
            // Skip duplicate points on A, B, MD poi!
            if((is_ab_start && (ab_point == node_test)) ||
               (is_md_start && (md_point == node_test)))
                continue;

            if(check_intersect_strict)
            {
                N_REACHED += 1;
            }
            else
            {
                N_INTSECD += 1;
            }
        }
    }

    // FIX FRAGMENTATION WITH GEOMETRY
    //-------------------------------------------------------------------------
    if(N_REACHED == 2 && is_ab_start && is_md_start)
    {
        if(N_INTSECD == 2)
            return true;
    }

    // Force FALSE
    return false;
}

//===========================================================================//
//      MERGE PERIMETER
//===========================================================================//

bool SitePolygonGraph::merge_perimeter()
{
    SitePolygonGraphNode prev = _nodes[_size_nodes - 2];
    SitePolygonGraphNode last = _nodes[_size_nodes - 1];
    bool check                = true;

    if(_size_nodes > 2)
    {
        check = (check && add_arch(prev, last, true));
        _arches[0].setA(last);
    }
    else
    {
        check = (check && add_arch(last, prev, true));
        check = (check && add_arch(prev, last, true));
    }

    return check;
}

//===========================================================================//
//      CHECK SAVED ARCHES
//===========================================================================//

bool SitePolygonGraph::arch_exists(const SitePolygonGraphArch &arch)
{
    if(_size_arches <= 0)
        return false;

    for(index_type i = 0; i < _size_arches; i++)
        if(_arches[i] == arch)
            return true;

    return false;
}

//===========================================================================//
//      CALCULATE INTERSECTION FROM TWO ARCHES
//===========================================================================//

bool SitePolygonGraph::get_xy_intersect(const SitePolygonGraphArch &arch1, const SitePolygonGraphArch &arch2, float &TX, float &TY, bool &DCHECK)
{
    TX              = float();
    TY              = float();
    DCHECK          = false;

    //---------------------------------------------------------------------
    // Arch flag
    bool is_m1_null = false;
    bool is_m1_inf  = false;
    bool is_m2_null = false;
    bool is_m2_inf  = false;

    //---------------------------------------------------------------------
    // Temporary save base_arch values
    float P1_X      = arch1.getA().getX();
    float P1_Y      = arch1.getA().getY();
    float P2_X      = arch1.getB().getX();
    float P2_Y      = arch1.getB().getY();

    //---------------------------------------------------------------------
    // Temporary save perimeter_arch values
    float P3_X      = arch2.getA().getX();
    float P3_Y      = arch2.getA().getY();
    float P4_X      = arch2.getB().getX();
    float P4_Y      = arch2.getB().getY();

    //---------------------------------------------------------------------
    // Swap values
    float PX_1      = P1_X > P2_X ? P2_X : P1_X;
    float PY_1      = P1_X > P2_X ? P2_Y : P1_Y;
    float PX_2      = P1_X > P2_X ? P1_X : P2_X;
    float PY_2      = P1_X > P2_X ? P1_Y : P2_Y;

    float PX_3      = P3_X > P4_X ? P4_X : P3_X;
    float PY_3      = P3_X > P4_X ? P4_Y : P3_Y;
    float PX_4      = P3_X > P4_X ? P3_X : P4_X;
    float PY_4      = P3_X > P4_X ? P3_Y : P4_Y;

    //---------------------------------------------------------------------
    // Calculate line ONE
    float DX_1      = PX_2 - PX_1;
    float DY_1      = PY_2 - PY_1;
    float M_1       = float();

    if(DX_1 == 0)
    {
        is_m1_inf   = true;
        M_1         = 0;
    }
    else if(DY_1 == 0)
    {
        is_m1_null  = true;
        M_1         = 0;
    }
    else M_1        = DY_1 / DX_1;

    //---------------------------------------------------------------------
    // Calculate intercept for line ONE
    float INTCP_1   = PY_1 - M_1 * PX_1;

    //---------------------------------------------------------------------
    // Calculate line TWO
    float DX_2      = PX_4 - PX_3;
    float DY_2      = PY_4 - PY_3;
    float M_2       = float();

    if(DX_2 == 0)
    {
        is_m2_inf   = true;
        M_2         = 0;
    }
    else if(DY_2 == 0)
    {
        is_m2_null  = true;
        M_2         = 0;
    }
    else M_2        = DY_2 / DX_2;

    //---------------------------------------------------------------------
    // Calculate intercept for line TWO
    float INTCP_2   = PY_3 - M_2 * PX_3;

    //---------------------------------------------------------------------
    // Check deltas
    if(((M_1 - M_2) != 0) || is_m1_inf || is_m2_inf)
    {
        // Calculate T parameter from segment equation
        float TK_1X = float();
        float TK_1Y = float();
        float TK_2X = float();
        float TK_2Y = float();

        // Save temporary XY
        float IX    = float();
        float IY    = float();

        if(M_1 != 0 && M_2 != 0)
        {
            IX      = (INTCP_2 - INTCP_1) / (M_1 - M_2);
            IY      = (M_1 * IX + INTCP_1);
            TK_1X   = (IX - PX_1) / (PX_2 - PX_1);
            TK_1Y   = (IY - PY_1) / (PY_2 - PY_1);
            TK_2X   = (IX - PX_3) / (PX_4 - PX_3);
            TK_2Y   = (IY - PY_3) / (PY_4 - PY_3);
        }
        else if(is_m1_inf && M_2 != 0)
        {
            IX      = PX_1;
            IY      = M_2 * IX + INTCP_2;
            TK_1X   = 1;
            TK_1Y   = (IY - PY_1) / (PY_2 - PY_1);
            TK_2X   = (IX - PX_3) / (PX_4 - PX_3);
            TK_2Y   = (IY - PY_3) / (PY_4 - PY_3);
        }
        else if(is_m1_null && M_2 != 0)
        {
            IY      = PY_1;
            IX      = (IY - INTCP_2) / M_2;
            TK_1Y   = 1;
            TK_1X   = (IX - PX_1) / (PX_2 - PX_1);
            TK_2X   = (IX - PX_3) / (PX_4 - PX_3);
            TK_2Y   = (IY - PY_3) / (PY_4 - PY_3);
        }
        else if(is_m2_inf && M_1 != 0)
        {
            IX      = PX_3;
            IY      = M_1 * IX + INTCP_1;
            TK_1X   = (IX - PX_1) / (PX_2 - PX_1);
            TK_1Y   = (IY - PY_1) / (PY_2 - PY_1);
            TK_2Y   = (IY - PY_3) / (PY_4 - PY_3);
            TK_2X   = 1;
        }
        else if(is_m2_null && M_1 != 0)
        {
            IY      = PY_3;
            IX      = (IY - INTCP_1) / M_1;
            TK_1X   = (IX - PX_1) / (PX_2 - PX_1);
            TK_1Y   = (IY - PY_1) / (PY_2 - PY_1);
            TK_2X   = (IX - PX_3) / (PX_4 - PX_3);
            TK_2Y   = 1;
        }
        else if((is_m1_null && is_m2_inf) || (is_m2_null && is_m1_inf))
        {
            IX      = PX_1;
            IY      = PY_3;

            if(is_m1_null && is_m2_inf)
            {
                TK_1Y   = 1;
                TK_1X   = (IX - PX_1) / (PX_2 - PX_1);
                TK_2Y   = (IY - PY_3) / (PY_4 - PY_3);
                TK_2X   = 1;
            }
            else if(is_m2_null && is_m1_inf)
            {
                TK_1X   = 1;
                TK_1Y   = (IY - PY_1) / (PY_2 - PY_1);
                TK_2X   = (IX - PX_3) / (PX_4 - PX_3);
                TK_2Y   = 1;
            }
        }

        // Check if T is valid into (0; 1)
        bool CKTK_1X = (TK_1X >= 0.0 && TK_1X <= 1.0);
        bool CKTK_1Y = (TK_1Y >= 0.0 && TK_1Y <= 1.0);
        bool CKTK_2X = (TK_2X >= 0.0 && TK_2X <= 1.0);
        bool CKTK_2Y = (TK_2Y >= 0.0 && TK_2Y <= 1.0);

        // Double check
        bool T_CHECK = (CKTK_2X && CKTK_2Y);
             DCHECK  = (CKTK_1X && CKTK_1Y && CKTK_2X && CKTK_2Y);

        // Return value
        if(T_CHECK)
        {
            // Set XY
            TX       = IX;
            TY       = IY;

            // Return TRUE
            return true;
        }
    }

    // Force FALSE
    return false;
}
