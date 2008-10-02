/** \file Utility.cpp
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
#include "Utility.h"
#include "Parse.h"
#include "Ipv4Address.h"
#include "Ipv6Address.h"
#include "Base64.h"
#include <vector>
#ifdef _WIN32
#include <time.h>
#else
#include <netdb.h>
#include <pthread.h>
#endif
#include <map>

#ifdef SOCKETS_NAMESPACE
namespace SOCKETS_NAMESPACE {
#endif


// defines for the random number generator
#define TWIST_IA        397
#define TWIST_IB       (TWIST_LEN - TWIST_IA)
#define UMASK           0x80000000
#define LMASK           0x7FFFFFFF
#define MATRIX_A        0x9908B0DF
#define TWIST(b,i,j)   ((b)[i] & UMASK) | ((b)[j] & LMASK)
#define MAGIC_TWIST(s) (((s) & 1) * MATRIX_A)


// statics
std::string Utility::m_host;
bool Utility::m_local_resolved = false;
ipaddr_t Utility::m_ip = 0;
std::string Utility::m_addr;
#ifdef ENABLE_IPV6
#ifdef IPPROTO_IPV6
struct in6_addr Utility::m_local_ip6;
std::string Utility::m_local_addr6;
#endif
#endif


std::string Utility::base64(const std::string& str_in)
{
	std::string str;
	Base64 m_b;
	m_b.encode(str_in, str, false); // , false == do not add cr/lf
	return str;
}


std::string Utility::base64d(const std::string& str_in)
{
	std::string str;
	Base64 m_b;
	m_b.decode(str_in, str);
	return str;
}


std::string Utility::l2string(long l)
{
	std::string str;
	char tmp[100];
	sprintf(tmp,"%ld",l);
	str = tmp;
	return str;
}


std::string Utility::bigint2string(uint64_t l)
{
	std::string str;
	uint64_t tmp = l;
	while (tmp)
	{
		uint64_t a = tmp % 10;
		str = (char)(a + 48) + str;
		tmp /= 10;
	}
	if (str.empty())
	{
		str = "0";
	}
	return str;
}


uint64_t Utility::atoi64(const std::string& str) 
{
	uint64_t l = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		l = l * 10 + str[i] - 48;
	}
	return l;
}


unsigned int Utility::hex2unsigned(const std::string& str)
{
	unsigned int r = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		r = r * 16 + str[i] - 48 - ((str[i] >= 'A') ? 7 : 0) - ((str[i] >= 'a') ? 32 : 0);
	}
	return r;
}


/*
* Encode string per RFC1738 URL encoding rules
* tnx rstaveley
*/
std::string Utility::rfc1738_encode(const std::string& src)
{
static	char hex[] = "0123456789ABCDEF";
	std::string dst;
	for (size_t i = 0; i < src.size(); i++)
	{
		if (isalnum(src[i]))
		{
			dst += src[i];
		}
		else
		if (src[i] == ' ')
		{
			dst += '+';
		}
		else
		{
			unsigned char c = static_cast<unsigned char>(src[i]);
			dst += '%';
			dst += hex[c / 16];
			dst += hex[c % 16];
		}
	}
	return dst;
} // rfc1738_encode


/*
* Decode string per RFC1738 URL encoding rules
* tnx rstaveley
*/
std::string Utility::rfc1738_decode(const std::string& src)
{
	std::string dst;
	for (size_t i = 0; i < src.size(); i++)
	{
		if (src[i] == '%' && isxdigit(src[i + 1]) && isxdigit(src[i + 2]))
		{
			char c1 = src[++i];
			char c2 = src[++i];
			c1 = c1 - 48 - ((c1 >= 'A') ? 7 : 0) - ((c1 >= 'a') ? 32 : 0);
			c2 = c2 - 48 - ((c2 >= 'A') ? 7 : 0) - ((c2 >= 'a') ? 32 : 0);
			dst += (char)(c1 * 16 + c2);
		}
		else
		if (src[i] == '+')
		{
			dst += ' ';
		}
		else
		{
			dst += src[i];
		}
	}
	return dst;
} // rfc1738_decode


bool Utility::isipv4(const std::string& str)
{
	int dots = 0;
	// %! ignore :port?
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == '.')
			dots++;
		else
		if (!isdigit(str[i]))
			return false;
	}
	if (dots != 3)
		return false;
	return true;
}


