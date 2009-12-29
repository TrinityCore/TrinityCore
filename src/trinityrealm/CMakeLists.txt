########### next target ###############

SET(trinity-realm_SRCS
AuthCodes.cpp
AuthCodes.h
AuthSocket.cpp
AuthSocket.h
Main.cpp
RealmList.cpp
RealmList.h
)

SET(trinity-realm_LINK_FLAGS "")

add_executable(trinity-realm ${trinity-realm_SRCS})
add_definitions(
-D_TRINITY_REALM_CONFIG='"${CONF_DIR}/trinityrealm.conf"'
)
IF (DO_MYSQL)
   SET(trinity-realm_LINK_FLAGS "-pthread ${trinity-realm_LINK_FLAGS}")
ENDIF(DO_MYSQL)
IF (DO_POSTGRESQL)
   SET(trinity-realm_LINK_FLAGS "-pthread ${trinity-realm_LINK_FLAGS}")
ENDIF(DO_POSTGRESQL)

IF (CMAKE_SYSTEM_NAME MATCHES "Darwin")
   SET(trinity-realm_LINK_FLAGS "-framework Carbon ${trinity-realm_LINK_FLAGS}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Darwin")

SET_TARGET_PROPERTIES(trinity-realm PROPERTIES LINK_FLAGS "${trinity-realm_LINK_FLAGS}")

target_link_libraries(
trinity-realm
shared
trinityframework
trinitysockets
trinitydatabase
trinityauth
trinityconfig
zlib
${SSLLIB}
${MYSQL_LIBRARIES}
${POSTGRESQL_LIBRARIES}
${OSX_LIBS}
)

install(TARGETS trinity-realm DESTINATION bin)


########### install files ###############

install(FILES  trinityrealm.conf.dist DESTINATION etc)

