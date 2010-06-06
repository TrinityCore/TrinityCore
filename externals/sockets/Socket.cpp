/** \file Socket.cpp
 ** \date  2004-02-13
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
#include "Socket.h"
#ifdef _WIN32
#ifdef _MSC_VER
#pragma warning(disable:4786)
#endif
#include <stdlib.h>
#else
#include <errno.h>
#include <netdb.h>
#endif
#include <ctype.h>
#include <fcntl.h>

#include "ISocketHandler.h"
#include "Utility.h"

#include "SocketAddress.h"
#include "SocketHandler.h"
#ifdef ENABLE_EXCEPTIONS
#include "Exception.h"
#endif
#include "Ipv4Address.h"

//#ifdef _DEBUG
//#define DEB(x) x; fflush(stderr);
//#else
#define DEB(x)
//#endif

#ifdef SOCKETS_NAMESPACE
namespace SOCKETS_NAMESPACE {
#endif

// statics
#ifdef _WIN32
WSAInitializer Socket::m_winsock_init;
#endif

Socket::Socket(ISocketHandler& h)
//:m_flags(0)
:m_handler(h)
,m_socket( INVALID_SOCKET )
,m_bDel(false)
,m_bClose(false)
,m_tCreate(time(NULL))
,m_parent(NULL)
,m_b_disable_read(false)
,m_connected(false)
,m_b_erased_by_handler(false)
,m_tClose(0)
,m_client_remote_address(NULL)
,m_remote_address(NULL)
,m_traffic_monitor(NULL)
,m_bLost(false)
#ifdef HAVE_OPENSSL
,m_b_enable_ssl(false)
,m_b_ssl(false)
,m_b_ssl_server(false)
#endif
#ifdef ENABLE_IPV6
,m_ipv6(false)
#endif
#ifdef ENABLE_POOL
,m_socket_type(0)
,m_bClient(false)
,m_bRetain(false)
#endif
#ifdef ENABLE_SOCKS4
,m_bSocks4(false)
,m_socks4_host(h.GetSocks4Host())
,m_socks4_port(h.GetSocks4Port())
,m_socks4_userid(h.GetSocks4Userid())
#endif
#ifdef ENABLE_DETACH
,m_detach(false)
,m_detached(false)
,m_pThread(NULL)
,m_slave_handler(NULL)
#endif
{
}

Socket::~Socket()
{
    Handler().Remove(this);
    if (m_socket != INVALID_SOCKET
#ifdef ENABLE_POOL
         && !m_bRetain
#endif
        )
    {
        Close();
    }
}

void Socket::Init()
{
}

void Socket::OnRead()
{
}

void Socket::OnWrite()
{
}

void Socket::OnException()
{
    // %! exception doesn't always mean something bad happened, this code should be reworked
    // errno valid here?
    int err = SoError();
    Handler().LogError(this, "exception on select", err, StrError(err), LOG_LEVEL_FATAL);
    SetCloseAndDelete();
}

void Socket::OnDelete()
{
}

void Socket::OnConnect()
{
}

void Socket::OnAccept()
{
}

int Socket::Close()
{
    if (m_socket == INVALID_SOCKET) // this could happen
    {
        Handler().LogError(this, "Socket::Close", 0, "file descriptor invalid", LOG_LEVEL_WARNING);
        return 0;
    }
    int n;
    if ((n = closesocket(m_socket)) == -1)
    {
        // failed...
        Handler().LogError(this, "close", Errno, StrError(Errno), LOG_LEVEL_ERROR);
    }
    Handler().Set(m_socket, false, false, false); // remove from fd_set's
    Handler().AddList(m_socket, LIST_CALLONCONNECT, false);
#ifdef ENABLE_DETACH
    Handler().AddList(m_socket, LIST_DETACH, false);
#endif
    Handler().AddList(m_socket, LIST_TIMEOUT, false);
    Handler().AddList(m_socket, LIST_RETRY, false);
    Handler().AddList(m_socket, LIST_CLOSE, false);
    m_socket = INVALID_SOCKET;
    return n;
}

SOCKET Socket::CreateSocket(int af,int type, const std::string& protocol)
{
    struct protoent *p = NULL;
    SOCKET s;

#ifdef ENABLE_POOL
    m_socket_type = type;
    m_socket_protocol = protocol;
#endif
    if (!protocol.empty())
    {
        p = getprotobyname( protocol.c_str() );
        if (!p)
        {
            Handler().LogError(this, "getprotobyname", Errno, StrError(Errno), LOG_LEVEL_FATAL);
            SetCloseAndDelete();
#ifdef ENABLE_EXCEPTIONS
            throw Exception(std::string("getprotobyname() failed: ") + StrError(Errno));
#endif
            return INVALID_SOCKET;
        }
    }
    int protno = p ? p -> p_proto : 0;

    s = socket(af, type, protno);
    if (s == INVALID_SOCKET)
    {
        Handler().LogError(this, "socket", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        SetCloseAndDelete();
#ifdef ENABLE_EXCEPTIONS
        throw Exception(std::string("socket() failed: ") + StrError(Errno));
#endif
        return INVALID_SOCKET;
    }
    Attach(s);
    OnOptions(af, type, protno, s);
    Attach(INVALID_SOCKET);
    return s;
}

void Socket::Attach(SOCKET s)
{
    m_socket = s;
}

SOCKET Socket::GetSocket()
{
    return m_socket;
}

void Socket::SetDeleteByHandler(bool x)
{
    m_bDel = x;
}

bool Socket::DeleteByHandler()
{
    return m_bDel;
}

void Socket::SetCloseAndDelete(bool x)
{
    if (x != m_bClose)
    {
        Handler().AddList(m_socket, LIST_CLOSE, x);
        m_bClose = x;
        if (x)
        {
            m_tClose = time(NULL);
        }
    }
}

bool Socket::CloseAndDelete()
{
    return m_bClose;
}

void Socket::SetRemoteAddress(SocketAddress& ad) //struct sockaddr* sa, socklen_t l)
{
    m_remote_address = ad.GetCopy();
}

std::auto_ptr<SocketAddress> Socket::GetRemoteSocketAddress()
{
    return m_remote_address -> GetCopy();
}

ISocketHandler& Socket::Handler() const
{
#ifdef ENABLE_DETACH
    if (IsDetached())
        return *m_slave_handler;
#endif
    return m_handler;
}

ISocketHandler& Socket::MasterHandler() const
{
    return m_handler;
}

ipaddr_t Socket::GetRemoteIP4()
{
    ipaddr_t l = 0;
#ifdef ENABLE_IPV6
    if (m_ipv6)
    {
        Handler().LogError(this, "GetRemoteIP4", 0, "get ipv4 address for ipv6 socket", LOG_LEVEL_WARNING);
    }
#endif
    if (m_remote_address.get() != NULL)
    {
        struct sockaddr *p = *m_remote_address;
        struct sockaddr_in *sa = (struct sockaddr_in *)p;
        memcpy(&l, &sa -> sin_addr, sizeof(struct in_addr));
    }
    return l;
}

#ifdef ENABLE_IPV6
#ifdef IPPROTO_IPV6
struct in6_addr Socket::GetRemoteIP6()
{
    if (!m_ipv6)
    {
        Handler().LogError(this, "GetRemoteIP6", 0, "get ipv6 address for ipv4 socket", LOG_LEVEL_WARNING);
    }
    struct sockaddr_in6 fail;
    if (m_remote_address.get() != NULL)
    {
        struct sockaddr *p = *m_remote_address;
        memcpy(&fail, p, sizeof(struct sockaddr_in6));
    }
    else
    {
        memset(&fail, 0, sizeof(struct sockaddr_in6));
    }
    return fail.sin6_addr;
}
#endif
#endif

port_t Socket::GetRemotePort()
{
    if (!m_remote_address.get())
    {
        return 0;
    }
    return m_remote_address -> GetPort();
}

std::string Socket::GetRemoteAddress()
{
    if (!m_remote_address.get())
    {
        return "";
    }
    return m_remote_address -> Convert(false);
}

std::string Socket::GetRemoteHostname()
{
    if (!m_remote_address.get())
    {
        return "";
    }
    return m_remote_address -> Reverse();
}

bool Socket::SetNonblocking(bool bNb)
{
#ifdef _WIN32
    unsigned long l = bNb ? 1 : 0;
    int n = ioctlsocket(m_socket, FIONBIO, &l);
    if (n != 0)
    {
        Handler().LogError(this, "ioctlsocket(FIONBIO)", Errno, "");
        return false;
    }
    return true;
#else
    if (bNb)
    {
        if (fcntl(m_socket, F_SETFL, O_NONBLOCK) == -1)
        {
            Handler().LogError(this, "fcntl(F_SETFL, O_NONBLOCK)", Errno, StrError(Errno), LOG_LEVEL_ERROR);
            return false;
        }
    }
    else
    {
        if (fcntl(m_socket, F_SETFL, 0) == -1)
        {
            Handler().LogError(this, "fcntl(F_SETFL, 0)", Errno, StrError(Errno), LOG_LEVEL_ERROR);
            return false;
        }
    }
    return true;
#endif
}

bool Socket::SetNonblocking(bool bNb, SOCKET s)
{
#ifdef _WIN32
    unsigned long l = bNb ? 1 : 0;
    int n = ioctlsocket(s, FIONBIO, &l);
    if (n != 0)
    {
        Handler().LogError(this, "ioctlsocket(FIONBIO)", Errno, "");
        return false;
    }
    return true;
#else
    if (bNb)
    {
        if (fcntl(s, F_SETFL, O_NONBLOCK) == -1)
        {
            Handler().LogError(this, "fcntl(F_SETFL, O_NONBLOCK)", Errno, StrError(Errno), LOG_LEVEL_ERROR);
            return false;
        }
    }
    else
    {
        if (fcntl(s, F_SETFL, 0) == -1)
        {
            Handler().LogError(this, "fcntl(F_SETFL, 0)", Errno, StrError(Errno), LOG_LEVEL_ERROR);
            return false;
        }
    }
    return true;
#endif
}

void Socket::Set(bool bRead, bool bWrite, bool bException)
{
    Handler().Set(m_socket, bRead, bWrite, bException);
}

bool Socket::Ready()
{
    if (m_socket != INVALID_SOCKET && !CloseAndDelete())
        return true;
    return false;
}

void Socket::OnLine(const std::string& )
{
}

void Socket::OnConnectFailed()
{
}

Socket *Socket::GetParent()
{
    return m_parent;
}

void Socket::SetParent(Socket *x)
{
    m_parent = x;
}

port_t Socket::GetPort()
{
    Handler().LogError(this, "GetPort", 0, "GetPort only implemented for ListenSocket", LOG_LEVEL_WARNING);
    return 0;
}

bool Socket::OnConnectRetry()
{
    return true;
}

#ifdef ENABLE_RECONNECT
void Socket::OnReconnect()
{
}
#endif

time_t Socket::Uptime()
{
    return time(NULL) - m_tCreate;
}

#ifdef ENABLE_IPV6
void Socket::SetIpv6(bool x)
{
    m_ipv6 = x;
}

bool Socket::IsIpv6()
{
    return m_ipv6;
}
#endif

void Socket::DisableRead(bool x)
{
    m_b_disable_read = x;
}

bool Socket::IsDisableRead()
{
    return m_b_disable_read;
}

void Socket::SendBuf(const char *,size_t,int)
{
}

void Socket::Send(const std::string&,int)
{
}

void Socket::SetConnected(bool x)
{
    m_connected = x;
}

bool Socket::IsConnected()
{
    return m_connected;
}

void Socket::OnDisconnect()
{
}

void Socket::SetLost()
{
    m_bLost = true;
}

bool Socket::Lost()
{
    return m_bLost;
}

void Socket::SetErasedByHandler(bool x)
{
    m_b_erased_by_handler = x;
}

bool Socket::ErasedByHandler()
{
    return m_b_erased_by_handler;
}

time_t Socket::TimeSinceClose()
{
    return time(NULL) - m_tClose;
}

void Socket::SetClientRemoteAddress(SocketAddress& ad)
{
    if (!ad.IsValid())
    {
        Handler().LogError(this, "SetClientRemoteAddress", 0, "remote address not valid", LOG_LEVEL_ERROR);
    }
    m_client_remote_address = ad.GetCopy();
}

std::auto_ptr<SocketAddress> Socket::GetClientRemoteAddress()
{
    if (!m_client_remote_address.get())
    {
        Handler().LogError(this, "GetClientRemoteAddress", 0, "remote address not yet set", LOG_LEVEL_ERROR);
    }
    return m_client_remote_address -> GetCopy();
}

uint64_t Socket::GetBytesSent(bool)
{
    return 0;
}

uint64_t Socket::GetBytesReceived(bool)
{
    return 0;
}

#ifdef HAVE_OPENSSL
void Socket::OnSSLConnect()
{
}

void Socket::OnSSLAccept()
{
}

bool Socket::SSLNegotiate()
{
    return false;
}

bool Socket::IsSSL()
{
    return m_b_enable_ssl;
}

void Socket::EnableSSL(bool x)
{
    m_b_enable_ssl = x;
}

bool Socket::IsSSLNegotiate()
{
    return m_b_ssl;
}

void Socket::SetSSLNegotiate(bool x)
{
    m_b_ssl = x;
}

bool Socket::IsSSLServer()
{
    return m_b_ssl_server;
}

void Socket::SetSSLServer(bool x)
{
    m_b_ssl_server = x;
}

void Socket::OnSSLConnectFailed()
{
}

void Socket::OnSSLAcceptFailed()
{
}
#endif // HAVE_OPENSSL

#ifdef ENABLE_POOL
void Socket::CopyConnection(Socket *sock)
{
    Attach( sock -> GetSocket() );
#ifdef ENABLE_IPV6
    SetIpv6( sock -> IsIpv6() );
#endif
    SetSocketType( sock -> GetSocketType() );
    SetSocketProtocol( sock -> GetSocketProtocol() );

    SetClientRemoteAddress( *sock -> GetClientRemoteAddress() );
    SetRemoteAddress( *sock -> GetRemoteSocketAddress() );
}

void Socket::SetIsClient()
{
    m_bClient = true;
}

void Socket::SetSocketType(int x)
{
    m_socket_type = x;
}

int Socket::GetSocketType()
{
    return m_socket_type;
}

void Socket::SetSocketProtocol(const std::string& x)
{
    m_socket_protocol = x;
}

const std::string& Socket::GetSocketProtocol()
{
    return m_socket_protocol;
}

void Socket::SetRetain()
{
    if (m_bClient) m_bRetain = true;
}

bool Socket::Retain()
{
    return m_bRetain;
}

#endif // ENABLE_POOL

#ifdef ENABLE_SOCKS4
void Socket::OnSocks4Connect()
{
    Handler().LogError(this, "OnSocks4Connect", 0, "Use with TcpSocket only");
}

void Socket::OnSocks4ConnectFailed()
{
    Handler().LogError(this, "OnSocks4ConnectFailed", 0, "Use with TcpSocket only");
}

bool Socket::OnSocks4Read()
{
    Handler().LogError(this, "OnSocks4Read", 0, "Use with TcpSocket only");
    return true;
}

void Socket::SetSocks4Host(const std::string& host)
{
    Utility::u2ip(host, m_socks4_host);
}

bool Socket::Socks4()
{
    return m_bSocks4;
}

void Socket::SetSocks4(bool x)
{
    m_bSocks4 = x;
}

void Socket::SetSocks4Host(ipaddr_t a)
{
    m_socks4_host = a;
}

void Socket::SetSocks4Port(port_t p)
{
    m_socks4_port = p;
}

void Socket::SetSocks4Userid(const std::string& x)
{
    m_socks4_userid = x;
}

ipaddr_t Socket::GetSocks4Host()
{
    return m_socks4_host;
}

port_t Socket::GetSocks4Port()
{
    return m_socks4_port;
}

const std::string& Socket::GetSocks4Userid()
{
    return m_socks4_userid;
}
#endif // ENABLE_SOCKS4

#ifdef ENABLE_DETACH
bool Socket::Detach()
{
    if (!DeleteByHandler())
        return false;
    if (m_pThread)
        return false;
    if (m_detached)
        return false;
    SetDetach();
    return true;
}

void Socket::DetachSocket()
{
    SetDetached();
    m_pThread = new SocketThread(this);
    m_pThread -> SetRelease(true);
}

void Socket::OnDetached()
{
}

void Socket::SetDetach(bool x)
{
    Handler().AddList(m_socket, LIST_DETACH, x);
    m_detach = x;
}

bool Socket::IsDetach()
{
    return m_detach;
}

void Socket::SetDetached(bool x)
{
    m_detached = x;
}

const bool Socket::IsDetached() const
{
    return m_detached;
}

void Socket::SetSlaveHandler(ISocketHandler *p)
{
    m_slave_handler = p;
}

Socket::SocketThread::SocketThread(Socket *p)
:Thread(false)
,m_socket(p)
{
    // Creator will release
}

Socket::SocketThread::~SocketThread()
{
    if (IsRunning())
    {
        SetRelease(true);
        SetRunning(false);
#ifdef _WIN32
        Sleep(1000);
#else
        sleep(1);
#endif
    }
}

void Socket::SocketThread::Run()
{
    SocketHandler h;
    h.SetSlave();
    h.Add(m_socket);
    m_socket -> SetSlaveHandler(&h);
    m_socket -> OnDetached();
    while (h.GetCount() && IsRunning())
    {
        h.Select(0, 500000);
    }
    // m_socket now deleted oops
    // yeah oops m_socket delete its socket thread, that means this
    // so Socket will no longer delete its socket thread, instead we do this:
    SetDeleteOnExit();
}
#endif // ENABLE_DETACH

#ifdef ENABLE_RESOLVER
int Socket::Resolve(const std::string& host,port_t port)
{
    return Handler().Resolve(this, host, port);
}

#ifdef ENABLE_IPV6
int Socket::Resolve6(const std::string& host,port_t port)
{
    return Handler().Resolve6(this, host, port);
}
#endif

int Socket::Resolve(ipaddr_t a)
{
    return Handler().Resolve(this, a);
}

#ifdef ENABLE_IPV6
int Socket::Resolve(in6_addr& a)
{
    return Handler().Resolve(this, a);
}
#endif

void Socket::OnResolved(int,ipaddr_t,port_t)
{
}

#ifdef ENABLE_IPV6
void Socket::OnResolved(int,in6_addr&,port_t)
{
}
#endif

void Socket::OnReverseResolved(int,const std::string&)
{
}

void Socket::OnResolveFailed(int)
{
}
#endif // ENABLE_RESOLVER

/* IP options */

