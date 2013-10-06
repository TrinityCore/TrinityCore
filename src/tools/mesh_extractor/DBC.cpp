#include <cstdio>
#include "DBC.h"
#include "Define.h"

DBC::DBC(Stream* stream) : StringBlock(NULL), StringBlockSize(0), IsFaulty(true)
{
    stream->Read(4); // Read the magic "WDBC"

    RecordCount = stream->Read<int>();
    Records.reserve(RecordCount);
    Fields = stream->Read<int>();
    RecordSize = stream->Read<int>();
    StringBlockSize = stream->Read<uint32>();

    for (int i = 0; i < RecordCount; i++)
    {
        Record* rec = new Record(this);
        Records.push_back(rec);
        int size = 0;
        for (int f = 0; f < Fields; f++)
        {
            if (size + 4 > RecordSize)
            {
                IsFaulty = true;
                break;
            }
            rec->Values.push_back(stream->Read<uint32>());
            size += 4;
        }
    }
    StringBlock = (uint8*)stream->Read(StringBlockSize);
}

DBC::~DBC()
{
    delete[] StringBlock;
    for (std::vector<Record*>::iterator itr = Records.begin(); itr != Records.end(); ++itr)
        delete *itr;
}

std::string DBC::GetStringByOffset( int offset )
{
    int len = 0;
    for (uint32 i = offset; i < StringBlockSize; i++)
    {
        if (!StringBlock[i])
        {
            len = (i - offset);
            break;
        }
    }
    char* d = new char[len+1];
    strcpy(d, (const char*)(StringBlock + offset));
    d[len] = '\0';
    std::string val = std::string(d);
    delete[] d;
    return val;
}

Record* DBC::GetRecordById( int id )
{
    // we assume Id is index 0
    for (std::vector<Record*>::iterator itr = Records.begin(); itr != Records.end(); ++itr)
        if ((*itr)->Values[0] == id)
            return *itr;
    return NULL;
}
