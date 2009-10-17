/** \file Socket.h
 ** \date  2004-02-13
 ** \author grymse@alhem.net
**/
/*
Copyright (C) 2004-2007  Anders Hedstrom

This software is made available under the terms of the GNU GPL.

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
#ifndef _SOCKETS_Socket_H
#define _SOCKETS_Socket_H
#include "sockets-config.h"

#include <string>
#include <vector>
#include <list>
#ifdef HAVE_OPENSSL
#include <openssl/ssl.h>
#endif

#include "socket_include.h"
#include <time.h>
#include "SocketAddress.h"
#include "Thread.h"

#ifdef SOCKETS_NAMESPACE
namespace SOCKETS_NAMESPACE {
#endif

class ISocketHandler;
class SocketAddress;
class IFile;

/** \defgroup basic Basic sockets */
/** Socket base class.
    \ingroup basic */
class Socket
{
    friend class ISocketHandler;
#ifdef ENABLE_DETACH
    /** Detached socket run thread.
        \ingroup internal */
    class SocketThread : public Thread
    {
    public:
        SocketThread(Socket *p);
        ~SocketThread();

        void Run();

    private:
        Socket *GetSocket() const { return m_socket; }
        SocketThread(const SocketThread& s) : m_socket(s.GetSocket()) {}
        SocketThread& operator=(const SocketThread& ) { return *this; }
        Socket *m_socket;
    };
#endif // ENABLE_DETACH

#ifdef ENABLE_TRIGGERS
public:
    /** Data pass class from source to destination. */
    class TriggerData
    {
    public:
        TriggerData() : m_src(NULL) {}
        virtual ~TriggerData() {}

        Socket *GetSource() const { return m_src; }
        void SetSource(Socket *x) { m_src = x; }

    private:
        Socket *m_src;
    };
#endif // ENABLE_TRIGGERS

    /** Socket mode flags. */
/*
    enum {
        // Socket
        SOCK_DEL =          0x01, ///< Delete by handler flag
        SOCK_CLOSE =            0x02, ///< Close and delete flag
        SOCK_DISABLE_READ =         0x04, ///< Disable checking for read events
        SOCK_CONNECTED =        0x08, ///< Socket is connected (tcp/udp)

        SOCK_ERASED_BY_HANDLER =    0x10, ///< Set by handler before delete
        // HAVE_OPENSSL
        SOCK_ENABLE_SSL =       0x20, ///< Enable SSL for this TcpSocket
        SOCK_SSL =          0x40, ///< ssl negotiation mode (TcpSocket)
        SOCK_SSL_SERVER =       0x80, ///< True if this is an incoming ssl TcpSocket connection

        // ENABLE_IPV6
        SOCK_IPV6 =             0x0100, ///< This is an ipv6 socket if this one is true
        // ENABLE_POOL
        SOCK_CLIENT =           0x0200, ///< only client connections are pooled
        SOCK_RETAIN =           0x0400, ///< keep connection on close
        SOCK_LOST =             0x0800, ///< connection lost

        // ENABLE_SOCKS4
        SOCK_SOCKS4 =           0x1000, ///< socks4 negotiation mode (TcpSocket)
        // ENABLE_DETACH
        SOCK_DETACH =           0x2000, ///< Socket ordered to detach flag
        SOCK_DETACHED =         0x4000, ///< Socket has been detached
        // StreamSocket
        STREAMSOCK_CONNECTING =     0x8000, ///< Flag indicating connection in progress

        STREAMSOCK_FLUSH_BEFORE_CLOSE = 0x010000L, ///< Send all data before closing (default true)
        STREAMSOCK_CALL_ON_CONNECT =    0x020000L, ///< OnConnect will be called next ISocketHandler cycle if true
        STREAMSOCK_RETRY_CONNECT =  0x040000L, ///< Try another connection attempt next ISocketHandler cycle
        STREAMSOCK_LINE_PROTOCOL =  0x080000L, ///< Line protocol mode flag

    };
*/

public:
    /** "Default" constructor */
    Socket(ISocketHandler&);

    virtual ~Socket();

    /** Socket class instantiation method. Used when a "non-standard" constructor
     * needs to be used for the socket class. Note: the socket class still needs
     * the "default" constructor with one ISocketHandler& as input parameter.
     */
    virtual Socket *Create() { return NULL; }

