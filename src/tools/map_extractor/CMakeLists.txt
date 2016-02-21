# Copyright (C) 2005-2009 MaNGOS project <http://getmangos.com/>
# Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB_RECURSE mapextractor_SRCS *.cpp *.h)

include_directories (
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/src/server/shared
  ${CMAKE_SOURCE_DIR}/dep/cppformat
  ${CMAKE_SOURCE_DIR}/dep/StormLib/src
  ${CMAKE_SOURCE_DIR}/dep/g3dlite/include
  ${CMAKE_SOURCE_DIR}/src/common
  ${CMAKE_SOURCE_DIR}/src/common/Utilities
  ${CMAKE_SOURCE_DIR}/src/server/shared
  ${CMAKE_CURRENT_SOURCE_DIR}/loadlib
)

include_directories(${include_Dirs})

add_executable(mapextractor
  ${mapextractor_SRCS}
)

target_link_libraries(mapextractor
  common
  format
  g3dlib
  ${BZIP2_LIBRARIES}
  ${ZLIB_LIBRARIES}
  ${Boost_LIBRARIES}
  storm
)

add_dependencies(mapextractor storm)

if( UNIX )
  install(TARGETS mapextractor DESTINATION bin)
elseif( WIN32 )
  install(TARGETS mapextractor DESTINATION "${CMAKE_INSTALL_PREFIX}")
endif()
