cmake_minimum_required(VERSION 3.8)
project(protoc_bnet)

set(CXX_EXTENSIONS OFF)

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
target_compile_features(protoc-gen-bnet
  PUBLIC
    cxx_std_17
    cxx_alias_templates
    cxx_auto_type
    cxx_constexpr
    cxx_decltype
    cxx_decltype_auto
    cxx_final
    cxx_lambdas
    cxx_generic_lambdas
    cxx_variadic_templates
    cxx_defaulted_functions
    cxx_nullptr
    cxx_trailing_return_types
    cxx_return_type_deduction)

target_link_libraries(protoc-gen-bnet ${PROTOBUF_PROTOC_LIBRARIES} ${PROTOBUF_LIBRARIES})

set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR})

install(TARGETS protoc-gen-bnet DESTINATION bin)
