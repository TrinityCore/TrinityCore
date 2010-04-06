SET(trinityframework_STAT_SRCS
   Policies/ObjectLifeTime.cpp
   Utilities/EventProcessor.cpp
)

include_directories(
  ${CMAKE_SOURCE_DIR}/src/framework
)

add_library(trinityframework STATIC ${trinityframework_STAT_SRCS})
