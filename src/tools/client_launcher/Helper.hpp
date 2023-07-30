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

#ifndef Helper_h__
#define Helper_h__

#include <vector>
#include <string>
#include <boost/filesystem.hpp>

namespace ClientLauncher
{
    namespace Helper
    {
        std::string GetFileChecksum(std::vector<unsigned char> const& data);
        std::vector<unsigned char> ReadFile(boost::filesystem::path const& path);
        void GetFile(std::string const& url, std::ostream& out);
        bool VerifyRequirements(const boost::filesystem::path& commonAppData);
    }
}

#endif // Helper_h__
