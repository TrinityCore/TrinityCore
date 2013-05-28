#ifndef DBCFILE_H
#define DBCFILE_H
#include <cassert>
#include <string>
#include "StormLib.h"

class DBCFile
{
    public:
        DBCFile(HANDLE file);
        ~DBCFile();

        // Open database. It must be openened before it can be used.
        bool open();

        // Database exceptions
        class Exception
        {
            public:
                Exception(const std::string &message) : message(message) { }
                virtual ~Exception() { }
                const std::string &getMessage() { return message; }
            private:
                std::string message;
        };

        class NotFound: public Exception
        {
            public:
                NotFound(): Exception("Key was not found") { }
        };

        // Iteration over database
        class Iterator;
        class Record
        {
            public:
                float getFloat(size_t field) const
                {
                    assert(field < file._fieldCount);
                    return *reinterpret_cast<float*>(offset + field * 4);
                }

                unsigned int getUInt(size_t field) const
                {
                    assert(field < file._fieldCount);
                    return *reinterpret_cast<unsigned int*>(offset + field * 4);
                }

                int getInt(size_t field) const
                {
                    assert(field < file._fieldCount);
                    return *reinterpret_cast<int*>(offset + field * 4);
                }

                char const* getString(size_t field) const
                {
                    assert(field < file._fieldCount);
                    size_t stringOffset = getUInt(field);
                    assert(stringOffset < file._stringSize);
                    return reinterpret_cast<char*>(file._stringTable + stringOffset);
                }

            private:
                Record(DBCFile& file, unsigned char* offset): file(file), offset(offset) {}
                DBCFile& file;
                unsigned char* offset;

                friend class DBCFile;
                friend class DBCFile::Iterator;
        };
        /** Iterator that iterates over records
        */
        class Iterator
        {
            public:
                Iterator(DBCFile &file, unsigned char* offset) : record(file, offset) { }

                /// Advance (prefix only)
                Iterator& operator++()
                {
                    record.offset += record.file._recordSize;
                    return *this;
                }

                /// Return address of current instance
                Record const& operator*() const { return record; }
                Record const* operator->() const { return &record; }

                /// Comparison
                bool operator==(Iterator const& b) const
                {
                    return record.offset == b.record.offset;
                }

                bool operator!=(Iterator const& b) const
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
        size_t getRecordCount() const { return _recordCount; }
        size_t getFieldCount() const { return _fieldCount; }
        size_t getMaxId();

    private:
        HANDLE _file;
        size_t _recordSize;
        size_t _recordCount;
        size_t _fieldCount;
        size_t _stringSize;
        unsigned char* _data;
        unsigned char* _stringTable;
};

#endif
