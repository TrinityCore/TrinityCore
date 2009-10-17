/** \file TcpSocket.cpp
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
#ifdef _WIN32
#ifdef _MSC_VER
#pragma warning(disable:4786)
#endif
#include <stdlib.h>
#else
#include <errno.h>
#endif
#include "ISocketHandler.h"
#include <fcntl.h>
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#ifdef HAVE_OPENSSL
#include <openssl/rand.h>
#include <openssl/err.h>
#endif
#include <map>
#include <cstdio>
#include "TcpSocket.h"
#include "Utility.h"
#include "Ipv4Address.h"
#include "Ipv6Address.h"
#include "Mutex.h"
#include "IFile.h"
#ifdef SOCKETS_NAMESPACE
namespace SOCKETS_NAMESPACE {
#endif

//#ifdef _DEBUG
//#define DEB(x) x
//#else
#define DEB(x)
//#endif

// statics
#ifdef HAVE_OPENSSL
SSLInitializer TcpSocket::m_ssl_init;
#endif

// thanks, q
#ifdef _MSC_VER
#pragma warning(disable:4355)
#endif
TcpSocket::TcpSocket(ISocketHandler& h) : StreamSocket(h)
,ibuf(TCP_BUFSIZE_READ)
,m_b_input_buffer_disabled(false)
,m_bytes_sent(0)
,m_bytes_received(0)
,m_skip_c(false)
#ifdef SOCKETS_DYNAMIC_TEMP
,m_buf(new char[TCP_BUFSIZE_READ + 1])
#endif
,m_obuf_top(NULL)
,m_transfer_limit(0)
,m_output_length(0)
#ifdef HAVE_OPENSSL
,m_ssl_ctx(NULL)
,m_ssl(NULL)
,m_sbio(NULL)
#endif
#ifdef ENABLE_SOCKS4
,m_socks4_state(0)
#endif
#ifdef ENABLE_RESOLVER
,m_resolver_id(0)
#endif
#ifdef ENABLE_RECONNECT
,m_b_reconnect(false)
,m_b_is_reconnect(false)
#endif
{
}
#ifdef _MSC_VER
#pragma warning(default:4355)
#endif

#ifdef _MSC_VER
#pragma warning(disable:4355)
#endif
TcpSocket::TcpSocket(ISocketHandler& h,size_t isize,size_t osize) : StreamSocket(h)
,ibuf(isize)
,m_b_input_buffer_disabled(false)
,m_bytes_sent(0)
,m_bytes_received(0)
,m_skip_c(false)
#ifdef SOCKETS_DYNAMIC_TEMP
,m_buf(new char[TCP_BUFSIZE_READ + 1])
#endif
,m_obuf_top(NULL)
,m_transfer_limit(0)
,m_output_length(0)
#ifdef HAVE_OPENSSL
,m_ssl_ctx(NULL)
,m_ssl(NULL)
,m_sbio(NULL)
#endif
#ifdef ENABLE_SOCKS4
,m_socks4_state(0)
#endif
#ifdef ENABLE_RESOLVER
,m_resolver_id(0)
#endif
#ifdef ENABLE_RECONNECT
,m_b_reconnect(false)
,m_b_is_reconnect(false)
#endif
{
}
#ifdef _MSC_VER
#pragma warning(default:4355)
#endif

TcpSocket::~TcpSocket()
{
#ifdef SOCKETS_DYNAMIC_TEMP
    delete[] m_buf;
#endif
    // %! empty m_obuf
    while (m_obuf.size())
    {
        output_l::iterator it = m_obuf.begin();
        OUTPUT *p = *it;
        delete p;
        m_obuf.erase(it);
    }
#ifdef HAVE_OPENSSL
    if (m_ssl)
    {
        SSL_free(m_ssl);
    }
#endif
}

bool TcpSocket::Open(ipaddr_t ip,port_t port,bool skip_socks)
{
    Ipv4Address ad(ip, port);
    Ipv4Address local;
    return Open(ad, local, skip_socks);
}

#ifdef ENABLE_IPV6
#ifdef IPPROTO_IPV6
bool TcpSocket::Open(in6_addr ip,port_t port,bool skip_socks)
{
    Ipv6Address ad(ip, port);
    return Open(ad, skip_socks);
}
#endif
#endif

bool TcpSocket::Open(SocketAddress& ad,bool skip_socks)
{
    Ipv4Address bind_ad("0.0.0.0", 0);
    return Open(ad, bind_ad, skip_socks);
}

bool TcpSocket::Open(SocketAddress& ad,SocketAddress& bind_ad,bool skip_socks)
{
    if (!ad.IsValid())
    {
        Handler().LogError(this, "Open", 0, "Invalid SocketAddress", LOG_LEVEL_FATAL);
        SetCloseAndDelete();
        return false;
    }
    if (Handler().GetCount() >= FD_SETSIZE)
    {
        Handler().LogError(this, "Open", 0, "no space left in fd_set", LOG_LEVEL_FATAL);
        SetCloseAndDelete();
        return false;
    }
    SetConnecting(false);
#ifdef ENABLE_SOCKS4
    SetSocks4(false);
#endif
    // check for pooling
#ifdef ENABLE_POOL
    if (Handler().PoolEnabled())
    {
        ISocketHandler::PoolSocket *pools = Handler().FindConnection(SOCK_STREAM, "tcp", ad);
        if (pools)
        {
            CopyConnection( pools );
            delete pools;
            SetIsClient();
            SetCallOnConnect(); // ISocketHandler must call OnConnect
            Handler().LogError(this, "SetCallOnConnect", 0, "Found pooled connection", LOG_LEVEL_INFO);
            return true;
        }
    }
#endif
    // if not, create new connection
    SOCKET s = CreateSocket(ad.GetFamily(), SOCK_STREAM, "tcp");
    if (s == INVALID_SOCKET)
    {
        return false;
    }
    // socket must be nonblocking for async connect
    if (!SetNonblocking(true, s))
    {
        SetCloseAndDelete();
        closesocket(s);
        return false;
    }
#ifdef ENABLE_POOL
    SetIsClient(); // client because we connect
#endif
    SetClientRemoteAddress(ad);
    int n = 0;
    if (bind_ad.GetPort() != 0)
    {
        bind(s, bind_ad, bind_ad);
    }
#ifdef ENABLE_SOCKS4
    if (!skip_socks && GetSocks4Host() && GetSocks4Port())
    {
        Ipv4Address sa(GetSocks4Host(), GetSocks4Port());
        {
            std::string sockshost;
            Utility::l2ip(GetSocks4Host(), sockshost);
            Handler().LogError(this, "Open", 0, "Connecting to socks4 server @ " + sockshost + ":" +
                Utility::l2string(GetSocks4Port()), LOG_LEVEL_INFO);
        }
        SetSocks4();
        n = connect(s, sa, sa);
        SetRemoteAddress(sa);
    }
    else
#endif
    {
        n = connect(s, ad, ad);
        SetRemoteAddress(ad);
    }
    if (n == -1)
    {
        // check error code that means a connect is in progress
#ifdef _WIN32
        if (Errno == WSAEWOULDBLOCK)
#else
        if (Errno == EINPROGRESS)
#endif
        {
            Attach(s);
            SetConnecting( true ); // this flag will control fd_set's
        }
        else
#ifdef ENABLE_SOCKS4
        if (Socks4() && Handler().Socks4TryDirect() ) // retry
        {
            closesocket(s);
            return Open(ad, true);
        }
        else
#endif
#ifdef ENABLE_RECONNECT
        if (Reconnect())
        {
            Handler().LogError(this, "connect: failed, reconnect pending", Errno, StrError(Errno), LOG_LEVEL_INFO);
            Attach(s);
            SetConnecting( true ); // this flag will control fd_set's
        }
        else
#endif
        {
            Handler().LogError(this, "connect: failed", Errno, StrError(Errno), LOG_LEVEL_FATAL);
            SetCloseAndDelete();
            closesocket(s);
            return false;
        }
    }
    else
    {
        Attach(s);
        SetCallOnConnect(); // ISocketHandler must call OnConnect
    }
    // 'true' means connected or connecting(not yet connected)
    // 'false' means something failed
    return true; //!Connecting();
}

bool TcpSocket::Open(const std::string &host,port_t port)
{
#ifdef ENABLE_IPV6
#ifdef IPPROTO_IPV6
    if (IsIpv6())
    {
#ifdef ENABLE_RESOLVER
        if (!Handler().ResolverEnabled() || Utility::isipv6(host) )
        {
#endif
            in6_addr a;
            if (!Utility::u2ip(host, a))
            {
                SetCloseAndDelete();
                return false;
            }
            Ipv6Address ad(a, port);
            Ipv6Address local;
            return Open(ad, local);
#ifdef ENABLE_RESOLVER
        }
        m_resolver_id = Resolve6(host, port);
        return true;
#endif
    }
#endif
#endif
#ifdef ENABLE_RESOLVER
    if (!Handler().ResolverEnabled() || Utility::isipv4(host) )
    {
#endif
        ipaddr_t l;
        if (!Utility::u2ip(host,l))
        {
            SetCloseAndDelete();
            return false;
        }
        Ipv4Address ad(l, port);
        Ipv4Address local;
        return Open(ad, local);
#ifdef ENABLE_RESOLVER
    }
    // resolve using async resolver thread
    m_resolver_id = Resolve(host, port);
    return true;
#endif
}

#ifdef ENABLE_RESOLVER
void TcpSocket::OnResolved(int id,ipaddr_t a,port_t port)
{
DEB(    fprintf(stderr, "TcpSocket::OnResolved id %d addr %x port %d\n", id, a, port);)
    if (id == m_resolver_id)
    {
        if (a && port)
        {
            Ipv4Address ad(a, port);
            Ipv4Address local;
            if (Open(ad, local))
            {
                if (!Handler().Valid(this))
                {
                    Handler().Add(this);
                }
            }
        }
        else
        {
            Handler().LogError(this, "OnResolved", 0, "Resolver failed", LOG_LEVEL_FATAL);
            SetCloseAndDelete();
        }
    }
    else
    {
        Handler().LogError(this, "OnResolved", id, "Resolver returned wrong job id", LOG_LEVEL_FATAL);
        SetCloseAndDelete();
    }
}

#ifdef ENABLE_IPV6
void TcpSocket::OnResolved(int id,in6_addr& a,port_t port)
{
    if (id == m_resolver_id)
    {
        Ipv6Address ad(a, port);
        if (ad.IsValid())
        {
            Ipv6Address local;
            if (Open(ad, local))
            {
                if (!Handler().Valid(this))
                {
                    Handler().Add(this);
                }
            }
        }
    }
    else
    {
        Handler().LogError(this, "OnResolved", id, "Resolver returned wrong job id", LOG_LEVEL_FATAL);
        SetCloseAndDelete();
    }
}
#endif
#endif

void TcpSocket::OnRead()
{
    int n = 0;
#ifdef SOCKETS_DYNAMIC_TEMP
    char *buf = m_buf;
#else
    char buf[TCP_BUFSIZE_READ];
#endif
#ifdef HAVE_OPENSSL
    if (IsSSL())
    {
        if (!Ready())
            return;
        n = SSL_read(m_ssl, buf, TCP_BUFSIZE_READ);
        if (n == -1)
        {
            n = SSL_get_error(m_ssl, n);
            switch (n)
            {
            case SSL_ERROR_NONE:
            case SSL_ERROR_WANT_READ:
            case SSL_ERROR_WANT_WRITE:
                break;
            case SSL_ERROR_ZERO_RETURN:
DEB(                fprintf(stderr, "SSL_read() returns zero - closing socket\n");)
                OnDisconnect();
                SetCloseAndDelete(true);
                SetFlushBeforeClose(false);
                SetLost();
                break;
            default:
DEB(                fprintf(stderr, "SSL read problem, errcode = %d\n",n);)
                OnDisconnect();
                SetCloseAndDelete(true);
                SetFlushBeforeClose(false);
                SetLost();
            }
            return;
        }
        else
        if (!n)
        {
            OnDisconnect();
            SetCloseAndDelete(true);
            SetFlushBeforeClose(false);
            SetLost();
            SetShutdown(SHUT_WR);
            return;
        }
        else
        if (n > 0 && n <= TCP_BUFSIZE_READ)
        {
            m_bytes_received += n;
            if (GetTrafficMonitor())
            {
                GetTrafficMonitor() -> fwrite(buf, 1, n);
            }
            if (!m_b_input_buffer_disabled && !ibuf.Write(buf,n))
            {
                Handler().LogError(this, "OnRead(ssl)", 0, "ibuf overflow", LOG_LEVEL_WARNING);
            }
        }
        else
        {
            Handler().LogError(this, "OnRead(ssl)", n, "abnormal value from SSL_read", LOG_LEVEL_ERROR);
        }
    }
    else
#endif // HAVE_OPENSSL
    {
        n = recv(GetSocket(), buf, TCP_BUFSIZE_READ, MSG_NOSIGNAL);
        if (n == -1)
        {
            Handler().LogError(this, "read", Errno, StrError(Errno), LOG_LEVEL_FATAL);
            OnDisconnect();
            SetCloseAndDelete(true);
            SetFlushBeforeClose(false);
            SetLost();
            return;
        }
        else
        if (!n)
        {
            OnDisconnect();
            SetCloseAndDelete(true);
            SetFlushBeforeClose(false);
            SetLost();
            SetShutdown(SHUT_WR);
            return;
        }
        else
        if (n > 0 && n <= TCP_BUFSIZE_READ)
        {
            m_bytes_received += n;
            if (GetTrafficMonitor())
            {
                GetTrafficMonitor() -> fwrite(buf, 1, n);
            }
            if (!m_b_input_buffer_disabled && !ibuf.Write(buf,n))
            {
                Handler().LogError(this, "OnRead", 0, "ibuf overflow", LOG_LEVEL_WARNING);
            }
        }
        else
        {
            Handler().LogError(this, "OnRead", n, "abnormal value from recv", LOG_LEVEL_ERROR);
        }
    }
    //
    OnRead( buf, n );
}

void TcpSocket::OnRead( char *buf, size_t n )
{
    // unbuffered
    if (n > 0 && n <= TCP_BUFSIZE_READ)
    {
        if (LineProtocol())
        {
            buf[n] = 0;
            size_t i = 0;
            if (m_skip_c && (buf[i] == 13 || buf[i] == 10) && buf[i] != m_c)
            {
                m_skip_c = false;
                i++;
            }
            size_t x = i;
            for (; i < n && LineProtocol(); i++)
            {
                while ((buf[i] == 13 || buf[i] == 10) && LineProtocol())
                {
                    char c = buf[i];
                    buf[i] = 0;
                    if (buf[x])
                    {
                        m_line += (buf + x);
                    }
                    OnLine( m_line );
                    i++;
                    m_skip_c = true;
                    m_c = c;
                    if (i < n && (buf[i] == 13 || buf[i] == 10) && buf[i] != c)
                    {
                        m_skip_c = false;
                        i++;
                    }
                    x = i;
                    m_line = "";
                }
                if (!LineProtocol())
                {
                    break;
                }
            }
            if (!LineProtocol())
            {
                if (i < n)
                {
                    OnRawData(buf + i, n - i);
                }
            }
            else
            if (buf[x])
            {
                m_line += (buf + x);
            }
        }
        else
        {
            OnRawData(buf, n);
        }
    }
    if (m_b_input_buffer_disabled)
    {
        return;
    }
    // further processing: socks4
#ifdef ENABLE_SOCKS4
    if (Socks4())
    {
        bool need_more = false;
        while (GetInputLength() && !need_more && !CloseAndDelete())
        {
            need_more = OnSocks4Read();
        }
    }
#endif
}

void TcpSocket::OnWriteComplete()
{
}

void TcpSocket::OnWrite()
{
    if (Connecting())
    {
        int err = SoError();
        // don't reset connecting flag on error here, we want the OnConnectFailed timeout later on
        if (!err) // ok
        {
            Set(!IsDisableRead(), false);
            SetConnecting(false);
            SetCallOnConnect();
            return;
        }
        Handler().LogError(this, "tcp: connect failed", err, StrError(err), LOG_LEVEL_FATAL);
        Set(false, false); // no more monitoring because connection failed
        // failed
#ifdef ENABLE_SOCKS4
        if (Socks4())
        {
            // %! leave 'Connecting' flag set?
            OnSocks4ConnectFailed();
            return;
        }
#endif
        if (GetConnectionRetry() == -1 ||
            (GetConnectionRetry() && GetConnectionRetries() < GetConnectionRetry()) )
        {
            // even though the connection failed at once, only retry after
            // the connection timeout.
            // should we even try to connect again, when CheckConnect returns
            // false it's because of a connection error - not a timeout...
            return;
        }
        SetConnecting(false);
        SetCloseAndDelete( true );
        /// \todo state reason why connect failed
        OnConnectFailed();
        return;
    }
    // try send next block in buffer
    // if full block is sent, repeat
    // if all blocks are sent, reset m_wfds
    bool repeat = false;
    size_t sz = m_transfer_limit ? GetOutputLength() : 0;
    do
    {
        output_l::iterator it = m_obuf.begin();
        OUTPUT *p = *it;
        repeat = false;
        int n = TryWrite(p -> Buf(), p -> Len());
        if (n > 0)
        {
            size_t left = p -> Remove(n);
            m_output_length -= n;
            if (!left)
            {
                delete p;
                m_obuf.erase(it);
                if (!m_obuf.size())
                {
                    m_obuf_top = NULL;
                    OnWriteComplete();
                }
                else
                {
                    repeat = true;
                }
            }
        }
    } while (repeat);
    if (m_transfer_limit && sz > m_transfer_limit && GetOutputLength() < m_transfer_limit)
    {
        OnTransferLimit();
    }
    // check output buffer set, set/reset m_wfds accordingly
    {
        bool br;
        bool bw;
        bool bx;
        Handler().Get(GetSocket(), br, bw, bx);
        if (m_obuf.size())
            Set(br, true);
        else
            Set(br, false);
    }
}

int TcpSocket::TryWrite(const char *buf, size_t len)
{
    int n = 0;
#ifdef HAVE_OPENSSL
    if (IsSSL())
    {
        n = SSL_write(m_ssl, buf, (int)len);
        if (n == -1)
        {
            int errnr = SSL_get_error(m_ssl, n);
            if ( errnr != SSL_ERROR_WANT_READ && errnr != SSL_ERROR_WANT_WRITE )
            {
                OnDisconnect();
                SetCloseAndDelete(true);
                SetFlushBeforeClose(false);
                SetLost();
                const char *errbuf = ERR_error_string(errnr, NULL);
                Handler().LogError(this, "OnWrite/SSL_write", errnr, errbuf, LOG_LEVEL_FATAL);
            }
            return 0;
        }
        else
        if (!n)
        {
            OnDisconnect();
            SetCloseAndDelete(true);
            SetFlushBeforeClose(false);
            SetLost();
DEB(            int errnr = SSL_get_error(m_ssl, n);
            const char *errbuf = ERR_error_string(errnr, NULL);
            fprintf(stderr, "SSL_write() returns 0: %d : %s\n",errnr, errbuf);)
        }
    }
    else
#endif // HAVE_OPENSSL
    {
        n = send(GetSocket(), buf, (int)len, MSG_NOSIGNAL);
        if (n == -1)
        {
        // normal error codes:
        // WSAEWOULDBLOCK
        //       EAGAIN or EWOULDBLOCK
#ifdef _WIN32
            if (Errno != WSAEWOULDBLOCK)
#else
            if (Errno != EWOULDBLOCK)
#endif
            {
                Handler().LogError(this, "send", Errno, StrError(Errno), LOG_LEVEL_FATAL);
                OnDisconnect();
                SetCloseAndDelete(true);
                SetFlushBeforeClose(false);
                SetLost();
            }
            return 0;
        }
    }
    if (n > 0)
    {
        m_bytes_sent += n;
        if (GetTrafficMonitor())
        {
            GetTrafficMonitor() -> fwrite(buf, 1, n);
        }
    }
    return n;
}

void TcpSocket::Buffer(const char *buf, size_t len)
{
    size_t ptr = 0;
    m_output_length += len;
    while (ptr < len)
    {
        // buf/len => pbuf/sz
        size_t space = 0;
        if (m_obuf_top && (space = m_obuf_top -> Space()) > 0)
        {
            const char *pbuf = buf + ptr;
            size_t sz = len - ptr;
            if (space >= sz)
            {
                m_obuf_top -> Add(pbuf, sz);
                ptr += sz;
            }
            else
            {
                m_obuf_top -> Add(pbuf, space);
                ptr += space;
            }
        }
        else
        {
            m_obuf_top = new OUTPUT;
            m_obuf.push_back( m_obuf_top );
        }
    }
}

void TcpSocket::Send(const std::string &str,int i)
{
    SendBuf(str.c_str(),str.size(),i);
}

void TcpSocket::SendBuf(const char *buf,size_t len,int)
{
    if (!Ready() && !Connecting())
    {
        Handler().LogError(this, "SendBuf", -1, "Attempt to write to a non-ready socket" ); // warning
        if (GetSocket() == INVALID_SOCKET)
            Handler().LogError(this, "SendBuf", 0, " * GetSocket() == INVALID_SOCKET", LOG_LEVEL_INFO);
        if (Connecting())
            Handler().LogError(this, "SendBuf", 0, " * Connecting()", LOG_LEVEL_INFO);
        if (CloseAndDelete())
            Handler().LogError(this, "SendBuf", 0, " * CloseAndDelete()", LOG_LEVEL_INFO);
        return;
    }
    if (!IsConnected())
    {
        Handler().LogError(this, "SendBuf", -1, "Attempt to write to a non-connected socket, will be sent on connect" ); // warning
        Buffer(buf, len);
        return;
    }
    if (m_obuf_top)
    {
        Buffer(buf, len);
        return;
    }
    int n = TryWrite(buf, len);
    if (n >= 0 && n < (int)len)
    {
        Buffer(buf + n, len - n);
    }
    // if ( data in buffer || !IsConnected )
    // {
    //   add to buffer
    // }
    // else
    // try_send
    // if any data is unsent, buffer it and set m_wfds
    // check output buffer set, set/reset m_wfds accordingly
    {
        bool br;
        bool bw;
        bool bx;
        Handler().Get(GetSocket(), br, bw, bx);
        if (m_obuf.size())
            Set(br, true);
        else
            Set(br, false);
    }
}

void TcpSocket::OnLine(const std::string& )
{
}

#ifdef _MSC_VER
#pragma warning(disable:4355)
#endif
TcpSocket::TcpSocket(const TcpSocket& s)
:StreamSocket(s)
,ibuf(0)
{
}
#ifdef _MSC_VER
#pragma warning(default:4355)
#endif

#ifdef ENABLE_SOCKS4
void TcpSocket::OnSocks4Connect()
{
    char request[1000];
    memset(request, 0, sizeof(request));
    request[0] = 4; // socks v4
    request[1] = 1; // command code: CONNECT
    {
        std::auto_ptr<SocketAddress> ad = GetClientRemoteAddress();
        if (ad.get())
        {
            struct sockaddr *p0 = (struct sockaddr *)*ad;
            struct sockaddr_in *p = (struct sockaddr_in *)p0;
            if (p -> sin_family == AF_INET)
            {
                memcpy(request + 2, &p -> sin_port, 2); // nwbo is ok here
                memcpy(request + 4, &p -> sin_addr, sizeof(struct in_addr));
            }
            else
            {
                /// \todo warn
            }
        }
        else
        {
            /// \todo warn
        }
    }
    strcpy(request + 8, GetSocks4Userid().c_str());
    size_t length = GetSocks4Userid().size() + 8 + 1;
    SendBuf(request, length);
    m_socks4_state = 0;
}

void TcpSocket::OnSocks4ConnectFailed()
{
    Handler().LogError(this,"OnSocks4ConnectFailed",0,"connection to socks4 server failed, trying direct connection",LOG_LEVEL_WARNING);
    if (!Handler().Socks4TryDirect())
    {
        SetConnecting(false);
        SetCloseAndDelete();
        OnConnectFailed(); // just in case
    }
    else
    {
        SetRetryClientConnect();
    }
}

bool TcpSocket::OnSocks4Read()
{
    switch (m_socks4_state)
    {
    case 0:
        ibuf.Read(&m_socks4_vn, 1);
        m_socks4_state = 1;
        break;
    case 1:
        ibuf.Read(&m_socks4_cd, 1);
        m_socks4_state = 2;
        break;
    case 2:
        if (GetInputLength() > 1)
        {
            ibuf.Read( (char *)&m_socks4_dstport, 2);
            m_socks4_state = 3;
        }
        else
        {
            return true;
        }
        break;
    case 3:
        if (GetInputLength() > 3)
        {
            ibuf.Read( (char *)&m_socks4_dstip, 4);
            SetSocks4(false);
            switch (m_socks4_cd)
            {
            case 90:
                OnConnect();
                Handler().LogError(this, "OnSocks4Read", 0, "Connection established", LOG_LEVEL_INFO);
                break;
            case 91:
            case 92:
            case 93:
                Handler().LogError(this,"OnSocks4Read",m_socks4_cd,"socks4 server reports connect failed",LOG_LEVEL_FATAL);
                SetConnecting(false);
                SetCloseAndDelete();
                OnConnectFailed();
                break;
            default:
                Handler().LogError(this,"OnSocks4Read",m_socks4_cd,"socks4 server unrecognized response",LOG_LEVEL_FATAL);
                SetCloseAndDelete();
                break;
            }
        }
        else
        {
            return true;
        }
        break;
    }
    return false;
}
#endif

void TcpSocket::Sendf(const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    char slask[5000]; // vsprintf / vsnprintf temporary
#ifdef _WIN32
    vsprintf(slask, format, ap);
#else
    vsnprintf(slask, 5000, format, ap);
#endif
    va_end(ap);
    Send( slask );
}

#ifdef HAVE_OPENSSL
void TcpSocket::OnSSLConnect()
{
    SetNonblocking(true);
    {
        if (m_ssl_ctx)
        {
DEB(            fprintf(stderr, "SSL Context already initialized - closing socket\n");)
            SetCloseAndDelete(true);
            return;
        }
        InitSSLClient();
    }
    if (m_ssl_ctx)
    {
        /* Connect the SSL socket */
        m_ssl = SSL_new(m_ssl_ctx);
        if (!m_ssl)
        {
DEB(            fprintf(stderr, " m_ssl is NULL\n");)
            SetCloseAndDelete(true);
            return;
        }
        SSL_set_mode(m_ssl, SSL_MODE_AUTO_RETRY);
        m_sbio = BIO_new_socket((int)GetSocket(), BIO_NOCLOSE);
        if (!m_sbio)
        {
DEB(            fprintf(stderr, " m_sbio is NULL\n");)
            SetCloseAndDelete(true);
            return;
        }
        SSL_set_bio(m_ssl, m_sbio, m_sbio);
        if (!SSLNegotiate())
        {
            SetSSLNegotiate();
        }
    }
    else
    {
        SetCloseAndDelete();
    }
}

