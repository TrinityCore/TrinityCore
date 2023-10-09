# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

set(g3dlib_STAT_SRCS
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
  source/Vector4.cpp
)

add_library(g3dlib STATIC ${g3dlib_STAT_SRCS})

target_include_directories(g3dlib
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

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

if(UNITY_BUILDS)
  set_target_properties(g3dlib
      PROPERTIES UNITY_BUILD ON)
  set_target_properties(g3dlib
      PROPERTIES
        UNITY_BUILD_MODE BATCH
        UNITY_BUILD_BATCH_SIZE 8)
endif()