    /** Returns reference to sockethandler that owns the socket.
    If the socket is detached, this is a reference to the slave sockethandler.
    */
    ISocketHandler& Handler() const;

    /** Returns reference to sockethandler that owns the socket.
    This one always returns the reference to the original sockethandler,
    even if the socket is detached.
    */
    ISocketHandler& MasterHandler() const;

    /** Called by ListenSocket after accept but before socket is added to handler.
     * CTcpSocket uses this to create its ICrypt member variable.
     * The ICrypt member variable is created by a virtual method, therefore
     * it can't be called directly from the CTcpSocket constructor.
     * Also used to determine if incoming HTTP connection is normal (port 80)
     * or ssl (port 443).
     */
    virtual void Init();

    /** Create a socket file descriptor.
        \param af Address family AF_INET / AF_INET6 / ...
        \param type SOCK_STREAM / SOCK_DGRAM / ...
        \param protocol "tcp" / "udp" / ... */
    SOCKET CreateSocket(int af,int type,const std::string& protocol = "");

    /** Assign this socket a file descriptor created
        by a call to socket() or otherwise. */
    void Attach(SOCKET s);

    /** Return file descriptor assigned to this socket. */
    SOCKET GetSocket();

    /** Close connection immediately - internal use.
        \sa SetCloseAndDelete */
    virtual int Close();

    /** Add file descriptor to sockethandler fd_set's. */
    void Set(bool bRead,bool bWrite,bool bException = true);

    /** Returns true when socket file descriptor is valid
        and socket is not about to be closed. */
    virtual bool Ready();

    /** Returns pointer to ListenSocket that created this instance
     * on an incoming connection. */
    Socket *GetParent();

    /** Used by ListenSocket to set parent pointer of newly created
     * socket instance. */
    void SetParent(Socket *);

    /** Get listening port from ListenSocket<>. */
    virtual port_t GetPort();

    /** Set socket non-block operation. */
    bool SetNonblocking(bool);

    /** Set socket non-block operation. */
    bool SetNonblocking(bool, SOCKET);

    /** Total lifetime of instance. */
    time_t Uptime();

    /** Set address/port of last connect() call. */
    void SetClientRemoteAddress(SocketAddress&);

    /** Get address/port of last connect() call. */
    std::auto_ptr<SocketAddress> GetClientRemoteAddress();

    /** Common interface for SendBuf used by Tcp and Udp sockets. */
    virtual void SendBuf(const char *,size_t,int = 0);

    /** Common interface for Send used by Tcp and Udp sockets. */
    virtual void Send(const std::string&,int = 0);

    /** Outgoing traffic counter. */
    virtual uint64_t GetBytesSent(bool clear = false);

    /** Incoming traffic counter. */
    virtual uint64_t GetBytesReceived(bool clear = false);

    // LIST_TIMEOUT

    /** Enable timeout control. 0=disable timeout check. */
    void SetTimeout(time_t secs);

    /** Check timeout. \return true if time limit reached */
    bool Timeout(time_t tnow);

    /** Used by ListenSocket. ipv4 and ipv6 */
    void SetRemoteAddress(SocketAddress&);

    /** \name Event callbacks */
    //@{

    /** Called when there is something to be read from the file descriptor. */
    virtual void OnRead();
    /** Called when there is room for another write on the file descriptor. */
    virtual void OnWrite();
    /** Called on socket exception. */
    virtual void OnException();
    /** Called before a socket class is deleted by the ISocketHandler. */
    virtual void OnDelete();
    /** Called when a connection has completed. */
    virtual void OnConnect();
    /** Called when an incoming connection has been completed. */
    virtual void OnAccept();
    /** Called when a complete line has been read and the socket is in
     * line protocol mode. */
    virtual void OnLine(const std::string& );
    /** Called on connect timeout (5s). */
    virtual void OnConnectFailed();
    /** Called when a client socket is created, to set socket options.
        \param family AF_INET, AF_INET6, etc
        \param type SOCK_STREAM, SOCK_DGRAM, etc
        \param protocol Protocol number (tcp, udp, sctp, etc)
        \param s Socket file descriptor
    */
    virtual void OnOptions(int family,int type,int protocol,SOCKET s) = 0;
    /** Connection retry callback - return false to abort connection attempts */
    virtual bool OnConnectRetry();
#ifdef ENABLE_RECONNECT
    /** a reconnect has been made */
    virtual void OnReconnect();
#endif
    /** TcpSocket: When a disconnect has been detected (recv/SSL_read returns 0 bytes). */
    virtual void OnDisconnect();
    /** Timeout callback. */
    virtual void OnTimeout();
    /** Connection timeout. */
    virtual void OnConnectTimeout();
    //@}