void TcpSocket::OnSSLAccept()
{
    SetNonblocking(true);
    {
        if (m_ssl_ctx)
        {
DEB(            fprintf(stderr, "SSL Context already initialized - closing socket\n");)
            SetCloseAndDelete(true);
            return;
        }
        InitSSLServer();
        SetSSLServer();
    }
    if (m_ssl_ctx)
    {
        m_ssl = SSL_new(m_ssl_ctx);
        if (!m_ssl)
        {
DEB(            fprintf(stderr, " m_ssl is NULL\n");)
            SetCloseAndDelete(true);
            return;
        }
        SSL_set_mode(m_ssl, SSL_MODE_AUTO_RETRY);
        m_sbio = BIO_new_socket((int)GetSocket(), BIO_NOCLOSE);
        if (!m_sbio)
        {
DEB(            fprintf(stderr, " m_sbio is NULL\n");)
            SetCloseAndDelete(true);
            return;
        }
        SSL_set_bio(m_ssl, m_sbio, m_sbio);
//      if (!SSLNegotiate())
        {
            SetSSLNegotiate();
        }
    }
}

bool TcpSocket::SSLNegotiate()
{
    if (!IsSSLServer()) // client
    {
        int r = SSL_connect(m_ssl);
        if (r > 0)
        {
            SetSSLNegotiate(false);
            /// \todo: resurrect certificate check... client
//          CheckCertificateChain( "");//ServerHOST);
            SetNonblocking(false);
            //
            {
                SetConnected();
                if (GetOutputLength())
                {
                    OnWrite();
                }
            }
#ifdef ENABLE_RECONNECT
            if (IsReconnect())
                OnReconnect();
            else
#endif
            {
                OnConnect();
            }
            Handler().LogError(this, "SSLNegotiate/SSL_connect", 0, "Connection established", LOG_LEVEL_INFO);
            return true;
        }
        else
        if (!r)
        {
            Handler().LogError(this, "SSLNegotiate/SSL_connect", 0, "Connection failed", LOG_LEVEL_INFO);
            SetSSLNegotiate(false);
            SetCloseAndDelete();
            OnSSLConnectFailed();
        }
        else
        {
            r = SSL_get_error(m_ssl, r);
            if (r != SSL_ERROR_WANT_READ && r != SSL_ERROR_WANT_WRITE)
            {
                Handler().LogError(this, "SSLNegotiate/SSL_connect", -1, "Connection failed", LOG_LEVEL_INFO);
DEB(                fprintf(stderr, "SSL_connect() failed - closing socket, return code: %d\n",r);)
                SetSSLNegotiate(false);
                SetCloseAndDelete(true);
                OnSSLConnectFailed();
            }
        }
    }
    else // server
    {
        int r = SSL_accept(m_ssl);
        if (r > 0)
        {
            SetSSLNegotiate(false);
            /// \todo: resurrect certificate check... server
//          CheckCertificateChain( "");//ClientHOST);
            SetNonblocking(false);
            //
            {
                SetConnected();
                if (GetOutputLength())
                {
                    OnWrite();
                }
            }
            OnAccept();
            Handler().LogError(this, "SSLNegotiate/SSL_accept", 0, "Connection established", LOG_LEVEL_INFO);
            return true;
        }
        else
        if (!r)
        {
            Handler().LogError(this, "SSLNegotiate/SSL_accept", 0, "Connection failed", LOG_LEVEL_INFO);
            SetSSLNegotiate(false);
            SetCloseAndDelete();
            OnSSLAcceptFailed();
        }
        else
        {
            r = SSL_get_error(m_ssl, r);
            if (r != SSL_ERROR_WANT_READ && r != SSL_ERROR_WANT_WRITE)
            {
                Handler().LogError(this, "SSLNegotiate/SSL_accept", -1, "Connection failed", LOG_LEVEL_INFO);
DEB(                fprintf(stderr, "SSL_accept() failed - closing socket, return code: %d\n",r);)
                SetSSLNegotiate(false);
                SetCloseAndDelete(true);
                OnSSLAcceptFailed();
            }
        }
    }
    return false;
}

