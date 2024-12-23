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

#ifndef TRINITYCORE_BYTE_BUFFER_H
#define TRINITYCORE_BYTE_BUFFER_H

#include "Define.h"
#include "ByteConverter.h"
#include <array>
#include <string>
#include <vector>
#include <cstring>

class MessageBuffer;

// Root of ByteBuffer exception hierarchy
class TC_SHARED_API ByteBufferException : public std::exception
{
public:
    explicit ByteBufferException() = default;
    explicit ByteBufferException(std::string&& message) noexcept : msg_(std::move(message)) { }

    char const* what() const noexcept override { return msg_.c_str(); }

protected:
    std::string msg_;
};

class TC_SHARED_API ByteBufferPositionException : public ByteBufferException
{
public:
    ByteBufferPositionException(size_t pos, size_t size, size_t valueSize);
};

class TC_SHARED_API ByteBufferInvalidValueException : public ByteBufferException
{
public:
    ByteBufferInvalidValueException(char const* type, std::string_view value);
};

class TC_SHARED_API ByteBuffer
{
    public:
        constexpr static size_t DEFAULT_SIZE = 0x1000;
        constexpr static uint8 InitialBitPos = 8;

        // constructor
        ByteBuffer() : _rpos(0), _wpos(0), _bitpos(InitialBitPos), _curbitval(0)
        {
            _storage.reserve(DEFAULT_SIZE);
        }

        // reserve/resize tag
        struct Reserve { };
        struct Resize { };

        ByteBuffer(size_t size, Reserve) : _rpos(0), _wpos(0), _bitpos(InitialBitPos), _curbitval(0)
        {
            _storage.reserve(size);
        }

        ByteBuffer(size_t size, Resize) : _rpos(0), _wpos(size), _bitpos(InitialBitPos), _curbitval(0)
        {
            _storage.resize(size);
        }

        ByteBuffer(ByteBuffer&& buf) noexcept : _rpos(buf._rpos), _wpos(buf._wpos),
            _bitpos(buf._bitpos), _curbitval(buf._curbitval), _storage(buf.Move()) { }

        ByteBuffer(ByteBuffer const& right) = default;

        ByteBuffer(MessageBuffer&& buffer);

        std::vector<uint8>&& Move() noexcept
        {
            _rpos = 0;
            _wpos = 0;
            _bitpos = InitialBitPos;
            _curbitval = 0;
            return std::move(_storage);
        }

        ByteBuffer& operator=(ByteBuffer const& right)
        {
            if (this != &right)
            {
                _rpos = right._rpos;
                _wpos = right._wpos;
                _bitpos = right._bitpos;
                _curbitval = right._curbitval;
                _storage = right._storage;
            }

            return *this;
        }

        ByteBuffer& operator=(ByteBuffer&& right) noexcept
        {
            if (this != &right)
            {
                _rpos = right._rpos;
                _wpos = right._wpos;
                _bitpos = right._bitpos;
                _curbitval = right._curbitval;
                _storage = right.Move();
            }

            return *this;
        }

        virtual ~ByteBuffer() = default;

        void clear()
        {
            _rpos = 0;
            _wpos = 0;
            _bitpos = InitialBitPos;
            _curbitval = 0;
            _storage.clear();
        }

        template <typename T>
        void append(T value)
        {
            static_assert(std::is_trivially_copyable_v<T>, "append(T) must be used with trivially copyable types");
            EndianConvert(value);
            append(reinterpret_cast<uint8 const*>(&value), sizeof(value));
        }

        bool HasUnfinishedBitPack() const
        {
            return _bitpos != 8;
        }

        void FlushBits()
        {
            if (_bitpos == 8)
                return;

            _bitpos = 8;

            append(&_curbitval, sizeof(uint8));
            _curbitval = 0;
        }

        void ResetBitPos()
        {
            if (_bitpos > 7)
                return;

            _bitpos = 8;
            _curbitval = 0;
        }

