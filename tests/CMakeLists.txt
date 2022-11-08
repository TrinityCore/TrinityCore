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
  TEST_SOURCES
)

GroupSources(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(tests ${TEST_SOURCES})

target_link_libraries(tests
  PRIVATE
    trinity-core-interface
    game
    Catch2::Catch2)

CollectIncludeDirectories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  TEST_INCLUDES)

target_include_directories(tests
  PUBLIC
    ${TEST_INCLUDES}
  PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR})

catch_discover_tests(tests)

set_target_properties(tests
    PROPERTIES
      FOLDER
        "tests")
