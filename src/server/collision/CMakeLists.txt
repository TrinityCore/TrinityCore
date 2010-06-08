
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
  ${CMAKE_SOURCE_DIR}/src/server/shared
  ${CMAKE_SOURCE_DIR}/src/server/shared/Dynamic
  ${CMAKE_SOURCE_DIR}/src/server/collision
  ${CMAKE_SOURCE_DIR}/src/server/collision/Management
  ${CMAKE_SOURCE_DIR}/src/server/collision/Maps
  ${CMAKE_SOURCE_DIR}/src/server/collision/Models
)

add_library(collision STATIC ${collision_STAT_SRCS})
