# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

# Adds all found source files to a given target
#
# Use it like:
# CollectAndAddSourceFiles(
#   common
#   ${CMAKE_CURRENT_SOURCE_DIR}
#   EXCLUDE
#   ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders
#   ${CMAKE_CURRENT_SOURCE_DIR}/Platform)
#
function(CollectAndAddSourceFiles target_name current_dir)
  cmake_parse_arguments(PARSE_ARGV 2 arg "" "BASE_DIR" "EXCLUDE")
  if(NOT arg_BASE_DIR)
    set(arg_BASE_DIR "${current_dir}")
  endif()
  list(FIND arg_EXCLUDE "${current_dir}" IS_EXCLUDED)
  if(IS_EXCLUDED EQUAL -1)
    cmake_path(RELATIVE_PATH current_dir BASE_DIRECTORY "${arg_BASE_DIR}" OUTPUT_VARIABLE fileset_name)
    # normalize file set name
    string(REGEX REPLACE "[./\\]" "_" fileset_name "${fileset_name}")

    file(GLOB private_source_files
      ${current_dir}/*.c
      ${current_dir}/*.cc
      ${current_dir}/*.cpp)

    file(GLOB public_header_files
      ${current_dir}/*.inl
      ${current_dir}/*.h
      ${current_dir}/*.hh
      ${current_dir}/*.hpp)

    target_sources(${target_name} PRIVATE ${private_source_files})
    target_sources(${target_name} PUBLIC FILE_SET "headers_${fileset_name}" TYPE HEADERS BASE_DIRS ${current_dir} FILES ${public_header_files})

    file(GLOB SUB_DIRECTORIES ${current_dir}/*)
    foreach(SUB_DIRECTORY ${SUB_DIRECTORIES})
      if(IS_DIRECTORY ${SUB_DIRECTORY})
        CollectAndAddSourceFiles("${target_name}" "${SUB_DIRECTORY}" BASE_DIR ${arg_BASE_DIR} EXCLUDE ${arg_EXCLUDE})
      endif()
    endforeach()
  endif()
endfunction()

# Collects all subdirectoroies into the given variable,
# which is useful to include all subdirectories.
# Ignores full qualified directories listed in the variadic arguments.
#
# Use it like:
# CollectIncludeDirectories(
#   ${CMAKE_CURRENT_SOURCE_DIR}
#   COMMON_PUBLIC_INCLUDES
#   EXCLUDE
#   ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders
#   ${CMAKE_CURRENT_SOURCE_DIR}/Platform)
#
function(CollectIncludeDirectories current_dir sources_variable)
  cmake_parse_arguments(PARSE_ARGV 2 arg "" "" "EXCLUDE")
  list(FIND arg_EXCLUDE "${current_dir}" IS_EXCLUDED)
  if(IS_EXCLUDED EQUAL -1)
    list(APPEND ${sources_variable} ${current_dir})
    file(GLOB SUB_DIRECTORIES ${current_dir}/*)
    foreach(SUB_DIRECTORY ${SUB_DIRECTORIES})
      if(IS_DIRECTORY ${SUB_DIRECTORY})
        CollectIncludeDirectories("${SUB_DIRECTORY}" "${sources_variable}" EXCLUDE ${arg_EXCLUDE})
      endif()
    endforeach()
    set(${sources_variable} ${${sources_variable}} PARENT_SCOPE)
  endif()
endfunction()
