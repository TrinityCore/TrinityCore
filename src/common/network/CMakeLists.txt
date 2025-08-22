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
  PRIVATE_SOURCES)

GroupSources(${CMAKE_CURRENT_SOURCE_DIR})

add_library(network
  ${PRIVATE_SOURCES})

CollectIncludeDirectories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  PUBLIC_INCLUDES)

target_include_directories(network
  PUBLIC
    ${PUBLIC_INCLUDES}
  PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(network
  PRIVATE
    trinity-core-interface
  PUBLIC
    common)

set_target_properties(network
  PROPERTIES
    COMPILE_WARNING_AS_ERROR ${WITH_WARNINGS_AS_ERRORS}
    DEFINE_SYMBOL TRINITY_API_EXPORT_NETWORK
    FOLDER "server"
    OUTPUT_NAME trinity_network)

if(BUILD_SHARED_LIBS)
  if(UNIX)
    install(TARGETS network
      LIBRARY
        DESTINATION lib)
  elseif(WIN32)
    install(TARGETS network
      RUNTIME
        DESTINATION "${CMAKE_INSTALL_PREFIX}")
  endif()
endif()

# Generate precompiled header
if(USE_COREPCH)
  add_cxx_pch(network PrecompiledHeaders/networkPCH.h)
endif()
