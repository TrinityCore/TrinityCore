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

#ifndef TRINITYCORE_NAMED_POINT_MGR_H
#define TRINITYCORE_NAMED_POINT_MGR_H

#include "Common.h"
#include <string>
#include <unordered_map>

class WorldObject;

struct NamedPoint
{
    uint32 Id;
    float PositionX;
    float PositionY;
    float PositionZ;
    float Orientation;
    std::string StringId;
    std::string Name;
};

typedef std::unordered_map<uint32, NamedPoint> NamedPointMap;

class TC_GAME_API NamedPointMgr
{ 
    public:
        static NamedPointMgr* Instance();

        void LoadNamedPoints();

        const NamedPoint* GetNamedPoint(uint32 id) const;
        const NamedPoint* FindNearestNamedPoint(float x, float y, float z, const std::string& stringId, float maxRange = 100.0f) const;
        const NamedPoint* FindNearestNamedPoint(WorldObject const* searcher, const std::string& stringId, float maxRange = 100.0f) const;

    private:
        NamedPointMap _namedPoints;
};

#define sNamedPointMgr NamedPointMgr::Instance()

#endif
