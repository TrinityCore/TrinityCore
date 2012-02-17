/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "Define.h"

struct bignum_st;

class BigNumber
{
    public:
        BigNumber();
        BigNumber(const BigNumber &bn);
        BigNumber(uint32);
        ~BigNumber();

        void SetDword(uint32);
        void SetQword(uint64);
        void SetBinary(const uint8 *bytes, int len);
        void SetHexStr(const char *str);

        void SetRand(int numbits);

        BigNumber operator=(const BigNumber &bn);

        BigNumber operator+=(const BigNumber &bn);
        BigNumber operator+(const BigNumber &bn)
        {
            BigNumber t(*this);
            return t += bn;
        }
        BigNumber operator-=(const BigNumber &bn);
        BigNumber operator-(const BigNumber &bn)
        {
            BigNumber t(*this);
            return t -= bn;
        }
        BigNumber operator*=(const BigNumber &bn);
        BigNumber operator*(const BigNumber &bn)
        {
            BigNumber t(*this);
            return t *= bn;
        }
        BigNumber operator/=(const BigNumber &bn);
        BigNumber operator/(const BigNumber &bn)
        {
            BigNumber t(*this);
            return t /= bn;
        }
        BigNumber operator%=(const BigNumber &bn);
        BigNumber operator%(const BigNumber &bn)
        {
            BigNumber t(*this);
            return t %= bn;
        }

        bool isZero() const;

        BigNumber ModExp(const BigNumber &bn1, const BigNumber &bn2);
        BigNumber Exp(const BigNumber &);

        int GetNumBytes(void);

        struct bignum_st *BN() { return _bn; }

        uint32 AsDword();
        uint8* AsByteArray(int minSize = 0, bool reverse = true);

        const char *AsHexStr();
        const char *AsDecStr();

    private:
        struct bignum_st *_bn;
        uint8 *_array;
};
#endif

