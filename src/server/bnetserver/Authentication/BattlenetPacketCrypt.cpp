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

#include "BattlenetPacketCrypt.h"
#include "Cryptography/HmacHash.h"
#include "Cryptography/BigNumber.h"

Battlenet::PacketCrypt::PacketCrypt() : ::PacketCrypt(SHA256_DIGEST_LENGTH)
{
}

void Battlenet::PacketCrypt::Init(BigNumber* K)
{
    uint8 ServerEncryptionKey[SEED_KEY_SIZE] = { 0x68, 0xE0, 0xC7, 0x2E, 0xDD, 0xD6, 0xD2, 0xF3, 0x1E, 0x5A, 0xB1, 0x55, 0xB1, 0x8B, 0x63, 0x1E };
    uint8 ClientDecryptionKey[SEED_KEY_SIZE] = { 0xDE, 0xA9, 0x65, 0xAE, 0x54, 0x3A, 0x1E, 0x93, 0x9E, 0x69, 0x0C, 0xAA, 0x68, 0xDE, 0x78, 0x39 };

    HmacSha256 serverEncryptHmac(K->GetNumBytes(), K->AsByteArray().get());
    serverEncryptHmac.UpdateData(ServerEncryptionKey, SEED_KEY_SIZE);
    serverEncryptHmac.Finalize();

    HmacSha256 clientDecryptHmac(K->GetNumBytes(), K->AsByteArray().get());
    clientDecryptHmac.UpdateData(ClientDecryptionKey, SEED_KEY_SIZE);
    clientDecryptHmac.Finalize();

    _clientDecrypt.Init(clientDecryptHmac.GetDigest());
    _serverEncrypt.Init(serverEncryptHmac.GetDigest());
    _initialized = true;
}
