/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#ifndef _TRANSACTION_H
#define _TRANSACTION_H

#include "SQLOperation.h"

//- Forward declare (don't include header to prevent circular includes)
class PreparedStatement;

/*! Transactions, high level class. */
class Transaction
{
    friend class TransactionTask;
    friend class MySQLConnection;

    template <typename T>
    friend class DatabaseWorkerPool;

    public:
        Transaction() : _cleanedUp(false) { }
        ~Transaction() { Cleanup(); }

        void Append(PreparedStatement* statement);
        void Append(const char* sql);
        void PAppend(const char* sql, ...);

        size_t GetSize() const { return m_queries.size(); }

    protected:
        void Cleanup();
        std::list<SQLElementData> m_queries;

    private:
        bool _cleanedUp;

};
typedef Trinity::AutoPtr<Transaction, ACE_Thread_Mutex> SQLTransaction;

/*! Low level class*/
class TransactionTask : public SQLOperation
{
    template <class T> friend class DatabaseWorkerPool;
    friend class DatabaseWorker;

    public:
        TransactionTask(SQLTransaction trans) : m_trans(trans) { } ;
        ~TransactionTask(){ };

    protected:
        bool Execute();

        SQLTransaction m_trans;
};

#endif
