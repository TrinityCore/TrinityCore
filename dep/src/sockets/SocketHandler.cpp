/** \file SocketHandler.cpp
 **	\date  2004-02-13
 **	\author grymse@alhem.net
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
#endif
#include <stdlib.h>
#include <errno.h>

#include "SocketHandler.h"
#include "UdpSocket.h"
#include "ResolvSocket.h"
#include "ResolvServer.h"
#include "TcpSocket.h"
#include "Mutex.h"
#include "Utility.h"
#include "SocketAddress.h"

#ifdef SOCKETS_NAMESPACE
namespace SOCKETS_NAMESPACE {
#endif


//#ifdef _DEBUG
//#define DEB(x) x; fflush(stderr);
//#else
#define DEB(x) 
//#endif


SocketHandler::SocketHandler(StdLog *p)
:m_stdlog(p)
,m_mutex(m_mutex)
,m_b_use_mutex(false)
,m_maxsock(0)
,m_preverror(-1)
,m_errcnt(0)
,m_tlast(0)
#ifdef ENABLE_SOCKS4
,m_socks4_host(0)
,m_socks4_port(0)
,m_bTryDirect(false)
#endif
#ifdef ENABLE_RESOLVER
,m_resolv_id(0)
,m_resolver(NULL)
#endif
#ifdef ENABLE_POOL
,m_b_enable_pool(false)
#endif
#ifdef ENABLE_TRIGGERS
,m_next_trigger_id(0)
#endif
#ifdef ENABLE_DETACH
,m_slave(false)
#endif
{
	FD_ZERO(&m_rfds);
	FD_ZERO(&m_wfds);
	FD_ZERO(&m_efds);
}


SocketHandler::SocketHandler(Mutex& mutex,StdLog *p)
:m_stdlog(p)
,m_mutex(mutex)
,m_b_use_mutex(true)
,m_maxsock(0)
,m_preverror(-1)
,m_errcnt(0)
,m_tlast(0)
#ifdef ENABLE_SOCKS4
,m_socks4_host(0)
,m_socks4_port(0)
,m_bTryDirect(false)
#endif
#ifdef ENABLE_RESOLVER
,m_resolv_id(0)
,m_resolver(NULL)
#endif
#ifdef ENABLE_POOL
,m_b_enable_pool(false)
#endif
#ifdef ENABLE_TRIGGERS
,m_next_trigger_id(0)
#endif
#ifdef ENABLE_DETACH
,m_slave(false)
#endif
{
	m_mutex.Lock();
	FD_ZERO(&m_rfds);
	FD_ZERO(&m_wfds);
	FD_ZERO(&m_efds);
}


SocketHandler::~SocketHandler()
{
#ifdef ENABLE_RESOLVER
	if (m_resolver)
	{
		m_resolver -> Quit();
	}
#endif
	{
		while (m_sockets.size())
		{
DEB(			fprintf(stderr, "Emptying sockets list in SocketHandler destructor, %d instances\n", (int)m_sockets.size());)
			socket_m::iterator it = m_sockets.begin();
			Socket *p = it -> second;
			if (p)
			{
DEB(				fprintf(stderr, "  fd %d\n", p -> GetSocket());)
				p -> Close();
DEB(				fprintf(stderr, "  fd closed %d\n", p -> GetSocket());)
//				p -> OnDelete(); // hey, I turn this back on. what's the worst that could happen??!!
				// MinionSocket breaks, calling MinderHandler methods in OnDelete -
				// MinderHandler is already gone when that happens...

				// only delete socket when controlled
				// ie master sockethandler can delete non-detached sockets
				// and a slave sockethandler can only delete a detach socket
				if (p -> DeleteByHandler()
#ifdef ENABLE_DETACH
					&& !(m_slave ^ p -> IsDetached()) 
#endif
					)
				{
					p -> SetErasedByHandler();
					delete p;
				}
				m_sockets.erase(it);
			}
			else
			{
				m_sockets.erase(it);
			}
DEB(			fprintf(stderr, "next\n");)
		}
DEB(		fprintf(stderr, "/Emptying sockets list in SocketHandler destructor, %d instances\n", (int)m_sockets.size());)
	}
#ifdef ENABLE_RESOLVER
	if (m_resolver)
	{
		delete m_resolver;
	}
#endif
	if (m_b_use_mutex)
	{
		m_mutex.Unlock();
	}
}


Mutex& SocketHandler::GetMutex() const
{
	return m_mutex; 
}


#ifdef ENABLE_DETACH
void SocketHandler::SetSlave(bool x)
{
	m_slave = x;
}


bool SocketHandler::IsSlave()
{
	return m_slave;
}
#endif


void SocketHandler::RegStdLog(StdLog *log)
{
	m_stdlog = log;
}


void SocketHandler::LogError(Socket *p,const std::string& user_text,int err,const std::string& sys_err,loglevel_t t)
{
	if (m_stdlog)
	{
		m_stdlog -> error(this, p, user_text, err, sys_err, t);
	}
}


void SocketHandler::Add(Socket *p)
{
	if (p -> GetSocket() == INVALID_SOCKET)
	{
		LogError(p, "Add", -1, "Invalid socket", LOG_LEVEL_WARNING);
		if (p -> CloseAndDelete())
		{
			m_delete.push_back(p);
		}
		return;
	}
	if (m_add.find(p -> GetSocket()) != m_add.end())
	{
		LogError(p, "Add", (int)p -> GetSocket(), "Attempt to add socket already in add queue", LOG_LEVEL_FATAL);
		m_delete.push_back(p);
		return;
	}
	m_add[p -> GetSocket()] = p;
}


void SocketHandler::Get(SOCKET s,bool& r,bool& w,bool& e)
{
	if (s >= 0)
	{
		r = FD_ISSET(s, &m_rfds) ? true : false;
		w = FD_ISSET(s, &m_wfds) ? true : false;
		e = FD_ISSET(s, &m_efds) ? true : false;
	}
}


void SocketHandler::Set(SOCKET s,bool bRead,bool bWrite,bool bException)
{
DEB(	fprintf(stderr, "Set(%d, %s, %s, %s)\n", s, bRead ? "true" : "false", bWrite ? "true" : "false", bException ? "true" : "false");)
	if (s >= 0)
	{
		if (bRead)
		{
			if (!FD_ISSET(s, &m_rfds))
			{
				FD_SET(s, &m_rfds);
			}
		}
		else
		{
			FD_CLR(s, &m_rfds);
		}
		if (bWrite)
		{
			if (!FD_ISSET(s, &m_wfds))
			{
				FD_SET(s, &m_wfds);
			}
		}
		else
		{
			FD_CLR(s, &m_wfds);
		}
		if (bException)
		{
			if (!FD_ISSET(s, &m_efds))
			{
				FD_SET(s, &m_efds);
			}
		}
		else
		{
			FD_CLR(s, &m_efds);
		}
	}
}


int SocketHandler::Select(long sec,long usec)
{
	struct timeval tv;
	tv.tv_sec = sec;
	tv.tv_usec = usec;
	return Select(&tv);
}


int SocketHandler::Select()
{
	if (!m_fds_callonconnect.empty() ||
#ifdef ENABLE_DETACH
		(!m_slave && !m_fds_detach.empty()) ||
#endif
		!m_fds_timeout.empty() ||
		!m_fds_retry.empty() ||
		!m_fds_close.empty() ||
		!m_fds_erase.empty())
	{
		return Select(0, 200000);
	}
	return Select(NULL);
}


int SocketHandler::Select(struct timeval *tsel)
{
	size_t ignore = 0;
	while (m_add.size() > ignore)
	{
		if (m_sockets.size() >= FD_SETSIZE)
		{
			LogError(NULL, "Select", (int)m_sockets.size(), "FD_SETSIZE reached", LOG_LEVEL_WARNING);
			break;
		}
		socket_m::iterator it = m_add.begin();
		SOCKET s = it -> first;
		Socket *p = it -> second;
DEB(		fprintf(stderr, "Trying to add fd %d,  m_add.size() %d,  ignore %d\n", (int)s, (int)m_add.size(), (int)ignore);)
		//
		if (m_sockets.find(p -> GetSocket()) != m_sockets.end())
		{
			LogError(p, "Add", (int)p -> GetSocket(), "Attempt to add socket already in controlled queue", LOG_LEVEL_FATAL);
			// %! it's a dup, don't add to delete queue, just ignore it
			m_delete.push_back(p);
			m_add.erase(it);
//			ignore++;
			continue;
		}
		if (!p -> CloseAndDelete())
		{
			StreamSocket *scp = dynamic_cast<StreamSocket *>(p);
			if (scp && scp -> Connecting()) // 'Open' called before adding socket
			{
				Set(s,false,true);
			}
			else
			{
				TcpSocket *tcp = dynamic_cast<TcpSocket *>(p);
				bool bWrite = tcp ? tcp -> GetOutputLength() != 0 : false;
				if (p -> IsDisableRead())
				{
					Set(s, false, bWrite);
				}
				else
				{
					Set(s, true, bWrite);
				}
			}
			m_maxsock = (s > m_maxsock) ? s : m_maxsock;
		}
		else
		{
			LogError(p, "Add", (int)p -> GetSocket(), "Trying to add socket with SetCloseAndDelete() true", LOG_LEVEL_WARNING);
		}
		// only add to m_fds (process fd_set events) if
		//  slave handler and detached/detaching socket
		//  master handler and non-detached socket
#ifdef ENABLE_DETACH
		if (!(m_slave ^ p -> IsDetach()))
#endif
		{
			m_fds.push_back(s);
		}
		m_sockets[s] = p;
		//
		m_add.erase(it);
	}
#ifdef MACOSX
	fd_set rfds;
	fd_set wfds;
	fd_set efds;
	FD_COPY(&m_rfds, &rfds);
	FD_COPY(&m_wfds, &wfds);
	FD_COPY(&m_efds, &efds);
#else
	fd_set rfds = m_rfds;
	fd_set wfds = m_wfds;
	fd_set efds = m_efds;
#endif
	int n;
	if (m_b_use_mutex)
	{
		m_mutex.Unlock();
		n = select( (int)(m_maxsock + 1),&rfds,&wfds,&efds,tsel);
		m_mutex.Lock();
	}
	else
	{
		n = select( (int)(m_maxsock + 1),&rfds,&wfds,&efds,tsel);
	}
	if (n == -1)
	{
		/*
			EBADF  An invalid file descriptor was given in one of the sets.
			EINTR  A non blocked signal was caught.
			EINVAL n is negative. Or struct timeval contains bad time values (<0).
			ENOMEM select was unable to allocate memory for internal tables.
		*/
		if (Errno != m_preverror || m_errcnt++ % 10000 == 0)
		{
			LogError(NULL, "select", Errno, StrError(Errno));
DEB(			fprintf(stderr, "m_maxsock: %d\n", m_maxsock);
			fprintf(stderr, "%s\n", Errno == EINVAL ? "EINVAL" :
				Errno == EINTR ? "EINTR" :
				Errno == EBADF ? "EBADF" :
				Errno == ENOMEM ? "ENOMEM" : "<another>");
			// test bad fd
			for (SOCKET i = 0; i <= m_maxsock; i++)
			{
				bool t = false;
				FD_ZERO(&rfds);
				FD_ZERO(&wfds);
				FD_ZERO(&efds);
				if (FD_ISSET(i, &m_rfds))
				{
					FD_SET(i, &rfds);
					t = true;
				}
				if (FD_ISSET(i, &m_wfds))
				{
					FD_SET(i, &wfds);
					t = true;
				}
				if (FD_ISSET(i, &m_efds))
				{
					FD_SET(i, &efds);
					t = true;
				}
				if (t && m_sockets.find(i) == m_sockets.end())
				{
					fprintf(stderr, "Bad fd in fd_set: %d\n", i);
				}
			}
) // DEB
			m_preverror = Errno;
		}
		/// \todo rebuild fd_set's from active sockets list (m_sockets) here
	}
	else
	if (!n)
	{
		m_preverror = -1;
	}
	else
	if (n > 0)
	{
		for (socket_v::iterator it2 = m_fds.begin(); it2 != m_fds.end() && n; it2++)
		{
			SOCKET i = *it2;
			if (FD_ISSET(i, &rfds))
			{
				socket_m::iterator itmp = m_sockets.find(i);
				if (itmp != m_sockets.end()) // found
				{
					Socket *p = itmp -> second;
					// new SSL negotiate method
#ifdef HAVE_OPENSSL
					if (p -> IsSSLNegotiate())
					{
						p -> SSLNegotiate();
					}
					else
#endif
					{
						p -> OnRead();
					}
				}
				else
				{
					LogError(NULL, "GetSocket/handler/1", (int)i, "Did not find expected socket using file descriptor", LOG_LEVEL_WARNING);
				}
				n--;
			}
			if (FD_ISSET(i, &wfds))
			{
				socket_m::iterator itmp = m_sockets.find(i);
				if (itmp != m_sockets.end()) // found
				{
					Socket *p = itmp -> second;
					// new SSL negotiate method
#ifdef HAVE_OPENSSL
					if (p -> IsSSLNegotiate())
					{
						p -> SSLNegotiate();
					}
					else
#endif
					{
						p -> OnWrite();
					}
				}
				else
				{
					LogError(NULL, "GetSocket/handler/2", (int)i, "Did not find expected socket using file descriptor", LOG_LEVEL_WARNING);
				}
				n--;
			}
			if (FD_ISSET(i, &efds))
			{
				socket_m::iterator itmp = m_sockets.find(i);
				if (itmp != m_sockets.end()) // found
				{
					Socket *p = itmp -> second;
					p -> OnException();
				}
				else
				{
					LogError(NULL, "GetSocket/handler/3", (int)i, "Did not find expected socket using file descriptor", LOG_LEVEL_WARNING);
				}
				n--;
			}
		} // m_fds loop
		m_preverror = -1;
	} // if (n > 0)

	// check CallOnConnect - EVENT
	if (!m_fds_callonconnect.empty())
	{
		socket_v tmp = m_fds_callonconnect;
		for (socket_v::iterator it = tmp.begin(); it != tmp.end(); it++)
		{
			Socket *p = NULL;
			{
				socket_m::iterator itmp = m_sockets.find(*it);
				if (itmp != m_sockets.end()) // found
				{
					p = itmp -> second;
				}
				else
				{
					LogError(NULL, "GetSocket/handler/4", (int)*it, "Did not find expected socket using file descriptor", LOG_LEVEL_WARNING);
				}
			}
			if (p)
			{
//				if (p -> CallOnConnect() && p -> Ready() )
				{
					p -> SetConnected(); // moved here from inside if (tcp) check below
#ifdef HAVE_OPENSSL
					if (p -> IsSSL()) // SSL Enabled socket
						p -> OnSSLConnect();
					else
#endif
#ifdef ENABLE_SOCKS4
					if (p -> Socks4())
						p -> OnSocks4Connect();
					else
#endif
					{
						TcpSocket *tcp = dynamic_cast<TcpSocket *>(p);
						if (tcp)
						{
							if (tcp -> GetOutputLength())
							{
								p -> OnWrite();
							}
						}
#ifdef ENABLE_RECONNECT
						if (tcp && tcp -> IsReconnect())
							p -> OnReconnect();
						else
#endif
						{
//							LogError(p, "Calling OnConnect", 0, "Because CallOnConnect", LOG_LEVEL_INFO);
							p -> OnConnect();
						}
					}
//					p -> SetCallOnConnect( false );
					AddList(p -> GetSocket(), LIST_CALLONCONNECT, false);
				}
			}
		}
	}
