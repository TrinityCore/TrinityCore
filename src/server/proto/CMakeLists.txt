# Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  string(REGEX REPLACE "/W[0-4] " "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  string(REGEX REPLACE "/W[0-4] " "" CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
  add_definitions(/W0)
else()
  add_definitions(-w)
endif()

CollectSourceFiles(
  ${CMAKE_CURRENT_SOURCE_DIR}
  PRIVATE_SOURCES
  # Exclude
  ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders)

if (USE_COREPCH)
  set(PRIVATE_PCH_HEADER PrecompiledHeaders/protoPCH.h)
  set(PRIVATE_PCH_SOURCE PrecompiledHeaders/protoPCH.cpp)
endif()

GroupSources(${CMAKE_CURRENT_SOURCE_DIR})

add_definitions(-DTRINITY_API_EXPORT_PROTO)

add_library(proto
  ${PRIVATE_PCH_SOURCE}
  ${PRIVATE_SOURCES}
)

CollectIncludeDirectories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  PUBLIC_INCLUDES
  # Exclude
  ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders)

target_include_directories(proto
  PUBLIC
    ${PUBLIC_INCLUDES}
  PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(proto
  PUBLIC
    common
    protobuf)

set_target_properties(proto
  PROPERTIES
    FOLDER
      "server")

if( BUILD_SHARED_LIBS )
  if( UNIX )
    install(TARGETS proto
      LIBRARY
        DESTINATION lib)
  elseif( WIN32 )
    install(TARGETS proto
      RUNTIME
        DESTINATION "${CMAKE_INSTALL_PREFIX}")
  endif()
endif()

# Generate precompiled header
if (USE_COREPCH)
  add_cxx_pch(proto ${PRIVATE_PCH_HEADER} ${PRIVATE_PCH_SOURCE})
endif()
