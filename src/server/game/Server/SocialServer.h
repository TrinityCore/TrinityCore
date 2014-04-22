#ifndef _SOCIALSERVER_H
#define _SOCIALSERVER_H

#include <zmqpp/zmqpp.hpp>
#include <ace/Singleton.h>
#include "Commands.h"

class WorldPacket;

class SocialServer
{
    friend class ACE_Singleton<SocialServer, ACE_Null_Mutex>;

    SocialServer();
    ~SocialServer();

public:
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

#define sSocialServer ACE_Singleton<SocialServer, ACE_Null_Mutex>::instance()
#endif
