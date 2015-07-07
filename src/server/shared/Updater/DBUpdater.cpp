/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#include "DBUpdater.h"
#include "Log.h"
#include "revision.h"
#include "UpdateFetcher.h"
#include "DatabaseLoader.h"
#include "Config.h"

#include <fstream>
#include <iostream>
#include <unordered_map>
#include <boost/process.hpp>
#include <boost/iostreams/device/file_descriptor.hpp>
#include <boost/system/system_error.hpp>

using namespace boost::process;
using namespace boost::process::initializers;
using namespace boost::iostreams;

template<class T>
std::string DBUpdater<T>::GetSourceDirectory()
{
    std::string const entry = sConfigMgr->GetStringDefault("Updates.SourcePath", "");
    if (!entry.empty())
        return entry;
    else
        return _SOURCE_DIRECTORY;
}

template<class T>
std::string DBUpdater<T>::GetMySqlCli()
{
    std::string const entry = sConfigMgr->GetStringDefault("Updates.MySqlCLIPath", "");
    if (!entry.empty())
        return entry;
    else
        return _MYSQL_EXECUTABLE;
}

// Auth Database
template<>
std::string DBUpdater<LoginDatabaseConnection>::GetConfigEntry()
{
    return "Updates.Auth";
}

template<>
std::string DBUpdater<LoginDatabaseConnection>::GetTableName()
{
    return "Auth";
}

template<>
std::string DBUpdater<LoginDatabaseConnection>::GetBaseFile()
{
    return DBUpdater<LoginDatabaseConnection>::GetSourceDirectory() + "/sql/base/auth_database.sql";
}

template<>
bool DBUpdater<LoginDatabaseConnection>::IsEnabled(uint32 const updateMask)
{
    // This way silences warnings under msvc
    return (updateMask & DatabaseLoader::DATABASE_LOGIN) ? true : false;
}

// World Database
template<>
std::string DBUpdater<WorldDatabaseConnection>::GetConfigEntry()
{
    return "Updates.World";
}

template<>
std::string DBUpdater<WorldDatabaseConnection>::GetTableName()
{
    return "World";
}

template<>
std::string DBUpdater<WorldDatabaseConnection>::GetBaseFile()
{
    return _FULL_DATABASE;
}

template<>
bool DBUpdater<WorldDatabaseConnection>::IsEnabled(uint32 const updateMask)
{
    // This way silences warnings under msvc
    return (updateMask & DatabaseLoader::DATABASE_WORLD) ? true : false;
}

template<>
BaseLocation DBUpdater<WorldDatabaseConnection>::GetBaseLocationType()
{
    return LOCATION_DOWNLOAD;
}

// Character Database
template<>
std::string DBUpdater<CharacterDatabaseConnection>::GetConfigEntry()
{
    return "Updates.Character";
}

template<>
std::string DBUpdater<CharacterDatabaseConnection>::GetTableName()
{
    return "Character";
}

template<>
std::string DBUpdater<CharacterDatabaseConnection>::GetBaseFile()
{
    return DBUpdater<CharacterDatabaseConnection>::GetSourceDirectory() + "/sql/base/characters_database.sql";
}

template<>
bool DBUpdater<CharacterDatabaseConnection>::IsEnabled(uint32 const updateMask)
{
    // This way silences warnings under msvc
    return (updateMask & DatabaseLoader::DATABASE_CHARACTER) ? true : false;
}

// All
template<class T>
BaseLocation DBUpdater<T>::GetBaseLocationType()
{
    return LOCATION_REPOSITORY;
}

template<class T>
bool DBUpdater<T>::CheckExecutable()
{
    DBUpdater<T>::Path const exe(DBUpdater<T>::GetMySqlCli());
    if (!exists(exe))
    {
        // Check for mysql in path
        std::vector<std::string> args = {"--version"};
        uint32 ret;
        try
        {
            child c = execute(run_exe("mysql"), set_args(args), throw_on_error(), close_stdout());
            ret = wait_for_exit(c);
        }
        catch (boost::system::system_error&)
        {
            ret = EXIT_FAILURE;
        }

        if (ret == EXIT_FAILURE)
        {
            TC_LOG_FATAL("sql.updates", "Didn't find executeable mysql binary at \'%s\', correct the path in the *.conf (\"Updates.MySqlCLIPath\").",
                absolute(exe).generic_string().c_str());

            return false;
        }
    }
    return true;
}

