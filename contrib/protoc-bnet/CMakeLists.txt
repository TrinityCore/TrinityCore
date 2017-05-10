cmake_minimum_required(VERSION 3.0)
project(protoc_bnet)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Protobuf REQUIRED)

file(GLOB_RECURSE SOURCE_PROTOBUF_CPP google/protobuf/*.cc)

set(SOURCE_FILES
  main.cpp
  BnetCodeGenerator.cpp
  BnetFileGenerator.cpp
  BnetServiceGenerator.cpp
  method_options.pb.cc
  service_options.pb.cc
  ${SOURCE_PROTOBUF_CPP})

include_directories(${CMAKE_SOURCE_DIR} ${PROTOBUF_INCLUDE_DIRS})

add_executable(protoc-gen-bnet ${SOURCE_FILES})

target_link_libraries(protoc-gen-bnet ${PROTOBUF_PROTOC_LIBRARIES} ${PROTOBUF_LIBRARIES})

set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR})

add_custom_target(install_plugin
  make install
  DEPENDS protoc-gen-bnet
  COMMENT "Installing protoc_bnet")

install(TARGETS protoc-gen-bnet DESTINATION bin)
