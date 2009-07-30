# - Find mysqlclient
# Find the native MySQL includes and library
#
#  MYSQL_INCLUDE_DIR - where to find mysql.h, etc.
#  MYSQL_LIBRARIES   - List of libraries when using MySQL.
#  MYSQL_FOUND       - True if MySQL found.
MACRO(FIND_MYSQL)

IF (MYSQL_INCLUDE_DIR)
  # Already in cache, be silent
  SET(MySQL_FIND_QUIETLY TRUE)
ENDIF (MYSQL_INCLUDE_DIR)

FIND_PATH(MYSQL_INCLUDE_DIR mysql.h
  "[HKEY_LOCAL_MACHINE\\SOFTWARE\\MySQL AB\\MySQL Server 6.0;Location]/include"
  "[HKEY_LOCAL_MACHINE\\SOFTWARE\\MySQL AB\\MySQL Server 5.1;Location]/include"
  "[HKEY_LOCAL_MACHINE\\SOFTWARE\\MySQL AB\\MySQL Server 5.0;Location]/include"
  "[HKEY_LOCAL_MACHINE\\SOFTWARE\\MySQL AB\\MySQL Server 4.1;Location]/include"
  "[HKEY_LOCAL_MACHINE\\SOFTWARE\\MySQL AB\\MySQL Server 4.0;Location]/include"
  /usr/local/mysql/include
  /usr/local/include/mysql
  /usr/local/include
  /usr/include/mysql
  /usr/include
  /usr/mysql/include
)

IF(MSVC)
  SET(MYSQL_NAMES libmysql)
ELSE(MSVC)
  SET(MYSQL_NAMES mysqlclient mysqlclient_r)
ENDIF(MSVC)
SET(MYSQL_SEARCH_LIB_PATHS
  "[HKEY_LOCAL_MACHINE\\SOFTWARE\\MySQL AB\\MySQL Server 6.0;Location]/lib/opt"
  "[HKEY_LOCAL_MACHINE\\SOFTWARE\\MySQL AB\\MySQL Server 5.1;Location]/lib/opt"
  "[HKEY_LOCAL_MACHINE\\SOFTWARE\\MySQL AB\\MySQL Server 5.0;Location]/lib/opt"
  "[HKEY_LOCAL_MACHINE\\SOFTWARE\\MySQL AB\\MySQL Server 4.1;Location]/lib/opt"
  "[HKEY_LOCAL_MACHINE\\SOFTWARE\\MySQL AB\\MySQL Server 4.0;Location]/lib/opt"
  /usr/local/mysql/lib
  /usr/local/lib/mysql
  /usr/local/lib
  /usr/lib/mysql
  /usr/lib
)
FIND_LIBRARY(MYSQL_LIBRARY
  NAMES ${MYSQL_NAMES}
  PATHS ${MYSQL_SEARCH_LIB_PATHS}
)

IF (MYSQL_INCLUDE_DIR AND MYSQL_LIBRARY)
  SET(MYSQL_FOUND TRUE)
  SET( MYSQL_LIBRARIES ${MYSQL_LIBRARY} )
ELSE (MYSQL_INCLUDE_DIR AND MYSQL_LIBRARY)
  SET(MYSQL_FOUND FALSE)
  SET( MYSQL_LIBRARIES )
ENDIF (MYSQL_INCLUDE_DIR AND MYSQL_LIBRARY)

IF (MYSQL_FOUND)
  IF (NOT MySQL_FIND_QUIETLY)
    MESSAGE(STATUS "Found MySQL: ${MYSQL_LIBRARY}")
  ENDIF (NOT MySQL_FIND_QUIETLY)
ELSE (MYSQL_FOUND)
  IF (MySQL_FIND_REQUIRED)
    MESSAGE(STATUS "Looked for MySQL libraries named ${MYSQL_NAMES}.")
    MESSAGE(FATAL_ERROR "Could NOT find MySQL library")
  ENDIF (MySQL_FIND_REQUIRED)
ENDIF (MYSQL_FOUND)

MARK_AS_ADVANCED(
  MYSQL_LIBRARY
  MYSQL_INCLUDE_DIR
)

ENDMACRO(FIND_MYSQL)
