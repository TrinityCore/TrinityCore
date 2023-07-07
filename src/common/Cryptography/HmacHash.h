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

#ifndef _AUTH_HMAC_H
#define _AUTH_HMAC_H

#include "Define.h"
#include <string>
#include <openssl/hmac.h>
#include <openssl/sha.h>

class BigNumber;

#define SEED_KEY_SIZE 16

typedef EVP_MD const* (*HashCreateFn)();

template<HashCreateFn HashCreator, uint32 DigestLength>
class TC_COMMON_API HmacHash
{
    public:
        HmacHash(uint32 len, uint8 const* seed);
        ~HmacHash();
        void UpdateData(std::string const& str);
        void UpdateData(uint8 const* data, size_t len);
        void Finalize();
        uint8* ComputeHash(BigNumber* bn);
        uint8* GetDigest() { return _digest; }
        uint32 GetLength() const { return DigestLength; }
    private:
        EVP_MD_CTX* _ctx;
        EVP_PKEY* _key;
        uint8 _digest[DigestLength];
};

typedef HmacHash<EVP_sha1, SHA_DIGEST_LENGTH> HmacSha1;
typedef HmacHash<EVP_sha256, SHA256_DIGEST_LENGTH> HmacSha256;

#endif