template<class T>
bool DBUpdater<T>::Create(DatabaseWorkerPool<T>& pool)
{
    TC_LOG_INFO("sql.updates", "Database \"%s\" does not exist, do you want to create it? [yes (default) / no]: ",
        pool.GetConnectionInfo()->database.c_str());

    std::string answer;
    std::getline(std::cin, answer);
    if (!answer.empty() && !(answer.substr(0, 1) == "y"))
        return false;

    TC_LOG_INFO("sql.updates", "Creating database \"%s\"...", pool.GetConnectionInfo()->database.c_str());

    // Path of temp file
    static Path const temp("create_table.sql");

    // Create temporary query to use external mysql cli
    std::ofstream file(temp.generic_string());
    if (!file.is_open())
    {
        TC_LOG_FATAL("sql.updates", "Failed to create temporary query file \"%s\"!", temp.generic_string().c_str());
        return false;
    }

    file << "CREATE DATABASE `" << pool.GetConnectionInfo()->database << "` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci\n\n";

    file.close();

    try
    {
        DBUpdater<T>::ApplyFile(pool, pool.GetConnectionInfo()->host, pool.GetConnectionInfo()->user, pool.GetConnectionInfo()->password,
            pool.GetConnectionInfo()->port_or_socket, "", temp);
    }
    catch (UpdateException&)
    {
        TC_LOG_FATAL("sql.updates", "Failed to create database %s! Has the user `CREATE` priviliges?", pool.GetConnectionInfo()->database.c_str());
        boost::filesystem::remove(temp);
        return false;
    }

    TC_LOG_INFO("sql.updates", "Done.");
    boost::filesystem::remove(temp);
    return true;
}

template<class T>
bool DBUpdater<T>::Update(DatabaseWorkerPool<T>& pool)
{
    if (!DBUpdater<T>::CheckExecutable())
        return false;

    TC_LOG_INFO("sql.updates", "Updating %s database...", DBUpdater<T>::GetTableName().c_str());

    Path const sourceDirectory(GetSourceDirectory());

    if (!is_directory(sourceDirectory))
    {
        TC_LOG_ERROR("sql.updates", "DBUpdater: Given source directory %s does not exist, skipped!", sourceDirectory.generic_string().c_str());
        return false;
    }

    UpdateFetcher updateFetcher(sourceDirectory, [&](std::string const& query) { DBUpdater<T>::Apply(pool, query); },
        [&](Path const& file) { DBUpdater<T>::ApplyFile(pool, file); },
            [&](std::string const& query) -> QueryResult { return DBUpdater<T>::Retrieve(pool, query); });

    UpdateResult result;
    try
    {
        result = updateFetcher.Update(
            sConfigMgr->GetBoolDefault("Updates.Redundancy", true),
            sConfigMgr->GetBoolDefault("Updates.AllowRehash", true),
            sConfigMgr->GetBoolDefault("Updates.ArchivedRedundancy", false),
            sConfigMgr->GetIntDefault("Updates.CleanDeadRefMaxCount", 3));
    }
    catch (UpdateException&)
    {
        return false;
    }

    std::string const info = Trinity::StringFormat("Containing " SZFMTD " new and " SZFMTD " archived updates.",
        result.recent, result.archived);

    if (!result.updated)
        TC_LOG_INFO("sql.updates", ">> %s database is up-to-date! %s", DBUpdater<T>::GetTableName().c_str(), info.c_str());
    else
        TC_LOG_INFO("sql.updates", ">> Applied " SZFMTD " %s. %s", result.updated, result.updated == 1 ? "query" : "queries", info.c_str());

    return true;
}

