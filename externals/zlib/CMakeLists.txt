file(GLOB sources *.c)
file(GLOB headers *.h)

SET(zlib_STAT_SRCS
  ${sources}
  )

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  )

add_library(zlib STATIC ${zlib_STAT_SRCS})
