/** 
  @file SmallArray.h
  
  @created 2009-04-26
  @edited  2009-04-26

  Copyright 2000-2009, Morgan McGuire, http://graphics.cs.williams.edu
  All rights reserved.
 */
#ifndef G3D_SmallArray_h
#define G3D_SmallArray_h

#include "G3D/platform.h"
#include "G3D/Array.h"

namespace G3D {

/** Embeds \a N elements to reduce allocation time and increase 
    memory coherence when working with arrays of arrays.
    Offers a limited subset of the functionality of G3D::Array.*/
template<class T, int N>
class SmallArray {
private:
    int                 m_size;

    /** First N elements */
    T                   m_embedded[N];

    /** Remaining elements */
    Array<T>            m_rest;

public:

    SmallArray() : m_size(0) {}

    inline int size() const {
        return m_size;
    }

    void resize(int n, bool shrinkIfNecessary = true) {
        m_rest.resize(std::max(0, n - N), shrinkIfNecessary);
        m_size = n;
    }

    void clear(bool shrinkIfNecessary = true) {
        resize(0, shrinkIfNecessary);
    }

    inline T& operator[](int i) {
        debugAssert(i < m_size && i >= 0);
        if (i < N) {
            return m_embedded[i];
        } else {
            return m_rest[i - N];
        }
    }

    inline const T& operator[](int i) const {
        debugAssert(i < m_size && i >= 0);
        if (i < N) {
            return m_embedded[i];
        } else {
            return m_rest[i - N];
        }
    }

    inline void push(const T& v) {
        ++m_size;
        if (m_size <= N) {
            m_embedded[m_size - 1] = v;
        } else {
            m_rest.append(v);
        }
    }

    inline void append(const T& v) {
        push(v);
    }

    void fastRemove(int i) {
        debugAssert(i < m_size && i >= 0);
        if (i < N) {
            if (m_size <= N) {
                // Exclusively embedded
                m_embedded[i] = m_embedded[m_size - 1];
            } else {
                // Move one down from the rest array
                m_embedded[i] = m_rest.pop();
            }
        } else {
            // Removing from the rest array
            m_rest.fastRemove(i - N);
        }
        --m_size;
    }

    T pop() {
        debugAssert(m_size > 0);
        if (m_size <= N) {
            // Popping from embedded, don't need a temporary
            --m_size;
            return m_embedded[m_size];
        } else {
            // Popping from rest
            --m_size;
            return m_rest.pop();
        }
    }

    inline void popDiscard() {
        debugAssert(m_size > 0);
        if (m_size > N) {
            m_rest.popDiscard();
        }
        --m_size;
    }

    inline T& next() {
        ++m_size;
        if (m_size <= N) {
            return m_embedded[m_size - 1];
        } else {
            return m_rest.next();
        }
    }

    bool contains(const T& value) const {
        for (int i = std::min(m_size, N) - 1; i >= 0; --i) {
            if (m_embedded[i] == value) {
                return true;
            }
        }
        return m_rest.contains(value);
    }

    template<int MIN_ELEMENTS, int MIN_BYTES>
    SmallArray<T, N>& operator=(const Array<T, MIN_ELEMENTS, MIN_BYTES>& src) {
        resize(src.size());
        for (int i = 0; i < src.size(); ++i) {
            (*this)[i] = src[i];
        }
        return *this;
    }

	inline const T& last() const {
		return (*this)[size() - 1];
	}

	inline T& last() {
		return (*this)[size() - 1];
	}
};

}
#endif
