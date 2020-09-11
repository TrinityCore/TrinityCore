# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

include(CheckSymbolExists)

set(strtod_l_headers stdlib.h)

if (APPLE)
  set(strtod_l_headers ${strtod_l_headers} xlocale.h)
endif ()

if(WIN32)
  check_symbol_exists(_strtod_l "${strtod_l_headers}" HAVE_STRTOD_L)
else()
  check_symbol_exists(strtod_l "${strtod_l_headers}" HAVE_STRTOD_L)
endif()

set(FMT_HEADERS 
  include/fmt/chrono.h
  include/fmt/color.h
  include/fmt/compile.h
  include/fmt/core.h
  include/fmt/format.h
  include/fmt/format-inl.h
  include/fmt/locale.h
  include/fmt/os.h
  include/fmt/ostream.h
  include/fmt/posix.h
  include/fmt/printf.h
  include/fmt/ranges.h)

set(FMT_SOURCES
  src/format.cc
  src/os.cc)

add_library(fmt STATIC ${FMT_SOURCES} ${FMT_HEADERS})

if (HAVE_STRTOD_L)
  target_compile_definitions(fmt 
    PUBLIC 
      FMT_LOCALE)
endif()

target_include_directories(fmt

  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(fmt
  PRIVATE
    trinity-dependency-interface)

set_target_properties(fmt
  PROPERTIES
    FOLDER
      "dep")
