# Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

# Returns the base path to the script directory in the source directory
function(WarnAboutSpacesInBuildPath)
  # Only check win32 since unix doesn't allow spaces in paths
  if (WIN32)
    string(FIND "${CMAKE_BINARY_DIR}" " " SPACE_INDEX_POS)

    if (SPACE_INDEX_POS GREATER -1)
      message("")
      message(WARNING " *** WARNING!\n"
                      " *** Your selected build directory contains spaces!\n"
                      " *** Please note that this will cause issues!")
    endif()
  endif()
endfunction()

# Returns the base path to the script directory in the source directory
function(GetScriptsBasePath variable)
  set(${variable} "${CMAKE_SOURCE_DIR}/src/server/scripts" PARENT_SCOPE)
endfunction()

# Stores the absolut path of the given module in the variable
function(GetPathToScriptModule module variable)
  GetScriptsBasePath(SCRIPTS_BASE_PATH)
  set(${variable} "${SCRIPTS_BASE_PATH}/${module}" PARENT_SCOPE)
endfunction()

# Stores the project name of the given module in the variable
function(GetProjectNameOfScriptModule module variable)
  string(TOLOWER "scripts_${SCRIPT_MODULE}" GENERATED_NAME)
  set(${variable} "${GENERATED_NAME}" PARENT_SCOPE)
endfunction()

# Creates a list of all script modules
# and stores it in the given variable.
function(GetScriptModuleList variable)
  GetScriptsBasePath(BASE_PATH)
  file(GLOB LOCALE_SCRIPT_MODULE_LIST RELATIVE
    ${BASE_PATH}
    ${BASE_PATH}/*)

  set(${variable})
  foreach(SCRIPT_MODULE ${LOCALE_SCRIPT_MODULE_LIST})
    GetPathToScriptModule(${SCRIPT_MODULE} SCRIPT_MODULE_PATH)
    if (IS_DIRECTORY ${SCRIPT_MODULE_PATH})
      list(APPEND ${variable} ${SCRIPT_MODULE})
    endif()
  endforeach()
  set(${variable} ${${variable}} PARENT_SCOPE)
endfunction()

# Converts the given script module name into it's
# variable name which holds the linkage type.
function(ScriptModuleNameToVariable module variable)
  string(TOUPPER ${module} ${variable})
  set(${variable} "SCRIPTS_${${variable}}")
  set(${variable} ${${variable}} PARENT_SCOPE)
endfunction()

# Stores in the given variable whether dynamic linking is required
function(IsDynamicLinkingRequired variable)
  if(SCRIPTS MATCHES "dynamic")
    set(IS_DEFAULT_VALUE_DYNAMIC ON)
  endif()

  GetScriptModuleList(SCRIPT_MODULE_LIST)
  set(IS_REQUIRED OFF)
  foreach(SCRIPT_MODULE ${SCRIPT_MODULE_LIST})
    ScriptModuleNameToVariable(${SCRIPT_MODULE} SCRIPT_MODULE_VARIABLE)
    if ((${SCRIPT_MODULE_VARIABLE} STREQUAL "dynamic") OR
        (${SCRIPT_MODULE_VARIABLE} STREQUAL "default" AND IS_DEFAULT_VALUE_DYNAMIC))
      set(IS_REQUIRED ON)
      break()
    endif()
  endforeach()
  set(${variable} ${IS_REQUIRED} PARENT_SCOPE)
endfunction()

# Stores the native variable name 
function(GetNativeSharedLibraryName module variable)
  if(WIN32)
    set(${variable} "${module}.dll" PARENT_SCOPE)
  else()
    set(${variable} "lib${module}.so" PARENT_SCOPE)
  endif()
endfunction()

# Stores the native install path in the variable
function(GetInstallOffset variable)
  if(WIN32)
    set(${variable} "${CMAKE_INSTALL_PREFIX}/scripts" PARENT_SCOPE)
  else()
    set(${variable} "${CMAKE_INSTALL_PREFIX}/bin/scripts" PARENT_SCOPE)
  endif()
endfunction()
