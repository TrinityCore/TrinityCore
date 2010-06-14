# - Find MySQL
# Find the MySQL includes and client library
# This module defines
#  MYSQL_INCLUDE_DIR, where to find mysql.h
#  MYSQL_LIBRARIES, the libraries needed to use MySQL.
#  MYSQL_FOUND, If false, do not try to use MySQL.
#
# Copyright (c) 2006, Jaroslaw Staniek, <js@iidea.pl>
# Lot of adustmens by Michal Cihar <michal@cihar.com>
#
# vim: expandtab sw=4 ts=4 sts=4:
#
# Redistribution and use is allowed according to the terms of the BSD license.

MACRO(FIND_MYSQL)
if(UNIX) 
    set(MYSQL_CONFIG_PREFER_PATH "$ENV{MYSQL_HOME}/bin" CACHE FILEPATH
        "preferred path to MySQL (mysql_config)")
    find_program(MYSQL_CONFIG mysql_config
        ${MYSQL_CONFIG_PREFER_PATH}
        /usr/local/mysql/bin/
        /usr/local/bin/
        /usr/bin/
        )
    
    if(MYSQL_CONFIG) 
        message(STATUS "Using mysql-config: ${MYSQL_CONFIG}")
        # set INCLUDE_DIR
        exec_program(${MYSQL_CONFIG}
            ARGS --include
            OUTPUT_VARIABLE MY_TMP)

        string(REGEX REPLACE "-I([^ ]*)( .*)?" "\\1" MY_TMP "${MY_TMP}")

        set(MYSQL_ADD_INCLUDE_DIR ${MY_TMP} CACHE FILEPATH INTERNAL)

        # set LIBRARY_DIR
        exec_program(${MYSQL_CONFIG}
            ARGS --libs_r
            OUTPUT_VARIABLE MY_TMP)

        set(MYSQL_ADD_LIBRARIES "")

        string(REGEX MATCHALL "-l[^ ]*" MYSQL_LIB_LIST "${MY_TMP}")
        foreach(LIB ${MYSQL_LIB_LIST})
            string(REGEX REPLACE "[ ]*-l([^ ]*)" "\\1" LIB "${LIB}")
            list(APPEND MYSQL_ADD_LIBRARIES "${LIB}")
        endforeach(LIB ${MYSQL_LIBS})

        set(MYSQL_ADD_LIBRARY_PATH "")

        string(REGEX MATCHALL "-L[^ ]*" MYSQL_LIBDIR_LIST "${MY_TMP}")
        foreach(LIB ${MYSQL_LIBDIR_LIST})
            string(REGEX REPLACE "[ ]*-L([^ ]*)" "\\1" LIB "${LIB}")
            list(APPEND MYSQL_ADD_LIBRARY_PATH "${LIB}")
        endforeach(LIB ${MYSQL_LIBS})

    else(MYSQL_CONFIG)
        set(MYSQL_ADD_LIBRARIES "")
        list(APPEND MYSQL_ADD_LIBRARIES "mysqlclient")
    endif(MYSQL_CONFIG)
else(UNIX)
    set(MYSQL_ADD_INCLUDE_DIR "c:/msys/local/include" CACHE FILEPATH INTERNAL)
    set(MYSQL_ADD_LIBRARY_PATH "c:/msys/local/lib" CACHE FILEPATH INTERNAL)
ENDIF(UNIX)

find_path(MYSQL_INCLUDE_DIR mysql.h
    ${MYSQL_ADD_INCLUDE_DIR}
    /usr/include
    /usr/include/mysql
    /usr/local/include
    /usr/local/include/mysql
    /usr/local/mysql/include
    /usr/local/mysql/include/mysql
    "C:/Program Files/MySQL/include"
    "C:/Program Files/MySQL/MySQL Server 5.0/include"
    "C:/MySQL/include"
    "[HKEY_LOCAL_MACHINE\\SOFTWARE\\MySQL AB\\MySQL Server 5.0;Location]/include"
    "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Wow6432Node\\MySQL AB\\MySQL Server 5.0;Location]/include"
    DOC "Specify the directory containing mysql.h."
)

set(TMP_MYSQL_LIBRARIES "")

foreach(LIB ${MYSQL_ADD_LIBRARIES})
    find_library("MYSQL_LIBRARIES_${LIB}" NAMES ${LIB}
        PATHS
        ${MYSQL_ADD_LIBRARY_PATH}
        /usr/lib
        /usr/lib/mysql
        /usr/local/lib
        /usr/local/lib/mysql
        /usr/local/mysql/lib
        "C:/Program Files/MySQL/lib"
        "C:/Program Files/MySQL/MySQL Server 5.0/lib/opt"
        "C:/MySQL/lib/debug"
        "[HKEY_LOCAL_MACHINE\\SOFTWARE\\MySQL AB\\MySQL Server 5.0;Location]/lib/opt"
        "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Wow6432Node\\MySQL AB\\MySQL Server 5.0;Location]/lib/opt"
        DOC "Specify the mysql library here."
    )
    list(APPEND TMP_MYSQL_LIBRARIES "${MYSQL_LIBRARIES_${LIB}}")
endforeach(LIB ${MYSQL_ADD_LIBRARIES})

set(MYSQL_LIBRARIES ${TMP_MYSQL_LIBRARIES} CACHE FILEPATH INTERNAL)

if(MYSQL_INCLUDE_DIR AND MYSQL_LIBRARIES)
    set(MYSQL_FOUND TRUE CACHE INTERNAL "MySQL found")
    message(STATUS "Found MySQL: ${MYSQL_INCLUDE_DIR}, ${MYSQL_LIBRARIES}")
else(MYSQL_INCLUDE_DIR AND MYSQL_LIBRARIES)
    set(MYSQL_FOUND FALSE CACHE INTERNAL "MySQL found")
    message(STATUS "MySQL not found.")
endif(MYSQL_INCLUDE_DIR AND MYSQL_LIBRARIES)

mark_as_advanced(MYSQL_INCLUDE_DIR MYSQL_LIBRARIES)
ENDMACRO(FIND_MYSQL)
