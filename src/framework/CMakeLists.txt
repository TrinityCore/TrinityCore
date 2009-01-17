SET(trinityframework_STAT_SRCS
   Policies/ObjectLifeTime.cpp
   Utilities/EventProcessor.cpp
)
include_directories(
${CMAKE_CURRENT_SRC_DIR}
)
add_library(trinityframework STATIC ${trinityframework_STAT_SRCS})
