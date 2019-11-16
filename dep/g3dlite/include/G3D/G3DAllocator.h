#ifndef G3D_G3DAllocator_h
#define G3D_G3DAllocator_h

#include "G3D/platform.h"
#include <limits>
#include <iostream>

namespace G3D {

namespace _internal {
    void* systemMalloc(size_t bytes);
    void systemFree(void* p);
} // _internal

/** \brief Maps the G3D default allocator (System::malloc) to an std::allocator 

 \cite Following an example from "The C++ Standard Library - A Tutorial and Reference" by Nicolai M. Josuttis, Addison-Wesley, 1999

*/
template <class T>
class G3DAllocator {
    public:
    // type definitions
    typedef T        value_type;
    typedef T*       pointer;
    typedef const T* const_pointer;
    typedef T&       reference;
    typedef const T& const_reference;
    typedef std::size_t    size_type;
    typedef std::ptrdiff_t difference_type;

    // rebind allocator to type U
    template <class U>
    struct rebind {
        typedef G3DAllocator<U> other;
    };

    // return address of values
    pointer address (reference value) const {
        return &value;
    }

    const_pointer address (const_reference value) const {
        return &value;
    }

    G3DAllocator() throw() {
    }

    G3DAllocator(const G3DAllocator&) throw() {
    }

    template <class U>
    G3DAllocator (const G3DAllocator<U>&) throw() {
    }

    ~G3DAllocator() throw() {
    }

    // return maximum number of elements that can be allocated
    size_type max_size () const throw() {
        return std::numeric_limits<std::size_t>::max() / sizeof(T);
    }

    // allocate but don't initialize num elements of type T
    pointer allocate (size_type num, const void* = 0) {
        //pointer ret = (pointer)(::operator new(num*sizeof(T)));
        // return ret;
        return (T*)_internal::systemMalloc(num * sizeof(T));
    }

    // initialize elements of allocated storage p with value value
    void construct (pointer p, const T& value) {
        // initialize memory with placement new
        new((void*)p)T(value);
    }

    // destroy elements of initialized storage p
    void destroy (pointer p) {
        // destroy objects by calling their destructor
        p->~T();
    }

    // deallocate storage p of deleted elements
    void deallocate (pointer p, size_type /*num*/) {
        //::operator delete((void*)p);
        _internal::systemFree(p);
    }
};

// All specializations of this allocator are interchangeable
template <class T1, class T2>
bool operator== (const G3DAllocator<T1>&,
                const G3DAllocator<T2>&) throw() {
    return true;
}

template <class T1, class T2>
bool operator!= (const G3DAllocator<T1>&,
                const G3DAllocator<T2>&) throw() {
    return false;
}

}



#endif