void TcpSocket::InitSSLClient()
{
    InitializeContext("", SSLv23_method());
}

void TcpSocket::InitSSLServer()
{
    Handler().LogError(this, "InitSSLServer", 0, "You MUST implement your own InitSSLServer method", LOG_LEVEL_FATAL);
    SetCloseAndDelete();
}

void TcpSocket::InitializeContext(const std::string& context, SSL_METHOD *meth_in)
{
    /* Create our context*/
    static std::map<std::string, SSL_CTX *> client_contexts;
    if (client_contexts.find(context) == client_contexts.end())
    {
        SSL_METHOD *meth = meth_in ? meth_in : SSLv3_method();
        m_ssl_ctx = client_contexts[context] = SSL_CTX_new(meth);
        SSL_CTX_set_mode(m_ssl_ctx, SSL_MODE_AUTO_RETRY);
    }
    else
    {
        m_ssl_ctx = client_contexts[context];
    }
}

void TcpSocket::InitializeContext(const std::string& context,const std::string& keyfile,const std::string& password,SSL_METHOD *meth_in)
{
    /* Create our context*/
    static std::map<std::string, SSL_CTX *> server_contexts;
    if (server_contexts.find(context) == server_contexts.end())
    {
        SSL_METHOD *meth = meth_in ? meth_in : SSLv3_method();
        m_ssl_ctx = server_contexts[context] = SSL_CTX_new(meth);
        SSL_CTX_set_mode(m_ssl_ctx, SSL_MODE_AUTO_RETRY);
        // session id
        if (!context.empty())
            SSL_CTX_set_session_id_context(m_ssl_ctx, (const unsigned char *)context.c_str(), (unsigned int)context.size());
        else
            SSL_CTX_set_session_id_context(m_ssl_ctx, (const unsigned char *)"--empty--", 9);
    }
    else
    {
        m_ssl_ctx = server_contexts[context];
    }
    /* Load our keys and certificates*/
    if (!(SSL_CTX_use_certificate_file(m_ssl_ctx, keyfile.c_str(), SSL_FILETYPE_PEM)))
    {
        Handler().LogError(this, "TcpSocket InitializeContext", 0, "Couldn't read certificate file " + keyfile, LOG_LEVEL_FATAL);
    }
    m_password = password;
    SSL_CTX_set_default_passwd_cb(m_ssl_ctx, SSL_password_cb);
    SSL_CTX_set_default_passwd_cb_userdata(m_ssl_ctx, this);
    if (!(SSL_CTX_use_PrivateKey_file(m_ssl_ctx, keyfile.c_str(), SSL_FILETYPE_PEM)))
    {
        Handler().LogError(this, "TcpSocket InitializeContext", 0, "Couldn't read private key file " + keyfile, LOG_LEVEL_FATAL);
    }
}

