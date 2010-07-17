/** 
  @file WeakCache.h
 
  @maintainer Morgan McGuire, graphics3d.com
 
  @created 2007-05-16
  @edited  2007-05-16

  Copyright 2000-2007, Morgan McGuire.
  All rights reserved.
 */
#ifndef G3D_WEAKCACHE_H
#define G3D_WEAKCACHE_H

#include "G3D/ReferenceCount.h"
#include "G3D/Table.h"

namespace G3D {

/**
   A cache that does not prevent its members from being garbage collected.
   Useful to avoid loading or computing an expression twice.  Useful
   for memoization and dynamic programming.

   Maintains a table of weak pointers.  Weak pointers do not prevent
   an object from being garbage collected.  If the object is garbage
   collected, the cache removes its reference.

   There are no "contains" or "iterate" methods because elements can be
   flushed from the cache at any time if they are garbage collected.

   Example:
   <pre>
      WeakCache<std::string, TextureRef> textureCache;

      TextureRef loadTexture(std::string s) {
          TextureRef t = textureCache[s];

          if (t.isNull()) {
              t = Texture::fromFile(s);
              textureCache.set(s, t);
          }

          return t;
      }
      
      
    </pre>
 */
template<class Key, class ValueRef>
class WeakCache {
    typedef WeakReferenceCountedPointer<typename ValueRef::element_type> ValueWeakRef;

private:

    Table<Key, ValueWeakRef> table;

public:
    /**
       Returns NULL if the object is not in the cache
    */
    ValueRef operator[](const Key& k) {
        if (table.containsKey(k)) {
            ValueWeakRef w = table[k];
            ValueRef s = w.createStrongPtr();
            if (s.isNull()) {
                // This object has been collected; clean out its key
                table.remove(k);
            }
            return s;
        } else {
            return NULL;
        }
    }

    void set(const Key& k, ValueRef v) {
        table.set(k, v);
    }

    /** Removes k from the cache or does nothing if it is not currently in the cache.*/
    void remove(const Key& k) {
        if (table.containsKey(k)) {
            table.remove(k);
        }
    }
};

}
#endif