#ifdef ENABLE_DETACH
	// check detach of socket if master handler - EVENT
	if (!m_slave && !m_fds_detach.empty())
	{
		// %! why not using tmp list here??!?
		for (socket_v::iterator it = m_fds_detach.begin(); it != m_fds_detach.end(); it++)
		{
			Socket *p = NULL;
			{
				socket_m::iterator itmp = m_sockets.find(*it);
				if (itmp != m_sockets.end()) // found
				{
					p = itmp -> second;
				}
				else
				{
					LogError(NULL, "GetSocket/handler/5", (int)*it, "Did not find expected socket using file descriptor", LOG_LEVEL_WARNING);
				}
			}
			if (p)
			{
//				if (p -> IsDetach())
				{
					Set(p -> GetSocket(), false, false, false);
					// After DetachSocket(), all calls to Handler() will return a reference
					// to the new slave SocketHandler running in the new thread.
					p -> DetachSocket();
					// Adding the file descriptor to m_fds_erase will now also remove the
					// socket from the detach queue - tnx knightmad
					m_fds_erase.push_back(p -> GetSocket());
				}
			}
		}
	}
#endif
	// check Connecting - connection timeout - conditional event
	if (m_fds_timeout.size())
	{
		time_t tnow = time(NULL);
		if (tnow != m_tlast)
		{
			socket_v tmp = m_fds_timeout;
DEB(			fprintf(stderr, "Checking %d socket(s) for timeout\n", tmp.size());)
			for (socket_v::iterator it = tmp.begin(); it != tmp.end(); it++)
			{
				Socket *p = NULL;
				{
					socket_m::iterator itmp = m_sockets.find(*it);
					if (itmp != m_sockets.end()) // found
					{
						p = itmp -> second;
					}
					else
					{
						itmp = m_add.find(*it);
						if (itmp != m_add.end())
						{
							p = itmp -> second;
						}
						else
						{
							LogError(NULL, "GetSocket/handler/6", (int)*it, "Did not find expected socket using file descriptor", LOG_LEVEL_WARNING);
						}
					}
				}
				if (p)
				{
					if (p -> Timeout(tnow))
					{
						StreamSocket *scp = dynamic_cast<StreamSocket *>(p);
						if (scp && scp -> Connecting())
							p -> OnConnectTimeout();
						else
							p -> OnTimeout();
						p -> SetTimeout(0);
					}
				}
			}
			m_tlast = tnow;
		} // tnow != tlast
	}
	// check retry client connect - EVENT
	if (!m_fds_retry.empty())
	{
		socket_v tmp = m_fds_retry;
		for (socket_v::iterator it = tmp.begin(); it != tmp.end(); it++)
		{
			Socket *p = NULL;
			{
				socket_m::iterator itmp = m_sockets.find(*it);
				if (itmp != m_sockets.end()) // found
				{
					p = itmp -> second;
				}
				else
				{
					LogError(NULL, "GetSocket/handler/7", (int)*it, "Did not find expected socket using file descriptor", LOG_LEVEL_WARNING);
				}
			}
			if (p)
			{
//				if (p -> RetryClientConnect())
				{
					TcpSocket *tcp = dynamic_cast<TcpSocket *>(p);
					SOCKET nn = *it; //(*it3).first;
					tcp -> SetRetryClientConnect(false);
DEB(					fprintf(stderr, "Close() before retry client connect\n");)
					p -> Close(); // removes from m_fds_retry
					std::auto_ptr<SocketAddress> ad = p -> GetClientRemoteAddress();
					if (ad.get())
					{
						tcp -> Open(*ad);
					}
					else
					{
						LogError(p, "RetryClientConnect", 0, "no address", LOG_LEVEL_ERROR);
					}
					Add(p);
					m_fds_erase.push_back(nn);
				}
			}
		}
	}
	// check close and delete - conditional event
	if (!m_fds_close.empty())
	{
		socket_v tmp = m_fds_close;
DEB(		fprintf(stderr, "m_fds_close.size() == %d\n", (int)m_fds_close.size());)
		for (socket_v::iterator it = tmp.begin(); it != tmp.end(); it++)
		{
			Socket *p = NULL;
			{
				socket_m::iterator itmp = m_sockets.find(*it);
				if (itmp != m_sockets.end()) // found
				{
					p = itmp -> second;
				}
				else
				{
					itmp = m_add.find(*it);
					if (itmp != m_add.end())
					{
						p = itmp -> second;
					}
					else
					{
						LogError(NULL, "GetSocket/handler/8", (int)*it, "Did not find expected socket using file descriptor", LOG_LEVEL_WARNING);
					}
				}
			}
			if (p)
			{
//				if (p -> CloseAndDelete() )
				{
					TcpSocket *tcp = dynamic_cast<TcpSocket *>(p);
					// new graceful tcp - flush and close timeout 5s
					if (tcp && p -> IsConnected() && tcp -> GetFlushBeforeClose() && 
#ifdef HAVE_OPENSSL
						!tcp -> IsSSL() && 
#endif
						p -> TimeSinceClose() < 5)
					{
DEB(						fprintf(stderr, " close(1)\n");)
						if (tcp -> GetOutputLength())
						{
							LogError(p, "Closing", (int)tcp -> GetOutputLength(), "Sending all data before closing", LOG_LEVEL_INFO);
						}
						else // shutdown write when output buffer is empty
						if (!(tcp -> GetShutdown() & SHUT_WR))
						{
							SOCKET nn = *it;
							if (nn != INVALID_SOCKET && shutdown(nn, SHUT_WR) == -1)
							{
								LogError(p, "graceful shutdown", Errno, StrError(Errno), LOG_LEVEL_ERROR);
							}
							tcp -> SetShutdown(SHUT_WR);
						}
					}
					else
#ifdef ENABLE_RECONNECT
					if (tcp && p -> IsConnected() && tcp -> Reconnect())
					{
						SOCKET nn = *it; //(*it3).first;
DEB(						fprintf(stderr, " close(2) fd %d\n", nn);)
						p -> SetCloseAndDelete(false);
						tcp -> SetIsReconnect();
						p -> SetConnected(false);
DEB(						fprintf(stderr, "Close() before reconnect\n");)
						p -> Close(); // dispose of old file descriptor (Open creates a new)
						p -> OnDisconnect();
						std::auto_ptr<SocketAddress> ad = p -> GetClientRemoteAddress();
						if (ad.get())
						{
							tcp -> Open(*ad);
						}
						else
						{
							LogError(p, "Reconnect", 0, "no address", LOG_LEVEL_ERROR);
						}
						tcp -> ResetConnectionRetries();
						Add(p);
						m_fds_erase.push_back(nn);
					}
					else
#endif
					{
						SOCKET nn = *it; //(*it3).first;
DEB(						fprintf(stderr, " close(3) fd %d GetSocket() %d\n", nn, p -> GetSocket());)
						if (tcp && p -> IsConnected() && tcp -> GetOutputLength())
						{
							LogError(p, "Closing", (int)tcp -> GetOutputLength(), "Closing socket while data still left to send", LOG_LEVEL_WARNING);
						}
#ifdef ENABLE_POOL
						if (p -> Retain() && !p -> Lost())
						{
							PoolSocket *p2 = new PoolSocket(*this, p);
							p2 -> SetDeleteByHandler();
							Add(p2);
							//
							p -> SetCloseAndDelete(false); // added - remove from m_fds_close
						}
						else
#endif // ENABLE_POOL
						{
							Set(p -> GetSocket(),false,false,false);
DEB(							fprintf(stderr, "Close() before OnDelete\n");)
							p -> Close();
						}
						p -> OnDelete();
						if (p -> DeleteByHandler())
						{
							p -> SetErasedByHandler();
						}
						m_fds_erase.push_back(nn);
					}
				}
			}
		}
	}

	// check erased sockets
	bool check_max_fd = false;
	while (!m_fds_erase.empty())
	{
		socket_v::iterator it = m_fds_erase.begin();
		SOCKET nn = *it;
#ifdef ENABLE_DETACH
		{
			for (socket_v::iterator it = m_fds_detach.begin(); it != m_fds_detach.end(); it++)
			{
				if (*it == nn)
				{
					m_fds_detach.erase(it);
					break;
				}
			}
		}
#endif
		{
			for (socket_v::iterator it = m_fds.begin(); it != m_fds.end(); it++)
			{
				if (*it == nn)
				{
					m_fds.erase(it);
					break;
				}
			}
		}
		{
			socket_m::iterator it = m_sockets.find(nn);
			if (it != m_sockets.end())
			{
				Socket *p = it -> second;
				/* Sometimes a SocketThread class can finish its run before the master
				   sockethandler gets here. In that case, the SocketThread has set the
				   'ErasedByHandler' flag on the socket which will make us end up with a
				   double delete on the socket instance. 
				   The fix is to make sure that the master sockethandler only can delete
				   non-detached sockets, and a slave sockethandler only can delete
				   detach sockets. */
				if (p -> ErasedByHandler()
#ifdef ENABLE_DETACH
					&& !(m_slave ^ p -> IsDetached()) 
#endif
					)
				{
#ifdef ENABLE_TRIGGERS
					bool again = false;
					do
					{
						again = false;
						for (std::map<int, Socket *>::iterator it = m_trigger_src.begin(); it != m_trigger_src.end(); it++)
						{
							int id = it -> first;
							Socket *src = it -> second;
							if (src == p)
							{
								for (std::map<Socket *, bool>::iterator it = m_trigger_dst[id].begin(); it != m_trigger_dst[id].end(); it++)
								{
									Socket *dst = it -> first;
									if (Valid(dst))
									{
										dst -> OnCancelled(id);
									}
								}
								m_trigger_src.erase(m_trigger_src.find(id));
								m_trigger_dst.erase(m_trigger_dst.find(id));
								again = true;
								break;
							}
						}
					} while (again);
#endif
					delete p;
				}
				m_sockets.erase(it);
			}
		}
		m_fds_erase.erase(it);
		check_max_fd = true;
	}
	// calculate max file descriptor for select() call
	if (check_max_fd)
	{
		m_maxsock = 0;
		for (socket_v::iterator it = m_fds.begin(); it != m_fds.end(); it++)
		{
			SOCKET s = *it;
			m_maxsock = s > m_maxsock ? s : m_maxsock;
		}
	}
	// remove Add's that fizzed
	while (!m_delete.empty())
	{
		std::list<Socket *>::iterator it = m_delete.begin();
		Socket *p = *it;
		p -> OnDelete();
		m_delete.erase(it);
		if (p -> DeleteByHandler()
#ifdef ENABLE_DETACH
			&& !(m_slave ^ p -> IsDetached()) 
#endif
			)
		{
			p -> SetErasedByHandler();
#ifdef ENABLE_TRIGGERS
			bool again = false;
			do
			{
				again = false;
				for (std::map<int, Socket *>::iterator it = m_trigger_src.begin(); it != m_trigger_src.end(); it++)
				{
					int id = it -> first;
					Socket *src = it -> second;
					if (src == p)
					{
						for (std::map<Socket *, bool>::iterator it = m_trigger_dst[id].begin(); it != m_trigger_dst[id].end(); it++)
						{
							Socket *dst = it -> first;
							if (Valid(dst))
							{
								dst -> OnCancelled(id);
							}
						}
						m_trigger_src.erase(m_trigger_src.find(id));
						m_trigger_dst.erase(m_trigger_dst.find(id));
						again = true;
						break;
					}
				}
			} while (again);
#endif
			delete p;
		}
	}
	return n;
}