void TcpSocket::InitializeContext(const std::string& context,const std::string& certfile,const std::string& keyfile,const std::string& password,SSL_METHOD *meth_in)
{
    /* Create our context*/
    static std::map<std::string, SSL_CTX *> server_contexts;
    if (server_contexts.find(context) == server_contexts.end())
    {
        SSL_METHOD *meth = meth_in ? meth_in : SSLv3_method();
        m_ssl_ctx = server_contexts[context] = SSL_CTX_new(meth);
        SSL_CTX_set_mode(m_ssl_ctx, SSL_MODE_AUTO_RETRY);
        // session id
        if (context.size())
            SSL_CTX_set_session_id_context(m_ssl_ctx, (const unsigned char *)context.c_str(), (unsigned int)context.size());
        else
            SSL_CTX_set_session_id_context(m_ssl_ctx, (const unsigned char *)"--empty--", 9);
    }
    else
    {
        m_ssl_ctx = server_contexts[context];
    }
    /* Load our keys and certificates*/
    if (!(SSL_CTX_use_certificate_file(m_ssl_ctx, certfile.c_str(), SSL_FILETYPE_PEM)))
    {
        Handler().LogError(this, "TcpSocket InitializeContext", 0, "Couldn't read certificate file " + keyfile, LOG_LEVEL_FATAL);
    }
    m_password = password;
    SSL_CTX_set_default_passwd_cb(m_ssl_ctx, SSL_password_cb);
    SSL_CTX_set_default_passwd_cb_userdata(m_ssl_ctx, this);
    if (!(SSL_CTX_use_PrivateKey_file(m_ssl_ctx, keyfile.c_str(), SSL_FILETYPE_PEM)))
    {
        Handler().LogError(this, "TcpSocket InitializeContext", 0, "Couldn't read private key file " + keyfile, LOG_LEVEL_FATAL);
    }
}

