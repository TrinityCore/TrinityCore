/**
   \file initG3D.cpp
 */
#include <stdlib.h>
#include "G3D/platform.h"
#include "G3D/System.h"

namespace G3D {

namespace _internal {

    G3DSpecification& g3dInitializationSpecification() {
        static G3DSpecification s;
        return s;
    }

    void initializeNetwork();
    void cleanupNetwork();
}

static void G3DCleanupHook() {
    _internal::cleanupNetwork();
    System::cleanup();
}

void initG3D(const G3DSpecification& spec) {
    static bool initialized = false;
    
    if (! initialized) {
        initialized = true;
        _internal::g3dInitializationSpecification() = spec;
        atexit(&G3DCleanupHook);
        
        // Trigger a call to System::init
        System::cpuSpeedMHz();

        _internal::initializeNetwork();
    }
}

} // namespace
