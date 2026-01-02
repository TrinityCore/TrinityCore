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

#ifndef TRINITYCORE_BASE_ENTITY_H
#define TRINITYCORE_BASE_ENTITY_H

#include "Common.h"
#include "ObjectGuid.h"
#include "UpdateFields.h"
#include "WowCSEntityDefinitions.h"
#include <unordered_map>

class BaseEntity;
class Player;
class UpdateData;
class WorldPacket;

typedef std::unordered_map<Player*, UpdateData> UpdateDataMapType;

struct CreateObjectBits
{
    bool HasEntityPosition : 1;
    bool NoBirthAnim : 1;
    bool EnablePortals : 1;
    bool PlayHoverAnim : 1;
    bool ThisIsYou : 1;
    bool MovementUpdate : 1;
    bool MovementTransport : 1;
    bool Stationary : 1;
    bool CombatVictim : 1;
    bool ServerTime : 1;
    bool Vehicle : 1;
    bool AnimKit : 1;
    bool Rotation : 1;
    bool GameObject : 1;
    bool SmoothPhasing : 1;
    bool SceneObject : 1;
    bool ActivePlayer : 1;
    bool Conversation : 1;
    bool Room : 1;
    bool Decor : 1;
    bool MeshObject : 1;

    void Clear()
    {
        memset(this, 0, sizeof(CreateObjectBits));
    }
};

namespace UF
{
    class UpdateFieldHolder
    {
    public:
        template<typename Derived, typename T, int32 BlockBit, uint32 Bit>
        inline MutableFieldReference<T, false> ModifyValue(UpdateField<T, BlockBit, Bit>(Derived::* field));

        template<typename Derived, typename T, int32 BlockBit, uint32 Bit>
        inline OptionalUpdateFieldSetter<T> ModifyValue(OptionalUpdateField<T, BlockBit, Bit>(Derived::* field));

        template<typename Derived, typename T, int32 BlockBit, uint32 Bit>
        inline MutableFieldReference<T, false> ModifyValue(OptionalUpdateField<T, BlockBit, Bit>(Derived::* field), uint32 /*dummy*/);

        template<typename Derived, typename T, int32 BlockBit, uint32 Bit>
        inline void ClearChangesMask(UpdateField<T, BlockBit, Bit>(Derived::* field));

        template<typename Derived, typename T, int32 BlockBit, uint32 Bit>
        inline void ClearChangesMask(OptionalUpdateField<T, BlockBit, Bit>(Derived::* field));

        uint32 GetChangedObjectTypeMask() const { return _changesMask; }

        bool HasChanged(uint32 index) const { return (_changesMask & UpdateMaskHelpers::GetBlockFlag(index)) != 0; }

        inline BaseEntity* GetOwner();

    private:
        friend BaseEntity;

        // This class is tightly tied to BaseEntity::m_values member, do not construct elsewhere
        UpdateFieldHolder() = default;

        uint32 _changesMask = 0; // changes mask for data of Object subclasses
    };

    template<typename T>
    inline bool SetUpdateFieldValue(UpdateFieldPrivateSetter<T>& setter, typename UpdateFieldPrivateSetter<T>::value_type&& value)
    {
        return setter.SetValue(std::move(value));
    }

    template<typename T>
    inline typename DynamicUpdateFieldSetter<T>::insert_result AddDynamicUpdateFieldValue(DynamicUpdateFieldSetter<T>& setter)
    {
        return setter.AddValue();
    }

    template<typename T>
    inline typename DynamicUpdateFieldSetter<T>::insert_result InsertDynamicUpdateFieldValue(DynamicUpdateFieldSetter<T>& setter, uint32 index)
    {
        return setter.InsertValue(index);
    }

    template<typename T>
    inline void RemoveDynamicUpdateFieldValue(DynamicUpdateFieldSetter<T>& setter, uint32 index)
    {
        setter.RemoveValue(index);
    }

    template<typename T>
    inline void ClearDynamicUpdateFieldValues(DynamicUpdateFieldSetter<T>& setter)
    {
        setter.Clear();
    }

    template<typename K, typename V>
    inline void RemoveMapUpdateFieldValue(MapUpdateFieldSetter<K, V>& setter, std::type_identity_t<K> const& key)
    {
        setter.RemoveKey(key);
    }