int TcpSocket::SSL_password_cb(char *buf,int num,int rwflag,void *userdata)
{
    Socket *p0 = static_cast<Socket *>(userdata);
    TcpSocket *p = dynamic_cast<TcpSocket *>(p0);
    std::string pw = p ? p -> GetPassword() : "";
    if ( (size_t)num < pw.size() + 1)
    {
        return 0;
    }
    strcpy(buf,pw.c_str());
    return (int)pw.size();
}
#endif // HAVE_OPENSSL

int TcpSocket::Close()
{
    if (GetSocket() == INVALID_SOCKET) // this could happen
    {
        Handler().LogError(this, "Socket::Close", 0, "file descriptor invalid", LOG_LEVEL_WARNING);
        return 0;
    }
    int n;
    SetNonblocking(true);
    if (!Lost() && IsConnected() && !(GetShutdown() & SHUT_WR))
    {
        if (shutdown(GetSocket(), SHUT_WR) == -1)
        {
            // failed...
            Handler().LogError(this, "shutdown", Errno, StrError(Errno), LOG_LEVEL_ERROR);
        }
    }
    //
    char tmp[1000];
    if (!Lost() && (n = recv(GetSocket(),tmp,1000,0)) >= 0)
    {
        if (n)
        {
            Handler().LogError(this, "read() after shutdown", n, "bytes read", LOG_LEVEL_WARNING);
        }
    }
#ifdef HAVE_OPENSSL
    if (IsSSL() && m_ssl)
        SSL_shutdown(m_ssl);
    if (m_ssl)
    {
        SSL_free(m_ssl);
        m_ssl = NULL;
    }
#endif
    return Socket::Close();
}

