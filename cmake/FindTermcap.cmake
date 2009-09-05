# find Terrmcap (terminal input library) includes and library
#
# TERMCAP_INCLUDE_DIR - where the directory containing the TERMCAP headers can be found
# TERMCAP_LIBRARY     - full path to the TERMCAP library
# TERMCAP_FOUND       - TRUE if TERMCAP was found

MACRO(FIND_TERMCAP)

FIND_PATH(TERMCAP_INCLUDE_DIR termcap.h
    /usr/include
    /usr/local/include

    /opt/local/include
)

FIND_LIBRARY(TERMCAP_LIBRARY NAMES termcap PATH
    /usr/lib
    /usr/local/lib
    /opt/local/lib
    /usr/lib64
) 

IF (TERMCAP_INCLUDE_DIR AND TERMCAP_LIBRARY)
    SET(TERMCAP_FOUND TRUE)
    MESSAGE(STATUS "Found GNU termcap: ${TERMCAP_LIBRARY}")
    MESSAGE(STATUS "Include dir is: ${TERMCAP_INCLUDE_DIR}")
    INCLUDE_DIRECTORIES(${TERMCAP_INCLUDE_DIR})
ELSE (TERMCAP_INCLUDE_DIR AND TERMCAP_LIBRARY)
    SET(TERMCAP_FOUND FALSE)
    MESSAGE(FATAL_ERROR "Could not find GNU termcap")
ENDIF (TERMCAP_INCLUDE_DIR AND TERMCAP_LIBRARY)

ENDMACRO(FIND_TERMCAP)
