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

#ifndef _BIH_H
#define _BIH_H

#include <G3D/Vector3.h>
#include <G3D/Ray.h>
#include <G3D/AABox.h>

#include "Define.h"

#include <stdexcept>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>
#include "string.h"

#define MAX_STACK_SIZE 64

// https://stackoverflow.com/a/4328396

static inline uint32 floatToRawIntBits(float f)
{
    static_assert(sizeof(float) == sizeof(uint32), "Size of uint32 and float must be equal for this to work");
    uint32 ret;
    memcpy(&ret, &f, sizeof(float));
    return ret;
}

static inline float intBitsToFloat(uint32 i)
{
    static_assert(sizeof(float) == sizeof(uint32), "Size of uint32 and float must be equal for this to work");
    float ret;
    memcpy(&ret, &i, sizeof(uint32));
    return ret;
}

struct AABound
{
    G3D::Vector3 lo, hi;
};

/** Bounding Interval Hierarchy Class.
    Building and Ray-Intersection functions based on BIH from
    Sunflow, a Java Raytracer, released under MIT/X11 License
    http://sunflow.sourceforge.net/
    Copyright (c) 2003-2007 Christopher Kulla
*/

class TC_COMMON_API BIH
{
    private:
        void init_empty()
        {
            tree.clear();
            objects.clear();
            // create space for the first node
            tree.push_back(3u << 30u); // dummy leaf
            tree.insert(tree.end(), 2, 0);
        }
    public:
        BIH() { init_empty(); }
        template <class BoundsFunc, class PrimArray>
        void build(PrimArray const& primitives, BoundsFunc& getBounds, uint32 leafSize = 3, bool printStats = false)
        {
            if (primitives.size() == 0)
            {
                init_empty();
                return;
            }

            buildData dat;
            dat.maxPrims = leafSize;
            dat.numPrims = uint32(primitives.size());
            dat.indices = new uint32[dat.numPrims];
            dat.primBound = new G3D::AABox[dat.numPrims];
            getBounds(primitives[0], bounds);
            for (uint32 i=0; i<dat.numPrims; ++i)
            {
                dat.indices[i] = i;
                getBounds(primitives[i], dat.primBound[i]);
                bounds.merge(dat.primBound[i]);
            }
            std::vector<uint32> tempTree;
            BuildStats stats;
            buildHierarchy(tempTree, dat, stats);
            if (printStats)
                stats.printStats();

            objects.resize(dat.numPrims);
            for (uint32 i=0; i<dat.numPrims; ++i)
                objects[i] = dat.indices[i];
            //nObjects = dat.numPrims;
            tree = tempTree;
            delete[] dat.primBound;
            delete[] dat.indices;
        }
        uint32 primCount() const { return uint32(objects.size()); }

        template<typename RayCallback>
        void intersectRay(const G3D::Ray &r, RayCallback& intersectCallback, float &maxDist, bool stopAtFirst = false) const
        {
            float intervalMin = -1.f;
            float intervalMax = -1.f;
            G3D::Vector3 org = r.origin();
            G3D::Vector3 dir = r.direction();
            G3D::Vector3 invDir;
            for (int i=0; i<3; ++i)
            {
                invDir[i] = 1.f / dir[i];
                if (G3D::fuzzyNe(dir[i], 0.0f))
                {
                    float t1 = (bounds.low()[i]  - org[i]) * invDir[i];
                    float t2 = (bounds.high()[i] - org[i]) * invDir[i];
                    if (t1 > t2)
                        std::swap(t1, t2);
                    if (t1 > intervalMin)
                        intervalMin = t1;
                    if (t2 < intervalMax || intervalMax < 0.f)
                        intervalMax = t2;
                    // intervalMax can only become smaller for other axis,
                    //  and intervalMin only larger respectively, so stop early
                    if (intervalMax <= 0 || intervalMin >= maxDist)
                        return;
                }
            }

            if (intervalMin > intervalMax)
                return;
            intervalMin = std::max(intervalMin, 0.f);
            intervalMax = std::min(intervalMax, maxDist);

            uint32 offsetFront[3];
            uint32 offsetBack[3];
            uint32 offsetFront3[3];
            uint32 offsetBack3[3];
            // compute custom offsets from direction sign bit

            for (int i=0; i<3; ++i)
            {
                offsetFront[i] = floatToRawIntBits(dir[i]) >> 31;
                offsetBack[i] = offsetFront[i] ^ 1;
                offsetFront3[i] = offsetFront[i] * 3;
                offsetBack3[i] = offsetBack[i] * 3;

                // avoid always adding 1 during the inner loop
                ++offsetFront[i];
                ++offsetBack[i];
            }

            StackNode stack[MAX_STACK_SIZE];
            int stackPos = 0;
            int node = 0;

            while (true) {
                while (true)
                {
                    uint32 tn = tree[node];
                    uint32 axis = (tn & (3 << 30)) >> 30;
                    bool BVH2 = (tn & (1 << 29)) != 0;
                    int offset = tn & ~(7 << 29);
                    if (!BVH2)
                    {
                        if (axis < 3)
                        {
                            // "normal" interior node
                            float tf = (intBitsToFloat(tree[node + offsetFront[axis]]) - org[axis]) * invDir[axis];
                            float tb = (intBitsToFloat(tree[node + offsetBack[axis]]) - org[axis]) * invDir[axis];
                            // ray passes between clip zones
                            if (tf < intervalMin && tb > intervalMax)
                                break;
                            int back = offset + offsetBack3[axis];
                            node = back;
                            // ray passes through far node only
                            if (tf < intervalMin) {
                                intervalMin = (tb >= intervalMin) ? tb : intervalMin;
                                continue;
                            }
                            node = offset + offsetFront3[axis]; // front
                            // ray passes through near node only
                            if (tb > intervalMax) {
                                intervalMax = (tf <= intervalMax) ? tf : intervalMax;
                                continue;
                            }
                            // ray passes through both nodes
                            // push back node
                            stack[stackPos].node = back;
                            stack[stackPos].tnear = (tb >= intervalMin) ? tb : intervalMin;
                            stack[stackPos].tfar = intervalMax;
                            stackPos++;
                            // update ray interval for front node
                            intervalMax = (tf <= intervalMax) ? tf : intervalMax;
                            continue;
                        }
                        else
                        {
                            // leaf - test some objects
                            int n = tree[node + 1];
                            while (n > 0) {
                                bool hit = intersectCallback(r, objects[offset], maxDist, stopAtFirst);
                                if (stopAtFirst && hit) return;
                                --n;
                                ++offset;
                            }
                            break;
                        }
                    }
                    else
                    {
                        if (axis>2)
                            return; // should not happen
                        float tf = (intBitsToFloat(tree[node + offsetFront[axis]]) - org[axis]) * invDir[axis];
                        float tb = (intBitsToFloat(tree[node + offsetBack[axis]]) - org[axis]) * invDir[axis];
                        node = offset;
                        intervalMin = (tf >= intervalMin) ? tf : intervalMin;
                        intervalMax = (tb <= intervalMax) ? tb : intervalMax;
                        if (intervalMin > intervalMax)
                            break;
                        continue;
                    }
                } // traversal loop
                do
                {
                    // stack is empty?
                    if (stackPos == 0)
                        return;
                    // move back up the stack
                    stackPos--;
                    intervalMin = stack[stackPos].tnear;
                    if (maxDist < intervalMin)
                        continue;
                    node = stack[stackPos].node;
                    intervalMax = stack[stackPos].tfar;
                    break;
                } while (true);
            }
        }

