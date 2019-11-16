#ifndef G3D_String_h
#define G3D_String_h

#include <string>
#include <stdint.h>
#include <smmintrin.h>
#include <assert.h>
#include <algorithm>
#include "G3D/platform.h"

#include "G3D/G3DAllocator.h"

#define USE_SSE_MEMCPY 1

namespace G3D {

#ifndef G3D_LINUX	
/** Returns true if this C string pointer is definitely located in the constant program data segment
	and does not require memory management. Used by String. */
bool inConstSegment(const char* c);

void* System_malloc(size_t);
void System_free(void*);

/** 
   \brief Very fast string class that follows the std::string/std::basic_string interface.

   - Recognizes constant segment strings and avoids copying them (currently, on MSVC 64-bit only)
   - Stores small strings internally to avoid heap allocation
   - Uses SSE instructions to copy internal strings
   - Uses the G3D block allocator when heap allocation is required
*/
template<size_t INTERNAL_SIZE = 64>
class __declspec(align(16)) SSESmallString {
public:

    typedef char                        value_type;
    typedef std::char_traits<char>      traits_type;
    typedef char&                       reference;
    typedef const char&                 const_reference;
    typedef char*                       pointer;
    typedef const char*                 const_pointer;
    typedef ptrdiff_t                   difference_type;
    typedef size_t                      size_type;
    typedef const char*                 const_iterator;
    typedef char*                       iterator;

protected:
    /** This inline storage is used when strings are small */
    __declspec(align(16)) char m_buffer[INTERNAL_SIZE];

    /** Includes NULL termination */
    value_type*     m_data;

    /** Bytes to but not including '\0' */
    size_t          m_length;

    /** Total size of m_data including '\0', or 0 if m_data is in a const segment */
    size_t          m_allocated;

    inline static void memcpy(void* dst, const void* src, size_t len) {
        ::memcpy(dst, src, len);
    }

    /** Requires 128-bit alignment */
    inline static void memcpyBuffer(void* dst, const void* src) {
#       if USE_SSE_MEMCPY
            if (INTERNAL_SIZE % 16 == 0) {
                __m128* d = reinterpret_cast<__m128*>(dst);
                const __m128* s = reinterpret_cast<const __m128*>(src);
                for (int i = 0; i < int(INTERNAL_SIZE / 16); ++i) {
                    d[i] = s[i];
                }
            } else {
                ::memcpy(dst, src, INTERNAL_SIZE);
            }
#       else
            ::memcpy(dst, src, INTERNAL_SIZE);
#       endif
    }

    inline void* alloc(size_t b) {
        if (b <= INTERNAL_SIZE) {
            return m_buffer;
        } else {
            return System_malloc(b);
        }
    }

    void free(void* p) const {
        if (p != m_buffer) {
            // debugAssert(! inConstSegment((const value_type *)p));
            return System_free(p);
        }
    }

    bool inConst() const {
        return ! m_allocated && m_data;
    }

    /** Choose the number of bytes to allocate to hold a string of length L */
    static size_t chooseAllocationSize(size_t L) {
        // Avoid allocating more than internal size unless required, but always allocate at least the internal size
        return (L + 1 <= INTERNAL_SIZE) ? INTERNAL_SIZE : std::max((size_t)(2 * L + 1), (size_t)64);
    }

    void prepareToMutate() {
        if (inConst()) {
            const value_type* old = m_data;
            m_allocated = chooseAllocationSize(m_length);
            m_data = (value_type*)alloc(m_allocated);
            memcpy(m_data, old, m_length + 1);
        }
    }

    void ensureAllocation(size_t newSize) {
        if ((m_allocated < newSize + 1) && ! ((m_data == m_buffer) && (newSize < INTERNAL_SIZE))) {
            // Allocate a new string and copy over
            value_type* old = m_data;
            m_allocated = chooseAllocationSize(newSize);
            m_data = (value_type*)alloc(m_allocated);
            memcpy(m_data, old, m_length);
            if (! inConstSegment(old)) { free(old); }
        }
    }

    void maybeDeallocate() {
        if (m_allocated) {
            // Free previously allocated data
            free(m_data);
            m_data = NULL;
            m_allocated = 0;
        }
    }

public:

    static const size_type npos = size_type(-1);
	/*
    void* operator new(size_t s) {
        return System_malloc(s);
    }
    
    void operator delete(void* p) {
        System_free(p);
    }
	*/

    /** Creates a zero-length string */
    inline SSESmallString() : m_data(m_buffer), m_length(0), m_allocated(INTERNAL_SIZE) {
        m_buffer[0] = '\0';
    }

    inline SSESmallString(const value_type c) : m_data(m_buffer), m_length(1), m_allocated(INTERNAL_SIZE) {
        m_buffer[0] = c;
        m_buffer[1] = '\0';
    }

    SSESmallString(const SSESmallString& s) {
        m_length = s.m_length;
        m_allocated = s.m_allocated;
        if (s.inConst()) {
            // Share this const_seg value
            m_data = s.m_data;
        } else {
            // Clone the value, putting it in the internal storage if possible
            m_data = (value_type*)alloc(m_allocated);

            if ((m_data == m_buffer) && (s.m_data == s.m_buffer)) {
                memcpyBuffer(m_data, s.m_data);
            } else {
                memcpy(m_data, s.m_data, m_length + 1); // Don't forget the '\0'
            }
        }
    }


    explicit SSESmallString(const std::string& s) : m_length(s.size()) {
        // Allocate more than needed for fast append
        m_allocated = chooseAllocationSize(m_length + 1);
        m_data = (value_type*)alloc(m_allocated);
        memcpy(m_data, s.c_str(), m_length + 1);
    }


    SSESmallString(const value_type* c) : m_length(::strlen(c)) {
        if (inConstSegment(c)) {
            m_data = const_cast<value_type*>(c);
            m_allocated = 0;
        } else {
            // Allocate more than needed for fast append
            m_allocated = chooseAllocationSize(m_length + 1);
            m_data = (value_type*)alloc(m_allocated);
            memcpy(m_data, c, m_length + 1);
        }
    }


    /** \param len Copy this many characters. The result is always copied because it is unsafe to
        check past the end of c for a null terminator. */
    SSESmallString(const value_type* c, size_t len) : m_length(len) {
        // Allocate more than needed for fast append
        m_allocated = chooseAllocationSize(m_length + 1);
        m_data = (value_type*)alloc(m_allocated);
        memcpy(m_data, c, m_length);
        m_data[m_length] = '\0'; // Don't forget the null terminator
    }


    SSESmallString& operator=(const SSESmallString& s) {
        if (&s == this) {
            return *this;
        } else if (s.inConst()) {
            // Constant storage
            maybeDeallocate();
            // Share this const_seg value
            m_data = s.m_data;
            m_length = s.m_length;
            m_allocated = s.m_allocated;

        } else if (s.m_allocated == 0) {
            // Internal storage or NULL
            maybeDeallocate();
            if (s.m_length > 0) {
                m_data = m_buffer;
                memcpyBuffer(m_buffer, s.m_buffer);
            }
            m_length = s.m_length;
            m_allocated = s.m_allocated;
        } else {
            // Clone the other value, putting it in the internal storage if possible
            m_length = s.m_length;
            m_allocated = chooseAllocationSize(m_length);
            m_data = (value_type*)alloc(m_allocated);

            if ((m_data == m_buffer) && (s.m_data == s.m_buffer)) {
                memcpyBuffer(m_data, s.m_data);
            } else {
                memcpy(m_data, s.m_data, m_length + 1); // Don't forget the null terminator
            }
        }

        return *this;
    }


    SSESmallString& assign(const SSESmallString& s) {
        return (*this) = s;
    }


    SSESmallString& assign(const SSESmallString& s, size_t subpos, size_t sublen) {
        size_t copy_len = (sublen == npos || subpos + sublen >= s.size()) ? s.size() - subpos : sublen;
        if (subpos == 0 && copy_len == s.size()) {
            return (*this).assign(s);
        }
        if (s.inConst() && subpos + copy_len == s.size()) {
            // Constant storage
            maybeDeallocate();
            // Share this const_seg value
            m_data      = s.m_data + subpos;
            m_length    = copy_len;
            m_allocated = s.m_allocated;
        } else {
            // Clone the other value, putting it in the internal storage if possible
            m_length = copy_len;
            m_allocated = chooseAllocationSize(m_length);
            m_data = (value_type*)alloc(m_allocated);
            memcpy(m_data, s.m_data + subpos, m_length); 
            m_data[m_length] = '\0'; // Don't forget the null terminator
        }
        return *this;
    }


