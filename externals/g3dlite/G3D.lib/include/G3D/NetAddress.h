#ifndef G3D_NETADDRESS_H
#define G3D_NETADDRESS_H

#include "G3D/platform.h"
#include "G3D/Table.h"

/** These control the version of Winsock used by G3D.
    Version 2.0 is standard for G3D 6.09 and later.
    Version 1.1 is standard for G3D 6.08 and earlier.
 */
#define G3D_WINSOCK_MAJOR_VERSION 2
#define G3D_WINSOCK_MINOR_VERSION 0

#ifdef G3D_WIN32
#   if (G3D_WINSOCK_MAJOR_VERSION == 2)
#       include <winsock2.h>
#   elif (G3D_WINSOCK_MAJOR_VERSION == 1)
#       include <winsock.h>
#   endif
#else
#   include <sys/types.h>
#   include <sys/socket.h>
#   include <netinet/in.h>
#   ifndef SOCKADDR_IN
#       define SOCKADDR_IN struct sockaddr_in
#   endif
#   ifndef SOCKET
#       define SOCKET int
#   endif
#endif

#include "G3D/g3dmath.h"

namespace G3D {

class NetAddress {
private:
    friend class NetworkDevice;
    friend class LightweightConduit;
    friend class ReliableConduit;

    /** Host byte order */
    void init(uint32 host, uint16 port);
    void init(const std::string& hostname, uint16 port);
    NetAddress(const SOCKADDR_IN& a);
    NetAddress(const struct in_addr& addr, uint16 port = 0);

    SOCKADDR_IN                 addr;

public:
    /**
     In host byte order
     */
    NetAddress(uint32 host, uint16 port = 0);

    /**
     @param port Specified in host byte order (i.e., don't worry about endian issues)
     */
    NetAddress(const std::string& hostname, uint16 port);

    /**
       @param hostnameAndPort in the form "hostname:port" or "ip:port"
     */
    NetAddress(const std::string& hostnameAndPort);

    /**
       @deprecated Use G3D::NetworkDevice::broadcastAddressArray()

     @brief Creates a UDP broadcast address for use with a
     G3D::LightweightConduit.

     UDP broadcast allows one machine to send a packet to all machines
     on the same local network. The IP portion of the address is
     0xFFFFFFFF, which indicates "broadcast" to the underlying socket
     API.  This feature is not available with the connection-based TCP
     protocol abstracted by G3D::ReliableConduit; use multisend
     instead.
     */
    static NetAddress broadcastAddress(uint16 port);

    NetAddress();

    void serialize(class BinaryOutput& b) const;
    void deserialize(class BinaryInput& b);

    /** @brief Returns true if this is not an illegal address. */
    bool ok() const;

    /** @brief Returns a value in host format (i.e., don't worry about
        endian issues) */
    inline uint32 ip() const {
        return ntohl(addr.sin_addr.s_addr);
        //return ntohl(addr.sin_addr.S_un.S_addr);
    }

    inline uint16 port() const {
        return ntohs(addr.sin_port);
    }

    std::string ipString() const;
    std::string toString() const;

};

std::ostream& operator<<(std::ostream& os, const NetAddress&);

} // namespace G3D

template <> struct HashTrait<G3D::NetAddress> {
    static size_t hashCode(const G3D::NetAddress& key) { 
        return static_cast<size_t>(key.ip() + (static_cast<G3D::uint32>(key.port()) << 16));
    }
};

namespace G3D {

/**
 Two addresses may point to the same computer but be != because
 they have different IP's.
 */
inline bool operator==(const NetAddress& a, const NetAddress& b) {
	return (a.ip() == b.ip()) && (a.port() == b.port());
}


inline bool operator!=(const NetAddress& a, const NetAddress& b) {
    return !(a == b);
}

} // namespace G3D

#endif
