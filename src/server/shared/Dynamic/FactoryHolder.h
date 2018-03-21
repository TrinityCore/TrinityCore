/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef TRINITY_FACTORY_HOLDER
#define TRINITY_FACTORY_HOLDER

#include "Define.h"
#include "Dynamic/TypeList.h"
#include "ObjectRegistry.h"

/** FactoryHolder holds a factory object of a specific type
 */
template<class T, class Key = std::string>
class FactoryHolder
{
    public:
        typedef ObjectRegistry<FactoryHolder<T, Key >, Key > FactoryHolderRegistry;

        FactoryHolder(Key k) : i_key(k) { }
        virtual ~FactoryHolder() { }
        inline Key key() const { return i_key; }

        void RegisterSelf(void) { FactoryHolderRegistry::instance()->InsertItem(this, i_key); }
        void DeregisterSelf(void) { FactoryHolderRegistry::instance()->RemoveItem(this, false); }

        /// Abstract Factory create method
        virtual T* Create(void *data = NULL) const = 0;
    private:
        Key i_key;
};

/** Permissible is a classic way of letting the object decide
 * whether how good they handle things.  This is not retricted
 * to factory selectors.
 */
template<class T>
class Permissible
{
    public:
        virtual ~Permissible() { }
        virtual int Permit(const T *) const = 0;
};
#endif
