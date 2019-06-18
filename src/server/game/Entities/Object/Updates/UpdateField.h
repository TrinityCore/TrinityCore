/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef UpdateField_h__
#define UpdateField_h__

#include "ObjectGuid.h"
#include "UpdateMask.h"
#include <algorithm>
#include <vector>

class ByteBuffer;
class Object;

namespace UF
{
    enum class UpdateFieldFlag : uint8
    {
        None = 0,
        Owner = 0x01,
        PartyMember = 0x02,
        UnitAll = 0x04,
        Empath = 0x08
    };

    template<typename T, uint32 BlockBit, uint32 Bit>
    class UpdateField;

    template<typename T, std::size_t Size, uint32 Bit, uint32 FirstElementBit>
    class UpdateFieldArray;

    template<typename T, uint32 BlockBit, uint32 Bit>
    class DynamicUpdateField;

    template<typename T, bool PublicSet>
    struct MutableFieldReference;

    struct IsUpdateFieldStructureTag
    {
    };
    struct HasChangesMaskTag
    {
    };

    template<typename T>
    struct UpdateFieldSetter
    {
        using ValueType = T;

        template<typename F>
        friend bool SetUpdateFieldValue(UpdateFieldSetter<F>& setter, typename UpdateFieldSetter<F>::ValueType&& value);

        UpdateFieldSetter(T& value) : _value(value)
        {
        }

        T GetValue() const
        {
            return _value;
        }

    private:
        bool SetValue(T value)
        {
            if (_value != value)
            {
                _value = std::move(value);
                return true;
            }
            return false;
        }

        T& _value;
    };

    // Same as UpdateFieldSetter but with public setter, used to set member fields for values added to dynamic fields
    template<typename T>
    struct UpdateFieldPublicSetter
    {
        using ValueType = T;

        UpdateFieldPublicSetter(T& value) : _value(value)
        {
        }

        T GetValue() const
        {
            return _value;
        }

        void SetValue(T value)
        {
            _value = std::move(value);
        }

    private:
        T& _value;
    };

    template<typename T>
    struct DynamicUpdateFieldSetter
    {
        using ValueType = T;
        using NewValueType = std::conditional_t<std::is_base_of<HasChangesMaskTag, T>::value, MutableFieldReference<T, true>, T&>;

        template<typename F>
        friend typename DynamicUpdateFieldSetter<F>::NewValueType AddDynamicUpdateFieldValue(DynamicUpdateFieldSetter<F>& setter);

        template<typename F>
        friend typename DynamicUpdateFieldSetter<F>::NewValueType InsertDynamicUpdateFieldValue(DynamicUpdateFieldSetter<F>& setter, uint32 index);

        template<typename F>
        friend void RemoveDynamicUpdateFieldValue(DynamicUpdateFieldSetter<F>& setter, uint32 index);

        template<typename F>
        friend void ClearDynamicUpdateFieldValues(DynamicUpdateFieldSetter<F>& setter);

        DynamicUpdateFieldSetter(std::vector<T>& values, std::vector<uint32>& updateMask) : _values(values), _updateMask(updateMask)
        {
        }

    private:
        NewValueType AddValue()
        {
            MarkChanged(_values.size());
            _values.emplace_back();
            T& value = _values.back();
            MarkNewValue(value, std::is_base_of<HasChangesMaskTag, T>{});
            return { value };
        }

        NewValueType InsertValue(uint32 index)
        {
            _values.emplace(_values.begin() + index);
            for (uint32 i = index; i < _values.size(); ++i)
            {
                MarkChanged(i);
                // also mark all fields of value as changed
                MarkNewValue(_values[i], std::is_base_of<HasChangesMaskTag, T>{});
            }
            return { _values[index] };
        }

        void RemoveValue(uint32 index)
        {
            // remove by shifting entire container - client might rely on values being sorted for certain fields
            _values.erase(_values.begin() + index);
            for (uint32 i = index; i < _values.size(); ++i)
            {
                MarkChanged(i);
                // also mark all fields of value as changed
                MarkNewValue(_values[i], std::is_base_of<HasChangesMaskTag, T>{});
            }
            if (_values.size() % 32)
                _updateMask[UpdateMaskHelpers::GetBlockIndex(_values.size())] &= ~UpdateMaskHelpers::GetBlockFlag(_values.size());
            else
                _updateMask.pop_back();
        }

        void Clear()
        {
            _values.clear();
            _updateMask.clear();
        }

        void MarkChanged(uint32 index)
        {
            uint32 block = UpdateMaskHelpers::GetBlockIndex(index);
            if (block >= _updateMask.size())
                _updateMask.resize(block + 1);

            _updateMask[block] |= UpdateMaskHelpers::GetBlockFlag(index);
        }

        void MarkNewValue(T&, std::false_type)
        {
        }