bool Utility::isipv6(const std::string& str)
{
	size_t qc = 0;
	size_t qd = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		qc += (str[i] == ':') ? 1 : 0;
		qd += (str[i] == '.') ? 1 : 0;
	}
	if (qc > 7)
	{
		return false;
	}
	if (qd && qd != 3)
	{
		return false;
	}
	Parse pa(str,":.");
	std::string tmp = pa.getword();
	while (!tmp.empty())
	{
		if (tmp.size() > 4)
		{
			return false;
		}
		for (size_t i = 0; i < tmp.size(); i++)
		{
			if (tmp[i] < '0' || (tmp[i] > '9' && tmp[i] < 'A') ||
				(tmp[i] > 'F' && tmp[i] < 'a') || tmp[i] > 'f')
			{
				return false;
			}
		}
		//
		tmp = pa.getword();
	}
	return true;
}


bool Utility::u2ip(const std::string& str, ipaddr_t& l)
{
	struct sockaddr_in sa;
	bool r = Utility::u2ip(str, sa);
	memcpy(&l, &sa.sin_addr, sizeof(l));
	return r;
}


#ifdef ENABLE_IPV6
#ifdef IPPROTO_IPV6
bool Utility::u2ip(const std::string& str, struct in6_addr& l)
{
	struct sockaddr_in6 sa;
	bool r = Utility::u2ip(str, sa);
	l = sa.sin6_addr;
	return r;
}
#endif
#endif


void Utility::l2ip(const ipaddr_t ip, std::string& str)
{
	struct sockaddr_in sa;
	memset(&sa, 0, sizeof(sa));
	sa.sin_family = AF_INET;
	memcpy(&sa.sin_addr, &ip, sizeof(sa.sin_addr));
	Utility::reverse( (struct sockaddr *)&sa, sizeof(sa), str, NI_NUMERICHOST);
}


void Utility::l2ip(const in_addr& ip, std::string& str)
{
	struct sockaddr_in sa;
	memset(&sa, 0, sizeof(sa));
	sa.sin_family = AF_INET;
	sa.sin_addr = ip;
	Utility::reverse( (struct sockaddr *)&sa, sizeof(sa), str, NI_NUMERICHOST);
}


#ifdef ENABLE_IPV6
#ifdef IPPROTO_IPV6
void Utility::l2ip(const struct in6_addr& ip, std::string& str,bool mixed)
{
	char slask[100]; // l2ip temporary
	*slask = 0;
	unsigned int prev = 0;
	bool skipped = false;
	bool ok_to_skip = true;
	if (mixed)
	{
		unsigned short x;
		unsigned short addr16[8];
		memcpy(addr16, &ip, sizeof(addr16));
		for (size_t i = 0; i < 6; i++)
		{
			x = ntohs(addr16[i]);
			if (*slask && (x || !ok_to_skip || prev))
				strcat(slask,":");
			if (x || !ok_to_skip)
			{
				sprintf(slask + strlen(slask),"%x", x);
				if (x && skipped)
					ok_to_skip = false;
			}
			else
			{
				skipped = true;
			}
			prev = x;
		}
		x = ntohs(addr16[6]);
		sprintf(slask + strlen(slask),":%u.%u",x / 256,x & 255);
		x = ntohs(addr16[7]);
		sprintf(slask + strlen(slask),".%u.%u",x / 256,x & 255);
	}
	else
	{
		struct sockaddr_in6 sa;
		memset(&sa, 0, sizeof(sa));
		sa.sin6_family = AF_INET6;
		sa.sin6_addr = ip;
		Utility::reverse( (struct sockaddr *)&sa, sizeof(sa), str, NI_NUMERICHOST);
		return;
	}
	str = slask;
}


int Utility::in6_addr_compare(in6_addr a,in6_addr b)
{
	for (size_t i = 0; i < 16; i++)
	{
		if (a.s6_addr[i] < b.s6_addr[i])
			return -1;
		if (a.s6_addr[i] > b.s6_addr[i])
			return 1;
	}
	return 0;
}
#endif
#endif


void Utility::ResolveLocal()
{
	char h[256];

	// get local hostname and translate into ip-address
	*h = 0;
	gethostname(h,255);
	{
		if (Utility::u2ip(h, m_ip))
		{
			Utility::l2ip(m_ip, m_addr);
		}
	}
#ifdef ENABLE_IPV6
#ifdef IPPROTO_IPV6
	memset(&m_local_ip6, 0, sizeof(m_local_ip6));
	{
		if (Utility::u2ip(h, m_local_ip6))
		{
			Utility::l2ip(m_local_ip6, m_local_addr6);
		}
	}
#endif
#endif
	m_host = h;
	m_local_resolved = true;
}


