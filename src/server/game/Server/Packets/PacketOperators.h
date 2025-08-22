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

#ifndef TRINITYCORE_PACKET_OPERATORS_H
#define TRINITYCORE_PACKET_OPERATORS_H

#include "ByteBuffer.h"
#include "Optional.h"
#include <memory>

namespace WorldPackets
{
    namespace Strings
    {
        enum Utf8Mode : uint8
        {
            DontValidateUtf8,
            ValidUtf8
        };
    }

    template<typename T>
    concept AsWritable = std::is_default_constructible_v<T> && HasByteBufferShiftOperators<T>;

    template<typename T, typename Underlying>
    concept AsWritableFor = requires { static_cast<Underlying>(std::declval<T>()); }
                         && requires { static_cast<T>(Underlying()); };

    template<AsWritable Underlying, AsWritableFor<Underlying> T>
    struct AsWriter
    {
        T const& Value;

        friend inline ByteBuffer& operator<<(ByteBuffer& data, AsWriter const& opt)
        {
            data << static_cast<Underlying>(opt.Value);
            return data;
        }
    };

    template<AsWritable Underlying, AsWritableFor<Underlying> T>
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

    template<AsWritable Underlying, AsWritableFor<Underlying> T>
    inline AsWriter<Underlying, T> As(T const& value) { return { value }; }

    template<AsWritable Underlying, AsWritableFor<Underlying> T>
    inline AsReaderWriter<Underlying, T> As(T& value) { return { value }; }

    template<typename T>
    concept OptionalWritable = std::is_default_constructible_v<T>;

    template<OptionalWritable T>
    struct OptionalInitWriter
    {
        Optional<T> const& Opt;

        friend inline ByteBuffer& operator<<(ByteBuffer& data, OptionalInitWriter const& opt)
        {
            data.WriteBit(opt.Opt.has_value());
            return data;
        }
    };

    template<OptionalWritable T>
    struct OptionalInitReaderWriter : OptionalInitWriter<T>
    {
        friend inline ByteBuffer& operator>>(ByteBuffer& data, OptionalInitReaderWriter const& opt)
        {
            if (data.ReadBit())
                const_cast<Optional<T>&>(opt.Opt).emplace();
            return data;
        }
    };

    template<OptionalWritable T>
    inline OptionalInitWriter<T> OptionalInit(Optional<T> const& value) { return { value }; }

    template<OptionalWritable T>
    inline OptionalInitReaderWriter<T> OptionalInit(Optional<T>& value) { return { value }; }

    template<OptionalWritable T>
    struct PtrInitWriter
    {
        std::unique_ptr<T> const& Ptr;

        friend inline ByteBuffer& operator<<(ByteBuffer& data, PtrInitWriter const& opt)
        {
            data.WriteBit(opt.Ptr != nullptr);
            return data;
        }
    };

    template<OptionalWritable T>
    struct PtrInitReaderWriter : PtrInitWriter<T>
    {
        friend inline ByteBuffer& operator>>(ByteBuffer& data, PtrInitReaderWriter const& opt)
        {
            if (data.ReadBit())
                const_cast<std::unique_ptr<T>&>(opt.Ptr) = std::make_unique<T>();
            return data;
        }
    };

    template<OptionalWritable T>
    inline PtrInitWriter<T> OptionalInit(std::unique_ptr<T> const& value) { return { value }; }

    template<OptionalWritable T>
    inline PtrInitReaderWriter<T> OptionalInit(std::unique_ptr<T>& value) { return { value }; }

    template<typename T>
    concept BitsWritable = AsWritableFor<T, uint32>;

    template<uint32 BitCount, BitsWritable T>
    struct BitsWriter
    {
        T const& Value;

        friend inline ByteBuffer& operator<<(ByteBuffer& data, BitsWriter const& bits)
        {
            if constexpr (BitCount != 1)
                data.WriteBits(static_cast<uint32>(bits.Value), BitCount);
            else
                data.WriteBit(static_cast<uint32>(bits.Value) != 0);

            return data;
        }
    };

