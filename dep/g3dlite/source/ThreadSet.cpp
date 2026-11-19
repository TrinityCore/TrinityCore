#include "G3D/ThreadSet.h"
#include "G3D/GThread.h"

namespace G3D {

int ThreadSet::size() const {
    ThreadSet* me = const_cast<ThreadSet*>(this);
    me->m_lock.lock();
    int s = m_thread.size();
    me->m_lock.unlock();
    return s;
}


int ThreadSet::numStarted() const {
    ThreadSet* me = const_cast<ThreadSet*>(this);
    me->m_lock.lock();
    int count = 0;
    for (int i = 0; i < m_thread.size(); ++i) {
        if (m_thread[i]->started()) {
            ++count;
        }
    }
    me->m_lock.unlock();
    return count;
}
    
    
void ThreadSet::start(SpawnBehavior lastBehavior) const {
    ThreadSet* me = const_cast<ThreadSet*>(this);

    Array<GThreadRef> unstarted;
    me->m_lock.lock();
    // Find the unstarted threads
    for (int i = 0; i < m_thread.size(); ++i) {
        if (! m_thread[i]->started()) {
            unstarted.append(m_thread[i]);
        }
    }

    int last = unstarted.size();
    if (lastBehavior == USE_CURRENT_THREAD) {
        // Save the last unstarted for the current thread
        --last;
    }

    // Start all threads
    for (int i = 0; i < last; ++i) {
        unstarted[i]->start(USE_NEW_THREAD);
    }

    me->m_lock.unlock();

    // Start the last one on my thread
    if ((unstarted.size() > 0) && (lastBehavior == USE_CURRENT_THREAD)) {
        unstarted.last()->start(USE_CURRENT_THREAD);
        debugAssert(unstarted.last()->completed());
    }
}
    

void ThreadSet::terminate() const {
    ThreadSet* me = const_cast<ThreadSet*>(this);
    me->m_lock.lock();
    for (int i = 0; i < m_thread.size(); ++i) {
        if (m_thread[i]->started()) {
            m_thread[i]->terminate();
        }
    }
    me->m_lock.unlock();
}
    

void ThreadSet::waitForCompletion() const {
    ThreadSet* me = const_cast<ThreadSet*>(this);

    me->m_lock.lock();
    for (int i = 0; i < m_thread.size(); ++i) {
        if (m_thread[i]->started()) {
            m_thread[i]->waitForCompletion();
        }
    }
    me->m_lock.unlock();
}
    

int ThreadSet::removeCompleted() {
    m_lock.lock();
    for (int i = 0; i < m_thread.size(); ++i) {
        if (m_thread[i]->completed()) {
            m_thread.fastRemove(i);
            --i;
        }
    }
    
    int s = m_thread.size();
    m_lock.unlock();
    return s;
}


void ThreadSet::clear() {
    m_lock.lock();
    m_thread.clear();
    m_lock.unlock();
}
    

int ThreadSet::insert(const ThreadRef& t) {
    m_lock.lock();
    bool found = false;
    for (int i = 0; i < m_thread.size() && ! found; ++i) {
        found = (m_thread[i] == t);
    }
    if (! found) {
        m_thread.append(t);
    }
    int s = m_thread.size();
    m_lock.unlock();
    return s;
}
    

bool ThreadSet::remove(const ThreadRef& t) {
    m_lock.lock();
    bool found = false;
    for (int i = 0; i < m_thread.size() && ! found; ++i) {
        found = (m_thread[i] == t);
        if (found) {
            m_thread.fastRemove(i);
        }
    }
    m_lock.unlock();
    return found;
}
    

bool ThreadSet::contains(const ThreadRef& t) const {
    ThreadSet* me = const_cast<ThreadSet*>(this);
    me->m_lock.lock();
    bool found = false;
    for (int i = 0; i < m_thread.size() && ! found; ++i) {
        found = (m_thread[i] == t);
    }
    me->m_lock.unlock();
    return found;
}

   
ThreadSet::Iterator ThreadSet::begin() {
    return m_thread.begin();
}
    

ThreadSet::Iterator ThreadSet::end() {
    return m_thread.end();
}
    

ThreadSet::ConstIterator ThreadSet::begin() const {
    return m_thread.begin();
}
    
    
ThreadSet::ConstIterator ThreadSet::end() const {
    return m_thread.end();
}


} // namespace G3D
