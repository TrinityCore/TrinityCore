# Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

execute_process(
  COMMAND hg id -n
  WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
  OUTPUT_VARIABLE hg_rev_id_str
  OUTPUT_STRIP_TRAILING_WHITESPACE
  ERROR_QUIET
)

execute_process(
  COMMAND hg id -i
  WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
  OUTPUT_VARIABLE hg_rev_hash_str
  OUTPUT_STRIP_TRAILING_WHITESPACE
  ERROR_QUIET
)

if(EXISTS ${CMAKE_SOURCE_DIR}/.hg_archival.txt)
  file(READ
    ${CMAKE_SOURCE_DIR}/.hg_archival.txt hg_rev_hash_str
    LIMIT 10
    OFFSET 7
    NEWLINE_CONSUME
  )
  string(STRIP ${hg_rev_hash_str} hg_rev_hash_str)
  set(hg_rev_id_str "Archive")
  set(hg_rev_id "0")
  set(hg_rev_hash ${hg_rev_hash_str})
endif()

# Last minute check - ensure that we have a proper revision
# If everything above fails (means the user has erased the mercurial revisional control directory, or runs archive and erased their .hg_archival.txt)
if(NOT hg_rev_id_str)
  message("")
  message(STATUS "WARNING - No revision-information found - have you been tampering with the sources?")

  # Ok, since we have no valid ways of finding/setting the revision, let's force some defaults
  set(hg_rev_hash_str "Archive")
  set(hg_rev_hash "0")
  set(hg_rev_id_str "0")
  set(hg_rev_id "0")
endif()

# Strip off excess strings (shows when the source is actually modified)
if(NOT hg_rev_id_str MATCHES "Archive")
  string(REPLACE "+" "" hg_rev_id ${hg_rev_id_str})
endif()
string(REPLACE "+" "" hg_rev_hash ${hg_rev_hash_str})

# Its not set during initial run
if(NOT BUILDDIR)
  set(BUILDDIR ${CMAKE_BINARY_DIR})
endif()

# Create the actual revision.h file from the above params
configure_file(
  "${CMAKE_SOURCE_DIR}/revision.h.in.cmake"
  "${BUILDDIR}/revision.h"
  @ONLY
)
