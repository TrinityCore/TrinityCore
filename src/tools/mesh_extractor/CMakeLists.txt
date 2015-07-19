# Copyright (C) 2005-2009 MaNGOS project <http://getmangos.com/>
# Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB_RECURSE meshExtract_Sources *.cpp *.h)

set(include_Base
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/src/server/shared
  ${CMAKE_SOURCE_DIR}/dep/recastnavigation/Recast
  ${CMAKE_SOURCE_DIR}/dep/recastnavigation/Detour
  ${CMAKE_SOURCE_DIR}/dep/libmpq
  ${CMAKE_SOURCE_DIR}/dep/g3dlite/include
  ${ACE_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
)

if( WIN32 )
  set(include_Base
    ${include_Base}
    ${CMAKE_SOURCE_DIR}/dep/libmpq/win
    )
endif()

include_directories(${include_Base})

add_executable(MeshExtractor ${meshExtract_Sources})

target_link_libraries(MeshExtractor
  g3dlib
  mpq
  Recast
  Detour
  ${BZIP2_LIBRARIES}
  ${ZLIB_LIBRARIES}
  ${ACE_LIBRARY}
)

if( UNIX )
  install(TARGETS MeshExtractor DESTINATION bin)
elseif( WIN32 )
  install(TARGETS MeshExtractor DESTINATION "${CMAKE_INSTALL_PREFIX}")
endif()
