/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef DatabaseEnvFwd_h__
#define DatabaseEnvFwd_h__

#include <future>
#include <memory>

class Field;

class ResultSet;
typedef std::shared_ptr<ResultSet> QueryResult;
typedef std::future<QueryResult> QueryResultFuture;
typedef std::promise<QueryResult> QueryResultPromise;

class CharacterDatabaseConnection;
class HotfixDatabaseConnection;
class LoginDatabaseConnection;
class WorldDatabaseConnection;

class PreparedStatementBase;

template<typename T>
class PreparedStatement;

using CharacterDatabasePreparedStatement = PreparedStatement<CharacterDatabaseConnection>;
using HotfixDatabasePreparedStatement = PreparedStatement<HotfixDatabaseConnection>;
using LoginDatabasePreparedStatement = PreparedStatement<LoginDatabaseConnection>;
using WorldDatabasePreparedStatement = PreparedStatement<WorldDatabaseConnection>;

class PreparedResultSet;
typedef std::shared_ptr<PreparedResultSet> PreparedQueryResult;
typedef std::future<PreparedQueryResult> PreparedQueryResultFuture;
typedef std::promise<PreparedQueryResult> PreparedQueryResultPromise;

class QueryCallback;

class TransactionBase;

template<typename T>
class Transaction;

template<typename T>
using SQLTransaction = std::shared_ptr<Transaction<T>>;

using CharacterDatabaseTransaction = SQLTransaction<CharacterDatabaseConnection>;
using HotfixDatabaseTransaction = SQLTransaction<HotfixDatabaseConnection>;
using LoginDatabaseTransaction = SQLTransaction<LoginDatabaseConnection>;
using WorldDatabaseTransaction = SQLTransaction<WorldDatabaseConnection>;

class SQLQueryHolderBase;
typedef std::future<SQLQueryHolderBase*> QueryResultHolderFuture;
typedef std::promise<SQLQueryHolderBase*> QueryResultHolderPromise;

template<typename T>
class SQLQueryHolder;

using CharacterDatabaseQueryHolder = SQLQueryHolder<CharacterDatabaseConnection>;
using HotfixDatabaseQueryHolder = SQLQueryHolder<HotfixDatabaseConnection>;
using LoginDatabaseQueryHolder = SQLQueryHolder<LoginDatabaseConnection>;
using WorldDatabaseQueryHolder = SQLQueryHolder<WorldDatabaseConnection>;

// mysql
struct MySQLHandle;
struct MySQLResult;
struct MySQLField;
struct MySQLBind;
struct MySQLStmt;

#endif // DatabaseEnvFwd_h__
