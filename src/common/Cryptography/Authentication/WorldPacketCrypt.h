/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef _WORLDPACKETCRYPT_H
#define _WORLDPACKETCRYPT_H

#include "PacketCrypt.h"

class BigNumber;

class TC_COMMON_API WorldPacketCrypt : public PacketCrypt
{
    public:
        WorldPacketCrypt();

        void Init(BigNumber* K) override;
        void Init(BigNumber* k, uint8 const* serverKey, uint8 const* clientKey);
};

#endif // _WORLDPACKETCRYPT_H
