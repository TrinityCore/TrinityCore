/**
 @file uint128.cpp
 
 @maintainer Morgan McGuire, http://graphics.cs.williams.edu
 @author Kyle Whitson
 
 @created 2008-07-17
 @edited  2008-07-17
 */

#include "G3D/uint128.h"

namespace G3D {

/** Adds two 64-bit integers, placing the result and the overflow into 64-bit integers.*/
static void addAndCarry(const uint64& _a, const uint64& _b, uint64& carry, uint64& result) {
        
    // Break each number into 4 32-bit chunks. Since we are using uints, right-shifting will fill with zeros.
    // This eliminates the need to and with 0xFFFFFFFF.
    uint32 a [2] = {_a & 0xFFFFFFFF, _a >> 32};
    uint32 b [2] = {_b & 0xFFFFFFFF, _b >> 32};

    uint64 tmp = uint64(a[0]) + b[0];

    result = tmp & 0xFFFFFFFF;
    uint32 c = tmp >> 32;

    tmp = uint64(c) + a[1] + b[1];
    result += tmp << 32;
    carry = (tmp >> 32);
}

/** Multiplies two unsigned 64-bit integers, placing the result into one 64-bit int and the overflow into another.*/
void multiplyAndCarry(const uint64& _a, const uint64& _b, uint64& carry, uint64& result) {

    // Break each number into 4 32-bit chunks. Since we are using uints, right-shifting will fill with zeros.
    // This eliminates the need to and with 0xFFFFFFFF.
    uint32 a [2] = {_a & 0xFFFFFFFF, _a >> 32};
    uint32 b [2] = {_b & 0xFFFFFFFF, _b >> 32};

    uint64 prod [2][2];
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
            prod[i][j] = uint64(a[i]) * b[j];
        }
    }

    // The product of the low bits of a and b will always fit into the result
    result = prod[0][0];

    // The product of the high bits of a and b will never fit into the result
    carry = prod[1][1];

    // The high 32 bits of prod[0][1] and prod[1][0] will never fit into the result
    carry += prod[0][1] >> 32;
    carry += prod[1][0] >> 32;

    uint64 tmp;
    addAndCarry(result, (prod[0][1] << 32), tmp, result);
    carry += tmp;
    addAndCarry(result, (prod[1][0] << 32), tmp, result);
    carry += tmp;
}


uint128::uint128(const uint64& hi, const uint64& lo) : hi(hi), lo(lo) {
}

uint128::uint128(const uint64& lo) : hi(0), lo(lo) {
}

uint128& uint128::operator+=(const uint128& x) {

    G3D::uint64 carry;
    addAndCarry(lo, x.lo, carry, lo);

    // Adding the carry will change hi. Save the old hi bits in case this == x.
    const uint64 xHi = x.hi;
    hi += carry;
    hi += xHi;
    return *this;
}

uint128& uint128::operator*=(const uint128& x) {

    // The low bits will get overwritten when doing the multiply, so back up both (in case &x == this)
    const uint64 oldLo = lo;
    const uint64 oldXLo = x.lo;

    G3D::uint64 carry;
    multiplyAndCarry(oldLo, oldXLo, carry, lo);

    // Overflow doesn't matter here because the result is going into hi - any overflow will exceed the capacity of a 128-bit number
    // Note: hi * x.hi will always overflow, since (x * 2^64) * (y * 2^64) = x*y*(2^128). The largest number expressable in 128 bits is
    // 2^128 - 1.
    hi = carry + (oldLo * x.hi) + (hi * oldXLo);

    return *this;
}

uint128& uint128::operator^=(const uint128& x) {
    hi ^= x.hi;
    lo ^= x.lo;
    return *this;
}

uint128& uint128::operator&=(const uint128& x) {
    hi &= x.hi;
    lo &= x.lo;
    return *this;
}

uint128& uint128::operator|=(const uint128& x) {
    hi |= x.hi;
    lo |= x.lo;
    return *this;
}

bool uint128::operator==(const uint128& x) {
    return (hi == x.hi) && (lo == x.lo);
}

uint128& uint128::operator>>=(const int x) {

    //Before shifting, mask out the bits that will be shifted out of hi.
    //Put a 1 in the first bit that will not be lost in the shift, then subtract 1 to get the mask.
    uint64 mask = ((uint64)1L << x) - 1;
    uint64 tmp = hi & mask;
    hi >>= x;

    //Shift lo and add the bits shifted down from hi
    lo = (lo >> x) + (tmp << (64 - x));
    
    return *this;
}

uint128& uint128::operator<<=(const int x) {

    //Before shifting, mask out the bits that will be shifted out of lo.
    //Put a 1 in the last bit that will be lost in the shift, then subtract 1 to get the logical inverse of the mask.
    //A bitwise NOT will then produce the correct mask.
    uint64 mask = ~((((uint64)1L) << (64 - x)) - 1);
    uint64 tmp = lo & mask;
    lo <<= x;

    //Shift hi and add the bits shifted up from lo
    hi = (hi << x) + (tmp >> (64 - x));
    
    return *this;
}

uint128 uint128::operator&(const uint128& x) {
    return uint128(hi & x.hi, lo & x.lo);
}
}
