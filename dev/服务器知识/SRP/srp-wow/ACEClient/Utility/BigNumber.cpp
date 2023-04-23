/* 
 * Copyright (C) 2005 MaNGOS <http://www.magosproject.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "BigNumber.h"
#include <openssl/bn.h>
#include <algorithm>

BigNumber::BigNumber()
{
    _bn = BN_new();
    _array = NULL;
}


BigNumber::BigNumber(const BigNumber &bn)
{
    _bn = BN_dup(bn._bn);
    _array = NULL;
}


BigNumber::BigNumber(unsigned long val)
{
    _bn = BN_new();
    BN_set_word(_bn, val);
    _array = NULL;
}


BigNumber::~BigNumber()
{
    BN_free(_bn);
    delete[] _array;
}


void BigNumber::SetDword(unsigned long val)
{
    BN_set_word(_bn, val);
}


void BigNumber::SetQword(unsigned __int64 val)
{
    BN_add_word(_bn, (unsigned long)(val >> 32));
    BN_lshift(_bn, _bn, 32);
    BN_add_word(_bn, (unsigned long)(val & 0xFFFFFFFF));
}


void BigNumber::SetBinary(const unsigned char *bytes, int len)
{
    unsigned char t[1000];
    for (int i = 0; i < len; i++) t[i] = bytes[len - 1 - i];
    BN_bin2bn(t, len, _bn);
}


void BigNumber::SetHexStr(const char *str)
{
    BN_hex2bn(&_bn, str);
}


void BigNumber::SetRand(int numbits)
{
    BN_rand(_bn, numbits, 0, 1);
}


BigNumber BigNumber::operator=(const BigNumber &bn)
{
    BN_copy(_bn, bn._bn);
    return *this;
}


BigNumber BigNumber::operator+=(const BigNumber &bn)
{
    BN_add(_bn, _bn, bn._bn);
    return *this;
}


BigNumber BigNumber::operator-=(const BigNumber &bn)
{
    BN_sub(_bn, _bn, bn._bn);
    return *this;
}


BigNumber BigNumber::operator*=(const BigNumber &bn)
{
    BN_CTX *bnctx;

    bnctx = BN_CTX_new();
    BN_mul(_bn, _bn, bn._bn, bnctx);
    BN_CTX_free(bnctx);

    return *this;
}


BigNumber BigNumber::operator/=(const BigNumber &bn)
{
    BN_CTX *bnctx;

    bnctx = BN_CTX_new();
    BN_div(_bn, NULL, _bn, bn._bn, bnctx);
    BN_CTX_free(bnctx);

    return *this;
}


BigNumber BigNumber::operator%=(const BigNumber &bn)
{
    BN_CTX *bnctx;

    bnctx = BN_CTX_new();
    BN_mod(_bn, _bn, bn._bn, bnctx);
    BN_CTX_free(bnctx);

    return *this;
}


BigNumber BigNumber::Exp(const BigNumber &bn)
{
    BigNumber ret;
    BN_CTX *bnctx;

    bnctx = BN_CTX_new();
    BN_exp(ret._bn, _bn, bn._bn, bnctx);
    BN_CTX_free(bnctx);

    return ret;
}


BigNumber BigNumber::ModExp(const BigNumber &bn1, const BigNumber &bn2)
{
    BigNumber ret;
    BN_CTX *bnctx;

    bnctx = BN_CTX_new();
    BN_mod_exp(ret._bn, _bn, bn1._bn, bn2._bn, bnctx);
    BN_CTX_free(bnctx);

    return ret;
}


int BigNumber::GetNumBytes(void)
{
    return BN_num_bytes(_bn);
}


unsigned long BigNumber::AsDword()
{
    return (unsigned long)BN_get_word(_bn);
}


unsigned char *BigNumber::AsByteArray()
{
    if (_array)
    {
        delete[] _array;
        _array = NULL;
    }
    _array = new unsigned char[GetNumBytes()];
    BN_bn2bin(_bn, (unsigned char *)_array);

    std::reverse(_array, _array + GetNumBytes());

    return _array;
}


ByteBuffer BigNumber::AsByteBuffer()
{
    ByteBuffer ret(GetNumBytes());
    ret.append(AsByteArray(), GetNumBytes());
    return ret;
}


std::vector<unsigned char> BigNumber::AsByteVector()
{
    std::vector<unsigned char> ret;
    ret.resize(GetNumBytes());
    memcpy(&ret[0], AsByteArray(), GetNumBytes());
    return ret;
}


const char *BigNumber::AsHexStr()
{
    return BN_bn2hex(_bn);
}


const char *BigNumber::AsDecStr()
{
    return BN_bn2dec(_bn);
}
