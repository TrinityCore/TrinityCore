/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "HmacHash.h"
#include "BigNumber.h"
#include "Errors.h"
#include <cstring>

#if defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER < 0x10100000L
HMAC_CTX* HMAC_CTX_new()
{
    HMAC_CTX *ctx = new HMAC_CTX();
    HMAC_CTX_init(ctx);
    return ctx;
}

void HMAC_CTX_free(HMAC_CTX* ctx)
{
    HMAC_CTX_cleanup(ctx);
    delete ctx;
}
#endif

template<HashCreateFn HashCreator, uint32 DigestLength>
HmacHash<HashCreator, DigestLength>::HmacHash(uint32 len, uint8 const* seed) : _ctx(HMAC_CTX_new())
{
    HMAC_Init_ex(_ctx, seed, len, HashCreator(), nullptr);
    memset(_digest, 0, DigestLength);
}

template<HashCreateFn HashCreator, uint32 DigestLength>
HmacHash<HashCreator, DigestLength>::~HmacHash()
{
    HMAC_CTX_free(_ctx);
}

template<HashCreateFn HashCreator, uint32 DigestLength>
void HmacHash<HashCreator, DigestLength>::UpdateData(std::string const& str)
{
    HMAC_Update(_ctx, reinterpret_cast<uint8 const*>(str.c_str()), str.length());
}

template<HashCreateFn HashCreator, uint32 DigestLength>
void HmacHash<HashCreator, DigestLength>::UpdateData(uint8 const* data, size_t len)
{
    HMAC_Update(_ctx, data, len);
}

template<HashCreateFn HashCreator, uint32 DigestLength>
void HmacHash<HashCreator, DigestLength>::Finalize()
{
    uint32 length = 0;
    HMAC_Final(_ctx, _digest, &length);
    ASSERT(length == DigestLength);
}

template<HashCreateFn HashCreator, uint32 DigestLength>
uint8* HmacHash<HashCreator, DigestLength>::ComputeHash(BigNumber* bn)
{
    HMAC_Update(_ctx, bn->AsByteArray().get(), bn->GetNumBytes());
    Finalize();
    return _digest;
}

template class TC_COMMON_API HmacHash<EVP_sha1, SHA_DIGEST_LENGTH>;
template class TC_COMMON_API HmacHash<EVP_sha256, SHA256_DIGEST_LENGTH>;
