# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.


# basic packagesearching and setup
# (further support will be needed, this is a preliminary release!)
find_package(OpenSSL 3 REQUIRED COMPONENTS Crypto SSL)

add_library(openssl INTERFACE)

target_link_libraries(openssl
  INTERFACE
    OpenSSL::Crypto
    OpenSSL::SSL)
