# set default configuration directory
if( NOT CONF_DIR )
  set(CONF_DIR ${CMAKE_INSTALL_PREFIX}/etc)
endif()

# set default library directory
if( NOT LIBSDIR )
  set(LIBSDIR ${CMAKE_INSTALL_PREFIX}/lib)
endif()

# configure uninstaller
configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
  IMMEDIATE @ONLY
)

# create uninstaller target (allows for using "make uninstall")
add_custom_target(uninstall
  "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
)

include(${CMAKE_SOURCE_DIR}/cmake/compiler/gcc/settings.cmake)

