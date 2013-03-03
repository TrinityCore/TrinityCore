# Set build-directive (used in core to tell which buildtype we used)
add_definitions(-D_BUILD_DIRECTIVE="'${CMAKE_BUILD_TYPE}'")

if(PLATFORM EQUAL 32)
  add_definitions(-axSSE2)
else()
  add_definitions(-xSSE2)
endif()

if( WITH_WARNINGS )
  add_definitions(-w1)
  message(STATUS "ICC: All warnings enabled")
endif()

if( WITH_COREDEBUG )
  add_definitions(-g)
  message(STATUS "ICC: Debug-flag set (-g)")
endif()
