/**
  @file System.cpp

  @maintainer Morgan McGuire, matrix@graphics3d.com

  Note: every routine must call init() first.

  There are two kinds of detection used in this file.  At compile
  time, the _MSC_VER #define is used to determine whether x86 assembly
  can be used at all.  At runtime, processor detection is used to
  determine if we can safely call the routines that use that assembly.

  @cite Rob Wyatt http://www.gamasutra.com/features/wyatts_world/19990709/processor_detection_01.htm
  @cite Benjamin Jurke http://www.flipcode.com/cgi-bin/msg.cgi?showThread=COTD-ProcessorDetectionClass&forum=cotd&id=-1
  @cite Michael Herf http://www.stereopsis.com/memcpy.html

  @created 2003-01-25
  @edited  2006-05-17
 */

#include "G3D/platform.h"
#include "G3D/System.h"
#include "G3D/debug.h"
#include "G3D/format.h"

#if defined(__OpenBSD__)
    #include <stdint.h>
#endif

#ifdef G3D_WIN32

    #include <conio.h>
    #include <sys/timeb.h>
    #include "G3D/RegistryUtil.h"

#elif defined(G3D_LINUX)

    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <errno.h>
    #include <sys/types.h>
    #include <sys/select.h>
    #include <termios.h>
    #include <unistd.h>
    #include <sys/ioctl.h>
    #include <sys/time.h>
    #include <pthread.h>

    // #include <assert.h>

#elif defined(G3D_OSX)

    #include <stdlib.h>
    #include <stdio.h>
    #include <errno.h>
    #include <sys/types.h>
    #include <sys/sysctl.h>
    #include <sys/select.h>
    #include <sys/time.h>
    #include <termios.h>
    #include <unistd.h>
    #include <pthread.h>
    #include <mach-o/arch.h>

    #include <sstream>
    #include <CoreServices/CoreServices.h>
#endif

#if defined(SSE)
    #include <xmmintrin.h>
#endif

namespace G3D {

static char                                     versionCstr[1024];
System::OutOfMemoryCallback                     System::outOfMemoryCallback = NULL;

void System::init() {
    // Cannot use most G3D data structures or utility functions in here because
    // they are not initialized.

    static bool initialized = false;

    if (initialized) {
        return;
    }

    initialized = true;

    if ((G3D_VER % 100) != 0) {
        sprintf(versionCstr, "G3D %d.%02d beta %d",
            G3D_VER / 10000,
            (G3D_VER / 100) % 100,
            G3D_VER % 100);
    } else {
        sprintf(versionCstr, "G3D %d.%02d",
            G3D_VER / 10000,
            (G3D_VER / 100) % 100);
    }

}

void System::memcpy(void* dst, const void* src, size_t numBytes) {
        ::memcpy(dst, src, numBytes);
}

void System::memset(void* dst, uint8 value, size_t numBytes) {
        ::memset(dst, value, numBytes);
}


////////////////////////////////////////////////////////////////
class BufferPool {
public:

    /** Only store buffers up to these sizes (in bytes) in each pool->
        Different pools have different management strategies.

        A large block is preallocated for tiny buffers; they are used with
        tremendous frequency.  Other buffers are allocated as demanded.
      */
    enum {tinyBufferSize = 128, smallBufferSize = 1024, medBufferSize = 4096};

    /**
       Most buffers we're allowed to store.
       64000 * 128  = 8 MB (preallocated)
        1024 * 1024 = 1 MB (allocated on demand)
        1024 * 4096 = 4 MB (allocated on demand)
     */
    enum {maxTinyBuffers = 64000, maxSmallBuffers = 1024, maxMedBuffers = 1024};

private:

    class MemBlock {
    public:
        void*           ptr;
        size_t          bytes;

        inline MemBlock() : ptr(NULL), bytes(0) {}
        inline MemBlock(void* p, size_t b) : ptr(p), bytes(b) {}
    };

    MemBlock smallPool[maxSmallBuffers];
    int smallPoolSize;

    MemBlock medPool[maxMedBuffers];
    int medPoolSize;

    /** The tiny pool is a single block of storage into which all tiny
        objects are allocated.  This provides better locality for
        small objects and avoids the search time, since all tiny
        blocks are exactly the same size. */
    void* tinyPool[maxTinyBuffers];
    int tinyPoolSize;

    /** Pointer to the data in the tiny pool */
    void* tinyHeap;

#   ifdef G3D_WIN32
    CRITICAL_SECTION    mutex;
#   else
    pthread_mutex_t     mutex;
#   endif

