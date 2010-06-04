
########### next target ###############

SET(vmaps_STAT_SRCS
   BIH.h
   BIH.cpp
   IVMapManager.h
   MapTree.cpp
   MapTree.h
   ModelInstance.cpp
   ModelInstance.h
   TileAssembler.cpp
   TileAssembler.h
   VMapDefinitions.h
   VMapFactory.cpp
   VMapFactory.h
   VMapManager2.cpp
   VMapManager2.h
   VMapTools.h
   WorldModel.cpp
   WorldModel.h
)

include_directories(
  ${CMAKE_SOURCE_DIR}/src/framework
  ${CMAKE_SOURCE_DIR}/dep/include/g3dlite
)

add_library(vmaps STATIC ${vmaps_STAT_SRCS})
