# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

########### bnetserver ###############

GroupSources(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(bnetserver)

CollectAndAddSourceFiles(
  bnetserver
  ${CMAKE_CURRENT_SOURCE_DIR}
  EXCLUDE
  ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders)

if (WIN32)
  if (MSVC)
    target_sources(bnetserver PRIVATE bnetserver.rc)
  endif()
else()
  target_compile_definitions(bnetserver PRIVATE
    _TRINITY_BNET_CONFIG="${CONF_DIR}/bnetserver.conf"
    _TRINITY_BNET_CONFIG_DIR="${CONF_DIR}/bnetserver.conf.d"
  )
endif()

target_link_libraries(bnetserver
  PRIVATE
    trinity-core-interface
  PUBLIC
    shared)

target_include_directories(bnetserver
  PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR})

set_target_properties(bnetserver
  PROPERTIES
    COMPILE_WARNING_AS_ERROR ${WITH_WARNINGS_AS_ERRORS}
    FOLDER "server")

add_custom_command(TARGET bnetserver
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/bnetserver.cert.pem ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/bnetserver.cert.pem
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/bnetserver.key.pem ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/bnetserver.key.pem
)

if (UNIX)
  install(TARGETS bnetserver DESTINATION bin)
  if (COPY_CONF)
    add_custom_command(TARGET bnetserver
      POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/bnetserver.conf.dist ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/../etc/bnetserver.conf.dist
    )
    install(FILES bnetserver.conf.dist DESTINATION ${CONF_DIR})
  endif()
  install(FILES bnetserver.cert.pem bnetserver.key.pem DESTINATION bin)
elseif (WIN32)
  install(TARGETS bnetserver DESTINATION "${CMAKE_INSTALL_PREFIX}")
  if (COPY_CONF)
    add_custom_command(TARGET bnetserver
      POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/bnetserver.conf.dist ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/bnetserver.conf.dist
    )
    install(FILES bnetserver.conf.dist DESTINATION "${CMAKE_INSTALL_PREFIX}")
  endif()
  install(FILES bnetserver.cert.pem bnetserver.key.pem DESTINATION "${CMAKE_INSTALL_PREFIX}")
endif()

# Generate precompiled header
if (USE_COREPCH)
  add_cxx_pch(bnetserver PrecompiledHeaders/bnetPCH.h)
endif()
