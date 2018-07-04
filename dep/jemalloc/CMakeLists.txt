# Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

if(CMAKE_SYSTEM_NAME MATCHES "Linux" AND NOT NOJEM)
  # We need to generate the jemalloc_def.h header based on platform-specific settings
  if (PLATFORM EQUAL 32)
    set(JEM_SIZEDEF 2)
    set(JEM_TLSMODEL)
  else()
    set(JEM_SIZEDEF 3)
    set(JEM_TLSMODEL "__attribute__\(\(tls_model\(\"initial-exec\"\)\)\)")
  endif()

  # Create the header, so we can use it
  configure_file(
    "${CMAKE_SOURCE_DIR}/dep/jemalloc/jemalloc_defs.h.in.cmake"
    "${BUILDDIR}/jemalloc_defs.h"
    @ONLY
  )

  # Done, let's continue
  set(jemalloc_STAT_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/arena.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/atomic.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/base.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/bitmap.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/chunk.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/chunk_dss.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/chunk_mmap.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ckh.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ctl.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/extent.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/hash.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/huge.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jemalloc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/mb.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/mutex.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/prof.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/quarantine.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/rtree.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/stats.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/tcache.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/tsd.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/util.c
  )

  add_library(jemalloc STATIC ${jemalloc_STAT_SRC})

  target_include_directories(jemalloc
    PRIVATE
      ${BUILDDIR}
      ${CMAKE_CURRENT_SOURCE_DIR}/include)

  target_compile_definitions(jemalloc
    PUBLIC
      -DNO_BUFFERPOOL
    PRIVATE
      -D_GNU_SOURCE
      -D_REENTRAN)

  target_link_libraries(jemalloc
    PRIVATE
      trinity-dependency-interface
    PUBLIC
      threads
      valgrind)

  set_target_properties(jemalloc
      PROPERTIES
        FOLDER
          "dep")

else()
  # Provide a dummy target for jemalloc which is used when jemalloc
  # is disabled or not supported.
  add_library(jemalloc INTERFACE)
  target_link_libraries(jemalloc
    INTERFACE
      valgrind)

endif()
