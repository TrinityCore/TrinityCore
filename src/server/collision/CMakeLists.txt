
########### collision ###############

SET(collision_STAT_SRCS
   BoundingIntervalHierarchy.h
   BoundingIntervalHierarchy.cpp
   Management/IVMapManager.h
   Maps/MapTree.cpp
   Maps/MapTree.h
   Models/ModelInstance.cpp
   Models/ModelInstance.h
   Maps/TileAssembler.cpp
   Maps/TileAssembler.h
   VMapDefinitions.h
   Management/VMapFactory.cpp
   Management/VMapFactory.h
   Management/VMapManager2.cpp
   Management/VMapManager2.h
   VMapTools.h
   Models/WorldModel.cpp
   Models/WorldModel.h
)

include_directories(
  ${ACE_INCLUDE_DIR}
  ${CMAKE_SOURCE_DIR}/externals/g3dlite
  ${CMAKE_SOURCE_DIR}/externals/g3dlite/G3D.lib
  ${CMAKE_SOURCE_DIR}/externals/g3dlite/G3D.lib/include
  ${CMAKE_SOURCE_DIR}/externals/g3dlite/G3D.lib/include/G3D
  ${CMAKE_SOURCE_DIR}/src/server/shared
  ${CMAKE_SOURCE_DIR}/src/server/shared/Dynamic
  ${CMAKE_SOURCE_DIR}/src/server/collision
  ${CMAKE_SOURCE_DIR}/src/server/collision/Maps
)

add_library(collision STATIC ${collision_STAT_SRCS})