    /** \name Socket mode flags, set/reset */
    //@{
    /** Set delete by handler true when you want the sockethandler to
        delete the socket instance after use. */
    void SetDeleteByHandler(bool = true);
    /** Check delete by handler flag.
        \return true if this instance should be deleted by the sockethandler */
    bool DeleteByHandler();

    // LIST_CLOSE - conditional event queue

    /** Set close and delete to terminate the connection. */
    void SetCloseAndDelete(bool = true);
    /** Check close and delete flag.
        \return true if this socket should be closed and the instance removed */
    bool CloseAndDelete();

    /** Return number of seconds since socket was ordered to close. \sa SetCloseAndDelete */
    time_t TimeSinceClose();

    /** Ignore read events for an output only socket. */
    void DisableRead(bool x = true);
    /** Check ignore read events flag.
        \return true if read events should be ignored */
    bool IsDisableRead();

    /** Set connected status. */
    void SetConnected(bool = true);
    /** Check connected status.
        \return true if connected */
    bool IsConnected();

    /** Connection lost - error while reading/writing from a socket - TcpSocket only. */
    void SetLost();
    /** Check connection lost status flag, used by TcpSocket only.
        \return true if there was an error while r/w causing the socket to close */
    bool Lost();

    /** Set flag indicating the socket is being actively deleted by the sockethandler. */
    void SetErasedByHandler(bool x = true);
    /** Get value of flag indicating socket is deleted by sockethandler. */
    bool ErasedByHandler();

    //@}

    /** \name Information about remote connection */
    //@{
    /** Returns address of remote end. */
    std::auto_ptr<SocketAddress> GetRemoteSocketAddress();
    /** Returns address of remote end: ipv4. */
    ipaddr_t GetRemoteIP4();
#ifdef ENABLE_IPV6
    /** Returns address of remote end: ipv6. */
#ifdef IPPROTO_IPV6
    struct in6_addr GetRemoteIP6();
#endif
#endif
    /** Returns remote port number: ipv4 and ipv6. */
    port_t GetRemotePort();
    /** Returns remote ip as string? ipv4 and ipv6. */
    std::string GetRemoteAddress();
    /** ipv4 and ipv6(not implemented) */
    std::string GetRemoteHostname();
    //@}

    /** Returns local port number for bound socket file descriptor. */
    port_t GetSockPort();
    /** Returns local ipv4 address for bound socket file descriptor. */
    ipaddr_t GetSockIP4();
    /** Returns local ipv4 address as text for bound socket file descriptor. */
    std::string GetSockAddress();
#ifdef ENABLE_IPV6
#ifdef IPPROTO_IPV6
    /** Returns local ipv6 address for bound socket file descriptor. */
    struct in6_addr GetSockIP6();
    /** Returns local ipv6 address as text for bound socket file descriptor. */
    std::string GetSockAddress6();
#endif
#endif
    // --------------------------------------------------------------------------
    /** @name IP options
       When an ip or socket option is available on all of the operating systems
       I'm testing on (linux 2.4.x, _win32, macosx, solaris9 intel) they are not
       checked with an #ifdef below.
       This might cause a compile error on other operating systems. */
    // --------------------------------------------------------------------------

    // IP options
    //@{

