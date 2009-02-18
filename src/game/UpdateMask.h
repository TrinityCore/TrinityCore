/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef __UPDATEMASK_H
#define __UPDATEMASK_H

#include "UpdateFields.h"
#include "Errors.h"

class UpdateMask
{
    public:
        UpdateMask( ) : mCount( 0 ), mBlocks( 0 ), mUpdateMask( 0 ) { }
        UpdateMask( const UpdateMask& mask ) : mUpdateMask( 0 ) { *this = mask; }

        ~UpdateMask( )
        {
            if(mUpdateMask)
                delete [] mUpdateMask;
        }

        inline void SetBit (uint32 index)
        {
            ( (uint8 *)mUpdateMask )[ index >> 3 ] |= 1 << ( index & 0x7 );
        }

        inline void UnsetBit (uint32 index)
        {
            ( (uint8 *)mUpdateMask )[ index >> 3 ] &= (0xff ^ (1 <<  ( index & 0x7 ) ) );
        }

        inline bool GetBit (uint32 index)
        {
            return ( ( (uint8 *)mUpdateMask)[ index >> 3 ] & ( 1 << ( index & 0x7 ) )) != 0;
        }

        inline uint32 GetBlockCount() { return mBlocks; }
        inline uint32 GetLength() { return mBlocks << 2; }
        inline uint32 GetCount() { return mCount; }
        inline uint8* GetMask() { return (uint8*)mUpdateMask; }

        inline void SetCount (uint32 valuesCount)
        {
            if(mUpdateMask)
                delete [] mUpdateMask;

            mCount = valuesCount;
            mBlocks = (valuesCount + 31) / 32;

            mUpdateMask = new uint32[mBlocks];
            memset(mUpdateMask, 0, mBlocks << 2);
        }

        inline void Clear()
        {
            if (mUpdateMask)
                memset(mUpdateMask, 0, mBlocks << 2);
        }

        inline UpdateMask& operator = ( const UpdateMask& mask )
        {
            SetCount(mask.mCount);
            memcpy(mUpdateMask, mask.mUpdateMask, mBlocks << 2);

            return *this;
        }

        inline void operator &= ( const UpdateMask& mask )
        {
            ASSERT(mask.mCount <= mCount);
            for (uint32 i = 0; i < mBlocks; i++)
                mUpdateMask[i] &= mask.mUpdateMask[i];
        }

        inline void operator |= ( const UpdateMask& mask )
        {
            ASSERT(mask.mCount <= mCount);
            for (uint32 i = 0; i < mBlocks; i++)
                mUpdateMask[i] |= mask.mUpdateMask[i];
        }

        inline UpdateMask operator & ( const UpdateMask& mask ) const
        {
            ASSERT(mask.mCount <= mCount);

            UpdateMask newmask;
            newmask = *this;
            newmask &= mask;

            return newmask;
        }

        inline UpdateMask operator | ( const UpdateMask& mask ) const
        {
            ASSERT(mask.mCount <= mCount);

            UpdateMask newmask;
            newmask = *this;
            newmask |= mask;

            return newmask;
        }

    private:
        uint32 mCount;
        uint32 mBlocks;
        uint32 *mUpdateMask;
};
#endif

