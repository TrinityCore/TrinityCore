# Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

########### bnetserver ###############

file(GLOB_RECURSE sources_authentication Authentication/*.cpp Authentication/*.h)
file(GLOB_RECURSE sources_realms Realms/*.cpp Realms/*.h)
file(GLOB_RECURSE sources_server Server/*.cpp Server/*.h)
file(GLOB_RECURSE sources_packets Packets/*.cpp Packets/*.h)
file(GLOB sources_localdir *.cpp *.h)

if (USE_COREPCH)
  set(bnetserver_PCH_HDR PrecompiledHeaders/bnetPCH.h)
  set(bnetserver_PCH_SRC PrecompiledHeaders/bnetPCH.cpp)
endif()

set(bnetserver_SRCS
  ${bnetserver_SRCS}
  ${sources_authentication}
  ${sources_realms}
  ${sources_server}
  ${sources_packets}
  ${sources_localdir}
)

if( WIN32 )
  set(bnetserver_SRCS
    ${bnetserver_SRCS}
    ${sources_windows_Debugging}
  )
  if ( MSVC )
    set(bnetserver_SRCS
      ${bnetserver_SRCS}
      bnetserver.rc
    )
  endif ()
endif()

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/Authentication
  ${CMAKE_CURRENT_SOURCE_DIR}/Packets
  ${CMAKE_CURRENT_SOURCE_DIR}/Realms
  ${CMAKE_CURRENT_SOURCE_DIR}/Server
  ${CMAKE_SOURCE_DIR}/dep/cppformat
  ${CMAKE_SOURCE_DIR}/dep/zmqpp
  ${CMAKE_SOURCE_DIR}/src/common
  ${CMAKE_SOURCE_DIR}/src/common/Configuration
  ${CMAKE_SOURCE_DIR}/src/common/Cryptography
  ${CMAKE_SOURCE_DIR}/src/common/Cryptography/Authentication
  ${CMAKE_SOURCE_DIR}/src/common/Debugging
  ${CMAKE_SOURCE_DIR}/src/common/Logging
  ${CMAKE_SOURCE_DIR}/src/common/Threading
  ${CMAKE_SOURCE_DIR}/src/common/Utilities
  ${CMAKE_SOURCE_DIR}/src/server/database
  ${CMAKE_SOURCE_DIR}/src/server/database/Database
  ${CMAKE_SOURCE_DIR}/src/server/database/Logging
  ${CMAKE_SOURCE_DIR}/src/server/ipc
  ${CMAKE_SOURCE_DIR}/src/server/shared
  ${CMAKE_SOURCE_DIR}/src/server/shared/Networking
  ${CMAKE_SOURCE_DIR}/src/server/shared/Packets
  ${CMAKE_SOURCE_DIR}/src/server/shared/Service
  ${MYSQL_INCLUDE_DIR}
  ${OPENSSL_INCLUDE_DIR}
  ${VALGRIND_INCLUDE_DIR}
  ${ZMQ_INCLUDE_DIR}
)

add_executable(bnetserver
  ${bnetserver_SRCS}
  ${bnetserver_PCH_SRC}
)

if( NOT WIN32 )
  set_target_properties(bnetserver PROPERTIES
    COMPILE_DEFINITIONS _TRINITY_BNET_CONFIG="${CONF_DIR}/bnetserver.conf"
  )
endif()

target_link_libraries(bnetserver
  shared
  database
  ipc
  common
  zmqpp
  format
  ${MYSQL_LIBRARY}
  ${OPENSSL_LIBRARIES}
  ${ZMQ_LIBRARY}
  ${CMAKE_THREAD_LIBS_INIT}
  ${Boost_LIBRARIES}
)

if( WIN32 )
  if ( MSVC )
    add_custom_command(TARGET bnetserver
      POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/bnetserver.conf.dist ${CMAKE_BINARY_DIR}/bin/$(ConfigurationName)/
    )
  elseif ( MINGW )
    add_custom_command(TARGET bnetserver
      POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/bnetserver.conf.dist ${CMAKE_BINARY_DIR}/bin/
    )
  endif()
endif()

if( UNIX )
  install(TARGETS bnetserver DESTINATION bin)
  install(FILES  bnetserver.conf.dist DESTINATION ${CONF_DIR})
elseif( WIN32 )
  install(TARGETS bnetserver DESTINATION "${CMAKE_INSTALL_PREFIX}")
  install(FILES bnetserver.conf.dist DESTINATION "${CMAKE_INSTALL_PREFIX}")
endif()

# Generate precompiled header
if (USE_COREPCH)
  add_cxx_pch(bnetserver ${bnetserver_PCH_HDR} ${bnetserver_PCH_SRC})
endif()
