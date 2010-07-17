#ifndef G3D_SERIALIZE_H
#define G3D_SERIALIZE_H

#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"
#include "G3D/Array.h"

namespace G3D {

 
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

}

#endif