    bool SetIpOptions(const void *p, socklen_t len);
    bool SetIpTOS(unsigned char tos);
    unsigned char IpTOS();
    bool SetIpTTL(int ttl);
    int IpTTL();
    bool SetIpHdrincl(bool x = true);
    bool SetIpMulticastTTL(int);
    int IpMulticastTTL();
    bool SetMulticastLoop(bool x = true);
    bool IpAddMembership(struct ip_mreq&);
    bool IpDropMembership(struct ip_mreq&);

#ifdef IP_PKTINFO
    bool SetIpPktinfo(bool x = true);
#endif
#ifdef IP_RECVTOS
    bool SetIpRecvTOS(bool x = true);
#endif
#ifdef IP_RECVTTL
    bool SetIpRecvTTL(bool x = true);
#endif
#ifdef IP_RECVOPTS
    bool SetIpRecvopts(bool x = true);
#endif
#ifdef IP_RETOPTS
    bool SetIpRetopts(bool x = true);
#endif
#ifdef IP_RECVERR
    bool SetIpRecverr(bool x = true);
#endif
#ifdef IP_MTU_DISCOVER
    bool SetIpMtudiscover(bool x = true);
#endif
#ifdef IP_MTU
    int IpMtu();
#endif
#ifdef IP_ROUTER_ALERT
    bool SetIpRouterAlert(bool x = true);
#endif
#ifdef LINUX
    bool IpAddMembership(struct ip_mreqn&);
#endif
#ifdef LINUX
    bool IpDropMembership(struct ip_mreqn&);
#endif
    //@}

    // SOCKET options
    /** @name Socket Options */
    //@{

    bool SoAcceptconn();
    bool SetSoBroadcast(bool x = true);
    bool SetSoDebug(bool x = true);
    int SoError();
    bool SetSoDontroute(bool x = true);
    bool SetSoLinger(int onoff, int linger);
    bool SetSoOobinline(bool x = true);
    bool SetSoRcvlowat(int);
    bool SetSoSndlowat(int);
    bool SetSoRcvtimeo(struct timeval&);
    bool SetSoSndtimeo(struct timeval&);
    bool SetSoRcvbuf(int);
    int SoRcvbuf();
    bool SetSoSndbuf(int);
    int SoSndbuf();
    int SoType();
    bool SetSoReuseaddr(bool x = true);
    bool SetSoKeepalive(bool x = true);

#ifdef SO_BSDCOMPAT
    bool SetSoBsdcompat(bool x = true);
#endif
#ifdef SO_BINDTODEVICE
    bool SetSoBindtodevice(const std::string& intf);
#endif
#ifdef SO_PASSCRED
    bool SetSoPasscred(bool x = true);
#endif
#ifdef SO_PEERCRED
    bool SoPeercred(struct ucred& );
#endif
#ifdef SO_PRIORITY
    bool SetSoPriority(int);
#endif
#ifdef SO_RCVBUFFORCE
    bool SetSoRcvbufforce(int);
#endif
#ifdef SO_SNDBUFFORCE
    bool SetSoSndbufforce(int);
#endif
#ifdef SO_TIMESTAMP
    bool SetSoTimestamp(bool x = true);
#endif
#ifdef SO_NOSIGPIPE
    bool SetSoNosigpipe(bool x = true);
#endif
    //@}

