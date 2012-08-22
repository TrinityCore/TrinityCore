/** 
  @file GMutex.h
   
  @created 2005-09-22
  @edited  2009-03-25
 */

#ifndef G3D_GMutex_h
#define G3D_GMutex_h

#include "G3D/platform.h"
#include "G3D/AtomicInt32.h"
#include "G3D/debugAssert.h"
#include <string>

#ifndef G3D_WIN32
#   include <pthread.h>
#   include <signal.h>
#   include <unistd.h>
#endif


namespace G3D {

/**
   \brief A mutual exclusion lock that busy-waits when locking.

   On a machine with one (significant) thread per processor core,
   a spinlock may be substantially faster than a mutex.

   \sa G3D::GThread, G3D::GMutex, G3D::AtomicInt32
 */
class Spinlock {
private:

    AtomicInt32   x;

public:

    inline Spinlock() : x(0) {}

    /** Busy waits until the lock is unlocked, then locks it
        exclusively.  Returns true if the lock succeeded on the first
        try (indicating no contention). */
    inline bool lock() {
        bool first = true;
        while (x.compareAndSet(0, 1) == 1) {
            first = false;
#           ifdef G3D_WIN32
                Sleep(0);
#           else
                usleep(0);
#           endif
        }
        return first;
    }

    inline void unlock() {
        x.compareAndSet(1, 0);
    }

};

/**
 \brief Mutual exclusion lock used for synchronization.

 @sa G3D::GThread, G3D::AtomicInt32, G3D::Spinlock
*/
class GMutex {
private:
#   ifdef G3D_WIN32
    CRITICAL_SECTION                    m_handle;
#   else
    pthread_mutex_t                     m_handle;
    pthread_mutexattr_t                 m_attr;
#   endif

    // Not implemented on purpose, don't use
    GMutex(const GMutex &mlock);
    GMutex &operator=(const GMutex &);
    bool operator==(const GMutex&);

public:
    GMutex();
    ~GMutex();

    /** Locks the mutex or blocks until available. */
    void lock();

    /** Locks the mutex if it not already locked.
        Returns true if lock successful, false otherwise. */
    bool tryLock();

    /** Unlocks the mutex. */
    void unlock();
};


/**
    Automatically locks while in scope.
*/
class GMutexLock {
private:
    GMutex* m;

    // Not implemented on purpose, don't use
    GMutexLock(const GMutexLock &mlock);
    GMutexLock &operator=(const GMutexLock &);
    bool operator==(const GMutexLock&);

public:
    GMutexLock(GMutex* mutex) {
        m = mutex;
        m->lock();
    }

    ~GMutexLock() {
        m->unlock();
    }
};

} // G3D

#endif