    /** Provide synchronization between threads */
    void lock() {
#       ifdef G3D_WIN32
            EnterCriticalSection(&mutex);
#       else
            pthread_mutex_lock(&mutex);
#       endif
    }

    void unlock() {
#       ifdef G3D_WIN32
            LeaveCriticalSection(&mutex);
#       else
            pthread_mutex_unlock(&mutex);
#       endif
    }

    /**
     Malloc out of the tiny heap.
     */
    inline void* tinyMalloc(size_t bytes) {
        // Note that we ignore the actual byte size
        // and create a constant size block.
        (void)bytes;
        debugAssert(tinyBufferSize >= bytes);

        void* ptr = NULL;

        if (tinyPoolSize > 0) {
            --tinyPoolSize;
            // Return the last one
            ptr = tinyPool[tinyPoolSize];
        }

        return ptr;
    }

    /** Returns true if this is a pointer into the tiny heap. */
    bool inTinyHeap(void* ptr) {
        return (ptr >= tinyHeap) &&
               (ptr < (uint8*)tinyHeap + maxTinyBuffers * tinyBufferSize);
    }

    void tinyFree(void* ptr) {
        debugAssert(tinyPoolSize < maxTinyBuffers);

        // Put the pointer back into the free list
        tinyPool[tinyPoolSize] = ptr;
        ++tinyPoolSize;

    }

    void flushPool(MemBlock* pool, int& poolSize) {
        for (int i = 0; i < poolSize; ++i) {
            ::free(pool->ptr);
            pool->ptr = NULL;
            pool->bytes = 0;
        }
        poolSize = 0;
    }

    /**  Allocate out of a specific pool->  Return NULL if no suitable
         memory was found.

         */
    void* malloc(MemBlock* pool, int& poolSize, size_t bytes) {

        // OPT: find the smallest block that satisfies the request.

        // See if there's something we can use in the buffer pool->
        // Search backwards since usually we'll re-use the last one.
        for (int i = (int)poolSize - 1; i >= 0; --i) {
            if (pool[i].bytes >= bytes) {
                // We found a suitable entry in the pool->

                // No need to offset the pointer; it is already offset
                void* ptr = pool[i].ptr;

                // Remove this element from the pool
                --poolSize;
                pool[i] = pool[poolSize];

                return ptr;
            }
        }

        return NULL;
    }

public:

    /** Count of memory allocations that have occurred. */
    int totalMallocs;
    int mallocsFromTinyPool;
    int mallocsFromSmallPool;
    int mallocsFromMedPool;

    /** Amount of memory currently allocated (according to the application).
        This does not count the memory still remaining in the buffer pool,
        but does count extra memory required for rounding off to the size
        of a buffer.
        Primarily useful for detecting leaks.*/
    // TODO: make me an atomic int!
    int bytesAllocated;

    BufferPool() {
        totalMallocs         = 0;

        mallocsFromTinyPool  = 0;
        mallocsFromSmallPool = 0;
        mallocsFromMedPool   = 0;

        bytesAllocated       = true;

        tinyPoolSize         = 0;
        tinyHeap             = NULL;

        smallPoolSize        = 0;

        medPoolSize          = 0;

        // Initialize the tiny heap as a bunch of pointers into one
        // pre-allocated buffer.
        tinyHeap = ::malloc(maxTinyBuffers * tinyBufferSize);
        for (int i = 0; i < maxTinyBuffers; ++i) {
            tinyPool[i] = (uint8*)tinyHeap + (tinyBufferSize * i);
        }
        tinyPoolSize = maxTinyBuffers;

#       ifdef G3D_WIN32
            InitializeCriticalSection(&mutex);
#       else
            pthread_mutex_init(&mutex, NULL);
#       endif
    }

    ~BufferPool() {
        ::free(tinyHeap);
#       ifdef G3D_WIN32
            DeleteCriticalSection(&mutex);
#       else
            // No destruction on pthreads
#       endif
    }

    void* realloc(void* ptr, size_t bytes) {
        if (ptr == NULL) {
            return malloc(bytes);
        }

        if (inTinyHeap(ptr)) {
            if (bytes <= tinyBufferSize) {
                // The old pointer actually had enough space.
                return ptr;
            } else {
                // Free the old pointer and malloc

                void* newPtr = malloc(bytes);
                System::memcpy(newPtr, ptr, tinyBufferSize);
                tinyFree(ptr);
                return newPtr;

            }
        } else {
            // In one of our heaps.

            // See how big the block really was
            size_t realSize = ((uint32*)ptr)[-1];
            if (bytes <= realSize) {
                // The old block was big enough.
                return ptr;
            }

            // Need to reallocate
            void* newPtr = malloc(bytes);
            System::memcpy(newPtr, ptr, realSize);
            free(ptr);
            return newPtr;
        }
    }

