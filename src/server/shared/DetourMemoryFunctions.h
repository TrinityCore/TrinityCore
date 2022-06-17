

#ifndef TRINITY_DETOUR_MEMORY_FUNCTIONS_H
#define TRINITY_DETOUR_MEMORY_FUNCTIONS_H

#include "DetourAlloc.h"

//  memory management
inline void* dtCustomAlloc(size_t size, dtAllocHint /*hint*/)
{
    return (void*)new unsigned char[size];
}

inline void dtCustomFree(void* ptr)
{
    delete [] (unsigned char*)ptr;
}

#endif // TRINITY_DETOUR_MEMORY_FUNCTIONS_H
