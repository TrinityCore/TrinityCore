# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

add_executable(mapextractor)

CollectAndAddSourceFiles(
  mapextractor
  ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(mapextractor
  PRIVATE
    trinity-core-interface
  PUBLIC
    extractor_common)

target_include_directories(mapextractor
  PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR})

set_target_properties(mapextractor
  PROPERTIES
    COMPILE_WARNING_AS_ERROR ${WITH_WARNINGS_AS_ERRORS}
    FOLDER "tools")

if(UNIX)
  install(TARGETS mapextractor DESTINATION bin)
elseif(WIN32)
  install(TARGETS mapextractor DESTINATION "${CMAKE_INSTALL_PREFIX}")
endif()
