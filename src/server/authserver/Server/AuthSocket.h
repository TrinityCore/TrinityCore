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

/// \addtogroup realmd
/// @{
/// \file

#ifndef _AUTHSOCKET_H
#define _AUTHSOCKET_H

#include "Common.h"
#include "BigNumber.h"

#include "RealmSocket.h"

enum RealmFlags
{
    REALM_FLAG_NONE         = 0x00,
    REALM_FLAG_INVALID      = 0x01,
    REALM_FLAG_OFFLINE      = 0x02,
    REALM_FLAG_SPECIFYBUILD = 0x04,                         // client will show realm version in RealmList screen in form "RealmName (major.minor.revision.build)"
    REALM_FLAG_UNK1         = 0x08,
    REALM_FLAG_UNK2         = 0x10,
    REALM_FLAG_RECOMMENDED  = 0x20,                         // client checks pop == 600f
    REALM_FLAG_NEW          = 0x40,                         // client checks pop == 200f
    REALM_FLAG_FULL         = 0x80                          // client checks pop == 400f
};

/// Handle login commands
class AuthSocket: public RealmSocket::Session
{
    public:
        const static int s_BYTE_SIZE = 32;

        AuthSocket(RealmSocket& socket);
        virtual ~AuthSocket(void);

        virtual void OnRead(void);
        virtual void OnAccept(void);
        virtual void OnClose(void);

        bool _HandleLogonChallenge();
        bool _HandleLogonProof();
        bool _HandleReconnectChallenge();
        bool _HandleReconnectProof();
        bool _HandleRealmList();
        //data transfer handle for patch

        bool _HandleXferResume();
        bool _HandleXferCancel();
        bool _HandleXferAccept();

        void _SetVSFields(const std::string& rI);

        FILE *pPatch;
        ACE_Thread_Mutex patcherLock;

    private:
        RealmSocket& socket_;
        RealmSocket& socket(void) { return socket_; }

        BigNumber N, s, g, v;
        BigNumber b, B;
        BigNumber K;
        BigNumber _reconnectProof;

        bool _authed;

        std::string _login;

        // Since GetLocaleByName() is _NOT_ bijective, we have to store the locale as a string. Otherwise we can't differ
        // between enUS and enGB, which is important for the patch system
        std::string _localizationName;
        uint16 _build;
        uint8 _expversion;
        AccountTypes _accountSecurityLevel;
};
#endif
/// @}