#ifdef ENABLE_RESOLVER
bool SocketHandler::Resolving(Socket *p0)
{
	std::map<Socket *, bool>::iterator it = m_resolve_q.find(p0);
	return it != m_resolve_q.end();
}
#endif


bool SocketHandler::Valid(Socket *p0)
{
	for (socket_m::iterator it = m_sockets.begin(); it != m_sockets.end(); it++)
	{
		Socket *p = it -> second;
		if (p0 == p)
			return true;
	}
	return false;
}


bool SocketHandler::OkToAccept(Socket *)
{
	return true;
}


size_t SocketHandler::GetCount()
{
/*
printf(" m_sockets : %d\n", m_sockets.size());
printf(" m_add     : %d\n", m_add.size());
printf(" m_delete  : %d\n", m_delete.size());
*/
	return m_sockets.size() + m_add.size() + m_delete.size();
}


#ifdef ENABLE_SOCKS4
void SocketHandler::SetSocks4Host(ipaddr_t a)
{
	m_socks4_host = a;
}


void SocketHandler::SetSocks4Host(const std::string& host)
{
	Utility::u2ip(host, m_socks4_host);
}


void SocketHandler::SetSocks4Port(port_t port)
{
	m_socks4_port = port;
}


void SocketHandler::SetSocks4Userid(const std::string& id)
{
	m_socks4_userid = id;
}
#endif


