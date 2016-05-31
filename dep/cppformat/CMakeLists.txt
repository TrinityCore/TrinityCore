# Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

include(CheckSymbolExists)
if (WIN32)
  check_symbol_exists(open io.h HAVE_OPEN)
else ()
  check_symbol_exists(open fcntl.h HAVE_OPEN)
endif ()

set(FMT_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/cppformat/format.h
  ${CMAKE_CURRENT_SOURCE_DIR}/cppformat/format.cc)

if (HAVE_OPEN)
  set(FMT_SOURCES ${FMT_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/cppformat/posix.h
    ${CMAKE_CURRENT_SOURCE_DIR}/cppformat/posix.cc)
endif()

add_library(cppformat STATIC ${FMT_SOURCES})

target_include_directories(cppformat
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(cppformat
    PROPERTIES
      FOLDER
        "dep")
