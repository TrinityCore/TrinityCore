
########### next target ###############

SET(trinity-core_SRCS
CliRunnable.cpp
CliRunnable.h
Main.cpp
Master.cpp
Master.h
RASocket.cpp
RASocket.h
WorldRunnable.cpp
WorldRunnable.h
)

SET(trinity-core_LINK_FLAGS "")

add_executable(trinity-core ${trinity-core_SRCS})
add_definitions(
-D_TRINITY_CORE_CONFIG='"${CONF_DIR}/trinitycore.conf"'
)
IF (DO_MYSQL)
    SET(trinity-core_LINK_FLAGS "-pthread ${trinity-core_LINK_FLAGS}")
ENDIF(DO_MYSQL)
IF (DO_POSTGRESQL)
    SET(trinity-core_LINK_FLAGS "-pthread ${trinity-core_LINK_FLAGS}")
ENDIF(DO_POSTGRESQL)


IF (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    SET(trinity-core_LINK_FLAGS "-framework Carbon ${trinity-core_LINK_FLAGS}")
    SET(SCRIPT_LIB "")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Darwin")

SET_TARGET_PROPERTIES(trinity-core PROPERTIES LINK_FLAGS "${trinity-core_LINK_FLAGS}")

target_link_libraries(
trinity-core
game
shared
zlib
trinityframework
trinitysockets
trinitydatabase
trinityauth
trinityconfig
vmaps
g3dlite
${READLINE_LIBRARY}
${TERMCAP_LIBRARY}
gomp
${SCRIPT_LIB}
${MYSQL_LIBRARIES}
${POSTGRESQL_LIBRARIES}
${SSLLIB}
${ACE_LIBRARY}
${ZLIB}
${OSX_LIBS}
)

install(TARGETS trinity-core DESTINATION bin)


########### install files ###############

install(FILES  trinitycore.conf.dist DESTINATION etc)

