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

/// \addtogroup Trinityd
/// @{
/// \file

#ifndef _RASOCKET_H
#define _RASOCKET_H

#include "TcpSocket.h"

#include "Common.h"
#include <ace/Synch_Traits.h>

#define RA_BUFF_SIZE 1024

class ISocketHandler;

typedef ACE_Atomic_Op<ACE_SYNCH_MUTEX, uint64> AtomicInt;

/// Remote Administration socket
class RASocket: public TcpSocket
{
    public:

        RASocket(ISocketHandler& h);
        ~RASocket();

        void OnAccept();
        void OnRead();

    AtomicInt pendingCommands;

    private:
        char buff[RA_BUFF_SIZE];
        std::string szLogin;

        unsigned int iInputLength;
        bool bSecure;
        //will protect from DOS, bruteforce attacks
        //some 'smart' protection must be added for more security
        uint8 iMinLevel;
        enum
        {
            NONE,                                           //initial value
            LG,                                             //only login was entered
            OK,                                             //both login and pass were given, and they are correct and user have enough priv.
        }stage;

        static void zprint(void* callbackArg, const char * szText );
        static void commandFinished(void* callbackArg, bool success);
};
#endif
/// @}