#ifdef ENABLE_RESOLVER
int SocketHandler::Resolve(Socket *p,const std::string& host,port_t port)
{
	// check cache
	ResolvSocket *resolv = new ResolvSocket(*this, p, host, port);
	resolv -> SetId(++m_resolv_id);
	resolv -> SetDeleteByHandler();
	ipaddr_t local;
	Utility::u2ip("127.0.0.1", local);
	if (!resolv -> Open(local, m_resolver_port))
	{
		LogError(resolv, "Resolve", -1, "Can't connect to local resolve server", LOG_LEVEL_FATAL);
	}
	Add(resolv);
	m_resolve_q[p] = true;
DEB(	fprintf(stderr, " *** Resolve '%s:%d' id#%d  m_resolve_q size: %d  p: %p\n", host.c_str(), port, resolv -> GetId(), m_resolve_q.size(), p);)
	return resolv -> GetId();
}


#ifdef ENABLE_IPV6
int SocketHandler::Resolve6(Socket *p,const std::string& host,port_t port)
{
	// check cache
	ResolvSocket *resolv = new ResolvSocket(*this, p, host, port, true);
	resolv -> SetId(++m_resolv_id);
	resolv -> SetDeleteByHandler();
	ipaddr_t local;
	Utility::u2ip("127.0.0.1", local);
	if (!resolv -> Open(local, m_resolver_port))
	{
		LogError(resolv, "Resolve", -1, "Can't connect to local resolve server", LOG_LEVEL_FATAL);
	}
	Add(resolv);
	m_resolve_q[p] = true;
	return resolv -> GetId();
}
#endif


