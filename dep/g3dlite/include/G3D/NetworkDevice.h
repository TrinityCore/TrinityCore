/**
 @file NetworkDevice.h
 These classes abstract networking from the socket level to a
 serialized messaging style that is more appropriate for games.  The
 performance has been tuned for sending many small messages.  The
 message protocol contains a header that prevents them from being used
 with raw UDP/TCP (e.g. connecting to an HTTP server). 

 LightweightConduit and ReliableConduits have different interfaces
 because they have different semantics.  You would never want to
 interchange them without rewriting the surrounding code.

 NetworkDevice creates conduits because they need access to a global
 log pointer and because I don't want non-reference counted conduits
 being created.

 Be careful with threads and reference counting.  The reference
 counters are not threadsafe, and are also not updated correctly if a
 thread is explicitly killed.  Since the conduits will be passed by
 const XConduitRef& most of the time this doesn't appear as a major
 problem.  With non-blocking conduits, you should need few threads
 anyway.

 LightweightConduits preceed each message with a 4-byte host order
 unsigned integer that is the message type.  This does not appear in
 the message serialization/deserialization.

 ReliableConduits preceed each message with two 4-byte host order
 unsigned integers.  The first is the message type and the second
 indicates the length of the rest of the data.  The size does not
 include the size of the header itself.  The minimum message is 9
 bytes:a 4-byte type, a 4-byte header equal to "1", and one byte of data.

 @maintainer Morgan McGuire, http://graphics.cs.williams.edu
 @created 2002-11-22
 @edited  2006-11-25
 */

#ifndef G3D_NETWORKDEVICE_H
#define G3D_NETWORKDEVICE_H

#include "G3D/platform.h"
#include "G3D/NetAddress.h"

#include <string>
#include <iostream>
#include "G3D/g3dmath.h"

#include "G3D/ReferenceCount.h"
#include "G3D/Array.h"
#include "G3D/BinaryOutput.h"

namespace G3D {

class TextOutput;
/**  \deprecated */
class Conduit : public ReferenceCountedObject {
protected:
    friend class NetworkDevice;
    friend class NetListener;

    uint64                          mSent;
    uint64                          mReceived;
    uint64                          bSent;
    uint64                          bReceived;

    SOCKET                          sock;

    /**
     Used for serialization.  One per socket
     to make this threadsafe.
     */
    BinaryOutput                    binaryOutput;

    Conduit();

public:

    virtual ~Conduit();
    uint64 bytesSent() const;
    uint64 messagesSent() const;
    uint64 bytesReceived() const;
    uint64 messagesReceived() const;

    /**
     If true, receive will return true.
     */
    virtual bool messageWaiting();

    /**
     Returns the type of the waiting message (i.e. the type supplied
     with send).  The return value is zero when there is no message
     waiting.

     One way to use this is to have a Table mapping message types to
     pre-allocated subclasses so receiving looks like:

     <PRE>
         // My base class for messages.
         class Message {
             virtual void serialize(BinaryOutput&) const;
             virtual void deserialize(BinaryInput&);
             virtual void process() = 0;
         };

         Message* m = table[conduit->waitingMessageType()];
         conduit->receive(m);
         m->process();
     </PRE>

      Another is to simply switch on the message type:

      <pre>
         switch (conduit->waitingMessageType()) {
         case 0:
            // No message
            break;

         case ENTITY_SPAWN_MSG:
            {
               EntitySpawnMsg m;
               condiut->receive(m);
               spawnEntity(m.id, m.position, m.modelID);
            }
            break;
            ...
         }
      </pre>
     */
    virtual uint32 waitingMessageType() = 0;

