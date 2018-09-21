/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef DB2HotfixGenerator_h__
#define DB2HotfixGenerator_h__

#include "DB2Store.h"
#include <initializer_list>

class TC_GAME_API DB2HotfixGeneratorBase
{
public:
    static void LogMissingRecord(std::string const& storageName, uint32 recordId);
    static void AddClientHotfix(uint32 tableHash, uint32 recordId);
};

template<class T>
class DB2HotfixGenerator : private DB2HotfixGeneratorBase
{
public:
    explicit DB2HotfixGenerator(DB2Storage<T>& storage) : _storage(storage), _count(0) { }

    void ApplyHotfix(uint32 id, void(*fixer)(T*), bool notifyClient = false) { ApplyHotfix({ id }, fixer, notifyClient); }
    void ApplyHotfix(std::initializer_list<uint32> ids, void(*fixer)(T*), bool notifyClient = false) { ApplyHotfix(ids.begin(), ids.end(), fixer, notifyClient); }

    template<class I, class = typename std::enable_if<!std::is_void<decltype(*std::begin(std::declval<I>()))>::value>::type>
    void ApplyHotfix(I const& ids, void(*fixer)(T*), bool notifyClient = false) { ApplyHotfix(std::begin(ids), std::end(ids), fixer, notifyClient); }

    uint32 GetAppliedHotfixesCount() const { return _count; }

private:
    void ApplyHotfix(uint32 const* begin, uint32 const* end, void(*fixer)(T*), bool notifyClient)
    {
        while (begin != end)
        {
            uint32 id = *begin++;
            T const* entry = _storage.LookupEntry(id);
            if (!entry)
            {
                DB2HotfixGeneratorBase::LogMissingRecord(_storage.GetFileName().c_str(), id);
                continue;
            }

            fixer(const_cast<T*>(entry));
            ++_count;

            if (notifyClient)
                DB2HotfixGeneratorBase::AddClientHotfix(_storage.GetTableHash(), id);
        }
    }


    DB2Storage<T>& _storage;
    uint32 _count;
};

#endif // DB2HotfixGenerator_h__
