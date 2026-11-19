/**
  @file Set.h

  Hash set

  @maintainer Morgan McGuire, http://graphics.cs.williams.edu

  @created 2001-12-09
  @edited  2009-06-10
 */

#ifndef G3D_Set_h
#define G3D_Set_h

#include "G3D/platform.h"
#include "G3D/Table.h"
#include "G3D/MemoryManager.h"
#include <assert.h>
#include <string>

namespace G3D {

/**
  An unordered data structure that has at most one of each element.
  Provides O(1) time insert, remove, and member test (contains).

  Set uses G3D::Table internally, which means that the template type T 
  must define a hashCode and operator== function.  See G3D::Table for 
  a discussion of these functions.
 */
// There is not copy constructor or assignment operator defined because
// the default ones are correct for Set.
template<class T, class HashFunc = HashTrait<T>, class EqualsFunc = EqualsTrait<T> > 
class Set {

    /**
     If an object is a member, it is contained in
     this table.
     */
    Table<T, bool, HashFunc, EqualsFunc> memberTable;

public:

    void clearAndSetMemoryManager(const MemoryManager::Ref& m) {
        memberTable.clearAndSetMemoryManager(m);
    }

    virtual ~Set() {}

    int size() const {
        return (int)memberTable.size();
    }

    bool contains(const T& member) const {
        return memberTable.containsKey(member);
    }

    /**
     Inserts into the table if not already present.
     Returns true if this is the first time the element was added.
     */
    bool insert(const T& member) {
        bool isNew = false;
        memberTable.getCreate(member, isNew) = true;
        return isNew;
    }

    /**
     Returns true if the element was present and removed.  Returns false
     if the element was not present.
     */
    bool remove(const T& member) {
        return memberTable.remove(member);  
    }

    /** If @a member is present, sets @a removed to the element
        being removed and returns true.  Otherwise returns false
        and does not write to @a removed. This is useful when building
        efficient hashed data structures that wrap Set. 
        */
    bool getRemove(const T& member, T& removed) {
        bool ignore;
        return memberTable.getRemove(member, removed, ignore);
    }

    /** If a value that is EqualsFunc to @a member is present, returns a pointer to the 
        version stored in the data structure, otherwise returns NULL.
     */
    const T* getPointer(const T& member) const {
        return memberTable.getKeyPointer(member);
    }

    Array<T> getMembers() const {
        return memberTable.getKeys();
    }

    void getMembers(Array<T>& keyArray) const {
        memberTable.getKeys(keyArray);
    }

    void clear() {
        memberTable.clear();
    }

    void deleteAll()  {
        getMembers().deleteAll();
        clear();
    }

    /**
     C++ STL style iterator variable.  See begin().
     */
    class Iterator {
    private:
        friend class Set<T>;

        // Note: this is a Table iterator, we are currently defining
        // Set iterator
        typename Table<T, bool>::Iterator it;

        Iterator(const typename Table<T, bool>::Iterator& it) : it(it) {}

    public:
        inline bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }

        bool isValid() const {
            return it.isValid();
        }

        /** @deprecated  Use isValid */
        bool hasMore() const {
            return it.isValid();
        }
        
        bool operator==(const Iterator& other) const {
            return it == other.it;
        }

        /**
         Pre increment.
         */
        Iterator& operator++() {
            ++it;
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

        const T& operator*() const {
            return it->key;
        }

        T* operator->() const {
            return &(it->key);
        }

        operator T*() const {
            return &(it->key);
        }
    };


    /**
     C++ STL style iterator method.  Returns the first member.  
     Use preincrement (++entry) to get to the next element.  
     Do not modify the set while iterating.
     */
    Iterator begin() const {
        return Iterator(memberTable.begin());
    }


    /**
     C++ STL style iterator method.  Returns one after the last iterator
     element.
     */
    const Iterator end() const {
        return Iterator(memberTable.end());
    }
};

}

#endif