        void MarkNewValue(T& value, std::true_type)
        {
            value._changesMask.SetAll();
        }

        std::vector<T>& _values;
        std::vector<uint32>& _updateMask;
    };

    template<typename T, bool PublicSet>
    struct MutableFieldReference
    {
        MutableFieldReference(T& value) : _value(value)
        {
        }

        template<typename V, uint32 BlockBit, uint32 Bit, typename U = T>
        std::enable_if_t<std::is_base_of<HasChangesMaskTag, U>::value,
            std::conditional_t<std::is_base_of<IsUpdateFieldStructureTag, V>::value,
            MutableFieldReference<V, PublicSet>,
            std::conditional_t<PublicSet, UpdateFieldPublicSetter<V>, UpdateFieldSetter<V>>>>
            ModifyValue(UpdateField<V, BlockBit, Bit>(T:: * field))
        {
            _value._changesMask.Set(BlockBit);
            _value._changesMask.Set(Bit);
            return { (_value.*field)._value };
        }

        template<typename V, std::size_t Size, uint32 Bit, uint32 FirstElementBit, typename U = T>
        std::enable_if_t<std::is_base_of<HasChangesMaskTag, U>::value,
            std::conditional_t<std::is_base_of<IsUpdateFieldStructureTag, V>::value,
            MutableFieldReference<V, PublicSet>,
            std::conditional_t<PublicSet, UpdateFieldPublicSetter<V>, UpdateFieldSetter<V>>>>
            ModifyValue(UpdateFieldArray<V, Size, Bit, FirstElementBit>(T:: * field), uint32 index)
        {
            _value._changesMask.Set(Bit);
            _value._changesMask.Set(FirstElementBit + index);
            return { (_value.*field)._values[index] };
        }

        template<typename V, uint32 BlockBit, uint32 Bit, typename U = T>
        std::enable_if_t<std::is_base_of<HasChangesMaskTag, U>::value, DynamicUpdateFieldSetter<V>>
            ModifyValue(DynamicUpdateField<V, BlockBit, Bit>(T::* field))
        {
            _value._changesMask.Set(BlockBit);
            _value._changesMask.Set(Bit);
            return { (_value.*field)._values, (_value.*field)._updateMask };
        }

        template<typename V, uint32 BlockBit, uint32 Bit, typename U = T>
        std::enable_if_t<std::is_base_of<HasChangesMaskTag, U>::value,
            std::conditional_t<std::is_base_of<IsUpdateFieldStructureTag, V>::value,
            MutableFieldReference<V, PublicSet>,
            std::conditional_t<PublicSet, UpdateFieldPublicSetter<V>, UpdateFieldSetter<V>>>>
            ModifyValue(DynamicUpdateField<V, BlockBit, Bit>(T:: * field), uint32 index)
        {
            if (index >= (_value.*field).size())
            {
                // fill with zeros until reaching desired slot
                (_value.*field)._values.resize(index + 1);
                (_value.*field)._updateMask.resize(((_value.*field)._values.size() + 31) / 32);
            }

            _value._changesMask.Set(BlockBit);
            _value._changesMask.Set(Bit);
            (_value.*field).MarkChanged(index);
            return { (_value.*field)._values[index] };
        }

        template<typename V, typename U = T>
        std::enable_if_t<!std::is_base_of<HasChangesMaskTag, U>::value && !std::is_array<V>::value,
            std::conditional_t<PublicSet, UpdateFieldPublicSetter<V>, UpdateFieldSetter<V>>>
            ModifyValue(V(T::* field))
        {
            return { _value.*field };
        }

        template<typename V, std::size_t Size, typename U = T>
        std::enable_if_t<!std::is_base_of<HasChangesMaskTag, U>::value,
            std::conditional_t<PublicSet, UpdateFieldPublicSetter<V>, UpdateFieldSetter<V>>>
            ModifyValue(V(T::* field)[Size], uint32 index)
        {
            return { (_value.*field)[index] };
        }

    private:
        T& _value;
    };

    template<std::size_t Bits>
    class HasChangesMask : public HasChangesMaskTag
    {
        template<typename T>
        friend struct DynamicUpdateFieldSetter;

        template<typename T, bool PublicSet>
        friend struct MutableFieldReference;

        template<typename T, uint32 BlockBit, uint32 Bit>
        friend class UpdateField;

        template<typename T, std::size_t Size, uint32 Bit, uint32 FirstElementBit>
        friend class UpdateFieldArray;

        template<typename T, uint32 BlockBit, uint32 Bit>
        friend class DynamicUpdateField;

    public:
        using Base = HasChangesMask<Bits>;
        using Mask = UpdateMask<Bits>;

