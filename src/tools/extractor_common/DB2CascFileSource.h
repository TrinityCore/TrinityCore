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

#ifndef DB2CascFileSource_h__
#define DB2CascFileSource_h__

#include "DB2FileLoader.h"
#include "CascHandles.h"
#include <string>

struct DB2CascFileSource : public DB2FileSource
{
    DB2CascFileSource(CASC::StorageHandle const& storage, std::string fileName);
    bool IsOpen() const override;
    bool Read(void* buffer, std::size_t numBytes) override;
    std::size_t GetPosition() const override;
    bool SetPosition(std::size_t position) override;
    std::size_t GetFileSize() const override;
    char const* GetFileName() const override;

private:
    CASC::FileHandle _fileHandle;
    std::string _fileName;
};

#endif // DB2CascFile_h__
