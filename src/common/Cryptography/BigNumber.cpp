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
    : _bn(BN_dup(bn._bn))
{ }

BigNumber::BigNumber(uint32 val)
    : _bn(BN_new())
{
    BN_set_word(_bn, val);
}

BigNumber::~BigNumber()
{
    BN_free(_bn);
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

void BigNumber::SetBinary(uint8 const* bytes, int32 len)
{
    uint8* array = new uint8[len];

    for (int i = 0; i < len; i++)
        array[i] = bytes[len - 1 - i];

    BN_bin2bn(array, len, _bn);

    delete[] array;
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

int BigNumber::CompareTo(BigNumber const& bn) const
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

bool BigNumber::AsByteArray(uint8* buf, std::size_t bufsize, bool littleEndian) const
{
    int nBytes = GetNumBytes();
    ASSERT(!(nBytes < 0));
    std::size_t numBytes = static_cast<std::size_t>(nBytes);

    // too large to store
    if (bufsize < numBytes)
        return false;

    // If we need more bytes than length of BigNumber set the rest to 0
    if (numBytes < bufsize)
        memset((void*)buf, 0, bufsize);

    BN_bn2bin(_bn, buf + (bufsize - numBytes));

    // openssl's BN stores data internally in big endian format, reverse if little endian desired
    if (littleEndian)
        std::reverse(buf, buf + bufsize);

    return true;
}

std::unique_ptr<uint8[]> BigNumber::AsByteArray(int32 minSize, bool littleEndian) const
{
    std::size_t length = std::max(GetNumBytes(), minSize);
    uint8* array = new uint8[length];
    bool success = AsByteArray(array, length, littleEndian);
    ASSERT(success);

    return std::unique_ptr<uint8[]>(array);
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
