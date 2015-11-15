if(WIN32)
 set(BOOST_DEBUG ON)
  if(DEFINED ENV{BOOST_ROOT})
    set(BOOST_ROOT $ENV{BOOST_ROOT})
    if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 19.0)
      set(BOOST_LIBRARYDIR ${BOOST_ROOT}/lib${PLATFORM}-msvc-12.0)
    else()
      set(BOOST_LIBRARYDIR ${BOOST_ROOT}/lib${PLATFORM}-msvc-14.0)
    endif()
  else()
    message(FATAL_ERROR "No BOOST_ROOT environment variable could be found! Please make sure it is set and the points to your Boost installation.")
  endif()

  set(Boost_USE_STATIC_LIBS        ON)
  set(Boost_USE_MULTITHREADED      ON)
  set(Boost_USE_STATIC_RUNTIME     OFF)

  add_definitions(-D_WIN32_WINNT=0x0601)
endif()

find_package(Boost 1.49 REQUIRED system filesystem thread program_options iostreams regex)
add_definitions(-DBOOST_DATE_TIME_NO_LIB)
add_definitions(-DBOOST_REGEX_NO_LIB)
add_definitions(-DBOOST_CHRONO_NO_LIB)

# Find if Boost was compiled in C++03 mode because it requires -DBOOST_NO_CXX11_SCOPED_ENUMS

include (CheckCXXSourceCompiles)

set(CMAKE_REQUIRED_INCLUDES ${Boost_INCLUDE_DIR})
set(CMAKE_REQUIRED_LIBRARIES ${Boost_SYSTEM_LIBRARY} ${Boost_FILESYSTEM_LIBRARY} ${Boost_IOSTREAMS_LIBRARY})
set(CMAKE_REQUIRED_FLAGS "-std=c++11")
unset(boost_filesystem_copy_links_without_NO_SCOPED_ENUM CACHE)
check_cxx_source_compiles("
  #include <boost/filesystem/path.hpp>
  #include <boost/filesystem/operations.hpp>
  int main() { boost::filesystem::copy_file(boost::filesystem::path(), boost::filesystem::path()); }"
boost_filesystem_copy_links_without_NO_SCOPED_ENUM)
unset(CMAKE_REQUIRED_INCLUDES CACHE)
unset(CMAKE_REQUIRED_LIBRARIES CACHE)
unset(CMAKE_REQUIRED_FLAGS CACHE)

if (NOT boost_filesystem_copy_links_without_NO_SCOPED_ENUM)
  if (Boost_VERSION LESS 105100) # 1.51
    add_definitions(-DBOOST_NO_SCOPED_ENUMS)
  else()
    add_definitions(-DBOOST_NO_CXX11_SCOPED_ENUMS)
  endif()
endif()

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
endif()
