/**
  @file GUniqueID.cpp
  @author Morgan McGuire, http://graphics.cs.williams.edu
 */
#include "G3D/GUniqueID.h"
#include "G3D/BinaryInput.h"
#include "G3D/TextInput.h"
#include "G3D/BinaryOutput.h"
#include "G3D/TextOutput.h"
#include "G3D/NetworkDevice.h"
#include "G3D/Any.h"

namespace G3D {
    
GUniqueID& GUniqueID::operator=(const Any& a) {
    a.verifyName("GUniqueID");
    a.verifyType(Any::ARRAY);
    a.verifySize(1);
    std::string s = a[0];
    a.verify(s.length() == 16);
    id = GUniqueID::fromString16(s);
    return *this;
}


Any GUniqueID::toAny() const {
    Any a(Any::ARRAY, "GUniqueID");
    a.append(toString16());
    return a;
}


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


GUniqueID GUniqueID::NONE(uint16 tag) {
    GUniqueID i;
    uint64 t = tag;
    i.id = (t << 54);
    return i;
}


std::string GUniqueID::toString16() const {
    return format("%08x%08x", uint32(id >> 32), uint32(id & 0xFFFFFFFF));
}


GUniqueID GUniqueID::fromString16(const std::string& s) {
    if (s.length() != 16) {
        debugAssertM(false, "Corrupt 16-character string");
        return GUniqueID();
    }
    
    uint32 high = 0, low = 0;
    sscanf(s.c_str(), "%08x%08x", &high, &low);
    GUniqueID i;
    i.id = (uint64(high) << 32) | low;
    return i;
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
