# Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

if( UNIX )
  # find Readline (terminal input library) includes and library
  #
  # READLINE_INCLUDE_DIR - where the directory containing the READLINE headers can be found
  # READLINE_LIBRARY     - full path to the READLINE library
  find_path(READLINE_INCLUDE_DIR readline/readline.h)
  find_library(READLINE_LIBRARY NAMES readline)

  message(STATUS "Found Readline library: ${READLINE_LIBRARY}")
  message(STATUS "Include dir is: ${READLINE_INCLUDE_DIR}")

  if (NOT READLINE_INCLUDE_DIR OR NOT READLINE_LIBRARY)
    message(FATAL_ERROR "** Readline library not found!\n** Your distro may provide a binary for Readline e.g. for ubuntu try apt-get install libreadline5-dev")
  endif ()

  add_library(readline SHARED IMPORTED GLOBAL)

  set_target_properties(readline
    PROPERTIES
      IMPORTED_LOCATION
        "${READLINE_LIBRARY}"
      INTERFACE_INCLUDE_DIRECTORIES
        "${READLINE_INCLUDE_DIR}")

else()
  # Provide a dummy target
  add_library(readline INTERFACE)
endif()
