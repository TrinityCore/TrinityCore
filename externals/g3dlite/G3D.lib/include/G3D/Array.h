/** 
  @file Array.h
 
  @maintainer Morgan McGuire, graphics3d.com
  @cite Portions written by Aaron Orenstein, a@orenstein.name
 
  @created 2001-03-11
  @edited  2008-07-09

  Copyright 2000-2008, Morgan McGuire, morgan@cs.williams.edu
  All rights reserved.
 */

#ifndef G3D_ARRAY_H
#define G3D_ARRAY_H

#include "G3D/platform.h"
#include "G3D/debug.h"
#include "G3D/System.h"
#ifdef G3D_DEBUG
//   For formatting error messages
#    include "G3D/format.h"
#endif
#include <vector>
#include <algorithm>

#ifdef _MSC_VER
#   include <new>
    
#   pragma warning (push)
    // debug information too long
#   pragma warning( disable : 4312)
#   pragma warning( disable : 4786)
#endif


namespace G3D {

/**
 Constant for passing to Array::resize
 */
const bool DONT_SHRINK_UNDERLYING_ARRAY = false;

/** Constant for Array::sort */
const int SORT_INCREASING = 1;
/** Constant for Array::sort */
const int SORT_DECREASING = -1;

/**
 Dynamic 1D array.  

 Objects must have a default constructor (constructor that
 takes no arguments) in order to be used with this template.
 You will get the error "no appropriate default constructor found"
 if they do not.

 Do not use with objects that overload placement <code>operator new</code>,
 since the speed of Array is partly due to pooled allocation.

 If SSE is defined Arrays allocate the first element aligned to
 16 bytes.


 Array is highly optimized compared to std::vector.  
 Array operations are less expensive than on std::vector and for large
 amounts of data, Array consumes only 1.5x the total size of the 
 data, while std::vector consumes 2.0x.  The default
 array takes up zero heap space.  The first resize (or append)
 operation grows it to a reasonable internal size so it is efficient
 to append to small arrays.  Memory is allocated using
 System::alignedMalloc, which produces pointers aligned to 16-byte
 boundaries for use with SSE instructions and uses pooled storage for
 fast allocation.  When Array needs to copy
 data internally on a resize operation it correctly invokes copy
 constructors of the elements (the MSVC6 implementation of
 std::vector uses realloc, which can create memory leaks for classes
 containing references and pointers).  Array provides a guaranteed
 safe way to access the underlying data as a flat C array --
 Array::getCArray.  Although (T*)std::vector::begin() can be used for
 this purpose, it is not guaranteed to succeed on all platforms.

 To serialize an array, see G3D::serialize.

 The template parameter MIN_ELEMENTS indicates the smallest number of 
 elements that will be allocated.  The default of 10 is designed to avoid 
 the overhead of repeatedly allocating the array as it grows from 1, to 2, and so on.
 If you are creating a lot of small Arrays, however, you may want to set this smaller
 to reduce the memory cost. Once the array has been allocated, it will never
 deallocate the underlying array unless MIN_ELEMENTS is set to 0, MIN_BYTES is 0, and the array
 is empty.

 Do not subclass an Array.
 */
template <class T, int MIN_ELEMENTS = 10, size_t MIN_BYTES = 32>
class Array {
private:
    /** 0...num-1 are initialized elements, num...numAllocated-1 are not */
    T*              data;

    int             num;
    int             numAllocated;

    void init(int n, int a) {
        debugAssert(n <= a);
        debugAssert(n >= 0);
        this->num = 0;
        this->numAllocated = 0;
        data = NULL;
        if (a > 0) {
            resize(n);
        } else {
            data = NULL;
        }
    }

    void _copy(const Array &other) {
        init(other.num, other.num);
        for (int i = 0; i < num; i++) {
            data[i] = other.data[i];
        }
    }

    /**
     Returns true iff address points to an element of this array.
     Used by append.
     */
    inline bool inArray(const T* address) {
        return (address >= data) && (address < data + num);
    }


