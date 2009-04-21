# - Find libpq
# Find the native PostgreSQL includes and library
#
#  PGSQL_INCLUDE_DIR - where to find libpq-fe.h, etc.
#  PGSQL_LIBRARIES   - List of libraries when using PGSQL.
#  PGSQL_FOUND       - True if PGSQL found.

MACRO(FIND_PGSQL)
IF (PGSQL_INCLUDE_DIR)
  # Already in cache, be silent
  SET(PostgreSQL_FIND_QUIETLY TRUE)
ENDIF (PGSQL_INCLUDE_DIR)

# the registry settings checked are in order:
# - for pgInstaller 8.2.x postgresql version
# - for pgInstaller 8.3.x postgresql version
SET(PGSQL_WIN_BASE 
 "[HKEY_LOCAL_MACHINE\\SOFTWARE\\PostgreSQL\\Installations\\{B823632F-3B72-4514-8861-B961CE263224};Base Directory]"
 "[HKEY_LOCAL_MACHINE\\SOFTWARE\\PostgreSQL\\Installations\\{1F701DBD-1660-4108-B10A-FB435EA63BF0};Base Directory]")

IF(PGSQL_WIN_BASE)
  IF(MSVC)
    SET(PGSQL_SEARCH_LIB_PATHS "${PGSQL_WIN_BASE}/lib/ms")
  ELSE(MSVC)
    SET(PGSQL_SEARCH_LIB_PATHS "${PGSQL_WIN_BASE}/lib")
  ENDIF(MSVC)
ENDIF(PGSQL_WIN_BASE)

FIND_PATH(PGSQL_INCLUDE_DIR libpq-fe.h
  "[HKEY_LOCAL_MACHINE\\SOFTWARE\\PostgreSQL\\Installations\\{1F701DBD-1660-4108-B10A-FB435EA63BF0};Base Directory]/include"
  "[HKEY_LOCAL_MACHINE\\SOFTWARE\\PostgreSQL\\Installations\\{B823632F-3B72-4514-8861-B961CE263224};Base Directory]/include"
  /usr/local/pgsql/include
  /usr/local/postgresql/include
  /usr/local/include/pgsql
  /usr/local/include/postgresql
  /usr/local/include
  /usr/include/pgsql
  /usr/include/postgresql
  /usr/include
  /usr/pgsql/include
  /usr/postgresql/include
)

SET(PGSQL_NAMES pq libpq)
SET(PGSQL_SEARCH_LIB_PATHS 
  ${PGSQL_SEARCH_LIB_PATHS}
  "[HKEY_LOCAL_MACHINE\\SOFTWARE\\PostgreSQL\\Installations\\{1F701DBD-1660-4108-B10A-FB435EA63BF0};Base Directory]/lib"
  "[HKEY_LOCAL_MACHINE\\SOFTWARE\\PostgreSQL\\Installations\\{B823632F-3B72-4514-8861-B961CE263224};Base Directory]/lib"
  /usr/local/pgsql/lib 
  /usr/local/lib 
  /usr/lib
)
FIND_LIBRARY(PGSQL_LIBRARY
  NAMES ${PGSQL_NAMES}
  PATHS ${PGSQL_SEARCH_LIB_PATHS}
)

IF (PGSQL_INCLUDE_DIR AND PGSQL_LIBRARY)
  SET(PGSQL_FOUND TRUE)
  SET( PGSQL_LIBRARIES ${PGSQL_LIBRARY} )
ELSE (PGSQL_INCLUDE_DIR AND PGSQL_LIBRARY)
  SET(PGSQL_FOUND FALSE)
  SET( PGSQL_LIBRARIES )
ENDIF (PGSQL_INCLUDE_DIR AND PGSQL_LIBRARY)

IF (PGSQL_FOUND)
  IF (NOT PostgreSQL_FIND_QUIETLY)
    MESSAGE(STATUS "Found PostgreSQL: ${PGSQL_LIBRARY}")
  ENDIF (NOT PostgreSQL_FIND_QUIETLY)
ELSE (PGSQL_FOUND)
  IF (PostgreSQL_FIND_REQUIRED)
    MESSAGE(STATUS "Looked for PostgreSQL libraries named ${PGSQL_NAMES}.")
    MESSAGE(FATAL_ERROR "Could NOT find PostgreSQL library")
  ENDIF (PostgreSQL_FIND_REQUIRED)
ENDIF (PGSQL_FOUND)

MARK_AS_ADVANCED(
  PGSQL_LIBRARY
  PGSQL_INCLUDE_DIR
)
ENDMACRO(FIND_PGSQL)

