# Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

set(GENREV_SRC
  genrevision.cpp
)
add_executable(genrev
  ${GENREV_SRC}
)

if( CMAKE_GENERATOR MATCHES "Visual Studio" )
  add_custom_command(TARGET genrev
    POST_BUILD
    COMMAND ${CMAKE_BINARY_DIR}/bin/$(ConfigurationName)/genrev ${CMAKE_SOURCE_DIR}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  )
else()
  add_custom_command(TARGET genrev
    POST_BUILD
    COMMAND ${CMAKE_BINARY_DIR}/src/genrevision/genrev ${CMAKE_SOURCE_DIR}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  )
endif()

