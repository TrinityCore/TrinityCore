/**
  @file MemoryManager.cpp

  @maintainer Morgan McGuire, http://graphics.cs.williams.edu
  @created 2009-04-20
  @edited  2009-05-29

  Copyright 2000-2009, Morgan McGuire.
  All rights reserved.
 */

#include "G3D/MemoryManager.h"
#include "G3D/System.h"

namespace G3D {

MemoryManager::MemoryManager() {}


void* MemoryManager::alloc(size_t s) {
    return System::malloc(s);
}


void MemoryManager::free(void* ptr) {
    System::free(ptr);
}


bool MemoryManager::isThreadsafe() const {
    return true;
}


MemoryManager::Ref MemoryManager::create() {
    static MemoryManager::Ref m(new MemoryManager());
    return m;
}


///////////////////////////////////////////////////

AlignedMemoryManager::AlignedMemoryManager() {}


void* AlignedMemoryManager::alloc(size_t s) {
    return System::alignedMalloc(s, 16);
}


void AlignedMemoryManager::free(void* ptr) {
    System::alignedFree(ptr);
}


bool AlignedMemoryManager::isThreadsafe() const {
    return true;
}


AlignedMemoryManager::Ref AlignedMemoryManager::create() {
    static AlignedMemoryManager::Ref m(new AlignedMemoryManager());
    return m;
}


///////////////////////////////////////////////////

CRTMemoryManager::CRTMemoryManager() {}


void* CRTMemoryManager::alloc(size_t s) {
    return ::malloc(s);
}


void CRTMemoryManager::free(void* ptr) {
    return ::free(ptr);
}


bool CRTMemoryManager::isThreadsafe() const {
    return true;
}


CRTMemoryManager::Ref CRTMemoryManager::create() {
    static CRTMemoryManager::Ref m(new CRTMemoryManager());
    return m;
}
}
