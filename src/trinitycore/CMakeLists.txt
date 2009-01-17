
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

add_executable(trinity-core ${trinity-core_SRCS})
add_definitions(
-D_TRINITY_CORE_CONFIG='"${CONF_DIR}/trinitycore.conf"'
)
IF (DO_MYSQL)
    SET_TARGET_PROPERTIES(trinity-core PROPERTIES LINK_FLAGS "-pthread")
ENDIF(DO_MYSQL)



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
ZThread
g3dlite
${SCRIPT_LIB}
${MYSQL_LIBRARIES}
${POSTGRE_LIBS}
${SSLLIB}
${ACE_LIBRARY}
${ZLIB}
)

install(TARGETS trinity-core DESTINATION bin)


########### install files ###############

install(FILES  trinitycore.conf.dist DESTINATION etc)