    /** Returns true if the connection is ok. */
    bool ok() const;
};

typedef shared_ptr<class ReliableConduit> ReliableConduitRef;

#ifdef __GNUC__
// Workaround for a known bug in gcc 4.x where htonl produces 
// a spurrious warning.
// http://gcc.gnu.org/ml/gcc-bugs/2005-10/msg03270.html
uint32 gcchtonl(uint32);
#endif

// Messaging and stream APIs must be supported on a single class because
// sometimes an application will switch modes on a single socket.  For
// example, when transferring 3D level geometry during handshaking with
// a game server.
/**
 A conduit that guarantees messages will arrive, intact and in order.
 Create on the client using NetworkDevice::createReliableConduit and
 on the server using NetListener::waitForConnection.  Set the reference
 counted pointer to NULL to disconnect.

 To construct a ReliableConduit:
 <OL>
   <LI> Create a G3D::NetworkDevice (if you are using G3D::GApp, it creates 
        one for you) on the client and on the server.
   <LI> On the server, create a G3D::NetListener using 
        G3D::NetworkDevice::createListener
   <LI> On the server, invoke G3D::NetListener::waitForConnection.
   <LI> On the client, call G3D::NetworkDevice::createReliableConduit.  
        You will need the server's G3D::NetAddress.  Consider using
        G3D::Discovery::Client to find it via broadcasting.
 </OL>
 \deprecated
 */
class ReliableConduit : public Conduit {
private:
    friend class NetworkDevice;
    friend class NetListener;

    enum State {RECEIVING, HOLDING, NO_MESSAGE} state;

    NetAddress                      addr;
    
    /**
     Type of the incoming message.
     */
    uint32                          messageType;

    /** 
     Total size of the incoming message (read from the header).
     */
    uint32                          messageSize;

    /** Shared buffer for receiving messages. */
    void*                           receiveBuffer;

    /** Total size of the receiveBuffer. */
    size_t                          receiveBufferTotalSize;

    /** Size occupied by the current message... so far.  This will be
        equal to messageSize when the whole message has arrived. 
      */
    size_t                          receiveBufferUsedSize;

    ReliableConduit(const NetAddress& addr);

    ReliableConduit(const SOCKET& sock, 
                    const NetAddress& addr);

    template<typename T> static void serializeMessage
              (uint32 t, const T& m, BinaryOutput& b) {

        b.writeUInt32(t);

        // Reserve space for the 4 byte size header
        b.writeUInt32(0);

        size_t L = (size_t)b.length();
        m.serialize(b);
        if ((size_t)b.length() == L) {
            // No data was created by serialization.
            // We need to send at least one byte because receive assumes that
            // a zero length message is an error.
            b.writeUInt8(0xFF);
        }
    
        uint32 len = (uint32)b.size() - 8;
    
        // We send the length first to tell recv how much data to read.
        // Here we abuse BinaryOutput a bit and write directly into
        // its buffer, violating the abstraction.
        // Note that we write to the second set of 4 bytes, which is
        // the size field.
        uint32* lenPtr = ((uint32*)b.getCArray()) + 1;
        #if defined(__GNUC__)
            *lenPtr = gcchtonl(len);
        #else
            *lenPtr = htonl(len);
        #endif
    }


    void sendBuffer(const BinaryOutput& b);

    /** Accumulates whatever part of the message (not the header) is
        still waiting on the socket into the receiveBuffer during
        state = RECEIVING mode.  Closes the socket if anything goes
        wrong.  When receiveBufferUsedSize == messageSize, the entire
        message has arrived. */
    void receiveIntoBuffer();

    /** Receives the messageType and messageSize from the socket. */
    void receiveHeader();

public:

    /**
     Client invokes this to connect to a server.  The call blocks until the 
     conduit is opened.  The conduit will not be ok() if it fails.
     */
    static ReliableConduitRef create(const NetAddress& address);

    /** Closes the socket. */
    ~ReliableConduit();


    /** The message is actually copied from the socket to an internal buffer during
     this call.  Receive only deserializes.*/
    virtual bool messageWaiting();

    /**
     Serializes the message and schedules it to be sent as soon as possible,
     and then returns immediately.  The message can be any <B>class</B> with
     a serialize and deserialize method.  On the receiving side,
     use G3D::ReliableConduit::waitingMessageType() to detect the incoming
     message and then invoke G3D::ReliableConduit::receive(msg) where msg
     is of the same class as the message that was sent.

     The actual data sent across the network is preceeded by the
     message type and the size of the serialized message as a 32-bit
     integer.  The size is sent because TCP is a stream protocol and
     doesn't have a concept of discrete messages.
     */
    template<typename T> inline void send(uint32 type, const T& message) {
        binaryOutput.reset();
        serializeMessage(type, message, binaryOutput);
        sendBuffer(binaryOutput);
    }
    
