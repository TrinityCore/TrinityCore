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

#ifndef DatabaseEnvFwd_h__
#define DatabaseEnvFwd_h__

#include <memory>

struct QueryResultFieldMetadata;
class Field;

class ResultSet;
using QueryResult = std::shared_ptr<ResultSet>;

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
using PreparedQueryResult = std::shared_ptr<PreparedResultSet>;

class QueryCallback;

template<typename T>
class AsyncCallbackProcessor;

using QueryCallbackProcessor = AsyncCallbackProcessor<QueryCallback>;

class TransactionBase;

template<typename T>
class Transaction;

class TransactionCallback;

template<typename T>
using SQLTransaction = std::shared_ptr<Transaction<T>>;

using CharacterDatabaseTransaction = SQLTransaction<CharacterDatabaseConnection>;
using HotfixDatabaseTransaction = SQLTransaction<HotfixDatabaseConnection>;
using LoginDatabaseTransaction = SQLTransaction<LoginDatabaseConnection>;
using WorldDatabaseTransaction = SQLTransaction<WorldDatabaseConnection>;

class SQLQueryHolderBase;

template<typename T>
class SQLQueryHolder;

using CharacterDatabaseQueryHolder = SQLQueryHolder<CharacterDatabaseConnection>;
using HotfixDatabaseQueryHolder = SQLQueryHolder<HotfixDatabaseConnection>;
using LoginDatabaseQueryHolder = SQLQueryHolder<LoginDatabaseConnection>;
using WorldDatabaseQueryHolder = SQLQueryHolder<WorldDatabaseConnection>;

class SQLQueryHolderCallback;

// mysql
struct MySQLHandle;
struct MySQLResult;
struct MySQLField;
struct MySQLBind;
struct MySQLStmt;

#endif // DatabaseEnvFwd_h__
