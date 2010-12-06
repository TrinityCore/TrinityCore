/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef _AUTHCRYPT_H
#define _AUTHCRYPT_H

#include <Common.h>
#include "Cryptography/ARC4.h"

class BigNumber;

class AuthCrypt
{
    public:
        AuthCrypt();
        ~AuthCrypt();

        void Init(BigNumber *K);
        void DecryptRecv(uint8 *, size_t);
        void EncryptSend(uint8 *, size_t);

        bool IsInitialized() const { return _initialized; }

    private:
        ARC4 _clientDecrypt;
        ARC4 _serverEncrypt;
        bool _initialized;
};
#endif

