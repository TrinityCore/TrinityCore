/**
  @file ReferenceCount.h

  Reference Counting Garbage Collector for C++

  @maintainer Morgan McGuire, matrix@graphics3d.com
  @cite Adapted and extended from Justin Miller's "RGC" class that appeared in BYTE magazine.
  @cite See also http://www.jelovic.com/articles/cpp_without_memory_errors_slides.htm

  @created 2001-10-23
  @edited  2008-09-25
*/

#ifndef G3D_RGC_H
#define G3D_RGC_H

#include "G3D/platform.h"
#include "G3D/debug.h"
#include "G3D/AtomicInt32.h"

namespace G3D {

/** Base class for WeakReferenceCountedPointer */
class _WeakPtr {
public:
    inline virtual ~_WeakPtr() {}

protected:
    friend class ReferenceCountedObject;

    /** Called by ReferenceCountedObject to tell a weak pointer that its underlying object was collected. */
    virtual void objectCollected() = 0;
};

/** Used internally by ReferenceCountedObject */
class _WeakPtrLinkedList {
public:
    _WeakPtr*                   weakPtr;
    _WeakPtrLinkedList*         next;

    inline _WeakPtrLinkedList() : weakPtr(NULL), next(NULL) {}

    /** Inserts this node into the head of the list that previously had n as its head. */
    inline _WeakPtrLinkedList(_WeakPtr* p, _WeakPtrLinkedList* n) : weakPtr(p), next(n) {}
};

/**
 Objects that are reference counted inherit from this.  Subclasses 
 <B>must</B> have a public destructor (the default destructor is fine)
 and <B>publicly</B> inherit ReferenceCountedObject.

 Multiple inheritance from a reference counted object is dangerous-- use 
 at your own risk.

 ReferenceCountedPointer and ReferenceCountedObject are threadsafe.
 You can create and drop references on multiple threads without
 violating integrity.  WeakReferenceCountedPointer is <i>not</i>
 threadsafe.  Introducing a weak pointer destroys all thread safety,
 even for strong pointers to the same object (this is inherent in the
 design of the class; we cannot fix it without slowing down the
 performance of reference counted objects.)

 <B>Usage Example</B>

  <PRE>

class Foo : public G3D::ReferenceCountedObject {
public:
    int x;
};

class Bar : public Foo {};

typedef G3D::ReferenceCountedPointer<Foo> FooRef;
typedef G3D::WeakReferenceCountedPointer<Foo> WeakFooRef;
typedef G3D::ReferenceCountedPointer<Bar> BarRef;


int main(int argc, char *argv[]) {

    WeakFooRef x;

    {
        FooRef a = new Foo();

        // Reference count == 1

        x = a;
        // Weak references do not increase count

        {
            FooRef b = a;
            // Reference count == 2
        }

        // Reference count == 1
    }
    // No more strong references; object automatically deleted.
    // x is set to NULL automatically.

    // Example of using dynamic cast on reference counted objects
    BarRef b = new Bar();

    // No cast needed to go down the heirarchy.
    FooRef f = b;

    // We can't cast the reference object because it is a class.
    // Instead we must extract the pointer and cast that:
    b = dynamic_cast<Bar*>(&*f);

    return 0;
}
</PRE>

@deprecated To be replaced by boost::shared_ptr in 7.0
 */
class ReferenceCountedObject {
public:

    /**
     The long name is to keep this from accidentally conflicting with
     a subclass's variable name.  Do not use or explicitly manipulate
     this value--its type may change in the future and is not part
     of the supported API.
     */
    AtomicInt32                 ReferenceCountedObject_refCount;
 
    /**
     Linked list of all weak pointers that reference this (some may be
     on the stack!).  Do not use or explicitly manipulate this value.
     */
    _WeakPtrLinkedList*         ReferenceCountedObject_weakPointer;

protected:

    ReferenceCountedObject() : 
        ReferenceCountedObject_refCount(0), 
        ReferenceCountedObject_weakPointer(0) {

        debugAssertM(isValidHeapPointer(this), 
            "Reference counted objects must be allocated on the heap.");
    }

public:

    /** Automatically called immediately before the object is deleted. 
        This is not called from the destructor because it needs to be invoked
        before the subclass destructor.
      */
    void ReferenceCountedObject_zeroWeakPointers() {
        // Tell all of my weak pointers that I'm gone.
        
        _WeakPtrLinkedList* node = ReferenceCountedObject_weakPointer;

        while (node != 0) {

            // Notify the weak pointer that it is going away
            node->weakPtr->objectCollected();

            // Free the node and advance
            _WeakPtrLinkedList* tmp = node;
            node = node->next;
            delete tmp;
        }
    }

