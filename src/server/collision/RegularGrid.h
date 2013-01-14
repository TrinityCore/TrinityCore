#ifndef _REGULAR_GRID_H
#define _REGULAR_GRID_H


#include <G3D/Ray.h>
#include <G3D/AABox.h>
#include <G3D/Table.h>
#include <G3D/BoundsTrait.h>
#include <G3D/PositionTrait.h>

#include "Errors.h"

using G3D::Vector2;
using G3D::Vector3;
using G3D::AABox;
using G3D::Ray;

template<class Node>
struct NodeCreator{
    static Node * makeNode(int /*x*/, int /*y*/) { return new Node();}
};

template<class T,
class Node,
class NodeCreatorFunc = NodeCreator<Node>,
    /*class BoundsFunc = BoundsTrait<T>,*/
class PositionFunc = PositionTrait<T>
>
class RegularGrid2D
{
public:

    enum{
        CELL_NUMBER = 64,
    };

    #define HGRID_MAP_SIZE  (533.33333f * 64.f)     // shouldn't be changed
    #define CELL_SIZE       float(HGRID_MAP_SIZE/(float)CELL_NUMBER)

    typedef G3D::Table<const T*, Node*> MemberTable;

    MemberTable memberTable;
    Node* nodes[CELL_NUMBER][CELL_NUMBER];

    RegularGrid2D(){
        memset(nodes, 0, sizeof(nodes));
    }

    ~RegularGrid2D(){
        for (int x = 0; x < CELL_NUMBER; ++x)
            for (int y = 0; y < CELL_NUMBER; ++y)
                delete nodes[x][y];
    }

    void insert(const T& value)
    {
        Vector3 pos;
        PositionFunc::getPosition(value, pos);
        Node& node = getGridFor(pos.x, pos.y);
        node.insert(value);
        memberTable.set(&value, &node);
    }

    void remove(const T& value)
    {
        memberTable[&value]->remove(value);
        // Remove the member
        memberTable.remove(&value);
    }

    void balance()
    {
        for (int x = 0; x < CELL_NUMBER; ++x)
            for (int y = 0; y < CELL_NUMBER; ++y)
                if (Node* n = nodes[x][y])
                    n->balance();
    }

    bool contains(const T& value) const { return memberTable.containsKey(&value); }
    int size() const { return memberTable.size(); }

    struct Cell
    {
        int x, y;
        bool operator == (const Cell& c2) const { return x == c2.x && y == c2.y;}

        static Cell ComputeCell(float fx, float fy)
        {
            Cell c = { int(fx * (1.f/CELL_SIZE) + (CELL_NUMBER/2)), int(fy * (1.f/CELL_SIZE) + (CELL_NUMBER/2)) };
            return c;
        }

        bool isValid() const { return x >= 0 && x < CELL_NUMBER && y >= 0 && y < CELL_NUMBER;}
    };


    Node& getGridFor(float fx, float fy)
    {
        Cell c = Cell::ComputeCell(fx, fy);
        return getGrid(c.x, c.y);
    }

    Node& getGrid(int x, int y)
    {
        ASSERT(x < CELL_NUMBER && y < CELL_NUMBER);
        if (!nodes[x][y])
            nodes[x][y] = NodeCreatorFunc::makeNode(x, y);
        return *nodes[x][y];
    }

    template<typename RayCallback>
    void intersectRay(const Ray& ray, RayCallback& intersectCallback, float max_dist)
    {
        intersectRay(ray, intersectCallback, max_dist, ray.origin() + ray.direction() * max_dist);
    }

    template<typename RayCallback>
    void intersectRay(const Ray& ray, RayCallback& intersectCallback, float& max_dist, const Vector3& end)
    {
        Cell cell = Cell::ComputeCell(ray.origin().x, ray.origin().y);
        if (!cell.isValid())
            return;

        Cell last_cell = Cell::ComputeCell(end.x, end.y);

        if (cell == last_cell)
        {
            if (Node* node = nodes[cell.x][cell.y])
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

        float tDeltaX = voxel * fabs(kx_inv);
        float tDeltaY = voxel * fabs(ky_inv);
        do
        {
            if (Node* node = nodes[cell.x][cell.y])
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
    void intersectPoint(const Vector3& point, IsectCallback& intersectCallback)
    {
        Cell cell = Cell::ComputeCell(point.x, point.y);
        if (!cell.isValid())
            return;
        if (Node* node = nodes[cell.x][cell.y])
            node->intersectPoint(point, intersectCallback);
    }

    // Optimized verson of intersectRay function for rays with vertical directions
    template<typename RayCallback>
    void intersectZAllignedRay(const Ray& ray, RayCallback& intersectCallback, float& max_dist)
    {
        Cell cell = Cell::ComputeCell(ray.origin().x, ray.origin().y);
        if (!cell.isValid())
            return;
        if (Node* node = nodes[cell.x][cell.y])
            node->intersectRay(ray, intersectCallback, max_dist);
    }
};

#undef CELL_SIZE
#undef HGRID_MAP_SIZE

#endif