    template<uint32 BitCount, BitsWritable T>
    struct BitsReaderWriter : BitsWriter<BitCount, T>
    {
        friend inline ByteBuffer& operator>>(ByteBuffer& data, BitsReaderWriter const& bits)
        {
            if constexpr (BitCount != 1)
                const_cast<T&>(bits.Value) = static_cast<T>(data.ReadBits(BitCount));
            else
                const_cast<T&>(bits.Value) = static_cast<T>(data.ReadBit() ? 1 : 0);

            return data;
        }
    };

    template<uint32 BitCount, BitsWritable T>
    inline BitsWriter<BitCount, T> Bits(T const& value) { return { value }; }

    template<uint32 BitCount, BitsWritable T>
    inline BitsReaderWriter<BitCount, T> Bits(T& value) { return { value }; }

    template<typename T, typename SizeType>
    concept ContainerWritable = requires(T const& container) { { container.size() } -> AsWritableFor<SizeType>; }
                             && !std::same_as<T, std::string_view>
                             && !std::same_as<T, std::string>;

    template<typename T, typename SizeType>
    concept ContainerReadable = ContainerWritable<T, SizeType>
                             && !std::is_const_v<T>
                             && requires(T & container) { container.resize(SizeType{}); };

    template<AsWritable Underlying, ContainerWritable<Underlying> Container>
    struct SizeWriter
    {
        Container const& Value;

        friend inline ByteBuffer& operator<<(ByteBuffer& data, SizeWriter const& size)
        {
            data << static_cast<Underlying>(size.Value.size());
            return data;
        }
    };

    template<AsWritable Underlying, ContainerReadable<Underlying> Container>
    struct SizeReaderWriter : SizeWriter<Underlying, Container>
    {
        friend inline ByteBuffer& operator>>(ByteBuffer& data, SizeReaderWriter const& size)
        {
            Underlying temp;
            data >> temp;
            const_cast<Container&>(size.Value).resize(temp);
            return data;
        }
    };

    template<AsWritable Underlying, ContainerWritable<Underlying> Container>
    inline SizeWriter<Underlying, Container> Size(Container const& value) { return { value }; }

    template<AsWritable Underlying, ContainerReadable<Underlying> Container>
    inline SizeReaderWriter<Underlying, Container> Size(Container& value) { return { value }; }

    template<uint32 BitCount, ContainerWritable<uint32> Container>
    struct BitsSizeWriter
    {
        Container const& Value;

        friend inline ByteBuffer& operator<<(ByteBuffer& data, BitsSizeWriter const& bits)
        {
            data.WriteBits(static_cast<uint32>(bits.Value.size()), BitCount);
            return data;
        }
    };

    template<uint32 BitCount, ContainerReadable<uint32> Container>
    struct BitsSizeReaderWriter : BitsSizeWriter<BitCount, Container>
    {
        friend inline ByteBuffer& operator>>(ByteBuffer& data, BitsSizeReaderWriter const& bits)
        {
            const_cast<Container&>(bits.Value).resize(data.ReadBits(BitCount));
            return data;
        }
    };

    template<uint32 BitCount, ContainerWritable<uint32> Container>
    inline BitsSizeWriter<BitCount, Container> BitsSize(Container const& value) { return { value }; }

    template<uint32 BitCount, ContainerReadable<uint32> Container>
    inline BitsSizeReaderWriter<BitCount, Container> BitsSize(Container& value) { return { value }; }

    template<typename T>
    concept StringWritable = requires(T const& container) { { container.length() } -> AsWritableFor<uint32>; }
                          && requires(ByteBuffer& data, T const& string) { data.WriteString(static_cast<std::string_view>(string)); /*TODO: Kill String class and remove the cast*/ };

    template<typename T>
    concept StringReadable = StringWritable<T>
                          && !std::is_const_v<T>
                          && !std::same_as<T, std::string_view>
                          && requires(T& container) { container.resize(uint32()); }
                          && requires(ByteBuffer& data, T& string) { string = data.ReadString(uint32(), bool()); };

    namespace SizedString
    {
        template<uint32 BitCount, StringWritable Container>
        struct SizeWriter
        {
            Container const& Value;

            friend inline ByteBuffer& operator<<(ByteBuffer& data, SizeWriter const& bits)
            {
                data.WriteBits(static_cast<uint32>(bits.Value.length()), BitCount);
                return data;
            }
        };

