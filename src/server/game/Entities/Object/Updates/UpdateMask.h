/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef __UPDATEMASK_H
#define __UPDATEMASK_H

#include "UpdateFields.h"
#include "Errors.h"
#include "ByteBuffer.h"

class UpdateMask
{
    public:
        /// Type representing how client reads update mask
        typedef uint32 ClientUpdateMaskType;

        enum UpdateMaskCount
        {
            CLIENT_UPDATE_MASK_BITS = sizeof(ClientUpdateMaskType) * 8,
        };

        UpdateMask() : _fieldCount(0), _blockCount(0), _bits(NULL) { }

        UpdateMask(UpdateMask const& right) : _bits(NULL)
        {
            SetCount(right.GetCount());
            memcpy(_bits, right._bits, sizeof(uint8) * _blockCount * 32);
        }

        ~UpdateMask() { delete[] _bits; }

        void SetBit(uint32 index) { _bits[index] = 1; }
        void UnsetBit(uint32 index) { _bits[index] = 0; }
        bool GetBit(uint32 index) const { return _bits[index] != 0; }

        void AppendToPacket(ByteBuffer* data)
        {
            for (uint32 i = 0; i < GetBlockCount(); ++i)
            {
                ClientUpdateMaskType maskPart = 0;
                for (uint32 j = 0; j < CLIENT_UPDATE_MASK_BITS; ++j)
                    if (_bits[CLIENT_UPDATE_MASK_BITS * i + j])
                        maskPart |= 1 << j;

                *data << maskPart;
            }
        }

        uint32 GetBlockCount() const { return _blockCount; }
        uint32 GetCount() const { return _fieldCount; }

        void SetCount(uint32 valuesCount)
        {
            delete[] _bits;

            _fieldCount = valuesCount;
            _blockCount = (valuesCount + CLIENT_UPDATE_MASK_BITS - 1) / CLIENT_UPDATE_MASK_BITS;

            _bits = new uint8[_blockCount * CLIENT_UPDATE_MASK_BITS];
            memset(_bits, 0, sizeof(uint8) * _blockCount * CLIENT_UPDATE_MASK_BITS);
        }

        void Clear()
        {
            if (_bits)
                memset(_bits, 0, sizeof(uint8) * _blockCount * CLIENT_UPDATE_MASK_BITS);
        }

        UpdateMask& operator=(UpdateMask const& right)
        {
            if (this == &right)
                return *this;

            SetCount(right.GetCount());
            memcpy(_bits, right._bits, sizeof(uint8) * _blockCount * CLIENT_UPDATE_MASK_BITS);
            return *this;
        }

        UpdateMask& operator&=(UpdateMask const& right)
        {
            ASSERT(right.GetCount() <= GetCount());
            for (uint32 i = 0; i < _fieldCount; ++i)
                _bits[i] &= right._bits[i];

            return *this;
        }

        UpdateMask& operator|=(UpdateMask const& right)
        {
            ASSERT(right.GetCount() <= GetCount());
            for (uint32 i = 0; i < _fieldCount; ++i)
                _bits[i] |= right._bits[i];

            return *this;
        }

        UpdateMask operator|(UpdateMask const& right)
        {
            UpdateMask ret(*this);
            ret |= right;
            return ret;
        }

    private:
        uint32 _fieldCount;
        uint32 _blockCount;
        uint8* _bits;
};

#endif

