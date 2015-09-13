include("${CMAKE_CURRENT_LIST_DIR}/cmake/Utils.cmake")

AZTH_SET_PATH("CMAKE_AZTH_DIR" "${CMAKE_CURRENT_LIST_DIR}/../")
AZTH_SET_PATH("CMAKE_AZTH_SRC_DIR" "${CMAKE_AZTH_DIR}/src/")

AZTH_SUBDIRLIST(sub_DIRS  "${CMAKE_AZTH_SRC_DIR}/server/" TRUE)
FOREACH(subdir ${sub_DIRS})
    file(GLOB sources "${subdir}/*.cpp" "${subdir}/*.h")

    set(azth_STAT_SRCS
        ${azth_STAT_SRCS}
        ${sources}
    )

    set(azth_DIRS
        ${subdir}
        ${azth_DIRS}
    )
ENDFOREACH()

AZTH_LOAD_INC_PATHS()

AZTH_ADD_INC_PATH("${azth_DIRS}")

AZTH_SET_CACHE("CMAKE_AZTH_SRCS" "${azth_STAT_SRCS}")


MACRO(LOAD_AZTH_MODS)
    message("${CMAKE_SOURCE_DIR}")

    include_directories(
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/dep
        ${CMAKE_SOURCE_DIR}/dep/cppformat
        ${CMAKE_SOURCE_DIR}/dep/g3dlite/include
        ${CMAKE_SOURCE_DIR}/dep/recastnavigation/Detour/Include
        ${CMAKE_SOURCE_DIR}/dep/zlib
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/common
        ${CMAKE_SOURCE_DIR}/src/common/Collision
        ${CMAKE_SOURCE_DIR}/src/common/Collision/Management
        ${CMAKE_SOURCE_DIR}/src/common/Collision/Maps
        ${CMAKE_SOURCE_DIR}/src/common/Collision/Models
        ${CMAKE_SOURCE_DIR}/src/common/Configuration
        ${CMAKE_SOURCE_DIR}/src/common/Cryptography
        ${CMAKE_SOURCE_DIR}/src/common/Cryptography/Authentication
        ${CMAKE_SOURCE_DIR}/src/common/Debugging
        ${CMAKE_SOURCE_DIR}/src/common/Logging
        ${CMAKE_SOURCE_DIR}/src/common/Threading
        ${CMAKE_SOURCE_DIR}/src/common/Utilities
        ${CMAKE_SOURCE_DIR}/src/server/database
        ${CMAKE_SOURCE_DIR}/src/server/database/Database
        ${CMAKE_SOURCE_DIR}/src/server/shared
        ${CMAKE_SOURCE_DIR}/src/server/shared/DataStores
        ${CMAKE_SOURCE_DIR}/src/server/shared/Dynamic
        ${CMAKE_SOURCE_DIR}/src/server/shared/Dynamic/LinkedReference
        ${CMAKE_SOURCE_DIR}/src/server/shared/Networking
        ${CMAKE_SOURCE_DIR}/src/server/shared/Packets
        ${CMAKE_SOURCE_DIR}/src/server/database/Database
        ${CMAKE_SOURCE_DIR}/src/server/game
        ${CMAKE_SOURCE_DIR}/src/server/game/Accounts
        ${CMAKE_SOURCE_DIR}/src/server/game/Achievements
        ${CMAKE_SOURCE_DIR}/src/server/game/Addons
        ${CMAKE_SOURCE_DIR}/src/server/game/AI
        ${CMAKE_SOURCE_DIR}/src/server/game/AI/CoreAI
        ${CMAKE_SOURCE_DIR}/src/server/game/AI/ScriptedAI
        ${CMAKE_SOURCE_DIR}/src/server/game/AI/SmartScripts
        ${CMAKE_SOURCE_DIR}/src/server/game/AuctionHouse
        ${CMAKE_SOURCE_DIR}/src/server/game/AuctionHouseBot
        ${CMAKE_SOURCE_DIR}/src/server/game/Battlefield
        ${CMAKE_SOURCE_DIR}/src/server/game/Battlefield/Zones
        ${CMAKE_SOURCE_DIR}/src/server/game/Battlegrounds
        ${CMAKE_SOURCE_DIR}/src/server/game/Battlegrounds/Zones
        ${CMAKE_SOURCE_DIR}/src/server/game/Chat
        ${CMAKE_SOURCE_DIR}/src/server/game/Chat/Channels
        ${CMAKE_SOURCE_DIR}/src/server/game/Combat
        ${CMAKE_SOURCE_DIR}/src/server/game/Conditions
        ${CMAKE_SOURCE_DIR}/src/server/game/DataStores
        ${CMAKE_SOURCE_DIR}/src/server/game/DungeonFinding
        ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Corpse
        ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Creature
        ${CMAKE_SOURCE_DIR}/src/server/game/Entities/DynamicObject
        ${CMAKE_SOURCE_DIR}/src/server/game/Entities/GameObject
        ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Item
        ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Item/Container
        ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Object
        ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Object/Updates
        ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Pet
        ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Player
        ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Transport
        ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Unit
        ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Vehicle
        ${CMAKE_SOURCE_DIR}/src/server/game/Events
        ${CMAKE_SOURCE_DIR}/src/server/game/Globals
        ${CMAKE_SOURCE_DIR}/src/server/game/Grids
        ${CMAKE_SOURCE_DIR}/src/server/game/Grids/Cells
        ${CMAKE_SOURCE_DIR}/src/server/game/Grids/Notifiers
        ${CMAKE_SOURCE_DIR}/src/server/game/Groups
        ${CMAKE_SOURCE_DIR}/src/server/game/Guilds
        ${CMAKE_SOURCE_DIR}/src/server/game/Handlers
        ${CMAKE_SOURCE_DIR}/src/server/game/Instances
        ${CMAKE_SOURCE_DIR}/src/server/game/Loot
        ${CMAKE_SOURCE_DIR}/src/server/game/Mails
        ${CMAKE_SOURCE_DIR}/src/server/game/Maps
        ${CMAKE_SOURCE_DIR}/src/server/game/Miscellaneous
        ${CMAKE_SOURCE_DIR}/src/server/game/Movement
        ${CMAKE_SOURCE_DIR}/src/server/game/Movement/MovementGenerators
        ${CMAKE_SOURCE_DIR}/src/server/game/Movement/Spline
        ${CMAKE_SOURCE_DIR}/src/server/game/Movement/Waypoints
        ${CMAKE_SOURCE_DIR}/src/server/game/OutdoorPvP
        ${CMAKE_SOURCE_DIR}/src/server/game/Pools
        ${CMAKE_SOURCE_DIR}/src/server/game/Quests
        ${CMAKE_SOURCE_DIR}/src/server/game/Reputation
        ${CMAKE_SOURCE_DIR}/src/server/game/Scripting
        ${CMAKE_SOURCE_DIR}/src/server/game/Server
        ${CMAKE_SOURCE_DIR}/src/server/game/Server/Protocol
        ${CMAKE_SOURCE_DIR}/src/server/game/Skills
        ${CMAKE_SOURCE_DIR}/src/server/game/Spells
        ${CMAKE_SOURCE_DIR}/src/server/game/Spells/Auras
        ${CMAKE_SOURCE_DIR}/src/server/game/Texts
        ${CMAKE_SOURCE_DIR}/src/server/game/Tickets
        ${CMAKE_SOURCE_DIR}/src/server/game/Tools
        ${CMAKE_SOURCE_DIR}/src/server/game/Warden
        ${CMAKE_SOURCE_DIR}/src/server/game/Weather
        ${CMAKE_SOURCE_DIR}/src/server/game/World
        ${MYSQL_INCLUDE_DIR}
        ${OPENSSL_INCLUDE_DIR}
        ${VALGRIND_INCLUDE_DIR}
    )

    add_library(azth_mod STATIC
      ${CMAKE_AZTH_SRCS}
    )

    target_link_libraries(azth_mod
      game
    )

    message(STATUS "AZTH-MODS PREPARATION COMPLETE")
    message("")
ENDMACRO(LOAD_AZTH_MODS)
