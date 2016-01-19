if( USE_COREPCH )
  include_directories(${CMAKE_CURRENT_BINARY_DIR})
endif()

file(GLOB_RECURSE sources_system     system/*.cpp system/*.h)

if (USE_COREPCH)
  set(hw2shared_STAT_PCH_HDR precompiledheaders/Hw2SharedPCH.h)
  set(hw2shared_STAT_PCH_SRC precompiledheaders/Hw2SharedPCH.cpp)
endif ()


# Create game-libary
set(hw2shared_STAT_SRCS
  ${hw2shared_STAT_SRCS}
  ${sources_system}
)

include(../cmake/CMakeIncludeFull.txt)

add_library(hw2shared STATIC
  ${hw2shared_STAT_SRCS}
  ${hw2shared_STAT_PCH_SRC}
)

target_link_libraries(hw2shared
  hw2game
  hw2server
  hw2scripts
)

add_dependencies(hw2shared revision_data.h)

# Generate precompiled header
if (USE_COREPCH)
  add_cxx_pch(hw2shared ${hw2shared_STAT_PCH_HDR} ${hw2shared_STAT_PCH_SRC})
endif ()