    // TCP options in TcpSocket.h/TcpSocket.cpp

#ifdef HAVE_OPENSSL
    /** @name SSL Support */
    //@{
    /** SSL client/server support - internal use. \sa TcpSocket */
    virtual void OnSSLConnect();
    /** SSL client/server support - internal use. \sa TcpSocket */
    virtual void OnSSLAccept();
    /** SSL negotiation failed for client connect. */
    virtual void OnSSLConnectFailed();
    /** SSL negotiation failed for server accept. */
    virtual void OnSSLAcceptFailed();
    /** new SSL support */
    virtual bool SSLNegotiate();
    /** Check if SSL is Enabled for this TcpSocket.
        \return true if this is a TcpSocket with SSL enabled */
    bool IsSSL();
    /** Enable SSL operation for a TcpSocket. */
    void EnableSSL(bool x = true);
    /** Still negotiating ssl connection.
        \return true if ssl negotiating is still in progress */
    bool IsSSLNegotiate();
    /** Set flag indicating ssl handshaking still in progress. */
    void SetSSLNegotiate(bool x = true);
    /** OnAccept called with SSL Enabled.
        \return true if this is a TcpSocket with an incoming SSL connection */
    bool IsSSLServer();
    /** Set flag indicating that this is a TcpSocket with incoming SSL connection. */
    void SetSSLServer(bool x = true);
    /** SSL; Get pointer to ssl context structure. */
    virtual SSL_CTX *GetSslContext() { return NULL; }
    /** SSL; Get pointer to ssl structure. */
    virtual SSL *GetSsl() { return NULL; }
    //@}
#endif // HAVE_OPENSSL

#ifdef ENABLE_IPV6
    /** Enable ipv6 for this socket. */
    void SetIpv6(bool x = true);
    /** Check ipv6 socket.
        \return true if this is an ipv6 socket */
    bool IsIpv6();
#endif

#ifdef ENABLE_POOL
    /** @name Connection Pool */
    //@{
    /** Client = connecting TcpSocket. */
    void SetIsClient();
    /** Socket type from socket() call. */
    void SetSocketType(int x);
    /** Socket type from socket() call. */
    int GetSocketType();
    /** Protocol type from socket() call. */
    void SetSocketProtocol(const std::string& x);
    /** Protocol type from socket() call. */
    const std::string& GetSocketProtocol();
    /** Instruct a client socket to stay open in the connection pool after use.
        If you have connected to a server using tcp, you can call SetRetain
        to leave the connection open after your socket instance has been deleted.
        The next connection you make to the same server will reuse the already
        opened connection, if it is still available.
    */
    void SetRetain();
    /** Check retain flag.
        \return true if the socket should be moved to connection pool after use */
    bool Retain();
    /** Copy connection parameters from sock. */
    void CopyConnection(Socket *sock);
    //@}
#endif // ENABLE_POOL

#ifdef ENABLE_SOCKS4
    /** \name Socks4 support */
    //@{
    /** Socks4 client support internal use. \sa TcpSocket */
    virtual void OnSocks4Connect();
    /** Socks4 client support internal use. \sa TcpSocket */
    virtual void OnSocks4ConnectFailed();
    /** Socks4 client support internal use. \sa TcpSocket */
    virtual bool OnSocks4Read();
    /** Called when the last write caused the tcp output buffer to
     * become empty. */
    /** socket still in socks4 negotiation mode */
    bool Socks4();
    /** Set flag indicating Socks4 handshaking in progress */
    void SetSocks4(bool x = true);

    /** Set socks4 server host address to use */
    void SetSocks4Host(ipaddr_t a);
    /** Set socks4 server hostname to use. */
    void SetSocks4Host(const std::string& );
    /** Socks4 server port to use. */
    void SetSocks4Port(port_t p);
    /** Provide a socks4 userid if required by the socks4 server. */
    void SetSocks4Userid(const std::string& x);
    /** Get the ip address of socks4 server to use.
        \return socks4 server host address */
    ipaddr_t GetSocks4Host();
    /** Get the socks4 server port to use.
        \return socks4 server port */
    port_t GetSocks4Port();
    /** Get socks4 userid.
        \return Socks4 userid */
    const std::string& GetSocks4Userid();
    //@}
#endif // ENABLE_SOCKS4

#ifdef ENABLE_RESOLVER
    /** \name Asynchronous Resolver */
    //@{
    /** Request an asynchronous dns resolution.
        \param host hostname to be resolved
        \param port port number passed along for the ride
        \return Resolve ID */
    int Resolve(const std::string& host,port_t port = 0);
#ifdef ENABLE_IPV6
    int Resolve6(const std::string& host, port_t port = 0);
#endif
    /** Callback returning a resolved address.
        \param id Resolve ID from Resolve call
        \param a resolved ip address
        \param port port number passed to Resolve */
    virtual void OnResolved(int id,ipaddr_t a,port_t port);
#ifdef ENABLE_IPV6
    virtual void OnResolved(int id,in6_addr& a,port_t port);
#endif
    /** Request asynchronous reverse dns lookup.
        \param a in_addr to be translated */
    int Resolve(ipaddr_t a);
#ifdef ENABLE_IPV6
    int Resolve(in6_addr& a);
#endif
    /** Callback returning reverse resolve results.
        \param id Resolve ID
        \param name Resolved hostname */
    virtual void OnReverseResolved(int id,const std::string& name);
    /** Callback indicating failed dns lookup.
        \param id Resolve ID */
    virtual void OnResolveFailed(int id);
    //@}
#endif  // ENABLE_RESOLVER

#ifdef ENABLE_DETACH
    /** \name Thread Support */
    //@{
    /** Callback fires when a new socket thread has started and this
        socket is ready for operation again.
        \sa ResolvSocket */
    virtual void OnDetached();

    // LIST_DETACH

    /** Internal use. */
    void SetDetach(bool x = true);
    /** Check detach flag.
        \return true if the socket should detach to its own thread */
    bool IsDetach();