    SSESmallString& assign(const value_type* c, size_t n) {
        m_length = n;
        // Clone the other value, putting it in the internal storage if possible
        m_allocated = chooseAllocationSize(m_length);
        m_data = (value_type*)alloc(m_allocated);
        memcpy(m_data, c, m_length); 
        m_data[m_length] = '\0'; // Don't forget the null terminator
        return *this;
    }

    
    SSESmallString& assign(size_t n, const value_type c) {
        m_length = n;
        // Clone the other value, putting it in the internal storage if possible
        m_allocated = chooseAllocationSize(m_length);
        m_data = (value_type*)alloc(m_allocated);
        memset(m_data, c, m_length); 
        m_data[m_length] = '\0'; // Don't forget the null terminator
        return *this;
    }


    ~SSESmallString() {
        if (m_data && m_allocated) {
            free(m_data);
        }
    }


    SSESmallString& insert(size_t pos, const SSESmallString& str, size_t subpos, size_t sublen) {

    }

    SSESmallString& insert(size_t pos, const SSESmallString& str) {
        return insert(pos, str, 0, str.size());
    }

    SSESmallString& insert(size_t pos, const value_type* c) {

    }


	void clear() {
		*this = SSESmallString();
	}


    const_iterator cbegin() const {
        return m_data;
    }


    const_iterator cend() const {
        if (m_data) {
            return m_data + m_length;
        } else {
            return NULL;
        }
    }


    iterator begin() {
        prepareToMutate();
        return m_data;
    }


    iterator end() {
        prepareToMutate();
        if (m_data) {
            return m_data + m_length;
        } else {
            return NULL;
        }
    }

    
    SSESmallString& erase(size_t pos = 0, size_t len = npos) {
        prepareToMutate();
        if ((len == npos) || (pos + len > m_length)) {
            len = m_length - pos;
        }

        if ((pos == 0) && (len == m_length)) {
            // Optimize erasing the entire string
            clear();
        } else if (len > 0) {
            for (int i = 0; i <= (int)max(m_length - pos, len - 1); ++i) {
                size_t nextIndex = pos + i + len;
                m_data[pos + i] = (nextIndex >= m_length) ? '\0' : m_data[nextIndex];
            }
            m_length -= len;
        }

        return *this;
    }


    void reserve(size_t newLength) {
        if (newLength + 1 > m_allocated) {
            // Reserve more space
            if (newLength + 1 > INTERNAL_SIZE) {
                // Need heap allocation
                char* old = m_data;
                // Allocate the exact size required
                m_data = (value_type*)alloc(newLength + 1);
                m_allocated = newLength + 1;
                memcpy(m_data, old, m_length + 1);

                // Maybe free the old buffer, if it was not m_buffer
                free(old);
            } else if (m_data != m_buffer) {
                // Must be in a const segment, because small and not in the buffer. Just copy to the internal buffer.
                memcpy(m_buffer, m_data, m_length + 1);
                m_allocated = INTERNAL_SIZE;
                m_data = m_buffer;
            } else {
                // Should already have been in the internal buffer and fitting
                assert(false); // "Should not reach this case if the new length is less than the internal buffer"
            }
        }
    }


    SSESmallString operator+(const SSESmallString& s) const {
        SSESmallString result;
        result.m_length = m_length + s.m_length;
        result.m_allocated = chooseAllocationSize(result.m_length);
        result.m_data = (value_type*)result.alloc(result.m_allocated);
        memcpy(result.m_data, m_data, m_length);
        memcpy(result.m_data + m_length, s.m_data, s.m_length + 1);
        return result;
    }