const std::string& Utility::GetLocalHostname()
{
	if (!m_local_resolved)
	{
		ResolveLocal();
	}
	return m_host;
}


ipaddr_t Utility::GetLocalIP()
{
	if (!m_local_resolved)
	{
		ResolveLocal();
	}
	return m_ip;
}


const std::string& Utility::GetLocalAddress()
{
	if (!m_local_resolved)
	{
		ResolveLocal();
	}
	return m_addr;
}


#ifdef ENABLE_IPV6
#ifdef IPPROTO_IPV6
const struct in6_addr& Utility::GetLocalIP6()
{
	if (!m_local_resolved)
	{
		ResolveLocal();
	}
	return m_local_ip6;
}


const std::string& Utility::GetLocalAddress6()
{
	if (!m_local_resolved)
	{
		ResolveLocal();
	}
	return m_local_addr6;
}
#endif
#endif


void Utility::SetEnv(const std::string& var,const std::string& value)
{
#if (defined(SOLARIS8) || defined(SOLARIS))
	{
		static std::map<std::string, char *> vmap;
		if (vmap.find(var) != vmap.end())
		{
			delete[] vmap[var];
		}
		vmap[var] = new char[var.size() + 1 + value.size() + 1];
		sprintf(vmap[var], "%s=%s", var.c_str(), value.c_str());
		putenv( vmap[var] );
	}
#elif defined _WIN32
	{
		std::string slask = var + "=" + value;
		_putenv( (char *)slask.c_str());
	}
#else
	setenv(var.c_str(), value.c_str(), 1);
#endif
}


std::string Utility::Sa2String(struct sockaddr *sa)
{
#ifdef ENABLE_IPV6
#ifdef IPPROTO_IPV6
	if (sa -> sa_family == AF_INET6)
	{
		struct sockaddr_in6 *sa6 = (struct sockaddr_in6 *)sa;
		std::string tmp;
		Utility::l2ip(sa6 -> sin6_addr, tmp);
		return tmp + ":" + Utility::l2string(ntohs(sa6 -> sin6_port));
	}
#endif
#endif
	if (sa -> sa_family == AF_INET)
	{
		struct sockaddr_in *sa4 = (struct sockaddr_in *)sa;
		ipaddr_t a;
		memcpy(&a, &sa4 -> sin_addr, 4);
		std::string tmp;
		Utility::l2ip(a, tmp);
		return tmp + ":" + Utility::l2string(ntohs(sa4 -> sin_port));
	}
	return "";
}


void Utility::GetTime(struct timeval *p)
{
#ifdef _WIN32
	FILETIME ft; // Contains a 64-bit value representing the number of 100-nanosecond intervals since January 1, 1601 (UTC).
	GetSystemTimeAsFileTime(&ft);
	uint64_t tt;
	memcpy(&tt, &ft, sizeof(tt));
	tt /= 10; // make it usecs
	p->tv_sec = (long)tt / 1000000;
	p->tv_usec = (long)tt % 1000000;
#else
	gettimeofday(p, NULL);
#endif
}


std::auto_ptr<SocketAddress> Utility::CreateAddress(struct sockaddr *sa,socklen_t sa_len)
{
	switch (sa -> sa_family)
	{
	case AF_INET:
		if (sa_len == sizeof(struct sockaddr_in))
		{
			struct sockaddr_in *p = (struct sockaddr_in *)sa;
			return std::auto_ptr<SocketAddress>(new Ipv4Address(*p));
		}
		break;
#ifdef ENABLE_IPV6
#ifdef IPPROTO_IPV6
	case AF_INET6:
		if (sa_len == sizeof(struct sockaddr_in6))
		{
			struct sockaddr_in6 *p = (struct sockaddr_in6 *)sa;
			return std::auto_ptr<SocketAddress>(new Ipv6Address(*p));
		}
		break;
#endif
#endif
	}
	return std::auto_ptr<SocketAddress>(NULL);
}