template<class T>
bool DBUpdater<T>::Populate(DatabaseWorkerPool<T>& pool)
{
    {
        QueryResult const result = Retrieve(pool, "SHOW TABLES");
        if (result && (result->GetRowCount() > 0))
            return true;
    }

    if (!DBUpdater<T>::CheckExecutable())
        return false;

    TC_LOG_INFO("sql.updates", "Database %s is empty, auto populating it...", DBUpdater<T>::GetTableName().c_str());

    std::string const p = DBUpdater<T>::GetBaseFile();
    if (p.empty())
    {
        TC_LOG_INFO("sql.updates", ">> No base file provided, skipped!");
        return true;
    }

    Path const base(p);
    if (!exists(base))
    {
        switch (DBUpdater<T>::GetBaseLocationType())
        {
            case LOCATION_REPOSITORY:
            {
                TC_LOG_ERROR("sql.updates", ">> Base file \"%s\" is missing, try to clone the source again.",
                    base.generic_string().c_str());

                break;
            }
            case LOCATION_DOWNLOAD:
            {
                TC_LOG_ERROR("sql.updates", ">> File \"%s\" is missing, download it from \"http://www.trinitycore.org/f/files/category/1-database/\"" \
                    " and place it in your server directory.", base.filename().generic_string().c_str());
                break;
            }
        }
        return false;
    }

    // Update database
    TC_LOG_INFO("sql.updates", ">> Applying \'%s\'...", base.generic_string().c_str());
    try
    {
        ApplyFile(pool, base);
    }
    catch (UpdateException&)
    {
        return false;
    }

    TC_LOG_INFO("sql.updates", ">> Done!");
    return true;
}

template<class T>
QueryResult DBUpdater<T>::Retrieve(DatabaseWorkerPool<T>& pool, std::string const& query)
{
    return pool.PQuery(query.c_str());
}

template<class T>
void DBUpdater<T>::Apply(DatabaseWorkerPool<T>& pool, std::string const& query)
{
    pool.DirectExecute(query.c_str());
}

template<class T>
void DBUpdater<T>::ApplyFile(DatabaseWorkerPool<T>& pool, Path const& path)
{
    DBUpdater<T>::ApplyFile(pool, pool.GetConnectionInfo()->host, pool.GetConnectionInfo()->user, pool.GetConnectionInfo()->password,
        pool.GetConnectionInfo()->port_or_socket, pool.GetConnectionInfo()->database, path);
}

template<class T>
void DBUpdater<T>::ApplyFile(DatabaseWorkerPool<T>& pool, std::string const& host, std::string const& user,
    std::string const& password, std::string const& port_or_socket, std::string const& database, Path const& path)
{
    std::vector<std::string> args;
    args.reserve(7);

    // CLI Client connection info
    args.push_back("-h" + host);
    args.push_back("-u" + user);

    if (!password.empty())
        args.push_back("-p" + password);

    // Check if we want to connect through ip or socket (Unix only)
#ifdef _WIN32

    args.push_back("-P" + port_or_socket);

#else

    if (!std::isdigit(port_or_socket[0]))
    {
        // We can't check here if host == "." because is named localhost if socket option is enabled
        args.push_back("-P0");
        args.push_back("--protocol=SOCKET");
        args.push_back("-S" + port_or_socket);
    }
    else
        // generic case
        args.push_back("-P" + port_or_socket);

#endif

    // Set the default charset to utf8
    args.push_back("--default-character-set=utf8");

    // Set max allowed packet to 1 GB
    args.push_back("--max-allowed-packet=1GB");

    // Database
    if (!database.empty())
        args.push_back(database);

    // ToDo: use the existing query in memory as virtual file if possible
    file_descriptor_source source(path);

    uint32 ret;
    try
    {
        child c = execute(run_exe(DBUpdater<T>::GetMySqlCli().empty() ? "mysql" :
                boost::filesystem::absolute(DBUpdater<T>::GetMySqlCli()).generic_string()),
                    set_args(args), bind_stdin(source), throw_on_error());

        ret = wait_for_exit(c);
    }
    catch (boost::system::system_error&)
    {
        ret = EXIT_FAILURE;
    }

    source.close();

    if (ret != EXIT_SUCCESS)
    {
        TC_LOG_FATAL("sql.updates", "Applying of file \'%s\' to database \'%s\' failed!" \
            " If you are an user pull the latest revision from the repository. If you are a developer fix your sql query.",
            path.generic_string().c_str(), pool.GetConnectionInfo()->database.c_str());

        throw UpdateException("update failed");
    }
}

template class DBUpdater<LoginDatabaseConnection>;
template class DBUpdater<WorldDatabaseConnection>;
template class DBUpdater<CharacterDatabaseConnection>;
