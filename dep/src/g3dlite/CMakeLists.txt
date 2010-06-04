
########### next target ###############

SET(g3dlite_STAT_SRCS
    AABox.cpp
    Box.cpp
    Crypto.cpp
    format.cpp
    Matrix3.cpp
    Plane.cpp
    System.cpp
    Triangle.cpp
    Vector3.cpp
    Vector4.cpp
    debugAssert.cpp
    fileutils.cpp
    g3dmath.cpp
    g3dfnmatch.cpp
    prompt.cpp
    stringutils.cpp
    Any.cpp
    BinaryFormat.cpp
    BinaryInput.cpp
    BinaryOutput.cpp
    Capsule.cpp
    CollisionDetection.cpp
    CoordinateFrame.cpp
    Cylinder.cpp
    Line.cpp
    LineSegment.cpp
    Log.cpp
    Matrix4.cpp
    MemoryManager.cpp
    Quat.cpp
    Random.cpp
    Ray.cpp
    ReferenceCount.cpp
    Sphere.cpp
    TextInput.cpp
    TextOutput.cpp
    UprightFrame.cpp
    Vector2.cpp
)

include_directories(
  ${CMAKE_SOURCE_DIR}/dep/include
  ${CMAKE_SOURCE_DIR}/dep/include/g3dlite
)

add_library(g3dlite STATIC ${g3dlite_STAT_SRCS})


########### install files ###############
