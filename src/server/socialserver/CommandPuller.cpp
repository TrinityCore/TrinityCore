#include "CommandPuller.h"

CommandPuller::CommandPuller()
{
    ctx = new zmqpp::context();
    poller = new zmqpp::poller();
    commands = new zmqpp::socket(*ctx, zmqpp::socket_type::pull);
    broadcast = new zmqpp::socket(*ctx, zmqpp::socket_type::publish);
    work_queue = new zmqpp::socket(*ctx, zmqpp::socket_type::push);
    work_res = new zmqpp::socket(*ctx, zmqpp::socket_type::pull);
}

CommandPuller::~CommandPuller()
{
    delete commands;
    delete broadcast;
    delete work_queue;
    delete work_res;
    delete poller;
    delete ctx;
}

int CommandPuller::open(void*)
{
    broadcast->bind("tcp://*:9998");
    commands->bind("tcp://*:9997");
    work_queue->bind("ipc://work_queue");
    work_res->bind("ipc://results");

    poller->add(*commands);
    poller->add(*work_res);
    poller->add(*broadcast, zmqpp::poller::poll_out);
    poller->add(*work_queue, zmqpp::poller::poll_out);

    ACE_Task_Base::activate();
}

int CommandPuller::svc()
{
    /*
      Polling strategy is pretty simple right now. 
      There are two socket pairs that need to be read and write ready for magic to happen.
      commands read -> work_queue write
      work_res read -> broadcast write
      So we're only doing stuff if both of them can handle writes/reads,
     */
    while(1)
    {
	poller->poll();
	pipeline(commands, work_queue);
	pipeline(work_res, broadcast);
    }
}

void CommandPuller::pipeline(zmqpp::socket* from, zmqpp::socket* to)
{
/*
  Push messages from node to node.
  To avoid blocking, check religiously wether both sockets are readable/writable.
  If not, let's just ignore them until they can.
 */
    if(poller->events(*from) == zmqpp::poller::poll_in &&
       poller->events(*to) == zmqpp::poller::poll_out)
    {
	
	int op1, op2;
	do
	{
	    zmqpp::message msg;
	    
	    if(!from->receive(msg, true))
		return; //No more messages to read from sock. This shouldn't happen.

	    to->send(msg);
	    
	    from->get(zmqpp::socket_option::events, op1);
	    to->get(zmqpp::socket_option::events, op2);
	}while(op1 & zmqpp::poller::poll_in && op2 & zmqpp::poller::poll_out );
    }
}
