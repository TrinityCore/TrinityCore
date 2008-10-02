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

#include "ThreadImpl.h"
#include "zthread/PoolExecutor.h"
#include "zthread/MonitoredQueue.h"
#include "zthread/FastMutex.h"
#include "ThreadImpl.h"
#include "ThreadQueue.h"

#include <algorithm>
#include <deque>
#include <utility>

using namespace ZThread;

namespace ZThread {

  namespace {

    /**
     */
    class WaiterQueue {

      typedef std::deque<ThreadImpl*>  ThreadList;
      
      typedef struct group_t {
        size_t     id;
        size_t     count;
        ThreadList waiters;
        group_t(size_t n) : id(n), count(0) {}
      } Group;

      typedef std::deque<Group>  GroupList;

      //! Predicate to find a specific group
      struct by_id : public std::unary_function<bool, Group> {
        size_t id;
        by_id(size_t n) : id(n) {}
        bool operator()(const Group& grp) {
          return grp.id == id;
        }
      };

      //! Functor to count groups
      struct counter : public std::unary_function<void, Group> {
        size_t count;
        counter() : count(0) {}
        void operator()(const Group& grp) { count += grp.count; }
        operator size_t() { return count; }
      };
      
      FastMutex     _lock;
      GroupList _list;
      size_t    _id;
      size_t    _generation;

    public:
      
      WaiterQueue() : _id(0), _generation(0) {
        // At least one empty-group exists
        _list.push_back( Group(_id++) );
      }

      /**
       * Insert the current thread into the current waiter list
       *
       * @pre  At least one empty group exists
       * @post At least one empty group exists
       */
      bool wait(unsigned long timeout) {

		ThreadImpl* current = ThreadImpl::current();
        Monitor& m = current->getMonitor();

        Monitor::STATE state;

        Guard<FastMutex> g1(_lock);

        // At least one empty-group exists
        assert(!_list.empty());

        // Return w/o waiting if there are no executing tasks
        if((size_t)std::for_each(_list.begin(), _list.end(), counter()) < 1)
          return true;

        // Update the waiter list for the active group 
        _list.back().waiters.push_back(current);
        size_t n = _list.back().id;

        m.acquire();
        
        {

          Guard<FastMutex, UnlockedScope> g2(g1);          
          state = timeout == 0 ? m.wait() : m.wait(timeout);

        }

        m.release();

        // If awoke due to a reason other than the last task in the group 'n' completing,
        // then then find the group 'current' is waiting in
        GroupList::iterator i = std::find_if(_list.begin(), _list.end(), by_id(n));
        if(i != _list.end()) {

          // Remove 'current' from that list if it is still a member
          ThreadList::iterator j = std::find(i->waiters.begin(), i->waiters.end(), current);
          if(j != i->waiters.end())
            i->waiters.erase(j);

        }

        // At least one empty-group exists
        assert(!_list.empty());

        switch(state) {
          case Monitor::SIGNALED:
            break;
          case Monitor::TIMEDOUT:
            return false;
          case Monitor::INTERRUPTED:
            throw Interrupted_Exception();
          default:
            throw Synchronization_Exception();
        } 
       
        return true;

      }
      
      /**
       * Increment the active group count
       *
       * @pre at least 1 empty group exists
       * @post at least 1 non-empty group exists 
       */
      std::pair<size_t, size_t> increment() {
        
        Guard<FastMutex> g(_lock);
        
        // At least one empty-group exists
        assert(!_list.empty());

        GroupList::iterator i = --_list.end();
        size_t n = i->id;

        if(i == _list.end()) {

          // A group should never have been removed until
          // the final task in that group completed
          assert(0);

        }

        i->count++;

        // When the active group is being incremented, insert a new active group
        // to replace it if there were waiting threads
        if(i == --_list.end() && !i->waiters.empty()) 
          _list.push_back(Group(_id++));

        // At least 1 non-empty group exists
        assert((size_t)std::for_each(_list.begin(), _list.end(), counter()) > 0);

        return std::make_pair(n, _generation);

      }
      

