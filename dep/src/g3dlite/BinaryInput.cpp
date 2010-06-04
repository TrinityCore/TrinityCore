/**
 @file BinaryInput.cpp
 
 @author Morgan McGuire, graphics3d.com
 Copyright 2001-2007, Morgan McGuire.  All rights reserved.
 
 @created 2001-08-09
 @edited  2005-02-24


  <PRE>
    {    
    BinaryOutput b("c:/tmp/test.b", BinaryOutput::LITTLE_ENDIAN);

    float f = 3.1415926;
    int i = 1027221;
    std::string s = "Hello World!";

    b.writeFloat32(f);
    b.writeInt32(i);
    b.writeString(s);
    b.commit();
    

    BinaryInput in("c:/tmp/test.b", BinaryInput::LITTLE_ENDIAN);

    debugAssert(f == in.readFloat32());
    int ii = in.readInt32();
    debugAssert(i == ii);
    debugAssert(s == in.readString());
    }
  </PRE>
 */

#include "G3D/platform.h"
#include "G3D/BinaryInput.h"
#include "G3D/Array.h"
#include "G3D/fileutils.h"
#include "G3D/Log.h"
#include <zlib.h>

#include <cstring>

namespace G3D {

void BinaryInput::readBool8(std::vector<bool>& out, int64 n) {
    out.resize((int)n);
    // std::vector optimizes bool in a way that prevents fast reading
    for (int64 i = 0; i < n ; ++i) {
        out[i] = readBool8();
    }
}


void BinaryInput::readBool8(Array<bool>& out, int64 n) {
    out.resize(n);
    readBool8(out.begin(), n);
}


#define IMPLEMENT_READER(ucase, lcase)\
void BinaryInput::read##ucase(std::vector<lcase>& out, int64 n) {\
    out.resize(n);\
    read##ucase(&out[0], n);\
}\
\
\
void BinaryInput::read##ucase(Array<lcase>& out, int64 n) {\
    out.resize(n);\
    read##ucase(out.begin(), n);\
}


IMPLEMENT_READER(UInt8,   uint8)
IMPLEMENT_READER(Int8,    int8)
IMPLEMENT_READER(UInt16,  uint16)
IMPLEMENT_READER(Int16,   int16)
IMPLEMENT_READER(UInt32,  uint32)
IMPLEMENT_READER(Int32,   int32)
IMPLEMENT_READER(UInt64,  uint64)
IMPLEMENT_READER(Int64,   int64)
IMPLEMENT_READER(Float32, float32)
IMPLEMENT_READER(Float64, float64)    

#undef IMPLEMENT_READER

// Data structures that are one byte per element can be 
// directly copied, regardles of endian-ness.
#define IMPLEMENT_READER(ucase, lcase)\
void BinaryInput::read##ucase(lcase* out, int64 n) {\
    if (sizeof(lcase) == 1) {\
        readBytes(out, n);\
    } else {\
        for (int64 i = 0; i < n ; ++i) {\
            out[i] = read##ucase();\
        }\
    }\
}

IMPLEMENT_READER(Bool8,   bool)
IMPLEMENT_READER(UInt8,   uint8)
IMPLEMENT_READER(Int8,    int8)

#undef IMPLEMENT_READER


#define IMPLEMENT_READER(ucase, lcase)\
void BinaryInput::read##ucase(lcase* out, int64 n) {\
    if (m_swapBytes) {\
        for (int64 i = 0; i < n; ++i) {\
            out[i] = read##ucase();\
        }\
    } else {\
        readBytes(out, sizeof(lcase) * n);\
    }\
}


IMPLEMENT_READER(UInt16,  uint16)
IMPLEMENT_READER(Int16,   int16)
IMPLEMENT_READER(UInt32,  uint32)
IMPLEMENT_READER(Int32,   int32)
IMPLEMENT_READER(UInt64,  uint64)
IMPLEMENT_READER(Int64,   int64)
IMPLEMENT_READER(Float32, float32)
IMPLEMENT_READER(Float64, float64)    

#undef IMPLEMENT_READER

