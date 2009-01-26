########### next target ###############

SET(trinity-realm_SRCS
AuthCodes.h 
AuthSocket.cpp 
AuthSocket.h 
Main.cpp 
RealmList.cpp 
RealmList.h
)

add_executable(trinity-realm ${trinity-realm_SRCS})
add_definitions(
-D_TRINITY_REALM_CONFIG='"${CONF_DIR}/trinityrealm.conf"'
)
IF (DO_MYSQL)
    #SET_TARGET_PROPERTIES(mangos-realmd PROPERTIES LINK_FLAGS ${MYSQL_LIBS})
    SET_TARGET_PROPERTIES(trinity-realm PROPERTIES LINK_FLAGS "-pthread")
ENDIF(DO_MYSQL)
IF (DO_POSTGRE)
    SET_TARGET_PROPERTIES(trinity-realmd PROPERTIES LINK_FLAGS ${POSTGRE_LIBS})
ENDIF(DO_POSTGRE)


target_link_libraries(
trinity-realm
shared
trinityframework
trinitysockets
trinitydatabase
trinityauth
trinityconfig
ZThread
zlib
${SSLLIB}
${MYSQL_LIBRARIES}
)

install(TARGETS trinity-realm DESTINATION bin)


########### install files ###############

install(FILES  realmd.conf.dist.in DESTINATION etc)

