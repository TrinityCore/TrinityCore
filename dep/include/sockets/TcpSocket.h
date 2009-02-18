/** \file TcpSocket.h
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
#ifndef _SOCKETS_TcpSocket_H
#define _SOCKETS_TcpSocket_H
#include "sockets-config.h"
#include "StreamSocket.h"
#ifdef HAVE_OPENSSL
#include <openssl/ssl.h>
#include "SSLInitializer.h"
#endif

#include <string.h>

#define TCP_BUFSIZE_READ 16400
#define TCP_OUTPUT_CAPACITY 1024000


#ifdef SOCKETS_NAMESPACE
namespace SOCKETS_NAMESPACE {
#endif

class SocketAddress;


/** Socket implementation for TCP.
    \ingroup basic */
class TcpSocket : public StreamSocket
{
    /** \defgroup internal Internal utility */
protected:
    /** Buffer class containing one read/write circular buffer.
        \ingroup internal */
    class CircularBuffer
    {
    public:
        CircularBuffer(size_t size);
        ~CircularBuffer();

        /** append l bytes from p to buffer */
        bool Write(const char *p,size_t l);
        /** copy l bytes from buffer to dest */
        bool Read(char *dest,size_t l);
        /** copy l bytes from buffer to dest, dont touch buffer pointers */
        bool SoftRead(char *dest, size_t l);
        /** skip l bytes from buffer */
        bool Remove(size_t l);
        /** read l bytes from buffer, returns as string. */
        std::string ReadString(size_t l);

        /** total buffer length */
        size_t GetLength();
        /** pointer to circular buffer beginning */
        const char *GetStart();
        /** return number of bytes from circular buffer beginning to buffer physical end */
        size_t GetL();
        /** return free space in buffer, number of bytes until buffer overrun */
        size_t Space();

        /** return total number of bytes written to this buffer, ever */
        unsigned long ByteCounter(bool clear = false);

    private:
        CircularBuffer(const CircularBuffer& /*s*/) {}
        CircularBuffer& operator=(const CircularBuffer& ) { return *this; }
        char *buf;
        size_t m_max;
        size_t m_q;
        size_t m_b;
        size_t m_t;
        unsigned long m_count;
    };
    /** Output buffer struct.
        \ingroup internal */
    struct OUTPUT {
        OUTPUT() : _b(0), _t(0), _q(0) {}
        OUTPUT(const char *buf, size_t len) : _b(0), _t(len), _q(len) {
            memcpy(_buf, buf, len);
        }
        size_t Space() {
            return TCP_OUTPUT_CAPACITY - _t;
        }
        void Add(const char *buf, size_t len) {
            memcpy(_buf + _t, buf, len);
            _t += len;
            _q += len;
        }
        size_t Remove(size_t len) {
            _b += len;
            _q -= len;
            return _q;
        }
        const char *Buf() {
            return _buf + _b;
        }
        size_t Len() {
            return _q;
        }
        size_t _b;
        size_t _t;
        size_t _q;
        char _buf[TCP_OUTPUT_CAPACITY];
    };
    typedef std::list<OUTPUT *> output_l;

public:
    /** Constructor with standard values on input/output buffers. */
    TcpSocket(ISocketHandler& );
    /** Constructor with custom values for i/o buffer.
        \param h ISocketHandler reference
        \param isize Input buffer size
        \param osize Output buffer size */
    TcpSocket(ISocketHandler& h,size_t isize,size_t osize);
    ~TcpSocket();

    /** Open a connection to a remote server.
        If you want your socket to connect to a server,
        always call Open before Add'ing a socket to the sockethandler.
        If not, the connection attempt will not be monitored by the
        socket handler...
        \param ip IP address
        \param port Port number
        \param skip_socks Do not use socks4 even if configured */
    bool Open(ipaddr_t ip,port_t port,bool skip_socks = false);
#ifdef ENABLE_IPV6
#ifdef IPPROTO_IPV6
    /** Open connection.
        \param ip Ipv6 address
        \param port Port number
        \param skip_socks Do not use socks4 even if configured */
    bool Open(in6_addr ip,port_t port,bool skip_socks = false);
#endif
#endif
    bool Open(SocketAddress&,bool skip_socks = false);
    bool Open(SocketAddress&,SocketAddress& bind_address,bool skip_socks = false);
    /** Open connection.
        \param host Hostname
        \param port Port number */
    bool Open(const std::string &host,port_t port);

    /** Connect timeout callback. */
    void OnConnectTimeout();
#ifdef _WIN32
    /** Connection failed reported as exception on win32 */
    void OnException();
#endif

    /** Close file descriptor - internal use only.
        \sa SetCloseAndDelete */
    int Close();

    /** Send a string.
        \param s String to send
        \param f Dummy flags -- not used */
    void Send(const std::string &s,int f = 0);
    /** Send string using printf formatting. */
    void Sendf(const char *format, ...);
    /** Send buffer of bytes.
        \param buf Buffer pointer
        \param len Length of data
        \param f Dummy flags -- not used */
    void SendBuf(const char *buf,size_t len,int f = 0);
    /** This callback is executed after a successful read from the socket.
        \param buf Pointer to the data
        \param len Length of the data */
    virtual void OnRawData(const char *buf,size_t len);

    /** Called when output buffer has been sent.
        Note: Will only be called IF the output buffer has been used.
        Send's that was successful without needing the output buffer
        will not generate a call to this method. */
    virtual void OnWriteComplete();
    /** Number of bytes in input buffer. */
    size_t GetInputLength();
    /** Number of bytes in output buffer. */
    size_t GetOutputLength();

