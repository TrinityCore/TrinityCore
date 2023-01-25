# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

message("")

# Make the script module list available in the current scope
GetScriptModuleList(SCRIPT_MODULE_LIST)

# Make the native install offset available in this scope
GetInstallOffset(INSTALL_OFFSET)

# Sets the SCRIPTS_${SCRIPT_MODULE} variables
# when using predefined templates for script building
# like dynamic, static, minimal-static...
# Sets SCRIPTS_DEFAULT_LINKAGE
if(SCRIPTS MATCHES "dynamic")
  set(SCRIPTS_DEFAULT_LINKAGE "dynamic")
elseif(SCRIPTS MATCHES "static")
  set(SCRIPTS_DEFAULT_LINKAGE "static")
else()
  set(SCRIPTS_DEFAULT_LINKAGE "disabled")
endif()
# Sets SCRIPTS_USE_WHITELIST
# Sets SCRIPTS_WHITELIST
if(SCRIPTS MATCHES "minimal")
  set(SCRIPTS_USE_WHITELIST ON)
  # Whitelist which is used when minimal is selected
  list(APPEND SCRIPTS_WHITELIST Commands Spells)
endif()

# Set the SCRIPTS_${SCRIPT_MODULE} variables from the
# variables set above
foreach(SCRIPT_MODULE ${SCRIPT_MODULE_LIST})
  ScriptModuleNameToVariable(${SCRIPT_MODULE} SCRIPT_MODULE_VARIABLE)
  if(${SCRIPT_MODULE_VARIABLE} STREQUAL "default")
    if(SCRIPTS_USE_WHITELIST)
      list(FIND SCRIPTS_WHITELIST "${SCRIPT_MODULE}" INDEX)
      if(${INDEX} GREATER -1)
        set(${SCRIPT_MODULE_VARIABLE} ${SCRIPTS_DEFAULT_LINKAGE})
      else()
        set(${SCRIPT_MODULE_VARIABLE} "disabled")
      endif()
    else()
      set(${SCRIPT_MODULE_VARIABLE} ${SCRIPTS_DEFAULT_LINKAGE})
    endif()
  endif()
  # Build the Graph values
  if(${SCRIPT_MODULE_VARIABLE} MATCHES "dynamic")
    GetProjectNameOfScriptModule(${SCRIPT_MODULE} SCRIPT_MODULE_PROJECT_NAME)
    GetNativeSharedLibraryName(${SCRIPT_MODULE_PROJECT_NAME} SCRIPT_PROJECT_LIBRARY)
    list(APPEND GRAPH_KEYS ${SCRIPT_MODULE_PROJECT_NAME})
    set(GRAPH_VALUE_DISPLAY_${SCRIPT_MODULE_PROJECT_NAME} ${SCRIPT_PROJECT_LIBRARY})
    list(APPEND GRAPH_VALUE_CONTAINS_MODULES_${SCRIPT_MODULE_PROJECT_NAME} ${SCRIPT_MODULE})
  elseif(${SCRIPT_MODULE_VARIABLE} MATCHES "static")
    list(APPEND GRAPH_KEYS worldserver)
    set(GRAPH_VALUE_DISPLAY_worldserver worldserver)
    list(APPEND GRAPH_VALUE_CONTAINS_MODULES_worldserver ${SCRIPT_MODULE})
  else()
    list(APPEND GRAPH_KEYS disabled)
    set(GRAPH_VALUE_DISPLAY_disabled disabled)
    list(APPEND GRAPH_VALUE_CONTAINS_MODULES_disabled ${SCRIPT_MODULE})
  endif()
endforeach()

list(SORT GRAPH_KEYS)
list(REMOVE_DUPLICATES GRAPH_KEYS)

