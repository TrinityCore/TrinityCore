set(MACOSX 1)
set(OSX_LIBS /usr/lib/libcrypto.dylib)
add_definitions(-D__ASSERTMACROS__)

# set default configuration directory
if( NOT CONF_DIR )
  set(CONF_DIR ${CMAKE_INSTALL_PREFIX}/etc)
  message(STATUS "OSX: Using default configuration directory")
endif()

# set default library directory
if( NOT LIBSDIR )
  set(LIBSDIR ${CMAKE_INSTALL_PREFIX}/lib)
  message(STATUS "OSX: Using default library directory")
endif()

# configure uninstaller
configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
  IMMEDIATE @ONLY
)
message(STATUS "OSX: Configuring uninstall target")

# create uninstaller target (allows for using "make uninstall")
add_custom_target(uninstall
  "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
)
message(STATUS "OSX: Created uninstall target")