    /** Only compiled if you use the sort procedure. */
    static bool __cdecl compareGT(const T& a, const T& b) {
        return a > b;
    }


    /**
     Allocates a new array of size numAllocated (not a parameter to the method) 
     and then copies at most oldNum elements from the old array to it.  Destructors are
     called for oldNum elements of the old array.
     */
    void realloc(int oldNum) {
         T* oldData = data;
         
         // The allocation is separate from the constructor invocation because we don't want 
         // to pay for the cost of constructors until the newly allocated
         // elements are actually revealed to the application.  They 
         // will be constructed in the resize() method.

         data = (T*)System::alignedMalloc(sizeof(T) * numAllocated, 16);

         // Call the copy constructors
         {const int N = G3D::min(oldNum, numAllocated);
          const T* end = data + N;
          T* oldPtr = oldData;
          for (T* ptr = data; ptr < end; ++ptr, ++oldPtr) {

             // Use placement new to invoke the constructor at the location
             // that we determined.  Use the copy constructor to make the assignment.
             const T* constructed = new (ptr) T(*oldPtr);

             (void)constructed;
             debugAssertM(constructed == ptr, 
                 "new returned a different address than the one provided by Array.");
         }}

         // Call destructors on the old array (if there is no destructor, this will compile away)
         {const T* end = oldData + oldNum;
          for (T* ptr = oldData; ptr < end; ++ptr) {
              ptr->~T();
         }}


         System::alignedFree(oldData);
    }

public:

    /**
     G3D C++ STL style iterator variable.  Call begin() to get 
     the first iterator, pre-increment (++i) the iterator to get to
     the next value.  Use dereference (*i) to access the element.
     */
    typedef T* Iterator;
    /** G3D C++ STL style const iterator in same style as Iterator. */
    typedef const T* ConstIterator;

    /** stl porting compatibility helper */
    typedef Iterator iterator;
    /** stl porting compatibility helper */
    typedef ConstIterator const_iterator;
    /** stl porting compatibility helper */
    typedef T value_type;
    /** stl porting compatibility helper */
    typedef int size_type;
    /** stl porting compatibility helper */
    typedef int difference_type;

    /**
     C++ STL style iterator method.  Returns the first iterator element.
     Do not change the size of the array while iterating.
     */
    Iterator begin() {
        return data;
    }

    ConstIterator begin() const {
        return data;
    }
    /**
     C++ STL style iterator method.  Returns one after the last iterator
     element.
     */
    ConstIterator end() const {
        return data + num;
    }

    Iterator end() {
        return data + num;
    }

   /**
    The array returned is only valid until the next append() or resize call, or 
	the Array is deallocated.
    */
   T* getCArray() {
       return data;
   }

   /**
    The array returned is only valid until the next append() or resize call, or 
	the Array is deallocated.
    */
   const T* getCArray() const {
       return data;
   }

   /** Creates a zero length array (no heap allocation occurs until resize). */
   Array() {
       init(0, 0);
   }

   /**
    Creates an array of size.
    */
   Array(int size) {
       init(size, size);
   }

   /**
    Copy constructor
    */
   Array(const Array& other) {
       _copy(other);
   }

   /**
    Destructor does not delete() the objects if T is a pointer type
    (e.g. T = int*) instead, it deletes the <B>pointers themselves</B> and 
    leaves the objects.  Call deleteAll if you want to dealocate
    the objects referenced.  Do not call deleteAll if <CODE>T</CODE> is not a pointer
    type (e.g. do call Array<Foo*>::deleteAll, do <B>not</B> call Array<Foo>::deleteAll).
    */
   ~Array() {
       // Invoke the destructors on the elements
       for (int i = 0; i < num; i++) {
           (data + i)->~T();
       }
       
       System::alignedFree(data);
       // Set to 0 in case this Array is global and gets referenced during app exit
       data = NULL;
	   num = 0;
       numAllocated = 0;
   }


