/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "ObjectRegistry.h"
#include "TypeList.h"

/** FactoryHolder holds a factory object of a specific type
 */
template<class T, class O, class Key = std::string>
class FactoryHolder
{
    public:
        typedef ObjectRegistry<FactoryHolder<T, O, Key>, Key> FactoryHolderRegistry;

        explicit FactoryHolder(Key const& k) : _key(k) { }
        virtual ~FactoryHolder() { }

        void RegisterSelf() { FactoryHolderRegistry::instance()->InsertItem(this, _key); }

        /// Abstract Factory create method
        virtual T* Create(O* object = nullptr) const = 0;
    private:
        Key const _key;
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
        virtual int32 Permit(T const*) const = 0;
};
#endif
