/**
  @file GUniqueID.cpp
  @author Morgan McGuire, morgan@cs.williams.edu
 */
#include "G3D/GUniqueID.h"
#include "G3D/BinaryInput.h"
#include "G3D/TextInput.h"
#include "G3D/BinaryOutput.h"
#include "G3D/TextOutput.h"
#include "G3D/NetworkDevice.h"

namespace G3D {

void GUniqueID::serialize(BinaryOutput& b) const {
    b.writeUInt64(id);
}


void GUniqueID::deserialize(BinaryInput& b) {
    id = b.readUInt64();
}

void GUniqueID::serialize(TextOutput& t) const {
    t.writeSymbol("(");
    t.writeNumber((double)(id >> 32));
    t.writeNumber((double)(id & 0xFFFFFFFF));
    t.writeSymbol(")");
}

void GUniqueID::deserialize(TextInput& t) {
    t.readSymbol("(");
    id = (((uint64)t.readNumber()) << 32) + (uint64)t.readNumber();
    t.readSymbol(")");
}


GUniqueID GUniqueID::create(uint16 tag) {
    static uint64 counter = 0;
    static uint64 systemID = 0;
    
    if (systemID == 0) {
        // Create a unique ID for this machine/program instance
        
        // TODO: see ioctl(skfd, SIOCGIFHWADDR, &if_hwaddr)
        Array<NetAddress> addr;
        NetworkDevice::instance()->localHostAddresses(addr);
        if (addr.size() > 0) {
            systemID |= addr[0].ip();
        }
        
        union {
            float64 ft;
            uint64 ut;
        };
        ft = System::time();
        systemID = ut << 22;
        systemID ^= ((uint64)iRandom(0, 32768)) << 8;
        
        systemID &= ~((uint64)1023 << 54);

        // Ensure that the systemID is non-zero (vanishingly small probability)
        if (systemID == 0) {
            systemID = 1;
        }
    }
    
    // No need for modulo; we'll all be dead before this counter
    // overflows 54 bits
    ++counter;
    
    GUniqueID i;
    
    i.id = (((uint64)(tag & 1023)) << 54) | (counter ^ systemID);
    
    return i;
}

} // G3D 
