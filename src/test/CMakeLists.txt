# Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB_RECURSE sources_cppunit cppunit/*.cpp cppunit/*.h)
file(GLOB_RECURSE sources_efficiency efficiency/*.cpp efficiency/*.h)
file(GLOB_RECURSE sources_main *.cpp *.h)

# Create game-libary

if (USE_COREPCH)
  set(tests_STAT_PCH_HDR pch.h)
  set(tests_STAT_PCH_SRC pch.cpp)
endif ()

set(tests_STAT_SRCS
  ${tests_STAT_SRCS}
  ${sources_cppunit}
  ${sources_efficiency}
  ${sources_main}
)

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/dep/recastnavigation/Detour
  ${CMAKE_SOURCE_DIR}/dep/recastnavigation/Detour/Include
  ${CMAKE_SOURCE_DIR}/dep/recastnavigation/Recast
  ${CMAKE_SOURCE_DIR}/dep/recastnavigation/Recast/Include
  ${CMAKE_SOURCE_DIR}/dep/g3dlite/include
  ${CMAKE_SOURCE_DIR}/dep/SFMT
  ${CMAKE_SOURCE_DIR}/dep/zlib
  ${CMAKE_SOURCE_DIR}/dep/cppformat
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
  ${CMAKE_SOURCE_DIR}/src/server/collision
  ${CMAKE_SOURCE_DIR}/src/server/collision/Management
  ${CMAKE_SOURCE_DIR}/src/server/collision/Models
  ${CMAKE_SOURCE_DIR}/src/server/collision/Maps
  ${CMAKE_SOURCE_DIR}/src/server/shared
  ${CMAKE_SOURCE_DIR}/src/server/shared/Configuration
  ${CMAKE_SOURCE_DIR}/src/server/shared/Cryptography
  ${CMAKE_SOURCE_DIR}/src/server/shared/Cryptography/Authentication
  ${CMAKE_SOURCE_DIR}/src/server/database
  ${CMAKE_SOURCE_DIR}/src/server/database/Database
  ${CMAKE_SOURCE_DIR}/src/server/shared/DataStores
  ${CMAKE_SOURCE_DIR}/src/server/shared/Debugging
  ${CMAKE_SOURCE_DIR}/src/server/shared/Dynamic/LinkedReference
  ${CMAKE_SOURCE_DIR}/src/server/shared/Dynamic
  ${CMAKE_SOURCE_DIR}/src/server/shared/Logging
  ${CMAKE_SOURCE_DIR}/src/server/shared/Networking
  ${CMAKE_SOURCE_DIR}/src/server/shared/Packets
  ${CMAKE_SOURCE_DIR}/src/server/shared/Threading
  ${CMAKE_SOURCE_DIR}/src/server/shared/Utilities
  ${CMAKE_SOURCE_DIR}/src/test
  ${CMAKE_SOURCE_DIR}/src/test/cppunit
  ${CMAKE_SOURCE_DIR}/src/server/game/Accounts
  ${CMAKE_SOURCE_DIR}/src/server/game/Achievements
  ${CMAKE_SOURCE_DIR}/src/server/game/Addons
  ${CMAKE_SOURCE_DIR}/src/server/game/AI
  ${CMAKE_SOURCE_DIR}/src/server/game/AI/CoreAI
  ${CMAKE_SOURCE_DIR}/src/server/game/AI/ScriptedAI
  ${CMAKE_SOURCE_DIR}/src/server/game/AI/SmartScripts
  ${CMAKE_SOURCE_DIR}/src/server/game/AuctionHouse
  ${CMAKE_SOURCE_DIR}/src/server/game/Battlefield
  ${CMAKE_SOURCE_DIR}/src/server/game/Battlefield/Zones
  ${CMAKE_SOURCE_DIR}/src/server/game/Battlegrounds
  ${CMAKE_SOURCE_DIR}/src/server/game/Battlegrounds/Zones
  ${CMAKE_SOURCE_DIR}/src/server/game/Calendar
  ${CMAKE_SOURCE_DIR}/src/server/game/Chat
  ${CMAKE_SOURCE_DIR}/src/server/game/Chat/Channels
  ${CMAKE_SOURCE_DIR}/src/server/game/Combat
  ${CMAKE_SOURCE_DIR}/src/server/game/Conditions
  ${CMAKE_SOURCE_DIR}/src/server/game/DataStores
  ${CMAKE_SOURCE_DIR}/src/server/game/DungeonFinding
  ${CMAKE_SOURCE_DIR}/src/server/game/Entities
  ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Creature
  ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Corpse
  ${CMAKE_SOURCE_DIR}/src/server/game/Entities/DynamicObject
  ${CMAKE_SOURCE_DIR}/src/server/game/Entities/GameObject
  ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Item
  ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Item/Container
  ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Object
  ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Object/Updates
  ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Pet
  ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Player
  ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Totem
  ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Unit
  ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Vehicle
  ${CMAKE_SOURCE_DIR}/src/server/game/Entities/Transport
  ${CMAKE_SOURCE_DIR}/src/server/game/Events
  ${CMAKE_SOURCE_DIR}/src/server/game/Globals
  ${CMAKE_SOURCE_DIR}/src/server/game/Grids/Cells
  ${CMAKE_SOURCE_DIR}/src/server/game/Grids/Notifiers
  ${CMAKE_SOURCE_DIR}/src/server/game/Grids
  ${CMAKE_SOURCE_DIR}/src/server/game/Groups
  ${CMAKE_SOURCE_DIR}/src/server/game/Guilds
  ${CMAKE_SOURCE_DIR}/src/server/game/Handlers
  ${CMAKE_SOURCE_DIR}/src/server/game/Instances
  ${CMAKE_SOURCE_DIR}/src/server/game/Loot
  ${CMAKE_SOURCE_DIR}/src/server/game/Mails
  ${CMAKE_SOURCE_DIR}/src/server/game/Maps
  ${CMAKE_SOURCE_DIR}/src/server/game/Miscellaneous
  ${CMAKE_SOURCE_DIR}/src/server/game/Movement
  ${CMAKE_SOURCE_DIR}/src/server/game/Movement/Spline
  ${CMAKE_SOURCE_DIR}/src/server/game/Movement/MovementGenerators
  ${CMAKE_SOURCE_DIR}/src/server/game/Movement/Waypoints
  ${CMAKE_SOURCE_DIR}/src/server/game/OutdoorPvP
  ${CMAKE_SOURCE_DIR}/src/server/game/Pools
  ${CMAKE_SOURCE_DIR}/src/server/game/PrecompiledHeaders
  ${CMAKE_SOURCE_DIR}/src/server/game/Quests
  ${CMAKE_SOURCE_DIR}/src/server/game/Reputation
  ${CMAKE_SOURCE_DIR}/src/server/game/Scripting
  ${CMAKE_SOURCE_DIR}/src/server/game/Server/Protocol
  ${CMAKE_SOURCE_DIR}/src/server/game/Server
  ${CMAKE_SOURCE_DIR}/src/server/game/Skills
  ${CMAKE_SOURCE_DIR}/src/server/game/Spells
  ${CMAKE_SOURCE_DIR}/src/server/game/Spells/Auras
  ${CMAKE_SOURCE_DIR}/src/server/game/Texts
  ${CMAKE_SOURCE_DIR}/src/server/game/Tools
  ${CMAKE_SOURCE_DIR}/src/server/game/Tickets
  ${CMAKE_SOURCE_DIR}/src/server/game/Warden
  ${CMAKE_SOURCE_DIR}/src/server/game/Warden/Modules
  ${CMAKE_SOURCE_DIR}/src/server/game/Weather
  ${CMAKE_SOURCE_DIR}/src/server/game/World
  ${CMAKE_SOURCE_DIR}/src/server/game/Playerbot
  ${CMAKE_SOURCE_DIR}/src/server/scripts/PrecompiledHeaders
  ${MYSQL_INCLUDE_DIR}
  ${OPENSSL_INCLUDE_DIR}
  ${CMAKE_SOURCE_DIR}/src/test/cppunit
)

add_executable(tests
  ${tests_STAT_SRCS}
  ${tests_STAT_PCH_SRC}
)

target_link_libraries(tests
  game
  plugins
  common
  shared
  database
  scripts
  g3dlib
  gsoap
  Detour
  format
  ${JEMALLOC_LIBRARY}
  ${READLINE_LIBRARY}
  ${TERMCAP_LIBRARY}
  ${MYSQL_LIBRARY}
  ${OPENSSL_LIBRARIES}
  ${ZLIB_LIBRARIES}
  ${CMAKE_THREAD_LIBS_INIT}
  ${Boost_LIBRARIES}
)

# Generate precompiled header
if (USE_COREPCH)
  add_cxx_pch(tests ${tests_STAT_PCH_HDR} ${tests_STAT_PCH_SRC})
endif ()
