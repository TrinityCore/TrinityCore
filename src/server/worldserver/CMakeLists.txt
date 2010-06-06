
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

include_directories(
  ${ACE_INCLUDE_DIR}
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/dep/include
  ${CMAKE_SOURCE_DIR}/src/server/shared
  ${CMAKE_SOURCE_DIR}/src/server/shared/Database
  ${CMAKE_SOURCE_DIR}/src/server/framework
  ${CMAKE_SOURCE_DIR}/src/server/game
  ${MYSQL_INCLUDE_DIR}
)

SET(trinity-core_LINK_FLAGS "")

add_executable(trinity-core ${trinity-core_SRCS})
add_definitions(
-D_TRINITY_CORE_CONFIG='"${CONF_DIR}/trinitycore.conf"'
)
IF (DO_MYSQL)
    SET(trinity-core_LINK_FLAGS "-pthread ${trinity-core_LINK_FLAGS}")
ENDIF(DO_MYSQL)

IF (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    SET(trinity-core_LINK_FLAGS "-framework Carbon ${trinity-core_LINK_FLAGS}")
    SET(SCRIPT_LIB "")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Darwin")

SET_TARGET_PROPERTIES(trinity-core PROPERTIES LINK_FLAGS "${trinity-core_LINK_FLAGS}")

if(DO_SCRIPTS)
    SET(SCRIPT_LIB "scripts")
else(DO_SCRIPTS)
    SET(SCRIPT_LIB "")
endif(DO_SCRIPTS)

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
jmalloc
${SCRIPT_LIB}
${READLINE_LIBRARY}
${TERMCAP_LIBRARY}
${MYSQL_LIBRARIES}
${SSLLIB}
${ACE_LIBRARY}
${ZLIB} 
${OSX_LIBS}
)

install(TARGETS trinity-core DESTINATION bin)


########### install files ###############

install(FILES  trinitycore.conf.dist DESTINATION etc)

