#
# This file is part of the DragonCore Project. See AUTHORS file for Copyright information
#
# This program is free software; you can redistribute it and/or modify it
# under the terms of the GNU Affero General Public License as published by the
# Free Software Foundation; either version 3 of the License, or (at your
# option) any later version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
# FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for
# more details.
#
# You should have received a copy of the GNU General Public License along
# with this program. If not, see <http://www.gnu.org/licenses/>.
#

CollectSourceFiles(${CMAKE_CURRENT_SOURCE_DIR} PRIVATE_SOURCES)

if (WIN32)
  list(APPEND PRIVATE_SOURCES ${sources_windows})
endif()

GroupSources(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(cert_creator ${PRIVATE_SOURCES})

target_link_libraries(cert_creator
  PRIVATE
    trinity-core-interface
  PUBLIC
    common
)

if (UNIX)
  install(TARGETS cert_creator DESTINATION bin)
elseif (WIN32)
  install(TARGETS cert_creator DESTINATION "${CMAKE_INSTALL_PREFIX}")
endif ()
