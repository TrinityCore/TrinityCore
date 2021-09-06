# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

if(NOT BUILDDIR)
  # Workaround for funny MSVC behaviour - this segment is only used when using cmake gui
  set(BUILDDIR ${CMAKE_BINARY_DIR})
endif()

if(WITHOUT_GIT)
  set(rev_date "1970-01-01 00:00:00 +0000")
  set(rev_hash "unknown")
  set(rev_branch "Archived")
else()
  if(GIT_EXECUTABLE)
    # Retrieve repository dirty status
    execute_process(
      COMMAND "${GIT_EXECUTABLE}" diff-index --quiet HEAD --
      WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
      RESULT_VARIABLE is_dirty
    )

    # Create a revision-string that we can use
    execute_process(
      COMMAND "${GIT_EXECUTABLE}" rev-parse --short=12 HEAD
      WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
      OUTPUT_VARIABLE rev_hash
      OUTPUT_STRIP_TRAILING_WHITESPACE
      ERROR_QUIET
    )

    # Append dirty marker to commit hash
    if(is_dirty)
      set(rev_hash "${rev_hash}+")
    endif()

    # And grab the commits timestamp
    execute_process(
      COMMAND "${GIT_EXECUTABLE}" show -s --format=%ci
      WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
      OUTPUT_VARIABLE rev_date
      OUTPUT_STRIP_TRAILING_WHITESPACE
      ERROR_QUIET
    )

    # Also retrieve branch name
    execute_process(
      COMMAND "${GIT_EXECUTABLE}" symbolic-ref -q --short HEAD
      WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
      OUTPUT_VARIABLE rev_branch
      OUTPUT_STRIP_TRAILING_WHITESPACE
      ERROR_QUIET
    )

    # when ran on CI, repository is put in detached HEAD state, attempt to scan for known local branches
    if(NOT rev_branch)
      execute_process(
        COMMAND "${GIT_EXECUTABLE}" for-each-ref --points-at=HEAD refs/heads "--format=%(refname:short)"
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
        OUTPUT_VARIABLE rev_branch
        OUTPUT_STRIP_TRAILING_WHITESPACE
        ERROR_QUIET
      )
    endif()

    # if local branch scan didn't find anything, try remote branches
    if(NOT rev_branch)
      execute_process(
        COMMAND "${GIT_EXECUTABLE}" for-each-ref --points-at=HEAD refs/remotes "--format=%(refname:short)"
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
        OUTPUT_VARIABLE rev_branch
        OUTPUT_STRIP_TRAILING_WHITESPACE
        ERROR_QUIET
      )
    endif()

    # give up finding a name for branch, use commit hash
    if(NOT rev_branch)
      set(rev_branch ${rev_hash})
    endif()

    # normalize branch to single line (for-each-ref can output multiple lines if there are multiple branches on the same commit)
    string(REGEX MATCH "^[^ \t\r\n]+" rev_branch ${rev_branch})
  endif()

  # Last minute check - ensure that we have a proper revision
  # If everything above fails (means the user has erased the git revision control directory or removed the origin/HEAD tag)
  if(NOT rev_hash)
    # No valid ways available to find/set the revision/hash, so let's force some defaults
    message(STATUS "
    Could not find a proper repository signature (hash) - you may need to pull tags with git fetch -t
    Continuing anyway - note that the versionstring will be set to \"unknown 1970-01-01 00:00:00 (Archived)\"")
    set(rev_date "1970-01-01 00:00:00 +0000")
    set(rev_hash "unknown")
    set(rev_branch "Archived")
  else()
  endif()
endif()

# Create the actual revision_data.h file from the above params
if(NOT "${rev_hash_cached}" STREQUAL "${rev_hash}" OR NOT "${rev_branch_cached}" STREQUAL "${rev_branch}" OR NOT EXISTS "${BUILDDIR}/revision_data.h")
  configure_file(
    "${CMAKE_SOURCE_DIR}/revision_data.h.in.cmake"
    "${BUILDDIR}/revision_data.h"
    @ONLY
  )
  set(rev_hash_cached "${rev_hash}" CACHE INTERNAL "Cached commit-hash")
  set(rev_branch_cached "${rev_branch}" CACHE INTERNAL "Cached branch name")
endif()
