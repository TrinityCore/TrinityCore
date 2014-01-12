SET(trinityframework_STAT_SRCS
   Policies/ObjectLifeTime.cpp
)

include_directories(
  ${ACE_INCLUDE_DIR}
  ${CMAKE_SOURCE_DIR}/src/framework
)

add_library(trinityframework STATIC ${trinityframework_STAT_SRCS})
