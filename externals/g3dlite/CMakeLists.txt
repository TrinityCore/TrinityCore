file(GLOB sources *.cpp)

SET(g3dlib_STAT_SRCS
  ${sources}
  )

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  )

add_library(g3dlib STATIC ${g3dlib_STAT_SRCS})
target_link_libraries(g3dlib zlib)
