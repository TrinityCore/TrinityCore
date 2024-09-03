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

#include "GitRevision.h"
#include "revision_data.h"

char const* GitRevision::GetHash()
{
    return TRINITY_GIT_COMMIT_HASH;
}

char const* GitRevision::GetDate()
{
    return TRINITY_GIT_COMMIT_DATE;
}

char const* GitRevision::GetBranch()
{
    return TRINITY_GIT_COMMIT_BRANCH;
}

char const* GitRevision::GetCMakeCommand()
{
    return TRINITY_BUILD_CMAKE_COMMAND;
}

char const* GitRevision::GetCMakeVersion()
{
    return TRINITY_BUILD_CMAKE_VERSION;
}

char const* GitRevision::GetHostOSVersion()
{
    return
#ifdef TRINITY_BUILD_HOST_DISTRO_NAME
        TRINITY_BUILD_HOST_DISTRO_NAME " " TRINITY_BUILD_HOST_DISTRO_VERSION_ID "; "
#endif
        TRINITY_BUILD_HOST_SYSTEM " " TRINITY_BUILD_HOST_SYSTEM_VERSION
    ;
}

char const* GitRevision::GetBuildDirectory()
{
    return TRINITY_BUILD_CMAKE_BUILD_DIRECTORY;
}

char const* GitRevision::GetSourceDirectory()
{
    return TRINITY_BUILD_CMAKE_SOURCE_DIRECTORY;
}

char const* GitRevision::GetMySQLExecutable()
{
    return DATABASE_MYSQL_EXECUTABLE;
}

char const* GitRevision::GetFullDatabase()
{
    return DATABASE_FULL_DATABASE;
}

char const* GitRevision::GetHotfixesDatabase()
{
    return DATABASE_HOTFIXES_DATABASE;
}

#ifndef TRINITY_API_USE_DYNAMIC_LINKING
#  define TRINITY_LINKAGE_TYPE_STR "Static"
#else
#  define TRINITY_LINKAGE_TYPE_STR "Dynamic"
#endif

char const* GitRevision::GetFullVersion()
{
  return "TrinityCore rev. " VER_PRODUCTVERSION_STR
    " (" TRINITY_BUILD_HOST_SYSTEM ", " TRINITY_BUILD_PROCESSOR  ", " _BUILD_DIRECTIVE ", " TRINITY_LINKAGE_TYPE_STR ")";
}

char const* GitRevision::GetCompanyNameStr()
{
    return VER_COMPANYNAME_STR;
}

char const* GitRevision::GetLegalCopyrightStr()
{
    return VER_LEGALCOPYRIGHT_STR;
}

char const* GitRevision::GetFileVersionStr()
{
    return VER_FILEVERSION_STR;
}

char const* GitRevision::GetProductVersionStr()
{
    return VER_PRODUCTVERSION_STR;
}