int SocketHandler::Resolve(Socket *p,ipaddr_t a)
{
	// check cache
	ResolvSocket *resolv = new ResolvSocket(*this, p, a);
	resolv -> SetId(++m_resolv_id);
	resolv -> SetDeleteByHandler();
	ipaddr_t local;
	Utility::u2ip("127.0.0.1", local);
	if (!resolv -> Open(local, m_resolver_port))
	{
		LogError(resolv, "Resolve", -1, "Can't connect to local resolve server", LOG_LEVEL_FATAL);
	}
	Add(resolv);
	m_resolve_q[p] = true;
	return resolv -> GetId();
}


#ifdef ENABLE_IPV6
int SocketHandler::Resolve(Socket *p,in6_addr& a)
{
	// check cache
	ResolvSocket *resolv = new ResolvSocket(*this, p, a);
	resolv -> SetId(++m_resolv_id);
	resolv -> SetDeleteByHandler();
	ipaddr_t local;
	Utility::u2ip("127.0.0.1", local);
	if (!resolv -> Open(local, m_resolver_port))
	{
		LogError(resolv, "Resolve", -1, "Can't connect to local resolve server", LOG_LEVEL_FATAL);
	}
	Add(resolv);
	m_resolve_q[p] = true;
	return resolv -> GetId();
}
#endif


