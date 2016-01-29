/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "PacketCrypt.h"

PacketCrypt::PacketCrypt(uint32 rc4InitSize)
    : _clientDecrypt(rc4InitSize), _serverEncrypt(rc4InitSize), _initialized(false)
{
}

void PacketCrypt::DecryptRecv(uint8* data, size_t len)
{
    if (!_initialized)
        return;

    _clientDecrypt.UpdateData(len, data);
}

void PacketCrypt::EncryptSend(uint8* data, size_t len)
{
    if (!_initialized)
        return;

    _serverEncrypt.UpdateData(len, data);
}
