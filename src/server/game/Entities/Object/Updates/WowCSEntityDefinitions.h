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

#ifndef TRINITYCORE_WOWCS_ENTITY_DEFINITIONS_H
#define TRINITYCORE_WOWCS_ENTITY_DEFINITIONS_H

#include "Define.h"
#include <span>

namespace WowCS
{
enum class EntityFragment : uint8
{
    CGObject                    = 0, //  UPDATEABLE, INDIRECT,
    Tag_Item                    = 1, //  TAG,
    Tag_Container               = 2, //  TAG,
    Tag_AzeriteEmpoweredItem    = 3, //  TAG,
    Tag_AzeriteItem             = 4, //  TAG,
    Tag_Unit                    = 5, //  TAG,
    Tag_Player                  = 6, //  TAG,
    Tag_GameObject              = 7, //  TAG,
    Tag_DynamicObject           = 8, //  TAG,
    Tag_Corpse                  = 9, //  TAG,
    Tag_AreaTrigger             = 10, //  TAG,
    Tag_SceneObject             = 11, //  TAG,
    Tag_Conversation            = 12, //  TAG,
    Tag_AIGroup                 = 13, //  TAG,
    Tag_Scenario                = 14, //  TAG,
    Tag_LootObject              = 15, //  TAG,
    Tag_ActivePlayer            = 16, //  TAG,
    Tag_ActiveClient_S          = 17, //  TAG,
    Tag_ActiveObject_C          = 18, //  TAG,
    Tag_VisibleObject_C         = 19, //  TAG,
    Tag_UnitVehicle             = 20, //  TAG,
    FEntityPosition             = 112,
    FEntityLocalMatrix          = 113,
    FEntityWorldMatrix          = 114,
    CActor                      = 115, //  INDIRECT,
    FVendor_C                   = 117, //  UPDATEABLE,
    FMirroredObject_C           = 119,
    End                         = 255,
};

inline constexpr bool IsUpdateableFragment(EntityFragment frag)
{
    return frag == EntityFragment::CGObject || frag == EntityFragment::FVendor_C;
}

inline constexpr bool IsIndirectFragment(EntityFragment frag)
{
    return frag == EntityFragment::CGObject || frag == EntityFragment::CActor;
}

// common case optimization, make use of the fact that fragment arrays are sorted
inline constexpr uint8 CGObjectActiveMask   = 0x1;
inline constexpr uint8 CGObjectChangedMask  = 0x2;
inline constexpr uint8 CGObjectUpdateMask   = CGObjectActiveMask | CGObjectChangedMask;

struct EntityFragmentsHolder
{
    std::array<EntityFragment, 8> Ids =
    {
        EntityFragment::End, EntityFragment::End, EntityFragment::End, EntityFragment::End,
        EntityFragment::End, EntityFragment::End, EntityFragment::End, EntityFragment::End
    };
    uint8 Count = 0;
    bool IdsChanged = false;

    std::array<EntityFragment, 2> UpdateableIds = { EntityFragment::End, EntityFragment::End };
    std::array<uint8, 2> UpdateableMasks = { };
    uint8 UpdateableCount = 0;
    uint8 ContentsChangedMask = 0;

    void Add(EntityFragment fragment, bool update);
    void Remove(EntityFragment fragment);

    std::span<EntityFragment const> GetIds() const { return std::span(Ids.begin(), Count); }
    std::span<EntityFragment const> GetUpdateableIds() const { return std::span(UpdateableIds.begin(), UpdateableCount); }

    uint8 GetUpdateMaskFor(EntityFragment fragment) const
    {
        if (fragment == EntityFragment::CGObject)   // common case optimization, make use of the fact that fragment arrays are sorted
            return CGObjectChangedMask;

        for (uint8 i = 1; i < UpdateableCount; ++i)
            if (UpdateableIds[i] == fragment)
                return UpdateableMasks[i];

        return 0;
    }
};

enum class EntityFragmentSerializationType : uint8
{
    Full    = 0,
    Partial = 1
};
}

#endif // TRINITYCORE_WOWCS_ENTITY_DEFINITIONS_H
