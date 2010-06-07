########### next target ###############

SET(trinity-realm_SRCS
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

SET(trinity-realm_LINK_FLAGS "")

add_executable(trinity-realm ${trinity-realm_SRCS})
add_definitions(
-D_TRINITY_REALM_CONFIG='"${CONF_DIR}/trinityrealm.conf"'
)
IF (DO_MYSQL)
   SET(trinity-realm_LINK_FLAGS "-pthread ${trinity-realm_LINK_FLAGS}")
ENDIF(DO_MYSQL)

IF (CMAKE_SYSTEM_NAME MATCHES "Darwin")
   SET(trinity-realm_LINK_FLAGS "-framework Carbon ${trinity-realm_LINK_FLAGS}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Darwin")

SET_TARGET_PROPERTIES(trinity-realm PROPERTIES LINK_FLAGS "${trinity-realm_LINK_FLAGS}")

target_link_libraries(
trinity-realm
shared
trinitydatabase
trinityauth
trinityconfig
${SSLLIB}
${MYSQL_LIBRARIES}
${OSX_LIBS}
)

install(TARGETS trinity-realm DESTINATION bin)


########### install files ###############

install(FILES  trinityrealm.conf.dist DESTINATION etc)
