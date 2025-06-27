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

#include "Cryptography/BigNumber.h"
#include "Errors.h"
#include <openssl/bn.h>
#include <cstring>
#include <algorithm>
#include <memory>

BigNumber::BigNumber()
    : _bn(BN_new())
{ }

BigNumber::BigNumber(BigNumber const& bn)
    : _bn(BN_dup(bn.BN()))
{ }

BigNumber::~BigNumber()
{
    BN_free(_bn);
}

void BigNumber::SetDword(int32 val)
{
    SetDword(uint32(abs(val)));
    if (val < 0)
        BN_set_negative(_bn, 1);
}

void BigNumber::SetDword(uint32 val)
{
    BN_set_word(_bn, val);
}

void BigNumber::SetQword(uint64 val)
{
    BN_set_word(_bn, (uint32)(val >> 32));
    BN_lshift(_bn, _bn, 32);
    BN_add_word(_bn, (uint32)(val & 0xFFFFFFFF));
}

void BigNumber::SetBinary(uint8 const* bytes, int32 len, bool littleEndian)
{
    if (littleEndian)
        BN_lebin2bn(bytes, len, _bn);
    else
        BN_bin2bn(bytes, len, _bn);
}

bool BigNumber::SetHexStr(char const* str)
{
    int n = BN_hex2bn(&_bn, str);
    return (n > 0);
}

void BigNumber::SetRand(int32 numbits)
{
    BN_rand(_bn, numbits, 0, 1);
}

BigNumber& BigNumber::operator=(BigNumber const& bn)
{
    if (this == &bn)
        return *this;

    BN_copy(_bn, bn._bn);
    return *this;
}

BigNumber& BigNumber::operator+=(BigNumber const& bn)
{
    BN_add(_bn, _bn, bn._bn);
    return *this;
}

BigNumber& BigNumber::operator-=(BigNumber const& bn)
{
    BN_sub(_bn, _bn, bn._bn);
    return *this;
}

BigNumber& BigNumber::operator*=(BigNumber const& bn)
{
    BN_CTX *bnctx;

    bnctx = BN_CTX_new();
    BN_mul(_bn, _bn, bn._bn, bnctx);
    BN_CTX_free(bnctx);

    return *this;
}

BigNumber& BigNumber::operator/=(BigNumber const& bn)
{
    BN_CTX *bnctx;

    bnctx = BN_CTX_new();
    BN_div(_bn, nullptr, _bn, bn._bn, bnctx);
    BN_CTX_free(bnctx);

    return *this;
}

BigNumber& BigNumber::operator%=(BigNumber const& bn)
{
    BN_CTX *bnctx;

    bnctx = BN_CTX_new();
    BN_mod(_bn, _bn, bn._bn, bnctx);
    BN_CTX_free(bnctx);

    return *this;
}

BigNumber& BigNumber::operator<<=(int n)
{
    BN_lshift(_bn, _bn, n);
    return *this;
}

int32 BigNumber::CompareTo(BigNumber const& bn) const
{
    return BN_cmp(_bn, bn._bn);
}

BigNumber BigNumber::Exp(BigNumber const& bn) const
{
    BigNumber ret;
    BN_CTX *bnctx;

    bnctx = BN_CTX_new();
    BN_exp(ret._bn, _bn, bn._bn, bnctx);
    BN_CTX_free(bnctx);

    return ret;
}

BigNumber BigNumber::ModExp(BigNumber const& bn1, BigNumber const& bn2) const
{
    BigNumber ret;
    BN_CTX *bnctx;

    bnctx = BN_CTX_new();
    BN_mod_exp(ret._bn, _bn, bn1._bn, bn2._bn, bnctx);
    BN_CTX_free(bnctx);

    return ret;
}

int32 BigNumber::GetNumBytes() const
{
    return BN_num_bytes(_bn);
}

uint32 BigNumber::AsDword() const
{
    return (uint32)BN_get_word(_bn);
}

bool BigNumber::IsZero() const
{
    return BN_is_zero(_bn);
}

bool BigNumber::IsNegative() const
{
    return BN_is_negative(_bn);
}

void BigNumber::GetBytes(uint8* buf, size_t bufsize, bool littleEndian) const
{
    int res = littleEndian ? BN_bn2lebinpad(_bn, buf, bufsize) : BN_bn2binpad(_bn, buf, bufsize);
    ASSERT(res > 0, "Buffer of size %zu is too small to hold bignum with %d bytes.\n", bufsize, BN_num_bytes(_bn));
}

std::vector<uint8> BigNumber::ToByteVector(int32 minSize, bool littleEndian) const
{
    std::size_t length = std::max(GetNumBytes(), minSize);
    std::vector<uint8> v;
    v.resize(length);
    GetBytes(v.data(), length, littleEndian);
    return v;
}

std::string BigNumber::AsHexStr() const
{
    char* ch = BN_bn2hex(_bn);
    std::string ret = ch;
    OPENSSL_free(ch);
    return ret;
}

std::string BigNumber::AsDecStr() const
{
    char* ch = BN_bn2dec(_bn);
    std::string ret = ch;
    OPENSSL_free(ch);
    return ret;
}
