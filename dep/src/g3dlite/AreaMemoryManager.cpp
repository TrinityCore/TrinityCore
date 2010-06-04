/**
 @file AreaMemoryManager.cpp
  
 @maintainer Morgan McGuire, http://graphics.cs.williams.edu

 @created 2009-01-20
 @edited  2009-01-20

 Copyright 2000-2009, Morgan McGuire.
 All rights reserved.
 */

#include "G3D/AreaMemoryManager.h"
#include "G3D/System.h"

namespace G3D {

AreaMemoryManager::Buffer::Buffer(size_t size) : m_size(size), m_used(0) {
    // Allocate space for a lot of buffers.
    m_first = (uint8*)::malloc(m_size);
}


AreaMemoryManager::Buffer::~Buffer() {
    ::free(m_first);
}


void* AreaMemoryManager::Buffer::alloc(size_t s) {
    if (s + m_used > m_size) {
        return NULL;
    } else {
        void* old = m_first + m_used;
        m_used += s;
        return old;
    }
}


bool AreaMemoryManager::isThreadsafe() const {
    return false;
}


AreaMemoryManager::Ref AreaMemoryManager::create(size_t sizeHint) {
    return new AreaMemoryManager(sizeHint);
}


AreaMemoryManager::AreaMemoryManager(size_t sizeHint) : m_sizeHint(sizeHint) {
    debugAssert(sizeHint > 0);
}


AreaMemoryManager::~AreaMemoryManager() {
    deallocateAll();
}


size_t AreaMemoryManager::bytesAllocated() const {
    return m_sizeHint * m_bufferArray.size();
}


void* AreaMemoryManager::alloc(size_t s) {
    void* n = (m_bufferArray.size() > 0) ? m_bufferArray.last()->alloc(s) : NULL;
    if (n == NULL) {
        // This buffer is full
        m_bufferArray.append(new Buffer(max(s, m_sizeHint)));
        return m_bufferArray.last()->alloc(s);
    } else {
        return n;
    }
}


void AreaMemoryManager::free(void* x) {
    // Intentionally empty; we block deallocate
}


void AreaMemoryManager::deallocateAll() {
    m_bufferArray.deleteAll();
    m_bufferArray.clear();
}

}
