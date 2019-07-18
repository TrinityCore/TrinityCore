# Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

CollectSourceFiles(
  ${CMAKE_CURRENT_SOURCE_DIR}
  PRIVATE_SOURCES)

add_library(extractor_common STATIC ${PRIVATE_SOURCES})

target_link_libraries(extractor_common
  PRIVATE
    trinity-core-interface
  PUBLIC
    casc
    common)

target_include_directories(extractor_common
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR})
