/**
  \file G3D/GUniqueID.h
  \author Morgan McGuire, http://graphics.cs.williams.edu
 */
#ifndef G3D_GUniqueID_h
#define G3D_GUniqueID_h

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include "G3D/Table.h"

namespace G3D {
     
class Any;
    
/** Globally unique identifiers. The probability of two different
    programs generating the same value from UniqueID::create is
    vanishingly small.
    
    UniqueIDs optionally contain a 10-bit application specific tag
    that distinguishes their type.
*/
class GUniqueID {
private:

    uint64 id;

public:

    /** \sa create */
    GUniqueID() : id(0) {}

    GUniqueID& operator=(const Any& a);

    /** \sa create */
    GUniqueID(const Any& a) {
        *this = a;
    }

    Any toAny() const;

    /** Returns a 16-character string equivalent to this GUniqueID's uint64 value. */
    std::string toString16() const;

    static GUniqueID fromString16(const std::string& s);

    /** Returns the ID that has the specified tag (so that it is not uninitialized), but
        which is a common sentinel "none" value. */
    static GUniqueID NONE(uint16 tag);

    bool uninitialized() const {
        return id == 0;
    }

    uint16 tag() const {
        return id >> 54;
    }

    operator uint64() const {
        return id;
    }    

    bool operator==(const GUniqueID& other) const {
        return id == other.id;
    }

    bool operator!=(const GUniqueID& other) const {
        return id != other.id;
    }

    void serialize(class BinaryOutput& b) const;

    void deserialize(class BinaryInput& b);

    void serialize(class TextOutput& t) const;

    void deserialize(class TextInput& t);

    /** Create a new ID */
    static GUniqueID create(uint16 tag = 0);
};

} // G3D 

/** For Table and Set */
template<> struct HashTrait<class G3D::GUniqueID> {
    static size_t hashCode(G3D::GUniqueID id) { return (size_t)(G3D::uint64)id; }
};

#endif
