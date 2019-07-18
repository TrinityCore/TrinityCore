/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

std::size_t DB2FileSystemSource::GetPosition() const
{
    return ftell(_file);
}

bool DB2FileSystemSource::SetPosition(std::size_t position)
{
    return fseek(_file, position, SEEK_SET) == 0;
}

std::size_t DB2FileSystemSource::GetFileSize() const
{
    boost::system::error_code error;
    std::size_t size = boost::filesystem::file_size(_fileName, error);
    return !error ? size : 0;
}

char const* DB2FileSystemSource::GetFileName() const
{
    return _fileName.c_str();
}
