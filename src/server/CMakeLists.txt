# Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

# Enforce compileparameters for corebuilds under GCC
# This to stop a few silly crashes that could have been avoided IF people
# weren't doing some -O3 psychooptimizations etc.

find_package(MySQL REQUIRED)

if(CMAKE_COMPILER_IS_GNUCXX AND NOT MINGW)
  add_definitions(-fno-delete-null-pointer-checks)
endif()

set(sources_windows_Debugging
  ${CMAKE_SOURCE_DIR}/src/common/Debugging/WheatyExceptionReport.cpp
  ${CMAKE_SOURCE_DIR}/src/common/Debugging/WheatyExceptionReport.h
)
add_subdirectory(database)
add_subdirectory(shared)
add_subdirectory(game)
add_subdirectory(ipc)
add_subdirectory(authserver)
add_subdirectory(bnetserver)
add_subdirectory(scripts)
add_subdirectory(worldserver)
