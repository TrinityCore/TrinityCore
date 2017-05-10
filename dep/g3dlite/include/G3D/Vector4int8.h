/**
  @file Vector4int8.h
 
  Homogeneous vector class.

  @maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
  @created 2007-02-09
  @edited  2007-02-09

  Copyright 2000-2007, Morgan McGuire.
  All rights reserved.
 */

#ifndef G3D_VECTOR4INT8_H
#define G3D_VECTOR4INT8_H

#include "G3D/platform.h"
#include "G3D/g3dmath.h"

namespace G3D {

class Vector3;
class Vector4;

/**
 Homogeneous vector stored efficiently in four signed int8s.

 */
class Vector4int8 {
private:
    // Hidden operators
    bool operator<(const Vector4int8&) const;
    bool operator>(const Vector4int8&) const;
    bool operator<=(const Vector4int8&) const;
    bool operator>=(const Vector4int8&) const;

  
    /** For fast operations, treat this packed data structure as 
      an int32 */
    inline uint32& asInt32() {
        return *reinterpret_cast<uint32*>(this);
    }

    inline const uint32& asInt32() const {
        return *reinterpret_cast<const uint32*>(this);
    }

public:
    // construction
    inline Vector4int8() : x(0), y(0), z(0), w(0) {}
    
    /** Multiplies the source by 127 and clamps to (-128, 127) when converting */
    explicit Vector4int8(const Vector4& source);

    /** Multiplies the source by 127 and clamps to (-128, 127) when converting */
    explicit Vector4int8(const Vector3& source, int8 w);

    inline Vector4int8(int8 x, int8 y, int8 z, int8 w) : x(x), y(y), z(z), w(w) {}

    explicit Vector4int8(class BinaryInput& b);
    void serialize(class BinaryOutput& b) const;
    void deserialize(class BinaryInput& b);

    // coordinates
    int8 x, y, z, w;

    inline operator int8* () {
        return reinterpret_cast<int8*>(this);
    }

    inline operator const int8* () const {
        return reinterpret_cast<const int8*>(this);
    }

    // access vector V as V[0] = V.x, V[1] = V.y, V[2] = V.z, etc.
    //
    // WARNING.  These member functions rely on
    // (1) Vector4int8 not having virtual functions
    // (2) the data packed in a 4*sizeof(int8) memory block
    inline int8& operator[] (int i) {
        debugAssert(i >= 0 && i <= 4);
        return ((int8*)this)[i];
    }

    const int8& operator[] (int i) const {
        debugAssert(i >= 0 && i <= 4);
        return ((const int8*)this)[i];
    }

    // assignment and comparison
    Vector4int8& operator= (const Vector4int8& other) {
        asInt32() = other.asInt32();
        return *this;
    }

    inline bool operator== (const Vector4int8& other) const {
        return asInt32() == other.asInt32();
    }

    inline bool operator!= (const Vector4int8& other) const {
        return ! (*this == other);
    }

    inline unsigned int hashCode() const {
        return asInt32();
    }
};

} // namespace G3D


#endif
