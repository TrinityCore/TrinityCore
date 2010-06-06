/**
 @file BinaryFormat.cpp
  @maintainer Morgan McGuire, matrix@graphics3d.com

  @created 2005-06-10
  @edited  2005-06-10
 */

#include "G3D/BinaryFormat.h"

namespace G3D {

int32 byteSize(BinaryFormat f) {
    switch (f) {
    case BOOL8_BINFMT:
    case UINT8_BINFMT:
    case INT8_BINFMT:
        return 1;

    case UINT16_BINFMT:
    case INT16_BINFMT:
        return 2;

    case FLOAT16_BINFMT:
        return 2;

    case UINT32_BINFMT:
    case INT32_BINFMT:
    case FLOAT32_BINFMT:
        return 4;

    case FLOAT64_BINFMT:
    case UINT64_BINFMT:
    case INT64_BINFMT:
        return 8;

    case INT128_BINFMT:
    case UINT128_BINFMT:
        return 16;

    case VECTOR2_BINFMT:
        return 2 * 4;

    case VECTOR2INT16_BINFMT:
        return 2 * 2;

    case VECTOR3_BINFMT:
        return 3 * 4;

    case VECTOR3INT16_BINFMT:
        return 3 * 2;

    case VECTOR4_BINFMT:
        return 4 * 4;

    case VECTOR4INT16_BINFMT:
        return 4 * 4;

    case COLOR3_BINFMT:
        return 3 * 4;

    case COLOR3UINT8_BINFMT:
        return 3 * 1;

    case COLOR3INT16_BINFMT:
        return 3 * 2;

    case COLOR4_BINFMT:
        return 4 * 4;

    case COLOR4UINT8_BINFMT:
        return 4 * 1;

    case COLOR4INT16_BINFMT:
        return 4 * 2;

    default:
        return -1;
    }
}
}
