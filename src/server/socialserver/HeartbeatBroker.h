#include "ace/Task.h"
#include "zmqpp/zmqpp.hpp"

class HeartbeatBroker : public ACE_Task_Base
{
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
