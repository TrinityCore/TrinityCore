# Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
# Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA


set (libMPQ_SRCS
	libmpq/common.c
	libmpq/common.h
	libmpq/crypt_buf.h
	libmpq/explode.c
	libmpq/explode.h
	libmpq/extract.c
	libmpq/extract.h
	libmpq/huffman.c
	libmpq/huffman.h
	libmpq/mpq.c
	libmpq/mpq.h
	libmpq/mpq-internal.h
	libmpq/pack_begin.h
	libmpq/pack_end.h
	libmpq/platform.h
	libmpq/wave.c
	libmpq/wave.h
)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/dep/include/bzip2
)

add_library(libmpq STATIC
	${libMPQ_SRCS}
)

if(UNIX)
  find_package(ZLIB REQUIRED)
  if(ZLIB_FOUND)
    include_directories(${ZLIB_INCLUDE_DIRS})
    target_link_libraries(libmpq ${ZLIB_LIBRARIES})
  endif(ZLIB_FOUND)
else()
  include_directories(${CMAKE_SOURCE_DIR}/dep/windows/include/zlib)
  if(MINGW)
    target_link_libraries(libmpq zlib)
  endif()
endif()

SET_TARGET_PROPERTIES (libmpq PROPERTIES FOLDER "3rd Party")
