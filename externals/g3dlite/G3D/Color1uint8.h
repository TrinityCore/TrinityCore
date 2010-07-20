/** 
  @file Color1uint8.h
 
  @maintainer Morgan McGuire, graphics3d.com
 
  @created 2007-01-30
  @edited  2007-01-30

  Copyright 2000-2007, Morgan McGuire.
  All rights reserved.
 */

#ifndef G3D_COLOR1UINT8_H
#define G3D_COLOR1UINT8_H

#include "G3D/platform.h"
#include "G3D/g3dmath.h"

namespace G3D {

/**
 Represents a Color1 as a packed integer.  Convenient
 for creating unsigned int vertex arrays. 

 <B>WARNING</B>: Integer color formats are different than
 integer vertex formats.  The color channels are automatically
 scaled by 255 (because OpenGL automatically scales integer
 colors back by this factor).  So Color3(1,1,1) == Color3uint8(255,255,255)
 but Vector3(1,1,1) == Vector3int16(1,1,1).

 <B>Note</B>:
 Conversion of a float32 to uint8 is accomplished by min(iFloor(f * 256)) and 
 back to float32 by u / 255.0f.  This gives equal size intervals.
Consider a number line from 0 to 1 and a corresponding one from 0 to 255.  If we use iRound(x * 255), then the mapping for three critical intervals are:

<pre>
let s = 0.5/255
  float             int       size
[0, s)           -> 0          s
[s, s * 3)       -> 1         2*s
(1 - s, 1]       -> 255        s
</pre>

If we use max(floor(x * 256), 255), then we get:

<pre>
let s = 1/256
  float             int           size
[0, s)           -> 0               s
[s, 2 * s)       -> 1               s
(1 - s, 1]       -> 255             s
</PRE>
and the intervals are all the same size, thus giving equal precision to all values.
 */
G3D_BEGIN_PACKED_CLASS(1)
class Color1uint8 {
private:
    // Hidden operators
    bool operator<(const Color1uint8&) const;
    bool operator>(const Color1uint8&) const;
    bool operator<=(const Color1uint8&) const;
    bool operator>=(const Color1uint8&) const;

public:

    uint8       value;

    Color1uint8() : value(0) {}

    explicit Color1uint8(const uint8 _v) : value(_v) {}

    Color1uint8(const class Color1& c);

    Color1uint8(class BinaryInput& bi);

    void serialize(class BinaryOutput& bo) const;

    void deserialize(class BinaryInput& bi);

    inline bool operator==(const Color1uint8& other) const {
        return value == other.value;
    }

    inline bool operator!=(const Color1uint8& other) const {
        return value != other.value;
    }

}
G3D_END_PACKED_CLASS(1)
}
#endif
