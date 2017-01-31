/**
 \file debug.h

 \maintainer Morgan McGuire, http://graphics.cs.williams.edu

 \created 2001-08-26
 \edited  2008-08-16

 Copyright 2000-2006, Morgan McGuire.
 All rights reserved.
*/

#ifndef G3D_debug_h
#define G3D_debug_h

#include "G3D/platform.h"
#ifdef _MSC_VER
    #include <crtdbg.h>
#endif

#include "G3D/debugPrintf.h"
#include "G3D/debugAssert.h"

namespace G3D {

#ifdef _MSC_VER
    // Turn off 64-bit warnings
#   pragma warning(push)
#   pragma warning( disable : 4312)
#   pragma warning( disable : 4267)
#   pragma warning( disable : 4311)
#endif


/**
 Useful for debugging purposes.
 */
inline bool isValidHeapPointer(const void* x) {
    #ifdef _MSC_VER
        return 
            (x != NULL) &&
            (x != (void*)0xcccccccc) && (x != (void*)0xdeadbeef) && (x != (void*)0xfeeefeee) &&
            (x != (void*)0xcdcdcdcd) && (x != (void*)0xabababab) && (x != (void*)0xfdfdfdfd);
    #else
        return x != NULL;
    #endif
}

/**
 Returns true if the pointer is likely to be
 a valid pointer (instead of an arbitrary number). 
 Useful for debugging purposes.
 */
inline bool isValidPointer(const void* x) {
    #ifdef _MSC_VER
        return (x != NULL) &&
            (x != (void*)0xcccccccc) && (x != (void*)0xdeadbeef) && (x != (void*)0xfeeefeee) &&
            (x != (void*)0xcdcdcdcd) && (x != (void*)0xabababab) && (x != (void*)0xfdfdfdfd);
    #else
        return x != NULL;
    #endif
}

#ifdef _MSC_VER
#   pragma warning(pop)
#endif

}

#endif
