# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

if(WIN32)
  set(BOOST_DEBUG ON)
  if(DEFINED ENV{BOOST_ROOT})
    set(BOOST_ROOT $ENV{BOOST_ROOT})
    list(APPEND BOOST_LIBRARYDIR
      ${BOOST_ROOT}/lib${PLATFORM}-msvc-14.2 )
  elseif(NOT DEFINED Boost_DIR AND NOT DEFINED BOOST_ROOT AND NOT DEFINED BOOSTROOT)
    message(FATAL_ERROR "No BOOST_ROOT environment variable could be found! Please make sure it is set and the points to your Boost installation.")
  endif()

  set(Boost_USE_STATIC_LIBS        ON)
  set(Boost_USE_MULTITHREADED      ON)
  set(Boost_USE_STATIC_RUNTIME     OFF)
endif()

if (CMAKE_VERSION VERSION_LESS "3.16.0")
  # boost's own cmake file adds extra compile definitions that cotire fails to pick up
  set(Boost_NO_BOOST_CMAKE ON)
endif()

include (CheckCXXSourceCompiles)

check_cxx_source_compiles("
  #include <regex>
  int main() { std::wregex r(L\".*\"); }"
  STD_HAS_WORKING_WREGEX)

if (WIN32)
  # On windows the requirements are higher according to the wiki.
  set(BOOST_REQUIRED_VERSION 1.70)
else()
  set(BOOST_REQUIRED_VERSION 1.68)
endif()

if (STD_HAS_WORKING_WREGEX)
  find_package(Boost ${BOOST_REQUIRED_VERSION} REQUIRED system filesystem thread program_options iostreams)
else()
  find_package(Boost ${BOOST_REQUIRED_VERSION} REQUIRED system filesystem thread program_options iostreams regex)
endif()

# Find if Boost was compiled in C++03 mode because it requires -DBOOST_NO_CXX11_SCOPED_ENUMS

set(CMAKE_REQUIRED_INCLUDES ${Boost_INCLUDE_DIR})
set(CMAKE_REQUIRED_LIBRARIES ${Boost_SYSTEM_LIBRARY} ${Boost_FILESYSTEM_LIBRARY} ${Boost_IOSTREAMS_LIBRARY})
set(CMAKE_REQUIRED_FLAGS "-std=c++11")
check_cxx_source_compiles("
  #include <boost/filesystem/path.hpp>
  #include <boost/filesystem/operations.hpp>
  int main() { boost::filesystem::copy_file(boost::filesystem::path(), boost::filesystem::path()); }"
boost_filesystem_copy_links_without_NO_SCOPED_ENUM)
unset(CMAKE_REQUIRED_INCLUDES)
unset(CMAKE_REQUIRED_LIBRARIES)
unset(CMAKE_REQUIRED_FLAGS)

add_library(boost INTERFACE)

target_link_libraries(boost
  INTERFACE
    ${Boost_LIBRARIES})

target_include_directories(boost
  INTERFACE
    ${Boost_INCLUDE_DIRS})

target_compile_definitions(boost
  INTERFACE
    -DBOOST_DATE_TIME_NO_LIB
    -DBOOST_REGEX_NO_LIB
    -DBOOST_CHRONO_NO_LIB
    -DBOOST_SERIALIZATION_NO_LIB
    -DBOOST_CONFIG_SUPPRESS_OUTDATED_MESSAGE
    -DBOOST_ASIO_NO_DEPRECATED
    -DBOOST_BIND_NO_PLACEHOLDERS)

if (NOT boost_filesystem_copy_links_without_NO_SCOPED_ENUM)
  target_compile_definitions(boost
    INTERFACE
      -DBOOST_NO_CXX11_SCOPED_ENUMS)
endif()

if (NOT STD_HAS_WORKING_WREGEX)
  target_compile_definitions(boost
    INTERFACE
      -DTC_HAS_BROKEN_WSTRING_REGEX)
endif()
