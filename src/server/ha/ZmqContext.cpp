#include "ZmqContext.h"
#include "ace/Guard_T.h"

zmqpp::socket* ZmqContext::newSocket(zmqpp::socket_type type)
{
    ACE_Guard<ACE_Recursive_Thread_Mutex> g(mtx);
    return new zmqpp::socket(ctx, type);

}
