/*
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
 *
 * Thanks to the original authors: MaNGOS <http://www.mangosproject.org/>
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

#ifndef TRINITY_WAYPOINTMANAGER_H
#define TRINITY_WAYPOINTMANAGER_H

#include <vector>
#include <string>
#include "Utilities/HashMap.h"

struct WaypointBehavior
{
    uint32 emote;
    uint32 spell;
    std::string text[5];
    uint32 model1;
    uint32 model2;

    bool isEmpty();
    WaypointBehavior() {}
    WaypointBehavior(const WaypointBehavior &b);
};

struct WaypointNode
{
    float x;
    float y;
    float z;
    float orientation;
    uint32 delay;
    WaypointBehavior * behavior;
    WaypointNode() {}
    WaypointNode(float _x, float _y, float _z, float _o, uint32 _delay, WaypointBehavior * _behavior)
      : x(_x), y(_y), z(_z), orientation(_o), delay(_delay), behavior(_behavior) {}
};

typedef std::vector<WaypointNode> WaypointPath;

class WaypointManager
{
    public:
        WaypointManager() {}
        ~WaypointManager() { Unload(); }

        void Load();
        void Unload();

        void Cleanup();

        WaypointPath *GetPath(uint32 id)
        {
            WaypointPathMap::iterator itr = m_pathMap.find(id);
            return itr != m_pathMap.end() ? &itr->second : NULL;
        }

        void AddLastNode(uint32 id, float x, float y, float z, float o, uint32 delay, uint32 wpGuid);
        void AddAfterNode(uint32 id, uint32 point, float x, float y, float z, float o, uint32 delay, uint32 wpGuid);
        uint32 GetLastPoint(uint32 id, uint32 default_notfound);
        void DeleteNode(uint32 id, uint32 point);
        void DeletePath(uint32 id);
        void SetNodePosition(uint32 id, uint32 point, float x, float y, float z);
        void SetNodeText(uint32 id, uint32 point, const char *text_field, const char *text);

    private:
        void _addNode(uint32 id, uint32 point, float x, float y, float z, float o, uint32 delay, uint32 wpGuid);
        void _clearPath(WaypointPath &path);

        typedef HM_NAMESPACE::hash_map<uint32, WaypointPath> WaypointPathMap;
        WaypointPathMap m_pathMap;
};

#define WaypointMgr Trinity::Singleton<WaypointManager>::Instance()

#endif