    /** Sends an empty message with the given type.  Useful for sending 
        commands that have no parameters. */
    void send(uint32 type);

    /** Send the same message to a number of conduits.  Useful for sending
        data from a server to many clients (only serializes once). */
    template<typename T>
    inline static void multisend(
        const Array<ReliableConduitRef>& array, 
        uint32                          type,
        const T&                        m) {
        
        if (array.size() > 0) {
            array[0]->binaryOutput.reset();
            serializeMessage(type, m, array[0]->binaryOutput);

            for (int i = 0; i < array.size(); ++i) {
                array[i]->sendBuffer(array[0]->binaryOutput);
            }
        }
    }

    virtual uint32 waitingMessageType();

    /** 
        If a message is waiting, deserializes the waiting message into
        message and returns true, otherwise returns false.  You can
        determine the type of the message (and therefore, the class
        of message) using G3D::ReliableConduit::waitingMessageType().
     */
    template<typename T> inline bool receive(T& message) {
        if (! messageWaiting()) {
            return false;
        }

        debugAssert(state == HOLDING);
        // Deserialize
        BinaryInput b((uint8*)receiveBuffer, receiveBufferUsedSize, G3D_LITTLE_ENDIAN, BinaryInput::NO_COPY);
        message.deserialize(b);
        
        // Don't let anyone read this message again.  We leave the buffer
        // allocated for the next caller, however.
        receiveBufferUsedSize = 0;
        state = NO_MESSAGE;
        messageType = 0;
        messageSize = 0;

        // Potentially read the next message.
        messageWaiting();

        return true;
    }

    /** Removes the current message from the queue. */
    inline void receive() {
        if (! messageWaiting()) {
            return;
        }
        receiveBufferUsedSize = 0;
        state = NO_MESSAGE;
        messageType = 0;
        messageSize = 0;

        // Potentially read the next message.
        messageWaiting();
    }

    /** The address of the other end of the conduit */
    NetAddress address() const;
};


typedef shared_ptr<class LightweightConduit> LightweightConduitRef;

/**
 Provides fast but unreliable transfer of messages.  On a LAN,
 LightweightConduit will probably never drop messages but you
 <I>might</I> get your messages out of order.  On an internet
 connection it might drop messages altogether.  Messages are never
 corrupted, however.  LightweightConduit requires a little less setup
 and overhead than ReliableConduit.  ReliableConduit guarantees
 message delivery and order but requires a persistent connection.
 
 To set up a LightweightConduit (assuming you have already made
 subclasses of G3D::NetMessage based on your application's
 pcommunication protocol):

[Server Side]
<OL>
<LI> Call LightweightConduit::create(port, true, false), 
where port is the port on which you will receive messages.

<LI> Poll LightweightConduit::messageWaiting from your main loop.  When 
it is true (or, equivalently, when LightweightConduit::waitingMessageType
is non-zero) there is an incoming message.

<LI> To read the incoming message, call LightweightConduit::receive with 
the appropriate class type, which mist have a deserialize method.
LightweightConduit::waitingMessageType tells you what class is 
needed (you make up your own message constants for your program; numbers 
under 1000 are reserved for G3D's internal use).

<LI> When done, simply set the G3D::LightweightConduitRef to NULL or let 
it go out of scope and the conduit cleans itself up automatically.
</OL>

[Client Side]
<OL>
<LI> Call G3D::LightweightConduit::create().  If you will 
broadcast to all servers on a LAN, set the third optional argument to 
true (the default is false for no broadcast).  You can also set up the
receive port as if it was a server to send and receive from a single 
LightweightConduit.

<LI> To send, call G3D::LightweightConduit::send with the target address 
and a pointer to an instance of the message you want to send.

<LI> When done, simply set the G3D::LightweightConduitRef to NULL or let 
it go out of scope and the conduit cleans itself up automatically.

</OL>

\deprecated
 */
class LightweightConduit : public Conduit {
private:
    friend class NetworkDevice;

    /**
     True when waitingForMessageType has read the message
     from the network into messageType/messageStream.
     */
    bool                    alreadyReadMessage;