    /** Internal use. */
    void SetDetached(bool x = true);
    /** Check detached flag.
        \return true if the socket runs in its own thread. */
    const bool IsDetached() const;
    /** Order this socket to start its own thread and call OnDetached
        when ready for operation. */
    bool Detach();
    /** Store the slave sockethandler pointer. */
    void SetSlaveHandler(ISocketHandler *);
    /** Create new thread for this socket to run detached in. */
    void DetachSocket();
    //@}
#endif // ENABLE_DETACH

    /** Write traffic to an IFile. Socket will not delete this object. */
    void SetTrafficMonitor(IFile *p) { m_traffic_monitor = p; }

#ifdef ENABLE_TRIGGERS
    /** \name Triggers */
    //@{
    /** Subscribe to trigger id. */
    void Subscribe(int id);
    /** Unsubscribe from trigger id. */
    void Unsubscribe(int id);
    /** Trigger callback, with data passed from source to destination. */
    virtual void OnTrigger(int id, const TriggerData& data);
    /** Trigger cancelled because source has been deleted (as in delete). */
    virtual void OnCancelled(int id);
    //@}
#endif

protected:
    /** default constructor not available */
    Socket() : m_handler(m_handler) {}
    /** copy constructor not available */
    Socket(const Socket& s) : m_handler(s.m_handler) {}

    /** assignment operator not available. */
    Socket& operator=(const Socket& ) { return *this; }

    /** All traffic will be written to this IFile, if set. */
    IFile *GetTrafficMonitor() { return m_traffic_monitor; }

//  unsigned long m_flags; ///< boolean flags, replacing old 'bool' members

private:
    ISocketHandler& m_handler; ///< Reference of ISocketHandler in control of this socket
    SOCKET m_socket; ///< File descriptor
    bool m_bDel; ///< Delete by handler flag
    bool m_bClose; ///< Close and delete flag
    time_t m_tCreate; ///< Time in seconds when this socket was created
    Socket *m_parent; ///< Pointer to ListenSocket class, valid for incoming sockets
    bool m_b_disable_read; ///< Disable checking for read events
    bool m_connected; ///< Socket is connected (tcp/udp)
    bool m_b_erased_by_handler; ///< Set by handler before delete
    time_t m_tClose; ///< Time in seconds when ordered to close
    std::auto_ptr<SocketAddress> m_client_remote_address; ///< Address of last connect()
    std::auto_ptr<SocketAddress> m_remote_address; ///< Remote end address
    IFile *m_traffic_monitor;
    time_t m_timeout_start; ///< Set by SetTimeout
    time_t m_timeout_limit; ///< Defined by SetTimeout
    bool m_bLost; ///< connection lost

#ifdef _WIN32
static  WSAInitializer m_winsock_init; ///< Winsock initialization singleton class
#endif

#ifdef HAVE_OPENSSL
    bool m_b_enable_ssl; ///< Enable SSL for this TcpSocket
    bool m_b_ssl; ///< ssl negotiation mode (TcpSocket)
    bool m_b_ssl_server; ///< True if this is an incoming ssl TcpSocket connection
#endif

#ifdef ENABLE_IPV6
    bool m_ipv6; ///< This is an ipv6 socket if this one is true
#endif

#ifdef ENABLE_POOL
    int m_socket_type; ///< Type of socket, from socket() call
    std::string m_socket_protocol; ///< Protocol, from socket() call
    bool m_bClient; ///< only client connections are pooled
    bool m_bRetain; ///< keep connection on close
#endif

#ifdef ENABLE_SOCKS4
    bool m_bSocks4; ///< socks4 negotiation mode (TcpSocket)
    ipaddr_t m_socks4_host; ///< socks4 server address
    port_t m_socks4_port; ///< socks4 server port number
    std::string m_socks4_userid; ///< socks4 server usedid
#endif

#ifdef ENABLE_DETACH
    bool m_detach; ///< Socket ordered to detach flag
    bool m_detached; ///< Socket has been detached
    SocketThread *m_pThread; ///< Detach socket thread class pointer
    ISocketHandler *m_slave_handler; ///< Actual sockethandler while detached
#endif
};

#ifdef SOCKETS_NAMESPACE
}
#endif

#endif // _SOCKETS_Socket_H


