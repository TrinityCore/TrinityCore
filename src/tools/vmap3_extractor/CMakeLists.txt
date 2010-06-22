# Copyright (C) 2005-2009 MaNGOS project <http://getmangos.com/>
# Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB sources *.cpp)

# uncomment next line to disable debug mode
add_definitions("-DIOMAP_DEBUG")

# build setup currently only supports libmpq 0.4.x
add_definitions("-DUSE_LIBMPQ04")
add_definitions("-Wall")
add_definitions("-ggdb")
add_definitions("-O3")

add_executable(vmap3extractor ${sources})

if(WIN32)
  target_link_libraries(vmap3extractor
    mpq
    bzip2
    zlib
  )
else()
  target_link_libraries(vmap3extractor
    mpq
    ${BZIP2_LIBRARIES}
    ${ZLIB_LIBRARIES}
  )
endif()

install(TARGETS vmap3extractor DESTINATION bin)
