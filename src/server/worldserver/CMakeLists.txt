
########### next target ###############

SET(trinity-core_SRCS
CommandLine/CliRunnable.cpp
CommandLine/CliRunnable.h
RemoteAccess/RASocket.cpp
RemoteAccess/RASocket.h
WorldThread/WorldRunnable.cpp
WorldThread/WorldRunnable.h
Main.cpp
Master.cpp
Master.h
)

include_directories(
  ${ACE_INCLUDE_DIR}
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/dep/include
  ${CMAKE_SOURCE_DIR}/src/server/shared
  ${CMAKE_SOURCE_DIR}/src/server/shared/Database
  ${CMAKE_SOURCE_DIR}/src/server/game
  ${CMAKE_SOURCE_DIR}/src/server/game/Account
  ${CMAKE_SOURCE_DIR}/src/server/game/Achievements
  ${CMAKE_SOURCE_DIR}/src/server/game/Addons
  ${CMAKE_SOURCE_DIR}/src/server/game/AI
  ${CMAKE_SOURCE_DIR}/src/server/game/AI/AuctionHouseBot
  ${CMAKE_SOURCE_DIR}/src/server/game/AI/EventAI
  ${CMAKE_SOURCE_DIR}/src/server/game/AI/ScriptedAI
  ${CMAKE_SOURCE_DIR}/src/server/game/AuctionHouse
  ${CMAKE_SOURCE_DIR}/src/server/game/BattleGrounds
  ${CMAKE_SOURCE_DIR}/src/server/game/Calendar
  ${CMAKE_SOURCE_DIR}/src/server/game/Chat
  ${CMAKE_SOURCE_DIR}/src/server/game/Combat
  ${CMAKE_SOURCE_DIR}/src/server/game/ConditionMgr
  ${CMAKE_SOURCE_DIR}/src/server/game/DataStores
  ${CMAKE_SOURCE_DIR}/src/server/game/Entities
  ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Creature
  ${CMAKE_SOURCE_DIR}/src/server/game/Entities/GameObject
  ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Item
  ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Object
  ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Pet
  ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Player
  ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Totem
  ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Unit
  ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Vehicle
  ${CMAKE_SOURCE_DIR}/src/server/game/Events
  ${CMAKE_SOURCE_DIR}/src/server/game/Globals
  ${CMAKE_SOURCE_DIR}/src/server/game/Groups
  ${CMAKE_SOURCE_DIR}/src/server/game/Guilds
  ${CMAKE_SOURCE_DIR}/src/server/game/Instances
  ${CMAKE_SOURCE_DIR}/src/server/game/LookingForGroup
  ${CMAKE_SOURCE_DIR}/src/server/game/Loot
  ${CMAKE_SOURCE_DIR}/src/server/game/Mails
  ${CMAKE_SOURCE_DIR}/src/server/game/Map
  ${CMAKE_SOURCE_DIR}/src/server/game/Map/Cell
  ${CMAKE_SOURCE_DIR}/src/server/game/Map/Grid
  ${CMAKE_SOURCE_DIR}/src/server/game/Movement
  ${CMAKE_SOURCE_DIR}/src/server/game/Movement/MovementGenerators
  ${CMAKE_SOURCE_DIR}/src/server/game/Opcodes
  ${CMAKE_SOURCE_DIR}/src/server/game/OutdoorPvP
  ${CMAKE_SOURCE_DIR}/src/server/game/Pools
  ${CMAKE_SOURCE_DIR}/src/server/game/PrecompiledHeaders
  ${CMAKE_SOURCE_DIR}/src/server/game/Quests
  ${CMAKE_SOURCE_DIR}/src/server/game/Reputation
  ${CMAKE_SOURCE_DIR}/src/server/game/ScriptMgr
  ${CMAKE_SOURCE_DIR}/src/server/game/Skills
  ${CMAKE_SOURCE_DIR}/src/server/game/Spells
  ${CMAKE_SOURCE_DIR}/src/server/game/Spells/Auras
  ${CMAKE_SOURCE_DIR}/src/server/game/Tools
  ${CMAKE_SOURCE_DIR}/src/server/game/Weather
  ${CMAKE_SOURCE_DIR}/src/server/game/World
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

