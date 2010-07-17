/**
  @file Discovery.h

 <H2>Discovery</H2>
 Discovery is the process by which computers on a Local Area Network (LAN) find
 one another.  The Discovery API allows clients to make a list of servers running
 the same application.  The application typically presents this list to the user
 so he can choose which server to connect to.
 <P>   
 Features of the Discovery API:
 <P>
 Low network traffic
 <BR>  - Broadcasts mainly occur only when a new machine enters/leaves the network
 <BR>Responsive
 <BR>  - Servers appear immediately after launching
 <BR>  - Servers disappear immedatiately after they shut down
 <BR>Extensible
 <BR>  - Add your own game information (e.g. score, num players, map name)
 <BR>Versioned
 <BR>  - Tracks incompatible servers so end-users know to upgrade their client/server

 <H2>Using the Discovery API</H2>

 Subclass DiscoveryAdvertisement to add fields describing a server running your
 application.  For a game, these might be the current map name and the number
 of players.
 <P>
 On the client, create an instance of DiscoveryClient<your advertisement subclass>.
 On the server, create an instance of DiscoveryServer and initialize it with an
 instance of your advertisement subclass.  From your main loop, call doNetwork()
 on the client and server instances.  When your server shuts down, invoke cleanup()
 on it.
  
  @maintainer Morgan McGuire, matrix@graphics3d.com
 
  @created 2003-06-26
  @edited  2008-11-24
 */

#ifndef G3D_DISCOVERY_H
#define G3D_DISCOVERY_H

#include "G3D/platform.h"
#include "G3D/G3DGameUnits.h"
#include "G3D/NetworkDevice.h"
#include "G3D/Log.h"
#include <time.h>

/**
 Different versions of G3D discovery protocols can't communicate with each other.
 */
#define G3D_DISCOVERY_PROTOCOL_NAME "G3D DISC"
#define G3D_DISCOVERY_PROTOCOL_VERSION 1

namespace G3D {

/**
 If a machine is running two different programs using discovery they
 must have different ports.  However different programs can share the
 same ports if they run on the same LAN with different servers.

 @deprecated See Discovery2::Settings
 */
class DiscoverySettings {
public:

    /**
     Name of the program using discovery; used so that mutliple
     programs can use the same discovery ports on the same network.
     */
    const char*         appProtocolName;

    /**
     Version of the network protocol of the program using discovery.
     Used so that discovery can identify incompatible versions of 
     the server.
     */
    int                 appProtocolVersion;

    /**
     Port on which the server broadcasts its identity.    The client
     and server must agree on this value.
     */
    uint16              serverBroadcastPort;

    /**
     Port on which the client broadcasts a server request.  The client
     and server must agree on this value.
     */
    uint16              clientBroadcastPort;

    /**
     Clients connect into this port using a reliable conduit
     to receive the advertisement from a server.  The client
     doesn't look at this value; it uses whatever the server
     sends it.
    */
    uint16              serverAdvertisementPort;

    /**
     You can use the default G3D discovery ports as long as no other
     program with the same protocol name is using this port.  You
     <B>can</B> run two different G3D discovery programs on the same
     two ports as long as they have different application protocol
     strings.
     */
    DiscoverySettings(
        const char*     _appProtocolName,
        int             _appProtocolVersion,
        uint16          _serverBroadcast = 6173,
        uint16          _clientBroadcast = 6174,
        uint16          _serverAdvertisementPort = 6175) :
        appProtocolName(_appProtocolName),
        appProtocolVersion(_appProtocolVersion),
        serverBroadcastPort(_serverBroadcast),
        clientBroadcastPort(_clientBroadcast),
        serverAdvertisementPort(_serverAdvertisementPort) {}
};

/**
 Make your own subclass of this advertisement.  Add fields
 (e.g. numPlayers, currentScore) to increase the amount
 of information advertised.

 Overrides must provide a default constructor.
 @deprecated See Discovery2::Settings
 */
class DiscoveryAdvertisement {
public:

    /**
     Address to connect to on the server for the actual game. 
     The IP portion is ignored (the client figures out the IP
     address from the packet itself) but the port is essential.
     Note that this port must not be the discovery port.
     */
    NetAddress                  address;

    /**
     (Only used on the client)
     Time since this advertisement was updated.
     */
    RealTime                    lastUpdateTime;

    /**
     Overrides must call DiscoveryAdvertisement::serialize(b) first.
     */
    virtual void serialize(BinaryOutput& b) const;

    /**
     Overrides must call DiscoveryAdvertisement::deserialize(b) first.
     */
    virtual void deserialize(BinaryInput& b);

    /**
     An empty virtual destructor for virtual methods.
    */
    virtual ~DiscoveryAdvertisement() {}
};


/**
 Sent by servers to describe their location.
 */
class DiscoveryServerAddressMessage {
public:

    /**
     Not part of the message; these settings are used to determine
     if the correct protocol is being used.
     */
    const DiscoverySettings*    settings;