    /**
     Origin of the received message.
     */
    NetAddress              messageSender;

    /**
     The type of the last message received.
     */
    uint32                  messageType;

    /**
     The message received (the type has already been read off).
     */
    Array<uint8>            messageBuffer;

    LightweightConduit(uint16 receivePort, bool enableReceive, bool enableBroadcast);
    
    void sendBuffer(const NetAddress& a, BinaryOutput& b);

    /** Maximum transmission unit (packet size in bytes) for this socket.
        May vary between sockets. */
    int                    MTU;


    template<typename T> 
    void serializeMessage(
        uint32 type, 
        const T& m, 
        BinaryOutput& b) const {

        debugAssert(type != 0);
        b.writeUInt32(type);
        m.serialize(b);
        b.writeUInt32(1);
    
        debugAssertM(b.size() < MTU, 
                    format("This LightweightConduit is limited to messages of "
                           "%d bytes (Ethernet hardware limit; this is the "
                           "'UDP MTU')", maxMessageSize()));

        if (b.size() >= MTU) {
            throw LightweightConduit::PacketSizeException(
                    format("This LightweightConduit is limited to messages of "
                           "%d bytes (Ethernet hardware limit; this is the "
                           "'UDP MTU')", maxMessageSize()),
                           (int)b.size() - 4, // Don't count the type header
                           maxMessageSize());
        }
    }

public:

    static LightweightConduitRef create(uint16 receivePort, bool enableReceive, bool enableBroadcast);

    class PacketSizeException {
    public:
        std::string            message;
        int                    serializedPacketSize;
        int                    maxMessageSize;

        inline PacketSizeException(const std::string& m, int s, int b) :
            message(m),
            serializedPacketSize(s),
            maxMessageSize(b) {}
    };

    /** Closes the socket. */
    ~LightweightConduit();

    /** The maximum length of a message that can be sent
        (G3D places a small header at the front of each UDP packet;
        this is already taken into account by the value returned).
     */
    inline int maxMessageSize() const {
        return MTU - 4;
    }


    template<typename T> inline void send(const NetAddress& a, uint32 type, const T& msg) {
        binaryOutput.reset();
        serializeMessage(type, msg, binaryOutput);
        sendBuffer(a, binaryOutput);
    }

    /** Send the same message to multiple addresses (only serializes once).
        Useful when server needs to send to a known list of addresses
        (unlike direct UDP broadcast to all addresses on the subnet) */
    template<typename T> inline void send(const Array<NetAddress>& a, uint32 type, const T& m) {
        binaryOutput.reset();
        serializeMessage(type, m, binaryOutput);

        for (int i = 0; i < a.size(); ++i) {
            sendBuffer(a[i], binaryOutput);
        }
    }

    bool receive(NetAddress& sender);

    template<typename T> inline bool receive(NetAddress& sender, T& message) {
        bool r = receive(sender);
        if (r) {
            BinaryInput b((messageBuffer.getCArray() + 4), 
                          messageBuffer.size() - 4, 
                          G3D_LITTLE_ENDIAN, BinaryInput::NO_COPY);
            message.deserialize(b);
        }

        return r;
    }

    inline bool receive() {
        static NetAddress ignore;
        return receive(ignore);
    }

    virtual uint32 waitingMessageType();


    virtual bool messageWaiting();
};

///////////////////////////////////////////////////////////////////////////////

typedef shared_ptr<class NetListener> NetListenerRef;

/**
 Runs on the server listening for clients trying to make reliable connections.

 \deprecated
 */
class NetListener : public ReferenceCountedObject {
private:

    friend class NetworkDevice;

    SOCKET                          sock;

    /** Port is in host byte order. */
    NetListener(uint16 port);

public:

    static NetListenerRef create(const uint16 port);

    ~NetListener();

    /** Block until a connection is received.  Returns NULL if 
        something went wrong. */
    ReliableConduitRef waitForConnection();

    /** True if a client is waiting (i.e. waitForConnection will
        return immediately). */
    bool clientWaiting() const;