    SSESmallString operator+(const value_type* c) const {
        assert(c);
        if (*c == '\0') {
            return *this;
        } else {
            const size_t L(strlen(c));
            SSESmallString result;
            result.m_length = m_length + L;
            result.m_allocated = chooseAllocationSize(result.m_length);
            result.m_data = (value_type*)result.alloc(result.m_allocated);
            
            if ((result.m_data == result.m_buffer) && (m_data == m_buffer)) {
                memcpyBuffer(result.m_data, m_data);
            } else {
                memcpy(result.m_data, m_data, m_length);
            }
            memcpy(result.m_data + m_length, c, L + 1);
            return result;
        }
    }
    

    SSESmallString operator+(const value_type c) const {
        const size_t L(1);
        SSESmallString result;
        result.m_length = m_length + L;
        result.m_allocated = chooseAllocationSize(result.m_length);
        result.m_data = (value_type*)result.alloc(result.m_allocated);

        if ((result.m_data == result.m_buffer) && (m_data == m_buffer)) {
            memcpyBuffer(result.m_data, m_data);
        } else {
            memcpy(result.m_data, m_data, m_length);
        }
        result.m_data[result.m_length - 1] = c;
        result.m_data[result.m_length] = '\0';
        return result;
    }


    SSESmallString& operator+=(const SSESmallString& s) {
		if (s.empty()) {
			return *this;
		}
        ensureAllocation(m_length + s.m_length);
        memcpy(m_data + m_length, s.m_data, s.m_length + 1);
        m_length += s.m_length;
        return *this;
    }

    SSESmallString& append(const SSESmallString& s, size_t subpos, size_t sublen) {
		if (s.empty() || subpos >= s.size() || sublen == 0) {
			return *this;
		}
        size_t copy_len = (sublen == npos || subpos + sublen >= s.size()) ? s.size() - subpos : sublen;
        ensureAllocation(m_length + copy_len);
        memcpy(m_data + m_length, s.m_data + subpos, copy_len);
        m_length += copy_len;
        m_data[m_length] = '\0';
        return *this;
    }

    SSESmallString& operator+=(const value_type c) {
        ensureAllocation(m_length + 1);
        m_data[m_length] = c;
        m_length += 1;
        m_data[m_length] = '\0';
        return *this;
    }

    void push_back(value_type c) {
        *this += c;
    }


    SSESmallString& append(const SSESmallString& s) {
        return (*this += s);
    }


    SSESmallString& append(size_t n, value_type c) {
        ensureAllocation(m_length + n);
        memset(m_data + m_length, c, n);
        m_length += n;
        m_data[m_length] = '\0';
        return *this;
    }

    SSESmallString& append(const value_type* c, size_t t) {
        ensureAllocation(m_length + t);
        memcpy(m_data + m_length, c, t);
        m_length += t;
        m_data[m_length] = '\0';
        return *this;
    }

    SSESmallString& operator+=(const value_type* c) {
        const size_t t = strlen(c);
        ensureAllocation(m_length + t);
        memcpy(m_data + m_length, c, t + 1);
        m_length += t;
        return *this;
    }

    SSESmallString& append(const value_type* c) {
        return (*this) += c;
    }

    bool operator==(const SSESmallString& s) const {
        return (m_data == s.m_data) || ((m_length == s.m_length) && (memcmp(m_data, s.m_data, m_length) == 0));
    }


    bool operator==(const value_type* c) const {
        return (m_data == c) || (strcmp(m_data, c) == 0);
    }

	bool operator!=(const SSESmallString& s) const {
        return ! (*this == s);
    }


    bool operator!=(const value_type* c) const {
        return ! (*this == c);
    }


    size_type size() const {
        return m_length;
    }


    size_type length() const {
        return m_length;
    }


    size_type capacity() const {
        if (m_data == m_buffer) {
            return INTERNAL_SIZE;
        } else {
            return m_allocated;
        }
    }


    size_type max_size() const {
        return size_type(-1);
    }


    bool empty() const {
        return (m_length == 0);
    }

    
    const value_type* c_str() const {
        return m_data;
    }


    const value_type* data() const {
        return m_data;
    }


    const_reference operator[](size_t x) const {
        assert(x < m_length && x >= 0); // "Index out of bounds");
        return m_data[x];
    }

    
    reference operator[](size_t x) {
        assert(x < m_length && x >= 0); // "Index out of bounds");
        return m_data[x];
    }


