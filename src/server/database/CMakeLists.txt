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
  PRIVATE_SOURCES
  # Exclude
  ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders)

if (USE_COREPCH)
  set(PRIVATE_PCH_HEADER PrecompiledHeaders/databasePCH.h)
endif()

GroupSources(${CMAKE_CURRENT_SOURCE_DIR})

add_library(database
  ${PRIVATE_SOURCES}
)

# Do NOT add any extra include directory unless it does not create unneeded extra dependencies,
# and specially, not add any dependency to neither of these: shared, game, scripts
# This way we ensure that if either a PR does that without modifying this file,
# a compile error will be generated, either this file will be modified so it
# is detected more easily.
# While it is OK to include files from other libs as long as they don't require
# linkage (enums, defines...) it is discouraged to do so unless necessary, as it will pullute
# include_directories leading to further unnoticed dependency aditions
# Linker Depencency requirements: common
CollectIncludeDirectories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  PUBLIC_INCLUDES
  # Exclude
  ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders)

target_include_directories(database
  PUBLIC
    ${PUBLIC_INCLUDES}
  PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR})

add_definitions(-DTRINITY_API_EXPORT_DATABASE)

target_link_libraries(database
  PRIVATE
    trinity-core-interface
    mysql
  PUBLIC
    common)

set_target_properties(database
    PROPERTIES
      FOLDER
        "server")

if( BUILD_SHARED_LIBS )
  if( UNIX )
    install(TARGETS database
      LIBRARY
        DESTINATION lib)
  elseif( WIN32 )
    install(TARGETS database
      RUNTIME
        DESTINATION "${CMAKE_INSTALL_PREFIX}")
  endif()
endif()

# Generate precompiled header
if (USE_COREPCH)
  add_cxx_pch(database ${PRIVATE_PCH_HEADER})
endif ()