    virtual ~ReferenceCountedObject() {}


    /**
      Note: copies will initially start out with 0 
      references and 0 weak references like any other object.
     */
    ReferenceCountedObject(const ReferenceCountedObject& notUsed) : 
        ReferenceCountedObject_refCount(0),
        ReferenceCountedObject_weakPointer(0) {
        (void)notUsed;
        debugAssertM(G3D::isValidHeapPointer(this), 
            "Reference counted objects must be allocated on the heap.");
    }

    ReferenceCountedObject& operator=(const ReferenceCountedObject& other) {
        (void)other;
        // Nothing changes when I am assigned; the reference count on
        // both objects is the same (although my super-class probably
        // changes).
        return *this;
    }
};



/**
 Use ReferenceCountedPointer<T> in place of T* in your program.
 T must subclass ReferenceCountedObject.
@deprecated To be replaced by boost::shared_ptr in 7.0
 */
template <class T>
class ReferenceCountedPointer {
private:

    T*           m_pointer;

public:
    typedef T element_type;

    inline T* pointer() const {
        return m_pointer;
    }

private:

    /** Nulls out the pointer and drops a reference. If the reference
        count hits zero. */
    void zeroPointer() {
        if (m_pointer != NULL) {

            debugAssert(G3D::isValidHeapPointer(m_pointer));
            debugAssertM(m_pointer->ReferenceCountedObject_refCount.value() > 0,
                        "Dangling reference detected.");

            // Only delete if this instance caused the count to hit
            // exactly zero.  If there is a race condition, the value
            // may be zero after decrement returns, but only one of
            // the instances will get a zero return value.
            if (m_pointer->ReferenceCountedObject_refCount.decrement() == 0) {
                // We held the last reference, so delete the object.
                // This test is threadsafe because there is no way for
                // the reference count to increase after the last
                // reference was dropped (assuming the application does
                // not voilate the class abstraction).
                //debugPrintf("  delete 0x%x\n", m_pointer);

                // We must zero the weak pointers *before* deletion in case there
                // are cycles of weak references.
                // Note that since there are no strong references at this point,
                // it is perfectly fair to zero the weak pointers anyway.
                m_pointer->ReferenceCountedObject_zeroWeakPointers();
                delete m_pointer;
            }

            m_pointer = NULL;
        }
    }

    /** Non-atomic (except for the referencec increment).  Can only be
        called in contexts like the copy constructor or initial
        constructor where it is known that the reference count will
        not hit zero on some other thread. */
    void setPointer(T* x) {
        if (x != m_pointer) {
            zeroPointer();

            if (x != NULL) {
                debugAssert(G3D::isValidHeapPointer(x));

		        m_pointer = x;

                // Note that the ref count can be zero if this is the
                // first pointer to it
                debugAssertM(m_pointer->ReferenceCountedObject_refCount.value() >= 0, 
                             "Negative reference count detected.");
                m_pointer->ReferenceCountedObject_refCount.increment();
            }
        }
    }

public:      

    inline ReferenceCountedPointer() : m_pointer(NULL) {}

    /**
      Allow silent cast <i>to</i> the base class.
    
      <pre>
        SubRef  s = new Sub();
        BaseRef b = s;
      </pre>

      i.e., compile-time subtyping rule 
      RCP&lt;<I>T</I>&gt; &lt;: RCP&lt;<I>S</I>&gt; if <I>T</I> &lt;: <I>S</I>
     */
    template <class S>
    inline ReferenceCountedPointer(const ReferenceCountedPointer<S>& p) : 
        m_pointer(NULL) {
        setPointer(p.pointer());
    }

#   if (! defined(MSC_VER) || (MSC_VER >= 1300))
    /**
      Explicit cast to a subclass.  Acts like dynamic cast; the result will be NULL if
      the cast cannot succeed.  Not supported on VC6.
      <pre>
        SubRef  s = new Sub();
        BaseRef b = s;
        s = b.downcast<Sub>();   // Note that the template argument is the object type, not the pointer type.
      </pre>
      */
    template <class S>
    ReferenceCountedPointer<S> downcast() {
        return ReferenceCountedPointer<S>(dynamic_cast<S*>(m_pointer));
    }

