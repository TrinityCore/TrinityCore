/* 
 * File:   Hw2Master.cpp
 * Author: giuseppe
 * 
 * Created on 31 agosto 2013, 9.32
 */

#include "thrift.h"


#include "Hw2Master.h"
#include <ace/Sig_Handler.h>

#include "Common.h"

Hw2Master::Hw2Master() {
}

Hw2Master::Hw2Master(const Hw2Master& orig) {
}

Hw2Master::~Hw2Master() {
}

void Hw2Master::run() {
    ACE_Based::Thread* thriftThread = NULL;
    Hw2ThriftRunnable* TRunnable = new Hw2ThriftRunnable();
    thriftThread = new ACE_Based::Thread(TRunnable);
}