bool Utility::u2ip(const std::string& host, struct sockaddr_in& sa, int ai_flags)
{
	memset(&sa, 0, sizeof(sa));
	sa.sin_family = AF_INET;
#ifdef NO_GETADDRINFO
	if ((ai_flags & AI_NUMERICHOST) != 0 || isipv4(host))
	{
		Parse pa((char *)host.c_str(), ".");
		union {
			struct {
				unsigned char b1;
				unsigned char b2;
				unsigned char b3;
				unsigned char b4;
			} a;
			ipaddr_t l;
		} u;
		u.a.b1 = static_cast<unsigned char>(pa.getvalue());
		u.a.b2 = static_cast<unsigned char>(pa.getvalue());
		u.a.b3 = static_cast<unsigned char>(pa.getvalue());
		u.a.b4 = static_cast<unsigned char>(pa.getvalue());
		memcpy(&sa.sin_addr, &u.l, sizeof(sa.sin_addr));
		return true;
	}
#ifndef LINUX
	struct hostent *he = gethostbyname( host.c_str() );
	if (!he)
	{
		return false;
	}
	memcpy(&sa.sin_addr, he -> h_addr, sizeof(sa.sin_addr));
#else
	struct hostent he;
	struct hostent *result = NULL;
	int myerrno = 0;
	char buf[2000];
	int n = gethostbyname_r(host.c_str(), &he, buf, sizeof(buf), &result, &myerrno);
	if (n || !result)
	{
		return false;
	}
	if (he.h_addr_list && he.h_addr_list[0])
		memcpy(&sa.sin_addr, he.h_addr, 4);
	else
		return false;
#endif
	return true;
#else
	struct addrinfo hints;
	memset(&hints, 0, sizeof(hints));
	// AI_NUMERICHOST
	// AI_CANONNAME
	// AI_PASSIVE - server
	// AI_ADDRCONFIG
	// AI_V4MAPPED
	// AI_ALL
	// AI_NUMERICSERV
	hints.ai_flags = ai_flags;
	hints.ai_family = AF_INET;
	hints.ai_socktype = 0;
	hints.ai_protocol = 0;
	struct addrinfo *res;
	if (Utility::isipv4(host))
		hints.ai_flags |= AI_NUMERICHOST;
	int n = getaddrinfo(host.c_str(), NULL, &hints, &res);
	if (!n)
	{
		std::vector<struct addrinfo *> vec;
		struct addrinfo *ai = res;
		while (ai)
		{
			if (ai -> ai_addrlen == sizeof(sa))
				vec.push_back( ai );
			ai = ai -> ai_next;
		}
		if (vec.empty())
			return false;
		ai = vec[Utility::Rnd() % vec.size()];
		{
			memcpy(&sa, ai -> ai_addr, ai -> ai_addrlen);
		}
		freeaddrinfo(res);
		return true;
	}
	std::string error = "Error: ";
#ifndef __CYGWIN__
	error += gai_strerror(n);
#endif
	return false;
#endif // NO_GETADDRINFO
}


