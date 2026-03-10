# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

add_library(fmt STATIC)

target_sources(fmt
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS include
    FILES
      include/fmt/args.h
      include/fmt/base.h
      include/fmt/chrono.h
      include/fmt/color.h
      include/fmt/compile.h
      include/fmt/core.h
      include/fmt/format.h
      include/fmt/format-inl.h
      include/fmt/os.h
      include/fmt/ostream.h
      include/fmt/printf.h
      include/fmt/ranges.h
      include/fmt/std.h
      include/fmt/xchar.h)

target_sources(fmt
  PRIVATE
    src/format.cc
    src/os.cc)

target_link_libraries(fmt
  PRIVATE
    trinity-dependency-interface)

set_target_properties(fmt
  PROPERTIES
    FOLDER
      "dep")
