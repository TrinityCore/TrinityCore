# Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

if(NOT MACOSX)
  add_subdirectory(jemalloc)
endif()

if(NOT UNIX)
  add_subdirectory(ace)
  add_subdirectory(zlib)
  add_subdirectory(bzip2)
endif()

add_subdirectory(g3dlite)
add_subdirectory(sockets)

# temporary disable libmpq building (through CMake at least) for now
# - needs a proper CMakeLists.txt
#add_subdirectory(libmpq)
