/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#ifndef _AUTH_BIGNUMBER_H
#define _AUTH_BIGNUMBER_H

#include <memory>
#include "Define.h"


struct bignum_st;

class BigNumber
{
    public:
        BigNumber();
        BigNumber(BigNumber const& bn);
        BigNumber(uint32);
        ~BigNumber();

        void SetDword(uint32);
        void SetQword(uint64);
        void SetBinary(uint8 const* bytes, int32 len);
        void SetHexStr(char const* str);

        void SetRand(int32 numbits);

        BigNumber& operator=(BigNumber const& bn);

        BigNumber operator+=(BigNumber const& bn);
        BigNumber operator+(BigNumber const& bn)
        {
            BigNumber t(*this);
            return t += bn;
        }

        BigNumber operator-=(BigNumber const& bn);
        BigNumber operator-(BigNumber const& bn)
        {
            BigNumber t(*this);
            return t -= bn;
        }

        BigNumber operator*=(BigNumber const& bn);
        BigNumber operator*(BigNumber const& bn)
        {
            BigNumber t(*this);
            return t *= bn;
        }

        BigNumber operator/=(BigNumber const& bn);
        BigNumber operator/(BigNumber const& bn)
        {
            BigNumber t(*this);
            return t /= bn;
        }

        BigNumber operator%=(BigNumber const& bn);
        BigNumber operator%(BigNumber const& bn)
        {
            BigNumber t(*this);
            return t %= bn;
        }

        bool isZero() const;

        BigNumber ModExp(BigNumber const& bn1, BigNumber const& bn2);
        BigNumber Exp(BigNumber const&);

        int32 GetNumBytes(void);

        struct bignum_st *BN() { return _bn; }

        uint32 AsDword();

        std::unique_ptr<uint8> AsByteArray(int32 minSize = 0, bool littleEndian = true);

        char * AsHexStr() const;
        char * AsDecStr() const;

    private:
        struct bignum_st *_bn;

};
#endif