# Display the script graph
message("* Script configuration (${SCRIPTS}):
    |")

foreach(GRAPH_KEY ${GRAPH_KEYS})
  if(NOT GRAPH_KEY STREQUAL "disabled")
    message("    +- ${GRAPH_VALUE_DISPLAY_${GRAPH_KEY}}")
  else()
    message("    |  ${GRAPH_VALUE_DISPLAY_${GRAPH_KEY}}")
  endif()
  foreach(GRAPH_PROJECT_ENTRY ${GRAPH_VALUE_CONTAINS_MODULES_${GRAPH_KEY}})
    message("    |   +- ${GRAPH_PROJECT_ENTRY}")
  endforeach()
  message("    |")
endforeach()

# Base sources which are used by every script project
if(USE_SCRIPTPCH)
  set(PRIVATE_PCH_HEADER ScriptPCH.h)
endif()

GroupSources(${CMAKE_CURRENT_SOURCE_DIR})

# Configures the scriptloader with the given name and stores the output in the LOADER_OUT variable.
# It is possible to expose multiple subdirectories from the same scriptloader through passing
# it to the variable arguments
function(ConfigureScriptLoader SCRIPTLOADER_NAME LOADER_OUT IS_DYNAMIC_SCRIPTLOADER)
  # Deduces following variables which are referenced by thge template:
  # TRINITY_IS_DYNAMIC_SCRIPTLOADER
  # TRINITY_SCRIPTS_FORWARD_DECL
  # TRINITY_SCRIPTS_INVOKE
  # TRINITY_CURRENT_SCRIPT_PROJECT

  # To generate export macros
  set(TRINITY_IS_DYNAMIC_SCRIPTLOADER ${IS_DYNAMIC_SCRIPTLOADER})
  # To generate forward declarations of the loading functions
  unset(TRINITY_SCRIPTS_FORWARD_DECL)
  unset(TRINITY_SCRIPTS_INVOKE)
  # The current script project which is built in
  set(TRINITY_CURRENT_SCRIPT_PROJECT ${SCRIPTLOADER_NAME})
  foreach(LOCALE_SCRIPT_MODULE ${ARGN})
    # Determine the loader function ("Add##${NameOfDirectory}##Scripts()")
    set(LOADER_FUNCTION
      "Add${LOCALE_SCRIPT_MODULE}Scripts()")
    # Generate the funciton call and the forward declarations
    set(TRINITY_SCRIPTS_FORWARD_DECL
      "${TRINITY_SCRIPTS_FORWARD_DECL}void ${LOADER_FUNCTION};\n")
    set(TRINITY_SCRIPTS_INVOKE
      "${TRINITY_SCRIPTS_INVOKE}    ${LOADER_FUNCTION};\n")
  endforeach()
  set(GENERATED_LOADER ${CMAKE_CURRENT_BINARY_DIR}/gen_scriptloader/${SCRIPTLOADER_NAME}/ScriptLoader.cpp)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/ScriptLoader.cpp.in.cmake ${GENERATED_LOADER})
  set(${LOADER_OUT} ${GENERATED_LOADER} PARENT_SCOPE)
endfunction()

