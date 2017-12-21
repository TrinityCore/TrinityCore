#
# Copyright (C) 2010 - 2014 Eluna Lua Engine <http://emudevs.com/>
# This program is free software licensed under GPL version 3
# Please see the included DOCS/LICENSE.md for more information
#

file(GLOB sources *.c)
list(REMOVE_ITEM sources ${CMAKE_CURRENT_SOURCE_DIR}/lua.c)
list(REMOVE_ITEM sources ${CMAKE_CURRENT_SOURCE_DIR}/luac.c)

set(lua_STAT_SRCS
  ${sources}
)

add_library(lualib STATIC ${lua_STAT_SRCS})


target_include_directories(lualib
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(lualib
  PRIVATE
    trinity-dependency-interface)
