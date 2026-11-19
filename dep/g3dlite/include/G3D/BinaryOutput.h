/**
 \file G3D/BinaryOutput.h
 
 \maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
 \created 2001-08-09
 \edited  2011-08-24

 Copyright 2000-2012, Morgan McGuire.
 All rights reserved.
 */

#ifndef G3D_BinaryOutput_h
#define G3D_BinaryOutput_h

#include "G3D/platform.h"
#include <assert.h>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include "G3D/unorm8.h"
#include "G3D/Color4.h"
#include "G3D/Color3.h"
#include "G3D/Vector4.h"
#include "G3D/Vector3.h"
#include "G3D/Vector2.h"
#include "G3D/g3dmath.h"
#include "G3D/debug.h"
#include "G3D/BinaryInput.h"
#include "G3D/System.h"

#ifdef _MSC_VER
#   pragma warning (push)
// Conditional is constant (wrong in inline)
#   pragma warning (disable : 4127)
#endif
namespace G3D {

/**
 Sequential or random access byte-order independent binary file access.

 The compress() call can be used to compress with zlib.

 Any method call can trigger an out of memory error (thrown as char*) 
 when writing to "<memory>" instead of a file.

 Compressed writing and seeking backwards is not supported for huge files
 (i.e., BinaryOutput may have to dump the contents to disk if they 
 exceed available RAM).
 */
class BinaryOutput {
private:
    std::string     m_filename;

    bool            m_committed;

    /** 0 outside of beginBits...endBits, 1 inside */
    int             m_beginEndBits;

    /** The current string of bits being built up by beginBits...endBits.
        This string is treated semantically, as if the lowest bit was
        on the left and the highest was on the right.*/
    int8            m_bitString;

    /** Position (from the lowest bit) currently used in bitString.*/
    int             m_bitPos;

    // True if the file endianess does not match the machine endian
    bool            m_swapBytes;

    G3DEndian       m_fileEndian;

    uint8*          m_buffer;
    
    /** Size of the elements used */
    size_t          m_bufferLen;

    /** Underlying size of memory allocaded */
    size_t          m_maxBufferLen;

    /** Next byte in file */
    int64           m_pos;

    /** is this initialized? */
    bool            m_init;

    /** Number of bytes already written to the file.  Even on 32-bit OS, this can be 64-bits*/
    int64           m_alreadyWritten;             

    bool            m_ok;

    void reserveBytesWhenOutOfMemory(size_t bytes);

    void reallocBuffer(size_t bytes, size_t oldBufferLen);

    /**
     Make sure at least bytes can be written, resizing if
     necessary.
     */
    inline void reserveBytes(size_t bytes) {
        debugAssert(bytes > 0);
        size_t oldBufferLen = m_bufferLen;

        m_bufferLen = max(m_bufferLen, (size_t)(m_pos + bytes));
        if (m_bufferLen > m_maxBufferLen) {
            reallocBuffer(bytes, oldBufferLen);
        }
    }

    // Not implemented on purpose, don't use
    BinaryOutput(const BinaryOutput&);
    BinaryOutput& operator=(const BinaryOutput&);
    bool operator==(const BinaryOutput&);

public:

    /**
     You must call setEndian() if you use this (memory) constructor.
     */
    BinaryOutput();

    /**
     Doesn't actually open the file; commit() does that.
     Use "<memory>" as the filename if you're going to commit
     to memory.
     */
    BinaryOutput(
        const std::string&  filename,
        G3DEndian           fileEndian);

    ~BinaryOutput();
    
    /** Compresses the data in the buffer in place, 
        preceeding it with a little-endian uint32 indicating 
        the uncompressed size.

        Call immediately before commit().

        Cannot be used for huge files (ones where the data
        was already written to disk)-- will throw char*.

        \param level Compression level.  0 = fast, low compression; 9 = slow, high compression
     */
    void compress(int level = 9);

    /** True if no errors have been encountered.*/
    bool ok() const;

    /**
     Returns a pointer to the internal memory buffer.
     */
    inline const uint8* getCArray() const {
        return m_buffer;
    }

    void setEndian(G3DEndian fileEndian);

    G3DEndian endian() const {
        return m_fileEndian;
    }

    std::string getFilename() const {
        return m_filename;
    }

    /**
     Write the bytes to disk.  It is ok to call this 
     multiple times; it will just overwrite the previous file.

     Parent directories are created as needed if they do
     not exist.

     <B>Not</B> called from the destructor; you must call
     it yourself.

     @param flush If true (default) the file is ready for reading when the method returns, otherwise 
      the method returns immediately and writes the file in the background.
    */
    void commit(bool flush = true);

    /**
     Write the bytes to memory (which must be of
     at least size() bytes).
     */
    void commit(uint8*);

    /**
      A memory BinaryOutput may be reset so that it can be written to again
      without allocating new memory.  The underlying array will not be deallocated,
      but the reset structure will act like a newly intialized one.
     */
    void reset();


    inline int64 length() const {
        return m_bufferLen + m_alreadyWritten;
    }

    inline int64 size() const {
        return length();
    }

    /**
     Sets the length of the file to n, padding
     with 0's past the current end.  Does not
     change the position of the next byte to be
     written unless n < size().

     Throws char* when resetting a huge file to be shorter
     than its current length.
     */
    inline void setLength(int64 n) {
        n = n - m_alreadyWritten;

        if (n < 0) {
            throw "Cannot resize huge files to be shorter.";
        }

        if (n < (int64)m_bufferLen) {
            m_pos = n;
        }
        if (n > (int64)m_bufferLen) {
            reserveBytes((size_t)(n - m_bufferLen));
        }
    }

