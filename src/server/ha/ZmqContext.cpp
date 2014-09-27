#include "ZmqContext.h"

zmqpp::socket* ZmqContext::newSocket(zmqpp::socket_type type)
{
  mtx.lock();
  zmqpp::socket* ret = new zmqpp::socket(ctx, type);
  mtx.unlock();
  return ret;
}
