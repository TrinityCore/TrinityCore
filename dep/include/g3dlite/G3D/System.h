/**
  @file System.h

  @maintainer Morgan McGuire, matrix@graphics3d.com

  @cite Rob Wyatt http://www.gamasutra.com/features/wyatts_world/19990709/processor_detection_01.htm
  @cite Benjamin Jurke http://www.flipcode.com/cgi-bin/msg.cgi?showThread=COTD-ProcessorDetectionClass&forum=cotd&id=-1
  @cite Michael Herf http://www.stereopsis.com/memcpy.html

  @created 2003-01-25
  @edited  2006-04-26
 */

#ifndef G3D_SYSTEM_H
#define G3D_SYSTEM_H

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include <string>

#ifdef G3D_OSX
#   include <CoreServices/CoreServices.h>
#endif

namespace G3D {

typedef double RealTime;

class System {
public:

    /** Called automatically by the other System routines.*/
    static void init();

    /**
     Guarantees that the start of the array is aligned to the
     specified number of bytes.
     */
    static void* alignedMalloc(size_t bytes, size_t alignment);

    /**
     Uses pooled storage to optimize small allocations (1 byte to 5 kilobytes).
     Can be 10x to 100x faster than calling ::malloc or new.

     The result must be freed with free.

     Threadsafe on Win32.

     @sa calloc realloc OutOfMemoryCallback free
     */
    static void* malloc(size_t bytes);

    static void* calloc(size_t n, size_t x);

    /**
     @param size Size of memory that the system was trying to allocate
     @param recoverable If true, the system will attempt to allocate again
            if the callback returns true.  If false, malloc is going to return
            NULL and this invocation is just to notify the application.
     @return Return true to force malloc to attempt allocation again if the
            error was recoverable.
     */
    typedef bool (*OutOfMemoryCallback)(size_t size, bool recoverable);

    /**
     When System::malloc fails to allocate memory because the system is
     out of memory, it invokes this handler (if it is not NULL).
     The argument to the callback is the amount of memory that malloc
     was trying to allocate when it ran out.  If the callback returns
     true, System::malloc will attempt to allocate the memory again.
     If the callback returns false, then System::malloc will return NULL.

     You can use outOfMemoryCallback to free data structures or to
     register the failure.
     */
    static OutOfMemoryCallback outOfMemoryCallback;

    /**
     Version of realloc that works with System::malloc.
     */
    static void* realloc(void* block, size_t bytes);

    /** Returns a string describing how well System::malloc is using its internal pooled storage.
        "heap" memory was slow to allocate; the other data sizes are comparatively fast.*/
    static std::string mallocPerformance();
    static void resetMallocPerformanceCounters();

    /**
       Returns a string describing the current usage of the buffer pools used for
       optimizing System::malloc.
     */
    static std::string mallocStatus();

    /**
     Free data allocated with System::malloc.

     Threadsafe on Win32.
     */
    static void free(void* p);

    /**
     Frees memory allocated with alignedMalloc.
     */
    static void alignedFree(void* ptr);

    /** An implementation of memcpy that may be up to 2x as fast as the C library
    one on some processors.  Guaranteed to have the same behavior as memcpy
    in all cases. */
    static void memcpy(void* dst, const void* src, size_t numBytes);

    /** An implementation of memset that may be up to 2x as fast as the C library
    one on some processors.  Guaranteed to have the same behavior as memset
    in all cases. */
    static void memset(void* dst, uint8 value, size_t numBytes);

};

} // namespace

#endif

