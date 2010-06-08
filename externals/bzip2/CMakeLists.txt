file(GLOB sources *.cpp)
set(bzip2_STAT_SRCS
  ${sources}
)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(bzip2 STATIC ${bzip2_STAT_SRCS})
