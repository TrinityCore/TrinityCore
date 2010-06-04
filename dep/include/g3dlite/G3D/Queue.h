/** 
  @file Queue.h
 
  @maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
  @created 2002-07-09
  @edited  2008-12-20
 */

#ifndef G3D_QUEUE_H
#define G3D_QUEUE_H

#include "G3D/platform.h"
#include "G3D/System.h"
#include "G3D/debug.h"

namespace G3D {

/**
 Locate the indices of the break between of the two 
 sections of the circular queue.  These are used to
 construct two for loops that iterate over the whole
 sequence without using the modulo operator.

   [0 ... secondEnd)   [head .... firstEnd)
 */
#define FIND_ENDS \
    int firstEnd  = head + num;\
    int secondEnd = 0;\
    if (firstEnd > numAllocated) {\
       secondEnd = firstEnd - numAllocated;\
       firstEnd  = numAllocated;\
    }


/**
 Dynamic queue that uses a circular buffer for performance.

 Faster than std::deque for objects with constructors.
 */
template <class T>
class Queue {
private:
    //                
    //             |<----  num  ---->|
    // [  |  |  |  |  |  |  |  |  |  |  |  |  |  ]
    //              ^ 
    //              |
    //             head
    //
    //

    /**
     Only num elements are initialized.
     */
    T*                  data;

    /**
     Index of the next element to be dequeue-d in data.
     */
    int                 head;

    /**
     Number of elements (including head) that are visible and initialized.
     */
    int                 num;
    
    /**
     Size of data array in elements.
     */
    int                 numAllocated;

    /** If a clear was needed, assumes it already occured */
    void _copy(const Queue& other) {
        debugAssert(data == NULL);
        data = (T*)System::malloc(sizeof(T) * other.numAllocated);
        debugAssert(data);
        head = other.head;
        num = other.num;
        numAllocated = other.numAllocated;

        FIND_ENDS;

        for (int i = head; i < firstEnd; ++i) {
            new (data + i)T(other.data[i]);
        }

        for (int i = 0; i < secondEnd; ++i) {
            new (data + i)T(other.data[i]);
        }
    }


    /**
     Computes a data array index from a queue position.  The queue position
     may be negative.
     */
    inline int index(int i) const {
        return (head + i + numAllocated) % numAllocated;
    }

    /**
     Allocates newSize elements and repacks the array.
     */
    void repackAndRealloc(int newSize) {
        // TODO: shrink queue
        T* old = data;
        data = (T*)System::malloc(newSize * sizeof(T));
        debugAssert(data != NULL);

        FIND_ENDS;

        int j = 0;
        for (int i = head; i < firstEnd; ++i, ++j) {
            new (data + j)T(old[i]);
            (old + i)->~T();
        }

        for (int i = 0; i < secondEnd; ++i, ++j) {
            new (data + j)T(old[i]);
            (old + i)->~T();
        }

        head = 0;
        System::free(old);
        numAllocated = newSize;
    }

    /**
      Ensure that there is at least one element between
      the tail and head, wrapping around in the circular
      buffer.
      */
    inline void reserveSpace() {
        if (num == numAllocated) {
            repackAndRealloc(numAllocated * 3 + 20);
        }
    }

public:

    Queue() : 
      data(NULL),
      head(0),
      num(0),
      numAllocated(0) {
    }


    /**
    Copy constructor
    */
    Queue(const Queue& other) : data(NULL) {
       _copy(other);
    }


   /**
    Destructor does not delete() the objects if T is a pointer type
    (e.g. T = int*) instead, it deletes the pointers themselves and 
    leaves the objects.  Call deleteAll if you want to dealocate
    the objects referenced.
    */
    virtual ~Queue() {
        clear();
    }

    /**
     Insert a new element into the front of the queue
     (a traditional queue only uses pushBack).
     */
    inline void pushFront(const T& e) {
        reserveSpace();

        // Get the index of head-1
        int i = index(-1);

        // Call the constructor on the newly exposed element.
        new (data + i)T(e);

        // Reassign the head to point to this index
        head = i;
        ++num;
    }

    /**
     Insert a new element at the end of the queue.
    */
    inline void pushBack(const T& e) {
        reserveSpace();

        // Get the index of 1+tail
        int i = index(num);

        // Initialize that element
        new (data + i)T(e);
        ++num;
    }

    /**
     pushBack
     */
    inline void enqueue(const T& e) {
        pushBack(e);
    }


    /**
     Remove the last element from the queue.  The queue will never
     shrink in size.  (A typical queue only uses popFront).
     */
    inline T popBack() {
        int tail = index(num - 1);
        T result(data[tail]);

        // Call the destructor
        (data + tail)->~T();
        --num;

        return result;
    }

    /**
    Remove the next element from the head of the queue.  The queue will never
    shrink in size. */
    inline T popFront() {
        T result(data[head]);
        // Call the destructor
        (data + head)->~T();
        head = (head + 1) % numAllocated;
        --num;
        return result;
    }


   /**
    popFront
    */
   inline T dequeue() {
       return popFront();
   }

   /**
    Removes all elements (invoking their destructors).

    @param freeStorage If false, the underlying array is not deallocated
    (allowing fast push in the future), however, the size of the Queue
    is reported as zero.
    
    */
   void clear(bool freeStorage = true) {

       FIND_ENDS;
       
       // Invoke the destructors on the elements
       int i;
       for (i = head; i < firstEnd; ++i) {
           (data + i)->~T();
       }

       for (i = 0; i < secondEnd; ++i) {
           (data + i)->~T();
       }
       
       num = 0;
       head = 0;
       if (freeStorage) {
           numAllocated = 0;
           System::free(data);
           data = NULL;
       }
   }

   /** Clear without freeing the underlying array. */
   void fastClear() {
       clear(false);
   }

   /**
    Assignment operator.
    */
   Queue& operator=(const Queue& other) {
       clear();
       _copy(other);
       return *this;
   }

   /**
    Number of elements in the queue.
    */
   inline int size() const {
      return num;
   }

   /**
    Number of elements in the queue.
    */
   inline int length() const {
      return size();
   }

   /**
    Performs bounds checks in debug mode
    */
   inline T& operator[](int n) {
      debugAssert((n >= 0) && (n < num));
      return data[index(n)];
   }

   /**
    Performs bounds checks in debug mode
    */
    inline const T& operator[](int n) const {
        debugAssert((n >= 0) && (n < num));
        return data[index(n)];
    }


    /** Returns the back element */
    inline const T& last() const {
        return (*this)[size() - 1];
    }

    inline T& last() {
        return (*this)[size() - 1];
    }

    /**
     Returns true if the given element is in the queue.
     */
    bool contains(const T& e) const {
        for (int i = 0; i < size(); ++i) {
            if ((*this)[i] == e) {
                return true;
            }
        }

        return false;
    }

   /**
    Calls delete on all objects[0...size-1]
    and sets the queue size to zero.
    */
    void deleteAll() {
        FIND_ENDS;
        
        int i;
    	for (i = 0; i < secondEnd; ++i) {
            delete data[i];
        }

        for (i = head; i < firstEnd; ++i) {
            delete data[i];
        }
        clear();
    }
};

#undef FIND_ENDS

}; // namespace

#endif