void SocketHandler::EnableResolver(port_t port)
{
	if (!m_resolver)
	{
		m_resolver_port = port;
		m_resolver = new ResolvServer(port);
	}
}


bool SocketHandler::ResolverReady()
{
	return m_resolver ? m_resolver -> Ready() : false;
}
#endif // ENABLE_RESOLVER


#ifdef ENABLE_SOCKS4
void SocketHandler::SetSocks4TryDirect(bool x)
{
	m_bTryDirect = x;
}


ipaddr_t SocketHandler::GetSocks4Host()
{
	return m_socks4_host;
}


port_t SocketHandler::GetSocks4Port()
{
	return m_socks4_port;
}


const std::string& SocketHandler::GetSocks4Userid()
{
	return m_socks4_userid;
}


bool SocketHandler::Socks4TryDirect()
{
	return m_bTryDirect;
}
#endif


#ifdef ENABLE_RESOLVER
bool SocketHandler::ResolverEnabled() 
{ 
	return m_resolver ? true : false; 
}


port_t SocketHandler::GetResolverPort() 
{ 
	return m_resolver_port; 
}
#endif // ENABLE_RESOLVER


#ifdef ENABLE_POOL
ISocketHandler::PoolSocket *SocketHandler::FindConnection(int type,const std::string& protocol,SocketAddress& ad)
{
	for (socket_m::iterator it = m_sockets.begin(); it != m_sockets.end() && !m_sockets.empty(); it++)
	{
		PoolSocket *pools = dynamic_cast<PoolSocket *>(it -> second);
		if (pools)
		{
			if (pools -> GetSocketType() == type &&
			    pools -> GetSocketProtocol() == protocol &&
// %!			    pools -> GetClientRemoteAddress() &&
			    *pools -> GetClientRemoteAddress() == ad)
			{
				m_sockets.erase(it);
				pools -> SetRetain(); // avoid Close in Socket destructor
				return pools; // Caller is responsible that this socket is deleted
			}
		}
	}
	return NULL;
}