        template<uint32 BitCount, StringReadable Container>
        struct SizeReaderWriter : SizeWriter<BitCount, Container>
        {
            friend inline ByteBuffer& operator>>(ByteBuffer& data, SizeReaderWriter const& bits)
            {
                const_cast<Container&>(bits.Value).resize(data.ReadBits(BitCount));
                return data;
            }
        };

        template<uint32 BitCount, StringWritable Container>
        inline SizeWriter<BitCount, Container> BitsSize(Container const& value) { return { value }; }

        template<uint32 BitCount, StringReadable Container>
        inline SizeReaderWriter<BitCount, Container> BitsSize(Container& value) { return { value }; }

        template<StringWritable Container>
        struct DataWriter
        {
            Container const& Value;

            friend inline ByteBuffer& operator<<(ByteBuffer& data, DataWriter const& string)
            {
                data.WriteString(string.Value);
                return data;
            }
        };

        template<StringReadable Container, Strings::Utf8Mode Mode>
        struct DataReaderWriter : DataWriter<Container>
        {
            static constexpr bool IsUtf8() { return Mode == Strings::ValidUtf8; }

            friend inline ByteBuffer& operator>>(ByteBuffer& data, DataReaderWriter const& string)
            {
                const_cast<Container&>(string.Value) = data.ReadString(string.Value.length(), IsUtf8());
                return data;
            }
        };

        template<Strings::Utf8Mode = Strings::ValidUtf8, StringWritable Container>
        inline DataWriter<Container> Data(Container const& value) { return { value }; }

        template<Strings::Utf8Mode Mode = Strings::ValidUtf8, StringReadable Container>
        inline DataReaderWriter<Container, Mode> Data(Container& value) { return { value }; }
    }

    // SizedCString (sends size + string + null terminator but only if not empty)
    namespace SizedCString
    {
        template<uint32 BitCount, StringWritable Container>
        struct SizeWriter
        {
            Container const& Value;

            friend inline ByteBuffer& operator<<(ByteBuffer& data, SizeWriter const& bits)
            {
                data.WriteBits(static_cast<uint32>(bits.Value.length() + 1), BitCount);
                return data;
            }
        };

        template<uint32 BitCount, StringReadable Container>
        struct SizeReaderWriter : SizeWriter<BitCount, Container>
        {
            friend inline ByteBuffer& operator>>(ByteBuffer& data, SizeReaderWriter const& bits)
            {
                if (uint32 bytesIncludingNullTerminator = data.ReadBits(BitCount); bytesIncludingNullTerminator > 1)
                    const_cast<Container&>(bits.Value).resize(bytesIncludingNullTerminator - 1);
                return data;
            }
        };

        template<uint32 BitCount, StringWritable Container>
        inline SizeWriter<BitCount, Container> BitsSize(Container const& value) { return { value }; }

        template<uint32 BitCount, StringReadable Container>
        inline SizeReaderWriter<BitCount, Container> BitsSize(Container& value) { return { value }; }

        template<StringWritable Container>
        struct DataWriter
        {
            Container const& Value;

            friend inline ByteBuffer& operator<<(ByteBuffer& data, DataWriter const& string)
            {
                if (!string.Value.empty())
                {
                    data.WriteString(string.Value);
                    data << char('\0');
                }
                return data;
            }
        };

        template<StringReadable Container, Strings::Utf8Mode Mode>
        struct DataReaderWriter : DataWriter<Container>
        {
            static constexpr bool IsUtf8() { return Mode == Strings::ValidUtf8; }

            friend inline ByteBuffer& operator>>(ByteBuffer& data, DataReaderWriter const& string)
            {
                if (!string.Value.empty())
                {
                    const_cast<Container&>(string.Value) = data.ReadString(string.Value.length(), IsUtf8());
                    (void)data.read<char>(); // null terminator
                }
                return data;
            }
        };

        template<Strings::Utf8Mode = Strings::ValidUtf8, StringWritable Container>
        inline DataWriter<Container> Data(Container const& value) { return { value }; }

        template<Strings::Utf8Mode Mode = Strings::ValidUtf8, StringReadable Container>
        inline DataReaderWriter<Container, Mode> Data(Container& value) { return { value }; }
    }
}

#endif // TRINITYCORE_PACKET_OPERATORS_H
