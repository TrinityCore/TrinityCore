/**
  \file G3D/Vector2unorm16.h
  
  \maintainer Morgan McGuire, morgan@cs.williams.edu

  \created 2003-03-13
  \edited  2012-03-13

  Copyright 2000-2012, Morgan McGuire.
  All rights reserved.
 */

#ifndef Vector2unorm16_h
#define Vector2unorm16_h

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include "G3D/HashTrait.h"
#include "G3D/unorm16.h"

namespace G3D {

class Any;
/**
 \class Vector2unorm16 

 A Vector2 that packs its fields into G3D::unorm16%s. This is mostly
 useful for texture coordinates that are on the range [0, 1].

 \sa Vector2int16
 */
G3D_BEGIN_PACKED_CLASS(2)
Vector2unorm16 {
private:
    // Hidden operators
    bool operator<(const Vector2unorm16&) const;
    bool operator>(const Vector2unorm16&) const;
    bool operator<=(const Vector2unorm16&) const;
    bool operator>=(const Vector2unorm16&) const;

public:
    G3D::unorm16              x;
    G3D::unorm16              y;

    Vector2unorm16() {}
    Vector2unorm16(G3D::unorm16 _x, G3D::unorm16 _y) : x(_x), y(_y){}
    Vector2unorm16(float _x, float _y) : x(_x), y(_y){}
    explicit Vector2unorm16(const class Vector2& v);
    explicit Vector2unorm16(class BinaryInput& bi);
    explicit Vector2unorm16(const class Any& a);

    Any toAny() const;
    
    Vector2unorm16& operator=(const Any& a);

    inline G3D::unorm16& operator[] (int i) {
        debugAssert(((unsigned int)i) <= 1);
        return ((G3D::unorm16*)this)[i];
    }

    inline const G3D::unorm16& operator[] (int i) const {
        debugAssert(((unsigned int)i) <= 1);
        return ((G3D::unorm16*)this)[i];
    }

    inline bool operator== (const Vector2unorm16& rkVector) const {
        return ((int32*)this)[0] == ((int32*)&rkVector)[0];
    }

    inline bool operator!= (const Vector2unorm16& rkVector) const {
        return ((int32*)this)[0] != ((int32*)&rkVector)[0];
    }

    void serialize(class BinaryOutput& bo) const;
    void deserialize(class BinaryInput& bi);
    size_t hashCode() const {
        return static_cast<size_t>(x.bits() + ((int)y.bits() << 16));
    }

}
G3D_END_PACKED_CLASS(2)

typedef Vector2unorm16 Point2unorm16;    

}

template<> struct HashTrait<G3D::Vector2unorm16> {
    static size_t hashCode(const G3D::Vector2unorm16& key) { return key.hashCode(); }
};

#endif
