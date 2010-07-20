/**
  Quat.inl

  @cite Quaternion implementation based on Watt & Watt page 363.
  Thanks to Max McGuire for slerp optimizations.

  @maintainer Morgan McGuire, matrix@graphics3d.com

  @created 2002-01-23
  @edited  2004-03-04
 */

namespace G3D {

inline float& Quat::operator[] (int i) {
    debugAssert(i >= 0);
    debugAssert(i < 4);
    return ((float*)this)[i];
}

inline const float& Quat::operator[] (int i) const {
    debugAssert(i >= 0);
    debugAssert(i < 4);
    return ((float*)this)[i];
}

inline Quat Quat::operator-(const Quat& other) const {
    return Quat(x - other.x, y - other.y, z - other.z, w - other.w);
}

inline Quat Quat::operator+(const Quat& other) const {
    return Quat(x + other.x, y + other.y, z + other.z, w + other.w);
}

}

