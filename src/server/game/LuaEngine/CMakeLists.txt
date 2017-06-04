#
# Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
# This program is free software licensed under GPL version 3
# Please see the included DOCS/LICENSE.md for more information
#

if( ${CMAKE_PROJECT_NAME} STREQUAL "MaNGOS" )

  if ( USE_COREPCH )
    include_directories(${CMAKE_CURRENT_BINARY_DIR})
    include_directories(${CMAKE_SOURCE_DIR})
  endif ()

  # Iterates through all the source files and adds them to the solution
  file(GLOB sources_localdir *.cpp *.h)

  # Adds all the method headers to its own source group
  file(GLOB method_headers  *Methods.h)
  source_group("Methods" FILES ${method_headers})

  set(LuaEngine_STAT_SRCS
    ${LuaEngine_STAT_SRCS}
    ${sources_localdir}
  )

  include_directories(
    ${CMAKE_SOURCE_DIR}/dep/zlib
    ${CMAKE_SOURCE_DIR}/dep/lualib
    ${CMAKE_BINARY_DIR}
    ${ACE_INCLUDE_DIR}
    ${MYSQL_INCLUDE_DIR}
    ${OPENSSL_INCLUDE_DIR}
  )

  add_library(LuaEngine STATIC
    ${LuaEngine_STAT_SRCS}
    ${game_STAT_SRCS}
    ${game_STAT_PCH_SRC}
  )

  include_directories(
    ${CMAKE_SOURCE_DIR}/dep/g3dlite
    ${CMAKE_SOURCE_DIR}/src/shared
    ${CMAKE_SOURCE_DIR}/src/shared/Common
    ${CMAKE_SOURCE_DIR}/src/shared/Utilities
    ${CMAKE_SOURCE_DIR}/src/shared/Log
    ${CMAKE_SOURCE_DIR}/src/shared/DataStores
    ${CMAKE_SOURCE_DIR}/src/shared/Threading
    ${CMAKE_SOURCE_DIR}/src/framework
    ${CMAKE_SOURCE_DIR}/src/framework/Platform
    ${CMAKE_SOURCE_DIR}/src/game/BattleGround
    ${CMAKE_SOURCE_DIR}/src/game/Server
    ${CMAKE_SOURCE_DIR}/src/game/vmap
    ${CMAKE_SOURCE_DIR}/src/game/Maps
    ${CMAKE_SOURCE_DIR}/src/game/MotionGenerators
    ${CMAKE_SOURCE_DIR}/src/game/Tools
    ${CMAKE_SOURCE_DIR}/src/game/References
    ${CMAKE_SOURCE_DIR}/src/game/WorldHandlers
    ${CMAKE_SOURCE_DIR}/src/game/Object
  )
  
  if( WIN32 )
    if ( MSVC )
      add_custom_command(TARGET LuaEngine
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/bin/$(ConfigurationName)/lua_scripts/extensions/"
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/extensions" "${CMAKE_BINARY_DIR}/bin/$(ConfigurationName)/lua_scripts/extensions/"
      )
    elseif ( MINGW )
      add_custom_command(TARGET LuaEngine
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/bin/lua_scripts/extensions/"
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/extensions" "${CMAKE_BINARY_DIR}/bin/ua_scripts/extensions/"
      )
    endif()
  endif()
  
  install(DIRECTORY extensions DESTINATION "${BIN_DIR}/lua_scripts/")
  
endif()
