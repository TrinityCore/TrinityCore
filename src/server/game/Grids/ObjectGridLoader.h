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

#ifndef TRINITY_OBJECT_GRID_LOADER_H
#define TRINITY_OBJECT_GRID_LOADER_H

#include "Define.h"
#include "GridDefines.h"
#include "ObjectGuid.h"

class Map;
class ObjectGuid;

class TC_GAME_API ObjectGridLoaderBase
{
    public:
        ObjectGridLoaderBase(NGridType& grid, Map* map)
            : i_grid(grid), i_map(map), i_gameObjects(0), i_creatures(0), i_corpses(0), i_areaTriggers(0)
            { }

        uint32 GetLoadedCreatures() const { return i_creatures; }
        uint32 GetLoadedGameObjects() const { return i_gameObjects; }
        uint32 GetLoadedCorpses() const { return i_corpses; }
        uint32 GetLoadedAreaTriggers() const { return i_areaTriggers; }

        template <typename T>
        static void AddToMap(T* obj, Map* map, uint32& objectCount);

    protected:
        NGridType &i_grid;
        Map* i_map;
        uint32 i_gameObjects;
        uint32 i_creatures;
        uint32 i_corpses;
        uint32 i_areaTriggers;
};

class TC_GAME_API ObjectGridLoader : public ObjectGridLoaderBase
{
    public:
        ObjectGridLoader(NGridType& grid, Map* map)
            : ObjectGridLoaderBase(grid, map)
            { }

        void LoadN();
};

class TC_GAME_API PersonalPhaseGridLoader : public ObjectGridLoaderBase
{
    public:
        PersonalPhaseGridLoader(NGridType& grid, Map* map, ObjectGuid const& phaseOwner)
            : ObjectGridLoaderBase(grid, map), _phaseOwner(phaseOwner)
            { }

        void Load(uint32 phaseId);

    private:
        ObjectGuid _phaseOwner;
};

//Stop the creatures before unloading the NGrid
class TC_GAME_API ObjectGridStoper
{
    public:
        void Visit(CreatureMapType &m);
        template<class T> void Visit(GridRefManager<T> &) { }
};

//Move the foreign creatures back to respawn positions before unloading the NGrid
class TC_GAME_API ObjectGridEvacuator
{
    public:
        void Visit(CreatureMapType &m);
        void Visit(GameObjectMapType &m);
        template<class T> void Visit(GridRefManager<T> &) { }
};

//Clean up and remove from world
class ObjectGridCleaner
{
    public:
        template<class T> void Visit(GridRefManager<T> &);
};

//Delete objects before deleting NGrid
class ObjectGridUnloader
{
    public:
        void Visit(CorpseMapType& /*m*/) { }    // corpses are deleted with Map
        template<class T> void Visit(GridRefManager<T> &m);
};
#endif
