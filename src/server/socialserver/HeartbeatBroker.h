#include <ace/Task.h>
#include <zmqpp/zmqpp.hpp>

class HeartbeatBroker : public ACE_Task_Base
{
/*
  This object's only role is to send heartbeat every second to nodes.
  That's it, really.
*/
public:
    virtual int open(void*);
    virtual int svc();
    ~HeartbeatBroker();
    HeartbeatBroker();
private:
    zmqpp::context* ctx;
    zmqpp::socket* sock;
    zmqpp::poller* poller;
};
