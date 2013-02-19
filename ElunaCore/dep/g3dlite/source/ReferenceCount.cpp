/**
  @file ReferenceCount.cpp

  Reference Counting Garbage Collector for C++

  @maintainer Morgan McGuire, http://graphics.cs.williams.edu
  @cite Adapted and extended from Justin Miller's "RGC" class that appeared in BYTE magazine.
  @cite See also http://www.jelovic.com/articles/cpp_without_memory_errors_slides.htm

  @created 2001-10-23
  @edited  2009-04-25
*/
#include "G3D/platform.h"
#include "G3D/ReferenceCount.h"

namespace G3D {

ReferenceCountedObject::ReferenceCountedObject() : 
    ReferenceCountedObject_refCount(0), 
    ReferenceCountedObject_weakPointer(0) {

    debugAssertM(isValidHeapPointer(this), 
        "Reference counted objects must be allocated on the heap.");
}

void ReferenceCountedObject::ReferenceCountedObject_zeroWeakPointers() {
    // Tell all of my weak pointers that I'm gone.
    
    _WeakPtrLinkedList* node = ReferenceCountedObject_weakPointer;

    while (node != NULL) {
        // Notify the weak pointer that it is going away
        node->weakPtr->objectCollected();

        // Free the node and advance
        _WeakPtrLinkedList* tmp = node;
        node = node->next;
        delete tmp;
    }
}

ReferenceCountedObject::~ReferenceCountedObject() {}


ReferenceCountedObject::ReferenceCountedObject(const ReferenceCountedObject& notUsed) : 
    ReferenceCountedObject_refCount(0),
    ReferenceCountedObject_weakPointer(0) {
    (void)notUsed;
    debugAssertM(G3D::isValidHeapPointer(this), 
        "Reference counted objects must be allocated on the heap.");
}

ReferenceCountedObject& ReferenceCountedObject::operator=(const ReferenceCountedObject& other) {
    (void)other;
    // Nothing changes when I am assigned; the reference count on
    // both objects is the same (although my super-class probably
    // changes).
    return *this;
}

} // G3D
