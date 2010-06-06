/**
 ** \file SctpSocket.h
 ** \date  2006-09-04
 ** \author grymse@alhem.net
**/
/*
Copyright (C) 2007  Anders Hedstrom

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
#ifndef _SOCKETS_SctpSocket_H
#define _SOCKETS_SctpSocket_H
#include "sockets-config.h"

#include "StreamSocket.h"
#ifdef USE_SCTP
#include <netinet/sctp.h>

#ifdef SOCKETS_NAMESPACE
namespace SOCKETS_NAMESPACE {
#endif

#define SCTP_BUFSIZE_READ 16400

class SocketAddress;

class SctpSocket : public StreamSocket
{
public:
    /** SctpSocket constructor.
        \param h Owner
        \param type SCTP_STREAM or SCTP_SEQPACKET */
    SctpSocket(ISocketHandler& h,int type);
    ~SctpSocket();

    /** bind() */
    int Bind(const std::string&,port_t);
    int Bind(SocketAddress&);
    /** sctp_bindx() */
    int AddAddress(const std::string&,port_t);
    int AddAddress(SocketAddress&);
    /** sctp_bindx() */
    int RemoveAddress(const std::string&,port_t);
    int RemoveAddress(SocketAddress&);

    /** connect() */
    int Open(const std::string&,port_t);
    int Open(SocketAddress&);

    /** Connect timeout callback. */
    void OnConnectTimeout();
#ifdef _WIN32
    /** Connection failed reported as exception on win32 */
    void OnException();
#endif

#ifndef SOLARIS
    /** sctp_connectx() */
    int AddConnection(const std::string&,port_t);
    int AddConnection(SocketAddress&);
#endif

    /** Get peer addresses of an association. */
    int getpaddrs(sctp_assoc_t id,std::list<std::string>&);
    /** Get all bound addresses of an association. */
    int getladdrs(sctp_assoc_t id,std::list<std::string>&);

    /** sctp_peeloff */
    int PeelOff(sctp_assoc_t id);

    /** recvmsg callback */
    virtual void OnReceiveMessage(const char *buf,size_t sz,struct sockaddr *sa,socklen_t sa_len,struct sctp_sndrcvinfo *sinfo,int msg_flags) = 0;

    void OnOptions(int,int,int,SOCKET) {}

    virtual int Protocol();

protected:
    SctpSocket(const SctpSocket& s) : StreamSocket(s) {}
    void OnRead();
    void OnWrite();

private:
    SctpSocket& operator=(const SctpSocket& s) { return *this; }
    int m_type; ///< SCTP_STREAM or SCTP_SEQPACKET
    char *m_buf; ///< Temporary receive buffer
};

#ifdef SOCKETS_NAMESPACE
} // namespace SOCKETS_NAMESPACE
#endif

#endif // USE_SCTP
#endif // _SOCKETS_SctpSocket_H


