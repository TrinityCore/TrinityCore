/**
  @file Table.h

  Templated hash table class.

  @maintainer Morgan McGuire, morgan@cs.williams.edu
  @created 2001-04-22
  @edited  2008-07-01
  Copyright 2000-2008, Morgan McGuire.
  All rights reserved.
 */

#ifndef G3D_TABLE_H
#define G3D_TABLE_H

#include <cstddef>
#include <string>

#include "G3D/platform.h"
#include "G3D/Array.h"
#include "G3D/debug.h"
#include "G3D/System.h"
#include "G3D/g3dmath.h"
#include "G3D/EqualsTrait.h"
#include "G3D/HashTrait.h"

#ifdef _MSC_VER
#   pragma warning (push)
    // Debug name too long warning
#   pragma warning (disable : 4786)
#endif

namespace G3D {

/**
 An unordered data structure mapping keys to values.

 Key must be a pointer, an int, a std::string or provide overloads for: 

  <PRE>
    template<> struct HashTrait<class Key> {
        static size_t hashCode(const Key& key) { return reinterpret_cast<size_t>( ... ); }
    }; 
  </PRE>

  and one of 

  <PRE>
    template<> struct EqualsTrait<class Key>{
         static bool equals(const Key& a, const Key& b) { return ... ; }
    };


    bool operator==(const Key&, const Key&);
  </PRE>

 G3D pre-defines HashTrait specializations for common types (like <CODE>int</CODE> and <CODE>std::string</CODE>).
 If you use a Table with a different type you must write those functions yourself.  For example,
 an enum would use:

  <PRE>
    template<> struct HashTrait<MyEnum> {
        static size_t equals(const MyEnum& key) const { return reinterpret_cast<size_t>( key ); }
    };
  </PRE>

  And rely on the default enum operator==.


  Periodically check that debugGetLoad() is low (> 0.1).  When it gets near
  1.0 your hash function is badly designed and maps too many inputs to
  the same output.
 */
template<class Key, class Value, class HashFunc = HashTrait<Key>, class EqualsFunc = EqualsTrait<Key> > 
class Table {
public:

    /**
     The pairs returned by iterator.
     */
    class Entry {
    public:
        Key    key;
        Value  value;
        Entry() {}
        Entry(const Key& k, const Value& v) : key(k), value(v) {}
    };

private:

    typedef Table<Key, Value, HashFunc, EqualsFunc> ThisType;

    /**
     Linked list nodes used internally by HashTable.
     */
    class Node {
    public:
        Entry       entry;
        size_t      hashCode;
        Node*       next;
        
        /** Provide pooled allocation for speed. */
        inline void* operator new (size_t size) {
            return System::malloc(size);
        }
        
        inline void operator delete (void* p) {
            System::free(p);
        }

        Node(const Key& k, const Value& v, size_t h, Node* n) 
            : entry(k, v), hashCode(h), next(n) {
        }

        /**
        Clones a whole chain;
        */
        Node* clone() {
           return new Node(this->entry.key, this->entry.value, hashCode, (next == NULL) ? NULL : next->clone());
        }
    };

    void checkIntegrity() const {
#       ifdef G3D_DEBUG
           debugAssert(bucket == NULL || isValidHeapPointer(bucket));
           for (size_t b = 0; b < numBuckets; ++b) {
               Node* node = bucket[b];
               debugAssert(node == NULL || isValidHeapPointer(node));
               while (node != NULL) {
                   debugAssert(node == NULL || isValidHeapPointer(node));
                   node = node->next;
               }
           }
#       endif
    }

    /**
     Number of elements in the table.
     */
    size_t          _size;

    /**
     Array of Node*. 
     We don't use Array<Node*> because Table is lower level.
     Some elements may be NULL.
     */
    Node**          bucket;
    
    /**
     Length of the bucket array.
     */
    size_t          numBuckets;

    /**
     Re-hashes for a larger bucket size.
     */
    void resize(size_t newSize) {

        // Hang onto the old bucket array
        Node** oldBucket = bucket;

        // Allocate a new bucket array with the new size
        bucket = (Node**)System::calloc(sizeof(Node*), newSize);
        debugAssertM(bucket != NULL, "System::calloc returned NULL. Out of memory.");
        // Move each node to its new hash location
        for (size_t b = 0; b < numBuckets; ++b) {
            Node* node = oldBucket[b];
         
            // There is a linked list of nodes at this bucket
            while (node != NULL) {
                // Hang onto the old next pointer
                Node* nextNode = node->next;
        
                // Insert at the head of the list for bucket[i]
                size_t i = node->hashCode % newSize;
                node->next = bucket[i];
                bucket[i] = node;

                // Move on to the next node
                node = nextNode;
            }

            // Drop the old pointer for cleanliness when debugging
            oldBucket[b] = NULL;
        }

        // Delete the old storage
        System::free(oldBucket);
        this->numBuckets = newSize;

        checkIntegrity();
    }


