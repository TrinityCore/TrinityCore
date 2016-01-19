########### webserver ###############

file(GLOB sources_localdir *.cpp *.h)

if (USE_COREPCH)
  set(webserver_PCH_HDR PrecompiledHeaders/webserverPCH.h)
  set(webserver_PCH_SRC PrecompiledHeaders/webserverPCH.cpp)
endif()

set(webserver_SRCS
  ${sources_localdir}
)

include(../cmake/CMakeIncludeHw2Sys.txt)

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/src/server/shared
  ${CMAKE_SOURCE_DIR}/src/server/shared/Database
  ${CMAKE_SOURCE_DIR}/src/server/shared/Debugging
  ${CMAKE_SOURCE_DIR}/src/server/shared/Packets
  ${CMAKE_SOURCE_DIR}/src/server/shared/Cryptography
  ${CMAKE_SOURCE_DIR}/src/server/shared/Cryptography/Authentication
  ${CMAKE_SOURCE_DIR}/src/server/shared/Logging
  ${CMAKE_SOURCE_DIR}/src/server/shared/Threading
  ${CMAKE_SOURCE_DIR}/src/server/shared/Utilities
  ${ACE_INCLUDE_DIR}
  ${MYSQL_INCLUDE_DIR}
  ${OPENSSL_INCLUDE_DIR}
)

add_executable(webserver
  ${webserver_SRCS}
  ${webserver_PCH_SRC}
)

add_dependencies(webserver revision_data.h)

if( NOT WIN32 )
  set_target_properties(webserver PROPERTIES
    COMPILE_DEFINITIONS _TRINITY_REALM_CONFIG="${CONF_DIR}/webserver.conf"
  )
endif()

target_link_libraries(webserver
  shared
  ${MYSQL_LIBRARY}
  ${OPENSSL_LIBRARIES}
  ${CMAKE_THREAD_LIBS_INIT}
  ${ACE_LIBRARY}
)

if( WIN32 )
  if ( MSVC )
    add_custom_command(TARGET webserver
      POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/webserver.conf.dist ${CMAKE_BINARY_DIR}/bin/$(ConfigurationName)/
    )
  elseif ( MINGW )
    add_custom_command(TARGET authserver
      POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/webserver.conf.dist ${CMAKE_BINARY_DIR}/bin/
    )
  endif()
endif()

if( UNIX )
  install(TARGETS webserver DESTINATION bin)
  install(FILES  webserver.conf.dist DESTINATION ${CONF_DIR})
elseif( WIN32 )
  install(TARGETS webserver DESTINATION "${CMAKE_INSTALL_PREFIX}")
  install(FILES webserver.conf.dist DESTINATION "${CMAKE_INSTALL_PREFIX}")
endif()

# Generate precompiled header
if (USE_COREPCH)
  add_cxx_pch(webserver ${webserver_PCH_HDR} ${webserver_PCH_SRC})
endif()
