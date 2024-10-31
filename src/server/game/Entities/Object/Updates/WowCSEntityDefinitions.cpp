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

#include "WowCSEntityDefinitions.h"
#include "Errors.h"
#include <algorithm>

namespace WowCS
{
void EntityFragmentsHolder::Add(EntityFragment fragment, bool update)
{
    ASSERT(Count < Ids.size());

    auto insertSorted = [](auto& arr, uint8& count, EntityFragment f)
    {
        auto where = std::ranges::lower_bound(arr.begin(), arr.begin() + count, f);
        if (*where == f)
            return std::pair(where, false);
        std::rotate(where, arr.begin() + count, arr.begin() + count + 1);
        ++count;
        *where = f;
        return std::pair(where, true);
    };

    if (!insertSorted(Ids, Count, fragment).second)
        return;

    if (IsUpdateableFragment(fragment))
    {
        ASSERT(UpdateableCount < UpdateableIds.size());

        auto insertedItr = insertSorted(UpdateableIds, UpdateableCount, fragment).first;
        std::ptrdiff_t index = std::distance(UpdateableIds.begin(), insertedItr);
        uint8 maskLowPart = ContentsChangedMask & ((1 << index) - 1);
        uint8 maskHighPart = (ContentsChangedMask & ~((1 << index) - 1)) << (1 + IsIndirectFragment(fragment));
        ContentsChangedMask = maskLowPart | maskHighPart;
        for (uint8 i = 0, maskIndex = 0; i < UpdateableCount; ++i)
        {
            UpdateableMasks[i] = 1 << maskIndex++;
            if (IsIndirectFragment(UpdateableIds[i]))
                UpdateableMasks[i] |= 1 << maskIndex++;
        }
    }

    if (update)
        IdsChanged = true;
}

void EntityFragmentsHolder::Remove(EntityFragment fragment)
{
    auto removeSorted = [](auto& arr, uint8& count, EntityFragment f)
    {
        auto where = std::ranges::find(arr.begin(), arr.begin() + count, f);
        if (where != arr.end())
        {
            *where = EntityFragment::End;
            std::rotate(where, where + 1, arr.begin() + count);
            --count;
            return std::pair(where, true);
        }
        return std::pair(where, false);
    };

    if (!removeSorted(Ids, Count, fragment).second)
        return;

    if (IsUpdateableFragment(fragment))
    {
        auto [removedItr, removed] = removeSorted(UpdateableIds, UpdateableCount, fragment);
        if (removed)
        {
            std::ptrdiff_t index = std::distance(UpdateableIds.begin(), removedItr);
            uint8 maskLowPart = ContentsChangedMask & ((1 << index) - 1);
            uint8 maskHighPart = (ContentsChangedMask & ~((1 << index) - 1)) >> (1 + IsIndirectFragment(fragment));
            ContentsChangedMask = maskLowPart | maskHighPart;
            for (uint8 i = 0, maskIndex = 0; i < UpdateableCount; ++i)
            {
                UpdateableMasks[i] = 1 << maskIndex++;
                if (IsIndirectFragment(UpdateableIds[i]))
                    UpdateableMasks[i] |= 1 << maskIndex++;
            }
        }
    }

    IdsChanged = true;
}
}
