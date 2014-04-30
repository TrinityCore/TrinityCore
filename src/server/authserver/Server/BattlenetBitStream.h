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
#include <exception>
#include <string>
#include <vector>

namespace Battlenet
{
    class BitStreamPositionException : public std::exception
    {
    public:
        char const* what() const
        {
            return "";
        }
    };

    class BitStream
    {
    public:
        static uint32 const MaxSize = 0x1000;

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

        std::string ReadString(uint32 bitCount, uint32 baseLength = 0)
        {
            uint32 len = Read<uint32>(bitCount) + baseLength;
            AlignToNextByte();
            std::string str(reinterpret_cast<char*>(&_buffer[_readPos >> 3]), len);
            _readPos += len * 8;
            return str;
        }

        uint8* ReadBytes(uint32 count)
        {
            AlignToNextByte();
            if (_readPos + count * 8 > _numBits)
                throw BitStreamPositionException();

            uint8* buf = new uint8[count];
            memcpy(buf, &_buffer[_readPos >> 3], count);
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
            T ret = 0;
            while (bitCount != 0)
            {
                uint32 bitPos = (_readPos & 7);
                uint32 bitsLeftInByte = 8 - bitPos;
                if (bitsLeftInByte >= bitCount)
                    bitsLeftInByte = bitCount;

                bitCount -= bitsLeftInByte;
                ret |= static_cast<T>((uint64)(_buffer[_readPos >> 3] >> bitPos & (uint32)((uint8)(1 << bitsLeftInByte) - 1)) << bitCount);
                _readPos += bitsLeftInByte;
            }
            return ret;
        }

        //WriteString

        template<typename T>
        void WriteBytes(T* data, uint32 count)
        {
            AlignToNextByte();
            if (_writePos + 8 * count > MaxSize)
                throw BitStreamPositionException();

            _buffer.resize(_buffer.size() + count);
            memcpy(&_buffer[_writePos >> 3], data, count);
            _writePos += count * 8;
        }

        //WriteFloat
        void WriteFourCC(char const* fcc)
        {
            uint32 intVal = *(uint32*)fcc;
            EndianConvertReverse(intVal);
            Write(intVal, 32);
        }

        template<typename T>
        void Write(T value, uint32 bitCount)
        {
            if (_writePos + bitCount >= 8 * MaxSize)
                throw BitStreamPositionException();

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
                    _buffer[_writePos >> 3] = (uint8)(_buffer[_writePos >> 3] & firstHalf | secondHalf);
                else
                    _buffer.push_back(secondHalf);

                _writePos += bitsLeftInByte;
            }
        }

        void SetReadPos(uint32 bits)
        {
            if (bits >= _numBits)
                throw BitStreamPositionException();

            _readPos = bits;
        }

        bool IsRead() const { return _readPos >= _numBits; }

        uint8* GetBuffer() { return _buffer.data(); }

        size_t GetSize() const { return _buffer.size(); }

    private:
        std::vector<uint8> _buffer;
        uint32 _numBits;
        uint32 _readPos;
        uint32 _writePos;
    };
}

#endif // __BATTLENETBITSTREAM_H__
