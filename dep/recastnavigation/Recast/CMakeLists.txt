# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

set(Recast_STAT_SRCS
    Source/Recast.cpp 
    Source/RecastAlloc.cpp 
	Source/RecastAssert.cpp 
    Source/RecastArea.cpp 
    Source/RecastContour.cpp 
    Source/RecastFilter.cpp 
    Source/RecastLayers.cpp
    Source/RecastMesh.cpp 
    Source/RecastMeshDetail.cpp 
    Source/RecastRasterization.cpp 
    Source/RecastRegion.cpp 
)

add_library(Recast STATIC ${Recast_STAT_SRCS})

target_include_directories(Recast
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Include)

target_link_libraries(Recast
  PRIVATE
    trinity-dependency-interface
  PUBLIC
    zlib)

set_target_properties(Recast
    PROPERTIES
      FOLDER
        "dep")

if(UNITY_BUILDS)
  set_target_properties(Recast
      PROPERTIES UNITY_BUILD ON)
  set_target_properties(Recast
      PROPERTIES
        UNITY_BUILD_MODE BATCH
        UNITY_BUILD_BATCH_SIZE 2)
endif()