    const_reference at(size_t x) const {
        assert(x < m_length && x >= 0); // "Index out of bounds");
        return m_data[x];
    }


    reference at(size_t x) {
        assert(x < m_length && x >= 0); // "Index out of bounds");
        return m_data[x];
    }


    const_reference front() const {
        assert(m_data); // "Empty string"
        return m_data[0];
    }


    reference front(size_t x) {
        assert(m_data); // "Empty string"
        return m_data[0];
    }


    const_reference back() const {
        assert(m_data); // "Empty string"
        return m_data[m_length - 1];
    }


    reference back(size_t x) {
        assert(m_data); // "Empty string"
        return m_data[m_length - 1];
    }


    size_t find(const SSESmallString& str, size_t pos = 0) const {
        return find(str.c_str(), pos, str.m_length);
    }


    size_t find(const char* s, size_t pos = 0) const {
        return find(s, pos, ::strlen(s));
    }


    size_t find(const char* s, size_t pos, size_t n) const {
        if (n > m_length) {
            return npos;
        }
        const size_t j = m_length - n + 1;

		if (n == 1) {
			// Special case the extremely common 1-character version
			for (size_t i = pos; i < j; ++i) {
				if (m_data[i] == *s) { return (size_t)i; }
			}
		} else {
			for (size_t i = pos; i < j; ++i) {
				if (compare(m_data + i, n, s, n) == 0) {
					return (size_t)i;
				}
			}
		}
        return npos;
    }


    size_t find(char c, size_t pos = 0) const {
        for (size_t i = pos; i < m_length; ++i) {
            if (m_data[i] == c) { return i; }
        }
        return npos;
    }

    
    size_t rfind(const SSESmallString& str, size_t pos = npos) const {
        return rfind(str.c_str(), pos, str.m_length);
    }


    size_t rfind(const char* s, size_t pos = npos) const {
        return rfind(s, pos, ::strlen(s));
    }

    
    size_t rfind(const char* s, size_t pos, size_t n) const {
        if (n > m_length ) {
            return npos;
        }

		if (n == 1) {
			for (int i = (int)std::min(pos, m_length - (int)n); i >= 0; --i) {
				if (m_data[i] == *s) { return (size_t)i; }
			}
		} else {
			for (int i = (int)std::min(pos, m_length - (int)n); i >= 0; --i) {
				if (compare(m_data + i, n, s, n) == 0) {
					return (size_t)i;
				}
			}
		}
        return npos;
    }

    
    size_t rfind(char c, size_t pos = npos) const {
        int start = (pos == npos || pos > m_length) ? (int)m_length - 1 : (int)pos;
        for (int i = start; i >= 0; --i) {
            if (m_data[i] == c) { return i; }
        }
        return npos;
    }


    size_t find_first_of(const value_type* s, size_t pos, size_t n) const {
        for (int j = (int)pos; j < m_length; ++j) {
            const value_type c = m_data[j];
            for (int i = 0; i < n; ++i) {
                if (c == s[i]) {
                    return (size_t)j;
                }
            }
        }

        return npos;
    }

    
    size_t find_first_of(const SSESmallString& str, size_t pos = 0) const {
        return find_first_of(str.c_str(), pos, str.length());
    }


    size_t find_first_of(const value_type* s, size_t pos = 0) const {
        return find_first_of(s, pos, ::strlen(s));
    }


    size_t find_first_of(value_type c, size_t pos = 0) const {
        return find_first_of(&c, pos, 1);
    }


    size_t find_last_of(const value_type* s, size_t pos, size_t n) const {
        // When pos is specified, the search only includes characters at or before position pos, ignoring any possible occurrences after pos.
        int start = (int)m_length - 1;
        start = (size_t)start > pos ? (int)pos : start;
        for (int j = (int)(m_length) - 1; j >= 0; --j) {
            const value_type c = m_data[j];
            for (int i = 0; i < n; ++i) {
                if (c == s[i]) {
                    return (size_t)j;
                }
            }
        }

        return npos;
    }


