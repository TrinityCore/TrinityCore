/*
 * Copyright (C) 2012-2014 Arctium Emulation <http://arctium.org>
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Helper.hpp"
#include "Patterns/Common.hpp"

namespace Connection_Patcher
{
    namespace Helper
    {
        // adapted from http://stackoverflow.com/questions/8593608/how-can-i-copy-a-directory-using-boost-filesystem
        void CopyDir(boost::filesystem::path const & source, boost::filesystem::path const & destination)
        {
            namespace fs = boost::filesystem;
            if (!fs::exists(source) || !fs::is_directory(source))
                throw std::invalid_argument("Source directory " + source.string() + " does not exist or is not a directory.");

            if (fs::exists(destination))
                throw std::invalid_argument("Destination directory " + destination.string() + " already exists.");

            if (!fs::create_directory(destination))
                throw std::runtime_error("Unable to create destination directory" + destination.string());

            for (fs::directory_iterator file(source); file != fs::directory_iterator(); ++file)
            {
                fs::path current(file->path());
                if (fs::is_directory(current))
                    CopyDir(current, destination / current.filename());
                else
                    fs::copy_file(current, destination / current.filename());
            }
        }

        Constants::BinaryTypes GetBinaryType(std::vector<unsigned char> const& data)
        {
            // Check MS-DOS magic
            if (*reinterpret_cast<uint16_t const*>(data.data()) == 0x5A4D)
            {
                uint32_t const peOffset(*reinterpret_cast<uint32_t const*>(data.data() + 0x3C));

                // Check PE magic
                if (*reinterpret_cast<uint32_t const*>(data.data() + peOffset) != 0x4550)
                    throw std::invalid_argument("Not a PE file!");

                return Constants::BinaryTypes(*reinterpret_cast<uint16_t const*>(data.data() + peOffset + 4));
            }
            else
                return Constants::BinaryTypes(*reinterpret_cast<uint32_t const*>(data.data()));
        }

        std::set<size_t> SearchOffset(std::vector<unsigned char> const& binary, std::vector<unsigned char> const& pattern)
        {
            std::set<size_t> offsets;
            for (size_t i = 0; (i + pattern.size()) < binary.size(); i++)
            {
                size_t matches = 0;

                for (size_t j = 0; j < pattern.size(); j++)
                {
                    if (binary[i + j] != pattern[j])
                        break;

                    matches++;
                }

                if (matches == pattern.size())
                {
                    offsets.insert(i);
                    i += matches;
                }
            }

            return offsets.empty() ? throw std::runtime_error("unable to find pattern") : offsets;
        }

        uint32_t GetBuildNumber(std::vector<unsigned char> const& binary)
        {
            std::set<size_t> offsets = SearchOffset(binary, Patterns::Common::BinaryVersion());

            if (!offsets.empty())
            {
                size_t const verOffset = (*offsets.begin());
                std::string ver(&binary[verOffset + 16], &binary[verOffset + 21]);

                return std::stoi(ver);
            }
            return 0;
        }
    }
}
