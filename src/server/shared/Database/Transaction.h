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

#ifndef _TRANSACTION_H
#define _TRANSACTION_H

#include "SQLOperation.h"

/*! Transactions, high level class. */
class Transaction
{
    friend class TransactionTask;
    public:
        ~Transaction() { Cleanup(); }

        void Append(const char* sql);
        void PAppend(const char* sql, ...);
    
        size_t GetSize() { return m_queries.size(); }

    protected:
        void Cleanup();
        std::queue<char*> m_queries;

    private:
        bool m_actioned;
};
typedef ACE_Refcounted_Auto_Ptr<Transaction, ACE_Null_Mutex> SQLTransaction;

/*! Low level class*/
class TransactionTask : public SQLOperation
{
    template <class T> friend class DatabaseWorkerPool;
    friend class DatabaseWorker;

    public:
        TransactionTask(SQLTransaction trans) : m_trans(trans) {} ;
        ~TransactionTask(){};

    protected:
        bool Execute();

        SQLTransaction m_trans;
};

#endif