# Copyright (C) 2005-2010 Trinity <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

########### collision ###############

SET(collision_STAT_SRCS
   BoundingIntervalHierarchy.h
   BoundingIntervalHierarchy.cpp
   Maps/MapTree.cpp
   Maps/MapTree.h
   Maps/TileAssembler.cpp
   Maps/TileAssembler.h
   Models/ModelInstance.cpp
   Models/ModelInstance.h
   Models/WorldModel.cpp
   Models/WorldModel.h
   Management/IVMapManager.h
   Management/VMapFactory.cpp
   Management/VMapFactory.h
   Management/VMapManager2.cpp
   Management/VMapManager2.h
   VMapDefinitions.h
   VMapTools.h
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
