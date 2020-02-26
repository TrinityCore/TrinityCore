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

#include "dbcfile.h"
#include "mpq_libmpq04.h"
#undef min
#undef max

#include <cstdio>

DBCFile::DBCFile(const std::string& filename):
    filename(filename), recordSize(0), recordCount(0), fieldCount(0), stringSize(0), data(nullptr), stringTable(nullptr)
{

}

bool DBCFile::open()
{
    MPQFile f(filename.c_str());

    // Need some error checking, otherwise an unhandled exception error occurs
    // if people screw with the data path.
    if (f.isEof() == true)
        return false;

    unsigned char header[4];
    unsigned int na,nb,es,ss;

    f.read(header,4); // File Header

    if (header[0]!='W' || header[1]!='D' || header[2]!='B' || header[3] != 'C')
    {
        f.close();
        data = nullptr;
        printf("Critical Error: An error occured while trying to read the DBCFile %s.", filename.c_str());
        return false;
    }

    //assert(header[0]=='W' && header[1]=='D' && header[2]=='B' && header[3] == 'C');

    f.read(&na,4); // Number of records
    f.read(&nb,4); // Number of fields
    f.read(&es,4); // Size of a record
    f.read(&ss,4); // String size

    recordSize = es;
    recordCount = na;
    fieldCount = nb;
    stringSize = ss;
    //assert(fieldCount*4 == recordSize);
    assert(fieldCount*4 >= recordSize);

    data = new unsigned char[recordSize*recordCount+stringSize];
    stringTable = data + recordSize*recordCount;
    f.read(data,recordSize*recordCount+stringSize);
    f.close();
    return true;
}

DBCFile::~DBCFile()
{
    delete [] data;
}

DBCFile::Record DBCFile::getRecord(size_t id)
{
    assert(data);
    return Record(*this, data + id*recordSize);
}

DBCFile::Iterator DBCFile::begin()
{
    assert(data);
    return Iterator(*this, data);
}

DBCFile::Iterator DBCFile::end()
{
    assert(data);
    return Iterator(*this, stringTable);
}