    /**
     Set to true if this server is running the correct protocol.
     */
    bool                        correctProtocol;

    /**
     This is set during the serialize process from the server's settings.
     If different from the client's settings the discovery system will
     classify this server as incompatible.
     */
    int                         serverProtocolVersion[2];

    Array<NetAddress>           address;

    DiscoveryServerAddressMessage() {}
    DiscoveryServerAddressMessage(const DiscoverySettings* s) : settings(s) {}

    void serialize(BinaryOutput& b) const;

    void deserialize(BinaryInput& b);
};


/**
 Base class for DiscoveryClient and DiscoveryServer.
 */
class Discovery {
public:

    const DiscoverySettings*    settings;

    enum {
        SERVER_SHUTDOWN_MESSAGE  = 2,
        SERVER_BROADCAST_MESSAGE = 3,
        CLIENT_BROADCAST_MESSAGE = 4};

    /**
     Only called from subclasses.
     */
    virtual void init(
        const DiscoverySettings* _settings) {
        settings  = _settings;
    }

    /**
     An empty virtual destructor for virtual methods.
    */
    virtual ~Discovery() {}
};

/** @deprecated See Discovery2::Server*/
class DiscoveryServer : private Discovery {
private:

    class ShutdownMessage {
    public:
        void serialize(BinaryOutput& b) const { (void)b; }

        void deserialize(BinaryInput& b) { (void)b; }
    };

    /**
     For broadcast.
     */
    LightweightConduitRef           net;

    /**
     Listen for clients wanting to hear the advertisement over
     a reliable connection.
     */
    NetListenerRef                  listener;

    DiscoveryAdvertisement*         advertisement;

    /**
     Broadcast across the lightweight conduit.
     */
    DiscoveryServerAddressMessage   addressMessage;

    /**
     Servers periodically broadcast (unsolicited) in case
     anyone missed the previous message.
     */
    RealTime                        lastBroadcast;

    void sendAnnouncement() const;

    void sendShutDown() const;
    
public:

    /**
     You may update the advertisement (synchronously with calling doNetwork)
     after it has been passed in.  This allows a server to change the advertised
     number of players or score for a game, for example.

     You must set the port of the @a _advertisement G3D::DiscoveryAdvertisement::address
     to the port which the G3D::NetListener for the actual program protocol (not discovery)
     is running. That field how the client knows what address to connect to using 
     G3D::ReliableConduit or G3D::LightweightConduit to actually initiate communication.
     */
    virtual void init(
        const DiscoverySettings* _settings,
        DiscoveryAdvertisement*  _advertisement);

    /** Returns the broadcast address in use.*/
    NetAddress broadcastAddress() const;

    /**
     Returns true if this discovery server has been initialized
     and is functioning properly.
     */
    bool ok() const;

    /**
     Call periodically to let the server do its job.
     */
    void doNetwork();

    /**
     Broadcast a shutdown message.
     */
    void cleanup();
};


/**
 Used by DiscoveryClient to report servers running a different version
 of this application's protocol.
 */
class IncompatibleServerDescription {
public:
    NetAddress                  address;
    int                         protocolVersion[2];
    RealTime                    lastUpdateTime;

    std::string toString() const;
};


/**
 Only one DiscoveryClient can be active on a given port at a time on 
 a single computer.

 AdType must be a subclass of DiscoveryAdvertisement.

 @deprecated See Discovery2::Client
 */
template<class AdType> 
class DiscoveryClient : private Discovery {
public:

    /**
     List of servers.  Do not access on a second thread while in
     doNetwork.
     */
    Array<AdType>                       serverList;

    /**
     List of servers running the same application but a different protocol.
     It is useful to show these to users to help them recognize version
     conflicts between client and server.
     Do not access on a second thread while in doNetwork.
     */
    Array<IncompatibleServerDescription> incompatibleServerList;

private:

    class BroadcastMessage {
    public:
        void serialize(BinaryOutput& b) const {}

        void deserialize(BinaryInput& b) {}
    };

    /**
     The client periodically checks servers to make sure they are still up
     and to update its information about them.
     */
    RealTime                            lastServerCheck;

    LightweightConduitRef               net;

    /**
     Returns an index in serverList of the server with the given address.
     Returns -1 if there is none.  Only checks IP addresses.
     */
    int findServerListIndex(const NetAddress& addr) const {
        for (int i = 0; i < serverList.size(); ++i) {
            if (addr.ip() == serverList[i].address.ip()) {
                return i;
            }
        }

        return -1;
    }
    
    /**
     Returns true if this discovery client has been initialized
     and is functioning properly.
     */
    bool ok() const {
        return net->ok();
    }

