# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
  CHECK_SYMBOL_EXISTS(MADV_FREE "sys/mman.h" HAVE_MADV_FREE)
  
  if (PLATFORM EQUAL 32)
    set(JEM_SIZEDEF 2)
    set(JEM_TLSMODEL)
	set(JEM_VADDRBITS 32)
  else()
    set(JEM_SIZEDEF 3)
    set(JEM_TLSMODEL "__attribute__\(\(tls_model\(\"initial-exec\"\)\)\)")
	set(JEM_VADDRBITS 48)
  endif()

  if (HAVE_MADV_FREE)
    set(JEM_MADFREE_DEF "#define")
  else()
    set(JEM_MADFREE_DEF "#undef")
  endif()

  if(TRINITY_SYSTEM_PROCESSOR MATCHES "arm")
    set(JEM_CPU_SPINWAIT "")
    set(JEM_HAVE_CPU_SPINWAIT 0)
  else()
    set(JEM_CPU_SPINWAIT "__asm__ volatile\(\"pause\"\)")
    set(JEM_HAVE_CPU_SPINWAIT 1)
  endif()

  # Create the header, so we can use it
  configure_file(
    "${CMAKE_SOURCE_DIR}/dep/jemalloc/jemalloc_internal_defs.h.in.cmake"
    "${BUILDDIR}/jemalloc_internal_defs.h"
    @ONLY
  )

  # Done, let's continue
  set(jemalloc_STAT_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/arena.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/background_thread.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/base.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/bin.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/bitmap.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ckh.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ctl.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/div.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/extent.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/extent_dss.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/extent_mmap.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/hash.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/hook.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jemalloc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jemalloc_cpp.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/large.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/log.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/malloc_io.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/mutex.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/mutex_pool.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/nstime.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/pages.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/prng.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/prof.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/rtree.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/safety_check.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/stats.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sz.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/tcache.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/test_hooks.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ticker.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/tsd.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/witness.c
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
      valgrind
	  ${CMAKE_DL_LIBS})

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
