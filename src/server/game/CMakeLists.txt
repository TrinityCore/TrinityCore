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
  ${PRIVATE_SOURCES} "Globals/BattlePetDataStore.cpp"  "Instances/InstanceSaveMgr.cpp" "BattlePay/BattlePayMgr.h" "BattlePay/BattlePayMgr.cpp" "Globals/BattlePayData.h" "Server/Packets/BattlePayPackets.h" "Quests/WorldQuestMgr.h" "Movement/PathfindingMgr.h" "Movement/Pathfinding.h" "Battlegrounds/CommandBG.h" "AI/PlayerAI/BotClassAI/BotWarriorAI.h" "AI/PlayerAI/BotClassAI/BotMageAI.h" "AI/PlayerAI/BotClassAI/BotPriestAI.h" "AI/PlayerAI/BotClassAI/BotHunterAI.h" "AI/PlayerAI/BotClassAI/BotWarlockAI.h" "AI/PlayerAI/BotClassAI/BotPaladinAI.h" "AI/PlayerAI/BotClassAI/BotRogueAI.h" "AI/PlayerAI/BotClassAI/BotShamanAI.h" "AI/PlayerAI/BotClassAI/BotDruidAI.h" "AI/PlayerAI/BotClassAI/BotDemonHunterAI.h" "AI/PlayerAI/BotClassAI/BotMonkAI.h" "AI/PlayerAI/BotClassAI/BotDeathknightAI.h" "AI/PlayerAI/BotClassAI/BotDruidAI.cpp" "AI/PlayerAI/BotClassAI/BotHunterAI.cpp" "AI/PlayerAI/BotClassAI/BotMageAI.cpp" "AI/PlayerAI/BotClassAI/BotDeathknightAI.cpp" "AI/PlayerAI/BotClassAI/BotPaladinAI.cpp" "AI/PlayerAI/BotClassAI/BotPriestAI.cpp" "AI/PlayerAI/BotClassAI/BotRogueAI.cpp" "AI/PlayerAI/BotClassAI/BotShamanAI.cpp" "AI/PlayerAI/BotClassAI/BotWarlockAI.cpp" "AI/PlayerAI/BotClassAI/BotWarriorAI.cpp" "AI/PlayerAI/BotDuelAI/BotDuelClassAI.h" "AI/PlayerAI/BotDuelAI/BotDuelAI.cpp" "Entities/Unit/CharmInfo.h" "AI/PlayerAI/BotDuelAI/DuelDeathknightAI.cpp"  "AI/PlayerAI/BotDuelAI/DuelDruidAI.cpp" "AI/PlayerAI/BotDuelAI/DuelHunterAI.cpp" "AI/PlayerAI/BotDuelAI/DuelMageAI.cpp" "AI/PlayerAI/BotDuelAI/DuelPaladinAI.cpp" "AI/PlayerAI/BotDuelAI/DuelPriestAI.cpp" "AI/PlayerAI/BotDuelAI/DuelRogueAI.cpp" "AI/PlayerAI/BotDuelAI/DuelShamanAI.cpp" "AI/PlayerAI/BotDuelAI/DuelWarlockAI.cpp" "AI/PlayerAI/BotDuelAI/DuelWarriorAI.cpp" "AI/PlayerAI/BotGroupAI/GroupDeathknightAI.cpp" "AI/PlayerAI/BotGroupAI/GroupDruidAI.cpp" "AI/PlayerAI/BotGroupAI/GroupHunterAI.cpp" "AI/PlayerAI/BotGroupAI/GroupMageAI.cpp" "AI/PlayerAI/BotGroupAI/GroupPaladinAI.cpp" "AI/PlayerAI/BotGroupAI/GroupPriestAI.cpp" "AI/PlayerAI/BotGroupAI/GroupRogueAI.cpp" "AI/PlayerAI/BotGroupAI/GroupShamanAI.cpp" "AI/PlayerAI/BotGroupAI/GroupWarlockAI.cpp" "AI/PlayerAI/BotGroupAI/GroupWarriorAI.cpp" "AI/PlayerAI/BotFieldAI/BotFieldAI.cpp" "AI/PlayerAI/BotFieldAI/BotFieldClassAI.h" "AI/PlayerAI/BotFieldAI/FieldDeathknightAI.cpp" "PlayerBot/FieldBotMgr.h" "AI/PlayerAI/BotFieldAI/FieldWarriorAI.cpp" "AI/PlayerAI/BotFieldAI/FieldWarlockAI.cpp" "AI/PlayerAI/BotFieldAI/FieldShamanAI.cpp" "AI/PlayerAI/BotFieldAI/FieldRogueAI.cpp" "AI/PlayerAI/BotFieldAI/FieldPriestAI.cpp" "AI/PlayerAI/BotFieldAI/FieldPaladinAI.cpp" "AI/PlayerAI/BotFieldAI/FieldMageAI.cpp" "AI/PlayerAI/BotFieldAI/FieldHunterAI.cpp" "AI/PlayerAI/BotFieldAI/FieldDruidAI.cpp" "AI/PlayerAI/BotClassAI/BotMonkAI.cpp" "AI/PlayerAI/BotClassAI/BotDemonHunterAI.cpp" "PlayerBot/PlayerBotMgr.cpp" "Server/OnlineMgr.h"  "PlayerBot/AIWaypointsMgr.cpp" "PlayerBot/FieldBotMgr.cpp" "PlayerBot/PlayerBotTalkMgr.cpp" "PlayerBot/PlayerBotSetting.cpp" "BattlePets/BattlePet.cpp" "BattlePets/PetBattleAbilityEffect.h" "Globals/EventObjectData.h" "Entities/EventObject/EventObject.h" "BattlePets/BattlePetSystem.cpp" "BattlePets/PetBattle.cpp" "BattlePets/PetBattleAbilityEffect.cpp" "Services/ServiceMgr.h" "Maps/BattlegroundMap.cpp" "Handlers/LoginQueryHolder.h")

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
