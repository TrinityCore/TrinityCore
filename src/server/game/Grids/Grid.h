/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#ifndef TRINITY_GRID_H
#define TRINITY_GRID_H

/*
  @class Grid
  Grid is a logical segment of the game world represented inside TrinIty.
  Grid is bind at compile time to a particular type of object which
  we call it the object of interested.  There are many types of loader,
  specially, dynamic loader, static loader, or on-demand loader.  There's
  a subtle difference between dynamic loader and on-demand loader but
  this is implementation specific to the loader class.  From the
  Grid's perspective, the loader meets its API requirement is suffice.
*/

#include "Define.h"
#include "TypeContainer.h"
#include "TypeContainerVisitor.h"

// forward declaration
template<class A, class T, class O> class GridLoader;

template
<
class ACTIVE_OBJECT,
class WORLD_OBJECT_TYPES,
class GRID_OBJECT_TYPES
>
class Grid
{
    // allows the GridLoader to access its internals
    template<class A, class T, class O> friend class GridLoader;
    public:

        /** destructor to clean up its resources. This includes unloading the
        grid if it has not been unload.
        */
        ~Grid() { }

        /** an object of interested enters the grid
         */
        template<class SPECIFIC_OBJECT> void AddWorldObject(SPECIFIC_OBJECT *obj)
        {
            i_objects.template insert<SPECIFIC_OBJECT>(obj);
            ASSERT(obj->IsInGrid());
        }

        /** an object of interested exits the grid
         */
        //Actually an unlink is enough, no need to go through the container
        //template<class SPECIFIC_OBJECT> void RemoveWorldObject(SPECIFIC_OBJECT *obj)
        //{
        //    ASSERT(obj->GetGridRef().isValid());
        //    i_objects.template remove<SPECIFIC_OBJECT>(obj);
        //    ASSERT(!obj->GetGridRef().isValid());
        //}

        /** Refreshes/update the grid. This required for remote grids.
         */
        //void RefreshGrid(void) { /* TBI */}

        /** Locks a grid.  Any object enters must wait until the grid is unlock.
         */
        //void LockGrid(void) { /* TBI */ }

        /** Unlocks the grid.
         */
        //void UnlockGrid(void) { /* TBI */ }

        // Visit grid objects
        template<class T>
        void Visit(TypeContainerVisitor<T, TypeMapContainer<GRID_OBJECT_TYPES> > &visitor)
        {
            visitor.Visit(i_container);
        }

        // Visit world objects
        template<class T>
        void Visit(TypeContainerVisitor<T, TypeMapContainer<WORLD_OBJECT_TYPES> > &visitor)
        {
            visitor.Visit(i_objects);
        }

        /** Returns the number of object within the grid.
         */
        //unsigned int ActiveObjectsInGrid(void) const { return i_objects.template Count<ACTIVE_OBJECT>(); }
        template<class T>
        uint32 GetWorldObjectCountInGrid() const
        {
            return i_objects.template Count<T>();
        }

        /** Inserts a container type object into the grid.
         */
        template<class SPECIFIC_OBJECT> void AddGridObject(SPECIFIC_OBJECT *obj)
        {
            i_container.template insert<SPECIFIC_OBJECT>(obj);
            ASSERT(obj->IsInGrid());
        }

        /** Removes a containter type object from the grid
         */
        //template<class SPECIFIC_OBJECT> void RemoveGridObject(SPECIFIC_OBJECT *obj)
        //{
        //    ASSERT(obj->GetGridRef().isValid());
        //    i_container.template remove<SPECIFIC_OBJECT>(obj);
        //    ASSERT(!obj->GetGridRef().isValid());
        //}

        /*bool NoWorldObjectInGrid() const
        {
            return i_objects.GetElements().isEmpty();
        }

        bool NoGridObjectInGrid() const
        {
            return i_container.GetElements().isEmpty();
        }*/
    private:

        TypeMapContainer<GRID_OBJECT_TYPES> i_container;
        TypeMapContainer<WORLD_OBJECT_TYPES> i_objects;
        //typedef std::set<void*> ActiveGridObjects;
        //ActiveGridObjects m_activeGridObjects;
};
#endif