   /**
    Removes all elements.  Use resize(0, false) or fastClear if you want to 
    remove all elements without deallocating the underlying array
    so that future append() calls will be faster.
    */
   void clear(bool shrink = true) {
       resize(0, shrink);
   }

   /** resize(0, false) 
      @deprecated*/
   void fastClear() {
       clear(false);
   }

   /**
    Assignment operator.
    */
   Array& operator=(const Array& other) {
       resize(other.num);
       for (int i = 0; i < num; ++i) {
           data[i] = other[i];
       }
       return *this;
   }

   Array& operator=(const std::vector<T>& other) {
       resize((int)other.size());
       for (int i = 0; i < num; ++i) {
           data[i] = other[i];
       }
       return *this;
   }

   /**
    Number of elements in the array.
    */
   inline int size() const {
      return num;
   }

   /**
    Number of elements in the array.  (Same as size; this is just
    here for convenience).
    */
   inline int length() const {
      return size();
   }

   /**
    Swaps element index with the last element in the array then
    shrinks the array by one.
    */
   void fastRemove(int index, bool shrinkIfNecessary = false) {
       debugAssert(index >= 0);
       debugAssert(index < num);
       data[index] = data[num - 1];
       resize(size() - 1, shrinkIfNecessary);
   }

   /** Resizes without shrinking the underlying array. Same as resize(n, false).
       @deprecated*/
   void fastResize(int n) {
      resize(n, false);
   }


   /**
    Inserts at the specified index and shifts all other elements up by one.
    */
   void insert(int n, const T& value) {
       // Add space for the extra element
       resize(num + 1, false);

       for (int i = num - 1; i > n; --i) {
           data[i] = data[i - 1];
       }
       data[n] = value;
   }

    /** @param shrinkIfNecessary if false, memory will never be
      reallocated when the array shrinks.  This makes resizing much
      faster but can waste memory. */
   void resize(int n, bool shrinkIfNecessary = true) {
      int oldNum = num;
      num = n;

      // Call the destructors on newly hidden elements if there are any
      for (int i = num; i < oldNum; ++i) {
          (data + i)->~T();
      }

      // Once allocated, always maintain MIN_ELEMENTS elements or 32 bytes, whichever is higher.
      static const int minSize = G3D::max(MIN_ELEMENTS, (int)(MIN_BYTES / sizeof(T)));

      if ((MIN_ELEMENTS == 0) && (MIN_BYTES == 0) && (n == 0) && shrinkIfNecessary) {
          // Deallocate the array completely
          numAllocated = 0;
          System::alignedFree(data);
          data = NULL;
          return;
      }

      if (num > numAllocated) {
          // Grow the underlying array

          if (numAllocated == 0) {
              // First allocation; grow to exactly the size requested to avoid wasting space.
              numAllocated = n;
              debugAssert(oldNum == 0);
              realloc(oldNum);
          } else {
         
              if (num < minSize) {
                  // Grow to at least the minimum size
                  numAllocated = minSize;

              } else {

                  // Increase the underlying size of the array.  Grow aggressively
                  // up to 64k, less aggressively up to 400k, and then grow relatively
                  // slowly (1.5x per resize) to avoid excessive space consumption.
                  //
                  // These numbers are tweaked according to performance tests.

                  float growFactor = 3.0;

                  size_t oldSizeBytes = numAllocated * sizeof(T);
                  if (oldSizeBytes > 400000) {
                      // Avoid bloat
                      growFactor = 1.5;
                  } else if (oldSizeBytes > 64000) {
                      // This is what std:: uses at all times
                      growFactor = 2.0;
                  }

                  numAllocated = (num - numAllocated) + (int)(numAllocated * growFactor);

                  if (numAllocated < minSize) {
                      numAllocated = minSize;
                  }
              }

              realloc(oldNum);
          }

      } else if ((num <= numAllocated / 3) && shrinkIfNecessary && (num > minSize)) {
          // Shrink the underlying array

          // Only copy over old elements that still remain after resizing
          // (destructors were called for others if we're shrinking)
          realloc(iMin(num, oldNum));

      }

      // Call the constructors on newly revealed elements.
      // Do not use parens because we don't want the intializer
      // invoked for POD types.
      for (int i = oldNum; i < num; ++i) {
          new (data + i) T;
      }
   }

