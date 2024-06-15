# set default configuration directory
if(NOT CONF_DIR)
  set(CONF_DIR ${CMAKE_INSTALL_PREFIX}/etc CACHE PATH "Configuration directory")
  message(STATUS "UNIX: Using default configuration directory")
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
  "${CMAKE_COMMAND}" -P "${CMAKE_BINARY_DIR}/cmake_uninstall.cmake"
)
message(STATUS "UNIX: Created uninstall target")

if(USE_LD_GOLD)
  execute_process(COMMAND ${CMAKE_C_COMPILER} -fuse-ld=gold -Wl,--version ERROR_QUIET OUTPUT_VARIABLE LD_VERSION)
  if("${LD_VERSION}" MATCHES "GNU gold")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=gold")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -fuse-ld=gold")
    message(STATUS "UNIX: Using GNU gold linker")
  else()
    message(WARNING "UNIX: GNU gold linker isn't available, using the default system linker")
  endif()
else()
  message(STATUS "UNIX: Using default system linker")
endif()

if(APPLE)
  find_program(HOMEBREW_EXECUTABLE brew)

  if (HOMEBREW_EXECUTABLE)
    # setup homebrew paths
    message(STATUS "Homebrew found at ${HOMEBREW_EXECUTABLE}")
    execute_process(COMMAND ${HOMEBREW_EXECUTABLE} config OUTPUT_VARIABLE HOMEBREW_STATUS_STR)
    string(REGEX MATCH "HOMEBREW_PREFIX: ([^\n]*)" HOMEBREW_STATUS_STR ${HOMEBREW_STATUS_STR})
    set(HOMEBREW_PREFIX ${CMAKE_MATCH_1})
    message(STATUS "Homebrew installation found at ${HOMEBREW_PREFIX}")
    set(CMAKE_PREFIX_PATH "${HOMEBREW_PREFIX}")
  endif()
endif()

message(STATUS "UNIX: Detected compiler: ${CMAKE_C_COMPILER}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>/lib")
