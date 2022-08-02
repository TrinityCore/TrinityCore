# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

CollectSourceFiles(
  ${CMAKE_CURRENT_SOURCE_DIR}
  PRIVATE_SOURCES
  # Exclude
  ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders)

if(USE_COREPCH)
  set(PRIVATE_PCH_HEADER PrecompiledHeaders/gamePCH.h)
endif()

GroupSources(${CMAKE_CURRENT_SOURCE_DIR})

add_definitions(-DTRINITY_API_EXPORT_GAME)

CollectIncludeDirectories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  PUBLIC_INCLUDES
  # Exclude
  ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders)

# Provide an interface target for the game project to allow
# dependent projects to build meanwhile.
add_library(game-interface INTERFACE)

target_include_directories(game-interface
  INTERFACE
    ${PUBLIC_INCLUDES})

target_link_libraries(game-interface
  INTERFACE
    shared
    Detour)

add_library(game
  ${PRIVATE_SOURCES}
  # tswow-begin
  ${TSWOW_SOURCES}
  # tswow-end
  )

target_include_directories(game
  PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
    # tswow-begin
    ${TSWOW_INCLUDES}
    ${LUA_ROOT}
    ${sourcemap_SOURCE_DIR}/src
    ${sourcemap_SOURCE_DIR}/deps/json
    ${sourcemap_SOURCE_DIR}/deps/cencode
    ${tracy_SOURCE_DIR}
    # tswow-end
    )

#tswow-begin
include(FetchContent)
FetchContent_Declare (json
GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
GIT_TAG v3.9.1
)
FetchContent_GetProperties (json)
if (NOT json_POPULATED)
message (STATUS "Installing json.hpp...")
FetchContent_Populate (json)
endif()
add_subdirectory (${json_SOURCE_DIR} ${json_BINARY_DIR})

FILE(GLOB TSWOW_PUBLIC ${TSWOW_CORE_PUBLIC}/*)
FILE(GLOB TSWOW_PRIVATE ${TSWOW_CORE_PRIVATE}/*)
FILE(GLOB TSWOW_MESSAGES ${TSWOW_MESSAGES_INCLUDES}/*)

target_compile_definitions(game PUBLIC CUSTOM_PACKET_API=TC_GAME_API)
target_compile_definitions(game PUBLIC TRINITY=1)


#tswow-begin
source_group("tswow-messages" FILES ${TSWOW_MESSAGES})
source_group("tswow-public" FILES ${TSWOW_PUBLIC})
source_group("tswow-private" FILES ${TSWOW_PRIVATE})
# tswow-end

target_link_libraries(game
  PRIVATE
    trinity-core-interface
    efsw
    sol2
  PUBLIC
    # tswow-begin
    nlohmann_json::nlohmann_json
    liblua
    sourcemaps
    TracyClient
    # tswow-end
    game-interface
    )

set_target_properties(game
    PROPERTIES
      FOLDER
        "server")

if(BUILD_SHARED_LIBS)
  if(UNIX)
    install(TARGETS game
      LIBRARY
        DESTINATION lib)
  elseif(WIN32)
    install(TARGETS game
      RUNTIME
        DESTINATION "${CMAKE_INSTALL_PREFIX}")
  endif()
endif()

# Generate precompiled header
if(USE_COREPCH)
  add_cxx_pch(game ${PRIVATE_PCH_HEADER})
endif()
