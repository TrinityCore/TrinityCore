/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "AES.h"
#include "Errors.h"
#include <array>
#include <limits>
#include <openssl/rand.h>

using namespace Trinity::Crypto;

AES::AES(bool encrypting) : _encrypting(encrypting), _ctx(EVP_CIPHER_CTX_new())
{
    EVP_CIPHER_CTX_init(_ctx);
    int status = EVP_CipherInit_ex(_ctx, EVP_aes_128_gcm(), nullptr, nullptr, nullptr, _encrypting ? 1 : 0);
    ASSERT(status);
}

AES::~AES()
{
    EVP_CIPHER_CTX_free(_ctx);
}

void AES::Init(AES::Key const& key)
{
    int status = EVP_CipherInit_ex(_ctx, nullptr, nullptr, key.data(), nullptr, -1);
    ASSERT(status);
}

bool AES::Process(AES::IV const& iv, uint8* data, std::size_t length, AES::Tag& tag)
{
    ASSERT(length <= std::numeric_limits<int>::max());
    int len = static_cast<int>(length);
    if (!EVP_CipherInit_ex(_ctx, nullptr, nullptr, nullptr, iv.data(), -1))
        return false;

    int outLen;
    if (!EVP_CipherUpdate(_ctx, data, &outLen, data, len))
        return false;
    len -= outLen;

    if (!_encrypting && !EVP_CIPHER_CTX_ctrl(_ctx, EVP_CTRL_GCM_SET_TAG, TAG_SIZE_BYTES, tag))
        return false;

    if (!EVP_CipherFinal_ex(_ctx, data + outLen, &outLen))
        return false;
    ASSERT(len == outLen);

    if (_encrypting && !EVP_CIPHER_CTX_ctrl(_ctx, EVP_CTRL_GCM_GET_TAG, sizeof(tag), tag))
        return false;

    return true;
}
