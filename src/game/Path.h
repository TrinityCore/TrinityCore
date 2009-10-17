/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef TRINITYCORE_PATH_H
#define TRINITYCORE_PATH_H

#include "Common.h"
#include <vector>

class Path
{
    public:
        struct PathNode
        {
            float x,y,z;
        };

        void SetLength(const unsigned int sz)
        {
            i_nodes.resize( sz );
        }

        unsigned int Size() const { return i_nodes.size(); }
        bool Empty() const { return i_nodes.empty(); }
        void Resize(unsigned int sz) { i_nodes.resize(sz); }
        void Clear(void) { i_nodes.clear(); }
        PathNode const* GetNodes(uint32 start = 0) const { return &i_nodes[start]; }
        float GetTotalLength() const { return GetTotalLength(0,Size()); }
        float GetTotalLength(uint32 start, uint32 end) const
        {
            float len = 0, xd, yd, zd;
            for (unsigned int idx=start+1; idx < end; ++idx)
            {
                xd = i_nodes[ idx ].x - i_nodes[ idx-1 ].x;
                yd = i_nodes[ idx ].y - i_nodes[ idx-1 ].y;
                zd = i_nodes[ idx ].z - i_nodes[ idx-1 ].z;
                len += sqrtf( xd*xd + yd*yd + zd*zd );
            }
            return len;
        }

        float GetPassedLength(uint32 curnode, float x, float y, float z)
        {
            float len = 0, xd, yd, zd;
            for (unsigned int idx=1; idx < curnode; ++idx)
            {
                xd = i_nodes[ idx ].x - i_nodes[ idx-1 ].x;
                yd = i_nodes[ idx ].y - i_nodes[ idx-1 ].y;
                zd = i_nodes[ idx ].z - i_nodes[ idx-1 ].z;
                len += sqrtf( xd*xd + yd*yd + zd*zd );
            }

            if(curnode > 0)
            {
                xd = x - i_nodes[curnode-1].x;
                yd = y - i_nodes[curnode-1].y;
                zd = z - i_nodes[curnode-1].z;
                len += sqrtf( xd*xd + yd*yd + zd*zd );
            }

            return len;
        }

        PathNode& operator[](const unsigned int idx) { return i_nodes[idx]; }
        const PathNode& operator()(const unsigned int idx) const { return i_nodes[idx]; }

    protected:
        std::vector<PathNode> i_nodes;
};
#endif

