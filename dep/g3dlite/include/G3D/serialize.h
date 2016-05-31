#ifndef G3D_serialize_h
#define G3D_serialize_h

#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"
#include "G3D/Array.h"
#include <string>

namespace G3D {
    

inline void serialize(const std::string& s, BinaryOutput& b) {
    b.writeString32(s);
}

inline void deserialize(std::string& s, BinaryInput& b) {
    s = b.readString32();
}

inline void serialize(const int32& i, BinaryOutput& b) {
    b.writeInt32(i);
}

inline void deserialize(int32& i, BinaryInput& b) {
    i = b.readInt32();
}

inline void serialize(const uint32& i, BinaryOutput& b) {
    b.writeUInt32(i);
}

inline void deserialize(uint32& i, BinaryInput& b) {
    i = b.readUInt32();
}

inline void serialize(const bool& i, BinaryOutput& b) {
    b.writeBool8(i);
}

inline void deserialize(bool& i, BinaryInput& b) {
    i = b.readBool8();
}

inline void serialize(const float32& f, BinaryOutput& b) {
    b.writeFloat32(f);
}

inline void deserialize(float32& f, BinaryInput& b) {
    f = b.readFloat32();
}

inline void serialize(const float64& f, BinaryOutput& b) {
    b.writeFloat64(f);
}

inline void deserialize(float64& f, BinaryInput& b) {
    f = b.readFloat64();
}

/** serialize(const T&, BinaryOutput&) must have been overridden as well */
template<typename T> 
void serialize(const Array<T>& array, BinaryOutput& b) { 
    b.writeInt32(array.size()); 
    for (int i = 0; i < array.size(); ++i) { 
        serialize(array[i], b); 
    } 
}

template<typename T> 
void deserialize(Array<T>& array, BinaryInput& b) { 
    int N = b.readInt32();
    array.resize(N);
    for (int i = 0; i < array.size(); ++i) { 
        deserialize(array[i], b); 
    }
}

} // G3D

#endif //G3D_serialize_h