    /**
     Add an element to the end of the array.  Will not shrink the underlying array
     under any circumstances.  It is safe to append an element that is already
     in the array.
     */
    inline void append(const T& value) {
        
        if (num < numAllocated) {
            // This is a simple situation; just stick it in the next free slot using
            // the copy constructor.
            new (data + num) T(value);
            ++num;
        } else if (inArray(&value)) {
            // The value was in the original array; resizing
            // is dangerous because it may move the value
            // we have a reference to.
            T tmp = value;
            append(tmp);
        } else {
            // Here we run the empty initializer where we don't have to, but
            // this simplifies the computation.
            resize(num + 1, DONT_SHRINK_UNDERLYING_ARRAY);
            data[num - 1] = value;
        }
    }


    inline void append(const T& v1, const T& v2) {
        if (inArray(&v1) || inArray(&v2)) {
            // Copy into temporaries so that the references won't break when
            // the array resizes.
            T t1 = v1;
            T t2 = v2;
            append(t1, t2);
        } else if (num + 1 < numAllocated) {
            // This is a simple situation; just stick it in the next free slot using
            // the copy constructor.
            new (data + num) T(v1);
            new (data + num + 1) T(v2);
            num += 2;
        } else {
            // Resize the array.  Note that neither value is already in the array.
            resize(num + 2, DONT_SHRINK_UNDERLYING_ARRAY);
            data[num - 2] = v1;
            data[num - 1] = v2;
        }
    }


    inline void append(const T& v1, const T& v2, const T& v3) {
        if (inArray(&v1) || inArray(&v2) || inArray(&v3)) {
            T t1 = v1;
            T t2 = v2;
            T t3 = v3;
            append(t1, t2, t3);
        } else if (num + 2 < numAllocated) {
            // This is a simple situation; just stick it in the next free slot using
            // the copy constructor.
            new (data + num) T(v1);
            new (data + num + 1) T(v2);
            new (data + num + 2) T(v3);
            num += 3;
        } else {
            resize(num + 3, DONT_SHRINK_UNDERLYING_ARRAY);
            data[num - 3] = v1;
            data[num - 2] = v2;
            data[num - 1] = v3;
        }
    }


    inline void append(const T& v1, const T& v2, const T& v3, const T& v4) {
        if (inArray(&v1) || inArray(&v2) || inArray(&v3) || inArray(&v4)) {
            T t1 = v1;
            T t2 = v2;
            T t3 = v3;
            T t4 = v4;
            append(t1, t2, t3, t4);
        } else if (num + 3 < numAllocated) {
            // This is a simple situation; just stick it in the next free slot using
            // the copy constructor.
            new (data + num) T(v1);
            new (data + num + 1) T(v2);
            new (data + num + 2) T(v3);
            new (data + num + 3) T(v4);
            num += 4;
        } else {
            resize(num + 4, DONT_SHRINK_UNDERLYING_ARRAY);
            data[num - 4] = v1;
            data[num - 3] = v2;
            data[num - 2] = v3;
            data[num - 1] = v4;
        }
    }

    /**
     Returns true if the given element is in the array.
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
    Append the elements of array.  Cannot be called with this array
    as an argument.
    */
   void append(const Array<T>& array) {
       debugAssert(this != &array);
       int oldNum = num;
       int arrayLength = array.length();

       resize(num + arrayLength, false);

       for (int i = 0; i < arrayLength; i++) {
           data[oldNum + i] = array.data[i];
       }
   }

   /**
    Pushes a new element onto the end and returns its address.
    This is the same as A.resize(A.size() + 1, false); A.last()
    */
   inline T& next() {
       resize(num + 1, false);
       return last();
   }

   /**
    Pushes an element onto the end (appends)
    */
   inline void push(const T& value) {
       append(value);
   }