    void copyFrom(const ThisType& h) {
        if (&h == this) {
            return;
        }

        debugAssert(bucket == NULL);
        _size = h._size;
        numBuckets = h.numBuckets;
        bucket = (Node**)System::calloc(sizeof(Node*), numBuckets);

        for (size_t b = 0; b < numBuckets; b++) {
            if (h.bucket[b] != NULL) {
                bucket[b] = h.bucket[b]->clone();
            }
        }

        checkIntegrity();
    }

    /**
     Frees the heap structures for the nodes.
     */
    void freeMemory() {
        checkIntegrity();

        for (size_t b = 0; b < numBuckets; b++) {
            Node* node = bucket[b];
            while (node != NULL) {
                Node* next = node->next;
                delete node;
                node = next;
            }
            bucket[b] = NULL;
        }
        System::free(bucket);
        bucket     = NULL;
        numBuckets = 0;
        _size      = 0;
    }


public:

    /**
     Creates an empty hash table.  This causes some heap allocation to occur.
     */
    Table() : bucket(NULL) {
        numBuckets = 10;
        _size      = 0;
        bucket     = (Node**)System::calloc(sizeof(Node*), numBuckets);
        checkIntegrity();
    }

    /** 
        Recommends that the table resize to anticipate at least this number of elements.
     */
    void setSizeHint(size_t n) {
        size_t s = n * 3;
        if (s > numBuckets) {
            resize(s);
        }
    }
    
    /**
       Destroys all of the memory allocated by the table, but does <B>not</B>
       call delete on keys or values if they are pointers.  If you want to
       deallocate things that the table points at, use getKeys() and Array::deleteAll()
       to delete them.
    */
    virtual ~Table() {
        freeMemory();
    }

    Table(const ThisType& h) {
        numBuckets = 0;
        _size = 0;
        bucket = NULL;
        this->copyFrom(h);
        checkIntegrity();
    }


    Table& operator=(const ThisType& h) {
        // No need to copy if the argument is this
        if (this != &h) {
            // Free the existing nodes
            freeMemory();
            this->copyFrom(h);
            checkIntegrity();
        }
        return *this;
    }

    /**
     Returns the length of the deepest bucket.
     */
    size_t debugGetDeepestBucketSize() const {
        size_t deepest = 0;

        for (size_t b = 0; b < numBuckets; b++) {
            size_t  count = 0;
            Node*   node = bucket[b];
            while (node != NULL) {
                node = node->next;
                ++count;
            }

            if (count > deepest) {
                deepest = count;
            }
        }

        return deepest;
    }

    /**
       Returns the average size of non-empty buckets.
    */
    float debugGetAverageBucketSize() const {
        size_t num = 0;
        size_t count = 0;

        for (size_t b = 0; b < numBuckets; b++) {
            Node* node = bucket[b];
            if (node != NULL) {
                ++num;
                while (node != NULL) {
                    node = node->next;
                    ++count;
                }
            }
        }

        return (float)((double)count / num);
    }

    /**
     A small load (close to zero) means the hash table is acting very
     efficiently most of the time.  A large load (close to 1) means 
     the hash table is acting poorly-- all operations will be very slow.
     A large load will result from a bad hash function that maps too
     many keys to the same code.
     */
    double debugGetLoad() const {
        return debugGetDeepestBucketSize() / (double)size();
    }

    /**
     Returns the number of buckets.
     */
    size_t debugGetNumBuckets() const {
        return numBuckets;
    }

    /**
     C++ STL style iterator variable.  See begin().
     */
    class Iterator {
    private:
        friend class Table<Key, Value, HashFunc, EqualsFunc>;

        /**
         Bucket index.
         */
        size_t              index;

        /**
         Linked list node.
         */
        Node*               node;
        ThisType*           table;
        size_t              numBuckets;
        Node**              bucket;
        bool                isDone;

        /**
         Creates the end iterator.
         */
        Iterator(const ThisType* table) : table(const_cast<ThisType*>(table)) {
            isDone = true;
        }

