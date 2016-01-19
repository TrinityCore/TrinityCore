#include "thrift.h"
#include "World.h"

class Hw2TWorldHandler : virtual public Hw2TWorldIf {
 public:
  Hw2TWorldHandler() {
    // Your initialization goes here
  }

  void SendWorldText(const int32_t string_id) {
      sWorld->SendWorldText(string_id);
  }

};

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace apache::thrift::server;
using namespace apache::thrift::concurrency;
 
using boost::shared_ptr;

void Hw2ThriftRunnable::run() {
    int port = 9090;
    shared_ptr<Hw2TWorldHandler> handler(new Hw2TWorldHandler());
    shared_ptr<TProcessor> worldProc(new Hw2TWorldProcessor(handler));
    shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
    
    shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
    
   /* shared_ptr<TMultiplexedProcessor> processor(new TMultiplexedProcessor());

    processor->registerProcessor(
        "World",
        worldProc); */


    //TSimpleServer server = new TSimpleServer(processor, serverTransport,transportFactory,protocolFactory);
    //server.serve();
    

    // using thread pool with maximum 15 threads to handle incoming requests
    shared_ptr<ThreadManager> threadManager = ThreadManager::newSimpleThreadManager(15);
    shared_ptr<PosixThreadFactory> threadFactory = shared_ptr<PosixThreadFactory>(new PosixThreadFactory());
    threadManager->threadFactory(threadFactory);
    threadManager->start();
    TNonblockingServer server(worldProc, protocolFactory, port, threadManager);
    server.serve();
    //TNonblockingServer server(processor, serverTransport, transportFactory, protocolFactory);
    //server.serve(); */
    return;
}