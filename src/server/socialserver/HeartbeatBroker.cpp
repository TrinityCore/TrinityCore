#include "HeartbeatBroker.h"
#include <zmqpp/socket_types.hpp>

HeartbeatBroker::HeartbeatBroker()
{
    ctx = new zmqpp::context();
    sock = new zmqpp::socket(*ctx, zmqpp::socket_type::publish);
    poller = new zmqpp::poller();
}

HeartbeatBroker::~HeartbeatBroker()
{
    delete poller;
    delete sock;
    delete ctx;
}

int HeartbeatBroker::open(void*)
{
    sock->bind("tcp://*:9999");
    poller->add(*sock);
    ACE_Task_Base::activate(THR_NEW_LWP|THR_JOINABLE);
    return 0;
}

int HeartbeatBroker::svc()
{
    while(1)
    {
        poller->poll(1000);
        sock->send("");
    }

    return 0;
}