    /**
     Returns the current byte position in the file,
     where 0 is the beginning and getLength() - 1 is the end.
     */
    inline int64 position() const {
        return m_pos + m_alreadyWritten;
    }


    /**
     Sets the position.  Can set past length, in which case
     the file is padded with zeros up to one byte before the
     next to be written.

     May throw a char* exception when seeking backwards on a huge file.
     */
    inline void setPosition(int64 p) {
        p = p - m_alreadyWritten;

        if (p > (int64)m_bufferLen) {
            setLength((int)(p + (int64)m_alreadyWritten));
        }

        if (p < 0) {
            throw "Cannot seek more than 10 MB backwards on huge files.";
        }

        m_pos = (int)p;
    }


    void writeBytes
       (const void*         b,
        size_t              count) {

        reserveBytes(count);
        debugAssert(m_pos >= 0);
        debugAssert(m_bufferLen >= count);
        System::memcpy(m_buffer + m_pos, b, count);
        m_pos += count;
    }

    /**
     Writes a signed 8-bit integer to the current position.
     */
    inline void writeInt8(int8 i) {
        reserveBytes(1);
        m_buffer[m_pos] = *(uint8*)&i;
        ++m_pos;
    }

    inline void writeBool8(bool b) {
        writeInt8(b ? 1 : 0);
    }

    inline void writeUInt8(uint8 i) {
        reserveBytes(1);
        m_buffer[m_pos] = i;
        ++m_pos;
    }

    inline void writeUNorm8(unorm8 i) {
        writeUInt8(i.bits());
    }

    void writeUInt16(uint16 u);

    inline void writeInt16(int16 i) {
        writeUInt16(*(uint16*)&i);
    }

    void writeUInt32(uint32 u);

    inline void writeInt32(int32 i) {
        debugAssert(m_beginEndBits == 0);
        writeUInt32(*(uint32*)&i);
    }

    void writeUInt64(uint64 u);

    inline void writeInt64(int64 i) {
        writeUInt64(*(uint64*)&i);
    }

    inline void writeFloat32(float32 f) {
        debugAssert(m_beginEndBits == 0);
        union {
            float32 a;
            uint32 b;
        };
        a = f;
        writeUInt32(b);
    }

    inline void writeFloat64(float64 f) {
        union {
            float64 a;
            uint64 b;
        };
        a = f;
        writeUInt64(b);
    }

    /**
     Write a string with NULL termination.
     */
    inline void writeString(const std::string& s) {
        writeString(s.c_str());
    }

    /** Write a string that always consumes len bytes, truncating or padding as necessary*/
    inline void writeString(const std::string& s, int len) {
        const int pad = len - ((int)s.length() + 1);
        if (pad >= 0) {
            writeString(s.c_str());
            for (int i = 0; i < pad; ++i) {
                writeUInt8(0);
            }
        } else {
            // Truncate
            writeBytes(s.c_str(), len);
        }
    }

    void writeString(const char* s);

    /**
     Write a string, ensuring that the total length
     including NULL is even.
     */
    void writeStringEven(const std::string& s) {
        writeStringEven(s.c_str());
    }

    void writeStringEven(const char* s);

    void writeString32(const char* s);

    /**
     Write a NULL-terminated string with a 32-bit length field in front
     of it.  The NULL character is included in the length count.
     */
    void writeString32(const std::string& s) {
        writeString32(s.c_str());
    }

    void writeVector4(const Vector4& v);

    void writeVector3(const Vector3& v);

    void writeVector2(const Vector2& v);

    void writeColor4(const Color4& v);

    void writeColor3(const Color3& v);

    /**
     Skips ahead n bytes.
     */
    inline void skip(int n) {
        if (m_pos + n > (int64)m_bufferLen) {
            setLength(m_pos + m_alreadyWritten + n);
        }
        m_pos += n;
    }

    /** Call before a series of BinaryOutput::writeBits calls. Only writeBits 
        can be called between beginBits and endBits without corrupting the stream.*/
    void beginBits();

    /** Write numBits from bitString to the output stream.  Bits are numbered from
        low to high.
    
        Can only be 
        called between beginBits and endBits.  Bits written are semantically
        little-endian, regardless of the actual endian-ness of the system.  That is,
        <CODE>writeBits(0xABCD, 16)</CODE> writes 0xCD to the first byte and 
        0xAB to the second byte.  However, if used with BinaryInput::readBits, the ordering
        is transparent to the caller.
      */
    void writeBits(uint32 bitString, int numBits);

    /** Call after a series of BinaryOutput::writeBits calls. This will
        finish out with zeros the last byte into which bits were written.*/
    void endBits();


#   define DECLARE_WRITER(ucase, lcase)\
    void write##ucase(const lcase* out, int n);\
    void write##ucase(const std::vector<lcase>& out, int n);\
    void write##ucase(const Array<lcase>& out, int n);

    DECLARE_WRITER(Bool8,   bool)
    DECLARE_WRITER(UInt8,   uint8)
    DECLARE_WRITER(Int8,    int8)
    DECLARE_WRITER(UInt16,  uint16)
    DECLARE_WRITER(Int16,   int16)
    DECLARE_WRITER(UInt32,  uint32)
    DECLARE_WRITER(Int32,   int32)
    DECLARE_WRITER(UInt64,  uint64)
    DECLARE_WRITER(Int64,   int64)
    DECLARE_WRITER(Float32, float32)
    DECLARE_WRITER(Float64, float64)    
#   undef DECLARE_WRITER

};

}

#ifdef _MSC_VER
#   pragma warning (pop)
#endif

#endif