    template <class S>
    const ReferenceCountedPointer<S> downcast() const {
        return ReferenceCountedPointer<S>(dynamic_cast<const S*>(m_pointer));
    }
#   endif

    // We need an explicit version of the copy constructor as well or 
    // the default copy constructor will be used.
    inline ReferenceCountedPointer(const ReferenceCountedPointer<T>& p) : m_pointer(NULL) {
        setPointer(p.m_pointer);
    }

    /** Allows construction from a raw pointer.  That object will thereafter be
        reference counted -- do not call delete on it. */
    inline ReferenceCountedPointer(T* p) : m_pointer(NULL) { 
        setPointer(p); 
    }
    
    inline ~ReferenceCountedPointer() {
        zeroPointer();
    }
  
    inline size_t hashCode() const {
        return reinterpret_cast<size_t>(m_pointer);;
    }

    inline const ReferenceCountedPointer<T>& operator=(const ReferenceCountedPointer<T>& p) {
        setPointer(p.m_pointer);
        return *this;
    }

    inline ReferenceCountedPointer<T>& operator=(T* p) {
        setPointer(p);
        return *this;
    }

    inline bool operator==(const ReferenceCountedPointer<T>& y) const { 
        return (m_pointer == y.m_pointer); 
    }

    inline bool operator!=(const ReferenceCountedPointer<T>& y) const { 
        return (m_pointer != y.m_pointer); 
    }

    bool operator < (const ReferenceCountedPointer<T>& y) const {
        return (m_pointer < y.m_pointer); 
    }
    
    bool operator > (const ReferenceCountedPointer<T>& y) const {
        return (m_pointer > y.m_pointer); 
    }
    
    bool operator <= (const ReferenceCountedPointer<T>& y) const {
        return (m_pointer <= y.m_pointer); 
    }
    
    bool operator >= (const ReferenceCountedPointer<T>& y) const {
        return (m_pointer >= y.m_pointer); 
    }
    
    inline T& operator*() const {
        debugAssertM(m_pointer != NULL, "Dereferenced a NULL ReferenceCountedPointer");
        return (*m_pointer);
    }

    inline T* operator->() const {
        debugAssertM(m_pointer != NULL, "Dereferenced a NULL ReferenceCountedPointer");
        return m_pointer;
    }

    inline bool isNull() const {
        return (m_pointer == NULL);
    }

    inline bool notNull() const {
        return (m_pointer != NULL);
    }

    // TODO: distinguish between last strong and last any pointer
    /**
     Returns true if this is the last reference to an object.
     Useful for flushing memoization caches-- a cache that holds the last
     reference is unnecessarily keeping an object alive.

     <b>Not threadsafe.</b>

     @deprecated Use WeakReferenceCountedPointer for caches
     */
    inline int isLastReference() const {
        return (m_pointer->ReferenceCountedObject_refCount.value() == 1);
    }
};


/**
 A weak pointer allows the object it references to be garbage collected.
 Weak pointers are commonly used in caches, where it is important to hold
 a pointer to an object without keeping that object alive solely for the
 cache's benefit (i.e., the object can be collected as soon as all
 pointers to it <B>outside</B> the cache are gone).  They are also convenient
 for adding back-pointers in tree and list structures.

 Weak pointers may become NULL at any point (when their target is collected).
 Therefore the only way to reference the target is to convert to a strong
 pointer and then check that it is not NULL.

@deprecated To be replaced by boost::weak_ptr in 7.0
 */
template <class T>
class WeakReferenceCountedPointer : public _WeakPtr {
private:

    /** NULL if the object has been collected. */
    T*          pointer;

public:
    /**
      Creates a strong pointer, which prevents the object from being
      garbage collected.  The strong pointer may be NULL, which means
      that the underlying.
      */
    //  There is intentionally no way to check if the
    //  WeakReferenceCountedPointer has a null reference without
    //  creating a strong pointer since there is no safe way to use
    //  that information-- the pointer could be collected by a
    //  subsequent statement.
    ReferenceCountedPointer<T> createStrongPtr() const {
        // TODO: What if the object's destructor is called while we
        // are in this method?
        return ReferenceCountedPointer<T>(pointer);
    }


private:

    /** 
        Thread issues: safe because this is only called when another
        object is guaranteed to keep p alive for the duration of this
        call.
     */
    void setPointer(T* p) {
        // TODO: must prevent the object from being collected while in
        // this method

        zeroPointer();
        pointer = p;

        if (pointer != 0) {
            // TODO: threadsafe: must update the list atomically

            // Add myself to the head of my target's list of weak pointers
            _WeakPtrLinkedList* head = 
                new _WeakPtrLinkedList
                (this, 
                 pointer->ReferenceCountedObject_weakPointer);

            pointer->ReferenceCountedObject_weakPointer = head;
        } else {

        }
    }


    /** 
        Removes this from its target's list of weak pointers.  Called
        when the weak pointer goes out of scope.

        Thread issues: depends on the thread safety of createStrongPtr.
     */
    void zeroPointer() {
        // Grab a strong reference to prevent the object from being collected while we
        // are traversing its list.
        ReferenceCountedPointer<T> strong = createStrongPtr();

        // If the following test fails then the object was collected before we
        // reached it.
        if (strong.notNull()) {
            debugAssertM(pointer->ReferenceCountedObject_weakPointer != NULL,
                "Weak pointer exists without a backpointer from the object.");
            
            // Remove myself from my target's list of weak pointers
            _WeakPtrLinkedList** node = &pointer->ReferenceCountedObject_weakPointer;
            while ((*node)->weakPtr != this) {
                node = &((*node)->next);
                debugAssertM(*node != NULL, 
                    "Weak pointer exists without a backpointer from the object (2).");
            }

            // Node must now point at the node for me.  Remove node and
            // close the linked list behind it.
            _WeakPtrLinkedList* temp = *node;
            *node = temp->next;
            
            // Now delete the node corresponding to me
            delete temp;
        }

        pointer = NULL;
    }

public:

    WeakReferenceCountedPointer() : pointer(0) {}

    /**
      Allow compile time subtyping rule 
      RCP&lt;<I>T</I>&gt; &lt;: RCP&lt;<I>S</I>&gt; if <I>T</I> &lt;: <I>S</I>
     */
    template <class S>
    inline WeakReferenceCountedPointer(const WeakReferenceCountedPointer<S>& p) : pointer(0) {
        // Threadsafe: the object cannot be collected while the other pointer exists.
        setPointer(p.pointer);
    }

    template <class S>
    inline WeakReferenceCountedPointer(const ReferenceCountedPointer<S>& p) : pointer(0) {
        // Threadsafe: the object cannot be collected while the other
        // pointer exists.
        setPointer(p.pointer());
    }

    // Gets called a *lot* when weak pointers are on the stack
    WeakReferenceCountedPointer(
        const WeakReferenceCountedPointer<T>& weakPtr) : pointer(0) {
        setPointer(weakPtr.pointer);
    }

    WeakReferenceCountedPointer(
        const ReferenceCountedPointer<T>& strongPtr) : pointer(0) {
        setPointer(strongPtr.pointer());
    }

    ~WeakReferenceCountedPointer() {
        zeroPointer();
    }

    WeakReferenceCountedPointer<T>& operator=(const WeakReferenceCountedPointer<T>& other) {
        // Threadsafe: the object cannot be collected while the other pointer exists.

        // I now point at other's target
        setPointer(other.pointer);

        return *this;
    }

    WeakReferenceCountedPointer<T>& operator=(const ReferenceCountedPointer<T>& other) {

        // Threadsafe: the object cannot be collected while the other pointer exists.

        // I now point at other's target
        setPointer(other.pointer());

        return *this;
    }

    bool operator==(const WeakReferenceCountedPointer<T>& other) const {
        return pointer == other.pointer;
    }

    bool operator!=(const WeakReferenceCountedPointer<T>& other) const {
        return pointer != other.pointer;
    }

    bool operator < (const WeakReferenceCountedPointer<T>& y) const {
        return (pointer < y.pointer); 
    }

    bool operator > (const WeakReferenceCountedPointer<T>& y) const {
        return (pointer > y.pointer); 
    }
    
    bool operator <= (const WeakReferenceCountedPointer<T>& y) const {
        return (pointer <= y.pointer); 
    }
    
    bool operator >= (const ReferenceCountedPointer<T>& y) const {
        return (pointer >= y.pointer); 
    }
    
protected:

    /** Invoked by the destructor on ReferenceCountedPointer. */
    virtual void objectCollected() {
        debugAssertM(pointer != NULL,
                     "Removed a weak pointer twice.");
        pointer = NULL;
    }

};

} // namespace

#endif

