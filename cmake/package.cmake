# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

# Define install candidates for SQL files
include(GNUInstallDirs)
install(DIRECTORY "${CMAKE_SOURCE_DIR}/sql" DESTINATION "${CMAKE_INSTALL_DATADIR}/${PROJECT_NAME}")

# Download the full database
set(FULL_DATABASE_URL "https://github.com/TrinityCore/TrinityCore/releases/download/TDB335.20011/TDB_full_world_335.20011_2020_01_15.7z"
    CACHE STRING
    "The url to download the full database from"
)
get_filename_component(FULL_DATABASE_NAME "${FULL_DATABASE_URL}" NAME)
string(REGEX REPLACE "\\.[^.]*$" "" FULL_DATABASE_NAMEWE ${FULL_DATABASE_NAME})
if(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/${FULL_DATABASE_NAME}")
  file(DOWNLOAD
    "${FULL_DATABASE_URL}"
    "${CMAKE_CURRENT_BINARY_DIR}/${FULL_DATABASE_NAME}"
  )

  execute_process(
    COMMAND
      ${CMAKE_COMMAND} -E tar xzf "${CMAKE_CURRENT_BINARY_DIR}/${FULL_DATABASE_NAME}"
    WORKING_DIRECTORY
      ${CMAKE_CURRENT_BINARY_DIR}
  )
endif()

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${FULL_DATABASE_NAMEWE}.sql" DESTINATION "${CONF_DIR}")

if(NOT CPACK_GENERATOR)
  set(CPACK_GENERATOR "DEB")
endif()
if(SERVERS AND TOOLS)
  set(CPACK_PACKAGE_NAME "trinity")
  set(CPACK_DEBIAN_PACKAGE_CONFLICTS "trinity-server, trinity-tools")
  set(CPACK_DEBIAN_PACKAGE_PROVIDES "trinity-server, trinity-tools")
elseif(SERVERS)
  set(CPACK_PACKAGE_NAME "trinity-server")
  set(CPACK_DEBIAN_PACKAGE_CONFLICTS "trinity")
elseif(TOOLS)
  set(CPACK_PACKAGE_NAME "trinity-tools")
  set(CPACK_DEBIAN_PACKAGE_CONFLICTS "trinity")
endif()

execute_process(
    COMMAND dpkg --print-architecture
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    OUTPUT_VARIABLE CPACK_PACKAGE_ARCHITECTURE
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_QUIET
)

# autogenerate dependency information
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
# Additional dependencies
set(CPACK_DEBIAN_PACKAGE_DEPENDS "mariadb-client")

set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${rev_branch}-${rev_hash}-${CPACK_PACKAGE_ARCHITECTURE}")
set(CPACK_PACKAGE_VERSION_MAJOR "${rev_version_major}")
set(CPACK_PACKAGE_VERSION_MINOR "${rev_version_minor}")
set(CPACK_PACKAGE_VERSION_PATCH "${rev_version_patch}")
string(REPLACE "/" "_" CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_FILE_NAME}")

message("* Package filename       : ${CPACK_PACKAGE_FILE_NAME}")

include(CPack)
