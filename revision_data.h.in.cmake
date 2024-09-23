/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TRINITYCORE_REVISION_DATA_H
#define TRINITYCORE_REVISION_DATA_H

// Git commit information
#define TRINITY_GIT_COMMIT_HASH     "@rev_hash@"
#define TRINITY_GIT_COMMIT_DATE     "@rev_date@"
#define TRINITY_GIT_COMMIT_BRANCH   R"(@rev_branch@)"

// Build OS information
#define TRINITY_BUILD_HOST_SYSTEM                   R"(@TRINITY_BUILD_HOST_SYSTEM@)"
#define TRINITY_BUILD_HOST_SYSTEM_VERSION           R"(@TRINITY_BUILD_HOST_SYSTEM_RELEASE@)"
#cmakedefine TRINITY_BUILD_HOST_DISTRO_NAME              R"(@TRINITY_BUILD_HOST_DISTRO_NAME@)"
#cmakedefine TRINITY_BUILD_HOST_DISTRO_VERSION_ID        R"(@TRINITY_BUILD_HOST_DISTRO_VERSION_ID@)"

// Build target information
#define TRINITY_BUILD_PROCESSOR     R"(@CMAKE_SYSTEM_PROCESSOR@)"

// CMake build information
#define TRINITY_BUILD_CMAKE_COMMAND             R"(@CMAKE_COMMAND@)"
#define TRINITY_BUILD_CMAKE_VERSION             R"(@CMAKE_VERSION@)"
#define TRINITY_BUILD_CMAKE_SOURCE_DIRECTORY    R"(@CMAKE_SOURCE_DIR@)"
#define TRINITY_BUILD_CMAKE_BUILD_DIRECTORY     R"(@BUILDDIR@)"

// Database updater base information
#define DATABASE_MYSQL_EXECUTABLE   R"(@MYSQL_EXECUTABLE@)"
#define DATABASE_FULL_DATABASE      "TDB_full_world_1102.24092_2024_09_23.sql"
#define DATABASE_HOTFIXES_DATABASE  "TDB_full_hotfixes_1102.24092_2024_09_23.sql"

// Windows resource defines
#define VER_COMPANYNAME_STR         "TrinityCore Developers"
#define VER_LEGALCOPYRIGHT_STR      "(c)2008-@rev_year@ TrinityCore"
#define VER_FILEVERSION             0,0,0
#define VER_FILEVERSION_STR         "@rev_hash@ @rev_date@ (@rev_branch@ branch)"
#define VER_PRODUCTVERSION          VER_FILEVERSION
#define VER_PRODUCTVERSION_STR      VER_FILEVERSION_STR

#endif // TRINITYCORE_REVISION_DATA_H
