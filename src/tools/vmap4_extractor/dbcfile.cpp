/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
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

#define _CRT_SECURE_NO_DEPRECATE

#include "dbcfile.h"

DBCFile::DBCFile(HANDLE mpq, const char* filename) :
    _mpq(mpq), _filename(filename), _file(NULL), _data(NULL), _stringTable(NULL)
{
}

bool DBCFile::open()
{
    if (!SFileOpenFileEx(_mpq, _filename, SFILE_OPEN_PATCHED_FILE, &_file))
        return false;

    char header[4];
    unsigned int na, nb, es, ss;

    DWORD readBytes = 0;
    SFileReadFile(_file, header, 4, &readBytes, NULL);
    if (readBytes != 4)                                         // Number of records
        return false;

    if (header[0] != 'W' || header[1] != 'D' || header[2] != 'B' || header[3] != 'C')
        return false;

    readBytes = 0;
    SFileReadFile(_file, &na, 4, &readBytes, NULL);
    if (readBytes != 4)                                         // Number of records
        return false;

    readBytes = 0;
    SFileReadFile(_file, &nb, 4, &readBytes, NULL);
    if (readBytes != 4)                                         // Number of fields
        return false;

    readBytes = 0;
    SFileReadFile(_file, &es, 4, &readBytes, NULL);
    if (readBytes != 4)                                         // Size of a record
        return false;

    readBytes = 0;
    SFileReadFile(_file, &ss, 4, &readBytes, NULL);
    if (readBytes != 4)                                         // String size
        return false;

    _recordSize = es;
    _recordCount = na;
    _fieldCount = nb;
    _stringSize = ss;
    if (_fieldCount * 4 != _recordSize)
        return false;

    _data = new unsigned char[_recordSize * _recordCount + _stringSize];
    _stringTable = _data + _recordSize*_recordCount;

    size_t data_size = _recordSize * _recordCount + _stringSize;
    readBytes = 0;
    SFileReadFile(_file, _data, data_size, &readBytes, NULL);
    if (readBytes != data_size)
        return false;

    return true;
}

DBCFile::~DBCFile()
{
    delete [] _data;
    if (_file != NULL)
        SFileCloseFile(_file);
}

DBCFile::Record DBCFile::getRecord(size_t id)
{
    assert(_data);
    return Record(*this, _data + id*_recordSize);
}

size_t DBCFile::getMaxId()
{
    assert(_data);

    size_t maxId = 0;
    for(size_t i = 0; i < getRecordCount(); ++i)
        if (maxId < getRecord(i).getUInt(0))
            maxId = getRecord(i).getUInt(0);

    return maxId;
}

DBCFile::Iterator DBCFile::begin()
{
    assert(_data);
    return Iterator(*this, _data);
}

DBCFile::Iterator DBCFile::end()
{
    assert(_data);
    return Iterator(*this, _stringTable);
}

