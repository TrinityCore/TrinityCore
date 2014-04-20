#ifndef _SOCIALSERVER_H
#define _SOCIALSERVER_H

#include "zmqpp/zmqpp.hpp"
#include <ace/Singleton.h>

class SocialServer {
  friend class ACE_Singleton<SocialServer, ACE_Null_Mutex>;
 public:
  void SendCommand(zmqpp::message&);
 private:
  SocialServer();
  SocialServer(SocialServer&){}
  zmqpp::socket* push_socket;
};


#define sSocialServer ACE_Singleton<SocialServer, ACE_Null_Mutex>::instance()
#endif 