void SocketHandler::EnablePool(bool x)
{
	m_b_enable_pool = x;
}


bool SocketHandler::PoolEnabled() 
{ 
	return m_b_enable_pool; 
}
#endif


void SocketHandler::Remove(Socket *p)
{
#ifdef ENABLE_RESOLVER
	std::map<Socket *, bool>::iterator it4 = m_resolve_q.find(p);
	if (it4 != m_resolve_q.end())
		m_resolve_q.erase(it4);
#endif
	if (p -> ErasedByHandler())
	{
		return;
	}
	for (socket_m::iterator it = m_sockets.begin(); it != m_sockets.end(); it++)
	{
		if (it -> second == p)
		{
			LogError(p, "Remove", -1, "Socket destructor called while still in use", LOG_LEVEL_WARNING);
			m_sockets.erase(it);
			return;
		}
	}
	for (socket_m::iterator it2 = m_add.begin(); it2 != m_add.end(); it2++)
	{
		if ((*it2).second == p)
		{
			LogError(p, "Remove", -2, "Socket destructor called while still in use", LOG_LEVEL_WARNING);
			m_add.erase(it2);
			return;
		}
	}
	for (std::list<Socket *>::iterator it3 = m_delete.begin(); it3 != m_delete.end(); it3++)
	{
		if (*it3 == p)
		{
			LogError(p, "Remove", -3, "Socket destructor called while still in use", LOG_LEVEL_WARNING);
			m_delete.erase(it3);
			return;
		}
	}
}


void SocketHandler::CheckSanity()
{
	CheckList(m_fds, "active sockets"); // active sockets
	CheckList(m_fds_erase, "sockets to be erased"); // should always be empty anyway
	CheckList(m_fds_callonconnect, "checklist CallOnConnect");
#ifdef ENABLE_DETACH
	CheckList(m_fds_detach, "checklist Detach");
#endif
	CheckList(m_fds_timeout, "checklist Timeout");
	CheckList(m_fds_retry, "checklist retry client connect");
	CheckList(m_fds_close, "checklist close and delete");
}


