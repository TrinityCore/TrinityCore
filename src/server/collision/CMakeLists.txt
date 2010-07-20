# Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

########### collision ###############

set(collision_STAT_SRCS
  BoundingIntervalHierarchy.cpp
  Maps/MapTree.cpp
  Maps/TileAssembler.cpp
  Models/ModelInstance.cpp
  Models/WorldModel.cpp
  Management/VMapFactory.cpp
  Management/VMapManager2.cpp
)

include_directories(
  ${ACE_INCLUDE_DIR}
  ${CMAKE_SOURCE_DIR}/externals/g3dlite
  ${CMAKE_SOURCE_DIR}/externals/mysql
  ${CMAKE_SOURCE_DIR}/src/server/shared
  ${CMAKE_SOURCE_DIR}/src/server/shared/Debugging
  ${CMAKE_SOURCE_DIR}/src/server/shared/Dynamic
  ${CMAKE_SOURCE_DIR}/src/server/shared/Logging
  ${CMAKE_SOURCE_DIR}/src/server/collision
  ${CMAKE_SOURCE_DIR}/src/server/collision/Management
  ${CMAKE_SOURCE_DIR}/src/server/collision/Maps
  ${CMAKE_SOURCE_DIR}/src/server/collision/Models
  ${CMAKE_BINARY_DIR}
)

add_library(collision STATIC ${collision_STAT_SRCS})
