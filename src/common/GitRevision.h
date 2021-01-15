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

#ifndef __GITREVISION_H__
#define __GITREVISION_H__

#include "Define.h"

namespace GitRevision
{
    TC_COMMON_API char const* GetHash();
    TC_COMMON_API char const* GetDate();
    TC_COMMON_API char const* GetBranch();
    TC_COMMON_API char const* GetCMakeCommand();
    TC_COMMON_API char const* GetCMakeVersion();
    TC_COMMON_API char const* GetHostOSVersion();
    TC_COMMON_API char const* GetBuildDirectory();
    TC_COMMON_API char const* GetSourceDirectory();
    TC_COMMON_API char const* GetMySQLExecutable();
    TC_COMMON_API char const* GetFullDatabase();
    TC_COMMON_API char const* GetHotfixesDatabase();
    TC_COMMON_API char const* GetFullVersion();
    TC_COMMON_API char const* GetCompanyNameStr();
    TC_COMMON_API char const* GetLegalCopyrightStr();
    TC_COMMON_API char const* GetFileVersionStr();
    TC_COMMON_API char const* GetProductVersionStr();
}

#endif
