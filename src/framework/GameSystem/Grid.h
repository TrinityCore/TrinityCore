/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
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

#include "Platform/Define.h"
#include "Policies/ThreadingModel.h"
#include "TypeContainer.h"
#include "TypeContainerVisitor.h"

// forward declaration
template<class A, class T, class O> class GridLoader;

template
<
class ACTIVE_OBJECT,
class WORLD_OBJECT_TYPES,
class GRID_OBJECT_TYPES,
class ThreadModel = Trinity::SingleThreaded<ACTIVE_OBJECT>
>
class TRINITY_DLL_DECL Grid
{
    // allows the GridLoader to access its internals
    template<class A, class T, class O> friend class GridLoader;
    public:

        /** destructor to clean up its resources. This includes unloading the
        grid if it has not been unload.
        */
        ~Grid() {}

        /** an object of interested enters the grid
         */
        template<class SPECIFIC_OBJECT> void AddWorldObject(SPECIFIC_OBJECT *obj, OBJECT_HANDLE hdl)
        {
            if(!i_objects.template insert<SPECIFIC_OBJECT>(hdl, obj))
                assert(false);
        }

        /** an object of interested exits the grid
         */
        template<class SPECIFIC_OBJECT> void RemoveWorldObject(SPECIFIC_OBJECT *obj, OBJECT_HANDLE hdl)
        {
            if(!i_objects.template remove<SPECIFIC_OBJECT>(obj, hdl))
                assert(false);
        }

        /** Accessors: Returns a specific type of object in the WORDL_OBJECT_TYPES
         */
        template<class SPECIFIC_OBJECT> const SPECIFIC_OBJECT* GetWorldObject(OBJECT_HANDLE hdl, SPECIFIC_OBJECT* fake) const { return i_objects.template find<SPECIFIC_OBJECT>(hdl); }
        template<class SPECIFIC_OBJECT>       SPECIFIC_OBJECT* GetWorldObject(OBJECT_HANDLE hdl, SPECIFIC_OBJECT *fake)       { return i_objects.template find<SPECIFIC_OBJECT>(hdl, fake); }

        /** Refreshes/update the grid. This required for remote grids.
         */
        void RefreshGrid(void) { /* TBI */}

        /** Locks a grid.  Any object enters must wait until the grid is unlock.
         */
        void LockGrid(void) { /* TBI */ }

        /** Unlocks the grid.
         */
        void UnlockGrid(void) { /* TBI */ }

        /** Grid visitor for grid objects
         */
        template<class T> void Visit(TypeContainerVisitor<T, TypeMapContainer<GRID_OBJECT_TYPES> > &visitor)
        {
            visitor.Visit(i_container);
        }

        /** Grid visitor for world objects
         */
        template<class T> void Visit(TypeContainerVisitor<T, TypeMapContainer<WORLD_OBJECT_TYPES> > &visitor)
        {
            visitor.Visit(i_objects);
        }

        /** Returns the number of object within the grid.
         */
        unsigned int ActiveObjectsInGrid(void) const { return /*m_activeGridObjects.size()+*/i_objects.template Count<ACTIVE_OBJECT>(); }

        /** Accessors: Returns a specific type of object in the GRID_OBJECT_TYPES
         */
        template<class SPECIFIC_OBJECT> const SPECIFIC_OBJECT* GetGridObject(OBJECT_HANDLE hdl, SPECIFIC_OBJECT *fake) const { return i_container.template find<SPECIFIC_OBJECT>(hdl, fake); }
        template<class SPECIFIC_OBJECT>       SPECIFIC_OBJECT* GetGridObject(OBJECT_HANDLE hdl, SPECIFIC_OBJECT *fake)       { return i_container.template find<SPECIFIC_OBJECT>(hdl, fake); }

        /** Inserts a container type object into the grid.
         */
        template<class SPECIFIC_OBJECT> void AddGridObject(SPECIFIC_OBJECT *obj, OBJECT_HANDLE hdl)
        {
            if(!i_container.template insert<SPECIFIC_OBJECT>(hdl, obj))
                assert(false);
        }

        /** Removes a containter type object from the grid
         */
        template<class SPECIFIC_OBJECT> void RemoveGridObject(SPECIFIC_OBJECT *obj, OBJECT_HANDLE hdl)
        {
            if(!i_container.template remove<SPECIFIC_OBJECT>(obj, hdl))
                assert(false);
        }

        /*bool NoWorldObjectInGrid() const
        {
            return i_objects.GetElements().isEmpty();
        }

        bool NoGridObjectInGrid() const
        {
            return i_container.GetElements().isEmpty();
        }*/
    private:

        typedef typename ThreadModel::Lock Guard;
        typedef typename ThreadModel::VolatileType VolatileType;

        TypeMapContainer<GRID_OBJECT_TYPES> i_container;
        TypeMapContainer<WORLD_OBJECT_TYPES> i_objects;
        //typedef std::set<void*> ActiveGridObjects;
        //ActiveGridObjects m_activeGridObjects;
};
#endif

