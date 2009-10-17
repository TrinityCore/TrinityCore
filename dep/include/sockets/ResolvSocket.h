/** \file ResolvSocket.h
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
#ifndef _SOCKETS_ResolvSocket_H
#define _SOCKETS_ResolvSocket_H
#include "sockets-config.h"
#ifdef ENABLE_RESOLVER
#include "TcpSocket.h"
#include <map>

#ifdef SOCKETS_NAMESPACE
namespace SOCKETS_NAMESPACE {
#endif

class Mutex;

/** Async DNS resolver socket.
    \ingroup async */
class ResolvSocket : public TcpSocket
{
    typedef std::map<std::string, /* type */
            std::map<std::string, std::string> > cache_t; /* host, result */
    typedef std::map<std::string, /* type */
            std::map<std::string, time_t> > timeout_t; /* host, time */

public:
    ResolvSocket(ISocketHandler&);
    ResolvSocket(ISocketHandler&, Socket *parent, const std::string& host, port_t port, bool ipv6 = false);
    ResolvSocket(ISocketHandler&, Socket *parent, ipaddr_t);
#ifdef ENABLE_IPV6
    ResolvSocket(ISocketHandler&, Socket *parent, in6_addr&);
#endif
    ~ResolvSocket();

    void OnAccept() { m_bServer = true; }
    void OnLine(const std::string& line);
    void OnDetached();
    void OnDelete();

    void SetId(int x) { m_resolv_id = x; }
    int GetId() { return m_resolv_id; }

    void OnConnect();

#ifdef ENABLE_IPV6
    void SetResolveIpv6(bool x = true) { m_resolve_ipv6 = x; }
#endif

private:
    ResolvSocket(const ResolvSocket& s) : TcpSocket(s) {} // copy constructor
    ResolvSocket& operator=(const ResolvSocket& ) { return *this; } // assignment operator

    std::string m_query;
    std::string m_data;
    bool m_bServer;
    Socket *m_parent;
    int m_resolv_id;
    std::string m_resolv_host;
    port_t m_resolv_port;
    ipaddr_t m_resolv_address;
#ifdef ENABLE_IPV6
    bool m_resolve_ipv6;
    in6_addr m_resolv_address6;
#endif
    static cache_t m_cache;
    static timeout_t m_cache_to;
    static Mutex m_cache_mutex;
    bool m_cached;
};




#ifdef SOCKETS_NAMESPACE
}
#endif

#endif // ENABLE_RESOLVER
#endif // _SOCKETS_ResolvSocket_H


