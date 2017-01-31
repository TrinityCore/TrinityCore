/**
  \file G3D/ReferenceCount.h

  Reference Counting Garbage Collector for C++

  \maintainer Morgan McGuire, http://graphics.cs.williams.edu

  \created 2001-10-23
  \edited  2013-01-05
*/
#ifndef G3D_ReferenceCount_h
#define G3D_ReferenceCount_h

#include "G3D/platform.h"
#include "G3D/debug.h"
#include "G3D/AtomicInt32.h"

#define USE_SHARED_PTR

#define ReferenceCountedPointer shared_ptr
#define WeakReferenceCountedPointer weak_ptr
namespace G3D {

class ReferenceCountedObject : public enable_shared_from_this<ReferenceCountedObject> {
public:
    virtual ~ReferenceCountedObject() {};
};

} // namespace

namespace G3D {

template<class T>
bool isNull(const ReferenceCountedPointer<T>& ptr) {
    return ! ptr;
}

template<class T>
bool notNull(const ReferenceCountedPointer<T>& ptr) {
    return (bool)ptr;
}

template<class T>
bool isNull(const T* ptr) {
    return ptr == NULL;
}

template<class T>
bool notNull(const T* ptr) {
    return ptr != NULL;
}

} // namespace

#endif

