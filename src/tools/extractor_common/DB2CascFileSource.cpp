/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "DB2CascFileSource.h"
#include <CascLib.h>

DB2CascFileSource::DB2CascFileSource(CASC::StorageHandle const& storage, std::string fileName)
{
    _fileHandle = CASC::OpenFile(storage, fileName.c_str(), CASC_LOCALE_NONE, true);
    _fileName = std::move(fileName);
}

bool DB2CascFileSource::IsOpen() const
{
    return _fileHandle != nullptr;
}

bool DB2CascFileSource::Read(void* buffer, std::size_t numBytes)
{
    DWORD bytesRead = 0;
    return CASC::ReadFile(_fileHandle, buffer, numBytes, &bytesRead) && numBytes == bytesRead;
}

std::size_t DB2CascFileSource::GetPosition() const
{
    return CASC::GetFilePointer(_fileHandle);
}

char const* DB2CascFileSource::GetFileName() const
{
    return _fileName.c_str();
}
