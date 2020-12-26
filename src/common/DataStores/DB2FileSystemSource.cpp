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

#include "DB2FileSystemSource.h"
#include <boost/filesystem/operations.hpp>

DB2FileSystemSource::DB2FileSystemSource(std::string const& fileName)
{
    _fileName = fileName;
    _file = fopen(_fileName.c_str(), "rb");
}

DB2FileSystemSource::~DB2FileSystemSource()
{
    if (_file)
        fclose(_file);
}

bool DB2FileSystemSource::IsOpen() const
{
    return _file != nullptr;
}

bool DB2FileSystemSource::Read(void* buffer, std::size_t numBytes)
{
    return fread(buffer, numBytes, 1, _file) == 1;
}

int64 DB2FileSystemSource::GetPosition() const
{
    return ftell(_file);
}

bool DB2FileSystemSource::SetPosition(int64 position)
{
    return fseek(_file, position, SEEK_SET) == 0;
}

int64 DB2FileSystemSource::GetFileSize() const
{
    boost::system::error_code error;
    int64 size = boost::filesystem::file_size(_fileName, error);
    return !error ? size : 0;
}

char const* DB2FileSystemSource::GetFileName() const
{
    return _fileName.c_str();
}

DB2EncryptedSectionHandling DB2FileSystemSource::HandleEncryptedSection(DB2SectionHeader const& /*sectionHeader*/) const
{
    return DB2EncryptedSectionHandling::Skip;
}
