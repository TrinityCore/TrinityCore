/** 
  @file GThread.h
 
  @created 2005-09-22
  @edited  2007-01-31

 */

#ifndef G3D_GTHREAD_H
#define G3D_GTHREAD_H

#include "G3D/platform.h"
#include "G3D/ReferenceCount.h"
#include <string>

#ifndef G3D_WIN32
#   include <pthread.h>
#   include <signal.h>
#endif


namespace G3D {
        
typedef ReferenceCountedPointer<class GThread> GThreadRef;

/**
 Platform independent thread implementation.  You can either subclass and 
 override GThread::threadMain or call the create method with a method.

 Beware of reference counting and threads.  If circular references exist between
 GThread subclasses then neither class will ever be deallocated.  Also, 
 dropping all pointers (and causing deallocation) of a GThread does NOT 
 stop the underlying process.

 @sa G3D::GMutex, G3D::Spinlock, G3D::AtomicInt32
*/
class GThread : public ReferenceCountedObject {
private:
    // "Status" is a reserved work on FreeBSD
    enum GStatus {STATUS_CREATED, STATUS_STARTED, STATUS_RUNNING, STATUS_COMPLETED};

    // Not implemented on purpose, don't use
    GThread(const GThread &);
    GThread& operator=(const GThread&);
    bool operator==(const GThread&);

#ifdef G3D_WIN32
    static DWORD WINAPI internalThreadProc(LPVOID param);
#else
    static void* internalThreadProc(void* param);
#endif //G3D_WIN32

    volatile GStatus     m_status;

    // Thread handle to hold HANDLE and pthread_t
#ifdef G3D_WIN32
    HANDLE              m_handle;
    HANDLE              m_event;
#else
    pthread_t           m_handle;
#endif //G3D_WIN32

    std::string         m_name;

protected:

    /** Overriden by the thread implementor */
    virtual void threadMain() = 0;

public:
    typedef ReferenceCountedPointer<class GThread> Ref;
    enum SpawnBehavior {USE_NEW_THREAD, USE_CURRENT_THREAD};

    GThread(const std::string& name);

    virtual ~GThread();

    /** Constructs a basic GThread without requiring a subclass.

        @param proc The global or static function for the threadMain() */
    static GThreadRef create(const std::string& name, void (*proc)(void*), void* param = NULL);

    /** Starts the thread and executes threadMain().  Returns false if
       the thread failed to start (either because it was already started
       or because the OS refused).
       
       @param behavior If USE_CURRENT_THREAD, rather than spawning a new thread, this routine
       runs threadMain on the current thread.
       */
    bool start(SpawnBehavior behavior = USE_NEW_THREAD);

    /** Terminates the thread without notifying or
        waiting for a cancelation point. */
    void terminate();

    /**
        Returns true if threadMain is currently executing.  This will
        only be set when the thread is actually running and might not
        be set when start() returns. */
    bool running() const;

    /** True after start() has been called, even through the thread
        may have already completed(), or be currently running().*/
    bool started() const;

    /** Returns true if the thread has exited. */
    bool completed() const;

    /** Waits for the thread to finish executing. */
    void waitForCompletion();

    /** Returns thread name */
    inline const std::string& name() {
        return m_name;
    }
};


} // namespace G3D

#endif //G3D_GTHREAD_H
