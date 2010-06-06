#ifndef DBCFILE_H
#define DBCFILE_H
#define __STORMLIB_SELF__

#include <cassert>
#include <string>
//#include "StormLib.h"

#undef min
#undef max
class DBCFile
{
public:
    DBCFile(const std::string &filename);
    ~DBCFile();

    // Open database. It must be openened before it can be used.
    bool open();

    // TODO: Add a close function?

    // Database exceptions
    class Exception
    {
    public:
        Exception(const std::string &message): message(message)
        { }
        virtual ~Exception()
        { }
        const std::string &getMessage() {return message;}
    private:
        std::string message;
    };

    //
    class NotFound: public Exception
    {
    public:
        NotFound(): Exception("Key was not found")
        { }
    };

    // Iteration over database
    class Iterator;
    class Record
    {
    public:
        Record& operator= (const Record& r)
        {
            file = r.file;
            offset = r.offset;
            return *this;
        }
        float getFloat(size_t field) const
        {
            assert(field < file.fieldCount);
            return *reinterpret_cast<float*>(offset+field*4);
        }
        unsigned int getUInt(size_t field) const
        {
            assert(field < file.fieldCount);
            return *reinterpret_cast<unsigned int*>(offset+(field*4));
        }
        int getInt(size_t field) const
        {
            assert(field < file.fieldCount);
            return *reinterpret_cast<int*>(offset+field*4);
        }
        unsigned char getByte(size_t ofs) const
        {
            assert(ofs < file.recordSize);
            return *reinterpret_cast<unsigned char*>(offset+ofs);
        }
        const char *getString(size_t field) const
        {
            assert(field < file.fieldCount);
            size_t stringOffset = getUInt(field);
            assert(stringOffset < file.stringSize);
            //char * tmp = (char*)file.stringTable + stringOffset;
            //unsigned char * tmp2 = file.stringTable + stringOffset;
            return reinterpret_cast<char*>(file.stringTable + stringOffset);
        }
    private:
        Record(DBCFile &file, unsigned char *offset): file(file), offset(offset) {}
        DBCFile &file;
        unsigned char *offset;

        friend class DBCFile;
        friend class Iterator;
    };

    /* Iterator that iterates over records */
    class Iterator
    {
    public:
        Iterator(DBCFile &file, unsigned char *offset):
            record(file, offset) {}
        /// Advance (prefix only)
        Iterator & operator++() {
            record.offset += record.file.recordSize;
            return *this;
        }
        /// Return address of current instance
        Record const & operator*() const { return record; }
        const Record* operator->() const {
            return &record;
        }
        /// Comparison
        bool operator==(const Iterator &b) const
        {
            return record.offset == b.record.offset;
        }
        bool operator!=(const Iterator &b) const
        {
            return record.offset != b.record.offset;
        }
    private:
        Record record;
    };

    // Get record by id
    Record getRecord(size_t id);
    /// Get begin iterator over records
    Iterator begin();
    /// Get begin iterator over records
    Iterator end();
    /// Trivial
    size_t getRecordCount() const { return recordCount;}
    size_t getFieldCount() const { return fieldCount; }

private:
    std::string filename;
    size_t recordSize;
    size_t recordCount;
    size_t fieldCount;
    size_t stringSize;
    unsigned char *data;
    unsigned char *stringTable;
};

#endif
