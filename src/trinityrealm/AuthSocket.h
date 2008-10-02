/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
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

/// \addtogroup realmd
/// @{
/// \file

#ifndef _AUTHSOCKET_H
#define _AUTHSOCKET_H

#include "Common.h"
#include "Auth/BigNumber.h"
#include "sockets/TcpSocket.h"
#include "sockets/SocketHandler.h"
#include "sockets/ListenSocket.h"
#include "sockets/Utility.h"
#include "sockets/Parse.h"
#include "sockets/Socket.h"

/// Handle login commands
class AuthSocket: public TcpSocket
{
    public:
        const static int s_BYTE_SIZE = 32;

        AuthSocket(ISocketHandler& h);
        ~AuthSocket();

        void OnAccept();
        void OnRead();

        bool _HandleLogonChallenge();
        bool _HandleLogonProof();
        bool _HandleRealmList();
        //data transfer handle for patch

        bool _HandleXferResume();
        bool _HandleXferCancel();
        bool _HandleXferAccept();

        void _SetVSFields(std::string rI);

        FILE *pPatch;
        bool IsLag();

    private:

        BigNumber N, s, g, v;
        BigNumber b, B;
        BigNumber K;

        bool _authed;

        std::string _login;
        std::string _safelogin;
        uint8 _localization;
        AccountTypes _accountSecurityLevel;
};
#endif
/// @}
