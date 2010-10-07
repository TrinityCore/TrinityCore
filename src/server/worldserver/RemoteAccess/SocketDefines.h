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

#ifndef TRINITY_SOCKETDEFINES_H
#define TRINITY_SOCKETDEFINES_H

#ifdef WIN32

/* Windows socket definitions
 */
#define FD_SETSIZE 1024
#include <winsock2.h>
#include <Ws2tcpip.h>

typedef SOCKET SocketHandle;
typedef fd_set SelectSet;

#else

/* The unix socket definitions
 */
#include <sys/socket.h>
#include <netinet/in.h>
#ifdef __APPLE_CC__
#include <sys/select.h>
#endif

typedef int SocketHandle;
typedef fd_set SelectSet;
#endif
#endif

