/**
 @file GThread.cpp

 GThread class.

 @created 2005-09-24
 @edited  2010-09-22
 */

#include "G3D/GThread.h"
#include "G3D/System.h"
#include "G3D/debugAssert.h"
#include "G3D/GMutex.h"

namespace G3D {

namespace _internal {

class BasicThread: public GThread {
public:
    BasicThread(const std::string& name, void (*proc)(void*), void* param):
        GThread(name), m_wrapperProc(proc), m_param(param) { }
protected:
    virtual void threadMain() {
        m_wrapperProc(m_param);
    }

private:
    void (*m_wrapperProc)(void*);

    void* m_param;
};

} // namespace _internal


GThread::GThread(const std::string& name):
    m_status(STATUS_CREATED),
    m_name(name) {

#ifdef G3D_WINDOWS
    m_event = NULL;
#endif

    // system-independent clear of handle
    System::memset(&m_handle, 0, sizeof(m_handle));
}

GThread::~GThread() {
#ifdef _MSC_VER
#   pragma warning( push )
#   pragma warning( disable : 4127 )
#endif
    alwaysAssertM(m_status != STATUS_RUNNING, "Deleting thread while running.");
#ifdef _MSC_VER
#   pragma warning( pop )
#endif

#ifdef G3D_WINDOWS
    if (m_event) {
        ::CloseHandle(m_event);
    }
#endif
}


GThreadRef GThread::create(const std::string& name, void (*proc)(void*), void* param) {
    return shared_ptr<GThread>(new _internal::BasicThread(name, proc, param));
}


bool GThread::started() const {
    return m_status != STATUS_CREATED;
}


int GThread::numCores() {
    return System::numCores();
}

#ifdef G3D_WINDOWS
// From http://msdn.microsoft.com/en-us/library/xcb2z8hs.aspx
const DWORD MS_VC_EXCEPTION=0x406D1388;

#pragma pack(push,8)
typedef struct tagTHREADNAME_INFO {
   DWORD dwType; // Must be 0x1000.
   LPCSTR szName; // Pointer to name (in user addr space).
   DWORD dwThreadID; // Thread ID (-1=caller thread).
   DWORD dwFlags; // Reserved for future use, must be zero.
} THREADNAME_INFO;
#pragma pack(pop)

static void SetThreadName(DWORD dwThreadID, const char* threadName) {
   THREADNAME_INFO info;
   info.dwType = 0x1000;
   info.szName = threadName;
   info.dwThreadID = dwThreadID;
   info.dwFlags = 0;

   __try {
      RaiseException( MS_VC_EXCEPTION, 0, sizeof(info)/sizeof(ULONG_PTR), (ULONG_PTR*)&info );
   } __except(EXCEPTION_EXECUTE_HANDLER) {}
}
#endif


bool GThread::start(SpawnBehavior behavior) {
    
    debugAssertM(! started(), "Thread has already executed.");
    if (started()) {
        return false;
    }

    m_status = STATUS_STARTED;

    if (behavior == USE_CURRENT_THREAD) {
        // Run on this thread
        m_status = STATUS_RUNNING;
        threadMain();
        m_status = STATUS_COMPLETED;
        return true;
    }

#   ifdef G3D_WINDOWS
        DWORD threadId;

        m_event = ::CreateEvent(NULL, TRUE, FALSE, NULL);
        debugAssert(m_event);

        m_handle = ::CreateThread(NULL, 0, &internalThreadProc, this, 0, &threadId);

        if (m_handle == NULL) {
            ::CloseHandle(m_event);
            m_event = NULL;
        }

        SetThreadName(threadId, m_name.c_str());

        return (m_handle != NULL);
#   else
        if (!pthread_create(&m_handle, NULL, &internalThreadProc, this)) {
            return true;
        } else {
            // system-independent clear of handle
            System::memset(&m_handle, 0, sizeof(m_handle));

            return false;
        }
#   endif
}

void GThread::terminate() {
    if (m_handle) {
#       ifdef G3D_WINDOWS
        ::TerminateThread(m_handle, 0);
#       else
        pthread_kill(m_handle, SIGSTOP);
#       endif
        // system-independent clear of handle
        System::memset(&m_handle, 0, sizeof(m_handle));
    }
}


bool GThread::running() const{
    return (m_status == STATUS_RUNNING);
}


bool GThread::completed() const {
    return (m_status == STATUS_COMPLETED);
}


void GThread::waitForCompletion() {
    if (m_status == STATUS_COMPLETED) {
        // Must be done
        return;
    }

#   ifdef G3D_WINDOWS
        debugAssert(m_event);
        ::WaitForSingleObject(m_event, INFINITE);
#   else
        debugAssert(m_handle);
        pthread_join(m_handle, NULL);
#   endif
}


#ifdef G3D_WINDOWS
DWORD WINAPI GThread::internalThreadProc(LPVOID param) {
    GThread* current = reinterpret_cast<GThread*>(param);
    debugAssert(current->m_event);
    current->m_status = STATUS_RUNNING;
    current->threadMain();
    current->m_status = STATUS_COMPLETED;
    ::SetEvent(current->m_event);
    return 0;
}
#else
void* GThread::internalThreadProc(void* param) {
    GThread* current = reinterpret_cast<GThread*>(param);
    current->m_status = STATUS_RUNNING;
    current->threadMain();
    current->m_status = STATUS_COMPLETED;
    return (void*)NULL;
}
#endif



//GMutex implementation
GMutex::GMutex() {
#ifdef G3D_WINDOWS
    ::InitializeCriticalSection(&m_handle);
#else
    int ret = pthread_mutexattr_init(&m_attr);
    debugAssert(ret == 0);
    ret = pthread_mutexattr_settype(&m_attr, PTHREAD_MUTEX_RECURSIVE);
    debugAssert(ret == 0);
    ret = pthread_mutex_init(&m_handle, &m_attr);
    debugAssert(ret == 0);
#endif
}

GMutex::~GMutex() {
    //TODO: Debug check for locked
#ifdef G3D_WINDOWS
    ::DeleteCriticalSection(&m_handle);
#else
    int ret = pthread_mutex_destroy(&m_handle);
    debugAssert(ret == 0);
    ret = pthread_mutexattr_destroy(&m_attr);
    debugAssert(ret == 0);
#endif
}

bool GMutex::tryLock() {
#ifdef G3D_WINDOWS
    return (::TryEnterCriticalSection(&m_handle) != 0);
#else
    return (pthread_mutex_trylock(&m_handle) == 0);
#endif
}

void GMutex::lock() {
#ifdef G3D_WINDOWS
    ::EnterCriticalSection(&m_handle);
#else
    pthread_mutex_lock(&m_handle);
#endif
}

void GMutex::unlock() {
#ifdef G3D_WINDOWS
    ::LeaveCriticalSection(&m_handle);
#else
    pthread_mutex_unlock(&m_handle);
#endif
}

} // namespace G3D
