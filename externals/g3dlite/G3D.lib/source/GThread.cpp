/**
 @file GThread.cpp

 GThread class.

 @created 2005-09-24
 @edited  2005-10-22
 */

#include "G3D/GThread.h"
#include "G3D/System.h"
#include "G3D/debugAssert.h"


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

#ifdef G3D_WIN32
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

#ifdef G3D_WIN32
    if (m_event) {
        ::CloseHandle(m_event);
    }
#endif
}

GThreadRef GThread::create(const std::string& name, void (*proc)(void*), void* param) {
    return new _internal::BasicThread(name, proc, param);
}


bool GThread::started() const {
    return m_status != STATUS_CREATED;
}

bool GThread::start() {
    
    debugAssertM(! started(), "Thread has already executed.");
    if (started()) {
        return false;
    }

    m_status = STATUS_STARTED;

#   ifdef G3D_WIN32
    DWORD threadId;

    m_event = ::CreateEvent(NULL, TRUE, FALSE, NULL);
    debugAssert(m_event);

    m_handle = ::CreateThread(NULL, 0, &internalThreadProc, this, 0, &threadId);

    if (m_handle == NULL) {
        ::CloseHandle(m_event);
        m_event = NULL;
    }

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
#       ifdef G3D_WIN32
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
#   ifdef G3D_WIN32
    debugAssert(m_event);
    ::WaitForSingleObject(m_event, INFINITE);
#   else
    debugAssert(m_handle);
    pthread_join(m_handle, NULL);
#   endif
}

#ifdef G3D_WIN32
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



GMutex::GMutex() {
#   ifdef G3D_WIN32
    ::InitializeCriticalSection(&m_handle);
#   else
    pthread_mutex_init(&m_handle, NULL);
#   endif
}

GMutex::~GMutex() {
    //TODO: Debug check for locked
#   ifdef G3D_WIN32
    ::DeleteCriticalSection(&m_handle);
#   else
    pthread_mutex_destroy(&m_handle);
#   endif
}

//bool GMutex::tryLock() {
//#   ifdef G3D_WIN32
//    return ::TryEnterCriticalSection(&m_handle);
//#   else
//    return pthread_mutex_trylock(&m_handle);
//#   endif
//}

void GMutex::lock() {
#   ifdef G3D_WIN32
    ::EnterCriticalSection(&m_handle);
#   else
    pthread_mutex_lock(&m_handle);
#   endif
}

void GMutex::unlock() {
#   ifdef G3D_WIN32
    ::LeaveCriticalSection(&m_handle);
#   else
    pthread_mutex_unlock(&m_handle);
#   endif
}

} // namespace G3D
