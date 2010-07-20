# default to x86 platform.  We'll check for X64 in a bit
SET(PLATFORM X86)

# This definition is necessary to work around a bug with Intellisense described
# here: http://tinyurl.com/2cb428.  Syntax highlighting is important for proper
# debugger functionality.

IF(CMAKE_SIZEOF_VOID_P MATCHES 8)
    MESSAGE(STATUS "Detected 64-bit platform.")
    if(WIN32)
      ADD_DEFINITIONS("-D_WIN64")
    ENDIF()
    SET (PLATFORM X64)
ELSE()
    MESSAGE(STATUS "Detected 32-bit platform.")
ENDIF()
