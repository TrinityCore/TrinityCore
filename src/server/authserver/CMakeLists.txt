# Copyright (C) 2005-2010 Trinity <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

########### authserver ###############

SET(authserver_SRCS
Authentication/AuthCodes.cpp
Authentication/AuthCodes.h
Realms/RealmList.cpp
Realms/RealmList.h
Server/AuthSocket.cpp
Server/AuthSocket.h
Server/RealmSocket.h
Server/RealmSocket.cpp
Server/RealmAcceptor.h
Main.cpp
)

include_directories(
  ${ACE_INCLUDE_DIR}
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/src/server/shared
  ${CMAKE_SOURCE_DIR}/src/server/shared/Database
  ${CMAKE_SOURCE_DIR}/src/server/shared/Packets
  ${CMAKE_SOURCE_DIR}/src/server/shared/Cryptography
  ${CMAKE_SOURCE_DIR}/src/server/shared/Cryptography/Authentication
  ${CMAKE_SOURCE_DIR}/src/server/shared/Logging
  ${CMAKE_SOURCE_DIR}/src/server/shared/Utilities
  ${CMAKE_SOURCE_DIR}/src/server/authserver
  ${CMAKE_SOURCE_DIR}/src/server/authserver/Authentication
  ${CMAKE_SOURCE_DIR}/src/server/authserver/Realms
  ${CMAKE_SOURCE_DIR}/src/server/authserver/Server
  ${MYSQL_INCLUDE_DIR}
)

SET(authserver_LINK_FLAGS "")

add_executable(authserver ${authserver_SRCS})
add_definitions(
-D_TRINITY_REALM_CONFIG='"${CONF_DIR}/authserver.conf"'
)

SET(trinity-realm_LINK_FLAGS "-pthread ${authserver_LINK_FLAGS}")

IF (CMAKE_SYSTEM_NAME MATCHES "Darwin")
   SET(authserver_LINK_FLAGS "-framework Carbon ${authserver_LINK_FLAGS}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Darwin")

SET_TARGET_PROPERTIES(authserver PROPERTIES LINK_FLAGS "${authserver_LINK_FLAGS}")

target_link_libraries(
authserver
shared
trinitydatabase
trinityauth
trinityconfig
${SSLLIB}
${MYSQL_LIBRARIES}
${OSX_LIBS}
)

install(TARGETS authserver DESTINATION bin)


########### install files ###############

install(FILES  authserver.conf.dist DESTINATION etc)
