# Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

CollectIncludeDirectories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  PUBLIC_INCLUDES
  # Exclude
  ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders)
  
execute_process(
    COMMAND python ${PROJECT_SOURCE_DIR}/cmake/describe_enum.py ${CMAKE_CURRENT_BINARY_DIR} ${PUBLIC_INCLUDES} --list
    OUTPUT_VARIABLE GENERATED_ENUM_INPUTS
    ERROR_VARIABLE GENERATED_ENUM_OUTPUTS
    RESULT_VARIABLE ENUM_GENERATION_RETURN
)

if (NOT ENUM_GENERATION_RETURN EQUAL 0)
    message(FATAL_ERROR ${GENERATED_ENUM_OUTPUTS})
endif()

add_custom_command(
    COMMAND python ${PROJECT_SOURCE_DIR}/cmake/describe_enum.py ${CMAKE_CURRENT_BINARY_DIR} ${PUBLIC_INCLUDES}
    DEPENDS ${GENERATED_ENUM_INPUTS} ${PROJECT_SOURCE_DIR}/cmake/describe_enum.py
    OUTPUT ${GENERATED_ENUM_OUTPUTS}
)

CollectSourceFiles(
  ${CMAKE_CURRENT_SOURCE_DIR}
  PRIVATE_SOURCES
  # Exclude
  ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders)

if (USE_COREPCH)
  set(PRIVATE_PCH_HEADER PrecompiledHeaders/sharedPCH.h)
endif()

GroupSources(${CMAKE_CURRENT_SOURCE_DIR})

add_definitions(-DTRINITY_API_EXPORT_SHARED)

add_library(shared
  ${PRIVATE_PCH_SOURCE}
  ${PRIVATE_SOURCES}
  ${GENERATED_ENUM_OUTPUTS}
)

target_include_directories(shared
  PUBLIC
    ${PUBLIC_INCLUDES}
  PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(shared
  PRIVATE
    trinity-core-interface
  PUBLIC
    database)

set_target_properties(shared
    PROPERTIES
      FOLDER
        "server")

if( BUILD_SHARED_LIBS )
  if( UNIX )
    install(TARGETS shared
      LIBRARY
        DESTINATION lib)
  elseif( WIN32 )
    install(TARGETS shared
      RUNTIME
        DESTINATION "${CMAKE_INSTALL_PREFIX}")
  endif()
endif()

# Generate precompiled header
if (USE_COREPCH)
  add_cxx_pch(shared ${PRIVATE_PCH_HEADER})
endif ()
