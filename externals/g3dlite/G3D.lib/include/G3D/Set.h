/**
  @file Set.h

  Hash set

  @maintainer Morgan McGuire, matrix@graphics3d.com

  @created 2001-12-09
  @edited  2006-02-20
 */

#ifndef G3D_SET_H
#define G3D_SET_H

#include "G3D/platform.h"
#include "G3D/Table.h"
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
template<class T> 
class Set {

    /**
     If an object is a member, it is contained in
     this table.
     */
    Table<T, bool> memberTable;

public:

    virtual ~Set() {}

    int size() const {
        return (int)memberTable.size();
    }

    bool contains(const T& member) const {
        return memberTable.containsKey(member);
    }

    /**
     Inserts into the table if not already present.
     */
    void insert(const T& member) {
        memberTable.set(member, true);
    }

    /**
     It is an error to remove members that are not already
     present.
     */
    void remove(const T& member) {
        memberTable.remove(member);  
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

