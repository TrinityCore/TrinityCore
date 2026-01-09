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
void EntityFragmentsHolder::Add(EntityFragment fragment, bool update,
    EntityFragmentSerializeFn serializeCreate, EntityFragmentSerializeFn serializeUpdate, EntityFragmentIsChangedFn isChanged)
{
    ASSERT(Count < Ids.size());

    auto insertSorted = []<size_t N>(std::array<EntityFragment, N>& arr, uint8& count, EntityFragment f)
    {
        auto end = arr.begin() + count;
        auto where = std::ranges::lower_bound(arr.begin(), end, f);
        if (*where == f)
            return std::pair(where, false);

        std::ranges::move_backward(where, end, end + 1);
        ++count;
        *where = f;
        return std::pair(where, true);
    };

    if (!insertSorted(Ids, Count, fragment).second)
        return;

    if (IsUpdateableFragment(fragment))
    {
        ASSERT(UpdateableCount < Updateable.Ids.size());
        ASSERT(serializeCreate && serializeUpdate && isChanged);

        auto insertedItr = insertSorted(Updateable.Ids, UpdateableCount, fragment).first;
        std::ptrdiff_t index = std::ranges::distance(Updateable.Ids.begin(), insertedItr);
        uint8 maskLowPart = ContentsChangedMask & ((1 << index) - 1);
        uint8 maskHighPart = (ContentsChangedMask & ~((1 << index) - 1)) << (1 + IsIndirectFragment(fragment));
        ContentsChangedMask = maskLowPart | maskHighPart;
        for (uint8 i = 0, maskIndex = 0; i < UpdateableCount; ++i)
        {
            Updateable.Masks[i] = 1 << maskIndex++;
            if (IsIndirectFragment(Updateable.Ids[i]))
            {
                ContentsChangedMask |= Updateable.Masks[i]; // set the first bit to true to activate fragment
                ++maskIndex;
                Updateable.Masks[i] <<= 1;
            }
        }

        auto insertAtIndex = []<typename T, size_t N>(std::array<T, N>& arr, uint8 size, std::ptrdiff_t i, T value)
        {
            std::ranges::move_backward(arr.begin() + i, arr.begin() + size - 1, arr.begin() + size);
            arr[i] = value;
        };

        insertAtIndex(Updateable.SerializeCreate, UpdateableCount, index, serializeCreate);
        insertAtIndex(Updateable.SerializeUpdate, UpdateableCount, index, serializeUpdate);
        insertAtIndex(Updateable.IsChanged, UpdateableCount, index, isChanged);
    }

    if (update)
        IdsChanged = true;
}

void EntityFragmentsHolder::Remove(EntityFragment fragment)
{
    auto removeSorted = []<size_t N>(std::array<EntityFragment, N>& arr, uint8& count, EntityFragment f)
    {
        auto end = arr.begin() + count;
        auto where = std::ranges::find(arr.begin(), end, f);
        if (where != end)
        {
            *std::ranges::move(where + 1, end, where).out = EntityFragment::End;
            --count;
            return std::pair(where, true);
        }
        return std::pair(where, false);
    };

    if (!removeSorted(Ids, Count, fragment).second)
        return;

    if (IsUpdateableFragment(fragment))
    {
        auto [removedItr, removed] = removeSorted(Updateable.Ids, UpdateableCount, fragment);
        if (removed)
        {
            std::ptrdiff_t index = std::ranges::distance(Updateable.Ids.begin(), removedItr);
            uint8 maskLowPart = ContentsChangedMask & ((1 << index) - 1);
            uint8 maskHighPart = (ContentsChangedMask & ~((1 << index) - 1)) >> (1 + IsIndirectFragment(fragment));
            ContentsChangedMask = maskLowPart | maskHighPart;
            for (uint8 i = 0, maskIndex = 0; i < UpdateableCount; ++i)
            {
                Updateable.Masks[i] = 1 << maskIndex++;
                if (IsIndirectFragment(Updateable.Ids[i]))
                {
                    ++maskIndex;
                    Updateable.Masks[i] <<= 1;
                }
            }

            auto removeAtIndex = []<typename T, size_t N>(std::array<T, N>& arr, uint8 oldSize, std::ptrdiff_t i, std::type_identity_t<T> value)
            {
                *std::ranges::move(arr.begin() + i + 1, arr.begin() + oldSize, arr.begin() + i).out = value;
            };

            uint8 oldSize = UpdateableCount + 1;
            removeAtIndex(Updateable.SerializeCreate, oldSize, index, nullptr);
            removeAtIndex(Updateable.SerializeUpdate, oldSize, index, nullptr);
            removeAtIndex(Updateable.IsChanged, oldSize, index, nullptr);
        }
    }

    IdsChanged = true;
}
}