#ifdef ENABLE_IPV6
#ifdef IPPROTO_IPV6
bool Utility::u2ip(const std::string& host, struct sockaddr_in6& sa, int ai_flags)
{
	memset(&sa, 0, sizeof(sa));
	sa.sin6_family = AF_INET6;
#ifdef NO_GETADDRINFO
	if ((ai_flags & AI_NUMERICHOST) != 0 || isipv6(host))
	{
		std::list<std::string> vec;
		size_t x = 0;
		for (size_t i = 0; i <= host.size(); i++)
		{
			if (i == host.size() || host[i] == ':')
			{
				std::string s = host.substr(x, i - x);
				//
				if (strstr(s.c_str(),".")) // x.x.x.x
				{
					Parse pa(s,".");
					char slask[100]; // u2ip temporary hex2string conversion
					unsigned long b0 = static_cast<unsigned long>(pa.getvalue());
					unsigned long b1 = static_cast<unsigned long>(pa.getvalue());
					unsigned long b2 = static_cast<unsigned long>(pa.getvalue());
					unsigned long b3 = static_cast<unsigned long>(pa.getvalue());
					sprintf(slask,"%lx",b0 * 256 + b1);
					vec.push_back(slask);
					sprintf(slask,"%lx",b2 * 256 + b3);
					vec.push_back(slask);
				}
				else
				{
					vec.push_back(s);
				}
				//
				x = i + 1;
			}
		}
		size_t sz = vec.size(); // number of byte pairs
		size_t i = 0; // index in in6_addr.in6_u.u6_addr16[] ( 0 .. 7 )
		unsigned short addr16[8];
		for (std::list<std::string>::iterator it = vec.begin(); it != vec.end(); it++)
		{
			std::string bytepair = *it;
			if (!bytepair.empty())
			{
				addr16[i++] = htons(Utility::hex2unsigned(bytepair));
			}
			else
			{
				addr16[i++] = 0;
				while (sz++ < 8)
				{
					addr16[i++] = 0;
				}
			}
		}
		memcpy(&sa.sin6_addr, addr16, sizeof(addr16));
		return true;
	}
#ifdef SOLARIS
	int errnum = 0;
	struct hostent *he = getipnodebyname( host.c_str(), AF_INET6, 0, &errnum );
#else
	struct hostent *he = gethostbyname2( host.c_str(), AF_INET6 );
#endif
	if (!he)
	{
		return false;
	}
	memcpy(&sa.sin6_addr,he -> h_addr_list[0],he -> h_length);
#ifdef SOLARIS
	free(he);
#endif
	return true;
#else
	struct addrinfo hints;
	memset(&hints, 0, sizeof(hints));
	hints.ai_flags = ai_flags;
	hints.ai_family = AF_INET6;
	hints.ai_socktype = 0;
	hints.ai_protocol = 0;
	struct addrinfo *res;
	if (Utility::isipv6(host))
		hints.ai_flags |= AI_NUMERICHOST;
	int n = getaddrinfo(host.c_str(), NULL, &hints, &res);
	if (!n)
	{
		std::vector<struct addrinfo *> vec;
		struct addrinfo *ai = res;
		while (ai)
		{
			if (ai -> ai_addrlen == sizeof(sa))
				vec.push_back( ai );
			ai = ai -> ai_next;
		}
		if (vec.empty())
			return false;
		ai = vec[Utility::Rnd() % vec.size()];
		{
			memcpy(&sa, ai -> ai_addr, ai -> ai_addrlen);
		}
		freeaddrinfo(res);
		return true;
	}
	std::string error = "Error: ";
#ifndef __CYGWIN__
	error += gai_strerror(n);
#endif
	return false;
#endif // NO_GETADDRINFO
}
#endif // IPPROTO_IPV6
#endif // ENABLE_IPV6


bool Utility::reverse(struct sockaddr *sa, socklen_t sa_len, std::string& hostname, int flags)
{
	std::string service;
	return Utility::reverse(sa, sa_len, hostname, service, flags);
}


bool Utility::reverse(struct sockaddr *sa, socklen_t sa_len, std::string& hostname, std::string& service, int flags)
{
	hostname = "";
	service = "";
#ifdef NO_GETADDRINFO
	switch (sa -> sa_family)
	{
	case AF_INET:
		if (flags & NI_NUMERICHOST)
		{
			union {
				struct {
					unsigned char b1;
					unsigned char b2;
					unsigned char b3;
					unsigned char b4;
				} a;
				ipaddr_t l;
			} u;
			struct sockaddr_in *sa_in = (struct sockaddr_in *)sa;
			memcpy(&u.l, &sa_in -> sin_addr, sizeof(u.l));
			char tmp[100];
			sprintf(tmp, "%u.%u.%u.%u", u.a.b1, u.a.b2, u.a.b3, u.a.b4);
			hostname = tmp;
			return true;
		}
		else
		{
			struct sockaddr_in *sa_in = (struct sockaddr_in *)sa;
			struct hostent *h = gethostbyaddr( (const char *)&sa_in -> sin_addr, sizeof(sa_in -> sin_addr), AF_INET);
			if (h)
			{
				hostname = h -> h_name;
				return true;
			}
		}
		break;
#ifdef ENABLE_IPV6
	case AF_INET6:
		if (flags & NI_NUMERICHOST)
		{
			char slask[100]; // l2ip temporary
			*slask = 0;
			unsigned int prev = 0;
			bool skipped = false;
			bool ok_to_skip = true;
			{
				unsigned short addr16[8];
				struct sockaddr_in6 *sa_in6 = (struct sockaddr_in6 *)sa;
				memcpy(addr16, &sa_in6 -> sin6_addr, sizeof(addr16));
				for (size_t i = 0; i < 8; i++)
				{
					unsigned short x = ntohs(addr16[i]);
					if (*slask && (x || !ok_to_skip || prev))
						strcat(slask,":");
					if (x || !ok_to_skip)
					{
						sprintf(slask + strlen(slask),"%x", x);
						if (x && skipped)
							ok_to_skip = false;
					}
					else
					{
						skipped = true;
					}
					prev = x;
				}
			}
			if (!*slask)
				strcpy(slask, "::");
			hostname = slask;
			return true;
		}
		else
		{
			// %! TODO: ipv6 reverse lookup
			struct sockaddr_in6 *sa_in = (struct sockaddr_in6 *)sa;
			struct hostent *h = gethostbyaddr( (const char *)&sa_in -> sin6_addr, sizeof(sa_in -> sin6_addr), AF_INET6);
			if (h)
			{
				hostname = h -> h_name;
				return true;
			}
		}
		break;
#endif
	}
	return false;
#else
	char host[NI_MAXHOST];
	char serv[NI_MAXSERV];
	// NI_NOFQDN
	// NI_NUMERICHOST
	// NI_NAMEREQD
	// NI_NUMERICSERV
	// NI_DGRAM
	int n = getnameinfo(sa, sa_len, host, sizeof(host), serv, sizeof(serv), flags);
	if (n)
	{
		// EAI_AGAIN
		// EAI_BADFLAGS
		// EAI_FAIL
		// EAI_FAMILY
		// EAI_MEMORY
		// EAI_NONAME
		// EAI_OVERFLOW
		// EAI_SYSTEM
		return false;
	}
	hostname = host;
	service = serv;
	return true;
#endif // NO_GETADDRINFO
}


