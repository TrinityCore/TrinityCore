/** \file ResolvServer.cpp
 ** \date  2005-03-24
 ** \author grymse@alhem.net
**/
/*
Copyright (C) 2004-2007  Anders Hedstrom

This library is made available under the terms of the GNU GPL.

If you would like to use this library in a closed-source application,
a separate license agreement is available. For information about
the closed-source license agreement for the C++ sockets library,
please visit http://www.alhem.net/Sockets/license.html and/or
email license@alhem.net.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/
#ifdef _MSC_VER
#pragma warning(disable:4786)
#endif
#include "ResolvServer.h"
#ifdef ENABLE_RESOLVER
#include "StdoutLog.h"
#include "ListenSocket.h"
#include "ResolvSocket.h"
#include "SocketHandler.h"

#ifdef SOCKETS_NAMESPACE
namespace SOCKETS_NAMESPACE {
#endif

ResolvServer::ResolvServer(port_t port)
:Thread()
,m_quit(false)
,m_port(port)
,m_ready(false)
{
}

ResolvServer::~ResolvServer()
{
}

void ResolvServer::Run()
{
//  StdoutLog log;
    SocketHandler h;
    ListenSocket<ResolvSocket> l(h);

    if (l.Bind("127.0.0.1", m_port))
    {
        return;
    }
    h.Add(&l);

    m_ready = true;
    while (!m_quit && IsRunning() )
    {
        h.Select(0, 500000);
    }
    SetRunning(false);
}

void ResolvServer::Quit()
{
    m_quit = true;
}

bool ResolvServer::Ready()
{
    return m_ready;
}

#ifdef SOCKETS_NAMESPACE
}
#endif

#endif // ENABLE_RESOLVER


