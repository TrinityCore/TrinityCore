# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

# Look for an installed zlib
find_package(ZLIB)

if(TARGET ZLIB::ZLIB)
  add_library(zlib INTERFACE)

  target_link_libraries(zlib
    INTERFACE
      ZLIB::ZLIB)
else()
  # Use the bundled source
  SET(zlib_STAT_SRCS
    adler32.c
    compress.c
    crc32.c
    deflate.c
    infback.c
    inffast.c
    inflate.c
    inftrees.c
    trees.c
    uncompr.c
    zutil.c
  )

  add_library(zlib STATIC
    ${zlib_STAT_SRCS})

  set_target_properties(zlib PROPERTIES LINKER_LANGUAGE CXX)

  target_include_directories(zlib
    PUBLIC
      ${CMAKE_CURRENT_SOURCE_DIR})

  target_link_libraries(zlib
    PRIVATE
      trinity-dependency-interface)

  set_target_properties(zlib
      PROPERTIES
        FOLDER
          "dep")
endif()