    template<typename T>
    inline void RemoveOptionalUpdateFieldValue(OptionalUpdateFieldSetter<T>& setter)
    {
        setter.RemoveValue();
    }
}

class TC_GAME_API BaseEntity
{
        ObjectGuid m_guid;

    public:
        virtual ~BaseEntity();

        bool IsInWorld() const { return m_inWorld; }

        virtual void AddToWorld();
        virtual void RemoveFromWorld();

        static ObjectGuid GetGUID(BaseEntity const* o) { return o ? o->GetGUID() : ObjectGuid::Empty; }
        ObjectGuid const& GetGUID() const { return m_guid; }

        TypeID GetTypeId() const { return m_objectTypeId; }
        bool isType(TypeMask mask) const { return (ObjectTypeMask[m_objectTypeId] & mask) != 0; }

        inline bool IsWorldObject() const { return isType(TYPEMASK_WORLDOBJECT); }
        inline bool IsItem() const { return isType(TYPEMASK_ITEM); }
        inline bool IsUnit() const { return isType(TYPEMASK_UNIT); }
        inline bool IsCreature() const { return GetTypeId() == TYPEID_UNIT; }
        inline bool IsPlayer() const { return GetTypeId() == TYPEID_PLAYER; }
        inline bool IsGameObject() const { return GetTypeId() == TYPEID_GAMEOBJECT; }
        inline bool IsDynObject() const { return GetTypeId() == TYPEID_DYNAMICOBJECT; }
        inline bool IsCorpse() const { return GetTypeId() == TYPEID_CORPSE; }
        inline bool IsAreaTrigger() const { return GetTypeId() == TYPEID_AREATRIGGER; }
        inline bool IsSceneObject() const { return GetTypeId() == TYPEID_SCENEOBJECT; }
        inline bool IsConversation() const { return GetTypeId() == TYPEID_CONVERSATION; }
        inline bool IsMeshObject() const { return GetTypeId() == TYPEID_MESH_OBJECT; }

        virtual void BuildCreateUpdateBlockForPlayer(UpdateData* data, Player* target) const;
        void SendUpdateToPlayer(Player* player) const;

        void BuildValuesUpdateBlockForPlayer(UpdateData* data, Player const* target) const;
        void BuildDestroyUpdateBlock(UpdateData* data) const;
        void BuildOutOfRangeUpdateBlock(UpdateData* data) const;
        ByteBuffer& PrepareValuesUpdateBuffer(UpdateData* data) const;

        virtual void DestroyForPlayer(Player const* target) const;
        void SendOutOfRangeForPlayer(Player const* target) const;

        virtual void ClearUpdateMask(bool remove);

        virtual std::string GetNameForLocaleIdx(LocaleConstant locale) const = 0;

        void SetIsNewObject(bool enable) { m_isNewObject = enable; }
        bool IsDestroyedObject() const { return m_isDestroyedObject; }
        void SetDestroyedObject(bool destroyed) { m_isDestroyedObject = destroyed; }
        virtual void BuildUpdate([[maybe_unused]] UpdateDataMapType& data_map) { }
        void BuildUpdateChangesMask();
        void BuildFieldsUpdate(Player* player, UpdateDataMapType& data_map) const;

        friend UF::UpdateFieldHolder;
        UF::UpdateFieldHolder m_values;

        template<typename T>
        void ForceUpdateFieldChange(UF::UpdateFieldPrivateSetter<T> const& /*setter*/)
        {
            AddToObjectUpdateIfNeeded();
        }

        virtual std::string GetDebugInfo() const;

    protected:
        BaseEntity();

        void _Create(ObjectGuid const& guid) { m_guid = guid; }

        template<typename T>
        void SetUpdateFieldValue(UF::UpdateFieldPrivateSetter<T> setter, typename UF::UpdateFieldPrivateSetter<T>::value_type value)
        {
            if (UF::SetUpdateFieldValue(setter, std::move(value)))
                AddToObjectUpdateIfNeeded();
        }

        template<typename T>
        void SetUpdateFieldFlagValue(UF::UpdateFieldPrivateSetter<T> setter, typename UF::UpdateFieldPrivateSetter<T>::value_type flag)
        {
            static_assert(std::is_integral_v<T>, "SetUpdateFieldFlagValue must be used with integral types");
            this->SetUpdateFieldValue(setter, setter.GetValue() | flag);
        }

