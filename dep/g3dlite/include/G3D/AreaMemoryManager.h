/**
 \file AreaMemoryManager.h
  
 \maintainer Morgan McGuire, http://graphics.cs.williams.edu

 \created 2009-01-20
 \edited  2010-10-29

 Copyright 2000-2012, Morgan McGuire.
 All rights reserved.
 */


#ifndef G3D_AreaMemoryManager_h
#define G3D_AreaMemoryManager_h

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include "G3D/Array.h"
#include "G3D/MemoryManager.h"

namespace G3D {

/** 
  \brief Allocates memory in large blocks and then frees it as an area.

  Useful for ensuring cache coherence and for reducing the time cost of 
  multiple allocations and deallocations.

  <b>Not threadsafe</b>
 */
class AreaMemoryManager : public MemoryManager {
private:

    class Buffer {
    private:
        uint8*              m_first;
        size_t              m_size;
        size_t              m_used;

    public:

        Buffer(size_t size);

        ~Buffer();

        /** Returns NULL if out of space */
        void* alloc(size_t s);
    };
    
    size_t                  m_sizeHint;

    /** The underlying array is stored in regular MemoryManager heap memory */
    Array<Buffer*>          m_bufferArray;

    AreaMemoryManager(size_t sizeHint);

public:

    typedef shared_ptr<AreaMemoryManager> Ref;

    /** 
        \param sizeHint Total amount of memory expected to be allocated.
        The allocator will allocate memory from the system in increments
        of this size.
    */
    static AreaMemoryManager::Ref create(size_t sizeHint = 10 * 1024 * 1024);

    /** Invokes deallocateAll. */
    ~AreaMemoryManager();

    size_t bytesAllocated() const;

    /** Allocates memory out of the buffer pool. 
        @param s must be no larger than sizeHint */
    virtual void* alloc(size_t s);

    /** Ignored. */
    virtual void free(void* x);

    virtual bool isThreadsafe() const;

    /** Deletes all previously allocated memory. Because delete is not
        invoked on objects in this memory, it is not safe to simply
        free memory containing C++ objects that expect their destructors
        to be called. */
    void deallocateAll();
};

typedef AreaMemoryManager CoherentAllocator;
}

#endif
