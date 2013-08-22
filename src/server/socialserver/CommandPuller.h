#include "ace/Task.h"
#include "zmqpp/zmqpp.hpp"

class CommandPuller : public ACE_Task_Base
{
/*
  This class serves as main message broker, and task enqueuer.
  Every social event broadcasted is received by puller, and then
  pushed down the work_queue socket, where one of worker threads receive it. 
  After processing worker thread sends ready message to work_res queue. 
  When received, it will be broadcasted via broadcast socket.
*/
public:
    virtual int open(void*);
    virtual int svc();
    ~CommandPuller();
    CommandPuller();
private:
    void pipeline(zmqpp::socket*, zmqpp::socket*);

    zmqpp::context* ctx;
    zmqpp::poller* poller;

    //PULL socket for nodes to announce events
    zmqpp::socket* commands; 

    //PUB socket for broadcasting events
    zmqpp::socket* broadcast;

    //IPC PUSH socket for enqueuing work
    zmqpp::socket* work_queue;
    
    //IPC PULL socket for work results
    zmqpp::socket* work_res;
};
//Two endlines. For Shauren.

