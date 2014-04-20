#include "SocialServer.h"
#include "ZmqContext.h"

SocialServer::SocialServer():
  push_socket(sContext->newSocket(zmqpp::socket_type::push))
{
  
}

void SocialServer::SendCommand(zmqpp::message& msg)
{
  this->push_socket->send(msg);
}

