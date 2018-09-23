#ifndef TRINITY_DBEDIT_GLOBALDBCSTORES_H
#define TRINITY_DBEDIT_GLOBALDBCSTORES_H

#include "DBCStore.h"
#include "Errors.h"
#include "IteratorPair.h"

std::string dbcdir();
template <typename DBCEntry, bool fromDB>
struct GlobalDBCStore
{
    public:
        using iterator = typename DBCStorage<DBCEntry>::iterator;
        static auto LookupEntry(uint32 id) { return _storage_ptr()->LookupEntry(id); }
        static auto GetNumRows() { return _storage_ptr()->GetNumRows(); }
        static auto begin() { return _storage_ptr()->begin(); }
        static auto end() { return _storage_ptr()->end(); }
        static Trinity::IteratorPair<iterator> iterate() { return { begin(), end() }; };

        template <bool DB = fromDB>
        static std::enable_if_t<DB, bool> Save(char const* dbtable, char const* customFormat, char const* customIndexName, uint32 indexValue, DBCEntry* entry)
        {
            return _storage()->SaveToDB(dbtable, customFormat, customIndexName, indexValue, entry);
        }
    private:
        template <bool DB = fromDB>
        static std::enable_if_t<DB, bool> Load(char const* dbtable, char const* format, char const* customFormat, char const* customIndex)
        {
            _storage() = std::make_unique<DBCStorage<DBCEntry>>(format);
            _storage()->LoadFromDB(dbtable, customFormat, customIndex);
            return true;
        }
        template <bool DB = fromDB>
        static std::enable_if_t<!DB, bool> Load(char const* filename, char const* format)
        {
            _storage() = std::make_unique<DBCStorage<DBCEntry>>(format);
            return _storage()->Load((dbcdir() + filename).c_str());
        }
        static DBCStorage<DBCEntry>* _storage_ptr()
        {
            auto ptr = _storage().get();
            ASSERT(ptr, "DBC storage not loaded for this type!");
            return ptr;
        }
        static std::unique_ptr<DBCStorage<DBCEntry>>& _storage()
        {
            static std::unique_ptr<DBCStorage<DBCEntry>> ptr;
            return ptr;
        }

    friend struct DBCLoads;
};

template <typename DBCEntry>
using StaticDBCStore = GlobalDBCStore<DBCEntry, false>;

template <typename DBCEntry>
using DatabaseDBCStore = GlobalDBCStore<DBCEntry, true>;

#endif
