# Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB_RECURSE sources_socialsrv *.cpp *.h)

set(socialserver_SRCS
  ${sources_socialsrv}
)

if (UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -pedantic -Wall -Wextra")
endif()

 if(WIN32)
   set(socialserver_SRCS
     ${socialserver_SRCS}
     ${sources_windows_Debugging}
   )
   if (MSVC)
     set(socialserver_SRCS
       ${socialserver_SRCS}
       socialserver.rc
     )
   endif ()
 endif()

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/dep/zmqpp
  ${CMAKE_SOURCE_DIR}/src/server/shared
  ${CMAKE_SOURCE_DIR}/src/server/shared/Configuration
  ${CMAKE_SOURCE_DIR}/src/server/shared/Database
  ${CMAKE_SOURCE_DIR}/src/server/shared/Logging
  ${CMAKE_SOURCE_DIR}/src/server/shared/Threading
  ${CMAKE_SOURCE_DIR}/src/server/shared/Utilities
  ${CMAKE_SOURCE_DIR}/src/server/shared/Debugging
  ${CMAKE_SOURCE_DIR}/src/server/ha
  ${ZMQ_INCLUDE_DIR}
  ${MYSQL_INCLUDE_DIR}
)

add_executable(socialserver 
  ${socialserver_SRCS}
)

if (NOT WIN32)
  set_target_properties(socialserver PROPERTIES
    COMPILE_DEFINITIONS _TRINITY_SOCIAL_CONFIG="${CONF_DIR}/socialserver.conf"
  )
endif()

add_dependencies(socialserver revision.h)

target_link_libraries(socialserver
  ha
  shared
  zmqpp
  ${ZMQ_LIBRARY}
  ${Boost_LIBRARIES}
  ${MYSQL_LIBRARY}
)

if (WIN32)
  if (MSVC)
    add_custom_command(TARGET socialserver
      POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/socialserver.conf.dist ${CMAKE_BINARY_DIR}/bin/$(ConfigurationName)/
    )
  elseif (MINGW)
    add_custom_command(TARGET socialserver
      POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/socialserver.conf.dist ${CMAKE_BINARY_DIR}/bin/
    )
  endif()
endif()

if (UNIX)
  install(TARGETS socialserver DESTINATION bin)
  install(FILES socialserver.conf.dist DESTINATION ${CONF_DIR})
elseif (WIN32)
  install(TARGETS socialserver DESTINATION "${CMAKE_INSTALL_PREFIX}")
  install(FILES socialserver.conf.dist DESTINATION "${CMAKE_INSTALL_PREFIX}")
endif()
