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

include_directories(
  ${CMAKE_SOURCE_DIR}/externals/g3dlite
  ${CMAKE_SOURCE_DIR}/src/server/shared
  ${CMAKE_SOURCE_DIR}/src/server/shared/Debugging
  ${CMAKE_SOURCE_DIR}/src/server/shared/Logging
  ${CMAKE_SOURCE_DIR}/src/server/collision/Maps
  ${CMAKE_SOURCE_DIR}/src/server/collision/Models
  ${ACE_INCLUDE_DIR}
)

add_definitions(-DNO_CORE_FUNCS)
add_executable(vmap3assembler VMapAssembler.cpp)
target_link_libraries(vmap3assembler collision g3dlib)

install(TARGETS vmap3assembler DESTINATION bin)
