/**
  @file Discovery.cpp
  
  @maintainer Morgan McGuire, matrix@graphics3d.com
 
  @created 2003-06-26
  @edited  2005-02-24
 */

#include "G3D/Discovery.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"

#include <cstring>

namespace G3D {

///////////////////////////////////////////////////////////////////////////////////////////

void DiscoveryAdvertisement::serialize(BinaryOutput& b) const {
    address.serialize(b);
}

void DiscoveryAdvertisement::deserialize(BinaryInput& b) {
    address.deserialize(b);
    lastUpdateTime = System::time();
}


///////////////////////////////////////////////////////////////////////////////////////////

void DiscoveryServerAddressMessage::serialize(BinaryOutput& b) const {
    b.writeString(G3D_DISCOVERY_PROTOCOL_NAME);
    b.writeInt32(G3D_DISCOVERY_PROTOCOL_VERSION);
    b.writeString(settings->appProtocolName);
    b.writeInt32(settings->appProtocolVersion);

    // Send addresses
    b.writeInt32(address.size());
    for (int i = 0; i < address.size(); ++i) {
        address[i].serialize(b);
    }
}


void DiscoveryServerAddressMessage::deserialize(BinaryInput& b) {
    address.clear();
    correctProtocol = false;
    serverProtocolVersion[0] = 0;
    serverProtocolVersion[1] = 0;

    // Verify that we are on the same protocol
    if (b.readString(strlen(G3D_DISCOVERY_PROTOCOL_NAME) + 1) != G3D_DISCOVERY_PROTOCOL_NAME) {
        return;
    }

    serverProtocolVersion[0] = b.readInt32();
    if (serverProtocolVersion[0] != G3D_DISCOVERY_PROTOCOL_VERSION) {
        return;
    }

    if (b.readString() != settings->appProtocolName) {
        return;
    }

    serverProtocolVersion[1] = b.readInt32();
    if (serverProtocolVersion[1] != settings->appProtocolVersion) {
        return;
    }

    correctProtocol = true;

    address.resize(b.readInt32());
    for (int i = 0; i < address.size(); ++i) {
        address[i].deserialize(b);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////

void DiscoveryServer::sendAnnouncement() const {
    NetAddress broadcast(NetworkDevice::instance()->broadcastAddressArray()[0], settings->serverBroadcastPort);

    net->send(broadcast, SERVER_BROADCAST_MESSAGE, addressMessage);

    const_cast<DiscoveryServer*>(this)->lastBroadcast = System::time();
}


void DiscoveryServer::sendShutDown() const {
    NetAddress broadcast(NetworkDevice::instance()->broadcastAddressArray()[0], settings->serverBroadcastPort);
    ShutdownMessage s;
    net->send(broadcast, SERVER_SHUTDOWN_MESSAGE, s);
}


bool DiscoveryServer::ok() const {
    return listener->ok() && net->ok();
}


void DiscoveryServer::init(
    const DiscoverySettings* _settings,
    DiscoveryAdvertisement*  _advertisement) {

    Discovery::init(_settings);

    advertisement = _advertisement;
    addressMessage.settings = settings;
    NetworkDevice::instance()->localHostAddresses(addressMessage.address);

    // Set the port number
    for (int i = 0; i < addressMessage.address.size(); ++i) {
        addressMessage.address[i] =
            NetAddress(addressMessage.address[i].ip(),
                       settings->serverAdvertisementPort);
    }

    net = LightweightConduit::create(settings->clientBroadcastPort, true, true);

    listener = NetListener::create(settings->serverAdvertisementPort);

    // Send initial announcement
    sendAnnouncement();
}


void DiscoveryServer::doNetwork() {
    const RealTime UNSOLICITED_BROADCAST_PERIOD = 60;

    // Check for client broadcast requests

    if (net->messageWaiting()) {
        // Some client broadcast that it is looking for servers.
        // Respond by sending out our announcement to everyone
        // (avoids having to figure out if the message return address
        // is correct).
        NetAddress dummy;
        net->receive(dummy);
        sendAnnouncement();
    } else if (System::time() > lastBroadcast + UNSOLICITED_BROADCAST_PERIOD) {
        sendAnnouncement();
    }

    // Handle incoming connections

    if (listener->clientWaiting()) {
        // Respond to this client
        ReliableConduitRef client = listener->waitForConnection();
        client->send(SERVER_BROADCAST_MESSAGE, *advertisement);
    }
}


void DiscoveryServer::cleanup() {
    sendShutDown();
}

//////////////////////////////////////////////////////////////////////////////////

std::string IncompatibleServerDescription::toString() const {
    return std::string("Incompatible server at ") + address.toString() +
        format(", version %d.%d", protocolVersion[0], protocolVersion[1]);
}

//////////////////////////////////////////////////////////////////////////////////


}