        bool WriteBit(bool bit)
        {
            --_bitpos;
            if (bit)
                _curbitval |= (1 << (_bitpos));

            if (_bitpos == 0)
            {
                _bitpos = 8;
                append(&_curbitval, sizeof(_curbitval));
                _curbitval = 0;
            }

            return bit;
        }

        bool ReadBit()
        {
            ++_bitpos;
            if (_bitpos > 7)
            {
                _curbitval = read<uint8>();
                _bitpos = 0;
            }

            return ((_curbitval >> (7 - _bitpos)) & 1) != 0;
        }

        void WriteBits(uint64 value, int32 bits)
        {
            // remove bits that don't fit
            value &= (UI64LIT(1) << bits) - 1;

            if (bits > int32(_bitpos))
            {
                // first write to fill bit buffer
                _curbitval |= value >> (bits - _bitpos);
                bits -= _bitpos;
                _bitpos = 8; // required "unneccessary" write to avoid double flushing
                append(&_curbitval, sizeof(_curbitval));

                // then append as many full bytes as possible
                while (bits >= 8)
                {
                    bits -= 8;
                    append<uint8>(value >> bits);
                }

                // store remaining bits in the bit buffer
                _bitpos = 8 - bits;
                _curbitval = (value & ((UI64LIT(1) << bits) - 1)) << _bitpos;
            }
            else
            {
                // entire value fits in the bit buffer
                _bitpos -= bits;
                _curbitval |= value << _bitpos;

                if (_bitpos == 0)
                {
                    _bitpos = 8;
                    append(&_curbitval, sizeof(_curbitval));
                    _curbitval = 0;
                }
            }
        }

        uint32 ReadBits(int32 bits)
        {
            uint32 value = 0;
            for (int32 i = bits - 1; i >= 0; --i)
                value |= uint32(ReadBit()) << i;

            return value;
        }

        template <typename T>
        void put(std::size_t pos, T value)
        {
            static_assert(std::is_trivially_copyable_v<T>, "put(size_t, T) must be used with trivially copyable types");
            EndianConvert(value);
            put(pos, reinterpret_cast<uint8 const*>(&value), sizeof(value));
        }

        /**
          * @name   PutBits
          * @brief  Places specified amount of bits of value at specified position in packet.
          *         To ensure all bits are correctly written, only call this method after
          *         bit flush has been performed

          * @param  pos Position to place the value at, in bits. The entire value must fit in the packet
          *             It is advised to obtain the position using bitwpos() function.

          * @param  value Data to write.
          * @param  bitCount Number of bits to store the value on.
        */
        void PutBits(std::size_t pos, std::size_t value, uint32 bitCount);

        ByteBuffer& operator<<(uint8 value)
        {
            append<uint8>(value);
            return *this;
        }

        ByteBuffer& operator<<(uint16 value)
        {
            append<uint16>(value);
            return *this;
        }

        ByteBuffer& operator<<(uint32 value)
        {
            append<uint32>(value);
            return *this;
        }

        ByteBuffer& operator<<(uint64 value)
        {
            append<uint64>(value);
            return *this;
        }

        // signed as in 2e complement
        ByteBuffer& operator<<(int8 value)
        {
            append<int8>(value);
            return *this;
        }

        ByteBuffer& operator<<(int16 value)
        {
            append<int16>(value);
            return *this;
        }

        ByteBuffer& operator<<(int32 value)
        {
            append<int32>(value);
            return *this;
        }

        ByteBuffer& operator<<(int64 value)
        {
            append<int64>(value);
            return *this;
        }

        // floating points
        ByteBuffer& operator<<(float value)
        {
            append<float>(value);
            return *this;
        }

        ByteBuffer& operator<<(double value)
        {
            append<double>(value);
            return *this;
        }

        ByteBuffer& operator<<(std::string_view value)
        {
            if (size_t len = value.length())
                append(reinterpret_cast<uint8 const*>(value.data()), len);
            append(static_cast<uint8>(0));
            return *this;
        }

        ByteBuffer& operator<<(std::string const& str)
        {
            return operator<<(std::string_view(str));
        }

        ByteBuffer& operator<<(char const* str)
        {
            return operator<<(std::string_view(str ? str : ""));
        }

