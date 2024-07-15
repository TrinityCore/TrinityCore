# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB sources *.cpp *.c *.h)

add_library(gsoap STATIC ${sources})

set_target_properties(gsoap PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(gsoap
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_definitions(gsoap
  PUBLIC
    WITH_OPENSSL)

target_link_libraries(gsoap
  PRIVATE
    trinity-dependency-interface
  PUBLIC
    openssl)

set_target_properties(gsoap
    PROPERTIES
      FOLDER
        "dep")

if (MSVC)
  # Little fix for MSVC / Windows platforms
  target_compile_definitions(gsoap
    PRIVATE
      _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES=0)
endif()
