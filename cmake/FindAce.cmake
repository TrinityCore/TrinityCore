# This script is taken from BFilter project, thanks to original authors.
# - Locate the ACE library
# This module defines
#  ACE_FOUND -- true if ACE was found
#  ACE_LIBRARY -- the library to link against
#  ACE_INCLUDE_DIR -- path to ace/ACE.h
MACRO(FIND_ACE LIBNAME)
    GET_FILENAME_COMPONENT(parent_dir_ "${PROJECT_SOURCE_DIR}/.." ABSOLUTE)
    FIND_PATH(
        ACE_INCLUDE_DIR ace/ACE.h
        PATHS /usr/include /usr/local/include
        "${CMAKE_INSTALL_PREFIX}/include" "${parent_dir_}/ACE_wrappers"
        DOC "Path to ace/ACE.h"
    )

    # This prevents it being taken from cache. - but also broke cmake -i, so we dont use it
    # SET(ACE_LIBRARY ACE_LIBRARY-NOTFOUND)

    FIND_LIBRARY(
        ACE_LIBRARY "${LIBNAME}"
        PATHS /usr/lib /usr/local/lib
        "${CMAKE_INSTALL_PREFIX}/lib" "${parent_dir_}/ACE_wrappers/ace"
        DOC "Path to ACE library file"
    )
    IF(ACE_INCLUDE_DIR AND ACE_LIBRARY)
        SET(ACE_FOUND TRUE)
    ELSE(ACE_INCLUDE_DIR AND ACE_LIBRARY)
        SET(ACE_FOUND FALSE)
    ENDIF(ACE_INCLUDE_DIR AND ACE_LIBRARY)
ENDMACRO(FIND_ACE)