void BinaryInput::loadIntoMemory(int64 startPosition, int64 minLength) {
    // Load the next section of the file
    debugAssertM(m_filename != "<memory>", "Read past end of file.");

    int64 absPos = m_alreadyRead + m_pos;

    if (m_bufferLength < minLength) {
        // The current buffer isn't big enough to hold the chunk we want to read.
        // This happens if there was little memory available during the initial constructor
        // read but more memory has since been freed.
        m_bufferLength = minLength;
        debugAssert(m_freeBuffer);
        m_buffer = (uint8*)System::realloc(m_buffer, m_bufferLength);
        if (m_buffer == NULL) {
            throw "Tried to read a larger memory chunk than could fit in memory. (2)";
        }
    }

    m_alreadyRead = startPosition;

#   ifdef G3D_WIN32
        FILE* file = fopen(m_filename.c_str(), "rb");
        debugAssert(file);
        int ret = fseek(file, (off_t)m_alreadyRead, SEEK_SET);
        debugAssert(ret == 0);
        size_t toRead = (size_t)G3D::min(m_bufferLength, m_length - m_alreadyRead);
        ret = fread(m_buffer, 1, toRead, file);
        debugAssert(ret == toRead);
        fclose(file);
        file = NULL;
    
#   else
        FILE* file = fopen(m_filename.c_str(), "rb");
        debugAssert(file);
        int ret = fseeko(file, (off_t)m_alreadyRead, SEEK_SET);
        debugAssert(ret == 0);
        size_t toRead = (size_t)G3D::min<int64>(m_bufferLength, m_length - m_alreadyRead);
        ret = fread(m_buffer, 1, toRead, file);
        debugAssert((size_t)ret == (size_t)toRead);
        fclose(file);
        file = NULL;
#   endif

    m_pos = absPos - m_alreadyRead;
    debugAssert(m_pos >= 0);
}



const bool BinaryInput::NO_COPY = false;
    
static bool needSwapBytes(G3DEndian fileEndian) {
    return (fileEndian != System::machineEndian());
}


/** Helper used by the constructors for decompression */
static uint32 readUInt32(const uint8* data, bool swapBytes) {
    if (swapBytes) {
        uint8 out[4];
        out[0] = data[3];
        out[1] = data[2];
        out[2] = data[1];
        out[3] = data[0];
        return *((uint32*)out);
    } else {
        return *((uint32*)data);
    }
}


void BinaryInput::setEndian(G3DEndian e) {
    m_fileEndian = e;
    m_swapBytes = needSwapBytes(m_fileEndian);
}


BinaryInput::BinaryInput(
    const uint8*        data,
    int64               dataLen,
    G3DEndian           dataEndian,
    bool                compressed,
    bool                copyMemory) :
    m_filename("<memory>"),
    m_bitPos(0),
    m_bitString(0),
    m_beginEndBits(0),
    m_alreadyRead(0),
    m_bufferLength(0),
    m_pos(0) {

    m_freeBuffer = copyMemory || compressed;

    setEndian(dataEndian);

    if (compressed) {
        // Read the decompressed size from the first 4 bytes
        m_length = G3D::readUInt32(data, m_swapBytes);

        debugAssert(m_freeBuffer);
        m_buffer = (uint8*)System::alignedMalloc(m_length, 16);

        unsigned long L = m_length;
        // Decompress with zlib
        int64 result = uncompress(m_buffer, (unsigned long*)&L, data + 4, dataLen - 4);
        m_length = L;
        m_bufferLength = L;
        debugAssert(result == Z_OK); (void)result;

    } else {
    	m_length = dataLen;
        m_bufferLength = m_length;
        if (! copyMemory) {
 	        debugAssert(!m_freeBuffer);
            m_buffer = const_cast<uint8*>(data);
        } else {
	        debugAssert(m_freeBuffer);
            m_buffer = (uint8*)System::alignedMalloc(m_length, 16);
            System::memcpy(m_buffer, data, dataLen);
        }
    }
}


