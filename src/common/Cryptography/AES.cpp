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

#include "AES.h"

Trinity::Crypto::AES::AES(bool encrypting) : _ctx(EVP_CIPHER_CTX_new()), _encrypting(encrypting)
{
    EVP_CIPHER_CTX_init(_ctx);
    EVP_CipherInit_ex(_ctx, EVP_aes_128_gcm(), nullptr, nullptr, nullptr, _encrypting ? 1 : 0);
}

Trinity::Crypto::AES::~AES()
{
    EVP_CIPHER_CTX_free(_ctx);
}

void Trinity::Crypto::AES::Init(uint8 const* key)
{
    EVP_CipherInit_ex(_ctx, nullptr, nullptr, key, nullptr, -1);
}

bool Trinity::Crypto::AES::Process(uint8 const* iv, uint8* data, std::size_t length, uint8(&tag)[12])
{
    if (!EVP_CipherInit_ex(_ctx, nullptr, nullptr, nullptr, iv, -1))
        return false;

    int outLen;
    if (!EVP_CipherUpdate(_ctx, data, &outLen, data, length))
        return false;

    if (!_encrypting && !EVP_CIPHER_CTX_ctrl(_ctx, EVP_CTRL_GCM_SET_TAG, sizeof(tag), tag))
        return false;

    if (!EVP_CipherFinal_ex(_ctx, data + outLen, &outLen))
        return false;

    if (_encrypting && !EVP_CIPHER_CTX_ctrl(_ctx, EVP_CTRL_GCM_GET_TAG, sizeof(tag), tag))
        return false;

    return true;
}
