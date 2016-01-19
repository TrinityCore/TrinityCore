/* 
 * File:   thrift_test.h
 * Author: giuseppe
 *
 * Created on 29 agosto 2013, 15.59
 */

#ifndef THRIFT_TEST_H
#define	THRIFT_TEST_H

#include <thrift/concurrency/ThreadManager.h>
#include <thrift/concurrency/PosixThreadFactory.h>
#include <thrift/protocol/TBinaryProtocol.h>
//#include <thrift/server/TSimpleServer.h>
#include <thrift/server/TNonblockingServer.h>
#include <thrift/server/TThreadPoolServer.h>
#include <thrift/server/TThreadedServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include <thrift/processor/TMultiplexedProcessor.h>
#include <thrift/concurrency/PosixThreadFactory.h>

#include <stdint.h>
#include <iostream>
#include <stdexcept>
#include <sstream>

#include "Common.h"
#include "Hw2TWorld.h"

#include <ace/Semaphore.h>
#include <ace/Task.h>
#include <Threading.h>
#include <ace/Reactor.h>

class Hw2ThriftRunnable : public ACE_Based::Runnable
{
    public:
        //ThriftRunnable();
        //virtual ~ThriftRunnable();
        void run() OVERRIDE;
};


#endif	/* THRIFT_TEST_H */

