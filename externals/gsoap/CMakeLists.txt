file(GLOB sources *.cpp)
set(gsoap_STAT_SRCS
   ${sources}
)

include_directories(
   ${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(gsoap STATIC ${gsoap_STAT_SRCS})