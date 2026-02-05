# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

GroupSources(${CMAKE_CURRENT_SOURCE_DIR})

add_library(common)

CollectAndAddSourceFiles(
  common
  ${CMAKE_CURRENT_SOURCE_DIR}
  EXCLUDE
  ${CMAKE_CURRENT_SOURCE_DIR}/Debugging/Windows
  ${CMAKE_CURRENT_SOURCE_DIR}/Platform
  ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders
  ${CMAKE_CURRENT_SOURCE_DIR}/mmaps_common
  ${CMAKE_CURRENT_SOURCE_DIR}/network)

if(WIN32)
  CollectAndAddSourceFiles(
    common
    ${CMAKE_CURRENT_SOURCE_DIR}/Debugging/Windows
    BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
  CollectAndAddSourceFiles(
    common
    ${CMAKE_CURRENT_SOURCE_DIR}/Platform/Windows
    BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
endif()

target_include_directories(common
  PUBLIC
    # Provide the binary dir for all child targets
    ${CMAKE_BINARY_DIR}
  PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(common
  PRIVATE
    trinity-core-interface
  PUBLIC
    argon2
    boost
    fmt
    g3dlib
    sfmt
    utf8cpp
    openssl
    valgrind
    threads
    jemalloc
    openssl_ed25519
    short_alloc)

set_target_properties(common
  PROPERTIES
    COMPILE_WARNING_AS_ERROR ${WITH_WARNINGS_AS_ERRORS}
    DEFINE_SYMBOL TRINITY_API_EXPORT_COMMON
    FOLDER "server")

add_dependencies(common revision_data.h)

if(BUILD_SHARED_LIBS)
  if(UNIX)
    install(TARGETS common
      LIBRARY
        DESTINATION lib)
  elseif(WIN32)
    install(TARGETS common
      RUNTIME
        DESTINATION "${CMAKE_INSTALL_PREFIX}")
  endif()
endif()

# Generate precompiled header
if(USE_COREPCH)
  add_cxx_pch(common PrecompiledHeaders/commonPCH.h)
endif()

add_subdirectory(mmaps_common)
add_subdirectory(network)