bool Socket::SetIpOptions(const void *p, socklen_t len)
{
#ifdef IP_OPTIONS
    if (setsockopt(GetSocket(), IPPROTO_IP, IP_OPTIONS, (char *)p, len) == -1)
    {
        Handler().LogError(this, "setsockopt(IPPROTO_IP, IP_OPTIONS)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
#else
    Handler().LogError(this, "ip option not available", 0, "IP_OPTIONS", LOG_LEVEL_INFO);
    return false;
#endif
}

#ifdef IP_PKTINFO
bool Socket::SetIpPktinfo(bool x)
{
    int optval = x ? 1 : 0;
    if (setsockopt(GetSocket(), IPPROTO_IP, IP_PKTINFO, (char *)&optval, sizeof(optval)) == -1)
    {
        Handler().LogError(this, "setsockopt(IPPROTO_IP, IP_PKTINFO)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
}
#endif

#ifdef IP_RECVTOS
bool Socket::SetIpRecvTOS(bool x)
{
    int optval = x ? 1 : 0;
    if (setsockopt(GetSocket(), IPPROTO_IP, IP_RECVTOS, (char *)&optval, sizeof(optval)) == -1)
    {
        Handler().LogError(this, "setsockopt(IPPROTO_IP, IP_RECVTOS)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
}
#endif

#ifdef IP_RECVTTL
bool Socket::SetIpRecvTTL(bool x)
{
    int optval = x ? 1 : 0;
    if (setsockopt(GetSocket(), IPPROTO_IP, IP_RECVTTL, (char *)&optval, sizeof(optval)) == -1)
    {
        Handler().LogError(this, "setsockopt(IPPROTO_IP, IP_RECVTTL)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
}
#endif

#ifdef IP_RECVOPTS
bool Socket::SetIpRecvopts(bool x)
{
    int optval = x ? 1 : 0;
    if (setsockopt(GetSocket(), IPPROTO_IP, IP_RECVOPTS, (char *)&optval, sizeof(optval)) == -1)
    {
        Handler().LogError(this, "setsockopt(IPPROTO_IP, IP_RECVOPTS)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
}
#endif

#ifdef IP_RETOPTS
bool Socket::SetIpRetopts(bool x)
{
    int optval = x ? 1 : 0;
    if (setsockopt(GetSocket(), IPPROTO_IP, IP_RETOPTS, (char *)&optval, sizeof(optval)) == -1)
    {
        Handler().LogError(this, "setsockopt(IPPROTO_IP, IP_RETOPTS)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
}
#endif

bool Socket::SetIpTOS(unsigned char tos)
{
#ifdef IP_TOS
    if (setsockopt(GetSocket(), IPPROTO_IP, IP_TOS, (char *)&tos, sizeof(tos)) == -1)
    {
        Handler().LogError(this, "setsockopt(IPPROTO_IP, IP_TOS)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
#else
    Handler().LogError(this, "ip option not available", 0, "IP_TOS", LOG_LEVEL_INFO);
    return false;
#endif
}

unsigned char Socket::IpTOS()
{
    unsigned char tos = 0;
#ifdef IP_TOS
    socklen_t len = sizeof(tos);
    if (getsockopt(GetSocket(), IPPROTO_IP, IP_TOS, (char *)&tos, &len) == -1)
    {
        Handler().LogError(this, "getsockopt(IPPROTO_IP, IP_TOS)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
    }
#else
    Handler().LogError(this, "ip option not available", 0, "IP_TOS", LOG_LEVEL_INFO);
#endif
    return tos;
}

bool Socket::SetIpTTL(int ttl)
{
#ifdef IP_TTL
    if (setsockopt(GetSocket(), IPPROTO_IP, IP_TTL, (char *)&ttl, sizeof(ttl)) == -1)
    {
        Handler().LogError(this, "setsockopt(IPPROTO_IP, IP_TTL)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
#else
    Handler().LogError(this, "ip option not available", 0, "IP_TTL", LOG_LEVEL_INFO);
    return false;
#endif
}

int Socket::IpTTL()
{
    int ttl = 0;
#ifdef IP_TTL
    socklen_t len = sizeof(ttl);
    if (getsockopt(GetSocket(), IPPROTO_IP, IP_TTL, (char *)&ttl, &len) == -1)
    {
        Handler().LogError(this, "getsockopt(IPPROTO_IP, IP_TTL)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
    }
#else
    Handler().LogError(this, "ip option not available", 0, "IP_TTL", LOG_LEVEL_INFO);
#endif
    return ttl;
}

bool Socket::SetIpHdrincl(bool x)
{
#ifdef IP_HDRINCL
    int optval = x ? 1 : 0;
    if (setsockopt(GetSocket(), IPPROTO_IP, IP_HDRINCL, (char *)&optval, sizeof(optval)) == -1)
    {
        Handler().LogError(this, "setsockopt(IPPROTO_IP, IP_HDRINCL)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
#else
    Handler().LogError(this, "ip option not available", 0, "IP_HDRINCL", LOG_LEVEL_INFO);
    return false;
#endif
}

#ifdef IP_RECVERR
bool Socket::SetIpRecverr(bool x)
{
    int optval = x ? 1 : 0;
    if (setsockopt(GetSocket(), IPPROTO_IP, IP_RECVERR, (char *)&optval, sizeof(optval)) == -1)
    {
        Handler().LogError(this, "setsockopt(IPPROTO_IP, IP_RECVERR)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
}
#endif

#ifdef IP_MTU_DISCOVER
bool Socket::SetIpMtudiscover(bool x)
{
    int optval = x ? 1 : 0;
    if (setsockopt(GetSocket(), IPPROTO_IP, IP_MTU_DISCOVER, (char *)&optval, sizeof(optval)) == -1)
    {
        Handler().LogError(this, "setsockopt(IPPROTO_IP, IP_MTU_DISCOVER)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
}
#endif

#ifdef IP_MTU
int Socket::IpMtu()
{
    int mtu = 0;
    socklen_t len = sizeof(mtu);
    if (getsockopt(GetSocket(), IPPROTO_IP, IP_MTU, (char *)&mtu, &len) == -1)
    {
        Handler().LogError(this, "getsockopt(IPPROTO_IP, IP_MTU)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
    }
    return mtu;
}
#endif

#ifdef IP_ROUTER_ALERT
bool Socket::SetIpRouterAlert(bool x)
{
    int optval = x ? 1 : 0;
    if (setsockopt(GetSocket(), IPPROTO_IP, IP_ROUTER_ALERT, (char *)&optval, sizeof(optval)) == -1)
    {
        Handler().LogError(this, "setsockopt(IPPROTO_IP, IP_ROUTER_ALERT)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
}
#endif

bool Socket::SetIpMulticastTTL(int ttl)
{
#ifdef IP_MULTICAST_TTL
    if (setsockopt(GetSocket(), IPPROTO_IP, IP_MULTICAST_TTL, (char *)&ttl, sizeof(ttl)) == -1)
    {
        Handler().LogError(this, "setsockopt(IPPROTO_IP, IP_MULTICAST_TTL)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
#else
    Handler().LogError(this, "ip option not available", 0, "IP_MULTICAST_TTL", LOG_LEVEL_INFO);
    return false;
#endif
}

int Socket::IpMulticastTTL()
{
    int ttl = 0;
#ifdef IP_MULTICAST_TTL
    socklen_t len = sizeof(ttl);
    if (getsockopt(GetSocket(), IPPROTO_IP, IP_MULTICAST_TTL, (char *)&ttl, &len) == -1)
    {
        Handler().LogError(this, "getsockopt(IPPROTO_IP, IP_MULTICAST_TTL)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
    }
#else
    Handler().LogError(this, "ip option not available", 0, "IP_MULTICAST_TTL", LOG_LEVEL_INFO);
#endif
    return ttl;
}

bool Socket::SetMulticastLoop(bool x)
{
#ifdef IP_MULTICAST_LOOP
    int optval = x ? 1 : 0;
    if (setsockopt(GetSocket(), IPPROTO_IP, IP_MULTICAST_LOOP, (char *)&optval, sizeof(optval)) == -1)
    {
        Handler().LogError(this, "setsockopt(IPPROTO_IP, IP_MULTICAST_LOOP)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
#else
    Handler().LogError(this, "ip option not available", 0, "IP_MULTICAST_LOOP", LOG_LEVEL_INFO);
    return false;
#endif
}

#ifdef LINUX
bool Socket::IpAddMembership(struct ip_mreqn& ref)
{
#ifdef IP_ADD_MEMBERSHIP
    if (setsockopt(GetSocket(), IPPROTO_IP, IP_ADD_MEMBERSHIP, (char *)&ref, sizeof(struct ip_mreqn)) == -1)
    {
        Handler().LogError(this, "setsockopt(IPPROTO_IP, IP_ADD_MEMBERSHIP)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
#else
    Handler().LogError(this, "ip option not available", 0, "IP_ADD_MEMBERSHIP", LOG_LEVEL_INFO);
    return false;
#endif
}
#endif

bool Socket::IpAddMembership(struct ip_mreq& ref)
{
#ifdef IP_ADD_MEMBERSHIP
    if (setsockopt(GetSocket(), IPPROTO_IP, IP_ADD_MEMBERSHIP, (char *)&ref, sizeof(struct ip_mreq)) == -1)
    {
        Handler().LogError(this, "setsockopt(IPPROTO_IP, IP_ADD_MEMBERSHIP)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
#else
    Handler().LogError(this, "ip option not available", 0, "IP_ADD_MEMBERSHIP", LOG_LEVEL_INFO);
    return false;
#endif
}

#ifdef LINUX
bool Socket::IpDropMembership(struct ip_mreqn& ref)
{
#ifdef IP_DROP_MEMBERSHIP
    if (setsockopt(GetSocket(), IPPROTO_IP, IP_DROP_MEMBERSHIP, (char *)&ref, sizeof(struct ip_mreqn)) == -1)
    {
        Handler().LogError(this, "setsockopt(IPPROTO_IP, IP_DROP_MEMBERSHIP)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
#else
    Handler().LogError(this, "ip option not available", 0, "IP_DROP_MEMBERSHIP", LOG_LEVEL_INFO);
    return false;
#endif
}
#endif

bool Socket::IpDropMembership(struct ip_mreq& ref)
{
#ifdef IP_DROP_MEMBERSHIP
    if (setsockopt(GetSocket(), IPPROTO_IP, IP_DROP_MEMBERSHIP, (char *)&ref, sizeof(struct ip_mreq)) == -1)
    {
        Handler().LogError(this, "setsockopt(IPPROTO_IP, IP_DROP_MEMBERSHIP)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
#else
    Handler().LogError(this, "ip option not available", 0, "IP_DROP_MEMBERSHIP", LOG_LEVEL_INFO);
    return false;
#endif
}

/* SOCKET options */

bool Socket::SetSoReuseaddr(bool x)
{
#ifdef SO_REUSEADDR
    int optval = x ? 1 : 0;
    if (setsockopt(GetSocket(), SOL_SOCKET, SO_REUSEADDR, (char *)&optval, sizeof(optval)) == -1)
    {
        Handler().LogError(this, "setsockopt(SOL_SOCKET, SO_REUSEADDR)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
#else
    Handler().LogError(this, "socket option not available", 0, "SO_REUSEADDR", LOG_LEVEL_INFO);
    return false;
#endif
}

bool Socket::SetSoKeepalive(bool x)
{
#ifdef SO_KEEPALIVE
    int optval = x ? 1 : 0;
    if (setsockopt(GetSocket(), SOL_SOCKET, SO_KEEPALIVE, (char *)&optval, sizeof(optval)) == -1)
    {
        Handler().LogError(this, "setsockopt(SOL_SOCKET, SO_KEEPALIVE)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
#else
    Handler().LogError(this, "socket option not available", 0, "SO_KEEPALIVE", LOG_LEVEL_INFO);
    return false;
#endif
}

#ifdef SO_NOSIGPIPE
bool Socket::SetSoNosigpipe(bool x)
{
    int optval = x ? 1 : 0;
    if (setsockopt(GetSocket(), SOL_SOCKET, SO_NOSIGPIPE, (char *)&optval, sizeof(optval)) == -1)
    {
        Handler().LogError(this, "setsockopt(SOL_SOCKET, SO_NOSIGPIPE)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
}
#endif

bool Socket::SoAcceptconn()
{
    int value = 0;
#ifdef SO_ACCEPTCONN
    socklen_t len = sizeof(value);
    if (getsockopt(GetSocket(), SOL_SOCKET, SO_ACCEPTCONN, (char *)&value, &len) == -1)
    {
        Handler().LogError(this, "getsockopt(SOL_SOCKET, SO_ACCEPTCONN)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
    }
#else
    Handler().LogError(this, "socket option not available", 0, "SO_ACCEPTCONN", LOG_LEVEL_INFO);
#endif
    return value ? true : false;
}

#ifdef SO_BSDCOMPAT
bool Socket::SetSoBsdcompat(bool x)
{
    int optval = x ? 1 : 0;
    if (setsockopt(GetSocket(), SOL_SOCKET, SO_BSDCOMPAT, (char *)&optval, sizeof(optval)) == -1)
    {
        Handler().LogError(this, "setsockopt(SOL_SOCKET, SO_BSDCOMPAT)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
}
#endif

#ifdef SO_BINDTODEVICE
bool Socket::SetSoBindtodevice(const std::string& intf)
{
    if (setsockopt(GetSocket(), SOL_SOCKET, SO_BINDTODEVICE, (char *)intf.c_str(), intf.size()) == -1)
    {
        Handler().LogError(this, "setsockopt(SOL_SOCKET, SO_BINDTODEVICE)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
}
#endif

bool Socket::SetSoBroadcast(bool x)
{
#ifdef SO_BROADCAST
    int optval = x ? 1 : 0;
    if (setsockopt(GetSocket(), SOL_SOCKET, SO_BROADCAST, (char *)&optval, sizeof(optval)) == -1)
    {
        Handler().LogError(this, "setsockopt(SOL_SOCKET, SO_BROADCAST)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
#else
    Handler().LogError(this, "socket option not available", 0, "SO_BROADCAST", LOG_LEVEL_INFO);
    return false;
#endif
}

bool Socket::SetSoDebug(bool x)
{
#ifdef SO_DEBUG
    int optval = x ? 1 : 0;
    if (setsockopt(GetSocket(), SOL_SOCKET, SO_DEBUG, (char *)&optval, sizeof(optval)) == -1)
    {
        Handler().LogError(this, "setsockopt(SOL_SOCKET, SO_DEBUG)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
#else
    Handler().LogError(this, "socket option not available", 0, "SO_DEBUG", LOG_LEVEL_INFO);
    return false;
#endif
}

int Socket::SoError()
{
    int value = 0;
#ifdef SO_ERROR
    socklen_t len = sizeof(value);
    if (getsockopt(GetSocket(), SOL_SOCKET, SO_ERROR, (char *)&value, &len) == -1)
    {
        Handler().LogError(this, "getsockopt(SOL_SOCKET, SO_ERROR)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
    }
#else
    Handler().LogError(this, "socket option not available", 0, "SO_ERROR", LOG_LEVEL_INFO);
#endif
    return value;
}

bool Socket::SetSoDontroute(bool x)
{
#ifdef SO_DONTROUTE
    int optval = x ? 1 : 0;
    if (setsockopt(GetSocket(), SOL_SOCKET, SO_DONTROUTE, (char *)&optval, sizeof(optval)) == -1)
    {
        Handler().LogError(this, "setsockopt(SOL_SOCKET, SO_DONTROUTE)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
#else
    Handler().LogError(this, "socket option not available", 0, "SO_DONTROUTE", LOG_LEVEL_INFO);
    return false;
#endif
}

bool Socket::SetSoLinger(int onoff, int linger)
{
#ifdef SO_LINGER
    struct linger stl;
    stl.l_onoff = onoff;
    stl.l_linger = linger;
    if (setsockopt(GetSocket(), SOL_SOCKET, SO_LINGER, (char *)&stl, sizeof(stl)) == -1)
    {
        Handler().LogError(this, "setsockopt(SOL_SOCKET, SO_LINGER)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
#else
    Handler().LogError(this, "socket option not available", 0, "SO_LINGER", LOG_LEVEL_INFO);
    return false;
#endif
}

bool Socket::SetSoOobinline(bool x)
{
#ifdef SO_OOBINLINE
    int optval = x ? 1 : 0;
    if (setsockopt(GetSocket(), SOL_SOCKET, SO_OOBINLINE, (char *)&optval, sizeof(optval)) == -1)
    {
        Handler().LogError(this, "setsockopt(SOL_SOCKET, SO_OOBINLINE)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
#else
    Handler().LogError(this, "socket option not available", 0, "SO_OOBINLINE", LOG_LEVEL_INFO);
    return false;
#endif
}

#ifdef SO_PASSCRED
bool Socket::SetSoPasscred(bool x)
{
    int optval = x ? 1 : 0;
    if (setsockopt(GetSocket(), SOL_SOCKET, SO_PASSCRED, (char *)&optval, sizeof(optval)) == -1)
    {
        Handler().LogError(this, "setsockopt(SOL_SOCKET, SO_PASSCRED)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
}
#endif

#ifdef SO_PEERCRED
bool Socket::SoPeercred(struct ucred& ucr)
{
    if (setsockopt(GetSocket(), SOL_SOCKET, SO_PEERCRED, (char *)&ucr, sizeof(ucr)) == -1)
    {
        Handler().LogError(this, "setsockopt(SOL_SOCKET, SO_PEERCRED)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
}
#endif

#ifdef SO_PRIORITY
bool Socket::SetSoPriority(int x)
{
    if (setsockopt(GetSocket(), SOL_SOCKET, SO_PRIORITY, (char *)&x, sizeof(x)) == -1)
    {
        Handler().LogError(this, "setsockopt(SOL_SOCKET, SO_PRIORITY)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
}
#endif

bool Socket::SetSoRcvlowat(int x)
{
#ifdef SO_RCVLOWAT
    if (setsockopt(GetSocket(), SOL_SOCKET, SO_RCVLOWAT, (char *)&x, sizeof(x)) == -1)
    {
        Handler().LogError(this, "setsockopt(SOL_SOCKET, SO_RCVLOWAT)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
#else
    Handler().LogError(this, "socket option not available", 0, "SO_RCVLOWAT", LOG_LEVEL_INFO);
    return false;
#endif
}

bool Socket::SetSoSndlowat(int x)
{
#ifdef SO_SNDLOWAT
    if (setsockopt(GetSocket(), SOL_SOCKET, SO_SNDLOWAT, (char *)&x, sizeof(x)) == -1)
    {
        Handler().LogError(this, "setsockopt(SOL_SOCKET, SO_SNDLOWAT)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
#else
    Handler().LogError(this, "socket option not available", 0, "SO_SNDLOWAT", LOG_LEVEL_INFO);
    return false;
#endif
}

bool Socket::SetSoRcvtimeo(struct timeval& tv)
{
#ifdef SO_RCVTIMEO
    if (setsockopt(GetSocket(), SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv)) == -1)
    {
        Handler().LogError(this, "setsockopt(SOL_SOCKET, SO_RCVTIMEO)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
#else
    Handler().LogError(this, "socket option not available", 0, "SO_RCVTIMEO", LOG_LEVEL_INFO);
    return false;
#endif
}

bool Socket::SetSoSndtimeo(struct timeval& tv)
{
#ifdef SO_SNDTIMEO
    if (setsockopt(GetSocket(), SOL_SOCKET, SO_SNDTIMEO, (char *)&tv, sizeof(tv)) == -1)
    {
        Handler().LogError(this, "setsockopt(SOL_SOCKET, SO_SNDTIMEO)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
#else
    Handler().LogError(this, "socket option not available", 0, "SO_SNDTIMEO", LOG_LEVEL_INFO);
    return false;
#endif
}

bool Socket::SetSoRcvbuf(int x)
{
#ifdef SO_RCVBUF
    if (setsockopt(GetSocket(), SOL_SOCKET, SO_RCVBUF, (char *)&x, sizeof(x)) == -1)
    {
        Handler().LogError(this, "setsockopt(SOL_SOCKET, SO_RCVBUF)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
#else
    Handler().LogError(this, "socket option not available", 0, "SO_RCVBUF", LOG_LEVEL_INFO);
    return false;
#endif
}

int Socket::SoRcvbuf()
{
    int value = 0;
#ifdef SO_RCVBUF
    socklen_t len = sizeof(value);
    if (getsockopt(GetSocket(), SOL_SOCKET, SO_RCVBUF, (char *)&value, &len) == -1)
    {
        Handler().LogError(this, "getsockopt(SOL_SOCKET, SO_RCVBUF)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
    }
#else
    Handler().LogError(this, "socket option not available", 0, "SO_RCVBUF", LOG_LEVEL_INFO);
#endif
    return value;
}

#ifdef SO_RCVBUFFORCE
bool Socket::SetSoRcvbufforce(int x)
{
    if (setsockopt(GetSocket(), SOL_SOCKET, SO_RCVBUFFORCE, (char *)&x, sizeof(x)) == -1)
    {
        Handler().LogError(this, "setsockopt(SOL_SOCKET, SO_RCVBUFFORCE)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
}
#endif

bool Socket::SetSoSndbuf(int x)
{
#ifdef SO_SNDBUF
    if (setsockopt(GetSocket(), SOL_SOCKET, SO_SNDBUF, (char *)&x, sizeof(x)) == -1)
    {
        Handler().LogError(this, "setsockopt(SOL_SOCKET, SO_SNDBUF)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
#else
    Handler().LogError(this, "socket option not available", 0, "SO_SNDBUF", LOG_LEVEL_INFO);
    return false;
#endif
}

int Socket::SoSndbuf()
{
    int value = 0;
#ifdef SO_SNDBUF
    socklen_t len = sizeof(value);
    if (getsockopt(GetSocket(), SOL_SOCKET, SO_SNDBUF, (char *)&value, &len) == -1)
    {
        Handler().LogError(this, "getsockopt(SOL_SOCKET, SO_SNDBUF)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
    }
#else
    Handler().LogError(this, "socket option not available", 0, "SO_SNDBUF", LOG_LEVEL_INFO);
#endif
    return value;
}

#ifdef SO_SNDBUFFORCE
bool Socket::SetSoSndbufforce(int x)
{
    if (setsockopt(GetSocket(), SOL_SOCKET, SO_SNDBUFFORCE, (char *)&x, sizeof(x)) == -1)
    {
        Handler().LogError(this, "setsockopt(SOL_SOCKET, SO_SNDBUFFORCE)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
}
#endif

#ifdef SO_TIMESTAMP
bool Socket::SetSoTimestamp(bool x)
{
    int optval = x ? 1 : 0;
    if (setsockopt(GetSocket(), SOL_SOCKET, SO_TIMESTAMP, (char *)&optval, sizeof(optval)) == -1)
    {
        Handler().LogError(this, "setsockopt(SOL_SOCKET, SO_TIMESTAMP)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
}
#endif

int Socket::SoType()
{
    int value = 0;
#ifdef SO_TYPE
    socklen_t len = sizeof(value);
    if (getsockopt(GetSocket(), SOL_SOCKET, SO_TYPE, (char *)&value, &len) == -1)
    {
        Handler().LogError(this, "getsockopt(SOL_SOCKET, SO_TYPE)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
    }
#else
    Handler().LogError(this, "socket option not available", 0, "SO_TYPE", LOG_LEVEL_INFO);
#endif
    return value;
}

#ifdef ENABLE_TRIGGERS
void Socket::Subscribe(int id)
{
    Handler().Subscribe(id, this);
}

void Socket::Unsubscribe(int id)
{
    Handler().Unsubscribe(id, this);
}

void Socket::OnTrigger(int, const TriggerData&)
{
}

void Socket::OnCancelled(int)
{
}
#endif

void Socket::SetTimeout(time_t secs)
{
    if (!secs)
    {
        Handler().AddList(m_socket, LIST_TIMEOUT, false);
        return;
    }
    Handler().AddList(m_socket, LIST_TIMEOUT, true);
    m_timeout_start = time(NULL);
    m_timeout_limit = secs;
}

void Socket::OnTimeout()
{
}

void Socket::OnConnectTimeout()
{
}

bool Socket::Timeout(time_t tnow)
{
    if (tnow - m_timeout_start > m_timeout_limit)
        return true;
    return false;
}

/** Returns local port number for bound socket file descriptor. */
port_t Socket::GetSockPort()
{
#ifdef ENABLE_IPV6
#ifdef IPPROTO_IPV6
    if (IsIpv6())
    {
        struct sockaddr_in6 sa;
        socklen_t sockaddr_length = sizeof(struct sockaddr_in6);
        if (getsockname(GetSocket(), (struct sockaddr *)&sa, (socklen_t*)&sockaddr_length) == -1)
            memset(&sa, 0, sizeof(sa));
        return ntohs(sa.sin6_port);
    }
#endif
#endif
    struct sockaddr_in sa;
    socklen_t sockaddr_length = sizeof(struct sockaddr_in);
    if (getsockname(GetSocket(), (struct sockaddr *)&sa, (socklen_t*)&sockaddr_length) == -1)
        memset(&sa, 0, sizeof(sa));
    return ntohs(sa.sin_port);
}

/** Returns local ipv4 address for bound socket file descriptor. */
ipaddr_t Socket::GetSockIP4()
{
#ifdef ENABLE_IPV6
#ifdef IPPROTO_IPV6
    if (IsIpv6())
    {
        return 0;
    }
#endif
#endif
    struct sockaddr_in sa;
    socklen_t sockaddr_length = sizeof(struct sockaddr_in);
    if (getsockname(GetSocket(), (struct sockaddr *)&sa, (socklen_t*)&sockaddr_length) == -1)
        memset(&sa, 0, sizeof(sa));
    ipaddr_t a;
    memcpy(&a, &sa.sin_addr, 4);
    return a;
}

/** Returns local ipv4 address as text for bound socket file descriptor. */
std::string Socket::GetSockAddress()
{
#ifdef ENABLE_IPV6
#ifdef IPPROTO_IPV6
    if (IsIpv6())
    {
        return "";
    }
#endif
#endif
    struct sockaddr_in sa;
    socklen_t sockaddr_length = sizeof(struct sockaddr_in);
    if (getsockname(GetSocket(), (struct sockaddr *)&sa, (socklen_t*)&sockaddr_length) == -1)
        memset(&sa, 0, sizeof(sa));
    Ipv4Address addr( sa );
    return addr.Convert();
}

#ifdef ENABLE_IPV6
#ifdef IPPROTO_IPV6
/** Returns local ipv6 address for bound socket file descriptor. */
struct in6_addr Socket::GetSockIP6()
{
    if (IsIpv6())
    {
        struct sockaddr_in6 sa;
        socklen_t sockaddr_length = sizeof(struct sockaddr_in6);
        if (getsockname(GetSocket(), (struct sockaddr *)&sa, (socklen_t*)&sockaddr_length) == -1)
            memset(&sa, 0, sizeof(sa));
        return sa.sin6_addr;
    }
    struct in6_addr a;
    memset(&a, 0, sizeof(a));
    return a;
}

/** Returns local ipv6 address as text for bound socket file descriptor. */
std::string Socket::GetSockAddress6()
{
    if (IsIpv6())
    {
        struct sockaddr_in6 sa;
        socklen_t sockaddr_length = sizeof(struct sockaddr_in6);
        if (getsockname(GetSocket(), (struct sockaddr *)&sa, (socklen_t*)&sockaddr_length) == -1)
            memset(&sa, 0, sizeof(sa));
        Ipv6Address addr( sa );
        return addr.Convert();
    }
    return "";
}
#endif
#endif

#ifdef SOCKETS_NAMESPACE
}
#endif


