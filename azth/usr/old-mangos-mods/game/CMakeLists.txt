if( USE_COREPCH )
  include_directories(${CMAKE_CURRENT_BINARY_DIR})
endif()

file(GLOB_RECURSE sources_chat     chat/*.cpp chat/*.h)
file(GLOB_RECURSE sources_creature creature/*.cpp creature/*.h)
file(GLOB_RECURSE sources_player   player/*.cpp player/*.h)
file(GLOB_RECURSE sources_pvp      pvp/*.cpp pvp/*.h)
file(GLOB_RECURSE sources_rpg      rpg/*.cpp rpg/*.h)
file(GLOB_RECURSE sources_world    world/*.cpp world/*.h)

if (USE_COREPCH)
  set(hw2game_STAT_PCH_HDR precompiledheaders/Hw2GamePCH.h)
  set(hw2game_STAT_PCH_SRC precompiledheaders/Hw2GamePCH.cpp)
endif ()

# Create game-libary
set(hw2game_STAT_SRCS
  ${hw2game_STAT_SRCS}
  ${sources_chat}
  ${sources_creature}
  ${sources_player}
  ${sources_pvp}
  ${sources_rpg}
  ${sources_world}
)

include(../cmake/CMakeIncludeFull.txt)

add_library(hw2game STATIC
  ${hw2game_STAT_SRCS}
  ${hw2game_STAT_PCH_SRC}
)

target_link_libraries(hw2game
  hw2shared
)

add_dependencies(hw2game revision_data.h)

# Generate precompiled header
if (USE_COREPCH)
  add_cxx_pch(hw2game ${hw2game_STAT_PCH_HDR} ${hw2game_STAT_PCH_SRC})
endif ()
