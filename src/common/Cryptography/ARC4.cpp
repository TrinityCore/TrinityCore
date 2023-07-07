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

ARC4::ARC4(uint32 len) : _ctx(EVP_CIPHER_CTX_new())
{
#if OPENSSL_VERSION_NUMBER >= 0x30000000L
    _cipher = EVP_CIPHER_fetch(nullptr, "RC4", nullptr);
#else
    EVP_CIPHER const *_cipher = EVP_rc4();
#endif

    EVP_CIPHER_CTX_init(_ctx);
    EVP_EncryptInit_ex(_ctx, _cipher, nullptr, nullptr, nullptr);
    EVP_CIPHER_CTX_set_key_length(_ctx, len);
}

ARC4::ARC4(uint8* seed, uint32 len) : _ctx(EVP_CIPHER_CTX_new())
{
#if OPENSSL_VERSION_NUMBER >= 0x30000000L
    _cipher = EVP_CIPHER_fetch(nullptr, "RC4", nullptr);
#else
    EVP_CIPHER const *_cipher = EVP_rc4();
#endif

    EVP_CIPHER_CTX_init(_ctx);
    EVP_EncryptInit_ex(_ctx, _cipher, nullptr, nullptr, nullptr);
    EVP_CIPHER_CTX_set_key_length(_ctx, len);
    EVP_EncryptInit_ex(_ctx, nullptr, nullptr, seed, nullptr);
}

ARC4::~ARC4()
{
    EVP_CIPHER_CTX_free(_ctx);

#if OPENSSL_VERSION_NUMBER >= 0x30000000L
    EVP_CIPHER_free(_cipher);
#endif
}

void ARC4::Init(uint8* seed)
{
    EVP_EncryptInit_ex(_ctx, nullptr, nullptr, seed, nullptr);
}

void ARC4::UpdateData(int len, uint8* data)
{
    int outlen = 0;
    EVP_EncryptUpdate(_ctx, data, &outlen, data, len);
    EVP_EncryptFinal_ex(_ctx, data, &outlen);
}