        template<typename Derived, typename T, uint32 BlockBit, uint32 Bit>
        MutableFieldReference<T, false> ModifyValue(UpdateField<T, BlockBit, Bit>(Derived::* field))
        {
            _changesMask.Set(BlockBit);
            _changesMask.Set(Bit);
            return { (static_cast<Derived*>(this)->*field)._value };
        }

        template<typename Derived, typename T, std::size_t Size, uint32 Bit, uint32 FirstElementBit>
        MutableFieldReference<T, false> ModifyValue(UpdateFieldArray<T, Size, Bit, FirstElementBit>(Derived::* field), uint32 index)
        {
            _changesMask.Set(Bit);
            _changesMask.Set(FirstElementBit + index);
            return { (static_cast<Derived*>(this)->*field)._values[index] };
        }

        template<typename Derived, typename T, uint32 BlockBit, uint32 Bit>
        MutableFieldReference<T, false> ModifyValue(DynamicUpdateField<T, BlockBit, Bit>(Derived::* field))
        {
            _changesMask.Set(BlockBit);
            _changesMask.Set(Bit);
            return { (static_cast<Derived*>(this)->*field)._values };
        }

        template<typename Derived, typename T, uint32 BlockBit, uint32 Bit>
        MutableFieldReference<T, false> ModifyValue(DynamicUpdateField<T, BlockBit, Bit>(Derived::* field), uint32 index)
        {
            DynamicUpdateField<T, BlockBit, Bit>& uf = (static_cast<Derived*>(this)->*field);
            if (index >= uf.size())
            {
                // fill with zeros until reaching desired slot
                uf._values.resize(index + 1);
                uf._updateMask.resize((uf._values.size() + 31) / 32);
            }

            _changesMask.Set(BlockBit);
            _changesMask.Set(Bit);
            (static_cast<Derived*>(this)->*field).MarkChanged(index);
            return { uf._values[index] };
        }

        template<typename Derived, typename T, uint32 BlockBit, uint32 Bit>
        void ClearChanged(UpdateField<T, BlockBit, Bit>(Derived::*))
        {
            _changesMask.Reset(Bit);
        }

        template<typename Derived, typename T, std::size_t Size, uint32 Bit, uint32 FirstElementBit>
        void ClearChanged(UpdateFieldArray<T, Size, Bit, FirstElementBit>(Derived::*), uint32 index)
        {
            _changesMask.Reset(Bit);
            _changesMask.Reset(FirstElementBit + index);
        }

        template<typename Derived, typename T, uint32 BlockBit, uint32 Bit>
        void ClearChanged(DynamicUpdateField<T, BlockBit, Bit>(Derived::* field), uint32 index)
        {
            _changesMask.Reset(Bit);
            (static_cast<Derived*>(this)->*field).ClearChanged(index);
        }

    protected:
        template<typename T, uint32 BlockBit, uint32 Bit>
        void ClearChangesMask(UpdateField<T, BlockBit, Bit>& field)
        {
            ClearChangesMask(field, std::is_base_of<HasChangesMaskTag, T>{});
        }

        template<typename T, uint32 BlockBit, uint32 Bit>
        void ClearChangesMask(UpdateField<T, BlockBit, Bit>&, std::false_type) { }

        template<typename T, uint32 BlockBit, uint32 Bit>
        void ClearChangesMask(UpdateField<T, BlockBit, Bit>& field, std::true_type)
        {
            field._value.ClearChangesMask();
        }

        template<typename T, std::size_t Size, uint32 Bit, uint32 FirstElementBit>
        void ClearChangesMask(UpdateFieldArray<T, Size, Bit, FirstElementBit>& field)
        {
            ClearChangesMask(field, std::is_base_of<HasChangesMaskTag, T>{});
        }

        template<typename T, std::size_t Size, uint32 Bit, uint32 FirstElementBit>
        void ClearChangesMask(UpdateFieldArray<T, Size, Bit, FirstElementBit>&, std::false_type) { }

        template<typename T, std::size_t Size, uint32 Bit, uint32 FirstElementBit>
        void ClearChangesMask(UpdateFieldArray<T, Size, Bit, FirstElementBit>& field, std::true_type)
        {
            for (uint32 i = 0; i < Size; ++i)
                field._values[i].ClearChangesMask();
        }

        template<typename T, uint32 BlockBit, uint32 Bit>
        void ClearChangesMask(DynamicUpdateField<T, BlockBit, Bit>& field)
        {
            ClearChangesMask(field, std::is_base_of<HasChangesMaskTag, T>{});
            field.ClearChangesMask();
        }

        template<typename T, uint32 BlockBit, uint32 Bit>
        void ClearChangesMask(DynamicUpdateField<T, BlockBit, Bit>&, std::false_type) { }

        template<typename T, uint32 BlockBit, uint32 Bit>
        void ClearChangesMask(DynamicUpdateField<T, BlockBit, Bit>& field, std::true_type)
        {
            for (uint32 i = 0; i < field._values.size(); ++i)
                field._values[i].ClearChangesMask();
        }

