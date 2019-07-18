# Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

set(protobuf_STAT_SRCS
  src/google/protobuf/compiler/importer.cc
  src/google/protobuf/compiler/parser.cc
  src/google/protobuf/descriptor.cc
  src/google/protobuf/descriptor.pb.cc
  src/google/protobuf/descriptor_database.cc
  src/google/protobuf/dynamic_message.cc
  src/google/protobuf/extension_set.cc
  src/google/protobuf/extension_set_heavy.cc
  src/google/protobuf/generated_message_reflection.cc
  src/google/protobuf/generated_message_util.cc
  src/google/protobuf/io/coded_stream.cc
  src/google/protobuf/io/gzip_stream.cc
  src/google/protobuf/io/printer.cc
  src/google/protobuf/io/strtod.cc
  src/google/protobuf/io/tokenizer.cc
  src/google/protobuf/io/zero_copy_stream.cc
  src/google/protobuf/io/zero_copy_stream_impl.cc
  src/google/protobuf/io/zero_copy_stream_impl_lite.cc
  src/google/protobuf/message.cc
  src/google/protobuf/message_lite.cc
  src/google/protobuf/reflection_ops.cc
  src/google/protobuf/repeated_field.cc
  src/google/protobuf/service.cc
  src/google/protobuf/stubs/common.cc
  src/google/protobuf/stubs/once.cc
  src/google/protobuf/stubs/stringprintf.cc
  src/google/protobuf/stubs/structurally_valid.cc
  src/google/protobuf/stubs/strutil.cc
  src/google/protobuf/stubs/substitute.cc
  src/google/protobuf/text_format.cc
  src/google/protobuf/unknown_field_set.cc
  src/google/protobuf/wire_format.cc
  src/google/protobuf/wire_format_lite.cc
)

if (MSVC)
  set(protobuf_STAT_SRCS
    ${protobuf_STAT_SRCS}
    src/google/protobuf/stubs/atomicops_internals_x86_msvc.cc
  )
else()
  set(protobuf_STAT_SRCS
    ${protobuf_STAT_SRCS}
    src/google/protobuf/stubs/atomicops_internals_x86_gcc.cc
  )
endif()

add_library(protobuf ${protobuf_STAT_SRCS})

target_include_directories(protobuf
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/tc_custom)

target_link_libraries(protobuf
  PRIVATE
    trinity-default-interface
    trinity-no-warning-interface
  PUBLIC
    threads)

if (BUILD_SHARED_LIBS)
  target_compile_definitions(protobuf
    PRIVATE
      -DLIBPROTOBUF_EXPORTS
      -DLIBPROTOC_EXPORTS
    PUBLIC
      -DPROTOBUF_USE_DLLS)
endif()

if (MSVC)
  target_compile_options(protobuf
    PRIVATE
      /wd4996)

  target_compile_definitions(protobuf
    PRIVATE
      -D_SCL_SECURE_NO_WARNINGS)
endif()

set_target_properties(protobuf
  PROPERTIES
    FOLDER
      "dep")

if (BUILD_SHARED_LIBS)
  if (UNIX)
    install(TARGETS protobuf
      LIBRARY
        DESTINATION lib)
  elseif (WIN32)
    install(TARGETS protobuf
      RUNTIME
        DESTINATION "${CMAKE_INSTALL_PREFIX}")
  endif()
endif()
