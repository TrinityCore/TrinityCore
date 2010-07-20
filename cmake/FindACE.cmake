#
# Find the ACE client includes and library
# 

# This module defines
# ACE_INCLUDE_DIR, where to find ace.h
# ACE_LIBRARIES, the libraries to link against
# ACE_FOUND, if false, you cannot build anything that requires ACE

# also defined, but not for general use are
# ACE_LIBRARY, where to find the ACE library.

set( ACE_FOUND 0 )

if ( UNIX )
  FIND_PATH( ACE_INCLUDE_DIR
    NAMES
      ace/ACE.h
    PATHS
      /usr/include
      /usr/include/ace
      /usr/local/include
      /usr/local/include/ace
      $ENV{ACE_ROOT}
      $ENV{ACE_ROOT}/include
      ${CMAKE_SOURCE_DIR}/externals/ace
  DOC
    "Specify include-directories that might contain ace.h here."
  )
  FIND_LIBRARY( ACE_LIBRARY 
    NAMES
      ace ACE
    PATHS
      /usr/lib
      /usr/lib/ace
      /usr/local/lib
      /usr/local/lib/ace
      /usr/local/ace/lib
      $ENV{ACE_ROOT}/lib
      $ENV{ACE_ROOT}
    DOC "Specify library-locations that might contain the ACE library here."
  )

#  FIND_LIBRARY( ACE_EXTRA_LIBRARIES
#    NAMES
#      z zlib
#    PATHS
#      /usr/lib
#      /usr/local/lib
#    DOC
#      "if more libraries are necessary to link into ACE, specify them here."
#  )

  if ( ACE_LIBRARY )
    if ( ACE_INCLUDE_DIR )
      set( ACE_FOUND 1 )
      message( STATUS "Found ACE library: ${ACE_LIBRARY}")
      message( STATUS "Found ACE headers: ${ACE_INCLUDE_DIR}")
    else ( ACE_INCLUDE_DIR )
      message(FATAL_ERROR "Could not find ACE headers! Please install ACE libraries and headers")
    endif ( ACE_INCLUDE_DIR )
  endif ( ACE_LIBRARY )

  mark_as_advanced( ACE_FOUND ACE_LIBRARY ACE_EXTRA_LIBRARIES ACE_INCLUDE_DIR )
endif (UNIX)
