
########### next target ###############

SET(vmaps_STAT_SRCS
   AABSPTree.h
   BaseModel.cpp
   BaseModel.h
   CoordModelMapping.cpp
   CoordModelMapping.h
   DebugCmdLogger.cpp
   DebugCmdLogger.h
   IVMapManager.h
   ManagedModelContainer.cpp
   ManagedModelContainer.h
   ModelContainer.cpp
   ModelContainer.h
   NodeValueAccess.h
   ShortBox.h
   ShortVector.h
   SubModel.cpp
   SubModel.h
   TileAssembler.cpp
   TileAssembler.h
   TreeNode.cpp
   TreeNode.h
   VMapDefinitions.h
   VMapFactory.cpp
   VMapFactory.h
   VMapManager.cpp
   VMapManager.h
   VMapTools.h
)

include_directories(
  ${CMAKE_SOURCE_DIR}/dep/include/g3dlite
)

add_library(vmaps STATIC ${vmaps_STAT_SRCS})

