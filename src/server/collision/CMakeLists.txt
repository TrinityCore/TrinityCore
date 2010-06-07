
########### next target ###############

SET(collision_STAT_SRCS
   BIH.h
   BIH.cpp
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
  ${CMAKE_SOURCE_DIR}/dep/include/g3dlite
)

add_library(collision STATIC ${collision_STAT_SRCS})
