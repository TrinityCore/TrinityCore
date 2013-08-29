#define _CRT_SECURE_NO_DEPRECATE

#include "dbcfile.h"

DBCFile::DBCFile(HANDLE file) :
    _file(file), _data(NULL), _stringTable(NULL)
{
}

bool DBCFile::open()
{
    char header[4];
    unsigned int na, nb, es, ss;

    DWORD readBytes = 0;
    SFileReadFile(_file, header, 4, &readBytes, NULL);
    if (readBytes != 4)                                         // Number of records
        return false;

    if (header[0] != 'W' || header[1] != 'D' || header[2] != 'B' || header[3] != 'C')
        return false;

    SFileReadFile(_file, &na, 4, &readBytes, NULL);
    if (readBytes != 4)                                         // Number of records
        return false;

    SFileReadFile(_file, &nb, 4, &readBytes, NULL);
    if (readBytes != 4)                                         // Number of fields
        return false;

    SFileReadFile(_file, &es, 4, &readBytes, NULL);
    if (readBytes != 4)                                         // Size of a record
        return false;

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
    SFileReadFile(_file, _data, data_size, &readBytes, NULL);
    if (readBytes != data_size)
        return false;

    return true;
}

DBCFile::~DBCFile()
{
    delete [] _data;
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