#ifdef HAVE_OPENSSL
SSL_CTX *TcpSocket::GetSslContext()
{
    if (!m_ssl_ctx)
        Handler().LogError(this, "GetSslContext", 0, "SSL Context is NULL; check InitSSLServer/InitSSLClient", LOG_LEVEL_WARNING);
    return m_ssl_ctx;
}
SSL *TcpSocket::GetSsl()
{
    if (!m_ssl)
        Handler().LogError(this, "GetSsl", 0, "SSL is NULL; check InitSSLServer/InitSSLClient", LOG_LEVEL_WARNING);
    return m_ssl;
}
#endif

#ifdef ENABLE_RECONNECT
void TcpSocket::SetReconnect(bool x)
{
    m_b_reconnect = x;
}
#endif

void TcpSocket::OnRawData(const char *buf_in,size_t len)
{
}

size_t TcpSocket::GetInputLength()
{
    return ibuf.GetLength();
}

size_t TcpSocket::GetOutputLength()
{
    return m_output_length;
}

uint64_t TcpSocket::GetBytesReceived(bool clear)
{
    uint64_t z = m_bytes_received;
    if (clear)
        m_bytes_received = 0;
    return z;
}

uint64_t TcpSocket::GetBytesSent(bool clear)
{
    uint64_t z = m_bytes_sent;
    if (clear)
        m_bytes_sent = 0;
    return z;
}

