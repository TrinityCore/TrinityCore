#ifndef _SOCIALSERVER_H
#define _SOCIALSERVER_H

#include <zmqpp/zmqpp.hpp>
#include "World.h"
#include "Commands.h"

class WorldPacket;

class SocialServer
{
    ~SocialServer();

public:
    SocialServer();
    void Init(RedirectInfo const& currentNode);
    void SendCommand(zmqpp::message& msg);
    void BuildPacketCommand(zmqpp::message& msg, WorldPacket& packet);

    void Update();
    void HandleCommand(zmqpp::message& msg);
    void QueueSession(WorldSession* session);

private:
    zmqpp::poller* poller;
    zmqpp::socket* push_socket;
    zmqpp::socket* pull_socket;
    RedirectInfo current_node;
    uint32 host_id;
    std::unordered_map<uint32, WorldSession*> _sessionQueue;
    
    SocialServer(SocialServer const& right);
    SocialServer& operator=(SocialServer const& right);
};

static SocialServer* sSocialServer = new SocialServer(); //GHETTO SINGLETON
#endif
