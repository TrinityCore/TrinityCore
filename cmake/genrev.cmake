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
  # Workaround for cmake script mode
  set(BUILDDIR ${CMAKE_BINARY_DIR})
endif()

if(WITHOUT_GIT)
  set(rev_date "1970-01-01 00:00:00 +0000")
  set(rev_hash "unknown")
  set(rev_branch "Archived")
  # No valid git commit date, use today
  string(TIMESTAMP rev_date_fallback "%Y-%m-%d %H:%M:%S" UTC)
else()
  if(GIT_EXECUTABLE)
    # Create a revision-string that we can use
    execute_process(
      COMMAND "${GIT_EXECUTABLE}" rev-parse --short=12 HEAD
      WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
      OUTPUT_VARIABLE rev_hash
      OUTPUT_STRIP_TRAILING_WHITESPACE
      ERROR_QUIET
    )

    if(rev_hash)
      # Retrieve repository dirty status
      execute_process(
        COMMAND "${GIT_EXECUTABLE}" diff-index --quiet HEAD --
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
        RESULT_VARIABLE is_dirty
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
    # No valid git commit date, use today
    string(TIMESTAMP rev_date_fallback "%Y-%m-%d %H:%M:%S" UTC)
  else()
    # We have valid date from git commit, use that
    set(rev_date_fallback ${rev_date})
  endif()
endif()

# For package/copyright information we always need a proper date - keep "Archived/1970" for displaying git info but a valid year elsewhere
string(REGEX MATCH "([0-9]+)-([0-9]+)-([0-9]+)" rev_date_fallback_match ${rev_date_fallback})
set(rev_year ${CMAKE_MATCH_1})
set(rev_month ${CMAKE_MATCH_2})
set(rev_day ${CMAKE_MATCH_3})

# Create the actual revision_data.h file from the above params
cmake_host_system_information(RESULT TRINITY_BUILD_HOST_SYSTEM QUERY OS_NAME)
cmake_host_system_information(RESULT TRINITY_BUILD_HOST_DISTRO QUERY DISTRIB_INFO)
cmake_host_system_information(RESULT TRINITY_BUILD_HOST_SYSTEM_RELEASE QUERY OS_RELEASE)
# on windows OS_RELEASE contains sub-type string tag like "Professional" instead of a version number and OS_VERSION has only build number
# so we grab that from cmd "ver" command
if(WIN32)
  execute_process(
    COMMAND cmd /c ver
    OUTPUT_VARIABLE TRINITY_BUILD_HOST_SYSTEM_RELEASE
  )
  string(STRIP ${TRINITY_BUILD_HOST_SYSTEM_RELEASE} TRINITY_BUILD_HOST_SYSTEM_RELEASE)
  string(REGEX MATCH "[0-9]+[.][0-9]+[.][0-9]+" TRINITY_BUILD_HOST_SYSTEM_RELEASE ${TRINITY_BUILD_HOST_SYSTEM_RELEASE})
endif()

if(CMAKE_SCRIPT_MODE_FILE)
  # hack for CMAKE_SYSTEM_PROCESSOR missing in script mode 
  set(CMAKE_PLATFORM_INFO_DIR ${BUILDDIR}${CMAKE_FILES_DIRECTORY})
  include(${CMAKE_ROOT}/Modules/CMakeDetermineSystem.cmake)
endif()

configure_file(
  "${CMAKE_SOURCE_DIR}/revision_data.h.in.cmake"
  "${BUILDDIR}/revision_data.h"
  @ONLY
)
