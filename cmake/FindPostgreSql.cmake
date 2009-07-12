# - Find PostgreSQL
# Find the PostgreSQL includes and client library
# This module defines
#  POSTGRESQL_INCLUDE_DIR, where to find POSTGRESQL.h
#  POSTGRESQL_LIBRARIES, the libraries needed to use POSTGRESQL.
#  POSTGRESQL_FOUND, If false, do not try to use PostgreSQL.
#
# Copyright (c) 2006, Jaroslaw Staniek, <js@iidea.pl>
#
# Redistribution and use is allowed according to the terms of the BSD license.
# For details see the accompanying COPYING-CMAKE-SCRIPTS file.

# Add the postgresql and mysql include paths here

MACRO(FIND_PostgreSQL)

#  find_path(POSTGRESQL_INCLUDE_DIR libpq-fe.h

 FIND_PATH(POSTGRESQL_INCLUDE_DIR libpq-fe.h
      /usr/include/server
      /usr/include/postgresql
      /usr/include/pgsql/server
      /usr/local/include/pgsql/server
      /usr/include/postgresql/server
      /usr/include/postgresql/*/server
      /usr/local/include/postgresql/server
      /usr/local/include/postgresql/*/server
      $ENV{ProgramFiles}/PostgreSQL/*/include/server
      $ENV{SystemDrive}/PostgreSQL/*/include/server
      )

  find_library(POSTGRESQL_LIBRARIES NAMES pq libpq
     PATHS
     /usr/lib
     /usr/local/lib
     /usr/lib/postgresql
     /usr/lib64
     /usr/local/lib64
     /usr/lib64/postgresql
     $ENV{ProgramFiles}/PostgreSQL/*/lib/ms
     $ENV{SystemDrive}/PostgreSQL/*/lib/ms
     )
      
  if(POSTGRESQL_INCLUDE_DIR AND POSTGRESQL_LIBRARIES)
    set(POSTGRESQL_FOUND TRUE)
    message(STATUS "Found PostgreSQL: ${POSTGRESQL_INCLUDE_DIR}, ${POSTGRESQL_LIBRARIES}")
    INCLUDE_DIRECTORIES(${POSTGRESQL_INCLUDE_DIR})
  else(POSTGRESQL_INCLUDE_DIR AND POSTGRESQL_LIBRARIES)
    set(POSTGRESQL_FOUND FALSE)
    message(STATUS "PostgreSQL not found.")
  endif(POSTGRESQL_INCLUDE_DIR AND POSTGRESQL_LIBRARIES)

  mark_as_advanced(POSTGRESQL_INCLUDE_DIR POSTGRESQL_LIBRARIES)

ENDMACRO(FIND_PostgreSQL)