#ifdef ENABLE_RECONNECT
bool TcpSocket::Reconnect()
{
    return m_b_reconnect;
}

void TcpSocket::SetIsReconnect(bool x)
{
    m_b_is_reconnect = x;
}

bool TcpSocket::IsReconnect()
{
    return m_b_is_reconnect;
}
#endif

#ifdef HAVE_OPENSSL
const std::string& TcpSocket::GetPassword()
{
    return m_password;
}
#endif

void TcpSocket::DisableInputBuffer(bool x)
{
    m_b_input_buffer_disabled = x;
}

void TcpSocket::OnOptions(int family,int type,int protocol,SOCKET s)
{
DEB(    fprintf(stderr, "Socket::OnOptions()\n");)
#ifdef SO_NOSIGPIPE
    SetSoNosigpipe(true);
#endif
    SetSoReuseaddr(true);
    SetSoKeepalive(true);
}

void TcpSocket::SetLineProtocol(bool x)
{
    StreamSocket::SetLineProtocol(x);
    DisableInputBuffer(x);
}

bool TcpSocket::SetTcpNodelay(bool x)
{
#ifdef TCP_NODELAY
    int optval = x ? 1 : 0;
    if (setsockopt(GetSocket(), IPPROTO_TCP, TCP_NODELAY, (char *)&optval, sizeof(optval)) == -1)
    {
        Handler().LogError(this, "setsockopt(IPPROTO_TCP, TCP_NODELAY)", Errno, StrError(Errno), LOG_LEVEL_FATAL);
        return false;
    }
    return true;
#else
    Handler().LogError(this, "socket option not available", 0, "TCP_NODELAY", LOG_LEVEL_INFO);
    return false;
#endif
}

