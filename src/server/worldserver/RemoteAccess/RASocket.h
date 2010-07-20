/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/// \addtogroup Trinityd
/// @{
/// \file

#ifndef _RASOCKET_H
#define _RASOCKET_H

#include "TcpSocket.h"

#include "Common.h"

#define RA_BUFF_SIZE 1024

class ISocketHandler;

/// Remote Administration socket
class RASocket: public TcpSocket
{
    public:

        RASocket(ISocketHandler& h);
        ~RASocket();

        void OnAccept();
        void OnRead();

    private:

        char * buff;
        std::string szLogin;
        uint32 iSess;
        unsigned int iInputLength;
        bool bLog;
        bool bSecure;                                       //kick on wrong pass, non exist. user, user with no priv
        //will protect from DOS, bruteforce attacks
        //some 'smart' protection must be added for more security
        uint8 iMinLevel;
        enum
        {
            NONE,                                           //initial value
            LG,                                             //only login was entered
            OK,                                             //both login and pass were given, and they are correct and user have enough priv.
        }stage;

        static void zprint( const char * szText );
};
#endif
/// @}
