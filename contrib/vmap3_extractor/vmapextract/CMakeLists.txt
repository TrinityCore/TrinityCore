# Copyright (C) 2005-2009 MaNGOS project <http://getmangos.com/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

cmake_minimum_required (VERSION 2.6)
project (MANGOS_IOMAP_EXTRACTOR)

LINK_DIRECTORIES( ${LINK_DIRECTORIES} ../../libmpq/libmpq/.libs/ )
add_executable(vmapextractor adtfile.cpp  dbcfile.cpp  model.cpp  mpq_libmpq.cpp  vmapexport.cpp  wdtfile.cpp  wmo.cpp)
target_link_libraries(vmapextractor mpq)