   inline void push(const Array<T>& array) {
       append(array);
   }

   /** Alias to provide std::vector compatibility */
   inline void push_back(const T& v) {
       push(v);
   }

   /** "The member function removes the last element of the controlled sequence, which must be non-empty."
        For compatibility with std::vector. */
   inline void pop_back() {
       pop();
   }

   /** 
      "The member function returns the storage currently allocated to hold the controlled
       sequence, a value at least as large as size()" 
       For compatibility with std::vector.
   */
   int capacity() const {
       return numAllocated;
   }

   /** 
      "The member function returns a reference to the first element of the controlled sequence, 
       which must be non-empty." 
       For compatibility with std::vector.
   */
   T& front() {
       return (*this)[0];
   }

   /** 
      "The member function returns a reference to the first element of the controlled sequence, 
       which must be non-empty." 
       For compatibility with std::vector.
   */
   const T& front() const {
       return (*this)[0];
   }

   /**
    Removes the last element and returns it.  By default, shrinks the underlying array.
    */
   inline T pop(bool shrinkUnderlyingArrayIfNecessary = true) {
       debugAssert(num > 0);
       T temp = data[num - 1];
       resize(num - 1, shrinkUnderlyingArrayIfNecessary);
       return temp;
   }

   /** Pops the last element and discards it without returning anything.  Faster than pop.
      By default, does not shrink the underlying array.*/
   inline void popDiscard(bool shrinkUnderlyingArrayIfNecessary = false) {
       debugAssert(num > 0);
       resize(num - 1, shrinkUnderlyingArrayIfNecessary);
   }


   /**
    "The member function swaps the controlled sequences between *this and str."
    Note that this is slower than the optimal std implementation.

    For compatibility with std::vector.
    */
   void swap(Array<T>& str) {
       Array<T> temp = str;
       str = *this;
       *this = temp;
   }


   /**
    Performs bounds checks in debug mode
    */
   inline T& operator[](int n) {
        debugAssertM((n >= 0) && (n < num), format("Array index out of bounds. n = %d, size() = %d", n, num));
        debugAssert(data!=NULL);
        return data[n];
   }

   inline T& operator[](unsigned int n) {
        debugAssertM(n < (unsigned int)num, format("Array index out of bounds. n = %d, size() = %d", n, num));
        return data[n];
   }

   /**
    Performs bounds checks in debug mode
    */
    inline const T& operator[](int n) const {
        debugAssert((n >= 0) && (n < num));
        debugAssert(data!=NULL);
        return data[n];
    }

    inline const T& operator[](unsigned int n) const {
        debugAssert((n < (unsigned int)num));
        debugAssert(data!=NULL);
        return data[n];
    }

    inline T& randomElement() {
        debugAssert(num > 0);
        debugAssert(data!=NULL);
        return data[iRandom(0, num - 1)];
    }

    inline const T& randomElement() const {
        debugAssert(num > 0);
        debugAssert(data!=NULL);
        return data[iRandom(0, num - 1)];
    }

    /**
    Returns the last element, performing a check in
    debug mode that there is at least one element.
    */
    inline const T& last() const {
        debugAssert(num > 0);
        debugAssert(data!=NULL);
        return data[num - 1];
    }

    /** Returns element lastIndex() */
    inline T& last() {
        debugAssert(num > 0);
        debugAssert(data!=NULL);
        return data[num - 1];
    }

    /** Returns <i>size() - 1</i> */
    inline int lastIndex() const {
        debugAssertM(num > 0, "Array is empty");
        return num - 1;
    }

    inline int firstIndex() const {
        debugAssertM(num > 0, "Array is empty");
        return 0;
    }

    /** Returns element firstIndex(), performing a check in debug mode to ensure that there is at least one */
    inline T& first() {
        debugAssertM(num > 0, "Array is empty");
        return data[0];
    }

    inline const T& first() const {
        debugAssertM(num > 0, "Array is empty");
        return data[0];
    }

