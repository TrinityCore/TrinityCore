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
 * asize_t with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Patcher.hpp"

namespace Connection_Patcher
{
    Patcher::Patcher(boost::filesystem::path file)
        : filePath(file)
    {
        ReadFile();
        binaryType = Helper::GetBinaryType(binary);
    }

    void Patcher::ReadFile()
    {
        std::ifstream ifs(filePath.string(), std::ifstream::binary);
        if (!ifs)
            throw std::runtime_error("could not open " + filePath.string());

        binary.clear();
        ifs >> std::noskipws;
        ifs.seekg(0, std::ios_base::end);
        binary.reserve(ifs.tellg());
        ifs.seekg(0, std::ios_base::beg);

        std::copy(std::istream_iterator<unsigned char>(ifs), std::istream_iterator<unsigned char>(), std::back_inserter(binary));
    }

    void Patcher::WriteFile(boost::filesystem::path const& path)
    {
        std::ofstream ofs(path.string(), std::ofstream::binary);
        if (!ofs)
            throw std::runtime_error("could not open " + path.string());

        ofs << std::noskipws;

        std::copy(binary.begin(), binary.end(), std::ostream_iterator<unsigned char>(ofs));
    }

    void Patcher::Patch(std::vector<unsigned char> const& bytes, std::vector<unsigned char> const& pattern)
    {
        if (binary.size() < pattern.size())
            throw std::logic_error("pattern larger than binary");

        if (pattern.empty())
            return;

        for (size_t const offset : Helper::SearchOffset(binary, pattern))
        {
            std::cout << "Found offset " << offset << std::endl;

            if (offset != 0 && binary.size() >= bytes.size())
                for (size_t i = 0; i < bytes.size(); i++)
                    binary[offset + i] = bytes[i];
        }
    }

    void Patcher::Finish(boost::filesystem::path out)
    {
        if (boost::filesystem::exists(out))
            boost::filesystem::remove(out);

        WriteFile(out);
    }
}
