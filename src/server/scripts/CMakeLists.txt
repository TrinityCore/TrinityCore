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
if (SCRIPTS MATCHES "dynamic")
  set(SCRIPTS_DEFAULT_LINKAGE "dynamic")
elseif(SCRIPTS MATCHES "static")
  set(SCRIPTS_DEFAULT_LINKAGE "static")
else()
  set(SCRIPTS_DEFAULT_LINKAGE "disabled")
endif()
# Sets SCRIPTS_USE_WHITELIST
# Sets SCRIPTS_WHITELIST
if (SCRIPTS MATCHES "minimal")
  set(SCRIPTS_USE_WHITELIST ON)
  # Whitelist which is used when minimal is selected
  list(APPEND SCRIPTS_WHITELIST Commands Spells)
endif()

# Set the SCRIPTS_${SCRIPT_MODULE} variables from the
# variables set above
foreach(SCRIPT_MODULE ${SCRIPT_MODULE_LIST})
  ScriptModuleNameToVariable(${SCRIPT_MODULE} SCRIPT_MODULE_VARIABLE)
  if (${SCRIPT_MODULE_VARIABLE} STREQUAL "default")
    if(SCRIPTS_USE_WHITELIST)
      list(FIND SCRIPTS_WHITELIST "${SCRIPT_MODULE}" INDEX)
      if (${INDEX} GREATER -1)
        set(${SCRIPT_MODULE_VARIABLE} ${SCRIPTS_DEFAULT_LINKAGE})
      else()
        set(${SCRIPT_MODULE_VARIABLE} "disabled")
      endif()
    else()
      set(${SCRIPT_MODULE_VARIABLE} ${SCRIPTS_DEFAULT_LINKAGE})
    endif()
  endif()
  # Build the Graph values
  if (${SCRIPT_MODULE_VARIABLE} MATCHES "dynamic")
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
  if (NOT GRAPH_KEY STREQUAL "disabled")
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
if (USE_SCRIPTPCH)
  set(PRIVATE_PCH_HEADER ScriptPCH.h)
endif ()

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

  if ((${SCRIPT_MODULE_VARIABLE} STREQUAL "disabled") OR
      (${SCRIPT_MODULE_VARIABLE} STREQUAL "static"))
    # Uninstall disabled modules
    GetProjectNameOfScriptModule(${SCRIPT_MODULE} SCRIPT_MODULE_PROJECT_NAME)
    GetNativeSharedLibraryName(${SCRIPT_MODULE_PROJECT_NAME} SCRIPT_MODULE_OUTPUT_NAME)
    list(APPEND DISABLED_SCRIPT_MODULE_PROJECTS ${INSTALL_OFFSET}/${SCRIPT_MODULE_OUTPUT_NAME})
    if (${SCRIPT_MODULE_VARIABLE} STREQUAL "static")
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
  ${PRIVATE_SOURCES})

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
if (USE_SCRIPTPCH)
  list(APPEND ALL_SCRIPT_PROJECTS scripts ${DYNAMIC_SCRIPT_MODULE_PROJECTS})
  add_cxx_pch("${ALL_SCRIPT_PROJECTS}" ${PRIVATE_PCH_HEADER})
endif()

# Remove all shared libraries in the installl directory which
# are contained in the static library already.
if (DISABLED_SCRIPT_MODULE_PROJECTS)
  install(CODE "
    foreach(SCRIPT_TO_UNINSTALL ${DISABLED_SCRIPT_MODULE_PROJECTS})
      if (EXISTS \"\${SCRIPT_TO_UNINSTALL}\")
        message(STATUS \"Uninstalling: \${SCRIPT_TO_UNINSTALL}\")
        file(REMOVE \"\${SCRIPT_TO_UNINSTALL}\")
      endif()
    endforeach()
  ")
endif()

message("")
