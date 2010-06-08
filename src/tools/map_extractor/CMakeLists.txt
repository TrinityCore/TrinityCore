# Copyright (C) 2005-2009 MaNGOS project <http://getmangos.com/>
# Copyright (C) 2005-2010 Trinity <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

cmake_minimum_required (VERSION 2.6)
project (TRINITY_MAP_EXTRACTOR)

file(GLOB sources *.cpp)
file(GLOB loadlib_sources loadlib/*.cpp)

include_directories (${CMAKE_SOURCE_DIR}/externals/libmpq)
include_directories (${CMAKE_SOURCE_DIR}/src/tools/map-extractor/loadlib)

link_directories (${CMAKE_SOURCE_DIR}/externals/libmpq)
link_directories (${CMAKE_SOURCE_DIR}}/src/tools/map-extractor/loadlib)

add_library (loadlib ${loadlib_sources})
target_link_libraries (loadlib zlib)

add_executable (trinity-map_extractor ${sources})

target_link_libraries (trinity-map_extractor libmpq loadlib)
