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
#include <array>
#include <span>

class BaseEntity;
class ByteBuffer;
class Player;

namespace UF
{
enum class UpdateFieldFlag : uint8;
}

namespace WowCS
{
enum class EntityFragment : uint8
{
    FEntityPosition             = 1,
    CGObject                    = 2, //  UPDATEABLE, INDIRECT,
    FTransportLink              = 5,
    FPlayerOwnershipLink        = 13, //  INDIRECT,
    CActor                      = 15, //  INDIRECT,
    FVendor_C                   = 17, //  UPDATEABLE,
    FMirroredObject_C           = 18,
    FMeshObjectData_C           = 19, //  UPDATEABLE,
    FHousingDecor_C             = 20, //  UPDATEABLE,
    FHousingRoom_C              = 21, //  UPDATEABLE,
    FHousingRoomComponentMesh_C = 22, //  UPDATEABLE,
    FHousingPlayerHouse_C       = 23, //  UPDATEABLE,
    FJamHousingCornerstone_C    = 27, //  UPDATEABLE,
    FHousingDecorActor_C        = 28,
    FHousingPlotAreaTrigger_C   = 29, //  UPDATEABLE,
    FNeighborhoodMirrorData_C   = 30, //  UPDATEABLE,
    FMirroredPositionData_C     = 31, //  UPDATEABLE,
    PlayerHouseInfoComponent_C  = 32, //  UPDATEABLE, INDIRECT,
    FHousingStorage_C           = 33, //  UPDATEABLE,
    FHousingFixture_C           = 34, //  UPDATEABLE,
    PlayerInitiativeComponent_C = 37, //  UPDATEABLE, INDIRECT,
    Tag_Item                    = 200, //  TAG,
    Tag_Container               = 201, //  TAG,
    Tag_AzeriteEmpoweredItem    = 202, //  TAG,
    Tag_AzeriteItem             = 203, //  TAG,
    Tag_Unit                    = 204, //  TAG,
    Tag_Player                  = 205, //  TAG,
    Tag_GameObject              = 206, //  TAG,
    Tag_DynamicObject           = 207, //  TAG,
    Tag_Corpse                  = 208, //  TAG,
    Tag_AreaTrigger             = 209, //  TAG,
    Tag_SceneObject             = 210, //  TAG,
    Tag_Conversation            = 211, //  TAG,
    Tag_AIGroup                 = 212, //  TAG,
    Tag_Scenario                = 213, //  TAG,
    Tag_LootObject              = 214, //  TAG,
    Tag_ActivePlayer            = 215, //  TAG,
    Tag_ActiveClient_S          = 216, //  TAG,
    Tag_ActiveObject_C          = 217, //  TAG,
    Tag_VisibleObject_C         = 218, //  TAG,
    Tag_UnitVehicle             = 219, //  TAG,
    Tag_HousingRoom             = 220, //  TAG,
    Tag_MeshObject              = 221, //  TAG,
    Tag_HouseExteriorPiece      = 224, //  TAG,
    Tag_HouseExteriorRoot       = 225, //  TAG,
    End                         = 255,
};

inline constexpr bool IsUpdateableFragment(EntityFragment frag)
{
    return frag == EntityFragment::CGObject
        || frag == EntityFragment::FVendor_C
        || frag == EntityFragment::FMeshObjectData_C
        || frag == EntityFragment::FHousingDecor_C
        || frag == EntityFragment::FHousingRoom_C
        || frag == EntityFragment::FHousingRoomComponentMesh_C
        || frag == EntityFragment::FHousingPlayerHouse_C
        || frag == EntityFragment::FJamHousingCornerstone_C
        || frag == EntityFragment::FHousingPlotAreaTrigger_C
        || frag == EntityFragment::FNeighborhoodMirrorData_C
        || frag == EntityFragment::FMirroredPositionData_C
        || frag == EntityFragment::PlayerHouseInfoComponent_C
        || frag == EntityFragment::FHousingStorage_C
        || frag == EntityFragment::FHousingFixture_C
        || frag == EntityFragment::PlayerInitiativeComponent_C;
}

inline constexpr bool IsIndirectFragment(EntityFragment frag)
{
    return frag == EntityFragment::CGObject
        || frag == EntityFragment::FPlayerOwnershipLink
        || frag == EntityFragment::CActor
        || frag == EntityFragment::PlayerHouseInfoComponent_C
        || frag == EntityFragment::PlayerInitiativeComponent_C;
}

template <auto /*FragmentMemberPtr*/>
struct FragmentSerializationTraits
{
};

template <typename Entity, typename Fragment, Fragment Entity::* FragmentData>
struct FragmentSerializationTraits<FragmentData>
{
    static void BuildCreate(BaseEntity const* baseEntity, ByteBuffer& data, UF::UpdateFieldFlag flags, Player const* target)
    {
        Entity const* entity = static_cast<Entity const*>(baseEntity);
        (entity->*FragmentData)->WriteCreate(data, flags, entity, target);
    }