    void* malloc(size_t bytes) {
        lock();
        ++totalMallocs;

        if (bytes <= tinyBufferSize) {

            void* ptr = tinyMalloc(bytes);

            if (ptr) {
                ++mallocsFromTinyPool;
                unlock();
                return ptr;
            }

        }

        // Failure to allocate a tiny buffer is allowed to flow
        // through to a small buffer
        if (bytes <= smallBufferSize) {

            void* ptr = malloc(smallPool, smallPoolSize, bytes);

            if (ptr) {
                ++mallocsFromSmallPool;
                unlock();
                return ptr;
            }

        } else  if (bytes <= medBufferSize) {
            // Note that a small allocation failure does *not* fall
            // through into a medium allocation because that would
            // waste the medium buffer's resources.

            void* ptr = malloc(medPool, medPoolSize, bytes);

            if (ptr) {
                ++mallocsFromMedPool;
                unlock();
                return ptr;
            }
        }

        bytesAllocated += 4 + (int) bytes;
        unlock();

        // Heap allocate

        // Allocate 4 extra bytes for our size header (unfortunate,
        // since malloc already added its own header).
        void* ptr = ::malloc(bytes + 4);

        if (ptr == NULL) {
            // Flush memory pools to try and recover space
            flushPool(smallPool, smallPoolSize);
            flushPool(medPool, medPoolSize);
            ptr = ::malloc(bytes + 4);
        }

        if (ptr == NULL) {
            if ((System::outOfMemoryCallback != NULL) &&
                (System::outOfMemoryCallback(bytes + 4, true) == true)) {
                // Re-attempt the malloc
                ptr = ::malloc(bytes + 4);
            }
        }

        if (ptr == NULL) {
            if (System::outOfMemoryCallback != NULL) {
                // Notify the application
                System::outOfMemoryCallback(bytes + 4, false);
            }
            return NULL;
        }

        *(uint32*)ptr = (uint32)bytes;

        return (uint8*)ptr + 4;
    }

    void free(void* ptr) {
        if (ptr == NULL) {
            // Free does nothing on null pointers
            return;
        }

        debugAssert(isValidPointer(ptr));

        if (inTinyHeap(ptr)) {
            lock();
            tinyFree(ptr);
            unlock();
            return;
        }

        uint32 bytes = ((uint32*)ptr)[-1];

        lock();
        if (bytes <= smallBufferSize) {
            if (smallPoolSize < maxSmallBuffers) {
                smallPool[smallPoolSize] = MemBlock(ptr, bytes);
                ++smallPoolSize;
                unlock();
                return;
            }
        } else if (bytes <= medBufferSize) {
            if (medPoolSize < maxMedBuffers) {
                medPool[medPoolSize] = MemBlock(ptr, bytes);
                ++medPoolSize;
                unlock();
                return;
            }
        }
        bytesAllocated -= bytes + 4;
        unlock();

        // Free; the buffer pools are full or this is too big to store.
        ::free((uint8*)ptr - 4);
    }

    std::string performance() const {
        if (totalMallocs > 0) {
            int pooled = mallocsFromTinyPool +
                         mallocsFromSmallPool +
                         mallocsFromMedPool;

            int total = totalMallocs;

            return format("malloc performance: %5.1f%% <= %db, %5.1f%% <= %db, "
                          "%5.1f%% <= %db, %5.1f%% > %db",
                          100.0 * mallocsFromTinyPool  / total,
                          BufferPool::tinyBufferSize,
                          100.0 * mallocsFromSmallPool / total,
                          BufferPool::smallBufferSize,
                          100.0 * mallocsFromMedPool   / total,
                          BufferPool::medBufferSize,
                          100.0 * (1.0 - (double)pooled / total),
                          BufferPool::medBufferSize);
        } else {
            return "No System::malloc calls made yet.";
        }
    }

