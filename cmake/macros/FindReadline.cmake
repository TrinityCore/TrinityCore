# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This program is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the
# Free Software Foundation; either version 2 of the License, or (at your
# option) any later version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
# FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
# more details.
#
# You should have received a copy of the GNU General Public License along
# with this program. If not, see <http://www.gnu.org/licenses/>.

#[=======================================================================[.rst:
FindReadline
-----------

Find The GNU Readline Library.

Imported Targets
^^^^^^^^^^^^^^^^

This module defines the following :prop_tgt:`IMPORTED` targets:

``Readline::Readline``
  The Readline library, if found.

Result Variables
^^^^^^^^^^^^^^^^

This module will set the following variables in your project:

``READLINE_FOUND``
  System has The GNU Readline Library.
``READLINE_INCLUDE_DIR``
  The Readline include directory.
``READLINE_LIBRARY``
  The Readline library.

Hints
^^^^^

Set ``READLINE_ROOT_DIR`` to the root directory of Readline installation.
#]=======================================================================]

set(_READLINE_ROOT_HINTS
  ${READLINE_ROOT_DIR}
  ENV READLINE_ROOT_DIR
)

if(HOMEBREW_PREFIX)
  list(APPEND _READLINE_ROOT_HINTS "${HOMEBREW_PREFIX}/opt/readline")
endif()

find_path(READLINE_INCLUDE_DIR
  NAMES
    readline/readline.h
  HINTS
    ${_READLINE_ROOT_HINTS}
  PATH_SUFFIXES
    include)

find_library(READLINE_LIBRARY
  NAMES
    readline
  HINTS
    ${_READLINE_ROOT_HINTS}
  PATH_SUFFIXES
    lib)

if(READLINE_INCLUDE_DIR AND EXISTS "${READLINE_INCLUDE_DIR}/readline/readline.h")
  file(STRINGS "${READLINE_INCLUDE_DIR}/readline/readline.h" readline_major
    REGEX "^#[\t ]*define[\t ]+RL_VERSION_MAJOR[\t ]+([0-9])+.*")
  file(STRINGS "${READLINE_INCLUDE_DIR}/readline/readline.h" readline_minor
    REGEX "^#[\t ]*define[\t ]+RL_VERSION_MINOR[\t ]+([0-9])+.*")
  if (readline_major AND readline_minor)
    string(REGEX REPLACE "^.*RL_VERSION_MAJOR[\t ]+([0-9])+.*$"
           "\\1" readline_major "${readline_major}")
    string(REGEX REPLACE "^.*RL_VERSION_MINOR[\t ]+([0-9])+.*$"
           "\\1" readline_minor "${readline_minor}")
    set(READLINE_VERSION "${readline_major}.${readline_minor}")
  endif()
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Readline
  REQUIRED_VARS
    READLINE_LIBRARY
    READLINE_INCLUDE_DIR
  VERSION_VAR
    READLINE_VERSION
)

mark_as_advanced(READLINE_FOUND READLINE_LIBRARY READLINE_INCLUDE_DIR)

if(READLINE_FOUND)
  message(STATUS "Found Readline library: ${READLINE_LIBRARY}")
  message(STATUS "Found Readline headers: ${READLINE_INCLUDE_DIR}")

  if (NOT TARGET Readline::Readline)
    add_library(Readline::Readline UNKNOWN IMPORTED)
    set_target_properties(Readline::Readline
      PROPERTIES
        IMPORTED_LOCATION
          "${READLINE_LIBRARY}"
        INTERFACE_INCLUDE_DIRECTORIES
          "${READLINE_INCLUDE_DIR}")
  endif()
endif()
