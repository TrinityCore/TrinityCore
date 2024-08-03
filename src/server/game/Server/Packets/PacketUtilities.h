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
#include "Optional.h"
#include "Tuples.h"
#include <short_alloc/short_alloc.h>
#include <string_view>
#include <ctime>

namespace WorldPackets
{
    class InvalidStringValueException : public ByteBufferInvalidValueException
    {
    public:
        InvalidStringValueException(std::string_view value);

        std::string const& GetInvalidValue() const { return _value; }

    private:
        std::string _value;
    };

    class InvalidUtf8ValueException : public InvalidStringValueException
    {
    public:
        InvalidUtf8ValueException(std::string_view value);
    };

    class InvalidHyperlinkException : public InvalidStringValueException
    {
    public:
        InvalidHyperlinkException(std::string_view value);
    };

    class IllegalHyperlinkException : public InvalidStringValueException
    {
    public:
        IllegalHyperlinkException(std::string_view value);
    };

    namespace Strings
    {
        struct RawBytes { static bool Validate(std::string_view /*value*/) { return true; } };
        template<std::size_t MaxBytesWithoutNullTerminator>
        struct ByteSize { static bool Validate(std::string_view value) { return value.size() <= MaxBytesWithoutNullTerminator; } };
        struct Utf8 { static bool Validate(std::string_view value); };
        struct Hyperlinks { static bool Validate(std::string_view value); };
        struct NoHyperlinks { static bool Validate(std::string_view value); };
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
        std::size_t length() const { return _storage.length(); }
        char const* c_str() const { return _storage.c_str(); }

        operator std::string_view() const { return _storage; }
        operator std::string&() { return _storage; }
        operator std::string const&() const { return _storage; }

        std::string&& Move() { return std::move(_storage); }

        friend ByteBuffer& operator>>(ByteBuffer& data, String& value)
        {
            value = data.ReadCString(false);
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

        String& operator=(std::string_view value)
        {
            Validate(value);
            _storage = std::move(value);
            return *this;
        }

        String& operator=(char const* value)
        {
            return *this = std::string_view(value);
        }

    private:
        static bool Validate(std::string_view value)
        {
            return ValidateNth(value, std::make_index_sequence<std::tuple_size_v<ValidatorList>>{});
        }

        template<std::size_t... indexes>
        static bool ValidateNth(std::string_view value, std::index_sequence<indexes...>)
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
        using allocator_type = short_alloc::short_alloc<T, (N * sizeof(T) + (alignof(std::max_align_t) - 1)) & ~(alignof(std::max_align_t) - 1)>;
        using arena_type = typename allocator_type::arena_type;

        using storage_type = std::vector<T, allocator_type>;

        using max_capacity = std::integral_constant<std::size_t, N>;

        using value_type = typename storage_type::value_type;
        using size_type = typename storage_type::size_type;
        using pointer = typename storage_type::pointer;
        using const_pointer = typename storage_type::const_pointer;
        using reference = typename storage_type::reference;
        using const_reference = typename storage_type::const_reference;
        using iterator = typename storage_type::iterator;
        using const_iterator = typename storage_type::const_iterator;

        Array() : _storage(_data) { }

        Array(Array const& other) : Array()
        {
            for (T const& element : other)
                _storage.push_back(element);
        }

        Array(Array&& other) noexcept = delete;

        Array& operator=(Array const& other)
        {
            if (this == &other)
                return *this;

            _storage.clear();
            for (T const& element : other)
                _storage.push_back(element);

            return *this;
        }

        Array& operator=(Array&& other) noexcept = delete;

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

        iterator erase(const_iterator first, const_iterator last)
        {
            return _storage.erase(first, last);
        }

        void clear()
        {
            _storage.clear();
        }

    private:
        arena_type _data;
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

    template<typename Underlying, typename T>
    struct AsWriter
    {
        T const& Value;

        friend inline ByteBuffer& operator<<(ByteBuffer& data, AsWriter const& opt)
        {
            data << Underlying(opt.Value);
            return data;
        }
    };

    template<typename Underlying, typename T>
    struct AsReaderWriter : AsWriter<Underlying, T>
    {
        friend inline ByteBuffer& operator>>(ByteBuffer& data, AsReaderWriter const& opt)
        {
            Underlying temp;
            data >> temp;
            const_cast<T&>(opt.Value) = static_cast<T>(temp);
            return data;
        }
    };

    template<typename Underlying, typename T>
    inline AsWriter<Underlying, T> As(T const& value) { return { value }; }

    template<typename Underlying, typename T>
    inline AsReaderWriter<Underlying, T> As(T& value) { return { value }; }

    template<typename T>
    struct OptionalInitWriter
    {
        Optional<T> const& Opt;

        friend inline ByteBuffer& operator<<(ByteBuffer& data, OptionalInitWriter const& opt)
        {
            data.WriteBit(opt.Opt.has_value());
            return data;
        }
    };

    template<typename T>
    struct OptionalInitReaderWriter : OptionalInitWriter<T>
    {
        friend inline ByteBuffer& operator>>(ByteBuffer& data, OptionalInitReaderWriter const& opt)
        {
            if (data.ReadBit())
                const_cast<Optional<T>&>(opt.Opt).emplace();
            return data;
        }
    };

    template<typename T>
    inline OptionalInitWriter<T> OptionalInit(Optional<T> const& value) { return { value }; }

    template<typename T>
    inline OptionalInitReaderWriter<T> OptionalInit(Optional<T>& value) { return { value }; }

    template<uint32 BitCount, typename T>
    struct BitsWriter
    {
        T const& Value;

        friend inline ByteBuffer& operator<<(ByteBuffer& data, BitsWriter const& bits)
        {
            data.WriteBits(static_cast<uint32>(bits.Value), BitCount);
            return data;
        }
    };

    template<uint32 BitCount, typename T>
    struct BitsReaderWriter : BitsWriter<BitCount, T>
    {
        friend inline ByteBuffer& operator>>(ByteBuffer& data, BitsReaderWriter const& bits)
        {
            const_cast<T&>(bits.Value) = static_cast<T>(data.ReadBits(BitCount));
            return data;
        }
    };

    template<uint32 BitCount, typename T>
    inline BitsWriter<BitCount, T> Bits(T const& value) { return { value }; }

    template<uint32 BitCount, typename T>
    inline BitsReaderWriter<BitCount, T> Bits(T& value) { return { value }; }

    template<uint32 BitCount, typename Container>
    struct BitsSizeWriter
    {
        Container const& Value;

        friend inline ByteBuffer& operator<<(ByteBuffer& data, BitsSizeWriter const& bits)
        {
            data.WriteBits(static_cast<uint32>(bits.Value.size()), BitCount);
            return data;
        }
    };

    template<uint32 BitCount, typename Container>
    struct BitsSizeReaderWriter : BitsSizeWriter<BitCount, Container>
    {
        friend inline ByteBuffer& operator>>(ByteBuffer& data, BitsSizeReaderWriter const& bits)
        {
            const_cast<Container&>(bits.Value).resize(data.ReadBits(BitCount));
            return data;
        }
    };

    template<uint32 BitCount, typename Container>
    inline BitsSizeWriter<BitCount, Container> BitsSize(Container const& value) { return { value }; }

    template<uint32 BitCount, typename Container>
    inline BitsSizeReaderWriter<BitCount, Container> BitsSize(Container& value) { return { value }; }
}

#endif // PacketUtilities_h__
