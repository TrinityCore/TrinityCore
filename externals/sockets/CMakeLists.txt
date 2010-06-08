file(GLOB sources *.cpp)
set(trinitysockets_STAT_SRCS
  ${sources}
)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(trinitysockets STATIC ${trinitysockets_STAT_SRCS})
