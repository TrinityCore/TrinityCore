
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
)

include_directories(
  ${CMAKE_SOURCE_DIR}/dep/include/g3dlite
)

add_library(g3dlite STATIC ${g3dlite_STAT_SRCS})


########### install files ###############
