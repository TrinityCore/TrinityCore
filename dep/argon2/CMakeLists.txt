# This file is part of the KitronCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB_RECURSE sources *.c)

add_library(argon2 STATIC
  ${sources})

target_compile_definitions(argon2
  PRIVATE
    -DARGON2_NO_THREADS)

set_target_properties(argon2 PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(argon2
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(argon2
  PRIVATE
    Kitron-dependency-interface)

set_target_properties(argon2
  PROPERTIES
    FOLDER
      "dep")
