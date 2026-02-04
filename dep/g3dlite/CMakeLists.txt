# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

add_library(g3dlib STATIC)

target_sources(g3dlib
  PRIVATE
    source/AABox.cpp
    source/Any.cpp
    source/AnyTableReader.cpp
    source/BinaryFormat.cpp
    source/BinaryInput.cpp
    source/BinaryOutput.cpp
    source/Box.cpp
    source/Capsule.cpp
    source/CollisionDetection.cpp
    source/CoordinateFrame.cpp
    source/Crypto.cpp
    source/Cylinder.cpp
    source/debugAssert.cpp
    source/FileSystem.cpp
    source/fileutils.cpp
    source/format.cpp
    source/g3dfnmatch.cpp
    source/g3dmath.cpp
    source/GThread.cpp
    source/Line.cpp
    source/LineSegment.cpp
    source/Log.cpp
    source/Matrix3.cpp
    source/Matrix4.cpp
    source/MemoryManager.cpp
    source/PhysicsFrame.cpp
    source/Plane.cpp
    source/prompt.cpp
    source/Quat.cpp
    source/Random.cpp
    source/Ray.cpp
    source/RegistryUtil.cpp
    source/Sphere.cpp
    source/stringutils.cpp
    source/System.cpp
    source/TextInput.cpp
    source/TextOutput.cpp
    source/Triangle.cpp
    source/uint128.cpp
    source/UprightFrame.cpp
    source/Vector2.cpp
    source/Vector3.cpp
    source/Vector4.cpp)

target_sources(g3dlib
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS include
    FILES
      include/G3D/AABox.h
      include/G3D/BoundsTrait.h
      include/G3D/Box.h
      include/G3D/CoordinateFrame.h
      include/G3D/g3dmath.h
      include/G3D/Matrix3.h
      include/G3D/Matrix4.h
      include/G3D/Plane.h
      include/G3D/Quat.h
      include/G3D/Ray.h
      include/G3D/Vector3.h
      include/G3D/Vector4.h)

if((CMAKE_SYSTEM_NAME MATCHES "Linux" AND NOT NOJEM) OR TSAN)
  target_compile_definitions(g3dlib
    PRIVATE
      NO_BUFFERPOOL)
endif()

target_link_libraries(g3dlib
  PRIVATE
    trinity-dependency-interface
  PUBLIC
    zlib
    threads)

set_target_properties(g3dlib
    PROPERTIES
      FOLDER
        "dep")

# Generate precompiled header
if(USE_COREPCH)
  list(APPEND g3dlib_PCH_HEADERS
    [["G3D/Any.h"]]
    [["G3D/Array.h"]]
    [["G3D/BinaryOutput.h"]]
    [["G3D/Vector3.h"]])

  add_cxx_pch(g3dlib "${g3dlib_PCH_HEADERS}")
endif()