        ByteBuffer& operator>>(bool& value)
        {
            value = read<char>() > 0;
            return *this;
        }

        ByteBuffer& operator>>(uint8& value)
        {
            read(&value, 1);
            return *this;
        }

        ByteBuffer& operator>>(uint16& value)
        {
            read(&value, 1);
            return *this;
        }

        ByteBuffer& operator>>(uint32& value)
        {
            read(&value, 1);
            return *this;
        }

        ByteBuffer& operator>>(uint64& value)
        {
            read(&value, 1);
            return *this;
        }

        //signed as in 2e complement
        ByteBuffer& operator>>(int8& value)
        {
            read(&value, 1);
            return *this;
        }

        ByteBuffer& operator>>(int16& value)
        {
            read(&value, 1);
            return *this;
        }

        ByteBuffer& operator>>(int32& value)
        {
            read(&value, 1);
            return *this;
        }

        ByteBuffer& operator>>(int64& value)
        {
            read(&value, 1);
            return *this;
        }

        ByteBuffer& operator>>(float& value);
        ByteBuffer& operator>>(double& value);

        ByteBuffer& operator>>(std::string& value)
        {
            value = ReadCString(true);
            return *this;
        }

        uint8& operator[](size_t const pos)
        {
            if (pos >= size())
                throw ByteBufferPositionException(pos, 1, size());
            return _storage[pos];
        }

        uint8 const& operator[](size_t const pos) const
        {
            if (pos >= size())
                throw ByteBufferPositionException(pos, 1, size());
            return _storage[pos];
        }

        size_t rpos() const { return _rpos; }

        size_t rpos(size_t rpos_)
        {
            _rpos = rpos_;
            return _rpos;
        }

        void rfinish()
        {
            _rpos = wpos();
        }

        size_t wpos() const { return _wpos; }

        size_t wpos(size_t wpos_)
        {
            _wpos = wpos_;
            return _wpos;
        }

        /// Returns position of last written bit
        size_t bitwpos() const { return _wpos * 8 + 8 - _bitpos; }

        size_t bitwpos(size_t newPos)
        {
            _wpos = newPos / 8;
            _bitpos = 8 - (newPos % 8);
            return _wpos * 8 + 8 - _bitpos;
        }

        template <typename T>
        void read_skip() { read_skip(sizeof(T)); }

        void read_skip(size_t skip)
        {
            if (_rpos + skip > size())
                throw ByteBufferPositionException(_rpos, skip, size());

            ResetBitPos();
            _rpos += skip;
        }

        template <typename T>
        T read()
        {
            ResetBitPos();
            T r = read<T>(_rpos);
            _rpos += sizeof(T);
            return r;
        }

        template <typename T>
        T read(size_t pos) const
        {
            if (pos + sizeof(T) > size())
                throw ByteBufferPositionException(pos, sizeof(T), size());
            T val;
            std::memcpy(&val, &_storage[pos], sizeof(T));
            EndianConvert(val);
            return val;
        }

        template <typename T>
        void read(T* dest, size_t count)
        {
            static_assert(std::is_trivially_copyable_v<T>, "read(T*, size_t) must be used with trivially copyable types");
            read(reinterpret_cast<uint8*>(dest), count * sizeof(T));
#if TRINITY_ENDIAN == TRINITY_BIGENDIAN
            for (size_t i = 0; i < count; ++i)
                EndianConvert(dest[i]);
#endif
        }

        void read(uint8* dest, size_t len)
        {
            if (_rpos + len > size())
                throw ByteBufferPositionException(_rpos, len, size());

            ResetBitPos();
            std::memcpy(dest, &_storage[_rpos], len);
            _rpos += len;
        }

        template <size_t Size>
        void read(std::array<uint8, Size>& arr)
        {
            read(arr.data(), Size);
        }

        void ReadPackedUInt64(uint64& guid)
        {
            guid = 0;
            ReadPackedUInt64(read<uint8>(), guid);
        }

