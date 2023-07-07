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

#include "HmacHash.h"
#include "BigNumber.h"
#include "Errors.h"
#include <cstring>

template<HashCreateFn HashCreator, uint32 DigestLength>
HmacHash<HashCreator, DigestLength>::HmacHash(uint32 len, uint8 const* seed) : _ctx(EVP_MD_CTX_create()), _key(EVP_PKEY_new_mac_key(EVP_PKEY_HMAC, nullptr, seed, len))
{
    EVP_DigestSignInit(_ctx, nullptr, HashCreator(), nullptr, _key);
    memset(_digest, 0, DigestLength);
}

template<HashCreateFn HashCreator, uint32 DigestLength>
HmacHash<HashCreator, DigestLength>::~HmacHash()
{
    EVP_MD_CTX_destroy(_ctx);
    _ctx = nullptr;
    EVP_PKEY_free(_key);
    _key = nullptr;
}

template<HashCreateFn HashCreator, uint32 DigestLength>
void HmacHash<HashCreator, DigestLength>::UpdateData(std::string const& str)
{
    EVP_DigestSignUpdate(_ctx, reinterpret_cast<uint8 const*>(str.c_str()), str.length());
}

template<HashCreateFn HashCreator, uint32 DigestLength>
void HmacHash<HashCreator, DigestLength>::UpdateData(uint8 const* data, size_t len)
{
    EVP_DigestSignUpdate(_ctx, data, len);
}

template<HashCreateFn HashCreator, uint32 DigestLength>
void HmacHash<HashCreator, DigestLength>::Finalize()
{
    size_t length = DigestLength;
    EVP_DigestSignFinal(_ctx, _digest, &length);
    ASSERT(length == DigestLength);
}

template<HashCreateFn HashCreator, uint32 DigestLength>
uint8* HmacHash<HashCreator, DigestLength>::ComputeHash(BigNumber* bn)
{
    EVP_DigestSignUpdate(_ctx, bn->AsByteArray().get(), bn->GetNumBytes());
    Finalize();
    return _digest;
}

template class TC_COMMON_API HmacHash<EVP_sha1, SHA_DIGEST_LENGTH>;
template class TC_COMMON_API HmacHash<EVP_sha256, SHA256_DIGEST_LENGTH>;
