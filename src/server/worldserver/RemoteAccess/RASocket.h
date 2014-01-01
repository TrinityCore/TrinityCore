/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "Common.h"

#include <ace/Synch_Traits.h>
#include <ace/Svc_Handler.h>
#include <ace/SOCK_Stream.h>
#include <ace/SOCK_Acceptor.h>

/// Remote Administration socket
class RASocket : public ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_MT_SYNCH>
{
    public:
        RASocket();
        virtual ~RASocket() { }

        virtual int svc() OVERRIDE;
        virtual int open(void* = 0) OVERRIDE;
        virtual int handle_close(ACE_HANDLE = ACE_INVALID_HANDLE, ACE_Reactor_Mask = ACE_Event_Handler::ALL_EVENTS_MASK) OVERRIDE;

    private:
        int recv_line(std::string& outLine);
        int recv_line(ACE_Message_Block& buffer);
        int process_command(const std::string& command);
        int authenticate();
        int subnegotiate();     ///< Used by telnet protocol RFC 854 / 855
        int check_access_level(const std::string& user);
        int check_password(const std::string& user, const std::string& pass);
        int send(const std::string& line);

        static void zprint(void* callbackArg, const char* szText);
        static void commandFinished(void* callbackArg, bool success);

    private:
        uint8 _minLevel; ///< Minimum security level required to connect
        ACE_Atomic_Op<ACE_Thread_Mutex, bool> _commandExecuting;
};

#endif

/// @}
