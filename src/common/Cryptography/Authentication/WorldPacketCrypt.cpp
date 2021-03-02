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
#include <array>
#include <cstring>

WorldPacketCrypt::WorldPacketCrypt() : _clientDecrypt(false), _serverEncrypt(true), _clientCounter(0), _serverCounter(0), _initialized(false)
{
}

void WorldPacketCrypt::Init(Trinity::Crypto::AES::Key const& key)
{
    _clientDecrypt.Init(key);
    _serverEncrypt.Init(key);
    _initialized = true;
}

struct WorldPacketCryptIV
{
    WorldPacketCryptIV(uint64 counter, uint32 magic)
    {
        memcpy(Value.data(), &counter, sizeof(uint64));
        memcpy(Value.data() + sizeof(uint64), &magic, sizeof(uint32));
    }

    std::array<uint8, 12> Value;
};

bool WorldPacketCrypt::PeekDecryptRecv(uint8* data, size_t length)
{
    if (_initialized)
    {
        WorldPacketCryptIV iv{ _clientCounter, 0x544E4C43 };
        if (!_clientDecrypt.ProcessNoIntegrityCheck(iv.Value, data, length))
            return false;
    }

    return true;
}

bool WorldPacketCrypt::DecryptRecv(uint8* data, size_t length, Trinity::Crypto::AES::Tag& tag)
{
    if (_initialized)
    {
        WorldPacketCryptIV iv{ _clientCounter, 0x544E4C43 };
        if (!_clientDecrypt.Process(iv.Value, data, length, tag))
            return false;
    }
    else
        memset(tag, 0, sizeof(tag));

    ++_clientCounter;
    return true;
}

bool WorldPacketCrypt::EncryptSend(uint8* data, size_t length, Trinity::Crypto::AES::Tag& tag)
{
    if (_initialized)
    {
        WorldPacketCryptIV iv{ _serverCounter, 0x52565253 };
        if (!_serverEncrypt.Process(iv.Value, data, length, tag))
            return false;
    }
    else
        memset(tag, 0, sizeof(tag));

    ++_serverCounter;
    return true;
}
