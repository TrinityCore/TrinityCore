# This file is part of the KitronCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

# An interface library to make the target com available to other targets
add_library(Kitron-compile-option-interface INTERFACE)

# Use -std=c++11 instead of -std=gnu++11
set(CXX_EXTENSIONS OFF)

# An interface library to make the target features available to other targets
add_library(Kitron-feature-interface INTERFACE)

target_compile_features(Kitron-feature-interface
  INTERFACE
    cxx_std_17)

# An interface library to make the warnings level available to other targets
# This interface taget is set-up through the platform specific script
add_library(Kitron-warning-interface INTERFACE)

# An interface used for all other interfaces
add_library(Kitron-default-interface INTERFACE)
target_link_libraries(Kitron-default-interface
  INTERFACE
    Kitron-compile-option-interface
    Kitron-feature-interface)

# An interface used for silencing all warnings
add_library(Kitron-no-warning-interface INTERFACE)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(Kitron-no-warning-interface
    INTERFACE
      /W0)
else()
  target_compile_options(Kitron-no-warning-interface
    INTERFACE
      -w)
endif()

# An interface library to change the default behaviour
# to hide symbols automatically.
add_library(Kitron-hidden-symbols-interface INTERFACE)

# An interface amalgamation which provides the flags and definitions
# used by the dependency targets.
add_library(Kitron-dependency-interface INTERFACE)
target_link_libraries(Kitron-dependency-interface
  INTERFACE
    Kitron-default-interface
    Kitron-no-warning-interface
    Kitron-hidden-symbols-interface)

# An interface amalgamation which provides the flags and definitions
# used by the core targets.
add_library(Kitron-core-interface INTERFACE)
target_link_libraries(Kitron-core-interface
  INTERFACE
    Kitron-default-interface
    Kitron-warning-interface)
