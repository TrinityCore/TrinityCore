#include "SocialServer.h"
#include "ZmqContext.h"
#include "Config.h"

SocialServer::SocialServer():
  push_socket(sContext->newSocket(zmqpp::socket_type::push))
{
  this->push_socket->connect(sConfigMgr->GetStringDefault("Redirect.SocialServer", "inproc:///no-ss"));
}

void SocialServer::SendCommand(zmqpp::message& msg)
{
  this->push_socket->send(msg);
}

