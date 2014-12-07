#include "G3D/G3DAllocator.h"
#include "G3D/System.h"

namespace G3D {
namespace _internal {

void* systemMalloc(size_t bytes) {
    return System::malloc(bytes);
}
void systemFree(void* p) {
    System::free(p);
}

} // namespace _internal
} // namespace G3D