# Generates the actual script projects
# Fills the STATIC_SCRIPT_MODULES and DYNAMIC_SCRIPT_MODULE_PROJECTS variables
# which contain the names which scripts are linked statically/dynamically and
# adds the sources of the static modules to the PRIVATE_SOURCES variable.
foreach(SCRIPT_MODULE ${SCRIPT_MODULE_LIST})
  GetPathToScriptModule(${SCRIPT_MODULE} SCRIPT_MODULE_PATH)
  ScriptModuleNameToVariable(${SCRIPT_MODULE} SCRIPT_MODULE_VARIABLE)

  if((${SCRIPT_MODULE_VARIABLE} STREQUAL "disabled") OR
      (${SCRIPT_MODULE_VARIABLE} STREQUAL "static"))
    # Uninstall disabled modules
    GetProjectNameOfScriptModule(${SCRIPT_MODULE} SCRIPT_MODULE_PROJECT_NAME)
    GetNativeSharedLibraryName(${SCRIPT_MODULE_PROJECT_NAME} SCRIPT_MODULE_OUTPUT_NAME)
    list(APPEND DISABLED_SCRIPT_MODULE_PROJECTS ${INSTALL_OFFSET}/${SCRIPT_MODULE_OUTPUT_NAME})
    if(${SCRIPT_MODULE_VARIABLE} STREQUAL "static")
      # Add the module name to STATIC_SCRIPT_MODULES
      list(APPEND STATIC_SCRIPT_MODULES ${SCRIPT_MODULE})
      # Add the module content to the whole static module
      CollectSourceFiles(${SCRIPT_MODULE_PATH} PRIVATE_SOURCES)
    endif()
  elseif(${SCRIPT_MODULE_VARIABLE} STREQUAL "dynamic")
    # Generate an own dynamic module which is loadable on runtime
    # Add the module content to the whole static module
    unset(SCRIPT_MODULE_PRIVATE_SOURCES)
    CollectSourceFiles(${SCRIPT_MODULE_PATH} SCRIPT_MODULE_PRIVATE_SOURCES)
    # Configure the scriptloader
    ConfigureScriptLoader(${SCRIPT_MODULE} SCRIPT_MODULE_PRIVATE_SCRIPTLOADER ON ${SCRIPT_MODULE})
    GetProjectNameOfScriptModule(${SCRIPT_MODULE} SCRIPT_MODULE_PROJECT_NAME)
    # Add the module name to DYNAMIC_SCRIPT_MODULES
    list(APPEND DYNAMIC_SCRIPT_MODULE_PROJECTS ${SCRIPT_MODULE_PROJECT_NAME})
    # Create the script module project
    add_library(${SCRIPT_MODULE_PROJECT_NAME} SHARED
      ${SCRIPT_MODULE_PRIVATE_SOURCES}
      ${SCRIPT_MODULE_PRIVATE_SCRIPTLOADER})
    target_link_libraries(${SCRIPT_MODULE_PROJECT_NAME}
      PRIVATE
        trinity-core-interface
      PUBLIC
        game)

    target_include_directories(${SCRIPT_MODULE_PROJECT_NAME}
      PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR})

    set_target_properties(${SCRIPT_MODULE_PROJECT_NAME}
      PROPERTIES
        FOLDER
          "scripts")

    if(UNIX)
      install(TARGETS ${SCRIPT_MODULE_PROJECT_NAME}
        DESTINATION ${INSTALL_OFFSET}
        COMPONENT ${SCRIPT_MODULE_PROJECT_NAME})
    elseif(WIN32)
      install(TARGETS ${SCRIPT_MODULE_PROJECT_NAME}
        RUNTIME DESTINATION ${INSTALL_OFFSET}
        COMPONENT ${SCRIPT_MODULE_PROJECT_NAME})
      if(MSVC)
        # Place the script modules in the script subdirectory
        set_target_properties(${SCRIPT_MODULE_PROJECT_NAME} PROPERTIES
          RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin/Debug/scripts
          RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin/Release/scripts
          RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_BINARY_DIR}/bin/RelWithDebInfo/scripts
          RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL ${CMAKE_BINARY_DIR}/bin/MinSizeRel/scripts)
      endif()
    endif()
  else()
    message(FATAL_ERROR "Unknown value \"${${SCRIPT_MODULE_VARIABLE}}\"!")
  endif()
endforeach()

# Add the dynamic script modules to the worldserver as dependency
set(WORLDSERVER_DYNAMIC_SCRIPT_MODULES_DEPENDENCIES ${DYNAMIC_SCRIPT_MODULE_PROJECTS} PARENT_SCOPE)

ConfigureScriptLoader("static" SCRIPT_MODULE_PRIVATE_SCRIPTLOADER OFF ${STATIC_SCRIPT_MODULES})

