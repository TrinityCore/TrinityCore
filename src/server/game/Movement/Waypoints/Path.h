/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef TRINITYCORE_PATH_H
#define TRINITYCORE_PATH_H

#include "Common.h"
#include <vector>

struct SimplePathNode
{
    float x, y, z;
};
template<typename PathElem, typename PathNode = PathElem>

class Path
{
    public:
        size_t size() const { return i_nodes.size(); }
        bool empty() const { return i_nodes.empty(); }
        void resize(unsigned int sz) { i_nodes.resize(sz); }
        void clear() { i_nodes.clear(); }
        void erase(uint32 idx) { i_nodes.erase(i_nodes.begin()+idx); }

        float GetTotalLength(uint32 start, uint32 end) const
        {
            float len = 0.0f;
            for (uint32 idx=start+1; idx < end; ++idx)
            {
                PathNode const& node = i_nodes[idx];
                PathNode const& prev = i_nodes[idx-1];
                float xd = node.x - prev.x;
                float yd = node.y - prev.y;
                float zd = node.z - prev.z;
                len += sqrtf(xd*xd + yd*yd + zd*zd);
            }
            return len;
        }

        float GetTotalLength() const { return GetTotalLength(0, size()); }

        float GetPassedLength(uint32 curnode, float x, float y, float z) const
        {
            float len = GetTotalLength(0, curnode);

            if (curnode > 0)
            {
                PathNode const& node = i_nodes[curnode-1];
                float xd = x - node.x;
                float yd = y - node.y;
                float zd = z - node.z;
                len += sqrtf(xd*xd + yd*yd + zd*zd);
            }

            return len;
        }

        PathNode& operator[](size_t idx) { return i_nodes[idx]; }
        PathNode const& operator[](size_t idx) const { return i_nodes[idx]; }

        void set(size_t idx, PathElem elem) { i_nodes[idx] = elem; }

    protected:
        std::vector<PathElem> i_nodes;
};

typedef Path<SimplePathNode> SimplePath;

#endif