    std::string status() const {
        return format("preallocated shared buffers: %5d/%d x %db",
            maxTinyBuffers - tinyPoolSize, maxTinyBuffers, tinyBufferSize);
    }
};

// Dynamically allocated because we need to ensure that
// the buffer pool is still around when the last global variable
// is deallocated.
static BufferPool* bufferpool = NULL;

std::string System::mallocPerformance() {
#ifndef NO_BUFFERPOOL
    return bufferpool->performance();
#else
    return "NO_BUFFERPOOL";
#endif
}

std::string System::mallocStatus() {
#ifndef NO_BUFFERPOOL
    return bufferpool->status();
#else
    return "NO_BUFFERPOOL";
#endif
}

void System::resetMallocPerformanceCounters() {
#ifndef NO_BUFFERPOOL
    bufferpool->totalMallocs         = 0;
    bufferpool->mallocsFromMedPool   = 0;
    bufferpool->mallocsFromSmallPool = 0;
    bufferpool->mallocsFromTinyPool  = 0;
#endif
}

#ifndef NO_BUFFERPOOL
inline void initMem() {
    // Putting the test here ensures that the system is always
    // initialized, even when globals are being allocated.
    static bool initialized = false;
    if (! initialized) {
        bufferpool = new BufferPool();
        initialized = true;
    }
}
#endif

void* System::malloc(size_t bytes) {
#ifndef NO_BUFFERPOOL
    initMem();
    return bufferpool->malloc(bytes);
#else
    return ::malloc(bytes);
#endif
}

void* System::calloc(size_t n, size_t x) {
#ifndef NO_BUFFERPOOL
    void* b = System::malloc(n * x);
    System::memset(b, 0, n * x);
    return b;
#else
    return ::calloc(n, x);
#endif
}

void* System::realloc(void* block, size_t bytes) {
#ifndef NO_BUFFERPOOL
    initMem();
    return bufferpool->realloc(block, bytes);
#else
    return ::realloc(block, bytes);
#endif
}

void System::free(void* p) {
#ifndef NO_BUFFERPOOL
    bufferpool->free(p);
#else
    return ::free(p);
#endif
}

void* System::alignedMalloc(size_t bytes, size_t alignment) {
    alwaysAssertM(isPow2(alignment), "alignment must be a power of 2");

    // We must align to at least a word boundary.
    alignment = iMax((int)alignment, sizeof(void *));

    // Pad the allocation size with the alignment size and the
    // size of the redirect pointer.
    size_t totalBytes = bytes + alignment + sizeof(intptr_t);

    void* truePtr = System::malloc(totalBytes);

    if (!truePtr) {
        // malloc returned NULL
        return NULL;
    }

    debugAssert(isValidHeapPointer(truePtr));
    #ifdef G3D_WIN32
    // The blocks we return will not be valid Win32 debug heap
    // pointers because they are offset
    //  debugAssert(_CrtIsValidPointer(truePtr, totalBytes, TRUE) );
    #endif

    // The return pointer will be the next aligned location (we must at least
    // leave space for the redirect pointer, however).
    char* alignedPtr = ((char*)truePtr)+ sizeof(intptr_t);

#if 0
    // 2^n - 1 has the form 1111... in binary.
    uint32 bitMask = (alignment - 1);

    // Advance forward until we reach an aligned location.
    while ((((intptr_t)alignedPtr) & bitMask) != 0) {
        alignedPtr += sizeof(void*);
    }
#else
    alignedPtr += alignment - (((intptr_t)alignedPtr) & (alignment - 1));
    // assert((alignedPtr - truePtr) + bytes <= totalBytes);
#endif

    debugAssert((alignedPtr - truePtr) + bytes <= totalBytes);

    // Immediately before the aligned location, write the true array location
    // so that we can free it correctly.
    intptr_t* redirectPtr = (intptr_t*)(alignedPtr - sizeof(intptr_t));
    redirectPtr[0] = (intptr_t)truePtr;

    debugAssert(isValidHeapPointer(truePtr));

    #ifdef G3D_WIN32
        debugAssert( _CrtIsValidPointer(alignedPtr, bytes, TRUE) );
    #endif
    return (void*)alignedPtr;
}

void System::alignedFree(void* _ptr) {
    if (_ptr == NULL) {
        return;
    }

    char* alignedPtr = (char*)_ptr;

    // Back up one word from the pointer the user passed in.
    // We now have a pointer to a pointer to the true start
    // of the memory block.
    intptr_t* redirectPtr = (intptr_t*)(alignedPtr - sizeof(intptr_t));

    // Dereference that pointer so that ptr = true start
    void* truePtr = (void*)(redirectPtr[0]);

    debugAssert(isValidHeapPointer(truePtr));
    System::free(truePtr);
}

}  // namespace

