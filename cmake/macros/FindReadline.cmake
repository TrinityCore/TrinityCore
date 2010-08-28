# find Readline (terminal input library) includes and library
#
# READLINE_INCLUDE_DIR - where the directory containing the READLINE headers can be found
# READLINE_LIBRARY     - full path to the READLINE library
# READLINE_FOUND       - TRUE if READLINE was found

FIND_PATH(READLINE_INCLUDE_DIR readline/readline.h)
FIND_LIBRARY(READLINE_LIBRARY NAMES readline) 

IF (READLINE_INCLUDE_DIR AND READLINE_LIBRARY)
    SET(READLINE_FOUND TRUE)
    MESSAGE(STATUS "Found Readline library: ${READLINE_LIBRARY}")
    MESSAGE(STATUS "Include dir is: ${READLINE_INCLUDE_DIR}")
    INCLUDE_DIRECTORIES(${READLINE_INCLUDE_DIR})
ELSE (READLINE_INCLUDE_DIR AND READLINE_LIBRARY)
    SET(READLINE_FOUND FALSE)
    MESSAGE(FATAL_ERROR "** Readline library not found!\n** Your distro may provide a binary for Readline e.g. for ubuntu try apt-get install libreadline5-dev")
ENDIF (READLINE_INCLUDE_DIR AND READLINE_LIBRARY)
