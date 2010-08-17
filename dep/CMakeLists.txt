# Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
  add_subdirectory(jemalloc)
  set(JEMALLOC_LIB "jemalloc")
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
  add_subdirectory(acelite)
  add_subdirectory(zlib)
  add_subdirectory(bzip2)
endif()

add_subdirectory(g3dlite)
add_subdirectory(sockets)
add_subdirectory(gsoap)

if(TOOLS)
  add_subdirectory(libmpq)
endif()
