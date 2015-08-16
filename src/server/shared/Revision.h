/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#ifndef __REVISION_H__
#define __REVISION_H__

#include <string>

namespace Revision
{
    std::string GetPackageName();
    std::string GetHash();
    std::string GetDate();
    std::string GetBranch();
    std::string GetSourceDirectory();
    std::string GetMySQLExecutable();
    std::string GetFullDatabase();
    std::string GetFullVersion();
    std::string GetCompanyNameStr();
    std::string GetLegalCopyrightStr();
    std::string GetFileVersionStr();
    std::string GetProductVersionStr();
}

#endif
