#include "HeartbeatBroker.h"
#include "CommandPuller.h"
#include "Worker.h"
#include <zmqpp/zmqpp.hpp>



int main(int /*argc*/, char** /*argv*/)
{
    zmqpp::context ctx;
    zmqpp::socket inproc(ctx, zmqpp::socket_type::pub);
    inproc.bind("inproc://workers");

    CommandPuller puller;
    Worker worker;

    puller.open(&ctx);
    worker.open(&ctx);

    puller.wait();
    return 0;
}
