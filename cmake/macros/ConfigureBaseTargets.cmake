# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

# An interface library to make the target com available to other targets
add_library(trinity-compile-option-interface INTERFACE)

# Use -std=c++11 instead of -std=gnu++11
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 20)

# Set build-directive (used in core to tell which buildtype we used)
target_compile_definitions(trinity-compile-option-interface
  INTERFACE
    -D_BUILD_DIRECTIVE="$<CONFIG>")

# An interface library to make the target features available to other targets
add_library(trinity-feature-interface INTERFACE)

# An interface library to make the warnings level available to other targets
# This interface taget is set-up through the platform specific script
add_library(trinity-warning-interface INTERFACE)

# An interface used for all other interfaces
add_library(trinity-default-interface INTERFACE)
target_link_libraries(trinity-default-interface
  INTERFACE
    trinity-compile-option-interface
    trinity-feature-interface)

# An interface used for silencing all warnings
add_library(trinity-no-warning-interface INTERFACE)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(trinity-no-warning-interface
    INTERFACE
      /W0)
else()
  target_compile_options(trinity-no-warning-interface
    INTERFACE
      -w)
endif()

# An interface library to change the default behaviour
# to hide symbols automatically.
add_library(trinity-hidden-symbols-interface INTERFACE)

# An interface amalgamation which provides the flags and definitions
# used by the dependency targets.
add_library(trinity-dependency-interface INTERFACE)
target_link_libraries(trinity-dependency-interface
  INTERFACE
    trinity-default-interface
    trinity-no-warning-interface
    trinity-hidden-symbols-interface)

# An interface amalgamation which provides the flags and definitions
# used by the core targets.
add_library(trinity-core-interface INTERFACE)
target_link_libraries(trinity-core-interface
  INTERFACE
    trinity-default-interface
    trinity-warning-interface)
