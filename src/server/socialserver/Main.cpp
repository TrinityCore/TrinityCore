#include "zmqpp/zmqpp.hpp"
#include "zmqpp/context.hpp"
#include "HeartbeatBroker.h"
#include "CommandPuller.h"
#include "Worker.h"



int main(int /*argc*/, char** /*argv*/)
{
    zmqpp::context ctx;
    zmqpp::socket inproc(ctx, zmqpp::socket_type::req);
    inproc.bind("inproc://workers");

    CommandPuller puller;
    Worker worker;

    puller.open(&ctx);
    worker.open(&ctx);

    puller.wait();
}
