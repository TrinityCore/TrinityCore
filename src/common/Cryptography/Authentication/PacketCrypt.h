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

#ifndef _PACKETCRYPT_H
#define _PACKETCRYPT_H

#include "Cryptography/ARC4.h"

class BigNumber;

class TC_COMMON_API PacketCrypt
{
    public:
        PacketCrypt(uint32 rc4InitSize);
        virtual ~PacketCrypt() { }

        virtual void Init(BigNumber* K) = 0;
        void DecryptRecv(uint8* data, size_t length);
        void EncryptSend(uint8* data, size_t length);

        bool IsInitialized() const { return _initialized; }

    protected:
        ARC4 _clientDecrypt;
        ARC4 _serverEncrypt;
        bool _initialized;
};

#endif // _PACKETCRYPT_H
