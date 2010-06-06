# Copyright (C) 2005-2009 MaNGOS project <http://getmangos.com/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

cmake_minimum_required (VERSION 2.6)
project (MANGOS_VMAP_ASSEMB_IO)

set(CMAKE_VERBOSE_MAKEFILE true)

# uncomment next line to disable debug mode
ADD_DEFINITIONS("-DIOMAP_DEBUG")

ADD_DEFINITIONS("-Wall")
ADD_DEFINITIONS("-ggdb")
ADD_DEFINITIONS("-O3")

include_directories(../../src/server/shared/vmap/)
include_directories(../../dep/include/g3dlite/)
include_directories(../../dep/ACE_wrappers/)
include_directories(../../objdir/dep/ACE_wrappers)
include_directories(../../src/server/framework/)

add_library(g3dlite ../../dep/src/g3dlite/AABox.cpp
	../../dep/src/g3dlite/Box.cpp
	../../dep/src/g3dlite/Crypto.cpp
	../../dep/src/g3dlite/format.cpp
	../../dep/src/g3dlite/Matrix3.cpp
	../../dep/src/g3dlite/Plane.cpp
	../../dep/src/g3dlite/System.cpp
	../../dep/src/g3dlite/Triangle.cpp
	../../dep/src/g3dlite/Vector3.cpp
	../../dep/src/g3dlite/Vector4.cpp
	../../dep/src/g3dlite/debugAssert.cpp
	../../dep/src/g3dlite/fileutils.cpp
	../../dep/src/g3dlite/g3dmath.cpp
	../../dep/src/g3dlite/g3dfnmatch.cpp
	../../dep/src/g3dlite/prompt.cpp
	../../dep/src/g3dlite/stringutils.cpp
	../../dep/src/g3dlite/Any.cpp
	../../dep/src/g3dlite/BinaryFormat.cpp
	../../dep/src/g3dlite/BinaryInput.cpp
	../../dep/src/g3dlite/BinaryOutput.cpp
	../../dep/src/g3dlite/Capsule.cpp
	../../dep/src/g3dlite/CollisionDetection.cpp
	../../dep/src/g3dlite/CoordinateFrame.cpp
	../../dep/src/g3dlite/Cylinder.cpp
	../../dep/src/g3dlite/Line.cpp
	../../dep/src/g3dlite/LineSegment.cpp
	../../dep/src/g3dlite/Log.cpp
	../../dep/src/g3dlite/Matrix4.cpp
	../../dep/src/g3dlite/MemoryManager.cpp
	../../dep/src/g3dlite/Quat.cpp
	../../dep/src/g3dlite/Random.cpp
	../../dep/src/g3dlite/Ray.cpp
	../../dep/src/g3dlite/ReferenceCount.cpp
	../../dep/src/g3dlite/Sphere.cpp
	../../dep/src/g3dlite/TextInput.cpp
	../../dep/src/g3dlite/TextOutput.cpp
	../../dep/src/g3dlite/UprightFrame.cpp
	../../dep/src/g3dlite/Vector2.cpp
	)

add_library(vmap
	../../src/shared/vmap/BoundingIntervalHierarchy.cpp
	../../src/shared/vmap/VMapManager2.cpp
	../../src/shared/vmap/MapTree.cpp
	../../src/shared/vmap/TileAssembler.cpp
	../../src/shared/vmap/WorldModel.cpp
	../../src/shared/vmap/ModelInstance.cpp
	)

target_link_libraries(vmap g3dlite z)

add_executable(vmap_assembler VMapAssembler.cpp)
target_link_libraries(vmap_assembler vmap)

# add_executable(vmap_test coordinate_test.cpp)
# target_link_libraries(vmap_test vmap)

