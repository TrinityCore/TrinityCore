/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#ifndef __BATTLENETBITSTREAM_H__
#define __BATTLENETBITSTREAM_H__

#include "ByteConverter.h"
#include "Common.h"
#include <exception>
#include <vector>
#include <type_traits>
#include <memory>

namespace Battlenet
{
    class BitStreamPositionException : public std::exception
    {
        static uint32 const MessageSize = 128;

    public:
        BitStreamPositionException(bool read, uint32 operationSize, uint32 position, uint32 streamSize)
        {
            memset(_message, 0, MessageSize);
            snprintf(_message, MessageSize, "Attempted to %s more bits (%u) %s stream than %s (%u)\n",
                (read ? "read" : "write"),
                operationSize + position,
                (read ? "from" : "to"),
                (read ? "exist" : "allowed"),
                streamSize);
        }

        char const* what() const throw()
        {
            return _message;
        }

    private:
        char _message[MessageSize];
    };

    class BitStream
    {
    public:
        static uint32 const MaxSize = 0x4000;

        // length : The maximum number of bytes to read
        BitStream(uint32 length) : _numBits(length * 8), _readPos(0), _writePos(0)
        {
            _buffer.resize(length, 0);
        }

        BitStream() : _numBits(0), _readPos(0), _writePos(0)
        {
            _buffer.reserve(0x1000);
        }

        void AlignToNextByte()
        {
            _readPos = (_readPos + 7) & ~7;
            _writePos = (_writePos + 7) & ~7;
        }

        std::string ReadString(uint32 bitCount, int32 baseLength = 0)
        {
            uint32 len = Read<uint32>(bitCount) + baseLength;
            AlignToNextByte();
            std::string str(reinterpret_cast<char*>(&_buffer[_readPos >> 3]), len);
            _readPos += len * 8;
            return str;
        }

        std::unique_ptr<uint8[]> ReadBytes(uint32 count)
        {
            AlignToNextByte();
            if (_readPos + count * 8 > _numBits)
                throw BitStreamPositionException(true, count * 8, _readPos, _numBits);

            std::unique_ptr<uint8[]> buf(new uint8[count]);
            memcpy(buf.get(), &_buffer[_readPos >> 3], count);
            _readPos += count * 8;
            return buf;
        }

        float ReadFloat()
        {
            uint32 val = Read<uint32>(32);
            return *reinterpret_cast<float*>(&val);
        }

        std::string ReadFourCC()
        {
            uint32 fcc = Read<uint32>(32);
            EndianConvertReverse(fcc);
            size_t len = 4;
            while (!(fcc & 0xFF))
            {
                fcc >>= 8;
                --len;
            }

            return std::string(reinterpret_cast<char*>(&fcc), len);
        }

        template<typename T>
        T Read(uint32 bitCount)
        {
            static_assert(std::is_integral<T>::value || std::is_enum<T>::value, "T must be an integer type");

            if (_readPos + bitCount >= _numBits)
                throw BitStreamPositionException(true, bitCount, _readPos, _numBits);

            uint64 ret = 0;
            while (bitCount != 0)
            {
                uint32 bitPos = (_readPos & 7);
                uint32 bitsLeftInByte = 8 - bitPos;
                if (bitsLeftInByte >= bitCount)
                    bitsLeftInByte = bitCount;

                bitCount -= bitsLeftInByte;
                ret |= (uint64)(_buffer[_readPos >> 3] >> bitPos & (uint32)((uint8)(1 << bitsLeftInByte) - 1)) << bitCount;
                _readPos += bitsLeftInByte;
            }

            return static_cast<T>(ret);
        }

        void WriteString(std::string const& str, uint32 bitCount, int32 baseLength = 0)
        {
            Write(str.length() + baseLength, bitCount);
            WriteBytes(str.c_str(), str.length());
        }

        template<typename T>
        void WriteBytes(T* data, uint32 count)
        {
            AlignToNextByte();
            if (!count || !data)
                return;

            if ((_writePos >> 3) + count > MaxSize)
                throw BitStreamPositionException(false, count * 8, _writePos, MaxSize * 8);

            _buffer.resize(_buffer.size() + count);
            memcpy(&_buffer[_writePos >> 3], data, count);
            _writePos += count * 8;
        }

        void WriteFloat(float value)
        {
            uint32 intVal = *reinterpret_cast<uint32*>(&value);
            Write(intVal, 32);
        }

        void WriteFourCC(std::string const& fcc)
        {
            uint32 intVal = *(uint32*)fcc.c_str();
            size_t len = fcc.length();
            EndianConvertReverse(intVal);
            // Add padding
            while (len++ < 4)
                intVal >>= 8;

            Write(intVal, 32);
        }

        template<typename T>
        void Write(T value, uint32 bitCount)
        {
            static_assert(std::is_integral<T>::value || std::is_enum<T>::value, "T must be an integer type");

            if (_writePos + bitCount >= 8 * MaxSize)
                throw BitStreamPositionException(false, bitCount, _writePos, MaxSize * 8);

            while (bitCount != 0)
            {
                uint32 bitPos = (_writePos & 7);
                uint32 bitsLeftInByte = 8 - bitPos;
                if (bitsLeftInByte >= bitCount)
                    bitsLeftInByte = bitCount;

                bitCount -= bitsLeftInByte;

                uint8 firstHalf = (uint8)(~(((uint8)(1 << bitsLeftInByte) - 1) << bitPos));
                uint8 secondHalf = (uint8)((((uint8)(1 << bitsLeftInByte) - 1) & (uint8)(value >> bitCount)) << bitPos);

                if (_buffer.size() > (_writePos >> 3))
                    _buffer[_writePos >> 3] = (uint8)((_buffer[_writePos >> 3] & firstHalf) | secondHalf);
                else
                    _buffer.push_back(secondHalf);

                _writePos += bitsLeftInByte;
            }
        }

        void SetReadPos(uint32 bits)
        {
            if (bits >= _numBits)
                throw BitStreamPositionException(true, bits, 0, _numBits);

            _readPos = bits;
        }

        bool IsRead() const { return _readPos >= _numBits; }

        uint8* GetBuffer() { return _buffer.data(); }
        uint8 const* GetBuffer() const { return _buffer.data(); }

        size_t GetSize() const { return _buffer.size(); }

        void FinishReading() { _readPos = _numBits; }

    private:
        std::vector<uint8> _buffer;
        uint32 _numBits;
        uint32 _readPos;
        uint32 _writePos;
    };

    template<>
    bool BitStream::Read<bool>(uint32 bitCount);
}

#endif // __BATTLENETBITSTREAM_H__