        Iterator(const ThisType* table, size_t numBuckets, Node** bucket) :
            table(const_cast<ThisType*>(table)),
            numBuckets(numBuckets),
            bucket(bucket) {
            
            if (numBuckets == 0) {
                // Empty table
                isDone = true;
                return;
            }

            index = 0;
            node = bucket[index];
            isDone = false;
            findNext();
        }

        /**
         Finds the next element, setting isDone if one can't be found.
         Looks at the current element first.
         */
        void findNext() {
            while (node == NULL) {
                index++;
                if (index >= numBuckets) {
                    isDone = true;
                    break;
                } else {
                    node = bucket[index];
                }
            }
        }

    public:
        inline bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }

        bool operator==(const Iterator& other) const {
            if (other.isDone || isDone) {
                // Common case; check against isDone.
                return (isDone == other.isDone) && (other.table == table);
            } else {
                return
                    (table == other.table) &&
                    (node == other.node) && 
                    (index == other.index);
            }
        }

        /**
         Pre increment.
         */
        Iterator& operator++() {
            node = node->next;
            findNext();
            return *this;
        }

        /**
         Post increment (slower than preincrement).
         */
        Iterator operator++(int) {
            Iterator old = *this;
            ++(*this);
            return old;
        }

        const Entry& operator*() const {
            return node->entry;
        }

        Entry* operator->() const {
            return &(node->entry);
        }

        operator Entry*() const {
            return &(node->entry);
        }

		bool hasMore() const {
			return ! isDone;
		}
    };


    /**
     C++ STL style iterator method.  Returns the first Entry, which 
     contains a key and value.  Use preincrement (++entry) to get to
     the next element.  Do not modify the table while iterating.
     */
    Iterator begin() const {
        return Iterator(this, numBuckets, bucket);
    }

    /**
     C++ STL style iterator method.  Returns one after the last iterator
     element.
     */
    const Iterator end() const {
        return Iterator(this);
    }

    /**
     Removes all elements
     */
    void clear() {
        freeMemory();
        numBuckets = 10;
        _size = 0;
        bucket = (Node**)System::calloc(sizeof(Node*), numBuckets);
    }

   
    /**
     Returns the number of keys.
     */
    size_t size() const {
        return _size;
    }


    /**
     If you insert a pointer into the key or value of a table, you are
     responsible for deallocating the object eventually.  Inserting 
     key into a table is O(1), but may cause a potentially slow rehashing.
     */
    void set(const Key& key, const Value& value) {
        size_t code = HashFunc::hashCode(key);
        size_t b = code % numBuckets;
        
        // Go to the bucket
        Node* n = bucket[b];

        // No bucket, so this must be the first
        if (n == NULL) {
            bucket[b] = new Node(key, value, code, NULL);
            ++_size;
            return;
        }

        size_t bucketLength = 1;

        // Sometimes a bad hash code will cause all elements
        // to collide.  Detect this case and don't rehash when 
        // it occurs; nothing good will come from the rehashing.
        bool allSameCode = true;

        // Try to find the node
        do {
            allSameCode = allSameCode && (code == n->hashCode);

            if ((code == n->hashCode) && EqualsFunc::equals(n->entry.key, key)) {
               // Replace the existing node.
               n->entry.value = value;
               return;
            }

            n = n->next;
            ++bucketLength;
        } while (n != NULL);

        const size_t maxBucketLength = 3;
        // (Don't bother changing the size of the table if all entries
        // have the same hashcode--they'll still collide)
        if ((bucketLength > maxBucketLength) && 
            ! allSameCode && 
            (numBuckets < _size * 15)) {

            // This bucket was really large; rehash if all elements
            // don't have the same hashcode the number of buckets is
            // reasonable.

            // Back off the scale factor as the number of buckets gets 
            // large
            float f = 3.0f;
            if (numBuckets > 1000000) {
                f = 1.5f;
            } else if (numBuckets > 100000) {
                f = 2.0f;
            }
            int newSize = iMax((int)(numBuckets * f) + 1, (int)(_size * f));
            resize(newSize);
        }

        // Not found; insert at the head.
        b = code % numBuckets;
        bucket[b] = new Node(key, value, code, bucket[b]);
        ++_size;
   }

