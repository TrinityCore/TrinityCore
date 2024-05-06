#
# This file is part of the AzerothCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#

# Returns the base path to the script directory in the source directory
function(GetModulesBasePath variable)
  set(${variable} "${CMAKE_SOURCE_DIR}/modules" PARENT_SCOPE)
endfunction()

# Stores the absolut path of the given module in the variable
function(GetPathToModuleSource module variable)
  GetModulesBasePath(MODULE_BASE_PATH)
  set(${variable} "${MODULE_BASE_PATH}/${module}/src" PARENT_SCOPE)
endfunction()

# Stores the project name of the given module in the variable
function(GetProjectNameOfModuleName module variable)
  string(TOLOWER "mod_${SOURCE_MODULE}" GENERATED_NAME)
  set(${variable} "${GENERATED_NAME}" PARENT_SCOPE)
endfunction()

# Creates a list of all script modules
# and stores it in the given variable.
function(GetModuleSourceList variable)
  GetModulesBasePath(BASE_PATH)
  file(GLOB LOCALE_MODULE_LIST RELATIVE
    ${BASE_PATH}
    ${BASE_PATH}/*)

  set(${variable})
  foreach(SOURCE_MODULE ${LOCALE_MODULE_LIST})
    GetPathToModuleSource(${SOURCE_MODULE} MODULE_SOURCE_PATH)
    if(IS_DIRECTORY ${MODULE_SOURCE_PATH})
      list(APPEND ${variable} ${SOURCE_MODULE})
    endif()
  endforeach()
  set(${variable} ${${variable}} PARENT_SCOPE)
endfunction()

# Converts the given script module name into it's
# variable name which holds the linkage type.
function(ModuleNameToVariable module variable)
  string(TOUPPER ${module} ${variable})
  set(${variable} "MODULE_${${variable}}")
  set(${variable} ${${variable}} PARENT_SCOPE)
endfunction()

# Stores in the given variable whether dynamic linking is required
function(IsDynamicLinkingModulesRequired variable)
  if(MODULES MATCHES "dynamic")
    set(IS_DEFAULT_VALUE_DYNAMIC_MODULE ON)
  endif()

  GetModuleSourceList(MODULES_MODULE_LIST)
  set(IS_REQUIRED OFF)
  foreach(SOURCE_MODULE ${MODULES_MODULE_LIST})
    ModuleNameToVariable(${SOURCE_MODULE} MODULE_MODULE_VARIABLE)
    if((${MODULE_MODULE_VARIABLE} STREQUAL "dynamic") OR
        (${MODULE_MODULE_VARIABLE} STREQUAL "default" AND IS_DEFAULT_VALUE_DYNAMIC_MODULE))
      set(IS_REQUIRED ON)
      break()
    endif()
  endforeach()
  set(${variable} ${IS_REQUIRED} PARENT_SCOPE)
endfunction()