add_library(scripts STATIC
  ScriptLoader.h
  ${SCRIPT_MODULE_PRIVATE_SCRIPTLOADER}
  ${PRIVATE_SOURCES} "Custom/hastecraftv2.cpp" "Custom/healthcraft.cpp" "Custom/mod_solocraft.cpp" "Custom/CRcraft.cpp" "Custom/Spellcraft.cpp" "Custom/custom_player_script.cpp" "Custom/world_chat.cpp" "BrokenIsles (2)/broken_isles_script_loader.cpp" "BrokenIsles (2)/legion_portal_at_scripts.cpp" "BrokenIsles (2)/zone_argus.cpp" "BrokenIsles (2)/zone_argus_antoran_wastes.cpp" "BrokenIsles (2)/zone_argus_krokuun.cpp" "BrokenIsles (2)/zone_argus_macaree.cpp" "BrokenIsles (2)/zone_azsuna.cpp" "BrokenIsles (2)/zone_broken_shore.cpp" "BrokenIsles (2)/zone_dalaran_legion.cpp" "BrokenIsles (2)/zone_highmountain.cpp" "BrokenIsles (2)/zone_orderhall_warrior.cpp" "BrokenIsles (2)/zone_stormheim.cpp" "BrokenIsles (2)/zone_suramar.cpp" "BrokenIsles (2)/zone_valsharah.cpp" "BrokenIsles (2)/AntorusTheBurningThrone/antorus.cpp" "BrokenIsles (2)/AntorusTheBurningThrone/antorus.h" "BrokenIsles (2)/AntorusTheBurningThrone/boss_aggramar.cpp" "BrokenIsles (2)/AntorusTheBurningThrone/boss_antoran.cpp" "BrokenIsles (2)/AntorusTheBurningThrone/boss_argus.cpp" "BrokenIsles (2)/AntorusTheBurningThrone/boss_coven_shivarres.cpp" "BrokenIsles (2)/AntorusTheBurningThrone/boss_eonar.cpp" "BrokenIsles (2)/AntorusTheBurningThrone/boss_felhounds.cpp" "BrokenIsles (2)/AntorusTheBurningThrone/boss_hasabel.cpp" "BrokenIsles (2)/AntorusTheBurningThrone/boss_imonar.cpp" "BrokenIsles (2)/AntorusTheBurningThrone/boss_kingaroth.cpp" "BrokenIsles (2)/AntorusTheBurningThrone/boss_varimathras.cpp" "BrokenIsles (2)/AntorusTheBurningThrone/boss_worldbreaker.cpp" "BrokenIsles (2)/AntorusTheBurningThrone/instance_antorus.cpp" "BrokenIsles (2)/BlackRookHold/black_rook_hold.cpp" "BrokenIsles (2)/BlackRookHold/black_rook_hold.h" "BrokenIsles (2)/BlackRookHold/boss_amalgam_of_souls.cpp" "BrokenIsles (2)/BlackRookHold/boss_illysanna_ravencrest.cpp" "BrokenIsles (2)/BlackRookHold/boss_lord_kurtalos_ravencrest.cpp" "BrokenIsles (2)/BlackRookHold/boss_smashspite_the_hateful.cpp" "BrokenIsles (2)/BlackRookHold/instance_black_rook_hold.cpp" "BrokenIsles (2)/CathedralEternalNight/boss_agronox.cpp" "BrokenIsles (2)/CathedralEternalNight/boss_domatrax.cpp" "BrokenIsles (2)/CathedralEternalNight/boss_mephistroth.cpp" "BrokenIsles (2)/CathedralEternalNight/boss_thrashbite_the_scornful.cpp" "BrokenIsles (2)/CathedralEternalNight/cathedral_of_eternal_night.cpp" "BrokenIsles (2)/CathedralEternalNight/cathedral_of_eternal_night.h" "BrokenIsles (2)/CathedralEternalNight/instance_cathedral_of_eternal_night.cpp" "BrokenIsles (2)/ClassHalls/class_hall_dh.cpp" "BrokenIsles (2)/ClassHalls/class_hall_dk.cpp" "BrokenIsles (2)/ClassHalls/class_hall_druid.cpp" "BrokenIsles (2)/ClassHalls/class_hall_hunter.cpp" "BrokenIsles (2)/ClassHalls/class_hall_mage.cpp" "BrokenIsles (2)/ClassHalls/class_hall_monk.cpp" "BrokenIsles (2)/ClassHalls/class_hall_paladin.cpp" "BrokenIsles (2)/ClassHalls/class_hall_priest.cpp" "BrokenIsles (2)/ClassHalls/class_hall_rogue.cpp" "BrokenIsles (2)/ClassHalls/class_hall_shaman.cpp" "BrokenIsles (2)/ClassHalls/class_hall_warlock.cpp" "BrokenIsles (2)/ClassHalls/class_hall_warrior.cpp" "BrokenIsles (2)/CourtOfStars/boss_advisor_melandrus.cpp" "BrokenIsles (2)/CourtOfStars/boss_patrol_captain_gerdo.cpp" "BrokenIsles (2)/CourtOfStars/boss_talixae_flamewreath.cpp" "BrokenIsles (2)/CourtOfStars/court_of_stars.cpp" "BrokenIsles (2)/CourtOfStars/court_of_stars.h" "BrokenIsles (2)/CourtOfStars/instance_court_of_stars.cpp" "BrokenIsles (2)/DarkheartThicket/boss_archdruid_glaidalis.cpp" "BrokenIsles (2)/DarkheartThicket/boss_dresaron.cpp" "BrokenIsles (2)/DarkheartThicket/boss_oakheart.cpp" "BrokenIsles (2)/DarkheartThicket/boss_shade_of_xavius.cpp" "BrokenIsles (2)/DarkheartThicket/darkheart_thicket.cpp" "BrokenIsles (2)/DarkheartThicket/darkheart_thicket.h" "BrokenIsles (2)/DarkheartThicket/instance_darkheart_thicket.cpp" "BrokenIsles (2)/DemonHunterZones/zone_mardum.cpp" "BrokenIsles (2)/DemonHunterZones/zone_vault_of_wardens.cpp" "BrokenIsles (2)/EmeraldNightmare/boss_cenarius.cpp" "BrokenIsles (2)/EmeraldNightmare/boss_dragons_of_nightmare.cpp" "BrokenIsles (2)/EmeraldNightmare/boss_elerethe_renferal.cpp" "BrokenIsles (2)/EmeraldNightmare/boss_ilgynoth.cpp" "BrokenIsles (2)/EmeraldNightmare/boss_nythendra.cpp" "BrokenIsles (2)/EmeraldNightmare/boss_ursoc.cpp" "BrokenIsles (2)/EmeraldNightmare/boss_xavius.cpp" "BrokenIsles (2)/EmeraldNightmare/emerald_nightmare.cpp" "BrokenIsles (2)/EmeraldNightmare/emerald_nightmare.h" "BrokenIsles (2)/EmeraldNightmare/instance_emerald_nightmare.cpp" "BrokenIsles (2)/EyeOfAzshara/boss_king_deepbeard.cpp" "BrokenIsles (2)/EyeOfAzshara/boss_lady_hatecoil.cpp" "BrokenIsles (2)/EyeOfAzshara/boss_serpentrix.cpp" "BrokenIsles (2)/EyeOfAzshara/boss_warlord_parjesh.cpp" "BrokenIsles (2)/EyeOfAzshara/boss_wrath_of_azshara.cpp" "BrokenIsles (2)/EyeOfAzshara/eye_of_azshara.cpp" "BrokenIsles (2)/EyeOfAzshara/eye_of_azshara.h" "BrokenIsles (2)/EyeOfAzshara/instance_eye_of_azshara.cpp" "BrokenIsles (2)/HallsOfValor/boss_fenryr.cpp" "BrokenIsles (2)/HallsOfValor/boss_godking_skovald.cpp" "BrokenIsles (2)/HallsOfValor/boss_hymdall.cpp" "BrokenIsles (2)/HallsOfValor/boss_hyrja.cpp" "BrokenIsles (2)/HallsOfValor/boss_odyn.cpp" "BrokenIsles (2)/HallsOfValor/halls_of_valor.cpp" "BrokenIsles (2)/HallsOfValor/halls_of_valor.h" "BrokenIsles (2)/HallsOfValor/instance_halls_of_valor.cpp" "BrokenIsles (2)/InvasionPoint/invasion_point_argus.cpp" "BrokenIsles (2)/InvasionPoint/zone_invasion_point.cpp" "BrokenIsles (2)/MawOfSouls/boss_harbaron_maw.cpp" "BrokenIsles (2)/MawOfSouls/boss_helya_maw.cpp" "BrokenIsles (2)/MawOfSouls/boss_ymiron_maw.cpp" "BrokenIsles (2)/MawOfSouls/instance_maw_of_souls.cpp" "BrokenIsles (2)/MawOfSouls/maw_of_souls.cpp" "BrokenIsles (2)/MawOfSouls/maw_of_souls.h" "BrokenIsles (2)/MicroHolidays/AuctionHouseDanceParty.cpp" "BrokenIsles (2)/NeltharionsLair/boss_dargrul_the_underking.cpp" "BrokenIsles (2)/NeltharionsLair/boss_naraxas.cpp" "BrokenIsles (2)/NeltharionsLair/boss_rokmora.cpp" "BrokenIsles (2)/NeltharionsLair/boss_ularogg_cragshaper.cpp" "BrokenIsles (2)/NeltharionsLair/instance_neltharions_lair.cpp" "BrokenIsles (2)/NeltharionsLair/neltharions_lair.cpp" "BrokenIsles (2)/NeltharionsLair/neltharions_lair.h" "BrokenIsles (2)/Professions/legion_profession_blacksmithing.cpp" "BrokenIsles (2)/ReturnToKharazan/boss_attumen.cpp" "BrokenIsles (2)/ReturnToKharazan/boss_curator.cpp" "BrokenIsles (2)/ReturnToKharazan/boss_maiden_of_virtue.cpp" "BrokenIsles (2)/ReturnToKharazan/boss_mana_devourer.cpp" "BrokenIsles (2)/ReturnToKharazan/boss_moroes.cpp" "BrokenIsles (2)/ReturnToKharazan/boss_nightbane.cpp" "BrokenIsles (2)/ReturnToKharazan/boss_opera.cpp" "BrokenIsles (2)/ReturnToKharazan/boss_shade_of_medivh.cpp" "BrokenIsles (2)/ReturnToKharazan/boss_vizaduum.cpp" "BrokenIsles (2)/ReturnToKharazan/instance_new_karazhan.cpp" "BrokenIsles (2)/ReturnToKharazan/new_karazhan.cpp" "BrokenIsles (2)/ReturnToKharazan/new_karazhan.h" "BrokenIsles (2)/Scenario/scenario_artifact_brokenshore.cpp" "BrokenIsles (2)/Scenario/scenario_artifact_karazhan_catacombs.cpp" "BrokenIsles (2)/Scenario/scenario_artifact_restoacqusition.cpp" "BrokenIsles (2)/Scenario/scenario_artifact_ruins_of_falanaar.cpp" "BrokenIsles (2)/Scenario/scenario_artifact_tirisfal_glades.cpp" "BrokenIsles (2)/Scenario/scenario_artifact_truthguard.cpp" "BrokenIsles (2)/Scenario/scenario_artifact_ursocslair.cpp" "BrokenIsles (2)/Scenario/scenario_defense_of_aviana.cpp" "BrokenIsles (2)/Scenario/scenario_mage_art.cpp" "BrokenIsles (2)/Scenario/scenario_the_violet_hold.cpp" "BrokenIsles (2)/Scenario/scenario_the_violet_hold_Dh.cpp" "BrokenIsles (2)/Scenario/scenario_you_cant_take_the_sky_from_me.cpp" "BrokenIsles (2)/SeatOfTriumvirate/boss_lura.cpp" "BrokenIsles (2)/SeatOfTriumvirate/boss_saprish.cpp" "BrokenIsles (2)/SeatOfTriumvirate/boss_viceroy_nezhar.cpp" "BrokenIsles (2)/SeatOfTriumvirate/boss_zuraal_the_ascended.cpp" "BrokenIsles (2)/SeatOfTriumvirate/instance_seat_of_triumvirate.cpp" "BrokenIsles (2)/SeatOfTriumvirate/seat_of_triumvirate.cpp" "BrokenIsles (2)/SeatOfTriumvirate/seat_of_triumvirate.h" "BrokenIsles (2)/TheArcway/boss_advisor_vandros.cpp" "BrokenIsles (2)/TheArcway/boss_corstilax.cpp" "BrokenIsles (2)/TheArcway/boss_general_xakal.cpp" "BrokenIsles (2)/TheArcway/boss_ivanyr.cpp" "BrokenIsles (2)/TheArcway/boss_naltira.cpp" "BrokenIsles (2)/TheArcway/instance_the_arcway.cpp" "BrokenIsles (2)/TheArcway/the_arcway.h" "BrokenIsles (2)/TheNighthold/boss_aluriel.cpp" "BrokenIsles (2)/TheNighthold/boss_chronomatic_anomaly.cpp" "BrokenIsles (2)/TheNighthold/boss_elisande.cpp" "BrokenIsles (2)/TheNighthold/boss_guldan.cpp" "BrokenIsles (2)/TheNighthold/boss_high_botanist_telarn.cpp" "BrokenIsles (2)/TheNighthold/boss_krosus.cpp" "BrokenIsles (2)/TheNighthold/boss_skorpyron.cpp" "BrokenIsles (2)/TheNighthold/boss_star_augur_etraeus.cpp" "BrokenIsles (2)/TheNighthold/boss_tichondrius.cpp" "BrokenIsles (2)/TheNighthold/boss_trilliax.cpp" "BrokenIsles (2)/TheNighthold/instance_the_nighthold.cpp" "BrokenIsles (2)/TheNighthold/thenighthold.h" "BrokenIsles (2)/TheNighthold/the_nighthold.cpp" "BrokenIsles (2)/TombOfSargeras/boss_demonic_inquisition.cpp" "BrokenIsles (2)/TombOfSargeras/boss_desolate_host.cpp" "BrokenIsles (2)/TombOfSargeras/boss_fallen_avatar.cpp" "BrokenIsles (2)/TombOfSargeras/boss_goroth.cpp" "BrokenIsles (2)/TombOfSargeras/boss_harjatan.cpp" "BrokenIsles (2)/TombOfSargeras/boss_kiljaeden.cpp" "BrokenIsles (2)/TombOfSargeras/boss_maiden_of_vigilance.cpp" "BrokenIsles (2)/TombOfSargeras/boss_sasszine.cpp" "BrokenIsles (2)/TombOfSargeras/boss_sisters_of_moon.cpp" "BrokenIsles (2)/TombOfSargeras/instance_tomb_of_sargeras.cpp" "BrokenIsles (2)/TombOfSargeras/tomb_of_sargeras.cpp" "BrokenIsles (2)/TombOfSargeras/tomb_of_sargeras.h" "BrokenIsles (2)/TrialOfValor/boss_tov_garm.cpp" "BrokenIsles (2)/TrialOfValor/boss_tov_helya.cpp" "BrokenIsles (2)/TrialOfValor/boss_tov_odyn.cpp" "BrokenIsles (2)/TrialOfValor/instance_trial_of_valor.cpp" "BrokenIsles (2)/TrialOfValor/trial_of_valor.cpp" "BrokenIsles (2)/TrialOfValor/trial_of_valor.h" "BrokenIsles (2)/VaultOfTheWardens/boss_ashgolm.cpp" "BrokenIsles (2)/VaultOfTheWardens/boss_cordana_felsong.cpp" "BrokenIsles (2)/VaultOfTheWardens/boss_glazer.cpp" "BrokenIsles (2)/VaultOfTheWardens/boss_inquisitor_tormentorum.cpp" "BrokenIsles (2)/VaultOfTheWardens/boss_tirathon_saltheril.cpp" "BrokenIsles (2)/VaultOfTheWardens/instance_vault_of_the_wardens.cpp" "BrokenIsles (2)/VaultOfTheWardens/vault_of_the_wardens.cpp" "BrokenIsles (2)/VaultOfTheWardens/vault_of_the_wardens.h" "BrokenIsles (2)/VioletHold/boss_anubesset.cpp" "BrokenIsles (2)/VioletHold/boss_blood_princess.cpp" "BrokenIsles (2)/VioletHold/boss_fel_lord_betrug.cpp" "BrokenIsles (2)/VioletHold/boss_festerface.cpp" "BrokenIsles (2)/VioletHold/boss_millificent_manastorm.cpp" "BrokenIsles (2)/VioletHold/boss_mind_flayer_kaarhj.cpp" "BrokenIsles (2)/VioletHold/boss_saelorn.cpp" "BrokenIsles (2)/VioletHold/boss_shivermaw.cpp" "BrokenIsles (2)/VioletHold/instance_violet_hold_assault.cpp" "BrokenIsles (2)/VioletHold/violet_hold.cpp" "BrokenIsles (2)/VioletHold/violet_hold_assault.h" "BrokenIsles (2)/WorldBosses/boss_ana_mouz.cpp" "BrokenIsles (2)/WorldBosses/boss_apocron.cpp" "BrokenIsles (2)/WorldBosses/boss_brutallus_legion.cpp" "BrokenIsles (2)/WorldBosses/boss_calamir.cpp" "BrokenIsles (2)/WorldBosses/boss_drugon_the_frostblood.cpp" "BrokenIsles (2)/WorldBosses/boss_flotsam.cpp" "BrokenIsles (2)/WorldBosses/boss_humongris.cpp" "BrokenIsles (2)/WorldBosses/boss_levantus.cpp" "BrokenIsles (2)/WorldBosses/boss_malificus.cpp" "BrokenIsles (2)/WorldBosses/boss_nazak_the_fiend.cpp" "BrokenIsles (2)/WorldBosses/boss_nithogg.cpp" "BrokenIsles (2)/WorldBosses/boss_sharthos.cpp" "BrokenIsles (2)/WorldBosses/boss_the_soultakers.cpp" "BrokenIsles (2)/WorldBosses/boss_withered_jim.cpp")

target_link_libraries(scripts
  PRIVATE
    trinity-core-interface
  PUBLIC
    game-interface)

target_include_directories(scripts
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(scripts
  PROPERTIES
    FOLDER
      "scripts")

# Generate precompiled header
if(USE_SCRIPTPCH)
  list(APPEND ALL_SCRIPT_PROJECTS scripts ${DYNAMIC_SCRIPT_MODULE_PROJECTS})
  add_cxx_pch("${ALL_SCRIPT_PROJECTS}" ${PRIVATE_PCH_HEADER})
endif()

# Remove all shared libraries in the installl directory which
# are contained in the static library already.
if(DISABLED_SCRIPT_MODULE_PROJECTS)
  install(CODE "
    foreach(SCRIPT_TO_UNINSTALL ${DISABLED_SCRIPT_MODULE_PROJECTS})
      if(EXISTS \"\${SCRIPT_TO_UNINSTALL}\")
        message(STATUS \"Uninstalling: \${SCRIPT_TO_UNINSTALL}\")
        file(REMOVE \"\${SCRIPT_TO_UNINSTALL}\")
      endif()
    endforeach()
  ")
endif()

message("")