BinaryInput::BinaryInput(
    const std::string&  filename,
    G3DEndian           fileEndian,
    bool                compressed) :
    m_filename(filename),
    m_bitPos(0),
    m_bitString(0),
    m_beginEndBits(0),
    m_alreadyRead(0),
    m_length(0),
    m_bufferLength(0),
    m_buffer(NULL),
    m_pos(0),
    m_freeBuffer(true) {

    setEndian(fileEndian);

    // Update global file tracker
    _internal::currentFilesUsed.insert(m_filename);
    

    if (! fileExists(m_filename, false)) {
        std::string zipfile;
        std::string internalfile;
        if (zipfileExists(m_filename, zipfile, internalfile)) {
            // Load from zipfile
            void* v;
            size_t s;
            zipRead(filename, v, s);
            m_buffer = reinterpret_cast<uint8*>(v);
            m_bufferLength = m_length = s;
            if (compressed) {
                decompress();
            }
            m_freeBuffer = true;
        } else {
            Log::common()->printf("Warning: File not found: %s\n", m_filename.c_str());
        }
        return;
    }

    // Figure out how big the file is and verify that it exists.
    m_length = fileLength(m_filename);

    // Read the file into memory
    FILE* file = fopen(m_filename.c_str(), "rb");

    if (! file || (m_length == -1)) {
        throw format("File not found: \"%s\"", m_filename.c_str());
        return;
    }

    if (! compressed && (m_length > INITIAL_BUFFER_LENGTH)) {
        // Read only a subset of the file so we don't consume
        // all available memory.
        m_bufferLength = INITIAL_BUFFER_LENGTH;
    } else {
        // Either the length is fine or the file is compressed
        // and requires us to read the whole thing for zlib.
        m_bufferLength = m_length;
    }

    debugAssert(m_freeBuffer);
    m_buffer = (uint8*)System::alignedMalloc(m_bufferLength, 16);
    if (m_buffer == NULL) {
        if (compressed) {
            throw "Not enough memory to load compressed file. (1)";
        }
        
        // Try to allocate a small array; not much memory is available.
        // Give up if we can't allocate even 1k.
        while ((m_buffer == NULL) && (m_bufferLength > 1024)) {
            m_bufferLength /= 2;
            m_buffer = (uint8*)System::alignedMalloc(m_bufferLength, 16);
        }
    }
    debugAssert(m_buffer);
    
    fread(m_buffer, m_bufferLength, sizeof(int8), file);
    fclose(file);
    file = NULL;

    if (compressed) {
        if (m_bufferLength != m_length) {
            throw "Not enough memory to load compressed file. (2)";
        }

        decompress();
    }
}

void BinaryInput::decompress() {
    // Decompress
    // Use the existing buffer as the source, allocate
    // a new buffer to use as the destination.
    
    int64 tempLength = m_length;
    m_length = G3D::readUInt32(m_buffer, m_swapBytes);
    
    // The file couldn't have better than 500:1 compression
    alwaysAssertM(m_length < m_bufferLength * 500, "Compressed file header is corrupted");
    
    uint8* tempBuffer = m_buffer;
    m_buffer = (uint8*)System::alignedMalloc(m_length, 16);
    
    debugAssert(m_buffer);
    debugAssert(isValidHeapPointer(tempBuffer));
    debugAssert(isValidHeapPointer(m_buffer));
    
    unsigned long L = m_length;
    int64 result = uncompress(m_buffer, &L, tempBuffer + 4, tempLength - 4);
    m_length = L;
    m_bufferLength = m_length;
    
    debugAssertM(result == Z_OK, "BinaryInput/zlib detected corruption in " + m_filename); 
    (void)result;
    
    System::alignedFree(tempBuffer);
}


void BinaryInput::readBytes(void* bytes, int64 n) {
    prepareToRead(n);
    debugAssert(isValidPointer(bytes));

    memcpy(bytes, m_buffer + m_pos, n);
    m_pos += n;
}


BinaryInput::~BinaryInput() {

    if (m_freeBuffer) {
        System::alignedFree(m_buffer);
    }
    m_buffer = NULL;
}