        template<typename T>
        void RemoveUpdateFieldFlagValue(UF::UpdateFieldPrivateSetter<T> setter, typename UF::UpdateFieldPrivateSetter<T>::value_type flag)
        {
            static_assert(std::is_integral_v<T>, "RemoveUpdateFieldFlagValue must be used with integral types");
            this->SetUpdateFieldValue(setter, setter.GetValue() & ~flag);
        }

        template<typename T>
        typename UF::DynamicUpdateFieldSetter<T>::insert_result AddDynamicUpdateFieldValue(UF::DynamicUpdateFieldSetter<T> setter)
        {
            AddToObjectUpdateIfNeeded();
            return UF::AddDynamicUpdateFieldValue(setter);
        }

        template<typename T>
        typename UF::DynamicUpdateFieldSetter<T>::insert_result InsertDynamicUpdateFieldValue(UF::DynamicUpdateFieldSetter<T> setter, uint32 index)
        {
            AddToObjectUpdateIfNeeded();
            return UF::InsertDynamicUpdateFieldValue(setter, index);
        }

        template<typename T>
        void RemoveDynamicUpdateFieldValue(UF::DynamicUpdateFieldSetter<T> setter, uint32 index)
        {
            AddToObjectUpdateIfNeeded();
            UF::RemoveDynamicUpdateFieldValue(setter, index);
        }

        template<typename K, typename V>
        void RemoveMapUpdateFieldValue(UF::MapUpdateFieldSetter<K, V> setter, std::type_identity_t<K> const& key)
        {
            AddToObjectUpdateIfNeeded();
            UF::RemoveMapUpdateFieldValue(setter, key);
        }

        template<typename T>
        void ClearDynamicUpdateFieldValues(UF::DynamicUpdateFieldSetter<T> setter)
        {
            AddToObjectUpdateIfNeeded();
            UF::ClearDynamicUpdateFieldValues(setter);
        }

        template<typename T>
        void RemoveOptionalUpdateFieldValue(UF::OptionalUpdateFieldSetter<T> setter)
        {
            AddToObjectUpdateIfNeeded();
            UF::RemoveOptionalUpdateFieldValue(setter);
        }

        // stat system helpers
        template<typename T>
        void SetUpdateFieldStatValue(UF::UpdateFieldPrivateSetter<T> setter, typename UF::UpdateFieldPrivateSetter<T>::value_type value)
        {
            static_assert(std::is_arithmetic_v<T>, "SetUpdateFieldStatValue must be used with arithmetic types");
            this->SetUpdateFieldValue(setter, std::max(value, T(0)));
        }

        template<typename T>
        void ApplyModUpdateFieldValue(UF::UpdateFieldPrivateSetter<T> setter, typename UF::UpdateFieldPrivateSetter<T>::value_type mod, bool apply)
        {
            static_assert(std::is_arithmetic_v<T>, "SetUpdateFieldStatValue must be used with arithmetic types");

            T value = setter.GetValue();
            if (apply)
                value += mod;
            else
                value -= mod;

            this->SetUpdateFieldValue(setter, value);
        }

        template<typename T>
        void ApplyPercentModUpdateFieldValue(UF::UpdateFieldPrivateSetter<T> setter, float percent, bool apply)
        {
            static_assert(std::is_arithmetic_v<T>, "SetUpdateFieldStatValue must be used with arithmetic types");

            T value = setter.GetValue();

            // don't want to include Util.h here
            //ApplyPercentModFloatVar(value, percent, apply);
            if (percent == -100.0f)
                percent = -99.99f;
            value *= (apply ? (100.0f + percent) / 100.0f : 100.0f / (100.0f + percent));

            this->SetUpdateFieldValue(setter, value);
        }

        template<typename Action>
        void DoWithSuppressingObjectUpdates(Action&& action)
        {
            bool wasUpdatedBeforeAction = m_objectUpdated;
            action();
            if (m_objectUpdated && !wasUpdatedBeforeAction)
            {
                RemoveFromObjectUpdate();
                m_objectUpdated = false;
            }
        }

        void BuildMovementUpdate(ByteBuffer* data, CreateObjectBits flags, Player const* target) const;
        virtual UF::UpdateFieldFlag GetUpdateFieldFlagsFor(Player const* target) const;
        static void BuildEntityFragments(ByteBuffer* data, std::span<WowCS::EntityFragment const> fragments);

