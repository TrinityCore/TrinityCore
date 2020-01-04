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

#include "WorldPacketCrypt.h"
#include "Cryptography/HmacHash.h"
#include "Cryptography/BigNumber.h"

#include <cstring>

WorldPacketCrypt::WorldPacketCrypt() : PacketCrypt(SHA_DIGEST_LENGTH)
{
}

void WorldPacketCrypt::Init(BigNumber* K)
{
    uint8 ServerEncryptionKey[SEED_KEY_SIZE] = { 0xCC, 0x98, 0xAE, 0x04, 0xE8, 0x97, 0xEA, 0xCA, 0x12, 0xDD, 0xC0, 0x93, 0x42, 0x91, 0x53, 0x57 };
    uint8 ServerDecryptionKey[SEED_KEY_SIZE] = { 0xC2, 0xB3, 0x72, 0x3C, 0xC6, 0xAE, 0xD9, 0xB5, 0x34, 0x3C, 0x53, 0xEE, 0x2F, 0x43, 0x67, 0xCE };
    Init(K, ServerEncryptionKey, ServerDecryptionKey);
}

void WorldPacketCrypt::Init(BigNumber* k, uint8 const* serverKey, uint8 const* clientKey)
{
    HmacSha1 serverEncryptHmac(SEED_KEY_SIZE, (uint8*)serverKey);
    uint8* encryptHash = serverEncryptHmac.ComputeHash(k);

    HmacSha1 clientDecryptHmac(SEED_KEY_SIZE, (uint8*)clientKey);
    uint8* decryptHash = clientDecryptHmac.ComputeHash(k);

    _clientDecrypt.Init(decryptHash);
    _serverEncrypt.Init(encryptHash);

    // Drop first 1024 bytes, as WoW uses ARC4-drop1024.
    uint8 syncBuf[1024];
    memset(syncBuf, 0, 1024);

    _serverEncrypt.UpdateData(1024, syncBuf);

    memset(syncBuf, 0, 1024);

    _clientDecrypt.UpdateData(1024, syncBuf);

    _initialized = true;
}