    /** Returns iFloor(size() / 2), throws an assertion in debug mode if the array is empty */
    inline int middleIndex() const {
        debugAssertM(num > 0, "Array is empty");
        return num >> 1;
    }

    /** Returns element middleIndex() */
    inline const T& middle() const {
        debugAssertM(num > 0, "Array is empty");
        return data[num >> 1];   
    }

    /** Returns element middleIndex() */
    inline T& middle() {
        debugAssertM(num > 0, "Array is empty");
        return data[num >> 1];   
    }

    /**
    Calls delete on all objects[0...size-1]
    and sets the size to zero.
    */
    void deleteAll() {
        for (int i = 0; i < num; i++) {
            delete data[i];
        }
        resize(0);
    }

    /**
     Returns the index of (the first occurance of) an index or -1 if
     not found.
     */
    int findIndex(const T& value) const {
        for (int i = 0; i < num; ++i) {
            if (data[i] == value) {
                return i;
            }
        }
        return -1;
    }

    /**
     Finds an element and returns the iterator to it.  If the element
     isn't found then returns end().
     */
    Iterator find(const T& value) {
        for (int i = 0; i < num; ++i) {
            if (data[i] == value) {
                return data + i;
            }
        }
        return end();
    }

    ConstIterator find(const T& value) const {
        for (int i = 0; i < num; ++i) {
            if (data[i] == value) {
                return data + i;
            }
        }
        return end();
    }

    /**
     Removes count elements from the array
     referenced either by index or Iterator.
     */
    void remove(Iterator element, int count = 1) {
        debugAssert((element >= begin()) && (element < end()));
        debugAssert((count > 0) && (element + count) <= end());
        Iterator last = end() - count;

        while(element < last) {
            element[0] = element[count];
            ++element;
        }
        
        resize(num - count);
    }

    void remove(int index, int count = 1) {
        debugAssert((index >= 0) && (index < num));
        debugAssert((count > 0) && (index + count <= num));
        
        remove(begin() + index, count);
    }

    /**
     Reverse the elements of the array in place.
     */
    void reverse() {
        T temp;
        
        int n2 = num / 2;
        for (int i = 0; i < n2; ++i) {
            temp = data[num - 1 - i];
            data[num - 1 - i] = data[i];
            data[i] = temp;
        }
    }

    /**
     Sort using a specific less-than function, e.g.:

  <PRE>
    bool __cdecl myLT(const MyClass& elem1, const MyClass& elem2) {
        return elem1.x < elem2.x;
    }
    </PRE>

  Note that for pointer arrays, the <CODE>const</CODE> must come 
  <I>after</I> the class name, e.g., <CODE>Array<MyClass*></CODE> uses:

  <PRE>
    bool __cdecl myLT(MyClass*const& elem1, MyClass*const& elem2) {
        return elem1->x < elem2->x;
    }
    </PRE>
     */
    void sort(bool (__cdecl *lessThan)(const T& elem1, const T& elem2)) {
        std::sort(data, data + num, lessThan);
    }


    /**
     Sorts the array in increasing order using the > or < operator.  To 
     invoke this method on Array<T>, T must override those operator.
     You can overide these operators as follows:
     <code>
        bool T::operator>(const T& other) const {
           return ...;
        }
        bool T::operator<(const T& other) const {
           return ...;
        }
     </code>
     */
    void sort(int direction = SORT_INCREASING) {
        if (direction == SORT_INCREASING) {
            std::sort(data, data + num);
        } else {
            std::sort(data, data + num, compareGT);
        }
    }

    /**
     Sorts elements beginIndex through and including endIndex.
     */
    void sortSubArray(int beginIndex, int endIndex, int direction = SORT_INCREASING) {
        if (direction == SORT_INCREASING) {
            std::sort(data + beginIndex, data + endIndex + 1);
        } else {
            std::sort(data + beginIndex, data + endIndex + 1, compareGT);
        }
    }

    void sortSubArray(int beginIndex, int endIndex, bool (__cdecl *lessThan)(const T& elem1, const T& elem2)) {
        std::sort(data + beginIndex, data + endIndex + 1, lessThan);
    }