        template<typename IsectCallback>
        void intersectPoint(const G3D::Vector3 &p, IsectCallback& intersectCallback) const
        {
            if (!bounds.contains(p))
                return;

            StackNode stack[MAX_STACK_SIZE];
            int stackPos = 0;
            int node = 0;

            while (true) {
                while (true)
                {
                    uint32 tn = tree[node];
                    uint32 axis = (tn & (3 << 30)) >> 30;
                    bool BVH2 = (tn & (1 << 29)) != 0;
                    int offset = tn & ~(7 << 29);
                    if (!BVH2)
                    {
                        if (axis < 3)
                        {
                            // "normal" interior node
                            float tl = intBitsToFloat(tree[node + 1]);
                            float tr = intBitsToFloat(tree[node + 2]);
                            // point is between clip zones
                            if (tl < p[axis] && tr > p[axis])
                                break;
                            int right = offset + 3;
                            node = right;
                            // point is in right node only
                            if (tl < p[axis]) {
                                continue;
                            }
                            node = offset; // left
                            // point is in left node only
                            if (tr > p[axis]) {
                                continue;
                            }
                            // point is in both nodes
                            // push back right node
                            stack[stackPos].node = right;
                            stackPos++;
                            continue;
                        }
                        else
                        {
                            // leaf - test some objects
                            int n = tree[node + 1];
                            while (n > 0) {
                                intersectCallback(p, objects[offset]); // !!!
                                --n;
                                ++offset;
                            }
                            break;
                        }
                    }
                    else // BVH2 node (empty space cut off left and right)
                    {
                        if (axis>2)
                            return; // should not happen
                        float tl = intBitsToFloat(tree[node + 1]);
                        float tr = intBitsToFloat(tree[node + 2]);
                        node = offset;
                        if (tl > p[axis] || tr < p[axis])
                            break;
                        continue;
                    }
                } // traversal loop

                // stack is empty?
                if (stackPos == 0)
                    return;
                // move back up the stack
                stackPos--;
                node = stack[stackPos].node;
            }
        }

        bool writeToFile(FILE* wf) const;
        bool readFromFile(FILE* rf);

    protected:
        std::vector<uint32> tree;
        std::vector<uint32> objects;
        G3D::AABox bounds;

        struct buildData
        {
            uint32 *indices;
            G3D::AABox *primBound;
            uint32 numPrims;
            int maxPrims;
        };
        struct StackNode
        {
            uint32 node;
            float tnear;
            float tfar;
        };

        class BuildStats
        {
            private:
                int numNodes;
                int numLeaves;
                int sumObjects;
                int minObjects;
                int maxObjects;
                int sumDepth;
                int minDepth;
                int maxDepth;
                int numLeavesN[6];
                int numBVH2;

            public:
            BuildStats():
                numNodes(0), numLeaves(0), sumObjects(0), minObjects(0x0FFFFFFF),
                maxObjects(0xFFFFFFFF), sumDepth(0), minDepth(0x0FFFFFFF),
                maxDepth(0xFFFFFFFF), numBVH2(0)
            {
                for (int i=0; i<6; ++i) numLeavesN[i] = 0;
            }

            void updateInner() { numNodes++; }
            void updateBVH2() { numBVH2++; }
            void updateLeaf(int depth, int n);
            void printStats();
        };

        void buildHierarchy(std::vector<uint32> &tempTree, buildData &dat, BuildStats &stats);

        void createNode(std::vector<uint32> &tempTree, int nodeIndex, uint32 left, uint32 right) const
        {
            // write leaf node
            tempTree[nodeIndex + 0] = (3 << 30) | left;
            tempTree[nodeIndex + 1] = right - left + 1;
        }

        void subdivide(int left, int right, std::vector<uint32> &tempTree, buildData &dat, AABound &gridBox, AABound &nodeBox, int nodeIndex, int depth, BuildStats &stats);
};

#endif // _BIH_H