      /**
       * Decrease the count for the group with the given id.
       *
       * @param n group id
       * 
       * @pre  At least 1 non-empty group exists
       * @post At least 1 empty group exists
       */
      void decrement(size_t n) {
       
        Guard<FastMutex> g1(_lock);
       
        // At least 1 non-empty group exists
        assert((size_t)std::for_each(_list.begin(), _list.end(), counter()) > 0);

        // Find the requested group
        GroupList::iterator i = std::find_if(_list.begin(), _list.end(), by_id(n));
        if(i == _list.end()) {
          
          // A group should never have been removed until
          // the final task in that group completed
          assert(0);

        }

        // Decrease the count for tasks in this group,
        if(--i->count == 0 && i == _list.begin()) {
       
          do { 

            // When the first group completes, wake all waiters for every
            // group, starting from the first until a group that is not 
            // complete is reached

            /*
            // Don't remove the empty active group
            if(i == --_list.end() && i->waiters.empty())
              break;
            */
            
            if( awaken(*i) ) {
            
              // If all waiters were awakened, remove the group  
              i = _list.erase(i);
              
            } else {
              
              {

                // Otherwise, unlock and yield allowing the waiter
                // lists to be updated if other threads are busy
                Guard<FastLock, UnlockedScope> g2(g1);
                ThreadImpl::yield();
              
              }

              i = _list.begin();

            }
              
          } while(i != _list.end() && i->count == 0); 
          
          // Ensure that an active group exists
          if(_list.empty())
            _list.push_back( Group(++_id) );

        }

        // At least one group exists
        assert(!_list.empty());
        
      }

      /**
       */
      size_t generation(bool next = false) {

        Guard<FastMutex> g(_lock);
        return next ? _generation++ : _generation;

      }
      
    private:
      
      /**
       * Awaken all the waiters remaining in the given group
       * 
       * @return
       *   - true if all the waiting threads were successfully awakened.
       *   - false if there were one or more threads that could not be awakened.
       */
      bool awaken(Group& grp) {

        // Go through the waiter list in the given group; 
        for(ThreadList::iterator i = grp.waiters.begin(); i != grp.waiters.end();) {
          
          ThreadImpl* impl = *i;
          Monitor& m = impl->getMonitor();
          
          // Try the monitor lock, if it cant be locked skip to the next waiter
          if(m.tryAcquire()) {
            
            // Notify the monitor & remove from the waiter list so time isn't
            // wasted checking it again.
            i = grp.waiters.erase(i);
            
            // Try to wake the waiter, it doesn't matter if this is successful
            // or not (only fails when the monitor is already going to stop waiting). 
            m.notify();
            m.release();
            
          } else ++i;
          
        }
        
        return grp.waiters.empty();

      }

    };

    /**
     * @class GroupedRunnable
     * 
     * Wrap a task with group and generation information. 
     *
     * - 'group' allows tasks to be grouped together so that lists of waiting
     *   threads can be managed.
     *
     * - 'generation' allows tasks to be interrupted  
     */
    class GroupedRunnable : public Runnable {

      Task _task;
      WaiterQueue& _queue;

      size_t _group;
      size_t _generation;

    public:

      GroupedRunnable(const Task& task, WaiterQueue& queue)
        : _task(task), _queue(queue) { 
        
        std::pair<size_t, size_t> pr( _queue.increment() );
    
        _group      = pr.first;
        _generation = pr.second;

      }

      size_t group() const {
        return _group;
      }

      size_t generation() const {
        return _generation;
      }

      void run() {

        try {

          _task->run();

        } catch(...) {

        }

        _queue.decrement( group() );

      }

    };

    typedef CountedPtr<GroupedRunnable, size_t> ExecutorTask;

    /**
     *
     */
    class ExecutorImpl {
      
      typedef MonitoredQueue<ExecutorTask, FastMutex> TaskQueue;
      typedef std::deque<ThreadImpl*> ThreadList;
      
      TaskQueue   _taskQueue;
      WaiterQueue _waitingQueue;

      ThreadList      _threads;
      volatile size_t _size;


    public:
      
      ExecutorImpl() : _size(0) {}


      void registerThread() {
        
        Guard<TaskQueue> g(_taskQueue);

        ThreadImpl* impl = ThreadImpl::current();
        _threads.push_back(impl);

        // current cancel if too many threads are being created
        if(_threads.size() > _size) 
          impl->cancel();

      }

      void unregisterThread() {

        Guard<TaskQueue> g(_taskQueue);
        std::remove(_threads.begin(), _threads.end(), ThreadImpl::current());

      }

      void execute(const Task& task) {

        // Wrap the task with a grouped task
        GroupedRunnable* runnable = new GroupedRunnable(task, _waitingQueue);
 
        try {
          
          _taskQueue.add( ExecutorTask(runnable) );

        } catch(...) {

          // Incase the queue is canceled between the time the WaiterQueue is 
          // updated and the task is added to the TaskQueue
          _waitingQueue.decrement( runnable->group() );
          throw;

        }

      }

