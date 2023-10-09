# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

list(APPEND PRIVATE_SOURCES ${sources_windows})

add_executable(vmap4extractor ${PRIVATE_SOURCES})

target_link_libraries(vmap4extractor
  PRIVATE
    trinity-core-interface
  PUBLIC
    common
    mpq)

set_target_properties(vmap4extractor
    PROPERTIES
      FOLDER
        "tools")

if(UNITY_BUILDS)
  set_target_properties(vmap4extractor
      PROPERTIES UNITY_BUILD ON)
  set_target_properties(vmap4extractor
      PROPERTIES
        UNITY_BUILD_MODE BATCH
        UNITY_BUILD_BATCH_SIZE 8)
endif()

if(UNIX)
  install(TARGETS vmap4extractor DESTINATION bin)
elseif(WIN32)
  install(TARGETS vmap4extractor DESTINATION "${CMAKE_INSTALL_PREFIX}")
endif()
