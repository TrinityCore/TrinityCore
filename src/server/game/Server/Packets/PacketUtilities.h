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
#include "Duration.h"
#include "Tuples.h"
#include <boost/container/static_vector.hpp>
#include <string_view>
#include <ctime>

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
            std::string string = data.ReadCString(false);
            Validate(string);
            value._storage = std::move(string);
            return data;
        }

        String& operator=(std::string const& value)
        {
            Validate(value);
            _storage = value;
            return *this;
        }

        String& operator=(std::string&& value)
        {
            Validate(value);
            _storage = std::move(value);
            return *this;
        }

    private:
        static bool Validate(std::string const& value)
        {
            return ValidateNth(value, std::make_index_sequence<std::tuple_size_v<ValidatorList>>{});
        }

        template<std::size_t... indexes>
        static bool ValidateNth(std::string const& value, std::index_sequence<indexes...>)
        {
            return (std::tuple_element_t<indexes, ValidatorList>::Validate(value) && ...);
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
    template<typename T, std::size_t N>
    class Array
    {
    public:
        typedef boost::container::static_vector<T, N> storage_type;

        typedef std::integral_constant<std::size_t, N> max_capacity;

        typedef typename storage_type::value_type value_type;
        typedef typename storage_type::size_type size_type;
        typedef typename storage_type::pointer pointer;
        typedef typename storage_type::const_pointer const_pointer;
        typedef typename storage_type::reference reference;
        typedef typename storage_type::const_reference const_reference;
        typedef typename storage_type::iterator iterator;
        typedef typename storage_type::const_iterator const_iterator;

        Array() { }

        iterator begin() { return _storage.begin(); }
        const_iterator begin() const { return _storage.begin(); }

        iterator end() { return _storage.end(); }
        const_iterator end() const { return _storage.end(); }

        pointer data() { return _storage.data(); }
        const_pointer data() const { return _storage.data(); }

        size_type size() const { return _storage.size(); }
        bool empty() const { return _storage.empty(); }

        reference operator[](size_type i) { return _storage[i]; }
        const_reference operator[](size_type i) const { return _storage[i]; }

        void resize(size_type newSize)
        {
            if (newSize > max_capacity::value)
                throw PacketArrayMaxCapacityException(newSize, max_capacity::value);

            _storage.resize(newSize);
        }

        void push_back(value_type const& value)
        {
            if (_storage.size() >= max_capacity::value)
                throw PacketArrayMaxCapacityException(_storage.size() + 1, max_capacity::value);

            _storage.push_back(value);
        }

        void push_back(value_type&& value)
        {
            if (_storage.size() >= max_capacity::value)
                throw PacketArrayMaxCapacityException(_storage.size() + 1, max_capacity::value);

            _storage.push_back(std::forward<value_type>(value));
        }

        template<typename... Args>
        T& emplace_back(Args&&... args)
        {
            _storage.emplace_back(std::forward<Args>(args)...);
            return _storage.back();
        }

    private:
        storage_type _storage;
    };

    template<typename Underlying = int64>
    class Timestamp
    {
    public:
        Timestamp() = default;
        Timestamp(time_t value) : _value(value) { }
        Timestamp(SystemTimePoint const& systemTime) : _value(std::chrono::system_clock::to_time_t(systemTime)) { }

        Timestamp& operator=(time_t value)
        {
            _value = value;
            return *this;
        }

        Timestamp& operator=(SystemTimePoint const& systemTime)
        {
            _value = std::chrono::system_clock::to_time_t(systemTime);
            return *this;
        }

        operator time_t() const
        {
            return _value;
        }

        Underlying AsUnderlyingType() const
        {
            return static_cast<Underlying>(_value);
        }

        friend ByteBuffer& operator<<(ByteBuffer& data, Timestamp timestamp)
        {
            data << static_cast<Underlying>(timestamp._value);
            return data;
        }

        friend ByteBuffer& operator>>(ByteBuffer& data, Timestamp& timestamp)
        {
            timestamp._value = data.read<time_t, Underlying>();
            return data;
        }

    private:
        time_t _value = time_t(0);
    };

    template<typename ChronoDuration, typename Underlying = int64>
    class Duration
    {
    public:
        Duration() = default;
        Duration(ChronoDuration value) : _value(value) { }

        Duration& operator=(ChronoDuration value)
        {
            _value = value;
            return *this;
        }

        operator ChronoDuration() const
        {
            return _value;
        }

        friend ByteBuffer& operator<<(ByteBuffer& data, Duration duration)
        {
            data << static_cast<Underlying>(duration._value.count());
            return data;
        }

        friend ByteBuffer& operator>>(ByteBuffer& data, Duration& duration)
        {
            duration._value = ChronoDuration(data.read<Underlying>());
            return data;
        }

    private:
        ChronoDuration _value = ChronoDuration::zero();
    };
}

#endif // PacketUtilities_h__
