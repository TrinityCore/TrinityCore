# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

set(MYSQL_MIN_VERSION_MySQL 8.0.34)
set(MYSQL_MIN_VERSION_MariaDB 10.6.3)
find_package(MySQL COMPONENTS lib)

add_library(mysql INTERFACE)

target_compile_definitions(mysql
  INTERFACE
    TRINITY_MYSQL_FLAVOR="${MYSQL_FLAVOR}"
    TRINITY_REQUIRED_MYSQL_VERSION="${MYSQL_MIN_VERSION_${MYSQL_FLAVOR}}")

target_link_libraries(mysql
  INTERFACE
    MySQL::MySQL)
