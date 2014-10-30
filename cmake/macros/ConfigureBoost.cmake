macro(get_WIN32_WINNT version)
    if (WIN32 AND CMAKE_SYSTEM_VERSION)
        set(ver ${CMAKE_SYSTEM_VERSION})
        string(REPLACE "." "" ver ${ver})
        string(REGEX REPLACE "([0-9])" "0\\1" ver ${ver})

        set(${version} "0x${ver}")
    endif()
endmacro()

if(WIN32)
 set(BOOST_DEBUG ON)
  if(DEFINED ENV{BOOST_ROOT})
    set(BOOST_ROOT $ENV{BOOST_ROOT})
    set(BOOST_LIBRARYDIR ${BOOST_ROOT}/lib${PLATFORM}-msvc-12.0)
  else()
    message(FATAL_ERROR "No BOOST_ROOT environment variable could be found! Please make sure it is set and the points to your Boost installation.")
  endif()

  set(Boost_USE_STATIC_LIBS        ON)
  set(Boost_USE_MULTITHREADED      ON)
  set(Boost_USE_STATIC_RUNTIME     OFF)

  get_WIN32_WINNT(ver)
  add_definitions(-D_WIN32_WINNT=${ver})
endif()

find_package(Boost 1.49 REQUIRED system filesystem thread program_options)
add_definitions(-DBOOST_DATE_TIME_NO_LIB)
add_definitions(-DBOOST_REGEX_NO_LIB)
add_definitions(-DBOOST_CHRONO_NO_LIB)

try_compile (boost_filesystem_copy_links_without_NO_SCOPED_ENUM
  ${CMAKE_BINARY_DIR}/try_compile/boost_filesystem_copy_links_without_NO_SCOPED_ENUM
  SOURCES ${CMAKE_SOURCE_DIR}/cmake/test_use_boost_cxx11_no_scoped_enum_for_filesystem.cpp
  COMPILE_DEFINITIONS -I${Boost_INCLUDE_DIR}
                      --std=c++11
  LINK_LIBRARIES ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY}
)

if (NOT boost_filesystem_copy_links_without_NO_SCOPED_ENUM)
  add_definitions(-DBOOST_NO_CXX11_SCOPED_ENUMS)
endif()

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
endif()
