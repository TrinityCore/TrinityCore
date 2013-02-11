# Copyright (C) 2008-2013 Trinity <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

# User has manually chosen to ignore the git-tests, so throw them a warning.
# This is done EACH compile so they can be alerted about the consequences.
if(WITHOUT_GIT)
  message(STATUS "
  By choosing the WITHOUT_GIT option, you waive all rights for support, and accept
  that any or all requests for assistance by you to core developers will be rejected.
  You, as user, take full responsibility for issues, problems etc that might arise
  from using the core, as we we can not properly detect what codebase you're using.
  We remind you that you need to use the repository and a proper version of git for
  the revision/hash to work, and thus get our support if the need arises.
  ")
  set(rev_date "1970-01-01 00:00:00 +0000")
  set(rev_hash "Archived")
else()
  # Workaround for funny MSVC behaviour - this segment only run during compile
  if(NOT BUILDDIR)
    set(BUILDDIR ${CMAKE_BINARY_DIR})
    set(_GIT_EXEC ${GIT_EXECUTABLE})
  endif()

  if(_GIT_EXEC)
    # Create a revision-string that we can use
    execute_process(
      COMMAND "${_GIT_EXEC}" describe --match init --dirty=+ --abbrev=12
      WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
      OUTPUT_VARIABLE rev_info
      OUTPUT_STRIP_TRAILING_WHITESPACE
      ERROR_QUIET
    )

  # And grab the commits timestamp
    execute_process(
      COMMAND "${_GIT_EXEC}" show -s --format=%ci
      WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
      OUTPUT_VARIABLE rev_date
      OUTPUT_STRIP_TRAILING_WHITESPACE
      ERROR_QUIET
    )
  endif()
endif()

# Last minute check - ensure that we have a proper revision
# If everything above fails (means the user has erased the git revision control directory or removed the origin/HEAD tag)

if(NOT rev_info)
  # No valid ways available to find/set the revision/hash, so let's force some defaults
  message(STATUS "WARNING - Missing repository tags - you may need to pull tags with git fetch -t")
  message(STATUS "WARNING - Continuing anyway - note that the versionstring will be set to 0000-00-00 00:00:00 (Archived)")
  set(rev_date "1970-01-01 00:00:00 +0000")
  set(rev_hash "Archived")
else()
  # Extract information required to build a proper versionstring
  string(REGEX REPLACE init-|[0-9]+-g "" rev_hash ${rev_info})
endif()

# Create the actual revision.h file from the above params
if(NOT "${rev_hash_cached}" MATCHES "${rev_hash}")
  configure_file(
    "${CMAKE_SOURCE_DIR}/revision.h.in.cmake"
    "${BUILDDIR}/revision.h"
    @ONLY
  )
  set(rev_hash_cached "${rev_hash}" CACHE INTERNAL "Cached commit-hash")
endif()
