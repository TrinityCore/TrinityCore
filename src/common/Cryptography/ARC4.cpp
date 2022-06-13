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

#include "ARC4.h"
#include "Errors.h"

#if OPENSSL_VERSION_NUMBER >= 0x30000000L
#include <openssl/provider.h>
#endif

Trinity::Crypto::ARC4::ARC4() : _ctx(EVP_CIPHER_CTX_new())
{
    EVP_CIPHER_CTX_init(_ctx);
    const EVP_CIPHER *cipher;

#if OPENSSL_VERSION_NUMBER >= 0x30000000L
    _libctx = OSSL_LIB_CTX_new();
    _legacy_provider = OSSL_PROVIDER_load(_libctx, "legacy");
    _default_provider = OSSL_PROVIDER_load(_libctx, "default");

    cipher = EVP_CIPHER_fetch(_libctx, "RC4", "");
#else
    cipher = EVP_rc4();
#endif

    int result = EVP_EncryptInit_ex(_ctx, cipher, nullptr, nullptr, nullptr);
    ASSERT(result == 1);
}

Trinity::Crypto::ARC4::~ARC4()
{
#if OPENSSL_VERSION_NUMBER >= 0x30000000L
    if (_legacy_provider) OSSL_PROVIDER_unload(_legacy_provider);
    if (_default_provider) OSSL_PROVIDER_unload(_default_provider);
    if (_libctx) OSSL_LIB_CTX_free(_libctx);
#endif

    EVP_CIPHER_CTX_free(_ctx);
}

void Trinity::Crypto::ARC4::Init(uint8 const* seed, size_t len)
{
    int result1 = EVP_CIPHER_CTX_set_key_length(_ctx, static_cast<int>(len));
    ASSERT(result1 == 1);
    int result2 = EVP_EncryptInit_ex(_ctx, nullptr, nullptr, seed, nullptr);
    ASSERT(result2 == 1);
}

void Trinity::Crypto::ARC4::UpdateData(uint8* data, size_t len)
{
    int outlen = 0;
    int result1 = EVP_EncryptUpdate(_ctx, data, &outlen, data, static_cast<int>(len));
    ASSERT(result1 == 1);
    int result2 = EVP_EncryptFinal_ex(_ctx, data, &outlen);
    ASSERT(result2 == 1);
}