    size_t find_last_of(const SSESmallString& str, size_t pos = npos) const {
        return find_last_of(str.c_str(), pos, str.length());
    }


    size_t find_last_of(const value_type* s, size_t pos = npos) const {
        return find_last_of(s, pos, ::strlen(s));
    }


    size_t find_last_of(value_type c, size_t pos = npos) const {
        return find_last_of(&c, pos, 1);
    }


    SSESmallString substr(size_t pos = 0, size_t len = npos) const {
        const size_t slen = std::max((size_t)0, std::min(m_length - pos, len));
        if (slen == 0) { return SSESmallString(); }

        // If copying from a const segment and ending at the end of the string, do not allocate
        if (inConst() && (m_length == pos + slen)) {
            return SSESmallString(m_data + pos);
        } else {
            return SSESmallString(m_data + pos, slen);
        }
    }

private:

    // Does not stop for internal null terminators.  Does not include the null
    // terminators.
    // See http://www.cplusplus.com/reference/string/string/compare/
    int compare(const char* a, size_t alen, const char* b, size_t blen) const {
        const size_t len = std::min(alen, blen);
        for (size_t i = 0; i < len; ++i, ++a, ++b) {
            const int c = *a - *b;
            if (c != 0) { return c; }
        }

        // Whichever was shorter is the lesser
        return (int)alen - (int)blen;
    }

public:

    int compare(const SSESmallString& str) const {
        if (m_data == str.m_data) {
            return 0;
        } else {
            return compare(m_data, m_length, str.m_data, str.m_length);
        }
    }

    int compare(size_t pos, size_t len, const SSESmallString& str) const {
        return compare(m_data + pos, std::min(m_length - pos, len), str.m_data, str.m_length); 
    }

    int compare(size_t pos, size_t len, const SSESmallString& str, size_t subpos, size_t sublen) const {
        return compare(m_data + pos, std::min(m_length - pos, len), str.m_data + subpos, std::min(str.m_length - subpos, sublen)); 
    }

    int compare(const char* s) const {
        return compare(m_data, m_length, s, ::strlen(s));
    }

    int compare(size_t pos, size_t len, const char* s) const {
        return compare(m_data + pos, std::min(m_length - pos, len), s, ::strlen(s)); 
    }

    int compare(size_t pos, size_t len, const char* s, size_t n) const {
        return compare(m_data + pos, std::min(m_length - pos, len), s, n); 
    }

    bool operator>(const SSESmallString& s) const {
        return compare(s) > 0;
    }
    
    bool operator<(const SSESmallString& s) const {
        return compare(s) < 0;
    }
};
#endif
/** \def G3D_STRING_DESTRUCTOR
 The name of the destructor for the class currently typedef'ed to String.
*/

// Choose the implementation of G3D::String
#if 1

    // Slow
    typedef std::string String;
    #define G3D_STRING_DESTRUCTOR ~basic_string

#elif !defined(G3D_64BIT) || !_MSC_VER

    // Faster
    typedef std::basic_string<char, std::char_traits<char>, G3DAllocator<char> >  String;
    #define G3D_STRING_DESTRUCTOR ~basic_string

#else

    // Fastest, but only supported on Windows
    typedef SSESmallString<64> String;
    #define G3D_STRING_DESTRUCTOR ~SSESmallString

#endif

/** For use with default output arguments. The value is always undefined. */
extern String ignoreString;


} // namespace G3D

#ifndef G3D_LINUX
inline G3D::SSESmallString<64> operator+(const char* s1, const G3D::SSESmallString<64>& s2) {
	return G3D::SSESmallString<64>(s1) + s2;
}

inline G3D::SSESmallString<64> operator+(const char s1, const G3D::SSESmallString<64>& s2) {
	return G3D::SSESmallString<64>(s1) + s2;
}
#endif


/*
#if defined(G3D_64BIT) && _MSC_VER
// For use with hash_map
namespace stdext {
inline
	size_t hash_value(const G3D::SSESmallString<64>& _Str)
	{	// hash string to size_t value
	  return (::std::_Hash_seq((const unsigned char *)_Str.c_str(),
		_Str.size() * sizeof (G3D::SSESmallString<64>::value_type)));
	}
}
#endif
*/

#endif
