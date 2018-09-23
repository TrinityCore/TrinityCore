# Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
  
if ( WIN32 )
  list(APPEND PRIVATE_SOURCES ${sources_windows})
endif()

add_executable(dbedit
  ${PRIVATE_SOURCES}
)

target_include_directories(dbedit
  PUBLIC
    ${CMAKE_SOURCE_DIR})

find_package(Qt5 REQUIRED Core Widgets)
target_link_libraries(dbedit
  PRIVATE
    trinity-core-interface
  PUBLIC
    common
    database
    shared
    Qt5::Widgets)
    
CollectIncludeDirectories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  PUBLIC_INCLUDES)
  
target_include_directories(dbedit
  PUBLIC
    ${PUBLIC_INCLUDES}
  PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR})
    
set_target_properties(dbedit
  PROPERTIES
    AUTOMOC
      ON
    AUTOUIC
      ON
    FOLDER
      "dbedit")
      
if ( UNIX )
  install(TARGETS dbedit DESTINATION bin)
elseif ( WIN32 )
  install (TARGETS dbedit DESTINATION "${CMAKE_INSTALL_PREFIX}")
endif()