    /** Callback fires when a socket in line protocol has read one full line.
        \param line Line read */
    void OnLine(const std::string& line);
    /** Get counter of number of bytes received. */
    uint64_t GetBytesReceived(bool clear = false);
    /** Get counter of number of bytes sent. */
    uint64_t GetBytesSent(bool clear = false);

    /** Socks4 specific callback. */
    void OnSocks4Connect();
    /** Socks4 specific callback. */
    void OnSocks4ConnectFailed();
    /** Socks4 specific callback.
        \return 'need_more' */
    bool OnSocks4Read();

#ifdef ENABLE_RESOLVER
    /** Callback executed when resolver thread has finished a resolve request. */
    void OnResolved(int id,ipaddr_t a,port_t port);
#ifdef ENABLE_IPV6
    void OnResolved(int id,in6_addr& a,port_t port);
#endif
#endif
#ifdef HAVE_OPENSSL
    /** Callback for 'New' ssl support - replaces SSLSocket. Internal use. */
    void OnSSLConnect();
    /** Callback for 'New' ssl support - replaces SSLSocket. Internal use. */
    void OnSSLAccept();
    /** This method must be implemented to initialize
        the ssl context for an outgoing connection. */
    virtual void InitSSLClient();
    /** This method must be implemented to initialize
        the ssl context for an incoming connection. */
    virtual void InitSSLServer();
#endif

#ifdef ENABLE_RECONNECT
    /** Flag that says a broken connection will try to reconnect. */
    void SetReconnect(bool = true);
    /** Check reconnect on lost connection flag status. */
    bool Reconnect();
    /** Flag to determine if a reconnect is in progress. */
    void SetIsReconnect(bool x = true);
    /** Socket is reconnecting. */
    bool IsReconnect();
#endif

    void DisableInputBuffer(bool = true);

    void OnOptions(int,int,int,SOCKET);

    void SetLineProtocol(bool = true);

    // TCP options
    bool SetTcpNodelay(bool = true);

    virtual int Protocol();

    /** Trigger limit for callback OnTransferLimit. */
    void SetTransferLimit(size_t sz);
    /** This callback fires when the output buffer drops below the value
        set by SetTransferLimit. Default: 0 (disabled). */
    virtual void OnTransferLimit();

protected:
    TcpSocket(const TcpSocket& );
    void OnRead();
    void OnRead( char *buf, size_t n );
    void OnWrite();
#ifdef HAVE_OPENSSL
    /** SSL; Initialize ssl context for a client socket.
        \param meth_in SSL method */
    void InitializeContext(const std::string& context, SSL_METHOD *meth_in = NULL);
    /** SSL; Initialize ssl context for a server socket.
        \param keyfile Combined private key/certificate file
        \param password Password for private key
        \param meth_in SSL method */
    void InitializeContext(const std::string& context, const std::string& keyfile, const std::string& password, SSL_METHOD *meth_in = NULL);
    /** SSL; Initialize ssl context for a server socket.
        \param certfile Separate certificate file
        \param keyfile Combined private key/certificate file
        \param password Password for private key
        \param meth_in SSL method */
    void InitializeContext(const std::string& context, const std::string& certfile, const std::string& keyfile, const std::string& password, SSL_METHOD *meth_in = NULL);
    /** SSL; Password callback method. */
static  int SSL_password_cb(char *buf,int num,int rwflag,void *userdata);
    /** SSL; Get pointer to ssl context structure. */
    virtual SSL_CTX *GetSslContext();
    /** SSL; Get pointer to ssl structure. */
    virtual SSL *GetSsl();
    /** ssl; still negotiating connection. */
    bool SSLNegotiate();
    /** SSL; Get ssl password. */
    const std::string& GetPassword();
#endif

    CircularBuffer ibuf; ///< Circular input buffer

private:
    TcpSocket& operator=(const TcpSocket& ) { return *this; }

    /** the actual send() */
    int TryWrite(const char *buf, size_t len);
    /** add data to output buffer top */
    void Buffer(const char *buf, size_t len);

    //
    bool m_b_input_buffer_disabled;
    uint64_t m_bytes_sent;
    uint64_t m_bytes_received;
    bool m_skip_c; ///< Skip second char of CRLF or LFCR sequence in OnRead
    char m_c; ///< First char in CRLF or LFCR sequence
    std::string m_line; ///< Current line in line protocol mode
#ifdef SOCKETS_DYNAMIC_TEMP
    char *m_buf; ///< temporary read buffer
#endif
    output_l m_obuf; ///< output buffer
    OUTPUT *m_obuf_top; ///< output buffer on top
    size_t m_transfer_limit;
    size_t m_output_length;

#ifdef HAVE_OPENSSL
static  SSLInitializer m_ssl_init;
    SSL_CTX *m_ssl_ctx; ///< ssl context
    SSL *m_ssl; ///< ssl 'socket'
    BIO *m_sbio; ///< ssl bio
    std::string m_password; ///< ssl password
#endif

#ifdef ENABLE_SOCKS4
    int m_socks4_state; ///< socks4 support
    char m_socks4_vn; ///< socks4 support, temporary variable
    char m_socks4_cd; ///< socks4 support, temporary variable
    unsigned short m_socks4_dstport; ///< socks4 support
    unsigned long m_socks4_dstip; ///< socks4 support
#endif

#ifdef ENABLE_RESOLVER
    int m_resolver_id; ///< Resolver id (if any) for current Open call
#endif

#ifdef ENABLE_RECONNECT
    bool m_b_reconnect; ///< Reconnect on lost connection flag
    bool m_b_is_reconnect; ///< Trying to reconnect
#endif

};


#ifdef SOCKETS_NAMESPACE
}
#endif

#endif // _SOCKETS_TcpSocket_H


