/*
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "DatabaseEnv.h"
#include "DatabaseWorker.h"
#include "DatabaseWorkerPool.h"
#include "MySQLConnection.h"
#include "SQLOperation.h"

DatabaseWorkerPool::
DatabaseWorkerPool::



void DatabaseWorkerPool::Close()


/*! This function creates a new MySQL connection for every MapUpdate thread
    and every unbundled task.
 */
void DatabaseWorkerPool::Init_MySQL_Connection()


void DatabaseWorkerPool::End_MySQL_Connection()


void DatabaseWorkerPool::Execute(const char* sql)


void DatabaseWorkerPool::PExecute(const char* sql, ...)
{
    
}

void DatabaseWorkerPool::DirectExecute(const char* sql)
{
    
}

void DatabaseWorkerPool::DirectPExecute(const char* sql, ...)
{
    
}

QueryResult_AutoPtr DatabaseWorkerPool::Query(const char* sql)


QueryResult_AutoPtr DatabaseWorkerPool::PQuery(const char* sql, ...)


SQLTransaction DatabaseWorkerPool::BeginTransaction()
{
    
}

void DatabaseWorkerPool::CommitTransaction(SQLTransaction transaction)


ACE_Future<QueryResult_AutoPtr> DatabaseWorkerPool::AsyncQuery(const char* sql)


ACE_Future<QueryResult_AutoPtr> DatabaseWorkerPool::AsyncPQuery(const char* sql, ...)


QueryResultHolderFuture DatabaseWorkerPool::DelayQueryHolder(SQLQueryHolder* holder)

MySQLConnection* DatabaseWorkerPool::GetConnection()

