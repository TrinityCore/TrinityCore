# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

# Look for an installed bzip2 first
find_package(BZip2)

if(TARGET BZip2::BZip2)
  add_library(bzip2 INTERFACE)

  target_link_libraries(bzip2 
    INTERFACE
      BZip2::BZip2)
else()
  # Use the bundled source
  file(GLOB sources *.c)
  add_library(bzip2 STATIC
    ${sources})

  set_target_properties(bzip2 PROPERTIES LINKER_LANGUAGE CXX)

  target_include_directories(bzip2
    PUBLIC
      ${CMAKE_CURRENT_SOURCE_DIR})

  target_link_libraries(bzip2
    PRIVATE
      trinity-dependency-interface)

  set_target_properties(bzip2
    PROPERTIES
      FOLDER
        "dep")
endif()
