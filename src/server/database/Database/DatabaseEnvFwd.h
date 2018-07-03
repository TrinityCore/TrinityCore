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

class PreparedStatement;

class PreparedResultSet;
typedef std::shared_ptr<PreparedResultSet> PreparedQueryResult;
typedef std::future<PreparedQueryResult> PreparedQueryResultFuture;
typedef std::promise<PreparedQueryResult> PreparedQueryResultPromise;

class QueryCallback;

class Transaction;
typedef std::shared_ptr<Transaction> SQLTransaction;

class SQLQueryHolder;
typedef std::future<SQLQueryHolder*> QueryResultHolderFuture;
typedef std::promise<SQLQueryHolder*> QueryResultHolderPromise;

// mysql
typedef struct st_mysql MYSQL;
typedef struct st_mysql_res MYSQL_RES;
typedef struct st_mysql_field MYSQL_FIELD;
typedef struct st_mysql_bind MYSQL_BIND;
typedef struct st_mysql_stmt MYSQL_STMT;

#endif // DatabaseEnvFwd_h__
