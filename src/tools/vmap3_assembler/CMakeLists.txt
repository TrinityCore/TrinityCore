# Copyright (C) 2005-2009 MaNGOS project <http://getmangos.com/>
# Copyright (C) 2005-2009 MaNGOS Trinity <http://www,trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

cmake_minimum_required (VERSION 2.6)
#project (MANGOS_VMAP_ASSEMB_IO)

#set(CMAKE_VERBOSE_MAKEFILE true)

# uncomment next line to disable debug mode
#ADD_DEFINITIONS("-DIOMAP_DEBUG")
#ADD_DEFINITIONS("-Wall")
#ADD_DEFINITIONS("-ggdb")
#ADD_DEFINITIONS("-O3")

include_directories(${CMAKE_SOURCE_FILE}/src/server/collision)
include_directories(${CMAKE_SOURCE_FILE}/externals/g3dlite)
include_directories(${ACE_INCLUDE_DIR})

add_executable(trinity-collision_assembler VMapAssembler.cpp)
target_link_libraries(trinity-collision_assembler collision g3dlite)

# add_executable(vmap_test coordinate_test.cpp)
# target_link_libraries(vmap_test vmap)

