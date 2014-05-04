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

#include "HmacHash.h"
#include "BigNumber.h"
#include "Common.h"

HmacHash::HmacHash(uint32 len, uint8 *seed, EVP_MD const* hasher, uint32 digestLength) : _digestLength(digestLength)
{
    HMAC_CTX_init(&_ctx);
    HMAC_Init_ex(&_ctx, seed, len, hasher, NULL);
    _digest = new uint8[digestLength];
    memset(_digest, 0, digestLength);
}

HmacHash::~HmacHash()
{
    HMAC_CTX_cleanup(&_ctx);
    delete[] _digest;
}

void HmacHash::UpdateData(const std::string &str)
{
    HMAC_Update(&_ctx, (uint8 const*)str.c_str(), str.length());
}

void HmacHash::UpdateData(const uint8* data, size_t len)
{
    HMAC_Update(&_ctx, data, len);
}

void HmacHash::Finalize()
{
    uint32 length = 0;
    HMAC_Final(&_ctx, _digest, &length);
    ASSERT(length == _digestLength);
}

uint8* HmacHash::ComputeHash(BigNumber* bn)
{
    HMAC_Update(&_ctx, bn->AsByteArray().get(), bn->GetNumBytes());
    Finalize();
    return _digest;
}
