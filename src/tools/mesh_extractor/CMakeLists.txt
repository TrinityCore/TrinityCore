# Copyright (C) 2005-2009 MaNGOS project <http://getmangos.com/>
# Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB_RECURSE sources *.cpp *.h)

if( UNIX )
  include_directories (
    ${CMAKE_BINARY_DIR}
    ${CMAKE_SOURCE_DIR}/src/server/shared
    ${CMAKE_SOURCE_DIR}/dep/recastnavigation/Recast
    ${CMAKE_SOURCE_DIR}/dep/recastnavigation/Detour
    ${CMAKE_SOURCE_DIR}/dep/libmpq
    ${CMAKE_SOURCE_DIR}/dep/g3dlite/include
    ${MYSQL_INCLUDE_DIR}
    ${OPENSSL_INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
  )
elseif( WIN32 )
  include_directories (
    ${CMAKE_BINARY_DIR}
    ${CMAKE_SOURCE_DIR}/src/server/shared
    ${CMAKE_SOURCE_DIR}/src/server/shared/Database
    ${CMAKE_SOURCE_DIR}/src/server/shared/Database/Implementation
    ${CMAKE_SOURCE_DIR}/src/server/shared/Threading
    ${CMAKE_SOURCE_DIR}/src/server/shared/Logging
    ${CMAKE_SOURCE_DIR}/src/server/shared/Utilities
    ${CMAKE_SOURCE_DIR}/src/server/shared/Dynamic
    ${CMAKE_SOURCE_DIR}/src/server/shared/Dynamic/LinkedReference
    ${CMAKE_SOURCE_DIR}/dep/recastnavigation/Recast
    ${CMAKE_SOURCE_DIR}/dep/recastnavigation/Detour
    ${CMAKE_SOURCE_DIR}/dep/libmpq
    ${CMAKE_SOURCE_DIR}/dep/libmpq/win
    ${CMAKE_SOURCE_DIR}/dep/g3dlite/include
    ${ACE_INCLUDE_DIR}
    ${MYSQL_INCLUDE_DIR}
    ${OPENSSL_INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
  )
endif()

add_executable(MeshExtractor
  ${sources}
)

target_link_libraries(MeshExtractor
  shared
  g3dlib
  mpq
  Recast
  Detour
  ${MYSQL_LIBRARY}
  ${OPENSSL_LIBRARIES}
  ${OPENSSL_EXTRA_LIBRARIES}
  ${BZIP2_LIBRARIES}
  ${ZLIB_LIBRARIES}
  ${ACE_LIBRARY}
)

add_dependencies(MeshExtractor mpq Recast Detour)

if( UNIX )
  install(TARGETS MeshExtractor DESTINATION bin)
elseif( WIN32 )
  install(TARGETS MeshExtractor DESTINATION "${CMAKE_INSTALL_PREFIX}")
endif()