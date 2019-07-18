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

#ifndef DB2FileSystemSource_h__
#define DB2FileSystemSource_h__

#include "DB2FileLoader.h"
#include <string>

struct TC_COMMON_API DB2FileSystemSource : public DB2FileSource
{
    DB2FileSystemSource(std::string const& fileName);
    ~DB2FileSystemSource();
    bool IsOpen() const override;
    bool Read(void* buffer, std::size_t numBytes) override;
    std::size_t GetPosition() const override;
    bool SetPosition(std::size_t position) override;
    std::size_t GetFileSize() const override;
    char const* GetFileName() const override;

private:
    std::string _fileName;
    FILE* _file;
};

#endif // DB2FileSystemSource_h__
