# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

add_library(rapidjson INTERFACE)

target_include_directories(rapidjson
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR})

set(rapidjson_compile_definitions_arch "")

if(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "(x86_64)|(AMD64|amd64)|(^i.86$)")
    set(rapidjson_compile_definitions_arch "-DRAPIDJSON_SSE2")
elseif(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "^arm")
    set(rapidjson_compile_definitions_arch "-DRAPIDJSON_NEON") 
elseif(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "^aarch64")
    set(rapidjson_compile_definitions_arch "-DRAPIDJSON_NEON") 
endif()

target_compile_definitions(rapidjson
  INTERFACE
    -DRAPIDJSON_HAS_STDSTRING
    ${rapidjson_compile_definitions_arch}
    -DRAPIDJSON_48BITPOINTER_OPTIMIZATION=0
    -DRAPIDJSON_ASSERT=WPAssert)
