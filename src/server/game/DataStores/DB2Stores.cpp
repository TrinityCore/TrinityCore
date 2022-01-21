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

#include "Common.h"
#include "DatabaseEnv.h"
#include "DBCStores.h"
#include "DB2Stores.h"
#include "DB2fmt.h"
#include "Errors.h"
#include "HotfixDatabase.h"
#include "Log.h"
#include "World.h"

#include <sstream>

DB2Storage<ItemEntry>               sItemStore("Item.db2", Itemfmt, HOTFIX_SEL_ITEM);
DB2Storage<ItemCurrencyCostEntry>   sItemCurrencyCostStore("ItemCurrencyCost.db2", ItemCurrencyCostfmt, HOTFIX_SEL_ITEM_CURRENCY_COST);
DB2Storage<ItemExtendedCostEntry>   sItemExtendedCostStore("ItemExtendedCost.db2", ItemExtendedCostEntryfmt, HOTFIX_SEL_ITEM_EXTENDED_COST);
DB2Storage<ItemSparseEntry>         sItemSparseStore("Item-sparse.db2", ItemSparsefmt, HOTFIX_SEL_ITEM_SPARSE);
DB2Storage<KeyChainEntry>           sKeyChainStore("KeyChain.db2", KeyChainfmt, HOTFIX_SEL_KEY_CHAIN);

typedef std::list<std::string> DB2StoreProblemList;

DB2Manager& DB2Manager::Instance()
{
    static DB2Manager instance;
    return instance;
}

uint32 DB2FilesCount = 0;

template<class T>
inline void LoadDB2(uint32& availableDb2Locales, DB2StoreProblemList& errlist, DB2Manager::StorageMap& stores, DB2Storage<T>* storage, std::string const& db2Path, uint32 defaultLocale)
{
    // compatibility format and C++ structure sizes
    ASSERT(DB2FileLoader::GetFormatRecordSize(storage->GetFormat()) == sizeof(T),
        "Size of '%s' set by format string (%u) not equal size of C++ structure (" SZFMTD ").",
        storage->GetFileName().c_str(), DB2FileLoader::GetFormatRecordSize(storage->GetFormat()), sizeof(T));

    ++DB2FilesCount;

    if (storage->Load(db2Path + localeNames[defaultLocale] + '/', defaultLocale))
    {
        storage->LoadFromDB();
        // LoadFromDB() always loads strings into enUS locale, other locales are expected to have data in corresponding _locale tables
        // so we need to make additional call to load that data in case said locale is set as default by worldserver.conf (and we do not want to load all this data from .db2 file again)
        if (defaultLocale != LOCALE_enUS)
            storage->LoadStringsFromDB(LocaleConstant(defaultLocale));

        for (uint32 i = 0; i < TOTAL_LOCALES; ++i)
        {
            if (defaultLocale == i || i == LOCALE_NONE)
                continue;

            if (availableDb2Locales & (1 << i))
                if (!storage->LoadStringsFrom((db2Path + localeNames[i] + '/'), i))
                    availableDb2Locales &= ~(1 << i);             // mark as not available for speedup next checks

            storage->LoadStringsFromDB(LocaleConstant(i));
        }
    }
    else
    {
        // sort problematic db2 to (1) non compatible and (2) nonexistent
        if (FILE* f = fopen((db2Path + storage->GetFileName()).c_str(), "rb"))
        {
            std::ostringstream stream;
            stream << storage->GetFileName() << " exists, and has " << storage->GetFieldCount() << " field(s) (expected " << strlen(storage->GetFormat())
                << "). Extracted file might be from wrong client version.";
            std::string buf = stream.str();
            errlist.push_back(buf);
            fclose(f);
        }
        else
            errlist.push_back(storage->GetFileName());
    }

    stores[storage->GetHash()] = storage;
}

uint32 DB2Manager::LoadStores(std::string const& dataPath, uint32 defaultLocale)
{
    uint32 oldMSTime = getMSTime();

    std::string db2Path = dataPath + "dbc/";

    DB2StoreProblemList bad_db2_files;
    uint32 availableDb2Locales = 0xFFFFFFFF;

    LoadDB2(availableDb2Locales, bad_db2_files, _stores, &sItemStore,                db2Path, defaultLocale);
    LoadDB2(availableDb2Locales, bad_db2_files, _stores, &sItemCurrencyCostStore,    db2Path, defaultLocale);
    LoadDB2(availableDb2Locales, bad_db2_files, _stores, &sItemSparseStore,          db2Path, defaultLocale);
    LoadDB2(availableDb2Locales, bad_db2_files, _stores, &sItemExtendedCostStore,    db2Path, defaultLocale);
    LoadDB2(availableDb2Locales, bad_db2_files, _stores, &sKeyChainStore,            db2Path, defaultLocale);

    // error checks
    if (bad_db2_files.size() >= DB2FilesCount)
    {
        TC_LOG_ERROR("misc", "\nIncorrect DataDir value in worldserver.conf or ALL required *.db2 files (%d) not found by path: %sdbc/%s/", DB2FilesCount, dataPath.c_str(), localeNames[defaultLocale]);
        exit(1);
    }
    else if (!bad_db2_files.empty())
    {
        std::string str;
        for (std::list<std::string>::iterator i = bad_db2_files.begin(); i != bad_db2_files.end(); ++i)
            str += *i + "\n";

        TC_LOG_ERROR("misc", "\nSome required *.db2 files (%u from %d) not found or not compatible:\n%s", (uint32)bad_db2_files.size(), DB2FilesCount, str.c_str());
        exit(1);
    }

    // Check loaded DB2 files proper version
    if (!sItemStore.LookupEntry(83086)             ||       // last item added in 4.3.4 (15595)
        !sItemExtendedCostStore.LookupEntry(3872)  )        // last item extended cost added in 4.3.4 (15595)
    {
        TC_LOG_ERROR("misc", "Please extract correct db2 files from client 4.3.4 15595.");
        exit(1);
    }

    TC_LOG_INFO("server.loading", ">> Initialized %d DB2 data stores in %u ms", DB2FilesCount, GetMSTimeDiffToNow(oldMSTime));

    return availableDb2Locales;
}

DB2StorageBase const* DB2Manager::GetStorage(uint32 type) const
{
    StorageMap::const_iterator itr = _stores.find(type);
    if (itr != _stores.end())
        return itr->second;

    return nullptr;
}

void DB2Manager::LoadHotfixData()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = HotfixDatabase.Query("SELECT TableHash, RecordID, Deleted FROM hotfix_data");

    if (!result)
    {
        TC_LOG_INFO("misc", ">> Loaded 0 hotfix info entries.");
        return;
    }

    uint32 count = 0;

    _hotfixData.reserve(result->GetRowCount());

    do
    {
        Field* fields = result->Fetch();

        HotfixNotify info;
        info.TableHash = fields[0].GetUInt32();
        info.Entry = fields[1].GetUInt32();
        _hotfixData.push_back(info);

        if (fields[2].GetBool())
        {
            auto itr = _stores.find(info.TableHash);
            if (itr != _stores.end())
                itr->second->EraseRecord(info.Entry);
        }

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("misc", ">> Loaded %u hotfix info entries in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}