    static void BuildUpdate(BaseEntity const* baseEntity, ByteBuffer& data, UF::UpdateFieldFlag flags, Player const* target)
    {
        Entity const* entity = static_cast<Entity const*>(baseEntity);
        (entity->*FragmentData)->WriteUpdate(data, flags, entity, target);
    }

    static bool IsChanged(BaseEntity const* baseEntity)
    {
        Entity const* entity = static_cast<Entity const*>(baseEntity);
        return (entity->*FragmentData)->GetChangesMask().IsAnySet();
    }
};

using EntityFragmentSerializeFn = void (*)(BaseEntity const* entity, ByteBuffer& data, UF::UpdateFieldFlag flags, Player const* target);
using EntityFragmentIsChangedFn = bool (*)(BaseEntity const* entity);

struct EntityFragmentsHolder
{
    std::array<EntityFragment, 8> Ids =
    {
        EntityFragment::End, EntityFragment::End, EntityFragment::End, EntityFragment::End,
        EntityFragment::End, EntityFragment::End, EntityFragment::End, EntityFragment::End
    };

    struct UpdateableFragments
    {
        static constexpr std::size_t N = 4;

        std::array<EntityFragment, N> Ids =
        {
            EntityFragment::End, EntityFragment::End, EntityFragment::End, EntityFragment::End
        };
        std::array<uint8, N> Masks = { };
        std::array<EntityFragmentSerializeFn, N> SerializeCreate = { };
        std::array<EntityFragmentSerializeFn, N> SerializeUpdate = { };
        std::array<EntityFragmentIsChangedFn, N> IsChanged = { };
    };

    UpdateableFragments Updateable;

    uint8 Count = 0;
    bool IdsChanged = false;

    uint8 UpdateableCount = 0;
    uint8 ContentsChangedMask = 0;

    void Add(EntityFragment fragment, bool update,
        EntityFragmentSerializeFn serializeCreate, EntityFragmentSerializeFn serializeUpdate, EntityFragmentIsChangedFn isChanged);

    inline void Add(EntityFragment fragment, bool update) { Add(fragment, update, nullptr, nullptr, nullptr); }

    template <typename SerializationTraits>
    inline void Add(EntityFragment fragment, bool update, SerializationTraits)
    {
        Add(fragment, update, &SerializationTraits::BuildCreate, &SerializationTraits::BuildUpdate, &SerializationTraits::IsChanged);
    }

    void Remove(EntityFragment fragment);

    std::span<EntityFragment const> GetIds() const { return std::span(Ids.begin(), Count); }
};

enum class EntityFragmentSerializationType : uint8
{
    Full    = 0,
    Partial = 1
};
}

#endif // TRINITYCORE_WOWCS_ENTITY_DEFINITIONS_H