   /**
    Removes an element from the table if it is present.  
    @return true if the element was found and removed, otherwise  false
    */
   bool remove(const Key& key) {
      
       size_t code = HashFunc::hashCode(key);
       size_t b = code % numBuckets;

       // Go to the bucket
       Node* n = bucket[b];

       if (n == NULL) {
           return false;
       }

       Node* previous = NULL;
      
       // Try to find the node
       do {
          if ((code == n->hashCode) && EqualsFunc::equals(n->entry.key, key)) {
              // This is the node; remove it

              // Replace the previous's next pointer
              if (previous == NULL) {
                  bucket[b] = n->next;
              } else {
                  previous->next = n->next;
              }

              // Delete the node
              delete n;
              --_size;
              return true;
          }

          previous = n;
          n = n->next;
      } while (n != NULL);


      return false;
      //alwaysAssertM(false, "Tried to remove a key that was not in the table.");
   }

   /**
    Returns the value associated with key.
    @deprecated Use get(key, val) or getPointer(key) 
    */
   Value& get(const Key& key) const {

       size_t  code = HashFunc::hashCode(key);
        size_t b = code % numBuckets;

        Node* node = bucket[b];

        while (node != NULL) {
            if ((node->hashCode == code) && EqualsFunc::equals(node->entry.key, key)) {
                return node->entry.value;
            }
            node = node->next;
        }

        debugAssertM(false, "Key not found");
        // The next line is here just to make
        // a compiler warning go away.
        return node->entry.value;
   }


   /** Returns a pointer to the element if it exists, or NULL if it does not.
       Note that if your value type <i>is</i> a pointer, the return value is 
       a pointer to a pointer.  Do not remove the element while holding this 
       pointer.

       It is easy to accidentally mis-use this method.  Consider making 
       a Table<Value*> and using get(key, val) instead, which makes you manage
       the memory for the values yourself and is less likely to result in 
       pointer errors.
     */
   Value* getPointer(const Key& key) const {
       size_t code = HashFunc::hashCode(key);
      size_t b = code % numBuckets;

      Node* node = bucket[b];

      while (node != NULL) {
          if ((node->hashCode == code) && EqualsFunc::equals(node->entry.key, key)) {
             // found key
             return &(node->entry.value);
          }
          node = node->next;
      }

      // Failed to find key
      return NULL;
   }

   /**
    If the key is present in the table, val is set to the associated value and returns true.
    If the key is not present, returns false.
    */
   bool get(const Key& key, Value& val) const {
       Value* v = getPointer(key);
       if (v != NULL) {
           val = *v;
           return true;
       } else {
           return false;
       }
   }

   /**
    Returns true if key is in the table.
    */
   bool containsKey(const Key& key) const {
       size_t code = HashFunc::hashCode(key);
       size_t b = code % numBuckets;

       Node* node = bucket[b];

       while (node != NULL) {
           if ((node->hashCode == code) && EqualsFunc::equals(node->entry.key, key)) {
              return true;
           }
           node = node->next;
       } while (node != NULL);

       return false;
   }


   /**
    Short syntax for get.
    */
   inline Value& operator[](const Key &key) const {
      return get(key);
   }


   /**
    Returns an array of all of the keys in the table.
    You can iterate over the keys to get the values.
    @deprecated
    */
   Array<Key> getKeys() const {
       Array<Key> keyArray;
       getKeys(keyArray);
       return keyArray;
   }

   void getKeys(Array<Key>& keyArray) const {
       keyArray.resize(0, DONT_SHRINK_UNDERLYING_ARRAY);
       for (size_t i = 0; i < numBuckets; i++) {
           Node* node = bucket[i];
           while (node != NULL) {
               keyArray.append(node->entry.key);
               node = node->next;
           }
       }
   }

   /**
    Calls delete on all of the keys and then clears the table.
    */
   void deleteKeys() {
       for (size_t i = 0; i < numBuckets; i++) {
           Node* node = bucket[i];
           while (node != NULL) {
               delete node->entry.key;
               node = node->next;
           }
       }
       clear();
   }

   /**
    Calls delete on all of the values.  This is unsafe--
    do not call unless you know that each value appears
    at most once.

    Does not clear the table, so you are left with a table
    of NULL pointers.
    */
   void deleteValues() {
       for (size_t i = 0; i < numBuckets; ++i) {
           Node* node = bucket[i];
           while (node != NULL) {
               delete node->entry.value;
               node->entry.value = NULL;
               node = node->next;
           }
       }
   }
};

} // namespace

#ifdef _MSC_VER
#   pragma warning (pop)
#endif

#endif