        UpdateMask<Bits> _changesMask;
    };

    class UpdateFieldHolder
    {
    public:
        explicit UpdateFieldHolder(Object* owner) : _owner(owner)
        {
        }

        template<typename Derived, typename T, uint32 BlockBit, uint32 Bit>
        MutableFieldReference<T, false> ModifyValue(UpdateField<T, BlockBit, Bit>(Derived::* field))
        {
            _changesMask.Set(Bit);
            return { (static_cast<Derived*>(_owner)->*field)._value };
        }

        template<typename Derived, typename T, uint32 BlockBit, uint32 Bit>
        void ClearChangesMask(UpdateField<T, BlockBit, Bit>(Derived::* field))
        {
            _changesMask.Reset(Bit);
            (static_cast<Derived*>(_owner)->*field)._value.ClearChangesMask();
        }

        uint32 GetChangedObjectTypeMask() const
        {
            return _changesMask.GetBlock(0);
        }

        bool HasChanged(uint32 index) const
        {
            return _changesMask[index];
        }

    private:
        UpdateMask<NUM_CLIENT_OBJECT_TYPES> _changesMask;
        Object* _owner;
    };

    template<typename T, uint32 BlockBit, uint32 Bit>
    class UpdateField
    {
        template<typename F, bool PublicSet>
        friend struct MutableFieldReference;

        template<std::size_t Bits>
        friend class HasChangesMask;

        friend class UpdateFieldHolder;

    public:
        using ValueType = T;

        operator T const& () const
        {
            return _value;
        }
        T const* operator->() const
        {
            return &_value;
        }
        T const& operator*() const
        {
            return _value;
        }

    private:
        T _value = {};
    };

    template<typename T, std::size_t Size, uint32 Bit, uint32 FirstElementBit>
    class UpdateFieldArray
    {
        template<typename F, bool PublicSet>
        friend struct MutableFieldReference;

        template<std::size_t Bits>
        friend class HasChangesMask;

    public:
        using ValueType = T;

        T const* begin() const
        {
            return std::begin(_values);
        }

        T const* end() const
        {
            return std::end(_values);
        }

        T const& operator[](uint32 index) const
        {
            return _values[index];
        }

    private:
        T _values[Size] = {};
    };

    void WriteDynamicFieldUpdateMask(std::size_t size, std::vector<uint32> const& updateMask, ByteBuffer& data);

    template<typename T, uint32 BlockBit, uint32 Bit>
    class DynamicUpdateField
    {
        template<typename F, bool PublicSet>
        friend struct MutableFieldReference;

        template<std::size_t Bits>
        friend class HasChangesMask;

    public:
        using ValueType = T;

        typename std::vector<T>::const_iterator begin() const
        {
            return _values.begin();
        }

        typename std::vector<T>::const_iterator end() const
        {
            return _values.end();
        }

        std::size_t size() const
        {
            return _values.size();
        }

        T const& operator[](uint32 index) const
        {
            return _values[index];
        }

        int32 FindIndex(T const& value) const
        {
            auto itr = std::find(_values.begin(), _values.end(), value);
            if (itr != _values.end())
                return int32(std::distance(_values.begin(), itr));

            return -1;
        }

        template<typename Pred>
        int32 FindIndexIf(Pred pred) const
        {
            auto itr = std::find_if(_values.begin(), _values.end(), pred);
            if (itr != _values.end())
                return int32(std::distance(_values.begin(), itr));

            return -1;
        }

        bool HasChanged(uint32 index) const
        {
            return (_updateMask[index / 32] & (1 << (index % 32))) != 0;
        }

        void WriteUpdateMask(ByteBuffer& data) const
        {
            WriteDynamicFieldUpdateMask(_values.size(), _updateMask, data);
        }

    private:
        void MarkChanged(uint32 index)
        {
            uint32 block = UpdateMaskHelpers::GetBlockIndex(index);
            if (block >= _updateMask.size())
                _updateMask.emplace_back(0);

            _updateMask[block] |= UpdateMaskHelpers::GetBlockFlag(index);
        }

        void ClearChanged(uint32 index)
        {
            uint32 block = UpdateMaskHelpers::GetBlockIndex(index);
            if (block >= _updateMask.size())
                _updateMask.emplace_back(0);

            _updateMask[block] &= ~UpdateMaskHelpers::GetBlockFlag(index);
        }

        void ClearChangesMask()
        {
            std::fill(_updateMask.begin(), _updateMask.end(), 0);
        }

        std::vector<T> _values;
        std::vector<uint32> _updateMask;
    };

    template<typename T>
    struct ViewerDependentValueTag
    {
        using ValueType = T;
    };
}

#endif // UpdateField_h__