      void interrupt() {

        // Bump the generation number
        _waitingQueue.generation(true);

        Guard<TaskQueue> g(_taskQueue);
        
        // Interrupt all threads currently running, thier tasks would be
        // from an older generation
        for(ThreadList::iterator i = _threads.begin(); i != _threads.end(); ++i)
          (*i)->interrupt();
       
      }

      //! Adjust the number of desired workers and return the number of Threads needed
      size_t workers(size_t n) {
        
        Guard<TaskQueue> g(_taskQueue);

        size_t m = (_size < n) ? (n - _size) : 0;
        _size = n;
        
        return m;

      }
      
      size_t workers() {
        
        Guard<TaskQueue> g(_taskQueue);
        return _size;
        
      }
      
      ExecutorTask next() {
        
        ExecutorTask task;
        
        // Draw the task from the queue
        for(;;) {

          try { 

            task = _taskQueue.next();
            break;

          } catch(Interrupted_Exception&) {

            // Ignore interruption here, it can only come from
            // another thread interrupt()ing the executor. The
            // thread was interrupted in the hopes it was busy 
            // with a task

          }

        }
        
        // Interrupt the thread running the tasks when the generation
        // does not match the current generation
        if( task->generation() != _waitingQueue.generation() )
          ThreadImpl::current()->interrupt();

        // Otherwise, clear the interrupted status for the thread and
        // give it a clean slate to start with
        else
          ThreadImpl::current()->isInterrupted();

        return task;

      }

      bool isCanceled() {
        return _taskQueue.isCanceled();
      }

      void cancel() {
        _taskQueue.cancel();
      }

      bool wait(unsigned long timeout) {
        return _waitingQueue.wait(timeout);
      }

    };

    //! Executor job
    class Worker : public Runnable {

      CountedPtr< ExecutorImpl > _impl;
      
    public:
      
      //! Create a Worker that draws upon the given Queue
      Worker(const CountedPtr< ExecutorImpl >& impl) 
        : _impl(impl) { }
   
      //! Run until Thread or Queue are canceled
      void run() { 
        
        _impl->registerThread();
        
        // Run until the Queue is canceled
        while(!Thread::canceled()) {
          
          // Draw tasks from the queue
          ExecutorTask task( _impl->next() );
          task->run();
                    
        } 
        
        _impl->unregisterThread();
   
      }
      
    }; /* Worker */


    //! Helper
    class Shutdown : public Runnable {

      CountedPtr< ExecutorImpl > _impl;

    public:

      Shutdown(const CountedPtr< ExecutorImpl >& impl) 
        : _impl(impl) { }
      
      void run() {        
        _impl->cancel();
      }

    }; /* Shutdown */

  }

  PoolExecutor::PoolExecutor(size_t n)
    : _impl( new ExecutorImpl() ), _shutdown( new Shutdown(_impl) ) {
   
    size(n);
    
    // Request cancelation when main() exits
    ThreadQueue::instance()->insertShutdownTask(_shutdown);

  }

  PoolExecutor::~PoolExecutor() { 

    try {
      
      /**
       * If the shutdown task for this executor has not already been
       * selected to run, then run it locally
       */
      if(ThreadQueue::instance()->removeShutdownTask(_shutdown)) 
        _shutdown->run();
        
    } catch(...) { }

  } 

  void PoolExecutor::interrupt() {
    _impl->interrupt();
  }

  void PoolExecutor::size(size_t n) {
    
    if(n < 1)
      throw InvalidOp_Exception();

    for(size_t m = _impl->workers(n); m > 0; --m)
      Thread t(new Worker(_impl));

  }

  size_t PoolExecutor::size() {
    return _impl->workers();
  }


  void PoolExecutor::execute(const Task& task) {

    // Enqueue the task, the Queue will reject it with a 
    // Cancelation_Exception if the Executor has been canceled
    _impl->execute(task); 

  }

  void PoolExecutor::cancel() {
    _impl->cancel(); 
  }

  bool PoolExecutor::isCanceled() {
    return _impl->isCanceled(); 
  }
 
  void PoolExecutor::wait() {    
    _impl->wait(0);
  }

  bool PoolExecutor::wait(unsigned long timeout) {
    return _impl->wait(timeout == 0 ? 1 : timeout); 
  }

}
