# Copyright (C) 2005-2009 MaNGOS project <http://getmangos.com/>
# Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

set(PRIVATE_SOURCES VMapAssembler.cpp)

if (WIN32)
  list(APPEND PRIVATE_SOURCES ${sources_windows})
endif()

add_executable(vmap4assembler ${PRIVATE_SOURCES})

if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
  set_target_properties(vmap4assembler PROPERTIES LINK_FLAGS "-framework Carbon")
endif()

target_link_libraries(vmap4assembler
  PRIVATE
    trinity-core-interface
  PUBLIC
    common
    zlib)

set_target_properties(vmap4assembler
    PROPERTIES
      FOLDER
        "tools")

if( UNIX )
  install(TARGETS vmap4assembler DESTINATION bin)
elseif( WIN32 )
  install(TARGETS vmap4assembler DESTINATION "${CMAKE_INSTALL_PREFIX}")
endif()
