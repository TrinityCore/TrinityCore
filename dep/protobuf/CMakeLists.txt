# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

add_library(protobuf)

target_sources(protobuf
  PRIVATE
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
    src/google/protobuf/stubs/atomicops_internals_x86_gcc.cc
    src/google/protobuf/stubs/atomicops_internals_x86_msvc.cc
    src/google/protobuf/stubs/common.cc
    src/google/protobuf/stubs/once.cc
    src/google/protobuf/stubs/stringprintf.cc
    src/google/protobuf/stubs/structurally_valid.cc
    src/google/protobuf/stubs/strutil.cc
    src/google/protobuf/stubs/substitute.cc
    src/google/protobuf/text_format.cc
    src/google/protobuf/unknown_field_set.cc
    src/google/protobuf/wire_format.cc
    src/google/protobuf/wire_format_lite.cc)

target_sources(protobuf
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS src
    FILES
      src/google/protobuf/compiler/importer.h
      src/google/protobuf/compiler/parser.h
      src/google/protobuf/descriptor_database.h
      src/google/protobuf/descriptor.h
      src/google/protobuf/descriptor.pb.h
      src/google/protobuf/dynamic_message.h
      src/google/protobuf/extension_set.h
      src/google/protobuf/generated_enum_reflection.h
      src/google/protobuf/generated_message_reflection.h
      src/google/protobuf/generated_message_util.h
      src/google/protobuf/io/coded_stream.h
      src/google/protobuf/io/coded_stream_inl.h
      src/google/protobuf/io/gzip_stream.h
      src/google/protobuf/io/printer.h
      src/google/protobuf/io/strtod.h
      src/google/protobuf/io/tokenizer.h
      src/google/protobuf/io/zero_copy_stream.h
      src/google/protobuf/io/zero_copy_stream_impl.h
      src/google/protobuf/io/zero_copy_stream_impl_lite.h
      src/google/protobuf/message.h
      src/google/protobuf/message_lite.h
      src/google/protobuf/reflection_ops.h
      src/google/protobuf/repeated_field.h
      src/google/protobuf/service.h
      src/google/protobuf/stubs/atomicops.h
      src/google/protobuf/stubs/common.h
      src/google/protobuf/stubs/hash.h
      src/google/protobuf/stubs/map_util.h
      src/google/protobuf/stubs/once.h
      src/google/protobuf/stubs/platform_macros.h
      src/google/protobuf/stubs/stl_util.h
      src/google/protobuf/stubs/stringprintf.h
      src/google/protobuf/stubs/strutil.h
      src/google/protobuf/stubs/substitute.h
      src/google/protobuf/stubs/template_util.h
      src/google/protobuf/stubs/type_traits.h
      src/google/protobuf/text_format.h
      src/google/protobuf/unknown_field_set.h
      src/google/protobuf/wire_format.h
      src/google/protobuf/wire_format_lite.h
      src/google/protobuf/wire_format_lite_inl.h
  PRIVATE
    FILE_SET protobuf_private_headers
    TYPE HEADERS
    BASE_DIRS tc_custom
    FILES
      tc_custom/config.h)

target_link_libraries(protobuf
  PRIVATE
    trinity-default-interface
    trinity-no-warning-interface
  PUBLIC
    threads)

if (BUILD_SHARED_LIBS)
  target_compile_definitions(protobuf
    PRIVATE
      LIBPROTOBUF_EXPORTS
      LIBPROTOC_EXPORTS
    PUBLIC
      PROTOBUF_USE_DLLS)
endif()

if (MSVC)
  target_compile_options(protobuf
    PRIVATE
      /wd4996)

  target_compile_definitions(protobuf
    PRIVATE
      _SCL_SECURE_NO_WARNINGS)
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

# Generate precompiled header
if(USE_COREPCH)
  list(APPEND protobuf_PCH_HEADERS
    <google/protobuf/descriptor.pb.h>
    <google/protobuf/io/coded_stream.h>
    <google/protobuf/wire_format.h>
    <google/protobuf/stubs/hash.h>
    <google/protobuf/stubs/strutil.h>
    <algorithm>
    <memory>)

  add_cxx_pch(protobuf "${protobuf_PCH_HEADERS}")
endif()