uint64 BinaryInput::readUInt64() {
    prepareToRead(8);
    uint8 out[8];

    if (m_swapBytes) {
        out[0] = m_buffer[m_pos + 7];
        out[1] = m_buffer[m_pos + 6];
        out[2] = m_buffer[m_pos + 5];
        out[3] = m_buffer[m_pos + 4];
        out[4] = m_buffer[m_pos + 3];
        out[5] = m_buffer[m_pos + 2];
        out[6] = m_buffer[m_pos + 1];
        out[7] = m_buffer[m_pos + 0];
    } else {
        *(uint64*)out = *(uint64*)(m_buffer + m_pos);
    }

    m_pos += 8;
    return *(uint64*)out;
}


std::string BinaryInput::readString(int64 n) {
    prepareToRead(n);
    debugAssertM((m_pos + n) <= m_length, "Read past end of file");
    
    char *s = (char*)System::alignedMalloc(n + 1, 16);
    assert(s != NULL);

    memcpy(s, m_buffer + m_pos, n);
    // There may not be a null, so make sure
    // we add one.
    s[n] = '\0';

    std::string out = s;
    System::alignedFree(s);
    s = NULL;

    m_pos += n;

    return out;

}


std::string BinaryInput::readString() {
    int64 n = 0;

    if ((m_pos + m_alreadyRead + n) < (m_length - 1)) {
        prepareToRead(1);
    }

    if ( ((m_pos + m_alreadyRead + n) < (m_length - 1)) &&
         (m_buffer[m_pos + n] != '\0')) {

        ++n;
        while ( ((m_pos + m_alreadyRead + n) < (m_length - 1)) &&
                (m_buffer[m_pos + n] != '\0')) {

            prepareToRead(1);
            ++n;
        }
    }

    // Consume NULL
    ++n;

    return readString(n);
}


std::string BinaryInput::readStringEven() {
    std::string x = readString();
    if (hasMore() && (G3D::isOdd(x.length() + 1))) {
        skip(1);
    }
    return x;
}


std::string BinaryInput::readString32() {
    int len = readUInt32();
    return readString(len);
}


Vector4 BinaryInput::readVector4() {
    float x = readFloat32();
    float y = readFloat32();
    float z = readFloat32();
    float w = readFloat32();
    return Vector4(x, y, z, w);
}


Vector3 BinaryInput::readVector3() {
    float x = readFloat32();
    float y = readFloat32();
    float z = readFloat32();
    return Vector3(x, y, z);
}


Vector2 BinaryInput::readVector2() {
    float x = readFloat32();
    float y = readFloat32();
    return Vector2(x, y);
}


Color4 BinaryInput::readColor4() {
    float r = readFloat32();
    float g = readFloat32();
    float b = readFloat32();
    float a = readFloat32();
    return Color4(r, g, b, a);
}


Color3 BinaryInput::readColor3() {
    float r = readFloat32();
    float g = readFloat32();
    float b = readFloat32();
    return Color3(r, g, b);
}


void BinaryInput::beginBits() {
    debugAssert(m_beginEndBits == 0);
    m_beginEndBits = 1;
    m_bitPos = 0;

    debugAssertM(hasMore(), "Can't call beginBits when at the end of a file");
    m_bitString = readUInt8();
}


uint32 BinaryInput::readBits(int numBits) {
    debugAssert(m_beginEndBits == 1);

    uint32 out = 0;

    const int total = numBits;
    while (numBits > 0) {
        if (m_bitPos > 7) {
            // Consume a new byte for reading.  We do this at the beginning
            // of the loop so that we don't try to read past the end of the file.
            m_bitPos = 0;
            m_bitString = readUInt8();
        }

        // Slide the lowest bit of the bitString into
        // the correct position.
        out |= (m_bitString & 1) << (total - numBits);

        // Shift over to the next bit
        m_bitString = m_bitString >> 1;
        ++m_bitPos;
        --numBits;
    }

    return out;
}


void BinaryInput::endBits() {
    debugAssert(m_beginEndBits == 1);
    if (m_bitPos == 0) {
        // Put back the last byte we read
        --m_pos;
    }
    m_beginEndBits = 0;
    m_bitPos = 0;
}

}
