/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "DB2.h"
#include <cassert>

DB2FileLoader::DB2FileLoader()
{
    meta = nullptr;

    recordSize = 0;
    recordCount = 0;
    fieldCount = 0;
    stringSize = 0;
    tableHash = 0;
    layoutHash = 0;
    minIndex = 0;
    maxIndex = 0;
    localeMask = 0;
    copyIdSize = 0;

    data = nullptr;
    stringTable = nullptr;
    idTable = nullptr;
    idTableSize = 0;
    copyTable = nullptr;
    fields = nullptr;
}

bool DB2FileLoader::Load(HANDLE db2Handle, DB2Meta const* meta)
{
    if (data)
    {
        delete[] data;
        data = nullptr;
    }

    DWORD bytesRead = 0;
    this->meta = meta;
    std::uint32_t header;
    CascReadFile(db2Handle, &header, sizeof(header), &bytesRead);
    if (bytesRead != sizeof(header))                        // Signature
        return false;

    EndianConvert(header);

    if (header != 0x35424457)
        return false;                                       //'WDB5'

    CascReadFile(db2Handle, &recordCount, sizeof(recordCount), &bytesRead);
    if (bytesRead != sizeof(recordCount))                   // Number of records
        return false;

    EndianConvert(recordCount);

    CascReadFile(db2Handle, &fieldCount, sizeof(fieldCount), &bytesRead);
    if (bytesRead != sizeof(fieldCount))                    // Number of fields
        return false;

    EndianConvert(fieldCount);

    CascReadFile(db2Handle, &recordSize, sizeof(recordSize), &bytesRead);
    if (bytesRead != sizeof(recordSize))                    // Size of a record
        return false;

    EndianConvert(recordSize);

    CascReadFile(db2Handle, &stringSize, sizeof(stringSize), &bytesRead);
    if (bytesRead != sizeof(stringSize))                    // String size
        return false;

    EndianConvert(stringSize);

    CascReadFile(db2Handle, &tableHash, sizeof(tableHash), &bytesRead);
    if (bytesRead != sizeof(tableHash))                     // Table hash
        return false;

    EndianConvert(tableHash);

    CascReadFile(db2Handle, &layoutHash, sizeof(layoutHash), &bytesRead);
    if (bytesRead != sizeof(layoutHash))                    // Layout hash
        return false;

    if (layoutHash != meta->LayoutHash)
        return false;

    EndianConvert(layoutHash);

    CascReadFile(db2Handle, &minIndex, sizeof(minIndex), &bytesRead);
    if (bytesRead != sizeof(minIndex))                      // MinIndex WDB2
        return false;

    EndianConvert(minIndex);

    CascReadFile(db2Handle, &maxIndex, sizeof(maxIndex), &bytesRead);
    if (bytesRead != sizeof(maxIndex))                      // MaxIndex WDB2
        return false;

    EndianConvert(maxIndex);

    CascReadFile(db2Handle, &localeMask, sizeof(localeMask), &bytesRead);
    if (bytesRead != sizeof(localeMask))                    // Locales
        return false;

    EndianConvert(localeMask);

    CascReadFile(db2Handle, &copyIdSize, sizeof(copyIdSize), &bytesRead);
    if (bytesRead != sizeof(copyIdSize))
        return false;

    EndianConvert(copyIdSize);

    CascReadFile(db2Handle, &metaFlags, sizeof(metaFlags), &bytesRead);
    if (bytesRead != sizeof(metaFlags))
        return false;

    EndianConvert(metaFlags);

    ASSERT((metaFlags & 0x1) == 0);
    ASSERT((meta->IndexField == -1) || (meta->IndexField == (metaFlags >> 16)));

    fields = new FieldEntry[fieldCount];
    CascReadFile(db2Handle, fields, fieldCount * sizeof(FieldEntry), &bytesRead);
    if (bytesRead != fieldCount * sizeof(FieldEntry))
        return false;

    if (!meta->HasIndexFieldInData())
        idTableSize = recordCount * sizeof(std::uint32_t);

    data = new unsigned char[recordSize * recordCount + stringSize];
    stringTable = data + recordSize * recordCount;

    CascReadFile(db2Handle, data, recordSize * recordCount + stringSize, &bytesRead);
    if (bytesRead != recordSize * recordCount + stringSize)
        return false;

    if (idTableSize)
    {
        idTable = new unsigned char[idTableSize];
        CascReadFile(db2Handle, idTable, idTableSize, &bytesRead);
        if (bytesRead != idTableSize)
            return false;
    }

    if (copyIdSize)
    {
        copyTable = new unsigned char[copyIdSize];
        CascReadFile(db2Handle, copyTable, copyIdSize, &bytesRead);
        if (bytesRead != copyIdSize)
            return false;
    }

    return true;
}

DB2FileLoader::~DB2FileLoader()
{
    delete[] data;
    delete[] idTable;
    delete[] copyTable;
    delete[] fields;
}

DB2FileLoader::Record DB2FileLoader::getRecord(size_t id)
{
    assert(data);
    return Record(*this, data + id * recordSize);
}

std::pair<std::uint32_t, std::uint32_t> DB2FileLoader::GetRowCopy(std::uint32_t i) const
{
    std::uint32_t* copyIds = (std::uint32_t*)copyTable;
    std::uint32_t to = copyIds[i];
    std::uint32_t from = copyIds[i + 1];
    return{ from, to };
}

std::uint32_t DB2FileLoader::GetMaxId() const
{
    std::uint32_t j = maxIndex;
    for (std::uint32_t i = 0; i < GetNumRowCopies(); ++i)
        if (j < GetRowCopy(i).second)
            j = GetRowCopy(i).second;

    return j;
}
