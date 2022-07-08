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

#ifndef TRINITY_OBJECTGRIDLOADER_H
#define TRINITY_OBJECTGRIDLOADER_H

#include "Define.h"
#include "GridDefines.h"
#include "Cell.h"

class MapObject;
class ObjectGuid;
class ObjectWorldLoader;

class TC_GAME_API ObjectGridLoaderBase
{
    public:
        ObjectGridLoaderBase(NGridType& grid, Map* map, Cell const& cell)
            : i_cell(cell), i_grid(grid), i_map(map), i_gameObjects(0), i_creatures(0), i_corpses(0), i_areaTriggers(0)
            { }

        static void SetObjectCell(MapObject* obj, CellCoord const& cellCoord);

        uint32 GetLoadedCreatures() const { return i_creatures; }
        uint32 GetLoadedGameObjects() const { return i_gameObjects; }
        uint32 GetLoadedCorpses() const { return i_corpses; }
        uint32 GetLoadedAreaTriggers() const { return i_areaTriggers; }

    protected:
        Cell i_cell;
        NGridType &i_grid;
        Map* i_map;
        uint32 i_gameObjects;
        uint32 i_creatures;
        uint32 i_corpses;
        uint32 i_areaTriggers;
};

class TC_GAME_API ObjectGridLoader : public ObjectGridLoaderBase
{
    friend class ObjectWorldLoader;

    public:
        ObjectGridLoader(NGridType& grid, Map* map, Cell const& cell)
            : ObjectGridLoaderBase(grid, map, cell)
            { }

        void Visit(GameObjectMapType &m);
        void Visit(CreatureMapType &m);
        void Visit(AreaTriggerMapType &m);
        void Visit(CorpseMapType &) const { }
        void Visit(DynamicObjectMapType&) const { }
        void Visit(SceneObjectMapType&) const { }
        void Visit(ConversationMapType&) const { }

        void LoadN();
};

class TC_GAME_API PersonalPhaseGridLoader : public ObjectGridLoaderBase
{
    public:
        PersonalPhaseGridLoader(NGridType& grid, Map* map, Cell const& cell, ObjectGuid const& phaseOwner)
            : ObjectGridLoaderBase(grid, map, cell), _phaseId(0), _phaseOwner(phaseOwner)
            { }

        void Visit(GameObjectMapType &m);
        void Visit(CreatureMapType &m);
        void Visit(AreaTriggerMapType&) const { }
        void Visit(CorpseMapType&) const { }
        void Visit(DynamicObjectMapType&) const { }
        void Visit(SceneObjectMapType&) const { }
        void Visit(ConversationMapType&) const { }

        void Load(uint32 phaseId);

    private:
        uint32 _phaseId;
        ObjectGuid const& _phaseOwner;
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