    /**
     Adds a server to the incompatible list if it is not already there.
     */
    void addToIncompatibleList(const NetAddress& addr, uint32 p0, uint32 p1) {
        const RealTime now = System::time();
        
        bool alreadyHere = false;

        // Incorrect protocol; add to the incompatible list
        for (int i = 0; i < incompatibleServerList.size(); ++i) {
            IncompatibleServerDescription& server = incompatibleServerList[i];

            if (server.address == addr) {
                server.lastUpdateTime = now;
                alreadyHere = true;
                break;
            }
        }

        if (! alreadyHere) {
            IncompatibleServerDescription server;

            server.lastUpdateTime       = now;
            server.address              = addr;
            server.protocolVersion[0]   = p0;
            server.protocolVersion[1]   = p1;

            incompatibleServerList.append(server);
        }
    }

    /**
     Connects to the specified server, reads its advertisement,
     and adds it to the active server list.  Returns true if the server
     can be reached.
     */
    bool readAdvertisement(const NetAddress& address) {
        std::string hostname = address.toString();

        RealTime TIMEOUT = 2.0;

        ReliableConduitRef server = ReliableConduit::create(address);

        if (! server->ok()) {
            return false;
        }

        AdType advertisement;

        // Read the advertisement
        RealTime stopWaiting = System::time() + TIMEOUT;
        bool timedOut = false;

        while (! server->messageWaiting() && ! timedOut && server->ok()) {
            System::sleep(0.1);
            timedOut = (System::time() > stopWaiting);
        }

        if (timedOut) {
            Log::common()->printf("Discovery: Timed out while reading advertisment from %s\n",
                hostname.c_str());
            return false;
        }


        if (! server->ok()) {
            Log::common()->printf("Discovery: Server %s dropped connection\n", hostname.c_str());
            return false;
        }

        // Read the advertisement
        debugAssert(server->messageWaiting());
        if (! server->receive(advertisement)) {
            Log::common()->printf("Discovery: Server %s failed to send advertisement\n", hostname.c_str());
            return false;
        }

        // Update existing server info or create a new entry
        int index = findServerListIndex(address);
        if (index == -1) {
            index = serverList.size();
            serverList.resize(index + 1);
        }

        // Update element index
        advertisement.address = address;
        serverList[index] = advertisement;

        return true;
    }

    /**
      Remove this address from our list if we previously
      had a server there.
      */
    void removeServer(const NetAddress& address) {
        int index = findServerListIndex(address);
        if (index > -1) {
            serverList.fastRemove(index);
        }
    }

    /**
     Tries to connect to the server through the addresses in the array.
     */
    void addToServerList(const Array<NetAddress>& addressArray) {
        // Try to connect to each address listed
        for (int a = addressArray.size() - 1; a >= 0; --a) {
            const NetAddress& address = addressArray[a];

            if (readAdvertisement(address)) {
                // We've connected to the server
                break;
            } else {
                removeServer(address);
            }
        }
    }

    void checkRandomServer() {
        if (serverList.size() >= 1) {
            int index = iRandom(0, serverList.size() - 1);

            Array<NetAddress> address;
            address.append(serverList[index].address);

            // Remove this server
            serverList.fastRemove(index);

            // Add it back with new info (or leave it removed if no response)
            addToServerList(address);
        }
    }

public:

    void init(
        const DiscoverySettings* _settings) {

        Discovery::init(_settings);

        lastServerCheck = System::time();

        net = LightweightConduit::create(settings->serverBroadcastPort, true, true);

        // Send announcement
        NetAddress broadcast(NetworkDevice::instance()->broadcastAddressArray()[0],
                             settings->clientBroadcastPort);
        BroadcastMessage tmp;
        net->send(broadcast, CLIENT_BROADCAST_MESSAGE, tmp);
    }

    /** Shut down the discovery client. */
    void cleanup() {
        net = NULL;
    }

    /**
     Call this regularly (several times per second) to
     update the server list.  Not threadsafe-- you must not touch
     the server list while this is running.  This will not block.
     */
    void doNetwork() {
        if (net->messageWaiting()) {
            NetAddress sender;

            switch (net->waitingMessageType()) {
            case SERVER_SHUTDOWN_MESSAGE:
                // Remove the server
                net->receive(sender);
                removeServer(sender);
                break;

            case SERVER_BROADCAST_MESSAGE:
                // Check the G3D protocol and the network protocol, then read the ad
                DiscoveryServerAddressMessage msg(settings);
                net->receive(sender, msg);

                if (msg.correctProtocol && (msg.address.size() > 0)) {
                    // Add the actual return address as the first one to be tried.
                    msg.address.append(NetAddress(sender.ip(), msg.address[0].port()));

                    addToServerList(msg.address);

                } else {

                    addToIncompatibleList(
                        sender,
                        msg.serverProtocolVersion[0],
                        msg.serverProtocolVersion[1]);
                }
                break;
            }
        }

        // Periodically re-check servers in the list to see if they crashed
        // (if they shut down, they should have broadcast a shut down message).
        RealTime now = System::time();
        const RealTime UPDATE_TIME_INTERVAL = 30;

        if (now > lastServerCheck + UPDATE_TIME_INTERVAL) {
            lastServerCheck = now;
            checkRandomServer();
        }
    }
};

}

#endif