    bool ok() const;
};


///////////////////////////////////////////////////////////////////////////////

/**
   @brief Abstraction of network (socket) functionality.

   An abstraction over sockets that provides a message-based network
   infrastructure optimized for sending many small (~500 bytes) messages.
   All functions always return immediately.
   
   Create only one NetworkDevice per process (a WinSock restriction).
   
   NetworkDevice is technically not thread safe.  However, as long as
   you use different conduits on different threads (or lock conduits
   before sending), you will encounter no problems sharing the single
   NetworkDevice across multiple threads.  That is, do not invoke the same
   Conduit's send or receive method on two threads at once.
   
   This assumes that the underlying WinSock/BSD sockets implementation
   is thread safe.  That is not guaranteed, but in practice seems
   to always be true (see
   http://tangentsoft.net/wskfaq/intermediate.html#threadsafety)

   <hr> 

   IP networks use "network byte order" (big-endian) for
   communicating integers.  "Host byte order" is the endian-ness of
   the local machine (typically little-endian; see
   System::endian). The C functions htonl() and ntohl() convert 32-bit
   values between these formats. G3D only ever exposes host byte order,
   so programmers rarely need to be aware of the distinction.

   \deprecated
 */
class NetworkDevice {
public:

    /** @brief Description of an ethernet or wireless ethernet adapter.*/
    class EthernetAdapter {
    public:
        /** Reverse-DNS of the ip address.*/
        std::string     hostname;

        /** Name of the adapter */
        std::string     name;

        /** IP address in host byte order.*/
        uint32          ip;

        /** Subnet mask in host byte order.*/
        uint32          subnet;

        /** UDP broadcast address in host byte order.*/
        uint32          broadcast;

        /** MAC (hardware) address, if known */
        uint8           mac[6];

        EthernetAdapter();

        /** Produces a text description of this adapter */
        void describe(TextOutput& t) const;
    };

private:

    friend class Conduit;
    friend class LightweightConduit;
    friend class ReliableConduit;
    friend class NetListener;

    bool                        initialized;

    Array<EthernetAdapter>      m_adapterArray;

    /** Broadcast addresses available on this machine,
     extracted from m_adapterArray.*/
    Array<uint32>               m_broadcastAddresses;

    /** Utility method. */
    void closesocket(SOCKET& sock) const;

    /** Utility method. Returns true on success.*/
    bool bind(SOCKET sock, const NetAddress& addr) const;

    /** The global instance */
    static NetworkDevice* s_instance;

    NetworkDevice();

    bool init();

    void _cleanup();

    /** Called from init to update m_adapterArray and
        m_broadcastAddresses. */
    void addAdapter(const EthernetAdapter& a);

public:

    /** Prints an IP address to a string.
        @param ip In host byte order.*/
    static std::string formatIP(uint32 ip);

    /** Prints a MAC address to a string. */
    static std::string formatMAC(const uint8 mac[6]);

    ~NetworkDevice();

    /** Returns the available ethernet adapters for the current
        machine that are online. Does not include the loopback adapter
        for localhost.*/
    inline const Array<EthernetAdapter>& adapterArray() const {
        return m_adapterArray;
    }

    /** Returns the (unique) IP addresses for UDP broadcasting
        extracted from adapterArray(). All are in host byte order. */
    inline const Array<uint32>& broadcastAddressArray() const {
        return m_broadcastAddresses;
    }

    /**
     Returns NULL if there was a problem initializing the network.
     */
    static NetworkDevice* instance();

    /**
     Shuts down the network device (destroying the global instance).
     */
    static void cleanup();

    /**
     Prints a human-readable description of this machine
     to the text output stream.
     */
    void describeSystem(
        TextOutput& t);

    void describeSystem(
        std::string&        s);

    /** Returns the name (or one of the names) of this computer */
    std::string localHostName() const;

    /** There is often more than one address for the local host. This
        returns all of them. 
        @deprecated Use adapterArray()
    */
    void localHostAddresses(Array<NetAddress>& array) const;
};


#ifdef __GNUC__
inline uint32 gcchtonl(uint32 x) {
    // This pragma fools gcc into surpressing all error messages,
    // including the bogus one that it creates for htonl
#   pragma GCC system_header
    return htonl(x);
}
#endif

} // G3D namespace

#ifndef _WIN32
#undef SOCKADDR_IN
#undef SOCKET
#endif

#endif
