# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

target_link_libraries(vmap4assembler
  PRIVATE
    trinity-core-interface
  PUBLIC
    common
    casc
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