        TypeID m_objectTypeId = NUM_CLIENT_OBJECT_TYPES;
        CreateObjectBits m_updateFlag = {};
        WowCS::EntityFragmentsHolder m_entityFragments;

        virtual bool AddToObjectUpdate() = 0;
        virtual void RemoveFromObjectUpdate() = 0;
        void AddToObjectUpdateIfNeeded();

        bool m_objectUpdated = false;

    private:
        bool m_inWorld = false;
        bool m_isNewObject = false;
        bool m_isDestroyedObject = false;

        BaseEntity(BaseEntity const& right) = delete;
        BaseEntity(BaseEntity&& right) = delete;
        BaseEntity& operator=(BaseEntity const& right) = delete;
        BaseEntity& operator=(BaseEntity&& right) = delete;
};

inline BaseEntity* UF::UpdateFieldHolder::GetOwner()
{
#if TRINITY_COMPILER == TRINITY_COMPILER_GNU
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Winvalid-offsetof"
#endif

    return reinterpret_cast<BaseEntity*>(reinterpret_cast<std::byte*>(this) - offsetof(BaseEntity, m_values));

#if TRINITY_COMPILER == TRINITY_COMPILER_GNU
#pragma GCC diagnostic pop
#endif
}

template <typename Derived, typename T, int32 BlockBit, uint32 Bit>
inline UF::MutableFieldReference<T, false> UF::UpdateFieldHolder::ModifyValue(UpdateField<T, BlockBit, Bit> Derived::* field)
{
    BaseEntity* owner = GetOwner();
    if constexpr (WowCS::EntityFragment(BlockBit) == WowCS::EntityFragment::CGObject)
        _changesMask |= UpdateMaskHelpers::GetBlockFlag(Bit);

    return { (static_cast<Derived*>(owner)->*field)._value };
}

template <typename Derived, typename T, int32 BlockBit, uint32 Bit>
inline UF::OptionalUpdateFieldSetter<T> UF::UpdateFieldHolder::ModifyValue(OptionalUpdateField<T, BlockBit, Bit> Derived::* field)
{
    BaseEntity* owner = GetOwner();
    if constexpr (WowCS::EntityFragment(BlockBit) == WowCS::EntityFragment::CGObject)
        _changesMask |= UpdateMaskHelpers::GetBlockFlag(Bit);

    return { static_cast<Derived*>(owner)->*field };
}

template <typename Derived, typename T, int32 BlockBit, uint32 Bit>
inline UF::MutableFieldReference<T, false> UF::UpdateFieldHolder::ModifyValue(OptionalUpdateField<T, BlockBit, Bit> Derived::* field, uint32 /*dummy*/)
{
    BaseEntity* owner = GetOwner();
    if constexpr (WowCS::EntityFragment(BlockBit) == WowCS::EntityFragment::CGObject)
        _changesMask |= UpdateMaskHelpers::GetBlockFlag(Bit);

    auto& uf = (static_cast<Derived*>(owner)->*field);
    if (!uf.has_value())
        uf.ConstructValue();

    return { *uf._value };
}

template <typename Derived, typename T, int32 BlockBit, uint32 Bit>
inline void UF::UpdateFieldHolder::ClearChangesMask(UpdateField<T, BlockBit, Bit> Derived::* field)
{
    BaseEntity* owner = GetOwner();
    if constexpr (WowCS::EntityFragment(BlockBit) == WowCS::EntityFragment::CGObject)
        _changesMask &= ~UpdateMaskHelpers::GetBlockFlag(Bit);

    (static_cast<Derived*>(owner)->*field)._value.ClearChangesMask();
}

template <typename Derived, typename T, int32 BlockBit, uint32 Bit>
inline void UF::UpdateFieldHolder::ClearChangesMask(OptionalUpdateField<T, BlockBit, Bit> Derived::* field)
{
    BaseEntity* owner = GetOwner();
    if constexpr (WowCS::EntityFragment(BlockBit) == WowCS::EntityFragment::CGObject)
        _changesMask &= ~UpdateMaskHelpers::GetBlockFlag(Bit);

    auto& uf = (static_cast<Derived*>(owner)->*field);
    if (uf.has_value())
        uf._value->ClearChangesMask();
}

#endif // TRINITYCORE_BASE_ENTITY_H
