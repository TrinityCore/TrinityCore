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

#include "TOTP.h"
#include <cstring>
#include <openssl/evp.h>
#include <openssl/hmac.h>

constexpr std::size_t Trinity::Crypto::TOTP::RECOMMENDED_SECRET_LENGTH;
static constexpr uint32 TOTP_INTERVAL = 30;
static constexpr uint32 HMAC_RESULT_SIZE = 20;
/*static*/ uint32 Trinity::Crypto::TOTP::GenerateToken(Secret const& secret, time_t timestamp)
{
    timestamp /= TOTP_INTERVAL;
    unsigned char challenge[8];
    for (int i = 8; i--; timestamp >>= 8)
        challenge[i] = timestamp;

    unsigned char digest[HMAC_RESULT_SIZE];
    uint32 digestSize = HMAC_RESULT_SIZE;
    HMAC(EVP_sha1(), secret.data(), secret.size(), challenge, 8, digest, &digestSize);

    uint32 offset = digest[19] & 0xF;
    uint32 truncated = (digest[offset] << 24) | (digest[offset + 1] << 16) | (digest[offset + 2] << 8) | (digest[offset + 3]);
    truncated &= 0x7FFFFFFF;
    return (truncated % 1000000);
}

/*static*/ bool Trinity::Crypto::TOTP::ValidateToken(Secret const& secret, uint32 token)
{
    time_t now = time(nullptr);
    return (
        (token == GenerateToken(secret, now - TOTP_INTERVAL)) ||
        (token == GenerateToken(secret, now)) ||
        (token == GenerateToken(secret, now + TOTP_INTERVAL))
    );
}
