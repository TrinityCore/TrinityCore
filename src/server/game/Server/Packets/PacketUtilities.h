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

#ifndef PacketUtilities_h__
#define PacketUtilities_h__

#include "ByteBuffer.h"
#include "Tuples.h"
#include <string_view>

namespace WorldPackets
{
    class InvalidStringValueException : public ByteBufferInvalidValueException
    {
    public:
        InvalidStringValueException(std::string const& value);

        std::string const& GetInvalidValue() const { return _value; }

    private:
        std::string _value;
    };

    class InvalidUtf8ValueException : public InvalidStringValueException
    {
    public:
        InvalidUtf8ValueException(std::string const& value);
    };

    class InvalidHyperlinkException : public InvalidStringValueException
    {
    public:
        InvalidHyperlinkException(std::string const& value);
    };

    class IllegalHyperlinkException : public InvalidStringValueException
    {
    public:
        IllegalHyperlinkException(std::string const& value);
    };

    namespace Strings
    {
        struct RawBytes { static bool Validate(std::string const& /*value*/) { return true; } };
        template<std::size_t MaxBytesWithoutNullTerminator>
        struct ByteSize { static bool Validate(std::string const& value) { return value.size() <= MaxBytesWithoutNullTerminator; } };
        struct Utf8 { static bool Validate(std::string const& value); };
        struct Hyperlinks { static bool Validate(std::string const& value); };
        struct NoHyperlinks { static bool Validate(std::string const& value); };
    }

    /**
     * Utility class for automated prevention of invalid strings in client packets
     */
    template<std::size_t MaxBytesWithoutNullTerminator, typename... Validators>
    class String
    {
        using ValidatorList = std::conditional_t<!Trinity::has_type<Strings::RawBytes, std::tuple<Validators...>>::value,
            std::tuple<Strings::ByteSize<MaxBytesWithoutNullTerminator>, Strings::Utf8, Validators...>,
            std::tuple<Strings::ByteSize<MaxBytesWithoutNullTerminator>, Validators...>>;

    public:
        bool empty() const { return _storage.empty(); }
        char const* c_str() const { return _storage.c_str(); }

        operator std::string_view() const { return _storage; }
        operator std::string&() { return _storage; }
        operator std::string const&() const { return _storage; }

        std::string&& Move() { return std::move(_storage); }

        friend ByteBuffer& operator>>(ByteBuffer& data, String& value)
        {
            value._storage = data.ReadCString(false);
            value.Validate();
            return data;
        }

    private:
        bool Validate() const
        {
            return ValidateNth(std::make_index_sequence<std::tuple_size_v<ValidatorList>>{});
        }

        template<std::size_t... indexes>
        bool ValidateNth(std::index_sequence<indexes...>) const
        {
            return (std::tuple_element_t<indexes, ValidatorList>::Validate(_storage) && ...);
        }

        std::string _storage;
    };

    class PacketArrayMaxCapacityException : public ByteBufferException
    {
    public:
        PacketArrayMaxCapacityException(std::size_t requestedSize, std::size_t sizeLimit);
    };

    /**
     * Utility class for automated prevention of loop counter spoofing in client packets
     */
    template<typename T, std::size_t N = 1000 /*select a sane default limit*/>
    class Array
    {
        typedef std::vector<T> storage_type;

        typedef typename storage_type::value_type value_type;
        typedef typename storage_type::size_type size_type;
        typedef typename storage_type::reference reference;
        typedef typename storage_type::const_reference const_reference;
        typedef typename storage_type::iterator iterator;
        typedef typename storage_type::const_iterator const_iterator;

    public:
        Array() : _limit(N) { }
        Array(size_type limit) : _limit(limit) { }

        iterator begin() { return _storage.begin(); }
        const_iterator begin() const { return _storage.begin(); }

        iterator end() { return _storage.end(); }
        const_iterator end() const { return _storage.end(); }

        size_type size() const { return _storage.size(); }
        bool empty() const { return _storage.empty(); }

        reference operator[](size_type i) { return _storage[i]; }
        const_reference operator[](size_type i) const { return _storage[i]; }

        void resize(size_type newSize)
        {
            if (newSize > _limit)
                throw PacketArrayMaxCapacityException(newSize, _limit);

            _storage.resize(newSize);
        }

        void reserve(size_type newSize)
        {
            if (newSize > _limit)
                throw PacketArrayMaxCapacityException(newSize, _limit);

            _storage.reserve(newSize);
        }

        void push_back(value_type const& value)
        {
            if (_storage.size() >= _limit)
                throw PacketArrayMaxCapacityException(_storage.size() + 1, _limit);

            _storage.push_back(value);
        }

        void push_back(value_type&& value)
        {
            if (_storage.size() >= _limit)
                throw PacketArrayMaxCapacityException(_storage.size() + 1, _limit);

            _storage.push_back(std::forward<value_type>(value));
        }

    private:
        storage_type _storage;
        size_type _limit;
    };

    void CheckCompactArrayMaskOverflow(std::size_t index, std::size_t limit);

    template <typename T>
    class CompactArray
    {
    public:
        CompactArray() : _mask(0) { }

        CompactArray(CompactArray const& right)
            : _mask(right._mask), _contents(right._contents) { }

        CompactArray(CompactArray&& right)
            : _mask(right._mask), _contents(std::move(right._contents))
        {
            right._mask = 0;
        }

        CompactArray& operator=(CompactArray const& right)
        {
            _mask = right._mask;
            _contents = right._contents;
            return *this;
        }

        CompactArray& operator=(CompactArray&& right)
        {
            _mask = right._mask;
            right._mask = 0;
            _contents = std::move(right._contents);
            return *this;
        }

        uint32 GetMask() const { return _mask; }
        T const& operator[](std::size_t index) const { return _contents.at(index); }
        std::size_t GetSize() const { return _contents.size(); }

        void Insert(std::size_t index, T const& value)
        {
            CheckCompactArrayMaskOverflow(index, sizeof(_mask) * 8);

            _mask |= 1 << index;
            if (_contents.size() <= index)
                _contents.resize(index + 1);
            _contents[index] = value;
        }

        void Clear()
        {
            _mask = 0;
            _contents.clear();
        }

        bool operator==(CompactArray const& r) const
        {
            if (_mask != r._mask)
                return false;

            return _contents == r._contents;
        }

        bool operator!=(CompactArray const& r) const { return !(*this == r); }

    private:
        uint32 _mask;
        std::vector<T> _contents;
    };

    template <typename T>
    ByteBuffer& operator<<(ByteBuffer& data, CompactArray<T> const& v)
    {
        uint32 mask = v.GetMask();
        data << uint32(mask);
        for (std::size_t i = 0; i < v.GetSize(); ++i)
            if (mask & (1 << i))
                data << v[i];

        return data;
    }

    template <typename T>
    ByteBuffer& operator>>(ByteBuffer& data, CompactArray<T>& v)
    {
        uint32 mask;
        data >> mask;

        for (std::size_t index = 0; mask != 0; mask >>= 1, ++index)
            if ((mask & 1) != 0)
                v.Insert(index, data.read<T>());

        return data;
    }
}

#endif // PacketUtilities_h__