TcpSocket::CircularBuffer::CircularBuffer(size_t size)
:buf(new char[2 * size])
,m_max(size)
,m_q(0)
,m_b(0)
,m_t(0)
,m_count(0)
{
}

TcpSocket::CircularBuffer::~CircularBuffer()
{
    delete[] buf;
}

bool TcpSocket::CircularBuffer::Write(const char *s,size_t l)
{
    if (m_q + l > m_max)
    {
        return false; // overflow
    }
    m_count += (unsigned long)l;
    if (m_t + l > m_max) // block crosses circular border
    {
        size_t l1 = m_max - m_t; // size left until circular border crossing
        // always copy full block to buffer(buf) + top pointer(m_t)
        // because we have doubled the buffer size for performance reasons
        memcpy(buf + m_t, s, l);
        memcpy(buf, s + l1, l - l1);
        m_t = l - l1;
        m_q += l;
    }
    else
    {
        memcpy(buf + m_t, s, l);
        memcpy(buf + m_max + m_t, s, l);
        m_t += l;
        if (m_t >= m_max)
            m_t -= m_max;
        m_q += l;
    }
    return true;
}

bool TcpSocket::CircularBuffer::Read(char *s,size_t l)
{
    if (l > m_q)
    {
        return false; // not enough chars
    }
    if (m_b + l > m_max) // block crosses circular border
    {
        size_t l1 = m_max - m_b;
        if (s)
        {
            memcpy(s, buf + m_b, l1);
            memcpy(s + l1, buf, l - l1);
        }
        m_b = l - l1;
        m_q -= l;
    }
    else
    {
        if (s)
        {
            memcpy(s, buf + m_b, l);
        }
        m_b += l;
        if (m_b >= m_max)
            m_b -= m_max;
        m_q -= l;
    }
    if (!m_q)
    {
        m_b = m_t = 0;
    }
    return true;
}
bool TcpSocket::CircularBuffer::SoftRead(char *s, size_t l)
{
    if (l > m_q)
    {
        return false;
    }
    if (m_b + l > m_max)                          // block crosses circular border
    {
        size_t l1 = m_max - m_b;
        if (s)
        {
            memcpy(s, buf + m_b, l1);
            memcpy(s + l1, buf, l - l1);
        }
    }
    else
    {
        if (s)
        {
            memcpy(s, buf + m_b, l);
        }
    }
    return true;
}
bool TcpSocket::CircularBuffer::Remove(size_t l)
{
    return Read(NULL, l);
}

size_t TcpSocket::CircularBuffer::GetLength()
{
    return m_q;
}

const char *TcpSocket::CircularBuffer::GetStart()
{
    return buf + m_b;
}

size_t TcpSocket::CircularBuffer::GetL()
{
    return (m_b + m_q > m_max) ? m_max - m_b : m_q;
}

size_t TcpSocket::CircularBuffer::Space()
{
    return m_max - m_q;
}

unsigned long TcpSocket::CircularBuffer::ByteCounter(bool clear)
{
    if (clear)
    {
        unsigned long x = m_count;
        m_count = 0;
        return x;
    }
    return m_count;
}

std::string TcpSocket::CircularBuffer::ReadString(size_t l)
{
    char *sz = new char[l + 1];
    if (!Read(sz, l)) // failed, debug printout in Read() method
    {
        delete[] sz;
        return "";
    }
    sz[l] = 0;
    std::string tmp = sz;
    delete[] sz;
    return tmp;
}

void TcpSocket::OnConnectTimeout()
{
    Handler().LogError(this, "connect", -1, "connect timeout", LOG_LEVEL_FATAL);
#ifdef ENABLE_SOCKS4
    if (Socks4())
    {
        OnSocks4ConnectFailed();
        // retry direct connection
    }
    else
#endif
    if (GetConnectionRetry() == -1 ||
        (GetConnectionRetry() && GetConnectionRetries() < GetConnectionRetry()) )
    {
        IncreaseConnectionRetries();
        // ask socket via OnConnectRetry callback if we should continue trying
        if (OnConnectRetry())
        {
            SetRetryClientConnect();
        }
        else
        {
            SetCloseAndDelete( true );
            /// \todo state reason why connect failed
            OnConnectFailed();
        }
    }
    else
    {
        SetCloseAndDelete(true);
        /// \todo state reason why connect failed
        OnConnectFailed();
    }
    //
    SetConnecting(false);
}

#ifdef _WIN32
void TcpSocket::OnException()
{
    if (Connecting())
    {
#ifdef ENABLE_SOCKS4
        if (Socks4())
            OnSocks4ConnectFailed();
        else
#endif
        if (GetConnectionRetry() == -1 ||
            (GetConnectionRetry() &&
             GetConnectionRetries() < GetConnectionRetry() ))
        {
            // even though the connection failed at once, only retry after
            // the connection timeout
            // should we even try to connect again, when CheckConnect returns
            // false it's because of a connection error - not a timeout...
        }
        else
        {
            SetConnecting(false); // tnx snibbe
            SetCloseAndDelete();
            OnConnectFailed();
        }
        return;
    }
    // %! exception doesn't always mean something bad happened, this code should be reworked
    // errno valid here?
    int err = SoError();
    Handler().LogError(this, "exception on select", err, StrError(err), LOG_LEVEL_FATAL);
    SetCloseAndDelete();
}
#endif // _WIN32

int TcpSocket::Protocol()
{
    return IPPROTO_TCP;
}

void TcpSocket::SetTransferLimit(size_t sz)
{
    m_transfer_limit = sz;
}

void TcpSocket::OnTransferLimit()
{
}

#ifdef SOCKETS_NAMESPACE
}
#endif

