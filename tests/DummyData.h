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

#ifndef TRINITY_DUMMYDATA_H
#define TRINITY_DUMMYDATA_H

#include "Common.h"
#include "Define.h"
#include "DBCStore.h"

#include <list>
#include <string_view>

struct ItemTemplate;

class SpellInfo;

class UnitTestDataLoader
{
    public:
        template <typename T, uint32 T::*ID>
        class DBC
        {
            class LoaderGuard
            {
                public:
                    LoaderGuard(DBC& d) : _d(d) {}
                    ~LoaderGuard() { _d.Dump(); }

                    T& Add() { return _d._storage.emplace_back(); }
                private:
                    DBC& _d;
            };

            public:
                DBC(DBCStorage<T>& store) : _store(store) {}
                LoaderGuard Loader() { return {*this}; }
                void Dump()
                {
                    delete[] _store._indexTable.AsT;
                    for (T const& entry : _storage)
                        if (entry.*ID >= _store._indexTableSize)
                            _store._indexTableSize = entry.*ID + 1;
                    _store._indexTable.AsT = new T*[_store._indexTableSize];
                    for (size_t i = 0; i < _store._indexTableSize; ++i)
                        _store._indexTable.AsT[i] = nullptr;
                    for (T& entry : _storage)
                        _store._indexTable.AsT[entry.*ID] = &entry;
                }

                bool Empty() const
                {
                    return !_store._indexTable.AsT;
                }

            private:
                std::list<T> _storage;
                DBCStorage<T>& _store;
        };

        static void LoadAchievementTemplates();
        static void LoadItemTemplates();
        static void LoadSpellInfo();

    private:
        static ItemTemplate& GetItemTemplate(uint32 id, std::string_view name);
        static void SetItemLocale(uint32 id, LocaleConstant locale, std::string_view name);
};

#endif
