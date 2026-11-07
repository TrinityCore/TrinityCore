# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

add_library(openssl_ed25519 SHARED)

target_sources(openssl_ed25519
  PRIVATE
    curve25519.c)

target_sources(openssl_ed25519
  PUBLIC
    FILE_SET HEADERS
    FILES
      ed25519/ed25519.h
  PRIVATE
    FILE_SET openssl_ed25519_private_headers
    TYPE HEADERS
    FILES
      ec_lcl.h
      internal/refcount.h)

set_target_properties(openssl_ed25519 PROPERTIES LINKER_LANGUAGE CXX)

target_compile_definitions(openssl_ed25519
  PRIVATE
    OPENSSL_ED25519_EXPORT)

target_link_libraries(openssl_ed25519
  PRIVATE
    trinity-dependency-interface
  PUBLIC
    openssl)

set_target_properties(openssl_ed25519
    PROPERTIES
      FOLDER
        "dep")

if(UNIX)
  install(TARGETS openssl_ed25519
    LIBRARY
      DESTINATION lib)
elseif(WIN32)
  install(TARGETS openssl_ed25519
    RUNTIME
      DESTINATION "${CMAKE_INSTALL_PREFIX}")
endif()
