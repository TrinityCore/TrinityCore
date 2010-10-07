# set default configuration directory
if( NOT CONF_DIR )
  set(CONF_DIR ${CMAKE_INSTALL_PREFIX}/etc)
  message(STATUS "UNIX: Using default configuration directory")
endif()

# set default library directory
if( NOT LIBSDIR )
  set(LIBSDIR ${CMAKE_INSTALL_PREFIX}/lib)
  message(STATUS "UNIX: Using default library directory")
endif()

# configure uninstaller
configure_file(
  "${CMAKE_SOURCE_DIR}/cmake/platform/cmake_uninstall.in.cmake"
  "${CMAKE_BINARY_DIR}/cmake_uninstall.cmake"
  @ONLY
)
message(STATUS "UNIX: Configuring uninstall target")

# create uninstaller target (allows for using "make uninstall")
add_custom_target(uninstall
  "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
)
message(STATUS "UNIX: Created uninstall target")

include(${CMAKE_SOURCE_DIR}/cmake/compiler/gcc/settings.cmake)
