# Set build-directive (used in core to tell which buildtype we used)
add_definitions(-D_BUILD_DIRECTIVE='"${CMAKE_BUILD_TYPE}"')

set(GCC_EXPECTED_VERSION 4.7.2)

if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS GCC_EXPECTED_VERSION)
  message(FATAL_ERROR "GCC: TrinityCore requires version ${GCC_EXPECTED_VERSION} to build but found ${CMAKE_CXX_COMPILER_VERSION}")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
message(STATUS "GCC: Enabled c++11 support")

if(PLATFORM EQUAL 32)
  # Required on 32-bit systems to enable SSE2 (standard on x64)
  set(SSE_FLAGS "-msse2 -mfpmath=sse")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${SSE_FLAGS}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SSE_FLAGS}")
endif()
add_definitions(-DHAVE_SSE2 -D__SSE2__)
message(STATUS "GCC: SFMT enabled, SSE2 flags forced")

if( WITH_WARNINGS )
  set(WARNING_FLAGS "-W -Wall -Wextra -Winit-self -Winvalid-pch -Wfatal-errors")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${WARNING_FLAGS}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WARNING_FLAGS} -Woverloaded-virtual")
  message(STATUS "GCC: All warnings enabled")
endif()

if( WITH_COREDEBUG )
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g3")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3")
  message(STATUS "GCC: Debug-flags set (-g3)")
endif()

execute_process(COMMAND ${CMAKE_C_COMPILER} -dumpversion
                    OUTPUT_VARIABLE GCC_VERSION)

if (GCC_VERSION VERSION_GREATER 4.7 OR GCC_VERSION VERSION_EQUAL 4.7)
    message(STATUS "GCC ${GCC_VERSION} found. C++11 activated.")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
elseif(GCC_VERSION VERSION_GREATER 4.3 OR GCC_VERSION VERSION_EQUAL 4.3)
    message(WARNING "GCC ${GCC_VERSION} found. C++0x activated. If you get any errors update to a compiler which fully supports C++11")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
endif()