        void ReadPackedUInt64(uint8 mask, uint64& value)
        {
            for (uint32 i = 0; i < 8; ++i)
                if (mask & (uint8(1) << i))
                    value |= (uint64(read<uint8>()) << (i * 8));
        }

        //! Method for writing strings that have their length sent separately in packet
        //! without null-terminating the string
        void WriteString(std::string const& str)
        {
            if (size_t len = str.length())
                append(str.c_str(), len);
        }

        void WriteString(std::string_view str)
        {
            if (size_t len = str.length())
                append(str.data(), len);
        }

        void WriteString(char const* str, size_t len)
        {
            if (len)
                append(str, len);
        }

        std::string_view ReadCString(bool requireValidUtf8 = true);

        std::string_view ReadString(uint32 length, bool requireValidUtf8 = true);

        uint8* contents()
        {
            if (_storage.empty())
                throw ByteBufferException();
            return _storage.data();
        }

        uint8 const* contents() const
        {
            if (_storage.empty())
                throw ByteBufferException();
            return _storage.data();
        }

        size_t size() const { return _storage.size(); }
        bool empty() const { return _storage.empty(); }

        void resize(size_t newsize)
        {
            _storage.resize(newsize, 0);
            _rpos = 0;
            _wpos = size();
        }

        void reserve(size_t ressize)
        {
            if (ressize > size())
                _storage.reserve(ressize);
        }

        void shrink_to_fit()
        {
            _storage.shrink_to_fit();
        }

        template <typename T>
        void append(T const* src, size_t cnt)
        {
#if TRINITY_ENDIAN == TRINITY_LITTLEENDIAN
            append(reinterpret_cast<uint8 const*>(src), cnt * sizeof(T));
#else
            for (size_t i = 0; i < cnt; ++i)
                append<T>(src[i]);
#endif
        }

        void append(uint8 const* src, size_t cnt);

        void append(ByteBuffer const& buffer)
        {
            if (!buffer.empty())
                append(buffer.contents(), buffer.size());
        }

        template <size_t Size>
        void append(std::array<uint8, Size> const& arr)
        {
            append(arr.data(), Size);
        }

        // can be used in SMSG_MONSTER_MOVE opcode
        void appendPackXYZ(float x, float y, float z)
        {
            uint32 packed = 0;
            packed |= ((int)(x / 0.25f) & 0x7FF);
            packed |= ((int)(y / 0.25f) & 0x7FF) << 11;
            packed |= ((int)(z / 0.25f) & 0x3FF) << 22;
            *this << packed;
        }

        void AppendPackedUInt64(uint64 guid)
        {
            uint8 mask = 0;
            size_t pos = wpos();
            *this << uint8(mask);

            uint8 packed[8];
            if (size_t packedSize = PackUInt64(guid, &mask, packed))
                append(packed, packedSize);

            put<uint8>(pos, mask);
        }

        static size_t PackUInt64(uint64 value, uint8* mask, uint8* result)
        {
            size_t resultSize = 0;
            *mask = 0;
            memset(result, 0, 8);

            for (uint8 i = 0; value != 0; ++i)
            {
                if (value & 0xFF)
                {
                    *mask |= uint8(1 << i);
                    result[resultSize++] = uint8(value & 0xFF);
                }

                value >>= 8;
            }

            return resultSize;
        }

        void put(size_t pos, uint8 const* src, size_t cnt);

        void print_storage() const;

        void textlike() const;

        void hexlike() const;

    protected:
        size_t _rpos, _wpos;
        uint8 _bitpos;
        uint8 _curbitval;
        std::vector<uint8> _storage;
};

/// @todo Make a ByteBuffer.cpp and move all this inlining to it.
template <> inline std::string ByteBuffer::read<std::string>()
{
    return std::string(ReadCString());
}

template <>
inline void ByteBuffer::read_skip<char*>()
{
    (void)ReadCString();
}

template <>
inline void ByteBuffer::read_skip<char const*>()
{
    read_skip<char*>();
}

template <>
inline void ByteBuffer::read_skip<std::string>()
{
    read_skip<char*>();
}

#endif
