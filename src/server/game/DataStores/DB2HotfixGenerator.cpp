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

#include "DB2HotfixGenerator.h"
#include "DB2Stores.h"
#include "Log.h"

template<class T>
void DB2HotfixGenerator<T>::ApplyHotfix(uint32 const* begin, uint32 const* end, void(*fixer)(T*), bool notifyClient)
{
    while (begin != end)
    {
        uint32 id = *begin++;
        T const* entry = _storage.LookupEntry(id);
        if (!entry)
        {
            TC_LOG_ERROR("db2.hotfix", "Hotfix specified for %s row which does not exist", _storage.GetFileName().c_str(), id);
            continue;
        }

        fixer(const_cast<T*>(entry));
        ++_count;

        if (notifyClient)
            sDB2Manager.InsertNewHotfix(_storage.GetTableHash(), id);
    }
}
