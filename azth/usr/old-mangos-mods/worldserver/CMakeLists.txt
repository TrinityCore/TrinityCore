set(CMAKE_MODULE_PATH 
    ${CMAKE_SOURCE_DIR}/src/hw2system/cmake
    ${CMAKE_MODULE_PATH}
)

if( USE_COREPCH )
  include_directories(${CMAKE_CURRENT_BINARY_DIR})
endif()

#find boost
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.40 COMPONENTS thread regex-mt system-mt filesystem-mt REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
set(LIBS ${LIBS} ${Boost_LIBRARIES})
message(STATUS ${Boost_INCLUDE_DIRS})
message(STATUS ${Boost_LIBRARIES})

find_package(LibEvent)

#find thrift
find_package(Thrift REQUIRED)

if (Thrift_FOUND)
  include_directories(${LibEvent_INCLUDE_DIR} ${Thrift_INCLUDE_DIR})
  add_definitions(-DHT_WITH_THRIFT)
endif ()

file(GLOB_RECURSE sources_database     database/*.cpp database/*.h)
file(GLOB_RECURSE sources_thrift     thrift/*.cpp thrift/*.h)
file(GLOB sources_localdir *.cpp *.h)

if (USE_COREPCH)
  set(hw2server_STAT_PCH_HDR precompiledheaders/Hw2ServerPCH.h)
  set(hw2server_STAT_PCH_SRC precompiledheaders/Hw2ServerPCH.cpp)
endif ()

# Create game-libary
set(hw2server_STAT_SRCS
  ${hw2server_STAT_SRCS}
  ${sources_database}
  ${sources_thrift}
  ${sources_localdir}
)

include(../cmake/CMakeIncludeFull.txt)

add_library(hw2server STATIC
  ${hw2server_STAT_SRCS}
  ${hw2server_STAT_PCH_SRC}
)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})                                                                                                                                                                                                                           
endif()

target_link_libraries(hw2server
  hw2shared
)

add_dependencies(hw2server revision_data.h)

# Generate precompiled header
if (USE_COREPCH)
  add_cxx_pch(hw2server ${hw2server_STAT_PCH_HDR} ${hw2server_STAT_PCH_SRC})
endif ()

target_link_libraries(hw2server 
    ${Thrift_LIB} 
    ${Thrift_NB_LIB} 
    ${LIBEVENT_LIB} 
    ${Boost_LIBRARIES}
)