    /**
     The StrictWeakOrdering can be either a class that overloads the function call operator() or
     a function pointer of the form <code>bool (__cdecl *lessThan)(const T& elem1, const T& elem2)</code>
     */
    template<typename StrictWeakOrdering>
    void sortSubArray(int beginIndex, int endIndex, StrictWeakOrdering& lessThan) {
        std::sort(data + beginIndex, data + endIndex + 1, lessThan);
    }

    /** Uses < and == to evaluate operator(); this is the default comparator for Array::partition. */
    class DefaultComparator {
    public:
        inline int operator()(const T& A, const T& B) const {
            if (A < B) {
                return 1;
            } else if (A == B) {
                return 0;
            } else {
                return -1;
            }
        }
    };

    /** The output arrays are resized with fastClear() so that if they are already of the same size
        as this array no memory is allocated during partitioning. 
        
        @param comparator A function, or class instance with an overloaded operator() that compares
        two elements of type <code>T</code> and returns 0 if they are equal, -1 if the second is smaller,
        and 1 if the first is smaller (i.e., following the conventions of std::string::compare).  For example:

        <pre>
        int compare(int A, int B) {
            if (A < B) {
                return 1;
            } else if (A == B) {
                return 0;
            } else {
                return -1;
            }
        }
        </pre>
        */
    template<typename Comparator>
    void partition(
        const T& partitionElement, 
        Array<T>& ltArray,
        Array<T>& eqArray,
        Array<T>& gtArray,
        const Comparator& comparator) const {

        // Make sure all arrays are independent
        debugAssert(&ltArray != this);
        debugAssert(&eqArray != this);
        debugAssert(&gtArray != this);
        debugAssert(&ltArray != &eqArray);
        debugAssert(&ltArray != &gtArray);
        debugAssert(&eqArray != &gtArray);

        // Clear the arrays
        ltArray.fastClear();
        eqArray.fastClear();
        gtArray.fastClear();

        // Form a table of buckets for lt, eq, and gt
        Array<T>* bucket[3] = {&ltArray, &eqArray, &gtArray};

        for (int i = 0; i < num; ++i) {
            int c = comparator(partitionElement, data[i]);
            debugAssertM(c >= -1 && c <= 1, "Comparator returned an illegal value.");

            // Insert into the correct bucket, 0, 1, or 2
            bucket[c + 1]->append(data[i]);
        }
    }

    /**
      Uses < and == on elements to perform a partition.  See partition().
     */
    void partition(
        const T& partitionElement, 
        Array<T>& ltArray,
        Array<T>& eqArray,
        Array<T>& gtArray) const {

        partition(partitionElement, ltArray, eqArray, gtArray, typename Array<T>::DefaultComparator());
    }

