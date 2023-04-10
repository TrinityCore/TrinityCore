# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

CollectSourceFiles(
  ${CMAKE_CURRENT_SOURCE_DIR}
  PRIVATE_SOURCES
  # Exclude
  ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders)

if(USE_COREPCH)
  set(PRIVATE_PCH_HEADER PrecompiledHeaders/gamePCH.h)
endif()

GroupSources(${CMAKE_CURRENT_SOURCE_DIR})

add_definitions(-DTRINITY_API_EXPORT_GAME)

CollectIncludeDirectories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  PUBLIC_INCLUDES
  # Exclude
  ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders)

# Provide an interface target for the game project to allow
# dependent projects to build meanwhile.
add_library(game-interface INTERFACE)

target_include_directories(game-interface
  INTERFACE
    ${PUBLIC_INCLUDES})

target_link_libraries(game-interface
  INTERFACE
    shared
    Detour)

add_library(game
  ${PRIVATE_SOURCES} "Globals/BattlePetDataStore.cpp"  "Instances/InstanceSaveMgr.cpp" "BattlePay/BattlePayMgr.h" "BattlePay/BattlePayMgr.cpp" "Globals/BattlePayData.h" "Server/Packets/BattlePayPackets.h" "Quests/WorldQuestMgr.h" "Movement/PathfindingMgr.h" "Movement/Pathfinding.h" "Battlegrounds/CommandBG.h" "AI/PlayerAI/BotClassAI/BotWarriorAI.h" "AI/PlayerAI/BotClassAI/BotMageAI.h" "AI/PlayerAI/BotClassAI/BotPriestAI.h" "AI/PlayerAI/BotClassAI/BotHunterAI.h" "AI/PlayerAI/BotClassAI/BotWarlockAI.h" "AI/PlayerAI/BotClassAI/BotPaladinAI.h" "AI/PlayerAI/BotClassAI/BotRogueAI.h" "AI/PlayerAI/BotClassAI/BotShamanAI.h" "AI/PlayerAI/BotClassAI/BotDruidAI.h" "AI/PlayerAI/BotClassAI/BotDemonHunterAI.h" "AI/PlayerAI/BotClassAI/BotMonkAI.h" "AI/PlayerAI/BotClassAI/BotDeathknightAI.h" "AI/PlayerAI/BotClassAI/BotDruidAI.cpp" "AI/PlayerAI/BotClassAI/BotHunterAI.cpp" "AI/PlayerAI/BotClassAI/BotMageAI.cpp" "AI/PlayerAI/BotClassAI/BotDeathknightAI.cpp" "AI/PlayerAI/BotClassAI/BotPaladinAI.cpp" "AI/PlayerAI/BotClassAI/BotPriestAI.cpp" "AI/PlayerAI/BotClassAI/BotRogueAI.cpp" "AI/PlayerAI/BotClassAI/BotShamanAI.cpp" "AI/PlayerAI/BotClassAI/BotWarlockAI.cpp" "AI/PlayerAI/BotClassAI/BotWarriorAI.cpp" "AI/PlayerAI/BotDuelAI/BotDuelClassAI.h" "AI/PlayerAI/BotDuelAI/BotDuelAI.cpp" "Entities/Unit/CharmInfo.h")

target_include_directories(game
  PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(game
  PRIVATE
    trinity-core-interface
    efsw
  PUBLIC
    game-interface)

set_target_properties(game
    PROPERTIES
      FOLDER
        "server")

if(BUILD_SHARED_LIBS)
  if(UNIX)
    install(TARGETS game
      LIBRARY
        DESTINATION lib)
  elseif(WIN32)
    install(TARGETS game
      RUNTIME
        DESTINATION "${CMAKE_INSTALL_PREFIX}")
  endif()
endif()

# Generate precompiled header
if(USE_COREPCH)
  add_cxx_pch(game ${PRIVATE_PCH_HEADER})
endif()
