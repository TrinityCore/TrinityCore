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

#ifndef TRANSPORTS_H
#define TRANSPORTS_H

#include "GameObject.h"

#include <map>
#include <set>
#include <string>

class TransportPath
{
    public:
        struct PathNode
        {
            uint32 mapid;
            float x,y,z;
            uint32 actionFlag;
            uint32 delay;
        };

        void SetLength(const unsigned int sz)
        {
            i_nodes.resize( sz );
        }

        unsigned int Size(void) const { return i_nodes.size(); }
        bool Empty(void) const { return i_nodes.empty(); }
        void Resize(unsigned int sz) { i_nodes.resize(sz); }
        void Clear(void) { i_nodes.clear(); }
        PathNode* GetNodes(void) { return static_cast<PathNode *>(&i_nodes[0]); }

        PathNode& operator[](const unsigned int idx) { return i_nodes[idx]; }
        const PathNode& operator()(const unsigned int idx) const { return i_nodes[idx]; }

    protected:
        std::vector<PathNode> i_nodes;
};

class Transport : protected GameObject
{
    public:
        explicit Transport();

        // prevent using Transports as normal GO, but allow call some inherited functions
        using GameObject::IsTransport;
        using GameObject::GetEntry;
        using GameObject::GetGUID;
        using GameObject::GetGUIDLow;
        using GameObject::GetMapId;
        using GameObject::GetPositionX;
        using GameObject::GetPositionY;
        using GameObject::GetPositionZ;
        using GameObject::BuildCreateUpdateBlockForPlayer;
        using GameObject::BuildOutOfRangeUpdateBlock;
        using GameObject::GetPackGUID;

        bool Create(uint32 guidlow, uint32 mapid, float x, float y, float z, float ang, uint32 animprogress, uint32 dynflags);
        bool GenerateWaypoints(uint32 pathid, std::set<uint32> &mapids);
        void Update(uint32 p_time);
        bool AddPassenger(Player* passenger);
        bool RemovePassenger(Player* passenger);
        void CheckForEvent(uint32 entry, uint32 wp_id);

        typedef std::set<Player*> PlayerSet;
        PlayerSet const& GetPassengers() const { return m_passengers; }

    private:
        struct WayPoint
        {
            WayPoint() : mapid(0), x(0), y(0), z(0), teleport(false), id(0) {}
            WayPoint(uint32 _mapid, float _x, float _y, float _z, bool _teleport, uint32 _id) :
            mapid(_mapid), x(_x), y(_y), z(_z), teleport(_teleport), id(_id) {}
            uint32 mapid;
            float x;
            float y;
            float z;
            bool teleport;
            uint32 id;
        };

        typedef std::map<uint32, WayPoint> WayPointMap;

        WayPointMap::const_iterator m_curr;
        WayPointMap::const_iterator m_next;
        uint32 m_pathTime;
        uint32 m_timer;

        PlayerSet m_passengers;

    public:
        WayPointMap m_WayPoints;
        uint32 m_nextNodeTime;
        uint32 m_period;

    private:
        void TeleportTransport(uint32 newMapid, float x, float y, float z);
        void UpdateForMap(Map const* map);
        WayPointMap::const_iterator GetNextWayPoint();
};
#endif