    /** 
     Paritions the array into those below the median, those above the median, and those elements
     equal to the median in expected O(n) time using quickselect.  If the array has an even
     number of different elements, the median for partition purposes is the largest value
     less than the median.

     @param tempArray used for working scratch space
     @param comparator see parition() for a discussion.*/
    template<typename Comparator>
    void medianPartition(
        Array<T>&           ltMedian, 
        Array<T>&           eqMedian, 
        Array<T>&           gtMedian,
        Array<T>&           tempArray,
        const Comparator&   comparator) const {

        ltMedian.fastClear();
        eqMedian.fastClear();
        gtMedian.fastClear();

        // Handle trivial cases first
        switch (size()) {
        case 0:
            // Array is empty; no parition is possible
            return;

        case 1:
            // One element
            eqMedian.append(first());
            return;

        case 2:
            {
                // Two element array; median is the smaller
                int c = comparator(first(), last());
                
                switch (c) {
                case -1:
                    // first was bigger
                    eqMedian.append(last());
                    gtMedian.append(first());
                    break;

                case 0:
                    // Both equal to the median
                    eqMedian.append(first(), last());
                    break;

                case 1:
                    // Last was bigger
                    eqMedian.append(first());
                    gtMedian.append(last());
                    break;
                }
            }
            return;
        }

        // All other cases use a recursive randomized median

        // Number of values less than all in the current arrays        
        int ltBoost = 0;

        // Number of values greater than all in the current arrays        
        int gtBoost = 0;

        // For even length arrays, force the gt array to be one larger than the
        // lt array:  
        //  [1 2 3] size = 3, choose half = (s + 1) /2
        //
        int lowerHalfSize, upperHalfSize;
        if (isEven(size())) {
            lowerHalfSize = size() / 2;
            upperHalfSize = lowerHalfSize + 1;
        } else {
            lowerHalfSize = upperHalfSize = (size() + 1) / 2;
        }
        const T* xPtr = NULL;

        // Maintain pointers to the arrays; we'll switch these around during sorting
        // to avoid copies.
        const Array<T>* source = this;
        Array<T>* lt     = &ltMedian;
        Array<T>* eq     = &eqMedian;
        Array<T>* gt     = &gtMedian;
        Array<T>* extra  = &tempArray;

        while (true) {
            // Choose a random element -- choose the middle element; this is theoretically
            // suboptimal, but for loosly sorted array is actually the best strategy

            xPtr = &(source->middle());
            if (source->size() == 1) {
                // Done; there's only one element left
                break;
            }
            const T& x = *xPtr;

            // Note: partition (fast) clears the arrays for us
            source->partition(x, *lt, *eq, *gt, comparator);

            int L = lt->size() + ltBoost + eq->size();
            int U = gt->size() + gtBoost + eq->size();
            if ((L >= lowerHalfSize) &&
                (U >= upperHalfSize)) {

                // x must be the partition median                    
                break;

            } else if (L < lowerHalfSize) {

                // x must be smaller than the median.  Recurse into the 'gt' array.
                ltBoost += lt->size() + eq->size();

                // The new gt array will be the old source array, unless
                // that was the this pointer (i.e., unless we are on the 
                // first iteration)
                Array<T>* newGt = (source == this) ? extra : const_cast<Array<T>*>(source);
                
                // Now set up the gt array as the new source
                source = gt;
                gt = newGt;

            } else {

                // x must be bigger than the median.  Recurse into the 'lt' array.
                gtBoost += gt->size() + eq->size();

                // The new lt array will be the old source array, unless
                // that was the this pointer (i.e., unless we are on the 
                // first iteration)
                Array<T>* newLt = (source == this) ? extra : const_cast<Array<T>*>(source);
                
                // Now set up the lt array as the new source
                source = lt;
                lt = newLt;
            }
        }

        // Now that we know the median, make a copy of it (since we're about to destroy the array that it
        // points into).
        T median = *xPtr;
        xPtr = NULL;

        // Partition the original array (note that this fast clears for us)
        partition(median, ltMedian, eqMedian, gtMedian, comparator);
    }

    /**
      Computes a median partition using the default comparator and a dynamically allocated temporary 
      working array.  If the median is not in the array, it is chosen to be the largest value smaller
      than the true median.
     */
    void medianPartition(
        Array<T>&           ltMedian, 
        Array<T>&           eqMedian, 
        Array<T>&           gtMedian) const {

        Array<T> temp;
        medianPartition(ltMedian, eqMedian, gtMedian, temp, DefaultComparator());
    }


    /** Redistributes the elements so that the new order is statistically independent
        of the original order. O(n) time.*/
    void randomize() {
        T temp;

        for (int i = size() - 1; i >= 0; --i) {
            int x = iRandom(0, i);

            temp = data[i];
            data[i] = data[x];
            data[x] = temp;
        }
    }


};


/** Array::contains for C-arrays */
template<class T> bool contains(const T* array, int len, const T& e) {
    for (int i = len - 1; i >= 0; --i) {
        if (array[i] == e) {
            return true;
        }
    }
    return false;
}

} // namespace

#ifdef _MSC_VER
#   pragma warning (pop)
#endif

#endif
