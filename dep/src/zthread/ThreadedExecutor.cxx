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

#include "zthread/ThreadedExecutor.h"
#include "zthread/Guard.h"
#include "zthread/FastMutex.h"
#include "zthread/Time.h"

#include "ThreadImpl.h"

namespace ZThread {

  namespace {

    //!
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

        ThreadImpl* self = ThreadImpl::current();
        Monitor& m = self->getMonitor();

        Monitor::STATE state;

        Guard<Lockable> g1(_lock);

        // At least one empty-group exists
        assert(!_list.empty());

        // Return w/o waiting if there are no executing tasks
        if((size_t)std::for_each(_list.begin(), _list.end(), counter()) < 1)
          return true;

        // Update the waiter list for the active group
        _list.back().waiters.push_back(self);
        size_t n = _list.back().id;

        m.acquire();

        {

          Guard<Lockable, UnlockedScope> g2(g1);
          state = timeout == 0 ? m.wait() : m.wait(timeout);

        }

        m.release();

        // If awoke due to a reason other than the last task in the group 'n' completing,
        // then then find the group 'self' is waiting in
        GroupList::iterator i = std::find_if(_list.begin(), _list.end(), by_id(n));
        if(i != _list.end()) {

          // Remove 'self' from that list if it is still a member
          ThreadList::iterator j = std::find(i->waiters.begin(), i->waiters.end(), self);
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

    //! Synchronization point for the Executor
    class ExecutorImpl {

      typedef std::deque<ThreadImpl*> ThreadList;

      bool _canceled;
      FastMutex _lock;

      //! Worker threads
      ThreadList _threads;

      WaiterQueue _queue;

    public:

      ExecutorImpl() : _canceled(false) {}

      WaiterQueue& getWaiterQueue() {
        return _queue;
      }

      void registerThread(size_t generation) {

        // Interrupt slow starting threads
        if(getWaiterQueue().generation() != generation)
          ThreadImpl::current()->interrupt();

        // Enqueue for possible future interrupt()
        else {

          Guard<FastMutex> g(_lock);
          _threads.push_back( ThreadImpl::current() );

        }

      }

      void unregisterThread() {

        Guard<FastMutex> g(_lock);
        std::remove(_threads.begin(), _threads.end(), ThreadImpl::current() );

      }

      void cancel() {

        Guard<FastMutex> g(_lock);
        _canceled = true;

      }

      bool isCanceled() {

        if(_canceled)
          return true;

        Guard<FastMutex> g(_lock);
        return _canceled;

      }

      void interrupt() {

        Guard<FastMutex> g(_lock);

        // Interrupt all the registered threads
        for(ThreadList::iterator i = _threads.begin(); i != _threads.end(); ++i)
          (*i)->interrupt();

        // Bump the generation up, ensuring slow starting threads get this interrupt
        getWaiterQueue().generation( true );

      }

    }; /* ExecutorImpl */

    //! Wrap a generation and a group around a task
    class Worker : public Runnable {

      CountedPtr< ExecutorImpl > _impl;
      Task _task;

      size_t _generation;
      size_t _group;

    public:

      Worker(const CountedPtr< ExecutorImpl >& impl, const Task& task)
        : _impl(impl), _task(task) {

        std::pair<size_t, size_t> pr( _impl->getWaiterQueue().increment() );

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

        // Register this thread once its begun; the generation is used to ensure
        // threads that are slow starting are properly interrupted

        _impl->registerThread( generation() );

        try {
          _task->run();
        } catch(...) {
          /* consume the exceptions the work propogates */
        }

        _impl->getWaiterQueue().decrement( group() );

        // Unregister this thread

        _impl->unregisterThread();

      }

    }; /* Worker */

  }

  ThreadedExecutor::ThreadedExecutor() : _impl(new ExecutorImpl) {}

  ThreadedExecutor::~ThreadedExecutor() {}

  void ThreadedExecutor::execute(const Task& task) {

    Thread t( new Worker(_impl, task) );

  }

  void ThreadedExecutor::interrupt() {
    _impl->interrupt();
  }

  void ThreadedExecutor::cancel() {
    _impl->cancel();
  }

  bool ThreadedExecutor::isCanceled() {
    return _impl->isCanceled();
  }

  void ThreadedExecutor::wait() {
    _impl->getWaiterQueue().wait(0);
  }

  bool ThreadedExecutor::wait(unsigned long timeout) {
    return _impl->getWaiterQueue().wait(timeout == 0 ? 1 : timeout);
  }

}
