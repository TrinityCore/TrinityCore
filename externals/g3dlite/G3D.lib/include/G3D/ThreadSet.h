#ifndef G3D_THREADSET_H
#define G3D_THREADSET_H

#include "G3D/platform.h"
#include "G3D/Array.h"
#include "G3D/ReferenceCount.h"
#include "G3D/GThread.h"

namespace G3D {

/** Manages a set of threads. All methods are threadsafe except for
    the iterator begin/end. 

    @beta*/
class ThreadSet : public ReferenceCountedObject {
public:
    /** Intended to allow future use with a template parameter.*/
    typedef GThread                                        Thread;

    typedef ReferenceCountedPointer<Thread>                ThreadRef;
    typedef ReferenceCountedPointer<ThreadSet>             Ref;
    typedef Array<ThreadRef>::Iterator                     Iterator;
    typedef Array<ThreadRef>::ConstIterator                ConstIterator;

private:

    /** Protects m_thread */
    GMutex                m_lock;

    /** Threads in the set */
    Array<ThreadRef>      m_thread;

public:
    
    /** Total number of threads (some of which may be completed). */
    int size() const;

    /** Number of threads that have been started */
    int numStarted() const;

    /** Start all threads that are not currently started */
    void start() const;

    /** Terminate all threads that are currently started */
    void terminate() const;

    /** Waits until all started threads have completed. */
    void waitForCompletion() const;

    /** Remove all (not stopping them) */
    void clear();

    /** Removes completed threads and returns the new size.*/
    int removeCompleted();

    /** Inserts a new thread, if it is not already present, and 
        returns the new number of threads.*/
    int insert(const ThreadRef& t);

    /** Removes a thread. Returns true if the thread was present and
        removed. */
    bool remove(const ThreadRef& t);

    bool contains(const ThreadRef& t) const;
   
    /** It is an error to mutate the ThreadSet while iterating through it. */
    Iterator begin();

    Iterator end();

    ConstIterator begin() const;

    ConstIterator end() const;
};


} // namespace G3D

#endif