bool Utility::u2service(const std::string& name, int& service, int ai_flags)
{
#ifdef NO_GETADDRINFO
	// %!
	return false;
#else
	struct addrinfo hints;
	service = 0;
	memset(&hints, 0, sizeof(hints));
	// AI_NUMERICHOST
	// AI_CANONNAME
	// AI_PASSIVE - server
	// AI_ADDRCONFIG
	// AI_V4MAPPED
	// AI_ALL
	// AI_NUMERICSERV
	hints.ai_flags = ai_flags;
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = 0;
	hints.ai_protocol = 0;
	struct addrinfo *res;
	int n = getaddrinfo(NULL, name.c_str(), &hints, &res);
	if (!n)
	{
		service = res -> ai_protocol;
		freeaddrinfo(res);
		return true;
	}
	return false;
#endif // NO_GETADDRINFO
}


unsigned long Utility::ThreadID()
{
#ifdef _WIN32
	return GetCurrentThreadId();
#else
	return (unsigned long)pthread_self();
#endif
}


std::string Utility::ToLower(const std::string& str)
{
	std::string r;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			r += str[i] | 32;
		else
			r += str[i];
	}
	return r;
}


std::string Utility::ToUpper(const std::string& str)
{
	std::string r;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			r += (char)(str[i] - 32);
		else
			r += str[i];
	}
	return r;
}


std::string Utility::ToString(double d)
{
	char tmp[100];
	sprintf(tmp, "%f", d);
	return tmp;
}


unsigned long Utility::Rnd()
{
static	Utility::Rng generator( (unsigned long)time(NULL) );
	return generator.Get();
}


Utility::Rng::Rng(unsigned long seed) : m_value( 0 )
{
	m_tmp[0]= seed & 0xffffffffUL;
	for (int i = 1; i < TWIST_LEN; i++)
	{
		m_tmp[i] = (1812433253UL * (m_tmp[i - 1] ^ (m_tmp[i - 1] >> 30)) + i);
	}
}
					

unsigned long Utility::Rng::Get()
{
	unsigned long val = m_tmp[m_value];
	++m_value;
	if (m_value == TWIST_LEN)
	{
		for (int i = 0; i < TWIST_IB; ++i)
		{
			unsigned long s = TWIST(m_tmp, i, i + 1);
			m_tmp[i] = m_tmp[i + TWIST_IA] ^ (s >> 1) ^ MAGIC_TWIST(s);
		}
		{
			for (int i = 0; i < TWIST_LEN - 1; ++i)
			{
				unsigned long s = TWIST(m_tmp, i, i + 1);
				m_tmp[i] = m_tmp[i - TWIST_IB] ^ (s >> 1) ^ MAGIC_TWIST(s);
			}
		}
		unsigned long s = TWIST(m_tmp, TWIST_LEN - 1, 0);
		m_tmp[TWIST_LEN - 1] = m_tmp[TWIST_IA - 1] ^ (s >> 1) ^ MAGIC_TWIST(s);

		m_value = 0;
	}
	return val;
}

#ifdef SOCKETS_NAMESPACE
}
#endif

