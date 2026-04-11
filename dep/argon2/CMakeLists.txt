# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

add_library(argon2 STATIC)

target_sources(argon2
  PRIVATE
    argon2/argon2.c
    argon2/core.c
    argon2/encoding.c
    argon2/thread.c
    argon2/blake2/blake2b.c)

if(TRINITY_SYSTEM_PROCESSOR MATCHES "x86|amd64")
  target_sources(argon2 PRIVATE argon2/opt.c)
else()
  target_sources(argon2 PRIVATE argon2/ref.c)
endif()

target_sources(argon2
  PUBLIC
    FILE_SET HEADERS
    FILES
      argon2/argon2.h
  PRIVATE
    FILE_SET argon2_private_headers
    TYPE HEADERS
    FILES
      argon2/core.h
      argon2/encoding.h
      argon2/thread.h
      argon2/blake2/blake2.h
      argon2/blake2/blake2-impl.h)

target_compile_definitions(argon2
  PRIVATE
    ARGON2_NO_THREADS)

set_target_properties(argon2 PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(argon2
  PRIVATE
    trinity-dependency-interface)

set_target_properties(argon2
  PROPERTIES
    FOLDER
      "dep")
