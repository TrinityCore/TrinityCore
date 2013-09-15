#include "HeartbeatBroker.h"
#include "CommandPuller.h"
#include "Worker.h"
#include <zmqpp/zmqpp.hpp>
#include "ZmqContext.h"


int main(int /*argc*/, char** /*argv*/)
{
    zmqpp::context ctx;
    zmqpp::socket *inproc = sContext->newSocket(zmqpp::socket_type::pub);
    inproc->bind("inproc://workers");

    CommandPuller puller;
    Worker worker("inproc://work_queue", "inproc://work_result");

    puller.open(&ctx);
    worker.open(&ctx);

    puller.wait();
    delete inproc;
    return 0;
}
