/*
 * Copyright (c) 2005, Eric Crahen
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef __ZTEXCEPTIONS_H__
#define __ZTEXCEPTIONS_H__


#include "zthread/Config.h"
#include <string>

namespace ZThread { 
  
/**
 * @class Synchronization_Exception
 *
 * Serves as a general base class for the Exception hierarchy used within
 * this package.
 *
 */
class Synchronization_Exception {

  // Restrict heap allocation
  static void * operator new(size_t size);
  static void * operator new[](size_t size);

  std::string _msg;
  
public:
  
  /**
   * Create a new exception with a default error message 'Synchronization 
   * Exception'
   */
  Synchronization_Exception() : _msg("Synchronization exception") { }

  /**
   * Create a new exception with a given error message
   *
   * @param const char* - error message
   */
  Synchronization_Exception(const char* msg) : _msg(msg) { }

  /**
   * Get additional info about the exception
   *
   * @return const char* for the error message
   */
  const char* what() const {
    return _msg.c_str();
  }
  
};
  

/**
 * @class Interrupted_Exception
 *
 * Used to describe an interrupted operation that would have normally
 * blocked the calling thread
 */
class Interrupted_Exception : public Synchronization_Exception {

  public:

  //! Create a new exception
  Interrupted_Exception() : Synchronization_Exception("Thread interrupted") { }

  //! Create a new exception
  Interrupted_Exception(const char* msg) : Synchronization_Exception(msg) { }

};
  
 
  
/**
 * @class Deadlock_Exception
 *
 * Thrown when deadlock has been detected
 */
class Deadlock_Exception : public Synchronization_Exception {
  public:

  //! Create a new exception
  Deadlock_Exception() : Synchronization_Exception("Deadlock detected") { }

  //! Create a new exception
  Deadlock_Exception(const char* msg) : Synchronization_Exception(msg) { }

};
  
  
/**
 * @class InvalidOp_Exception
 *
 * Thrown when performing an illegal operation this object
 */
class InvalidOp_Exception : public Synchronization_Exception {
  public:

  //! Create a new exception
  InvalidOp_Exception() : Synchronization_Exception("Invalid operation") { }
  //! Create a new exception
  InvalidOp_Exception(const char* msg) : Synchronization_Exception(msg) { }

};

  
  
/**
 * @class Initialization_Exception
 *
 * Thrown when the system has no more resources to create new 
 * synchronization controls
 */
class Initialization_Exception : public Synchronization_Exception {
  
  public:

  //! Create a new exception
  Initialization_Exception() : Synchronization_Exception("Initialization error") { }
  //! Create a new exception
  Initialization_Exception(const char*msg) : Synchronization_Exception(msg) { }

};
  
/**
 * @class Cancellation_Exception
 *
 * Cancellation_Exceptions are thrown by 'Canceled' objects. 
 * @see Cancelable
 */
class Cancellation_Exception : public Synchronization_Exception {

  public:
  
  //! Create a new Cancelltion_Exception
  Cancellation_Exception()  : Synchronization_Exception("Canceled") { }
  //! Create a new Cancelltion_Exception
  Cancellation_Exception(const char*msg) : Synchronization_Exception(msg) { }
  
};
  

/**
 * @class Timeout_Exception
 *
 * There is no need for error messaged simply indicates the last
 * operation timed out
 */
class Timeout_Exception : public Synchronization_Exception {
  public:

  //! Create a new Timeout_Exception
  Timeout_Exception() : Synchronization_Exception("Timeout") { }
  //! Create a new 
  Timeout_Exception(const char*msg) : Synchronization_Exception(msg) { }
  
};

/**
 * @class NoSuchElement_Exception
 * 
 * The last operation that was attempted on a Queue could not find 
 * the item that was indicated (during that last Queue method invocation)
 */
class NoSuchElement_Exception {
 public:
  
  //! Create a new exception
  NoSuchElement_Exception() {}

};

/**
 * @class InvalidTask_Exception
 *
 * Thrown when a task is not valid (e.g. null or start()ing a thread with 
 * no overriden run() method)
 */
class InvalidTask_Exception : public InvalidOp_Exception {
 public:

  //! Create a new exception
  InvalidTask_Exception() : InvalidOp_Exception("Invalid task") {}
  
};

/**
 * @class BrokenBarrier_Exception
 *
 * Thrown when a Barrier is broken because one of the participating threads
 * has been interrupted.
 */
class BrokenBarrier_Exception : public Synchronization_Exception {

  public:

  //! Create a new exception
  BrokenBarrier_Exception() : Synchronization_Exception("Barrier broken") { }

  //! Create a new exception
  BrokenBarrier_Exception(const char* msg) : Synchronization_Exception(msg) { }

};
  
/**
 * @class Future_Exception
 *
 * Thrown when there is an error using a Future.
 */
class Future_Exception : public Synchronization_Exception {

  public:

  //! Create a new exception
  Future_Exception() : Synchronization_Exception() { }

  //! Create a new exception
  Future_Exception(const char* msg) : Synchronization_Exception(msg) { }

};

};

#endif // __ZTEXCEPTIONS_H__