void SocketHandler::CheckList(socket_v& ref,const std::string& listname)
{
	for (socket_v::iterator it = ref.begin(); it != ref.end(); it++)
	{
		SOCKET s = *it;
		if (m_sockets.find(s) != m_sockets.end())
			continue;
		if (m_add.find(s) != m_add.end())
			continue;
		bool found = false;
		for (std::list<Socket *>::iterator it = m_delete.begin(); it != m_delete.end(); it++)
		{
			Socket *p = *it;
			if (p -> GetSocket() == s)
			{
				found = true;
				break;
			}
		}
		if (!found)
		{
			fprintf(stderr, "CheckList failed for \"%s\": fd %d\n", listname.c_str(), s);
		}
	}
}


void SocketHandler::AddList(SOCKET s,list_t which_one,bool add)
{
	if (s == INVALID_SOCKET)
	{
DEB(		fprintf(stderr, "AddList:  invalid_socket\n");)
		return;
	}
	socket_v& ref =
		(which_one == LIST_CALLONCONNECT) ? m_fds_callonconnect :
#ifdef ENABLE_DETACH
		(which_one == LIST_DETACH) ? m_fds_detach :
#endif
		(which_one == LIST_TIMEOUT) ? m_fds_timeout :
		(which_one == LIST_RETRY) ? m_fds_retry :
		(which_one == LIST_CLOSE) ? m_fds_close : m_fds_close;
	if (add)
	{
#ifdef ENABLE_DETACH
DEB(	fprintf(stderr, "AddList;  %5d: %s: %s\n", s, (which_one == LIST_CALLONCONNECT) ? "CallOnConnect" :
		(which_one == LIST_DETACH) ? "Detach" :
		(which_one == LIST_TIMEOUT) ? "Timeout" :
		(which_one == LIST_RETRY) ? "Retry" :
		(which_one == LIST_CLOSE) ? "Close" : "<undef>",
		add ? "Add" : "Remove");)
#else
DEB(	fprintf(stderr, "AddList;  %5d: %s: %s\n", s, (which_one == LIST_CALLONCONNECT) ? "CallOnConnect" :
		(which_one == LIST_TIMEOUT) ? "Timeout" :
		(which_one == LIST_RETRY) ? "Retry" :
		(which_one == LIST_CLOSE) ? "Close" : "<undef>",
		add ? "Add" : "Remove");)
#endif
	}
	if (add)
	{
		for (socket_v::iterator it = ref.begin(); it != ref.end(); it++)
		{
			if (*it == s) // already there
			{
				return;
			}
		}
		ref.push_back(s);
		return;
	}
	// remove
	for (socket_v::iterator it = ref.begin(); it != ref.end(); it++)
	{
		if (*it == s)
		{
			ref.erase(it);
			break;
		}
	}
//DEB(	fprintf(stderr, "/AddList\n");)
}


#ifdef ENABLE_TRIGGERS
int SocketHandler::TriggerID(Socket *src)
{
	int id = m_next_trigger_id++;
	m_trigger_src[id] = src;
	return id;
}


bool SocketHandler::Subscribe(int id, Socket *dst)
{
	if (m_trigger_src.find(id) != m_trigger_src.end())
	{
		std::map<Socket *, bool>::iterator it = m_trigger_dst[id].find(dst);
		if (it != m_trigger_dst[id].end())
		{
			m_trigger_dst[id][dst] = true;
			return true;
		}
		LogError(dst, "Subscribe", id, "Already subscribed", LOG_LEVEL_INFO);
		return false;
	}
	LogError(dst, "Subscribe", id, "Trigger id not found", LOG_LEVEL_INFO);
	return false;
}


bool SocketHandler::Unsubscribe(int id, Socket *dst)
{
	if (m_trigger_src.find(id) != m_trigger_src.end())
	{
		std::map<Socket *, bool>::iterator it = m_trigger_dst[id].find(dst);
		if (it != m_trigger_dst[id].end())
		{
			m_trigger_dst[id].erase(it);
			return true;
		}
		LogError(dst, "Unsubscribe", id, "Not subscribed", LOG_LEVEL_INFO);
		return false;
	}
	LogError(dst, "Unsubscribe", id, "Trigger id not found", LOG_LEVEL_INFO);
	return false;
}


void SocketHandler::Trigger(int id, Socket::TriggerData& data, bool erase)
{
	if (m_trigger_src.find(id) != m_trigger_src.end())
	{
		data.SetSource( m_trigger_src[id] );
		for (std::map<Socket *, bool>::iterator it = m_trigger_dst[id].begin(); it != m_trigger_dst[id].end(); it++)
		{
			Socket *dst = it -> first;
			if (Valid(dst))
			{
				dst -> OnTrigger(id, data);
			}
		}
		if (erase)
		{
			m_trigger_src.erase(m_trigger_src.find(id));
			m_trigger_dst.erase(m_trigger_dst.find(id));
		}
	}
	else
	{
		LogError(NULL, "Trigger", id, "Trigger id not found", LOG_LEVEL_INFO);
	}
}
#endif // ENABLE_TRIGGERS


#ifdef SOCKETS_NAMESPACE
}
#endif

