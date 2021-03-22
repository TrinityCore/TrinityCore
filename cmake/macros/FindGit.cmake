# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
include(${CMAKE_SOURCE_DIR}/cmake/macros/EnsureVersion.cmake)

set(_REQUIRED_GIT_VERSION "1.7")

find_program(GIT_EXECUTABLE
  NAMES
    git git.cmd
  HINTS
    ENV PATH
  DOC "Full path to git commandline client"
)
MARK_AS_ADVANCED(GIT_EXECUTABLE)

if(NOT GIT_EXECUTABLE)
  message(FATAL_ERROR "
    Git was NOT FOUND on your system - did you forget to install a recent version, or setting the path to it?
    Observe that for revision hash/date to work you need at least version ${_REQUIRED_GIT_VERSION}")
else()
  message(STATUS "Found git binary : ${GIT_EXECUTABLE}")
  execute_process(
    COMMAND "${GIT_EXECUTABLE}" --version
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    OUTPUT_VARIABLE _GIT_VERSION
    ERROR_QUIET
  )

  # make sure we're using minimum the required version of git, so the "dirty-testing" will work properly
  ensure_version( "${_REQUIRED_GIT_VERSION}" "${_GIT_VERSION}" _GIT_VERSION_OK)

  # throw an error if we don't have a recent enough version of git...
  if(NOT _GIT_VERSION_OK)
    message(STATUS "Git version too old : ${_GIT_VERSION}")
    message(FATAL_ERROR "
      Git was found but is OUTDATED - did you forget to install a recent version, or setting the path to it?
      Observe that for revision hash/date to work you need at least version ${_REQUIRED_GIT_VERSION}, found ${_GIT_VERSION}")
  endif()
endif()
