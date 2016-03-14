# Copyright (C) 2005-2009 MaNGOS project <http://getmangos.com/>
# Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

CollectSourceFiles(
  ${CMAKE_CURRENT_SOURCE_DIR}
  PRIVATE_SOURCES)

add_executable(vmap4extractor ${PRIVATE_SOURCES})

target_link_libraries(vmap4extractor
  PUBLIC
    mpq)

CollectIncludeDirectories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  PUBLIC_INCLUDES)

target_include_directories(vmap4extractor
  PUBLIC
    ${PUBLIC_INCLUDES}
  PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR})

set_target_properties(vmap4extractor
    PROPERTIES
      FOLDER
        "tools")

if( UNIX )
  install(TARGETS vmap4extractor DESTINATION bin)
elseif( WIN32 )
  install(TARGETS vmap4extractor DESTINATION "${CMAKE_INSTALL_PREFIX}")
endif()
