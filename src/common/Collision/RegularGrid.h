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

#ifndef _REGULAR_GRID_H
#define _REGULAR_GRID_H

#include "Errors.h"
#include "IteratorPair.h"
#include <G3D/Ray.h>
#include <G3D/BoundsTrait.h>
#include <memory>
#include <unordered_map>

template<class Node>
struct NodeCreator{
    static Node * makeNode(int /*x*/, int /*y*/) { return new Node();}
};

template<class T,
class Node,
class NodeCreatorFunc = NodeCreator<Node>,
class BoundsFunc = BoundsTrait<T>
>
class TC_COMMON_API RegularGrid2D
{
public:

    enum{
        CELL_NUMBER = 64,
    };

    #define CELL_SIZE       533.33333f

    typedef std::unordered_multimap<T const*, Node*> MemberTable;

    MemberTable memberTable;
    std::unique_ptr<Node> nodes[CELL_NUMBER][CELL_NUMBER] = { };

    void insert(T const& value)
    {
        G3D::AABox bounds = G3D::AABox::empty();
        BoundsFunc::getBounds(value, bounds);
        Cell low = Cell::ComputeCell(bounds.low().x, bounds.low().y);
        Cell high = Cell::ComputeCell(bounds.high().x, bounds.high().y);
        for (int x = low.x; x <= high.x; ++x)
        {
            for (int y = low.y; y <= high.y; ++y)
            {
                Node& node = getGrid(x, y);
                node.insert(value);
                memberTable.emplace(&value, &node);
            }
        }
    }

    void remove(T const& value)
    {
        for (auto& p : Trinity::Containers::MapEqualRange(memberTable, &value))
            p.second->remove(value);
        // Remove the member
        memberTable.erase(&value);
    }

    void balance()
    {
        for (int x = 0; x < CELL_NUMBER; ++x)
            for (int y = 0; y < CELL_NUMBER; ++y)
                if (Node* n = nodes[x][y].get())
                    n->balance();
    }

    bool contains(T const& value) const { return memberTable.contains(&value); }
    bool empty() const { return memberTable.empty(); }

    struct Cell
    {
        int x, y;

        friend bool operator==(Cell const&, Cell const&) = default;

        static Cell ComputeCell(float fx, float fy)
        {
            return { .x = int(fx * (1.f / CELL_SIZE) + (CELL_NUMBER / 2)), .y = int(fy * (1.f / CELL_SIZE) + (CELL_NUMBER / 2)) };
        }

        bool isValid() const { return x >= 0 && x < CELL_NUMBER && y >= 0 && y < CELL_NUMBER; }
    };

    Node& getGrid(int x, int y)
    {
        ASSERT(x < CELL_NUMBER && y < CELL_NUMBER);
        if (!nodes[x][y])
            nodes[x][y].reset(NodeCreatorFunc::makeNode(x, y));
        return *nodes[x][y];
    }

    template<typename RayCallback>
    void intersectRay(G3D::Ray const& ray, RayCallback& intersectCallback, float max_dist)
    {
        intersectRay(ray, intersectCallback, max_dist, ray.origin() + ray.direction() * max_dist);
    }

    template<typename RayCallback>
    void intersectRay(G3D::Ray const& ray, RayCallback& intersectCallback, float& max_dist, G3D::Vector3 const& end)
    {
        Cell cell = Cell::ComputeCell(ray.origin().x, ray.origin().y);
        if (!cell.isValid())
            return;

        Cell last_cell = Cell::ComputeCell(end.x, end.y);

        if (cell == last_cell)
        {
            if (Node* node = nodes[cell.x][cell.y].get())
                node->intersectRay(ray, intersectCallback, max_dist);
            return;
        }

        float voxel = (float)CELL_SIZE;
        float kx_inv = ray.invDirection().x, bx = ray.origin().x;
        float ky_inv = ray.invDirection().y, by = ray.origin().y;

        int stepX, stepY;
        float tMaxX, tMaxY;
        if (kx_inv >= 0)
        {
            stepX = 1;
            float x_border = (cell.x+1) * voxel;
            tMaxX = (x_border - bx) * kx_inv;
        }
        else
        {
            stepX = -1;
            float x_border = (cell.x-1) * voxel;
            tMaxX = (x_border - bx) * kx_inv;
        }

        if (ky_inv >= 0)
        {
            stepY = 1;
            float y_border = (cell.y+1) * voxel;
            tMaxY = (y_border - by) * ky_inv;
        }
        else
        {
            stepY = -1;
            float y_border = (cell.y-1) * voxel;
            tMaxY = (y_border - by) * ky_inv;
        }

        //int Cycles = std::max((int)ceilf(max_dist/tMaxX),(int)ceilf(max_dist/tMaxY));
        //int i = 0;

        float tDeltaX = voxel * std::fabs(kx_inv);
        float tDeltaY = voxel * std::fabs(ky_inv);
        do
        {
            if (Node* node = nodes[cell.x][cell.y].get())
            {
                //float enterdist = max_dist;
                node->intersectRay(ray, intersectCallback, max_dist);
            }
            if (cell == last_cell)
                break;
            if (tMaxX < tMaxY)
            {
                tMaxX += tDeltaX;
                cell.x += stepX;
            }
            else
            {
                tMaxY += tDeltaY;
                cell.y += stepY;
            }
            //++i;
        } while (cell.isValid());
    }

    template<typename IsectCallback>
    void intersectPoint(G3D::Vector3 const& point, IsectCallback& intersectCallback)
    {
        Cell cell = Cell::ComputeCell(point.x, point.y);
        if (!cell.isValid())
            return;
        if (Node* node = nodes[cell.x][cell.y].get())
            node->intersectPoint(point, intersectCallback);
    }

    // Optimized verson of intersectRay function for rays with vertical directions
    template<typename RayCallback>
    void intersectZAllignedRay(G3D::Ray const& ray, RayCallback& intersectCallback, float& max_dist)
    {
        Cell cell = Cell::ComputeCell(ray.origin().x, ray.origin().y);
        if (!cell.isValid())
            return;
        if (Node* node = nodes[cell.x][cell.y].get())
            node->intersectRay(ray, intersectCallback, max_dist);
    }

    std::span<T const* const> getObjects(int x, int y) const
    {
        if (Node* n = nodes[x][y].get())
            return n->getObjects();
        return {};
    }
};

#undef CELL_SIZE

#endif
