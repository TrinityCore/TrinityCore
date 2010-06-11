# Copyright (C) 2005-2009 MaNGOS project <http://getmangos.com/>
# Copyright (C) 2005-2010 Trinity <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

include_directories (${CMAKE_SOURCE_DIR}/externals/libmpq)

add_executable(vmap3extractor adtfile.cpp  dbcfile.cpp  model.cpp  mpq_libmpq.cpp  vmapexport.cpp  wdtfile.cpp  wmo.cpp)
target_link_libraries(vmap3extractor libmpq bzip2 zlib)

install(TARGETS vmap3extractor DESTINATION bin)
