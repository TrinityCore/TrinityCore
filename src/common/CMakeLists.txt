# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

CollectSourceFiles(
  ${CMAKE_CURRENT_SOURCE_DIR}
  PRIVATE_SOURCES
  # Exclude
  ${CMAKE_CURRENT_SOURCE_DIR}/Debugging/Windows
  ${CMAKE_CURRENT_SOURCE_DIR}/Platform
  ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders)

if(WIN32)
  CollectSourceFiles(
    ${CMAKE_CURRENT_SOURCE_DIR}/Debugging/Windows
    WINDOWS_DEBUGGING_SOURCES)
  list(APPEND PRIVATE_SOURCES
    ${WINDOWS_DEBUGGING_SOURCES})
  CollectSourceFiles(
    ${CMAKE_CURRENT_SOURCE_DIR}/Platform/Windows
    WINDOWS_PLATFORM_SOURCES)
  list(APPEND PRIVATE_SOURCES
    ${WINDOWS_PLATFORM_SOURCES})
endif()

if(USE_COREPCH)
  set(PRIVATE_PCH_HEADER PrecompiledHeaders/commonPCH.h)
endif(USE_COREPCH)

GroupSources(${CMAKE_CURRENT_SOURCE_DIR})

add_library(common
  ${PRIVATE_SOURCES}
)

CollectIncludeDirectories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  PUBLIC_INCLUDES
  # Exclude
  ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders)

target_include_directories(common
  PUBLIC
    # Provide the binary dir for all child targets
    ${CMAKE_BINARY_DIR}
    ${PUBLIC_INCLUDES}
  PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR})

set_target_properties(common
  PROPERTIES
    DEFINE_SYMBOL TRINITY_API_EXPORT_COMMON)

target_link_libraries(common
  PRIVATE
    trinity-core-interface
  PUBLIC
    argon2
    boost
    fmt
    g3dlib
    Detour
    sfmt
    utf8cpp
    openssl
    valgrind
    threads
    jemalloc
    openssl_ed25519
    short_alloc)

add_dependencies(common revision_data.h)

set_target_properties(common
    PROPERTIES
      FOLDER
        "server")

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
  add_cxx_pch(common ${PRIVATE_PCH_HEADER})
endif()
