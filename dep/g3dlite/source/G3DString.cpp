#include "G3D/G3DString.h"
#include "G3D/g3dmath.h"

namespace G3D {

static const char* testStr = "__HackString.h__";
static const uintptr_t PROBED_CONST_SEG_ADDR = uintptr_t(testStr);

#ifdef G3D_WINDOWS
#define abs _abs64
#endif

bool inConstSegment(const char* c) {
#   if defined(G3D_64BIT) && _MSC_VER
        // MSVC assigns the const_seg to very high addresses that are grouped together
        //return uintptr_t(c) >= MIN_CONST_SEG_ADDR;
        return (abs(int64(uintptr_t(c) - PROBED_CONST_SEG_ADDR)) < int64(50000000));
#   else
        return false;
#   endif
    (void)PROBED_CONST_SEG_ADDR;
}
}
