# Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

if( WIN32 )
  list(APPEND PRIVATE_SOURCES ${sources_windows})
  if ( MSVC )
    list(APPEND PRIVATE_SOURCES worldserver.rc)
  endif()
endif()

if (USE_COREPCH)
  set(PRIVATE_PCH_HEADER PrecompiledHeaders/worldPCH.h)
endif()

GroupSources(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(worldserver
  ${PRIVATE_SOURCES}
)

if( NOT WIN32 )
  set_target_properties(worldserver PROPERTIES
    COMPILE_DEFINITIONS _TRINITY_CORE_CONFIG="${CONF_DIR}/worldserver.conf"
  )
endif()

if( UNIX AND NOT NOJEM AND NOT APPLE )
  set(worldserver_LINK_FLAGS "-pthread -lncurses ${worldserver_LINK_FLAGS}")
endif()

set_target_properties(worldserver PROPERTIES LINK_FLAGS "${worldserver_LINK_FLAGS}")

target_link_libraries(worldserver
  PRIVATE
    trinity-core-interface
  PUBLIC
    scripts
    game
    readline)

CollectIncludeDirectories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  PUBLIC_INCLUDES
  # Exclude
  ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders)

target_include_directories(worldserver
  PUBLIC
    ${PUBLIC_INCLUDES}
  PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR})

set_target_properties(worldserver
    PROPERTIES
      FOLDER
        "server")

# Add all dynamic projects as dependency to the worldserver
if (WORLDSERVER_DYNAMIC_SCRIPT_MODULES_DEPENDENCIES)
  add_dependencies(worldserver ${WORLDSERVER_DYNAMIC_SCRIPT_MODULES_DEPENDENCIES})
endif()

if( WIN32 )
  if ( "${CMAKE_MAKE_PROGRAM}" MATCHES "MSBuild" )
    add_custom_command(TARGET worldserver
      POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/worldserver.conf.dist ${CMAKE_BINARY_DIR}/bin/$(ConfigurationName)/
    )
  elseif ( MINGW )
    add_custom_command(TARGET worldserver
      POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/worldserver.conf.dist ${CMAKE_BINARY_DIR}/bin/
    )
  endif()
endif()

if( UNIX )
  install(TARGETS worldserver DESTINATION bin)
  install(FILES worldserver.conf.dist DESTINATION ${CONF_DIR})
elseif( WIN32 )
  install(TARGETS worldserver DESTINATION "${CMAKE_INSTALL_PREFIX}")
  install(FILES worldserver.conf.dist DESTINATION "${CMAKE_INSTALL_PREFIX}")
endif()

# Generate precompiled header
if( USE_COREPCH )
  add_cxx_pch(worldserver ${PRIVATE_PCH_HEADER})
endif()
