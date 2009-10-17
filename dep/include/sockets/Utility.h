/** \file Utility.h
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
#ifndef _SOCKETS_Utility_H
#define _SOCKETS_Utility_H

#include "sockets-config.h"
#include <ctype.h>
#include <string.h>
#include <memory>
#include "socket_include.h"
#include <map>
#include <string>

#ifdef SOCKETS_NAMESPACE
namespace SOCKETS_NAMESPACE {
#endif

#define TWIST_LEN     624

class SocketAddress;

/** Conversion utilities.
    \ingroup util */
class Utility
{
    /**
        The Mersenne Twister
        http://www.math.keio.ac.jp/~matumoto/emt.html
    */
    class Rng {
    public:
        Rng(unsigned long seed);

        unsigned long Get();

    private:
        int m_value;
        unsigned long m_tmp[TWIST_LEN];
    };
    class ncmap_compare {
    public:
        bool operator()(const std::string& x, const std::string& y) const {
            return strcasecmp(x.c_str(), y.c_str()) < 0;
        }
    };
public:
    template<typename Y> class ncmap : public std::map<std::string, Y, ncmap_compare> {
    public:
        ncmap() {}
    };
public:
    static std::string base64(const std::string& str_in);
    static std::string base64d(const std::string& str_in);
    static std::string l2string(long l);
    static std::string bigint2string(uint64_t l);
    static uint64_t atoi64(const std::string& str);
    static unsigned int hex2unsigned(const std::string& str);
    static std::string rfc1738_encode(const std::string& src);
    static std::string rfc1738_decode(const std::string& src);

    /** Checks whether a string is a valid ipv4/ipv6 ip number. */
    static bool isipv4(const std::string&);
    /** Checks whether a string is a valid ipv4/ipv6 ip number. */
    static bool isipv6(const std::string&);

    /** Hostname to ip resolution ipv4, not asynchronous. */
    static bool u2ip(const std::string&, ipaddr_t&);
    static bool u2ip(const std::string&, struct sockaddr_in& sa, int ai_flags = 0);

#ifdef ENABLE_IPV6
#ifdef IPPROTO_IPV6
    /** Hostname to ip resolution ipv6, not asynchronous. */
    static bool u2ip(const std::string&, struct in6_addr&);
    static bool u2ip(const std::string&, struct sockaddr_in6& sa, int ai_flags = 0);
#endif
#endif

    /** Reverse lookup of address to hostname */
    static bool reverse(struct sockaddr *sa, socklen_t sa_len, std::string&, int flags = 0);
    static bool reverse(struct sockaddr *sa, socklen_t sa_len, std::string& hostname, std::string& service, int flags = 0);

    static bool u2service(const std::string& name, int& service, int ai_flags = 0);

    /** Convert binary ip address to string: ipv4. */
    static void l2ip(const ipaddr_t,std::string& );
    static void l2ip(const in_addr&,std::string& );
#ifdef ENABLE_IPV6
#ifdef IPPROTO_IPV6
    /** Convert binary ip address to string: ipv6. */
    static void l2ip(const struct in6_addr&,std::string& ,bool mixed = false);

    /** ipv6 address compare. */
    static int in6_addr_compare(in6_addr,in6_addr);
#endif
#endif
    /** ResolveLocal (hostname) - call once before calling any GetLocal method. */
    static void ResolveLocal();
    /** Returns local hostname, ResolveLocal must be called once before using.
        \sa ResolveLocal */
    static const std::string& GetLocalHostname();
    /** Returns local ip, ResolveLocal must be called once before using.
        \sa ResolveLocal */
    static ipaddr_t GetLocalIP();
    /** Returns local ip number as string.
        \sa ResolveLocal */
    static const std::string& GetLocalAddress();
#ifdef ENABLE_IPV6
#ifdef IPPROTO_IPV6
    /** Returns local ipv6 ip.
        \sa ResolveLocal */
    static const struct in6_addr& GetLocalIP6();
    /** Returns local ipv6 address.
        \sa ResolveLocal */
    static const std::string& GetLocalAddress6();
#endif
#endif
    /** Set environment variable.
        \param var Name of variable to set
        \param value Value */
    static void SetEnv(const std::string& var,const std::string& value);
    /** Convert sockaddr struct to human readable string.
        \param sa Ptr to sockaddr struct */
    static std::string Sa2String(struct sockaddr *sa);

    /** Get current time in sec/microseconds. */
    static void GetTime(struct timeval *);

    static std::auto_ptr<SocketAddress> CreateAddress(struct sockaddr *,socklen_t);

    static unsigned long ThreadID();

    static std::string ToLower(const std::string& str);
    static std::string ToUpper(const std::string& str);

    static std::string ToString(double d);

    /** Returns a random 32-bit integer */
    static unsigned long Rnd();

private:
    static std::string m_host; ///< local hostname
    static ipaddr_t m_ip; ///< local ip address
    static std::string m_addr; ///< local ip address in string format
#ifdef ENABLE_IPV6
#ifdef IPPROTO_IPV6
    static struct in6_addr m_local_ip6; ///< local ipv6 address
#endif
    static std::string m_local_addr6; ///< local ipv6 address in string format
#endif
    static bool m_local_resolved; ///< ResolveLocal has been called if true
};

#ifdef SOCKETS_NAMESPACE
}
#endif

#endif // _SOCKETS_Utility_H


